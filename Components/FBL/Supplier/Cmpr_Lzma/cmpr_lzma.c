/***********************************************************************************************************************
 *  FILE DESCRIPTION
 *  ------------------------------------------------------------------------------------------------------------------*/
/** \file
 *  \brief       Lzma Decompression Wrapper for implementation of emCompression component
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

/***********************************************************************************************************************
 *  AUTHOR IDENTITY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Name                          Initials      Company
 *  --------------------------------------------------------------------------------------------------------------------
 *  Thomas Mueller                ThM           Vector Informatik GmbH
 *  --------------------------------------------------------------------------------------------------------------------
 *  REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Version    Date        Author  Change Id        Description
 *  --------------------------------------------------------------------------------------------------------------------
 *  01.00.00   2016-11-05  ThM     -                Creation
 *  01.00.01   2016-11-17  ThM     ESCAN00092841    Added compression mode switch
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/

#include "fbl_inc.h"
#include "cmpr_lzma.h"
#include "COMPRESS_LZMA_DECODE.h"

/***********************************************************************************************************************
 *   VERSION
 **********************************************************************************************************************/

#if ( SYSSERVICE_CMPRLZMA_VERSION != 0x0100u ) || \
    ( SYSSERVICE_CMPRLZMA_RELEASE_VERSION != 0x01u )
# error "Error in cmpr_lzma.c: Source and header file are inconsistent!"
#endif

#if defined( FBL_ENABLE_COMPRESSION_MODE )

/***********************************************************************************************************************
 *  DEFINES
 **********************************************************************************************************************/

#define LZMA_COMPRESS_ERROR_OCCURED             0x0
#define LZMA_COMPRESS_INPUT_BUFFER_CONSUMED     0x1
#define LZMA_COMPRESS_OUTBUTBUFFER_FULL         0x2
#define LZMA_COMPRESS_FINISHED_RUN              0x3
#define LZMA_COMPRESS_RUN                       0x4

/* Extend compression return states */
#define COMPRESS_LZMA_STATUS_PENDING                  0x0
#define COMPRESS_LZMA_STATUS_DECOMPRESSION_FINISHED   0x1

/***********************************************************************************************************************
 *  LOCAL DATA
 **********************************************************************************************************************/

V_MEMRAM0 static V_MEMRAM1 COMPRESS_LZMA_DECODE_CONTEXT V_MEMRAM2 lzmaPSelf; /* PRQA S 3218, 0612 */ /* MD_FblCmprLzma_3218, MD_FblCmprLzma_0612 */
V_MEMRAM0 static V_MEMRAM1 COMPRESS_LZMA_STREAM V_MEMRAM2 lzmaStream; /* PRQA S 3218 */ /* MD_FblCmprLzma_3218 */
V_MEMRAM0 static V_MEMRAM1 vuint8 V_MEMRAM2 cmprEos;

/***********************************************************************************************************************
 *  CmprLzmaInit
 **********************************************************************************************************************/
/*! \brief       Initializes cmprEos and pSelf structure of decompression module
 *  \return      kFblOk Decompression module successfully initialized
 *               kFblFailed Decompression module initialization failed
 **********************************************************************************************************************/
tFblResult CmprLzmaInit( void )
{
   cmprEos = COMPRESS_LZMA_EOS_INVALID;
   COMPRESS_LZMA_DECODE_Init(&lzmaPSelf);
   
   return kFblOk;
}

/***********************************************************************************************************************
 *  CmprLzmaDeinit
 **********************************************************************************************************************/
/*! \brief       Deinitialization of the decompression module for final decompression call
 *  \return      kFblOk Decompression module successfully deinitialized
 *               kFblFailed Decompression module deinitialization
 **********************************************************************************************************************/
tFblResult CmprLzmaDeinit( V_MEMRAM1 tProcParam V_MEMRAM2 V_MEMRAM3 * procParam )
{
   cmprEos = COMPRESS_LZMA_EOS_VALID;
   
   return CmprLzmaDecompress(procParam);
}

/***********************************************************************************************************************
 *  CmprLzmaDecompress
 **********************************************************************************************************************/
/*! \brief       Used as wrapper for the LZMA decompression algorithm
 *  \param[out]  procParam Contains length and pointer of in/out-buffer
 *  \return      kFblOk Decompression of buffer successful
 *               kFblFailed Failure in buffer decompression
 **********************************************************************************************************************/
tFblResult CmprLzmaDecompress( V_MEMRAM1 tProcParam V_MEMRAM2 V_MEMRAM3 * procParam )
{
   COMPRESS_LZMA_DECODE_STATE checkState;
   ILEAST16 rangeCoderError;
   vuint8 result = kFblFailed;
   vuint8 compressionCode = LZMA_COMPRESS_RUN;
   ILEAST16 compressionReturn = -1;
   vuint16 overallProducedBytes = 0u;
   vuint16 overallConsumedBytes = 0u;
   vuint32 consumedIn = 0u;
   vuint32 consumedOut = 0u;
   vuint32 producedBytesInLastRun = 0u;
   vuint32 consumedBytesInLastRun = 0u;

   lzmaStream.pIn = procParam->dataBuffer;
   lzmaStream.AvailIn = procParam->dataLength;
   lzmaStream.pOut = procParam->dataOutBuffer;
   lzmaStream.AvailOut = procParam->dataOutMaxLength;

   while (compressionCode == LZMA_COMPRESS_RUN)
   {
      consumedIn = lzmaStream.AvailIn;
      consumedOut = lzmaStream.AvailOut;
      checkState = lzmaPSelf.MetaState;
      rangeCoderError = lzmaPSelf.RangeCoder.Error;
      /* Call of LZMA decompression API */
      compressionReturn = COMPRESS_LZMA_DECODE_Run(&lzmaPSelf, &lzmaStream, (ILEAST16)cmprEos); /* PRQA S 3756, 3715 */ /* MD_FblCmprLzma_37xx */
      consumedBytesInLastRun = consumedIn - lzmaStream.AvailIn;
      producedBytesInLastRun = consumedOut - lzmaStream.AvailOut;
      overallConsumedBytes += (vuint16)consumedBytesInLastRun;
      overallProducedBytes += (vuint16)producedBytesInLastRun;

      switch (compressionReturn)
      {
         case COMPRESS_LZMA_STATUS_DECOMPRESSION_FINISHED:
            {
               compressionCode = LZMA_COMPRESS_FINISHED_RUN;
               result = kFblOk;
               break;
            }
         /* Usually output buffer is fully consumed */
         case COMPRESS_LZMA_STATUS_USAGE_ERROR:
            {
               if ((lzmaStream.AvailIn != 0u) || (producedBytesInLastRun != 0u))
               {
                  compressionCode = LZMA_COMPRESS_OUTBUTBUFFER_FULL;
                  /* Error occured but nothing changed in buffer or length, neither input nor output, reset error state to proceed further run calls */
                  lzmaPSelf.MetaState = checkState;
                  lzmaPSelf.RangeCoder.Error = rangeCoderError;
                  result = kFblOk;
               }
               else
               {
                  cmprEos = COMPRESS_LZMA_EOS_VALID;
                  compressionCode = LZMA_COMPRESS_RUN;
               }
               break;
            }
         default:
            {
               if (compressionReturn < 0)
               {
                  compressionCode = LZMA_COMPRESS_ERROR_OCCURED;
                  result = kFblFailed;
               }
               /* Output buffer is full */
               else if (lzmaStream.AvailOut == 0u)
               {
                  compressionCode = LZMA_COMPRESS_OUTBUTBUFFER_FULL;
                  result = kFblOk;
               }
               /* Input buffer is fully consumed */
               else if (lzmaStream.AvailIn == 0u)
               {
                  /* When nothing happened repeat decompression call */
                  if ((producedBytesInLastRun == 0u) && (consumedBytesInLastRun == 0u))
                  {
                     compressionCode = LZMA_COMPRESS_RUN;
                  }
                  else
                  {
                     compressionCode = LZMA_COMPRESS_INPUT_BUFFER_CONSUMED;
                  }
                  result = kFblOk;
               }
               else
               {
                  compressionCode = LZMA_COMPRESS_ERROR_OCCURED;
                  result = kFblFailed;
               }
            } /* default */
      } /* switch */
   } /* compressionCode == LZMA_COMPRESS_RUN */
   
   /* Processed input length */
   procParam->dataLength = overallConsumedBytes;
   /* Processed output length */
   procParam->dataOutLength = overallProducedBytes;

   return result;
} /* PRQA S 6080 */ /* MD_FblCmprLzma_6080 */

/* module specific MISRA deviations:

   MD_FblCmprLzma_3218:
     Reason: Leave this as global, even though accessed only in one function through symmetry reasons.
     Risk: No risk.
     Prevention: No prevention

   MD_FblCmprLzma_37xx:
     Reason: This warning occurs because of the interface of the decompression implementation which 
     cannot be modified.
     Risk: No risk.
     Prevention: No prevention
     
   MD_FblCmprLzma_0612:
     Reason: Object defined by interface of decompression implementation which is an external resource
     and cannot be modified. Size of object depends on configuration and is just in special cases
     larger than 32767 bytes.
     Risk: No risk.
     Prevention: No prevention

   MD_FblCmprLzma_6080:
     Reason: This warning occurs because of a complex wrapper algorithm.
     Risk: No risk.
     Prevention: No prevention
     
*/

#endif /* FBL_ENABLE_COMPRESSION_MODE */

/***********************************************************************************************************************
 *  END OF FILE: CMPR_LZMA.C
 **********************************************************************************************************************/
