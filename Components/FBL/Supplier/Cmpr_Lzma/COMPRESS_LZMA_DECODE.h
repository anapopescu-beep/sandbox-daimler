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

File        : COMPRESS_LZMA_DECODE.h
Purpose     : emCompress-LZMA decoder API.

*/

#ifndef COMPRESS_LZMA_DECODE_H
#define COMPRESS_LZMA_DECODE_H

/*********************************************************************
*
*       #include section
*
**********************************************************************
*/

#include "COMPRESS_LZMA_DECODE_Int.h"

#ifdef __cplusplus
extern "C" {
#endif

/*********************************************************************
*
*       emCompress-LZMA decoder API
*
**********************************************************************
*/

void     COMPRESS_LZMA_DECODE_Init (COMPRESS_LZMA_DECODE_CONTEXT *pSelf);
ILEAST16 COMPRESS_LZMA_DECODE_Run  (COMPRESS_LZMA_DECODE_CONTEXT *pSelf, COMPRESS_LZMA_STREAM *pStream, ILEAST16 Flush);

#ifdef __cplusplus
}
#endif

#endif

/*************************** End of file ****************************/
