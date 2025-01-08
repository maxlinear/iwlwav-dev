
/***********************************************************************************
File:				B1PsSettingRegs.h
Module:				b1PsSetting
SOC Revision:		latest
Generated at:       2024-06-26 12:54:44
Purpose:
Description:		This File was auto generated using SOC Online

************************************************************************************/
#ifndef _B1_PS_SETTING_REGS_H_
#define _B1_PS_SETTING_REGS_H_

/*---------------------------------------------------------------------------------
/						Registers Addresses													 
/----------------------------------------------------------------------------------*/
#include "HwMemoryMap.h"

#define B1_PS_SETTING_BASE_ADDRESS                                      MEMORY_MAP_UNIT_10058_BASE_ADDRESS
#define	REG_B1_PS_SETTING_PS_SETTING_CONTROL                                (B1_PS_SETTING_BASE_ADDRESS + 0x0)
#define	REG_B1_PS_SETTING_PS_VAP_DISABLE                                    (B1_PS_SETTING_BASE_ADDRESS + 0x4)
#define	REG_B1_PS_SETTING_PD_NDP_TX_PD_LIST_IDX                             (B1_PS_SETTING_BASE_ADDRESS + 0x8)
#define	REG_B1_PS_SETTING_PS_STATUS_CHANGE_STA_0TO31_NOTIFY_EN              (B1_PS_SETTING_BASE_ADDRESS + 0x10)
#define	REG_B1_PS_SETTING_PS_STATUS_CHANGE_STA_32TO63_NOTIFY_EN             (B1_PS_SETTING_BASE_ADDRESS + 0x14)
#define	REG_B1_PS_SETTING_PS_STATUS_CHANGE_STA_64TO95_NOTIFY_EN             (B1_PS_SETTING_BASE_ADDRESS + 0x18)
#define	REG_B1_PS_SETTING_PS_STATUS_CHANGE_STA_96TO127_NOTIFY_EN            (B1_PS_SETTING_BASE_ADDRESS + 0x1C)
#define	REG_B1_PS_SETTING_PS_STATUS_CHANGE_STA_128TO159_NOTIFY_EN           (B1_PS_SETTING_BASE_ADDRESS + 0x20)
#define	REG_B1_PS_SETTING_PS_STATUS_CHANGE_STA_160TO191_NOTIFY_EN           (B1_PS_SETTING_BASE_ADDRESS + 0x24)
#define	REG_B1_PS_SETTING_PS_STATUS_CHANGE_STA_192TO223_NOTIFY_EN           (B1_PS_SETTING_BASE_ADDRESS + 0x28)
#define	REG_B1_PS_SETTING_PS_STATUS_CHANGE_STA_224TO255_NOTIFY_EN           (B1_PS_SETTING_BASE_ADDRESS + 0x2C)
#define	REG_B1_PS_SETTING_PS_FW_NOTIFICATION_EN                             (B1_PS_SETTING_BASE_ADDRESS + 0x30)
#define	REG_B1_PS_SETTING_PS_FIFO_BASE_ADDR                                 (B1_PS_SETTING_BASE_ADDRESS + 0x40)
#define	REG_B1_PS_SETTING_PS_FIFO_DEPTH_MINUS_ONE                           (B1_PS_SETTING_BASE_ADDRESS + 0x44)
#define	REG_B1_PS_SETTING_PS_FIFO_CLEAR_STRB                                (B1_PS_SETTING_BASE_ADDRESS + 0x48)
#define	REG_B1_PS_SETTING_PS_FIFO_RD_ENTRIES_NUM                            (B1_PS_SETTING_BASE_ADDRESS + 0x4C)
#define	REG_B1_PS_SETTING_PS_FIFO_NUM_ENTRIES_COUNT                         (B1_PS_SETTING_BASE_ADDRESS + 0x50)
#define	REG_B1_PS_SETTING_PS_FIFO_DEBUG                                     (B1_PS_SETTING_BASE_ADDRESS + 0x54)
#define	REG_B1_PS_SETTING_PS_DEBUG                                          (B1_PS_SETTING_BASE_ADDRESS + 0x58)
#define	REG_B1_PS_SETTING_PS_LOGGER                                         (B1_PS_SETTING_BASE_ADDRESS + 0x5C)
#define	REG_B1_PS_SETTING_PS_LOGGER_ACTIVE                                  (B1_PS_SETTING_BASE_ADDRESS + 0x60)
#define	REG_B1_PS_SETTING_PS_SETTING_ERR_IRQ_EN                             (B1_PS_SETTING_BASE_ADDRESS + 0x64)
#define	REG_B1_PS_SETTING_PS_SETTING_ERR_IRQ_CLR                            (B1_PS_SETTING_BASE_ADDRESS + 0x68)
#define	REG_B1_PS_SETTING_PS_SETTING_ERR_IRQ_STATUS                         (B1_PS_SETTING_BASE_ADDRESS + 0x6C)
#define	REG_B1_PS_SETTING_PS_STATUS_CHANGE_STA_0TO31_PS_REQ_NOTIFY_EN       (B1_PS_SETTING_BASE_ADDRESS + 0x70)
#define	REG_B1_PS_SETTING_PS_STATUS_CHANGE_STA_32TO63_PS_REQ_NOTIFY_EN      (B1_PS_SETTING_BASE_ADDRESS + 0x74)
#define	REG_B1_PS_SETTING_PS_STATUS_CHANGE_STA_64TO95_PS_REQ_NOTIFY_EN      (B1_PS_SETTING_BASE_ADDRESS + 0x78)
#define	REG_B1_PS_SETTING_PS_STATUS_CHANGE_STA_96TO127_PS_REQ_NOTIFY_EN     (B1_PS_SETTING_BASE_ADDRESS + 0x7C)
#define	REG_B1_PS_SETTING_PS_STATUS_CHANGE_STA_128TO159_PS_REQ_NOTIFY_EN    (B1_PS_SETTING_BASE_ADDRESS + 0x80)
#define	REG_B1_PS_SETTING_PS_STATUS_CHANGE_STA_160TO191_PS_REQ_NOTIFY_EN    (B1_PS_SETTING_BASE_ADDRESS + 0x84)
#define	REG_B1_PS_SETTING_PS_STATUS_CHANGE_STA_192TO223_PS_REQ_NOTIFY_EN    (B1_PS_SETTING_BASE_ADDRESS + 0x88)
#define	REG_B1_PS_SETTING_PS_STATUS_CHANGE_STA_224TO255_PS_REQ_NOTIFY_EN    (B1_PS_SETTING_BASE_ADDRESS + 0x8C)
/*---------------------------------------------------------------------------------
/						Data Type Definition										
/----------------------------------------------------------------------------------*/
/*REG_B1_PS_SETTING_PS_SETTING_CONTROL 0x0 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 psSettingEn : 1; //Enable PS setting module, reset value: 0x1, access type: RW
		uint32 reserved0 : 1;
		uint32 psRequestMode : 1; //PS request mode: , 0 --- Selective Request Mode , 1 --- Full Request Mode, reset value: 0x0, access type: RW
		uint32 psRequestTwtAvailEn : 1; //Enable PS request rules for TWT Availability agreement STA, reset value: 0x1, access type: RW
		uint32 psRequestNfrpEn : 1; //Enable setting PS request in case of NDP feedback, reset value: 0x1, access type: RW
		uint32 ndpNonAckablePdTypeTwt : 1; //In case of pushing NDP PD, and no TID configured as SU and TWT is ON: 0 - set PD type 2 of ackable NDP, 1 - set PD type 20 of non-ackable NDP, reset value: 0x0, access type: RW
		uint32 ndpNonAckablePdTypeNoTwt : 1; //In case of pushing NDP PD, and no TID configured as SU and TWT is OFF: 0 - set PD type 2 of ackable NDP, 1 - set PD type 20 of non-ackable NDP, reset value: 0x0, access type: RW
		uint32 reserved1 : 25;
	} bitFields;
} RegB1PsSettingPsSettingControl_u;

/*REG_B1_PS_SETTING_PS_VAP_DISABLE 0x4 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 psVapDisable : 32; //Enable/disable PS setting per VAP: , '1' --- Disable PS setting, , '0' --- Enable PS Setting., reset value: 0x0, access type: RW
	} bitFields;
} RegB1PsSettingPsVapDisable_u;

/*REG_B1_PS_SETTING_PD_NDP_TX_PD_LIST_IDX 0x8 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 pdNdpTxPdListIdx : 7; //List index in Q manager of NDP Tx PD poll, reset value: 0x0, access type: RW
		uint32 reserved0 : 25;
	} bitFields;
} RegB1PsSettingPdNdpTxPdListIdx_u;

/*REG_B1_PS_SETTING_PS_STATUS_CHANGE_STA_0TO31_NOTIFY_EN 0x10 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 psStatusChangeSta0To31NotifyEn : 32; //Enable FW notification PS status change STA0to31, reset value: 0x0, access type: RW
	} bitFields;
} RegB1PsSettingPsStatusChangeSta0To31NotifyEn_u;

/*REG_B1_PS_SETTING_PS_STATUS_CHANGE_STA_32TO63_NOTIFY_EN 0x14 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 psStatusChangeSta32To63NotifyEn : 32; //Enable FW notification PS status change STA32to63, reset value: 0x0, access type: RW
	} bitFields;
} RegB1PsSettingPsStatusChangeSta32To63NotifyEn_u;

/*REG_B1_PS_SETTING_PS_STATUS_CHANGE_STA_64TO95_NOTIFY_EN 0x18 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 psStatusChangeSta64To95NotifyEn : 32; //Enable FW notification PS status change STA64to95, reset value: 0x0, access type: RW
	} bitFields;
} RegB1PsSettingPsStatusChangeSta64To95NotifyEn_u;

/*REG_B1_PS_SETTING_PS_STATUS_CHANGE_STA_96TO127_NOTIFY_EN 0x1C */
typedef union
{
	uint32 val;
	struct
	{
		uint32 psStatusChangeSta96To127NotifyEn : 32; //Enable FW notification PS status change STA96to127, reset value: 0x0, access type: RW
	} bitFields;
} RegB1PsSettingPsStatusChangeSta96To127NotifyEn_u;

/*REG_B1_PS_SETTING_PS_STATUS_CHANGE_STA_128TO159_NOTIFY_EN 0x20 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 psStatusChangeSta128To159NotifyEn : 32; //Enable FW notification PS status change STA128to159, reset value: 0x0, access type: RW
	} bitFields;
} RegB1PsSettingPsStatusChangeSta128To159NotifyEn_u;

/*REG_B1_PS_SETTING_PS_STATUS_CHANGE_STA_160TO191_NOTIFY_EN 0x24 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 psStatusChangeSta160To191NotifyEn : 32; //Enable FW notification PS status change STA160to191, reset value: 0x0, access type: RW
	} bitFields;
} RegB1PsSettingPsStatusChangeSta160To191NotifyEn_u;

/*REG_B1_PS_SETTING_PS_STATUS_CHANGE_STA_192TO223_NOTIFY_EN 0x28 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 psStatusChangeSta192To223NotifyEn : 32; //Enable FW notification PS status change STA192to223, reset value: 0x0, access type: RW
	} bitFields;
} RegB1PsSettingPsStatusChangeSta192To223NotifyEn_u;

/*REG_B1_PS_SETTING_PS_STATUS_CHANGE_STA_224TO255_NOTIFY_EN 0x2C */
typedef union
{
	uint32 val;
	struct
	{
		uint32 psStatusChangeSta224To255NotifyEn : 32; //Enable FW notification PS status change STA224to255, reset value: 0x0, access type: RW
	} bitFields;
} RegB1PsSettingPsStatusChangeSta224To255NotifyEn_u;

/*REG_B1_PS_SETTING_PS_FW_NOTIFICATION_EN 0x30 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 ndpTxPdEmptyNotifyEn : 1; //Enable notification to FW in case of No setting of PS request due to NDP Tx PD list empty, reset value: 0x0, access type: RW
		uint32 psPollFcPmZeroNotifyEn : 1; //Enable notification to FW in case of Receive PS-Poll with Power Management bit==0, reset value: 0x0, access type: RW
		uint32 psPollNoMatchAidNotifyEn : 1; //Enable notification to FW in case of Receive PS-Poll while AID[13:0] != (Addr2 index + 1), reset value: 0x0, access type: RW
		uint32 skipPushNdpNoSuTidForwardFwEn : 1; //Enable notification to FW in case of No setting PS request due to no TIDs 0-7 configured as SU, which caused to skip pushing NDP Tx PD. , reset value: 0x0, access type: RW
		uint32 reserved0 : 28;
	} bitFields;
} RegB1PsSettingPsFwNotificationEn_u;

/*REG_B1_PS_SETTING_PS_FIFO_BASE_ADDR 0x40 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 psFifoBaseAddr : 22; //PS FIFO base address, reset value: 0x0, access type: RW
		uint32 reserved0 : 10;
	} bitFields;
} RegB1PsSettingPsFifoBaseAddr_u;

/*REG_B1_PS_SETTING_PS_FIFO_DEPTH_MINUS_ONE 0x44 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 psFifoDepthMinusOne : 8; //PS FIFO depth minus one, reset value: 0x0, access type: RW
		uint32 reserved0 : 24;
	} bitFields;
} RegB1PsSettingPsFifoDepthMinusOne_u;

/*REG_B1_PS_SETTING_PS_FIFO_CLEAR_STRB 0x48 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 psFifoClearStrb : 1; //Clear PS FIFO by write '1', reset value: 0x0, access type: WO
		uint32 psFifoClearFullDropCtrStrb : 1; //Clear PS fifo full drop counter, reset value: 0x0, access type: WO
		uint32 reserved0 : 30;
	} bitFields;
} RegB1PsSettingPsFifoClearStrb_u;

/*REG_B1_PS_SETTING_PS_FIFO_RD_ENTRIES_NUM 0x4C */
typedef union
{
	uint32 val;
	struct
	{
		uint32 psFifoRdEntriesNum : 9; //PS FIFO number of entries to decrement, reset value: 0x0, access type: RW
		uint32 reserved0 : 23;
	} bitFields;
} RegB1PsSettingPsFifoRdEntriesNum_u;

/*REG_B1_PS_SETTING_PS_FIFO_NUM_ENTRIES_COUNT 0x50 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 psFifoNumEntriesCount : 9; //PS FIFO number of entries count, reset value: 0x0, access type: RO
		uint32 reserved0 : 23;
	} bitFields;
} RegB1PsSettingPsFifoNumEntriesCount_u;

/*REG_B1_PS_SETTING_PS_FIFO_DEBUG 0x54 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 psFifoWrPtr : 8; //PS FIFO write pointer index, reset value: 0x0, access type: RO
		uint32 reserved0 : 8;
		uint32 psFifoNotEmpty : 1; //PS FIFO not empty indication, reset value: 0x0, access type: RO
		uint32 psFifoFull : 1; //PS FIFO full indication, reset value: 0x0, access type: RO
		uint32 reserved1 : 6;
		uint32 psFifoFullDropCtr : 8; //PS setting FIFO full drop counter, reset value: 0x0, access type: RO
	} bitFields;
} RegB1PsSettingPsFifoDebug_u;

/*REG_B1_PS_SETTING_PS_DEBUG 0x58 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 psStateMachine : 5; //PS state machine, reset value: 0x0, access type: RO
		uint32 psWrpSm : 3; //PS wrapper state machine, reset value: 0x0, access type: RO
		uint32 psShramIfSm : 3; //PS ShRAM I/F state machine, reset value: 0x0, access type: RO
		uint32 loggerSm : 3; //PS logger state machine, reset value: 0x0, access type: RO
		uint32 reserved0 : 18;
	} bitFields;
} RegB1PsSettingPsDebug_u;

/*REG_B1_PS_SETTING_PS_LOGGER 0x5C */
typedef union
{
	uint32 val;
	struct
	{
		uint32 psLoggerEn : 1; //PS Setting logger enable, reset value: 0x0, access type: RW
		uint32 reserved0 : 7;
		uint32 psLoggerPriority : 2; //PS Setting logger priority, reset value: 0x0, access type: RW
		uint32 reserved1 : 22;
	} bitFields;
} RegB1PsSettingPsLogger_u;

/*REG_B1_PS_SETTING_PS_LOGGER_ACTIVE 0x60 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 psLoggerActive : 1; //PS setting logger active, reset value: 0x0, access type: RO
		uint32 reserved0 : 31;
	} bitFields;
} RegB1PsSettingPsLoggerActive_u;

/*REG_B1_PS_SETTING_PS_SETTING_ERR_IRQ_EN 0x64 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 startNewRxSessionWhileWaitAutoRespIrqEn : 1; //Start new Rx session, while PS setting module wait for auto response result ready, IRQ enable, reset value: 0x0, access type: RW
		uint32 startNewRxSessionWhilePsSettingActiveIrqEn : 1; //Start new Rx session, while PS setting module is still active, IRQ enable, reset value: 0x0, access type: RW
		uint32 psSettingFifoDecrementLessThanZeroIrqEn : 1; //PS setting FIFO amount has been decremented less than zero, IRQ enable, reset value: 0x0, access type: RW
		uint32 psSettingFifoFullDropIrqEn : 1; //PS setting drop entry due to FIFO full, IRQ enable, reset value: 0x0, access type: RW
		uint32 reserved0 : 28;
	} bitFields;
} RegB1PsSettingPsSettingErrIrqEn_u;

/*REG_B1_PS_SETTING_PS_SETTING_ERR_IRQ_CLR 0x68 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 startNewRxSessionWhileWaitAutoRespIrqClr : 1; //Start new Rx session, while PS setting module wait for auto response result ready, IRQ clear by write '1', reset value: 0x0, access type: WO
		uint32 startNewRxSessionWhilePsSettingActiveIrqClr : 1; //Start new Rx session, while PS setting module is still active, IRQ clear by write '1', reset value: 0x0, access type: WO
		uint32 psSettingFifoDecrementLessThanZeroIrqClr : 1; //PS setting FIFO amount has been decremented less than zero, IRQ clear by write '1', reset value: 0x0, access type: WO
		uint32 reserved0 : 29;
	} bitFields;
} RegB1PsSettingPsSettingErrIrqClr_u;

/*REG_B1_PS_SETTING_PS_SETTING_ERR_IRQ_STATUS 0x6C */
typedef union
{
	uint32 val;
	struct
	{
		uint32 startNewRxSessionWhileWaitAutoRespIrq : 1; //Start new Rx session, while PS setting module wait for auto response result ready, IRQ status, reset value: 0x0, access type: RO
		uint32 startNewRxSessionWhilePsSettingActiveIrq : 1; //Start new Rx session, while PS setting module is still active, IRQ status, reset value: 0x0, access type: RO
		uint32 psSettingFifoDecrementLessThanZeroIrq : 1; //PS setting FIFO amount has been decremented less than zero, IRQ status, reset value: 0x0, access type: RO
		uint32 psSettingFifoFullDropIrq : 1; //PS setting drop entry due to FIFO full, IRQ status, reset value: 0x0, access type: RO
		uint32 reserved0 : 28;
	} bitFields;
} RegB1PsSettingPsSettingErrIrqStatus_u;

/*REG_B1_PS_SETTING_PS_STATUS_CHANGE_STA_0TO31_PS_REQ_NOTIFY_EN 0x70 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 psStatusChangeSta0To31PsReqNotifyEn : 32; //Enable FW notification PS_REQ status change STA0to31, reset value: 0x0, access type: RW
	} bitFields;
} RegB1PsSettingPsStatusChangeSta0To31PsReqNotifyEn_u;

/*REG_B1_PS_SETTING_PS_STATUS_CHANGE_STA_32TO63_PS_REQ_NOTIFY_EN 0x74 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 psStatusChangeSta32To63PsReqNotifyEn : 32; //Enable FW notification PS_REQ status change STA32to63, reset value: 0x0, access type: RW
	} bitFields;
} RegB1PsSettingPsStatusChangeSta32To63PsReqNotifyEn_u;

/*REG_B1_PS_SETTING_PS_STATUS_CHANGE_STA_64TO95_PS_REQ_NOTIFY_EN 0x78 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 psStatusChangeSta64To95PsReqNotifyEn : 32; //Enable FW notification PS_REQ status change STA64to95, reset value: 0x0, access type: RW
	} bitFields;
} RegB1PsSettingPsStatusChangeSta64To95PsReqNotifyEn_u;

/*REG_B1_PS_SETTING_PS_STATUS_CHANGE_STA_96TO127_PS_REQ_NOTIFY_EN 0x7C */
typedef union
{
	uint32 val;
	struct
	{
		uint32 psStatusChangeSta96To127PsReqNotifyEn : 32; //Enable FW notification PS_REQ status change STA96to127, reset value: 0x0, access type: RW
	} bitFields;
} RegB1PsSettingPsStatusChangeSta96To127PsReqNotifyEn_u;

/*REG_B1_PS_SETTING_PS_STATUS_CHANGE_STA_128TO159_PS_REQ_NOTIFY_EN 0x80 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 psStatusChangeSta128To159PsReqNotifyEn : 32; //Enable FW notification PS_REQ status change STA128to159, reset value: 0x0, access type: RW
	} bitFields;
} RegB1PsSettingPsStatusChangeSta128To159PsReqNotifyEn_u;

/*REG_B1_PS_SETTING_PS_STATUS_CHANGE_STA_160TO191_PS_REQ_NOTIFY_EN 0x84 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 psStatusChangeSta160To191PsReqNotifyEn : 32; //Enable FW notification PS_REQ status change STA160to191, reset value: 0x0, access type: RW
	} bitFields;
} RegB1PsSettingPsStatusChangeSta160To191PsReqNotifyEn_u;

/*REG_B1_PS_SETTING_PS_STATUS_CHANGE_STA_192TO223_PS_REQ_NOTIFY_EN 0x88 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 psStatusChangeSta192To223PsReqNotifyEn : 32; //Enable FW notification PS_REQ status change STA192to223, reset value: 0x0, access type: RW
	} bitFields;
} RegB1PsSettingPsStatusChangeSta192To223PsReqNotifyEn_u;

/*REG_B1_PS_SETTING_PS_STATUS_CHANGE_STA_224TO255_PS_REQ_NOTIFY_EN 0x8C */
typedef union
{
	uint32 val;
	struct
	{
		uint32 psStatusChangeSta224To255PsReqNotifyEn : 32; //Enable FW notification PS_REQ status change STA224to255, reset value: 0x0, access type: RW
	} bitFields;
} RegB1PsSettingPsStatusChangeSta224To255PsReqNotifyEn_u;

//========================================
/* REG_PS_SETTING_PS_SETTING_CONTROL 0x0 */
#define B1_PS_SETTING_PS_SETTING_CONTROL_FIELD_PS_SETTING_EN_MASK                                                 0x00000001
#define B1_PS_SETTING_PS_SETTING_CONTROL_FIELD_PS_REQUEST_MODE_MASK                                               0x00000004
#define B1_PS_SETTING_PS_SETTING_CONTROL_FIELD_PS_REQUEST_TWT_AVAIL_EN_MASK                                       0x00000008
#define B1_PS_SETTING_PS_SETTING_CONTROL_FIELD_PS_REQUEST_NFRP_EN_MASK                                            0x00000010
#define B1_PS_SETTING_PS_SETTING_CONTROL_FIELD_NDP_NON_ACKABLE_PD_TYPE_TWT_MASK                                   0x00000020
#define B1_PS_SETTING_PS_SETTING_CONTROL_FIELD_NDP_NON_ACKABLE_PD_TYPE_NO_TWT_MASK                                0x00000040
//========================================
/* REG_PS_SETTING_PS_VAP_DISABLE 0x4 */
#define B1_PS_SETTING_PS_VAP_DISABLE_FIELD_PS_VAP_DISABLE_MASK                                                    0xFFFFFFFF
//========================================
/* REG_PS_SETTING_PD_NDP_TX_PD_LIST_IDX 0x8 */
#define B1_PS_SETTING_PD_NDP_TX_PD_LIST_IDX_FIELD_PD_NDP_TX_PD_LIST_IDX_MASK                                      0x0000007F
//========================================
/* REG_PS_SETTING_PS_STATUS_CHANGE_STA_0TO31_NOTIFY_EN 0x10 */
#define B1_PS_SETTING_PS_STATUS_CHANGE_STA_0TO31_NOTIFY_EN_FIELD_PS_STATUS_CHANGE_STA_0TO31_NOTIFY_EN_MASK        0xFFFFFFFF
//========================================
/* REG_PS_SETTING_PS_STATUS_CHANGE_STA_32TO63_NOTIFY_EN 0x14 */
#define B1_PS_SETTING_PS_STATUS_CHANGE_STA_32TO63_NOTIFY_EN_FIELD_PS_STATUS_CHANGE_STA_32TO63_NOTIFY_EN_MASK      0xFFFFFFFF
//========================================
/* REG_PS_SETTING_PS_STATUS_CHANGE_STA_64TO95_NOTIFY_EN 0x18 */
#define B1_PS_SETTING_PS_STATUS_CHANGE_STA_64TO95_NOTIFY_EN_FIELD_PS_STATUS_CHANGE_STA_64TO95_NOTIFY_EN_MASK      0xFFFFFFFF
//========================================
/* REG_PS_SETTING_PS_STATUS_CHANGE_STA_96TO127_NOTIFY_EN 0x1C */
#define B1_PS_SETTING_PS_STATUS_CHANGE_STA_96TO127_NOTIFY_EN_FIELD_PS_STATUS_CHANGE_STA_96TO127_NOTIFY_EN_MASK    0xFFFFFFFF
//========================================
/* REG_PS_SETTING_PS_STATUS_CHANGE_STA_128TO159_NOTIFY_EN 0x20 */
#define B1_PS_SETTING_PS_STATUS_CHANGE_STA_128TO159_NOTIFY_EN_FIELD_PS_STATUS_CHANGE_STA_128TO159_NOTIFY_EN_MASK  0xFFFFFFFF
//========================================
/* REG_PS_SETTING_PS_STATUS_CHANGE_STA_160TO191_NOTIFY_EN 0x24 */
#define B1_PS_SETTING_PS_STATUS_CHANGE_STA_160TO191_NOTIFY_EN_FIELD_PS_STATUS_CHANGE_STA_160TO191_NOTIFY_EN_MASK  0xFFFFFFFF
//========================================
/* REG_PS_SETTING_PS_STATUS_CHANGE_STA_192TO223_NOTIFY_EN 0x28 */
#define B1_PS_SETTING_PS_STATUS_CHANGE_STA_192TO223_NOTIFY_EN_FIELD_PS_STATUS_CHANGE_STA_192TO223_NOTIFY_EN_MASK  0xFFFFFFFF
//========================================
/* REG_PS_SETTING_PS_STATUS_CHANGE_STA_224TO255_NOTIFY_EN 0x2C */
#define B1_PS_SETTING_PS_STATUS_CHANGE_STA_224TO255_NOTIFY_EN_FIELD_PS_STATUS_CHANGE_STA_224TO255_NOTIFY_EN_MASK  0xFFFFFFFF
//========================================
/* REG_PS_SETTING_PS_FW_NOTIFICATION_EN 0x30 */
#define B1_PS_SETTING_PS_FW_NOTIFICATION_EN_FIELD_NDP_TX_PD_EMPTY_NOTIFY_EN_MASK                                  0x00000001
#define B1_PS_SETTING_PS_FW_NOTIFICATION_EN_FIELD_PS_POLL_FC_PM_ZERO_NOTIFY_EN_MASK                               0x00000002
#define B1_PS_SETTING_PS_FW_NOTIFICATION_EN_FIELD_PS_POLL_NO_MATCH_AID_NOTIFY_EN_MASK                             0x00000004
#define B1_PS_SETTING_PS_FW_NOTIFICATION_EN_FIELD_SKIP_PUSH_NDP_NO_SU_TID_FORWARD_FW_EN_MASK                      0x00000008
//========================================
/* REG_PS_SETTING_PS_FIFO_BASE_ADDR 0x40 */
#define B1_PS_SETTING_PS_FIFO_BASE_ADDR_FIELD_PS_FIFO_BASE_ADDR_MASK                                              0x003FFFFF
//========================================
/* REG_PS_SETTING_PS_FIFO_DEPTH_MINUS_ONE 0x44 */
#define B1_PS_SETTING_PS_FIFO_DEPTH_MINUS_ONE_FIELD_PS_FIFO_DEPTH_MINUS_ONE_MASK                                  0x000000FF
//========================================
/* REG_PS_SETTING_PS_FIFO_CLEAR_STRB 0x48 */
#define B1_PS_SETTING_PS_FIFO_CLEAR_STRB_FIELD_PS_FIFO_CLEAR_STRB_MASK                                            0x00000001
#define B1_PS_SETTING_PS_FIFO_CLEAR_STRB_FIELD_PS_FIFO_CLEAR_FULL_DROP_CTR_STRB_MASK                              0x00000002
//========================================
/* REG_PS_SETTING_PS_FIFO_RD_ENTRIES_NUM 0x4C */
#define B1_PS_SETTING_PS_FIFO_RD_ENTRIES_NUM_FIELD_PS_FIFO_RD_ENTRIES_NUM_MASK                                    0x000001FF
//========================================
/* REG_PS_SETTING_PS_FIFO_NUM_ENTRIES_COUNT 0x50 */
#define B1_PS_SETTING_PS_FIFO_NUM_ENTRIES_COUNT_FIELD_PS_FIFO_NUM_ENTRIES_COUNT_MASK                              0x000001FF
//========================================
/* REG_PS_SETTING_PS_FIFO_DEBUG 0x54 */
#define B1_PS_SETTING_PS_FIFO_DEBUG_FIELD_PS_FIFO_WR_PTR_MASK                                                     0x000000FF
#define B1_PS_SETTING_PS_FIFO_DEBUG_FIELD_PS_FIFO_NOT_EMPTY_MASK                                                  0x00010000
#define B1_PS_SETTING_PS_FIFO_DEBUG_FIELD_PS_FIFO_FULL_MASK                                                       0x00020000
#define B1_PS_SETTING_PS_FIFO_DEBUG_FIELD_PS_FIFO_FULL_DROP_CTR_MASK                                              0xFF000000
//========================================
/* REG_PS_SETTING_PS_DEBUG 0x58 */
#define B1_PS_SETTING_PS_DEBUG_FIELD_PS_STATE_MACHINE_MASK                                                        0x0000001F
#define B1_PS_SETTING_PS_DEBUG_FIELD_PS_WRP_SM_MASK                                                               0x000000E0
#define B1_PS_SETTING_PS_DEBUG_FIELD_PS_SHRAM_IF_SM_MASK                                                          0x00000700
#define B1_PS_SETTING_PS_DEBUG_FIELD_LOGGER_SM_MASK                                                               0x00003800
//========================================
/* REG_PS_SETTING_PS_LOGGER 0x5C */
#define B1_PS_SETTING_PS_LOGGER_FIELD_PS_LOGGER_EN_MASK                                                           0x00000001
#define B1_PS_SETTING_PS_LOGGER_FIELD_PS_LOGGER_PRIORITY_MASK                                                     0x00000300
//========================================
/* REG_PS_SETTING_PS_LOGGER_ACTIVE 0x60 */
#define B1_PS_SETTING_PS_LOGGER_ACTIVE_FIELD_PS_LOGGER_ACTIVE_MASK                                                0x00000001
//========================================
/* REG_PS_SETTING_PS_SETTING_ERR_IRQ_EN 0x64 */
#define B1_PS_SETTING_PS_SETTING_ERR_IRQ_EN_FIELD_START_NEW_RX_SESSION_WHILE_WAIT_AUTO_RESP_IRQ_EN_MASK           0x00000001
#define B1_PS_SETTING_PS_SETTING_ERR_IRQ_EN_FIELD_START_NEW_RX_SESSION_WHILE_PS_SETTING_ACTIVE_IRQ_EN_MASK        0x00000002
#define B1_PS_SETTING_PS_SETTING_ERR_IRQ_EN_FIELD_PS_SETTING_FIFO_DECREMENT_LESS_THAN_ZERO_IRQ_EN_MASK            0x00000004
#define B1_PS_SETTING_PS_SETTING_ERR_IRQ_EN_FIELD_PS_SETTING_FIFO_FULL_DROP_IRQ_EN_MASK                           0x00000008
//========================================
/* REG_PS_SETTING_PS_SETTING_ERR_IRQ_CLR 0x68 */
#define B1_PS_SETTING_PS_SETTING_ERR_IRQ_CLR_FIELD_START_NEW_RX_SESSION_WHILE_WAIT_AUTO_RESP_IRQ_CLR_MASK         0x00000001
#define B1_PS_SETTING_PS_SETTING_ERR_IRQ_CLR_FIELD_START_NEW_RX_SESSION_WHILE_PS_SETTING_ACTIVE_IRQ_CLR_MASK      0x00000002
#define B1_PS_SETTING_PS_SETTING_ERR_IRQ_CLR_FIELD_PS_SETTING_FIFO_DECREMENT_LESS_THAN_ZERO_IRQ_CLR_MASK          0x00000004
//========================================
/* REG_PS_SETTING_PS_SETTING_ERR_IRQ_STATUS 0x6C */
#define B1_PS_SETTING_PS_SETTING_ERR_IRQ_STATUS_FIELD_START_NEW_RX_SESSION_WHILE_WAIT_AUTO_RESP_IRQ_MASK          0x00000001
#define B1_PS_SETTING_PS_SETTING_ERR_IRQ_STATUS_FIELD_START_NEW_RX_SESSION_WHILE_PS_SETTING_ACTIVE_IRQ_MASK       0x00000002
#define B1_PS_SETTING_PS_SETTING_ERR_IRQ_STATUS_FIELD_PS_SETTING_FIFO_DECREMENT_LESS_THAN_ZERO_IRQ_MASK           0x00000004
#define B1_PS_SETTING_PS_SETTING_ERR_IRQ_STATUS_FIELD_PS_SETTING_FIFO_FULL_DROP_IRQ_MASK                          0x00000008
//========================================
/* REG_PS_SETTING_PS_STATUS_CHANGE_STA_0TO31_PS_REQ_NOTIFY_EN 0x70 */
#define B1_PS_SETTING_PS_STATUS_CHANGE_STA_0TO31_PS_REQ_NOTIFY_EN_FIELD_PS_STATUS_CHANGE_STA_0TO31_PS_REQ_NOTIFY_EN_MASK 0xFFFFFFFF
//========================================
/* REG_PS_SETTING_PS_STATUS_CHANGE_STA_32TO63_PS_REQ_NOTIFY_EN 0x74 */
#define B1_PS_SETTING_PS_STATUS_CHANGE_STA_32TO63_PS_REQ_NOTIFY_EN_FIELD_PS_STATUS_CHANGE_STA_32TO63_PS_REQ_NOTIFY_EN_MASK 0xFFFFFFFF
//========================================
/* REG_PS_SETTING_PS_STATUS_CHANGE_STA_64TO95_PS_REQ_NOTIFY_EN 0x78 */
#define B1_PS_SETTING_PS_STATUS_CHANGE_STA_64TO95_PS_REQ_NOTIFY_EN_FIELD_PS_STATUS_CHANGE_STA_64TO95_PS_REQ_NOTIFY_EN_MASK 0xFFFFFFFF
//========================================
/* REG_PS_SETTING_PS_STATUS_CHANGE_STA_96TO127_PS_REQ_NOTIFY_EN 0x7C */
#define B1_PS_SETTING_PS_STATUS_CHANGE_STA_96TO127_PS_REQ_NOTIFY_EN_FIELD_PS_STATUS_CHANGE_STA_96TO127_PS_REQ_NOTIFY_EN_MASK 0xFFFFFFFF
//========================================
/* REG_PS_SETTING_PS_STATUS_CHANGE_STA_128TO159_PS_REQ_NOTIFY_EN 0x80 */
#define B1_PS_SETTING_PS_STATUS_CHANGE_STA_128TO159_PS_REQ_NOTIFY_EN_FIELD_PS_STATUS_CHANGE_STA_128TO159_PS_REQ_NOTIFY_EN_MASK 0xFFFFFFFF
//========================================
/* REG_PS_SETTING_PS_STATUS_CHANGE_STA_160TO191_PS_REQ_NOTIFY_EN 0x84 */
#define B1_PS_SETTING_PS_STATUS_CHANGE_STA_160TO191_PS_REQ_NOTIFY_EN_FIELD_PS_STATUS_CHANGE_STA_160TO191_PS_REQ_NOTIFY_EN_MASK 0xFFFFFFFF
//========================================
/* REG_PS_SETTING_PS_STATUS_CHANGE_STA_192TO223_PS_REQ_NOTIFY_EN 0x88 */
#define B1_PS_SETTING_PS_STATUS_CHANGE_STA_192TO223_PS_REQ_NOTIFY_EN_FIELD_PS_STATUS_CHANGE_STA_192TO223_PS_REQ_NOTIFY_EN_MASK 0xFFFFFFFF
//========================================
/* REG_PS_SETTING_PS_STATUS_CHANGE_STA_224TO255_PS_REQ_NOTIFY_EN 0x8C */
#define B1_PS_SETTING_PS_STATUS_CHANGE_STA_224TO255_PS_REQ_NOTIFY_EN_FIELD_PS_STATUS_CHANGE_STA_224TO255_PS_REQ_NOTIFY_EN_MASK 0xFFFFFFFF


#endif // _PS_SETTING_REGS_H_
