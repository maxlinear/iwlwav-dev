/***************************************************************
 File:		SecureBoot_definitions.h
 Module:	Secure Boot
 Purpose: 	holds the base address by diver
 Description:  This file contains the definions base addresses
 	 	 	   used by driver of the Secure Boot
 Copyright(c) 2021, MaxLinear, Inc.
***************************************************************/
#ifndef SECUREBOOT_DEFINITIONS_H_
#define SECUREBOOT_DEFINITIONS_H_


//---------------------------------------------------------------------------------
//						Includes
//---------------------------------------------------------------------------------


//---------------------------------------------------------------------------------
//						Defines
//---------------------------------------------------------------------------------

//Common loading addres for WAVE600D2 and WAVE700
	#define SECURE_BOOT_FW_IMAGE_ADDRESS									(0x00000000)

//List with loading address for WAVE600D2
	#define SECURE_BOOT_FW_CERTIFICATE_ADDRESS_WAVE600D2					(0x00400000)
	#define SECURE_BOOT_DUT_CERTIFICATE_ADDRESS_WAVE600D2					(0x004001E8)
	#define SECURE_BOOT_FW_HEADER_ADDRESS_WAVE600D2							(0x004003D0)
	#define SECURE_BOOT_PSD_HEADER_ADDRESS_WAVE600D2						(0x00400558)
	#define SECURE_BOOT_CAL_FILE_HEADER_ADDRESS_WAVE600D2					(0x004006E0)
	#define SECURE_BOOT_TX_SENDER_GENRISC_FIRST_IMAGE_ADDRESS_WAVE600D2		(0x00400868)
//List with loading address for WAVE700
	#define SECURE_BOOT_FW_CERTIFICATE_ADDRESS_WAVE700						(0x00800000)
	#define SECURE_BOOT_DUT_CERTIFICATE_ADDRESS_WAVE700						(0x008001E8)
	#define SECURE_BOOT_FW_HEADER_ADDRESS_WAVE700							(0x008003D0)
	#define SECURE_BOOT_PSD_HEADER_ADDRESS_WAVE700							(0x00800558)
	#define SECURE_BOOT_CAL_FILE_HEADER_ADDRESS_WAVE700						(0x008006E0)
	#define SECURE_BOOT_TX_SENDER_GENRISC_FIRST_IMAGE_ADDRESS_WAVE700		(0x00800868)


//Common loading addres for WAVE600D2 and WAVE700
	#define SECURE_BOOT_TX_SENDER_GENRISC_FIRST_IMAGE_SIZE					(0x00010000)
	#define SECURE_BOOT_RX_HANDLER_GENRISC_SIZE								(0x00004000)

//List with sizes for WAVE600D2
	#define SECURE_BOOT_FW_CERTIFICATE_SIZE_WAVE600D2						(SECURE_BOOT_DUT_CERTIFICATE_ADDRESS_WAVE600D2 - SECURE_BOOT_FW_CERTIFICATE_ADDRESS_WAVE600D2)
	#define SECURE_BOOT_DUT_CERTIFICATE_SIZE_WAVE600D2						(SECURE_BOOT_FW_HEADER_ADDRESS_WAVE600D2 - SECURE_BOOT_DUT_CERTIFICATE_ADDRESS_WAVE600D2)
	#define SECURE_BOOT_FW_HEADER_SIZE_WAVE600D2							(SECURE_BOOT_PSD_HEADER_ADDRESS_WAVE600D2 - SECURE_BOOT_FW_HEADER_ADDRESS_WAVE600D2)
	#define SECURE_BOOT_PSD_HEADER_SIZE_WAVE600D2 							(SECURE_BOOT_CAL_FILE_HEADER_ADDRESS_WAVE600D2 - SECURE_BOOT_PSD_HEADER_ADDRESS_WAVE600D2)
	#define SECURE_BOOT_CAL_FILE_HEADER_SIZE_WAVE600D2						(SECURE_BOOT_TX_SENDER_GENRISC_FIRST_IMAGE_ADDRESS_WAVE600D2 -SECURE_BOOT_CAL_FILE_HEADER_ADDRESS_WAVE600D2)
	#define SECURE_BOOT_HOST_IF_IRAM_SIZE_WAVE600D2							(MAC_GENRISC_HOST_IRAM_SIZE)


//List with sizes for WAVE700
	#define SECURE_BOOT_FW_CERTIFICATE_SIZE_WAVE700					    	(SECURE_BOOT_DUT_CERTIFICATE_ADDRESS_WAVE700 - SECURE_BOOT_FW_CERTIFICATE_ADDRESS_WAVE700)
	#define SECURE_BOOT_DUT_CERTIFICATE_SIZE_WAVE700						(SECURE_BOOT_FW_HEADER_ADDRESS_WAVE700 - SECURE_BOOT_DUT_CERTIFICATE_ADDRESS_WAVE700)
	#define SECURE_BOOT_FW_HEADER_SIZE_WAVE700						    	(SECURE_BOOT_PSD_HEADER_ADDRESS_WAVE700 - SECURE_BOOT_FW_HEADER_ADDRESS_WAVE700)
	#define SECURE_BOOT_PSD_HEADER_SIZE_WAVE700 							(SECURE_BOOT_CAL_FILE_HEADER_ADDRESS_WAVE700 - SECURE_BOOT_PSD_HEADER_ADDRESS_WAVE700)
	#define SECURE_BOOT_CAL_FILE_HEADER_SIZE_WAVE700						(SECURE_BOOT_TX_SENDER_GENRISC_FIRST_IMAGE_ADDRESS_WAVE700 -SECURE_BOOT_CAL_FILE_HEADER_ADDRESS_WAVE700)
	#define SECURE_BOOT_HOST_IF_IRAM_SIZE_WAVE700							(HOST_IF_U_ICCM_RAM0_SIZE)  //this value comes from the file Data-path uC SAS.docx


#endif /* SECUREBOOT_DEFINITIONS_H_ */
