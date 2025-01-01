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

File        : COMPRESS_LZMA_Decode.c
Purpose     : Implementation of raw LZMA decoder.

*/

/*********************************************************************
*
*       #include Section
*
**********************************************************************
*/

#include "COMPRESS_LZMA_DECODE_Int.h"
#include "COMPRESS_LZMA_DECODE.h"

/*********************************************************************
*
*       Static const data
*
**********************************************************************
*/

/*********************************************************************
*
*       Static code
*
**********************************************************************
*/

//lint -esym(550,idx) Reference to variable 'idx' depends on the COMPRESS_LZMA_DECODE_WATCHDOG_TICK macro.

/*********************************************************************
*
*       _COMPRESS_LZMA_RdU32LE()
*
*  Function description
*    Load 32-bit LE unsigned value.
*
*  Parameters
*    pData - Pointer to least significant byte in octet string.
*
*  Return value
*    Value read from octet string.
*/
static U32 _COMPRESS_LZMA_RdU32LE(const U8 * pData) {
  return  (U32)pData[0] +
         ((U32)pData[1] <<  8) +
         ((U32)pData[2] << 16) +
         ((U32)pData[3] << 24);
}

/*********************************************************************
*
*       _COMPRESS_LZMA_RdU64LE()
*
*  Function description
*    Load 64-bit LE unsigned value.
*
*  Parameters
*    pData - Pointer to least significant byte in octet string.
*
*  Return value
*    Value read from octet string.
*/
static U64 _COMPRESS_LZMA_RdU64LE(const U8 * pData) {
  return ((U64)_COMPRESS_LZMA_RdU32LE(&pData[4]) << 32) | _COMPRESS_LZMA_RdU32LE(&pData[0]);
}

/*********************************************************************
*
*       _COMPRESS_LZMA_DECODE_GetU8()
*
*  Function description
*    Get byte from window.
*
*  Parameters
*    pSelf    - Pointer to decoder context.
*    Distance - Distance (backward) from cursor to target.
*
*  Return value
*    Value read from history.
*/
static U8 _COMPRESS_LZMA_DECODE_GetU8(const COMPRESS_LZMA_DECODE_CONTEXT *pSelf, U32 Distance) {
  return pSelf->aWindow[(Distance <= pSelf->WindowCursor) ? (pSelf->WindowCursor - Distance) : (pSelf->WindowCursor + pSelf->WindowSize - Distance)];
}

/*********************************************************************
*
*       _COMPRESS_LZMA_DECODE_PutU8()
*
*  Function description
*    Put byte to window.
*
*  Parameters
*    pSelf   - Pointer to decoder context.
*    pStream - Pointer to stream context.
*    Byte    - Byte to place into window.
*
*  Additional information
*    The window cursor is advanced on function exit.
*/
static void _COMPRESS_LZMA_DECODE_PutU8(COMPRESS_LZMA_DECODE_CONTEXT *pSelf, COMPRESS_LZMA_STREAM *pStream, U8 Byte) {
  U32 W;
  //
  --pSelf->BytesRemaining;
  ++pSelf->DecodeCursor;
  W = pSelf->WindowCursor;
  pSelf->aWindow[W] = Byte;
  ++W;
  if (W >= pSelf->WindowSize) {
    W = 0;
  }
  pSelf->WindowCursor = W;
  //
  *pStream->pOut = Byte;
  ++pStream->pOut;
  --pStream->AvailOut;
}

/*********************************************************************
*
*       _COMPRESS_LZMA_DECODE_InitProbs()
*
*  Function description
*    Initialize probability array.
*
*  Parameters
*    pProb - Pointer to probability array.
*    Len   - Length of array.
*
*  Additional information
*    All elements are initialize to probability 0.5.
*/
static void _COMPRESS_LZMA_DECODE_InitProbs(COMPRESS_LZMA_PROB *pProb, ULEAST16 Len) {
  ULEAST16 i;
  //
  for (i = 0; i < Len; ++i) {
    COMPRESS_LZMA_DECODE_WATCHDOG_TICK(i);
    pProb[i] = COMPRESS_LZMA_PROB_0v5;
  }
}

/*********************************************************************
*
*       _COMPRESS_LZMA_DECODE_RdHeader()
*
*  Function description
*    Decode the LZMA header.
*
*  Parameters
*    pSelf - Pointer to LZMA decoding context.
*
*  Syntax
*    pHeader[0]      LZMA model properties (lc, lp, pb) in encoded form
*    pHeader[1..4]   Dictionary size,   32-bit LE unsigned
*    pHeader[5..12]  Uncompressed size, 64-bit LE unsigned
*/
static void _COMPRESS_LZMA_DECODE_RdHeader(COMPRESS_LZMA_DECODE_CONTEXT *pSelf) {
  ULEAST16 ControlByte;
  //
  pSelf->WindowSize     = _COMPRESS_LZMA_RdU32LE(&pSelf->RangeCoder.aBuf[1]);  // LZMA format deviation: do not impose a minimum dictionary size of COMPRESS_LZMA_MIN_DICT_SIZE.
  pSelf->DecodedSize    = _COMPRESS_LZMA_RdU64LE(&pSelf->RangeCoder.aBuf[5]);
  pSelf->BytesRemaining = pSelf->DecodedSize;
  //
  ControlByte = pSelf->RangeCoder.aBuf[0];
  pSelf->LC = ControlByte % 9u;        // LC in [0, 8].
  ControlByte /= 9u;
  pSelf->LP = ControlByte % 5u;        // LP in [0, 4].
  ControlByte /= 5u;
  pSelf->PB = ControlByte;             // PB in [0, 4] and the only one that may be out of range after computation
  if (pSelf->PB <= 4u) {
    pSelf->PBMask = ((ULEAST16)1 << pSelf->PB) - 1u;
    pSelf->LPMask = ((ULEAST16)1 << pSelf->LP) - 1u;
  } else {
    pSelf->RangeCoder.Error = COMPRESS_LZMA_STATUS_PARAMETER_ERROR;
  }
}

/*********************************************************************
*
*       _COMPRESS_LZMA_RANGE_DECODE_Init()
*
*  Function description
*    Initialize range decoder.
*
*  Parameters
*    pSelf - Pointer to range coder.
*/
static void _COMPRESS_LZMA_RANGE_DECODE_Init(COMPRESS_LZMA_RANGE_DECODE_CONTEXT *pSelf) {
  pSelf->Range = 0xFFFFFFFFuL;
  pSelf->Code  = 0x00000000uL;
  pSelf->Len   = 0;
  pSelf->Rd    = 0;
  pSelf->Wr    = 0;
  pSelf->Error = 0;
}

/*********************************************************************
*
*       _COMPRESS_LZMA_RANGE_DECODE_Normalize()
*
*  Function description
*    Normalize range decoder.
*
*  Parameters
*    pSelf - Pointer to range coder.
*
*  Additional information
*    In normal operation the range coder will never run out of
*    data, but if it does because of a bitstream error, we
*    register the error to recover gracefully and pump excess
*    zero bits through and continue back to toplevel decoding.
*/
static void _COMPRESS_LZMA_RANGE_DECODE_Normalize(COMPRESS_LZMA_RANGE_DECODE_CONTEXT *pSelf) {
  ULEAST16 B;
  //
  if (pSelf->Range < (U32)0x01000000uL) {
    if (pSelf->Len == 0u) {
      pSelf->Error = COMPRESS_LZMA_STATUS_BITSTREAM_ERROR;  // Unexpected exhaustion of input stream
      B = 0;
    } else {
      B = pSelf->aBuf[pSelf->Rd];
      ++pSelf->Rd;
      if (pSelf->Rd >= sizeof(pSelf->aBuf)) {
        pSelf->Rd = 0;
      }
      --pSelf->Len;
    }
    pSelf->Range <<= 8;
    pSelf->Code  <<= 8;
    pSelf->Code   |= B;
  }
}

/*********************************************************************
*
*       _COMPRESS_LZMA_RANGE_DECODE_Start()
*
*  Function description
*    Start range decoder.
*
*  Parameters
*    pSelf - Pointer to range coder.
*    pData - Pointer to start of bitstream, at least 5 octets.
*
*  Additional information
*    The range decoder is initialized from the incoming bitstream
*    and the leading bytes used to prime the current code.  If there's
*    an error in the leading bytes, it's flagged into the range
*    decoder's error register.
*/
static void _COMPRESS_LZMA_RANGE_DECODE_Start(COMPRESS_LZMA_RANGE_DECODE_CONTEXT *pSelf, const U8 *pData) {
  ULEAST16 i;
  ULEAST16 B;
  //
  B = *pData;
  ++pData;
  for (i = 0; i < 4u; ++i) {
    pSelf->Code = (pSelf->Code << 8) | *pData;
    ++pData;
  }
  if ((B != 0u) || (pSelf->Code == pSelf->Range)) {
    pSelf->Error = COMPRESS_LZMA_STATUS_BITSTREAM_ERROR;
  }
}

/*********************************************************************
*
*       _COMPRESS_LZMA_RANGE_DECODE_RdFixedProbBits()
*
*  Function description
*    Read symbol encoded with fixed-probability bits.
*
*  Parameters
*    pSelf - Pointer to LZMA decoding context.
*    Len   - Number of bits in symbol, 0 <= Len < 32.
*
*  Return value
*    Decoded symbol.
*/
static U32 _COMPRESS_LZMA_RANGE_DECODE_RdFixedProbBits(COMPRESS_LZMA_RANGE_DECODE_CONTEXT *pSelf, ULEAST16 Len) {
  U32 Bits;
  U32 t;
  //
  Bits = 0;
  while (Len > 0u) {
    COMPRESS_LZMA_DECODE_WATCHDOG_TICK(0);
    //
    pSelf->Range >>= 1;
    pSelf->Code -= pSelf->Range;
    t     = (U32)0 - (pSelf->Code >> 31);
    pSelf->Code += pSelf->Range & t;
    //
    _COMPRESS_LZMA_RANGE_DECODE_Normalize(pSelf);
    Bits = (Bits << 1) + t + 1u;
    --Len;
  }
  return Bits;
}

/*********************************************************************
*
*       _COMPRESS_LZMA_RANGE_DECODE_RdBit()
*
*  Function description
*    Read a single bit guided by bit probability.
*
*  Parameters
*    pSelf - Pointer to LZMA decoding context.
*    pProb - Pointer to probability variable modeling bit.
*
*  Return value
*    Bit value, 0 or 1.
*/
static ULEAST16 _COMPRESS_LZMA_RANGE_DECODE_RdBit(COMPRESS_LZMA_RANGE_DECODE_CONTEXT *pSelf, COMPRESS_LZMA_PROB *pProb) {
  U32      Bound;
  ULEAST16 Bit;
  ULEAST16 Prob;
  //
  Prob = *pProb;
  Bound = (pSelf->Range >> COMPRESS_LZMA_RANGE_ENCODER_TOTAL_BITS) * Prob;
  if (pSelf->Code < Bound) {
    Prob         += (((ULEAST16)1 << COMPRESS_LZMA_RANGE_ENCODER_TOTAL_BITS) - Prob) >> COMPRESS_LZMA_RANGE_ENCODER_SHIFT_BITS;  // cast to avoid "essential type" warning
    pSelf->Range  = Bound;
    Bit           = 0;
  } else {
    Prob         -= Prob >> COMPRESS_LZMA_RANGE_ENCODER_SHIFT_BITS;
    pSelf->Code  -= Bound;
    pSelf->Range -= Bound;
    Bit           = 1;
  }
  *pProb = (COMPRESS_LZMA_PROB)Prob;
  //
  _COMPRESS_LZMA_RANGE_DECODE_Normalize(pSelf);
  //
  return Bit;
}

/*********************************************************************
*
*       _COMPRESS_LZMA_BITTREE_DECODE_Init()
*
*  Function description
*    Initialize bittree decoder.
*
*  Parameters
*    pSelf   - Pointer to LZMA decoding context.
*    pProb   - Pointer to probability array of 2^NumBits elements.
*    NumBits - Number of bits that the bittree decodes.
*/
static void _COMPRESS_LZMA_BITTREE_DECODE_Init(COMPRESS_LZMA_BITTREE_DECODE_CONTEXT *pSelf, COMPRESS_LZMA_PROB *pProb, ULEAST16 NumBits) {
  ULEAST16 i;
  //
  pSelf->NumBits  = NumBits;
  pSelf->Capacity = (ULEAST16)1 << NumBits;
  pSelf->pProbs   = pProb;
  for (i = 0; i < pSelf->Capacity; ++i) {
    COMPRESS_LZMA_DECODE_WATCHDOG_TICK(i);
    pSelf->pProbs[i] = COMPRESS_LZMA_PROB_0v5;
  }
}

/*********************************************************************
*
*       _COMPRESS_LZMA_BITTREE_DECODE_RdMSBFirst()
*
*  Function description
*    Read symbol from tree, first decoded bit is MSB.
*
*  Parameters
*    pSelf       - Pointer to tree probabilities.
*    pRangeCoder - Pointer to range coder delivering bits.
*
*  Return value
*    Decoded symbol.
*/
static ULEAST16 _COMPRESS_LZMA_BITTREE_DECODE_RdMSBFirst(const COMPRESS_LZMA_BITTREE_DECODE_CONTEXT * pSelf,
                                                               COMPRESS_LZMA_RANGE_DECODE_CONTEXT   * pRangeCoder) {
  ULEAST16 Symbol;
  ULEAST16 i;
  //
  Symbol = 1;
  for (i = 0; i < pSelf->NumBits; ++i) {
    COMPRESS_LZMA_DECODE_WATCHDOG_TICK(i);
    Symbol = (Symbol << 1) + _COMPRESS_LZMA_RANGE_DECODE_RdBit(pRangeCoder, &pSelf->pProbs[Symbol]);
  }
  return Symbol & (pSelf->Capacity-1u);  // remove excess high-order '1' bit
}

/*********************************************************************
*
*       _COMPRESS_LZMA_BITTREE_DECODE_RdLSBFirst()
*
*  Function description
*    Read symbol from tree, first decoded bit is LSB.
*
*  Parameters
*    pProbs      - Pointer to tree probabilities.
*    Len         - Number of bits in symbol.
*    pRangeCoder - Pointer to range coder delivering bits.
*
*  Return value
*    Decoded symbol.
*/
static ULEAST16 _COMPRESS_LZMA_BITTREE_DECODE_RdLSBFirst(COMPRESS_LZMA_PROB                 * pProbs,
                                                         ULEAST16                             Len,
                                                         COMPRESS_LZMA_RANGE_DECODE_CONTEXT * pRangeCoder) {
  ULEAST16 Bit;
  ULEAST16 M;          // Current path to bit within tree
  ULEAST16 i;
  ULEAST16 Symbol;
  //
  Symbol = 0;
  M      = 1;
  for (i = 0; i < Len; ++i) {
    COMPRESS_LZMA_DECODE_WATCHDOG_TICK(i);
    Bit     = _COMPRESS_LZMA_RANGE_DECODE_RdBit(pRangeCoder, &pProbs[M]);
    M     <<= 1;
    M      += Bit;
    Symbol |= (Bit << i);
  }
  return Symbol;
}

/*********************************************************************
*
*       _COMPRESS_LZMA_LENGTH_DECODE_Init()
*
*  Function description
*    Initialize length decoder.
*
*  Parameters
*    pSelf - Pointer to length decoder.
*/
static void _COMPRESS_LZMA_LENGTH_DECODE_Init(COMPRESS_LZMA_LENGTH_DECODE_CONTEXT *pSelf) {
  ULEAST16 i;
  //
  pSelf->Choice1 = COMPRESS_LZMA_PROB_0v5;
  pSelf->Choice2 = COMPRESS_LZMA_PROB_0v5;
  _COMPRESS_LZMA_BITTREE_DECODE_Init(&pSelf->HighCoder, pSelf->aHighProbs, COMPRESS_LZMA_PROB_HIGH_BITS);
  for (i = 0u; i < COMPRESS_LZMA_DECODE_POS_SIZE; ++i) {
    COMPRESS_LZMA_DECODE_WATCHDOG_TICK(0);
    _COMPRESS_LZMA_BITTREE_DECODE_Init(&pSelf->aMidCoder[i], &pSelf->aaMidProbs[i][0], COMPRESS_LZMA_PROB_MID_BITS);
    _COMPRESS_LZMA_BITTREE_DECODE_Init(&pSelf->aLowCoder[i], &pSelf->aaLowProbs[i][0], COMPRESS_LZMA_PROB_LOW_BITS);
  }
}

/*********************************************************************
*
*       _COMPRESS_LZMA_LENGTH_DECODE_Rd()
*
*  Function description
*    Read normalized length from bitstream.
*
*  Parameters
*    pSelf       - Pointer to range length coder.
*    pRangeCoder - Pointer to range coder that delivers bits.
*    PosState    - Position state.
*
*  Return value
*    Normalized length, 0 through 271.
*
*  Implementation notes
*     0<tree>    Length is 0-7 decoded from 3-bit bittree
*     10<tree>   Length is 8-15 decoded from 3-bit bittree
*     11<tree>   Length is 16-271 decoded from 8-bit bittree
*
*     All bit tree probability models are separate and position
*     dependent.
*/
static ULEAST16 _COMPRESS_LZMA_LENGTH_DECODE_Rd(COMPRESS_LZMA_LENGTH_DECODE_CONTEXT *pSelf, COMPRESS_LZMA_RANGE_DECODE_CONTEXT *pRangeCoder, ULEAST16 PosState) {
  ULEAST16 Len;
  //
  if (_COMPRESS_LZMA_RANGE_DECODE_RdBit(pRangeCoder, &pSelf->Choice1) == 0u) {
    Len = _COMPRESS_LZMA_BITTREE_DECODE_RdMSBFirst(&pSelf->aLowCoder[PosState], pRangeCoder);
  } else if (_COMPRESS_LZMA_RANGE_DECODE_RdBit(pRangeCoder, &pSelf->Choice2) == 0u) {
    Len = COMPRESS_LZMA_PROB_LOW_SIZE + _COMPRESS_LZMA_BITTREE_DECODE_RdMSBFirst(&pSelf->aMidCoder[PosState], pRangeCoder);
  } else {
    Len = COMPRESS_LZMA_PROB_LOW_SIZE + COMPRESS_LZMA_PROB_MID_SIZE + _COMPRESS_LZMA_BITTREE_DECODE_RdMSBFirst(&pSelf->HighCoder, pRangeCoder);
  }
  //
  return Len;
}

/*********************************************************************
*
*       _COMPRESS_LZMA_DECODE_RdLiteral()
*
*  Function description
*    Read 8-bit literal from bitstream.
*
*  Parameters
*    pSelf    - Pointer to range length coder.
*    State    - LZMA decoder state (0-11).
*    RepDist0 - Topmost repeat distance.
*
*  Return value
*    Decoded literal value, 0 through 255.
*
*  Additional information
*    The value returned lites strictly within the range [0, 255],
*    hence the client requires no additional validation checks.
*/
static U8 _COMPRESS_LZMA_DECODE_RdLiteral(COMPRESS_LZMA_DECODE_CONTEXT *pSelf, ULEAST16 State, U32 RepDist0) {
  COMPRESS_LZMA_PROB * pProbs;
  ULEAST16             PrevByte;
  ULEAST16             Symbol;
  ULEAST16             LitState;
  ULEAST16             MatchByte;
  ULEAST16             MatchBit;
  ULEAST16             Bit;
  ULEAST16             idx = 0u;   
  //
  // Assume that dictionary is zeroed before decoding starts
  // so the following picks up a historical 'zero' byte.
  //
  PrevByte = _COMPRESS_LZMA_DECODE_GetU8(pSelf, 1);
  //
  LitState = ((pSelf->DecodeCursor & pSelf->LPMask) << pSelf->LC) | (PrevByte >> (8u - pSelf->LC));
  pProbs = &pSelf->aLitProbs[0x300uL * LitState];
  //
  // We require eight bits, so use a sentinel bit in Symbol
  // that, when shifted out of the 8 low order bits, lets
  // us drop out of the loop.
  //
  Symbol = 0x01;
  if (State >= 7u) {
    MatchByte = _COMPRESS_LZMA_DECODE_GetU8(pSelf, RepDist0 + 1u);  // Get value of last-encoded literal
    do {
      MatchBit    = (MatchByte >> 7) & 1u;
      MatchByte <<= 1;
      COMPRESS_LZMA_DECODE_WATCHDOG_TICK(idx);
      idx++;
      Bit         = _COMPRESS_LZMA_RANGE_DECODE_RdBit(&pSelf->RangeCoder, &pProbs[((1u + MatchBit) << 8) + Symbol]);
      Symbol    <<= 1;
      Symbol     |= Bit;
    } while ((Symbol < 0x100u) && (MatchBit == Bit));
  }
  idx = 0u;
  while (Symbol < 0x100u) {
    COMPRESS_LZMA_DECODE_WATCHDOG_TICK(idx);
    idx++;
    Symbol = (Symbol << 1) | _COMPRESS_LZMA_RANGE_DECODE_RdBit(&pSelf->RangeCoder, &pProbs[Symbol]);
  }
  return (U8)(Symbol & 0xFFu);
} 

/*********************************************************************
*
*       _COMPRESS_LZMA_DECODE_RdDistance()
*
*  Function description
*    Read distance value from bitstream.
*
*  Parameters
*    pSelf   - Pointer to decoder context.
*    PairLen - Length tied to (length, distance) pairing.
*
*  Return value
*    Distance.
*
*  Additional information
*    There is no guarantee that the distance value lies within the
*    window as bitstream errors are undetectable. The client is
*    responsible for validity checks on the distance.
*/
static U32 _COMPRESS_LZMA_DECODE_RdDistance(COMPRESS_LZMA_DECODE_CONTEXT *pSelf, ULEAST16 PairLen) {
  ULEAST16 PosSlot;
  ULEAST16 TrailingLen;
  U32      Distance;
  ULEAST16 Len;
  //
  if (PairLen < (COMPRESS_LZMA_POS_SLOT_CODER_SIZE-1u)) {
    Len = PairLen;
  } else {
    Len = COMPRESS_LZMA_POS_SLOT_CODER_SIZE-1u;
  }
  //
  PosSlot = _COMPRESS_LZMA_BITTREE_DECODE_RdMSBFirst(&pSelf->aPosSlotCoder[Len], &pSelf->RangeCoder);
  //
  if (PosSlot < 4u) {
    //
    // All these stand for themselves.
    //
    // 0 -> 0
    // 1 -> 1
    // 2 -> 10
    // 3 -> 11
    //
    Distance = PosSlot;
  } else {
    //
    TrailingLen = (PosSlot/2u) - 1u;                     // Total number of trailing bits after leading 10 or 11
    Distance    = (2u | (PosSlot & 1u)) << TrailingLen;  // 10<TrailingLen*0> ... or 11<TrailingLen*0>
    //
    if (PosSlot <= 13u) {
      //
      // x -> single contex-encoded bit taken from position decoder.
      //
      //  4 -> 10 x
      //  5 -> 11 x
      //  6 -> 10 xx
      //  7 -> 11 xx
      //  8 -> 10 xxx
      //  9 -> 11 xxx
      // 10 -> 10 xxxx
      // 11 -> 11 xxxx
      // 12 -> 10 xxxxx
      // 13 -> 11 xxxxx
      //
      Distance += _COMPRESS_LZMA_BITTREE_DECODE_RdLSBFirst(&pSelf->aPosCoderProbs[Distance-PosSlot], TrailingLen, &pSelf->RangeCoder);
    } else {
      //
      // y = fixed 0.5 probability bit, field width is dependent on position slot.
      // z = context-encoded bit, field always 4 bits wide.
      //
      // 14 -> 10 yy zzzz
      // 15 -> 11 yy zzzz
      // 16 -> 10 yyy zzzz
      // 17 -> 11 yyy zzzz
      // ...
      // 62 -> 10 yyyyyyyyyyyyyyyyyyyyyyyyyy zzzz
      // 63 -> 11 yyyyyyyyyyyyyyyyyyyyyyyyyy zzzz
      //
      Distance += _COMPRESS_LZMA_RANGE_DECODE_RdFixedProbBits(&pSelf->RangeCoder, TrailingLen - COMPRESS_LZMA_DIST_CONTEXT_BITS) << COMPRESS_LZMA_DIST_CONTEXT_BITS;
      Distance += _COMPRESS_LZMA_BITTREE_DECODE_RdLSBFirst(pSelf->PoolCoder.pProbs, pSelf->PoolCoder.NumBits, &pSelf->RangeCoder);
    }
  }
  //
  return Distance;
}

/*********************************************************************
*
*       _COMPRESS_LZMA_DECODE_Next()
*
*  Function description
*    Run decoder to decode next literal or reference.
*
*  Parameters
*    pSelf   - Pointer to decoder context.
*    pStream - Pointer to stream context.
*
*  Additional information
*    This function is called only if there is at least one byte still
*    to decode, i.e. pSelf->BytesRemaining > 0.
*
*  Implementation notes
*    Each bit in the binary tree that decodes the literal is
*    controlled by a different probability model that corresponds
*    to both that bit and the (cyclic) position of the output
*    cursor.
*
*    This table defines the structure of the bitstream we are
*    decoding and the probability models associated with each bit:
*
*    0<lit>         Emit literal <lit>
*    10<len><dist>  New match      (<dist>, <len>), push <dist> to stack
*    1100           Repeated match (RepDist0, 1)
*    1101 <len>     Repeated match (RepDist0, <len>)
*    1110 <len>     Repeated match (RepDist1, <len>), rotate RepDist1 to top
*    11110<len>     Repeated match (RepDist2, <len>), rotate RepDist2 to top
*    11111<len>     Repeated match (RepDist3, <len>), rotate RepDist3 to top
*
*    The probability models are taken according to the LZMA specification:
*
*    pSelf->aIsMatch[]
*      0 - Emit literal <lit>
*      1 - Match
*        pSelf->aIsRep[]
*          0 - New match      (<dist>, <len>), push <dist> to stack
*          1 - Repeated Match
*            pSelf->aIsRepG0[]
*              0 - Distance in RepDist0
*                pSelf->IsRep0Long[]
*                  0 - Repeated match (RepDist0, 1)
*                  1 - Repeated match (RepDist0, <len>)
*              1 -
*                pSelf->aIsRepG1[]
*                  0 - Repeated match (RepDist1, <len>), rotate RepDist1 to top
*                  1 -
*                    pSelf->aIsRepG2[]
*                      0 - Repeated match (RepDist2, <len>), rotate RepDist2 to top
*                      1 - Repeated match (RepDist3, <len>), rotate RepDist3 to top
*
*    Note that the parse tree is completely covered and therefore
*    there is no input bitstream that leads to a terminal state
*    that can be associated with a decoding error.
*/
static void _COMPRESS_LZMA_DECODE_Next(COMPRESS_LZMA_DECODE_CONTEXT *pSelf, COMPRESS_LZMA_STREAM *pStream) {
  ULEAST16 PosState;
  ULEAST16 Len;
  ULEAST16 State;
  U32      RepDist0;
  U32      RepDist1;
  U32      RepDist2;
  U32      RepDist3;
  U32      T;
  //
  // LZMA state transitions.
  //                                                                                     0   1   2   3   4   5   6   7   8   9  10  11
  static const U8 _COMPRESS_LZMA_DECODE_aLitStateTrans     [COMPRESS_LZMA_STATE_MAX] = { 0,  0,  0,  0,  1,  2,  3,  4,  5,  6,  4,  5 };
  static const U8 _COMPRESS_LZMA_DECODE_aMatchStateTrans   [COMPRESS_LZMA_STATE_MAX] = { 7,  7,  7,  7,  7,  7,  7, 10, 10, 10, 10, 10 };
  static const U8 _COMPRESS_LZMA_DECODE_aRepStateTrans     [COMPRESS_LZMA_STATE_MAX] = { 8,  8,  8,  8,  8,  8,  8, 11, 11, 11, 11, 11 };
  static const U8 _COMPRESS_LZMA_DECODE_aShortRepStateTrans[COMPRESS_LZMA_STATE_MAX] = { 9,  9,  9,  9,  9,  9,  9, 11, 11, 11, 11, 11 };
  //
  // Load state.
  //
  State    = pSelf->State;
  RepDist0 = pSelf->RepDist0;
  RepDist1 = pSelf->RepDist1;
  RepDist2 = pSelf->RepDist2;
  RepDist3 = pSelf->RepDist3;
  //
  PosState = pSelf->DecodeCursor & pSelf->PBMask;
  //
  // Literal or match.
  //
  // 0<lit>         Emit literal <lit>
  // 10<len><dist>  New match      (<dist>, <len>), push <dist> to stack
  // 1100           Repeated match (RepDist0, 1)
  // 1101<len>      Repeated match (RepDist0, <len>)
  // 1110<len>      Repeated match (RepDist1, <len>), rotate RepDist1 to top
  // 11110<len>     Repeated match (RepDist2, <len>), rotate RepDist2 to top
  // 11111<len>     Repeated match (RepDist3, <len>), rotate RepDist3 to top
  // ^
  if (_COMPRESS_LZMA_RANGE_DECODE_RdBit(&pSelf->RangeCoder, &pSelf->aIsMatchProbs[(State << COMPRESS_LZMA_CONFIG_DECODE_PB_MAX) + PosState]) == 0u) {
    //
    // 0<lit>         Emit literal <lit>
    //  ^
    _COMPRESS_LZMA_DECODE_PutU8(pSelf, pStream, _COMPRESS_LZMA_DECODE_RdLiteral(pSelf, State, RepDist0));  // Precondition above ensures pSelf->BytesRemaining > 0.
    //
    State = _COMPRESS_LZMA_DECODE_aLitStateTrans[State];
  } else {
    //
    // New match or repeated match.
    //
    // 10<len><dist>  New match      (<dist>, <len>), push <dist> to stack
    // 1100           Repeated match (RepDist0, 1)
    // 1101 <len>     Repeated match (RepDist0, <len>)
    // 1110 <len>     Repeated match (RepDist1, <len>), rotate RepDist1 to top
    // 11110<len>     Repeated match (RepDist2, <len>), rotate RepDist2 to top
    // 11111<len>     Repeated match (RepDist3, <len>), rotate RepDist3 to top
    //  ^
    //
    if (_COMPRESS_LZMA_RANGE_DECODE_RdBit(&pSelf->RangeCoder, &pSelf->aIsRepProbs[State]) == 0u) {
      //
      // New match.
      //
      // 10<len><dist>  New match      (<dist>, <len>)
      //   ^
      Len       = _COMPRESS_LZMA_LENGTH_DECODE_Rd(&pSelf->LenCoder, &pSelf->RangeCoder, PosState);
      RepDist3  = RepDist2;
      RepDist2  = RepDist1;
      RepDist1  = RepDist0;
      RepDist0  = _COMPRESS_LZMA_DECODE_RdDistance(pSelf, Len);
      Len      += COMPRESS_LZMA_MIN_MATCH_LEN;
      State     = _COMPRESS_LZMA_DECODE_aMatchStateTrans[State];
      //
      // Encountered an an end marker?  If so then we DO NOT EXPECT IT!  emCompress
      // always ensures that we encode exactly the correct number of bytes in advance
      // and never uses an end marker.
      //
      if ((RepDist0 == (U32)0xFFFFFFFFu) || (RepDist0 > pSelf->WindowSize)) {
        pSelf->RangeCoder.Error = COMPRESS_LZMA_STATUS_BITSTREAM_ERROR;
      }
    } else {
      //
      // Repeated match.  Need to decode type of match.
      //
      // 1100           Repeated match (RepDist0, 1)
      // 1101 <len>     Repeated match (RepDist0, <len>)
      // 1110 <len>     Repeated match (RepDist1, <len>), rotate RepDist1 to top
      // 11110<len>     Repeated match (RepDist2, <len>), rotate RepDist2 to top
      // 11111<len>     Repeated match (RepDist3, <len>), rotate RepDist3 to top
      //   ^
      if (_COMPRESS_LZMA_RANGE_DECODE_RdBit(&pSelf->RangeCoder, &pSelf->aIsRepG0Probs[State]) == 0u) {
        //
        // 1100           Repeated match (RepDist0, 1)
        // 1101<len>      Repeated match (RepDist0, <len>)
        //    ^
        if (_COMPRESS_LZMA_RANGE_DECODE_RdBit(&pSelf->RangeCoder, &pSelf->aIsRep0LongProbs[(State << COMPRESS_LZMA_CONFIG_DECODE_PB_MAX) + PosState]) == 0u) {
          //
          // 1100           Repeated match (RepDist0, 1)
          //     ^
          Len   = 1;
          State = _COMPRESS_LZMA_DECODE_aShortRepStateTrans[State];
        } else {
          //
          // 1101<len>      Repeated match (RepDist0, <len>)
          //     ^
          Len   = COMPRESS_LZMA_MIN_MATCH_LEN + _COMPRESS_LZMA_LENGTH_DECODE_Rd(&pSelf->RepLenCoder, &pSelf->RangeCoder, PosState);
          State = _COMPRESS_LZMA_DECODE_aRepStateTrans[State];
        }
      } else {
        //
        // 1110 <len>     Repeated match (RepDist1, <len>), rotate RepDist1 to top
        // 11110<len>     Repeated match (RepDist2, <len>), rotate RepDist2 to top
        // 11111<len>     Repeated match (RepDist3, <len>), rotate RepDist3 to top
        //    ^
        COMPRESS_LZMA_DECODE_WATCHDOG_TICK(0u);
        if (_COMPRESS_LZMA_RANGE_DECODE_RdBit(&pSelf->RangeCoder, &pSelf->aIsRepG1Probs[State]) == 0u) {
          //
          // 1110<len>      Repeated match (RepDist1, <len>), rotate RepDist1 to top
          //     ^
          T = RepDist1; RepDist1 = RepDist0; RepDist0 = T;
        } else {
          //
          // 11110<len>     Repeated match (RepDist2, <len>), rotate RepDist2 to top
          // 11111<len>     Repeated match (RepDist3, <len>), rotate RepDist3 to top
          //     ^
          if (_COMPRESS_LZMA_RANGE_DECODE_RdBit(&pSelf->RangeCoder, &pSelf->aIsRepG2Probs[State]) == 0u) {
            //
            // 11110<len>     Repeated match (RepDist2, <len>), rotate RepDist2 to top
            //      ^
            T = RepDist2; RepDist2 = RepDist1; RepDist1 = RepDist0; RepDist0 = T;
          } else {
            //
            // 11111<len>     Repeated match (RepDist3, <len>), rotate RepDist3 to top
            //      ^
            T = RepDist3; RepDist3 = RepDist2; RepDist2 = RepDist1; RepDist1 = RepDist0; RepDist0 = T;
          }
        }
        //
        // 1110 <len>     Repeated match (RepDist1, <len>), rotate RepDist1 to top
        // 11110<len>     Repeated match (RepDist2, <len>), rotate RepDist2 to top
        // 11111<len>     Repeated match (RepDist3, <len>), rotate RepDist3 to top
        //      ^
        Len   = COMPRESS_LZMA_MIN_MATCH_LEN + _COMPRESS_LZMA_LENGTH_DECODE_Rd(&pSelf->RepLenCoder, &pSelf->RangeCoder, PosState);
        State = _COMPRESS_LZMA_DECODE_aRepStateTrans[State];
      }
    }
    //
    // If this match extends past the end of the stream, this is a
    // bitstream error.  If the repeat distance extends stretches
    // beyond the start of the window, this is a bitstream error.
    //
    if ((pSelf->BytesRemaining < Len) || (RepDist0 > pSelf->WindowSize)) {
      pSelf->RangeCoder.Error = COMPRESS_LZMA_STATUS_BITSTREAM_ERROR;
    } else {
      pSelf->CopyLen   = Len;
      pSelf->MetaState = COMPRESS_LZMA_DECODE_STATE_COPY;
    }
  }
  //
  // Store state.
  //
  pSelf->State    = State;
  pSelf->RepDist0 = RepDist0;
  pSelf->RepDist1 = RepDist1;
  pSelf->RepDist2 = RepDist2;
  pSelf->RepDist3 = RepDist3;
}

/*********************************************************************
*
*       _COMPRESS_LZMA_DECODE_Take()
*
*  Function description
*    Accept bitstream input from client.
*
*  Parameters
*    pSelf   - Pointer to decoder context.
*    pStream - Pointer to stream context.
*
*  Additional information
*    It is required that additional input be available from the
*    stream before taking it, i.e. the caller must ensure that
*    pStream->AvailIn > 0.
*/
static void _COMPRESS_LZMA_DECODE_Take(COMPRESS_LZMA_DECODE_CONTEXT *pSelf, COMPRESS_LZMA_STREAM *pStream) {
  pSelf->RangeCoder.aBuf[pSelf->RangeCoder.Wr] = *pStream->pIn;
  ++pSelf->RangeCoder.Len;
  ++pSelf->RangeCoder.Wr;
  if (pSelf->RangeCoder.Wr >= sizeof(pSelf->RangeCoder.aBuf)) {
    pSelf->RangeCoder.Wr = 0;
  }
  ++pStream->pIn;
  --pStream->AvailIn;
}

/*********************************************************************
*
*       _COMPRESS_LZMA_DECODE_Step()
*
*  Function description
*    Run LZMA decoder.
*
*  Parameters
*    pSelf   - Pointer to decoder context.
*    pStream - Pointer to stream context.
*    Flush   - End of input stream flag.
*/
static void _COMPRESS_LZMA_DECODE_Step(COMPRESS_LZMA_DECODE_CONTEXT *pSelf, COMPRESS_LZMA_STREAM *pStream, ILEAST16 Flush) {
  //
  switch (pSelf->MetaState) {
  case COMPRESS_LZMA_DECODE_STATE_INIT:
    if ((Flush != 0) && (pSelf->RangeCoder.Len < (13u+5u))) {
      pSelf->RangeCoder.Error = COMPRESS_LZMA_STATUS_BITSTREAM_ERROR;  // Truncated bitstream.
    } else {
      _COMPRESS_LZMA_DECODE_RdHeader(pSelf);
      if (pSelf->RangeCoder.Error >= 0) {
        _COMPRESS_LZMA_RANGE_DECODE_Start(&pSelf->RangeCoder, &pSelf->RangeCoder.aBuf[13]);
        pSelf->RangeCoder.Len -= 13u + 5u;
        pSelf->RangeCoder.Rd  += 13u + 5u;
        if ((pSelf->LC <= (ULEAST16)COMPRESS_LZMA_CONFIG_DECODE_LC_MAX) && (pSelf->LP <= (ULEAST16)COMPRESS_LZMA_CONFIG_DECODE_LP_MAX) && (pSelf->PB <= (ULEAST16)COMPRESS_LZMA_CONFIG_DECODE_PB_MAX) && (pSelf->WindowSize <= (U32)COMPRESS_LZMA_CONFIG_DECODE_WINDOW_SIZE_MAX)) {
          pSelf->MetaState = COMPRESS_LZMA_DECODE_STATE_NEXT;
        } else {
          pSelf->RangeCoder.Error = COMPRESS_LZMA_STATUS_PARAMETER_ERROR;
        }
      }
    }
    break;
    //
  case COMPRESS_LZMA_DECODE_STATE_NEXT:
    if (pSelf->BytesRemaining > 0u) {
      _COMPRESS_LZMA_DECODE_Next(pSelf, pStream);
    } else {
      pSelf->MetaState = COMPRESS_LZMA_DECODE_STATE_DONE;
    }
    break;
    //
  case COMPRESS_LZMA_DECODE_STATE_COPY:
    COMPRESS_LZMA_DECODE_WATCHDOG_TICK(0);
    while ((pStream->AvailOut > 0u) && (pSelf->CopyLen > 0u)) {
      COMPRESS_LZMA_DECODE_WATCHDOG_TICK(pSelf->CopyLen);
      _COMPRESS_LZMA_DECODE_PutU8(pSelf, pStream, _COMPRESS_LZMA_DECODE_GetU8(pSelf, pSelf->RepDist0 + 1u));
      --pSelf->CopyLen;
    }
    if (pSelf->CopyLen == 0u) {
      pSelf->MetaState = COMPRESS_LZMA_DECODE_STATE_NEXT;
    }
    break;
    //
  case COMPRESS_LZMA_DECODE_STATE_DONE:
  case COMPRESS_LZMA_DECODE_STATE_ERROR:
  default:
    //
    // No state transition in terminal states.
    //
    break;
  }
  //
  // Whenever we error, end up in a terminal state.
  //
  if (pSelf->RangeCoder.Error < 0) {
    pSelf->MetaState = COMPRESS_LZMA_DECODE_STATE_ERROR;
  }
}

/*********************************************************************
*
*       Public code
*
**********************************************************************
*/

/*********************************************************************
*
*       COMPRESS_LZMA_DECODE_Init()
*
*  Function description
*    Initialize LZMA decoder.
*
*  Parameters
*    pSelf - Pointer to decoder context.
*/
void COMPRESS_LZMA_DECODE_Init(COMPRESS_LZMA_DECODE_CONTEXT *pSelf) {
  ULEAST16 i;
  //
  pSelf->MetaState      = COMPRESS_LZMA_DECODE_STATE_INIT;
  pSelf->State          = 0;
  pSelf->RepDist0       = 0;
  pSelf->RepDist1       = 0;
  pSelf->RepDist2       = 0;
  pSelf->RepDist3       = 0;
  pSelf->LC             = 0;
  pSelf->LP             = 0;
  pSelf->PB             = 0;
  pSelf->PBMask         = 0;
  pSelf->DecodedSize    = 0;
  pSelf->BytesRemaining = 0;
  pSelf->WindowCursor   = 0;
  pSelf->WindowSize     = 0;
  pSelf->DecodeCursor   = 0;
  //
  for (i = 0; i < COMPRESS_LZMA_COUNTOF(pSelf->aWindow); ++i) {
    COMPRESS_LZMA_DECODE_WATCHDOG_TICK(i);
    pSelf->aWindow[i] = 0;
  }
  //
  _COMPRESS_LZMA_RANGE_DECODE_Init(&pSelf->RangeCoder);
  _COMPRESS_LZMA_BITTREE_DECODE_Init(&pSelf->PoolCoder, &pSelf->aPoolCoderProbs[0], COMPRESS_LZMA_DIST_CONTEXT_BITS);
  _COMPRESS_LZMA_DECODE_InitProbs(pSelf->aPosCoderProbs, COMPRESS_LZMA_COUNTOF(pSelf->aPosCoderProbs));
  for (i = 0; i < COMPRESS_LZMA_POS_SLOT_CODER_SIZE; ++i) {
    _COMPRESS_LZMA_BITTREE_DECODE_Init(&pSelf->aPosSlotCoder[i], &pSelf->aPosSlotCoderProbs[i][0], COMPRESS_LZMA_POS_SLOT_BITS);
  }
  _COMPRESS_LZMA_DECODE_InitProbs(pSelf->aIsRepProbs,      COMPRESS_LZMA_COUNTOF(pSelf->aIsRepProbs));
  _COMPRESS_LZMA_DECODE_InitProbs(pSelf->aIsRepG0Probs,    COMPRESS_LZMA_COUNTOF(pSelf->aIsRepG0Probs));
  _COMPRESS_LZMA_DECODE_InitProbs(pSelf->aIsRepG1Probs,    COMPRESS_LZMA_COUNTOF(pSelf->aIsRepG1Probs));
  _COMPRESS_LZMA_DECODE_InitProbs(pSelf->aIsRepG2Probs,    COMPRESS_LZMA_COUNTOF(pSelf->aIsRepG2Probs));
  _COMPRESS_LZMA_DECODE_InitProbs(pSelf->aIsRep0LongProbs, COMPRESS_LZMA_COUNTOF(pSelf->aIsRep0LongProbs));
  _COMPRESS_LZMA_DECODE_InitProbs(pSelf->aIsMatchProbs,    COMPRESS_LZMA_COUNTOF(pSelf->aIsMatchProbs));
  _COMPRESS_LZMA_DECODE_InitProbs(pSelf->aLitProbs,        COMPRESS_LZMA_COUNTOF(pSelf->aLitProbs));
  //
  _COMPRESS_LZMA_LENGTH_DECODE_Init(&pSelf->LenCoder);
  _COMPRESS_LZMA_LENGTH_DECODE_Init(&pSelf->RepLenCoder);
}

/*********************************************************************
*
*       COMPRESS_LZMA_DECODE_Run()
*
*  Function description
*    Run LZMA decoder.
*
*  Parameters
*    pSelf   - Pointer to decoder context.
*    pStream - Pointer to stream context.
*    Flush   - End of input stream flag.
*
*  Return value
*    <  0 - Processing error or bitstream error
*    == 0 - Call again to continue processing
*    >  0 - Decompression complete
*/
ILEAST16 COMPRESS_LZMA_DECODE_Run(COMPRESS_LZMA_DECODE_CONTEXT *pSelf, COMPRESS_LZMA_STREAM *pStream, ILEAST16 Flush) {
  ILEAST16 Status;
  ULEAST16 idx = 0u;
  //
  COMPRESS_LZMA_DECODE_WATCHDOG_TICK(0);
  //
  // API validation.
  //
  if ((pStream->AvailOut == 0u) || (pStream->pOut == (void *)0)) {  // Require output buffer
    Status = COMPRESS_LZMA_STATUS_USAGE_ERROR;
  } else if ((pStream->AvailIn == 0u) && (Flush == 0)) {                   // No input requires that we are flushing
    Status = COMPRESS_LZMA_STATUS_USAGE_ERROR;
  } else if ((pStream->AvailIn > 0u) && (pStream->pIn == (void *)0)) {     // Require nonnull input buffer
    Status = COMPRESS_LZMA_STATUS_USAGE_ERROR;
  } else {
    //
    // Keep decoding until we run out of input or fill our output buffer.
    //
    while ((pStream->AvailOut > 0u) && (pSelf->MetaState < COMPRESS_LZMA_DECODE_STATE_DONE)) {
      //
      // Fill internal buffer as far as possible, end-stop on flush.
      //
      COMPRESS_LZMA_DECODE_WATCHDOG_TICK(0);
      while ((pStream->AvailIn > 0u) && (pSelf->RangeCoder.Len < sizeof(pSelf->RangeCoder.aBuf))) {
        COMPRESS_LZMA_DECODE_WATCHDOG_TICK(pStream->AvailIn);
        _COMPRESS_LZMA_DECODE_Take(pSelf, pStream);
      }
      //
      // If we do not have a full buffer to work with, we must exit.
      //
      if ((pSelf->RangeCoder.Len < sizeof(pSelf->RangeCoder.aBuf)) && (Flush == 0)) {
        break;
      }
      //
      // Decompress one item, a literal or match.
      //
      COMPRESS_LZMA_DECODE_WATCHDOG_TICK(idx);
      idx++;
      _COMPRESS_LZMA_DECODE_Step(pSelf, pStream, Flush);
    }
    //
    if (pSelf->RangeCoder.Error < 0) {
      Status = pSelf->RangeCoder.Error;
    } else if (pSelf->MetaState == COMPRESS_LZMA_DECODE_STATE_DONE) {
      Status = 1;
    } else {
      Status = 0;
    }
  }
  //
  return Status;
}

/*************************** End of file ****************************/
