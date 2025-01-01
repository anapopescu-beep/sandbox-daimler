/***********************************************************************************************************************
 *  FILE DESCRIPTION
 *  ------------------------------------------------------------------------------------------------------------------*/
/** \file
 *  \brief         Routines for compression / decompression
 *
 *  --------------------------------------------------------------------------------------------------------------------
 *  COPYRIGHT
 *  --------------------------------------------------------------------------------------------------------------------
 *  \par Copyright
 *  \verbatim
 *  Copyright (c) 2022 by Vector Informatik GmbH.                                                  All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 */
/**********************************************************************************************************************/

/***********************************************************************************************************************
 *  REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Version    Date        Author  Change Id        Description
 *  --------------------------------------------------------------------------------------------------------------------
 *  01.00.00   2006-10-27  visfhe                   First implementation based on version 0.48 of LZVECTOR
 *                                                  Added support for new decompression with variable output length
 *  01.01.00   2008-10-06  visjhg                   Pass decompression parameters in struct
 *                                                  Return length information about processed data
 *                                                  Added return code to DecompressBlockVL
 *                         visfhe                   Release of new data interface
 *  01.02.00   2009-07-13  visfhe                   New handling of output buffer size for VL decompression
 *                                 ESCAN00036209    DecompressBlockVL:
 *                                                  New default case in switch statement to avoid warnings
 *  01.03.00   2010-02-09  visjhg  ESCAN00040756    Renamed package from SysService_Cmpr to SysService_Cmpr1_Vector
 *                                 ESCAN00040758    Improved compression ratio by adding new matches to search buffer
 *                                                  Code refactoring, split window search and output
 *                                 ESCAN00040784    Added maximum output size to CompressBlock
 *  01.04.00   2010-12-09  visjhg  ESCAN00047587    Configurable elemental data types
 *  01.05.00   2012-11-13  visach  ESCAN00062975    Adapted comments to use Doxygen
 *  02.00.00   2019-07-01  visdkl  ESCAN00103551    No changes
 *  02.01.00   2021-01-12  visjdn  FBL-2322         MISRA 2012 analysis and rework
 *  02.01.01   2022-08-18  visjdn  FBL-5647         Added/adapted MemMap sections
 *                                 ESCAN00111905    Configurable watchdog call frequency
 **********************************************************************************************************************/

#define CMPR_SOURCE

/***********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/

#include "cmpr_inc.h"

/***********************************************************************************************************************
 *  VERSION
 **********************************************************************************************************************/

#if ( SYSSERVICE_CMPR1_VECTOR_VERSION != 0x0201u ) || \
    ( SYSSERVICE_CMPR1_VECTOR_RELEASE_VERSION != 0x01u )
# error "Error in CMPR.C: Source and header file are inconsistent!"
#endif

#if ( SYSSERVICE_CMPR1_VECTOR_VERSION != _SYSSERVICE_CMPR_VERSION ) || \
    ( SYSSERVICE_CMPR1_VECTOR_RELEASE_VERSION != _SYSSERVICE_CMPR_RELEASE_VERSION )
# error "Error in CMPR.C: Source and v_ver.h are inconsistent!"
#endif

/***********************************************************************************************************************
 *  DEFINES
 **********************************************************************************************************************/

/* Bit operation macros */
#define CMPR_BITS_TO_LEN(bits)   ((1uL << (bits)) - 1u)
#define CMPR_BYTE_COUNT(bits)    ((bits) >> 3u)
#define CMPR_MASK_LOW(bits)      (cmprUint8)(CMPR_BITS_TO_LEN(bits))
#define CMPR_MASK_HIGH(bits)     (cmprUint8)~(CMPR_MASK_LOW(8u - (bits)))
#define CMPR_MOD_8(value)        ((value) & 0x07u)
#define CMPR_MOD_8_1(value)      ((((value) - 1u) & 0x07u) + 1u)

/* Variable Length Compression Defines */
#define CMPR_PHRASE_ONE                 0x01u
#define CMPR_PHRASE_TWO                 0x02u
#define CMPR_CHARACTER                  0x03u

/* Sliding window size */
#define CMPR_CYCLE_BITS                 (8u)
#define CMPR_CYCLE_MASK                 ((cmprUint32)CMPR_BITS_TO_LEN(CMPR_CYCLE_BITS))
#define CMPR_CYCLE_LENGTH               ((cmprUint32)(CMPR_BITS_TO_LEN(CMPR_CYCLE_BITS) + 1u))

/* Decompression output macros */
#define DecompressOutputByte(buffer, ptrPosition, data) \
{                                      \
   (buffer)[(*ptrPosition)] = (data);  \
   (*ptrPosition)++;                   \
}

#define DecompressUpdateWindow(window, ptrPosition, data)   \
{                                            \
   /* Add to sliding window */               \
   (window)[(*ptrPosition)] = (data);        \
   (*ptrPosition)++;                         \
   /* Wrap around of sliding window index */ \
   (*ptrPosition) &= CMPR_CYCLE_MASK;        \
}

#if ( CMPR_WATCHDOG_FREQ > 0x00uL )
# define doWatchdogHandle(wdgCounter)              \
{                                                  \
   /* Trigger watchdog every n-th cycle */         \
   if ((wdgCounter & CMPR_WATCHDOG_FREQ) == 0u)    \
   {                                               \
      CMPR_WATCHDOG_FCT();                         \
   }                                               \
   /* Increment the watchdog counter */            \
   wdgCounter++;                                   \
}
#endif

/***********************************************************************************************************************
 *  GLOBAL DATA
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  LOCAL DATA
 **********************************************************************************************************************/

#define CMPR_START_SEC_VAR
#include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* Variable Length Compression Defines*/
V_MEMRAM0 static V_MEMRAM1 cmprUint8  V_MEMRAM2 elementType;
V_MEMRAM0 static V_MEMRAM1 cmprUint8  V_MEMRAM2 phraseByte1;  /* PRQA S 3218 */ /* MD_FblCmpr_3218 */
V_MEMRAM0 static V_MEMRAM1 cmprUint8  V_MEMRAM2 phraseByte2;  /* PRQA S 3218 */ /* MD_FblCmpr_3218 */
V_MEMRAM0 static V_MEMRAM1 cmprUint32 V_MEMRAM2 dist;         /* PRQA S 3218 */ /* MD_FblCmpr_3218 */
V_MEMRAM0 static V_MEMRAM1 cmprUint32 V_MEMRAM2 cyclicBufferPos;

/** Cyclic buffer for Decompression */
V_MEMRAM0 static V_MEMRAM1 cmprUint8  V_MEMRAM2 cyclicBuffer[CMPR_CYCLE_LENGTH + 5u];  /* PRQA S 3218 */ /* MD_FblCmpr_3218 */

#define CMPR_STOP_SEC_VAR
#include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_MemMap */

/***********************************************************************************************************************
 *  EXTERNAL DATA
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  PROTOTYPES
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 **********************************************************************************************************************/
#define CMPR_START_SEC_CODE
#include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_MemMap */
/***********************************************************************************************************************
 *  InitDecompressionVL
 **********************************************************************************************************************/
/*! \brief      Make initializations for decompression
 **********************************************************************************************************************/
void InitDecompressionVL(void)
{
   elementType = CMPR_PHRASE_ONE;
   cyclicBufferPos = 0uL;
}

/***********************************************************************************************************************
 *  DecompressBlockVL
 **********************************************************************************************************************/
/*! \brief       Decompress data
 *  \pre         InitDecompressionVL must be called before
 *  \param[in]   cmprParam: structure defining input and output buffer
 **********************************************************************************************************************/
/* PRQA S 6030, 6080 1 */ /* MD_MSR_STCYC, MD_MSR_STMIF */
cmprUint8 DecompressBlockVL( tCmprParam * cmprParam )
{
#if ( CMPR_WATCHDOG_FREQ > 0x00uL )
   cmprUint32  wdgCounter;
#endif
   cmprUint32  currentPos;
   cmprUint32  posIncrement;
   cmprUint32  copyPos;
   cmprUint32  i;
   cmprUint16  phraseLength;
   cmprUint32  phrasePointer;
   cmprUint8   element;
   cmprUint8   overflow;
   cmprUint8   decompState;
   cmprUint8   retVal;
   cmprUint8 const * inputBuffer;
   cmprUint8 * outputBuffer;
   cmprUint32  inputLength;
   cmprUint32  outputLength;
   cmprUint32  maxOutLength;

   /* Place input parameters in local variables */
   inputBuffer = cmprParam->inputBuffer;
   outputBuffer = cmprParam->outputBuffer;

   inputLength = cmprParam->inputLength;
   outputLength = 0u;
   maxOutLength = cmprParam->outputLength;

#if ( CMPR_WATCHDOG_FREQ > 0x00uL )
   wdgCounter = 0uL;
#endif
   currentPos = 0u;
   overflow = 0u;
   decompState = kCmprOk;

   /* Initialize the return value */
   retVal = kCmprOk;

   /* Process input data while output buffer not full */
   while ((currentPos < inputLength)
          && (outputLength < maxOutLength)
          && (overflow == 0u) && (decompState == kCmprOk))
   {
#if (CMPR_WATCHDOG_FREQ > 0x00uL)
      doWatchdogHandle(wdgCounter);
#else
      CMPR_WATCHDOG_FCT();
#endif /* CMPR_WATCHDOG_FREQ */

      /* Read byte from input */
      element = inputBuffer[currentPos];
      posIncrement = 1uL;

      /* State machine */
      switch (elementType)
      {
         case CMPR_PHRASE_ONE:
         {
            /* First phrase byte */
            phraseByte1 = element;
            elementType = CMPR_PHRASE_TWO;

            break;
         }
         case CMPR_PHRASE_TWO:
         {
            /* Second phrase byte */
            phraseByte2 = element;

            /* Decode phrase bytes */

            /* Get phrase position */
            phrasePointer = phraseByte1;

            /* Get length of phrase and distance to next phrase */
            phraseLength = ((cmprUint16)phraseByte2 >> 4);
            dist = ((cmprUint32)phraseByte2 & 0x0Fu);

            if ((phraseLength + outputLength) >= maxOutLength)
            {
               /*
                  Decompressed data exceeds output buffer
                  Abort processing and return current lengths
               */
               overflow = 1u;
               posIncrement = 0uL;
            }
            else
            {
               /* Check if zero phrase or not */
               if (phraseLength == 0u)
               {
                  /* No compressed data encoded */

                  /* Phrase pointer contains uncompressed byte instead */
                  DecompressOutputByte(outputBuffer, &outputLength, (cmprUint8)phrasePointer);

                  /* Add to sliding window */
                  DecompressUpdateWindow(cyclicBuffer, &cyclicBufferPos, (cmprUint8)phrasePointer);
               }
               else
               {
                  /*
                     Calculate modulo position in sliding window
                     According to ISO/IEC 9899 6.2.5 - 9 overflow is well defined
                  */
                  copyPos = (cmprUint32) (cyclicBufferPos - phrasePointer);
                  /* Wrap around of sliding window index */
                  copyPos &= CMPR_CYCLE_MASK;

                  /* Output match */
                  for (i = 0u; i < phraseLength; i++)
                  {
#if (CMPR_WATCHDOG_FREQ > 0x00uL)
                     doWatchdogHandle(wdgCounter);
#else
                     CMPR_WATCHDOG_FCT();
#endif /* CMPR_WATCHDOG_FREQ */

                     /* Copy match from sliding window */
                     DecompressOutputByte(outputBuffer, &outputLength, cyclicBuffer[copyPos]);
                     /* Add to sliding window */
                     DecompressUpdateWindow(cyclicBuffer, &cyclicBufferPos, cyclicBuffer[copyPos]);

                     copyPos++;
                     /* Wrap around of sliding window index */
                     copyPos &= CMPR_CYCLE_MASK;
                  }
               }

               /* Uncompressed data present? */
               if (dist > 0u)
               {
                  /* Uncompressed bytes next */
                  elementType = CMPR_CHARACTER;
               }
               else
               {
                  /* Continue with next phrase */
                  elementType = CMPR_PHRASE_ONE;
               }
            }

            break;
         }

         case CMPR_CHARACTER:
         {
            /* Output single character */
            DecompressOutputByte(outputBuffer, &outputLength, inputBuffer[currentPos]);

            /* Add to sliding window */
            DecompressUpdateWindow(cyclicBuffer, &cyclicBufferPos, inputBuffer[currentPos]);

            /* Reduce counter for uncompressed data */
            dist--;
            if (dist == 0u)
            {
               /* Next phrase reached */
               elementType = CMPR_PHRASE_ONE;
            }

            break;
         }

         default:
         {
            /* State should never be reached */
            decompState = kCmprFailed;
            break;
         }
      }

      /* Increment input buffer position */
      currentPos += posIncrement;
   }

   /* Return length information of processed data */
   cmprParam->inputLength = currentPos;
   cmprParam->outputLength = outputLength;

   if (((inputLength != 0u) && (currentPos == 0u)) || (decompState == kCmprFailed))
   {
      /* No data processed at all (insufficient output buffer size?) */
      retVal = kCmprFailed;
   }

   return retVal;
}
#define CMPR_STOP_SEC_CODE
#include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  MISRA
 *********************************************************************************************************************/

/* Module specific MISRA deviations:

   MD_FblCmpr_3218:
     Reason: The local variables of this module are kept at a central location for a better overview and maintenance.
     Risk: Scope is larger than required (whole file instead of one function). Some other function could access
      the variable.
     Prevention: Restrict the functionality in this module to the intended purpose. Don't add functions which shall not
      be able to access the local data buffers.

*/

/***********************************************************************************************************************
 *  END OF FILE: CMPR.C
 **********************************************************************************************************************/
