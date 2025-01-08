
/***********************************************************************************
File:				B1RxClassifierRegs.h
Module:				b1RxClassifier
SOC Revision:		latest
Generated at:       2022-05-04 10:57:55
Purpose:
Description:		This File was auto generated using SOC Online

************************************************************************************/
#ifndef _B1_RX_CLASSIFIER_REGS_H_
#define _B1_RX_CLASSIFIER_REGS_H_

/*---------------------------------------------------------------------------------
/						Registers Addresses													 
/----------------------------------------------------------------------------------*/
#include "HwMemoryMap.h"

#define B1_RX_CLASSIFIER_BASE_ADDRESS                             MEMORY_MAP_UNIT_10057_BASE_ADDRESS
#define	REG_B1_RX_CLASSIFIER_FRAME_CLASS_FILTER_CONTROL     (B1_RX_CLASSIFIER_BASE_ADDRESS + 0x0)
#define	REG_B1_RX_CLASSIFIER_FRAME_DATA_SUBTYPES_CLASS      (B1_RX_CLASSIFIER_BASE_ADDRESS + 0x4)
#define	REG_B1_RX_CLASSIFIER_FRAME_CTRL_SUBTYPES_CLASS      (B1_RX_CLASSIFIER_BASE_ADDRESS + 0x8)
#define	REG_B1_RX_CLASSIFIER_FRAME_MGMT_SUBTYPES_CLASS      (B1_RX_CLASSIFIER_BASE_ADDRESS + 0xC)
#define	REG_B1_RX_CLASSIFIER_FRAME_MGMT_ACTION_CLASS        (B1_RX_CLASSIFIER_BASE_ADDRESS + 0x10)
#define	REG_B1_RX_CLASSIFIER_DLM_SEC_LIST_IDX               (B1_RX_CLASSIFIER_BASE_ADDRESS + 0x40)
#define	REG_B1_RX_CLASSIFIER_DLM_IF_DBG                     (B1_RX_CLASSIFIER_BASE_ADDRESS + 0x44)
#define	REG_B1_RX_CLASSIFIER_WPA_SEC_PASS_THROUGH_VAP_EN    (B1_RX_CLASSIFIER_BASE_ADDRESS + 0x48)
#define	REG_B1_RX_CLASSIFIER_MPDU_HDR_FIELDS_FILTER_EN      (B1_RX_CLASSIFIER_BASE_ADDRESS + 0x4C)
#define	REG_B1_RX_CLASSIFIER_RD_TYPE_DROP_VALUE             (B1_RX_CLASSIFIER_BASE_ADDRESS + 0x50)
#define	REG_B1_RX_CLASSIFIER_RXQ_ID_FILTER0                 (B1_RX_CLASSIFIER_BASE_ADDRESS + 0x60)
#define	REG_B1_RX_CLASSIFIER_RXQ_ID_FILTER1                 (B1_RX_CLASSIFIER_BASE_ADDRESS + 0x64)
#define	REG_B1_RX_CLASSIFIER_RXQ_ID_FILTER2                 (B1_RX_CLASSIFIER_BASE_ADDRESS + 0x68)
#define	REG_B1_RX_CLASSIFIER_RXQ_ID_FILTER3                 (B1_RX_CLASSIFIER_BASE_ADDRESS + 0x6C)
#define	REG_B1_RX_CLASSIFIER_RXQ_ID_FILTER4                 (B1_RX_CLASSIFIER_BASE_ADDRESS + 0x70)
#define	REG_B1_RX_CLASSIFIER_RXQ_ID_FILTER5                 (B1_RX_CLASSIFIER_BASE_ADDRESS + 0x74)
#define	REG_B1_RX_CLASSIFIER_RXQ_ID_FILTER6                 (B1_RX_CLASSIFIER_BASE_ADDRESS + 0x78)
#define	REG_B1_RX_CLASSIFIER_RXQ_ID_FILTER7                 (B1_RX_CLASSIFIER_BASE_ADDRESS + 0x7C)
#define	REG_B1_RX_CLASSIFIER_RXQ_ID_FILTER8                 (B1_RX_CLASSIFIER_BASE_ADDRESS + 0x80)
#define	REG_B1_RX_CLASSIFIER_RXQ_ID_FILTER9                 (B1_RX_CLASSIFIER_BASE_ADDRESS + 0x84)
#define	REG_B1_RX_CLASSIFIER_RXQ_ID_FILTER10                (B1_RX_CLASSIFIER_BASE_ADDRESS + 0x88)
#define	REG_B1_RX_CLASSIFIER_RXQ_ID_FILTER11                (B1_RX_CLASSIFIER_BASE_ADDRESS + 0x8C)
#define	REG_B1_RX_CLASSIFIER_RXQ_ID_FILTER12                (B1_RX_CLASSIFIER_BASE_ADDRESS + 0x90)
#define	REG_B1_RX_CLASSIFIER_RXQ_ID_FILTER13                (B1_RX_CLASSIFIER_BASE_ADDRESS + 0x94)
#define	REG_B1_RX_CLASSIFIER_RXQ_ID_FILTER14                (B1_RX_CLASSIFIER_BASE_ADDRESS + 0x98)
#define	REG_B1_RX_CLASSIFIER_RXQ_ID_FILTER15                (B1_RX_CLASSIFIER_BASE_ADDRESS + 0x9C)
#define	REG_B1_RX_CLASSIFIER_RXQ_ID_FILTER_CONTROL          (B1_RX_CLASSIFIER_BASE_ADDRESS + 0xA0)
#define	REG_B1_RX_CLASSIFIER_RX_CLASSIFIER_ENABLE           (B1_RX_CLASSIFIER_BASE_ADDRESS + 0xB0)
#define	REG_B1_RX_CLASSIFIER_WEP_KEY_IDX_DB_LOCATION        (B1_RX_CLASSIFIER_BASE_ADDRESS + 0xB4)
#define	REG_B1_RX_CLASSIFIER_RX_CLAS_RTD_CTRL               (B1_RX_CLASSIFIER_BASE_ADDRESS + 0x100)
#define	REG_B1_RX_CLASSIFIER_RX_CLAS_SM_DBG                 (B1_RX_CLASSIFIER_BASE_ADDRESS + 0x114)
#define	REG_B1_RX_CLASSIFIER_RX_CLAS_LOGGER_CONTROL         (B1_RX_CLASSIFIER_BASE_ADDRESS + 0x134)
#define	REG_B1_RX_CLASSIFIER_RX_CLAS_LOGGER_ACTIVE          (B1_RX_CLASSIFIER_BASE_ADDRESS + 0x138)
#define	REG_B1_RX_CLASSIFIER_SPARE_REGISTERS                (B1_RX_CLASSIFIER_BASE_ADDRESS + 0x1FC)
/*---------------------------------------------------------------------------------
/						Data Type Definition										
/----------------------------------------------------------------------------------*/
/*REG_B1_RX_CLASSIFIER_FRAME_CLASS_FILTER_CONTROL 0x0 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 frameClassFilterAddr2ValidDropEn : 1; //Enable frame class drop filter when Addr2 index is valid, reset value: 0x1, access type: RW
		uint32 frameClassFilterAddr2InvalidDropEn : 1; //Enable frame class drop filter when Addr2 index is invalid, reset value: 0x1, access type: RW
		uint32 vapStaMisFilterDropEn : 1; //Enable VAP-STA mismatch drop filter, reset value: 0x1, access type: RW
		uint32 reserved0 : 1;
		uint32 addr2InvalidDropMpduClassVal : 2; //MPDU frame class to be dropped in case of addr2 index is not valid, reset value: 0x3, access type: RW
		uint32 vapStaMisDropMpduClassVal : 2; //MPDU frame class to be dropped in case of VAP-STA mismatch, reset value: 0x3, access type: RW
		uint32 reserved1 : 24;
	} bitFields;
} RegB1RxClassifierFrameClassFilterControl_u;

/*REG_B1_RX_CLASSIFIER_FRAME_DATA_SUBTYPES_CLASS 0x4 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 frameDataSubtypesClass : 32; //no description, reset value: 0xffffffff, access type: RW
	} bitFields;
} RegB1RxClassifierFrameDataSubtypesClass_u;

/*REG_B1_RX_CLASSIFIER_FRAME_CTRL_SUBTYPES_CLASS 0x8 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 frameCtrlSubtypesClass : 32; //no description, reset value: 0x557fffff, access type: RW
	} bitFields;
} RegB1RxClassifierFrameCtrlSubtypesClass_u;

/*REG_B1_RX_CLASSIFIER_FRAME_MGMT_SUBTYPES_CLASS 0xC */
typedef union
{
	uint32 val;
	struct
	{
		uint32 frameMgmtSubtypesClass : 32; //no description, reset value: 0xfd65f5aa, access type: RW
	} bitFields;
} RegB1RxClassifierFrameMgmtSubtypesClass_u;

/*REG_B1_RX_CLASSIFIER_FRAME_MGMT_ACTION_CLASS 0x10 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 frameMgmtAction4Class : 2; //no description, reset value: 0x1, access type: RW
		uint32 frameMgmtAction15Class : 2; //no description, reset value: 0x1, access type: RW
		uint32 frameMgmtActionOtherClass : 2; //no description, reset value: 0x3, access type: RW
		uint32 reserved0 : 26;
	} bitFields;
} RegB1RxClassifierFrameMgmtActionClass_u;

/*REG_B1_RX_CLASSIFIER_DLM_SEC_LIST_IDX 0x40 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 dlmSecListIdx : 8; //Rx MPDU descriptor DLM list index of Security engine user0, reset value: 0x8, access type: RW
		uint32 reserved0 : 24;
	} bitFields;
} RegB1RxClassifierDlmSecListIdx_u;

/*REG_B1_RX_CLASSIFIER_DLM_IF_DBG 0x44 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 dlmOutFifoNumEntries : 2; //DLM out FIFO number of entries, reset value: 0x0, access type: RO
		uint32 reserved0 : 5;
		uint32 dlmOutFifoCleanStb : 1; //DLM out FIFO clean strobe, reset value: 0x0, access type: WO
		uint32 dlmInFifoNumEntries : 2; //DLM in FIFO number of entries, reset value: 0x0, access type: RO
		uint32 reserved1 : 5;
		uint32 dlmInFifoCleanStb : 1; //DLM in FIFO clean strobe, reset value: 0x0, access type: WO
		uint32 reserved2 : 16;
	} bitFields;
} RegB1RxClassifierDlmIfDbg_u;

/*REG_B1_RX_CLASSIFIER_WPA_SEC_PASS_THROUGH_VAP_EN 0x48 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 wpaSecPassThroughVapEn : 32; //Enable setting RD type of WPA in case of Protected and security mismatch. , 1 bit per VAP, reset value: 0x0, access type: RW
	} bitFields;
} RegB1RxClassifierWpaSecPassThroughVapEn_u;

/*REG_B1_RX_CLASSIFIER_MPDU_HDR_FIELDS_FILTER_EN 0x4C */
typedef union
{
	uint32 val;
	struct
	{
		uint32 mpduHdrFcFieldsFilterEn : 8; //MPDU header Frame control fields filter enable, 1bit per group., reset value: 0x0, access type: RW
		uint32 mpduHdrQosFieldsFilterEn : 8; //MPDU header QoS control fields filter enable, 1bit per group., reset value: 0x0, access type: RW
		uint32 mpduHdrHtcFieldsFilterEn : 8; //MPDU header HT control fields filter enable, 1bit per group., reset value: 0x0, access type: RW
		uint32 reserved0 : 8;
	} bitFields;
} RegB1RxClassifierMpduHdrFieldsFilterEn_u;

/*REG_B1_RX_CLASSIFIER_RD_TYPE_DROP_VALUE 0x50 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 rdTypeDropValue : 5; //RD type value of DROP, reset value: 0x9, access type: RW
		uint32 reserved0 : 27;
	} bitFields;
} RegB1RxClassifierRdTypeDropValue_u;

/*REG_B1_RX_CLASSIFIER_RXQ_ID_FILTER0 0x60 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 rxqIdFilter0DropEn : 1; //Enable RXQ-ID filter drop indication, reset value: 0x0, access type: RW
		uint32 reserved0 : 1;
		uint32 rxqIdFilter0FrameType : 2; //Field frame type in RXQ-ID filter, reset value: 0x0, access type: RW
		uint32 rxqIdFilter0TypeNa : 1; //Field frame type in RXQ-ID filter is N/A, reset value: 0x0, access type: RW
		uint32 rxqIdFilter0FrameSubtype : 4; //Field frame subtype in RXQ-ID filter, reset value: 0x0, access type: RW
		uint32 rxqIdFilter0SubtypeNa : 1; //Field frame subtype in RXQ-ID filter is N/A, reset value: 0x0, access type: RW
		uint32 rxqIdFilter0SubtypeEqual : 1; //Subtype compare logic: , 1: logic of equal , 0: logic of not equal, reset value: 0x0, access type: RW
		uint32 reserved1 : 2;
		uint32 rxqIdFilter0Addr2IdVal : 1; //Address2 index valid bit in RXQ-ID filter, reset value: 0x0, access type: RW
		uint32 rxqIdFilter0Addr2IdValNa : 1; //Address2 index valid bit in RXQ-ID filter is N/A, reset value: 0x0, access type: RW
		uint32 rxqIdFilter0Addr1Unicast : 1; //Address1 unicast bit in RXQ-ID filter, reset value: 0x0, access type: RW
		uint32 rxqIdFilter0Addr1UnicastNa : 1; //Address1 unicast bit in RXQ-ID filter is N/A, reset value: 0x0, access type: RW
		uint32 reserved2 : 15;
	} bitFields;
} RegB1RxClassifierRxqIdFilter0_u;

/*REG_B1_RX_CLASSIFIER_RXQ_ID_FILTER1 0x64 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 rxqIdFilter1DropEn : 1; //Enable RXQ-ID filter drop indication, reset value: 0x0, access type: RW
		uint32 reserved0 : 1;
		uint32 rxqIdFilter1FrameType : 2; //Field frame type in RXQ-ID filter, reset value: 0x0, access type: RW
		uint32 rxqIdFilter1TypeNa : 1; //Field frame type in RXQ-ID filter is N/A, reset value: 0x0, access type: RW
		uint32 rxqIdFilter1FrameSubtype : 4; //Field frame subtype in RXQ-ID filter, reset value: 0x0, access type: RW
		uint32 rxqIdFilter1SubtypeNa : 1; //Field frame subtype in RXQ-ID filter is N/A, reset value: 0x0, access type: RW
		uint32 rxqIdFilter1SubtypeEqual : 1; //Subtype compare logic: , 1: logic of equal , 0: logic of not equal, reset value: 0x0, access type: RW
		uint32 reserved1 : 2;
		uint32 rxqIdFilter1Addr2IdVal : 1; //Address2 index valid bit in RXQ-ID filter, reset value: 0x0, access type: RW
		uint32 rxqIdFilter1Addr2IdValNa : 1; //Address2 index valid bit in RXQ-ID filter is N/A, reset value: 0x0, access type: RW
		uint32 rxqIdFilter1Addr1Unicast : 1; //Address1 unicast bit in RXQ-ID filter, reset value: 0x0, access type: RW
		uint32 rxqIdFilter1Addr1UnicastNa : 1; //Address1 unicast bit in RXQ-ID filter is N/A, reset value: 0x0, access type: RW
		uint32 reserved2 : 15;
	} bitFields;
} RegB1RxClassifierRxqIdFilter1_u;

/*REG_B1_RX_CLASSIFIER_RXQ_ID_FILTER2 0x68 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 rxqIdFilter2DropEn : 1; //Enable RXQ-ID filter drop indication, reset value: 0x0, access type: RW
		uint32 reserved0 : 1;
		uint32 rxqIdFilter2FrameType : 2; //Field frame type in RXQ-ID filter, reset value: 0x0, access type: RW
		uint32 rxqIdFilter2TypeNa : 1; //Field frame type in RXQ-ID filter is N/A, reset value: 0x0, access type: RW
		uint32 rxqIdFilter2FrameSubtype : 4; //Field frame subtype in RXQ-ID filter, reset value: 0x0, access type: RW
		uint32 rxqIdFilter2SubtypeNa : 1; //Field frame subtype in RXQ-ID filter is N/A, reset value: 0x0, access type: RW
		uint32 rxqIdFilter2SubtypeEqual : 1; //Subtype compare logic: , 1: logic of equal , 0: logic of not equal, reset value: 0x0, access type: RW
		uint32 reserved1 : 2;
		uint32 rxqIdFilter2Addr2IdVal : 1; //Address2 index valid bit in RXQ-ID filter, reset value: 0x0, access type: RW
		uint32 rxqIdFilter2Addr2IdValNa : 1; //Address2 index valid bit in RXQ-ID filter is N/A, reset value: 0x0, access type: RW
		uint32 rxqIdFilter2Addr1Unicast : 1; //Address1 unicast bit in RXQ-ID filter, reset value: 0x0, access type: RW
		uint32 rxqIdFilter2Addr1UnicastNa : 1; //Address1 unicast bit in RXQ-ID filter is N/A, reset value: 0x0, access type: RW
		uint32 reserved2 : 15;
	} bitFields;
} RegB1RxClassifierRxqIdFilter2_u;

/*REG_B1_RX_CLASSIFIER_RXQ_ID_FILTER3 0x6C */
typedef union
{
	uint32 val;
	struct
	{
		uint32 rxqIdFilter3DropEn : 1; //Enable RXQ-ID filter drop indication, reset value: 0x0, access type: RW
		uint32 reserved0 : 1;
		uint32 rxqIdFilter3FrameType : 2; //Field frame type in RXQ-ID filter, reset value: 0x0, access type: RW
		uint32 rxqIdFilter3TypeNa : 1; //Field frame type in RXQ-ID filter is N/A, reset value: 0x0, access type: RW
		uint32 rxqIdFilter3FrameSubtype : 4; //Field frame subtype in RXQ-ID filter, reset value: 0x0, access type: RW
		uint32 rxqIdFilter3SubtypeNa : 1; //Field frame subtype in RXQ-ID filter is N/A, reset value: 0x0, access type: RW
		uint32 rxqIdFilter3SubtypeEqual : 1; //Subtype compare logic: , 1: logic of equal , 0: logic of not equal, reset value: 0x0, access type: RW
		uint32 reserved1 : 2;
		uint32 rxqIdFilter3Addr2IdVal : 1; //Address2 index valid bit in RXQ-ID filter, reset value: 0x0, access type: RW
		uint32 rxqIdFilter3Addr2IdValNa : 1; //Address2 index valid bit in RXQ-ID filter is N/A, reset value: 0x0, access type: RW
		uint32 rxqIdFilter3Addr1Unicast : 1; //Address1 unicast bit in RXQ-ID filter, reset value: 0x0, access type: RW
		uint32 rxqIdFilter3Addr1UnicastNa : 1; //Address1 unicast bit in RXQ-ID filter is N/A, reset value: 0x0, access type: RW
		uint32 reserved2 : 15;
	} bitFields;
} RegB1RxClassifierRxqIdFilter3_u;

/*REG_B1_RX_CLASSIFIER_RXQ_ID_FILTER4 0x70 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 rxqIdFilter4DropEn : 1; //Enable RXQ-ID filter drop indication, reset value: 0x0, access type: RW
		uint32 reserved0 : 1;
		uint32 rxqIdFilter4FrameType : 2; //Field frame type in RXQ-ID filter, reset value: 0x0, access type: RW
		uint32 rxqIdFilter4TypeNa : 1; //Field frame type in RXQ-ID filter is N/A, reset value: 0x0, access type: RW
		uint32 rxqIdFilter4FrameSubtype : 4; //Field frame subtype in RXQ-ID filter, reset value: 0x0, access type: RW
		uint32 rxqIdFilter4SubtypeNa : 1; //Field frame subtype in RXQ-ID filter is N/A, reset value: 0x0, access type: RW
		uint32 rxqIdFilter4SubtypeEqual : 1; //Subtype compare logic: , 1: logic of equal , 0: logic of not equal, reset value: 0x0, access type: RW
		uint32 reserved1 : 2;
		uint32 rxqIdFilter4Addr2IdVal : 1; //Address2 index valid bit in RXQ-ID filter, reset value: 0x0, access type: RW
		uint32 rxqIdFilter4Addr2IdValNa : 1; //Address2 index valid bit in RXQ-ID filter is N/A, reset value: 0x0, access type: RW
		uint32 rxqIdFilter4Addr1Unicast : 1; //Address1 unicast bit in RXQ-ID filter, reset value: 0x0, access type: RW
		uint32 rxqIdFilter4Addr1UnicastNa : 1; //Address1 unicast bit in RXQ-ID filter is N/A, reset value: 0x0, access type: RW
		uint32 reserved2 : 15;
	} bitFields;
} RegB1RxClassifierRxqIdFilter4_u;

/*REG_B1_RX_CLASSIFIER_RXQ_ID_FILTER5 0x74 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 rxqIdFilter5DropEn : 1; //Enable RXQ-ID filter drop indication, reset value: 0x0, access type: RW
		uint32 reserved0 : 1;
		uint32 rxqIdFilter5FrameType : 2; //Field frame type in RXQ-ID filter, reset value: 0x0, access type: RW
		uint32 rxqIdFilter5TypeNa : 1; //Field frame type in RXQ-ID filter is N/A, reset value: 0x0, access type: RW
		uint32 rxqIdFilter5FrameSubtype : 4; //Field frame subtype in RXQ-ID filter, reset value: 0x0, access type: RW
		uint32 rxqIdFilter5SubtypeNa : 1; //Field frame subtype in RXQ-ID filter is N/A, reset value: 0x0, access type: RW
		uint32 rxqIdFilter5SubtypeEqual : 1; //Subtype compare logic: , 1: logic of equal , 0: logic of not equal, reset value: 0x0, access type: RW
		uint32 reserved1 : 2;
		uint32 rxqIdFilter5Addr2IdVal : 1; //Address2 index valid bit in RXQ-ID filter, reset value: 0x0, access type: RW
		uint32 rxqIdFilter5Addr2IdValNa : 1; //Address2 index valid bit in RXQ-ID filter is N/A, reset value: 0x0, access type: RW
		uint32 rxqIdFilter5Addr1Unicast : 1; //Address1 unicast bit in RXQ-ID filter, reset value: 0x0, access type: RW
		uint32 rxqIdFilter5Addr1UnicastNa : 1; //Address1 unicast bit in RXQ-ID filter is N/A, reset value: 0x0, access type: RW
		uint32 reserved2 : 15;
	} bitFields;
} RegB1RxClassifierRxqIdFilter5_u;

/*REG_B1_RX_CLASSIFIER_RXQ_ID_FILTER6 0x78 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 rxqIdFilter6DropEn : 1; //Enable RXQ-ID filter drop indication, reset value: 0x0, access type: RW
		uint32 reserved0 : 1;
		uint32 rxqIdFilter6FrameType : 2; //Field frame type in RXQ-ID filter, reset value: 0x0, access type: RW
		uint32 rxqIdFilter6TypeNa : 1; //Field frame type in RXQ-ID filter is N/A, reset value: 0x0, access type: RW
		uint32 rxqIdFilter6FrameSubtype : 4; //Field frame subtype in RXQ-ID filter, reset value: 0x0, access type: RW
		uint32 rxqIdFilter6SubtypeNa : 1; //Field frame subtype in RXQ-ID filter is N/A, reset value: 0x0, access type: RW
		uint32 rxqIdFilter6SubtypeEqual : 1; //Subtype compare logic: , 1: logic of equal , 0: logic of not equal, reset value: 0x0, access type: RW
		uint32 reserved1 : 2;
		uint32 rxqIdFilter6Addr2IdVal : 1; //Address2 index valid bit in RXQ-ID filter, reset value: 0x0, access type: RW
		uint32 rxqIdFilter6Addr2IdValNa : 1; //Address2 index valid bit in RXQ-ID filter is N/A, reset value: 0x0, access type: RW
		uint32 rxqIdFilter6Addr1Unicast : 1; //Address1 unicast bit in RXQ-ID filter, reset value: 0x0, access type: RW
		uint32 rxqIdFilter6Addr1UnicastNa : 1; //Address1 unicast bit in RXQ-ID filter is N/A, reset value: 0x0, access type: RW
		uint32 reserved2 : 15;
	} bitFields;
} RegB1RxClassifierRxqIdFilter6_u;

/*REG_B1_RX_CLASSIFIER_RXQ_ID_FILTER7 0x7C */
typedef union
{
	uint32 val;
	struct
	{
		uint32 rxqIdFilter7DropEn : 1; //Enable RXQ-ID filter drop indication, reset value: 0x0, access type: RW
		uint32 reserved0 : 1;
		uint32 rxqIdFilter7FrameType : 2; //Field frame type in RXQ-ID filter, reset value: 0x0, access type: RW
		uint32 rxqIdFilter7TypeNa : 1; //Field frame type in RXQ-ID filter is N/A, reset value: 0x0, access type: RW
		uint32 rxqIdFilter7FrameSubtype : 4; //Field frame subtype in RXQ-ID filter, reset value: 0x0, access type: RW
		uint32 rxqIdFilter7SubtypeNa : 1; //Field frame subtype in RXQ-ID filter is N/A, reset value: 0x0, access type: RW
		uint32 rxqIdFilter7SubtypeEqual : 1; //Subtype compare logic: , 1: logic of equal , 0: logic of not equal, reset value: 0x0, access type: RW
		uint32 reserved1 : 2;
		uint32 rxqIdFilter7Addr2IdVal : 1; //Address2 index valid bit in RXQ-ID filter, reset value: 0x0, access type: RW
		uint32 rxqIdFilter7Addr2IdValNa : 1; //Address2 index valid bit in RXQ-ID filter is N/A, reset value: 0x0, access type: RW
		uint32 rxqIdFilter7Addr1Unicast : 1; //Address1 unicast bit in RXQ-ID filter, reset value: 0x0, access type: RW
		uint32 rxqIdFilter7Addr1UnicastNa : 1; //Address1 unicast bit in RXQ-ID filter is N/A, reset value: 0x0, access type: RW
		uint32 reserved2 : 15;
	} bitFields;
} RegB1RxClassifierRxqIdFilter7_u;

/*REG_B1_RX_CLASSIFIER_RXQ_ID_FILTER8 0x80 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 rxqIdFilter8DropEn : 1; //Enable RXQ-ID filter drop indication, reset value: 0x0, access type: RW
		uint32 reserved0 : 1;
		uint32 rxqIdFilter8FrameType : 2; //Field frame type in RXQ-ID filter, reset value: 0x0, access type: RW
		uint32 rxqIdFilter8TypeNa : 1; //Field frame type in RXQ-ID filter is N/A, reset value: 0x0, access type: RW
		uint32 rxqIdFilter8FrameSubtype : 4; //Field frame subtype in RXQ-ID filter, reset value: 0x0, access type: RW
		uint32 rxqIdFilter8SubtypeNa : 1; //Field frame subtype in RXQ-ID filter is N/A, reset value: 0x0, access type: RW
		uint32 rxqIdFilter8SubtypeEqual : 1; //Subtype compare logic: , 1: logic of equal , 0: logic of not equal, reset value: 0x0, access type: RW
		uint32 reserved1 : 2;
		uint32 rxqIdFilter8Addr2IdVal : 1; //Address2 index valid bit in RXQ-ID filter, reset value: 0x0, access type: RW
		uint32 rxqIdFilter8Addr2IdValNa : 1; //Address2 index valid bit in RXQ-ID filter is N/A, reset value: 0x0, access type: RW
		uint32 rxqIdFilter8Addr1Unicast : 1; //Address1 unicast bit in RXQ-ID filter, reset value: 0x0, access type: RW
		uint32 rxqIdFilter8Addr1UnicastNa : 1; //Address1 unicast bit in RXQ-ID filter is N/A, reset value: 0x0, access type: RW
		uint32 reserved2 : 15;
	} bitFields;
} RegB1RxClassifierRxqIdFilter8_u;

/*REG_B1_RX_CLASSIFIER_RXQ_ID_FILTER9 0x84 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 rxqIdFilter9DropEn : 1; //Enable RXQ-ID filter drop indication, reset value: 0x0, access type: RW
		uint32 reserved0 : 1;
		uint32 rxqIdFilter9FrameType : 2; //Field frame type in RXQ-ID filter, reset value: 0x0, access type: RW
		uint32 rxqIdFilter9TypeNa : 1; //Field frame type in RXQ-ID filter is N/A, reset value: 0x0, access type: RW
		uint32 rxqIdFilter9FrameSubtype : 4; //Field frame subtype in RXQ-ID filter, reset value: 0x0, access type: RW
		uint32 rxqIdFilter9SubtypeNa : 1; //Field frame subtype in RXQ-ID filter is N/A, reset value: 0x0, access type: RW
		uint32 rxqIdFilter9SubtypeEqual : 1; //Subtype compare logic: , 1: logic of equal , 0: logic of not equal, reset value: 0x0, access type: RW
		uint32 reserved1 : 2;
		uint32 rxqIdFilter9Addr2IdVal : 1; //Address2 index valid bit in RXQ-ID filter, reset value: 0x0, access type: RW
		uint32 rxqIdFilter9Addr2IdValNa : 1; //Address2 index valid bit in RXQ-ID filter is N/A, reset value: 0x0, access type: RW
		uint32 rxqIdFilter9Addr1Unicast : 1; //Address1 unicast bit in RXQ-ID filter, reset value: 0x0, access type: RW
		uint32 rxqIdFilter9Addr1UnicastNa : 1; //Address1 unicast bit in RXQ-ID filter is N/A, reset value: 0x0, access type: RW
		uint32 reserved2 : 15;
	} bitFields;
} RegB1RxClassifierRxqIdFilter9_u;

/*REG_B1_RX_CLASSIFIER_RXQ_ID_FILTER10 0x88 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 rxqIdFilter10DropEn : 1; //Enable RXQ-ID filter drop indication, reset value: 0x0, access type: RW
		uint32 reserved0 : 1;
		uint32 rxqIdFilter10FrameType : 2; //Field frame type in RXQ-ID filter, reset value: 0x0, access type: RW
		uint32 rxqIdFilter10TypeNa : 1; //Field frame type in RXQ-ID filter is N/A, reset value: 0x0, access type: RW
		uint32 rxqIdFilter10FrameSubtype : 4; //Field frame subtype in RXQ-ID filter, reset value: 0x0, access type: RW
		uint32 rxqIdFilter10SubtypeNa : 1; //Field frame subtype in RXQ-ID filter is N/A, reset value: 0x0, access type: RW
		uint32 rxqIdFilter10SubtypeEqual : 1; //Subtype compare logic: , 1: logic of equal , 0: logic of not equal, reset value: 0x0, access type: RW
		uint32 reserved1 : 2;
		uint32 rxqIdFilter10Addr2IdVal : 1; //Address2 index valid bit in RXQ-ID filter, reset value: 0x0, access type: RW
		uint32 rxqIdFilter10Addr2IdValNa : 1; //Address2 index valid bit in RXQ-ID filter is N/A, reset value: 0x0, access type: RW
		uint32 rxqIdFilter10Addr1Unicast : 1; //Address1 unicast bit in RXQ-ID filter, reset value: 0x0, access type: RW
		uint32 rxqIdFilter10Addr1UnicastNa : 1; //Address1 unicast bit in RXQ-ID filter is N/A, reset value: 0x0, access type: RW
		uint32 reserved2 : 15;
	} bitFields;
} RegB1RxClassifierRxqIdFilter10_u;

/*REG_B1_RX_CLASSIFIER_RXQ_ID_FILTER11 0x8C */
typedef union
{
	uint32 val;
	struct
	{
		uint32 rxqIdFilter11DropEn : 1; //Enable RXQ-ID filter drop indication, reset value: 0x0, access type: RW
		uint32 reserved0 : 1;
		uint32 rxqIdFilter11FrameType : 2; //Field frame type in RXQ-ID filter, reset value: 0x0, access type: RW
		uint32 rxqIdFilter11TypeNa : 1; //Field frame type in RXQ-ID filter is N/A, reset value: 0x0, access type: RW
		uint32 rxqIdFilter11FrameSubtype : 4; //Field frame subtype in RXQ-ID filter, reset value: 0x0, access type: RW
		uint32 rxqIdFilter11SubtypeNa : 1; //Field frame subtype in RXQ-ID filter is N/A, reset value: 0x0, access type: RW
		uint32 rxqIdFilter11SubtypeEqual : 1; //Subtype compare logic: , 1: logic of equal , 0: logic of not equal, reset value: 0x0, access type: RW
		uint32 reserved1 : 2;
		uint32 rxqIdFilter11Addr2IdVal : 1; //Address2 index valid bit in RXQ-ID filter, reset value: 0x0, access type: RW
		uint32 rxqIdFilter11Addr2IdValNa : 1; //Address2 index valid bit in RXQ-ID filter is N/A, reset value: 0x0, access type: RW
		uint32 rxqIdFilter11Addr1Unicast : 1; //Address1 unicast bit in RXQ-ID filter, reset value: 0x0, access type: RW
		uint32 rxqIdFilter11Addr1UnicastNa : 1; //Address1 unicast bit in RXQ-ID filter is N/A, reset value: 0x0, access type: RW
		uint32 reserved2 : 15;
	} bitFields;
} RegB1RxClassifierRxqIdFilter11_u;

/*REG_B1_RX_CLASSIFIER_RXQ_ID_FILTER12 0x90 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 rxqIdFilter12DropEn : 1; //Enable RXQ-ID filter drop indication, reset value: 0x0, access type: RW
		uint32 reserved0 : 1;
		uint32 rxqIdFilter12FrameType : 2; //Field frame type in RXQ-ID filter, reset value: 0x0, access type: RW
		uint32 rxqIdFilter12TypeNa : 1; //Field frame type in RXQ-ID filter is N/A, reset value: 0x0, access type: RW
		uint32 rxqIdFilter12FrameSubtype : 4; //Field frame subtype in RXQ-ID filter, reset value: 0x0, access type: RW
		uint32 rxqIdFilter12SubtypeNa : 1; //Field frame subtype in RXQ-ID filter is N/A, reset value: 0x0, access type: RW
		uint32 rxqIdFilter12SubtypeEqual : 1; //Subtype compare logic: , 1: logic of equal , 0: logic of not equal, reset value: 0x0, access type: RW
		uint32 reserved1 : 2;
		uint32 rxqIdFilter12Addr2IdVal : 1; //Address2 index valid bit in RXQ-ID filter, reset value: 0x0, access type: RW
		uint32 rxqIdFilter12Addr2IdValNa : 1; //Address2 index valid bit in RXQ-ID filter is N/A, reset value: 0x0, access type: RW
		uint32 rxqIdFilter12Addr1Unicast : 1; //Address1 unicast bit in RXQ-ID filter, reset value: 0x0, access type: RW
		uint32 rxqIdFilter12Addr1UnicastNa : 1; //Address1 unicast bit in RXQ-ID filter is N/A, reset value: 0x0, access type: RW
		uint32 reserved2 : 15;
	} bitFields;
} RegB1RxClassifierRxqIdFilter12_u;

/*REG_B1_RX_CLASSIFIER_RXQ_ID_FILTER13 0x94 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 rxqIdFilter13DropEn : 1; //Enable RXQ-ID filter drop indication, reset value: 0x0, access type: RW
		uint32 reserved0 : 1;
		uint32 rxqIdFilter13FrameType : 2; //Field frame type in RXQ-ID filter, reset value: 0x0, access type: RW
		uint32 rxqIdFilter13TypeNa : 1; //Field frame type in RXQ-ID filter is N/A, reset value: 0x0, access type: RW
		uint32 rxqIdFilter13FrameSubtype : 4; //Field frame subtype in RXQ-ID filter, reset value: 0x0, access type: RW
		uint32 rxqIdFilter13SubtypeNa : 1; //Field frame subtype in RXQ-ID filter is N/A, reset value: 0x0, access type: RW
		uint32 rxqIdFilter13SubtypeEqual : 1; //Subtype compare logic: , 1: logic of equal , 0: logic of not equal, reset value: 0x0, access type: RW
		uint32 reserved1 : 2;
		uint32 rxqIdFilter13Addr2IdVal : 1; //Address2 index valid bit in RXQ-ID filter, reset value: 0x0, access type: RW
		uint32 rxqIdFilter13Addr2IdValNa : 1; //Address2 index valid bit in RXQ-ID filter is N/A, reset value: 0x0, access type: RW
		uint32 rxqIdFilter13Addr1Unicast : 1; //Address1 unicast bit in RXQ-ID filter, reset value: 0x0, access type: RW
		uint32 rxqIdFilter13Addr1UnicastNa : 1; //Address1 unicast bit in RXQ-ID filter is N/A, reset value: 0x0, access type: RW
		uint32 reserved2 : 15;
	} bitFields;
} RegB1RxClassifierRxqIdFilter13_u;

/*REG_B1_RX_CLASSIFIER_RXQ_ID_FILTER14 0x98 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 rxqIdFilter14DropEn : 1; //Enable RXQ-ID filter drop indication, reset value: 0x0, access type: RW
		uint32 reserved0 : 1;
		uint32 rxqIdFilter14FrameType : 2; //Field frame type in RXQ-ID filter, reset value: 0x0, access type: RW
		uint32 rxqIdFilter14TypeNa : 1; //Field frame type in RXQ-ID filter is N/A, reset value: 0x0, access type: RW
		uint32 rxqIdFilter14FrameSubtype : 4; //Field frame subtype in RXQ-ID filter, reset value: 0x0, access type: RW
		uint32 rxqIdFilter14SubtypeNa : 1; //Field frame subtype in RXQ-ID filter is N/A, reset value: 0x0, access type: RW
		uint32 rxqIdFilter14SubtypeEqual : 1; //Subtype compare logic: , 1: logic of equal , 0: logic of not equal, reset value: 0x0, access type: RW
		uint32 reserved1 : 2;
		uint32 rxqIdFilter14Addr2IdVal : 1; //Address2 index valid bit in RXQ-ID filter, reset value: 0x0, access type: RW
		uint32 rxqIdFilter14Addr2IdValNa : 1; //Address2 index valid bit in RXQ-ID filter is N/A, reset value: 0x0, access type: RW
		uint32 rxqIdFilter14Addr1Unicast : 1; //Address1 unicast bit in RXQ-ID filter, reset value: 0x0, access type: RW
		uint32 rxqIdFilter14Addr1UnicastNa : 1; //Address1 unicast bit in RXQ-ID filter is N/A, reset value: 0x0, access type: RW
		uint32 reserved2 : 15;
	} bitFields;
} RegB1RxClassifierRxqIdFilter14_u;

/*REG_B1_RX_CLASSIFIER_RXQ_ID_FILTER15 0x9C */
typedef union
{
	uint32 val;
	struct
	{
		uint32 rxqIdFilter15DropEn : 1; //Enable RXQ-ID filter drop indication, reset value: 0x0, access type: RW
		uint32 reserved0 : 1;
		uint32 rxqIdFilter15FrameType : 2; //Field frame type in RXQ-ID filter, reset value: 0x0, access type: RW
		uint32 rxqIdFilter15TypeNa : 1; //Field frame type in RXQ-ID filter is N/A, reset value: 0x0, access type: RW
		uint32 rxqIdFilter15FrameSubtype : 4; //Field frame subtype in RXQ-ID filter, reset value: 0x0, access type: RW
		uint32 rxqIdFilter15SubtypeNa : 1; //Field frame subtype in RXQ-ID filter is N/A, reset value: 0x0, access type: RW
		uint32 rxqIdFilter15SubtypeEqual : 1; //Subtype compare logic: , 1: logic of equal , 0: logic of not equal, reset value: 0x0, access type: RW
		uint32 reserved1 : 2;
		uint32 rxqIdFilter15Addr2IdVal : 1; //Address2 index valid bit in RXQ-ID filter, reset value: 0x0, access type: RW
		uint32 rxqIdFilter15Addr2IdValNa : 1; //Address2 index valid bit in RXQ-ID filter is N/A, reset value: 0x0, access type: RW
		uint32 rxqIdFilter15Addr1Unicast : 1; //Address1 unicast bit in RXQ-ID filter, reset value: 0x0, access type: RW
		uint32 rxqIdFilter15Addr1UnicastNa : 1; //Address1 unicast bit in RXQ-ID filter is N/A, reset value: 0x0, access type: RW
		uint32 reserved2 : 15;
	} bitFields;
} RegB1RxClassifierRxqIdFilter15_u;

/*REG_B1_RX_CLASSIFIER_RXQ_ID_FILTER_CONTROL 0xA0 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 rxqIdFilterGroupAndLogic : 3; //The number of filters minus one (starting from filter #0) which gathered as AND group, i.e. the result will be only if all the filters till this value indicate as DROP/Unsupported., reset value: 0x0, access type: RW
		uint32 reserved0 : 29;
	} bitFields;
} RegB1RxClassifierRxqIdFilterControl_u;

/*REG_B1_RX_CLASSIFIER_RX_CLASSIFIER_ENABLE 0xB0 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 rxClasTopEn : 1; //Rx Classifier enable, reset value: 0x0, access type: RW
		uint32 rxClasSecurityEn : 1; //Enable Security engine initiation, reset value: 0x1, access type: RW
		uint32 rxClasRtdGenerationEn : 1; //Enable RD template generation, reset value: 0x1, access type: RW
		uint32 reserved0 : 29;
	} bitFields;
} RegB1RxClassifierRxClassifierEnable_u;

/*REG_B1_RX_CLASSIFIER_WEP_KEY_IDX_DB_LOCATION 0xB4 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 wepWdsKeyIdxDbLocation : 1; //WEP Key Index Location in case of unicast WDS: , 0 - STA DB , 1 - VAP DB, reset value: 0x0, access type: RW
		uint32 wepNoWdsKeyIdxDbLocation : 1; //WEP Key Index Location in case of unicast no WDS: , 0 - STA DB , 1 - VAP DB, reset value: 0x0, access type: RW
		uint32 reserved0 : 30;
	} bitFields;
} RegB1RxClassifierWepKeyIdxDbLocation_u;

/*REG_B1_RX_CLASSIFIER_RX_CLAS_RTD_CTRL 0x100 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 reserved0 : 5;
		uint32 lengthCalcNegativeDropEn : 1; //Set RD type DROP in case of negative length result, reset value: 0x1, access type: RW
		uint32 misDataProtFrameDbDropEn : 1; //Set RD type DROP in case of mismatch between frame protected bit and security enable in DB for Data Frames., reset value: 0x1, access type: RW
		uint32 reserved1 : 25;
	} bitFields;
} RegB1RxClassifierRxClasRtdCtrl_u;

/*REG_B1_RX_CLASSIFIER_RX_CLAS_SM_DBG 0x114 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 rxClassifierSm : 4; //Main Rx Classifier SM, reset value: 0x0, access type: RO
		uint32 rdCirBufSm : 2; //Read Cir buffer SM, reset value: 0x0, access type: RO
		uint32 rdMpduDescSm : 2; //Read MPDU desc SM, reset value: 0x0, access type: RO
		uint32 rxqIdSm : 2; //RxQ ID SM, reset value: 0x0, access type: RO
		uint32 secInitSm : 4; //Security init SM, reset value: 0x0, access type: RO
		uint32 reserved0 : 4;
		uint32 rmdFillSm : 3; //Rx MPDU desc fill SM, reset value: 0x0, access type: RO
		uint32 dlmIfSm : 2; //DLM IF SM, reset value: 0x0, access type: RO
		uint32 mpduFieldsFilterSm : 3; //MPDU fields filter SM, reset value: 0x0, access type: RO
		uint32 rdSecHdrSm : 2; //Read Security header SM, reset value: 0x0, access type: RO
		uint32 reserved1 : 4;
	} bitFields;
} RegB1RxClassifierRxClasSmDbg_u;

/*REG_B1_RX_CLASSIFIER_RX_CLAS_LOGGER_CONTROL 0x134 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 rxClasLoggerEn : 1; //Rx Classifier logger enable, reset value: 0x0, access type: RW
		uint32 reserved0 : 7;
		uint32 rxClasLoggerPriority : 2; //Rx Classifier logger priority, reset value: 0x0, access type: RW
		uint32 reserved1 : 22;
	} bitFields;
} RegB1RxClassifierRxClasLoggerControl_u;

/*REG_B1_RX_CLASSIFIER_RX_CLAS_LOGGER_ACTIVE 0x138 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 rxClasLoggerActive : 1; //Rx Classifier logger active indication, reset value: 0x0, access type: RO
		uint32 reserved0 : 31;
	} bitFields;
} RegB1RxClassifierRxClasLoggerActive_u;

/*REG_B1_RX_CLASSIFIER_SPARE_REGISTERS 0x1FC */
typedef union
{
	uint32 val;
	struct
	{
		uint32 spareRegisters : 16; //Spare registers, reset value: 0x8888, access type: RW
		uint32 reserved0 : 16;
	} bitFields;
} RegB1RxClassifierSpareRegisters_u;



#endif // _B1_RX_CLASSIFIER_REGS_H_
