
/***********************************************************************************
File:				PhyRxtdAnt2Regs.h
Module:				phyRxtdAnt2
SOC Revision:		latest
Generated at:       2024-06-26 12:55:19
Purpose:
Description:		This File was auto generated using SOC Online

************************************************************************************/
#ifndef _PHY_RXTD_ANT2_REGS_H_
#define _PHY_RXTD_ANT2_REGS_H_

/*---------------------------------------------------------------------------------
/						Registers Addresses													 
/----------------------------------------------------------------------------------*/
#include "HwMemoryMap.h"

#define PHY_RXTD_ANT2_BASE_ADDRESS                        MEMORY_MAP_UNIT_242_BASE_ADDRESS
#define	REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG00                  (PHY_RXTD_ANT2_BASE_ADDRESS + 0x0)
#define	REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG01                  (PHY_RXTD_ANT2_BASE_ADDRESS + 0x4)
#define	REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG02                  (PHY_RXTD_ANT2_BASE_ADDRESS + 0x8)
#define	REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG03                  (PHY_RXTD_ANT2_BASE_ADDRESS + 0xC)
#define	REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG04                  (PHY_RXTD_ANT2_BASE_ADDRESS + 0x10)
#define	REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG05                  (PHY_RXTD_ANT2_BASE_ADDRESS + 0x14)
#define	REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG06                  (PHY_RXTD_ANT2_BASE_ADDRESS + 0x18)
#define	REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG07                  (PHY_RXTD_ANT2_BASE_ADDRESS + 0x1C)
#define	REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG08                  (PHY_RXTD_ANT2_BASE_ADDRESS + 0x20)
#define	REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG09                  (PHY_RXTD_ANT2_BASE_ADDRESS + 0x24)
#define	REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG0A                  (PHY_RXTD_ANT2_BASE_ADDRESS + 0x28)
#define	REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG0B                  (PHY_RXTD_ANT2_BASE_ADDRESS + 0x2C)
#define	REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG0C                  (PHY_RXTD_ANT2_BASE_ADDRESS + 0x30)
#define	REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG0D                  (PHY_RXTD_ANT2_BASE_ADDRESS + 0x34)
#define	REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG0E                  (PHY_RXTD_ANT2_BASE_ADDRESS + 0x38)
#define	REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG0F                  (PHY_RXTD_ANT2_BASE_ADDRESS + 0x3C)
#define	REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG10                  (PHY_RXTD_ANT2_BASE_ADDRESS + 0x40)
#define	REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG11                  (PHY_RXTD_ANT2_BASE_ADDRESS + 0x44)
#define	REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG12                  (PHY_RXTD_ANT2_BASE_ADDRESS + 0x48)
#define	REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG13                  (PHY_RXTD_ANT2_BASE_ADDRESS + 0x4C)
#define	REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG14                  (PHY_RXTD_ANT2_BASE_ADDRESS + 0x50)
#define	REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG15                  (PHY_RXTD_ANT2_BASE_ADDRESS + 0x54)
#define	REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG16                  (PHY_RXTD_ANT2_BASE_ADDRESS + 0x58)
#define	REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG17                  (PHY_RXTD_ANT2_BASE_ADDRESS + 0x5C)
#define	REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG18                  (PHY_RXTD_ANT2_BASE_ADDRESS + 0x60)
#define	REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG19                  (PHY_RXTD_ANT2_BASE_ADDRESS + 0x64)
#define	REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG1A                  (PHY_RXTD_ANT2_BASE_ADDRESS + 0x68)
#define	REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG1B                  (PHY_RXTD_ANT2_BASE_ADDRESS + 0x6C)
#define	REG_PHY_RXTD_ANT2_OLA_CONTROL                         (PHY_RXTD_ANT2_BASE_ADDRESS + 0x70)
#define	REG_PHY_RXTD_ANT2_OLA_START                           (PHY_RXTD_ANT2_BASE_ADDRESS + 0x78)
#define	REG_PHY_RXTD_ANT2_OLA_STATUS                          (PHY_RXTD_ANT2_BASE_ADDRESS + 0x7C)
#define	REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG20                  (PHY_RXTD_ANT2_BASE_ADDRESS + 0x80)
#define	REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG21                  (PHY_RXTD_ANT2_BASE_ADDRESS + 0x84)
#define	REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG22                  (PHY_RXTD_ANT2_BASE_ADDRESS + 0x88)
#define	REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG23                  (PHY_RXTD_ANT2_BASE_ADDRESS + 0x8C)
#define	REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG24                  (PHY_RXTD_ANT2_BASE_ADDRESS + 0x90)
#define	REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG25                  (PHY_RXTD_ANT2_BASE_ADDRESS + 0x94)
#define	REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG26                  (PHY_RXTD_ANT2_BASE_ADDRESS + 0x98)
#define	REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG27                  (PHY_RXTD_ANT2_BASE_ADDRESS + 0x9C)
#define	REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG28                  (PHY_RXTD_ANT2_BASE_ADDRESS + 0xA0)
#define	REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG29                  (PHY_RXTD_ANT2_BASE_ADDRESS + 0xA4)
#define	REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG2A                  (PHY_RXTD_ANT2_BASE_ADDRESS + 0xA8)
#define	REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG2B                  (PHY_RXTD_ANT2_BASE_ADDRESS + 0xAC)
#define	REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG2C                  (PHY_RXTD_ANT2_BASE_ADDRESS + 0xB0)
#define	REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG2D                  (PHY_RXTD_ANT2_BASE_ADDRESS + 0xB4)
#define	REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG2E                  (PHY_RXTD_ANT2_BASE_ADDRESS + 0xB8)
#define	REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG2F                  (PHY_RXTD_ANT2_BASE_ADDRESS + 0xBC)
#define	REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG30                  (PHY_RXTD_ANT2_BASE_ADDRESS + 0xC0)
#define	REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG31                  (PHY_RXTD_ANT2_BASE_ADDRESS + 0xC4)
#define	REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG32                  (PHY_RXTD_ANT2_BASE_ADDRESS + 0xC8)
#define	REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG33                  (PHY_RXTD_ANT2_BASE_ADDRESS + 0xCC)
#define	REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG34                  (PHY_RXTD_ANT2_BASE_ADDRESS + 0xD0)
#define	REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG3B                  (PHY_RXTD_ANT2_BASE_ADDRESS + 0xEC)
#define	REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG3C                  (PHY_RXTD_ANT2_BASE_ADDRESS + 0xF0)
#define	REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG3D                  (PHY_RXTD_ANT2_BASE_ADDRESS + 0xF4)
#define	REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG3E                  (PHY_RXTD_ANT2_BASE_ADDRESS + 0xF8)
#define	REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG3F                  (PHY_RXTD_ANT2_BASE_ADDRESS + 0xFC)
#define	REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG40                  (PHY_RXTD_ANT2_BASE_ADDRESS + 0x100)
#define	REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG41                  (PHY_RXTD_ANT2_BASE_ADDRESS + 0x104)
#define	REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG42                  (PHY_RXTD_ANT2_BASE_ADDRESS + 0x108)
#define	REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG43                  (PHY_RXTD_ANT2_BASE_ADDRESS + 0x10C)
#define	REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG44                  (PHY_RXTD_ANT2_BASE_ADDRESS + 0x110)
#define	REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG45                  (PHY_RXTD_ANT2_BASE_ADDRESS + 0x114)
#define	REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG46                  (PHY_RXTD_ANT2_BASE_ADDRESS + 0x118)
#define	REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG47                  (PHY_RXTD_ANT2_BASE_ADDRESS + 0x11C)
#define	REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG48                  (PHY_RXTD_ANT2_BASE_ADDRESS + 0x120)
#define	REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG49                  (PHY_RXTD_ANT2_BASE_ADDRESS + 0x124)
#define	REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG4A                  (PHY_RXTD_ANT2_BASE_ADDRESS + 0x128)
#define	REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG4B                  (PHY_RXTD_ANT2_BASE_ADDRESS + 0x12C)
#define	REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG4C                  (PHY_RXTD_ANT2_BASE_ADDRESS + 0x130)
#define	REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG4D                  (PHY_RXTD_ANT2_BASE_ADDRESS + 0x134)
#define	REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG4E                  (PHY_RXTD_ANT2_BASE_ADDRESS + 0x138)
#define	REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG4F                  (PHY_RXTD_ANT2_BASE_ADDRESS + 0x13C)
#define	REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG50                  (PHY_RXTD_ANT2_BASE_ADDRESS + 0x140)
#define	REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG51                  (PHY_RXTD_ANT2_BASE_ADDRESS + 0x144)
#define	REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG52                  (PHY_RXTD_ANT2_BASE_ADDRESS + 0x148)
#define	REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG53                  (PHY_RXTD_ANT2_BASE_ADDRESS + 0x14C)
#define	REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG54                  (PHY_RXTD_ANT2_BASE_ADDRESS + 0x150)
#define	REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG55                  (PHY_RXTD_ANT2_BASE_ADDRESS + 0x154)
#define	REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG56                  (PHY_RXTD_ANT2_BASE_ADDRESS + 0x158)
#define	REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG57                  (PHY_RXTD_ANT2_BASE_ADDRESS + 0x15C)
#define	REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG58                  (PHY_RXTD_ANT2_BASE_ADDRESS + 0x160)
#define	REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG60                  (PHY_RXTD_ANT2_BASE_ADDRESS + 0x180)
#define	REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG61                  (PHY_RXTD_ANT2_BASE_ADDRESS + 0x184)
#define	REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG62                  (PHY_RXTD_ANT2_BASE_ADDRESS + 0x188)
#define	REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG63                  (PHY_RXTD_ANT2_BASE_ADDRESS + 0x18C)
#define	REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG64                  (PHY_RXTD_ANT2_BASE_ADDRESS + 0x190)
#define	REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG65                  (PHY_RXTD_ANT2_BASE_ADDRESS + 0x194)
#define	REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG66                  (PHY_RXTD_ANT2_BASE_ADDRESS + 0x198)
#define	REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG67                  (PHY_RXTD_ANT2_BASE_ADDRESS + 0x19C)
#define	REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG69                  (PHY_RXTD_ANT2_BASE_ADDRESS + 0x1A4)
#define	REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG6A                  (PHY_RXTD_ANT2_BASE_ADDRESS + 0x1A8)
#define	REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG6B                  (PHY_RXTD_ANT2_BASE_ADDRESS + 0x1AC)
#define	REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG6C                  (PHY_RXTD_ANT2_BASE_ADDRESS + 0x1B0)
#define	REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG6D                  (PHY_RXTD_ANT2_BASE_ADDRESS + 0x1B4)
#define	REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG6E                  (PHY_RXTD_ANT2_BASE_ADDRESS + 0x1B8)
#define	REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG6F                  (PHY_RXTD_ANT2_BASE_ADDRESS + 0x1BC)
#define	REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG70                  (PHY_RXTD_ANT2_BASE_ADDRESS + 0x1C0)
#define	REG_PHY_RXTD_ANT2_RX_ABB_ANT_REG71                    (PHY_RXTD_ANT2_BASE_ADDRESS + 0x1C4)
#define	REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG72                  (PHY_RXTD_ANT2_BASE_ADDRESS + 0x1C8)
#define	REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG73                  (PHY_RXTD_ANT2_BASE_ADDRESS + 0x1CC)
#define	REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG74                  (PHY_RXTD_ANT2_BASE_ADDRESS + 0x1D0)
#define	REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG75                  (PHY_RXTD_ANT2_BASE_ADDRESS + 0x1D4)
#define	REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG76                  (PHY_RXTD_ANT2_BASE_ADDRESS + 0x1D8)
#define	REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG77                  (PHY_RXTD_ANT2_BASE_ADDRESS + 0x1DC)
#define	REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG78                  (PHY_RXTD_ANT2_BASE_ADDRESS + 0x1E0)
#define	REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG79                  (PHY_RXTD_ANT2_BASE_ADDRESS + 0x1E4)
#define	REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG7A                  (PHY_RXTD_ANT2_BASE_ADDRESS + 0x1E8)
#define	REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG7B                  (PHY_RXTD_ANT2_BASE_ADDRESS + 0x1EC)
#define	REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG7C                  (PHY_RXTD_ANT2_BASE_ADDRESS + 0x1F0)
#define	REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG7D                  (PHY_RXTD_ANT2_BASE_ADDRESS + 0x1F4)
#define	REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG7E                  (PHY_RXTD_ANT2_BASE_ADDRESS + 0x1F8)
#define	REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG7F                  (PHY_RXTD_ANT2_BASE_ADDRESS + 0x1FC)
#define	REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG80                  (PHY_RXTD_ANT2_BASE_ADDRESS + 0x200)
#define	REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG82                  (PHY_RXTD_ANT2_BASE_ADDRESS + 0x208)
#define	REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG83                  (PHY_RXTD_ANT2_BASE_ADDRESS + 0x20C)
#define	REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG84                  (PHY_RXTD_ANT2_BASE_ADDRESS + 0x210)
#define	REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG85                  (PHY_RXTD_ANT2_BASE_ADDRESS + 0x214)
#define	REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG86                  (PHY_RXTD_ANT2_BASE_ADDRESS + 0x218)
#define	REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG87                  (PHY_RXTD_ANT2_BASE_ADDRESS + 0x21C)
#define	REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG88                  (PHY_RXTD_ANT2_BASE_ADDRESS + 0x220)
#define	REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG89                  (PHY_RXTD_ANT2_BASE_ADDRESS + 0x224)
#define	REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG8A                  (PHY_RXTD_ANT2_BASE_ADDRESS + 0x228)
#define	REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG8B                  (PHY_RXTD_ANT2_BASE_ADDRESS + 0x22C)
#define	REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG8C                  (PHY_RXTD_ANT2_BASE_ADDRESS + 0x230)
#define	REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG8D                  (PHY_RXTD_ANT2_BASE_ADDRESS + 0x234)
#define	REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG8E                  (PHY_RXTD_ANT2_BASE_ADDRESS + 0x238)
#define	REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG8F                  (PHY_RXTD_ANT2_BASE_ADDRESS + 0x23C)
#define	REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG90                  (PHY_RXTD_ANT2_BASE_ADDRESS + 0x240)
#define	REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG91                  (PHY_RXTD_ANT2_BASE_ADDRESS + 0x244)
#define	REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG92                  (PHY_RXTD_ANT2_BASE_ADDRESS + 0x248)
#define	REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG93                  (PHY_RXTD_ANT2_BASE_ADDRESS + 0x24C)
#define	REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG94                  (PHY_RXTD_ANT2_BASE_ADDRESS + 0x250)
#define	REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG95                  (PHY_RXTD_ANT2_BASE_ADDRESS + 0x254)
#define	REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG96                  (PHY_RXTD_ANT2_BASE_ADDRESS + 0x258)
#define	REG_PHY_RXTD_ANT2_CONTROL_11B                         (PHY_RXTD_ANT2_BASE_ADDRESS + 0x25C)
#define	REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG98                  (PHY_RXTD_ANT2_BASE_ADDRESS + 0x260)
#define	REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG99                  (PHY_RXTD_ANT2_BASE_ADDRESS + 0x264)
#define	REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG9A                  (PHY_RXTD_ANT2_BASE_ADDRESS + 0x268)
#define	REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG9B                  (PHY_RXTD_ANT2_BASE_ADDRESS + 0x26C)
#define	REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG9C                  (PHY_RXTD_ANT2_BASE_ADDRESS + 0x270)
#define	REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG9D                  (PHY_RXTD_ANT2_BASE_ADDRESS + 0x274)
#define	REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG9E                  (PHY_RXTD_ANT2_BASE_ADDRESS + 0x278)
#define	REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG9F                  (PHY_RXTD_ANT2_BASE_ADDRESS + 0x27C)
#define	REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REGA1                  (PHY_RXTD_ANT2_BASE_ADDRESS + 0x284)
#define	REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REGA2                  (PHY_RXTD_ANT2_BASE_ADDRESS + 0x288)
#define	REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REGA3                  (PHY_RXTD_ANT2_BASE_ADDRESS + 0x28C)
#define	REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REGA4                  (PHY_RXTD_ANT2_BASE_ADDRESS + 0x290)
#define	REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REGA5                  (PHY_RXTD_ANT2_BASE_ADDRESS + 0x294)
#define	REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REGA6                  (PHY_RXTD_ANT2_BASE_ADDRESS + 0x298)
#define	REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REGA7                  (PHY_RXTD_ANT2_BASE_ADDRESS + 0x29C)
#define	REG_PHY_RXTD_ANT2_FORCE_OP_CH_ZERO                    (PHY_RXTD_ANT2_BASE_ADDRESS + 0x2A0)
#define	REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REGA9                  (PHY_RXTD_ANT2_BASE_ADDRESS + 0x2A4)
#define	REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REGAA                  (PHY_RXTD_ANT2_BASE_ADDRESS + 0x2A8)
#define	REG_PHY_RXTD_ANT2_TB_BANDSELECT_BANDS                 (PHY_RXTD_ANT2_BASE_ADDRESS + 0x2AC)
#define	REG_PHY_RXTD_ANT2_CONTROL_OVERRIDE                    (PHY_RXTD_ANT2_BASE_ADDRESS + 0x2B0)
#define	REG_PHY_RXTD_ANT2_ANT_SW_RESET_N_REG                  (PHY_RXTD_ANT2_BASE_ADDRESS + 0x2B4)
#define	REG_PHY_RXTD_ANT2_ANT_BLOCK_EN                        (PHY_RXTD_ANT2_BASE_ADDRESS + 0x2B8)
#define	REG_PHY_RXTD_ANT2_ACI_BAND_POWER_0                    (PHY_RXTD_ANT2_BASE_ADDRESS + 0x2BC)
#define	REG_PHY_RXTD_ANT2_ACI_BAND_POWER_1                    (PHY_RXTD_ANT2_BASE_ADDRESS + 0x2C0)
#define	REG_PHY_RXTD_ANT2_ACI_BAND_POWER_2                    (PHY_RXTD_ANT2_BASE_ADDRESS + 0x2C4)
#define	REG_PHY_RXTD_ANT2_ACI_BAND_POWER_3                    (PHY_RXTD_ANT2_BASE_ADDRESS + 0x2C8)
#define	REG_PHY_RXTD_ANT2_ACI_BAND_POWER_4                    (PHY_RXTD_ANT2_BASE_ADDRESS + 0x2CC)
#define	REG_PHY_RXTD_ANT2_ACI_BAND_POWER_5                    (PHY_RXTD_ANT2_BASE_ADDRESS + 0x2D0)
#define	REG_PHY_RXTD_ANT2_ACI_BAND_POWER_6                    (PHY_RXTD_ANT2_BASE_ADDRESS + 0x2D4)
#define	REG_PHY_RXTD_ANT2_ACI_BAND_POWER_7                    (PHY_RXTD_ANT2_BASE_ADDRESS + 0x2D8)
#define	REG_PHY_RXTD_ANT2_ACI_BAND_POWER_8                    (PHY_RXTD_ANT2_BASE_ADDRESS + 0x2DC)
#define	REG_PHY_RXTD_ANT2_ACI_BAND_POWER_9                    (PHY_RXTD_ANT2_BASE_ADDRESS + 0x2E0)
#define	REG_PHY_RXTD_ANT2_ACI_BAND_POWER_10                   (PHY_RXTD_ANT2_BASE_ADDRESS + 0x2E4)
#define	REG_PHY_RXTD_ANT2_ACI_BAND_POWER_11                   (PHY_RXTD_ANT2_BASE_ADDRESS + 0x2E8)
#define	REG_PHY_RXTD_ANT2_ACI_BAND_POWER_12                   (PHY_RXTD_ANT2_BASE_ADDRESS + 0x2EC)
#define	REG_PHY_RXTD_ANT2_ACI_BAND_POWER_13                   (PHY_RXTD_ANT2_BASE_ADDRESS + 0x2F0)
#define	REG_PHY_RXTD_ANT2_ACI_BAND_POWER_14                   (PHY_RXTD_ANT2_BASE_ADDRESS + 0x2F4)
#define	REG_PHY_RXTD_ANT2_ACI_BAND_POWER_15                   (PHY_RXTD_ANT2_BASE_ADDRESS + 0x2F8)
#define	REG_PHY_RXTD_ANT2_ACI_BAND_POWER_OVR_0_3              (PHY_RXTD_ANT2_BASE_ADDRESS + 0x2FC)
#define	REG_PHY_RXTD_ANT2_ACI_BAND_POWER_OVR_4_7              (PHY_RXTD_ANT2_BASE_ADDRESS + 0x300)
#define	REG_PHY_RXTD_ANT2_ACI_BAND_POWER_OVR_8_11             (PHY_RXTD_ANT2_BASE_ADDRESS + 0x304)
#define	REG_PHY_RXTD_ANT2_ACI_BAND_POWER_OVR_12_15            (PHY_RXTD_ANT2_BASE_ADDRESS + 0x308)
#define	REG_PHY_RXTD_ANT2_ACI_DET_RADAR_COUNTER_TH            (PHY_RXTD_ANT2_BASE_ADDRESS + 0x30C)
#define	REG_PHY_RXTD_ANT2_LOOPBACK_PYPASS                     (PHY_RXTD_ANT2_BASE_ADDRESS + 0x310)
#define	REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REGC5                  (PHY_RXTD_ANT2_BASE_ADDRESS + 0x314)
#define	REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REGC6                  (PHY_RXTD_ANT2_BASE_ADDRESS + 0x318)
#define	REG_PHY_RXTD_ANT2_PM_ACIDET_BYPASS_OFFSETS            (PHY_RXTD_ANT2_BASE_ADDRESS + 0x31C)
#define	REG_PHY_RXTD_ANT2_ANTENNA_320M_MODE_CONTROLS          (PHY_RXTD_ANT2_BASE_ADDRESS + 0x320)
#define	REG_PHY_RXTD_ANT2_FDL_RESET_SHIFT                     (PHY_RXTD_ANT2_BASE_ADDRESS + 0x324)
#define	REG_PHY_RXTD_ANT2_ABB_DPD_CONTROLS                    (PHY_RXTD_ANT2_BASE_ADDRESS + 0x328)
#define	REG_PHY_RXTD_ANT2_ABB_DFT_CONTROLS                    (PHY_RXTD_ANT2_BASE_ADDRESS + 0x32C)
#define	REG_PHY_RXTD_ANT2_FDL_PPM_COMPUTE                     (PHY_RXTD_ANT2_BASE_ADDRESS + 0x330)
#define	REG_PHY_RXTD_ANT2_FFT_IN_GAIN_MRU                     (PHY_RXTD_ANT2_BASE_ADDRESS + 0x334)
#define	REG_PHY_RXTD_ANT2_PRE_FILTER_COEF_LEN_SEL             (PHY_RXTD_ANT2_BASE_ADDRESS + 0x338)
#define	REG_PHY_RXTD_ANT2_INTERP_BEFORE_CHENNEL_FILTER        (PHY_RXTD_ANT2_BASE_ADDRESS + 0x33C)
#define	REG_PHY_RXTD_ANT2_ACI_RSSI_MAX_BAND_PWR               (PHY_RXTD_ANT2_BASE_ADDRESS + 0x340)
#define	REG_PHY_RXTD_ANT2_ACI_RSSI_MAX_BAND_PWR_HB            (PHY_RXTD_ANT2_BASE_ADDRESS + 0x344)
#define	REG_PHY_RXTD_ANT2_ACI_RSSI_SAT_FLAG                   (PHY_RXTD_ANT2_BASE_ADDRESS + 0x348)
#define	REG_PHY_RXTD_ANT2_POWER_OPTIMIZATION                  (PHY_RXTD_ANT2_BASE_ADDRESS + 0x34C)
#define	REG_PHY_RXTD_ANT2_EMULATION_CONTROL                   (PHY_RXTD_ANT2_BASE_ADDRESS + 0x350)
#define	REG_PHY_RXTD_ANT2_ACIDET_POW_HB                       (PHY_RXTD_ANT2_BASE_ADDRESS + 0x354)
#define	REG_PHY_RXTD_ANT2_PM_SPURC_NSAMP_THR_0                (PHY_RXTD_ANT2_BASE_ADDRESS + 0x358)
#define	REG_PHY_RXTD_ANT2_PM_SPURC_POW_THR_LOW_0              (PHY_RXTD_ANT2_BASE_ADDRESS + 0x35C)
#define	REG_PHY_RXTD_ANT2_PM_SPURC_POW_THR_HIGH_0             (PHY_RXTD_ANT2_BASE_ADDRESS + 0x360)
#define	REG_PHY_RXTD_ANT2_PM_SPURC_CONTROL_0                  (PHY_RXTD_ANT2_BASE_ADDRESS + 0x364)
#define	REG_PHY_RXTD_ANT2_PM_SPURC_GAIN_TIMER_0               (PHY_RXTD_ANT2_BASE_ADDRESS + 0x368)
#define	REG_PHY_RXTD_ANT2_PM_SPURC_DDFS_PHASE_ADJUST_0        (PHY_RXTD_ANT2_BASE_ADDRESS + 0x36C)
#define	REG_PHY_RXTD_ANT2_PM_SPURC_DDFS_PHASE_INIT_0          (PHY_RXTD_ANT2_BASE_ADDRESS + 0x370)
#define	REG_PHY_RXTD_ANT2_PM_SPURC_DDFS_FCW_0                 (PHY_RXTD_ANT2_BASE_ADDRESS + 0x374)
#define	REG_PHY_RXTD_ANT2_PM_SPURC_DDFS_P_Q_0                 (PHY_RXTD_ANT2_BASE_ADDRESS + 0x378)
#define	REG_PHY_RXTD_ANT2_PM_SPURC_MEM_RESET_0                (PHY_RXTD_ANT2_BASE_ADDRESS + 0x37C)
#define	REG_PHY_RXTD_ANT2_PM_SPURC_MEM_LOAD_0                 (PHY_RXTD_ANT2_BASE_ADDRESS + 0x380)
#define	REG_PHY_RXTD_ANT2_PM_SPURC_MEM_M_R_31_0_0             (PHY_RXTD_ANT2_BASE_ADDRESS + 0x384)
#define	REG_PHY_RXTD_ANT2_PM_SPURC_MEM_M_R_37_32_0            (PHY_RXTD_ANT2_BASE_ADDRESS + 0x388)
#define	REG_PHY_RXTD_ANT2_PM_SPURC_MEM_M_I_31_0_0             (PHY_RXTD_ANT2_BASE_ADDRESS + 0x38C)
#define	REG_PHY_RXTD_ANT2_PM_SPURC_MEM_M_I_37_32_0            (PHY_RXTD_ANT2_BASE_ADDRESS + 0x390)
#define	REG_PHY_RXTD_ANT2_PM_SPURC_MEM_NSAMP_0                (PHY_RXTD_ANT2_BASE_ADDRESS + 0x394)
#define	REG_PHY_RXTD_ANT2_PM_SPURC_MEM_DIG_GAIN_0             (PHY_RXTD_ANT2_BASE_ADDRESS + 0x398)
#define	REG_PHY_RXTD_ANT2_PM_SPURC_MEM_ALPHA_IDX_0            (PHY_RXTD_ANT2_BASE_ADDRESS + 0x39C)
#define	REG_PHY_RXTD_ANT2_PM_SPURC_ALPHA_STEP_0_0             (PHY_RXTD_ANT2_BASE_ADDRESS + 0x3A0)
#define	REG_PHY_RXTD_ANT2_PM_SPURC_ALPHA_STEP_1_0             (PHY_RXTD_ANT2_BASE_ADDRESS + 0x3A4)
#define	REG_PHY_RXTD_ANT2_PM_SPURC_ALPHA_STEP_2_0             (PHY_RXTD_ANT2_BASE_ADDRESS + 0x3A8)
#define	REG_PHY_RXTD_ANT2_PM_SPURC_ALPHA_STEP_3_0             (PHY_RXTD_ANT2_BASE_ADDRESS + 0x3AC)
#define	REG_PHY_RXTD_ANT2_PM_SPURC_ALPHA_STEP_4_0             (PHY_RXTD_ANT2_BASE_ADDRESS + 0x3B0)
#define	REG_PHY_RXTD_ANT2_PM_SPURC_ALPHA_STEP_5_0             (PHY_RXTD_ANT2_BASE_ADDRESS + 0x3B4)
#define	REG_PHY_RXTD_ANT2_PM_SPURC_ALPHA_STEP_6_0             (PHY_RXTD_ANT2_BASE_ADDRESS + 0x3B8)
#define	REG_PHY_RXTD_ANT2_PM_SPURC_ALPHA_STEP_7_0             (PHY_RXTD_ANT2_BASE_ADDRESS + 0x3BC)
#define	REG_PHY_RXTD_ANT2_PM_SPURC_ALPHA_STEP_8_0             (PHY_RXTD_ANT2_BASE_ADDRESS + 0x3C0)
#define	REG_PHY_RXTD_ANT2_PM_SPURC_ALPHA_STEP_9_0             (PHY_RXTD_ANT2_BASE_ADDRESS + 0x3C4)
#define	REG_PHY_RXTD_ANT2_PM_SPURC_ALPHA_STEP_10_0            (PHY_RXTD_ANT2_BASE_ADDRESS + 0x3C8)
#define	REG_PHY_RXTD_ANT2_PM_SPURC_ALPHA_STEP_11_0            (PHY_RXTD_ANT2_BASE_ADDRESS + 0x3CC)
#define	REG_PHY_RXTD_ANT2_PM_SPURC_ALPHA_STEP_12_0            (PHY_RXTD_ANT2_BASE_ADDRESS + 0x3D0)
#define	REG_PHY_RXTD_ANT2_PM_SPURC_ALPHA_STEP_13_0            (PHY_RXTD_ANT2_BASE_ADDRESS + 0x3D4)
#define	REG_PHY_RXTD_ANT2_PM_SPURC_ALPHA_STEP_14_0            (PHY_RXTD_ANT2_BASE_ADDRESS + 0x3D8)
#define	REG_PHY_RXTD_ANT2_PM_SPURC_ALPHA_STEP_15_0            (PHY_RXTD_ANT2_BASE_ADDRESS + 0x3DC)
#define	REG_PHY_RXTD_ANT2_PM_SPURC_ALPHA_TIME_0_0             (PHY_RXTD_ANT2_BASE_ADDRESS + 0x3E0)
#define	REG_PHY_RXTD_ANT2_PM_SPURC_ALPHA_TIME_1_0             (PHY_RXTD_ANT2_BASE_ADDRESS + 0x3E4)
#define	REG_PHY_RXTD_ANT2_PM_SPURC_ALPHA_TIME_2_0             (PHY_RXTD_ANT2_BASE_ADDRESS + 0x3E8)
#define	REG_PHY_RXTD_ANT2_PM_SPURC_ALPHA_TIME_3_0             (PHY_RXTD_ANT2_BASE_ADDRESS + 0x3EC)
#define	REG_PHY_RXTD_ANT2_PM_SPURC_ALPHA_TIME_4_0             (PHY_RXTD_ANT2_BASE_ADDRESS + 0x3F0)
#define	REG_PHY_RXTD_ANT2_PM_SPURC_ALPHA_TIME_5_0             (PHY_RXTD_ANT2_BASE_ADDRESS + 0x3F4)
#define	REG_PHY_RXTD_ANT2_PM_SPURC_ALPHA_TIME_6_0             (PHY_RXTD_ANT2_BASE_ADDRESS + 0x3F8)
#define	REG_PHY_RXTD_ANT2_PM_SPURC_ALPHA_TIME_7_0             (PHY_RXTD_ANT2_BASE_ADDRESS + 0x3FC)
#define	REG_PHY_RXTD_ANT2_PM_SPURC_ALPHA_TIME_8_0             (PHY_RXTD_ANT2_BASE_ADDRESS + 0x400)
#define	REG_PHY_RXTD_ANT2_PM_SPURC_ALPHA_TIME_9_0             (PHY_RXTD_ANT2_BASE_ADDRESS + 0x404)
#define	REG_PHY_RXTD_ANT2_PM_SPURC_ALPHA_TIME_10_0            (PHY_RXTD_ANT2_BASE_ADDRESS + 0x408)
#define	REG_PHY_RXTD_ANT2_PM_SPURC_ALPHA_TIME_11_0            (PHY_RXTD_ANT2_BASE_ADDRESS + 0x40C)
#define	REG_PHY_RXTD_ANT2_PM_SPURC_ALPHA_TIME_12_0            (PHY_RXTD_ANT2_BASE_ADDRESS + 0x410)
#define	REG_PHY_RXTD_ANT2_PM_SPURC_ALPHA_TIME_13_0            (PHY_RXTD_ANT2_BASE_ADDRESS + 0x414)
#define	REG_PHY_RXTD_ANT2_PM_SPURC_ALPHA_TIME_14_0            (PHY_RXTD_ANT2_BASE_ADDRESS + 0x418)
#define	REG_PHY_RXTD_ANT2_PM_SPURC_ALPHA_TIME_15_0            (PHY_RXTD_ANT2_BASE_ADDRESS + 0x41C)
#define	REG_PHY_RXTD_ANT2_PM_SPURC_NSAMP_THR_1                (PHY_RXTD_ANT2_BASE_ADDRESS + 0x420)
#define	REG_PHY_RXTD_ANT2_PM_SPURC_POW_THR_LOW_1              (PHY_RXTD_ANT2_BASE_ADDRESS + 0x424)
#define	REG_PHY_RXTD_ANT2_PM_SPURC_POW_THR_HIGH_1             (PHY_RXTD_ANT2_BASE_ADDRESS + 0x428)
#define	REG_PHY_RXTD_ANT2_PM_SPURC_CONTROL_1                  (PHY_RXTD_ANT2_BASE_ADDRESS + 0x42C)
#define	REG_PHY_RXTD_ANT2_PM_SPURC_GAIN_TIMER_1               (PHY_RXTD_ANT2_BASE_ADDRESS + 0x430)
#define	REG_PHY_RXTD_ANT2_PM_SPURC_DDFS_PHASE_ADJUST_1        (PHY_RXTD_ANT2_BASE_ADDRESS + 0x434)
#define	REG_PHY_RXTD_ANT2_PM_SPURC_DDFS_PHASE_INIT_1          (PHY_RXTD_ANT2_BASE_ADDRESS + 0x438)
#define	REG_PHY_RXTD_ANT2_PM_SPURC_DDFS_FCW_1                 (PHY_RXTD_ANT2_BASE_ADDRESS + 0x43C)
#define	REG_PHY_RXTD_ANT2_PM_SPURC_DDFS_P_Q_1                 (PHY_RXTD_ANT2_BASE_ADDRESS + 0x440)
#define	REG_PHY_RXTD_ANT2_PM_SPURC_MEM_RESET_1                (PHY_RXTD_ANT2_BASE_ADDRESS + 0x444)
#define	REG_PHY_RXTD_ANT2_PM_SPURC_MEM_LOAD_1                 (PHY_RXTD_ANT2_BASE_ADDRESS + 0x448)
#define	REG_PHY_RXTD_ANT2_PM_SPURC_MEM_M_R_31_0_1             (PHY_RXTD_ANT2_BASE_ADDRESS + 0x44C)
#define	REG_PHY_RXTD_ANT2_PM_SPURC_MEM_M_R_37_32_1            (PHY_RXTD_ANT2_BASE_ADDRESS + 0x450)
#define	REG_PHY_RXTD_ANT2_PM_SPURC_MEM_M_I_31_0_1             (PHY_RXTD_ANT2_BASE_ADDRESS + 0x454)
#define	REG_PHY_RXTD_ANT2_PM_SPURC_MEM_M_I_37_32_1            (PHY_RXTD_ANT2_BASE_ADDRESS + 0x458)
#define	REG_PHY_RXTD_ANT2_PM_SPURC_MEM_NSAMP_1                (PHY_RXTD_ANT2_BASE_ADDRESS + 0x45C)
#define	REG_PHY_RXTD_ANT2_PM_SPURC_MEM_DIG_GAIN_1             (PHY_RXTD_ANT2_BASE_ADDRESS + 0x460)
#define	REG_PHY_RXTD_ANT2_PM_SPURC_MEM_ALPHA_IDX_1            (PHY_RXTD_ANT2_BASE_ADDRESS + 0x464)
#define	REG_PHY_RXTD_ANT2_PM_SPURC_ALPHA_STEP_0_1             (PHY_RXTD_ANT2_BASE_ADDRESS + 0x468)
#define	REG_PHY_RXTD_ANT2_PM_SPURC_ALPHA_STEP_1_1             (PHY_RXTD_ANT2_BASE_ADDRESS + 0x46C)
#define	REG_PHY_RXTD_ANT2_PM_SPURC_ALPHA_STEP_2_1             (PHY_RXTD_ANT2_BASE_ADDRESS + 0x470)
#define	REG_PHY_RXTD_ANT2_PM_SPURC_ALPHA_STEP_3_1             (PHY_RXTD_ANT2_BASE_ADDRESS + 0x474)
#define	REG_PHY_RXTD_ANT2_PM_SPURC_ALPHA_STEP_4_1             (PHY_RXTD_ANT2_BASE_ADDRESS + 0x478)
#define	REG_PHY_RXTD_ANT2_PM_SPURC_ALPHA_STEP_5_1             (PHY_RXTD_ANT2_BASE_ADDRESS + 0x47C)
#define	REG_PHY_RXTD_ANT2_PM_SPURC_ALPHA_STEP_6_1             (PHY_RXTD_ANT2_BASE_ADDRESS + 0x480)
#define	REG_PHY_RXTD_ANT2_PM_SPURC_ALPHA_STEP_7_1             (PHY_RXTD_ANT2_BASE_ADDRESS + 0x484)
#define	REG_PHY_RXTD_ANT2_PM_SPURC_ALPHA_STEP_8_1             (PHY_RXTD_ANT2_BASE_ADDRESS + 0x488)
#define	REG_PHY_RXTD_ANT2_PM_SPURC_ALPHA_STEP_9_1             (PHY_RXTD_ANT2_BASE_ADDRESS + 0x48C)
#define	REG_PHY_RXTD_ANT2_PM_SPURC_ALPHA_STEP_10_1            (PHY_RXTD_ANT2_BASE_ADDRESS + 0x490)
#define	REG_PHY_RXTD_ANT2_PM_SPURC_ALPHA_STEP_11_1            (PHY_RXTD_ANT2_BASE_ADDRESS + 0x494)
#define	REG_PHY_RXTD_ANT2_PM_SPURC_ALPHA_STEP_12_1            (PHY_RXTD_ANT2_BASE_ADDRESS + 0x498)
#define	REG_PHY_RXTD_ANT2_PM_SPURC_ALPHA_STEP_13_1            (PHY_RXTD_ANT2_BASE_ADDRESS + 0x49C)
#define	REG_PHY_RXTD_ANT2_PM_SPURC_ALPHA_STEP_14_1            (PHY_RXTD_ANT2_BASE_ADDRESS + 0x4A0)
#define	REG_PHY_RXTD_ANT2_PM_SPURC_ALPHA_STEP_15_1            (PHY_RXTD_ANT2_BASE_ADDRESS + 0x4A4)
#define	REG_PHY_RXTD_ANT2_PM_SPURC_ALPHA_TIME_0_1             (PHY_RXTD_ANT2_BASE_ADDRESS + 0x4A8)
#define	REG_PHY_RXTD_ANT2_PM_SPURC_ALPHA_TIME_1_1             (PHY_RXTD_ANT2_BASE_ADDRESS + 0x4AC)
#define	REG_PHY_RXTD_ANT2_PM_SPURC_ALPHA_TIME_2_1             (PHY_RXTD_ANT2_BASE_ADDRESS + 0x4B0)
#define	REG_PHY_RXTD_ANT2_PM_SPURC_ALPHA_TIME_3_1             (PHY_RXTD_ANT2_BASE_ADDRESS + 0x4B4)
#define	REG_PHY_RXTD_ANT2_PM_SPURC_ALPHA_TIME_4_1             (PHY_RXTD_ANT2_BASE_ADDRESS + 0x4B8)
#define	REG_PHY_RXTD_ANT2_PM_SPURC_ALPHA_TIME_5_1             (PHY_RXTD_ANT2_BASE_ADDRESS + 0x4BC)
#define	REG_PHY_RXTD_ANT2_PM_SPURC_ALPHA_TIME_6_1             (PHY_RXTD_ANT2_BASE_ADDRESS + 0x4C0)
#define	REG_PHY_RXTD_ANT2_PM_SPURC_ALPHA_TIME_7_1             (PHY_RXTD_ANT2_BASE_ADDRESS + 0x4C4)
#define	REG_PHY_RXTD_ANT2_PM_SPURC_ALPHA_TIME_8_1             (PHY_RXTD_ANT2_BASE_ADDRESS + 0x4C8)
#define	REG_PHY_RXTD_ANT2_PM_SPURC_ALPHA_TIME_9_1             (PHY_RXTD_ANT2_BASE_ADDRESS + 0x4CC)
#define	REG_PHY_RXTD_ANT2_PM_SPURC_ALPHA_TIME_10_1            (PHY_RXTD_ANT2_BASE_ADDRESS + 0x4D0)
#define	REG_PHY_RXTD_ANT2_PM_SPURC_ALPHA_TIME_11_1            (PHY_RXTD_ANT2_BASE_ADDRESS + 0x4D4)
#define	REG_PHY_RXTD_ANT2_PM_SPURC_ALPHA_TIME_12_1            (PHY_RXTD_ANT2_BASE_ADDRESS + 0x4D8)
#define	REG_PHY_RXTD_ANT2_PM_SPURC_ALPHA_TIME_13_1            (PHY_RXTD_ANT2_BASE_ADDRESS + 0x4DC)
#define	REG_PHY_RXTD_ANT2_PM_SPURC_ALPHA_TIME_14_1            (PHY_RXTD_ANT2_BASE_ADDRESS + 0x4E0)
#define	REG_PHY_RXTD_ANT2_PM_SPURC_ALPHA_TIME_15_1            (PHY_RXTD_ANT2_BASE_ADDRESS + 0x4E4)
#define	REG_PHY_RXTD_ANT2_PM_RXTD_SPURC_RAM_RM_0              (PHY_RXTD_ANT2_BASE_ADDRESS + 0x4E8)
#define	REG_PHY_RXTD_ANT2_PM_RXTD_SPURC_RAM_RM_1              (PHY_RXTD_ANT2_BASE_ADDRESS + 0x4EC)
#define	REG_PHY_RXTD_ANT2_PM_RXTD_SPURC_GAIN_WORD             (PHY_RXTD_ANT2_BASE_ADDRESS + 0x4F0)
#define	REG_PHY_RXTD_ANT2_PM_WHITE_NOISE                      (PHY_RXTD_ANT2_BASE_ADDRESS + 0x4F4)
#define	REG_PHY_RXTD_ANT2_PM_WHITE_NOISE_SEED                 (PHY_RXTD_ANT2_BASE_ADDRESS + 0x4F8)
#define	REG_PHY_RXTD_ANT2_PM_NOTCH_SPUR_BANDSEL_EN            (PHY_RXTD_ANT2_BASE_ADDRESS + 0x4FC)
#define	REG_PHY_RXTD_ANT2_PM_BANDSELECT_IIR_ALPHA             (PHY_RXTD_ANT2_BASE_ADDRESS + 0x500)
#define	REG_PHY_RXTD_ANT2_PM_NOTCH_SPUR_MAIN_EN               (PHY_RXTD_ANT2_BASE_ADDRESS + 0x504)
#define	REG_PHY_RXTD_ANT2_PM_MAIN_IIR_ALPHA                   (PHY_RXTD_ANT2_BASE_ADDRESS + 0x508)
#define	REG_PHY_RXTD_ANT2_PM_NOTCH_SPUR_BYPASS_THR_20         (PHY_RXTD_ANT2_BASE_ADDRESS + 0x50C)
#define	REG_PHY_RXTD_ANT2_PM_NOTCH_SPUR_BYPASS_THR_40         (PHY_RXTD_ANT2_BASE_ADDRESS + 0x510)
#define	REG_PHY_RXTD_ANT2_PM_NOTCH_SPUR_BYPASS_THR_80         (PHY_RXTD_ANT2_BASE_ADDRESS + 0x514)
#define	REG_PHY_RXTD_ANT2_PM_NOTCH_SPUR_BYPASS_THR_160_320    (PHY_RXTD_ANT2_BASE_ADDRESS + 0x518)
#define	REG_PHY_RXTD_ANT2_PM_NOTCH_SPUR_BYPASS_SRC_CURR       (PHY_RXTD_ANT2_BASE_ADDRESS + 0x51C)
#define	REG_PHY_RXTD_ANT2_PM_NOTCH_SPUR_FREQ_OFFSET           (PHY_RXTD_ANT2_BASE_ADDRESS + 0x520)
#define	REG_PHY_RXTD_ANT2_PM_ACIDET_PWR                       (PHY_RXTD_ANT2_BASE_ADDRESS + 0x524)
#define	REG_PHY_RXTD_ANT2_PM_NOTCH_SPUR_BYPASS_CURR_ANT       (PHY_RXTD_ANT2_BASE_ADDRESS + 0x528)
#define	REG_PHY_RXTD_ANT2_PM_NOTCH_SPUR_MAIN_BYPASS           (PHY_RXTD_ANT2_BASE_ADDRESS + 0x52C)
/*---------------------------------------------------------------------------------
/						Data Type Definition										
/----------------------------------------------------------------------------------*/
/*REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG00 0x0 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 freqShiftSig3Bypass : 1; //freq_shift_sig3_bypass, reset value: 0x0, access type: RW
		uint32 reserved0 : 31;
	} bitFields;
} RegPhyRxtdAnt2PhyRxtdAntReg00_u;

/*REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG01 0x4 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 iqMismatchBypassIir : 1; //IQ Mismatch IIR Bypass, reset value: 0x0, access type: RW
		uint32 iqMismatchBypassEq : 1; //IQ Mismatch Equalizer Bypass, reset value: 0x0, access type: RW
		uint32 iqMismatchBypassEqI2Q : 1; //no description, reset value: 0x0, access type: RW
		uint32 reserved0 : 1;
		uint32 iqW12ModSel : 1; //iq decorrelator w1 w2 coefficient mode selection: , 0: iq_w1_mod0, iq_w2_mod0 , 1: iq_w1_mod1, iq_w2_mod1, reset value: 0x0, access type: RW
		uint32 reserved1 : 27;
	} bitFields;
} RegPhyRxtdAnt2PhyRxtdAntReg01_u;

/*REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG02 0x8 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 iqMismatchIirMu : 4; //IQ Mismatch IIR Mu I, reset value: 0x0, access type: RW
		uint32 reserved0 : 20;
		uint32 iqMismatchEstRegularISum : 1; //Rx TD IQ Mismatch I regular sum (not sqr), reset value: 0x0, access type: RW
		uint32 reserved1 : 3;
		uint32 iqMismatchEstRegularQSum : 1; //Rx TD IQ Mismatch Q regular sum (not sqr), reset value: 0x0, access type: RW
		uint32 reserved2 : 3;
	} bitFields;
} RegPhyRxtdAnt2PhyRxtdAntReg02_u;

/*REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG03 0xC */
typedef union
{
	uint32 val;
	struct
	{
		uint32 reserved0 : 4;
		uint32 iqMismatchEqLengthQ : 3; //IQ equalizer FIR Q-path delay. , Range is 0 to 6. , Usually configured according to RF BW: , 1: BW = 20, 40 , 2: BW = 80, 160 , 4: BW = 320 , Should be similar to IQ equalizer FIR center tap (5th element) delay (iq_fir_delay)., reset value: 0x2, access type: RW
		uint32 reserved1 : 25;
	} bitFields;
} RegPhyRxtdAnt2PhyRxtdAntReg03_u;

/*REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG04 0x10 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 iqMismatchEstAccCounter : 24; //IQ Mismatch Est Acc Counter, reset value: 0x0, access type: RW
		uint32 reserved0 : 8;
	} bitFields;
} RegPhyRxtdAnt2PhyRxtdAntReg04_u;

/*REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG05 0x14 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 reserved0 : 4;
		uint32 iqMismatchEstStartWork : 1; //IQ Mismatch Est Start Work, reset value: 0x0, access type: WO
		uint32 reserved1 : 3;
		uint32 iqMismatchEstResetRegs : 1; //IQ Mismatch Est Reset Regs, reset value: 0x0, access type: RW
		uint32 reserved2 : 3;
		uint32 iqMismatchEstValidIq : 1; //Rx TD IQ Mismatch Est valid, reset value: 0x0, access type: RO
		uint32 reserved3 : 19;
	} bitFields;
} RegPhyRxtdAnt2PhyRxtdAntReg05_u;

/*REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG06 0x18 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 iqMismatchEstRegIi : 32; //IQ Mismatch Est Reg II low, reset value: 0x0, access type: RO
	} bitFields;
} RegPhyRxtdAnt2PhyRxtdAntReg06_u;

/*REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG07 0x1C */
typedef union
{
	uint32 val;
	struct
	{
		uint32 iqMismatchEstRegQq : 32; //IQ Mismatch Est Reg QQ low, reset value: 0x0, access type: RO
	} bitFields;
} RegPhyRxtdAnt2PhyRxtdAntReg07_u;

/*REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG08 0x20 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 iqMismatchEstRegIq : 32; //IQ Mismatch Est Reg IQ low, reset value: 0x0, access type: RO
	} bitFields;
} RegPhyRxtdAnt2PhyRxtdAntReg08_u;

/*REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG09 0x24 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 rxIqSwap : 1; //IQ Swap, reset value: 0x0, access type: RW
		uint32 reserved0 : 31;
	} bitFields;
} RegPhyRxtdAnt2PhyRxtdAntReg09_u;

/*REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG0A 0x28 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 reserved0 : 4;
		uint32 rxSpectrumFlip : 1; //Spectrum flip, reset value: 0x0, access type: RW
		uint32 reserved1 : 27;
	} bitFields;
} RegPhyRxtdAnt2PhyRxtdAntReg0A_u;

/*REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG0B 0x2C */
typedef union
{
	uint32 val;
	struct
	{
		uint32 geortzelResetAcum : 1; //Geortzel Reset Acumulator., reset value: 0x0, access type: WO
		uint32 reserved0 : 31;
	} bitFields;
} RegPhyRxtdAnt2PhyRxtdAntReg0B_u;

/*REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG0C 0x30 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 reserved0 : 12;
		uint32 geortzelLength : 12; //geortzel_length, reset value: 0x0, access type: RW
		uint32 reserved1 : 8;
	} bitFields;
} RegPhyRxtdAnt2PhyRxtdAntReg0C_u;

/*REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG0D 0x34 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 geortzel0MulI : 14; //Geortzel 0 Mult I Data., reset value: 0x0, access type: RW
		uint32 reserved0 : 2;
		uint32 geortzel0MulQ : 14; //Geortzel 0 Mult Q Data., reset value: 0x0, access type: RW
		uint32 reserved1 : 2;
	} bitFields;
} RegPhyRxtdAnt2PhyRxtdAntReg0D_u;

/*REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG0E 0x38 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 geortzel1MulI : 14; //Geortzel 1 Mult I Data., reset value: 0x0, access type: RW
		uint32 reserved0 : 2;
		uint32 geortzel1MulQ : 14; //Geortzel 1 Mult Q Data., reset value: 0x0, access type: RW
		uint32 reserved1 : 2;
	} bitFields;
} RegPhyRxtdAnt2PhyRxtdAntReg0E_u;

/*REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG0F 0x3C */
typedef union
{
	uint32 val;
	struct
	{
		uint32 geortzel0CplxMode : 1; //no description, reset value: 0x0, access type: RW
		uint32 geortzel1CplxMode : 1; //no description, reset value: 0x0, access type: RW
		uint32 reserved0 : 6;
		uint32 geortzelValidThr : 7; //Geortzel Valid Threshold., reset value: 0x0, access type: RW
		uint32 reserved1 : 17;
	} bitFields;
} RegPhyRxtdAnt2PhyRxtdAntReg0F_u;

/*REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG10 0x40 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 iqEqTap0 : 10; //IQ Mismatch Equalizer Calibration Coefficient Num 0., reset value: 0x0, access type: RW
		uint32 reserved0 : 22;
	} bitFields;
} RegPhyRxtdAnt2PhyRxtdAntReg10_u;

/*REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG11 0x44 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 iqEqTap1 : 10; //IQ Mismatch Equalizer Calibration Coefficient Num 1., reset value: 0x0, access type: RW
		uint32 reserved0 : 22;
	} bitFields;
} RegPhyRxtdAnt2PhyRxtdAntReg11_u;

/*REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG12 0x48 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 iqEqTap2 : 10; //IQ Mismatch Equalizer Calibration Coefficient Num 2., reset value: 0x0, access type: RW
		uint32 reserved0 : 22;
	} bitFields;
} RegPhyRxtdAnt2PhyRxtdAntReg12_u;

/*REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG13 0x4C */
typedef union
{
	uint32 val;
	struct
	{
		uint32 iqEqTap3 : 10; //IQ Mismatch Equalizer Calibration Coefficient Num 3., reset value: 0x0, access type: RW
		uint32 reserved0 : 22;
	} bitFields;
} RegPhyRxtdAnt2PhyRxtdAntReg13_u;

/*REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG14 0x50 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 iqEqTap4 : 10; //IQ Mismatch Equalizer Calibration Coefficient Num 4., reset value: 0x0, access type: RW
		uint32 reserved0 : 22;
	} bitFields;
} RegPhyRxtdAnt2PhyRxtdAntReg14_u;

/*REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG15 0x54 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 iqEqTap5 : 10; //IQ Mismatch Equalizer Calibration Coefficient Num 5., reset value: 0x0, access type: RW
		uint32 reserved0 : 22;
	} bitFields;
} RegPhyRxtdAnt2PhyRxtdAntReg15_u;

/*REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG16 0x58 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 iqEqTap6 : 10; //IQ Mismatch Equalizer Calibration Coefficient Num 6., reset value: 0x0, access type: RW
		uint32 reserved0 : 22;
	} bitFields;
} RegPhyRxtdAnt2PhyRxtdAntReg16_u;

/*REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG17 0x5C */
typedef union
{
	uint32 val;
	struct
	{
		uint32 iqEqTap7 : 10; //IQ Mismatch Equalizer Calibration Coefficient Num 7., reset value: 0x0, access type: RW
		uint32 reserved0 : 22;
	} bitFields;
} RegPhyRxtdAnt2PhyRxtdAntReg17_u;

/*REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG18 0x60 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 iqEqTap8 : 10; //IQ Mismatch Equalizer Calibration Coefficient Num 8., reset value: 0x0, access type: RW
		uint32 reserved0 : 22;
	} bitFields;
} RegPhyRxtdAnt2PhyRxtdAntReg18_u;

/*REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG19 0x64 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 iqEqTap9 : 10; //IQ Mismatch Equalizer Calibration Coefficient Num 9., reset value: 0x0, access type: RW
		uint32 reserved0 : 22;
	} bitFields;
} RegPhyRxtdAnt2PhyRxtdAntReg19_u;

/*REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG1A 0x68 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 iqEqTap10 : 10; //IQ Mismatch Equalizer Calibration Coefficient Num 10., reset value: 0x0, access type: RW
		uint32 reserved0 : 22;
	} bitFields;
} RegPhyRxtdAnt2PhyRxtdAntReg1A_u;

/*REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG1B 0x6C */
typedef union
{
	uint32 val;
	struct
	{
		uint32 iqEqTap11 : 10; //IQ Mismatch Equalizer Calibration Coefficient Num 11., reset value: 0x0, access type: RW
		uint32 reserved0 : 22;
	} bitFields;
} RegPhyRxtdAnt2PhyRxtdAntReg1B_u;

/*REG_PHY_RXTD_ANT2_OLA_CONTROL 0x70 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 olaMode : 3; //ola mode: 0 -256, 1-512, 2-1024, 3-2048, 4-4096, reset value: 0x0, access type: RW
		uint32 reserved0 : 1;
		uint32 olaFftInShift : 3; //Rx TD fft in shift OLA, reset value: 0x0, access type: RW
		uint32 olaFftInMult : 1; //Rx TD fft in mult OLA, reset value: 0x0, access type: RW
		uint32 olaNumOfWindows : 5; //2^(ola number of windows ), reset value: 0x0, access type: RW
		uint32 reserved1 : 3;
		uint32 olaZeroInput : 2; //ola zero input: , 00- regular mode , 01- Q-part zero , 10- I part zero, reset value: 0x0, access type: RW
		uint32 reserved2 : 2;
		uint32 olaRound : 5; //ola round parameter, reset value: 0x0, access type: RW
		uint32 reserved3 : 3;
		uint32 olaSource : 3; //0-ola_ib, 1-ola_bb, 2-ola_hb, 3-ola rssi,4-ola_dfs, reset value: 0x0, access type: RW
		uint32 reserved4 : 1;
	} bitFields;
} RegPhyRxtdAnt2OlaControl_u;

/*REG_PHY_RXTD_ANT2_OLA_START 0x78 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 olaStart : 1; //ola_start_an0 pulse, reset value: 0x0, access type: WO
		uint32 reserved0 : 31;
	} bitFields;
} RegPhyRxtdAnt2OlaStart_u;

/*REG_PHY_RXTD_ANT2_OLA_STATUS 0x7C */
typedef union
{
	uint32 val;
	struct
	{
		uint32 olaState : 3; //ola_state: , 000 - IDLE , 001 - FIRST WINDOW , 010 - LAST WINDOW , 011 - REGULAR WINDOW , 100 - FIRST LAST WINDOW , 101 - End OF WINDOWS , 110 - FFT working , 111 - dump to test bus, reset value: 0x0, access type: RO
		uint32 reserved0 : 1;
		uint32 olaDone : 1; //ola_done_an0 level, reset value: 0x0, access type: RO
		uint32 reserved1 : 27;
	} bitFields;
} RegPhyRxtdAnt2OlaStatus_u;

/*REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG20 0x80 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 reserved0 : 20;
		uint32 iqCoefRm : 3; //iq_coef_rm, reset value: 0x3, access type: RW
		uint32 reserved1 : 9;
	} bitFields;
} RegPhyRxtdAnt2PhyRxtdAntReg20_u;

/*REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG21 0x84 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 rxFifoRm : 3; //rx_fifo_rm, reset value: 0x3, access type: RW
		uint32 fft0Rm : 3; //fft_0_rm, reset value: 0x3, access type: RW
		uint32 fft1Rm : 3; //fft_1_rm, reset value: 0x3, access type: RW
		uint32 bandselFirDpmemRm : 3; //bandsel_fir_dpmem_rm, reset value: 0x3, access type: RW
		uint32 chanfiltMidDelayFifoRm : 3; //chanfilt_mid_delay_fifo_rm, reset value: 0x3, access type: RW
		uint32 chanfiltCoeffLutRm : 3; //chanfilt_coeff_lut_rm, reset value: 0x3, access type: RW
		uint32 bandselFirCoeffRm : 3; //bandsel_fir_coeff_rm, reset value: 0x3, access type: RW
		uint32 iirMemRm : 3; //iir_mem_rm, reset value: 0x3, access type: RW
		uint32 rxFifo2Rm : 3; //rx_fifo_2_rm, reset value: 0x3, access type: RW
		uint32 reserved0 : 5;
	} bitFields;
} RegPhyRxtdAnt2PhyRxtdAntReg21_u;

/*REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG22 0x88 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 dcRegI : 18; //dc_reg_i_an0, reset value: 0x0, access type: RO
		uint32 dcRemovalBypass : 1; //no description, reset value: 0x0, access type: RO
		uint32 reserved0 : 13;
	} bitFields;
} RegPhyRxtdAnt2PhyRxtdAntReg22_u;

/*REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG23 0x8C */
typedef union
{
	uint32 val;
	struct
	{
		uint32 dcRegQ : 18; //dc_reg_q_an0, reset value: 0x0, access type: RO
		uint32 reserved0 : 14;
	} bitFields;
} RegPhyRxtdAnt2PhyRxtdAntReg23_u;

/*REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG24 0x90 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 reserved0 : 1;
		uint32 iqFdlBypass : 1; //iq_fdl_bypass, reset value: 0x0, access type: RW
		uint32 iqFdlBypassRam : 1; //iq_fdl_bypass_ram, reset value: 0x0, access type: RW
		uint32 reserved1 : 29;
	} bitFields;
} RegPhyRxtdAnt2PhyRxtdAntReg24_u;

/*REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG25 0x94 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 reserved0 : 1;
		uint32 iqEqBypassRam : 1; //IQ equalizer bypass RAM. Use cofficients from prog model, reset value: 0x0, access type: RW
		uint32 iqW12Bypass : 1; //IQ W1, W2 De-correlator bypass, reset value: 0x0, access type: RW
		uint32 iqPgcFromAgcAcc : 1; //select PGC1,PGC2 source: , 0-progmodels, 1-AGC accelerator, reset value: 0x0, access type: RW
		uint32 reserved1 : 1;
		uint32 iqFirDecorOrder : 1; //0: FIR -> Decorrelator , 1: Decorrelator -> FIR, reset value: 0x1, access type: RW
		uint32 reserved2 : 26;
	} bitFields;
} RegPhyRxtdAnt2PhyRxtdAntReg25_u;

/*REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG26 0x98 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 iqMismatchEstRate : 1; //w1,w2 estimator work before (1 - @320MHz) or after the decimation filter (0 - @160MHZ), reset value: 0x0, access type: RW
		uint32 iqMismatchAccumRssi : 1; //use iq_mismatch w12_estimator's accumulator to accumulate rssi_data, reset value: 0x0, access type: RW
		uint32 iqMismatchEstIqFixSelect : 1; //Select input for IQ Estimator: 0 = Decimation Filter output, 1 = IQ-Fix output , , reset value: 0x0, access type: RW
		uint32 iqMismatchEstCalibtrationsCorrSelect : 1; //Select input for IQ Estimator: 0 = WAV700 Cal mode input rate 640MHz, 1 = WAV600-2 input modes after prefilter , , reset value: 0x1, access type: RW
		uint32 iqMismatchEstShift : 4; //w1,w2 estimator shift value antenna 0, reset value: 0x0, access type: RW
		uint32 reserved0 : 24;
	} bitFields;
} RegPhyRxtdAnt2PhyRxtdAntReg26_u;

/*REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG27 0x9C */
typedef union
{
	uint32 val;
	struct
	{
		uint32 iqMismatchEstOfIi : 1; //OverFlow indication on i^2 32-bit accumulation antenna 0, reset value: 0x0, access type: RO
		uint32 iqMismatchEstOfQq : 1; //OverFlow indication on q^2 32-bit accumulation antenna 0, reset value: 0x0, access type: RO
		uint32 iqMismatchEstOfIq : 1; //OverFlow indication on i*q 32-bit accumulation antenna 0, reset value: 0x0, access type: RO
		uint32 reserved0 : 29;
	} bitFields;
} RegPhyRxtdAnt2PhyRxtdAntReg27_u;

/*REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG28 0xA0 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 iqRamReadTrigger : 1; //Upon writing '1' a RAM read is performed into IQ coefficients, reset value: 0x0, access type: WO
		uint32 reserved0 : 31;
	} bitFields;
} RegPhyRxtdAnt2PhyRxtdAntReg28_u;

/*REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG29 0xA4 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 iqEqUsedTap0 : 10; //IQ Mismatch Equalizer Calibration Coefficient Num 0 used in filter, reset value: 0x0, access type: RO
		uint32 reserved0 : 22;
	} bitFields;
} RegPhyRxtdAnt2PhyRxtdAntReg29_u;

/*REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG2A 0xA8 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 iqEqUsedTap1 : 10; //IQ Mismatch Equalizer Calibration Coefficient Num 1 used in filter, reset value: 0x0, access type: RO
		uint32 reserved0 : 22;
	} bitFields;
} RegPhyRxtdAnt2PhyRxtdAntReg2A_u;

/*REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG2B 0xAC */
typedef union
{
	uint32 val;
	struct
	{
		uint32 iqEqUsedTap2 : 10; //IQ Mismatch Equalizer Calibration Coefficient Num 2 used in filter, reset value: 0x0, access type: RO
		uint32 reserved0 : 22;
	} bitFields;
} RegPhyRxtdAnt2PhyRxtdAntReg2B_u;

/*REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG2C 0xB0 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 iqEqUsedTap3 : 10; //IQ Mismatch Equalizer Calibration Coefficient Num 3 used in filter, reset value: 0x0, access type: RO
		uint32 reserved0 : 22;
	} bitFields;
} RegPhyRxtdAnt2PhyRxtdAntReg2C_u;

/*REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG2D 0xB4 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 iqEqUsedTap4 : 10; //IQ Mismatch Equalizer Calibration Coefficient Num 4 used in filter, reset value: 0x0, access type: RO
		uint32 reserved0 : 22;
	} bitFields;
} RegPhyRxtdAnt2PhyRxtdAntReg2D_u;

/*REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG2E 0xB8 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 iqEqUsedTap5 : 10; //IQ Mismatch Equalizer Calibration Coefficient Num 5 used in filter, reset value: 0x0, access type: RO
		uint32 reserved0 : 22;
	} bitFields;
} RegPhyRxtdAnt2PhyRxtdAntReg2E_u;

/*REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG2F 0xBC */
typedef union
{
	uint32 val;
	struct
	{
		uint32 iqEqUsedTap6 : 10; //IQ Mismatch Equalizer Calibration Coefficient Num 6 used in filter, reset value: 0x0, access type: RO
		uint32 reserved0 : 22;
	} bitFields;
} RegPhyRxtdAnt2PhyRxtdAntReg2F_u;

/*REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG30 0xC0 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 iqEqUsedTap7 : 10; //IQ Mismatch Equalizer Calibration Coefficient Num 7 used in filter, reset value: 0x0, access type: RO
		uint32 reserved0 : 22;
	} bitFields;
} RegPhyRxtdAnt2PhyRxtdAntReg30_u;

/*REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG31 0xC4 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 iqEqUsedTap8 : 10; //IQ Mismatch Equalizer Calibration Coefficient Num 8 used in filter, reset value: 0x0, access type: RO
		uint32 reserved0 : 22;
	} bitFields;
} RegPhyRxtdAnt2PhyRxtdAntReg31_u;

/*REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG32 0xC8 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 iqEqUsedTap9 : 10; //IQ Mismatch Equalizer Calibration Coefficient Num 9 used in filter, reset value: 0x0, access type: RO
		uint32 reserved0 : 22;
	} bitFields;
} RegPhyRxtdAnt2PhyRxtdAntReg32_u;

/*REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG33 0xCC */
typedef union
{
	uint32 val;
	struct
	{
		uint32 iqEqUsedTap10 : 10; //IQ Mismatch Equalizer Calibration Coefficient Num 10 used in filter, reset value: 0x0, access type: RO
		uint32 reserved0 : 22;
	} bitFields;
} RegPhyRxtdAnt2PhyRxtdAntReg33_u;

/*REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG34 0xD0 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 iqEqUsedTap11 : 10; //IQ Mismatch Equalizer Calibration Coefficient Num 11 used in filter, reset value: 0x0, access type: RO
		uint32 reserved0 : 22;
	} bitFields;
} RegPhyRxtdAnt2PhyRxtdAntReg34_u;

/*REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG3B 0xEC */
typedef union
{
	uint32 val;
	struct
	{
		uint32 rxDifi1DcCancelEnable : 1; //DC Cancellation Enable, reset value: 0x0, access type: RW
		uint32 rxDifi1DcCancelHwSelect : 1; //Progmodel or Accelerator, reset value: 0x0, access type: RW
		uint32 rxDifi2RssiGainHwSelect : 1; //Progmodel or Accelerator, reset value: 0x0, access type: RW
		uint32 reserved0 : 29;
	} bitFields;
} RegPhyRxtdAnt2PhyRxtdAntReg3B_u;

/*REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG3C 0xF0 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 difi1DcCancelI : 14; //DC Offset I Ant 1, reset value: 0x0, access type: RW
		uint32 difi1DcCancelQ : 14; //DC Offset Q Ant 1, reset value: 0x0, access type: RW
		uint32 reserved0 : 4;
	} bitFields;
} RegPhyRxtdAnt2PhyRxtdAntReg3C_u;

/*REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG3D 0xF4 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 geortzel0IResult : 30; //Geortzel 0 I Result., reset value: 0x0, access type: RO
		uint32 reserved0 : 2;
	} bitFields;
} RegPhyRxtdAnt2PhyRxtdAntReg3D_u;

/*REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG3E 0xF8 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 geortzel0QResult : 30; //Geortzel 0 Q Result., reset value: 0x0, access type: RO
		uint32 reserved0 : 1;
		uint32 geortzel0DataValid : 1; //Geortzel 0 Data Valid., reset value: 0x0, access type: RO
	} bitFields;
} RegPhyRxtdAnt2PhyRxtdAntReg3E_u;

/*REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG3F 0xFC */
typedef union
{
	uint32 val;
	struct
	{
		uint32 geortzel1IResult : 30; //Geortzel 1 I Result., reset value: 0x0, access type: RO
		uint32 reserved0 : 2;
	} bitFields;
} RegPhyRxtdAnt2PhyRxtdAntReg3F_u;

/*REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG40 0x100 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 geortzel1QResult : 30; //Geortzel 1 Q Result., reset value: 0x0, access type: RO
		uint32 reserved0 : 1;
		uint32 geortzel1DataValid : 1; //Geortzel 1 Data Valid., reset value: 0x0, access type: RO
	} bitFields;
} RegPhyRxtdAnt2PhyRxtdAntReg40_u;

/*REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG41 0x104 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 fftInShift26B : 3; //Rx TD fft in shift 26b, reset value: 0x5, access type: RW
		uint32 fftInShift52B : 3; //Rx TD fft in shift 52b, reset value: 0x7, access type: RW
		uint32 fftInShift106B : 3; //Rx TD fft in shift 106b, reset value: 0x6, access type: RW
		uint32 fftInShift20 : 3; //Rx TD fft in shift for hb2080, reset value: 0x0, access type: RW
		uint32 fftInShift40 : 3; //Rx TD fft in shift for hb4080, reset value: 0x7, access type: RW
		uint32 fftInShift80 : 3; //Rx TD fft in shift for hb80160, reset value: 0x7, access type: RW
		uint32 fftInShift160 : 3; //Rx TD fft in shift for 160, reset value: 0x1, access type: RW
		uint32 fftInShiftHestf : 3; //Rx TD fft in shift for he stf, reset value: 0x6, access type: RW
		uint32 fftInMult26B : 1; //Rx TD fft in mult 26b, reset value: 0x1, access type: RW
		uint32 fftInMult52B : 1; //Rx TD fft in mult 52b, reset value: 0x0, access type: RW
		uint32 fftInMult106B : 1; //Rx TD fft in mult 106b, reset value: 0x1, access type: RW
		uint32 fftInMult20 : 1; //Rx TD fft in mult for hb2080, reset value: 0x0, access type: RW
		uint32 fftInMult40 : 1; //Rx TD fft in mult for hb4080, reset value: 0x1, access type: RW
		uint32 fftInMult80 : 1; //Rx TD fft in mult for hb80160, reset value: 0x1, access type: RW
		uint32 fftInMult160 : 1; //Rx TD fft in mult for 160, reset value: 0x0, access type: RW
		uint32 fftInMultHestf : 1; //Rx TD fft in mult for he stf, reset value: 0x0, access type: RW
	} bitFields;
} RegPhyRxtdAnt2PhyRxtdAntReg41_u;

/*REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG42 0x108 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 rfCalMode : 1; //rf calibration mode, reset value: 0x0, access type: RW
		uint32 reserved0 : 31;
	} bitFields;
} RegPhyRxtdAnt2PhyRxtdAntReg42_u;

/*REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG43 0x10C */
typedef union
{
	uint32 val;
	struct
	{
		uint32 afeTpControl : 2; //timer in 20Mhz from sec detect till primary, reset value: 0x0, access type: RW
		uint32 reserved0 : 2;
		uint32 decimatorTpControl : 1; //decimator hb sensitive:  , 1'b0 all strobe , 1'b1: case hb_mode , CB80: all strobes , HB4080:one every two samples , HB2080:one every four samples, reset value: 0x0, access type: RW
		uint32 reserved1 : 27;
	} bitFields;
} RegPhyRxtdAnt2PhyRxtdAntReg43_u;

/*REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG44 0x110 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 rxDigitalGainEnable : 1; //Digital Gain Enable, reset value: 0x0, access type: RW
		uint32 reserved0 : 31;
	} bitFields;
} RegPhyRxtdAnt2PhyRxtdAntReg44_u;

/*REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG45 0x114 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 memGlobalRm : 2; //mem_global_rm, reset value: 0x0, access type: RW
		uint32 reserved0 : 30;
	} bitFields;
} RegPhyRxtdAnt2PhyRxtdAntReg45_u;

/*REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG46 0x118 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 fcsiGrAddr : 7; //fcsi_gr_addr, reset value: 0x0, access type: RW
		uint32 reserved0 : 1;
		uint32 fcsiGrWrData : 16; //fcsi_gr_wr_data, reset value: 0x0, access type: RW
		uint32 reserved1 : 8;
	} bitFields;
} RegPhyRxtdAnt2PhyRxtdAntReg46_u;

/*REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG47 0x11C */
typedef union
{
	uint32 val;
	struct
	{
		uint32 fcsiRdData : 16; //fcsi_rd_data, reset value: 0x0, access type: RO
		uint32 reserved0 : 16;
	} bitFields;
} RegPhyRxtdAnt2PhyRxtdAntReg47_u;

/*REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG48 0x120 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 fcsiClkWrDivrExtRf : 6; //fcsi_clk_wr_divr_ext_rf, reset value: 0x4, access type: RW
		uint32 reserved0 : 2;
		uint32 fcsiClkRdDivrExtRf : 6; //fcsi_clk_rd_divr_ext_rf, reset value: 0xf, access type: RW
		uint32 reserved1 : 18;
	} bitFields;
} RegPhyRxtdAnt2PhyRxtdAntReg48_u;

/*REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG49 0x124 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 fcsiClkWrDivrAfe : 6; //fcsi_clk_wr_divr_afe, reset value: 0x4, access type: RW
		uint32 reserved0 : 2;
		uint32 fcsiClkRdDivrAfe : 6; //fcsi_clk_rd_divr_afe, reset value: 0xf, access type: RW
		uint32 reserved1 : 18;
	} bitFields;
} RegPhyRxtdAnt2PhyRxtdAntReg49_u;

/*REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG4A 0x128 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 externalRfMode : 1; //external_rf_mode, reset value: 0x1, access type: RW
		uint32 reserved0 : 3;
		uint32 fcsiModeMs : 1; //fcsi_mode_ms, reset value: 0x1, access type: RW
		uint32 fcsiModeRfExt : 1; //fcsi_mode_rf_ext, reset value: 0x1, access type: RW
		uint32 reserved1 : 2;
		uint32 fcsiAdditionalCycles : 4; //fcsi_additional_cycles, reset value: 0x0, access type: RW
		uint32 reserved2 : 20;
	} bitFields;
} RegPhyRxtdAnt2PhyRxtdAntReg4A_u;

/*REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG4B 0x12C */
typedef union
{
	uint32 val;
	struct
	{
		uint32 fcsiMsResetAntennasN : 1; //fcsi_ms_reset_antennas_n, reset value: 0x0, access type: RW
		uint32 reserved0 : 3;
		uint32 fcsiRfResetN : 1; //fcsi_rf_reset_n, reset value: 0x0, access type: RW
		uint32 reserved1 : 27;
	} bitFields;
} RegPhyRxtdAnt2PhyRxtdAntReg4B_u;

/*REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG4C 0x130 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 hypFcsiStateMachine : 3; //hyp_fcsi_state_machine, reset value: 0x0, access type: RO
		uint32 hypFcsiCounter : 5; //hyp_fcsi_counter, reset value: 0x0, access type: RO
		uint32 hypFcsiCounterLimit : 5; //hyp_fcsi_counter_limit, reset value: 0x0, access type: RO
		uint32 hypFcsiClockActive : 1; //hyp_fcsi_clock_active, reset value: 0x0, access type: RO
		uint32 hypFcsiClockEnable : 1; //hyp_fcsi_clock_enable, reset value: 0x0, access type: RO
		uint32 hypFcsiActive : 1; //hyp_fcsi_active, reset value: 0x0, access type: RO
		uint32 reserved0 : 16;
	} bitFields;
} RegPhyRxtdAnt2PhyRxtdAntReg4C_u;

/*REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG4D 0x134 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 fcsiForceDefaultWlan2Ms : 1; //fcsi_force_default_wlan2ms, reset value: 0x0, access type: RW
		uint32 reserved0 : 31;
	} bitFields;
} RegPhyRxtdAnt2PhyRxtdAntReg4D_u;

/*REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG4E 0x138 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 antennaResetEnable : 1; //antenna_reset_enable, reset value: 0x1, access type: RW
		uint32 reserved0 : 31;
	} bitFields;
} RegPhyRxtdAnt2PhyRxtdAntReg4E_u;

/*REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG4F 0x13C */
typedef union
{
	uint32 val;
	struct
	{
		uint32 rxLpbkSelect : 2; //Rx LoopBack Select, reset value: 0x0, access type: RW
		uint32 reserved0 : 30;
	} bitFields;
} RegPhyRxtdAnt2PhyRxtdAntReg4F_u;

/*REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG50 0x140 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 rfFreqMhz : 13; //rf_freq_mhz, reset value: 0x0, access type: RW
		uint32 reserved0 : 1;
		uint32 fdlIqComp : 16; //fdl_iq_comp, reset value: 0x0, access type: RW
		uint32 fdlBypass : 1; //fdl_bypass, reset value: 0x0, access type: RW
		uint32 reserved1 : 1;
	} bitFields;
} RegPhyRxtdAnt2PhyRxtdAntReg50_u;

/*REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG51 0x144 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 fdlNcoUpLim : 30; //fdl_nco_up_lim, reset value: 0x0, access type: RW
		uint32 freqShiftM1Bypass : 1; //freq_shift_m1_bypass, reset value: 0x0, access type: RW
		uint32 freqShiftM2Bypass : 1; //freq_shift_m2_bypass, reset value: 0x0, access type: RW
	} bitFields;
} RegPhyRxtdAnt2PhyRxtdAntReg51_u;

/*REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG52 0x148 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 chanfiltBypass : 1; //chanfilt_bypass, reset value: 0x0, access type: RW
		uint32 chanfiltChangePhase : 4; //chanfilt_change_phase, reset value: 0x0, access type: RW
		uint32 chanfiltLdSrc : 2; //chanfilt_ld_src, reset value: 0x0, access type: RW
		uint32 chanfiltCoefLoad : 1; //chanfilt_coef_load, reset value: 0x0, access type: WO
		uint32 chanfiltCoefDbg : 6; //chanfilt_coef_dbg, reset value: 0x0, access type: RW
		uint32 chanfiltFlexLength : 1; //chanfilt_flex_length, reset value: 0x1, access type: RW
		uint32 chanfiltDisZout : 1; //chanfilt_dis_zout, reset value: 0x0, access type: RW
		uint32 frcChangeLoad : 1; //frc_change_load, reset value: 0x0, access type: RW
		uint32 frcLutGainDis : 1; //frc_lut_gain_dis, reset value: 0x0, access type: RW
		uint32 frcRssiGainDis : 1; //frc_rssi_gain_dis, reset value: 0x0, access type: RW
		uint32 chanfiltGain : 7; //chanfilt_gain, reset value: 0x0, access type: RW
		uint32 chanfiltIirMode : 2; //Channel filter IIR operation mode: , 0 - never use IIR, (Use FIR) , 1 - from 1st sample, (force IIR from start) , 2 - from HESTF (only if channel is 320MHz wide), (default) , 3 - from HESTF if channel is 160MHz wide or 320MHz wide , , reset value: 0x2, access type: RW
		uint32 iirEnAlignedToStrobesDisable : 1; //chicken bit to disable a fix made to the iir_en logic.  , by default iir_en is aligned to the strobes grid which supports smooth switching from FIR mode to IIR mode.  , If pm_iir_en_aligned_to_strobes_disable is set to 1. No alignment is done. , reset value: 0x0, access type: RW
		uint32 reserved0 : 3;
	} bitFields;
} RegPhyRxtdAnt2PhyRxtdAntReg52_u;

/*REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG53 0x14C */
typedef union
{
	uint32 val;
	struct
	{
		uint32 frcBypass : 1; //frc_bypass, reset value: 0x0, access type: RW
		uint32 sig3Bypass : 1; //sig3_bypass, reset value: 0x0, access type: RW
		uint32 frcOfdmBypass : 1; //frc_ofdm_bypass, reset value: 0x0, access type: RW
		uint32 bBypass : 1; //b_bypass, reset value: 0x0, access type: RW
		uint32 disablePrimaryDetection : 1; //disable_primary_detection, reset value: 0x0, access type: RW
		uint32 rxFreqShiftMode : 1; //rx_freq_shift_mode, reset value: 0x0, access type: RW
		uint32 rxFreqWaitForRas : 1; //rx_freq_wait_for_ras, reset value: 0x1, access type: RW
		uint32 reserved0 : 5;
		uint32 frcFwShift1 : 4; //frc_fw_shift1, reset value: 0x0, access type: RW
		uint32 frcFwShift2 : 4; //frc_fw_shift2, reset value: 0x0, access type: RW
		uint32 frcFwCntr : 12; //frc_fw_cntr, reset value: 0x0, access type: RW
	} bitFields;
} RegPhyRxtdAnt2PhyRxtdAntReg53_u;

/*REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG54 0x150 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 frcOfdmCntr : 12; //frc_ofdm_cntr, reset value: 0x0, access type: RW
		uint32 frcSig3Cntr : 12; //frc_sig3_cntr, reset value: 0x0, access type: RW
		uint32 reserved0 : 8;
	} bitFields;
} RegPhyRxtdAnt2PhyRxtdAntReg54_u;

/*REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG55 0x154 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 frc11BCntr : 12; //frc_11b_cntr, reset value: 0x0, access type: RW
		uint32 chanfiltIdle20Mhz : 3; //chanfilt_idle_20mhz, reset value: 0x1, access type: RW
		uint32 chanfiltIdle40Mhz : 3; //chanfilt_idle_40mhz, reset value: 0x1, access type: RW
		uint32 chanfiltIdle80Mhz : 3; //chanfilt_idle_80mhz, reset value: 0x1, access type: RW
		uint32 chanfiltIdle160Mhz : 3; //chanfilt_idle_160mhz, reset value: 0x1, access type: RW
		uint32 chanfiltLegacy20Mhz : 3; //chanfilt_legacy_20mhz, reset value: 0x3, access type: RW
		uint32 chanfiltLegacy40Mhz : 3; //chanfilt_legacy_40mhz, reset value: 0x3, access type: RW
		uint32 reserved0 : 2;
	} bitFields;
} RegPhyRxtdAnt2PhyRxtdAntReg55_u;

/*REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG56 0x158 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 chanfiltLegacy80Mhz : 3; //chanfilt_legacy_80mhz, reset value: 0x3, access type: RW
		uint32 chanfiltLegacy160Mhz : 3; //chanfilt_legacy_160mhz, reset value: 0x3, access type: RW
		uint32 det80211BFilt : 3; //det_802_11b_filt, reset value: 0x0, access type: RW
		uint32 reserved0 : 1;
		uint32 chanfiltForceAc : 1; //chanfilt_force_ac, reset value: 0x0, access type: RW
		uint32 chanfiltForceAci20Mhz : 2; //chanfilt_force_aci_20mhz, reset value: 0x0, access type: RW
		uint32 chanfiltForceAci40Mhz : 2; //chanfilt_force_aci_40mhz, reset value: 0x0, access type: RW
		uint32 chanfiltForceAci80Mhz : 2; //chanfilt_force_aci_80mhz, reset value: 0x0, access type: RW
		uint32 chanfiltForceAci160Mhz : 2; //chanfilt_force_aci_160mhz, reset value: 0x0, access type: RW
		uint32 chanfiltHeLowpassSel : 2; //chanfilt_he_lowpass_sel, reset value: 0x1, access type: RW
		uint32 chanfiltForceImmediate : 1; //chanfilt_force_immediate, reset value: 0x0, access type: RW
		uint32 chanfiltForceBw : 2; //chanfilt_force_bw, reset value: 0x0, access type: RW
		uint32 chanfiltForceFilt : 3; //chanfilt_force_filt, reset value: 0x0, access type: RW
		uint32 chanfiltForceNatural : 1; //chanfilt_force_natural, reset value: 0x0, access type: RW
		uint32 chanfiltFullSwCtrl : 1; //chanfilt_full_sw_ctrl, reset value: 0x0, access type: RW
		uint32 chanfiltHeLowpassWideSel : 2; //chanfilt_he_lowpass_wide_sel, reset value: 0x1, access type: RW
		uint32 reserved1 : 1;
	} bitFields;
} RegPhyRxtdAnt2PhyRxtdAntReg56_u;

/*REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG57 0x15C */
typedef union
{
	uint32 val;
	struct
	{
		uint32 reserved0 : 4;
		uint32 bandselInitGain : 7; //bandsel_init_gain, reset value: 0x0, access type: RW
		uint32 reserved1 : 5;
		uint32 bandselInitGainValid : 1; //bandsel_init_gain_valid, reset value: 0x0, access type: RW
		uint32 reserved2 : 15;
	} bitFields;
} RegPhyRxtdAnt2PhyRxtdAntReg57_u;

/*REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG58 0x160 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 dcIirBandselBypass : 1; //dc_iir_bandsel_bypass, reset value: 0x0, access type: RW
		uint32 dcIirBandselAlpha : 4; //dc_iir_bandsel_alpha, reset value: 0x0, access type: RW
		uint32 dcIirDetBypass : 1; //dc_iir_det_bypass, reset value: 0x0, access type: RW
		uint32 dcIirDetAlpha : 4; //dc_iir_det_alpha, reset value: 0x0, access type: RW
		uint32 reserved0 : 22;
	} bitFields;
} RegPhyRxtdAnt2PhyRxtdAntReg58_u;

/*REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG60 0x180 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 reserved0 : 12;
		uint32 difi2OpGainDb : 7; //difi2_op_gain_db, reset value: 0x0, access type: RW
		uint32 rssiDifi2OpGainDb : 7; //rssi_difi2_op_gain_db, reset value: 0x0, access type: RW
		uint32 reserved1 : 6;
	} bitFields;
} RegPhyRxtdAnt2PhyRxtdAntReg60_u;

/*REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG61 0x184 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 c64DiffMode : 1; // c64_diff_mode, reset value: 0x0, access type: RW
		uint32 detC64MrbEn : 1; //det_c64_mrb_en, reset value: 0x0, access type: RW
		uint32 det160MPhase : 1; //det_160m_phase, reset value: 0x0, access type: RW
		uint32 reserved0 : 29;
	} bitFields;
} RegPhyRxtdAnt2PhyRxtdAntReg61_u;

/*REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG62 0x188 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 memGlobalTestMode : 2; //Global test mode for rams, reset value: 0x0, access type: RW
		uint32 reserved0 : 30;
	} bitFields;
} RegPhyRxtdAnt2PhyRxtdAntReg62_u;

/*REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG63 0x18C */
typedef union
{
	uint32 val;
	struct
	{
		uint32 swBistStart : 1; //sw_bist_start, reset value: 0x0, access type: RW
		uint32 clearRamMode : 1; //clear_ram_mode, reset value: 0x0, access type: RW
		uint32 bistScrBypass : 1; //bist_scr_bypass, reset value: 0x0, access type: RW
		uint32 reserved0 : 29;
	} bitFields;
} RegPhyRxtdAnt2PhyRxtdAntReg63_u;

/*REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG64 0x190 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 detPpmFreqOffset : 20; //det_ppm_freq_offset, reset value: 0x0, access type: RW
		uint32 reserved0 : 12;
	} bitFields;
} RegPhyRxtdAnt2PhyRxtdAntReg64_u;

/*REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG65 0x194 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 reserved0 : 14;
		uint32 iqPgc : 3; //iq_pgc , Note: Values from 0 to 5 are supported., reset value: 0x5, access type: RW
		uint32 reserved1 : 15;
	} bitFields;
} RegPhyRxtdAnt2PhyRxtdAntReg65_u;

/*REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG66 0x198 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 iqW1Mod0 : 13; //iq decorrelator w1 coefficient for mode 0, reset value: 0x0, access type: RW
		uint32 iqW2Mod0 : 11; //iq decorrelator w2 coefficient for mode 0, reset value: 0x0, access type: RW
		uint32 reserved0 : 8;
	} bitFields;
} RegPhyRxtdAnt2PhyRxtdAntReg66_u;

/*REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG67 0x19C */
typedef union
{
	uint32 val;
	struct
	{
		uint32 iqW1Mod1 : 13; //iq decorrelator w1 coefficient for mode 1, reset value: 0x0, access type: RW
		uint32 iqW2Mod1 : 11; //iq decorrelator w2 coefficient for mode 1, reset value: 0x0, access type: RW
		uint32 reserved0 : 8;
	} bitFields;
} RegPhyRxtdAnt2PhyRxtdAntReg67_u;

/*REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG69 0x1A4 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 reserved0 : 24;
		uint32 iqFirDelay : 3; //IQ equalizer FIR center tap (5th element) delay. , Range is 0 to 6. , Usually configured according to RF BW: , 1: BW = 20, 40 , 2: BW = 80, 160 , 4: BW = 320 , Should be similar to IQ equalizer FIR Q-path delay (iq_mismatch_eq_length_q)., reset value: 0x2, access type: RW
		uint32 reserved1 : 5;
	} bitFields;
} RegPhyRxtdAnt2PhyRxtdAntReg69_u;

/*REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG6A 0x1A8 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 pmCcaDbOffset : 12; //cca dB offset, reset value: 0x0, access type: RW
		uint32 reserved0 : 20;
	} bitFields;
} RegPhyRxtdAnt2PhyRxtdAntReg6A_u;

/*REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG6B 0x1AC */
typedef union
{
	uint32 val;
	struct
	{
		uint32 pmCcaBw : 3; //cca BW, reset value: 0x0, access type: RW
		uint32 reserved0 : 29;
	} bitFields;
} RegPhyRxtdAnt2PhyRxtdAntReg6B_u;

/*REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG6C 0x1B0 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 pmCcaAccSamples : 1; //cca acc samples 8/16 (16=1), reset value: 0x1, access type: RW
		uint32 reserved0 : 31;
	} bitFields;
} RegPhyRxtdAnt2PhyRxtdAntReg6C_u;

/*REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG6D 0x1B4 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 pmCcaRfCorrection1600 : 6; //cca RF correction 160MHz band0 Upper 20MHz, reset value: 0x0, access type: RW
		uint32 reserved0 : 2;
		uint32 pmCcaRfCorrection1601 : 6; //cca RF correction 160MHz band1 , reset value: 0x0, access type: RW
		uint32 reserved1 : 2;
		uint32 pmCcaRfCorrection1602 : 6; //cca RF correction 160MHz band2, reset value: 0x0, access type: RW
		uint32 reserved2 : 2;
		uint32 pmCcaRfCorrection1603 : 6; //cca RF correction 160MHz band3, reset value: 0x0, access type: RW
		uint32 reserved3 : 2;
	} bitFields;
} RegPhyRxtdAnt2PhyRxtdAntReg6D_u;

/*REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG6E 0x1B8 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 pmCcaRfCorrection1604 : 6; //cca RF correction 160MHz band4, reset value: 0x0, access type: RW
		uint32 reserved0 : 2;
		uint32 pmCcaRfCorrection1605 : 6; //cca RF correction 160MHz band5, reset value: 0x0, access type: RW
		uint32 reserved1 : 2;
		uint32 pmCcaRfCorrection1606 : 6; //cca RF correction 160MHz band6, reset value: 0x0, access type: RW
		uint32 reserved2 : 2;
		uint32 pmCcaRfCorrection1607 : 6; //cca RF correction 160MHz band7 Lower 20MHz, reset value: 0x0, access type: RW
		uint32 reserved3 : 2;
	} bitFields;
} RegPhyRxtdAnt2PhyRxtdAntReg6E_u;

/*REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG6F 0x1BC */
typedef union
{
	uint32 val;
	struct
	{
		uint32 pmCcaRfCorrection800 : 6; //cca RF correction 80MHz band0 Upper 20MHz, reset value: 0x0, access type: RW
		uint32 reserved0 : 2;
		uint32 pmCcaRfCorrection801 : 6; //cca RF correction 80MHz band1 , reset value: 0x0, access type: RW
		uint32 reserved1 : 2;
		uint32 pmCcaRfCorrection802 : 6; //cca RF correction 80MHz band2, reset value: 0x0, access type: RW
		uint32 reserved2 : 2;
		uint32 pmCcaRfCorrection803 : 6; //cca RF correction 80MHz band3 Lower 20MHz, reset value: 0x0, access type: RW
		uint32 reserved3 : 2;
	} bitFields;
} RegPhyRxtdAnt2PhyRxtdAntReg6F_u;

/*REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG70 0x1C0 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 pmCcaRfCorrection400 : 6; //cca RF correction 40MHz band0 Upper 20MHz, reset value: 0x0, access type: RW
		uint32 reserved0 : 2;
		uint32 pmCcaRfCorrection401 : 6; //cca RF correction 40MHz band1 Lower 20MHz, reset value: 0x0, access type: RW
		uint32 reserved1 : 18;
	} bitFields;
} RegPhyRxtdAnt2PhyRxtdAntReg70_u;

/*REG_PHY_RXTD_ANT2_RX_ABB_ANT_REG71 0x1C4 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 rxSc2FcPhaseRegfile : 2; //rx_sc2fc_phase_regfile, reset value: 0x0, access type: RW
		uint32 rxFc2ScPhaseRegfile : 2; //rx_fc2sc_phase_regfile, reset value: 0x0, access type: RW
		uint32 rxSc2FcRxon : 2; //no description, reset value: 0x0, access type: RW
		uint32 reserved0 : 26;
	} bitFields;
} RegPhyRxtdAnt2RxAbbAntReg71_u;

/*REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG72 0x1C8 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 pmBypassSelLpbkAfeN : 1; //pm_bypass_sel_lpbk_afe_n, reset value: 0x0, access type: RW
		uint32 pmDifi1Bypass : 1; //pm_difi1_bypass, reset value: 0x0, access type: RW
		uint32 pmDifi2Bypass : 1; //pm_difi2_bypass, reset value: 0x0, access type: RW
		uint32 pmDifi1LpbkType : 1; //pm_difi1_lpbk_type, reset value: 0x0, access type: RW
		uint32 reserved0 : 12;
		uint32 pmDifi2ShiftBy320M : 1; //pm_difi2_shift_by_320m, reset value: 0x0, access type: RW
		uint32 pmDifi3Bypass : 1; //no description, reset value: 0x0, access type: RW
		uint32 reserved1 : 14;
	} bitFields;
} RegPhyRxtdAnt2PhyRxtdAntReg72_u;

/*REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG73 0x1CC */
typedef union
{
	uint32 val;
	struct
	{
		uint32 pmAcidetBlkSize : 8; //pm_acidet_blk_size, reset value: 0x0, access type: RW
		uint32 pmAcidetAciDetTrig : 1; //pm_acidet_aci_det_trig, reset value: 0x0, access type: WO
		uint32 reserved0 : 23;
	} bitFields;
} RegPhyRxtdAnt2PhyRxtdAntReg73_u;

/*REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG74 0x1D0 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 pmAcidetThDb0 : 6; //pm_acidet_th_db_0, reset value: 0x0, access type: RW
		uint32 reserved0 : 2;
		uint32 pmAcidetThDb1 : 6; //pm_acidet_th_db_1, reset value: 0x0, access type: RW
		uint32 reserved1 : 2;
		uint32 pmAcidetThOffset : 6; //pm_acidet_th_offset, reset value: 0x0, access type: RW
		uint32 reserved2 : 10;
	} bitFields;
} RegPhyRxtdAnt2PhyRxtdAntReg74_u;

/*REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG75 0x1D4 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 pmAcidetRadarHighTh : 8; //pm_acidet_radar_high_th, reset value: 0x0, access type: RW
		uint32 pmAcidetRadarLowTh : 8; //pm_acidet_radar_low_th, reset value: 0x0, access type: RW
		uint32 pmAcidetRadarClear : 1; //pm_acidet_radar_clear, reset value: 0x0, access type: WO
		uint32 pmAcidetRadarAutoClearEn : 1; //pm_acidet_radar_auto_clear_en, reset value: 0x0, access type: RW
		uint32 pmAcidetAciDetTrigOnFineEn : 1; //pm_acidet_aci_det_trig_on_fine_en , reset value: 0x0, access type: RW
		uint32 reserved0 : 13;
	} bitFields;
} RegPhyRxtdAnt2PhyRxtdAntReg75_u;

/*REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG76 0x1D8 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 aciDetected : 1; //aci_detected, reset value: 0x0, access type: RO
		uint32 aciDetectedValid : 1; //aci_detected_valid, reset value: 0x0, access type: RO
		uint32 reserved0 : 2;
		uint32 acidetPowPrim : 9; //acidet_pow_prim, reset value: 0x0, access type: RO
		uint32 reserved1 : 3;
		uint32 acidetMaxPowBandReg : 8; //acidet_max_pow_band_reg, reset value: 0x0, access type: RO
		uint32 reserved2 : 8;
	} bitFields;
} RegPhyRxtdAnt2PhyRxtdAntReg76_u;

/*REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG77 0x1DC */
typedef union
{
	uint32 val;
	struct
	{
		uint32 acidetPowBandReg0 : 8; //acidet_pow_band_reg0, reset value: 0x0, access type: RO
		uint32 acidetPowBandReg1 : 8; //acidet_pow_band_reg1, reset value: 0x0, access type: RO
		uint32 acidetPowBandReg2 : 8; //acidet_pow_band_reg2, reset value: 0x0, access type: RO
		uint32 acidetPowBandReg3 : 8; //acidet_pow_band_reg3, reset value: 0x0, access type: RO
	} bitFields;
} RegPhyRxtdAnt2PhyRxtdAntReg77_u;

/*REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG78 0x1E0 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 acidetPowBandReg4 : 8; //acidet_pow_band_reg4, reset value: 0x0, access type: RO
		uint32 acidetPowBandReg5 : 8; //acidet_pow_band_reg5, reset value: 0x0, access type: RO
		uint32 acidetPowBandReg6 : 8; //acidet_pow_band_reg6, reset value: 0x0, access type: RO
		uint32 acidetPowBandReg7 : 8; //acidet_pow_band_reg7, reset value: 0x0, access type: RO
	} bitFields;
} RegPhyRxtdAnt2PhyRxtdAntReg78_u;

/*REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG79 0x1E4 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 acidetRadarCounter0 : 12; //acidet_radar_counter0, reset value: 0x0, access type: RO
		uint32 acidetRadarCounter1 : 12; //acidet_radar_counter1, reset value: 0x0, access type: RO
		uint32 reserved0 : 8;
	} bitFields;
} RegPhyRxtdAnt2PhyRxtdAntReg79_u;

/*REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG7A 0x1E8 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 acidetRadarCounter2 : 12; //acidet_radar_counter2, reset value: 0x0, access type: RO
		uint32 acidetRadarCounter3 : 12; //acidet_radar_counter3, reset value: 0x0, access type: RO
		uint32 reserved0 : 8;
	} bitFields;
} RegPhyRxtdAnt2PhyRxtdAntReg7A_u;

/*REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG7B 0x1EC */
typedef union
{
	uint32 val;
	struct
	{
		uint32 acidetRadarCounter4 : 12; //acidet_radar_counter4, reset value: 0x0, access type: RO
		uint32 acidetRadarCounter5 : 12; //acidet_radar_counter5, reset value: 0x0, access type: RO
		uint32 reserved0 : 8;
	} bitFields;
} RegPhyRxtdAnt2PhyRxtdAntReg7B_u;

/*REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG7C 0x1F0 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 acidetRadarCounter6 : 12; //acidet_radar_counter6, reset value: 0x0, access type: RO
		uint32 acidetRadarCounter7 : 12; //acidet_radar_counter7, reset value: 0x0, access type: RO
		uint32 reserved0 : 8;
	} bitFields;
} RegPhyRxtdAnt2PhyRxtdAntReg7C_u;

/*REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG7D 0x1F4 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 acidetRadarEventMask : 8; //acidet_radar_event_mask, reset value: 0x0, access type: RO
		uint32 acidetRadarEventNodetMask : 8; //acidet_radar_event_nodet_mask, reset value: 0x0, access type: RO
		uint32 acidetRadarCompletedEventMask : 8; //acidet_radar_completed_event_mask, reset value: 0x0, access type: RO
		uint32 reserved0 : 8;
	} bitFields;
} RegPhyRxtdAnt2PhyRxtdAntReg7D_u;

/*REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG7E 0x1F8 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 pmAciSystemGain : 9; //pm_aci_system_gain, reset value: 0x0, access type: RW
		uint32 reserved0 : 1;
		uint32 pmAciSystemGainHwOnMux : 1; //1- choose system gain from AGC HW. 0- from PM -pm_bs_system_gain, reset value: 0x1, access type: RW
		uint32 reserved1 : 1;
		uint32 pmAciRssiSatThr : 18; //threshold on RSSI for flag assert to AGC , reset value: 0x0, access type: RW
		uint32 reserved2 : 2;
	} bitFields;
} RegPhyRxtdAnt2PhyRxtdAntReg7E_u;

/*REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG7F 0x1FC */
typedef union
{
	uint32 val;
	struct
	{
		uint32 pmSystemGainCcaCtrlHw0 : 1; //pm_system_gain_cca_ctrl_hw0 , reset value: 0x0, access type: RW
		uint32 reserved0 : 3;
		uint32 pmSystemGainCca : 9; //pm_system_gain_cca , reset value: 0x0, access type: RW
		uint32 reserved1 : 19;
	} bitFields;
} RegPhyRxtdAnt2PhyRxtdAntReg7F_u;

/*REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG80 0x200 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 ccaPmBwPwrOut : 8; //cca_pm_bw_pwr_out, reset value: 0x0, access type: RO
		uint32 reserved0 : 24;
	} bitFields;
} RegPhyRxtdAnt2PhyRxtdAntReg80_u;

/*REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG82 0x208 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 fdlResetHwSync : 10; //fdl_reset_hw_sync, reset value: 0x0, access type: RW
		uint32 reserved0 : 22;
	} bitFields;
} RegPhyRxtdAnt2PhyRxtdAntReg82_u;

/*REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG83 0x20C */
typedef union
{
	uint32 val;
	struct
	{
		uint32 fdlRestartEn : 1; //fdl_restart_en, reset value: 0x0, access type: RW
		uint32 fdlCorrectionEnable : 1; //fdl_correction_enable, reset value: 0x0, access type: RW
		uint32 freqShiftPpmEnable : 1; //freq_shift_ppm_enable, reset value: 0x0, access type: RW
		uint32 freqShiftM2DcPpmShift : 1; //no description, reset value: 0x0, access type: RW
		uint32 freqShiftIirShift : 4; //no description, reset value: 0x2, access type: RW
		uint32 fdlEht160Cp : 1; //rx.fdl_restart_use_detected_cp_for_eht_bw160 , 0 --- 1st fdl restart does not use he_cp size BE update after sig4 on 160BW EHT (default) , 1 --- 1st fdl restart use BE he_cp size update after sig4 on 160BW EHT(NU/optional only) , this option is limited as sig4 may rise after 1st fdl restart, and cp may not be valid. ,  , , reset value: 0x0, access type: RW
		uint32 reserved0 : 23;
	} bitFields;
} RegPhyRxtdAnt2PhyRxtdAntReg83_u;

/*REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG84 0x210 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 fdlNcoIncrMax : 32; //fdl_nco_incr_max, reset value: 0x0, access type: RW
	} bitFields;
} RegPhyRxtdAnt2PhyRxtdAntReg84_u;

/*REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG85 0x214 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 fdlNcoIncr : 32; //fdl_nco_incr, reset value: 0x0, access type: RW
	} bitFields;
} RegPhyRxtdAnt2PhyRxtdAntReg85_u;

/*REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG86 0x218 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 pmFdlForceNcoIncr : 1; //pm_fdl_force_nco_incr, reset value: 0x0, access type: RW
		uint32 reserved0 : 31;
	} bitFields;
} RegPhyRxtdAnt2PhyRxtdAntReg86_u;

/*REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG87 0x21C */
typedef union
{
	uint32 val;
	struct
	{
		uint32 fdlNcoIncrOut : 32; //fdl_nco_incr_out, reset value: 0x0, access type: RO
	} bitFields;
} RegPhyRxtdAnt2PhyRxtdAntReg87_u;

/*REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG88 0x220 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 fdlNcoIncrValidOut : 1; //fdl_nco_incr_valid_out, reset value: 0x0, access type: RO
		uint32 reserved0 : 31;
	} bitFields;
} RegPhyRxtdAnt2PhyRxtdAntReg88_u;

/*REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG89 0x224 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 fdlNcoIncrSat : 1; //fdl_nco_incr_sat, reset value: 0x0, access type: RO
		uint32 reserved0 : 31;
	} bitFields;
} RegPhyRxtdAnt2PhyRxtdAntReg89_u;

/*REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG8A 0x228 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 fdlNcoAccStsOut : 32; //fdl_nco_acc_sts_out, reset value: 0x0, access type: RO
	} bitFields;
} RegPhyRxtdAnt2PhyRxtdAntReg8A_u;

/*REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG8B 0x22C */
typedef union
{
	uint32 val;
	struct
	{
		uint32 pm11BDecimPhase : 2; //decimation phase from 160M to 40M from Shifter-M2 to 11B core, reset value: 0x2, access type: RW
		uint32 pm11BDecimPathSelect : 1; //11b mux data path selection  , 0 - band select  , 1 - decimator path select ,  ,  , , reset value: 0x0, access type: RW
		uint32 reserved0 : 29;
	} bitFields;
} RegPhyRxtdAnt2PhyRxtdAntReg8B_u;

/*REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG8C 0x230 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 fftShareOverrideControl : 1; //fft_share_override_control for digital loopback, reset value: 0x0, access type: RW
		uint32 reserved0 : 3;
		uint32 fftControlRx : 1; //fft control rx mode or tx mode: 0 -TX, 1-RX, reset value: 0x0, access type: RW
		uint32 reserved1 : 27;
	} bitFields;
} RegPhyRxtdAnt2PhyRxtdAntReg8C_u;

/*REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG8D 0x234 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 antOfdmC16Rm : 3; //ant_ofdm_c16_rm, reset value: 0x3, access type: RW
		uint32 reserved0 : 1;
		uint32 antOfdmC64Rm : 3; //ant_ofdm_c64_rm, reset value: 0x3, access type: RW
		uint32 reserved1 : 1;
		uint32 antOfdmMrbRm : 3; //ant_ofdm_mrb_rm, reset value: 0x3, access type: RW
		uint32 reserved2 : 1;
		uint32 antAciDetAvgRm : 3; //ant_aci_det_avg_rm, reset value: 0x3, access type: RW
		uint32 reserved3 : 1;
		uint32 antIqParamsLutRm : 3; //ant_iq_params_lut_rm, reset value: 0x3, access type: RW
		uint32 reserved4 : 1;
		uint32 antIqFireqLutRm : 3; //ant_iq_fireq_lut_rm, reset value: 0x3, access type: RW
		uint32 reserved5 : 9;
	} bitFields;
} RegPhyRxtdAnt2PhyRxtdAntReg8D_u;

/*REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG8E 0x238 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 testPlugLen : 12; //test_plug_len, reset value: 0x0, access type: RW
		uint32 reserved0 : 20;
	} bitFields;
} RegPhyRxtdAnt2PhyRxtdAntReg8E_u;

/*REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG8F 0x23C */
typedef union
{
	uint32 val;
	struct
	{
		uint32 fdlDisableTimingUpdates : 1; //fdl_disable_timing_updates, reset value: 0x0, access type: RW
		uint32 reserved0 : 31;
	} bitFields;
} RegPhyRxtdAnt2PhyRxtdAntReg8F_u;

/*REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG90 0x240 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 heTrigStfGainBypass : 1; //he_trig_stf_gain_bypass, reset value: 0x1, access type: RW
		uint32 reserved0 : 31;
	} bitFields;
} RegPhyRxtdAnt2PhyRxtdAntReg90_u;

/*REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG91 0x244 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 rssiData : 15; //rssi_data, reset value: 0x0, access type: RO
		uint32 reserved0 : 17;
	} bitFields;
} RegPhyRxtdAnt2PhyRxtdAntReg91_u;

/*REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG92 0x248 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 stsFdlIqComp : 16; //sts_fdl_iq_comp, reset value: 0x0, access type: RO
		uint32 reserved0 : 16;
	} bitFields;
} RegPhyRxtdAnt2PhyRxtdAntReg92_u;

/*REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG93 0x24C */
typedef union
{
	uint32 val;
	struct
	{
		uint32 stsChanfiltCoef : 12; //sts_chanfilt_coef, reset value: 0x0, access type: RO
		uint32 stsChanfiltSetId : 5; //sts_chanfilt_set_id, reset value: 0x0, access type: RO
		uint32 stsChanfiltFiltLength : 8; //sts_chanfilt_filt_length, reset value: 0x0, access type: RO
		uint32 reserved0 : 7;
	} bitFields;
} RegPhyRxtdAnt2PhyRxtdAntReg93_u;

/*REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG94 0x250 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 acidetRadarMaxCnt : 12; //acidet_radar_max_cnt, reset value: 0x0, access type: RO
		uint32 reserved0 : 20;
	} bitFields;
} RegPhyRxtdAnt2PhyRxtdAntReg94_u;

/*REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG95 0x254 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 pmPreFilterBypass : 1; //pm_pre_filter_bypass, reset value: 0x1, access type: RW
		uint32 pmPreFilterBypassWithDelay : 1; //pm_pre_filter_bypass_with_delay, reset value: 0x0, access type: RW
		uint32 pmPreFilterNarrowMode : 1; //pm_pre_filter_narrow_mode, reset value: 0x0, access type: RW
		uint32 pmPreFilterBypassWithGain : 1; //pm_pre_filter_bypass_no_delay_with_gain, reset value: 0x0, access type: RW
		uint32 reserved0 : 28;
	} bitFields;
} RegPhyRxtdAnt2PhyRxtdAntReg95_u;

/*REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG96 0x258 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 pmPreFilterGain : 7; //pm_pre_filter_gain, reset value: 0x0, access type: RW
		uint32 pmPreFilterGainEn : 1; //pm_pre_filter_gain_en, reset value: 0x0, access type: RW
		uint32 reserved0 : 24;
	} bitFields;
} RegPhyRxtdAnt2PhyRxtdAntReg96_u;

/*REG_PHY_RXTD_ANT2_CONTROL_11B 0x25C */
typedef union
{
	uint32 val;
	struct
	{
		uint32 bitShift11B : 2; //bit shift for 11b , reset value: 0x0, access type: RW
		uint32 bitShift11BHwEn : 1; //choose if taking hw or pm for bit shift, reset value: 0x0, access type: RW
		uint32 reserved0 : 29;
	} bitFields;
} RegPhyRxtdAnt2Control11B_u;

/*REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG98 0x260 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 pmBandselFilterIndex : 1; //bandsel filter index to select between regular to narrow filter , offsets in coefficients memory are 0, 32, 64 and 80, reset value: 0x0, access type: RW
		uint32 reserved0 : 7;
		uint32 pmBandselInputRate : 3; //Value for bandsel input rate: NEW in WAV700. Acceptable values: 4-320, 3-160, 2-80, 1-40, 0-20, reset value: 0x4, access type: RW
		uint32 reserved1 : 21;
	} bitFields;
} RegPhyRxtdAnt2PhyRxtdAntReg98_u;

/*REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG99 0x264 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 bandselToDetPmGainDb : 7; //bandsel_to_det_pm_gain_db, reset value: 0x0, access type: RW
		uint32 bandselToDetHwGainDbEn : 1; //bandsel_to_det_hw_gain_db_en, reset value: 0x0, access type: RW
		uint32 bandsel10MhzForce : 2; //bandsel_10mhz_force, reset value: 0x0, access type: RW
		uint32 reserved0 : 22;
	} bitFields;
} RegPhyRxtdAnt2PhyRxtdAntReg99_u;

/*REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG9A 0x268 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 i2QEqTap0 : 10; //no description, reset value: 0x0, access type: RW
		uint32 reserved0 : 6;
		uint32 i2QEqTap1 : 10; //no description, reset value: 0x0, access type: RW
		uint32 reserved1 : 6;
	} bitFields;
} RegPhyRxtdAnt2PhyRxtdAntReg9A_u;

/*REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG9B 0x26C */
typedef union
{
	uint32 val;
	struct
	{
		uint32 i2QEqTap2 : 10; //no description, reset value: 0x0, access type: RW
		uint32 reserved0 : 6;
		uint32 i2QEqTap3 : 10; //no description, reset value: 0x0, access type: RW
		uint32 reserved1 : 6;
	} bitFields;
} RegPhyRxtdAnt2PhyRxtdAntReg9B_u;

/*REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG9C 0x270 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 i2QEqTap4 : 10; //no description, reset value: 0x0, access type: RW
		uint32 reserved0 : 6;
		uint32 i2QEqTap5 : 10; //no description, reset value: 0x0, access type: RW
		uint32 reserved1 : 6;
	} bitFields;
} RegPhyRxtdAnt2PhyRxtdAntReg9C_u;

/*REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG9D 0x274 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 i2QEqTap6 : 10; //no description, reset value: 0x0, access type: RW
		uint32 reserved0 : 6;
		uint32 i2QEqTap7 : 10; //no description, reset value: 0x0, access type: RW
		uint32 reserved1 : 6;
	} bitFields;
} RegPhyRxtdAnt2PhyRxtdAntReg9D_u;

/*REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG9E 0x278 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 i2QEqTap8 : 10; //no description, reset value: 0x0, access type: RW
		uint32 reserved0 : 6;
		uint32 i2QEqTap9 : 10; //no description, reset value: 0x0, access type: RW
		uint32 reserved1 : 6;
	} bitFields;
} RegPhyRxtdAnt2PhyRxtdAntReg9E_u;

/*REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG9F 0x27C */
typedef union
{
	uint32 val;
	struct
	{
		uint32 i2QEqTap10 : 10; //no description, reset value: 0x0, access type: RW
		uint32 reserved0 : 6;
		uint32 i2QEqTap11 : 10; //no description, reset value: 0x0, access type: RW
		uint32 reserved1 : 6;
	} bitFields;
} RegPhyRxtdAnt2PhyRxtdAntReg9F_u;

/*REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REGA1 0x284 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 i2QEqUsedTap0 : 10; //IQ Mismatch Equalizer Calibration Coefficient Num 0 used in filter, reset value: 0x0, access type: RO
		uint32 reserved0 : 6;
		uint32 i2QEqUsedTap1 : 10; //no description, reset value: 0x0, access type: RO
		uint32 reserved1 : 6;
	} bitFields;
} RegPhyRxtdAnt2PhyRxtdAntRega1_u;

/*REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REGA2 0x288 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 i2QEqUsedTap2 : 10; //IQ Mismatch Equalizer Calibration Coefficient Num 0 used in filter, reset value: 0x0, access type: RO
		uint32 reserved0 : 6;
		uint32 i2QEqUsedTap3 : 10; //no description, reset value: 0x0, access type: RO
		uint32 reserved1 : 6;
	} bitFields;
} RegPhyRxtdAnt2PhyRxtdAntRega2_u;

/*REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REGA3 0x28C */
typedef union
{
	uint32 val;
	struct
	{
		uint32 i2QEqUsedTap4 : 10; //IQ Mismatch Equalizer Calibration Coefficient Num 0 used in filter, reset value: 0x0, access type: RO
		uint32 reserved0 : 6;
		uint32 i2QEqUsedTap5 : 10; //no description, reset value: 0x0, access type: RO
		uint32 reserved1 : 6;
	} bitFields;
} RegPhyRxtdAnt2PhyRxtdAntRega3_u;

/*REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REGA4 0x290 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 i2QEqUsedTap6 : 10; //IQ Mismatch Equalizer Calibration Coefficient Num 0 used in filter, reset value: 0x0, access type: RO
		uint32 reserved0 : 6;
		uint32 i2QEqUsedTap7 : 10; //no description, reset value: 0x0, access type: RO
		uint32 reserved1 : 6;
	} bitFields;
} RegPhyRxtdAnt2PhyRxtdAntRega4_u;

/*REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REGA5 0x294 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 i2QEqUsedTap8 : 10; //IQ Mismatch Equalizer Calibration Coefficient Num 0 used in filter, reset value: 0x0, access type: RO
		uint32 reserved0 : 6;
		uint32 i2QEqUsedTap9 : 10; //no description, reset value: 0x0, access type: RO
		uint32 reserved1 : 6;
	} bitFields;
} RegPhyRxtdAnt2PhyRxtdAntRega5_u;

/*REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REGA6 0x298 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 i2QEqUsedTap10 : 10; //IQ Mismatch Equalizer Calibration Coefficient Num 0 used in filter, reset value: 0x0, access type: RO
		uint32 reserved0 : 6;
		uint32 i2QEqUsedTap11 : 10; //no description, reset value: 0x0, access type: RO
		uint32 reserved1 : 6;
	} bitFields;
} RegPhyRxtdAnt2PhyRxtdAntRega6_u;

/*REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REGA7 0x29C */
typedef union
{
	uint32 val;
	struct
	{
		uint32 pmRamLs : 10; //pm_ram_ls, reset value: 0x0, access type: RW
		uint32 pmRamDs : 3; //pm_ram_ds, reset value: 0x0, access type: RW
		uint32 reserved0 : 3;
		uint32 pmRamSd : 3; //pm_ram_sd, reset value: 0x0, access type: RW
		uint32 reserved1 : 5;
		uint32 pmRamPsHwEn : 8; //pm_ram_ps_hw_en, reset value: 0x0, access type: RW
	} bitFields;
} RegPhyRxtdAnt2PhyRxtdAntRega7_u;

/*REG_PHY_RXTD_ANT2_FORCE_OP_CH_ZERO 0x2A0 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 forceOpChZero : 16; //force_op_zero, reset value: 0x0, access type: RW
		uint32 reserved0 : 16;
	} bitFields;
} RegPhyRxtdAnt2ForceOpChZero_u;

/*REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REGA9 0x2A4 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 pmRamRop : 2; //pm_ram_rop, reset value: 0x0, access type: RO
		uint32 reserved0 : 30;
	} bitFields;
} RegPhyRxtdAnt2PhyRxtdAntRega9_u;

/*REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REGAA 0x2A8 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 mrbOutForce0Enable : 1; //mrb_out_force_0_enable   , reset value: 0x0, access type: WO
		uint32 lengthOfMrbOutForce0 : 7; //length_of_mrb_out_force_0, reset value: 0x0, access type: RW
		uint32 reserved0 : 24;
	} bitFields;
} RegPhyRxtdAnt2PhyRxtdAntRegaa_u;

/*REG_PHY_RXTD_ANT2_TB_BANDSELECT_BANDS 0x2AC */
typedef union
{
	uint32 val;
	struct
	{
		uint32 tbBandselectBands : 16; //which bands to record in test bus, reset value: 0xFFFF, access type: RW
		uint32 reserved0 : 16;
	} bitFields;
} RegPhyRxtdAnt2TbBandselectBands_u;

/*REG_PHY_RXTD_ANT2_CONTROL_OVERRIDE 0x2B0 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 pmAntSwResetNRegSel : 1; //take sw_reset_n from ant vs common, reset value: 0x0, access type: RW
		uint32 pmAntBlockEnSel : 1; //take block_en from ant vs common, reset value: 0x0, access type: RW
		uint32 reserved0 : 30;
	} bitFields;
} RegPhyRxtdAnt2ControlOverride_u;

/*REG_PHY_RXTD_ANT2_ANT_SW_RESET_N_REG 0x2B4 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 antSwResetNReg : 32; //sw reset n from ant, reset value: 0x0, access type: RW
	} bitFields;
} RegPhyRxtdAnt2AntSwResetNReg_u;

/*REG_PHY_RXTD_ANT2_ANT_BLOCK_EN 0x2B8 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 antBlockEn : 32; //block en ant, reset value: 0x0, access type: RW
	} bitFields;
} RegPhyRxtdAnt2AntBlockEn_u;

/*REG_PHY_RXTD_ANT2_ACI_BAND_POWER_0 0x2BC */
typedef union
{
	uint32 val;
	struct
	{
		uint32 aciBandPower0 : 9; //aci_band_power_0, reset value: 0x0, access type: RO
		uint32 reserved0 : 23;
	} bitFields;
} RegPhyRxtdAnt2AciBandPower0_u;

/*REG_PHY_RXTD_ANT2_ACI_BAND_POWER_1 0x2C0 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 aciBandPower1 : 9; //aci_band_power_1, reset value: 0x0, access type: RO
		uint32 reserved0 : 23;
	} bitFields;
} RegPhyRxtdAnt2AciBandPower1_u;

/*REG_PHY_RXTD_ANT2_ACI_BAND_POWER_2 0x2C4 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 aciBandPower2 : 9; //aci_band_power_2, reset value: 0x0, access type: RO
		uint32 reserved0 : 23;
	} bitFields;
} RegPhyRxtdAnt2AciBandPower2_u;

/*REG_PHY_RXTD_ANT2_ACI_BAND_POWER_3 0x2C8 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 aciBandPower3 : 9; //aci_band_power_3, reset value: 0x0, access type: RO
		uint32 reserved0 : 23;
	} bitFields;
} RegPhyRxtdAnt2AciBandPower3_u;

/*REG_PHY_RXTD_ANT2_ACI_BAND_POWER_4 0x2CC */
typedef union
{
	uint32 val;
	struct
	{
		uint32 aciBandPower4 : 9; //aci_band_power_4, reset value: 0x0, access type: RO
		uint32 reserved0 : 23;
	} bitFields;
} RegPhyRxtdAnt2AciBandPower4_u;

/*REG_PHY_RXTD_ANT2_ACI_BAND_POWER_5 0x2D0 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 aciBandPower5 : 9; //aci_band_power_5, reset value: 0x0, access type: RO
		uint32 reserved0 : 23;
	} bitFields;
} RegPhyRxtdAnt2AciBandPower5_u;

/*REG_PHY_RXTD_ANT2_ACI_BAND_POWER_6 0x2D4 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 aciBandPower6 : 9; //aci_band_power_6, reset value: 0x0, access type: RO
		uint32 reserved0 : 23;
	} bitFields;
} RegPhyRxtdAnt2AciBandPower6_u;

/*REG_PHY_RXTD_ANT2_ACI_BAND_POWER_7 0x2D8 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 aciBandPower7 : 9; //aci_band_power_7, reset value: 0x0, access type: RO
		uint32 reserved0 : 23;
	} bitFields;
} RegPhyRxtdAnt2AciBandPower7_u;

/*REG_PHY_RXTD_ANT2_ACI_BAND_POWER_8 0x2DC */
typedef union
{
	uint32 val;
	struct
	{
		uint32 aciBandPower8 : 9; //aci_band_power_8, reset value: 0x0, access type: RO
		uint32 reserved0 : 23;
	} bitFields;
} RegPhyRxtdAnt2AciBandPower8_u;

/*REG_PHY_RXTD_ANT2_ACI_BAND_POWER_9 0x2E0 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 aciBandPower9 : 9; //aci_band_power_9, reset value: 0x0, access type: RO
		uint32 reserved0 : 23;
	} bitFields;
} RegPhyRxtdAnt2AciBandPower9_u;

/*REG_PHY_RXTD_ANT2_ACI_BAND_POWER_10 0x2E4 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 aciBandPower10 : 9; //aci_band_power_10, reset value: 0x0, access type: RO
		uint32 reserved0 : 23;
	} bitFields;
} RegPhyRxtdAnt2AciBandPower10_u;

/*REG_PHY_RXTD_ANT2_ACI_BAND_POWER_11 0x2E8 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 aciBandPower11 : 9; //aci_band_power_11, reset value: 0x0, access type: RO
		uint32 reserved0 : 23;
	} bitFields;
} RegPhyRxtdAnt2AciBandPower11_u;

/*REG_PHY_RXTD_ANT2_ACI_BAND_POWER_12 0x2EC */
typedef union
{
	uint32 val;
	struct
	{
		uint32 aciBandPower12 : 9; //aci_band_power_12, reset value: 0x0, access type: RO
		uint32 reserved0 : 23;
	} bitFields;
} RegPhyRxtdAnt2AciBandPower12_u;

/*REG_PHY_RXTD_ANT2_ACI_BAND_POWER_13 0x2F0 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 aciBandPower13 : 9; //aci_band_power_13, reset value: 0x0, access type: RO
		uint32 reserved0 : 23;
	} bitFields;
} RegPhyRxtdAnt2AciBandPower13_u;

/*REG_PHY_RXTD_ANT2_ACI_BAND_POWER_14 0x2F4 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 aciBandPower14 : 9; //aci_band_power_14, reset value: 0x0, access type: RO
		uint32 reserved0 : 23;
	} bitFields;
} RegPhyRxtdAnt2AciBandPower14_u;

/*REG_PHY_RXTD_ANT2_ACI_BAND_POWER_15 0x2F8 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 aciBandPower15 : 9; //aci_band_power_15, reset value: 0x0, access type: RO
		uint32 reserved0 : 23;
	} bitFields;
} RegPhyRxtdAnt2AciBandPower15_u;

/*REG_PHY_RXTD_ANT2_ACI_BAND_POWER_OVR_0_3 0x2FC */
typedef union
{
	uint32 val;
	struct
	{
		uint32 aciBandPowerOvr0 : 7; //aci_band_power_ovr_0, reset value: 0x0, access type: RW
		uint32 aciBandPowerOvr0En : 1; //aci_band_power_ovr_0_en, reset value: 0x0, access type: RW
		uint32 aciBandPowerOvr1 : 7; //aci_band_power_ovr_1, reset value: 0x0, access type: RW
		uint32 aciBandPowerOvr1En : 1; //aci_band_power_ovr_1_en, reset value: 0x0, access type: RW
		uint32 aciBandPowerOvr2 : 7; //aci_band_power_ovr_2, reset value: 0x0, access type: RW
		uint32 aciBandPowerOvr2En : 1; //aci_band_power_ovr_2_en, reset value: 0x0, access type: RW
		uint32 aciBandPowerOvr3 : 7; //aci_band_power_ovr_3, reset value: 0x0, access type: RW
		uint32 aciBandPowerOvr3En : 1; //aci_band_power_ovr_3_en, reset value: 0x0, access type: RW
	} bitFields;
} RegPhyRxtdAnt2AciBandPowerOvr03_u;

/*REG_PHY_RXTD_ANT2_ACI_BAND_POWER_OVR_4_7 0x300 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 aciBandPowerOvr4 : 7; //aci_band_power_ovr_4, reset value: 0x0, access type: RW
		uint32 aciBandPowerOvr4En : 1; //aci_band_power_ovr_4_en, reset value: 0x0, access type: RW
		uint32 aciBandPowerOvr5 : 7; //aci_band_power_ovr_5, reset value: 0x0, access type: RW
		uint32 aciBandPowerOvr5En : 1; //aci_band_power_ovr_5_en, reset value: 0x0, access type: RW
		uint32 aciBandPowerOvr6 : 7; //aci_band_power_ovr_6, reset value: 0x0, access type: RW
		uint32 aciBandPowerOvr6En : 1; //aci_band_power_ovr_6_en, reset value: 0x0, access type: RW
		uint32 aciBandPowerOvr7 : 7; //aci_band_power_ovr_7, reset value: 0x0, access type: RW
		uint32 aciBandPowerOvr7En : 1; //aci_band_power_ovr_7_en, reset value: 0x0, access type: RW
	} bitFields;
} RegPhyRxtdAnt2AciBandPowerOvr47_u;

/*REG_PHY_RXTD_ANT2_ACI_BAND_POWER_OVR_8_11 0x304 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 aciBandPowerOvr8 : 7; //aci_band_power_ovr_8, reset value: 0x0, access type: RW
		uint32 aciBandPowerOvr8En : 1; //aci_band_power_ovr_8_en, reset value: 0x0, access type: RW
		uint32 aciBandPowerOvr9 : 7; //aci_band_power_ovr_9, reset value: 0x0, access type: RW
		uint32 aciBandPowerOvr9En : 1; //aci_band_power_ovr_9_en, reset value: 0x0, access type: RW
		uint32 aciBandPowerOvr10 : 7; //aci_band_power_ovr_10, reset value: 0x0, access type: RW
		uint32 aciBandPowerOvr10En : 1; //aci_band_power_ovr_10_en, reset value: 0x0, access type: RW
		uint32 aciBandPowerOvr11 : 7; //aci_band_power_ovr_11, reset value: 0x0, access type: RW
		uint32 aciBandPowerOvr11En : 1; //aci_band_power_ovr_11_en, reset value: 0x0, access type: RW
	} bitFields;
} RegPhyRxtdAnt2AciBandPowerOvr811_u;

/*REG_PHY_RXTD_ANT2_ACI_BAND_POWER_OVR_12_15 0x308 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 aciBandPowerOvr12 : 7; //aci_band_power_ovr_12, reset value: 0x0, access type: RW
		uint32 aciBandPowerOvr12En : 1; //aci_band_power_ovr_12_en, reset value: 0x0, access type: RW
		uint32 aciBandPowerOvr13 : 7; //aci_band_power_ovr_13, reset value: 0x0, access type: RW
		uint32 aciBandPowerOvr13En : 1; //aci_band_power_ovr_13_en, reset value: 0x0, access type: RW
		uint32 aciBandPowerOvr14 : 7; //aci_band_power_ovr_14, reset value: 0x0, access type: RW
		uint32 aciBandPowerOvr14En : 1; //aci_band_power_ovr_14_en, reset value: 0x0, access type: RW
		uint32 aciBandPowerOvr15 : 7; //aci_band_power_ovr_15, reset value: 0x0, access type: RW
		uint32 aciBandPowerOvr15En : 1; //aci_band_power_ovr_15_en, reset value: 0x0, access type: RW
	} bitFields;
} RegPhyRxtdAnt2AciBandPowerOvr1215_u;

/*REG_PHY_RXTD_ANT2_ACI_DET_RADAR_COUNTER_TH 0x30C */
typedef union
{
	uint32 val;
	struct
	{
		uint32 aciDetRadarCounterTh : 12; //aci_det_radar_counter_th, reset value: 0x16, access type: RW
		uint32 reserved0 : 20;
	} bitFields;
} RegPhyRxtdAnt2AciDetRadarCounterTh_u;

/*REG_PHY_RXTD_ANT2_LOOPBACK_PYPASS 0x310 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 pmLoopPrefilterBypass : 1; //pm_loop_prefilter_bypass, reset value: 0x0, access type: RW
		uint32 pmLoopFdlBypass : 1; //pm_loop_fdl_bypass, reset value: 0x0, access type: RW
		uint32 reserved0 : 30;
	} bitFields;
} RegPhyRxtdAnt2LoopbackPypass_u;

/*REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REGC5 0x314 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 fdlFreqShiftScale : 24; //fdl_freq_shift_scale, reset value: 0x0, access type: RO
		uint32 reserved0 : 8;
	} bitFields;
} RegPhyRxtdAnt2PhyRxtdAntRegc5_u;

/*REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REGC6 0x318 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 tdNcoFreq : 24; //td_nco_freq, reset value: 0x0, access type: RO
		uint32 reserved0 : 8;
	} bitFields;
} RegPhyRxtdAnt2PhyRxtdAntRegc6_u;

/*REG_PHY_RXTD_ANT2_PM_ACIDET_BYPASS_OFFSETS 0x31C */
typedef union
{
	uint32 val;
	struct
	{
		uint32 pmAcidetBypassOffsets : 1; //pm_acidet_bypass_offsets , reset value: 0x0, access type: RW
		uint32 reserved0 : 31;
	} bitFields;
} RegPhyRxtdAnt2PmAcidetBypassOffsets_u;

/*REG_PHY_RXTD_ANT2_ANTENNA_320M_MODE_CONTROLS 0x320 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 pmMixer80Bp : 1; //no description, reset value: 0x0, access type: RW
		uint32 pmSplitterBp : 1; //no description, reset value: 0x1, access type: RW
		uint32 reserved0 : 30;
	} bitFields;
} RegPhyRxtdAnt2Antenna320MModeControls_u;

/*REG_PHY_RXTD_ANT2_FDL_RESET_SHIFT 0x324 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 fdlResetShift04 : 7; //no description, reset value: 0x0, access type: RW
		uint32 reserved0 : 1;
		uint32 fdlResetShift08 : 7; //no description, reset value: 0x0, access type: RW
		uint32 reserved1 : 1;
		uint32 fdlResetShift16 : 7; //no description, reset value: 0x0, access type: RW
		uint32 reserved2 : 1;
		uint32 fdlResetShift32 : 7; //no description, reset value: 0x0, access type: RW
		uint32 reserved3 : 1;
	} bitFields;
} RegPhyRxtdAnt2FdlResetShift_u;

/*REG_PHY_RXTD_ANT2_ABB_DPD_CONTROLS 0x328 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 dpdFc2ScPhaseRegfile : 2; //no description, reset value: 0x0, access type: RW
		uint32 dpdSc2FcPhaseRegfile : 2; //no description, reset value: 0x0, access type: RW
		uint32 dpdSc2FcRxon : 2; //no description, reset value: 0x0, access type: RW
		uint32 reserved0 : 26;
	} bitFields;
} RegPhyRxtdAnt2AbbDpdControls_u;

/*REG_PHY_RXTD_ANT2_ABB_DFT_CONTROLS 0x32C */
typedef union
{
	uint32 val;
	struct
	{
		uint32 dftFc2ScPhaseRegfile : 2; //no description, reset value: 0x0, access type: RW
		uint32 dftSc2FcPhaseRegfile : 2; //no description, reset value: 0x0, access type: RW
		uint32 dftSc2FcRxon : 2; //no description, reset value: 0x0, access type: RW
		uint32 reserved0 : 26;
	} bitFields;
} RegPhyRxtdAnt2AbbDftControls_u;

/*REG_PHY_RXTD_ANT2_FDL_PPM_COMPUTE 0x330 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 fdlUseDetectorSsbShiftForPpmCalc : 1; //no description, reset value: 0x1, access type: RW
		uint32 reserved0 : 31;
	} bitFields;
} RegPhyRxtdAnt2FdlPpmCompute_u;

/*REG_PHY_RXTD_ANT2_FFT_IN_GAIN_MRU 0x334 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 fftInShift60 : 3; //Rx TD fft in shift for mru 60, reset value: 0x7, access type: RW
		uint32 fftInShift120 : 3; //Rx TD fft in shift for mru 120, reset value: 0x1, access type: RW
		uint32 fftInShift140 : 3; //Rx TD fft in shift for mru 140, reset value: 0x1, access type: RW
		uint32 fftInMult60 : 1; //Rx TD fft in mult for mru 60, reset value: 0x1, access type: RW
		uint32 fftInMult120 : 1; //Rx TD fft in mult for mru 120, reset value: 0x0, access type: RW
		uint32 fftInMult140 : 1; //Rx TD fft in mult for mru 140, reset value: 0x0, access type: RW
		uint32 reserved0 : 20;
	} bitFields;
} RegPhyRxtdAnt2FftInGainMru_u;

/*REG_PHY_RXTD_ANT2_PRE_FILTER_COEF_LEN_SEL 0x338 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 pmPreFilterCoefLenSel : 2; //no description, reset value: 0x0, access type: RW
		uint32 reserved0 : 30;
	} bitFields;
} RegPhyRxtdAnt2PreFilterCoefLenSel_u;

/*REG_PHY_RXTD_ANT2_INTERP_BEFORE_CHENNEL_FILTER 0x33C */
typedef union
{
	uint32 val;
	struct
	{
		uint32 pmInterp2En : 1; //pm_interp2_en, reset value: 0x0, access type: RW
		uint32 reserved0 : 31;
	} bitFields;
} RegPhyRxtdAnt2InterpBeforeChennelFilter_u;

/*REG_PHY_RXTD_ANT2_ACI_RSSI_MAX_BAND_PWR 0x340 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 aciRssiMaxBandPwr : 18; //aci_rssi_max_band_pwr, reset value: 0x0, access type: RO
		uint32 reserved0 : 14;
	} bitFields;
} RegPhyRxtdAnt2AciRssiMaxBandPwr_u;

/*REG_PHY_RXTD_ANT2_ACI_RSSI_MAX_BAND_PWR_HB 0x344 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 aciRssiMaxBandPwrHb : 18; //aci_rssi_max_band_pwr_hb, reset value: 0x0, access type: RO
		uint32 reserved0 : 14;
	} bitFields;
} RegPhyRxtdAnt2AciRssiMaxBandPwrHb_u;

/*REG_PHY_RXTD_ANT2_ACI_RSSI_SAT_FLAG 0x348 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 aciRssiHbSatFlag : 1; //aci_rssi_hb_sat_flag, reset value: 0x0, access type: RO
		uint32 aciRssiSatFlag : 1; //aci_rssi_sat_flag, reset value: 0x0, access type: RO
		uint32 reserved0 : 30;
	} bitFields;
} RegPhyRxtdAnt2AciRssiSatFlag_u;

/*REG_PHY_RXTD_ANT2_POWER_OPTIMIZATION 0x34C */
typedef union
{
	uint32 val;
	struct
	{
		uint32 powerSaveBeforeDetectionDisable : 1; //By default, Antenna data path will save power before detection.  , In this mode ('0') the modules from FDL in the antenna are driven by zeros to save switching power. Strobes and other control signals are flowing but high consuming logics are gated by LPS gators.  , Set this bit to "1" to disable this optimization. - will cause the module inputs to get received data instead of zeros. , reset value: 0x0, access type: RW
		uint32 powerSaveBeforeDetectionTdfifoExclude : 1; //by default, TD fifo will be part of the "power save before detection", , In cases of "late-detection" there are cases that power-save in TD FIFO writes causes garbage data to exit the FIFO.  , To overcome this issue turn on this parameter, reset value: 0x0, access type: RW
		uint32 powerSaveAfterDetectionFirDisable : 1; //by default, in Band#2 lower antennas the FIR arithmetic unit will be switched off when IIR is asserted-- , Set this control to 1 to disable (consume more power) , , reset value: 0x0, access type: RW
		uint32 reserved0 : 29;
	} bitFields;
} RegPhyRxtdAnt2PowerOptimization_u;

/*REG_PHY_RXTD_ANT2_EMULATION_CONTROL 0x350 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 pmDifi1EmulSel : 1; //Controls which data is selected to DIFI2 in EMULATION mode.   , In non-emulation mode this control is not connected to any logic.  , In EMULATION_MODE: , '0' selects the data from digital-loopback/DIFI1 input. , '1' selects the data coming from BaseBand connection for emulation. (rx_bb_emul_i/q_in) ,  , reset value: 0x0, access type: RW
		uint32 pmBbEmulSel : 1; //Controls which data is selected to M1 mixer in EMULATION MODE. , In non-emulation mode this control is not connected to any logic.  , In EMULATION_MODE: , '0' Selects IQ module to the M1 mixer , '1' Selects data coming from BaseBand connection for emulation (rx_bb_emul_i/q_in), reset value: 0x1, access type: RW
		uint32 reserved0 : 30;
	} bitFields;
} RegPhyRxtdAnt2EmulationControl_u;

/*REG_PHY_RXTD_ANT2_ACIDET_POW_HB 0x354 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 acidetPowHb : 9; //acidet_pow_hb, reset value: 0x0, access type: RO
		uint32 reserved0 : 23;
	} bitFields;
} RegPhyRxtdAnt2AcidetPowHb_u;

/*REG_PHY_RXTD_ANT2_PM_SPURC_NSAMP_THR_0 0x358 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 pmSpurcNsampThr0 : 32; //no description, reset value: 0x0, access type: RW
	} bitFields;
} RegPhyRxtdAnt2PmSpurcNsampThr0_u;

/*REG_PHY_RXTD_ANT2_PM_SPURC_POW_THR_LOW_0 0x35C */
typedef union
{
	uint32 val;
	struct
	{
		uint32 pmSpurcPowThrLow0 : 32; //no description, reset value: 0x0, access type: RW
	} bitFields;
} RegPhyRxtdAnt2PmSpurcPowThrLow0_u;

/*REG_PHY_RXTD_ANT2_PM_SPURC_POW_THR_HIGH_0 0x360 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 pmSpurcPowThrHigh0 : 32; //no description, reset value: 0x1000, access type: RW
	} bitFields;
} RegPhyRxtdAnt2PmSpurcPowThrHigh0_u;

/*REG_PHY_RXTD_ANT2_PM_SPURC_CONTROL_0 0x364 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 pmSpurcShutdown0 : 1; //no description, reset value: 0x1, access type: RW
		uint32 pmSpurcStop0 : 1; //no description, reset value: 0x0, access type: RW
		uint32 pmSpurcBypass0 : 1; //no description, reset value: 0x1, access type: RW
		uint32 pmSpurcFreeze0 : 1; //no description, reset value: 0x1, access type: RW
		uint32 pmSpurcAfeStable : 1; //no description, reset value: 0x0, access type: RW
		uint32 pmSpurcDoWhenAgc0 : 2; //no description, reset value: 0x1, access type: RW
		uint32 reserved0 : 25;
	} bitFields;
} RegPhyRxtdAnt2PmSpurcControl0_u;

/*REG_PHY_RXTD_ANT2_PM_SPURC_GAIN_TIMER_0 0x368 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 pmSpurcGainTimer0 : 32; //no description, reset value: 0x0, access type: RW
	} bitFields;
} RegPhyRxtdAnt2PmSpurcGainTimer0_u;

/*REG_PHY_RXTD_ANT2_PM_SPURC_DDFS_PHASE_ADJUST_0 0x36C */
typedef union
{
	uint32 val;
	struct
	{
		uint32 pmSpurcDdfsPhaseAdjust0 : 32; //no description, reset value: 0x0, access type: RW
	} bitFields;
} RegPhyRxtdAnt2PmSpurcDdfsPhaseAdjust0_u;

/*REG_PHY_RXTD_ANT2_PM_SPURC_DDFS_PHASE_INIT_0 0x370 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 pmSpurcDdfsPhaseInit0 : 32; //no description, reset value: 0x0, access type: RW
	} bitFields;
} RegPhyRxtdAnt2PmSpurcDdfsPhaseInit0_u;

/*REG_PHY_RXTD_ANT2_PM_SPURC_DDFS_FCW_0 0x374 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 pmSpurcDdfsFcw0 : 32; //no description, reset value: 0x0, access type: RW
	} bitFields;
} RegPhyRxtdAnt2PmSpurcDdfsFcw0_u;

/*REG_PHY_RXTD_ANT2_PM_SPURC_DDFS_P_Q_0 0x378 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 pmSpurcDdfsP0 : 9; //no description, reset value: 0x0, access type: RW
		uint32 pmSpurcDdfsQ0 : 9; //no description, reset value: 0x0, access type: RW
		uint32 reserved0 : 14;
	} bitFields;
} RegPhyRxtdAnt2PmSpurcDdfsPQ0_u;

/*REG_PHY_RXTD_ANT2_PM_SPURC_MEM_RESET_0 0x37C */
typedef union
{
	uint32 val;
	struct
	{
		uint32 pmSpurcMemReset0 : 1; //no description, reset value: 0x0, access type: RW
		uint32 reserved0 : 31;
	} bitFields;
} RegPhyRxtdAnt2PmSpurcMemReset0_u;

/*REG_PHY_RXTD_ANT2_PM_SPURC_MEM_LOAD_0 0x380 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 pmSpurcMemLoad0 : 3; //no description, reset value: 0x0, access type: RW
		uint32 reserved0 : 29;
	} bitFields;
} RegPhyRxtdAnt2PmSpurcMemLoad0_u;

/*REG_PHY_RXTD_ANT2_PM_SPURC_MEM_M_R_31_0_0 0x384 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 pmSpurcMemMR3100 : 32; //no description, reset value: 0x0, access type: RW
	} bitFields;
} RegPhyRxtdAnt2PmSpurcMemMR3100_u;

/*REG_PHY_RXTD_ANT2_PM_SPURC_MEM_M_R_37_32_0 0x388 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 pmSpurcMemMR37320 : 6; //no description, reset value: 0x0, access type: RW
		uint32 reserved0 : 26;
	} bitFields;
} RegPhyRxtdAnt2PmSpurcMemMR37320_u;

/*REG_PHY_RXTD_ANT2_PM_SPURC_MEM_M_I_31_0_0 0x38C */
typedef union
{
	uint32 val;
	struct
	{
		uint32 pmSpurcMemMI3100 : 32; //no description, reset value: 0x0, access type: RW
	} bitFields;
} RegPhyRxtdAnt2PmSpurcMemMI3100_u;

/*REG_PHY_RXTD_ANT2_PM_SPURC_MEM_M_I_37_32_0 0x390 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 pmSpurcMemMI37320 : 6; //no description, reset value: 0x0, access type: RW
		uint32 reserved0 : 26;
	} bitFields;
} RegPhyRxtdAnt2PmSpurcMemMI37320_u;

/*REG_PHY_RXTD_ANT2_PM_SPURC_MEM_NSAMP_0 0x394 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 pmSpurcMemNsamp0 : 32; //no description, reset value: 0x0, access type: RW
	} bitFields;
} RegPhyRxtdAnt2PmSpurcMemNsamp0_u;

/*REG_PHY_RXTD_ANT2_PM_SPURC_MEM_DIG_GAIN_0 0x398 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 pmSpurcMemDigGain0 : 7; //no description, reset value: 0x0, access type: RW
		uint32 reserved0 : 25;
	} bitFields;
} RegPhyRxtdAnt2PmSpurcMemDigGain0_u;

/*REG_PHY_RXTD_ANT2_PM_SPURC_MEM_ALPHA_IDX_0 0x39C */
typedef union
{
	uint32 val;
	struct
	{
		uint32 pmSpurcMemAlphaIdx0 : 4; //no description, reset value: 0x0, access type: RW
		uint32 reserved0 : 28;
	} bitFields;
} RegPhyRxtdAnt2PmSpurcMemAlphaIdx0_u;

/*REG_PHY_RXTD_ANT2_PM_SPURC_ALPHA_STEP_0_0 0x3A0 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 pmSpurcAlphaStep00 : 6; //no description, reset value: 0x0, access type: RW
		uint32 reserved0 : 26;
	} bitFields;
} RegPhyRxtdAnt2PmSpurcAlphaStep00_u;

/*REG_PHY_RXTD_ANT2_PM_SPURC_ALPHA_STEP_1_0 0x3A4 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 pmSpurcAlphaStep10 : 6; //no description, reset value: 0x0, access type: RW
		uint32 reserved0 : 26;
	} bitFields;
} RegPhyRxtdAnt2PmSpurcAlphaStep10_u;

/*REG_PHY_RXTD_ANT2_PM_SPURC_ALPHA_STEP_2_0 0x3A8 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 pmSpurcAlphaStep20 : 6; //no description, reset value: 0x0, access type: RW
		uint32 reserved0 : 26;
	} bitFields;
} RegPhyRxtdAnt2PmSpurcAlphaStep20_u;

/*REG_PHY_RXTD_ANT2_PM_SPURC_ALPHA_STEP_3_0 0x3AC */
typedef union
{
	uint32 val;
	struct
	{
		uint32 pmSpurcAlphaStep30 : 6; //no description, reset value: 0x0, access type: RW
		uint32 reserved0 : 26;
	} bitFields;
} RegPhyRxtdAnt2PmSpurcAlphaStep30_u;

/*REG_PHY_RXTD_ANT2_PM_SPURC_ALPHA_STEP_4_0 0x3B0 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 pmSpurcAlphaStep40 : 6; //no description, reset value: 0x0, access type: RW
		uint32 reserved0 : 26;
	} bitFields;
} RegPhyRxtdAnt2PmSpurcAlphaStep40_u;

/*REG_PHY_RXTD_ANT2_PM_SPURC_ALPHA_STEP_5_0 0x3B4 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 pmSpurcAlphaStep50 : 6; //no description, reset value: 0x0, access type: RW
		uint32 reserved0 : 26;
	} bitFields;
} RegPhyRxtdAnt2PmSpurcAlphaStep50_u;

/*REG_PHY_RXTD_ANT2_PM_SPURC_ALPHA_STEP_6_0 0x3B8 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 pmSpurcAlphaStep60 : 6; //no description, reset value: 0x0, access type: RW
		uint32 reserved0 : 26;
	} bitFields;
} RegPhyRxtdAnt2PmSpurcAlphaStep60_u;

/*REG_PHY_RXTD_ANT2_PM_SPURC_ALPHA_STEP_7_0 0x3BC */
typedef union
{
	uint32 val;
	struct
	{
		uint32 pmSpurcAlphaStep70 : 6; //no description, reset value: 0x0, access type: RW
		uint32 reserved0 : 26;
	} bitFields;
} RegPhyRxtdAnt2PmSpurcAlphaStep70_u;

/*REG_PHY_RXTD_ANT2_PM_SPURC_ALPHA_STEP_8_0 0x3C0 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 pmSpurcAlphaStep80 : 6; //no description, reset value: 0x0, access type: RW
		uint32 reserved0 : 26;
	} bitFields;
} RegPhyRxtdAnt2PmSpurcAlphaStep80_u;

/*REG_PHY_RXTD_ANT2_PM_SPURC_ALPHA_STEP_9_0 0x3C4 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 pmSpurcAlphaStep90 : 6; //no description, reset value: 0x0, access type: RW
		uint32 reserved0 : 26;
	} bitFields;
} RegPhyRxtdAnt2PmSpurcAlphaStep90_u;

/*REG_PHY_RXTD_ANT2_PM_SPURC_ALPHA_STEP_10_0 0x3C8 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 pmSpurcAlphaStep100 : 6; //no description, reset value: 0x0, access type: RW
		uint32 reserved0 : 26;
	} bitFields;
} RegPhyRxtdAnt2PmSpurcAlphaStep100_u;

/*REG_PHY_RXTD_ANT2_PM_SPURC_ALPHA_STEP_11_0 0x3CC */
typedef union
{
	uint32 val;
	struct
	{
		uint32 pmSpurcAlphaStep110 : 6; //no description, reset value: 0x0, access type: RW
		uint32 reserved0 : 26;
	} bitFields;
} RegPhyRxtdAnt2PmSpurcAlphaStep110_u;

/*REG_PHY_RXTD_ANT2_PM_SPURC_ALPHA_STEP_12_0 0x3D0 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 pmSpurcAlphaStep120 : 6; //no description, reset value: 0x0, access type: RW
		uint32 reserved0 : 26;
	} bitFields;
} RegPhyRxtdAnt2PmSpurcAlphaStep120_u;

/*REG_PHY_RXTD_ANT2_PM_SPURC_ALPHA_STEP_13_0 0x3D4 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 pmSpurcAlphaStep130 : 6; //no description, reset value: 0x0, access type: RW
		uint32 reserved0 : 26;
	} bitFields;
} RegPhyRxtdAnt2PmSpurcAlphaStep130_u;

/*REG_PHY_RXTD_ANT2_PM_SPURC_ALPHA_STEP_14_0 0x3D8 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 pmSpurcAlphaStep140 : 6; //no description, reset value: 0x0, access type: RW
		uint32 reserved0 : 26;
	} bitFields;
} RegPhyRxtdAnt2PmSpurcAlphaStep140_u;

/*REG_PHY_RXTD_ANT2_PM_SPURC_ALPHA_STEP_15_0 0x3DC */
typedef union
{
	uint32 val;
	struct
	{
		uint32 pmSpurcAlphaStep150 : 6; //no description, reset value: 0x0, access type: RW
		uint32 reserved0 : 26;
	} bitFields;
} RegPhyRxtdAnt2PmSpurcAlphaStep150_u;

/*REG_PHY_RXTD_ANT2_PM_SPURC_ALPHA_TIME_0_0 0x3E0 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 pmSpurcAlphaTime00 : 32; //no description, reset value: 0x0, access type: RW
	} bitFields;
} RegPhyRxtdAnt2PmSpurcAlphaTime00_u;

/*REG_PHY_RXTD_ANT2_PM_SPURC_ALPHA_TIME_1_0 0x3E4 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 pmSpurcAlphaTime10 : 32; //no description, reset value: 0x0, access type: RW
	} bitFields;
} RegPhyRxtdAnt2PmSpurcAlphaTime10_u;

/*REG_PHY_RXTD_ANT2_PM_SPURC_ALPHA_TIME_2_0 0x3E8 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 pmSpurcAlphaTime20 : 32; //no description, reset value: 0x0, access type: RW
	} bitFields;
} RegPhyRxtdAnt2PmSpurcAlphaTime20_u;

/*REG_PHY_RXTD_ANT2_PM_SPURC_ALPHA_TIME_3_0 0x3EC */
typedef union
{
	uint32 val;
	struct
	{
		uint32 pmSpurcAlphaTime30 : 32; //no description, reset value: 0x0, access type: RW
	} bitFields;
} RegPhyRxtdAnt2PmSpurcAlphaTime30_u;

/*REG_PHY_RXTD_ANT2_PM_SPURC_ALPHA_TIME_4_0 0x3F0 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 pmSpurcAlphaTime40 : 32; //no description, reset value: 0x0, access type: RW
	} bitFields;
} RegPhyRxtdAnt2PmSpurcAlphaTime40_u;

/*REG_PHY_RXTD_ANT2_PM_SPURC_ALPHA_TIME_5_0 0x3F4 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 pmSpurcAlphaTime50 : 32; //no description, reset value: 0x0, access type: RW
	} bitFields;
} RegPhyRxtdAnt2PmSpurcAlphaTime50_u;

/*REG_PHY_RXTD_ANT2_PM_SPURC_ALPHA_TIME_6_0 0x3F8 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 pmSpurcAlphaTime60 : 32; //no description, reset value: 0x0, access type: RW
	} bitFields;
} RegPhyRxtdAnt2PmSpurcAlphaTime60_u;

/*REG_PHY_RXTD_ANT2_PM_SPURC_ALPHA_TIME_7_0 0x3FC */
typedef union
{
	uint32 val;
	struct
	{
		uint32 pmSpurcAlphaTime70 : 32; //no description, reset value: 0x0, access type: RW
	} bitFields;
} RegPhyRxtdAnt2PmSpurcAlphaTime70_u;

/*REG_PHY_RXTD_ANT2_PM_SPURC_ALPHA_TIME_8_0 0x400 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 pmSpurcAlphaTime80 : 32; //no description, reset value: 0x0, access type: RW
	} bitFields;
} RegPhyRxtdAnt2PmSpurcAlphaTime80_u;

/*REG_PHY_RXTD_ANT2_PM_SPURC_ALPHA_TIME_9_0 0x404 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 pmSpurcAlphaTime90 : 32; //no description, reset value: 0x0, access type: RW
	} bitFields;
} RegPhyRxtdAnt2PmSpurcAlphaTime90_u;

/*REG_PHY_RXTD_ANT2_PM_SPURC_ALPHA_TIME_10_0 0x408 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 pmSpurcAlphaTime100 : 32; //no description, reset value: 0x0, access type: RW
	} bitFields;
} RegPhyRxtdAnt2PmSpurcAlphaTime100_u;

/*REG_PHY_RXTD_ANT2_PM_SPURC_ALPHA_TIME_11_0 0x40C */
typedef union
{
	uint32 val;
	struct
	{
		uint32 pmSpurcAlphaTime110 : 32; //no description, reset value: 0x0, access type: RW
	} bitFields;
} RegPhyRxtdAnt2PmSpurcAlphaTime110_u;

/*REG_PHY_RXTD_ANT2_PM_SPURC_ALPHA_TIME_12_0 0x410 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 pmSpurcAlphaTime120 : 32; //no description, reset value: 0x0, access type: RW
	} bitFields;
} RegPhyRxtdAnt2PmSpurcAlphaTime120_u;

/*REG_PHY_RXTD_ANT2_PM_SPURC_ALPHA_TIME_13_0 0x414 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 pmSpurcAlphaTime130 : 32; //no description, reset value: 0x0, access type: RW
	} bitFields;
} RegPhyRxtdAnt2PmSpurcAlphaTime130_u;

/*REG_PHY_RXTD_ANT2_PM_SPURC_ALPHA_TIME_14_0 0x418 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 pmSpurcAlphaTime140 : 32; //no description, reset value: 0x0, access type: RW
	} bitFields;
} RegPhyRxtdAnt2PmSpurcAlphaTime140_u;

/*REG_PHY_RXTD_ANT2_PM_SPURC_ALPHA_TIME_15_0 0x41C */
typedef union
{
	uint32 val;
	struct
	{
		uint32 pmSpurcAlphaTime150 : 32; //no description, reset value: 0x0, access type: RW
	} bitFields;
} RegPhyRxtdAnt2PmSpurcAlphaTime150_u;

/*REG_PHY_RXTD_ANT2_PM_SPURC_NSAMP_THR_1 0x420 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 pmSpurcNsampThr1 : 32; //no description, reset value: 0x0, access type: RW
	} bitFields;
} RegPhyRxtdAnt2PmSpurcNsampThr1_u;

/*REG_PHY_RXTD_ANT2_PM_SPURC_POW_THR_LOW_1 0x424 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 pmSpurcPowThrLow1 : 32; //no description, reset value: 0x0, access type: RW
	} bitFields;
} RegPhyRxtdAnt2PmSpurcPowThrLow1_u;

/*REG_PHY_RXTD_ANT2_PM_SPURC_POW_THR_HIGH_1 0x428 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 pmSpurcPowThrHigh1 : 32; //no description, reset value: 0x1000, access type: RW
	} bitFields;
} RegPhyRxtdAnt2PmSpurcPowThrHigh1_u;

/*REG_PHY_RXTD_ANT2_PM_SPURC_CONTROL_1 0x42C */
typedef union
{
	uint32 val;
	struct
	{
		uint32 pmSpurcShutdown1 : 1; //no description, reset value: 0x1, access type: RW
		uint32 pmSpurcStop1 : 1; //no description, reset value: 0x0, access type: RW
		uint32 pmSpurcBypass1 : 1; //no description, reset value: 0x1, access type: RW
		uint32 pmSpurcFreeze1 : 1; //no description, reset value: 0x1, access type: RW
		uint32 pmSpurcDoWhenAgc1 : 2; //no description, reset value: 0x1, access type: RW
		uint32 reserved0 : 26;
	} bitFields;
} RegPhyRxtdAnt2PmSpurcControl1_u;

/*REG_PHY_RXTD_ANT2_PM_SPURC_GAIN_TIMER_1 0x430 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 pmSpurcGainTimer1 : 32; //no description, reset value: 0x0, access type: RW
	} bitFields;
} RegPhyRxtdAnt2PmSpurcGainTimer1_u;

/*REG_PHY_RXTD_ANT2_PM_SPURC_DDFS_PHASE_ADJUST_1 0x434 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 pmSpurcDdfsPhaseAdjust1 : 32; //no description, reset value: 0x0, access type: RW
	} bitFields;
} RegPhyRxtdAnt2PmSpurcDdfsPhaseAdjust1_u;

/*REG_PHY_RXTD_ANT2_PM_SPURC_DDFS_PHASE_INIT_1 0x438 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 pmSpurcDdfsPhaseInit1 : 32; //no description, reset value: 0x0, access type: RW
	} bitFields;
} RegPhyRxtdAnt2PmSpurcDdfsPhaseInit1_u;

/*REG_PHY_RXTD_ANT2_PM_SPURC_DDFS_FCW_1 0x43C */
typedef union
{
	uint32 val;
	struct
	{
		uint32 pmSpurcDdfsFcw1 : 32; //no description, reset value: 0x0, access type: RW
	} bitFields;
} RegPhyRxtdAnt2PmSpurcDdfsFcw1_u;

/*REG_PHY_RXTD_ANT2_PM_SPURC_DDFS_P_Q_1 0x440 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 pmSpurcDdfsP1 : 9; //no description, reset value: 0x0, access type: RW
		uint32 pmSpurcDdfsQ1 : 9; //no description, reset value: 0x0, access type: RW
		uint32 reserved0 : 14;
	} bitFields;
} RegPhyRxtdAnt2PmSpurcDdfsPQ1_u;

/*REG_PHY_RXTD_ANT2_PM_SPURC_MEM_RESET_1 0x444 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 pmSpurcMemReset1 : 1; //no description, reset value: 0x0, access type: RW
		uint32 reserved0 : 31;
	} bitFields;
} RegPhyRxtdAnt2PmSpurcMemReset1_u;

/*REG_PHY_RXTD_ANT2_PM_SPURC_MEM_LOAD_1 0x448 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 pmSpurcMemLoad1 : 3; //no description, reset value: 0x0, access type: RW
		uint32 reserved0 : 29;
	} bitFields;
} RegPhyRxtdAnt2PmSpurcMemLoad1_u;

/*REG_PHY_RXTD_ANT2_PM_SPURC_MEM_M_R_31_0_1 0x44C */
typedef union
{
	uint32 val;
	struct
	{
		uint32 pmSpurcMemMR3101 : 32; //no description, reset value: 0x0, access type: RW
	} bitFields;
} RegPhyRxtdAnt2PmSpurcMemMR3101_u;

/*REG_PHY_RXTD_ANT2_PM_SPURC_MEM_M_R_37_32_1 0x450 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 pmSpurcMemMR37321 : 6; //no description, reset value: 0x0, access type: RW
		uint32 reserved0 : 26;
	} bitFields;
} RegPhyRxtdAnt2PmSpurcMemMR37321_u;

/*REG_PHY_RXTD_ANT2_PM_SPURC_MEM_M_I_31_0_1 0x454 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 pmSpurcMemMI3101 : 32; //no description, reset value: 0x0, access type: RW
	} bitFields;
} RegPhyRxtdAnt2PmSpurcMemMI3101_u;

/*REG_PHY_RXTD_ANT2_PM_SPURC_MEM_M_I_37_32_1 0x458 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 pmSpurcMemMI37321 : 6; //no description, reset value: 0x0, access type: RW
		uint32 reserved0 : 26;
	} bitFields;
} RegPhyRxtdAnt2PmSpurcMemMI37321_u;

/*REG_PHY_RXTD_ANT2_PM_SPURC_MEM_NSAMP_1 0x45C */
typedef union
{
	uint32 val;
	struct
	{
		uint32 pmSpurcMemNsamp1 : 32; //no description, reset value: 0x0, access type: RW
	} bitFields;
} RegPhyRxtdAnt2PmSpurcMemNsamp1_u;

/*REG_PHY_RXTD_ANT2_PM_SPURC_MEM_DIG_GAIN_1 0x460 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 pmSpurcMemDigGain1 : 7; //no description, reset value: 0x0, access type: RW
		uint32 reserved0 : 25;
	} bitFields;
} RegPhyRxtdAnt2PmSpurcMemDigGain1_u;

/*REG_PHY_RXTD_ANT2_PM_SPURC_MEM_ALPHA_IDX_1 0x464 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 pmSpurcMemAlphaIdx1 : 4; //no description, reset value: 0x0, access type: RW
		uint32 reserved0 : 28;
	} bitFields;
} RegPhyRxtdAnt2PmSpurcMemAlphaIdx1_u;

/*REG_PHY_RXTD_ANT2_PM_SPURC_ALPHA_STEP_0_1 0x468 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 pmSpurcAlphaStep01 : 6; //no description, reset value: 0x0, access type: RW
		uint32 reserved0 : 26;
	} bitFields;
} RegPhyRxtdAnt2PmSpurcAlphaStep01_u;

/*REG_PHY_RXTD_ANT2_PM_SPURC_ALPHA_STEP_1_1 0x46C */
typedef union
{
	uint32 val;
	struct
	{
		uint32 pmSpurcAlphaStep11 : 6; //no description, reset value: 0x0, access type: RW
		uint32 reserved0 : 26;
	} bitFields;
} RegPhyRxtdAnt2PmSpurcAlphaStep11_u;

/*REG_PHY_RXTD_ANT2_PM_SPURC_ALPHA_STEP_2_1 0x470 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 pmSpurcAlphaStep21 : 6; //no description, reset value: 0x0, access type: RW
		uint32 reserved0 : 26;
	} bitFields;
} RegPhyRxtdAnt2PmSpurcAlphaStep21_u;

/*REG_PHY_RXTD_ANT2_PM_SPURC_ALPHA_STEP_3_1 0x474 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 pmSpurcAlphaStep31 : 6; //no description, reset value: 0x0, access type: RW
		uint32 reserved0 : 26;
	} bitFields;
} RegPhyRxtdAnt2PmSpurcAlphaStep31_u;

/*REG_PHY_RXTD_ANT2_PM_SPURC_ALPHA_STEP_4_1 0x478 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 pmSpurcAlphaStep41 : 6; //no description, reset value: 0x0, access type: RW
		uint32 reserved0 : 26;
	} bitFields;
} RegPhyRxtdAnt2PmSpurcAlphaStep41_u;

/*REG_PHY_RXTD_ANT2_PM_SPURC_ALPHA_STEP_5_1 0x47C */
typedef union
{
	uint32 val;
	struct
	{
		uint32 pmSpurcAlphaStep51 : 6; //no description, reset value: 0x0, access type: RW
		uint32 reserved0 : 26;
	} bitFields;
} RegPhyRxtdAnt2PmSpurcAlphaStep51_u;

/*REG_PHY_RXTD_ANT2_PM_SPURC_ALPHA_STEP_6_1 0x480 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 pmSpurcAlphaStep61 : 6; //no description, reset value: 0x0, access type: RW
		uint32 reserved0 : 26;
	} bitFields;
} RegPhyRxtdAnt2PmSpurcAlphaStep61_u;

/*REG_PHY_RXTD_ANT2_PM_SPURC_ALPHA_STEP_7_1 0x484 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 pmSpurcAlphaStep71 : 6; //no description, reset value: 0x0, access type: RW
		uint32 reserved0 : 26;
	} bitFields;
} RegPhyRxtdAnt2PmSpurcAlphaStep71_u;

/*REG_PHY_RXTD_ANT2_PM_SPURC_ALPHA_STEP_8_1 0x488 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 pmSpurcAlphaStep81 : 6; //no description, reset value: 0x0, access type: RW
		uint32 reserved0 : 26;
	} bitFields;
} RegPhyRxtdAnt2PmSpurcAlphaStep81_u;

/*REG_PHY_RXTD_ANT2_PM_SPURC_ALPHA_STEP_9_1 0x48C */
typedef union
{
	uint32 val;
	struct
	{
		uint32 pmSpurcAlphaStep91 : 6; //no description, reset value: 0x0, access type: RW
		uint32 reserved0 : 26;
	} bitFields;
} RegPhyRxtdAnt2PmSpurcAlphaStep91_u;

/*REG_PHY_RXTD_ANT2_PM_SPURC_ALPHA_STEP_10_1 0x490 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 pmSpurcAlphaStep101 : 6; //no description, reset value: 0x0, access type: RW
		uint32 reserved0 : 26;
	} bitFields;
} RegPhyRxtdAnt2PmSpurcAlphaStep101_u;

/*REG_PHY_RXTD_ANT2_PM_SPURC_ALPHA_STEP_11_1 0x494 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 pmSpurcAlphaStep111 : 6; //no description, reset value: 0x0, access type: RW
		uint32 reserved0 : 26;
	} bitFields;
} RegPhyRxtdAnt2PmSpurcAlphaStep111_u;

/*REG_PHY_RXTD_ANT2_PM_SPURC_ALPHA_STEP_12_1 0x498 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 pmSpurcAlphaStep121 : 6; //no description, reset value: 0x0, access type: RW
		uint32 reserved0 : 26;
	} bitFields;
} RegPhyRxtdAnt2PmSpurcAlphaStep121_u;

/*REG_PHY_RXTD_ANT2_PM_SPURC_ALPHA_STEP_13_1 0x49C */
typedef union
{
	uint32 val;
	struct
	{
		uint32 pmSpurcAlphaStep131 : 6; //no description, reset value: 0x0, access type: RW
		uint32 reserved0 : 26;
	} bitFields;
} RegPhyRxtdAnt2PmSpurcAlphaStep131_u;

/*REG_PHY_RXTD_ANT2_PM_SPURC_ALPHA_STEP_14_1 0x4A0 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 pmSpurcAlphaStep141 : 6; //no description, reset value: 0x0, access type: RW
		uint32 reserved0 : 26;
	} bitFields;
} RegPhyRxtdAnt2PmSpurcAlphaStep141_u;

/*REG_PHY_RXTD_ANT2_PM_SPURC_ALPHA_STEP_15_1 0x4A4 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 pmSpurcAlphaStep151 : 6; //no description, reset value: 0x0, access type: RW
		uint32 reserved0 : 26;
	} bitFields;
} RegPhyRxtdAnt2PmSpurcAlphaStep151_u;

/*REG_PHY_RXTD_ANT2_PM_SPURC_ALPHA_TIME_0_1 0x4A8 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 pmSpurcAlphaTime01 : 32; //no description, reset value: 0x0, access type: RW
	} bitFields;
} RegPhyRxtdAnt2PmSpurcAlphaTime01_u;

/*REG_PHY_RXTD_ANT2_PM_SPURC_ALPHA_TIME_1_1 0x4AC */
typedef union
{
	uint32 val;
	struct
	{
		uint32 pmSpurcAlphaTime11 : 32; //no description, reset value: 0x0, access type: RW
	} bitFields;
} RegPhyRxtdAnt2PmSpurcAlphaTime11_u;

/*REG_PHY_RXTD_ANT2_PM_SPURC_ALPHA_TIME_2_1 0x4B0 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 pmSpurcAlphaTime21 : 32; //no description, reset value: 0x0, access type: RW
	} bitFields;
} RegPhyRxtdAnt2PmSpurcAlphaTime21_u;

/*REG_PHY_RXTD_ANT2_PM_SPURC_ALPHA_TIME_3_1 0x4B4 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 pmSpurcAlphaTime31 : 32; //no description, reset value: 0x0, access type: RW
	} bitFields;
} RegPhyRxtdAnt2PmSpurcAlphaTime31_u;

/*REG_PHY_RXTD_ANT2_PM_SPURC_ALPHA_TIME_4_1 0x4B8 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 pmSpurcAlphaTime41 : 32; //no description, reset value: 0x0, access type: RW
	} bitFields;
} RegPhyRxtdAnt2PmSpurcAlphaTime41_u;

/*REG_PHY_RXTD_ANT2_PM_SPURC_ALPHA_TIME_5_1 0x4BC */
typedef union
{
	uint32 val;
	struct
	{
		uint32 pmSpurcAlphaTime51 : 32; //no description, reset value: 0x0, access type: RW
	} bitFields;
} RegPhyRxtdAnt2PmSpurcAlphaTime51_u;

/*REG_PHY_RXTD_ANT2_PM_SPURC_ALPHA_TIME_6_1 0x4C0 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 pmSpurcAlphaTime61 : 32; //no description, reset value: 0x0, access type: RW
	} bitFields;
} RegPhyRxtdAnt2PmSpurcAlphaTime61_u;

/*REG_PHY_RXTD_ANT2_PM_SPURC_ALPHA_TIME_7_1 0x4C4 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 pmSpurcAlphaTime71 : 32; //no description, reset value: 0x0, access type: RW
	} bitFields;
} RegPhyRxtdAnt2PmSpurcAlphaTime71_u;

/*REG_PHY_RXTD_ANT2_PM_SPURC_ALPHA_TIME_8_1 0x4C8 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 pmSpurcAlphaTime81 : 32; //no description, reset value: 0x0, access type: RW
	} bitFields;
} RegPhyRxtdAnt2PmSpurcAlphaTime81_u;

/*REG_PHY_RXTD_ANT2_PM_SPURC_ALPHA_TIME_9_1 0x4CC */
typedef union
{
	uint32 val;
	struct
	{
		uint32 pmSpurcAlphaTime91 : 32; //no description, reset value: 0x0, access type: RW
	} bitFields;
} RegPhyRxtdAnt2PmSpurcAlphaTime91_u;

/*REG_PHY_RXTD_ANT2_PM_SPURC_ALPHA_TIME_10_1 0x4D0 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 pmSpurcAlphaTime101 : 32; //no description, reset value: 0x0, access type: RW
	} bitFields;
} RegPhyRxtdAnt2PmSpurcAlphaTime101_u;

/*REG_PHY_RXTD_ANT2_PM_SPURC_ALPHA_TIME_11_1 0x4D4 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 pmSpurcAlphaTime111 : 32; //no description, reset value: 0x0, access type: RW
	} bitFields;
} RegPhyRxtdAnt2PmSpurcAlphaTime111_u;

/*REG_PHY_RXTD_ANT2_PM_SPURC_ALPHA_TIME_12_1 0x4D8 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 pmSpurcAlphaTime121 : 32; //no description, reset value: 0x0, access type: RW
	} bitFields;
} RegPhyRxtdAnt2PmSpurcAlphaTime121_u;

/*REG_PHY_RXTD_ANT2_PM_SPURC_ALPHA_TIME_13_1 0x4DC */
typedef union
{
	uint32 val;
	struct
	{
		uint32 pmSpurcAlphaTime131 : 32; //no description, reset value: 0x0, access type: RW
	} bitFields;
} RegPhyRxtdAnt2PmSpurcAlphaTime131_u;

/*REG_PHY_RXTD_ANT2_PM_SPURC_ALPHA_TIME_14_1 0x4E0 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 pmSpurcAlphaTime141 : 32; //no description, reset value: 0x0, access type: RW
	} bitFields;
} RegPhyRxtdAnt2PmSpurcAlphaTime141_u;

/*REG_PHY_RXTD_ANT2_PM_SPURC_ALPHA_TIME_15_1 0x4E4 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 pmSpurcAlphaTime151 : 32; //no description, reset value: 0x0, access type: RW
	} bitFields;
} RegPhyRxtdAnt2PmSpurcAlphaTime151_u;

/*REG_PHY_RXTD_ANT2_PM_RXTD_SPURC_RAM_RM_0 0x4E8 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 pmRxtdSpurcRamRm0 : 32; //no description, reset value: 0x0, access type: RW
	} bitFields;
} RegPhyRxtdAnt2PmRxtdSpurcRamRm0_u;

/*REG_PHY_RXTD_ANT2_PM_RXTD_SPURC_RAM_RM_1 0x4EC */
typedef union
{
	uint32 val;
	struct
	{
		uint32 pmRxtdSpurcRamRm1 : 32; //no description, reset value: 0x0, access type: RW
	} bitFields;
} RegPhyRxtdAnt2PmRxtdSpurcRamRm1_u;

/*REG_PHY_RXTD_ANT2_PM_RXTD_SPURC_GAIN_WORD 0x4F0 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 pmSpurcGainWord : 14; //no description, reset value: 0x0, access type: RW
		uint32 reserved0 : 18;
	} bitFields;
} RegPhyRxtdAnt2PmRxtdSpurcGainWord_u;

/*REG_PHY_RXTD_ANT2_PM_WHITE_NOISE 0x4F4 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 whiteNoiseEnable : 1; //no description, reset value: 0x0, access type: RW
		uint32 whiteNoiseSnr : 8; //no description, reset value: 0x0, access type: RW
		uint32 reserved0 : 23;
	} bitFields;
} RegPhyRxtdAnt2PmWhiteNoise_u;

/*REG_PHY_RXTD_ANT2_PM_WHITE_NOISE_SEED 0x4F8 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 whiteNoiseSeed : 32; //no description, reset value: 0x0, access type: RW
	} bitFields;
} RegPhyRxtdAnt2PmWhiteNoiseSeed_u;

/*REG_PHY_RXTD_ANT2_PM_NOTCH_SPUR_BANDSEL_EN 0x4FC */
typedef union
{
	uint32 val;
	struct
	{
		uint32 pmNotchSpurBandselEn : 1; //Indicating that the specific notch spur mechanism for the specific antenna bandselect branch is enabled, reset value: 0x0, access type: RW
		uint32 reserved0 : 31;
	} bitFields;
} RegPhyRxtdAnt2PmNotchSpurBandselEn_u;

/*REG_PHY_RXTD_ANT2_PM_BANDSELECT_IIR_ALPHA 0x500 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 pmBandselectIirAlpha : 4; //Alpha value for the bandselect IIR notch filter, reset value: 0x9, access type: RW
		uint32 reserved0 : 28;
	} bitFields;
} RegPhyRxtdAnt2PmBandselectIirAlpha_u;

/*REG_PHY_RXTD_ANT2_PM_NOTCH_SPUR_MAIN_EN 0x504 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 pmNotchSpurMainEn : 1; //Indicating that the specific notch spur mechanism for the specific antenna main branch is enabled, reset value: 0x0, access type: RW
		uint32 reserved0 : 31;
	} bitFields;
} RegPhyRxtdAnt2PmNotchSpurMainEn_u;

/*REG_PHY_RXTD_ANT2_PM_MAIN_IIR_ALPHA 0x508 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 pmMainIirAlpha : 4; //Alpha value for the main IIR notch filter, reset value: 0x9, access type: RW
		uint32 reserved0 : 28;
	} bitFields;
} RegPhyRxtdAnt2PmMainIirAlpha_u;

/*REG_PHY_RXTD_ANT2_PM_NOTCH_SPUR_BYPASS_THR_20 0x50C */
typedef union
{
	uint32 val;
	struct
	{
		uint32 pmNotchSpurBypassThr20 : 9; //Compared to the aci_pwr. Above this threshold the notch_spur should be bypassed on BW20, reset value: 0x9, access type: RW
		uint32 reserved0 : 23;
	} bitFields;
} RegPhyRxtdAnt2PmNotchSpurBypassThr20_u;

/*REG_PHY_RXTD_ANT2_PM_NOTCH_SPUR_BYPASS_THR_40 0x510 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 pmNotchSpurBypassThr40 : 9; //Compared to the aci_pwr. Above this threshold the notch_spur should be bypassed on BW40, reset value: 0x9, access type: RW
		uint32 reserved0 : 23;
	} bitFields;
} RegPhyRxtdAnt2PmNotchSpurBypassThr40_u;

/*REG_PHY_RXTD_ANT2_PM_NOTCH_SPUR_BYPASS_THR_80 0x514 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 pmNotchSpurBypassThr80 : 9; //Compared to the aci_pwr. Above this threshold the notch_spur should be bypassed on BW80, reset value: 0x9, access type: RW
		uint32 reserved0 : 23;
	} bitFields;
} RegPhyRxtdAnt2PmNotchSpurBypassThr80_u;

/*REG_PHY_RXTD_ANT2_PM_NOTCH_SPUR_BYPASS_THR_160_320 0x518 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 pmNotchSpurBypassThr160320 : 9; //Compared to the aci_pwr. Above this threshold the notch_spur should be bypassed on BW160 or BW320, reset value: 0x9, access type: RW
		uint32 reserved0 : 23;
	} bitFields;
} RegPhyRxtdAnt2PmNotchSpurBypassThr160320_u;

/*REG_PHY_RXTD_ANT2_PM_NOTCH_SPUR_BYPASS_SRC_CURR 0x51C */
typedef union
{
	uint32 val;
	struct
	{
		uint32 pmNotchSpurBypassSrcCurr : 1; //Indicating if the bypass decision should be from the OR-ed  notch_spur_bypass_<curr|other>_ant ('0') or only from the current antenna ('1')., reset value: 0x1, access type: RW
		uint32 reserved0 : 31;
	} bitFields;
} RegPhyRxtdAnt2PmNotchSpurBypassSrcCurr_u;

/*REG_PHY_RXTD_ANT2_PM_NOTCH_SPUR_FREQ_OFFSET 0x520 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 pmNotchSpurFreqOffset : 12; //Frequency offset for NCO down conversion. , reset value: 0x0, access type: RW
		uint32 reserved0 : 20;
	} bitFields;
} RegPhyRxtdAnt2PmNotchSpurFreqOffset_u;

/*REG_PHY_RXTD_ANT2_PM_ACIDET_PWR 0x524 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 pmAcidetPwr : 9; //Store ACI measured power on ofdm detection, reset value: 0x0, access type: RO
		uint32 reserved0 : 23;
	} bitFields;
} RegPhyRxtdAnt2PmAcidetPwr_u;

/*REG_PHY_RXTD_ANT2_PM_NOTCH_SPUR_BYPASS_CURR_ANT 0x528 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 pmNotchSpurBypassCurrAnt : 1; //Current antenna dynamic bypass according to ACI power during ofdm detect, reset value: 0x0, access type: RO
		uint32 reserved0 : 31;
	} bitFields;
} RegPhyRxtdAnt2PmNotchSpurBypassCurrAnt_u;

/*REG_PHY_RXTD_ANT2_PM_NOTCH_SPUR_MAIN_BYPASS 0x52C */
typedef union
{
	uint32 val;
	struct
	{
		uint32 pmNotchSpurMainBypass : 1; //Final decision of the antenna dynamic bypass (with respect to the other antennas inside the segment), reset value: 0x0, access type: RO
		uint32 reserved0 : 31;
	} bitFields;
} RegPhyRxtdAnt2PmNotchSpurMainBypass_u;

//========================================
/* REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG00 0x0 */
#define B0_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG00_FIELD_FREQ_SHIFT_SIG3_BYPASS_MASK                                     0x00000001
//========================================
/* REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG01 0x4 */
#define B0_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG01_FIELD_IQ_MISMATCH_BYPASS_IIR_MASK                                     0x00000001
#define B0_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG01_FIELD_IQ_MISMATCH_BYPASS_EQ_MASK                                      0x00000002
#define B0_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG01_FIELD_IQ_MISMATCH_BYPASS_EQ_I2Q_MASK                                  0x00000004
#define B0_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG01_FIELD_IQ_W12_MOD_SEL_MASK                                             0x00000010
//========================================
/* REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG02 0x8 */
#define B0_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG02_FIELD_IQ_MISMATCH_IIR_MU_MASK                                         0x0000000F
#define B0_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG02_FIELD_IQ_MISMATCH_EST_REGULAR_I_SUM_MASK                              0x01000000
#define B0_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG02_FIELD_IQ_MISMATCH_EST_REGULAR_Q_SUM_MASK                              0x10000000
//========================================
/* REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG03 0xC */
#define B0_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG03_FIELD_IQ_MISMATCH_EQ_LENGTH_Q_MASK                                    0x00000070
//========================================
/* REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG04 0x10 */
#define B0_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG04_FIELD_IQ_MISMATCH_EST_ACC_COUNTER_MASK                                0x00FFFFFF
//========================================
/* REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG05 0x14 */
#define B0_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG05_FIELD_IQ_MISMATCH_EST_START_WORK_MASK                                 0x00000010
#define B0_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG05_FIELD_IQ_MISMATCH_EST_RESET_REGS_MASK                                 0x00000100
#define B0_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG05_FIELD_IQ_MISMATCH_EST_VALID_IQ_MASK                                   0x00001000
//========================================
/* REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG06 0x18 */
#define B0_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG06_FIELD_IQ_MISMATCH_EST_REG_II_MASK                                     0xFFFFFFFF
//========================================
/* REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG07 0x1C */
#define B0_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG07_FIELD_IQ_MISMATCH_EST_REG_QQ_MASK                                     0xFFFFFFFF
//========================================
/* REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG08 0x20 */
#define B0_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG08_FIELD_IQ_MISMATCH_EST_REG_IQ_MASK                                     0xFFFFFFFF
//========================================
/* REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG09 0x24 */
#define B0_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG09_FIELD_RX_IQ_SWAP_MASK                                                 0x00000001
//========================================
/* REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG0A 0x28 */
#define B0_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG0A_FIELD_RX_SPECTRUM_FLIP_MASK                                           0x00000010
//========================================
/* REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG0B 0x2C */
#define B0_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG0B_FIELD_GEORTZEL_RESET_ACUM_MASK                                        0x00000001
//========================================
/* REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG0C 0x30 */
#define B0_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG0C_FIELD_GEORTZEL_LENGTH_MASK                                            0x00FFF000
//========================================
/* REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG0D 0x34 */
#define B0_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG0D_FIELD_GEORTZEL_0_MUL_I_MASK                                           0x00003FFF
#define B0_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG0D_FIELD_GEORTZEL_0_MUL_Q_MASK                                           0x3FFF0000
//========================================
/* REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG0E 0x38 */
#define B0_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG0E_FIELD_GEORTZEL_1_MUL_I_MASK                                           0x00003FFF
#define B0_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG0E_FIELD_GEORTZEL_1_MUL_Q_MASK                                           0x3FFF0000
//========================================
/* REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG0F 0x3C */
#define B0_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG0F_FIELD_GEORTZEL0_CPLX_MODE_MASK                                        0x00000001
#define B0_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG0F_FIELD_GEORTZEL1_CPLX_MODE_MASK                                        0x00000002
#define B0_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG0F_FIELD_GEORTZEL_VALID_THR_MASK                                         0x00007F00
//========================================
/* REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG10 0x40 */
#define B0_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG10_FIELD_IQ_EQ_TAP0_MASK                                                 0x000003FF
//========================================
/* REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG11 0x44 */
#define B0_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG11_FIELD_IQ_EQ_TAP1_MASK                                                 0x000003FF
//========================================
/* REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG12 0x48 */
#define B0_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG12_FIELD_IQ_EQ_TAP2_MASK                                                 0x000003FF
//========================================
/* REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG13 0x4C */
#define B0_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG13_FIELD_IQ_EQ_TAP3_MASK                                                 0x000003FF
//========================================
/* REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG14 0x50 */
#define B0_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG14_FIELD_IQ_EQ_TAP4_MASK                                                 0x000003FF
//========================================
/* REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG15 0x54 */
#define B0_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG15_FIELD_IQ_EQ_TAP5_MASK                                                 0x000003FF
//========================================
/* REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG16 0x58 */
#define B0_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG16_FIELD_IQ_EQ_TAP6_MASK                                                 0x000003FF
//========================================
/* REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG17 0x5C */
#define B0_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG17_FIELD_IQ_EQ_TAP7_MASK                                                 0x000003FF
//========================================
/* REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG18 0x60 */
#define B0_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG18_FIELD_IQ_EQ_TAP8_MASK                                                 0x000003FF
//========================================
/* REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG19 0x64 */
#define B0_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG19_FIELD_IQ_EQ_TAP9_MASK                                                 0x000003FF
//========================================
/* REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG1A 0x68 */
#define B0_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG1A_FIELD_IQ_EQ_TAP10_MASK                                                0x000003FF
//========================================
/* REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG1B 0x6C */
#define B0_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG1B_FIELD_IQ_EQ_TAP11_MASK                                                0x000003FF
//========================================
/* REG_PHY_RXTD_ANT2_OLA_CONTROL 0x70 */
#define B0_PHY_RXTD_ANT2_OLA_CONTROL_FIELD_OLA_MODE_MASK                                                          0x00000007
#define B0_PHY_RXTD_ANT2_OLA_CONTROL_FIELD_OLA_FFT_IN_SHIFT_MASK                                                  0x00000070
#define B0_PHY_RXTD_ANT2_OLA_CONTROL_FIELD_OLA_FFT_IN_MULT_MASK                                                   0x00000080
#define B0_PHY_RXTD_ANT2_OLA_CONTROL_FIELD_OLA_NUM_OF_WINDOWS_MASK                                                0x00001F00
#define B0_PHY_RXTD_ANT2_OLA_CONTROL_FIELD_OLA_ZERO_INPUT_MASK                                                    0x00030000
#define B0_PHY_RXTD_ANT2_OLA_CONTROL_FIELD_OLA_ROUND_MASK                                                         0x01F00000
#define B0_PHY_RXTD_ANT2_OLA_CONTROL_FIELD_OLA_SOURCE_MASK                                                        0x70000000
//========================================
/* REG_PHY_RXTD_ANT2_OLA_START 0x78 */
#define B0_PHY_RXTD_ANT2_OLA_START_FIELD_OLA_START_MASK                                                           0x00000001
//========================================
/* REG_PHY_RXTD_ANT2_OLA_STATUS 0x7C */
#define B0_PHY_RXTD_ANT2_OLA_STATUS_FIELD_OLA_STATE_MASK                                                          0x00000007
#define B0_PHY_RXTD_ANT2_OLA_STATUS_FIELD_OLA_DONE_MASK                                                           0x00000010
//========================================
/* REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG20 0x80 */
#define B0_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG20_FIELD_IQ_COEF_RM_MASK                                                 0x00700000
//========================================
/* REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG21 0x84 */
#define B0_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG21_FIELD_RX_FIFO_RM_MASK                                                 0x00000007
#define B0_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG21_FIELD_FFT_0_RM_MASK                                                   0x00000038
#define B0_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG21_FIELD_FFT_1_RM_MASK                                                   0x000001C0
#define B0_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG21_FIELD_BANDSEL_FIR_DPMEM_RM_MASK                                       0x00000E00
#define B0_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG21_FIELD_CHANFILT_MID_DELAY_FIFO_RM_MASK                                 0x00007000
#define B0_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG21_FIELD_CHANFILT_COEFF_LUT_RM_MASK                                      0x00038000
#define B0_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG21_FIELD_BANDSEL_FIR_COEFF_RM_MASK                                       0x001C0000
#define B0_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG21_FIELD_IIR_MEM_RM_MASK                                                 0x00E00000
#define B0_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG21_FIELD_RX_FIFO_2_RM_MASK                                               0x07000000
//========================================
/* REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG22 0x88 */
#define B0_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG22_FIELD_DC_REG_I_MASK                                                   0x0003FFFF
#define B0_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG22_FIELD_DC_REMOVAL_BYPASS_MASK                                          0x00040000
//========================================
/* REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG23 0x8C */
#define B0_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG23_FIELD_DC_REG_Q_MASK                                                   0x0003FFFF
//========================================
/* REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG24 0x90 */
#define B0_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG24_FIELD_IQ_FDL_BYPASS_MASK                                              0x00000002
#define B0_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG24_FIELD_IQ_FDL_BYPASS_RAM_MASK                                          0x00000004
//========================================
/* REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG25 0x94 */
#define B0_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG25_FIELD_IQ_EQ_BYPASS_RAM_MASK                                           0x00000002
#define B0_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG25_FIELD_IQ_W12_BYPASS_MASK                                              0x00000004
#define B0_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG25_FIELD_IQ_PGC_FROM_AGC_ACC_MASK                                        0x00000008
#define B0_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG25_FIELD_IQ_FIR_DECOR_ORDER_MASK                                         0x00000020
//========================================
/* REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG26 0x98 */
#define B0_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG26_FIELD_IQ_MISMATCH_EST_RATE_MASK                                       0x00000001
#define B0_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG26_FIELD_IQ_MISMATCH_ACCUM_RSSI_MASK                                     0x00000002
#define B0_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG26_FIELD_IQ_MISMATCH_EST_IQ_FIX_SELECT_MASK                              0x00000004
#define B0_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG26_FIELD_IQ_MISMATCH_EST_CALIBTRATIONS_CORR_SELECT_MASK                  0x00000008
#define B0_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG26_FIELD_IQ_MISMATCH_EST_SHIFT_MASK                                      0x000000F0
//========================================
/* REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG27 0x9C */
#define B0_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG27_FIELD_IQ_MISMATCH_EST_OF_II_MASK                                      0x00000001
#define B0_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG27_FIELD_IQ_MISMATCH_EST_OF_QQ_MASK                                      0x00000002
#define B0_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG27_FIELD_IQ_MISMATCH_EST_OF_IQ_MASK                                      0x00000004
//========================================
/* REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG28 0xA0 */
#define B0_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG28_FIELD_IQ_RAM_READ_TRIGGER_MASK                                        0x00000001
//========================================
/* REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG29 0xA4 */
#define B0_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG29_FIELD_IQ_EQ_USED_TAP0_MASK                                            0x000003FF
//========================================
/* REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG2A 0xA8 */
#define B0_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG2A_FIELD_IQ_EQ_USED_TAP1_MASK                                            0x000003FF
//========================================
/* REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG2B 0xAC */
#define B0_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG2B_FIELD_IQ_EQ_USED_TAP2_MASK                                            0x000003FF
//========================================
/* REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG2C 0xB0 */
#define B0_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG2C_FIELD_IQ_EQ_USED_TAP3_MASK                                            0x000003FF
//========================================
/* REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG2D 0xB4 */
#define B0_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG2D_FIELD_IQ_EQ_USED_TAP4_MASK                                            0x000003FF
//========================================
/* REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG2E 0xB8 */
#define B0_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG2E_FIELD_IQ_EQ_USED_TAP5_MASK                                            0x000003FF
//========================================
/* REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG2F 0xBC */
#define B0_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG2F_FIELD_IQ_EQ_USED_TAP6_MASK                                            0x000003FF
//========================================
/* REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG30 0xC0 */
#define B0_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG30_FIELD_IQ_EQ_USED_TAP7_MASK                                            0x000003FF
//========================================
/* REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG31 0xC4 */
#define B0_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG31_FIELD_IQ_EQ_USED_TAP8_MASK                                            0x000003FF
//========================================
/* REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG32 0xC8 */
#define B0_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG32_FIELD_IQ_EQ_USED_TAP9_MASK                                            0x000003FF
//========================================
/* REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG33 0xCC */
#define B0_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG33_FIELD_IQ_EQ_USED_TAP10_MASK                                           0x000003FF
//========================================
/* REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG34 0xD0 */
#define B0_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG34_FIELD_IQ_EQ_USED_TAP11_MASK                                           0x000003FF
//========================================
/* REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG3B 0xEC */
#define B0_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG3B_FIELD_RX_DIFI1_DC_CANCEL_ENABLE_MASK                                  0x00000001
#define B0_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG3B_FIELD_RX_DIFI1_DC_CANCEL_HW_SELECT_MASK                               0x00000002
#define B0_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG3B_FIELD_RX_DIFI2_RSSI_GAIN_HW_SELECT_MASK                               0x00000004
//========================================
/* REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG3C 0xF0 */
#define B0_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG3C_FIELD_DIFI1_DC_CANCEL_I_MASK                                          0x00003FFF
#define B0_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG3C_FIELD_DIFI1_DC_CANCEL_Q_MASK                                          0x0FFFC000
//========================================
/* REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG3D 0xF4 */
#define B0_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG3D_FIELD_GEORTZEL_0_I_RESULT_MASK                                        0x3FFFFFFF
//========================================
/* REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG3E 0xF8 */
#define B0_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG3E_FIELD_GEORTZEL_0_Q_RESULT_MASK                                        0x3FFFFFFF
#define B0_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG3E_FIELD_GEORTZEL_0_DATA_VALID_MASK                                      0x80000000
//========================================
/* REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG3F 0xFC */
#define B0_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG3F_FIELD_GEORTZEL_1_I_RESULT_MASK                                        0x3FFFFFFF
//========================================
/* REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG40 0x100 */
#define B0_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG40_FIELD_GEORTZEL_1_Q_RESULT_MASK                                        0x3FFFFFFF
#define B0_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG40_FIELD_GEORTZEL_1_DATA_VALID_MASK                                      0x80000000
//========================================
/* REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG41 0x104 */
#define B0_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG41_FIELD_FFT_IN_SHIFT_26B_MASK                                           0x00000007
#define B0_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG41_FIELD_FFT_IN_SHIFT_52B_MASK                                           0x00000038
#define B0_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG41_FIELD_FFT_IN_SHIFT_106B_MASK                                          0x000001C0
#define B0_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG41_FIELD_FFT_IN_SHIFT20_MASK                                             0x00000E00
#define B0_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG41_FIELD_FFT_IN_SHIFT40_MASK                                             0x00007000
#define B0_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG41_FIELD_FFT_IN_SHIFT80_MASK                                             0x00038000
#define B0_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG41_FIELD_FFT_IN_SHIFT160_MASK                                            0x001C0000
#define B0_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG41_FIELD_FFT_IN_SHIFT_HESTF_MASK                                         0x00E00000
#define B0_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG41_FIELD_FFT_IN_MULT_26B_MASK                                            0x01000000
#define B0_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG41_FIELD_FFT_IN_MULT_52B_MASK                                            0x02000000
#define B0_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG41_FIELD_FFT_IN_MULT_106B_MASK                                           0x04000000
#define B0_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG41_FIELD_FFT_IN_MULT20_MASK                                              0x08000000
#define B0_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG41_FIELD_FFT_IN_MULT40_MASK                                              0x10000000
#define B0_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG41_FIELD_FFT_IN_MULT80_MASK                                              0x20000000
#define B0_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG41_FIELD_FFT_IN_MULT160_MASK                                             0x40000000
#define B0_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG41_FIELD_FFT_IN_MULT_HESTF_MASK                                          0x80000000
//========================================
/* REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG42 0x108 */
#define B0_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG42_FIELD_RF_CAL_MODE_MASK                                                0x00000001
//========================================
/* REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG43 0x10C */
#define B0_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG43_FIELD_AFE_TP_CONTROL_MASK                                             0x00000003
#define B0_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG43_FIELD_DECIMATOR_TP_CONTROL_MASK                                       0x00000010
//========================================
/* REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG44 0x110 */
#define B0_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG44_FIELD_RX_DIGITAL_GAIN_ENABLE_MASK                                     0x00000001
//========================================
/* REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG45 0x114 */
#define B0_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG45_FIELD_MEM_GLOBAL_RM_MASK                                              0x00000003
//========================================
/* REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG46 0x118 */
#define B0_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG46_FIELD_FCSI_GR_ADDR_MASK                                               0x0000007F
#define B0_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG46_FIELD_FCSI_GR_WR_DATA_MASK                                            0x00FFFF00
//========================================
/* REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG47 0x11C */
#define B0_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG47_FIELD_FCSI_RD_DATA_MASK                                               0x0000FFFF
//========================================
/* REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG48 0x120 */
#define B0_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG48_FIELD_FCSI_CLK_WR_DIVR_EXT_RF_MASK                                    0x0000003F
#define B0_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG48_FIELD_FCSI_CLK_RD_DIVR_EXT_RF_MASK                                    0x00003F00
//========================================
/* REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG49 0x124 */
#define B0_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG49_FIELD_FCSI_CLK_WR_DIVR_AFE_MASK                                       0x0000003F
#define B0_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG49_FIELD_FCSI_CLK_RD_DIVR_AFE_MASK                                       0x00003F00
//========================================
/* REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG4A 0x128 */
#define B0_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG4A_FIELD_EXTERNAL_RF_MODE_MASK                                           0x00000001
#define B0_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG4A_FIELD_FCSI_MODE_MS_MASK                                               0x00000010
#define B0_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG4A_FIELD_FCSI_MODE_RF_EXT_MASK                                           0x00000020
#define B0_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG4A_FIELD_FCSI_ADDITIONAL_CYCLES_MASK                                     0x00000F00
//========================================
/* REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG4B 0x12C */
#define B0_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG4B_FIELD_FCSI_MS_RESET_ANTENNAS_N_MASK                                   0x00000001
#define B0_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG4B_FIELD_FCSI_RF_RESET_N_MASK                                            0x00000010
//========================================
/* REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG4C 0x130 */
#define B0_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG4C_FIELD_HYP_FCSI_STATE_MACHINE_MASK                                     0x00000007
#define B0_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG4C_FIELD_HYP_FCSI_COUNTER_MASK                                           0x000000F8
#define B0_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG4C_FIELD_HYP_FCSI_COUNTER_LIMIT_MASK                                     0x00001F00
#define B0_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG4C_FIELD_HYP_FCSI_CLOCK_ACTIVE_MASK                                      0x00002000
#define B0_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG4C_FIELD_HYP_FCSI_CLOCK_ENABLE_MASK                                      0x00004000
#define B0_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG4C_FIELD_HYP_FCSI_ACTIVE_MASK                                            0x00008000
//========================================
/* REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG4D 0x134 */
#define B0_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG4D_FIELD_FCSI_FORCE_DEFAULT_WLAN2MS_MASK                                 0x00000001
//========================================
/* REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG4E 0x138 */
#define B0_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG4E_FIELD_ANTENNA_RESET_ENABLE_MASK                                       0x00000001
//========================================
/* REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG4F 0x13C */
#define B0_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG4F_FIELD_RX_LPBK_SELECT_MASK                                             0x00000003
//========================================
/* REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG50 0x140 */
#define B0_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG50_FIELD_RF_FREQ_MHZ_MASK                                                0x00001FFF
#define B0_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG50_FIELD_FDL_IQ_COMP_MASK                                                0x3FFFC000
#define B0_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG50_FIELD_FDL_BYPASS_MASK                                                 0x40000000
//========================================
/* REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG51 0x144 */
#define B0_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG51_FIELD_FDL_NCO_UP_LIM_MASK                                             0x3FFFFFFF
#define B0_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG51_FIELD_FREQ_SHIFT_M1_BYPASS_MASK                                       0x40000000
#define B0_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG51_FIELD_FREQ_SHIFT_M2_BYPASS_MASK                                       0x80000000
//========================================
/* REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG52 0x148 */
#define B0_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG52_FIELD_CHANFILT_BYPASS_MASK                                            0x00000001
#define B0_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG52_FIELD_CHANFILT_CHANGE_PHASE_MASK                                      0x0000001E
#define B0_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG52_FIELD_CHANFILT_LD_SRC_MASK                                            0x00000060
#define B0_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG52_FIELD_CHANFILT_COEF_LOAD_MASK                                         0x00000080
#define B0_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG52_FIELD_CHANFILT_COEF_DBG_MASK                                          0x00003F00
#define B0_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG52_FIELD_CHANFILT_FLEX_LENGTH_MASK                                       0x00004000
#define B0_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG52_FIELD_CHANFILT_DIS_ZOUT_MASK                                          0x00008000
#define B0_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG52_FIELD_FRC_CHANGE_LOAD_MASK                                            0x00010000
#define B0_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG52_FIELD_FRC_LUT_GAIN_DIS_MASK                                           0x00020000
#define B0_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG52_FIELD_FRC_RSSI_GAIN_DIS_MASK                                          0x00040000
#define B0_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG52_FIELD_CHANFILT_GAIN_MASK                                              0x03F80000
#define B0_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG52_FIELD_CHANFILT_IIR_MODE_MASK                                          0x0C000000
#define B0_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG52_FIELD_IIR_EN_ALIGNED_TO_STROBES_DISABLE_MASK                          0x10000000
//========================================
/* REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG53 0x14C */
#define B0_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG53_FIELD_FRC_BYPASS_MASK                                                 0x00000001
#define B0_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG53_FIELD_SIG3_BYPASS_MASK                                                0x00000002
#define B0_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG53_FIELD_FRC_OFDM_BYPASS_MASK                                            0x00000004
#define B0_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG53_FIELD_B_BYPASS_MASK                                                   0x00000008
#define B0_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG53_FIELD_DISABLE_PRIMARY_DETECTION_MASK                                  0x00000010
#define B0_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG53_FIELD_RX_FREQ_SHIFT_MODE_MASK                                         0x00000020
#define B0_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG53_FIELD_RX_FREQ_WAIT_FOR_RAS_MASK                                       0x00000040
#define B0_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG53_FIELD_FRC_FW_SHIFT1_MASK                                              0x0000F000
#define B0_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG53_FIELD_FRC_FW_SHIFT2_MASK                                              0x000F0000
#define B0_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG53_FIELD_FRC_FW_CNTR_MASK                                                0xFFF00000
//========================================
/* REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG54 0x150 */
#define B0_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG54_FIELD_FRC_OFDM_CNTR_MASK                                              0x00000FFF
#define B0_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG54_FIELD_FRC_SIG3_CNTR_MASK                                              0x00FFF000
//========================================
/* REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG55 0x154 */
#define B0_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG55_FIELD_FRC_11B_CNTR_MASK                                               0x00000FFF
#define B0_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG55_FIELD_CHANFILT_IDLE_20MHZ_MASK                                        0x00007000
#define B0_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG55_FIELD_CHANFILT_IDLE_40MHZ_MASK                                        0x00038000
#define B0_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG55_FIELD_CHANFILT_IDLE_80MHZ_MASK                                        0x001C0000
#define B0_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG55_FIELD_CHANFILT_IDLE_160MHZ_MASK                                       0x00E00000
#define B0_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG55_FIELD_CHANFILT_LEGACY_20MHZ_MASK                                      0x07000000
#define B0_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG55_FIELD_CHANFILT_LEGACY_40MHZ_MASK                                      0x38000000
//========================================
/* REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG56 0x158 */
#define B0_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG56_FIELD_CHANFILT_LEGACY_80MHZ_MASK                                      0x00000007
#define B0_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG56_FIELD_CHANFILT_LEGACY_160MHZ_MASK                                     0x00000038
#define B0_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG56_FIELD_DET_802_11B_FILT_MASK                                           0x000001C0
#define B0_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG56_FIELD_CHANFILT_FORCE_AC_MASK                                          0x00000400
#define B0_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG56_FIELD_CHANFILT_FORCE_ACI_20MHZ_MASK                                   0x00001800
#define B0_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG56_FIELD_CHANFILT_FORCE_ACI_40MHZ_MASK                                   0x00006000
#define B0_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG56_FIELD_CHANFILT_FORCE_ACI_80MHZ_MASK                                   0x00018000
#define B0_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG56_FIELD_CHANFILT_FORCE_ACI_160MHZ_MASK                                  0x00060000
#define B0_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG56_FIELD_CHANFILT_HE_LOWPASS_SEL_MASK                                    0x00180000
#define B0_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG56_FIELD_CHANFILT_FORCE_IMMEDIATE_MASK                                   0x00200000
#define B0_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG56_FIELD_CHANFILT_FORCE_BW_MASK                                          0x00C00000
#define B0_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG56_FIELD_CHANFILT_FORCE_FILT_MASK                                        0x07000000
#define B0_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG56_FIELD_CHANFILT_FORCE_NATURAL_MASK                                     0x08000000
#define B0_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG56_FIELD_CHANFILT_FULL_SW_CTRL_MASK                                      0x10000000
#define B0_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG56_FIELD_CHANFILT_HE_LOWPASS_WIDE_SEL_MASK                               0x60000000
//========================================
/* REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG57 0x15C */
#define B0_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG57_FIELD_BANDSEL_INIT_GAIN_MASK                                          0x000007F0
#define B0_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG57_FIELD_BANDSEL_INIT_GAIN_VALID_MASK                                    0x00010000
//========================================
/* REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG58 0x160 */
#define B0_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG58_FIELD_DC_IIR_BANDSEL_BYPASS_MASK                                      0x00000001
#define B0_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG58_FIELD_DC_IIR_BANDSEL_ALPHA_MASK                                       0x0000001E
#define B0_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG58_FIELD_DC_IIR_DET_BYPASS_MASK                                          0x00000020
#define B0_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG58_FIELD_DC_IIR_DET_ALPHA_MASK                                           0x000003C0
//========================================
/* REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG60 0x180 */
#define B0_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG60_FIELD_DIFI2_OP_GAIN_DB_MASK                                           0x0007F000
#define B0_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG60_FIELD_RSSI_DIFI2_OP_GAIN_DB_MASK                                      0x03F80000
//========================================
/* REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG61 0x184 */
#define B0_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG61_FIELD_C64_DIFF_MODE_MASK                                              0x00000001
#define B0_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG61_FIELD_DET_C64_MRB_EN_MASK                                             0x00000002
#define B0_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG61_FIELD_DET_160M_PHASE_MASK                                             0x00000004
//========================================
/* REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG62 0x188 */
#define B0_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG62_FIELD_MEM_GLOBAL_TEST_MODE_MASK                                       0x00000003
//========================================
/* REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG63 0x18C */
#define B0_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG63_FIELD_SW_BIST_START_MASK                                              0x00000001
#define B0_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG63_FIELD_CLEAR_RAM_MODE_MASK                                             0x00000002
#define B0_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG63_FIELD_BIST_SCR_BYPASS_MASK                                            0x00000004
//========================================
/* REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG64 0x190 */
#define B0_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG64_FIELD_DET_PPM_FREQ_OFFSET_MASK                                        0x000FFFFF
//========================================
/* REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG65 0x194 */
#define B0_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG65_FIELD_IQ_PGC_MASK                                                     0x0001C000
//========================================
/* REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG66 0x198 */
#define B0_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG66_FIELD_IQ_W1_MOD0_MASK                                                 0x00001FFF
#define B0_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG66_FIELD_IQ_W2_MOD0_MASK                                                 0x00FFE000
//========================================
/* REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG67 0x19C */
#define B0_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG67_FIELD_IQ_W1_MOD1_MASK                                                 0x00001FFF
#define B0_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG67_FIELD_IQ_W2_MOD1_MASK                                                 0x00FFE000
//========================================
/* REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG69 0x1A4 */
#define B0_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG69_FIELD_IQ_FIR_DELAY_MASK                                               0x07000000
//========================================
/* REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG6A 0x1A8 */
#define B0_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG6A_FIELD_PM_CCA_DB_OFFSET_MASK                                           0x00000FFF
//========================================
/* REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG6B 0x1AC */
#define B0_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG6B_FIELD_PM_CCA_BW_MASK                                                  0x00000007
//========================================
/* REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG6C 0x1B0 */
#define B0_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG6C_FIELD_PM_CCA_ACC_SAMPLES_MASK                                         0x00000001
//========================================
/* REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG6D 0x1B4 */
#define B0_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG6D_FIELD_PM_CCA_RF_CORRECTION_160_0_MASK                                 0x0000003F
#define B0_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG6D_FIELD_PM_CCA_RF_CORRECTION_160_1_MASK                                 0x00003F00
#define B0_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG6D_FIELD_PM_CCA_RF_CORRECTION_160_2_MASK                                 0x003F0000
#define B0_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG6D_FIELD_PM_CCA_RF_CORRECTION_160_3_MASK                                 0x3F000000
//========================================
/* REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG6E 0x1B8 */
#define B0_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG6E_FIELD_PM_CCA_RF_CORRECTION_160_4_MASK                                 0x0000003F
#define B0_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG6E_FIELD_PM_CCA_RF_CORRECTION_160_5_MASK                                 0x00003F00
#define B0_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG6E_FIELD_PM_CCA_RF_CORRECTION_160_6_MASK                                 0x003F0000
#define B0_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG6E_FIELD_PM_CCA_RF_CORRECTION_160_7_MASK                                 0x3F000000
//========================================
/* REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG6F 0x1BC */
#define B0_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG6F_FIELD_PM_CCA_RF_CORRECTION_80_0_MASK                                  0x0000003F
#define B0_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG6F_FIELD_PM_CCA_RF_CORRECTION_80_1_MASK                                  0x00003F00
#define B0_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG6F_FIELD_PM_CCA_RF_CORRECTION_80_2_MASK                                  0x003F0000
#define B0_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG6F_FIELD_PM_CCA_RF_CORRECTION_80_3_MASK                                  0x3F000000
//========================================
/* REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG70 0x1C0 */
#define B0_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG70_FIELD_PM_CCA_RF_CORRECTION_40_0_MASK                                  0x0000003F
#define B0_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG70_FIELD_PM_CCA_RF_CORRECTION_40_1_MASK                                  0x00003F00
//========================================
/* REG_PHY_RXTD_ANT2_RX_ABB_ANT_REG71 0x1C4 */
#define B0_PHY_RXTD_ANT2_RX_ABB_ANT_REG71_FIELD_RX_SC2FC_PHASE_REGFILE_MASK                                       0x00000003
#define B0_PHY_RXTD_ANT2_RX_ABB_ANT_REG71_FIELD_RX_FC2SC_PHASE_REGFILE_MASK                                       0x0000000C
#define B0_PHY_RXTD_ANT2_RX_ABB_ANT_REG71_FIELD_RX_SC2FC_RXON_MASK                                                0x00000030
//========================================
/* REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG72 0x1C8 */
#define B0_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG72_FIELD_PM_BYPASS_SEL_LPBK_AFE_N_MASK                                   0x00000001
#define B0_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG72_FIELD_PM_DIFI1_BYPASS_MASK                                            0x00000002
#define B0_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG72_FIELD_PM_DIFI2_BYPASS_MASK                                            0x00000004
#define B0_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG72_FIELD_PM_DIFI1_LPBK_TYPE_MASK                                         0x00000008
#define B0_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG72_FIELD_PM_DIFI2_SHIFT_BY_320M_MASK                                     0x00010000
#define B0_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG72_FIELD_PM_DIFI3_BYPASS_MASK                                            0x00020000
//========================================
/* REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG73 0x1CC */
#define B0_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG73_FIELD_PM_ACIDET_BLK_SIZE_MASK                                         0x000000FF
#define B0_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG73_FIELD_PM_ACIDET_ACI_DET_TRIG_MASK                                     0x00000100
//========================================
/* REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG74 0x1D0 */
#define B0_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG74_FIELD_PM_ACIDET_TH_DB_0_MASK                                          0x0000003F
#define B0_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG74_FIELD_PM_ACIDET_TH_DB_1_MASK                                          0x00003F00
#define B0_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG74_FIELD_PM_ACIDET_TH_OFFSET_MASK                                        0x003F0000
//========================================
/* REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG75 0x1D4 */
#define B0_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG75_FIELD_PM_ACIDET_RADAR_HIGH_TH_MASK                                    0x000000FF
#define B0_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG75_FIELD_PM_ACIDET_RADAR_LOW_TH_MASK                                     0x0000FF00
#define B0_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG75_FIELD_PM_ACIDET_RADAR_CLEAR_MASK                                      0x00010000
#define B0_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG75_FIELD_PM_ACIDET_RADAR_AUTO_CLEAR_EN_MASK                              0x00020000
#define B0_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG75_FIELD_PM_ACIDET_ACI_DET_TRIG_ON_FINE_EN_MASK                          0x00040000
//========================================
/* REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG76 0x1D8 */
#define B0_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG76_FIELD_ACI_DETECTED_MASK                                               0x00000001
#define B0_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG76_FIELD_ACI_DETECTED_VALID_MASK                                         0x00000002
#define B0_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG76_FIELD_ACIDET_POW_PRIM_MASK                                            0x00001FF0
#define B0_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG76_FIELD_ACIDET_MAX_POW_BAND_REG_MASK                                    0x00FF0000
//========================================
/* REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG77 0x1DC */
#define B0_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG77_FIELD_ACIDET_POW_BAND_REG0_MASK                                       0x000000FF
#define B0_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG77_FIELD_ACIDET_POW_BAND_REG1_MASK                                       0x0000FF00
#define B0_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG77_FIELD_ACIDET_POW_BAND_REG2_MASK                                       0x00FF0000
#define B0_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG77_FIELD_ACIDET_POW_BAND_REG3_MASK                                       0xFF000000
//========================================
/* REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG78 0x1E0 */
#define B0_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG78_FIELD_ACIDET_POW_BAND_REG4_MASK                                       0x000000FF
#define B0_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG78_FIELD_ACIDET_POW_BAND_REG5_MASK                                       0x0000FF00
#define B0_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG78_FIELD_ACIDET_POW_BAND_REG6_MASK                                       0x00FF0000
#define B0_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG78_FIELD_ACIDET_POW_BAND_REG7_MASK                                       0xFF000000
//========================================
/* REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG79 0x1E4 */
#define B0_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG79_FIELD_ACIDET_RADAR_COUNTER0_MASK                                      0x00000FFF
#define B0_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG79_FIELD_ACIDET_RADAR_COUNTER1_MASK                                      0x00FFF000
//========================================
/* REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG7A 0x1E8 */
#define B0_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG7A_FIELD_ACIDET_RADAR_COUNTER2_MASK                                      0x00000FFF
#define B0_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG7A_FIELD_ACIDET_RADAR_COUNTER3_MASK                                      0x00FFF000
//========================================
/* REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG7B 0x1EC */
#define B0_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG7B_FIELD_ACIDET_RADAR_COUNTER4_MASK                                      0x00000FFF
#define B0_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG7B_FIELD_ACIDET_RADAR_COUNTER5_MASK                                      0x00FFF000
//========================================
/* REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG7C 0x1F0 */
#define B0_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG7C_FIELD_ACIDET_RADAR_COUNTER6_MASK                                      0x00000FFF
#define B0_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG7C_FIELD_ACIDET_RADAR_COUNTER7_MASK                                      0x00FFF000
//========================================
/* REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG7D 0x1F4 */
#define B0_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG7D_FIELD_ACIDET_RADAR_EVENT_MASK_MASK                                    0x000000FF
#define B0_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG7D_FIELD_ACIDET_RADAR_EVENT_NODET_MASK_MASK                              0x0000FF00
#define B0_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG7D_FIELD_ACIDET_RADAR_COMPLETED_EVENT_MASK_MASK                          0x00FF0000
//========================================
/* REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG7E 0x1F8 */
#define B0_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG7E_FIELD_PM_ACI_SYSTEM_GAIN_MASK                                         0x000001FF
#define B0_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG7E_FIELD_PM_ACI_SYSTEM_GAIN_HW_ON_MUX_MASK                               0x00000400
#define B0_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG7E_FIELD_PM_ACI_RSSI_SAT_THR_MASK                                        0x3FFFF000
//========================================
/* REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG7F 0x1FC */
#define B0_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG7F_FIELD_PM_SYSTEM_GAIN_CCA_CTRL_HW0_MASK                                0x00000001
#define B0_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG7F_FIELD_PM_SYSTEM_GAIN_CCA_MASK                                         0x00001FF0
//========================================
/* REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG80 0x200 */
#define B0_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG80_FIELD_CCA_PM_BW_PWR_OUT_MASK                                          0x000000FF
//========================================
/* REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG82 0x208 */
#define B0_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG82_FIELD_FDL_RESET_HW_SYNC_MASK                                          0x000003FF
//========================================
/* REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG83 0x20C */
#define B0_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG83_FIELD_FDL_RESTART_EN_MASK                                             0x00000001
#define B0_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG83_FIELD_FDL_CORRECTION_ENABLE_MASK                                      0x00000002
#define B0_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG83_FIELD_FREQ_SHIFT_PPM_ENABLE_MASK                                      0x00000004
#define B0_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG83_FIELD_FREQ_SHIFT_M2_DC_PPM_SHIFT_MASK                                 0x00000008
#define B0_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG83_FIELD_FREQ_SHIFT_IIR_SHIFT_MASK                                       0x000000F0
#define B0_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG83_FIELD_FDL_EHT160_CP_MASK                                              0x00000100
//========================================
/* REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG84 0x210 */
#define B0_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG84_FIELD_FDL_NCO_INCR_MAX_MASK                                           0xFFFFFFFF
//========================================
/* REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG85 0x214 */
#define B0_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG85_FIELD_FDL_NCO_INCR_MASK                                               0xFFFFFFFF
//========================================
/* REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG86 0x218 */
#define B0_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG86_FIELD_PM_FDL_FORCE_NCO_INCR_MASK                                      0x00000001
//========================================
/* REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG87 0x21C */
#define B0_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG87_FIELD_FDL_NCO_INCR_OUT_MASK                                           0xFFFFFFFF
//========================================
/* REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG88 0x220 */
#define B0_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG88_FIELD_FDL_NCO_INCR_VALID_OUT_MASK                                     0x00000001
//========================================
/* REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG89 0x224 */
#define B0_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG89_FIELD_FDL_NCO_INCR_SAT_MASK                                           0x00000001
//========================================
/* REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG8A 0x228 */
#define B0_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG8A_FIELD_FDL_NCO_ACC_STS_OUT_MASK                                        0xFFFFFFFF
//========================================
/* REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG8B 0x22C */
#define B0_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG8B_FIELD_PM_11B_DECIM_PHASE_MASK                                         0x00000003
#define B0_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG8B_FIELD_PM_11B_DECIM_PATH_SELECT_MASK                                   0x00000004
//========================================
/* REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG8C 0x230 */
#define B0_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG8C_FIELD_FFT_SHARE_OVERRIDE_CONTROL_MASK                                 0x00000001
#define B0_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG8C_FIELD_FFT_CONTROL_RX_MASK                                             0x00000010
//========================================
/* REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG8D 0x234 */
#define B0_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG8D_FIELD_ANT_OFDM_C16_RM_MASK                                            0x00000007
#define B0_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG8D_FIELD_ANT_OFDM_C64_RM_MASK                                            0x00000070
#define B0_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG8D_FIELD_ANT_OFDM_MRB_RM_MASK                                            0x00000700
#define B0_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG8D_FIELD_ANT_ACI_DET_AVG_RM_MASK                                         0x00007000
#define B0_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG8D_FIELD_ANT_IQ_PARAMS_LUT_RM_MASK                                       0x00070000
#define B0_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG8D_FIELD_ANT_IQ_FIREQ_LUT_RM_MASK                                        0x00700000
//========================================
/* REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG8E 0x238 */
#define B0_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG8E_FIELD_TEST_PLUG_LEN_MASK                                              0x00000FFF
//========================================
/* REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG8F 0x23C */
#define B0_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG8F_FIELD_FDL_DISABLE_TIMING_UPDATES_MASK                                 0x00000001
//========================================
/* REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG90 0x240 */
#define B0_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG90_FIELD_HE_TRIG_STF_GAIN_BYPASS_MASK                                    0x00000001
//========================================
/* REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG91 0x244 */
#define B0_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG91_FIELD_RSSI_DATA_MASK                                                  0x00007FFF
//========================================
/* REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG92 0x248 */
#define B0_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG92_FIELD_STS_FDL_IQ_COMP_MASK                                            0x0000FFFF
//========================================
/* REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG93 0x24C */
#define B0_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG93_FIELD_STS_CHANFILT_COEF_MASK                                          0x00000FFF
#define B0_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG93_FIELD_STS_CHANFILT_SET_ID_MASK                                        0x0001F000
#define B0_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG93_FIELD_STS_CHANFILT_FILT_LENGTH_MASK                                   0x01FE0000
//========================================
/* REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG94 0x250 */
#define B0_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG94_FIELD_ACIDET_RADAR_MAX_CNT_MASK                                       0x00000FFF
//========================================
/* REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG95 0x254 */
#define B0_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG95_FIELD_PM_PRE_FILTER_BYPASS_MASK                                       0x00000001
#define B0_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG95_FIELD_PM_PRE_FILTER_BYPASS_WITH_DELAY_MASK                            0x00000002
#define B0_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG95_FIELD_PM_PRE_FILTER_NARROW_MODE_MASK                                  0x00000004
#define B0_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG95_FIELD_PM_PRE_FILTER_BYPASS_WITH_GAIN_MASK                             0x00000008
//========================================
/* REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG96 0x258 */
#define B0_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG96_FIELD_PM_PRE_FILTER_GAIN_MASK                                         0x0000007F
#define B0_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG96_FIELD_PM_PRE_FILTER_GAIN_EN_MASK                                      0x00000080
//========================================
/* REG_PHY_RXTD_ANT2_CONTROL_11B 0x25C */
#define B0_PHY_RXTD_ANT2_CONTROL_11B_FIELD_BIT_SHIFT11B_MASK                                                      0x00000003
#define B0_PHY_RXTD_ANT2_CONTROL_11B_FIELD_BIT_SHIFT11B_HW_EN_MASK                                                0x00000004
//========================================
/* REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG98 0x260 */
#define B0_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG98_FIELD_PM_BANDSEL_FILTER_INDEX_MASK                                    0x00000001
#define B0_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG98_FIELD_PM_BANDSEL_INPUT_RATE_MASK                                      0x00000700
//========================================
/* REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG99 0x264 */
#define B0_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG99_FIELD_BANDSEL_TO_DET_PM_GAIN_DB_MASK                                  0x0000007F
#define B0_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG99_FIELD_BANDSEL_TO_DET_HW_GAIN_DB_EN_MASK                               0x00000080
#define B0_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG99_FIELD_BANDSEL_10MHZ_FORCE_MASK                                        0x00000300
//========================================
/* REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG9A 0x268 */
#define B0_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG9A_FIELD_I2Q_EQ_TAP0_MASK                                                0x000003FF
#define B0_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG9A_FIELD_I2Q_EQ_TAP1_MASK                                                0x03FF0000
//========================================
/* REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG9B 0x26C */
#define B0_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG9B_FIELD_I2Q_EQ_TAP2_MASK                                                0x000003FF
#define B0_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG9B_FIELD_I2Q_EQ_TAP3_MASK                                                0x03FF0000
//========================================
/* REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG9C 0x270 */
#define B0_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG9C_FIELD_I2Q_EQ_TAP4_MASK                                                0x000003FF
#define B0_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG9C_FIELD_I2Q_EQ_TAP5_MASK                                                0x03FF0000
//========================================
/* REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG9D 0x274 */
#define B0_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG9D_FIELD_I2Q_EQ_TAP6_MASK                                                0x000003FF
#define B0_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG9D_FIELD_I2Q_EQ_TAP7_MASK                                                0x03FF0000
//========================================
/* REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG9E 0x278 */
#define B0_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG9E_FIELD_I2Q_EQ_TAP8_MASK                                                0x000003FF
#define B0_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG9E_FIELD_I2Q_EQ_TAP9_MASK                                                0x03FF0000
//========================================
/* REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG9F 0x27C */
#define B0_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG9F_FIELD_I2Q_EQ_TAP10_MASK                                               0x000003FF
#define B0_PHY_RXTD_ANT2_PHY_RXTD_ANT_REG9F_FIELD_I2Q_EQ_TAP11_MASK                                               0x03FF0000
//========================================
/* REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REGA1 0x284 */
#define B0_PHY_RXTD_ANT2_PHY_RXTD_ANT_REGA1_FIELD_I2Q_EQ_USED_TAP0_MASK                                           0x000003FF
#define B0_PHY_RXTD_ANT2_PHY_RXTD_ANT_REGA1_FIELD_I2Q_EQ_USED_TAP1_MASK                                           0x03FF0000
//========================================
/* REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REGA2 0x288 */
#define B0_PHY_RXTD_ANT2_PHY_RXTD_ANT_REGA2_FIELD_I2Q_EQ_USED_TAP2_MASK                                           0x000003FF
#define B0_PHY_RXTD_ANT2_PHY_RXTD_ANT_REGA2_FIELD_I2Q_EQ_USED_TAP3_MASK                                           0x03FF0000
//========================================
/* REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REGA3 0x28C */
#define B0_PHY_RXTD_ANT2_PHY_RXTD_ANT_REGA3_FIELD_I2Q_EQ_USED_TAP4_MASK                                           0x000003FF
#define B0_PHY_RXTD_ANT2_PHY_RXTD_ANT_REGA3_FIELD_I2Q_EQ_USED_TAP5_MASK                                           0x03FF0000
//========================================
/* REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REGA4 0x290 */
#define B0_PHY_RXTD_ANT2_PHY_RXTD_ANT_REGA4_FIELD_I2Q_EQ_USED_TAP6_MASK                                           0x000003FF
#define B0_PHY_RXTD_ANT2_PHY_RXTD_ANT_REGA4_FIELD_I2Q_EQ_USED_TAP7_MASK                                           0x03FF0000
//========================================
/* REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REGA5 0x294 */
#define B0_PHY_RXTD_ANT2_PHY_RXTD_ANT_REGA5_FIELD_I2Q_EQ_USED_TAP8_MASK                                           0x000003FF
#define B0_PHY_RXTD_ANT2_PHY_RXTD_ANT_REGA5_FIELD_I2Q_EQ_USED_TAP9_MASK                                           0x03FF0000
//========================================
/* REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REGA6 0x298 */
#define B0_PHY_RXTD_ANT2_PHY_RXTD_ANT_REGA6_FIELD_I2Q_EQ_USED_TAP10_MASK                                          0x000003FF
#define B0_PHY_RXTD_ANT2_PHY_RXTD_ANT_REGA6_FIELD_I2Q_EQ_USED_TAP11_MASK                                          0x03FF0000
//========================================
/* REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REGA7 0x29C */
#define B0_PHY_RXTD_ANT2_PHY_RXTD_ANT_REGA7_FIELD_PM_RAM_LS_MASK                                                  0x000003FF
#define B0_PHY_RXTD_ANT2_PHY_RXTD_ANT_REGA7_FIELD_PM_RAM_DS_MASK                                                  0x00001C00
#define B0_PHY_RXTD_ANT2_PHY_RXTD_ANT_REGA7_FIELD_PM_RAM_SD_MASK                                                  0x00070000
#define B0_PHY_RXTD_ANT2_PHY_RXTD_ANT_REGA7_FIELD_PM_RAM_PS_HW_EN_MASK                                            0xFF000000
//========================================
/* REG_PHY_RXTD_ANT2_FORCE_OP_CH_ZERO 0x2A0 */
#define B0_PHY_RXTD_ANT2_FORCE_OP_CH_ZERO_FIELD_FORCE_OP_CH_ZERO_MASK                                             0x0000FFFF
//========================================
/* REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REGA9 0x2A4 */
#define B0_PHY_RXTD_ANT2_PHY_RXTD_ANT_REGA9_FIELD_PM_RAM_ROP_MASK                                                 0x00000003
//========================================
/* REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REGAA 0x2A8 */
#define B0_PHY_RXTD_ANT2_PHY_RXTD_ANT_REGAA_FIELD_MRB_OUT_FORCE_0_ENABLE_MASK                                     0x00000001
#define B0_PHY_RXTD_ANT2_PHY_RXTD_ANT_REGAA_FIELD_LENGTH_OF_MRB_OUT_FORCE_0_MASK                                  0x000000FE
//========================================
/* REG_PHY_RXTD_ANT2_TB_BANDSELECT_BANDS 0x2AC */
#define B0_PHY_RXTD_ANT2_TB_BANDSELECT_BANDS_FIELD_TB_BANDSELECT_BANDS_MASK                                       0x0000FFFF
//========================================
/* REG_PHY_RXTD_ANT2_CONTROL_OVERRIDE 0x2B0 */
#define B0_PHY_RXTD_ANT2_CONTROL_OVERRIDE_FIELD_PM_ANT_SW_RESET_N_REG_SEL_MASK                                    0x00000001
#define B0_PHY_RXTD_ANT2_CONTROL_OVERRIDE_FIELD_PM_ANT_BLOCK_EN_SEL_MASK                                          0x00000002
//========================================
/* REG_PHY_RXTD_ANT2_ANT_SW_RESET_N_REG 0x2B4 */
#define B0_PHY_RXTD_ANT2_ANT_SW_RESET_N_REG_FIELD_ANT_SW_RESET_N_REG_MASK                                         0xFFFFFFFF
//========================================
/* REG_PHY_RXTD_ANT2_ANT_BLOCK_EN 0x2B8 */
#define B0_PHY_RXTD_ANT2_ANT_BLOCK_EN_FIELD_ANT_BLOCK_EN_MASK                                                     0xFFFFFFFF
//========================================
/* REG_PHY_RXTD_ANT2_ACI_BAND_POWER_0 0x2BC */
#define B0_PHY_RXTD_ANT2_ACI_BAND_POWER_0_FIELD_ACI_BAND_POWER_0_MASK                                             0x000001FF
//========================================
/* REG_PHY_RXTD_ANT2_ACI_BAND_POWER_1 0x2C0 */
#define B0_PHY_RXTD_ANT2_ACI_BAND_POWER_1_FIELD_ACI_BAND_POWER_1_MASK                                             0x000001FF
//========================================
/* REG_PHY_RXTD_ANT2_ACI_BAND_POWER_2 0x2C4 */
#define B0_PHY_RXTD_ANT2_ACI_BAND_POWER_2_FIELD_ACI_BAND_POWER_2_MASK                                             0x000001FF
//========================================
/* REG_PHY_RXTD_ANT2_ACI_BAND_POWER_3 0x2C8 */
#define B0_PHY_RXTD_ANT2_ACI_BAND_POWER_3_FIELD_ACI_BAND_POWER_3_MASK                                             0x000001FF
//========================================
/* REG_PHY_RXTD_ANT2_ACI_BAND_POWER_4 0x2CC */
#define B0_PHY_RXTD_ANT2_ACI_BAND_POWER_4_FIELD_ACI_BAND_POWER_4_MASK                                             0x000001FF
//========================================
/* REG_PHY_RXTD_ANT2_ACI_BAND_POWER_5 0x2D0 */
#define B0_PHY_RXTD_ANT2_ACI_BAND_POWER_5_FIELD_ACI_BAND_POWER_5_MASK                                             0x000001FF
//========================================
/* REG_PHY_RXTD_ANT2_ACI_BAND_POWER_6 0x2D4 */
#define B0_PHY_RXTD_ANT2_ACI_BAND_POWER_6_FIELD_ACI_BAND_POWER_6_MASK                                             0x000001FF
//========================================
/* REG_PHY_RXTD_ANT2_ACI_BAND_POWER_7 0x2D8 */
#define B0_PHY_RXTD_ANT2_ACI_BAND_POWER_7_FIELD_ACI_BAND_POWER_7_MASK                                             0x000001FF
//========================================
/* REG_PHY_RXTD_ANT2_ACI_BAND_POWER_8 0x2DC */
#define B0_PHY_RXTD_ANT2_ACI_BAND_POWER_8_FIELD_ACI_BAND_POWER_8_MASK                                             0x000001FF
//========================================
/* REG_PHY_RXTD_ANT2_ACI_BAND_POWER_9 0x2E0 */
#define B0_PHY_RXTD_ANT2_ACI_BAND_POWER_9_FIELD_ACI_BAND_POWER_9_MASK                                             0x000001FF
//========================================
/* REG_PHY_RXTD_ANT2_ACI_BAND_POWER_10 0x2E4 */
#define B0_PHY_RXTD_ANT2_ACI_BAND_POWER_10_FIELD_ACI_BAND_POWER_10_MASK                                           0x000001FF
//========================================
/* REG_PHY_RXTD_ANT2_ACI_BAND_POWER_11 0x2E8 */
#define B0_PHY_RXTD_ANT2_ACI_BAND_POWER_11_FIELD_ACI_BAND_POWER_11_MASK                                           0x000001FF
//========================================
/* REG_PHY_RXTD_ANT2_ACI_BAND_POWER_12 0x2EC */
#define B0_PHY_RXTD_ANT2_ACI_BAND_POWER_12_FIELD_ACI_BAND_POWER_12_MASK                                           0x000001FF
//========================================
/* REG_PHY_RXTD_ANT2_ACI_BAND_POWER_13 0x2F0 */
#define B0_PHY_RXTD_ANT2_ACI_BAND_POWER_13_FIELD_ACI_BAND_POWER_13_MASK                                           0x000001FF
//========================================
/* REG_PHY_RXTD_ANT2_ACI_BAND_POWER_14 0x2F4 */
#define B0_PHY_RXTD_ANT2_ACI_BAND_POWER_14_FIELD_ACI_BAND_POWER_14_MASK                                           0x000001FF
//========================================
/* REG_PHY_RXTD_ANT2_ACI_BAND_POWER_15 0x2F8 */
#define B0_PHY_RXTD_ANT2_ACI_BAND_POWER_15_FIELD_ACI_BAND_POWER_15_MASK                                           0x000001FF
//========================================
/* REG_PHY_RXTD_ANT2_ACI_BAND_POWER_OVR_0_3 0x2FC */
#define B0_PHY_RXTD_ANT2_ACI_BAND_POWER_OVR_0_3_FIELD_ACI_BAND_POWER_OVR_0_MASK                                   0x0000007F
#define B0_PHY_RXTD_ANT2_ACI_BAND_POWER_OVR_0_3_FIELD_ACI_BAND_POWER_OVR_0_EN_MASK                                0x00000080
#define B0_PHY_RXTD_ANT2_ACI_BAND_POWER_OVR_0_3_FIELD_ACI_BAND_POWER_OVR_1_MASK                                   0x00007F00
#define B0_PHY_RXTD_ANT2_ACI_BAND_POWER_OVR_0_3_FIELD_ACI_BAND_POWER_OVR_1_EN_MASK                                0x00008000
#define B0_PHY_RXTD_ANT2_ACI_BAND_POWER_OVR_0_3_FIELD_ACI_BAND_POWER_OVR_2_MASK                                   0x007F0000
#define B0_PHY_RXTD_ANT2_ACI_BAND_POWER_OVR_0_3_FIELD_ACI_BAND_POWER_OVR_2_EN_MASK                                0x00800000
#define B0_PHY_RXTD_ANT2_ACI_BAND_POWER_OVR_0_3_FIELD_ACI_BAND_POWER_OVR_3_MASK                                   0x7F000000
#define B0_PHY_RXTD_ANT2_ACI_BAND_POWER_OVR_0_3_FIELD_ACI_BAND_POWER_OVR_3_EN_MASK                                0x80000000
//========================================
/* REG_PHY_RXTD_ANT2_ACI_BAND_POWER_OVR_4_7 0x300 */
#define B0_PHY_RXTD_ANT2_ACI_BAND_POWER_OVR_4_7_FIELD_ACI_BAND_POWER_OVR_4_MASK                                   0x0000007F
#define B0_PHY_RXTD_ANT2_ACI_BAND_POWER_OVR_4_7_FIELD_ACI_BAND_POWER_OVR_4_EN_MASK                                0x00000080
#define B0_PHY_RXTD_ANT2_ACI_BAND_POWER_OVR_4_7_FIELD_ACI_BAND_POWER_OVR_5_MASK                                   0x00007F00
#define B0_PHY_RXTD_ANT2_ACI_BAND_POWER_OVR_4_7_FIELD_ACI_BAND_POWER_OVR_5_EN_MASK                                0x00008000
#define B0_PHY_RXTD_ANT2_ACI_BAND_POWER_OVR_4_7_FIELD_ACI_BAND_POWER_OVR_6_MASK                                   0x007F0000
#define B0_PHY_RXTD_ANT2_ACI_BAND_POWER_OVR_4_7_FIELD_ACI_BAND_POWER_OVR_6_EN_MASK                                0x00800000
#define B0_PHY_RXTD_ANT2_ACI_BAND_POWER_OVR_4_7_FIELD_ACI_BAND_POWER_OVR_7_MASK                                   0x7F000000
#define B0_PHY_RXTD_ANT2_ACI_BAND_POWER_OVR_4_7_FIELD_ACI_BAND_POWER_OVR_7_EN_MASK                                0x80000000
//========================================
/* REG_PHY_RXTD_ANT2_ACI_BAND_POWER_OVR_8_11 0x304 */
#define B0_PHY_RXTD_ANT2_ACI_BAND_POWER_OVR_8_11_FIELD_ACI_BAND_POWER_OVR_8_MASK                                  0x0000007F
#define B0_PHY_RXTD_ANT2_ACI_BAND_POWER_OVR_8_11_FIELD_ACI_BAND_POWER_OVR_8_EN_MASK                               0x00000080
#define B0_PHY_RXTD_ANT2_ACI_BAND_POWER_OVR_8_11_FIELD_ACI_BAND_POWER_OVR_9_MASK                                  0x00007F00
#define B0_PHY_RXTD_ANT2_ACI_BAND_POWER_OVR_8_11_FIELD_ACI_BAND_POWER_OVR_9_EN_MASK                               0x00008000
#define B0_PHY_RXTD_ANT2_ACI_BAND_POWER_OVR_8_11_FIELD_ACI_BAND_POWER_OVR_10_MASK                                 0x007F0000
#define B0_PHY_RXTD_ANT2_ACI_BAND_POWER_OVR_8_11_FIELD_ACI_BAND_POWER_OVR_10_EN_MASK                              0x00800000
#define B0_PHY_RXTD_ANT2_ACI_BAND_POWER_OVR_8_11_FIELD_ACI_BAND_POWER_OVR_11_MASK                                 0x7F000000
#define B0_PHY_RXTD_ANT2_ACI_BAND_POWER_OVR_8_11_FIELD_ACI_BAND_POWER_OVR_11_EN_MASK                              0x80000000
//========================================
/* REG_PHY_RXTD_ANT2_ACI_BAND_POWER_OVR_12_15 0x308 */
#define B0_PHY_RXTD_ANT2_ACI_BAND_POWER_OVR_12_15_FIELD_ACI_BAND_POWER_OVR_12_MASK                                0x0000007F
#define B0_PHY_RXTD_ANT2_ACI_BAND_POWER_OVR_12_15_FIELD_ACI_BAND_POWER_OVR_12_EN_MASK                             0x00000080
#define B0_PHY_RXTD_ANT2_ACI_BAND_POWER_OVR_12_15_FIELD_ACI_BAND_POWER_OVR_13_MASK                                0x00007F00
#define B0_PHY_RXTD_ANT2_ACI_BAND_POWER_OVR_12_15_FIELD_ACI_BAND_POWER_OVR_13_EN_MASK                             0x00008000
#define B0_PHY_RXTD_ANT2_ACI_BAND_POWER_OVR_12_15_FIELD_ACI_BAND_POWER_OVR_14_MASK                                0x007F0000
#define B0_PHY_RXTD_ANT2_ACI_BAND_POWER_OVR_12_15_FIELD_ACI_BAND_POWER_OVR_14_EN_MASK                             0x00800000
#define B0_PHY_RXTD_ANT2_ACI_BAND_POWER_OVR_12_15_FIELD_ACI_BAND_POWER_OVR_15_MASK                                0x7F000000
#define B0_PHY_RXTD_ANT2_ACI_BAND_POWER_OVR_12_15_FIELD_ACI_BAND_POWER_OVR_15_EN_MASK                             0x80000000
//========================================
/* REG_PHY_RXTD_ANT2_ACI_DET_RADAR_COUNTER_TH 0x30C */
#define B0_PHY_RXTD_ANT2_ACI_DET_RADAR_COUNTER_TH_FIELD_ACI_DET_RADAR_COUNTER_TH_MASK                             0x00000FFF
//========================================
/* REG_PHY_RXTD_ANT2_LOOPBACK_PYPASS 0x310 */
#define B0_PHY_RXTD_ANT2_LOOPBACK_PYPASS_FIELD_PM_LOOP_PREFILTER_BYPASS_MASK                                      0x00000001
#define B0_PHY_RXTD_ANT2_LOOPBACK_PYPASS_FIELD_PM_LOOP_FDL_BYPASS_MASK                                            0x00000002
//========================================
/* REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REGC5 0x314 */
#define B0_PHY_RXTD_ANT2_PHY_RXTD_ANT_REGC5_FIELD_FDL_FREQ_SHIFT_SCALE_MASK                                       0x00FFFFFF
//========================================
/* REG_PHY_RXTD_ANT2_PHY_RXTD_ANT_REGC6 0x318 */
#define B0_PHY_RXTD_ANT2_PHY_RXTD_ANT_REGC6_FIELD_TD_NCO_FREQ_MASK                                                0x00FFFFFF
//========================================
/* REG_PHY_RXTD_ANT2_PM_ACIDET_BYPASS_OFFSETS 0x31C */
#define B0_PHY_RXTD_ANT2_PM_ACIDET_BYPASS_OFFSETS_FIELD_PM_ACIDET_BYPASS_OFFSETS_MASK                             0x00000001
//========================================
/* REG_PHY_RXTD_ANT2_ANTENNA_320M_MODE_CONTROLS 0x320 */
#define B0_PHY_RXTD_ANT2_ANTENNA_320M_MODE_CONTROLS_FIELD_PM_MIXER80_BP_MASK                                      0x00000001
#define B0_PHY_RXTD_ANT2_ANTENNA_320M_MODE_CONTROLS_FIELD_PM_SPLITTER_BP_MASK                                     0x00000002
//========================================
/* REG_PHY_RXTD_ANT2_FDL_RESET_SHIFT 0x324 */
#define B0_PHY_RXTD_ANT2_FDL_RESET_SHIFT_FIELD_FDL_RESET_SHIFT_0_4_MASK                                           0x0000007F
#define B0_PHY_RXTD_ANT2_FDL_RESET_SHIFT_FIELD_FDL_RESET_SHIFT_0_8_MASK                                           0x00007F00
#define B0_PHY_RXTD_ANT2_FDL_RESET_SHIFT_FIELD_FDL_RESET_SHIFT_1_6_MASK                                           0x007F0000
#define B0_PHY_RXTD_ANT2_FDL_RESET_SHIFT_FIELD_FDL_RESET_SHIFT_3_2_MASK                                           0x7F000000
//========================================
/* REG_PHY_RXTD_ANT2_ABB_DPD_CONTROLS 0x328 */
#define B0_PHY_RXTD_ANT2_ABB_DPD_CONTROLS_FIELD_DPD_FC2SC_PHASE_REGFILE_MASK                                      0x00000003
#define B0_PHY_RXTD_ANT2_ABB_DPD_CONTROLS_FIELD_DPD_SC2FC_PHASE_REGFILE_MASK                                      0x0000000C
#define B0_PHY_RXTD_ANT2_ABB_DPD_CONTROLS_FIELD_DPD_SC2FC_RXON_MASK                                               0x00000030
//========================================
/* REG_PHY_RXTD_ANT2_ABB_DFT_CONTROLS 0x32C */
#define B0_PHY_RXTD_ANT2_ABB_DFT_CONTROLS_FIELD_DFT_FC2SC_PHASE_REGFILE_MASK                                      0x00000003
#define B0_PHY_RXTD_ANT2_ABB_DFT_CONTROLS_FIELD_DFT_SC2FC_PHASE_REGFILE_MASK                                      0x0000000C
#define B0_PHY_RXTD_ANT2_ABB_DFT_CONTROLS_FIELD_DFT_SC2FC_RXON_MASK                                               0x00000030
//========================================
/* REG_PHY_RXTD_ANT2_FDL_PPM_COMPUTE 0x330 */
#define B0_PHY_RXTD_ANT2_FDL_PPM_COMPUTE_FIELD_FDL_USE_DETECTOR_SSB_SHIFT_FOR_PPM_CALC_MASK                       0x00000001
//========================================
/* REG_PHY_RXTD_ANT2_FFT_IN_GAIN_MRU 0x334 */
#define B0_PHY_RXTD_ANT2_FFT_IN_GAIN_MRU_FIELD_FFT_IN_SHIFT60_MASK                                                0x00000007
#define B0_PHY_RXTD_ANT2_FFT_IN_GAIN_MRU_FIELD_FFT_IN_SHIFT120_MASK                                               0x00000038
#define B0_PHY_RXTD_ANT2_FFT_IN_GAIN_MRU_FIELD_FFT_IN_SHIFT140_MASK                                               0x000001C0
#define B0_PHY_RXTD_ANT2_FFT_IN_GAIN_MRU_FIELD_FFT_IN_MULT60_MASK                                                 0x00000200
#define B0_PHY_RXTD_ANT2_FFT_IN_GAIN_MRU_FIELD_FFT_IN_MULT120_MASK                                                0x00000400
#define B0_PHY_RXTD_ANT2_FFT_IN_GAIN_MRU_FIELD_FFT_IN_MULT140_MASK                                                0x00000800
//========================================
/* REG_PHY_RXTD_ANT2_PRE_FILTER_COEF_LEN_SEL 0x338 */
#define B0_PHY_RXTD_ANT2_PRE_FILTER_COEF_LEN_SEL_FIELD_PM_PRE_FILTER_COEF_LEN_SEL_MASK                            0x00000003
//========================================
/* REG_PHY_RXTD_ANT2_INTERP_BEFORE_CHENNEL_FILTER 0x33C */
#define B0_PHY_RXTD_ANT2_INTERP_BEFORE_CHENNEL_FILTER_FIELD_PM_INTERP2_EN_MASK                                    0x00000001
//========================================
/* REG_PHY_RXTD_ANT2_ACI_RSSI_MAX_BAND_PWR 0x340 */
#define B0_PHY_RXTD_ANT2_ACI_RSSI_MAX_BAND_PWR_FIELD_ACI_RSSI_MAX_BAND_PWR_MASK                                   0x0003FFFF
//========================================
/* REG_PHY_RXTD_ANT2_ACI_RSSI_MAX_BAND_PWR_HB 0x344 */
#define B0_PHY_RXTD_ANT2_ACI_RSSI_MAX_BAND_PWR_HB_FIELD_ACI_RSSI_MAX_BAND_PWR_HB_MASK                             0x0003FFFF
//========================================
/* REG_PHY_RXTD_ANT2_ACI_RSSI_SAT_FLAG 0x348 */
#define B0_PHY_RXTD_ANT2_ACI_RSSI_SAT_FLAG_FIELD_ACI_RSSI_HB_SAT_FLAG_MASK                                        0x00000001
#define B0_PHY_RXTD_ANT2_ACI_RSSI_SAT_FLAG_FIELD_ACI_RSSI_SAT_FLAG_MASK                                           0x00000002
//========================================
/* REG_PHY_RXTD_ANT2_POWER_OPTIMIZATION 0x34C */
#define B0_PHY_RXTD_ANT2_POWER_OPTIMIZATION_FIELD_POWER_SAVE_BEFORE_DETECTION_DISABLE_MASK                        0x00000001
#define B0_PHY_RXTD_ANT2_POWER_OPTIMIZATION_FIELD_POWER_SAVE_BEFORE_DETECTION_TDFIFO_EXCLUDE_MASK                 0x00000002
#define B0_PHY_RXTD_ANT2_POWER_OPTIMIZATION_FIELD_POWER_SAVE_AFTER_DETECTION_FIR_DISABLE_MASK                     0x00000004
//========================================
/* REG_PHY_RXTD_ANT2_EMULATION_CONTROL 0x350 */
#define B0_PHY_RXTD_ANT2_EMULATION_CONTROL_FIELD_PM_DIFI1_EMUL_SEL_MASK                                           0x00000001
#define B0_PHY_RXTD_ANT2_EMULATION_CONTROL_FIELD_PM_BB_EMUL_SEL_MASK                                              0x00000002
//========================================
/* REG_PHY_RXTD_ANT2_ACIDET_POW_HB 0x354 */
#define B0_PHY_RXTD_ANT2_ACIDET_POW_HB_FIELD_ACIDET_POW_HB_MASK                                                   0x000001FF
//========================================
/* REG_PHY_RXTD_ANT2_PM_SPURC_NSAMP_THR_0 0x358 */
#define B0_PHY_RXTD_ANT2_PM_SPURC_NSAMP_THR_0_FIELD_PM_SPURC_NSAMP_THR_0_MASK                                     0xFFFFFFFF
//========================================
/* REG_PHY_RXTD_ANT2_PM_SPURC_POW_THR_LOW_0 0x35C */
#define B0_PHY_RXTD_ANT2_PM_SPURC_POW_THR_LOW_0_FIELD_PM_SPURC_POW_THR_LOW_0_MASK                                 0xFFFFFFFF
//========================================
/* REG_PHY_RXTD_ANT2_PM_SPURC_POW_THR_HIGH_0 0x360 */
#define B0_PHY_RXTD_ANT2_PM_SPURC_POW_THR_HIGH_0_FIELD_PM_SPURC_POW_THR_HIGH_0_MASK                               0xFFFFFFFF
//========================================
/* REG_PHY_RXTD_ANT2_PM_SPURC_CONTROL_0 0x364 */
#define B0_PHY_RXTD_ANT2_PM_SPURC_CONTROL_0_FIELD_PM_SPURC_SHUTDOWN_0_MASK                                        0x00000001
#define B0_PHY_RXTD_ANT2_PM_SPURC_CONTROL_0_FIELD_PM_SPURC_STOP_0_MASK                                            0x00000002
#define B0_PHY_RXTD_ANT2_PM_SPURC_CONTROL_0_FIELD_PM_SPURC_BYPASS_0_MASK                                          0x00000004
#define B0_PHY_RXTD_ANT2_PM_SPURC_CONTROL_0_FIELD_PM_SPURC_FREEZE_0_MASK                                          0x00000008
#define B0_PHY_RXTD_ANT2_PM_SPURC_CONTROL_0_FIELD_PM_SPURC_AFE_STABLE_MASK                                        0x00000010
#define B0_PHY_RXTD_ANT2_PM_SPURC_CONTROL_0_FIELD_PM_SPURC_DO_WHEN_AGC_0_MASK                                     0x00000060
//========================================
/* REG_PHY_RXTD_ANT2_PM_SPURC_GAIN_TIMER_0 0x368 */
#define B0_PHY_RXTD_ANT2_PM_SPURC_GAIN_TIMER_0_FIELD_PM_SPURC_GAIN_TIMER_0_MASK                                   0xFFFFFFFF
//========================================
/* REG_PHY_RXTD_ANT2_PM_SPURC_DDFS_PHASE_ADJUST_0 0x36C */
#define B0_PHY_RXTD_ANT2_PM_SPURC_DDFS_PHASE_ADJUST_0_FIELD_PM_SPURC_DDFS_PHASE_ADJUST_0_MASK                     0xFFFFFFFF
//========================================
/* REG_PHY_RXTD_ANT2_PM_SPURC_DDFS_PHASE_INIT_0 0x370 */
#define B0_PHY_RXTD_ANT2_PM_SPURC_DDFS_PHASE_INIT_0_FIELD_PM_SPURC_DDFS_PHASE_INIT_0_MASK                         0xFFFFFFFF
//========================================
/* REG_PHY_RXTD_ANT2_PM_SPURC_DDFS_FCW_0 0x374 */
#define B0_PHY_RXTD_ANT2_PM_SPURC_DDFS_FCW_0_FIELD_PM_SPURC_DDFS_FCW_0_MASK                                       0xFFFFFFFF
//========================================
/* REG_PHY_RXTD_ANT2_PM_SPURC_DDFS_P_Q_0 0x378 */
#define B0_PHY_RXTD_ANT2_PM_SPURC_DDFS_P_Q_0_FIELD_PM_SPURC_DDFS_P_0_MASK                                         0x000001FF
#define B0_PHY_RXTD_ANT2_PM_SPURC_DDFS_P_Q_0_FIELD_PM_SPURC_DDFS_Q_0_MASK                                         0x0003FE00
//========================================
/* REG_PHY_RXTD_ANT2_PM_SPURC_MEM_RESET_0 0x37C */
#define B0_PHY_RXTD_ANT2_PM_SPURC_MEM_RESET_0_FIELD_PM_SPURC_MEM_RESET_0_MASK                                     0x00000001
//========================================
/* REG_PHY_RXTD_ANT2_PM_SPURC_MEM_LOAD_0 0x380 */
#define B0_PHY_RXTD_ANT2_PM_SPURC_MEM_LOAD_0_FIELD_PM_SPURC_MEM_LOAD_0_MASK                                       0x00000007
//========================================
/* REG_PHY_RXTD_ANT2_PM_SPURC_MEM_M_R_31_0_0 0x384 */
#define B0_PHY_RXTD_ANT2_PM_SPURC_MEM_M_R_31_0_0_FIELD_PM_SPURC_MEM_M_R_31_0_0_MASK                               0xFFFFFFFF
//========================================
/* REG_PHY_RXTD_ANT2_PM_SPURC_MEM_M_R_37_32_0 0x388 */
#define B0_PHY_RXTD_ANT2_PM_SPURC_MEM_M_R_37_32_0_FIELD_PM_SPURC_MEM_M_R_37_32_0_MASK                             0x0000003F
//========================================
/* REG_PHY_RXTD_ANT2_PM_SPURC_MEM_M_I_31_0_0 0x38C */
#define B0_PHY_RXTD_ANT2_PM_SPURC_MEM_M_I_31_0_0_FIELD_PM_SPURC_MEM_M_I_31_0_0_MASK                               0xFFFFFFFF
//========================================
/* REG_PHY_RXTD_ANT2_PM_SPURC_MEM_M_I_37_32_0 0x390 */
#define B0_PHY_RXTD_ANT2_PM_SPURC_MEM_M_I_37_32_0_FIELD_PM_SPURC_MEM_M_I_37_32_0_MASK                             0x0000003F
//========================================
/* REG_PHY_RXTD_ANT2_PM_SPURC_MEM_NSAMP_0 0x394 */
#define B0_PHY_RXTD_ANT2_PM_SPURC_MEM_NSAMP_0_FIELD_PM_SPURC_MEM_NSAMP_0_MASK                                     0xFFFFFFFF
//========================================
/* REG_PHY_RXTD_ANT2_PM_SPURC_MEM_DIG_GAIN_0 0x398 */
#define B0_PHY_RXTD_ANT2_PM_SPURC_MEM_DIG_GAIN_0_FIELD_PM_SPURC_MEM_DIG_GAIN_0_MASK                               0x0000007F
//========================================
/* REG_PHY_RXTD_ANT2_PM_SPURC_MEM_ALPHA_IDX_0 0x39C */
#define B0_PHY_RXTD_ANT2_PM_SPURC_MEM_ALPHA_IDX_0_FIELD_PM_SPURC_MEM_ALPHA_IDX_0_MASK                             0x0000000F
//========================================
/* REG_PHY_RXTD_ANT2_PM_SPURC_ALPHA_STEP_0_0 0x3A0 */
#define B0_PHY_RXTD_ANT2_PM_SPURC_ALPHA_STEP_0_0_FIELD_PM_SPURC_ALPHA_STEP_0_0_MASK                               0x0000003F
//========================================
/* REG_PHY_RXTD_ANT2_PM_SPURC_ALPHA_STEP_1_0 0x3A4 */
#define B0_PHY_RXTD_ANT2_PM_SPURC_ALPHA_STEP_1_0_FIELD_PM_SPURC_ALPHA_STEP_1_0_MASK                               0x0000003F
//========================================
/* REG_PHY_RXTD_ANT2_PM_SPURC_ALPHA_STEP_2_0 0x3A8 */
#define B0_PHY_RXTD_ANT2_PM_SPURC_ALPHA_STEP_2_0_FIELD_PM_SPURC_ALPHA_STEP_2_0_MASK                               0x0000003F
//========================================
/* REG_PHY_RXTD_ANT2_PM_SPURC_ALPHA_STEP_3_0 0x3AC */
#define B0_PHY_RXTD_ANT2_PM_SPURC_ALPHA_STEP_3_0_FIELD_PM_SPURC_ALPHA_STEP_3_0_MASK                               0x0000003F
//========================================
/* REG_PHY_RXTD_ANT2_PM_SPURC_ALPHA_STEP_4_0 0x3B0 */
#define B0_PHY_RXTD_ANT2_PM_SPURC_ALPHA_STEP_4_0_FIELD_PM_SPURC_ALPHA_STEP_4_0_MASK                               0x0000003F
//========================================
/* REG_PHY_RXTD_ANT2_PM_SPURC_ALPHA_STEP_5_0 0x3B4 */
#define B0_PHY_RXTD_ANT2_PM_SPURC_ALPHA_STEP_5_0_FIELD_PM_SPURC_ALPHA_STEP_5_0_MASK                               0x0000003F
//========================================
/* REG_PHY_RXTD_ANT2_PM_SPURC_ALPHA_STEP_6_0 0x3B8 */
#define B0_PHY_RXTD_ANT2_PM_SPURC_ALPHA_STEP_6_0_FIELD_PM_SPURC_ALPHA_STEP_6_0_MASK                               0x0000003F
//========================================
/* REG_PHY_RXTD_ANT2_PM_SPURC_ALPHA_STEP_7_0 0x3BC */
#define B0_PHY_RXTD_ANT2_PM_SPURC_ALPHA_STEP_7_0_FIELD_PM_SPURC_ALPHA_STEP_7_0_MASK                               0x0000003F
//========================================
/* REG_PHY_RXTD_ANT2_PM_SPURC_ALPHA_STEP_8_0 0x3C0 */
#define B0_PHY_RXTD_ANT2_PM_SPURC_ALPHA_STEP_8_0_FIELD_PM_SPURC_ALPHA_STEP_8_0_MASK                               0x0000003F
//========================================
/* REG_PHY_RXTD_ANT2_PM_SPURC_ALPHA_STEP_9_0 0x3C4 */
#define B0_PHY_RXTD_ANT2_PM_SPURC_ALPHA_STEP_9_0_FIELD_PM_SPURC_ALPHA_STEP_9_0_MASK                               0x0000003F
//========================================
/* REG_PHY_RXTD_ANT2_PM_SPURC_ALPHA_STEP_10_0 0x3C8 */
#define B0_PHY_RXTD_ANT2_PM_SPURC_ALPHA_STEP_10_0_FIELD_PM_SPURC_ALPHA_STEP_10_0_MASK                             0x0000003F
//========================================
/* REG_PHY_RXTD_ANT2_PM_SPURC_ALPHA_STEP_11_0 0x3CC */
#define B0_PHY_RXTD_ANT2_PM_SPURC_ALPHA_STEP_11_0_FIELD_PM_SPURC_ALPHA_STEP_11_0_MASK                             0x0000003F
//========================================
/* REG_PHY_RXTD_ANT2_PM_SPURC_ALPHA_STEP_12_0 0x3D0 */
#define B0_PHY_RXTD_ANT2_PM_SPURC_ALPHA_STEP_12_0_FIELD_PM_SPURC_ALPHA_STEP_12_0_MASK                             0x0000003F
//========================================
/* REG_PHY_RXTD_ANT2_PM_SPURC_ALPHA_STEP_13_0 0x3D4 */
#define B0_PHY_RXTD_ANT2_PM_SPURC_ALPHA_STEP_13_0_FIELD_PM_SPURC_ALPHA_STEP_13_0_MASK                             0x0000003F
//========================================
/* REG_PHY_RXTD_ANT2_PM_SPURC_ALPHA_STEP_14_0 0x3D8 */
#define B0_PHY_RXTD_ANT2_PM_SPURC_ALPHA_STEP_14_0_FIELD_PM_SPURC_ALPHA_STEP_14_0_MASK                             0x0000003F
//========================================
/* REG_PHY_RXTD_ANT2_PM_SPURC_ALPHA_STEP_15_0 0x3DC */
#define B0_PHY_RXTD_ANT2_PM_SPURC_ALPHA_STEP_15_0_FIELD_PM_SPURC_ALPHA_STEP_15_0_MASK                             0x0000003F
//========================================
/* REG_PHY_RXTD_ANT2_PM_SPURC_ALPHA_TIME_0_0 0x3E0 */
#define B0_PHY_RXTD_ANT2_PM_SPURC_ALPHA_TIME_0_0_FIELD_PM_SPURC_ALPHA_TIME_0_0_MASK                               0xFFFFFFFF
//========================================
/* REG_PHY_RXTD_ANT2_PM_SPURC_ALPHA_TIME_1_0 0x3E4 */
#define B0_PHY_RXTD_ANT2_PM_SPURC_ALPHA_TIME_1_0_FIELD_PM_SPURC_ALPHA_TIME_1_0_MASK                               0xFFFFFFFF
//========================================
/* REG_PHY_RXTD_ANT2_PM_SPURC_ALPHA_TIME_2_0 0x3E8 */
#define B0_PHY_RXTD_ANT2_PM_SPURC_ALPHA_TIME_2_0_FIELD_PM_SPURC_ALPHA_TIME_2_0_MASK                               0xFFFFFFFF
//========================================
/* REG_PHY_RXTD_ANT2_PM_SPURC_ALPHA_TIME_3_0 0x3EC */
#define B0_PHY_RXTD_ANT2_PM_SPURC_ALPHA_TIME_3_0_FIELD_PM_SPURC_ALPHA_TIME_3_0_MASK                               0xFFFFFFFF
//========================================
/* REG_PHY_RXTD_ANT2_PM_SPURC_ALPHA_TIME_4_0 0x3F0 */
#define B0_PHY_RXTD_ANT2_PM_SPURC_ALPHA_TIME_4_0_FIELD_PM_SPURC_ALPHA_TIME_4_0_MASK                               0xFFFFFFFF
//========================================
/* REG_PHY_RXTD_ANT2_PM_SPURC_ALPHA_TIME_5_0 0x3F4 */
#define B0_PHY_RXTD_ANT2_PM_SPURC_ALPHA_TIME_5_0_FIELD_PM_SPURC_ALPHA_TIME_5_0_MASK                               0xFFFFFFFF
//========================================
/* REG_PHY_RXTD_ANT2_PM_SPURC_ALPHA_TIME_6_0 0x3F8 */
#define B0_PHY_RXTD_ANT2_PM_SPURC_ALPHA_TIME_6_0_FIELD_PM_SPURC_ALPHA_TIME_6_0_MASK                               0xFFFFFFFF
//========================================
/* REG_PHY_RXTD_ANT2_PM_SPURC_ALPHA_TIME_7_0 0x3FC */
#define B0_PHY_RXTD_ANT2_PM_SPURC_ALPHA_TIME_7_0_FIELD_PM_SPURC_ALPHA_TIME_7_0_MASK                               0xFFFFFFFF
//========================================
/* REG_PHY_RXTD_ANT2_PM_SPURC_ALPHA_TIME_8_0 0x400 */
#define B0_PHY_RXTD_ANT2_PM_SPURC_ALPHA_TIME_8_0_FIELD_PM_SPURC_ALPHA_TIME_8_0_MASK                               0xFFFFFFFF
//========================================
/* REG_PHY_RXTD_ANT2_PM_SPURC_ALPHA_TIME_9_0 0x404 */
#define B0_PHY_RXTD_ANT2_PM_SPURC_ALPHA_TIME_9_0_FIELD_PM_SPURC_ALPHA_TIME_9_0_MASK                               0xFFFFFFFF
//========================================
/* REG_PHY_RXTD_ANT2_PM_SPURC_ALPHA_TIME_10_0 0x408 */
#define B0_PHY_RXTD_ANT2_PM_SPURC_ALPHA_TIME_10_0_FIELD_PM_SPURC_ALPHA_TIME_10_0_MASK                             0xFFFFFFFF
//========================================
/* REG_PHY_RXTD_ANT2_PM_SPURC_ALPHA_TIME_11_0 0x40C */
#define B0_PHY_RXTD_ANT2_PM_SPURC_ALPHA_TIME_11_0_FIELD_PM_SPURC_ALPHA_TIME_11_0_MASK                             0xFFFFFFFF
//========================================
/* REG_PHY_RXTD_ANT2_PM_SPURC_ALPHA_TIME_12_0 0x410 */
#define B0_PHY_RXTD_ANT2_PM_SPURC_ALPHA_TIME_12_0_FIELD_PM_SPURC_ALPHA_TIME_12_0_MASK                             0xFFFFFFFF
//========================================
/* REG_PHY_RXTD_ANT2_PM_SPURC_ALPHA_TIME_13_0 0x414 */
#define B0_PHY_RXTD_ANT2_PM_SPURC_ALPHA_TIME_13_0_FIELD_PM_SPURC_ALPHA_TIME_13_0_MASK                             0xFFFFFFFF
//========================================
/* REG_PHY_RXTD_ANT2_PM_SPURC_ALPHA_TIME_14_0 0x418 */
#define B0_PHY_RXTD_ANT2_PM_SPURC_ALPHA_TIME_14_0_FIELD_PM_SPURC_ALPHA_TIME_14_0_MASK                             0xFFFFFFFF
//========================================
/* REG_PHY_RXTD_ANT2_PM_SPURC_ALPHA_TIME_15_0 0x41C */
#define B0_PHY_RXTD_ANT2_PM_SPURC_ALPHA_TIME_15_0_FIELD_PM_SPURC_ALPHA_TIME_15_0_MASK                             0xFFFFFFFF
//========================================
/* REG_PHY_RXTD_ANT2_PM_SPURC_NSAMP_THR_1 0x420 */
#define B0_PHY_RXTD_ANT2_PM_SPURC_NSAMP_THR_1_FIELD_PM_SPURC_NSAMP_THR_1_MASK                                     0xFFFFFFFF
//========================================
/* REG_PHY_RXTD_ANT2_PM_SPURC_POW_THR_LOW_1 0x424 */
#define B0_PHY_RXTD_ANT2_PM_SPURC_POW_THR_LOW_1_FIELD_PM_SPURC_POW_THR_LOW_1_MASK                                 0xFFFFFFFF
//========================================
/* REG_PHY_RXTD_ANT2_PM_SPURC_POW_THR_HIGH_1 0x428 */
#define B0_PHY_RXTD_ANT2_PM_SPURC_POW_THR_HIGH_1_FIELD_PM_SPURC_POW_THR_HIGH_1_MASK                               0xFFFFFFFF
//========================================
/* REG_PHY_RXTD_ANT2_PM_SPURC_CONTROL_1 0x42C */
#define B0_PHY_RXTD_ANT2_PM_SPURC_CONTROL_1_FIELD_PM_SPURC_SHUTDOWN_1_MASK                                        0x00000001
#define B0_PHY_RXTD_ANT2_PM_SPURC_CONTROL_1_FIELD_PM_SPURC_STOP_1_MASK                                            0x00000002
#define B0_PHY_RXTD_ANT2_PM_SPURC_CONTROL_1_FIELD_PM_SPURC_BYPASS_1_MASK                                          0x00000004
#define B0_PHY_RXTD_ANT2_PM_SPURC_CONTROL_1_FIELD_PM_SPURC_FREEZE_1_MASK                                          0x00000008
#define B0_PHY_RXTD_ANT2_PM_SPURC_CONTROL_1_FIELD_PM_SPURC_DO_WHEN_AGC_1_MASK                                     0x00000030
//========================================
/* REG_PHY_RXTD_ANT2_PM_SPURC_GAIN_TIMER_1 0x430 */
#define B0_PHY_RXTD_ANT2_PM_SPURC_GAIN_TIMER_1_FIELD_PM_SPURC_GAIN_TIMER_1_MASK                                   0xFFFFFFFF
//========================================
/* REG_PHY_RXTD_ANT2_PM_SPURC_DDFS_PHASE_ADJUST_1 0x434 */
#define B0_PHY_RXTD_ANT2_PM_SPURC_DDFS_PHASE_ADJUST_1_FIELD_PM_SPURC_DDFS_PHASE_ADJUST_1_MASK                     0xFFFFFFFF
//========================================
/* REG_PHY_RXTD_ANT2_PM_SPURC_DDFS_PHASE_INIT_1 0x438 */
#define B0_PHY_RXTD_ANT2_PM_SPURC_DDFS_PHASE_INIT_1_FIELD_PM_SPURC_DDFS_PHASE_INIT_1_MASK                         0xFFFFFFFF
//========================================
/* REG_PHY_RXTD_ANT2_PM_SPURC_DDFS_FCW_1 0x43C */
#define B0_PHY_RXTD_ANT2_PM_SPURC_DDFS_FCW_1_FIELD_PM_SPURC_DDFS_FCW_1_MASK                                       0xFFFFFFFF
//========================================
/* REG_PHY_RXTD_ANT2_PM_SPURC_DDFS_P_Q_1 0x440 */
#define B0_PHY_RXTD_ANT2_PM_SPURC_DDFS_P_Q_1_FIELD_PM_SPURC_DDFS_P_1_MASK                                         0x000001FF
#define B0_PHY_RXTD_ANT2_PM_SPURC_DDFS_P_Q_1_FIELD_PM_SPURC_DDFS_Q_1_MASK                                         0x0003FE00
//========================================
/* REG_PHY_RXTD_ANT2_PM_SPURC_MEM_RESET_1 0x444 */
#define B0_PHY_RXTD_ANT2_PM_SPURC_MEM_RESET_1_FIELD_PM_SPURC_MEM_RESET_1_MASK                                     0x00000001
//========================================
/* REG_PHY_RXTD_ANT2_PM_SPURC_MEM_LOAD_1 0x448 */
#define B0_PHY_RXTD_ANT2_PM_SPURC_MEM_LOAD_1_FIELD_PM_SPURC_MEM_LOAD_1_MASK                                       0x00000007
//========================================
/* REG_PHY_RXTD_ANT2_PM_SPURC_MEM_M_R_31_0_1 0x44C */
#define B0_PHY_RXTD_ANT2_PM_SPURC_MEM_M_R_31_0_1_FIELD_PM_SPURC_MEM_M_R_31_0_1_MASK                               0xFFFFFFFF
//========================================
/* REG_PHY_RXTD_ANT2_PM_SPURC_MEM_M_R_37_32_1 0x450 */
#define B0_PHY_RXTD_ANT2_PM_SPURC_MEM_M_R_37_32_1_FIELD_PM_SPURC_MEM_M_R_37_32_1_MASK                             0x0000003F
//========================================
/* REG_PHY_RXTD_ANT2_PM_SPURC_MEM_M_I_31_0_1 0x454 */
#define B0_PHY_RXTD_ANT2_PM_SPURC_MEM_M_I_31_0_1_FIELD_PM_SPURC_MEM_M_I_31_0_1_MASK                               0xFFFFFFFF
//========================================
/* REG_PHY_RXTD_ANT2_PM_SPURC_MEM_M_I_37_32_1 0x458 */
#define B0_PHY_RXTD_ANT2_PM_SPURC_MEM_M_I_37_32_1_FIELD_PM_SPURC_MEM_M_I_37_32_1_MASK                             0x0000003F
//========================================
/* REG_PHY_RXTD_ANT2_PM_SPURC_MEM_NSAMP_1 0x45C */
#define B0_PHY_RXTD_ANT2_PM_SPURC_MEM_NSAMP_1_FIELD_PM_SPURC_MEM_NSAMP_1_MASK                                     0xFFFFFFFF
//========================================
/* REG_PHY_RXTD_ANT2_PM_SPURC_MEM_DIG_GAIN_1 0x460 */
#define B0_PHY_RXTD_ANT2_PM_SPURC_MEM_DIG_GAIN_1_FIELD_PM_SPURC_MEM_DIG_GAIN_1_MASK                               0x0000007F
//========================================
/* REG_PHY_RXTD_ANT2_PM_SPURC_MEM_ALPHA_IDX_1 0x464 */
#define B0_PHY_RXTD_ANT2_PM_SPURC_MEM_ALPHA_IDX_1_FIELD_PM_SPURC_MEM_ALPHA_IDX_1_MASK                             0x0000000F
//========================================
/* REG_PHY_RXTD_ANT2_PM_SPURC_ALPHA_STEP_0_1 0x468 */
#define B0_PHY_RXTD_ANT2_PM_SPURC_ALPHA_STEP_0_1_FIELD_PM_SPURC_ALPHA_STEP_0_1_MASK                               0x0000003F
//========================================
/* REG_PHY_RXTD_ANT2_PM_SPURC_ALPHA_STEP_1_1 0x46C */
#define B0_PHY_RXTD_ANT2_PM_SPURC_ALPHA_STEP_1_1_FIELD_PM_SPURC_ALPHA_STEP_1_1_MASK                               0x0000003F
//========================================
/* REG_PHY_RXTD_ANT2_PM_SPURC_ALPHA_STEP_2_1 0x470 */
#define B0_PHY_RXTD_ANT2_PM_SPURC_ALPHA_STEP_2_1_FIELD_PM_SPURC_ALPHA_STEP_2_1_MASK                               0x0000003F
//========================================
/* REG_PHY_RXTD_ANT2_PM_SPURC_ALPHA_STEP_3_1 0x474 */
#define B0_PHY_RXTD_ANT2_PM_SPURC_ALPHA_STEP_3_1_FIELD_PM_SPURC_ALPHA_STEP_3_1_MASK                               0x0000003F
//========================================
/* REG_PHY_RXTD_ANT2_PM_SPURC_ALPHA_STEP_4_1 0x478 */
#define B0_PHY_RXTD_ANT2_PM_SPURC_ALPHA_STEP_4_1_FIELD_PM_SPURC_ALPHA_STEP_4_1_MASK                               0x0000003F
//========================================
/* REG_PHY_RXTD_ANT2_PM_SPURC_ALPHA_STEP_5_1 0x47C */
#define B0_PHY_RXTD_ANT2_PM_SPURC_ALPHA_STEP_5_1_FIELD_PM_SPURC_ALPHA_STEP_5_1_MASK                               0x0000003F
//========================================
/* REG_PHY_RXTD_ANT2_PM_SPURC_ALPHA_STEP_6_1 0x480 */
#define B0_PHY_RXTD_ANT2_PM_SPURC_ALPHA_STEP_6_1_FIELD_PM_SPURC_ALPHA_STEP_6_1_MASK                               0x0000003F
//========================================
/* REG_PHY_RXTD_ANT2_PM_SPURC_ALPHA_STEP_7_1 0x484 */
#define B0_PHY_RXTD_ANT2_PM_SPURC_ALPHA_STEP_7_1_FIELD_PM_SPURC_ALPHA_STEP_7_1_MASK                               0x0000003F
//========================================
/* REG_PHY_RXTD_ANT2_PM_SPURC_ALPHA_STEP_8_1 0x488 */
#define B0_PHY_RXTD_ANT2_PM_SPURC_ALPHA_STEP_8_1_FIELD_PM_SPURC_ALPHA_STEP_8_1_MASK                               0x0000003F
//========================================
/* REG_PHY_RXTD_ANT2_PM_SPURC_ALPHA_STEP_9_1 0x48C */
#define B0_PHY_RXTD_ANT2_PM_SPURC_ALPHA_STEP_9_1_FIELD_PM_SPURC_ALPHA_STEP_9_1_MASK                               0x0000003F
//========================================
/* REG_PHY_RXTD_ANT2_PM_SPURC_ALPHA_STEP_10_1 0x490 */
#define B0_PHY_RXTD_ANT2_PM_SPURC_ALPHA_STEP_10_1_FIELD_PM_SPURC_ALPHA_STEP_10_1_MASK                             0x0000003F
//========================================
/* REG_PHY_RXTD_ANT2_PM_SPURC_ALPHA_STEP_11_1 0x494 */
#define B0_PHY_RXTD_ANT2_PM_SPURC_ALPHA_STEP_11_1_FIELD_PM_SPURC_ALPHA_STEP_11_1_MASK                             0x0000003F
//========================================
/* REG_PHY_RXTD_ANT2_PM_SPURC_ALPHA_STEP_12_1 0x498 */
#define B0_PHY_RXTD_ANT2_PM_SPURC_ALPHA_STEP_12_1_FIELD_PM_SPURC_ALPHA_STEP_12_1_MASK                             0x0000003F
//========================================
/* REG_PHY_RXTD_ANT2_PM_SPURC_ALPHA_STEP_13_1 0x49C */
#define B0_PHY_RXTD_ANT2_PM_SPURC_ALPHA_STEP_13_1_FIELD_PM_SPURC_ALPHA_STEP_13_1_MASK                             0x0000003F
//========================================
/* REG_PHY_RXTD_ANT2_PM_SPURC_ALPHA_STEP_14_1 0x4A0 */
#define B0_PHY_RXTD_ANT2_PM_SPURC_ALPHA_STEP_14_1_FIELD_PM_SPURC_ALPHA_STEP_14_1_MASK                             0x0000003F
//========================================
/* REG_PHY_RXTD_ANT2_PM_SPURC_ALPHA_STEP_15_1 0x4A4 */
#define B0_PHY_RXTD_ANT2_PM_SPURC_ALPHA_STEP_15_1_FIELD_PM_SPURC_ALPHA_STEP_15_1_MASK                             0x0000003F
//========================================
/* REG_PHY_RXTD_ANT2_PM_SPURC_ALPHA_TIME_0_1 0x4A8 */
#define B0_PHY_RXTD_ANT2_PM_SPURC_ALPHA_TIME_0_1_FIELD_PM_SPURC_ALPHA_TIME_0_1_MASK                               0xFFFFFFFF
//========================================
/* REG_PHY_RXTD_ANT2_PM_SPURC_ALPHA_TIME_1_1 0x4AC */
#define B0_PHY_RXTD_ANT2_PM_SPURC_ALPHA_TIME_1_1_FIELD_PM_SPURC_ALPHA_TIME_1_1_MASK                               0xFFFFFFFF
//========================================
/* REG_PHY_RXTD_ANT2_PM_SPURC_ALPHA_TIME_2_1 0x4B0 */
#define B0_PHY_RXTD_ANT2_PM_SPURC_ALPHA_TIME_2_1_FIELD_PM_SPURC_ALPHA_TIME_2_1_MASK                               0xFFFFFFFF
//========================================
/* REG_PHY_RXTD_ANT2_PM_SPURC_ALPHA_TIME_3_1 0x4B4 */
#define B0_PHY_RXTD_ANT2_PM_SPURC_ALPHA_TIME_3_1_FIELD_PM_SPURC_ALPHA_TIME_3_1_MASK                               0xFFFFFFFF
//========================================
/* REG_PHY_RXTD_ANT2_PM_SPURC_ALPHA_TIME_4_1 0x4B8 */
#define B0_PHY_RXTD_ANT2_PM_SPURC_ALPHA_TIME_4_1_FIELD_PM_SPURC_ALPHA_TIME_4_1_MASK                               0xFFFFFFFF
//========================================
/* REG_PHY_RXTD_ANT2_PM_SPURC_ALPHA_TIME_5_1 0x4BC */
#define B0_PHY_RXTD_ANT2_PM_SPURC_ALPHA_TIME_5_1_FIELD_PM_SPURC_ALPHA_TIME_5_1_MASK                               0xFFFFFFFF
//========================================
/* REG_PHY_RXTD_ANT2_PM_SPURC_ALPHA_TIME_6_1 0x4C0 */
#define B0_PHY_RXTD_ANT2_PM_SPURC_ALPHA_TIME_6_1_FIELD_PM_SPURC_ALPHA_TIME_6_1_MASK                               0xFFFFFFFF
//========================================
/* REG_PHY_RXTD_ANT2_PM_SPURC_ALPHA_TIME_7_1 0x4C4 */
#define B0_PHY_RXTD_ANT2_PM_SPURC_ALPHA_TIME_7_1_FIELD_PM_SPURC_ALPHA_TIME_7_1_MASK                               0xFFFFFFFF
//========================================
/* REG_PHY_RXTD_ANT2_PM_SPURC_ALPHA_TIME_8_1 0x4C8 */
#define B0_PHY_RXTD_ANT2_PM_SPURC_ALPHA_TIME_8_1_FIELD_PM_SPURC_ALPHA_TIME_8_1_MASK                               0xFFFFFFFF
//========================================
/* REG_PHY_RXTD_ANT2_PM_SPURC_ALPHA_TIME_9_1 0x4CC */
#define B0_PHY_RXTD_ANT2_PM_SPURC_ALPHA_TIME_9_1_FIELD_PM_SPURC_ALPHA_TIME_9_1_MASK                               0xFFFFFFFF
//========================================
/* REG_PHY_RXTD_ANT2_PM_SPURC_ALPHA_TIME_10_1 0x4D0 */
#define B0_PHY_RXTD_ANT2_PM_SPURC_ALPHA_TIME_10_1_FIELD_PM_SPURC_ALPHA_TIME_10_1_MASK                             0xFFFFFFFF
//========================================
/* REG_PHY_RXTD_ANT2_PM_SPURC_ALPHA_TIME_11_1 0x4D4 */
#define B0_PHY_RXTD_ANT2_PM_SPURC_ALPHA_TIME_11_1_FIELD_PM_SPURC_ALPHA_TIME_11_1_MASK                             0xFFFFFFFF
//========================================
/* REG_PHY_RXTD_ANT2_PM_SPURC_ALPHA_TIME_12_1 0x4D8 */
#define B0_PHY_RXTD_ANT2_PM_SPURC_ALPHA_TIME_12_1_FIELD_PM_SPURC_ALPHA_TIME_12_1_MASK                             0xFFFFFFFF
//========================================
/* REG_PHY_RXTD_ANT2_PM_SPURC_ALPHA_TIME_13_1 0x4DC */
#define B0_PHY_RXTD_ANT2_PM_SPURC_ALPHA_TIME_13_1_FIELD_PM_SPURC_ALPHA_TIME_13_1_MASK                             0xFFFFFFFF
//========================================
/* REG_PHY_RXTD_ANT2_PM_SPURC_ALPHA_TIME_14_1 0x4E0 */
#define B0_PHY_RXTD_ANT2_PM_SPURC_ALPHA_TIME_14_1_FIELD_PM_SPURC_ALPHA_TIME_14_1_MASK                             0xFFFFFFFF
//========================================
/* REG_PHY_RXTD_ANT2_PM_SPURC_ALPHA_TIME_15_1 0x4E4 */
#define B0_PHY_RXTD_ANT2_PM_SPURC_ALPHA_TIME_15_1_FIELD_PM_SPURC_ALPHA_TIME_15_1_MASK                             0xFFFFFFFF
//========================================
/* REG_PHY_RXTD_ANT2_PM_RXTD_SPURC_RAM_RM_0 0x4E8 */
#define B0_PHY_RXTD_ANT2_PM_RXTD_SPURC_RAM_RM_0_FIELD_PM_RXTD_SPURC_RAM_RM_0_MASK                                 0xFFFFFFFF
//========================================
/* REG_PHY_RXTD_ANT2_PM_RXTD_SPURC_RAM_RM_1 0x4EC */
#define B0_PHY_RXTD_ANT2_PM_RXTD_SPURC_RAM_RM_1_FIELD_PM_RXTD_SPURC_RAM_RM_1_MASK                                 0xFFFFFFFF
//========================================
/* REG_PHY_RXTD_ANT2_PM_RXTD_SPURC_GAIN_WORD 0x4F0 */
#define B0_PHY_RXTD_ANT2_PM_RXTD_SPURC_GAIN_WORD_FIELD_PM_SPURC_GAIN_WORD_MASK                                    0x00003FFF
//========================================
/* REG_PHY_RXTD_ANT2_PM_WHITE_NOISE 0x4F4 */
#define B0_PHY_RXTD_ANT2_PM_WHITE_NOISE_FIELD_WHITE_NOISE_ENABLE_MASK                                             0x00000001
#define B0_PHY_RXTD_ANT2_PM_WHITE_NOISE_FIELD_WHITE_NOISE_SNR_MASK                                                0x000001FE
//========================================
/* REG_PHY_RXTD_ANT2_PM_WHITE_NOISE_SEED 0x4F8 */
#define B0_PHY_RXTD_ANT2_PM_WHITE_NOISE_SEED_FIELD_WHITE_NOISE_SEED_MASK                                          0xFFFFFFFF
//========================================
/* REG_PHY_RXTD_ANT2_PM_NOTCH_SPUR_BANDSEL_EN 0x4FC */
#define B0_PHY_RXTD_ANT2_PM_NOTCH_SPUR_BANDSEL_EN_FIELD_PM_NOTCH_SPUR_BANDSEL_EN_MASK                             0x00000001
//========================================
/* REG_PHY_RXTD_ANT2_PM_BANDSELECT_IIR_ALPHA 0x500 */
#define B0_PHY_RXTD_ANT2_PM_BANDSELECT_IIR_ALPHA_FIELD_PM_BANDSELECT_IIR_ALPHA_MASK                               0x0000000F
//========================================
/* REG_PHY_RXTD_ANT2_PM_NOTCH_SPUR_MAIN_EN 0x504 */
#define B0_PHY_RXTD_ANT2_PM_NOTCH_SPUR_MAIN_EN_FIELD_PM_NOTCH_SPUR_MAIN_EN_MASK                                   0x00000001
//========================================
/* REG_PHY_RXTD_ANT2_PM_MAIN_IIR_ALPHA 0x508 */
#define B0_PHY_RXTD_ANT2_PM_MAIN_IIR_ALPHA_FIELD_PM_MAIN_IIR_ALPHA_MASK                                           0x0000000F
//========================================
/* REG_PHY_RXTD_ANT2_PM_NOTCH_SPUR_BYPASS_THR_20 0x50C */
#define B0_PHY_RXTD_ANT2_PM_NOTCH_SPUR_BYPASS_THR_20_FIELD_PM_NOTCH_SPUR_BYPASS_THR_20_MASK                       0x000001FF
//========================================
/* REG_PHY_RXTD_ANT2_PM_NOTCH_SPUR_BYPASS_THR_40 0x510 */
#define B0_PHY_RXTD_ANT2_PM_NOTCH_SPUR_BYPASS_THR_40_FIELD_PM_NOTCH_SPUR_BYPASS_THR_40_MASK                       0x000001FF
//========================================
/* REG_PHY_RXTD_ANT2_PM_NOTCH_SPUR_BYPASS_THR_80 0x514 */
#define B0_PHY_RXTD_ANT2_PM_NOTCH_SPUR_BYPASS_THR_80_FIELD_PM_NOTCH_SPUR_BYPASS_THR_80_MASK                       0x000001FF
//========================================
/* REG_PHY_RXTD_ANT2_PM_NOTCH_SPUR_BYPASS_THR_160_320 0x518 */
#define B0_PHY_RXTD_ANT2_PM_NOTCH_SPUR_BYPASS_THR_160_320_FIELD_PM_NOTCH_SPUR_BYPASS_THR_160_320_MASK             0x000001FF
//========================================
/* REG_PHY_RXTD_ANT2_PM_NOTCH_SPUR_BYPASS_SRC_CURR 0x51C */
#define B0_PHY_RXTD_ANT2_PM_NOTCH_SPUR_BYPASS_SRC_CURR_FIELD_PM_NOTCH_SPUR_BYPASS_SRC_CURR_MASK                   0x00000001
//========================================
/* REG_PHY_RXTD_ANT2_PM_NOTCH_SPUR_FREQ_OFFSET 0x520 */
#define B0_PHY_RXTD_ANT2_PM_NOTCH_SPUR_FREQ_OFFSET_FIELD_PM_NOTCH_SPUR_FREQ_OFFSET_MASK                           0x00000FFF
//========================================
/* REG_PHY_RXTD_ANT2_PM_ACIDET_PWR 0x524 */
#define B0_PHY_RXTD_ANT2_PM_ACIDET_PWR_FIELD_PM_ACIDET_PWR_MASK                                                   0x000001FF
//========================================
/* REG_PHY_RXTD_ANT2_PM_NOTCH_SPUR_BYPASS_CURR_ANT 0x528 */
#define B0_PHY_RXTD_ANT2_PM_NOTCH_SPUR_BYPASS_CURR_ANT_FIELD_PM_NOTCH_SPUR_BYPASS_CURR_ANT_MASK                   0x00000001
//========================================
/* REG_PHY_RXTD_ANT2_PM_NOTCH_SPUR_MAIN_BYPASS 0x52C */
#define B0_PHY_RXTD_ANT2_PM_NOTCH_SPUR_MAIN_BYPASS_FIELD_PM_NOTCH_SPUR_MAIN_BYPASS_MASK                           0x00000001


#endif // _PHY_RXTD_ANT2_REGS_H_
