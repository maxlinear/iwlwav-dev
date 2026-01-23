
/***********************************************************************************
File:				HobPacTimRegs.h
Module:				hobPacTim
SOC Revision:		
Purpose:
Description:		This File was auto generated using SOC Online

COPYRIGHT:
  Copyright(c) 2020 - 2025, MaxLinear, Inc.
  Copyright 2016 - 2020 Intel Corporation
  Copyright 2014 - 2016 Lantiq Beteiligungs - GmbH & Co.KG
  Copyright 2010 - 2014 Lantiq Deutschland GmbH
  Copyright 2007 - 2010 Metalink Ltd.

  For licensing information, see the file 'LICENSE' in the root folder of this software module.

************************************************************************************/
#ifndef _HOB_PAC_TIM_REGS_H_
#define _HOB_PAC_TIM_REGS_H_

/*---------------------------------------------------------------------------------
/						Registers Addresses													 
/----------------------------------------------------------------------------------*/
#include "HwMemoryMap.h"

#define HOB_PAC_TIM_BASE_ADDRESS                             MEMORY_MAP_UNIT_502_BASE_ADDRESS
#define	REG_HOB_PAC_TIM_LATCHED_TST_FIME_LOW     (HOB_PAC_TIM_BASE_ADDRESS + 0x0)
#define	REG_HOB_PAC_TIM_LATCHED_TST_FIME_HIGH    (HOB_PAC_TIM_BASE_ADDRESS + 0x4)
/*---------------------------------------------------------------------------------
/						Data Type Definition										
/----------------------------------------------------------------------------------*/
/*REG_HOB_PAC_TIM_LATCHED_TST_FIME_LOW 0x0 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 latchedTstFimeLow : 32; //no description, reset value: 0x0, access type: RO
	} bitFields;
} RegHobPacTimLatchedTstFimeLow_u;

/*REG_HOB_PAC_TIM_LATCHED_TST_FIME_HIGH 0x4 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 latchedTstFimeHigh : 32; //no description, reset value: 0x0, access type: RO
	} bitFields;
} RegHobPacTimLatchedTstFimeHigh_u;



#endif // _HOB_PAC_TIM_REGS_H_
