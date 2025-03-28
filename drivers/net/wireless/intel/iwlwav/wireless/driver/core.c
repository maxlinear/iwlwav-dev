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
 * $Id$
 *
 *
 *
 * Core functionality
 *
 */
#include "mtlkinc.h"

#include "core_priv.h"
#include "mtlk_df.h"
#include "mtlk_df_user_priv.h"
#include "mtlk_df_priv.h"
#include "mtlk_coreui.h"
#include "core.h"
#include "core_config.h"
#include "core_stats.h"
#include "mtlkhal.h"
#include "drvver.h"
#include "mhi_mac_event.h"
#include "mtlk_packets.h"
#include "mtlkparams.h"
#include "nlmsgs.h"
#include "log_drv.h"
#include "mtlk_snprintf.h"
#include "eeprom.h"
#include "bitrate.h"
#include "mtlk_gpl_helper.h"
#include "mtlkaux.h"
#include "mtlk_param_db.h"
#include "mtlkwssa_drvinfo.h"
#include "wds.h"
#include "ta.h"
#include "core_common.h"
#include "mtlk_df_nbuf.h"
#include "mtlk_coc.h"
#include "vendor_cmds.h"

#ifdef CPTCFG_IWLWAV_PMCU_SUPPORT
  #include "mtlk_pcoc.h"
#endif /*CPTCFG_IWLWAV_PMCU_SUPPORT*/

#include "cfg80211.h"
#include "mac80211.h"
#include "wave_radio.h"
#include "fw_recovery.h"
#include "scan_support.h"
#include "mhi_umi.h"
#include "mcast.h"
#include "mtlk_hs20.h"
#include "eth_parser.h"
#include "core_pdb_def.h"
#include "wave_hal_stats.h"
#include "wave_80211ax.h"
#include "mtlk_rtlog.h"
#include "ieee80211_crc32.h"  /* for IEEE80211 32-bit CRC computation */

#define LOG_LOCAL_GID   GID_CORE
#define LOG_LOCAL_FID   4

#define MTLK_CORE_STA_LIST_HASH_NOF_BUCKETS          16
#define MTLK_CORE_WIDAN_BLACKLIST_HASH_NOF_BUCKETS   16
#define MTLK_CORE_4ADDR_STA_LIST_HASH_NOF_BUCKETS    16
#define MTLK_CORE_ACL_HASH_NOF_BUCKETS               16

typedef enum __mtlk_core_async_priorities_t
{
  _MTLK_CORE_PRIORITY_MAINTENANCE = 0,
  _MTLK_CORE_PRIORITY_NETWORK,
  _MTLK_CORE_PRIORITY_INTERNAL,
  _MTLK_CORE_PRIORITY_USER,
  _MTLK_CORE_PRIORITY_EMERGENCY,
  _MTLK_CORE_NUM_PRIORITIES
} _mtlk_core_async_priorities_t;

#define SCAN_CACHE_AGEING (3600) /* 1 hour */

static const uint32 _mtlk_core_wss_id_map[] =
{
  MTLK_WWSS_WLAN_STAT_ID_BYTES_SENT_64,                                            /* MTLK_CORE_CNT_BYTES_SENT_64 */
  MTLK_WWSS_WLAN_STAT_ID_BYTES_RECEIVED_64,                                        /* MTLK_CORE_CNT_BYTES_RECEIVED_64 */
  MTLK_WWSS_WLAN_STAT_ID_PACKETS_SENT_64,                                          /* MTLK_CORE_CNT_PACKETS_SENT_64 */
  MTLK_WWSS_WLAN_STAT_ID_PACKETS_RECEIVED_64,                                      /* MTLK_CORE_CNT_PACKETS_RECEIVED_64 */

  MTLK_WWSS_WLAN_STAT_ID_UNICAST_PACKETS_SENT,                                     /* MTLK_CORE_CNT_UNICAST_PACKETS_SENT */
  MTLK_WWSS_WLAN_STAT_ID_MULTICAST_PACKETS_SENT,                                   /* MTLK_CORE_CNT_MULTICAST_PACKETS_SENT */
  MTLK_WWSS_WLAN_STAT_ID_BROADCAST_PACKETS_SENT,                                   /* MTLK_CORE_CNT_BROADCAST_PACKETS_SENT */
  MTLK_WWSS_WLAN_STAT_ID_UNICAST_BYTES_SENT,                                       /* MTLK_CORE_CNT_UNICAST_BYTES_SENT */
  MTLK_WWSS_WLAN_STAT_ID_MULTICAST_BYTES_SENT,                                     /* MTLK_CORE_CNT_MULTICAST_BYTES_SENT */
  MTLK_WWSS_WLAN_STAT_ID_BROADCAST_BYTES_SENT,                                     /* MTLK_CORE_CNT_BROADCAST_BYTES_SENT */

  MTLK_WWSS_WLAN_STAT_ID_UNICAST_PACKETS_RECEIVED,                                 /* MTLK_CORE_CNT_UNICAST_PACKETS_RECEIVED */
  MTLK_WWSS_WLAN_STAT_ID_MULTICAST_PACKETS_RECEIVED,                               /* MTLK_CORE_CNT_MULTICAST_PACKETS_RECEIVED */
  MTLK_WWSS_WLAN_STAT_ID_BROADCAST_PACKETS_RECEIVED,                               /* MTLK_CORE_CNT_BROADCAST_PACKETS_RECEIVED */
  MTLK_WWSS_WLAN_STAT_ID_UNICAST_BYTES_RECEIVED,                                   /* MTLK_CORE_CNT_UNICAST_BYTES_RECEIVED */
  MTLK_WWSS_WLAN_STAT_ID_MULTICAST_BYTES_RECEIVED,                                 /* MTLK_CORE_CNT_MULTICAST_BYTES_RECEIVED */
  MTLK_WWSS_WLAN_STAT_ID_BROADCAST_BYTES_RECEIVED,                                 /* MTLK_CORE_CNT_BROADCAST_BYTES_RECEIVED */

  MTLK_WWSS_WLAN_STAT_ID_ERROR_PACKETS_SENT,                                       /* MTLK_CORE_CNT_ERROR_PACKETS_SENT */
  MTLK_WWSS_WLAN_STAT_ID_ERROR_PACKETS_RECEIVED,                                   /* MTLK_CORE_CNT_ERROR_PACKETS_RECEIVED */
  MTLK_WWSS_WLAN_STAT_ID_DISCARD_PACKETS_RECEIVED,                                 /* MTLK_CORE_CNT_DISCARD_PACKETS_RECEIVED */

  MTLK_WWSS_WLAN_STAT_ID_TX_PROBE_RESP_SENT,                                       /* MTLK_CORE_CNT_TX_PROBE_RESP_SENT */
  MTLK_WWSS_WLAN_STAT_ID_TX_PROBE_RESP_DROPPED,                                    /* MTLK_CORE_CNT_TX_PROBE_RESP_DROPPED */
  MTLK_WWSS_WLAN_STAT_ID_BSS_MGMT_TX_QUE_FULL,                                     /* MTLK_CORE_CNT_BSS_MGMT_TX_QUE_FULL */

  MTLK_WWSS_WLAN_STAT_ID_MAN_FRAMES_RES_QUEUE,                                     /* MTLK_CORE_CNT_MAN_FRAMES_RES_QUEUE */
  MTLK_WWSS_WLAN_STAT_ID_MAN_FRAMES_SENT,                                          /* MTLK_CORE_CNT_MAN_FRAMES_SENT */
  MTLK_WWSS_WLAN_STAT_ID_MAN_FRAMES_CONFIRMED,                                     /* MTLK_CORE_CNT_MAN_FRAMES_CONFIRMED */

  MTLK_WWSS_WLAN_STAT_ID_PD_BROADCAST_PACKETS_SENT,                                /* MTLK_CORE_CNT_PD_BROADCAST_PACKETS_SENT */
  MTLK_WWSS_WLAN_STAT_ID_PD_BROADCAST_BYTES_SENT_64,                               /* MTLK_CORE_CNT_PD_BROADCAST_BYTES_SENT_64 */
  MTLK_WWSS_WLAN_STAT_ID_PD_UNICAST_PACKETS_SENT,                                  /* MTLK_CORE_CNT_PD_UNICAST_PACKETS_SENT */
  MTLK_WWSS_WLAN_STAT_ID_PD_UNICAST_BYTES_SENT_64,                                 /* MTLK_CORE_CNT_PD_UNICAST_BYTES_SENT_64 */
  MTLK_WWSS_WLAN_STAT_ID_PD_MULTICAST_PACKETS_SENT,                                /* MTLK_CORE_CNT_PD_MULTICAST_PACKETS_SENT */
  MTLK_WWSS_WLAN_STAT_ID_PD_MULTICAST_BYTES_SENT_64,                               /* MTLK_CORE_CNT_PD_MULTICAST_BYTES_SENT_64 */

#if MTLK_MTIDL_WLAN_STAT_FULL
  MTLK_WWSS_WLAN_STAT_ID_RX_PACKETS_DISCARDED_DRV_DUPLICATE,                       /* MTLK_CORE_CNT_RX_PACKETS_DISCARDED_DRV_DUPLICATE */
  MTLK_WWSS_WLAN_STAT_ID_TX_PACKETS_DISCARDED_DRV_NO_PEERS,                        /* MTLK_CORE_CNT_TX_PACKETS_DISCARDED_NO_PEERS                                   */
  MTLK_WWSS_WLAN_STAT_ID_TX_PACKETS_DISCARDED_DRV_UNKNOWN_DESTINATION_DIRECTED,    /* MTLK_CORE_CNT_TX_PACKETS_DISCARDED_DRV_UNKNOWN_DESTINATION_DIRECTED           */
  MTLK_WWSS_WLAN_STAT_ID_TX_PACKETS_DISCARDED_DRV_UNKNOWN_DESTINATION_MCAST,       /* MTLK_CORE_CNT_TX_PACKETS_DISCARDED_DRV_UNKNOWN_DESTINATION_MCAST              */
  MTLK_WWSS_WLAN_STAT_ID_TX_PACKETS_DISCARDED_DRV_NO_RESOURCES,                    /* MTLK_CORE_CNT_TX_PACKETS_DISCARDED_DRV_NO_RESOURCES                           */
  MTLK_WWSS_WLAN_STAT_ID_TX_PACKETS_DISCARDED_DRV_SQ_OVERFLOW,                     /* MTLK_CORE_CNT_TX_PACKETS_DISCARDED_SQ_OVERFLOW                                */
  MTLK_WWSS_WLAN_STAT_ID_TX_PACKETS_DISCARDED_DRV_DROP_ALL_FILTER,                 /* MTLK_CORE_CNT_TX_PACKETS_DISCARDED_DROP_ALL_FILTER                            */
  MTLK_WWSS_WLAN_STAT_ID_TX_PACKETS_DISCARDED_DRV_TX_QUEUE_OVERFLOW,               /* MTLK_CORE_CNT_TX_PACKETS_DISCARDED_TX_QUEUE_OVERFLOW                          */
  MTLK_WWSS_WLAN_STAT_ID_802_1X_PACKETS_RECEIVED,                                  /* MTLK_CORE_CNT_802_1X_PACKETS_RECEIVED                                         */
  MTLK_WWSS_WLAN_STAT_ID_802_1X_PACKETS_SENT,                                      /* MTLK_CORE_CNT_802_1X_PACKETS_SENT                                             */
  MTLK_WWSS_WLAN_STAT_ID_802_1X_PACKETS_DISCARDED,                                 /* MTLK_CORE_CNT_802_1X_PACKETS_DISCARDED                                        */
  MTLK_WWSS_WLAN_STAT_ID_PAIRWISE_MIC_FAILURE_PACKETS,                              /* MTLK_CORE_CNT_PAIRWISE_MIC_FAILURE_PACKETS */
  MTLK_WWSS_WLAN_STAT_ID_GROUP_MIC_FAILURE_PACKETS,                                 /* MTLK_CORE_CNT_GROUP_MIC_FAILURE_PACKETS */
  MTLK_WWSS_WLAN_STAT_ID_UNICAST_REPLAYED_PACKETS,                                  /* MTLK_CORE_CNT_UNICAST_REPLAYED_PACKETS */
  MTLK_WWSS_WLAN_STAT_ID_MULTICAST_REPLAYED_PACKETS,                                /* MTLK_CORE_CNT_MULTICAST_REPLAYED_PACKETS */
  MTLK_WWSS_WLAN_STAT_ID_MANAGEMENT_REPLAYED_PACKETS,                               /* MTLK_CORE_CNT_MANAGEMENT_REPLAYED_PACKETS */
  MTLK_WWSS_WLAN_STAT_ID_FWD_RX_PACKETS,                                            /* MTLK_CORE_CNT_FWD_RX_PACKETS */
  MTLK_WWSS_WLAN_STAT_ID_FWD_RX_BYTES,                                              /* MTLK_CORE_CNT_FWD_RX_BYTES */
  MTLK_WWSS_WLAN_STAT_ID_DAT_FRAMES_RECEIVED,                                       /* MTLK_CORE_CNT_DAT_FRAMES_RECEIVED */
  MTLK_WWSS_WLAN_STAT_ID_CTL_FRAMES_RECEIVED,                                       /* MTLK_CORE_CNT_CTL_FRAMES_RECEIVED */
  MTLK_WWSS_WLAN_STAT_ID_MAN_FRAMES_RECEIVED,                                       /* MTLK_CORE_CNT_MAN_FRAMES_RECEIVED */
  MTLK_WWSS_WLAN_STAT_ID_RX_MAN_FRAMES_RETRY_DROPPED,                               /* MTLK_CORE_CNT_RX_MAN_FRAMES_RETRY_DROPPED */
  MTLK_WWSS_WLAN_STAT_ID_MAN_FRAMES_FAILED,                                         /* MTLK_CORE_CNT_MAN_FRAMES_FAILED */
  MTLK_WWSS_WLAN_STAT_ID_NOF_CHANNEL_SWITCH_20_TO_40,                               /* MTLK_CORE_CNT_CHANNEL_SWITCH_20_TO_40 */
  MTLK_WWSS_WLAN_STAT_ID_NOF_CHANNEL_SWITCH_40_TO_20,                               /* MTLK_CORE_CNT_CHANNEL_SWITCH_40_TO_20 */
  MTLK_WWSS_WLAN_STAT_ID_TX_PACKETS_TO_UNICAST_DGAF_DISABLED,                       /* MTLK_CORE_CNT_TX_PACKETS_TO_UNICAST_DGAF_DISABLED */
  MTLK_WWSS_WLAN_STAT_ID_TX_PACKETS_SKIPPED_DGAF_DISABLED,                          /* MTLK_CORE_CNT_TX_PACKETS_SKIPPED_DGAF_DISABLED */
#endif /* MTLK_MTIDL_WLAN_STAT_FULL */
};

/* API between Core and HW */
static int  _mtlk_core_start (mtlk_vap_handle_t vap_handle);
static int  _mtlk_core_handle_tx_data (mtlk_core_t* nic, mtlk_core_handle_tx_data_t *data, uint32 nbuf_flags) __MTLK_INT_HANDLER_SECTION;
static int  _mtlk_core_release_tx_data (mtlk_vap_handle_t vap_handle, mtlk_hw_data_req_mirror_t *data_req) __MTLK_INT_HANDLER_SECTION;
static int  _mtlk_core_handle_rx_data (mtlk_vap_handle_t vap_handle, mtlk_core_handle_rx_data_t *data) __MTLK_INT_HANDLER_SECTION;
static int  _mtlk_core_handle_rx_bss (mtlk_vap_handle_t vap_handle, mtlk_core_handle_rx_bss_t *data);
static void _mtlk_core_handle_rx_ctrl (mtlk_vap_handle_t vap_handle, uint32 id, void *payload, uint32 payload_buffer_size);
static int  _mtlk_core_get_prop (mtlk_vap_handle_t vap_handle, mtlk_core_prop_e prop_id, void* buffer, uint32 size);
static int  _mtlk_core_set_prop (mtlk_vap_handle_t vap_handle, mtlk_core_prop_e prop_id, void *buffer, uint32 size);
static void _mtlk_core_stop (mtlk_vap_handle_t vap_handle);
static void _mtlk_core_prepare_stop (mtlk_vap_handle_t vap_handle);

static mtlk_core_vft_t const core_vft = {
  _mtlk_core_start,
  _mtlk_core_handle_tx_data,
  _mtlk_core_release_tx_data,
  _mtlk_core_handle_rx_data,
  _mtlk_core_handle_rx_bss,
  _mtlk_core_handle_rx_ctrl,
  _mtlk_core_get_prop,
  _mtlk_core_set_prop,
  _mtlk_core_stop,
  _mtlk_core_prepare_stop
};

typedef struct {
  uint8    *frame;
  uint32   size;
  unsigned freq;
  int      sig_dbm;
  unsigned subtype;
  BOOL     probe_req_wps_ie;
  BOOL     probe_req_interworking_ie;
  BOOL     probe_req_vsie;
  BOOL     probe_req_he_ie;
  BOOL     probe_req_mlo_ie;
  uint8    pmf_flags;
  mtlk_phy_info_t  phy_info;
} mtlk_mngmnt_frame_t;

/* API between Core and DF UI */

static int  _wave_core_sync_done(mtlk_handle_t hcore, const void* data, uint32 data_size);
static int  _wave_core_handle_radar_event(mtlk_handle_t core_object, const void *payload, uint32 size);

static int _mtlk_core_get_tx_rate_power(mtlk_handle_t hcore, const void* data, uint32 data_size);
static int _mtlk_core_get_stadb_sta_list(mtlk_handle_t hcore, const void* data, uint32 data_size);
static int _mtlk_core_range_info_get (mtlk_handle_t hcore, const void* data, uint32 data_size);
static int _mtlk_core_get_status(mtlk_handle_t hcore, const void* data, uint32 data_size);
static int _mtlk_core_set_qamplus_mode(mtlk_handle_t hcore, const void* data, uint32 data_size);
static int _mtlk_core_get_qamplus_mode(mtlk_handle_t hcore, const void* data, uint32 data_size);
static int _mtlk_core_set_radio_mode(mtlk_handle_t hcore, const void* data, uint32 data_size);
static int _mtlk_core_get_radio_mode(mtlk_handle_t hcore, const void* data, uint32 data_size);
static int _mtlk_core_set_aggr_cfg(mtlk_handle_t hcore, const void* data, uint32 data_size);
static int _mtlk_core_get_aggr_cfg(mtlk_handle_t hcore, const void* data, uint32 data_size);
static int _mtlk_core_set_amsdu_num(mtlk_handle_t hcore, const void* data, uint32 data_size);
static int _mtlk_core_get_vap_measurements(mtlk_handle_t hcore, const void *data, uint32 data_size);
static int _mtlk_core_get_radio_info(mtlk_handle_t hcore, const void *data, uint32 data_size);
static int _wave_core_bss_tx_status_get(mtlk_handle_t hcore, const void* data, uint32 data_size);
static int _mtlk_core_cfg_store_chan_switch_deauth_params(mtlk_handle_t hcore, const void* data, uint32 data_size);

static void _mtlk_core_get_vap_info_stats(mtlk_core_t* core, struct driver_vap_info *vap_info);
static void _mtlk_core_get_tr181_hw(mtlk_core_t* core,  mtlk_wssa_drv_tr181_hw_t* tr181_hw);

/* with checking ALLOWED option */
#define _mtlk_core_get_cnt(core, id)        ((TRUE == id##_ALLOWED) ? __mtlk_core_get_cnt(core, id) : 0)
#define _mtlk_core_get_cnt_64(core, id)     ((TRUE == id##_ALLOWED) ? __mtlk_core_get_cnt_64(core, id) : 0)
#define _mtlk_core_reset_cnt(core, id)      if (TRUE == id##_ALLOWED) __mtlk_core_reset_cnt(core, id)

static __INLINE uint32
__mtlk_core_get_cnt (mtlk_core_t       *core,
                    mtlk_core_wss_cnt_id_e cnt_id)
{
  MTLK_ASSERT(cnt_id >= 0 && cnt_id < MTLK_CORE_CNT_LAST);
  return mtlk_wss_get_stat(core->wss, cnt_id);
}

static __INLINE uint64
__mtlk_core_get_cnt_64 (mtlk_core_t       *core,
                        mtlk_core_wss_cnt_id_e cnt_id)
{
  MTLK_ASSERT(cnt_id >= 0 && cnt_id < MTLK_CORE_CNT_LAST);
  return mtlk_wss_get_stat_64(core->wss, cnt_id);
}

static __INLINE void
__mtlk_core_reset_cnt (mtlk_core_t *core, mtlk_core_wss_cnt_id_e cnt_id)
{
  MTLK_ASSERT(cnt_id >= 0 && cnt_id < MTLK_CORE_CNT_LAST);
  mtlk_wss_reset_stat(core->wss, cnt_id);
}

static __INLINE void
_mtlk_core_on_mic_failure (mtlk_core_t       *core,
                           mtlk_df_ui_mic_fail_type_t mic_fail_type)
{
  MTLK_ASSERT((MIC_FAIL_PAIRWISE == mic_fail_type) || (MIC_FAIL_GROUP== mic_fail_type));
  switch(mic_fail_type) {
  case MIC_FAIL_PAIRWISE:
    mtlk_core_inc_cnt(core, MTLK_CORE_CNT_PAIRWISE_MIC_FAILURE_PACKETS);
    break;
  case MIC_FAIL_GROUP:
    mtlk_core_inc_cnt(core, MTLK_CORE_CNT_GROUP_MIC_FAILURE_PACKETS);
    break;
  default:
    WLOG_D("CID-%04x: Wrong type of pairwise packet", mtlk_vap_get_oid(core->vap_handle));
    break;
  }
}

static __INLINE BOOL
_mtlk_core_has_connections(mtlk_core_t *core)
{
  return !mtlk_stadb_is_empty(&core->slow_ctx->stadb);
};

BOOL __MTLK_IFUNC
mtlk_core_has_connections(mtlk_core_t *core)
{
  return _mtlk_core_has_connections(core);
};

/* ======================================================*/
/* Core internal wrapper for asynchronous execution.     */
/* Uses serializer, command can't be tracked/canceled,   */
/* allocated on heap and deleted by completion callback. */
static void
_mtlk_core_async_clb(mtlk_handle_t user_context)
{
  int res = MTLK_ERR_BUSY;
  _core_async_exec_t *ctx = (_core_async_exec_t *) user_context;

  if (_mtlk_abmgr_is_ability_enabled(mtlk_vap_get_abmgr(ctx->vap_handle),
                                          ctx->ability_id))
  {
    res = ctx->func(ctx->receiver, &ctx[1], ctx->data_size);
  } else {
    WLOG_DD("CID-%04x: Requested ability 0x%X is disabled or never was registered",
           mtlk_vap_get_oid(ctx->vap_handle), ctx->ability_id);
  }

  if(NULL != ctx->user_req)
    mtlk_df_ui_req_complete(ctx->user_req, res);
}

static void
_mtlk_core_async_compl_clb(serializer_result_t res,
                           mtlk_command_t* command,
                           mtlk_handle_t completion_ctx)
{
  _core_async_exec_t *ctx = (_core_async_exec_t *) completion_ctx;

  mtlk_command_cleanup(&ctx->cmd);
  mtlk_osal_mem_free(ctx);
}

static int
_mtlk_core_execute_async_ex (struct nic *nic, mtlk_ability_id_t ability_id, mtlk_handle_t receiver,
                             mtlk_core_task_func_t func, const void *data, size_t size,
                             _mtlk_core_async_priorities_t priority,
                             mtlk_user_request_t *req,
                             mtlk_slid_t issuer_slid)
{
  int res;
  _core_async_exec_t *ctx;

  MTLK_ASSERT(0 == sizeof(_core_async_exec_t) % sizeof(void*));

  ctx = mtlk_osal_mem_alloc(sizeof(_core_async_exec_t) + size,
                            MTLK_MEM_TAG_ASYNC_CTX);
  if(NULL == ctx) {
    ELOG_D("CID-%04x: Failed to allocate execution context object", mtlk_vap_get_oid(nic->vap_handle));
    return MTLK_ERR_NO_MEM;
  }

  ctx->receiver     = receiver;
  ctx->data_size    = size;
  ctx->func         = func;
  ctx->user_req     = req;
  ctx->vap_handle   = nic->vap_handle;
  ctx->ability_id   = ability_id;
  wave_memcpy(&ctx[1], size, data, size);

  res = mtlk_command_init(&ctx->cmd, _mtlk_core_async_clb, HANDLE_T(ctx), issuer_slid);
  if(MTLK_ERR_OK != res) {
    mtlk_osal_mem_free(ctx);
    ELOG_D("CID-%04x: Failed to initialize command object", mtlk_vap_get_oid(nic->vap_handle));
    return res;
  }

  res = mtlk_serializer_enqueue(&nic->slow_ctx->serializer, priority,
                                &ctx->cmd, _mtlk_core_async_compl_clb,
                                HANDLE_T(ctx));
  if(MTLK_ERR_OK != res) {
    mtlk_osal_mem_free(ctx);
    ELOG_DD("CID-%04x: Failed to enqueue command object (error: %d)", mtlk_vap_get_oid(nic->vap_handle), res);
    return res;
  }

  return res;
}

#define _mtlk_core_execute_async(nic, ability_id, receiver, func, data, size, priority, req) \
  _mtlk_core_execute_async_ex((nic), (ability_id), (receiver), (func), (data), (size), (priority), (req), MTLK_SLID)

int __MTLK_IFUNC mtlk_core_schedule_internal_task_ex (struct nic *nic,
                                                      mtlk_handle_t object,
                                                      mtlk_core_task_func_t func,
                                                      const void *data, size_t size,
                                                      mtlk_slid_t issuer_slid)
{
  return _mtlk_core_execute_async_ex(nic, MTLK_ABILITY_NONE, object, func, data, size,
                                     _MTLK_CORE_PRIORITY_INTERNAL, NULL, issuer_slid);
}

int __MTLK_IFUNC mtlk_core_schedule_user_task_ex (struct nic *nic,
                                                  mtlk_handle_t object,
                                                  mtlk_core_task_func_t func,
                                                  const void *data, size_t size,
                                                  mtlk_slid_t issuer_slid)
{
  return _mtlk_core_execute_async_ex(nic, MTLK_ABILITY_NONE, object, func, data, size,
                                     _MTLK_CORE_PRIORITY_USER, NULL, issuer_slid);
}

/*! Function for scheduling out of order (emergency) task.
    Sends message confirmation for message object specified

    \param   nic              Pointer to the core object
    \param   object           Handle of receiver object
    \param   func             Task callback
    \param   data             Pointer to the data buffer provided by caller
    \param   data_size        Size of data buffer provided by caller

*/
int __MTLK_IFUNC mtlk_core_schedule_emergency_task (struct nic *nic,
                                                    mtlk_handle_t object,
                                                    mtlk_core_task_func_t func,
                                                    const void *data, size_t size,
                                                    mtlk_slid_t issuer_slid)
{
  return _mtlk_core_execute_async_ex(nic, MTLK_ABILITY_NONE, object, func, data, size,
                                     _MTLK_CORE_PRIORITY_EMERGENCY, NULL, issuer_slid);
}

/*! Function for scheduling serialized task on demand of HW module activities
    Sends message confirmation for message object specified

    \param   nic              Pointer to the core object
    \param   object           Handle of receiver object
    \param   func             Task callback
    \param   data             Pointer to the data buffer provided by caller
    \param   data_size        Size of data buffer provided by caller

*/
int __MTLK_IFUNC mtlk_core_schedule_hw_task(struct nic *nic,
                                            mtlk_handle_t object,
                                            mtlk_core_task_func_t func,
                                            const void *data, size_t size,
                                            mtlk_slid_t issuer_slid)
{
  return _mtlk_core_execute_async_ex(nic, MTLK_ABILITY_NONE, object, func, data, size,
                                     _MTLK_CORE_PRIORITY_NETWORK, NULL, issuer_slid);
}
/* ======================================================*/

/* ======================================================*/
/* Function for processing HW tasks                      */

typedef enum __mtlk_hw_task_type_t
{
  SYNCHRONOUS,
  SERIALIZABLE
} _mtlk_core_task_type_t;

static void
_mtlk_process_hw_task_ex (mtlk_core_t* nic,
                          _mtlk_core_task_type_t task_type, mtlk_core_task_func_t task_func,
                          mtlk_handle_t object, const void* data, uint32 data_size, mtlk_slid_t issuer_slid)
{
    if(SYNCHRONOUS == task_type) {
      task_func(object, data, data_size);
    } else {
      if(MTLK_ERR_OK != mtlk_core_schedule_hw_task(nic, object,
                                                   task_func, data, data_size, issuer_slid))
      {
        ELOG_D("CID-%04x: Hardware task schedule failed.", mtlk_vap_get_oid(nic->vap_handle));
      }
    }
}

#define _mtlk_process_hw_task(nic, task_type, task_func, object, data, data_size) \
  _mtlk_process_hw_task_ex((nic), (task_type), (task_func), (object), (data), (data_size), MTLK_SLID)

static void
_mtlk_process_user_task_ex (mtlk_core_t* nic, mtlk_user_request_t *req,
                            _mtlk_core_task_type_t task_type, mtlk_ability_id_t ability_id,
                            mtlk_core_task_func_t task_func,
                            mtlk_handle_t object, mtlk_clpb_t* data, mtlk_slid_t issuer_slid)
{
    if(SYNCHRONOUS == task_type) {
      int res = MTLK_ERR_BUSY;
      /* check is ability enabled for execution */
      if (_mtlk_abmgr_is_ability_enabled(mtlk_vap_get_abmgr(nic->vap_handle), ability_id)) {
        res = task_func(object, &data, sizeof(mtlk_clpb_t*));
      } else {
        WLOG_DD("CID-%04x: Requested ability 0x%X is disabled or never was registered",
                mtlk_vap_get_oid(nic->vap_handle), ability_id);
      }
      mtlk_df_ui_req_complete(req, res);
    } else {
      int result = _mtlk_core_execute_async_ex(nic, ability_id, object, task_func,
                                               &data, sizeof(typeof(data)), _MTLK_CORE_PRIORITY_USER, req,
                                               issuer_slid);
      if(MTLK_ERR_OK != result) {
        ELOG_DD("CID-%04x: User task schedule failed (error %d).",
                mtlk_vap_get_oid(nic->vap_handle), result);
        mtlk_df_ui_req_complete(req, result);
      }
    }
}

#define _mtlk_process_user_task(nic, req, task_type, ability_id, task_func, object, data) \
  _mtlk_process_user_task_ex((nic), (req), (task_type), (ability_id), (task_func), (object), (data), MTLK_SLID)

static void
_mtlk_process_emergency_task_ex (mtlk_core_t* nic,
                                 mtlk_core_task_func_t task_func,
                                 mtlk_handle_t object, const void* data, uint32 data_size, mtlk_slid_t issuer_slid)
{
  if (MTLK_ERR_OK != mtlk_core_schedule_emergency_task(nic, object,
                                                      task_func, data, data_size, issuer_slid)) {
    ELOG_D("CID-%04x: Emergency task schedule failed.", mtlk_vap_get_oid(nic->vap_handle));
  }
}

#define _mtlk_process_emergency_task(nic, task_func, object, data, data_size) \
  _mtlk_process_emergency_task_ex((nic), (task_func), (object), (data), (data_size), MTLK_SLID)

/* ======================================================*/
static void cleanup_on_disconnect(struct nic *nic);

mtlk_eeprom_data_t* __MTLK_IFUNC
mtlk_core_get_eeprom(mtlk_core_t* core)
{
  mtlk_eeprom_data_t *ee_data = NULL;

  (void)mtlk_hw_get_prop(mtlk_vap_get_hwapi(core->vap_handle), MTLK_HW_PROP_EEPROM_DATA, &ee_data, sizeof(typeof(ee_data)));

  return ee_data;
}

mtlk_scan_support_t* __MTLK_IFUNC
mtlk_core_get_scan_support(mtlk_core_t* core)
{
  return wave_radio_scan_support_get(wave_vap_radio_get(core->vap_handle));
}

const char *mtlk_net_state_to_string(uint32 state)
{
  switch (state) {
  case NET_STATE_HALTED:
    return "NET_STATE_HALTED";
  case NET_STATE_IDLE:
    return "NET_STATE_IDLE";
  case NET_STATE_READY:
    return "NET_STATE_READY";
  case NET_STATE_ACTIVATING:
    return "NET_STATE_ACTIVATING";
  case NET_STATE_CONNECTED:
    return "NET_STATE_CONNECTED";
  case NET_STATE_DEACTIVATING:
    return "NET_STATE_DEACTIVATING";
  default:
    break;
  }
  ILOG1_D("Unknown state 0x%04X", state);
  return "NET_STATE_UNKNOWN";
}

static __INLINE mtlk_hw_state_e
__mtlk_core_get_hw_state (mtlk_core_t *nic)
{
  mtlk_hw_state_e hw_state = MTLK_HW_STATE_LAST;
  mtlk_hw_get_prop(mtlk_vap_get_hwapi(nic->vap_handle), MTLK_HW_PROP_STATE, &hw_state, sizeof(hw_state));
  return hw_state;
}

mtlk_hw_state_e __MTLK_IFUNC
mtlk_core_get_hw_state (mtlk_core_t *nic)
{
  return __mtlk_core_get_hw_state(nic);
}

int __MTLK_IFUNC
mtlk_set_hw_state (mtlk_core_t *nic, mtlk_hw_state_e st)
{
#if (IWLWAV_RTLOG_MAX_DLEVEL >= 1)
  mtlk_hw_state_e ost;
  (void)mtlk_hw_get_prop(mtlk_vap_get_hwapi(nic->vap_handle), MTLK_HW_PROP_STATE, &ost, sizeof(ost));
  ILOG1_DD("%i -> %i", ost, st);
#endif
  return mtlk_hw_set_prop(mtlk_vap_get_hwapi(nic->vap_handle), MTLK_HW_PROP_STATE, &st, sizeof(st));
}

BOOL mtlk_core_is_hw_halted(mtlk_core_t *nic)
{
  mtlk_hw_state_e hw_state = mtlk_core_get_hw_state(nic);
  return mtlk_hw_is_halted(hw_state);
}

int __MTLK_IFUNC
mtlk_core_set_net_state(mtlk_core_t *core, uint32 new_state)
{
  uint32 allow_mask;
  mtlk_hw_state_e hw_state;
  int result = MTLK_ERR_OK;
  int net_state;

  net_state = mtlk_core_get_net_state(core);
  if (new_state == NET_STATE_HALTED) {
    ILOG3_SSS("%s: Going from %s to %s", mtlk_df_get_name(mtlk_vap_get_df(core->vap_handle)),
              mtlk_net_state_to_string(net_state), "NET_STATE_HALTED");
    mtlk_osal_atomic_set(&core->net_state, NET_STATE_HALTED);
    goto FINISH;
  }
  /* allow transition from NET_STATE_HALTED to NET_STATE_IDLE
     while in hw state MTLK_HW_STATE_READY */
  hw_state = __mtlk_core_get_hw_state(core);
  if ((hw_state != MTLK_HW_STATE_READY) && (hw_state != MTLK_HW_STATE_UNLOADING) &&
      (new_state != NET_STATE_IDLE)) {
    ELOG_DD("CID-%04x: Wrong hw_state=%d", mtlk_vap_get_oid(core->vap_handle), hw_state);
    result = MTLK_ERR_HW;
    goto FINISH;
  }
  allow_mask = 0;
  switch (new_state) {
  case NET_STATE_IDLE:
    allow_mask = NET_STATE_HALTED | NET_STATE_READY; /* on core_start & core_stop */
    break;
  case NET_STATE_READY:
    allow_mask = NET_STATE_IDLE | NET_STATE_ACTIVATING | NET_STATE_DEACTIVATING;
    break;
  case NET_STATE_ACTIVATING:
    allow_mask = NET_STATE_READY | NET_STATE_DEACTIVATING; /* because activating/disconnecting may morph into one another */
    break;
  case NET_STATE_CONNECTED:
    allow_mask = NET_STATE_ACTIVATING;
    break;
  case NET_STATE_DEACTIVATING:
    allow_mask = NET_STATE_CONNECTED | NET_STATE_ACTIVATING; /* because activating/disconnecting may morph into one another */
    break;
  default:
    break;
  }
  /* check mask */
  if (net_state & allow_mask) {
    RLOG_SSS("%s: Going from %s to %s", mtlk_df_get_name(mtlk_vap_get_df(core->vap_handle)),
             mtlk_net_state_to_string(net_state), mtlk_net_state_to_string(new_state));
    mtlk_osal_atomic_set(&core->net_state, new_state);
  } else {
    RLOG_SSS("%s: Failed to change state from %s to %s", mtlk_df_get_name(mtlk_vap_get_df(core->vap_handle)),
             mtlk_net_state_to_string(net_state), mtlk_net_state_to_string(new_state));
    result = MTLK_ERR_WRONG_CONTEXT;
  }
FINISH:
  return result;
}

int __MTLK_IFUNC
mtlk_core_get_net_state (mtlk_core_t *core)
{
  mtlk_hw_state_e hw_state = __mtlk_core_get_hw_state(core);
  if (hw_state != MTLK_HW_STATE_READY && hw_state != MTLK_HW_STATE_UNLOADING) {
    return  NET_STATE_HALTED; /* FIXME? don't we need to do some cleanup, too to avoid resource leaks? */
  }
  return mtlk_osal_atomic_get(&core->net_state);
}

static uint32
mac_watchdog_timer_handler (mtlk_osal_timer_t *timer, mtlk_handle_t data)
{
  mtlk_error_t err;
  struct nic *nic = (struct nic *)data;

  err = _mtlk_core_execute_async(nic, MTLK_ABILITY_NONE, HANDLE_T(nic), wave_check_mac_watchdog,
                                 NULL, 0, _MTLK_CORE_PRIORITY_MAINTENANCE, NULL);

  if (err != MTLK_ERR_OK) {
    ELOG_DD("CID-%04x: Can't schedule MAC WATCHDOG task (err=%d)", mtlk_vap_get_oid(nic->vap_handle), err);
  }
  return 0;
}

#define WAVE_SYNC_HOSTAPD_TIMER   (10 * 1000) /* 10 seconds in ms */

static mtlk_error_t
wave_core_sync_hostapd_handler (mtlk_handle_t handle, const void *data,  uint32 data_size)
{
  struct nic *core = (struct nic *)handle;
  (void)wv_cfg80211_handle_flush_stations(core->vap_handle, NULL, 0); /* ignore ret code */
  return MTLK_ERR_OK;
}

static uint32
wave_core_sync_hostapd_on_timer (mtlk_osal_timer_t *timer, mtlk_handle_t handle)
{
  struct nic *core = (struct nic *)handle;
  if (!core || mtlk_osal_timer_is_cancelled(&core->slow_ctx->sync_hostapd_timer))
    return 0;

  mtlk_core_schedule_internal_task(core, handle, wave_core_sync_hostapd_handler, NULL, 0);
  return WAVE_SYNC_HOSTAPD_TIMER;
}

BOOL __MTLK_IFUNC
mtlk_core_cca_is_above_configured (mtlk_core_t *core, iwpriv_cca_th_t *cca_th_params)
{
  int i;
  for (i = 0; i < MTLK_CCA_TH_PARAMS_LEN; i++)
    if (core->slow_ctx->cca_adapt.cca_th_params[i] > cca_th_params->values[i]) return TRUE;

  return FALSE;
}

static BOOL
_mtlk_core_cca_is_below_limit (mtlk_core_t *core, int limit)
{
  int i;
  for (i = 0; i < MTLK_CCA_TH_PARAMS_LEN; i++)
    if (core->slow_ctx->cca_adapt.cca_th_params[i] < limit) return TRUE;

  return FALSE;
}

static uint32
cca_step_down_timer_clb_func (mtlk_osal_timer_t *timer, mtlk_handle_t data)
{
  struct nic *nic = (struct nic *)data;
  wave_radio_t *radio = wave_vap_radio_get(nic->vap_handle);
  iwpriv_cca_adapt_t cca_adapt_params;
  mtlk_pdb_size_t    cca_adapt_size = sizeof(cca_adapt_params);
  iwpriv_cca_th_t    cca_th_params;

  if (MTLK_ERR_OK != WAVE_RADIO_PDB_GET_BINARY(radio, PARAM_DB_RADIO_CCA_ADAPT, &cca_adapt_params, &cca_adapt_size)) {
    ELOG_V("cannot read CCA_ADAPT data");
    return 0;
  }

  /* read user config */
  if (MTLK_ERR_OK != mtlk_core_cfg_read_cca_threshold(nic, &cca_th_params)) {
    return MTLK_ERR_UNKNOWN;
  }

  ILOG3_V("CCA adaptive: step down timer triggered");
  if (mtlk_core_cca_is_above_configured(nic, &cca_th_params)) {
    uint32 interval = nic->slow_ctx->cca_adapt.step_down_coef * cca_adapt_params.step_down_interval;
    int i;

    ILOG2_D("CCA adaptive: step down, next interval %d", interval);
    for (i = 0; i < MTLK_CCA_TH_PARAMS_LEN; i++) {
      nic->slow_ctx->cca_adapt.cca_th_params[i] = MAX(cca_th_params.values[i],
         nic->slow_ctx->cca_adapt.cca_th_params[i] - (int)cca_adapt_params.step_down);
      cca_th_params.values[i] = nic->slow_ctx->cca_adapt.cca_th_params[i];
      ILOG2_DD("CCA adaptive: step down value %d: %d", i, cca_th_params.values[i]);
    }

    nic->slow_ctx->cca_adapt.interval = interval;
    _mtlk_process_hw_task(nic, SERIALIZABLE, mtlk_core_cfg_send_cca_thresholds, HANDLE_T(nic), &cca_th_params, sizeof(cca_th_params));

  } else nic->slow_ctx->cca_adapt.stepping_down = 0;

  return 0;
}

static void __MTLK_IFUNC
clean_all_sta_on_disconnect_sta_clb (mtlk_handle_t    usr_ctx,
                                     sta_entry *sta)
{
  struct nic      *nic  = HANDLE_T_PTR(struct nic, usr_ctx);
  const IEEE_ADDR *addr = mtlk_sta_get_addr(sta);

  ILOG1_Y("Station %Y disconnected", addr->au8Addr);

  /* Notify Traffic analyzer about STA disconnect */
  mtlk_ta_on_disconnect(mtlk_vap_get_ta(nic->vap_handle), addr);

  /* Remove all hosts MAC addr from switch MAC table */
  mtlk_hstdb_dcdp_remove_all_by_sta(&nic->slow_ctx->hstdb, sta);

  if (BR_MODE_WDS == MTLK_CORE_HOT_PATH_PDB_GET_INT(nic, CORE_DB_CORE_BRIDGE_MODE) ||
    mtlk_sta_is_4addr(sta)) {
    /* Don't remove HOST from DB if in WDS mode or 4 address station */
    mtlk_hstdb_stop_all_by_sta(&nic->slow_ctx->hstdb, addr);
  } else {
    mtlk_hstdb_remove_all_by_sta(&nic->slow_ctx->hstdb, addr);
  }

  /* Remove sta MAC addr from DC DP MAC table */
  mtlk_df_user_dcdp_remove_mac_addr(mtlk_vap_get_secondary_df(nic->vap_handle, sta->secondary_vap_id),
                                    addr->au8Addr);

  if (mtlk_vap_is_ap(nic->vap_handle) &&
      (MULTI_AP_BACKHAUL == MTLK_CORE_HOT_PATH_PDB_GET_INT(nic, CORE_DB_CORE_MULTI_AP_MODE) ||
       (MULTI_AP_EXT_HYBRID == MTLK_CORE_HOT_PATH_PDB_GET_INT(nic, CORE_DB_CORE_MULTI_AP_MODE) &&
        mtlk_sta_info_is_4addr(&sta->info)))) {
    mtlk_vap_unbind_backhaul_sta(nic->vap_handle, sta);
  }
}

static void
_mtlk_core_clean_vap_tx_on_disconnect(struct nic *nic)
{
  MTLK_UNREFERENCED_PARAM(nic);
}

void __MTLK_IFUNC
wave_clean_all_sta_on_disconnect (struct nic *nic)
{
  BOOL wait_all_packets_confirmed;

  wait_all_packets_confirmed = (mtlk_core_get_net_state(nic) != NET_STATE_HALTED);

  mtlk_stadb_disconnect_all(&nic->slow_ctx->stadb,
                            clean_all_sta_on_disconnect_sta_clb,
                            HANDLE_T(nic),
                            wait_all_packets_confirmed);

  _mtlk_core_clean_vap_tx_on_disconnect(nic);
}

static void
cleanup_on_disconnect (struct nic *nic)
{
  if (!mtlk_vap_is_ap(nic->vap_handle)) {
    /* rollback network mode */
    MTLK_CORE_PDB_SET_INT(nic, PARAM_DB_CORE_NET_MODE_CUR, core_cfg_get_network_mode_cfg(nic));
  }

  if (!_mtlk_core_has_connections(nic)) {
    if (mtlk_core_get_net_state(nic) == NET_STATE_DEACTIVATING) {
      MTLK_CORE_PDB_SET_MAC(nic, PARAM_DB_CORE_BSSID, mtlk_osal_eth_zero_addr);
    }
    _mtlk_core_clean_vap_tx_on_disconnect(nic);
  }

#ifdef CPTCFG_IWLWAV_SET_PM_QOS
  if (mtlk_global_stadb_is_empty()) {
    mtlk_mmb_update_cpu_dma_latency(mtlk_vap_get_hw(nic->vap_handle), MTLK_HW_PM_QOS_VALUE_NO_CLIENTS);
  }
#endif
}

static mtlk_error_t
_mtlk_core_ap_disconnect_sta_blocked(struct nic *nic, struct ieee80211_sta * mac80211_sta)
{
  mtlk_error_t res = MTLK_ERR_OK;
  int       net_state;
  mtlk_df_t *df;
  sta_entry *sta = NULL;
  uint16 sid;
  IEEE_ADDR addr;
  bool skip_stop_traffic = FALSE;

  MTLK_ASSERT(NULL != nic);
  MTLK_ASSERT(NULL != mac80211_sta);

  if (mac80211_sta == NULL) {
    ELOG_D("CID-%04x: mac80211_sta is NULL", mtlk_vap_get_oid(nic->vap_handle));
    res = MTLK_ERR_UNKNOWN;
    goto finish;
  }

  sta = wv_ieee80211_get_sta(mac80211_sta);
  if (!sta->is_added_to_driver) {
    ELOG_DY("CID-%04x: ERROR:Trying to remove sta which is not added:%Y", mtlk_vap_get_oid(nic->vap_handle), mac80211_sta->addr);
    if (mtlk_vap_is_sta(nic->vap_handle)) {
        ELOG_V("Skipping remove sta for client mode");
        goto finish;
    } else {
        ASSERT(FALSE);
    }
  }

  df = mtlk_vap_get_secondary_df(nic->vap_handle, sta->secondary_vap_id);
  MTLK_ASSERT(NULL != df);

  ieee_addr_set(&addr, mac80211_sta->addr);
  /* Check is STA is a peer AP */
  if (BR_MODE_WDS == MTLK_CORE_HOT_PATH_PDB_GET_INT(nic, CORE_DB_CORE_BRIDGE_MODE)) {
    wds_peer_disconnect(&nic->slow_ctx->wds_mng, mtlk_sta_get_addr(sta));
  }

  net_state = mtlk_core_get_net_state(nic);
  if (net_state == NET_STATE_HALTED) {
    /* Do not send anything to halted MAC or if STA hasn't been connected */
    res = MTLK_ERR_UNKNOWN;
    goto finish;
  }

  mtlk_sta_set_packets_filter(sta, MTLK_PCKT_FLTR_DISCARD_ALL);
  /* Remove sta MAC addr from switch MAC table */
  mtlk_df_user_dcdp_remove_mac_addr(df, mac80211_sta->addr);

#ifdef MTLK_WAVE_700
  if (mac80211_sta->ml_sta_info.is_ml) {
    wave_core_ap_disconnect_sta_mld(nic, sta);
    skip_stop_traffic = TRUE;
  }
#endif

  sid = mtlk_sta_get_sid(sta);
  if (!skip_stop_traffic) {
    res = wave_core_ap_stop_traffic(nic, sid, &addr); /* Send Stop Traffic Request to FW */
    if (MTLK_ERR_OK != res) {
      ELOG_DY("CID-%04x: Failed to stop traffic for STA %Y. Proceed Driver STA entry cleanup", mtlk_vap_get_oid(nic->vap_handle), mac80211_sta->addr);
      goto driver_sta_cleanup;
    }
  }

  res = wave_core_ap_remove_sta(nic, sid, &addr);
  if (MTLK_ERR_OK != res) {
    res = MTLK_ERR_UNKNOWN;
    ELOG_DY("CID-%04x: Failed to remove STA %Y. Proceed Driver STA entry cleanup", mtlk_vap_get_oid(nic->vap_handle), mac80211_sta->addr);
    goto driver_sta_cleanup;
  }

driver_sta_cleanup:
  /* At some places, mac80211 only warns and proceeds to delete mac80211_sta entry
   * even if Driver sta delete (state change) fails. So here, in case FW msg send fails,
   * do FW reset and proceed to delete Driver STA entry.
   */
  if ((res != MTLK_ERR_OK) && !wave_in_fw_recovery(nic)) {
      ELOG_D("CID-%04x: FW msg send failed for STA remove, asserting FW", mtlk_vap_get_oid(nic->vap_handle));
      (void)mtlk_hw_set_prop(mtlk_vap_get_hwapi(nic->vap_handle), MTLK_HW_RESET, NULL, 0);
  }

  /* check all BSS TX frames are confirmed for the STA */
#if WAVE_USE_BSS_TX_MONITOR
  {
    mtlk_hw_t *hw = mtlk_vap_get_hw(nic->vap_handle);
    MTLK_ASSERT(NULL != hw);
    if (!wave_hw_is_bss_tx_sta_cfmed(hw, sid)) {
      ELOG_D("CID-%04x: failed, asserting FW", mtlk_vap_get_oid(nic->vap_handle));
      if (!wave_in_fw_recovery(nic))
        (void)mtlk_hw_set_prop(mtlk_vap_get_hwapi(nic->vap_handle), MTLK_HW_RESET, NULL, 0);
    }
  }
#endif

  /* Remove all hosts MAC addr from switch MAC table */
  mtlk_hstdb_dcdp_remove_all_by_sta(&nic->slow_ctx->hstdb, sta);

  if (BR_MODE_WDS == MTLK_CORE_HOT_PATH_PDB_GET_INT(nic, CORE_DB_CORE_BRIDGE_MODE) ||
    mtlk_sta_is_4addr(sta)) {
    /* Don't remove HOST from DB if in WDS mode or 4 address station */
    mtlk_hstdb_stop_all_by_sta(&nic->slow_ctx->hstdb, &addr);
  } else {
    mtlk_hstdb_remove_all_by_sta(&nic->slow_ctx->hstdb, &addr);
  }

  mtlk_stadb_remove_sta(&nic->slow_ctx->stadb, sta);

  if (mtlk_vap_is_ap(nic->vap_handle) &&
      (MULTI_AP_BACKHAUL == MTLK_CORE_HOT_PATH_PDB_GET_INT(nic, CORE_DB_CORE_MULTI_AP_MODE) ||
       (MULTI_AP_EXT_HYBRID == MTLK_CORE_HOT_PATH_PDB_GET_INT(nic, CORE_DB_CORE_MULTI_AP_MODE) &&
        mtlk_sta_info_is_4addr(&sta->info)))) {
    mtlk_vap_unbind_backhaul_sta(nic->vap_handle, sta);
  }

  /* Notify ARP proxy if enabled */
  if (MTLK_CORE_PDB_GET_INT(nic, PARAM_DB_CORE_ARP_PROXY)) {
    mtlk_parp_notify_disconnect((char*) mtlk_df_get_name(df), (char *) mac80211_sta->addr);
  }

  /* Notify Traffic analyzer about STA disconnect */
  mtlk_ta_on_disconnect(mtlk_vap_get_ta(nic->vap_handle), &addr);

  cleanup_on_disconnect(nic);
  /* update disconnections statistics */
  nic->pstats.num_disconnects++;

finish:
  if (sta) {
    mtlk_sta_decref(sta); /* De-reference of find */
  }
  return res;
}

static int
reset_security_stuff(struct nic *nic)
{
  int res = MTLK_ERR_OK;

  memset(&nic->slow_ctx->keys, 0, sizeof(nic->slow_ctx->keys));
  nic->slow_ctx->default_key      = 0;
  nic->slow_ctx->default_mgmt_key = 0;
  nic->slow_ctx->default_bcn_key  = 0;
  nic->slow_ctx->wep_enabled      = FALSE;
  nic->slow_ctx->rsn_enabled      = FALSE;
  nic->slow_ctx->group_cipher     = IW_ENCODE_ALG_NONE;
  nic->slow_ctx->bcn_prot_cipher  = IW_ENCODE_ALG_NONE;
  return res;
}

static BOOL
_can_disconnect_now (struct nic *nic)
{
  return !mtlk_core_is_in_scan_mode(mtlk_core_get_master(nic->vap_handle)) ||
          wave_in_fw_recovery(nic);
}

/* kernel doesn't have structure of the BOOTP/DHCP header
 * so here it is defined according to rfc2131
 */

struct dhcphdr {
  u8      op;
#define BOOTREQUEST   1
#define BOOTREPLY     2
  u8      htype;
  u8      hlen;
  u8      hops;
  u32     xid;
  u16     secs;
  u16     flags;
#define BOOTP_BRD_FLAG 0x8000
  u32     ciaddr;
  u32     yiaddr;
  u32     siaddr;
  u32     giaddr;
  u8      chaddr[16];
  u8      sname[64];
  u8      file[128];
  u32     magic; /* NB: actually magic is a part of options */
  u8      options[0];
} __attribute__((aligned(1), packed));

typedef struct _whole_dhcp_packet_t
{
  struct ethhdr  eth_hdr;
  struct iphdr   ip_hdr;
  struct udphdr  udp_hdr;
  struct dhcphdr dhcp_hdr;
} __attribute__((aligned(1), packed)) whole_dhcp_packet_t;

#define UDP_PORT_DHCP_SERVER (67)
#define UDP_PORT_DHCP_CLIENT (68)

#define IP_ALEN 4
#define ARP_REQ_SEND_RATE_MS  300 /* 1 ARP request per 300ms */

BOOL __MTLK_IFUNC
mtlk_core_convert_dhcp_bcast_to_ucast(mtlk_nbuf_t *nbuf)
{
  BOOL res = FALSE;
  whole_dhcp_packet_t *wdp = (whole_dhcp_packet_t*) nbuf->data;

  if (nbuf->len >= sizeof(*wdp) &&
      wdp->eth_hdr.h_proto == __constant_htons(ETH_P_IP) &&
      wdp->ip_hdr.protocol == IPPROTO_UDP &&
      (wdp->udp_hdr.source == __constant_htons(UDP_PORT_DHCP_SERVER) || wdp->udp_hdr.source == __constant_htons(UDP_PORT_DHCP_CLIENT)) &&
      (wdp->udp_hdr.dest == __constant_htons(UDP_PORT_DHCP_SERVER) || wdp->udp_hdr.dest == __constant_htons(UDP_PORT_DHCP_CLIENT)))
  {
    mtlk_osal_copy_eth_addresses(wdp->eth_hdr.h_dest, wdp->dhcp_hdr.chaddr);
    res = TRUE;
  }

  return res;
}

mtlk_nbuf_t* subst_ip_to_arp_probe ( mtlk_nbuf_t            **nbuf_in_out,
                                     mtlk_osal_timestamp_t *last_arp_req)
{
  struct ethhdr *ether_header_in, *ether_header_arp;
  struct iphdr  *ip_header_in;
  struct arphdr *arp_hdr;
  uint8         *arp_data;
  mtlk_nbuf_t   *nbuf_arp, *nbuf_in;
  uint32         arp_pck_size;
  mtlk_osal_timestamp_diff_t diff;

  /* Limit ARP probe sending rate */
  diff = mtlk_osal_timestamp_diff(mtlk_osal_timestamp(), *last_arp_req);
  if (mtlk_osal_timestamp_to_ms(diff) < ARP_REQ_SEND_RATE_MS){
    goto subst_ip_to_arp_probe_err;
  }

  /* IP packet sanity check */
  nbuf_in = *nbuf_in_out;
  ether_header_in = (struct ethhdr *)nbuf_in->data;
  if( ntohs(ether_header_in->h_proto) != ETH_P_IP){
    goto subst_ip_to_arp_probe_err;
  }

  ip_header_in = (struct iphdr *)(nbuf_in->data + sizeof(struct ethhdr));
  if (!ip_header_in->saddr || !ip_header_in->daddr){
    goto subst_ip_to_arp_probe_err;
  }

  /* Allocate and Compose ARP probe packet */
  arp_pck_size = sizeof(struct ethhdr) + sizeof(struct arphdr) + (ETH_ALEN + IP_ALEN)*2;
  nbuf_arp = mtlk_df_nbuf_alloc(arp_pck_size);

  if (!nbuf_arp){
    WLOG_V("Unable to allocate buffer for ARP probe");
    goto subst_ip_to_arp_probe_err;
  }

  /* Init nbuf fields */
  nbuf_arp->dev = nbuf_in->dev;
  nbuf_arp->len = arp_pck_size;
  mtlk_df_nbuf_set_priority(nbuf_arp, MTLK_WMM_ACI_DEFAULT_CLASS);

  /* Fill up ETH header */
  ether_header_arp = (struct ethhdr *)nbuf_arp->data;
  mtlk_osal_copy_eth_addresses(ether_header_arp->h_source, ether_header_in->h_source);
  memset(ether_header_arp->h_dest, 0xFF, ETH_ALEN);
  ether_header_arp->h_proto = htons(ETH_P_ARP);

  /* Fill up ARP header */
  arp_hdr = (struct arphdr *)(ether_header_arp + 1);
  arp_hdr->ar_hrd = htons(ARPHRD_ETHER);
  arp_hdr->ar_pro = htons(ETH_P_IP);
  arp_hdr->ar_hln = ETH_ALEN;
  arp_hdr->ar_pln = IP_ALEN;
  arp_hdr->ar_op  = htons(ARPOP_REQUEST);

  /* Fill up ARP body */
  arp_data = (uint8 *)(arp_hdr + 1);
  mtlk_osal_copy_eth_addresses(arp_data + 0,                             ether_header_in->h_source); /* Sender MAC - from IN pck */
  mtlk_osal_zero_ip4_address  (arp_data + ETH_ALEN                       );                          /* Sender IP  - all 0 */
  mtlk_osal_copy_eth_addresses(arp_data + ETH_ALEN + IP_ALEN,            ether_header_in->h_dest);   /* Target MAC - from IN pck */
  mtlk_osal_copy_ip4_addresses(arp_data + ETH_ALEN + IP_ALEN + ETH_ALEN, &ip_header_in->daddr);      /* Target IP  - from IN pck */

  /* Release original nbuf */
  mtlk_df_nbuf_free(nbuf_in);

  *nbuf_in_out = nbuf_arp;
  *last_arp_req = mtlk_osal_timestamp();

  ILOG2_Y("Sending ARP probe to %Y", &ether_header_in->h_dest);

  return nbuf_arp;

subst_ip_to_arp_probe_err:

  return NULL;
}

/*****************************************************************************
**
** NAME         mtlk_core_handle_tx_data
**
** PARAMETERS   vap_handle           Handle of VAP object
**              nbuf                 Skbuff to transmit
**
** DESCRIPTION  Entry point for TX buffers
**
******************************************************************************/
void __MTLK_IFUNC
mtlk_core_handle_tx_data (mtlk_vap_handle_t vap_handle, mtlk_nbuf_t *nbuf)
{
  mtlk_core_t   *nic = mtlk_vap_get_core(vap_handle);
  struct ethhdr *ether_header = (struct ethhdr *)nbuf->data;
  multi_ap_mode_t multi_ap_mode = MTLK_CORE_HOT_PATH_PDB_GET_INT(nic, CORE_DB_CORE_MULTI_AP_MODE);
  bridge_mode_t  bridge_mode;
  sta_entry     *sta = NULL; /* destination STA in AP mode or destination BSS in STA mode */
  uint32         nbuf_flags = 0;
  sta_db        *stadb;

  MTLK_ASSERT(NULL != nic);
  stadb = &nic->slow_ctx->stadb;
  CPU_STAT_BEGIN_TRACK(CPU_STAT_ID_TX_OS);

  /* Transmit only if connected to someone */
  if (__UNLIKELY(!_mtlk_core_has_connections(nic))) {
    mtlk_core_inc_cnt(nic, MTLK_CORE_CNT_TX_PACKETS_DISCARDED_NO_PEERS);
    goto tx_error;
  }

#if defined(CPTCFG_IWLWAV_PER_PACKET_STATS)
  {
    /* get private fields */
    mtlk_nbuf_priv_t *nbuf_priv = mtlk_nbuf_priv(nbuf);
    mtlk_nbuf_priv_stats_set(nbuf_priv, MTLK_NBUF_STATS_TS_SQ_IN, mtlk_hw_get_timestamp(vap_handle));
  }
#endif

  ILOG4_Y("802.3 tx DA: %Y", ether_header->h_dest);
  ILOG4_Y("802.3 tx SA: %Y", ether_header->h_source);
  mtlk_eth_parser(nbuf->data, nbuf->len, mtlk_df_get_name(mtlk_vap_get_df(vap_handle)), "TX");

  bridge_mode = MTLK_CORE_HOT_PATH_PDB_GET_INT(nic, CORE_DB_CORE_BRIDGE_MODE);

  if (mtlk_vap_is_ap(vap_handle)) {
     /* AP mode interface */
    if (MULTI_AP_BACKHAUL & multi_ap_mode) {
      mtlk_df_user_t *df_user = mtlk_df_user_from_ndev(nbuf->dev);

      if (MULTI_AP_FRONTHAUL & multi_ap_mode) { /* MULTI_AP_EXT_HYBRID */
        if (df_user == mtlk_df_get_user(mtlk_vap_get_df(vap_handle)))
          goto hybrid_3addr;
      }

      /* MultiAP: backhaul AP always has ONLY one station per netdev and always
       * transmits frames to the connected STA as is, w/o additional processing. */
      if (__UNLIKELY(df_user == NULL)) {
        ELOG_D("CID-%04x: Failed to get df_user", mtlk_vap_get_oid(vap_handle));
        goto tx_error;
      }
      sta = mtlk_df_user_get_backhaul_sta(df_user);
      if (!sta) {
        ILOG3_D("CID-%04x: Failed to get destination STA", mtlk_vap_get_oid(vap_handle));
        mtlk_core_inc_cnt(nic, MTLK_CORE_CNT_TX_PACKETS_DISCARDED_DRV_UNKNOWN_DESTINATION_DIRECTED);
        goto tx_error;
      }
      nbuf_flags = MTLK_NBUFF_UNICAST;
      goto send_tx_data;
    }

hybrid_3addr:
    /* check frame destination */
    if (mtlk_osal_eth_is_multicast(ether_header->h_dest)) {
      if (mtlk_osal_eth_is_broadcast(ether_header->h_dest)) {
        if (nic->dgaf_disabled) {
          if (mtlk_core_convert_dhcp_bcast_to_ucast(nbuf)) {
            ILOG3_V("DGAF disabled: Convert DHCP to Unicast");
            mtlk_core_inc_cnt(nic, MTLK_CORE_CNT_TX_PACKETS_TO_UNICAST_DGAF_DISABLED);
            goto unicast;
          } else {
            ILOG3_V("DGAF disabled: Skip Broadcast packet");
            mtlk_core_inc_cnt(nic, MTLK_CORE_CNT_TX_PACKETS_SKIPPED_DGAF_DISABLED);
            goto tx_error;
          }
        }
        nbuf_flags |= MTLK_NBUFF_BROADCAST;
      } else {
        if (nic->dgaf_disabled) {
          if (wv_check_dgaf_disabled_packet(nbuf)) {
            ILOG3_V("DGAF disabled: Convert RA or DHCP to Unicast");
            mtlk_core_inc_cnt(nic, MTLK_CORE_CNT_TX_PACKETS_TO_UNICAST_DGAF_DISABLED);
          } else {
            ILOG3_V("DGAF disabled: Skip Multicast packet");
            mtlk_core_inc_cnt(nic, MTLK_CORE_CNT_TX_PACKETS_SKIPPED_DGAF_DISABLED);
            goto tx_error;
          }
        }
        nbuf_flags |= MTLK_NBUFF_MULTICAST;
      }
      goto send_tx_data;
    }

unicast:
    /* Process unicast packet */
    sta = mtlk_stadb_find_sta(stadb, ether_header->h_dest);
    if (!sta) { /* search even if not WDS - to support STA bridge mode */
      sta = mtlk_hstdb_find_sta(&nic->slow_ctx->hstdb, ether_header->h_dest);
    }

    if (sta) {
      nbuf_flags |= MTLK_NBUFF_UNICAST;
    } else {
      ILOG3_Y("Unknown destination (%Y)", ether_header->h_dest);
      mtlk_core_inc_cnt(nic, MTLK_CORE_CNT_TX_PACKETS_DISCARDED_DRV_UNKNOWN_DESTINATION_DIRECTED);
      /* To support 3addr and 4addr repeater,
          in case of IP UNICAST packet to unknown destination,
          substitute original packet with ARP probe */
      if (NULL == subst_ip_to_arp_probe(&nbuf, &nic->slow_ctx->last_arp_probe)){
        goto tx_error; /* Fail to generate ARP packet */
      }
      nbuf_flags |= MTLK_NBUFF_BROADCAST;
    }
  } else {
    /* Station mode interface */
    sta = mtlk_stadb_get_ap(stadb);
    if (!sta) {
      ELOG_D("CID-%04x: peer ap sta_entry not found in sta mode", mtlk_vap_get_oid(vap_handle));
      goto tx_error;
    }
    if (!mtlk_sta_is_4addr(sta) && MTLK_CORE_HOT_PATH_PDB_CMP_MAC(nic, CORE_DB_CORE_MAC_ADDR, ether_header->h_source)) {
      mtlk_dump(0, nbuf->data, MIN(nbuf->len, 64), "ERROR, not our source MAC address in sta mode");
      goto tx_error;
    }
    nbuf_flags |= MTLK_NBUFF_UNICAST;
  }

send_tx_data:
  {
    mtlk_core_handle_tx_data_t tx_data;
    /* initialize tx_data */
    memset(&tx_data, 0, sizeof(tx_data));
    tx_data.nbuf = nbuf;
    tx_data.dst_sta = sta;
    tx_data.vap_id = mtlk_vap_get_id(nic->vap_handle);
    mtlk_mc_transmit(nic, &tx_data, nbuf_flags, bridge_mode, NULL);
  }
  if (sta) mtlk_sta_decref(sta);
  CPU_STAT_END_TRACK(CPU_STAT_ID_TX_OS);
  return;

tx_error:
  mtlk_df_nbuf_free(nbuf);
  nbuf = NULL;
  if (sta) mtlk_sta_decref(sta);
  CPU_STAT_END_TRACK(CPU_STAT_ID_TX_OS);
}

#define SEQUENCE_NUMBER_LIMIT                    (0x1000)
#define SEQ_DISTANCE(seq1, seq2) (((seq2) - (seq1) + SEQUENCE_NUMBER_LIMIT) \
                                    % SEQUENCE_NUMBER_LIMIT)

/* proxy_arp enabled - all ARP and solicitation/advertisement packets will be send only to Linux IP stack
 * hs2.0 enabled and DGAF is disabled -  Gratitous ARP and unsolicitation (MC/BC) packets will be send only to Linux IP stack
 */
static __INLINE void
__mtlk_core_hs20_proxy_arp_frwd (mtlk_core_t* nic, mtlk_nbuf_t *nbuf, uint32 *flags)
{
  if(*flags & MTLK_NBUFF_FORWARD) {
    struct ethhdr *ether_header = (struct ethhdr *)nbuf->data;
    if (MTLK_CORE_PDB_GET_INT(nic, PARAM_DB_CORE_ARP_PROXY)) {
      if(ether_header->h_proto == htons(ETH_P_ARP)) {
        *flags &= ~MTLK_NBUFF_FORWARD;
        *flags |= MTLK_NBUFF_CONSUME; /* let the system forward */
        ILOG4_D("CID-%04x: BC ARP packet is not forwarded", mtlk_vap_get_oid(nic->vap_handle));
      } else if (wv_is_na_ns(nbuf)) {
        *flags &= ~MTLK_NBUFF_FORWARD;
        *flags |= MTLK_NBUFF_CONSUME; /* let the system forward */
        ILOG4_D("CID-%04x: IPV6 neighbor adver./solicit. packet is not forwarded", mtlk_vap_get_oid(nic->vap_handle));
      }
    } else if ((mtlk_df_user_get_hs20_status(mtlk_vap_get_df(nic->vap_handle))) &&
                (*flags & (MTLK_NBUFF_BROADCAST | MTLK_NBUFF_MULTICAST))) {
      /* proxy_arp is disabled and hs20 is enabled, no need to check for dgaf due to forward flag is set */
      if(ether_header->h_proto == htons(ETH_P_ARP)) {
        if (nbuf->len >= (sizeof(struct ethhdr) + sizeof(struct arphdr) + (ETH_ALEN + IP_ALEN)*2)) {
          struct arphdr *arp_hdr = (struct arphdr *)(ether_header + 1);
          if ((arp_hdr->ar_hrd == htons(ARPHRD_ETHER)) && (arp_hdr->ar_pro == htons(ETH_P_IP)) &&
                (arp_hdr->ar_hln == ETH_ALEN) && (arp_hdr->ar_pln == IP_ALEN) && (arp_hdr->ar_op  == htons(ARPOP_REQUEST))) {
            uint8 *arp_data = (uint8 *)(arp_hdr + 1);
            uint8 *sip = arp_data + ETH_ALEN;
            uint8 *tip = arp_data + ETH_ALEN + IP_ALEN + ETH_ALEN;
            if (!memcmp(sip, tip, IP_ALEN)) {
              *flags &= ~MTLK_NBUFF_FORWARD;
              ILOG4_DD("CID-%04x: gratuitous ARP is not forwarded:%B", mtlk_vap_get_oid(nic->vap_handle), htonl(*(uint32 *)sip));
            }
          }
        }
      } else {
        /* check if it is neighbor unsolicitation advertisement packet */
        const struct in6_addr *ipv6_src = wv_is_unsolic_na(nbuf);
        if (ipv6_src) {
          *flags &= ~MTLK_NBUFF_FORWARD;
          ILOG4_DK("CID-%04x: unsolicitation advertisement is not forwarded:%K", mtlk_vap_get_oid(nic->vap_handle), ipv6_src);
        }
      }
    }
  }
}

static __INLINE BOOL
__mtlk_core_is_looped_packet (mtlk_core_t* nic, mtlk_nbuf_t *nbuf)
{
  struct ethhdr *ether_header = (struct ethhdr *)nbuf->data;
  return (0 == MTLK_CORE_HOT_PATH_PDB_CMP_MAC(nic, CORE_DB_CORE_MAC_ADDR, ether_header->h_source));
}

BOOL __MTLK_IFUNC
mtlk_core_is_looped_packet (mtlk_core_t* nic, mtlk_nbuf_t *nbuf)
{
  return __mtlk_core_is_looped_packet(nic, nbuf);
}

/* Look for a STA in both stadb and hstdb */
static __INLINE sta_entry *
__wave_core_find_sta (mtlk_core_t *core, const unsigned char *mac)
{
  sta_entry *sta = mtlk_stadb_find_sta(&core->slow_ctx->stadb, mac);
  if (!sta)
    sta = mtlk_hstdb_find_sta(&core->slow_ctx->hstdb, mac);

  return sta;
}

sta_entry * __MTLK_IFUNC
wave_core_find_sta (mtlk_core_t *core, const unsigned char *mac)
{
  MTLK_ASSERT(core);
  MTLK_ASSERT(mac);
  if (!core || !mac)
    return NULL;

  return __wave_core_find_sta(core, mac);
}

/* Send Packet to the OS's protocol stack or forward */
void __MTLK_IFUNC
mtlk_core_analyze_and_send_up (mtlk_core_t* nic, mtlk_core_handle_tx_data_t *tx_data, sta_entry *src_sta)
{
  uint32 nbuf_flags = 0;
  mtlk_nbuf_t *nbuf = tx_data->nbuf;
  multi_ap_mode_t multi_ap_mode = MTLK_CORE_HOT_PATH_PDB_GET_INT(nic, CORE_DB_CORE_MULTI_AP_MODE);
  struct ethhdr *ether_header = (struct ethhdr *)nbuf->data;
  BOOL is_igmp_or_mld = FALSE;

  if (__UNLIKELY(__mtlk_core_is_looped_packet(nic, nbuf))) {
    ILOG3_Y("drop rx packet - the source address is the same as own address: %Y", ether_header->h_source);
    mtlk_df_nbuf_free(nbuf);
    return;
  }

  if (mtlk_vap_is_sta(nic->vap_handle)) {
    ILOG3_V("Client mode");
    nbuf_flags |= MTLK_NBUFF_UNICAST | MTLK_NBUFF_CONSUME;
  } else if (MULTI_AP_BACKHAUL == multi_ap_mode) {
    /* MultiAP: backhaul AP always has ONLY one connected station and always forwards frames
     * from the connected STA to Linux as is, without additional processing. */
    ILOG3_V("AP in Backhaul mode - short path");
    nbuf_flags |= MTLK_NBUFF_UNICAST | MTLK_NBUFF_CONSUME;
  } else if (MULTI_AP_EXT_HYBRID == multi_ap_mode && mtlk_sta_is_4addr(src_sta)) {
    ILOG3_V("AP in Hybrid mode & 4addr station - short path");
    nbuf_flags |= MTLK_NBUFF_UNICAST | MTLK_NBUFF_CONSUME;
  } else {
    /* AP mode */
    mtlk_nbuf_t *nbuf_orig = nbuf;
    sta_entry *dst_sta = NULL;
    sta_db *stadb = &nic->slow_ctx->stadb;
    bridge_mode_t bridge_mode = MTLK_CORE_HOT_PATH_PDB_GET_INT(nic, CORE_DB_CORE_BRIDGE_MODE);

    if (mtlk_osal_eth_is_broadcast(ether_header->h_dest)) {
      /* Broadcast packet */
      nbuf_flags |= MTLK_NBUFF_BROADCAST | MTLK_NBUFF_CONSUME;
      if (MTLK_CORE_HOT_PATH_PDB_GET_INT(nic, CORE_DB_CORE_AP_FORWARDING) && !nic->dgaf_disabled) {
        nbuf_flags |= MTLK_NBUFF_FORWARD;
       }
       /* Increment Rx broadcast counters */
       src_sta->sta_stats_cntrs.broadcastRecvPacketCount++;
       src_sta->sta_stats_cntrs.broadcastRecvBytesCount += mtlk_df_nbuf_get_data_length(nbuf);
    } else if (mtlk_osal_eth_is_multicast(ether_header->h_dest)) {
      /* Multicast packet */
      nbuf_flags |= MTLK_NBUFF_MULTICAST | MTLK_NBUFF_CONSUME;
      if (MTLK_CORE_HOT_PATH_PDB_GET_INT(nic, CORE_DB_CORE_AP_FORWARDING) && !nic->dgaf_disabled)
        nbuf_flags |= MTLK_NBUFF_FORWARD;
    } else {
      /* Unicast packet */
      nbuf_flags |= MTLK_NBUFF_UNICAST;
      if (MTLK_CORE_HOT_PATH_PDB_GET_INT(nic, CORE_DB_CORE_AP_FORWARDING)) {
        /* Search of DESTINATION MAC ADDRESS of RECEIVED packet */
        dst_sta = mtlk_stadb_find_sta(stadb, ether_header->h_dest);
        if ((dst_sta == NULL) && ((BR_MODE_WDS == bridge_mode))) {
          dst_sta = mtlk_hstdb_find_sta(&nic->slow_ctx->hstdb, ether_header->h_dest);
        }

        if (dst_sta != NULL) {
          if ((wave_is_mld_sta(dst_sta)) && (dst_sta->info.MainVapId != mtlk_vap_get_id_fw(dst_sta->vap_handle))) {
            /* let the system forward - the main vap for dst sta is in another band */
            nbuf_flags |= MTLK_NBUFF_CONSUME;
          } else if (dst_sta != src_sta) {
            nbuf_flags |= MTLK_NBUFF_FORWARD;
    #if MTLK_USE_DIRECTCONNECT_DP_API
            if (src_sta->vap_handle == dst_sta->vap_handle) {
              /* Allow Acceleration subsystem to learn about session when driver shortcuts
                 forwarding without going to stack. The flag can be set safely even if acceleration isn't available */
              nbuf_flags |= MTLK_NBUFF_SHORTCUT;
              #if (CPTCFG_IWLWAV_MAX_DLEVEL >= 2)
              if (mtlk_mmb_fastpath_available(mtlk_vap_get_hw(nic->vap_handle))) {
                /* Output log message only if acceleratoin is available */
                ILOG2_DYDY("Learn shortcut from STA_ID %d (MAC:%Y) to STA_ID %d (MAC %Y)",
                      mtlk_sta_get_sid(src_sta), ether_header->h_source, mtlk_sta_get_sid(dst_sta), ether_header->h_dest);
              }
              #endif
            }
    #endif
          } else {
            ILOG3_V("Loop detected ! Don't forward packet !");
          }
        } else nbuf_flags |= MTLK_NBUFF_CONSUME; /* let the system forward - dst STA not found */
      } else nbuf_flags |= MTLK_NBUFF_CONSUME; /* let the system forward - FWD disabled */
    }

    if (nbuf_flags & (MTLK_NBUFF_BROADCAST | MTLK_NBUFF_MULTICAST)) {
      const IEEE_ADDR * addr;
      if (wave_is_mld_sta(src_sta))
        addr = wave_get_sta_mld_addr(src_sta);
      else
        addr = mtlk_sta_get_addr(src_sta);

      mtlk_mc_parse(nic, nbuf, addr, src_sta->secondary_vap_id, &is_igmp_or_mld);

      if ((nbuf_flags & MTLK_NBUFF_MULTICAST) &&
          !is_igmp_or_mld &&
          MTLK_CORE_HOT_PATH_PDB_GET_INT(nic, CORE_DB_CORE_INTRA_VAP_MCAST))
        nbuf_flags &= ~MTLK_NBUFF_FORWARD;
    }

    __mtlk_core_hs20_proxy_arp_frwd(nic, nbuf, &nbuf_flags);

    switch (nbuf_flags & (MTLK_NBUFF_FORWARD | MTLK_NBUFF_CONSUME))
    {
      case (MTLK_NBUFF_FORWARD | MTLK_NBUFF_CONSUME):
        nbuf = mtlk_df_nbuf_clone_no_priv(nbuf);
        break;

      case 0:
        mtlk_df_nbuf_free(nbuf);
        ILOG3_P("nbuf %p dropped - consumption is disabled", nbuf);
        if (dst_sta)
          mtlk_sta_decref(dst_sta);
        return;
    }

    if (nbuf_flags & MTLK_NBUFF_FORWARD) {
      CPU_STAT_BEGIN_TRACK(CPU_STAT_ID_TX_FWD);
      if (__LIKELY(nbuf)) {
        /* update tx_data before transmitting */
        tx_data->nbuf = nbuf;
        tx_data->dst_sta = dst_sta;
        tx_data->vap_id = mtlk_vap_get_id(nic->vap_handle);
        mtlk_mc_transmit(nic, tx_data, nbuf_flags, bridge_mode, src_sta);
      } else {
        ELOG_D("CID-%04x: Can't clone the packet for forwarding", mtlk_vap_get_oid(nic->vap_handle));
        nic->pstats.fwd_cannot_clone++;
        nic->pstats.fwd_dropped++;
      }

      nbuf = nbuf_orig;
      /* Count rxed data to be forwarded */
      mtlk_sta_on_rx_packet_forwarded(src_sta, nbuf);
      CPU_STAT_END_TRACK(CPU_STAT_ID_TX_FWD);
    }
    if (dst_sta)
      mtlk_sta_decref(dst_sta);
  } /* AP mode */

  if (__LIKELY(nbuf) && (nbuf_flags & MTLK_NBUFF_CONSUME)) {
    int net_state;
    ether_header = (struct ethhdr *)nbuf->data;

#if defined MTLK_DEBUG_IPERF_PAYLOAD_RX
    //check if it is an iperf's packet we use to debug
    mtlk_iperf_payload_t *iperf = debug_ooo_is_iperf_pkt((uint8*) ether_header);
    if (iperf != NULL) {
      iperf->ts.tag_tx_to_os = htonl(debug_iperf_priv.tag_tx_to_os);
      debug_iperf_priv.tag_tx_to_os++;
    }
#endif

    ILOG3_Y("802.3 rx DA: %Y", nbuf->data);
    ILOG3_Y("802.3 rx SA: %Y", nbuf->data+ETH_ALEN);
    ILOG3_D("packet protocol %04x", ntohs(ether_header->h_proto));

    net_state = mtlk_core_get_net_state(nic);
    if (net_state != NET_STATE_CONNECTED) {
      mtlk_df_nbuf_free(nbuf);
      if (net_state != NET_STATE_DEACTIVATING) {
        WLOG_DD("CID-%04x: Data rx in not connected state (current state is %d), dropped", mtlk_vap_get_oid(nic->vap_handle), net_state);
      }
      return;
    }

    if (ntohs(ether_header->h_proto) == ETH_P_IP) {
      struct iphdr *iph;
      uint16 ip_len;
      uint32 nbuf_len = mtlk_df_nbuf_get_data_length(nbuf);

      if (nbuf_len < (sizeof(struct ethhdr) + sizeof(struct iphdr))) {
        ILOG2_V("malformed IP packet due to uncomplete hdr, dropped\n");
        mtlk_df_nbuf_free(nbuf);
        return;
      }

      iph = (struct iphdr *)((mtlk_handle_t)ether_header + sizeof(struct ethhdr));
      ip_len = ntohs(iph->tot_len);
      if((iph->ihl < 5) || (ip_len < (iph->ihl * sizeof(uint32))) || (ip_len > (nbuf_len - sizeof(struct ethhdr)))) {
        ILOG2_V("malformed IP packet due to payload invalidity, dropped\n");
        mtlk_df_nbuf_free(nbuf);
        return;
      }
    }

#ifdef MTLK_DEBUG_CHARIOT_OOO
    /* check out-of-order */
    {
      int diff, seq_prev;

      seq_prev = nic->seq_prev_sent[nbuf_priv->seq_qos];
      diff = SEQ_DISTANCE(seq_prev, nbuf_priv->seq_num);
      if (diff > SEQUENCE_NUMBER_LIMIT / 2)
        ILOG2_DDD("ooo: qos %u prev = %u, cur %u\n", nbuf_priv->seq_qos, seq_prev, nbuf_priv->seq_num);
      nic->seq_prev_sent[nbuf_priv->seq_qos] = nbuf_priv->seq_num;
    }
#endif

    /* Count only packets sent to OS */
    mtlk_sta_on_packet_indicated(src_sta, nbuf, nbuf_flags);

    CPU_STAT_END_TRACK(CPU_STAT_ID_RX_HW);
    mtlk_df_ui_indicate_rx_data(mtlk_vap_get_secondary_df(nic->vap_handle,
                                                          src_sta->secondary_vap_id), nbuf);
  }
}

void
mtlk_core_record_xmit_err(struct nic *nic, mtlk_nbuf_t *nbuf, uint32 nbuf_flags)
{
  if (nbuf_flags & MTLK_NBUFF_FORWARD) {
    nic->pstats.fwd_dropped++;
  }

  if (++nic->pstats.tx_cons_drop_cnt > nic->pstats.tx_max_cons_drop)
    nic->pstats.tx_max_cons_drop = nic->pstats.tx_cons_drop_cnt;
}

/*****************************************************************************
 * Helper functions for _mtlk_core_handle_tx_data():
 ******************************************************************************/
static __INLINE int
__mtlk_core_prepare_and_xmit (mtlk_core_t* nic, mtlk_core_handle_tx_data_t *tx_data, BOOL wds, uint16 sta_sid, int mc_index, uint32 nbuf_flags)
{
    int res = MTLK_ERR_PKT_DROPPED;
    mtlk_nbuf_t       *nbuf         = tx_data->nbuf;
    struct ethhdr     *ether_header = (struct ethhdr *)nbuf->data;
    mtlk_hw_api_t     *hw_api       = mtlk_vap_get_hwapi(nic->vap_handle);
    uint32             tid          = mtlk_df_nbuf_get_priority(nbuf);
    uint32             ntx_free     = 0;
    mtlk_hw_data_req_mirror_t *msg  = NULL;

    /* Sanity check */
    if (__UNLIKELY(tid >= NTS_TIDS_GEN6)) {
      ELOG_D("Invalid priority: %u", tid);
      goto tx_skip;
    }

    /* prepare hw message */
    msg = DATA_REQ_MIRROR_PTR(mtlk_hw_get_msg_to_send(hw_api, nic->vap_handle, &ntx_free));
    if (__UNLIKELY(!msg)) {
      ++nic->pstats.ac_dropped_counter[tid];
      nic->pstats.tx_overruns++;
      nic->pstats.txerr_swpath_overruns++;
      goto tx_skip;
    }

    ++nic->pstats.ac_used_counter[tid];
    mtlk_osal_atomic_inc(&nic->unconfirmed_data);
    ILOG4_P("got from hw_msg %p", msg);

    /* fill fields */
    msg->nbuf       = nbuf;
    msg->size       = mtlk_df_nbuf_get_data_length(nbuf);
    msg->sid        = sta_sid;
    msg->tid        = tid;
    msg->wds        = (uint8)wds;
    msg->mcf        = wds ? 0 : nbuf_flags & (MTLK_NBUFF_MULTICAST | MTLK_NBUFF_BROADCAST);
    msg->frame_type = (ntohs(ether_header->h_proto) >= ETH_P_802_3_MIN) ? FRAME_TYPE_ETHERNET : FRAME_TYPE_IPX_LLC_SNAP;
    msg->mc_index   = mc_index;
  #ifdef CPTCFG_IWLWAV_PER_PACKET_STATS
    {
        mtlk_nbuf_priv_t *nbuf_priv = mtlk_nbuf_priv(nbuf);
        mtlk_nbuf_priv_stats_set(nbuf_priv, MTLK_NBUF_STATS_DATA_SIZE, msg->size);

        #if defined(CPTCFG_IWLWAV_TSF_TIMER_ACCESS_ENABLED)
        mtlk_nbuf_priv_stats_set(nbuf_priv, MTLK_NBUF_STATS_TS_FW_IN, mtlk_hw_get_timestamp(nic->vap_handle));
        #endif
    }
  #endif

    /* send hw message */
    res = mtlk_hw_send_data(hw_api, nic->vap_handle, msg);
    if (__LIKELY(res == MTLK_ERR_OK))
        return res;

    ELOG_D("mtlk_hw_send_data ret (%d)", res);
    nic->pstats.txerr_swpath_hwsend++;

tx_skip:
    /* release hw message and record error's statistic */
    if (msg) {
      mtlk_hw_release_msg_to_send(hw_api, HW_MSG_PTR(msg));
    }

    return res;
}

#if MTLK_USE_DIRECTCONNECT_DP_API
static __INLINE int
__mtlk_core_dcdp_prepare_and_xmit (mtlk_core_t *nic, mtlk_core_handle_tx_data_t *tx_data, BOOL wds, uint16 sta_sid, int mc_index, uint32 nbuf_flags)
{
  int res = mtlk_df_ui_dp_prepare_and_xmit(nic->vap_handle, tx_data, wds, sta_sid, mc_index, nbuf_flags);
  if (__UNLIKELY(MTLK_ERR_OK != res)) {
    nic->pstats.txerr_dc_xmit++;
  }
  return res;
}
#endif

/*****************************************************************************
**
** NAME         _mtlk_core_handle_tx_data
**
** PARAMETERS   nbuf                Skbuff to transmit
**              dev                 Device context
**
** RETURNS      Skbuff transmission status
**
** DESCRIPTION  This function called to perform packet transmission.
**
******************************************************************************/
static int
_mtlk_core_handle_tx_data (mtlk_core_t *nic, mtlk_core_handle_tx_data_t *data, uint32 nbuf_flags)
{
  int res = MTLK_ERR_PKT_DROPPED;
  uint16 sta_sid;
  sta_entry *sta = data->dst_sta;
  struct ethhdr *ether_header = (struct ethhdr *)data->nbuf->data;
  multi_ap_mode_t multi_ap_mode = MTLK_CORE_HOT_PATH_PDB_GET_INT(nic, CORE_DB_CORE_MULTI_AP_MODE);
  int mc_index = MCAST_GROUP_BROADCAST;
  BOOL wds = 0;
  mtlk_hw_t *hw;
  wave_mhi_PDstats_vap_t *mhi_vap_PDstat;

  MTLK_UNUSED_VAR(ether_header);
  mtlk_dump(5, data->nbuf->data, data->nbuf->len, "nbuf->data received from OS");

  if (__LIKELY(sta)) {
    if (MTLK_PCKT_FLTR_DISCARD_ALL == mtlk_sta_get_packets_filter(sta)) {
      mtlk_sta_on_packet_dropped(sta, MTLK_TX_DISCARDED_DROP_ALL_FILTER);
      nic->pstats.txerr_drop_all_filter++;
      goto tx_skip;
    }
  }

#ifdef MTLK_WAVE_700
  if ((nbuf_flags & MTLK_NBUFF_UNICAST) && (sta) && (wave_is_mld_sta(sta)) &&
      (sta->info.MainVapId != mtlk_vap_get_id_fw(sta->vap_handle))) {
    ILOG3_Y("Drop the packet arrived in ML sta %Y secondary link", mtlk_sta_get_addr(sta));
    goto tx_skip;
  }
#endif

  hw = mtlk_vap_get_hw(nic->vap_handle);
  sta_sid = wave_hw_get_all_sta_sid(hw);
  if (MULTI_AP_BACKHAUL == multi_ap_mode) {
    /* Multi-AP: AP works as backhaul AP. All frames should be sent as-is to the single 4-address STA*/
    MTLK_ASSERT(sta);
    if (!sta) {
      /* In fact this code should not be executed, but added there for the safety */
      mtlk_core_inc_cnt(nic, MTLK_CORE_CNT_TX_PACKETS_DISCARDED_NO_PEERS);
      goto tx_skip;
    }
    sta_sid = mtlk_sta_get_sid(sta);
    data->vap_id = sta->secondary_vap_id;
  } else {
    /* Determine multicast group index */
    if (nbuf_flags & MTLK_NBUFF_MULTICAST) {
      mc_index = mtlk_mc_get_grid(nic, data->nbuf);
      if (MCAST_GROUP_UNDEF == mc_index) {
        ILOG3_V("Drop due to undefined MC index.");
        nic->pstats.txerr_undef_mc_index++;
        goto tx_skip;
      }
      if ((nic->dgaf_disabled) && ((MCAST_GROUP_BROADCAST == mc_index) || (!wv_is_dhcpv6(data->nbuf)))) {
        /* If dgaf is disabled we should only let dhcpv6 known multicast packets
         * and no other multicast packets. They will be converted to unicast in fw (as it is reliable multicast) */
        ILOG3_V("Drop due to dgaf disabled");
        mtlk_core_inc_cnt(nic, MTLK_CORE_CNT_TX_PACKETS_SKIPPED_DGAF_DISABLED);
        goto tx_skip;
      }
    }
    ILOG3_DD("CID-%04x: multicast group: %d", mtlk_vap_get_oid(nic->vap_handle), mc_index);

    if (nbuf_flags & MTLK_NBUFF_BROADCAST) {
      mhi_vap_PDstat = &nic->mhi_vap_PDstat;
      mtlk_osal_atomic_inc(&mhi_vap_PDstat->PDstats.txInBroadcastPD);
      mtlk_osal_atomic64_add(&mhi_vap_PDstat->PDstats64.txInBroadcastBytePD, (mtlk_df_nbuf_get_data_length(data->nbuf)));
    }

    if (sta) {
      BOOL is_4addr_sta = mtlk_sta_is_4addr(sta);
      /* Use 4 address for peer APs and 4 address stations */
      if (MULTI_AP_EXT_HYBRID == multi_ap_mode && is_4addr_sta) {
        data->vap_id = sta->secondary_vap_id;
      } else if (sta->peer_ap || is_4addr_sta) {
        wds = 1;
        ILOG4_DYY("WDS/four address STA packet: Peer %d, STA %Y, ETH Dest %Y",
          sta->peer_ap, mtlk_sta_get_addr(sta), ether_header->h_dest);
      }
      sta_sid = mtlk_sta_get_sid(sta);
    }
  }
  ILOG3_D("SID: %d", sta_sid);

#if MTLK_USE_DIRECTCONNECT_DP_API
  if (mtlk_mmb_dcdp_path_available(hw))
    res = __mtlk_core_dcdp_prepare_and_xmit(nic, data, wds, sta_sid, mc_index, nbuf_flags);
  else
#endif
    res = __mtlk_core_prepare_and_xmit(nic, data, wds, sta_sid, mc_index, nbuf_flags);

  if (__LIKELY(res == MTLK_ERR_OK)) {
    mtlk_df_ui_notify_tx_start(mtlk_vap_get_df(nic->vap_handle));
  } else {
    if(sta) {
      mtlk_sta_on_packet_dropped(sta, MTLK_TX_DISCARDED_TX_QUEUE_OVERFLOW);
    } else {
      mtlk_core_inc_cnt(nic, MTLK_CORE_CNT_TX_PACKETS_DISCARDED_TX_QUEUE_OVERFLOW);
    }
  }

tx_skip:
  return res;
}

#if MTLK_USE_DIRECTCONNECT_DP_API
int __MTLK_IFUNC
mtlk_core_get_dev_spec_info (struct net_device *dev, mtlk_nbuf_t *nbuf, mtlk_core_dev_spec_info_t *dev_spec_info)
{
  struct ethhdr *ether_header = (struct ethhdr *)nbuf->data;
  sta_entry *dst_sta = NULL;
  mtlk_df_user_t *df_user;
  mtlk_vap_handle_t vap_handle;
  mtlk_core_t *core;

  df_user = mtlk_df_user_from_ndev(dev);
  if (!df_user) {
    return MTLK_ERR_UNKNOWN;
  }

  vap_handle = mtlk_df_get_vap_handle(mtlk_df_user_get_df(df_user));
  core = mtlk_vap_get_core(vap_handle);

  /* analyze and adjust packet's priority */
  wave_core_qos_adjust_priority(core, nbuf);

  dev_spec_info->vap_id  = wave_df_user_get_dcdp_vap_id(df_user);

  dev_spec_info->mc_index = MCAST_GROUP_BROADCAST;
  dev_spec_info->sta_id = wave_core_get_all_sta_sid(core);
  dev_spec_info->frame_type = (ntohs(ether_header->h_proto) >= ETH_P_802_3_MIN) ? FRAME_TYPE_ETHERNET : FRAME_TYPE_IPX_LLC_SNAP;

  if (mtlk_vap_is_ap(vap_handle)) {
    /* AP mode */
    if (mtlk_osal_eth_is_multicast(ether_header->h_dest)) {
      /* Multicast/broadcast*/
      if (!mtlk_osal_eth_is_broadcast(ether_header->h_dest)) {
          dev_spec_info->mc_index = mtlk_mc_get_grid(core, nbuf);
          if (dev_spec_info->mc_index == MCAST_GROUP_UNDEF)
            ILOG1_V("Undefined multicast group index");
      }
      dev_spec_info->mcf = 1;
    } else {
      /* Unicast */

      if (mtlk_df_user_is_secondary(df_user)) {
        dst_sta = mtlk_df_user_get_backhaul_sta(df_user);
        if (dst_sta)
          dev_spec_info->sta_id = mtlk_sta_get_sid(dst_sta);
        else
          return MTLK_ERR_UNKNOWN;
      } else if (MULTI_AP_BACKHAUL == MTLK_CORE_HOT_PATH_PDB_GET_INT(core, CORE_DB_CORE_MULTI_AP_MODE)) {
        dst_sta = mtlk_stadb_find_sta(&core->slow_ctx->stadb, ether_header->h_dest);
        if (dst_sta)
          dev_spec_info->sta_id = mtlk_sta_get_sid(dst_sta);
        else {
          dst_sta = mtlk_df_user_get_backhaul_sta(df_user);
          if (dst_sta)
            dev_spec_info->sta_id = mtlk_sta_get_sid(dst_sta);
          else
            return MTLK_ERR_UNKNOWN;
        }
      } else {
        dst_sta = mtlk_stadb_find_sta(&core->slow_ctx->stadb, ether_header->h_dest);
        if (!dst_sta) /* search even if not WDS - to support STA bridge mode */
          dst_sta = mtlk_hstdb_find_sta(&core->slow_ctx->hstdb, ether_header->h_dest);

        if (dst_sta)
          dev_spec_info->sta_id = mtlk_sta_get_sid(dst_sta);
        else
          return MTLK_ERR_UNKNOWN;
      }
#ifdef BEST_EFFORT_TID_SPREADING
      wave_core_qos_adjust_be_priority(dst_sta, nbuf);
#endif

      mtlk_sta_decref(dst_sta);
      dev_spec_info->mcf = 0;
    }
  } else {
    /* STA mode */
    dst_sta = mtlk_stadb_get_ap(&core->slow_ctx->stadb);
    if (dst_sta) {
      dev_spec_info->sta_id = mtlk_sta_get_sid(dst_sta);
      mtlk_sta_decref(dst_sta);
    }
    /* in STA mode we always send unicast packets*/
    dev_spec_info->mcf = 0;
  }
  return MTLK_ERR_OK;
}
#endif /* MTLK_USE_DIRECTCONNECT_DP_API */

#ifdef DEBUG_WPS
static char test_wps_ie0[] = {0xdd, 7, 0x00, 0x50, 0xf2, 0x04, 1, 2, 3};
static char test_wps_ie1[] = {0xdd, 7, 0x00, 0x50, 0xf2, 0x04, 4, 5, 6};
static char test_wps_ie2[] = {0xdd, 7, 0x00, 0x50, 0xf2, 0x04, 7, 8, 9};
#endif

/*
+----+-------++-----------------++------------------- -----------------------------------------+
|     \      ||  Interf. Dis.   ||                   Inerf. Enabled                            |
|      \     ||--------+--------||--------+--------+----------+----------+----------+----------|
|       \    || No Meas| No Meas|| No Meas| No Meas| Measure  | Measure  | Measure  | Measure  |
|        \   || Scan20 | Scan40 || Scan20 | Scan40 | Scan20   | Scan20   | Scan40   | Scan40   |
|         \  || Regular| Regular|| Regular| Regular|  LONG    | SHORT    |  LONG    |  SHORT   |
|          \ || all       all   || all    | all    | unrestr  | restr    | unrestr  | restr    |
| Spectrum  \|| clr $$ | clr $$ || clr $$ | clr $$ |          |          |          |          |
+------------++--------+--------++--------+--------+----------+----------+----------+----------+
|   20       ||   1    |   .    ||    .   |   .    |    1     |    2     |    .     |    .     |
|   40       ||   2    |   1    ||    1   |   .    |    .     |    .     |    2     |    3     |
| 20/40,coex ||   2    |   1    ||    .   |   1    |    2     |    3     |    .     |    .     |
+------------++--------+--------++--------+--------+----------+----------+----------+----------+

1..3 - scan execution order
.    - scan skipped
*/
#define SCAN_TABLE_IDX_20     0
#define SCAN_TABLE_IDX_40     1
#define SCAN_TABLE_IDX_20_40  2
#define SCAN_TABLE_IDX_COEX   3
#define SCAN_TABLE_IDX_LAST   4

#define SCAN_TABLE_NO_MEAS_20_REGULAR_ALL   1
#define SCAN_TABLE_NO_MEAS_40_REGULAR_ALL   2
#define SCAN_TABLE_MEAS_20_LONG_UNRESTR     3
#define SCAN_TABLE_MEAS_20_SHORT_RESTR      4
#define SCAN_TABLE_MEAS_40_LONG_UNRESTR     5
#define SCAN_TABLE_MEAS_40_SHORT_RESTR      6
#define SCAN_TABLE_MEAS_LAST                7

#define SCAN_TABLE_ROW_LAST 4

static const uint8 scan_table_interf_en[SCAN_TABLE_IDX_LAST][SCAN_TABLE_ROW_LAST] = {
  /* SCAN_TABLE_IDX_20 */
  { SCAN_TABLE_MEAS_20_LONG_UNRESTR,   SCAN_TABLE_MEAS_20_SHORT_RESTR,  0, 0},
  /* SCAN_TABLE_IDX_40 */
  { SCAN_TABLE_NO_MEAS_20_REGULAR_ALL, SCAN_TABLE_MEAS_40_LONG_UNRESTR, SCAN_TABLE_MEAS_40_SHORT_RESTR, 0},
  /* SCAN_TABLE_IDX_20_40 */
  { SCAN_TABLE_NO_MEAS_40_REGULAR_ALL, SCAN_TABLE_MEAS_20_LONG_UNRESTR, SCAN_TABLE_MEAS_20_SHORT_RESTR, 0},
};

static const uint8 scan_table_interf_dis[SCAN_TABLE_IDX_LAST][SCAN_TABLE_ROW_LAST] = {
  /* SCAN_TABLE_IDX_20 */
  { SCAN_TABLE_NO_MEAS_20_REGULAR_ALL, 0, 0, 0},
  /* SCAN_TABLE_IDX_40 */
  { SCAN_TABLE_NO_MEAS_40_REGULAR_ALL, SCAN_TABLE_NO_MEAS_20_REGULAR_ALL, 0, 0},
  /* SCAN_TABLE_IDX_20_40 */
  { SCAN_TABLE_NO_MEAS_40_REGULAR_ALL, SCAN_TABLE_NO_MEAS_20_REGULAR_ALL, 0, 0},
};

/* Get/set param DB value of MGMT_FRAMES_RATE */
static uint32 _core_management_frames_rate_get (mtlk_core_t *core)
{
  return (uint32)MTLK_CORE_PDB_GET_INT(core, PARAM_DB_CORE_MGMT_FRAMES_RATE);
}

static void _wave_core_management_frames_rate_set (mtlk_core_t *core, uint32 value)
{
  MTLK_CORE_PDB_SET_INT(core, PARAM_DB_CORE_MGMT_FRAMES_RATE, value);
}

/* We can't to use the real configured value because we don't send 11g rates to FW in 11b mode */
uint32 __MTLK_IFUNC
wave_core_management_frames_rate_select (mtlk_core_t *core)
{
  mtlk_core_t *mcore = mtlk_core_get_master(core->vap_handle);

  if ((!mcore) || ((UMI_PHY_TYPE_BAND_2_4_GHZ == __wave_core_chandef_get(mcore)->chan.band) &&
                   (MTLK_NETWORK_11B_ONLY == core_cfg_get_network_mode_cur(core)))) {
    WLOG_DD("CID-%04x: Set MCS VAP Management to default (%02x) value in FW due to 11B HW mode",
            mtlk_vap_get_oid(core->vap_handle), FIXED_MCS_VAP_MANAGEMENT_IS_NOT_VALID);
    return FIXED_MCS_VAP_MANAGEMENT_IS_NOT_VALID;
  }
  return _core_management_frames_rate_get(core);
}

#define WAVE_HW_11B_RATES_NUM  4
#define WAVE_HW_11G_RATES_NUM  8
#define WAVE_HW_11A_RATES_NUM  8

static uint32 _core_basic_rates_11g_set (mtlk_core_t *core, mtlk_hw_band_e band, uint8 *rates_buf, uint32 rates_buf_len, uint32 rates_fill_len)
{
  uint32 rates_len = rates_fill_len;
  uint8 rates[] = {
    (1 * MBIT_RATE_ENCODING_MUL), /* rates 11b */
    (2 * MBIT_RATE_ENCODING_MUL),
    (55 / HUNDRED_KBIT_RATE_ENCODING_DIV),
    (11 * MBIT_RATE_ENCODING_MUL),
    (6 * MBIT_RATE_ENCODING_MUL), /* rates 11g or 11a */
    (9 * MBIT_RATE_ENCODING_MUL),
    (12 * MBIT_RATE_ENCODING_MUL),
    (18 * MBIT_RATE_ENCODING_MUL),
    (24 * MBIT_RATE_ENCODING_MUL),
    (36 * MBIT_RATE_ENCODING_MUL),
    (48 * MBIT_RATE_ENCODING_MUL),
    (54 * MBIT_RATE_ENCODING_MUL)
  };

  if (UMI_PHY_TYPE_BAND_2_4_GHZ == band)
  {
    uint32 mode = core_cfg_get_network_mode_cur(core);

    if ((MTLK_NETWORK_11BG_MIXED == mode) ||
        (MTLK_NETWORK_11BGN_MIXED == mode) ||
        (MTLK_NETWORK_11BGNAX_MIXED == mode) ||
        (MTLK_NETWORK_11BGNAXBE_MIXED == mode))
    {
      if (rates_buf_len >= sizeof(rates)) {
        wave_memcpy(rates_buf, rates_buf_len, rates, sizeof(rates));
        rates_len = sizeof(rates);
      }
    }
    else if ((MTLK_NETWORK_11G_ONLY == mode) ||
             (MTLK_NETWORK_11GN_MIXED == mode) ||
             (MTLK_NETWORK_11GNAX_MIXED == mode) ||
             (MTLK_NETWORK_11GNAXBE_MIXED == mode))
    {
      if (rates_buf_len >= WAVE_HW_11A_RATES_NUM) {
        wave_memcpy(rates_buf, rates_buf_len, &rates[WAVE_HW_11B_RATES_NUM], WAVE_HW_11A_RATES_NUM);
        rates_len = WAVE_HW_11A_RATES_NUM;
      }
    }
    else if (MTLK_NETWORK_11B_ONLY == mode)
    {
      if (rates_buf_len >= WAVE_HW_11B_RATES_NUM) {
        wave_memcpy(rates_buf, rates_buf_len, rates, WAVE_HW_11B_RATES_NUM);
        rates_len = WAVE_HW_11B_RATES_NUM;
      }
    }
  }
  else /* if (UMI_PHY_TYPE_BAND_5_2_GHZ == band) */
  {
    if (rates_buf_len >= WAVE_HW_11A_RATES_NUM) {
      wave_memcpy(rates_buf, rates_buf_len, &rates[WAVE_HW_11B_RATES_NUM], WAVE_HW_11A_RATES_NUM);
      rates_len = WAVE_HW_11A_RATES_NUM;
    }
  }
  return rates_len;
}

uint32 __MTLK_IFUNC wave_core_param_db_basic_rates_get (mtlk_core_t *core, mtlk_hw_band_e band, uint8 *rates_buf, uint32 rates_buf_len)
{
  mtlk_pdb_size_t rates_len = rates_buf_len;
  mtlk_pdb_t *param_db_core = mtlk_vap_get_param_db(core->vap_handle);
  mtlk_pdb_id_t param_id = (band == UMI_PHY_TYPE_BAND_2_4_GHZ ?
                            PARAM_DB_CORE_BASIC_RATES_2 : PARAM_DB_CORE_BASIC_RATES_5);

  if (MTLK_ERR_OK == wave_pdb_get_binary(param_db_core, param_id, rates_buf, &rates_len))
    rates_len = _core_basic_rates_11g_set(core, band, rates_buf, rates_buf_len, rates_len);
  else
    rates_len = 0;

  return rates_len;
}

/* ===============================================================================
 * This function fills UMI_SET_BSS request with values from parameters db,
 * combined with bss_parameters.
 * =============================================================================== */
static void
_mtlk_core_fill_set_bss_request(mtlk_core_t *core, UMI_SET_BSS *req, struct mtlk_bss_parameters *params)
{
    mtlk_pdb_t *param_db_core = mtlk_vap_get_param_db(core->vap_handle);
    struct nic *master_core = mtlk_core_get_master(core->vap_handle);
    struct mtlk_chan_def *current_chandef = __wave_core_chandef_get(master_core);
    wave_radio_t *radio = wave_vap_radio_get(core->vap_handle);

    MTLK_ASSERT(req);
    MTLK_ASSERT(params);
    memset(req, 0, sizeof(*req));

    /* Dealing w/ cts protection */
    if (params->use_cts_prot == -1)
        params->use_cts_prot = MTLK_CORE_PDB_GET_INT(core, PARAM_DB_CORE_HT_PROTECTION);
    req->protectionMode = params->use_cts_prot;

    /* Dealing w/ short slot time */
    if (params->use_short_slot_time == -1)
        params->use_short_slot_time = WAVE_RADIO_PDB_GET_INT(radio, PARAM_DB_RADIO_SHORT_SLOT);
    req->slotTime = params->use_short_slot_time;

    /* Dealing w/ short preamble */
    if (params->use_short_preamble == -1)
        params->use_short_preamble = WAVE_RADIO_PDB_GET_INT(radio, PARAM_DB_RADIO_SHORT_PREAMBLE);
    req->useShortPreamble = params->use_short_preamble;
    /* FIXME figure out how preamble affects the rates */

    current_chandef->chan.band = core_cfg_get_freq_band_cfg(core);

    /* Dealing w/ basic rates */
    if (!params->basic_rates_len) {
        /* copy existing parameters from params db */
        req->u8Rates_Length = (uint8)wave_core_param_db_basic_rates_get(core, current_chandef->chan.band,
                                                                        req->u8Rates, sizeof(req->u8Rates));
    } else {
        /* copy from input structure */
        wave_memcpy(req->u8Rates, sizeof(req->u8Rates), params->basic_rates, params->basic_rates_len);
        req->u8Rates_Length = (uint8)_core_basic_rates_11g_set(core, current_chandef->chan.band,
                                                               req->u8Rates, sizeof(req->u8Rates), params->basic_rates_len);
    }

    /* Dealing w/ HT/VHT MCS-s and flags */
    {
        mtlk_pdb_size_t mcs_len;
        mcs_len = sizeof(req->u8HT_MCS_Set);
        wave_pdb_get_binary(param_db_core, PARAM_DB_CORE_RX_MCS_BITMASK, &req->u8HT_MCS_Set, &mcs_len);

        mcs_len = sizeof(req->u8VHT_Mcs_Nss);
        wave_pdb_get_binary(param_db_core, PARAM_DB_CORE_VHT_MCS_NSS, &req->u8VHT_Mcs_Nss, &mcs_len);

        req->flags = wave_pdb_get_int(param_db_core, PARAM_DB_CORE_SET_BSS_FLAGS);

        if (mtlk_df_user_get_hs20_status(mtlk_vap_get_df(core->vap_handle))) {
            req->flags |= MTLK_BFIELD_VALUE(VAP_ADD_FLAGS_HS20_ENABLE, 1, uint8);
        }
    }

    /* 802.11AX HE support */
    {
      mtlk_pdb_size_t mcs_len;
      mcs_len = sizeof(req->u8HE_Mcs_Nss);
      /* Each MCS Map subfield of u8VHT_Mcs_Nss/u8HE_Mcs_Nss is two bits wide,
       * 3 indicates that n spatial streams is not supported for HE PPDUs.
       * Filling it with 0xff - meaning all subfields are equal to 3 by default */
      memset(req->u8HE_Mcs_Nss, 0xff, sizeof(req->u8HE_Mcs_Nss));
      wave_pdb_get_binary(param_db_core, PARAM_DB_CORE_HE_MCS_NSS, &req->u8HE_Mcs_Nss, &mcs_len);
      mtlk_dump(1, &req->u8HE_Mcs_Nss, mcs_len, "dump of u8HE_Mcs_Nss:");

      /* Set BSS color */
      if (params->he_bss_color.color == MAX_UINT8) {
        req->u8HE_Bss_Color_info = MTLK_CORE_PDB_GET_INT(core, PARAM_DB_CORE_HE_BSS_COLOR);
      } else {
        req->u8HE_Bss_Color_info = params->he_bss_color.color;
        if (!params->he_bss_color.enabled)
          req->u8HE_Bss_Color_info |= HE_OPERATION_BSS_COLOR_DISABLED_FLAG;
      }

      if (mtlk_vap_is_sta(core->vap_handle)) {
        req->flags |= MTLK_BFIELD_VALUE(VAP_ADD_FLAGS_HE, 1, uint8);
      }

      ILOG1_DD("CID-%04x: UMI_SET_BSS->u8HE_Bss_Color_info: 0x%x", mtlk_vap_get_oid(core->vap_handle), req->u8HE_Bss_Color_info);
    }

#ifdef MTLK_WAVE_700
    /* 802.11BE EHT support */
    if (wave_radio_is_gen7(radio)) {
      mtlk_pdb_size_t eht_mcs_len;
      eht_mcs_len = sizeof(req->u8EHT_Mcs_Nss);
      /* Each MCS Map subfield of u8EHT_Mcs_Nss is 4 bits wide,
       * 0 indicates that n spatial streams is not supported for EHT PPDUs. */
      memset(req->u8EHT_Mcs_Nss, 0, sizeof(req->u8EHT_Mcs_Nss));
      wave_pdb_get_binary(param_db_core, PARAM_DB_CORE_EHT_MCS_NSS, &req->u8EHT_Mcs_Nss, &eht_mcs_len);
      mtlk_dump(1, &req->u8EHT_Mcs_Nss, eht_mcs_len, "dump of u8EHT_Mcs_Nss:");

      if (mtlk_vap_is_sta(core->vap_handle)) {
        req->flags |= MTLK_BFIELD_VALUE(VAP_ADD_FLAGS_EHT, 1, uint8);
      }
    }
#endif
}

/* ===============================================================================
 * This function updates values in parameters db using data in already filled
 * UMI_SET_BSS request, according to values in bss_parameters as update indicators
 * ===============================================================================
 */
static void
_mtlk_core_update_bss_params(mtlk_core_t *core, UMI_SET_BSS *req, struct mtlk_bss_parameters *params)
{
    mtlk_pdb_t *param_db_core = mtlk_vap_get_param_db(core->vap_handle);
    struct nic *master_core = mtlk_core_get_master(core->vap_handle);
    struct mtlk_chan_def *current_chandef = __wave_core_chandef_get(master_core);
    wave_radio_t *radio = wave_vap_radio_get(core->vap_handle);

    /* Dealing w/ cts protection */
    if (params->use_cts_prot != -1)
      MTLK_CORE_PDB_SET_INT(core, PARAM_DB_CORE_HT_PROTECTION, req->protectionMode);

    /* Dealing w/ short slot time */
    if (params->use_short_slot_time != -1)
      WAVE_RADIO_PDB_SET_INT(radio, PARAM_DB_RADIO_SHORT_SLOT, req->slotTime);

    /* Dealing w/ short preamble */
    if (params->use_short_preamble != -1)
      WAVE_RADIO_PDB_SET_INT(radio, PARAM_DB_RADIO_SHORT_PREAMBLE, req->useShortPreamble);
    /* FIXME figure out how preamble affects the rates */

    /* Dealing w/ basic rates */
    if (params->basic_rates_len) {
        wave_pdb_set_binary(param_db_core,
                          (current_chandef->chan.band == UMI_PHY_TYPE_BAND_2_4_GHZ
                           ? PARAM_DB_CORE_BASIC_RATES_2
                           : PARAM_DB_CORE_BASIC_RATES_5),
                             req->u8Rates, params->basic_rates_len);
    }
    if (params->he_bss_color.color != MAX_UINT8) {
      MTLK_CORE_PDB_SET_INT(core, PARAM_DB_CORE_HE_BSS_COLOR, req->u8HE_Bss_Color_info);
    }
}

static int _mtlk_core_recover_rx_threshold (mtlk_core_t *core);

/* This function should be called from master serializer context */
static int
_core_change_bss_by_params(mtlk_core_t *master_core, struct mtlk_bss_parameters *params)
{
  mtlk_core_t *core = NULL;
  UMI_SET_BSS fw_request;
  int res = MTLK_ERR_OK;
  mtlk_pdb_t *param_db_core = NULL;
  mtlk_vap_handle_t vap_handle;
  wave_radio_t *radio;
  mtlk_card_type_info_t card_type_info;
  int net_state;

  MTLK_ASSERT(master_core == mtlk_core_get_master(master_core->vap_handle));

  /* Prevent set bss while in block_tx */
  if (mtlk_core_is_block_tx_mode(master_core)) {
    res = MTLK_ERR_NOT_READY;
    goto end;
  }

  /* Prevent set bss while in scan */
  if (mtlk_core_is_in_scan_mode(master_core)) {
    res = MTLK_ERR_RETRY;
    goto end;
  }

  if (MTLK_ERR_OK != mtlk_vap_manager_get_vap_handle(mtlk_vap_get_manager(master_core->vap_handle), params->vap_id, &vap_handle)) {
    res = MTLK_ERR_VALUE;
    goto end;
  }
  core = mtlk_vap_get_core (vap_handle);
  param_db_core = mtlk_vap_get_param_db(core->vap_handle);
  radio = wave_vap_radio_get(core->vap_handle);
  net_state = mtlk_core_get_net_state(core);
  if (net_state != NET_STATE_ACTIVATING &&
      net_state != NET_STATE_CONNECTED ) {
      ELOG_D("CID-%04x: inappropriate NET_STATE", mtlk_vap_get_oid(core->vap_handle));
    res = MTLK_ERR_NOT_READY;
    goto end;
  }

  if (mtlk_vap_is_ap(core->vap_handle)) {
    /* Update ap_isolate parameter */
    wave_pdb_set_int(param_db_core, PARAM_DB_CORE_AP_FORWARDING, !params->ap_isolate);

    /* Update ht_protection value if it was changed earlier by iwpriv */
    if (MTLK_CORE_PDB_GET_INT(core, PARAM_DB_CORE_IWPRIV_FORCED) & PARAM_DB_CORE_IWPRIV_FORCED_HT_PROTECTION_FLAG) {
        params->use_cts_prot = MTLK_CORE_PDB_GET_INT(core, PARAM_DB_CORE_HT_PROTECTION);
    }
  } else {
    wave_pdb_set_int(param_db_core, PARAM_DB_CORE_AP_FORWARDING, FALSE);
  }

  {
    struct intel_vendor_he_oper he_operation = {0};
    mtlk_pdb_size_t he_operation_len = sizeof(he_operation);
    wave_pdb_get_binary(param_db_core, PARAM_DB_CORE_HE_OPERATION, &he_operation, &he_operation_len);

    if(wave_radio_max_tx_antennas_get(radio) == MAX_NUM_TX_ANTENNAS)
      he_operation.co_hosted_bss = HE_OPERATION_MAX_COHOSTED_BSS_IND_4STS;

    wave_pdb_set_binary(param_db_core, PARAM_DB_CORE_HE_OPERATION, &he_operation, he_operation_len);
  }

  /* Fill UMI_SET_BSS FW request */
  _mtlk_core_fill_set_bss_request(core, &fw_request, params);

  /* Process UM_BSS_SET_BSS_REQ */
  res = mtlk_core_set_bss(core, master_core, &fw_request);

  /* Update params db */
  if (MTLK_ERR_OK == res)
      _mtlk_core_update_bss_params(core, &fw_request, params);

  /* send tx power offset and rx threshold here on non-ASIC to avoid sending in time-critical
   *  periods later */
  mtlk_hw_get_prop(mtlk_vap_get_hwapi(core->vap_handle), MTLK_HW_PROP_CARD_TYPE_INFO,
                   &card_type_info, sizeof(card_type_info));
  if (!_mtlk_card_is_asic(card_type_info)) { /* non ASIC, i.e. FPGA/Emul */
    _mtlk_core_recover_rx_threshold(core);
    mtlk_core_send_tx_power_limit_offset(core,
                POWER_TO_DBM(WAVE_RADIO_PDB_GET_INT(radio, PARAM_DB_RADIO_TX_POWER_LIMIT_OFFSET)));
  }

end:
  return res;
}

/* This function should be called from master serializer context */
static int
_core_change_bss (mtlk_handle_t hcore, const void* data, uint32 data_size)
{
  mtlk_core_t *master_core = HANDLE_T_PTR(mtlk_core_t, hcore);
  mtlk_clpb_t *clpb = *(mtlk_clpb_t **) data;
  struct mtlk_bss_parameters *params;
  unsigned params_size;
  int res = MTLK_ERR_OK;

  MTLK_ASSERT(sizeof(mtlk_clpb_t *) == data_size);

  params = mtlk_clpb_enum_get_next(clpb, &params_size);
  MTLK_CLPB_TRY(params, params_size)
    res = _core_change_bss_by_params(master_core, params);
  MTLK_CLPB_FINALLY(res)
    return mtlk_clpb_push_res(clpb, res);
  MTLK_CLPB_END;
}

static void _mtlk_core_flush_bcast_probe_resp_list (mtlk_core_t *nic);
static void _mtlk_core_flush_ucast_probe_resp_list (mtlk_core_t *nic);
static int  _mtlk_core_add_ucast_probe_resp_entry (mtlk_core_t* nic, const IEEE_ADDR *addr);
static int  _mtlk_core_del_ucast_probe_resp_entry (mtlk_core_t *nic, const IEEE_ADDR *addr);
static BOOL _mtlk_core_ucast_probe_resp_entry_exists (mtlk_core_t *nic, const IEEE_ADDR *addr);

void __MTLK_IFUNC
mtlk_core_on_bss_tx (mtlk_core_t *nic,  uint32 subtype)
{
  MTLK_ASSERT(nic);
  MTLK_UNREFERENCED_PARAM(subtype); /* can be used in the future */
  ILOG3_DD("CID-%04x: mgmt subtype %d", mtlk_vap_get_oid(nic->vap_handle), subtype);
  mtlk_core_inc_cnt(nic, MTLK_CORE_CNT_MAN_FRAMES_SENT);
}

void __MTLK_IFUNC
mtlk_core_on_bss_cfm (mtlk_core_t *nic, IEEE_ADDR *peer, uint32 extra_processing, uint32 subtype, BOOL is_broadcast)
{
  MTLK_ASSERT(nic);
  mtlk_core_inc_cnt(nic, MTLK_CORE_CNT_MAN_FRAMES_CONFIRMED);

  ILOG3_DDDYD("CID-%04x: type %d, subtype %d, peer %Y, is_broadcast %d",
            mtlk_vap_get_oid(nic->vap_handle), extra_processing, subtype, peer->au8Addr, (int)is_broadcast);
  if (extra_processing == PROCESS_NULL_DATA_PACKET && nic->waiting_for_ndp_ack)
    mtlk_osal_event_set(&nic->ndp_acked);
  else if (extra_processing == PROCESS_EAPOL && nic->waiting_for_eapol_ack)
    mtlk_osal_event_set(&nic->eapol_acked);

  if (subtype == MAN_TYPE_PROBE_RES) {
    if (is_broadcast) {
        _mtlk_core_del_bcast_probe_resp_entry(nic, peer);
    } else {
        _mtlk_core_del_ucast_probe_resp_entry(nic, peer);
    }
  }
}

/*
 * Wait for the ack from FW for Transmitted DPP
 * public action frame,upon ack the scan timer
 * will execute imidiatley and switch back to
 * original channel from off channel
 * */
#ifndef WAVE_BSS_TX_DPP_EASY_CONNECT
void __MTLK_IFUNC
mtlk_core_on_bss_dpp_acked (mtlk_core_t *nic, uint32 subtype, uint8 action_code ,uint8 action_field, BOOL is_dpp)
{
  struct scan_support *ss;
  MTLK_ASSERT(nic);

  ss = __wave_core_scan_support_get(nic);

  if((MAN_TYPE_ACTION == subtype) && ( action_code == IEEE80211_PUBLIC_ACTION_FRAME_CATEGORY ) &&
      (action_field == IEEE80211_PUBLIC_ACTION_FRAME_ACTION) && (is_dpp))
  {
    mtlk_osal_hrtimer_set(&ss->scan_timer, 0, MTLK_HRTIMER_MODE_REL);
  }
}
#endif

/* Update counters for BSS reserved queue */
void __MTLK_IFUNC
mtlk_core_on_bss_res_queued (mtlk_core_t *nic)
{
  MTLK_ASSERT(nic);
  mtlk_core_inc_cnt(nic, MTLK_CORE_CNT_MAN_FRAMES_RES_QUEUE);
}

void __MTLK_IFUNC
mtlk_core_on_bss_res_freed (mtlk_core_t *nic)
{
  MTLK_ASSERT(nic);
  mtlk_core_dec_cnt(nic, MTLK_CORE_CNT_MAN_FRAMES_RES_QUEUE);
}

int __MTLK_IFUNC
mtlk_wait_all_packets_confirmed(mtlk_core_t *nic)
{
#define SQ_WAIT_ALL_PACKETS_CFM_TIMEOUT_TOTAL  (2 * MSEC_PER_SEC)
#define SQ_WAIT_ALL_PACKETS_CFM_TIMEOUT_ONCE   10
  int wait_cnt = (SQ_WAIT_ALL_PACKETS_CFM_TIMEOUT_TOTAL / SQ_WAIT_ALL_PACKETS_CFM_TIMEOUT_ONCE);
  int res = MTLK_ERR_OK;
  uint32    dat_uncfm, bss_sent, bss_cfm, bss_uncfm, bss_res_queue;
  mtlk_hw_t *hw = mtlk_vap_get_hw(nic->vap_handle);

  for (;;) {
    dat_uncfm = mtlk_osal_atomic_get(&nic->unconfirmed_data);
    bss_sent  = _mtlk_core_get_cnt(nic, MTLK_CORE_CNT_MAN_FRAMES_SENT);     /* main ring */
    bss_cfm   = _mtlk_core_get_cnt(nic, MTLK_CORE_CNT_MAN_FRAMES_CONFIRMED);
    bss_uncfm = bss_sent - bss_cfm;

    ILOG4_DDDDDD("CID-%04x: wait_cnt %3d,  data:%d, bss:%d (sent:%d, confirmed:%d)",
                mtlk_vap_get_oid(nic->vap_handle),
                wait_cnt, dat_uncfm, bss_uncfm, bss_sent, bss_cfm);

    if (!(dat_uncfm | bss_uncfm)) break; /* all confirmed */

    if (wait_cnt == 0) {
      mtlk_hw_t *hw = mtlk_vap_get_hw(nic->vap_handle);

      ELOG_DDDDD("CID-%04x: Unconfirmed data:%d, bss:%d (sent:%d, confirmed:%d)",
                mtlk_vap_get_oid(nic->vap_handle),
                dat_uncfm, bss_uncfm, bss_sent, bss_cfm);

      if (dat_uncfm) mtlk_mmb_print_tx_dat_ring_info(hw);
      if (bss_uncfm) mtlk_mmb_print_tx_bss_ring_info(hw);

      res = MTLK_ERR_CANCELED;
      break;
    }

    mtlk_osal_msleep(SQ_WAIT_ALL_PACKETS_CFM_TIMEOUT_ONCE);
    wait_cnt--;
  }

  bss_res_queue = _mtlk_core_get_cnt(nic, MTLK_CORE_CNT_MAN_FRAMES_RES_QUEUE);  /* reserved queue */

  if (bss_res_queue)
    _mtlk_core_reset_cnt(nic, MTLK_CORE_CNT_MAN_FRAMES_RES_QUEUE);

  if (1 == mtlk_hw_get_number_of_active_vaps(hw)) {
    uint32 tx_res_used_bds = 0;
    (void)mtlk_hw_get_prop(mtlk_vap_get_hwapi(nic->vap_handle), MTLK_HW_BSS_MGMT_MSGS_RES_USED_PEAK, &tx_res_used_bds, sizeof(tx_res_used_bds));

    if (tx_res_used_bds > 0){
      mtlk_mmb_clean_tx_bss_res_queue_for_vap(mtlk_vap_get_hw(nic->vap_handle), wave_vap_radio_id_get(nic->vap_handle), MTLK_VAP_INVALID_IDX);
      WLOG_DD("CID-%04x: cleaned %d HDs in bss_res_queue",
           mtlk_vap_get_oid(nic->vap_handle), tx_res_used_bds);
    }
  }

  return res;
}

static int _mtlk_mbss_deactivate_vap(mtlk_core_t *running_core, mtlk_core_t *nic)
{
  int net_state = mtlk_core_get_net_state(nic);
  int res;
  bool skip_stop_traffic = FALSE;
  mtlk_hw_t *hw = mtlk_vap_get_hw(nic->vap_handle);
#ifdef MTLK_WAVE_700
  wave_rcvry_type_e rcvry_type = wave_rcvry_type_current_get(hw);
#endif

  ILOG2_DS("CID-%04x: net_state=%s", mtlk_vap_get_oid(nic->vap_handle), mtlk_net_state_to_string(net_state));

  finish_and_prevent_fw_set_chan(running_core, TRUE); /* remove_vap is a "process", so need this. Not sure about stop_vap_traffic */
  core_cfg_remove_all_sids_if_needed(nic);            /* in case interface goes down while hostapd is up or hostapd crashes */

  if (net_state == NET_STATE_HALTED) {
    goto CORE_HALTED;
  }

#if MTLK_USE_DIRECTCONNECT_DP_API
  if (mtlk_mmb_dcdp_path_available(hw)) {
    mtlk_dcdp_entries_disconnect(mtlk_vap_get_df(nic->vap_handle));
  }
#endif

  if (net_state == NET_STATE_CONNECTED) {
    if (nic->vap_in_fw_is_active) {
#ifdef MTLK_WAVE_700
      if (mtlk_hw_type_is_gen7(hw)) {
        if (MTLK_CORE_PDB_GET_INT(nic, PARAM_DB_CORE_MLD_ID) != 0xFF) {
          skip_stop_traffic = TRUE;
        }
      }
#endif
      if (!skip_stop_traffic) {
        res = mtlk_core_send_stop_vap_traffic(nic);
        if (res != MTLK_ERR_OK) {
          goto FINISH;
        }
      }
    } else {
      ILOG0_V("skip UM_MAN_STOP_VAP_TRAFFIC_REQ due vap is not active in fw");
      if ((res = mtlk_core_set_net_state(nic, NET_STATE_DEACTIVATING)) != MTLK_ERR_OK) {
        goto FINISH;
      }
    }
  }
  #ifdef MTLK_WAVE_700
  if (MTLK_CORE_PDB_GET_INT(nic, PARAM_DB_CORE_MLD_ID) != 0xFF) {
    wave_core_vap_remove_mld(nic);
  }
  #endif

  if (mtlk_wait_all_packets_confirmed(nic)) {
    WLOG_D("CID-%04x: wait time for all MSDUs confirmation expired", mtlk_vap_get_oid(nic->vap_handle));
    res = MTLK_ERR_FW;
    mtlk_hw_set_prop(mtlk_vap_get_hwapi(nic->vap_handle), MTLK_HW_RESET, NULL, 0);
    goto FINISH;
  }

CORE_HALTED:
  cleanup_on_disconnect(nic); /* Don't wait with this for complete removal */
#ifdef MTLK_WAVE_700
  if (RCVRY_TYPE_UNRECOVERABLE_ERROR == rcvry_type) {
    if (MTLK_CORE_PDB_GET_INT(nic, PARAM_DB_CORE_MLD_ID) != 0xFF) {
      wave_ml_vap_info_cleanup(nic->vap_handle);
    }
  }
#endif
  res = mtlk_core_send_vap_remove(nic);
  mtlk_vap_set_stopped(nic->vap_handle);

FINISH:
  finish_and_prevent_fw_set_chan(running_core, FALSE);

  if (1 >= mtlk_vap_manager_get_active_vaps_number(mtlk_vap_get_manager(nic->vap_handle))) {
    struct mtlk_chan_def *current_chandef = __wave_core_chandef_get(nic);
    current_chandef->center_freq1 = 0;
    current_chandef->power_level = MTLK_POWER_NOT_SET;
  }

  if (MTLK_ERR_OK != res) {
    ELOG_D("CID-%04x: Error during VAP deactivation", mtlk_vap_get_oid(nic->vap_handle));
    res = MTLK_ERR_FW;
/* FIXME Are we really supposed to halt the FW or just pretend we did?
    mtlk_core_set_net_state(nic, NET_STATE_HALTED);
*/
  }

  nic->vap_in_fw_is_active = FALSE;

  return res;
}

static int _mtlk_sta_status_query(mtlk_handle_t hcore, const void* payload, uint32 size)
{
  int res = MTLK_ERR_OK;
  mtlk_core_t *core = HANDLE_T_PTR(mtlk_core_t, hcore);
  uint8 *mac_addr = (uint8 *) payload;
  sta_entry *sta = NULL;
  int status;

  MTLK_ASSERT(ETH_ALEN == size);

  if (NET_STATE_HALTED == mtlk_core_get_net_state(core)) { /* Do nothing if halted */
    return MTLK_ERR_OK;
  }

  sta = mtlk_stadb_find_sta(&core->slow_ctx->stadb, mac_addr);

  if (NULL == sta) {
    ILOG1_Y("STA not found during status query: %Y", mac_addr);
    return MTLK_ERR_NO_ENTRY;
  }

  res = poll_client_req(core->vap_handle, sta, &status);
  mtlk_sta_decref(sta);

  if (MTLK_ERR_OK != res)
    ELOG_Y("Failed to poll STA %Y ", mac_addr);

  return res;
}

static void __MTLK_IFUNC
_mtlk_core_on_sta_keepalive (mtlk_handle_t usr_data, IEEE_ADDR addr)
{
  struct nic *nic = HANDLE_T_PTR(struct nic, usr_data);

  /* Skip scheduling because serializer is blocked during Recovery */
  if (!wave_in_fw_recovery(nic))
    _mtlk_process_hw_task(nic, SERIALIZABLE, _mtlk_sta_status_query, HANDLE_T(nic), &addr.au8Addr, ETH_ALEN);
}

static int
_mtlk_core_get_ap_capabilities (mtlk_handle_t hcore,
                                const void* data, uint32 data_size)
{
  mtlk_core_t *nic = HANDLE_T_PTR(mtlk_core_t, hcore);
  mtlk_card_capabilities_t card_capabilities;
  mtlk_clpb_t *clpb = *(mtlk_clpb_t **) data;
  wave_radio_t *radio;

  MTLK_ASSERT(mtlk_vap_is_master_ap(nic->vap_handle));
  MTLK_ASSERT(sizeof(mtlk_clpb_t*) == data_size);

  radio = wave_vap_radio_get(nic->vap_handle);

  MTLK_CFG_SET_ITEM(&card_capabilities, max_stas_supported, wave_radio_max_stas_get(radio));
  MTLK_CFG_SET_ITEM(&card_capabilities, max_vaps_supported, wave_radio_max_vaps_get(radio));

  return mtlk_clpb_push(clpb, &card_capabilities, sizeof(card_capabilities));
}

static int
_mtlk_core_cfg_init_mr_coex (mtlk_core_t *core)
{
  int res;
  mtlk_coex_data_t coex_cfg;

  if (MTLK_ERR_OK != mtlk_core_is_band_supported(core, UMI_PHY_TYPE_BAND_2_4_GHZ)) {
    ILOG1_D("CID-%04x: MR Coex only supported in 2.4 GHz", mtlk_vap_get_oid(core->vap_handle));
    return MTLK_ERR_OK;
  }

  res = mtlk_core_receive_coex_config(core, &coex_cfg);
  if (MTLK_ERR_OK == res) {
    wave_radio_t *radio = wave_vap_radio_get(core->vap_handle);
    WAVE_RADIO_PDB_SET_INT(radio, PARAM_DB_RADIO_COEX_MODE, coex_cfg.coex_mode);
    WAVE_RADIO_PDB_SET_INT(radio, PARAM_DB_RADIO_COEX_ACTIVE_TIME, coex_cfg.activeWifiWindowSize);
    WAVE_RADIO_PDB_SET_INT(radio, PARAM_DB_RADIO_COEX_INACTIVE_TIME, coex_cfg.inactiveWifiWindowSize);
    WAVE_RADIO_PDB_SET_INT(radio, PARAM_DB_RADIO_COEX_CTS2SELF_ACTIVE, coex_cfg.cts2self_active);
  }
  return res;
}

static mtlk_error_t
_mtlk_core_cfg_init_pw_lim_offset (mtlk_core_t *core)
{
  mtlk_error_t res;
  uint8 power_limit_offset;

  res = mtlk_core_receive_tx_power_limit_offset(core, &power_limit_offset);
  if (MTLK_ERR_OK == res) {
    wave_radio_t *radio = wave_vap_radio_get(core->vap_handle);
    WAVE_RADIO_PDB_SET_INT(radio, PARAM_DB_RADIO_TX_POWER_LIMIT_OFFSET, DBM_TO_POWER(power_limit_offset));
    WAVE_RADIO_PDB_SET_INT(radio, PARAM_DB_RADIO_TX_POWER_LIMIT_OFFSET_PREV, DBM_TO_POWER(power_limit_offset));
  }
  return res;
}

static int
_wave_core_cfg_init_rts_threshold (mtlk_core_t *core)
{
  int res;
  uint32 rts_threshold;

  res = _wave_core_cfg_get_rts_threshold(core, &rts_threshold);
  if (MTLK_ERR_OK == res)
    WAVE_RADIO_PDB_SET_INT(wave_vap_radio_get(core->vap_handle), PARAM_DB_RADIO_RTS_THRESH, rts_threshold);

  return res;
}

static mtlk_error_t
_wave_core_cfg_init_interference_det (mtlk_core_t *core)
{
  mtlk_error_t res;
  int8 threshold;

  res = wave_core_receive_interfdet_threshold(core, &threshold);
  if (MTLK_ERR_OK == res)
    WAVE_RADIO_PDB_SET_INT(wave_vap_radio_get(core->vap_handle), PARAM_DB_RADIO_INTERFDET_THRESHOLD, threshold);

  return res;
}

static mtlk_error_t
_wave_core_cfg_init_dynamic_wmm (mtlk_core_t *core)
{
  mtlk_error_t res;
  uint8 enabled;

  res = wave_core_receive_dynamic_wmm(core, &enabled);
  if (MTLK_ERR_OK == res)
    WAVE_RADIO_PDB_SET_INT(wave_vap_radio_get(core->vap_handle), PARAM_DB_RADIO_DYNAMIC_WMM, enabled);

  return res;
}

static mtlk_error_t
_wave_core_cfg_init_dynamic_edca (mtlk_core_t *core)
{
  mtlk_error_t res;
  uint8 enabled;

  res = wave_core_receive_dynamic_edca(core, &enabled);
  if (MTLK_ERR_OK == res)
    WAVE_RADIO_PDB_SET_INT(wave_vap_radio_get(core->vap_handle), PARAM_DB_RADIO_DYNAMIC_EDCA, enabled);

  return res;
}

int mtlk_core_init_defaults (mtlk_core_t *core)
{
  int res = MTLK_ERR_UNKNOWN;

  if (mtlk_vap_is_master(core->vap_handle)) {
    res = mtlk_core_cfg_init_cca_adapt(core);
    if (res != MTLK_ERR_OK) goto end;

    res = _mtlk_core_cfg_init_mr_coex(core);
    if (res != MTLK_ERR_OK) goto end;

    res = _mtlk_core_cfg_init_pw_lim_offset(core);
    if (res != MTLK_ERR_OK) goto end;

    res = _wave_core_cfg_init_rts_threshold(core);
    if (res != MTLK_ERR_OK) goto end;

    res = _wave_core_cfg_init_interference_det(core);
    if (res != MTLK_ERR_OK) goto end;

    res = _wave_core_cfg_init_dynamic_wmm(core);
    if (res != MTLK_ERR_OK) goto end;

    res = _wave_core_cfg_init_dynamic_edca(core);
    if (res != MTLK_ERR_OK) goto end;
  }

  res = mtlk_core_send_iwpriv_config_to_fw(core);

end:
  return res;
}

static void
_mtlk_core_reset_pstat_traffic_cntrs(mtlk_core_t *core)
{
    core->pstats.tx_bytes   = 0;
    core->pstats.rx_bytes   = 0;
    core->pstats.tx_packets = 0;
    core->pstats.rx_packets = 0;
    core->pstats.rx_multicast_packets = 0;
}

static void
_mtlk_core_poll_stat_stop(mtlk_core_t *core)
{
    mtlk_wss_poll_stat_stop(&core->poll_stat);
}

static void
_mtlk_core_poll_stat_init(mtlk_core_t *core)
{
    memset(&core->poll_stat_last, 0, sizeof(core->poll_stat_last));
    mtlk_wss_poll_stat_init(&core->poll_stat, MTLK_CORE_CNT_POLL_STAT_NUM,
                             &core->wss_hcntrs[MTLK_CORE_CNT_POLL_STAT_FIRST],
                             &core->poll_stat_last[0]);
}

static void
_mtlk_core_poll_stat_start(mtlk_core_t *core)
{
    _mtlk_core_reset_pstat_traffic_cntrs(core);
    mtlk_wss_poll_stat_start(&core->poll_stat);
}

static BOOL
_mtlk_core_poll_stat_is_started(mtlk_core_t *core)
{
    return mtlk_wss_poll_stat_is_started(&core->poll_stat);
}

static void
_mtlk_core_poll_stat_update (mtlk_core_t *core, uint32 *values, uint32 values_num)
{
    mtlk_poll_stat_update_cntrs(&core->poll_stat, values, values_num);
}

static int
_mtlk_core_activate (mtlk_handle_t hcore, const void* data, uint32 data_size)
{
  mtlk_core_t *nic = HANDLE_T_PTR(mtlk_core_t, hcore);
  mtlk_clpb_t *clpb = *(mtlk_clpb_t **) data;
  wave_radio_t *radio = wave_vap_radio_get(nic->vap_handle);
  int res;
  sta_db_cfg_t sta_db_cfg;
  u8 band = UMI_PHY_TYPE_BAND_2_4_GHZ;

  /* Tri band support */
  if (WAVE_RADIO_PDB_GET_INT(radio, PARAM_DB_RADIO_FREQ_BAND_CFG) == MTLK_HW_BAND_5_2_GHZ) {
     band = UMI_PHY_TYPE_BAND_5_2_GHZ;
  } else if (WAVE_RADIO_PDB_GET_INT(radio, PARAM_DB_RADIO_FREQ_BAND_CFG) == MTLK_HW_BAND_6_GHZ) {
     band = UMI_PHY_TYPE_BAND_6_GHZ;
  } else if (WAVE_RADIO_PDB_GET_INT(radio, PARAM_DB_RADIO_FREQ_BAND_CFG) != MTLK_HW_BAND_2_4_GHZ) {
     ELOG_D("CID-%04x: band not set - assuming 2.4GHZ", mtlk_vap_get_oid(nic->vap_handle));
  }

  {
    /* We used to check that the VAP is not up here but now it might be due to scan or
     * initial channels switch. Yet it may not have the BSS, so we need to keep working on it */
    ILOG0_D("CID-%04x: open interface", mtlk_vap_get_oid(nic->vap_handle));
    if (MTLK_ERR_OK != mtlk_eeprom_is_valid(mtlk_core_get_eeprom(nic))) {
      WLOG_D("CID-%04x: Interface cannot UP after EEPROM failure", mtlk_vap_get_oid(nic->vap_handle));
      res = MTLK_ERR_NOT_READY;
      goto FINISH;
    }
    if (mtlk_vap_is_dut(nic->vap_handle)) {
      WLOG_D("CID-%04x: Interface cannot UP in DUT mode", mtlk_vap_get_oid(nic->vap_handle));
      res = MTLK_ERR_NOT_SUPPORTED;
      goto FINISH;
    }
    if (!(mtlk_core_get_net_state(nic) & (NET_STATE_READY | NET_STATE_ACTIVATING | NET_STATE_CONNECTED))
        || mtlk_core_is_stopping(nic)) {
      ELOG_D("CID-%04x: Failed to open - inappropriate state", mtlk_vap_get_oid(nic->vap_handle));
      res = MTLK_ERR_NOT_READY;
      goto FINISH;
    }

    _mtlk_core_poll_stat_start(nic);
    res = mtlk_mbss_send_vap_activate(nic, band);

    if (!mtlk_vap_is_sta(nic->vap_handle)) {
      if (BR_MODE_WDS == MTLK_CORE_HOT_PATH_PDB_GET_INT(nic, CORE_DB_CORE_BRIDGE_MODE)){
        wds_on_if_up(&nic->slow_ctx->wds_mng);
      }
    }
    if (MTLK_ERR_OK != res) {
      ELOG_D("CID-%04x: Failed to activate the core", mtlk_vap_get_oid(nic->vap_handle));
      goto FINISH;
    }
    if (mtlk_vap_is_master_ap(nic->vap_handle) &&
        !mtlk_vap_manager_did_ap_started(mtlk_vap_get_manager(nic->vap_handle))) {
      /* if hostapd crashes during recovery, or is disabled by wpa_supplicant duo to disconnection
       * from the far AP (because of recovery), it might not send us the sync_done vendor event,
       * and we will forever remain in "sync not done" state, and cause bss_changed() to fail.
       * if this is master vap and no other AP is active, assume that hostapd is comming up. */
      wave_core_sync_hostapd_done_set(nic, TRUE);
    }
    /* CoC configuration */
    if (1 >= mtlk_vap_manager_get_active_vaps_number(mtlk_vap_get_manager(nic->vap_handle))) {
      mtlk_coc_t *coc_mgmt = __wave_core_coc_mgmt_get(nic);
      mtlk_coc_reset_antenna_params(coc_mgmt);
      mtlk_coc_dump_antenna_params(coc_mgmt);
      res = mtlk_coc_set_power_mode(coc_mgmt, mtlk_coc_get_auto_mode_cfg(coc_mgmt));
      if (MTLK_ERR_OK != res) {
        ELOG_D("CID-%04x: Unable to set Power Mode, Failed to activate the core",
              mtlk_vap_get_oid(nic->vap_handle));
        goto FINISH;
      }
    }
    /* interface is up - start timers */
    sta_db_cfg.api.usr_data          = HANDLE_T(nic);
    sta_db_cfg.api.on_sta_keepalive  = _mtlk_core_on_sta_keepalive;
    sta_db_cfg.max_nof_stas = wave_radio_max_stas_get(radio);
    sta_db_cfg.parent_wss   = nic->wss;
    mtlk_stadb_configure(&nic->slow_ctx->stadb, &sta_db_cfg);
    mtlk_stadb_start(&nic->slow_ctx->stadb);
  }
FINISH:
  return mtlk_clpb_push_res(clpb, res);
}

static int
__mtlk_core_deactivate(mtlk_core_t *running_core, mtlk_core_t *nic)
{
  mtlk_hw_t *hw;
  BOOL is_scan_rcvry;
  wave_rcvry_type_e rcvry_type;
  mtlk_scan_support_t *ss;
  int net_state = mtlk_core_get_net_state(nic);
  mtlk_vap_manager_t *vap_manager = mtlk_vap_get_manager(nic->vap_handle);
  int res = MTLK_ERR_OK;
  int deactivate_res  = MTLK_ERR_OK;
  UMI_SET_BSS set_bss = { 0 };
  mtlk_pdb_size_t set_bss_size = sizeof(UMI_SET_BSS);
  wave_radio_t *radio       = wave_vap_radio_get(nic->vap_handle);
  struct wireless_dev *wdev = mtlk_core_get_wdev(nic->vap_handle);
  BOOL is_rcvry = wave_in_fw_recovery(running_core);

  ILOG1_SDDDS("%s: Deactivating: is_stopped=%u, is_iface_stopping=%u, is_slave_ap=%u, net_state=%s",
              mtlk_df_get_name(mtlk_vap_get_df(nic->vap_handle)), nic->is_stopped, nic->is_iface_stopping,
              mtlk_vap_is_slave_ap(nic->vap_handle), mtlk_net_state_to_string(net_state));

#ifdef MTLK_WAVE_700
  MTLK_CORE_PDB_SET_INT(nic, PARAM_DB_CORE_SKIP_SET_BEACON, 0);
#endif
  if (nic->is_stopped) {
    /* Interface has already been stopped */
    res = MTLK_ERR_OK;
    goto FINISH;
  }

  MTLK_ASSERT(0 != mtlk_vap_manager_get_active_vaps_number(mtlk_vap_get_manager(nic->vap_handle)));

  hw = mtlk_vap_get_hw(nic->vap_handle);
  rcvry_type = wave_rcvry_type_current_get(hw);
  is_scan_rcvry = (RCVRY_NO_SCAN != wave_rcvry_scan_type_current_get(hw, vap_manager));

  nic->is_iface_stopping = TRUE;

  _mtlk_core_poll_stat_stop(nic);

  if (MTLK_ERR_OK != MTLK_CORE_PDB_SET_BINARY(nic, PARAM_DB_CORE_SET_BSS, &set_bss, set_bss_size)) {
    ELOG_V("Failed to reset SET_BSS data");
  }

  ss = __wave_core_scan_support_get(running_core);

  if (mtlk_vap_is_master(nic->vap_handle)) {
    struct mtlk_chan_def *ccd = __wave_core_chandef_get(nic);

    ccd->sb_dfs.sb_dfs_bw = MTLK_SB_DFS_BW_NORMAL;

    if (ss->dfs_debug_params.debug_chan)
      ss->dfs_debug_params.switch_in_progress = FALSE;

    if (is_scan_rcvry) {
      pause_or_prevent_scan(nic);
      if (ss->set_chan_man_msg.data) {
        mtlk_txmm_msg_cleanup(&ss->set_chan_man_msg);
        ss->set_chan_man_msg.data = NULL;
      }
    }
  }

  if (!is_scan_rcvry) {
    mtlk_df_user_t *df_user   = mtlk_df_get_user(mtlk_vap_get_df(nic->vap_handle));

    if(ss->req.saved_request != NULL && ((struct cfg80211_scan_request *)ss->req.saved_request)->wdev == mtlk_df_user_get_wdev(df_user))
      abort_scan_sync(mtlk_core_get_master(running_core->vap_handle)); /* this can be done many times, so no other checks */
  }

  /* Force disconnect of all WDS peers */
  if (!mtlk_vap_is_sta(nic->vap_handle) &&
      BR_MODE_WDS == MTLK_CORE_HOT_PATH_PDB_GET_INT(nic, CORE_DB_CORE_BRIDGE_MODE)){
    wds_on_if_down(&nic->slow_ctx->wds_mng);
  }

  if (!_can_disconnect_now(nic)) {
     res = MTLK_ERR_RETRY;
     nic->is_iface_stopping = FALSE;
     goto FINISH;
  }

  if (nic->color_change_active)
    wave_core_send_abort_cca(nic);

  /* for all of these states we can at least remove the VAP. For connected will also do stop_vap_traffic before that */
  if ((net_state & (NET_STATE_CONNECTED | NET_STATE_ACTIVATING | NET_STATE_DEACTIVATING))
      || (net_state == NET_STATE_HALTED)) /* for cleanup after exception */
  {
    deactivate_res = _mtlk_mbss_deactivate_vap(running_core, nic); /* this will set the net_state */

    /* For Fast and Full Recovery we will need to restore WEP or GTK keys.
       For Complete Recovery - hostapd will restore all keys */
    if ((RCVRY_TYPE_FAST != rcvry_type) && (RCVRY_TYPE_FULL != rcvry_type)) {
      ILOG1_D("CID-%04x: Reset security", mtlk_vap_get_oid(nic->vap_handle));
      reset_security_stuff(nic);
    } else {
      ILOG1_D("CID-%04x: Skip reset security", mtlk_vap_get_oid(nic->vap_handle));
    }
  }

  MTLK_ASSERT(0 == mtlk_stadb_get_four_addr_sta_cnt(&nic->slow_ctx->stadb));

  mtlk_stadb_stop(&nic->slow_ctx->stadb);

  mtlk_qos_dscp_table_init(nic->dscp_table);

  net_state = mtlk_core_get_net_state(nic); /* see what the new net_state is */

  nic->is_iface_stopping = FALSE;
  /* FIXME is_stopped should always be deduced from the net_state flags, a separate field is a nuisance */
  nic->is_stopped = !(net_state & (NET_STATE_CONNECTED | NET_STATE_ACTIVATING | NET_STATE_DEACTIVATING));
  if (nic->is_stopped) {
    mtlk_vap_manager_notify_vap_deactivated(vap_manager);
    ILOG1_D("CID-%04x: interface is stopped", mtlk_vap_get_oid(nic->vap_handle));
  }
  ILOG1_SDDDS("%s: Deactivated: is_stopped=%u, is_stopping=%u, is_iface_stopping=%u, net_state=%s",
              mtlk_df_get_name(mtlk_vap_get_df(nic->vap_handle)),
              nic->is_stopped, nic->is_stopping, nic->is_iface_stopping,
              mtlk_net_state_to_string(mtlk_core_get_net_state(nic)));

  if ((0 == mtlk_vap_manager_get_active_vaps_number(vap_manager))) {
    mtlk_coc_t *coc_mgmt = __wave_core_coc_mgmt_get(nic);
    mtlk_coc_auto_mode_disable(coc_mgmt);
    if (wave_hw_mmb_get_pcie_auto_gen_transition(hw))
      wave_core_configure_pcie_speed(nic, PCIE_SPEED_GEN1);
  }

  if (mtlk_vap_is_master (nic->vap_handle)) { // re-enable in case we disabled during channel switch
    wave_radio_abilities_enable_vap_ops(nic->vap_handle);
    /* Abort background_cac for WAV700 ZWDFS as radio config change of 5G band affects zwdfs */
    if (mtlk_hw_type_is_gen7(hw) && is_rcvry && wave_radio_get_zwdfs_ant_enabled(radio)) {
      cfg80211_background_cac_abort(wdev->wiphy);
      wave_radio_set_zwdfs_ant_enabled(radio, FALSE);
    }
  }

  if (0 == mtlk_vap_manager_get_active_vaps_number(vap_manager)) {
    __wave_core_chan_switch_type_set(nic, ST_NONE);
    if (!is_rcvry)
      wave_radio_reset_chan_statistics(hw, 0, wave_radio_id_get(wave_vap_radio_get(running_core->vap_handle)), TRUE);
  }

FINISH:
  /*
    If deactivate_res indicates an error - we must make sure
    that the close function will not reiterate. Therefore, we return
    specific error code in this case.
  */
  if (MTLK_ERR_OK != deactivate_res)
    res = deactivate_res;
  return res;
}

int core_recovery_deactivate(mtlk_core_t *master_core, mtlk_core_t *nic)
{
  return __mtlk_core_deactivate(master_core, nic);
}

static int
_mtlk_core_deactivate (mtlk_handle_t hcore, const void* data, uint32 data_size)
{
  int res = MTLK_ERR_OK;
  mtlk_core_t *core = HANDLE_T_PTR(mtlk_core_t, hcore);
  mtlk_clpb_t *clpb = *(mtlk_clpb_t **) data;

  MTLK_ASSERT(core != NULL);
  MTLK_ASSERT(sizeof(mtlk_clpb_t*) == data_size);

  if (wave_in_fw_recovery(core) && wave_rcvry_is_enabled(core))
    ELOG_V("Recovery is running, but core deactivation must be done");

  res = __mtlk_core_deactivate(core, core);

  return mtlk_clpb_push(clpb, &res, sizeof(res));
}

static mtlk_error_t
_mtlk_beacon_man_set_beacon_interval (mtlk_handle_t hcore, const void* data, uint32 data_size)
{
  mtlk_core_t *core = HANDLE_T_PTR(mtlk_core_t, hcore);
  mtlk_clpb_t *clpb = *(mtlk_clpb_t **) data;
  mtlk_beacon_interval_t *mtlk_beacon_interval;
  mtlk_error_t res = MTLK_ERR_UNKNOWN;

  MTLK_ASSERT(sizeof(mtlk_clpb_t*) == data_size);
  mtlk_beacon_interval = mtlk_clpb_enum_get_next(clpb, NULL);
  MTLK_ASSERT(NULL != mtlk_beacon_interval);

  if (mtlk_beacon_interval) {
    res = mtlk_beacon_man_set_beacon_interval_by_params(core, mtlk_beacon_interval);
  }

  return mtlk_clpb_push_res(clpb, res);
}

static int
_mtlk_core_mgmt_tx (mtlk_handle_t hcore, const void* data, uint32 data_size)
{
  mtlk_error_t res = MTLK_ERR_OK;
  mtlk_core_t *core = HANDLE_T_PTR(mtlk_core_t, hcore);
  mtlk_clpb_t *clpb = *(mtlk_clpb_t **) data;
  struct mgmt_tx_params *mtp;
  uint32 mtp_size;
  sta_entry *sta = NULL;
  const unsigned char *dst_addr;
  unsigned frame_ctrl, subtype;
  size_t frame_min_len = sizeof(frame_head_t);
#ifdef MTLK_WAVE_700
  struct ieee80211_sta * mac80211_sta;
  struct ieee80211_vif *vif;
  mtlk_pdb_t *param_db_core = mtlk_vap_get_param_db(core->vap_handle);
#endif

  MTLK_ASSERT(sizeof(mtlk_clpb_t*) == data_size);
  mtp = mtlk_clpb_enum_get_next(clpb, &mtp_size);
  MTLK_CLPB_TRY(mtp, mtp_size)
  {
    if (PROCESS_EAPOL == mtp->extra_processing)
      frame_min_len = sizeof(struct ethhdr);

    if (mtp->len < frame_min_len) {
      ELOG_DDD("CID-%04x: Management Frame length %u is less than min %u",
        mtlk_vap_get_oid(core->vap_handle), mtp->len, frame_min_len);
      MTLK_CLPB_EXIT(MTLK_ERR_NOT_IN_USE);
    }

    dst_addr   = WLAN_GET_ADDR1(mtp->buf);
    frame_ctrl = mtlk_wlan_pkt_get_frame_ctl((uint8 *)mtp->buf);
    subtype    = (frame_ctrl & FRAME_SUBTYPE_MASK) >> FRAME_SUBTYPE_SHIFT;

    /* For master AP process only PROBE REQ for the scan */
    if (mtlk_vap_is_master_ap(core->vap_handle)) {
      if ((PROCESS_MANAGEMENT != mtp->extra_processing) || (MAN_TYPE_PROBE_REQ != subtype)) {
        MTLK_CLPB_EXIT(MTLK_ERR_NOT_HANDLED);
      }
    }

    if (PROCESS_EAPOL == mtp->extra_processing) {
        struct ethhdr *ether_header = (struct ethhdr *) mtp->buf;
      sta = mtlk_stadb_find_sta(&core->slow_ctx->stadb, ether_header->h_dest);
      if (!sta) {
        MTLK_CLPB_EXIT(MTLK_ERR_NOT_HANDLED);
      }
      if (MTLK_PCKT_FLTR_DISCARD_ALL == mtlk_sta_get_packets_filter(sta)) {
        mtlk_sta_on_packet_dropped(sta,  MTLK_TX_DISCARDED_DROP_ALL_FILTER);
        MTLK_CLPB_EXIT(MTLK_ERR_NOT_HANDLED);
      }
#ifdef MTLK_WAVE_700
      if (mtlk_hw_type_is_gen7(mtlk_vap_get_hw(core->vap_handle))) {
        mac80211_sta = wv_sta_entry_get_mac80211_sta(sta);
        vif = wave_vap_get_vif(core->vap_handle);
        if (mac80211_sta->ml_sta_info.is_ml) {
          wave_memcpy(ether_header->h_dest, IEEE_ADDR_LEN, mac80211_sta->ml_sta_info.mld_mac, IEEE_ADDR_LEN);

          if (MTLK_CORE_PDB_GET_INT(core, PARAM_DB_CORE_MLD_ID) != 0xFF) {
            wave_pdb_get_mac(param_db_core, PARAM_DB_CORE_AP_MLD_MAC, &ether_header->h_source);
          }
        }
      }
#endif
      if (mtlk_vap_is_sta(core->vap_handle)) {
        /* since we are sending the last eapol (4of4) frame in station mode, we must wait for eapol ack,
         * to not cause a race condition with FW sending the Frame over air, and the driver sending SET_KEY commands
         * which will cause the frame to be encrypted and lead to 4way handshake timeout (-15) */
        mtlk_osal_event_reset(&core->eapol_acked);
        core->waiting_for_eapol_ack = TRUE;
      }
    } else if (PROCESS_NULL_DATA_PACKET == mtp->extra_processing) {
      uint16 sid = mtlk_core_get_sid_by_addr(core, (char *)dst_addr);
      if (DB_UNKNOWN_SID == sid) {
        ELOG_Y("Unknown SID when sending null data packet, STA address %Y", dst_addr);
        MTLK_CLPB_EXIT(MTLK_ERR_NOT_HANDLED);
      }
    } else if (PROCESS_MANAGEMENT == mtp->extra_processing) {
      ILOG2_DDY("CID-%04x: mgmt subtype %d, peer %Y", mtlk_vap_get_oid(core->vap_handle), subtype, dst_addr);
      if (MAN_TYPE_PROBE_RES == subtype) { /* Filtering the Probe Responses */
        if (_mtlk_core_ucast_probe_resp_entry_exists(core, (IEEE_ADDR *)dst_addr)) {
          ILOG2_DY("CID-%04x: Don't send Probe Response to %Y", mtlk_vap_get_oid(core->vap_handle), dst_addr);
          if (mtp->skb)
            wv_ieee80211_free_txskb(core->vap_handle, mtp->skb);
          MTLK_CLPB_EXIT(MTLK_ERR_OK);
        } else {
          /*
           * We are in serializer context. It is important to add entry to the list
           * prior to frame transmission is executed, as CFM may come nearly immediately
           * after HD is copied to the ring. The entry is removed from list in the
           * tasklet context, that might create a racing on entry removal.
           */
          _mtlk_core_add_ucast_probe_resp_entry(core, (IEEE_ADDR *)dst_addr);
        }
      }
    }

    res = mtlk_mmb_bss_mgmt_tx(core->vap_handle, mtp->buf, mtp->len, mtp->channum,
                                 mtp->no_cck, mtp->dont_wait_for_ack, FALSE, /* unicast */
                               mtp->cookie, mtp->extra_processing, mtp->skb,
                               FALSE, NTS_TID_USE_DEFAULT);

    if (res != MTLK_ERR_OK) {
      /* delete entry if TX failed */
      if ((PROCESS_MANAGEMENT == mtp->extra_processing) && (MAN_TYPE_PROBE_RES == subtype)) {
        _mtlk_core_del_ucast_probe_resp_entry(core, (IEEE_ADDR *)dst_addr);
      }
      ILOG1_DSDDS("CID-%04x: Send %s frame error: type=%d, res=%d (%s)",
               mtlk_vap_get_oid(core->vap_handle),
               (mtp->extra_processing == PROCESS_MANAGEMENT) ? "management" : (mtp->extra_processing == PROCESS_EAPOL) ? "EAPOL" : (mtp->extra_processing == PROCESS_NULL_DATA_PACKET) ? "null data" : "unknown",
               mtp->extra_processing, res, mtlk_get_error_text(res));
      if (sta)
        if (PROCESS_EAPOL == mtp->extra_processing) {
          mtlk_sta_on_tx_packet_discarded_802_1x(sta);  /* Count 802_1x discarded TX packets */
          core->waiting_for_eapol_ack = FALSE;
        }
    } else {
      if (sta && (PROCESS_EAPOL == mtp->extra_processing))
          mtlk_sta_on_tx_packet_802_1x(sta); /* Count 802_1x TX packets */
    }
  }
  MTLK_CLPB_FINALLY(res) {
    if (sta) mtlk_sta_decref(sta);
    if (res != MTLK_ERR_OK && res != MTLK_ERR_CLPB_DATA) {
      if (mtp->skb)
        wv_ieee80211_free_txskb(core->vap_handle, mtp->skb);
    }

    return mtlk_clpb_push_res(clpb, res);
  }
  MTLK_CLPB_END;
}

static mtlk_error_t
_mtlk_core_mgmt_rx (mtlk_handle_t hcore, const void* data, uint32 data_size)
{
  mtlk_error_t res = MTLK_ERR_OK;
  mtlk_core_t *core = HANDLE_T_PTR(mtlk_core_t, hcore);
  mtlk_clpb_t *clpb = *(mtlk_clpb_t **) data;
  mtlk_core_handle_rx_bss_t *rx_bss;
  uint32 rx_bss_size;

  MTLK_ASSERT(sizeof(mtlk_clpb_t*) == data_size);

  rx_bss = mtlk_clpb_enum_get_next(clpb, &rx_bss_size);
  MTLK_CLPB_TRY(rx_bss, rx_bss_size)
    res = _mtlk_core_handle_rx_bss(core->vap_handle, rx_bss);
  MTLK_CLPB_FINALLY(res)
    return mtlk_clpb_push_res(clpb, res);
  MTLK_CLPB_END;
}

int mtlk_handle_eapol(mtlk_vap_handle_t vap_handle, void *data, int data_len)
{
  struct ethhdr *ether_header = (struct ethhdr *)data;
  mtlk_core_t *nic            = mtlk_vap_get_core(vap_handle);
  wave_radio_t *radio         = wave_vap_radio_get(vap_handle);
  sta_entry *sta              = NULL;
  nl80211_band_e band         = mtlkband2nlband(wave_radio_band_get(radio));
  const IEEE_ADDR               *addr;

  CAPWAP1(mtlk_hw_mmb_get_card_idx(mtlk_vap_get_hw(vap_handle)), data, data_len, 0, 0);

  sta = mtlk_stadb_find_sta(&nic->slow_ctx->stadb, ether_header->h_source);
  if (sta) {
    struct ieee80211_sta * mac80211_sta;
    struct ieee80211_vif *vif = wave_vap_get_vif(nic->vap_handle);
    /* Replace the non-ap mld addr with link addr */
    addr = mtlk_sta_get_addr(sta);
    wave_memcpy(ether_header->h_source, sizeof(ether_header->h_source), addr, IEEE_ADDR_LEN);
    mac80211_sta = wv_sta_entry_get_mac80211_sta(sta);
    if (mac80211_sta->ml_sta_info.is_ml && vif != NULL)
      wave_memcpy(ether_header->h_dest, sizeof(ether_header->h_dest), vif->addr, IEEE_ADDR_LEN);
    /* If WDS WPS station sent EAPOL not to us, discard. */
    if (MTLK_BFIELD_GET(sta->info.flags, STA_FLAGS_WDS_WPA)) {
      if (MTLK_CORE_HOT_PATH_PDB_CMP_MAC(nic, CORE_DB_CORE_MAC_ADDR, ether_header->h_dest)) {
        mtlk_sta_decref(sta);               /* De-reference of find */
        return MTLK_ERR_OK;
      }
    }
    mtlk_sta_on_rx_packet_802_1x(sta);  /* Count 802_1x RX packets */
    mtlk_sta_decref(sta);               /* De-reference of find */
  }

  return wv_ieee80211_eapol_rx(wave_radio_mac80211_get(radio),
                               wave_vap_get_vif(nic->vap_handle),
                               data, data_len, band);
}

static int
_mtlk_core_set_mac_addr_wrapper (mtlk_handle_t hcore,
                                 const void* data, uint32 data_size)
{
  mtlk_core_t *nic = HANDLE_T_PTR(mtlk_core_t, hcore);
  mtlk_clpb_t *clpb = *(mtlk_clpb_t **) data;
  const char* mac_addr;

  MTLK_ASSERT(sizeof(mtlk_clpb_t*) == data_size);
  mac_addr = mtlk_clpb_enum_get_next(clpb, NULL);
  MTLK_ASSERT(NULL != mac_addr);
  if (!mac_addr) return MTLK_ERR_UNKNOWN;

  return core_cfg_set_mac_addr(nic, mac_addr);
}

static int
_mtlk_core_get_mac_addr (mtlk_handle_t hcore,
                         const void* data, uint32 data_size)
{
  mtlk_core_t *core = HANDLE_T_PTR(mtlk_core_t, hcore);
  mtlk_clpb_t *clpb = *(mtlk_clpb_t **) data;
  IEEE_ADDR mac_addr;

  MTLK_ASSERT(sizeof(mtlk_clpb_t*) == data_size);

  MTLK_CORE_PDB_GET_MAC(core, PARAM_DB_CORE_MAC_ADDR, &mac_addr);
  return mtlk_clpb_push(clpb, &mac_addr, sizeof(mac_addr));
}

int mtlk_get_dbg_channel_availability_check_time(mtlk_scan_support_t* obj)
{
  mtlk_df_t *df;
  mtlk_df_user_t *df_user;
  struct wireless_dev *wdev;
  struct wiphy *wiphy;
  MTLK_ASSERT(NULL != obj);
  df = mtlk_vap_get_df(obj->master_core->vap_handle);
  df_user = mtlk_df_get_user(df);
  wdev = mtlk_df_user_get_wdev(df_user);
  wiphy = wdev->wiphy;
  if (wiphy->cac_time_debug == -1)
    return -1;
  return (wiphy->cac_time_debug/MTLK_OSAL_MSEC_IN_SEC);
}

static int
_mtlk_core_get_hw_limits (mtlk_handle_t hcore, const void *data, uint32 data_size)
{
  mtlk_core_t *nic = HANDLE_T_PTR(mtlk_core_t, hcore);
  mtlk_clpb_t *clpb = *(mtlk_clpb_t **) data;
  MTLK_ASSERT(sizeof(mtlk_clpb_t*) == data_size);

  return mtlk_psdb_get_hw_limits_list(nic, clpb);
}

/* Fixed Rate configuration */
struct mtlk_param_limits {
      uint32 min_limit;
      uint32 max_limit;
};

static BOOL
_mtlk_core_params_limits_valid (mtlk_core_t *core, const uint32 *params, struct mtlk_param_limits *limits, int size)
{
    uint32  value, v_min, v_max;
    int     i;

    for (i = 0; i < size; i++) {
      value = params[i];
      v_min = limits[i].min_limit;
      v_max = limits[i].max_limit;
      if (!((v_min <= value) && (value <= v_max))) {
          ELOG_DDDD("params[%d] = %u is not fit to range [%u ... %u]", i, value, v_min, v_max);
          return FALSE;
      }
    }
#ifdef MTLK_WAVE_700
  {
   /* IEEE P802.11be/D1.31, December 2021 Sec 36.1.1 and Sec 36.5 */
   /* MCS14: Only for 6GHz 80/160/320 MHz BW and NSS=1. Not allowed in other cases. *
    * MCS15: only NSS = 1 is allowed                                                */
    wave_radio_t *radio = wave_vap_radio_get(core->vap_handle);
    if (wave_radio_is_gen7(radio)) {
      if ((params[MTLK_FIXED_RATE_CFG_PHYM] >= PHY_MODE_AX) &&
           (params[MTLK_FIXED_RATE_CFG_PHYM] <=PHY_MODE_11AX_MU_DL)) {
        if ((params[MTLK_FIXED_RATE_CFG_BW] > CW_160) ||
            (params[MTLK_FIXED_RATE_CFG_DCM] > 1))
          return FALSE;
      } else if (params[MTLK_FIXED_RATE_CFG_PHYM] > PHY_MODE_11AX_MU_DL) {
          switch(params[MTLK_FIXED_RATE_CFG_MCS]) {
            case 14:
              /* if ((wave_radio_band_get(radio) != MTLK_HW_BAND_6_GHZ) ||
                  (params[MTLK_FIXED_RATE_CFG_NSS] > 1) ||
                  (params[MTLK_FIXED_RATE_CFG_BW] < CW_80)) */
                //TODO: Case14/MCS14 - The above if condition must be enabled, only when MCS14 support is provided.
                return FALSE;
              break;

            case 15:
              if ((params[MTLK_FIXED_RATE_CFG_NSS] > 1) ||
                  (params[MTLK_FIXED_RATE_CFG_DCM] != 1))
                return FALSE;
              break;

            default: break;
          }
      }
    }
  }
#endif
    return TRUE;
}

static mtlk_error_t
_mtlk_core_check_fixed_rate (mtlk_core_t *core, const mtlk_fixed_rate_cfg_t *fixed_rate_cfg)
{
    struct mtlk_param_limits limits[MTLK_FIXED_RATE_CFG_SIZE] = {
      [MTLK_FIXED_RATE_CFG_SID]  = {            0,  ALL_SID_MAX }, /* stationIndex */
      [MTLK_FIXED_RATE_CFG_AUTO] = {            0,            1 }, /* isAutoRate   */
      [MTLK_FIXED_RATE_CFG_BW]   = {        CW_20,       CW_160 }, /* bw           */
      [MTLK_FIXED_RATE_CFG_PHYM] = {            0,            7 }, /* phyMode      */
      [MTLK_FIXED_RATE_CFG_NSS]  = {            0,            4 }, /* nss          */
      [MTLK_FIXED_RATE_CFG_MCS]  = {            0,           32 }, /* mcs          */
      [MTLK_FIXED_RATE_CFG_SCP]  = {            0,            5 }, /* scp/cpMode   */
      [MTLK_FIXED_RATE_CFG_DCM]  = {            0,            1 }, /* dcm   */
      [MTLK_FIXED_RATE_CFG_HE_EXTPARTIALBWDATA] = {            0,            1 }, /* heExtPartialBwData   */
      [MTLK_FIXED_RATE_CFG_HE_EXTPARTIALBWMNG]  = {            0,            1 }, /* heExtPartialBwMng   */
      [MTLK_FIXED_RATE_CFG_CHANGETYPE]          = {            1,            3 }, /* changeType   */
    };

#ifdef MTLK_WAVE_700
    wave_radio_t *radio = wave_vap_radio_get(core->vap_handle);
    if (wave_radio_is_gen7(radio)) {
      limits[MTLK_FIXED_RATE_CFG_SID].max_limit = ALL_SID_MAX_G7;
      limits[MTLK_FIXED_RATE_CFG_PHYM].max_limit = PHY_MODE_MAX_G7;
    }
    if (wave_radio_is_320mhz_supported(radio))
      limits[MTLK_FIXED_RATE_CFG_BW].max_limit = CW_320;
#endif
    if (/* All params are within limits */
        _mtlk_core_params_limits_valid(core, &fixed_rate_cfg->params[0], &limits[0], MTLK_FIXED_RATE_CFG_SIZE) &&
        /* StationID: valid OR for all */
        mtlk_hw_is_sid_valid_or_all_sta_sid(mtlk_vap_get_hw(core->vap_handle),
                                            fixed_rate_cfg->params[MTLK_FIXED_RATE_CFG_SID]) &&
        /* AutoRate OR correct bitrate params */
        ((0 != fixed_rate_cfg->params[MTLK_FIXED_RATE_CFG_AUTO]) ||
          mtlk_bitrate_hw_params_supported(
            fixed_rate_cfg->params[MTLK_FIXED_RATE_CFG_PHYM],
            fixed_rate_cfg->params[MTLK_FIXED_RATE_CFG_BW],
            fixed_rate_cfg->params[MTLK_FIXED_RATE_CFG_SCP],
            fixed_rate_cfg->params[MTLK_FIXED_RATE_CFG_MCS],
            fixed_rate_cfg->params[MTLK_FIXED_RATE_CFG_NSS]))
        ) {
        return MTLK_ERR_OK;
    }

    return MTLK_ERR_PARAMS;
}

static mtlk_error_t
_mtlk_core_check_and_send_fixed_rate (mtlk_core_t *core, const mtlk_fixed_rate_cfg_t *fixed_rate_cfg)
{
    mtlk_error_t res = _mtlk_core_check_fixed_rate(core, fixed_rate_cfg);
    if (MTLK_ERR_OK == res) {
      res = mtlk_core_send_fixed_rate(core, fixed_rate_cfg);
    }
    return res;
}

static int
_mtlk_core_set_fixed_rate (mtlk_handle_t hcore, const void *data, uint32 data_size)
{
    int res = MTLK_ERR_OK;
    mtlk_core_t *core = (mtlk_core_t *) hcore;
    mtlk_clpb_t *clpb = *(mtlk_clpb_t **) data;
    mtlk_fixed_rate_cfg_t *fixed_rate_cfg = NULL;
    uint32 cfg_size;

    MTLK_ASSERT(core != NULL);
    MTLK_ASSERT(sizeof(mtlk_clpb_t*) == data_size);

    /* get configuration */
    fixed_rate_cfg = mtlk_clpb_enum_get_next(clpb, &cfg_size);
    MTLK_CLPB_TRY(fixed_rate_cfg, cfg_size)
      MTLK_CFG_START_CHEK_ITEM_AND_CALL()
        /* send configuration to FW */
        MTLK_CFG_CHECK_ITEM_AND_CALL(fixed_rate_cfg, params, _mtlk_core_check_and_send_fixed_rate,
                                     (core, fixed_rate_cfg), res);
      MTLK_CFG_END_CHEK_ITEM_AND_CALL()
    MTLK_CLPB_FINALLY(res)
      /* push result into clipboard */
      return mtlk_clpb_push_res(clpb, res);
    MTLK_CLPB_END
}

static int
_mtlk_core_set_mac_assert (mtlk_handle_t hcore, const void* data, uint32 data_size)
{
  int res = MTLK_ERR_NOT_SUPPORTED;
  mtlk_core_t *nic = HANDLE_T_PTR(mtlk_core_t, hcore);
  mtlk_clpb_t *clpb = *(mtlk_clpb_t **) data;
  uint32  clpb_data_size;
  uint32* clpb_data;
  int     assert_type;

  MTLK_ASSERT(sizeof(mtlk_clpb_t*) == data_size);

  clpb_data = mtlk_clpb_enum_get_next(clpb, &clpb_data_size);
  MTLK_CLPB_TRY(clpb_data, clpb_data_size)
    assert_type = *clpb_data;

    WLOG_DD("CID-%04x: Rise MAC assert (assert type=%d)", mtlk_vap_get_oid(nic->vap_handle), assert_type);

    switch (assert_type) {
      case MTLK_CORE_UI_ASSERT_TYPE_ALL_MACS:
        wave_rcvry_type_forced_set(mtlk_vap_get_hw(nic->vap_handle), MTLK_CORE_UI_RCVRY_TYPE_NONE);
        (void)mtlk_hw_set_prop(mtlk_vap_get_hwapi(nic->vap_handle), MTLK_HW_DBG_ASSERT_ALL_MACS, NULL, 0);
        res = MTLK_ERR_OK;
        break;
      case MTLK_CORE_UI_ASSERT_TYPE_FW_LMIPS0:
      case MTLK_CORE_UI_ASSERT_TYPE_FW_LMIPS1:
      case MTLK_CORE_UI_ASSERT_TYPE_FW_LMIPS2:
      case MTLK_CORE_UI_ASSERT_TYPE_FW_UMIPS:
      {
        int mips_no;

        mips_no = hw_assert_type_to_core_nr(mtlk_vap_get_hw(nic->vap_handle), assert_type);
        if (mips_no == -1) {
          ELOG_DD("CID-%04x: Invalid assert type %d", mtlk_vap_get_oid(nic->vap_handle), assert_type);
          break;
        }
        wave_rcvry_type_forced_set(mtlk_vap_get_hw(nic->vap_handle), MTLK_CORE_UI_RCVRY_TYPE_NONE);
        res = mtlk_hw_set_prop(mtlk_vap_get_hwapi(nic->vap_handle), MTLK_HW_DBG_ASSERT_FW, &mips_no, sizeof(mips_no));
        if (res != MTLK_ERR_OK) {
          ELOG_DDD("CID-%04x: Can't assert FW MIPS#%d (res=%d)", mtlk_vap_get_oid(nic->vap_handle), mips_no, res);
        }
      }
      break;

      case MTLK_CORE_UI_ASSERT_TYPE_DRV_DIV0:
      {
      #ifdef __KLOCWORK__
        abort(1); /* Special case for correct analysis by Klocwork  */
      #else
        volatile int do_bug = 0;
        do_bug = 1/do_bug;
        ILOG0_D("do_bug = %d", do_bug); /* To avoid compilation optimization */
        res = MTLK_ERR_OK;
      #endif
      }
      break;

      case MTLK_CORE_UI_ASSERT_TYPE_DRV_BLOOP:
      #ifdef __KLOCWORK__
        abort(1); /* Special case for correct analysis by Klocwork  */
      #else
        while (1) {;}
      #endif
        break;

      case MTLK_CORE_UI_ASSERT_TYPE_NONE:
      case MTLK_CORE_UI_ASSERT_TYPE_LAST:
      default:
        WLOG_DD("CID-%04x: Unsupported assert type: %d", mtlk_vap_get_oid(nic->vap_handle), assert_type);
        res = MTLK_ERR_NOT_SUPPORTED;
        break;
    }
  MTLK_CLPB_FINALLY(res)
    return res;
  MTLK_CLPB_END
}

/********** DEBUG FUNCTIONS **********/
#ifdef CONFIG_WAVE_DEBUG

void __MTLK_IFUNC
mtlk_core_bswap_bcl_request (UMI_BCL_REQUEST *req, BOOL hdr_only)
{
  unsigned i;

  req->Size    = cpu_to_le32(req->Size);
  req->Address = cpu_to_le32(req->Address);
  req->Unit    = cpu_to_le32(req->Unit);

  if (!hdr_only) {
    for (i = 0; i < MTLK_ARRAY_SIZE(req->Data); i++) {
      req->Data[i] = cpu_to_le32(req->Data[i]);
    }
  }
}

typedef struct
{
  int          res;
  mtlk_clpb_t *clpb;
} mtlk_core_get_serializer_info_enum_ctx_t;

static BOOL
__mtlk_core_get_serializer_info_enum_clb (mtlk_serializer_t    *szr,
                                          const mtlk_command_t *command,
                                          BOOL                  is_current,
                                          mtlk_handle_t         enum_ctx)
{
  mtlk_core_get_serializer_info_enum_ctx_t *ctx =
    HANDLE_T_PTR(mtlk_core_get_serializer_info_enum_ctx_t, enum_ctx);
  mtlk_serializer_command_info_t cmd_info;

  MTLK_CFG_START_CHEK_ITEM_AND_CALL()
    MTLK_CFG_SET_ITEM(&cmd_info, is_current, is_current);
    MTLK_CFG_SET_ITEM(&cmd_info, priority, mtlk_command_get_priority(command));
    MTLK_CFG_SET_ITEM(&cmd_info, issuer_slid, mtlk_command_get_issuer_slid(command));
  MTLK_CFG_END_CHEK_ITEM_AND_CALL()

  ctx->res = mtlk_clpb_push(ctx->clpb, &cmd_info, sizeof(cmd_info));

  return (ctx->res == MTLK_ERR_OK)?TRUE:FALSE;
}

static int
_mtlk_core_get_serializer_info (mtlk_handle_t hcore,
                                const void* data, uint32 data_size)
{
  mtlk_core_t *nic = HANDLE_T_PTR(mtlk_core_t, hcore);
  mtlk_core_get_serializer_info_enum_ctx_t ctx;

  MTLK_ASSERT(sizeof(mtlk_clpb_t*) == data_size);

  ctx.clpb = *(mtlk_clpb_t **) data;
  ctx.res  = MTLK_ERR_OK;

  mtlk_serializer_enum_commands(&nic->slow_ctx->serializer, __mtlk_core_get_serializer_info_enum_clb, HANDLE_T(&ctx));

  return ctx.res;
}

static int __MTLK_IFUNC
wave_dbg_static_plan_mu_group_stats_ind_handle(mtlk_handle_t object, const void *data, uint32 data_size)
{
  int i;
  int group_id;
  mtlk_core_t *master_core;
  wave_radio_t *radio;
  UMI_DBG_HE_MU_GROUP_STATS *UmiDbgMuGroup = (UMI_DBG_HE_MU_GROUP_STATS *) data;
  UMI_DBG_HE_MU_GROUP_STATS HeMuGroups[HE_MU_MAX_NUM_OF_GROUPS];
  mtlk_pdb_size_t UmiDbgMuGroupStatsSize = sizeof(HeMuGroups);

  MTLK_ASSERT(sizeof(*UmiDbgMuGroup) == data_size);

  group_id = UmiDbgMuGroup->groupId;

  if(group_id >= HE_MU_MAX_NUM_OF_GROUPS) {
    ELOG_D("Wrong HE MU Group ID (%d) !", group_id);
    return MTLK_ERR_PARAMS;
  }

  master_core = HANDLE_T_PTR(mtlk_core_t, object);
  radio = wave_vap_radio_get(master_core->vap_handle);

  mtlk_dump(4, UmiDbgMuGroup, sizeof(*UmiDbgMuGroup), "dump of the UMI_MAN_HE_MU_DBG_IND");

  /* Read current MU group stats */
  if (MTLK_ERR_OK != WAVE_RADIO_PDB_GET_BINARY(radio, PARAM_DB_RADIO_PLAN_MU_GROUP_STATS, &HeMuGroups[0], &UmiDbgMuGroupStatsSize)) {
    ELOG_D("CID-%04x: Can't read PLAN_MU_GROUP_STATS from PDB", mtlk_vap_get_oid(master_core->vap_handle));
    return MTLK_ERR_PARAMS;
  }

  /* Update the stats for particular group */
  HeMuGroups[group_id].groupId  = group_id;
  HeMuGroups[group_id].planType = UmiDbgMuGroup->planType;
  HeMuGroups[group_id].vapId = UmiDbgMuGroup->vapId;
  HeMuGroups[group_id].setReset = UmiDbgMuGroup->setReset;
  for(i = 0; i < HE_MU_MAX_NUM_OF_USERS_PER_GROUP; i++) {
    HeMuGroups[group_id].stationId[i] = MAC_TO_HOST16(UmiDbgMuGroup->stationId[i]);
  }

  if (MTLK_ERR_OK != WAVE_RADIO_PDB_SET_BINARY(radio, PARAM_DB_RADIO_PLAN_MU_GROUP_STATS, &HeMuGroups[0], UmiDbgMuGroupStatsSize)) {
    ELOG_D("CID-%04x: Can't set PLAN_MU_GROUP_STATS to PDB", mtlk_vap_get_oid(master_core->vap_handle));
    return MTLK_ERR_PARAMS;
  }

  return MTLK_ERR_OK;
}

static int
_mtlk_core_get_qos_map_info (mtlk_handle_t hcore, const void* data, uint32 data_size)
{
  int                       res = MTLK_ERR_OK;
  mtlk_core_t               *nic = HANDLE_T_PTR(mtlk_core_t, hcore);
  mtlk_clpb_t               *clpb = *(mtlk_clpb_t **) data;
  mtlk_core_qos_map_info_t  *qos_map_info;

  MTLK_ASSERT(sizeof(mtlk_clpb_t*) == data_size);

  qos_map_info = mtlk_osal_mem_alloc(sizeof(*qos_map_info), MTLK_MEM_TAG_CLPB);
  if(qos_map_info == NULL) {
    ELOG_V("Can't allocate clipboard data");
    res = MTLK_ERR_NO_MEM;
    goto err_finish;
  }
  memset(qos_map_info, 0, sizeof(*qos_map_info));
  wave_memcpy(qos_map_info->dscp_table, sizeof(qos_map_info->dscp_table), nic->dscp_table, sizeof(nic->dscp_table));

  res = mtlk_clpb_push_nocopy(clpb, qos_map_info, sizeof(*qos_map_info));
  if (MTLK_ERR_OK != res) {
    mtlk_clpb_purge(clpb);
    goto err_finish;
  }

  return MTLK_ERR_OK;

err_finish:
  if (qos_map_info) {
    mtlk_osal_mem_free(qos_map_info);
  }
  return res;
}

static int _mtlk_core_get_blacklist_entries (mtlk_handle_t hcore, const void* data, uint32 data_size)
{
  mtlk_core_t *core = HANDLE_T_PTR(mtlk_core_t, hcore);

  return _mtlk_core_dump_ieee_addr_list (core, &core->widan_blacklist,
    "widan black", data, data_size);
}

static int
_mtlk_core_get_mc_hw_tbl (mtlk_handle_t hcore, const void* data, uint32 data_size)
{
  int res = MTLK_ERR_NOT_SUPPORTED;
  mtlk_core_t *nic = HANDLE_T_PTR(mtlk_core_t, hcore);
  mtlk_clpb_t *clpb = *(mtlk_clpb_t **) data;
  mtlk_core_ui_mc_grid_action_t req;
  int i;

  MTLK_ASSERT(sizeof(mtlk_clpb_t*) == data_size);

  for (i = MC_MIN_GROUP; i < MC_GROUPS; i++) {
    req.grp_id = i;
    mtlk_hw_get_prop(mtlk_vap_get_hwapi(nic->vap_handle), MTLK_HW_MC_GROUP_ID, &req, sizeof(req));
    res = mtlk_clpb_push(clpb, &req, sizeof(req));
    if (MTLK_ERR_OK != res) {
      goto err_push;
    }
  }

  goto finish;

err_push:
   mtlk_clpb_purge(clpb);
finish:
  return res;
}

static int
_mtlk_core_get_mc_igmp_tbl(mtlk_handle_t hcore, const void* data, uint32 data_size)
{
  int res = MTLK_ERR_NOT_SUPPORTED;
  mtlk_core_t *nic = HANDLE_T_PTR(mtlk_core_t, hcore);
  mtlk_clpb_t *clpb = *(mtlk_clpb_t **) data;

  MTLK_ASSERT(sizeof(mtlk_clpb_t*) == data_size);

  res = mtlk_mc_dump_groups(nic, clpb);

  return res;
}

static mtlk_error_t
_mtlk_core_set_fw_log_severity (mtlk_handle_t hcore, const void* data, uint32 data_size)
{
  mtlk_error_t res = MTLK_ERR_UNKNOWN;
  mtlk_fw_log_severity_t  *fw_log_severity;
  mtlk_core_t  *core = HANDLE_T_PTR(mtlk_core_t, hcore);
  mtlk_clpb_t  *clpb = *(mtlk_clpb_t **) data;
  uint32        clpb_data_size;

  MTLK_ASSERT(sizeof(mtlk_clpb_t*) == data_size);

  fw_log_severity = mtlk_clpb_enum_get_next(clpb, &clpb_data_size);
  MTLK_CLPB_TRY(fw_log_severity, clpb_data_size)
    MTLK_CFG_START_CHEK_ITEM_AND_CALL()
      /* need to check two parameters */
      /* 1st: check only */
      MTLK_CFG_CHECK_ITEM_VOID(fw_log_severity, newLevel);
      /* 2nd: check and call */
      MTLK_CFG_CHECK_ITEM_AND_CALL(fw_log_severity, targetCPU,
          _mtlk_mmb_send_fw_log_severity,
          (mtlk_vap_get_hw(core->vap_handle), fw_log_severity->newLevel, fw_log_severity->targetCPU), res);
    MTLK_CFG_END_CHEK_ITEM_AND_CALL()
  MTLK_CLPB_FINALLY(res)
    return mtlk_clpb_push_res(clpb, res);
  MTLK_CLPB_END
}

static mtlk_error_t
_mtlk_core_fw_debug (mtlk_handle_t hcore, const void* data, uint32 data_size)
{
  mtlk_fw_debug_cfg_t *UmiFWDebugReq;
  mtlk_error_t         res = MTLK_ERR_OK;

  mtlk_core_t *core = HANDLE_T_PTR(mtlk_core_t, hcore);
  mtlk_clpb_t *clpb = *(mtlk_clpb_t **) data;
  uint32 clpb_data_size;
  mtlk_fw_debug_cfg_t* clpb_data;

  MTLK_ASSERT(sizeof(mtlk_clpb_t*) == data_size);

  clpb_data = mtlk_clpb_enum_get_next(clpb, &clpb_data_size);
  MTLK_CLPB_TRY(clpb_data, clpb_data_size)
  {
    UmiFWDebugReq = (mtlk_fw_debug_cfg_t*)clpb_data;

    ILOG2_DD("CID-%04x: FW debug type: %d",
             mtlk_vap_get_oid(core->vap_handle),
             UmiFWDebugReq->FWDebugReq.debugType);

    wave_rcvry_set_to_dbg_mode(core->vap_handle);
    res = mtlk_core_fw_assert(core, &UmiFWDebugReq->FWDebugReq);
  }
  MTLK_CLPB_FINALLY(res)
    return mtlk_clpb_push_res(clpb, res);
  MTLK_CLPB_END;
}

static void _mtlk_set_dbg_channel_switch_count(mtlk_scan_support_t *obj, int channel_switch_count)
{
  obj->dfs_debug_params.beacon_count = channel_switch_count;
}

static int _mtlk_get_dbg_channel_switch_count (mtlk_scan_support_t* obj)
{
  MTLK_ASSERT(NULL != obj);

  return obj->dfs_debug_params.beacon_count;
}

static void _mtlk_set_dbg_nop (mtlk_scan_support_t *obj, uint32 nop)
{
  obj->dfs_debug_params.nop = nop;
}

static int _mtlk_get_dbg_nop (mtlk_scan_support_t* obj)
{
  MTLK_ASSERT(NULL != obj);

  return obj->dfs_debug_params.nop ? obj->dfs_debug_params.nop : (IEEE80211_DFS_MIN_NOP_TIME_MS / MTLK_OSAL_MSEC_IN_MIN);
}

static void
_wave_radio_fixed_pwr_params_get (wave_radio_t *radio, FIXED_POWER *fixed_pwr_params)
{
  mtlk_pdb_size_t fixed_pwr_cfg_size = sizeof(*fixed_pwr_params);

  MTLK_ASSERT(NULL != radio);
  if (MTLK_ERR_OK != WAVE_RADIO_PDB_GET_BINARY(radio, PARAM_DB_RADIO_FIXED_PWR, fixed_pwr_params, &fixed_pwr_cfg_size)) {
    ELOG_V("Failed to get Fixed TX management power parameters");
  }
}

static mtlk_error_t
_mtlk_core_get_mac_wdog_cfg (mtlk_handle_t hcore,
                             const void* data, uint32 data_size)
{
  mtlk_error_t res = MTLK_ERR_OK;
  mtlk_mac_wdog_cfg_t mac_wdog_cfg;
  mtlk_core_t *core = (mtlk_core_t*)hcore;
  mtlk_clpb_t *clpb = *(mtlk_clpb_t **) data;
  wave_radio_t *radio = wave_vap_radio_get(core->vap_handle);

  MTLK_ASSERT(sizeof(mtlk_clpb_t*) == data_size);

  memset(&mac_wdog_cfg, 0, sizeof(mac_wdog_cfg));

  MTLK_CFG_SET_ITEM(&mac_wdog_cfg, mac_watchdog_timeout_ms,
                    WAVE_RADIO_PDB_GET_INT(radio, PARAM_DB_RADIO_MAC_WATCHDOG_TIMER_TIMEOUT_MS));
  MTLK_CFG_SET_ITEM(&mac_wdog_cfg, mac_watchdog_period_ms,
                    WAVE_RADIO_PDB_GET_INT(radio, PARAM_DB_RADIO_MAC_WATCHDOG_TIMER_PERIOD_MS));

  res = mtlk_clpb_push(clpb, &res, sizeof(res));
  if (MTLK_ERR_OK == res) {
    res = mtlk_clpb_push(clpb, &mac_wdog_cfg, sizeof(mac_wdog_cfg));
  }

  return res;
}

static int
_mtlk_core_set_mac_wdog_timeout(mtlk_core_t *core, uint16 value)
{
  if (value < 1000) {
    return MTLK_ERR_PARAMS;
  }
  WAVE_RADIO_PDB_SET_INT(wave_vap_radio_get(core->vap_handle), PARAM_DB_RADIO_MAC_WATCHDOG_TIMER_TIMEOUT_MS, value);
  return MTLK_ERR_OK;
}

static int
_mtlk_core_set_mac_wdog_period(mtlk_core_t *core, uint32 value)
{
  if (0 == value) {
    return MTLK_ERR_PARAMS;
  }
  WAVE_RADIO_PDB_SET_INT(wave_vap_radio_get(core->vap_handle), PARAM_DB_RADIO_MAC_WATCHDOG_TIMER_PERIOD_MS, value);
  return MTLK_ERR_OK;
}

static mtlk_error_t
_mtlk_core_set_mac_wdog_cfg (mtlk_handle_t hcore,
                             const void* data, uint32 data_size)
{
  mtlk_error_t res = MTLK_ERR_OK;
  mtlk_core_t *core = (mtlk_core_t*)hcore;
  mtlk_mac_wdog_cfg_t *mac_wdog_cfg = NULL;
  uint32 mac_wdog_cfg_size;
  mtlk_clpb_t *clpb = *(mtlk_clpb_t **) data;

  MTLK_ASSERT(sizeof(mtlk_clpb_t*) == data_size);

  mac_wdog_cfg = mtlk_clpb_enum_get_next(clpb, &mac_wdog_cfg_size);
  MTLK_CLPB_TRY(mac_wdog_cfg, mac_wdog_cfg_size)
  {
    MTLK_CFG_START_CHEK_ITEM_AND_CALL()
       MTLK_CFG_CHECK_ITEM_AND_CALL(mac_wdog_cfg, mac_watchdog_timeout_ms, _mtlk_core_set_mac_wdog_timeout,
                                   (core, mac_wdog_cfg->mac_watchdog_timeout_ms), res);
       MTLK_CFG_CHECK_ITEM_AND_CALL(mac_wdog_cfg, mac_watchdog_period_ms, _mtlk_core_set_mac_wdog_period,
                                   (core, mac_wdog_cfg->mac_watchdog_period_ms), res);
    MTLK_CFG_END_CHEK_ITEM_AND_CALL()
  }
  MTLK_CLPB_FINALLY(res)
    return mtlk_clpb_push_res(clpb, res);
  MTLK_CLPB_END;
}

static mtlk_error_t
_mtlk_core_get_hstdb_cfg (mtlk_handle_t hcore,
                          const void* data, uint32 data_size)
{
  mtlk_error_t res = MTLK_ERR_OK;
  mtlk_hstdb_cfg_t hstdb_cfg;
  mtlk_core_t *core = (mtlk_core_t*)hcore;
  mtlk_clpb_t *clpb = *(mtlk_clpb_t **) data;

  MTLK_ASSERT(sizeof(mtlk_clpb_t*) == data_size);

  memset(&hstdb_cfg, 0, sizeof(hstdb_cfg));

  MTLK_CFG_SET_ITEM(&hstdb_cfg, wds_host_timeout, core->slow_ctx->hstdb.wds_host_timeout);

  res = mtlk_clpb_push(clpb, &res, sizeof(res));
  if (MTLK_ERR_OK == res) {
    res = mtlk_clpb_push(clpb, &hstdb_cfg, sizeof(hstdb_cfg));
  }

  return res;
}

static mtlk_error_t
_mtlk_core_set_hstdb_cfg (mtlk_handle_t hcore,
                          const void* data, uint32 data_size)
{
  mtlk_error_t res = MTLK_ERR_OK;
  mtlk_core_t *core = (mtlk_core_t*)hcore;
  mtlk_hstdb_cfg_t *hstdb_cfg = NULL;
  uint32 hstdb_cfg_size;
  mtlk_clpb_t *clpb = *(mtlk_clpb_t **) data;

  MTLK_ASSERT(sizeof(mtlk_clpb_t*) == data_size);

  hstdb_cfg = mtlk_clpb_enum_get_next(clpb, &hstdb_cfg_size);
  MTLK_CLPB_TRY(hstdb_cfg, hstdb_cfg_size)
  {
    MTLK_CFG_START_CHEK_ITEM_AND_CALL()
      MTLK_CFG_GET_ITEM(hstdb_cfg, wds_host_timeout, core->slow_ctx->hstdb.wds_host_timeout);
    MTLK_CFG_END_CHEK_ITEM_AND_CALL()
  }
  MTLK_CLPB_FINALLY(res)
    return mtlk_clpb_push_res(clpb, res);
  MTLK_CLPB_END;
}

#ifdef CPTCFG_IWLWAV_PMCU_SUPPORT
static int
_mtlk_core_get_pcoc_params (mtlk_core_t *core, mtlk_pcoc_params_t *params)
{
  mtlk_pcoc_params_t *configured_params;

  MTLK_ASSERT(core != NULL);
  MTLK_ASSERT(params != NULL);

  configured_params = wv_PMCU_Get_Params();
  *params = *configured_params;

  return MTLK_ERR_OK;
}

static mtlk_error_t
_mtlk_core_get_pcoc_cfg (mtlk_handle_t hcore,
                         const void* data, uint32 data_size)
{
  mtlk_error_t res = MTLK_ERR_OK;
  mtlk_pcoc_mode_cfg_t pcoc_cfg;
  mtlk_core_t *core = (mtlk_core_t*)hcore;
  mtlk_clpb_t *clpb = *(mtlk_clpb_t **) data;

  MTLK_ASSERT(sizeof(mtlk_clpb_t*) == data_size);
  MTLK_ASSERT(!mtlk_vap_is_slave_ap(core->vap_handle));

  memset(&pcoc_cfg, 0, sizeof(pcoc_cfg));

  MTLK_CFG_SET_ITEM(&pcoc_cfg, is_enabled,    wv_PMCU_is_enabled_adm());
  MTLK_CFG_SET_ITEM(&pcoc_cfg, is_active,     wv_PMCU_is_active());
  MTLK_CFG_SET_ITEM(&pcoc_cfg, traffic_state, wv_PMCU_get_traffic_state());
  MTLK_CFG_SET_ITEM_BY_FUNC(&pcoc_cfg, params,
                            _mtlk_core_get_pcoc_params, (core, &pcoc_cfg.params), res);

  res = mtlk_clpb_push(clpb, &res, sizeof(res));
  if (MTLK_ERR_OK == res) {
    res = mtlk_clpb_push(clpb, &pcoc_cfg, sizeof(pcoc_cfg));
  }

  return res;
}

static int
_mtlk_core_set_pcoc_enabled (mtlk_core_t *core, BOOL is_enabled)
{
  int res = MTLK_ERR_OK;

  res = wv_PMCU_set_enabled_adm(is_enabled);

  return res;
}

static int
_mtlk_core_set_pcoc_pmcu_debug (mtlk_core_t *core, uint32 pmcu_debug)
{
  int res = MTLK_ERR_OK;

  return res;
}

static mtlk_error_t
_mtlk_core_set_pcoc_cfg (mtlk_handle_t hcore,
                         const void* data, uint32 data_size)
{
  mtlk_error_t res = MTLK_ERR_OK;
  mtlk_core_t *core = (mtlk_core_t*)hcore;
  mtlk_pcoc_mode_cfg_t *pcoc_cfg = NULL;
  uint32 pcoc_cfg_size;
  mtlk_clpb_t *clpb = *(mtlk_clpb_t **) data;

  MTLK_ASSERT(sizeof(mtlk_clpb_t*) == data_size);

  pcoc_cfg = mtlk_clpb_enum_get_next(clpb, &pcoc_cfg_size);
  MTLK_CLPB_TRY(pcoc_cfg, pcoc_cfg_size)
  {
    MTLK_CFG_START_CHEK_ITEM_AND_CALL()
      MTLK_CFG_CHECK_ITEM_AND_CALL(pcoc_cfg, params, wv_PMCU_Set_Params,
                                   (&pcoc_cfg->params), res);
      MTLK_CFG_CHECK_ITEM_AND_CALL(pcoc_cfg, is_enabled, _mtlk_core_set_pcoc_enabled,
                                   (core, pcoc_cfg->is_enabled), res);
      MTLK_CFG_CHECK_ITEM_AND_CALL(pcoc_cfg, pmcu_debug, _mtlk_core_set_pcoc_pmcu_debug,
                                   (core, pcoc_cfg->pmcu_debug), res);
    MTLK_CFG_END_CHEK_ITEM_AND_CALL()
  }
  MTLK_CLPB_FINALLY(res)
    return mtlk_clpb_push_res(clpb, res);
  MTLK_CLPB_END;
}
#endif /*CPTCFG_IWLWAV_PMCU_SUPPORT*/

static mtlk_error_t
_mtlk_core_get_ta_cfg (mtlk_handle_t hcore, const void* data, uint32 data_size)
{
  mtlk_error_t res = MTLK_ERR_OK;
  mtlk_ta_cfg_t *ta_cfg;
  mtlk_core_t *core = (mtlk_core_t*)hcore;
  mtlk_clpb_t *clpb = *(mtlk_clpb_t **) data;

  MTLK_ASSERT(sizeof(mtlk_clpb_t*) == data_size);

  ta_cfg = mtlk_osal_mem_alloc(sizeof(*ta_cfg), MTLK_MEM_TAG_CLPB);
  if(ta_cfg == NULL) {
    ELOG_D("CID-%04x: Can't allocate clipboard data", mtlk_vap_get_oid(core->vap_handle));
    return MTLK_ERR_NO_MEM;
  }

  memset(ta_cfg, 0, sizeof(*ta_cfg));

  MTLK_CFG_SET_ITEM(ta_cfg, timer_resolution,
    mtlk_ta_get_timer_resolution_ticks(mtlk_vap_get_ta(core->vap_handle)));

  MTLK_CFG_SET_ITEM_BY_FUNC_VOID(ta_cfg, debug_info, mtlk_ta_get_debug_info,
                                 (mtlk_vap_get_ta(core->vap_handle), &ta_cfg->debug_info));

  res = mtlk_clpb_push(clpb, &res, sizeof(res));
  if (MTLK_ERR_OK == res) {
    res = mtlk_clpb_push_nocopy(clpb, ta_cfg, sizeof(*ta_cfg));
    if(MTLK_ERR_OK != res) {
      mtlk_osal_mem_free(ta_cfg);
    }
  }

  return res;
}

static mtlk_error_t
_mtlk_core_set_ta_cfg (mtlk_handle_t hcore, const void* data, uint32 data_size)
{
  mtlk_error_t res = MTLK_ERR_OK;
  mtlk_ta_cfg_t *ta_cfg;
  uint32  ta_cfg_size;
  mtlk_core_t *core = (mtlk_core_t*)hcore;
  mtlk_clpb_t *clpb = *(mtlk_clpb_t **) data;

  MTLK_ASSERT(sizeof(mtlk_clpb_t*) == data_size);

  ta_cfg = mtlk_clpb_enum_get_next(clpb, &ta_cfg_size);
  MTLK_CLPB_TRY(ta_cfg, ta_cfg_size)
    MTLK_CFG_START_CHEK_ITEM_AND_CALL()
      MTLK_CFG_CHECK_ITEM_AND_CALL(ta_cfg, timer_resolution, mtlk_ta_set_timer_resolution_ticks,
                                   (mtlk_vap_get_ta(core->vap_handle), ta_cfg->timer_resolution), res);
    MTLK_CFG_END_CHEK_ITEM_AND_CALL()
  MTLK_CLPB_FINALLY(res)
    return mtlk_clpb_push_res(clpb, res);
  MTLK_CLPB_END
}

static mtlk_error_t
_mtlk_core_get_tasklet_limits (mtlk_handle_t hcore, const void* data, uint32 data_size)
{
  mtlk_core_t *core = (mtlk_core_t *) hcore;
  mtlk_hw_api_t *hw_api = mtlk_vap_get_hwapi(core->vap_handle);
  mtlk_tasklet_limits_cfg_t tl_cfg;
  mtlk_clpb_t *clpb = *(mtlk_clpb_t **) data;
  mtlk_error_t res = MTLK_ERR_OK;

  MTLK_ASSERT(sizeof(mtlk_clpb_t*) == data_size);
  MTLK_ASSERT(!mtlk_vap_is_slave_ap(core->vap_handle));

  memset(&tl_cfg, 0, sizeof(tl_cfg));

  res |= mtlk_hw_get_prop(hw_api, MTLK_HW_DATA_TXOUT_LIM, &tl_cfg.tl.data_txout_lim, sizeof(tl_cfg.tl.data_txout_lim));
  res |= mtlk_hw_get_prop(hw_api, MTLK_HW_DATA_RX_LIM, &tl_cfg.tl.data_rx_lim, sizeof(tl_cfg.tl.data_rx_lim));
  res |= mtlk_hw_get_prop(hw_api, MTLK_HW_BSS_RX_LIM, &tl_cfg.tl.bss_rx_lim, sizeof(tl_cfg.tl.bss_rx_lim));
  res |= mtlk_hw_get_prop(hw_api, MTLK_HW_BSS_CFM_LIM, &tl_cfg.tl.bss_cfm_lim, sizeof(tl_cfg.tl.bss_cfm_lim));
  res |= mtlk_hw_get_prop(hw_api, MTLK_HW_LEGACY_LIM, &tl_cfg.tl.legacy_lim, sizeof(tl_cfg.tl.legacy_lim));

  if (MTLK_ERR_OK != res)
    ELOG_D("CID-%04x: Can't get tasklet_limits", mtlk_vap_get_oid(core->vap_handle));
  else
    tl_cfg.tl_filled = 1;

  res = mtlk_clpb_push(clpb, &res, sizeof(res));

  if (MTLK_ERR_OK == res)
    res = mtlk_clpb_push(clpb, &tl_cfg, sizeof(tl_cfg));

  return res;
}

static mtlk_error_t
_mtlk_core_set_tasklet_limits (mtlk_handle_t hcore, const void* data, uint32 data_size)
{
  mtlk_error_t res = MTLK_ERR_OK;
  mtlk_core_t *core = (mtlk_core_t *) hcore;
  mtlk_hw_api_t *hw_api = mtlk_vap_get_hwapi(core->vap_handle);
  mtlk_tasklet_limits_cfg_t *tl_cfg = NULL;
  uint32 tl_cfg_size;
  mtlk_clpb_t *clpb = *(mtlk_clpb_t **) data;

  MTLK_ASSERT(sizeof(mtlk_clpb_t*) == data_size);

  tl_cfg = mtlk_clpb_enum_get_next(clpb, &tl_cfg_size);
  MTLK_CLPB_TRY(tl_cfg, tl_cfg_size)
    if (!tl_cfg->tl_filled)
      MTLK_CLPB_EXIT(MTLK_ERR_UNKNOWN);

    res |= mtlk_hw_set_prop(hw_api, MTLK_HW_DATA_TXOUT_LIM, &tl_cfg->tl.data_txout_lim, sizeof(tl_cfg->tl.data_txout_lim));
    res |= mtlk_hw_set_prop(hw_api, MTLK_HW_DATA_RX_LIM, &tl_cfg->tl.data_rx_lim, sizeof(tl_cfg->tl.data_rx_lim));
    res |= mtlk_hw_set_prop(hw_api, MTLK_HW_BSS_RX_LIM, &tl_cfg->tl.bss_rx_lim, sizeof(tl_cfg->tl.bss_rx_lim));
    res |= mtlk_hw_set_prop(hw_api, MTLK_HW_BSS_CFM_LIM, &tl_cfg->tl.bss_cfm_lim, sizeof(tl_cfg->tl.bss_cfm_lim));
    res |= mtlk_hw_set_prop(hw_api, MTLK_HW_LEGACY_LIM, &tl_cfg->tl.legacy_lim, sizeof(tl_cfg->tl.legacy_lim));

    if (MTLK_ERR_OK != res)
      ELOG_D("CID-%04x: Can't set tasklet_limits", mtlk_vap_get_oid(core->vap_handle));
  MTLK_CLPB_FINALLY(res)
    return mtlk_clpb_push_res(clpb, res);
  MTLK_CLPB_END
}

static mtlk_error_t
_mtlk_core_get_bf_explicit_cap (mtlk_handle_t hcore, const void* data, uint32 data_size)
{
    mtlk_error_t res = MTLK_ERR_OK;
    mtlk_bf_explicit_cap_cfg_t bf_explicit_cap_cfg;
    mtlk_core_t *core = (mtlk_core_t*)hcore;
    mtlk_clpb_t *clpb = *(mtlk_clpb_t **) data;

    MTLK_ASSERT(sizeof(mtlk_clpb_t*) == data_size);

    /* read capability */
    MTLK_CFG_SET_ITEM(&bf_explicit_cap_cfg, bf_explicit_cap, core_get_psdb_bf_explicit_cap(core));

    /* push result and config to clipboard*/
    res = mtlk_clpb_push(clpb, &res, sizeof(res));
    if (MTLK_ERR_OK == res) {
        res = mtlk_clpb_push(clpb, &bf_explicit_cap_cfg, sizeof(bf_explicit_cap_cfg));
    }

    return res;
}

#ifdef CPTCFG_IWLWAV_SET_PM_QOS
static int
_mtlk_core_set_cpu_dma_latency (mtlk_handle_t hcore, const void* data, uint32 data_size)
{
    int res = MTLK_ERR_OK;
    mtlk_core_t *core = (mtlk_core_t *) hcore;
    mtlk_pm_qos_cfg_t *pm_qos_cfg = NULL;
    uint32 pm_qos_cfg_size;
    mtlk_clpb_t *clpb = *(mtlk_clpb_t **) data;

    MTLK_ASSERT(sizeof(mtlk_clpb_t*) == data_size);
    /* get configuration */
    pm_qos_cfg = mtlk_clpb_enum_get_next(clpb, &pm_qos_cfg_size);
    MTLK_CLPB_TRY(pm_qos_cfg, pm_qos_cfg_size)
    {
      MTLK_CFG_START_CHEK_ITEM_AND_CALL()
        /* change config */
        MTLK_CFG_CHECK_ITEM_AND_CALL(pm_qos_cfg, cpu_dma_latency, mtlk_mmb_update_cpu_dma_latency,
                                (mtlk_vap_get_hw(core->vap_handle), pm_qos_cfg->cpu_dma_latency), res);
      MTLK_CFG_END_CHEK_ITEM_AND_CALL()
    }
    MTLK_CLPB_FINALLY(res)
      /* push result into clipboard */
      return mtlk_clpb_push_res(clpb, res);
    MTLK_CLPB_END;
}

static int
_mtlk_core_get_cpu_dma_latency (mtlk_handle_t hcore, const void* data, uint32 data_size)
{
    int res = MTLK_ERR_OK;
    mtlk_pm_qos_cfg_t pm_qos_cfg;
    mtlk_clpb_t *clpb = *(mtlk_clpb_t **) data;

    MTLK_UNREFERENCED_PARAM(hcore);
    MTLK_ASSERT(sizeof(mtlk_clpb_t*) == data_size);
    MTLK_CFG_SET_ITEM(&pm_qos_cfg, cpu_dma_latency, cpu_dma_latency);

    /* push result and config to clipboard*/
    res = mtlk_clpb_push(clpb, &res, sizeof(res));
    if (MTLK_ERR_OK == res) {
        res = mtlk_clpb_push(clpb, &pm_qos_cfg, sizeof(pm_qos_cfg));
    }
    return res;
}
#endif
#endif /* CONFIG_WAVE_DEBUG */

static mtlk_error_t
_mtlk_core_get_dot11h_ap_cfg (mtlk_handle_t hcore,
                              const void* data, uint32 data_size)
{
  mtlk_error_t res = MTLK_ERR_OK;
  mtlk_11h_ap_cfg_t dot11h_cfg;
  mtlk_core_t *core = (mtlk_core_t*)hcore;
  mtlk_clpb_t *clpb = *(mtlk_clpb_t **) data;

  MTLK_ASSERT(sizeof(mtlk_clpb_t*) == data_size);
  MTLK_ASSERT(!mtlk_vap_is_slave_ap(core->vap_handle));

  memset(&dot11h_cfg, 0, sizeof(dot11h_cfg));

  MTLK_CFG_SET_ITEM(&dot11h_cfg, debugChannelAvailabilityCheckTime,
                     mtlk_get_dbg_channel_availability_check_time(mtlk_core_get_scan_support(core)));
#ifdef CONFIG_WAVE_DEBUG
  MTLK_CFG_SET_ITEM(&dot11h_cfg, debugChannelSwitchCount,
                     _mtlk_get_dbg_channel_switch_count(mtlk_core_get_scan_support(core)));

  MTLK_CFG_SET_ITEM(&dot11h_cfg, debugNOP,
                     _mtlk_get_dbg_nop(mtlk_core_get_scan_support(core)));
#endif
  res = mtlk_clpb_push(clpb, &res, sizeof(res));
  if (MTLK_ERR_OK == res) {
    res = mtlk_clpb_push(clpb, &dot11h_cfg, sizeof(dot11h_cfg));
  }

  return res;
}

static int
_mtlk_set_dbg_channel_availability_check_time (mtlk_scan_support_t* obj, int channel_availability_check_time)
{
  mtlk_df_t *df;
  mtlk_df_user_t *df_user;
  struct wireless_dev *wdev;
  struct wiphy *wiphy;
  MTLK_ASSERT(NULL != obj);
  df = mtlk_vap_get_df(obj->master_core->vap_handle);
  df_user = mtlk_df_get_user(df);
  wdev = mtlk_df_user_get_wdev(df_user);
  wiphy = wdev->wiphy;

  if ((channel_availability_check_time < -1) ||
      (channel_availability_check_time == 0) ||
      (channel_availability_check_time > (IEEE80211_DFS_MAX_CAC_TIME_MS / MTLK_OSAL_MSEC_IN_SEC))) {
    ELOG_D("Wrong debug CAC time: %d seconds", channel_availability_check_time);
    return MTLK_ERR_PARAMS;
  }

  wiphy->cac_time_debug = channel_availability_check_time * MTLK_OSAL_MSEC_IN_SEC;
  return MTLK_ERR_OK;
}

static mtlk_error_t
_mtlk_core_set_dot11h_ap_cfg (mtlk_handle_t hcore,
                              const void* data, uint32 data_size)
{
  mtlk_error_t res = MTLK_ERR_OK;
  mtlk_core_t *core = (mtlk_core_t*)hcore;
  mtlk_11h_ap_cfg_t *dot11h_cfg = NULL;
  uint32 dot11h_cfg_size;
  mtlk_clpb_t *clpb = *(mtlk_clpb_t **) data;

  MTLK_ASSERT(sizeof(mtlk_clpb_t*) == data_size);
  MTLK_ASSERT(!mtlk_vap_is_slave_ap(core->vap_handle));

  dot11h_cfg = mtlk_clpb_enum_get_next(clpb, &dot11h_cfg_size);
  MTLK_CLPB_TRY(dot11h_cfg, dot11h_cfg_size)
  {
    MTLK_CFG_START_CHEK_ITEM_AND_CALL()

      MTLK_CFG_CHECK_ITEM_AND_CALL(dot11h_cfg, debugChannelAvailabilityCheckTime, _mtlk_set_dbg_channel_availability_check_time,
                                   (mtlk_core_get_scan_support(core), dot11h_cfg->debugChannelAvailabilityCheckTime), res);
#ifdef CONFIG_WAVE_DEBUG
      MTLK_CFG_CHECK_ITEM_AND_CALL_VOID(dot11h_cfg, debugChannelSwitchCount, _mtlk_set_dbg_channel_switch_count,
                                        (mtlk_core_get_scan_support(core), dot11h_cfg->debugChannelSwitchCount));

      MTLK_CFG_CHECK_ITEM_AND_CALL_VOID(dot11h_cfg, debugNOP, _mtlk_set_dbg_nop,
                                    (mtlk_core_get_scan_support(core), dot11h_cfg->debugNOP));
#endif
    MTLK_CFG_END_CHEK_ITEM_AND_CALL()
  }
  MTLK_CLPB_FINALLY(res)
    return mtlk_clpb_push_res(clpb, res);
  MTLK_CLPB_END;
}

static int
_wave_core_get_phy_inband_power (mtlk_handle_t hcore,
                                 const void *data, uint32 data_size)
{
  int res = MTLK_ERR_OK;
  mtlk_phy_inband_power_cfg_t power_cfg;
  mtlk_core_t *core = (mtlk_core_t*)hcore;
  mtlk_clpb_t *clpb = *(mtlk_clpb_t **) data;
  wave_radio_t *radio;

  MTLK_ASSERT(sizeof(mtlk_clpb_t*) == data_size);

  radio = wave_vap_radio_get(core->vap_handle);

  memset(&power_cfg, 0, sizeof(power_cfg));
  MTLK_CFG_SET_ITEM_BY_FUNC(&power_cfg, power_data, mtlk_ccr_read_phy_inband_power,
                            (mtlk_hw_mmb_get_ccr(mtlk_vap_get_hw(core->vap_handle)),
                             wave_radio_id_get(radio),
                             wave_radio_current_antenna_mask_get(radio),
                             power_cfg.power_data.noise_estim,
                             power_cfg.power_data.system_gain),
                             res);

  return mtlk_clpb_push_res_data(clpb, res, &power_cfg, sizeof(power_cfg));
}

static mtlk_error_t
_mtlk_core_set_wds_cfg (mtlk_handle_t hcore,
                        const void* data, uint32 data_size)
{
  mtlk_error_t res = MTLK_ERR_OK;
  mtlk_wds_cfg_t *wds_cfg;
  uint32  wds_cfg_size;
  mtlk_core_t *core = (mtlk_core_t*)hcore;
  mtlk_clpb_t *clpb = *(mtlk_clpb_t **) data;

  MTLK_ASSERT(sizeof(mtlk_clpb_t*) == data_size);

  wds_cfg = mtlk_clpb_enum_get_next(clpb, &wds_cfg_size);
  MTLK_CLPB_TRY(wds_cfg, wds_cfg_size)
  {
    MTLK_CFG_START_CHEK_ITEM_AND_CALL()
      MTLK_CFG_CHECK_ITEM_AND_CALL(wds_cfg, peer_ap_addr_add, wds_usr_add_peer_ap,
                                   (&core->slow_ctx->wds_mng, &wds_cfg->peer_ap_addr_add), res);

      MTLK_CFG_CHECK_ITEM_AND_CALL(wds_cfg, peer_ap_addr_del, wds_usr_del_peer_ap,
                                   (&core->slow_ctx->wds_mng, &wds_cfg->peer_ap_addr_del), res);

      MTLK_CFG_GET_ITEM(wds_cfg, peer_ap_key_idx, core->slow_ctx->peerAPs_key_idx);

    MTLK_CFG_END_CHEK_ITEM_AND_CALL()
  }
  MTLK_CLPB_FINALLY(res)
    return mtlk_clpb_push_res(clpb, res);
  MTLK_CLPB_END;
}

static mtlk_error_t
_mtlk_core_get_wds_cfg (mtlk_handle_t hcore,
                        const void* data, uint32 data_size)
{
  mtlk_error_t res = MTLK_ERR_OK;
  mtlk_wds_cfg_t wds_cfg;
  mtlk_core_t *core = (mtlk_core_t*)hcore;
  mtlk_clpb_t *clpb = *(mtlk_clpb_t **) data;

  MTLK_ASSERT(sizeof(mtlk_clpb_t*) == data_size);

  memset(&wds_cfg, 0, sizeof(wds_cfg));

  MTLK_CFG_SET_ITEM(&wds_cfg, peer_ap_key_idx, core->slow_ctx->peerAPs_key_idx);

  res = mtlk_clpb_push(clpb, &res, sizeof(res));
  if (MTLK_ERR_OK == res) {
    res = mtlk_clpb_push(clpb, &wds_cfg, sizeof(wds_cfg));
  }

  return res;
}

static mtlk_error_t
_mtlk_core_get_wds_peer_ap (mtlk_handle_t hcore,
                            const void* data, uint32 data_size)
{
  mtlk_error_t res = MTLK_ERR_OK;
  mtlk_wds_cfg_t wds_cfg;
  mtlk_core_t *core = (mtlk_core_t*)hcore;
  mtlk_clpb_t *clpb = *(mtlk_clpb_t **) data;

  MTLK_ASSERT(sizeof(mtlk_clpb_t*) == data_size);

  memset(&wds_cfg, 0, sizeof(wds_cfg));

  MTLK_CFG_SET_ITEM_BY_FUNC(&wds_cfg, peer_ap_vect,
    mtlk_wds_get_peer_vect, (&core->slow_ctx->wds_mng, &wds_cfg.peer_ap_vect), res);

  res = mtlk_clpb_push(clpb, &res, sizeof(res));
  if (MTLK_ERR_OK == res) {
    res = mtlk_clpb_push(clpb, &wds_cfg, sizeof(wds_cfg));
  }

  return res;
}

static uint8
_mtlk_core_get_spectrum_mode(mtlk_core_t *core)
{
  wave_radio_t *radio = wave_vap_radio_get(core->vap_handle);
  if (mtlk_vap_is_ap(core->vap_handle)) {
    return WAVE_RADIO_PDB_GET_INT(radio, PARAM_DB_RADIO_SPECTRUM_MODE);
  }

  return MTLK_CORE_PDB_GET_INT(core, PARAM_DB_CORE_STA_FORCE_SPECTRUM_MODE);
}

static int
_mtlk_core_get_channel (mtlk_core_t *core)
{
  wave_radio_t *radio;
  MTLK_ASSERT(NULL != core);

  radio = wave_vap_radio_get(core->vap_handle);

  /* Retrieve PARAM_DB_RADIO_CHANNEL_CUR channel in case if there are active VAPs
   * Master VAP can be in NET_STATE_READY, but Slave VAP can be in NET_STATE_CONNECTED,
   * therefore PARAM_DB_RADIO_CHANNEL_CUR channel, belonged to Master VAP has correct value */
  if ((NET_STATE_CONNECTED == mtlk_core_get_net_state(core)) || (0 != mtlk_vap_manager_get_active_vaps_number(mtlk_vap_get_manager(core->vap_handle))))
    return WAVE_RADIO_PDB_GET_INT(radio, PARAM_DB_RADIO_CHANNEL_CUR);
  else
    return WAVE_RADIO_PDB_GET_INT(radio, PARAM_DB_RADIO_CHANNEL_CFG);
}

int __MTLK_IFUNC
mtlk_core_get_channel (mtlk_core_t *core)
{
  return _mtlk_core_get_channel(core);
}

static void
_mtlk_core_fill_channel_params (mtlk_core_t *core, mtlk_core_channel_def_t *ch_def)
{
  wave_radio_t *radio = wave_vap_radio_get(core->vap_handle);

  ch_def->channel = _mtlk_core_get_channel(core);
  ch_def->spectrum_mode = _mtlk_core_get_spectrum_mode(core);
  ch_def->bonding = WAVE_RADIO_PDB_GET_INT(radio, PARAM_DB_RADIO_BONDING_MODE);
}

static void
_mtlk_master_core_get_core_cfg (mtlk_core_t *core,
                         mtlk_gen_core_cfg_t* pCore_Cfg)
{
  wave_radio_t *radio = wave_vap_radio_get(core->vap_handle);

  MTLK_CFG_CHECK_AND_SET_ITEM(pCore_Cfg, dbg_sw_wd_enable, WAVE_RADIO_PDB_GET_INT(radio, PARAM_DB_RADIO_MAC_SOFT_RESET_ENABLE));
  MTLK_CFG_CHECK_AND_SET_ITEM(pCore_Cfg, frequency_band_cur, core_cfg_get_freq_band_cur(core));
  MTLK_CFG_CHECK_AND_SET_ITEM_BY_FUNC_VOID(pCore_Cfg, channel_def, _mtlk_core_fill_channel_params, (core, &pCore_Cfg->channel_def));
}

static void
_mtlk_slave_core_get_core_cfg (mtlk_core_t *core,
                         mtlk_gen_core_cfg_t* pCore_Cfg)
{
  _mtlk_master_core_get_core_cfg(mtlk_core_get_master(core->vap_handle), pCore_Cfg);
}

static uint32 __MTLK_IFUNC
_core_get_network_mode_current(mtlk_core_t *core)
{
    return core_cfg_get_network_mode_cur(core);
}

static mtlk_error_t
_mtlk_core_set_calibrate_on_demand (mtlk_handle_t hcore, const void* data, uint32 data_size)
{
  mtlk_error_t res = MTLK_ERR_OK;
  mtlk_temperature_sensor_t *temperature_cfg = NULL;
  uint32 temperature_cfg_size;
  mtlk_core_t *core = (mtlk_core_t*)hcore;
  mtlk_clpb_t *clpb = *(mtlk_clpb_t **) data;

  MTLK_ASSERT(sizeof(mtlk_clpb_t*) == data_size);

  temperature_cfg = mtlk_clpb_enum_get_next(clpb, &temperature_cfg_size);
  MTLK_CLPB_TRY(temperature_cfg, temperature_cfg_size)
    MTLK_CFG_SET_ITEM_BY_FUNC(temperature_cfg, temperature, mtlk_core_get_temperature_req,
                              (core, &temperature_cfg->temperature, temperature_cfg->calibrate_mask), res);
  MTLK_CLPB_FINALLY(res)
    return mtlk_clpb_push_res(clpb, res);
  MTLK_CLPB_END;
}

static mtlk_error_t
_mtlk_core_get_temperature (mtlk_handle_t hcore, const void* data, uint32 data_size)
{
  mtlk_error_t res = MTLK_ERR_OK;
  mtlk_temperature_sensor_t temperature_cfg = {0};
  mtlk_core_t *core = (mtlk_core_t*)hcore;
  mtlk_clpb_t *clpb = *(mtlk_clpb_t **) data;

  MTLK_ASSERT(sizeof(mtlk_clpb_t*) == data_size);

  MTLK_CFG_SET_ITEM_BY_FUNC(&temperature_cfg, temperature, mtlk_core_get_temperature_req,
                            (core, &temperature_cfg.temperature, 0), res);

  /* push result and config to clipboard*/
  res = mtlk_clpb_push(clpb, &res, sizeof(res));
  if (MTLK_ERR_OK == res) {
    res = mtlk_clpb_push(clpb, &temperature_cfg, sizeof(temperature_cfg));
  }

  return res;
}

static int
_mtlk_core_get_essid (mtlk_core_t *core, mtlk_gen_core_cfg_t* pcore_cfg)
{
  int res = MTLK_ERR_OK;
  mtlk_pdb_size_t str_size = sizeof(pcore_cfg->essid);

  /* Don't report ESSID to iw/iwconfig if we are not beaconing */
  if (core_cfg_is_connected(core)) {
    res = MTLK_CORE_PDB_GET_BINARY(core, PARAM_DB_CORE_ESSID, pcore_cfg->essid, &str_size);
  } else {
    pcore_cfg->essid[0] = '\0';
  }
  return res;
}

static int
_mtlk_core_get_core_cfg (mtlk_handle_t hcore,
                         const void* data, uint32 data_size)
{
  int res = MTLK_ERR_OK;
  mtlk_gen_core_cfg_t* pcore_cfg;
  mtlk_core_t *core = (mtlk_core_t*)hcore;
  mtlk_clpb_t *clpb = *(mtlk_clpb_t **) data;
  uint32 str_size, core_cfg_size;

  MTLK_ASSERT(sizeof(mtlk_clpb_t*) == data_size);

  pcore_cfg = mtlk_clpb_enum_get_next(clpb, &core_cfg_size);

  MTLK_CLPB_TRY(pcore_cfg, core_cfg_size)
    MTLK_CFG_CHECK_AND_SET_ITEM(pcore_cfg, bridge_mode,
                                MTLK_CORE_PDB_GET_INT(core, PARAM_DB_CORE_BRIDGE_MODE));
    MTLK_CFG_CHECK_AND_SET_ITEM(pcore_cfg, ap_forwarding,
                                MTLK_CORE_PDB_GET_INT(core, PARAM_DB_CORE_AP_FORWARDING));
    MTLK_CFG_CHECK_AND_SET_ITEM_BY_FUNC(pcore_cfg, reliable_multicast, mtlk_core_get_reliable_multicast,
                                        (core, &pcore_cfg->reliable_multicast), res);

    if (NET_STATE_CONNECTED == mtlk_core_get_net_state(core)) {
      MTLK_CFG_CHECK_AND_SET_ITEM_BY_FUNC_VOID(pcore_cfg, bssid, MTLK_CORE_PDB_GET_MAC, (core,
                                               PARAM_DB_CORE_BSSID, &pcore_cfg->bssid));
    } else {
      MTLK_CFG_CHECK_AND_SET_ITEM_BY_FUNC_VOID(pcore_cfg, bssid, ieee_addr_zero, (&pcore_cfg->bssid));
    }

    MTLK_CFG_CHECK_AND_SET_ITEM(pcore_cfg, net_mode, _core_get_network_mode_current(core));
    str_size = sizeof(pcore_cfg->nickname);
    MTLK_CFG_CHECK_AND_SET_ITEM_BY_FUNC(pcore_cfg, nickname, wave_pdb_get_string,
                                        (mtlk_vap_get_param_db(core->vap_handle),
                                        PARAM_DB_CORE_NICK_NAME,
                                        pcore_cfg->nickname, &str_size), res);
    MTLK_CFG_CHECK_AND_SET_ITEM_BY_FUNC(pcore_cfg, essid, _mtlk_core_get_essid, (core, pcore_cfg), res);
    MTLK_CFG_CHECK_AND_SET_ITEM_BY_FUNC(pcore_cfg, admission_capacity, mtlk_core_receive_admission_capacity,
                                        (core, &pcore_cfg->admission_capacity), res);
    MTLK_CFG_CHECK_AND_SET_ITEM_BY_FUNC(pcore_cfg, pcie_auto_cfg, wave_core_get_pcie_auto_gen_transition,
                                        (core, &pcore_cfg->pcie_auto_cfg), res);
    if (mtlk_vap_is_slave_ap(core->vap_handle)) {
      _mtlk_slave_core_get_core_cfg(core, pcore_cfg);
    } else {
      _mtlk_master_core_get_core_cfg(core, pcore_cfg);
    }
  MTLK_CLPB_FINALLY(res)
    return mtlk_clpb_push_res_data(clpb, res, pcore_cfg, sizeof(*pcore_cfg));
  MTLK_CLPB_END
}

static int _wave_core_network_mode_get (mtlk_handle_t hcore, const void* data, uint32 data_size)
{
  int res = MTLK_ERR_OK;
  wave_core_network_mode_cfg_t network_mode_cfg;
  mtlk_core_t *core = (mtlk_core_t*)hcore;
  mtlk_clpb_t *clpb = *(mtlk_clpb_t **) data;

  MTLK_ASSERT(sizeof(mtlk_clpb_t*) == data_size);

  /* read config from internal db */
  memset(&network_mode_cfg, 0, sizeof(network_mode_cfg));
  MTLK_CFG_SET_ITEM(&network_mode_cfg, net_mode, (uint8)_core_get_network_mode_current(core));

  /* push result and config to clipboard*/
  res = mtlk_clpb_push(clpb, &res, sizeof(res));
  if (MTLK_ERR_OK == res)
      res = mtlk_clpb_push(clpb, &network_mode_cfg, sizeof(network_mode_cfg));

  return res;
}

mtlk_error_t __MTLK_IFUNC
wave_core_get_bf_mode (mtlk_core_t *core, uint8 *bf_mode)
{
  mtlk_error_t res = MTLK_ERR_OK;
  wave_radio_t *radio = wave_vap_radio_get(core->vap_handle);

  *bf_mode = WAVE_RADIO_PDB_GET_INT(radio, PARAM_DB_RADIO_BF_MODE);

  if (MTLK_PARAM_DB_BF_MODE_IS_INVALID(*bf_mode)) {
    res = wave_core_receive_bf_mode(core, bf_mode);
    if (res == MTLK_ERR_OK) {
      WAVE_RADIO_PDB_SET_INT(radio, PARAM_DB_RADIO_BF_MODE, *bf_mode);
    }
  }

  return res;
}

static int
_mtlk_core_get_master_specific_cfg (mtlk_handle_t hcore,
                                    const void* data, uint32 data_size)
{
  int res = MTLK_ERR_OK;
  mtlk_core_t *core = (mtlk_core_t*)hcore;
  wave_radio_t *radio = wave_vap_radio_get(core->vap_handle);
  mtlk_clpb_t *clpb = *(mtlk_clpb_t **) data;

  mtlk_master_core_cfg_t *master_cfg = NULL;
  uint32 master_cfg_size;

  MTLK_ASSERT(sizeof(mtlk_clpb_t*) == data_size);

  master_cfg = mtlk_clpb_enum_get_next(clpb, &master_cfg_size);

  MTLK_CLPB_TRY(master_cfg, master_cfg_size)
  MTLK_CFG_CHECK_AND_SET_ITEM(master_cfg, acs_update_timeout, WAVE_RADIO_PDB_GET_INT(radio, PARAM_DB_RADIO_ACS_UPDATE_TO));
  MTLK_CFG_CHECK_AND_SET_ITEM_BY_FUNC(master_cfg, mu_operation, mtlk_core_receive_mu_operation, (core, &master_cfg->mu_operation), res);
  MTLK_CFG_CHECK_AND_SET_ITEM(master_cfg, probe_req_list_enabled, WAVE_RADIO_PDB_GET_INT(radio, PARAM_DB_RADIO_COLLECT_PROBE_REQ));
  MTLK_CFG_CHECK_AND_SET_ITEM(master_cfg, rts_mode_params.dynamic_bw, WAVE_RADIO_PDB_GET_INT(radio, PARAM_DB_RADIO_RTS_DYNAMIC_BW));
  MTLK_CFG_CHECK_AND_SET_ITEM_BY_FUNC(master_cfg, rts_mode_params, mtlk_core_receive_rts_mode, (core, &master_cfg->rts_mode_params), res);
  MTLK_CFG_CHECK_AND_SET_ITEM_BY_FUNC(master_cfg, bf_mode, wave_core_get_bf_mode, (core, &master_cfg->bf_mode), res);
  MTLK_CFG_CHECK_AND_SET_ITEM_BY_FUNC(master_cfg, txop_params, wave_core_cfg_receive_txop_params, (core, &master_cfg->txop_params), res);
  MTLK_CFG_CHECK_AND_SET_ITEM_BY_FUNC(master_cfg, active_ant_mask, mtlk_core_cfg_get_active_ant_mask, (core, &master_cfg->active_ant_mask), res);
  MTLK_CFG_CHECK_AND_SET_ITEM_BY_FUNC(master_cfg, fast_drop, mtlk_core_receive_fast_drop, (core, &master_cfg->fast_drop), res);

#ifdef WAVE_ENABLE_PIE
  MTLK_CFG_CHECK_AND_SET_ITEM_BY_FUNC(master_cfg, wave_pie_cfg, wave_core_pie_cfg_receive, (core, &master_cfg->wave_pie_cfg), res);
#endif /* WAVE_ENABLE_PIE */

  MTLK_CFG_CHECK_AND_SET_ITEM_BY_FUNC(master_cfg, slow_probing_mask, mtlk_core_receive_slow_probing_mask,
                                      (core, &master_cfg->slow_probing_mask), res);

  MTLK_CFG_CHECK_AND_SET_ITEM(master_cfg, unconnected_sta_scan_time,
                              WAVE_RADIO_PDB_GET_INT(radio, PARAM_DB_RADIO_UNCONNECTED_STA_SCAN_TIME));

#ifdef CONFIG_WAVE_DEBUG
  MTLK_CFG_CHECK_AND_SET_ITEM_BY_FUNC_VOID(master_cfg, fixed_pwr_params, _wave_radio_fixed_pwr_params_get,
                                           (radio, &master_cfg->fixed_pwr_params));
#endif
  MTLK_CFG_CHECK_AND_SET_ITEM(master_cfg, vw_test_mode, WAVE_RADIO_PDB_GET_INT(radio, PARAM_DB_RADIO_VW_TEST_MODE));

  MTLK_CLPB_FINALLY(res)
    return mtlk_clpb_push_res_data(clpb, res, master_cfg, sizeof(*master_cfg));
  MTLK_CLPB_END
}

static int
_mtlk_core_set_bridge_mode(mtlk_core_t *core, uint8 mode)
{
  uint8 mode_old;
  mtlk_vap_manager_t* vap_manager = mtlk_vap_get_manager(core->vap_handle);

  /* check for only allowed values */
  if (mode >= BR_MODE_LAST) {
    ELOG_DD("CID-%04x: Unsupported bridge mode %u", mtlk_vap_get_oid(core->vap_handle), mode);
    return MTLK_ERR_PARAMS;
  }

  /* Only NONE is allowed on master VAP */
  if (mtlk_vap_is_master(core->vap_handle) && (mode != BR_MODE_NONE)) {
    ELOG_DD("CID-%04x: Only bridge mode %u is allowed on master VAP",
            mtlk_vap_get_oid(core->vap_handle), BR_MODE_NONE);
    return MTLK_ERR_PARAMS;
  }

  /* on AP only NONE and WDS allowed */
  if (mtlk_vap_is_ap(core->vap_handle) && mode != BR_MODE_NONE && mode != BR_MODE_WDS) {
    ELOG_DD("CID-%04x: Unsupported (on AP) bridge mode %u", mtlk_vap_get_oid(core->vap_handle), mode);
    return MTLK_ERR_PARAMS;
  }

  mode_old = MTLK_CORE_PDB_GET_INT(core, PARAM_DB_CORE_BRIDGE_MODE);

  /* Nothing's changed */
  if (mode_old == mode)
    return MTLK_ERR_OK;

  MTLK_CORE_PDB_SET_INT(core, PARAM_DB_CORE_BRIDGE_MODE, mode);

  ILOG1_DD("CID-%04x: bridge_mode set to %u", mtlk_vap_get_oid(core->vap_handle), mode);

  if (mtlk_vap_is_ap(core->vap_handle)) {
    if (mode == BR_MODE_WDS){
      /* Enable WDS abilities */
      wds_enable_abilities(&core->slow_ctx->wds_mng);
      mtlk_vap_manager_inc_wds_bridgemode(vap_manager);
    } else {
      /* Disable WDS abilities */
      wds_disable_abilities(&core->slow_ctx->wds_mng);
    }
    if ((mode != BR_MODE_WDS) && (mode_old == BR_MODE_WDS)) {
      wds_switch_off(&core->slow_ctx->wds_mng);
      mtlk_vap_manager_dec_wds_bridgemode(vap_manager);
    }
  }

  return MTLK_ERR_OK;
}

static int
_mtlk_core_recovery_reliable_multicast (mtlk_core_t *core)
{
  uint8 flag = MTLK_CORE_PDB_GET_INT(core, PARAM_DB_CORE_RELIABLE_MCAST);

  if (MTLK_PARAM_DB_VALUE_IS_INVALID(flag))
    return MTLK_ERR_OK;

  return mtlk_core_set_reliable_multicast(core, flag);
}

static int
_mtlk_core_update_network_mode(mtlk_core_t *core, uint8 mode)
{
  if(mtlk_core_scan_is_running(core)) {
    ELOG_D("CID-%04x: Cannot set network mode while scan is running", mtlk_vap_get_oid(core->vap_handle));
    return MTLK_ERR_BUSY;
  }

  return mtlk_core_update_network_mode(core, mode);
}

static __INLINE int
_mtlk_core_set_nickname_by_cfg(mtlk_core_t *core, mtlk_gen_core_cfg_t *core_cfg)
{
  int res = wave_pdb_set_string(mtlk_vap_get_param_db(core->vap_handle),
                                PARAM_DB_CORE_NICK_NAME,
                                core_cfg->nickname);
  if (MTLK_ERR_OK == res) {
    ILOG2_DS("CID-%04x: Set NICKNAME to \"%s\"", mtlk_vap_get_oid(core->vap_handle),
        core_cfg->nickname);
  }
  return res;
}

int mtlk_core_set_essid_by_cfg(mtlk_core_t *core, mtlk_gen_core_cfg_t *core_cfg)
{
  u32 ap_short_ssid = 0;
  int res = MTLK_CORE_PDB_SET_BINARY(core, PARAM_DB_CORE_ESSID, core_cfg->essid, wave_strlen(core_cfg->essid, MAX_SSID_LEN));
  if (MTLK_ERR_OK != res) {
    ELOG_DD("CID-%04x: Can't store ESSID (err=%d)", mtlk_vap_get_oid(core->vap_handle), res);
  } else {
    ILOG2_DS("CID-%04x: Set ESSID to \"%s\"", mtlk_vap_get_oid(core->vap_handle), core_cfg->essid);
  }
  /* Compute short SSID and store it in Param DB for later use */
  ap_short_ssid = cpu_to_le32(ieee80211_crc32(core_cfg->essid, wave_strlen(core_cfg->essid, MAX_SSID_LEN)));
  wave_pdb_set_int(mtlk_vap_get_param_db(core->vap_handle), PARAM_DB_CORE_SHORT_SSID, ap_short_ssid);
  return res;
}

static mtlk_error_t
_mtlk_core_check_and_set_radio_mode (mtlk_core_t *core, uint32 radio_mode)
{
  int net_state;
  struct mtlk_chan_def *cd = __wave_core_chandef_get(core);
  wave_radio_t *radio = wave_vap_radio_get(core->vap_handle);

  if (mtlk_core_is_block_tx_mode(core)) {
    ILOG1_V("waiting for beacons");
    return MTLK_ERR_OK;
  }

  if (mtlk_core_scan_is_running(core) ||
      mtlk_core_is_in_scan_mode(core)) {
    ILOG1_V("scan is running");
    return MTLK_ERR_OK;
  }

  if (ST_RSSI == __wave_core_chan_switch_type_get(core)) {
    ILOG1_V("Is in ST_RSSI channel switch mode");
    return MTLK_ERR_OK;
  }

  net_state = mtlk_core_get_net_state(core);
  if (NET_STATE_ACTIVATING > net_state) {
    ILOG1_D("net state: %d", net_state);
    return MTLK_ERR_OK;
  }
  if (!is_channel_certain(cd)) {
    ILOG1_V("channel is not certain");
    return MTLK_ERR_OK;
  }

  if (radio_mode == WAVE_RADIO_PDB_GET_UINT(radio, PARAM_DB_RADIO_MODE_CURRENT)) {
    ILOG1_S("Radio already %s", radio_mode ? "ON" : "OFF");
    return MTLK_ERR_OK;
  }

  return mtlk_core_set_radio_mode_req(core, radio_mode);
}

static int
_mtlk_core_set_multi_ap_mode (mtlk_core_t *core, int new_multi_ap_mode)
{
  multi_ap_mode_t multi_ap_mode = MTLK_CORE_PDB_GET_INT(core, PARAM_DB_CORE_MULTI_AP_MODE);

  if (new_multi_ap_mode & ~MULTI_AP_SUPPORTED_MODES) {
    ELOG_D("Wrong multi_ap_mode provided %d", new_multi_ap_mode);
    return MTLK_ERR_VALUE;
  }

  if ((new_multi_ap_mode) && !mtlk_vap_is_ap(core->vap_handle)) {
    /* Multi-AP mode can be set only for AP */
    return MTLK_ERR_NOT_SUPPORTED;
  }

  if ((multi_ap_mode == MULTI_AP_BACKHAUL) && (new_multi_ap_mode != MULTI_AP_BACKHAUL)) {
    ILOG0_D("CID-%04x: switching back from MULTI_AP_BACKHAUL is not supported",
            mtlk_vap_get_oid(core->vap_handle));
    return MTLK_ERR_BUSY;
  }

  MTLK_CORE_PDB_SET_INT(core, PARAM_DB_CORE_MULTI_AP_MODE, new_multi_ap_mode);
  return MTLK_ERR_OK;
}

static int
_mtlk_core_set_mbssid_vap (mtlk_core_t *core, uint8 mbssid_vap)
{
  if (mbssid_vap > WAVE_RADIO_OPERATION_MODE_MBSSID_LAST) {
    ELOG_D("Wrong value (%d)", mbssid_vap);
    return MTLK_ERR_VALUE;
  }

  MTLK_CORE_PDB_SET_INT(core, PARAM_DB_CORE_MBSSID_VAP, mbssid_vap);
  return MTLK_ERR_OK;
}

static int
_mtlk_core_set_vaps_in_group (mtlk_core_t *core, uint8 vaps_in_group)
{
  if (vaps_in_group > HW_NUM_OF_VAPS) {
    ELOG_D("Wrong number of VAPs in group provided %d", vaps_in_group);
    return MTLK_ERR_VALUE;
  }

  MTLK_CORE_PDB_SET_INT(core, PARAM_DB_CORE_MBSSID_NUM_VAPS_IN_GROUP, vaps_in_group);
  return MTLK_ERR_OK;
}

static void
_wave_core_set_sb_timer_acl(mtlk_core_t *core, wave_core_sb_timer_acl_t *sb_timer_acl)
{
  MTLK_CORE_PDB_SET_INT(core, PARAM_DB_CORE_SB_TIMER_ACL_ON, sb_timer_acl->timer_acl_on);
  MTLK_CORE_PDB_SET_INT(core, PARAM_DB_CORE_SB_TIMER_ACL_PROBE_DROP, sb_timer_acl->timer_acl_probe_drop);
  ILOG2_DDD("CID-%04x: SB timer ACL: ON: %d, Probe Drop: %d",
           mtlk_vap_get_oid(core->vap_handle),
           sb_timer_acl->timer_acl_on,
           sb_timer_acl->timer_acl_probe_drop);
}

static int
_mtlk_core_set_offload_mode (mtlk_core_t *core, wave_offload_mode_t offload_mode)
{
  if (offload_mode < PROBEREQ_OFFLOAD_ON || offload_mode >= PROBEREQ_OFFLOAD_MODE_LAST) {
    ELOG_D("Wrong probe requests offload mode provided %d", offload_mode);
    return MTLK_ERR_VALUE;
  }

  MTLK_CORE_PDB_SET_INT(core, PARAM_DB_CORE_PROBEREQ_OFFLOAD_MODE, offload_mode);
  return MTLK_ERR_OK;
}

static int
_mtlk_core_set_core_cfg (mtlk_handle_t hcore,
                         const void* data, uint32 data_size)
{
  int res = MTLK_ERR_OK;
  mtlk_core_t *core = (mtlk_core_t*)hcore;
  mtlk_gen_core_cfg_t *core_cfg = NULL;
  uint32 core_cfg_size;
  mtlk_clpb_t *clpb = *(mtlk_clpb_t **) data;

  MTLK_ASSERT(sizeof(mtlk_clpb_t*) == data_size);

  core_cfg = mtlk_clpb_enum_get_next(clpb, &core_cfg_size);
  MTLK_CLPB_TRY(core_cfg, core_cfg_size)
  {
    MTLK_CFG_START_CHEK_ITEM_AND_CALL()

      MTLK_CFG_CHECK_ITEM_AND_CALL(core_cfg, bridge_mode, _mtlk_core_set_bridge_mode,
                                  (core, core_cfg->bridge_mode), res);
      MTLK_CFG_CHECK_ITEM_AND_CALL(core_cfg, reliable_multicast, mtlk_core_set_reliable_multicast,
                                  (core, !!core_cfg->reliable_multicast), res);

      MTLK_CFG_CHECK_ITEM_AND_CALL_VOID(core_cfg, ap_forwarding, MTLK_CORE_PDB_SET_INT,
                                        (core, PARAM_DB_CORE_AP_FORWARDING, !!core_cfg->ap_forwarding));

      MTLK_CFG_CHECK_ITEM_AND_CALL(core_cfg, net_mode, _mtlk_core_update_network_mode,
                                  (core, core_cfg->net_mode), res);

      MTLK_CFG_CHECK_ITEM_AND_CALL(core_cfg, nickname, _mtlk_core_set_nickname_by_cfg, (core, core_cfg), res);

      MTLK_CFG_CHECK_ITEM_AND_CALL(core_cfg, admission_capacity, mtlk_core_set_admission_capacity,
                                  (core, core_cfg->admission_capacity), res);

      MTLK_CFG_CHECK_ITEM_AND_CALL_VOID(core_cfg, bss_load, MTLK_CORE_PDB_SET_INT,
                                       (core, PARAM_DB_CORE_IS_BSS_LOAD_ENABLE, !!core_cfg->bss_load));

      MTLK_CFG_CHECK_ITEM_AND_CALL(core_cfg, multi_ap_mode, _mtlk_core_set_multi_ap_mode,
                                  (core, core_cfg->multi_ap_mode), res);

      MTLK_CFG_CHECK_ITEM_AND_CALL_VOID(core_cfg, softblock, MTLK_CORE_PDB_SET_INT,
                                       (core, PARAM_DB_CORE_SOFTBLOCK_DISABLE, !!core_cfg->softblock));

      MTLK_CFG_CHECK_ITEM_AND_CALL(core_cfg, mbssid_vap, _mtlk_core_set_mbssid_vap,
                                  (core, core_cfg->mbssid_vap), res);

      MTLK_CFG_CHECK_ITEM_AND_CALL(core_cfg, vaps_in_grp, _mtlk_core_set_vaps_in_group,
                                  (core, core_cfg->vaps_in_grp), res);

      MTLK_CFG_CHECK_ITEM_AND_CALL_VOID(core_cfg, mgmt_rate, _wave_core_management_frames_rate_set,
                                       (core, core_cfg->mgmt_rate));

      MTLK_CFG_CHECK_ITEM_AND_CALL_VOID(core_cfg, he_beacon, wave_core_set_he_beacon,
                                       (core, core_cfg->he_beacon));

      MTLK_CFG_CHECK_ITEM_AND_CALL_VOID(core_cfg, duplicate_beacon, wave_core_set_duplicate_beacon,
                                       (core, &core_cfg->duplicate_beacon));

      MTLK_CFG_CHECK_ITEM_AND_CALL_VOID(core_cfg, sb_timer_acl, _wave_core_set_sb_timer_acl,
                                       (core, &core_cfg->sb_timer_acl));

      MTLK_CFG_CHECK_ITEM_AND_CALL_VOID(core_cfg, intra_vap_mcast, MTLK_CORE_PDB_SET_INT,
                                        (core, PARAM_DB_CORE_INTRA_VAP_MCAST, !!core_cfg->intra_vap_mcast));

      MTLK_CFG_CHECK_ITEM_AND_CALL(core_cfg, probereq_offload_mode, _mtlk_core_set_offload_mode,
                                  (core, (wave_offload_mode_t)core_cfg->probereq_offload_mode), res);
      MTLK_CFG_CHECK_ITEM_AND_CALL(core_cfg, pcie_auto_cfg, wave_core_set_pcie_auto_gen_transition,
                                       (core, core_cfg->pcie_auto_cfg), res);
    MTLK_CFG_END_CHEK_ITEM_AND_CALL()
  }
  MTLK_CLPB_FINALLY(res)
    return mtlk_clpb_push_res(clpb, res);
  MTLK_CLPB_END;
}

mtlk_error_t __MTLK_IFUNC wave_core_send_bf_mode (mtlk_core_t *core, BeamformingMode_e bf_mode)
{
  MTLK_ASSERT(NULL != core);
  return  mtlk_core_send_bf_mode (core, bf_mode);
}

#define ACS_UPDATE_TIMEOUT_MAX (86400 * MTLK_OSAL_MSEC_IN_SEC) /* ms */

static int
_mtlk_core_set_acs_update_timeout (wave_radio_t *radio, uint32 acs_update_timeout)
{
  if (acs_update_timeout > ACS_UPDATE_TIMEOUT_MAX) {
    ELOG_DD("Incorrect ACS update timeout %u, must be 0..%u (0 - ACS update disabled)",
            acs_update_timeout, ACS_UPDATE_TIMEOUT_MAX);
    return MTLK_ERR_VALUE;
  }

  WAVE_RADIO_PDB_SET_INT(radio, PARAM_DB_RADIO_ACS_UPDATE_TO, acs_update_timeout);
  return MTLK_ERR_OK;
}

static int
_mtlk_core_set_probe_req_list_enabled (wave_radio_t *radio, uint32 probe_req_list_enabled)
{
  WAVE_RADIO_PDB_SET_INT(radio, PARAM_DB_RADIO_COLLECT_PROBE_REQ, probe_req_list_enabled);
  return MTLK_ERR_OK;
}

static void
_wave_core_set_dfs_debug (mtlk_core_t *core, uint8 dfs_debug)
{
  mtlk_scan_support_t *scan_support = mtlk_core_get_scan_support(core);
  scan_support->dfs_debug_params.debug_chan = dfs_debug;

  ILOG1_S("DFS debug channel requires radar detection: %s", dfs_debug ? "YES" : "NO");
}

static mtlk_error_t
_mtlk_core_set_master_specific_cfg (mtlk_handle_t hcore,
                                    const void* data, uint32 data_size)
{
  mtlk_error_t res = MTLK_ERR_OK;
  mtlk_core_t *core = (mtlk_core_t*)hcore;
  wave_radio_t *radio = wave_vap_radio_get(core->vap_handle);
  mtlk_master_core_cfg_t *master_cfg = NULL;
  uint32 master_cfg_size;
  mtlk_clpb_t *clpb = *(mtlk_clpb_t **) data;

  MTLK_ASSERT(sizeof(mtlk_clpb_t*) == data_size);

  master_cfg = mtlk_clpb_enum_get_next(clpb, &master_cfg_size);
  MTLK_CLPB_TRY(master_cfg, master_cfg_size)
  {
    MTLK_CFG_START_CHEK_ITEM_AND_CALL()

      MTLK_CFG_CHECK_ITEM_AND_CALL(master_cfg, acs_update_timeout, _mtlk_core_set_acs_update_timeout,
                                  (radio, master_cfg->acs_update_timeout), res);

      MTLK_CFG_CHECK_ITEM_AND_CALL(master_cfg, txop_params, wave_core_cfg_send_and_store_txop_params,
                                  (core, &master_cfg->txop_params), res);

      MTLK_CFG_CHECK_ITEM_AND_CALL(master_cfg, mu_operation, mtlk_core_set_mu_operation,
                                  (core, !!master_cfg->mu_operation), res);

      MTLK_CFG_CHECK_ITEM_AND_CALL(master_cfg, probe_req_list_enabled, _mtlk_core_set_probe_req_list_enabled,
                                  (radio, !!master_cfg->probe_req_list_enabled), res);

      MTLK_CFG_CHECK_ITEM_AND_CALL(master_cfg, rts_mode_params, mtlk_core_set_rts_mode,
                                  (core, !!master_cfg->rts_mode_params.dynamic_bw, !!master_cfg->rts_mode_params.static_bw), res);

      MTLK_CFG_CHECK_ITEM_AND_CALL(master_cfg, bf_mode, mtlk_core_send_bf_mode,
                                  (core, master_cfg->bf_mode), res);

      MTLK_CFG_CHECK_ITEM_AND_CALL(master_cfg, active_ant_mask, mtlk_core_cfg_send_active_ant_mask,
                                  (core, master_cfg->active_ant_mask), res);

      MTLK_CFG_CHECK_ITEM_AND_CALL(master_cfg, fast_drop, mtlk_core_cfg_set_fast_drop,
                                   (core, master_cfg->fast_drop), res);

#ifdef WAVE_ENABLE_PIE
      MTLK_CFG_CHECK_ITEM_AND_CALL(master_cfg, wave_pie_cfg, wave_core_pie_cfg_send,
                                  (core, &master_cfg->wave_pie_cfg), res);
#endif /* WAVE_ENABLE_PIE */

      MTLK_CFG_CHECK_ITEM_AND_CALL_VOID(master_cfg, dfs_debug, _wave_core_set_dfs_debug,
                                       (core, master_cfg->dfs_debug));

      MTLK_CFG_CHECK_ITEM_AND_CALL(master_cfg, slow_probing_mask, mtlk_core_cfg_send_slow_probing_mask,
                                  (core, master_cfg->slow_probing_mask), res);

      MTLK_CFG_CHECK_ITEM_AND_CALL(master_cfg, mu_group_config_params, wave_core_set_and_store_mu_group_cfg_params,
                                  (core, &master_cfg->mu_group_config_params), res);

      MTLK_CFG_CHECK_ITEM_AND_CALL_VOID(master_cfg, unconnected_sta_scan_time, WAVE_RADIO_PDB_SET_INT,
                                        (radio, PARAM_DB_RADIO_UNCONNECTED_STA_SCAN_TIME,
                                         master_cfg->unconnected_sta_scan_time));

      MTLK_CFG_CHECK_ITEM_AND_CALL(master_cfg, dynamic_wmm, wave_core_set_and_store_dynamic_wmm,
                                  (core, master_cfg->dynamic_wmm), res);

      MTLK_CFG_CHECK_ITEM_AND_CALL(master_cfg, dynamic_edca, wave_core_set_and_store_dynamic_edca,
                                  (core, master_cfg->dynamic_edca), res);

#ifdef CONFIG_WAVE_DEBUG
      MTLK_CFG_CHECK_ITEM_AND_CALL(master_cfg, fixed_pwr_params, mtlk_core_store_and_send_fixed_pwr_cfg,
                                  (core, &master_cfg->fixed_pwr_params), res);
#endif
      MTLK_CFG_CHECK_ITEM_AND_CALL(master_cfg, vw_test_mode, wave_core_set_vw_test_mode,
                                  (core, master_cfg->vw_test_mode), res);


    MTLK_CFG_END_CHEK_ITEM_AND_CALL()
  }
  MTLK_CLPB_FINALLY(res)
    return mtlk_clpb_push_res(clpb, res);
  MTLK_CLPB_END;
}

/*------ PHY_RX_STATUS -------*/

static int
_mtlk_core_get_phy_rx_status (mtlk_handle_t hcore, const void* data, uint32 data_size)
{
  mtlk_core_t      *core = HANDLE_T_PTR(mtlk_core_t, hcore);
  mtlk_clpb_t      *clpb = *(mtlk_clpb_t **) data;
  wave_bin_data_t  *phy_rx_status;
  uint32            size;
  int               res;

  MTLK_ASSERT(sizeof(mtlk_clpb_t*) == data_size);

  phy_rx_status = mtlk_clpb_enum_get_next(clpb, &size);
  MTLK_CLPB_TRY(phy_rx_status, size)
    res = mtlk_hw_copy_phy_rx_status(mtlk_vap_get_hw(core->vap_handle),
                                     phy_rx_status->buff, &phy_rx_status->size);
  MTLK_CLPB_FINALLY(res)
    return res;
  MTLK_CLPB_END;
}

static int
_mtlk_core_get_phy_channel_status (mtlk_handle_t hcore, const void* data, uint32 data_size)
{
  mtlk_core_t   *core = mtlk_core_get_master(((mtlk_core_t*)hcore)->vap_handle);
  wave_radio_t  *radio = wave_vap_radio_get(core->vap_handle);
  mtlk_clpb_t   *clpb = *(mtlk_clpb_t **) data;
  wave_radio_phy_stat_t radio_phy_stat;
  int res = MTLK_ERR_OK;

  wave_radio_phy_status_get(radio, &radio_phy_stat);

  return mtlk_clpb_push_res_data(clpb, res, &radio_phy_stat, sizeof(radio_phy_stat));
}

static mtlk_error_t
_mtlk_core_get_eeprom_cfg (mtlk_handle_t hcore,
                           const void* data, uint32 data_size)
{
  mtlk_error_t res = MTLK_ERR_OK;
  mtlk_eeprom_data_t *ee_data = NULL;
  mtlk_eeprom_cfg_t  *eeprom_cfg;
  mtlk_core_t *core = (mtlk_core_t*)hcore;
  mtlk_clpb_t *clpb = *(mtlk_clpb_t **) data;

  MTLK_ASSERT(sizeof(mtlk_clpb_t*) == data_size);

  ee_data = mtlk_core_get_eeprom(core);
  if (!ee_data) {
    ELOG_D("CID-%04x: Cant get EEPROM", mtlk_vap_get_oid(core->vap_handle));
    return MTLK_ERR_NO_ENTRY;
  }

  eeprom_cfg = mtlk_osal_mem_alloc(sizeof(mtlk_eeprom_cfg_t), MTLK_MEM_TAG_EEPROM);
  if(NULL == eeprom_cfg) {
    return MTLK_ERR_NO_MEM;
  }

  memset(eeprom_cfg, 0, sizeof(mtlk_eeprom_cfg_t));

  MTLK_CFG_SET_ITEM_BY_FUNC_VOID(eeprom_cfg, eeprom_data, mtlk_eeprom_get_cfg,
                                 (ee_data, &eeprom_cfg->eeprom_data));

  MTLK_CFG_SET_ITEM_BY_FUNC_VOID(eeprom_cfg, eeprom_raw_data, mtlk_eeprom_get_raw_data,
                                 (ee_data, eeprom_cfg));

  res = mtlk_clpb_push(clpb, &res, sizeof(res));
  if (MTLK_ERR_OK == res) {
    res = mtlk_clpb_push(clpb, eeprom_cfg, sizeof(mtlk_eeprom_cfg_t));
  }

  mtlk_osal_mem_free(eeprom_cfg);

  return res;
}

static int
_mtlk_core_emulate_radar_event (mtlk_handle_t hcore, iwpriv_emulate_params_t *emulate_params)
{
  int res, cur_channel = 0;
  mtlk_core_radar_emu_t radar_emu;
  mtlk_core_t *core = (mtlk_core_t*)hcore;
  struct mtlk_chan_def *ccd;

  if (emulate_params->dfs_band == ZWDFS_BAND) {
    if (!wave_radio_get_zwdfs_ant_enabled(wave_vap_radio_get(core->vap_handle))) {
      ELOG_V("Can not emulate radar as ZWDFS is not enabled");
      return MTLK_ERR_UNKNOWN;
    }
    else
      ccd = __wave_core_zwdfs_chandef_get(core);
  }
  else
    ccd = __wave_core_chandef_get(core);

  cur_channel = ieee80211_frequency_to_channel(ccd->chan.center_freq);
  if (!is_channel_certain(ccd)) {
    ELOG_V("Can not emulate radar, channel is not certain");
    return MTLK_ERR_UNKNOWN;
  }

  if (!cur_channel) {
    ELOG_D("Could not find channel for frequency %d", ccd->chan.center_freq);
    return MTLK_ERR_UNKNOWN;
  }

  memset(&radar_emu, 0, sizeof(radar_emu));
  radar_emu.radar_det.channel = cur_channel;
  radar_emu.radar_det.subBandBitmap = emulate_params->rbm;
  radar_emu.radar_det.dfsband = emulate_params->dfs_band;
  res = _wave_core_handle_radar_event(hcore, &radar_emu, sizeof(radar_emu));
  return res;
}

static int
_mtlk_core_radar_fifo_dump (mtlk_handle_t hcore, iwpriv_radar_fifo_params_t *radar_fifo_params)
{
  int res = MTLK_ERR_OK;
  mtlk_core_t *core = (mtlk_core_t*)hcore;
  wave_radio_t *radio;

  radio = wave_vap_radio_get(core->vap_handle);
  MTLK_ASSERT(radio);

  if (mtlk_vap_manager_vap_is_not_ready(mtlk_vap_get_manager(core->vap_handle), mtlk_vap_get_id(core->vap_handle))) {
    ELOG_V("Interface is not enabled");
    return MTLK_ERR_NOT_READY;
  }

  if (mtlk_vap_is_slave_ap(core->vap_handle)) {
    return MTLK_ERR_PARAMS;
  }

  if ((radar_fifo_params->dfs_band && !wave_radio_get_zwdfs_ant_enabled(wave_vap_radio_get(core->vap_handle)))) {
    ELOG_V("ZWDFS antenna is not enabled");
    return MTLK_ERR_NOT_READY;
  }

  WAVE_RADIO_PDB_SET_INT(radio, PARAM_DB_RADAR_FIFO_DUMP, radar_fifo_params->enable_dump);
  if (radar_fifo_params->enable_dump && radar_fifo_params->immediate) {
    res = mtlk_radar_pulses_fifo_dump(hcore, radar_fifo_params->dfs_band);
  }
  return res;
}

static mtlk_error_t
_mtlk_core_set_scan_and_calib_cfg (mtlk_handle_t hcore, const void* data, uint32 data_size)
{
  mtlk_error_t res = MTLK_ERR_OK;
  mtlk_core_t *core = (mtlk_core_t*)hcore;
  wave_radio_t *radio = wave_vap_radio_get(core->vap_handle);

  mtlk_scan_and_calib_cfg_t *scan_and_calib_cfg;
  uint32 clpb_data_size;
  mtlk_clpb_t *clpb = *(mtlk_clpb_t **) data;

  MTLK_ASSERT(sizeof(mtlk_clpb_t*) == data_size);

  scan_and_calib_cfg = mtlk_clpb_enum_get_next(clpb, &clpb_data_size);
  MTLK_CLPB_TRY(scan_and_calib_cfg, clpb_data_size)
    MTLK_CFG_START_CHEK_ITEM_AND_CALL()
      MTLK_CFG_CHECK_ITEM_AND_CALL(scan_and_calib_cfg, emulate_params, _mtlk_core_emulate_radar_event,
                                   (hcore, &scan_and_calib_cfg->emulate_params), res);
      MTLK_CFG_CHECK_ITEM_AND_CALL(scan_and_calib_cfg, radar_fifo_params, _mtlk_core_radar_fifo_dump,
                                   (hcore, &scan_and_calib_cfg->radar_fifo_params), res);
      MTLK_CFG_CHECK_ITEM_AND_CALL(scan_and_calib_cfg, radar_detect, mtlk_core_set_radar_detect,
                                   (core, !!scan_and_calib_cfg->radar_detect), res);
      MTLK_CFG_CHECK_ITEM_AND_CALL_VOID(scan_and_calib_cfg, scan_modifs, WAVE_RADIO_PDB_SET_INT,
                                        (radio, PARAM_DB_RADIO_SCAN_MODIFS, scan_and_calib_cfg->scan_modifs));
      MTLK_CFG_CHECK_ITEM_AND_CALL_VOID(scan_and_calib_cfg, scan_pause_bg_cache, WAVE_RADIO_PDB_SET_INT,
                                        (radio, PARAM_DB_RADIO_SCAN_PAUSE_BG_CACHE, scan_and_calib_cfg->scan_pause_bg_cache));
#ifdef CONFIG_WAVE_DEBUG
      MTLK_CFG_CHECK_ITEM_AND_CALL_VOID(scan_and_calib_cfg, scan_expire_time, wv_cfg80211_set_scan_expire_time,
                                        (mtlk_core_get_wdev(core->vap_handle),
                                        scan_and_calib_cfg->scan_expire_time));
#endif
      MTLK_CFG_CHECK_ITEM_AND_CALL(scan_and_calib_cfg, scan_params, WAVE_RADIO_PDB_SET_BINARY,
                                  (radio, PARAM_DB_RADIO_SCAN_PARAMS, &scan_and_calib_cfg->scan_params,
                                   sizeof(iwpriv_scan_params_t)), res);
      MTLK_CFG_CHECK_ITEM_AND_CALL(scan_and_calib_cfg, scan_params_bg, WAVE_RADIO_PDB_SET_BINARY,
                                  (radio, PARAM_DB_RADIO_SCAN_PARAMS_BG, &scan_and_calib_cfg->scan_params_bg,
                                   sizeof(iwpriv_scan_params_bg_t)), res);
      MTLK_CFG_CHECK_ITEM_AND_CALL_VOID(scan_and_calib_cfg, out_of_scan_cache, wv_cfg80211_set_out_of_scan_caching,
                                        (mtlk_core_get_wdev(core->vap_handle),
                                        scan_and_calib_cfg->out_of_scan_cache));
    MTLK_CFG_END_CHEK_ITEM_AND_CALL()
  MTLK_CLPB_FINALLY(res)
    return mtlk_clpb_push_res(clpb, res);
  MTLK_CLPB_END
}

static mtlk_error_t
_mtlk_core_get_scan_and_calib_cfg (mtlk_handle_t hcore, const void* data, uint32 data_size)
{
  mtlk_error_t res = MTLK_ERR_OK;
  mtlk_pdb_size_t scan_params_size = sizeof(iwpriv_scan_params_t);
  mtlk_pdb_size_t scan_params_bg_size = sizeof(iwpriv_scan_params_bg_t);
  mtlk_core_t *core = (mtlk_core_t*)hcore;
  wave_radio_t *radio = wave_vap_radio_get(core->vap_handle);
  mtlk_scan_and_calib_cfg_t scan_and_calib_cfg;
  mtlk_clpb_t *clpb = *(mtlk_clpb_t **) data;

  MTLK_ASSERT(sizeof(mtlk_clpb_t*) == data_size);

  memset(&scan_and_calib_cfg, 0, sizeof(scan_and_calib_cfg));

  MTLK_CFG_SET_ITEM(&scan_and_calib_cfg, radar_detect, WAVE_RADIO_PDB_GET_INT(radio, PARAM_DB_RADIO_DFS_RADAR_DETECTION));
  MTLK_CFG_SET_ITEM(&scan_and_calib_cfg, scan_modifs, WAVE_RADIO_PDB_GET_INT(radio, PARAM_DB_RADIO_SCAN_MODIFS));
  MTLK_CFG_SET_ITEM(&scan_and_calib_cfg, scan_pause_bg_cache, WAVE_RADIO_PDB_GET_INT(radio, PARAM_DB_RADIO_SCAN_PAUSE_BG_CACHE));

#ifdef CONFIG_WAVE_DEBUG
  if (mtlk_vap_is_ap(core->vap_handle)){
    MTLK_CFG_SET_ITEM(&scan_and_calib_cfg, scan_expire_time,
                     wv_cfg80211_get_scan_expire_time(mtlk_core_get_wdev(core->vap_handle)));
  }
#endif
  MTLK_CFG_SET_ITEM_BY_FUNC(&scan_and_calib_cfg, scan_params, WAVE_RADIO_PDB_GET_BINARY,
                            (radio, PARAM_DB_RADIO_SCAN_PARAMS, &scan_and_calib_cfg.scan_params,
                            &scan_params_size), res);
  MTLK_CFG_SET_ITEM_BY_FUNC(&scan_and_calib_cfg, scan_params_bg, WAVE_RADIO_PDB_GET_BINARY,
                            (radio, PARAM_DB_RADIO_SCAN_PARAMS_BG, &scan_and_calib_cfg.scan_params_bg,
                            &scan_params_bg_size), res);
  MTLK_CFG_SET_ITEM(&scan_and_calib_cfg, out_of_scan_cache,
                    wv_cfg80211_get_out_of_scan_caching(mtlk_core_get_wdev(core->vap_handle)));
  res = mtlk_clpb_push(clpb, &res, sizeof(res));
  if (MTLK_ERR_OK == res)
    res = mtlk_clpb_push(clpb, &scan_and_calib_cfg, sizeof(scan_and_calib_cfg));

  return res;
}

static mtlk_error_t
_mtlk_core_get_allow_scan_during_cac (mtlk_handle_t hcore, const void* data, uint32 data_size)
{
  mtlk_error_t res = MTLK_ERR_OK;
  mtlk_scan_during_cac_cfg_t _scan_in_cac_cfg;
  mtlk_core_t *core = (mtlk_core_t*)hcore;
  mtlk_clpb_t *clpb = *(mtlk_clpb_t **) data;

  MTLK_ASSERT(sizeof(mtlk_clpb_t*) == data_size);

  memset(&_scan_in_cac_cfg, 0, sizeof(_scan_in_cac_cfg));

  MTLK_CFG_SET_ITEM(&_scan_in_cac_cfg, allow,
                    wv_cfg80211_get_allow_scan_during_cac(mtlk_core_get_wdev(core->vap_handle)));

  res = mtlk_clpb_push(clpb, &res, sizeof(res));
  if (MTLK_ERR_OK == res) {
    res = mtlk_clpb_push(clpb, &_scan_in_cac_cfg, sizeof(_scan_in_cac_cfg));
  }
  return res;

}

static int
_mtlk_core_set_allow_scan_during_cac (mtlk_handle_t hcore, const void* data, uint32 data_size)
{
  int res = MTLK_ERR_OK;
  mtlk_scan_during_cac_cfg_t *_scan_in_cac_cfg = NULL;
  mtlk_core_t *core = (mtlk_core_t*)hcore;
  mtlk_clpb_t *clpb = *(mtlk_clpb_t **) data;
  uint32 scan_in_cac_cfg_size;

  MTLK_ASSERT(sizeof(mtlk_clpb_t*) == data_size);
  MTLK_ASSERT(!mtlk_vap_is_slave_ap(core->vap_handle));

  _scan_in_cac_cfg = mtlk_clpb_enum_get_next(clpb, &scan_in_cac_cfg_size);
  MTLK_CLPB_TRY(_scan_in_cac_cfg, scan_in_cac_cfg_size)
  {
    MTLK_CFG_START_CHEK_ITEM_AND_CALL()
      MTLK_CFG_CHECK_ITEM_AND_CALL_VOID(_scan_in_cac_cfg, allow, wv_cfg80211_set_allow_scan_during_cac,
                                        (mtlk_core_get_wdev(core->vap_handle),
                                        _scan_in_cac_cfg->allow));
    MTLK_CFG_END_CHEK_ITEM_AND_CALL()
  }
  MTLK_CLPB_FINALLY(res)
    return mtlk_clpb_push_res(clpb, res);
  MTLK_CLPB_END;

}

static mtlk_error_t
_mtlk_core_get_coc_power_params (mtlk_core_t *core, mtlk_coc_power_cfg_t *power_params)
{
  MTLK_ASSERT(core != NULL);

  return wave_coc_get_current_power_params(__wave_core_coc_mgmt_get(core), power_params);
}

static unsigned
_mtlk_core_get_current_tx_antennas (mtlk_core_t *core)
{
  mtlk_coc_antenna_cfg_t *current_params;
  mtlk_coc_t *coc_mgmt = __wave_core_coc_mgmt_get(core);

  MTLK_ASSERT(core != NULL);

  current_params = mtlk_coc_get_current_params(coc_mgmt);

  return current_params->num_tx_antennas;
}

static int
_mtlk_core_get_coc_auto_params (mtlk_core_t *core, mtlk_coc_auto_cfg_t *auto_params)
{
  mtlk_coc_auto_cfg_t *configured_params;
  mtlk_coc_t *coc_mgmt = __wave_core_coc_mgmt_get(core);

  MTLK_ASSERT(core != NULL);
  MTLK_ASSERT(auto_params != NULL);

  configured_params = mtlk_coc_get_auto_params(coc_mgmt);
  *auto_params = *configured_params;

  return MTLK_ERR_OK;
}

static mtlk_error_t
_mtlk_core_get_coc_cfg (mtlk_handle_t hcore, const void* data, uint32 data_size)
{
  mtlk_error_t res = MTLK_ERR_OK;
  mtlk_coc_mode_cfg_t coc_cfg;
  mtlk_core_t *core = (mtlk_core_t*)hcore;
  wave_radio_t *radio;
  mtlk_clpb_t *clpb = *(mtlk_clpb_t **) data;

  MTLK_ASSERT(sizeof(mtlk_clpb_t*) == data_size);
  MTLK_ASSERT(!mtlk_vap_is_slave_ap(core->vap_handle));

  radio = wave_vap_radio_get(core->vap_handle);
  MTLK_ASSERT(radio);

  memset(&coc_cfg, 0, sizeof(coc_cfg));

  MTLK_CFG_SET_ITEM_BY_FUNC(&coc_cfg, power_params,
                            _mtlk_core_get_coc_power_params, (core, &coc_cfg.power_params), res);
  MTLK_CFG_SET_ITEM_BY_FUNC(&coc_cfg, auto_params,
                            _mtlk_core_get_coc_auto_params, (core, &coc_cfg.auto_params), res);
  MTLK_CFG_SET_ITEM(&coc_cfg, cur_ant_mask, wave_radio_current_antenna_mask_get(radio));
  MTLK_CFG_SET_ITEM(&coc_cfg, hw_ant_mask,  wave_radio_rx_antenna_mask_get(radio));

  res = mtlk_clpb_push(clpb, &res, sizeof(res));
  if (MTLK_ERR_OK == res) {
    res = mtlk_clpb_push(clpb, &coc_cfg, sizeof(coc_cfg));
  }
  return res;
}

static int
_mtlk_core_set_coc_power_mode (mtlk_core_t *core, BOOL is_auto_mode)
{
  int res = MTLK_ERR_OK;
  mtlk_coc_t *coc_mgmt = __wave_core_coc_mgmt_get(core);
  res = mtlk_coc_set_power_mode(coc_mgmt, is_auto_mode);
  return res;
}

int __MTLK_IFUNC
mtlk_core_set_coc_actual_power_mode(mtlk_core_t *core)
{
  mtlk_coc_t *coc_mgmt = __wave_core_coc_mgmt_get(core);
  return mtlk_coc_set_actual_power_mode(coc_mgmt);
}

int __MTLK_IFUNC
mtlk_core_set_coc_pause_power_mode (mtlk_core_t *core)
{
  mtlk_coc_t *coc_mgmt = __wave_core_coc_mgmt_get(core);
  return mtlk_coc_set_pause_power_mode(coc_mgmt);
}

mtlk_error_t __MTLK_IFUNC
wave_core_set_coc_power_params (mtlk_core_t *core, mtlk_coc_power_cfg_t *power_params)
{
  mtlk_error_t res;
  struct intel_vendor_event_coc  bw_params;
  uint8 current_state, new_state;
  wave_radio_t *radio = NULL;
  MTLK_ASSERT(core != NULL);

  current_state = mtlk_coc_get_current_tx_antennas (__wave_core_coc_mgmt_get(core));
  new_state = power_params->antenna_params.num_tx_antennas;
  radio = wave_vap_radio_get(core->vap_handle);
  memset(&bw_params, 0, sizeof(bw_params));
  bw_params.coc_BW = power_params->bw_params.coc_BW;
  bw_params.coc_omn_IE = new_state;
  if (((0 != bw_params.coc_BW) || (current_state != new_state)) && (power_params->is_auto_mode != 1)) {
    struct wireless_dev *wdev = mtlk_core_get_wdev(core->vap_handle);
    MTLK_ASSERT(wdev != NULL);
    res = wv_ieee80211_vendor_event_coc(LTQ_NL80211_VENDOR_EVENT_COC_BEACON_UPDATE, wdev, &bw_params, sizeof(bw_params));
  }

  if ((power_params->is_auto_mode == 0) && (power_params->antenna_params.num_tx_antennas == 0) &&
      (power_params->antenna_params.num_rx_antennas == 0)) {
    power_params->antenna_params.num_tx_antennas = mtlk_core_get_max_tx_antennas(core);
    power_params->antenna_params.num_rx_antennas = mtlk_core_get_max_rx_antennas(core);
   }

   res = wave_coc_set_power_params(__wave_core_coc_mgmt_get(core), power_params); /* except auto_mode */
   if (MTLK_ERR_OK == res) {
     res = _mtlk_core_set_coc_power_mode(core, power_params->is_auto_mode);
   }

  return res;
}

static int
_mtlk_core_set_auto_params (mtlk_core_t *core, mtlk_coc_auto_cfg_t *auto_params)
{
  int res = MTLK_ERR_OK;
  mtlk_coc_t *coc_mgmt = __wave_core_coc_mgmt_get(core);
  res = mtlk_coc_set_auto_params(coc_mgmt, auto_params);
  return res;
}

static mtlk_error_t
_mtlk_core_set_coc_cfg (mtlk_handle_t hcore, const void* data, uint32 data_size)
{
  mtlk_error_t res = MTLK_ERR_OK;
  mtlk_core_t *core = (mtlk_core_t*)hcore;
  mtlk_coc_mode_cfg_t *coc_cfg = NULL;
  uint32 coc_cfg_size;
  mtlk_clpb_t *clpb = *(mtlk_clpb_t **) data;

  MTLK_ASSERT(sizeof(mtlk_clpb_t*) == data_size);

  coc_cfg = mtlk_clpb_enum_get_next(clpb, &coc_cfg_size);
  MTLK_CLPB_TRY(coc_cfg, coc_cfg_size)
    MTLK_CFG_START_CHEK_ITEM_AND_CALL()
      MTLK_CFG_CHECK_ITEM_AND_CALL(coc_cfg, auto_params, _mtlk_core_set_auto_params,
                                   (core, &coc_cfg->auto_params), res);
      MTLK_CFG_CHECK_ITEM_AND_CALL(coc_cfg, power_params, wave_core_set_coc_power_params,
                                   (core, &coc_cfg->power_params), res);
    MTLK_CFG_END_CHEK_ITEM_AND_CALL()
  MTLK_CLPB_FINALLY(res)
    return mtlk_clpb_push_res(clpb, res);
  MTLK_CLPB_END
}

/************* Dynamic Multicast Rate*******************/

static void
_mtlk_core_read_multicast_rate (mtlk_core_t *core, mtlk_multicast_rate_cfg_t *multicast_rate_cfg)
{
    wave_radio_t *radio;
    MTLK_ASSERT(core != NULL);
    MTLK_ASSERT(multicast_rate_cfg != NULL);
    radio = wave_vap_radio_get(core->vap_handle);

    multicast_rate_cfg->multicast_rate.mode    = (uint8) WAVE_RADIO_PDB_GET_INT(radio, PARAM_DB_RADIO_DYNAMIC_MC_RATE_MODE);
    multicast_rate_cfg->multicast_rate.maxRate = (uint8) WAVE_RADIO_PDB_GET_INT(radio, PARAM_DB_RADIO_DYNAMIC_MC_RATE_MAXRATE);
}

static void
_mtlk_core_store_multicast_rate (mtlk_core_t *core, const mtlk_multicast_rate_cfg_t *multicast_rate_cfg)
{
    wave_radio_t *radio;
    MTLK_ASSERT(core != NULL);
    MTLK_ASSERT(multicast_rate_cfg!= NULL);
    radio = wave_vap_radio_get(core->vap_handle);

    WAVE_RADIO_PDB_SET_INT(radio, PARAM_DB_RADIO_DYNAMIC_MC_RATE_MODE, multicast_rate_cfg->multicast_rate.mode);
    WAVE_RADIO_PDB_SET_INT(radio, PARAM_DB_RADIO_DYNAMIC_MC_RATE_MAXRATE, multicast_rate_cfg->multicast_rate.maxRate);
}

static int
_wave_core_set_multicast_rate (mtlk_handle_t hcore, const void* data, uint32 data_size)
{
    int res = MTLK_ERR_OK;
    mtlk_core_t *core = (mtlk_core_t *) hcore;

    mtlk_multicast_rate_cfg_t *multicast_rate_cfg = NULL;
    uint32 multicast_rate_cfg_size;
    mtlk_clpb_t *clpb = *(mtlk_clpb_t **) data;

    MTLK_ASSERT(sizeof(mtlk_clpb_t*) == data_size);

    /* get configuration */
    multicast_rate_cfg = mtlk_clpb_enum_get_next(clpb, &multicast_rate_cfg_size);
    MTLK_CLPB_TRY(multicast_rate_cfg, multicast_rate_cfg_size)
      MTLK_CFG_START_CHEK_ITEM_AND_CALL()
        /* send new config to FW */
        MTLK_CFG_CHECK_ITEM_AND_CALL(multicast_rate_cfg, multicast_rate, wave_core_send_multicast_rate,
                                     (core, multicast_rate_cfg), res);
        /* store new config in internal db*/
        MTLK_CFG_CHECK_ITEM_AND_CALL_VOID(multicast_rate_cfg, multicast_rate, _mtlk_core_store_multicast_rate,
                                          (core, multicast_rate_cfg));
      MTLK_CFG_END_CHEK_ITEM_AND_CALL()
    MTLK_CLPB_FINALLY(res)
      /* push result into clipboard */
      return mtlk_clpb_push_res(clpb, res);
    MTLK_CLPB_END
}

/************* MU OFDMA Beamforming *******************/

static int _mtlk_core_receive_mu_ofdma_bf (mtlk_core_t *core, mtlk_mu_ofdma_bf_req_cfg_t *mu_ofdma_bf_cfg)
{
  int res = MTLK_ERR_OK;
  wave_radio_t *radio = wave_vap_radio_get(core->vap_handle);

  mu_ofdma_bf_cfg->mode     =  (uint8) WAVE_RADIO_PDB_GET_INT(radio, PARAM_DB_RADIO_MU_OFDMA_BF_MODE);
  mu_ofdma_bf_cfg->bfPeriod = (uint32) WAVE_RADIO_PDB_GET_INT(radio, PARAM_DB_RADIO_MU_OFDMA_BF_PERIOD);

  if(MTLK_PARAM_DB_VALUE_IS_INVALID(mu_ofdma_bf_cfg->mode)) {
    res = wave_core_receive_mu_ofdma_bf (core, mu_ofdma_bf_cfg);

    if (res == MTLK_ERR_OK) {
      WAVE_RADIO_PDB_SET_INT(radio, PARAM_DB_RADIO_MU_OFDMA_BF_MODE, mu_ofdma_bf_cfg->mode);
      WAVE_RADIO_PDB_SET_INT(radio, PARAM_DB_RADIO_MU_OFDMA_BF_PERIOD, mu_ofdma_bf_cfg->bfPeriod);
    }
  }
  return res;
}

static void
_mtlk_core_read_mu_ofdma_bf (mtlk_core_t *core, mtlk_mu_ofdma_bf_cfg_t *mu_ofdma_bf_cfg)
{
    wave_radio_t *radio;
    MTLK_ASSERT(core != NULL);
    MTLK_ASSERT(mu_ofdma_bf_cfg != NULL);
    radio = wave_vap_radio_get(core->vap_handle);

    mu_ofdma_bf_cfg->mu_ofdma_bf.mode     =  (uint8) WAVE_RADIO_PDB_GET_INT(radio, PARAM_DB_RADIO_MU_OFDMA_BF_MODE);
    mu_ofdma_bf_cfg->mu_ofdma_bf.bfPeriod = (uint32) WAVE_RADIO_PDB_GET_INT(radio, PARAM_DB_RADIO_MU_OFDMA_BF_PERIOD);
}

static void
_mtlk_core_store_mu_ofdma_bf (mtlk_core_t *core, const mtlk_mu_ofdma_bf_cfg_t *mu_ofdma_bf_cfg)
{
    wave_radio_t *radio;
    MTLK_ASSERT(core != NULL);
    MTLK_ASSERT(mu_ofdma_bf_cfg!= NULL);
    radio = wave_vap_radio_get(core->vap_handle);

    WAVE_RADIO_PDB_SET_INT(radio, PARAM_DB_RADIO_MU_OFDMA_BF_MODE, mu_ofdma_bf_cfg->mu_ofdma_bf.mode);
    WAVE_RADIO_PDB_SET_INT(radio, PARAM_DB_RADIO_MU_OFDMA_BF_PERIOD, mu_ofdma_bf_cfg->mu_ofdma_bf.bfPeriod);
}

static mtlk_error_t
_wave_core_set_mu_ofdma_bf (mtlk_handle_t hcore, const void* data, uint32 data_size)
{
    mtlk_error_t res = MTLK_ERR_OK;
    mtlk_core_t *core = (mtlk_core_t *) hcore;

    mtlk_mu_ofdma_bf_cfg_t *mu_ofdma_bf_cfg = NULL;
    uint32 mu_ofdma_bf_cfg_size;
    mtlk_clpb_t *clpb = *(mtlk_clpb_t **) data;

    MTLK_ASSERT(sizeof(mtlk_clpb_t*) == data_size);

    /* get configuration */
    mu_ofdma_bf_cfg = mtlk_clpb_enum_get_next(clpb, &mu_ofdma_bf_cfg_size);
    MTLK_CLPB_TRY(mu_ofdma_bf_cfg, mu_ofdma_bf_cfg_size)
      MTLK_CFG_START_CHEK_ITEM_AND_CALL()
        /* send new config to FW */
        MTLK_CFG_CHECK_ITEM_AND_CALL(mu_ofdma_bf_cfg, mu_ofdma_bf, wave_core_send_mu_ofdma_bf,
                                     (core, mu_ofdma_bf_cfg), res);
        /* store new config in internal db*/
        MTLK_CFG_CHECK_ITEM_AND_CALL_VOID(mu_ofdma_bf_cfg, mu_ofdma_bf, _mtlk_core_store_mu_ofdma_bf,
                                          (core, mu_ofdma_bf_cfg));
      MTLK_CFG_END_CHEK_ITEM_AND_CALL()
    MTLK_CLPB_FINALLY(res)
      /* push result into clipboard */
      return mtlk_clpb_push_res(clpb, res);
    MTLK_CLPB_END
}

static int
_wave_core_get_mu_ofdma_bf (mtlk_handle_t hcore, const void* data, uint32 data_size)
{
    int res = MTLK_ERR_OK;
    mtlk_mu_ofdma_bf_cfg_t mu_ofdma_bf_cfg;
    mtlk_core_t *core = (mtlk_core_t*)hcore;
    mtlk_clpb_t *clpb = *(mtlk_clpb_t **) data;

    MTLK_ASSERT(sizeof(mtlk_clpb_t*) == data_size);

    /* read config from internal db */
    memset(&mu_ofdma_bf_cfg, 0, sizeof(mu_ofdma_bf_cfg));
    MTLK_CFG_SET_ITEM_BY_FUNC(&mu_ofdma_bf_cfg, mu_ofdma_bf, _mtlk_core_receive_mu_ofdma_bf,
                              (core, &mu_ofdma_bf_cfg.mu_ofdma_bf), res)

    /* push result and config to clipboard*/
    res = mtlk_clpb_push(clpb, &res, sizeof(res));
    if (MTLK_ERR_OK == res) {
        res = mtlk_clpb_push(clpb, &mu_ofdma_bf_cfg, sizeof(mu_ofdma_bf_cfg));
    }

    return res;
}

/************* AGG rate limit *******************/

static void
_mtlk_core_read_agg_rate_limit (mtlk_core_t *core, mtlk_agg_rate_limit_cfg_t *agg_rate_cfg)
{
    wave_radio_t *radio;
    MTLK_ASSERT(core != NULL);
    MTLK_ASSERT(agg_rate_cfg != NULL);
    radio = wave_vap_radio_get(core->vap_handle);

    agg_rate_cfg->agg_rate_limit.mode    = (uint8)  WAVE_RADIO_PDB_GET_INT(radio, PARAM_DB_RADIO_AGG_RATE_LIMIT_MODE);
    agg_rate_cfg->agg_rate_limit.maxRate = (uint16) WAVE_RADIO_PDB_GET_INT(radio, PARAM_DB_RADIO_AGG_RATE_LIMIT_MAXRATE);
}

static void
_mtlk_core_store_agg_rate_limit (mtlk_core_t *core, const mtlk_agg_rate_limit_cfg_t *agg_rate_cfg)
{
    wave_radio_t *radio;
    MTLK_ASSERT(core != NULL);
    MTLK_ASSERT(agg_rate_cfg != NULL);
    radio = wave_vap_radio_get(core->vap_handle);

    WAVE_RADIO_PDB_SET_INT(radio, PARAM_DB_RADIO_AGG_RATE_LIMIT_MODE, agg_rate_cfg->agg_rate_limit.mode);
    WAVE_RADIO_PDB_SET_INT(radio, PARAM_DB_RADIO_AGG_RATE_LIMIT_MAXRATE, agg_rate_cfg->agg_rate_limit.maxRate);
}

static int
_mtlk_core_set_agg_rate_limit (mtlk_handle_t hcore, const void* data, uint32 data_size)
{
    int res = MTLK_ERR_OK;
    mtlk_core_t *core = (mtlk_core_t *) hcore;

    mtlk_agg_rate_limit_cfg_t *agg_cfg = NULL;
    uint32 agg_cfg_size;
    mtlk_clpb_t *clpb = *(mtlk_clpb_t **) data;

    MTLK_ASSERT(sizeof(mtlk_clpb_t*) == data_size);

    /* get configuration */
    agg_cfg = mtlk_clpb_enum_get_next(clpb, &agg_cfg_size);
    MTLK_CLPB_TRY(agg_cfg, agg_cfg_size)
      MTLK_CFG_START_CHEK_ITEM_AND_CALL()
        /* send new config to FW */
        MTLK_CFG_CHECK_ITEM_AND_CALL(agg_cfg, agg_rate_limit, mtlk_core_set_agg_rate_limit,
                                     (core, agg_cfg), res);
        /* store new config in internal db*/
        MTLK_CFG_CHECK_ITEM_AND_CALL_VOID(agg_cfg, agg_rate_limit, _mtlk_core_store_agg_rate_limit,
                                          (core, agg_cfg));
      MTLK_CFG_END_CHEK_ITEM_AND_CALL()
    MTLK_CLPB_FINALLY(res)
      /* push result into clipboard */
      return mtlk_clpb_push_res(clpb, res);
    MTLK_CLPB_END
}

static mtlk_error_t
_mtlk_core_get_agg_rate_limit (mtlk_handle_t hcore, const void* data, uint32 data_size)
{
    mtlk_error_t res = MTLK_ERR_OK;
    mtlk_agg_rate_limit_cfg_t agg_cfg;
    mtlk_core_t *core = (mtlk_core_t*)hcore;
    mtlk_clpb_t *clpb = *(mtlk_clpb_t **) data;

    MTLK_ASSERT(sizeof(mtlk_clpb_t*) == data_size);

    /* read config from internal db */
    memset(&agg_cfg, 0, sizeof(agg_cfg));
    MTLK_CFG_SET_ITEM_BY_FUNC(&agg_cfg, agg_rate_limit, wave_core_receive_agg_rate_limit,
                              (core, &agg_cfg.agg_rate_limit), res)

    /* push result and config to clipboard*/
    res = mtlk_clpb_push(clpb, &res, sizeof(res));
    if (MTLK_ERR_OK == res) {
        res = mtlk_clpb_push(clpb, &agg_cfg, sizeof(agg_cfg));
    }

    return res;
}

/************* TX Power Limit configuration ******************/
static mtlk_error_t
_mtlk_core_set_tx_power_limit_offset (mtlk_handle_t hcore, const void* data, uint32 data_size)
{
    mtlk_error_t res = MTLK_ERR_OK;
    mtlk_core_t *core = (mtlk_core_t *) hcore;
    wave_radio_t *radio = wave_vap_radio_get(core->vap_handle);
    mtlk_tx_power_lim_cfg_t *tx_power_lim_cfg = NULL;
    uint32 tx_power_lim_cfg_size;
    mtlk_clpb_t *clpb = *(mtlk_clpb_t **) data;
    mtlk_card_type_info_t card_type_info;

    MTLK_ASSERT(sizeof(mtlk_clpb_t*) == data_size);

    mtlk_hw_get_prop(mtlk_vap_get_hwapi(core->vap_handle), MTLK_HW_PROP_CARD_TYPE_INFO,
                        &card_type_info, sizeof(card_type_info));

    /* get configuration */
    tx_power_lim_cfg = mtlk_clpb_enum_get_next(clpb, &tx_power_lim_cfg_size);
    MTLK_CLPB_TRY(tx_power_lim_cfg, tx_power_lim_cfg_size)
      MTLK_CFG_START_CHEK_ITEM_AND_CALL()
        if (_mtlk_card_is_asic(card_type_info)) { /* avoid on non-ASIC, due to timing */
          /* send new config to FW */
          MTLK_CFG_CHECK_ITEM_AND_CALL(tx_power_lim_cfg, powerLimitOffset, mtlk_core_send_tx_power_limit_offset,
                                       (core, tx_power_lim_cfg->powerLimitOffset), res);
        }
        /* store new config in internal db. Must be stored in power units. */
        MTLK_CFG_CHECK_ITEM_AND_CALL_VOID(tx_power_lim_cfg, powerLimitOffset, WAVE_RADIO_PDB_SET_INT,
                                          (radio, PARAM_DB_RADIO_TX_POWER_LIMIT_OFFSET, DBM_TO_POWER(tx_power_lim_cfg->powerLimitOffset)));
      MTLK_CFG_END_CHEK_ITEM_AND_CALL()
    MTLK_CLPB_FINALLY(res)
      /* push result into clipboard */
      return mtlk_clpb_push_res(clpb, res);
    MTLK_CLPB_END
}

static mtlk_error_t
_mtlk_core_get_tx_power_limit_offset (mtlk_handle_t hcore, const void* data, uint32 data_size)
{
    mtlk_error_t res = MTLK_ERR_OK;
    mtlk_tx_power_lim_cfg_t tx_power_lim_cfg;
    mtlk_core_t *core = (mtlk_core_t*)hcore;
    mtlk_clpb_t *clpb = *(mtlk_clpb_t **) data;

    MTLK_ASSERT(sizeof(mtlk_clpb_t*) == data_size);

    MTLK_CFG_SET_ITEM_BY_FUNC(&tx_power_lim_cfg, powerLimitOffset, mtlk_core_receive_tx_power_limit_offset,
                              (core, &tx_power_lim_cfg.powerLimitOffset), res);

    /* push result and config to clipboard*/
    res = mtlk_clpb_push(clpb, &res, sizeof(res));
    if (MTLK_ERR_OK == res) {
        res = mtlk_clpb_push(clpb, &tx_power_lim_cfg, sizeof(tx_power_lim_cfg));
    }

    return res;
}

/************* Change HT protection method ******************/

static int
_mtlk_core_set_bss_internal(mtlk_core_t *core, struct mtlk_bss_parameters *params)
{
    UMI_SET_BSS fw_request;
    int res = MTLK_ERR_OK;

    ILOG2_DD("CID-%04x: vap_in_fw_is_active=%u",
            mtlk_vap_get_oid(core->vap_handle), core->vap_in_fw_is_active);

    /* FIXME: be sure that this flag as correct */
    if (!core->vap_in_fw_is_active) {
        /* Workaround: UM_BSS_SET_BSS_REQ still cannot be sent, but it is not a fatal error.
           Updated parameterts has to written to pdb; they will be set during a new call
           of UM_BSS_SET_BSS_REQ.
         */
        ILOG2_D("CID-%04x: UM_BSS_SET_BSS_REQ rejected, but settings will be updated in pdb",  mtlk_vap_get_oid(core->vap_handle));
        goto end;
    }

    /* Fill UMI_SET_BSS FW request */
    _mtlk_core_fill_set_bss_request(core, &fw_request, params);

    /* Process UM_BSS_SET_BSS_REQ */
    res = mtlk_core_set_bss(core, core, &fw_request);

end:
    return res;
}

static void
_mtlk_core_reset_bss_params_internal(struct mtlk_bss_parameters *bss_parameters)
{
    memset(bss_parameters, 0, sizeof(*bss_parameters));
    bss_parameters->use_cts_prot = -1;
    bss_parameters->use_short_preamble = -1;
    bss_parameters->use_short_slot_time = -1;
    bss_parameters->ht_opmode = -1;
    bss_parameters->p2p_ctwindow = -1;
    bss_parameters->p2p_opp_ps = -1;
    bss_parameters->he_bss_color.color = MAX_UINT8;
}

static int
mtlk_core_set_ht_protection (mtlk_core_t *core, uint32 protection_mode)
{
    struct mtlk_bss_parameters bss_parameters;

    /* reset structure and set protection mode */
    _mtlk_core_reset_bss_params_internal(&bss_parameters);
    bss_parameters.use_cts_prot = protection_mode;

    /* set bss */
    return _mtlk_core_set_bss_internal(core, &bss_parameters);
}

static void
_mtlk_core_store_ht_protection (mtlk_core_t *core, const uint32 protection_mode)
{
    int flags;

    MTLK_ASSERT(core != NULL);

    /* store value */
    MTLK_CORE_PDB_SET_INT(core, PARAM_DB_CORE_HT_PROTECTION, protection_mode);
    /* update priority flag */
    flags = MTLK_CORE_PDB_GET_INT(core, PARAM_DB_CORE_IWPRIV_FORCED);
    MTLK_CORE_PDB_SET_INT(core, PARAM_DB_CORE_IWPRIV_FORCED, flags | PARAM_DB_CORE_IWPRIV_FORCED_HT_PROTECTION_FLAG);
}

static mtlk_error_t
_mtlk_core_set_ht_protection (mtlk_handle_t hcore, const void* data, uint32 data_size)
{
    mtlk_error_t res = MTLK_ERR_OK;
    mtlk_core_t *core = (mtlk_core_t *) hcore;
    mtlk_ht_protection_cfg_t *protection_cfg = NULL;
    uint32 protection_cfg_size;
    mtlk_clpb_t *clpb = *(mtlk_clpb_t **) data;

    MTLK_ASSERT(sizeof(mtlk_clpb_t*) == data_size);

    /* get configuration */
    protection_cfg = mtlk_clpb_enum_get_next(clpb, &protection_cfg_size);
    MTLK_CLPB_TRY(protection_cfg, protection_cfg_size)
      MTLK_CFG_START_CHEK_ITEM_AND_CALL()
        /* send new config to FW */
        MTLK_CFG_CHECK_ITEM_AND_CALL(protection_cfg, use_cts_prot, mtlk_core_set_ht_protection,
                                     (core, protection_cfg->use_cts_prot), res);
        /* store new config in internal db*/
        MTLK_CFG_CHECK_ITEM_AND_CALL_VOID(protection_cfg, use_cts_prot, _mtlk_core_store_ht_protection,
                                          (core, protection_cfg->use_cts_prot));
      MTLK_CFG_END_CHEK_ITEM_AND_CALL()
    MTLK_CLPB_FINALLY(res)
      /* push result into clipboard */
      return mtlk_clpb_push_res(clpb, res);
    MTLK_CLPB_END
}

static mtlk_error_t
_mtlk_core_get_ht_protection (mtlk_handle_t hcore, const void* data, uint32 data_size)
{
    mtlk_error_t res = MTLK_ERR_OK;
    mtlk_ht_protection_cfg_t protection_cfg;
    mtlk_core_t *core = (mtlk_core_t*)hcore;
    mtlk_clpb_t *clpb = *(mtlk_clpb_t **) data;

    MTLK_ASSERT(sizeof(mtlk_clpb_t*) == data_size);

    /* read config from internal db */
    MTLK_CFG_SET_ITEM(&protection_cfg, use_cts_prot, MTLK_CORE_PDB_GET_INT(core, PARAM_DB_CORE_HT_PROTECTION));

    /* push result and config to clipboard*/
    res = mtlk_clpb_push(clpb, &res, sizeof(res));
    if (MTLK_ERR_OK == res) {
        res = mtlk_clpb_push(clpb, &protection_cfg, sizeof(protection_cfg));
    }

    return res;
}

static int
_mtlk_core_get_tx_power (mtlk_handle_t hcore, const void* data, uint32 data_size)
{
    int res = MTLK_ERR_OK;
    mtlk_tx_power_cfg_t tx_power_cfg;
    mtlk_core_t *core = (mtlk_core_t*)hcore;
    wave_radio_t *radio = wave_vap_radio_get(core->vap_handle);
    mtlk_clpb_t *clpb = *(mtlk_clpb_t **) data;

    MTLK_ASSERT(sizeof(mtlk_clpb_t*) == data_size);

    /* read tx power and convert it from power units to dBm */
    MTLK_CFG_SET_ITEM(&tx_power_cfg, tx_power,
      POWER_TO_DBM(WAVE_RADIO_PDB_GET_INT(radio, PARAM_DB_RADIO_TX_POWER_CFG) -
                   WAVE_RADIO_PDB_GET_INT(radio, PARAM_DB_RADIO_TX_POWER_LIMIT_OFFSET)));

    /* push result and config to clipboard*/
    res = mtlk_clpb_push(clpb, &res, sizeof(res));
    if (MTLK_ERR_OK == res) {
        res = mtlk_clpb_push(clpb, &tx_power_cfg, sizeof(tx_power_cfg));
    }

    return res;
}

/********************************/

#define DSCP_LOWEST_PRIORITY 0
#define DSCP_UNUSED_RANGE 255

static int
_save_qos_map (mtlk_core_t *core, struct cfg80211_qos_map *qos_map)
{
  int res = MTLK_ERR_PARAMS;
  uint32 up_idx, dscp_idx, dscp_low, dscp_high;
  uint8 dscp_table[DSCP_NUM];

  /* Erase table. All frames with unknown DSCP must be transmitted with UP=0 (DSCP_LOWEST_PRIORITY) */
  memset(dscp_table, DSCP_LOWEST_PRIORITY, sizeof(dscp_table));

  /* Process common DSCP values */
  {
    for (up_idx = 0; up_idx < NTS_TIDS; up_idx++) {
      dscp_low = qos_map->up[up_idx].low;
      dscp_high = qos_map->up[up_idx].high;

      if ((dscp_low < DSCP_NUM) && (dscp_high < DSCP_NUM) && (dscp_low <= dscp_high)) {
        for (dscp_idx = dscp_low; dscp_idx <= dscp_high; dscp_idx++) {
          dscp_table[dscp_idx] = up_idx;
        }
      } else if ((dscp_low == DSCP_UNUSED_RANGE) && (dscp_high == DSCP_UNUSED_RANGE)){
        ILOG0_D("Skip pair for up_idx %d", up_idx);
      } else {
        ELOG_DDD("Incorrect value(s) for up_idx: %d (dscp_low: %d, dscp_high %d)", up_idx, dscp_low, dscp_high);
        goto end;
      }
    }
  }

  /* Process DSCP exceptions */
  {
    int num_des = qos_map->num_des;
    int i;

    if (num_des > IEEE80211_QOS_MAP_MAX_EX) {
      ELOG_DD("Too many DSCP exceptions: %d, maximum allowed: %d", num_des, IEEE80211_QOS_MAP_MAX_EX);
      goto end;
    }

    for (i = 0; i < num_des; i++) {
      dscp_idx = qos_map->dscp_exception[i].dscp;
      up_idx = qos_map->dscp_exception[i].up;
      if ((dscp_idx < DSCP_NUM) && (up_idx < NTS_TIDS)) {
        dscp_table[dscp_idx] = up_idx;
      } else {
        ELOG_DDD("Incorrect value(s) for exception %d (dscp_idx: %d, up_idx: %d)", i, dscp_idx, up_idx);
        goto end;
      }
    }
  }

  mtlk_dump(2, dscp_table, sizeof(dscp_table), "dump of QoS map");
  wave_memcpy(core->dscp_table, sizeof(core->dscp_table), dscp_table, sizeof(dscp_table));
  res = MTLK_ERR_OK;

#if MTLK_USE_DIRECTCONNECT_DP_API
  /* Update QoS for DirectConnect DP Driver */
  {
    mtlk_df_user_t *df_user = mtlk_df_get_user(mtlk_vap_get_df(core->vap_handle));
    if (MTLK_ERR_OK != mtlk_df_user_set_priority_to_qos(df_user, core->dscp_table)) {
      WLOG_S("%s: Unable set priority to WMM", mtlk_df_user_get_name(df_user));
    }
  }
#endif

end:
  return res;
}

static int
_mtlk_core_set_qos_map (mtlk_handle_t hcore, const void* data, uint32 data_size)
{
  int                       res = MTLK_ERR_NOT_SUPPORTED;
  mtlk_core_t               *core = (mtlk_core_t*)hcore;
  mtlk_clpb_t               *clpb = *(mtlk_clpb_t **) data;
  uint32                    qos_map_size;
  struct cfg80211_qos_map   *qos_map = NULL;

  MTLK_ASSERT(sizeof(mtlk_clpb_t*) == data_size);

  qos_map = mtlk_clpb_enum_get_next(clpb, &qos_map_size);
  MTLK_CLPB_TRY(qos_map, qos_map_size)
    res = _save_qos_map(core, qos_map);
  MTLK_CLPB_FINALLY(res)
    return mtlk_clpb_push_res(clpb, res);
  MTLK_CLPB_END
}

static mtlk_error_t
_mtlk_core_mbss_add_vap_idx (mtlk_handle_t hcore, uint32 vap_index, mtlk_work_role_e role, BOOL is_master)
{
  mtlk_error_t res = MTLK_ERR_OK;
  mtlk_core_t *core = (mtlk_core_t*)hcore;
  char ndev_name_pattern[IFNAMSIZ];
  int nchars;

  ILOG2_D("CID-%04x: Got PRM_ID_VAP_ADD", mtlk_vap_get_oid(core->vap_handle));

  nchars = mtlk_snprintf(ndev_name_pattern, sizeof(ndev_name_pattern), "%s.%d", MTLK_NDEV_NAME, (vap_index - 1));
  if (nchars < 0 || (size_t)nchars >= sizeof(ndev_name_pattern)) {
    return MTLK_ERR_BUF_TOO_SMALL;
  }

  if ((res = mtlk_vap_manager_create_vap(mtlk_vap_get_manager(core->vap_handle),
                                         vap_index,
                                         ndev_name_pattern,
                                         role,
                                         is_master,
                                         NULL)) != MTLK_ERR_OK) {
    ELOG_DD("CID-%04x: Can't add VapID %u", mtlk_vap_get_oid(core->vap_handle), vap_index);
  } else {
    ILOG0_DD("CID-%04x: VapID %u added", mtlk_vap_get_oid(core->vap_handle), vap_index);
  }

  return res;
}

static mtlk_error_t
_mtlk_core_mbss_del_vap_idx (mtlk_handle_t hcore, uint32 vap_index)
{
  mtlk_error_t res = MTLK_ERR_OK;
  mtlk_core_t *core = (mtlk_core_t*)hcore;
  mtlk_vap_handle_t vap_handle;
  int target_core_state;
  uint32 max_vaps_count;

  max_vaps_count = mtlk_vap_manager_get_max_vaps_count(mtlk_vap_get_manager(core->vap_handle));
  if (vap_index >= max_vaps_count) {
    ELOG_DD("CID-%04x: VapID %u invalid", mtlk_vap_get_oid(core->vap_handle), vap_index);
    res = MTLK_ERR_PARAMS;
    goto func_ret;
  }

  res = mtlk_vap_manager_get_vap_handle(mtlk_vap_get_manager(core->vap_handle), vap_index, &vap_handle);
  if (MTLK_ERR_OK != res ) {
    ELOG_DD("CID-%04x: VapID %u doesn't exist", mtlk_vap_get_oid(core->vap_handle), vap_index);
    res = MTLK_ERR_PARAMS;
    goto func_ret;
  }

  if (mtlk_vap_is_master(vap_handle)) {
    ELOG_D("CID-%04x: Can't remove Master VAP", mtlk_vap_get_oid(core->vap_handle));
    res = MTLK_ERR_PARAMS;
    goto func_ret;
  }

  target_core_state = mtlk_core_get_net_state(mtlk_vap_get_core(vap_handle));
  if ( 0 == ((NET_STATE_READY|NET_STATE_IDLE|NET_STATE_HALTED) & target_core_state) ) {
    ILOG1_D("CID-%04x:: Invalid card state - request rejected", mtlk_vap_get_oid(vap_handle));
    res = MTLK_ERR_NOT_READY;
    goto func_ret;
  }

  ILOG0_DD("CID-%04x: Deleting VapID %u", mtlk_vap_get_oid(core->vap_handle), vap_index);
  mtlk_vap_stop(vap_handle);
  mtlk_vap_delete(vap_handle);
  res = MTLK_ERR_OK;

func_ret:
  return res;
}

static int
_mtlk_core_add_vap_name (mtlk_handle_t hcore,
                         const void* data, uint32 data_size)
{
  int res = MTLK_ERR_NO_RESOURCES;
  mtlk_core_t *nic = HANDLE_T_PTR(mtlk_core_t, hcore);
  mtlk_clpb_t *clpb = *(mtlk_clpb_t **) data;
  mtlk_mbss_cfg_t *mbss_cfg;
  uint32 mbss_cfg_size = sizeof(mtlk_mbss_cfg_t);
  uint32 _vap_index;
  mtlk_vap_handle_t _vap_handle;
  void *ctx;

  MTLK_ASSERT(sizeof(mtlk_clpb_t*) == data_size);

  mbss_cfg = mtlk_clpb_enum_get_next(clpb, &mbss_cfg_size);
  MTLK_CLPB_TRY(mbss_cfg, mbss_cfg_size)
  {
    if (wave_in_fw_recovery(nic)) {
        ELOG_V("Cannot add vap due to recovery");
        MTLK_CLPB_EXIT(MTLK_ERR_NOT_READY);
    }

    if (mtlk_core_is_block_tx_mode(nic)) {
      ELOG_V("Cannot add vap, waiting for beacons");
        MTLK_CLPB_EXIT(MTLK_ERR_RETRY);
    }

    if (mtlk_core_is_in_scan_mode(nic)) {
      ILOG1_V("Cannot add vap, scan is running");
        MTLK_CLPB_EXIT(MTLK_ERR_RETRY);
    }

    res = mtlk_vap_manager_get_free_vap_index(mtlk_vap_get_manager(nic->vap_handle), &_vap_index);
    if (MTLK_ERR_OK != res) {
      ELOG_V("No free slot for new VAP");
        MTLK_CLPB_EXIT(res);
    }

    res = mtlk_vap_manager_create_vap(mtlk_vap_get_manager(nic->vap_handle),
        _vap_index,
        mbss_cfg->added_vap_name,
        mbss_cfg->role,
        mbss_cfg->is_master,
        mbss_cfg->ndev);
    if (MTLK_ERR_OK != res) {
      ELOG_V("Can't add VAP");
        MTLK_CLPB_EXIT(res);
    }

    res = mtlk_vap_manager_get_vap_handle(mtlk_vap_get_manager(nic->vap_handle), _vap_index, &_vap_handle);
    if (MTLK_ERR_OK != res) {
      ELOG_D("VapID %u doesn't exist", _vap_index);
        MTLK_CLPB_EXIT(res);
    }

    {
      struct intel_vendor_he_oper he_operation = {0};
      mtlk_pdb_size_t he_operation_len = sizeof(he_operation);
      mtlk_pdb_t *param_db_core = mtlk_vap_get_param_db(_vap_handle);
      wave_radio_t *radio = wave_vap_radio_get(nic->vap_handle);
      wave_pdb_get_binary(param_db_core, PARAM_DB_CORE_HE_OPERATION, &he_operation, &he_operation_len);

      if(wave_radio_max_tx_antennas_get(radio) == MAX_NUM_TX_ANTENNAS)
        he_operation.co_hosted_bss = HE_OPERATION_MAX_COHOSTED_BSS_IND_4STS;

      wave_pdb_set_binary(param_db_core, PARAM_DB_CORE_HE_OPERATION, &he_operation, he_operation_len);
    }

    ctx = mtlk_df_get_user(mtlk_vap_get_df(_vap_handle));

    res = mtlk_clpb_push(clpb, &ctx, sizeof(ctx));
    if (MTLK_ERR_OK != res) {
      mtlk_clpb_purge(clpb);
    }
  }
  MTLK_CLPB_FINALLY(res)
    return res;
  MTLK_CLPB_END;
}

static mtlk_error_t
_mtlk_core_add_vap_idx (mtlk_handle_t hcore,
                        const void* data, uint32 data_size)
{
  mtlk_error_t res = MTLK_ERR_OK;
  mtlk_mbss_cfg_t *mbss_cfg;
  uint32 mbss_cfg_size = sizeof(mtlk_mbss_cfg_t);
  mtlk_clpb_t *clpb = *(mtlk_clpb_t **) data;

  MTLK_ASSERT(sizeof(mtlk_clpb_t*) == data_size);

  mbss_cfg = mtlk_clpb_enum_get_next(clpb, &mbss_cfg_size);
  MTLK_CLPB_TRY(mbss_cfg, mbss_cfg_size)
    {
    MTLK_CFG_START_CHEK_ITEM_AND_CALL()
      MTLK_CFG_CHECK_ITEM_AND_CALL(mbss_cfg, added_vap_index, _mtlk_core_mbss_add_vap_idx,
                                   (hcore, mbss_cfg->added_vap_index, mbss_cfg->role, mbss_cfg->is_master), res);
    MTLK_CFG_END_CHEK_ITEM_AND_CALL()
    }
  MTLK_CLPB_FINALLY(res)
    return mtlk_clpb_push_res(clpb, res);
  MTLK_CLPB_END;
}

static int
_mtlk_core_del_vap_name (mtlk_handle_t hcore,
                         const void* data, uint32 data_size)
{
  int res = MTLK_ERR_OK;
  mtlk_core_t *core = (mtlk_core_t*)hcore;
  mtlk_clpb_t *clpb = *(mtlk_clpb_t **) data;
  mtlk_mbss_cfg_t *mbss_cfg;
  uint32 mbss_cfg_size = sizeof(mtlk_mbss_cfg_t);

  MTLK_ASSERT(sizeof(mtlk_clpb_t*) == data_size);

  mbss_cfg = mtlk_clpb_enum_get_next(clpb, &mbss_cfg_size);
  MTLK_CLPB_TRY(mbss_cfg, mbss_cfg_size)
    if (mtlk_vap_is_master(mbss_cfg->vap_handle)) {
      ELOG_D("CID-%04x: Can't remove Master VAP", mtlk_vap_get_oid(core->vap_handle));
      MTLK_CLPB_EXIT(MTLK_ERR_PARAMS);
    }

    if (!mtlk_vap_get_core(mbss_cfg->vap_handle)->is_stopped) {
      res = __mtlk_core_deactivate(core, mtlk_vap_get_core(mbss_cfg->vap_handle));
      if ((MTLK_ERR_OK != res) && (MTLK_ERR_RETRY != res)) {
        ELOG_DD("CID-%04x: Core deactivation is failed err:%d", mtlk_vap_get_oid(mbss_cfg->vap_handle), res);
        /* Continue deactivation flow */
      } else if (MTLK_ERR_RETRY == res) {
        ILOG2_D("CID-%04x: Core deactivation is postponded", mtlk_vap_get_oid(mbss_cfg->vap_handle));
        MTLK_CLPB_EXIT(res);
      }
    }

    if (mtlk_core_is_block_tx_mode(core)) {
      ELOG_V("Cannot remove vap, waiting for beacons");
      MTLK_CLPB_EXIT(MTLK_ERR_RETRY);
    }

    if (mtlk_core_is_in_scan_mode(core)) {
      ELOG_V("Cannot remove vap, scan is running");
      MTLK_CLPB_EXIT(MTLK_ERR_RETRY);
    }

    /* keep as last check before mtlk_vap_stop() */
    if (wave_in_fw_recovery(core) && !wave_in_complete_recovery(core)) {
      ELOG_V("FW recovery, will remove VAP after recovery");
      MTLK_CLPB_EXIT(MTLK_ERR_RETRY);
    }

    mtlk_vap_stop(mbss_cfg->vap_handle);
    mtlk_vap_delete(mbss_cfg->vap_handle);
  MTLK_CLPB_FINALLY(res)
    return mtlk_clpb_push_res(clpb, res);
  MTLK_CLPB_END;
}

static mtlk_error_t
_mtlk_core_del_vap_idx (mtlk_handle_t hcore,
                        const void* data, uint32 data_size)
{
  mtlk_error_t res = MTLK_ERR_OK;
  mtlk_mbss_cfg_t *mbss_cfg;
  uint32 mbss_cfg_size = sizeof(mtlk_mbss_cfg_t);
  mtlk_clpb_t *clpb = *(mtlk_clpb_t **) data;

  MTLK_ASSERT(sizeof(mtlk_clpb_t*) == data_size);

  mbss_cfg = mtlk_clpb_enum_get_next(clpb, &mbss_cfg_size);
  MTLK_CLPB_TRY(mbss_cfg, mbss_cfg_size)
    MTLK_CFG_START_CHEK_ITEM_AND_CALL()
      MTLK_CFG_CHECK_ITEM_AND_CALL(mbss_cfg, deleted_vap_index, _mtlk_core_mbss_del_vap_idx,
                                   (hcore, mbss_cfg->deleted_vap_index), res);
    MTLK_CFG_END_CHEK_ITEM_AND_CALL()
  MTLK_CLPB_FINALLY(res)
    return mtlk_clpb_push_res(clpb, res);
  MTLK_CLPB_END;
}

static mtlk_error_t
_wave_core_interfdet_cfg_set (mtlk_core_t *core, const int threshold)
{
  mtlk_error_t res = MTLK_ERR_OK;
  BOOL interf_det_enabled = FALSE;

  MTLK_ASSERT(core != NULL);
  MTLK_ASSERT(mtlk_vap_is_master_ap(core->vap_handle));

  if (threshold > 1 || threshold < MIN_INT8) {
    ELOG_DD("Wrong interfernce detection threshold provieded %d, must be 1 (interference detection disabled in driver) or %d..0",
            threshold, MIN_INT8);
    return MTLK_ERR_VALUE;
  }

  if (threshold < 1) {
    res = mtlk_core_set_fw_interfdet_req(core, (int8)threshold);
    if (MTLK_ERR_OK == res)
      interf_det_enabled = TRUE;
  }

  wave_radio_interfdet_set(wave_vap_radio_get(core->vap_handle), interf_det_enabled, (int8)threshold);

  return res;
}

static mtlk_error_t
_mtlk_core_set_interfdet_cfg (mtlk_handle_t hcore, const void* data, uint32 data_size)
{
  mtlk_error_t res = MTLK_ERR_OK;
  mtlk_interfdet_cfg_t *interfdet_cfg;
  mtlk_core_t *core = HANDLE_T_PTR(mtlk_core_t, hcore);
  uint32 interfdet_cfg_size = sizeof(mtlk_interfdet_cfg_t);
  mtlk_clpb_t *clpb = *(mtlk_clpb_t **)data;

  MTLK_ASSERT(sizeof(mtlk_clpb_t*) == data_size);

  interfdet_cfg = mtlk_clpb_enum_get_next(clpb, &interfdet_cfg_size);
  MTLK_CLPB_TRY(interfdet_cfg, interfdet_cfg_size)
    MTLK_CFG_START_CHEK_ITEM_AND_CALL()
      MTLK_CFG_CHECK_ITEM_AND_CALL(interfdet_cfg, threshold, _wave_core_interfdet_cfg_set,
                                   (core, interfdet_cfg->threshold), res);
    MTLK_CFG_END_CHEK_ITEM_AND_CALL()
  MTLK_CLPB_FINALLY(res)
    return mtlk_clpb_push_res(clpb, res);
  MTLK_CLPB_END
}

static int8
_wave_core_interfdet_cfg_get (mtlk_core_t *core)
{
  int8 threshold = MTLK_INTERFDET_DISABLED_THRESHOLD;

  if (wave_radio_interfdet_get(wave_vap_radio_get(core->vap_handle))) {
    if (MTLK_ERR_OK != wave_core_receive_interfdet_threshold(core, &threshold))
      threshold = MTLK_INTERFDET_DISABLED_THRESHOLD;
  }

  return threshold;
}

static int
_mtlk_core_get_interfdet_cfg (mtlk_handle_t hcore, const void* data, uint32 data_size)
{
  mtlk_interfdet_cfg_t interfdet_cfg = {0};
  mtlk_core_t *core = HANDLE_T_PTR(mtlk_core_t, hcore);
  mtlk_clpb_t *clpb = *(mtlk_clpb_t **)data;

  MTLK_ASSERT(sizeof(mtlk_clpb_t*) == data_size);
  MTLK_ASSERT(mtlk_vap_is_master_ap(core->vap_handle));

  MTLK_CFG_SET_ITEM(&interfdet_cfg, threshold, _wave_core_interfdet_cfg_get(core));

  return mtlk_clpb_push(clpb, &interfdet_cfg, sizeof(interfdet_cfg));
}

static mtlk_error_t
_mtlk_core_set_11b_cfg (mtlk_handle_t hcore, const void* data, uint32 data_size)
{
  mtlk_error_t res = MTLK_ERR_OK;
  mtlk_core_t *core = (mtlk_core_t*)hcore;
  wave_radio_t *radio;
  mtlk_11b_cfg_t *_11b_cfg = NULL;
  uint32 _11b_cfg_size;
  mtlk_clpb_t *clpb = *(mtlk_clpb_t **) data;

  MTLK_ASSERT(sizeof(mtlk_clpb_t*) == data_size);
  MTLK_ASSERT(core != NULL);

  radio = wave_vap_radio_get(core->vap_handle);
  MTLK_ASSERT(radio != NULL);

  _11b_cfg = mtlk_clpb_enum_get_next(clpb, &_11b_cfg_size);
  MTLK_CLPB_TRY(_11b_cfg, _11b_cfg_size)
    MTLK_CFG_START_CHEK_ITEM_AND_CALL()
      MTLK_CFG_CHECK_ITEM_AND_CALL(_11b_cfg, antsel, mtlk_core_send_11b_antsel,
                                   (core, &_11b_cfg->antsel), res);
      WAVE_RADIO_PDB_SET_INT(radio, PARAM_DB_RADIO_11B_ANTSEL_TXANT, _11b_cfg->antsel.txAnt);
      WAVE_RADIO_PDB_SET_INT(radio, PARAM_DB_RADIO_11B_ANTSEL_RXANT, _11b_cfg->antsel.rxAnt);
      WAVE_RADIO_PDB_SET_INT(radio, PARAM_DB_RADIO_11B_ANTSEL_RATE,  _11b_cfg->antsel.rate);
    MTLK_CFG_END_CHEK_ITEM_AND_CALL()

  MTLK_CLPB_FINALLY(res)
    return mtlk_clpb_push_res(clpb, res);
  MTLK_CLPB_END
}

static mtlk_error_t
_mtlk_core_get_11b_cfg (mtlk_handle_t hcore, const void* data, uint32 data_size)
{
  mtlk_error_t res = MTLK_ERR_OK;
  mtlk_11b_cfg_t _11b_cfg;
  mtlk_core_t *core = (mtlk_core_t*)hcore;
  mtlk_clpb_t *clpb = *(mtlk_clpb_t **) data;

  MTLK_ASSERT(sizeof(mtlk_clpb_t*) == data_size);

  memset(&_11b_cfg, 0, sizeof(_11b_cfg));

  MTLK_CFG_START_CHEK_ITEM_AND_CALL()
    MTLK_CFG_SET_ITEM_BY_FUNC(&_11b_cfg, antsel, mtlk_core_receive_11b_antsel,
                              (core, &_11b_cfg.antsel), res);
  MTLK_CFG_END_CHEK_ITEM_AND_CALL()

  res = mtlk_clpb_push(clpb, &res, sizeof(res));
  if (MTLK_ERR_OK == res) {
    res = mtlk_clpb_push(clpb, &_11b_cfg, sizeof(_11b_cfg));
  }

  return res;
}

static uint32
_mtlk_core_get_available_bitrates (struct nic *nic)
{
  uint8 net_mode;
  uint32 mask = 0;

  net_mode = core_cfg_get_network_mode(nic);
  mask = get_operate_rate_set(net_mode);
  ILOG3_D("Configuration mask: 0x%08x", mask);

  return mask;
}

int mtlk_core_is_chandef_identical(struct mtlk_chan_def *chan1, struct mtlk_chan_def *chan2)
{
  return (chan1->width == chan2->width
        && chan1->center_freq1 == chan2->center_freq1
        && chan1->center_freq2 == chan2->center_freq2
        && chan1->chan.center_freq == chan2->chan.center_freq);
}

int mtlk_core_is_band_supported(mtlk_core_t *nic, mtlk_hw_band_e band)
{
  mtlk_hw_t    *hw = mtlk_vap_get_hw(nic->vap_handle);
  wave_radio_t *radio = wave_vap_radio_get(nic->vap_handle);
  unsigned      radio_id = wave_radio_id_get(radio);
  int           res = MTLK_ERR_NOT_SUPPORTED;

  if (((band != MTLK_HW_BAND_2_4_5_2_GHZ) && (band != MTLK_HW_BAND_2_4_6_GHZ) && (band != MTLK_HW_BAND_5_2_6_GHZ)) && /* VAP (station or AP role) can't be dual-band */
      (mtlk_is_band_supported(HANDLE_T(hw), radio_id, band)))
  {
    res = MTLK_ERR_OK;
  }

  return res;
}

#ifdef CONFIG_WAVE_RTLOG_REMOTE
int __MTLK_IFUNC
hw_mmb_set_rtlog_cfg(mtlk_hw_t *hw, void *buff, uint32 size);

static int
_mtlk_core_set_rtlog_cfg (mtlk_handle_t hcore,
                          const void* data, uint32 size)
{
  mtlk_core_t *core = (mtlk_core_t*)hcore;
  mtlk_clpb_t *clpb = *(mtlk_clpb_t **) data;
  uint32        cfg_size;
  void         *cfg_data; /* FIXME */

  MTLK_ASSERT(sizeof(mtlk_clpb_t*) == size);

  cfg_data = mtlk_clpb_enum_get_next(clpb, &cfg_size);
  MTLK_ASSERT(NULL != cfg_data);
  if (NULL == cfg_data) {
    ELOG_SD("%s(%d): failed to get data from clipboard", __FUNCTION__, __LINE__);
    return MTLK_ERR_UNKNOWN;
  }

  mtlk_dump(2, cfg_data, MIN(64, cfg_size), "cfg_data");

  /* Don't need to push result to clipboard */
  return hw_mmb_set_rtlog_cfg(mtlk_vap_get_hw(core->vap_handle), cfg_data, cfg_size);
}
#endif

static int
_mtlk_core_mcast_group_id_action (mtlk_handle_t core_object, const void *payload, uint32 size)
{
  struct nic *nic = HANDLE_T_PTR(struct nic, core_object);
  mtlk_core_ui_mc_action_t *req = (mtlk_core_ui_mc_action_t *)payload;
  sta_entry *sta = NULL;

  MTLK_ASSERT(size == sizeof(mtlk_core_ui_mc_action_t));

  ILOG1_DDSDY("CID-%04x: action=%d (%s), group=%d, sta addr=%Y", mtlk_vap_get_oid(nic->vap_handle), req->action,
    ((req->action == MTLK_MC_STA_JOIN_GROUP) ? "join group" : ((req->action == MTLK_MC_STA_LEAVE_GROUP) ? "leave group" : "unknown")),
    req->grp_id, &req->sta_mac_addr);
  if (MTLK_IPv4 == req->mc_addr.type)
    ILOG1_D("dst IPv4:%B", htonl(req->mc_addr.grp_ip.ip4_addr.s_addr));
  else
    ILOG1_K("dst IPv6:%K", req->mc_addr.grp_ip.ip6_addr.s6_addr);

  sta = mtlk_stadb_find_sta(&nic->slow_ctx->stadb, req->sta_mac_addr.au8Addr);
  if (NULL == sta) {
    sta = mtlk_hstdb_find_sta(&nic->slow_ctx->hstdb, req->sta_mac_addr.au8Addr);
    if (NULL == sta) {
      ILOG1_DY("CID-%04x: can't find sta:%Y", mtlk_vap_get_oid(nic->vap_handle), req->sta_mac_addr.au8Addr);
      return MTLK_ERR_OK;
    }
  }

  mtlk_mc_update_group_id_sta(nic, req->grp_id, req->action, &req->mc_addr, sta);
  mtlk_sta_decref(sta);

  return MTLK_ERR_OK;
}

int _mtlk_core_mcast_helper_group_id_action (mtlk_handle_t hcore, const void* data, uint32 data_size)
{
  mtlk_core_t *core = HANDLE_T_PTR(mtlk_core_t, hcore);
  mtlk_clpb_t *clpb = *(mtlk_clpb_t **) data;
  mtlk_core_ui_mc_update_sta_db_t *req;
  unsigned r_size;
  int res = MTLK_ERR_OK;

  ILOG1_V("mcast_helper group action invoked");

  MTLK_ASSERT(sizeof(mtlk_clpb_t *) == data_size);
  req = mtlk_clpb_enum_get_next(clpb, &r_size);
  MTLK_CLPB_TRY(req, r_size)
    mtlk_mc_update_stadb(core, req);
    mtlk_osal_mem_free(req->macs_list);
  MTLK_CLPB_FINALLY(res)
    return res;
  MTLK_CLPB_END
}

int
mtlk_core_update_network_mode(mtlk_core_t* nic, uint8 net_mode)
{
  mtlk_core_t *core = nic;
  uint8 band_new = net_mode_to_band(net_mode);
  wave_radio_t *radio;

  MTLK_ASSERT(NULL != nic);

  radio = wave_vap_radio_get(nic->vap_handle);
  if (mtlk_core_is_band_supported(core, band_new) != MTLK_ERR_OK) {
    if ((band_new == MTLK_HW_BAND_2_4_5_2_GHZ) || (band_new == MTLK_HW_BAND_2_4_6_GHZ) || (band_new == MTLK_HW_BAND_5_2_6_GHZ)) {
      /*
       * Just in case of single-band hardware
       * continue to use `default' frequency band,
       * which is de facto correct.
       */
      ELOG_D("CID-%04x: dualband isn't supported", mtlk_vap_get_oid(core->vap_handle));
      return MTLK_ERR_OK;
    } else {
      ELOG_DSD("CID-%04x: %s band isn't supported (%d)", mtlk_vap_get_oid(core->vap_handle),
              mtlk_eeprom_band_to_string(net_mode_to_band(net_mode)), net_mode);
      return MTLK_ERR_NOT_SUPPORTED;
    }
  }

  ILOG1_S("Set Network Mode to %s", net_mode_to_string(net_mode));

  MTLK_CORE_PDB_SET_INT(core, PARAM_DB_CORE_NET_MODE_CUR, net_mode);
  MTLK_CORE_PDB_SET_INT(core, PARAM_DB_CORE_NET_MODE_CFG, net_mode);

  WAVE_RADIO_PDB_SET_INT(radio, PARAM_DB_RADIO_FREQ_BAND_CFG, band_new);
  WAVE_RADIO_PDB_SET_INT(radio, PARAM_DB_RADIO_FREQ_BAND_CUR, band_new);

  /* The set of supported bands may be changed by this request.           */

  return MTLK_ERR_OK;
}

/*
 * Definitions and macros below are used only for the packet's header transformation
 * For more information, please see following documents:
 *   - IEEE 802.1H standard
 *   - IETF RFC 1042
 *   - IEEE 802.11n standard draft 5 Annex M
 * */

#define _8021H_LLC_HI4BYTES             0xAAAA0300
#define _8021H_LLC_LO2BYTES_CONVERT     0x0000
#define RFC1042_LLC_LO2BYTES_TUNNEL     0x00F8

/* Default ISO/IEC conversion
 * we need to keep full LLC header and store packet length in the T/L subfield */
#define _8021H_CONVERT(ether_header, nbuf, data_offset) \
  data_offset -= sizeof(struct ethhdr); \
  ether_header = (struct ethhdr *)(nbuf->data + data_offset); \
  ether_header->h_proto = htons(nbuf->len - data_offset - sizeof(struct ethhdr))

/* 802.1H encapsulation
 * we need to remove LLC header except the 'type' field */
#define _8021H_DECAPSULATE(ether_header, nbuf, data_offset) \
  data_offset -= sizeof(struct ethhdr) - (sizeof(mtlk_snap_hdr_t) + sizeof(mtlk_llc_hdr_t)); \
  ether_header = (struct ethhdr *)(nbuf->data + data_offset)

static int
_handle_rx_ind (mtlk_core_t *nic, mtlk_nbuf_t *nbuf, mtlk_core_handle_rx_data_t *data)
{
  int res = MTLK_ERR_OK; /* Do not free nbuf */
  uint32 qos = 0;
  sta_entry *src_sta = NULL;
  struct ethhdr *ether_header = (struct ethhdr *)nbuf->data;
  IEEE_ADDR sta_addr;
  multi_ap_mode_t mode;

  ILOG4_V("Rx indication");
  mtlk_core_inc_cnt(nic, MTLK_CORE_CNT_DAT_FRAMES_RECEIVED);

  if (__UNLIKELY(nbuf->len < sizeof(*ether_header))) {
    ILOG1_V("Ethernet Frame length is wrong");
    res = MTLK_ERR_NOT_IN_USE;
    goto end;
  }

  mtlk_eth_parser(nbuf->data, nbuf->len, mtlk_df_get_name(mtlk_vap_get_df(nic->vap_handle)), "RX");
  mtlk_dump(3, nbuf->data, MIN(64, nbuf->len), "dump of recvd 802.3 packet");
  /* Try to find source MAC of transmitter */
  src_sta = mtlk_stadb_find_sid(&nic->slow_ctx->stadb, data->sid);
  if (src_sta == NULL) {
    ILOG2_V("SOURCE of RX packet not found!");
    res = MTLK_ERR_NOT_IN_USE; /* Free nbuf */
    goto end;
  }
  sta_addr = *mtlk_sta_get_addr(src_sta);
  ILOG5_YD("STA %Y found by SID %d", &sta_addr, data->sid);

  qos = data->priority;
#ifdef MTLK_DEBUG_CHARIOT_OOO
  {
    /* Get pointer to private area */
    mtlk_nbuf_priv_t *nbuf_priv = mtlk_nbuf_priv(nbuf);
    nbuf_priv->seq_qos = qos;
  }
#endif

  if (__LIKELY(qos < NTS_TIDS_GEN6))
    nic->pstats.ac_rx_counter[qos]++;
  else
    ELOG_D("Invalid priority: %u", qos);
  nic->pstats.sta_session_rx_packets++;

  /* In Backhaul AP or EXT-hybrid mode we do not need to update hostdb */
  mode = MTLK_CORE_HOT_PATH_PDB_GET_INT(nic, CORE_DB_CORE_MULTI_AP_MODE);
  if (!((MULTI_AP_BACKHAUL == mode) || ((MULTI_AP_EXT_HYBRID == mode) &&
      mtlk_sta_is_4addr(src_sta))))
  {
    if (memcmp(ether_header->h_source, sta_addr.au8Addr, ETH_ALEN)) {
      /* On AP we need to update HOST's entry in database of registered
      * HOSTs behind connected STAs */
      mtlk_hstdb_update_host(&nic->slow_ctx->hstdb, ether_header->h_source, &sta_addr);
    }
  }

  {
    mtlk_core_handle_tx_data_t tx_data;
    memset(&tx_data, 0, sizeof(tx_data));
    tx_data.nbuf = nbuf;
    mtlk_core_analyze_and_send_up(nic, &tx_data, src_sta);
  }

end:
  if (src_sta) mtlk_sta_decref(src_sta); /* De-reference of find */
  return res;
}

/* Funstions for STA DB hash */
__INLINE void
_mtlk_core_flush_ieee_addr_list (mtlk_core_t *nic,
                                 ieee_addr_list_t *list, char *name)
{
  mtlk_hash_enum_t              e;
  MTLK_HASH_ENTRY_T(ieee_addr) *h;
  ieee_addr_entry_t            *ieee_addr_entry;

  MTLK_UNREFERENCED_PARAM(name);
  ILOG2_DS("CID-%04x: %s list flush", mtlk_vap_get_oid(nic->vap_handle), name);

  mtlk_osal_lock_acquire(&list->ieee_addr_lock);
  h = mtlk_hash_enum_first_ieee_addr(&list->hash, &e);
  while (h) {
    ILOG2_Y("\t remove %Y", h->key.au8Addr);
    ieee_addr_entry = MTLK_CONTAINER_OF(h, ieee_addr_entry_t, hentry);
    mtlk_hash_remove_ieee_addr(&list->hash, &ieee_addr_entry->hentry);
    mtlk_osal_mem_free(ieee_addr_entry);
    h = mtlk_hash_enum_next_ieee_addr(&list->hash, &e);
  }
  mtlk_osal_lock_release(&list->ieee_addr_lock);
}

__INLINE BOOL
_mtlk_core_ieee_addr_entry_exists (mtlk_core_t *nic, const IEEE_ADDR *addr,
                                   ieee_addr_list_t *list, char *name)
{
  MTLK_HASH_ENTRY_T(ieee_addr) *h;

  MTLK_UNREFERENCED_PARAM(name);
  ILOG3_DSY("CID-%04x: looking for %s list entry %Y",
           mtlk_vap_get_oid(nic->vap_handle), name, addr->au8Addr);

  mtlk_osal_lock_acquire(&list->ieee_addr_lock);
  h = mtlk_hash_find_ieee_addr(&list->hash, addr);
  mtlk_osal_lock_release(&list->ieee_addr_lock);
  if (!h) {
    ILOG3_DSY("CID-%04x: %s list entry NOT found %Y",
             mtlk_vap_get_oid(nic->vap_handle), name, addr->au8Addr);
  }
  return (h != NULL);
}

__INLINE void*
__mtlk_core_add_ieee_addr_entry_internal (mtlk_core_t *nic, const IEEE_ADDR *addr,
                                   ieee_addr_list_t *list, char *name, size_t extra_size)
{
  ieee_addr_entry_t *ieee_addr_entry = NULL;
  MTLK_HASH_ENTRY_T(ieee_addr) *h;
  size_t alloc_size = sizeof(*ieee_addr_entry) + extra_size;

  ieee_addr_entry = mtlk_osal_mem_alloc(alloc_size, MTLK_MEM_TAG_IEEE_ADDR_LIST);
  if (!ieee_addr_entry) {
    WLOG_V("Can't alloc list entry");
    return NULL;
  }
  memset(ieee_addr_entry, 0, alloc_size);

  mtlk_osal_lock_acquire(&list->ieee_addr_lock);
  h = mtlk_hash_insert_ieee_addr(&list->hash, addr, &ieee_addr_entry->hentry);
  mtlk_osal_lock_release(&list->ieee_addr_lock);
  if (h) {
    mtlk_osal_mem_free(ieee_addr_entry);
    ieee_addr_entry = MTLK_CONTAINER_OF(h, ieee_addr_entry_t, hentry);
    WLOG_DYS("CID-%04x: %Y already in %s list", mtlk_vap_get_oid(nic->vap_handle), addr->au8Addr, name);
  } else {
    ILOG3_DSY("CID-%04x: %s list entry add %Y", mtlk_vap_get_oid(nic->vap_handle), name, addr->au8Addr);
  }

  return ieee_addr_entry;
}

__INLINE int
_mtlk_core_add_ieee_addr_entry (mtlk_core_t *nic, const IEEE_ADDR *addr,
                                   ieee_addr_list_t *list, char *name)
{
  return ((__mtlk_core_add_ieee_addr_entry_internal (nic, addr, list, name, 0)
      == NULL) ? MTLK_ERR_NO_MEM : MTLK_ERR_OK);
}

__INLINE int
_mtlk_core_del_ieee_addr_entry (mtlk_core_t* nic, const IEEE_ADDR *addr,
                                   ieee_addr_list_t *list, char *name,
                                   BOOL entry_expected)
{
  MTLK_HASH_ENTRY_T(ieee_addr) *h;

  ILOG3_DSY("CID-%04x: %s list entry del %Y",
            mtlk_vap_get_oid(nic->vap_handle), name, addr->au8Addr);

  mtlk_osal_lock_acquire(&list->ieee_addr_lock);
  h = mtlk_hash_find_ieee_addr(&list->hash, addr); /* find address list entry in address list */
  if (h) {
    ieee_addr_entry_t *ieee_addr_entry = MTLK_CONTAINER_OF(h, ieee_addr_entry_t, hentry);
    mtlk_hash_remove_ieee_addr(&list->hash, &ieee_addr_entry->hentry);
    mtlk_osal_mem_free(ieee_addr_entry);
    mtlk_osal_lock_release(&list->ieee_addr_lock);
  } else {
    mtlk_osal_lock_release(&list->ieee_addr_lock);
    if (entry_expected) {
      ILOG0_DSY("CID-%04x: %s list entry %Y doesn't exist",
               mtlk_vap_get_oid(nic->vap_handle), name, addr->au8Addr);
    } else {
      ILOG2_DSY("CID-%04x: %s list entry %Y doesn't exist",
               mtlk_vap_get_oid(nic->vap_handle), name, addr->au8Addr);
    }
  }
  return MTLK_ERR_OK;
}

__INLINE int
_mtlk_core_dump_ieee_addr_list (mtlk_core_t *nic,
                                ieee_addr_list_t *list, char *name,
                                const void* data, uint32 data_size)
{
  mtlk_clpb_t *clpb = *(mtlk_clpb_t **) data;
  mtlk_hash_enum_t             e;
  MTLK_HASH_ENTRY_T(ieee_addr) *h;
  int                          res = MTLK_ERR_UNKNOWN;

  MTLK_ASSERT(sizeof(mtlk_clpb_t*) == data_size);
  MTLK_ASSERT(nic);
  MTLK_ASSERT(clpb);
  MTLK_UNREFERENCED_PARAM(name);
  ILOG2_DS("CID-%04x: %s list dump", mtlk_vap_get_oid(nic->vap_handle), name);

  mtlk_osal_lock_acquire(&list->ieee_addr_lock);
  h = mtlk_hash_enum_first_ieee_addr(&list->hash, &e);
  while (h) {
    ILOG2_Y("\t dump %Y", h->key.au8Addr);
    if (MTLK_ERR_OK != (res = mtlk_clpb_push(clpb, h, sizeof(*h)))) {
      mtlk_osal_lock_release(&list->ieee_addr_lock);
      goto err_push;
    }
    h = mtlk_hash_enum_next_ieee_addr(&list->hash, &e);
  }
  mtlk_osal_lock_release(&list->ieee_addr_lock);

  return MTLK_ERR_OK;

err_push:
  mtlk_clpb_purge(clpb);
  return res;
}

/* STA DB hash for filtering the Probe Responses
    1) on broadcast Probe Request (offline)     2) on unicast Probe Request */
static void _mtlk_core_flush_bcast_probe_resp_list (mtlk_core_t *nic)
{
  _mtlk_core_flush_ieee_addr_list(nic, &nic->broadcast_probe_resp_sta_list, "broadcast");
}

static BOOL _mtlk_core_bcast_probe_resp_entry_exists (mtlk_core_t *nic, const IEEE_ADDR *addr)
{
  return _mtlk_core_ieee_addr_entry_exists(nic, addr, &nic->broadcast_probe_resp_sta_list, "broadcast");
}

int _mtlk_core_add_bcast_probe_resp_entry (mtlk_core_t* nic, const IEEE_ADDR *addr)
{
  return _mtlk_core_add_ieee_addr_entry(nic, addr, &nic->broadcast_probe_resp_sta_list, "broadcast");
}

int _mtlk_core_del_bcast_probe_resp_entry (mtlk_core_t* nic, const IEEE_ADDR *addr)
{
  return _mtlk_core_del_ieee_addr_entry(nic, addr, &nic->broadcast_probe_resp_sta_list, "broadcast", TRUE);
}

static void _mtlk_core_flush_ucast_probe_resp_list (mtlk_core_t *nic)
{
  _mtlk_core_flush_ieee_addr_list(nic, &nic->unicast_probe_resp_sta_list, "unicast");
}

static BOOL _mtlk_core_ucast_probe_resp_entry_exists (mtlk_core_t *nic, const IEEE_ADDR *addr)
{
  return _mtlk_core_ieee_addr_entry_exists(nic, addr, &nic->unicast_probe_resp_sta_list, "unicast");
}

static int _mtlk_core_add_ucast_probe_resp_entry (mtlk_core_t* nic, const IEEE_ADDR *addr)
{
  return _mtlk_core_add_ieee_addr_entry(nic, addr, &nic->unicast_probe_resp_sta_list, "unicast");
}

static int _mtlk_core_del_ucast_probe_resp_entry (mtlk_core_t* nic, const IEEE_ADDR *addr)
{
  return _mtlk_core_del_ieee_addr_entry(nic, addr, &nic->unicast_probe_resp_sta_list, "unicast", TRUE);
}

void __MTLK_IFUNC _mtlk_core_flush_acl_list (mtlk_core_t *nic)
{
  wave_core_acl_t *acl = &nic->acl;
  acl->wildcard = FALSE;
  acl->policy = WAVE_ACL_POLICY_DISABLED;
  _mtlk_core_flush_ieee_addr_list(nic, &acl->mac_list, "ACL list");
}

int __MTLK_IFUNC _mtlk_core_add_acl_entry (mtlk_core_t* nic, const IEEE_ADDR *addr)
{
  wave_core_acl_t *acl = &nic->acl;

  return _mtlk_core_add_ieee_addr_entry(nic, addr, &acl->mac_list, "ACL list");
}

static __INLINE BOOL
_mtlk_core_acl_drop (mtlk_core_t *nic, const IEEE_ADDR *addr)
{
  wave_core_acl_t *acl = &nic->acl;
  BOOL drop = FALSE;

  if (WAVE_ACL_POLICY_DISABLED == acl->policy)
    return drop;

  if (acl->wildcard)
    drop = TRUE;
  else
    drop = _mtlk_core_ieee_addr_entry_exists(nic, addr, &acl->mac_list, "ACL list");

  if (acl->policy == WAVE_ACL_POLICY_ACCEPT)
    drop = !drop;

  return drop;
}

/* This function must be called from Master VAP serializer context */
static void
_mtlk_core_finalize_and_send_probe_resp (mtlk_core_t *core, mtlk_mngmnt_frame_t *frame, int mbssid_vap)
{
  uint64 cookie;
  frame_head_t *head_req, *head_resp;
  size_t len, max_buflen;
  u8 *buf;
  wave_radio_t *radio;
  mtlk_hw_band_e band;
  u32 hidden = MTLK_CORE_PDB_GET_INT(core, PARAM_DB_CORE_HIDDEN_SSID);
  u8 *tmp_buf = NULL;

  radio = wave_vap_radio_get(core->vap_handle);
  band = wave_radio_band_get(radio);
  head_req = (frame_head_t *) frame->frame;

  /* Need to remove HE IEs from probe response for clients that do not support HE. *
   * HE IEs shall be inlcuded always for 6GHz clients                              */
  if (!frame->probe_req_he_ie && (band != MTLK_HW_BAND_6_GHZ)) {
    buf = core->slow_ctx->probe_resp_templ_non_he;
    len = core->slow_ctx->probe_resp_templ_non_he_len;
  }
  else
  {
    buf = core->slow_ctx->probe_resp_templ;
    len = core->slow_ctx->probe_resp_templ_len;
  }

#define BSS_MGMT_FRAME_SIZE     2348
  tmp_buf = mtlk_osal_mem_alloc(BSS_MGMT_FRAME_SIZE, MTLK_MEM_TAG_BSS_MGMT);
  if (!tmp_buf) {
     ELOG_D("Cannot allocate %hu bytes for a new Probe Response template", BSS_MGMT_FRAME_SIZE);
     goto error;
  }
  /* Copy the full template */
  wave_memcpy(tmp_buf, BSS_MGMT_FRAME_SIZE, buf, len);
  buf = tmp_buf;
  max_buflen = BSS_MGMT_FRAME_SIZE;

  head_resp = (frame_head_t *) buf;
  /* we mess up the dst_addr in the template, but it's OK, we're under a lock and it will get copied into one of the queues in mgmt_tx *
   * In the case of 6GHz clients, the destination address is always set to Broadcast address as long as the BSS is not in hidden mode  */
  if ((band == MTLK_HW_BAND_6_GHZ) && !hidden)
    head_resp->dst_addr = head_req->dst_addr;
  else
    head_resp->dst_addr = head_req->src_addr;

  ILOG3_DY("CID-%04x: Probe Response to %Y",
           mtlk_vap_get_oid(core->vap_handle), head_resp->dst_addr.au8Addr);

  /* check if have enough room in tx queue. Do not send probe response if not */
  if (mtlk_mmb_bss_mgmt_tx_check(core->vap_handle)) {
    /* Search STA in list. Don't send if found */
    if (_mtlk_core_bcast_probe_resp_entry_exists(core, &head_resp->dst_addr)) {
        ILOG2_DY("CID-%04x: Don't send Probe Response to %Y",
                 mtlk_vap_get_oid(core->vap_handle), head_resp->dst_addr.au8Addr);
      goto error;
    }

    /* In the case of multiBSS if the Tx VAP is Hidden while the probe response is generated on behalf  *
       of a non Tx VAP, then the Probe Resp transmitted on the Tx VAP shall contain SSID with all zeros */
    if (hidden && (mbssid_vap == WAVE_RADIO_OPERATION_MODE_MBSSID_NON_TRANSMIT_VAP))
      wave_reset_ssid_in_probe_response_buffer(buf, len);

    /*
     * Add/Change BSS color data
     */
    if (core->color_change_active) {
      if (wave_core_add_bss_color_data_in_presp(core, buf, &len, max_buflen)) {
        ELOG_DY("CID-%04x: Unable to add/modify BSS color data in the probe response to %Y",
                mtlk_vap_get_oid(core->vap_handle), head_resp->dst_addr.au8Addr);
        goto error;
      }
    }
    /*
     * We are in serializer context. It is important to add entry to the list
     * prior to frame transmission is executed, as CFM may come nearly immediately
     * after HD is copied to the ring. The entry is removed from list in the
     * tasklet context, that might create a racing on entry removal.
     */
    _mtlk_core_add_bcast_probe_resp_entry(core, &head_resp->dst_addr);

    if (MTLK_ERR_OK ==
      mtlk_mmb_bss_mgmt_tx(core->vap_handle, buf, len,
                           freq2lowchannum(frame->freq, CW_20),
                           FALSE, TRUE, TRUE /* broadcast */, &cookie, PROCESS_MANAGEMENT, NULL,
                           FALSE, NTS_TID_USE_DEFAULT)) {
      mtlk_core_inc_cnt(core, MTLK_CORE_CNT_TX_PROBE_RESP_SENT);
      ILOG2_DYY("Probe Response sent - band %d, src %Y dst %Y", band, &head_resp->src_addr, &head_resp->dst_addr);
      goto end;
    } else {
      /* delete entry if TX failed */
      _mtlk_core_del_bcast_probe_resp_entry(core, &head_resp->dst_addr);
    }

  }

error:
  mtlk_core_inc_cnt(core, MTLK_CORE_CNT_TX_PROBE_RESP_DROPPED);
end:
  if (tmp_buf)
    mtlk_osal_mem_free(tmp_buf);
}

static __INLINE void
__mtlk_core_mngmnt_frame_notify (mtlk_core_t *nic, const u8 *data, uint32 size, unsigned freq,
                                 unsigned subtype, mtlk_phy_info_t *phy_info, uint8 pmf_flags)
{
  BOOL is_broadcast = FALSE;
  IEEE_ADDR *src_addr = (IEEE_ADDR *)&(((frame_head_t*)data)->src_addr);
  u8 nss;
  if (mtlk_vap_is_ap(nic->vap_handle)) {
    if (is_multicast_ether_addr((const u8 *)&(((frame_head_t*)data)->dst_addr))) {
      is_broadcast = TRUE;
    }

    if (((MAN_TYPE_PROBE_REQ == subtype) ||
         (MAN_TYPE_AUTH == subtype)      ||
         (MAN_TYPE_ASSOC_REQ == subtype) ||
         (MAN_TYPE_REASSOC_REQ == subtype)) &&
        _mtlk_core_acl_drop(nic, src_addr))
      return;

    /* don't notify about client that is in the blacklist */
    if (wave_core_blacklist_frame_drop(nic, src_addr, subtype, phy_info->snr_db, is_broadcast))
      return;
  }
  phy_info->rate_idx = mtlk_bitrate_info_to_rate_idx(phy_info->bitrate_info);
  nss = mtlk_bitrate_info_get_nss(phy_info->bitrate_info);
  if (wv_ieee80211_mngmn_frame_rx(nic, data, size, freq, phy_info->sig_dbm, phy_info->snr_db, phy_info->noise_estimation,
                              subtype, phy_info->rate_idx, phy_info->phy_mode, pmf_flags, nss)) {
    mtlk_core_inc_cnt(nic, MTLK_CORE_CNT_MAN_FRAMES_FAILED);
  }
}

void
copy_mtlk_chandef(struct mtlk_chan_def *mcd, struct mtlk_chan_def *mcs)
{
  struct mtlk_channel *mc_dest = &mcd->chan;
  struct mtlk_channel *mc_src = &mcs->chan;

  mcd->center_freq1 = mcs->center_freq1;
  mcd->center_freq2 = mcs->center_freq2;
  mcd->width = mcs->width;
  mcd->is_noht = mcs->is_noht;

  mc_dest->dfs_state_entered = mc_src->dfs_state_entered;
  mc_dest->dfs_state = mc_src->dfs_state;
  mc_dest->band = mc_src->band;
  mc_dest->center_freq = mc_src->center_freq;
  mc_dest->flags = mc_src->flags;
  mc_dest->orig_flags = mc_src->orig_flags;
  mc_dest->max_antenna_gain = mc_src->max_antenna_gain;
  mc_dest->max_power = mc_src->max_power;
  mc_dest->max_reg_power = mc_src->max_reg_power;
  mc_dest->dfs_cac_ms = mc_src->dfs_cac_ms;
}

int __MTLK_IFUNC
_mtlk_core_switch_channel_normal(mtlk_core_t *master_core, struct mtlk_chan_def *chandef)
{
  mtlk_df_t *master_df;
  mtlk_vap_handle_t master_vap_handle;
  struct set_chan_param_data cpd;

  master_df = mtlk_vap_manager_get_master_df(mtlk_vap_get_manager(master_core->vap_handle));
  MTLK_RET_CHECK_DF(master_df);
  master_vap_handle = mtlk_df_get_vap_handle(master_df);

  ILOG0_V("Seen a beacon changing channel to type normal");

  memset(&cpd, 0, sizeof(cpd));
  cpd.vap_id = mtlk_vap_get_id(master_vap_handle);
  copy_mtlk_chandef(&cpd.chandef, chandef);

  cpd.switch_type = ST_NORMAL;
  cpd.block_tx_pre = FALSE;
  cpd.block_tx_post = FALSE; /* TRUE means waiting for radars */

  _mtlk_df_user_invoke_core_async(master_df,
    WAVE_RADIO_REQ_SET_CHAN, &cpd, sizeof(cpd),
    NULL, 0);

  return MTLK_ERR_OK;
}

bool _mtlk_core_is_radar_chan(struct mtlk_channel *channel)
{
  return (channel->flags & MTLK_CHAN_RADAR);
}

static int
_mtlk_core_broadcast_mngmnt_frame_notify (mtlk_handle_t object, const void *data,  uint32 data_size)
{
  mtlk_mngmnt_frame_t *frame = (mtlk_mngmnt_frame_t *)data;
  mtlk_core_t         *master_core = HANDLE_T_PTR(struct nic, object);
  mtlk_core_t         *cur_core;
  mtlk_vap_manager_t  *vap_mng;
  mtlk_vap_handle_t   vap_handle;
  uint8 *buf       = frame->frame;
  uint32 size      = frame->size;
  unsigned freq    = frame->freq;
  unsigned subtype = frame->subtype;
  unsigned i, max_vaps;
  sta_entry *sta;
  IEEE_ADDR *src_addr;
  int softblockcheck;
  struct intel_vendor_event_msg_drop prb_req_drop;
  wave_radio_t *radio;
  mtlk_hw_band_e band;
  BOOL no_probe_req_offload = FALSE;
  int mbssid_vap = 0;
  mtlk_core_t *mbssid_vap_tx_core = NULL;
  BOOL wildcard_ssid = FALSE;
  int master_net_state;
  wave_offload_mode_t offload_mode = MTLK_CORE_HOT_PATH_PDB_GET_INT(master_core, CORE_DB_CORE_PROBEREQ_OFFLOAD_MODE);

  MTLK_ASSERT (data_size == sizeof(mtlk_mngmnt_frame_t));

  vap_mng  = mtlk_vap_get_manager(master_core->vap_handle);
  max_vaps = wave_radio_max_vaps_get(wave_vap_radio_get(master_core->vap_handle));
  master_net_state = mtlk_core_get_net_state(master_core);

  no_probe_req_offload = frame->probe_req_wps_ie || frame->probe_req_interworking_ie || frame->probe_req_vsie
                         || frame->probe_req_mlo_ie;

  if (no_probe_req_offload) {
    ILOG3_D("CID-%04x: Probe request with WPS IE || INTERWORKING IE || VSIE || ML_PROBE received, notify hostapd", mtlk_vap_get_oid(master_core->vap_handle));
  }

  if ((subtype == MAN_TYPE_PROBE_REQ) && (offload_mode != PROBEREQ_OFFLOAD_OFF) && (!no_probe_req_offload)) {
    src_addr = &((frame_head_t*)buf)->src_addr;
    for (i = 0; i < max_vaps; i++) {
      if (MTLK_ERR_OK != mtlk_vap_manager_get_vap_handle(vap_mng, i, &vap_handle)) {
        continue;   /* VAP does not exist */
      }
      cur_core = mtlk_vap_get_core(vap_handle);
      if (NET_STATE_CONNECTED != mtlk_core_get_net_state(cur_core)) {
        /* Core is not ready */
        continue;
      }
      if (mtlk_vap_is_master(vap_handle)){
        /* Dummy master VAP (in order to support reconf for all VAPs) */
        continue;
      }

      /* Probe response should be sent only from transmitted VAP in case of MBSSID */
      /* Save the transmit VAP core to use in case of a probe request frame for a non Tx VAP */
      mbssid_vap = MTLK_CORE_PDB_GET_INT(cur_core, PARAM_DB_CORE_MBSSID_VAP);
      if (mbssid_vap == WAVE_RADIO_OPERATION_MODE_MBSSID_TRANSMIT_VAP)
        mbssid_vap_tx_core = cur_core;

      sta = mtlk_stadb_find_sta(&cur_core->slow_ctx->stadb, src_addr->au8Addr);

      if (sta == NULL) {
        if (_mtlk_core_acl_drop(cur_core, src_addr))
          continue;

        /* don't notify about unassociated client that is in the blacklist */
        if (wave_core_blacklist_frame_drop(cur_core, src_addr, subtype, frame->phy_info.snr_db, TRUE))
          continue;
      }
      if (sta)
        mtlk_sta_decref(sta);

      if (mtlk_vap_is_ap(vap_handle)) {
        u8 *loc_ptr = NULL;
        u8 loc_size = 0;
        IEEE_ADDR *bssid;
        mtlk_pdb_t *param_db_core = mtlk_vap_get_param_db(vap_handle);
        int32 rssi_ignore;

        if(!cur_core->slow_ctx->ap_started){
          ILOG3_D("CID-%04x: AP not started, won't send probe response", mtlk_vap_get_oid(vap_handle));
          continue;
        }

        if (size > sizeof(frame_head_t)) {
          loc_ptr = buf + sizeof(frame_head_t);
          loc_size = size - sizeof(frame_head_t);
        }

        /* check if the received ESSID matches with that of the AP, OR  *
         * in the case of 2.4/5 GHz band only, the ESSID is NOT present *
         * but the AP is NOT hidden, OR the ESSID received matches with *
         * that of one of the coloc neigh 6G APs included in the RNR    */

        radio = wave_vap_radio_get(vap_handle);
        band = wave_radio_band_get(radio);
        bssid = &((frame_head_t *)buf)->bssid;
        ILOG2_DDYY("Broadcast Probe Request: band %d, mbssid_vap %d, src %Y, bssid %Y", band, mbssid_vap,
                    &((frame_head_t *)buf)->src_addr, bssid);
        rssi_ignore = MTLK_CORE_PDB_GET_INT(cur_core, PARAM_DB_CORE_RSSI_IGNORE_PROBE_REQ);
        if (rssi_ignore && (frame->phy_info.sig_dbm < rssi_ignore)) {
          ILOG2_DD("Ignoring Broadcast Probe Request rssi_ignore_probe_request=%d phy_sigdbm=%d", rssi_ignore, frame->phy_info.sig_dbm);
          continue;
        }
        if (mtlk_core_broadcast_probe_req_enhanced_check(band, param_db_core, loc_ptr, loc_size, bssid, &wildcard_ssid))
        {
          /* case when wps, interworking, vs ies are not present */

          int sb_timer_acl_on = MTLK_CORE_PDB_GET_INT(cur_core, PARAM_DB_CORE_SB_TIMER_ACL_ON);
          int sb_timer_acl_probe_drop = MTLK_CORE_PDB_GET_INT(cur_core, PARAM_DB_CORE_SB_TIMER_ACL_PROBE_DROP);

          /* Probe response should be sent only from transmitted VAP in case of MBSSID */
          if (mbssid_vap == WAVE_RADIO_OPERATION_MODE_MBSSID_NON_TRANSMIT_VAP)
            cur_core = mbssid_vap_tx_core;
          /* Tx VAP in case of MBSSID set should be activated in order to transmit the probe response */
          if (!cur_core)
            continue;

          if (cur_core->slow_ctx->probe_resp_templ) {
             softblockcheck = wave_core_mngmnt_softblock_notify(cur_core, src_addr, &cur_core->multi_ap_blacklist,
               "multi-AP black", frame->phy_info.snr_db, TRUE, &prb_req_drop);

             if (wildcard_ssid && ((softblockcheck == DRV_SOFTBLOCK_ACCEPT) || (softblockcheck == DRV_SOFTBLOCK_ALLOW))) {
                _mtlk_core_finalize_and_send_probe_resp(cur_core, frame, mbssid_vap);

                /* Notify hostap */
                if (softblockcheck == DRV_SOFTBLOCK_ALLOW) {
                   /* Trigger notification */
                   wave_core_send_softblock_msg_drop(cur_core->vap_handle, &prb_req_drop, sizeof(prb_req_drop));
                }
             }
          }
          if (!wildcard_ssid || (offload_mode == PROBEREQ_OFFLOAD_WILDCARD_SSID_OFF)) {
            if (sb_timer_acl_on && sb_timer_acl_probe_drop) {
              /* drop probe if sb_timer_acl_probe_drop is set */
              ILOG3_D("CID-%04x: SB Timer ACL: sb_timer_acl_probe_drop", mtlk_vap_get_oid(vap_handle));
            } else {
              /* forward probe to hostapd */
              __mtlk_core_mngmnt_frame_notify(cur_core, buf, size, freq, subtype, &frame->phy_info, frame->pmf_flags);
              ILOG3_D("CID-%04x: probe forwarded to hostapd", mtlk_vap_get_oid(vap_handle));
            }
          }
          /* If the Probe Response generated is for an MBSS VAP then skip the processing on remaining VAPs */
          if (mbssid_vap != WAVE_RADIO_NON_MULTIBSS_VAP)
            break; /*exit the for loop for VAPs */
        }
      }
    } /* for (i = 0; i < max_vaps; i++) */
  }
  else
  { /* broadcast management frames will be cloned per interface in mac80211 */
      if ((NET_STATE_CONNECTED == master_net_state) || (NET_STATE_ACTIVATING == master_net_state)) {
       /* Allow all frames when VAP is ready */
       __mtlk_core_mngmnt_frame_notify(master_core, buf, size, freq, subtype, &frame->phy_info, frame->pmf_flags);
      }
  }

  mtlk_osal_mem_free(frame->frame);
  return MTLK_ERR_OK;
}

static int
handle_rx_bss_ind(mtlk_core_t *nic, mtlk_core_handle_rx_bss_t *data)
{
  int res = MTLK_ERR_OK;
  uint16 frame_ctl;
  unsigned frame_type;
  int frame_subtype;

  mtlk_dump(4, data->buf, MIN(data->size, 32), "RX BSS IND data (first 32 bytes):");

  if (data->size < sizeof(frame_head_t)) {
    ILOG1_D("CID-%04x: Management Frame length is wrong",
      mtlk_vap_get_oid(nic->vap_handle));
    return MTLK_ERR_NOT_IN_USE;
  }
  frame_ctl = mtlk_wlan_pkt_get_frame_ctl(data->buf);
  frame_type = WLAN_FC_GET_TYPE(frame_ctl);
  frame_subtype = (frame_ctl & FRAME_SUBTYPE_MASK) >> FRAME_SUBTYPE_SHIFT;

/*
802.11n data frame from AP:

        |----------------------------------------------------------------|
 Bytes  |  2   |  2    |  6  |  6  |  6  |  2  | 6?  | 2?  | 0..2312 | 4 |
        |------|-------|-----|-----|-----|-----|-----|-----|---------|---|
 Descr. | Ctl  |Dur/ID |Addr1|Addr2|Addr3| Seq |Addr4| QoS |  Frame  |fcs|
        |      |       |     |     |     | Ctl |     | Ctl |  data   |   |
        |----------------------------------------------------------------|
Total: 28-2346 bytes

Existance of Addr4 in frame is optional and depends on To_DS From_DS flags.
Existance of QoS_Ctl is also optional and depends on Ctl flags.
(802.11n-D1.0 describes also HT Control (0 or 4 bytes) field after QoS_Ctl
but we don't support this for now.)

Interpretation of Addr1/2/3/4 depends on To_DS From_DS flags:

To DS From DS   Addr1   Addr2   Addr3   Addr4
---------------------------------------------
0       0       DA      SA      BSSID   N/A
0       1       DA      BSSID   SA      N/A
1       0       BSSID   SA      DA      N/A
1       1       RA      TA      DA      SA

frame data begins with 8 bytes of LLC/SNAP:

        |-----------------------------------|
 Bytes  |  1   |   1  |  1   |    3   |  2  |
        |-----------------------------------|
 Descr. |        LLC         |     SNAP     |
        |-----------------------------------+
        | DSAP | SSAP | Ctrl |   OUI  |  T  |
        |-----------------------------------|
        |  AA  |  AA  |  03  | 000000 |     |
        |-----------------------------------|

From 802.11 data frame that we receive from MAC we are making
Ethernet DIX (II) frame.

Ethernet DIX (II) frame format:

        |------------------------------------------------------|
 Bytes  |  6  |  6  | 2 |         46 - 1500               |  4 |
        |------------------------------------------------------|
 Descr. | DA  | SA  | T |          Data                   | FCS|
        |------------------------------------------------------|

So we overwrite 6 bytes of LLC/SNAP with SA.

  Excerpts from "IEEE P802.11e/D13.0, January 2005" p.p. 22-23
  Type          Subtype     Description
  -------------------------------------------------------------
  00 Management 0000        Association request
  00 Management 0001        Association response
  00 Management 0010        Reassociation request
  00 Management 0011        Reassociation response
  00 Management 0100        Probe request
  00 Management 0101        Probe response
  00 Management 0110-0111   Reserved
  00 Management 1000        Beacon
  00 Management 1001        Announcement traffic indication message (ATIM)
  00 Management 1010        Disassociation
  00 Management 1011        Authentication
  00 Management 1100        Deauthentication
  00 Management 1101        Action
  00 Management 1101-1111   Reserved
  01 Control    0000-0111   Reserved
  01 Control    1000        Block Acknowledgement Request (BlockAckReq)
  01 Control    1001        Block Acknowledgement (BlockAck)
  01 Control    1010        Power Save Poll (PS-Poll)
  01 Control    1011        Request To Send (RTS)
  01 Control    1100        Clear To Send (CTS)
  01 Control    1101        Acknowledgement (ACK)
  01 Control    1110        Contention-Free (CF)-End
  01 Control    1111        CF-End + CF-Ack
  10 Data       0000        Data
  10 Data       0001        Data + CF-Ack
  10 Data       0010        Data + CF-Poll
  10 Data       0011        Data + CF-Ack + CF-Poll
  10 Data       0100        Null function (no data)
  10 Data       0101        CF-Ack (no data)
  10 Data       0110        CF-Poll (no data)
  10 Data       0111        CF-Ack + CF-Poll (no data)
  10 Data       1000        QoS Data
  10 Data       1001        QoS Data + CF-Ack
  10 Data       1010        QoS Data + CF-Poll
  10 Data       1011        QoS Data + CF-Ack + CF-Poll
  10 Data       1100        QoS Null (no data)
  10 Data       1101        Reserved
  10 Data       1110        QoS CF-Poll (no data)
  10 Data       1111        QoS CF-Ack + CF-Poll (no data)
  11 Reserved   0000-1111   Reserved
  */

  /*
  If we are AP:
  - in CAC time filter out all management/control/action frames. Print AUTH_REQ for debug a specific case.
  - if NET_STATE != CONNECTED: pass only beacons and probe responces.
  */

  if (mtlk_vap_is_ap(nic->vap_handle)) {
    mtlk_core_t *master_core = mtlk_core_get_master(nic->vap_handle);
    int net_state;

    /* are we in NET_STATE_CONNECTED ? */
    net_state = mtlk_core_get_net_state(master_core);
    if (NET_STATE_CONNECTED != net_state) {
      if (frame_type == IEEE80211_FTYPE_MGMT) {
        if ((frame_subtype != MAN_TYPE_PROBE_RES) && (frame_subtype != MAN_TYPE_BEACON)) {
          if (NET_STATE_ACTIVATING != net_state) {
            ILOG2_DYD("Frame subtype %d from %Y dropped due to wrong NET_STATE %d", frame_subtype, WLAN_GET_ADDR2(data->buf), net_state);
            return res;
          }
        }
      } else {
        /* not a management frame */
          ILOG2_DYD("Frame type %d from %Y dropped due to wrong NET_STATE %d", frame_type, WLAN_GET_ADDR2(data->buf), net_state);
          return res;
      }
    }
  } else /* STA */ {
    int net_state;

    net_state = mtlk_core_get_net_state(nic);
    if (NET_STATE_CONNECTED != net_state && NET_STATE_ACTIVATING != net_state) {
      ILOG2_DDYD("Frame type %d subtype %d from %Y dropped due to wrong NET_STATE %d",
                frame_type, frame_subtype, WLAN_GET_ADDR2(data->buf), net_state);
      return res;
    }
  }

  switch (frame_type)
  {
  case IEEE80211_FTYPE_MGMT:
    {
      mtlk_phy_info_t *phy_info = &data->phy_info;
      uint8 *src_addr = WLAN_GET_ADDR2(data->buf);
      sta_entry *sta = NULL;
      mtlk_mgmt_frame_data_t fd;

      unsigned subtype = (frame_ctl & FRAME_SUBTYPE_MASK) >> FRAME_SUBTYPE_SHIFT;

      bool is_sta = FALSE;
      bool is_sta_mfp = FALSE;

      uint8 *fbuf = data->buf;
      fbuf += sizeof(frame_head_t);

      memset(&fd, 0, sizeof(fd));
      fd.phy_info = phy_info;
      fd.chan = NULL;

      sta = mtlk_stadb_find_sta(&(nic->slow_ctx->stadb), src_addr);
      is_sta = !(sta == NULL);
      if (is_sta)
        is_sta_mfp = mtlk_sta_is_mfp(sta);
      res = mtlk_process_man_frame(HANDLE_T(nic), is_sta, is_sta_mfp, data->buf, &data->size, &fd);

      if (res == MTLK_ERR_OK)
      {
        if (fd.notify_hapd_supplicant)
        {
          BOOL is_broadcast = FALSE;

          if (mgmt_frame_filter_allows(nic, &nic->slow_ctx->mgmt_frame_filter,
               data->buf, data->size, &is_broadcast))
          {
            wave_radio_t *radio = wave_vap_radio_get(nic->vap_handle);
            int radio_probe_req_flag = WAVE_RADIO_PDB_GET_INT(radio, PARAM_DB_RADIO_COLLECT_PROBE_REQ);
            if (radio_probe_req_flag && subtype == MAN_TYPE_PROBE_REQ) {
              wave_probe_req_list_add(radio, (IEEE_ADDR *)src_addr, phy_info->max_rssi);
            }
            if (is_broadcast) {
              /* Broad cast frames will be send throught serialzer - we need copy them for all vaps */
              mtlk_mngmnt_frame_t frame;
              frame.size = data->size;
              frame.freq = fd.chan->center_freq;
              frame.subtype = subtype;
              frame.phy_info = *fd.phy_info; /* including max_rssi */
              frame.probe_req_wps_ie = fd.probe_req_wps_ie;
              frame.probe_req_interworking_ie = fd.probe_req_interworking_ie;
              frame.probe_req_vsie = fd.probe_req_vsie;
              frame.probe_req_he_ie = fd.probe_req_he_ie;
              frame.probe_req_mlo_ie = fd.probe_req_mlo_ie;
              frame.pmf_flags = fd.pmf_flags;
              frame.frame = mtlk_osal_mem_alloc(data->size, MTLK_MEM_TAG_CFG80211);
              if (frame.frame == NULL) {
                ELOG_D("CID-%04x: Can't allocate memory for mngmnt frame", mtlk_vap_get_oid(nic->vap_handle));
              } else {
                mtlk_core_t *master_core = mtlk_core_get_master(nic->vap_handle);
                wave_memcpy(frame.frame, data->size, data->buf, data->size);
                _mtlk_process_hw_task(master_core, SERIALIZABLE, _mtlk_core_broadcast_mngmnt_frame_notify, HANDLE_T(master_core),
                                      &frame, sizeof(mtlk_mngmnt_frame_t));
              }
            } else {
              /* Sanity: drop unicast frames sent to a dummy master VAP exclude probe response and beacons*/
              if ((mtlk_vap_is_master(nic->vap_handle)) &&
                  (frame_subtype != MAN_TYPE_PROBE_RES) &&
                  (frame_subtype != MAN_TYPE_BEACON) &&
                  !((frame_subtype == MAN_TYPE_ACTION) &&
                   (fbuf[0] == WLAN_CATEGORY_PUBLIC) && (fbuf[1] == WLAN_PUB_ACTION_FILS_DISCOVERY)))
              {
                ILOG2_DY("Frame type %d from %Y dropped since master VAP is dummy",
                         frame_type, WLAN_GET_ADDR2(data->buf));
                if (sta) mtlk_sta_decref(sta); /* De-reference of find */
                return MTLK_ERR_OK;
              }

              /* unicast frames can be send directly */
              __mtlk_core_mngmnt_frame_notify(nic, data->buf, data->size, fd.chan->center_freq,
                                              subtype, fd.phy_info, fd.pmf_flags);
            }
          }
        }
      }

      mtlk_core_inc_cnt(nic, MTLK_CORE_CNT_MAN_FRAMES_RECEIVED);

      if (sta) {
        ILOG3_YDDDDDD("STA %Y frame_ctrl 0x%04X, rssi (%d, %d, %d, %d), max_rssi %d",
                    mtlk_sta_get_addr(sta), frame_ctl,
                    phy_info->rssi[0], phy_info->rssi[1], phy_info->rssi[2], phy_info->rssi[3],
                    phy_info->max_rssi);

        mtlk_sta_update_rx_rate_rssi_on_man_frame(sta, phy_info);

        mtlk_sta_decref(sta); /* De-reference of find */
      }
    }
    break;
  case IEEE80211_FTYPE_CTL:
    CPU_STAT_SPECIFY_TRACK(CPU_STAT_ID_RX_CTL);
    res = mtlk_process_ctl_frame(HANDLE_T(nic), data->buf, data->size);
    mtlk_core_inc_cnt(nic, MTLK_CORE_CNT_CTL_FRAMES_RECEIVED);
    break;
  default:
    WLOG_DD("CID-%04x: Not Management or Control packet in BSS RX path, frame_ctl %04x", mtlk_vap_get_oid(nic->vap_handle), frame_ctl);
    mtlk_dump(0, data->buf, MIN(data->size, 128), "RX BSS IND data (first 128 bytes):");
    data->make_assert = TRUE;
    res = MTLK_ERR_CORRUPTED;
  }

  return res;
}

static int
_wave_core_radar_reset_channel (mtlk_core_t *core, struct mtlk_chan_def *ccd, uint8 dfsband)
{
  int res;
  struct set_chan_param_data *cpd = NULL;

  MTLK_ASSERT(core == mtlk_core_get_master(core->vap_handle));

  if (dfsband != ZWDFS_BAND) {  /* Operational band */
    cpd = mtlk_core_chan_param_data_get(core);
    if (cpd && (ST_SCAN != cpd->switch_type))
      cpd = NULL;
  } else {  /* ZWDFS band */
    /* prepare a channel param data for ZWDFS. */
    res = wave_core_set_zwdfs_antenna_enable (core, TRUE, ccd);
    return res;
  }

  res = core_cfg_send_set_chan(core, ccd, cpd);
  if (MTLK_ERR_OK != res)
    ELOG_D("CID-%04x Failed to re-set channel", mtlk_vap_get_oid(core->vap_handle));

  return res;
}

static int
_wave_core_handle_radar_event (mtlk_handle_t core_object, const void *payload, uint32 size)
{
  BOOL emulating, radar_det_enabled;
  uint8 rbm; /* Radar Bit Map */
  struct mtlk_chan_def ccd;
  UMI_RADAR_DETECTION *radar_det;
  mtlk_scan_support_t *ss;
  mtlk_df_t *df;
  mtlk_df_user_t *df_user;
  struct wireless_dev *wdev;
  int cur_channel;
  struct nic *nic = HANDLE_T_PTR(struct nic, core_object);
  wave_radio_t *radio;
  wv_mac80211_t *mac80211;
  struct wiphy *wiphy;

  MTLK_ASSERT(nic == mtlk_core_get_master(nic->vap_handle));
  nic = mtlk_core_get_master(nic->vap_handle);

  radio = wave_vap_radio_get(nic->vap_handle);
  mac80211 = wave_radio_mac80211_get(radio);
  wiphy = wv_mac80211_wiphy_get(mac80211);

  if (mtlk_vap_manager_vap_is_not_ready(mtlk_vap_get_manager(nic->vap_handle), mtlk_vap_get_id(nic->vap_handle))) {
    ELOG_V("Radar detection: interface already deactivated");
    return MTLK_ERR_UNKNOWN;
  }

  ss = mtlk_core_get_scan_support(nic);
  df = mtlk_vap_get_df(nic->vap_handle);
  df_user = mtlk_df_get_user(df);
  wdev = mtlk_df_user_get_wdev(df_user);
  radar_det_enabled = WAVE_RADIO_PDB_GET_INT(radio, PARAM_DB_RADIO_DFS_RADAR_DETECTION);
  ccd = *__wave_core_chandef_get(nic);
  cur_channel = ieee80211_frequency_to_channel(ccd.chan.center_freq); /* Primary channel */

  if (sizeof(UMI_RADAR_DETECTION) == size) {
    radar_det = (UMI_RADAR_DETECTION *)payload;
    emulating = FALSE;
    rbm = MAC_TO_HOST16(radar_det->subBandBitmap);
  } else if (sizeof(mtlk_core_radar_emu_t) == size) { /* Emulating */
    mtlk_core_radar_emu_t *radar_emu = (mtlk_core_radar_emu_t *)payload;
    radar_det = &radar_emu->radar_det;
    rbm = radar_det->subBandBitmap;
    emulating = TRUE;
  } else {
    ELOG_D("Wrong radar event data size %d", size);
    return MTLK_ERR_UNKNOWN;
  }

  RLOG_DDDD("RADAR detected on channel: %u, radar_type: %u, radar bit map 0x%02x, emulated %d",
            radar_det->channel, radar_det->radarType, rbm, emulating);
  if ((wave_radio_is_gen7(radio)) && (!emulating) && (WAVE_RADIO_PDB_GET_INT(radio, PARAM_DB_RADAR_FIFO_DUMP)))
    mtlk_radar_pulses_fifo_dump(core_object, radar_det->dfsband);  /* Included to copy radar signal fifo entries to track false detection */

  if (!radar_det_enabled) {
    if (!emulating) {
      ELOG_V("Radar detected while radar detection is disabled");
      return MTLK_ERR_OK; /* Ignore message */
    } else {
      ILOG0_V("Allowing radar emulation even radar detection is disabled");
    }
  }

  if (WAVE_RADIO_OFF == WAVE_RADIO_PDB_GET_INT(radio, PARAM_DB_RADIO_MODE_CURRENT)) {
    ILOG1_V("Radar detected while RF is off, ignoring");
    goto SET_CHAN; /* Ignore message */
  }

  if (radar_det->dfsband == ZWDFS_BAND) {
    ccd = *__wave_core_zwdfs_chandef_get(nic);
    if (!is_channel_certain(&ccd)) {
      ELOG_V("ZWDFS is not enabled but FW reports radar detection in ZWDFS antenna");
      return MTLK_ERR_OK;
    }

    if (!emulating) {
      /* Adjust radar bitmap according to the BW in zwdfs channel def. This is for the WAR we added
         during set channel for zwdfs. */
      rbm = wv_zwdfs_adjust_radar_bitmap_gen7(&ccd, rbm);
    }

    /* Check whether current DFS channels lies in the radar bitmap. */
    if (!rbm || wv_cfg80211_dfs_validate_radar_bitmap(wiphy, ccd.center_freq1, mtlkcw2cw(ccd.width), &rbm)) {
      ILOG0_V("Radar reported out of current DFS channel in ZWDFS, ignoring");
      goto SET_CHAN; /* Ignore message */
    }

    mtlk_hw_inc_radar_cntr(mtlk_vap_get_hw(nic->vap_handle), radar_det->dfsband); /* Increment radar counter */
    wv_ieee80211_radar_detected(mac80211, &ccd, rbm, TRUE);
    return MTLK_ERR_OK;
  }

  if (cur_channel != radar_det->channel) {
    WLOG_DD("Radar detected on different channel (%u) than current channel (%d)", radar_det->channel, cur_channel);
    goto SET_CHAN; /* Ignore message */
  }

  if (__mtlk_is_sb_dfs_switch(ccd.sb_dfs.sb_dfs_bw)) {
    ccd.center_freq1 = ccd.sb_dfs.center_freq;
    ccd.width = ccd.sb_dfs.width;
  }

  if (!wv_cfg80211_get_chans_dfs_required(wiphy, ccd.center_freq1, mtlkcw2cw(ccd.width))) {
    WLOG_V("Radar detected while operating on non-DFS channels, ignoring");
    return MTLK_ERR_OK; /* Ignore message */
  }

  if (wv_cfg80211_dfs_validate_radar_bitmap(wiphy, ccd.center_freq1, mtlkcw2cw(ccd.width), &rbm))
    goto SET_CHAN; /* Ignore message */

  /* Radar simulation debug switch may take some time,
   * so ignore new event if previous not completed yet */
  if (ss->dfs_debug_params.debug_chan) {
    if (ss->dfs_debug_params.switch_in_progress)
      return MTLK_ERR_OK; /* Ignore message */
    else
      ss->dfs_debug_params.switch_in_progress = TRUE;
  }

  if (wv_mac80211_has_sta_connections(mac80211)) {
    mtlk_hw_inc_radar_cntr(mtlk_vap_get_hw(nic->vap_handle), radar_det->dfsband); /* Increment radar counter */
    ILOG0_V("At least one sta vif is connected to back haul AP, don't notify kernel");
    return wv_mac80211_radar_event_if_sta_connected(mac80211, wdev, &ccd, rbm);
  }

  /* Abort scan in case radar was detected on the current operating channel as hostapd may
   * try to switch to a DFS channel and perform CAC. Do not abort ACS scan, only bg scan */
  if (is_scan_running(ss) && (ss->flags & SDF_BACKGROUND)){
    if (wv_cfg80211_radar_overlaps_chandef(wiphy, ccd.center_freq1,
        mtlkcw2cw(ccd.width), rbm, &ss->orig_chandef)) {
      ILOG0_V("Radar detected during bg scan on the current operating channel, aborting scan.");
      abort_scan_sync(nic);
    } else {
      /* Radar detection during scan can be caused by false detections, report radar event only on operating channels */
      ILOG0_V("Radar detected during bg scan on non-operating ch, do not report radar event.");
      return MTLK_ERR_OK;
    }
  }

  mtlk_hw_inc_radar_cntr(mtlk_vap_get_hw(nic->vap_handle), radar_det->dfsband); /* Increment radar counter */
  wv_ieee80211_radar_detected(mac80211, &ccd, rbm, FALSE);
  return MTLK_ERR_OK;

/* Once radar reported, FW stops reporting radars until next SET_CHANNEL message
 * from driver. So in case we did not forward message to mac80211, but still want
 * to receive radar detect events, send SET_CHANNEL from here */
SET_CHAN:
  return _wave_core_radar_reset_channel(nic, &ccd, radar_det->dfsband);
}

static int
_mtlk_core_add_sta (mtlk_core_t *core, sta_entry * sta, sta_info *info_cfg)
{
#ifdef CPTCFG_IWLWAV_SET_PM_QOS
  BOOL is_empty = mtlk_global_stadb_is_empty();
#endif
  int res = mtlk_stadb_add_sta(&core->slow_ctx->stadb, sta, info_cfg);
  mtlk_osal_copy_eth_addresses(core->slow_ctx->last_sta_addr.au8Addr, (const uint8 *)mtlk_sta_get_addr(sta));
#ifdef CPTCFG_IWLWAV_SET_PM_QOS
  if (!res && is_empty) {
    /* change PM QOS latency, if added very first STA */
    mtlk_mmb_update_cpu_dma_latency(mtlk_vap_get_hw(core->vap_handle), MTLK_HW_PM_QOS_VALUE_ANY_CLIENT);
  }
#endif
  return res;
}

static __INLINE mtlk_error_t __mtlk_core_ap_push_backhaul_sta_to_pending_list (mtlk_core_t *core, sta_entry *backhaul_sta)
/* The vlan/bkh interface has not yet been created, so need to add backhaul_sta to the pending list
   in order to associate it with the bkh interface later after interface creation */
{
  mtlk_df_user_t *df_user = mtlk_df_get_user(mtlk_vap_get_df(core->vap_handle));
  return mtlk_df_user_push_backhaul_sta_to_pending_list(df_user, backhaul_sta);
}

static int _mtlk_core_ap_connect_sta_by_entry (mtlk_core_t *core, struct ieee80211_sta * mac80211_sta)
{
  mtlk_error_t res = MTLK_ERR_PARAMS;
  sta_entry *sta = wv_ieee80211_get_sta(mac80211_sta);
  sta_info * info = &sta->info;
  IEEE_ADDR *addr = (IEEE_ADDR *) mac80211_sta->addr;
  BOOL is_ht_capable;
  uint16 sid = info->sid;
  multi_ap_mode_t multi_ap_mode = MTLK_CORE_HOT_PATH_PDB_GET_INT(core, CORE_DB_CORE_MULTI_AP_MODE);
  BOOL connected_to_backhaul_ap = FALSE;

  if (sta->is_added_to_driver) {
      ELOG_DY("CID-%04x: ERROR:Try to add sta which already exist:%Y", mtlk_vap_get_oid(core->vap_handle), mac80211_sta->addr);
      ASSERT(FALSE);
  }

  /* set WDS flag for peer AP */
  if (mtlk_vap_is_ap(core->vap_handle) &&
      BR_MODE_WDS == MTLK_CORE_HOT_PATH_PDB_GET_INT(core, CORE_DB_CORE_BRIDGE_MODE)){
    MTLK_BFIELD_SET(info->flags, STA_FLAGS_WDS, wds_sta_is_peer_ap(&core->slow_ctx->wds_mng, addr) ? 1 : 0);
  }

  MTLK_BFIELD_SET(info->flags, STA_FLAGS_WDS_WPA, mtlk_core_cfg_wds_wpa_entry_exists(core, addr));

  /* For WDS WPA 4-way Handshake must be in 4-addr mode, otherwise in 3-addr mode:
   *    FOUR_ADDRESSES_STATION - EAPOL 4-way handshake will be in 3-addr mode
   *    WPA_WDS                - EAPOL 4-way handshake will be in 4-addr mode
   * For both cases data afterwards will be sent in 4-addr mode
   */
  if (MULTI_AP_BACKHAUL == multi_ap_mode || core_cfg_four_addr_entry_exists(core, addr))
    info->WDS_client_type = FOUR_ADDRESSES_STATION;
  else if (MTLK_BFIELD_GET(info->flags, STA_FLAGS_WDS_WPA))
    info->WDS_client_type = WPA_WDS;

  sta->secondary_vap_id = mtlk_vap_get_id(core->vap_handle);
  if (mtlk_vap_is_ap(core->vap_handle) &&
      (multi_ap_mode == MULTI_AP_BACKHAUL ||
      (multi_ap_mode == MULTI_AP_EXT_HYBRID && mtlk_sta_info_is_4addr(&sta->info)))) {
    res = mtlk_vap_bind_backhaul_sta(core->vap_handle, sta);
    switch (res) {
      case MTLK_ERR_OK:
        connected_to_backhaul_ap = TRUE;
        break;
      case MTLK_ERR_PENDING:
        ILOG0_DYS("CID-%04x: STA %Y is pending backhaul AP %s ...",
              mtlk_vap_get_oid(core->vap_handle), mtlk_sta_get_addr(sta)->au8Addr, sta->vlan_ifname);
        if (MTLK_ERR_OK != __mtlk_core_ap_push_backhaul_sta_to_pending_list(core, sta)) {
              ELOG_DY("CID-%04x: failed adding STA %Y to pending list",
              mtlk_vap_get_oid(core->vap_handle), mtlk_sta_get_addr(sta)->au8Addr);
              goto FINISH;
        }
        break;
      default:
        ELOG_DY("CID-%04x: Failed to connect STA %Y to backhaul AP",
              mtlk_vap_get_oid(core->vap_handle), mtlk_sta_get_addr(sta)->au8Addr);
        goto FINISH;
    }
  }

  res = mtlk_core_ap_add_sta_req(core, mac80211_sta);
  if (MTLK_ERR_OK != res) {
    goto FINISH;
  }

  /* Remove sta MAC addr from DC DP MAC table */
  mtlk_df_user_dcdp_remove_mac_addr(mtlk_vap_get_secondary_df(core->vap_handle, sta->secondary_vap_id),
                                    addr->au8Addr);

  is_ht_capable = MTLK_BFIELD_GET(info->flags, STA_FLAGS_11n);
  res = _mtlk_core_add_sta(core, sta, info);

  if (res != MTLK_ERR_OK) {
    wave_core_ap_remove_sta(core, sid, addr);
    goto FINISH;
  }

  if (MTLK_BFIELD_GET(info->flags, STA_FLAGS_WDS)) {
    /* WDS peer */
    if (core->slow_ctx->peerAPs_key_idx) {
#ifdef CPTCFG_IWLWAV_WAVE_FPGA
      if (MTLK_ERR_OK != _mtlk_core_set_test_ccmp_key  (core, sta, core->slow_ctx->peerAPs_key_idx - 1)) {
#else
      if (MTLK_ERR_OK != mtlk_core_set_wep_key_blocked(core, &sid, core->slow_ctx->peerAPs_key_idx - 1)) {
#endif

        wds_peer_disconnect (&core->slow_ctx->wds_mng, addr);
        wave_core_ap_stop_traffic(core, sid, addr); /* Send Stop Traffic Request to FW */
        wave_core_ap_remove_sta(core, sid, addr);

        if (connected_to_backhaul_ap) {
          mtlk_vap_unbind_backhaul_sta(core->vap_handle, sta);
        }

        mtlk_stadb_remove_sta(&core->slow_ctx->stadb, sta);
        res = MTLK_ERR_UNKNOWN;
        goto FINISH;
      }

      mtlk_sta_set_cipher(sta, IW_ENCODE_ALG_WEP);
    }
  } else {
    if (core->slow_ctx->wep_enabled) {
      mtlk_sta_set_cipher(sta, IW_ENCODE_ALG_WEP);
    }
  }

  mtlk_sta_set_packets_filter(sta, MTLK_PCKT_FLTR_ALLOW_802_1X);

  if (BR_MODE_WDS == MTLK_CORE_HOT_PATH_PDB_GET_INT(core, CORE_DB_CORE_BRIDGE_MODE) ||
    mtlk_sta_is_4addr(sta)) {
    mtlk_hstdb_start_all_by_sta(&core->slow_ctx->hstdb, addr);
  }
  mtlk_hstdb_remove_host_by_addr(&core->slow_ctx->hstdb, addr);

  if (BR_MODE_WDS == MTLK_CORE_HOT_PATH_PDB_GET_INT(core, CORE_DB_CORE_BRIDGE_MODE)){
    wds_peer_connect(&core->slow_ctx->wds_mng, sta, addr,
                     MTLK_BFIELD_GET(info->flags, STA_FLAGS_11n),
                     MTLK_BFIELD_GET(info->flags, STA_FLAGS_11ac),
#ifdef MTLK_WAVE_700
                     MTLK_BFIELD_GET(info->flags, STA_FLAGS_11be),
#endif
                     MTLK_BFIELD_GET(info->flags, STA_FLAGS_11ax));
  }

  /* notify Traffic Analyzer about new STA */
  mtlk_ta_on_connect(mtlk_vap_get_ta(core->vap_handle), addr, core->vap_handle);

FINISH:
  if (res != MTLK_ERR_OK) {
    if (connected_to_backhaul_ap) {
      mtlk_vap_unbind_backhaul_sta(core->vap_handle, sta);
    }
  }

  mtlk_sta_decref(sta);
  return res;
}

static int _mtlk_core_ap_connect_sta (mtlk_handle_t hcore, const void* data, uint32 data_size)
{
  int res = MTLK_ERR_OK;
  mtlk_core_t *core = HANDLE_T_PTR(mtlk_core_t, hcore);
  mtlk_clpb_t *clpb = *(mtlk_clpb_t **) data;
  struct ieee80211_sta * sta = NULL;
  struct ieee80211_sta ** stapp = NULL;
  uint32 sta_size;

  MTLK_ASSERT(sizeof(mtlk_clpb_t*) == data_size);

  stapp = mtlk_clpb_enum_get_next(clpb, &sta_size);
  MTLK_CLPB_TRY(stapp, sta_size)
    sta = *stapp;
    MTLK_ASSERT(sta != NULL);

    if (mtlk_vap_is_ap(core->vap_handle) && !wave_core_sync_hostapd_done_get(core)) {
      ILOG1_D("CID-%04x: HOSTAPD STA database is not synced", mtlk_vap_get_oid(core->vap_handle));
      MTLK_CLPB_EXIT(MTLK_ERR_NOT_READY);
    } else {
      res = _mtlk_core_ap_connect_sta_by_entry(core, sta);
    }
  MTLK_CLPB_FINALLY(res)
    return mtlk_clpb_push_res(clpb, res);
  MTLK_CLPB_END
}

static mtlk_error_t
_mtlk_core_ap_authorizing_sta (mtlk_handle_t hcore, const void* data, uint32 data_size)
{
  mtlk_error_t res = MTLK_ERR_PARAMS;
  mtlk_core_t *core = HANDLE_T_PTR(mtlk_core_t, hcore);
  mtlk_clpb_t *clpb = *(mtlk_clpb_t **) data;
  mtlk_core_ui_authorizing_cfg_t *t_authorizing;
  uint32       size;
  IEEE_ADDR    sStationID;
  BOOL         authorizing = FALSE;
  sta_entry   *sta = NULL;
  struct ieee80211_sta * mac80211_sta = NULL;
  mtlk_pckt_filter_e       sta_filter_stored;
  uint16 sid;

  MTLK_ASSERT(sizeof(mtlk_clpb_t*) == data_size);

  if (mtlk_vap_is_ap(core->vap_handle) && !wave_core_sync_hostapd_done_get(core)) {
    ILOG1_D("CID-%04x: HOSTAPD STA database is not synced", mtlk_vap_get_oid(core->vap_handle));
    res = MTLK_ERR_NOT_READY;
    goto FINISH;
  }

  if ((mtlk_core_get_net_state(core) & (NET_STATE_READY | NET_STATE_CONNECTED)) == 0) {
    ILOG1_D("CID-%04x: Invalid card state - request rejected", mtlk_vap_get_oid(core->vap_handle));
    res = MTLK_ERR_NOT_READY;
    goto FINISH;
  }

  if (mtlk_core_is_stopping(core)) {
    ILOG1_D("CID-%04x: Can't set authorizing configuration - core is stopping", mtlk_vap_get_oid(core->vap_handle));
    res = MTLK_ERR_NOT_READY;
    goto FINISH;
  }

  t_authorizing = mtlk_clpb_enum_get_next(clpb, &size);
  if ( (NULL == t_authorizing) || (sizeof(*t_authorizing) != size) ) {
    ELOG_D("CID-%04x: Failed to set authorizing configuration parameters from CLPB", mtlk_vap_get_oid(core->vap_handle));
    res = MTLK_ERR_UNKNOWN;
    goto FINISH;
  }

  MTLK_CFG_START_CHEK_ITEM_AND_CALL()
    MTLK_CFG_GET_ITEM(t_authorizing, sta_addr, sStationID);
    MTLK_CFG_GET_ITEM(t_authorizing, authorizing, authorizing);
    MTLK_CFG_GET_ITEM(t_authorizing, sta, mac80211_sta);

  MTLK_CFG_END_CHEK_ITEM_AND_CALL()

  if (mac80211_sta == NULL) {
    ILOG1_DY("CID-%04x: Station %Y not found during authorizing",
              mtlk_vap_get_oid(core->vap_handle), sStationID.au8Addr);
    res = MTLK_ERR_OK;
    goto FINISH;
  }
  sta = wv_ieee80211_get_sta(mac80211_sta);

  if (sta == NULL) {
    ILOG1_DY("CID-%04x: Station %Y not found during authorizing",
             mtlk_vap_get_oid(core->vap_handle), sStationID.au8Addr);
    res = MTLK_ERR_OK;
    goto FINISH;
  }

  /*check if we already have the same filter set */
  sta_filter_stored = mtlk_sta_get_packets_filter(sta);
  sid = mtlk_sta_get_sid(sta);
  if ((MTLK_PCKT_FLTR_ALLOW_ALL == sta_filter_stored) && (authorizing)) {
    ILOG2_DY("CID-%04x: Station %Y has already filter set",
             mtlk_vap_get_oid(core->vap_handle), sStationID.au8Addr);
    res = MTLK_ERR_OK;
    goto FINISH;
  } else if ((MTLK_PCKT_FLTR_ALLOW_802_1X == sta_filter_stored) && (!authorizing)) {
    ILOG2_DY("CID-%04x: Station %Y has already filter set",
             mtlk_vap_get_oid(core->vap_handle), sStationID.au8Addr);

    res = MTLK_ERR_OK;
    goto FINISH;
  }

  res = mtlk_send_filter_req(core, sid, authorizing);

  if(authorizing) {
    mtlk_sta_set_packets_filter(sta, MTLK_PCKT_FLTR_ALLOW_ALL);
    mtlk_df_mcast_notify_sta_connected(mtlk_vap_get_secondary_df(core->vap_handle,
                                       sta->secondary_vap_id));
  } else {
    mtlk_sta_set_packets_filter(sta, MTLK_PCKT_FLTR_ALLOW_802_1X);
  }

FINISH:
  if (NULL != sta) {
    mtlk_sta_decref(sta); /* De-reference of find */
  }
  return res;
}

static int
_mtlk_core_ap_disconnect_sta (mtlk_handle_t hcore, const void* data, uint32 data_size)
{
  mtlk_error_t res = MTLK_ERR_PARAMS;
  mtlk_core_t *core = HANDLE_T_PTR(mtlk_core_t, hcore);
  mtlk_clpb_t *clpb = *(mtlk_clpb_t **) data;
  IEEE_ADDR *addr =NULL;
  struct ieee80211_sta * sta = NULL;
  struct ieee80211_sta ** sta_p = NULL;
  uint32 size;

  MTLK_ASSERT(sizeof(mtlk_clpb_t*) == data_size);

  sta_p = mtlk_clpb_enum_get_next(clpb, &size);
  MTLK_CLPB_TRY(sta_p, size)
    sta = *sta_p;
    MTLK_ASSERT(sta != NULL);
    addr = (IEEE_ADDR *) sta->addr;
    MTLK_ASSERT(addr != NULL);

    res = _mtlk_core_ap_disconnect_sta_blocked(core, sta);

    if (MTLK_ERR_OK != res) {
      ILOG1_DYD("CID-%04x: Station %Y disconnection failed (%d)",
                mtlk_vap_get_oid(core->vap_handle),
                addr, res);
    }
  MTLK_CLPB_FINALLY(res)
    return mtlk_clpb_push_res(clpb, res);
  MTLK_CLPB_END
}

int __MTLK_IFUNC
core_ap_disconnect_all (mtlk_core_t *core)
{
  mtlk_error_t          res = MTLK_ERR_OK;
  const sta_entry      *sta = NULL;
  /* int                   net_state = mtlk_core_get_net_state(nic); */
  mtlk_stadb_iterator_t iter;

  sta = mtlk_stadb_iterate_first(&core->slow_ctx->stadb, &iter);
  if (sta) {
    do {
      /*uint16 sid = mtlk_sta_get_sid(sta);*/
      res = _mtlk_core_ap_disconnect_sta_blocked(core,
              wv_sta_entry_get_mac80211_sta(sta));

      if (res != MTLK_ERR_OK) {
        ELOG_DYD("CID-%04x: Station %Y disconnection failed (%d)",
                mtlk_vap_get_oid(core->vap_handle),
                mtlk_sta_get_addr(sta), res);
        break;
      }

      /* all SIDs will be removed by commands from hostapd */
      /*core_remove_sid(core, sid);*/
      sta = mtlk_stadb_iterate_next(&iter);
    } while (sta);
    mtlk_stadb_iterate_done(&iter);
  }

  return res;
}

static int
_handle_security_alert_ind(mtlk_handle_t object, const void *data,  uint32 data_size)
{
  mtlk_core_t *core = HANDLE_T_PTR(mtlk_core_t, object);
  UMI_TKIP_MIC_FAILURE *usa = (UMI_TKIP_MIC_FAILURE *)data;
  mtlk_df_ui_mic_fail_type_t mic_fail_type;
  sta_entry *sta = NULL;
  mtlk_core_t         *cur_core;
  mtlk_vap_manager_t  *vap_mng;
  mtlk_vap_handle_t   vap_handle;
  unsigned            i, j, max_vaps;
  uint16_t            stationId;

  MTLK_ASSERT(sizeof(UMI_TKIP_MIC_FAILURE) == data_size);

  if (MAX_NUMBER_TKIP_MIC_FAILURE_ENTRIES_IN_MESSAGE < usa->u8numOfValidEntries) {
    ELOG_D("Number of valid entries too big: %d", usa->u8numOfValidEntries);
    mtlk_dump(0, usa, sizeof(*usa), "Dump of UMI_TKIP_MIC_FAILURE");
    return MTLK_ERR_OK;
  }

  vap_mng  = mtlk_vap_get_manager(core->vap_handle);
  max_vaps = mtlk_vap_manager_get_max_vaps_count(vap_mng);

  for (i = 0; i < usa->u8numOfValidEntries; i++) {
    stationId = MAC_TO_HOST16(usa->micFailureEntry[i].stationId);
    for (j = 0; j < max_vaps; j++) {
      if (MTLK_ERR_OK != mtlk_vap_manager_get_vap_handle(vap_mng, j, &vap_handle)) {
        continue;   /* VAP does not exist */
      }
      cur_core = mtlk_vap_get_core(vap_handle);
      if (NET_STATE_CONNECTED != mtlk_core_get_net_state(cur_core)) {
        /* Core is not ready */
        continue;
      }
      sta = mtlk_stadb_find_sid(&cur_core->slow_ctx->stadb, stationId);

      if (sta) {
        mic_fail_type = usa->micFailureEntry[i].isGroupKey ? MIC_FAIL_GROUP : MIC_FAIL_PAIRWISE;
        mtlk_df_ui_notify_mic_failure(mtlk_vap_get_df(vap_handle),
                                   mtlk_sta_get_addr(sta)->au8Addr, mic_fail_type);
        _mtlk_core_on_mic_failure(cur_core, mic_fail_type);
        mtlk_sta_decref(sta); /* De-reference of find */
        break;
      }
    }
  }

  return MTLK_ERR_OK;
}

uint32 hw_get_max_tx_antennas (mtlk_hw_t *hw);
uint32 hw_get_max_rx_antennas (mtlk_hw_t *hw);

uint32 mtlk_core_get_max_tx_antennas (struct nic* nic)
{
  return wave_radio_max_tx_antennas_get(wave_vap_radio_get(nic->vap_handle));
}

uint32 mtlk_core_get_max_rx_antennas (struct nic* nic)
{
  return wave_radio_max_rx_antennas_get(wave_vap_radio_get(nic->vap_handle));
}

uint32 mtlk_core_get_max_tx_ampdu_density (struct nic* nic, uint32 sta_ampdu_density)
{
  return wave_radio_max_tx_ampdu_density_get(wave_vap_radio_get(nic->vap_handle), sta_ampdu_density);
}

/* To keep this valid forever Master VAP slow ctx should only get deleted on card/driver removal */
int current_chandef_init(mtlk_core_t *core, struct mtlk_chan_def *ccd)
{
  UMI_HDK_CONFIG *chc = __wave_core_hdkconfig_get(core);
  uint32 dma_addr;
  mtlk_eeprom_data_t *eeprom = mtlk_core_get_eeprom(core);

  if (MTLK_ERR_OK != mtlk_eeprom_is_valid(eeprom)) {
    ELOG_D("CID-%04x: EEPROM/calibration file info is invalid", mtlk_vap_get_oid(core->vap_handle));
    return MTLK_ERR_UNKNOWN;
  }

  memset(ccd, 0, sizeof(*ccd));
  ccd->power_level = MTLK_POWER_NOT_SET;
  /* mtlk_osal_lock_init(&ccd->chan_lock); */
  __wave_core_chan_switch_type_set(core, ST_NONE);

  memset(chc, 0, sizeof(*chc));
  mtlk_hw_get_prop(mtlk_vap_get_hwapi(core->vap_handle), MTLK_HW_CALIB_BUF_DMA_ADDR, &dma_addr, sizeof(dma_addr));
  chc->calibrationBufferBaseAddress = HOST_TO_MAC32(dma_addr);

  chc->hdkConf.numTxAnts = mtlk_core_get_max_tx_antennas(core);
  chc->hdkConf.numRxAnts = mtlk_core_get_max_rx_antennas(core);
  chc->hdkConf.eepromInfo.u16EEPROMVersion = HOST_TO_MAC16(mtlk_eeprom_get_version(eeprom));

  return MTLK_ERR_OK;
}

/* steps for init and cleanup */
MTLK_INIT_STEPS_LIST_BEGIN(core_slow_ctx)
#ifdef EEPROM_DATA_ACCESS
  MTLK_INIT_STEPS_LIST_ENTRY(core_slow_ctx, EEPROM)
#endif /* EEPROM_DATA_ACCESS */
  MTLK_INIT_STEPS_LIST_ENTRY(core_slow_ctx, SERIALIZER)
  MTLK_INIT_STEPS_LIST_ENTRY(core_slow_ctx, WATCHDOG_TIMER_INIT)
  MTLK_INIT_STEPS_LIST_ENTRY(core_slow_ctx, STADB_INIT)
  MTLK_INIT_STEPS_LIST_ENTRY(core_slow_ctx, HSTDB_INIT)
  MTLK_INIT_STEPS_LIST_ENTRY(core_slow_ctx, BEACON_DATA)
  MTLK_INIT_STEPS_LIST_ENTRY(core_slow_ctx, MGMT_FRAME_FILTER)
  MTLK_INIT_STEPS_LIST_ENTRY(core_slow_ctx, CCA_TIMER_INIT)
  MTLK_INIT_STEPS_LIST_ENTRY(core_slow_ctx, SYNC_HOSTAPD_TIMER_INIT)
  MTLK_INIT_STEPS_LIST_ENTRY(core_slow_ctx, PROBE_RESP_TEMPL)
MTLK_INIT_INNER_STEPS_BEGIN(core_slow_ctx)
MTLK_INIT_STEPS_LIST_END(core_slow_ctx);

static __INLINE
void mem_free_nullsafe(void **ptrptr)
{
  if (*ptrptr) {
    mtlk_osal_mem_free(*ptrptr);
    *ptrptr = NULL;
  }
}

static __INLINE void
__probe_resp_templ_mem_free (struct nic_slow_ctx *slow_ctx)
{
  if (slow_ctx->probe_resp_templ)
    mtlk_osal_mem_free(slow_ctx->probe_resp_templ);

  if (slow_ctx->probe_resp_templ_non_he &&
      (slow_ctx->probe_resp_templ_non_he != slow_ctx->probe_resp_templ))
    mtlk_osal_mem_free(slow_ctx->probe_resp_templ_non_he);

  slow_ctx->probe_resp_templ = NULL;
  slow_ctx->probe_resp_templ_non_he = NULL;
}

static void __MTLK_IFUNC
_mtlk_slow_ctx_cleanup(struct nic_slow_ctx *slow_ctx, struct nic* nic)
{
  MTLK_ASSERT(NULL != slow_ctx);
  MTLK_ASSERT(NULL != nic);

  MTLK_CLEANUP_BEGIN(core_slow_ctx, MTLK_OBJ_PTR(slow_ctx))
    MTLK_CLEANUP_STEP(core_slow_ctx, PROBE_RESP_TEMPL, MTLK_OBJ_PTR(slow_ctx),
                      __probe_resp_templ_mem_free, (slow_ctx));
    MTLK_CLEANUP_STEP(core_slow_ctx, SYNC_HOSTAPD_TIMER_INIT, MTLK_OBJ_PTR(slow_ctx),
                      mtlk_osal_timer_cleanup, (&slow_ctx->sync_hostapd_timer));
    MTLK_CLEANUP_STEP(core_slow_ctx, CCA_TIMER_INIT, MTLK_OBJ_PTR(slow_ctx),
                      mtlk_osal_timer_cleanup, (&slow_ctx->cca_step_down_timer));
    MTLK_CLEANUP_STEP(core_slow_ctx, MGMT_FRAME_FILTER, MTLK_OBJ_PTR(slow_ctx),
                      mgmt_frame_filter_cleanup, (&slow_ctx->mgmt_frame_filter));
    MTLK_CLEANUP_STEP(core_slow_ctx, BEACON_DATA, MTLK_OBJ_PTR(slow_ctx),
                      wave_beacon_man_cleanup, (&slow_ctx->beacon_man_data, nic->vap_handle));
    MTLK_CLEANUP_STEP(core_slow_ctx, HSTDB_INIT, MTLK_OBJ_PTR(slow_ctx),
                      mtlk_hstdb_cleanup, (&slow_ctx->hstdb));
    MTLK_CLEANUP_STEP(core_slow_ctx, STADB_INIT, MTLK_OBJ_PTR(slow_ctx),
                      mtlk_stadb_cleanup, (&slow_ctx->stadb));
    MTLK_CLEANUP_STEP(core_slow_ctx, WATCHDOG_TIMER_INIT, MTLK_OBJ_PTR(slow_ctx),
                      mtlk_osal_timer_cleanup, (&slow_ctx->mac_watchdog_timer));
    MTLK_CLEANUP_STEP(core_slow_ctx, SERIALIZER, MTLK_OBJ_PTR(slow_ctx),
                      mtlk_serializer_cleanup, (&slow_ctx->serializer));
#ifdef EEPROM_DATA_ACCESS
    MTLK_CLEANUP_STEP(core_slow_ctx, EEPROM, MTLK_OBJ_PTR(slow_ctx),
                      mtlk_eeprom_access_cleanup, (nic->vap_handle));
#endif /* EEPROM_DATA_ACCESS */
  MTLK_CLEANUP_END(core_slow_ctx, MTLK_OBJ_PTR(slow_ctx));
}

static int __MTLK_IFUNC
_mtlk_slow_ctx_init(struct nic_slow_ctx *slow_ctx, struct nic* nic)
{
  char ser_name[sizeof(slow_ctx->serializer.name)];

  MTLK_ASSERT(NULL != slow_ctx);
  MTLK_ASSERT(NULL != nic);

  memset(slow_ctx, 0, sizeof(struct nic_slow_ctx));
  slow_ctx->nic = nic;

  mtlk_snprintf(ser_name, sizeof(ser_name), "mtlk_%s", mtlk_df_get_name(mtlk_vap_get_df(nic->vap_handle)));

  MTLK_INIT_TRY(core_slow_ctx, MTLK_OBJ_PTR(slow_ctx))

#ifdef EEPROM_DATA_ACCESS
    MTLK_INIT_STEP_IF(!mtlk_vap_is_slave_ap(nic->vap_handle), core_slow_ctx, EEPROM, MTLK_OBJ_PTR(slow_ctx),
                      mtlk_eeprom_access_init, (nic->vap_handle));
#endif /* EEPROM_DATA_ACCESS */

    MTLK_INIT_STEP(core_slow_ctx, SERIALIZER, MTLK_OBJ_PTR(slow_ctx),
                   mtlk_serializer_init, (&slow_ctx->serializer, ser_name, _MTLK_CORE_NUM_PRIORITIES));

    MTLK_INIT_STEP_IF(!mtlk_vap_is_slave_ap(nic->vap_handle), core_slow_ctx, WATCHDOG_TIMER_INIT, MTLK_OBJ_PTR(slow_ctx),
                      mtlk_osal_timer_init, (&slow_ctx->mac_watchdog_timer,
                                             mac_watchdog_timer_handler,
                                             HANDLE_T(nic)));

    /* TODO MAC80211: is this required for station mode interfaces? */
    MTLK_INIT_STEP(core_slow_ctx, STADB_INIT, MTLK_OBJ_PTR(slow_ctx),
                   mtlk_stadb_init, (&slow_ctx->stadb, nic->vap_handle));

    MTLK_INIT_STEP(core_slow_ctx, HSTDB_INIT, MTLK_OBJ_PTR(slow_ctx),
                   mtlk_hstdb_init, (&slow_ctx->hstdb, nic->vap_handle));

    /* TODO MAC80211: is this required for station mode interfaces? */
    MTLK_INIT_STEP(core_slow_ctx, BEACON_DATA, MTLK_OBJ_PTR(slow_ctx),
                   wave_beacon_man_init, (&slow_ctx->beacon_man_data, nic->vap_handle));

    MTLK_INIT_STEP(core_slow_ctx, MGMT_FRAME_FILTER, MTLK_OBJ_PTR(slow_ctx),
                   mgmt_frame_filter_init, (&slow_ctx->mgmt_frame_filter));

    MTLK_INIT_STEP(core_slow_ctx, CCA_TIMER_INIT, MTLK_OBJ_PTR(slow_ctx),
                   mtlk_osal_timer_init, (&slow_ctx->cca_step_down_timer, cca_step_down_timer_clb_func, HANDLE_T(nic)));

    MTLK_INIT_STEP(core_slow_ctx, SYNC_HOSTAPD_TIMER_INIT, MTLK_OBJ_PTR(slow_ctx),
                      mtlk_osal_timer_init, (&slow_ctx->sync_hostapd_timer, wave_core_sync_hostapd_on_timer, HANDLE_T(nic)));

    /* everything in slow_ctx was memset to 0, so we don't need to set probe_resp_templ to NULL explicitly */
    /* MAC80211 TODO: no need to do that for sta */
    MTLK_INIT_STEP_VOID(core_slow_ctx, PROBE_RESP_TEMPL, MTLK_OBJ_PTR(slow_ctx),
                        MTLK_NOACTION, ());

    nic->slow_ctx->tx_limits.num_tx_antennas = mtlk_core_get_max_tx_antennas(nic);
    nic->slow_ctx->tx_limits.num_rx_antennas = mtlk_core_get_max_rx_antennas(nic);

  MTLK_INIT_FINALLY(core_slow_ctx, MTLK_OBJ_PTR(slow_ctx))
  MTLK_INIT_RETURN(core_slow_ctx, MTLK_OBJ_PTR(slow_ctx), _mtlk_slow_ctx_cleanup, (nic->slow_ctx, nic))
}

static mtlk_error_t
_mtlk_core_crypto_cleanup (mtlk_core_t *core)
{
  return MTLK_ERR_OK;
}

static mtlk_error_t
_mtlk_core_crypto_init (mtlk_core_t *core)
{
  struct nic_slow_ctx *slow_ctx = core->slow_ctx;

  /* start WEP IV from a random value */
  get_random_bytes(&slow_ctx->wep_iv, IEEE80211_WEP_IV_LEN);

  return MTLK_ERR_OK;
}

BOOL __MTLK_IFUNC
mtlk_core_crypto_decrypt(mtlk_core_t *core, uint32 key_idx, uint8 *fbuf, uint8 *data, int32 data_len)
{
struct nic_slow_ctx *slow_ctx = core->slow_ctx;
uint8 rc4key[3 + WAVE_WEP_KEY_WEP2_LENGTH];
uint32 key_len;
uint32 crc;

  /* check the cipher */
  if ((slow_ctx->keys[key_idx].key_len == 0) || ((slow_ctx->keys[key_idx].cipher != SECURITY_TYPE_SECD_WEP104) &&
       (slow_ctx->keys[key_idx].cipher != SECURITY_TYPE_SECD_WEP40))) {
    ILOG1_DDDD("CID-%04x: KEY:%d is not set or cipher is wrong key_len:%d cipher:%d", mtlk_vap_get_oid(core->vap_handle), key_idx, slow_ctx->keys[key_idx].key_len,
            slow_ctx->keys[key_idx].cipher);
    return FALSE;
  }

  key_len =  IEEE80211_WEP_IV_WO_IDX_LEN + slow_ctx->keys[key_idx].key_len;

  /* Prepend 24-bit IV to RC4 key */
  wave_memcpy(rc4key, sizeof(rc4key), fbuf, IEEE80211_WEP_IV_WO_IDX_LEN);

  /* Copy rest of the WEP key (the secret part) */
  wave_memcpy(rc4key + IEEE80211_WEP_IV_WO_IDX_LEN, sizeof(rc4key) - IEEE80211_WEP_IV_WO_IDX_LEN,
      slow_ctx->keys[key_idx].key, slow_ctx->keys[key_idx].key_len);

  arc4_setkey(&slow_ctx->wep_rx, rc4key, key_len);
  arc4_crypt(&slow_ctx->wep_rx, data, data, data_len + 4);
  crc = cpu_to_le32(~crc32_le(~0, data, data_len));
  if (memcmp(&crc, data + data_len, IEEE80211_WEP_ICV_LEN) != 0) {
    /* ICV mismatch */
    ILOG1_D("CID-%04x: ICV mismatch", mtlk_vap_get_oid(core->vap_handle));
    return FALSE;
  }

  return TRUE;
}

/* steps for init and cleanup */
MTLK_INIT_STEPS_LIST_BEGIN(core)
  MTLK_INIT_STEPS_LIST_ENTRY(core, CORE_PDB_INIT)
  MTLK_INIT_STEPS_LIST_ENTRY(core, SLOW_CTX_ALLOC)
  MTLK_INIT_STEPS_LIST_ENTRY(core, SLOW_CTX_INIT)
  MTLK_INIT_STEPS_LIST_ENTRY(core, WSS_CREATE)
  MTLK_INIT_STEPS_LIST_ENTRY(core, WSS_HCTNRs)
  MTLK_INIT_STEPS_LIST_ENTRY(core, TXMM_EEPROM_ASYNC_MSGS_INIT)
  MTLK_INIT_STEPS_LIST_ENTRY(core, CRYPTO_INIT)
  MTLK_INIT_STEPS_LIST_ENTRY(core, BLACKLIST_INIT)
  MTLK_INIT_STEPS_LIST_ENTRY(core, BLACKLIST_LOCK_INIT)
  MTLK_INIT_STEPS_LIST_ENTRY(core, MULTI_AP_BLACKLIST_INIT)
  MTLK_INIT_STEPS_LIST_ENTRY(core, MULTI_AP_BLACKLIST_LOCK_INIT)
  MTLK_INIT_STEPS_LIST_ENTRY(core, 4ADDR_STA_LIST_INIT)
  MTLK_INIT_STEPS_LIST_ENTRY(core, 4ADDR_STA_LIST_LOCK_INIT)
  MTLK_INIT_STEPS_LIST_ENTRY(core, BC_PROBE_REQ_STA_LIST_INIT)
  MTLK_INIT_STEPS_LIST_ENTRY(core, BC_PROBE_REQ_STA_LIST_LOCK_INIT)
  MTLK_INIT_STEPS_LIST_ENTRY(core, UC_PROBE_REQ_STA_LIST_INIT)
  MTLK_INIT_STEPS_LIST_ENTRY(core, UC_PROBE_REQ_STA_LIST_LOCK_INIT)
  MTLK_INIT_STEPS_LIST_ENTRY(core, NDP_WDS_WPA_STA_LIST_INIT)
  MTLK_INIT_STEPS_LIST_ENTRY(core, NDP_WDS_WPA_STA_LIST_LOCK_INIT)
  MTLK_INIT_STEPS_LIST_ENTRY(core, ACL_LIST_INIT)
  MTLK_INIT_STEPS_LIST_ENTRY(core, ACL_LOCK_INIT)
  MTLK_INIT_STEPS_LIST_ENTRY(core, NDP_ACKED)
  MTLK_INIT_STEPS_LIST_ENTRY(core, EAPOL_ACKED)
MTLK_INIT_INNER_STEPS_BEGIN(core)
MTLK_INIT_STEPS_LIST_END(core);

static void __MTLK_IFUNC
_mtlk_core_cleanup(struct nic* nic)
{
  unsigned i;

  MTLK_ASSERT(NULL != nic);

  /* delete all four address list entries */
  core_cfg_flush_four_addr_list(nic);
  /* delete all blacklist entries */
  _mtlk_core_flush_ieee_addr_list(nic, &nic->widan_blacklist, "widan black");
  _mtlk_core_flush_ieee_addr_list(nic, &nic->multi_ap_blacklist, "multi-AP black");
  _mtlk_core_flush_bcast_probe_resp_list(nic);
  _mtlk_core_flush_ucast_probe_resp_list(nic);
  mtlk_core_cfg_flush_wds_wpa_list(nic);
  _mtlk_core_flush_acl_list(nic);
  mtlk_osal_event_terminate(&nic->ndp_acked);
  mtlk_osal_event_terminate(&nic->eapol_acked);

  if (BR_MODE_WDS == MTLK_CORE_PDB_GET_INT(nic, PARAM_DB_CORE_BRIDGE_MODE)) {
    mtlk_vap_manager_dec_wds_bridgemode(mtlk_vap_get_manager(nic->vap_handle));
  }

  MTLK_CLEANUP_BEGIN(core, MTLK_OBJ_PTR(nic))

    MTLK_CLEANUP_STEP(core, EAPOL_ACKED, MTLK_OBJ_PTR(nic),
      mtlk_osal_event_cleanup, (&nic->eapol_acked));

    MTLK_CLEANUP_STEP(core, NDP_ACKED, MTLK_OBJ_PTR(nic),
      mtlk_osal_event_cleanup, (&nic->ndp_acked));

    MTLK_CLEANUP_STEP(core, ACL_LOCK_INIT, MTLK_OBJ_PTR(nic),
      mtlk_osal_lock_cleanup, (&nic->acl.mac_list.ieee_addr_lock));

    MTLK_CLEANUP_STEP(core, ACL_LIST_INIT, MTLK_OBJ_PTR(nic),
      mtlk_hash_cleanup_ieee_addr, (&nic->acl.mac_list.hash));

    MTLK_CLEANUP_STEP(core, NDP_WDS_WPA_STA_LIST_LOCK_INIT, MTLK_OBJ_PTR(nic),
      mtlk_osal_lock_cleanup, (&nic->wds_wpa_sta_list.ieee_addr_lock));

    MTLK_CLEANUP_STEP(core, NDP_WDS_WPA_STA_LIST_INIT, MTLK_OBJ_PTR(nic),
      mtlk_hash_cleanup_ieee_addr, (&nic->wds_wpa_sta_list.hash));

    MTLK_CLEANUP_STEP(core, UC_PROBE_REQ_STA_LIST_LOCK_INIT, MTLK_OBJ_PTR(nic),
      mtlk_osal_lock_cleanup, (&nic->unicast_probe_resp_sta_list.ieee_addr_lock));

    MTLK_CLEANUP_STEP(core, UC_PROBE_REQ_STA_LIST_INIT, MTLK_OBJ_PTR(nic),
      mtlk_hash_cleanup_ieee_addr, (&nic->unicast_probe_resp_sta_list.hash));

    MTLK_CLEANUP_STEP(core, BC_PROBE_REQ_STA_LIST_LOCK_INIT, MTLK_OBJ_PTR(nic),
      mtlk_osal_lock_cleanup, (&nic->broadcast_probe_resp_sta_list.ieee_addr_lock));

    MTLK_CLEANUP_STEP(core, BC_PROBE_REQ_STA_LIST_INIT, MTLK_OBJ_PTR(nic),
      mtlk_hash_cleanup_ieee_addr, (&nic->broadcast_probe_resp_sta_list.hash));

    MTLK_CLEANUP_STEP(core, 4ADDR_STA_LIST_LOCK_INIT, MTLK_OBJ_PTR(nic),
      mtlk_osal_lock_cleanup, (&nic->four_addr_sta_list.ieee_addr_lock));

    MTLK_CLEANUP_STEP(core, 4ADDR_STA_LIST_INIT, MTLK_OBJ_PTR(nic),
      mtlk_hash_cleanup_ieee_addr, (&nic->four_addr_sta_list.hash));

    MTLK_CLEANUP_STEP(core, MULTI_AP_BLACKLIST_LOCK_INIT, MTLK_OBJ_PTR(nic),
      mtlk_osal_lock_cleanup, (&nic->multi_ap_blacklist.ieee_addr_lock));

    MTLK_CLEANUP_STEP(core, MULTI_AP_BLACKLIST_INIT, MTLK_OBJ_PTR(nic),
      mtlk_hash_cleanup_ieee_addr, (&nic->multi_ap_blacklist.hash));

    MTLK_CLEANUP_STEP(core, BLACKLIST_LOCK_INIT, MTLK_OBJ_PTR(nic),
      mtlk_osal_lock_cleanup, (&nic->widan_blacklist.ieee_addr_lock));

    MTLK_CLEANUP_STEP(core, BLACKLIST_INIT, MTLK_OBJ_PTR(nic),
      mtlk_hash_cleanup_ieee_addr, (&nic->widan_blacklist.hash));

    MTLK_CLEANUP_STEP(core, CRYPTO_INIT, MTLK_OBJ_PTR(nic), _mtlk_core_crypto_cleanup, (nic));

    for (i = 0; i < MTLK_ARRAY_SIZE(nic->txmm_async_eeprom_msgs); i++) {
      MTLK_CLEANUP_STEP_LOOP(core, TXMM_EEPROM_ASYNC_MSGS_INIT, MTLK_OBJ_PTR(nic),
                             mtlk_txmm_msg_cleanup, (&nic->txmm_async_eeprom_msgs[i]));
    }

    MTLK_CLEANUP_STEP(core, WSS_HCTNRs, MTLK_OBJ_PTR(nic),
                      mtlk_wss_cntrs_close, (nic->wss, nic->wss_hcntrs, ARRAY_SIZE(nic->wss_hcntrs)))

    MTLK_CLEANUP_STEP(core, WSS_CREATE, MTLK_OBJ_PTR(nic),
                      mtlk_wss_delete, (nic->wss));

    MTLK_CLEANUP_STEP(core, SLOW_CTX_INIT, MTLK_OBJ_PTR(nic),
                      _mtlk_slow_ctx_cleanup, (nic->slow_ctx, nic));

    MTLK_CLEANUP_STEP(core, SLOW_CTX_ALLOC, MTLK_OBJ_PTR(nic),
                      kfree_tag, (nic->slow_ctx));

    MTLK_CLEANUP_STEP(core, CORE_PDB_INIT, MTLK_OBJ_PTR(nic),
        mtlk_core_pdb_fast_handles_close, (nic->pdb_hot_path_handles));

  MTLK_CLEANUP_END(core, MTLK_OBJ_PTR(nic));
}

static int __MTLK_IFUNC
_mtlk_core_init(struct nic* nic, mtlk_vap_handle_t vap_handle, mtlk_df_t*   df)
{
  unsigned txem_cnt = 0;

  MTLK_ASSERT(NULL != nic);

  MTLK_STATIC_ASSERT(MTLK_CORE_CNT_LAST == ARRAY_SIZE(nic->wss_hcntrs));
  MTLK_STATIC_ASSERT(MTLK_CORE_CNT_LAST == ARRAY_SIZE(_mtlk_core_wss_id_map));

  MTLK_INIT_TRY(core, MTLK_OBJ_PTR(nic))
    /* set initial net state */
    mtlk_osal_atomic_set(&nic->net_state, NET_STATE_HALTED);
    nic->vap_handle  = vap_handle;

    nic->radio_wss = wave_radio_wss_get(wave_vap_radio_get(nic->vap_handle)); /* Get parent WSS from Radio */
    MTLK_ASSERT(NULL != nic->radio_wss);

    MTLK_INIT_STEP(core, CORE_PDB_INIT, MTLK_OBJ_PTR(nic),
        mtlk_core_pdb_fast_handles_open, (mtlk_vap_get_param_db(nic->vap_handle), nic->pdb_hot_path_handles));

    MTLK_INIT_STEP_EX(core, SLOW_CTX_ALLOC, MTLK_OBJ_PTR(nic),
                      kmalloc_tag, (sizeof(struct nic_slow_ctx), GFP_KERNEL, MTLK_MEM_TAG_CORE),
                      nic->slow_ctx, NULL != nic->slow_ctx, MTLK_ERR_NO_MEM);

    MTLK_INIT_STEP(core, SLOW_CTX_INIT, MTLK_OBJ_PTR(nic),
                   _mtlk_slow_ctx_init, (nic->slow_ctx, nic));

    MTLK_INIT_STEP_EX(core, WSS_CREATE, MTLK_OBJ_PTR(nic),
                      mtlk_wss_create, (nic->radio_wss, _mtlk_core_wss_id_map, ARRAY_SIZE(_mtlk_core_wss_id_map)),
                      nic->wss, nic->wss != NULL, MTLK_ERR_NO_MEM);

    MTLK_INIT_STEP(core, WSS_HCTNRs, MTLK_OBJ_PTR(nic),
                   mtlk_wss_cntrs_open, (nic->wss, _mtlk_core_wss_id_map, nic->wss_hcntrs, MTLK_CORE_CNT_LAST));

    for (txem_cnt = 0; txem_cnt < ARRAY_SIZE(nic->txmm_async_eeprom_msgs); txem_cnt++) {
      MTLK_INIT_STEP_LOOP(core, TXMM_EEPROM_ASYNC_MSGS_INIT, MTLK_OBJ_PTR(nic),
                          mtlk_txmm_msg_init, (&nic->txmm_async_eeprom_msgs[txem_cnt]));
    }

    MTLK_INIT_STEP(core, CRYPTO_INIT, MTLK_OBJ_PTR(nic), _mtlk_core_crypto_init, (nic));

    MTLK_INIT_STEP_VOID(core, BLACKLIST_INIT, MTLK_OBJ_PTR(nic),
      mtlk_hash_init_ieee_addr, (&nic->widan_blacklist.hash,
        MTLK_CORE_WIDAN_BLACKLIST_HASH_NOF_BUCKETS));

    MTLK_INIT_STEP(core, BLACKLIST_LOCK_INIT, MTLK_OBJ_PTR(nic),
      mtlk_osal_lock_init, (&nic->widan_blacklist.ieee_addr_lock));

    MTLK_INIT_STEP_VOID(core, MULTI_AP_BLACKLIST_INIT, MTLK_OBJ_PTR(nic),
      mtlk_hash_init_ieee_addr, (&nic->multi_ap_blacklist.hash,
        MTLK_CORE_STA_LIST_HASH_NOF_BUCKETS));

    MTLK_INIT_STEP(core, MULTI_AP_BLACKLIST_LOCK_INIT, MTLK_OBJ_PTR(nic),
      mtlk_osal_lock_init, (&nic->multi_ap_blacklist.ieee_addr_lock));

    MTLK_INIT_STEP_VOID(core, 4ADDR_STA_LIST_INIT, MTLK_OBJ_PTR(nic),
      mtlk_hash_init_ieee_addr, (&nic->four_addr_sta_list.hash,
        MTLK_CORE_4ADDR_STA_LIST_HASH_NOF_BUCKETS));

    MTLK_INIT_STEP(core, 4ADDR_STA_LIST_LOCK_INIT, MTLK_OBJ_PTR(nic),
      mtlk_osal_lock_init, (&nic->four_addr_sta_list.ieee_addr_lock));

    MTLK_INIT_STEP_VOID(core, BC_PROBE_REQ_STA_LIST_INIT, MTLK_OBJ_PTR(nic),
      mtlk_hash_init_ieee_addr, (&nic->broadcast_probe_resp_sta_list.hash,
        MTLK_CORE_STA_LIST_HASH_NOF_BUCKETS));

    MTLK_INIT_STEP(core, BC_PROBE_REQ_STA_LIST_LOCK_INIT, MTLK_OBJ_PTR(nic),
      mtlk_osal_lock_init, (&nic->broadcast_probe_resp_sta_list.ieee_addr_lock));

    MTLK_INIT_STEP_VOID(core, UC_PROBE_REQ_STA_LIST_INIT, MTLK_OBJ_PTR(nic),
      mtlk_hash_init_ieee_addr, (&nic->unicast_probe_resp_sta_list.hash,
        MTLK_CORE_STA_LIST_HASH_NOF_BUCKETS));

    MTLK_INIT_STEP(core, UC_PROBE_REQ_STA_LIST_LOCK_INIT, MTLK_OBJ_PTR(nic),
      mtlk_osal_lock_init, (&nic->unicast_probe_resp_sta_list.ieee_addr_lock));

    MTLK_INIT_STEP_VOID(core, NDP_WDS_WPA_STA_LIST_INIT, MTLK_OBJ_PTR(nic),
      mtlk_hash_init_ieee_addr, (&nic->wds_wpa_sta_list.hash,
        MTLK_CORE_4ADDR_STA_LIST_HASH_NOF_BUCKETS));

    MTLK_INIT_STEP(core, NDP_WDS_WPA_STA_LIST_LOCK_INIT, MTLK_OBJ_PTR(nic),
      mtlk_osal_lock_init, (&nic->wds_wpa_sta_list.ieee_addr_lock));

    MTLK_INIT_STEP_VOID(core, ACL_LIST_INIT, MTLK_OBJ_PTR(nic),
      mtlk_hash_init_ieee_addr, (&nic->acl.mac_list.hash, MTLK_CORE_ACL_HASH_NOF_BUCKETS));

    MTLK_INIT_STEP(core, ACL_LOCK_INIT, MTLK_OBJ_PTR(nic),
      mtlk_osal_lock_init, (&nic->acl.mac_list.ieee_addr_lock));

    MTLK_INIT_STEP(core, NDP_ACKED, MTLK_OBJ_PTR(nic),
      mtlk_osal_event_init, (&nic->ndp_acked));

    MTLK_INIT_STEP(core, EAPOL_ACKED, MTLK_OBJ_PTR(nic),
      mtlk_osal_event_init, (&nic->eapol_acked));

    nic->is_stopped = TRUE;
    ILOG1_SDDDS("%s: Inited: is_stopped=%u, is_stopping=%u, is_iface_stopping=%u, net_state=%s",
                mtlk_df_get_name(mtlk_vap_get_df(nic->vap_handle)),
                nic->is_stopped, nic->is_stopping, nic->is_iface_stopping,
                mtlk_net_state_to_string(mtlk_core_get_net_state(nic)));

  MTLK_INIT_FINALLY(core, MTLK_OBJ_PTR(nic))
  MTLK_INIT_RETURN(core, MTLK_OBJ_PTR(nic), _mtlk_core_cleanup, (nic))
}

int __MTLK_IFUNC
mtlk_core_api_init (mtlk_vap_handle_t vap_handle, mtlk_core_api_t *core_api, mtlk_df_t* df)
{
  int res;
  mtlk_core_t *core;

  MTLK_ASSERT(NULL != core_api);

  /* initialize function table */
  core_api->vft = &core_vft;

  core = mtlk_osal_mem_alloc(sizeof(mtlk_core_t), MTLK_MEM_TAG_USER_CORE);
  if(NULL == core) {
    return MTLK_ERR_NO_MEM;
  }

  memset(core, 0, sizeof(mtlk_core_t));

  res = _mtlk_core_init(core, vap_handle, df);
  if (MTLK_ERR_OK != res) {
    mtlk_osal_mem_free(core);
    return res;
  }

  core_api->core_handle = HANDLE_T(core);

  return MTLK_ERR_OK;
}

static int
mtlk_core_master_set_default_band(struct nic *nic)
{
  uint8 freq_band_cfg = MTLK_HW_BAND_NONE;
  wave_radio_t *radio = wave_vap_radio_get(nic->vap_handle);

  MTLK_ASSERT(!mtlk_vap_is_slave_ap(nic->vap_handle));

  if (mtlk_core_is_band_supported(nic, MTLK_HW_BAND_2_4_5_2_GHZ) == MTLK_ERR_OK) {
     freq_band_cfg = MTLK_HW_BAND_2_4_5_2_GHZ;
  } else if (mtlk_core_is_band_supported(nic, MTLK_HW_BAND_2_4_6_GHZ) == MTLK_ERR_OK) {
     freq_band_cfg = MTLK_HW_BAND_2_4_6_GHZ;
  } else if (mtlk_core_is_band_supported(nic, MTLK_HW_BAND_5_2_6_GHZ) == MTLK_ERR_OK) {
     freq_band_cfg = MTLK_HW_BAND_5_2_6_GHZ;
  } else if (mtlk_core_is_band_supported(nic, MTLK_HW_BAND_5_2_GHZ) == MTLK_ERR_OK) {
    freq_band_cfg = MTLK_HW_BAND_5_2_GHZ;
  } else if (mtlk_core_is_band_supported(nic, MTLK_HW_BAND_2_4_GHZ) == MTLK_ERR_OK) {
    freq_band_cfg = MTLK_HW_BAND_2_4_GHZ;
  } else if (mtlk_core_is_band_supported(nic, MTLK_HW_BAND_6_GHZ) == MTLK_ERR_OK) {
    freq_band_cfg = MTLK_HW_BAND_6_GHZ;
  } else {
    ELOG_D("CID-%04x: None of the bands is supported", mtlk_vap_get_oid(nic->vap_handle));
    return MTLK_ERR_UNKNOWN;
  }

  WAVE_RADIO_PDB_SET_INT(radio, PARAM_DB_RADIO_FREQ_BAND_CFG, freq_band_cfg);
  WAVE_RADIO_PDB_SET_INT(radio, PARAM_DB_RADIO_FREQ_BAND_CUR, freq_band_cfg);

  return MTLK_ERR_OK;
}

static int
mtlk_core_set_default_net_mode(struct nic *nic)
{
  uint8 freq_band_cfg = MTLK_HW_BAND_NONE;
  uint8 net_mode = MTLK_NETWORK_NONE;
  mtlk_core_t *core_master = NULL;

  MTLK_ASSERT(nic != NULL);

  if(mtlk_vap_is_master(nic->vap_handle)) {
    /* Set default mode based on band
     * for Master AP or STA */
    freq_band_cfg = core_cfg_get_freq_band_cfg(nic);
    net_mode = get_net_mode(freq_band_cfg, TRUE);
  } else {
    /* Copy default mode from Master VAP.
     * This is important while scripts
     * are not ready for network mode per VAP. */
    core_master = mtlk_core_get_master(nic->vap_handle);
    MTLK_ASSERT(core_master != NULL);
    net_mode = core_cfg_get_network_mode_cfg(core_master);
  }

  MTLK_CORE_PDB_SET_INT(nic, PARAM_DB_CORE_NET_MODE_CUR, net_mode);
  MTLK_CORE_PDB_SET_INT(nic, PARAM_DB_CORE_NET_MODE_CFG, net_mode);

  return MTLK_ERR_OK;
}

MTLK_START_STEPS_LIST_BEGIN(core_slow_ctx)
  MTLK_START_STEPS_LIST_ENTRY(core_slow_ctx, SERIALIZER_START)
  MTLK_START_STEPS_LIST_ENTRY(core_slow_ctx, SET_MAC_MAC_ADDR)
  MTLK_START_STEPS_LIST_ENTRY(core_slow_ctx, PARSE_EE_DATA)
  MTLK_START_STEPS_LIST_ENTRY(core_slow_ctx, PROCESS_ANTENNA_CFG)
#ifdef CPTCFG_IWLWAV_PMCU_SUPPORT
#ifdef CONFIG_WAVE_DEBUG
  MTLK_START_STEPS_LIST_ENTRY(core_slow_ctx, PROCESS_PCOC)
#endif
#endif /*CPTCFG_IWLWAV_PMCU_SUPPORT*/
  MTLK_START_STEPS_LIST_ENTRY(core_slow_ctx, WDS_INIT)
  MTLK_START_STEPS_LIST_ENTRY(core_slow_ctx, SET_DEFAULT_BAND)
  MTLK_START_STEPS_LIST_ENTRY(core_slow_ctx, SET_DEFAULT_NET_MODE)
  MTLK_START_STEPS_LIST_ENTRY(core_slow_ctx, WATCHDOG_TIMER_START)
  MTLK_START_STEPS_LIST_ENTRY(core_slow_ctx, SERIALIZER_ACTIVATE)
MTLK_START_INNER_STEPS_BEGIN(core_slow_ctx)
MTLK_START_STEPS_LIST_END(core_slow_ctx);

#ifdef CPTCFG_IWLWAV_PMCU_SUPPORT
#ifdef CONFIG_WAVE_DEBUG
static const mtlk_ability_id_t _core_pmcu_abilities[] = {
  WAVE_RADIO_REQ_GET_PCOC_CFG,
  WAVE_RADIO_REQ_SET_PCOC_CFG
};

void __MTLK_IFUNC mtlk_core_pmcu_register_vap(mtlk_vap_handle_t vap_handle)
{
  mtlk_abmgr_register_ability_set(mtlk_vap_get_abmgr(vap_handle),
                    _core_pmcu_abilities, ARRAY_SIZE(_core_pmcu_abilities));
  mtlk_abmgr_enable_ability_set(mtlk_vap_get_abmgr(vap_handle),
                    _core_pmcu_abilities, ARRAY_SIZE(_core_pmcu_abilities));
}

void __MTLK_IFUNC mtlk_core_pmcu_unregister_vap(mtlk_vap_handle_t vap_handle)
{
  mtlk_abmgr_disable_ability_set(mtlk_vap_get_abmgr(vap_handle),
                    _core_pmcu_abilities, ARRAY_SIZE(_core_pmcu_abilities));
  mtlk_abmgr_unregister_ability_set(mtlk_vap_get_abmgr(vap_handle),
                    _core_pmcu_abilities, ARRAY_SIZE(_core_pmcu_abilities));
}
#endif /* CONFIG_WAVE_DEBUG */
#endif /*CPTCFG_IWLWAV_PMCU_SUPPORT*/

static void __MTLK_IFUNC
_mtlk_slow_ctx_stop(struct nic_slow_ctx *slow_ctx, struct nic* nic)
{
  MTLK_ASSERT(NULL != slow_ctx);
  MTLK_ASSERT(NULL != nic);

  MTLK_STOP_BEGIN(core_slow_ctx, MTLK_OBJ_PTR(slow_ctx))

    MTLK_STOP_STEP(core_slow_ctx, SERIALIZER_ACTIVATE, MTLK_OBJ_PTR(slow_ctx),
                   mtlk_serializer_stop, (&slow_ctx->serializer))

    MTLK_STOP_STEP(core_slow_ctx, WATCHDOG_TIMER_START, MTLK_OBJ_PTR(slow_ctx),
                   mtlk_osal_timer_cancel_sync, (&slow_ctx->mac_watchdog_timer))

    MTLK_STOP_STEP(core_slow_ctx, SET_DEFAULT_NET_MODE, MTLK_OBJ_PTR(slow_ctx),
                   MTLK_NOACTION, ())

    MTLK_STOP_STEP(core_slow_ctx, SET_DEFAULT_BAND, MTLK_OBJ_PTR(slow_ctx),
                   MTLK_NOACTION, ())

    MTLK_STOP_STEP(core_slow_ctx, WDS_INIT, MTLK_OBJ_PTR(slow_ctx),
                   wds_cleanup, (&slow_ctx->wds_mng))
#ifdef CPTCFG_IWLWAV_PMCU_SUPPORT
#ifdef CONFIG_WAVE_DEBUG
    MTLK_STOP_STEP(core_slow_ctx, PROCESS_PCOC, MTLK_OBJ_PTR(slow_ctx),
                               mtlk_core_pmcu_unregister_vap, (nic->vap_handle))
#endif
#endif /*CPTCFG_IWLWAV_PMCU_SUPPORT*/

    MTLK_STOP_STEP(core_slow_ctx, PROCESS_ANTENNA_CFG, MTLK_OBJ_PTR(slow_ctx),
                   MTLK_NOACTION, ())

    MTLK_STOP_STEP(core_slow_ctx, PARSE_EE_DATA, MTLK_OBJ_PTR(slow_ctx),
                   MTLK_NOACTION, ())

    MTLK_STOP_STEP(core_slow_ctx, SET_MAC_MAC_ADDR, MTLK_OBJ_PTR(slow_ctx),
                   MTLK_NOACTION, ())

    MTLK_STOP_STEP(core_slow_ctx, SERIALIZER_START, MTLK_OBJ_PTR(slow_ctx),
                   MTLK_NOACTION, ())
  MTLK_STOP_END(core_slow_ctx, MTLK_OBJ_PTR(slow_ctx))
}

static int __MTLK_IFUNC
_mtlk_slow_ctx_start(struct nic_slow_ctx *slow_ctx, struct nic* nic)
{
  int cache_param;
  mtlk_eeprom_data_t *eeprom_data;
  mtlk_txmm_t *txmm;
  BOOL is_dut;
  BOOL is_master;
  int res = MTLK_ERR_OK;

  MTLK_ASSERT(NULL != slow_ctx);
  MTLK_ASSERT(NULL != nic);

  MTLK_UNREFERENCED_PARAM(res);

  txmm = mtlk_vap_get_txmm(nic->vap_handle);
  is_dut = mtlk_vap_is_dut(nic->vap_handle);
  is_master = mtlk_vap_is_master (nic->vap_handle);

  MTLK_START_TRY(core_slow_ctx, MTLK_OBJ_PTR(slow_ctx))
    MTLK_START_STEP(core_slow_ctx, SERIALIZER_START, MTLK_OBJ_PTR(slow_ctx),
                    mtlk_serializer_start, (&slow_ctx->serializer))

    eeprom_data = mtlk_core_get_eeprom(nic);

    MTLK_START_STEP_IF(!is_dut && is_master, core_slow_ctx, SET_MAC_MAC_ADDR, MTLK_OBJ_PTR(slow_ctx),
                       core_cfg_set_mac_addr, (nic, (char *)mtlk_eeprom_get_nic_mac_addr(eeprom_data)))

    MTLK_START_STEP_IF(!is_dut && is_master, core_slow_ctx, PARSE_EE_DATA, MTLK_OBJ_PTR(slow_ctx),
                       mtlk_eeprom_check_ee_data, (eeprom_data, txmm, mtlk_vap_is_ap(nic->vap_handle)))

    core_cfg_country_code_set_default(nic);

    if (mtlk_vap_is_ap(nic->vap_handle)) {
      cache_param = 0;
    } else {
      cache_param = SCAN_CACHE_AGEING;
    }

    MTLK_START_STEP_VOID(core_slow_ctx, PROCESS_ANTENNA_CFG, MTLK_OBJ_PTR(slow_ctx),
                         MTLK_NOACTION, ())

    SLOG0(SLOG_DFLT_ORIGINATOR, SLOG_DFLT_RECEIVER, tx_limit_t, &nic->slow_ctx->tx_limits);

#ifdef CPTCFG_IWLWAV_PMCU_SUPPORT
#ifdef CONFIG_WAVE_DEBUG
    MTLK_START_STEP_VOID_IF((is_master), core_slow_ctx, PROCESS_PCOC,
        MTLK_OBJ_PTR(slow_ctx), mtlk_core_pmcu_register_vap, (nic->vap_handle));
#endif
#endif /*CPTCFG_IWLWAV_PMCU_SUPPORT*/

    MTLK_START_STEP_IF(mtlk_vap_is_ap(nic->vap_handle), core_slow_ctx, WDS_INIT, MTLK_OBJ_PTR(slow_ctx),
                       wds_init, (&slow_ctx->wds_mng, nic->vap_handle))

    MTLK_START_STEP_IF(!is_dut && is_master, core_slow_ctx, SET_DEFAULT_BAND, MTLK_OBJ_PTR(slow_ctx),
                       mtlk_core_master_set_default_band, (nic))

    MTLK_START_STEP(core_slow_ctx, SET_DEFAULT_NET_MODE, MTLK_OBJ_PTR(slow_ctx),
                    mtlk_core_set_default_net_mode, (nic))

    MTLK_START_STEP_IF(is_master, core_slow_ctx, WATCHDOG_TIMER_START, MTLK_OBJ_PTR(slow_ctx),
                       mtlk_osal_timer_set,
                       (&slow_ctx->mac_watchdog_timer,
                       WAVE_RADIO_PDB_GET_INT(wave_vap_radio_get(nic->vap_handle), PARAM_DB_RADIO_MAC_WATCHDOG_TIMER_PERIOD_MS)))

    MTLK_START_STEP_VOID(core_slow_ctx, SERIALIZER_ACTIVATE, MTLK_OBJ_PTR(slow_ctx),
                         MTLK_NOACTION, ())

  MTLK_START_FINALLY(core_slow_ctx, MTLK_OBJ_PTR(slow_ctx))
  MTLK_START_RETURN(core_slow_ctx, MTLK_OBJ_PTR(slow_ctx), _mtlk_slow_ctx_stop, (slow_ctx, nic))
}

MTLK_START_STEPS_LIST_BEGIN(core)
  MTLK_START_STEPS_LIST_ENTRY(core, SET_NET_STATE_IDLE)
  MTLK_START_STEPS_LIST_ENTRY(core, SLOW_CTX_START)
  MTLK_START_STEPS_LIST_ENTRY(core, RESET_STATS)
  MTLK_START_STEPS_LIST_ENTRY(core, MC_INIT)
  MTLK_START_STEPS_LIST_ENTRY(core, DUT_REGISTER)
  MTLK_START_STEPS_LIST_ENTRY(core, CORE_ABILITIES_INIT)
  MTLK_START_STEPS_LIST_ENTRY(core, RADIO_ABILITIES_INIT)
  MTLK_START_STEPS_LIST_ENTRY(core, SET_NET_STATE_READY)
  MTLK_START_STEPS_LIST_ENTRY(core, INIT_DEFAULTS)
  MTLK_START_STEPS_LIST_ENTRY(core, CHECK_TPC_LOOP_TYPE)
MTLK_START_INNER_STEPS_BEGIN(core)
MTLK_START_STEPS_LIST_END(core);

static void
_mtlk_core_stop (mtlk_vap_handle_t vap_handle)
{
  mtlk_core_t *nic = mtlk_vap_get_core (vap_handle);
  unsigned i;

  ILOG0_D("CID-%04x: stop", mtlk_vap_get_oid(vap_handle));

  /*send RMMOD event to application*/
  if (!mtlk_core_is_hw_halted(nic) && mtlk_vap_is_ap(vap_handle)) {
    ILOG4_V("RMMOD send event");
    mtlk_df_ui_notify_notify_rmmod(mtlk_df_get_name(mtlk_vap_get_df(vap_handle)));
  }

  MTLK_STOP_BEGIN(core, MTLK_OBJ_PTR(nic))
    MTLK_STOP_STEP(core, CHECK_TPC_LOOP_TYPE, MTLK_OBJ_PTR(nic),
                   MTLK_NOACTION, ())

    MTLK_STOP_STEP(core, INIT_DEFAULTS, MTLK_OBJ_PTR(nic),
                   MTLK_NOACTION, ())

    MTLK_STOP_STEP(core, SET_NET_STATE_READY, MTLK_OBJ_PTR(nic),
                   mtlk_core_set_net_state, (nic, NET_STATE_IDLE))

    MTLK_STOP_STEP(core, RADIO_ABILITIES_INIT, MTLK_OBJ_PTR(nic),
                   wave_radio_abilities_unregister, (nic))

    MTLK_STOP_STEP(core, CORE_ABILITIES_INIT, MTLK_OBJ_PTR(nic),
                   wave_core_abilities_unregister, (nic))

    MTLK_STOP_STEP(core, DUT_REGISTER, MTLK_OBJ_PTR(nic),
                   mtlk_dut_core_unregister, (nic));

    MTLK_STOP_STEP(core, MC_INIT, MTLK_OBJ_PTR(nic),
                   mtlk_mc_uninit, (nic))

    MTLK_STOP_STEP(core, RESET_STATS, MTLK_OBJ_PTR(nic),
                   MTLK_NOACTION, ())

    MTLK_STOP_STEP(core, SLOW_CTX_START, MTLK_OBJ_PTR(nic),
                   _mtlk_slow_ctx_stop, (nic->slow_ctx, nic))

    MTLK_STOP_STEP(core, SET_NET_STATE_IDLE, MTLK_OBJ_PTR(nic),
                   mtlk_core_set_net_state, (nic, NET_STATE_HALTED))

  MTLK_STOP_END(core, MTLK_OBJ_PTR(nic))

  for (i = 0; i < MTLK_ARRAY_SIZE(nic->txmm_async_eeprom_msgs); i++) {
    mtlk_txmm_msg_cancel(&nic->txmm_async_eeprom_msgs[i]);
  }

  ILOG1_SDDDS("%s: Stopped: is_stopped=%u, is_stopping=%u, is_iface_stopping=%u, net_state=%s",
              mtlk_df_get_name(mtlk_vap_get_df(nic->vap_handle)),
              nic->is_stopped, nic->is_stopping, nic->is_iface_stopping,
              mtlk_net_state_to_string(mtlk_core_get_net_state(nic)));
}

/* Check if TPC close loop is ON and we have calibrations in EEPROM for selected frequency band */
static int
_mtlk_core_check_tpc_loop_type (mtlk_core_t *nic)
{
  wave_radio_t *radio = wave_vap_radio_get(nic->vap_handle);

  if (TPC_CLOSED_LOOP == WAVE_RADIO_PDB_GET_INT(radio, PARAM_DB_RADIO_TPC_LOOP_TYPE)) {
    uint8 freq_band_cur = WAVE_RADIO_PDB_GET_INT(radio, PARAM_DB_RADIO_FREQ_BAND_CUR);

    if (!mtlk_eeprom_is_band_supported(mtlk_core_get_eeprom(nic),freq_band_cur)) {
      ILOG1_S("TPC close loop is ON and no calibrations for current band (%s GHz) in EEPROM",
               mtlk_eeprom_band_to_string(freq_band_cur));
      ILOG1_V("Force TPC open loop");
      WAVE_RADIO_PDB_SET_INT(radio, PARAM_DB_RADIO_TPC_LOOP_TYPE, TPC_OPEN_LOOP);
    }
  }

  return MTLK_ERR_OK;
}

static int
_mtlk_core_start (mtlk_vap_handle_t vap_handle)
{
  mtlk_core_t       *nic = mtlk_vap_get_core (vap_handle);

  MTLK_STATIC_ASSERT_MSG((WAVE_MAX_KEY_LEN == WLAN_MAX_KEY_LEN), "Must be same length");

  MTLK_START_TRY(core, MTLK_OBJ_PTR(nic))
    MTLK_START_STEP(core, SET_NET_STATE_IDLE, MTLK_OBJ_PTR(nic),
                    mtlk_core_set_net_state, (nic, NET_STATE_IDLE))

    _mtlk_core_poll_stat_init(nic);

    MTLK_START_STEP(core, SLOW_CTX_START, MTLK_OBJ_PTR(nic),
                    _mtlk_slow_ctx_start, (nic->slow_ctx, nic))

    MTLK_START_STEP_VOID(core, RESET_STATS, MTLK_OBJ_PTR(nic),
                         mtlk_core_reset_stats_internal, (nic))

    MTLK_START_STEP_IF((mtlk_vap_is_ap(vap_handle)), core, MC_INIT, MTLK_OBJ_PTR(nic),
                       mtlk_mc_init, (nic))

    MTLK_START_STEP(core, DUT_REGISTER, MTLK_OBJ_PTR(nic),
                    mtlk_dut_core_register, (nic));

    MTLK_START_STEP(core, CORE_ABILITIES_INIT, MTLK_OBJ_PTR(nic),
                    wave_core_abilities_register, (nic))

    MTLK_START_STEP_IF(mtlk_vap_is_master_ap(vap_handle),
                    core, RADIO_ABILITIES_INIT, MTLK_OBJ_PTR(nic),
                    wave_radio_abilities_register, (nic))

    MTLK_START_STEP(core, SET_NET_STATE_READY, MTLK_OBJ_PTR(nic),
                    mtlk_core_set_net_state, (nic, NET_STATE_READY))

    MTLK_START_STEP(core, INIT_DEFAULTS, MTLK_OBJ_PTR(nic),
                    mtlk_core_init_defaults, (nic))

    mtlk_qos_dscp_table_init(nic->dscp_table);
    if (mtlk_vap_is_ap(vap_handle))
      nic->dgaf_disabled = FALSE;
    else
      nic->dgaf_disabled = TRUE;
    nic->csi_data_len = FALSE;
    nic->csi_more_frag = FALSE;
    nic->csi_stats = NULL;
#ifdef WAVE_DCDP_DGAF_SUPPORTED
    /* Force DC DP DGAF update on first call */
    nic->dgaf_disabled_update = -1;
#endif

    MTLK_START_STEP_IF(mtlk_vap_is_ap(vap_handle),
                       core, CHECK_TPC_LOOP_TYPE, MTLK_OBJ_PTR(nic),
                       _mtlk_core_check_tpc_loop_type, (nic))

  MTLK_START_FINALLY(core, MTLK_OBJ_PTR(nic))
  MTLK_START_RETURN(core, MTLK_OBJ_PTR(nic), _mtlk_core_stop, (vap_handle))
}

static int
_mtlk_core_release_tx_data (mtlk_vap_handle_t vap_handle, mtlk_hw_data_req_mirror_t *data_req)
{
  int res = MTLK_ERR_UNKNOWN;
  mtlk_core_t *nic = mtlk_vap_get_core (vap_handle);
  mtlk_nbuf_t *nbuf = data_req->nbuf;
  unsigned short qos = 0;
#if defined(CPTCFG_IWLWAV_PER_PACKET_STATS)
  mtlk_nbuf_priv_t *nbuf_priv = mtlk_nbuf_priv(nbuf);
#endif

#if defined(CPTCFG_IWLWAV_PER_PACKET_STATS)
  mtlk_nbuf_priv_stats_set(nbuf_priv, MTLK_NBUF_STATS_TS_FW_OUT, mtlk_hw_get_timestamp(vap_handle));
#endif

  // check if NULL packet confirmed
  if (data_req->size == 0) {
    ILOG9_V("Confirmation for NULL nbuf");
    goto FINISH;
  }

  qos = data_req->tid;

  if (nic->pstats.ac_used_counter[qos] > 0)
    --nic->pstats.ac_used_counter[qos];

  mtlk_osal_atomic_dec(&nic->unconfirmed_data);

  res = MTLK_ERR_OK;

FINISH:

#if defined(CPTCFG_IWLWAV_PRINT_PER_PACKET_STATS)
  mtlk_nbuf_priv_stats_dump(nbuf_priv);
#endif

  /* Release net buffer
   * WARNING: we can't do it before since we use STA referenced by this packet on FINISH.
   */
  mtlk_df_nbuf_free(nbuf);

  return res;
}

static int
_mtlk_core_handle_rx_data (mtlk_vap_handle_t vap_handle, mtlk_core_handle_rx_data_t *data)
{
  mtlk_nbuf_t *nbuf = data->nbuf;
  MTLK_ASSERT(nbuf != NULL);
  return _handle_rx_ind(mtlk_vap_get_core(vap_handle), nbuf, data);
}

static int
_mtlk_core_handle_rx_bss (mtlk_vap_handle_t vap_handle, mtlk_core_handle_rx_bss_t *data)
{
  MTLK_ASSERT(data != NULL);
  return handle_rx_bss_ind(mtlk_vap_get_core(vap_handle), data);
}

static int __MTLK_IFUNC
_handle_fw_debug_trace_event(mtlk_handle_t object, const void *data, uint32 data_size)
{
  UMI_DBG_TRACE_IND *UmiDbgTraceInd = (UMI_DBG_TRACE_IND *) data;
  MTLK_UNREFERENCED_PARAM(object);
  MTLK_ASSERT(sizeof(UMI_DBG_TRACE_IND) >= data_size);
  MTLK_ASSERT(MAX_DBG_TRACE_DATA >= MAC_TO_HOST32(UmiDbgTraceInd->length));

  UmiDbgTraceInd->au8Data[MAX_DBG_TRACE_DATA - 1] = 0; // make sure it is NULL-terminated (although it should be without this)
  ILOG0_SDDD("DBG TRACE: %s, val1:0x%08X val2:0x%08X val3:0x%08X",
             UmiDbgTraceInd->au8Data,
             MAC_TO_HOST32(UmiDbgTraceInd->val1),
             MAC_TO_HOST32(UmiDbgTraceInd->val2),
             MAC_TO_HOST32(UmiDbgTraceInd->val3));

  return MTLK_ERR_OK;
}

static int
_wave_core_rcvry_reset (mtlk_handle_t hcore, const void* data, uint32 data_size)
{
  mtlk_clpb_t *clpb = *(mtlk_clpb_t **)data;
  wave_rcvry_task_ctx_t ** rcvry_handle = NULL;
  int res = MTLK_ERR_OK;
  uint32 size = sizeof(wave_rcvry_task_ctx_t *);

  MTLK_ASSERT(sizeof(mtlk_clpb_t*) == data_size);
  ILOG1_V("resetting recovery config");

  rcvry_handle = mtlk_clpb_enum_get_next(clpb, &size);
  MTLK_CLPB_TRY(rcvry_handle, size)
    wave_rcvry_reset(rcvry_handle);
  MTLK_CLPB_FINALLY(res)
    return mtlk_clpb_push_res(clpb, res);
  MTLK_CLPB_END;
}

static int __MTLK_IFUNC
_handle_core_class3_error(mtlk_handle_t core_object, const void *data, uint32 data_size)
{
mtlk_core_t                 *master_core = HANDLE_T_PTR(mtlk_core_t, core_object);
mtlk_core_t                 *core;
UMI_FRAME_CLASS_ERROR       *frame_error = (UMI_FRAME_CLASS_ERROR *)data;
UMI_FRAME_CLASS_ERROR_ENTRY *class3_error = NULL;
mtlk_vap_manager_t          *vap_mng;
mtlk_vap_handle_t            vap_handle;
uint32                       i;

  MTLK_ASSERT(sizeof(UMI_FRAME_CLASS_ERROR) == data_size);
  MTLK_ASSERT(frame_error->u8numOfValidEntries <= MAX_NUMBER_FRAME_CLASS_ERROR_ENTRIES_IN_MESSAGE);
  MTLK_ASSERT(master_core != NULL);

  vap_mng = mtlk_vap_get_manager(master_core->vap_handle);

  for(i = 0; i < frame_error->u8numOfValidEntries; i++) {
    class3_error = &frame_error->frameClassErrorEntries[i];
    MTLK_ASSERT(class3_error != NULL);

    if (MTLK_ERR_OK != mtlk_vap_manager_get_vap_handle(vap_mng, class3_error->u8vapIndex, &vap_handle)){
      ILOG2_D("VapID %u doesn't exist. Ignore class3 error", class3_error->u8vapIndex);
      continue;   /* VAP not exist */
    }

    core = mtlk_vap_get_core(vap_handle);
    MTLK_ASSERT(core != NULL);

    if (mtlk_core_get_net_state(core) != NET_STATE_CONNECTED){
      ILOG2_D("VapID %u not active. Ignore class3 error", class3_error->u8vapIndex);
      continue;
    }

    /* if WDS is ON, find peer AP in DB and filter out Class 3 errors */
    if (mtlk_vap_is_ap(vap_handle) &&
       (BR_MODE_WDS == MTLK_CORE_HOT_PATH_PDB_GET_INT(core, CORE_DB_CORE_BRIDGE_MODE)) &&
      (core_wds_frame_drop(core, &class3_error->sAddr))) {
      ILOG2_Y("Ignore class3 error for WDS peers:%Y", class3_error->sAddr.au8Addr);
      continue;
    }

    ILOG2_DDY("CID-%04x: Class3 Error VapID:%u MAC:%Y",
              mtlk_vap_get_oid(core->vap_handle), class3_error->u8vapIndex, class3_error->sAddr.au8Addr);

    if (mtlk_vap_is_ap(vap_handle))
      wv_cfg80211_class3_error_notify(mtlk_core_get_wdev(core->vap_handle),
                                     class3_error->sAddr.au8Addr);
  }

  return MTLK_ERR_OK;
}

static int __MTLK_IFUNC
_handle_class3_error_ind_handle (mtlk_handle_t core_object, const void *data, uint32 data_size)
{
  mtlk_core_t *core = HANDLE_T_PTR(mtlk_core_t, core_object);

  ILOG5_V("Handling class 3 error");

  _mtlk_process_hw_task(core, SERIALIZABLE, _handle_core_class3_error,
                         HANDLE_T(core), data, sizeof(UMI_FRAME_CLASS_ERROR));

  return MTLK_ERR_OK;
}

void mtlk_cca_step_up_if_allowed (mtlk_core_t* core, int cwi_noise, int limit, int step_up)
{
  wave_radio_t *radio = wave_vap_radio_get(core->vap_handle);
  int threshold;
  int i;

  threshold = WAVE_RADIO_PDB_GET_INT(radio, PARAM_DB_RADIO_INTERFDET_THRESHOLD);

  ILOG1_DDD("noise = %d, det_thresh = %d, limit = %d", cwi_noise, threshold, limit);
  ILOG1_DDDDD("current adaptive CCA thresholds: %d %d %d %d %d",
    core->slow_ctx->cca_adapt.cca_th_params[0],
    core->slow_ctx->cca_adapt.cca_th_params[1],
    core->slow_ctx->cca_adapt.cca_th_params[2],
    core->slow_ctx->cca_adapt.cca_th_params[3],
    core->slow_ctx->cca_adapt.cca_th_params[4]);

  if (cwi_noise < threshold) {
    if (core->slow_ctx->cca_adapt.cwi_poll) {
      if (core->slow_ctx->cca_adapt.cwi_drop_detected) {
        core->slow_ctx->cca_adapt.cwi_poll = FALSE;
        core->slow_ctx->cca_adapt.cwi_drop_detected = FALSE;
      } else {
        core->slow_ctx->cca_adapt.cwi_drop_detected = TRUE;
        return; /* act next time */
      }
    }

    if (_mtlk_core_cca_is_below_limit(core, limit)) { /* increase threshold, send */
      iwpriv_cca_th_t cca_th_params;

      for (i = 0; i < MTLK_CCA_TH_PARAMS_LEN; i++) {
        core->slow_ctx->cca_adapt.cca_th_params[i] = MIN(limit, core->slow_ctx->cca_adapt.cca_th_params[i] + step_up);
        cca_th_params.values[i] = core->slow_ctx->cca_adapt.cca_th_params[i];
        ILOG1_DD("CCA adaptive: step up value %d: %d", i, cca_th_params.values[i]);
      }
      core->slow_ctx->cca_adapt.stepping_up = TRUE;
      mtlk_core_cfg_send_cca_threshold_req(core, &cca_th_params);
    }
  } else {
    core->slow_ctx->cca_adapt.cwi_poll = TRUE;
  }
}

static int __MTLK_IFUNC
_handle_beacon_blocked_ind(mtlk_handle_t core_object, const void *data, uint32 data_size)
{
  iwpriv_cca_adapt_t cca_adapt_params;
  mtlk_pdb_size_t cca_adapt_size = sizeof(cca_adapt_params);
  mtlk_core_t* core = HANDLE_T_PTR(mtlk_core_t, core_object);
  const UMI_BEACON_BLOCK *beacon_block_ind = (const UMI_BEACON_BLOCK *)data;
  mtlk_osal_msec_t cur_time = mtlk_osal_timestamp_to_ms(mtlk_osal_timestamp());
  wave_radio_t *radio = wave_vap_radio_get(core->vap_handle);
  iwpriv_cca_th_t cca_th_params;

  MTLK_ASSERT(sizeof(UMI_BEACON_BLOCK) == data_size);

  ILOG1_D("BEACON_BLOCKED event: blocked: %d", beacon_block_ind->beaconBlock);

  if (mtlk_vap_is_master_ap(core->vap_handle)) {
    if (core->is_stopped) {
      ILOG1_V("BEACON_BLOCKED event while core is down");
      return MTLK_ERR_OK; /* do not process */
    }

    if (!wave_radio_interfdet_get(radio)) {
      ILOG1_V("BEACON_BLOCKED event while interference detection is deactivated");
      return MTLK_ERR_OK; /* do not process */
    }

    if (MTLK_ERR_OK == WAVE_RADIO_PDB_GET_BINARY(radio, PARAM_DB_RADIO_CCA_ADAPT, &cca_adapt_params, &cca_adapt_size)) {
      if (!cca_adapt_params.initial) {
        ILOG1_V("BEACON_BLOCKED event while CCA adaptation is deactivated");
        return MTLK_ERR_OK; /* do not process */
      }
    }

    /* read default user config */
    if (MTLK_ERR_OK != mtlk_core_cfg_read_cca_threshold(core, &cca_th_params)) {
      return MTLK_ERR_UNKNOWN;
    }

    if (beacon_block_ind->beaconBlock) { /* blocked */
      struct intel_vendor_channel_data ch_data;

      if (core->slow_ctx->cca_adapt.stepping_down) {
        /* cancel step_down_timer */
        mtlk_osal_timer_cancel_sync(&core->slow_ctx->cca_step_down_timer);
        core->slow_ctx->cca_adapt.stepping_down = FALSE;
        if ((cur_time - core->slow_ctx->cca_adapt.last_unblocked_time) < (cca_adapt_params.min_unblocked_time * 1000)) {
          core->slow_ctx->cca_adapt.step_down_coef <<= 1;
        }
      } else {
        if (!core->slow_ctx->cca_adapt.stepping_up) {
          core->slow_ctx->cca_adapt.step_down_coef = 1; /* reset if adaptation is (re)started */
        }
      }

      memset(&ch_data, 0, sizeof(ch_data));
      scan_get_aocs_info(core, &ch_data);
      mtlk_cca_step_up_if_allowed(core, ch_data.cwi_noise, cca_adapt_params.limit, cca_adapt_params.step_up);
    } else { /* unblocked */
      core->slow_ctx->cca_adapt.stepping_up = FALSE;
      core->slow_ctx->cca_adapt.cwi_poll = FALSE;

      if (!core->slow_ctx->cca_adapt.stepping_down) {
        core->slow_ctx->cca_adapt.last_unblocked_time = cur_time;
        ILOG2_D("CCA adaptive: set last unblocked %d", core->slow_ctx->cca_adapt.last_unblocked_time);

        if (mtlk_core_cca_is_above_configured(core, &cca_th_params)) {
          ILOG1_D("CCA adaptive: Schedule step down timer, interval %d", core->slow_ctx->cca_adapt.step_down_coef * cca_adapt_params.step_down_interval);
          ILOG1_DDDDD("user config  th: %d %d %d %d %d", cca_th_params.values[0], cca_th_params.values[1], cca_th_params.values[2], cca_th_params.values[3], cca_th_params.values[4]);
          ILOG1_DDDDD("current core th: %d %d %d %d %d",
            core->slow_ctx->cca_adapt.cca_th_params[0],
            core->slow_ctx->cca_adapt.cca_th_params[1],
            core->slow_ctx->cca_adapt.cca_th_params[2],
            core->slow_ctx->cca_adapt.cca_th_params[3],
            core->slow_ctx->cca_adapt.cca_th_params[4]);

          core->slow_ctx->cca_adapt.stepping_down = TRUE;
          mtlk_osal_timer_set(&core->slow_ctx->cca_step_down_timer,
            core->slow_ctx->cca_adapt.step_down_coef * cca_adapt_params.step_down_interval * 1000);
        }
      }
    }
  }

  return MTLK_ERR_OK;
}

static struct ieee80211_channel * _wave_core_channel_get (mtlk_core_t *core)
{
  struct mtlk_chan_def *ccd = __wave_core_chandef_get(core);
  struct wiphy *wiphy = wv_mac80211_wiphy_get(wave_radio_mac80211_get(wave_vap_radio_get(core->vap_handle)));

  return wave_radio_channel_get(wiphy, ccd->chan.band, ccd->chan.center_freq);
}

static int
_mtlk_core_sta_req_bss_change (mtlk_core_t *master_core, struct mtlk_sta_bss_change_parameters *bss_change_params)
{
  struct cfg80211_chan_def *chandef = &bss_change_params->info->chandef;
  struct ieee80211_channel *channel = chandef->chan;
  struct mtlk_bss_parameters bp;
  unsigned long basic_rates = bss_change_params->info->basic_rates;
  int i, res;
  mtlk_vap_handle_t vap_handle;
  mtlk_pdb_t *param_db_core;

  if (channel == NULL) {
    WLOG_V("Channel not provided for set BSS, try getting internally");
    channel = _wave_core_channel_get(master_core);
    if (!channel) {
      ELOG_V("Could not get channel for set BSS");
      return MTLK_ERR_PARAMS;
    }
  }

  res = mtlk_vap_manager_get_vap_handle(mtlk_vap_get_manager(master_core->vap_handle), bss_change_params->vap_index, &vap_handle);
  if (MTLK_ERR_OK != res){
    ILOG2_D("VAP:%d is not exist", bss_change_params->vap_index);
    return res;   /* VAP not exist */
  }
  param_db_core = mtlk_vap_get_param_db(vap_handle);

  memset(&bp, 0, sizeof(bp));
  bp.vap_id = bss_change_params->vap_index;
  bp.use_cts_prot = bss_change_params->info->use_cts_prot;
  bp.use_short_preamble = bss_change_params->info->use_short_preamble;
  bp.use_short_slot_time = bss_change_params->info->use_short_slot;
  bp.ap_isolate = bss_change_params->info->ap_isolate;
  bp.ht_opmode = bss_change_params->info->ht_operation_mode;
  bp.p2p_ctwindow = bss_change_params->info->p2p_noa_attr.oppps_ctwindow;
  bp.p2p_opp_ps = 0;
  bp.he_bss_color.color = bss_change_params->info->he_bss_color.color;
  bp.he_bss_color.enabled = bss_change_params->info->he_bss_color.enabled;

  for_each_set_bit(i, &basic_rates, BITS_PER_LONG) {
    bp.basic_rates[bp.basic_rates_len++] =
        bss_change_params->bands[channel->band]->bitrates[i].bitrate / 5;
  }

  res = _core_change_bss_by_params(master_core, &bp);

  return res;
}

/* This function should be called from master serializer context */
static mtlk_error_t
_mtlk_core_change_bss (mtlk_handle_t hcore, const void* data, uint32 data_size)
{
  mtlk_error_t res = MTLK_ERR_OK;
  mtlk_clpb_t *clpb = *(mtlk_clpb_t **) data;
  struct mtlk_sta_bss_change_parameters *bss_change_params = NULL;
  uint32 params_size;
  mtlk_core_t   *master_core = HANDLE_T_PTR(mtlk_core_t, hcore);
  wave_radio_t  *radio = wave_vap_radio_get(master_core->vap_handle);
  wv_mac80211_t *mac80211 = wave_radio_mac80211_get(radio);

  MTLK_ASSERT(sizeof(mtlk_clpb_t*) == data_size);
  MTLK_ASSERT(master_core == mtlk_core_get_master(master_core->vap_handle));

  bss_change_params = mtlk_clpb_enum_get_next(clpb, &params_size);
  MTLK_CLPB_TRY(bss_change_params, params_size)

     if (!mtlk_vap_is_sta(bss_change_params->core->vap_handle) &&
         bss_change_params->core->is_stopped) {
      ILOG1_S("%s: BSS configuration changed before AP vap added to FW, ignoring",
              bss_change_params->vif_name);
      MTLK_CLPB_EXIT(MTLK_ERR_OK);
    }

    /* Prevent setting WMM while in scan */
    if (mtlk_core_is_in_scan_mode(master_core)) {
      MTLK_CLPB_EXIT(MTLK_ERR_RETRY);
    }

    if (bss_change_params->changed & BSS_CHANGED_HE_BSS_COLOR) {
      if (bss_change_params->color_change_active) {
        uint8 active_vaps = 1;
        if (mtlk_vap_is_sta(bss_change_params->core->vap_handle)) {
          if (master_core->color_change_active) {
             struct ieee80211_vif *vif = wv_mac80211_get_vif(mac80211, bss_change_params->vap_index);
             /* FW doesn't support AP and STA VAP color change at the same time. */
             WLOG_S("AP VAP color change in progress. Can't start CCA on STA VAP %s", bss_change_params->vif_name);
             if (vif) ieee80211_color_switch_done(vif, FALSE);
             MTLK_CLPB_EXIT(res);
          }
        } else if (mtlk_vap_is_ap(bss_change_params->core->vap_handle)) {
            if (mtlk_vap_is_sta_in_cca(mtlk_vap_get_manager(master_core->vap_handle))) {
              struct ieee80211_vif *vif = wv_mac80211_get_vif(mac80211, bss_change_params->vap_index);
              /* FW doesn't support AP and STA VAP color change at the same time. */
              WLOG_S("STA VAP color change in progress. Can't start CCA on AP VAP %s", bss_change_params->vif_name);
              if (vif) {
                  vif->bss_conf.he_bss_color.color = MTLK_CORE_PDB_GET_INT(bss_change_params->core, PARAM_DB_CORE_HE_BSS_COLOR);
                  ieee80211_color_switch_done(vif, FALSE);
              }
              MTLK_CLPB_EXIT(res);
            }
        }
        active_vaps = mtlk_vap_manager_get_active_vaps_number(mtlk_vap_get_manager(master_core->vap_handle));        
        res = wave_core_bss_color_start_cca(bss_change_params->core,
                  bss_change_params->color_change_color,
                  bss_change_params->color_switchtime,
                  bss_change_params->he_oper_color_offset_beacon);
        if (res) {
          bss_change_params->core->color_change_active = false;
          ELOG_S("%s: Bss Configuration failed - Color change failed", bss_change_params->vif_name);
          MTLK_CLPB_EXIT(res);
        }
        bss_change_params->core->color_change_active = bss_change_params->color_change_active;
#define MAX_COLOR_SWITCH_TIMEOUT_MULTIPLE 3
        /* This is single timer for all Vaps CCA completion timeout.
         * Adding 1sec Execution delay per active VAP
         */
        wave_cca_start_timer(mac80211, (MAX_COLOR_SWITCH_TIMEOUT_MULTIPLE * bss_change_params->color_switchtime) +
                (active_vaps * MTLK_OSAL_MSEC_IN_SEC));
        bss_change_params->core->color_change_color = bss_change_params->color_change_color;
        bss_change_params->changed &= (~((uint64)BSS_CHANGED_HE_BSS_COLOR));
      } else {
        if (((MTLK_CORE_PDB_GET_INT(bss_change_params->core, PARAM_DB_CORE_HE_BSS_COLOR) & HE_OPERATION_BSS_COLOR_MASK) ==
            bss_change_params->color_change_color) &&
            bss_change_params->core->color_change_active)
          /* Ignore color change sent post CCA complete notify */
          bss_change_params->changed &= (~((uint64)BSS_CHANGED_HE_BSS_COLOR));
        bss_change_params->core->color_change_active = bss_change_params->color_change_active;
      }

      /* if no more params changed, return */
      if (!bss_change_params->changed)
        MTLK_CLPB_EXIT(MTLK_ERR_OK);
    }

    if ((bss_change_params->changed & BSS_CHANGED_BASIC_RATES) ||
        (bss_change_params->changed & BSS_CHANGED_ERP_PREAMBLE) ||
        (bss_change_params->changed & BSS_CHANGED_ERP_SLOT) ||
        (bss_change_params->changed & BSS_CHANGED_ERP_CTS_PROT) ||
        (bss_change_params->changed & BSS_CHANGED_AP_ISOLATE) ||
        (bss_change_params->changed & BSS_CHANGED_HE_BSS_COLOR)) {
      ILOG1_S("%s: BSS configuration changed", bss_change_params->vif_name);
      res = _mtlk_core_sta_req_bss_change(master_core, bss_change_params);
      if (res) {
        ELOG_V("_mtlk_core_change_bss failed");
        MTLK_CLPB_EXIT(res);
      }

      if (!wv_mac80211_iface_get_is_initialized(mac80211, bss_change_params->vap_index)) {
        if (mtlk_vap_is_ap(bss_change_params->core->vap_handle))
          res = core_cfg_wmm_param_set_by_params(master_core, bss_change_params->core);
        wv_mac80211_iface_set_initialized(mac80211, bss_change_params->vap_index);
      }
    }

    if (bss_change_params->changed & BSS_CHANGED_BEACON_INT) {
      mtlk_beacon_interval_t mtlk_beacon_interval;

      /*
       * FW should be notified about peer AP beacon interval so that FW ages out packets correctly.
       * Ager timeout for STA is set according to VAP beacon interval * STA listen interval.
       * If we only have one VSTA VAP FW may drop packets unnecessarily as ageing period will be minimum
       * Note: even though we do not enter PS we still need to do some periodic ageing on STA queues
       * in case we have low rate, many retries, lack of PDs, etc...
       */
      /* In the case of AP the FW should be notified in mtlk_mbss_send_vap_activate called by _mtlk_core_activate.
       * For some reason it does not, so that code is required by ap as well
       */

      ILOG1_DD("Beacon interval (idx %d) has updated to: %d", bss_change_params->vap_index, bss_change_params->info->beacon_int);

      MTLK_CORE_PDB_SET_INT(bss_change_params->core, PARAM_DB_CORE_BEACON_PERIOD, bss_change_params->info->beacon_int);
      mtlk_beacon_interval.beacon_interval = bss_change_params->info->beacon_int;
      mtlk_beacon_interval.vap_id = bss_change_params->vap_index;

      res = mtlk_beacon_man_set_beacon_interval_by_params(bss_change_params->core, &mtlk_beacon_interval);
      if (res != MTLK_ERR_OK)
        ELOG_DD("Error setting peer AP beacon interval %u for VapID %u ", bss_change_params->info->beacon_int, bss_change_params->vap_index);
    }

    if (bss_change_params->changed & BSS_CHANGED_TXPOWER) {
      ILOG0_SD("%s: TX power changed to=%d", bss_change_params->vif_name,
               bss_change_params->info->txpower);
    }

  MTLK_CLPB_FINALLY(res)
    return mtlk_clpb_push_res(clpb, res);
  MTLK_CLPB_END
}

/* This function should be called from master serializer context */
static int
_mtlk_core_set_ap_beacon_info (mtlk_handle_t hcore, const void* data, uint32 data_size)
{
  mtlk_error_t res = MTLK_ERR_OK;
  mtlk_clpb_t *clpb = *(mtlk_clpb_t **) data;
  mtlk_core_t *master_core = HANDLE_T_PTR(mtlk_core_t, hcore);
  struct mtlk_beacon_info_parameters *beacon_info_params = NULL;
  uint32 params_size;
  mtlk_vap_handle_t vap_handle;
  mtlk_core_t *core;
  wave_radio_t *radio;

  MTLK_ASSERT(sizeof(mtlk_clpb_t*) == data_size);
  MTLK_ASSERT(master_core == mtlk_core_get_master(master_core->vap_handle));
  beacon_info_params = mtlk_clpb_enum_get_next(clpb, &params_size);
  MTLK_CLPB_TRY(beacon_info_params, params_size)
    if (MTLK_ERR_OK != mtlk_vap_manager_get_vap_handle(mtlk_vap_get_manager(master_core->vap_handle), beacon_info_params->vap_index, &vap_handle))
      MTLK_CLPB_EXIT(MTLK_ERR_PARAMS);

    if (!mtlk_vap_is_ap(vap_handle)) MTLK_CLPB_EXIT(MTLK_ERR_PARAMS); /* Ap mode only, Station mode has set_beacon_interval */

    core = mtlk_vap_get_core(vap_handle);
    if (core == NULL) MTLK_CLPB_EXIT(MTLK_ERR_UNKNOWN);

    if (core->vap_in_fw_is_active) {
      ILOG0_DDDDD("CID-%04x: Skipping setting AP beacon info as VAP already active in FW, (%d, %d) --> (%d, %d)",
                  mtlk_vap_get_oid(core->vap_handle), MTLK_CORE_PDB_GET_INT(core, PARAM_DB_CORE_DTIM_PERIOD),
                  MTLK_CORE_PDB_GET_INT(core, PARAM_DB_CORE_BEACON_PERIOD),
                  beacon_info_params->dtim_period, beacon_info_params->beacon_int);
      MTLK_CLPB_EXIT(MTLK_ERR_OK);
    }

    res = mtlk_core_set_ap_beacon_info_by_params(core, beacon_info_params);
    if (MTLK_ERR_OK == res) {
      MTLK_CORE_PDB_SET_INT(core, PARAM_DB_CORE_DTIM_PERIOD, beacon_info_params->dtim_period);
      MTLK_CORE_PDB_SET_INT(core, PARAM_DB_CORE_BEACON_PERIOD, beacon_info_params->beacon_int);
    }

    if (!mtlk_hw_type_is_gen7(mtlk_vap_get_hw(vap_handle))) { /* For WAV700 since there is no change in operational antennas, no need to notify antenna switch if zwdfs enabled */
      radio = wave_vap_radio_get(vap_handle);
      if (wave_radio_get_is_zwdfs_operational_radio(radio)) {
        wave_radio_t *zwdfs_radio = wave_radio_descr_get_zwdfs_radio(wave_card_radio_descr_get(mtlk_vap_get_hw(master_core->vap_handle)));
        if (wave_radio_get_zwdfs_ant_enabled(zwdfs_radio))
          mtlk_coc_zwdfs_switch_opmode_notify(wave_radio_coc_mgmt_get(radio), TRUE);
      }
    }

  MTLK_CLPB_FINALLY(res)
    return mtlk_clpb_push_res(clpb, res);
  MTLK_CLPB_END
}

static int __MTLK_IFUNC
_mtlk_handle_eeprom_failure_sync(mtlk_handle_t object, const void *data,  uint32 data_size)
{
  mtlk_core_t *nic = HANDLE_T_PTR(mtlk_core_t, object);
  MTLK_ASSERT(sizeof(EEPROM_FAILURE_EVENT) == data_size);

  mtlk_cc_handle_eeprom_failure(nic->vap_handle, (const EEPROM_FAILURE_EVENT*) data);

  return MTLK_ERR_OK;
}

static int __MTLK_IFUNC
_mtlk_handle_generic_event(mtlk_handle_t object, const void *data,  uint32 data_size)
{
  MTLK_ASSERT(sizeof(GENERIC_EVENT) == data_size);
  mtlk_cc_handle_generic_event(HANDLE_T_PTR(mtlk_core_t, object)->vap_handle, (GENERIC_EVENT*) data);
  return MTLK_ERR_OK;
}

static int __MTLK_IFUNC
_mtlk_handle_algo_failure(mtlk_handle_t object, const void *data,  uint32 data_size)
{
  mtlk_core_t *nic = HANDLE_T_PTR(mtlk_core_t, object);

  MTLK_ASSERT(sizeof(CALIBR_ALGO_EVENT) == data_size);

  mtlk_cc_handle_algo_calibration_failure(nic->vap_handle, (const CALIBR_ALGO_EVENT*)data);

  return MTLK_ERR_OK;
}

static int __MTLK_IFUNC
_mtlk_handle_dummy_event(mtlk_handle_t object, const void *data,  uint32 data_size)
{
  MTLK_ASSERT(sizeof(DUMMY_EVENT) == data_size);
  mtlk_cc_handle_dummy_event(HANDLE_T_PTR(mtlk_core_t, object)->vap_handle, (const DUMMY_EVENT*) data);
  return MTLK_ERR_OK;
}

static int __MTLK_IFUNC
_mtlk_handle_unknown_event(mtlk_handle_t object, const void *data,  uint32 data_size)
{
  MTLK_ASSERT(sizeof(uint32) == data_size);
  mtlk_cc_handle_unknown_event(HANDLE_T_PTR(mtlk_core_t, object)->vap_handle, *(uint32*)data);
  return MTLK_ERR_OK;
}

static void __MTLK_IFUNC
_mtlk_handle_mac_event(mtlk_core_t         *nic,
                       MAC_EVENT           *event)
{
  uint32 event_id = MAC_TO_HOST32(event->u32EventID) & 0xff;

  switch(event_id)
  {
  case EVENT_EEPROM_FAILURE:
    _mtlk_process_hw_task(nic, SYNCHRONOUS, _mtlk_handle_eeprom_failure_sync,
                          HANDLE_T(nic), &event->u.sEepromEvent, sizeof(EEPROM_FAILURE_EVENT));
    break;
  case EVENT_GENERIC_EVENT:
    _mtlk_process_hw_task(nic, SERIALIZABLE, _mtlk_handle_generic_event,
                          HANDLE_T(nic), &event->u.sGenericData, sizeof(GENERIC_EVENT));
    break;
  case EVENT_CALIBR_ALGO_FAILURE:
    _mtlk_process_hw_task(nic, SERIALIZABLE, _mtlk_handle_algo_failure,
                          HANDLE_T(nic), &event->u.sCalibrationEvent, sizeof(CALIBR_ALGO_EVENT));
    break;
  case EVENT_DUMMY:
    _mtlk_process_hw_task(nic, SERIALIZABLE, _mtlk_handle_dummy_event,
                          HANDLE_T(nic), &event->u.sDummyEvent, sizeof(DUMMY_EVENT));
    break;
  default:
    _mtlk_process_hw_task(nic, SERIALIZABLE, _mtlk_handle_unknown_event,
                          HANDLE_T(nic), &event_id, sizeof(uint32));
    break;
  }
}

static int __MTLK_IFUNC
_mtlk_handle_unknown_ind_type(mtlk_handle_t object, const void *data,  uint32 data_size)
{
  MTLK_ASSERT(sizeof(uint32) == data_size);
  ILOG0_DD("CID-%04x: Unknown MAC indication type %u",
           mtlk_vap_get_oid(HANDLE_T_PTR(mtlk_core_t, object)->vap_handle), *(uint32*)data);
  return MTLK_ERR_OK;
}

static void
_mtlk_core_handle_rx_ctrl (mtlk_vap_handle_t   vap_handle,
                          uint32               id,
                          void                *payload,
                          uint32               payload_buffer_size)
{
  mtlk_core_t *nic = mtlk_vap_get_core (vap_handle);
  mtlk_core_t *master_nic = NULL;
  mtlk_hw_t *hw = mtlk_vap_get_hw(vap_handle);

  MTLK_ASSERT(NULL != nic);

  master_nic = mtlk_core_get_master(nic->vap_handle);
  MTLK_ASSERT(NULL != master_nic);

  switch(id)
  {
  case MC_MAN_MAC_EVENT_IND:
    _mtlk_handle_mac_event(nic, (MAC_EVENT*)payload);
    break;
  case MC_MAN_TKIP_MIC_FAILURE_IND:
    _mtlk_process_hw_task(master_nic, SERIALIZABLE, _handle_security_alert_ind,
                           HANDLE_T(master_nic), payload, sizeof(UMI_TKIP_MIC_FAILURE));
    break;
  case MC_MAN_TRACE_IND:
    _mtlk_process_hw_task(nic, SERIALIZABLE, _handle_fw_debug_trace_event,
                          HANDLE_T(nic), payload, sizeof(UMI_DBG_TRACE_IND));
    break;
  case MC_MAN_CONTINUOUS_INTERFERER_IND:
    _mtlk_process_hw_task(nic, SERIALIZABLE, _handle_fw_interference_ind,
                          HANDLE_T(nic), payload, sizeof(UMI_CONTINUOUS_INTERFERER));
    break;
  case MC_MAN_BEACON_BLOCKED_IND:
    _mtlk_process_hw_task(nic, SERIALIZABLE, _handle_beacon_blocked_ind,
      HANDLE_T(nic), payload, sizeof(UMI_BEACON_BLOCK));
    break;
  case MC_MAN_RADAR_IND:
    _mtlk_process_hw_task(master_nic, SERIALIZABLE, _wave_core_handle_radar_event,
                          HANDLE_T(master_nic), payload, sizeof(UMI_RADAR_DETECTION));
    break;
  case MC_MAN_BEACON_TEMPLATE_WAS_SET_IND:
    /* This has to be run in master VAP context */
    if (RCVRY_TYPE_UNDEF != wave_rcvry_type_current_get(mtlk_vap_get_hw(nic->vap_handle))) {
      /* recovery case */
      wave_beacon_man_rcvry_template_ind_handle(master_nic);
    } else {
      /* operational case */
      _mtlk_process_hw_task(master_nic, SERIALIZABLE, wave_beacon_man_template_ind_handle,
                            HANDLE_T(master_nic), payload, sizeof(UMI_BEACON_SET));
    }
    break;
  case MC_MAN_CLASS3_ERROR_IND:
    _mtlk_process_hw_task(nic, SYNCHRONOUS, _handle_class3_error_ind_handle,
                           HANDLE_T(nic), payload, sizeof(UMI_FRAME_CLASS_ERROR_ENTRY));
    break;
  case MC_MAN_HE_MU_DBG_IND: {
#ifdef CONFIG_WAVE_DEBUG
    _mtlk_process_hw_task(master_nic, SERIALIZABLE, wave_dbg_static_plan_mu_group_stats_ind_handle,
                          HANDLE_T(master_nic), payload, sizeof(UMI_DBG_HE_MU_GROUP_STATS));
#endif
    break;
  }
  case MC_MAN_WARNING_DETECTED_IND:
    _mtlk_process_hw_task(nic, SYNCHRONOUS, wave_core_fw_warning_detection_ind_handle,
                           HANDLE_T(nic), payload, sizeof(UMI_WHM_WARNING_DETECTION));
    break;
  case MC_MAN_STA_EXCESSIVE_RETRIES_IND:
    _mtlk_process_hw_task(nic, SERIALIZABLE, wave_core_handle_sta_excessive_retries,
                           HANDLE_T(nic), payload, sizeof(UMI_STA_EXCESSIVE_RETRIES_DETECTION));
    break;
  case MC_MAN_CCA_INDICATION:
     _mtlk_process_hw_task(master_nic, SERIALIZABLE, wave_core_handle_color_change_event,
                           HANDLE_T(master_nic), NULL, 0);
    break;
#ifdef MTLK_WAVE_700
  case MC_MAN_CHANNEL_SWITCH_NOTIFICATION_DONE_IND:
    if (mtlk_hw_type_is_gen7(hw))
      _mtlk_process_hw_task(nic, SERIALIZABLE, wave_core_handle_ml_chan_switch_done_event,
                            HANDLE_T(nic), payload, sizeof(UMI_MAN_CHANNEL_SWITCH_DONE_IND));
    else
      _mtlk_process_hw_task(nic, SERIALIZABLE, _mtlk_handle_unknown_ind_type,
                           HANDLE_T(nic), &id, sizeof(uint32));
    break;
#endif
  case MC_MAN_BEACON_DYN_WMM_PARAM_SET_IND:
    _mtlk_process_hw_task(master_nic, SERIALIZABLE, wave_core_handle_dynamic_wmm_event,
                          HANDLE_T(master_nic), payload, sizeof(UMI_BEACON_DYN_WMM_SET));
    break;
  default:
    _mtlk_process_hw_task(nic, SERIALIZABLE, _mtlk_handle_unknown_ind_type,
                           HANDLE_T(nic), &id, sizeof(uint32));
    break;
  }
}

static BOOL
mtlk_core_ready_to_process_task (mtlk_core_t *nic, uint32 req_id)
{
  mtlk_hw_t *hw = mtlk_vap_get_hw(nic->vap_handle);

  /* if error is occurred in _pci_probe then serializer is absent */
  if (wave_rcvry_pci_probe_error_get(wave_hw_mmb_get_mmb_base(hw)))
    return FALSE;

  if (wave_in_fw_recovery(nic) &&
      (WAVE_CORE_REQ_SET_BEACON           == req_id ||
       WAVE_CORE_REQ_ACTIVATE_OPEN        == req_id ||
       WAVE_CORE_REQ_GET_STATION          == req_id ||
       WAVE_CORE_REQ_CHANGE_BSS           == req_id ||
       WAVE_RADIO_REQ_CHANGE_BSS          == req_id ||
       WAVE_CORE_REQ_SET_WMM_PARAM        == req_id ||
       WAVE_RADIO_REQ_SET_CHAN            == req_id ||
       WAVE_RADIO_REQ_DO_SCAN             == req_id ||
       WAVE_RADIO_REQ_SCAN_TIMEOUT        == req_id ||
       WAVE_RADIO_REQ_PREPARE_CAC_START   == req_id)) {
    return FALSE;
  }

  return TRUE;
}

void __MTLK_IFUNC
mtlk_core_handle_tx_ctrl (mtlk_vap_handle_t    vap_handle,
                          mtlk_user_request_t *req,
                          uint32               id,
                          mtlk_clpb_t         *data)
{
#define _WAVE_CORE_REQ_MAP_START(req_id)                                                \
  switch (req_id) {

#define _MTLK_CORE_HANDLE_REQ_SERIALIZABLE(req_id, func)                                \
  case (req_id):                                                                        \
    _mtlk_process_user_task(nic, req, SERIALIZABLE, req_id, func, HANDLE_T(nic), data); \
    break;

#define _MTLK_CORE_HANDLE_REQ_SYNCHRONOUS(req_id, func)                                 \
  case (req_id):                                                                        \
    _mtlk_process_user_task(nic, req, SYNCHRONOUS, req_id, func, HANDLE_T(nic), data);  \
    break;
#define _MTLK_CORE_HANDLE_REQ_DUMPABLE(req_id, func)                                    \
  case (req_id):                                                                        \
  if (wave_rcvry_fw_dump_in_progress_get(mtlk_vap_get_hw(nic->vap_handle))) {           \
    _mtlk_process_user_task(nic, req, SYNCHRONOUS, req_id, func, HANDLE_T(nic), data);  \
  } else {                                                                              \
    _mtlk_process_user_task(nic, req, SERIALIZABLE, req_id, func, HANDLE_T(nic), data); \
  }                                                                                     \
  break;
#define _WAVE_CORE_REQ_MAP_END(_id_)                                                    \
    default:                                                                            \
      ELOG_D("Request 0x%08x not mapped by core", _id_);                                \
      MTLK_ASSERT(FALSE);                                                               \
  }

  mtlk_core_t *nic = mtlk_vap_get_core(vap_handle);
  MTLK_ASSERT(NULL != nic);
  MTLK_ASSERT(NULL != req);
  MTLK_ASSERT(NULL != data);

  if (!mtlk_core_ready_to_process_task (nic, id)) {
    mtlk_df_ui_req_complete(req, MTLK_ERR_NOT_READY);
    return;
  }

  _WAVE_CORE_REQ_MAP_START(id)
    /* Radio requests */
    _MTLK_CORE_HANDLE_REQ_SERIALIZABLE(WAVE_CORE_REQ_ACTIVATE_OPEN,             _mtlk_core_activate);
    _MTLK_CORE_HANDLE_REQ_SERIALIZABLE(WAVE_CORE_REQ_SET_BEACON,                wave_beacon_man_beacon_set);
    _MTLK_CORE_HANDLE_REQ_SERIALIZABLE(WAVE_CORE_REQ_SET_BEACON_INTERVAL,       _mtlk_beacon_man_set_beacon_interval);
    _MTLK_CORE_HANDLE_REQ_SERIALIZABLE(WAVE_CORE_REQ_REQUEST_AID,               core_cfg_request_aid);
    _MTLK_CORE_HANDLE_REQ_SERIALIZABLE(WAVE_CORE_REQ_REMOVE_AID,                core_cfg_remove_aid);
    _MTLK_CORE_HANDLE_REQ_SERIALIZABLE(WAVE_CORE_REQ_SYNC_DONE,                 _wave_core_sync_done)
    _MTLK_CORE_HANDLE_REQ_SERIALIZABLE(WAVE_CORE_REQ_CHANGE_BSS,                _core_change_bss)
    _MTLK_CORE_HANDLE_REQ_SERIALIZABLE(WAVE_CORE_REQ_GET_STATION,               core_cfg_get_station);
    _MTLK_CORE_HANDLE_REQ_SERIALIZABLE(WAVE_CORE_REQ_SET_WMM_PARAM,             core_cfg_wmm_param_set);
    _MTLK_CORE_HANDLE_REQ_SYNCHRONOUS(WAVE_CORE_REQ_MGMT_TX,                    _mtlk_core_mgmt_tx);
    _MTLK_CORE_HANDLE_REQ_SYNCHRONOUS(WAVE_CORE_REQ_MGMT_RX,                    _mtlk_core_mgmt_rx);
    _MTLK_CORE_HANDLE_REQ_SERIALIZABLE(WAVE_CORE_REQ_AP_CONNECT_STA,            _mtlk_core_ap_connect_sta);
    _MTLK_CORE_HANDLE_REQ_SERIALIZABLE(WAVE_CORE_REQ_AP_DISCONNECT_STA,         _mtlk_core_ap_disconnect_sta);
    _MTLK_CORE_HANDLE_REQ_SERIALIZABLE(WAVE_CORE_REQ_AP_DISCONNECT_ALL,         core_cfg_ap_disconnect_all);
    _MTLK_CORE_HANDLE_REQ_SERIALIZABLE(WAVE_CORE_REQ_AUTHORIZING_STA,           _mtlk_core_ap_authorizing_sta);
    _MTLK_CORE_HANDLE_REQ_SERIALIZABLE(WAVE_CORE_REQ_DEACTIVATE,                _mtlk_core_deactivate);
    _MTLK_CORE_HANDLE_REQ_SERIALIZABLE(WAVE_CORE_REQ_SET_MAC_ADDR,              _mtlk_core_set_mac_addr_wrapper);
    _MTLK_CORE_HANDLE_REQ_SERIALIZABLE(WAVE_CORE_REQ_GET_MAC_ADDR,              _mtlk_core_get_mac_addr);
    _MTLK_CORE_HANDLE_REQ_SERIALIZABLE(WAVE_CORE_REQ_GET_STATUS,                _mtlk_core_get_status);
    _MTLK_CORE_HANDLE_REQ_SERIALIZABLE(WAVE_CORE_REQ_GET_TX_RX_WARN,            mtlk_core_get_tx_rx_warn);
    _MTLK_CORE_HANDLE_REQ_SERIALIZABLE(WAVE_CORE_REQ_SET_WDS_CFG,               _mtlk_core_set_wds_cfg);
    _MTLK_CORE_HANDLE_REQ_SERIALIZABLE(WAVE_CORE_REQ_GET_WDS_CFG,               _mtlk_core_get_wds_cfg);
    _MTLK_CORE_HANDLE_REQ_SERIALIZABLE(WAVE_CORE_REQ_GET_WDS_PEERAP,            _mtlk_core_get_wds_peer_ap);
    _MTLK_CORE_HANDLE_REQ_SERIALIZABLE(WAVE_CORE_REQ_GET_CORE_CFG,              _mtlk_core_get_core_cfg);
    _MTLK_CORE_HANDLE_REQ_SERIALIZABLE(WAVE_CORE_REQ_SET_CORE_CFG,              _mtlk_core_set_core_cfg);
    _MTLK_CORE_HANDLE_REQ_SERIALIZABLE(WAVE_CORE_REQ_GET_RANGE_INFO,            _mtlk_core_range_info_get);
    _MTLK_CORE_HANDLE_REQ_SERIALIZABLE(WAVE_CORE_REQ_GET_STADB_STATUS,          _mtlk_core_get_stadb_sta_list);
    _MTLK_CORE_HANDLE_REQ_SERIALIZABLE(WAVE_CORE_REQ_SET_WDS_WEP_ENC_CFG,       mtlk_core_cfg_set_wds_wep_enc_cfg);
    _MTLK_CORE_HANDLE_REQ_SERIALIZABLE(WAVE_CORE_REQ_GET_ENCEXT_CFG,            mtlk_core_get_enc_ext_cfg);
    _MTLK_CORE_HANDLE_REQ_SERIALIZABLE(WAVE_CORE_REQ_SET_ENCEXT_CFG,            mtlk_core_set_enc_ext_cfg);
    _MTLK_CORE_HANDLE_REQ_SERIALIZABLE(WAVE_CORE_REQ_SET_DEFAULT_KEY_CFG,       mtlk_core_set_default_key_cfg);
#ifdef CONFIG_WAVE_RTLOG_REMOTE
    _MTLK_CORE_HANDLE_REQ_SERIALIZABLE(WAVE_CORE_REQ_SET_RTLOG_CFG,             _mtlk_core_set_rtlog_cfg);
#endif
    _MTLK_CORE_HANDLE_REQ_SERIALIZABLE(MTLK_CORE_REQ_MCAST_HELPER_GROUP_ID_ACTION, _mtlk_core_mcast_helper_group_id_action);
    _MTLK_CORE_HANDLE_REQ_SERIALIZABLE(WAVE_CORE_REQ_GET_RX_TH,                 mtlk_core_cfg_get_rx_threshold);
    _MTLK_CORE_HANDLE_REQ_SERIALIZABLE(WAVE_CORE_REQ_SET_RX_TH,                 mtlk_core_cfg_set_rx_threshold);
    _MTLK_CORE_HANDLE_REQ_SERIALIZABLE(WAVE_CORE_REQ_SET_QOS_MAP,               _mtlk_core_set_qos_map);
    _MTLK_CORE_HANDLE_REQ_SERIALIZABLE(WAVE_CORE_REQ_SET_AGGR_CONFIG,           _mtlk_core_set_aggr_cfg);
    _MTLK_CORE_HANDLE_REQ_SERIALIZABLE(WAVE_CORE_REQ_GET_AGGR_CONFIG,           _mtlk_core_get_aggr_cfg);
    _MTLK_CORE_HANDLE_REQ_SERIALIZABLE(WAVE_CORE_REQ_SET_SOFTBLOCKLIST_ENTRY,   wave_core_set_softblocklist_entry);
    _MTLK_CORE_HANDLE_REQ_SERIALIZABLE(WAVE_CORE_REQ_SET_BLACKLIST_ENTRY,       wave_core_clpb_set_blacklist_entry);
    _MTLK_CORE_HANDLE_REQ_SERIALIZABLE(WAVE_CORE_REQ_GET_ASSOCIATED_DEV_RATE_INFO_RX_STATS,  mtlk_core_get_associated_dev_rate_info_rx_stats_clb);
    _MTLK_CORE_HANDLE_REQ_SERIALIZABLE(WAVE_CORE_REQ_GET_ASSOCIATED_DEV_RATE_INFO_TX_STATS,  mtlk_core_get_associated_dev_rate_info_tx_stats_clb);
    _MTLK_CORE_HANDLE_REQ_SERIALIZABLE(WAVE_CORE_REQ_GET_STATION_MEASUREMENTS,  mtlk_core_get_station_measurements);
    _MTLK_CORE_HANDLE_REQ_SERIALIZABLE(WAVE_CORE_REQ_GET_VAP_MEASUREMENTS,      _mtlk_core_get_vap_measurements);
    _MTLK_CORE_HANDLE_REQ_SERIALIZABLE(WAVE_CORE_REQ_GET_UNCONNECTED_STATION,   mtlk_core_get_unconnected_station);
    _MTLK_CORE_HANDLE_REQ_SERIALIZABLE(WAVE_CORE_REQ_SET_FOUR_ADDR_CFG,         core_cfg_set_four_addr_cfg);
    _MTLK_CORE_HANDLE_REQ_SERIALIZABLE(WAVE_CORE_REQ_GET_FOUR_ADDR_STA_LIST,    core_cfg_get_four_addr_sta_list);
    _MTLK_CORE_HANDLE_REQ_SERIALIZABLE(WAVE_CORE_REQ_SET_ATF_QUOTAS,            mtlk_core_cfg_set_atf_quotas);
    _MTLK_CORE_HANDLE_REQ_SERIALIZABLE(WAVE_CORE_REQ_SET_MCAST_RANGE,           mtlk_core_cfg_set_mcast_range);
    _MTLK_CORE_HANDLE_REQ_SERIALIZABLE(WAVE_CORE_REQ_GET_MCAST_RANGE_IPV4,      mtlk_core_cfg_get_mcast_range_list_ipv4);
    _MTLK_CORE_HANDLE_REQ_SERIALIZABLE(WAVE_CORE_REQ_GET_MCAST_RANGE_IPV6,      mtlk_core_cfg_get_mcast_range_list_ipv6);
    _MTLK_CORE_HANDLE_REQ_SERIALIZABLE(WAVE_CORE_REQ_SET_FWRD_UNKWN_MCAST_FLAG, mtlk_core_cfg_set_forward_unknown_mcast_flag);
    _MTLK_CORE_HANDLE_REQ_SERIALIZABLE(WAVE_CORE_REQ_GET_FWRD_UNKWN_MCAST_FLAG, mtlk_core_cfg_get_forward_unknown_mcast_flag);
    _MTLK_CORE_HANDLE_REQ_SERIALIZABLE(WAVE_CORE_REQ_SET_OPERATING_MODE,        mtlk_core_cfg_set_operating_mode);
    _MTLK_CORE_HANDLE_REQ_SERIALIZABLE(WAVE_CORE_REQ_SET_WDS_WPA_LIST_ENTRY,    mtlk_core_cfg_set_wds_wpa_entry);
    _MTLK_CORE_HANDLE_REQ_SERIALIZABLE(WAVE_CORE_REQ_GET_TX_POWER,             _mtlk_core_get_tx_power);
    _MTLK_CORE_HANDLE_REQ_SERIALIZABLE(WAVE_CORE_REQ_SET_DYNAMIC_MC_RATE,       _wave_core_set_multicast_rate);
#ifdef UNUSED_CODE
    _MTLK_CORE_HANDLE_REQ_SERIALIZABLE(WAVE_CORE_REQ_ABORT_CCA,                 wave_core_abort_cca);
#endif /* UNUSED_CODE */

    _MTLK_CORE_HANDLE_REQ_SERIALIZABLE(WAVE_RADIO_REQ_GET_RADIO_INFO,           _mtlk_core_get_radio_info);
    _MTLK_CORE_HANDLE_REQ_SERIALIZABLE(WAVE_RADIO_REQ_PREPARE_CAC_START,        wave_core_cfg_prepare_cac_start);
    _MTLK_CORE_HANDLE_REQ_SERIALIZABLE(WAVE_RADIO_REQ_NOTIFY_CAC_FINISHED,      wave_core_cfg_notify_cac_finished);
    _MTLK_CORE_HANDLE_REQ_SERIALIZABLE(WAVE_RADIO_REQ_SET_CHAN,                 core_cfg_set_chan_clpb);
    _MTLK_CORE_HANDLE_REQ_SERIALIZABLE(WAVE_RADIO_REQ_DO_SCAN,                  scan_do_scan);
    _MTLK_CORE_HANDLE_REQ_SERIALIZABLE(WAVE_RADIO_REQ_SCAN_TIMEOUT,             scan_timeout_async_func);
    _MTLK_CORE_HANDLE_REQ_SERIALIZABLE(WAVE_RADIO_REQ_ALTER_SCAN,               mtlk_alter_scan)
    _MTLK_CORE_HANDLE_REQ_SYNCHRONOUS(WAVE_RADIO_REQ_DUMP_SURVEY,               scan_dump_survey);
    _MTLK_CORE_HANDLE_REQ_SERIALIZABLE(WAVE_RADIO_REQ_FIN_PREV_FW_SC,           finish_and_prevent_fw_set_chan_clpb);
    _MTLK_CORE_HANDLE_REQ_SERIALIZABLE(WAVE_RADIO_REQ_GET_DOT11H_AP_CFG,        _mtlk_core_get_dot11h_ap_cfg);
    _MTLK_CORE_HANDLE_REQ_SERIALIZABLE(WAVE_RADIO_REQ_SET_DOT11H_AP_CFG,        _mtlk_core_set_dot11h_ap_cfg);
    _MTLK_CORE_HANDLE_REQ_SERIALIZABLE(WAVE_RADIO_REQ_GET_MASTER_CFG,           _mtlk_core_get_master_specific_cfg);
    _MTLK_CORE_HANDLE_REQ_SERIALIZABLE(WAVE_RADIO_REQ_SET_MASTER_CFG,           _mtlk_core_set_master_specific_cfg);
    _MTLK_CORE_HANDLE_REQ_SERIALIZABLE(WAVE_RADIO_REQ_GET_PHY_RX_STATUS,        _mtlk_core_get_phy_rx_status);
    _MTLK_CORE_HANDLE_REQ_SERIALIZABLE(WAVE_RADIO_REQ_GET_PHY_CHAN_STATUS,      _mtlk_core_get_phy_channel_status);
    _MTLK_CORE_HANDLE_REQ_SERIALIZABLE(WAVE_RADIO_REQ_GET_TX_RATE_POWER,        _mtlk_core_get_tx_rate_power);
    _MTLK_CORE_HANDLE_REQ_SERIALIZABLE(WAVE_RADIO_REQ_GET_TPC_CFG,              mtlk_core_get_tpc_cfg);
    _MTLK_CORE_HANDLE_REQ_SERIALIZABLE(WAVE_RADIO_REQ_SET_TPC_CFG,              mtlk_core_set_tpc_cfg);
    _MTLK_CORE_HANDLE_REQ_SERIALIZABLE(WAVE_RADIO_REQ_GET_COC_CFG,              _mtlk_core_get_coc_cfg);
    _MTLK_CORE_HANDLE_REQ_SERIALIZABLE(WAVE_RADIO_REQ_SET_COC_CFG,              _mtlk_core_set_coc_cfg);
    _MTLK_CORE_HANDLE_REQ_SERIALIZABLE(WAVE_RADIO_REQ_GET_ERP_CFG,              mtlk_core_coc_get_erp_mode);
    _MTLK_CORE_HANDLE_REQ_SERIALIZABLE(WAVE_RADIO_REQ_SET_ERP_CFG,              mtlk_core_coc_set_erp_mode);
    _MTLK_CORE_HANDLE_REQ_SERIALIZABLE(WAVE_RADIO_REQ_MBSS_ADD_VAP_IDX,         _mtlk_core_add_vap_idx);
    _MTLK_CORE_HANDLE_REQ_SERIALIZABLE(WAVE_RADIO_REQ_MBSS_ADD_VAP_NAME,        _mtlk_core_add_vap_name);
    _MTLK_CORE_HANDLE_REQ_SERIALIZABLE(WAVE_RADIO_REQ_MBSS_DEL_VAP_IDX,         _mtlk_core_del_vap_idx);
    _MTLK_CORE_HANDLE_REQ_SERIALIZABLE(WAVE_RADIO_REQ_MBSS_DEL_VAP_NAME,        _mtlk_core_del_vap_name);
    _MTLK_CORE_HANDLE_REQ_SERIALIZABLE(WAVE_RADIO_REQ_MBSS_VAP_CREATE_SEC_VAP,  mtlk_core_cfg_create_sec_vap);
    _MTLK_CORE_HANDLE_REQ_SERIALIZABLE(WAVE_RADIO_REQ_MBSS_VAP_DEL_SEC_VAP,     mtlk_core_cfg_del_sec_vap);
    /* Interference Detection */
    _MTLK_CORE_HANDLE_REQ_SERIALIZABLE(WAVE_RADIO_REQ_SET_INTERFDET_CFG,        _mtlk_core_set_interfdet_cfg);
    _MTLK_CORE_HANDLE_REQ_SERIALIZABLE(WAVE_RADIO_REQ_GET_INTERFDET_CFG,        _mtlk_core_get_interfdet_cfg);
    _MTLK_CORE_HANDLE_REQ_SERIALIZABLE(WAVE_RADIO_REQ_EMULATE_INTERFERER,       _mtlk_core_emulate_interferer);
    _MTLK_CORE_HANDLE_REQ_SERIALIZABLE(WAVE_RADIO_REQ_SET_11B_CFG,              _mtlk_core_set_11b_cfg);
    _MTLK_CORE_HANDLE_REQ_SERIALIZABLE(WAVE_RADIO_REQ_GET_11B_CFG,              _mtlk_core_get_11b_cfg);
    _MTLK_CORE_HANDLE_REQ_SERIALIZABLE(WAVE_RADIO_REQ_SET_RECOVERY_CFG,         wave_core_set_recovery_cfg);
    _MTLK_CORE_HANDLE_REQ_SERIALIZABLE(WAVE_RADIO_REQ_GET_RECOVERY_CFG,         wave_core_get_recovery_cfg);
    _MTLK_CORE_HANDLE_REQ_SERIALIZABLE(WAVE_RADIO_REQ_GET_RECOVERY_STATS,       wave_core_get_recovery_stats);
    _MTLK_CORE_HANDLE_REQ_SERIALIZABLE(WAVE_RADIO_REQ_SET_SCAN_AND_CALIB_CFG,   _mtlk_core_set_scan_and_calib_cfg);
    _MTLK_CORE_HANDLE_REQ_SERIALIZABLE(WAVE_RADIO_REQ_GET_SCAN_AND_CALIB_CFG,   _mtlk_core_get_scan_and_calib_cfg);
    _MTLK_CORE_HANDLE_REQ_SERIALIZABLE(WAVE_RADIO_REQ_SET_ALLOW_SCAN_DURING_CAC, _mtlk_core_set_allow_scan_during_cac);
    _MTLK_CORE_HANDLE_REQ_SERIALIZABLE(WAVE_RADIO_REQ_GET_ALLOW_SCAN_DURING_CAC, _mtlk_core_get_allow_scan_during_cac);
    _MTLK_CORE_HANDLE_REQ_SERIALIZABLE(WAVE_RADIO_REQ_GET_AGG_RATE_LIMIT,       _mtlk_core_get_agg_rate_limit);
    _MTLK_CORE_HANDLE_REQ_SERIALIZABLE(WAVE_RADIO_REQ_SET_AGG_RATE_LIMIT,       _mtlk_core_set_agg_rate_limit);
    _MTLK_CORE_HANDLE_REQ_SERIALIZABLE(WAVE_RADIO_REQ_GET_RX_DUTY_CYCLE,        mtlk_core_cfg_get_rx_duty_cycle);
    _MTLK_CORE_HANDLE_REQ_SERIALIZABLE(WAVE_RADIO_REQ_SET_RX_DUTY_CYCLE,        mtlk_core_cfg_set_rx_duty_cycle);
    _MTLK_CORE_HANDLE_REQ_SERIALIZABLE(WAVE_RADIO_REQ_GET_TX_POWER_LIMIT_OFFSET,  _mtlk_core_get_tx_power_limit_offset);
    _MTLK_CORE_HANDLE_REQ_SERIALIZABLE(WAVE_RADIO_REQ_SET_TX_POWER_LIMIT_OFFSET,  _mtlk_core_set_tx_power_limit_offset);
    _MTLK_CORE_HANDLE_REQ_SERIALIZABLE(WAVE_CORE_REQ_GET_HT_PROTECTION,         _mtlk_core_get_ht_protection)
    _MTLK_CORE_HANDLE_REQ_SERIALIZABLE(WAVE_CORE_REQ_SET_HT_PROTECTION,         _mtlk_core_set_ht_protection)
    _MTLK_CORE_HANDLE_REQ_SERIALIZABLE(WAVE_RADIO_REQ_SET_QAMPLUS_MODE,         _mtlk_core_set_qamplus_mode);
    _MTLK_CORE_HANDLE_REQ_SERIALIZABLE(WAVE_RADIO_REQ_GET_QAMPLUS_MODE,         _mtlk_core_get_qamplus_mode);
    _MTLK_CORE_HANDLE_REQ_SERIALIZABLE(WAVE_RADIO_REQ_SET_RADIO_MODE,           _mtlk_core_set_radio_mode);
    _MTLK_CORE_HANDLE_REQ_SERIALIZABLE(WAVE_RADIO_REQ_GET_RADIO_MODE,           _mtlk_core_get_radio_mode);
    _MTLK_CORE_HANDLE_REQ_SERIALIZABLE(WAVE_RADIO_REQ_SET_AMSDU_NUM,            _mtlk_core_set_amsdu_num);
    _MTLK_CORE_HANDLE_REQ_SERIALIZABLE(WAVE_RADIO_REQ_GET_AMSDU_NUM,            mtlk_core_get_amsdu_num);
    _MTLK_CORE_HANDLE_REQ_SERIALIZABLE(WAVE_RADIO_REQ_SET_CCA_THRESHOLD,        mtlk_core_cfg_set_cca_threshold);
    _MTLK_CORE_HANDLE_REQ_SERIALIZABLE(WAVE_RADIO_REQ_GET_CCA_THRESHOLD,        mtlk_core_cfg_get_cca_threshold);
    _MTLK_CORE_HANDLE_REQ_SERIALIZABLE(WAVE_RADIO_REQ_SET_CCA_ADAPTIVE,         mtlk_core_cfg_set_cca_intervals);
    _MTLK_CORE_HANDLE_REQ_SERIALIZABLE(WAVE_RADIO_REQ_GET_CCA_ADAPTIVE,         mtlk_core_cfg_get_cca_intervals);
    _MTLK_CORE_HANDLE_REQ_SERIALIZABLE(WAVE_RADIO_REQ_SET_RADAR_RSSI_TH,        mtlk_core_cfg_set_radar_rssi_threshold);
    _MTLK_CORE_HANDLE_REQ_SERIALIZABLE(WAVE_RADIO_REQ_GET_RADAR_RSSI_TH,        mtlk_core_cfg_get_radar_rssi_threshold);
    _MTLK_CORE_HANDLE_REQ_SERIALIZABLE(WAVE_RADIO_REQ_SET_FILS_BEACON_FLAG,        mtlk_core_cfg_set_fils_beacon_flag);
    _MTLK_CORE_HANDLE_REQ_SERIALIZABLE(WAVE_RADIO_REQ_GET_FILS_BEACON_FLAG,        mtlk_core_cfg_get_fils_beacon_flag);
    _MTLK_CORE_HANDLE_REQ_SERIALIZABLE(WAVE_RADIO_REQ_SET_MAX_MPDU_LENGTH,      mtlk_core_cfg_set_max_mpdu_length);
    _MTLK_CORE_HANDLE_REQ_SERIALIZABLE(WAVE_RADIO_REQ_GET_MAX_MPDU_LENGTH,      mtlk_core_cfg_get_max_mpdu_length);
    _MTLK_CORE_HANDLE_REQ_SERIALIZABLE(WAVE_RADIO_SET_STATIC_PLAN,              mtlk_core_cfg_set_static_plan);
    _MTLK_CORE_HANDLE_REQ_SERIALIZABLE(WAVE_RADIO_REQ_SET_SSB_MODE,             mtlk_core_set_ssb_mode);
    _MTLK_CORE_HANDLE_REQ_SERIALIZABLE(WAVE_RADIO_REQ_GET_SSB_MODE,             mtlk_core_get_ssb_mode);
    _MTLK_CORE_HANDLE_REQ_SERIALIZABLE(WAVE_RADIO_REQ_SET_COEX_CFG,             mtlk_core_set_coex_cfg);
    _MTLK_CORE_HANDLE_REQ_SERIALIZABLE(WAVE_RADIO_REQ_GET_COEX_CFG,             mtlk_core_get_coex_cfg);
    _MTLK_CORE_HANDLE_REQ_SERIALIZABLE(WAVE_RADIO_REQ_SET_RESTRICTED_AC_MODE,    mtlk_core_cfg_set_restricted_ac_mode_cfg);
    _MTLK_CORE_HANDLE_REQ_SERIALIZABLE(WAVE_RADIO_REQ_GET_RESTRICTED_AC_MODE,    mtlk_core_cfg_get_restricted_ac_mode_cfg);
    _MTLK_CORE_HANDLE_REQ_SERIALIZABLE(WAVE_RADIO_REQ_CHANGE_BSS,                _mtlk_core_change_bss);
    _MTLK_CORE_HANDLE_REQ_SERIALIZABLE(WAVE_RADIO_REQ_SET_AP_BEACON_INFO,        _mtlk_core_set_ap_beacon_info);
    _MTLK_CORE_HANDLE_REQ_SERIALIZABLE(WAVE_RADIO_REQ_SET_CALIBRATION_MASK,      core_cfg_set_calibration_mask);
    _MTLK_CORE_HANDLE_REQ_SERIALIZABLE(WAVE_RADIO_REQ_GET_CALIBRATION_MASK,      core_cfg_get_calibration_mask);
    _MTLK_CORE_HANDLE_REQ_SERIALIZABLE(WAVE_RADIO_REQ_GET_RTS_THRESHOLD,         wave_core_get_rts_threshold);
    _MTLK_CORE_HANDLE_REQ_SERIALIZABLE(WAVE_RADIO_REQ_SET_RTS_THRESHOLD,         wave_core_set_rts_threshold);
    _MTLK_CORE_HANDLE_REQ_SERIALIZABLE(WAVE_RADIO_REQ_GET_MU_OFDMA_BF,           _wave_core_get_mu_ofdma_bf);
    _MTLK_CORE_HANDLE_REQ_SERIALIZABLE(WAVE_RADIO_REQ_SET_MU_OFDMA_BF,           _wave_core_set_mu_ofdma_bf);
    _MTLK_CORE_HANDLE_REQ_SERIALIZABLE(WAVE_RADIO_REQ_GET_20MHZ_TX_POWER,        wave_core_cfg_get_20mhz_tx_power);
    _MTLK_CORE_HANDLE_REQ_SERIALIZABLE(WAVE_RADIO_REQ_UPDATE_WIPHY_REGDB,      wave_core_cfg_update_wiphy_regdb);
    _MTLK_CORE_HANDLE_REQ_SERIALIZABLE(WAVE_RADIO_REQ_UPDATE_AFC_REG_INFO,     wave_core_cfg_update_afc_reg_info);

    /* HW requests */
#ifdef EEPROM_DATA_ACCESS
    _MTLK_CORE_HANDLE_REQ_SERIALIZABLE(WAVE_HW_REQ_GET_EEPROM_CFG,              _mtlk_core_get_eeprom_cfg);
#endif /* EEPROM_DATA_ACCESS */
    _MTLK_CORE_HANDLE_REQ_SERIALIZABLE(WAVE_HW_REQ_GET_AP_CAPABILITIES,         _mtlk_core_get_ap_capabilities)
    _MTLK_CORE_HANDLE_REQ_SERIALIZABLE(WAVE_HW_REQ_SET_TEMPERATURE_SENSOR,      _mtlk_core_set_calibrate_on_demand);
    _MTLK_CORE_HANDLE_REQ_SERIALIZABLE(WAVE_HW_REQ_GET_TEMPERATURE_SENSOR,      _mtlk_core_get_temperature);
    _MTLK_CORE_HANDLE_REQ_SERIALIZABLE(WAVE_HW_REQ_GET_PVT_SENSOR,              wave_core_get_pvt_sensor);
    _MTLK_CORE_HANDLE_REQ_SERIALIZABLE(WAVE_RCVRY_RESET,                        _wave_core_rcvry_reset);
    _MTLK_CORE_HANDLE_REQ_SERIALIZABLE(WAVE_HW_REQ_SET_PCIE_SPEED,              _wave_core_set_pcie_speed_cfg);
    _MTLK_CORE_HANDLE_REQ_SERIALIZABLE(WAVE_HW_REQ_GET_ZWDFS_ANT_ENABLED,       wave_core_get_zwdfs_antenna_enabled);
    _MTLK_CORE_HANDLE_REQ_SERIALIZABLE(WAVE_HW_REQ_SET_ZWDFS_ANT_ENABLED,       wave_core_set_zwdfs_antenna_enabled);
    _MTLK_CORE_HANDLE_REQ_SERIALIZABLE(WAVE_HW_REQ_SET_ZWDFS_CARD_ANT_CONFIG,   wave_core_set_zwdfs_card_antennas_config);

    _MTLK_CORE_HANDLE_REQ_SERIALIZABLE(WAVE_CORE_REQ_GET_NETWORK_MODE,          _wave_core_network_mode_get);
    _MTLK_CORE_HANDLE_REQ_SERIALIZABLE(WAVE_RADIO_REQ_GET_RTS_RATE,             wave_core_cfg_get_rts_rate);
    _MTLK_CORE_HANDLE_REQ_SERIALIZABLE(WAVE_RADIO_REQ_SET_RTS_RATE,             wave_core_cfg_set_rts_rate);
#ifdef MTLK_PER_RATE_STAT
    _MTLK_CORE_HANDLE_REQ_SERIALIZABLE(WAVE_RADIO_REQ_SET_STATIONS_STATS,       wave_core_cfg_set_stations_stats_enabled);
    _MTLK_CORE_HANDLE_REQ_SERIALIZABLE(WAVE_RADIO_REQ_GET_STATIONS_STATS,       wave_core_cfg_get_stations_stats_enabled);
#endif /* MTLK_PER_RATE_STAT */

    _MTLK_CORE_HANDLE_REQ_SERIALIZABLE(WAVE_RADIO_REQ_GET_PHY_INBAND_POWER,     _wave_core_get_phy_inband_power);

    _MTLK_CORE_HANDLE_REQ_SERIALIZABLE(WAVE_CORE_REQ_GET_ASSOCIATED_DEV_STATS,    mtlk_core_get_associated_dev_stats);
    _MTLK_CORE_HANDLE_REQ_SERIALIZABLE(WAVE_CORE_REQ_GET_WIFI_CHANNEL_STATS,      mtlk_core_get_wifi_channel_stats);
    _MTLK_CORE_HANDLE_REQ_SERIALIZABLE(WAVE_CORE_REQ_GET_DRV_CHANNEL_STATS,       mtlk_core_get_drv_channel_stats);
    _MTLK_CORE_HANDLE_REQ_SERIALIZABLE(WAVE_CORE_REQ_GET_ASSOCIATED_DEV_TID_STATS,  mtlk_core_get_associated_dev_tid_stats);

    _MTLK_CORE_HANDLE_REQ_SERIALIZABLE(WAVE_CORE_REQ_GET_STATS_POLL_PERIOD,      mtlk_core_stats_poll_period_get);
    _MTLK_CORE_HANDLE_REQ_SERIALIZABLE(WAVE_CORE_REQ_SET_STATS_POLL_PERIOD,      mtlk_core_stats_poll_period_set);

    _MTLK_CORE_HANDLE_REQ_SERIALIZABLE(WAVE_CORE_REQ_GET_PEER_LIST,             mtlk_core_get_peer_list);
    _MTLK_CORE_HANDLE_REQ_SERIALIZABLE(WAVE_CORE_REQ_GET_PEER_FLOW_STATUS,      mtlk_core_get_peer_flow_status);
    _MTLK_CORE_HANDLE_REQ_SERIALIZABLE(WAVE_CORE_REQ_GET_PEER_CAPABILITIES,     mtlk_core_get_peer_capabilities);
    _MTLK_CORE_HANDLE_REQ_SERIALIZABLE(WAVE_CORE_REQ_GET_PEER_RATE_INFO,        mtlk_core_get_peer_rate_info);
    _MTLK_CORE_HANDLE_REQ_SERIALIZABLE(WAVE_CORE_REQ_GET_RECOVERY_STATS,        mtlk_core_get_recovery_stats);
    _MTLK_CORE_HANDLE_REQ_SERIALIZABLE(WAVE_CORE_REQ_GET_HW_FLOW_STATUS,        mtlk_core_get_hw_flow_status);
    _MTLK_CORE_HANDLE_REQ_SERIALIZABLE(WAVE_CORE_REQ_GET_TR181_WLAN_STATS,      mtlk_core_get_tr181_wlan_statistics);
    _MTLK_CORE_HANDLE_REQ_SERIALIZABLE(WAVE_CORE_REQ_GET_TR181_HW_STATS,        mtlk_core_get_tr181_hw_statistics);
    _MTLK_CORE_HANDLE_REQ_SERIALIZABLE(WAVE_CORE_REQ_GET_TR181_PEER_STATS,      mtlk_core_get_tr181_peer_statistics);
    _MTLK_CORE_HANDLE_REQ_SERIALIZABLE(WAVE_CORE_REQ_GET_DEV_DIAG_RESULT2,      wave_core_get_dev_diag_result2);
    _MTLK_CORE_HANDLE_REQ_SERIALIZABLE(WAVE_CORE_REQ_GET_DEV_DIAG_RESULT3,      wave_core_get_dev_diag_result3);
    _MTLK_CORE_HANDLE_REQ_SERIALIZABLE(WAVE_CORE_REQ_GET_ASSOC_STATIONS_STATS,  wave_core_get_associated_stations_stats);
    _MTLK_CORE_HANDLE_REQ_SERIALIZABLE(WAVE_CORE_REQ_GET_PRIORITY_GPIO_STATS,   mtlk_core_get_priority_gpio_statistics);

    _MTLK_CORE_HANDLE_REQ_SERIALIZABLE(WAVE_HW_REQ_SET_DYNAMIC_MU_CFG,          wave_core_cfg_set_dynamic_mu_cfg);
    _MTLK_CORE_HANDLE_REQ_SERIALIZABLE(WAVE_HW_REQ_GET_DYNAMIC_MU_CFG,          wave_core_cfg_get_dynamic_mu_cfg);

    _MTLK_CORE_HANDLE_REQ_SERIALIZABLE(WAVE_CORE_REQ_GET_TWT_PARAMETERS,        wave_core_cfg_get_twt_params);
    _MTLK_CORE_HANDLE_REQ_SERIALIZABLE(WAVE_CORE_REQ_GET_AX_DEFAULT_PARAMS,     wave_core_cfg_get_ax_defaults);
    _MTLK_CORE_HANDLE_REQ_SERIALIZABLE(WAVE_RADIO_REQ_GET_BSS_TX_STATUS,       _wave_core_bss_tx_status_get);

    _MTLK_CORE_HANDLE_REQ_SERIALIZABLE(WAVE_RADIO_REQ_GET_ETSI_PPDU_LIMITS,     wave_core_cfg_get_etsi_ppdu_duration_limits);
    _MTLK_CORE_HANDLE_REQ_SERIALIZABLE(WAVE_RADIO_REQ_SET_ETSI_PPDU_LIMITS,     wave_core_cfg_set_etsi_ppdu_duration_limits);

    _MTLK_CORE_HANDLE_REQ_SERIALIZABLE(WAVE_RADIO_REQ_SET_AP_RETRY_LIMIT,       wave_core_cfg_set_ap_retry_limit);
    _MTLK_CORE_HANDLE_REQ_SERIALIZABLE(WAVE_RADIO_REQ_GET_AP_RETRY_LIMIT,       wave_core_cfg_get_ap_retry_limit);

    _MTLK_CORE_HANDLE_REQ_SERIALIZABLE(WAVE_CORE_REQ_SET_AP_EXCE_RETRY_LIMIT,  wave_core_cfg_set_ap_exce_retry_limit);
    _MTLK_CORE_HANDLE_REQ_SERIALIZABLE(WAVE_CORE_REQ_GET_AP_EXCE_RETRY_LIMIT,  wave_core_cfg_get_ap_exce_retry_limit);

    _MTLK_CORE_HANDLE_REQ_SERIALIZABLE(WAVE_CORE_REQ_SET_CHAN_SWITCH_DEAUTH_PARAMS,   _mtlk_core_cfg_store_chan_switch_deauth_params);

    _MTLK_CORE_HANDLE_REQ_SERIALIZABLE(WAVE_RADIO_REQ_GET_CTS_TO_SELF_TO,       wave_core_get_cts_to_self_to);
    _MTLK_CORE_HANDLE_REQ_SERIALIZABLE(WAVE_RADIO_REQ_SET_CTS_TO_SELF_TO,       wave_core_set_cts_to_self_to);

    _MTLK_CORE_HANDLE_REQ_SERIALIZABLE(WAVE_RADIO_REQ_GET_TX_AMPDU_DENSITY,     wave_core_get_tx_ampdu_density);
    _MTLK_CORE_HANDLE_REQ_SERIALIZABLE(WAVE_RADIO_REQ_SET_TX_AMPDU_DENSITY,     wave_core_set_tx_ampdu_density);
    _MTLK_CORE_HANDLE_REQ_SERIALIZABLE(WAVE_CORE_REQ_SET_UNSOLICITED_FRAME_TX,  wave_beacon_man_set_unsolicited_frame_tx);
    _MTLK_CORE_HANDLE_REQ_SERIALIZABLE(WAVE_RADIO_REQ_SET_INITAL_DATA,          wave_core_set_initial_data);
    _MTLK_CORE_HANDLE_REQ_SERIALIZABLE(WAVE_RADIO_REQ_STEER_STA,                wave_core_steer_sta);
    _MTLK_CORE_HANDLE_REQ_SERIALIZABLE(WAVE_CORE_REQ_GET_HE_OPERATION,          wave_core_get_he_operation);
    _MTLK_CORE_HANDLE_REQ_SERIALIZABLE(WAVE_CORE_REQ_SET_HE_NON_ADVERTISED,     wave_core_set_he_non_advertised);
    _MTLK_CORE_HANDLE_REQ_SERIALIZABLE(WAVE_CORE_REQ_GET_HE_NON_ADVERTISED,     wave_core_get_he_non_advertised);
    _MTLK_CORE_HANDLE_REQ_SERIALIZABLE(WAVE_CORE_REQ_SET_HE_DEBUG,              wave_core_set_he_debug_data);
    _MTLK_CORE_HANDLE_REQ_SERIALIZABLE(WAVE_CORE_REQ_SET_FILS_DISCOVERY_FRAME,  wave_core_store_fils_discovery_frame);
    _MTLK_CORE_HANDLE_REQ_SERIALIZABLE(WAVE_CORE_REQ_CCA_STATS_GET,             wave_core_cca_stats_get);
    _MTLK_CORE_HANDLE_REQ_SERIALIZABLE(WAVE_RADIO_REQ_GET_PROBE_REQ_LIST,       wave_core_probe_req_list_get);
    _MTLK_CORE_HANDLE_REQ_SERIALIZABLE(WAVE_CORE_REQ_SET_PREAMBLE_PUNCTURE_CCA_OVERRIDE,  wave_core_cfg_set_cca_preamble_puncture_override);
    _MTLK_CORE_HANDLE_REQ_SERIALIZABLE(WAVE_CORE_REQ_GET_PREAMBLE_PUNCTURE_CCA_OVERRIDE,  wave_core_cfg_get_cca_preamble_puncture_override);
    _MTLK_CORE_HANDLE_REQ_SERIALIZABLE(WAVE_RADIO_REQ_GET_USAGE_STATS,         wave_core_radio_usage_stats_get);
    _MTLK_CORE_HANDLE_REQ_SERIALIZABLE(WAVE_CORE_REQ_ADVERTISE_BTWT_SCHEDULE,  wave_beacon_man_advertise_btwt_schedule);
    _MTLK_CORE_HANDLE_REQ_SERIALIZABLE(WAVE_CORE_REQ_TERMINATE_BTWT_SCHEDULE,  wave_beacon_man_terminate_btwt_schedule);
    _MTLK_CORE_HANDLE_REQ_SERIALIZABLE(WAVE_CORE_REQ_GET_ADVERTISED_BTWT_SCHEDULE, wave_beacon_man_get_advertised_btwt_schedule);
    _MTLK_CORE_HANDLE_REQ_SERIALIZABLE(WAVE_CORE_REQ_TX_TWT_TEARDOWN,          wave_core_tx_twt_teardown);
    _MTLK_CORE_HANDLE_REQ_SERIALIZABLE(WAVE_RADIO_REQ_GET_HW_LIMITS,            _mtlk_core_get_hw_limits);
    _MTLK_CORE_HANDLE_REQ_SERIALIZABLE(WAVE_RADIO_REQ_SET_MAC_ASSERT,           _mtlk_core_set_mac_assert);
    _MTLK_CORE_HANDLE_REQ_SERIALIZABLE(WAVE_RADIO_REQ_SET_FIXED_LTF_AND_GI,    mtlk_core_set_fixed_ltf_and_gi);
    _MTLK_CORE_HANDLE_REQ_SERIALIZABLE(WAVE_RADIO_REQ_GET_FIXED_LTF_AND_GI,    mtlk_core_get_fixed_ltf_and_gi);
    _MTLK_CORE_HANDLE_REQ_SERIALIZABLE(WAVE_RADIO_REQ_SET_WHM_CONFIG,          wave_core_set_whm_config);
    _MTLK_CORE_HANDLE_REQ_SERIALIZABLE(WAVE_RADIO_REQ_SET_WHM_RESET,           wave_core_set_whm_reset);
    _MTLK_CORE_HANDLE_REQ_SERIALIZABLE(WAVE_CORE_REQ_SET_WHM_TRIGGER,          wave_core_set_whm_trigger);
    _MTLK_CORE_HANDLE_REQ_SERIALIZABLE(WAVE_CORE_REQ_GET_CONNECTION_ALIVE,     wave_core_get_connection_alive);
    _MTLK_CORE_HANDLE_REQ_SERIALIZABLE(WAVE_CORE_REQ_RESET_STATISTICS,         wave_core_reset_statistics);
    _MTLK_CORE_HANDLE_REQ_SERIALIZABLE(WAVE_CORE_REQ_GET_MGMT_FRAME_PWR_CTRL,  wave_core_get_mgmt_frame_pwr_ctrl);
    _MTLK_CORE_HANDLE_REQ_SERIALIZABLE(WAVE_CORE_REQ_SET_MGMT_FRAME_PWR_CTRL,  wave_core_set_mgmt_frame_pwr_ctrl);
    _MTLK_CORE_HANDLE_REQ_SERIALIZABLE(WAVE_CORE_REQ_SET_CSI_ENABLE,           wave_core_set_csi_enable);
    _MTLK_CORE_HANDLE_REQ_SERIALIZABLE(WAVE_CORE_REQ_GET_CSI_ENABLE,           wave_core_get_csi_enable);
    _MTLK_CORE_HANDLE_REQ_SERIALIZABLE(WAVE_CORE_REQ_SET_CSI_SEND_QOS_NULL,    wave_core_set_csi_send_qos_null);
    _MTLK_CORE_HANDLE_REQ_SERIALIZABLE(WAVE_CORE_REQ_SET_CSI_AUTO_RATE,        wave_core_set_csi_auto_rate);
    _MTLK_CORE_HANDLE_REQ_SERIALIZABLE(WAVE_CORE_REQ_GET_CSI_AUTO_RATE,        wave_core_get_csi_auto_rate);
    _MTLK_CORE_HANDLE_REQ_SERIALIZABLE(WAVE_CORE_REQ_GET_CSI_STATS,            wave_core_get_csi_stats);
    _MTLK_CORE_HANDLE_REQ_SERIALIZABLE(WAVE_CORE_REQ_GET_CSI_COUNTERS,         wave_core_get_csi_counters);
    _MTLK_CORE_HANDLE_REQ_SERIALIZABLE(WAVE_CORE_REQ_GET_LA_MU_GROUPS_STATS,   wave_core_get_la_mu_groups_statistics);
    _MTLK_CORE_HANDLE_REQ_SERIALIZABLE(WAVE_CORE_REQ_SET_RSSI_IGNORE_PROBE_REQUEST, wave_core_cfg_set_rssi_ignore_probe_request);
    _MTLK_CORE_HANDLE_REQ_SERIALIZABLE(WAVE_CORE_REQ_GET_PEER_MIXED_STATS,     wave_core_get_peer_mixed_stats);
    _MTLK_CORE_HANDLE_REQ_SERIALIZABLE(WAVE_CORE_REQ_GET_STA_DISCNT_WARN,      mtlk_core_get_sta_discnt_whm_warn);
    _MTLK_CORE_HANDLE_REQ_SERIALIZABLE(WAVE_CORE_REQ_TRIGGER_STA_DISCNT_WHM,   wave_core_sta_discnt_whm_trigger);
    _MTLK_CORE_HANDLE_REQ_SERIALIZABLE(WAVE_CORE_REQ_SET_ACL,                  wave_core_set_acl);
    _MTLK_CORE_HANDLE_REQ_SERIALIZABLE(WAVE_CORE_REQ_GET_ACL,                  wave_core_get_acl);
    _MTLK_CORE_HANDLE_REQ_SERIALIZABLE(WAVE_RADIO_REQ_GET_MU_GRP_CFG,          wave_core_get_mu_group_cfg_params);

#ifdef MTLK_WAVE_700
    _MTLK_CORE_HANDLE_REQ_SERIALIZABLE(WAVE_CORE_REQ_SET_EHT_DEBUG,            wave_core_set_eht_debug_data);
    _MTLK_CORE_HANDLE_REQ_SERIALIZABLE(WAVE_CORE_REQ_SET_EHT_OPERATION,        wave_core_set_eht_operation);
    _MTLK_CORE_HANDLE_REQ_SERIALIZABLE(WAVE_CORE_REQ_GET_EHT_OPERATION,        wave_core_get_eht_operation);
    _MTLK_CORE_HANDLE_REQ_SERIALIZABLE(WAVE_CORE_REQ_SET_EHT_NON_ADVERTISED,   wave_core_set_eht_non_advertised);
    _MTLK_CORE_HANDLE_REQ_SERIALIZABLE(WAVE_CORE_REQ_GET_EHT_NON_ADVERTISED,   wave_core_get_eht_non_advertised);
    _MTLK_CORE_HANDLE_REQ_SERIALIZABLE(WAVE_RADIO_REQ_SET_LOGGER_FIFO_MUX_CFG, wave_core_set_logger_fifo_mux_cfg);
    _MTLK_CORE_HANDLE_REQ_SERIALIZABLE(WAVE_RADIO_REQ_GET_LOGGER_FIFO_MUX_CFG, wave_core_get_logger_fifo_mux_cfg);
    _MTLK_CORE_HANDLE_REQ_SERIALIZABLE(WAVE_CORE_REQ_SETUP_MLD,                wave_core_setup_ap_mld);
    _MTLK_CORE_HANDLE_REQ_SERIALIZABLE(WAVE_CORE_REQ_SET_MLD_INFO,             wave_core_set_ap_mld_info);
    _MTLK_CORE_HANDLE_REQ_SERIALIZABLE(WAVE_CORE_REQ_ML_SID,                   wave_core_req_ml_sid);
    _MTLK_CORE_HANDLE_REQ_SERIALIZABLE(WAVE_CORE_REQ_SET_ML_SID,               wave_core_set_ml_sid);
    _MTLK_CORE_HANDLE_REQ_SERIALIZABLE(WAVE_CORE_REQ_ML_STA_ADD,               wave_core_ml_sta_add);
    _MTLK_CORE_HANDLE_REQ_SERIALIZABLE(WAVE_CORE_REQ_REMOVE_MLD,               wave_core_remove_mld);
    _MTLK_CORE_HANDLE_REQ_SERIALIZABLE(WAVE_CORE_REQ_REMOVE_STA_MLD,           wave_core_remove_sta_mld);
    _MTLK_CORE_HANDLE_REQ_SERIALIZABLE(WAVE_CORE_REQ_SET_ML_CRITICAL_UPDATE,   wave_core_set_ml_critical_update);
    _MTLK_CORE_HANDLE_REQ_SERIALIZABLE(WAVE_CORE_REQ_SCS_ADD,                   wave_core_scs_add_req);
    _MTLK_CORE_HANDLE_REQ_SERIALIZABLE(WAVE_CORE_REQ_SCS_REM,                   wave_core_scs_rem_req);
    _MTLK_CORE_HANDLE_REQ_SERIALIZABLE(WAVE_CORE_REQ_ML_TX_T2LM_TEARDOWN,       wave_core_ml_send_t2lm_teardown);
    _MTLK_CORE_HANDLE_REQ_SERIALIZABLE(WAVE_CORE_REQ_GET_ML_STA_LINK_STATS,    wave_core_get_ml_link_stats);
    _MTLK_CORE_HANDLE_REQ_SERIALIZABLE(WAVE_CORE_REQ_SET_ML_STA_LINK_STATS,    wave_core_set_ml_link_stats);
    _MTLK_CORE_HANDLE_REQ_SERIALIZABLE(WAVE_CORE_REQ_GET_ML_VAP_LIST,          wave_core_get_ml_vap_list);
#ifdef BEST_EFFORT_TID_SPREADING
    _MTLK_CORE_HANDLE_REQ_SERIALIZABLE(WAVE_CORE_REQ_SET_STR_TID_LINK_SPREADING, wave_core_set_str_tid_link_spreading_cfg);
    _MTLK_CORE_HANDLE_REQ_SERIALIZABLE(WAVE_CORE_REQ_CLEANUP_SKB_HASH,           wave_stadb_cleanup_skb_hash);
    _MTLK_CORE_HANDLE_REQ_SERIALIZABLE(WAVE_CORE_REQ_CALCULATE_EFFECTIVE_RATES_STR, wave_calculate_str_sta_effective_rates);
#endif
    _MTLK_CORE_HANDLE_REQ_SERIALIZABLE(WAVE_CORE_REQ_ML_STA_REASSOC_NOTIFY,     wave_core_ml_sta_reassoc_notify);
    _MTLK_CORE_HANDLE_REQ_SERIALIZABLE(WAVE_CORE_REQ_GET_ML_PEER_FLOW_STATUS,   wave_core_get_ml_peer_stats);
    _MTLK_CORE_HANDLE_REQ_SERIALIZABLE(WAVE_CORE_REQ_GET_ML_STA_LIST,           wave_core_get_ml_sta_list);
#endif
    _MTLK_CORE_HANDLE_REQ_SERIALIZABLE(WAVE_RADIO_REQ_SET_FIXED_RATE,           _mtlk_core_set_fixed_rate);
    _MTLK_CORE_HANDLE_REQ_SERIALIZABLE(WAVE_CORE_REQ_SET_ALLOW_3ADDR_MCAST,     wave_core_set_allow_3addr_mcast);
    _MTLK_CORE_HANDLE_REQ_SERIALIZABLE(WAVE_CORE_REQ_GET_ALLOW_3ADDR_MCAST,     wave_core_get_allow_3addr_mcast);
    _MTLK_CORE_HANDLE_REQ_SERIALIZABLE(WAVE_CORE_REQ_GET_LA_SU_MU_RU_OFDMA_STATS, wave_core_get_la_su_mu_ru_ofdma_stats);
    _MTLK_CORE_HANDLE_REQ_SERIALIZABLE(WAVE_CORE_REQ_CHANGE_ROLE,               wave_core_change_role);
    _MTLK_CORE_HANDLE_REQ_SERIALIZABLE(WAVE_RADIO_REQ_GET_PROP_PHY_CAP,         wave_core_get_prop_phy_cap);
    _MTLK_CORE_HANDLE_REQ_SERIALIZABLE(WAVE_RADIO_REQ_GET_RADIO_PEER_LIST,      wave_core_get_radio_sta_list);
    _MTLK_CORE_HANDLE_REQ_SERIALIZABLE(WAVE_CORE_REQ_GET_LA_MIMO_OFDMA_STATS,   wave_core_get_link_adapt_mimo_statistics);
    _MTLK_CORE_HANDLE_REQ_SERIALIZABLE(WAVE_CORE_REQ_GET_LA_MU_HE_EHT_STATS,    wave_core_get_la_mu_he_eht_stats);

/* DEBUG COMMANDS */
#ifdef CONFIG_WAVE_DEBUG
    _MTLK_CORE_HANDLE_REQ_SERIALIZABLE(WAVE_CORE_REQ_SET_FIXED_RATE_THERMAL,    wave_core_set_fixed_rate_thermal);
    _MTLK_CORE_HANDLE_REQ_SERIALIZABLE(WAVE_CORE_REQ_GET_FIXED_RATE_THERMAL,    wave_core_get_fixed_rate_thermal);
    _MTLK_CORE_HANDLE_REQ_SERIALIZABLE(MTLK_HW_REQ_GET_COUNTERS_SRC,            mtlk_core_cfg_get_counters_src);
    _MTLK_CORE_HANDLE_REQ_SERIALIZABLE(MTLK_HW_REQ_SET_COUNTERS_SRC,            mtlk_core_cfg_set_counters_src);

#ifdef CPTCFG_IWLWAV_SET_PM_QOS
    _MTLK_CORE_HANDLE_REQ_SYNCHRONOUS (WAVE_RADIO_REQ_GET_CPU_DMA_LATENCY,      _mtlk_core_get_cpu_dma_latency);
    _MTLK_CORE_HANDLE_REQ_SYNCHRONOUS (WAVE_RADIO_REQ_SET_CPU_DMA_LATENCY,      _mtlk_core_set_cpu_dma_latency);
#endif

    _MTLK_CORE_HANDLE_REQ_SERIALIZABLE(WAVE_HW_REQ_GET_BF_EXPLICIT_CAP,         _mtlk_core_get_bf_explicit_cap);
    _MTLK_CORE_HANDLE_REQ_SERIALIZABLE(WAVE_HW_REQ_GET_TASKLET_LIMITS,          _mtlk_core_get_tasklet_limits);
    _MTLK_CORE_HANDLE_REQ_SERIALIZABLE(WAVE_HW_REQ_SET_TASKLET_LIMITS,          _mtlk_core_set_tasklet_limits);
    /* Traffic Analyzer */
    _MTLK_CORE_HANDLE_REQ_SERIALIZABLE(WAVE_RADIO_REQ_SET_TA_CFG,               _mtlk_core_set_ta_cfg);
    _MTLK_CORE_HANDLE_REQ_SERIALIZABLE(WAVE_RADIO_REQ_GET_TA_CFG,               _mtlk_core_get_ta_cfg);

#ifdef CPTCFG_IWLWAV_PMCU_SUPPORT
    _MTLK_CORE_HANDLE_REQ_SERIALIZABLE(WAVE_RADIO_REQ_GET_PCOC_CFG,             _mtlk_core_get_pcoc_cfg);
    _MTLK_CORE_HANDLE_REQ_SERIALIZABLE(WAVE_RADIO_REQ_SET_PCOC_CFG,             _mtlk_core_set_pcoc_cfg);
#endif /*CPTCFG_IWLWAV_PMCU_SUPPORT*/

    _MTLK_CORE_HANDLE_REQ_SERIALIZABLE(WAVE_CORE_REQ_GET_HSTDB_CFG,             _mtlk_core_get_hstdb_cfg);
    _MTLK_CORE_HANDLE_REQ_SERIALIZABLE(WAVE_CORE_REQ_SET_HSTDB_CFG,             _mtlk_core_set_hstdb_cfg);
    _MTLK_CORE_HANDLE_REQ_SERIALIZABLE(WAVE_RADIO_REQ_GET_MAC_WATCHDOG_CFG,     _mtlk_core_get_mac_wdog_cfg);
    _MTLK_CORE_HANDLE_REQ_SERIALIZABLE(WAVE_RADIO_REQ_SET_MAC_WATCHDOG_CFG,     _mtlk_core_set_mac_wdog_cfg);
    _MTLK_CORE_HANDLE_REQ_SERIALIZABLE(WAVE_HW_REQ_SET_TEST_BUS,                wave_core_set_test_bus_mode);
    _MTLK_CORE_HANDLE_REQ_SERIALIZABLE(WAVE_RADIO_REQ_SET_DBG_CLI,              mtlk_core_simple_cli);
    _MTLK_CORE_HANDLE_REQ_SERIALIZABLE(WAVE_RADIO_REQ_SET_FW_DEBUG,             _mtlk_core_fw_debug);
    _MTLK_CORE_HANDLE_REQ_SERIALIZABLE(WAVE_RADIO_REQ_SET_FW_LOG_SEVERITY,      _mtlk_core_set_fw_log_severity);
    _MTLK_CORE_HANDLE_REQ_SERIALIZABLE(WAVE_RADIO_REQ_SET_MTLK_DEBUG,           mtlk_core_set_mtlk_log_level);
    _MTLK_CORE_HANDLE_REQ_SERIALIZABLE(WAVE_CORE_REQ_GET_MC_IGMP_TBL,           _mtlk_core_get_mc_igmp_tbl);
    _MTLK_CORE_HANDLE_REQ_SERIALIZABLE(WAVE_CORE_REQ_GET_MC_HW_TBL,             _mtlk_core_get_mc_hw_tbl);
    _MTLK_CORE_HANDLE_REQ_SERIALIZABLE(WAVE_CORE_REQ_GET_BLACKLIST_ENTRIES,     _mtlk_core_get_blacklist_entries);
    _MTLK_CORE_HANDLE_REQ_SERIALIZABLE(WAVE_CORE_REQ_GET_MULTI_AP_BL_ENTRIES,   mtlk_core_cfg_get_multi_ap_blacklist_entries);
    _MTLK_CORE_HANDLE_REQ_SERIALIZABLE(WAVE_CORE_REQ_GET_WDS_WPA_LIST_ENTRIES,  mtlk_core_cfg_get_wds_wpa_entry);
    _MTLK_CORE_HANDLE_REQ_SERIALIZABLE(WAVE_CORE_REQ_GET_QOS_MAP_INFO,          _mtlk_core_get_qos_map_info);
    _MTLK_CORE_HANDLE_REQ_SYNCHRONOUS(WAVE_CORE_REQ_GET_SERIALIZER_INFO,        _mtlk_core_get_serializer_info);
    _MTLK_CORE_HANDLE_REQ_SERIALIZABLE(WAVE_RADIO_REQ_SET_DEBUG_CMD_FW,         wave_core_cfg_set_debug_cmd);
    _MTLK_CORE_HANDLE_REQ_DUMPABLE(WAVE_RADIO_REQ_GET_BCL_MAC_DATA,             mtlk_core_bcl_mac_data_get);
    _MTLK_CORE_HANDLE_REQ_SERIALIZABLE(WAVE_RADIO_REQ_SET_BCL_MAC_DATA,         mtlk_core_bcl_mac_data_set);
    _MTLK_CORE_HANDLE_REQ_SERIALIZABLE(WAVE_CORE_REQ_RESET_STATS,               mtlk_core_reset_stats);
    _MTLK_CORE_HANDLE_REQ_SERIALIZABLE(WAVE_CORE_REQ_GET_PEER_HOST_IF_QOS,      wave_core_get_peer_host_if_qos_statistics);
    _MTLK_CORE_HANDLE_REQ_SERIALIZABLE(WAVE_CORE_REQ_GET_PEER_HOST_IF,          wave_core_get_peer_host_if_statistics);
    _MTLK_CORE_HANDLE_REQ_SERIALIZABLE(WAVE_CORE_REQ_GET_PEER_RX_STATS,         wave_core_get_peer_rx_statistics);
    _MTLK_CORE_HANDLE_REQ_SERIALIZABLE(WAVE_CORE_REQ_GET_PEER_UL_BSRC_TID,      wave_core_get_peer_ul_bsrc_tid_statistics);
    _MTLK_CORE_HANDLE_REQ_SERIALIZABLE(WAVE_CORE_REQ_GET_PEER_BAA_STATS,        wave_core_get_peer_baa_statistics);
    _MTLK_CORE_HANDLE_REQ_SERIALIZABLE(WAVE_CORE_REQ_GET_LINK_ADAPTION_STATS,   wave_core_get_link_adaption_statistics);
    _MTLK_CORE_HANDLE_REQ_SERIALIZABLE(WAVE_CORE_REQ_GET_PLAN_MANAGER_STATS,    wave_core_get_plan_manager_statistics);
    _MTLK_CORE_HANDLE_REQ_SERIALIZABLE(WAVE_CORE_REQ_GET_TWT_STATS,             wave_core_get_peer_twt_statistics);
    _MTLK_CORE_HANDLE_REQ_SERIALIZABLE(WAVE_CORE_REQ_GET_PER_CLIENT_STATS,      wave_core_get_per_client_statistics);
    _MTLK_CORE_HANDLE_REQ_SERIALIZABLE(WAVE_CORE_REQ_GET_PEER_PHY_RX_STATUS,    wave_core_get_peer_phy_rx_status);
    _MTLK_CORE_HANDLE_REQ_SERIALIZABLE(WAVE_CORE_REQ_GET_PEER_INFO,             wave_core_get_peer_info_statistics);
    _MTLK_CORE_HANDLE_REQ_SERIALIZABLE(WAVE_CORE_REQ_GET_WLAN_HOST_IF_QOS,      wave_core_get_wlan_host_if_qos_statistics);
    _MTLK_CORE_HANDLE_REQ_SERIALIZABLE(WAVE_CORE_REQ_GET_WLAN_HOST_IF,          wave_core_get_wlan_host_if_statistics);
    _MTLK_CORE_HANDLE_REQ_SERIALIZABLE(WAVE_CORE_REQ_GET_WLAN_RX_STATS,         wave_core_get_wlan_rx_statistics);
    _MTLK_CORE_HANDLE_REQ_SERIALIZABLE(WAVE_CORE_REQ_GET_WLAN_BAA_STATS,        wave_core_get_wlan_baa_statistics);
    _MTLK_CORE_HANDLE_REQ_SERIALIZABLE(WAVE_CORE_REQ_GET_RADIO_RX_STATS,        wave_core_get_radio_rx_statistics);
    _MTLK_CORE_HANDLE_REQ_SERIALIZABLE(WAVE_CORE_REQ_GET_RADIO_BAA_STATS,       wave_core_get_radio_baa_statistics);
    _MTLK_CORE_HANDLE_REQ_SERIALIZABLE(WAVE_CORE_REQ_GET_TSMAN_INIT_TID_GL,     wave_core_get_tsman_init_tid_gl_statistics);
    _MTLK_CORE_HANDLE_REQ_SERIALIZABLE(WAVE_CORE_REQ_GET_TSMAN_INIT_STA_GL,     wave_core_get_tsman_init_sta_gl_statistics);
    _MTLK_CORE_HANDLE_REQ_SERIALIZABLE(WAVE_CORE_REQ_GET_TSMAN_RCPT_TID_GL,     wave_core_get_tsman_rcpt_tid_gl_statistics);
    _MTLK_CORE_HANDLE_REQ_SERIALIZABLE(WAVE_CORE_REQ_GET_TSMAN_RCPT_STA_GL,     wave_core_get_tsman_rcpt_sta_gl_statistics);
    _MTLK_CORE_HANDLE_REQ_SERIALIZABLE(WAVE_CORE_REQ_GET_RADIO_LINK_ADAPT_STATS,wave_core_get_radio_link_adapt_statistics);
    _MTLK_CORE_HANDLE_REQ_SERIALIZABLE(WAVE_CORE_REQ_GET_MULTICAST_STATS,       wave_core_get_multicast_statistics);
    _MTLK_CORE_HANDLE_REQ_SERIALIZABLE(WAVE_CORE_REQ_GET_TR_MAN_STATS,          wave_core_get_training_man_statistics);
    _MTLK_CORE_HANDLE_REQ_SERIALIZABLE(WAVE_CORE_REQ_GET_GRP_MAN_STATS,         wave_core_get_grp_man_statistics);
    _MTLK_CORE_HANDLE_REQ_SERIALIZABLE(WAVE_CORE_REQ_GET_GENERAL_STATS,         wave_core_get_general_statistics);
    _MTLK_CORE_HANDLE_REQ_SERIALIZABLE(WAVE_CORE_REQ_GET_CUR_CHANNEL_STATS,     wave_core_get_cur_channel_statistics);
    _MTLK_CORE_HANDLE_REQ_SERIALIZABLE(WAVE_CORE_REQ_GET_RADIO_PHY_RX_STATS,    wave_core_get_radio_phy_rx_statistics);
    _MTLK_CORE_HANDLE_REQ_SERIALIZABLE(WAVE_CORE_REQ_GET_DYNAMIC_BW_STATS,      wave_core_get_dynamic_bw_statistics);
    _MTLK_CORE_HANDLE_REQ_SERIALIZABLE(WAVE_CORE_REQ_GET_LA_MU_VHT_STATS,       wave_core_get_la_mu_vht_statistics);
    _MTLK_CORE_HANDLE_REQ_SERIALIZABLE(WAVE_RADIO_REQ_GET_MU_GROUP_PLAN,        wave_core_get_mu_group_plan);
    _MTLK_CORE_HANDLE_REQ_SERIALIZABLE(WAVE_RADIO_REQ_GET_CSI_CAPABILITY,       wave_core_get_csi_capability);

#endif /* CONFIG_WAVE_DEBUG */

  _WAVE_CORE_REQ_MAP_END(id)

#undef _WAVE_CORE_REQ_MAP_START
#undef _MTLK_CORE_HANDLE_REQ_SERIALIZABLE
#undef _WAVE_CORE_REQ_MAP_END
}

static int
_mtlk_core_get_prop (mtlk_vap_handle_t vap_handle, mtlk_core_prop_e prop_id, void* buffer, uint32 size)
{
  int res = MTLK_ERR_NOT_SUPPORTED;
  switch (prop_id) {
  case MTLK_CORE_PROP_MAC_SW_RESET_ENABLED:
    if (buffer && size == sizeof(uint32)) {
      uint32 *mac_sw_reset_enabled = (uint32 *)buffer;
      *mac_sw_reset_enabled = WAVE_RADIO_PDB_GET_INT(wave_vap_radio_get(vap_handle), PARAM_DB_RADIO_MAC_SOFT_RESET_ENABLE);
      res = MTLK_ERR_OK;
    }
    break;
  case MTLK_CORE_PROP_IS_DUT:
    if (buffer && size == sizeof(BOOL)) {
      BOOL *val = (BOOL *)buffer;
      *val = mtlk_is_dut_core_active(mtlk_vap_get_core(vap_handle));
      res = MTLK_ERR_OK;
    }
    break;
  case MTLK_CORE_PROP_IS_MAC_FATAL_PENDING:
    if (buffer && size == sizeof(BOOL)) {
      BOOL *val = (BOOL *)buffer;
      mtlk_hw_t *hw = mtlk_vap_get_hw(vap_handle);
      *val = (wave_rcvry_mac_fatal_pending_get(hw) | wave_rcvry_fw_dump_in_progress_get(hw));
      res = MTLK_ERR_OK;
    }
    break;
  default:
    break;
  }
  return res;
}

static int
_mtlk_core_set_prop (mtlk_vap_handle_t vap_handle,
                    mtlk_core_prop_e  prop_id,
                    void             *buffer,
                    uint32            size)
{
  int res = MTLK_ERR_NOT_SUPPORTED;
  mtlk_core_t *nic = mtlk_vap_get_core (vap_handle);
  switch (prop_id)
  {
  case MTLK_CORE_PROP_MAC_STUCK_DETECTED:
    if (buffer && size == sizeof(uint32)) {
      uint32 *cpu_no = (uint32 *)buffer;
      nic->slow_ctx->mac_stuck_detected_by_sw = 1;
      mtlk_set_hw_state(nic, MTLK_HW_STATE_APPFATAL);
      (void)mtlk_hw_set_prop(mtlk_vap_get_hwapi(nic->vap_handle), MTLK_HW_RESET, NULL, 0);
      mtlk_df_ui_notify_notify_fw_hang(mtlk_vap_get_df(nic->vap_handle), *cpu_no, MTLK_HW_STATE_APPFATAL);
    }
    break;
  default:
    break;
  }

  return res;
}

void __MTLK_IFUNC
mtlk_core_api_cleanup (mtlk_core_api_t *core_api)
{
  mtlk_core_t* core = HANDLE_T_PTR(mtlk_core_t, core_api->core_handle);
  _mtlk_core_cleanup(core);
  mtlk_osal_mem_free(core);
}

void __MTLK_IFUNC
mtlk_core_get_tx_power_data (mtlk_core_t *core, mtlk_tx_power_data_t *tx_power_data)
{
  wave_radio_t *radio;
  int i;
  uint8 bf;
  uint16 tx_power_offs; /* user set tx power offset in to reduce total tx power */
  mtlk_pdb_size_t pw_limits_size = sizeof(psdb_pw_limits_t);
  unsigned radio_idx;

  MTLK_ASSERT(core);
  MTLK_ASSERT(tx_power_data);

  radio = wave_vap_radio_get(core->vap_handle);
  MTLK_ASSERT(NULL != radio);

  radio_idx = wave_radio_id_get(radio);

  if (MTLK_ERR_OK != wave_core_get_bf_mode(core, &bf)) {
    ELOG_V("Failed to get bf mode");
  }

  tx_power_offs = WAVE_RADIO_PDB_GET_INT(radio, PARAM_DB_RADIO_TX_POWER_LIMIT_OFFSET); /* power units */

  mtlk_hw_mhi_get_tx_power(mtlk_vap_get_hw(core->vap_handle), &tx_power_data->power_hw, radio_idx);

  /* All TX power values are in power units */
  tx_power_data->power_usr_offs = tx_power_offs;
  tx_power_data->power_reg = (uint16)WAVE_RADIO_PDB_GET_INT(radio, PARAM_DB_RADIO_TX_POWER_REG_LIM); /* power units */
  if (bf == BF_STATE_EXPLICIT || bf == BF_STATE_IMPLICIT || bf == BF_STATE_AUTO_MODE) {
    tx_power_data->power_psd = (uint16)WAVE_RADIO_PDB_GET_INT(radio, PARAM_DB_RADIO_BF_TX_POWER_PSD); /* power units */
    tx_power_data->power_cfg = (uint16)WAVE_RADIO_PDB_GET_INT(radio, PARAM_DB_RADIO_BF_TX_POWER_CFG) - tx_power_offs; /* power units */
  } else {
    tx_power_data->power_psd = (uint16)WAVE_RADIO_PDB_GET_INT(radio, PARAM_DB_RADIO_TX_POWER_PSD); /* power units */
    tx_power_data->power_cfg = (uint16)WAVE_RADIO_PDB_GET_INT(radio, PARAM_DB_RADIO_TX_POWER_CFG) - tx_power_offs; /* power units */
  }
  pw_limits_size = sizeof(psdb_pw_limits_t);
  if (MTLK_ERR_OK !=  WAVE_RADIO_PDB_GET_BINARY(radio, PARAM_DB_RADIO_TPC_PW_LIMITS_PSD, &(tx_power_data->power_tpc_psd), &pw_limits_size)) {
    ELOG_V("Failed to get TPC Power limits PSD array");
  }

  pw_limits_size = sizeof(psdb_pw_limits_t);
  if (MTLK_ERR_OK !=  WAVE_RADIO_PDB_GET_BINARY(radio, PARAM_DB_RADIO_TPC_PW_LIMITS_CFG, &(tx_power_data->power_tpc_cfg), &pw_limits_size)) {
    ELOG_V("Failed to get TPC Power limits Configured array");
  }

  for (i = PSDB_PHY_CW_11B; i <= PSDB_PHY_CW_OFDM_320; i++) {
    tx_power_data->power_tpc_cfg.pw_limits[i] -= tx_power_offs; /* substruct power backoffs for 11b till bw320 */
  }

  tx_power_data->open_loop = (TPC_OPEN_LOOP == WAVE_RADIO_PDB_GET_INT(radio, PARAM_DB_RADIO_TPC_LOOP_TYPE));

  core_cfg_country_code_get(core, &tx_power_data->cur_country_code);
  tx_power_data->cur_band = core_cfg_get_freq_band_cfg(core);
  tx_power_data->cur_chan = _mtlk_core_get_channel(core);

  tx_power_data->cur_cbw = _mtlk_core_get_spectrum_mode(core);
  tx_power_data->max_cbw = (MTLK_HW_BAND_2_4_GHZ == tx_power_data->cur_band) ? CW_MAX_2G : CW_MAX_5G_GEN6;
#ifdef MTLK_WAVE_700
  tx_power_data->max_cbw = CW_MAX_6G_GEN7;
#endif
  tx_power_data->max_antennas = core->slow_ctx->tx_limits.num_tx_antennas;
  tx_power_data->cur_antennas = _mtlk_core_get_current_tx_antennas(core);

  tx_power_data->max_ant_gain = mtlk_antennas_factor(tx_power_data->max_antennas);
  tx_power_data->cur_ant_gain = mtlk_antennas_factor(tx_power_data->cur_antennas);

  for (i = 0; i < PHY_STAT_RATE_CBW_NUM; i++) {
    tx_power_data->pw_min_brd[i] = tx_power_data->cur_ant_gain + tx_power_data->power_hw.pw_min_ant[i];
    tx_power_data->pw_max_brd[i] = tx_power_data->cur_ant_gain + tx_power_data->power_hw.pw_max_ant[i];
    tx_power_data->pw_targets[i] = hw_mmb_get_tx_power_target(tx_power_data->power_cfg, (uint16)(tx_power_data->cur_ant_gain + tx_power_data->power_hw.pw_max_ant[i]));
    ILOG3_DD("pw_min_ant[%d]=%d", i, tx_power_data->power_hw.pw_min_ant[i]);
    ILOG3_DD("pw_max_ant[%d]=%d", i, tx_power_data->power_hw.pw_max_ant[i]);
  }
}

static int
_mtlk_core_get_tx_rate_power (mtlk_handle_t hcore, const void *data, uint32 data_size)
{
  mtlk_core_t *core = HANDLE_T_PTR(mtlk_core_t, hcore);
  mtlk_clpb_t *clpb = *(mtlk_clpb_t **) data;
  mtlk_tx_power_data_t  tx_power_data;
  int res;

  MTLK_ASSERT(sizeof(mtlk_clpb_t*) == data_size);

  /* 1. Tx power */
  mtlk_core_get_tx_power_data(core, &tx_power_data);
  if (MTLK_ERR_OK != (res = mtlk_clpb_push(clpb, &tx_power_data, sizeof(tx_power_data)))) {
    goto err_push;
  }

  /* 2. PSD damage power limit */
  if ((tx_power_data.cur_band >= MTLK_HW_BAND_MAX) || (MTLK_ERR_OK != (res = mtlk_psdb_get_damage_power_limit(core, clpb, tx_power_data.cur_band, tx_power_data.max_ant_gain)))) {
    goto err_push;
  }

  /* 3. Antenna Gain */
  if ((MTLK_ERR_OK != (res = mtlk_psdb_get_ant_gain(core, clpb, tx_power_data.cur_chan, tx_power_data.cur_band)))) {
    goto err_push;
  }

  /* 4. PSDB rate power list */
  return mtlk_psdb_get_rate_power_list(core, clpb, tx_power_data.cur_band);

err_push:
    mtlk_clpb_purge(clpb);
    return res;
}

static int
_mtlk_core_get_stadb_sta_list (mtlk_handle_t hcore, const void* data, uint32 data_size)
{
  mtlk_core_t *nic = HANDLE_T_PTR(mtlk_core_t, hcore);
  mtlk_clpb_t *clpb = *(mtlk_clpb_t **) data;
  mtlk_core_ui_get_stadb_status_req_t *get_stadb_status_req;
  uint32 size;
  hst_db *hstdb = NULL;
  uint8 group_cipher = FALSE;
#ifdef BEST_EFFORT_TID_SPREADING
  uint8 get_str_sta_cfg;
#endif
  MTLK_ASSERT(sizeof(mtlk_clpb_t*) == data_size);

  if ( 0 == (mtlk_core_get_net_state(nic) & (NET_STATE_HALTED | NET_STATE_CONNECTED)) ) {
    mtlk_clpb_purge(clpb);
    return MTLK_ERR_OK;
  }

  get_stadb_status_req = mtlk_clpb_enum_get_next(clpb, &size);
  if ( (NULL == get_stadb_status_req) || (sizeof(*get_stadb_status_req) != size) ) {
    ELOG_SD("Failed to get data from clipboard in function %s, line %d", __FUNCTION__, __LINE__);
    return MTLK_ERR_UNKNOWN;
  }

  if (get_stadb_status_req->get_hostdb) {
    hstdb = &nic->slow_ctx->hstdb;
  }

  if (get_stadb_status_req->use_cipher) {
    group_cipher = nic->slow_ctx->group_cipher;
  }

#ifdef BEST_EFFORT_TID_SPREADING
  get_str_sta_cfg = get_stadb_status_req->get_str_sta_tid_spread_cfg;
#endif

  mtlk_clpb_purge(clpb);

#ifdef BEST_EFFORT_TID_SPREADING
  if (get_str_sta_cfg) {
    return wave_get_ml_str_sta_tid_spread_stat(&nic->slow_ctx->stadb, clpb);
  }
#endif

  return mtlk_stadb_get_stat(&nic->slow_ctx->stadb, hstdb, clpb, group_cipher);
}

uint8 __MTLK_IFUNC mtlk_core_is_device_busy(mtlk_handle_t context)
{
    return FALSE;
}

tx_limit_t* __MTLK_IFUNC
mtlk_core_get_tx_limits(mtlk_core_t *core)
{
  return &core->slow_ctx->tx_limits;
}

static void _mtlk_core_prepare_stop(mtlk_vap_handle_t vap_handle)
{
  mtlk_core_t *nic = mtlk_vap_get_core (vap_handle);

  if (!nic->is_stopped) {
    if (MTLK_ERR_OK != __mtlk_core_deactivate(nic, nic)) {
      ELOG_D("CID-%04x: Core deactivation is failed", mtlk_vap_get_oid(vap_handle));
    }
  }

  ILOG1_V("Core prepare stopping....");
  nic->is_stopping = TRUE;

  if (mtlk_vap_is_slave_ap(vap_handle)) {
    return;
  }
}

BOOL __MTLK_IFUNC
mtlk_core_is_stopping(mtlk_core_t *core)
{
  return (core->is_stopping || core->is_iface_stopping);
}

static int
_mtlk_general_core_range_info_get (mtlk_core_t* nic, const void* data, uint32 data_size)
{
  int res = MTLK_ERR_OK;
  mtlk_core_ui_range_info_t range_info;
  mtlk_clpb_t *clpb = *(mtlk_clpb_t **) data;
  wave_radio_t *radio = wave_vap_radio_get(nic->vap_handle);

  MTLK_ASSERT(sizeof(mtlk_clpb_t*) == data_size);
  MTLK_ASSERT(!mtlk_vap_is_slave_ap(nic->vap_handle));

  /* Get supported bitrates */
  {
    int avail = _mtlk_core_get_available_bitrates(nic);
    int32 short_cyclic_prefix = WAVE_RADIO_PDB_GET_INT(radio, PARAM_DB_RADIO_SHORT_CYCLIC_PREFIX);
    int num_bitrates; /* Index in table returned to userspace */
    int value; /* Bitrate's value */
    int i; /* Bitrate index */
    int k, l; /* Counters, used for sorting */
    int sm = WAVE_RADIO_PDB_GET_INT(radio, PARAM_DB_RADIO_SPECTRUM_MODE);
    BOOL is_eht = FALSE;

#ifdef MTLK_WAVE_700
    is_eht = wave_radio_is_gen7(radio);
#endif
    /* Array of bitrates is sorted and consist of only unique elements */
    num_bitrates = 0;
    for (i = BITRATE_FIRST; i <= BITRATE_LAST; i++) {
      if ((1 << i) & avail) {
        value = mtlk_bitrate_get_value(i, sm, short_cyclic_prefix, is_eht);
        if (MTLK_BITRATE_INVALID == value) {
            ILOG1_DDD("Rate is not supported: index %d, spectrum mode %d, scp %d", i, sm, short_cyclic_prefix);
            continue;   /* is not supported  (e.g in AC mode) */
        }

        range_info.bitrates[num_bitrates] = value;
        k = num_bitrates;
        while (k && (range_info.bitrates[k-1] >= value)) k--; /* Position found */
        if ((k == num_bitrates) || (range_info.bitrates[k] != value)) {
          for (l = num_bitrates; l > k; l--)
            range_info.bitrates[l] = range_info.bitrates[l-1];
          range_info.bitrates[k] = value;
          num_bitrates++;
        }
      }
    }

    range_info.num_bitrates = num_bitrates;
  }

  res = mtlk_clpb_push(clpb, &range_info, sizeof(range_info));
  if (MTLK_ERR_OK != res) {
    mtlk_clpb_purge(clpb);
  }

  return res;
}

static int
_mtlk_slave_core_range_info_get (mtlk_core_t* nic, const void* data, uint32 data_size)
{
  return (_mtlk_general_core_range_info_get (mtlk_core_get_master (nic->vap_handle), data, data_size));
}

static int
_mtlk_core_range_info_get (mtlk_handle_t hcore, const void* data, uint32 data_size)
{
  mtlk_core_t *core = HANDLE_T_PTR(mtlk_core_t, hcore);
  if (!mtlk_vap_is_slave_ap (core->vap_handle)) {
    return _mtlk_general_core_range_info_get (core, data, data_size);
  }
  else
    return _mtlk_slave_core_range_info_get (core, data, data_size);
}

void __MTLK_IFUNC
mtlk_core_set_umi_key_au8TxSeqNum (UMI_SET_KEY *umi_key, mtlk_core_t *core)
{
  /* set TX sequence number */
  umi_key->au8TxSeqNum[0] = 1;
#ifdef CONFIG_WAVE_DEBUG
#define DISABLE_PN_RESET 0xFF
  /* FW expects the TxSeqNum to be set to a pre-defined signature to avoid PN reset */
  if ((wave_radio_band_get(wave_vap_radio_get(core->vap_handle)) == MTLK_HW_BAND_6_GHZ) &&
    (!wave_core_get_dbg_pn_reset(core))) {
    memset(umi_key->au8TxSeqNum, DISABLE_PN_RESET, sizeof(umi_key->au8TxSeqNum));
  }
#endif
}

/* Aggregation configuration */
static int _mtlk_core_get_aggr_cfg (mtlk_handle_t hcore, const void* data, uint32 data_size)
{
  int                    res = MTLK_ERR_OK;
  mtlk_aggr_cfg_t        aggr_cfg;
  mtlk_core_t            *core = HANDLE_T_PTR(mtlk_core_t, hcore);
  mtlk_clpb_t            *clpb = *(mtlk_clpb_t **)data;

  MTLK_ASSERT(sizeof(mtlk_clpb_t*) == data_size);

  /* read config from internal db */
  memset(&aggr_cfg, 0, sizeof(aggr_cfg));

  MTLK_CFG_SET_ITEM_BY_FUNC(&aggr_cfg, cfg, mtlk_core_receive_agg_rate_cfg,
                            (core, &aggr_cfg.cfg), res)

  /* push result and config to clipboard*/
  res = mtlk_clpb_push(clpb, &res, sizeof(res));
  if (MTLK_ERR_OK == res) {
    res = mtlk_clpb_push(clpb, &aggr_cfg, sizeof(aggr_cfg));
  }

  return res;
}

static void _mtlk_core_store_aggr_config (mtlk_core_t *core, uint32 amsdu_mode, uint32 ba_mode, uint32 windowSize)
{
  MTLK_CORE_PDB_SET_INT(core, PARAM_DB_CORE_AMSDU_MODE, amsdu_mode);
  MTLK_CORE_PDB_SET_INT(core, PARAM_DB_CORE_BA_MODE, ba_mode);
  MTLK_CORE_PDB_SET_INT(core, PARAM_DB_CORE_WINDOW_SIZE, windowSize);
}

static int _mtlk_core_set_aggr_cfg (mtlk_handle_t hcore, const void* data, uint32 data_size)
{
  int                    res = MTLK_ERR_OK;
  mtlk_core_t            *core = HANDLE_T_PTR(mtlk_core_t, hcore);
  mtlk_aggr_cfg_t        *aggr_cfg = NULL;
  uint32                 aggr_cfg_size;
  mtlk_clpb_t            *clpb = *(mtlk_clpb_t **)data;

  MTLK_ASSERT(sizeof(mtlk_clpb_t*) == data_size);

  /* get configuration */
  aggr_cfg = mtlk_clpb_enum_get_next(clpb, &aggr_cfg_size);
  MTLK_CLPB_TRY(aggr_cfg, aggr_cfg_size)
    MTLK_CFG_START_CHEK_ITEM_AND_CALL()
      /* send new config to FW */
      MTLK_CFG_CHECK_ITEM_AND_CALL(aggr_cfg, cfg, mtlk_core_set_aggr_cfg_req,
                                   (core, aggr_cfg->cfg.amsdu_mode, aggr_cfg->cfg.ba_mode, aggr_cfg->cfg.windowSize), res);
      /* store new config in internal db*/
      MTLK_CFG_CHECK_ITEM_AND_CALL_VOID(aggr_cfg, cfg, _mtlk_core_store_aggr_config,
                                        (core, aggr_cfg->cfg.amsdu_mode, aggr_cfg->cfg.ba_mode, aggr_cfg->cfg.windowSize));
    MTLK_CFG_END_CHEK_ITEM_AND_CALL()
  MTLK_CLPB_FINALLY(res)
    /* push result into clipboard */
    return mtlk_clpb_push_res(clpb, res);
  MTLK_CLPB_END
}

/* Calculate summ of 3 counters, update summ of them, return delta.
 */
static __INLINE uint32
_update_summ_of_3_cntrs (uint64 *summ, uint32 cntr1, uint32 cntr2, uint32 cntr3)
{
    uint32 sum123, value;

    sum123 = cntr1 + cntr2 + cntr3; /* new */
    value = (uint32)*summ;          /* prev */
    value = sum123 - value;         /* delta = new - prev */
    *summ += (uint64)value;         /* update with delta */

    return value;
}

static int
_mtlk_core_update_vaps_mhi_stats (mtlk_core_t *nic, wave_radio_t *radio, mtlk_hw_t *hw)
{
  mtlk_vap_manager_t    *vap_mgr;
  mtlk_core_t           *cur_nic;
  mtlk_mhi_stats_vap_t  *mhi_vap_stat;
  mtlk_vap_handle_t      vap_handle;
  int                    vaps_count, vap_index;
  uint64                 total_traffic = 0;
  uint32                 delta, total_traffic_delta = 0;
  int                    res = MTLK_ERR_NOT_IN_USE;
  uint32                 *stats;

  stats = mtlk_osal_mem_alloc(sizeof(mhi_vap_stat->stats), MTLK_MEM_TAG_EXTENSION);
  if(NULL == stats) {
    ELOG_D("CID-%04x: Failed to allocate stats", mtlk_vap_get_oid(nic->vap_handle));
    return MTLK_ERR_NO_MEM;
  }

/* Update statistics for all VAPs and calculate total_traffic */
  vap_mgr = mtlk_vap_get_manager(nic->vap_handle);
  vaps_count = mtlk_vap_manager_get_max_vaps_count(vap_mgr);
  for (vap_index = vaps_count - 1; vap_index >= 0; vap_index--) {
    if (MTLK_ERR_OK == mtlk_vap_manager_get_vap_handle(vap_mgr, vap_index, &vap_handle))
    {
      res = MTLK_ERR_OK;
      cur_nic = mtlk_vap_get_core(vap_handle);

      mhi_vap_stat = &cur_nic->mhi_vap_stat;
      mtlk_hw_mhi_get_vap_stats(hw, mhi_vap_stat, mtlk_vap_get_id_fw(cur_nic->vap_handle)); /* Vap ID in FW */
      wave_update_multicast_group_stats(hw, cur_nic, mtlk_vap_get_id_fw(cur_nic->vap_handle));

      if (_mtlk_core_poll_stat_is_started(cur_nic)) {
        /* - Update all 32-bit statistics from FW;
           - 64-bit statistics is updated manually */

        wave_memcpy(stats, sizeof(mhi_vap_stat->stats), &mhi_vap_stat->stats, sizeof(mhi_vap_stat->stats));
        _mtlk_core_poll_stat_update(cur_nic, (uint32 *)stats, sizeof(mhi_vap_stat->stats));

        /* Take into account the traffic since last update */
        delta = _update_summ_of_3_cntrs(&cur_nic->pstats.tx_packets,
                                  mhi_vap_stat->stats.txInUnicastHd,
                                  mhi_vap_stat->stats.txInBroadcastHd,
                                  mhi_vap_stat->stats.txInMulticastHd);
        mhi_vap_stat->stats64.txFrames = cur_nic->pstats.tx_packets;

        mtlk_core_add64_cnt(cur_nic, MTLK_CORE_CNT_PACKETS_SENT_64, delta);

        delta = _update_summ_of_3_cntrs(&cur_nic->pstats.rx_packets,
                                  mhi_vap_stat->stats.rxOutUnicastHd,
                                  mhi_vap_stat->stats.rxOutBroadcastHd,
                                  mhi_vap_stat->stats.rxOutMulticastHd);
        mhi_vap_stat->stats64.rxFrames = cur_nic->pstats.rx_packets;

        mtlk_core_add64_cnt(cur_nic, MTLK_CORE_CNT_PACKETS_RECEIVED_64, delta);

        delta = _update_summ_of_3_cntrs(&cur_nic->pstats.tx_bytes,
                                  mhi_vap_stat->stats.txInUnicastNumOfBytes,
                                  mhi_vap_stat->stats.txInBroadcastNumOfBytes,
                                  mhi_vap_stat->stats.txInMulticastNumOfBytes);
        mhi_vap_stat->stats64.txBytes = cur_nic->pstats.tx_bytes;

        mtlk_core_add64_cnt(cur_nic, MTLK_CORE_CNT_BYTES_SENT_64, delta);
        total_traffic_delta += delta;

        delta = _update_summ_of_3_cntrs(&cur_nic->pstats.rx_bytes,
                                  mhi_vap_stat->stats.rxOutUnicastNumOfBytes,
                                  mhi_vap_stat->stats.rxOutBroadcastNumOfBytes,
                                  mhi_vap_stat->stats.rxOutMulticastNumOfBytes);
        mhi_vap_stat->stats64.rxBytes = cur_nic->pstats.rx_bytes;

        mtlk_core_add64_cnt(cur_nic, MTLK_CORE_CNT_BYTES_RECEIVED_64, delta);
        total_traffic_delta += delta;

        /* Received multicast packets */
        _update_summ_of_3_cntrs(&cur_nic->pstats.rx_multicast_packets,
            0, 0, mhi_vap_stat->stats.rxOutMulticastHd);
      }

      total_traffic += cur_nic->pstats.tx_bytes;
      total_traffic += cur_nic->pstats.rx_bytes;

      wv_hostdb_cleanup(mtlk_core_get_hstdb(cur_nic));
    }
  }

  if( NULL != stats){
    mtlk_osal_mem_free(stats);
  }
#ifdef CPTCFG_IWLWAV_PMCU_SUPPORT
  wv_PMCU_Traffic_Report(hw, total_traffic);
#endif

  wave_radio_total_traffic_delta_set(radio, total_traffic_delta);

  return res;
}

/* PHY_RX_STATUS */
void hw_mac_update_peers_stats (mtlk_hw_t *hw, mtlk_core_t *core);

static int
_mtlk_core_mac_get_phy_status(mtlk_core_t *nic, mtlk_hw_t *hw, mtlk_core_general_stats_t *general_stats)
{
  MTLK_ASSERT(nic != NULL);
  MTLK_ASSERT(general_stats != NULL);

  if (NET_STATE_HALTED == mtlk_core_get_net_state(nic)) { /* Do nothing if halted */
    return MTLK_ERR_OK;
  }

  return hw_phy_rx_status_get(hw, nic);
}

static void
_wave_link_adapt_ofdma_band_ppdus_stats(mtlk_core_t *nic)
{
  hw_mac_update_ofdma_band_stats(mtlk_vap_get_hw(nic->vap_handle), nic);
}

static void
_mtlk_core_mac_update_peers_stats (mtlk_core_t *nic)
{
  hw_mac_update_peers_stats(mtlk_vap_get_hw(nic->vap_handle), nic);
}

/* Sync Log Timestamp with FW TSF */
static void
_mtlk_core_sync_log_timestamp (mtlk_vap_handle_t vap_handle)
{
#if defined (CPTCFG_IWLWAV_TSF_TIMER_ACCESS_ENABLED) && defined (CONFIG_WAVE_RTLOG_REMOTE)
    uint32  t_log, t_tsf;
    int32   t_ofs;

    mtlk_hw_get_log_fw_timestamps(vap_handle, &t_log, &t_tsf);

    t_ofs = t_tsf - t_log;          /* signed time shift */

    mtlk_log_tsf_sync_msg(mtlk_vap_get_hw_idx(vap_handle), t_log, t_ofs);

#endif /* CPTCFG_IWLWAV_TSF_TIMER_ACCESS_ENABLED && CONFIG_WAVE_RTLOG_REMOTE*/
}

static int
_mtlk_core_get_status (mtlk_handle_t hcore, const void* data, uint32 data_size)
{
  int                        res = MTLK_ERR_OK;
  mtlk_core_t               *nic = HANDLE_T_PTR(mtlk_core_t, hcore);
  wave_radio_t              *radio = wave_vap_radio_get(nic->vap_handle);
  mtlk_hw_api_t             *hw_api = mtlk_vap_get_hwapi(nic->vap_handle);
  mtlk_clpb_t               *clpb = *(mtlk_clpb_t **) data;
  mtlk_core_general_stats_t *general_stats;
  mtlk_txmm_stats_t          txm_stats;

  MTLK_ASSERT(sizeof(mtlk_clpb_t*) == data_size);

  general_stats = mtlk_osal_mem_alloc(sizeof(*general_stats), MTLK_MEM_TAG_CLPB);
  if(general_stats == NULL) {
    ELOG_D("CID-%04x: Can't allocate clipboard data", mtlk_vap_get_oid(nic->vap_handle));
    return MTLK_ERR_NO_MEM;
  }
  memset(general_stats, 0, sizeof(*general_stats));

  /* Fill Core private statistic fields*/
  general_stats->core_priv_stats = nic->pstats; /* struct copy */

  general_stats->tx_packets = nic->pstats.tx_packets;
  general_stats->tx_bytes   = nic->pstats.tx_bytes;
  general_stats->rx_packets = nic->pstats.rx_packets;
  general_stats->rx_bytes   = nic->pstats.rx_bytes;
  general_stats->rx_multicast_packets = nic->pstats.rx_multicast_packets;

  general_stats->unicast_replayed_packets = _mtlk_core_get_cnt(nic, MTLK_CORE_CNT_UNICAST_REPLAYED_PACKETS);
  general_stats->multicast_replayed_packets = _mtlk_core_get_cnt(nic, MTLK_CORE_CNT_MULTICAST_REPLAYED_PACKETS);
  general_stats->management_replayed_packets = _mtlk_core_get_cnt(nic, MTLK_CORE_CNT_MANAGEMENT_REPLAYED_PACKETS);
  general_stats->fwd_rx_packets = _mtlk_core_get_cnt(nic, MTLK_CORE_CNT_FWD_RX_PACKETS);
  general_stats->fwd_rx_bytes = _mtlk_core_get_cnt(nic, MTLK_CORE_CNT_FWD_RX_BYTES);
  general_stats->rx_dat_frames = _mtlk_core_get_cnt(nic, MTLK_CORE_CNT_DAT_FRAMES_RECEIVED);
  general_stats->rx_ctl_frames = _mtlk_core_get_cnt(nic, MTLK_CORE_CNT_CTL_FRAMES_RECEIVED);

  general_stats->tx_man_frames_res_queue = _mtlk_core_get_cnt(nic, MTLK_CORE_CNT_MAN_FRAMES_RES_QUEUE);
  general_stats->tx_man_frames_sent      = _mtlk_core_get_cnt(nic, MTLK_CORE_CNT_MAN_FRAMES_SENT);
  general_stats->tx_man_frames_confirmed = _mtlk_core_get_cnt(nic, MTLK_CORE_CNT_MAN_FRAMES_CONFIRMED);

  general_stats->rx_man_frames = _mtlk_core_get_cnt(nic, MTLK_CORE_CNT_MAN_FRAMES_RECEIVED);
  general_stats->rx_man_frames_retry_dropped = _mtlk_core_get_cnt(nic, MTLK_CORE_CNT_RX_MAN_FRAMES_RETRY_DROPPED);
  general_stats->rx_man_frames_fail = _mtlk_core_get_cnt(nic, MTLK_CORE_CNT_MAN_FRAMES_FAILED);

  general_stats->dgaf_disabled_tx_pck_dropped = _mtlk_core_get_cnt(nic, MTLK_CORE_CNT_TX_PACKETS_TO_UNICAST_DGAF_DISABLED);
  general_stats->dgaf_disabled_tx_pck_converted = _mtlk_core_get_cnt(nic, MTLK_CORE_CNT_TX_PACKETS_SKIPPED_DGAF_DISABLED);

  /* bss mgmt statistics */
  general_stats->tx_probe_resp_sent_cnt    = _mtlk_core_get_cnt(nic, MTLK_CORE_CNT_TX_PROBE_RESP_SENT);
  general_stats->tx_probe_resp_dropped_cnt = _mtlk_core_get_cnt(nic, MTLK_CORE_CNT_TX_PROBE_RESP_DROPPED);
  general_stats->bss_mgmt_tx_que_full_cnt = _mtlk_core_get_cnt(nic, MTLK_CORE_CNT_BSS_MGMT_TX_QUE_FULL);

  /* Radio status */
  general_stats->tx_probe_resp_sent_cnt_per_radio    = mtlk_wss_get_stat(nic->radio_wss, WAVE_RADIO_CNT_TX_PROBE_RESP_SENT);
  general_stats->tx_probe_resp_dropped_cnt_per_radio = mtlk_wss_get_stat(nic->radio_wss, WAVE_RADIO_CNT_TX_PROBE_RESP_DROPPED);
  general_stats->bss_mgmt_tx_que_full_cnt_per_radio  = mtlk_wss_get_stat(nic->radio_wss, WAVE_RADIO_CNT_BSS_MGMT_TX_QUE_FULL);

  /* HW status */
  (void)mtlk_hw_get_prop(hw_api, MTLK_HW_BSS_MGMT_MAX_MSGS, &general_stats->bss_mgmt_bds_max_num, sizeof(general_stats->bss_mgmt_bds_max_num));
  (void)mtlk_hw_get_prop(hw_api, MTLK_HW_BSS_MGMT_FREE_MSGS, &general_stats->bss_mgmt_bds_free_num, sizeof(general_stats->bss_mgmt_bds_free_num));
  (void)mtlk_hw_get_prop(hw_api, MTLK_HW_BSS_MGMT_MSGS_USED_PEAK, &general_stats->bss_mgmt_bds_usage_peak, sizeof(general_stats->bss_mgmt_bds_usage_peak));
  (void)mtlk_hw_get_prop(hw_api, MTLK_HW_BSS_MGMT_MAX_RES_MSGS, &general_stats->bss_mgmt_bds_max_num_res, sizeof(general_stats->bss_mgmt_bds_max_num_res));
  (void)mtlk_hw_get_prop(hw_api, MTLK_HW_BSS_MGMT_FREE_RES_MSGS, &general_stats->bss_mgmt_bds_free_num_res, sizeof(general_stats->bss_mgmt_bds_free_num_res));
  (void)mtlk_hw_get_prop(hw_api, MTLK_HW_BSS_MGMT_MSGS_RES_USED_PEAK, &general_stats->bss_mgmt_bds_usage_peak_res, sizeof(general_stats->bss_mgmt_bds_usage_peak_res));

  (void)mtlk_hw_get_prop(hw_api, MTLK_HW_FREE_TX_MSGS, &general_stats->tx_msdus_free, sizeof(general_stats->tx_msdus_free));
  (void)mtlk_hw_get_prop(hw_api, MTLK_HW_TX_MSGS_USED_PEAK, &general_stats->tx_msdus_usage_peak, sizeof(general_stats->tx_msdus_usage_peak));
  (void)mtlk_hw_get_prop(hw_api, MTLK_HW_BIST, &general_stats->bist_check_passed, sizeof(general_stats->bist_check_passed));
  (void)mtlk_hw_get_prop(hw_api, MTLK_HW_FW_BUFFERS_PROCESSED, &general_stats->fw_logger_packets_processed, sizeof(general_stats->fw_logger_packets_processed));
  (void)mtlk_hw_get_prop(hw_api, MTLK_HW_FW_BUFFERS_DROPPED, &general_stats->fw_logger_packets_dropped, sizeof(general_stats->fw_logger_packets_dropped));
  (void)mtlk_hw_get_prop(hw_api, MTLK_HW_RADARS_DETECTED, &general_stats->radars_detected, sizeof(general_stats->radars_detected));
#ifdef CPTCFG_IWLWAV_LEGACY_INT_RECOVERY_MON
  (void)mtlk_hw_get_prop(hw_api, MTLK_HW_ISR_LOST_SUSPECT, &general_stats->isr_lost_suspect, sizeof(general_stats->isr_lost_suspect));
  (void)mtlk_hw_get_prop(hw_api, MTLK_HW_ISR_LOST_RECOVERED, &general_stats->isr_recovered, sizeof(general_stats->isr_recovered));
#endif

#ifdef MTLK_DEBUG
  (void)mtlk_hw_get_prop(hw_api, MTLK_HW_FW_CFM_IN_TASKLET,         &general_stats->tx_max_cfm_in_tasklet,      sizeof(general_stats->tx_max_cfm_in_tasklet));
  (void)mtlk_hw_get_prop(hw_api, MTLK_HW_FW_TX_TIME_INT_TO_TASKLET, &general_stats->tx_max_time_int_to_tasklet, sizeof(general_stats->tx_max_time_int_to_tasklet));
  (void)mtlk_hw_get_prop(hw_api, MTLK_HW_FW_TX_TIME_INT_TO_CFM,     &general_stats->tx_max_time_int_to_pck,     sizeof(general_stats->tx_max_time_int_to_pck));
  (void)mtlk_hw_get_prop(hw_api, MTLK_HW_FW_DATA_IN_TASKLET,        &general_stats->rx_max_pck_in_tasklet,      sizeof(general_stats->rx_max_pck_in_tasklet));
  (void)mtlk_hw_get_prop(hw_api, MTLK_HW_FW_RX_TIME_INT_TO_TASKLET, &general_stats->rx_max_time_int_to_tasklet, sizeof(general_stats->rx_max_time_int_to_tasklet));
  (void)mtlk_hw_get_prop(hw_api, MTLK_HW_FW_RX_TIME_INT_TO_PCK,     &general_stats->rx_max_time_int_to_pck,     sizeof(general_stats->rx_max_time_int_to_pck));
#endif

  mtlk_txmm_get_stats(mtlk_vap_get_txmm(nic->vap_handle), &txm_stats);
  general_stats->txmm_sent = txm_stats.nof_sent;
  general_stats->txmm_cfmd = txm_stats.nof_cfmed;
  general_stats->txmm_peak = txm_stats.used_peak;

  mtlk_txmm_get_stats(mtlk_vap_get_txdm(nic->vap_handle), &txm_stats);
  general_stats->txdm_sent = txm_stats.nof_sent;
  general_stats->txdm_cfmd = txm_stats.nof_cfmed;
  general_stats->txdm_peak = txm_stats.used_peak;

  /* For master VAP only */
  if(mtlk_vap_is_master(nic->vap_handle)) {
    mtlk_vap_handle_t   vap_handle = nic->vap_handle;
    mtlk_hw_t          *hw = mtlk_vap_get_hw(vap_handle);
    wave_radio_t       *radio = wave_vap_radio_get(vap_handle);
    int                 chip_id = hw_mmb_get_chip_id(hw);
    unsigned            radio_idx = wave_radio_id_get(radio);

    /* Sync Log Timestamp with FW TSF */
    _mtlk_core_sync_log_timestamp(vap_handle);

    /* Check HW ring queues */
    if (wave_hw_mmb_all_rings_queue_check(hw)) {
      ELOG_V("Ring failure -> Reset FW");
      (void)mtlk_hw_set_prop(mtlk_vap_get_hwapi(nic->vap_handle), MTLK_HW_RESET, NULL, 0);
      res = MTLK_ERR_UNKNOWN;
      goto FINISH;
    }

    wave_radio_clean_probe_req_list(radio, FALSE);

    /* if any core on this card is scanning then _mtlk_core_get_statistics is
     * invoked from scan context and  not from stats context, this
     * prevents both scan and stats context accessing the common stats buffer */
    if (_chipid_is_gen7(chip_id)) {
      if ((wave_radio_is_first(radio) ||
         (wave_hw_master_vap_net_state_is_not_connected(hw, WAVE_RADIO_ID_FIRST) && ((radio_idx == WAVE_RADIO_ID_SECOND) ||
         ((radio_idx == WAVE_RADIO_ID_THIRD) && wave_hw_master_vap_net_state_is_not_connected(hw, WAVE_RADIO_ID_SECOND)))))
         && (mtlk_hw_stats_scan_allow(hw))) {
          res = mtlk_core_get_statistics(nic, hw);
          if (MTLK_ERR_OK != res)
            goto FINISH;
      }
    } else {
      if ((wave_radio_is_first(radio) || (wave_hw_is_cdb(hw) &&
         wave_hw_master_vap_net_state_is_not_connected(hw, WAVE_RADIO_ID_FIRST)))
         && (mtlk_hw_stats_scan_allow(hw))) {
          res = mtlk_core_get_statistics(nic, hw);
          if (MTLK_ERR_OK != res)
            goto FINISH;
      }
    }

    if (mtlk_hw_get_stats_available(hw)) {
      struct intel_vendor_channel_data ch_data;
      mtlk_osal_msec_t cur_time = mtlk_osal_timestamp_to_ms(mtlk_osal_timestamp());
      iwpriv_cca_adapt_t cca_adapt_params;
      mtlk_pdb_size_t cca_adapt_size = sizeof(cca_adapt_params);
      memset(&ch_data, 0, sizeof(ch_data));

      /* Update all VAPs Statistics */
      res = _mtlk_core_update_vaps_mhi_stats(nic, radio, hw);
      if (MTLK_ERR_OK != res)
        goto FINISH;

      res = _mtlk_core_mac_get_phy_status(nic, hw, general_stats);
      if (MTLK_ERR_OK != res)
        goto FINISH;

      /* if beacons were blocked due to CCA, need to poll CWI */
      if (nic->slow_ctx->cca_adapt.cwi_poll) {
        if (MTLK_ERR_OK != WAVE_RADIO_PDB_GET_BINARY(radio, PARAM_DB_RADIO_CCA_ADAPT, &cca_adapt_params, &cca_adapt_size))
          goto FINISH;

        if ((cur_time - nic->slow_ctx->cca_adapt.cwi_poll_ts) > (cca_adapt_params.iterative * DEFAULT_BEACON_INTERVAL)) {
          scan_get_aocs_info(nic, &ch_data);
          mtlk_cca_step_up_if_allowed(nic, ch_data.cwi_noise, cca_adapt_params.limit, cca_adapt_params.step_up);
          nic->slow_ctx->cca_adapt.cwi_poll_ts = cur_time;
        }
      }

      /* for AP channel 0 means "use AOCS" */
      if (!WAVE_RADIO_PDB_GET_INT(radio, PARAM_DB_RADIO_CHANNEL_CFG) &&
          WAVE_RADIO_PDB_GET_INT(radio, PARAM_DB_RADIO_ACS_UPDATE_TO) &&
          (cur_time - nic->acs_updated_ts) > WAVE_RADIO_PDB_GET_UINT(radio, PARAM_DB_RADIO_ACS_UPDATE_TO))
      {
        fill_channel_data(nic, &ch_data);

        res = mtlk_send_chan_data(nic->vap_handle, &ch_data, sizeof(ch_data));
        if (MTLK_ERR_OK != res)
          goto FINISH;

        nic->acs_updated_ts = cur_time;
      } else {
        get_channel_data_hw_save_chan_stats_info(nic, &ch_data);
      }

      /* for each stat update request, we fill the chan_statistics info
       * of the serving channel, So any userspace application can fetch the
       * info at later point of time.
       * No need to check ZWDFS radio as Channel stats are not available for it.
       */
      wave_hw_stats_scan_lock_acquire(hw);
      if (mtlk_hw_stats_scan_allow(hw))
        mtlk_core_save_chan_statistics_info(nic, &ch_data);

      wave_hw_stats_scan_lock_release(hw);
    }

    if (MTLK_ERR_OK != res) {
      goto FINISH;
    }

    /* Fill core status fields */
    general_stats->net_state = mtlk_core_get_net_state(nic);

    MTLK_CORE_PDB_GET_MAC(nic, PARAM_DB_CORE_BSSID, &general_stats->bssid);

    if (mtlk_vap_is_sta(nic->vap_handle) && (mtlk_core_get_net_state(nic) == NET_STATE_CONNECTED)) {
      sta_entry *sta =  mtlk_stadb_get_ap(&nic->slow_ctx->stadb);

      if (NULL != sta) {
        general_stats->max_rssi = mtlk_sta_get_max_rssi(sta);

        mtlk_sta_decref(sta);  /* De-reference of get_ap */
      }
    }
  }
  general_stats->rx_drops    = nic->mhi_vap_stat.stats.dropMpdu;
  general_stats->rx_errors   = nic->mhi_vap_stat.stats.mpduTypeNotSupported +
                               nic->mhi_vap_stat.stats.replayData +
                               nic->mhi_vap_stat.stats.replayMngmnt +
                               nic->mhi_vap_stat.stats.tkipCount +
                               nic->mhi_vap_stat.stats.securityFailure;
  /* Radio Phy Status */
  {
    wave_radio_phy_stat_t phy_stat;

    wave_radio_phy_status_get(radio, &phy_stat);

    general_stats->noise              = phy_stat.noise;
    general_stats->channel_util       = phy_stat.ch_util;
    general_stats->airtime            = phy_stat.airtime;
    general_stats->airtime_efficiency = phy_stat.airtime_efficiency;;
  }

  /* update UL/DL ofdma band stats */
  _wave_link_adapt_ofdma_band_ppdus_stats(nic);

  /* Get PHY Status */
  _mtlk_core_mac_update_peers_stats(nic);

  /* Return Core status & statistic data */
  res = mtlk_clpb_push_nocopy(clpb, general_stats, sizeof(*general_stats));
  if (MTLK_ERR_OK != res) {
    mtlk_clpb_purge(clpb);
    goto FINISH;
  }
  return MTLK_ERR_OK;

FINISH:
  mtlk_osal_mem_free(general_stats);
  return res;
}

void __MTLK_IFUNC core_wds_beacon_process(mtlk_core_t *master_core, wds_beacon_data_t *beacon_data)
{
  wds_t           *master_wds = &master_core->slow_ctx->wds_mng;
  wds_on_beacon_t *on_beacon;

  ILOG5_V("Processing a WDS beacon");

  mtlk_osal_lock_acquire(&master_wds->on_beacon_lock);
  on_beacon = wds_on_beacon_find_remove(master_wds, &beacon_data->addr, FALSE);
  if (on_beacon) {
    beacon_data->vap_idx = on_beacon->vap_id;
    if (NULL == on_beacon->ie_data) {
      on_beacon->ie_data = mtlk_osal_mem_alloc(beacon_data->ie_data_len, LQLA_MEM_TAG_WDS);
      if (on_beacon->ie_data) {
        wave_memcpy(on_beacon->ie_data, beacon_data->ie_data_len,
                    beacon_data->ie_data, beacon_data->ie_data_len);
        on_beacon->ie_data_len = beacon_data->ie_data_len;
        _mtlk_process_hw_task(master_core, SERIALIZABLE, wds_beacon_process, HANDLE_T(master_wds), beacon_data, sizeof(wds_beacon_data_t));
      }
    }
  }
  mtlk_osal_lock_release(&master_wds->on_beacon_lock);
}

BOOL __MTLK_IFUNC core_wds_frame_drop(mtlk_core_t *core, IEEE_ADDR *addr)
{
  wds_t               *wds_ctx = &core->slow_ctx->wds_mng;

  return wds_sta_is_peer_ap(wds_ctx, addr);
}

uint32 __MTLK_IFUNC
mtlk_core_ta_on_timer (mtlk_osal_timer_t *timer, mtlk_handle_t ta_handle)
{
  /* Note: This function is called from timer context
           Do not modify TA structure from here
  */
  mtlk_core_t     *core;

  mtlk_vap_handle_t vap_handle = mtlk_ta_get_vap_handle(ta_handle);
  if (vap_handle) {
    core = mtlk_vap_get_core(vap_handle);
    mtlk_core_schedule_internal_task(core, ta_handle, ta_timer, NULL, 0);
    return mtlk_ta_get_timer_resolution_ms(ta_handle);
  } else {
    ELOG_V("Can't to schedule TA task: VAP-handler not found");
    return 0;
  }
}

int __MTLK_IFUNC core_on_rcvry_isol (mtlk_core_t *core, uint32 rcvry_type)
{
  int res;

  if (mtlk_vap_is_master_ap(core->vap_handle)) {
    mtlk_coc_t *coc_mgmt = __wave_core_coc_mgmt_get(core);
    mtlk_erp_t *erp_mgmt = __wave_core_erp_mgmt_get(core);
    mtlk_ta_on_rcvry_isol(mtlk_vap_get_ta(core->vap_handle));

    /* Disable MAC WatchDog */
    mtlk_osal_timer_cancel_sync(&core->slow_ctx->mac_watchdog_timer);

    /* CoC isolation */
    mtlk_coc_on_rcvry_isol(coc_mgmt);
    mtlk_erp_on_rcvry_isol(erp_mgmt);

    /* radio isolation */
#if WAVE_USE_BSS_TX_MONITOR
    wave_radio_on_rcvry_isol(wave_vap_radio_get(core->vap_handle));
#endif

    if (mtlk_core_scan_is_running(core)) {
      res = pause_or_prevent_scan(core);
      if (MTLK_ERR_OK != res) {
        return res;
      }
    }
  }

  wave_clean_all_sta_on_disconnect(core);

  if (mtlk_vap_is_ap(core->vap_handle)) {
    wds_on_if_down(&core->slow_ctx->wds_mng);
  }

  mtlk_stadb_stop(&core->slow_ctx->stadb);

  res = wave_beacon_man_rcvry_reset(core);
  if (MTLK_ERR_OK != res) {
    return res;
  }

  res = mtlk_core_set_net_state(core, NET_STATE_HALTED);
  if (res != MTLK_ERR_OK) {
    return res;
  }

  return MTLK_ERR_OK;
}

void __MTLK_IFUNC
core_on_rcvry_error (mtlk_core_t *core)
{
  if (mtlk_vap_is_master(core->vap_handle)) {
    wave_core_sync_hostapd_done_set(core, TRUE);
    ILOG1_D("CID-%04x: Recovery: Set HOSTAPD STA database synced to TRUE", mtlk_vap_get_oid(core->vap_handle));
  }
}

static void
mtlk_core_on_rcvry_reset_counters(mtlk_core_t *core)
{
  /* Reset data packet confirmation counter */
  mtlk_osal_atomic_set(&core->unconfirmed_data, 0);

  /* Reset management packet sent/confirmed counters */
  _mtlk_core_reset_cnt(core, MTLK_CORE_CNT_MAN_FRAMES_SENT);
  _mtlk_core_reset_cnt(core, MTLK_CORE_CNT_MAN_FRAMES_CONFIRMED);

  /* Reserved queue is cleaned up in mtlk_hw_mmb_restore, so just reset counter */
  _mtlk_core_reset_cnt(core, MTLK_CORE_CNT_MAN_FRAMES_RES_QUEUE);
}

int __MTLK_IFUNC
core_on_rcvry_restore (mtlk_core_t *core, uint32 rcvry_type)
{
  /* Restore CORE's data & variables
     not related with current configuration
  */
  int res = MTLK_ERR_OK;

  res = mtlk_core_set_net_state(core, NET_STATE_IDLE);
  if (res != MTLK_ERR_OK) {
    return res;
  }

  if (mtlk_vap_is_master(core->vap_handle)) {
    wave_radio_t *radio = wave_vap_radio_get(core->vap_handle);

    /* Restore WATCHDOG timer */
    mtlk_osal_timer_set(&core->slow_ctx->mac_watchdog_timer,
                        WAVE_RADIO_PDB_GET_INT(radio, PARAM_DB_RADIO_MAC_WATCHDOG_TIMER_PERIOD_MS));

    wave_radio_progmodel_loaded_set(radio, FALSE);
    wave_radio_last_pm_freq_set(radio, MTLK_HW_BAND_NONE);

    /* Reset Radio Calibration context */
    if (RCVRY_TYPE_FULL == rcvry_type) {
      struct mtlk_chan_def  *ccd = wave_radio_chandef_get(radio);
      struct scan_support   *ss  = wave_radio_scan_support_get(radio);

      /* Make channel uncertain */
      ccd->center_freq1 = 0;
      ccd->power_level = MTLK_POWER_NOT_SET;

      /* Reset previously calibrated channels list */
      memset(ss->css, 0, sizeof(ss->css));
      memset(ss->css_6g, 0, sizeof(ss->css_6g));
    }
    /* radio restore */
#if WAVE_USE_BSS_TX_MONITOR
    wave_radio_on_rcvry_restore(radio);
#endif
    /* Reset MU GROUP Statistics */
#ifdef CONFIG_WAVE_DEBUG
    wave_radio_on_rcvry_reset_mu_group_stats(radio);
#endif /* CONFIG_WAVE_DEBUG */

    /* Reset Statistics */
    wave_hw_stats_lock(mtlk_vap_get_hw(core->vap_handle), TRUE);
    wave_hw_reset_stats_snapshot(mtlk_vap_get_hw(core->vap_handle));
    wave_hw_reset_stats(mtlk_vap_get_hw(core->vap_handle));
    wave_radio_reset_ofdma_stats(radio);
    wave_hw_stats_lock(mtlk_vap_get_hw(core->vap_handle), FALSE);
  }

  /* Reset required counters */
  mtlk_core_on_rcvry_reset_counters (core);

  res = mtlk_core_set_net_state(core, NET_STATE_READY);
  if (res != MTLK_ERR_OK) {
    ELOG_D("Set net state failed. res=%d", res);
    return res;
  }

  return MTLK_ERR_OK;
}

static mtlk_error_t core_on_rcvry_security(mtlk_core_t *core)
{
  mtlk_error_t res;
  int i;

  for (i = 0; i < WAVE_NUM_KEYS; i++) {
    if ((i < WAVE_WEP_NUM_DEFAULT_KEYS) || IS_BCN_KEY_IDX(i)) {
      res = wave_core_set_umi_key(core, i);
      if (res != MTLK_ERR_OK) {
        ELOG_DD("CID-%04x: Recovery failed. res=%d", mtlk_vap_get_oid(core->vap_handle), res);
        return res;
      }
    }
  }

  res = core_recovery_default_key(core, FALSE);
  if (res != MTLK_ERR_OK) {
    ELOG_DD("CID-%04x: Recovery failed. res=%d", mtlk_vap_get_oid(core->vap_handle), res);
    return res;
  }

  return res;
}

static int core_recovery_cfg_set_ap_beacon_info(mtlk_core_t *core)
{
  struct mtlk_beacon_info_parameters beacon_params;

  MTLK_ASSERT(core != NULL);

  if (!core->slow_ctx->ap_started) {
    /* recovery started before beacon info was sent */
    ILOG1_D("CID-%04x: Recovery: AP not started yet, not sending SET_AP_BEACON_INFO",
            mtlk_vap_get_oid(core->vap_handle));
    return MTLK_ERR_OK;
  }

  memset(&beacon_params, 0, sizeof(beacon_params));
  beacon_params.vap_index = mtlk_vap_get_id(core->vap_handle);

  ILOG4_V("Dealing with DTIM and Beacon intervals");
  beacon_params.beacon_int = (uint16) MTLK_CORE_PDB_GET_INT(core, PARAM_DB_CORE_BEACON_PERIOD);
  beacon_params.dtim_period = (uint16) MTLK_CORE_PDB_GET_INT(core, PARAM_DB_CORE_DTIM_PERIOD);

  return mtlk_core_set_ap_beacon_info_by_params(core, &beacon_params);
}

static __INLINE BOOL
__mtlk_core_11b_antsel_configured (mtlk_11b_antsel_t *antsel)
{
  MTLK_ASSERT(antsel != NULL);

  return antsel->txAnt != MTLK_PARAM_DB_INVALID_UINT8 &&
         antsel->rxAnt != MTLK_PARAM_DB_INVALID_UINT8 &&
         antsel->rate  != MTLK_PARAM_DB_INVALID_UINT8;
}

static mtlk_error_t
_mtlk_core_set_11b_antsel (mtlk_core_t *core)
{
  wave_radio_t *radio = wave_vap_radio_get(core->vap_handle);
  mtlk_11b_antsel_t antsel;

  memset(&antsel, 0, sizeof(antsel));
  antsel.txAnt = WAVE_RADIO_PDB_GET_INT(radio, PARAM_DB_RADIO_11B_ANTSEL_TXANT);
  antsel.rxAnt = WAVE_RADIO_PDB_GET_INT(radio, PARAM_DB_RADIO_11B_ANTSEL_RXANT);
  antsel.rate =  WAVE_RADIO_PDB_GET_INT(radio, PARAM_DB_RADIO_11B_ANTSEL_RATE);

  if (!__mtlk_core_11b_antsel_configured(&antsel))
    return MTLK_ERR_OK;

  return mtlk_core_send_11b_antsel(core, &antsel);
}

static int
mtlk_core_rcvry_set_channel (mtlk_core_t *core, BOOL cac_started)
{
  mtlk_handle_t ccd_handle;
  struct mtlk_chan_def *ccd;
  struct set_chan_param_data *cpd = NULL;

  if (cac_started) {
    cpd = mtlk_core_chan_param_data_get(core);
    if (NULL == cpd)
      return MTLK_ERR_NOT_SUPPORTED;
  }

  wave_rcvry_chandef_current_get(mtlk_vap_get_hw(core->vap_handle),
                                 mtlk_vap_get_manager(core->vap_handle),
                                 &ccd_handle);
  ccd = (struct mtlk_chan_def *)ccd_handle;
  if (NULL == ccd)
    return MTLK_ERR_NOT_SUPPORTED;

  if (cpd && !mtlk_core_is_chandef_identical(ccd, &cpd->chandef))
    cpd = NULL;

  return core_cfg_set_chan(core, ccd, cpd);
}

static int
mtlk_core_cfg_recovery_set_coex (mtlk_core_t *core)
{
  wave_radio_t *radio = wave_vap_radio_get(core->vap_handle);
  uint8 coex_mode     = (uint8)WAVE_RADIO_PDB_GET_INT(radio, PARAM_DB_RADIO_COEX_MODE);
  uint32 active_time  = WAVE_RADIO_PDB_GET_INT(radio, PARAM_DB_RADIO_COEX_ACTIVE_TIME);
  uint8 inactive_time = (uint8)WAVE_RADIO_PDB_GET_INT(radio, PARAM_DB_RADIO_COEX_INACTIVE_TIME);
  uint8 cts2self_active = (uint8)WAVE_RADIO_PDB_GET_INT(radio, PARAM_DB_RADIO_COEX_CTS2SELF_ACTIVE);

  if (MTLK_ERR_OK != mtlk_core_is_band_supported(core, UMI_PHY_TYPE_BAND_2_4_GHZ))
    return MTLK_ERR_OK;

  return mtlk_core_send_coex_config_req(core, coex_mode, active_time, inactive_time, cts2self_active);
}

static int _mtlk_core_rcvry_set_pd_threshold (mtlk_core_t *core)
{
  UMI_SET_PD_THRESH pd_thresh;

  mtlk_core_cfg_get_pd_threshold(core, &pd_thresh);

  if (QOS_PD_THRESHOLD_NUM_MODES == pd_thresh.mode)
    return MTLK_ERR_OK;

  return mtlk_core_cfg_send_pd_threshold(core, &pd_thresh);
}

static int _mtlk_core_rcvry_set_resticted_ac_mode (mtlk_core_t *core)
{
  UMI_SET_RESTRICTED_AC restricted_ac_mode;

  mtlk_core_cfg_get_restricted_ac_mode(core, &restricted_ac_mode);

  if (MTLK_PARAM_DB_VALUE_IS_INVALID(restricted_ac_mode.restrictedAcModeEnable))
    return MTLK_ERR_OK;

  return mtlk_core_cfg_send_restricted_ac_mode(core, &restricted_ac_mode);
}

static int _mtlk_core_recover_aggr_cfg (mtlk_core_t *core)
{
  uint8 amsdu_mode   = MTLK_CORE_PDB_GET_INT(core, PARAM_DB_CORE_AMSDU_MODE);
  uint8 ba_mode      = MTLK_CORE_PDB_GET_INT(core, PARAM_DB_CORE_BA_MODE);
  uint32 window_size = MTLK_CORE_PDB_GET_INT(core, PARAM_DB_CORE_WINDOW_SIZE);

  if (MTLK_PARAM_DB_VALUE_IS_INVALID(amsdu_mode) ||
      MTLK_PARAM_DB_VALUE_IS_INVALID(ba_mode) ||
      MTLK_PARAM_DB_VALUE_IS_INVALID(window_size))
    return MTLK_ERR_OK;

  return mtlk_core_set_aggr_cfg_req(core, amsdu_mode, ba_mode, window_size);
}

static int
_mtlk_core_recover_agg_rate_limit (mtlk_core_t *core)
{
  mtlk_agg_rate_limit_cfg_t agg_rate_cfg;

  _mtlk_core_read_agg_rate_limit(core, &agg_rate_cfg);

  if (MTLK_PARAM_DB_VALUE_IS_INVALID(agg_rate_cfg.agg_rate_limit.mode))
      return MTLK_ERR_OK;

  return mtlk_core_set_agg_rate_limit(core, &agg_rate_cfg);
}

static int
_mtlk_core_recover_multicast_rate (mtlk_core_t *core)
{
  mtlk_multicast_rate_cfg_t multicast_rate_cfg;

  _mtlk_core_read_multicast_rate(core, &multicast_rate_cfg);

  if (MTLK_PARAM_DB_VALUE_IS_INVALID(multicast_rate_cfg.multicast_rate.mode))
      return MTLK_ERR_OK;

  return wave_core_send_multicast_rate(core, &multicast_rate_cfg);
}

static int
_mtlk_core_recover_mu_ofdma_bf (mtlk_core_t *core)
{
  mtlk_mu_ofdma_bf_cfg_t mu_ofdma_bf_cfg;

  _mtlk_core_read_mu_ofdma_bf(core, &mu_ofdma_bf_cfg);

  if (MTLK_PARAM_DB_VALUE_IS_INVALID(mu_ofdma_bf_cfg.mu_ofdma_bf.mode))
      return MTLK_ERR_OK;

  return wave_core_send_mu_ofdma_bf(core, &mu_ofdma_bf_cfg);
}

static int
_mtlk_core_recover_max_mpdu_length (mtlk_core_t *core)
{
  uint32 length = mtlk_core_cfg_read_max_mpdu_length(core);

  if (MTLK_PARAM_DB_VALUE_IS_INVALID(length))
    return MTLK_ERR_OK;

  return mtlk_core_cfg_send_max_mpdu_length(core, length);
}

static int
_mtlk_core_recover_mu_operation (mtlk_core_t *core)
{
  uint8 mu_operation = WAVE_RADIO_PDB_GET_INT(wave_vap_radio_get(core->vap_handle), PARAM_DB_RADIO_MU_OPERATION);

  if (MTLK_PARAM_DB_VALUE_IS_INVALID(mu_operation))
    return MTLK_ERR_OK;

  return mtlk_core_set_mu_operation(core, mu_operation);
}

static int _mtlk_core_recover_amsdu_cfg (mtlk_core_t *core)
{
  wave_radio_t *radio = wave_vap_radio_get(core->vap_handle);
  uint32 amsdu_num  = WAVE_RADIO_PDB_GET_INT(radio, PARAM_DB_RADIO_AMSDU_NUM);
  uint32 amsdu_vnum = WAVE_RADIO_PDB_GET_INT(radio, PARAM_DB_RADIO_AMSDU_VNUM);
  uint32 amsdu_henum = WAVE_RADIO_PDB_GET_INT(radio, PARAM_DB_RADIO_AMSDU_HENUM);
  uint32 amsdu_ehtnum = 0;
#ifdef MTLK_WAVE_700
  amsdu_ehtnum = WAVE_RADIO_PDB_GET_INT(radio, PARAM_DB_RADIO_AMSDU_EHTNUM);
  if (MTLK_PARAM_DB_VALUE_IS_INVALID(amsdu_ehtnum))
    return MTLK_ERR_OK;
#endif

  if (MTLK_PARAM_DB_VALUE_IS_INVALID(amsdu_num) ||
      MTLK_PARAM_DB_VALUE_IS_INVALID(amsdu_vnum) ||
      MTLK_PARAM_DB_VALUE_IS_INVALID(amsdu_henum))
      return MTLK_ERR_OK;

  return mtlk_core_set_amsdu_num_req(core, amsdu_num, amsdu_vnum, amsdu_henum, amsdu_ehtnum);
}

static int _mtlk_core_recover_qamplus_mode (mtlk_core_t *core)
{
  uint8 qam_plus_mode = WAVE_RADIO_PDB_GET_INT(wave_vap_radio_get(core->vap_handle), PARAM_DB_RADIO_QAMPLUS_MODE);

  if (MTLK_PARAM_DB_VALUE_IS_INVALID(qam_plus_mode))
    return MTLK_ERR_OK;

  return mtlk_core_qamplus_mode_req(core, qam_plus_mode);
}

static int _mtlk_recover_rts_mode (mtlk_core_t *core)
{
  uint8 dynamic_bw, static_bw;
  wave_radio_t *radio = wave_vap_radio_get(core->vap_handle);

  dynamic_bw = WAVE_RADIO_PDB_GET_INT(radio, PARAM_DB_RADIO_RTS_DYNAMIC_BW);
  static_bw  = WAVE_RADIO_PDB_GET_INT(radio, PARAM_DB_RADIO_RTS_STATIC_BW);

  if (MTLK_PARAM_DB_VALUE_IS_INVALID(dynamic_bw) ||
      MTLK_PARAM_DB_VALUE_IS_INVALID(static_bw))
    return MTLK_ERR_OK;

  return mtlk_core_set_rts_mode(core, dynamic_bw, static_bw);
}

static int _mtlk_core_recover_rx_duty_cycle (mtlk_core_t *core)
{
  uint32 on_time, off_time;
  mtlk_rx_duty_cycle_cfg_t duty_cycle_cfg;
  wave_radio_t *radio = wave_vap_radio_get(core->vap_handle);

  memset(&duty_cycle_cfg, 0, sizeof(duty_cycle_cfg));

  on_time  = WAVE_RADIO_PDB_GET_INT(radio, PARAM_DB_RADIO_RX_DUTY_CYCLE_ON_TIME);
  off_time = WAVE_RADIO_PDB_GET_INT(radio, PARAM_DB_RADIO_RX_DUTY_CYCLE_OFF_TIME);

  if (MTLK_PARAM_DB_VALUE_IS_INVALID(on_time) ||
      MTLK_PARAM_DB_VALUE_IS_INVALID(off_time))
    return MTLK_ERR_OK;

  duty_cycle_cfg.duty_cycle.onTime  = on_time;
  duty_cycle_cfg.duty_cycle.offTime = off_time;

  return mtlk_core_set_rx_duty_cycle(core, &duty_cycle_cfg);
}

static int _mtlk_core_recover_rx_threshold (mtlk_core_t *core)
{
  uint32 rx_thr = MTLK_CORE_PDB_GET_INT(core, PARAM_DB_CORE_RX_THRESHOLD);
  mtlk_rx_th_cfg_t rx_th_cfg;

  if (MTLK_PARAM_DB_VALUE_IS_INVALID(rx_thr))
    return MTLK_ERR_OK;

  /* Validated on iwpriv setter */
  rx_th_cfg.rx_threshold = (int8)rx_thr;

  return mtlk_core_set_rx_threshold(core, &rx_th_cfg);
}
static int _mtlk_core_recover_preamble_puncture_override (mtlk_core_t *core)
{
  UMI_PREAMBLE_PUNCT_CCA_OVERRIDE req;
  mtlk_pdb_size_t size = sizeof(req);
  wave_radio_t *radio = wave_vap_radio_get(core->vap_handle);
  int res;

  MTLK_ASSERT(radio);
  res = WAVE_RADIO_PDB_GET_BINARY(radio, PARAM_DB_RADIO_PREAMBLE_PUNCTURE_CFG, &req, &size);
  if (MTLK_ERR_OK == res) {
    res = wave_core_cfg_send_cca_preamble_puncture_override(core, &req);
  }

  return res;
}

static int _mtlk_core_recover_slow_probing_mask (mtlk_core_t *core)
{
  uint32 mask = WAVE_RADIO_PDB_GET_INT(wave_vap_radio_get(core->vap_handle), PARAM_DB_RADIO_SLOW_PROBING_MASK);

  if (MTLK_PARAM_DB_VALUE_IS_INVALID(mask))
    return MTLK_ERR_OK;

  return mtlk_core_cfg_send_slow_probing_mask(core, mask);
}

static int _mtlk_core_recover_ssb_mode (mtlk_core_t *core)
{
  mtlk_ssb_mode_cfg_t ssb_mode_cfg;
  uint32              ssb_mode_cfg_data_size = MTLK_SSB_MODE_CFG_SIZE;

  mtlk_core_read_ssb_mode(core, &ssb_mode_cfg, &ssb_mode_cfg_data_size);

  if (MTLK_PARAM_DB_VALUE_IS_INVALID(ssb_mode_cfg.params[MTLK_SSB_MODE_CFG_EN]) ||
      MTLK_PARAM_DB_VALUE_IS_INVALID(ssb_mode_cfg.params[MTLK_SSB_MODE_CFG_20MODE]))
    return MTLK_ERR_OK;

  return mtlk_core_send_ssb_mode(core, &ssb_mode_cfg);
}

static mtlk_error_t _mtlk_core_recover_txop_params (mtlk_core_t *core)
{
  UMI_SET_TXOP_CONFIG txop_params;
  mtlk_error_t res = wave_core_cfg_get_txop_params(core, &txop_params);

  if (MTLK_ERR_OK == res)
    res = wave_core_cfg_send_txop_params(core, &txop_params);

  return res;
}

static int _mtlk_core_recover_admission_capacity (mtlk_core_t *core)
{
  uint32 admission_capacity = MTLK_CORE_PDB_GET_INT(core, PARAM_DB_CORE_ADMISSION_CAPACITY);

  if (MTLK_PARAM_DB_VALUE_IS_INVALID(admission_capacity))
    return MTLK_ERR_OK;

  return mtlk_core_set_admission_capacity(core, admission_capacity);
}

static int _mtlk_core_recover_fast_drop (mtlk_core_t *core)
{
  uint8 fast_drop =  WAVE_RADIO_PDB_GET_INT(wave_vap_radio_get(core->vap_handle), PARAM_DB_RADIO_FAST_DROP);

  if (MTLK_PARAM_DB_VALUE_IS_INVALID(fast_drop))
    return MTLK_ERR_OK;

  return mtlk_core_cfg_send_fast_drop(core, fast_drop);
}

static int _mtlk_recover_bf_mode (mtlk_core_t *core)
{
  uint8 bf_mode = WAVE_RADIO_PDB_GET_INT(wave_vap_radio_get(core->vap_handle), PARAM_DB_RADIO_BF_MODE);

  if (MTLK_PARAM_DB_BF_MODE_IS_INVALID(bf_mode))
    return MTLK_ERR_OK;

  return mtlk_core_send_bf_mode(core, bf_mode);
}

static mtlk_error_t _mtlk_core_recover_interfdet_threshold (mtlk_core_t *core)
{
  wave_radio_t *radio = wave_vap_radio_get(core->vap_handle);

  if (wave_radio_interfdet_get(radio))
    return mtlk_core_set_fw_interfdet_req(core, (int8)WAVE_RADIO_PDB_GET_INT(radio, PARAM_DB_RADIO_INTERFDET_THRESHOLD));

  return MTLK_ERR_OK;
}

static mtlk_error_t _wave_core_recover_ap_retry_limit (mtlk_core_t *core)
{
  wave_retry_limit_cfg_t retry_limit_cfg;

  retry_limit_cfg.retry_limit.retry_limit_mgmt = WAVE_RADIO_PDB_GET_INT(wave_vap_radio_get(core->vap_handle), PARAM_DB_RADIO_AP_RETRY_LIMIT);
  retry_limit_cfg.retry_limit.retry_limit_data = WAVE_RADIO_PDB_GET_INT(wave_vap_radio_get(core->vap_handle), PARAM_DB_RADIO_AP_RETRY_LIMIT_DATA);
  retry_limit_cfg.retry_limit.retry_limit_proberesp = WAVE_RADIO_PDB_GET_INT(wave_vap_radio_get(core->vap_handle), PARAM_DB_RADIO_AP_RETRY_LIMIT_PROBERESP);

  if (MTLK_PARAM_DB_VALUE_IS_INVALID(retry_limit_cfg.retry_limit.retry_limit_mgmt) ||
      MTLK_PARAM_DB_VALUE_IS_INVALID(retry_limit_cfg.retry_limit.retry_limit_data) ||
      MTLK_PARAM_DB_VALUE_IS_INVALID(retry_limit_cfg.retry_limit.retry_limit_proberesp)) {
    return MTLK_ERR_OK;
  }

  return wave_core_cfg_send_retry_limit(core, &retry_limit_cfg);
}

static mtlk_error_t _wave_core_recover_ap_exce_retry_limit (mtlk_core_t *core)
{
  mtlk_exce_retry_limit_cfg_t retry_limit_cfg;
  memset(&retry_limit_cfg, 0, sizeof(retry_limit_cfg));
  retry_limit_cfg.exce_retry_limit = MTLK_CORE_PDB_GET_INT(core, PARAM_DB_CORE_AP_RETRY_LIMIT_EXCE);

  if (MTLK_PARAM_DB_VALUE_IS_INVALID(retry_limit_cfg.exce_retry_limit)) {
     return MTLK_ERR_OK;
  }
  return  wave_core_cfg_send_exce_retry_limit(core, retry_limit_cfg.exce_retry_limit);
}

static void
_mtlk_core_rcvry_chan_switch_notify (mtlk_core_t *core)
{
  mtlk_df_t         *df       = mtlk_vap_get_df(core->vap_handle);
  mtlk_df_user_t    *df_user  = mtlk_df_get_user(df);
  struct net_device *ndev     = mtlk_df_user_get_ndev(df_user);

  wv_cfg80211_ch_switch_notify(ndev, __wave_core_chandef_get(core), FALSE);
}

static mtlk_error_t _wave_core_recover_dynamic_wmm (mtlk_core_t *core)
{
  wave_radio_t *radio = wave_vap_radio_get(core->vap_handle);
  uint8 enabled = WAVE_RADIO_PDB_GET_INT(radio, PARAM_DB_RADIO_DYNAMIC_WMM);

  if (MTLK_PARAM_DB_VALUE_IS_INVALID(enabled))
    return MTLK_ERR_OK;

  return wave_core_set_dynamic_wmm(core, enabled);
}

static mtlk_error_t _wave_core_recover_dynamic_edca (mtlk_core_t *core)
{
  wave_radio_t *radio = wave_vap_radio_get(core->vap_handle);
  uint8 enabled = WAVE_RADIO_PDB_GET_INT(radio, PARAM_DB_RADIO_DYNAMIC_EDCA);

  if (MTLK_PARAM_DB_VALUE_IS_INVALID(enabled))
    return MTLK_ERR_OK;

  return wave_core_set_dynamic_edca(core, enabled);
}

#define RECOVERY_INFO(text, oid)    do { ILOG1_DS("CID-%04x: Recovery %s", oid, text); } while(0)
#define RECOVERY_WARN(text, oid)    do { WLOG_DS("CID-%04x: Recovery %s", oid, text);  } while(0)
static int _core_on_rcvry_configure (mtlk_core_t *core, uint32 target_net_state)
{
  int res = MTLK_ERR_OK;
  uint32                    active_ant_mask;
  mtlk_hw_band_e            band;
  uint16 core_oid                       = mtlk_vap_get_oid(core->vap_handle);
  mtlk_core_t *master_core              = mtlk_core_get_master(core->vap_handle);
  struct mtlk_chan_def *current_chandef = __wave_core_chandef_get(master_core);
  mtlk_scan_support_t *ss               = mtlk_core_get_scan_support(core);
  mtlk_coc_t *coc_mgmt                  = __wave_core_coc_mgmt_get(core);
  mtlk_erp_t *erp_mgmt                  = __wave_core_erp_mgmt_get(core);
  wave_radio_t *radio                   = wave_vap_radio_get(core->vap_handle);
  mtlk_hw_t *hw                         = mtlk_vap_get_hw(core->vap_handle);
  mtlk_vap_manager_t *vap_manager       = mtlk_vap_get_manager(core->vap_handle);
  mtlk_df_t *df                         = mtlk_vap_get_df(core->vap_handle);
  mtlk_df_user_t *df_user               = mtlk_df_get_user(df);
  struct wireless_dev *wdev             = mtlk_df_user_get_wdev(df_user);
  uint32 chip_id                        = hw_mmb_get_chip_id(hw);
  BOOL cac_started                      = FALSE;

  MTLK_ASSERT(master_core != NULL);
  MTLK_ASSERT(current_chandef != NULL);

  MTLK_UNUSED_VAR(core_oid);
  ILOG1_DS("CID-%04x: Recovery: target_net_state: %s", core_oid, mtlk_net_state_to_string(target_net_state));

  RECOVERY_INFO("check TPC loop", core_oid);
  res = _mtlk_core_check_tpc_loop_type(core);
  if (res != MTLK_ERR_OK) {goto ERR_END;}

  /* Set before Activating VAP */

  RECOVERY_INFO("Aggregation config", core_oid);
  res = _mtlk_core_recover_aggr_cfg(core);
  if (res != MTLK_ERR_OK) {goto ERR_END;}

  RECOVERY_INFO("Admission Capacity", core_oid);
  res = _mtlk_core_recover_admission_capacity(core);
  if (res != MTLK_ERR_OK) {goto ERR_END;}

  if (mtlk_vap_is_master(core->vap_handle)) {
#ifdef CONFIG_WAVE_DEBUG
    /* HW card abilities are for the first radio */
    if (wave_radio_is_first(radio)) {
      /* Test Bus */
      uint32 db_value = WAVE_RADIO_PDB_GET_INT(radio, PARAM_DB_RADIO_TEST_BUS_MODE);
      if (!MTLK_PARAM_DB_VALUE_IS_INVALID(db_value)) {
      RECOVERY_INFO("Enable Test Bus", core_oid);
        res = wave_core_send_test_bus_mode(core, db_value);
        if (res != MTLK_ERR_OK) {goto ERR_END;}
      }
    }
#endif

    RECOVERY_INFO("Set regulatory domain", core_oid);
    res = _core_send_reg_domain_config(core);
    if (res != MTLK_ERR_OK) {goto ERR_END;}

    RECOVERY_INFO("Enable radar detection", core_oid);
    res = mtlk_core_set_radar_detect(core, WAVE_RADIO_PDB_GET_INT(radio, PARAM_DB_RADIO_DFS_RADAR_DETECTION));
    if (res != MTLK_ERR_OK) {goto ERR_END;}

    RECOVERY_INFO("Set aggr limits", core_oid);
    res = _mtlk_core_recover_agg_rate_limit(core);
    if (res != MTLK_ERR_OK) {goto ERR_END;}

    RECOVERY_INFO("Set Dynamic Multicast rate", core_oid);
    res = _mtlk_core_recover_multicast_rate(core);
    if (res != MTLK_ERR_OK) {goto ERR_END;}

    RECOVERY_INFO("Set mu ofdma bf", core_oid);
    res = _mtlk_core_recover_mu_ofdma_bf(core);
    if (res != MTLK_ERR_OK) {goto ERR_END;}

    RECOVERY_INFO("MAX MPDU length", core_oid);
    res = _mtlk_core_recover_max_mpdu_length(core);
    if (res != MTLK_ERR_OK) {goto ERR_END;}

    RECOVERY_INFO("AMSDU config", core_oid);
    res = _mtlk_core_recover_amsdu_cfg(core);
    if (res != MTLK_ERR_OK) {goto ERR_END;}

    RECOVERY_INFO("MU operation", core_oid);
    res = _mtlk_core_recover_mu_operation(core);
    if (res != MTLK_ERR_OK) {goto ERR_END;}

    RECOVERY_INFO("RTS mode", core_oid);
    res = _mtlk_recover_rts_mode(core);
    if (res != MTLK_ERR_OK) { goto ERR_END; }

    RECOVERY_INFO("11b antsel", core_oid);
    res = _mtlk_core_set_11b_antsel(core);
    if (res != MTLK_ERR_OK) { goto ERR_END; }

    RECOVERY_INFO("BF Mode", core_oid);
    res = _mtlk_recover_bf_mode(core);
    if (res != MTLK_ERR_OK) {goto ERR_END;}

    RECOVERY_INFO("SSB Mode", core_oid);
    res = _mtlk_core_recover_ssb_mode(core);
    if (res != MTLK_ERR_OK) {goto ERR_END;}

    RECOVERY_INFO("QOS PD Threshold", core_oid);
    res = _mtlk_core_rcvry_set_pd_threshold(core);
    if (res != MTLK_ERR_OK) {goto ERR_END;}

    RECOVERY_INFO("Restricted AC Mode", core_oid);
    res = _mtlk_core_rcvry_set_resticted_ac_mode(core);
    if (res != MTLK_ERR_OK) {goto ERR_END;}

    RECOVERY_INFO("Fast Drop", core_oid);
    res = _mtlk_core_recover_fast_drop(core);
    if (res != MTLK_ERR_OK) {goto ERR_END;}

    /* CCA Threshold */
    RECOVERY_INFO("set CCA Threshold", core_oid);
    res = mtlk_core_cfg_recovery_cca_threshold(core);
    if (res != MTLK_ERR_OK) {goto ERR_END;}

    /* adaptive CCA Threshold */
    RECOVERY_INFO("set CCA Adaptive Intervals", core_oid);
    res = mtlk_core_cfg_recovery_cca_adapt(core);
    if (res != MTLK_ERR_OK) { goto ERR_END; }

    /* 2.4 GHz Coexistance */
    RECOVERY_INFO("Set Coexistance configuration", core_oid);
    res = mtlk_core_cfg_recovery_set_coex(core);
    if (res != MTLK_ERR_OK) {goto ERR_END;}

    /* TX Power limit configuration */
    RECOVERY_INFO("set power limits", core_oid);
    res = mtlk_core_send_tx_power_limit_offset(core,
            POWER_TO_DBM(WAVE_RADIO_PDB_GET_INT(radio, PARAM_DB_RADIO_TX_POWER_LIMIT_OFFSET)));
    if (res != MTLK_ERR_OK) {goto ERR_END;}

    /* QAMplus mode configuration */
    RECOVERY_INFO("QAMplus mode", core_oid);
    res = _mtlk_core_recover_qamplus_mode(core);
    if (res != MTLK_ERR_OK) {goto ERR_END;}

    /* Reception Duty Cycle configuration */
    RECOVERY_INFO("set duty cycle", core_oid);
    res = _mtlk_core_recover_rx_duty_cycle(core);
    if (res != MTLK_ERR_OK) {goto ERR_END;}

    /* High Reception Threshold configuration */
    RECOVERY_INFO("set rx_thresold", core_oid);
    res = _mtlk_core_recover_rx_threshold(core);
    if (res != MTLK_ERR_OK) {goto ERR_END;}

    if (((mtlk_core_is_band_supported(core, MTLK_HW_BAND_5_2_GHZ) == MTLK_ERR_OK)) &&
        (_chipid_is_gen6_d2_or_gen7(chip_id)))
    {
      /* set cca preamble puncture override configuration */
      RECOVERY_INFO("set cca preamble puncture override", core_oid);
      res = _mtlk_core_recover_preamble_puncture_override(core);
      if (res != MTLK_ERR_OK) {goto ERR_END;}
    }

    /* Slow Probing Mask */
    RECOVERY_INFO("Slow Probing Mask", core_oid);
    res = _mtlk_core_recover_slow_probing_mask(core);
    if (res != MTLK_ERR_OK) { goto ERR_END; }

    /* TXOP mode */
    RECOVERY_INFO("set TXOP parameters", core_oid);
    res = _mtlk_core_recover_txop_params(core);
    if (res != MTLK_ERR_OK) { goto ERR_END; }

    RECOVERY_INFO("Multicast", core_oid);
    res = _mtlk_core_recovery_reliable_multicast(core);
    if (res != MTLK_ERR_OK) {goto ERR_END;}

    /* Radar Detection Threshold */
    RECOVERY_INFO("set Radar Detection Threshold", core_oid);
    res = mtlk_core_cfg_recovery_radar_rssi_threshold(core);
    if (res != MTLK_ERR_OK) {goto ERR_END;}

    RECOVERY_INFO("set AP retry limit", core_oid);
    res = _wave_core_recover_ap_retry_limit(core);
    if (res != MTLK_ERR_OK) {goto ERR_END;}

    RECOVERY_INFO("set AP Excessive retry limit", core_oid);
    res = _wave_core_recover_ap_exce_retry_limit(core);
    if (res != MTLK_ERR_OK) {goto ERR_END;}

    /* WHM CFG */
    RECOVERY_INFO("set WHM cfg", core_oid);
    res = wave_core_recover_whm(core);
    if (res != MTLK_ERR_OK) {goto ERR_END;}

    /* MAC Fatal occurred during scan, but before VAP was activated (NET_STATE_READY) */
    if (RCVRY_FG_SCAN == wave_rcvry_scan_type_current_get(hw, vap_manager) &&
        (target_net_state & NET_STATE_READY)) {
      RECOVERY_INFO("Resuming foreground scan", core_oid);
      res = mtlk_scan_recovery_continue_scan(core, MTLK_SCAN_SUPPORT_NO_BG_SCAN);
      if (res != MTLK_ERR_OK) {goto ERR_END;}
    }

    RECOVERY_INFO("RTS protection cutoff point", core_oid);
    res = wave_core_cfg_recover_cutoff_point(core);
    if (res != MTLK_ERR_OK) {goto ERR_END;}

    RECOVERY_INFO("set RTS Threshold", core_oid);
    res = wave_core_cfg_recover_rts_threshold(core);
    if (res != MTLK_ERR_OK) {goto ERR_END;}

    RECOVERY_INFO("set Mgmt Frame Power Control", core_oid);
    res = wave_core_cfg_recover_mgmt_frame_pwr_ctrl(core);
    if (res != MTLK_ERR_OK) {goto ERR_END;}

    /* Dynamic MU CFG */
    RECOVERY_INFO("set Dynamic MU parameters", core_oid);
    res = wave_core_recover_dynamic_mu_type (core);
    if (res != MTLK_ERR_OK) { goto ERR_END; }

    RECOVERY_INFO("set MU Groups configuration", core_oid);
    res = wave_core_recover_mu_group_params(core);
    if (res != MTLK_ERR_OK) { goto ERR_END; }

    RECOVERY_INFO("set Dynamic WMM", core_oid);
    res = _wave_core_recover_dynamic_wmm(core);
    if (res != MTLK_ERR_OK) { goto ERR_END; }

    RECOVERY_INFO("set Dynamic EDCA", core_oid);
    res = _wave_core_recover_dynamic_edca(core);
    if (res != MTLK_ERR_OK) { goto ERR_END; }
  }

  /* VAP was not previously activated, nothing to configure */
  if (!(target_net_state & (NET_STATE_ACTIVATING | NET_STATE_CONNECTED))) {
    goto ERR_OK;
  }

  if (wdev)
    cac_started = wdev->cac_started;

  RECOVERY_INFO("vap activate", core_oid);
  band = wave_radio_band_get(radio);

  if (!is_channel_certain(current_chandef) &&
      RCVRY_FG_SCAN == wave_rcvry_scan_type_current_get(hw, vap_manager)) {
    band = ss->req.channels[0].band; /* Band wasn't set yet, so get from original scan request */
  }

  res = mtlk_mbss_send_vap_activate(core, band);
  if (res != MTLK_ERR_OK) {goto ERR_END;}
  /* net state is ACTIVATING */

  RECOVERY_INFO("stadb start", core_oid);
  mtlk_stadb_start(&core->slow_ctx->stadb);
  if (res != MTLK_ERR_OK) {goto ERR_END;}

  RECOVERY_INFO("restore security", core_oid);
  res = core_on_rcvry_security(core);
  if (res != MTLK_ERR_OK) {goto ERR_END;}

  if (mtlk_vap_is_master(core->vap_handle)) {
    /* WDS */
    if (BR_MODE_WDS == MTLK_CORE_HOT_PATH_PDB_GET_INT(core, CORE_DB_CORE_BRIDGE_MODE)) {
      RECOVERY_INFO("restore WDS", core_oid);
      wds_on_if_up(&core->slow_ctx->wds_mng);
    }

    /* Continue foreground scan */
    if (RCVRY_FG_SCAN == wave_rcvry_scan_type_current_get(hw, vap_manager)) {
      RECOVERY_INFO("Resuming foreground scan", core_oid);
      res = mtlk_scan_recovery_continue_scan(core, MTLK_SCAN_SUPPORT_NO_BG_SCAN);
      if (res != MTLK_ERR_OK) { goto ERR_END; }
    }
  }

  /* Continue only if NET_STATE_CONNECTED */
  if (!(target_net_state & NET_STATE_CONNECTED)) {
    if (!mtlk_vap_is_master(core->vap_handle))
      goto ERR_OK;

    if (cac_started) {
      RECOVERY_INFO("set channel", core_oid);
      res = mtlk_core_rcvry_set_channel(core, cac_started);
      if (res != MTLK_ERR_OK) {goto ERR_END;}
      goto continue_cac;
    }
#ifdef ONEWIFI_IWLWAV_DEV
    /* On the OneWifi image master vap is never in the state NET_STATE_CONNECTED, but it can be
      in NET_STATE_ACTIVATING. So, if state is NET_STATE_ACTIVATING, just continue the execution flow
    */
    if (!(target_net_state & NET_STATE_ACTIVATING))
      goto ERR_OK;
#else
    goto ERR_OK;
#endif
  }

  if (mtlk_vap_is_master(core->vap_handle)) {
    RECOVERY_INFO("set channel", core_oid);
    res = mtlk_core_rcvry_set_channel(core, cac_started);
    if (res != MTLK_ERR_OK) {goto ERR_END;}
  }

  if (mtlk_vap_is_ap(core->vap_handle)) {
    /* Master VAP is used as a dummy VAP (in order to support reconf
     * of all VAPs without having to restart hostapd) we avoid setting beacon
     * so that the dummy VAPs will not send beacons */
    if (mtlk_vap_is_master(core->vap_handle)){
      RECOVERY_INFO("Dummy Master VAP, not setting beacon template in FW",
                    core_oid);
    } else if (!cac_started) {
      RECOVERY_INFO("set beacon template", core_oid);
      res = wave_beacon_man_rcvry_beacon_set(core);
      if (res != MTLK_ERR_OK) {goto ERR_END;}
    }
    RECOVERY_INFO("set unsolicited frame template", core_oid);
    res = _wave_recovery_unsolicited_frame_template_push(core);
  }

  if (!cac_started) {
    RECOVERY_INFO("set bss", core_oid);
    res = wave_core_recovery_cfg_change_bss(core);
    if (res != MTLK_ERR_OK) {goto ERR_END;}

    /* net state is CONNECTED */

    RECOVERY_INFO("set wmm", core_oid);
    /*Set after state CONNECTED */
    res = core_recovery_cfg_wmm_param_set(core);
    if (res != MTLK_ERR_OK) {goto ERR_END;}
  }

  if (mtlk_vap_is_ap(core->vap_handle)) {
    /* Master VAP is used as a dummy VAP (in order to support reconf
     * of all VAPs without having to restart hostapd) we avoid setting beacon
     * so that the dummy VAPs will not send beacons */
    if (mtlk_vap_is_master(core->vap_handle)) {
      RECOVERY_INFO("Dummy Master VAP, not setting beacon info in FW",
                    core_oid);
    } else {
      RECOVERY_INFO("set beacon info", core_oid);
      res = core_recovery_cfg_set_ap_beacon_info(core);
      if (res != MTLK_ERR_OK) {goto ERR_END;}
    }
    RECOVERY_INFO("set Broadcast TWT configuration", core_oid);
    res = _wave_beacon_recovery_btwt_config(core);
    if (res != MTLK_ERR_OK)
      RECOVERY_INFO("Set Broadcast TWT configuration FAILED!", core_oid);
  }

continue_cac:
  if (mtlk_vap_is_master(core->vap_handle)) {
    RECOVERY_INFO("Enable radio", core_oid);
    res = mtlk_core_set_radio_mode_req(core, WAVE_RADIO_PDB_GET_INT(radio, PARAM_DB_RADIO_MODE_REQUESTED));
    if (res != MTLK_ERR_OK) {goto ERR_END;}

    /* CoC configuration */
    RECOVERY_INFO("COC start", core_oid);
    res = mtlk_coc_on_rcvry_configure(coc_mgmt);
    if (res != MTLK_ERR_OK) {goto ERR_END;}

    /* ERP configuration */
    RECOVERY_INFO("ERP start", core_oid);
    res = mtlk_erp_on_rcvry_configure(erp_mgmt);
    if (res != MTLK_ERR_OK) {goto ERR_END;}

    active_ant_mask = WAVE_RADIO_PDB_GET_INT(radio, PARAM_DB_RADIO_ACTIVE_ANT_MASK);
    if (active_ant_mask) {
      RECOVERY_INFO("Active ant mask", core_oid);
      res = mtlk_core_cfg_send_active_ant_mask(core, active_ant_mask);
      if (res != MTLK_ERR_OK) {goto ERR_END;}
    }

    RECOVERY_INFO("Interference detection", core_oid);
    res = _mtlk_core_recover_interfdet_threshold(core);
    if (res != MTLK_ERR_OK) {goto ERR_END;}

    if (cac_started && (MTLK_HW_BAND_5_2_GHZ == core_cfg_get_freq_band_cur(core))){
      struct ieee80211_hw *hw;
      RECOVERY_INFO("restart CAC-procedure", core_oid);
      hw = wave_vap_ieee80211_hw_get(core->vap_handle);
      if (__LIKELY(hw != NULL)) {
        wave_disable_rcvry_finish_wait(core);
        ieee80211_dfs_cac_restart(hw);
        wave_enable_rcvry_finish_wait(core);
      } else {
        res = MTLK_ERR_HW;
        goto ERR_END;
      }
    }

    if (mtlk_vap_manager_did_ap_started(vap_manager)){
      RECOVERY_INFO("Sync HOSTAPD STA database", core_oid);
      wave_core_sync_hostapd_done_set(core, FALSE);
      ILOG0_D("CID-%04x: Recovery: Set HOSTAPD STA database synced to FALSE", core_oid);
      res = wv_cfg80211_handle_flush_stations(core->vap_handle, NULL, 0);
      if (res != MTLK_ERR_OK) {goto ERR_END;}
      mtlk_osal_timer_set(&core->slow_ctx->sync_hostapd_timer, WAVE_SYNC_HOSTAPD_TIMER);
    }
  }

  /* If FW crashed e.g. during SET_CHAN procedure, recovery could end up
   * with misaligned channel, beacons, etc. Notify hostapd to make sure
   * we have aligned beacons to the recovered channel */
  if (mtlk_vap_manager_did_ap_started(vap_manager) &&
      (is_channel_certain(current_chandef) && !cac_started) &&
      !(mtlk_vap_is_sta(core->vap_handle))) {
        _mtlk_core_rcvry_chan_switch_notify(core);
  }

  /* If FW crashed during Color switch procedure, recovery could end up
   * with misaligned color switch state. Complete CCA notification.
   */
  if (core->color_change_active) {
    if (mtlk_vap_is_ap(core->vap_handle)) {
      if (mtlk_vap_is_master(core->vap_handle))
        _mtlk_process_hw_task(core, SERIALIZABLE, wave_core_handle_color_change_event,
                              HANDLE_T(core), NULL, 0);
    } else {
     _mtlk_process_hw_task(core, SERIALIZABLE, wave_core_handle_color_change_event,
                           HANDLE_T(core), NULL, 0);
    }
  }

ERR_OK:
  return res;

ERR_END:
  ELOG_DD("CID-%04x: Recovery configuration fail. res=%d", core_oid, res);
  return res;
}

/* Restore CORE's and its sub modules configuration.
 * This function is intended for recovery configurable
 * parameters only. Non configurable parameters and
 * variables must be set in RESTORE function.
 */
int __MTLK_IFUNC
core_on_rcvry_configure (mtlk_core_t *core, uint32 was_connected)
{
  int res;
  uint16 oid = mtlk_vap_get_oid(core->vap_handle);

  MTLK_UNREFERENCED_PARAM(oid);

  ILOG1_DDS("CID-%04x: Net State before Recovery = %d (%s)", oid, was_connected,
            mtlk_net_state_to_string(was_connected));

  res = _core_on_rcvry_configure(core, was_connected);
  if (res != MTLK_ERR_OK) {
    ELOG_D("CID-%04x: Recovery configuration failed", oid);
  }
  return res;
}

void __MTLK_IFUNC
core_schedule_recovery_task (mtlk_vap_handle_t vap_handle, mtlk_core_task_func_t task,
            mtlk_handle_t rcvry_handle, const void* data, uint32 data_size)
{
    /* Just wrapper to put recovery task to the serializer */
    mtlk_core_t *core = mtlk_vap_get_core(vap_handle);

    _mtlk_process_emergency_task(core, task, rcvry_handle, data, data_size);

    return;
}

void __MTLK_IFUNC
mtlk_core_store_calibration_channel_bit_map (mtlk_core_t *core, uint32 *storedCalibrationChannelBitMap)
{
  wave_memcpy(core->storedCalibrationChannelBitMap,
         sizeof(core->storedCalibrationChannelBitMap),
         storedCalibrationChannelBitMap,
         sizeof(core->storedCalibrationChannelBitMap));
}

static int _wave_core_sync_done (mtlk_handle_t hcore, const void* data, uint32 data_size)
{
  mtlk_core_t *core = HANDLE_T_PTR(mtlk_core_t, hcore);
  mtlk_clpb_t *clpb = *(mtlk_clpb_t **) data;
  mtlk_core_t *mcore;

  MTLK_ASSERT(sizeof(mtlk_clpb_t*) == data_size);

  mcore = mtlk_core_get_master(core->vap_handle);
  MTLK_ASSERT(mcore);

  mtlk_osal_timer_cancel_sync(&mcore->slow_ctx->sync_hostapd_timer);
  wave_core_sync_hostapd_done_set(mcore, TRUE);
  ILOG0_D("CID-%04x: Recovery: Set HOSTAPD STA database synced to TRUE", mtlk_vap_get_oid(mcore->vap_handle));
  return mtlk_clpb_push_res(clpb, MTLK_ERR_OK);
}

uint16 __MTLK_IFUNC
mtlk_core_get_sid_by_addr(mtlk_core_t *nic, uint8 *addr)
{
  uint16 sid = DB_UNKNOWN_SID;
  sta_entry *sta = NULL;

  if (mtlk_osal_eth_is_multicast(addr)) { /* Broadcast is a kind of multicast too */
    sid = wave_core_get_all_sta_sid(nic);
  } else {
    sta = mtlk_stadb_find_sta(&nic->slow_ctx->stadb, addr);
    if (sta) {
      sid = mtlk_sta_get_sid(sta);
    } else {
      sta = mtlk_hstdb_find_sta(&nic->slow_ctx->hstdb, addr);
      if (sta) sid = mtlk_sta_get_sid(sta);
    }
  }
  if (sta) mtlk_sta_decref(sta);

  ILOG3_DY("SID is=:%d STA:%Y", sid, addr);
  return sid;
}

#if MTLK_USE_DIRECTCONNECT_DP_API

/* Get station ID callback */
int mtlk_core_dp_get_subif_cb (mtlk_df_user_t *df_user, char *mac_addr, uint32_t *subif, int32_t port_id) {
  uint16    sta_id = 0;
  sta_entry   *sta = NULL;
  mtlk_vap_handle_t vap_handle = mtlk_df_get_vap_handle(mtlk_df_user_get_df(df_user));
  mtlk_core_t *nic = mtlk_vap_get_core(vap_handle);
  struct dc_dp_subif subif_id;

  MTLK_ASSERT(NULL != nic);
  MTLK_ASSERT(NULL != nic->slow_ctx);

  *subif = 0;
  memset(&subif_id, 0, sizeof(subif_id));
  subif_id.vap_id = wave_df_user_get_dcdp_vap_id(df_user);
  subif_id.port_id = port_id;

  if (mac_addr) {
    if (mtlk_df_user_is_secondary(df_user)) {
      sta = mtlk_df_user_get_backhaul_sta(df_user);
      if (sta) sta_id = mtlk_sta_get_sid(sta);
      else {
        ILOG2_D("CID-%04x: backhaul/ext-hyb AP, cannot return STA_ID", mtlk_vap_get_oid(vap_handle));
        return MTLK_ERR_UNKNOWN;
      }
      ILOG2_DD("CID-%04x: backhaul/ext-hyb AP, returned IRE STA_ID = %u", mtlk_vap_get_oid(vap_handle), sta_id);
    } else if (MULTI_AP_BACKHAUL == MTLK_CORE_HOT_PATH_PDB_GET_INT(nic, CORE_DB_CORE_MULTI_AP_MODE)) {
      sta = mtlk_stadb_find_sta(&nic->slow_ctx->stadb, mac_addr);
      if (sta) sta_id = mtlk_sta_get_sid(sta);
      else {
        sta = mtlk_df_user_get_backhaul_sta(df_user);
        if (sta) sta_id = mtlk_sta_get_sid(sta);
        else {
          ILOG2_D("CID-%04x: backhaul AP, cannot return STA_ID", mtlk_vap_get_oid(vap_handle));
          return MTLK_ERR_UNKNOWN;
        }
      }
      ILOG2_DD("CID-%04x: backhaul AP, returned IRE STA_ID = %u", mtlk_vap_get_oid(vap_handle), sta_id);
    } else {
      /* Normal processing */
      sta = mtlk_stadb_find_sta(&nic->slow_ctx->stadb, mac_addr);
      if (sta) {
        sta_id = mtlk_sta_get_sid(sta);
      } else {
        /* try searching in hostdb */
        sta = mtlk_hstdb_find_sta(&nic->slow_ctx->hstdb, mac_addr);
        if (sta) sta_id = mtlk_sta_get_sid(sta);
        else {
          ILOG2_DY("CID-%04x: Cannot find STA_ID for MAC %Y", mtlk_vap_get_oid(vap_handle), mac_addr);
          return MTLK_ERR_UNKNOWN;
        }
      }
      ILOG2_DYD("CID-%04x: Requested MAC = %Y, returned STA_ID = %u", mtlk_vap_get_oid(vap_handle), mac_addr, sta_id);
    }
    subif_id.sta_id = sta_id;
    mtlk_sta_decref(sta); /* De-reference of find or get_last */
  }
  /* API to set subif params in DCDP */
  dc_dp_set_subif_param(&subif_id);
  *subif = subif_id.subif;

  return MTLK_ERR_OK;
}
#endif

BOOL __MTLK_IFUNC
mtlk_core_mcast_module_is_available (mtlk_core_t* nic)
{
  return mtlk_df_ui_mcast_is_registered(mtlk_vap_get_df(nic->vap_handle));
}

uint32 __MTLK_IFUNC
mtlk_core_mcast_handle_grid (mtlk_core_t* nic, mtlk_mc_addr_t *mc_addr, mc_grid_action_t action, int grp_id)
{
  mtlk_core_ui_mc_grid_action_t req;

  req.mc_addr = *mc_addr;
  req.action = action;
  req.grp_id = grp_id;

  if (MTLK_ERR_OK == mtlk_hw_set_prop(mtlk_vap_get_hwapi(nic->vap_handle), MTLK_HW_MC_GROUP_ID, &req, sizeof(req))) {
    if ((MCAST_GROUP_UNDEF == req.grp_id) && (MTLK_GRID_ADD == action)) {
      ELOG_D("CID-%04x: No free group ID", mtlk_vap_get_oid(nic->vap_handle));
    }
  }
  return req.grp_id;
}

void __MTLK_IFUNC
mtlk_core_mcast_group_id_action_serialized (mtlk_core_t* nic, mc_action_t action, int grp_id, uint8 *mac_addr, mtlk_mc_addr_t *mc_addr)
{
  mtlk_core_ui_mc_action_t req;

  if (MCAST_GROUP_UNDEF == grp_id) {
    ILOG1_V("Group ID is not defined yet");
    return;
  }

  req.action = action;
  req.grp_id = grp_id;
  ieee_addr_set(&req.sta_mac_addr, mac_addr);
  req.mc_addr = *mc_addr;
  _mtlk_process_hw_task(nic, SERIALIZABLE, _mtlk_core_mcast_group_id_action, HANDLE_T(nic), &req, sizeof(mtlk_core_ui_mc_action_t));
}

void
mtlk_core_on_bss_drop_tx_que_full(mtlk_core_t *core)
{
    MTLK_ASSERT(core);
    mtlk_core_inc_cnt(core, MTLK_CORE_CNT_BSS_MGMT_TX_QUE_FULL);
}

/* QAMplus configuration */

static void _core_store_qamplus_mode (wave_radio_t *radio, const uint32 qamplus_mode)
{
  MTLK_ASSERT(radio != NULL);
  WAVE_RADIO_PDB_SET_INT(radio, PARAM_DB_RADIO_QAMPLUS_MODE, qamplus_mode);
}

static int _mtlk_core_set_qamplus_mode (mtlk_handle_t hcore, const void* data, uint32 data_size)
{
  int res = MTLK_ERR_OK;
  mtlk_core_t *core = mtlk_core_get_master(((mtlk_core_t*)hcore)->vap_handle);
  wave_radio_t *radio = wave_vap_radio_get(core->vap_handle);
  mtlk_qamplus_mode_cfg_t *qamplus_mode_cfg = NULL;
  uint32 qamplus_mode_cfg_size;
  mtlk_clpb_t *clpb = *(mtlk_clpb_t **)data;

  MTLK_ASSERT(sizeof(mtlk_clpb_t*) == data_size);

  /* get configuration */
  qamplus_mode_cfg = mtlk_clpb_enum_get_next(clpb, &qamplus_mode_cfg_size);
  MTLK_CLPB_TRY(qamplus_mode_cfg, qamplus_mode_cfg_size)
    MTLK_CFG_START_CHEK_ITEM_AND_CALL()
      /* send new config to FW */
      MTLK_CFG_CHECK_ITEM_AND_CALL(qamplus_mode_cfg, qamplus_mode, mtlk_core_qamplus_mode_req,
                                   (core, qamplus_mode_cfg->qamplus_mode), res);
      /* store new config in internal db*/
      MTLK_CFG_CHECK_ITEM_AND_CALL_VOID(qamplus_mode_cfg, qamplus_mode, _core_store_qamplus_mode,
                                        (radio, qamplus_mode_cfg->qamplus_mode));
    MTLK_CFG_END_CHEK_ITEM_AND_CALL()
  MTLK_CLPB_FINALLY(res)
    /* push result into clipboard */
    return mtlk_clpb_push_res(clpb, res);
  MTLK_CLPB_END
}

static int _mtlk_core_get_qamplus_mode (mtlk_handle_t hcore, const void* data, uint32 data_size)
{
  int res = MTLK_ERR_OK;
  mtlk_qamplus_mode_cfg_t qamplus_mode_cfg;
  mtlk_core_t *master_core = mtlk_core_get_master(((mtlk_core_t*)hcore)->vap_handle);
  mtlk_clpb_t *clpb = *(mtlk_clpb_t **)data;

  MTLK_ASSERT(sizeof(mtlk_clpb_t*) == data_size);

  MTLK_CFG_SET_ITEM_BY_FUNC(&qamplus_mode_cfg, qamplus_mode, mtlk_core_receive_qamplus_mode,
                            (master_core, &qamplus_mode_cfg.qamplus_mode), res);

  /* push result and config to clipboard*/
  res = mtlk_clpb_push(clpb, &res, sizeof(res));
  if (MTLK_ERR_OK == res) {
    res = mtlk_clpb_push(clpb, &qamplus_mode_cfg, sizeof(qamplus_mode_cfg));
  }

  return res;
}

/* Radio configuration */
static int _mtlk_core_get_radio_mode(mtlk_handle_t hcore, const void* data, uint32 data_size)
{
  int res = MTLK_ERR_OK;
  mtlk_radio_mode_cfg_t radio_mode_cfg;
  mtlk_core_t *master_core = mtlk_core_get_master(((mtlk_core_t*)hcore)->vap_handle);
  wave_radio_t *radio = wave_vap_radio_get(master_core->vap_handle);
  mtlk_clpb_t *clpb = *(mtlk_clpb_t **)data;

  MTLK_ASSERT(sizeof(mtlk_clpb_t*) == data_size);

  /* read config from internal db */
  MTLK_CFG_SET_ITEM(&radio_mode_cfg, radio_mode, wave_radio_mode_get(radio))

  /* push result and config to clipboard*/
  res = mtlk_clpb_push(clpb, &res, sizeof(res));
  if (MTLK_ERR_OK == res) {
    res = mtlk_clpb_push(clpb, &radio_mode_cfg, sizeof(radio_mode_cfg));
  }

  return res;
}

static int _mtlk_core_set_radio_mode (mtlk_handle_t hcore, const void* data, uint32 data_size)
{
  int res = MTLK_ERR_OK;
  mtlk_core_t *core = mtlk_core_get_master(((mtlk_core_t*)hcore)->vap_handle);
  wave_radio_t *radio = wave_vap_radio_get(core->vap_handle);
  mtlk_radio_mode_cfg_t *radio_mode_cfg = NULL;
  uint32 radio_mode_cfg_size;
  mtlk_clpb_t *clpb = *(mtlk_clpb_t **)data;

  MTLK_ASSERT(sizeof(mtlk_clpb_t*) == data_size);

  /* get configuration */
  radio_mode_cfg = mtlk_clpb_enum_get_next(clpb, &radio_mode_cfg_size);
  MTLK_CLPB_TRY(radio_mode_cfg, radio_mode_cfg_size)
    MTLK_CFG_START_CHEK_ITEM_AND_CALL()
      /* send new config to FW if it is ready, if not, send it later after set bss */
      MTLK_CFG_CHECK_ITEM_AND_CALL(radio_mode_cfg, radio_mode, _mtlk_core_check_and_set_radio_mode,
                                   (core, radio_mode_cfg->radio_mode), res);
      /* store new config in internal db*/
      MTLK_CFG_CHECK_ITEM_AND_CALL_VOID(radio_mode_cfg, radio_mode, wave_radio_mode_set,
                                        (radio, radio_mode_cfg->radio_mode));
    MTLK_CFG_END_CHEK_ITEM_AND_CALL()
  MTLK_CLPB_FINALLY(res)
    /* push result into clipboard */
    return mtlk_clpb_push_res(clpb, res);
  MTLK_CLPB_END
}

/* AMSDU NUM configuration */
static __INLINE void
__core_store_amsdu_num (mtlk_core_t *core,
  const uint32 htMsduInAmsdu, const uint32 vhtMsduInAmsdu,
  const uint32 heMsduInAmsdu, const uint32 ehtMsduInAmsdu)
{
  wave_radio_t *radio = wave_vap_radio_get(core->vap_handle);
  MTLK_ASSERT(radio != NULL);

  WAVE_RADIO_PDB_SET_INT(radio, PARAM_DB_RADIO_AMSDU_NUM, htMsduInAmsdu);
  WAVE_RADIO_PDB_SET_INT(radio, PARAM_DB_RADIO_AMSDU_VNUM, vhtMsduInAmsdu);
  WAVE_RADIO_PDB_SET_INT(radio, PARAM_DB_RADIO_AMSDU_HENUM, heMsduInAmsdu);
#ifdef MTLK_WAVE_700
  WAVE_RADIO_PDB_SET_INT(radio, PARAM_DB_RADIO_AMSDU_EHTNUM, ehtMsduInAmsdu);
#endif
}

static int
_mtlk_core_check_and_set_amsdu_num (mtlk_core_t *core, uint32 htMsduInAmsdu,
                                    uint32 vhtMsduInAmsdu, uint32 heMsduInAmsdu, uint32 ehtMsduInAmsdu)
{
  if (htMsduInAmsdu > HT_MSDU_IN_AMSDU_MAX || htMsduInAmsdu < HT_MSDU_IN_AMSDU_MIN) {
    ELOG_D("Invalid htMsduInAmsdu: %u", htMsduInAmsdu);
    return MTLK_ERR_PARAMS;
  }

  if (vhtMsduInAmsdu > VHT_MSDU_IN_AMSDU_MAX || vhtMsduInAmsdu < VHT_MSDU_IN_AMSDU_MIN) {
    ELOG_D("Invalid vhtMsduInAmsdu: %u", vhtMsduInAmsdu);
    return MTLK_ERR_PARAMS;
  }

  if (heMsduInAmsdu > HE_MSDU_IN_AMSDU_MAX || heMsduInAmsdu < HE_MSDU_IN_AMSDU_MIN) {
    ELOG_D("Invalid heMsduInAmsdu: %u", heMsduInAmsdu);
    return MTLK_ERR_PARAMS;
  }
#ifdef MTLK_WAVE_700
  if (ehtMsduInAmsdu > EHT_MSDU_IN_AMSDU_MAX || ehtMsduInAmsdu < EHT_MSDU_IN_AMSDU_MIN) {
    ELOG_D("Invalid ehtMsduInAmsdu: %u", ehtMsduInAmsdu);
    return MTLK_ERR_PARAMS;
  }
#endif
  return mtlk_core_set_amsdu_num_req(core, htMsduInAmsdu, vhtMsduInAmsdu, heMsduInAmsdu, ehtMsduInAmsdu);
}

static int _mtlk_core_set_amsdu_num (mtlk_handle_t hcore, const void* data, uint32 data_size)
{
  int                    res = MTLK_ERR_OK;
  mtlk_core_t            *core = mtlk_core_get_master(((mtlk_core_t*)hcore)->vap_handle);
  mtlk_amsdu_num_cfg_t   *amsdu_num_cfg = NULL;
  uint32                 amsdu_num_cfg_size;
  mtlk_clpb_t            *clpb = *(mtlk_clpb_t **)data;

  MTLK_ASSERT(sizeof(mtlk_clpb_t*) == data_size);

  /* get configuration */
  amsdu_num_cfg = mtlk_clpb_enum_get_next(clpb, &amsdu_num_cfg_size);
  MTLK_CLPB_TRY(amsdu_num_cfg, amsdu_num_cfg_size)
    MTLK_CFG_START_CHEK_ITEM_AND_CALL()
      /* send new config to FW */
      MTLK_CFG_CHECK_ITEM_AND_CALL(amsdu_num_cfg, amsdu_num, _mtlk_core_check_and_set_amsdu_num,
                                   (core, amsdu_num_cfg->amsdu_num, amsdu_num_cfg->amsdu_vnum,
                                    amsdu_num_cfg->amsdu_henum, amsdu_num_cfg->amsdu_ehtnum), res);
      /* store new config in internal db*/
      MTLK_CFG_CHECK_ITEM_AND_CALL_VOID(amsdu_num_cfg, amsdu_num, __core_store_amsdu_num,
                                        (core, amsdu_num_cfg->amsdu_num, amsdu_num_cfg->amsdu_vnum,
                                         amsdu_num_cfg->amsdu_henum, amsdu_num_cfg->amsdu_ehtnum));
    MTLK_CFG_END_CHEK_ITEM_AND_CALL()
  MTLK_CLPB_FINALLY(res)
    /* push result into clipboard */
    return mtlk_clpb_push_res(clpb, res);
  MTLK_CLPB_END
}

static int
_mtlk_core_get_vap_measurements (mtlk_handle_t hcore, const void *data, uint32 data_size)
{
  mtlk_core_t *core = HANDLE_T_PTR(mtlk_core_t, hcore);
  mtlk_clpb_t *clpb = *(mtlk_clpb_t **) data;
  struct driver_vap_info vap_info;

  _mtlk_core_get_vap_info_stats(core, &vap_info);
  return mtlk_clpb_push_res_data(clpb, MTLK_ERR_OK, &vap_info,
    sizeof(vap_info));
}

/* Radio has to be ON for set channel, calibrate request, CoC and temperature */
mtlk_error_t __MTLK_IFUNC mtlk_core_radio_enable_if_needed (mtlk_core_t *core)
{
  mtlk_error_t res = MTLK_ERR_OK;
  mtlk_core_t* master_core = mtlk_core_get_master(core->vap_handle);
  wave_radio_t *radio = wave_vap_radio_get(master_core->vap_handle);

  if (WAVE_RADIO_OFF == WAVE_RADIO_PDB_GET_INT(radio, PARAM_DB_RADIO_MODE_CURRENT)) {
    res = mtlk_core_set_radio_mode_req(master_core, WAVE_RADIO_ON);

    if (MTLK_ERR_OK != res) {
      ELOG_V("Failed to enable radio");
    }
  }

  return res;
}

mtlk_error_t __MTLK_IFUNC mtlk_core_radio_disable_if_needed (mtlk_core_t *core)
{
  mtlk_error_t res = MTLK_ERR_OK;
  mtlk_core_t *master_core = mtlk_core_get_master(core->vap_handle);
  wave_radio_t *radio = wave_vap_radio_get(master_core->vap_handle);

  if (mtlk_core_is_block_tx_mode(master_core)) {
    ILOG2_V("Waiting for beacons");
    return MTLK_ERR_OK;
  }

  /* will be disabled after scan */
  if (mtlk_core_scan_is_running(master_core) ||
      mtlk_core_is_in_scan_mode(master_core)) {
    ILOG2_V("Is in scan mode");
    return MTLK_ERR_OK;
  }

  if (ST_RSSI == __wave_core_chan_switch_type_get(core)) {
    ILOG2_V("Is in ST_RSSI channel switch mode");
    return MTLK_ERR_OK;
  }

  if ((WAVE_RADIO_ON  == WAVE_RADIO_PDB_GET_INT(radio, PARAM_DB_RADIO_MODE_CURRENT)) &&
      (WAVE_RADIO_OFF == WAVE_RADIO_PDB_GET_INT(radio, PARAM_DB_RADIO_MODE_REQUESTED))) {
    res = mtlk_core_set_radio_mode_req(master_core, WAVE_RADIO_OFF);

    if (MTLK_ERR_OK != res) {
      ELOG_V("Failed to disable radio");
    }
  }

  return res;
}

static int
_mtlk_core_get_radio_info (mtlk_handle_t hcore, const void *data, uint32 data_size)
{
  mtlk_core_t   *core = mtlk_core_get_master(((mtlk_core_t*)hcore)->vap_handle);
  wave_radio_t  *radio = wave_vap_radio_get(core->vap_handle);
  mtlk_clpb_t   *clpb = *(mtlk_clpb_t **) data;
  int res = MTLK_ERR_OK;
  struct driver_radio_info radio_info;
  mtlk_tx_power_data_t tx_pw_data;
  mtlk_coc_antenna_cfg_t *current_params;
  mtlk_coc_t *coc_mgmt = __wave_core_coc_mgmt_get(core);
  struct mtlk_chan_def cd;

  memset(&radio_info, 0, sizeof(radio_info));
#if defined(CPTCFG_IWLWAV_TSF_TIMER_ACCESS_ENABLED)
  radio_info.tsf_start_time = mtlk_hw_get_timestamp(core->vap_handle);
#endif
  _mtlk_core_get_tr181_hw(core, &radio_info.tr181_hw);
  wave_radio_get_tr181_hw_stats(radio, &radio_info.tr181_hw_stats);

  radio_info.load = wave_radio_channel_load_get(radio);

  mtlk_core_get_tx_power_data(core, &tx_pw_data);
  radio_info.tx_pwr_cfg = POWER_TO_MBM(tx_pw_data.pw_targets[tx_pw_data.cur_cbw]);

  current_params = mtlk_coc_get_current_params(coc_mgmt);
  radio_info.num_tx_antennas = current_params->num_tx_antennas;
  radio_info.num_rx_antennas = current_params->num_rx_antennas;

  /* Note: this info could have been changing while we copied it and
   * we won't necessarily catch it with the is_channel_certain() trick.
   */
  cd = *__wave_core_chandef_get(core);

  if (is_channel_certain(&cd)) {
    radio_info.primary_center_freq = cd.chan.center_freq;
    radio_info.center_freq1 = cd.center_freq1;
    radio_info.center_freq2 = cd.center_freq2;
    radio_info.width = MHZS_PER_20MHZ << cd.width;
  }

  return mtlk_clpb_push_res_data(clpb, res, &radio_info,
    sizeof(radio_info));
}

void fill_channel_data (mtlk_core_t *core, struct intel_vendor_channel_data *ch_data)
{
  mtlk_core_t* master_core = mtlk_core_get_master(core->vap_handle);
  const struct mtlk_chan_def *cd = __wave_core_chandef_get(master_core);
  uint8 sec_offset;
  wave_radio_t *radio = wave_vap_radio_get(core->vap_handle);
  mtlk_hw_band_e band = wave_radio_band_get(radio);
  uint32 cf = cd->center_freq1;

  memset(ch_data, 0, sizeof(*ch_data));
  ch_data->channel = WAVE_RADIO_PDB_GET_INT(radio, PARAM_DB_RADIO_CHANNEL_CUR);

  switch (WAVE_RADIO_PDB_GET_INT(radio, PARAM_DB_RADIO_SPECTRUM_MODE)) {
  case CW_20: ch_data->BW = 20; break;
  case CW_40: ch_data->BW = 40; break;
  case CW_80: ch_data->BW = 80; break;
  case CW_160:ch_data->BW = 160; break;
  case CW_80_80: ch_data->BW = -160; break;
#ifdef MTLK_WAVE_700
  case CW_320:
      if (wave_radio_is_320mhz_supported(radio))
        ch_data->BW = 320;
      else
        MTLK_ASSERT(0);
      break;
#endif
  default: MTLK_ASSERT(0);
  }
  ch_data->primary = ch_data->channel;

  switch (WAVE_RADIO_PDB_GET_INT(radio, PARAM_DB_RADIO_BONDING_MODE)) {
  case ALTERNATE_UPPER: sec_offset = UMI_CHANNEL_SW_MODE_SCA; break;
  case ALTERNATE_LOWER: sec_offset = UMI_CHANNEL_SW_MODE_SCB; break;
  case ALTERNATE_NONE:  sec_offset = UMI_CHANNEL_SW_MODE_SCN; break;
  default: sec_offset = UMI_CHANNEL_SW_MODE_SCN; break;
  }

  ch_data->secondary = mtlk_channels_get_secondary_channel_no_by_offset(ch_data->primary, sec_offset);
#ifdef MTLK_WAVE_700
  if ((band == MTLK_HW_BAND_6_GHZ) && ((cd->width == CW_160) || cd->width == CW_320))
#else
  if ((band == MTLK_HW_BAND_6_GHZ) && (cd->width == CW_160))
#endif
    cf = cd->center_freq2;
  ch_data->freq = channel_to_frequency(freq2lowchannum(cf, cd->width), band);

  scan_get_aocs_info(core, ch_data);

  ch_data->total_time = 255;
  ch_data->filled_mask |= CHDATA_TOTAL_TIME;
}

static void
_mtlk_core_get_traffic_wlan_stats (mtlk_core_t* core, mtlk_wssa_drv_traffic_stats_t* stats)
{
  mtlk_mhi_stats_vap_t *mhi_vap_stats;
  MTLK_ASSERT((core) || (stats));

  mhi_vap_stats = &core->mhi_vap_stat;
  /* 64-bit accumulated values */
  stats->PacketsSent = mhi_vap_stats->stats64.txFrames;
  stats->PacketsReceived = mhi_vap_stats->stats64.rxFrames;
  stats->BytesSent = mhi_vap_stats->stats64.txBytes;
  stats->BytesReceived = mhi_vap_stats->stats64.rxBytes;

  stats->UnicastPacketsSent = mhi_vap_stats->stats.txInUnicastHd;
  stats->UnicastPacketsReceived = mhi_vap_stats->stats.rxOutUnicastHd;
  stats->MulticastPacketsSent = mhi_vap_stats->stats.txInMulticastHd;
  stats->MulticastPacketsReceived = mhi_vap_stats->stats.rxOutMulticastHd;
  stats->BroadcastPacketsSent = mhi_vap_stats->stats.txInBroadcastHd;
  stats->BroadcastPacketsReceived = mhi_vap_stats->stats.rxOutBroadcastHd;

  /* VAP PD statistics */
  stats->PacketPDSent       = (_mtlk_core_get_cnt(core, MTLK_CORE_CNT_PD_BROADCAST_PACKETS_SENT)) +
                              (_mtlk_core_get_cnt(core, MTLK_CORE_CNT_PD_MULTICAST_PACKETS_SENT)) +
                              (_mtlk_core_get_cnt(core, MTLK_CORE_CNT_PD_UNICAST_PACKETS_SENT));

  stats->PDBytesSent        = (_mtlk_core_get_cnt_64(core, MTLK_CORE_CNT_PD_BROADCAST_BYTES_SENT_64)) +
                              (_mtlk_core_get_cnt_64(core, MTLK_CORE_CNT_PD_MULTICAST_BYTES_SENT_64)) +
                              (_mtlk_core_get_cnt_64(core, MTLK_CORE_CNT_PD_UNICAST_BYTES_SENT_64));

  stats->UnicastPDSent      = _mtlk_core_get_cnt(core, MTLK_CORE_CNT_PD_UNICAST_PACKETS_SENT);
  stats->UnicastPDBytesSent = _mtlk_core_get_cnt_64(core, MTLK_CORE_CNT_PD_UNICAST_BYTES_SENT_64);
}

static void
_mtlk_core_get_tr181_hw (mtlk_core_t* core, mtlk_wssa_drv_tr181_hw_t* tr181_hw)
{
  wave_radio_t *radio;
  MTLK_ASSERT((core) || (tr181_hw));

  radio = wave_vap_radio_get(core->vap_handle);
  tr181_hw->Enable = wave_radio_mode_get(radio);
  tr181_hw->Channel = _mtlk_core_get_channel(core);
}

static void
_mtlk_core_get_tr181_error_stats (mtlk_core_t* core, mtlk_wssa_drv_tr181_error_stats_t* errors)
{
  mtlk_mhi_stats_vap_t *mhi_vap_stats;
  MTLK_ASSERT((core) || (errors));

  mhi_vap_stats = &core->mhi_vap_stat;

  errors->ErrorsSent              = mhi_vap_stats->stats.agerCount;
  errors->ErrorsReceived          = mhi_vap_stats->stats.mpduTypeNotSupported +
                                    mhi_vap_stats->stats.replayData +
                                    mhi_vap_stats->stats.replayMngmnt +
                                    mhi_vap_stats->stats.tkipCount +
                                    mhi_vap_stats->stats.securityFailure;
  errors->DiscardPacketsReceived  = mhi_vap_stats->stats.dropMpdu;
  errors->DiscardPacketsSent      = errors->ErrorsSent;
}

static void
_mtlk_core_get_tr181_retrans_stats (mtlk_core_t* core, mtlk_wssa_retrans_stats_t* retrans)
{
  mtlk_mhi_stats_vap_t *mhi_vap_stats;
  MTLK_ASSERT((core) || (retrans));

  mhi_vap_stats = &core->mhi_vap_stat;

  retrans->Retransmissions    = 0; /* Not available in FW so far */
  retrans->FailedRetransCount = 0; /* Never drop packets due to retry limit */
  retrans->RetransCount       = mhi_vap_stats->stats.transmitStreamRprtMultipleRetryCount;
  retrans->RetryCount         = mhi_vap_stats->stats.retryAmsdu;
  retrans->MultipleRetryCount = mhi_vap_stats->stats.multipleRetryAmsdu;
}

void __MTLK_IFUNC
mtlk_core_get_tr181_wlan_stats (mtlk_core_t* core, mtlk_wssa_drv_tr181_wlan_stats_t* stats)
{
  mtlk_mhi_stats_vap_t *mhi_vap_stats;
  MTLK_ASSERT((core) || (stats));

  mhi_vap_stats = &core->mhi_vap_stat;

  _mtlk_core_get_traffic_wlan_stats(core, &stats->traffic_stats);
  _mtlk_core_get_tr181_error_stats(core, &stats->error_stats);
  _mtlk_core_get_tr181_retrans_stats(core, &stats->retrans_stats);

  stats->UnknownProtoPacketsReceived = mhi_vap_stats->stats.mpduTypeNotSupported;
  stats->ACKFailureCount = mhi_vap_stats->stats.ackFailure;
  stats->AggregatedPacketCount = mhi_vap_stats->stats.transmittedAmsdu;
}

static void
_mtlk_core_get_vap_info_stats (mtlk_core_t* core, struct driver_vap_info *vap_info)
{
  mtlk_mhi_stats_vap_t *mhi_vap_stats;
  MTLK_ASSERT((core) || (vap_info));

  mhi_vap_stats = &core->mhi_vap_stat;

  mtlk_core_get_tr181_wlan_stats(core, &vap_info->vap_stats);

  /* todo: These 4 counters are 64-bit, but actual values are 32-bit. Check
   * if 64 bit values are needed and implement. */
  vap_info->TransmittedOctetsInAMSDUCount = mhi_vap_stats->stats.transmittedOctetsInAmsdu;
  vap_info->ReceivedOctetsInAMSDUCount = mhi_vap_stats->stats.amsduBytes;
  vap_info->TransmittedOctetsInAMPDUCount = mhi_vap_stats->stats.transmittedOctetsInAmpdu;
  vap_info->ReceivedOctetsInAMPDUCount = mhi_vap_stats->stats.octetsInAmpdu;

  vap_info->RTSSuccessCount = mhi_vap_stats->stats.rtsSuccessCount;
  vap_info->RTSFailureCount = mhi_vap_stats->stats.rtsFailure;
  vap_info->TransmittedAMSDUCount = mhi_vap_stats->stats.transmittedAmsdu;
  vap_info->FailedAMSDUCount = mhi_vap_stats->stats.failedAmsdu;
  vap_info->AMSDUAckFailureCount = mhi_vap_stats->stats.amsduAckFailure;
  vap_info->ReceivedAMSDUCount = mhi_vap_stats->stats.amsdu;
  vap_info->TransmittedAMPDUCount = mhi_vap_stats->stats.transmittedAmpdu;
  vap_info->TransmittedMPDUsInAMPDUCount = mhi_vap_stats->stats.transmittedMpduInAmpdu;
  vap_info->AMPDUReceivedCount = mhi_vap_stats->stats.ampdu;
  vap_info->MPDUInReceivedAMPDUCount = mhi_vap_stats->stats.mpduInAmpdu;
  vap_info->ImplicitBARFailureCount = mhi_vap_stats->stats.implicitBarFailure;
  vap_info->ExplicitBARFailureCount = mhi_vap_stats->stats.explicitBarFailure;
  vap_info->TwentyMHzFrameTransmittedCount = mhi_vap_stats->stats.transmitBw20;
  vap_info->FortyMHzFrameTransmittedCount = mhi_vap_stats->stats.transmitBw40;
  vap_info->SwitchChannel20To40 = _mtlk_core_get_cnt(mtlk_core_get_master(core->vap_handle), MTLK_CORE_CNT_CHANNEL_SWITCH_20_TO_40);
  vap_info->SwitchChannel40To20 = _mtlk_core_get_cnt(mtlk_core_get_master(core->vap_handle), MTLK_CORE_CNT_CHANNEL_SWITCH_40_TO_20);
  vap_info->FrameDuplicateCount = _mtlk_core_get_cnt(core, MTLK_CORE_CNT_RX_PACKETS_DISCARDED_DRV_DUPLICATE);
}

static mtlk_error_t
_mtlk_core_cfg_store_chan_switch_deauth_params(mtlk_handle_t hcore, const void* data, uint32 data_size)
{
  mtlk_error_t res = MTLK_ERR_OK;
  mtlk_clpb_t *clpb = *(mtlk_clpb_t **) data;
  mtlk_core_t *core = HANDLE_T_PTR(mtlk_core_t, hcore);
  struct intel_vendor_channel_switch_cfg *deauth_data = mtlk_clpb_enum_get_next(clpb, &data_size);

  MTLK_ASSERT(NULL != core);

  MTLK_CLPB_TRY_EX(deauth_data, data_size, sizeof(struct intel_vendor_channel_switch_cfg))
    res = MTLK_CORE_PDB_SET_BINARY(core,
           PARAM_DB_CORE_CSA_DEAUTH_PARAMS, deauth_data, data_size);
    if (MTLK_ERR_OK != res) {
      ELOG_DD("CID-%04x: Can't store deauth multicast frames (err=%d)", mtlk_vap_get_oid(core->vap_handle), res);
    }
  MTLK_CLPB_FINALLY(res)
    return mtlk_clpb_push_res(clpb, res);
  MTLK_CLPB_END
}

int __MTLK_IFUNC
mtlk_core_send_iwpriv_config_to_fw (mtlk_core_t *core)
{
  int res = MTLK_ERR_OK;
  wave_radio_t *radio = wave_vap_radio_get(core->vap_handle);

  if (mtlk_vap_is_master(core->vap_handle)) {
    res = mtlk_core_set_radar_detect(core, WAVE_RADIO_PDB_GET_INT(radio, PARAM_DB_RADIO_DFS_RADAR_DETECTION));
    if (MTLK_ERR_OK != res) goto end;

    res = mtlk_core_cfg_init_cca_threshold(core);
  }

end:
  return res;
}

BOOL __MTLK_IFUNC
mtlk_core_get_ieee80211_radar_detected(mtlk_core_t* core, uint32 freq)
{
  wave_radio_t *radio = wave_vap_radio_get(core->vap_handle);
  struct wiphy *wiphy = wv_mac80211_wiphy_get(wave_radio_mac80211_get(radio));
  struct ieee80211_channel *ch;

  ch = ieee80211_get_channel(wiphy, freq);
  if ((ch != NULL) && (ch->flags & IEEE80211_CHAN_RADAR)){
    return (ch->dfs_state == NL80211_DFS_UNAVAILABLE);
  }

  return 0;
}

static int
_wave_core_bss_tx_status_get (mtlk_handle_t hcore,
                              const void* data, uint32 data_size)
{
  mtlk_core_t *master_core = HANDLE_T_PTR(mtlk_core_t, hcore);
  mtlk_hw_t *hw;

  MTLK_ASSERT(sizeof(mtlk_clpb_t*) == data_size);
  MTLK_ASSERT(mtlk_vap_is_master(master_core->vap_handle));

  hw = mtlk_vap_get_hw(master_core->vap_handle);
  MTLK_ASSERT(hw != NULL);

#if WAVE_USE_BSS_TX_MONITOR
  wave_hw_bss_tx_map_check(hw);
#endif

  return MTLK_ERR_OK;
}

void __MTLK_IFUNC wave_core_sta_disconnect (mtlk_vap_handle_t vap_handle, IEEE_ADDR *addr)
{
  MTLK_ASSERT(vap_handle != NULL);
  /* disconnect STA: reuse our WDS vendor event is fully OK for that */
  wv_cfg80211_peer_disconnect(mtlk_df_user_get_ndev(mtlk_df_get_user(mtlk_vap_get_df(vap_handle))), addr);
}

void __MTLK_IFUNC
wave_core_cfg_set_whm_hw_logger_cfg (struct nic *nic, wave_whm_hwlogger_cfg_t *hw_logger, uint32 data_size)
{
  _mtlk_process_hw_task(nic, SERIALIZABLE, wave_core_cfg_send_whm_hw_logger_cfg, HANDLE_T(nic), hw_logger, data_size);
}

mtlk_error_t __MTLK_IFUNC
mtlk_core_set_pcie_speed (mtlk_core_t *core, uint16 pcie_speed)
{
  uint32 linkctrl2, link_speed, elapsed_time = 0;
  uint16 lnkctl, lnksta, current_speed;
  uint8 lane_width, lanectl;
  mtlk_hw_t *hw = mtlk_vap_get_hw(core->vap_handle);
  struct pci_dev *pdev = wave_hw_mmb_get_pci_dev(hw);

  /* traverse the pcie device hierarchy to find the root complex */
  while (pdev && !pci_is_root_bus(pdev->bus)) {
        pdev = pdev->bus->self;
  }

  if (pdev && pci_is_root_bus(pdev->bus)) {
    ILOG1_SDD("Found root complex: %s, vendor: 0x%x, device: 0x%x\n",
               pci_name(pdev), pdev->vendor, pdev->device);
  }
  else {
    ILOG1_V("Root complex not found\n");
    return MTLK_ERR_NO_RESOURCES;
  }

  /* PCI_EXP_LNKCTL2 register stores the target link speed */
  pcie_capability_read_dword(pdev, PCI_EXP_LNKCTL2, &linkctrl2);
  linkctrl2 &= ~PCI_EXP_LNKCTL2_TLS;

  /* Modified custom register PCIE_PORT_MULTI_LANE_CTRL for lane change to take effect */
  pci_read_config_byte(pdev, PCIE_PORT_MULTI_LANE_CTRL, &lanectl);
  lanectl &= ~(PORT_MLTI_LNK_WDTH_CHNG | PORT_MLTI_LNK_WDTH);

  if(pcie_speed == PCIE_SPEED_GEN1) {
    link_speed = PCI_EXP_LNKCTL2_TLS_2_5GT;
    lane_width = 1;
  } else {
    link_speed = PCI_EXP_LNKCTL2_TLS_16_0GT;
    lane_width = 2;
  }

  pcie_capability_write_dword(pdev, PCI_EXP_LNKCTL2, linkctrl2 | link_speed);
  lanectl |= PORT_MLTI_LNK_WDTH_CHNG | lane_width;
  pci_write_config_byte(pdev,  PCIE_PORT_MULTI_LANE_CTRL, lanectl);

  /* retrain pcie link */
  pcie_capability_read_word(pdev, PCI_EXP_LNKCTL, &lnkctl);
  lnkctl |= PCI_EXP_LNKCTL_RL;
  pcie_capability_write_word(pdev, PCI_EXP_LNKCTL, lnkctl);

  while (elapsed_time < RETRAIN_TIMEOUT_MS) {
    /* read the current link status register value */
    pcie_capability_read_word(pdev, PCI_EXP_LNKSTA, &lnksta);
    current_speed = lnksta & PCI_EXP_LNKSTA_CLS;
    /* check if the link speed has been modified */
    if (current_speed == pcie_speed) {
      ILOG0_D("mtlk_core_set_pcie_speed: pcie_speed set to %d", pcie_speed);
      return MTLK_ERR_OK; // Retrain complete
    }
    /* sleep for the poll interval */
    msleep(POLL_INTERVAL_MS);
    elapsed_time += POLL_INTERVAL_MS;
  }
  return MTLK_ERR_UNKNOWN;
}

mtlk_error_t __MTLK_IFUNC mtlk_core_get_pcie_speed(struct pci_dev *pdev, uint16 *pcie_speed)
{
  u16 link_status;
  int ret;

  /* read the Link Status register to get the current link speed */
  ret = pcie_capability_read_word(pdev, PCI_EXP_LNKSTA, &link_status);
  if (ret) {
    ILOG1_V("Failed to read PCIe Link Status register\n");
    return MTLK_ERR_UNKNOWN;
  }
  *pcie_speed = link_status & PCI_EXP_LNKSTA_CLS;

  return MTLK_ERR_OK;
}
