/*********************************************************************
*                SEGGER Microcontroller GmbH & Co. KG                *
*                        The Embedded Experts                        *
**********************************************************************
*                                                                    *
*       (c) 2015 - 2016  SEGGER Microcontroller GmbH & Co. KG        *
*                                                                    *
*       www.segger.com     Support: support(at)segger.com            *
*                                                                    *
**********************************************************************
*                                                                    *
*       emCompress-LZMA * Compression library                        *
*                                                                    *
*                                                                    *
*       Please note:                                                 *
*                                                                    *
*       Knowledge of this file may under no circumstances            *
*       be used to write a similar product for in-house use.         *
*                                                                    *
*       Thank you for your fairness !                                *
*                                                                    *
**********************************************************************
*                                                                    *
*       emCompress-LZMA version: V2.20b                               *
*                                                                    *
**********************************************************************
----------------------------------------------------------------------
Licensing information

Licensor:                 SEGGER Software GmbH
Licensed to:              Vector Informatik GmbH, Ingersheimer Str. 24, 70499 Stuttgart
Licensed SEGGER software: emCompress
License number:           CPR-00121
License model:            emCompress Buyout Agreement, signed on 18th July 2016
-------------------------- END-OF-HEADER -----------------------------

File        : COMPRESS_LZMA_DECODE_ConfDefaults.h
Purpose     : Defines defaults for most configurable defines used in
              the component.  If you want to change a value, please do
              so in COMPRESS_LZMA_DECODE_Conf.h, DO NOT modify this
              file.

*/

#ifndef COMPRESS_LZMA_DECODE_CONFDEFAULTS_H
#define COMPRESS_LZMA_DECODE_CONFDEFAULTS_H

#ifdef __cplusplus
extern "C" {
#endif

#include "cmpr_lzma_cfg.h"
#include "COMPRESS_LZMA_Int.h"

/*lint -estring(9026, COMPRESS_LZMA_DECODE_WATCHDOG_TICK)  Macro was requested by the requirement specification. */
#ifndef   COMPRESS_LZMA_DECODE_WATCHDOG_TICK
  #define COMPRESS_LZMA_DECODE_WATCHDOG_TICK(I)
#endif

#ifndef   COMPRESS_LZMA_CONFIG_DECODE_WINDOW_SIZE_MAX
  #define COMPRESS_LZMA_CONFIG_DECODE_WINDOW_SIZE_MAX  (1024*1024)
#endif

#ifndef   COMPRESS_LZMA_CONFIG_DECODE_LC_MAX
  #define COMPRESS_LZMA_CONFIG_DECODE_LC_MAX     8    // Maximum number of literal context bits the decoder will accept [0, 8].
#endif

#ifndef   COMPRESS_LZMA_CONFIG_DECODE_LP_MAX
  #define COMPRESS_LZMA_CONFIG_DECODE_LP_MAX     4    // Maximum number of literal position bits the decoder will accept [0, 4].
#endif

#ifndef   COMPRESS_LZMA_CONFIG_DECODE_PB_MAX
  #define COMPRESS_LZMA_CONFIG_DECODE_PB_MAX     4    // Maximum number of position bits the decoder will accept [0, 4].
#endif

#if (COMPRESS_LZMA_CONFIG_DECODE_LC_MAX < 0) || (8 < COMPRESS_LZMA_CONFIG_DECODE_PB_MAX)
  #error Bad configuration for LC
#endif

#if (COMPRESS_LZMA_CONFIG_DECODE_LP_MAX < 0) || (4 < COMPRESS_LZMA_CONFIG_DECODE_LP_MAX)
  #error Bad configuration for LP
#endif

#if (COMPRESS_LZMA_CONFIG_DECODE_PB_MAX < 0) || (4 < COMPRESS_LZMA_CONFIG_DECODE_PB_MAX)
  #error Bad configuration for PB
#endif

#ifdef __cplusplus
}
#endif

#endif

/*************************** End of file ****************************/
