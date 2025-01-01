/****************************************************************
*
*  Filename:      S:\Tools\Vector_configuration\Workspace\fblbmupdater\\..\..\..\Build_Env\Workspace\Outputs\fblbm_upd\Out\NewFbl.h
*  Project:       Exported definition of C-Array Flash-Driver
*  File created:  Fri Mar 29 02:30:03 2024

*
****************************************************************/

#ifndef __FBLUPDATE__
#define __FBLUPDATE__
#define FBLUPDATE_GEN_RAND 3014

#define FBLUPDATE_NUMBLOCKS 7

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

#define FBLUPDATE_BLOCK0_ADDRESS	0xA0034000
#define FBLUPDATE_BLOCK0_LENGTH	0x1E0
#define FBLUPDATE_BLOCK0_CHECKSUM	0xCA7Fu

V_MEMROM0 extern V_MEMROM1 vuint8 V_MEMROM2 FblUpdateBlk0[FBLUPDATE_BLOCK0_LENGTH];

#define FBLUPDATE_BLOCK1_ADDRESS	0xA0034200
#define FBLUPDATE_BLOCK1_LENGTH	0x114A0
#define FBLUPDATE_BLOCK1_CHECKSUM	0xBDC5u

V_MEMROM0 extern V_MEMROM1 vuint8 V_MEMROM2 FblUpdateBlk1[FBLUPDATE_BLOCK1_LENGTH];

#define FBLUPDATE_BLOCK2_ADDRESS	0xA0048000
#define FBLUPDATE_BLOCK2_LENGTH	0x2E0
#define FBLUPDATE_BLOCK2_CHECKSUM	0xECCBu

V_MEMROM0 extern V_MEMROM1 vuint8 V_MEMROM2 FblUpdateBlk2[FBLUPDATE_BLOCK2_LENGTH];

#define FBLUPDATE_BLOCK3_ADDRESS	0xA0048300
#define FBLUPDATE_BLOCK3_LENGTH	0x21340
#define FBLUPDATE_BLOCK3_CHECKSUM	0x27F2u

V_MEMROM0 extern V_MEMROM1 vuint8 V_MEMROM2 FblUpdateBlk3[FBLUPDATE_BLOCK3_LENGTH];

#define FBLUPDATE_BLOCK4_ADDRESS	0xA006BC60
#define FBLUPDATE_BLOCK4_LENGTH	0x20
#define FBLUPDATE_BLOCK4_CHECKSUM	0x1C0Bu

V_MEMROM0 extern V_MEMROM1 vuint8 V_MEMROM2 FblUpdateBlk4[FBLUPDATE_BLOCK4_LENGTH];

#define FBLUPDATE_BLOCK5_ADDRESS	0xA006BDC0
#define FBLUPDATE_BLOCK5_LENGTH	0x180
#define FBLUPDATE_BLOCK5_CHECKSUM	0xAA74u

V_MEMROM0 extern V_MEMROM1 vuint8 V_MEMROM2 FblUpdateBlk5[FBLUPDATE_BLOCK5_LENGTH];

#define FBLUPDATE_BLOCK6_ADDRESS	0xA006BFC0
#define FBLUPDATE_BLOCK6_LENGTH	0x20
#define FBLUPDATE_BLOCK6_CHECKSUM	0x1D28u

V_MEMROM0 extern V_MEMROM1 vuint8 V_MEMROM2 FblUpdateBlk6[FBLUPDATE_BLOCK6_LENGTH];

#define FBLUPDATE_STOP_SEC_CONST_EXPORT
#include "MemMap.h"


#endif    /* #ifdef __FBLUPDATE__ */

