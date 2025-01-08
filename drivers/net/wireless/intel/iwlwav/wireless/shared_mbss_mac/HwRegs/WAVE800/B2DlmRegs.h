
/***********************************************************************************
File:				B2DlmRegs.h
Module:				b2Dlm
SOC Revision:		latest
Generated at:       2024-06-26 12:54:48
Purpose:
Description:		This File was auto generated using SOC Online

************************************************************************************/
#ifndef _B2_DLM_REGS_H_
#define _B2_DLM_REGS_H_

/*---------------------------------------------------------------------------------
/						Registers Addresses													 
/----------------------------------------------------------------------------------*/
#include "HwMemoryMap.h"

#define B2_DLM_BASE_ADDRESS                     MEMORY_MAP_UNIT_1117_BASE_ADDRESS
#define	REG_B2_DLM_DLM0_DIS_CHECK_EN         (B2_DLM_BASE_ADDRESS + 0xB004)
#define	REG_B2_DLM_DLM0_ERR_STATUS           (B2_DLM_BASE_ADDRESS + 0xB00C)
#define	REG_B2_DLM_DLM0_ERR_STATUS_CLR       (B2_DLM_BASE_ADDRESS + 0xB010)
#define	REG_B2_DLM_DLM0_FLUSH_COUNTER        (B2_DLM_BASE_ADDRESS + 0xB014)
#define	REG_B2_DLM_DLM0_FLUSH_COUNTER_CLR    (B2_DLM_BASE_ADDRESS + 0xB018)
#define	REG_B2_DLM_DLM0_LOGGER_CFG           (B2_DLM_BASE_ADDRESS + 0xB01C)
#define	REG_B2_DLM_DLM1_ERR_STATUS           (B2_DLM_BASE_ADDRESS + 0xB03C)
#define	REG_B2_DLM_DLM1_ERR_STATUS_CLR       (B2_DLM_BASE_ADDRESS + 0xB040)
#define	REG_B2_DLM_DLM1_FLUSH_COUNTER        (B2_DLM_BASE_ADDRESS + 0xB044)
#define	REG_B2_DLM_DLM1_FLUSH_COUNTER_CLR    (B2_DLM_BASE_ADDRESS + 0xB048)
#define	REG_B2_DLM_DLM1_LOGGER_CFG           (B2_DLM_BASE_ADDRESS + 0xB04C)
#define	REG_B2_DLM_DLM2_ERR_STATUS           (B2_DLM_BASE_ADDRESS + 0xB06C)
#define	REG_B2_DLM_DLM2_ERR_STATUS_CLR       (B2_DLM_BASE_ADDRESS + 0xB070)
#define	REG_B2_DLM_DLM2_FLUSH_COUNTER        (B2_DLM_BASE_ADDRESS + 0xB074)
#define	REG_B2_DLM_DLM2_FLUSH_COUNTER_CLR    (B2_DLM_BASE_ADDRESS + 0xB078)
#define	REG_B2_DLM_DLM2_LOGGER_CFG           (B2_DLM_BASE_ADDRESS + 0xB07C)
#define	REG_B2_DLM_DLM3_ERR_STATUS           (B2_DLM_BASE_ADDRESS + 0xB09C)
#define	REG_B2_DLM_DLM3_ERR_STATUS_CLR       (B2_DLM_BASE_ADDRESS + 0xB0A0)
#define	REG_B2_DLM_DLM3_FLUSH_COUNTER        (B2_DLM_BASE_ADDRESS + 0xB0A4)
#define	REG_B2_DLM_DLM3_FLUSH_COUNTER_CLR    (B2_DLM_BASE_ADDRESS + 0xB0A8)
#define	REG_B2_DLM_DLM3_LOGGER_CFG           (B2_DLM_BASE_ADDRESS + 0xB0AC)
#define	REG_B2_DLM_DLM4_ERR_STATUS           (B2_DLM_BASE_ADDRESS + 0xB0CC)
#define	REG_B2_DLM_DLM4_ERR_STATUS_CLR       (B2_DLM_BASE_ADDRESS + 0xB0D0)
#define	REG_B2_DLM_DLM4_FLUSH_COUNTER        (B2_DLM_BASE_ADDRESS + 0xB0D4)
#define	REG_B2_DLM_DLM4_FLUSH_COUNTER_CLR    (B2_DLM_BASE_ADDRESS + 0xB0D8)
#define	REG_B2_DLM_DLM4_LOGGER_CFG           (B2_DLM_BASE_ADDRESS + 0xB0DC)
#define	REG_B2_DLM_DLM5_ERR_STATUS           (B2_DLM_BASE_ADDRESS + 0xB0FC)
#define	REG_B2_DLM_DLM5_ERR_STATUS_CLR       (B2_DLM_BASE_ADDRESS + 0xB100)
#define	REG_B2_DLM_DLM5_FLUSH_COUNTER        (B2_DLM_BASE_ADDRESS + 0xB104)
#define	REG_B2_DLM_DLM5_FLUSH_COUNTER_CLR    (B2_DLM_BASE_ADDRESS + 0xB108)
#define	REG_B2_DLM_DLM5_LOGGER_CFG           (B2_DLM_BASE_ADDRESS + 0xB10C)
#define	REG_B2_DLM_DLM6_ERR_STATUS           (B2_DLM_BASE_ADDRESS + 0xB12C)
#define	REG_B2_DLM_DLM6_ERR_STATUS_CLR       (B2_DLM_BASE_ADDRESS + 0xB130)
#define	REG_B2_DLM_DLM6_FLUSH_COUNTER        (B2_DLM_BASE_ADDRESS + 0xB134)
#define	REG_B2_DLM_DLM6_FLUSH_COUNTER_CLR    (B2_DLM_BASE_ADDRESS + 0xB138)
#define	REG_B2_DLM_DLM6_LOGGER_CFG           (B2_DLM_BASE_ADDRESS + 0xB13C)
#define	REG_B2_DLM_DLM7_ERR_STATUS           (B2_DLM_BASE_ADDRESS + 0xB15C)
#define	REG_B2_DLM_DLM7_ERR_STATUS_CLR       (B2_DLM_BASE_ADDRESS + 0xB160)
#define	REG_B2_DLM_DLM7_FLUSH_COUNTER        (B2_DLM_BASE_ADDRESS + 0xB164)
#define	REG_B2_DLM_DLM7_FLUSH_COUNTER_CLR    (B2_DLM_BASE_ADDRESS + 0xB168)
#define	REG_B2_DLM_DLM7_LOGGER_CFG           (B2_DLM_BASE_ADDRESS + 0xB16C)
#define	REG_B2_DLM_DLM8_ERR_STATUS           (B2_DLM_BASE_ADDRESS + 0xB18C)
#define	REG_B2_DLM_DLM8_ERR_STATUS_CLR       (B2_DLM_BASE_ADDRESS + 0xB190)
#define	REG_B2_DLM_DLM8_FLUSH_COUNTER        (B2_DLM_BASE_ADDRESS + 0xB194)
#define	REG_B2_DLM_DLM8_FLUSH_COUNTER_CLR    (B2_DLM_BASE_ADDRESS + 0xB198)
#define	REG_B2_DLM_DLM8_LOGGER_CFG           (B2_DLM_BASE_ADDRESS + 0xB19C)
#define	REG_B2_DLM_LOGGER_MESSAGE_CFG        (B2_DLM_BASE_ADDRESS + 0xB200)
/*---------------------------------------------------------------------------------
/						Data Type Definition										
/----------------------------------------------------------------------------------*/
/*REG_B2_DLM_DLM0_DIS_CHECK_EN 0xB004 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 dlm0DisCheckEn : 8; //DLM Disable check enable, reset value: 0xFF, access type: RW
		uint32 reserved0 : 24;
	} bitFields;
} RegB2DlmDlm0DisCheckEn_u;

/*REG_B2_DLM_DLM0_ERR_STATUS 0xB00C */
typedef union
{
	uint32 val;
	struct
	{
		uint32 dlm0ErrPopDisabled : 1; //Pop of empty list - No PDs, reset value: 0x0, access type: RO
		uint32 reserved0 : 7;
		uint32 dlm0ErrPopDisabledMasterIdx : 6; //no description, reset value: 0x0, access type: RO
		uint32 reserved1 : 2;
		uint32 dlm0NullPushErr : 1; //no description, reset value: 0x0, access type: RO
		uint32 reserved2 : 3;
		uint32 dlm0NullPushErrEn : 1; //no description, reset value: 0x1, access type: RW
		uint32 reserved3 : 3;
		uint32 dlm0NullPushErrMasterIdx : 6; //no description, reset value: 0x0, access type: RO
		uint32 reserved4 : 2;
	} bitFields;
} RegB2DlmDlm0ErrStatus_u;

/*REG_B2_DLM_DLM0_ERR_STATUS_CLR 0xB010 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 dlm0ErrPopDisabledClr : 1; //Clears empty list pop error, reset value: 0x0, access type: WO
		uint32 reserved0 : 3;
		uint32 dlm0NullPushErrClr : 1; //no description, reset value: 0x0, access type: WO
		uint32 reserved1 : 27;
	} bitFields;
} RegB2DlmDlm0ErrStatusClr_u;

/*REG_B2_DLM_DLM0_FLUSH_COUNTER 0xB014 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 dlm0FlushCounter : 16; //Counts number of Flush requests done in the DLM, reset value: 0x0, access type: RO
		uint32 reserved0 : 16;
	} bitFields;
} RegB2DlmDlm0FlushCounter_u;

/*REG_B2_DLM_DLM0_FLUSH_COUNTER_CLR 0xB018 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 dlm0FlushCounterClr : 1; //Clears flush counter, reset value: 0x0, access type: WO
		uint32 reserved0 : 31;
	} bitFields;
} RegB2DlmDlm0FlushCounterClr_u;

/*REG_B2_DLM_DLM0_LOGGER_CFG 0xB01C */
typedef union
{
	uint32 val;
	struct
	{
		uint32 dlm0LoggerPrimary : 8; //no description, reset value: 0x0, access type: RW
		uint32 dlm0LoggerSecondary : 3; //no description, reset value: 0x0, access type: RW
		uint32 dlm0LoggerMgmtTid : 1; //no description, reset value: 0x0, access type: RW
		uint32 dlm0LoggerDpl : 8; //no description, reset value: 0x0, access type: RW
		uint32 reserved0 : 4;
		uint32 dlm0LoggerPriority : 2; //no description, reset value: 0x0, access type: RW
		uint32 reserved1 : 2;
		uint32 dlm0LoggerEn : 1; //no description, reset value: 0x0, access type: RW
		uint32 dlm0LoggerSpecificClient : 1; //no description, reset value: 0x0, access type: RW
		uint32 reserved2 : 1;
		uint32 dlm0LoggerBusy : 1; //no description, reset value: 0x0, access type: RO
	} bitFields;
} RegB2DlmDlm0LoggerCfg_u;

/*REG_B2_DLM_DLM1_ERR_STATUS 0xB03C */
typedef union
{
	uint32 val;
	struct
	{
		uint32 reserved0 : 4;
		uint32 dlm1NullPushErr : 1; //no description, reset value: 0x0, access type: RO
		uint32 reserved1 : 3;
		uint32 dlm1NullPushErrEn : 1; //no description, reset value: 0x1, access type: RW
		uint32 reserved2 : 3;
		uint32 dlm1NullPushErrMasterIdx : 6; //no description, reset value: 0x0, access type: RO
		uint32 reserved3 : 14;
	} bitFields;
} RegB2DlmDlm1ErrStatus_u;

/*REG_B2_DLM_DLM1_ERR_STATUS_CLR 0xB040 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 reserved0 : 4;
		uint32 dlm1NullPushErrClr : 1; //no description, reset value: 0x0, access type: WO
		uint32 reserved1 : 27;
	} bitFields;
} RegB2DlmDlm1ErrStatusClr_u;

/*REG_B2_DLM_DLM1_FLUSH_COUNTER 0xB044 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 dlm1FlushCounter : 16; //Counts number of Flush requests done in the DLM, reset value: 0x0, access type: RO
		uint32 reserved0 : 16;
	} bitFields;
} RegB2DlmDlm1FlushCounter_u;

/*REG_B2_DLM_DLM1_FLUSH_COUNTER_CLR 0xB048 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 dlm1FlushCounterClr : 1; //Clears flush counter, reset value: 0x0, access type: WO
		uint32 reserved0 : 31;
	} bitFields;
} RegB2DlmDlm1FlushCounterClr_u;

/*REG_B2_DLM_DLM1_LOGGER_CFG 0xB04C */
typedef union
{
	uint32 val;
	struct
	{
		uint32 reserved0 : 12;
		uint32 dlm1LoggerDpl : 8; //no description, reset value: 0x0, access type: RW
		uint32 reserved1 : 4;
		uint32 dlm1LoggerPriority : 2; //no description, reset value: 0x0, access type: RW
		uint32 reserved2 : 2;
		uint32 dlm1LoggerEn : 1; //no description, reset value: 0x0, access type: RW
		uint32 dlm1LoggerSpecificClient : 1; //no description, reset value: 0x0, access type: RW
		uint32 reserved3 : 1;
		uint32 dlm1LoggerBusy : 1; //no description, reset value: 0x0, access type: RO
	} bitFields;
} RegB2DlmDlm1LoggerCfg_u;

/*REG_B2_DLM_DLM2_ERR_STATUS 0xB06C */
typedef union
{
	uint32 val;
	struct
	{
		uint32 reserved0 : 4;
		uint32 dlm2NullPushErr : 1; //no description, reset value: 0x0, access type: RO
		uint32 reserved1 : 3;
		uint32 dlm2NullPushErrEn : 1; //no description, reset value: 0x1, access type: RW
		uint32 reserved2 : 3;
		uint32 dlm2NullPushErrMasterIdx : 6; //no description, reset value: 0x0, access type: RO
		uint32 reserved3 : 14;
	} bitFields;
} RegB2DlmDlm2ErrStatus_u;

/*REG_B2_DLM_DLM2_ERR_STATUS_CLR 0xB070 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 reserved0 : 4;
		uint32 dlm2NullPushErrClr : 1; //no description, reset value: 0x0, access type: WO
		uint32 reserved1 : 27;
	} bitFields;
} RegB2DlmDlm2ErrStatusClr_u;

/*REG_B2_DLM_DLM2_FLUSH_COUNTER 0xB074 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 dlm2FlushCounter : 16; //Counts number of Flush requests done in the DLM, reset value: 0x0, access type: RO
		uint32 reserved0 : 16;
	} bitFields;
} RegB2DlmDlm2FlushCounter_u;

/*REG_B2_DLM_DLM2_FLUSH_COUNTER_CLR 0xB078 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 dlm2FlushCounterClr : 1; //Clears flush counter, reset value: 0x0, access type: WO
		uint32 reserved0 : 31;
	} bitFields;
} RegB2DlmDlm2FlushCounterClr_u;

/*REG_B2_DLM_DLM2_LOGGER_CFG 0xB07C */
typedef union
{
	uint32 val;
	struct
	{
		uint32 dlm2LoggerPrimary : 8; //no description, reset value: 0x0, access type: RW
		uint32 dlm2LoggerSecondary : 3; //no description, reset value: 0x0, access type: RW
		uint32 dlm2LoggerMgmtTid : 1; //no description, reset value: 0x0, access type: RW
		uint32 dlm2LoggerDpl : 8; //no description, reset value: 0x0, access type: RW
		uint32 reserved0 : 4;
		uint32 dlm2LoggerPriority : 2; //no description, reset value: 0x0, access type: RW
		uint32 reserved1 : 2;
		uint32 dlm2LoggerEn : 1; //no description, reset value: 0x0, access type: RW
		uint32 dlm2LoggerSpecificClient : 1; //no description, reset value: 0x0, access type: RW
		uint32 reserved2 : 1;
		uint32 dlm2LoggerBusy : 1; //no description, reset value: 0x0, access type: RO
	} bitFields;
} RegB2DlmDlm2LoggerCfg_u;

/*REG_B2_DLM_DLM3_ERR_STATUS 0xB09C */
typedef union
{
	uint32 val;
	struct
	{
		uint32 reserved0 : 4;
		uint32 dlm3NullPushErr : 1; //no description, reset value: 0x0, access type: RO
		uint32 reserved1 : 3;
		uint32 dlm3NullPushErrEn : 1; //no description, reset value: 0x1, access type: RW
		uint32 reserved2 : 3;
		uint32 dlm3NullPushErrMasterIdx : 6; //no description, reset value: 0x0, access type: RO
		uint32 reserved3 : 14;
	} bitFields;
} RegB2DlmDlm3ErrStatus_u;

/*REG_B2_DLM_DLM3_ERR_STATUS_CLR 0xB0A0 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 reserved0 : 4;
		uint32 dlm3NullPushErrClr : 1; //no description, reset value: 0x0, access type: WO
		uint32 reserved1 : 27;
	} bitFields;
} RegB2DlmDlm3ErrStatusClr_u;

/*REG_B2_DLM_DLM3_FLUSH_COUNTER 0xB0A4 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 dlm3FlushCounter : 16; //Counts number of Flush requests done in the DLM, reset value: 0x0, access type: RO
		uint32 reserved0 : 16;
	} bitFields;
} RegB2DlmDlm3FlushCounter_u;

/*REG_B2_DLM_DLM3_FLUSH_COUNTER_CLR 0xB0A8 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 dlm3FlushCounterClr : 1; //Clears flush counter, reset value: 0x0, access type: WO
		uint32 reserved0 : 31;
	} bitFields;
} RegB2DlmDlm3FlushCounterClr_u;

/*REG_B2_DLM_DLM3_LOGGER_CFG 0xB0AC */
typedef union
{
	uint32 val;
	struct
	{
		uint32 reserved0 : 12;
		uint32 dlm3LoggerDpl : 8; //no description, reset value: 0x0, access type: RW
		uint32 reserved1 : 4;
		uint32 dlm3LoggerPriority : 2; //no description, reset value: 0x0, access type: RW
		uint32 reserved2 : 2;
		uint32 dlm3LoggerEn : 1; //no description, reset value: 0x0, access type: RW
		uint32 dlm3LoggerSpecificClient : 1; //no description, reset value: 0x0, access type: RW
		uint32 reserved3 : 1;
		uint32 dlm3LoggerBusy : 1; //no description, reset value: 0x0, access type: RO
	} bitFields;
} RegB2DlmDlm3LoggerCfg_u;

/*REG_B2_DLM_DLM4_ERR_STATUS 0xB0CC */
typedef union
{
	uint32 val;
	struct
	{
		uint32 reserved0 : 4;
		uint32 dlm4NullPushErr : 1; //no description, reset value: 0x0, access type: RO
		uint32 reserved1 : 3;
		uint32 dlm4NullPushErrEn : 1; //no description, reset value: 0x1, access type: RW
		uint32 reserved2 : 3;
		uint32 dlm4NullPushErrMasterIdx : 6; //no description, reset value: 0x0, access type: RO
		uint32 reserved3 : 14;
	} bitFields;
} RegB2DlmDlm4ErrStatus_u;

/*REG_B2_DLM_DLM4_ERR_STATUS_CLR 0xB0D0 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 reserved0 : 4;
		uint32 dlm4NullPushErrClr : 1; //no description, reset value: 0x0, access type: WO
		uint32 reserved1 : 27;
	} bitFields;
} RegB2DlmDlm4ErrStatusClr_u;

/*REG_B2_DLM_DLM4_FLUSH_COUNTER 0xB0D4 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 dlm4FlushCounter : 16; //Counts number of Flush requests done in the DLM, reset value: 0x0, access type: RO
		uint32 reserved0 : 16;
	} bitFields;
} RegB2DlmDlm4FlushCounter_u;

/*REG_B2_DLM_DLM4_FLUSH_COUNTER_CLR 0xB0D8 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 dlm4FlushCounterClr : 1; //Clears flush counter, reset value: 0x0, access type: WO
		uint32 reserved0 : 31;
	} bitFields;
} RegB2DlmDlm4FlushCounterClr_u;

/*REG_B2_DLM_DLM4_LOGGER_CFG 0xB0DC */
typedef union
{
	uint32 val;
	struct
	{
		uint32 reserved0 : 12;
		uint32 dlm4LoggerDpl : 8; //no description, reset value: 0x0, access type: RW
		uint32 reserved1 : 4;
		uint32 dlm4LoggerPriority : 2; //no description, reset value: 0x0, access type: RW
		uint32 reserved2 : 2;
		uint32 dlm4LoggerEn : 1; //no description, reset value: 0x0, access type: RW
		uint32 dlm4LoggerSpecificClient : 1; //no description, reset value: 0x0, access type: RW
		uint32 reserved3 : 1;
		uint32 dlm4LoggerBusy : 1; //no description, reset value: 0x0, access type: RO
	} bitFields;
} RegB2DlmDlm4LoggerCfg_u;

/*REG_B2_DLM_DLM5_ERR_STATUS 0xB0FC */
typedef union
{
	uint32 val;
	struct
	{
		uint32 reserved0 : 4;
		uint32 dlm5NullPushErr : 1; //no description, reset value: 0x0, access type: RO
		uint32 reserved1 : 3;
		uint32 dlm5NullPushErrEn : 1; //no description, reset value: 0x1, access type: RW
		uint32 reserved2 : 3;
		uint32 dlm5NullPushErrMasterIdx : 6; //no description, reset value: 0x0, access type: RO
		uint32 reserved3 : 14;
	} bitFields;
} RegB2DlmDlm5ErrStatus_u;

/*REG_B2_DLM_DLM5_ERR_STATUS_CLR 0xB100 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 reserved0 : 4;
		uint32 dlm5NullPushErrClr : 1; //no description, reset value: 0x0, access type: WO
		uint32 reserved1 : 27;
	} bitFields;
} RegB2DlmDlm5ErrStatusClr_u;

/*REG_B2_DLM_DLM5_FLUSH_COUNTER 0xB104 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 dlm5FlushCounter : 16; //Counts number of Flush requests done in the DLM, reset value: 0x0, access type: RO
		uint32 reserved0 : 16;
	} bitFields;
} RegB2DlmDlm5FlushCounter_u;

/*REG_B2_DLM_DLM5_FLUSH_COUNTER_CLR 0xB108 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 dlm5FlushCounterClr : 1; //Clears flush counter, reset value: 0x0, access type: WO
		uint32 reserved0 : 31;
	} bitFields;
} RegB2DlmDlm5FlushCounterClr_u;

/*REG_B2_DLM_DLM5_LOGGER_CFG 0xB10C */
typedef union
{
	uint32 val;
	struct
	{
		uint32 reserved0 : 12;
		uint32 dlm5LoggerDpl : 8; //no description, reset value: 0x0, access type: RW
		uint32 reserved1 : 4;
		uint32 dlm5LoggerPriority : 2; //no description, reset value: 0x0, access type: RW
		uint32 reserved2 : 2;
		uint32 dlm5LoggerEn : 1; //no description, reset value: 0x0, access type: RW
		uint32 dlm5LoggerSpecificClient : 1; //no description, reset value: 0x0, access type: RW
		uint32 reserved3 : 1;
		uint32 dlm5LoggerBusy : 1; //no description, reset value: 0x0, access type: RO
	} bitFields;
} RegB2DlmDlm5LoggerCfg_u;

/*REG_B2_DLM_DLM6_ERR_STATUS 0xB12C */
typedef union
{
	uint32 val;
	struct
	{
		uint32 reserved0 : 4;
		uint32 dlm6NullPushErr : 1; //no description, reset value: 0x0, access type: RO
		uint32 reserved1 : 3;
		uint32 dlm6NullPushErrEn : 1; //no description, reset value: 0x1, access type: RW
		uint32 reserved2 : 3;
		uint32 dlm6NullPushErrMasterIdx : 6; //no description, reset value: 0x0, access type: RO
		uint32 reserved3 : 14;
	} bitFields;
} RegB2DlmDlm6ErrStatus_u;

/*REG_B2_DLM_DLM6_ERR_STATUS_CLR 0xB130 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 reserved0 : 4;
		uint32 dlm6NullPushErrClr : 1; //no description, reset value: 0x0, access type: WO
		uint32 reserved1 : 27;
	} bitFields;
} RegB2DlmDlm6ErrStatusClr_u;

/*REG_B2_DLM_DLM6_FLUSH_COUNTER 0xB134 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 dlm6FlushCounter : 16; //Counts number of Flush requests done in the DLM, reset value: 0x0, access type: RO
		uint32 reserved0 : 16;
	} bitFields;
} RegB2DlmDlm6FlushCounter_u;

/*REG_B2_DLM_DLM6_FLUSH_COUNTER_CLR 0xB138 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 dlm6FlushCounterClr : 1; //Clears flush counter, reset value: 0x0, access type: WO
		uint32 reserved0 : 31;
	} bitFields;
} RegB2DlmDlm6FlushCounterClr_u;

/*REG_B2_DLM_DLM6_LOGGER_CFG 0xB13C */
typedef union
{
	uint32 val;
	struct
	{
		uint32 reserved0 : 12;
		uint32 dlm6LoggerDpl : 8; //no description, reset value: 0x0, access type: RW
		uint32 reserved1 : 4;
		uint32 dlm6LoggerPriority : 2; //no description, reset value: 0x0, access type: RW
		uint32 reserved2 : 2;
		uint32 dlm6LoggerEn : 1; //no description, reset value: 0x0, access type: RW
		uint32 dlm6LoggerSpecificClient : 1; //no description, reset value: 0x0, access type: RW
		uint32 reserved3 : 1;
		uint32 dlm6LoggerBusy : 1; //no description, reset value: 0x0, access type: RO
	} bitFields;
} RegB2DlmDlm6LoggerCfg_u;

/*REG_B2_DLM_DLM7_ERR_STATUS 0xB15C */
typedef union
{
	uint32 val;
	struct
	{
		uint32 reserved0 : 4;
		uint32 dlm7NullPushErr : 1; //no description, reset value: 0x0, access type: RO
		uint32 reserved1 : 3;
		uint32 dlm7NullPushErrEn : 1; //no description, reset value: 0x1, access type: RW
		uint32 reserved2 : 3;
		uint32 dlm7NullPushErrMasterIdx : 6; //no description, reset value: 0x0, access type: RO
		uint32 reserved3 : 14;
	} bitFields;
} RegB2DlmDlm7ErrStatus_u;

/*REG_B2_DLM_DLM7_ERR_STATUS_CLR 0xB160 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 reserved0 : 4;
		uint32 dlm7NullPushErrClr : 1; //no description, reset value: 0x0, access type: WO
		uint32 reserved1 : 27;
	} bitFields;
} RegB2DlmDlm7ErrStatusClr_u;

/*REG_B2_DLM_DLM7_FLUSH_COUNTER 0xB164 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 dlm7FlushCounter : 16; //Counts number of Flush requests done in the DLM, reset value: 0x0, access type: RO
		uint32 reserved0 : 16;
	} bitFields;
} RegB2DlmDlm7FlushCounter_u;

/*REG_B2_DLM_DLM7_FLUSH_COUNTER_CLR 0xB168 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 dlm7FlushCounterClr : 1; //Clears flush counter, reset value: 0x0, access type: WO
		uint32 reserved0 : 31;
	} bitFields;
} RegB2DlmDlm7FlushCounterClr_u;

/*REG_B2_DLM_DLM7_LOGGER_CFG 0xB16C */
typedef union
{
	uint32 val;
	struct
	{
		uint32 reserved0 : 12;
		uint32 dlm7LoggerDpl : 8; //no description, reset value: 0x0, access type: RW
		uint32 reserved1 : 4;
		uint32 dlm7LoggerPriority : 2; //no description, reset value: 0x0, access type: RW
		uint32 reserved2 : 2;
		uint32 dlm7LoggerEn : 1; //no description, reset value: 0x0, access type: RW
		uint32 dlm7LoggerSpecificClient : 1; //no description, reset value: 0x0, access type: RW
		uint32 reserved3 : 1;
		uint32 dlm7LoggerBusy : 1; //no description, reset value: 0x0, access type: RO
	} bitFields;
} RegB2DlmDlm7LoggerCfg_u;

/*REG_B2_DLM_DLM8_ERR_STATUS 0xB18C */
typedef union
{
	uint32 val;
	struct
	{
		uint32 reserved0 : 4;
		uint32 dlm8NullPushErr : 1; //no description, reset value: 0x0, access type: RO
		uint32 reserved1 : 3;
		uint32 dlm8NullPushErrEn : 1; //no description, reset value: 0x1, access type: RW
		uint32 reserved2 : 3;
		uint32 dlm8NullPushErrMasterIdx : 6; //no description, reset value: 0x0, access type: RO
		uint32 reserved3 : 14;
	} bitFields;
} RegB2DlmDlm8ErrStatus_u;

/*REG_B2_DLM_DLM8_ERR_STATUS_CLR 0xB190 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 reserved0 : 4;
		uint32 dlm8NullPushErrClr : 1; //no description, reset value: 0x0, access type: WO
		uint32 reserved1 : 27;
	} bitFields;
} RegB2DlmDlm8ErrStatusClr_u;

/*REG_B2_DLM_DLM8_FLUSH_COUNTER 0xB194 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 dlm8FlushCounter : 16; //Counts number of Flush requests done in the DLM, reset value: 0x0, access type: RO
		uint32 reserved0 : 16;
	} bitFields;
} RegB2DlmDlm8FlushCounter_u;

/*REG_B2_DLM_DLM8_FLUSH_COUNTER_CLR 0xB198 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 dlm8FlushCounterClr : 1; //Clears flush counter, reset value: 0x0, access type: WO
		uint32 reserved0 : 31;
	} bitFields;
} RegB2DlmDlm8FlushCounterClr_u;

/*REG_B2_DLM_DLM8_LOGGER_CFG 0xB19C */
typedef union
{
	uint32 val;
	struct
	{
		uint32 reserved0 : 12;
		uint32 dlm8LoggerDpl : 8; //no description, reset value: 0x0, access type: RW
		uint32 reserved1 : 4;
		uint32 dlm8LoggerPriority : 2; //no description, reset value: 0x0, access type: RW
		uint32 reserved2 : 2;
		uint32 dlm8LoggerEn : 1; //no description, reset value: 0x0, access type: RW
		uint32 dlm8LoggerSpecificClient : 1; //no description, reset value: 0x0, access type: RW
		uint32 reserved3 : 1;
		uint32 dlm8LoggerBusy : 1; //no description, reset value: 0x0, access type: RO
	} bitFields;
} RegB2DlmDlm8LoggerCfg_u;

/*REG_B2_DLM_LOGGER_MESSAGE_CFG 0xB200 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 loggerMaxMessageCount : 6; //no description, reset value: 0x1E, access type: RW
		uint32 reserved0 : 2;
		uint32 loggerTimeoutCount : 10; //no description, reset value: 0x40, access type: RW
		uint32 reserved1 : 14;
	} bitFields;
} RegB2DlmLoggerMessageCfg_u;

//========================================
/* REG_DLM_DLM0_DIS_CHECK_EN 0xB004 */
#define B2_DLM_DLM0_DIS_CHECK_EN_FIELD_DLM0_DIS_CHECK_EN_MASK                                                     0x000000FF
//========================================
/* REG_DLM_DLM0_ERR_STATUS 0xB00C */
#define B2_DLM_DLM0_ERR_STATUS_FIELD_DLM0_ERR_POP_DISABLED_MASK                                                   0x00000001
#define B2_DLM_DLM0_ERR_STATUS_FIELD_DLM0_ERR_POP_DISABLED_MASTER_IDX_MASK                                        0x00003F00
#define B2_DLM_DLM0_ERR_STATUS_FIELD_DLM0_NULL_PUSH_ERR_MASK                                                      0x00010000
#define B2_DLM_DLM0_ERR_STATUS_FIELD_DLM0_NULL_PUSH_ERR_EN_MASK                                                   0x00100000
#define B2_DLM_DLM0_ERR_STATUS_FIELD_DLM0_NULL_PUSH_ERR_MASTER_IDX_MASK                                           0x3F000000
//========================================
/* REG_DLM_DLM0_ERR_STATUS_CLR 0xB010 */
#define B2_DLM_DLM0_ERR_STATUS_CLR_FIELD_DLM0_ERR_POP_DISABLED_CLR_MASK                                           0x00000001
#define B2_DLM_DLM0_ERR_STATUS_CLR_FIELD_DLM0_NULL_PUSH_ERR_CLR_MASK                                              0x00000010
//========================================
/* REG_DLM_DLM0_FLUSH_COUNTER 0xB014 */
#define B2_DLM_DLM0_FLUSH_COUNTER_FIELD_DLM0_FLUSH_COUNTER_MASK                                                   0x0000FFFF
//========================================
/* REG_DLM_DLM0_FLUSH_COUNTER_CLR 0xB018 */
#define B2_DLM_DLM0_FLUSH_COUNTER_CLR_FIELD_DLM0_FLUSH_COUNTER_CLR_MASK                                           0x00000001
//========================================
/* REG_DLM_DLM0_LOGGER_CFG 0xB01C */
#define B2_DLM_DLM0_LOGGER_CFG_FIELD_DLM0_LOGGER_PRIMARY_MASK                                                     0x000000FF
#define B2_DLM_DLM0_LOGGER_CFG_FIELD_DLM0_LOGGER_SECONDARY_MASK                                                   0x00000700
#define B2_DLM_DLM0_LOGGER_CFG_FIELD_DLM0_LOGGER_MGMT_TID_MASK                                                    0x00000800
#define B2_DLM_DLM0_LOGGER_CFG_FIELD_DLM0_LOGGER_DPL_MASK                                                         0x000FF000
#define B2_DLM_DLM0_LOGGER_CFG_FIELD_DLM0_LOGGER_PRIORITY_MASK                                                    0x03000000
#define B2_DLM_DLM0_LOGGER_CFG_FIELD_DLM0_LOGGER_EN_MASK                                                          0x10000000
#define B2_DLM_DLM0_LOGGER_CFG_FIELD_DLM0_LOGGER_SPECIFIC_CLIENT_MASK                                             0x20000000
#define B2_DLM_DLM0_LOGGER_CFG_FIELD_DLM0_LOGGER_BUSY_MASK                                                        0x80000000
//========================================
/* REG_DLM_DLM1_ERR_STATUS 0xB03C */
#define B2_DLM_DLM1_ERR_STATUS_FIELD_DLM1_NULL_PUSH_ERR_MASK                                                      0x00000010
#define B2_DLM_DLM1_ERR_STATUS_FIELD_DLM1_NULL_PUSH_ERR_EN_MASK                                                   0x00000100
#define B2_DLM_DLM1_ERR_STATUS_FIELD_DLM1_NULL_PUSH_ERR_MASTER_IDX_MASK                                           0x0003F000
//========================================
/* REG_DLM_DLM1_ERR_STATUS_CLR 0xB040 */
#define B2_DLM_DLM1_ERR_STATUS_CLR_FIELD_DLM1_NULL_PUSH_ERR_CLR_MASK                                              0x00000010
//========================================
/* REG_DLM_DLM1_FLUSH_COUNTER 0xB044 */
#define B2_DLM_DLM1_FLUSH_COUNTER_FIELD_DLM1_FLUSH_COUNTER_MASK                                                   0x0000FFFF
//========================================
/* REG_DLM_DLM1_FLUSH_COUNTER_CLR 0xB048 */
#define B2_DLM_DLM1_FLUSH_COUNTER_CLR_FIELD_DLM1_FLUSH_COUNTER_CLR_MASK                                           0x00000001
//========================================
/* REG_DLM_DLM1_LOGGER_CFG 0xB04C */
#define B2_DLM_DLM1_LOGGER_CFG_FIELD_DLM1_LOGGER_DPL_MASK                                                         0x000FF000
#define B2_DLM_DLM1_LOGGER_CFG_FIELD_DLM1_LOGGER_PRIORITY_MASK                                                    0x03000000
#define B2_DLM_DLM1_LOGGER_CFG_FIELD_DLM1_LOGGER_EN_MASK                                                          0x10000000
#define B2_DLM_DLM1_LOGGER_CFG_FIELD_DLM1_LOGGER_SPECIFIC_CLIENT_MASK                                             0x20000000
#define B2_DLM_DLM1_LOGGER_CFG_FIELD_DLM1_LOGGER_BUSY_MASK                                                        0x80000000
//========================================
/* REG_DLM_DLM2_ERR_STATUS 0xB06C */
#define B2_DLM_DLM2_ERR_STATUS_FIELD_DLM2_NULL_PUSH_ERR_MASK                                                      0x00000010
#define B2_DLM_DLM2_ERR_STATUS_FIELD_DLM2_NULL_PUSH_ERR_EN_MASK                                                   0x00000100
#define B2_DLM_DLM2_ERR_STATUS_FIELD_DLM2_NULL_PUSH_ERR_MASTER_IDX_MASK                                           0x0003F000
//========================================
/* REG_DLM_DLM2_ERR_STATUS_CLR 0xB070 */
#define B2_DLM_DLM2_ERR_STATUS_CLR_FIELD_DLM2_NULL_PUSH_ERR_CLR_MASK                                              0x00000010
//========================================
/* REG_DLM_DLM2_FLUSH_COUNTER 0xB074 */
#define B2_DLM_DLM2_FLUSH_COUNTER_FIELD_DLM2_FLUSH_COUNTER_MASK                                                   0x0000FFFF
//========================================
/* REG_DLM_DLM2_FLUSH_COUNTER_CLR 0xB078 */
#define B2_DLM_DLM2_FLUSH_COUNTER_CLR_FIELD_DLM2_FLUSH_COUNTER_CLR_MASK                                           0x00000001
//========================================
/* REG_DLM_DLM2_LOGGER_CFG 0xB07C */
#define B2_DLM_DLM2_LOGGER_CFG_FIELD_DLM2_LOGGER_PRIMARY_MASK                                                     0x000000FF
#define B2_DLM_DLM2_LOGGER_CFG_FIELD_DLM2_LOGGER_SECONDARY_MASK                                                   0x00000700
#define B2_DLM_DLM2_LOGGER_CFG_FIELD_DLM2_LOGGER_MGMT_TID_MASK                                                    0x00000800
#define B2_DLM_DLM2_LOGGER_CFG_FIELD_DLM2_LOGGER_DPL_MASK                                                         0x000FF000
#define B2_DLM_DLM2_LOGGER_CFG_FIELD_DLM2_LOGGER_PRIORITY_MASK                                                    0x03000000
#define B2_DLM_DLM2_LOGGER_CFG_FIELD_DLM2_LOGGER_EN_MASK                                                          0x10000000
#define B2_DLM_DLM2_LOGGER_CFG_FIELD_DLM2_LOGGER_SPECIFIC_CLIENT_MASK                                             0x20000000
#define B2_DLM_DLM2_LOGGER_CFG_FIELD_DLM2_LOGGER_BUSY_MASK                                                        0x80000000
//========================================
/* REG_DLM_DLM3_ERR_STATUS 0xB09C */
#define B2_DLM_DLM3_ERR_STATUS_FIELD_DLM3_NULL_PUSH_ERR_MASK                                                      0x00000010
#define B2_DLM_DLM3_ERR_STATUS_FIELD_DLM3_NULL_PUSH_ERR_EN_MASK                                                   0x00000100
#define B2_DLM_DLM3_ERR_STATUS_FIELD_DLM3_NULL_PUSH_ERR_MASTER_IDX_MASK                                           0x0003F000
//========================================
/* REG_DLM_DLM3_ERR_STATUS_CLR 0xB0A0 */
#define B2_DLM_DLM3_ERR_STATUS_CLR_FIELD_DLM3_NULL_PUSH_ERR_CLR_MASK                                              0x00000010
//========================================
/* REG_DLM_DLM3_FLUSH_COUNTER 0xB0A4 */
#define B2_DLM_DLM3_FLUSH_COUNTER_FIELD_DLM3_FLUSH_COUNTER_MASK                                                   0x0000FFFF
//========================================
/* REG_DLM_DLM3_FLUSH_COUNTER_CLR 0xB0A8 */
#define B2_DLM_DLM3_FLUSH_COUNTER_CLR_FIELD_DLM3_FLUSH_COUNTER_CLR_MASK                                           0x00000001
//========================================
/* REG_DLM_DLM3_LOGGER_CFG 0xB0AC */
#define B2_DLM_DLM3_LOGGER_CFG_FIELD_DLM3_LOGGER_DPL_MASK                                                         0x000FF000
#define B2_DLM_DLM3_LOGGER_CFG_FIELD_DLM3_LOGGER_PRIORITY_MASK                                                    0x03000000
#define B2_DLM_DLM3_LOGGER_CFG_FIELD_DLM3_LOGGER_EN_MASK                                                          0x10000000
#define B2_DLM_DLM3_LOGGER_CFG_FIELD_DLM3_LOGGER_SPECIFIC_CLIENT_MASK                                             0x20000000
#define B2_DLM_DLM3_LOGGER_CFG_FIELD_DLM3_LOGGER_BUSY_MASK                                                        0x80000000
//========================================
/* REG_DLM_DLM4_ERR_STATUS 0xB0CC */
#define B2_DLM_DLM4_ERR_STATUS_FIELD_DLM4_NULL_PUSH_ERR_MASK                                                      0x00000010
#define B2_DLM_DLM4_ERR_STATUS_FIELD_DLM4_NULL_PUSH_ERR_EN_MASK                                                   0x00000100
#define B2_DLM_DLM4_ERR_STATUS_FIELD_DLM4_NULL_PUSH_ERR_MASTER_IDX_MASK                                           0x0003F000
//========================================
/* REG_DLM_DLM4_ERR_STATUS_CLR 0xB0D0 */
#define B2_DLM_DLM4_ERR_STATUS_CLR_FIELD_DLM4_NULL_PUSH_ERR_CLR_MASK                                              0x00000010
//========================================
/* REG_DLM_DLM4_FLUSH_COUNTER 0xB0D4 */
#define B2_DLM_DLM4_FLUSH_COUNTER_FIELD_DLM4_FLUSH_COUNTER_MASK                                                   0x0000FFFF
//========================================
/* REG_DLM_DLM4_FLUSH_COUNTER_CLR 0xB0D8 */
#define B2_DLM_DLM4_FLUSH_COUNTER_CLR_FIELD_DLM4_FLUSH_COUNTER_CLR_MASK                                           0x00000001
//========================================
/* REG_DLM_DLM4_LOGGER_CFG 0xB0DC */
#define B2_DLM_DLM4_LOGGER_CFG_FIELD_DLM4_LOGGER_DPL_MASK                                                         0x000FF000
#define B2_DLM_DLM4_LOGGER_CFG_FIELD_DLM4_LOGGER_PRIORITY_MASK                                                    0x03000000
#define B2_DLM_DLM4_LOGGER_CFG_FIELD_DLM4_LOGGER_EN_MASK                                                          0x10000000
#define B2_DLM_DLM4_LOGGER_CFG_FIELD_DLM4_LOGGER_SPECIFIC_CLIENT_MASK                                             0x20000000
#define B2_DLM_DLM4_LOGGER_CFG_FIELD_DLM4_LOGGER_BUSY_MASK                                                        0x80000000
//========================================
/* REG_DLM_DLM5_ERR_STATUS 0xB0FC */
#define B2_DLM_DLM5_ERR_STATUS_FIELD_DLM5_NULL_PUSH_ERR_MASK                                                      0x00000010
#define B2_DLM_DLM5_ERR_STATUS_FIELD_DLM5_NULL_PUSH_ERR_EN_MASK                                                   0x00000100
#define B2_DLM_DLM5_ERR_STATUS_FIELD_DLM5_NULL_PUSH_ERR_MASTER_IDX_MASK                                           0x0003F000
//========================================
/* REG_DLM_DLM5_ERR_STATUS_CLR 0xB100 */
#define B2_DLM_DLM5_ERR_STATUS_CLR_FIELD_DLM5_NULL_PUSH_ERR_CLR_MASK                                              0x00000010
//========================================
/* REG_DLM_DLM5_FLUSH_COUNTER 0xB104 */
#define B2_DLM_DLM5_FLUSH_COUNTER_FIELD_DLM5_FLUSH_COUNTER_MASK                                                   0x0000FFFF
//========================================
/* REG_DLM_DLM5_FLUSH_COUNTER_CLR 0xB108 */
#define B2_DLM_DLM5_FLUSH_COUNTER_CLR_FIELD_DLM5_FLUSH_COUNTER_CLR_MASK                                           0x00000001
//========================================
/* REG_DLM_DLM5_LOGGER_CFG 0xB10C */
#define B2_DLM_DLM5_LOGGER_CFG_FIELD_DLM5_LOGGER_DPL_MASK                                                         0x000FF000
#define B2_DLM_DLM5_LOGGER_CFG_FIELD_DLM5_LOGGER_PRIORITY_MASK                                                    0x03000000
#define B2_DLM_DLM5_LOGGER_CFG_FIELD_DLM5_LOGGER_EN_MASK                                                          0x10000000
#define B2_DLM_DLM5_LOGGER_CFG_FIELD_DLM5_LOGGER_SPECIFIC_CLIENT_MASK                                             0x20000000
#define B2_DLM_DLM5_LOGGER_CFG_FIELD_DLM5_LOGGER_BUSY_MASK                                                        0x80000000
//========================================
/* REG_DLM_DLM6_ERR_STATUS 0xB12C */
#define B2_DLM_DLM6_ERR_STATUS_FIELD_DLM6_NULL_PUSH_ERR_MASK                                                      0x00000010
#define B2_DLM_DLM6_ERR_STATUS_FIELD_DLM6_NULL_PUSH_ERR_EN_MASK                                                   0x00000100
#define B2_DLM_DLM6_ERR_STATUS_FIELD_DLM6_NULL_PUSH_ERR_MASTER_IDX_MASK                                           0x0003F000
//========================================
/* REG_DLM_DLM6_ERR_STATUS_CLR 0xB130 */
#define B2_DLM_DLM6_ERR_STATUS_CLR_FIELD_DLM6_NULL_PUSH_ERR_CLR_MASK                                              0x00000010
//========================================
/* REG_DLM_DLM6_FLUSH_COUNTER 0xB134 */
#define B2_DLM_DLM6_FLUSH_COUNTER_FIELD_DLM6_FLUSH_COUNTER_MASK                                                   0x0000FFFF
//========================================
/* REG_DLM_DLM6_FLUSH_COUNTER_CLR 0xB138 */
#define B2_DLM_DLM6_FLUSH_COUNTER_CLR_FIELD_DLM6_FLUSH_COUNTER_CLR_MASK                                           0x00000001
//========================================
/* REG_DLM_DLM6_LOGGER_CFG 0xB13C */
#define B2_DLM_DLM6_LOGGER_CFG_FIELD_DLM6_LOGGER_DPL_MASK                                                         0x000FF000
#define B2_DLM_DLM6_LOGGER_CFG_FIELD_DLM6_LOGGER_PRIORITY_MASK                                                    0x03000000
#define B2_DLM_DLM6_LOGGER_CFG_FIELD_DLM6_LOGGER_EN_MASK                                                          0x10000000
#define B2_DLM_DLM6_LOGGER_CFG_FIELD_DLM6_LOGGER_SPECIFIC_CLIENT_MASK                                             0x20000000
#define B2_DLM_DLM6_LOGGER_CFG_FIELD_DLM6_LOGGER_BUSY_MASK                                                        0x80000000
//========================================
/* REG_DLM_DLM7_ERR_STATUS 0xB15C */
#define B2_DLM_DLM7_ERR_STATUS_FIELD_DLM7_NULL_PUSH_ERR_MASK                                                      0x00000010
#define B2_DLM_DLM7_ERR_STATUS_FIELD_DLM7_NULL_PUSH_ERR_EN_MASK                                                   0x00000100
#define B2_DLM_DLM7_ERR_STATUS_FIELD_DLM7_NULL_PUSH_ERR_MASTER_IDX_MASK                                           0x0003F000
//========================================
/* REG_DLM_DLM7_ERR_STATUS_CLR 0xB160 */
#define B2_DLM_DLM7_ERR_STATUS_CLR_FIELD_DLM7_NULL_PUSH_ERR_CLR_MASK                                              0x00000010
//========================================
/* REG_DLM_DLM7_FLUSH_COUNTER 0xB164 */
#define B2_DLM_DLM7_FLUSH_COUNTER_FIELD_DLM7_FLUSH_COUNTER_MASK                                                   0x0000FFFF
//========================================
/* REG_DLM_DLM7_FLUSH_COUNTER_CLR 0xB168 */
#define B2_DLM_DLM7_FLUSH_COUNTER_CLR_FIELD_DLM7_FLUSH_COUNTER_CLR_MASK                                           0x00000001
//========================================
/* REG_DLM_DLM7_LOGGER_CFG 0xB16C */
#define B2_DLM_DLM7_LOGGER_CFG_FIELD_DLM7_LOGGER_DPL_MASK                                                         0x000FF000
#define B2_DLM_DLM7_LOGGER_CFG_FIELD_DLM7_LOGGER_PRIORITY_MASK                                                    0x03000000
#define B2_DLM_DLM7_LOGGER_CFG_FIELD_DLM7_LOGGER_EN_MASK                                                          0x10000000
#define B2_DLM_DLM7_LOGGER_CFG_FIELD_DLM7_LOGGER_SPECIFIC_CLIENT_MASK                                             0x20000000
#define B2_DLM_DLM7_LOGGER_CFG_FIELD_DLM7_LOGGER_BUSY_MASK                                                        0x80000000
//========================================
/* REG_DLM_DLM8_ERR_STATUS 0xB18C */
#define B2_DLM_DLM8_ERR_STATUS_FIELD_DLM8_NULL_PUSH_ERR_MASK                                                      0x00000010
#define B2_DLM_DLM8_ERR_STATUS_FIELD_DLM8_NULL_PUSH_ERR_EN_MASK                                                   0x00000100
#define B2_DLM_DLM8_ERR_STATUS_FIELD_DLM8_NULL_PUSH_ERR_MASTER_IDX_MASK                                           0x0003F000
//========================================
/* REG_DLM_DLM8_ERR_STATUS_CLR 0xB190 */
#define B2_DLM_DLM8_ERR_STATUS_CLR_FIELD_DLM8_NULL_PUSH_ERR_CLR_MASK                                              0x00000010
//========================================
/* REG_DLM_DLM8_FLUSH_COUNTER 0xB194 */
#define B2_DLM_DLM8_FLUSH_COUNTER_FIELD_DLM8_FLUSH_COUNTER_MASK                                                   0x0000FFFF
//========================================
/* REG_DLM_DLM8_FLUSH_COUNTER_CLR 0xB198 */
#define B2_DLM_DLM8_FLUSH_COUNTER_CLR_FIELD_DLM8_FLUSH_COUNTER_CLR_MASK                                           0x00000001
//========================================
/* REG_DLM_DLM8_LOGGER_CFG 0xB19C */
#define B2_DLM_DLM8_LOGGER_CFG_FIELD_DLM8_LOGGER_DPL_MASK                                                         0x000FF000
#define B2_DLM_DLM8_LOGGER_CFG_FIELD_DLM8_LOGGER_PRIORITY_MASK                                                    0x03000000
#define B2_DLM_DLM8_LOGGER_CFG_FIELD_DLM8_LOGGER_EN_MASK                                                          0x10000000
#define B2_DLM_DLM8_LOGGER_CFG_FIELD_DLM8_LOGGER_SPECIFIC_CLIENT_MASK                                             0x20000000
#define B2_DLM_DLM8_LOGGER_CFG_FIELD_DLM8_LOGGER_BUSY_MASK                                                        0x80000000
//========================================
/* REG_DLM_LOGGER_MESSAGE_CFG 0xB200 */
#define B2_DLM_LOGGER_MESSAGE_CFG_FIELD_LOGGER_MAX_MESSAGE_COUNT_MASK                                             0x0000003F
#define B2_DLM_LOGGER_MESSAGE_CFG_FIELD_LOGGER_TIMEOUT_COUNT_MASK                                                 0x0003FF00


#endif // _DLM_REGS_H_
