
/***********************************************************************************
File:				Modem11BFeRegs.h
Module:				modem11BFe
SOC Revision:		latest
Generated at:       2022-03-29 07:45:56
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
#ifndef _MODEM_11B_FE_REGS_H_
#define _MODEM_11B_FE_REGS_H_

/*---------------------------------------------------------------------------------
/						Registers Addresses													 
/----------------------------------------------------------------------------------*/
#include "HwMemoryMap.h"

#define MODEM_11B_FE_BASE_ADDRESS                             MEMORY_MAP_UNIT_52_BASE_ADDRESS
#define	REG_MODEM_11B_FE_FRONTENDCTRL    (MODEM_11B_FE_BASE_ADDRESS + 0xC0E0)
/*---------------------------------------------------------------------------------
/						Data Type Definition										
/----------------------------------------------------------------------------------*/
/*REG_MODEM_11B_FE_FRONTENDCTRL 0xC0E0 */
typedef union
{
	uint32 val;
	struct
	{
		uint32 intDcdisb : 1; //disable the dc offset estimation , reset value: 0x0, access type: RW
		uint32 intScaldisb : 1; //disable scaling, reset value: 0x0, access type: RW
		uint32 intMultscaldisb : 1; //disable amplifier, reset value: 0x0, access type: RW
		uint32 intMultscal : 7; //setting the amplifier's values of scaling_mult and scaling_shift , , reset value: 0x1, access type: RW
		uint32 intDcesttime : 1; //DC estimation time selection , , reset value: 0x0, access type: RW
		uint32 reserved0 : 21;
	} bitFields;
} RegModem11BFeFrontendctrl_u;



#endif // _MODEM_11B_FE_REGS_H_
