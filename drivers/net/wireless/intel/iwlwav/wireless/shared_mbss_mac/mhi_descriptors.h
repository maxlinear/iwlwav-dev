/******************************************************************************

COPYRIGHT:
  Copyright(c) 2020 - 2025, MaxLinear, Inc.
  Copyright 2016 - 2020 Intel Corporation
  Copyright 2014 - 2016 Lantiq Beteiligungs - GmbH & Co.KG
  Copyright 2010 - 2014 Lantiq Deutschland GmbH
  Copyright 2007 - 2010 Metalink Ltd.

  For licensing information, see the file 'LICENSE' in the root folder of this software module.

******************************************************************************/

#ifndef __MHI_DESC_INCLUDED_H
#define __MHI_DESC_INCLUDED_H

//#include "mtlkpack.h"
//#define __MTLK_PACKED
#define BYTE_OFFSET_MASK   0x3
#define PACKET_DESC_SIZE  36



typedef struct _HOST_DSC
{
    uint32    u32frameInfo0;
    uint32    u32frameInfo1;
    uint32    u32HostPayloadAddr;
    uint32    u32frameInfo3;
    uint32    u32BdIndex;
} __MTLK_PACKED HOST_DSC;










#endif // __MHI_DESC_INCLUDED_H


