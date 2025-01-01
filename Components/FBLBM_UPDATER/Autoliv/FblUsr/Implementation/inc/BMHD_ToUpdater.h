/****************************************************************
*
*  Filename:      S:\Tools\Vector_configuration\Workspace\fblupdater\BMHD0\bmhd.h
*  Project:       Exported definition of C-Array Flash-Driver
*  File created:  Wed May  3 19:45:24 2023

*
****************************************************************/

#ifndef __FBLUPDBMHDFIELD_TOUPDATER__
#define __FBLUPDBMHDFIELD_TOUPDATER__
#define FBLUPDBMHDFIELD_TOUPDATER_GEN_RAND 28738

#define FBLUPDBMHDFIELD_TOUPDATER_NUMBLOCKS 1

#define FBLUPDBMHDFIELD_TOUPDATER_DECRYPTDATA(a)   (vuint8)(a)

/* Definition of the structure that stores address and length info */
typedef struct _tFblUpdBmhdField_ToUpdaterBlkInfo
{
   FBL_ADDR_TYPE     blockAddress;
   FBL_MEMSIZE_TYPE  blockLength;
   V_MEMROM1  vuint8 V_MEMROM2 * V_MEMROM3 blockSource;
} tFblUpdBmhdField_ToUpdaterBlkInfo;

V_MEMROM0 extern V_MEMROM1 tFblUpdBmhdField_ToUpdaterBlkInfo V_MEMROM2 FblUpdBmhdField_ToUpdaterBlkInfo[FBLUPDBMHDFIELD_TOUPDATER_NUMBLOCKS];

#define FBLUPDBMHDFIELD_TOUPDATER_START_SEC_CONST_EXPORT
#include "MemMap.h"

#define FBLUPDBMHDFIELD_TOUPDATER_BLOCK0_ADDRESS	0x0
#define FBLUPDBMHDFIELD_TOUPDATER_BLOCK0_LENGTH	0x200
#define FBLUPDBMHDFIELD_TOUPDATER_BLOCK0_CHECKSUM	0x818u

V_MEMROM0 extern V_MEMROM1 vuint8 V_MEMROM2 FblUpdBmhdField_ToUpdaterBlk0[FBLUPDBMHDFIELD_TOUPDATER_BLOCK0_LENGTH];

#define FBLUPDDFLASHFIELD_TOUPDATERBLK0_BLOCK0_LENGTH	0x200

V_MEMROM0 extern V_MEMROM1 vuint8 V_MEMROM2 FblUpdDFlashField_ToUpdaterBlk0Blk0[FBLUPDDFLASHFIELD_TOUPDATERBLK0_BLOCK0_LENGTH];
#define FBLUPDBMHDFIELD_TOUPDATER_STOP_SEC_CONST_EXPORT
#include "MemMap.h"


#endif    /* #ifdef __FBLUPDBMHDFIELD_TOUPDATER__ */

