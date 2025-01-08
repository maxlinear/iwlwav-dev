
/***********************************************************************************
File:				RxMsduParserRegs.h
Module:				rxMsduParser
SOC Revision:		latest
Generated at:       2024-06-26 12:55:21
Purpose:
Description:		This File was auto generated using SOC Online

************************************************************************************/
#ifndef _RX_MSDU_PARSER_REGS_H_
#define _RX_MSDU_PARSER_REGS_H_

/*---------------------------------------------------------------------------------
/						Registers Addresses													 
/----------------------------------------------------------------------------------*/
#include "HwMemoryMap.h"

#define RX_MSDU_PARSER_BASE_ADDRESS                       MEMORY_MAP_UNIT_65_BASE_ADDRESS
#define	REG_RX_MSDU_PARSER_RX_MSDU_PARSER_EN                   (RX_MSDU_PARSER_BASE_ADDRESS + 0x0)
#define	REG_RX_MSDU_PARSER_RD_TYPE_CONV_EN                     (RX_MSDU_PARSER_BASE_ADDRESS + 0x4)
#define	REG_RX_MSDU_PARSER_WPA_PT_MODE_EN                      (RX_MSDU_PARSER_BASE_ADDRESS + 0x8)
#define	REG_RX_MSDU_PARSER_RX_MSDU_PARSER_CFG                  (RX_MSDU_PARSER_BASE_ADDRESS + 0xC)
#define	REG_RX_MSDU_PARSER_MSDU_DESC_FIFO_CFG                  (RX_MSDU_PARSER_BASE_ADDRESS + 0x10)
#define	REG_RX_MSDU_PARSER_MSDU_DESC_FIFO_NUM_ENTRIES_COUNT    (RX_MSDU_PARSER_BASE_ADDRESS + 0x14)
#define	REG_RX_MSDU_PARSER_MSDU_DESC_FIFO_RD_ENTRIES_NUM       (RX_MSDU_PARSER_BASE_ADDRESS + 0x18)
#define	REG_RX_MSDU_PARSER_MSDU_DESC_FIFO_DEBUG                (RX_MSDU_PARSER_BASE_ADDRESS + 0x1C)
#define	REG_RX_MSDU_PARSER_MSDU_DESC_FIFO_STUCK                (RX_MSDU_PARSER_BASE_ADDRESS + 0x20)
#define	REG_RX_MSDU_PARSER_NO_MATCH_CONV_TYPE                  (RX_MSDU_PARSER_BASE_ADDRESS + 0x24)
#define	REG_RX_MSDU_PARSER_CONF_LLC                            (RX_MSDU_PARSER_BASE_ADDRESS + 0x28)
#define	REG_RX_MSDU_PARSER_CONF_OUI                            (RX_MSDU_PARSER_BASE_ADDRESS + 0x2C)
#define	REG_RX_MSDU_PARSER_CONF_TYPE                           (RX_MSDU_PARSER_BASE_ADDRESS + 0x30)
#define	REG_RX_MSDU_PARSER_CONF_CONV_TYPE                      (RX_MSDU_PARSER_BASE_ADDRESS + 0x34)
#define	REG_RX_MSDU_PARSER_MSDU_PARSER_STATUS                  (RX_MSDU_PARSER_BASE_ADDRESS + 0x38)
#define	REG_RX_MSDU_PARSER_RX_MSDU_PARSER_LOGGER_CFG           (RX_MSDU_PARSER_BASE_ADDRESS + 0x3C)
/*---------------------------------------------------------------------------------
/						Data Type Definition										
/----------------------------------------------------------------------------------*/
/*REG_RX_MSDU_PARSER_RX_MSDU_PARSER_EN 0x0 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 rxMsduParserEn : 1; //Enables/Disables the module: , 0x0 - Block is disabled, no MPDU descriptor will be accessed. , 0x1 - Block is enabled, reset value: 0x0, access type: RW
		uint32 reserved0 : 7;
		uint32 rxMsduConvEn : 1; //Conversion enable: , 0x0 - No conversion will be done, only security check. , 0x1 - Conversion will be done, reset value: 0x0, access type: RW
		uint32 reserved1 : 7;
		uint32 lastMsduFullPaddEn : 1; //'1' = do not produce min-length err when the last MSDU is padded with alignment to 4 (1..3 extra bytes), reset value: 0x0, access type: RW
		uint32 lastMsduPartPaddEn : 1; //'1' = do not produce min-length err when the last MSDU is padded without alignment to 4 (1..3 extra bytes), reset value: 0x0, access type: RW
		uint32 lastMsduGarbagePaddEn : 1; //'1' = do not produce min-length err when the last MSDU is padded with 1..22 extra bytes., reset value: 0x0, access type: RW
		uint32 reserved2 : 13;
	} bitFields;
} RegRxMsduParserRxMsduParserEn_u;

/*REG_RX_MSDU_PARSER_RD_TYPE_CONV_EN 0x4 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 rdTypeConvEn : 32; //no description, reset value: 0x0, access type: RW
	} bitFields;
} RegRxMsduParserRdTypeConvEn_u;

/*REG_RX_MSDU_PARSER_WPA_PT_MODE_EN 0x8 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 wpaPtRdTypeIdx : 5; //no description, reset value: 0x0, access type: RW
		uint32 reserved0 : 3;
		uint32 wpaPtEn : 1; //no description, reset value: 0x0, access type: RW
		uint32 reserved1 : 23;
	} bitFields;
} RegRxMsduParserWpaPtModeEn_u;

/*REG_RX_MSDU_PARSER_RX_MSDU_PARSER_CFG 0xC */
typedef union
{
	uint32 val;
	struct
	{
		uint32 maxFrameLength : 14; //no description, reset value: 0x2000, access type: RW
		uint32 reserved0 : 2;
		uint32 flowContByteCount : 3; //no description, reset value: 0x0, access type: RW
		uint32 reserved1 : 5;
		uint32 amsduMsduMinLength : 5; //Minimum length check of the MSDU inside AMSDU length without the header. , If configed to '0' the check will always pass., reset value: 0x8, access type: RW
		uint32 reserved2 : 3;
	} bitFields;
} RegRxMsduParserRxMsduParserCfg_u;

/*REG_RX_MSDU_PARSER_MSDU_DESC_FIFO_CFG 0x10 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 msduDescFifoDepthMinusOne : 10; //Depth of the FIFO minus one (in entries not words), reset value: 0x7F, access type: RW
		uint32 reserved0 : 22;
	} bitFields;
} RegRxMsduParserMsduDescFifoCfg_u;

/*REG_RX_MSDU_PARSER_MSDU_DESC_FIFO_NUM_ENTRIES_COUNT 0x14 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 msduDescFifoNumEntriesCount : 11; //Number of entries available for read in the FIFO, reset value: 0x0, access type: RO
		uint32 reserved0 : 21;
	} bitFields;
} RegRxMsduParserMsduDescFifoNumEntriesCount_u;

/*REG_RX_MSDU_PARSER_MSDU_DESC_FIFO_RD_ENTRIES_NUM 0x18 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 msduDescFifoRdEntriesNum : 11; //Numver of entries to decrement., reset value: 0x0, access type: RW
		uint32 reserved0 : 21;
	} bitFields;
} RegRxMsduParserMsduDescFifoRdEntriesNum_u;

/*REG_RX_MSDU_PARSER_MSDU_DESC_FIFO_DEBUG 0x1C */
typedef union
{
	uint32 val;
	struct
	{
		uint32 msduDescFifoWrPtr : 16; //no description, reset value: 0x0, access type: RO
		uint32 msduDescFifoNotEmpty : 1; //no description, reset value: 0x0, access type: RO
		uint32 msduDescFifoClearStrb : 1; //no description, reset value: 0x0, access type: WO
		uint32 msduDescFifoDecrementLessThanZero : 1; //no description, reset value: 0x0, access type: RO
		uint32 msduDescFifoClearDecLessThanZeroStrb : 1; //no description, reset value: 0x0, access type: WO
		uint32 reserved0 : 12;
	} bitFields;
} RegRxMsduParserMsduDescFifoDebug_u;

/*REG_RX_MSDU_PARSER_MSDU_DESC_FIFO_STUCK 0x20 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 msduDescFifoFullCountLimit : 30; //Number of cycles that the FIFO needs to be full in order for stuck indication to be asserted, reset value: 0x1000, access type: RW
		uint32 msduDescStuck : 1; //MSDU descriptor IF stuck indication - Sticky., reset value: 0x0, access type: RO
		uint32 msduDescStuckClr : 1; //MSDU descriptor IF stuck indication clear bit, reset value: 0x0, access type: WO
	} bitFields;
} RegRxMsduParserMsduDescFifoStuck_u;

/*REG_RX_MSDU_PARSER_NO_MATCH_CONV_TYPE 0x24 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 noMatchConvType : 2; //This fields describes how the converter behaves when no match is found for the frame's header: , 0x0 - No conversion , 0x1 - LLC/SNAP conversion, EType 10 , 0x2 - Eth II eapol conversion, EType 11 , 0x3 - Eth II conversion, EType 00, reset value: 0x0, access type: RW
		uint32 reserved0 : 30;
	} bitFields;
} RegRxMsduParserNoMatchConvType_u;

/*REG_RX_MSDU_PARSER_CONF_LLC 0x28 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 confLlc : 24; //Comparator for LLC field in the frame., reset value: 0x0, access type: RW
		uint32 reserved0 : 4;
		uint32 confLlcMask : 3; //Mask of LLC as comparator., reset value: 0x0, access type: RW
		uint32 reserved1 : 1;
	} bitFields;
} RegRxMsduParserConfLlc_u;

/*REG_RX_MSDU_PARSER_CONF_OUI 0x2C */
typedef union
{
	uint32 val;
	struct
	{
		uint32 confOui : 24; //Comparator for SNAP OUI field in the frame., reset value: 0x0, access type: RW
		uint32 reserved0 : 4;
		uint32 confOuiMask : 3; //Mask of SNAP OUI as comparator., reset value: 0x0, access type: RW
		uint32 reserved1 : 1;
	} bitFields;
} RegRxMsduParserConfOui_u;

/*REG_RX_MSDU_PARSER_CONF_TYPE 0x30 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 confType : 16; //Comparator for SNAP TYPE field in the frame., reset value: 0x0, access type: RW
		uint32 reserved0 : 12;
		uint32 confTypeMask : 2; //Mask of SNAP TYPE as comparator., reset value: 0x0, access type: RW
		uint32 reserved1 : 2;
	} bitFields;
} RegRxMsduParserConfType_u;

/*REG_RX_MSDU_PARSER_CONF_CONV_TYPE 0x34 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 confConvEn : 1; //no description, reset value: 0x0, access type: RW
		uint32 reserved0 : 7;
		uint32 confConvType : 2; //Convertion type for configurable line: , 0x0 - No conversion , 0x1 - LLC/SNAP conversion, EType 10 , 0x2 - Eth II eapol conversion, EType 11 , 0x3 - Eth II conversion, EType 00 , , reset value: 0x0, access type: RW
		uint32 reserved1 : 22;
	} bitFields;
} RegRxMsduParserConfConvType_u;

/*REG_RX_MSDU_PARSER_MSDU_PARSER_STATUS 0x38 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 secMonSm : 3; //no description, reset value: 0x0, access type: RO
		uint32 reserved0 : 1;
		uint32 headConvSm : 4; //no description, reset value: 0x0, access type: RO
		uint32 convExeSm : 2; //no description, reset value: 0x0, access type: RO
		uint32 reserved1 : 2;
		uint32 msduDescSm : 2; //no description, reset value: 0x0, access type: RO
		uint32 reserved2 : 2;
		uint32 rxMsduParserLoggerSm : 3; //no description, reset value: 0x0, access type: RO
		uint32 reserved3 : 13;
	} bitFields;
} RegRxMsduParserMsduParserStatus_u;

/*REG_RX_MSDU_PARSER_RX_MSDU_PARSER_LOGGER_CFG 0x3C */
typedef union
{
	uint32 val;
	struct
	{
		uint32 rxMsduParserLoggerEn : 1; //no description, reset value: 0x0, access type: RW
		uint32 reserved0 : 3;
		uint32 rxMsduParserLoggerPriority : 2; //no description, reset value: 0x0, access type: RW
		uint32 reserved1 : 2;
		uint32 rxMsduParserMpduMsduSel : 1; //Logger can either be of incoming MPDU or outgoing MSDU: , 0x0: MSDU logger , 0x1: MPDU logger ,  , , reset value: 0x0, access type: RW
		uint32 reserved2 : 23;
	} bitFields;
} RegRxMsduParserRxMsduParserLoggerCfg_u;

//========================================
/* REG_RX_MSDU_PARSER_RX_MSDU_PARSER_EN 0x0 */
#define B0_RX_MSDU_PARSER_RX_MSDU_PARSER_EN_FIELD_RX_MSDU_PARSER_EN_MASK                                          0x00000001
#define B0_RX_MSDU_PARSER_RX_MSDU_PARSER_EN_FIELD_RX_MSDU_CONV_EN_MASK                                            0x00000100
#define B0_RX_MSDU_PARSER_RX_MSDU_PARSER_EN_FIELD_LAST_MSDU_FULL_PADD_EN_MASK                                     0x00010000
#define B0_RX_MSDU_PARSER_RX_MSDU_PARSER_EN_FIELD_LAST_MSDU_PART_PADD_EN_MASK                                     0x00020000
#define B0_RX_MSDU_PARSER_RX_MSDU_PARSER_EN_FIELD_LAST_MSDU_GARBAGE_PADD_EN_MASK                                  0x00040000
//========================================
/* REG_RX_MSDU_PARSER_RD_TYPE_CONV_EN 0x4 */
#define B0_RX_MSDU_PARSER_RD_TYPE_CONV_EN_FIELD_RD_TYPE_CONV_EN_MASK                                              0xFFFFFFFF
//========================================
/* REG_RX_MSDU_PARSER_WPA_PT_MODE_EN 0x8 */
#define B0_RX_MSDU_PARSER_WPA_PT_MODE_EN_FIELD_WPA_PT_RD_TYPE_IDX_MASK                                            0x0000001F
#define B0_RX_MSDU_PARSER_WPA_PT_MODE_EN_FIELD_WPA_PT_EN_MASK                                                     0x00000100
//========================================
/* REG_RX_MSDU_PARSER_RX_MSDU_PARSER_CFG 0xC */
#define B0_RX_MSDU_PARSER_RX_MSDU_PARSER_CFG_FIELD_MAX_FRAME_LENGTH_MASK                                          0x00003FFF
#define B0_RX_MSDU_PARSER_RX_MSDU_PARSER_CFG_FIELD_FLOW_CONT_BYTE_COUNT_MASK                                      0x00070000
#define B0_RX_MSDU_PARSER_RX_MSDU_PARSER_CFG_FIELD_AMSDU_MSDU_MIN_LENGTH_MASK                                     0x1F000000
//========================================
/* REG_RX_MSDU_PARSER_MSDU_DESC_FIFO_CFG 0x10 */
#define B0_RX_MSDU_PARSER_MSDU_DESC_FIFO_CFG_FIELD_MSDU_DESC_FIFO_DEPTH_MINUS_ONE_MASK                            0x000003FF
//========================================
/* REG_RX_MSDU_PARSER_MSDU_DESC_FIFO_NUM_ENTRIES_COUNT 0x14 */
#define B0_RX_MSDU_PARSER_MSDU_DESC_FIFO_NUM_ENTRIES_COUNT_FIELD_MSDU_DESC_FIFO_NUM_ENTRIES_COUNT_MASK            0x000007FF
//========================================
/* REG_RX_MSDU_PARSER_MSDU_DESC_FIFO_RD_ENTRIES_NUM 0x18 */
#define B0_RX_MSDU_PARSER_MSDU_DESC_FIFO_RD_ENTRIES_NUM_FIELD_MSDU_DESC_FIFO_RD_ENTRIES_NUM_MASK                  0x000007FF
//========================================
/* REG_RX_MSDU_PARSER_MSDU_DESC_FIFO_DEBUG 0x1C */
#define B0_RX_MSDU_PARSER_MSDU_DESC_FIFO_DEBUG_FIELD_MSDU_DESC_FIFO_WR_PTR_MASK                                   0x0000FFFF
#define B0_RX_MSDU_PARSER_MSDU_DESC_FIFO_DEBUG_FIELD_MSDU_DESC_FIFO_NOT_EMPTY_MASK                                0x00010000
#define B0_RX_MSDU_PARSER_MSDU_DESC_FIFO_DEBUG_FIELD_MSDU_DESC_FIFO_CLEAR_STRB_MASK                               0x00020000
#define B0_RX_MSDU_PARSER_MSDU_DESC_FIFO_DEBUG_FIELD_MSDU_DESC_FIFO_DECREMENT_LESS_THAN_ZERO_MASK                 0x00040000
#define B0_RX_MSDU_PARSER_MSDU_DESC_FIFO_DEBUG_FIELD_MSDU_DESC_FIFO_CLEAR_DEC_LESS_THAN_ZERO_STRB_MASK            0x00080000
//========================================
/* REG_RX_MSDU_PARSER_MSDU_DESC_FIFO_STUCK 0x20 */
#define B0_RX_MSDU_PARSER_MSDU_DESC_FIFO_STUCK_FIELD_MSDU_DESC_FIFO_FULL_COUNT_LIMIT_MASK                         0x3FFFFFFF
#define B0_RX_MSDU_PARSER_MSDU_DESC_FIFO_STUCK_FIELD_MSDU_DESC_STUCK_MASK                                         0x40000000
#define B0_RX_MSDU_PARSER_MSDU_DESC_FIFO_STUCK_FIELD_MSDU_DESC_STUCK_CLR_MASK                                     0x80000000
//========================================
/* REG_RX_MSDU_PARSER_NO_MATCH_CONV_TYPE 0x24 */
#define B0_RX_MSDU_PARSER_NO_MATCH_CONV_TYPE_FIELD_NO_MATCH_CONV_TYPE_MASK                                        0x00000003
//========================================
/* REG_RX_MSDU_PARSER_CONF_LLC 0x28 */
#define B0_RX_MSDU_PARSER_CONF_LLC_FIELD_CONF_LLC_MASK                                                            0x00FFFFFF
#define B0_RX_MSDU_PARSER_CONF_LLC_FIELD_CONF_LLC_MASK_MASK                                                       0x70000000
//========================================
/* REG_RX_MSDU_PARSER_CONF_OUI 0x2C */
#define B0_RX_MSDU_PARSER_CONF_OUI_FIELD_CONF_OUI_MASK                                                            0x00FFFFFF
#define B0_RX_MSDU_PARSER_CONF_OUI_FIELD_CONF_OUI_MASK_MASK                                                       0x70000000
//========================================
/* REG_RX_MSDU_PARSER_CONF_TYPE 0x30 */
#define B0_RX_MSDU_PARSER_CONF_TYPE_FIELD_CONF_TYPE_MASK                                                          0x0000FFFF
#define B0_RX_MSDU_PARSER_CONF_TYPE_FIELD_CONF_TYPE_MASK_MASK                                                     0x30000000
//========================================
/* REG_RX_MSDU_PARSER_CONF_CONV_TYPE 0x34 */
#define B0_RX_MSDU_PARSER_CONF_CONV_TYPE_FIELD_CONF_CONV_EN_MASK                                                  0x00000001
#define B0_RX_MSDU_PARSER_CONF_CONV_TYPE_FIELD_CONF_CONV_TYPE_MASK                                                0x00000300
//========================================
/* REG_RX_MSDU_PARSER_MSDU_PARSER_STATUS 0x38 */
#define B0_RX_MSDU_PARSER_MSDU_PARSER_STATUS_FIELD_SEC_MON_SM_MASK                                                0x00000007
#define B0_RX_MSDU_PARSER_MSDU_PARSER_STATUS_FIELD_HEAD_CONV_SM_MASK                                              0x000000F0
#define B0_RX_MSDU_PARSER_MSDU_PARSER_STATUS_FIELD_CONV_EXE_SM_MASK                                               0x00000300
#define B0_RX_MSDU_PARSER_MSDU_PARSER_STATUS_FIELD_MSDU_DESC_SM_MASK                                              0x00003000
#define B0_RX_MSDU_PARSER_MSDU_PARSER_STATUS_FIELD_RX_MSDU_PARSER_LOGGER_SM_MASK                                  0x00070000
//========================================
/* REG_RX_MSDU_PARSER_RX_MSDU_PARSER_LOGGER_CFG 0x3C */
#define B0_RX_MSDU_PARSER_RX_MSDU_PARSER_LOGGER_CFG_FIELD_RX_MSDU_PARSER_LOGGER_EN_MASK                           0x00000001
#define B0_RX_MSDU_PARSER_RX_MSDU_PARSER_LOGGER_CFG_FIELD_RX_MSDU_PARSER_LOGGER_PRIORITY_MASK                     0x00000030
#define B0_RX_MSDU_PARSER_RX_MSDU_PARSER_LOGGER_CFG_FIELD_RX_MSDU_PARSER_MPDU_MSDU_SEL_MASK                       0x00000100


#endif // _RX_MSDU_PARSER_REGS_H_
