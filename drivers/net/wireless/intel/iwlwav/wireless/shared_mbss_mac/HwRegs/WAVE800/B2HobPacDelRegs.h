
/***********************************************************************************
File:				B2HobPacDelRegs.h
Module:				b2HobPacDel
SOC Revision:		latest
Generated at:       2024-06-26 12:54:49
Purpose:
Description:		This File was auto generated using SOC Online

************************************************************************************/
#ifndef _B2_HOB_PAC_DEL_REGS_H_
#define _B2_HOB_PAC_DEL_REGS_H_

/*---------------------------------------------------------------------------------
/						Registers Addresses													 
/----------------------------------------------------------------------------------*/
#include "HwMemoryMap.h"

#define B2_HOB_PAC_DEL_BASE_ADDRESS                  MEMORY_MAP_UNIT_20503_BASE_ADDRESS
#define	REG_B2_HOB_PAC_DEL_HOB_DEL_COUNTER0_EVENT         (B2_HOB_PAC_DEL_BASE_ADDRESS + 0x0)
#define	REG_B2_HOB_PAC_DEL_HOB_DEL_COUNTER1_EVENT         (B2_HOB_PAC_DEL_BASE_ADDRESS + 0x4)
#define	REG_B2_HOB_PAC_DEL_NOP_WAIT_EVENT_VECTOR          (B2_HOB_PAC_DEL_BASE_ADDRESS + 0x8)
#define	REG_B2_HOB_PAC_DEL_TX_DATA_STRUCTURE_ADDR         (B2_HOB_PAC_DEL_BASE_ADDRESS + 0xC)
#define	REG_B2_HOB_PAC_DEL_DEL2GENRISC_START_TX_INT       (B2_HOB_PAC_DEL_BASE_ADDRESS + 0x10)
#define	REG_B2_HOB_PAC_DEL_PRBS_DATA                      (B2_HOB_PAC_DEL_BASE_ADDRESS + 0x18)
#define	REG_B2_HOB_PAC_DEL_PHY_MODE                       (B2_HOB_PAC_DEL_BASE_ADDRESS + 0x1C)
#define	REG_B2_HOB_PAC_DEL_BF_TX_MAX_THRESHOLD_TIMER      (B2_HOB_PAC_DEL_BASE_ADDRESS + 0x20)
#define	REG_B2_HOB_PAC_DEL_ZLD_VAL                        (B2_HOB_PAC_DEL_BASE_ADDRESS + 0x24)
#define	REG_B2_HOB_PAC_DEL_DEL_TXC_RESP_TIMEOUT_VALUE     (B2_HOB_PAC_DEL_BASE_ADDRESS + 0x28)
#define	REG_B2_HOB_PAC_DEL_RX_LAST_MPDU_IN_PTR            (B2_HOB_PAC_DEL_BASE_ADDRESS + 0x2C)
#define	REG_B2_HOB_PAC_DEL_CTR_DATA                       (B2_HOB_PAC_DEL_BASE_ADDRESS + 0x34)
#define	REG_B2_HOB_PAC_DEL_LOGGER_HOB_INFO                (B2_HOB_PAC_DEL_BASE_ADDRESS + 0x38)
#define	REG_B2_HOB_PAC_DEL_HT_DELIMITER_DATA_IN           (B2_HOB_PAC_DEL_BASE_ADDRESS + 0x3C)
#define	REG_B2_HOB_PAC_DEL_VHT_DELIMITER_DATA_IN          (B2_HOB_PAC_DEL_BASE_ADDRESS + 0x40)
#define	REG_B2_HOB_PAC_DEL_VHT_EOF_DELIMITER_DATA_IN      (B2_HOB_PAC_DEL_BASE_ADDRESS + 0x44)
#define	REG_B2_HOB_PAC_DEL_DELIMITER_DATA_OUT             (B2_HOB_PAC_DEL_BASE_ADDRESS + 0x48)
#define	REG_B2_HOB_PAC_DEL_DELIA_EVENT_THRESHOLD_TIMER    (B2_HOB_PAC_DEL_BASE_ADDRESS + 0x4C)
#define	REG_B2_HOB_PAC_DEL_TIM_DEL_EVENT_TIMER_EXPIRED    (B2_HOB_PAC_DEL_BASE_ADDRESS + 0x50)
#define	REG_B2_HOB_PAC_DEL_TCR_TXOP_DUR_FROM_MAC          (B2_HOB_PAC_DEL_BASE_ADDRESS + 0x54)
#define	REG_B2_HOB_PAC_DEL_DELIA_TX_MPDU_DUR_FIELD        (B2_HOB_PAC_DEL_BASE_ADDRESS + 0x5C)
#define	REG_B2_HOB_PAC_DEL_PAC_PHY_TX_LENGTH_ZERO         (B2_HOB_PAC_DEL_BASE_ADDRESS + 0x60)
#define	REG_B2_HOB_PAC_DEL_DELIMITER_VALUE_PRE_TX_DATA    (B2_HOB_PAC_DEL_BASE_ADDRESS + 0x64)
#define	REG_B2_HOB_PAC_DEL_NUM_OF_USER_TCRS               (B2_HOB_PAC_DEL_BASE_ADDRESS + 0x68)
#define	REG_B2_HOB_PAC_DEL_NUM_OF_USER_TCR_BYTES          (B2_HOB_PAC_DEL_BASE_ADDRESS + 0x6C)
#define	REG_B2_HOB_PAC_DEL_EXPECTED_RCRS                  (B2_HOB_PAC_DEL_BASE_ADDRESS + 0x70)
#define	REG_B2_HOB_PAC_DEL_NUM_OF_USER_RCR_BYTES          (B2_HOB_PAC_DEL_BASE_ADDRESS + 0x74)
#define	REG_B2_HOB_PAC_DEL_TX_CIR_BUF_BASE_ADDR           (B2_HOB_PAC_DEL_BASE_ADDRESS + 0x78)
#define	REG_B2_HOB_PAC_DEL_REG2HOB_GP0                    (B2_HOB_PAC_DEL_BASE_ADDRESS + 0x7C)
#define	REG_B2_HOB_PAC_DEL_REG2HOB_GP1                    (B2_HOB_PAC_DEL_BASE_ADDRESS + 0x80)
#define	REG_B2_HOB_PAC_DEL_TCR_BASE_ADDR1                 (B2_HOB_PAC_DEL_BASE_ADDRESS + 0x84)
#define	REG_B2_HOB_PAC_DEL_TCR_BASE_ADDR2                 (B2_HOB_PAC_DEL_BASE_ADDRESS + 0x88)
#define	REG_B2_HOB_PAC_DEL_RCR_BASE_ADDR                  (B2_HOB_PAC_DEL_BASE_ADDRESS + 0x8C)
#define	REG_B2_HOB_PAC_DEL_SENDER_MPDU_DURATION           (B2_HOB_PAC_DEL_BASE_ADDRESS + 0x90)
#define	REG_B2_HOB_PAC_DEL_ALL_ONES_PADDING               (B2_HOB_PAC_DEL_BASE_ADDRESS + 0x94)
#define	REG_B2_HOB_PAC_DEL_TCC_CRC                        (B2_HOB_PAC_DEL_BASE_ADDRESS + 0x98)
/*---------------------------------------------------------------------------------
/						Data Type Definition										
/----------------------------------------------------------------------------------*/
/*REG_B2_HOB_PAC_DEL_HOB_DEL_COUNTER0_EVENT 0x0 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 hobDelCounter0Event : 12; //no description, reset value: 0x0, access type: RW
		uint32 reserved0 : 20;
	} bitFields;
} RegB2HobPacDelHobDelCounter0Event_u;

/*REG_B2_HOB_PAC_DEL_HOB_DEL_COUNTER1_EVENT 0x4 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 hobDelCounter1Event : 12; //no description, reset value: 0x0, access type: RW
		uint32 reserved0 : 20;
	} bitFields;
} RegB2HobPacDelHobDelCounter1Event_u;

/*REG_B2_HOB_PAC_DEL_NOP_WAIT_EVENT_VECTOR 0x8 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 nopWaitEventVector : 22; //no description, reset value: 0x0, access type: RO
		uint32 reserved0 : 10;
	} bitFields;
} RegB2HobPacDelNopWaitEventVector_u;

/*REG_B2_HOB_PAC_DEL_TX_DATA_STRUCTURE_ADDR 0xC */
typedef union
{
	uint32 val;
	struct
	{
		uint32 txDataStructureAddr : 26; //no description, reset value: 0x0, access type: RO
		uint32 reserved0 : 6;
	} bitFields;
} RegB2HobPacDelTxDataStructureAddr_u;

/*REG_B2_HOB_PAC_DEL_DEL2GENRISC_START_TX_INT 0x10 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 del2GenriscStartTxInt : 6; //no description, reset value: 0x0, access type: RW
		uint32 reserved0 : 26;
	} bitFields;
} RegB2HobPacDelDel2GenriscStartTxInt_u;

/*REG_B2_HOB_PAC_DEL_PRBS_DATA 0x18 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 prbsData : 8; //no description, reset value: 0x0, access type: RO
		uint32 reserved0 : 24;
	} bitFields;
} RegB2HobPacDelPrbsData_u;

/*REG_B2_HOB_PAC_DEL_PHY_MODE 0x1C */
typedef union
{
	uint32 val;
	struct
	{
		uint32 pacPhy11AgMode : 1; //no description, reset value: 0x0, access type: RO
		uint32 pacPhy11BMode : 1; //no description, reset value: 0x0, access type: RO
		uint32 pacPhy11NMode : 1; //no description, reset value: 0x0, access type: RO
		uint32 pacPhy11AcMode : 1; //no description, reset value: 0x0, access type: RO
		uint32 pacPhyHeSu : 1; //no description, reset value: 0x0, access type: RO
		uint32 pacPhyHeExSu : 1; //no description, reset value: 0x0, access type: RO
		uint32 pacPhyHeMuTf : 1; //no description, reset value: 0x0, access type: RO
		uint32 pacPhyHeMu : 1; //no description, reset value: 0x0, access type: RO
		uint32 pacPhyEhtSu : 1; //no description, reset value: 0x0, access type: RW
		uint32 pacPhyEhtMuTf : 1; //no description, reset value: 0x0, access type: RW
		uint32 pacPhyEhtMu : 1; //no description, reset value: 0x0, access type: RW
		uint32 pacPhyVhtHeEht : 1; //no description, reset value: 0x0, access type: RO
		uint32 reserved0 : 20;
	} bitFields;
} RegB2HobPacDelPhyMode_u;

/*REG_B2_HOB_PAC_DEL_BF_TX_MAX_THRESHOLD_TIMER 0x20 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 bfTxMaxThresholdTimer : 10; //no description, reset value: 0x0, access type: RO
		uint32 reserved0 : 22;
	} bitFields;
} RegB2HobPacDelBfTxMaxThresholdTimer_u;

/*REG_B2_HOB_PAC_DEL_ZLD_VAL 0x24 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 zldVal : 32; //no description, reset value: 0x0, access type: RO
	} bitFields;
} RegB2HobPacDelZldVal_u;

/*REG_B2_HOB_PAC_DEL_DEL_TXC_RESP_TIMEOUT_VALUE 0x28 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 delTxcRespTimeoutValue : 13; //no description, reset value: 0x0, access type: RW
		uint32 reserved0 : 19;
	} bitFields;
} RegB2HobPacDelDelTxcRespTimeoutValue_u;

/*REG_B2_HOB_PAC_DEL_RX_LAST_MPDU_IN_PTR 0x2C */
typedef union
{
	uint32 val;
	struct
	{
		uint32 rxLastMpduInPtr : 25; //no description, reset value: 0x0, access type: RO
		uint32 reserved0 : 7;
	} bitFields;
} RegB2HobPacDelRxLastMpduInPtr_u;

/*REG_B2_HOB_PAC_DEL_CTR_DATA 0x34 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 ctrData : 8; //no description, reset value: 0x0, access type: RO
		uint32 reserved0 : 24;
	} bitFields;
} RegB2HobPacDelCtrData_u;

/*REG_B2_HOB_PAC_DEL_LOGGER_HOB_INFO 0x38 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 loggerHobInfo : 8; //no description, reset value: 0x0, access type: RW
		uint32 reserved0 : 24;
	} bitFields;
} RegB2HobPacDelLoggerHobInfo_u;

/*REG_B2_HOB_PAC_DEL_HT_DELIMITER_DATA_IN 0x3C */
typedef union
{
	uint32 val;
	struct
	{
		uint32 delimiterDataIn : 16; //no description, reset value: 0x0, access type: RW
		uint32 reserved0 : 16;
	} bitFields;
} RegB2HobPacDelHtDelimiterDataIn_u;

/*REG_B2_HOB_PAC_DEL_VHT_DELIMITER_DATA_IN 0x40 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 delimiterDataIn : 16; //no description, reset value: 0x0, access type: RW
		uint32 reserved0 : 16;
	} bitFields;
} RegB2HobPacDelVhtDelimiterDataIn_u;

/*REG_B2_HOB_PAC_DEL_VHT_EOF_DELIMITER_DATA_IN 0x44 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 delimiterDataIn : 16; //no description, reset value: 0x0, access type: RW
		uint32 reserved0 : 16;
	} bitFields;
} RegB2HobPacDelVhtEofDelimiterDataIn_u;

/*REG_B2_HOB_PAC_DEL_DELIMITER_DATA_OUT 0x48 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 delimiterDataOut : 32; //no description, reset value: 0x0, access type: RO
	} bitFields;
} RegB2HobPacDelDelimiterDataOut_u;

/*REG_B2_HOB_PAC_DEL_DELIA_EVENT_THRESHOLD_TIMER 0x4C */
typedef union
{
	uint32 val;
	struct
	{
		uint32 deliaEventThresholdTimer : 24; //no description, reset value: 0x0, access type: RW
		uint32 reserved0 : 8;
	} bitFields;
} RegB2HobPacDelDeliaEventThresholdTimer_u;

/*REG_B2_HOB_PAC_DEL_TIM_DEL_EVENT_TIMER_EXPIRED 0x50 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 timDelEventTimerExpired : 1; //no description, reset value: 0x0, access type: RO
		uint32 reserved0 : 31;
	} bitFields;
} RegB2HobPacDelTimDelEventTimerExpired_u;

/*REG_B2_HOB_PAC_DEL_TCR_TXOP_DUR_FROM_MAC 0x54 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 tcrTxopDurFromMac : 1; //no description, reset value: 0x0, access type: RO
		uint32 reserved0 : 31;
	} bitFields;
} RegB2HobPacDelTcrTxopDurFromMac_u;

/*REG_B2_HOB_PAC_DEL_DELIA_TX_MPDU_DUR_FIELD 0x5C */
typedef union
{
	uint32 val;
	struct
	{
		uint32 txMpduDurField : 16; //no description, reset value: 0x0, access type: RO
		uint32 reserved0 : 16;
	} bitFields;
} RegB2HobPacDelDeliaTxMpduDurField_u;

/*REG_B2_HOB_PAC_DEL_PAC_PHY_TX_LENGTH_ZERO 0x60 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 pacPhyTxLengthZero : 1; //no description, reset value: 0x0, access type: RO
		uint32 reserved0 : 31;
	} bitFields;
} RegB2HobPacDelPacPhyTxLengthZero_u;

/*REG_B2_HOB_PAC_DEL_DELIMITER_VALUE_PRE_TX_DATA 0x64 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 delimiterValuePreTxData : 32; //no description, reset value: 0x0, access type: RO
	} bitFields;
} RegB2HobPacDelDelimiterValuePreTxData_u;

/*REG_B2_HOB_PAC_DEL_NUM_OF_USER_TCRS 0x68 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 numOfUserTcrs : 8; //no description, reset value: 0x0, access type: RO
		uint32 reserved0 : 24;
	} bitFields;
} RegB2HobPacDelNumOfUserTcrs_u;

/*REG_B2_HOB_PAC_DEL_NUM_OF_USER_TCR_BYTES 0x6C */
typedef union
{
	uint32 val;
	struct
	{
		uint32 numOfUserTcrBytes : 12; //no description, reset value: 0x0, access type: RO
		uint32 reserved0 : 20;
	} bitFields;
} RegB2HobPacDelNumOfUserTcrBytes_u;

/*REG_B2_HOB_PAC_DEL_EXPECTED_RCRS 0x70 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 expectedRcrs : 1; //no description, reset value: 0x0, access type: RO
		uint32 reserved0 : 31;
	} bitFields;
} RegB2HobPacDelExpectedRcrs_u;

/*REG_B2_HOB_PAC_DEL_NUM_OF_USER_RCR_BYTES 0x74 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 numOfUserRcrBytes : 12; //no description, reset value: 0x0, access type: RO
		uint32 reserved0 : 20;
	} bitFields;
} RegB2HobPacDelNumOfUserRcrBytes_u;

/*REG_B2_HOB_PAC_DEL_TX_CIR_BUF_BASE_ADDR 0x78 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 txCirBufBaseAddr : 32; //no description, reset value: 0x0, access type: RO
	} bitFields;
} RegB2HobPacDelTxCirBufBaseAddr_u;

/*REG_B2_HOB_PAC_DEL_REG2HOB_GP0 0x7C */
typedef union
{
	uint32 val;
	struct
	{
		uint32 reg2HobGp0 : 32; //no description, reset value: 0x0, access type: RO
	} bitFields;
} RegB2HobPacDelReg2HobGp0_u;

/*REG_B2_HOB_PAC_DEL_REG2HOB_GP1 0x80 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 reg2HobGp1 : 32; //no description, reset value: 0x0, access type: RO
	} bitFields;
} RegB2HobPacDelReg2HobGp1_u;

/*REG_B2_HOB_PAC_DEL_TCR_BASE_ADDR1 0x84 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 tcrBaseAddr2 : 26; //no description, reset value: 0x0, access type: RO
		uint32 reserved0 : 6;
	} bitFields;
} RegB2HobPacDelTcrBaseAddr1_u;

/*REG_B2_HOB_PAC_DEL_TCR_BASE_ADDR2 0x88 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 tcrBaseAddr2 : 26; //no description, reset value: 0x0, access type: RO
		uint32 reserved0 : 6;
	} bitFields;
} RegB2HobPacDelTcrBaseAddr2_u;

/*REG_B2_HOB_PAC_DEL_RCR_BASE_ADDR 0x8C */
typedef union
{
	uint32 val;
	struct
	{
		uint32 rcrBaseAddr : 26; //no description, reset value: 0x0, access type: RO
		uint32 reserved0 : 6;
	} bitFields;
} RegB2HobPacDelRcrBaseAddr_u;

/*REG_B2_HOB_PAC_DEL_SENDER_MPDU_DURATION 0x90 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 senderMpduDuration : 16; //no description, reset value: 0x0, access type: RO
		uint32 reserved0 : 16;
	} bitFields;
} RegB2HobPacDelSenderMpduDuration_u;

/*REG_B2_HOB_PAC_DEL_ALL_ONES_PADDING 0x94 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 allOnesPadding : 32; //no description, reset value: 0xffffffff, access type: RO
	} bitFields;
} RegB2HobPacDelAllOnesPadding_u;

/*REG_B2_HOB_PAC_DEL_TCC_CRC 0x98 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 tccCrc : 32; //no description, reset value: 0x0, access type: RO
	} bitFields;
} RegB2HobPacDelTccCrc_u;

//========================================
/* REG_HOB_PAC_DEL_HOB_DEL_COUNTER0_EVENT 0x0 */
#define B2_HOB_PAC_DEL_HOB_DEL_COUNTER0_EVENT_FIELD_HOB_DEL_COUNTER0_EVENT_MASK                                   0x00000FFF
//========================================
/* REG_HOB_PAC_DEL_HOB_DEL_COUNTER1_EVENT 0x4 */
#define B2_HOB_PAC_DEL_HOB_DEL_COUNTER1_EVENT_FIELD_HOB_DEL_COUNTER1_EVENT_MASK                                   0x00000FFF
//========================================
/* REG_HOB_PAC_DEL_NOP_WAIT_EVENT_VECTOR 0x8 */
#define B2_HOB_PAC_DEL_NOP_WAIT_EVENT_VECTOR_FIELD_NOP_WAIT_EVENT_VECTOR_MASK                                     0x003FFFFF
//========================================
/* REG_HOB_PAC_DEL_TX_DATA_STRUCTURE_ADDR 0xC */
#define B2_HOB_PAC_DEL_TX_DATA_STRUCTURE_ADDR_FIELD_TX_DATA_STRUCTURE_ADDR_MASK                                   0x03FFFFFF
//========================================
/* REG_HOB_PAC_DEL_DEL2GENRISC_START_TX_INT 0x10 */
#define B2_HOB_PAC_DEL_DEL2GENRISC_START_TX_INT_FIELD_DEL2GENRISC_START_TX_INT_MASK                               0x0000003F
//========================================
/* REG_HOB_PAC_DEL_PRBS_DATA 0x18 */
#define B2_HOB_PAC_DEL_PRBS_DATA_FIELD_PRBS_DATA_MASK                                                             0x000000FF
//========================================
/* REG_HOB_PAC_DEL_PHY_MODE 0x1C */
#define B2_HOB_PAC_DEL_PHY_MODE_FIELD_PAC_PHY_11AG_MODE_MASK                                                      0x00000001
#define B2_HOB_PAC_DEL_PHY_MODE_FIELD_PAC_PHY_11B_MODE_MASK                                                       0x00000002
#define B2_HOB_PAC_DEL_PHY_MODE_FIELD_PAC_PHY_11N_MODE_MASK                                                       0x00000004
#define B2_HOB_PAC_DEL_PHY_MODE_FIELD_PAC_PHY_11AC_MODE_MASK                                                      0x00000008
#define B2_HOB_PAC_DEL_PHY_MODE_FIELD_PAC_PHY_HE_SU_MASK                                                          0x00000010
#define B2_HOB_PAC_DEL_PHY_MODE_FIELD_PAC_PHY_HE_EX_SU_MASK                                                       0x00000020
#define B2_HOB_PAC_DEL_PHY_MODE_FIELD_PAC_PHY_HE_MU_TF_MASK                                                       0x00000040
#define B2_HOB_PAC_DEL_PHY_MODE_FIELD_PAC_PHY_HE_MU_MASK                                                          0x00000080
#define B2_HOB_PAC_DEL_PHY_MODE_FIELD_PAC_PHY_EHT_SU_MASK                                                         0x00000100
#define B2_HOB_PAC_DEL_PHY_MODE_FIELD_PAC_PHY_EHT_MU_TF_MASK                                                      0x00000200
#define B2_HOB_PAC_DEL_PHY_MODE_FIELD_PAC_PHY_EHT_MU_MASK                                                         0x00000400
#define B2_HOB_PAC_DEL_PHY_MODE_FIELD_PAC_PHY_VHT_HE_EHT_MASK                                                     0x00000800
//========================================
/* REG_HOB_PAC_DEL_BF_TX_MAX_THRESHOLD_TIMER 0x20 */
#define B2_HOB_PAC_DEL_BF_TX_MAX_THRESHOLD_TIMER_FIELD_BF_TX_MAX_THRESHOLD_TIMER_MASK                             0x000003FF
//========================================
/* REG_HOB_PAC_DEL_ZLD_VAL 0x24 */
#define B2_HOB_PAC_DEL_ZLD_VAL_FIELD_ZLD_VAL_MASK                                                                 0xFFFFFFFF
//========================================
/* REG_HOB_PAC_DEL_DEL_TXC_RESP_TIMEOUT_VALUE 0x28 */
#define B2_HOB_PAC_DEL_DEL_TXC_RESP_TIMEOUT_VALUE_FIELD_DEL_TXC_RESP_TIMEOUT_VALUE_MASK                           0x00001FFF
//========================================
/* REG_HOB_PAC_DEL_RX_LAST_MPDU_IN_PTR 0x2C */
#define B2_HOB_PAC_DEL_RX_LAST_MPDU_IN_PTR_FIELD_RX_LAST_MPDU_IN_PTR_MASK                                         0x01FFFFFF
//========================================
/* REG_HOB_PAC_DEL_CTR_DATA 0x34 */
#define B2_HOB_PAC_DEL_CTR_DATA_FIELD_CTR_DATA_MASK                                                               0x000000FF
//========================================
/* REG_HOB_PAC_DEL_LOGGER_HOB_INFO 0x38 */
#define B2_HOB_PAC_DEL_LOGGER_HOB_INFO_FIELD_LOGGER_HOB_INFO_MASK                                                 0x000000FF
//========================================
/* REG_HOB_PAC_DEL_HT_DELIMITER_DATA_IN 0x3C */
#define B2_HOB_PAC_DEL_HT_DELIMITER_DATA_IN_FIELD_DELIMITER_DATA_IN_MASK                                          0x0000FFFF
//========================================
/* REG_HOB_PAC_DEL_VHT_DELIMITER_DATA_IN 0x40 */
#define B2_HOB_PAC_DEL_VHT_DELIMITER_DATA_IN_FIELD_DELIMITER_DATA_IN_MASK                                         0x0000FFFF
//========================================
/* REG_HOB_PAC_DEL_VHT_EOF_DELIMITER_DATA_IN 0x44 */
#define B2_HOB_PAC_DEL_VHT_EOF_DELIMITER_DATA_IN_FIELD_DELIMITER_DATA_IN_MASK                                     0x0000FFFF
//========================================
/* REG_HOB_PAC_DEL_DELIMITER_DATA_OUT 0x48 */
#define B2_HOB_PAC_DEL_DELIMITER_DATA_OUT_FIELD_DELIMITER_DATA_OUT_MASK                                           0xFFFFFFFF
//========================================
/* REG_HOB_PAC_DEL_DELIA_EVENT_THRESHOLD_TIMER 0x4C */
#define B2_HOB_PAC_DEL_DELIA_EVENT_THRESHOLD_TIMER_FIELD_DELIA_EVENT_THRESHOLD_TIMER_MASK                         0x00FFFFFF
//========================================
/* REG_HOB_PAC_DEL_TIM_DEL_EVENT_TIMER_EXPIRED 0x50 */
#define B2_HOB_PAC_DEL_TIM_DEL_EVENT_TIMER_EXPIRED_FIELD_TIM_DEL_EVENT_TIMER_EXPIRED_MASK                         0x00000001
//========================================
/* REG_HOB_PAC_DEL_TCR_TXOP_DUR_FROM_MAC 0x54 */
#define B2_HOB_PAC_DEL_TCR_TXOP_DUR_FROM_MAC_FIELD_TCR_TXOP_DUR_FROM_MAC_MASK                                     0x00000001
//========================================
/* REG_HOB_PAC_DEL_DELIA_TX_MPDU_DUR_FIELD 0x5C */
#define B2_HOB_PAC_DEL_DELIA_TX_MPDU_DUR_FIELD_FIELD_TX_MPDU_DUR_FIELD_MASK                                       0x0000FFFF
//========================================
/* REG_HOB_PAC_DEL_PAC_PHY_TX_LENGTH_ZERO 0x60 */
#define B2_HOB_PAC_DEL_PAC_PHY_TX_LENGTH_ZERO_FIELD_PAC_PHY_TX_LENGTH_ZERO_MASK                                   0x00000001
//========================================
/* REG_HOB_PAC_DEL_DELIMITER_VALUE_PRE_TX_DATA 0x64 */
#define B2_HOB_PAC_DEL_DELIMITER_VALUE_PRE_TX_DATA_FIELD_DELIMITER_VALUE_PRE_TX_DATA_MASK                         0xFFFFFFFF
//========================================
/* REG_HOB_PAC_DEL_NUM_OF_USER_TCRS 0x68 */
#define B2_HOB_PAC_DEL_NUM_OF_USER_TCRS_FIELD_NUM_OF_USER_TCRS_MASK                                               0x000000FF
//========================================
/* REG_HOB_PAC_DEL_NUM_OF_USER_TCR_BYTES 0x6C */
#define B2_HOB_PAC_DEL_NUM_OF_USER_TCR_BYTES_FIELD_NUM_OF_USER_TCR_BYTES_MASK                                     0x00000FFF
//========================================
/* REG_HOB_PAC_DEL_EXPECTED_RCRS 0x70 */
#define B2_HOB_PAC_DEL_EXPECTED_RCRS_FIELD_EXPECTED_RCRS_MASK                                                     0x00000001
//========================================
/* REG_HOB_PAC_DEL_NUM_OF_USER_RCR_BYTES 0x74 */
#define B2_HOB_PAC_DEL_NUM_OF_USER_RCR_BYTES_FIELD_NUM_OF_USER_RCR_BYTES_MASK                                     0x00000FFF
//========================================
/* REG_HOB_PAC_DEL_TX_CIR_BUF_BASE_ADDR 0x78 */
#define B2_HOB_PAC_DEL_TX_CIR_BUF_BASE_ADDR_FIELD_TX_CIR_BUF_BASE_ADDR_MASK                                       0xFFFFFFFF
//========================================
/* REG_HOB_PAC_DEL_REG2HOB_GP0 0x7C */
#define B2_HOB_PAC_DEL_REG2HOB_GP0_FIELD_REG2HOB_GP0_MASK                                                         0xFFFFFFFF
//========================================
/* REG_HOB_PAC_DEL_REG2HOB_GP1 0x80 */
#define B2_HOB_PAC_DEL_REG2HOB_GP1_FIELD_REG2HOB_GP1_MASK                                                         0xFFFFFFFF
//========================================
/* REG_HOB_PAC_DEL_TCR_BASE_ADDR1 0x84 */
#define B2_HOB_PAC_DEL_TCR_BASE_ADDR1_FIELD_TCR_BASE_ADDR2_MASK                                                   0x03FFFFFF
//========================================
/* REG_HOB_PAC_DEL_TCR_BASE_ADDR2 0x88 */
#define B2_HOB_PAC_DEL_TCR_BASE_ADDR2_FIELD_TCR_BASE_ADDR2_MASK                                                   0x03FFFFFF
//========================================
/* REG_HOB_PAC_DEL_RCR_BASE_ADDR 0x8C */
#define B2_HOB_PAC_DEL_RCR_BASE_ADDR_FIELD_RCR_BASE_ADDR_MASK                                                     0x03FFFFFF
//========================================
/* REG_HOB_PAC_DEL_SENDER_MPDU_DURATION 0x90 */
#define B2_HOB_PAC_DEL_SENDER_MPDU_DURATION_FIELD_SENDER_MPDU_DURATION_MASK                                       0x0000FFFF
//========================================
/* REG_HOB_PAC_DEL_ALL_ONES_PADDING 0x94 */
#define B2_HOB_PAC_DEL_ALL_ONES_PADDING_FIELD_ALL_ONES_PADDING_MASK                                               0xFFFFFFFF
//========================================
/* REG_HOB_PAC_DEL_TCC_CRC 0x98 */
#define B2_HOB_PAC_DEL_TCC_CRC_FIELD_TCC_CRC_MASK                                                                 0xFFFFFFFF


#endif // _HOB_PAC_DEL_REGS_H_
