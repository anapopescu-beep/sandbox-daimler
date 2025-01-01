/****************************************************************
*
*  Filename:      D:\starter_kit_classic_aurix\examples\_common\flash_drv\Build\..\FlashRom.h
*  Project:       Exported definition of C-Array Flash-Driver
*  File created:  Thu May 12 15:18:21 2022

*
****************************************************************/

#ifndef __FLASHDRV__
#define __FLASHDRV__
#define FLASHDRV_GEN_RAND 10866

#define FLASHDRV_NUMBLOCKS 1

#define FLASHDRV_DECRYPTVALUE	0xCC
#define FLASHDRV_DECRYPTDATA(a)   (vuint8)((vuint8)(a) ^ (vuint8)FLASHDRV_DECRYPTVALUE)
#define FLASHDRV_BLOCK0_ADDRESS	0x70100000
#define FLASHDRV_BLOCK0_LENGTH	0x7EA
#define FLASHDRV_BLOCK0_CHECKSUM	0xCA0Fu

V_MEMROM0 extern V_MEMROM1 vuint8 V_MEMROM2 flashDrvBlk0[FLASHDRV_BLOCK0_LENGTH];


#endif    /* #ifdef __FLASHDRV__ */

