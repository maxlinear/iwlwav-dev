
/***********************************************************************************
File:				TxMdmaRegs.h
Module:				txMdma
SOC Revision:		latest
Generated at:       2022-05-04 10:58:56
Purpose:
Description:		This File was auto generated using SOC Online

************************************************************************************/
#ifndef _TX_MDMA_REGS_H_
#define _TX_MDMA_REGS_H_

/*---------------------------------------------------------------------------------
/						Registers Addresses													 
/----------------------------------------------------------------------------------*/
#include "HwMemoryMap.h"

#define TX_MDMA_BASE_ADDRESS                             MEMORY_MAP_UNIT_50_BASE_ADDRESS
#define	REG_TX_MDMA_DMAE_VER_REG               (TX_MDMA_BASE_ADDRESS + 0x0)
#define	REG_TX_MDMA_DMA_CONFIG_REG             (TX_MDMA_BASE_ADDRESS + 0x4)
#define	REG_TX_MDMA_DESTINATION_ADDRESS_REG    (TX_MDMA_BASE_ADDRESS + 0x8)
#define	REG_TX_MDMA_SOURCE_ADDRESS_REG         (TX_MDMA_BASE_ADDRESS + 0xC)
#define	REG_TX_MDMA_LEN_REG                    (TX_MDMA_BASE_ADDRESS + 0x10)
#define	REG_TX_MDMA_CFG_DIRECT_ACCESS_REG      (TX_MDMA_BASE_ADDRESS + 0x14)
#define	REG_TX_MDMA_CMD_DIRECT_COUNTER_REG     (TX_MDMA_BASE_ADDRESS + 0x18)
#define	REG_TX_MDMA_COUNTER_REG                (TX_MDMA_BASE_ADDRESS + 0x1C)
#define	REG_TX_MDMA_TIMEOUT_CFG_REG            (TX_MDMA_BASE_ADDRESS + 0x20)
#define	REG_TX_MDMA_TIMEOUT_ERROR_REG          (TX_MDMA_BASE_ADDRESS + 0x24)
#define	REG_TX_MDMA_PENDING_JOBS_REG           (TX_MDMA_BASE_ADDRESS + 0x28)
/*---------------------------------------------------------------------------------
/						Data Type Definition										
/----------------------------------------------------------------------------------*/
/*REG_TX_MDMA_DMAE_VER_REG 0x0 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 dmaVerI : 32; //dma_ver, reset value: 0x2, access type: RW
	} bitFields;
} RegTxMdmaDmaeVerReg_u;

/*REG_TX_MDMA_DMA_CONFIG_REG 0x4 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 maxBurst : 16; //max_burst_-_the_DMA_will_deivide_the_transaction_to_several_burst_with_mac_burst_size, reset value: 0x10, access type: RW
		uint32 ddrAlignEnable : 1; //ddr_align_enable-_the_DMA_will_deivide_the_transaction_to_burst_which_align_to_DDR_line_, reset value: 0x0, access type: RW
		uint32 outstanding : 8; //number_outstanding_-_max_outstanding_accordng_the_DMA_define_, reset value: 0x20, access type: RW
		uint32 reserved0 : 3;
		uint32 ddrLine : 4; //ddr_line-_to_be_use_in_DDR_align_access__4_->_16B__5->_32B__6->64__, reset value: 0x6, access type: RW
	} bitFields;
} RegTxMdmaDmaConfigReg_u;

/*REG_TX_MDMA_DESTINATION_ADDRESS_REG 0x8 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 destinationAddressI : 32; //DMA_destination_address, reset value: 0x0, access type: RW
	} bitFields;
} RegTxMdmaDestinationAddressReg_u;

/*REG_TX_MDMA_SOURCE_ADDRESS_REG 0xC */
typedef union
{
	uint32 val;
	struct
	{
		uint32 sourceAddressI : 32; //DMA_source_address, reset value: 0x0, access type: RW
	} bitFields;
} RegTxMdmaSourceAddressReg_u;

/*REG_TX_MDMA_LEN_REG 0x10 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 sizeI : 32; //size, reset value: 0x0, access type: RW
	} bitFields;
} RegTxMdmaLenReg_u;

/*REG_TX_MDMA_CFG_DIRECT_ACCESS_REG 0x14 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 directWnpEnableI : 1; //enable_WNP_transaction, reset value: 0x0, access type: RW
		uint32 directWordSwapI : 1; //enable_word_swap_for_direct_access, reset value: 0x0, access type: RW
		uint32 directByteSwapI : 1; //enable_byte_swap_for_direct_access, reset value: 0x0, access type: RW
		uint32 reserved0 : 28;
		uint32 directDoneAccessI : 1; //done_with_job_requested_from_direct_access_clear_befor_sending_job, reset value: 0x0, access type: RO
	} bitFields;
} RegTxMdmaCfgDirectAccessReg_u;

/*REG_TX_MDMA_CMD_DIRECT_COUNTER_REG 0x18 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 cmdCounterI : 32; //Number_of_command_request_passed_wrap_around__RWV_, reset value: 0x0, access type: RW
	} bitFields;
} RegTxMdmaCmdDirectCounterReg_u;

/*REG_TX_MDMA_COUNTER_REG 0x1C */
typedef union
{
	uint32 val;
	struct
	{
		uint32 cmdCounterI : 32; //Number_of_command_request_passed_wrap_around__RWV_, reset value: 0x0, access type: RW
	} bitFields;
} RegTxMdmaCounterReg_u;

/*REG_TX_MDMA_TIMEOUT_CFG_REG 0x20 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 timeoutCfgI : 32; //timeout, reset value: 0x0, access type: RW
	} bitFields;
} RegTxMdmaTimeoutCfgReg_u;

/*REG_TX_MDMA_TIMEOUT_ERROR_REG 0x24 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 timeoutErrorI : 1; //error, reset value: 0x0, access type: RO
		uint32 reserved0 : 31;
	} bitFields;
} RegTxMdmaTimeoutErrorReg_u;

/*REG_TX_MDMA_PENDING_JOBS_REG 0x28 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 wnpPendingI : 8; //WNP_pending, reset value: 0x0, access type: RO
		uint32 wpPendingI : 8; //WP_pending, reset value: 0x0, access type: RO
		uint32 reserved0 : 16;
	} bitFields;
} RegTxMdmaPendingJobsReg_u;



#endif // _TX_MDMA_REGS_H_
