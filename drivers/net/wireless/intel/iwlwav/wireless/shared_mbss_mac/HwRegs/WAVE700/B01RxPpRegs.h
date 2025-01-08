
/***********************************************************************************
File:				B01RxPpRegs.h
Module:				b01RxPp
SOC Revision:		latest
Generated at:       2022-05-04 10:57:03
Purpose:
Description:		This File was auto generated using SOC Online

************************************************************************************/
#ifndef _B01_RX_PP_REGS_H_
#define _B01_RX_PP_REGS_H_

/*---------------------------------------------------------------------------------
/						Registers Addresses													 
/----------------------------------------------------------------------------------*/
#include "HwMemoryMap.h"

#define B01_RX_PP_BASE_ADDRESS                             MEMORY_MAP_UNIT_47_BASE_ADDRESS
#define	REG_B01_RX_PP_SW_INST_CTL                     (B01_RX_PP_BASE_ADDRESS + 0x0)
#define	REG_B01_RX_PP_SW_INST_ADDR                    (B01_RX_PP_BASE_ADDRESS + 0x4)
#define	REG_B01_RX_PP_SW_HALT                         (B01_RX_PP_BASE_ADDRESS + 0x8)
#define	REG_B01_RX_PP_MPDU_IN_LIST                    (B01_RX_PP_BASE_ADDRESS + 0xC)
#define	REG_B01_RX_PP_ERR_LIST                        (B01_RX_PP_BASE_ADDRESS + 0x10)
#define	REG_B01_RX_PP_UMAC_DONE_LIST                  (B01_RX_PP_BASE_ADDRESS + 0x14)
#define	REG_B01_RX_PP_LIBERATOR_LIST                  (B01_RX_PP_BASE_ADDRESS + 0x18)
#define	REG_B01_RX_PP_RD_TYPE0_FORWARD_LIST           (B01_RX_PP_BASE_ADDRESS + 0x1C)
#define	REG_B01_RX_PP_RD_TYPE1_FORWARD_LIST           (B01_RX_PP_BASE_ADDRESS + 0x20)
#define	REG_B01_RX_PP_RD_TYPE2_FORWARD_LIST           (B01_RX_PP_BASE_ADDRESS + 0x24)
#define	REG_B01_RX_PP_RD_TYPE3_FORWARD_LIST           (B01_RX_PP_BASE_ADDRESS + 0x28)
#define	REG_B01_RX_PP_RD_TYPE4_FORWARD_LIST           (B01_RX_PP_BASE_ADDRESS + 0x2C)
#define	REG_B01_RX_PP_RD_TYPE5_FORWARD_LIST           (B01_RX_PP_BASE_ADDRESS + 0x30)
#define	REG_B01_RX_PP_RD_TYPE6_FORWARD_LIST           (B01_RX_PP_BASE_ADDRESS + 0x34)
#define	REG_B01_RX_PP_RD_TYPE7_FORWARD_LIST           (B01_RX_PP_BASE_ADDRESS + 0x38)
#define	REG_B01_RX_PP_RD_TYPE8_FORWARD_LIST           (B01_RX_PP_BASE_ADDRESS + 0x3C)
#define	REG_B01_RX_PP_RD_TYPE9_FORWARD_LIST           (B01_RX_PP_BASE_ADDRESS + 0x40)
#define	REG_B01_RX_PP_RD_TYPE10_FORWARD_LIST          (B01_RX_PP_BASE_ADDRESS + 0x44)
#define	REG_B01_RX_PP_RD_TYPE11_FORWARD_LIST          (B01_RX_PP_BASE_ADDRESS + 0x48)
#define	REG_B01_RX_PP_RD_TYPE12_FORWARD_LIST          (B01_RX_PP_BASE_ADDRESS + 0x4C)
#define	REG_B01_RX_PP_RD_TYPE13_FORWARD_LIST          (B01_RX_PP_BASE_ADDRESS + 0x50)
#define	REG_B01_RX_PP_RD_TYPE14_FORWARD_LIST          (B01_RX_PP_BASE_ADDRESS + 0x54)
#define	REG_B01_RX_PP_RD_TYPE15_FORWARD_LIST          (B01_RX_PP_BASE_ADDRESS + 0x58)
#define	REG_B01_RX_PP_RD_TYPE16_FORWARD_LIST          (B01_RX_PP_BASE_ADDRESS + 0x5C)
#define	REG_B01_RX_PP_RD_TYPE17_FORWARD_LIST          (B01_RX_PP_BASE_ADDRESS + 0x60)
#define	REG_B01_RX_PP_RD_TYPE18_FORWARD_LIST          (B01_RX_PP_BASE_ADDRESS + 0x64)
#define	REG_B01_RX_PP_RD_TYPE19_FORWARD_LIST          (B01_RX_PP_BASE_ADDRESS + 0x68)
#define	REG_B01_RX_PP_RD_TYPE20_FORWARD_LIST          (B01_RX_PP_BASE_ADDRESS + 0x6C)
#define	REG_B01_RX_PP_RD_TYPE21_FORWARD_LIST          (B01_RX_PP_BASE_ADDRESS + 0x70)
#define	REG_B01_RX_PP_RD_TYPE22_FORWARD_LIST          (B01_RX_PP_BASE_ADDRESS + 0x74)
#define	REG_B01_RX_PP_RD_TYPE23_FORWARD_LIST          (B01_RX_PP_BASE_ADDRESS + 0x78)
#define	REG_B01_RX_PP_RD_TYPE24_FORWARD_LIST          (B01_RX_PP_BASE_ADDRESS + 0x7C)
#define	REG_B01_RX_PP_RD_TYPE25_FORWARD_LIST          (B01_RX_PP_BASE_ADDRESS + 0x80)
#define	REG_B01_RX_PP_RD_TYPE26_FORWARD_LIST          (B01_RX_PP_BASE_ADDRESS + 0x84)
#define	REG_B01_RX_PP_RD_TYPE27_FORWARD_LIST          (B01_RX_PP_BASE_ADDRESS + 0x88)
#define	REG_B01_RX_PP_RD_TYPE28_FORWARD_LIST          (B01_RX_PP_BASE_ADDRESS + 0x8C)
#define	REG_B01_RX_PP_RD_TYPE29_FORWARD_LIST          (B01_RX_PP_BASE_ADDRESS + 0x90)
#define	REG_B01_RX_PP_RD_TYPE30_FORWARD_LIST          (B01_RX_PP_BASE_ADDRESS + 0x94)
#define	REG_B01_RX_PP_RD_TYPE31_FORWARD_LIST          (B01_RX_PP_BASE_ADDRESS + 0x98)
#define	REG_B01_RX_PP_RD_TYPE_SKIP_CFG                (B01_RX_PP_BASE_ADDRESS + 0xA0)
#define	REG_B01_RX_PP_RD_TYPE_SEC_SKIP_CFG            (B01_RX_PP_BASE_ADDRESS + 0xA4)
#define	REG_B01_RX_PP_RD_TYPE_UMAC_CFG                (B01_RX_PP_BASE_ADDRESS + 0xA8)
#define	REG_B01_RX_PP_SHRAM_FIFO_CFG                  (B01_RX_PP_BASE_ADDRESS + 0xAC)
#define	REG_B01_RX_PP_SHRAM_FIFO_BASE_ADD             (B01_RX_PP_BASE_ADDRESS + 0xB0)
#define	REG_B01_RX_PP_SHRAM_FIFO_DEPTH_MINUS_ONE      (B01_RX_PP_BASE_ADDRESS + 0xB4)
#define	REG_B01_RX_PP_SHRAM_FIFO_CLEAR_STRB           (B01_RX_PP_BASE_ADDRESS + 0xB8)
#define	REG_B01_RX_PP_SHRAM_FIFO_RD_ENTRIES_NUM       (B01_RX_PP_BASE_ADDRESS + 0xBC)
#define	REG_B01_RX_PP_SHRAM_FIFO_NUM_ENTRIES_COUNT    (B01_RX_PP_BASE_ADDRESS + 0xC0)
#define	REG_B01_RX_PP_SHRAM_FIFO_DEBUG                (B01_RX_PP_BASE_ADDRESS + 0xC4)
#define	REG_B01_RX_PP_SYN_FIFO_STATUS                 (B01_RX_PP_BASE_ADDRESS + 0xC8)
#define	REG_B01_RX_PP_CONTROL_BACKDOOR_UPDATE         (B01_RX_PP_BASE_ADDRESS + 0xCC)
#define	REG_B01_RX_PP_RX_PP_SPARE                     (B01_RX_PP_BASE_ADDRESS + 0xD0)
#define	REG_B01_RX_PP_RX_COUNTERS_CFG                 (B01_RX_PP_BASE_ADDRESS + 0xD4)
#define	REG_B01_RX_PP_RX_LOGGER_CFG                   (B01_RX_PP_BASE_ADDRESS + 0xD8)
#define	REG_B01_RX_PP_RX_LOGGER_BUSY                  (B01_RX_PP_BASE_ADDRESS + 0xDC)
#define	REG_B01_RX_PP_SW_REKEY_EN                     (B01_RX_PP_BASE_ADDRESS + 0xE0)
#define	REG_B01_RX_PP_SW_REKEY_INST_LSB               (B01_RX_PP_BASE_ADDRESS + 0xE4)
#define	REG_B01_RX_PP_SW_REKEY_INST_MSB               (B01_RX_PP_BASE_ADDRESS + 0xE8)
#define	REG_B01_RX_PP_FRAG_DIS_LIB_ERR_LIST           (B01_RX_PP_BASE_ADDRESS + 0xEC)
#define	REG_B01_RX_PP_SM_STATUS_PART1                 (B01_RX_PP_BASE_ADDRESS + 0xF0)
#define	REG_B01_RX_PP_SM_STATUS_PART2                 (B01_RX_PP_BASE_ADDRESS + 0xF4)
#define	REG_B01_RX_PP_UC_MGMT_TID_CFG                 (B01_RX_PP_BASE_ADDRESS + 0xF8)
#define	REG_B01_RX_PP_MC_CFG                          (B01_RX_PP_BASE_ADDRESS + 0xFC)
#define	REG_B01_RX_PP_RX_PP_INT_ERROR_STATUS          (B01_RX_PP_BASE_ADDRESS + 0x100)
#define	REG_B01_RX_PP_RX_PP_INT_ERROR_EN              (B01_RX_PP_BASE_ADDRESS + 0x104)
#define	REG_B01_RX_PP_RX_PP_INT_ERROR_CLEAR           (B01_RX_PP_BASE_ADDRESS + 0x108)
#define	REG_B01_RX_PP_RX_PP_CONTROL_BITS              (B01_RX_PP_BASE_ADDRESS + 0x10C)
#define	REG_B01_RX_PP_RXDD_SW_UPDATE_LAST_SN          (B01_RX_PP_BASE_ADDRESS + 0x110)
#define	REG_B01_RX_PP_RXDD_SW_UPDATE_DUP_ENABLE       (B01_RX_PP_BASE_ADDRESS + 0x114)
#define	REG_B01_RX_PP_RXDD_SW_UPDATE_SN_VALID         (B01_RX_PP_BASE_ADDRESS + 0x118)
#define	REG_B01_RX_PP_RXDD_SW_RD_DUP_DB               (B01_RX_PP_BASE_ADDRESS + 0x11C)
#define	REG_B01_RX_PP_RXDD_SN_0_INFO_DBG              (B01_RX_PP_BASE_ADDRESS + 0x120)
#define	REG_B01_RX_PP_RXDD_SN_1_INFO_DBG              (B01_RX_PP_BASE_ADDRESS + 0x124)
#define	REG_B01_RX_PP_RXDD_SN_2_INFO_DBG              (B01_RX_PP_BASE_ADDRESS + 0x128)
#define	REG_B01_RX_PP_RXDD_SN_3_INFO_DBG              (B01_RX_PP_BASE_ADDRESS + 0x12C)
#define	REG_B01_RX_PP_RXDD_SN_4_INFO_DBG              (B01_RX_PP_BASE_ADDRESS + 0x130)
#define	REG_B01_RX_PP_RXDD_SN_5_INFO_DBG              (B01_RX_PP_BASE_ADDRESS + 0x134)
#define	REG_B01_RX_PP_RXDD_SN_6_INFO_DBG              (B01_RX_PP_BASE_ADDRESS + 0x138)
#define	REG_B01_RX_PP_RXDD_SN_7_INFO_DBG              (B01_RX_PP_BASE_ADDRESS + 0x13C)
#define	REG_B01_RX_PP_MC_DATA_CFG                     (B01_RX_PP_BASE_ADDRESS + 0x140)
/*---------------------------------------------------------------------------------
/						Data Type Definition										
/----------------------------------------------------------------------------------*/
/*REG_B01_RX_PP_SW_INST_CTL 0x0 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 baWindowSize : 9; //BA window size, reset value: 0x0, access type: RW
		uint32 statusBitValue : 1; //no description, reset value: 0x0, access type: RW
		uint32 fragEnValue : 1; //no description, reset value: 0x0, access type: RW
		uint32 fragEnUpdate : 1; //Frag_en bit update. Relevant for BAA only, reset value: 0x0, access type: RW
		uint32 newSn : 12; //New SN value. Valid when sn_update is asserted, reset value: 0x0, access type: RW
		uint32 clearDest : 1; //Deciding where to send SNs in list when clearing it , reset value: 0x0, access type: RW
		uint32 noBaForce : 1; //no description, reset value: 0x0, access type: RW
		uint32 reserved0 : 1;
		uint32 mulTids : 1; //no description, reset value: 0x0, access type: RW
		uint32 snUpdate : 1; //New SN update, reset value: 0x0, access type: RW
		uint32 winSizeUpdate : 1; //Window size update, reset value: 0x0, access type: RW
		uint32 flush : 1; //Flushing all SNs from list, reset value: 0x0, access type: RW
		uint32 statusBitUpdate : 1; //no description, reset value: 0x0, access type: RW
	} bitFields;
} RegB01RxPpSwInstCtl_u;

/*REG_B01_RX_PP_SW_INST_ADDR 0x4 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 tid : 4; //TID address. Valid values are 0-8, reset value: 0x0, access type: RW
		uint32 sta : 8; //STA address. Valid values are 0-127, reset value: 0x0, access type: RW
		uint32 swInstDone : 1; //no description, reset value: 0x0, access type: RO
		uint32 mcVapAccess : 1; //no description, reset value: 0x0, access type: RW
		uint32 mulTidsEn : 9; //no description, reset value: 0x0, access type: RW
		uint32 mulTidsFragEnValue : 9; //no description, reset value: 0x0, access type: RW
	} bitFields;
} RegB01RxPpSwInstAddr_u;

/*REG_B01_RX_PP_SW_HALT 0x8 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 swHalt : 1; //Halts the block from moving to the next MPDU, reset value: 0x1, access type: RW
		uint32 reserved0 : 31;
	} bitFields;
} RegB01RxPpSwHalt_u;

/*REG_B01_RX_PP_MPDU_IN_LIST 0xC */
typedef union
{
	uint32 val;
	struct
	{
		uint32 mpduInListIdx : 6; //MPDU list index number at the RX lists DLM, reset value: 0x11, access type: RW
		uint32 reserved0 : 26;
	} bitFields;
} RegB01RxPpMpduInList_u;

/*REG_B01_RX_PP_ERR_LIST 0x10 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 errListIdx : 7; //Host IF list index number at the RX lists DLM. MSBit serves as destination ID, reset value: 0x0, access type: RW
		uint32 reserved0 : 25;
	} bitFields;
} RegB01RxPpErrList_u;

/*REG_B01_RX_PP_UMAC_DONE_LIST 0x14 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 umacDoneListIdx : 7; //UMAC done list index number at the RX lists DLM. MSBit serves as destination ID, reset value: 0x12, access type: RW
		uint32 reserved0 : 25;
	} bitFields;
} RegB01RxPpUmacDoneList_u;

/*REG_B01_RX_PP_LIBERATOR_LIST 0x18 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 liberatorListIdx : 7; //Drop src0 Host IF list index number at the RX lists DLM. MSBit serves as destination ID, reset value: 0x0, access type: RW
		uint32 reserved0 : 25;
	} bitFields;
} RegB01RxPpLiberatorList_u;

/*REG_B01_RX_PP_RD_TYPE0_FORWARD_LIST 0x1C */
typedef union
{
	uint32 val;
	struct
	{
		uint32 rdType0ListIdx : 7; //no description, reset value: 0x0, access type: RW
		uint32 reserved0 : 25;
	} bitFields;
} RegB01RxPpRdType0ForwardList_u;

/*REG_B01_RX_PP_RD_TYPE1_FORWARD_LIST 0x20 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 rdType1ListIdx : 7; //no description, reset value: 0x0, access type: RW
		uint32 reserved0 : 25;
	} bitFields;
} RegB01RxPpRdType1ForwardList_u;

/*REG_B01_RX_PP_RD_TYPE2_FORWARD_LIST 0x24 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 rdType2ListIdx : 7; //no description, reset value: 0x0, access type: RW
		uint32 reserved0 : 25;
	} bitFields;
} RegB01RxPpRdType2ForwardList_u;

/*REG_B01_RX_PP_RD_TYPE3_FORWARD_LIST 0x28 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 rdType3ListIdx : 7; //no description, reset value: 0x0, access type: RW
		uint32 reserved0 : 25;
	} bitFields;
} RegB01RxPpRdType3ForwardList_u;

/*REG_B01_RX_PP_RD_TYPE4_FORWARD_LIST 0x2C */
typedef union
{
	uint32 val;
	struct
	{
		uint32 rdType4ListIdx : 7; //no description, reset value: 0x0, access type: RW
		uint32 reserved0 : 25;
	} bitFields;
} RegB01RxPpRdType4ForwardList_u;

/*REG_B01_RX_PP_RD_TYPE5_FORWARD_LIST 0x30 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 rdType5ListIdx : 7; //no description, reset value: 0x0, access type: RW
		uint32 reserved0 : 25;
	} bitFields;
} RegB01RxPpRdType5ForwardList_u;

/*REG_B01_RX_PP_RD_TYPE6_FORWARD_LIST 0x34 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 rdType6ListIdx : 7; //no description, reset value: 0x0, access type: RW
		uint32 reserved0 : 25;
	} bitFields;
} RegB01RxPpRdType6ForwardList_u;

/*REG_B01_RX_PP_RD_TYPE7_FORWARD_LIST 0x38 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 rdType7ListIdx : 7; //no description, reset value: 0x0, access type: RW
		uint32 reserved0 : 25;
	} bitFields;
} RegB01RxPpRdType7ForwardList_u;

/*REG_B01_RX_PP_RD_TYPE8_FORWARD_LIST 0x3C */
typedef union
{
	uint32 val;
	struct
	{
		uint32 rdType8ListIdx : 7; //no description, reset value: 0x0, access type: RW
		uint32 reserved0 : 25;
	} bitFields;
} RegB01RxPpRdType8ForwardList_u;

/*REG_B01_RX_PP_RD_TYPE9_FORWARD_LIST 0x40 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 rdType9ListIdx : 7; //no description, reset value: 0x0, access type: RW
		uint32 reserved0 : 25;
	} bitFields;
} RegB01RxPpRdType9ForwardList_u;

/*REG_B01_RX_PP_RD_TYPE10_FORWARD_LIST 0x44 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 rdType10ListIdx : 7; //no description, reset value: 0x0, access type: RW
		uint32 reserved0 : 25;
	} bitFields;
} RegB01RxPpRdType10ForwardList_u;

/*REG_B01_RX_PP_RD_TYPE11_FORWARD_LIST 0x48 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 rdType11ListIdx : 7; //no description, reset value: 0x0, access type: RW
		uint32 reserved0 : 25;
	} bitFields;
} RegB01RxPpRdType11ForwardList_u;

/*REG_B01_RX_PP_RD_TYPE12_FORWARD_LIST 0x4C */
typedef union
{
	uint32 val;
	struct
	{
		uint32 rdType12ListIdx : 7; //no description, reset value: 0x0, access type: RW
		uint32 reserved0 : 25;
	} bitFields;
} RegB01RxPpRdType12ForwardList_u;

/*REG_B01_RX_PP_RD_TYPE13_FORWARD_LIST 0x50 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 rdType13ListIdx : 7; //no description, reset value: 0x0, access type: RW
		uint32 reserved0 : 25;
	} bitFields;
} RegB01RxPpRdType13ForwardList_u;

/*REG_B01_RX_PP_RD_TYPE14_FORWARD_LIST 0x54 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 rdType14ListIdx : 7; //no description, reset value: 0x0, access type: RW
		uint32 reserved0 : 25;
	} bitFields;
} RegB01RxPpRdType14ForwardList_u;

/*REG_B01_RX_PP_RD_TYPE15_FORWARD_LIST 0x58 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 rdType15ListIdx : 7; //no description, reset value: 0x0, access type: RW
		uint32 reserved0 : 25;
	} bitFields;
} RegB01RxPpRdType15ForwardList_u;

/*REG_B01_RX_PP_RD_TYPE16_FORWARD_LIST 0x5C */
typedef union
{
	uint32 val;
	struct
	{
		uint32 rdType16ListIdx : 7; //no description, reset value: 0x0, access type: RW
		uint32 reserved0 : 25;
	} bitFields;
} RegB01RxPpRdType16ForwardList_u;

/*REG_B01_RX_PP_RD_TYPE17_FORWARD_LIST 0x60 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 rdType17ListIdx : 7; //no description, reset value: 0x0, access type: RW
		uint32 reserved0 : 25;
	} bitFields;
} RegB01RxPpRdType17ForwardList_u;

/*REG_B01_RX_PP_RD_TYPE18_FORWARD_LIST 0x64 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 rdType18ListIdx : 7; //no description, reset value: 0x0, access type: RW
		uint32 reserved0 : 25;
	} bitFields;
} RegB01RxPpRdType18ForwardList_u;

/*REG_B01_RX_PP_RD_TYPE19_FORWARD_LIST 0x68 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 rdType19ListIdx : 7; //no description, reset value: 0x0, access type: RW
		uint32 reserved0 : 25;
	} bitFields;
} RegB01RxPpRdType19ForwardList_u;

/*REG_B01_RX_PP_RD_TYPE20_FORWARD_LIST 0x6C */
typedef union
{
	uint32 val;
	struct
	{
		uint32 rdType20ListIdx : 7; //no description, reset value: 0x0, access type: RW
		uint32 reserved0 : 25;
	} bitFields;
} RegB01RxPpRdType20ForwardList_u;

/*REG_B01_RX_PP_RD_TYPE21_FORWARD_LIST 0x70 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 rdType21ListIdx : 7; //no description, reset value: 0x0, access type: RW
		uint32 reserved0 : 25;
	} bitFields;
} RegB01RxPpRdType21ForwardList_u;

/*REG_B01_RX_PP_RD_TYPE22_FORWARD_LIST 0x74 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 rdType22ListIdx : 7; //no description, reset value: 0x0, access type: RW
		uint32 reserved0 : 25;
	} bitFields;
} RegB01RxPpRdType22ForwardList_u;

/*REG_B01_RX_PP_RD_TYPE23_FORWARD_LIST 0x78 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 rdType23ListIdx : 7; //no description, reset value: 0x0, access type: RW
		uint32 reserved0 : 25;
	} bitFields;
} RegB01RxPpRdType23ForwardList_u;

/*REG_B01_RX_PP_RD_TYPE24_FORWARD_LIST 0x7C */
typedef union
{
	uint32 val;
	struct
	{
		uint32 rdType24ListIdx : 7; //no description, reset value: 0x0, access type: RW
		uint32 reserved0 : 25;
	} bitFields;
} RegB01RxPpRdType24ForwardList_u;

/*REG_B01_RX_PP_RD_TYPE25_FORWARD_LIST 0x80 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 rdType25ListIdx : 7; //no description, reset value: 0x0, access type: RW
		uint32 reserved0 : 25;
	} bitFields;
} RegB01RxPpRdType25ForwardList_u;

/*REG_B01_RX_PP_RD_TYPE26_FORWARD_LIST 0x84 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 rdType26ListIdx : 7; //no description, reset value: 0x0, access type: RW
		uint32 reserved0 : 25;
	} bitFields;
} RegB01RxPpRdType26ForwardList_u;

/*REG_B01_RX_PP_RD_TYPE27_FORWARD_LIST 0x88 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 rdType27ListIdx : 7; //no description, reset value: 0x0, access type: RW
		uint32 reserved0 : 25;
	} bitFields;
} RegB01RxPpRdType27ForwardList_u;

/*REG_B01_RX_PP_RD_TYPE28_FORWARD_LIST 0x8C */
typedef union
{
	uint32 val;
	struct
	{
		uint32 rdType28ListIdx : 7; //no description, reset value: 0x0, access type: RW
		uint32 reserved0 : 25;
	} bitFields;
} RegB01RxPpRdType28ForwardList_u;

/*REG_B01_RX_PP_RD_TYPE29_FORWARD_LIST 0x90 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 rdType29ListIdx : 7; //no description, reset value: 0x0, access type: RW
		uint32 reserved0 : 25;
	} bitFields;
} RegB01RxPpRdType29ForwardList_u;

/*REG_B01_RX_PP_RD_TYPE30_FORWARD_LIST 0x94 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 rdType30ListIdx : 7; //no description, reset value: 0x0, access type: RW
		uint32 reserved0 : 25;
	} bitFields;
} RegB01RxPpRdType30ForwardList_u;

/*REG_B01_RX_PP_RD_TYPE31_FORWARD_LIST 0x98 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 rdType31ListIdx : 7; //no description, reset value: 0x0, access type: RW
		uint32 reserved0 : 25;
	} bitFields;
} RegB01RxPpRdType31ForwardList_u;

/*REG_B01_RX_PP_RD_TYPE_SKIP_CFG 0xA0 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 skipBit : 32; //no description, reset value: 0xFFFFFFFF, access type: RW
	} bitFields;
} RegB01RxPpRdTypeSkipCfg_u;

/*REG_B01_RX_PP_RD_TYPE_SEC_SKIP_CFG 0xA4 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 secSkipBit : 32; //no description, reset value: 0xFFFFFFFF, access type: RW
	} bitFields;
} RegB01RxPpRdTypeSecSkipCfg_u;

/*REG_B01_RX_PP_RD_TYPE_UMAC_CFG 0xA8 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 umacBit : 32; //no description, reset value: 0xFFFFFFFF, access type: RW
	} bitFields;
} RegB01RxPpRdTypeUmacCfg_u;

/*REG_B01_RX_PP_SHRAM_FIFO_CFG 0xAC */
typedef union
{
	uint32 val;
	struct
	{
		uint32 shramFifoEn : 1; //no description, reset value: 0x1, access type: RW
		uint32 reserved0 : 31;
	} bitFields;
} RegB01RxPpShramFifoCfg_u;

/*REG_B01_RX_PP_SHRAM_FIFO_BASE_ADD 0xB0 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 shramFifoBaseAddr : 22; //SHRAM Frag FIFO base address - Byte aligned, reset value: 0x0, access type: RW
		uint32 reserved0 : 10;
	} bitFields;
} RegB01RxPpShramFifoBaseAdd_u;

/*REG_B01_RX_PP_SHRAM_FIFO_DEPTH_MINUS_ONE 0xB4 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 shramFifoDepthMinusOne : 10; //no description, reset value: 0x100, access type: RW
		uint32 reserved0 : 22;
	} bitFields;
} RegB01RxPpShramFifoDepthMinusOne_u;

/*REG_B01_RX_PP_SHRAM_FIFO_CLEAR_STRB 0xB8 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 shramFifoClearStrb : 1; //no description, reset value: 0x0, access type: WO
		uint32 reserved0 : 31;
	} bitFields;
} RegB01RxPpShramFifoClearStrb_u;

/*REG_B01_RX_PP_SHRAM_FIFO_RD_ENTRIES_NUM 0xBC */
typedef union
{
	uint32 val;
	struct
	{
		uint32 shramFifoRdEntriesNum : 11; //no description, reset value: 0x0, access type: RW
		uint32 reserved0 : 21;
	} bitFields;
} RegB01RxPpShramFifoRdEntriesNum_u;

/*REG_B01_RX_PP_SHRAM_FIFO_NUM_ENTRIES_COUNT 0xC0 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 shramFifoNumEntriesCount : 11; //no description, reset value: 0x0, access type: RO
		uint32 reserved0 : 21;
	} bitFields;
} RegB01RxPpShramFifoNumEntriesCount_u;

/*REG_B01_RX_PP_SHRAM_FIFO_DEBUG 0xC4 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 shramFifoWrPtr : 10; //no description, reset value: 0x0, access type: RO
		uint32 reserved0 : 6;
		uint32 shramFifoNotEmpty : 1; //no description, reset value: 0x0, access type: RO
		uint32 shramFifoFull : 1; //no description, reset value: 0x0, access type: RO
		uint32 reserved1 : 6;
		uint32 shramFifoFullDropCtr : 8; //no description, reset value: 0x0, access type: RO
	} bitFields;
} RegB01RxPpShramFifoDebug_u;

/*REG_B01_RX_PP_SYN_FIFO_STATUS 0xC8 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 shramSynFifoBytesInFifo : 2; //no description, reset value: 0x0, access type: RO
		uint32 reserved0 : 2;
		uint32 shramSynFifoFull : 1; //no description, reset value: 0x0, access type: RO
		uint32 shramSynFifoEmpty : 1; //no description, reset value: 0x0, access type: RO
		uint32 shramSynFifoPopWhileEmpty : 1; //no description, reset value: 0x0, access type: RO
		uint32 shramSynFifoPushWhileFull : 1; //no description, reset value: 0x0, access type: RO
		uint32 reserved1 : 24;
	} bitFields;
} RegB01RxPpSynFifoStatus_u;

/*REG_B01_RX_PP_CONTROL_BACKDOOR_UPDATE 0xCC */
typedef union
{
	uint32 val;
	struct
	{
		uint32 controlSnNumValid : 1; //SN num valid bit value, reset value: 0x0, access type: RW
		uint32 controlPnNumValid : 1; //PN num valid bit value, reset value: 0x0, access type: RW
		uint32 controlFragEn : 1; //Frag_en bit. Used in BAA only, reset value: 0x0, access type: RW
		uint32 controlHighestSnNumValid : 1; //Highest SN in window valid, reset value: 0x0, access type: RW
		uint32 controlBe : 4; //Valid bits be, reset value: 0x0, access type: RW
		uint32 controlUpdateDone : 1; //no description, reset value: 0x0, access type: RO
		uint32 reserved0 : 23;
	} bitFields;
} RegB01RxPpControlBackdoorUpdate_u;

/*REG_B01_RX_PP_RX_PP_SPARE 0xD0 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 rxPpSpare : 32; //no description, reset value: 0x0, access type: RW
	} bitFields;
} RegB01RxPpRxPpSpare_u;

/*REG_B01_RX_PP_RX_COUNTERS_CFG 0xD4 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 qosRxEn : 1; //no description, reset value: 0x0, access type: RW
		uint32 rdCountEn : 1; //no description, reset value: 0x0, access type: RW
		uint32 rdDelayedCountEn : 1; //no description, reset value: 0x0, access type: RW
		uint32 rdSwDropCountEn : 1; //no description, reset value: 0x0, access type: RW
		uint32 rdDuplicateDropCountEn : 1; //no description, reset value: 0x0, access type: RW
		uint32 missingSnSwUpdateCountEn : 1; //no description, reset value: 0x0, access type: RW
		uint32 mpduUniOrMgmtEn : 1; //no description, reset value: 0x0, access type: RW
		uint32 mpduRetryEn : 1; //no description, reset value: 0x0, access type: RW
		uint32 amsduCountEn : 1; //no description, reset value: 0x0, access type: RW
		uint32 dropMpduEn : 1; //no description, reset value: 0x0, access type: RW
		uint32 mpduTypeNotSupportedEn : 1; //no description, reset value: 0x0, access type: RW
		uint32 barMpduCountEn : 1; //no description, reset value: 0x0, access type: RW
		uint32 replayEn : 1; //no description, reset value: 0x0, access type: RW
		uint32 replayMgmtEn : 1; //no description, reset value: 0x0, access type: RW
		uint32 tkipCountEn : 1; //no description, reset value: 0x0, access type: RW
		uint32 failureCountEn : 1; //no description, reset value: 0x0, access type: RW
		uint32 rxClassAmsduBytesStbEn : 1; //no description, reset value: 0x0, access type: RW
		uint32 rxcAmpduStbEn : 1; //no description, reset value: 0x0, access type: RW
		uint32 rxClassMpduInAmpduStbEn : 1; //no description, reset value: 0x0, access type: RW
		uint32 rxClassOctetMpduStbEn : 1; //no description, reset value: 0x0, access type: RW
		uint32 rxClassDropStbEn : 1; //no description, reset value: 0x0, access type: RW
		uint32 rxClassSecurMisStbEn : 1; //no description, reset value: 0x0, access type: RW
		uint32 rxcCrcErrorStbEn : 1; //no description, reset value: 0x0, access type: RW
		uint32 delineatorCrcErrorStbEn : 1; //no description, reset value: 0x0, access type: RW
		uint32 bcMcCountEn : 1; //no description, reset value: 0x0, access type: RW
		uint32 reserved0 : 5;
		uint32 qosRxDecEn : 1; //no description, reset value: 0x0, access type: RW
		uint32 rxCountCleanFifo : 1; //no description, reset value: 0x0, access type: WO
	} bitFields;
} RegB01RxPpRxCountersCfg_u;

/*REG_B01_RX_PP_RX_LOGGER_CFG 0xD8 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 rxPpLoggerPriority : 2; //no description, reset value: 0x0, access type: RW
		uint32 rxPpLoggerEn : 1; //no description, reset value: 0x0, access type: RW
		uint32 reserved0 : 29;
	} bitFields;
} RegB01RxPpRxLoggerCfg_u;

/*REG_B01_RX_PP_RX_LOGGER_BUSY 0xDC */
typedef union
{
	uint32 val;
	struct
	{
		uint32 rxPpLoggerBusy : 1; //no description, reset value: 0x0, access type: RO
		uint32 reserved0 : 31;
	} bitFields;
} RegB01RxPpRxLoggerBusy_u;

/*REG_B01_RX_PP_SW_REKEY_EN 0xE0 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 rekeyEn : 1; //ReKey feature enable, reset value: 0x0, access type: RW
		uint32 keyIdCheckEn : 1; //Enable KEY_ID check. When enabled, every incoming MPDU is checked for correct key, reset value: 0x0, access type: RW
		uint32 reserved0 : 30;
	} bitFields;
} RegB01RxPpSwRekeyEn_u;

/*REG_B01_RX_PP_SW_REKEY_INST_LSB 0xE4 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 rekeySta : 8; //STA/VAP ID parameter for Rekey command. When rekey_vap_access is set, this field is interpreted as VAP ID. Otherwise, it is STA_ID parameter., reset value: 0x0, access type: RW
		uint32 rekeyVapAccess : 1; //Rekey command parameter. Designates whether the command is VAP access command  (MC) or STA command, reset value: 0x0, access type: RW
		uint32 rekeyDataUpdateOnly : 1; //Rekey command parameter. When set, the Rekey commnad shall only update the contents of the STA bitmap RAM (rekey_pn, key, mgmt_tid_en, old_key), without waiting for Rekey HIT (i.e. rekey_set shall not be set), reset value: 0x0, access type: RW
		uint32 reserved0 : 2;
		uint32 rekeyKey : 2; //KEY_ID parameter for the Rekey command, reset value: 0x0, access type: RW
		uint32 rekeyMgmtTidEn : 1; //Rekey command parameter. Designates whether the command includes mgmt_tid (TID 8). In case rekey_vap_access is set, this field is don't  care, reset value: 0x0, access type: RW
		uint32 rekeyDone : 1; //Done indication of ReKey sequence activation., reset value: 0x0, access type: RO
		uint32 rekeyPn015 : 16; //LSB ReKey PN parameter for the Rekey command, reset value: 0x0, access type: RW
	} bitFields;
} RegB01RxPpSwRekeyInstLsb_u;

/*REG_B01_RX_PP_SW_REKEY_INST_MSB 0xE8 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 rekeyPn1647 : 32; //MSB ReKey PN parameter for the Rekey command, reset value: 0x0, access type: RW
	} bitFields;
} RegB01RxPpSwRekeyInstMsb_u;

/*REG_B01_RX_PP_FRAG_DIS_LIB_ERR_LIST 0xEC */
typedef union
{
	uint32 val;
	struct
	{
		uint32 fragDisLibErrList : 1; //When fragment is disabled for the STA-TID it is dropped to: , 0x0: Liberator , 0x1: Error list, reset value: 0x0, access type: RW
		uint32 reserved0 : 31;
	} bitFields;
} RegB01RxPpFragDisLibErrList_u;

/*REG_B01_RX_PP_SM_STATUS_PART1 0xF0 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 clearMpduSm : 6; //no description, reset value: 0x0, access type: RO
		uint32 oooDigMpduSm : 5; //no description, reset value: 0x0, access type: RO
		uint32 ssnClearMpduClearSm : 5; //no description, reset value: 0x0, access type: RO
		uint32 impMpduClearSm : 3; //no description, reset value: 0x0, access type: RO
		uint32 noBaaClearSm : 5; //no description, reset value: 0x0, access type: RO
		uint32 flushSm : 4; //no description, reset value: 0x0, access type: RO
		uint32 rekeyHitSm : 4; //no description, reset value: 0x0, access type: RO
	} bitFields;
} RegB01RxPpSmStatusPart1_u;

/*REG_B01_RX_PP_SM_STATUS_PART2 0xF4 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 statusUpdateSm : 2; //no description, reset value: 0x0, access type: RO
		uint32 reserved0 : 2;
		uint32 setRekeySm : 3; //no description, reset value: 0x0, access type: RO
		uint32 reserved1 : 1;
		uint32 fragEnUpdateSm : 2; //no description, reset value: 0x0, access type: RO
		uint32 reserved2 : 2;
		uint32 mainMpduSm : 5; //no description, reset value: 0x0, access type: RO
		uint32 reserved3 : 3;
		uint32 snUpdateSm : 4; //no description, reset value: 0x0, access type: RO
		uint32 loggerSm : 3; //no description, reset value: 0x0, access type: RO
		uint32 reserved4 : 1;
		uint32 windowSizeSm : 3; //no description, reset value: 0x0, access type: RO
		uint32 shramFifoSm : 1; //no description, reset value: 0x0, access type: RO
	} bitFields;
} RegB01RxPpSmStatusPart2_u;

/*REG_B01_RX_PP_UC_MGMT_TID_CFG 0xF8 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 ucMgmtTidCfg : 32; //Indication which RD Type is diverted to queue 8 (Management)., reset value: 0x7FF9FFF6, access type: RW
	} bitFields;
} RegB01RxPpUcMgmtTidCfg_u;

/*REG_B01_RX_PP_MC_CFG 0xFC */
typedef union
{
	uint32 val;
	struct
	{
		uint32 mcCfg : 32; //Indication which RD Type is defined as MC., reset value: 0x10104, access type: RW
	} bitFields;
} RegB01RxPpMcCfg_u;

/*REG_B01_RX_PP_RX_PP_INT_ERROR_STATUS 0x100 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 shramSynFifoOverflowStatus : 1; //SHRAM SYN FIFO overflow (push while full) event, reset value: 0x0, access type: RO
		uint32 shramFifoOverflow : 1; //SHRAM FIFO dropped entries event, reset value: 0x0, access type: RO
		uint32 shramFifoDecrementLessThanZero : 1; //SHRAM FIFO decrement less than zero event. Number of entries of SHRAM FIFO  has been decremented to less than zero, reset value: 0x0, access type: RO
		uint32 reserved0 : 29;
	} bitFields;
} RegB01RxPpRxPpIntErrorStatus_u;

/*REG_B01_RX_PP_RX_PP_INT_ERROR_EN 0x104 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 shramSynFifoOverflowEn : 1; //SHRAM SYN FIFO overflow (push while full) interrupt enable, reset value: 0x1, access type: RW
		uint32 shramFifoFullDropCtrEn : 1; //SHRAM FIFO dropped entries interrupt enable, reset value: 0x1, access type: RW
		uint32 shramFifoDecLessThanZeroEn : 1; //SHRAM FIFO decrement less than zero interrupt enable, reset value: 0x1, access type: RW
		uint32 reserved0 : 29;
	} bitFields;
} RegB01RxPpRxPpIntErrorEn_u;

/*REG_B01_RX_PP_RX_PP_INT_ERROR_CLEAR 0x108 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 shramSynFifoClearOverflowStrb : 1; //SHRAM SYN FIFO overflow (push while full) interrupt clear, reset value: 0x0, access type: WO
		uint32 shramFifoClearFullDropCtrStrb : 1; //SHRAM FIFO dropped entries interrupt clear. Writing '1' to this field shall also clear the value of the SHRAM FIFO drop counter, reset value: 0x0, access type: WO
		uint32 shramFifoClearDecLessThanZeroStrb : 1; //SHRAM FIFO decrement less than zero interrupt clear, reset value: 0x0, access type: WO
		uint32 reserved0 : 29;
	} bitFields;
} RegB01RxPpRxPpIntErrorClear_u;

/*REG_B01_RX_PP_RX_PP_CONTROL_BITS 0x10C */
typedef union
{
	uint32 val;
	struct
	{
		uint32 trafficIndicatorEn : 1; //When this bit is set, traffic indication is enabled. Otherwise, it is disabled, reset value: 0x1, access type: RW
		uint32 rxPpGadfMldEnable : 1; //When this bit is set, GADF Duplicate Detection in MLD feature is enabled. When this bit is inactive, RX Dup Detect module is not accessed, reset value: 0x1, access type: RW
		uint32 reserved0 : 30;
	} bitFields;
} RegB01RxPpRxPpControlBits_u;

/*REG_B01_RX_PP_RXDD_SW_UPDATE_LAST_SN 0x110 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 swUpdateLastSn : 12; //Last SN value to write to Rx-Dup Detect DB, reset value: 0x0, access type: RW
		uint32 reserved0 : 20;
	} bitFields;
} RegB01RxPpRxddSwUpdateLastSn_u;

/*REG_B01_RX_PP_RXDD_SW_UPDATE_DUP_ENABLE 0x114 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 swUpdateDupEnable : 1; //Dup Enable value to write to Rx-Dup Detect DB, reset value: 0x0, access type: RW
		uint32 reserved0 : 31;
	} bitFields;
} RegB01RxPpRxddSwUpdateDupEnable_u;

/*REG_B01_RX_PP_RXDD_SW_UPDATE_SN_VALID 0x118 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 swUpdateSnValid : 1; //SN Valid value to write to Rx-Dup Detect DB, reset value: 0x0, access type: RW
		uint32 reserved0 : 31;
	} bitFields;
} RegB01RxPpRxddSwUpdateSnValid_u;

/*REG_B01_RX_PP_RXDD_SW_RD_DUP_DB 0x11C */
typedef union
{
	uint32 val;
	struct
	{
		uint32 swRdLastSn : 12; //Current Last SN value in the Rx-Dup Detect DB, reset value: 0x0, access type: RO
		uint32 swRdSnValid : 1; //Current SN Valid value in the Rx-Dup Detect DB, reset value: 0x0, access type: RO
		uint32 swRdDupEnable : 1; //Current Dup Enable value in the Rx-Dup Detect DB, reset value: 0x0, access type: RO
		uint32 reserved0 : 18;
	} bitFields;
} RegB01RxPpRxddSwRdDupDb_u;

/*REG_B01_RX_PP_RXDD_SN_0_INFO_DBG 0x120 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 queriedSn0 : 12; //SN for which a query was generated, reset value: 0x0, access type: RO
		uint32 lastSn0 : 12; //Last SN within the DB at the time of the query, reset value: 0x0, access type: RO
		uint32 dropResult0 : 1; //Drop result of the query, reset value: 0x0, access type: RO
		uint32 rxPpId0 : 1; //designates the RX_PP which made the query.  0 - RX_PP01; 1 - RX_PP2, reset value: 0x0, access type: RO
		uint32 ptrVal0 : 4; //Rolling Write Pointer, reset value: 0x0, access type: RO
		uint32 valid0 : 1; //designates the validity of this entry, reset value: 0x0, access type: RO
		uint32 reserved0 : 1;
	} bitFields;
} RegB01RxPpRxddSn0InfoDbg_u;

/*REG_B01_RX_PP_RXDD_SN_1_INFO_DBG 0x124 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 queriedSn1 : 12; //SN for which a query was generated, reset value: 0x0, access type: RO
		uint32 lastSn1 : 12; //Last SN within the DB at the time of the query, reset value: 0x0, access type: RO
		uint32 dropResult1 : 1; //Drop result of the query, reset value: 0x0, access type: RO
		uint32 rxPpId1 : 1; //designates the RX_PP which made the query.  0 - RX_PP01; 1 - RX_PP2, reset value: 0x0, access type: RO
		uint32 ptrVal1 : 4; //Rolling Write Pointer, reset value: 0x0, access type: RO
		uint32 valid1 : 1; //designates the validity of this entry, reset value: 0x0, access type: RO
		uint32 reserved0 : 1;
	} bitFields;
} RegB01RxPpRxddSn1InfoDbg_u;

/*REG_B01_RX_PP_RXDD_SN_2_INFO_DBG 0x128 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 queriedSn2 : 12; //SN for which a query was generated, reset value: 0x0, access type: RO
		uint32 lastSn2 : 12; //Last SN within the DB at the time of the query, reset value: 0x0, access type: RO
		uint32 dropResult2 : 1; //Drop result of the query, reset value: 0x0, access type: RO
		uint32 rxPpId2 : 1; //designates the RX_PP which made the query.  0 - RX_PP01; 1 - RX_PP2, reset value: 0x0, access type: RO
		uint32 ptrVal2 : 4; //Rolling Write Pointer, reset value: 0x0, access type: RO
		uint32 valid2 : 1; //designates the validity of this entry, reset value: 0x0, access type: RO
		uint32 reserved0 : 1;
	} bitFields;
} RegB01RxPpRxddSn2InfoDbg_u;

/*REG_B01_RX_PP_RXDD_SN_3_INFO_DBG 0x12C */
typedef union
{
	uint32 val;
	struct
	{
		uint32 queriedSn3 : 12; //SN for which a query was generated, reset value: 0x0, access type: RO
		uint32 lastSn3 : 12; //Last SN within the DB at the time of the query, reset value: 0x0, access type: RO
		uint32 dropResult3 : 1; //Drop result of the query, reset value: 0x0, access type: RO
		uint32 rxPpId3 : 1; //designates the RX_PP which made the query.  0 - RX_PP01; 1 - RX_PP2, reset value: 0x0, access type: RO
		uint32 ptrVal3 : 4; //Rolling Write Pointer, reset value: 0x0, access type: RO
		uint32 valid3 : 1; //designates the validity of this entry, reset value: 0x0, access type: RO
		uint32 reserved0 : 1;
	} bitFields;
} RegB01RxPpRxddSn3InfoDbg_u;

/*REG_B01_RX_PP_RXDD_SN_4_INFO_DBG 0x130 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 queriedSn4 : 12; //SN for which a query was generated, reset value: 0x0, access type: RO
		uint32 lastSn4 : 12; //Last SN within the DB at the time of the query, reset value: 0x0, access type: RO
		uint32 dropResult4 : 1; //Drop result of the query, reset value: 0x0, access type: RO
		uint32 rxPpId4 : 1; //designates the RX_PP which made the query.  0 - RX_PP01; 1 - RX_PP2, reset value: 0x0, access type: RO
		uint32 ptrVal4 : 4; //Rolling Write Pointer, reset value: 0x0, access type: RO
		uint32 valid4 : 1; //designates the validity of this entry, reset value: 0x0, access type: RO
		uint32 reserved0 : 1;
	} bitFields;
} RegB01RxPpRxddSn4InfoDbg_u;

/*REG_B01_RX_PP_RXDD_SN_5_INFO_DBG 0x134 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 queriedSn5 : 12; //SN for which a query was generated, reset value: 0x0, access type: RO
		uint32 lastSn5 : 12; //Last SN within the DB at the time of the query, reset value: 0x0, access type: RO
		uint32 dropResult5 : 1; //Drop result of the query, reset value: 0x0, access type: RO
		uint32 rxPpId5 : 1; //designates the RX_PP which made the query.  0 - RX_PP01; 1 - RX_PP2, reset value: 0x0, access type: RO
		uint32 ptrVal5 : 4; //Rolling Write Pointer, reset value: 0x0, access type: RO
		uint32 valid5 : 1; //designates the validity of this entry, reset value: 0x0, access type: RO
		uint32 reserved0 : 1;
	} bitFields;
} RegB01RxPpRxddSn5InfoDbg_u;

/*REG_B01_RX_PP_RXDD_SN_6_INFO_DBG 0x138 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 queriedSn6 : 12; //SN for which a query was generated, reset value: 0x0, access type: RO
		uint32 lastSn6 : 12; //Last SN within the DB at the time of the query, reset value: 0x0, access type: RO
		uint32 dropResult6 : 1; //Drop result of the query, reset value: 0x0, access type: RO
		uint32 rxPpId6 : 1; //designates the RX_PP which made the query.  0 - RX_PP01; 1 - RX_PP2, reset value: 0x0, access type: RO
		uint32 ptrVal6 : 4; //Rolling Write Pointer, reset value: 0x0, access type: RO
		uint32 valid6 : 1; //designates the validity of this entry, reset value: 0x0, access type: RO
		uint32 reserved0 : 1;
	} bitFields;
} RegB01RxPpRxddSn6InfoDbg_u;

/*REG_B01_RX_PP_RXDD_SN_7_INFO_DBG 0x13C */
typedef union
{
	uint32 val;
	struct
	{
		uint32 queriedSn7 : 12; //SN for which a query was generated, reset value: 0x0, access type: RO
		uint32 lastSn7 : 12; //Last SN within the DB at the time of the query, reset value: 0x0, access type: RO
		uint32 dropResult7 : 1; //Drop result of the query, reset value: 0x0, access type: RO
		uint32 rxPpId7 : 1; //designates the RX_PP which made the query.  0 - RX_PP01; 1 - RX_PP2, reset value: 0x0, access type: RO
		uint32 ptrVal7 : 4; //Rolling Write Pointer, reset value: 0x0, access type: RO
		uint32 valid7 : 1; //designates the validity of this entry, reset value: 0x0, access type: RO
		uint32 reserved0 : 1;
	} bitFields;
} RegB01RxPpRxddSn7InfoDbg_u;

/*REG_B01_RX_PP_MC_DATA_CFG 0x140 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 mcDataCfg : 32; //Indication which RD Type is defined as MC Data. Used only for Duplicate detection in case of MLD, reset value: 0x4, access type: RW
	} bitFields;
} RegB01RxPpMcDataCfg_u;



#endif // _B01_RX_PP_REGS_H_
