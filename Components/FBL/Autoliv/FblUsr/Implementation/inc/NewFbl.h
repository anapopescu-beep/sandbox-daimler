/****************************************************************
*
*  Filename:      D:\sk\examples\_common\fblupdater\Appl\\NewFbl.h
*  Project:       Exported definition of C-Array Flash-Driver
*  File created:  Tue Jul 27 15:43:33 2021

*
****************************************************************/

#ifndef __FBLUPDATE__
#define __FBLUPDATE__
#define FBLUPDATE_GEN_RAND 2380

#define FBLUPDATE_NUMBLOCKS 3

#define FBLUPDATE_DECRYPTDATA(a)   (vuint8)(a)

/* Definition of the structure that stores address and length info */
typedef struct _tFblUpdateBlkInfo
{
   FBL_ADDR_TYPE     blockAddress;
   FBL_MEMSIZE_TYPE  blockLength;
   V_MEMROM1  vuint8 V_MEMROM2 * V_MEMROM3 blockSource;
} tFblUpdateBlkInfo;

V_MEMROM0 extern V_MEMROM1 tFblUpdateBlkInfo V_MEMROM2 FblUpdateBlkInfo[FBLUPDATE_NUMBLOCKS];

#define FBLUPDATE_START_SEC_CONST_EXPORT
#include "MemMap.h"

#define FBLUPDATE_BLOCK0_ADDRESS	0xA0090000
#define FBLUPDATE_BLOCK0_LENGTH	0x2E0
#define FBLUPDATE_BLOCK0_CHECKSUM	0xCD2Bu

V_MEMROM0 extern V_MEMROM1 vuint8 V_MEMROM2 FblUpdateBlk0[FBLUPDATE_BLOCK0_LENGTH];

#define FBLUPDATE_BLOCK1_ADDRESS	0xA0090300
#define FBLUPDATE_BLOCK1_LENGTH	0x20B00
#define FBLUPDATE_BLOCK1_CHECKSUM	0xD862u

V_MEMROM0 extern V_MEMROM1 vuint8 V_MEMROM2 FblUpdateBlk1[FBLUPDATE_BLOCK1_LENGTH];

#define FBLUPDATE_BLOCK2_ADDRESS	0xA00FFDC0
#define FBLUPDATE_BLOCK2_LENGTH	0x9A
#define FBLUPDATE_BLOCK2_CHECKSUM	0x3BE7u

V_MEMROM0 extern V_MEMROM1 vuint8 V_MEMROM2 FblUpdateBlk2[FBLUPDATE_BLOCK2_LENGTH];

#define FBLUPDATE_STOP_SEC_CONST_EXPORT
#include "MemMap.h"


#endif    /* #ifdef __FBLUPDATE__ */

