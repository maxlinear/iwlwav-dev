
/***********************************************************************************
File:				B2HobPacTimRegs.h
Module:				b2HobPacTim
SOC Revision:		latest
Generated at:       2022-05-04 10:58:07
Purpose:
Description:		This File was auto generated using SOC Online

************************************************************************************/
#ifndef _B2_HOB_PAC_TIM_REGS_H_
#define _B2_HOB_PAC_TIM_REGS_H_

/*---------------------------------------------------------------------------------
/						Registers Addresses													 
/----------------------------------------------------------------------------------*/
#include "HwMemoryMap.h"

#define B2_HOB_PAC_TIM_BASE_ADDRESS                             MEMORY_MAP_UNIT_20502_BASE_ADDRESS
#define	REG_B2_HOB_PAC_TIM_LATCHED_TST_FIME_LOW     (B2_HOB_PAC_TIM_BASE_ADDRESS + 0x0)
#define	REG_B2_HOB_PAC_TIM_LATCHED_TST_FIME_HIGH    (B2_HOB_PAC_TIM_BASE_ADDRESS + 0x4)
/*---------------------------------------------------------------------------------
/						Data Type Definition										
/----------------------------------------------------------------------------------*/
/*REG_B2_HOB_PAC_TIM_LATCHED_TST_FIME_LOW 0x0 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 latchedTstFimeLow : 32; //no description, reset value: 0x0, access type: RO
	} bitFields;
} RegB2HobPacTimLatchedTstFimeLow_u;

/*REG_B2_HOB_PAC_TIM_LATCHED_TST_FIME_HIGH 0x4 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 latchedTstFimeHigh : 32; //no description, reset value: 0x0, access type: RO
	} bitFields;
} RegB2HobPacTimLatchedTstFimeHigh_u;



#endif // _B2_HOB_PAC_TIM_REGS_H_
