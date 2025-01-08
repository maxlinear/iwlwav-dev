
/***********************************************************************************
File:				B2PhyAgcAnt0Regs.h
Module:				b2PhyAgcAnt0
SOC Revision:		latest
Generated at:       2024-06-26 12:54:51
Purpose:
Description:		This File was auto generated using SOC Online

************************************************************************************/
#ifndef _B2_PHY_AGC_ANT0_REGS_H_
#define _B2_PHY_AGC_ANT0_REGS_H_

/*---------------------------------------------------------------------------------
/						Registers Addresses													 
/----------------------------------------------------------------------------------*/
#include "HwMemoryMap.h"

#define B2_PHY_AGC_ANT0_BASE_ADDRESS                           MEMORY_MAP_UNIT_20220_BASE_ADDRESS
#define	REG_B2_PHY_AGC_ANT0_BB_RSSI_PARAMS_REG                       (B2_PHY_AGC_ANT0_BASE_ADDRESS + 0x0)
#define	REG_B2_PHY_AGC_ANT0_BB_RSSI_OFFSET2_REG                      (B2_PHY_AGC_ANT0_BASE_ADDRESS + 0x4)
#define	REG_B2_PHY_AGC_ANT0_BB_RSSI_SYSTEM_GAIN_REG                  (B2_PHY_AGC_ANT0_BASE_ADDRESS + 0x8)
#define	REG_B2_PHY_AGC_ANT0_BB_RSSI_SYSTEM_GAIN_SELECT_REG           (B2_PHY_AGC_ANT0_BASE_ADDRESS + 0xC)
#define	REG_B2_PHY_AGC_ANT0_BB_RSSI_SAT_THR                          (B2_PHY_AGC_ANT0_BASE_ADDRESS + 0x10)
#define	REG_B2_PHY_AGC_ANT0_INB_RSSI_PARAMS_REG                      (B2_PHY_AGC_ANT0_BASE_ADDRESS + 0x14)
#define	REG_B2_PHY_AGC_ANT0_INB_RSSI_OFFSET2_REG                     (B2_PHY_AGC_ANT0_BASE_ADDRESS + 0x18)
#define	REG_B2_PHY_AGC_ANT0_INBAND_RSSI_SYSTEM_GAIN_REG              (B2_PHY_AGC_ANT0_BASE_ADDRESS + 0x1C)
#define	REG_B2_PHY_AGC_ANT0_INBAND_RSSI_SYSTEM_GAIN_SELECT_REG       (B2_PHY_AGC_ANT0_BASE_ADDRESS + 0x20)
#define	REG_B2_PHY_AGC_ANT0_INBAND_RSSI_SAT_THR                      (B2_PHY_AGC_ANT0_BASE_ADDRESS + 0x24)
#define	REG_B2_PHY_AGC_ANT0_FB_RSSI_PARAMS_REG                       (B2_PHY_AGC_ANT0_BASE_ADDRESS + 0x28)
#define	REG_B2_PHY_AGC_ANT0_FB_RSSI_OFFSET2_REG                      (B2_PHY_AGC_ANT0_BASE_ADDRESS + 0x2C)
#define	REG_B2_PHY_AGC_ANT0_FB_RSSI_SYSTEM_GAIN_REG                  (B2_PHY_AGC_ANT0_BASE_ADDRESS + 0x30)
#define	REG_B2_PHY_AGC_ANT0_FB_RSSI_SYSTEM_GAIN_SELECT_REG           (B2_PHY_AGC_ANT0_BASE_ADDRESS + 0x34)
#define	REG_B2_PHY_AGC_ANT0_FB_RSSI_SAT_THR                          (B2_PHY_AGC_ANT0_BASE_ADDRESS + 0x38)
#define	REG_B2_PHY_AGC_ANT0_HB_RSSI_PARAMS_REG                       (B2_PHY_AGC_ANT0_BASE_ADDRESS + 0x3C)
#define	REG_B2_PHY_AGC_ANT0_HB_RSSI_OFFSET2_REG                      (B2_PHY_AGC_ANT0_BASE_ADDRESS + 0x40)
#define	REG_B2_PHY_AGC_ANT0_HB_RSSI_SYSTEM_GAIN_REG                  (B2_PHY_AGC_ANT0_BASE_ADDRESS + 0x44)
#define	REG_B2_PHY_AGC_ANT0_HB_RSSI_SYSTEM_GAIN_SELECT_REG           (B2_PHY_AGC_ANT0_BASE_ADDRESS + 0x48)
#define	REG_B2_PHY_AGC_ANT0_HB_RSSI_SAT_THR                          (B2_PHY_AGC_ANT0_BASE_ADDRESS + 0x4C)
#define	REG_B2_PHY_AGC_ANT0_RF_RSSI_PARAMS_REG                       (B2_PHY_AGC_ANT0_BASE_ADDRESS + 0x50)
#define	REG_B2_PHY_AGC_ANT0_RF_RSSI_OFFSET1_RX_RANGE0                (B2_PHY_AGC_ANT0_BASE_ADDRESS + 0x54)
#define	REG_B2_PHY_AGC_ANT0_RF_RSSI_OFFSET1_RX_RANGE1                (B2_PHY_AGC_ANT0_BASE_ADDRESS + 0x58)
#define	REG_B2_PHY_AGC_ANT0_RF_RSSI_OFFSET1_TX                       (B2_PHY_AGC_ANT0_BASE_ADDRESS + 0x5C)
#define	REG_B2_PHY_AGC_ANT0_RF_RSSI_OFFSET2_RX_REG                   (B2_PHY_AGC_ANT0_BASE_ADDRESS + 0x60)
#define	REG_B2_PHY_AGC_ANT0_RF_RSSI_OFFSET2_TX_REG                   (B2_PHY_AGC_ANT0_BASE_ADDRESS + 0x64)
#define	REG_B2_PHY_AGC_ANT0_RF_RSSI_SYSTEM_GAIN_REG                  (B2_PHY_AGC_ANT0_BASE_ADDRESS + 0x68)
#define	REG_B2_PHY_AGC_ANT0_RF_RSSI_SYSTEM_GAIN_SELECT_REG           (B2_PHY_AGC_ANT0_BASE_ADDRESS + 0x6C)
#define	REG_B2_PHY_AGC_ANT0_RF_RSSI_SAT_THR_RANGE0                   (B2_PHY_AGC_ANT0_BASE_ADDRESS + 0x70)
#define	REG_B2_PHY_AGC_ANT0_RF_RSSI_SAT_THR_RANGE1                   (B2_PHY_AGC_ANT0_BASE_ADDRESS + 0x74)
#define	REG_B2_PHY_AGC_ANT0_RF_RSSI_COEF_A_RANGE0_REG                (B2_PHY_AGC_ANT0_BASE_ADDRESS + 0x78)
#define	REG_B2_PHY_AGC_ANT0_RF_RSSI_COEF_A_RANGE1_REG                (B2_PHY_AGC_ANT0_BASE_ADDRESS + 0x7C)
#define	REG_B2_PHY_AGC_ANT0_RF_RSSI_COEF_A2_RANGE0_REG               (B2_PHY_AGC_ANT0_BASE_ADDRESS + 0x80)
#define	REG_B2_PHY_AGC_ANT0_RF_RSSI_COEF_A2_RANGE1_REG               (B2_PHY_AGC_ANT0_BASE_ADDRESS + 0x84)
#define	REG_B2_PHY_AGC_ANT0_RF_RSSI_COEF_B_RANGE0_REG                (B2_PHY_AGC_ANT0_BASE_ADDRESS + 0x88)
#define	REG_B2_PHY_AGC_ANT0_RF_RSSI_COEF_B_RANGE1_REG                (B2_PHY_AGC_ANT0_BASE_ADDRESS + 0x8C)
#define	REG_B2_PHY_AGC_ANT0_RF_RSSI_COEF_C_RANGE0_REG                (B2_PHY_AGC_ANT0_BASE_ADDRESS + 0x90)
#define	REG_B2_PHY_AGC_ANT0_RF_RSSI_COEF_C_RANGE1_REG                (B2_PHY_AGC_ANT0_BASE_ADDRESS + 0x94)
#define	REG_B2_PHY_AGC_ANT0_RF_RSSI_COEF_NLOG_RANGE0_REG             (B2_PHY_AGC_ANT0_BASE_ADDRESS + 0x98)
#define	REG_B2_PHY_AGC_ANT0_RF_RSSI_COEF_NLOG_RANGE1_REG             (B2_PHY_AGC_ANT0_BASE_ADDRESS + 0x9C)
#define	REG_B2_PHY_AGC_ANT0_RF_TSSI_COEF_A_REG                       (B2_PHY_AGC_ANT0_BASE_ADDRESS + 0xA0)
#define	REG_B2_PHY_AGC_ANT0_RF_TSSI_COEF_A2_REG                      (B2_PHY_AGC_ANT0_BASE_ADDRESS + 0xA4)
#define	REG_B2_PHY_AGC_ANT0_RF_TSSI_COEF_B_REG                       (B2_PHY_AGC_ANT0_BASE_ADDRESS + 0xA8)
#define	REG_B2_PHY_AGC_ANT0_RF_TSSI_COEF_C_REG                       (B2_PHY_AGC_ANT0_BASE_ADDRESS + 0xAC)
#define	REG_B2_PHY_AGC_ANT0_RF_TSSI_COEF_NLOG_REG                    (B2_PHY_AGC_ANT0_BASE_ADDRESS + 0xB0)
#define	REG_B2_PHY_AGC_ANT0_RF_RSSI_TX_RX_REG                        (B2_PHY_AGC_ANT0_BASE_ADDRESS + 0xB4)
#define	REG_B2_PHY_AGC_ANT0_BB_RSSI_REG                              (B2_PHY_AGC_ANT0_BASE_ADDRESS + 0xB8)
#define	REG_B2_PHY_AGC_ANT0_BB_POWER_REG                             (B2_PHY_AGC_ANT0_BASE_ADDRESS + 0xBC)
#define	REG_B2_PHY_AGC_ANT0_BB_SRSSI_REG                             (B2_PHY_AGC_ANT0_BASE_ADDRESS + 0xC0)
#define	REG_B2_PHY_AGC_ANT0_BB_SPOWER_REG                            (B2_PHY_AGC_ANT0_BASE_ADDRESS + 0xC4)
#define	REG_B2_PHY_AGC_ANT0_BB_PWR_DIFF_REG                          (B2_PHY_AGC_ANT0_BASE_ADDRESS + 0xC8)
#define	REG_B2_PHY_AGC_ANT0_IB_RSSI_REG                              (B2_PHY_AGC_ANT0_BASE_ADDRESS + 0xCC)
#define	REG_B2_PHY_AGC_ANT0_IB_POWER_REG                             (B2_PHY_AGC_ANT0_BASE_ADDRESS + 0xD0)
#define	REG_B2_PHY_AGC_ANT0_IB_SRSSI_REG                             (B2_PHY_AGC_ANT0_BASE_ADDRESS + 0xD4)
#define	REG_B2_PHY_AGC_ANT0_IB_SPOWER_REG                            (B2_PHY_AGC_ANT0_BASE_ADDRESS + 0xD8)
#define	REG_B2_PHY_AGC_ANT0_IB_PWR_DIFF_REG                          (B2_PHY_AGC_ANT0_BASE_ADDRESS + 0xDC)
#define	REG_B2_PHY_AGC_ANT0_FB_RSSI_REG                              (B2_PHY_AGC_ANT0_BASE_ADDRESS + 0xE0)
#define	REG_B2_PHY_AGC_ANT0_FB_POWER_REG                             (B2_PHY_AGC_ANT0_BASE_ADDRESS + 0xE4)
#define	REG_B2_PHY_AGC_ANT0_FB_SRSSI_REG                             (B2_PHY_AGC_ANT0_BASE_ADDRESS + 0xE8)
#define	REG_B2_PHY_AGC_ANT0_FB_SPOWER_REG                            (B2_PHY_AGC_ANT0_BASE_ADDRESS + 0xEC)
#define	REG_B2_PHY_AGC_ANT0_FB_PWR_DIFF_REG                          (B2_PHY_AGC_ANT0_BASE_ADDRESS + 0xF0)
#define	REG_B2_PHY_AGC_ANT0_HB_RSSI_REG                              (B2_PHY_AGC_ANT0_BASE_ADDRESS + 0xF4)
#define	REG_B2_PHY_AGC_ANT0_HB_POWER_REG                             (B2_PHY_AGC_ANT0_BASE_ADDRESS + 0xF8)
#define	REG_B2_PHY_AGC_ANT0_HB_SRSSI_REG                             (B2_PHY_AGC_ANT0_BASE_ADDRESS + 0xFC)
#define	REG_B2_PHY_AGC_ANT0_HB_SPOWER_REG                            (B2_PHY_AGC_ANT0_BASE_ADDRESS + 0x100)
#define	REG_B2_PHY_AGC_ANT0_HB_PWR_DIFF_REG                          (B2_PHY_AGC_ANT0_BASE_ADDRESS + 0x104)
#define	REG_B2_PHY_AGC_ANT0_RF_RSSI_REG                              (B2_PHY_AGC_ANT0_BASE_ADDRESS + 0x108)
#define	REG_B2_PHY_AGC_ANT0_RF_POWER_REG                             (B2_PHY_AGC_ANT0_BASE_ADDRESS + 0x10C)
#define	REG_B2_PHY_AGC_ANT0_RF_SRSSI_REG                             (B2_PHY_AGC_ANT0_BASE_ADDRESS + 0x110)
#define	REG_B2_PHY_AGC_ANT0_RF_SPOWER_REG                            (B2_PHY_AGC_ANT0_BASE_ADDRESS + 0x114)
#define	REG_B2_PHY_AGC_ANT0_SATURATION_RESULT                        (B2_PHY_AGC_ANT0_BASE_ADDRESS + 0x118)
#define	REG_B2_PHY_AGC_ANT0_RSSI_BLOCKS_GCLK_EN                      (B2_PHY_AGC_ANT0_BASE_ADDRESS + 0x11C)
#define	REG_B2_PHY_AGC_ANT0_RF_RSSI_DEC_OUT_STS                      (B2_PHY_AGC_ANT0_BASE_ADDRESS + 0x120)
#define	REG_B2_PHY_AGC_ANT0_RF_RSSI_HIGH_RES_REG                     (B2_PHY_AGC_ANT0_BASE_ADDRESS + 0x124)
#define	REG_B2_PHY_AGC_ANT0_PM_RF_POWER                              (B2_PHY_AGC_ANT0_BASE_ADDRESS + 0x140)
#define	REG_B2_PHY_AGC_ANT0_PM_FB_POWER                              (B2_PHY_AGC_ANT0_BASE_ADDRESS + 0x144)
#define	REG_B2_PHY_AGC_ANT0_PM_BB_POWER                              (B2_PHY_AGC_ANT0_BASE_ADDRESS + 0x148)
#define	REG_B2_PHY_AGC_ANT0_PM_HB_POWER                              (B2_PHY_AGC_ANT0_BASE_ADDRESS + 0x14C)
#define	REG_B2_PHY_AGC_ANT0_PM_IB_POWER                              (B2_PHY_AGC_ANT0_BASE_ADDRESS + 0x150)
#define	REG_B2_PHY_AGC_ANT0_PM_ACI_POWER                             (B2_PHY_AGC_ANT0_BASE_ADDRESS + 0x154)
#define	REG_B2_PHY_AGC_ANT0_PM_RF_OFFSET                             (B2_PHY_AGC_ANT0_BASE_ADDRESS + 0x158)
#define	REG_B2_PHY_AGC_ANT0_PM_FB_OFFSET                             (B2_PHY_AGC_ANT0_BASE_ADDRESS + 0x15C)
#define	REG_B2_PHY_AGC_ANT0_PM_BB_OFFSET                             (B2_PHY_AGC_ANT0_BASE_ADDRESS + 0x160)
#define	REG_B2_PHY_AGC_ANT0_PM_HB_OFFSET                             (B2_PHY_AGC_ANT0_BASE_ADDRESS + 0x164)
#define	REG_B2_PHY_AGC_ANT0_PM_IB_OFFSET                             (B2_PHY_AGC_ANT0_BASE_ADDRESS + 0x168)
#define	REG_B2_PHY_AGC_ANT0_PM_ACI_OFFSET                            (B2_PHY_AGC_ANT0_BASE_ADDRESS + 0x16C)
#define	REG_B2_PHY_AGC_ANT0_PM_SATURATION_REG                        (B2_PHY_AGC_ANT0_BASE_ADDRESS + 0x170)
#define	REG_B2_PHY_AGC_ANT0_PM_ACC_GAIN_DELAY                        (B2_PHY_AGC_ANT0_BASE_ADDRESS + 0x174)
#define	REG_B2_PHY_AGC_ANT0_PM_ACC_GAIN_SOURCES                      (B2_PHY_AGC_ANT0_BASE_ADDRESS + 0x178)
#define	REG_B2_PHY_AGC_ANT0_PM_ACC_GAIN_MAX_POWER_LEVEL              (B2_PHY_AGC_ANT0_BASE_ADDRESS + 0x17C)
#define	REG_B2_PHY_AGC_ANT0_PM_ACC_GAIN_MIN_POWER_LEVEL              (B2_PHY_AGC_ANT0_BASE_ADDRESS + 0x180)
#define	REG_B2_PHY_AGC_ANT0_PM_ACC_GAIN_SIGNAL_MAX_LEVEL             (B2_PHY_AGC_ANT0_BASE_ADDRESS + 0x184)
#define	REG_B2_PHY_AGC_ANT0_PM_ACC_GAIN_ENV_MIN_LEVEL                (B2_PHY_AGC_ANT0_BASE_ADDRESS + 0x188)
#define	REG_B2_PHY_AGC_ANT0_PM_ACC_GAIN_SIGNAL_ENV_DIFF_VALUES       (B2_PHY_AGC_ANT0_BASE_ADDRESS + 0x18C)
#define	REG_B2_PHY_AGC_ANT0_PM_ACC_GAIN_GSP_TABLE_CONTROL            (B2_PHY_AGC_ANT0_BASE_ADDRESS + 0x190)
#define	REG_B2_PHY_AGC_ANT0_PM_ACC_GAIN_LNA_CONTROL                  (B2_PHY_AGC_ANT0_BASE_ADDRESS + 0x194)
#define	REG_B2_PHY_AGC_ANT0_PM_SEL_S2D_RX_LUT                        (B2_PHY_AGC_ANT0_BASE_ADDRESS + 0x1B4)
#define	REG_B2_PHY_AGC_ANT0_PM_PGC1_GAIN_OFFSET                      (B2_PHY_AGC_ANT0_BASE_ADDRESS + 0x1B8)
#define	REG_B2_PHY_AGC_ANT0_PM_PGC1_GAIN_LIMITS                      (B2_PHY_AGC_ANT0_BASE_ADDRESS + 0x1BC)
#define	REG_B2_PHY_AGC_ANT0_PM_PGC1_GAIN_SHIFT                       (B2_PHY_AGC_ANT0_BASE_ADDRESS + 0x1C0)
#define	REG_B2_PHY_AGC_ANT0_PM_RX_FILTER_CONTROL                     (B2_PHY_AGC_ANT0_BASE_ADDRESS + 0x1C4)
#define	REG_B2_PHY_AGC_ANT0_PM_RF_SYSTEM_GAIN_OFFSET                 (B2_PHY_AGC_ANT0_BASE_ADDRESS + 0x1C8)
#define	REG_B2_PHY_AGC_ANT0_PM_FB_SYSTEM_GAIN_OFFSET                 (B2_PHY_AGC_ANT0_BASE_ADDRESS + 0x1CC)
#define	REG_B2_PHY_AGC_ANT0_PM_BB_SYSTEM_GAIN_OFFSET                 (B2_PHY_AGC_ANT0_BASE_ADDRESS + 0x1D0)
#define	REG_B2_PHY_AGC_ANT0_PM_POST_BB_SYSTEM_GAIN_OFFSET            (B2_PHY_AGC_ANT0_BASE_ADDRESS + 0x1D4)
#define	REG_B2_PHY_AGC_ANT0_PM_HB_SYSTEM_GAIN_OFFSET                 (B2_PHY_AGC_ANT0_BASE_ADDRESS + 0x1D8)
#define	REG_B2_PHY_AGC_ANT0_PM_IB_SYSTEM_GAIN_OFFSET                 (B2_PHY_AGC_ANT0_BASE_ADDRESS + 0x1DC)
#define	REG_B2_PHY_AGC_ANT0_PM_ACI_SYSTEM_GAIN_OFFSET                (B2_PHY_AGC_ANT0_BASE_ADDRESS + 0x1E0)
#define	REG_B2_PHY_AGC_ANT0_PM_CCA_SYSTEM_GAIN_OFFSET                (B2_PHY_AGC_ANT0_BASE_ADDRESS + 0x1E4)
#define	REG_B2_PHY_AGC_ANT0_PM_DET_SYSTEM_GAIN_OFFSET                (B2_PHY_AGC_ANT0_BASE_ADDRESS + 0x1E8)
#define	REG_B2_PHY_AGC_ANT0_PM_BB_BOF_OFFSET                         (B2_PHY_AGC_ANT0_BASE_ADDRESS + 0x1EC)
#define	REG_B2_PHY_AGC_ANT0_PM_HB_BOF_OFFSET                         (B2_PHY_AGC_ANT0_BASE_ADDRESS + 0x1F0)
#define	REG_B2_PHY_AGC_ANT0_PM_IB_RSSI_BOF_OFFSET                    (B2_PHY_AGC_ANT0_BASE_ADDRESS + 0x1F4)
#define	REG_B2_PHY_AGC_ANT0_PM_IB_ACI_BOF_OFFSET                     (B2_PHY_AGC_ANT0_BASE_ADDRESS + 0x1F8)
#define	REG_B2_PHY_AGC_ANT0_PM_DET_BOF_OFFSET                        (B2_PHY_AGC_ANT0_BASE_ADDRESS + 0x1FC)
#define	REG_B2_PHY_AGC_ANT0_PM_BB_BOF_TARGET                         (B2_PHY_AGC_ANT0_BASE_ADDRESS + 0x200)
#define	REG_B2_PHY_AGC_ANT0_PM_HB_BOF_TARGET                         (B2_PHY_AGC_ANT0_BASE_ADDRESS + 0x204)
#define	REG_B2_PHY_AGC_ANT0_PM_IB_BOF_TARGET                         (B2_PHY_AGC_ANT0_BASE_ADDRESS + 0x208)
#define	REG_B2_PHY_AGC_ANT0_PM_DET_BOF_TARGET                        (B2_PHY_AGC_ANT0_BASE_ADDRESS + 0x20C)
#define	REG_B2_PHY_AGC_ANT0_PM_DIFI1_DB_GAIN                         (B2_PHY_AGC_ANT0_BASE_ADDRESS + 0x210)
#define	REG_B2_PHY_AGC_ANT0_PM_PRESET_LNA_PGC1                       (B2_PHY_AGC_ANT0_BASE_ADDRESS + 0x214)
#define	REG_B2_PHY_AGC_ANT0_PM_MAX_BB_DIGITAL_GAIN                   (B2_PHY_AGC_ANT0_BASE_ADDRESS + 0x218)
#define	REG_B2_PHY_AGC_ANT0_PM_STEP1_BB_DIGITAL_GAIN                 (B2_PHY_AGC_ANT0_BASE_ADDRESS + 0x21C)
#define	REG_B2_PHY_AGC_ANT0_PM_STEP1_ENV_SAT_BB_DIGITAL_GAIN         (B2_PHY_AGC_ANT0_BASE_ADDRESS + 0x220)
#define	REG_B2_PHY_AGC_ANT0_PM_STEP1_SIGNAL_SAT_BB_DIGITAL_GAIN      (B2_PHY_AGC_ANT0_BASE_ADDRESS + 0x224)
#define	REG_B2_PHY_AGC_ANT0_PM_MAX_HB_DIGITAL_GAIN                   (B2_PHY_AGC_ANT0_BASE_ADDRESS + 0x228)
#define	REG_B2_PHY_AGC_ANT0_PM_STEP1_HB_DIGITAL_GAIN                 (B2_PHY_AGC_ANT0_BASE_ADDRESS + 0x22C)
#define	REG_B2_PHY_AGC_ANT0_PM_STEP1_ENV_SAT_HB_DIGITAL_GAIN         (B2_PHY_AGC_ANT0_BASE_ADDRESS + 0x230)
#define	REG_B2_PHY_AGC_ANT0_PM_STEP1_SIGNAL_SAT_HB_DIGITAL_GAIN      (B2_PHY_AGC_ANT0_BASE_ADDRESS + 0x234)
#define	REG_B2_PHY_AGC_ANT0_PM_MAX_IB_DIGITAL_GAIN                   (B2_PHY_AGC_ANT0_BASE_ADDRESS + 0x238)
#define	REG_B2_PHY_AGC_ANT0_PM_STEP1_IB_DIGITAL_GAIN                 (B2_PHY_AGC_ANT0_BASE_ADDRESS + 0x23C)
#define	REG_B2_PHY_AGC_ANT0_PM_STEP1_ENV_SAT_IB_DIGITAL_GAIN         (B2_PHY_AGC_ANT0_BASE_ADDRESS + 0x240)
#define	REG_B2_PHY_AGC_ANT0_PM_STEP1_SIGNAL_SAT_IB_DIGITAL_GAIN      (B2_PHY_AGC_ANT0_BASE_ADDRESS + 0x244)
#define	REG_B2_PHY_AGC_ANT0_PM_MAX_DET_DIGITAL_GAIN                  (B2_PHY_AGC_ANT0_BASE_ADDRESS + 0x248)
#define	REG_B2_PHY_AGC_ANT0_PM_STEP1_DET_DIGITAL_GAIN                (B2_PHY_AGC_ANT0_BASE_ADDRESS + 0x24C)
#define	REG_B2_PHY_AGC_ANT0_PM_STEP1_ENV_SAT_DET_DIGITAL_GAIN        (B2_PHY_AGC_ANT0_BASE_ADDRESS + 0x250)
#define	REG_B2_PHY_AGC_ANT0_PM_STEP1_SIGNAL_SAT_DET_DIGITAL_GAIN     (B2_PHY_AGC_ANT0_BASE_ADDRESS + 0x254)
#define	REG_B2_PHY_AGC_ANT0_ACC_RF_POWER                             (B2_PHY_AGC_ANT0_BASE_ADDRESS + 0x258)
#define	REG_B2_PHY_AGC_ANT0_ACC_FB_POWER                             (B2_PHY_AGC_ANT0_BASE_ADDRESS + 0x25C)
#define	REG_B2_PHY_AGC_ANT0_ACC_BB_POWER                             (B2_PHY_AGC_ANT0_BASE_ADDRESS + 0x260)
#define	REG_B2_PHY_AGC_ANT0_ACC_HB_POWER                             (B2_PHY_AGC_ANT0_BASE_ADDRESS + 0x264)
#define	REG_B2_PHY_AGC_ANT0_ACC_IB_POWER                             (B2_PHY_AGC_ANT0_BASE_ADDRESS + 0x268)
#define	REG_B2_PHY_AGC_ANT0_ACC_ACI_POWER                            (B2_PHY_AGC_ANT0_BASE_ADDRESS + 0x26C)
#define	REG_B2_PHY_AGC_ANT0_ACC_SIGNAL_POWER                         (B2_PHY_AGC_ANT0_BASE_ADDRESS + 0x270)
#define	REG_B2_PHY_AGC_ANT0_ACC_ENV_POWER                            (B2_PHY_AGC_ANT0_BASE_ADDRESS + 0x274)
#define	REG_B2_PHY_AGC_ANT0_ACC_STATUS                               (B2_PHY_AGC_ANT0_BASE_ADDRESS + 0x278)
#define	REG_B2_PHY_AGC_ANT0_ACC_RF_SYSTEM_GAIN                       (B2_PHY_AGC_ANT0_BASE_ADDRESS + 0x27C)
#define	REG_B2_PHY_AGC_ANT0_ACC_FB_SYSTEM_GAIN                       (B2_PHY_AGC_ANT0_BASE_ADDRESS + 0x280)
#define	REG_B2_PHY_AGC_ANT0_ACC_BB_SYSTEM_GAIN                       (B2_PHY_AGC_ANT0_BASE_ADDRESS + 0x284)
#define	REG_B2_PHY_AGC_ANT0_ACC_POST_BB_SYSTEM_GAIN                  (B2_PHY_AGC_ANT0_BASE_ADDRESS + 0x288)
#define	REG_B2_PHY_AGC_ANT0_ACC_HB_SYSTEM_GAIN                       (B2_PHY_AGC_ANT0_BASE_ADDRESS + 0x28C)
#define	REG_B2_PHY_AGC_ANT0_ACC_IB_SYSTEM_GAIN                       (B2_PHY_AGC_ANT0_BASE_ADDRESS + 0x290)
#define	REG_B2_PHY_AGC_ANT0_ACC_ACI_SYSTEM_GAIN                      (B2_PHY_AGC_ANT0_BASE_ADDRESS + 0x294)
#define	REG_B2_PHY_AGC_ANT0_ACC_CCA_SYSTEM_GAIN                      (B2_PHY_AGC_ANT0_BASE_ADDRESS + 0x298)
#define	REG_B2_PHY_AGC_ANT0_ACC_DET_SYSTEM_GAIN                      (B2_PHY_AGC_ANT0_BASE_ADDRESS + 0x29C)
#define	REG_B2_PHY_AGC_ANT0_ACC_BB_DIGITAL_GAIN                      (B2_PHY_AGC_ANT0_BASE_ADDRESS + 0x2A0)
#define	REG_B2_PHY_AGC_ANT0_ACC_HB_DIGITAL_GAIN                      (B2_PHY_AGC_ANT0_BASE_ADDRESS + 0x2A4)
#define	REG_B2_PHY_AGC_ANT0_ACC_IB_DIGITAL_GAIN                      (B2_PHY_AGC_ANT0_BASE_ADDRESS + 0x2A8)
#define	REG_B2_PHY_AGC_ANT0_ACC_DET_DIGITAL_GAIN                     (B2_PHY_AGC_ANT0_BASE_ADDRESS + 0x2AC)
#define	REG_B2_PHY_AGC_ANT0_ACC_BB_BOF                               (B2_PHY_AGC_ANT0_BASE_ADDRESS + 0x2B0)
#define	REG_B2_PHY_AGC_ANT0_ACC_BB_TOTAL_DIGITAL_GAIN                (B2_PHY_AGC_ANT0_BASE_ADDRESS + 0x2B4)
#define	REG_B2_PHY_AGC_ANT0_ACC_BB_DIGITAL_BOF                       (B2_PHY_AGC_ANT0_BASE_ADDRESS + 0x2B8)
#define	REG_B2_PHY_AGC_ANT0_ACC_HB_BOF                               (B2_PHY_AGC_ANT0_BASE_ADDRESS + 0x2BC)
#define	REG_B2_PHY_AGC_ANT0_ACC_HB_TOTAL_DIGITAL_GAIN                (B2_PHY_AGC_ANT0_BASE_ADDRESS + 0x2C0)
#define	REG_B2_PHY_AGC_ANT0_ACC_HB_DIGITAL_BOF                       (B2_PHY_AGC_ANT0_BASE_ADDRESS + 0x2C4)
#define	REG_B2_PHY_AGC_ANT0_ACC_IB_BOF                               (B2_PHY_AGC_ANT0_BASE_ADDRESS + 0x2C8)
#define	REG_B2_PHY_AGC_ANT0_ACC_IB_TOTAL_DIGITAL_GAIN                (B2_PHY_AGC_ANT0_BASE_ADDRESS + 0x2CC)
#define	REG_B2_PHY_AGC_ANT0_ACC_IB_DIGITAL_BOF                       (B2_PHY_AGC_ANT0_BASE_ADDRESS + 0x2D0)
#define	REG_B2_PHY_AGC_ANT0_ACC_DET_BOF                              (B2_PHY_AGC_ANT0_BASE_ADDRESS + 0x2D4)
#define	REG_B2_PHY_AGC_ANT0_ACC_DET_TOTAL_DIGITAL_GAIN               (B2_PHY_AGC_ANT0_BASE_ADDRESS + 0x2D8)
#define	REG_B2_PHY_AGC_ANT0_ACC_DET_DIGITAL_BOF                      (B2_PHY_AGC_ANT0_BASE_ADDRESS + 0x2DC)
#define	REG_B2_PHY_AGC_ANT0_ACC_DC_OFFSET_I                          (B2_PHY_AGC_ANT0_BASE_ADDRESS + 0x2E0)
#define	REG_B2_PHY_AGC_ANT0_ACC_DC_OFFSET_Q                          (B2_PHY_AGC_ANT0_BASE_ADDRESS + 0x2E4)
#define	REG_B2_PHY_AGC_ANT0_PM_AGC_RAMS_RM                           (B2_PHY_AGC_ANT0_BASE_ADDRESS + 0x2E8)
#define	REG_B2_PHY_AGC_ANT0_ACC_GAIN_VALUES                          (B2_PHY_AGC_ANT0_BASE_ADDRESS + 0x2EC)
#define	REG_B2_PHY_AGC_ANT0_PM_FCSI_CONTROL                          (B2_PHY_AGC_ANT0_BASE_ADDRESS + 0x2F0)
#define	REG_B2_PHY_AGC_ANT0_ACC_FCSI_VALUES                          (B2_PHY_AGC_ANT0_BASE_ADDRESS + 0x2F8)
#define	REG_B2_PHY_AGC_ANT0_ACC_GAIN_ACC_CONTROL                     (B2_PHY_AGC_ANT0_BASE_ADDRESS + 0x2FC)
#define	REG_B2_PHY_AGC_ANT0_PM_IB_CODE_ACC_THR                       (B2_PHY_AGC_ANT0_BASE_ADDRESS + 0x300)
#define	REG_B2_PHY_AGC_ANT0_PM_BB_CODE_ACC_THR                       (B2_PHY_AGC_ANT0_BASE_ADDRESS + 0x304)
#define	REG_B2_PHY_AGC_ANT0_PM_LONGTERM_RELEASE_THR                  (B2_PHY_AGC_ANT0_BASE_ADDRESS + 0x308)
#define	REG_B2_PHY_AGC_ANT0_PM_LONGTERM_THR                          (B2_PHY_AGC_ANT0_BASE_ADDRESS + 0x30C)
#define	REG_B2_PHY_AGC_ANT0_PM_BB_POWER_FAST_LOW_THR                 (B2_PHY_AGC_ANT0_BASE_ADDRESS + 0x310)
#define	REG_B2_PHY_AGC_ANT0_PM_DELTA_CODE_ACC_THR                    (B2_PHY_AGC_ANT0_BASE_ADDRESS + 0x314)
#define	REG_B2_PHY_AGC_ANT0_PM_BB_POWER_UP_THR                       (B2_PHY_AGC_ANT0_BASE_ADDRESS + 0x318)
#define	REG_B2_PHY_AGC_ANT0_PM_BB_POWER_SLOW_LOW_THR                 (B2_PHY_AGC_ANT0_BASE_ADDRESS + 0x31C)
#define	REG_B2_PHY_AGC_ANT0_PM_IB_POWER_UP_THR                       (B2_PHY_AGC_ANT0_BASE_ADDRESS + 0x320)
#define	REG_B2_PHY_AGC_ANT0_PM_IB_POWER_SLOW_LOW_THR                 (B2_PHY_AGC_ANT0_BASE_ADDRESS + 0x324)
#define	REG_B2_PHY_AGC_ANT0_PM_SET_CODE_ACC_THR_CTRL                 (B2_PHY_AGC_ANT0_BASE_ADDRESS + 0x328)
#define	REG_B2_PHY_AGC_ANT0_PM_ALGO_CTRL                             (B2_PHY_AGC_ANT0_BASE_ADDRESS + 0x32C)
#define	REG_B2_PHY_AGC_ANT0_ACC_EVENT_STATUS                         (B2_PHY_AGC_ANT0_BASE_ADDRESS + 0x330)
#define	REG_B2_PHY_AGC_ANT0_PM_BB_TH_SET_INC_GAP_DB                  (B2_PHY_AGC_ANT0_BASE_ADDRESS + 0x334)
#define	REG_B2_PHY_AGC_ANT0_PM_BB_TH_SET_DEC_GAP_DB                  (B2_PHY_AGC_ANT0_BASE_ADDRESS + 0x338)
#define	REG_B2_PHY_AGC_ANT0_PM_BB_TH_UP_EXTRA_GAP_DB                 (B2_PHY_AGC_ANT0_BASE_ADDRESS + 0x33C)
#define	REG_B2_PHY_AGC_ANT0_PM_BB_POWER_UP_DEF_THR                   (B2_PHY_AGC_ANT0_BASE_ADDRESS + 0x340)
#define	REG_B2_PHY_AGC_ANT0_PM_BB_POWER_SLOW_LOW_MIN_THR             (B2_PHY_AGC_ANT0_BASE_ADDRESS + 0x344)
#define	REG_B2_PHY_AGC_ANT0_PM_IB_TH_SET_INC_GAP_DB                  (B2_PHY_AGC_ANT0_BASE_ADDRESS + 0x348)
#define	REG_B2_PHY_AGC_ANT0_PM_IB_TH_SET_DEC_GAP_DB                  (B2_PHY_AGC_ANT0_BASE_ADDRESS + 0x34C)
#define	REG_B2_PHY_AGC_ANT0_PM_IB_TH_UP_EXTRA_GAP_DB                 (B2_PHY_AGC_ANT0_BASE_ADDRESS + 0x350)
#define	REG_B2_PHY_AGC_ANT0_PM_IB_POWER_UP_DEF_THR                   (B2_PHY_AGC_ANT0_BASE_ADDRESS + 0x354)
#define	REG_B2_PHY_AGC_ANT0_PM_IB_POWER_SLOW_LOW_MIN_THR             (B2_PHY_AGC_ANT0_BASE_ADDRESS + 0x358)
#define	REG_B2_PHY_AGC_ANT0_ACC_BB_POWER_UP_THR                      (B2_PHY_AGC_ANT0_BASE_ADDRESS + 0x35C)
#define	REG_B2_PHY_AGC_ANT0_ACC_BB_POWER_SLOW_LOW_THR                (B2_PHY_AGC_ANT0_BASE_ADDRESS + 0x360)
#define	REG_B2_PHY_AGC_ANT0_ACC_IB_POWER_UP_THR                      (B2_PHY_AGC_ANT0_BASE_ADDRESS + 0x364)
#define	REG_B2_PHY_AGC_ANT0_ACC_IB_POWER_SLOW_LOW_THR                (B2_PHY_AGC_ANT0_BASE_ADDRESS + 0x368)
#define	REG_B2_PHY_AGC_ANT0_CALC_AGC_GAIN_WORD                       (B2_PHY_AGC_ANT0_BASE_ADDRESS + 0x36C)
#define	REG_B2_PHY_AGC_ANT0_CALC_AGC_STM_CLEAR_CONTROL               (B2_PHY_AGC_ANT0_BASE_ADDRESS + 0x370)
#define	REG_B2_PHY_AGC_ANT0_CALC_ACC_AUTO_CLOSE_MODE                 (B2_PHY_AGC_ANT0_BASE_ADDRESS + 0x374)
#define	REG_B2_PHY_AGC_ANT0_CALC_POWER_THR_ACC_GO                    (B2_PHY_AGC_ANT0_BASE_ADDRESS + 0x378)
#define	REG_B2_PHY_AGC_ANT0_CALC_AGC_GAIN_CANCEL                     (B2_PHY_AGC_ANT0_BASE_ADDRESS + 0x37C)
#define	REG_B2_PHY_AGC_ANT0_DISABLE_PERIPHERALS                      (B2_PHY_AGC_ANT0_BASE_ADDRESS + 0x380)
#define	REG_B2_PHY_AGC_ANT0_AGC_STM_RDBACK                           (B2_PHY_AGC_ANT0_BASE_ADDRESS + 0x384)
#define	REG_B2_PHY_AGC_ANT0_PM_MAX_LIMIT_ACC_BB_DIGITAL_GAIN         (B2_PHY_AGC_ANT0_BASE_ADDRESS + 0x388)
#define	REG_B2_PHY_AGC_ANT0_PM_MIN_LIMIT_ACC_BB_DIGITAL_GAIN         (B2_PHY_AGC_ANT0_BASE_ADDRESS + 0x38C)
#define	REG_B2_PHY_AGC_ANT0_PM_MAX_LIMIT_ACC_HB_DIGITAL_GAIN         (B2_PHY_AGC_ANT0_BASE_ADDRESS + 0x390)
#define	REG_B2_PHY_AGC_ANT0_PM_MIN_LIMIT_ACC_HB_DIGITAL_GAIN         (B2_PHY_AGC_ANT0_BASE_ADDRESS + 0x394)
#define	REG_B2_PHY_AGC_ANT0_PM_MAX_LIMIT_ACC_IB_DIGITAL_GAIN         (B2_PHY_AGC_ANT0_BASE_ADDRESS + 0x398)
#define	REG_B2_PHY_AGC_ANT0_PM_MIN_LIMIT_ACC_IB_DIGITAL_GAIN         (B2_PHY_AGC_ANT0_BASE_ADDRESS + 0x39C)
#define	REG_B2_PHY_AGC_ANT0_PM_MAX_LIMIT_ACC_DET_DIGITAL_GAIN        (B2_PHY_AGC_ANT0_BASE_ADDRESS + 0x3A0)
#define	REG_B2_PHY_AGC_ANT0_PM_MIN_LIMIT_ACC_DET_DIGITAL_GAIN        (B2_PHY_AGC_ANT0_BASE_ADDRESS + 0x3A4)
#define	REG_B2_PHY_AGC_ANT0_BLOCKER_CONTROL                          (B2_PHY_AGC_ANT0_BASE_ADDRESS + 0x3C0)
#define	REG_B2_PHY_AGC_ANT0_PM_BLOCKER_TH                            (B2_PHY_AGC_ANT0_BASE_ADDRESS + 0x3C4)
#define	REG_B2_PHY_AGC_ANT0_PM_ALGO_CTRL_SEL                         (B2_PHY_AGC_ANT0_BASE_ADDRESS + 0x3D0)
#define	REG_B2_PHY_AGC_ANT0_ACC_BLOCKER_ADDR                         (B2_PHY_AGC_ANT0_BASE_ADDRESS + 0x3D4)
#define	REG_B2_PHY_AGC_ANT0_UP_INB_RSSI_PARAMS_REG                   (B2_PHY_AGC_ANT0_BASE_ADDRESS + 0x400)
#define	REG_B2_PHY_AGC_ANT0_UP_INB_RSSI_OFFSET2_REG                  (B2_PHY_AGC_ANT0_BASE_ADDRESS + 0x404)
#define	REG_B2_PHY_AGC_ANT0_UP_INBAND_RSSI_SYSTEM_GAIN_REG           (B2_PHY_AGC_ANT0_BASE_ADDRESS + 0x408)
#define	REG_B2_PHY_AGC_ANT0_UP_INBAND_RSSI_SYSTEM_GAIN_SELECT_REG    (B2_PHY_AGC_ANT0_BASE_ADDRESS + 0x40C)
#define	REG_B2_PHY_AGC_ANT0_UP_INBAND_RSSI_SAT_THR                   (B2_PHY_AGC_ANT0_BASE_ADDRESS + 0x410)
#define	REG_B2_PHY_AGC_ANT0_UP_HB_RSSI_PARAMS_REG                    (B2_PHY_AGC_ANT0_BASE_ADDRESS + 0x414)
#define	REG_B2_PHY_AGC_ANT0_UP_HB_RSSI_OFFSET2_REG                   (B2_PHY_AGC_ANT0_BASE_ADDRESS + 0x418)
#define	REG_B2_PHY_AGC_ANT0_UP_HB_RSSI_SYSTEM_GAIN_REG               (B2_PHY_AGC_ANT0_BASE_ADDRESS + 0x41C)
#define	REG_B2_PHY_AGC_ANT0_UP_HB_RSSI_SYSTEM_GAIN_SELECT_REG        (B2_PHY_AGC_ANT0_BASE_ADDRESS + 0x420)
#define	REG_B2_PHY_AGC_ANT0_UP_HB_RSSI_SAT_THR                       (B2_PHY_AGC_ANT0_BASE_ADDRESS + 0x424)
#define	REG_B2_PHY_AGC_ANT0_UP_IB_RSSI_REG                           (B2_PHY_AGC_ANT0_BASE_ADDRESS + 0x428)
#define	REG_B2_PHY_AGC_ANT0_UP_IB_POWER_REG                          (B2_PHY_AGC_ANT0_BASE_ADDRESS + 0x42C)
#define	REG_B2_PHY_AGC_ANT0_UP_IB_SRSSI_REG                          (B2_PHY_AGC_ANT0_BASE_ADDRESS + 0x430)
#define	REG_B2_PHY_AGC_ANT0_UP_IB_SPOWER_REG                         (B2_PHY_AGC_ANT0_BASE_ADDRESS + 0x434)
#define	REG_B2_PHY_AGC_ANT0_UP_IB_PWR_DIFF_REG                       (B2_PHY_AGC_ANT0_BASE_ADDRESS + 0x438)
#define	REG_B2_PHY_AGC_ANT0_UP_HB_RSSI_REG                           (B2_PHY_AGC_ANT0_BASE_ADDRESS + 0x43C)
#define	REG_B2_PHY_AGC_ANT0_UP_HB_POWER_REG                          (B2_PHY_AGC_ANT0_BASE_ADDRESS + 0x440)
#define	REG_B2_PHY_AGC_ANT0_UP_HB_SRSSI_REG                          (B2_PHY_AGC_ANT0_BASE_ADDRESS + 0x444)
#define	REG_B2_PHY_AGC_ANT0_UP_HB_SPOWER_REG                         (B2_PHY_AGC_ANT0_BASE_ADDRESS + 0x448)
#define	REG_B2_PHY_AGC_ANT0_UP_HB_PWR_DIFF_REG                       (B2_PHY_AGC_ANT0_BASE_ADDRESS + 0x44C)
#define	REG_B2_PHY_AGC_ANT0_PM_UP_HB_POWER                           (B2_PHY_AGC_ANT0_BASE_ADDRESS + 0x450)
#define	REG_B2_PHY_AGC_ANT0_PM_UP_IB_POWER                           (B2_PHY_AGC_ANT0_BASE_ADDRESS + 0x454)
#define	REG_B2_PHY_AGC_ANT0_PM_UP_ACI_POWER                          (B2_PHY_AGC_ANT0_BASE_ADDRESS + 0x458)
#define	REG_B2_PHY_AGC_ANT0_ACC_UP_HB_POWER                          (B2_PHY_AGC_ANT0_BASE_ADDRESS + 0x45C)
#define	REG_B2_PHY_AGC_ANT0_ACC_UP_IB_POWER                          (B2_PHY_AGC_ANT0_BASE_ADDRESS + 0x460)
#define	REG_B2_PHY_AGC_ANT0_ACC_UP_ACI_POWER                         (B2_PHY_AGC_ANT0_BASE_ADDRESS + 0x464)
#define	REG_B2_PHY_AGC_ANT0_UP_CONTROL                               (B2_PHY_AGC_ANT0_BASE_ADDRESS + 0x468)
#define	REG_B2_PHY_AGC_ANT0_PM_UP_HB_SYSTEM_GAIN_OFFSET              (B2_PHY_AGC_ANT0_BASE_ADDRESS + 0x46C)
#define	REG_B2_PHY_AGC_ANT0_PM_UP_IB_SYSTEM_GAIN_OFFSET              (B2_PHY_AGC_ANT0_BASE_ADDRESS + 0x470)
#define	REG_B2_PHY_AGC_ANT0_PM_UP_ACI_SYSTEM_GAIN_OFFSET             (B2_PHY_AGC_ANT0_BASE_ADDRESS + 0x474)
#define	REG_B2_PHY_AGC_ANT0_PM_UP_CCA_SYSTEM_GAIN_OFFSET             (B2_PHY_AGC_ANT0_BASE_ADDRESS + 0x478)
#define	REG_B2_PHY_AGC_ANT0_PM_UP_HB_BOF_OFFSET                      (B2_PHY_AGC_ANT0_BASE_ADDRESS + 0x47C)
#define	REG_B2_PHY_AGC_ANT0_PM_UP_IB_RSSI_BOF_OFFSET                 (B2_PHY_AGC_ANT0_BASE_ADDRESS + 0x480)
#define	REG_B2_PHY_AGC_ANT0_PM_UP_IB_ACI_BOF_OFFSET                  (B2_PHY_AGC_ANT0_BASE_ADDRESS + 0x484)
#define	REG_B2_PHY_AGC_ANT0_PM_UP_HB_BOF_TARGET                      (B2_PHY_AGC_ANT0_BASE_ADDRESS + 0x488)
#define	REG_B2_PHY_AGC_ANT0_PM_UP_IB_BOF_TARGET                      (B2_PHY_AGC_ANT0_BASE_ADDRESS + 0x48C)
#define	REG_B2_PHY_AGC_ANT0_ACC_UP_HB_SYSTEM_GAIN                    (B2_PHY_AGC_ANT0_BASE_ADDRESS + 0x490)
#define	REG_B2_PHY_AGC_ANT0_ACC_UP_IB_SYSTEM_GAIN                    (B2_PHY_AGC_ANT0_BASE_ADDRESS + 0x494)
#define	REG_B2_PHY_AGC_ANT0_ACC_UP_ACI_SYSTEM_GAIN                   (B2_PHY_AGC_ANT0_BASE_ADDRESS + 0x498)
#define	REG_B2_PHY_AGC_ANT0_ACC_UP_CCA_SYSTEM_GAIN                   (B2_PHY_AGC_ANT0_BASE_ADDRESS + 0x49C)
#define	REG_B2_PHY_AGC_ANT0_ACC_UP_HB_DIGITAL_GAIN                   (B2_PHY_AGC_ANT0_BASE_ADDRESS + 0x4A0)
#define	REG_B2_PHY_AGC_ANT0_ACC_UP_IB_DIGITAL_GAIN                   (B2_PHY_AGC_ANT0_BASE_ADDRESS + 0x4A4)
#define	REG_B2_PHY_AGC_ANT0_ACC_UP_HB_BOF                            (B2_PHY_AGC_ANT0_BASE_ADDRESS + 0x4A8)
#define	REG_B2_PHY_AGC_ANT0_ACC_UP_HB_TOTAL_DIGITAL_GAIN             (B2_PHY_AGC_ANT0_BASE_ADDRESS + 0x4AC)
#define	REG_B2_PHY_AGC_ANT0_ACC_UP_HB_DIGITAL_BOF                    (B2_PHY_AGC_ANT0_BASE_ADDRESS + 0x4B0)
#define	REG_B2_PHY_AGC_ANT0_ACC_UP_IB_BOF                            (B2_PHY_AGC_ANT0_BASE_ADDRESS + 0x4B4)
#define	REG_B2_PHY_AGC_ANT0_ACC_UP_IB_TOTAL_DIGITAL_GAIN             (B2_PHY_AGC_ANT0_BASE_ADDRESS + 0x4B8)
#define	REG_B2_PHY_AGC_ANT0_ACC_UP_IB_DIGITAL_BOF                    (B2_PHY_AGC_ANT0_BASE_ADDRESS + 0x4BC)
#define	REG_B2_PHY_AGC_ANT0_PM_ACC_GAIN_SAT_SOURCES                  (B2_PHY_AGC_ANT0_BASE_ADDRESS + 0x4C0)
#define	REG_B2_PHY_AGC_ANT0_PM_LNA_GAIN_LUT_0                        (B2_PHY_AGC_ANT0_BASE_ADDRESS + 0x4C4)
#define	REG_B2_PHY_AGC_ANT0_PM_LNA_GAIN_LUT_1                        (B2_PHY_AGC_ANT0_BASE_ADDRESS + 0x4C8)
#define	REG_B2_PHY_AGC_ANT0_PM_LNA_GAIN_LUT_2                        (B2_PHY_AGC_ANT0_BASE_ADDRESS + 0x4CC)
#define	REG_B2_PHY_AGC_ANT0_PM_LNA_GAIN_LUT_3                        (B2_PHY_AGC_ANT0_BASE_ADDRESS + 0x4D0)
#define	REG_B2_PHY_AGC_ANT0_PM_LNA_GAIN_LUT_4                        (B2_PHY_AGC_ANT0_BASE_ADDRESS + 0x4D4)
#define	REG_B2_PHY_AGC_ANT0_PM_LNA_GAIN_LUT_5                        (B2_PHY_AGC_ANT0_BASE_ADDRESS + 0x4D8)
#define	REG_B2_PHY_AGC_ANT0_PM_LNA_GAIN_LUT_6                        (B2_PHY_AGC_ANT0_BASE_ADDRESS + 0x4DC)
#define	REG_B2_PHY_AGC_ANT0_PM_LNA_GAIN_LUT_7                        (B2_PHY_AGC_ANT0_BASE_ADDRESS + 0x4E0)
#define	REG_B2_PHY_AGC_ANT0_PM_LNA_GAIN_LUT_8                        (B2_PHY_AGC_ANT0_BASE_ADDRESS + 0x4E4)
#define	REG_B2_PHY_AGC_ANT0_PM_LNA_GAIN_LUT_9                        (B2_PHY_AGC_ANT0_BASE_ADDRESS + 0x4E8)
#define	REG_B2_PHY_AGC_ANT0_PM_LNA_GAIN_LUT_10                       (B2_PHY_AGC_ANT0_BASE_ADDRESS + 0x4EC)
#define	REG_B2_PHY_AGC_ANT0_PM_LNA_GAIN_LUT_11                       (B2_PHY_AGC_ANT0_BASE_ADDRESS + 0x4F0)
#define	REG_B2_PHY_AGC_ANT0_PM_LNA_GAIN_LUT_12                       (B2_PHY_AGC_ANT0_BASE_ADDRESS + 0x4F4)
#define	REG_B2_PHY_AGC_ANT0_PM_LNA_GAIN_LUT_13                       (B2_PHY_AGC_ANT0_BASE_ADDRESS + 0x4F8)
#define	REG_B2_PHY_AGC_ANT0_PM_BS_ABS_TH_B0_B4                       (B2_PHY_AGC_ANT0_BASE_ADDRESS + 0x500)
#define	REG_B2_PHY_AGC_ANT0_PM_BS_ABS_TH_B5_B7                       (B2_PHY_AGC_ANT0_BASE_ADDRESS + 0x504)
#define	REG_B2_PHY_AGC_ANT0_PM_BS_ABS_TH_B8_B11                      (B2_PHY_AGC_ANT0_BASE_ADDRESS + 0x508)
#define	REG_B2_PHY_AGC_ANT0_PM_BS_OFF_TH_B0_B4                       (B2_PHY_AGC_ANT0_BASE_ADDRESS + 0x50C)
#define	REG_B2_PHY_AGC_ANT0_PM_BS_OFF_TH_B5_B7                       (B2_PHY_AGC_ANT0_BASE_ADDRESS + 0x510)
#define	REG_B2_PHY_AGC_ANT0_PM_BS_OFF_TH_B8_B11                      (B2_PHY_AGC_ANT0_BASE_ADDRESS + 0x514)
#define	REG_B2_PHY_AGC_ANT0_ACC_OFFSET_BS0_B4                        (B2_PHY_AGC_ANT0_BASE_ADDRESS + 0x518)
#define	REG_B2_PHY_AGC_ANT0_ACC_OFFSET_BS4_B7                        (B2_PHY_AGC_ANT0_BASE_ADDRESS + 0x51C)
#define	REG_B2_PHY_AGC_ANT0_ACC_OFFSET_BS8_B11                       (B2_PHY_AGC_ANT0_BASE_ADDRESS + 0x520)
#define	REG_B2_PHY_AGC_ANT0_ACC_ABS_BLOCKER_MAP                      (B2_PHY_AGC_ANT0_BASE_ADDRESS + 0x524)
#define	REG_B2_PHY_AGC_ANT0_ACC_TH_BLOCKER_MAP                       (B2_PHY_AGC_ANT0_BASE_ADDRESS + 0x528)
#define	REG_B2_PHY_AGC_ANT0_ACC_MAX_BLOCKER_LSB_POWER                (B2_PHY_AGC_ANT0_BASE_ADDRESS + 0x52C)
#define	REG_B2_PHY_AGC_ANT0_ACC_MAX_BLOCKER_USB_POWER                (B2_PHY_AGC_ANT0_BASE_ADDRESS + 0x530)
#define	REG_B2_PHY_AGC_ANT0_PM_LNA_INTERNAL_GAIN                     (B2_PHY_AGC_ANT0_BASE_ADDRESS + 0x534)
#define	REG_B2_PHY_AGC_ANT0_PM_PRI_ACI_POWER                         (B2_PHY_AGC_ANT0_BASE_ADDRESS + 0x538)
#define	REG_B2_PHY_AGC_ANT0_ACC_PRI_ACI_POWER                        (B2_PHY_AGC_ANT0_BASE_ADDRESS + 0x53C)
#define	REG_B2_PHY_AGC_ANT0_ULTRA_WIDE_BAND                          (B2_PHY_AGC_ANT0_BASE_ADDRESS + 0x540)
#define	REG_B2_PHY_AGC_ANT0_PM_PRESET_CALIBRATION                    (B2_PHY_AGC_ANT0_BASE_ADDRESS + 0x544)
#define	REG_B2_PHY_AGC_ANT0_AGC_MEASURMENT_FOR_SPUR_CANCEL           (B2_PHY_AGC_ANT0_BASE_ADDRESS + 0x548)
#define	REG_B2_PHY_AGC_ANT0_PM_LIMIT_LNA_MAX_INDEX                   (B2_PHY_AGC_ANT0_BASE_ADDRESS + 0x54C)
/*---------------------------------------------------------------------------------
/						Data Type Definition										
/----------------------------------------------------------------------------------*/
/*REG_B2_PHY_AGC_ANT0_BB_RSSI_PARAMS_REG 0x0 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 bbRssiBlkSize : 3; //bb rssi decimatiion, 2^(block size), reset value: 0x0, access type: RW
		uint32 reserved0 : 4;
		uint32 bbRssiIirPole : 4; //bb rssi iir pole, reset value: 0x0, access type: RW
		uint32 bbRssiIirPoleMin : 3; //bb rssi iir shift, reset value: 0x0, access type: RW
		uint32 bbRssiOffset1 : 16; //bb rssi offset1, reset value: 0x0, access type: RW
		uint32 bbRssiCancelDc : 1; //bb rssi cancel DC in power calculation (1 - remove dc, 0 - no remove), reset value: 0x0, access type: RW
		uint32 reserved1 : 1;
	} bitFields;
} RegB2PhyAgcAnt0BbRssiParamsReg_u;

/*REG_B2_PHY_AGC_ANT0_BB_RSSI_OFFSET2_REG 0x4 */
typedef union
{
	uint32 val;
	struct
	{
		int32  bbRssiOffset2 : 9; //bb rssi offset2, used for digital to power dBm conversion, reset value: 0x0, access type: RWS
		uint32 reserved0 : 23;
	} bitFields;
} RegB2PhyAgcAnt0BbRssiOffset2Reg_u;

/*REG_B2_PHY_AGC_ANT0_BB_RSSI_SYSTEM_GAIN_REG 0x8 */
typedef union
{
	uint32 val;
	struct
	{
		int32  bbRssiSystemGain : 9; //bb rssi system gain from progmodel, reset value: 0x0, access type: RWS
		uint32 reserved0 : 23;
	} bitFields;
} RegB2PhyAgcAnt0BbRssiSystemGainReg_u;

/*REG_B2_PHY_AGC_ANT0_BB_RSSI_SYSTEM_GAIN_SELECT_REG 0xC */
typedef union
{
	uint32 val;
	struct
	{
		uint32 bbRssiSystemGainHwSelect : 1; //bb rssi system gain selection: 1 from hw, 0 from pm, reset value: 0x0, access type: RW
		uint32 reserved0 : 31;
	} bitFields;
} RegB2PhyAgcAnt0BbRssiSystemGainSelectReg_u;

/*REG_B2_PHY_AGC_ANT0_BB_RSSI_SAT_THR 0x10 */
typedef union
{
	uint32 val;
	struct
	{
		int32  bbRssiSatThr : 9; //bb rssi saturation threshold, reset value: 0x0, access type: RWS
		uint32 reserved0 : 23;
	} bitFields;
} RegB2PhyAgcAnt0BbRssiSatThr_u;

/*REG_B2_PHY_AGC_ANT0_INB_RSSI_PARAMS_REG 0x14 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 inbandRssiBlkSize : 3; //inband rssi decimatiion, 2^(block size), reset value: 0x0, access type: RW
		uint32 reserved0 : 4;
		uint32 inbandRssiIirPole : 4; //inband rssi iir pole, reset value: 0x0, access type: RW
		uint32 inbandRssiIirPoleMin : 3; //inband rssi iir shift, reset value: 0x0, access type: RW
		uint32 inbandRssiOffset1 : 16; //inband rssi offset1, reset value: 0x0, access type: RW
		uint32 inbandRssiCancelDc : 1; //inband cancel DC in power calculation (1 - remove dc, 0 - no remove), reset value: 0x0, access type: RW
		uint32 reserved1 : 1;
	} bitFields;
} RegB2PhyAgcAnt0InbRssiParamsReg_u;

/*REG_B2_PHY_AGC_ANT0_INB_RSSI_OFFSET2_REG 0x18 */
typedef union
{
	uint32 val;
	struct
	{
		int32  inbandRssiOffset2 : 9; //inband rssi offset2, used for digital to power dBm conversion, reset value: 0x0, access type: RWS
		uint32 reserved0 : 23;
	} bitFields;
} RegB2PhyAgcAnt0InbRssiOffset2Reg_u;

/*REG_B2_PHY_AGC_ANT0_INBAND_RSSI_SYSTEM_GAIN_REG 0x1C */
typedef union
{
	uint32 val;
	struct
	{
		int32  inbandRssiSystemGain : 9; //inband rssi system gain from progmodel, reset value: 0x0, access type: RWS
		uint32 reserved0 : 23;
	} bitFields;
} RegB2PhyAgcAnt0InbandRssiSystemGainReg_u;

/*REG_B2_PHY_AGC_ANT0_INBAND_RSSI_SYSTEM_GAIN_SELECT_REG 0x20 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 inbandRssiSystemGainHwSelect : 1; //inband rssi system gain selection: 1 from hw, 0 from pm, reset value: 0x0, access type: RW
		uint32 reserved0 : 31;
	} bitFields;
} RegB2PhyAgcAnt0InbandRssiSystemGainSelectReg_u;

/*REG_B2_PHY_AGC_ANT0_INBAND_RSSI_SAT_THR 0x24 */
typedef union
{
	uint32 val;
	struct
	{
		int32  inbandRssiSatThr : 9; //inband rssi saturation threshold, reset value: 0x0, access type: RWS
		uint32 reserved0 : 23;
	} bitFields;
} RegB2PhyAgcAnt0InbandRssiSatThr_u;

/*REG_B2_PHY_AGC_ANT0_FB_RSSI_PARAMS_REG 0x28 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 fbRssiBlkSize : 3; //full band rssi decimatiion, 2^(block size), reset value: 0x0, access type: RW
		uint32 reserved0 : 4;
		uint32 fbRssiIirPole : 4; //full band rssi iir pole, reset value: 0x0, access type: RW
		uint32 fbRssiIirPoleMin : 3; //full band rssi iir shift, reset value: 0x0, access type: RW
		uint32 fbRssiOffset1 : 16; //full band rssi offset1, reset value: 0x0, access type: RW
		uint32 fbRssiCancelDc : 1; //full band cancel DC in power calculation (1 - remove dc, 0 - no remove), reset value: 0x0, access type: RW
		uint32 reserved1 : 1;
	} bitFields;
} RegB2PhyAgcAnt0FbRssiParamsReg_u;

/*REG_B2_PHY_AGC_ANT0_FB_RSSI_OFFSET2_REG 0x2C */
typedef union
{
	uint32 val;
	struct
	{
		int32  fbRssiOffset2 : 9; //full band rssi offset2, used for digital to power dBm conversion, reset value: 0x0, access type: RWS
		uint32 reserved0 : 23;
	} bitFields;
} RegB2PhyAgcAnt0FbRssiOffset2Reg_u;

/*REG_B2_PHY_AGC_ANT0_FB_RSSI_SYSTEM_GAIN_REG 0x30 */
typedef union
{
	uint32 val;
	struct
	{
		int32  fbRssiSystemGain : 9; //full band rssi system gain from progmodel, reset value: 0x0, access type: RWS
		uint32 reserved0 : 23;
	} bitFields;
} RegB2PhyAgcAnt0FbRssiSystemGainReg_u;

/*REG_B2_PHY_AGC_ANT0_FB_RSSI_SYSTEM_GAIN_SELECT_REG 0x34 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 fbRssiSystemGainHwSelect : 1; //full band rssi system gain selection: 1 from hw, 0 from pm, reset value: 0x0, access type: RW
		uint32 reserved0 : 31;
	} bitFields;
} RegB2PhyAgcAnt0FbRssiSystemGainSelectReg_u;

/*REG_B2_PHY_AGC_ANT0_FB_RSSI_SAT_THR 0x38 */
typedef union
{
	uint32 val;
	struct
	{
		int32  fbRssiSatThr : 9; //full band rssi saturation threshold, reset value: 0x0, access type: RWS
		uint32 reserved0 : 23;
	} bitFields;
} RegB2PhyAgcAnt0FbRssiSatThr_u;

/*REG_B2_PHY_AGC_ANT0_HB_RSSI_PARAMS_REG 0x3C */
typedef union
{
	uint32 val;
	struct
	{
		uint32 hbRssiBlkSize : 3; //hb rssi decimatiion, 2^(block size), reset value: 0x0, access type: RW
		uint32 reserved0 : 4;
		uint32 hbRssiIirPole : 4; //hb rssi iir pole, reset value: 0x0, access type: RW
		uint32 hbRssiIirPoleMin : 3; //hb rssi iir shift, reset value: 0x0, access type: RW
		uint32 hbRssiOffset1 : 16; //hb rssi offset1, reset value: 0x0, access type: RW
		uint32 hbRssiCancelDc : 1; //hb rssi cancel DC in power calculation (1 - remove dc, 0 - no remove), reset value: 0x0, access type: RW
		uint32 reserved1 : 1;
	} bitFields;
} RegB2PhyAgcAnt0HbRssiParamsReg_u;

/*REG_B2_PHY_AGC_ANT0_HB_RSSI_OFFSET2_REG 0x40 */
typedef union
{
	uint32 val;
	struct
	{
		int32  hbRssiOffset2 : 9; //hb rssi offset2, used for digital to power dBm conversion, reset value: 0x0, access type: RWS
		uint32 reserved0 : 23;
	} bitFields;
} RegB2PhyAgcAnt0HbRssiOffset2Reg_u;

/*REG_B2_PHY_AGC_ANT0_HB_RSSI_SYSTEM_GAIN_REG 0x44 */
typedef union
{
	uint32 val;
	struct
	{
		int32  hbRssiSystemGain : 9; //hb rssi system gain from progmodel, reset value: 0x0, access type: RWS
		uint32 reserved0 : 23;
	} bitFields;
} RegB2PhyAgcAnt0HbRssiSystemGainReg_u;

/*REG_B2_PHY_AGC_ANT0_HB_RSSI_SYSTEM_GAIN_SELECT_REG 0x48 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 hbRssiSystemGainHwSelect : 1; //hb rssi system gain selection: 1 from hw, 0 from pm, reset value: 0x0, access type: RW
		uint32 reserved0 : 31;
	} bitFields;
} RegB2PhyAgcAnt0HbRssiSystemGainSelectReg_u;

/*REG_B2_PHY_AGC_ANT0_HB_RSSI_SAT_THR 0x4C */
typedef union
{
	uint32 val;
	struct
	{
		int32  hbRssiSatThr : 9; //hb rssi saturation threshold, reset value: 0x0, access type: RWS
		uint32 reserved0 : 23;
	} bitFields;
} RegB2PhyAgcAnt0HbRssiSatThr_u;

/*REG_B2_PHY_AGC_ANT0_RF_RSSI_PARAMS_REG 0x50 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 rfRssiBlkSizeRxMode : 3; //rf rssi decimatiion, 2^(block size), in RX mode, reset value: 0x0, access type: RW
		uint32 rfRssiBlkSizeTxMode : 3; //rf rssi decimatiion, 2^(block size), in TX mode, reset value: 0x0, access type: RW
		uint32 rfRssiBlkSizeUserMode : 3; //rf rssi decimatiion, 2^(block size), in user mode (override TX/RX), reset value: 0x0, access type: RW
		uint32 rfRssiIirPole : 4; //rf rssi iir pole, reset value: 0x0, access type: RW
		uint32 rfRssiIirPoleMin : 3; //rf rssi iir shift, reset value: 0x0, access type: RW
		uint32 reserved0 : 16;
	} bitFields;
} RegB2PhyAgcAnt0RfRssiParamsReg_u;

/*REG_B2_PHY_AGC_ANT0_RF_RSSI_OFFSET1_RX_RANGE0 0x54 */
typedef union
{
	uint32 val;
	struct
	{
		int32  rfRssiOffset1RxRange0 : 14; //rf rssi offset1, used for dc cancellation in rx range0, reset value: 0x0, access type: RWS
		uint32 reserved0 : 18;
	} bitFields;
} RegB2PhyAgcAnt0RfRssiOffset1RxRange0_u;

/*REG_B2_PHY_AGC_ANT0_RF_RSSI_OFFSET1_RX_RANGE1 0x58 */
typedef union
{
	uint32 val;
	struct
	{
		int32  rfRssiOffset1RxRange1 : 14; //rf rssi offset1, used for dc cancellation in rx range1, reset value: 0x0, access type: RWS
		uint32 reserved0 : 18;
	} bitFields;
} RegB2PhyAgcAnt0RfRssiOffset1RxRange1_u;

/*REG_B2_PHY_AGC_ANT0_RF_RSSI_OFFSET1_TX 0x5C */
typedef union
{
	uint32 val;
	struct
	{
		int32  rfRssiOffset1Tx : 14; //rf rssi offset1, used for dc cancellation in tx, reset value: 0x0, access type: RWS
		uint32 reserved0 : 18;
	} bitFields;
} RegB2PhyAgcAnt0RfRssiOffset1Tx_u;

/*REG_B2_PHY_AGC_ANT0_RF_RSSI_OFFSET2_RX_REG 0x60 */
typedef union
{
	uint32 val;
	struct
	{
		int32  rfRssiOffset2Rx : 8; //rf rssi offset2, used for digital top power dBm conversion, RX mode, reset value: 0x0, access type: RWS
		uint32 reserved0 : 24;
	} bitFields;
} RegB2PhyAgcAnt0RfRssiOffset2RxReg_u;

/*REG_B2_PHY_AGC_ANT0_RF_RSSI_OFFSET2_TX_REG 0x64 */
typedef union
{
	uint32 val;
	struct
	{
		int32  rfRssiOffset2Tx : 8; //rf rssi offset2, used for digital top power dBm conversion, TX mode, reset value: 0x0, access type: RWS
		uint32 reserved0 : 24;
	} bitFields;
} RegB2PhyAgcAnt0RfRssiOffset2TxReg_u;

/*REG_B2_PHY_AGC_ANT0_RF_RSSI_SYSTEM_GAIN_REG 0x68 */
typedef union
{
	uint32 val;
	struct
	{
		int32  rfRssiSystemGain : 9; //rf rssi system gain from progmodel, reset value: 0x0, access type: RWS
		uint32 reserved0 : 23;
	} bitFields;
} RegB2PhyAgcAnt0RfRssiSystemGainReg_u;

/*REG_B2_PHY_AGC_ANT0_RF_RSSI_SYSTEM_GAIN_SELECT_REG 0x6C */
typedef union
{
	uint32 val;
	struct
	{
		uint32 rfRssiSystemGainHwSelect : 1; //rf  rssi system gain selection: 1 from hw, 0 from pm, reset value: 0x0, access type: RW
		uint32 reserved0 : 31;
	} bitFields;
} RegB2PhyAgcAnt0RfRssiSystemGainSelectReg_u;

/*REG_B2_PHY_AGC_ANT0_RF_RSSI_SAT_THR_RANGE0 0x70 */
typedef union
{
	uint32 val;
	struct
	{
		int32  rfRssiSatThrRange0 : 9; //rf rssi saturation threshold for range 0, reset value: 0x0, access type: RWS
		uint32 reserved0 : 23;
	} bitFields;
} RegB2PhyAgcAnt0RfRssiSatThrRange0_u;

/*REG_B2_PHY_AGC_ANT0_RF_RSSI_SAT_THR_RANGE1 0x74 */
typedef union
{
	uint32 val;
	struct
	{
		int32  rfRssiSatThrRange1 : 9; //rf rssi saturation threshold for range 1, reset value: 0x0, access type: RWS
		uint32 reserved0 : 23;
	} bitFields;
} RegB2PhyAgcAnt0RfRssiSatThrRange1_u;

/*REG_B2_PHY_AGC_ANT0_RF_RSSI_COEF_A_RANGE0_REG 0x78 */
typedef union
{
	uint32 val;
	struct
	{
		int32  rfRssiCoefARange0 : 16; //rf rssi coef A range0, reset value: 0x0, access type: RWS
		uint32 reserved0 : 16;
	} bitFields;
} RegB2PhyAgcAnt0RfRssiCoefARange0Reg_u;

/*REG_B2_PHY_AGC_ANT0_RF_RSSI_COEF_A_RANGE1_REG 0x7C */
typedef union
{
	uint32 val;
	struct
	{
		int32  rfRssiCoefARange1 : 16; //rf rssi coef A range1, reset value: 0x0, access type: RWS
		uint32 reserved0 : 16;
	} bitFields;
} RegB2PhyAgcAnt0RfRssiCoefARange1Reg_u;

/*REG_B2_PHY_AGC_ANT0_RF_RSSI_COEF_A2_RANGE0_REG 0x80 */
typedef union
{
	uint32 val;
	struct
	{
		int32  rfRssiCoefA2Range0 : 16; //rf rssi coef A2 range0, reset value: 0x0, access type: RWS
		uint32 reserved0 : 16;
	} bitFields;
} RegB2PhyAgcAnt0RfRssiCoefA2Range0Reg_u;

/*REG_B2_PHY_AGC_ANT0_RF_RSSI_COEF_A2_RANGE1_REG 0x84 */
typedef union
{
	uint32 val;
	struct
	{
		int32  rfRssiCoefA2Range1 : 16; //rf rssi coef A2 range1, reset value: 0x0, access type: RWS
		uint32 reserved0 : 16;
	} bitFields;
} RegB2PhyAgcAnt0RfRssiCoefA2Range1Reg_u;

/*REG_B2_PHY_AGC_ANT0_RF_RSSI_COEF_B_RANGE0_REG 0x88 */
typedef union
{
	uint32 val;
	struct
	{
		int32  rfRssiCoefBRange0 : 16; //rf rssi coef B range0, reset value: 0x0, access type: RWS
		uint32 reserved0 : 16;
	} bitFields;
} RegB2PhyAgcAnt0RfRssiCoefBRange0Reg_u;

/*REG_B2_PHY_AGC_ANT0_RF_RSSI_COEF_B_RANGE1_REG 0x8C */
typedef union
{
	uint32 val;
	struct
	{
		int32  rfRssiCoefBRange1 : 16; //rf rssi coef B range1, reset value: 0x0, access type: RWS
		uint32 reserved0 : 16;
	} bitFields;
} RegB2PhyAgcAnt0RfRssiCoefBRange1Reg_u;

/*REG_B2_PHY_AGC_ANT0_RF_RSSI_COEF_C_RANGE0_REG 0x90 */
typedef union
{
	uint32 val;
	struct
	{
		int32  rfRssiCoefCRange0 : 16; //rf rssi coef C range0, reset value: 0x0, access type: RWS
		uint32 reserved0 : 16;
	} bitFields;
} RegB2PhyAgcAnt0RfRssiCoefCRange0Reg_u;

/*REG_B2_PHY_AGC_ANT0_RF_RSSI_COEF_C_RANGE1_REG 0x94 */
typedef union
{
	uint32 val;
	struct
	{
		int32  rfRssiCoefCRange1 : 16; //rf rssi coef C range1, reset value: 0x0, access type: RWS
		uint32 reserved0 : 16;
	} bitFields;
} RegB2PhyAgcAnt0RfRssiCoefCRange1Reg_u;

/*REG_B2_PHY_AGC_ANT0_RF_RSSI_COEF_NLOG_RANGE0_REG 0x98 */
typedef union
{
	uint32 val;
	struct
	{
		int32  rfRssiCoefNlogRange0 : 16; //rf rssi coef Nlog range0, reset value: 0x0, access type: RWS
		uint32 reserved0 : 16;
	} bitFields;
} RegB2PhyAgcAnt0RfRssiCoefNlogRange0Reg_u;

/*REG_B2_PHY_AGC_ANT0_RF_RSSI_COEF_NLOG_RANGE1_REG 0x9C */
typedef union
{
	uint32 val;
	struct
	{
		int32  rfRssiCoefNlogRange1 : 16; //rf rssi coef Nlog range1, reset value: 0x0, access type: RWS
		uint32 reserved0 : 16;
	} bitFields;
} RegB2PhyAgcAnt0RfRssiCoefNlogRange1Reg_u;

/*REG_B2_PHY_AGC_ANT0_RF_TSSI_COEF_A_REG 0xA0 */
typedef union
{
	uint32 val;
	struct
	{
		int32  rfTssiCoefA : 16; //rf_tssi_coef_A, reset value: 0x0, access type: RWS
		uint32 reserved0 : 16;
	} bitFields;
} RegB2PhyAgcAnt0RfTssiCoefAReg_u;

/*REG_B2_PHY_AGC_ANT0_RF_TSSI_COEF_A2_REG 0xA4 */
typedef union
{
	uint32 val;
	struct
	{
		int32  rfTssiCoefA2 : 16; //rf_tssi_coef_A2, reset value: 0x0, access type: RWS
		uint32 reserved0 : 16;
	} bitFields;
} RegB2PhyAgcAnt0RfTssiCoefA2Reg_u;

/*REG_B2_PHY_AGC_ANT0_RF_TSSI_COEF_B_REG 0xA8 */
typedef union
{
	uint32 val;
	struct
	{
		int32  rfTssiCoefB : 16; //rf_tssi_coef_B, reset value: 0x0, access type: RWS
		uint32 reserved0 : 16;
	} bitFields;
} RegB2PhyAgcAnt0RfTssiCoefBReg_u;

/*REG_B2_PHY_AGC_ANT0_RF_TSSI_COEF_C_REG 0xAC */
typedef union
{
	uint32 val;
	struct
	{
		int32  rfTssiCoefC : 16; //rf_tssi_coef_C, reset value: 0x0, access type: RWS
		uint32 reserved0 : 16;
	} bitFields;
} RegB2PhyAgcAnt0RfTssiCoefCReg_u;

/*REG_B2_PHY_AGC_ANT0_RF_TSSI_COEF_NLOG_REG 0xB0 */
typedef union
{
	uint32 val;
	struct
	{
		int32  rfTssiCoefNlog : 16; //rf_tssi_coef_Nlog, reset value: 0x0, access type: RWS
		uint32 reserved0 : 16;
	} bitFields;
} RegB2PhyAgcAnt0RfTssiCoefNlogReg_u;

/*REG_B2_PHY_AGC_ANT0_RF_RSSI_TX_RX_REG 0xB4 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 rfRssiTxMode : 1; //rf rssi user programable mode : 1 tx mode, 0 rx mode, reset value: 0x0, access type: RW
		uint32 rfRssiRxRange : 1; //rf rssi user programable range, reset value: 0x0, access type: RW
		uint32 rfRssiModeOverride : 1; //rf rssi  mode override  - 1 use from pm, 0 use hw mode, reset value: 0x0, access type: RW
		uint32 reserved0 : 1;
		uint32 rfRssiRangeOverride : 1; //rf rssi  range override  - 1 use from pm, 0 use hw mode, reset value: 0x0, access type: RW
		uint32 rfTssiCoefOverride : 1; //rf tssi coef override  - 1 tssi coef from pm, 0 tssi coef from TPC  hw , reset value: 0x0, access type: RW
		uint32 rfRssiBlkSizeOverride : 1; //rf rssi blk size override: 1 decimation from pm, 0 - decimation according to TX/RX mode, reset value: 0x0, access type: RW
		uint32 rfTssiCoefMode : 2; //rf_tssi_coef_mode, reset value: 0x0, access type: RW
		uint32 reserved1 : 23;
	} bitFields;
} RegB2PhyAgcAnt0RfRssiTxRxReg_u;

/*REG_B2_PHY_AGC_ANT0_BB_RSSI_REG 0xB8 */
typedef union
{
	uint32 val;
	struct
	{
		int32  bbRssi : 9; //BB RSSI output, reset value: 0x0, access type: ROS
		uint32 reserved0 : 23;
	} bitFields;
} RegB2PhyAgcAnt0BbRssiReg_u;

/*REG_B2_PHY_AGC_ANT0_BB_POWER_REG 0xBC */
typedef union
{
	uint32 val;
	struct
	{
		int32  bbPower : 9; //BB power output (0.5 dB), reset value: 0x0, access type: ROS
		uint32 reserved0 : 23;
	} bitFields;
} RegB2PhyAgcAnt0BbPowerReg_u;

/*REG_B2_PHY_AGC_ANT0_BB_SRSSI_REG 0xC0 */
typedef union
{
	uint32 val;
	struct
	{
		int32  bbSrssi : 9; //BB RSSI, slow IIR decimation , reset value: 0x0, access type: ROS
		uint32 reserved0 : 23;
	} bitFields;
} RegB2PhyAgcAnt0BbSrssiReg_u;

/*REG_B2_PHY_AGC_ANT0_BB_SPOWER_REG 0xC4 */
typedef union
{
	uint32 val;
	struct
	{
		int32  bbSpower : 9; //BB Spower output (0.5 dB) slow IIR decimation , reset value: 0x0, access type: ROS
		uint32 reserved0 : 23;
	} bitFields;
} RegB2PhyAgcAnt0BbSpowerReg_u;

/*REG_B2_PHY_AGC_ANT0_BB_PWR_DIFF_REG 0xC8 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 bbB1 : 9; //BB power delta  (diff between 2 last samples, abs(Rn-R(n-1))), reset value: 0x0, access type: RO
		uint32 bbB2 : 9; //BB power delta (delay diffs, (abs(R(n-1)-R(n-2)), reset value: 0x0, access type: RO
		uint32 reserved0 : 14;
	} bitFields;
} RegB2PhyAgcAnt0BbPwrDiffReg_u;

/*REG_B2_PHY_AGC_ANT0_IB_RSSI_REG 0xCC */
typedef union
{
	uint32 val;
	struct
	{
		int32  ibRssi : 9; //IB RSSI output, reset value: 0x0, access type: ROS
		uint32 reserved0 : 23;
	} bitFields;
} RegB2PhyAgcAnt0IbRssiReg_u;

/*REG_B2_PHY_AGC_ANT0_IB_POWER_REG 0xD0 */
typedef union
{
	uint32 val;
	struct
	{
		int32  ibPower : 9; //IB power output (0.5 dB), reset value: 0x0, access type: ROS
		uint32 reserved0 : 23;
	} bitFields;
} RegB2PhyAgcAnt0IbPowerReg_u;

/*REG_B2_PHY_AGC_ANT0_IB_SRSSI_REG 0xD4 */
typedef union
{
	uint32 val;
	struct
	{
		int32  ibSrssi : 9; //IB RSSI, slow IIR decimation , reset value: 0x0, access type: ROS
		uint32 reserved0 : 23;
	} bitFields;
} RegB2PhyAgcAnt0IbSrssiReg_u;

/*REG_B2_PHY_AGC_ANT0_IB_SPOWER_REG 0xD8 */
typedef union
{
	uint32 val;
	struct
	{
		int32  ibSpower : 9; //IB Spower output (0.5 dB) slow IIR decimation , reset value: 0x0, access type: ROS
		uint32 reserved0 : 23;
	} bitFields;
} RegB2PhyAgcAnt0IbSpowerReg_u;

/*REG_B2_PHY_AGC_ANT0_IB_PWR_DIFF_REG 0xDC */
typedef union
{
	uint32 val;
	struct
	{
		uint32 ibB1 : 9; //IB power delta  (diff between 2 last samples, abs(Rn-R(n-1))), reset value: 0x0, access type: RO
		uint32 ibB2 : 9; //IB power delta (delay diffs, (abs(R(n-1)-R(n-2)), reset value: 0x0, access type: RO
		uint32 reserved0 : 14;
	} bitFields;
} RegB2PhyAgcAnt0IbPwrDiffReg_u;

/*REG_B2_PHY_AGC_ANT0_FB_RSSI_REG 0xE0 */
typedef union
{
	uint32 val;
	struct
	{
		int32  fbRssi : 9; //FB RSSI output, reset value: 0x0, access type: ROS
		uint32 reserved0 : 23;
	} bitFields;
} RegB2PhyAgcAnt0FbRssiReg_u;

/*REG_B2_PHY_AGC_ANT0_FB_POWER_REG 0xE4 */
typedef union
{
	uint32 val;
	struct
	{
		int32  fbPower : 9; //FB power output (0.5 dB), reset value: 0x0, access type: ROS
		uint32 reserved0 : 23;
	} bitFields;
} RegB2PhyAgcAnt0FbPowerReg_u;

/*REG_B2_PHY_AGC_ANT0_FB_SRSSI_REG 0xE8 */
typedef union
{
	uint32 val;
	struct
	{
		int32  fbSrssi : 9; //FB RSSI, slow IIR decimation , reset value: 0x0, access type: ROS
		uint32 reserved0 : 23;
	} bitFields;
} RegB2PhyAgcAnt0FbSrssiReg_u;

/*REG_B2_PHY_AGC_ANT0_FB_SPOWER_REG 0xEC */
typedef union
{
	uint32 val;
	struct
	{
		int32  fbSpower : 9; //FB Spower output (0.5 dB) slow IIR decimation , reset value: 0x0, access type: ROS
		uint32 reserved0 : 23;
	} bitFields;
} RegB2PhyAgcAnt0FbSpowerReg_u;

/*REG_B2_PHY_AGC_ANT0_FB_PWR_DIFF_REG 0xF0 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 fbB1 : 9; //FB power delta  (diff between 2 last samples, abs(Rn-R(n-1))), reset value: 0x0, access type: RO
		uint32 fbB2 : 9; //FB power delta (delay diffs, (abs(R(n-1)-R(n-2)), reset value: 0x0, access type: RO
		uint32 reserved0 : 14;
	} bitFields;
} RegB2PhyAgcAnt0FbPwrDiffReg_u;

/*REG_B2_PHY_AGC_ANT0_HB_RSSI_REG 0xF4 */
typedef union
{
	uint32 val;
	struct
	{
		int32  hbRssi : 9; //HB RSSI output, reset value: 0x0, access type: ROS
		uint32 reserved0 : 23;
	} bitFields;
} RegB2PhyAgcAnt0HbRssiReg_u;

/*REG_B2_PHY_AGC_ANT0_HB_POWER_REG 0xF8 */
typedef union
{
	uint32 val;
	struct
	{
		int32  hbPower : 9; //HB power output (0.5 dB), reset value: 0x0, access type: ROS
		uint32 reserved0 : 23;
	} bitFields;
} RegB2PhyAgcAnt0HbPowerReg_u;

/*REG_B2_PHY_AGC_ANT0_HB_SRSSI_REG 0xFC */
typedef union
{
	uint32 val;
	struct
	{
		int32  hbSrssi : 9; //HB RSSI, slow IIR decimation , reset value: 0x0, access type: ROS
		uint32 reserved0 : 23;
	} bitFields;
} RegB2PhyAgcAnt0HbSrssiReg_u;

/*REG_B2_PHY_AGC_ANT0_HB_SPOWER_REG 0x100 */
typedef union
{
	uint32 val;
	struct
	{
		int32  hbSpower : 9; //HB Spower output (0.5 dB) slow IIR decimation , reset value: 0x0, access type: ROS
		uint32 reserved0 : 23;
	} bitFields;
} RegB2PhyAgcAnt0HbSpowerReg_u;

/*REG_B2_PHY_AGC_ANT0_HB_PWR_DIFF_REG 0x104 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 hbB1 : 9; //HB power delta  (diff between 2 last samples, abs(Rn-R(n-1))), reset value: 0x0, access type: RO
		uint32 hbB2 : 9; //HB power delta (delay diffs, (abs(R(n-1)-R(n-2)), reset value: 0x0, access type: RO
		uint32 reserved0 : 14;
	} bitFields;
} RegB2PhyAgcAnt0HbPwrDiffReg_u;

/*REG_B2_PHY_AGC_ANT0_RF_RSSI_REG 0x108 */
typedef union
{
	uint32 val;
	struct
	{
		int32  rfRssi : 9; //RF RSSI output, reset value: 0x0, access type: ROS
		uint32 reserved0 : 23;
	} bitFields;
} RegB2PhyAgcAnt0RfRssiReg_u;

/*REG_B2_PHY_AGC_ANT0_RF_POWER_REG 0x10C */
typedef union
{
	uint32 val;
	struct
	{
		int32  rfPower : 9; //RF power output (0.5 dB), reset value: 0x0, access type: ROS
		uint32 reserved0 : 23;
	} bitFields;
} RegB2PhyAgcAnt0RfPowerReg_u;

/*REG_B2_PHY_AGC_ANT0_RF_SRSSI_REG 0x110 */
typedef union
{
	uint32 val;
	struct
	{
		int32  rfSrssi : 9; //RF RSSI, slow IIR decimation , reset value: 0x0, access type: ROS
		uint32 reserved0 : 23;
	} bitFields;
} RegB2PhyAgcAnt0RfSrssiReg_u;

/*REG_B2_PHY_AGC_ANT0_RF_SPOWER_REG 0x114 */
typedef union
{
	uint32 val;
	struct
	{
		int32  rfSpower : 9; //RF Spower output (0.5 dB) slow IIR decimation , reset value: 0x0, access type: ROS
		uint32 reserved0 : 23;
	} bitFields;
} RegB2PhyAgcAnt0RfSpowerReg_u;

/*REG_B2_PHY_AGC_ANT0_SATURATION_RESULT 0x118 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 rfRssiSatFlag : 1; //rf rssi is saturated above threshold, reset value: 0x0, access type: RO
		uint32 fbRssiSatFlag : 1; //fb rssi is saturated above threshold, reset value: 0x0, access type: RO
		uint32 bbRssiSatFlag : 1; //bb rssi is saturated above threshold, reset value: 0x0, access type: RO
		uint32 hbRssiSatFlag : 1; //hb rssi is saturated above threshold, reset value: 0x0, access type: RO
		uint32 ibRssiSatFlag : 1; //ib rssi is saturated above threshold, reset value: 0x0, access type: RO
		uint32 aciRssiSatFlag : 1; //aci rssi is saturated above threshold, reset value: 0x0, access type: RO
		uint32 upHbRssiSatFlag : 1; //up_hb rssi is saturated above threshold, reset value: 0x0, access type: RO
		uint32 upIbRssiSatFlag : 1; //up_ib rssi is saturated above threshold, reset value: 0x0, access type: RO
		uint32 upAciRssiSatFlag : 1; //up_aci rssi is saturated above threshold, reset value: 0x0, access type: RO
		uint32 reserved0 : 23;
	} bitFields;
} RegB2PhyAgcAnt0SaturationResult_u;

/*REG_B2_PHY_AGC_ANT0_RSSI_BLOCKS_GCLK_EN 0x11C */
typedef union
{
	uint32 val;
	struct
	{
		uint32 rfRssiGclkEn : 1; //enable rf rssi peripheral gator, reset value: 0x1, access type: RW
		uint32 fbRssiGclkEn : 1; //enable fb rssi peripheral gator, reset value: 0x0, access type: RW
		uint32 bbRssiGclkEn : 1; //enable bb rssi peripheral gator, reset value: 0x1, access type: RW
		uint32 hbRssiGclkEn : 1; //enable hb rssi peripheral gator, reset value: 0x1, access type: RW
		uint32 ibRssiGclkEn : 1; //enable ib rssi peripheral gator, reset value: 0x1, access type: RW
		uint32 upHbRssiGclkEn : 1; //enable up hb rssi peripheral gator, reset value: 0x1, access type: RW
		uint32 upIbRssiGclkEn : 1; //enable up ib rssi peripheral gator, reset value: 0x1, access type: RW
		uint32 reserved0 : 25;
	} bitFields;
} RegB2PhyAgcAnt0RssiBlocksGclkEn_u;

/*REG_B2_PHY_AGC_ANT0_RF_RSSI_DEC_OUT_STS 0x120 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 rfRssiDecOutSts : 14; //rf rssi decimator output for dc measurement, reset value: 0x0, access type: RO
		uint32 reserved0 : 18;
	} bitFields;
} RegB2PhyAgcAnt0RfRssiDecOutSts_u;

/*REG_B2_PHY_AGC_ANT0_RF_RSSI_HIGH_RES_REG 0x124 */
typedef union
{
	uint32 val;
	struct
	{
		int32  rfRssiHighRes : 10; //RF RSSI output in 1/4 db resolution , reset value: 0x0, access type: ROS
		uint32 reserved0 : 22;
	} bitFields;
} RegB2PhyAgcAnt0RfRssiHighResReg_u;

/*REG_B2_PHY_AGC_ANT0_PM_RF_POWER 0x140 */
typedef union
{
	uint32 val;
	struct
	{
		int32  pmRfPower : 9; //programmble rf power to gain acceleration in 1/2 dB, reset value: 0x0, access type: RWS
		uint32 reserved0 : 23;
	} bitFields;
} RegB2PhyAgcAnt0PmRfPower_u;

/*REG_B2_PHY_AGC_ANT0_PM_FB_POWER 0x144 */
typedef union
{
	uint32 val;
	struct
	{
		int32  pmFbPower : 9; //programmble fb power to gain acceleration in 1/2 dB, reset value: 0x0, access type: RWS
		uint32 reserved0 : 23;
	} bitFields;
} RegB2PhyAgcAnt0PmFbPower_u;

/*REG_B2_PHY_AGC_ANT0_PM_BB_POWER 0x148 */
typedef union
{
	uint32 val;
	struct
	{
		int32  pmBbPower : 9; //programmble bb power to gain acceleration in 1/2 dB, reset value: 0x0, access type: RWS
		uint32 reserved0 : 23;
	} bitFields;
} RegB2PhyAgcAnt0PmBbPower_u;

/*REG_B2_PHY_AGC_ANT0_PM_HB_POWER 0x14C */
typedef union
{
	uint32 val;
	struct
	{
		int32  pmHbPower : 9; //programmble hb power to gain acceleration in 1/2 dB, reset value: 0x0, access type: RWS
		uint32 reserved0 : 23;
	} bitFields;
} RegB2PhyAgcAnt0PmHbPower_u;

/*REG_B2_PHY_AGC_ANT0_PM_IB_POWER 0x150 */
typedef union
{
	uint32 val;
	struct
	{
		int32  pmIbPower : 9; //programmble ib power to gain acceleration in 1/2 dB, reset value: 0x0, access type: RWS
		uint32 reserved0 : 23;
	} bitFields;
} RegB2PhyAgcAnt0PmIbPower_u;

/*REG_B2_PHY_AGC_ANT0_PM_ACI_POWER 0x154 */
typedef union
{
	uint32 val;
	struct
	{
		int32  pmAciPower : 9; //programmble aci power to gain acceleration in 1/2 dB, reset value: 0x0, access type: RWS
		uint32 reserved0 : 23;
	} bitFields;
} RegB2PhyAgcAnt0PmAciPower_u;

/*REG_B2_PHY_AGC_ANT0_PM_RF_OFFSET 0x158 */
typedef union
{
	uint32 val;
	struct
	{
		int32  pmRfOffset : 9; //offset for rf power gain acceleration (may be used for dBv to dBm) in 1/2 dB, reset value: 0x0, access type: RWS
		uint32 reserved0 : 23;
	} bitFields;
} RegB2PhyAgcAnt0PmRfOffset_u;

/*REG_B2_PHY_AGC_ANT0_PM_FB_OFFSET 0x15C */
typedef union
{
	uint32 val;
	struct
	{
		int32  pmFbOffset : 9; //offset for fb power gain acceleration (may be used for dBv to dBm) in 1/2 dB, reset value: 0x0, access type: RWS
		uint32 reserved0 : 23;
	} bitFields;
} RegB2PhyAgcAnt0PmFbOffset_u;

/*REG_B2_PHY_AGC_ANT0_PM_BB_OFFSET 0x160 */
typedef union
{
	uint32 val;
	struct
	{
		int32  pmBbOffset : 9; //offset for bb power gain acceleration (may be used for dBv to dBm) in 1/2 dB, reset value: 0x0, access type: RWS
		uint32 reserved0 : 23;
	} bitFields;
} RegB2PhyAgcAnt0PmBbOffset_u;

/*REG_B2_PHY_AGC_ANT0_PM_HB_OFFSET 0x164 */
typedef union
{
	uint32 val;
	struct
	{
		int32  pmHbOffset : 9; //offset for hb power gain acceleration (may be used for dBv to dBm) in 1/2 dB, reset value: 0x0, access type: RWS
		uint32 reserved0 : 23;
	} bitFields;
} RegB2PhyAgcAnt0PmHbOffset_u;

/*REG_B2_PHY_AGC_ANT0_PM_IB_OFFSET 0x168 */
typedef union
{
	uint32 val;
	struct
	{
		int32  pmIbOffset : 9; //offset for ib power gain acceleration (may be used for dBv to dBm) in 1/2 dB, reset value: 0x0, access type: RWS
		uint32 reserved0 : 23;
	} bitFields;
} RegB2PhyAgcAnt0PmIbOffset_u;

/*REG_B2_PHY_AGC_ANT0_PM_ACI_OFFSET 0x16C */
typedef union
{
	uint32 val;
	struct
	{
		int32  pmAciOffset : 9; //offset for aci power gain acceleration (may be used for dBv to dBm) in 1/2 dB, reset value: 0x0, access type: RWS
		uint32 reserved0 : 23;
	} bitFields;
} RegB2PhyAgcAnt0PmAciOffset_u;

/*REG_B2_PHY_AGC_ANT0_PM_SATURATION_REG 0x170 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 pmRfRssiSatFlag : 1; //rf rssi is saturated above threshold from pm, reset value: 0x0, access type: RW
		uint32 pmFbRssiSatFlag : 1; //fb rssi is saturated above threshold from pm, reset value: 0x0, access type: RW
		uint32 pmBbRssiSatFlag : 1; //bb rssi is saturated above threshold from pm, reset value: 0x0, access type: RW
		uint32 pmHbRssiSatFlag : 1; //hb rssi is saturated above threshold from pm, reset value: 0x0, access type: RW
		uint32 pmIbRssiSatFlag : 1; //ib rssi is saturated above threshold from pm, reset value: 0x0, access type: RW
		uint32 pmAciRssiSatFlag : 1; //aci rssi is saturated above threshold from pm, reset value: 0x0, access type: RW
		uint32 pmUpHbRssiSatFlag : 1; //up hb rssi is saturated above threshold from pm, reset value: 0x0, access type: RW
		uint32 pmUpIbRssiSatFlag : 1; //up ib rssi is saturated above threshold from pm, reset value: 0x0, access type: RW
		uint32 pmUpAciRssiSatFlag : 1; //up aci rssi is saturated above threshold from pm, reset value: 0x0, access type: RW
		uint32 reserved0 : 23;
	} bitFields;
} RegB2PhyAgcAnt0PmSaturationReg_u;

/*REG_B2_PHY_AGC_ANT0_PM_ACC_GAIN_DELAY 0x174 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 pmAccGainDelay : 16; //delay between table go to start acceleration, reset value: 0x0, access type: RW
		uint32 reserved0 : 16;
	} bitFields;
} RegB2PhyAgcAnt0PmAccGainDelay_u;

/*REG_B2_PHY_AGC_ANT0_PM_ACC_GAIN_SOURCES 0x178 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 pmAccGainRfSource : 1; //rf power from pm or peripherals: 1- from pm, 0-from peripherals, reset value: 0x0, access type: RW
		uint32 pmAccGainFbSource : 1; //fb power from pm or peripherals: 1- from pm, 0-from peripherals, reset value: 0x0, access type: RW
		uint32 pmAccGainBbSource : 1; //bb power from pm or peripherals: 1- from pm, 0-from peripherals, reset value: 0x0, access type: RW
		uint32 pmAccGainHbSource : 1; //hb power from pm or peripherals: 1- from pm, 0-from peripherals, reset value: 0x0, access type: RW
		uint32 pmAccGainIbSource : 1; //ib power from pm or peripherals: 1- from pm, 0-from peripherals, reset value: 0x0, access type: RW
		uint32 pmAccGainAciSource : 1; //aci power from pm or peripherals: 1- from pm, 0-from peripherals, reset value: 0x0, access type: RW
		uint32 pmAccGainUpHbSource : 1; //up hb power from pm or peripherals: 1- from pm, 0-from peripherals, reset value: 0x0, access type: RW
		uint32 pmAccGainUpIbSource : 1; //up ib power from pm or peripherals: 1- from pm, 0-from peripherals, reset value: 0x0, access type: RW
		uint32 pmAccGainUpAciSource : 1; //up aci power from pm or peripherals: 1- from pm, 0-from peripherals, reset value: 0x0, access type: RW
		uint32 pmAccGainRfSatSource : 1; //rf rssi is saturated above threshold from pm, reset value: 0x0, access type: RW
		uint32 pmAccGainFbSatSource : 1; //fb rssi is saturated above threshold from pm, reset value: 0x0, access type: RW
		uint32 pmAccGainBbSatSource : 1; //bb rssi is saturated above threshold from pm, reset value: 0x0, access type: RW
		uint32 pmAccGainHbSatSource : 1; //hb rssi is saturated above threshold from pm, reset value: 0x0, access type: RW
		uint32 pmAccGainIbSatSource : 1; //ib rssi is saturated above threshold from pm, reset value: 0x0, access type: RW
		uint32 pmAccGainAciSatSource : 1; //aci rssi is saturated above threshold from pm, reset value: 0x0, access type: RW
		uint32 pmAccGainUpHbSatSource : 1; //up hb rssi is saturated above threshold from pm, reset value: 0x0, access type: RW
		uint32 pmAccGainUpIbSatSource : 1; //up ib rssi is saturated above threshold from pm, reset value: 0x0, access type: RW
		uint32 pmAccGainUpAciSatSource : 1; //up aci rssi is saturated above threshold from pm, reset value: 0x0, access type: RW
		uint32 pmAccGainPriAciSource : 1; //primary aci power from pm or peripherals: 1- from pm, 0-from peripherals, reset value: 0x0, access type: RW
		uint32 reserved0 : 1;
		uint32 pmAccGainSignalSource : 2; //acc_gain_signal_source: 0-from BB, 1-from IB, 2-from Aci, 3- from HB, reset value: 0x0, access type: RW
		uint32 pmAccGainEnvSource : 2; //acc_gain_env_source: 0- from rf, 1-from fb, 2 - from bb, reset value: 0x0, access type: RW
		uint32 pmAccGainPgc1Source : 2; //acc_gain_pgc1_source: 0- from fb, 1-from bb,2-rf, reset value: 0x0, access type: RW
		uint32 pmAccGainIbGainSource : 1; //acc_gain_ib_gain calculation source: 0-from ib rssi, 1- from aci, reset value: 0x0, access type: RW
		uint32 pmAccGainBlockerTypeSource : 1; //blocker type source, reset value: 0x0, access type: RW
		uint32 reserved1 : 4;
	} bitFields;
} RegB2PhyAgcAnt0PmAccGainSources_u;

/*REG_B2_PHY_AGC_ANT0_PM_ACC_GAIN_MAX_POWER_LEVEL 0x17C */
typedef union
{
	uint32 val;
	struct
	{
		int32  pmAccGainMaxPowerLevel : 9; //acc gain HW limit max power in 1/2 dB, reset value: 0x0, access type: RWS
		uint32 reserved0 : 23;
	} bitFields;
} RegB2PhyAgcAnt0PmAccGainMaxPowerLevel_u;

/*REG_B2_PHY_AGC_ANT0_PM_ACC_GAIN_MIN_POWER_LEVEL 0x180 */
typedef union
{
	uint32 val;
	struct
	{
		int32  pmAccGainMinPowerLevel : 9; //acc gain HW limit min power in 1/2 dB, reset value: 0x0, access type: RWS
		uint32 reserved0 : 23;
	} bitFields;
} RegB2PhyAgcAnt0PmAccGainMinPowerLevel_u;

/*REG_B2_PHY_AGC_ANT0_PM_ACC_GAIN_SIGNAL_MAX_LEVEL 0x184 */
typedef union
{
	uint32 val;
	struct
	{
		int32  pmAccGainSignalMaxLevel : 9; //acc gain HW limit for BB is RF  in 1/2 dB, reset value: 0x0, access type: RWS
		uint32 reserved0 : 23;
	} bitFields;
} RegB2PhyAgcAnt0PmAccGainSignalMaxLevel_u;

/*REG_B2_PHY_AGC_ANT0_PM_ACC_GAIN_ENV_MIN_LEVEL 0x188 */
typedef union
{
	uint32 val;
	struct
	{
		int32  pmAccGainEnvMinLevel : 9; //acc gain HW limit for RF is BB in 1/2 dB, reset value: 0x0, access type: RWS
		uint32 reserved0 : 23;
	} bitFields;
} RegB2PhyAgcAnt0PmAccGainEnvMinLevel_u;

/*REG_B2_PHY_AGC_ANT0_PM_ACC_GAIN_SIGNAL_ENV_DIFF_VALUES 0x18C */
typedef union
{
	uint32 val;
	struct
	{
		uint32 pmAccGainSignalEnvMaxDiff : 9; //maximal difference beween signal and environment for table access in 1/2 dB, reset value: 0x0, access type: RW
		uint32 reserved0 : 7;
		uint32 pmAccGainSignalEnvMinDiff : 9; //minimal difference beween signal and environment for table access, reset value: 0x0, access type: RW
		uint32 reserved1 : 7;
	} bitFields;
} RegB2PhyAgcAnt0PmAccGainSignalEnvDiffValues_u;

/*REG_B2_PHY_AGC_ANT0_PM_ACC_GAIN_GSP_TABLE_CONTROL 0x190 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 reserved0 : 16;
		uint32 pmAccGainGspTableShift : 3; //shift for delta calculated for table resolution, reset value: 0x0, access type: RW
		uint32 reserved1 : 5;
		uint32 pmAccGainGspTableMode : 1; //mode for table:0-per bw, 1-full band, reset value: 0x0, access type: RW
		uint32 reserved2 : 7;
	} bitFields;
} RegB2PhyAgcAnt0PmAccGainGspTableControl_u;

/*REG_B2_PHY_AGC_ANT0_PM_ACC_GAIN_LNA_CONTROL 0x194 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 pmAccGainLnaIndexMode : 1; //lna_target or switching point, reset value: 0x0, access type: RW
		uint32 reserved0 : 31;
	} bitFields;
} RegB2PhyAgcAnt0PmAccGainLnaControl_u;

/*REG_B2_PHY_AGC_ANT0_PM_SEL_S2D_RX_LUT 0x1B4 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 pmSelS2DRxLut0 : 1; //control bit to select rf rssi range and s2d pair for lna index 0, reset value: 0x0, access type: RW
		uint32 pmSelS2DRxLut1 : 1; //control bit to select rf rssi range and s2d pair for lna index 1, reset value: 0x0, access type: RW
		uint32 pmSelS2DRxLut2 : 1; //control bit to select rf rssi range and s2d pair for lna index 2, reset value: 0x0, access type: RW
		uint32 pmSelS2DRxLut3 : 1; //control bit to select rf rssi range and s2d pair for lna index 3, reset value: 0x0, access type: RW
		uint32 pmSelS2DRxLut4 : 1; //control bit to select rf rssi range and s2d pair for lna index 4, reset value: 0x0, access type: RW
		uint32 pmSelS2DRxLut5 : 1; //control bit to select rf rssi range and s2d pair for lna index 5, reset value: 0x0, access type: RW
		uint32 pmSelS2DRxLut6 : 1; //control bit to select rf rssi range and s2d pair for lna index 6, reset value: 0x0, access type: RW
		uint32 pmSelS2DRxLut7 : 1; //control bit to select rf rssi range and s2d pair for lna index 7, reset value: 0x0, access type: RW
		uint32 pmSelS2DRxLut8 : 1; //control bit to select rf rssi range and s2d pair for lna index 8, reset value: 0x0, access type: RW
		uint32 pmSelS2DRxLut9 : 1; //control bit to select rf rssi range and s2d pair for lna index 9, reset value: 0x0, access type: RW
		uint32 pmSelS2DRxLut10 : 1; //control bit to select rf rssi range and s2d pair for lna index 10, reset value: 0x0, access type: RW
		uint32 pmSelS2DRxLut11 : 1; //control bit to select rf rssi range and s2d pair for lna index 11, reset value: 0x0, access type: RW
		uint32 pmSelS2DRxLut12 : 1; //control bit to select rf rssi range and s2d pair for lna index 12, reset value: 0x0, access type: RW
		uint32 pmSelS2DRxLut13 : 1; //control bit to select rf rssi range and s2d pair for lna index 13, reset value: 0x0, access type: RW
		uint32 reserved0 : 18;
	} bitFields;
} RegB2PhyAgcAnt0PmSelS2DRxLut_u;

/*REG_B2_PHY_AGC_ANT0_PM_PGC1_GAIN_OFFSET 0x1B8 */
typedef union
{
	uint32 val;
	struct
	{
		int32  pmPgc1GainOffset : 9; //pgc1 target power offset in 1/2 dB, reset value: 0x0, access type: RWS
		uint32 reserved0 : 23;
	} bitFields;
} RegB2PhyAgcAnt0PmPgc1GainOffset_u;

/*REG_B2_PHY_AGC_ANT0_PM_PGC1_GAIN_LIMITS 0x1BC */
typedef union
{
	uint32 val;
	struct
	{
		uint32 pmPgc1GainPlusOffsetMaxLimit : 9; //pgc1 gain plus offset max limit in 1/2 dB, reset value: 0x0, access type: RW
		uint32 reserved0 : 7;
		uint32 pmPgc1GainPlusOffsetMinLimit : 9; //pgc1 gain plus offset min limit in 1/2 dB, reset value: 0x0, access type: RW
		uint32 reserved1 : 7;
	} bitFields;
} RegB2PhyAgcAnt0PmPgc1GainLimits_u;

/*REG_B2_PHY_AGC_ANT0_PM_PGC1_GAIN_SHIFT 0x1C0 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 pmPgc1GainShift : 3; //pgc1 index shift to convert from gain to index, reset value: 0x0, access type: RW
		uint32 reserved0 : 29;
	} bitFields;
} RegB2PhyAgcAnt0PmPgc1GainShift_u;

/*REG_B2_PHY_AGC_ANT0_PM_RX_FILTER_CONTROL 0x1C4 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 reserved0 : 2;
		uint32 pmRxFilterBwInterferenceMode : 1; //rx_filter_bw interference_mode: 0-no interference, 1-w/ interference. Different filter bw for int, reset value: 0x0, access type: RW
		uint32 reserved1 : 29;
	} bitFields;
} RegB2PhyAgcAnt0PmRxFilterControl_u;

/*REG_B2_PHY_AGC_ANT0_PM_RF_SYSTEM_GAIN_OFFSET 0x1C8 */
typedef union
{
	uint32 val;
	struct
	{
		int32  pmRfSystemGainOffset : 9; //offset for rf gain acceleration (may be used to overcome unexpected constant gain in HW) in 1/2 dB, reset value: 0x0, access type: RWS
		uint32 reserved0 : 23;
	} bitFields;
} RegB2PhyAgcAnt0PmRfSystemGainOffset_u;

/*REG_B2_PHY_AGC_ANT0_PM_FB_SYSTEM_GAIN_OFFSET 0x1CC */
typedef union
{
	uint32 val;
	struct
	{
		int32  pmFbSystemGainOffset : 9; //offset for fb gain acceleration (may be used to overcome unexpected constant gain in HW) in 1/2 dB, reset value: 0x0, access type: RWS
		uint32 reserved0 : 23;
	} bitFields;
} RegB2PhyAgcAnt0PmFbSystemGainOffset_u;

/*REG_B2_PHY_AGC_ANT0_PM_BB_SYSTEM_GAIN_OFFSET 0x1D0 */
typedef union
{
	uint32 val;
	struct
	{
		int32  pmBbSystemGainOffset : 9; //offset for bb gain acceleration  (may be used to overcome unexpected constant gain in HW) in 1/2 dB, reset value: 0x0, access type: RWS
		uint32 reserved0 : 23;
	} bitFields;
} RegB2PhyAgcAnt0PmBbSystemGainOffset_u;

/*REG_B2_PHY_AGC_ANT0_PM_POST_BB_SYSTEM_GAIN_OFFSET 0x1D4 */
typedef union
{
	uint32 val;
	struct
	{
		int32  pmPostBbSystemGainOffset : 9; //offset for pre bb gain acceleration  (may be used to overcome unexpected constant gain in HW) in 1/2 dB, reset value: 0x0, access type: RWS
		uint32 reserved0 : 23;
	} bitFields;
} RegB2PhyAgcAnt0PmPostBbSystemGainOffset_u;

/*REG_B2_PHY_AGC_ANT0_PM_HB_SYSTEM_GAIN_OFFSET 0x1D8 */
typedef union
{
	uint32 val;
	struct
	{
		int32  pmHbSystemGainOffset : 9; //offset for hb gain acceleration  (may be used to overcome unexpected constant gain in HW) in 1/2 dB, reset value: 0x0, access type: RWS
		uint32 reserved0 : 23;
	} bitFields;
} RegB2PhyAgcAnt0PmHbSystemGainOffset_u;

/*REG_B2_PHY_AGC_ANT0_PM_IB_SYSTEM_GAIN_OFFSET 0x1DC */
typedef union
{
	uint32 val;
	struct
	{
		int32  pmIbSystemGainOffset : 9; //offset for ib gain acceleration  (may be used to overcome unexpected constant gain in HW) in 1/2 dB, reset value: 0x0, access type: RWS
		uint32 reserved0 : 23;
	} bitFields;
} RegB2PhyAgcAnt0PmIbSystemGainOffset_u;

/*REG_B2_PHY_AGC_ANT0_PM_ACI_SYSTEM_GAIN_OFFSET 0x1E0 */
typedef union
{
	uint32 val;
	struct
	{
		int32  pmAciSystemGainOffset : 9; //offset for aci gain acceleration  (may be used to overcome unexpected constant gain in HW) in 1/2 dB, reset value: 0x0, access type: RWS
		uint32 reserved0 : 23;
	} bitFields;
} RegB2PhyAgcAnt0PmAciSystemGainOffset_u;

/*REG_B2_PHY_AGC_ANT0_PM_CCA_SYSTEM_GAIN_OFFSET 0x1E4 */
typedef union
{
	uint32 val;
	struct
	{
		int32  pmCcaSystemGainOffset : 9; //offset for cca gain acceleration  (may be used to overcome unexpected constant gain in HW) in 1/2 dB, reset value: 0x0, access type: RWS
		uint32 reserved0 : 23;
	} bitFields;
} RegB2PhyAgcAnt0PmCcaSystemGainOffset_u;

/*REG_B2_PHY_AGC_ANT0_PM_DET_SYSTEM_GAIN_OFFSET 0x1E8 */
typedef union
{
	uint32 val;
	struct
	{
		int32  pmDetSystemGainOffset : 9; //offset for det gain acceleration  (may be used to overcome unexpected constant gain in HW) in 1/2 dB, reset value: 0x0, access type: RWS
		uint32 reserved0 : 23;
	} bitFields;
} RegB2PhyAgcAnt0PmDetSystemGainOffset_u;

/*REG_B2_PHY_AGC_ANT0_PM_BB_BOF_OFFSET 0x1EC */
typedef union
{
	uint32 val;
	struct
	{
		int32  pmBbBofOffset : 9; //convert bb rssi power to backoff in 1/2 dB, reset value: 0x0, access type: RWS
		uint32 reserved0 : 23;
	} bitFields;
} RegB2PhyAgcAnt0PmBbBofOffset_u;

/*REG_B2_PHY_AGC_ANT0_PM_HB_BOF_OFFSET 0x1F0 */
typedef union
{
	uint32 val;
	struct
	{
		int32  pmHbBofOffset : 9; //convert hb rssi power to backoff in 1/2 dB, reset value: 0x0, access type: RWS
		uint32 reserved0 : 23;
	} bitFields;
} RegB2PhyAgcAnt0PmHbBofOffset_u;

/*REG_B2_PHY_AGC_ANT0_PM_IB_RSSI_BOF_OFFSET 0x1F4 */
typedef union
{
	uint32 val;
	struct
	{
		int32  pmIbRssiBofOffset : 9; //convert ib rssi power to backoff in 1/2 dB, reset value: 0x0, access type: RWS
		uint32 reserved0 : 23;
	} bitFields;
} RegB2PhyAgcAnt0PmIbRssiBofOffset_u;

/*REG_B2_PHY_AGC_ANT0_PM_IB_ACI_BOF_OFFSET 0x1F8 */
typedef union
{
	uint32 val;
	struct
	{
		int32  pmIbAciBofOffset : 9; //convert ib aci power to backoff in 1/2 dB, reset value: 0x0, access type: RWS
		uint32 reserved0 : 23;
	} bitFields;
} RegB2PhyAgcAnt0PmIbAciBofOffset_u;

/*REG_B2_PHY_AGC_ANT0_PM_DET_BOF_OFFSET 0x1FC */
typedef union
{
	uint32 val;
	struct
	{
		int32  pmDetBofOffset : 9; //convert det power to backoff in 1/2 dB, reset value: 0x0, access type: RWS
		uint32 reserved0 : 23;
	} bitFields;
} RegB2PhyAgcAnt0PmDetBofOffset_u;

/*REG_B2_PHY_AGC_ANT0_PM_BB_BOF_TARGET 0x200 */
typedef union
{
	uint32 val;
	struct
	{
		int32  pmBbBofTarget : 9; //target backoff from full scale at bb rssi in 1/2 dB, reset value: 0x0, access type: RWS
		uint32 reserved0 : 23;
	} bitFields;
} RegB2PhyAgcAnt0PmBbBofTarget_u;

/*REG_B2_PHY_AGC_ANT0_PM_HB_BOF_TARGET 0x204 */
typedef union
{
	uint32 val;
	struct
	{
		int32  pmHbBofTarget : 9; //target backoff from full scale at hb rssi in 1/2 dB, reset value: 0x0, access type: RWS
		uint32 reserved0 : 23;
	} bitFields;
} RegB2PhyAgcAnt0PmHbBofTarget_u;

/*REG_B2_PHY_AGC_ANT0_PM_IB_BOF_TARGET 0x208 */
typedef union
{
	uint32 val;
	struct
	{
		int32  pmIbBofTarget : 9; //target backoff from full scale at ib rssi in 1/2 dB, reset value: 0x0, access type: RWS
		uint32 reserved0 : 23;
	} bitFields;
} RegB2PhyAgcAnt0PmIbBofTarget_u;

/*REG_B2_PHY_AGC_ANT0_PM_DET_BOF_TARGET 0x20C */
typedef union
{
	uint32 val;
	struct
	{
		int32  pmDetBofTarget : 9; //target backoff from full scale at det rssi in 1/2 dB, reset value: 0x0, access type: RWS
		uint32 reserved0 : 23;
	} bitFields;
} RegB2PhyAgcAnt0PmDetBofTarget_u;

/*REG_B2_PHY_AGC_ANT0_PM_DIFI1_DB_GAIN 0x210 */
typedef union
{
	uint32 val;
	struct
	{
		int32  pmDifi1DbGain : 9; //difi1 gain in 1/2 dB must be equal to the linear gain of pm_difi1_gain , reset value: 0x0, access type: RWS
		uint32 reserved0 : 23;
	} bitFields;
} RegB2PhyAgcAnt0PmDifi1DbGain_u;

/*REG_B2_PHY_AGC_ANT0_PM_PRESET_LNA_PGC1 0x214 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 pmLnaIndexMaxGain : 4; //max gain lna index, reset value: 0x0, access type: RW
		uint32 pmLnaIndexStep1Gain : 4; //step1 env & signal are saturated, gain lna index, reset value: 0x0, access type: RW
		uint32 pmLnaIndexStep1EnvSatGain : 4; //step1 env only is saturated, gain lna index, reset value: 0x0, access type: RW
		uint32 pmLnaIndexStep1SignalSatGain : 4; //step1 signal only is saturated, gain lna index, reset value: 0x0, access type: RW
		uint32 pmPgc1IndexMaxGain : 3; //max gain pgc1 index, reset value: 0x0, access type: RW
		uint32 reserved0 : 1;
		uint32 pmPgc1IndexStep1Gain : 3; //step1 env & signal are satuarted gain pgc1 index, reset value: 0x0, access type: RW
		uint32 reserved1 : 1;
		uint32 pmPgc1IndexStep1EnvSatGain : 3; //step1 env only is saturated gain pgc1 index, reset value: 0x0, access type: RW
		uint32 reserved2 : 1;
		uint32 pmPgc1IndexStep1SignalSatGain : 3; //step1 signal only is saturated gain pgc1 index, reset value: 0x0, access type: RW
		uint32 reserved3 : 1;
	} bitFields;
} RegB2PhyAgcAnt0PmPresetLnaPgc1_u;

/*REG_B2_PHY_AGC_ANT0_PM_MAX_BB_DIGITAL_GAIN 0x218 */
typedef union
{
	uint32 val;
	struct
	{
		int32  pmMaxBbDigitalGain : 9; //max gain bb digital gain in 1/2 dB, reset value: 0x0, access type: RWS
		uint32 reserved0 : 23;
	} bitFields;
} RegB2PhyAgcAnt0PmMaxBbDigitalGain_u;

/*REG_B2_PHY_AGC_ANT0_PM_STEP1_BB_DIGITAL_GAIN 0x21C */
typedef union
{
	uint32 val;
	struct
	{
		int32  pmStep1BbDigitalGain : 9; //step1 env & signal are saturated gain bb digital gain in 1/2 dB, reset value: 0x0, access type: RWS
		uint32 reserved0 : 23;
	} bitFields;
} RegB2PhyAgcAnt0PmStep1BbDigitalGain_u;

/*REG_B2_PHY_AGC_ANT0_PM_STEP1_ENV_SAT_BB_DIGITAL_GAIN 0x220 */
typedef union
{
	uint32 val;
	struct
	{
		int32  pmStep1EnvSatBbDigitalGain : 9; //step1 env only is saturated gain bb digital gain in 1/2 dB, reset value: 0x0, access type: RWS
		uint32 reserved0 : 23;
	} bitFields;
} RegB2PhyAgcAnt0PmStep1EnvSatBbDigitalGain_u;

/*REG_B2_PHY_AGC_ANT0_PM_STEP1_SIGNAL_SAT_BB_DIGITAL_GAIN 0x224 */
typedef union
{
	uint32 val;
	struct
	{
		int32  pmStep1SignalSatBbDigitalGain : 9; //step1 signal only is saturated gain bb digital gain in 1/2 dB, reset value: 0x0, access type: RWS
		uint32 reserved0 : 23;
	} bitFields;
} RegB2PhyAgcAnt0PmStep1SignalSatBbDigitalGain_u;

/*REG_B2_PHY_AGC_ANT0_PM_MAX_HB_DIGITAL_GAIN 0x228 */
typedef union
{
	uint32 val;
	struct
	{
		int32  pmMaxHbDigitalGain : 9; //max gain hb digital gain in 1/2 dB, reset value: 0x0, access type: RWS
		uint32 reserved0 : 23;
	} bitFields;
} RegB2PhyAgcAnt0PmMaxHbDigitalGain_u;

/*REG_B2_PHY_AGC_ANT0_PM_STEP1_HB_DIGITAL_GAIN 0x22C */
typedef union
{
	uint32 val;
	struct
	{
		int32  pmStep1HbDigitalGain : 9; //step1 env & signal are saturated gain hb digital gain in 1/2 dB, reset value: 0x0, access type: RWS
		uint32 reserved0 : 23;
	} bitFields;
} RegB2PhyAgcAnt0PmStep1HbDigitalGain_u;

/*REG_B2_PHY_AGC_ANT0_PM_STEP1_ENV_SAT_HB_DIGITAL_GAIN 0x230 */
typedef union
{
	uint32 val;
	struct
	{
		int32  pmStep1EnvSatHbDigitalGain : 9; //step1 env only is saturated gain hb digital gain in 1/2 dB, reset value: 0x0, access type: RWS
		uint32 reserved0 : 23;
	} bitFields;
} RegB2PhyAgcAnt0PmStep1EnvSatHbDigitalGain_u;

/*REG_B2_PHY_AGC_ANT0_PM_STEP1_SIGNAL_SAT_HB_DIGITAL_GAIN 0x234 */
typedef union
{
	uint32 val;
	struct
	{
		int32  pmStep1SignalSatHbDigitalGain : 9; //step1 signal only is saturated gain hb digital gain in 1/2 dB, reset value: 0x0, access type: RWS
		uint32 reserved0 : 23;
	} bitFields;
} RegB2PhyAgcAnt0PmStep1SignalSatHbDigitalGain_u;

/*REG_B2_PHY_AGC_ANT0_PM_MAX_IB_DIGITAL_GAIN 0x238 */
typedef union
{
	uint32 val;
	struct
	{
		int32  pmMaxIbDigitalGain : 9; //max gain ib digital gain in 1/2 dB, reset value: 0x0, access type: RWS
		uint32 reserved0 : 23;
	} bitFields;
} RegB2PhyAgcAnt0PmMaxIbDigitalGain_u;

/*REG_B2_PHY_AGC_ANT0_PM_STEP1_IB_DIGITAL_GAIN 0x23C */
typedef union
{
	uint32 val;
	struct
	{
		int32  pmStep1IbDigitalGain : 9; //step1 env & signal are saturated, gain ib digital gain in 1/2 dB, reset value: 0x0, access type: RWS
		uint32 reserved0 : 23;
	} bitFields;
} RegB2PhyAgcAnt0PmStep1IbDigitalGain_u;

/*REG_B2_PHY_AGC_ANT0_PM_STEP1_ENV_SAT_IB_DIGITAL_GAIN 0x240 */
typedef union
{
	uint32 val;
	struct
	{
		int32  pmStep1EnvSatIbDigitalGain : 9; //step1 env only is saturated, gain ib digital gain in 1/2 dB, reset value: 0x0, access type: RWS
		uint32 reserved0 : 23;
	} bitFields;
} RegB2PhyAgcAnt0PmStep1EnvSatIbDigitalGain_u;

/*REG_B2_PHY_AGC_ANT0_PM_STEP1_SIGNAL_SAT_IB_DIGITAL_GAIN 0x244 */
typedef union
{
	uint32 val;
	struct
	{
		int32  pmStep1SignalSatIbDigitalGain : 9; //step1 signal only is saturated, gain ib digital gain in 1/2 dB, reset value: 0x0, access type: RWS
		uint32 reserved0 : 23;
	} bitFields;
} RegB2PhyAgcAnt0PmStep1SignalSatIbDigitalGain_u;

/*REG_B2_PHY_AGC_ANT0_PM_MAX_DET_DIGITAL_GAIN 0x248 */
typedef union
{
	uint32 val;
	struct
	{
		int32  pmMaxDetDigitalGain : 9; //max gain det digital gain in 1/2 dB, reset value: 0x0, access type: RWS
		uint32 reserved0 : 23;
	} bitFields;
} RegB2PhyAgcAnt0PmMaxDetDigitalGain_u;

/*REG_B2_PHY_AGC_ANT0_PM_STEP1_DET_DIGITAL_GAIN 0x24C */
typedef union
{
	uint32 val;
	struct
	{
		int32  pmStep1DetDigitalGain : 9; //step1 env & signal are saturated, gain det digital gain in 1/2 dB, reset value: 0x0, access type: RWS
		uint32 reserved0 : 23;
	} bitFields;
} RegB2PhyAgcAnt0PmStep1DetDigitalGain_u;

/*REG_B2_PHY_AGC_ANT0_PM_STEP1_ENV_SAT_DET_DIGITAL_GAIN 0x250 */
typedef union
{
	uint32 val;
	struct
	{
		int32  pmStep1EnvSatDetDigitalGain : 9; //step1 env only is saturated, gain det digital gain in 1/2 dB, reset value: 0x0, access type: RWS
		uint32 reserved0 : 23;
	} bitFields;
} RegB2PhyAgcAnt0PmStep1EnvSatDetDigitalGain_u;

/*REG_B2_PHY_AGC_ANT0_PM_STEP1_SIGNAL_SAT_DET_DIGITAL_GAIN 0x254 */
typedef union
{
	uint32 val;
	struct
	{
		int32  pmStep1SignalSatDetDigitalGain : 9; //step1 signal only is saturated, gain det digital gain in 1/2 dB, reset value: 0x0, access type: RWS
		uint32 reserved0 : 23;
	} bitFields;
} RegB2PhyAgcAnt0PmStep1SignalSatDetDigitalGain_u;

/*REG_B2_PHY_AGC_ANT0_ACC_RF_POWER 0x258 */
typedef union
{
	uint32 val;
	struct
	{
		int32  accRfPower : 9; //rf power reading locked at "table go" in 1/2 dB, reset value: 0x0, access type: ROS
		uint32 reserved0 : 23;
	} bitFields;
} RegB2PhyAgcAnt0AccRfPower_u;

/*REG_B2_PHY_AGC_ANT0_ACC_FB_POWER 0x25C */
typedef union
{
	uint32 val;
	struct
	{
		int32  accFbPower : 9; //fb power reading locked at "table go" in 1/2 dB, reset value: 0x0, access type: ROS
		uint32 reserved0 : 23;
	} bitFields;
} RegB2PhyAgcAnt0AccFbPower_u;

/*REG_B2_PHY_AGC_ANT0_ACC_BB_POWER 0x260 */
typedef union
{
	uint32 val;
	struct
	{
		int32  accBbPower : 9; //bb power reading locked at "table go" in 1/2 dB, reset value: 0x0, access type: ROS
		uint32 reserved0 : 23;
	} bitFields;
} RegB2PhyAgcAnt0AccBbPower_u;

/*REG_B2_PHY_AGC_ANT0_ACC_HB_POWER 0x264 */
typedef union
{
	uint32 val;
	struct
	{
		int32  accHbPower : 9; //hb power reading locked at "table go" in 1/2 dB, reset value: 0x0, access type: ROS
		uint32 reserved0 : 23;
	} bitFields;
} RegB2PhyAgcAnt0AccHbPower_u;

/*REG_B2_PHY_AGC_ANT0_ACC_IB_POWER 0x268 */
typedef union
{
	uint32 val;
	struct
	{
		int32  accIbPower : 9; //ib power reading locked at "table go" in 1/2 dB, reset value: 0x0, access type: ROS
		uint32 reserved0 : 23;
	} bitFields;
} RegB2PhyAgcAnt0AccIbPower_u;

/*REG_B2_PHY_AGC_ANT0_ACC_ACI_POWER 0x26C */
typedef union
{
	uint32 val;
	struct
	{
		int32  accAciPower : 9; //aci power reading locked at "table go" in 1/2 dB, reset value: 0x0, access type: ROS
		uint32 reserved0 : 23;
	} bitFields;
} RegB2PhyAgcAnt0AccAciPower_u;

/*REG_B2_PHY_AGC_ANT0_ACC_SIGNAL_POWER 0x270 */
typedef union
{
	uint32 val;
	struct
	{
		int32  accSignalPower : 9; //signal power reading locked at "table go" in 1/2 dB, reset value: 0x0, access type: ROS
		uint32 reserved0 : 23;
	} bitFields;
} RegB2PhyAgcAnt0AccSignalPower_u;

/*REG_B2_PHY_AGC_ANT0_ACC_ENV_POWER 0x274 */
typedef union
{
	uint32 val;
	struct
	{
		int32  accEnvPower : 9; //env power reading locked at "table go" in 1/2 dB, reset value: 0x0, access type: ROS
		uint32 reserved0 : 23;
	} bitFields;
} RegB2PhyAgcAnt0AccEnvPower_u;

/*REG_B2_PHY_AGC_ANT0_ACC_STATUS 0x278 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 accRfSat : 1; //rf rssi sat reading locked at "table go", reset value: 0x0, access type: RO
		uint32 accFbSat : 1; //fb rssi sat reading locked at "table go", reset value: 0x0, access type: RO
		uint32 accBbSat : 1; //bb rssi sat reading locked at "table go", reset value: 0x0, access type: RO
		uint32 accHbSat : 1; //hb rssi sat reading locked at "table go", reset value: 0x0, access type: RO
		uint32 accIbSat : 1; //ib rssi sat reading locked at "table go", reset value: 0x0, access type: RO
		uint32 accAciSat : 1; //aci rssi sat reading locked at "table go", reset value: 0x0, access type: RO
		uint32 accUpHbSat : 1; //up_hb rssi sat reading locked at "table go", reset value: 0x0, access type: RO
		uint32 accUpIbSat : 1; //up ib rssi sat reading locked at "table go", reset value: 0x0, access type: RO
		uint32 accUpAciSat : 1; //up aci rssi sat reading locked at "table go", reset value: 0x0, access type: RO
		uint32 accSignalLimitMax : 1; //signal power is bigger than pm_max_power_level, reset value: 0x0, access type: RO
		uint32 accSignalLimitMin : 1; //signal power is less than pm_min_power_level, reset value: 0x0, access type: RO
		uint32 accSignalSat : 1; //signal rssi sat reading locked at "table go", reset value: 0x0, access type: RO
		uint32 accEnvLimitMax : 1; //env power is bigger than pm_max_power_level, reset value: 0x0, access type: RO
		uint32 accEnvSat : 1; //env rssi sat reading locked at "table go", reset value: 0x0, access type: RO
		uint32 accEnvLimitMin : 1; //env power is less than pm_min_power_level, reset value: 0x0, access type: RO
		uint32 accSignalIsEnvValid : 1; //signal power is bigger than pm_signal_max_level, use env power instead, reset value: 0x0, access type: RO
		uint32 accEnvIsSignalValid : 1; //env power is less than pm_env_min_level, use signal power instead, reset value: 0x0, access type: RO
		uint32 reserved0 : 15;
	} bitFields;
} RegB2PhyAgcAnt0AccStatus_u;

/*REG_B2_PHY_AGC_ANT0_ACC_RF_SYSTEM_GAIN 0x27C */
typedef union
{
	uint32 val;
	struct
	{
		int32  accRfSystemGain : 9; //rf system gain accelerator calculation result in 1/2 dB, reset value: 0x0, access type: ROS
		uint32 reserved0 : 23;
	} bitFields;
} RegB2PhyAgcAnt0AccRfSystemGain_u;

/*REG_B2_PHY_AGC_ANT0_ACC_FB_SYSTEM_GAIN 0x280 */
typedef union
{
	uint32 val;
	struct
	{
		int32  accFbSystemGain : 9; //fb system gain accelerator calculation result in 1/2 dB, reset value: 0x0, access type: ROS
		uint32 reserved0 : 23;
	} bitFields;
} RegB2PhyAgcAnt0AccFbSystemGain_u;

/*REG_B2_PHY_AGC_ANT0_ACC_BB_SYSTEM_GAIN 0x284 */
typedef union
{
	uint32 val;
	struct
	{
		int32  accBbSystemGain : 9; //bb system gain accelerator calculation result in 1/2 dB, reset value: 0x0, access type: ROS
		uint32 reserved0 : 23;
	} bitFields;
} RegB2PhyAgcAnt0AccBbSystemGain_u;

/*REG_B2_PHY_AGC_ANT0_ACC_POST_BB_SYSTEM_GAIN 0x288 */
typedef union
{
	uint32 val;
	struct
	{
		int32  accPostBbSystemGain : 9; //pre bb system gain accelerator calculation result in 1/2 dB, reset value: 0x0, access type: ROS
		uint32 reserved0 : 23;
	} bitFields;
} RegB2PhyAgcAnt0AccPostBbSystemGain_u;

/*REG_B2_PHY_AGC_ANT0_ACC_HB_SYSTEM_GAIN 0x28C */
typedef union
{
	uint32 val;
	struct
	{
		int32  accHbSystemGain : 9; //hb system gain accelerator calculation result in 1/2 dB, reset value: 0x0, access type: ROS
		uint32 reserved0 : 23;
	} bitFields;
} RegB2PhyAgcAnt0AccHbSystemGain_u;

/*REG_B2_PHY_AGC_ANT0_ACC_IB_SYSTEM_GAIN 0x290 */
typedef union
{
	uint32 val;
	struct
	{
		int32  accIbSystemGain : 9; //ib system gain accelerator calculation result in 1/2 dB, reset value: 0x0, access type: ROS
		uint32 reserved0 : 23;
	} bitFields;
} RegB2PhyAgcAnt0AccIbSystemGain_u;

/*REG_B2_PHY_AGC_ANT0_ACC_ACI_SYSTEM_GAIN 0x294 */
typedef union
{
	uint32 val;
	struct
	{
		int32  accAciSystemGain : 9; //aci system gain accelerator calculation result in 1/2 dB, reset value: 0x0, access type: ROS
		uint32 reserved0 : 23;
	} bitFields;
} RegB2PhyAgcAnt0AccAciSystemGain_u;

/*REG_B2_PHY_AGC_ANT0_ACC_CCA_SYSTEM_GAIN 0x298 */
typedef union
{
	uint32 val;
	struct
	{
		int32  accCcaSystemGain : 9; //cca system gain accelerator calculation result in 1/2 dB, reset value: 0x0, access type: ROS
		uint32 reserved0 : 23;
	} bitFields;
} RegB2PhyAgcAnt0AccCcaSystemGain_u;

/*REG_B2_PHY_AGC_ANT0_ACC_DET_SYSTEM_GAIN 0x29C */
typedef union
{
	uint32 val;
	struct
	{
		int32  accDetSystemGain : 9; //det system gain accelerator calculation result in 1/2 dB, reset value: 0x0, access type: ROS
		uint32 reserved0 : 23;
	} bitFields;
} RegB2PhyAgcAnt0AccDetSystemGain_u;

/*REG_B2_PHY_AGC_ANT0_ACC_BB_DIGITAL_GAIN 0x2A0 */
typedef union
{
	uint32 val;
	struct
	{
		int32  accBbDigitalGain : 9; //bb digital gain accelerator calculation result in 1/2 dB, reset value: 0x0, access type: ROS
		uint32 reserved0 : 23;
	} bitFields;
} RegB2PhyAgcAnt0AccBbDigitalGain_u;

/*REG_B2_PHY_AGC_ANT0_ACC_HB_DIGITAL_GAIN 0x2A4 */
typedef union
{
	uint32 val;
	struct
	{
		int32  accHbDigitalGain : 9; //hb digital gain accelerator calculation result in 1/2 dB, reset value: 0x0, access type: ROS
		uint32 reserved0 : 23;
	} bitFields;
} RegB2PhyAgcAnt0AccHbDigitalGain_u;

/*REG_B2_PHY_AGC_ANT0_ACC_IB_DIGITAL_GAIN 0x2A8 */
typedef union
{
	uint32 val;
	struct
	{
		int32  accIbDigitalGain : 9; //ib digital gain accelerator calculation result in 1/2 dB, reset value: 0x0, access type: ROS
		uint32 reserved0 : 23;
	} bitFields;
} RegB2PhyAgcAnt0AccIbDigitalGain_u;

/*REG_B2_PHY_AGC_ANT0_ACC_DET_DIGITAL_GAIN 0x2AC */
typedef union
{
	uint32 val;
	struct
	{
		int32  accDetDigitalGain : 9; //det digital gain accelerator calculation result in 1/2 dB, reset value: 0x0, access type: ROS
		uint32 reserved0 : 23;
	} bitFields;
} RegB2PhyAgcAnt0AccDetDigitalGain_u;

/*REG_B2_PHY_AGC_ANT0_ACC_BB_BOF 0x2B0 */
typedef union
{
	uint32 val;
	struct
	{
		int32  accBbBof : 9; //bb backoff accelerator calculation result in 1/2 dB pre bb digital gain, reset value: 0x0, access type: ROS
		uint32 reserved0 : 23;
	} bitFields;
} RegB2PhyAgcAnt0AccBbBof_u;

/*REG_B2_PHY_AGC_ANT0_ACC_BB_TOTAL_DIGITAL_GAIN 0x2B4 */
typedef union
{
	uint32 val;
	struct
	{
		int32  accBbTotalDigitalGain : 9; //bb_total_digital_gain accelerator calculation result in 1/2 dB, reset value: 0x0, access type: ROS
		uint32 reserved0 : 23;
	} bitFields;
} RegB2PhyAgcAnt0AccBbTotalDigitalGain_u;

/*REG_B2_PHY_AGC_ANT0_ACC_BB_DIGITAL_BOF 0x2B8 */
typedef union
{
	uint32 val;
	struct
	{
		int32  accBbDigitalBof : 9; //bb_digital_bof accelerator calculation result in 1/2 dB post bb digital gain, reset value: 0x0, access type: ROS
		uint32 reserved0 : 23;
	} bitFields;
} RegB2PhyAgcAnt0AccBbDigitalBof_u;

/*REG_B2_PHY_AGC_ANT0_ACC_HB_BOF 0x2BC */
typedef union
{
	uint32 val;
	struct
	{
		int32  accHbBof : 9; //hb backoff accelerator calculation result in 1/2 dB pre bb digital gain, reset value: 0x0, access type: ROS
		uint32 reserved0 : 23;
	} bitFields;
} RegB2PhyAgcAnt0AccHbBof_u;

/*REG_B2_PHY_AGC_ANT0_ACC_HB_TOTAL_DIGITAL_GAIN 0x2C0 */
typedef union
{
	uint32 val;
	struct
	{
		int32  accHbTotalDigitalGain : 9; //hb_total_digital_gain accelerator calculation result in 1/2 dB, reset value: 0x0, access type: ROS
		uint32 reserved0 : 23;
	} bitFields;
} RegB2PhyAgcAnt0AccHbTotalDigitalGain_u;

/*REG_B2_PHY_AGC_ANT0_ACC_HB_DIGITAL_BOF 0x2C4 */
typedef union
{
	uint32 val;
	struct
	{
		int32  accHbDigitalBof : 9; //hb_digital_bof accelerator calculation result in 1/2 dB post bb digital gain, reset value: 0x0, access type: ROS
		uint32 reserved0 : 23;
	} bitFields;
} RegB2PhyAgcAnt0AccHbDigitalBof_u;

/*REG_B2_PHY_AGC_ANT0_ACC_IB_BOF 0x2C8 */
typedef union
{
	uint32 val;
	struct
	{
		int32  accIbBof : 9; //ib backoff accelerator calculation result in 1/2 dB pre ib digital gain, reset value: 0x0, access type: ROS
		uint32 reserved0 : 23;
	} bitFields;
} RegB2PhyAgcAnt0AccIbBof_u;

/*REG_B2_PHY_AGC_ANT0_ACC_IB_TOTAL_DIGITAL_GAIN 0x2CC */
typedef union
{
	uint32 val;
	struct
	{
		int32  accIbTotalDigitalGain : 9; //sum of ib digital gain compunents: agc acceleration, pm and hw (bw compensation), reset value: 0x0, access type: ROS
		uint32 reserved0 : 23;
	} bitFields;
} RegB2PhyAgcAnt0AccIbTotalDigitalGain_u;

/*REG_B2_PHY_AGC_ANT0_ACC_IB_DIGITAL_BOF 0x2D0 */
typedef union
{
	uint32 val;
	struct
	{
		int32  accIbDigitalBof : 9; //ib_digital_bof accelerator calculation result in 1/2 dB post ib digital gain, reset value: 0x0, access type: ROS
		uint32 reserved0 : 23;
	} bitFields;
} RegB2PhyAgcAnt0AccIbDigitalBof_u;

/*REG_B2_PHY_AGC_ANT0_ACC_DET_BOF 0x2D4 */
typedef union
{
	uint32 val;
	struct
	{
		int32  accDetBof : 9; //det backoff accelerator calculation result in 1/2 dB pre ib digital gain, reset value: 0x0, access type: ROS
		uint32 reserved0 : 23;
	} bitFields;
} RegB2PhyAgcAnt0AccDetBof_u;

/*REG_B2_PHY_AGC_ANT0_ACC_DET_TOTAL_DIGITAL_GAIN 0x2D8 */
typedef union
{
	uint32 val;
	struct
	{
		int32  accDetTotalDigitalGain : 9; //sum of det digital gain compunents: agc acceleration, pm and hw (bw compensation), reset value: 0x0, access type: ROS
		uint32 reserved0 : 23;
	} bitFields;
} RegB2PhyAgcAnt0AccDetTotalDigitalGain_u;

/*REG_B2_PHY_AGC_ANT0_ACC_DET_DIGITAL_BOF 0x2DC */
typedef union
{
	uint32 val;
	struct
	{
		int32  accDetDigitalBof : 9; //det_digital_bof accelerator calculation result in 1/2 dB post ib digital gain, reset value: 0x0, access type: ROS
		uint32 reserved0 : 23;
	} bitFields;
} RegB2PhyAgcAnt0AccDetDigitalBof_u;

/*REG_B2_PHY_AGC_ANT0_ACC_DC_OFFSET_I 0x2E0 */
typedef union
{
	uint32 val;
	struct
	{
		int32  accDcOffsetI : 14; //chosen dc Q offset according to bw,pgc1_index,lna_index, reset value: 0x0, access type: ROS
		uint32 reserved0 : 18;
	} bitFields;
} RegB2PhyAgcAnt0AccDcOffsetI_u;

/*REG_B2_PHY_AGC_ANT0_ACC_DC_OFFSET_Q 0x2E4 */
typedef union
{
	uint32 val;
	struct
	{
		int32  accDcOffsetQ : 14; //chosen dc I offset according to bw,pgc1_index,lna_index, reset value: 0x0, access type: ROS
		uint32 reserved0 : 18;
	} bitFields;
} RegB2PhyAgcAnt0AccDcOffsetQ_u;

/*REG_B2_PHY_AGC_ANT0_PM_AGC_RAMS_RM 0x2E8 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 pmAgcTableRm : 3; //agc_gsp_table_rm, reset value: 0x3, access type: RW
		uint32 reserved0 : 29;
	} bitFields;
} RegB2PhyAgcAnt0PmAgcRamsRm_u;

/*REG_B2_PHY_AGC_ANT0_ACC_GAIN_VALUES 0x2EC */
typedef union
{
	uint32 val;
	struct
	{
		uint32 accLnaIndex : 4; //calculated lna_index, reset value: 0x0, access type: RO
		uint32 accSelS2DRx : 1; //calculated sel_s2d_rx, reset value: 0x0, access type: RO
		uint32 accPgc1Index : 3; //calculated pgc1_index, reset value: 0x0, access type: RO
		uint32 accRxFilter : 6; //calculated rx_filter tuning word, reset value: 0x0, access type: RO
		uint32 reserved0 : 18;
	} bitFields;
} RegB2PhyAgcAnt0AccGainValues_u;

/*REG_B2_PHY_AGC_ANT0_PM_FCSI_CONTROL 0x2F0 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 pmFcsiEnable : 1; //enable fcsi , reset value: 0x0, access type: RW
		uint32 pmFcsiHeader : 2; //header upper 1 bits of fcsi , reset value: 0x0, access type: RW
		uint32 reserved0 : 5;
		uint32 pmFcsiAddress : 7; //fcsi_address, reset value: 0x0, access type: RW
		uint32 reserved1 : 17;
	} bitFields;
} RegB2PhyAgcAnt0PmFcsiControl_u;

/*REG_B2_PHY_AGC_ANT0_ACC_FCSI_VALUES 0x2F8 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 accFcsiData : 16; //data which is sent to rfic via fcsi, reset value: 0x0, access type: RO
		uint32 reserved0 : 16;
	} bitFields;
} RegB2PhyAgcAnt0AccFcsiValues_u;

/*REG_B2_PHY_AGC_ANT0_ACC_GAIN_ACC_CONTROL 0x2FC */
typedef union
{
	uint32 val;
	struct
	{
		uint32 accDelayTimer : 16; //read acc_delay_timer counting, 0 means no timer, reset value: 0x0, access type: RO
		uint32 accStmCounter : 5; //read acc_stm_counter counting, 0 means no ongoing acceleration, reset value: 0x0, access type: RO
		uint32 reserved0 : 3;
		uint32 accFcsiBusy : 1; //fcsi_busy, 0 means no fcsi access, reset value: 0x0, access type: RO
		uint32 reserved1 : 7;
	} bitFields;
} RegB2PhyAgcAnt0AccGainAccControl_u;

/*REG_B2_PHY_AGC_ANT0_PM_IB_CODE_ACC_THR 0x300 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 pmIbTimerThr : 16; //pm_ib_timer_thr, reset value: 0x0, access type: RW
		uint32 pmIbReleaseThr : 16; //pm_ib_release_thr, reset value: 0x0, access type: RW
	} bitFields;
} RegB2PhyAgcAnt0PmIbCodeAccThr_u;

/*REG_B2_PHY_AGC_ANT0_PM_BB_CODE_ACC_THR 0x304 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 pmBbTimerThr : 16; //pm_bb_timer_thr, reset value: 0x0, access type: RW
		uint32 pmBbReleaseThr : 16; //pm_bb_release_thr, reset value: 0x0, access type: RW
	} bitFields;
} RegB2PhyAgcAnt0PmBbCodeAccThr_u;

/*REG_B2_PHY_AGC_ANT0_PM_LONGTERM_RELEASE_THR 0x308 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 pmLongtermReleaseThr : 16; //pm_longterm_release_thr, reset value: 0x0, access type: RW
		uint32 reserved0 : 16;
	} bitFields;
} RegB2PhyAgcAnt0PmLongtermReleaseThr_u;

/*REG_B2_PHY_AGC_ANT0_PM_LONGTERM_THR 0x30C */
typedef union
{
	uint32 val;
	struct
	{
		int32  pmLongtermThr : 9; //pm_longterm_thr, reset value: 0x0, access type: RWS
		uint32 reserved0 : 23;
	} bitFields;
} RegB2PhyAgcAnt0PmLongtermThr_u;

/*REG_B2_PHY_AGC_ANT0_PM_BB_POWER_FAST_LOW_THR 0x310 */
typedef union
{
	uint32 val;
	struct
	{
		int32  pmBbPowerFastLowThr : 9; //pm_bb_power_fast_low_thr, reset value: 0x0, access type: RWS
		uint32 reserved0 : 23;
	} bitFields;
} RegB2PhyAgcAnt0PmBbPowerFastLowThr_u;

/*REG_B2_PHY_AGC_ANT0_PM_DELTA_CODE_ACC_THR 0x314 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 pmBbDeltaThr : 9; //pm_bb_delta_thr, reset value: 0x0, access type: RW
		uint32 reserved0 : 7;
		uint32 pmIbDeltaThr : 9; //pm_ib_delta_thr, reset value: 0x0, access type: RW
		uint32 reserved1 : 7;
	} bitFields;
} RegB2PhyAgcAnt0PmDeltaCodeAccThr_u;

/*REG_B2_PHY_AGC_ANT0_PM_BB_POWER_UP_THR 0x318 */
typedef union
{
	uint32 val;
	struct
	{
		int32  pmBbPowerUpThr : 9; //pm_bb_power_up_thr, reset value: 0x0, access type: RWS
		uint32 reserved0 : 23;
	} bitFields;
} RegB2PhyAgcAnt0PmBbPowerUpThr_u;

/*REG_B2_PHY_AGC_ANT0_PM_BB_POWER_SLOW_LOW_THR 0x31C */
typedef union
{
	uint32 val;
	struct
	{
		int32  pmBbPowerSlowLowThr : 9; //pm_bb_power_slow_low_thr, reset value: 0x0, access type: RWS
		uint32 reserved0 : 23;
	} bitFields;
} RegB2PhyAgcAnt0PmBbPowerSlowLowThr_u;

/*REG_B2_PHY_AGC_ANT0_PM_IB_POWER_UP_THR 0x320 */
typedef union
{
	uint32 val;
	struct
	{
		int32  pmIbPowerUpThr : 9; //pm_ib_power_up_thr, reset value: 0x0, access type: RWS
		uint32 reserved0 : 23;
	} bitFields;
} RegB2PhyAgcAnt0PmIbPowerUpThr_u;

/*REG_B2_PHY_AGC_ANT0_PM_IB_POWER_SLOW_LOW_THR 0x324 */
typedef union
{
	uint32 val;
	struct
	{
		int32  pmIbPowerSlowLowThr : 9; //pm_ib_power_slow_low_thr, reset value: 0x0, access type: RWS
		uint32 reserved0 : 23;
	} bitFields;
} RegB2PhyAgcAnt0PmIbPowerSlowLowThr_u;

/*REG_B2_PHY_AGC_ANT0_PM_SET_CODE_ACC_THR_CTRL 0x328 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 pmSetBbThrCtrl : 1; //set_bb_thr_ctrl: 1 -from pm, 0- from hw accelerator, reset value: 0x0, access type: RW
		uint32 pmSetIbThrCtrl : 1; //set_ib_thr_ctrl: 1 -from pm, 0- from hw accelerator, reset value: 0x0, access type: RW
		uint32 reserved0 : 30;
	} bitFields;
} RegB2PhyAgcAnt0PmSetCodeAccThrCtrl_u;

/*REG_B2_PHY_AGC_ANT0_PM_ALGO_CTRL 0x32C */
typedef union
{
	uint32 val;
	struct
	{
		uint32 pmAlgoCtrl : 16; //code acclerator algo ctrl, reset value: 0x0, access type: RW
		uint32 reserved0 : 16;
	} bitFields;
} RegB2PhyAgcAnt0PmAlgoCtrl_u;

/*REG_B2_PHY_AGC_ANT0_ACC_EVENT_STATUS 0x330 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 accCodeAccEventType : 9; //code acc event, reset value: 0x0, access type: RO
		uint32 reserved0 : 3;
		uint32 accCodeAccEventIndication : 1; //code acc event bit wise or, reset value: 0x0, access type: RO
		uint32 reserved1 : 19;
	} bitFields;
} RegB2PhyAgcAnt0AccEventStatus_u;

/*REG_B2_PHY_AGC_ANT0_PM_BB_TH_SET_INC_GAP_DB 0x334 */
typedef union
{
	uint32 val;
	struct
	{
		int32  pmBbThSetIncGapDb : 9; //margin to add above measured bb power to calculate energy increase threshold in 1/2 dB, reset value: 0x0, access type: RWS
		uint32 reserved0 : 23;
	} bitFields;
} RegB2PhyAgcAnt0PmBbThSetIncGapDb_u;

/*REG_B2_PHY_AGC_ANT0_PM_BB_TH_SET_DEC_GAP_DB 0x338 */
typedef union
{
	uint32 val;
	struct
	{
		int32  pmBbThSetDecGapDb : 9; //margin to substract below measured bb power to calculate energy deccrease threshold in 1/2 dB, reset value: 0x0, access type: RWS
		uint32 reserved0 : 23;
	} bitFields;
} RegB2PhyAgcAnt0PmBbThSetDecGapDb_u;

/*REG_B2_PHY_AGC_ANT0_PM_BB_TH_UP_EXTRA_GAP_DB 0x33C */
typedef union
{
	uint32 val;
	struct
	{
		int32  pmBbThUpExtraGapDb : 9; //margin used inorder to limit enery increase threhold for high bb power in 1/2 dB, reset value: 0x0, access type: RWS
		uint32 reserved0 : 23;
	} bitFields;
} RegB2PhyAgcAnt0PmBbThUpExtraGapDb_u;

/*REG_B2_PHY_AGC_ANT0_PM_BB_POWER_UP_DEF_THR 0x340 */
typedef union
{
	uint32 val;
	struct
	{
		int32  pmBbPowerUpDefThr : 9; //default energy increases bb power threshold in 1/2 dB, reset value: 0x0, access type: RWS
		uint32 reserved0 : 23;
	} bitFields;
} RegB2PhyAgcAnt0PmBbPowerUpDefThr_u;

/*REG_B2_PHY_AGC_ANT0_PM_BB_POWER_SLOW_LOW_MIN_THR 0x344 */
typedef union
{
	uint32 val;
	struct
	{
		int32  pmBbPowerSlowLowMinThr : 9; //default energy decrease bb power threshold in 1/2 dB, reset value: 0x0, access type: RWS
		uint32 reserved0 : 23;
	} bitFields;
} RegB2PhyAgcAnt0PmBbPowerSlowLowMinThr_u;

/*REG_B2_PHY_AGC_ANT0_PM_IB_TH_SET_INC_GAP_DB 0x348 */
typedef union
{
	uint32 val;
	struct
	{
		int32  pmIbThSetIncGapDb : 9; //margin to add above measured ib power to calculate energy increase threshold in 1/2 dB, reset value: 0x0, access type: RWS
		uint32 reserved0 : 23;
	} bitFields;
} RegB2PhyAgcAnt0PmIbThSetIncGapDb_u;

/*REG_B2_PHY_AGC_ANT0_PM_IB_TH_SET_DEC_GAP_DB 0x34C */
typedef union
{
	uint32 val;
	struct
	{
		int32  pmIbThSetDecGapDb : 9; //margin to substract below measured ib power to calculate energy deccrease threshold in 1/2 dB, reset value: 0x0, access type: RWS
		uint32 reserved0 : 23;
	} bitFields;
} RegB2PhyAgcAnt0PmIbThSetDecGapDb_u;

/*REG_B2_PHY_AGC_ANT0_PM_IB_TH_UP_EXTRA_GAP_DB 0x350 */
typedef union
{
	uint32 val;
	struct
	{
		int32  pmIbThUpExtraGapDb : 9; //margin used inorder to limit enery increase threhold for high ib power in 1/2 dB, reset value: 0x0, access type: RWS
		uint32 reserved0 : 23;
	} bitFields;
} RegB2PhyAgcAnt0PmIbThUpExtraGapDb_u;

/*REG_B2_PHY_AGC_ANT0_PM_IB_POWER_UP_DEF_THR 0x354 */
typedef union
{
	uint32 val;
	struct
	{
		int32  pmIbPowerUpDefThr : 9; //default energy increases ib power threshold in 1/2 dB, reset value: 0x0, access type: RWS
		uint32 reserved0 : 23;
	} bitFields;
} RegB2PhyAgcAnt0PmIbPowerUpDefThr_u;

/*REG_B2_PHY_AGC_ANT0_PM_IB_POWER_SLOW_LOW_MIN_THR 0x358 */
typedef union
{
	uint32 val;
	struct
	{
		int32  pmIbPowerSlowLowMinThr : 9; //default energy decrease ib power threshold in 1/2 dB, reset value: 0x0, access type: RWS
		uint32 reserved0 : 23;
	} bitFields;
} RegB2PhyAgcAnt0PmIbPowerSlowLowMinThr_u;

/*REG_B2_PHY_AGC_ANT0_ACC_BB_POWER_UP_THR 0x35C */
typedef union
{
	uint32 val;
	struct
	{
		int32  accBbPowerUpThr : 9; //bb energy increase threshold acceleration result, reset value: 0x0, access type: ROS
		uint32 reserved0 : 23;
	} bitFields;
} RegB2PhyAgcAnt0AccBbPowerUpThr_u;

/*REG_B2_PHY_AGC_ANT0_ACC_BB_POWER_SLOW_LOW_THR 0x360 */
typedef union
{
	uint32 val;
	struct
	{
		int32  accBbPowerSlowLowThr : 9; //bb energy deccrease threshold acceleration result, reset value: 0x0, access type: ROS
		uint32 reserved0 : 23;
	} bitFields;
} RegB2PhyAgcAnt0AccBbPowerSlowLowThr_u;

/*REG_B2_PHY_AGC_ANT0_ACC_IB_POWER_UP_THR 0x364 */
typedef union
{
	uint32 val;
	struct
	{
		int32  accIbPowerUpThr : 9; //ib energy increase threshold acceleration result, reset value: 0x0, access type: ROS
		uint32 reserved0 : 23;
	} bitFields;
} RegB2PhyAgcAnt0AccIbPowerUpThr_u;

/*REG_B2_PHY_AGC_ANT0_ACC_IB_POWER_SLOW_LOW_THR 0x368 */
typedef union
{
	uint32 val;
	struct
	{
		int32  accIbPowerSlowLowThr : 9; //ib energy deccrease threshold acceleration result, reset value: 0x0, access type: ROS
		uint32 reserved0 : 23;
	} bitFields;
} RegB2PhyAgcAnt0AccIbPowerSlowLowThr_u;

/*REG_B2_PHY_AGC_ANT0_CALC_AGC_GAIN_WORD 0x36C */
typedef union
{
	uint32 val;
	struct
	{
		uint32 calcTableGo : 1; //trigger agc gain accleration, reset value: 0x0, access type: WO
		uint32 reserved0 : 2;
		uint32 calcSetCalibration : 1; //calc_set_calibration, reset value: 0x0, access type: RW
		uint32 calcSetMaxGain : 1; //calc_set_max_gain, reset value: 0x0, access type: RW
		uint32 calcSetStep1Gain : 1; //calc_set_step1_gain, reset value: 0x0, access type: RW
		uint32 calcNewLna : 1; //calc_new_lna, reset value: 0x0, access type: RW
		uint32 calcNewPgc1 : 1; //calc_new_pgc1, reset value: 0x0, access type: RW
		uint32 calcNewBbDigitalGain : 1; //calc_new_bb_digital_gain after difi2, reset value: 0x0, access type: RW
		uint32 calcNewHbDigitalGain : 1; //calc_new_hb_digital_gain after pre filter, reset value: 0x0, access type: RW
		uint32 calcNewIbDigitalGain : 1; //calc_new_ib_digital_gain after channel filter, reset value: 0x0, access type: RW
		uint32 calcNewDetDigitalGain : 1; //calc_new_det_digital_gain after band select for detector, reset value: 0x0, access type: RW
		uint32 calcNewDcValues : 1; //calc_new_dc_values offset after difi2, reset value: 0x0, access type: RW
		uint32 calcNewBlockerType : 1; //calc new blocker type, reset value: 0x0, access type: RW
		uint32 reserved1 : 1;
		uint32 calcNoRfAccess : 1; //calc new gain without rf access, reset value: 0x0, access type: RW
		uint32 reserved2 : 16;
	} bitFields;
} RegB2PhyAgcAnt0CalcAgcGainWord_u;

/*REG_B2_PHY_AGC_ANT0_CALC_AGC_STM_CLEAR_CONTROL 0x370 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 calcClearAgcTimers : 1; //clear agc timers in code acceleator stm, reset value: 0x0, access type: WO
		uint32 calcClearAgcEventType : 1; //clea agc event in code accelerator stm, reset value: 0x0, access type: WO
		uint32 calcClearAgcMaskOp : 1; //disable code accelerator, reset value: 0x0, access type: WO
		uint32 reserved0 : 29;
	} bitFields;
} RegB2PhyAgcAnt0CalcAgcStmClearControl_u;

/*REG_B2_PHY_AGC_ANT0_CALC_ACC_AUTO_CLOSE_MODE 0x374 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 calcAccAutoCloseMode : 1; //enables code acceleration, reset value: 0x0, access type: RW
		uint32 reserved0 : 31;
	} bitFields;
} RegB2PhyAgcAnt0CalcAccAutoCloseMode_u;

/*REG_B2_PHY_AGC_ANT0_CALC_POWER_THR_ACC_GO 0x378 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 calcBbPowerThrAccGo : 1; //calc_bb_power_thr_acc_go, reset value: 0x0, access type: WO
		uint32 calcIbPowerThrAccGo : 1; //calc_ib_power_thr_acc_go, reset value: 0x0, access type: WO
		uint32 reserved0 : 30;
	} bitFields;
} RegB2PhyAgcAnt0CalcPowerThrAccGo_u;

/*REG_B2_PHY_AGC_ANT0_CALC_AGC_GAIN_CANCEL 0x37C */
typedef union
{
	uint32 val;
	struct
	{
		uint32 calcAgcGainCancel : 1; //cancels gain acceleration timer and cancels table go, reset value: 0x0, access type: WO
		uint32 reserved0 : 31;
	} bitFields;
} RegB2PhyAgcAnt0CalcAgcGainCancel_u;

/*REG_B2_PHY_AGC_ANT0_DISABLE_PERIPHERALS 0x380 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 disablePeripherals : 1; //disable_peripherals, reset value: 0x0, access type: RW
		uint32 reserved0 : 31;
	} bitFields;
} RegB2PhyAgcAnt0DisablePeripherals_u;

/*REG_B2_PHY_AGC_ANT0_AGC_STM_RDBACK 0x384 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 agcStmRdback : 6; //agc_stm_rdback, reset value: 0x0, access type: RO
		uint32 reserved0 : 26;
	} bitFields;
} RegB2PhyAgcAnt0AgcStmRdback_u;

/*REG_B2_PHY_AGC_ANT0_PM_MAX_LIMIT_ACC_BB_DIGITAL_GAIN 0x388 */
typedef union
{
	uint32 val;
	struct
	{
		int32  pmMaxLimitAccBbDigitalGain : 9; //max limit for bb digital gain after acceleration, reset value: 0x54, access type: RWS
		uint32 reserved0 : 23;
	} bitFields;
} RegB2PhyAgcAnt0PmMaxLimitAccBbDigitalGain_u;

/*REG_B2_PHY_AGC_ANT0_PM_MIN_LIMIT_ACC_BB_DIGITAL_GAIN 0x38C */
typedef union
{
	uint32 val;
	struct
	{
		int32  pmMinLimitAccBbDigitalGain : 9; //min limit for bb digital gain after acceleration, reset value: 0x1F4, access type: RWS
		uint32 reserved0 : 23;
	} bitFields;
} RegB2PhyAgcAnt0PmMinLimitAccBbDigitalGain_u;

/*REG_B2_PHY_AGC_ANT0_PM_MAX_LIMIT_ACC_HB_DIGITAL_GAIN 0x390 */
typedef union
{
	uint32 val;
	struct
	{
		int32  pmMaxLimitAccHbDigitalGain : 9; //max limit for hb digital gain after acceleration, reset value: 0x54, access type: RWS
		uint32 reserved0 : 23;
	} bitFields;
} RegB2PhyAgcAnt0PmMaxLimitAccHbDigitalGain_u;

/*REG_B2_PHY_AGC_ANT0_PM_MIN_LIMIT_ACC_HB_DIGITAL_GAIN 0x394 */
typedef union
{
	uint32 val;
	struct
	{
		int32  pmMinLimitAccHbDigitalGain : 9; //min limit for hb digital gain after acceleration, reset value: 0x1F4, access type: RWS
		uint32 reserved0 : 23;
	} bitFields;
} RegB2PhyAgcAnt0PmMinLimitAccHbDigitalGain_u;

/*REG_B2_PHY_AGC_ANT0_PM_MAX_LIMIT_ACC_IB_DIGITAL_GAIN 0x398 */
typedef union
{
	uint32 val;
	struct
	{
		int32  pmMaxLimitAccIbDigitalGain : 9; //max limit for ib digital gain after acceleration, reset value: 0x54, access type: RWS
		uint32 reserved0 : 23;
	} bitFields;
} RegB2PhyAgcAnt0PmMaxLimitAccIbDigitalGain_u;

/*REG_B2_PHY_AGC_ANT0_PM_MIN_LIMIT_ACC_IB_DIGITAL_GAIN 0x39C */
typedef union
{
	uint32 val;
	struct
	{
		int32  pmMinLimitAccIbDigitalGain : 9; //min limit for ib digital gain after acceleration, reset value: 0x1F4, access type: RWS
		uint32 reserved0 : 23;
	} bitFields;
} RegB2PhyAgcAnt0PmMinLimitAccIbDigitalGain_u;

/*REG_B2_PHY_AGC_ANT0_PM_MAX_LIMIT_ACC_DET_DIGITAL_GAIN 0x3A0 */
typedef union
{
	uint32 val;
	struct
	{
		int32  pmMaxLimitAccDetDigitalGain : 9; //max limit for det digital gain after acceleration, reset value: 0x54, access type: RWS
		uint32 reserved0 : 23;
	} bitFields;
} RegB2PhyAgcAnt0PmMaxLimitAccDetDigitalGain_u;

/*REG_B2_PHY_AGC_ANT0_PM_MIN_LIMIT_ACC_DET_DIGITAL_GAIN 0x3A4 */
typedef union
{
	uint32 val;
	struct
	{
		int32  pmMinLimitAccDetDigitalGain : 9; //min limit for det digital gain after acceleration, reset value: 0x1F4, access type: RWS
		uint32 reserved0 : 23;
	} bitFields;
} RegB2PhyAgcAnt0PmMinLimitAccDetDigitalGain_u;

/*REG_B2_PHY_AGC_ANT0_BLOCKER_CONTROL 0x3C0 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 pmBlockerType : 2; //pm blocker type, reset value: 0x0, access type: RW
		uint32 reserved0 : 2;
		uint32 accBlockerType : 2; //selected blocker type, reset value: 0x0, access type: RO
		uint32 reserved1 : 26;
	} bitFields;
} RegB2PhyAgcAnt0BlockerControl_u;

/*REG_B2_PHY_AGC_ANT0_PM_BLOCKER_TH 0x3C4 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 pmBsAdjAltTh : 8; //threshold for adj alt between LSB and USB in 1 db, reset value: 0x0, access type: RW
		uint32 pmEnvAltTh : 8; //threshold for alt on env, reset value: 0x0, access type: RW
		uint32 pmEnvSigAltTh : 8; //threshold for alt on env compare to sig, reset value: 0x0, access type: RW
		uint32 reserved0 : 8;
	} bitFields;
} RegB2PhyAgcAnt0PmBlockerTh_u;

/*REG_B2_PHY_AGC_ANT0_PM_ALGO_CTRL_SEL 0x3D0 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 pmAlgoCtrlSelIn0 : 3; //select source in0: 0-rf, 1-fb, 2-bb, 3-hb, 4-ib, 5-aci, reset value: 0x2, access type: RW
		uint32 reserved0 : 1;
		uint32 pmAlgoCtrlSelIn1 : 3; //select source in1: 0-rf, 1-fb, 2-bb, 3-hb, 4-ib, 5-aci, reset value: 0x3, access type: RW
		uint32 reserved1 : 25;
	} bitFields;
} RegB2PhyAgcAnt0PmAlgoCtrlSel_u;

/*REG_B2_PHY_AGC_ANT0_ACC_BLOCKER_ADDR 0x3D4 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 accLsbBlockerAddr : 7; //lsb blocker address, reset value: 0x0, access type: RO
		uint32 reserved0 : 1;
		uint32 accUsbBlockerAddr : 7; //usb blocker address, reset value: 0x0, access type: RO
		uint32 reserved1 : 17;
	} bitFields;
} RegB2PhyAgcAnt0AccBlockerAddr_u;

/*REG_B2_PHY_AGC_ANT0_UP_INB_RSSI_PARAMS_REG 0x400 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 upInbandRssiBlkSize : 3; //up inband rssi decimatiion, 2^(block size), reset value: 0x0, access type: RW
		uint32 reserved0 : 4;
		uint32 upInbandRssiIirPole : 4; //up inband rssi iir pole, reset value: 0x0, access type: RW
		uint32 upInbandRssiIirPoleMin : 3; //up inband rssi iir shift, reset value: 0x0, access type: RW
		uint32 upInbandRssiOffset1 : 16; //up inband rssi offset1, reset value: 0x0, access type: RW
		uint32 upInbandRssiCancelDc : 1; //up inband cancel DC in power calculation (1 - remove dc, 0 - no remove), reset value: 0x0, access type: RW
		uint32 reserved1 : 1;
	} bitFields;
} RegB2PhyAgcAnt0UpInbRssiParamsReg_u;

/*REG_B2_PHY_AGC_ANT0_UP_INB_RSSI_OFFSET2_REG 0x404 */
typedef union
{
	uint32 val;
	struct
	{
		int32  upInbandRssiOffset2 : 9; //up inband rssi offset2, used for digital to power dBm conversion, reset value: 0x0, access type: RWS
		uint32 reserved0 : 23;
	} bitFields;
} RegB2PhyAgcAnt0UpInbRssiOffset2Reg_u;

/*REG_B2_PHY_AGC_ANT0_UP_INBAND_RSSI_SYSTEM_GAIN_REG 0x408 */
typedef union
{
	uint32 val;
	struct
	{
		int32  upInbandRssiSystemGain : 9; //up inband rssi system gain from progmodel, reset value: 0x0, access type: RWS
		uint32 reserved0 : 23;
	} bitFields;
} RegB2PhyAgcAnt0UpInbandRssiSystemGainReg_u;

/*REG_B2_PHY_AGC_ANT0_UP_INBAND_RSSI_SYSTEM_GAIN_SELECT_REG 0x40C */
typedef union
{
	uint32 val;
	struct
	{
		uint32 upInbandRssiSystemGainHwSelect : 1; //up inband rssi system gain selection: 1 from hw, 0 from pm, reset value: 0x0, access type: RW
		uint32 reserved0 : 31;
	} bitFields;
} RegB2PhyAgcAnt0UpInbandRssiSystemGainSelectReg_u;

/*REG_B2_PHY_AGC_ANT0_UP_INBAND_RSSI_SAT_THR 0x410 */
typedef union
{
	uint32 val;
	struct
	{
		int32  upInbandRssiSatThr : 9; //up inband rssi saturation threshold, reset value: 0x0, access type: RWS
		uint32 reserved0 : 23;
	} bitFields;
} RegB2PhyAgcAnt0UpInbandRssiSatThr_u;

/*REG_B2_PHY_AGC_ANT0_UP_HB_RSSI_PARAMS_REG 0x414 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 upHbRssiBlkSize : 3; //up hb rssi decimatiion, 2^(block size), reset value: 0x0, access type: RW
		uint32 reserved0 : 4;
		uint32 upHbRssiIirPole : 4; //up hb rssi iir pole, reset value: 0x0, access type: RW
		uint32 upHbRssiIirPoleMin : 3; //up hb rssi iir shift, reset value: 0x0, access type: RW
		uint32 upHbRssiOffset1 : 16; //up hb rssi offset1, reset value: 0x0, access type: RW
		uint32 upHbRssiCancelDc : 1; //up hb rssi cancel DC in power calculation (1 - remove dc, 0 - no remove), reset value: 0x0, access type: RW
		uint32 reserved1 : 1;
	} bitFields;
} RegB2PhyAgcAnt0UpHbRssiParamsReg_u;

/*REG_B2_PHY_AGC_ANT0_UP_HB_RSSI_OFFSET2_REG 0x418 */
typedef union
{
	uint32 val;
	struct
	{
		int32  upHbRssiOffset2 : 9; //up hb rssi offset2, used for digital to power dBm conversion, reset value: 0x0, access type: RWS
		uint32 reserved0 : 23;
	} bitFields;
} RegB2PhyAgcAnt0UpHbRssiOffset2Reg_u;

/*REG_B2_PHY_AGC_ANT0_UP_HB_RSSI_SYSTEM_GAIN_REG 0x41C */
typedef union
{
	uint32 val;
	struct
	{
		int32  upHbRssiSystemGain : 9; //up hb rssi system gain from progmodel, reset value: 0x0, access type: RWS
		uint32 reserved0 : 23;
	} bitFields;
} RegB2PhyAgcAnt0UpHbRssiSystemGainReg_u;

/*REG_B2_PHY_AGC_ANT0_UP_HB_RSSI_SYSTEM_GAIN_SELECT_REG 0x420 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 upHbRssiSystemGainHwSelect : 1; //up hb rssi system gain selection: 1 from hw, 0 from pm, reset value: 0x0, access type: RW
		uint32 reserved0 : 31;
	} bitFields;
} RegB2PhyAgcAnt0UpHbRssiSystemGainSelectReg_u;

/*REG_B2_PHY_AGC_ANT0_UP_HB_RSSI_SAT_THR 0x424 */
typedef union
{
	uint32 val;
	struct
	{
		int32  upHbRssiSatThr : 9; //up hb rssi saturation threshold, reset value: 0x0, access type: RWS
		uint32 reserved0 : 23;
	} bitFields;
} RegB2PhyAgcAnt0UpHbRssiSatThr_u;

/*REG_B2_PHY_AGC_ANT0_UP_IB_RSSI_REG 0x428 */
typedef union
{
	uint32 val;
	struct
	{
		int32  upIbRssi : 9; //up IB RSSI output, reset value: 0x0, access type: ROS
		uint32 reserved0 : 23;
	} bitFields;
} RegB2PhyAgcAnt0UpIbRssiReg_u;

/*REG_B2_PHY_AGC_ANT0_UP_IB_POWER_REG 0x42C */
typedef union
{
	uint32 val;
	struct
	{
		int32  upIbPower : 9; //up IB power output (0.5 dB), reset value: 0x0, access type: ROS
		uint32 reserved0 : 23;
	} bitFields;
} RegB2PhyAgcAnt0UpIbPowerReg_u;

/*REG_B2_PHY_AGC_ANT0_UP_IB_SRSSI_REG 0x430 */
typedef union
{
	uint32 val;
	struct
	{
		int32  upIbSrssi : 9; //up IB RSSI, slow IIR decimation , reset value: 0x0, access type: ROS
		uint32 reserved0 : 23;
	} bitFields;
} RegB2PhyAgcAnt0UpIbSrssiReg_u;

/*REG_B2_PHY_AGC_ANT0_UP_IB_SPOWER_REG 0x434 */
typedef union
{
	uint32 val;
	struct
	{
		int32  upIbSpower : 9; //up IB Spower output (0.5 dB) slow IIR decimation , reset value: 0x0, access type: ROS
		uint32 reserved0 : 23;
	} bitFields;
} RegB2PhyAgcAnt0UpIbSpowerReg_u;

/*REG_B2_PHY_AGC_ANT0_UP_IB_PWR_DIFF_REG 0x438 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 upIbB1 : 9; //up IB power delta  (diff between 2 last samples, abs(Rn-R(n-1))), reset value: 0x0, access type: RO
		uint32 upIbB2 : 9; //up IB power delta (delay diffs, (abs(R(n-1)-R(n-2)), reset value: 0x0, access type: RO
		uint32 reserved0 : 14;
	} bitFields;
} RegB2PhyAgcAnt0UpIbPwrDiffReg_u;

/*REG_B2_PHY_AGC_ANT0_UP_HB_RSSI_REG 0x43C */
typedef union
{
	uint32 val;
	struct
	{
		int32  upHbRssi : 9; //up HB RSSI output, reset value: 0x0, access type: ROS
		uint32 reserved0 : 23;
	} bitFields;
} RegB2PhyAgcAnt0UpHbRssiReg_u;

/*REG_B2_PHY_AGC_ANT0_UP_HB_POWER_REG 0x440 */
typedef union
{
	uint32 val;
	struct
	{
		int32  upHbPower : 9; //up HB power output (0.5 dB), reset value: 0x0, access type: ROS
		uint32 reserved0 : 23;
	} bitFields;
} RegB2PhyAgcAnt0UpHbPowerReg_u;

/*REG_B2_PHY_AGC_ANT0_UP_HB_SRSSI_REG 0x444 */
typedef union
{
	uint32 val;
	struct
	{
		int32  upHbSrssi : 9; //up HB RSSI, slow IIR decimation , reset value: 0x0, access type: ROS
		uint32 reserved0 : 23;
	} bitFields;
} RegB2PhyAgcAnt0UpHbSrssiReg_u;

/*REG_B2_PHY_AGC_ANT0_UP_HB_SPOWER_REG 0x448 */
typedef union
{
	uint32 val;
	struct
	{
		int32  upHbSpower : 9; //up HB Spower output (0.5 dB) slow IIR decimation , reset value: 0x0, access type: ROS
		uint32 reserved0 : 23;
	} bitFields;
} RegB2PhyAgcAnt0UpHbSpowerReg_u;

/*REG_B2_PHY_AGC_ANT0_UP_HB_PWR_DIFF_REG 0x44C */
typedef union
{
	uint32 val;
	struct
	{
		uint32 upHbB1 : 9; //up HB power delta  (diff between 2 last samples, abs(Rn-R(n-1))), reset value: 0x0, access type: RO
		uint32 upHbB2 : 9; //up HB power delta (delay diffs, (abs(R(n-1)-R(n-2)), reset value: 0x0, access type: RO
		uint32 reserved0 : 14;
	} bitFields;
} RegB2PhyAgcAnt0UpHbPwrDiffReg_u;

/*REG_B2_PHY_AGC_ANT0_PM_UP_HB_POWER 0x450 */
typedef union
{
	uint32 val;
	struct
	{
		int32  pmUpHbPower : 9; //programmble up hb power to gain acceleration in 1/2 dB, reset value: 0x0, access type: RWS
		uint32 reserved0 : 23;
	} bitFields;
} RegB2PhyAgcAnt0PmUpHbPower_u;

/*REG_B2_PHY_AGC_ANT0_PM_UP_IB_POWER 0x454 */
typedef union
{
	uint32 val;
	struct
	{
		int32  pmUpIbPower : 9; //programmble up ib power to gain acceleration in 1/2 dB, reset value: 0x0, access type: RWS
		uint32 reserved0 : 23;
	} bitFields;
} RegB2PhyAgcAnt0PmUpIbPower_u;

/*REG_B2_PHY_AGC_ANT0_PM_UP_ACI_POWER 0x458 */
typedef union
{
	uint32 val;
	struct
	{
		int32  pmUpAciPower : 9; //programmble up aci power to gain acceleration in 1/2 dB, reset value: 0x0, access type: RWS
		uint32 reserved0 : 23;
	} bitFields;
} RegB2PhyAgcAnt0PmUpAciPower_u;

/*REG_B2_PHY_AGC_ANT0_ACC_UP_HB_POWER 0x45C */
typedef union
{
	uint32 val;
	struct
	{
		int32  accUpHbPower : 9; //up hb power reading locked at "table go" in 1/2 dB, reset value: 0x0, access type: ROS
		uint32 reserved0 : 23;
	} bitFields;
} RegB2PhyAgcAnt0AccUpHbPower_u;

/*REG_B2_PHY_AGC_ANT0_ACC_UP_IB_POWER 0x460 */
typedef union
{
	uint32 val;
	struct
	{
		int32  accUpIbPower : 9; //up ib power reading locked at "table go" in 1/2 dB, reset value: 0x0, access type: ROS
		uint32 reserved0 : 23;
	} bitFields;
} RegB2PhyAgcAnt0AccUpIbPower_u;

/*REG_B2_PHY_AGC_ANT0_ACC_UP_ACI_POWER 0x464 */
typedef union
{
	uint32 val;
	struct
	{
		int32  accUpAciPower : 9; //up aci power reading locked at "table go" in 1/2 dB, reset value: 0x0, access type: ROS
		uint32 reserved0 : 23;
	} bitFields;
} RegB2PhyAgcAnt0AccUpAciPower_u;

/*REG_B2_PHY_AGC_ANT0_UP_CONTROL 0x468 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 hbIsMax : 1; //for gain accelerator hb is max between up and lo / else is primary, reset value: 0x0, access type: RW
		uint32 ibIsMax : 1; //for gain accelerator ib is max between up and lo / else is primary, reset value: 0x0, access type: RW
		uint32 aciIsMax : 1; //for gain accelerator aci is max between up and lo / else is primary, reset value: 0x0, access type: RW
		uint32 reserved0 : 1;
		uint32 hbSysGainSource : 2; //hb source: 0 - lo is lo & up is up, 1-primary for both, 2- max for both, reset value: 0x0, access type: RW
		uint32 ibSysGainSource : 2; //ib source: 0 - lo is lo & up is up, 1-primary for both, 2- max for both, reset value: 0x0, access type: RW
		uint32 aciSysGainSource : 2; //aci source: 0 - lo is lo & up is up, 1-primary for both, 2- max for both, reset value: 0x0, access type: RW
		uint32 reserved1 : 2;
		uint32 eventHbIsMax : 1; //for event accelerator hb is max between up and lo / else is primary, reset value: 0x0, access type: RW
		uint32 eventIbIsMax : 1; //for event accelerator ib is max between up and lo / else is primary, reset value: 0x0, access type: RW
		uint32 eventAciIsMax : 1; //for event accelerator aci is max between up and lo / else is primary, reset value: 0x0, access type: RW
		uint32 reserved2 : 17;
	} bitFields;
} RegB2PhyAgcAnt0UpControl_u;

/*REG_B2_PHY_AGC_ANT0_PM_UP_HB_SYSTEM_GAIN_OFFSET 0x46C */
typedef union
{
	uint32 val;
	struct
	{
		int32  pmUpHbSystemGainOffset : 9; //offset for up hb gain acceleration  (may be used to overcome unexpected constant gain in HW) in 1/2 dB, reset value: 0x0, access type: RWS
		uint32 reserved0 : 23;
	} bitFields;
} RegB2PhyAgcAnt0PmUpHbSystemGainOffset_u;

/*REG_B2_PHY_AGC_ANT0_PM_UP_IB_SYSTEM_GAIN_OFFSET 0x470 */
typedef union
{
	uint32 val;
	struct
	{
		int32  pmUpIbSystemGainOffset : 9; //offset for up ib gain acceleration  (may be used to overcome unexpected constant gain in HW) in 1/2 dB, reset value: 0x0, access type: RWS
		uint32 reserved0 : 23;
	} bitFields;
} RegB2PhyAgcAnt0PmUpIbSystemGainOffset_u;

/*REG_B2_PHY_AGC_ANT0_PM_UP_ACI_SYSTEM_GAIN_OFFSET 0x474 */
typedef union
{
	uint32 val;
	struct
	{
		int32  pmUpAciSystemGainOffset : 9; //offset for up aci gain acceleration  (may be used to overcome unexpected constant gain in HW) in 1/2 dB, reset value: 0x0, access type: RWS
		uint32 reserved0 : 23;
	} bitFields;
} RegB2PhyAgcAnt0PmUpAciSystemGainOffset_u;

/*REG_B2_PHY_AGC_ANT0_PM_UP_CCA_SYSTEM_GAIN_OFFSET 0x478 */
typedef union
{
	uint32 val;
	struct
	{
		int32  pmUpCcaSystemGainOffset : 9; //offset for up cca gain acceleration  (may be used to overcome unexpected constant gain in HW) in 1/2 dB, reset value: 0x0, access type: RWS
		uint32 reserved0 : 23;
	} bitFields;
} RegB2PhyAgcAnt0PmUpCcaSystemGainOffset_u;

/*REG_B2_PHY_AGC_ANT0_PM_UP_HB_BOF_OFFSET 0x47C */
typedef union
{
	uint32 val;
	struct
	{
		int32  pmUpHbBofOffset : 9; //convert up hb rssi power to backoff in 1/2 dB, reset value: 0x0, access type: RWS
		uint32 reserved0 : 23;
	} bitFields;
} RegB2PhyAgcAnt0PmUpHbBofOffset_u;

/*REG_B2_PHY_AGC_ANT0_PM_UP_IB_RSSI_BOF_OFFSET 0x480 */
typedef union
{
	uint32 val;
	struct
	{
		int32  pmUpIbRssiBofOffset : 9; //convert up ib rssi power to backoff in 1/2 dB, reset value: 0x0, access type: RWS
		uint32 reserved0 : 23;
	} bitFields;
} RegB2PhyAgcAnt0PmUpIbRssiBofOffset_u;

/*REG_B2_PHY_AGC_ANT0_PM_UP_IB_ACI_BOF_OFFSET 0x484 */
typedef union
{
	uint32 val;
	struct
	{
		int32  pmUpIbAciBofOffset : 9; //convert up ib aci power to backoff in 1/2 dB, reset value: 0x0, access type: RWS
		uint32 reserved0 : 23;
	} bitFields;
} RegB2PhyAgcAnt0PmUpIbAciBofOffset_u;

/*REG_B2_PHY_AGC_ANT0_PM_UP_HB_BOF_TARGET 0x488 */
typedef union
{
	uint32 val;
	struct
	{
		int32  pmUpHbBofTarget : 9; //target backoff from full scale at up hb rssi in 1/2 dB, reset value: 0x0, access type: RWS
		uint32 reserved0 : 23;
	} bitFields;
} RegB2PhyAgcAnt0PmUpHbBofTarget_u;

/*REG_B2_PHY_AGC_ANT0_PM_UP_IB_BOF_TARGET 0x48C */
typedef union
{
	uint32 val;
	struct
	{
		int32  pmUpIbBofTarget : 9; //target backoff from full scale at up ib rssi in 1/2 dB, reset value: 0x0, access type: RWS
		uint32 reserved0 : 23;
	} bitFields;
} RegB2PhyAgcAnt0PmUpIbBofTarget_u;

/*REG_B2_PHY_AGC_ANT0_ACC_UP_HB_SYSTEM_GAIN 0x490 */
typedef union
{
	uint32 val;
	struct
	{
		int32  accUpHbSystemGain : 9; //up hb system gain accelerator calculation result in 1/2 dB, reset value: 0x0, access type: ROS
		uint32 reserved0 : 23;
	} bitFields;
} RegB2PhyAgcAnt0AccUpHbSystemGain_u;

/*REG_B2_PHY_AGC_ANT0_ACC_UP_IB_SYSTEM_GAIN 0x494 */
typedef union
{
	uint32 val;
	struct
	{
		int32  accUpIbSystemGain : 9; //up ib system gain accelerator calculation result in 1/2 dB, reset value: 0x0, access type: ROS
		uint32 reserved0 : 23;
	} bitFields;
} RegB2PhyAgcAnt0AccUpIbSystemGain_u;

/*REG_B2_PHY_AGC_ANT0_ACC_UP_ACI_SYSTEM_GAIN 0x498 */
typedef union
{
	uint32 val;
	struct
	{
		int32  accUpAciSystemGain : 9; //up aci system gain accelerator calculation result in 1/2 dB, reset value: 0x0, access type: ROS
		uint32 reserved0 : 23;
	} bitFields;
} RegB2PhyAgcAnt0AccUpAciSystemGain_u;

/*REG_B2_PHY_AGC_ANT0_ACC_UP_CCA_SYSTEM_GAIN 0x49C */
typedef union
{
	uint32 val;
	struct
	{
		int32  accUpCcaSystemGain : 9; //up cca system gain accelerator calculation result in 1/2 dB, reset value: 0x0, access type: ROS
		uint32 reserved0 : 23;
	} bitFields;
} RegB2PhyAgcAnt0AccUpCcaSystemGain_u;

/*REG_B2_PHY_AGC_ANT0_ACC_UP_HB_DIGITAL_GAIN 0x4A0 */
typedef union
{
	uint32 val;
	struct
	{
		int32  accUpHbDigitalGain : 9; //up hb digital gain accelerator calculation result in 1/2 dB, reset value: 0x0, access type: ROS
		uint32 reserved0 : 23;
	} bitFields;
} RegB2PhyAgcAnt0AccUpHbDigitalGain_u;

/*REG_B2_PHY_AGC_ANT0_ACC_UP_IB_DIGITAL_GAIN 0x4A4 */
typedef union
{
	uint32 val;
	struct
	{
		int32  accUpIbDigitalGain : 9; //up ib digital gain accelerator calculation result in 1/2 dB, reset value: 0x0, access type: ROS
		uint32 reserved0 : 23;
	} bitFields;
} RegB2PhyAgcAnt0AccUpIbDigitalGain_u;

/*REG_B2_PHY_AGC_ANT0_ACC_UP_HB_BOF 0x4A8 */
typedef union
{
	uint32 val;
	struct
	{
		int32  accUpHbBof : 9; //up hb backoff accelerator calculation result in 1/2 dB pre bb digital gain, reset value: 0x0, access type: ROS
		uint32 reserved0 : 23;
	} bitFields;
} RegB2PhyAgcAnt0AccUpHbBof_u;

/*REG_B2_PHY_AGC_ANT0_ACC_UP_HB_TOTAL_DIGITAL_GAIN 0x4AC */
typedef union
{
	uint32 val;
	struct
	{
		int32  accUpHbTotalDigitalGain : 9; //up hb_total_digital_gain accelerator calculation result in 1/2 dB, reset value: 0x0, access type: ROS
		uint32 reserved0 : 23;
	} bitFields;
} RegB2PhyAgcAnt0AccUpHbTotalDigitalGain_u;

/*REG_B2_PHY_AGC_ANT0_ACC_UP_HB_DIGITAL_BOF 0x4B0 */
typedef union
{
	uint32 val;
	struct
	{
		int32  accUpHbDigitalBof : 9; //up hb_digital_bof accelerator calculation result in 1/2 dB post bb digital gain, reset value: 0x0, access type: ROS
		uint32 reserved0 : 23;
	} bitFields;
} RegB2PhyAgcAnt0AccUpHbDigitalBof_u;

/*REG_B2_PHY_AGC_ANT0_ACC_UP_IB_BOF 0x4B4 */
typedef union
{
	uint32 val;
	struct
	{
		int32  accUpIbBof : 9; //up ib backoff accelerator calculation result in 1/2 dB pre ib digital gain, reset value: 0x0, access type: ROS
		uint32 reserved0 : 23;
	} bitFields;
} RegB2PhyAgcAnt0AccUpIbBof_u;

/*REG_B2_PHY_AGC_ANT0_ACC_UP_IB_TOTAL_DIGITAL_GAIN 0x4B8 */
typedef union
{
	uint32 val;
	struct
	{
		int32  accUpIbTotalDigitalGain : 9; //sum of up ib digital gain compunents: agc acceleration, pm and hw (bw compensation), reset value: 0x0, access type: ROS
		uint32 reserved0 : 23;
	} bitFields;
} RegB2PhyAgcAnt0AccUpIbTotalDigitalGain_u;

/*REG_B2_PHY_AGC_ANT0_ACC_UP_IB_DIGITAL_BOF 0x4BC */
typedef union
{
	uint32 val;
	struct
	{
		int32  accUpIbDigitalBof : 9; //up_ib_digital_bof accelerator calculation result in 1/2 dB post ib digital gain, reset value: 0x0, access type: ROS
		uint32 reserved0 : 23;
	} bitFields;
} RegB2PhyAgcAnt0AccUpIbDigitalBof_u;

/*REG_B2_PHY_AGC_ANT0_PM_ACC_GAIN_SAT_SOURCES 0x4C0 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 pmAccGainEnvSatSource : 3; //acc_gain_env_sat_source: 0- from rf, 1-from fb, 2 - from bb, reset value: 0x0, access type: RW
		uint32 reserved0 : 5;
		uint32 pmAccGainSignalSatSource : 7; //acc_gain_signal_source: 0-from BB, 1-from IB, 2-from Aci, 3- from HB, 4-up_ib, 5-up_aci,6-up_hb, reset value: 0x0, access type: RW
		uint32 reserved1 : 17;
	} bitFields;
} RegB2PhyAgcAnt0PmAccGainSatSources_u;

/*REG_B2_PHY_AGC_ANT0_PM_LNA_GAIN_LUT_0 0x4C4 */
typedef union
{
	uint32 val;
	struct
	{
		int32  pmLnaGainLut0 : 9; //lna gain in db for lna_index 0 in 1/2 dB, reset value: 0x0, access type: RWS
		uint32 reserved0 : 23;
	} bitFields;
} RegB2PhyAgcAnt0PmLnaGainLut0_u;

/*REG_B2_PHY_AGC_ANT0_PM_LNA_GAIN_LUT_1 0x4C8 */
typedef union
{
	uint32 val;
	struct
	{
		int32  pmLnaGainLut1 : 9; //lna gain in db for lna_index 1 in 1/2 dB, reset value: 0x0, access type: RWS
		uint32 reserved0 : 23;
	} bitFields;
} RegB2PhyAgcAnt0PmLnaGainLut1_u;

/*REG_B2_PHY_AGC_ANT0_PM_LNA_GAIN_LUT_2 0x4CC */
typedef union
{
	uint32 val;
	struct
	{
		int32  pmLnaGainLut2 : 9; //lna gain in db for lna_index 2 in 1/2 dB, reset value: 0x0, access type: RWS
		uint32 reserved0 : 23;
	} bitFields;
} RegB2PhyAgcAnt0PmLnaGainLut2_u;

/*REG_B2_PHY_AGC_ANT0_PM_LNA_GAIN_LUT_3 0x4D0 */
typedef union
{
	uint32 val;
	struct
	{
		int32  pmLnaGainLut3 : 9; //lna gain in db for lna_index 3 in 1/2 dB, reset value: 0x0, access type: RWS
		uint32 reserved0 : 23;
	} bitFields;
} RegB2PhyAgcAnt0PmLnaGainLut3_u;

/*REG_B2_PHY_AGC_ANT0_PM_LNA_GAIN_LUT_4 0x4D4 */
typedef union
{
	uint32 val;
	struct
	{
		int32  pmLnaGainLut4 : 9; //lna gain in db for lna_index 4 in 1/2 dB, reset value: 0x0, access type: RWS
		uint32 reserved0 : 23;
	} bitFields;
} RegB2PhyAgcAnt0PmLnaGainLut4_u;

/*REG_B2_PHY_AGC_ANT0_PM_LNA_GAIN_LUT_5 0x4D8 */
typedef union
{
	uint32 val;
	struct
	{
		int32  pmLnaGainLut5 : 9; //lna gain in db for lna_index 5 in 1/2 dB, reset value: 0x0, access type: RWS
		uint32 reserved0 : 23;
	} bitFields;
} RegB2PhyAgcAnt0PmLnaGainLut5_u;

/*REG_B2_PHY_AGC_ANT0_PM_LNA_GAIN_LUT_6 0x4DC */
typedef union
{
	uint32 val;
	struct
	{
		int32  pmLnaGainLut6 : 9; //lna gain in db for lna_index 6 in 1/2 dB, reset value: 0x0, access type: RWS
		uint32 reserved0 : 23;
	} bitFields;
} RegB2PhyAgcAnt0PmLnaGainLut6_u;

/*REG_B2_PHY_AGC_ANT0_PM_LNA_GAIN_LUT_7 0x4E0 */
typedef union
{
	uint32 val;
	struct
	{
		int32  pmLnaGainLut7 : 9; //lna gain in db for lna_index 7 in 1/2 dB, reset value: 0x0, access type: RWS
		uint32 reserved0 : 23;
	} bitFields;
} RegB2PhyAgcAnt0PmLnaGainLut7_u;

/*REG_B2_PHY_AGC_ANT0_PM_LNA_GAIN_LUT_8 0x4E4 */
typedef union
{
	uint32 val;
	struct
	{
		int32  pmLnaGainLut8 : 9; //lna gain in db for lna_index 8 in 1/2 dB, reset value: 0x0, access type: RWS
		uint32 reserved0 : 23;
	} bitFields;
} RegB2PhyAgcAnt0PmLnaGainLut8_u;

/*REG_B2_PHY_AGC_ANT0_PM_LNA_GAIN_LUT_9 0x4E8 */
typedef union
{
	uint32 val;
	struct
	{
		int32  pmLnaGainLut9 : 9; //lna gain in db for lna_index 9 in 1/2 dB, reset value: 0x0, access type: RWS
		uint32 reserved0 : 23;
	} bitFields;
} RegB2PhyAgcAnt0PmLnaGainLut9_u;

/*REG_B2_PHY_AGC_ANT0_PM_LNA_GAIN_LUT_10 0x4EC */
typedef union
{
	uint32 val;
	struct
	{
		int32  pmLnaGainLut10 : 9; //lna gain in db for lna_index 10 in 1/2 dB, reset value: 0x0, access type: RWS
		uint32 reserved0 : 23;
	} bitFields;
} RegB2PhyAgcAnt0PmLnaGainLut10_u;

/*REG_B2_PHY_AGC_ANT0_PM_LNA_GAIN_LUT_11 0x4F0 */
typedef union
{
	uint32 val;
	struct
	{
		int32  pmLnaGainLut11 : 9; //lna gain in db for lna_index 11 in 1/2 dB, reset value: 0x0, access type: RWS
		uint32 reserved0 : 23;
	} bitFields;
} RegB2PhyAgcAnt0PmLnaGainLut11_u;

/*REG_B2_PHY_AGC_ANT0_PM_LNA_GAIN_LUT_12 0x4F4 */
typedef union
{
	uint32 val;
	struct
	{
		int32  pmLnaGainLut12 : 9; //lna gain in db for lna_index 12 in 1/2 dB, reset value: 0x0, access type: RWS
		uint32 reserved0 : 23;
	} bitFields;
} RegB2PhyAgcAnt0PmLnaGainLut12_u;

/*REG_B2_PHY_AGC_ANT0_PM_LNA_GAIN_LUT_13 0x4F8 */
typedef union
{
	uint32 val;
	struct
	{
		int32  pmLnaGainLut13 : 9; //lna gain in db for lna_index 13 in 1/2 dB, reset value: 0x0, access type: RWS
		uint32 reserved0 : 23;
	} bitFields;
} RegB2PhyAgcAnt0PmLnaGainLut13_u;

/*REG_B2_PHY_AGC_ANT0_PM_BS_ABS_TH_B0_B4 0x500 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 pmBsAbsThB0 : 8; //absolut threshold for for blocker in 1 db resolution for band 0, reset value: 0x0, access type: RW
		uint32 pmBsAbsThB1 : 8; //absolut threshold for for blocker in 1 db resolution for band 1, reset value: 0x0, access type: RW
		uint32 pmBsAbsThB2 : 8; //absolut threshold for for blocker in 1 db resolution for band 2, reset value: 0x0, access type: RW
		uint32 pmBsAbsThB3 : 8; //absolut threshold for for blocker in 1 db resolution for band 3, reset value: 0x0, access type: RW
	} bitFields;
} RegB2PhyAgcAnt0PmBsAbsThB0B4_u;

/*REG_B2_PHY_AGC_ANT0_PM_BS_ABS_TH_B5_B7 0x504 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 pmBsAbsThB4 : 8; //absolut threshold for for blocker in 1 db resolution for band 4, reset value: 0x0, access type: RW
		uint32 pmBsAbsThB5 : 8; //absolut threshold for for blocker in 1 db resolution for band 5, reset value: 0x0, access type: RW
		uint32 pmBsAbsThB6 : 8; //absolut threshold for for blocker in 1 db resolution for band 6, reset value: 0x0, access type: RW
		uint32 pmBsAbsThB7 : 8; //absolut threshold for for blocker in 1 db resolution for band 7, reset value: 0x0, access type: RW
	} bitFields;
} RegB2PhyAgcAnt0PmBsAbsThB5B7_u;

/*REG_B2_PHY_AGC_ANT0_PM_BS_ABS_TH_B8_B11 0x508 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 pmBsAbsThB8 : 8; //absolut threshold for for blocker in 1 db resolution for band 8, reset value: 0x0, access type: RW
		uint32 pmBsAbsThB9 : 8; //absolut threshold for for blocker in 1 db resolution for band 9, reset value: 0x0, access type: RW
		uint32 pmBsAbsThB10 : 8; //absolut threshold for for blocker in 1 db resolution for band 10, reset value: 0x0, access type: RW
		uint32 pmBsAbsThB11 : 8; //absolut threshold for for blocker in 1 db resolution for band 11, reset value: 0x0, access type: RW
	} bitFields;
} RegB2PhyAgcAnt0PmBsAbsThB8B11_u;

/*REG_B2_PHY_AGC_ANT0_PM_BS_OFF_TH_B0_B4 0x50C */
typedef union
{
	uint32 val;
	struct
	{
		uint32 pmBsOffThB0 : 8; //relative threshold for for blocker in 1 db resolution for band 0, reset value: 0x0, access type: RW
		uint32 pmBsOffThB1 : 8; //relative threshold for for blocker in 1 db resolution for band 1, reset value: 0x0, access type: RW
		uint32 pmBsOffThB2 : 8; //relative threshold for for blocker in 1 db resolution for band 2, reset value: 0x0, access type: RW
		uint32 pmBsOffThB3 : 8; //relative threshold for for blocker in 1 db resolution for band 3, reset value: 0x0, access type: RW
	} bitFields;
} RegB2PhyAgcAnt0PmBsOffThB0B4_u;

/*REG_B2_PHY_AGC_ANT0_PM_BS_OFF_TH_B5_B7 0x510 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 pmBsOffThB4 : 8; //relative threshold for for blocker in 1 db resolution for band 4, reset value: 0x0, access type: RW
		uint32 pmBsOffThB5 : 8; //relative threshold for for blocker in 1 db resolution for band 5, reset value: 0x0, access type: RW
		uint32 pmBsOffThB6 : 8; //relative threshold for for blocker in 1 db resolution for band 6, reset value: 0x0, access type: RW
		uint32 pmBsOffThB7 : 8; //relative threshold for for blocker in 1 db resolution for band 7, reset value: 0x0, access type: RW
	} bitFields;
} RegB2PhyAgcAnt0PmBsOffThB5B7_u;

/*REG_B2_PHY_AGC_ANT0_PM_BS_OFF_TH_B8_B11 0x514 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 pmBsOffThB8 : 8; //relative threshold for for blocker in 1 db resolution for band 8, reset value: 0x0, access type: RW
		uint32 pmBsOffThB9 : 8; //relative threshold for for blocker in 1 db resolution for band 9, reset value: 0x0, access type: RW
		uint32 pmBsOffThB10 : 8; //relative threshold for for blocker in 1 db resolution for band 10, reset value: 0x0, access type: RW
		uint32 pmBsOffThB11 : 8; //relative threshold for for blocker in 1 db resolution for band 11, reset value: 0x0, access type: RW
	} bitFields;
} RegB2PhyAgcAnt0PmBsOffThB8B11_u;

/*REG_B2_PHY_AGC_ANT0_ACC_OFFSET_BS0_B4 0x518 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 accOffsetBs0 : 8; //offset to band select in 1/2 db resolution for band0, reset value: 0x0, access type: RO
		uint32 accOffsetBs1 : 8; //offset to band select in 1/2 db resolution for band1, reset value: 0x0, access type: RO
		uint32 accOffsetBs2 : 8; //offset to band select in 1/2 db resolution for band2, reset value: 0x0, access type: RO
		uint32 accOffsetBs3 : 8; //offset to band select in 1/2 db resolution for band3, reset value: 0x0, access type: RO
	} bitFields;
} RegB2PhyAgcAnt0AccOffsetBs0B4_u;

/*REG_B2_PHY_AGC_ANT0_ACC_OFFSET_BS4_B7 0x51C */
typedef union
{
	uint32 val;
	struct
	{
		uint32 accOffsetBs4 : 8; //offset to band select in 1/2 db resolution for band4, reset value: 0x0, access type: RO
		uint32 accOffsetBs5 : 8; //offset to band select in 1/2 db resolution for band5, reset value: 0x0, access type: RO
		uint32 accOffsetBs6 : 8; //offset to band select in 1/2 db resolution for band6, reset value: 0x0, access type: RO
		uint32 accOffsetBs7 : 8; //offset to band select in 1/2 db resolution for band7, reset value: 0x0, access type: RO
	} bitFields;
} RegB2PhyAgcAnt0AccOffsetBs4B7_u;

/*REG_B2_PHY_AGC_ANT0_ACC_OFFSET_BS8_B11 0x520 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 accOffsetBs8 : 8; //offset to band select in 1/2 db resolution for band8, reset value: 0x0, access type: RO
		uint32 accOffsetBs9 : 8; //offset to band select in 1/2 db resolution for band9, reset value: 0x0, access type: RO
		uint32 accOffsetBs10 : 8; //offset to band select in 1/2 db resolution for band10, reset value: 0x0, access type: RO
		uint32 accOffsetBs11 : 8; //offset to band select in 1/2 db resolution for band11, reset value: 0x0, access type: RO
	} bitFields;
} RegB2PhyAgcAnt0AccOffsetBs8B11_u;

/*REG_B2_PHY_AGC_ANT0_ACC_ABS_BLOCKER_MAP 0x524 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 accAbsBlockerMap : 32; //map of absolute threshold check, reset value: 0x0, access type: RO
	} bitFields;
} RegB2PhyAgcAnt0AccAbsBlockerMap_u;

/*REG_B2_PHY_AGC_ANT0_ACC_TH_BLOCKER_MAP 0x528 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 accThBlockerMap : 32; //map of relative threshold check, reset value: 0x0, access type: RO
	} bitFields;
} RegB2PhyAgcAnt0AccThBlockerMap_u;

/*REG_B2_PHY_AGC_ANT0_ACC_MAX_BLOCKER_LSB_POWER 0x52C */
typedef union
{
	uint32 val;
	struct
	{
		int32  accMaxBlockerLsbPower : 9; //max blocker power in lsb side in 1/2 db resolution, reset value: 0x0, access type: ROS
		uint32 reserved0 : 23;
	} bitFields;
} RegB2PhyAgcAnt0AccMaxBlockerLsbPower_u;

/*REG_B2_PHY_AGC_ANT0_ACC_MAX_BLOCKER_USB_POWER 0x530 */
typedef union
{
	uint32 val;
	struct
	{
		int32  accMaxBlockerUsbPower : 9; //max blocker power in usb side in 1/2 db resolution, reset value: 0x0, access type: ROS
		uint32 reserved0 : 23;
	} bitFields;
} RegB2PhyAgcAnt0AccMaxBlockerUsbPower_u;

/*REG_B2_PHY_AGC_ANT0_PM_LNA_INTERNAL_GAIN 0x534 */
typedef union
{
	uint32 val;
	struct
	{
		int32  pmLnaInternalGain : 9; //lna internal gain in 1/2 dB, reset value: 0x0, access type: RWS
		uint32 reserved0 : 23;
	} bitFields;
} RegB2PhyAgcAnt0PmLnaInternalGain_u;

/*REG_B2_PHY_AGC_ANT0_PM_PRI_ACI_POWER 0x538 */
typedef union
{
	uint32 val;
	struct
	{
		int32  pmPriAciPower : 9; //programmble primary aci power to gain acceleration in 1/2 dB, reset value: 0x0, access type: RWS
		uint32 reserved0 : 23;
	} bitFields;
} RegB2PhyAgcAnt0PmPriAciPower_u;

/*REG_B2_PHY_AGC_ANT0_ACC_PRI_ACI_POWER 0x53C */
typedef union
{
	uint32 val;
	struct
	{
		int32  accPriAciPower : 9; //primary aci power reading locked at "table go" in 1/2 dB, reset value: 0x0, access type: ROS
		uint32 reserved0 : 23;
	} bitFields;
} RegB2PhyAgcAnt0AccPriAciPower_u;

/*REG_B2_PHY_AGC_ANT0_ULTRA_WIDE_BAND 0x540 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 ultraWideBand : 1; //rf filter is open wide, reset value: 0x0, access type: RW
		uint32 reserved0 : 31;
	} bitFields;
} RegB2PhyAgcAnt0UltraWideBand_u;

/*REG_B2_PHY_AGC_ANT0_PM_PRESET_CALIBRATION 0x544 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 pmPresetCalibrationLnaIndex : 4; //lna index for calibration, reset value: 0x0, access type: RW
		uint32 pmPresetCalibrationSelS2DRx : 1; //sel_s2d_rx for calibration, reset value: 0x0, access type: RW
		uint32 pmPresetCalibrationPgc1Index : 3; //pgc1 index for calibration, reset value: 0x0, access type: RW
		uint32 pmPresetCalibrationRxFilter : 6; //rx_filter for calibration, reset value: 0x0, access type: RW
		uint32 reserved0 : 18;
	} bitFields;
} RegB2PhyAgcAnt0PmPresetCalibration_u;

/*REG_B2_PHY_AGC_ANT0_AGC_MEASURMENT_FOR_SPUR_CANCEL 0x548 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 lnaIndexForSpurCancel : 4; //lna_index, reset value: 0x0, access type: RO
		uint32 pgcIndexForSpurCancel : 3; //pgc_index_for_spur_cancel, reset value: 0x0, access type: RO
		uint32 bbDigitalGainForSpurCancel : 7; //bb_digital_gain_for_spur_cancel, reset value: 0x0, access type: RO
		uint32 reserved0 : 18;
	} bitFields;
} RegB2PhyAgcAnt0AgcMeasurmentForSpurCancel_u;

/*REG_B2_PHY_AGC_ANT0_PM_LIMIT_LNA_MAX_INDEX 0x54C */
typedef union
{
	uint32 val;
	struct
	{
		uint32 pmLimitLnaMaxIndex : 4; //pm_limit_lna_max_index, reset value: 0x0, access type: RW
		uint32 reserved0 : 28;
	} bitFields;
} RegB2PhyAgcAnt0PmLimitLnaMaxIndex_u;

//========================================
/* REG_PHY_AGC_ANT0_BB_RSSI_PARAMS_REG 0x0 */
#define B2_PHY_AGC_ANT0_BB_RSSI_PARAMS_REG_FIELD_BB_RSSI_BLK_SIZE_MASK                                            0x00000007
#define B2_PHY_AGC_ANT0_BB_RSSI_PARAMS_REG_FIELD_BB_RSSI_IIR_POLE_MASK                                            0x00000780
#define B2_PHY_AGC_ANT0_BB_RSSI_PARAMS_REG_FIELD_BB_RSSI_IIR_POLE_MIN_MASK                                        0x00003800
#define B2_PHY_AGC_ANT0_BB_RSSI_PARAMS_REG_FIELD_BB_RSSI_OFFSET1_MASK                                             0x3FFFC000
#define B2_PHY_AGC_ANT0_BB_RSSI_PARAMS_REG_FIELD_BB_RSSI_CANCEL_DC_MASK                                           0x40000000
//========================================
/* REG_PHY_AGC_ANT0_BB_RSSI_OFFSET2_REG 0x4 */
#define B2_PHY_AGC_ANT0_BB_RSSI_OFFSET2_REG_FIELD_BB_RSSI_OFFSET2_MASK                                            0x000001FF
//========================================
/* REG_PHY_AGC_ANT0_BB_RSSI_SYSTEM_GAIN_REG 0x8 */
#define B2_PHY_AGC_ANT0_BB_RSSI_SYSTEM_GAIN_REG_FIELD_BB_RSSI_SYSTEM_GAIN_MASK                                    0x000001FF
//========================================
/* REG_PHY_AGC_ANT0_BB_RSSI_SYSTEM_GAIN_SELECT_REG 0xC */
#define B2_PHY_AGC_ANT0_BB_RSSI_SYSTEM_GAIN_SELECT_REG_FIELD_BB_RSSI_SYSTEM_GAIN_HW_SELECT_MASK                   0x00000001
//========================================
/* REG_PHY_AGC_ANT0_BB_RSSI_SAT_THR 0x10 */
#define B2_PHY_AGC_ANT0_BB_RSSI_SAT_THR_FIELD_BB_RSSI_SAT_THR_MASK                                                0x000001FF
//========================================
/* REG_PHY_AGC_ANT0_INB_RSSI_PARAMS_REG 0x14 */
#define B2_PHY_AGC_ANT0_INB_RSSI_PARAMS_REG_FIELD_INBAND_RSSI_BLK_SIZE_MASK                                       0x00000007
#define B2_PHY_AGC_ANT0_INB_RSSI_PARAMS_REG_FIELD_INBAND_RSSI_IIR_POLE_MASK                                       0x00000780
#define B2_PHY_AGC_ANT0_INB_RSSI_PARAMS_REG_FIELD_INBAND_RSSI_IIR_POLE_MIN_MASK                                   0x00003800
#define B2_PHY_AGC_ANT0_INB_RSSI_PARAMS_REG_FIELD_INBAND_RSSI_OFFSET1_MASK                                        0x3FFFC000
#define B2_PHY_AGC_ANT0_INB_RSSI_PARAMS_REG_FIELD_INBAND_RSSI_CANCEL_DC_MASK                                      0x40000000
//========================================
/* REG_PHY_AGC_ANT0_INB_RSSI_OFFSET2_REG 0x18 */
#define B2_PHY_AGC_ANT0_INB_RSSI_OFFSET2_REG_FIELD_INBAND_RSSI_OFFSET2_MASK                                       0x000001FF
//========================================
/* REG_PHY_AGC_ANT0_INBAND_RSSI_SYSTEM_GAIN_REG 0x1C */
#define B2_PHY_AGC_ANT0_INBAND_RSSI_SYSTEM_GAIN_REG_FIELD_INBAND_RSSI_SYSTEM_GAIN_MASK                            0x000001FF
//========================================
/* REG_PHY_AGC_ANT0_INBAND_RSSI_SYSTEM_GAIN_SELECT_REG 0x20 */
#define B2_PHY_AGC_ANT0_INBAND_RSSI_SYSTEM_GAIN_SELECT_REG_FIELD_INBAND_RSSI_SYSTEM_GAIN_HW_SELECT_MASK           0x00000001
//========================================
/* REG_PHY_AGC_ANT0_INBAND_RSSI_SAT_THR 0x24 */
#define B2_PHY_AGC_ANT0_INBAND_RSSI_SAT_THR_FIELD_INBAND_RSSI_SAT_THR_MASK                                        0x000001FF
//========================================
/* REG_PHY_AGC_ANT0_FB_RSSI_PARAMS_REG 0x28 */
#define B2_PHY_AGC_ANT0_FB_RSSI_PARAMS_REG_FIELD_FB_RSSI_BLK_SIZE_MASK                                            0x00000007
#define B2_PHY_AGC_ANT0_FB_RSSI_PARAMS_REG_FIELD_FB_RSSI_IIR_POLE_MASK                                            0x00000780
#define B2_PHY_AGC_ANT0_FB_RSSI_PARAMS_REG_FIELD_FB_RSSI_IIR_POLE_MIN_MASK                                        0x00003800
#define B2_PHY_AGC_ANT0_FB_RSSI_PARAMS_REG_FIELD_FB_RSSI_OFFSET1_MASK                                             0x3FFFC000
#define B2_PHY_AGC_ANT0_FB_RSSI_PARAMS_REG_FIELD_FB_RSSI_CANCEL_DC_MASK                                           0x40000000
//========================================
/* REG_PHY_AGC_ANT0_FB_RSSI_OFFSET2_REG 0x2C */
#define B2_PHY_AGC_ANT0_FB_RSSI_OFFSET2_REG_FIELD_FB_RSSI_OFFSET2_MASK                                            0x000001FF
//========================================
/* REG_PHY_AGC_ANT0_FB_RSSI_SYSTEM_GAIN_REG 0x30 */
#define B2_PHY_AGC_ANT0_FB_RSSI_SYSTEM_GAIN_REG_FIELD_FB_RSSI_SYSTEM_GAIN_MASK                                    0x000001FF
//========================================
/* REG_PHY_AGC_ANT0_FB_RSSI_SYSTEM_GAIN_SELECT_REG 0x34 */
#define B2_PHY_AGC_ANT0_FB_RSSI_SYSTEM_GAIN_SELECT_REG_FIELD_FB_RSSI_SYSTEM_GAIN_HW_SELECT_MASK                   0x00000001
//========================================
/* REG_PHY_AGC_ANT0_FB_RSSI_SAT_THR 0x38 */
#define B2_PHY_AGC_ANT0_FB_RSSI_SAT_THR_FIELD_FB_RSSI_SAT_THR_MASK                                                0x000001FF
//========================================
/* REG_PHY_AGC_ANT0_HB_RSSI_PARAMS_REG 0x3C */
#define B2_PHY_AGC_ANT0_HB_RSSI_PARAMS_REG_FIELD_HB_RSSI_BLK_SIZE_MASK                                            0x00000007
#define B2_PHY_AGC_ANT0_HB_RSSI_PARAMS_REG_FIELD_HB_RSSI_IIR_POLE_MASK                                            0x00000780
#define B2_PHY_AGC_ANT0_HB_RSSI_PARAMS_REG_FIELD_HB_RSSI_IIR_POLE_MIN_MASK                                        0x00003800
#define B2_PHY_AGC_ANT0_HB_RSSI_PARAMS_REG_FIELD_HB_RSSI_OFFSET1_MASK                                             0x3FFFC000
#define B2_PHY_AGC_ANT0_HB_RSSI_PARAMS_REG_FIELD_HB_RSSI_CANCEL_DC_MASK                                           0x40000000
//========================================
/* REG_PHY_AGC_ANT0_HB_RSSI_OFFSET2_REG 0x40 */
#define B2_PHY_AGC_ANT0_HB_RSSI_OFFSET2_REG_FIELD_HB_RSSI_OFFSET2_MASK                                            0x000001FF
//========================================
/* REG_PHY_AGC_ANT0_HB_RSSI_SYSTEM_GAIN_REG 0x44 */
#define B2_PHY_AGC_ANT0_HB_RSSI_SYSTEM_GAIN_REG_FIELD_HB_RSSI_SYSTEM_GAIN_MASK                                    0x000001FF
//========================================
/* REG_PHY_AGC_ANT0_HB_RSSI_SYSTEM_GAIN_SELECT_REG 0x48 */
#define B2_PHY_AGC_ANT0_HB_RSSI_SYSTEM_GAIN_SELECT_REG_FIELD_HB_RSSI_SYSTEM_GAIN_HW_SELECT_MASK                   0x00000001
//========================================
/* REG_PHY_AGC_ANT0_HB_RSSI_SAT_THR 0x4C */
#define B2_PHY_AGC_ANT0_HB_RSSI_SAT_THR_FIELD_HB_RSSI_SAT_THR_MASK                                                0x000001FF
//========================================
/* REG_PHY_AGC_ANT0_RF_RSSI_PARAMS_REG 0x50 */
#define B2_PHY_AGC_ANT0_RF_RSSI_PARAMS_REG_FIELD_RF_RSSI_BLK_SIZE_RX_MODE_MASK                                    0x00000007
#define B2_PHY_AGC_ANT0_RF_RSSI_PARAMS_REG_FIELD_RF_RSSI_BLK_SIZE_TX_MODE_MASK                                    0x00000038
#define B2_PHY_AGC_ANT0_RF_RSSI_PARAMS_REG_FIELD_RF_RSSI_BLK_SIZE_USER_MODE_MASK                                  0x000001C0
#define B2_PHY_AGC_ANT0_RF_RSSI_PARAMS_REG_FIELD_RF_RSSI_IIR_POLE_MASK                                            0x00001E00
#define B2_PHY_AGC_ANT0_RF_RSSI_PARAMS_REG_FIELD_RF_RSSI_IIR_POLE_MIN_MASK                                        0x0000E000
//========================================
/* REG_PHY_AGC_ANT0_RF_RSSI_OFFSET1_RX_RANGE0 0x54 */
#define B2_PHY_AGC_ANT0_RF_RSSI_OFFSET1_RX_RANGE0_FIELD_RF_RSSI_OFFSET1_RX_RANGE0_MASK                            0x00003FFF
//========================================
/* REG_PHY_AGC_ANT0_RF_RSSI_OFFSET1_RX_RANGE1 0x58 */
#define B2_PHY_AGC_ANT0_RF_RSSI_OFFSET1_RX_RANGE1_FIELD_RF_RSSI_OFFSET1_RX_RANGE1_MASK                            0x00003FFF
//========================================
/* REG_PHY_AGC_ANT0_RF_RSSI_OFFSET1_TX 0x5C */
#define B2_PHY_AGC_ANT0_RF_RSSI_OFFSET1_TX_FIELD_RF_RSSI_OFFSET1_TX_MASK                                          0x00003FFF
//========================================
/* REG_PHY_AGC_ANT0_RF_RSSI_OFFSET2_RX_REG 0x60 */
#define B2_PHY_AGC_ANT0_RF_RSSI_OFFSET2_RX_REG_FIELD_RF_RSSI_OFFSET2_RX_MASK                                      0x000000FF
//========================================
/* REG_PHY_AGC_ANT0_RF_RSSI_OFFSET2_TX_REG 0x64 */
#define B2_PHY_AGC_ANT0_RF_RSSI_OFFSET2_TX_REG_FIELD_RF_RSSI_OFFSET2_TX_MASK                                      0x000000FF
//========================================
/* REG_PHY_AGC_ANT0_RF_RSSI_SYSTEM_GAIN_REG 0x68 */
#define B2_PHY_AGC_ANT0_RF_RSSI_SYSTEM_GAIN_REG_FIELD_RF_RSSI_SYSTEM_GAIN_MASK                                    0x000001FF
//========================================
/* REG_PHY_AGC_ANT0_RF_RSSI_SYSTEM_GAIN_SELECT_REG 0x6C */
#define B2_PHY_AGC_ANT0_RF_RSSI_SYSTEM_GAIN_SELECT_REG_FIELD_RF_RSSI_SYSTEM_GAIN_HW_SELECT_MASK                   0x00000001
//========================================
/* REG_PHY_AGC_ANT0_RF_RSSI_SAT_THR_RANGE0 0x70 */
#define B2_PHY_AGC_ANT0_RF_RSSI_SAT_THR_RANGE0_FIELD_RF_RSSI_SAT_THR_RANGE0_MASK                                  0x000001FF
//========================================
/* REG_PHY_AGC_ANT0_RF_RSSI_SAT_THR_RANGE1 0x74 */
#define B2_PHY_AGC_ANT0_RF_RSSI_SAT_THR_RANGE1_FIELD_RF_RSSI_SAT_THR_RANGE1_MASK                                  0x000001FF
//========================================
/* REG_PHY_AGC_ANT0_RF_RSSI_COEF_A_RANGE0_REG 0x78 */
#define B2_PHY_AGC_ANT0_RF_RSSI_COEF_A_RANGE0_REG_FIELD_RF_RSSI_COEF_A_RANGE0_MASK                                0x0000FFFF
//========================================
/* REG_PHY_AGC_ANT0_RF_RSSI_COEF_A_RANGE1_REG 0x7C */
#define B2_PHY_AGC_ANT0_RF_RSSI_COEF_A_RANGE1_REG_FIELD_RF_RSSI_COEF_A_RANGE1_MASK                                0x0000FFFF
//========================================
/* REG_PHY_AGC_ANT0_RF_RSSI_COEF_A2_RANGE0_REG 0x80 */
#define B2_PHY_AGC_ANT0_RF_RSSI_COEF_A2_RANGE0_REG_FIELD_RF_RSSI_COEF_A2_RANGE0_MASK                              0x0000FFFF
//========================================
/* REG_PHY_AGC_ANT0_RF_RSSI_COEF_A2_RANGE1_REG 0x84 */
#define B2_PHY_AGC_ANT0_RF_RSSI_COEF_A2_RANGE1_REG_FIELD_RF_RSSI_COEF_A2_RANGE1_MASK                              0x0000FFFF
//========================================
/* REG_PHY_AGC_ANT0_RF_RSSI_COEF_B_RANGE0_REG 0x88 */
#define B2_PHY_AGC_ANT0_RF_RSSI_COEF_B_RANGE0_REG_FIELD_RF_RSSI_COEF_B_RANGE0_MASK                                0x0000FFFF
//========================================
/* REG_PHY_AGC_ANT0_RF_RSSI_COEF_B_RANGE1_REG 0x8C */
#define B2_PHY_AGC_ANT0_RF_RSSI_COEF_B_RANGE1_REG_FIELD_RF_RSSI_COEF_B_RANGE1_MASK                                0x0000FFFF
//========================================
/* REG_PHY_AGC_ANT0_RF_RSSI_COEF_C_RANGE0_REG 0x90 */
#define B2_PHY_AGC_ANT0_RF_RSSI_COEF_C_RANGE0_REG_FIELD_RF_RSSI_COEF_C_RANGE0_MASK                                0x0000FFFF
//========================================
/* REG_PHY_AGC_ANT0_RF_RSSI_COEF_C_RANGE1_REG 0x94 */
#define B2_PHY_AGC_ANT0_RF_RSSI_COEF_C_RANGE1_REG_FIELD_RF_RSSI_COEF_C_RANGE1_MASK                                0x0000FFFF
//========================================
/* REG_PHY_AGC_ANT0_RF_RSSI_COEF_NLOG_RANGE0_REG 0x98 */
#define B2_PHY_AGC_ANT0_RF_RSSI_COEF_NLOG_RANGE0_REG_FIELD_RF_RSSI_COEF_NLOG_RANGE0_MASK                          0x0000FFFF
//========================================
/* REG_PHY_AGC_ANT0_RF_RSSI_COEF_NLOG_RANGE1_REG 0x9C */
#define B2_PHY_AGC_ANT0_RF_RSSI_COEF_NLOG_RANGE1_REG_FIELD_RF_RSSI_COEF_NLOG_RANGE1_MASK                          0x0000FFFF
//========================================
/* REG_PHY_AGC_ANT0_RF_TSSI_COEF_A_REG 0xA0 */
#define B2_PHY_AGC_ANT0_RF_TSSI_COEF_A_REG_FIELD_RF_TSSI_COEF_A_MASK                                              0x0000FFFF
//========================================
/* REG_PHY_AGC_ANT0_RF_TSSI_COEF_A2_REG 0xA4 */
#define B2_PHY_AGC_ANT0_RF_TSSI_COEF_A2_REG_FIELD_RF_TSSI_COEF_A2_MASK                                            0x0000FFFF
//========================================
/* REG_PHY_AGC_ANT0_RF_TSSI_COEF_B_REG 0xA8 */
#define B2_PHY_AGC_ANT0_RF_TSSI_COEF_B_REG_FIELD_RF_TSSI_COEF_B_MASK                                              0x0000FFFF
//========================================
/* REG_PHY_AGC_ANT0_RF_TSSI_COEF_C_REG 0xAC */
#define B2_PHY_AGC_ANT0_RF_TSSI_COEF_C_REG_FIELD_RF_TSSI_COEF_C_MASK                                              0x0000FFFF
//========================================
/* REG_PHY_AGC_ANT0_RF_TSSI_COEF_NLOG_REG 0xB0 */
#define B2_PHY_AGC_ANT0_RF_TSSI_COEF_NLOG_REG_FIELD_RF_TSSI_COEF_NLOG_MASK                                        0x0000FFFF
//========================================
/* REG_PHY_AGC_ANT0_RF_RSSI_TX_RX_REG 0xB4 */
#define B2_PHY_AGC_ANT0_RF_RSSI_TX_RX_REG_FIELD_RF_RSSI_TX_MODE_MASK                                              0x00000001
#define B2_PHY_AGC_ANT0_RF_RSSI_TX_RX_REG_FIELD_RF_RSSI_RX_RANGE_MASK                                             0x00000002
#define B2_PHY_AGC_ANT0_RF_RSSI_TX_RX_REG_FIELD_RF_RSSI_MODE_OVERRIDE_MASK                                        0x00000004
#define B2_PHY_AGC_ANT0_RF_RSSI_TX_RX_REG_FIELD_RF_RSSI_RANGE_OVERRIDE_MASK                                       0x00000010
#define B2_PHY_AGC_ANT0_RF_RSSI_TX_RX_REG_FIELD_RF_TSSI_COEF_OVERRIDE_MASK                                        0x00000020
#define B2_PHY_AGC_ANT0_RF_RSSI_TX_RX_REG_FIELD_RF_RSSI_BLK_SIZE_OVERRIDE_MASK                                    0x00000040
#define B2_PHY_AGC_ANT0_RF_RSSI_TX_RX_REG_FIELD_RF_TSSI_COEF_MODE_MASK                                            0x00000180
//========================================
/* REG_PHY_AGC_ANT0_BB_RSSI_REG 0xB8 */
#define B2_PHY_AGC_ANT0_BB_RSSI_REG_FIELD_BB_RSSI_MASK                                                            0x000001FF
//========================================
/* REG_PHY_AGC_ANT0_BB_POWER_REG 0xBC */
#define B2_PHY_AGC_ANT0_BB_POWER_REG_FIELD_BB_POWER_MASK                                                          0x000001FF
//========================================
/* REG_PHY_AGC_ANT0_BB_SRSSI_REG 0xC0 */
#define B2_PHY_AGC_ANT0_BB_SRSSI_REG_FIELD_BB_SRSSI_MASK                                                          0x000001FF
//========================================
/* REG_PHY_AGC_ANT0_BB_SPOWER_REG 0xC4 */
#define B2_PHY_AGC_ANT0_BB_SPOWER_REG_FIELD_BB_SPOWER_MASK                                                        0x000001FF
//========================================
/* REG_PHY_AGC_ANT0_BB_PWR_DIFF_REG 0xC8 */
#define B2_PHY_AGC_ANT0_BB_PWR_DIFF_REG_FIELD_BB_B1_MASK                                                          0x000001FF
#define B2_PHY_AGC_ANT0_BB_PWR_DIFF_REG_FIELD_BB_B2_MASK                                                          0x0003FE00
//========================================
/* REG_PHY_AGC_ANT0_IB_RSSI_REG 0xCC */
#define B2_PHY_AGC_ANT0_IB_RSSI_REG_FIELD_IB_RSSI_MASK                                                            0x000001FF
//========================================
/* REG_PHY_AGC_ANT0_IB_POWER_REG 0xD0 */
#define B2_PHY_AGC_ANT0_IB_POWER_REG_FIELD_IB_POWER_MASK                                                          0x000001FF
//========================================
/* REG_PHY_AGC_ANT0_IB_SRSSI_REG 0xD4 */
#define B2_PHY_AGC_ANT0_IB_SRSSI_REG_FIELD_IB_SRSSI_MASK                                                          0x000001FF
//========================================
/* REG_PHY_AGC_ANT0_IB_SPOWER_REG 0xD8 */
#define B2_PHY_AGC_ANT0_IB_SPOWER_REG_FIELD_IB_SPOWER_MASK                                                        0x000001FF
//========================================
/* REG_PHY_AGC_ANT0_IB_PWR_DIFF_REG 0xDC */
#define B2_PHY_AGC_ANT0_IB_PWR_DIFF_REG_FIELD_IB_B1_MASK                                                          0x000001FF
#define B2_PHY_AGC_ANT0_IB_PWR_DIFF_REG_FIELD_IB_B2_MASK                                                          0x0003FE00
//========================================
/* REG_PHY_AGC_ANT0_FB_RSSI_REG 0xE0 */
#define B2_PHY_AGC_ANT0_FB_RSSI_REG_FIELD_FB_RSSI_MASK                                                            0x000001FF
//========================================
/* REG_PHY_AGC_ANT0_FB_POWER_REG 0xE4 */
#define B2_PHY_AGC_ANT0_FB_POWER_REG_FIELD_FB_POWER_MASK                                                          0x000001FF
//========================================
/* REG_PHY_AGC_ANT0_FB_SRSSI_REG 0xE8 */
#define B2_PHY_AGC_ANT0_FB_SRSSI_REG_FIELD_FB_SRSSI_MASK                                                          0x000001FF
//========================================
/* REG_PHY_AGC_ANT0_FB_SPOWER_REG 0xEC */
#define B2_PHY_AGC_ANT0_FB_SPOWER_REG_FIELD_FB_SPOWER_MASK                                                        0x000001FF
//========================================
/* REG_PHY_AGC_ANT0_FB_PWR_DIFF_REG 0xF0 */
#define B2_PHY_AGC_ANT0_FB_PWR_DIFF_REG_FIELD_FB_B1_MASK                                                          0x000001FF
#define B2_PHY_AGC_ANT0_FB_PWR_DIFF_REG_FIELD_FB_B2_MASK                                                          0x0003FE00
//========================================
/* REG_PHY_AGC_ANT0_HB_RSSI_REG 0xF4 */
#define B2_PHY_AGC_ANT0_HB_RSSI_REG_FIELD_HB_RSSI_MASK                                                            0x000001FF
//========================================
/* REG_PHY_AGC_ANT0_HB_POWER_REG 0xF8 */
#define B2_PHY_AGC_ANT0_HB_POWER_REG_FIELD_HB_POWER_MASK                                                          0x000001FF
//========================================
/* REG_PHY_AGC_ANT0_HB_SRSSI_REG 0xFC */
#define B2_PHY_AGC_ANT0_HB_SRSSI_REG_FIELD_HB_SRSSI_MASK                                                          0x000001FF
//========================================
/* REG_PHY_AGC_ANT0_HB_SPOWER_REG 0x100 */
#define B2_PHY_AGC_ANT0_HB_SPOWER_REG_FIELD_HB_SPOWER_MASK                                                        0x000001FF
//========================================
/* REG_PHY_AGC_ANT0_HB_PWR_DIFF_REG 0x104 */
#define B2_PHY_AGC_ANT0_HB_PWR_DIFF_REG_FIELD_HB_B1_MASK                                                          0x000001FF
#define B2_PHY_AGC_ANT0_HB_PWR_DIFF_REG_FIELD_HB_B2_MASK                                                          0x0003FE00
//========================================
/* REG_PHY_AGC_ANT0_RF_RSSI_REG 0x108 */
#define B2_PHY_AGC_ANT0_RF_RSSI_REG_FIELD_RF_RSSI_MASK                                                            0x000001FF
//========================================
/* REG_PHY_AGC_ANT0_RF_POWER_REG 0x10C */
#define B2_PHY_AGC_ANT0_RF_POWER_REG_FIELD_RF_POWER_MASK                                                          0x000001FF
//========================================
/* REG_PHY_AGC_ANT0_RF_SRSSI_REG 0x110 */
#define B2_PHY_AGC_ANT0_RF_SRSSI_REG_FIELD_RF_SRSSI_MASK                                                          0x000001FF
//========================================
/* REG_PHY_AGC_ANT0_RF_SPOWER_REG 0x114 */
#define B2_PHY_AGC_ANT0_RF_SPOWER_REG_FIELD_RF_SPOWER_MASK                                                        0x000001FF
//========================================
/* REG_PHY_AGC_ANT0_SATURATION_RESULT 0x118 */
#define B2_PHY_AGC_ANT0_SATURATION_RESULT_FIELD_RF_RSSI_SAT_FLAG_MASK                                             0x00000001
#define B2_PHY_AGC_ANT0_SATURATION_RESULT_FIELD_FB_RSSI_SAT_FLAG_MASK                                             0x00000002
#define B2_PHY_AGC_ANT0_SATURATION_RESULT_FIELD_BB_RSSI_SAT_FLAG_MASK                                             0x00000004
#define B2_PHY_AGC_ANT0_SATURATION_RESULT_FIELD_HB_RSSI_SAT_FLAG_MASK                                             0x00000008
#define B2_PHY_AGC_ANT0_SATURATION_RESULT_FIELD_IB_RSSI_SAT_FLAG_MASK                                             0x00000010
#define B2_PHY_AGC_ANT0_SATURATION_RESULT_FIELD_ACI_RSSI_SAT_FLAG_MASK                                            0x00000020
#define B2_PHY_AGC_ANT0_SATURATION_RESULT_FIELD_UP_HB_RSSI_SAT_FLAG_MASK                                          0x00000040
#define B2_PHY_AGC_ANT0_SATURATION_RESULT_FIELD_UP_IB_RSSI_SAT_FLAG_MASK                                          0x00000080
#define B2_PHY_AGC_ANT0_SATURATION_RESULT_FIELD_UP_ACI_RSSI_SAT_FLAG_MASK                                         0x00000100
//========================================
/* REG_PHY_AGC_ANT0_RSSI_BLOCKS_GCLK_EN 0x11C */
#define B2_PHY_AGC_ANT0_RSSI_BLOCKS_GCLK_EN_FIELD_RF_RSSI_GCLK_EN_MASK                                            0x00000001
#define B2_PHY_AGC_ANT0_RSSI_BLOCKS_GCLK_EN_FIELD_FB_RSSI_GCLK_EN_MASK                                            0x00000002
#define B2_PHY_AGC_ANT0_RSSI_BLOCKS_GCLK_EN_FIELD_BB_RSSI_GCLK_EN_MASK                                            0x00000004
#define B2_PHY_AGC_ANT0_RSSI_BLOCKS_GCLK_EN_FIELD_HB_RSSI_GCLK_EN_MASK                                            0x00000008
#define B2_PHY_AGC_ANT0_RSSI_BLOCKS_GCLK_EN_FIELD_IB_RSSI_GCLK_EN_MASK                                            0x00000010
#define B2_PHY_AGC_ANT0_RSSI_BLOCKS_GCLK_EN_FIELD_UP_HB_RSSI_GCLK_EN_MASK                                         0x00000020
#define B2_PHY_AGC_ANT0_RSSI_BLOCKS_GCLK_EN_FIELD_UP_IB_RSSI_GCLK_EN_MASK                                         0x00000040
//========================================
/* REG_PHY_AGC_ANT0_RF_RSSI_DEC_OUT_STS 0x120 */
#define B2_PHY_AGC_ANT0_RF_RSSI_DEC_OUT_STS_FIELD_RF_RSSI_DEC_OUT_STS_MASK                                        0x00003FFF
//========================================
/* REG_PHY_AGC_ANT0_RF_RSSI_HIGH_RES_REG 0x124 */
#define B2_PHY_AGC_ANT0_RF_RSSI_HIGH_RES_REG_FIELD_RF_RSSI_HIGH_RES_MASK                                          0x000003FF
//========================================
/* REG_PHY_AGC_ANT0_PM_RF_POWER 0x140 */
#define B2_PHY_AGC_ANT0_PM_RF_POWER_FIELD_PM_RF_POWER_MASK                                                        0x000001FF
//========================================
/* REG_PHY_AGC_ANT0_PM_FB_POWER 0x144 */
#define B2_PHY_AGC_ANT0_PM_FB_POWER_FIELD_PM_FB_POWER_MASK                                                        0x000001FF
//========================================
/* REG_PHY_AGC_ANT0_PM_BB_POWER 0x148 */
#define B2_PHY_AGC_ANT0_PM_BB_POWER_FIELD_PM_BB_POWER_MASK                                                        0x000001FF
//========================================
/* REG_PHY_AGC_ANT0_PM_HB_POWER 0x14C */
#define B2_PHY_AGC_ANT0_PM_HB_POWER_FIELD_PM_HB_POWER_MASK                                                        0x000001FF
//========================================
/* REG_PHY_AGC_ANT0_PM_IB_POWER 0x150 */
#define B2_PHY_AGC_ANT0_PM_IB_POWER_FIELD_PM_IB_POWER_MASK                                                        0x000001FF
//========================================
/* REG_PHY_AGC_ANT0_PM_ACI_POWER 0x154 */
#define B2_PHY_AGC_ANT0_PM_ACI_POWER_FIELD_PM_ACI_POWER_MASK                                                      0x000001FF
//========================================
/* REG_PHY_AGC_ANT0_PM_RF_OFFSET 0x158 */
#define B2_PHY_AGC_ANT0_PM_RF_OFFSET_FIELD_PM_RF_OFFSET_MASK                                                      0x000001FF
//========================================
/* REG_PHY_AGC_ANT0_PM_FB_OFFSET 0x15C */
#define B2_PHY_AGC_ANT0_PM_FB_OFFSET_FIELD_PM_FB_OFFSET_MASK                                                      0x000001FF
//========================================
/* REG_PHY_AGC_ANT0_PM_BB_OFFSET 0x160 */
#define B2_PHY_AGC_ANT0_PM_BB_OFFSET_FIELD_PM_BB_OFFSET_MASK                                                      0x000001FF
//========================================
/* REG_PHY_AGC_ANT0_PM_HB_OFFSET 0x164 */
#define B2_PHY_AGC_ANT0_PM_HB_OFFSET_FIELD_PM_HB_OFFSET_MASK                                                      0x000001FF
//========================================
/* REG_PHY_AGC_ANT0_PM_IB_OFFSET 0x168 */
#define B2_PHY_AGC_ANT0_PM_IB_OFFSET_FIELD_PM_IB_OFFSET_MASK                                                      0x000001FF
//========================================
/* REG_PHY_AGC_ANT0_PM_ACI_OFFSET 0x16C */
#define B2_PHY_AGC_ANT0_PM_ACI_OFFSET_FIELD_PM_ACI_OFFSET_MASK                                                    0x000001FF
//========================================
/* REG_PHY_AGC_ANT0_PM_SATURATION_REG 0x170 */
#define B2_PHY_AGC_ANT0_PM_SATURATION_REG_FIELD_PM_RF_RSSI_SAT_FLAG_MASK                                          0x00000001
#define B2_PHY_AGC_ANT0_PM_SATURATION_REG_FIELD_PM_FB_RSSI_SAT_FLAG_MASK                                          0x00000002
#define B2_PHY_AGC_ANT0_PM_SATURATION_REG_FIELD_PM_BB_RSSI_SAT_FLAG_MASK                                          0x00000004
#define B2_PHY_AGC_ANT0_PM_SATURATION_REG_FIELD_PM_HB_RSSI_SAT_FLAG_MASK                                          0x00000008
#define B2_PHY_AGC_ANT0_PM_SATURATION_REG_FIELD_PM_IB_RSSI_SAT_FLAG_MASK                                          0x00000010
#define B2_PHY_AGC_ANT0_PM_SATURATION_REG_FIELD_PM_ACI_RSSI_SAT_FLAG_MASK                                         0x00000020
#define B2_PHY_AGC_ANT0_PM_SATURATION_REG_FIELD_PM_UP_HB_RSSI_SAT_FLAG_MASK                                       0x00000040
#define B2_PHY_AGC_ANT0_PM_SATURATION_REG_FIELD_PM_UP_IB_RSSI_SAT_FLAG_MASK                                       0x00000080
#define B2_PHY_AGC_ANT0_PM_SATURATION_REG_FIELD_PM_UP_ACI_RSSI_SAT_FLAG_MASK                                      0x00000100
//========================================
/* REG_PHY_AGC_ANT0_PM_ACC_GAIN_DELAY 0x174 */
#define B2_PHY_AGC_ANT0_PM_ACC_GAIN_DELAY_FIELD_PM_ACC_GAIN_DELAY_MASK                                            0x0000FFFF
//========================================
/* REG_PHY_AGC_ANT0_PM_ACC_GAIN_SOURCES 0x178 */
#define B2_PHY_AGC_ANT0_PM_ACC_GAIN_SOURCES_FIELD_PM_ACC_GAIN_RF_SOURCE_MASK                                      0x00000001
#define B2_PHY_AGC_ANT0_PM_ACC_GAIN_SOURCES_FIELD_PM_ACC_GAIN_FB_SOURCE_MASK                                      0x00000002
#define B2_PHY_AGC_ANT0_PM_ACC_GAIN_SOURCES_FIELD_PM_ACC_GAIN_BB_SOURCE_MASK                                      0x00000004
#define B2_PHY_AGC_ANT0_PM_ACC_GAIN_SOURCES_FIELD_PM_ACC_GAIN_HB_SOURCE_MASK                                      0x00000008
#define B2_PHY_AGC_ANT0_PM_ACC_GAIN_SOURCES_FIELD_PM_ACC_GAIN_IB_SOURCE_MASK                                      0x00000010
#define B2_PHY_AGC_ANT0_PM_ACC_GAIN_SOURCES_FIELD_PM_ACC_GAIN_ACI_SOURCE_MASK                                     0x00000020
#define B2_PHY_AGC_ANT0_PM_ACC_GAIN_SOURCES_FIELD_PM_ACC_GAIN_UP_HB_SOURCE_MASK                                   0x00000040
#define B2_PHY_AGC_ANT0_PM_ACC_GAIN_SOURCES_FIELD_PM_ACC_GAIN_UP_IB_SOURCE_MASK                                   0x00000080
#define B2_PHY_AGC_ANT0_PM_ACC_GAIN_SOURCES_FIELD_PM_ACC_GAIN_UP_ACI_SOURCE_MASK                                  0x00000100
#define B2_PHY_AGC_ANT0_PM_ACC_GAIN_SOURCES_FIELD_PM_ACC_GAIN_RF_SAT_SOURCE_MASK                                  0x00000200
#define B2_PHY_AGC_ANT0_PM_ACC_GAIN_SOURCES_FIELD_PM_ACC_GAIN_FB_SAT_SOURCE_MASK                                  0x00000400
#define B2_PHY_AGC_ANT0_PM_ACC_GAIN_SOURCES_FIELD_PM_ACC_GAIN_BB_SAT_SOURCE_MASK                                  0x00000800
#define B2_PHY_AGC_ANT0_PM_ACC_GAIN_SOURCES_FIELD_PM_ACC_GAIN_HB_SAT_SOURCE_MASK                                  0x00001000
#define B2_PHY_AGC_ANT0_PM_ACC_GAIN_SOURCES_FIELD_PM_ACC_GAIN_IB_SAT_SOURCE_MASK                                  0x00002000
#define B2_PHY_AGC_ANT0_PM_ACC_GAIN_SOURCES_FIELD_PM_ACC_GAIN_ACI_SAT_SOURCE_MASK                                 0x00004000
#define B2_PHY_AGC_ANT0_PM_ACC_GAIN_SOURCES_FIELD_PM_ACC_GAIN_UP_HB_SAT_SOURCE_MASK                               0x00008000
#define B2_PHY_AGC_ANT0_PM_ACC_GAIN_SOURCES_FIELD_PM_ACC_GAIN_UP_IB_SAT_SOURCE_MASK                               0x00010000
#define B2_PHY_AGC_ANT0_PM_ACC_GAIN_SOURCES_FIELD_PM_ACC_GAIN_UP_ACI_SAT_SOURCE_MASK                              0x00020000
#define B2_PHY_AGC_ANT0_PM_ACC_GAIN_SOURCES_FIELD_PM_ACC_GAIN_PRI_ACI_SOURCE_MASK                                 0x00040000
#define B2_PHY_AGC_ANT0_PM_ACC_GAIN_SOURCES_FIELD_PM_ACC_GAIN_SIGNAL_SOURCE_MASK                                  0x00300000
#define B2_PHY_AGC_ANT0_PM_ACC_GAIN_SOURCES_FIELD_PM_ACC_GAIN_ENV_SOURCE_MASK                                     0x00C00000
#define B2_PHY_AGC_ANT0_PM_ACC_GAIN_SOURCES_FIELD_PM_ACC_GAIN_PGC1_SOURCE_MASK                                    0x03000000
#define B2_PHY_AGC_ANT0_PM_ACC_GAIN_SOURCES_FIELD_PM_ACC_GAIN_IB_GAIN_SOURCE_MASK                                 0x04000000
#define B2_PHY_AGC_ANT0_PM_ACC_GAIN_SOURCES_FIELD_PM_ACC_GAIN_BLOCKER_TYPE_SOURCE_MASK                            0x08000000
//========================================
/* REG_PHY_AGC_ANT0_PM_ACC_GAIN_MAX_POWER_LEVEL 0x17C */
#define B2_PHY_AGC_ANT0_PM_ACC_GAIN_MAX_POWER_LEVEL_FIELD_PM_ACC_GAIN_MAX_POWER_LEVEL_MASK                        0x000001FF
//========================================
/* REG_PHY_AGC_ANT0_PM_ACC_GAIN_MIN_POWER_LEVEL 0x180 */
#define B2_PHY_AGC_ANT0_PM_ACC_GAIN_MIN_POWER_LEVEL_FIELD_PM_ACC_GAIN_MIN_POWER_LEVEL_MASK                        0x000001FF
//========================================
/* REG_PHY_AGC_ANT0_PM_ACC_GAIN_SIGNAL_MAX_LEVEL 0x184 */
#define B2_PHY_AGC_ANT0_PM_ACC_GAIN_SIGNAL_MAX_LEVEL_FIELD_PM_ACC_GAIN_SIGNAL_MAX_LEVEL_MASK                      0x000001FF
//========================================
/* REG_PHY_AGC_ANT0_PM_ACC_GAIN_ENV_MIN_LEVEL 0x188 */
#define B2_PHY_AGC_ANT0_PM_ACC_GAIN_ENV_MIN_LEVEL_FIELD_PM_ACC_GAIN_ENV_MIN_LEVEL_MASK                            0x000001FF
//========================================
/* REG_PHY_AGC_ANT0_PM_ACC_GAIN_SIGNAL_ENV_DIFF_VALUES 0x18C */
#define B2_PHY_AGC_ANT0_PM_ACC_GAIN_SIGNAL_ENV_DIFF_VALUES_FIELD_PM_ACC_GAIN_SIGNAL_ENV_MAX_DIFF_MASK             0x000001FF
#define B2_PHY_AGC_ANT0_PM_ACC_GAIN_SIGNAL_ENV_DIFF_VALUES_FIELD_PM_ACC_GAIN_SIGNAL_ENV_MIN_DIFF_MASK             0x01FF0000
//========================================
/* REG_PHY_AGC_ANT0_PM_ACC_GAIN_GSP_TABLE_CONTROL 0x190 */
#define B2_PHY_AGC_ANT0_PM_ACC_GAIN_GSP_TABLE_CONTROL_FIELD_PM_ACC_GAIN_GSP_TABLE_SHIFT_MASK                      0x00070000
#define B2_PHY_AGC_ANT0_PM_ACC_GAIN_GSP_TABLE_CONTROL_FIELD_PM_ACC_GAIN_GSP_TABLE_MODE_MASK                       0x01000000
//========================================
/* REG_PHY_AGC_ANT0_PM_ACC_GAIN_LNA_CONTROL 0x194 */
#define B2_PHY_AGC_ANT0_PM_ACC_GAIN_LNA_CONTROL_FIELD_PM_ACC_GAIN_LNA_INDEX_MODE_MASK                             0x00000001
//========================================
/* REG_PHY_AGC_ANT0_PM_SEL_S2D_RX_LUT 0x1B4 */
#define B2_PHY_AGC_ANT0_PM_SEL_S2D_RX_LUT_FIELD_PM_SEL_S2D_RX_LUT_0_MASK                                          0x00000001
#define B2_PHY_AGC_ANT0_PM_SEL_S2D_RX_LUT_FIELD_PM_SEL_S2D_RX_LUT_1_MASK                                          0x00000002
#define B2_PHY_AGC_ANT0_PM_SEL_S2D_RX_LUT_FIELD_PM_SEL_S2D_RX_LUT_2_MASK                                          0x00000004
#define B2_PHY_AGC_ANT0_PM_SEL_S2D_RX_LUT_FIELD_PM_SEL_S2D_RX_LUT_3_MASK                                          0x00000008
#define B2_PHY_AGC_ANT0_PM_SEL_S2D_RX_LUT_FIELD_PM_SEL_S2D_RX_LUT_4_MASK                                          0x00000010
#define B2_PHY_AGC_ANT0_PM_SEL_S2D_RX_LUT_FIELD_PM_SEL_S2D_RX_LUT_5_MASK                                          0x00000020
#define B2_PHY_AGC_ANT0_PM_SEL_S2D_RX_LUT_FIELD_PM_SEL_S2D_RX_LUT_6_MASK                                          0x00000040
#define B2_PHY_AGC_ANT0_PM_SEL_S2D_RX_LUT_FIELD_PM_SEL_S2D_RX_LUT_7_MASK                                          0x00000080
#define B2_PHY_AGC_ANT0_PM_SEL_S2D_RX_LUT_FIELD_PM_SEL_S2D_RX_LUT_8_MASK                                          0x00000100
#define B2_PHY_AGC_ANT0_PM_SEL_S2D_RX_LUT_FIELD_PM_SEL_S2D_RX_LUT_9_MASK                                          0x00000200
#define B2_PHY_AGC_ANT0_PM_SEL_S2D_RX_LUT_FIELD_PM_SEL_S2D_RX_LUT_10_MASK                                         0x00000400
#define B2_PHY_AGC_ANT0_PM_SEL_S2D_RX_LUT_FIELD_PM_SEL_S2D_RX_LUT_11_MASK                                         0x00000800
#define B2_PHY_AGC_ANT0_PM_SEL_S2D_RX_LUT_FIELD_PM_SEL_S2D_RX_LUT_12_MASK                                         0x00001000
#define B2_PHY_AGC_ANT0_PM_SEL_S2D_RX_LUT_FIELD_PM_SEL_S2D_RX_LUT_13_MASK                                         0x00002000
//========================================
/* REG_PHY_AGC_ANT0_PM_PGC1_GAIN_OFFSET 0x1B8 */
#define B2_PHY_AGC_ANT0_PM_PGC1_GAIN_OFFSET_FIELD_PM_PGC1_GAIN_OFFSET_MASK                                        0x000001FF
//========================================
/* REG_PHY_AGC_ANT0_PM_PGC1_GAIN_LIMITS 0x1BC */
#define B2_PHY_AGC_ANT0_PM_PGC1_GAIN_LIMITS_FIELD_PM_PGC1_GAIN_PLUS_OFFSET_MAX_LIMIT_MASK                         0x000001FF
#define B2_PHY_AGC_ANT0_PM_PGC1_GAIN_LIMITS_FIELD_PM_PGC1_GAIN_PLUS_OFFSET_MIN_LIMIT_MASK                         0x01FF0000
//========================================
/* REG_PHY_AGC_ANT0_PM_PGC1_GAIN_SHIFT 0x1C0 */
#define B2_PHY_AGC_ANT0_PM_PGC1_GAIN_SHIFT_FIELD_PM_PGC1_GAIN_SHIFT_MASK                                          0x00000007
//========================================
/* REG_PHY_AGC_ANT0_PM_RX_FILTER_CONTROL 0x1C4 */
#define B2_PHY_AGC_ANT0_PM_RX_FILTER_CONTROL_FIELD_PM_RX_FILTER_BW_INTERFERENCE_MODE_MASK                         0x00000004
//========================================
/* REG_PHY_AGC_ANT0_PM_RF_SYSTEM_GAIN_OFFSET 0x1C8 */
#define B2_PHY_AGC_ANT0_PM_RF_SYSTEM_GAIN_OFFSET_FIELD_PM_RF_SYSTEM_GAIN_OFFSET_MASK                              0x000001FF
//========================================
/* REG_PHY_AGC_ANT0_PM_FB_SYSTEM_GAIN_OFFSET 0x1CC */
#define B2_PHY_AGC_ANT0_PM_FB_SYSTEM_GAIN_OFFSET_FIELD_PM_FB_SYSTEM_GAIN_OFFSET_MASK                              0x000001FF
//========================================
/* REG_PHY_AGC_ANT0_PM_BB_SYSTEM_GAIN_OFFSET 0x1D0 */
#define B2_PHY_AGC_ANT0_PM_BB_SYSTEM_GAIN_OFFSET_FIELD_PM_BB_SYSTEM_GAIN_OFFSET_MASK                              0x000001FF
//========================================
/* REG_PHY_AGC_ANT0_PM_POST_BB_SYSTEM_GAIN_OFFSET 0x1D4 */
#define B2_PHY_AGC_ANT0_PM_POST_BB_SYSTEM_GAIN_OFFSET_FIELD_PM_POST_BB_SYSTEM_GAIN_OFFSET_MASK                    0x000001FF
//========================================
/* REG_PHY_AGC_ANT0_PM_HB_SYSTEM_GAIN_OFFSET 0x1D8 */
#define B2_PHY_AGC_ANT0_PM_HB_SYSTEM_GAIN_OFFSET_FIELD_PM_HB_SYSTEM_GAIN_OFFSET_MASK                              0x000001FF
//========================================
/* REG_PHY_AGC_ANT0_PM_IB_SYSTEM_GAIN_OFFSET 0x1DC */
#define B2_PHY_AGC_ANT0_PM_IB_SYSTEM_GAIN_OFFSET_FIELD_PM_IB_SYSTEM_GAIN_OFFSET_MASK                              0x000001FF
//========================================
/* REG_PHY_AGC_ANT0_PM_ACI_SYSTEM_GAIN_OFFSET 0x1E0 */
#define B2_PHY_AGC_ANT0_PM_ACI_SYSTEM_GAIN_OFFSET_FIELD_PM_ACI_SYSTEM_GAIN_OFFSET_MASK                            0x000001FF
//========================================
/* REG_PHY_AGC_ANT0_PM_CCA_SYSTEM_GAIN_OFFSET 0x1E4 */
#define B2_PHY_AGC_ANT0_PM_CCA_SYSTEM_GAIN_OFFSET_FIELD_PM_CCA_SYSTEM_GAIN_OFFSET_MASK                            0x000001FF
//========================================
/* REG_PHY_AGC_ANT0_PM_DET_SYSTEM_GAIN_OFFSET 0x1E8 */
#define B2_PHY_AGC_ANT0_PM_DET_SYSTEM_GAIN_OFFSET_FIELD_PM_DET_SYSTEM_GAIN_OFFSET_MASK                            0x000001FF
//========================================
/* REG_PHY_AGC_ANT0_PM_BB_BOF_OFFSET 0x1EC */
#define B2_PHY_AGC_ANT0_PM_BB_BOF_OFFSET_FIELD_PM_BB_BOF_OFFSET_MASK                                              0x000001FF
//========================================
/* REG_PHY_AGC_ANT0_PM_HB_BOF_OFFSET 0x1F0 */
#define B2_PHY_AGC_ANT0_PM_HB_BOF_OFFSET_FIELD_PM_HB_BOF_OFFSET_MASK                                              0x000001FF
//========================================
/* REG_PHY_AGC_ANT0_PM_IB_RSSI_BOF_OFFSET 0x1F4 */
#define B2_PHY_AGC_ANT0_PM_IB_RSSI_BOF_OFFSET_FIELD_PM_IB_RSSI_BOF_OFFSET_MASK                                    0x000001FF
//========================================
/* REG_PHY_AGC_ANT0_PM_IB_ACI_BOF_OFFSET 0x1F8 */
#define B2_PHY_AGC_ANT0_PM_IB_ACI_BOF_OFFSET_FIELD_PM_IB_ACI_BOF_OFFSET_MASK                                      0x000001FF
//========================================
/* REG_PHY_AGC_ANT0_PM_DET_BOF_OFFSET 0x1FC */
#define B2_PHY_AGC_ANT0_PM_DET_BOF_OFFSET_FIELD_PM_DET_BOF_OFFSET_MASK                                            0x000001FF
//========================================
/* REG_PHY_AGC_ANT0_PM_BB_BOF_TARGET 0x200 */
#define B2_PHY_AGC_ANT0_PM_BB_BOF_TARGET_FIELD_PM_BB_BOF_TARGET_MASK                                              0x000001FF
//========================================
/* REG_PHY_AGC_ANT0_PM_HB_BOF_TARGET 0x204 */
#define B2_PHY_AGC_ANT0_PM_HB_BOF_TARGET_FIELD_PM_HB_BOF_TARGET_MASK                                              0x000001FF
//========================================
/* REG_PHY_AGC_ANT0_PM_IB_BOF_TARGET 0x208 */
#define B2_PHY_AGC_ANT0_PM_IB_BOF_TARGET_FIELD_PM_IB_BOF_TARGET_MASK                                              0x000001FF
//========================================
/* REG_PHY_AGC_ANT0_PM_DET_BOF_TARGET 0x20C */
#define B2_PHY_AGC_ANT0_PM_DET_BOF_TARGET_FIELD_PM_DET_BOF_TARGET_MASK                                            0x000001FF
//========================================
/* REG_PHY_AGC_ANT0_PM_DIFI1_DB_GAIN 0x210 */
#define B2_PHY_AGC_ANT0_PM_DIFI1_DB_GAIN_FIELD_PM_DIFI1_DB_GAIN_MASK                                              0x000001FF
//========================================
/* REG_PHY_AGC_ANT0_PM_PRESET_LNA_PGC1 0x214 */
#define B2_PHY_AGC_ANT0_PM_PRESET_LNA_PGC1_FIELD_PM_LNA_INDEX_MAX_GAIN_MASK                                       0x0000000F
#define B2_PHY_AGC_ANT0_PM_PRESET_LNA_PGC1_FIELD_PM_LNA_INDEX_STEP1_GAIN_MASK                                     0x000000F0
#define B2_PHY_AGC_ANT0_PM_PRESET_LNA_PGC1_FIELD_PM_LNA_INDEX_STEP1_ENV_SAT_GAIN_MASK                             0x00000F00
#define B2_PHY_AGC_ANT0_PM_PRESET_LNA_PGC1_FIELD_PM_LNA_INDEX_STEP1_SIGNAL_SAT_GAIN_MASK                          0x0000F000
#define B2_PHY_AGC_ANT0_PM_PRESET_LNA_PGC1_FIELD_PM_PGC1_INDEX_MAX_GAIN_MASK                                      0x00070000
#define B2_PHY_AGC_ANT0_PM_PRESET_LNA_PGC1_FIELD_PM_PGC1_INDEX_STEP1_GAIN_MASK                                    0x00700000
#define B2_PHY_AGC_ANT0_PM_PRESET_LNA_PGC1_FIELD_PM_PGC1_INDEX_STEP1_ENV_SAT_GAIN_MASK                            0x07000000
#define B2_PHY_AGC_ANT0_PM_PRESET_LNA_PGC1_FIELD_PM_PGC1_INDEX_STEP1_SIGNAL_SAT_GAIN_MASK                         0x70000000
//========================================
/* REG_PHY_AGC_ANT0_PM_MAX_BB_DIGITAL_GAIN 0x218 */
#define B2_PHY_AGC_ANT0_PM_MAX_BB_DIGITAL_GAIN_FIELD_PM_MAX_BB_DIGITAL_GAIN_MASK                                  0x000001FF
//========================================
/* REG_PHY_AGC_ANT0_PM_STEP1_BB_DIGITAL_GAIN 0x21C */
#define B2_PHY_AGC_ANT0_PM_STEP1_BB_DIGITAL_GAIN_FIELD_PM_STEP1_BB_DIGITAL_GAIN_MASK                              0x000001FF
//========================================
/* REG_PHY_AGC_ANT0_PM_STEP1_ENV_SAT_BB_DIGITAL_GAIN 0x220 */
#define B2_PHY_AGC_ANT0_PM_STEP1_ENV_SAT_BB_DIGITAL_GAIN_FIELD_PM_STEP1_ENV_SAT_BB_DIGITAL_GAIN_MASK              0x000001FF
//========================================
/* REG_PHY_AGC_ANT0_PM_STEP1_SIGNAL_SAT_BB_DIGITAL_GAIN 0x224 */
#define B2_PHY_AGC_ANT0_PM_STEP1_SIGNAL_SAT_BB_DIGITAL_GAIN_FIELD_PM_STEP1_SIGNAL_SAT_BB_DIGITAL_GAIN_MASK        0x000001FF
//========================================
/* REG_PHY_AGC_ANT0_PM_MAX_HB_DIGITAL_GAIN 0x228 */
#define B2_PHY_AGC_ANT0_PM_MAX_HB_DIGITAL_GAIN_FIELD_PM_MAX_HB_DIGITAL_GAIN_MASK                                  0x000001FF
//========================================
/* REG_PHY_AGC_ANT0_PM_STEP1_HB_DIGITAL_GAIN 0x22C */
#define B2_PHY_AGC_ANT0_PM_STEP1_HB_DIGITAL_GAIN_FIELD_PM_STEP1_HB_DIGITAL_GAIN_MASK                              0x000001FF
//========================================
/* REG_PHY_AGC_ANT0_PM_STEP1_ENV_SAT_HB_DIGITAL_GAIN 0x230 */
#define B2_PHY_AGC_ANT0_PM_STEP1_ENV_SAT_HB_DIGITAL_GAIN_FIELD_PM_STEP1_ENV_SAT_HB_DIGITAL_GAIN_MASK              0x000001FF
//========================================
/* REG_PHY_AGC_ANT0_PM_STEP1_SIGNAL_SAT_HB_DIGITAL_GAIN 0x234 */
#define B2_PHY_AGC_ANT0_PM_STEP1_SIGNAL_SAT_HB_DIGITAL_GAIN_FIELD_PM_STEP1_SIGNAL_SAT_HB_DIGITAL_GAIN_MASK        0x000001FF
//========================================
/* REG_PHY_AGC_ANT0_PM_MAX_IB_DIGITAL_GAIN 0x238 */
#define B2_PHY_AGC_ANT0_PM_MAX_IB_DIGITAL_GAIN_FIELD_PM_MAX_IB_DIGITAL_GAIN_MASK                                  0x000001FF
//========================================
/* REG_PHY_AGC_ANT0_PM_STEP1_IB_DIGITAL_GAIN 0x23C */
#define B2_PHY_AGC_ANT0_PM_STEP1_IB_DIGITAL_GAIN_FIELD_PM_STEP1_IB_DIGITAL_GAIN_MASK                              0x000001FF
//========================================
/* REG_PHY_AGC_ANT0_PM_STEP1_ENV_SAT_IB_DIGITAL_GAIN 0x240 */
#define B2_PHY_AGC_ANT0_PM_STEP1_ENV_SAT_IB_DIGITAL_GAIN_FIELD_PM_STEP1_ENV_SAT_IB_DIGITAL_GAIN_MASK              0x000001FF
//========================================
/* REG_PHY_AGC_ANT0_PM_STEP1_SIGNAL_SAT_IB_DIGITAL_GAIN 0x244 */
#define B2_PHY_AGC_ANT0_PM_STEP1_SIGNAL_SAT_IB_DIGITAL_GAIN_FIELD_PM_STEP1_SIGNAL_SAT_IB_DIGITAL_GAIN_MASK        0x000001FF
//========================================
/* REG_PHY_AGC_ANT0_PM_MAX_DET_DIGITAL_GAIN 0x248 */
#define B2_PHY_AGC_ANT0_PM_MAX_DET_DIGITAL_GAIN_FIELD_PM_MAX_DET_DIGITAL_GAIN_MASK                                0x000001FF
//========================================
/* REG_PHY_AGC_ANT0_PM_STEP1_DET_DIGITAL_GAIN 0x24C */
#define B2_PHY_AGC_ANT0_PM_STEP1_DET_DIGITAL_GAIN_FIELD_PM_STEP1_DET_DIGITAL_GAIN_MASK                            0x000001FF
//========================================
/* REG_PHY_AGC_ANT0_PM_STEP1_ENV_SAT_DET_DIGITAL_GAIN 0x250 */
#define B2_PHY_AGC_ANT0_PM_STEP1_ENV_SAT_DET_DIGITAL_GAIN_FIELD_PM_STEP1_ENV_SAT_DET_DIGITAL_GAIN_MASK            0x000001FF
//========================================
/* REG_PHY_AGC_ANT0_PM_STEP1_SIGNAL_SAT_DET_DIGITAL_GAIN 0x254 */
#define B2_PHY_AGC_ANT0_PM_STEP1_SIGNAL_SAT_DET_DIGITAL_GAIN_FIELD_PM_STEP1_SIGNAL_SAT_DET_DIGITAL_GAIN_MASK      0x000001FF
//========================================
/* REG_PHY_AGC_ANT0_ACC_RF_POWER 0x258 */
#define B2_PHY_AGC_ANT0_ACC_RF_POWER_FIELD_ACC_RF_POWER_MASK                                                      0x000001FF
//========================================
/* REG_PHY_AGC_ANT0_ACC_FB_POWER 0x25C */
#define B2_PHY_AGC_ANT0_ACC_FB_POWER_FIELD_ACC_FB_POWER_MASK                                                      0x000001FF
//========================================
/* REG_PHY_AGC_ANT0_ACC_BB_POWER 0x260 */
#define B2_PHY_AGC_ANT0_ACC_BB_POWER_FIELD_ACC_BB_POWER_MASK                                                      0x000001FF
//========================================
/* REG_PHY_AGC_ANT0_ACC_HB_POWER 0x264 */
#define B2_PHY_AGC_ANT0_ACC_HB_POWER_FIELD_ACC_HB_POWER_MASK                                                      0x000001FF
//========================================
/* REG_PHY_AGC_ANT0_ACC_IB_POWER 0x268 */
#define B2_PHY_AGC_ANT0_ACC_IB_POWER_FIELD_ACC_IB_POWER_MASK                                                      0x000001FF
//========================================
/* REG_PHY_AGC_ANT0_ACC_ACI_POWER 0x26C */
#define B2_PHY_AGC_ANT0_ACC_ACI_POWER_FIELD_ACC_ACI_POWER_MASK                                                    0x000001FF
//========================================
/* REG_PHY_AGC_ANT0_ACC_SIGNAL_POWER 0x270 */
#define B2_PHY_AGC_ANT0_ACC_SIGNAL_POWER_FIELD_ACC_SIGNAL_POWER_MASK                                              0x000001FF
//========================================
/* REG_PHY_AGC_ANT0_ACC_ENV_POWER 0x274 */
#define B2_PHY_AGC_ANT0_ACC_ENV_POWER_FIELD_ACC_ENV_POWER_MASK                                                    0x000001FF
//========================================
/* REG_PHY_AGC_ANT0_ACC_STATUS 0x278 */
#define B2_PHY_AGC_ANT0_ACC_STATUS_FIELD_ACC_RF_SAT_MASK                                                          0x00000001
#define B2_PHY_AGC_ANT0_ACC_STATUS_FIELD_ACC_FB_SAT_MASK                                                          0x00000002
#define B2_PHY_AGC_ANT0_ACC_STATUS_FIELD_ACC_BB_SAT_MASK                                                          0x00000004
#define B2_PHY_AGC_ANT0_ACC_STATUS_FIELD_ACC_HB_SAT_MASK                                                          0x00000008
#define B2_PHY_AGC_ANT0_ACC_STATUS_FIELD_ACC_IB_SAT_MASK                                                          0x00000010
#define B2_PHY_AGC_ANT0_ACC_STATUS_FIELD_ACC_ACI_SAT_MASK                                                         0x00000020
#define B2_PHY_AGC_ANT0_ACC_STATUS_FIELD_ACC_UP_HB_SAT_MASK                                                       0x00000040
#define B2_PHY_AGC_ANT0_ACC_STATUS_FIELD_ACC_UP_IB_SAT_MASK                                                       0x00000080
#define B2_PHY_AGC_ANT0_ACC_STATUS_FIELD_ACC_UP_ACI_SAT_MASK                                                      0x00000100
#define B2_PHY_AGC_ANT0_ACC_STATUS_FIELD_ACC_SIGNAL_LIMIT_MAX_MASK                                                0x00000200
#define B2_PHY_AGC_ANT0_ACC_STATUS_FIELD_ACC_SIGNAL_LIMIT_MIN_MASK                                                0x00000400
#define B2_PHY_AGC_ANT0_ACC_STATUS_FIELD_ACC_SIGNAL_SAT_MASK                                                      0x00000800
#define B2_PHY_AGC_ANT0_ACC_STATUS_FIELD_ACC_ENV_LIMIT_MAX_MASK                                                   0x00001000
#define B2_PHY_AGC_ANT0_ACC_STATUS_FIELD_ACC_ENV_SAT_MASK                                                         0x00002000
#define B2_PHY_AGC_ANT0_ACC_STATUS_FIELD_ACC_ENV_LIMIT_MIN_MASK                                                   0x00004000
#define B2_PHY_AGC_ANT0_ACC_STATUS_FIELD_ACC_SIGNAL_IS_ENV_VALID_MASK                                             0x00008000
#define B2_PHY_AGC_ANT0_ACC_STATUS_FIELD_ACC_ENV_IS_SIGNAL_VALID_MASK                                             0x00010000
//========================================
/* REG_PHY_AGC_ANT0_ACC_RF_SYSTEM_GAIN 0x27C */
#define B2_PHY_AGC_ANT0_ACC_RF_SYSTEM_GAIN_FIELD_ACC_RF_SYSTEM_GAIN_MASK                                          0x000001FF
//========================================
/* REG_PHY_AGC_ANT0_ACC_FB_SYSTEM_GAIN 0x280 */
#define B2_PHY_AGC_ANT0_ACC_FB_SYSTEM_GAIN_FIELD_ACC_FB_SYSTEM_GAIN_MASK                                          0x000001FF
//========================================
/* REG_PHY_AGC_ANT0_ACC_BB_SYSTEM_GAIN 0x284 */
#define B2_PHY_AGC_ANT0_ACC_BB_SYSTEM_GAIN_FIELD_ACC_BB_SYSTEM_GAIN_MASK                                          0x000001FF
//========================================
/* REG_PHY_AGC_ANT0_ACC_POST_BB_SYSTEM_GAIN 0x288 */
#define B2_PHY_AGC_ANT0_ACC_POST_BB_SYSTEM_GAIN_FIELD_ACC_POST_BB_SYSTEM_GAIN_MASK                                0x000001FF
//========================================
/* REG_PHY_AGC_ANT0_ACC_HB_SYSTEM_GAIN 0x28C */
#define B2_PHY_AGC_ANT0_ACC_HB_SYSTEM_GAIN_FIELD_ACC_HB_SYSTEM_GAIN_MASK                                          0x000001FF
//========================================
/* REG_PHY_AGC_ANT0_ACC_IB_SYSTEM_GAIN 0x290 */
#define B2_PHY_AGC_ANT0_ACC_IB_SYSTEM_GAIN_FIELD_ACC_IB_SYSTEM_GAIN_MASK                                          0x000001FF
//========================================
/* REG_PHY_AGC_ANT0_ACC_ACI_SYSTEM_GAIN 0x294 */
#define B2_PHY_AGC_ANT0_ACC_ACI_SYSTEM_GAIN_FIELD_ACC_ACI_SYSTEM_GAIN_MASK                                        0x000001FF
//========================================
/* REG_PHY_AGC_ANT0_ACC_CCA_SYSTEM_GAIN 0x298 */
#define B2_PHY_AGC_ANT0_ACC_CCA_SYSTEM_GAIN_FIELD_ACC_CCA_SYSTEM_GAIN_MASK                                        0x000001FF
//========================================
/* REG_PHY_AGC_ANT0_ACC_DET_SYSTEM_GAIN 0x29C */
#define B2_PHY_AGC_ANT0_ACC_DET_SYSTEM_GAIN_FIELD_ACC_DET_SYSTEM_GAIN_MASK                                        0x000001FF
//========================================
/* REG_PHY_AGC_ANT0_ACC_BB_DIGITAL_GAIN 0x2A0 */
#define B2_PHY_AGC_ANT0_ACC_BB_DIGITAL_GAIN_FIELD_ACC_BB_DIGITAL_GAIN_MASK                                        0x000001FF
//========================================
/* REG_PHY_AGC_ANT0_ACC_HB_DIGITAL_GAIN 0x2A4 */
#define B2_PHY_AGC_ANT0_ACC_HB_DIGITAL_GAIN_FIELD_ACC_HB_DIGITAL_GAIN_MASK                                        0x000001FF
//========================================
/* REG_PHY_AGC_ANT0_ACC_IB_DIGITAL_GAIN 0x2A8 */
#define B2_PHY_AGC_ANT0_ACC_IB_DIGITAL_GAIN_FIELD_ACC_IB_DIGITAL_GAIN_MASK                                        0x000001FF
//========================================
/* REG_PHY_AGC_ANT0_ACC_DET_DIGITAL_GAIN 0x2AC */
#define B2_PHY_AGC_ANT0_ACC_DET_DIGITAL_GAIN_FIELD_ACC_DET_DIGITAL_GAIN_MASK                                      0x000001FF
//========================================
/* REG_PHY_AGC_ANT0_ACC_BB_BOF 0x2B0 */
#define B2_PHY_AGC_ANT0_ACC_BB_BOF_FIELD_ACC_BB_BOF_MASK                                                          0x000001FF
//========================================
/* REG_PHY_AGC_ANT0_ACC_BB_TOTAL_DIGITAL_GAIN 0x2B4 */
#define B2_PHY_AGC_ANT0_ACC_BB_TOTAL_DIGITAL_GAIN_FIELD_ACC_BB_TOTAL_DIGITAL_GAIN_MASK                            0x000001FF
//========================================
/* REG_PHY_AGC_ANT0_ACC_BB_DIGITAL_BOF 0x2B8 */
#define B2_PHY_AGC_ANT0_ACC_BB_DIGITAL_BOF_FIELD_ACC_BB_DIGITAL_BOF_MASK                                          0x000001FF
//========================================
/* REG_PHY_AGC_ANT0_ACC_HB_BOF 0x2BC */
#define B2_PHY_AGC_ANT0_ACC_HB_BOF_FIELD_ACC_HB_BOF_MASK                                                          0x000001FF
//========================================
/* REG_PHY_AGC_ANT0_ACC_HB_TOTAL_DIGITAL_GAIN 0x2C0 */
#define B2_PHY_AGC_ANT0_ACC_HB_TOTAL_DIGITAL_GAIN_FIELD_ACC_HB_TOTAL_DIGITAL_GAIN_MASK                            0x000001FF
//========================================
/* REG_PHY_AGC_ANT0_ACC_HB_DIGITAL_BOF 0x2C4 */
#define B2_PHY_AGC_ANT0_ACC_HB_DIGITAL_BOF_FIELD_ACC_HB_DIGITAL_BOF_MASK                                          0x000001FF
//========================================
/* REG_PHY_AGC_ANT0_ACC_IB_BOF 0x2C8 */
#define B2_PHY_AGC_ANT0_ACC_IB_BOF_FIELD_ACC_IB_BOF_MASK                                                          0x000001FF
//========================================
/* REG_PHY_AGC_ANT0_ACC_IB_TOTAL_DIGITAL_GAIN 0x2CC */
#define B2_PHY_AGC_ANT0_ACC_IB_TOTAL_DIGITAL_GAIN_FIELD_ACC_IB_TOTAL_DIGITAL_GAIN_MASK                            0x000001FF
//========================================
/* REG_PHY_AGC_ANT0_ACC_IB_DIGITAL_BOF 0x2D0 */
#define B2_PHY_AGC_ANT0_ACC_IB_DIGITAL_BOF_FIELD_ACC_IB_DIGITAL_BOF_MASK                                          0x000001FF
//========================================
/* REG_PHY_AGC_ANT0_ACC_DET_BOF 0x2D4 */
#define B2_PHY_AGC_ANT0_ACC_DET_BOF_FIELD_ACC_DET_BOF_MASK                                                        0x000001FF
//========================================
/* REG_PHY_AGC_ANT0_ACC_DET_TOTAL_DIGITAL_GAIN 0x2D8 */
#define B2_PHY_AGC_ANT0_ACC_DET_TOTAL_DIGITAL_GAIN_FIELD_ACC_DET_TOTAL_DIGITAL_GAIN_MASK                          0x000001FF
//========================================
/* REG_PHY_AGC_ANT0_ACC_DET_DIGITAL_BOF 0x2DC */
#define B2_PHY_AGC_ANT0_ACC_DET_DIGITAL_BOF_FIELD_ACC_DET_DIGITAL_BOF_MASK                                        0x000001FF
//========================================
/* REG_PHY_AGC_ANT0_ACC_DC_OFFSET_I 0x2E0 */
#define B2_PHY_AGC_ANT0_ACC_DC_OFFSET_I_FIELD_ACC_DC_OFFSET_I_MASK                                                0x00003FFF
//========================================
/* REG_PHY_AGC_ANT0_ACC_DC_OFFSET_Q 0x2E4 */
#define B2_PHY_AGC_ANT0_ACC_DC_OFFSET_Q_FIELD_ACC_DC_OFFSET_Q_MASK                                                0x00003FFF
//========================================
/* REG_PHY_AGC_ANT0_PM_AGC_RAMS_RM 0x2E8 */
#define B2_PHY_AGC_ANT0_PM_AGC_RAMS_RM_FIELD_PM_AGC_TABLE_RM_MASK                                                 0x00000007
//========================================
/* REG_PHY_AGC_ANT0_ACC_GAIN_VALUES 0x2EC */
#define B2_PHY_AGC_ANT0_ACC_GAIN_VALUES_FIELD_ACC_LNA_INDEX_MASK                                                  0x0000000F
#define B2_PHY_AGC_ANT0_ACC_GAIN_VALUES_FIELD_ACC_SEL_S2D_RX_MASK                                                 0x00000010
#define B2_PHY_AGC_ANT0_ACC_GAIN_VALUES_FIELD_ACC_PGC1_INDEX_MASK                                                 0x000000E0
#define B2_PHY_AGC_ANT0_ACC_GAIN_VALUES_FIELD_ACC_RX_FILTER_MASK                                                  0x00003F00
//========================================
/* REG_PHY_AGC_ANT0_PM_FCSI_CONTROL 0x2F0 */
#define B2_PHY_AGC_ANT0_PM_FCSI_CONTROL_FIELD_PM_FCSI_ENABLE_MASK                                                 0x00000001
#define B2_PHY_AGC_ANT0_PM_FCSI_CONTROL_FIELD_PM_FCSI_HEADER_MASK                                                 0x00000006
#define B2_PHY_AGC_ANT0_PM_FCSI_CONTROL_FIELD_PM_FCSI_ADDRESS_MASK                                                0x00007F00
//========================================
/* REG_PHY_AGC_ANT0_ACC_FCSI_VALUES 0x2F8 */
#define B2_PHY_AGC_ANT0_ACC_FCSI_VALUES_FIELD_ACC_FCSI_DATA_MASK                                                  0x0000FFFF
//========================================
/* REG_PHY_AGC_ANT0_ACC_GAIN_ACC_CONTROL 0x2FC */
#define B2_PHY_AGC_ANT0_ACC_GAIN_ACC_CONTROL_FIELD_ACC_DELAY_TIMER_MASK                                           0x0000FFFF
#define B2_PHY_AGC_ANT0_ACC_GAIN_ACC_CONTROL_FIELD_ACC_STM_COUNTER_MASK                                           0x001F0000
#define B2_PHY_AGC_ANT0_ACC_GAIN_ACC_CONTROL_FIELD_ACC_FCSI_BUSY_MASK                                             0x01000000
//========================================
/* REG_PHY_AGC_ANT0_PM_IB_CODE_ACC_THR 0x300 */
#define B2_PHY_AGC_ANT0_PM_IB_CODE_ACC_THR_FIELD_PM_IB_TIMER_THR_MASK                                             0x0000FFFF
#define B2_PHY_AGC_ANT0_PM_IB_CODE_ACC_THR_FIELD_PM_IB_RELEASE_THR_MASK                                           0xFFFF0000
//========================================
/* REG_PHY_AGC_ANT0_PM_BB_CODE_ACC_THR 0x304 */
#define B2_PHY_AGC_ANT0_PM_BB_CODE_ACC_THR_FIELD_PM_BB_TIMER_THR_MASK                                             0x0000FFFF
#define B2_PHY_AGC_ANT0_PM_BB_CODE_ACC_THR_FIELD_PM_BB_RELEASE_THR_MASK                                           0xFFFF0000
//========================================
/* REG_PHY_AGC_ANT0_PM_LONGTERM_RELEASE_THR 0x308 */
#define B2_PHY_AGC_ANT0_PM_LONGTERM_RELEASE_THR_FIELD_PM_LONGTERM_RELEASE_THR_MASK                                0x0000FFFF
//========================================
/* REG_PHY_AGC_ANT0_PM_LONGTERM_THR 0x30C */
#define B2_PHY_AGC_ANT0_PM_LONGTERM_THR_FIELD_PM_LONGTERM_THR_MASK                                                0x000001FF
//========================================
/* REG_PHY_AGC_ANT0_PM_BB_POWER_FAST_LOW_THR 0x310 */
#define B2_PHY_AGC_ANT0_PM_BB_POWER_FAST_LOW_THR_FIELD_PM_BB_POWER_FAST_LOW_THR_MASK                              0x000001FF
//========================================
/* REG_PHY_AGC_ANT0_PM_DELTA_CODE_ACC_THR 0x314 */
#define B2_PHY_AGC_ANT0_PM_DELTA_CODE_ACC_THR_FIELD_PM_BB_DELTA_THR_MASK                                          0x000001FF
#define B2_PHY_AGC_ANT0_PM_DELTA_CODE_ACC_THR_FIELD_PM_IB_DELTA_THR_MASK                                          0x01FF0000
//========================================
/* REG_PHY_AGC_ANT0_PM_BB_POWER_UP_THR 0x318 */
#define B2_PHY_AGC_ANT0_PM_BB_POWER_UP_THR_FIELD_PM_BB_POWER_UP_THR_MASK                                          0x000001FF
//========================================
/* REG_PHY_AGC_ANT0_PM_BB_POWER_SLOW_LOW_THR 0x31C */
#define B2_PHY_AGC_ANT0_PM_BB_POWER_SLOW_LOW_THR_FIELD_PM_BB_POWER_SLOW_LOW_THR_MASK                              0x000001FF
//========================================
/* REG_PHY_AGC_ANT0_PM_IB_POWER_UP_THR 0x320 */
#define B2_PHY_AGC_ANT0_PM_IB_POWER_UP_THR_FIELD_PM_IB_POWER_UP_THR_MASK                                          0x000001FF
//========================================
/* REG_PHY_AGC_ANT0_PM_IB_POWER_SLOW_LOW_THR 0x324 */
#define B2_PHY_AGC_ANT0_PM_IB_POWER_SLOW_LOW_THR_FIELD_PM_IB_POWER_SLOW_LOW_THR_MASK                              0x000001FF
//========================================
/* REG_PHY_AGC_ANT0_PM_SET_CODE_ACC_THR_CTRL 0x328 */
#define B2_PHY_AGC_ANT0_PM_SET_CODE_ACC_THR_CTRL_FIELD_PM_SET_BB_THR_CTRL_MASK                                    0x00000001
#define B2_PHY_AGC_ANT0_PM_SET_CODE_ACC_THR_CTRL_FIELD_PM_SET_IB_THR_CTRL_MASK                                    0x00000002
//========================================
/* REG_PHY_AGC_ANT0_PM_ALGO_CTRL 0x32C */
#define B2_PHY_AGC_ANT0_PM_ALGO_CTRL_FIELD_PM_ALGO_CTRL_MASK                                                      0x0000FFFF
//========================================
/* REG_PHY_AGC_ANT0_ACC_EVENT_STATUS 0x330 */
#define B2_PHY_AGC_ANT0_ACC_EVENT_STATUS_FIELD_ACC_CODE_ACC_EVENT_TYPE_MASK                                       0x000001FF
#define B2_PHY_AGC_ANT0_ACC_EVENT_STATUS_FIELD_ACC_CODE_ACC_EVENT_INDICATION_MASK                                 0x00001000
//========================================
/* REG_PHY_AGC_ANT0_PM_BB_TH_SET_INC_GAP_DB 0x334 */
#define B2_PHY_AGC_ANT0_PM_BB_TH_SET_INC_GAP_DB_FIELD_PM_BB_TH_SET_INC_GAP_DB_MASK                                0x000001FF
//========================================
/* REG_PHY_AGC_ANT0_PM_BB_TH_SET_DEC_GAP_DB 0x338 */
#define B2_PHY_AGC_ANT0_PM_BB_TH_SET_DEC_GAP_DB_FIELD_PM_BB_TH_SET_DEC_GAP_DB_MASK                                0x000001FF
//========================================
/* REG_PHY_AGC_ANT0_PM_BB_TH_UP_EXTRA_GAP_DB 0x33C */
#define B2_PHY_AGC_ANT0_PM_BB_TH_UP_EXTRA_GAP_DB_FIELD_PM_BB_TH_UP_EXTRA_GAP_DB_MASK                              0x000001FF
//========================================
/* REG_PHY_AGC_ANT0_PM_BB_POWER_UP_DEF_THR 0x340 */
#define B2_PHY_AGC_ANT0_PM_BB_POWER_UP_DEF_THR_FIELD_PM_BB_POWER_UP_DEF_THR_MASK                                  0x000001FF
//========================================
/* REG_PHY_AGC_ANT0_PM_BB_POWER_SLOW_LOW_MIN_THR 0x344 */
#define B2_PHY_AGC_ANT0_PM_BB_POWER_SLOW_LOW_MIN_THR_FIELD_PM_BB_POWER_SLOW_LOW_MIN_THR_MASK                      0x000001FF
//========================================
/* REG_PHY_AGC_ANT0_PM_IB_TH_SET_INC_GAP_DB 0x348 */
#define B2_PHY_AGC_ANT0_PM_IB_TH_SET_INC_GAP_DB_FIELD_PM_IB_TH_SET_INC_GAP_DB_MASK                                0x000001FF
//========================================
/* REG_PHY_AGC_ANT0_PM_IB_TH_SET_DEC_GAP_DB 0x34C */
#define B2_PHY_AGC_ANT0_PM_IB_TH_SET_DEC_GAP_DB_FIELD_PM_IB_TH_SET_DEC_GAP_DB_MASK                                0x000001FF
//========================================
/* REG_PHY_AGC_ANT0_PM_IB_TH_UP_EXTRA_GAP_DB 0x350 */
#define B2_PHY_AGC_ANT0_PM_IB_TH_UP_EXTRA_GAP_DB_FIELD_PM_IB_TH_UP_EXTRA_GAP_DB_MASK                              0x000001FF
//========================================
/* REG_PHY_AGC_ANT0_PM_IB_POWER_UP_DEF_THR 0x354 */
#define B2_PHY_AGC_ANT0_PM_IB_POWER_UP_DEF_THR_FIELD_PM_IB_POWER_UP_DEF_THR_MASK                                  0x000001FF
//========================================
/* REG_PHY_AGC_ANT0_PM_IB_POWER_SLOW_LOW_MIN_THR 0x358 */
#define B2_PHY_AGC_ANT0_PM_IB_POWER_SLOW_LOW_MIN_THR_FIELD_PM_IB_POWER_SLOW_LOW_MIN_THR_MASK                      0x000001FF
//========================================
/* REG_PHY_AGC_ANT0_ACC_BB_POWER_UP_THR 0x35C */
#define B2_PHY_AGC_ANT0_ACC_BB_POWER_UP_THR_FIELD_ACC_BB_POWER_UP_THR_MASK                                        0x000001FF
//========================================
/* REG_PHY_AGC_ANT0_ACC_BB_POWER_SLOW_LOW_THR 0x360 */
#define B2_PHY_AGC_ANT0_ACC_BB_POWER_SLOW_LOW_THR_FIELD_ACC_BB_POWER_SLOW_LOW_THR_MASK                            0x000001FF
//========================================
/* REG_PHY_AGC_ANT0_ACC_IB_POWER_UP_THR 0x364 */
#define B2_PHY_AGC_ANT0_ACC_IB_POWER_UP_THR_FIELD_ACC_IB_POWER_UP_THR_MASK                                        0x000001FF
//========================================
/* REG_PHY_AGC_ANT0_ACC_IB_POWER_SLOW_LOW_THR 0x368 */
#define B2_PHY_AGC_ANT0_ACC_IB_POWER_SLOW_LOW_THR_FIELD_ACC_IB_POWER_SLOW_LOW_THR_MASK                            0x000001FF
//========================================
/* REG_PHY_AGC_ANT0_CALC_AGC_GAIN_WORD 0x36C */
#define B2_PHY_AGC_ANT0_CALC_AGC_GAIN_WORD_FIELD_CALC_TABLE_GO_MASK                                               0x00000001
#define B2_PHY_AGC_ANT0_CALC_AGC_GAIN_WORD_FIELD_CALC_SET_CALIBRATION_MASK                                        0x00000008
#define B2_PHY_AGC_ANT0_CALC_AGC_GAIN_WORD_FIELD_CALC_SET_MAX_GAIN_MASK                                           0x00000010
#define B2_PHY_AGC_ANT0_CALC_AGC_GAIN_WORD_FIELD_CALC_SET_STEP1_GAIN_MASK                                         0x00000020
#define B2_PHY_AGC_ANT0_CALC_AGC_GAIN_WORD_FIELD_CALC_NEW_LNA_MASK                                                0x00000040
#define B2_PHY_AGC_ANT0_CALC_AGC_GAIN_WORD_FIELD_CALC_NEW_PGC1_MASK                                               0x00000080
#define B2_PHY_AGC_ANT0_CALC_AGC_GAIN_WORD_FIELD_CALC_NEW_BB_DIGITAL_GAIN_MASK                                    0x00000100
#define B2_PHY_AGC_ANT0_CALC_AGC_GAIN_WORD_FIELD_CALC_NEW_HB_DIGITAL_GAIN_MASK                                    0x00000200
#define B2_PHY_AGC_ANT0_CALC_AGC_GAIN_WORD_FIELD_CALC_NEW_IB_DIGITAL_GAIN_MASK                                    0x00000400
#define B2_PHY_AGC_ANT0_CALC_AGC_GAIN_WORD_FIELD_CALC_NEW_DET_DIGITAL_GAIN_MASK                                   0x00000800
#define B2_PHY_AGC_ANT0_CALC_AGC_GAIN_WORD_FIELD_CALC_NEW_DC_VALUES_MASK                                          0x00001000
#define B2_PHY_AGC_ANT0_CALC_AGC_GAIN_WORD_FIELD_CALC_NEW_BLOCKER_TYPE_MASK                                       0x00002000
#define B2_PHY_AGC_ANT0_CALC_AGC_GAIN_WORD_FIELD_CALC_NO_RF_ACCESS_MASK                                           0x00008000
//========================================
/* REG_PHY_AGC_ANT0_CALC_AGC_STM_CLEAR_CONTROL 0x370 */
#define B2_PHY_AGC_ANT0_CALC_AGC_STM_CLEAR_CONTROL_FIELD_CALC_CLEAR_AGC_TIMERS_MASK                               0x00000001
#define B2_PHY_AGC_ANT0_CALC_AGC_STM_CLEAR_CONTROL_FIELD_CALC_CLEAR_AGC_EVENT_TYPE_MASK                           0x00000002
#define B2_PHY_AGC_ANT0_CALC_AGC_STM_CLEAR_CONTROL_FIELD_CALC_CLEAR_AGC_MASK_OP_MASK                              0x00000004
//========================================
/* REG_PHY_AGC_ANT0_CALC_ACC_AUTO_CLOSE_MODE 0x374 */
#define B2_PHY_AGC_ANT0_CALC_ACC_AUTO_CLOSE_MODE_FIELD_CALC_ACC_AUTO_CLOSE_MODE_MASK                              0x00000001
//========================================
/* REG_PHY_AGC_ANT0_CALC_POWER_THR_ACC_GO 0x378 */
#define B2_PHY_AGC_ANT0_CALC_POWER_THR_ACC_GO_FIELD_CALC_BB_POWER_THR_ACC_GO_MASK                                 0x00000001
#define B2_PHY_AGC_ANT0_CALC_POWER_THR_ACC_GO_FIELD_CALC_IB_POWER_THR_ACC_GO_MASK                                 0x00000002
//========================================
/* REG_PHY_AGC_ANT0_CALC_AGC_GAIN_CANCEL 0x37C */
#define B2_PHY_AGC_ANT0_CALC_AGC_GAIN_CANCEL_FIELD_CALC_AGC_GAIN_CANCEL_MASK                                      0x00000001
//========================================
/* REG_PHY_AGC_ANT0_DISABLE_PERIPHERALS 0x380 */
#define B2_PHY_AGC_ANT0_DISABLE_PERIPHERALS_FIELD_DISABLE_PERIPHERALS_MASK                                        0x00000001
//========================================
/* REG_PHY_AGC_ANT0_AGC_STM_RDBACK 0x384 */
#define B2_PHY_AGC_ANT0_AGC_STM_RDBACK_FIELD_AGC_STM_RDBACK_MASK                                                  0x0000003F
//========================================
/* REG_PHY_AGC_ANT0_PM_MAX_LIMIT_ACC_BB_DIGITAL_GAIN 0x388 */
#define B2_PHY_AGC_ANT0_PM_MAX_LIMIT_ACC_BB_DIGITAL_GAIN_FIELD_PM_MAX_LIMIT_ACC_BB_DIGITAL_GAIN_MASK              0x000001FF
//========================================
/* REG_PHY_AGC_ANT0_PM_MIN_LIMIT_ACC_BB_DIGITAL_GAIN 0x38C */
#define B2_PHY_AGC_ANT0_PM_MIN_LIMIT_ACC_BB_DIGITAL_GAIN_FIELD_PM_MIN_LIMIT_ACC_BB_DIGITAL_GAIN_MASK              0x000001FF
//========================================
/* REG_PHY_AGC_ANT0_PM_MAX_LIMIT_ACC_HB_DIGITAL_GAIN 0x390 */
#define B2_PHY_AGC_ANT0_PM_MAX_LIMIT_ACC_HB_DIGITAL_GAIN_FIELD_PM_MAX_LIMIT_ACC_HB_DIGITAL_GAIN_MASK              0x000001FF
//========================================
/* REG_PHY_AGC_ANT0_PM_MIN_LIMIT_ACC_HB_DIGITAL_GAIN 0x394 */
#define B2_PHY_AGC_ANT0_PM_MIN_LIMIT_ACC_HB_DIGITAL_GAIN_FIELD_PM_MIN_LIMIT_ACC_HB_DIGITAL_GAIN_MASK              0x000001FF
//========================================
/* REG_PHY_AGC_ANT0_PM_MAX_LIMIT_ACC_IB_DIGITAL_GAIN 0x398 */
#define B2_PHY_AGC_ANT0_PM_MAX_LIMIT_ACC_IB_DIGITAL_GAIN_FIELD_PM_MAX_LIMIT_ACC_IB_DIGITAL_GAIN_MASK              0x000001FF
//========================================
/* REG_PHY_AGC_ANT0_PM_MIN_LIMIT_ACC_IB_DIGITAL_GAIN 0x39C */
#define B2_PHY_AGC_ANT0_PM_MIN_LIMIT_ACC_IB_DIGITAL_GAIN_FIELD_PM_MIN_LIMIT_ACC_IB_DIGITAL_GAIN_MASK              0x000001FF
//========================================
/* REG_PHY_AGC_ANT0_PM_MAX_LIMIT_ACC_DET_DIGITAL_GAIN 0x3A0 */
#define B2_PHY_AGC_ANT0_PM_MAX_LIMIT_ACC_DET_DIGITAL_GAIN_FIELD_PM_MAX_LIMIT_ACC_DET_DIGITAL_GAIN_MASK            0x000001FF
//========================================
/* REG_PHY_AGC_ANT0_PM_MIN_LIMIT_ACC_DET_DIGITAL_GAIN 0x3A4 */
#define B2_PHY_AGC_ANT0_PM_MIN_LIMIT_ACC_DET_DIGITAL_GAIN_FIELD_PM_MIN_LIMIT_ACC_DET_DIGITAL_GAIN_MASK            0x000001FF
//========================================
/* REG_PHY_AGC_ANT0_BLOCKER_CONTROL 0x3C0 */
#define B2_PHY_AGC_ANT0_BLOCKER_CONTROL_FIELD_PM_BLOCKER_TYPE_MASK                                                0x00000003
#define B2_PHY_AGC_ANT0_BLOCKER_CONTROL_FIELD_ACC_BLOCKER_TYPE_MASK                                               0x00000030
//========================================
/* REG_PHY_AGC_ANT0_PM_BLOCKER_TH 0x3C4 */
#define B2_PHY_AGC_ANT0_PM_BLOCKER_TH_FIELD_PM_BS_ADJ_ALT_TH_MASK                                                 0x000000FF
#define B2_PHY_AGC_ANT0_PM_BLOCKER_TH_FIELD_PM_ENV_ALT_TH_MASK                                                    0x0000FF00
#define B2_PHY_AGC_ANT0_PM_BLOCKER_TH_FIELD_PM_ENV_SIG_ALT_TH_MASK                                                0x00FF0000
//========================================
/* REG_PHY_AGC_ANT0_PM_ALGO_CTRL_SEL 0x3D0 */
#define B2_PHY_AGC_ANT0_PM_ALGO_CTRL_SEL_FIELD_PM_ALGO_CTRL_SEL_IN0_MASK                                          0x00000007
#define B2_PHY_AGC_ANT0_PM_ALGO_CTRL_SEL_FIELD_PM_ALGO_CTRL_SEL_IN1_MASK                                          0x00000070
//========================================
/* REG_PHY_AGC_ANT0_ACC_BLOCKER_ADDR 0x3D4 */
#define B2_PHY_AGC_ANT0_ACC_BLOCKER_ADDR_FIELD_ACC_LSB_BLOCKER_ADDR_MASK                                          0x0000007F
#define B2_PHY_AGC_ANT0_ACC_BLOCKER_ADDR_FIELD_ACC_USB_BLOCKER_ADDR_MASK                                          0x00007F00
//========================================
/* REG_PHY_AGC_ANT0_UP_INB_RSSI_PARAMS_REG 0x400 */
#define B2_PHY_AGC_ANT0_UP_INB_RSSI_PARAMS_REG_FIELD_UP_INBAND_RSSI_BLK_SIZE_MASK                                 0x00000007
#define B2_PHY_AGC_ANT0_UP_INB_RSSI_PARAMS_REG_FIELD_UP_INBAND_RSSI_IIR_POLE_MASK                                 0x00000780
#define B2_PHY_AGC_ANT0_UP_INB_RSSI_PARAMS_REG_FIELD_UP_INBAND_RSSI_IIR_POLE_MIN_MASK                             0x00003800
#define B2_PHY_AGC_ANT0_UP_INB_RSSI_PARAMS_REG_FIELD_UP_INBAND_RSSI_OFFSET1_MASK                                  0x3FFFC000
#define B2_PHY_AGC_ANT0_UP_INB_RSSI_PARAMS_REG_FIELD_UP_INBAND_RSSI_CANCEL_DC_MASK                                0x40000000
//========================================
/* REG_PHY_AGC_ANT0_UP_INB_RSSI_OFFSET2_REG 0x404 */
#define B2_PHY_AGC_ANT0_UP_INB_RSSI_OFFSET2_REG_FIELD_UP_INBAND_RSSI_OFFSET2_MASK                                 0x000001FF
//========================================
/* REG_PHY_AGC_ANT0_UP_INBAND_RSSI_SYSTEM_GAIN_REG 0x408 */
#define B2_PHY_AGC_ANT0_UP_INBAND_RSSI_SYSTEM_GAIN_REG_FIELD_UP_INBAND_RSSI_SYSTEM_GAIN_MASK                      0x000001FF
//========================================
/* REG_PHY_AGC_ANT0_UP_INBAND_RSSI_SYSTEM_GAIN_SELECT_REG 0x40C */
#define B2_PHY_AGC_ANT0_UP_INBAND_RSSI_SYSTEM_GAIN_SELECT_REG_FIELD_UP_INBAND_RSSI_SYSTEM_GAIN_HW_SELECT_MASK     0x00000001
//========================================
/* REG_PHY_AGC_ANT0_UP_INBAND_RSSI_SAT_THR 0x410 */
#define B2_PHY_AGC_ANT0_UP_INBAND_RSSI_SAT_THR_FIELD_UP_INBAND_RSSI_SAT_THR_MASK                                  0x000001FF
//========================================
/* REG_PHY_AGC_ANT0_UP_HB_RSSI_PARAMS_REG 0x414 */
#define B2_PHY_AGC_ANT0_UP_HB_RSSI_PARAMS_REG_FIELD_UP_HB_RSSI_BLK_SIZE_MASK                                      0x00000007
#define B2_PHY_AGC_ANT0_UP_HB_RSSI_PARAMS_REG_FIELD_UP_HB_RSSI_IIR_POLE_MASK                                      0x00000780
#define B2_PHY_AGC_ANT0_UP_HB_RSSI_PARAMS_REG_FIELD_UP_HB_RSSI_IIR_POLE_MIN_MASK                                  0x00003800
#define B2_PHY_AGC_ANT0_UP_HB_RSSI_PARAMS_REG_FIELD_UP_HB_RSSI_OFFSET1_MASK                                       0x3FFFC000
#define B2_PHY_AGC_ANT0_UP_HB_RSSI_PARAMS_REG_FIELD_UP_HB_RSSI_CANCEL_DC_MASK                                     0x40000000
//========================================
/* REG_PHY_AGC_ANT0_UP_HB_RSSI_OFFSET2_REG 0x418 */
#define B2_PHY_AGC_ANT0_UP_HB_RSSI_OFFSET2_REG_FIELD_UP_HB_RSSI_OFFSET2_MASK                                      0x000001FF
//========================================
/* REG_PHY_AGC_ANT0_UP_HB_RSSI_SYSTEM_GAIN_REG 0x41C */
#define B2_PHY_AGC_ANT0_UP_HB_RSSI_SYSTEM_GAIN_REG_FIELD_UP_HB_RSSI_SYSTEM_GAIN_MASK                              0x000001FF
//========================================
/* REG_PHY_AGC_ANT0_UP_HB_RSSI_SYSTEM_GAIN_SELECT_REG 0x420 */
#define B2_PHY_AGC_ANT0_UP_HB_RSSI_SYSTEM_GAIN_SELECT_REG_FIELD_UP_HB_RSSI_SYSTEM_GAIN_HW_SELECT_MASK             0x00000001
//========================================
/* REG_PHY_AGC_ANT0_UP_HB_RSSI_SAT_THR 0x424 */
#define B2_PHY_AGC_ANT0_UP_HB_RSSI_SAT_THR_FIELD_UP_HB_RSSI_SAT_THR_MASK                                          0x000001FF
//========================================
/* REG_PHY_AGC_ANT0_UP_IB_RSSI_REG 0x428 */
#define B2_PHY_AGC_ANT0_UP_IB_RSSI_REG_FIELD_UP_IB_RSSI_MASK                                                      0x000001FF
//========================================
/* REG_PHY_AGC_ANT0_UP_IB_POWER_REG 0x42C */
#define B2_PHY_AGC_ANT0_UP_IB_POWER_REG_FIELD_UP_IB_POWER_MASK                                                    0x000001FF
//========================================
/* REG_PHY_AGC_ANT0_UP_IB_SRSSI_REG 0x430 */
#define B2_PHY_AGC_ANT0_UP_IB_SRSSI_REG_FIELD_UP_IB_SRSSI_MASK                                                    0x000001FF
//========================================
/* REG_PHY_AGC_ANT0_UP_IB_SPOWER_REG 0x434 */
#define B2_PHY_AGC_ANT0_UP_IB_SPOWER_REG_FIELD_UP_IB_SPOWER_MASK                                                  0x000001FF
//========================================
/* REG_PHY_AGC_ANT0_UP_IB_PWR_DIFF_REG 0x438 */
#define B2_PHY_AGC_ANT0_UP_IB_PWR_DIFF_REG_FIELD_UP_IB_B1_MASK                                                    0x000001FF
#define B2_PHY_AGC_ANT0_UP_IB_PWR_DIFF_REG_FIELD_UP_IB_B2_MASK                                                    0x0003FE00
//========================================
/* REG_PHY_AGC_ANT0_UP_HB_RSSI_REG 0x43C */
#define B2_PHY_AGC_ANT0_UP_HB_RSSI_REG_FIELD_UP_HB_RSSI_MASK                                                      0x000001FF
//========================================
/* REG_PHY_AGC_ANT0_UP_HB_POWER_REG 0x440 */
#define B2_PHY_AGC_ANT0_UP_HB_POWER_REG_FIELD_UP_HB_POWER_MASK                                                    0x000001FF
//========================================
/* REG_PHY_AGC_ANT0_UP_HB_SRSSI_REG 0x444 */
#define B2_PHY_AGC_ANT0_UP_HB_SRSSI_REG_FIELD_UP_HB_SRSSI_MASK                                                    0x000001FF
//========================================
/* REG_PHY_AGC_ANT0_UP_HB_SPOWER_REG 0x448 */
#define B2_PHY_AGC_ANT0_UP_HB_SPOWER_REG_FIELD_UP_HB_SPOWER_MASK                                                  0x000001FF
//========================================
/* REG_PHY_AGC_ANT0_UP_HB_PWR_DIFF_REG 0x44C */
#define B2_PHY_AGC_ANT0_UP_HB_PWR_DIFF_REG_FIELD_UP_HB_B1_MASK                                                    0x000001FF
#define B2_PHY_AGC_ANT0_UP_HB_PWR_DIFF_REG_FIELD_UP_HB_B2_MASK                                                    0x0003FE00
//========================================
/* REG_PHY_AGC_ANT0_PM_UP_HB_POWER 0x450 */
#define B2_PHY_AGC_ANT0_PM_UP_HB_POWER_FIELD_PM_UP_HB_POWER_MASK                                                  0x000001FF
//========================================
/* REG_PHY_AGC_ANT0_PM_UP_IB_POWER 0x454 */
#define B2_PHY_AGC_ANT0_PM_UP_IB_POWER_FIELD_PM_UP_IB_POWER_MASK                                                  0x000001FF
//========================================
/* REG_PHY_AGC_ANT0_PM_UP_ACI_POWER 0x458 */
#define B2_PHY_AGC_ANT0_PM_UP_ACI_POWER_FIELD_PM_UP_ACI_POWER_MASK                                                0x000001FF
//========================================
/* REG_PHY_AGC_ANT0_ACC_UP_HB_POWER 0x45C */
#define B2_PHY_AGC_ANT0_ACC_UP_HB_POWER_FIELD_ACC_UP_HB_POWER_MASK                                                0x000001FF
//========================================
/* REG_PHY_AGC_ANT0_ACC_UP_IB_POWER 0x460 */
#define B2_PHY_AGC_ANT0_ACC_UP_IB_POWER_FIELD_ACC_UP_IB_POWER_MASK                                                0x000001FF
//========================================
/* REG_PHY_AGC_ANT0_ACC_UP_ACI_POWER 0x464 */
#define B2_PHY_AGC_ANT0_ACC_UP_ACI_POWER_FIELD_ACC_UP_ACI_POWER_MASK                                              0x000001FF
//========================================
/* REG_PHY_AGC_ANT0_UP_CONTROL 0x468 */
#define B2_PHY_AGC_ANT0_UP_CONTROL_FIELD_HB_IS_MAX_MASK                                                           0x00000001
#define B2_PHY_AGC_ANT0_UP_CONTROL_FIELD_IB_IS_MAX_MASK                                                           0x00000002
#define B2_PHY_AGC_ANT0_UP_CONTROL_FIELD_ACI_IS_MAX_MASK                                                          0x00000004
#define B2_PHY_AGC_ANT0_UP_CONTROL_FIELD_HB_SYS_GAIN_SOURCE_MASK                                                  0x00000030
#define B2_PHY_AGC_ANT0_UP_CONTROL_FIELD_IB_SYS_GAIN_SOURCE_MASK                                                  0x000000C0
#define B2_PHY_AGC_ANT0_UP_CONTROL_FIELD_ACI_SYS_GAIN_SOURCE_MASK                                                 0x00000300
#define B2_PHY_AGC_ANT0_UP_CONTROL_FIELD_EVENT_HB_IS_MAX_MASK                                                     0x00001000
#define B2_PHY_AGC_ANT0_UP_CONTROL_FIELD_EVENT_IB_IS_MAX_MASK                                                     0x00002000
#define B2_PHY_AGC_ANT0_UP_CONTROL_FIELD_EVENT_ACI_IS_MAX_MASK                                                    0x00004000
//========================================
/* REG_PHY_AGC_ANT0_PM_UP_HB_SYSTEM_GAIN_OFFSET 0x46C */
#define B2_PHY_AGC_ANT0_PM_UP_HB_SYSTEM_GAIN_OFFSET_FIELD_PM_UP_HB_SYSTEM_GAIN_OFFSET_MASK                        0x000001FF
//========================================
/* REG_PHY_AGC_ANT0_PM_UP_IB_SYSTEM_GAIN_OFFSET 0x470 */
#define B2_PHY_AGC_ANT0_PM_UP_IB_SYSTEM_GAIN_OFFSET_FIELD_PM_UP_IB_SYSTEM_GAIN_OFFSET_MASK                        0x000001FF
//========================================
/* REG_PHY_AGC_ANT0_PM_UP_ACI_SYSTEM_GAIN_OFFSET 0x474 */
#define B2_PHY_AGC_ANT0_PM_UP_ACI_SYSTEM_GAIN_OFFSET_FIELD_PM_UP_ACI_SYSTEM_GAIN_OFFSET_MASK                      0x000001FF
//========================================
/* REG_PHY_AGC_ANT0_PM_UP_CCA_SYSTEM_GAIN_OFFSET 0x478 */
#define B2_PHY_AGC_ANT0_PM_UP_CCA_SYSTEM_GAIN_OFFSET_FIELD_PM_UP_CCA_SYSTEM_GAIN_OFFSET_MASK                      0x000001FF
//========================================
/* REG_PHY_AGC_ANT0_PM_UP_HB_BOF_OFFSET 0x47C */
#define B2_PHY_AGC_ANT0_PM_UP_HB_BOF_OFFSET_FIELD_PM_UP_HB_BOF_OFFSET_MASK                                        0x000001FF
//========================================
/* REG_PHY_AGC_ANT0_PM_UP_IB_RSSI_BOF_OFFSET 0x480 */
#define B2_PHY_AGC_ANT0_PM_UP_IB_RSSI_BOF_OFFSET_FIELD_PM_UP_IB_RSSI_BOF_OFFSET_MASK                              0x000001FF
//========================================
/* REG_PHY_AGC_ANT0_PM_UP_IB_ACI_BOF_OFFSET 0x484 */
#define B2_PHY_AGC_ANT0_PM_UP_IB_ACI_BOF_OFFSET_FIELD_PM_UP_IB_ACI_BOF_OFFSET_MASK                                0x000001FF
//========================================
/* REG_PHY_AGC_ANT0_PM_UP_HB_BOF_TARGET 0x488 */
#define B2_PHY_AGC_ANT0_PM_UP_HB_BOF_TARGET_FIELD_PM_UP_HB_BOF_TARGET_MASK                                        0x000001FF
//========================================
/* REG_PHY_AGC_ANT0_PM_UP_IB_BOF_TARGET 0x48C */
#define B2_PHY_AGC_ANT0_PM_UP_IB_BOF_TARGET_FIELD_PM_UP_IB_BOF_TARGET_MASK                                        0x000001FF
//========================================
/* REG_PHY_AGC_ANT0_ACC_UP_HB_SYSTEM_GAIN 0x490 */
#define B2_PHY_AGC_ANT0_ACC_UP_HB_SYSTEM_GAIN_FIELD_ACC_UP_HB_SYSTEM_GAIN_MASK                                    0x000001FF
//========================================
/* REG_PHY_AGC_ANT0_ACC_UP_IB_SYSTEM_GAIN 0x494 */
#define B2_PHY_AGC_ANT0_ACC_UP_IB_SYSTEM_GAIN_FIELD_ACC_UP_IB_SYSTEM_GAIN_MASK                                    0x000001FF
//========================================
/* REG_PHY_AGC_ANT0_ACC_UP_ACI_SYSTEM_GAIN 0x498 */
#define B2_PHY_AGC_ANT0_ACC_UP_ACI_SYSTEM_GAIN_FIELD_ACC_UP_ACI_SYSTEM_GAIN_MASK                                  0x000001FF
//========================================
/* REG_PHY_AGC_ANT0_ACC_UP_CCA_SYSTEM_GAIN 0x49C */
#define B2_PHY_AGC_ANT0_ACC_UP_CCA_SYSTEM_GAIN_FIELD_ACC_UP_CCA_SYSTEM_GAIN_MASK                                  0x000001FF
//========================================
/* REG_PHY_AGC_ANT0_ACC_UP_HB_DIGITAL_GAIN 0x4A0 */
#define B2_PHY_AGC_ANT0_ACC_UP_HB_DIGITAL_GAIN_FIELD_ACC_UP_HB_DIGITAL_GAIN_MASK                                  0x000001FF
//========================================
/* REG_PHY_AGC_ANT0_ACC_UP_IB_DIGITAL_GAIN 0x4A4 */
#define B2_PHY_AGC_ANT0_ACC_UP_IB_DIGITAL_GAIN_FIELD_ACC_UP_IB_DIGITAL_GAIN_MASK                                  0x000001FF
//========================================
/* REG_PHY_AGC_ANT0_ACC_UP_HB_BOF 0x4A8 */
#define B2_PHY_AGC_ANT0_ACC_UP_HB_BOF_FIELD_ACC_UP_HB_BOF_MASK                                                    0x000001FF
//========================================
/* REG_PHY_AGC_ANT0_ACC_UP_HB_TOTAL_DIGITAL_GAIN 0x4AC */
#define B2_PHY_AGC_ANT0_ACC_UP_HB_TOTAL_DIGITAL_GAIN_FIELD_ACC_UP_HB_TOTAL_DIGITAL_GAIN_MASK                      0x000001FF
//========================================
/* REG_PHY_AGC_ANT0_ACC_UP_HB_DIGITAL_BOF 0x4B0 */
#define B2_PHY_AGC_ANT0_ACC_UP_HB_DIGITAL_BOF_FIELD_ACC_UP_HB_DIGITAL_BOF_MASK                                    0x000001FF
//========================================
/* REG_PHY_AGC_ANT0_ACC_UP_IB_BOF 0x4B4 */
#define B2_PHY_AGC_ANT0_ACC_UP_IB_BOF_FIELD_ACC_UP_IB_BOF_MASK                                                    0x000001FF
//========================================
/* REG_PHY_AGC_ANT0_ACC_UP_IB_TOTAL_DIGITAL_GAIN 0x4B8 */
#define B2_PHY_AGC_ANT0_ACC_UP_IB_TOTAL_DIGITAL_GAIN_FIELD_ACC_UP_IB_TOTAL_DIGITAL_GAIN_MASK                      0x000001FF
//========================================
/* REG_PHY_AGC_ANT0_ACC_UP_IB_DIGITAL_BOF 0x4BC */
#define B2_PHY_AGC_ANT0_ACC_UP_IB_DIGITAL_BOF_FIELD_ACC_UP_IB_DIGITAL_BOF_MASK                                    0x000001FF
//========================================
/* REG_PHY_AGC_ANT0_PM_ACC_GAIN_SAT_SOURCES 0x4C0 */
#define B2_PHY_AGC_ANT0_PM_ACC_GAIN_SAT_SOURCES_FIELD_PM_ACC_GAIN_ENV_SAT_SOURCE_MASK                             0x00000007
#define B2_PHY_AGC_ANT0_PM_ACC_GAIN_SAT_SOURCES_FIELD_PM_ACC_GAIN_SIGNAL_SAT_SOURCE_MASK                          0x00007F00
//========================================
/* REG_PHY_AGC_ANT0_PM_LNA_GAIN_LUT_0 0x4C4 */
#define B2_PHY_AGC_ANT0_PM_LNA_GAIN_LUT_0_FIELD_PM_LNA_GAIN_LUT_0_MASK                                            0x000001FF
//========================================
/* REG_PHY_AGC_ANT0_PM_LNA_GAIN_LUT_1 0x4C8 */
#define B2_PHY_AGC_ANT0_PM_LNA_GAIN_LUT_1_FIELD_PM_LNA_GAIN_LUT_1_MASK                                            0x000001FF
//========================================
/* REG_PHY_AGC_ANT0_PM_LNA_GAIN_LUT_2 0x4CC */
#define B2_PHY_AGC_ANT0_PM_LNA_GAIN_LUT_2_FIELD_PM_LNA_GAIN_LUT_2_MASK                                            0x000001FF
//========================================
/* REG_PHY_AGC_ANT0_PM_LNA_GAIN_LUT_3 0x4D0 */
#define B2_PHY_AGC_ANT0_PM_LNA_GAIN_LUT_3_FIELD_PM_LNA_GAIN_LUT_3_MASK                                            0x000001FF
//========================================
/* REG_PHY_AGC_ANT0_PM_LNA_GAIN_LUT_4 0x4D4 */
#define B2_PHY_AGC_ANT0_PM_LNA_GAIN_LUT_4_FIELD_PM_LNA_GAIN_LUT_4_MASK                                            0x000001FF
//========================================
/* REG_PHY_AGC_ANT0_PM_LNA_GAIN_LUT_5 0x4D8 */
#define B2_PHY_AGC_ANT0_PM_LNA_GAIN_LUT_5_FIELD_PM_LNA_GAIN_LUT_5_MASK                                            0x000001FF
//========================================
/* REG_PHY_AGC_ANT0_PM_LNA_GAIN_LUT_6 0x4DC */
#define B2_PHY_AGC_ANT0_PM_LNA_GAIN_LUT_6_FIELD_PM_LNA_GAIN_LUT_6_MASK                                            0x000001FF
//========================================
/* REG_PHY_AGC_ANT0_PM_LNA_GAIN_LUT_7 0x4E0 */
#define B2_PHY_AGC_ANT0_PM_LNA_GAIN_LUT_7_FIELD_PM_LNA_GAIN_LUT_7_MASK                                            0x000001FF
//========================================
/* REG_PHY_AGC_ANT0_PM_LNA_GAIN_LUT_8 0x4E4 */
#define B2_PHY_AGC_ANT0_PM_LNA_GAIN_LUT_8_FIELD_PM_LNA_GAIN_LUT_8_MASK                                            0x000001FF
//========================================
/* REG_PHY_AGC_ANT0_PM_LNA_GAIN_LUT_9 0x4E8 */
#define B2_PHY_AGC_ANT0_PM_LNA_GAIN_LUT_9_FIELD_PM_LNA_GAIN_LUT_9_MASK                                            0x000001FF
//========================================
/* REG_PHY_AGC_ANT0_PM_LNA_GAIN_LUT_10 0x4EC */
#define B2_PHY_AGC_ANT0_PM_LNA_GAIN_LUT_10_FIELD_PM_LNA_GAIN_LUT_10_MASK                                          0x000001FF
//========================================
/* REG_PHY_AGC_ANT0_PM_LNA_GAIN_LUT_11 0x4F0 */
#define B2_PHY_AGC_ANT0_PM_LNA_GAIN_LUT_11_FIELD_PM_LNA_GAIN_LUT_11_MASK                                          0x000001FF
//========================================
/* REG_PHY_AGC_ANT0_PM_LNA_GAIN_LUT_12 0x4F4 */
#define B2_PHY_AGC_ANT0_PM_LNA_GAIN_LUT_12_FIELD_PM_LNA_GAIN_LUT_12_MASK                                          0x000001FF
//========================================
/* REG_PHY_AGC_ANT0_PM_LNA_GAIN_LUT_13 0x4F8 */
#define B2_PHY_AGC_ANT0_PM_LNA_GAIN_LUT_13_FIELD_PM_LNA_GAIN_LUT_13_MASK                                          0x000001FF
//========================================
/* REG_PHY_AGC_ANT0_PM_BS_ABS_TH_B0_B4 0x500 */
#define B2_PHY_AGC_ANT0_PM_BS_ABS_TH_B0_B4_FIELD_PM_BS_ABS_TH_B0_MASK                                             0x000000FF
#define B2_PHY_AGC_ANT0_PM_BS_ABS_TH_B0_B4_FIELD_PM_BS_ABS_TH_B1_MASK                                             0x0000FF00
#define B2_PHY_AGC_ANT0_PM_BS_ABS_TH_B0_B4_FIELD_PM_BS_ABS_TH_B2_MASK                                             0x00FF0000
#define B2_PHY_AGC_ANT0_PM_BS_ABS_TH_B0_B4_FIELD_PM_BS_ABS_TH_B3_MASK                                             0xFF000000
//========================================
/* REG_PHY_AGC_ANT0_PM_BS_ABS_TH_B5_B7 0x504 */
#define B2_PHY_AGC_ANT0_PM_BS_ABS_TH_B5_B7_FIELD_PM_BS_ABS_TH_B4_MASK                                             0x000000FF
#define B2_PHY_AGC_ANT0_PM_BS_ABS_TH_B5_B7_FIELD_PM_BS_ABS_TH_B5_MASK                                             0x0000FF00
#define B2_PHY_AGC_ANT0_PM_BS_ABS_TH_B5_B7_FIELD_PM_BS_ABS_TH_B6_MASK                                             0x00FF0000
#define B2_PHY_AGC_ANT0_PM_BS_ABS_TH_B5_B7_FIELD_PM_BS_ABS_TH_B7_MASK                                             0xFF000000
//========================================
/* REG_PHY_AGC_ANT0_PM_BS_ABS_TH_B8_B11 0x508 */
#define B2_PHY_AGC_ANT0_PM_BS_ABS_TH_B8_B11_FIELD_PM_BS_ABS_TH_B8_MASK                                            0x000000FF
#define B2_PHY_AGC_ANT0_PM_BS_ABS_TH_B8_B11_FIELD_PM_BS_ABS_TH_B9_MASK                                            0x0000FF00
#define B2_PHY_AGC_ANT0_PM_BS_ABS_TH_B8_B11_FIELD_PM_BS_ABS_TH_B10_MASK                                           0x00FF0000
#define B2_PHY_AGC_ANT0_PM_BS_ABS_TH_B8_B11_FIELD_PM_BS_ABS_TH_B11_MASK                                           0xFF000000
//========================================
/* REG_PHY_AGC_ANT0_PM_BS_OFF_TH_B0_B4 0x50C */
#define B2_PHY_AGC_ANT0_PM_BS_OFF_TH_B0_B4_FIELD_PM_BS_OFF_TH_B0_MASK                                             0x000000FF
#define B2_PHY_AGC_ANT0_PM_BS_OFF_TH_B0_B4_FIELD_PM_BS_OFF_TH_B1_MASK                                             0x0000FF00
#define B2_PHY_AGC_ANT0_PM_BS_OFF_TH_B0_B4_FIELD_PM_BS_OFF_TH_B2_MASK                                             0x00FF0000
#define B2_PHY_AGC_ANT0_PM_BS_OFF_TH_B0_B4_FIELD_PM_BS_OFF_TH_B3_MASK                                             0xFF000000
//========================================
/* REG_PHY_AGC_ANT0_PM_BS_OFF_TH_B5_B7 0x510 */
#define B2_PHY_AGC_ANT0_PM_BS_OFF_TH_B5_B7_FIELD_PM_BS_OFF_TH_B4_MASK                                             0x000000FF
#define B2_PHY_AGC_ANT0_PM_BS_OFF_TH_B5_B7_FIELD_PM_BS_OFF_TH_B5_MASK                                             0x0000FF00
#define B2_PHY_AGC_ANT0_PM_BS_OFF_TH_B5_B7_FIELD_PM_BS_OFF_TH_B6_MASK                                             0x00FF0000
#define B2_PHY_AGC_ANT0_PM_BS_OFF_TH_B5_B7_FIELD_PM_BS_OFF_TH_B7_MASK                                             0xFF000000
//========================================
/* REG_PHY_AGC_ANT0_PM_BS_OFF_TH_B8_B11 0x514 */
#define B2_PHY_AGC_ANT0_PM_BS_OFF_TH_B8_B11_FIELD_PM_BS_OFF_TH_B8_MASK                                            0x000000FF
#define B2_PHY_AGC_ANT0_PM_BS_OFF_TH_B8_B11_FIELD_PM_BS_OFF_TH_B9_MASK                                            0x0000FF00
#define B2_PHY_AGC_ANT0_PM_BS_OFF_TH_B8_B11_FIELD_PM_BS_OFF_TH_B10_MASK                                           0x00FF0000
#define B2_PHY_AGC_ANT0_PM_BS_OFF_TH_B8_B11_FIELD_PM_BS_OFF_TH_B11_MASK                                           0xFF000000
//========================================
/* REG_PHY_AGC_ANT0_ACC_OFFSET_BS0_B4 0x518 */
#define B2_PHY_AGC_ANT0_ACC_OFFSET_BS0_B4_FIELD_ACC_OFFSET_BS0_MASK                                               0x000000FF
#define B2_PHY_AGC_ANT0_ACC_OFFSET_BS0_B4_FIELD_ACC_OFFSET_BS1_MASK                                               0x0000FF00
#define B2_PHY_AGC_ANT0_ACC_OFFSET_BS0_B4_FIELD_ACC_OFFSET_BS2_MASK                                               0x00FF0000
#define B2_PHY_AGC_ANT0_ACC_OFFSET_BS0_B4_FIELD_ACC_OFFSET_BS3_MASK                                               0xFF000000
//========================================
/* REG_PHY_AGC_ANT0_ACC_OFFSET_BS4_B7 0x51C */
#define B2_PHY_AGC_ANT0_ACC_OFFSET_BS4_B7_FIELD_ACC_OFFSET_BS4_MASK                                               0x000000FF
#define B2_PHY_AGC_ANT0_ACC_OFFSET_BS4_B7_FIELD_ACC_OFFSET_BS5_MASK                                               0x0000FF00
#define B2_PHY_AGC_ANT0_ACC_OFFSET_BS4_B7_FIELD_ACC_OFFSET_BS6_MASK                                               0x00FF0000
#define B2_PHY_AGC_ANT0_ACC_OFFSET_BS4_B7_FIELD_ACC_OFFSET_BS7_MASK                                               0xFF000000
//========================================
/* REG_PHY_AGC_ANT0_ACC_OFFSET_BS8_B11 0x520 */
#define B2_PHY_AGC_ANT0_ACC_OFFSET_BS8_B11_FIELD_ACC_OFFSET_BS8_MASK                                              0x000000FF
#define B2_PHY_AGC_ANT0_ACC_OFFSET_BS8_B11_FIELD_ACC_OFFSET_BS9_MASK                                              0x0000FF00
#define B2_PHY_AGC_ANT0_ACC_OFFSET_BS8_B11_FIELD_ACC_OFFSET_BS10_MASK                                             0x00FF0000
#define B2_PHY_AGC_ANT0_ACC_OFFSET_BS8_B11_FIELD_ACC_OFFSET_BS11_MASK                                             0xFF000000
//========================================
/* REG_PHY_AGC_ANT0_ACC_ABS_BLOCKER_MAP 0x524 */
#define B2_PHY_AGC_ANT0_ACC_ABS_BLOCKER_MAP_FIELD_ACC_ABS_BLOCKER_MAP_MASK                                        0xFFFFFFFF
//========================================
/* REG_PHY_AGC_ANT0_ACC_TH_BLOCKER_MAP 0x528 */
#define B2_PHY_AGC_ANT0_ACC_TH_BLOCKER_MAP_FIELD_ACC_TH_BLOCKER_MAP_MASK                                          0xFFFFFFFF
//========================================
/* REG_PHY_AGC_ANT0_ACC_MAX_BLOCKER_LSB_POWER 0x52C */
#define B2_PHY_AGC_ANT0_ACC_MAX_BLOCKER_LSB_POWER_FIELD_ACC_MAX_BLOCKER_LSB_POWER_MASK                            0x000001FF
//========================================
/* REG_PHY_AGC_ANT0_ACC_MAX_BLOCKER_USB_POWER 0x530 */
#define B2_PHY_AGC_ANT0_ACC_MAX_BLOCKER_USB_POWER_FIELD_ACC_MAX_BLOCKER_USB_POWER_MASK                            0x000001FF
//========================================
/* REG_PHY_AGC_ANT0_PM_LNA_INTERNAL_GAIN 0x534 */
#define B2_PHY_AGC_ANT0_PM_LNA_INTERNAL_GAIN_FIELD_PM_LNA_INTERNAL_GAIN_MASK                                      0x000001FF
//========================================
/* REG_PHY_AGC_ANT0_PM_PRI_ACI_POWER 0x538 */
#define B2_PHY_AGC_ANT0_PM_PRI_ACI_POWER_FIELD_PM_PRI_ACI_POWER_MASK                                              0x000001FF
//========================================
/* REG_PHY_AGC_ANT0_ACC_PRI_ACI_POWER 0x53C */
#define B2_PHY_AGC_ANT0_ACC_PRI_ACI_POWER_FIELD_ACC_PRI_ACI_POWER_MASK                                            0x000001FF
//========================================
/* REG_PHY_AGC_ANT0_ULTRA_WIDE_BAND 0x540 */
#define B2_PHY_AGC_ANT0_ULTRA_WIDE_BAND_FIELD_ULTRA_WIDE_BAND_MASK                                                0x00000001
//========================================
/* REG_PHY_AGC_ANT0_PM_PRESET_CALIBRATION 0x544 */
#define B2_PHY_AGC_ANT0_PM_PRESET_CALIBRATION_FIELD_PM_PRESET_CALIBRATION_LNA_INDEX_MASK                          0x0000000F
#define B2_PHY_AGC_ANT0_PM_PRESET_CALIBRATION_FIELD_PM_PRESET_CALIBRATION_SEL_S2D_RX_MASK                         0x00000010
#define B2_PHY_AGC_ANT0_PM_PRESET_CALIBRATION_FIELD_PM_PRESET_CALIBRATION_PGC1_INDEX_MASK                         0x000000E0
#define B2_PHY_AGC_ANT0_PM_PRESET_CALIBRATION_FIELD_PM_PRESET_CALIBRATION_RX_FILTER_MASK                          0x00003F00
//========================================
/* REG_PHY_AGC_ANT0_AGC_MEASURMENT_FOR_SPUR_CANCEL 0x548 */
#define B2_PHY_AGC_ANT0_AGC_MEASURMENT_FOR_SPUR_CANCEL_FIELD_LNA_INDEX_FOR_SPUR_CANCEL_MASK                       0x0000000F
#define B2_PHY_AGC_ANT0_AGC_MEASURMENT_FOR_SPUR_CANCEL_FIELD_PGC_INDEX_FOR_SPUR_CANCEL_MASK                       0x00000070
#define B2_PHY_AGC_ANT0_AGC_MEASURMENT_FOR_SPUR_CANCEL_FIELD_BB_DIGITAL_GAIN_FOR_SPUR_CANCEL_MASK                 0x00003F80
//========================================
/* REG_PHY_AGC_ANT0_PM_LIMIT_LNA_MAX_INDEX 0x54C */
#define B2_PHY_AGC_ANT0_PM_LIMIT_LNA_MAX_INDEX_FIELD_PM_LIMIT_LNA_MAX_INDEX_MASK                                  0x0000000F


#endif // _PHY_AGC_ANT0_REGS_H_
