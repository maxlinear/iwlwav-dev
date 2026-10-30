/******************************************************************************

         Copyright (c) 2026, MaxLinear, Inc.

  For licensing information, see the file 'LICENSE' in the root folder of
  this software module.

*******************************************************************************/

/*
 * Radio (per radio) ParamDB parameter ids, one PDB_ID() per parameter.
 *
 * Included twice: mtlk_param_db.h expands this list into the enum,
 * mtlk_param_db.c into the id -> name table the logs print. The includer
 * defines PDB_ID and PDB_ID_VAL first and undefines them after, so one
 * list feeds both. After adding a parameter here, add its initial value
 * to radio_pdb_def.h above the *_LAST_VALUE_ID row: a parameter with no row
 * there is never initialised.
 *
 * No include guard on purpose: this list is included twice per translation unit.
 */

#if !defined(PDB_ID) || !defined(PDB_ID_VAL)
#error "radio_pdb_ids.h is an id list; include it with PDB_ID and PDB_ID_VAL defined"
#endif
PDB_ID_VAL(PARAM_DB_RADIO_TEST_PARAM0, PARAM_DB_CORE_LAST_VALUE_ID) /*!< Test parameter  */
PDB_ID(PARAM_DB_RADIO_TEST_PARAM1)                         /*!< Test parameter  */
PDB_ID(PARAM_DB_RADIO_TX_ANTENNAS)                         /*!< Radio MIB parameter - transmission antenna list*/
PDB_ID(PARAM_DB_RADIO_RX_ANTENNAS)                         /*!< Radio MIB parameter - reception antenna list*/
PDB_ID(PARAM_DB_RADIO_INTERFDET_THRESHOLD)                 /*!< notification threshold for firmware */
PDB_ID(PARAM_DB_RADIO_PROG_MODEL_SPECTRUM_MODE)            /*!< radio parameter  */
PDB_ID(PARAM_DB_RADIO_SPECTRUM_MODE)                       /*!< radio parameter - spectrum mode */
PDB_ID(PARAM_DB_RADIO_BONDING_MODE)                        /*!< radio parameter - bonding mode */
PDB_ID(PARAM_DB_RADIO_CHANNEL_CFG)                         /*!< radio parameter configured channel */
PDB_ID(PARAM_DB_RADIO_CHANNEL_CUR)                         /*!< radio parameter current channel*/
PDB_ID(PARAM_DB_RADIO_CHANNEL_PREV)                        /*!< radio parameter previous channel*/
PDB_ID(PARAM_DB_RADIO_POWER_SELECTION)                     /*!< radio parameter  */
/* probably move to per card or remove at all*/
PDB_ID(PARAM_DB_RADIO_MAC_SOFT_RESET_ENABLE)               /*!< radio parameter - MAC reset control: automatically on MAC assert/exception */
PDB_ID(PARAM_DB_RADIO_MAC_WATCHDOG_TIMER_TIMEOUT_MS)       /*!< radio parameter - set timeout for MAC watchdog message sending */
PDB_ID(PARAM_DB_RADIO_MAC_WATCHDOG_TIMER_PERIOD_MS)        /*!< radio parameter - set MAC watchdog checking timer period */
PDB_ID(PARAM_DB_RADIO_FREQ_BAND_CFG)                       /*!< radio parameter - configured Frequency band*/
PDB_ID(PARAM_DB_RADIO_FREQ_BAND_CUR)                       /*!< radio parameter - current Frequency band*/
PDB_ID(PARAM_DB_RADIO_TX_POWER_REG_LIM)                    /*!< radio parameter - TX power regulatory limit */
PDB_ID(PARAM_DB_RADIO_TX_POWER_PSD)                        /*!< radio parameter - TX power limit according to PSD per current BW */
PDB_ID(PARAM_DB_RADIO_BF_TX_POWER_PSD)                     /*!< radio parameter - BF TX power limit according to PSD per current BW */
PDB_ID(PARAM_DB_RADIO_TX_POWER_CFG)                        /*!< radio parameter - TX power limit configured per current BW */
PDB_ID(PARAM_DB_RADIO_BF_TX_POWER_CFG)                     /*!< radio parameter - BF TX power limit configured per current BW */
PDB_ID(PARAM_DB_RADIO_SHORT_CYCLIC_PREFIX)                 /*!< radio MIB parameter - use short cyclic prefix*/
PDB_ID(PARAM_DB_RADIO_POWER_INCREASE)                      /*!< radio MIB parameter - power increase vs duty circle*/
PDB_ID(PARAM_DB_RADIO_SM_ENABLE)                           /*!< radio MIB parameter - channel announcement enabled*/
PDB_ID(PARAM_DB_RADIO_STBC)                                /*!< MIB_USE_SPACE_TIME_BLOCK_CODE */
PDB_ID(PARAM_DB_RADIO_RTS_THRESH)                          /*!< MIB_RTS_THRESHOLD */
PDB_ID(PARAM_DB_RADIO_ADVANCED_CODING)                     /*!< MIB_ADVANCED_CODING_SUPPORTED */
PDB_ID(PARAM_DB_RADIO_OFDM_PROTECTION)                     /*!< MIB_OFDM_PROTECTION_METHOD */
PDB_ID(PARAM_DB_RADIO_OVERLAPPING_PROT)                    /*!<MIB_OVERLAPPING_PROTECTION_ENABLE */
PDB_ID(PARAM_DB_RADIO_MSDU_LIFETIME)                       /*!< MIB_TX_MSDU_LIFETIME */
PDB_ID(PARAM_DB_RADIO_POWER_LIMIT)                         /*!< UM_MAN_CHANGE_TX_POWER_LIMIT_REQ */
PDB_ID(PARAM_DB_RADIO_SHORT_PREAMBLE)                      /*!< use_short_preamble from hostapd */
PDB_ID(PARAM_DB_RADIO_SCAN_PARAMS)                         /*!< scan parameters (wait times, probe stuff, valid times */
PDB_ID(PARAM_DB_RADIO_SCAN_PARAMS_BG)                      /*!< scan parameters (wait times, probe stuff, chunk stuff */
PDB_ID(PARAM_DB_RADIO_SCAN_MODIFS)                         /*!< scan modifier flags */
PDB_ID(PARAM_DB_RADIO_SCAN_PAUSE_BG_CACHE)                 /*!< scan support bg scan pause */
PDB_ID(PARAM_DB_RADIO_11B_ANTSEL_RATE)
PDB_ID(PARAM_DB_RADIO_11B_ANTSEL_RXANT)
PDB_ID(PARAM_DB_RADIO_11B_ANTSEL_TXANT)
PDB_ID(PARAM_DB_RADIO_COUNTRY_CODE_ALPHA)                  /*!< country code as alpha */
PDB_ID(PARAM_DB_RADIO_CCA_THRESHOLD)                       /*!< CCA threshold */
PDB_ID(PARAM_DB_RADIO_CCA_ADAPT)                           /*!< CCA adaptive intervals */
PDB_ID(PARAM_DB_RADIO_TX_POWER_LIMIT_OFFSET)               /*!< Mirror of FW' "Set Power Limit": UMI_TX_POWER_LIMIT.powerLimitOffset */
PDB_ID(PARAM_DB_RADIO_TX_POWER_LIMIT_OFFSET_PREV)          /*!< Used to detect changes in Set Power Limit to force SET_CHAN request */
PDB_ID(PARAM_DB_RADIO_QAMPLUS_MODE)                        /*!< QAMplus mode */
PDB_ID(PARAM_DB_RADIO_MODE_CURRENT)                        /*!< Current actual radio mode */
PDB_ID(PARAM_DB_RADIO_MODE_REQUESTED)                      /*!< Requested radio mode */
PDB_ID(PARAM_DB_RADIO_MRU_TX_POWER_ENABLE)                 /*!< MRU TX Power Test Mode enabled */
PDB_ID(PARAM_DB_RADIO_ZWDFS_NOISE_SUPPRESS)                /*!< ZWDFS packet-noise suppression enable + threshold */
PDB_ID(PARAM_DB_RADIO_ACS_UPDATE_TO)                       /*!< AOCS update timeout */
PDB_ID(PARAM_DB_RADIO_MU_OPERATION)                        /*!< MU operation */
PDB_ID(PARAM_DB_RADIO_RADAR_RSSI_TH)                       /*!< Radar Detection RSSI threshold */
PDB_ID(PARAM_DB_RADIO_FILS_BEACON_FLAG)                    /*!< Fils Beacon Flag */
PDB_ID(PARAM_DB_RADIO_RTS_DYNAMIC_BW)                      /*!< Signaling of RTS frame with dynamic bw */
PDB_ID(PARAM_DB_RADIO_RTS_STATIC_BW)                       /*!< Signaling of RTS frame with static bw */
PDB_ID(PARAM_DB_RADIO_BF_MODE)                             /*!< Beamforming Mode */
PDB_ID(PARAM_DB_RADIO_ACTIVE_ANT_MASK)                     /*!< Active Antenna Mask */
PDB_ID(PARAM_DB_RADIO_TXOP_CFG)                            /*!< TXOP Parameters */
PDB_ID(PARAM_DB_RADIO_ONLINE_ACM)                          /*!< Radio parameter: online calibration algo mask*/
PDB_ID(PARAM_DB_RADIO_CALIBRATION_ALGO_MASK)               /*!< Radio parameter: offline calibration algo mask*/
PDB_ID(PARAM_DB_RADIO_AGG_RATE_LIMIT_MODE)                 /*!< Mirror of FW's Aggregation-Rate Limit: UMI_AGG_RATE_LIMIT.mode */
PDB_ID(PARAM_DB_RADIO_AGG_RATE_LIMIT_MAXRATE)              /*!< Mirror of FW's Aggregation-Rate Limit: UMI_AGG_RATE_LIMIT.maxRate */
PDB_ID(PARAM_DB_RADIO_DYNAMIC_MC_RATE_MODE)                /*!< Mirror of FW's Multicast Rate : UM_MAN_DMR_CONFIG_REQ.mode */
PDB_ID(PARAM_DB_RADIO_DYNAMIC_MC_RATE_MAXRATE)             /*!< Mirror of FW's Multicast Rate : UM_MAN_DMR_CONFIG_REQ.maxRate*/
PDB_ID(PARAM_DB_RADIO_COEX_MODE)                           /*!< 2.4 GHz Coex (BT, BLE, ZigBee) mode */
PDB_ID(PARAM_DB_RADIO_TPC_RESERVED)                        /*!< Radio parameter - TPC Reserved */
PDB_ID(PARAM_DB_RADIO_COEX_ACTIVE_TIME)                    /*!< 2.4 GHz Coex period of time [mSec] that WIFI is allowed to transmit */
PDB_ID(PARAM_DB_RADIO_COEX_INACTIVE_TIME)                  /*!< 2.4 GHz Coex period of time [mSec] that WIFI is not allowed to transmit */
PDB_ID(PARAM_DB_RADIO_COEX_CTS2SELF_ACTIVE)                /*!< 2.4 GHz Coex CTS2Self is activated - true (1), otherwise - false (0) */
PDB_ID(PARAM_DB_RADIO_TPC_LOOP_TYPE)                       /*!< Radio parameter - TPC loop type */
PDB_ID(PARAM_DB_RADIO_TPC_PW_LIMITS_PSD)                   /*!< Radio parameter - TPC power limits according to PSD for all BW */
PDB_ID(PARAM_DB_RADIO_CFG_PW_LIMITS_PSD)                   /*!< Radio parameter - TPC power limits according to PSD for all BW */
PDB_ID(PARAM_DB_RADIO_TPC_PW_LIMITS_CFG)                   /*!< Radio parameter - TPC power limits configured for all BW */
PDB_ID(PARAM_DB_RADIO_DFS_RADAR_DETECTION)                 /*!< DFS params */
PDB_ID(PARAM_DB_RADIO_RX_DUTY_CYCLE_ON_TIME)               /*!< Mirror of FW' "Set Reception Duty Cycle": UMI_RX_DUTY_CYCLE.onTime */
PDB_ID(PARAM_DB_RADIO_RX_DUTY_CYCLE_OFF_TIME)              /*!< Mirror of FW' "Set Reception Duty Cycle": UMI_RX_DUTY_CYCLE.offTime */
PDB_ID(PARAM_DB_RADIO_AMSDU_NUM)                           /*!< AMSDU num */
PDB_ID(PARAM_DB_RADIO_AMSDU_VNUM)                          /*!< AMSDU vnum */
PDB_ID(PARAM_DB_RADIO_AMSDU_HENUM)                         /*!< AMSDU henum */
#ifdef MTLK_WAVE_700
PDB_ID(PARAM_DB_RADIO_AMSDU_EHTNUM)                        /*!< AMSDU ehtnum */
#endif
PDB_ID(PARAM_DB_RADIO_MAX_MPDU_LENGTH)                     /*!< MAX MPDU length */
PDB_ID(PARAM_DB_RADIO_TF_PARAMS)                           /*!< Trigger frame params for WCS AX Demo */
PDB_ID(PARAM_DB_RADIO_SSB_MODE)                            /*!< SSB Mode */
PDB_ID(PARAM_DB_RADIO_SHORT_SLOT)                          /*!< use_short_slot_time from hostapd */
PDB_ID(PARAM_DB_RADIO_UNCONNECTED_STA_SCAN_TIME)           /*!< Unconnected STA scan time */
PDB_ID(PARAM_DB_RADIO_RESTRICTED_AC_MODE)                  /*!< Restricted AC Mode */
PDB_ID(PARAM_DB_RADIO_PD_THRESHOLD)                        /*!< PD Threshold */
PDB_ID(PARAM_DB_RADIO_FAST_DROP)                           /*!< Fast Drop */
PDB_ID(PARAM_DB_RADIO_WLAN_COUNTERS_SRC)                   /*!< WLAN counters source switch */
PDB_ID(PARAM_DB_RADIO_RTS_CUTOFF_POINT)                    /*!< RTS protection rate cuttoff point */
PDB_ID(PARAM_DB_RADIO_11N_ACAX_COMPAT)                     /*!< 11n, 11ac and 11ax compatibility */
PDB_ID(PARAM_DB_RADIO_DYNAMIC_MU_TYPE)                     /*!< Dynamic MU Type */
PDB_ID(PARAM_DB_RADIO_HE_MU_FIXED_PARAMTERS)               /*!< HE MU Fixed Parameters */
PDB_ID(PARAM_DB_RADIO_HE_MU_DURATION)                      /*!< HE MU Duration */
PDB_ID(PARAM_DB_RADIO_STATIONS_STATS_ENABLED)              /*!< Stations statistics enabled */
PDB_ID(PARAM_DB_RADIO_ZWDFS_ANT_ACTIVE)                    /*!< ZWDFS Antenna Enabled/Disable */
PDB_ID(PARAM_DB_RADIO_ETSI_PPDU_DURATION_LIMITS)           /*!< ETSI PPDU Duration Limits */
PDB_ID(PARAM_DB_RADIO_RTS_THRESHOLD)                       /*!< RTS threshold */
PDB_ID(PARAM_DB_RADIO_AP_RETRY_LIMIT)                      /*!< AP retry limit value Mgmt */
PDB_ID(PARAM_DB_RADIO_AP_RETRY_LIMIT_DATA)                 /*!< AP retry limit value Data */
PDB_ID(PARAM_DB_RADIO_AP_RETRY_LIMIT_PROBERESP)            /*!< AP retry limit value Probe Response */
PDB_ID(PARAM_DB_RADIO_CTS_TO_SELF_TO)                      /*!< CTS to self timeout value */
PDB_ID(PARAM_DB_RADIO_TX_AMPDU_DENSITY)                    /*!< Tx AMPDU Density */
PDB_ID(PARAM_DB_RADIO_MU_OFDMA_BF_MODE)                    /*!< Mirror of FW's MU OFDMA BF UMI_MU_OFDMA_BF_CONFIG.mode */
PDB_ID(PARAM_DB_RADIO_MU_OFDMA_BF_PERIOD)                  /*!< Mirror of FW's MU OFDMA BF UMI_MU_OFDMA_BF_CONFIG.bfPeriod */
PDB_ID(PARAM_DB_RADIO_COLLECT_PROBE_REQ)                   /*!< Whether or not to collect probe requests for statistics */
PDB_ID(PARAM_DB_RADIO_PREAMBLE_PUNCTURE_CFG)
PDB_ID(PARAM_DB_RADIO_SLOW_PROBING_MASK)                   /*!< Slow Probing Mask */
PDB_ID(PARAM_DB_RADIO_FIXED_LTF_AND_GI)                    /*!< Fixed LTF and GI */
PDB_ID(PARAM_DB_RADIO_WHM_ENABLE)                          /*!< WHM Enable Main flag */
PDB_ID(PARAM_DB_RADIO_WHM_FW_WARN)                         /*!< WHM FW warn enable */
PDB_ID(PARAM_DB_RADIO_WHM_PHY_WARN)                        /*!< WHM PHY warn enable */
PDB_ID(PARAM_DB_RADIO_MU_GROUP_CFG)                        /*!< MU Group configuration params */
PDB_ID(PARAM_DB_RADIO_DYNAMIC_WMM)                         /*!< Dynamic WMM enable/disable flag */
PDB_ID(PARAM_DB_RADIO_DYNAMIC_EDCA)                        /*!< Dynamic EDCA enable/disable flag */
PDB_ID(PARAM_DB_RADIO_FIXED_PWR)                           /*!< Fixed TX management power */
#ifdef CONFIG_WAVE_DEBUG
PDB_ID(PARAM_DB_RADIO_TEST_BUS_MODE)                       /*!< Test Bus mode */
#endif
PDB_ID(PARAM_DB_RADIO_PLAN_MU_GROUP_STATS)                 /*!< HE MU Group manager statistics */
PDB_ID(PARAM_DB_RADIO_FILS_DISCOVERY_FRAME)                /*!< FILS Discovery frame */
PDB_ID(PARAM_DB_RADIO_FILS_DISCOVERY_FRAME_LEN)            /*!< FILS Discovery frame length */
PDB_ID(PARAM_DB_RADIO_UNSOLICIT_FRAME_CFG_MODE)            /*!< Unsolicited frame tx cfg mode */
PDB_ID(PARAM_DB_RADIO_UNSOLICIT_FRAME_CFG_DURATION)        /*!< Unsolicited frame tx cfg duration */
PDB_ID(PARAM_DB_RADIO_UNSOLICIT_PROBE_RESP_TEMPL)          /*!< Unsolicited Probe Response template */
PDB_ID(PARAM_DB_RADIO_UNSOLICIT_PROBE_RESP_TEMPL_LEN)      /*!< Unsolicited Probe Response template len*/
PDB_ID(PARAM_DB_RADIO_UNSOLICIT_TX_FRAME_INFO)             /*!< Unsolicited frame tx info*/
PDB_ID(PARAM_DB_RADIO_6GHZ_REG_FCC_SP)                     /*!< Regulatory table for Standard Power mode AP*/
PDB_ID(PARAM_DB_RADIO_6GHZ_OPER_POWER_MODE)                /*!< 6GHz Operation power mode (SP/LPI)*/
PDB_ID(PARAM_DB_RADAR_FIFO_DUMP)                           /*!< Radar signal phy fifo entries*/
PDB_ID(PARAM_DB_RADIO_VW_TEST_MODE)                        /*!< VW test mode */
PDB_ID(PARAM_DB_RADIO_20MHZ_TX_POWER)                      /*!< 20MHz TX power */
