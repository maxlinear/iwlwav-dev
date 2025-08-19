/******************************************************************************

         Copyright (c) 2020, MaxLinear, Inc.
         Copyright 2016 - 2020 Intel Corporation
         Copyright 2015 - 2016 Lantiq Beteiligungs-GmbH & Co. KG
         Copyright 2009 - 2014 Lantiq Deutschland GmbH
         Copyright 2007 - 2008 Infineon Technologies AG

  For licensing information, see the file 'LICENSE' in the root folder of
  this software module.

*******************************************************************************/

/*
 * $Id:
 *
 * 
 *
 * Shared QoS
 *
 */
#include "mtlkinc.h"

#include "mtlkqos.h"
#include "mtlk_packets.h"
#include "mtlk_core_iface.h"
#include "mtlk_coreui.h"
#include "mtlk_df_nbuf.h"
#include "mtlk_param_db.h"

#define LOG_LOCAL_GID   GID_QOS
#define LOG_LOCAL_FID   1


static __INLINE int
_mtlk_qos_get_priority (const uint8 *dscp_table, mtlk_nbuf_t* nbuf, uint16* ppriority)
{
  uint8 dscp_field, dscp_value;
  uint8 ether_type_and_tos[4];
  uint8 *p_type_tos = nbuf->data + (MTLK_ETH_HDR_SIZE - MTLK_ETH_SIZEOF_ETHERNET_TYPE);
  struct ethhdr *ether_header = (struct ethhdr *)nbuf->data;

  ASSERT (nbuf != NULL);  
  ASSERT (nbuf->len >= MTLK_ETH_HDR_SIZE);

  ether_type_and_tos[0] = *p_type_tos++;
  ether_type_and_tos[1] = *p_type_tos++;
  ether_type_and_tos[2] = *p_type_tos++;
  ether_type_and_tos[3] = *p_type_tos++;

  switch (ntohs(ether_header->h_proto))
  {
  case MTLK_ETH_DGRAM_TYPE_IP:
    dscp_field = get_ip4_tos(ether_type_and_tos + MTLK_ETH_SIZEOF_ETHERNET_TYPE);
    break;
  case MTLK_ETH_DGRAM_TYPE_IPV6:
    dscp_field = get_ip6_tos(ether_type_and_tos + MTLK_ETH_SIZEOF_ETHERNET_TYPE);
    break;
  case ETH_P_ARP:
  case ETH_P_RARP:
    *ppriority = MTLK_WMM_ACI_VO_CLASS;
    return MTLK_ERR_OK;
  case MTLK_ETH_TYPE_VLAN_TAG:
    *ppriority = mtlk_df_buf_get_vlan_pcp(nbuf->data, mtlk_df_nbuf_get_data_length(nbuf));
    return MTLK_ERR_OK;
  default:
    /* Unknown protocol */
    *ppriority = MTLK_WMM_ACI_DEFAULT_CLASS;
    return MTLK_ERR_OK;
  }

  dscp_value = dscp_field >> 2;
  *ppriority = dscp_table[dscp_value];

  return MTLK_ERR_OK;
}

static __INLINE bool
_mtlk_scs_match_rules (mtlk_core_t *core, mtlk_nbuf_t* nbuf, uint16* ppriority)
{
  u8 *src_ip, *dst_ip;
  BOOL type10_match = true;
  u8 version, protocol, hdr_len, next, nxt_hdr, idx;
  u8 *proto_octet = NULL, *pos = NULL;
  u16 src_port = 0, dst_port = 0;
  u32 offset = 0, ext_len = 0;
  mtlk_dlist_entry_t *head;
  mtlk_dlist_entry_t *entry;
  sta_entry *sta = NULL;
  wave_scs_list_info_t *scs_rules = NULL;
  struct iphdr *iph = NULL;
  struct ipv6hdr *ip6h = NULL;
  struct ethhdr *ether_header = NULL;
  bool ret = false;

  ASSERT (nbuf != NULL);

  ether_header = (struct ethhdr *)nbuf->data;
  sta = mtlk_stadb_find_sta(&core->slow_ctx->stadb, ether_header->h_dest);
  if (sta == NULL) {
    ELOG_V("STA not found \n");
    goto FINISH;
  }

  *ppriority = MTLK_WMM_ACI_DEFAULT_CLASS;

  switch (ntohs(ether_header->h_proto))
  {
    case ETH_P_IP:
      iph = ip_hdr(nbuf);
      if (!iph)
        return ret;

      wave_memcpy(src_ip, MTLK_IP4_ALEN, &iph->saddr, MTLK_IP4_ALEN);
      wave_memcpy(dst_ip, MTLK_IP4_ALEN, &iph->daddr, MTLK_IP4_ALEN);
      protocol = iph->protocol;
      version = MTLK_IP4_VER;

      if (protocol == IPPROTO_TCP) {
        src_port = ntohs(tcp_hdr(nbuf)->source);
        dst_port = ntohs(tcp_hdr(nbuf)->dest);
      } else if (protocol == IPPROTO_UDP) {
        src_port = ntohs(udp_hdr(nbuf)->source);
        dst_port = ntohs(udp_hdr(nbuf)->dest);
      }
      break;
    case ETH_P_IPV6:
      ip6h = ipv6_hdr(nbuf);
      if (!ip6h)
        return ret;

      wave_memcpy(src_ip, MTLK_IP6_ALEN, &ip6h->saddr, MTLK_IP6_ALEN);
      wave_memcpy(dst_ip, MTLK_IP6_ALEN, &ip6h->daddr, MTLK_IP6_ALEN);
      protocol = ip6h->nexthdr;
      version = MTLK_IP6_VER;

      if (protocol == IPPROTO_TCP) {
        src_port = ntohs(tcp_hdr(nbuf)->source);
        dst_port = ntohs(tcp_hdr(nbuf)->dest);
      } else if (protocol == IPPROTO_UDP) {
        src_port = ntohs(udp_hdr(nbuf)->source);
        dst_port = ntohs(udp_hdr(nbuf)->dest);
      }
      break;
    default:
      return ret;
  }

  mtlk_osal_lock_acquire(&sta->scs_db.scs_list_lock);
  if (mtlk_dlist_is_empty(&sta->scs_db.scs_list))
  {
     ELOG_V("SCS session not created for the STA\n");
     ret = false;
     goto FINISH;
  }

  mtlk_dlist_foreach(&sta->scs_db.scs_list, entry, head)
  {
    scs_rules = MTLK_LIST_GET_CONTAINING_RECORD(entry, wave_scs_list_info_t, lentry);
    if (scs_rules->ip_tuple.ip_version != version)
      continue;
    if (version == MTLK_IP4_VER)
    {
      if ((scs_rules->ip_tuple.u.ipv4.protocol != protocol) ||
          (memcmp(&src_ip, &scs_rules->ip_tuple.u.ipv4.src_ip, MTLK_IP4_ALEN)) ||
          (memcmp(&dst_ip, &scs_rules->ip_tuple.u.ipv4.dst_ip, MTLK_IP4_ALEN)) ||
          (src_port != scs_rules->ip_tuple.u.ipv4.src_port) ||
          (dst_port != scs_rules->ip_tuple.u.ipv4.dst_port))
         continue;
    } else if (version == MTLK_IP6_VER) {
       if ((scs_rules->ip_tuple.u.ipv6.next_header != protocol) ||
           (memcmp(src_ip, scs_rules->ip_tuple.u.ipv6.src_ip, MTLK_IP6_ALEN)) ||
           (memcmp(dst_ip, scs_rules->ip_tuple.u.ipv6.dst_ip, MTLK_IP6_ALEN)) ||
           (src_port != scs_rules->ip_tuple.u.ipv6.src_port) ||
           (dst_port != scs_rules->ip_tuple.u.ipv6.dst_port))
         continue;
    }

    if (scs_rules->tclas_info.tclass_type == FRAME_CLASSIFIER_TYPE10)
    {
      if ((protocol != IPPROTO_UDP && protocol != IPPROTO_ESP) &&
           (protocol != scs_rules->clas_type10.proto_num))
        continue;

      if (version == MTLK_IP4_VER) //for ipv4, class10
      {
        proto_octet = (u8*)iph + (iph->ihl * 4); //iph->ihl * 4 - ipv4 header len, include options field
      } else if (version == MTLK_IP6_VER) { //for ipv6, class10
        offset = sizeof(struct ipv6hdr); //points to the start of the next header field of the ipv6 frame(~40bytes)
        nxt_hdr = ip6h->nexthdr;

        while (offset < nbuf->len)
        {
          pos = (u8*)ip6h + offset;
          if (nxt_hdr == scs_rules->ip_tuple.u.ipv6.next_header)
          {
            proto_octet = pos;
            break;
          }
          next = pos[0]; //read next header from the current ext header
          hdr_len = pos[1];
          ext_len = (hdr_len + 1) * 8; //total length of current ext header

          nxt_hdr = next;
          offset += ext_len;
        }
      }

      if (proto_octet) //Compare protocol octets with filter value for both ipv6 and ipv4
      {
        for (idx = 0; idx < scs_rules->clas_type10.filter_len; idx++)
        {
           if ((proto_octet[idx] & scs_rules->clas_type10.filter_mask[idx]) !=
                (scs_rules->clas_type10.filter_val[idx] & scs_rules->clas_type10.filter_mask[idx]))
           {
             type10_match = false;
             break;
           }
         }
       }

       if (type10_match)
       {
         *ppriority = scs_rules->req_up;
         ret = true;
         goto FINISH; 
       }
    } else if (scs_rules->tclas_info.tclass_type == FRAME_CLASSIFIER_TYPE4) {
      *ppriority = scs_rules->req_up;
      ret = true;
      goto FINISH;
    }
  }
FINISH:
  mtlk_osal_lock_release(&sta->scs_db.scs_list_lock);
  if (sta) {
    mtlk_sta_decref(sta);
  }
  return ret;
}

void __MTLK_IFUNC
mtlk_qos_adjust_priority(mtlk_core_t *core, mtlk_nbuf_t *nbuf)
{
  uint16 priority;
  uint8 scs_enable = 0;
  /* TODO: WLANRTSYS-88975, thr priority precedence i.e QOS > SCS will
   * carried out in the next phase. The SCS rules match will be carried
   * out only if enable scs set. This is flag will be set in hostapd.conf */
  scs_enable = MTLK_CORE_PDB_GET_INT(core, PARAM_DB_CORE_SCS_ENABLE);

  if (scs_enable) {
    if (!(_mtlk_scs_match_rules(core, nbuf, &priority)))
      _mtlk_qos_get_priority(core->dscp_table, nbuf, &priority);
  }
  else
    /* Get priority from DSCP bits (IP priority) or PCP from vlan header*/
    _mtlk_qos_get_priority(core->dscp_table, nbuf, &priority);

  /* update packet's priority */
  mtlk_df_nbuf_set_priority(nbuf, priority);
}

void __MTLK_IFUNC mtlk_qos_dscp_table_init (uint8 *dscp_table)
{
  uint32 up;

  for (up = 0; up < NTS_TIDS; up++)
  {
    memset(&dscp_table[up * DSCP_PER_UP], up, DSCP_PER_UP);
  }
}
