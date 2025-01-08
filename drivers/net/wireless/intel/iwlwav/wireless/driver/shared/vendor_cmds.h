/******************************************************************************

         Copyright (c) 2020, MaxLinear, Inc.
         Copyright 2016 - 2020 Intel Corporation
         Copyright 2015 - 2016 Lantiq Beteiligungs-GmbH & Co. KG
         Copyright 2009 - 2014 Lantiq Deutschland GmbH
         Copyright 2007 - 2008 Infineon Technologies AG

  For licensing information, see the file 'LICENSE' in the root folder of
  this software module.

*******************************************************************************/

#ifndef _VENDOR_CMDS_H_
#define _VENDOR_CMDS_H_

#ifdef __KERNEL__
#define DEF_IEEE_ADDR(name) IEEE_ADDR name
#else
#define DEF_IEEE_ADDR(name) u8 name[ETH_ALEN]
#endif


/*
 * This file is a registry of identifier assignments from the Lantiq
 * OUI AC:9A:96 for purposes other than MAC address assignment. New identifiers
 * can be assigned through normal review process for changes to the upstream
 * hostap.git repository.
 */

#define OUI_LTQ 0xAC9A96
#define OUI_MXL OUI_LTQ

/**
 * enum ltq_nl80211_vendor_subcmds - LTQ nl80211 vendor command identifiers
 *
 * @LTQ_NL80211_VENDOR_SUBCMD_UNSPEC: Reserved value 0
 *
 * @LTQ_NL80211_VENDOR_SUBCMD_GET_AID: Get AID request.
 *
 * @LTQ_NL80211_VENDOR_SUBCMD_FREE_AID: Free AID request.
 *
 * @LTQ_NL80211_VENDOR_SUBCMD_TX_EAPOL: Send EAPoL request.
 *
 * @LTQ_NL80211_VENDOR_SUBCMD_SYNC_DONE: Sync the operations between hostapd and
 * driver
 */
enum ltq_nl80211_vendor_subcmds {
  LTQ_NL80211_VENDOR_SUBCMD_UNSPEC,
  LTQ_NL80211_VENDOR_SUBCMD_GET_AID,
  LTQ_NL80211_VENDOR_SUBCMD_FREE_AID,
  LTQ_NL80211_VENDOR_SUBCMD_SYNC_DONE,
  LTQ_NL80211_VENDOR_SUBCMD_TX_EAPOL,
  LTQ_NL80211_VENDOR_SUBCMD_INITIAL_DATA,
  LTQ_NL80211_VENDOR_SUBCMD_DFS_DEBUG,
  LTQ_NL80211_VENDOR_SUBCMD_SET_DENY_MAC,
  LTQ_NL80211_VENDOR_SUBCMD_STA_STEER,
  LTQ_NL80211_VENDOR_SUBCMD_GET_STA_MEASUREMENTS,
  LTQ_NL80211_VENDOR_SUBCMD_GET_UNCONNECTED_STA,
  LTQ_NL80211_VENDOR_SUBCMD_GET_VAP_MEASUREMENTS,
  LTQ_NL80211_VENDOR_SUBCMD_GET_RADIO_INFO,
  LTQ_NL80211_VENDOR_SUBCMD_SET_ATF_QUOTAS,
  LTQ_NL80211_VENDOR_SUBCMD_SET_WDS_WPA_STA,
  LTQ_NL80211_VENDOR_SUBCMD_SET_BSS_LOAD,
  LTQ_NL80211_VENDOR_SUBCMD_SET_MESH_MODE,
  LTQ_NL80211_VENDOR_SUBCMD_CHECK_4ADDR_MODE,
  LTQ_NL80211_VENDOR_SUBCMD_SET_SOFTBLOCK_THRESHOLDS,
  LTQ_NL80211_VENDOR_SUBCMD_SET_SOFTBLOCK_DISABLE,
  LTQ_NL80211_VENDOR_SUBCMD_SET_11H_RADAR_DETECT,
  LTQ_NL80211_VENDOR_SUBCMD_GET_11H_RADAR_DETECT,
  LTQ_NL80211_VENDOR_SUBCMD_SET_11H_BEACON_COUNT,
  LTQ_NL80211_VENDOR_SUBCMD_GET_11H_BEACON_COUNT,
  LTQ_NL80211_VENDOR_SUBCMD_SET_11H_CH_CHECK_TIME,
  LTQ_NL80211_VENDOR_SUBCMD_GET_11H_CH_CHECK_TIME,
  LTQ_NL80211_VENDOR_SUBCMD_SET_NON_OCCUPATED_PRD,
  LTQ_NL80211_VENDOR_SUBCMD_GET_NON_OCCUPATED_PRD,
  LTQ_NL80211_VENDOR_SUBCMD_SET_11H_EMULAT_RADAR,
  LTQ_NL80211_VENDOR_SUBCMD_SET_ADD_PEERAP,
  LTQ_NL80211_VENDOR_SUBCMD_SET_DEL_PEERAP,
  LTQ_NL80211_VENDOR_SUBCMD_SET_PEERAP_KEY_IDX,
  LTQ_NL80211_VENDOR_SUBCMD_GET_PEERAP_KEY_IDX,
  LTQ_NL80211_VENDOR_SUBCMD_GET_PEERAP_LIST,
  LTQ_NL80211_VENDOR_SUBCMD_SET_MAC_WATCHDOG_TIMEOUT_MS,
  LTQ_NL80211_VENDOR_SUBCMD_GET_MAC_WATCHDOG_TIMEOUT_MS,
  LTQ_NL80211_VENDOR_SUBCMD_SET_MAC_WATCHDOG_PERIOD_MS,
  LTQ_NL80211_VENDOR_SUBCMD_GET_MAC_WATCHDOG_PERIOD_MS,
  LTQ_NL80211_VENDOR_SUBCMD_SET_BRIDGE_MODE,
  LTQ_NL80211_VENDOR_SUBCMD_GET_BRIDGE_MODE,
  LTQ_NL80211_VENDOR_SUBCMD_SET_RELIABLE_MULTICAST,
  LTQ_NL80211_VENDOR_SUBCMD_GET_RELIABLE_MULTICAST,
  LTQ_NL80211_VENDOR_SUBCMD_SET_AP_FORWARDING,
  LTQ_NL80211_VENDOR_SUBCMD_GET_AP_FORWARDING,
  LTQ_NL80211_VENDOR_SUBCMD_SET_FW_LOG_SEVERITY,
  LTQ_NL80211_VENDOR_SUBCMD_SET_WDS_HOST_TIMEOUT,
  LTQ_NL80211_VENDOR_SUBCMD_GET_WDS_HOST_TIMEOUT,
  LTQ_NL80211_VENDOR_SUBCMD_GET_EEPROM,
  LTQ_NL80211_VENDOR_SUBCMD_SET_DCDP_API_LITEPATH,
  LTQ_NL80211_VENDOR_SUBCMD_GET_DCDP_API_LITEPATH,
  LTQ_NL80211_VENDOR_SUBCMD_SET_DCDP_API_LITEPATH_COMP,
  LTQ_NL80211_VENDOR_SUBCMD_GET_DCDP_API_LITEPATH_COMP,
  LTQ_NL80211_VENDOR_SUBCMD_SET_UDMA_API,
  LTQ_NL80211_VENDOR_SUBCMD_GET_UDMA_API,
  LTQ_NL80211_VENDOR_SUBCMD_SET_UDMA_API_EXT,
  LTQ_NL80211_VENDOR_SUBCMD_GET_UDMA_API_EXT,
  LTQ_NL80211_VENDOR_SUBCMD_SET_UDMA_VLAN_ID,
  LTQ_NL80211_VENDOR_SUBCMD_GET_UDMA_VLAN_ID,
  LTQ_NL80211_VENDOR_SUBCMD_SET_UDMA_VLAN_ID_EXT,
  LTQ_NL80211_VENDOR_SUBCMD_GET_UDMA_VLAN_ID_EXT,
  LTQ_NL80211_VENDOR_SUBCMD_SET_COC_POWER_MODE,
  LTQ_NL80211_VENDOR_SUBCMD_GET_COC_POWER_MODE,
  LTQ_NL80211_VENDOR_SUBCMD_SET_COC_AUTO_PARAMS,
  LTQ_NL80211_VENDOR_SUBCMD_GET_COC_AUTO_PARAMS,
  LTQ_NL80211_VENDOR_SUBCMD_SET_PCOC_POWER_MODE,
  LTQ_NL80211_VENDOR_SUBCMD_GET_PCOC_POWER_MODE,
  LTQ_NL80211_VENDOR_SUBCMD_SET_PCOC_AUTO_PARAMS,
  LTQ_NL80211_VENDOR_SUBCMD_GET_PCOC_AUTO_PARAMS,
  LTQ_NL80211_VENDOR_SUBCMD_SET_PCOC_PMCU_DEBUG,
  LTQ_NL80211_VENDOR_SUBCMD_SET_PRM_ID_TPC_LOOP_TYPE,
  LTQ_NL80211_VENDOR_SUBCMD_GET_PRM_ID_TPC_LOOP_TYPE,
  LTQ_NL80211_VENDOR_SUBCMD_SET_INTERFER_THRESH,
  LTQ_NL80211_VENDOR_SUBCMD_GET_INTERFER_MODE,
  LTQ_NL80211_VENDOR_SUBCMD_GET_AP_CAPABILITIES_MAX_STAs,
  LTQ_NL80211_VENDOR_SUBCMD_GET_AP_CAPABILITIES_MAX_VAPs,
  LTQ_NL80211_VENDOR_SUBCMD_SET_11B_ANTENNA_SELECTION,
  LTQ_NL80211_VENDOR_SUBCMD_GET_11B_ANTENNA_SELECTION,
  LTQ_NL80211_VENDOR_SUBCMD_SET_DBG_CLI,
  LTQ_NL80211_VENDOR_SUBCMD_SET_FW_DEBUG,
  LTQ_NL80211_VENDOR_SUBCMD_SET_TA_TIMER_RESOLUTION,
  LTQ_NL80211_VENDOR_SUBCMD_GET_TA_TIMER_RESOLUTION,
  LTQ_NL80211_VENDOR_SUBCMD_GET_TA_DBG,
  LTQ_NL80211_VENDOR_SUBCMD_SET_FW_RECOVERY,
  LTQ_NL80211_VENDOR_SUBCMD_GET_FW_RECOVERY,
  LTQ_NL80211_VENDOR_SUBCMD_SET_SCAN_PARAMS,
  LTQ_NL80211_VENDOR_SUBCMD_GET_SCAN_PARAMS,
  LTQ_NL80211_VENDOR_SUBCMD_SET_SCAN_PARAMS_BG,
  LTQ_NL80211_VENDOR_SUBCMD_GET_SCAN_PARAMS_BG,
  LTQ_NL80211_VENDOR_SUBCMD_SET_SCAN_MODIFS,
  LTQ_NL80211_VENDOR_SUBCMD_GET_SCAN_MODIFS,
  LTQ_NL80211_VENDOR_SUBCMD_SET_SCAN_PAUSE_BG_CACHE,
  LTQ_NL80211_VENDOR_SUBCMD_GET_SCAN_PAUSE_BG_CACHE,
  LTQ_NL80211_VENDOR_SUBCMD_SET_SCAN_EXP_TIME,
  LTQ_NL80211_VENDOR_SUBCMD_GET_SCAN_EXP_TIME,
  LTQ_NL80211_VENDOR_SUBCMD_GET_GENL_FAMILY_ID,
  LTQ_NL80211_VENDOR_SUBCMD_SET_TASKLET_LIMITS,
  LTQ_NL80211_VENDOR_SUBCMD_GET_TASKLET_LIMITS,
  LTQ_NL80211_VENDOR_SUBCMD_SET_RADIO_MODE,
  LTQ_NL80211_VENDOR_SUBCMD_GET_RADIO_MODE,
  LTQ_NL80211_VENDOR_SUBCMD_SET_AGGR_CONFIG,
  LTQ_NL80211_VENDOR_SUBCMD_GET_AGGR_CONFIG,
  LTQ_NL80211_VENDOR_SUBCMD_SET_AMSDU_NUM,
  LTQ_NL80211_VENDOR_SUBCMD_GET_AMSDU_NUM,
  LTQ_NL80211_VENDOR_SUBCMD_SET_AGG_RATE_LIMIT,
  LTQ_NL80211_VENDOR_SUBCMD_GET_AGG_RATE_LIMIT,
  LTQ_NL80211_VENDOR_SUBCMD_SET_ADMISSION_CAPACITY,
  LTQ_NL80211_VENDOR_SUBCMD_GET_ADMISSION_CAPACITY,
  LTQ_NL80211_VENDOR_SUBCMD_SET_RX_THRESHOLD,
  LTQ_NL80211_VENDOR_SUBCMD_GET_RX_THRESHOLD,
  LTQ_NL80211_VENDOR_SUBCMD_SET_RX_DUTY_CYCLE,
  LTQ_NL80211_VENDOR_SUBCMD_GET_RX_DUTY_CYCLE,
  LTQ_NL80211_VENDOR_SUBCMD_SET_TX_POWER_LIMIT_OFFSET,
  LTQ_NL80211_VENDOR_SUBCMD_GET_TX_POWER_LIMIT_OFFSET,
  LTQ_NL80211_VENDOR_SUBCMD_SET_PROTECTION_METHOD,
  LTQ_NL80211_VENDOR_SUBCMD_GET_PROTECTION_METHOD,
  LTQ_NL80211_VENDOR_SUBCMD_GET_BEAMFORM_EXPLICIT,
  LTQ_NL80211_VENDOR_SUBCMD_SET_TEMPERATURE_SENSOR,
  LTQ_NL80211_VENDOR_SUBCMD_GET_TEMPERATURE_SENSOR,
  LTQ_NL80211_VENDOR_SUBCMD_SET_QAMPLUS_MODE,
  LTQ_NL80211_VENDOR_SUBCMD_GET_QAMPLUS_MODE,
  LTQ_NL80211_VENDOR_SUBCMD_SET_ACS_UPDATE_TO,
  LTQ_NL80211_VENDOR_SUBCMD_GET_ACS_UPDATE_TO,
  LTQ_NL80211_VENDOR_SUBCMD_SET_MU_OPERATION,
  LTQ_NL80211_VENDOR_SUBCMD_GET_MU_OPERATION,
  LTQ_NL80211_VENDOR_SUBCMD_SET_CCA_THRESHOLD,
  LTQ_NL80211_VENDOR_SUBCMD_GET_CCA_THRESHOLD,
  LTQ_NL80211_VENDOR_SUBCMD_SET_CCA_ADAPT,
  LTQ_NL80211_VENDOR_SUBCMD_GET_CCA_ADAPT,
  LTQ_NL80211_VENDOR_SUBCMD_SET_RADAR_RSSI_TH,
  LTQ_NL80211_VENDOR_SUBCMD_GET_RADAR_RSSI_TH,
  LTQ_NL80211_VENDOR_SUBCMD_SET_FILS_BEACON_FLAG,
  LTQ_NL80211_VENDOR_SUBCMD_GET_FILS_BEACON_FLAG,
  LTQ_NL80211_VENDOR_SUBCMD_SET_CPU_DMA_LATENCY,
  LTQ_NL80211_VENDOR_SUBCMD_GET_CPU_DMA_LATENCY,
  LTQ_NL80211_VENDOR_SUBCMD_SET_RTS_MODE,
  LTQ_NL80211_VENDOR_SUBCMD_GET_RTS_MODE,
  LTQ_NL80211_VENDOR_SUBCMD_SET_MAX_MPDU_LENGTH,
  LTQ_NL80211_VENDOR_SUBCMD_GET_MAX_MPDU_LENGTH,
  LTQ_NL80211_VENDOR_SUBCMD_SET_BF_MODE,
  LTQ_NL80211_VENDOR_SUBCMD_GET_BF_MODE,
  LTQ_NL80211_VENDOR_SUBCMD_SET_FIXED_RATE,
  LTQ_NL80211_VENDOR_SUBCMD_SET_ACTIVE_ANT_MASK,
  LTQ_NL80211_VENDOR_SUBCMD_GET_ACTIVE_ANT_MASK,
  LTQ_NL80211_VENDOR_SUBCMD_SET_4ADDR_STA_ADD,
  LTQ_NL80211_VENDOR_SUBCMD_SET_4ADDR_STA_DEL,
  LTQ_NL80211_VENDOR_SUBCMD_GET_4ADDR_STA_LIST,
  LTQ_NL80211_VENDOR_SUBCMD_SET_TXOP_CONFIG,
  LTQ_NL80211_VENDOR_SUBCMD_GET_TXOP_CONFIG,
  LTQ_NL80211_VENDOR_SUBCMD_SET_SSB_MODE,
  LTQ_NL80211_VENDOR_SUBCMD_GET_SSB_MODE,
  LTQ_NL80211_VENDOR_SUBCMD_SET_COEX_CFG,
  LTQ_NL80211_VENDOR_SUBCMD_GET_COEX_CFG,
  LTQ_NL80211_VENDOR_SUBCMD_SET_PROBING_MASK,
  LTQ_NL80211_VENDOR_SUBCMD_GET_PROBING_MASK,
  LTQ_NL80211_VENDOR_SUBCMD_SET_MCAST_RANGE_SETUP,
  LTQ_NL80211_VENDOR_SUBCMD_GET_MCAST_RANGE_SETUP,
  LTQ_NL80211_VENDOR_SUBCMD_SET_MCAST_RANGE_SETUP_IPV6,
  LTQ_NL80211_VENDOR_SUBCMD_GET_MCAST_RANGE_SETUP_IPV6,
  LTQ_NL80211_VENDOR_SUBCMD_SET_ONLINE_CALIBRATION_ALGO_MASK,
  LTQ_NL80211_VENDOR_SUBCMD_GET_ONLINE_CALIBRATION_ALGO_MASK,
  LTQ_NL80211_VENDOR_SUBCMD_SET_CALIBRATION_ALGO_MASK,
  LTQ_NL80211_VENDOR_SUBCMD_GET_CALIBRATION_ALGO_MASK,
  LTQ_NL80211_VENDOR_SUBCMD_SET_FIXED_POWER,
  LTQ_NL80211_VENDOR_SUBCMD_GET_FIXED_POWER,
  LTQ_NL80211_VENDOR_SUBCMD_SET_UNCONNECTED_STA_SCAN_TIME,
  LTQ_NL80211_VENDOR_SUBCMD_GET_UNCONNECTED_STA_SCAN_TIME,
  LTQ_NL80211_VENDOR_SUBCMD_SET_RESTRICTED_AC_MODE,
  LTQ_NL80211_VENDOR_SUBCMD_GET_RESTRICTED_AC_MODE,
  LTQ_NL80211_VENDOR_SUBCMD_SET_PD_THRESHOLD,
  LTQ_NL80211_VENDOR_SUBCMD_GET_PD_THRESHOLD,
  LTQ_NL80211_VENDOR_SUBCMD_SET_FAST_DROP,
  LTQ_NL80211_VENDOR_SUBCMD_GET_FAST_DROP,
  LTQ_NL80211_VENDOR_SUBCMD_SET_ERP,
  LTQ_NL80211_VENDOR_SUBCMD_SET_FAST_DYNAMIC_MC_RATE,
  LTQ_NL80211_VENDOR_SUBCMD_SET_COUNTERS_SRC,
  LTQ_NL80211_VENDOR_SUBCMD_GET_COUNTERS_SRC,
  LTQ_NL80211_VENDOR_SUBCMD_SET_FIXED_LTF_AND_GI,
  LTQ_NL80211_VENDOR_SUBCMD_GET_FIXED_LTF_AND_GI,
  LTQ_NL80211_VENDOR_SUBCMD_SET_STATIC_PLAN_CONFIG,
  LTQ_NL80211_VENDOR_SUBCMD_SET_WDS_WEP_ENC_CFG,
  LTQ_NL80211_VENDOR_SUBCMD_GET_PVT_SENSOR,
  LTQ_NL80211_VENDOR_SUBCMD_SET_ENABLE_TEST_BUS,
  LTQ_NL80211_VENDOR_SUBCMD_SET_HE_MU_OPERATION,
  LTQ_NL80211_VENDOR_SUBCMD_GET_HE_MU_OPERATION,
  LTQ_NL80211_VENDOR_SUBCMD_SET_RTS_RATE,
  LTQ_NL80211_VENDOR_SUBCMD_GET_RTS_RATE,
  LTQ_NL80211_VENDOR_SUBCMD_SET_DBG_ASSERT,
  LTQ_NL80211_VENDOR_SUBCMD_SET_MBSSID_VAP,
  LTQ_NL80211_VENDOR_SUBCMD_SET_MBSSID_NUM_VAPS_IN_GROUP,
  LTQ_NL80211_VENDOR_SUBCMD_GET_RCVRY_STATS,
  LTQ_NL80211_VENDOR_SUBCMD_GET_ASSOCIATED_DEV_STATS,
  LTQ_NL80211_VENDOR_SUBCMD_GET_ASSOCIATED_DEV_RATE_INFO_RX_STATS,
  LTQ_NL80211_VENDOR_SUBCMD_GET_ASSOCIATED_DEV_RATE_INFO_TX_STATS,
  LTQ_NL80211_VENDOR_SUBCMD_GET_CHANNEL_STATS,
  LTQ_NL80211_VENDOR_SUBCMD_SET_STATS_POLL_PERIOD,
  LTQ_NL80211_VENDOR_SUBCMD_GET_STATS_POLL_PERIOD,
  LTQ_NL80211_VENDOR_SUBCMD_GET_ASSOCIATED_DEV_TID_STATS,
  LTQ_NL80211_VENDOR_SUBCMD_GET_PEER_LIST,
  LTQ_NL80211_VENDOR_SUBCMD_GET_PEER_FLOW_STATUS,
  LTQ_NL80211_VENDOR_SUBCMD_GET_PEER_CAPABILITIES,
  LTQ_NL80211_VENDOR_SUBCMD_GET_PEER_RATE_INFO,
  LTQ_NL80211_VENDOR_SUBCMD_GET_RECOVERY_STATS,
  LTQ_NL80211_VENDOR_SUBCMD_GET_HW_FLOW_STATUS,
  LTQ_NL80211_VENDOR_SUBCMD_GET_TR181_WLAN_STATS,
  LTQ_NL80211_VENDOR_SUBCMD_GET_TR181_HW_STATS,
  LTQ_NL80211_VENDOR_SUBCMD_GET_TR181_PEER_STATS,
  LTQ_NL80211_VENDOR_SUBCMD_SET_NFRP_CFG,
  LTQ_NL80211_VENDOR_SUBCMD_SET_MGMT_FRAMES_RATE,
  LTQ_NL80211_VENDOR_SUBCMD_SET_DYNAMIC_MU_TYPE,
  LTQ_NL80211_VENDOR_SUBCMD_GET_DYNAMIC_MU_TYPE,
  LTQ_NL80211_VENDOR_SUBCMD_SET_HE_MU_FIXED_PARAMETERS,
  LTQ_NL80211_VENDOR_SUBCMD_GET_HE_MU_FIXED_PARAMETERS,
  LTQ_NL80211_VENDOR_SUBCMD_SET_HE_MU_DURATION,
  LTQ_NL80211_VENDOR_SUBCMD_GET_HE_MU_DURATION,
  LTQ_NL80211_VENDOR_SUBCMD_GET_PHY_INBAND_POWER,
  LTQ_NL80211_VENDOR_SUBCMD_GET_HE_OPERATION,
  LTQ_NL80211_VENDOR_SUBCMD_GET_HE_NON_ADVERTISED,
  LTQ_NL80211_VENDOR_SUBCMD_SET_ZWDFS_ANT,
  LTQ_NL80211_VENDOR_SUBCMD_GET_ZWDFS_ANT,
  LTQ_NL80211_VENDOR_SUBCMD_GET_TWT_PARAMETERS,
  LTQ_NL80211_VENDOR_SUBCMD_GET_AX_DEFAULT_PARAMS,
  LTQ_NL80211_VENDOR_SUBCMD_SET_STATIONS_STATISTICS,
  LTQ_NL80211_VENDOR_SUBCMD_GET_STATIONS_STATISTICS,
  LTQ_NL80211_VENDOR_SUBCMD_SET_ETSI_PPDU_LIMITS,
  LTQ_NL80211_VENDOR_SUBCMD_GET_ETSI_PPDU_LIMITS,
  LTQ_NL80211_VENDOR_SUBCMD_GET_DEV_DIAG_RESULT2,
  LTQ_NL80211_VENDOR_SUBCMD_GET_DEV_DIAG_RESULT3,
  LTQ_NL80211_VENDOR_SUBCMD_GET_DCDP_DATAPATH_MODE,
  LTQ_NL80211_VENDOR_SUBCMD_GET_RTS_THRESHOLD,
  LTQ_NL80211_VENDOR_SUBCMD_SET_PIE_CFG,
  LTQ_NL80211_VENDOR_SUBCMD_GET_PIE_CFG,
  LTQ_NL80211_VENDOR_SUBCMD_SET_HE_NON_ADVERTISED,
  LTQ_NL80211_VENDOR_SUBCMD_SET_AP_RETRY_LIMIT,
  LTQ_NL80211_VENDOR_SUBCMD_GET_AP_RETRY_LIMIT,
  LTQ_NL80211_VENDOR_SUBCMD_CHANNEL_SWITCH_DEAUTH_CFG,
  LTQ_NL80211_VENDOR_SUBCMD_SET_CTS_TO_SELF_TO,
  LTQ_NL80211_VENDOR_SUBCMD_GET_CTS_TO_SELF_TO,
  LTQ_NL80211_VENDOR_SUBCMD_GET_ERP_CFG,
  LTQ_NL80211_VENDOR_SUBCMD_SET_TX_AMPDU_DENSITY,
  LTQ_NL80211_VENDOR_SUBCMD_GET_TX_AMPDU_DENSITY,
  LTQ_NL80211_VENDOR_SUBCMD_ADD_BACKHAUL_VRT_IFACE,
  LTQ_NL80211_VENDOR_SUBCMD_SET_OUT_OF_SCAN_CACHING,
  LTQ_NL80211_VENDOR_SUBCMD_GET_OUT_OF_SCAN_CACHING,
  LTQ_NL80211_VENDOR_SUBCMD_GET_PRIORITY_GPIO,
  LTQ_NL80211_VENDOR_SUBCMD_SET_HE_DEBUG_DATA,
  LTQ_NL80211_VENDOR_SUBCMD_SET_ALLOW_SCAN_DURING_CAC,
  LTQ_NL80211_VENDOR_SUBCMD_GET_ALLOW_SCAN_DURING_CAC,
  LTQ_NL80211_VENDOR_SUBCMD_GET_PHY_CHAN_STATUS,
  LTQ_NL80211_VENDOR_SUBCMD_SET_UNSOLICITED_FRAME_TX,
  LTQ_NL80211_VENDOR_SUBCMD_SET_DBG_CMD_FW,
  LTQ_NL80211_VENDOR_SUBCMD_SEND_FILS_DISCOVERY_FRAME,
  LTQ_NL80211_VENDOR_SUBCMD_GET_PEER_HOST_IF_QOS,
  LTQ_NL80211_VENDOR_SUBCMD_GET_PEER_HOST_IF,
  LTQ_NL80211_VENDOR_SUBCMD_GET_PEER_RX_STATS,
  LTQ_NL80211_VENDOR_SUBCMD_GET_PEER_UL_BSRC_TID_STATS,
  LTQ_NL80211_VENDOR_SUBCMD_GET_PEER_BAA_STATS,
  LTQ_NL80211_VENDOR_SUBCMD_GET_LINK_ADAPTION_STATS,
  LTQ_NL80211_VENDOR_SUBCMD_GET_PLAN_MANAGER_STATS,
  LTQ_NL80211_VENDOR_SUBCMD_GET_PEER_TWT_STATS,
  LTQ_NL80211_VENDOR_SUBCMD_GET_PER_CLIENT_STATS,
  LTQ_NL80211_VENDOR_SUBCMD_GET_PEER_PHY_RX_STATUS,
  LTQ_NL80211_VENDOR_SUBCMD_GET_PEER_INFO,
  LTQ_NL80211_VENDOR_SUBCMD_GET_WLAN_HOST_IF_QOS,
  LTQ_NL80211_VENDOR_SUBCMD_GET_WLAN_HOST_IF,
  LTQ_NL80211_VENDOR_SUBCMD_GET_WLAN_RX_STATS,
  LTQ_NL80211_VENDOR_SUBCMD_GET_WLAN_BAA_STATS,
  LTQ_NL80211_VENDOR_SUBCMD_GET_RADIO_RX_STATS,
  LTQ_NL80211_VENDOR_SUBCMD_GET_RADIO_BAA_STATS,
  LTQ_NL80211_VENDOR_SUBCMD_GET_TSMAN_INIT_TID_GL,
  LTQ_NL80211_VENDOR_SUBCMD_GET_TSMAN_INIT_STA_GL,
  LTQ_NL80211_VENDOR_SUBCMD_GET_TSMAN_RCPT_TID_GL,
  LTQ_NL80211_VENDOR_SUBCMD_GET_TSMAN_RCPT_STA_GL,
  LTQ_NL80211_VENDOR_SUBCMD_GET_RADIO_LINK_ADAPT_STATS,
  LTQ_NL80211_VENDOR_SUBCMD_GET_MULTICAST_STATS,
  LTQ_NL80211_VENDOR_SUBCMD_GET_TRAINING_MAN_STATS,
  LTQ_NL80211_VENDOR_SUBCMD_GET_GROUP_MAN_STATS,
  LTQ_NL80211_VENDOR_SUBCMD_GET_GENERAL_STATS,
  LTQ_NL80211_VENDOR_SUBCMD_GET_CUR_CHANNEL_STATS,
  LTQ_NL80211_VENDOR_SUBCMD_GET_RADIO_PHY_RX_STATS,
  LTQ_NL80211_VENDOR_SUBCMD_GET_DYNAMIC_BW_STATS,
  LTQ_NL80211_VENDOR_SUBCMD_GET_LA_MU_VHT_STATS,
  LTQ_NL80211_VENDOR_SUBCMD_SET_HE_BEACON,
  LTQ_NL80211_VENDOR_SUBCMD_SET_UNPROTECTED_DEAUTH,
  LTQ_NL80211_VENDOR_SUBCMD_SET_MU_OFDMA_BF,
  LTQ_NL80211_VENDOR_SUBCMD_GET_MU_OFDMA_BF,
  LTQ_NL80211_VENDOR_SUBCMD_SET_START_CCA_MSR_OFF_CHAN,
  LTQ_NL80211_VENDOR_SUBCMD_GET_CCA_MSR_OFF_CHAN,
  LTQ_NL80211_VENDOR_SUBCMD_GET_CCA_STATS_CURRENT_CHAN,
  LTQ_NL80211_VENDOR_SUBCMD_GET_LAST_PROBE_REQS,
  LTQ_NL80211_VENDOR_SUBCMD_SET_CLT_PROBE_REQS_MODE,
  LTQ_NL80211_VENDOR_SUBCMD_GET_CLT_PROBE_REQS_MODE,
  LTQ_NL80211_VENDOR_SUBCMD_SET_CCA_PREAMBLE_PUNCTURE_CFG,
  LTQ_NL80211_VENDOR_SUBCMD_GET_CCA_PREAMBLE_PUNCTURE_CFG,
  LTQ_NL80211_VENDOR_SUBCMD_GET_RADIO_USAGE_STATS,
  LTQ_NL80211_VENDOR_SUBCMD_GET_FORWARD_UNKNOWN_MCAST_FLAG,
  LTQ_NL80211_VENDOR_SUBCMD_SET_FORWARD_UNKNOWN_MCAST_FLAG,
  LTQ_NL80211_VENDOR_SUBCMD_SET_PN_RESET,
  LTQ_NL80211_VENDOR_SUBCMD_GET_ASSOCIATED_STATIONS_STATS,
  LTQ_NL80211_VENDOR_SUBCMD_EMULATE_INTERFERER,
  LTQ_NL80211_VENDOR_SUBCMD_ADVERTISE_BTWT_SCHEDULE,
  LTQ_NL80211_VENDOR_SUBCMD_TERMINATE_BTWT_SCHEDULE,
  LTQ_NL80211_VENDOR_SUBCMD_GET_ADVERTISED_BTWT_SCHEDULE,
  LTQ_NL80211_VENDOR_SUBCMD_TX_TWT_TEARDOWN,
  LTQ_NL80211_VENDOR_SUBCMD_SET_SB_TIMER_ACL_CFG,
  LTQ_NL80211_VENDOR_SUBCMD_SET_MTLK_LOG_LEVEL,
  LTQ_NL80211_VENDOR_SUBCMD_SET_WHM_CONFIG,
  LTQ_NL80211_VENDOR_SUBCMD_SET_WHM_RESET,
  LTQ_NL80211_VENDOR_SUBCMD_SET_WHM_TRIGGER,
  LTQ_NL80211_VENDOR_SUBCMD_RESET_STATISTICS,
  LTQ_NL80211_VENDOR_SUBCMD_SET_INTRA_VAP_MCAST,
  LTQ_NL80211_VENDOR_SUBCMD_SET_AP_EXCE_RETRY_LIMIT,
  LTQ_NL80211_VENDOR_SUBCMD_GET_AP_EXCE_RETRY_LIMIT,
  LTQ_NL80211_VENDOR_SUBCMD_SET_FIXED_RATE_THERMAL,
  LTQ_NL80211_VENDOR_SUBCMD_GET_FIXED_RATE_THERMAL,
  LTQ_NL80211_VENDOR_SUBCMD_SET_MGMT_FRAME_PWR_CTRL,
  LTQ_NL80211_VENDOR_SUBCMD_GET_MGMT_FRAME_PWR_CTRL,
  LTQ_NL80211_VENDOR_SUBCMD_SET_RSSI_IGNORE_PROBE_REQ,
  LTQ_NL80211_VENDOR_SUBCMD_SET_CSI_ENABLE,
  LTQ_NL80211_VENDOR_SUBCMD_GET_CSI_ENABLE,
  LTQ_NL80211_VENDOR_SUBCMD_CSI_SEND_NDP,
  LTQ_NL80211_VENDOR_SUBCMD_SET_CSI_AUTO_RATE,
  LTQ_NL80211_VENDOR_SUBCMD_GET_CSI_AUTO_RATE,
  LTQ_NL80211_VENDOR_SUBCMD_GET_CSI_STATS,
  LTQ_NL80211_VENDOR_SUBCMD_GET_CSI_COUNTERS,
  LTQ_NL80211_VENDOR_SUBCMD_GET_PEER_MIXED_STATS,
  LTQ_NL80211_VENDOR_SUBCMD_GET_LINK_ADAPT_MU_OFDMA_STATS,
  LTQ_NL80211_VENDOR_SUBCMD_SET_ALLOW_3ADDR_MCAST,
  LTQ_NL80211_VENDOR_SUBCMD_GET_ALLOW_3ADDR_MCAST,
  LTQ_NL80211_VENDOR_SUBCMD_GET_LINK_ADAPT_SU_MU_RU_OFDMA_STATS,
  LTQ_NL80211_VENDOR_SUBCMD_GET_20MHZ_TX_POWER,
  MXL_NL80211_VENDOR_SUBCMD_SET_EHT_DEBUG_DATA,
  MXL_NL80211_VENDOR_SUBCMD_SET_EHT_OPERATION,
  MXL_NL80211_VENDOR_SUBCMD_GET_EHT_OPERATION,
  MXL_NL80211_VENDOR_SUBCMD_SET_EHT_NON_ADVERTISED,
  MXL_NL80211_VENDOR_SUBCMD_GET_EHT_NON_ADVERTISED,
  MXL_NL80211_VENDOR_SUBCMD_GET_LOGGER_FIFO_MUX_CFG,
  MXL_NL80211_VENDOR_SUBCMD_SET_LOGGER_FIFO_MUX_CFG,
  LTQ_NL80211_VENDOR_SUBCMD_SETUP_MLD,
  LTQ_NL80211_VENDOR_SUBCMD_SET_MLD_INFO,
  LTQ_NL80211_VENDOR_SUBCMD_REQUEST_ML_SID,
  LTQ_NL80211_VENDOR_SUBCMD_SET_ML_SID,
  LTQ_NL80211_VENDOR_SUBCMD_ML_STA_ADD,
  LTQ_NL80211_VENDOR_SUBCMD_FREE_STA,
  LTQ_NL80211_VENDOR_SUBCMD_ML_SET_MAIN_VAPID,
  LTQ_NL80211_VENDOR_SUBCMD_MLD_REMOVE,
  LTQ_NL80211_VENDOR_SUBCMD_REMOVE_STA_MLD,
  LTQ_NL80211_VENDOR_SUBCMD_SET_ML_STA_LINK,
  LTQ_NL80211_VENDOR_SUBCMD_GET_ML_STA_LINK,
  LTQ_NL80211_VENDOR_SUBCMD_GET_CSI_CAPABILITY,
  LTQ_NL80211_VENDOR_SUBCMD_SET_PROBEREQ_OFFLOAD_MODE,
  LTQ_NL80211_VENDOR_SUBCMD_GET_PROP_PHY_CAP,
  LTQ_NL80211_VENDOR_SUBCMD_SET_MU_GROUPS_CONFIG,
  LTQ_NL80211_VENDOR_SUBCMD_GET_MU_GROUPS_CONFIG,
  LTQ_NL80211_VENDOR_SUBCMD_GET_OBSS_BSSCOLOR_INFO,
  LTQ_NL80211_VENDOR_SUBCMD_SET_BSS_CRITICAL_UPDATE_INFO,
  LTQ_NL80211_VENDOR_SUBCMD_GET_LA_MU_HE_EHT_STATS,
  LTQ_NL80211_VENDOR_SUBCMD_SET_DYNAMIC_WMM,
  LTQ_NL80211_VENDOR_SUBCMD_GET_RADIO_PEER_LIST,
  LTQ_NL80211_VENDOR_SUBCMD_GET_LINK_ADAPT_MIMO_OFDMA_STATS,
  LTQ_NL80211_VENDOR_SUBCMD_SCS_ADD_REQ,
  LTQ_NL80211_VENDOR_SUBCMD_SCS_REM_REQ,
  LTQ_NL80211_VENDOR_SUBCMD_GET_LINK_ADAPT_MU_GROUPS_COUNTERS_STATS,
  LTQ_NL80211_VENDOR_SUBCMD_ML_SEND_T2LM_TEARDOWN_FRAME,
  LTQ_NL80211_VENDOR_SUBCMD_GET_ML_LINK_STATS,
  LTQ_NL80211_VENDOR_SUBCMD_SET_ML_LINK_STATS,
  LTQ_NL80211_VENDOR_SUBCMD_GET_ML_VAP_LIST,
  LTQ_NL80211_VENDOR_SUBCMD_SET_DYNAMIC_EDCA,
  LTQ_NL80211_VENDOR_SUBCMD_SET_STR_TID_LINK_SPREADING,
  LTQ_NL80211_VENDOR_SUBCMD_REG_UPDATE_6GHZ_OPER_POWER_MODE,
  LTQ_NL80211_VENDOR_SUBCMD_UPDATE_AFC_INFO,
  LTQ_NL80211_VENDOR_SUBCMD_ML_STA_REASSOC_NOTIFY,
  LTQ_NL80211_VENDOR_SUBCMD_GET_ML_PEER_FLOW_STATUS,
  LTQ_NL80211_VENDOR_SUBCMD_GET_ML_STA_LIST,
  LTQ_NL80211_VENDOR_SUBCMD_SET_RADAR_FIFO_DUMP,
  LTQ_NL80211_VENDOR_SUBCMD_SET_DUPLICATE_BEACON,
  LTQ_NL80211_VENDOR_SUBCMD_GET_PCIE_AUTO_GEN_ENABLE,
  LTQ_NL80211_VENDOR_SUBCMD_SET_PCIE_AUTO_GEN_ENABLE,
  LTQ_NL80211_VENDOR_SUBCMD_SET_VW_TEST_MODE,
  LTQ_NL80211_VENDOR_SUBCMD_GET_VW_TEST_MODE,
  /* add new iw sub commands here */

  /* used to define LTQ_NL80211_VENDOR_SUBCMD_MAX below */
  __LTQ_NL80211_VENDOR_SUBCMD_AFTER_LAST,
  LTQ_NL80211_VENDOR_SUBCMD_MAX = __LTQ_NL80211_VENDOR_SUBCMD_AFTER_LAST - 1

};

enum ltq_nl80211_vendor_events {
  LTQ_NL80211_VENDOR_EVENT_RX_EAPOL            = 0,
  LTQ_NL80211_VENDOR_EVENT_FLUSH_STATIONS      = 1,
  LTQ_NL80211_VENDOR_EVENT_CHAN_DATA           = 2,
  LTQ_NL80211_VENDOR_EVENT_UNCONNECTED_STA     = 3,
  LTQ_NL80211_VENDOR_EVENT_WDS_CONNECT         = 4,
  LTQ_NL80211_VENDOR_EVENT_WDS_DISCONNECT      = 5,
  LTQ_NL80211_VENDOR_EVENT_CSA_RECEIVED        = 6,
  LTQ_NL80211_VENDOR_EVENT_RADAR_DETECTED      = 7,
  LTQ_NL80211_VENDOR_EVENT_ASSERT_DUMP_READY   = 8,
  LTQ_NL80211_VENDOR_EVENT_NO_DUMP             = 9,
  LTQ_NL80211_VENDOR_EVENT_UNRECOVERABLE_ERROR = 10,
  LTQ_NL80211_VENDOR_EVENT_MAC_ERROR           = 11,
  LTQ_NL80211_VENDOR_EVENT_SOFTBLOCK_DROP      = 12,
  LTQ_NL80211_VENDOR_EVENT_CAL_FILE            = 13,
  LTQ_NL80211_VENDOR_EVENT_COC_BEACON_UPDATE   = 14,
  LTQ_NL80211_VENDOR_EVENT_WHM                 = 15,
  LTQ_NL80211_VENDOR_EVENT_CSI_STATS           = 16,
  LTQ_NL80211_VENDOR_EVENT_DYNAMIC_WMM_UPDATE  = 17,
  LTQ_NL80211_VENDOR_EVENT_REGDB_INFO_UPDATE   = 18,
};




/*******************************************************************************
*                           Command structures                                 *
*******************************************************************************/

#define COUNTRY_CODE_MAX_LEN                  3
/* Maximum possible number of antennas for statistics in driver */
#define WAVE_STAT_MAX_ANTENNAS                5
#define INTEL_CSA_DEAUTH_TX_TIME_ARR_SIZE     2
#define INTEL_CSA_DEAUTH_TX_TIME_UC_IDX       0
#define INTEL_CSA_DEAUTH_TX_TIME_MC_IDX       1
#define INTEL_MAX_PROTECTED_DEAUTH_FRAME_LEN  44
#define INTEL_NON_PROTECTED_DEAUTH_FRAME_LEN  26

enum {
  CSA_DEAUTH_MODE_DISABLED = 0,
  CSA_DEAUTH_MODE_UNICAST,
  CSA_DEAUTH_MODE_BROADCAST
};

struct intel_vendor_initial_data_cfg
{
  char  alpha2[COUNTRY_CODE_MAX_LEN];
  u8  is_11b;
  u8  radar_detection;
  u8  ieee80211n_acax_compat;
} __attribute__ ((packed));

struct intel_vendor_blacklist_cfg {
  DEF_IEEE_ADDR(addr);
  u16 status;
  u8 remove;
  u8 snrProbeHWM;
  u8 snrProbeLWM;
} __attribute__ ((packed));

struct intel_vendor_steer_cfg {
  DEF_IEEE_ADDR(addr);
  DEF_IEEE_ADDR(bssid);
  u16 status;
} __attribute__ ((packed));

struct intel_vendor_unconnected_sta_req_cfg {
  u32 bandwidth;
  u32 freq;
  u32 center_freq1;
  u32 center_freq2;
  DEF_IEEE_ADDR(addr);
} __attribute__ ((packed));

struct intel_vendor_sta_info { /* corresponds to vendor_sta_info in Driver */
  u32 StationId;
  u32 NetModesSupported;
  u64 BytesSent;        /* Peer traffic */
  u64 BytesReceived;
  u64 PacketsSent;
  u64 PacketsReceived;
  u32 RetransCount;
  u32 FailedRetransCount;
  u32 RetryCount;
  u32 LastDataUplinkRate;   /* Kbps */
  u32 LastDataDownlinkRate; /* Kbps */
  u32 MaxRate;              /* Kbps */
  u32 ErrorsSent;
  u32 RateInfoFlag; /* Is rate info valid */
  u32 RatePhyMode;  /* Network (Phy) Mode */
  u32 RateCbwMHz;   /* BW [MHz] */
  u32 RateMcs;      /* MCS index */
  u32 RateNss;      /* NSS */
  s8  snr[WAVE_STAT_MAX_ANTENNAS];
  s8  ShortTermRSSIAverage[WAVE_STAT_MAX_ANTENNAS];
  s32 SignalStrength;
  u32 TxMgmtPwr;
  u32 TxStbcMode;
} __attribute__ ((packed));

struct intel_vendor_traffic_stats {
  u64 BytesSent;
  u64 BytesReceived;
  u64 PacketsSent;
  u64 PacketsReceived;
  u32 UnicastPacketsSent;
  u32 UnicastPacketsReceived;
  u32 MulticastPacketsSent;
  u32 MulticastPacketsReceived;
  u32 BroadcastPacketsSent;
  u32 BroadcastPacketsReceived;
} __attribute__ ((packed));

struct intel_vendor_error_stats {
  u32 ErrorsSent;
  u32 ErrorsReceived;
  u32 DiscardPacketsSent;
  u32 DiscardPacketsReceived;
} __attribute__ ((packed));

struct intel_vendor_vap_info {
  struct intel_vendor_traffic_stats traffic_stats;
  struct intel_vendor_error_stats   error_stats;
  u32 RetransCount;
  u32 FailedRetransCount;
  u32 RetryCount;
  u32 MultipleRetryCount;
  u32 ACKFailureCount;
  u32 AggregatedPacketCount;
  u32 UnknownProtoPacketsReceived;
  u64 TransmittedOctetsInAMSDUCount;
  u64 ReceivedOctetsInAMSDUCount;
  u64 TransmittedOctetsInAMPDUCount;
  u64 ReceivedOctetsInAMPDUCount;
  u32 RTSSuccessCount;
  u32 RTSFailureCount;
  u32 TransmittedAMSDUCount;
  u32 FailedAMSDUCount;
  u32 AMSDUAckFailureCount;
  u32 ReceivedAMSDUCount;
  u32 TransmittedAMPDUCount;
  u32 TransmittedMPDUsInAMPDUCount;
  u32 AMPDUReceivedCount;
  u32 MPDUInReceivedAMPDUCount;
  u32 ImplicitBARFailureCount;
  u32 ExplicitBARFailureCount;
  u32 TwentyMHzFrameTransmittedCount;
  u32 FortyMHzFrameTransmittedCount;
  u32 SwitchChannel20To40;
  u32 SwitchChannel40To20;
  u32 FrameDuplicateCount;
} __attribute__ ((packed));

struct intel_vendor_radio_info {
  struct intel_vendor_traffic_stats traffic_stats;
  struct intel_vendor_error_stats error_stats;
  u8 Enable;
  u8 Channel;
  u32 FCSErrorCount;
  s32 Noise;
  u64 tsf_start_time;
  u8 load;
  u32 tx_pwr_cfg;
  u8 num_tx_antennas;
  u8 num_rx_antennas;
  u32 primary_center_freq; /* center frequency in MHz */
  u32 center_freq1;
  u32 center_freq2;
  u32 width; /* 20,40,80,... */
} __attribute__ ((packed));

/* ATF: Air Time Fairness (a variable length message) */
struct intel_vendor_sta_grant {
  u16 sid;
  u16 grant;
} __attribute__ ((packed));

struct intel_vendor_atf_quotas {
  u8 debug;
  u8 distr_type;    /* disabled / dynamic / static */
  u8 algo_type;     /* global or weighted */
  u8 weighted_type; /* PER_STATION / PER_STATION_PER_AC / PER_VAP / ... */
  u32 interval;     /* in microseconds */
  u32 free_time;    /* in microseconds */
  u16 nof_bss;      /* number of BSSes - keep for debug */
  u16 nof_sta;      /* cfg param: ap_max_num_sta */
  u16 nof_grants;   /* number of elements in sta_grant[] array */
  u16 data_len;     /* sizeof sta_grant[] array in bytes */
  struct intel_vendor_sta_grant sta_grant[0];  /* SID and STA grant[nof_sta]; */
} __attribute__ ((packed));

struct intel_vendor_mac_addr_list_cfg {
  DEF_IEEE_ADDR(addr);
  u8 remove;
} __attribute__ ((packed));

/* Data for channel switch vendor implementation */
struct intel_vendor_channel_switch_cfg {
  u8 csaDeauthMode; /* 0-disabled, 1-unicast, 2-multicast */
  u8 csaMcDeauthFrameLength; /* Length of deauth frame per VAP */
  u16 csaDeauthTxTime[INTEL_CSA_DEAUTH_TX_TIME_ARR_SIZE]; /* Unicast and multicast deauth frame transmit time */
  u8 csaDeauthFrames[INTEL_MAX_PROTECTED_DEAUTH_FRAME_LEN]; /* Deauth frames (optionally encrypted) per VAP */
} __attribute__ ((packed));

/* TPE IE in FILS Discovery frames       */
/* Only one Max Transmit PSD is included */
struct intel_vendor_fd_tpe_ie {
	u8 elem_id;
	u8 len;
	u8 transmit_power_info;
	u8 max_transmit_psd;
} __attribute__ ((packed));

/* FILS Discovery info structure: Refer Sec 9.6.7.36 FILS Discovery Frame format in the latest 11AX standard *
 * CAUTION: The order of the sub fields and IEs is IMPORTANT. Maintain the below order while adding/deleting *
 *** Mandatory sub fields in FILS Discovery Information field                                                *
 * FILS Discovery Frame Control | Timestamp | Beacon Interval | SSID/Short SSID                              *
 *** Optional sub fields in FILS Discovery Information field                                                 *
 * Length | FD Capability | Operating Class | Primary Channel | AP Configuration Sequence Number |           *
 * Access Network Options | FD RSN Information | Channel Center Frequency Segment 1 | Mobility Domain        *
 ***Optional IEs in a FILS Discovery frame                                                                   *
 * Reduced Neighbor Report element | FILS Indication element | Roaming Consortium element | TIM element |    *
 * TWT element | OPS element | Transmit Power Envelope element                                               */

struct intel_vendor_fils_discovery_info {
  u16 fils_discovery_frame_control;
  u64 timestamp;
  u16 beacon_int;
  u8 short_ssid[4];
  u8 length;
  u8 op_class;
  u8 primary_chan;
  struct intel_vendor_fd_tpe_ie tpe_ie;
} __attribute__ ((packed));

struct intel_vendor_probe_req_info {
  DEF_IEEE_ADDR(addr);
  u16 age;
  s8 rssi;
} __attribute__ ((packed));

/* SoftBlock Timer ACL configuration */
struct intel_vendor_sb_timer_acl_cfg {
  int timer_acl_on;
  int timer_acl_probe_drop;
} __attribute__ ((packed));

/* Data for LTQ_NL80211_VENDOR_SUBCMD_SET_HE_DEBUG_DATA,
 *          LTQ_NL80211_VENDOR_SUBCMD_SET_HE_NON_ADVERTISED and
 *          LTQ_NL80211_VENDOR_SUBCMD_GET_HE_NON_ADVERTISED vendor commands */
struct intel_vendor_he_capa {
  u8 he_mac_capab_info[6];
  u8 he_phy_capab_info[11];
  u8 he_txrx_mcs_support[12];
  u8 he_ppe_thresholds[25];
} __attribute__ ((packed));


/* Data for LTQ_NL80211_VENDOR_SUBCMD_GET_HE_OPERATION vendor commands */
struct intel_vendor_he_oper {
  u8 he_oper_params[3];
  u8 he_bss_color_info;
  u8 he_mcs_nss_set[2];
  u8 vht_oper_info[3];
  u8 co_hosted_bss;
  u8 oper_6GHz_info[5];
} __attribute__ ((packed));

/* Data for MXL_NL80211_VENDOR_SUBCMD_SET_EHT_DEBUG_DATA,
 *          MXL_NL80211_VENDOR_SUBCMD_SET_EHT_NON_ADVERTISED and
 *          MXL_NL80211_VENDOR_SUBCMD_GET_EHT_NON_ADVERTISED vendor commands */
struct mxl_vendor_eht_capa {
  u8 eht_mac_capab_info[2];
  u8 eht_phy_capab_info[9];
  u8 eht_txrx_mcs_support[9];
  u8 eht_ppe_thresholds[32];
} __attribute__ ((packed));

/* Data for MXL_NL80211_VENDOR_SUBCMD_SET_EHT_OPERATION and
 *          MXL_NL80211_VENDOR_SUBCMD_GET_EHT_OPERATION vendor commands */
struct mxl_vendor_eht_oper {
  u8 eht_op_params;
  u8 eht_mcs_nss_set[4];
  u8 eht_channel_width;
  u8 eht_ccfs0;
  u8 eht_ccfs1;
  u8 eht_disable_subch_bitmap[2];
} __attribute__ ((packed));

/* Data for LTQ_NL80211_VENDOR_SUBCMD_GET_PROP_PHY_CAP vendor command */
struct mxl_vendor_prop_phy_cap {
  u32 ht_bf;
} __attribute__ ((packed));

/* Data for LTQ_NL80211_VENDOR_SUBCMD_GET_ML_LINKSWITCH_STATS */
typedef enum {
  MLD_MAIN_LINK,
  MLD_SECONDARY_LINK,
  MLD_MAX_ACTIVE_LINKS,
}mld_active_links;

struct ml_link_stats {
  u32 link_active_time[MLD_MAX_ACTIVE_LINKS]; /* In usec */
  u8 current_ml_operating_mode;
  u8 main_band;
  u8 secondary_band;
} __attribute__ ((packed));

struct ml_vap_list {
  int mld_id;
  u8 ifname[MLD_MAX_ACTIVE_LINKS][IFNAMSIZ + 1];
  u8 ssid[33];
  DEF_IEEE_ADDR(mld_addr);
} __attribute__ ((packed));

/*******************************************************************************
*                           Event structures                                   *
*******************************************************************************/

/* Data for EVENT_LTQ_CHAN_DATA events */
struct intel_vendor_channel_data
{
  u32 channel;
  int BW;
  u32 primary;
  u32 secondary;
  u32 freq;
  u32 load;
  u32 busy_time;
  u32 total_time;
  u32 calibration; /* success mask */
  u32 num_bss;
  u32 dynBW20;
  u32 dynBW40;
  u32 dynBW80;
  u32 dynBW160;
  u32 tx_power;
  int rssi;
  u32 snr;
  int cwi_noise;
  u32 not_80211_rx_evt; /* Used only by legacy statistcis */
  u32 ext_sta_rx;

  u32 filled_mask;
} __attribute__ ((packed));

/* Data for EVENT_LTQ_UNCONNECTED_STA_RX events */
struct intel_vendor_unconnected_sta {
  u64 rx_bytes;
  u32 rx_packets;
  s8 rssi[WAVE_STAT_MAX_ANTENNAS];
  DEF_IEEE_ADDR(addr);
  s8 noise[WAVE_STAT_MAX_ANTENNAS];
  u16 rate;
} __attribute__ ((packed));

/* Data for EVENT_LTQ_WDS_CONNECT and EVENT_LTQ_WDS_DISCONNECT */
struct intel_vendor_wds_sta_info {
  char ifname[IFNAMSIZ + 1];
  u32 max_rssi;
  u32 sta_flags_mask;
  u32 sta_flags_set;
  size_t assoc_req_ies_len;
  u16 beacon_interval;
  DEF_IEEE_ADDR(mac_addr);
  u8 dtim_period;
  u8 protection;
  u8 short_preamble;
  u8 short_slot_time;
  u8 assoc_req_ies[0];
} __attribute__ ((packed));

/* Data for EVENT_LTQ_CSA_RECEIVED */
struct intel_vendor_csa_received {
  u32 bandwidth;
  u32 freq;
  u32 center_freq1;
  u32 center_freq2;
  u32 count; /* the number of TBTT's until the channel switch event */
} __attribute__ ((packed));

/* Data for EVENT_LTQ_RADAR events */
struct intel_vendor_radar {
  s32 width; /* enum nl80211_chan_width (drv) -> enum chan_width (hostap) */
  u32 center_freq;
  u32 center_freq1;
  u32 center_freq2;
  u8 radar_bit_map;
} __attribute__ ((packed));

/* Data for EVENT_LTQ_COC events */
struct intel_vendor_event_coc {
  u8 coc_BW;
  u8 coc_omn_IE;
  u8 coc_is_max_nss;
} __attribute__ ((packed));

/* Data for EVENT_LTQ_WMM events */
#define MAX_AC_PRIORITIES 4
struct intel_vendor_wmm_info {
  u16 txop_limit;
  u8  cwmin;
  u8  cwmax;
  u8  aifs;
} __attribute__ ((packed));

struct intel_vendor_event_wmm {
  struct intel_vendor_wmm_info ac_info[MAX_AC_PRIORITIES];
} __attribute__ ((packed));

/* Data for EVENT_LTQ_SOFTBLOCK events */
struct intel_vendor_event_msg_drop {
  DEF_IEEE_ADDR(addr);          /**< Client MAC Address         */
  DEF_IEEE_ADDR(bssid);         /**< bssid of the vap           */
  u8 msgtype;                   /**  Msgtype                    */
  u8 rx_snr;                    /**< SNR in DB                  */
  u8 blocked;                   /**< True if response blocked   */
  u8 rejected;                  /**< True if Auth Resp with rejection sent to STA       */
  u8 broadcast;                 /**< True if broadcast probe    */
  u8 reason;                    /**< Ignore for Probe Req       */
} __attribute__ ((packed));

/* Data for CCA measurements */
struct intel_vendor_cca_msr_cfg {
  u32 channel;
  u32 duration;
} __attribute__ ((packed));

/* Data for WHM warningID */
typedef enum {
  WHM_DRV_MAC_FATAL = 1,
  WHM_DRV_STA_DISCONNECT,
  WHM_DRV_TX_STALL,
  WHM_DRV_RX_STALL,
  /* Add new driver warnings here */
  WHM_HOSTAP_SAMPLE = 51,
  WHM_HOSTAP_ACS_FAILURE,
  WHM_HOSTAP_IFDOWN,
  /* Add new hostap warnings here */
  WHM_WARNING_TRIGGER_BY_IW = 101,
  WHM_IW_IFDOWN
  /* Add new IW warnings here */
}whm_warning_id;

typedef enum {
  WHM_HOSTAPD_TRIGGER = 1,
  WHM_DRIVER_TRIGGER,
  WHM_FW_TRIGGER,
  WHM_IW_TRIGGER,
  WHM_PHY_TRIGGER
}whm_warning_layer;

struct intel_vendor_whm_event_cfg {
  whm_warning_id    warning_id;
  whm_warning_layer warning_layer;
  u32               num_cards;
} __attribute__ ((packed));

/* Data for dump handler */
struct intel_vendor_fw_dump_ready_info {
  u32 card_idx;
} __attribute__ ((packed));

struct intel_vendor_unrecoverable_error_info {
  u32 card_idx;
} __attribute__ ((packed));

/* Data for reset_statistics */
struct intel_vendor_reset_statistics {
  u32 category;
  DEF_IEEE_ADDR(addr);
} __attribute__ ((packed));

/* Broadcast TWT configuration vendor structure */
#define MAX_NUM_BCAST_TWT_SP_TO_ADD 8
struct _mxl_vendor_btwt_params_t {
  u32 broadcast_twt_id;
  u32 flow_type;
  u32 trigger;
  u32 twt_wake_duration;
  u32 twt_wake_interval_mantissa;
  u32 wake_interval_exp;
} __attribute__ ((packed));

struct _mxl_vendor_bcast_twt_config_t {
  u32 number_of_sps_to_add;
  u32 wake_duration_unit;
  struct _mxl_vendor_btwt_params_t btwt_params[MAX_NUM_BCAST_TWT_SP_TO_ADD];
} __attribute__ ((packed));

/* MLO params */
#define MAX_NUM_OF_LINKS          3
#define INVALID_LINK_ID          15
#define LINK_ID_6G                2
#define LINK_ID_5G                1
#define LINK_ID_2G                0

struct _mxl_vendor_mld_info {
  int mld_id;
  u8 ap_mld_mac[ETH_ALEN];
  u8 link1_bssid[ETH_ALEN];
  u8 link2_vapid;
} __attribute__ ((packed));

struct _mxl_vendor_mld_link_info {
  int mld_id;
  u8 ap_mld_mac[ETH_ALEN];
} __attribute__ ((packed));

struct mxl_vendor_ml_sid {
  u16 sid[3];
} __attribute__ ((packed));

struct mxl_ml_sta_info {
  u8 addr[ETH_ALEN];
  u16 sid;
  u16 aid;
} __attribute__ ((packed));

struct mxl_ml_sta_mac_addr {
  u8 addr1[ETH_ALEN];
  u8 addr2[ETH_ALEN];
  u8 addr3[ETH_ALEN];
  u8 assoc_link_bitmap;
} __attribute__ ((packed));

struct mxl_ml_sta_add_param {
  u8 sta_addr1[ETH_ALEN];
  u8 sta_addr2[ETH_ALEN];
  u8 sta_addr3[ETH_ALEN];
  u8 mld_mac_addr[ETH_ALEN];
  u8 assoc_link_bitmap;
  u16 eml_capab;
  u8 num_of_sim_links;
  u8 mld_id;
  u16 aid;
} __attribute__ ((packed));

struct mxl_ml_mainVapId {
  u8 sta_addr[ETH_ALEN];
  u8 mainVapId;
} __attribute__ ((packed));

struct mxl_mld_remove {
  u8 mld_id;
  u8 sendto_fw;
} __attribute__ ((packed));

struct mxl_sta_mld_remove {
  u16 aid;
  u8 sendto_fw;
} __attribute__ ((packed));

struct mxl_vendor_ml_critical_update {
  u8  flags;
  u8  op_class;
  u32 max_chan_switch_time;
} __attribute__ ((packed));

struct mxl_scs_add_req {
  u16 aid;
  u8  status;
  u8  scsid;
  u32 tid;
  u32 userPrio;
  u32 linkId;
  u32 minServiceInterval;
  u32 maxServiceInterval;
  u32 minDataRate;
  u32 bitmapNextParamPresence; // Bitmap to indicate presence (in the SCS original frame) of the below parameters
  u32 delayBound;
  u32 maxMsduSize;
  u32 serviceStartTime;
  u32 serviceStartTimeLinkId;
  u32 meanDataRate;
  u32 burstSize;
  u16 msduLifeTime;
  u8  msduDeliveryRatio;
  u8  msduCountExponent;
  u16 mediumTime;
}__attribute__ ((packed));

struct mxl_scs_rem_req {
  u16 aid;
  u8 status;
  u8 scsid;
}__attribute__ ((packed));

struct mxl_ml_sta_t2lm_teardown {
  u16 aid;
} __attribute__ ((packed));

enum {
  AFC_UPDATE_STATUS_DEFAULT = 0,
  AFC_UPDATE_STATUS_SERVER,
};

/* Data for CMD_REG_UPDATE_6GHZ_OPER_POWER_MODE and EVENT_LTQ_REGDB_UPDATE */
struct mxl_update_power_reg_info {
  u8 flags;
  u8 oper_power_mode;
  u8 curr_power_mode;
} __attribute__ ((packed));

typedef struct wave_radio_reg_data {
  const struct ieee80211_regdomain *regd;
  u8 flags;
} wave_radio_reg_data_t;

struct mxl_ml_sta_reassoc_notify {
  u16 aid;
} __attribute__ ((packed));

/* Data for LTQ_NL80211_VENDOR_SUBCMD_GET_ML_STA_LIST */
struct mxl_ml_sta_list {
  char ifname [MLD_MAX_ACTIVE_LINKS][IFNAMSIZ + 1];
  u8 is_single_link;
  u8 supported_mode;
  u16 aid;
  u16 sid[MLD_MAX_ACTIVE_LINKS];
  DEF_IEEE_ADDR(mld_addr);
  DEF_IEEE_ADDR(sta_addr[MLD_MAX_ACTIVE_LINKS]);
} __attribute__ ((packed));
#endif /* _VENDOR_CMDS_H_ */
