/***********************************************************************************************************************
 *  FILE DESCRIPTION
 *  ------------------------------------------------------------------------------------------------------------------*/
/** \file
 *  \brief         Configuration file of LZMA (de)compression component
 *
 *  --------------------------------------------------------------------------------------------------------------------
 *  COPYRIGHT
 *  --------------------------------------------------------------------------------------------------------------------
 *  \par Copyright
 *  \verbatim
 *  Copyright (c) 2016 by Vector Informatik GmbH.                                                  All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 */
/**********************************************************************************************************************/

#ifndef __CMPR_LZMA_CFG_H__
#define __CMPR_LZMA_CFG_H__

#include "fbl_inc.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Configuration of types required by emCompress-LZMA */
typedef unsigned long long U64;
typedef unsigned long      U32;
typedef unsigned short     U16;
typedef unsigned char       U8;
typedef unsigned int  ULEAST16;   /* unsigned integer with a range of at least 0 to (2^16)-1 */
typedef int           ILEAST16;   /* signed integer with a range of at least -(2^15) to (2^15)-1 */

#define CMPR_WATCHDOG_CYCLE_COUNT 0x100u

/* Watchdog function */
#define COMPRESS_LZMA_DECODE_WATCHDOG_TICK(I) if(((I) & (CMPR_WATCHDOG_CYCLE_COUNT - 1u)) == 0u) {   \
                                                   FblLookForWatchdogVoid();                         \
                                              }

/* Maximum number of literal context (LC) bits the decoder will accept  [0, 8] */
#define COMPRESS_LZMA_CONFIG_DECODE_LC_MAX     3

/* Maximum number of literal position (LP) bits the decoder will accept [0, 4] */
#define COMPRESS_LZMA_CONFIG_DECODE_LP_MAX     0

/* Maximum number of position bits (PB) bits the decoder will accept    [0, 4] */
#define COMPRESS_LZMA_CONFIG_DECODE_PB_MAX     2

/* Maximum size of LZMA window */
#define COMPRESS_LZMA_CONFIG_DECODE_WINDOW_SIZE_MAX  (4*1024)

#ifdef __cplusplus
}
#endif

#endif /* __CMPR_LZMA_CFG_H__ */

/***********************************************************************************************************************
 *  END OF FILE: CMPR_LZMA_CFG.H
 **********************************************************************************************************************/
