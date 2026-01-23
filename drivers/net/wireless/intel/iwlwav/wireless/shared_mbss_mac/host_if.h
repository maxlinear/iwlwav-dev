/******************************************************************************

COPYRIGHT:
  Copyright(c) 2020 - 2025, MaxLinear, Inc.
  Copyright 2016 - 2020 Intel Corporation
  Copyright 2014 - 2016 Lantiq Beteiligungs - GmbH & Co.KG
  Copyright 2010 - 2014 Lantiq Deutschland GmbH
  Copyright 2007 - 2010 Metalink Ltd.

  For licensing information, see the file 'LICENSE' in the root folder of this software module.

******************************************************************************/

/***************************************************************************
****************************************************************************
**
** COMPONENT:        Host Interface Manager
**
** MODULE:           $File: //bwp/enet/demo153_sw/develop/src/shared/host_if.h $
**
** VERSION:          $Revision: #1 $  
**
** DATED:            $Date: 2003/10/27 $
**
** AUTHOR:           Laurence Evans
**
** DESCRIPTION:      Host interface definition file.
**                      Note:
**                  Most of the messages are passed transparently between the
**                  Host and the MAC and so are deifned in umi.h
**
** CHANGE HISTORY:
**  
**   Initial revision
**
** LAST MODIFIED BY:   $Author: njk $
**                     $Modtime:$
**
****************************************************************************
*
* 
* 
* 
*
****************************************************************************/

#ifndef HOST_IF_INCLUDED
#define HOST_IF_INCLUDED

#define   MTLK_PACK_ON
#include "mtlkpack.h"

/***************************************************************************/
/***                       Types and Defines                             ***/
/***************************************************************************/

#define HOST_MAGIC                  0xBEADFEED



/***************************************************************************/
/***                            Message Structures                       ***/
/***************************************************************************/

/***************************************************************************
**
** NAME         HOST_DAT_TRANSFER_CFM
**              HOST_MAN_TRANSFER_CFM
**              HOST_DBG_TRANSFER_CFM
** 
** PARAMETERS   None.
**
** DESCRIPTION  These message will be sent by the HIM to the Host to transfer
**              Message Buffers to the Host for use by the host as Request
**              messages.
**
****************************************************************************/


#define  MTLK_PACK_OFF
#include "mtlkpack.h"

#endif /* HOST_IF_INCLUDED */
