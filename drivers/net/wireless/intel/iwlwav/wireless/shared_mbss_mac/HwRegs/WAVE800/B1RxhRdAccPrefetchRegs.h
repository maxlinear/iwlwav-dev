
/***********************************************************************************
File:				B1RxhRdAccPrefetchRegs.h
Module:				b1RxhRdAccPrefetch
SOC Revision:		latest
Generated at:       2024-06-26 12:54:45
Purpose:
Description:		This File was auto generated using SOC Online

************************************************************************************/
#ifndef _B1_RXH_RD_ACC_PREFETCH_REGS_H_
#define _B1_RXH_RD_ACC_PREFETCH_REGS_H_

/*---------------------------------------------------------------------------------
/						Registers Addresses													 
/----------------------------------------------------------------------------------*/
#include "HwMemoryMap.h"

#define B1_RXH_RD_ACC_PREFETCH_BASE_ADDRESS  MEMORY_MAP_UNIT_10063_BASE_ADDRESS
#define	REG_B1_RXH_RD_ACC_PREFETCH_FIFO_DATA_PREF0    (B1_RXH_RD_ACC_PREFETCH_BASE_ADDRESS + 0x100)
#define	REG_B1_RXH_RD_ACC_PREFETCH_FIFO_DATA_PREF1    (B1_RXH_RD_ACC_PREFETCH_BASE_ADDRESS + 0x104)
#define	REG_B1_RXH_RD_ACC_PREFETCH_FIFO_DATA_PREF2    (B1_RXH_RD_ACC_PREFETCH_BASE_ADDRESS + 0x108)
/*---------------------------------------------------------------------------------
/						Data Type Definition										
/----------------------------------------------------------------------------------*/
/*REG_B1_RXH_RD_ACC_PREFETCH_FIFO_DATA_PREF0 0x100 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 fifoDataPref0 : 32; //RD-Acc Prefetcher read data: APB read access is routed to the HW block (not to the reg-file).  , The reg is dummy; no RTL generated; only RAL., reset value: 0x0, access type: RO
	} bitFields;
} RegB1RxhRdAccPrefetchFifoDataPref0_u;

/*REG_B1_RXH_RD_ACC_PREFETCH_FIFO_DATA_PREF1 0x104 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 fifoDataPref1 : 32; //RD-Acc Prefetcher read data: APB read access is routed to the HW block (not to the reg-file).  , The reg is dummy; no RTL generated; only RAL., reset value: 0x0, access type: RO
	} bitFields;
} RegB1RxhRdAccPrefetchFifoDataPref1_u;

/*REG_B1_RXH_RD_ACC_PREFETCH_FIFO_DATA_PREF2 0x108 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 fifoDataPref2 : 32; //RD-Acc Prefetcher read data: APB read access is routed to the HW block (not to the reg-file).  , The reg is dummy; no RTL generated; only RAL., reset value: 0x0, access type: RO
	} bitFields;
} RegB1RxhRdAccPrefetchFifoDataPref2_u;

//========================================
/* REG_RXH_RD_ACC_PREFETCH_FIFO_DATA_PREF0 0x100 */
#define B1_RXH_RD_ACC_PREFETCH_FIFO_DATA_PREF0_FIELD_FIFO_DATA_PREF0_MASK                                         0xFFFFFFFF
//========================================
/* REG_RXH_RD_ACC_PREFETCH_FIFO_DATA_PREF1 0x104 */
#define B1_RXH_RD_ACC_PREFETCH_FIFO_DATA_PREF1_FIELD_FIFO_DATA_PREF1_MASK                                         0xFFFFFFFF
//========================================
/* REG_RXH_RD_ACC_PREFETCH_FIFO_DATA_PREF2 0x108 */
#define B1_RXH_RD_ACC_PREFETCH_FIFO_DATA_PREF2_FIELD_FIFO_DATA_PREF2_MASK                                         0xFFFFFFFF


#endif // _RXH_RD_ACC_PREFETCH_REGS_H_
