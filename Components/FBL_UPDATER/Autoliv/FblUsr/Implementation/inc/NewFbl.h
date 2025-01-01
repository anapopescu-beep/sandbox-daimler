/****************************************************************
*
*  Filename:      S:\Tools\Vector_configuration\Workspace\fblupdater\\..\..\..\Build_Env\Workspace\Outputs\fbl_upd\Out\NewFbl.h
*  Project:       Exported definition of C-Array Flash-Driver
*  File created:  Thu Jan 27 14:47:11 2022

*
****************************************************************/

#ifndef __FBLUPDATE__
#define __FBLUPDATE__
#define FBLUPDATE_GEN_RAND 1696

#define FBLUPDATE_NUMBLOCKS 4

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

#define FBLUPDATE_BLOCK0_ADDRESS	0xA0044000
#define FBLUPDATE_BLOCK0_LENGTH	0x2E0
#define FBLUPDATE_BLOCK0_CHECKSUM	0xE6D8u

V_MEMROM0 extern V_MEMROM1 vuint8 V_MEMROM2 FblUpdateBlk0[FBLUPDATE_BLOCK0_LENGTH];

#define FBLUPDATE_BLOCK1_ADDRESS	0xA0044300
#define FBLUPDATE_BLOCK1_LENGTH	0x22120
#define FBLUPDATE_BLOCK1_CHECKSUM	0xA894u

V_MEMROM0 extern V_MEMROM1 vuint8 V_MEMROM2 FblUpdateBlk1[FBLUPDATE_BLOCK1_LENGTH];

#define FBLUPDATE_BLOCK2_ADDRESS	0xA0067DC0
#define FBLUPDATE_BLOCK2_LENGTH	0x1A0
#define FBLUPDATE_BLOCK2_CHECKSUM	0xAD51u

V_MEMROM0 extern V_MEMROM1 vuint8 V_MEMROM2 FblUpdateBlk2[FBLUPDATE_BLOCK2_LENGTH];

#define FBLUPDATE_BLOCK3_ADDRESS	0xA0067FC0
#define FBLUPDATE_BLOCK3_LENGTH	0x20
#define FBLUPDATE_BLOCK3_CHECKSUM	0x1D28u

V_MEMROM0 extern V_MEMROM1 vuint8 V_MEMROM2 FblUpdateBlk3[FBLUPDATE_BLOCK3_LENGTH];

#define FBLUPDATE_STOP_SEC_CONST_EXPORT
#include "MemMap.h"


#endif    /* #ifdef __FBLUPDATE__ */

