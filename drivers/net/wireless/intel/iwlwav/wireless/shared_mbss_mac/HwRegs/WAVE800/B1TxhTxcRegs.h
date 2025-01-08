
/***********************************************************************************
File:				B1TxhTxcRegs.h
Module:				b1TxhTxc
SOC Revision:		latest
Generated at:       2024-06-26 12:54:47
Purpose:
Description:		This File was auto generated using SOC Online

************************************************************************************/
#ifndef _B1_TXH_TXC_REGS_H_
#define _B1_TXH_TXC_REGS_H_

/*---------------------------------------------------------------------------------
/						Registers Addresses													 
/----------------------------------------------------------------------------------*/
#include "HwMemoryMap.h"

#define B1_TXH_TXC_BASE_ADDRESS                    MEMORY_MAP_UNIT_10053_BASE_ADDRESS
#define	REG_B1_TXH_TXC_TXH_TXC_ENABLE               (B1_TXH_TXC_BASE_ADDRESS + 0x0)
#define	REG_B1_TXH_TXC_TXH_TXC_CONTROL              (B1_TXH_TXC_BASE_ADDRESS + 0x4)
#define	REG_B1_TXH_TXC_SIFS_ELEMENT                 (B1_TXH_TXC_BASE_ADDRESS + 0x10)
#define	REG_B1_TXH_TXC_TXC_SENSITIVE_DEFAULT        (B1_TXH_TXC_BASE_ADDRESS + 0x20)
#define	REG_B1_TXH_TXC_RESP_TIMEOUT_VALUE_SET       (B1_TXH_TXC_BASE_ADDRESS + 0x24)
#define	REG_B1_TXH_TXC_RESP_TIMEOUT_RD              (B1_TXH_TXC_BASE_ADDRESS + 0x28)
#define	REG_B1_TXH_TXC_TXC_DEBUG                    (B1_TXH_TXC_BASE_ADDRESS + 0x2C)
#define	REG_B1_TXH_TXC_START_SLOT_AFTER_SIFS_CTR    (B1_TXH_TXC_BASE_ADDRESS + 0x30)
#define	REG_B1_TXH_TXC_START_SLOT_AFTER_SLOT_CTR    (B1_TXH_TXC_BASE_ADDRESS + 0x34)
/*---------------------------------------------------------------------------------
/						Data Type Definition										
/----------------------------------------------------------------------------------*/
/*REG_B1_TXH_TXC_TXH_TXC_ENABLE 0x0 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 txhTxcEnable : 1; //TXH TXC enable, reset value: 0x0, access type: RW
		uint32 reserved0 : 31;
	} bitFields;
} RegB1TxhTxcTxhTxcEnable_u;

/*REG_B1_TXH_TXC_TXH_TXC_CONTROL 0x4 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 abortEifsOnCcaBusyEn : 1; //0: Abort EIFS counting on new PHY-MAC RX session. , 1: Abort EIFS counting on new PHY-MAC RX session OR CCA primary busy., reset value: 0x0, access type: RW
		uint32 reserved0 : 31;
	} bitFields;
} RegB1TxhTxcTxhTxcControl_u;

/*REG_B1_TXH_TXC_SIFS_ELEMENT 0x10 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 sifsElement : 8; //SIFS element, reset value: 0x0, access type: RW
		uint32 reserved0 : 24;
	} bitFields;
} RegB1TxhTxcSifsElement_u;

/*REG_B1_TXH_TXC_TXC_SENSITIVE_DEFAULT 0x20 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 txcCcaSensitiveDefault : 1; //CCA sensitive default, reset value: 0x1, access type: RW
		uint32 txcRxNavSensitiveDefault : 1; //RX NAV sensitive default, reset value: 0x1, access type: RW
		uint32 txcTxNavSensitiveDefault : 1; //TX NAV sensitive default, reset value: 0x1, access type: RW
		uint32 reserved0 : 29;
	} bitFields;
} RegB1TxhTxcTxcSensitiveDefault_u;

/*REG_B1_TXH_TXC_RESP_TIMEOUT_VALUE_SET 0x24 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 respTimeoutValueSet : 13; //Response timeout set, reset value: 0x0, access type: RW
		uint32 reserved0 : 19;
	} bitFields;
} RegB1TxhTxcRespTimeoutValueSet_u;

/*REG_B1_TXH_TXC_RESP_TIMEOUT_RD 0x28 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 respTimeoutRd : 13; //Response timeout read, reset value: 0x0, access type: RO
		uint32 reserved0 : 3;
		uint32 respTimeoutEnRd : 1; //Response timeout enable read, reset value: 0x0, access type: RO
		uint32 reserved1 : 15;
	} bitFields;
} RegB1TxhTxcRespTimeoutRd_u;

/*REG_B1_TXH_TXC_TXC_DEBUG 0x2C */
typedef union
{
	uint32 val;
	struct
	{
		uint32 txcSm : 4; //TXC state machine, reset value: 0x0, access type: RO
		uint32 reserved0 : 28;
	} bitFields;
} RegB1TxhTxcTxcDebug_u;

/*REG_B1_TXH_TXC_START_SLOT_AFTER_SIFS_CTR 0x30 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 startSlotAfterSifsCtr : 16; //Counter of Start SLOT after SIFS events from TXC to TxH, reset value: 0x0, access type: RO
		uint32 reserved0 : 16;
	} bitFields;
} RegB1TxhTxcStartSlotAfterSifsCtr_u;

/*REG_B1_TXH_TXC_START_SLOT_AFTER_SLOT_CTR 0x34 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 startSlotAfterSlotCtr : 24; //Counter of Start SLOT after SLOT events from TXC to TxH, reset value: 0x0, access type: RO
		uint32 reserved0 : 8;
	} bitFields;
} RegB1TxhTxcStartSlotAfterSlotCtr_u;

//========================================
/* REG_TXH_TXC_TXH_TXC_ENABLE 0x0 */
#define B1_TXH_TXC_TXH_TXC_ENABLE_FIELD_TXH_TXC_ENABLE_MASK                                                       0x00000001
//========================================
/* REG_TXH_TXC_TXH_TXC_CONTROL 0x4 */
#define B1_TXH_TXC_TXH_TXC_CONTROL_FIELD_ABORT_EIFS_ON_CCA_BUSY_EN_MASK                                           0x00000001
//========================================
/* REG_TXH_TXC_SIFS_ELEMENT 0x10 */
#define B1_TXH_TXC_SIFS_ELEMENT_FIELD_SIFS_ELEMENT_MASK                                                           0x000000FF
//========================================
/* REG_TXH_TXC_TXC_SENSITIVE_DEFAULT 0x20 */
#define B1_TXH_TXC_TXC_SENSITIVE_DEFAULT_FIELD_TXC_CCA_SENSITIVE_DEFAULT_MASK                                     0x00000001
#define B1_TXH_TXC_TXC_SENSITIVE_DEFAULT_FIELD_TXC_RX_NAV_SENSITIVE_DEFAULT_MASK                                  0x00000002
#define B1_TXH_TXC_TXC_SENSITIVE_DEFAULT_FIELD_TXC_TX_NAV_SENSITIVE_DEFAULT_MASK                                  0x00000004
//========================================
/* REG_TXH_TXC_RESP_TIMEOUT_VALUE_SET 0x24 */
#define B1_TXH_TXC_RESP_TIMEOUT_VALUE_SET_FIELD_RESP_TIMEOUT_VALUE_SET_MASK                                       0x00001FFF
//========================================
/* REG_TXH_TXC_RESP_TIMEOUT_RD 0x28 */
#define B1_TXH_TXC_RESP_TIMEOUT_RD_FIELD_RESP_TIMEOUT_RD_MASK                                                     0x00001FFF
#define B1_TXH_TXC_RESP_TIMEOUT_RD_FIELD_RESP_TIMEOUT_EN_RD_MASK                                                  0x00010000
//========================================
/* REG_TXH_TXC_TXC_DEBUG 0x2C */
#define B1_TXH_TXC_TXC_DEBUG_FIELD_TXC_SM_MASK                                                                    0x0000000F
//========================================
/* REG_TXH_TXC_START_SLOT_AFTER_SIFS_CTR 0x30 */
#define B1_TXH_TXC_START_SLOT_AFTER_SIFS_CTR_FIELD_START_SLOT_AFTER_SIFS_CTR_MASK                                 0x0000FFFF
//========================================
/* REG_TXH_TXC_START_SLOT_AFTER_SLOT_CTR 0x34 */
#define B1_TXH_TXC_START_SLOT_AFTER_SLOT_CTR_FIELD_START_SLOT_AFTER_SLOT_CTR_MASK                                 0x00FFFFFF


#endif // _TXH_TXC_REGS_H_
