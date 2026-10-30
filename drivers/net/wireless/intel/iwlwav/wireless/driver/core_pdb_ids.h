/******************************************************************************

         Copyright (c) 2026, MaxLinear, Inc.

  For licensing information, see the file 'LICENSE' in the root folder of
  this software module.

*******************************************************************************/

/*
 * Core (per VAP) ParamDB parameter ids, one PDB_ID() per parameter.
 *
 * Included twice: mtlk_param_db.h expands this list into the enum,
 * mtlk_param_db.c into the id -> name table the logs print. The includer
 * defines PDB_ID and PDB_ID_VAL first and undefines them after, so one
 * list feeds both. After adding a parameter here, add its initial value
 * to core_pdb_def.h above the *_LAST_VALUE_ID row: a parameter with no row
 * there is never initialised.
 *
 * No include guard on purpose: this list is included twice per translation unit.
 */

#if !defined(PDB_ID) || !defined(PDB_ID_VAL)
#error "core_pdb_ids.h is an id list; include it with PDB_ID and PDB_ID_VAL defined"
#endif
PDB_ID_VAL(PARAM_DB_CORE_ARP_PROXY, 0)                     /*!< HS20  */
PDB_ID(PARAM_DB_CORE_BRIDGE_MODE)                          /*!< Core Hot-Path (H-P) parameter  */
PDB_ID(PARAM_DB_CORE_AP_FORWARDING)                        /*!< Core H-P parameter  */
PDB_ID(PARAM_DB_CORE_MAC_ADDR)                             /*!< Core H-P parameter  */
PDB_ID(PARAM_DB_CORE_RELIABLE_MCAST)                       /*!< Core H-P parameter - Enable/disable Reliable Multicast */
PDB_ID(PARAM_DB_CORE_BSSID)                                /*!< Core H-P parameter - BSSID */
PDB_ID(PARAM_DB_CORE_STA_FORCE_SPECTRUM_MODE)              /*!< Core parameter  */
PDB_ID(PARAM_DB_CORE_NICK_NAME)                            /*!< Core parameter - IW Nick name */
PDB_ID(PARAM_DB_CORE_ESSID)                                /*!< Core parameter - ESSID */
PDB_ID(PARAM_DB_CORE_NET_MODE_CFG)                         /*!< Core parameter - configured Network mode*/
PDB_ID(PARAM_DB_CORE_NET_MODE_CUR)                         /*!< Core parameter - current Network mode*/
PDB_ID(PARAM_DB_CORE_HIDDEN_SSID)                          /*!< use hidden_ssid from hostapd */
PDB_ID(PARAM_DB_CORE_BASIC_RATES_2)                        /*!< basic rates from hostapd for 2.4 GHz*/
PDB_ID(PARAM_DB_CORE_BASIC_RATES_5)                        /*!< basic rates from hostapd for 5 GHz*/
PDB_ID(PARAM_DB_CORE_RX_MCS_BITMASK)                       /*!< RX MCS bitmask from the beacon */
PDB_ID(PARAM_DB_CORE_VHT_MCS_NSS)                          /*!< VHT_MCS_NSS from the beacon */
PDB_ID(PARAM_DB_CORE_HE_MCS_NSS)                           /*!< HE_MCS_NSS from the beacon */
PDB_ID(PARAM_DB_CORE_HE_OPERATION)                         /*!< HE_OPERATION from the beacon */
PDB_ID(PARAM_DB_CORE_SET_BSS_FLAGS)                        /*!< additional flags to set at SET_BSS time */
/* Note---these have to come in the same order as AC queue defines in enum UMI_AC */
PDB_ID(PARAM_DB_CORE_WMM_PARAMS_BE)                        /*!< WMM parameters for AC BE from hostapd */
PDB_ID(PARAM_DB_CORE_WMM_PARAMS_BK)                        /*!< WMM parameters for AC BK from hostapd */
PDB_ID(PARAM_DB_CORE_WMM_PARAMS_VI)                        /*!< WMM parameters for AC VI from hostapd */
PDB_ID(PARAM_DB_CORE_WMM_PARAMS_VO)                        /*!< WMM parameters for AC V0 from hostapd */
PDB_ID(PARAM_DB_CORE_IS_BSS_LOAD_ENABLE)                   /*!< is bss load ie enable value */
PDB_ID(PARAM_DB_CORE_ADMISSION_CAPACITY)                   /*!< available admiision capacity value for bss load ie*/
PDB_ID(PARAM_DB_CORE_STA_LIMIT_MIN)
PDB_ID(PARAM_DB_CORE_STA_LIMIT_MAX)
/* RX Threshold */
PDB_ID(PARAM_DB_CORE_RX_THRESHOLD)                         /*!< Mirror of FW's "Set High Reception Threshold": UMI_RX_TH.rxThValue */
/* Aggregation configuration */
PDB_ID(PARAM_DB_CORE_AMSDU_MODE)                           /*!< AMSDU mode */
PDB_ID(PARAM_DB_CORE_BA_MODE)                              /*!< BA mode */
PDB_ID(PARAM_DB_CORE_WINDOW_SIZE)                          /*!< Dynamic window size */
PDB_ID(PARAM_DB_CORE_TWT_OPERATION_MODE)                   /*!< TWT operation mode */
PDB_ID(PARAM_DB_CORE_IWPRIV_FORCED)                        /*!< core parameter - settings, forced by iwpriv call */
PDB_ID(PARAM_DB_CORE_HT_PROTECTION)                        /*!< Protection method */
PDB_ID(PARAM_DB_CORE_MULTI_AP_MODE)                        /*!< Multi-AP mode for the current AP */
PDB_ID(PARAM_DB_CORE_DTIM_PERIOD)                          /*!< DTIM_PERIOD */
PDB_ID(PARAM_DB_CORE_MBSSID_VAP)                           /*!< Set MBSSID VAP */
PDB_ID(PARAM_DB_CORE_MBSSID_NUM_VAPS_IN_GROUP)             /*!< Set MBSSID number of VAPs in group */
PDB_ID(PARAM_DB_CORE_SOFTBLOCK_DISABLE)                    /*!< Set softblock disable */
PDB_ID(PARAM_DB_CORE_MGMT_FRAMES_RATE)                     /*!< Management frames rate */
PDB_ID(PARAM_DB_CORE_BEACON_PERIOD)                        /*!< MIB_BEACON_PERIOD */
PDB_ID(PARAM_DB_CORE_HE_NON_ADVERTISED)                    /*!< Non advertised HE capabilities */
PDB_ID(PARAM_DB_CORE_CSA_DEAUTH_PARAMS)                    /*!< CSA deauth multicast frames data */
PDB_ID(PARAM_DB_CORE_RNR_6G_SHORT_SSID_LIST)               /*!< 6GHz VAPs Short SSID List */
PDB_ID(PARAM_DB_CORE_RNR_6G_SHORT_SSID_COUNT)              /*!< 6GHz VAPs Short SSID List size */
PDB_ID(PARAM_DB_CORE_HE_DEBUG_DATA)                        /*!< HE debug data */
PDB_ID(PARAM_DB_CORE_HE_BEACON)                            /*!< Beacon in HE SU PPDU format */
PDB_ID(PARAM_DB_CORE_SHORT_SSID)                           /*!< Computed Short SSID */
PDB_ID(PARAM_DB_CORE_FWRD_UNKWN_MCAST_FLAG)                /*!< Core H-P parameter - unknown multicast filter mode */
PDB_ID(PARAM_DB_CORE_BCAST_TWT_OPERATION_MODE)             /*!< Broadcast TWT operation mode */
PDB_ID(PARAM_DB_CORE_BCAST_TWT_CONFIG)                     /*!< Broadcast TWT schedule(s) advertised */
PDB_ID(PARAM_DB_CORE_DUPLICATE_BEACON_ENABLED)             /*!< Duplicate Beacon enable/disable flag */
PDB_ID(PARAM_DB_CORE_DUPLICATE_BEACON_BW)                  /*!< Duplicate Beacon coresponding bw(if enabled) */
PDB_ID(PARAM_DB_CORE_PBAC)                                 /*!< PBAC - protected block ack capable */
/* SoftBlock timer ACL control for probe requests */
PDB_ID(PARAM_DB_CORE_SB_TIMER_ACL_ON)                      /*!< SoftBlock Timer ACL is ON */
PDB_ID(PARAM_DB_CORE_SB_TIMER_ACL_PROBE_DROP)              /*!< SoftBlock Timer ACL: drop all unicast probe requests */
PDB_ID(PARAM_DB_CORE_INTRA_VAP_MCAST)                      /*!< Intra VAP Multicast traffic handling */
PDB_ID(PARAM_DB_CORE_AP_RETRY_LIMIT_EXCE)                  /*!< AP retry limit value excessive */
PDB_ID(PARAM_DB_CORE_MGMT_PWR_CTRL)                        /*!< Management Frame Power Control */
PDB_ID(PARAM_DB_CORE_RSSI_IGNORE_PROBE_REQ)                /*!< RSSI Ignore probe response value*/
PDB_ID(PARAM_DB_CORE_ALLOW_3ADDR_MCAST)                    /*!< Repeater Mode 3-Address Multicast handling */
PDB_ID(PARAM_DB_CORE_HE_BSS_COLOR)                         /*!< b7 - BSS Color Disabled, b5-b0 HE BSS color */
PDB_ID(PARAM_DB_CORE_SET_BSS)                              /*!< AP set BSS parameters */
PDB_ID(PARAM_DB_CORE_PROBEREQ_OFFLOAD_MODE)                /*!< Disable probe request offload */
#ifdef MTLK_WAVE_700
PDB_ID(PARAM_DB_CORE_EHT_MCS_NSS)                          /*!< EHT_MCS_NSS from the 802.11BE beacon */
PDB_ID(PARAM_DB_CORE_EHT_OPERATION)                        /*!< EHT_OPERATION from the 802.11BE beacon */
PDB_ID(PARAM_DB_CORE_EHT_DEBUG_DATA)                       /*!< EHT Capabilities Debug Data */
PDB_ID(PARAM_DB_CORE_EHT_NON_ADVERTISED)                   /*!< Non advertised EHT capabilities */
/* MLD parameter */
PDB_ID(PARAM_DB_CORE_AP_MLD_MAC)                           /*!< AP MLD MAC address */
PDB_ID(PARAM_DB_CORE_MLD_ID)                               /*!< MLD ID */
PDB_ID(PARAM_DB_CORE_BSS_CRITICAL_UPDATE)                  /*!< save BSS critical update info */
PDB_ID(PARAM_DB_CORE_SKIP_SET_BEACON)                      /*!< save Skip set beacon info */
PDB_ID(PARAM_DB_CORE_MLD_INFO)                             /*!< MLD Info parameters received during the setup MLD */
PDB_ID(PARAM_DB_CORE_SCS_ENABLE)                           /*!< Enable/disable SCS */
#endif
PDB_ID(PARAM_DB_CORE_FIXED_RATE_THERMAL)                   /*!< Fixed rate thermal power */
PDB_ID(PARAM_DB_CORE_MSCS_ENABLE)                          /*!< Enable/disable MSCS */
