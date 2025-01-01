/****************************************************************
*
*  Filename:      S:\Tools\Vector_configuration\Workspace\fblupdater\BMHD0\bmhd.h
*  Project:       Exported definition of C-Array Flash-Driver
*  File created:  Wed May  3 19:46:26 2023

*
****************************************************************/

#ifndef __FBLUPDBMHDFIELD_TOFBL__
#define __FBLUPDBMHDFIELD_TOFBL__
#define FBLUPDBMHDFIELD_TOFBL_GEN_RAND 28940

#define FBLUPDBMHDFIELD_TOFBL_NUMBLOCKS 1

#define FBLUPDBMHDFIELD_TOFBL_DECRYPTDATA(a)   (vuint8)(a)

/* Definition of the structure that stores address and length info */
typedef struct _tFblUpdBmhdField_ToFblBlkInfo
{
   FBL_ADDR_TYPE     blockAddress;
   FBL_MEMSIZE_TYPE  blockLength;
   V_MEMROM1  vuint8 V_MEMROM2 * V_MEMROM3 blockSource;
} tFblUpdBmhdField_ToFblBlkInfo;

V_MEMROM0 extern V_MEMROM1 tFblUpdBmhdField_ToFblBlkInfo V_MEMROM2 FblUpdBmhdField_ToFblBlkInfo[FBLUPDBMHDFIELD_TOFBL_NUMBLOCKS];

#define FBLUPDBMHDFIELD_TOFBL_START_SEC_CONST_EXPORT
#include "MemMap.h"

#define FBLUPDBMHDFIELD_TOFBL_BLOCK0_ADDRESS	0x0
#define FBLUPDBMHDFIELD_TOFBL_BLOCK0_LENGTH	0x200
#define FBLUPDBMHDFIELD_TOFBL_BLOCK0_CHECKSUM	0x793u

V_MEMROM0 extern V_MEMROM1 vuint8 V_MEMROM2 FblUpdBmhdField_ToFblBlk0[FBLUPDBMHDFIELD_TOFBL_BLOCK0_LENGTH];

#define FBLUPDBMHDFIELD_TOFBL_STOP_SEC_CONST_EXPORT
#include "MemMap.h"


#endif    /* #ifdef __FBLUPDBMHDFIELD_TOFBL__ */

