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

File        : COMPRESS_LZMA.h
Purpose     : emCompress-LZMA definitions common to encoder and decoder.

*/

#ifndef COMPRESS_LZMA_H
#define COMPRESS_LZMA_H

/*********************************************************************
*
*       #include Section
*
**********************************************************************
*/

#ifdef __cplusplus
extern "C" {
#endif

/*********************************************************************
*
*       Defines, fixed
*
**********************************************************************
*/

#define COMPRESS_LZMA_VERSION                    22002

/*********************************************************************
*
*       emCompress-LZMA errors.
*/
#define COMPRESS_LZMA_STATUS_USAGE_ERROR         -101   // API usage violation
#define COMPRESS_LZMA_STATUS_BITSTREAM_ERROR     -102   // Bitstream is invalid
#define COMPRESS_LZMA_STATUS_PARAMETER_ERROR     -103   // One or more parameters in error

/*********************************************************************
*
*       Streaming interface.
*/
typedef struct {
  U32        AvailIn;  // Number of elements available as input octets
  const U8 * pIn;      // Pointer to available input octets
  U32        AvailOut; // Number of elements available for output octets
  U8       * pOut;     // Pointer to output octets
} COMPRESS_LZMA_STREAM;

#ifdef __cplusplus
}
#endif

#endif

/*************************** End of file ****************************/
