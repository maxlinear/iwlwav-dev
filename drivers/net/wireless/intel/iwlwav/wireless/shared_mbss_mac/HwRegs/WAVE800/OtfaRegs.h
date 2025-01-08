
/***********************************************************************************
File:				OtfaRegs.h
Module:				otfa
SOC Revision:		latest
Generated at:       2024-06-26 12:55:15
Purpose:
Description:		This File was auto generated using SOC Online

************************************************************************************/
#ifndef _OTFA_REGS_H_
#define _OTFA_REGS_H_

/*---------------------------------------------------------------------------------
/						Registers Addresses													 
/----------------------------------------------------------------------------------*/
#include "HwMemoryMap.h"

#define OTFA_BASE_ADDRESS                                 MEMORY_MAP_UNIT_6_BASE_ADDRESS
#define	REG_OTFA_GENERAL_CONTROL                     (OTFA_BASE_ADDRESS + 0x0)
#define	REG_OTFA_RETRY_BUFFER_INDEX                  (OTFA_BASE_ADDRESS + 0x4)
#define	REG_OTFA_ZLDS_CONTROL_1                      (OTFA_BASE_ADDRESS + 0x8)
#define	REG_OTFA_ZLDS_CONTROL_2                      (OTFA_BASE_ADDRESS + 0xC)
#define	REG_OTFA_STOP_BUILDING                       (OTFA_BASE_ADDRESS + 0x10)
#define	REG_OTFA_BEACON_TIM_OVERHEAD_LENGTH          (OTFA_BASE_ADDRESS + 0x14)
#define	REG_OTFA_ETH_TYPE_OVERHEAD                   (OTFA_BASE_ADDRESS + 0x18)
#define	REG_OTFA_ZLDS_CONTROL_3                      (OTFA_BASE_ADDRESS + 0x1C)
#define	REG_OTFA_PD_ERR_ENABLE                       (OTFA_BASE_ADDRESS + 0x24)
#define	REG_OTFA_AVG_MPDU_LENGTH_MIN_TH              (OTFA_BASE_ADDRESS + 0x30)
#define	REG_OTFA_MAX_MPDU_LENGTH_11AG                (OTFA_BASE_ADDRESS + 0x34)
#define	REG_OTFA_MAX_MPDU_LENGTH_11B                 (OTFA_BASE_ADDRESS + 0x38)
#define	REG_OTFA_MAX_MPDU_LENGTH_HT                  (OTFA_BASE_ADDRESS + 0x3C)
#define	REG_OTFA_MAX_MPDU_LENGTH_VHT                 (OTFA_BASE_ADDRESS + 0x40)
#define	REG_OTFA_MAX_MPDU_LENGTH_HEBE                (OTFA_BASE_ADDRESS + 0x44)
#define	REG_OTFA_MAX_MSDU_LENGTH                     (OTFA_BASE_ADDRESS + 0x48)
#define	REG_OTFA_MAX_DMA_RATE                        (OTFA_BASE_ADDRESS + 0x4C)
#define	REG_OTFA_MIN_FRAG_CONF                       (OTFA_BASE_ADDRESS + 0x50)
#define	REG_OTFA_FREE_MD_PTR_FIFO_STATUS             (OTFA_BASE_ADDRESS + 0x54)
#define	REG_OTFA_FREE_MD_PTR_FIFO_DATA0_1            (OTFA_BASE_ADDRESS + 0x58)
#define	REG_OTFA_FREE_MD_PTR_FIFO_DATA2_3            (OTFA_BASE_ADDRESS + 0x5C)
#define	REG_OTFA_MD_USER_0_LIST_INDEX                (OTFA_BASE_ADDRESS + 0x70)
#define	REG_OTFA_OTF_START                           (OTFA_BASE_ADDRESS + 0x74)
#define	REG_OTFA_FIFO_ERROR                          (OTFA_BASE_ADDRESS + 0x78)
#define	REG_OTFA_FIFO_CLEAN                          (OTFA_BASE_ADDRESS + 0x7C)
#define	REG_OTFA_ALLOWED_PD_TYPE_OTF_MODE            (OTFA_BASE_ADDRESS + 0x80)
#define	REG_OTFA_TID_ERROR_FIFO_BASE_ADDR            (OTFA_BASE_ADDRESS + 0x84)
#define	REG_OTFA_TID_ERROR_FIFO_DEPTH_MINUS_ONE      (OTFA_BASE_ADDRESS + 0x88)
#define	REG_OTFA_TID_ERROR_FIFO_CLEAR_STRB           (OTFA_BASE_ADDRESS + 0x8C)
#define	REG_OTFA_TID_ERROR_FIFO_RD_ENTRIES_NUM       (OTFA_BASE_ADDRESS + 0x90)
#define	REG_OTFA_TID_ERROR_FIFO_NUM_ENTRIES_COUNT    (OTFA_BASE_ADDRESS + 0x94)
#define	REG_OTFA_TID_ERROR_FIFO_DEBUG                (OTFA_BASE_ADDRESS + 0x98)
#define	REG_OTFA_BAR_ZLDS_CTRL                       (OTFA_BASE_ADDRESS + 0x9C)
#define	REG_OTFA_USER0_MORE_DATA                     (OTFA_BASE_ADDRESS + 0xA0)
#define	REG_OTFA_SENDER_DURATION_SETTING_EN          (OTFA_BASE_ADDRESS + 0xA4)
#define	REG_OTFA_DEBUG_INFO2STD                      (OTFA_BASE_ADDRESS + 0xA8)
#define	REG_OTFA_LOGGER                              (OTFA_BASE_ADDRESS + 0xAC)
#define	REG_OTFA_TOTAL_PDS_COUNT                     (OTFA_BASE_ADDRESS + 0xB0)
#define	REG_OTFA_TOTAL_MPDUS_COUNT                   (OTFA_BASE_ADDRESS + 0xB4)
#define	REG_OTFA_SELECTED_TID_INDEX4DEBUG            (OTFA_BASE_ADDRESS + 0xB8)
#define	REG_OTFA_SELECTED_TID_INDEX_LIMIT_INFO       (OTFA_BASE_ADDRESS + 0xBC)
#define	REG_OTFA_SLOWEST_HW_MIN_PD_SPACE             (OTFA_BASE_ADDRESS + 0xC0)
#define	REG_OTFA_STATE_MACHINES1                     (OTFA_BASE_ADDRESS + 0xC4)
#define	REG_OTFA_STATE_MACHINES2                     (OTFA_BASE_ADDRESS + 0xC8)
#define	REG_OTFA_ERROR_IRQ_STATUS                    (OTFA_BASE_ADDRESS + 0xCC)
#define	REG_OTFA_ERROR_IRQ_ENABLE                    (OTFA_BASE_ADDRESS + 0xD0)
#define	REG_OTFA_SW_UPDATE_FRAG_DB                   (OTFA_BASE_ADDRESS + 0xD4)
#define	REG_OTFA_HE_TB_MODE                          (OTFA_BASE_ADDRESS + 0xD8)
#define	REG_OTFA_SPARE_REGISTERS                     (OTFA_BASE_ADDRESS + 0xFC)
/*---------------------------------------------------------------------------------
/						Data Type Definition										
/----------------------------------------------------------------------------------*/
/*REG_OTFA_GENERAL_CONTROL 0x0 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 retryMaxMpduLengthLimitCheckEn : 1; //Enable checking Max MPDU length in case of retry, reset value: 0x1, access type: RW
		uint32 retryMaxMsdusAtAmsduLimitCheckEn : 1; //Enable checking Max MSDU length in case of retry, reset value: 0x1, access type: RW
		uint32 reserved0 : 2;
		uint32 forceDelimiterInSingleMpduHt : 1; //Force adding delimiter when A-MPDU contains only one MPDU in HT, reset value: 0x0, access type: RW
		uint32 reserved1 : 2;
		uint32 dmaTran256Bytes : 1; //DMA transaction length , 0 - 128 bytes , 1 - 256 bytes, reset value: 0x0, access type: RW
		uint32 setEofInTf : 1; //set EOF in TF, reset value: 0x0, access type: RW
		uint32 eofConfA : 1; //eof_conf_a, reset value: 0x1, access type: RW
		uint32 eofConfB : 1; //eof_conf_b, reset value: 0x0, access type: RW
		uint32 eofConfC : 1; //eof_conf_c, reset value: 0x1, access type: RW
		uint32 eofConfD : 1; //no description, reset value: 0x1, access type: RW
		uint32 eofLastOnly : 1; //eof_last_only, reset value: 0x0, access type: RW
		uint32 maxBetweenAverageAndMinMpduEn : 1; //Enable taking Average MPDU length as maximum between STD Average MPDU length and STD minimum MPDU length, reset value: 0x0, access type: RW
		uint32 reserved2 : 17;
	} bitFields;
} RegOtfaGeneralControl_u;

/*REG_OTFA_RETRY_BUFFER_INDEX 0x4 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 retryBufferIndex : 1; //Retry DB buffer index- toggled by OTFA whenever it starts a new transmission., reset value: 0x0, access type: RO
		uint32 reserved0 : 31;
	} bitFields;
} RegOtfaRetryBufferIndex_u;

/*REG_OTFA_ZLDS_CONTROL_1 0x8 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 zldsInitPeriod : 6; //ZLDs init period [uS], reset value: 0x10, access type: RW
		uint32 reserved0 : 2;
		uint32 zldsMinThresholdPeriod : 5; //ZLDs min threshold period [uS], reset value: 0x1, access type: RW
		uint32 reserved1 : 3;
		uint32 zldsRecoverThresholdPeriod : 5; //ZLDs recover threshold period, reset value: 0x4, access type: RW
		uint32 reserved2 : 3;
		uint32 zldsInitLengthCalcCtrl : 1; //Defines how to calculate DMA Init Length , 0 --- Use DMA Rate for ZLD Init Length calculation , 1 --- use STA PHY Rate for ZLD Init Length calculation, reset value: 0x1, access type: RW
		uint32 reserved3 : 7;
	} bitFields;
} RegOtfaZldsControl1_u;

/*REG_OTFA_ZLDS_CONTROL_2 0xC */
typedef union
{
	uint32 val;
	struct
	{
		uint32 zldsMaxBudget4K : 13; //ZLDs max budget for circular buffer of 4K, reset value: 0xf30, access type: RW
		uint32 reserved0 : 3;
		uint32 zldsMaxBudget8K : 14; //ZLDs max budget for circular buffer of 8K, reset value: 0x1f00, access type: RW
		uint32 reserved1 : 2;
	} bitFields;
} RegOtfaZldsControl2_u;

/*REG_OTFA_STOP_BUILDING 0x10 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 stopBuilding : 1; //Stop MPDU building, reset value: 0x0, access type: WO
		uint32 reserved0 : 31;
	} bitFields;
} RegOtfaStopBuilding_u;

/*REG_OTFA_BEACON_TIM_OVERHEAD_LENGTH 0x14 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 beaconTimOverheadLength : 8; //TIM overhead length for Beacon, reset value: 0x2, access type: RW
		uint32 beaconMltiOverheadLength : 8; //MLTI overhead length for Beacon, reset value: 0x2, access type: RW
		uint32 reserved0 : 16;
	} bitFields;
} RegOtfaBeaconTimOverheadLength_u;

/*REG_OTFA_ETH_TYPE_OVERHEAD 0x18 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 ethType0Oh : 8; //Overhead length for Ether type = 0 , 8-bit two's complement value, reset value: 0xFA, access type: RW
		uint32 ethType1Oh : 8; //Overhead length for Ether type = 1 , 8-bit two's complement value, reset value: 0xFA, access type: RW
		uint32 ethType2Oh : 8; //Overhead length for Ether type = 2 , 8-bit two's complement value, reset value: 0xF2, access type: RW
		uint32 ethType3Oh : 8; //Overhead length for Ether type = 3 , 8-bit two's complement value, reset value: 0xFA, access type: RW
	} bitFields;
} RegOtfaEthTypeOverhead_u;

/*REG_OTFA_ZLDS_CONTROL_3 0x1C */
typedef union
{
	uint32 val;
	struct
	{
		uint32 zldsMaxBudget16K : 15; //ZLDs max budget for circular buffer of 16K, reset value: 0x3e00, access type: RW
		uint32 reserved0 : 17;
	} bitFields;
} RegOtfaZldsControl3_u;

/*REG_OTFA_PD_ERR_ENABLE 0x24 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 pdErrEnable : 12; //pd_err_enable, reset value: 0xFFF, access type: RW
		uint32 reserved0 : 20;
	} bitFields;
} RegOtfaPdErrEnable_u;

/*REG_OTFA_AVG_MPDU_LENGTH_MIN_TH 0x30 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 avgMpduLengthMinTh : 16; //Average MPDU length minimum threshold , 16-bit two's complement value, reset value: 0xf000, access type: RW
		uint32 reserved0 : 16;
	} bitFields;
} RegOtfaAvgMpduLengthMinTh_u;

/*REG_OTFA_MAX_MPDU_LENGTH_11AG 0x34 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 maxMpduLength11Ag : 14; //Max MPDU length 11ag, reset value: 0x3fff, access type: RW
		uint32 reserved0 : 18;
	} bitFields;
} RegOtfaMaxMpduLength11Ag_u;

/*REG_OTFA_MAX_MPDU_LENGTH_11B 0x38 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 maxMpduLength11B : 14; //Max MPDU length 11b, reset value: 0x3fff, access type: RW
		uint32 reserved0 : 18;
	} bitFields;
} RegOtfaMaxMpduLength11B_u;

/*REG_OTFA_MAX_MPDU_LENGTH_HT 0x3C */
typedef union
{
	uint32 val;
	struct
	{
		uint32 maxMpduLengthHt : 14; //Max MPDU length for HT non-aggregate, reset value: 0x3fff, access type: RW
		uint32 reserved0 : 2;
		uint32 maxMpduLengthHtAgg : 14; //Max MPDU length for HT ggregate, reset value: 0x3fff, access type: RW
		uint32 reserved1 : 2;
	} bitFields;
} RegOtfaMaxMpduLengthHt_u;

/*REG_OTFA_MAX_MPDU_LENGTH_VHT 0x40 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 maxMpduLengthVht : 14; //Max MPDU length VHT, reset value: 0x3fff, access type: RW
		uint32 reserved0 : 18;
	} bitFields;
} RegOtfaMaxMpduLengthVht_u;

/*REG_OTFA_MAX_MPDU_LENGTH_HEBE 0x44 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 maxMpduLengthHebe : 14; //Max MPDU length for HE and BE, reset value: 0x3fff, access type: RW
		uint32 reserved0 : 18;
	} bitFields;
} RegOtfaMaxMpduLengthHebe_u;

/*REG_OTFA_MAX_MSDU_LENGTH 0x48 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 maxMsduLength : 14; //Max MSDU length, reset value: 0x900, access type: RW
		uint32 reserved0 : 18;
	} bitFields;
} RegOtfaMaxMsduLength_u;

/*REG_OTFA_MAX_DMA_RATE 0x4C */
typedef union
{
	uint32 val;
	struct
	{
		uint32 maxDmaRate : 17; //Max DMA Rate - Holds the DMA Max Rate value which is used by the system in 125Kbps units, reset value: 0x14000, access type: RW
		uint32 reserved0 : 15;
	} bitFields;
} RegOtfaMaxDmaRate_u;

/*REG_OTFA_MIN_FRAG_CONF 0x50 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 minFragConf : 2; //Min Frag length: , 0 - No restriction , 1 - 128 Bytes , 2 - 256 Bytes , 3 - 512 Bytes, reset value: 0x1, access type: RW
		uint32 reserved0 : 30;
	} bitFields;
} RegOtfaMinFragConf_u;

/*REG_OTFA_FREE_MD_PTR_FIFO_STATUS 0x54 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 freeMdPtrFifoFullness : 3; //Free MPDU Descriptor pointers FIFO fullness, reset value: 0x0, access type: RO
		uint32 reserved0 : 5;
		uint32 freeMdPtrFifoRdPtr : 2; //Free MPDU Descriptor pointers FIFO - read pointer, reset value: 0x0, access type: RO
		uint32 reserved1 : 6;
		uint32 freeMdPtrFifoWrPtr : 2; //Free MPDU Descriptor pointers FIFO - write pointer, reset value: 0x0, access type: RO
		uint32 reserved2 : 14;
	} bitFields;
} RegOtfaFreeMdPtrFifoStatus_u;

/*REG_OTFA_FREE_MD_PTR_FIFO_DATA0_1 0x58 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 freeMdPtrFifoSwRdData0 : 16; //Free MPDU Descriptor pointer FiFO - SW read data 0, reset value: 0x0, access type: RO
		uint32 freeMdPtrFifoSwRdData1 : 16; //Free MPDU Descriptor pointer FiFO - SW read data 1, reset value: 0x0, access type: RO
	} bitFields;
} RegOtfaFreeMdPtrFifoData01_u;

/*REG_OTFA_FREE_MD_PTR_FIFO_DATA2_3 0x5C */
typedef union
{
	uint32 val;
	struct
	{
		uint32 freeMdPtrFifoSwRdData2 : 16; //Free MPDU Descriptor pointer FiFO - SW read data 2, reset value: 0x0, access type: RO
		uint32 freeMdPtrFifoSwRdData3 : 16; //Free MPDU Descriptor pointer FiFO - SW read data 3, reset value: 0x0, access type: RO
	} bitFields;
} RegOtfaFreeMdPtrFifoData23_u;

/*REG_OTFA_MD_USER_0_LIST_INDEX 0x70 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 mdUser0ListIndex : 8; //MPDU descriptor - user 0 list index, reset value: 0x2C, access type: RW
		uint32 reserved0 : 24;
	} bitFields;
} RegOtfaMdUser0ListIndex_u;

/*REG_OTFA_OTF_START 0x74 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 otfStart : 1; //no description, reset value: 0x0, access type: WO
		uint32 buildOnlyTf : 1; //Build only TF, reset value: 0x0, access type: RW
		uint32 reserved0 : 30;
	} bitFields;
} RegOtfaOtfStart_u;

/*REG_OTFA_FIFO_ERROR 0x78 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 mpduDescFifoErrorSticky : 2; //bit 0 - indicates underflow , bit 1 - indicates overflow, reset value: 0x0, access type: RO
		uint32 freeMdPtrFifoErrorSticky : 2; //bit 0 - indicates underflow , bit 1 - indicates overflow, reset value: 0x0, access type: RO
		uint32 reserved0 : 28;
	} bitFields;
} RegOtfaFifoError_u;

/*REG_OTFA_FIFO_CLEAN 0x7C */
typedef union
{
	uint32 val;
	struct
	{
		uint32 mpduDescFifoClean : 1; //mpdu_desc_fifo_clean, reset value: 0x0, access type: WO
		uint32 freeMdPtrFifoClean : 1; //free_md_ptr_fifo_clean, reset value: 0x0, access type: WO
		uint32 reserved0 : 30;
	} bitFields;
} RegOtfaFifoClean_u;

/*REG_OTFA_ALLOWED_PD_TYPE_OTF_MODE 0x80 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 allowedPdTypeOtfMode : 32; //Allowed PD types in OTF mode, reset value: 0x3, access type: RW
	} bitFields;
} RegOtfaAllowedPdTypeOtfMode_u;

/*REG_OTFA_TID_ERROR_FIFO_BASE_ADDR 0x84 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 tidErrorFifoBaseAddr : 22; //TID error FIFO base address, reset value: 0x0, access type: RW
		uint32 reserved0 : 10;
	} bitFields;
} RegOtfaTidErrorFifoBaseAddr_u;

/*REG_OTFA_TID_ERROR_FIFO_DEPTH_MINUS_ONE 0x88 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 tidErrorFifoDepthMinusOne : 8; //TID error FIFO depth minus one, reset value: 0xff, access type: RW
		uint32 reserved0 : 24;
	} bitFields;
} RegOtfaTidErrorFifoDepthMinusOne_u;

/*REG_OTFA_TID_ERROR_FIFO_CLEAR_STRB 0x8C */
typedef union
{
	uint32 val;
	struct
	{
		uint32 tidErrorFifoClearStrb : 1; //Clear TID error FIFO. , By write '1'., reset value: 0x0, access type: WO
		uint32 tidErrorFifoClearFullDropCtrStrb : 1; //Clear TID error FIFO full drop counter. , By write '1'., reset value: 0x0, access type: WO
		uint32 tidErrorFifoClearDecLessThanZeroStrb : 1; //Clear TID error FIFO decrement amount less than zero indication. , By write '1'.  , , reset value: 0x0, access type: WO
		uint32 reserved0 : 29;
	} bitFields;
} RegOtfaTidErrorFifoClearStrb_u;

/*REG_OTFA_TID_ERROR_FIFO_RD_ENTRIES_NUM 0x90 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 tidErrorFifoRdEntriesNum : 9; //TID error FIFO number of entries to decrement., reset value: 0x0, access type: RW
		uint32 reserved0 : 23;
	} bitFields;
} RegOtfaTidErrorFifoRdEntriesNum_u;

/*REG_OTFA_TID_ERROR_FIFO_NUM_ENTRIES_COUNT 0x94 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 tidErrorFifoNumEntriesCount : 9; //TID error FIFO number of entries count, reset value: 0x0, access type: RO
		uint32 reserved0 : 23;
	} bitFields;
} RegOtfaTidErrorFifoNumEntriesCount_u;

/*REG_OTFA_TID_ERROR_FIFO_DEBUG 0x98 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 tidErrorFifoWrPtr : 8; //TID error FIFO write pointer index, reset value: 0x0, access type: RO
		uint32 reserved0 : 8;
		uint32 tidErrorFifoNotEmpty : 1; //TID error FIFO not empty indication, reset value: 0x0, access type: RO
		uint32 tidErrorFifoFull : 1; //TID error FIFO full indication, reset value: 0x0, access type: RO
		uint32 tidErrorFifoDecrementLessThanZero : 1; //TID error setting FIFO amount has been decremented less than zero, reset value: 0x0, access type: RO
		uint32 reserved1 : 5;
		uint32 tidErrorFifoFullDropCtr : 8; //TID error setting FIFO full drop counter, reset value: 0x0, access type: RO
	} bitFields;
} RegOtfaTidErrorFifoDebug_u;

/*REG_OTFA_BAR_ZLDS_CTRL 0x9C */
typedef union
{
	uint32 val;
	struct
	{
		uint32 bar8ZldsCnt : 10; //Num of 8 ZLDs to add before BAR, reset value: 0x0, access type: RW
		uint32 reserved0 : 22;
	} bitFields;
} RegOtfaBarZldsCtrl_u;

/*REG_OTFA_USER0_MORE_DATA 0xA0 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 otfaUser0MoreData : 1; //User 0 more data, reset value: 0x0, access type: RO
		uint32 reserved0 : 31;
	} bitFields;
} RegOtfaUser0MoreData_u;

/*REG_OTFA_SENDER_DURATION_SETTING_EN 0xA4 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 senderDurationSettingEn : 1; //Sender duration setting enable, reset value: 0x0, access type: RW
		uint32 reserved0 : 31;
	} bitFields;
} RegOtfaSenderDurationSettingEn_u;

/*REG_OTFA_DEBUG_INFO2STD 0xA8 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 debugInfo2StdAddr : 12; //Base address in STD for TID debug info, reset value: 0x26d, access type: RW
		uint32 reserved0 : 4;
		uint32 debugInfo2StdEnable : 1; //Enable TID debug info to STD, reset value: 0x0, access type: RW
		uint32 reserved1 : 15;
	} bitFields;
} RegOtfaDebugInfo2Std_u;

/*REG_OTFA_LOGGER 0xAC */
typedef union
{
	uint32 val;
	struct
	{
		uint32 loggerActive : 1; //OTFA logger active, reset value: 0x0, access type: RO
		uint32 loggerEnable : 1; //OTFA logger enable, reset value: 0x0, access type: RW
		uint32 reserved0 : 2;
		uint32 otfaLoggerPriority : 2; //OTFA logger priority, reset value: 0x0, access type: RW
		uint32 reserved1 : 26;
	} bitFields;
} RegOtfaLogger_u;

/*REG_OTFA_TOTAL_PDS_COUNT 0xB0 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 totalPdsCount : 20; //total_pds_count, reset value: 0x0, access type: RO
		uint32 reserved0 : 12;
	} bitFields;
} RegOtfaTotalPdsCount_u;

/*REG_OTFA_TOTAL_MPDUS_COUNT 0xB4 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 totalMpdusCount : 15; //total_mpdus_count, reset value: 0x0, access type: RO
		uint32 reserved0 : 17;
	} bitFields;
} RegOtfaTotalMpdusCount_u;

/*REG_OTFA_SELECTED_TID_INDEX4DEBUG 0xB8 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 selectedTidIndex4Debug : 8; //selected_tid_index4debug, reset value: 0x0, access type: RW
		uint32 reserved0 : 24;
	} bitFields;
} RegOtfaSelectedTidIndex4Debug_u;

/*REG_OTFA_SELECTED_TID_INDEX_LIMIT_INFO 0xBC */
typedef union
{
	uint32 val;
	struct
	{
		uint32 selectedTidIndexLimitInfo : 32; //selected_tid_index_limit_info, reset value: 0x0, access type: RO
	} bitFields;
} RegOtfaSelectedTidIndexLimitInfo_u;

/*REG_OTFA_SLOWEST_HW_MIN_PD_SPACE 0xC0 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 slowestHwMinPdSpace : 8; //slowest_hw_min_pd_space , Units are in [us]/128  (value of 128 means 1uS, 64 - 500nS, etc.). , reset value: 0x1a, access type: RW
		uint32 reserved0 : 24;
	} bitFields;
} RegOtfaSlowestHwMinPdSpace_u;

/*REG_OTFA_STATE_MACHINES1 0xC4 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 baaTidCntrsSmOut : 3; //no description, reset value: 0x0, access type: RO
		uint32 pdPtrCacheCtrlSmOut : 3; //no description, reset value: 0x0, access type: RO
		uint32 descCacheCtrlSmOut : 2; //no description, reset value: 0x0, access type: RO
		uint32 mpduBuilderSmOut : 6; //no description, reset value: 0x0, access type: RO
		uint32 mpduDescHandlerSmOut : 3; //no description, reset value: 0x0, access type: RO
		uint32 otfaCtrlSmOut : 3; //no description, reset value: 0x0, access type: RO
		uint32 pdCacheCtrlSmOut : 3; //no description, reset value: 0x0, access type: RO
		uint32 retryDbCacheCtrlSmOut : 4; //no description, reset value: 0x0, access type: RO
		uint32 reserved0 : 4;
		uint32 otfaInIdle : 1; //no description, reset value: 0x1, access type: RO
	} bitFields;
} RegOtfaStateMachines1_u;

/*REG_OTFA_STATE_MACHINES2 0xC8 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 stdFetchReqSmOut : 4; //no description, reset value: 0x0, access type: RO
		uint32 stdFetchAckSmOut : 4; //no description, reset value: 0x0, access type: RO
		uint32 tidErrorFifoSmOut : 2; //no description, reset value: 0x0, access type: RO
		uint32 fragDbSmOut : 2; //no description, reset value: 0x0, access type: RO
		uint32 reserved0 : 20;
	} bitFields;
} RegOtfaStateMachines2_u;

/*REG_OTFA_ERROR_IRQ_STATUS 0xCC */
typedef union
{
	uint32 val;
	struct
	{
		uint32 tidErrorFifoFullDropIrq : 1; //tid_error_fifo_full_drop_irq, reset value: 0x0, access type: RO
		uint32 tidErrorFifoDecrementLessThanZeroIrq : 1; //tid_error_fifo_decrement_less_than_zero_irq, reset value: 0x0, access type: RO
		uint32 reserved0 : 30;
	} bitFields;
} RegOtfaErrorIrqStatus_u;

/*REG_OTFA_ERROR_IRQ_ENABLE 0xD0 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 tidErrorFifoFullDropIrqEnabled : 1; //tid_error_fifo_full_drop_irq_enabled, reset value: 0x0, access type: RW
		uint32 tidErrorFifoDecrementLessThanZeroIrqEnabled : 1; //tid_error_fifo_decrement_less_than_zero_irq_enable, reset value: 0x0, access type: RW
		uint32 reserved0 : 30;
	} bitFields;
} RegOtfaErrorIrqEnable_u;

/*REG_OTFA_SW_UPDATE_FRAG_DB 0xD4 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 swUpdateFragDbStaId : 7; //In-band sta index for sw_update command, reset value: 0x0, access type: RW
		uint32 reserved0 : 9;
		uint32 swUpdateFragDbValue : 4; //no description, reset value: 0x0, access type: RW
		uint32 swUpdateFragDbAction : 1; //0 - Decrement 1 , 1 - Set value, reset value: 0x0, access type: RW
		uint32 reserved1 : 10;
		uint32 swUpdateFragDbDone : 1; //no description, reset value: 0x1, access type: RO
	} bitFields;
} RegOtfaSwUpdateFragDb_u;

/*REG_OTFA_HE_TB_MODE 0xD8 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 bsrMaxTidsDataConf : 4; //no description, reset value: 0x8, access type: RW
		uint32 bsrMaxTidsBsrpConf : 4; //no description, reset value: 0x8, access type: RW
		uint32 bsrMaxTidsBaConf : 4; //no description, reset value: 0x1, access type: RW
		uint32 reserved0 : 4;
		uint32 heTbModeTid8ByteCountConf : 8; //Resolution of 64 bytes, reset value: 0x18, access type: RW
		uint32 reserved1 : 7;
		uint32 reportSumByteCountersInLastTidConf : 1; //no description, reset value: 0x1, access type: RW
	} bitFields;
} RegOtfaHeTbMode_u;

/*REG_OTFA_SPARE_REGISTERS 0xFC */
typedef union
{
	uint32 val;
	struct
	{
		uint32 spareRegisters : 16; //Spare registers, reset value: 0x8888, access type: RW
		uint32 reserved0 : 16;
	} bitFields;
} RegOtfaSpareRegisters_u;

//========================================
/* REG_OTFA_GENERAL_CONTROL 0x0 */
#define B0_OTFA_GENERAL_CONTROL_FIELD_RETRY_MAX_MPDU_LENGTH_LIMIT_CHECK_EN_MASK                                   0x00000001
#define B0_OTFA_GENERAL_CONTROL_FIELD_RETRY_MAX_MSDUS_AT_AMSDU_LIMIT_CHECK_EN_MASK                                0x00000002
#define B0_OTFA_GENERAL_CONTROL_FIELD_FORCE_DELIMITER_IN_SINGLE_MPDU_HT_MASK                                      0x00000010
#define B0_OTFA_GENERAL_CONTROL_FIELD_DMA_TRAN_256BYTES_MASK                                                      0x00000080
#define B0_OTFA_GENERAL_CONTROL_FIELD_SET_EOF_IN_TF_MASK                                                          0x00000100
#define B0_OTFA_GENERAL_CONTROL_FIELD_EOF_CONF_A_MASK                                                             0x00000200
#define B0_OTFA_GENERAL_CONTROL_FIELD_EOF_CONF_B_MASK                                                             0x00000400
#define B0_OTFA_GENERAL_CONTROL_FIELD_EOF_CONF_C_MASK                                                             0x00000800
#define B0_OTFA_GENERAL_CONTROL_FIELD_EOF_CONF_D_MASK                                                             0x00001000
#define B0_OTFA_GENERAL_CONTROL_FIELD_EOF_LAST_ONLY_MASK                                                          0x00002000
#define B0_OTFA_GENERAL_CONTROL_FIELD_MAX_BETWEEN_AVERAGE_AND_MIN_MPDU_EN_MASK                                    0x00004000
//========================================
/* REG_OTFA_RETRY_BUFFER_INDEX 0x4 */
#define B0_OTFA_RETRY_BUFFER_INDEX_FIELD_RETRY_BUFFER_INDEX_MASK                                                  0x00000001
//========================================
/* REG_OTFA_ZLDS_CONTROL_1 0x8 */
#define B0_OTFA_ZLDS_CONTROL_1_FIELD_ZLDS_INIT_PERIOD_MASK                                                        0x0000003F
#define B0_OTFA_ZLDS_CONTROL_1_FIELD_ZLDS_MIN_THRESHOLD_PERIOD_MASK                                               0x00001F00
#define B0_OTFA_ZLDS_CONTROL_1_FIELD_ZLDS_RECOVER_THRESHOLD_PERIOD_MASK                                           0x001F0000
#define B0_OTFA_ZLDS_CONTROL_1_FIELD_ZLDS_INIT_LENGTH_CALC_CTRL_MASK                                              0x01000000
//========================================
/* REG_OTFA_ZLDS_CONTROL_2 0xC */
#define B0_OTFA_ZLDS_CONTROL_2_FIELD_ZLDS_MAX_BUDGET_4K_MASK                                                      0x00001FFF
#define B0_OTFA_ZLDS_CONTROL_2_FIELD_ZLDS_MAX_BUDGET_8K_MASK                                                      0x3FFF0000
//========================================
/* REG_OTFA_STOP_BUILDING 0x10 */
#define B0_OTFA_STOP_BUILDING_FIELD_STOP_BUILDING_MASK                                                            0x00000001
//========================================
/* REG_OTFA_BEACON_TIM_OVERHEAD_LENGTH 0x14 */
#define B0_OTFA_BEACON_TIM_OVERHEAD_LENGTH_FIELD_BEACON_TIM_OVERHEAD_LENGTH_MASK                                  0x000000FF
#define B0_OTFA_BEACON_TIM_OVERHEAD_LENGTH_FIELD_BEACON_MLTI_OVERHEAD_LENGTH_MASK                                 0x0000FF00
//========================================
/* REG_OTFA_ETH_TYPE_OVERHEAD 0x18 */
#define B0_OTFA_ETH_TYPE_OVERHEAD_FIELD_ETH_TYPE0_OH_MASK                                                         0x000000FF
#define B0_OTFA_ETH_TYPE_OVERHEAD_FIELD_ETH_TYPE1_OH_MASK                                                         0x0000FF00
#define B0_OTFA_ETH_TYPE_OVERHEAD_FIELD_ETH_TYPE2_OH_MASK                                                         0x00FF0000
#define B0_OTFA_ETH_TYPE_OVERHEAD_FIELD_ETH_TYPE3_OH_MASK                                                         0xFF000000
//========================================
/* REG_OTFA_ZLDS_CONTROL_3 0x1C */
#define B0_OTFA_ZLDS_CONTROL_3_FIELD_ZLDS_MAX_BUDGET_16K_MASK                                                     0x00007FFF
//========================================
/* REG_OTFA_PD_ERR_ENABLE 0x24 */
#define B0_OTFA_PD_ERR_ENABLE_FIELD_PD_ERR_ENABLE_MASK                                                            0x00000FFF
//========================================
/* REG_OTFA_AVG_MPDU_LENGTH_MIN_TH 0x30 */
#define B0_OTFA_AVG_MPDU_LENGTH_MIN_TH_FIELD_AVG_MPDU_LENGTH_MIN_TH_MASK                                          0x0000FFFF
//========================================
/* REG_OTFA_MAX_MPDU_LENGTH_11AG 0x34 */
#define B0_OTFA_MAX_MPDU_LENGTH_11AG_FIELD_MAX_MPDU_LENGTH_11AG_MASK                                              0x00003FFF
//========================================
/* REG_OTFA_MAX_MPDU_LENGTH_11B 0x38 */
#define B0_OTFA_MAX_MPDU_LENGTH_11B_FIELD_MAX_MPDU_LENGTH_11B_MASK                                                0x00003FFF
//========================================
/* REG_OTFA_MAX_MPDU_LENGTH_HT 0x3C */
#define B0_OTFA_MAX_MPDU_LENGTH_HT_FIELD_MAX_MPDU_LENGTH_HT_MASK                                                  0x00003FFF
#define B0_OTFA_MAX_MPDU_LENGTH_HT_FIELD_MAX_MPDU_LENGTH_HT_AGG_MASK                                              0x3FFF0000
//========================================
/* REG_OTFA_MAX_MPDU_LENGTH_VHT 0x40 */
#define B0_OTFA_MAX_MPDU_LENGTH_VHT_FIELD_MAX_MPDU_LENGTH_VHT_MASK                                                0x00003FFF
//========================================
/* REG_OTFA_MAX_MPDU_LENGTH_HEBE 0x44 */
#define B0_OTFA_MAX_MPDU_LENGTH_HEBE_FIELD_MAX_MPDU_LENGTH_HEBE_MASK                                              0x00003FFF
//========================================
/* REG_OTFA_MAX_MSDU_LENGTH 0x48 */
#define B0_OTFA_MAX_MSDU_LENGTH_FIELD_MAX_MSDU_LENGTH_MASK                                                        0x00003FFF
//========================================
/* REG_OTFA_MAX_DMA_RATE 0x4C */
#define B0_OTFA_MAX_DMA_RATE_FIELD_MAX_DMA_RATE_MASK                                                              0x0001FFFF
//========================================
/* REG_OTFA_MIN_FRAG_CONF 0x50 */
#define B0_OTFA_MIN_FRAG_CONF_FIELD_MIN_FRAG_CONF_MASK                                                            0x00000003
//========================================
/* REG_OTFA_FREE_MD_PTR_FIFO_STATUS 0x54 */
#define B0_OTFA_FREE_MD_PTR_FIFO_STATUS_FIELD_FREE_MD_PTR_FIFO_FULLNESS_MASK                                      0x00000007
#define B0_OTFA_FREE_MD_PTR_FIFO_STATUS_FIELD_FREE_MD_PTR_FIFO_RD_PTR_MASK                                        0x00000300
#define B0_OTFA_FREE_MD_PTR_FIFO_STATUS_FIELD_FREE_MD_PTR_FIFO_WR_PTR_MASK                                        0x00030000
//========================================
/* REG_OTFA_FREE_MD_PTR_FIFO_DATA0_1 0x58 */
#define B0_OTFA_FREE_MD_PTR_FIFO_DATA0_1_FIELD_FREE_MD_PTR_FIFO_SW_RD_DATA_0_MASK                                 0x0000FFFF
#define B0_OTFA_FREE_MD_PTR_FIFO_DATA0_1_FIELD_FREE_MD_PTR_FIFO_SW_RD_DATA_1_MASK                                 0xFFFF0000
//========================================
/* REG_OTFA_FREE_MD_PTR_FIFO_DATA2_3 0x5C */
#define B0_OTFA_FREE_MD_PTR_FIFO_DATA2_3_FIELD_FREE_MD_PTR_FIFO_SW_RD_DATA_2_MASK                                 0x0000FFFF
#define B0_OTFA_FREE_MD_PTR_FIFO_DATA2_3_FIELD_FREE_MD_PTR_FIFO_SW_RD_DATA_3_MASK                                 0xFFFF0000
//========================================
/* REG_OTFA_MD_USER_0_LIST_INDEX 0x70 */
#define B0_OTFA_MD_USER_0_LIST_INDEX_FIELD_MD_USER_0_LIST_INDEX_MASK                                              0x000000FF
//========================================
/* REG_OTFA_OTF_START 0x74 */
#define B0_OTFA_OTF_START_FIELD_OTF_START_MASK                                                                    0x00000001
#define B0_OTFA_OTF_START_FIELD_BUILD_ONLY_TF_MASK                                                                0x00000002
//========================================
/* REG_OTFA_FIFO_ERROR 0x78 */
#define B0_OTFA_FIFO_ERROR_FIELD_MPDU_DESC_FIFO_ERROR_STICKY_MASK                                                 0x00000003
#define B0_OTFA_FIFO_ERROR_FIELD_FREE_MD_PTR_FIFO_ERROR_STICKY_MASK                                               0x0000000C
//========================================
/* REG_OTFA_FIFO_CLEAN 0x7C */
#define B0_OTFA_FIFO_CLEAN_FIELD_MPDU_DESC_FIFO_CLEAN_MASK                                                        0x00000001
#define B0_OTFA_FIFO_CLEAN_FIELD_FREE_MD_PTR_FIFO_CLEAN_MASK                                                      0x00000002
//========================================
/* REG_OTFA_ALLOWED_PD_TYPE_OTF_MODE 0x80 */
#define B0_OTFA_ALLOWED_PD_TYPE_OTF_MODE_FIELD_ALLOWED_PD_TYPE_OTF_MODE_MASK                                      0xFFFFFFFF
//========================================
/* REG_OTFA_TID_ERROR_FIFO_BASE_ADDR 0x84 */
#define B0_OTFA_TID_ERROR_FIFO_BASE_ADDR_FIELD_TID_ERROR_FIFO_BASE_ADDR_MASK                                      0x003FFFFF
//========================================
/* REG_OTFA_TID_ERROR_FIFO_DEPTH_MINUS_ONE 0x88 */
#define B0_OTFA_TID_ERROR_FIFO_DEPTH_MINUS_ONE_FIELD_TID_ERROR_FIFO_DEPTH_MINUS_ONE_MASK                          0x000000FF
//========================================
/* REG_OTFA_TID_ERROR_FIFO_CLEAR_STRB 0x8C */
#define B0_OTFA_TID_ERROR_FIFO_CLEAR_STRB_FIELD_TID_ERROR_FIFO_CLEAR_STRB_MASK                                    0x00000001
#define B0_OTFA_TID_ERROR_FIFO_CLEAR_STRB_FIELD_TID_ERROR_FIFO_CLEAR_FULL_DROP_CTR_STRB_MASK                      0x00000002
#define B0_OTFA_TID_ERROR_FIFO_CLEAR_STRB_FIELD_TID_ERROR_FIFO_CLEAR_DEC_LESS_THAN_ZERO_STRB_MASK                 0x00000004
//========================================
/* REG_OTFA_TID_ERROR_FIFO_RD_ENTRIES_NUM 0x90 */
#define B0_OTFA_TID_ERROR_FIFO_RD_ENTRIES_NUM_FIELD_TID_ERROR_FIFO_RD_ENTRIES_NUM_MASK                            0x000001FF
//========================================
/* REG_OTFA_TID_ERROR_FIFO_NUM_ENTRIES_COUNT 0x94 */
#define B0_OTFA_TID_ERROR_FIFO_NUM_ENTRIES_COUNT_FIELD_TID_ERROR_FIFO_NUM_ENTRIES_COUNT_MASK                      0x000001FF
//========================================
/* REG_OTFA_TID_ERROR_FIFO_DEBUG 0x98 */
#define B0_OTFA_TID_ERROR_FIFO_DEBUG_FIELD_TID_ERROR_FIFO_WR_PTR_MASK                                             0x000000FF
#define B0_OTFA_TID_ERROR_FIFO_DEBUG_FIELD_TID_ERROR_FIFO_NOT_EMPTY_MASK                                          0x00010000
#define B0_OTFA_TID_ERROR_FIFO_DEBUG_FIELD_TID_ERROR_FIFO_FULL_MASK                                               0x00020000
#define B0_OTFA_TID_ERROR_FIFO_DEBUG_FIELD_TID_ERROR_FIFO_DECREMENT_LESS_THAN_ZERO_MASK                           0x00040000
#define B0_OTFA_TID_ERROR_FIFO_DEBUG_FIELD_TID_ERROR_FIFO_FULL_DROP_CTR_MASK                                      0xFF000000
//========================================
/* REG_OTFA_BAR_ZLDS_CTRL 0x9C */
#define B0_OTFA_BAR_ZLDS_CTRL_FIELD_BAR_8ZLDS_CNT_MASK                                                            0x000003FF
//========================================
/* REG_OTFA_USER0_MORE_DATA 0xA0 */
#define B0_OTFA_USER0_MORE_DATA_FIELD_OTFA_USER0_MORE_DATA_MASK                                                   0x00000001
//========================================
/* REG_OTFA_SENDER_DURATION_SETTING_EN 0xA4 */
#define B0_OTFA_SENDER_DURATION_SETTING_EN_FIELD_SENDER_DURATION_SETTING_EN_MASK                                  0x00000001
//========================================
/* REG_OTFA_DEBUG_INFO2STD 0xA8 */
#define B0_OTFA_DEBUG_INFO2STD_FIELD_DEBUG_INFO2STD_ADDR_MASK                                                     0x00000FFF
#define B0_OTFA_DEBUG_INFO2STD_FIELD_DEBUG_INFO2STD_ENABLE_MASK                                                   0x00010000
//========================================
/* REG_OTFA_LOGGER 0xAC */
#define B0_OTFA_LOGGER_FIELD_LOGGER_ACTIVE_MASK                                                                   0x00000001
#define B0_OTFA_LOGGER_FIELD_LOGGER_ENABLE_MASK                                                                   0x00000002
#define B0_OTFA_LOGGER_FIELD_OTFA_LOGGER_PRIORITY_MASK                                                            0x00000030
//========================================
/* REG_OTFA_TOTAL_PDS_COUNT 0xB0 */
#define B0_OTFA_TOTAL_PDS_COUNT_FIELD_TOTAL_PDS_COUNT_MASK                                                        0x000FFFFF
//========================================
/* REG_OTFA_TOTAL_MPDUS_COUNT 0xB4 */
#define B0_OTFA_TOTAL_MPDUS_COUNT_FIELD_TOTAL_MPDUS_COUNT_MASK                                                    0x00007FFF
//========================================
/* REG_OTFA_SELECTED_TID_INDEX4DEBUG 0xB8 */
#define B0_OTFA_SELECTED_TID_INDEX4DEBUG_FIELD_SELECTED_TID_INDEX4DEBUG_MASK                                      0x000000FF
//========================================
/* REG_OTFA_SELECTED_TID_INDEX_LIMIT_INFO 0xBC */
#define B0_OTFA_SELECTED_TID_INDEX_LIMIT_INFO_FIELD_SELECTED_TID_INDEX_LIMIT_INFO_MASK                            0xFFFFFFFF
//========================================
/* REG_OTFA_SLOWEST_HW_MIN_PD_SPACE 0xC0 */
#define B0_OTFA_SLOWEST_HW_MIN_PD_SPACE_FIELD_SLOWEST_HW_MIN_PD_SPACE_MASK                                        0x000000FF
//========================================
/* REG_OTFA_STATE_MACHINES1 0xC4 */
#define B0_OTFA_STATE_MACHINES1_FIELD_BAA_TID_CNTRS_SM_OUT_MASK                                                   0x00000007
#define B0_OTFA_STATE_MACHINES1_FIELD_PD_PTR_CACHE_CTRL_SM_OUT_MASK                                               0x00000038
#define B0_OTFA_STATE_MACHINES1_FIELD_DESC_CACHE_CTRL_SM_OUT_MASK                                                 0x000000C0
#define B0_OTFA_STATE_MACHINES1_FIELD_MPDU_BUILDER_SM_OUT_MASK                                                    0x00003F00
#define B0_OTFA_STATE_MACHINES1_FIELD_MPDU_DESC_HANDLER_SM_OUT_MASK                                               0x0001C000
#define B0_OTFA_STATE_MACHINES1_FIELD_OTFA_CTRL_SM_OUT_MASK                                                       0x000E0000
#define B0_OTFA_STATE_MACHINES1_FIELD_PD_CACHE_CTRL_SM_OUT_MASK                                                   0x00700000
#define B0_OTFA_STATE_MACHINES1_FIELD_RETRY_DB_CACHE_CTRL_SM_OUT_MASK                                             0x07800000
#define B0_OTFA_STATE_MACHINES1_FIELD_OTFA_IN_IDLE_MASK                                                           0x80000000
//========================================
/* REG_OTFA_STATE_MACHINES2 0xC8 */
#define B0_OTFA_STATE_MACHINES2_FIELD_STD_FETCH_REQ_SM_OUT_MASK                                                   0x0000000F
#define B0_OTFA_STATE_MACHINES2_FIELD_STD_FETCH_ACK_SM_OUT_MASK                                                   0x000000F0
#define B0_OTFA_STATE_MACHINES2_FIELD_TID_ERROR_FIFO_SM_OUT_MASK                                                  0x00000300
#define B0_OTFA_STATE_MACHINES2_FIELD_FRAG_DB_SM_OUT_MASK                                                         0x00000C00
//========================================
/* REG_OTFA_ERROR_IRQ_STATUS 0xCC */
#define B0_OTFA_ERROR_IRQ_STATUS_FIELD_TID_ERROR_FIFO_FULL_DROP_IRQ_MASK                                          0x00000001
#define B0_OTFA_ERROR_IRQ_STATUS_FIELD_TID_ERROR_FIFO_DECREMENT_LESS_THAN_ZERO_IRQ_MASK                           0x00000002
//========================================
/* REG_OTFA_ERROR_IRQ_ENABLE 0xD0 */
#define B0_OTFA_ERROR_IRQ_ENABLE_FIELD_TID_ERROR_FIFO_FULL_DROP_IRQ_ENABLED_MASK                                  0x00000001
#define B0_OTFA_ERROR_IRQ_ENABLE_FIELD_TID_ERROR_FIFO_DECREMENT_LESS_THAN_ZERO_IRQ_ENABLED_MASK                   0x00000002
//========================================
/* REG_OTFA_SW_UPDATE_FRAG_DB 0xD4 */
#define B0_OTFA_SW_UPDATE_FRAG_DB_FIELD_SW_UPDATE_FRAG_DB_STA_ID_MASK                                             0x0000007F
#define B0_OTFA_SW_UPDATE_FRAG_DB_FIELD_SW_UPDATE_FRAG_DB_VALUE_MASK                                              0x000F0000
#define B0_OTFA_SW_UPDATE_FRAG_DB_FIELD_SW_UPDATE_FRAG_DB_ACTION_MASK                                             0x00100000
#define B0_OTFA_SW_UPDATE_FRAG_DB_FIELD_SW_UPDATE_FRAG_DB_DONE_MASK                                               0x80000000
//========================================
/* REG_OTFA_HE_TB_MODE 0xD8 */
#define B0_OTFA_HE_TB_MODE_FIELD_BSR_MAX_TIDS_DATA_CONF_MASK                                                      0x0000000F
#define B0_OTFA_HE_TB_MODE_FIELD_BSR_MAX_TIDS_BSRP_CONF_MASK                                                      0x000000F0
#define B0_OTFA_HE_TB_MODE_FIELD_BSR_MAX_TIDS_BA_CONF_MASK                                                        0x00000F00
#define B0_OTFA_HE_TB_MODE_FIELD_HE_TB_MODE_TID_8_BYTE_COUNT_CONF_MASK                                            0x00FF0000
#define B0_OTFA_HE_TB_MODE_FIELD_REPORT_SUM_BYTE_COUNTERS_IN_LAST_TID_CONF_MASK                                   0x80000000
//========================================
/* REG_OTFA_SPARE_REGISTERS 0xFC */
#define B0_OTFA_SPARE_REGISTERS_FIELD_SPARE_REGISTERS_MASK                                                        0x0000FFFF


#endif // _OTFA_REGS_H_
