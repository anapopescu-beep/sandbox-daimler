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

File        : COMPRESS_LZMA_Int.h
Purpose     : Internal aspects of emCompress-LZMA common to both
              encoder and decoder.

*/

#ifndef COMPRESS_LZMA_INT_H
#define COMPRESS_LZMA_INT_H

/*********************************************************************
*
*       #include section
*
**********************************************************************
*/

#include "COMPRESS_LZMA.h"
#include "COMPRESS_LZMA_DECODE_Conf.h"

#ifdef __cplusplus
extern "C" {
#endif

/*********************************************************************
*
*       Defines, fixed.
*
**********************************************************************
*/

/*********************************************************************
*
*       LZSS matcher.
*/
#define COMPRESS_LZMA_LZSS_EOF                  0x100

/*********************************************************************
*
*       LZMA parameters, fixed.
*/
#define COMPRESS_LZMA_RANGE_ENCODER_TOTAL_BITS     11   // 11 bits represent probability
#define COMPRESS_LZMA_RANGE_ENCODER_SHIFT_BITS      5   // 16 bits for total probability, 5 left over
#define COMPRESS_LZMA_PROB_0v5            ((U16)0x400)  // Probability 0.5 = 0.5*(2^11) = 2^10 = 0x400
#define COMPRESS_LZMA_STATE_MAX                    12u  // Number of LZMA state machine states when encoding or decoding
#define COMPRESS_LZMA_DIST_CONTEXT_BITS             4u  // Number of position-dependent context bits in distance encoding
#define COMPRESS_LZMA_DIST_CONTEXT_SIZE          0x10u  //                                delivered by 16-entry probability model
#define COMPRESS_LZMA_POS_CODER_SIZE              115   // Number of position coder probabilities: (2^(14/2))/2 - 14 + 1 = 128-14+1 = 115
#define COMPRESS_LZMA_PROB_LOW_BITS                 3   // Lengths 2-9 (encoded 0-7)      delivered by 8 symbols
#define COMPRESS_LZMA_PROB_LOW_SIZE                 8u  //                                3 bits == 8-entry probability model
#define COMPRESS_LZMA_PROB_MID_BITS                 3   // Length  10-17 (encoded 8-15)   delivered by 8 symbols
#define COMPRESS_LZMA_PROB_MID_SIZE                 8u  //                                3 bits == 8-entry probability model
#define COMPRESS_LZMA_PROB_HIGH_BITS                8   // Lengths 18-273 (encoded 0-255) delivered by 256 symbols
#define COMPRESS_LZMA_PROB_HIGH_SIZE              256u  //                                8 bits = 256-entry probability model
#define COMPRESS_LZMA_POS_SLOT_BITS                 6   // 6 bits encode 64 "position slot" bits for match distance
#define COMPRESS_LZMA_POS_SLOT_SIZE                64   //                                6 bits = 64-entry table
#define COMPRESS_LZMA_POS_SLOT_CODER_SIZE           4u  // Four "Position slot" coders corresponding to (normalized) lengths 0, 1, 2, and 3+
#define COMPRESS_LZMA_MIN_MATCH_LEN                 2u  // Minimum match distance for LZMA is 2, but we use 3 as it typically provides better compression using our matcher implementation

/*********************************************************************
*
*       LZMA configuration-derived sizes.
*/
#define COMPRESS_LZMA_ENCODE_POS_SIZE      ((ULEAST16)1 << COMPRESS_LZMA_CONFIG_ENCODE_PB_MAX)
#define COMPRESS_LZMA_DECODE_POS_SIZE      ((ULEAST16)1 << COMPRESS_LZMA_CONFIG_DECODE_PB_MAX)

/*********************************************************************
*
*       Utility macros.
*/
/*lint -estring(9026, COMPRESS_LZMA_COUNTOF)  Macro cannot be replaced by a function. */
#define COMPRESS_LZMA_COUNTOF(a)           (sizeof((a))/sizeof((a)[0]))


/*********************************************************************
*
*       Package-private data types
*
**********************************************************************
*/

/*********************************************************************
*
*       LZMA probability model.
*/
typedef U16   COMPRESS_LZMA_PROB;

/*********************************************************************
*
*       Bit-level I/O interface.
*/
typedef struct {
  ULEAST16               BitNum;
  ULEAST16               Data;
  COMPRESS_LZMA_STREAM * pStream;
  COMPRESS_LZMA_STREAM * pOverflow;
} COMPRESS_LZMA_BITIO_CONTEXT;

#ifdef __cplusplus
}
#endif

#endif

/*************************** End of file ****************************/
