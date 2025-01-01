/****************************************************************
*
*  Filename:      C:\Users\emanuel.jivan\Downloads\debug_password.h
*  Project:       Exported definition of C-Array Flash-Driver
*  File created:  Tue Mar 19 18:12:00 2024

*
****************************************************************/

#ifndef __DBG_PASS__
#define __DBG_PASS__
#define DBG_PASS_GEN_RAND 20322

#define DBG_PASS_NUMBLOCKS 1

#define DBG_PASS_DECRYPTDATA(a)   (vuint8)(a)
#define DBG_PASS_BLOCK0_ADDRESS	0xAF402400
#define DBG_PASS_BLOCK0_LENGTH	0x200
#define DBG_PASS_BLOCK0_CHECKSUM	0x1E4u

V_MEMROM0 extern V_MEMROM1 vuint8 V_MEMROM2 dbg_passBlk0[DBG_PASS_BLOCK0_LENGTH];


#endif    /* #ifdef __DBG_PASS__ */

