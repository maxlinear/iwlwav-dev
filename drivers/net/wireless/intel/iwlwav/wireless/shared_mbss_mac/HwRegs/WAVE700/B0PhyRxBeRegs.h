
/***********************************************************************************
File:				B0PhyRxBeRegs.h
Module:				b0PhyRxBe
SOC Revision:		latest
Generated at:       2022-05-04 10:57:17
Purpose:
Description:		This File was auto generated using SOC Online

************************************************************************************/
#ifndef _B0_PHY_RX_BE_REGS_H_
#define _B0_PHY_RX_BE_REGS_H_

/*---------------------------------------------------------------------------------
/						Registers Addresses													 
/----------------------------------------------------------------------------------*/
#include "HwMemoryMap.h"

#define B0_PHY_RX_BE_BASE_ADDRESS                             MEMORY_MAP_UNIT_201_BASE_ADDRESS
#define	REG_B0_PHY_RX_BE_PHY_RXBE_REG04                      (B0_PHY_RX_BE_BASE_ADDRESS + 0x10)
#define	REG_B0_PHY_RX_BE_PHY_RXBE_REG05                      (B0_PHY_RX_BE_BASE_ADDRESS + 0x14)
#define	REG_B0_PHY_RX_BE_PHY_RXBE_REG07                      (B0_PHY_RX_BE_BASE_ADDRESS + 0x1C)
#define	REG_B0_PHY_RX_BE_PHY_RXBE_REG08                      (B0_PHY_RX_BE_BASE_ADDRESS + 0x20)
#define	REG_B0_PHY_RX_BE_PHY_RXBE_REG18                      (B0_PHY_RX_BE_BASE_ADDRESS + 0x60)
#define	REG_B0_PHY_RX_BE_PHY_RXBE_REG19                      (B0_PHY_RX_BE_BASE_ADDRESS + 0x64)
#define	REG_B0_PHY_RX_BE_PHY_RXBE_REG1E                      (B0_PHY_RX_BE_BASE_ADDRESS + 0x78)
#define	REG_B0_PHY_RX_BE_PHY_RXBE_REG20                      (B0_PHY_RX_BE_BASE_ADDRESS + 0x80)
#define	REG_B0_PHY_RX_BE_PHY_RXBE_REG21                      (B0_PHY_RX_BE_BASE_ADDRESS + 0x84)
#define	REG_B0_PHY_RX_BE_PHY_RXBE_REG22                      (B0_PHY_RX_BE_BASE_ADDRESS + 0x88)
#define	REG_B0_PHY_RX_BE_PHY_RXBE_REG23                      (B0_PHY_RX_BE_BASE_ADDRESS + 0x8C)
#define	REG_B0_PHY_RX_BE_PHY_RXBE_REG24                      (B0_PHY_RX_BE_BASE_ADDRESS + 0x90)
#define	REG_B0_PHY_RX_BE_PHY_RXBE_REG25                      (B0_PHY_RX_BE_BASE_ADDRESS + 0x94)
#define	REG_B0_PHY_RX_BE_PHY_RXBE_REG26                      (B0_PHY_RX_BE_BASE_ADDRESS + 0x98)
#define	REG_B0_PHY_RX_BE_PHY_RXBE_REG28                      (B0_PHY_RX_BE_BASE_ADDRESS + 0xA0)
#define	REG_B0_PHY_RX_BE_PHY_RXBE_REG34                      (B0_PHY_RX_BE_BASE_ADDRESS + 0xD0)
#define	REG_B0_PHY_RX_BE_PHY_RXBE_REG35                      (B0_PHY_RX_BE_BASE_ADDRESS + 0xD4)
#define	REG_B0_PHY_RX_BE_PHY_RXBE_REG36                      (B0_PHY_RX_BE_BASE_ADDRESS + 0xD8)
#define	REG_B0_PHY_RX_BE_PHY_RXBE_REG37                      (B0_PHY_RX_BE_BASE_ADDRESS + 0xDC)
#define	REG_B0_PHY_RX_BE_PHY_RXBE_REG38                      (B0_PHY_RX_BE_BASE_ADDRESS + 0xE0)
#define	REG_B0_PHY_RX_BE_PHY_RXBE_REG39                      (B0_PHY_RX_BE_BASE_ADDRESS + 0xE4)
#define	REG_B0_PHY_RX_BE_PHY_RXBE_REG3F                      (B0_PHY_RX_BE_BASE_ADDRESS + 0xFC)
#define	REG_B0_PHY_RX_BE_PHY_RXBE_REG41                      (B0_PHY_RX_BE_BASE_ADDRESS + 0x104)
#define	REG_B0_PHY_RX_BE_PHY_RXBE_REG42                      (B0_PHY_RX_BE_BASE_ADDRESS + 0x108)
#define	REG_B0_PHY_RX_BE_PHY_RXBE_REG4A                      (B0_PHY_RX_BE_BASE_ADDRESS + 0x128)
#define	REG_B0_PHY_RX_BE_PHY_RXBE_REG4B                      (B0_PHY_RX_BE_BASE_ADDRESS + 0x12C)
#define	REG_B0_PHY_RX_BE_PHY_RXBE_REG4C                      (B0_PHY_RX_BE_BASE_ADDRESS + 0x130)
#define	REG_B0_PHY_RX_BE_PHY_RXBE_REG4D                      (B0_PHY_RX_BE_BASE_ADDRESS + 0x134)
#define	REG_B0_PHY_RX_BE_PHY_RXBE_REG4E                      (B0_PHY_RX_BE_BASE_ADDRESS + 0x138)
#define	REG_B0_PHY_RX_BE_PHY_RXBE_REG4F                      (B0_PHY_RX_BE_BASE_ADDRESS + 0x13C)
#define	REG_B0_PHY_RX_BE_PHY_RXBE_REG50                      (B0_PHY_RX_BE_BASE_ADDRESS + 0x140)
#define	REG_B0_PHY_RX_BE_PHY_RXBE_REG52                      (B0_PHY_RX_BE_BASE_ADDRESS + 0x148)
#define	REG_B0_PHY_RX_BE_PHY_RXBE_REG55                      (B0_PHY_RX_BE_BASE_ADDRESS + 0x154)
#define	REG_B0_PHY_RX_BE_PHY_RXBE_REG56                      (B0_PHY_RX_BE_BASE_ADDRESS + 0x158)
#define	REG_B0_PHY_RX_BE_PHY_RXBE_REG57                      (B0_PHY_RX_BE_BASE_ADDRESS + 0x15C)
#define	REG_B0_PHY_RX_BE_PHY_RXBE_REG58                      (B0_PHY_RX_BE_BASE_ADDRESS + 0x160)
#define	REG_B0_PHY_RX_BE_PHY_RXBE_REG59                      (B0_PHY_RX_BE_BASE_ADDRESS + 0x164)
#define	REG_B0_PHY_RX_BE_PHY_RXBE_REG5A                      (B0_PHY_RX_BE_BASE_ADDRESS + 0x168)
#define	REG_B0_PHY_RX_BE_PHY_RXBE_REG5D                      (B0_PHY_RX_BE_BASE_ADDRESS + 0x174)
#define	REG_B0_PHY_RX_BE_PHY_RXBE_REG5E                      (B0_PHY_RX_BE_BASE_ADDRESS + 0x178)
#define	REG_B0_PHY_RX_BE_PHY_RXBE_REG64                      (B0_PHY_RX_BE_BASE_ADDRESS + 0x190)
#define	REG_B0_PHY_RX_BE_PHY_RXBE_REG65                      (B0_PHY_RX_BE_BASE_ADDRESS + 0x194)
#define	REG_B0_PHY_RX_BE_PHY_RXBE_REG67                      (B0_PHY_RX_BE_BASE_ADDRESS + 0x19C)
#define	REG_B0_PHY_RX_BE_PHY_RXBE_REG68                      (B0_PHY_RX_BE_BASE_ADDRESS + 0x1A0)
#define	REG_B0_PHY_RX_BE_PHY_RXBE_REG69                      (B0_PHY_RX_BE_BASE_ADDRESS + 0x1A4)
#define	REG_B0_PHY_RX_BE_PHY_RXBE_REG6A                      (B0_PHY_RX_BE_BASE_ADDRESS + 0x1A8)
#define	REG_B0_PHY_RX_BE_PHY_RXBE_REG6B                      (B0_PHY_RX_BE_BASE_ADDRESS + 0x1AC)
#define	REG_B0_PHY_RX_BE_PHY_RXBE_REG6C                      (B0_PHY_RX_BE_BASE_ADDRESS + 0x1B0)
#define	REG_B0_PHY_RX_BE_PHY_RXBE_REG6D                      (B0_PHY_RX_BE_BASE_ADDRESS + 0x1B4)
#define	REG_B0_PHY_RX_BE_PHY_RXBE_REG6E                      (B0_PHY_RX_BE_BASE_ADDRESS + 0x1B8)
#define	REG_B0_PHY_RX_BE_PHY_RXBE_REG6F                      (B0_PHY_RX_BE_BASE_ADDRESS + 0x1BC)
#define	REG_B0_PHY_RX_BE_PHY_RXBE_REG70                      (B0_PHY_RX_BE_BASE_ADDRESS + 0x1C0)
#define	REG_B0_PHY_RX_BE_PHY_RXBE_REG71                      (B0_PHY_RX_BE_BASE_ADDRESS + 0x1C4)
#define	REG_B0_PHY_RX_BE_PHY_RXBE_REG72                      (B0_PHY_RX_BE_BASE_ADDRESS + 0x1C8)
#define	REG_B0_PHY_RX_BE_PHY_RXBE_REG73                      (B0_PHY_RX_BE_BASE_ADDRESS + 0x1CC)
#define	REG_B0_PHY_RX_BE_PHY_RXBE_REG74                      (B0_PHY_RX_BE_BASE_ADDRESS + 0x1D0)
#define	REG_B0_PHY_RX_BE_PHY_RXBE_REG75                      (B0_PHY_RX_BE_BASE_ADDRESS + 0x1D4)
#define	REG_B0_PHY_RX_BE_PHY_RXBE_REG76                      (B0_PHY_RX_BE_BASE_ADDRESS + 0x1D8)
#define	REG_B0_PHY_RX_BE_PHY_RXBE_REG77                      (B0_PHY_RX_BE_BASE_ADDRESS + 0x1DC)
#define	REG_B0_PHY_RX_BE_PHY_RXBE_REG78                      (B0_PHY_RX_BE_BASE_ADDRESS + 0x1E0)
#define	REG_B0_PHY_RX_BE_PHY_RXBE_REG79                      (B0_PHY_RX_BE_BASE_ADDRESS + 0x1E4)
#define	REG_B0_PHY_RX_BE_PHY_RXBE_REG80                      (B0_PHY_RX_BE_BASE_ADDRESS + 0x1E8)
#define	REG_B0_PHY_RX_BE_PHY_RXBE_REG81                      (B0_PHY_RX_BE_BASE_ADDRESS + 0x1EC)
#define	REG_B0_PHY_RX_BE_PHY_RXBE_REG82                      (B0_PHY_RX_BE_BASE_ADDRESS + 0x1F0)
#define	REG_B0_PHY_RX_BE_PHY_RXBE_REG83                      (B0_PHY_RX_BE_BASE_ADDRESS + 0x1F4)
#define	REG_B0_PHY_RX_BE_PHY_RXBE_REG84                      (B0_PHY_RX_BE_BASE_ADDRESS + 0x1F8)
#define	REG_B0_PHY_RX_BE_PHY_RXBE_REG85                      (B0_PHY_RX_BE_BASE_ADDRESS + 0x1FC)
#define	REG_B0_PHY_RX_BE_PHY_RXBE_REG86                      (B0_PHY_RX_BE_BASE_ADDRESS + 0x200)
#define	REG_B0_PHY_RX_BE_PHY_RXBE_REG87                      (B0_PHY_RX_BE_BASE_ADDRESS + 0x204)
#define	REG_B0_PHY_RX_BE_PHY_RXBE_REG88                      (B0_PHY_RX_BE_BASE_ADDRESS + 0x208)
#define	REG_B0_PHY_RX_BE_PHY_RXBE_REG89                      (B0_PHY_RX_BE_BASE_ADDRESS + 0x20C)
#define	REG_B0_PHY_RX_BE_PHY_RXBE_REG90                      (B0_PHY_RX_BE_BASE_ADDRESS + 0x210)
#define	REG_B0_PHY_RX_BE_PHY_RXBE_REG91                      (B0_PHY_RX_BE_BASE_ADDRESS + 0x214)
#define	REG_B0_PHY_RX_BE_PHY_RXBE_REG92                      (B0_PHY_RX_BE_BASE_ADDRESS + 0x218)
#define	REG_B0_PHY_RX_BE_PHY_RXBE_REG93                      (B0_PHY_RX_BE_BASE_ADDRESS + 0x21C)
#define	REG_B0_PHY_RX_BE_PHY_RXBE_REG94                      (B0_PHY_RX_BE_BASE_ADDRESS + 0x220)
#define	REG_B0_PHY_RX_BE_PHY_RXBE_REG95                      (B0_PHY_RX_BE_BASE_ADDRESS + 0x224)
#define	REG_B0_PHY_RX_BE_PHY_RXBE_REG96                      (B0_PHY_RX_BE_BASE_ADDRESS + 0x228)
#define	REG_B0_PHY_RX_BE_PHY_RXBE_REG97                      (B0_PHY_RX_BE_BASE_ADDRESS + 0x22C)
#define	REG_B0_PHY_RX_BE_PHY_RXBE_REG98                      (B0_PHY_RX_BE_BASE_ADDRESS + 0x230)
#define	REG_B0_PHY_RX_BE_PHY_RXBE_REG99                      (B0_PHY_RX_BE_BASE_ADDRESS + 0x234)
#define	REG_B0_PHY_RX_BE_PHY_RXBE_REG9A                      (B0_PHY_RX_BE_BASE_ADDRESS + 0x238)
#define	REG_B0_PHY_RX_BE_PHY_RXBE_REG9B                      (B0_PHY_RX_BE_BASE_ADDRESS + 0x23C)
#define	REG_B0_PHY_RX_BE_PHY_RXBE_REG9C                      (B0_PHY_RX_BE_BASE_ADDRESS + 0x240)
#define	REG_B0_PHY_RX_BE_PHY_RXBE_REGA1                      (B0_PHY_RX_BE_BASE_ADDRESS + 0x254)
#define	REG_B0_PHY_RX_BE_PHY_RXBE_REGA2                      (B0_PHY_RX_BE_BASE_ADDRESS + 0x258)
#define	REG_B0_PHY_RX_BE_LDPC_CALC_VALID                     (B0_PHY_RX_BE_BASE_ADDRESS + 0x25C)
#define	REG_B0_PHY_RX_BE_LDPC_VITERBI_USER_ACTIVE            (B0_PHY_RX_BE_BASE_ADDRESS + 0x260)
#define	REG_B0_PHY_RX_BE_LDPC_USER_ACTIVE                    (B0_PHY_RX_BE_BASE_ADDRESS + 0x264)
#define	REG_B0_PHY_RX_BE_LDPC_MAX_N_CW                       (B0_PHY_RX_BE_BASE_ADDRESS + 0x268)
#define	REG_B0_PHY_RX_BE_LDPC_CYCLES_PER_CW                  (B0_PHY_RX_BE_BASE_ADDRESS + 0x26C)
#define	REG_B0_PHY_RX_BE_LDPC_MAX_CHECK_CONV                 (B0_PHY_RX_BE_BASE_ADDRESS + 0x270)
#define	REG_B0_PHY_RX_BE_BUS_PAC_PHY_RX_CRC_CHECK_0          (B0_PHY_RX_BE_BASE_ADDRESS + 0x274)
#define	REG_B0_PHY_RX_BE_BUS_PAC_PHY_RX_CRC_CHECK_1          (B0_PHY_RX_BE_BASE_ADDRESS + 0x278)
#define	REG_B0_PHY_RX_BE_RCR_ACTIVE_USERS_0                  (B0_PHY_RX_BE_BASE_ADDRESS + 0x27C)
#define	REG_B0_PHY_RX_BE_RCR_ACTIVE_USERS_1                  (B0_PHY_RX_BE_BASE_ADDRESS + 0x280)
#define	REG_B0_PHY_RX_BE_SIGB_STID_0                         (B0_PHY_RX_BE_BASE_ADDRESS + 0x284)
#define	REG_B0_PHY_RX_BE_SIGB_STID_1                         (B0_PHY_RX_BE_BASE_ADDRESS + 0x288)
#define	REG_B0_PHY_RX_BE_SIGB_STID_2                         (B0_PHY_RX_BE_BASE_ADDRESS + 0x28C)
#define	REG_B0_PHY_RX_BE_SIGB_STID_3                         (B0_PHY_RX_BE_BASE_ADDRESS + 0x290)
#define	REG_B0_PHY_RX_BE_SIGB_STID_4                         (B0_PHY_RX_BE_BASE_ADDRESS + 0x294)
#define	REG_B0_PHY_RX_BE_SIGB_STID_5                         (B0_PHY_RX_BE_BASE_ADDRESS + 0x298)
#define	REG_B0_PHY_RX_BE_SIGB_STID_6                         (B0_PHY_RX_BE_BASE_ADDRESS + 0x29C)
#define	REG_B0_PHY_RX_BE_SIGB_STID_7                         (B0_PHY_RX_BE_BASE_ADDRESS + 0x2A0)
#define	REG_B0_PHY_RX_BE_SIGB_STID_8                         (B0_PHY_RX_BE_BASE_ADDRESS + 0x2A4)
#define	REG_B0_PHY_RX_BE_SIGB_STID_9                         (B0_PHY_RX_BE_BASE_ADDRESS + 0x2A8)
#define	REG_B0_PHY_RX_BE_SIGB_STID_10                        (B0_PHY_RX_BE_BASE_ADDRESS + 0x2AC)
#define	REG_B0_PHY_RX_BE_SIGB_STID_11                        (B0_PHY_RX_BE_BASE_ADDRESS + 0x2B0)
#define	REG_B0_PHY_RX_BE_SIGB_STID_12                        (B0_PHY_RX_BE_BASE_ADDRESS + 0x2B4)
#define	REG_B0_PHY_RX_BE_SIGB_STID_13                        (B0_PHY_RX_BE_BASE_ADDRESS + 0x2B8)
#define	REG_B0_PHY_RX_BE_SIGB_STID_14                        (B0_PHY_RX_BE_BASE_ADDRESS + 0x2BC)
#define	REG_B0_PHY_RX_BE_SIGB_STID_15                        (B0_PHY_RX_BE_BASE_ADDRESS + 0x2D0)
#define	REG_B0_PHY_RX_BE_LDPC_CYCLES_LAST_SYMBOL             (B0_PHY_RX_BE_BASE_ADDRESS + 0x2D4)
#define	REG_B0_PHY_RX_BE_LDPC_CYCLES_STEADY_STATE            (B0_PHY_RX_BE_BASE_ADDRESS + 0x2D8)
#define	REG_B0_PHY_RX_BE_LDPC_CYCLES_FIRST_CW                (B0_PHY_RX_BE_BASE_ADDRESS + 0x2DC)
#define	REG_B0_PHY_RX_BE_LDPC_LAST_SYMBOL_CW_INDEX           (B0_PHY_RX_BE_BASE_ADDRESS + 0x2E0)
#define	REG_B0_PHY_RX_BE_LDPC_CORE_GCLK_CHICKEN_BIT          (B0_PHY_RX_BE_BASE_ADDRESS + 0x2E4)
#define	REG_B0_PHY_RX_BE_RXBE_FSM_FORCE                      (B0_PHY_RX_BE_BASE_ADDRESS + 0x2F0)
#define	REG_B0_PHY_RX_BE_PM_LEG_MCS_TH                       (B0_PHY_RX_BE_BASE_ADDRESS + 0x2F8)
#define	REG_B0_PHY_RX_BE_PM_LEG_EVM_TH                       (B0_PHY_RX_BE_BASE_ADDRESS + 0x2FC)
#define	REG_B0_PHY_RX_BE_LEG_BELOW_EVM_TH_ERR                (B0_PHY_RX_BE_BASE_ADDRESS + 0x300)
#define	REG_B0_PHY_RX_BE_PM_MASK_LPLUSR                      (B0_PHY_RX_BE_BASE_ADDRESS + 0x304)
#define	REG_B0_PHY_RX_BE_PM_R_PLUS_L_MINIMUM_PACKET_SIZE     (B0_PHY_RX_BE_BASE_ADDRESS + 0x308)
#define	REG_B0_PHY_RX_BE_DESCRAMBLER_SEED                    (B0_PHY_RX_BE_BASE_ADDRESS + 0x30C)
#define	REG_B0_PHY_RX_BE_PM_SD_REGISTER                      (B0_PHY_RX_BE_BASE_ADDRESS + 0x310)
#define	REG_B0_PHY_RX_BE_PM_DS_REGISTER                      (B0_PHY_RX_BE_BASE_ADDRESS + 0x314)
#define	REG_B0_PHY_RX_BE_SIGB_ERROR_CODE                     (B0_PHY_RX_BE_BASE_ADDRESS + 0x318)
#define	REG_B0_PHY_RX_BE_HE_MU_COMPRESSED_MODE_INDICATION    (B0_PHY_RX_BE_BASE_ADDRESS + 0x31C)
#define	REG_B0_PHY_RX_BE_HW_MCS_UNSUPPORTED_CAUSE            (B0_PHY_RX_BE_BASE_ADDRESS + 0x320)
#define	REG_B0_PHY_RX_BE_RXBE_MASK_UNSUPPORTED_MCS           (B0_PHY_RX_BE_BASE_ADDRESS + 0x324)
#define	REG_B0_PHY_RX_BE_ROP_REGISTER                        (B0_PHY_RX_BE_BASE_ADDRESS + 0x328)
#define	REG_B0_PHY_RX_BE_EXT_RANGE_READ_ONLY                 (B0_PHY_RX_BE_BASE_ADDRESS + 0x32C)
#define	REG_B0_PHY_RX_BE_DISABLE_NEW_ER_MODE                 (B0_PHY_RX_BE_BASE_ADDRESS + 0x330)
#define	REG_B0_PHY_RX_BE_PM_MAC_DATA_0                       (B0_PHY_RX_BE_BASE_ADDRESS + 0x334)
#define	REG_B0_PHY_RX_BE_PM_MAC_DATA_1                       (B0_PHY_RX_BE_BASE_ADDRESS + 0x338)
#define	REG_B0_PHY_RX_BE_PM_MAC_DATA_2                       (B0_PHY_RX_BE_BASE_ADDRESS + 0x33C)
#define	REG_B0_PHY_RX_BE_PM_MAC_DATA_3                       (B0_PHY_RX_BE_BASE_ADDRESS + 0x340)
#define	REG_B0_PHY_RX_BE_PM_MAC_DATA_READY                   (B0_PHY_RX_BE_BASE_ADDRESS + 0x344)
#define	REG_B0_PHY_RX_BE_DC_CNT_RRAM_EN_CHK_BIT              (B0_PHY_RX_BE_BASE_ADDRESS + 0x348)
#define	REG_B0_PHY_RX_BE_PM_MIN_BURST_LENGTH                 (B0_PHY_RX_BE_BASE_ADDRESS + 0x34C)
#define	REG_B0_PHY_RX_BE_PM_LAST_SYMBOL_LDPC_CTRL            (B0_PHY_RX_BE_BASE_ADDRESS + 0x350)
#define	REG_B0_PHY_RX_BE_PM_FORCE_RU_SIZE_7                  (B0_PHY_RX_BE_BASE_ADDRESS + 0x354)
#define	REG_B0_PHY_RX_BE_PM_EHT_SCRAMBLER_ENABLE             (B0_PHY_RX_BE_BASE_ADDRESS + 0x358)
#define	REG_B0_PHY_RX_BE_LDPC_CONVERGENCE_PER_USER           (B0_PHY_RX_BE_BASE_ADDRESS + 0x35C)
#define	REG_B0_PHY_RX_BE_LDPC_CYCLES_LIMIT_0                 (B0_PHY_RX_BE_BASE_ADDRESS + 0x360)
#define	REG_B0_PHY_RX_BE_LDPC_CYCLES_LIMIT_1                 (B0_PHY_RX_BE_BASE_ADDRESS + 0x364)
#define	REG_B0_PHY_RX_BE_NUM_OF_CORES                        (B0_PHY_RX_BE_BASE_ADDRESS + 0x368)
#define	REG_B0_PHY_RX_BE_USIG_OVERFLOW                       (B0_PHY_RX_BE_BASE_ADDRESS + 0x36C)
#define	REG_B0_PHY_RX_BE_EHT_INFO                            (B0_PHY_RX_BE_BASE_ADDRESS + 0x370)
#define	REG_B0_PHY_RX_BE_SPARE_FROM_FD0                      (B0_PHY_RX_BE_BASE_ADDRESS + 0x374)
#define	REG_B0_PHY_RX_BE_SPARE_FROM_FD1                      (B0_PHY_RX_BE_BASE_ADDRESS + 0x378)
#define	REG_B0_PHY_RX_BE_SPARE_FROM_TX                       (B0_PHY_RX_BE_BASE_ADDRESS + 0x37C)
#define	REG_B0_PHY_RX_BE_SPARE_FROM_TD                       (B0_PHY_RX_BE_BASE_ADDRESS + 0x380)
#define	REG_B0_PHY_RX_BE_SPARE_TO_FD0                        (B0_PHY_RX_BE_BASE_ADDRESS + 0x384)
#define	REG_B0_PHY_RX_BE_SPARE_TO_FD1                        (B0_PHY_RX_BE_BASE_ADDRESS + 0x388)
#define	REG_B0_PHY_RX_BE_SPARE_TO_TX                         (B0_PHY_RX_BE_BASE_ADDRESS + 0x38C)
#define	REG_B0_PHY_RX_BE_SPARE_TO_TD                         (B0_PHY_RX_BE_BASE_ADDRESS + 0x390)
#define	REG_B0_PHY_RX_BE_LDPC_CYCLES_SS_OV                   (B0_PHY_RX_BE_BASE_ADDRESS + 0x394)
#define	REG_B0_PHY_RX_BE_LDPC_CYCLE_LAST_SYM_OV              (B0_PHY_RX_BE_BASE_ADDRESS + 0x398)
#define	REG_B0_PHY_RX_BE_LDPC_LAST_SYM_CW_IDX                (B0_PHY_RX_BE_BASE_ADDRESS + 0x39C)
#define	REG_B0_PHY_RX_BE_USIG_0                              (B0_PHY_RX_BE_BASE_ADDRESS + 0x3A0)
#define	REG_B0_PHY_RX_BE_USIG_1                              (B0_PHY_RX_BE_BASE_ADDRESS + 0x3A4)
#define	REG_B0_PHY_RX_BE_EHT_0                               (B0_PHY_RX_BE_BASE_ADDRESS + 0x3A8)
#define	REG_B0_PHY_RX_BE_EHT_1                               (B0_PHY_RX_BE_BASE_ADDRESS + 0x3AC)
#define	REG_B0_PHY_RX_BE_IS_320_UPPER_CHANNEL                (B0_PHY_RX_BE_BASE_ADDRESS + 0x3B0)
#define	REG_B0_PHY_RX_BE_TEST_BUS_GCLK_EN                    (B0_PHY_RX_BE_BASE_ADDRESS + 0x3B4)
#define	REG_B0_PHY_RX_BE_BYTE_ERROR_CONTOL                   (B0_PHY_RX_BE_BASE_ADDRESS + 0x3B8)
#define	REG_B0_PHY_RX_BE_BYTE_ERROR_RATE                     (B0_PHY_RX_BE_BASE_ADDRESS + 0x3BC)
#define	REG_B0_PHY_RX_BE_BYTE_ERROR_RATE_RD                  (B0_PHY_RX_BE_BASE_ADDRESS + 0x3C0)
#define	REG_B0_PHY_RX_BE_DFE_CONTROL                         (B0_PHY_RX_BE_BASE_ADDRESS + 0x3C4)
#define	REG_B0_PHY_RX_BE_DFE_VALID                           (B0_PHY_RX_BE_BASE_ADDRESS + 0x3C8)
#define	REG_B0_PHY_RX_BE_EVM_PPRU_RAM_READY                  (B0_PHY_RX_BE_BASE_ADDRESS + 0x3CC)
#define	REG_B0_PHY_RX_BE_EHT_SIG_INFO_VALID                  (B0_PHY_RX_BE_BASE_ADDRESS + 0x3D0)
#define	REG_B0_PHY_RX_BE_LSIG_ERROR_CAUSE                    (B0_PHY_RX_BE_BASE_ADDRESS + 0x3D4)
#define	REG_B0_PHY_RX_BE_MAXIMUM_PACKET_SIZE                 (B0_PHY_RX_BE_BASE_ADDRESS + 0x3D8)
#define	REG_B0_PHY_RX_BE_SIG3_ERROR_CAUSE                    (B0_PHY_RX_BE_BASE_ADDRESS + 0x3DC)
#define	REG_B0_PHY_RX_BE_MASK_SIG3_ERROR_CAUSE               (B0_PHY_RX_BE_BASE_ADDRESS + 0x3E0)
#define	REG_B0_PHY_RX_BE_EHTSIG_ERROR_CAUSE                  (B0_PHY_RX_BE_BASE_ADDRESS + 0x3E4)
#define	REG_B0_PHY_RX_BE_MASK_EHTSIG_ERROR_CAUSE             (B0_PHY_RX_BE_BASE_ADDRESS + 0x3E8)
/*---------------------------------------------------------------------------------
/						Data Type Definition										
/----------------------------------------------------------------------------------*/
/*REG_B0_PHY_RX_BE_PHY_RXBE_REG04 0x10 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 tpPhyMacEventLen : 1; //RxBE Test bus control, reset value: 0x0, access type: RW
		uint32 tpPhyMacDataLen : 1; //RxBE Test bus control, reset value: 0x0, access type: RW
		uint32 tpPhyMacStationIdLen : 1; //RxBE Test bus control, reset value: 0x0, access type: RW
		uint32 tpLdpcCwStatLen : 1; //RxBE Test bus control, reset value: 0x0, access type: RW
		uint32 tpLlrStreamLen : 1; //RxBE Test bus control, reset value: 0x0, access type: RW
		uint32 reserved0 : 26;
		uint32 tpDebugCntEn : 1; //Test Plug counter enable, reset value: 0x0, access type: RW
	} bitFields;
} RegB0PhyRxBePhyRxbeReg04_u;

/*REG_B0_PHY_RX_BE_PHY_RXBE_REG05 0x14 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 tpLlrStreamSel : 2; //RxBE Test bus control, reset value: 0x0, access type: RW
		uint32 reserved0 : 30;
	} bitFields;
} RegB0PhyRxBePhyRxbeReg05_u;

/*REG_B0_PHY_RX_BE_PHY_RXBE_REG07 0x1C */
typedef union
{
	uint32 val;
	struct
	{
		uint32 tpDebugClk2Strb : 4; //Test Bus debug clock per strobe, reset value: 0x6, access type: RW
		uint32 reserved0 : 28;
	} bitFields;
} RegB0PhyRxBePhyRxbeReg07_u;

/*REG_B0_PHY_RX_BE_PHY_RXBE_REG08 0x20 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 tpLowMuxCtrl : 2; //RxBE low test bus control, reset value: 0x0, access type: RW
		uint32 tpMidMuxCtrl : 2; //RxBE mid test bus control, reset value: 0x1, access type: RW
		uint32 tpHighMuxCtrl : 2; //RxBE high test bus control, reset value: 0x2, access type: RW
		uint32 tpFourMuxCtrl : 2; //RxBE high test bus control, reset value: 0x3, access type: RW
		uint32 reserved0 : 24;
	} bitFields;
} RegB0PhyRxBePhyRxbeReg08_u;

/*REG_B0_PHY_RX_BE_PHY_RXBE_REG18 0x60 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 viterbiTbDepth : 6; //Viterbi length, reset value: 0x0, access type: RW
		uint32 reserved0 : 26;
	} bitFields;
} RegB0PhyRxBePhyRxbeReg18_u;

/*REG_B0_PHY_RX_BE_PHY_RXBE_REG19 0x64 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 reportFullMetrics : 1; //Report full metrics, reset value: 0x0, access type: RW
		uint32 waitForGriscMetrics : 1; //Wait for gen risc metrics, reset value: 0x0, access type: RW
		uint32 reserved0 : 2;
		uint32 waitForSnrMetrics : 1; //Wait for snr metrics, reset value: 0x1, access type: RW
		uint32 reserved1 : 27;
	} bitFields;
} RegB0PhyRxBePhyRxbeReg19_u;

/*REG_B0_PHY_RX_BE_PHY_RXBE_REG1E 0x78 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 numBitsInPacket : 25; //Number of bits in the packet, reset value: 0x0, access type: RO
		uint32 reserved0 : 7;
	} bitFields;
} RegB0PhyRxBePhyRxbeReg1E_u;

/*REG_B0_PHY_RX_BE_PHY_RXBE_REG20 0x80 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 reserved0 : 16;
		uint32 macIfMinCycle : 8; //Cycle length, reset value: 0x4, access type: RW
		uint32 reserved1 : 8;
	} bitFields;
} RegB0PhyRxBePhyRxbeReg20_u;

/*REG_B0_PHY_RX_BE_PHY_RXBE_REG21 0x84 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 packetLimit : 19; //Errors per Packet limit, reset value: 0x7ffff, access type: RW
		uint32 reserved0 : 13;
	} bitFields;
} RegB0PhyRxBePhyRxbeReg21_u;

/*REG_B0_PHY_RX_BE_PHY_RXBE_REG22 0x88 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 prbsLoadVal : 32; //PRBS LSFR init value, reset value: 0x162, access type: CONST
	} bitFields;
} RegB0PhyRxBePhyRxbeReg22_u;

/*REG_B0_PHY_RX_BE_PHY_RXBE_REG23 0x8C */
typedef union
{
	uint32 val;
	struct
	{
		uint32 prbsCrcEnable : 1; //Enable PRBS Comparison, reset value: 0x0, access type: RW
		uint32 packetWithCrc : 1; //Enable CRC in packet, reset value: 0x0, access type: RW
		uint32 reserved0 : 30;
	} bitFields;
} RegB0PhyRxBePhyRxbeReg23_u;

/*REG_B0_PHY_RX_BE_PHY_RXBE_REG24 0x90 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 clearCounters : 1; //Clear PRBS Counters, reset value: 0x0, access type: WO
		uint32 reserved0 : 31;
	} bitFields;
} RegB0PhyRxBePhyRxbeReg24_u;

/*REG_B0_PHY_RX_BE_PHY_RXBE_REG25 0x94 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 latchCounters : 1; //Latch PRBS Counters, reset value: 0x0, access type: WO
		uint32 reserved0 : 31;
	} bitFields;
} RegB0PhyRxBePhyRxbeReg25_u;

/*REG_B0_PHY_RX_BE_PHY_RXBE_REG26 0x98 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 prbsType : 32; //PRBS Polynom type, reset value: 0x80000003, access type: CONST
	} bitFields;
} RegB0PhyRxBePhyRxbeReg26_u;

/*REG_B0_PHY_RX_BE_PHY_RXBE_REG28 0xA0 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 sigDecodeCrcLen : 3; //Signal CRC length, reset value: 0x7, access type: CONST
		uint32 reserved0 : 1;
		uint32 sigDecodeCrcType : 8; //Signal CRC type, reset value: 0x60, access type: CONST
		uint32 sigDecodeCrcCorrupt : 1; //Signal CRC corrupt, reset value: 0x0, access type: RW
		uint32 reserved1 : 3;
		uint32 sigDecodeCrcInit : 8; //Signal CRC Init value, reset value: 0xff, access type: CONST
		uint32 reserved2 : 8;
	} bitFields;
} RegB0PhyRxBePhyRxbeReg28_u;

/*REG_B0_PHY_RX_BE_PHY_RXBE_REG34 0xD0 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 prbsErrCntLatched : 32; //PRBS Error count - latched, reset value: 0x0, access type: RO
	} bitFields;
} RegB0PhyRxBePhyRxbeReg34_u;

/*REG_B0_PHY_RX_BE_PHY_RXBE_REG35 0xD4 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 prbsBitCntLatched310 : 32; //PRBS Bit count [31:0] - latched, reset value: 0x0, access type: RO
	} bitFields;
} RegB0PhyRxBePhyRxbeReg35_u;

/*REG_B0_PHY_RX_BE_PHY_RXBE_REG36 0xD8 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 prbsBitCntLatched4732 : 16; //PRBS Bit count [47:32] - latched, reset value: 0x0, access type: RO
		uint32 reserved0 : 16;
	} bitFields;
} RegB0PhyRxBePhyRxbeReg36_u;

/*REG_B0_PHY_RX_BE_PHY_RXBE_REG37 0xDC */
typedef union
{
	uint32 val;
	struct
	{
		uint32 crcPacketCntLatched : 32; //Number of compared packets - latched, reset value: 0x0, access type: RO
	} bitFields;
} RegB0PhyRxBePhyRxbeReg37_u;

/*REG_B0_PHY_RX_BE_PHY_RXBE_REG38 0xE0 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 crcErrPacketCntLatched : 32; //Number of compared errored packets with CRC error - latched, reset value: 0x0, access type: RO
	} bitFields;
} RegB0PhyRxBePhyRxbeReg38_u;

/*REG_B0_PHY_RX_BE_PHY_RXBE_REG39 0xE4 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 prbsErrPacketCntLatched : 32; //Number of compared errored packets with PRBS error - latched, reset value: 0x0, access type: RO
	} bitFields;
} RegB0PhyRxBePhyRxbeReg39_u;

/*REG_B0_PHY_RX_BE_PHY_RXBE_REG3F 0xFC */
typedef union
{
	uint32 val;
	struct
	{
		uint32 swBistStart : 1; //BIST start, reset value: 0x0, access type: RW
		uint32 clearRamMode : 1; //Clear RAM mode in BIST, reset value: 0x0, access type: RW
		uint32 reserved0 : 30;
	} bitFields;
} RegB0PhyRxBePhyRxbeReg3F_u;

/*REG_B0_PHY_RX_BE_PHY_RXBE_REG41 0x104 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 rxbeMaskParityErr : 1; //Mask parity error in signal 1, reset value: 0x0, access type: RW
		uint32 rxbeMaskRateErr : 1; //Mask invalid rate error in signal 1, reset value: 0x0, access type: RW
		uint32 rxbeMaskPSizeErr : 1; //Mask packet size error in signal 1, reset value: 0x0, access type: RW
		uint32 rxbeMaskReservedErr : 1; //Mask reserved bit error in signal 1, reset value: 0x0, access type: RW
		uint32 rxbeMaskCrcErr : 1; //Mask bad CRC error in signal 3, reset value: 0x0, access type: RW
		uint32 rxbeMaskSigbCrcErr : 1; //Mask bad CRC error in vht sigb, reset value: 0x0, access type: RW
		uint32 rxbeMaskSig3ReservedErr : 1; //Mask reserved bit error in signal 2/3, reset value: 0x0, access type: RW
		uint32 rxbeMaskSig3LengthErr : 1; //Mask min length check based on sig3 and sig1, reset value: 0x0, access type: RW
		uint32 rxbeMaskNdpErr : 1; //Mask ndp error, reset value: 0x0, access type: RW
		uint32 rxbeMaskNdpErrAll : 1; //rxbe_mask_p_max_size_err, reset value: 0x1, access type: RW
		uint32 rxbeMaskPMaxSizeErr : 1; //rxbe_mask_ndp_err_all, reset value: 0x0, access type: RW
		uint32 reserved0 : 21;
	} bitFields;
} RegB0PhyRxBePhyRxbeReg41_u;

/*REG_B0_PHY_RX_BE_PHY_RXBE_REG42 0x108 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 minimumPacketSize : 12; //Minimum packet size in bytes, reset value: 0xc, access type: RW
		uint32 reserved0 : 20;
	} bitFields;
} RegB0PhyRxBePhyRxbeReg42_u;

/*REG_B0_PHY_RX_BE_PHY_RXBE_REG4A 0x128 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 prbsErrCnt : 32; //PRBS Error count - real time, reset value: 0x0, access type: RO
	} bitFields;
} RegB0PhyRxBePhyRxbeReg4A_u;

/*REG_B0_PHY_RX_BE_PHY_RXBE_REG4B 0x12C */
typedef union
{
	uint32 val;
	struct
	{
		uint32 prbsBitCnt310 : 32; //PRBS Bit count [31:0] - real time, reset value: 0x0, access type: RO
	} bitFields;
} RegB0PhyRxBePhyRxbeReg4B_u;

/*REG_B0_PHY_RX_BE_PHY_RXBE_REG4C 0x130 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 prbsBitCnt4732 : 16; //PRBS Bit count [47:32] - real time, reset value: 0x0, access type: RO
		uint32 reserved0 : 16;
	} bitFields;
} RegB0PhyRxBePhyRxbeReg4C_u;

/*REG_B0_PHY_RX_BE_PHY_RXBE_REG4D 0x134 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 crcPacketCnt : 32; //Number of compared packets - real time, reset value: 0x0, access type: RO
	} bitFields;
} RegB0PhyRxBePhyRxbeReg4D_u;

/*REG_B0_PHY_RX_BE_PHY_RXBE_REG4E 0x138 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 crcErrPacketCnt : 32; //Number of compared errored packets with CRC error  - real time, reset value: 0x0, access type: RO
	} bitFields;
} RegB0PhyRxBePhyRxbeReg4E_u;

/*REG_B0_PHY_RX_BE_PHY_RXBE_REG4F 0x13C */
typedef union
{
	uint32 val;
	struct
	{
		uint32 prbsErrPacketCnt : 32; //Number of compared errored packets with PRBS error - real time, reset value: 0x0, access type: RO
	} bitFields;
} RegB0PhyRxBePhyRxbeReg4F_u;

/*REG_B0_PHY_RX_BE_PHY_RXBE_REG50 0x140 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 phyMacIfBitCounter : 23; //Phy MAC IF bit counter, reset value: 0x0, access type: RO
		uint32 reserved0 : 9;
	} bitFields;
} RegB0PhyRxBePhyRxbeReg50_u;

/*REG_B0_PHY_RX_BE_PHY_RXBE_REG52 0x148 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 hypRxbeGpr : 32; //RxBE general purpose register, reset value: 0x0, access type: RW
	} bitFields;
} RegB0PhyRxBePhyRxbeReg52_u;

/*REG_B0_PHY_RX_BE_PHY_RXBE_REG55 0x154 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 deintRamRm : 3; //deint_ram_rm, reset value: 0x3, access type: RW
		uint32 reserved0 : 29;
	} bitFields;
} RegB0PhyRxBePhyRxbeReg55_u;

/*REG_B0_PHY_RX_BE_PHY_RXBE_REG56 0x158 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 rcrRamRm : 3; //rcr_ram_rm, reset value: 0x3, access type: RW
		uint32 reserved0 : 29;
	} bitFields;
} RegB0PhyRxBePhyRxbeReg56_u;

/*REG_B0_PHY_RX_BE_PHY_RXBE_REG57 0x15C */
typedef union
{
	uint32 val;
	struct
	{
		uint32 viterbiTbBlockRamRm : 3; //viterbi_tb_block_ram_rm, reset value: 0x3, access type: RW
		uint32 reserved0 : 29;
	} bitFields;
} RegB0PhyRxBePhyRxbeReg57_u;

/*REG_B0_PHY_RX_BE_PHY_RXBE_REG58 0x160 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 userRamRm : 3; //user_ram_rm, reset value: 0x3, access type: RW
		uint32 reserved0 : 29;
	} bitFields;
} RegB0PhyRxBePhyRxbeReg58_u;

/*REG_B0_PHY_RX_BE_PHY_RXBE_REG59 0x164 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 muRamRm : 3; //mu_ram_rm, reset value: 0x3, access type: RW
		uint32 reserved0 : 29;
	} bitFields;
} RegB0PhyRxBePhyRxbeReg59_u;

/*REG_B0_PHY_RX_BE_PHY_RXBE_REG5A 0x168 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 rRam2Rm : 3; //r_ram2_rm, reset value: 0x3, access type: RW
		uint32 reserved0 : 1;
		uint32 obufRamRm : 3; //obuf_ram_rm, reset value: 0x3, access type: RW
		uint32 reserved1 : 1;
		uint32 sigbRamRm : 3; //sigb_ram_rm, reset value: 0x3, access type: RW
		uint32 reserved2 : 1;
		uint32 cwParams96RamRm : 3; //cw_params_96_ram_rm, reset value: 0x3, access type: RW
		uint32 reserved3 : 1;
		uint32 cwParams48RamRm : 3; //cw_params_48_ram_rm, reset value: 0x3, access type: RW
		uint32 burstBufferRm : 3; //burst_buffer, reset value: 0x3, access type: RW
		uint32 reserved4 : 10;
	} bitFields;
} RegB0PhyRxBePhyRxbeReg5A_u;

/*REG_B0_PHY_RX_BE_PHY_RXBE_REG5D 0x174 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 gclkShutdownEn : 14; //gclk shutdown - when '1' clocks will be always deactive, reset value: 0x0, access type: RW
		uint32 reserved0 : 18;
	} bitFields;
} RegB0PhyRxBePhyRxbeReg5D_u;

/*REG_B0_PHY_RX_BE_PHY_RXBE_REG5E 0x178 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 bistScrBypass : 1; //bist_scr_bypass, reset value: 0x0, access type: RW
		uint32 ramTestMode : 1; //ram_test_mode, reset value: 0x0, access type: RW
		uint32 ramTestRnm : 1; //ram_test_rnm, reset value: 0x0, access type: RW
		uint32 memGlobalRm : 2; //mem_global_rm, reset value: 0x0, access type: RW
		uint32 reserved0 : 27;
	} bitFields;
} RegB0PhyRxBePhyRxbeReg5E_u;

/*REG_B0_PHY_RX_BE_PHY_RXBE_REG64 0x190 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 globalRdyLimit : 16; //global_rdy_limit, reset value: 0x1CC0, access type: RW
		uint32 reserved0 : 16;
	} bitFields;
} RegB0PhyRxBePhyRxbeReg64_u;

/*REG_B0_PHY_RX_BE_PHY_RXBE_REG65 0x194 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 enableAirTimeBlock : 1; //enable_air_time_block, reset value: 0x1, access type: RW
		uint32 reserved0 : 31;
	} bitFields;
} RegB0PhyRxBePhyRxbeReg65_u;

/*REG_B0_PHY_RX_BE_PHY_RXBE_REG67 0x19C */
typedef union
{
	uint32 val;
	struct
	{
		uint32 vhtNonAggregate : 1; //vht_non_aggregate, reset value: 0x0, access type: RW
		uint32 reserved0 : 31;
	} bitFields;
} RegB0PhyRxBePhyRxbeReg67_u;

/*REG_B0_PHY_RX_BE_PHY_RXBE_REG68 0x1A0 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 spareGpr0 : 32; //spare_gpr_0, reset value: 0x0, access type: RW
	} bitFields;
} RegB0PhyRxBePhyRxbeReg68_u;

/*REG_B0_PHY_RX_BE_PHY_RXBE_REG69 0x1A4 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 spareGpr1 : 32; //spare_gpr_1, reset value: 0x0, access type: RW
	} bitFields;
} RegB0PhyRxBePhyRxbeReg69_u;

/*REG_B0_PHY_RX_BE_PHY_RXBE_REG6A 0x1A8 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 spareGpr2 : 32; //spare_gpr_2, reset value: 0x0, access type: RW
	} bitFields;
} RegB0PhyRxBePhyRxbeReg6A_u;

/*REG_B0_PHY_RX_BE_PHY_RXBE_REG6B 0x1AC */
typedef union
{
	uint32 val;
	struct
	{
		uint32 spareGpr3 : 32; //spare_gpr_3, reset value: 0x0, access type: RW
	} bitFields;
} RegB0PhyRxBePhyRxbeReg6B_u;

/*REG_B0_PHY_RX_BE_PHY_RXBE_REG6C 0x1B0 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 txGlobalResetMask : 12; //reset rxbe units for tx, reset value: 0xfdf, access type: RW
		uint32 reserved0 : 20;
	} bitFields;
} RegB0PhyRxBePhyRxbeReg6C_u;

/*REG_B0_PHY_RX_BE_PHY_RXBE_REG6D 0x1B4 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 riscAirTimeResult : 17; //risc_air_time_result, reset value: 0x0, access type: RW
		uint32 reserved0 : 15;
	} bitFields;
} RegB0PhyRxBePhyRxbeReg6D_u;

/*REG_B0_PHY_RX_BE_PHY_RXBE_REG6E 0x1B8 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 riscNumSym : 15; //risc_num_sym, reset value: 0x0, access type: RW
		uint32 reserved0 : 17;
	} bitFields;
} RegB0PhyRxBePhyRxbeReg6E_u;

/*REG_B0_PHY_RX_BE_PHY_RXBE_REG6F 0x1BC */
typedef union
{
	uint32 val;
	struct
	{
		uint32 riscPhyRate : 15; //risc_phy_rate, reset value: 0x0, access type: RW
		uint32 reserved0 : 17;
	} bitFields;
} RegB0PhyRxBePhyRxbeReg6F_u;

/*REG_B0_PHY_RX_BE_PHY_RXBE_REG70 0x1C0 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 evmResultSs0 : 8; //evm_result_ss0, reset value: 0x0, access type: RO
		uint32 evmResultSs1 : 8; //evm_result_ss1, reset value: 0x0, access type: RO
		uint32 evmResultSs2 : 8; //evm_result_ss2, reset value: 0x0, access type: RO
		uint32 evmResultSs3 : 8; //evm_result_ss3, reset value: 0x0, access type: RO
	} bitFields;
} RegB0PhyRxBePhyRxbeReg70_u;

/*REG_B0_PHY_RX_BE_PHY_RXBE_REG71 0x1C4 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 vhtSigA1 : 24; //vht_sig_a1, reset value: 0x0, access type: RO
		uint32 reserved0 : 8;
	} bitFields;
} RegB0PhyRxBePhyRxbeReg71_u;

/*REG_B0_PHY_RX_BE_PHY_RXBE_REG72 0x1C8 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 vhtSigA2 : 24; //vht_sig_a2, reset value: 0x0, access type: RO
		uint32 reserved0 : 8;
	} bitFields;
} RegB0PhyRxBePhyRxbeReg72_u;

/*REG_B0_PHY_RX_BE_PHY_RXBE_REG73 0x1CC */
typedef union
{
	uint32 val;
	struct
	{
		uint32 vhtSigB : 24; //vht_sig_b, reset value: 0x0, access type: RO
		uint32 reserved0 : 8;
	} bitFields;
} RegB0PhyRxBePhyRxbeReg73_u;

/*REG_B0_PHY_RX_BE_PHY_RXBE_REG74 0x1D0 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 htSig2 : 24; //ht_sig2, reset value: 0x0, access type: RO
		uint32 reserved0 : 8;
	} bitFields;
} RegB0PhyRxBePhyRxbeReg74_u;

/*REG_B0_PHY_RX_BE_PHY_RXBE_REG75 0x1D4 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 htSig3 : 24; //ht_sig3, reset value: 0x0, access type: RO
		uint32 reserved0 : 8;
	} bitFields;
} RegB0PhyRxBePhyRxbeReg75_u;

/*REG_B0_PHY_RX_BE_PHY_RXBE_REG76 0x1D8 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 lsig : 24; //lsig, reset value: 0x0, access type: RO
		uint32 reserved0 : 8;
	} bitFields;
} RegB0PhyRxBePhyRxbeReg76_u;

/*REG_B0_PHY_RX_BE_PHY_RXBE_REG77 0x1DC */
typedef union
{
	uint32 val;
	struct
	{
		uint32 bfHeaderDelayLimit : 8; //bf_header_delay_limit, reset value: 0xf0, access type: RW
		uint32 reserved0 : 24;
	} bitFields;
} RegB0PhyRxBePhyRxbeReg77_u;

/*REG_B0_PHY_RX_BE_PHY_RXBE_REG78 0x1E0 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 pmColour0 : 6; //pm_colour_0, reset value: 0x0, access type: RW
		uint32 reserved0 : 2;
		uint32 pmColour1 : 6; //pm_colour_1, reset value: 0x0, access type: RW
		uint32 reserved1 : 2;
		uint32 pmColour2 : 6; //pm_colour_2, reset value: 0x0, access type: RW
		uint32 reserved2 : 2;
		uint32 pmColour3 : 6; //pm_colour_3, reset value: 0x0, access type: RW
		uint32 reserved3 : 2;
	} bitFields;
} RegB0PhyRxBePhyRxbeReg78_u;

/*REG_B0_PHY_RX_BE_PHY_RXBE_REG79 0x1E4 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 pmColour4 : 6; //pm_colour_4, reset value: 0x0, access type: RW
		uint32 reserved0 : 2;
		uint32 pmColour5 : 6; //pm_colour_5, reset value: 0x0, access type: RW
		uint32 reserved1 : 2;
		uint32 pmColour6 : 6; //pm_colour_6, reset value: 0x0, access type: RW
		uint32 reserved2 : 2;
		uint32 pmColour7 : 6; //pm_colour_7, reset value: 0x0, access type: RW
		uint32 reserved3 : 2;
	} bitFields;
} RegB0PhyRxBePhyRxbeReg79_u;

/*REG_B0_PHY_RX_BE_PHY_RXBE_REG80 0x1E8 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 pmColour8 : 6; //pm_colour_8, reset value: 0x0, access type: RW
		uint32 reserved0 : 2;
		uint32 pmColour9 : 6; //pm_colour_9, reset value: 0x0, access type: RW
		uint32 reserved1 : 2;
		uint32 pmColour10 : 6; //pm_colour_10, reset value: 0x0, access type: RW
		uint32 reserved2 : 2;
		uint32 pmColour11 : 6; //pm_colour_11, reset value: 0x0, access type: RW
		uint32 reserved3 : 2;
	} bitFields;
} RegB0PhyRxBePhyRxbeReg80_u;

/*REG_B0_PHY_RX_BE_PHY_RXBE_REG81 0x1EC */
typedef union
{
	uint32 val;
	struct
	{
		uint32 pmColour12 : 6; //pm_colour_12, reset value: 0x0, access type: RW
		uint32 reserved0 : 2;
		uint32 pmColour13 : 6; //pm_colour_13, reset value: 0x0, access type: RW
		uint32 reserved1 : 2;
		uint32 pmColour14 : 6; //pm_colour_14, reset value: 0x0, access type: RW
		uint32 reserved2 : 2;
		uint32 pmColour15 : 6; //pm_colour_15, reset value: 0x0, access type: RW
		uint32 reserved3 : 2;
	} bitFields;
} RegB0PhyRxBePhyRxbeReg81_u;

/*REG_B0_PHY_RX_BE_PHY_RXBE_REG82 0x1F0 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 pmColour16 : 6; //pm_colour_16, reset value: 0x0, access type: RW
		uint32 reserved0 : 2;
		uint32 pmColour17 : 6; //pm_colour_17, reset value: 0x0, access type: RW
		uint32 reserved1 : 2;
		uint32 pmColour18 : 6; //pm_colour_18, reset value: 0x0, access type: RW
		uint32 reserved2 : 2;
		uint32 pmColour19 : 6; //pm_colour_19, reset value: 0x0, access type: RW
		uint32 reserved3 : 2;
	} bitFields;
} RegB0PhyRxBePhyRxbeReg82_u;

/*REG_B0_PHY_RX_BE_PHY_RXBE_REG83 0x1F4 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 pmColour20 : 6; //pm_colour_20, reset value: 0x0, access type: RW
		uint32 reserved0 : 2;
		uint32 pmColour21 : 6; //pm_colour_21, reset value: 0x0, access type: RW
		uint32 reserved1 : 2;
		uint32 pmColour22 : 6; //pm_colour_22, reset value: 0x0, access type: RW
		uint32 reserved2 : 2;
		uint32 pmColour23 : 6; //pm_colour_23, reset value: 0x0, access type: RW
		uint32 reserved3 : 2;
	} bitFields;
} RegB0PhyRxBePhyRxbeReg83_u;

/*REG_B0_PHY_RX_BE_PHY_RXBE_REG84 0x1F8 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 pmColour24 : 6; //pm_colour_24, reset value: 0x0, access type: RW
		uint32 reserved0 : 2;
		uint32 pmColour25 : 6; //pm_colour_25, reset value: 0x0, access type: RW
		uint32 reserved1 : 2;
		uint32 pmColour26 : 6; //pm_colour_26, reset value: 0x0, access type: RW
		uint32 reserved2 : 2;
		uint32 pmColour27 : 6; //pm_colour_27, reset value: 0x0, access type: RW
		uint32 reserved3 : 2;
	} bitFields;
} RegB0PhyRxBePhyRxbeReg84_u;

/*REG_B0_PHY_RX_BE_PHY_RXBE_REG85 0x1FC */
typedef union
{
	uint32 val;
	struct
	{
		uint32 pmColour28 : 6; //pm_colour_28, reset value: 0x0, access type: RW
		uint32 reserved0 : 2;
		uint32 pmColour29 : 6; //pm_colour_29, reset value: 0x0, access type: RW
		uint32 reserved1 : 2;
		uint32 pmColour30 : 6; //pm_colour_30, reset value: 0x0, access type: RW
		uint32 reserved2 : 2;
		uint32 pmColour31 : 6; //pm_colour_31, reset value: 0x0, access type: RW
		uint32 reserved3 : 2;
	} bitFields;
} RegB0PhyRxBePhyRxbeReg85_u;

/*REG_B0_PHY_RX_BE_PHY_RXBE_REG86 0x200 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 pmColour32 : 6; //pm_colour_32, reset value: 0x0, access type: RW
		uint32 reserved0 : 2;
		uint32 pmColour33 : 6; //pm_colour_33, reset value: 0x0, access type: RW
		uint32 reserved1 : 2;
		uint32 pmColour34 : 6; //pm_colour_34, reset value: 0x0, access type: RW
		uint32 reserved2 : 2;
		uint32 pmColour35 : 6; //pm_colour_35, reset value: 0x0, access type: RW
		uint32 reserved3 : 2;
	} bitFields;
} RegB0PhyRxBePhyRxbeReg86_u;

/*REG_B0_PHY_RX_BE_PHY_RXBE_REG87 0x204 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 pmColour36 : 6; //pm_colour_36, reset value: 0x0, access type: RW
		uint32 reserved0 : 2;
		uint32 pmColour37 : 6; //pm_colour_37, reset value: 0x0, access type: RW
		uint32 reserved1 : 2;
		uint32 pmColour38 : 6; //pm_colour_38, reset value: 0x0, access type: RW
		uint32 reserved2 : 2;
		uint32 pmColour39 : 6; //pm_colour_39, reset value: 0x0, access type: RW
		uint32 reserved3 : 2;
	} bitFields;
} RegB0PhyRxBePhyRxbeReg87_u;

/*REG_B0_PHY_RX_BE_PHY_RXBE_REG88 0x208 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 pmColour40 : 6; //pm_colour_40, reset value: 0x0, access type: RW
		uint32 reserved0 : 2;
		uint32 pmColour41 : 6; //pm_colour_41, reset value: 0x0, access type: RW
		uint32 reserved1 : 2;
		uint32 pmColour42 : 6; //pm_colour_42, reset value: 0x0, access type: RW
		uint32 reserved2 : 2;
		uint32 pmColour43 : 6; //pm_colour_43, reset value: 0x0, access type: RW
		uint32 reserved3 : 2;
	} bitFields;
} RegB0PhyRxBePhyRxbeReg88_u;

/*REG_B0_PHY_RX_BE_PHY_RXBE_REG89 0x20C */
typedef union
{
	uint32 val;
	struct
	{
		uint32 pmColour44 : 6; //pm_colour_44, reset value: 0x0, access type: RW
		uint32 reserved0 : 2;
		uint32 pmColour45 : 6; //pm_colour_45, reset value: 0x0, access type: RW
		uint32 reserved1 : 2;
		uint32 pmColour46 : 6; //pm_colour_46, reset value: 0x0, access type: RW
		uint32 reserved2 : 2;
		uint32 pmColour47 : 6; //pm_colour_47, reset value: 0x0, access type: RW
		uint32 reserved3 : 2;
	} bitFields;
} RegB0PhyRxBePhyRxbeReg89_u;

/*REG_B0_PHY_RX_BE_PHY_RXBE_REG90 0x210 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 pmColour48 : 6; //pm_colour_48, reset value: 0x0, access type: RW
		uint32 reserved0 : 2;
		uint32 pmColour49 : 6; //pm_colour_49, reset value: 0x0, access type: RW
		uint32 reserved1 : 2;
		uint32 pmColour50 : 6; //pm_colour_50, reset value: 0x0, access type: RW
		uint32 reserved2 : 2;
		uint32 pmColour51 : 6; //pm_colour_51, reset value: 0x0, access type: RW
		uint32 reserved3 : 2;
	} bitFields;
} RegB0PhyRxBePhyRxbeReg90_u;

/*REG_B0_PHY_RX_BE_PHY_RXBE_REG91 0x214 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 pmColour52 : 6; //pm_colour_52, reset value: 0x0, access type: RW
		uint32 reserved0 : 2;
		uint32 pmColour53 : 6; //pm_colour_53, reset value: 0x0, access type: RW
		uint32 reserved1 : 2;
		uint32 pmColour54 : 6; //pm_colour_54, reset value: 0x0, access type: RW
		uint32 reserved2 : 2;
		uint32 pmColour55 : 6; //pm_colour_55, reset value: 0x0, access type: RW
		uint32 reserved3 : 2;
	} bitFields;
} RegB0PhyRxBePhyRxbeReg91_u;

/*REG_B0_PHY_RX_BE_PHY_RXBE_REG92 0x218 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 pmColour56 : 6; //pm_colour_56, reset value: 0x0, access type: RW
		uint32 reserved0 : 2;
		uint32 pmColour57 : 6; //pm_colour_57, reset value: 0x0, access type: RW
		uint32 reserved1 : 2;
		uint32 pmColour58 : 6; //pm_colour_58, reset value: 0x0, access type: RW
		uint32 reserved2 : 2;
		uint32 pmColour59 : 6; //pm_colour_59, reset value: 0x0, access type: RW
		uint32 reserved3 : 2;
	} bitFields;
} RegB0PhyRxBePhyRxbeReg92_u;

/*REG_B0_PHY_RX_BE_PHY_RXBE_REG93 0x21C */
typedef union
{
	uint32 val;
	struct
	{
		uint32 pmColour60 : 6; //pm_colour_60, reset value: 0x0, access type: RW
		uint32 reserved0 : 2;
		uint32 pmColour61 : 6; //pm_colour_61, reset value: 0x0, access type: RW
		uint32 reserved1 : 2;
		uint32 pmColour62 : 6; //pm_colour_62, reset value: 0x0, access type: RW
		uint32 reserved2 : 2;
		uint32 pmColour63 : 6; //pm_colour_63, reset value: 0x0, access type: RW
		uint32 reserved3 : 2;
	} bitFields;
} RegB0PhyRxBePhyRxbeReg93_u;

/*REG_B0_PHY_RX_BE_PHY_RXBE_REG94 0x220 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 pmAirTimeInterval : 10; //pm_air_time_interval, reset value: 0x14a, access type: RW
		uint32 reserved0 : 22;
	} bitFields;
} RegB0PhyRxBePhyRxbeReg94_u;

/*REG_B0_PHY_RX_BE_PHY_RXBE_REG95 0x224 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 pmCurrentUser : 6; //pm_current_user, reset value: 0x0, access type: RW
		uint32 reserved0 : 26;
	} bitFields;
} RegB0PhyRxBePhyRxbeReg95_u;

/*REG_B0_PHY_RX_BE_PHY_RXBE_REG96 0x228 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 ldpcTotalLastSym : 8; //ldpc_total_last_sym, reset value: 0x0, access type: RO
		uint32 reserved0 : 24;
	} bitFields;
} RegB0PhyRxBePhyRxbeReg96_u;

/*REG_B0_PHY_RX_BE_PHY_RXBE_REG97 0x22C */
typedef union
{
	uint32 val;
	struct
	{
		uint32 ldpcTotalCw : 16; //ldpc_total_cw, reset value: 0x0, access type: RO
		uint32 reserved0 : 16;
	} bitFields;
} RegB0PhyRxBePhyRxbeReg97_u;

/*REG_B0_PHY_RX_BE_PHY_RXBE_REG98 0x230 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 heSigA1 : 26; //he_sig_a1, reset value: 0x0, access type: RO
		uint32 reserved0 : 6;
	} bitFields;
} RegB0PhyRxBePhyRxbeReg98_u;

/*REG_B0_PHY_RX_BE_PHY_RXBE_REG99 0x234 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 heSigA2 : 26; //he_sig_a2, reset value: 0x0, access type: RO
		uint32 reserved0 : 6;
	} bitFields;
} RegB0PhyRxBePhyRxbeReg99_u;

/*REG_B0_PHY_RX_BE_PHY_RXBE_REG9A 0x238 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 psduLen : 23; //psdu_len, reset value: 0x0, access type: RO
		uint32 reserved0 : 9;
	} bitFields;
} RegB0PhyRxBePhyRxbeReg9A_u;

/*REG_B0_PHY_RX_BE_PHY_RXBE_REG9B 0x23C */
typedef union
{
	uint32 val;
	struct
	{
		uint32 userConfig : 12; //user_config, reset value: 0x0, access type: RO
		uint32 reserved0 : 20;
	} bitFields;
} RegB0PhyRxBePhyRxbeReg9B_u;

/*REG_B0_PHY_RX_BE_PHY_RXBE_REG9C 0x240 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 rxbeSchPs : 5; //rxbe_sch_ps, reset value: 0x0, access type: RO
		uint32 reserved0 : 27;
	} bitFields;
} RegB0PhyRxBePhyRxbeReg9C_u;

/*REG_B0_PHY_RX_BE_PHY_RXBE_REGA1 0x254 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 ldpcAlphaIndex : 2; //ldpc_alpha_index, reset value: 0x0, access type: RW
		uint32 reserved0 : 30;
	} bitFields;
} RegB0PhyRxBePhyRxbeRega1_u;

/*REG_B0_PHY_RX_BE_PHY_RXBE_REGA2 0x258 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 ldpcQuantizeCycles : 1; //ldpc_quantize_cycles, reset value: 0x0, access type: RW
		uint32 reserved0 : 31;
	} bitFields;
} RegB0PhyRxBePhyRxbeRega2_u;

/*REG_B0_PHY_RX_BE_LDPC_CALC_VALID 0x25C */
typedef union
{
	uint32 val;
	struct
	{
		uint32 ldpcCalcValid : 1; //ldpc cycles calculator done, reset value: 0x0, access type: RO
		uint32 reserved0 : 31;
	} bitFields;
} RegB0PhyRxBeLdpcCalcValid_u;

/*REG_B0_PHY_RX_BE_LDPC_VITERBI_USER_ACTIVE 0x260 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 ldpcViterbiUserActive : 6; //number of active users viterbi+ldpc, reset value: 0x0, access type: RO
		uint32 reserved0 : 26;
	} bitFields;
} RegB0PhyRxBeLdpcViterbiUserActive_u;

/*REG_B0_PHY_RX_BE_LDPC_USER_ACTIVE 0x264 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 ldpcUserActive : 6; //number of active users ldpc only, reset value: 0x0, access type: RO
		uint32 reserved0 : 26;
	} bitFields;
} RegB0PhyRxBeLdpcUserActive_u;

/*REG_B0_PHY_RX_BE_LDPC_MAX_N_CW 0x268 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 ldpcMaxNCw : 16; //maximal value of ldpc_n_cw from all ldpc users, reset value: 0x0, access type: RO
		uint32 reserved0 : 16;
	} bitFields;
} RegB0PhyRxBeLdpcMaxNCw_u;

/*REG_B0_PHY_RX_BE_LDPC_CYCLES_PER_CW 0x26C */
typedef union
{
	uint32 val;
	struct
	{
		uint32 ldpcCyclesPerCw : 12; //calculated cycles per cw, reset value: 0x480, access type: RO
		uint32 reserved0 : 20;
	} bitFields;
} RegB0PhyRxBeLdpcCyclesPerCw_u;

/*REG_B0_PHY_RX_BE_LDPC_MAX_CHECK_CONV 0x270 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 ldpcMaxChecksRo : 16; //ldpc_max_checks_ro, reset value: 0x0, access type: RO
		uint32 ldpcNoConvergence : 1; //ldpc_no_convergence, reset value: 0x0, access type: RO
		uint32 reserved0 : 15;
	} bitFields;
} RegB0PhyRxBeLdpcMaxCheckConv_u;

/*REG_B0_PHY_RX_BE_BUS_PAC_PHY_RX_CRC_CHECK_0 0x274 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 busPacPhyRxCrcCheck0 : 32; //bus_pac_phy_rx_crc_check_0, reset value: 0x0, access type: RO
	} bitFields;
} RegB0PhyRxBeBusPacPhyRxCrcCheck0_u;

/*REG_B0_PHY_RX_BE_BUS_PAC_PHY_RX_CRC_CHECK_1 0x278 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 busPacPhyRxCrcCheck1 : 4; //bus_pac_phy_rx_crc_check_1, reset value: 0x0, access type: RO
		uint32 reserved0 : 28;
	} bitFields;
} RegB0PhyRxBeBusPacPhyRxCrcCheck1_u;

/*REG_B0_PHY_RX_BE_RCR_ACTIVE_USERS_0 0x27C */
typedef union
{
	uint32 val;
	struct
	{
		uint32 rcrActiveUsers0 : 32; //rcr_active_users_0, reset value: 0x0, access type: RO
	} bitFields;
} RegB0PhyRxBeRcrActiveUsers0_u;

/*REG_B0_PHY_RX_BE_RCR_ACTIVE_USERS_1 0x280 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 rcrActiveUsers1 : 4; //rcr_active_users_1, reset value: 0x0, access type: RO
		uint32 reserved0 : 28;
	} bitFields;
} RegB0PhyRxBeRcrActiveUsers1_u;

/*REG_B0_PHY_RX_BE_SIGB_STID_0 0x284 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 sigbStid0 : 11; //sigb_stid_0, reset value: 0x0, access type: RW
		uint32 sigbStid0Enable : 1; //sigb_stid_0_enable, reset value: 0x0, access type: RW
		uint32 reserved0 : 4;
		uint32 sigbStid1 : 11; //sigb_stid_1, reset value: 0x0, access type: RW
		uint32 sigbStid1Enable : 1; //sigb_stid_1_enable, reset value: 0x0, access type: RW
		uint32 reserved1 : 4;
	} bitFields;
} RegB0PhyRxBeSigbStid0_u;

/*REG_B0_PHY_RX_BE_SIGB_STID_1 0x288 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 sigbStid2 : 11; //sigb_stid_2, reset value: 0x0, access type: RW
		uint32 sigbStid2Enable : 1; //sigb_stid_2_enable, reset value: 0x0, access type: RW
		uint32 reserved0 : 4;
		uint32 sigbStid3 : 11; //sigb_stid_3, reset value: 0x0, access type: RW
		uint32 sigbStid3Enable : 1; //sigb_stid_3_enable, reset value: 0x0, access type: RW
		uint32 reserved1 : 4;
	} bitFields;
} RegB0PhyRxBeSigbStid1_u;

/*REG_B0_PHY_RX_BE_SIGB_STID_2 0x28C */
typedef union
{
	uint32 val;
	struct
	{
		uint32 sigbStid4 : 11; //sigb_stid_4, reset value: 0x0, access type: RW
		uint32 sigbStid4Enable : 1; //sigb_stid_4_enable, reset value: 0x0, access type: RW
		uint32 reserved0 : 4;
		uint32 sigbStid5 : 11; //sigb_stid_5, reset value: 0x0, access type: RW
		uint32 sigbStid5Enable : 1; //sigb_stid_5_enable, reset value: 0x0, access type: RW
		uint32 reserved1 : 4;
	} bitFields;
} RegB0PhyRxBeSigbStid2_u;

/*REG_B0_PHY_RX_BE_SIGB_STID_3 0x290 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 sigbStid6 : 11; //sigb_stid_6, reset value: 0x0, access type: RW
		uint32 sigbStid6Enable : 1; //sigb_stid_6_enable, reset value: 0x0, access type: RW
		uint32 reserved0 : 4;
		uint32 sigbStid7 : 11; //sigb_stid_7, reset value: 0x0, access type: RW
		uint32 sigbStid7Enable : 1; //sigb_stid_7_enable, reset value: 0x0, access type: RW
		uint32 reserved1 : 4;
	} bitFields;
} RegB0PhyRxBeSigbStid3_u;

/*REG_B0_PHY_RX_BE_SIGB_STID_4 0x294 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 sigbStid8 : 11; //sigb_stid_8, reset value: 0x0, access type: RW
		uint32 sigbStid8Enable : 1; //sigb_stid_8_enable, reset value: 0x0, access type: RW
		uint32 reserved0 : 4;
		uint32 sigbStid9 : 11; //sigb_stid_9, reset value: 0x0, access type: RW
		uint32 sigbStid9Enable : 1; //sigb_stid_9_enable, reset value: 0x0, access type: RW
		uint32 reserved1 : 4;
	} bitFields;
} RegB0PhyRxBeSigbStid4_u;

/*REG_B0_PHY_RX_BE_SIGB_STID_5 0x298 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 sigbStid10 : 11; //sigb_stid_10, reset value: 0x0, access type: RW
		uint32 sigbStid10Enable : 1; //sigb_stid_10_enable, reset value: 0x0, access type: RW
		uint32 reserved0 : 4;
		uint32 sigbStid11 : 11; //sigb_stid_11, reset value: 0x0, access type: RW
		uint32 sigbStid11Enable : 1; //sigb_stid_11_enable, reset value: 0x0, access type: RW
		uint32 reserved1 : 4;
	} bitFields;
} RegB0PhyRxBeSigbStid5_u;

/*REG_B0_PHY_RX_BE_SIGB_STID_6 0x29C */
typedef union
{
	uint32 val;
	struct
	{
		uint32 sigbStid12 : 11; //sigb_stid_12, reset value: 0x0, access type: RW
		uint32 sigbStid12Enable : 1; //sigb_stid_12_enable, reset value: 0x0, access type: RW
		uint32 reserved0 : 4;
		uint32 sigbStid13 : 11; //sigb_stid_13, reset value: 0x0, access type: RW
		uint32 sigbStid13Enable : 1; //sigb_stid_13_enable, reset value: 0x0, access type: RW
		uint32 reserved1 : 4;
	} bitFields;
} RegB0PhyRxBeSigbStid6_u;

/*REG_B0_PHY_RX_BE_SIGB_STID_7 0x2A0 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 sigbStid14 : 11; //sigb_stid_14, reset value: 0x0, access type: RW
		uint32 sigbStid14Enable : 1; //sigb_stid_14_enable, reset value: 0x0, access type: RW
		uint32 reserved0 : 4;
		uint32 sigbStid15 : 11; //sigb_stid_15, reset value: 0x0, access type: RW
		uint32 sigbStid15Enable : 1; //sigb_stid_15_enable, reset value: 0x0, access type: RW
		uint32 reserved1 : 4;
	} bitFields;
} RegB0PhyRxBeSigbStid7_u;

/*REG_B0_PHY_RX_BE_SIGB_STID_8 0x2A4 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 sigbStid16 : 11; //sigb_stid_16, reset value: 0x0, access type: RW
		uint32 sigbStid16Enable : 1; //sigb_stid_16_enable, reset value: 0x0, access type: RW
		uint32 reserved0 : 4;
		uint32 sigbStid17 : 11; //sigb_stid_17, reset value: 0x0, access type: RW
		uint32 sigbStid17Enable : 1; //sigb_stid_17_enable, reset value: 0x0, access type: RW
		uint32 reserved1 : 4;
	} bitFields;
} RegB0PhyRxBeSigbStid8_u;

/*REG_B0_PHY_RX_BE_SIGB_STID_9 0x2A8 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 sigbStid18 : 11; //sigb_stid_18, reset value: 0x0, access type: RW
		uint32 sigbStid18Enable : 1; //sigb_stid_18_enable, reset value: 0x0, access type: RW
		uint32 reserved0 : 4;
		uint32 sigbStid19 : 11; //sigb_stid_19, reset value: 0x0, access type: RW
		uint32 sigbStid19Enable : 1; //sigb_stid_19_enable, reset value: 0x0, access type: RW
		uint32 reserved1 : 4;
	} bitFields;
} RegB0PhyRxBeSigbStid9_u;

/*REG_B0_PHY_RX_BE_SIGB_STID_10 0x2AC */
typedef union
{
	uint32 val;
	struct
	{
		uint32 sigbStid20 : 11; //sigb_stid_20, reset value: 0x0, access type: RW
		uint32 sigbStid20Enable : 1; //sigb_stid_20_enable, reset value: 0x0, access type: RW
		uint32 reserved0 : 4;
		uint32 sigbStid21 : 11; //sigb_stid_21, reset value: 0x0, access type: RW
		uint32 sigbStid21Enable : 1; //sigb_stid_21_enable, reset value: 0x0, access type: RW
		uint32 reserved1 : 4;
	} bitFields;
} RegB0PhyRxBeSigbStid10_u;

/*REG_B0_PHY_RX_BE_SIGB_STID_11 0x2B0 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 sigbStid22 : 11; //sigb_stid_22, reset value: 0x0, access type: RW
		uint32 sigbStid22Enable : 1; //sigb_stid_22_enable, reset value: 0x0, access type: RW
		uint32 reserved0 : 4;
		uint32 sigbStid23 : 11; //sigb_stid_23, reset value: 0x0, access type: RW
		uint32 sigbStid23Enable : 1; //sigb_stid_23_enable, reset value: 0x0, access type: RW
		uint32 reserved1 : 4;
	} bitFields;
} RegB0PhyRxBeSigbStid11_u;

/*REG_B0_PHY_RX_BE_SIGB_STID_12 0x2B4 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 sigbStid24 : 11; //sigb_stid_24, reset value: 0x0, access type: RW
		uint32 sigbStid24Enable : 1; //sigb_stid_24_enable, reset value: 0x0, access type: RW
		uint32 reserved0 : 4;
		uint32 sigbStid25 : 11; //sigb_stid_25, reset value: 0x0, access type: RW
		uint32 sigbStid25Enable : 1; //sigb_stid_25_enable, reset value: 0x0, access type: RW
		uint32 reserved1 : 4;
	} bitFields;
} RegB0PhyRxBeSigbStid12_u;

/*REG_B0_PHY_RX_BE_SIGB_STID_13 0x2B8 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 sigbStid26 : 11; //sigb_stid_26, reset value: 0x0, access type: RW
		uint32 sigbStid26Enable : 1; //sigb_stid_26_enable, reset value: 0x0, access type: RW
		uint32 reserved0 : 4;
		uint32 sigbStid27 : 11; //sigb_stid_27, reset value: 0x0, access type: RW
		uint32 sigbStid27Enable : 1; //sigb_stid_27_enable, reset value: 0x0, access type: RW
		uint32 reserved1 : 4;
	} bitFields;
} RegB0PhyRxBeSigbStid13_u;

/*REG_B0_PHY_RX_BE_SIGB_STID_14 0x2BC */
typedef union
{
	uint32 val;
	struct
	{
		uint32 sigbStid28 : 11; //sigb_stid_28, reset value: 0x0, access type: RW
		uint32 sigbStid28Enable : 1; //sigb_stid_28_enable, reset value: 0x0, access type: RW
		uint32 reserved0 : 4;
		uint32 sigbStid29 : 11; //sigb_stid_29, reset value: 0x0, access type: RW
		uint32 sigbStid29Enable : 1; //sigb_stid_29_enable, reset value: 0x0, access type: RW
		uint32 reserved1 : 4;
	} bitFields;
} RegB0PhyRxBeSigbStid14_u;

/*REG_B0_PHY_RX_BE_SIGB_STID_15 0x2D0 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 sigbStid30 : 11; //sigb_stid_30, reset value: 0x0, access type: RW
		uint32 sigbStid30Enable : 1; //sigb_stid_30_enable, reset value: 0x0, access type: RW
		uint32 reserved0 : 4;
		uint32 sigbStid31 : 11; //sigb_stid_31, reset value: 0x0, access type: RW
		uint32 sigbStid31Enable : 1; //sigb_stid_31_enable, reset value: 0x0, access type: RW
		uint32 reserved1 : 4;
	} bitFields;
} RegB0PhyRxBeSigbStid15_u;

/*REG_B0_PHY_RX_BE_LDPC_CYCLES_LAST_SYMBOL 0x2D4 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 ldpcCyclesLastSymbol : 12; //ldpc_cycles_last_symbol, reset value: 0x0, access type: RO
		uint32 reserved0 : 20;
	} bitFields;
} RegB0PhyRxBeLdpcCyclesLastSymbol_u;

/*REG_B0_PHY_RX_BE_LDPC_CYCLES_STEADY_STATE 0x2D8 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 ldpcCyclesSteadyState : 12; //ldpc_cycles_steady_state, reset value: 0x0, access type: RO
		uint32 reserved0 : 20;
	} bitFields;
} RegB0PhyRxBeLdpcCyclesSteadyState_u;

/*REG_B0_PHY_RX_BE_LDPC_CYCLES_FIRST_CW 0x2DC */
typedef union
{
	uint32 val;
	struct
	{
		uint32 ldpcCyclesFirstCw : 12; //ldpc_cycles_first_cw, reset value: 0x0, access type: RO
		uint32 reserved0 : 20;
	} bitFields;
} RegB0PhyRxBeLdpcCyclesFirstCw_u;

/*REG_B0_PHY_RX_BE_LDPC_LAST_SYMBOL_CW_INDEX 0x2E0 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 ldpcLastSymbolCwIndex : 16; //ldpc_last_symbol_cw_index, reset value: 0x0, access type: RO
		uint32 reserved0 : 16;
	} bitFields;
} RegB0PhyRxBeLdpcLastSymbolCwIndex_u;

/*REG_B0_PHY_RX_BE_LDPC_CORE_GCLK_CHICKEN_BIT 0x2E4 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 ldpcCoreGclkChickenBit : 1; //bypass internal clock gating of ldpc core clock, reset value: 0x0, access type: RW
		uint32 reserved0 : 31;
	} bitFields;
} RegB0PhyRxBeLdpcCoreGclkChickenBit_u;

/*REG_B0_PHY_RX_BE_RXBE_FSM_FORCE 0x2F0 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 pmForceLsigErr : 1; //pm_force_lsig_err, reset value: 0x0, access type: RW
		uint32 pmForceLplusrErPass : 1; //pm_force_lplusr_er_pass , reset value: 0x0, access type: RW
		uint32 pmForceLsigNotEqualRlsig : 1; //pm_force_lsog_not_equal_rlsig, reset value: 0x0, access type: RW
		uint32 pmForceLsigMcsEvmFailCond : 1; //pm_force_lsig_mcs_evm_fail_cond , reset value: 0x0, access type: RW
		uint32 reserved0 : 28;
	} bitFields;
} RegB0PhyRxBeRxbeFsmForce_u;

/*REG_B0_PHY_RX_BE_PM_LEG_MCS_TH 0x2F8 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 pmLegMcsTh : 4; //pm_leg_mcs_th, reset value: 0x0, access type: RW
		uint32 reserved0 : 28;
	} bitFields;
} RegB0PhyRxBePmLegMcsTh_u;

/*REG_B0_PHY_RX_BE_PM_LEG_EVM_TH 0x2FC */
typedef union
{
	uint32 val;
	struct
	{
		uint32 pmLegEvmTh : 8; //pm_leg_evm_th, reset value: 0x0, access type: RW
		uint32 reserved0 : 24;
	} bitFields;
} RegB0PhyRxBePmLegEvmTh_u;

/*REG_B0_PHY_RX_BE_LEG_BELOW_EVM_TH_ERR 0x300 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 legBelowEvmThErr : 1; //leg_below_evm_th_err, reset value: 0x0, access type: RO
		uint32 reserved0 : 31;
	} bitFields;
} RegB0PhyRxBeLegBelowEvmThErr_u;

/*REG_B0_PHY_RX_BE_PM_MASK_LPLUSR 0x304 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 pmMaskLplusrParityErr : 1; //pm_mask_ lplusr _parity_err, reset value: 0x0, access type: RW
		uint32 pmMaskLplusrRateErr : 1; //pm_mask_ lplusr _rate_err, reset value: 0x0, access type: RW
		uint32 pmMaskLplusrPSizeErr : 1; //pm_mask_ lplusr _p_size_err, reset value: 0x0, access type: RW
		uint32 pmMaskLplusrReserveErr : 1; //pm_mask_ lplusr _reserve_err, reset value: 0x0, access type: RW
		uint32 reserved0 : 28;
	} bitFields;
} RegB0PhyRxBePmMaskLplusr_u;

/*REG_B0_PHY_RX_BE_PM_R_PLUS_L_MINIMUM_PACKET_SIZE 0x308 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 pmRPlusLMinimumPacketSize : 12; //pm_r_plus_l_minimum_packet_size, reset value: 0x13, access type: RW
		uint32 reserved0 : 20;
	} bitFields;
} RegB0PhyRxBePmRPlusLMinimumPacketSize_u;

/*REG_B0_PHY_RX_BE_DESCRAMBLER_SEED 0x30C */
typedef union
{
	uint32 val;
	struct
	{
		uint32 descramblerSeed : 11; //descrambler_seed, reset value: 0x0, access type: RO
		uint32 reserved0 : 21;
	} bitFields;
} RegB0PhyRxBeDescramblerSeed_u;

/*REG_B0_PHY_RX_BE_PM_SD_REGISTER 0x310 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 pmSdSigbRam : 1; //pm_sd_sigb_ram, reset value: 0x0, access type: RW
		uint32 pmSdViterbiBankRam : 1; //pm_sd_viterbi_bank_ram, reset value: 0x0, access type: RW
		uint32 pmSdDeintRam : 1; //pm_sd_deint_ram, reset value: 0x0, access type: RW
		uint32 pmSdRcrRam : 1; //pm_sd_rcr_ram, reset value: 0x0, access type: RW
		uint32 pmSdCwParamsFifo : 1; //pm_sd_cw_params_fifo, reset value: 0x0, access type: RW
		uint32 pmSdObufCore : 1; //pm_sd_obuf_core, reset value: 0x0, access type: RW
		uint32 pmSdViterbiTbRam : 1; //pm_sd_viterbi_tb_ram, reset value: 0x0, access type: RW
		uint32 pmSdRram2 : 1; //pm_sd_rram2, reset value: 0x0, access type: RW
		uint32 pmSdBurstBuffer0 : 1; //pm_sd_burst_buffer0, reset value: 0x0, access type: RW
		uint32 pmSdBurstBuffer1 : 1; //pm_sd_burst_buffer1, reset value: 0x0, access type: RW
		uint32 pmSdBurstBuffer0Mru : 1; //pm_sd_burst_buffer0_mru, reset value: 0x0, access type: RW
		uint32 pmSdBurstBuffer1Mru : 1; //pm_sd_burst_buffer1_mru, reset value: 0x0, access type: RW
		uint32 reserved0 : 20;
	} bitFields;
} RegB0PhyRxBePmSdRegister_u;

/*REG_B0_PHY_RX_BE_PM_DS_REGISTER 0x314 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 pmDsSigbRam : 1; //pm_ds_sigb_ram, reset value: 0x0, access type: RW
		uint32 pmDsViterbiBankRam : 1; //pm_ds_viterbi_bank_ram, reset value: 0x0, access type: RW
		uint32 pmDsDeintRam : 1; //pm_ds_deint_ram, reset value: 0x0, access type: RW
		uint32 pmDsRcrRam : 1; //pm_ds_rcr_ram, reset value: 0x0, access type: RW
		uint32 pmDsCwParamsFifo : 1; //pm_ds_cw_params_fifo, reset value: 0x0, access type: RW
		uint32 pmDsObufCore : 1; //pm_ds_obuf_core, reset value: 0x0, access type: RW
		uint32 pmDsViterbiTbRam : 1; //pm_ds_viterbi_tb_ram, reset value: 0x0, access type: RW
		uint32 pmDsRram2 : 1; //pm_ds_rram2, reset value: 0x0, access type: RW
		uint32 pmDsBurstBuffer0 : 1; //pm_ds_burst_buffer0, reset value: 0x0, access type: RW
		uint32 pmDsBurstBuffer1 : 1; //pm_ds_burst_buffer1, reset value: 0x0, access type: RW
		uint32 pmDsBurstBuffer0Mru : 1; //pm_ds_burst_buffer0_mru, reset value: 0x0, access type: RW
		uint32 pmDsBurstBuffer1Mru : 1; //pm_ds_burst_buffer1_mru, reset value: 0x0, access type: RW
		uint32 reserved0 : 20;
	} bitFields;
} RegB0PhyRxBePmDsRegister_u;

/*REG_B0_PHY_RX_BE_SIGB_ERROR_CODE 0x318 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 sigbErrorCode : 4; //sigb_error_code, reset value: 0x0, access type: RO
		uint32 reserved0 : 28;
	} bitFields;
} RegB0PhyRxBeSigbErrorCode_u;

/*REG_B0_PHY_RX_BE_HE_MU_COMPRESSED_MODE_INDICATION 0x31C */
typedef union
{
	uint32 val;
	struct
	{
		uint32 heMuCompressedModeIndication : 1; //he_mu_compressed_mode_indication, reset value: 0x0, access type: RO
		uint32 reserved0 : 31;
	} bitFields;
} RegB0PhyRxBeHeMuCompressedModeIndication_u;

/*REG_B0_PHY_RX_BE_HW_MCS_UNSUPPORTED_CAUSE 0x320 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 hwMcsUnsupportedCause : 26; //hw_mcs_unsupported_cause, reset value: 0x0, access type: RO
		uint32 reserved0 : 6;
	} bitFields;
} RegB0PhyRxBeHwMcsUnsupportedCause_u;

/*REG_B0_PHY_RX_BE_RXBE_MASK_UNSUPPORTED_MCS 0x324 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 rxbeMaskUnsupportedMcs : 26; //rxbe_mask_unsupported_mcs, reset value: 0x0, access type: RW
		uint32 reserved0 : 6;
	} bitFields;
} RegB0PhyRxBeRxbeMaskUnsupportedMcs_u;

/*REG_B0_PHY_RX_BE_ROP_REGISTER 0x328 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 ropDeintRam : 1; //rop_deint_ram, reset value: 0x0, access type: RO
		uint32 ropViterbiBankRam : 1; //rop_viterbi_bank_ram, reset value: 0x0, access type: RO
		uint32 ropViterbiTbRam : 1; //rop_viterbi_bank_ram, reset value: 0x0, access type: RO
		uint32 ropRcrRam : 1; //rop_rcr_ram, reset value: 0x0, access type: RO
		uint32 ropSigbRam : 1; //rop_sigb_ram, reset value: 0x0, access type: RO
		uint32 ropCwParamsFifo : 1; //rop_cw_params_fifo, reset value: 0x0, access type: RO
		uint32 ropRram2 : 1; //rop_rram2, reset value: 0x0, access type: RO
		uint32 ropObuf : 1; //rop_obuf, reset value: 0x0, access type: RO
		uint32 ropBurstBuffer0 : 1; //rop_burst_buffer0, reset value: 0x0, access type: RO
		uint32 ropBurstBuffer1 : 1; //rop_burst_buffer1, reset value: 0x0, access type: RO
		uint32 ropBurstBuffer0Mru : 1; //rop_burst_buffer0_mru, reset value: 0x0, access type: RO
		uint32 ropBurstBuffer1Mru : 1; //rop_burst_buffer1_mru, reset value: 0x0, access type: RO
		uint32 reserved0 : 20;
	} bitFields;
} RegB0PhyRxBeRopRegister_u;

/*REG_B0_PHY_RX_BE_EXT_RANGE_READ_ONLY 0x32C */
typedef union
{
	uint32 val;
	struct
	{
		uint32 heExtBeCriteria : 1; //he_ext_be_criteria, reset value: 0x0, access type: RO
		uint32 heExtBeCriteriaValid : 1; //he_ext_be_criteria_valid, reset value: 0x0, access type: RO
		uint32 weakErCriteria : 1; //weak_er_criteria, reset value: 0x0, access type: RO
		uint32 reserved0 : 29;
	} bitFields;
} RegB0PhyRxBeExtRangeReadOnly_u;

/*REG_B0_PHY_RX_BE_DISABLE_NEW_ER_MODE 0x330 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 disableNewErMode : 1; //disable_new_er_mode, reset value: 0x1, access type: RW
		uint32 reserved0 : 31;
	} bitFields;
} RegB0PhyRxBeDisableNewErMode_u;

/*REG_B0_PHY_RX_BE_PM_MAC_DATA_0 0x334 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 pmMacData0 : 32; //pm_mac_data_0, reset value: 0x0, access type: RO
	} bitFields;
} RegB0PhyRxBePmMacData0_u;

/*REG_B0_PHY_RX_BE_PM_MAC_DATA_1 0x338 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 pmMacData1 : 32; //pm_mac_data_1, reset value: 0x0, access type: RO
	} bitFields;
} RegB0PhyRxBePmMacData1_u;

/*REG_B0_PHY_RX_BE_PM_MAC_DATA_2 0x33C */
typedef union
{
	uint32 val;
	struct
	{
		uint32 pmMacData2 : 32; //pm_mac_data_2, reset value: 0x0, access type: RO
	} bitFields;
} RegB0PhyRxBePmMacData2_u;

/*REG_B0_PHY_RX_BE_PM_MAC_DATA_3 0x340 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 pmMacData3 : 32; //pm_mac_data_3, reset value: 0x0, access type: RO
	} bitFields;
} RegB0PhyRxBePmMacData3_u;

/*REG_B0_PHY_RX_BE_PM_MAC_DATA_READY 0x344 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 pmMacDataReady : 1; //pm_mac_data_ready, reset value: 0x0, access type: RO
		uint32 reserved0 : 31;
	} bitFields;
} RegB0PhyRxBePmMacDataReady_u;

/*REG_B0_PHY_RX_BE_DC_CNT_RRAM_EN_CHK_BIT 0x348 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 dcCntRramEnChkBit : 1; //dc_cnt_rram_en_chk_bit, reset value: 0x1, access type: RW
		uint32 reserved0 : 31;
	} bitFields;
} RegB0PhyRxBeDcCntRramEnChkBit_u;

/*REG_B0_PHY_RX_BE_PM_MIN_BURST_LENGTH 0x34C */
typedef union
{
	uint32 val;
	struct
	{
		uint32 pmMinBurstLength : 5; //pm_min_burst_length, reset value: 0x8, access type: RW
		uint32 reserved0 : 27;
	} bitFields;
} RegB0PhyRxBePmMinBurstLength_u;

/*REG_B0_PHY_RX_BE_PM_LAST_SYMBOL_LDPC_CTRL 0x350 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 pmLastSymbolLdpcHeOffset : 16; //offset to reduce from last symbol in he, reset value: 0x780, access type: RW
		uint32 pmLastSymbolLdpcNonHeOffset : 12; //offset to reduce from last symbol in non he, reset value: 0x0, access type: RW
		uint32 pmLastSymbolLdpcEn : 1; //allow to reduce from last symbol from HW, reset value: 0x0, access type: RW
		uint32 pmLastSymbolLdpcSwEn : 1; //force to reduce from last symbol from SW, reset value: 0x0, access type: RW
		uint32 pmFixLdpcLastSymCalc : 1; //fix last sym num cw calc, reset value: 0x0, access type: RW
		uint32 reserved0 : 1;
	} bitFields;
} RegB0PhyRxBePmLastSymbolLdpcCtrl_u;

/*REG_B0_PHY_RX_BE_PM_FORCE_RU_SIZE_7 0x354 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 pmForceRuSize7 : 1; //Force RU size 7 , reset value: 0x0, access type: RW
		uint32 reserved0 : 31;
	} bitFields;
} RegB0PhyRxBePmForceRuSize7_u;

/*REG_B0_PHY_RX_BE_PM_EHT_SCRAMBLER_ENABLE 0x358 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 pmEhtScramblerEnable : 1; //pm_eht_scrambler_enable, reset value: 0x0, access type: RW
		uint32 reserved0 : 31;
	} bitFields;
} RegB0PhyRxBePmEhtScramblerEnable_u;

/*REG_B0_PHY_RX_BE_LDPC_CONVERGENCE_PER_USER 0x35C */
typedef union
{
	uint32 val;
	struct
	{
		uint32 ldpcConvergencePerUser : 32; //ldpc_convergence_per_user, reset value: 0x0, access type: RO
	} bitFields;
} RegB0PhyRxBeLdpcConvergencePerUser_u;

/*REG_B0_PHY_RX_BE_LDPC_CYCLES_LIMIT_0 0x360 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 ldpcCyclesLimitRate12 : 16; //ldpc_cycles_limit_rate_1_2 , reset value: 0x384, access type: RW
		uint32 ldpcCyclesLimitRate23 : 16; //ldpc_cycles_limit_rate_2_3 , reset value: 0x28a, access type: RW
	} bitFields;
} RegB0PhyRxBeLdpcCyclesLimit0_u;

/*REG_B0_PHY_RX_BE_LDPC_CYCLES_LIMIT_1 0x364 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 ldpcCyclesLimitRate34 : 16; //ldpc_cycles_limit_rate_3_4, reset value: 0x226, access type: RW
		uint32 ldpcCyclesLimitRate56 : 16; //ldpc_cycles_limit_rate_5_6, reset value: 0x226, access type: RW
	} bitFields;
} RegB0PhyRxBeLdpcCyclesLimit1_u;

/*REG_B0_PHY_RX_BE_NUM_OF_CORES 0x368 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 numOfCores : 3; //num_of_cores , reset value: 0x0, access type: RW
		uint32 reserved0 : 29;
	} bitFields;
} RegB0PhyRxBeNumOfCores_u;

/*REG_B0_PHY_RX_BE_USIG_OVERFLOW 0x36C */
typedef union
{
	uint32 val;
	struct
	{
		uint32 usigOverflow : 20; //usig_overflow, reset value: 0x0, access type: RO
		uint32 reserved0 : 12;
	} bitFields;
} RegB0PhyRxBeUsigOverflow_u;

/*REG_B0_PHY_RX_BE_EHT_INFO 0x370 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 ehtInfo : 22; //eht_info, reset value: 0x0, access type: RO
		uint32 reserved0 : 10;
	} bitFields;
} RegB0PhyRxBeEhtInfo_u;

/*REG_B0_PHY_RX_BE_SPARE_FROM_FD0 0x374 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 spareFromFd0 : 16; //spare connectivity from FD0, reset value: 0x0, access type: RO
		uint32 reserved0 : 16;
	} bitFields;
} RegB0PhyRxBeSpareFromFd0_u;

/*REG_B0_PHY_RX_BE_SPARE_FROM_FD1 0x378 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 spareFromFd1 : 16; //spare connectivity from FD1, reset value: 0x0, access type: RO
		uint32 reserved0 : 16;
	} bitFields;
} RegB0PhyRxBeSpareFromFd1_u;

/*REG_B0_PHY_RX_BE_SPARE_FROM_TX 0x37C */
typedef union
{
	uint32 val;
	struct
	{
		uint32 spareFromTx : 16; //spare connectivity from TX, reset value: 0x0, access type: RO
		uint32 reserved0 : 16;
	} bitFields;
} RegB0PhyRxBeSpareFromTx_u;

/*REG_B0_PHY_RX_BE_SPARE_FROM_TD 0x380 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 spareFromTd : 16; //spare connectivity from TD, reset value: 0x0, access type: RO
		uint32 reserved0 : 16;
	} bitFields;
} RegB0PhyRxBeSpareFromTd_u;

/*REG_B0_PHY_RX_BE_SPARE_TO_FD0 0x384 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 spareToFd0 : 16; //spare connectivity to FD0, reset value: 0x0, access type: RW
		uint32 reserved0 : 16;
	} bitFields;
} RegB0PhyRxBeSpareToFd0_u;

/*REG_B0_PHY_RX_BE_SPARE_TO_FD1 0x388 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 spareToFd1 : 16; //spare connectivity to FD1, reset value: 0x0, access type: RW
		uint32 reserved0 : 16;
	} bitFields;
} RegB0PhyRxBeSpareToFd1_u;

/*REG_B0_PHY_RX_BE_SPARE_TO_TX 0x38C */
typedef union
{
	uint32 val;
	struct
	{
		uint32 spareToTx : 16; //spare connectivity to TX, reset value: 0x0, access type: RW
		uint32 reserved0 : 16;
	} bitFields;
} RegB0PhyRxBeSpareToTx_u;

/*REG_B0_PHY_RX_BE_SPARE_TO_TD 0x390 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 spareToTd : 16; //spare connectivity to TD, reset value: 0x0, access type: RW
		uint32 reserved0 : 16;
	} bitFields;
} RegB0PhyRxBeSpareToTd_u;

/*REG_B0_PHY_RX_BE_LDPC_CYCLES_SS_OV 0x394 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 ldpcCyclesSteadyStateOverride : 12; //ldpc_cycles_steady_state_override, reset value: 0x0, access type: RW
		uint32 ldpcCyclesSteadyStateOverrideEn : 1; //ldpc_cycles_steady_state_override_en, reset value: 0x0, access type: RW
		uint32 reserved0 : 19;
	} bitFields;
} RegB0PhyRxBeLdpcCyclesSsOv_u;

/*REG_B0_PHY_RX_BE_LDPC_CYCLE_LAST_SYM_OV 0x398 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 ldpcCyclesLastSymOverride : 12; //ldpc_cycles_last_sym_override, reset value: 0x0, access type: RW
		uint32 ldpcCyclesLastSymOverrideEn : 1; //ldpc_cycles_last_sym_override_en, reset value: 0x0, access type: RW
		uint32 reserved0 : 19;
	} bitFields;
} RegB0PhyRxBeLdpcCycleLastSymOv_u;

/*REG_B0_PHY_RX_BE_LDPC_LAST_SYM_CW_IDX 0x39C */
typedef union
{
	uint32 val;
	struct
	{
		uint32 ldpcLastSymbolCwIdxOverride : 16; //ldpc_last_symbol_cw_idx_override, reset value: 0x0, access type: RW
		uint32 ldpcLastSymbolCwIdxOverrideEn : 1; //ldpc_last_symbol_cw_idx_override_en, reset value: 0x0, access type: RW
		uint32 reserved0 : 15;
	} bitFields;
} RegB0PhyRxBeLdpcLastSymCwIdx_u;

/*REG_B0_PHY_RX_BE_USIG_0 0x3A0 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 usig0 : 26; //usig_0, reset value: 0x0, access type: RO
		uint32 reserved0 : 6;
	} bitFields;
} RegB0PhyRxBeUsig0_u;

/*REG_B0_PHY_RX_BE_USIG_1 0x3A4 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 usig1 : 26; //usig_1, reset value: 0x0, access type: RO
		uint32 reserved0 : 6;
	} bitFields;
} RegB0PhyRxBeUsig1_u;

/*REG_B0_PHY_RX_BE_EHT_0 0x3A8 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 eht0 : 26; //eht_0, reset value: 0x0, access type: RO
		uint32 reserved0 : 6;
	} bitFields;
} RegB0PhyRxBeEht0_u;

/*REG_B0_PHY_RX_BE_EHT_1 0x3AC */
typedef union
{
	uint32 val;
	struct
	{
		uint32 eht1 : 26; //eht_1, reset value: 0x0, access type: RO
		uint32 reserved0 : 6;
	} bitFields;
} RegB0PhyRxBeEht1_u;

/*REG_B0_PHY_RX_BE_IS_320_UPPER_CHANNEL 0x3B0 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 is320UpperChannel : 1; //is_320_upper_channel, reset value: 0x0, access type: RW
		uint32 reserved0 : 31;
	} bitFields;
} RegB0PhyRxBeIs320UpperChannel_u;

/*REG_B0_PHY_RX_BE_TEST_BUS_GCLK_EN 0x3B4 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 testBusGclkEn : 1; //test_bus_gclk_en, reset value: 0x0, access type: RW
		uint32 reserved0 : 31;
	} bitFields;
} RegB0PhyRxBeTestBusGclkEn_u;

/*REG_B0_PHY_RX_BE_BYTE_ERROR_CONTOL 0x3B8 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 byteErrorUser : 8; //byte error user index, reset value: 0x0, access type: CONST
		uint32 byteErrorLoad : 1; //load new rate , reset value: 0x0, access type: WO
		uint32 byteErrorClear : 1; //clear error, reset value: 0x0, access type: WO
		uint32 reserved0 : 22;
	} bitFields;
} RegB0PhyRxBeByteErrorContol_u;

/*REG_B0_PHY_RX_BE_BYTE_ERROR_RATE 0x3BC */
typedef union
{
	uint32 val;
	struct
	{
		uint32 byteErrorRate : 32; //ber rate, reset value: 0x0, access type: RW
	} bitFields;
} RegB0PhyRxBeByteErrorRate_u;

/*REG_B0_PHY_RX_BE_BYTE_ERROR_RATE_RD 0x3C0 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 byteErrorRateRd : 32; //ber rate rd, reset value: 0x0, access type: RO
	} bitFields;
} RegB0PhyRxBeByteErrorRateRd_u;

/*REG_B0_PHY_RX_BE_DFE_CONTROL 0x3C4 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 dfeEnable : 1; //enable dfe, reset value: 0x0, access type: RW
		uint32 reserved0 : 3;
		uint32 dfeMinNumSymbols : 4; //minimal packet length in symbols, reset value: 0x5, access type: RW
		uint32 dfeMinCwPerSymbol : 3; //minimal  cw per symbol, reset value: 0x3, access type: RW
		uint32 reserved1 : 1;
		uint32 dfeVhtMinNumSymbols : 4; //minimal vht packet length in symbols, reset value: 0x6, access type: RW
		uint32 dfeVhtMinCwPerSymbol : 3; //minimal vht cw per symbol, reset value: 0x3, access type: RW
		uint32 reserved2 : 13;
	} bitFields;
} RegB0PhyRxBeDfeControl_u;

/*REG_B0_PHY_RX_BE_DFE_VALID 0x3C8 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 dfeValid : 1; //packet is applicable for dfe, reset value: 0x0, access type: RO
		uint32 reserved0 : 31;
	} bitFields;
} RegB0PhyRxBeDfeValid_u;

/*REG_B0_PHY_RX_BE_EVM_PPRU_RAM_READY 0x3CC */
typedef union
{
	uint32 val;
	struct
	{
		uint32 evmPpruRamReady : 1; //evm_ppru_ram_ready, reset value: 0x0, access type: RO
		uint32 reserved0 : 31;
	} bitFields;
} RegB0PhyRxBeEvmPpruRamReady_u;

/*REG_B0_PHY_RX_BE_EHT_SIG_INFO_VALID 0x3D0 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 ehtSigInfoValid : 1; //evm_sig_info_valid, reset value: 0x0, access type: RO
		uint32 reserved0 : 31;
	} bitFields;
} RegB0PhyRxBeEhtSigInfoValid_u;

/*REG_B0_PHY_RX_BE_LSIG_ERROR_CAUSE 0x3D4 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 sig1ParityErr : 1; //sig1_parity_err, reset value: 0x0, access type: RO
		uint32 sig1RateErr : 1; //sig1_rate_err, reset value: 0x0, access type: RO
		uint32 sig1LengthMinErr : 1; //sig1_length_min_err, reset value: 0x0, access type: RO
		uint32 sig1ReservedErr : 1; //sig1_reserved_err, reset value: 0x0, access type: RO
		uint32 sig1LengthMaxErr : 1; //sig1_length_max_err, reset value: 0x0, access type: RO
		uint32 reserved0 : 27;
	} bitFields;
} RegB0PhyRxBeLsigErrorCause_u;

/*REG_B0_PHY_RX_BE_MAXIMUM_PACKET_SIZE 0x3D8 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 maximumPacketSize : 12; //maximum_packet_size, reset value: 0x0, access type: RW
		uint32 reserved0 : 20;
	} bitFields;
} RegB0PhyRxBeMaximumPacketSize_u;

/*REG_B0_PHY_RX_BE_SIG3_ERROR_CAUSE 0x3DC */
typedef union
{
	uint32 val;
	struct
	{
		uint32 sig3CrcError : 1; //crc_error, reset value: 0x0, access type: RO
		uint32 sig3McsError : 1; //mcs_error, reset value: 0x0, access type: RO
		uint32 sig3AirTimeErr : 1; //air_time_err, reset value: 0x0, access type: RO
		uint32 sig3NdpPeErr : 1; //ndp_pe_err, reset value: 0x0, access type: RO
		uint32 sig3NdpInvalidHeSigaGiLtfErr : 1; //ndp_invalid_he_siga_gi_ltf_err, reset value: 0x0, access type: RO
		uint32 sig3BccMcsErr : 1; //bcc_mcs_err, reset value: 0x0, access type: RO
		uint32 sig3BccBwErr : 1; //bcc_bw_err, reset value: 0x0, access type: RO
		uint32 sig3HeErErr : 1; //he_er_err, reset value: 0x0, access type: RO
		uint32 sig3WrongBandErr : 1; //wrong_band_err, reset value: 0x0, access type: RO
		uint32 sig3HtPacket : 1; //ht_packet, reset value: 0x0, access type: RO
		uint32 sig3VhtPacket : 1; //vht_packet, reset value: 0x0, access type: RO
		uint32 sig3DcmErr : 1; //dcm_err, reset value: 0x0, access type: RO
		uint32 sig3EhtSigNsymErr : 1; //eht_sig_nsym_err, reset value: 0x0, access type: RO
		uint32 sig3ReservedErr : 1; //sig3_reserved_err, reset value: 0x0, access type: RO
		uint32 reserved0 : 18;
	} bitFields;
} RegB0PhyRxBeSig3ErrorCause_u;

/*REG_B0_PHY_RX_BE_MASK_SIG3_ERROR_CAUSE 0x3E0 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 maskSig3CrcError : 1; //mask_sig3_crc_error, reset value: 0x0, access type: RW
		uint32 maskSig3McsError : 1; //mask_sig3_mcs_error, reset value: 0x0, access type: RW
		uint32 maskSig3AirTimeErr : 1; //mask_sig3_air_time_err, reset value: 0x0, access type: RW
		uint32 maskSig3NdpPeErr : 1; //mask_sig3_ndp_pe_err, reset value: 0x0, access type: RW
		uint32 maskSig3NdpInvalidHeSigaGiLtfErr : 1; //mask_sig3_ndp_invalid_he_siga_gi_ltf_err, reset value: 0x0, access type: RW
		uint32 maskSig3BccMcsErr : 1; //mask_sig3_bcc_mcs_err, reset value: 0x0, access type: RW
		uint32 maskSig3BccBwErr : 1; //mask_sig3_bcc_bw_err, reset value: 0x0, access type: RW
		uint32 maskSig3HeErErr : 1; //mask_sig3_he_er_err, reset value: 0x0, access type: RW
		uint32 maskSig3WrongBandErr : 1; //mask_sig3_wrong_band_err, reset value: 0x0, access type: RW
		uint32 maskSig3HtPacket : 1; //mask_sig3_ht_packet, reset value: 0x0, access type: RW
		uint32 maskSig3VhtPacket : 1; //mask_sig3_vht_packet, reset value: 0x0, access type: RW
		uint32 maskSig3DcmErr : 1; //mask_sig3_dcm_err, reset value: 0x0, access type: RW
		uint32 maskSig3EhtSigNsymErr : 1; //mask_sig3_eht_sig_nsym_err, reset value: 0x0, access type: RW
		uint32 maskSig3ReservedErr : 1; //mask_sig3_reserved_err, reset value: 0x0, access type: RW
		uint32 reserved0 : 18;
	} bitFields;
} RegB0PhyRxBeMaskSig3ErrorCause_u;

/*REG_B0_PHY_RX_BE_EHTSIG_ERROR_CAUSE 0x3E4 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 ehtBccMcsErr : 1; //eht_bcc_mcs_err, reset value: 0x0, access type: RO
		uint32 ehtBccBwErr : 1; //eht_bcc_bw_err, reset value: 0x0, access type: RO
		uint32 ehtMcs15Err : 1; //eht_mcs15_err, reset value: 0x0, access type: RO
		uint32 ehtAirTimeErr : 1; //eht_air_time_err, reset value: 0x0, access type: RO
		uint32 ehtNdpErr : 1; //eht_ndp_err, reset value: 0x0, access type: RO
		uint32 ehtSuNehtLtfErr : 1; //eht_su_neht_ltf_err, reset value: 0x0, access type: RO
		uint32 ehtCrcErr : 1; //eht_crc_err, reset value: 0x0, access type: RO
		uint32 ehtDupMode5G : 1; //eht_dup_mode_5g, reset value: 0x0, access type: RO
		uint32 reserved0 : 24;
	} bitFields;
} RegB0PhyRxBeEhtsigErrorCause_u;

/*REG_B0_PHY_RX_BE_MASK_EHTSIG_ERROR_CAUSE 0x3E8 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 maskEhtBccMcsErr : 1; //mask_eht_bcc_mcs_err, reset value: 0x0, access type: RW
		uint32 maskEhtBccBwErr : 1; //mask_eht_bcc_bw_err, reset value: 0x0, access type: RW
		uint32 maskEhtMcs15Err : 1; //mask_eht_mcs15_err, reset value: 0x0, access type: RW
		uint32 maskEhtAirTimeErr : 1; //mask_eht_air_time_err, reset value: 0x0, access type: RW
		uint32 maskEhtNdpErr : 1; //mask_eht_ndp_err, reset value: 0x0, access type: RW
		uint32 maskEhtSuNehtLtfErr : 1; //mask_eht_su_neht_ltf_err, reset value: 0x0, access type: RW
		uint32 maskEhtCrcErr : 1; //mask_eht_crc_err, reset value: 0x0, access type: RW
		uint32 maskEhtDupMode5G : 1; //mask_eht_dup_mode_5g, reset value: 0x0, access type: RW
		uint32 reserved0 : 24;
	} bitFields;
} RegB0PhyRxBeMaskEhtsigErrorCause_u;



#endif // _B0_PHY_RX_BE_REGS_H_
