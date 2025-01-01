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

File        : COMPRESS_LZMA_DECODE_Int.h
Purpose     : Internal aspects of emCompress-LZMA decompressors.

*/

#ifndef COMPRESS_LZMA_DECODE_INT_H
#define COMPRESS_LZMA_DECODE_INT_H

/*********************************************************************
*
*       #include section
*
**********************************************************************
*/

#include "COMPRESS_LZMA_DECODE_ConfDefaults.h"

#ifdef __cplusplus
extern "C" {
#endif

/*********************************************************************
*
*       Defines, fixed
*
**********************************************************************
*/

#define COMPRESS_LZMA_DECODE_BITIO_SIZE   128  // This must be at least greater than 13+5 to start the range coder

/*********************************************************************
*
*       Data types
*
**********************************************************************
*/

typedef struct {
  U32      Range;       // Current range
  U32      Code;        // Current code
  ILEAST16 Error;       // Error register
  ULEAST16 Len;         // Number of bytes in bit I/O buffer
  ULEAST16 Rd;          // Bit I/O read pointer
  ULEAST16 Wr;          // Bit I/O write pointer
  U8       aBuf[COMPRESS_LZMA_DECODE_BITIO_SIZE];  // More than enough
} COMPRESS_LZMA_RANGE_DECODE_CONTEXT;

typedef struct {
  ULEAST16             NumBits;
  ULEAST16             Capacity;  // == 1 << NumBits
  COMPRESS_LZMA_PROB * pProbs;    // == array aProbs[Capacity];
} COMPRESS_LZMA_BITTREE_DECODE_CONTEXT;

typedef struct {
  COMPRESS_LZMA_PROB                   Choice1;
  COMPRESS_LZMA_PROB                   Choice2;
  COMPRESS_LZMA_PROB                   aaLowProbs[COMPRESS_LZMA_DECODE_POS_SIZE][COMPRESS_LZMA_PROB_LOW_SIZE];
  COMPRESS_LZMA_PROB                   aaMidProbs[COMPRESS_LZMA_DECODE_POS_SIZE][COMPRESS_LZMA_PROB_MID_SIZE];
  COMPRESS_LZMA_PROB                   aHighProbs                               [COMPRESS_LZMA_PROB_HIGH_SIZE];
  COMPRESS_LZMA_BITTREE_DECODE_CONTEXT aLowCoder [COMPRESS_LZMA_DECODE_POS_SIZE];
  COMPRESS_LZMA_BITTREE_DECODE_CONTEXT aMidCoder [COMPRESS_LZMA_DECODE_POS_SIZE];
  COMPRESS_LZMA_BITTREE_DECODE_CONTEXT HighCoder;
} COMPRESS_LZMA_LENGTH_DECODE_CONTEXT;

typedef enum {
  COMPRESS_LZMA_DECODE_STATE_INIT,
  COMPRESS_LZMA_DECODE_STATE_NEXT,
  COMPRESS_LZMA_DECODE_STATE_COPY,
  COMPRESS_LZMA_DECODE_STATE_DONE,
  COMPRESS_LZMA_DECODE_STATE_ERROR
} COMPRESS_LZMA_DECODE_STATE;

typedef struct {
  COMPRESS_LZMA_DECODE_STATE             MetaState;        // Meta-state for streaming interface
  ULEAST16                               State;            // LZMA bitstream decoder state according to model decoder
  ULEAST16                               RepDist0;         // Repeat distances, most recent first
  ULEAST16                               RepDist1;
  ULEAST16                               RepDist2;
  ULEAST16                               RepDist3;
  ULEAST16                               CopyLen;          // Number of octets remaining to copy in a reference
  ULEAST16                               LC;               // Number of literal context bits,  0 <= LC <= 8
  ULEAST16                               LP;               // Number of literal position bits, 0 <= LP <= 4
  ULEAST16                               PB;               // Number of position bits,         0 <= PB <= 4
  ULEAST16                               PBMask;           // Position bit mask, make value modulo 2^PB
  ULEAST16                               LPMask;           // Literal position bit mask, make value modulo 2^LP
  U64                                    DecodedSize;      // Uncompressed size as defined in header
  U64                                    BytesRemaining;   // Number of bytes remaining to be decompressed
  U32                                    WindowCursor;     // Output position within window, 0 <= WindowCursor < WindowSize
  U32                                    WindowSize;       // Window size we will be using, derived from header
  ULEAST16                               DecodeCursor;     // Number of bytes decoded
  COMPRESS_LZMA_RANGE_DECODE_CONTEXT     RangeCoder;       // Underlying range coder
  COMPRESS_LZMA_BITTREE_DECODE_CONTEXT   PoolCoder;        // Tree coder for "long distance" context-dependent distance bits
  COMPRESS_LZMA_LENGTH_DECODE_CONTEXT    LenCoder;         // Match-length coder for simple matches
  COMPRESS_LZMA_LENGTH_DECODE_CONTEXT    RepLenCoder;      // Match-length coder for repeated matches
  COMPRESS_LZMA_BITTREE_DECODE_CONTEXT   aPosSlotCoder     [COMPRESS_LZMA_POS_SLOT_CODER_SIZE];                               //4
  COMPRESS_LZMA_PROB                     aPoolCoderProbs   [COMPRESS_LZMA_DIST_CONTEXT_SIZE];                                 //16
  COMPRESS_LZMA_PROB                     aPosCoderProbs    [COMPRESS_LZMA_POS_CODER_SIZE];                                    //115
  COMPRESS_LZMA_PROB                     aPosSlotCoderProbs[COMPRESS_LZMA_POS_SLOT_CODER_SIZE][COMPRESS_LZMA_POS_SLOT_SIZE];  //4x64=256
  COMPRESS_LZMA_PROB                     aIsRepProbs       [COMPRESS_LZMA_STATE_MAX];                                         //12
  COMPRESS_LZMA_PROB                     aIsRepG0Probs     [COMPRESS_LZMA_STATE_MAX];                                         //12
  COMPRESS_LZMA_PROB                     aIsRepG1Probs     [COMPRESS_LZMA_STATE_MAX];                                         //12
  COMPRESS_LZMA_PROB                     aIsRepG2Probs     [COMPRESS_LZMA_STATE_MAX];                                         //12
  COMPRESS_LZMA_PROB                     aIsRep0LongProbs  [COMPRESS_LZMA_STATE_MAX << COMPRESS_LZMA_CONFIG_DECODE_PB_MAX];   //12xPBSize
  COMPRESS_LZMA_PROB                     aIsMatchProbs     [COMPRESS_LZMA_STATE_MAX << COMPRESS_LZMA_CONFIG_DECODE_PB_MAX];   //12xPBSize
  COMPRESS_LZMA_PROB                     aLitProbs         [(ULEAST16)0x300 << (COMPRESS_LZMA_CONFIG_DECODE_LC_MAX + COMPRESS_LZMA_CONFIG_DECODE_LP_MAX)];
  U8                                     aWindow           [COMPRESS_LZMA_CONFIG_DECODE_WINDOW_SIZE_MAX];
} COMPRESS_LZMA_DECODE_CONTEXT;

#ifdef __cplusplus
}
#endif

#endif

/*************************** End of file ****************************/
