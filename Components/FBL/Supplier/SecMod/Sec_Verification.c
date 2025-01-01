/***********************************************************************************************************************
 *  FILE DESCRIPTION
 *  ------------------------------------------------------------------------------------------------------------------*/
/** \file
 *  \brief        Implementation of the verification component of the HIS security module - Signature verification
 *
 *  \description  Offers signature/checksum verification interface
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
 *  Refer to the module's header file.
 *
 *  FILE VERSION
 *  --------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 **********************************************************************************************************************/

#define SEC_VERIFICATION_SOURCE

/***********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/

/* Security module interface */
#include "Sec.h"

/* Verification interface */
#include "Sec_Verification.h"

#if defined ( SEC_ENABLE_CSM )
# include "Csm.h"
#endif /* SEC_ENABLE_CSM */
/***********************************************************************************************************************
 *  DEFINES
 **********************************************************************************************************************/

/* PRQA S 3453 TAG_SecVerification_3453_1 */ /* MD_CBD_19.7 */

/** Byte length of address and length information included in checksum calculation */
#define SEC_ADDRESS_LENGTH_INPUT_SIZE    4u

/* Configuration of addons of verification API */
#if defined( SEC_ENABLE_CRC_TOTAL )
# define SEC_OPERATION_SIZE_CRC_TOTAL           1u
#else
# define SEC_OPERATION_SIZE_CRC_TOTAL           0u
#endif /* SEC_ENABLE_CRC_TOTAL */
#if defined( SEC_ENABLE_CRC_WRITTEN )
# define SEC_OPERATION_SIZE_CRC_WRITTEN         1u
#else
# define SEC_OPERATION_SIZE_CRC_WRITTEN         0u
#endif /* SEC_ENABLE_CRC_WRITTEN */
#if defined( SEC_ENABLE_VENDOR_CHECKSUM )
# define SEC_OPERATION_SIZE_VENDOR_CHECKSUM     1u
#else
# define SEC_OPERATION_SIZE_VENDOR_CHECKSUM     0u
#endif /* SEC_ENABLE_VENDOR_CHECKSUM */
/** Total size of operation table */
#define SEC_OPERATION_SIZE                      (SEC_OPERATION_SIZE_CRC_TOTAL + SEC_OPERATION_SIZE_CRC_WRITTEN + SEC_OPERATION_SIZE_VENDOR_CHECKSUM + 1u)

/** Maximum number of operation primitives which can be passed to SecM_VerificationWrapper */
#if defined( SEC_VER_MAX_CONFIG_COUNT )
#else
# define SEC_VER_MAX_CONFIG_COUNT               SEC_OPERATION_SIZE
#endif /* SEC_VER_MAX_CONFIG_COUNT */

/** Number of elements in array */
#define SEC_VER_ARRAY_SIZE(arr)                 (sizeof(arr) / sizeof((arr)[0]))

/* Handling of resulting length for memory reads */

/** Report no error in case no data was read at all */
#define SEC_READ_COUNT_RESULT_IGNORE            SECM_VER_OK
/** Report error in case of mismatch between read count and requested length */
#define SEC_READ_COUNT_RESULT_ASSERT            SECM_VER_ERROR

/** Read count can differ from requested length */
#define SEC_READ_COUNT_MASK_IGNORE              0x00u
/** Read count has to match requested length */
/* Remark: Conversion of negative one to unsigned type with all bits set is guaranteed by C standard (6.3.1.3/2) */
#define SEC_READ_COUNT_MASK_ASSERT              0xFFFFFFFFuL

/** Depending on the underlying memory (byte-/word-addressed) the behavior of the readMemory() function deviates:
 *  - On byte-addressed platforms the function usually reads exactly the requested number of bytes
 *  - On word-addressed platforms twice the number of requested bytes is read */
# define SEC_MEMORY_READ_ACCESS_WIDTH           1u

/* PRQA L:TAG_SecVerification_3453_1 */

/***********************************************************************************************************************
 *  LOCAL DATA TYPES AND STRUCTURES
 **********************************************************************************************************************/

/** Context of SecM_Verification operation */
typedef struct
{
   FL_ReadMemoryFctType       readMemory;       /**< Pointer to memory read function */
   SecM_AddrType              verifyAddress;    /**< Current verification address */
   SecM_SizeType              remainingBytes;   /**< Number of remaining bytes in segment */
   SecM_SignatureParamType    sigParam;         /**< Pointer to global signature parameter */
#if defined( SEC_ENABLE_VERIFICATION_ASSERT_READ_COUNT ) && \
    defined( SEC_ENABLE_CRC_TOTAL )
   SecM_SizeType              readCountMask;    /**< Mask applied when comparing read count against requested length */
   SecM_StatusType            readCountResult;  /**< Result returned when comparison of read count and requested length fails */
#endif /* SEC_ENABLE_VERIFICATION_ASSERT_READ_COUNT && SEC_ENABLE_CRC_TOTAL */
} SecM_VerifyContextType;

/** List of verification primitive configurations */
typedef struct
{
   SecM_VerifyConfigType   pPrimitives[SEC_VER_MAX_CONFIG_COUNT]; /**< List of primitive operation and context pairs */
   SecM_ByteFastType       count;                                 /**< Number of list entries */
} SecM_VerifyConfigPairType;

/***********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 **********************************************************************************************************************/

#define SECM_START_SEC_CODE
#include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_MemMap */

#if defined( SEC_ENABLE_VERIFICATION_RANGE_CHECK )
static SecM_StatusType SecM_CheckRangeOverflow( SecM_AddrType address, SecM_SizeType length );
#endif /* SEC_ENABLE_VERIFICATION_RANGE_CHECK */

static SecM_StatusType SecM_VerifyWrapper( V_MEMRAM1 SecM_SignatureParamType V_MEMRAM2 V_MEMRAM3 * pVerifyParam,
   V_MEMRAM1 SecM_VerifyConfigPairType V_MEMRAM2 V_MEMRAM3 * pCfgList );
static SecM_StatusType SecM_UpdateSegment( V_MEMRAM1 SecM_VerifyContextType V_MEMRAM2 V_MEMRAM3 * pContext,
   V_MEMRAM1 SecM_VerifyConfigPairType V_MEMRAM2 V_MEMRAM3 * pCfgList );

#if defined( SEC_ENABLE_VERIFICATION_ADDRESS_LENGTH )
static SecM_StatusType SecM_UpdateSegmentAddress( V_MEMRAM1 SecM_VerifyContextType V_MEMRAM2 V_MEMRAM3 * pContext,
   V_MEMRAM1 SecM_VerifyConfigPairType V_MEMRAM2 V_MEMRAM3 * pCfgList,
   const V_MEMRAM1 FL_SegmentInfoType V_MEMRAM2 V_MEMRAM3 * pSegmentInfo );
#endif /* SEC_ENABLE_VERIFICATION_ADDRESS_LENGTH */

static void SecM_PopulateCfgList( const V_MEMRAM1 SecM_VerifyConfigListType V_MEMRAM2 V_MEMRAM3 * pSourceList,
   V_MEMRAM1 SecM_VerifyConfigPairType V_MEMRAM2 V_MEMRAM3 * pTargetList, SecM_ByteType mask );

#if defined( SEC_ENABLE_VERIFICATION_WRAPPER )
#else
static SecM_StatusType SecM_VerificationWrapper ( V_MEMRAM1 SecM_VerifyParamType V_MEMRAM2 V_MEMRAM3 * pVerifyParam,
   const V_MEMRAM1 SecM_VerifyConfigListType V_MEMRAM2 V_MEMRAM3 * pCfgList );
#endif /* SEC_ENABLE_VERIFICATION_WRAPPER */

#if defined( SEC_ENABLE_VERIFY_HASH )
static SecM_StatusType SecM_CopyDigest(SecM_ConstRamDataType pCalculatedData, SecM_LengthType calculatedSize,
   SecM_RamDataType pOutputData, SecM_LengthType outputSize);
static SecM_StatusType SecM_CompareDigest(SecM_ConstRamDataType pCalculatedData, SecM_LengthType calculatedSize,
   SecM_ConstRamDataType pProvidedData, SecM_LengthType providedSize);
#endif /* SEC_ENABLE_VERIFY_HASH */
#if defined( SEC_ENABLE_VERIFY_CRC )
static SecM_StatusType SecM_CopyCrcParam(V_MEMRAM1 SecM_SignatureParamType V_MEMRAM2 V_MEMRAM3 * pVerifyParam,
   SecM_ByteType crcAction, V_MEMROM1 SecM_CrcPrimitiveType V_MEMROM2 V_MEMROM3 * pPrimitive);
#endif /* SEC_ENABLE_VERIFY_CRC */
#if defined( SEC_ENABLE_VERIFY_MAC_CONTEXT_HANDLING ) || \
    defined( SEC_ENABLE_VERIFY_SIGNATURE_CONTEXT_HANDLING )
static SecM_StatusType SecM_VerifyContextHandling( SecM_WordType jobId, SecM_WordType ctxBuffSize, SecM_WordType *pSize, SecM_ByteType *pData );
#endif
#define SECM_STOP_SEC_CODE
#include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_MemMap */

/***********************************************************************************************************************
 *  LOCAL DATA
 **********************************************************************************************************************/

#define SECM_START_SEC_CONST
#include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_MemMap */

#if defined( SEC_ENABLE_CRC )
/** Zero CRC value */
V_MEMROM0 static V_MEMROM1 SecM_CRCType V_MEMROM2 crcZeroValue = SEC_ZERO_VALUE;    /* PRQA S 3218 */ /* MD_SecVerification_3218 */
#endif /* SEC_ENABLE_CRC */

#define SECM_STOP_SEC_CONST
#include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_MemMap */

/***********************************************************************************************************************
 *  LOCAL FUNCTIONS
 **********************************************************************************************************************/

#define SECM_START_SEC_CODE
#include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_MemMap */

#if defined( SEC_ENABLE_VERIFICATION_RANGE_CHECK )
/***********************************************************************************************************************
 *  SecM_CheckRangeOverflow
 **********************************************************************************************************************/
/*! \brief      Check whether memory range defined by address and length create an address range overflow
 *  \param[in]  address Start address of memory range
 *  \param[in]  length Length of memory range
 *  \return     SECM_OK if no range overflow detected
 *              SECM_NOT_OK otherwise
 **********************************************************************************************************************/
static SecM_StatusType SecM_CheckRangeOverflow( SecM_AddrType address, SecM_SizeType length )
{
   SecM_StatusType result;

   result = SECM_OK;

   /* No range overflow possible with zero length */
   if (length > 0u)
   {
      /* Last address of memory range is not allowed to be greater than the maximum representable value
         Following expression mathematically equals: (address + (length - 1u)) > 0xFF...FFu
         Conversion of negative one to unsigned type with all bits set is guaranteed by C standard (6.3.1.3/2) */
      if (address > (0xFFFFFFFFuL - (length - 1u)))
      {
         result = SECM_NOT_OK;
      }
   }

   return result;
}
#endif /* SEC_ENABLE_VERIFICATION_RANGE_CHECK */

/***********************************************************************************************************************
 *  SecM_VerifyWrapper
 **********************************************************************************************************************/
/*! \brief         Performs a verify operation for a given set of verification primitives
 *  \details       Interates over all primitives given in list, passing them the information from the verification
 *                 parameter.
 *                 During initialization operation (SEC_HASH_INIT) the following additional information is assigned
 *                 to the primary verification primitive:
 *                 - External key data
 *                 During verification operation (SEC_SIG_VERIFY) the following additional information is passed
 *                 to all verification primitives:
 *                 - Length of signature/checksum taken from primitive configuration instead of verification parameter
 *                 - Pointer to verification data moved by offset taken from primitive configuration
 *  \param[in]     pVerifyParam Pointer to parameter structure for signature verification
 *  \param[in]     pCfgList Pointer to list of verification primitives including contexts
 *  \return        SECM_VER_OK if verification operation successful
 *                 SECM_VER_ERROR if error occured during verification
 *                 SECM_VER_CRC if CRC verification failed
 *                 SECM_VER_SIG if MAC/Signature verification failed
 **********************************************************************************************************************/
 /* PRQA S 3673 2 */ /* MD_MSR_Rule8.13 */
static SecM_StatusType SecM_VerifyWrapper( V_MEMRAM1 SecM_SignatureParamType V_MEMRAM2 V_MEMRAM3 * pVerifyParam,
                                           V_MEMRAM1 SecM_VerifyConfigPairType V_MEMRAM2 V_MEMRAM3 * pCfgList )
{
   SecM_StatusType            result;
   SecM_ByteFastType          index;
   SecM_ByteFastType          cfgCount;
   SecM_ByteType              action;
   SecM_LengthType            byteCount;
   SecM_LengthFastType        sourceOffset;
   V_MEMRAM1 SecM_VerifyConfigType V_MEMRAM2 V_MEMRAM3 *    pConfig; /* PRQA S 3678 */ /* MD_MSR_Rule8.13 */
   V_MEMROM1 SecM_VerifyOperationType V_MEMROM2 V_MEMROM3 * pOperation;
   V_MEMRAM1 SecM_SignatureParamType V_MEMRAM2 V_MEMRAM3 *  pParam;

   result = SECM_VER_OK;

   /* Action and byte count taken from verification parameter per default */
   action         = pVerifyParam->sigState;
   byteCount      = pVerifyParam->sigByteCount;
   /* Offset into source buffer defaults to zero: all primitives process the full input data */
   sourceOffset   = 0u;

   /* Perform some special actions during intialization */
   if (SEC_HASH_INIT == action)
   {
      /* Get pointer to primary verification primitive Located in first entry */
      pConfig  = &pCfgList->pPrimitives[0u];
      pParam   = pConfig->pContext;

      /* Pass external key to primary verification primitive
         This may be a null pointer (SEC_VERIFY_KEY_NULL) */
      pParam->key = pVerifyParam->key;
   }

   /* Loop all verification primitives */
   cfgCount = pCfgList->count;

   for (index = 0u; index < cfgCount; index++)
   {
      /* Get pointer to verification primitive for easier access */
      pConfig     = &pCfgList->pPrimitives[index];
      pOperation  = pConfig->pOperation;
      pParam      = pConfig->pContext;

      /* Special handling for finalization operation */
      if (SEC_SIG_VERIFY == action)
      {
         /* Length of signature/checksum and offset into verification data taken from primitve configuration */
         sourceOffset   = pOperation->offset;
         byteCount      = pOperation->length;
      }

      /* Pass settings to dedicated parameters */
      pParam->sigState        = action;
      pParam->sigSourceBuffer = &pVerifyParam->sigSourceBuffer[sourceOffset];
      pParam->sigByteCount    = byteCount;
      pParam->wdTriggerFct    = pVerifyParam->wdTriggerFct;

      /* Perform operation for current primitive */
      result = pOperation->pFunction(pParam);

      if (SECM_VER_OK != result)
      {
         /* Operation failed, abort further processing */
         break;
      }
   }

   return result;
}

/***********************************************************************************************************************
 *  SecM_UpdateSegment
 **********************************************************************************************************************/
/*! \brief         Read memory contents of one segment and pass to update operation of given primitives
 *  \param[in,out] pContext Pointer to verification context containing segment information
 *  \param[in]     pCfgList Pointer to list of verification primitives
 *  \return        SECM_VER_OK if update operation successful
 *                 SECM_VER_ERROR if error occured during update
 **********************************************************************************************************************/
static SecM_StatusType SecM_UpdateSegment( V_MEMRAM1 SecM_VerifyContextType V_MEMRAM2 V_MEMRAM3 * pContext,
   V_MEMRAM1 SecM_VerifyConfigPairType V_MEMRAM2 V_MEMRAM3 * pCfgList )
{
   SecM_StatusType   result;
   SecM_AddrType     currentAddress;
   SecM_SizeType     remainderLength;
   SecM_SizeType     verifyCount;
   SecM_SizeType     readCount;
#if defined( SEC_ENABLE_VERIFICATION_ASSERT_READ_COUNT ) && \
    defined( SEC_ENABLE_CRC_TOTAL )
   SecM_SizeType     countMask;
   SecM_StatusType   countResult;
#endif /* SEC_ENABLE_VERIFICATION_ASSERT_READ_COUNT && SEC_ENABLE_CRC_TOTAL */
   SecM_ByteType     verifyBuffer[SEC_VERIFY_BYTES];
   V_MEMRAM1 SecM_SignatureParamType V_MEMRAM2 V_MEMRAM3 * pVerifyParam;

   result = SECM_VER_OK;

   if (pCfgList->count > 0u)
   {
      /* Move context parameters to local variables for easier access */
      currentAddress  = pContext->verifyAddress;
      remainderLength = pContext->remainingBytes;

#if defined( SEC_ENABLE_VERIFICATION_ASSERT_READ_COUNT ) && \
    defined( SEC_ENABLE_CRC_TOTAL )
      countMask      = pContext->readCountMask;
      countResult    = pContext->readCountResult;
#endif /* SEC_ENABLE_VERIFICATION_ASSERT_READ_COUNT && SEC_ENABLE_CRC_TOTAL */

#if defined( SEC_ENABLE_VERIFICATION_RANGE_CHECK )
      /* Check for range overflow */
      if (SECM_OK != SecM_CheckRangeOverflow(currentAddress, remainderLength))
      {
         /* Invalid memory range */
         result = SECM_VER_ERROR;
      }
      else
#endif /* SEC_ENABLE_VERIFICATION_RANGE_CHECK */
      {
         pVerifyParam = &pContext->sigParam;

         pVerifyParam->sigSourceBuffer  = verifyBuffer;      /* PRQA S 3225 */ /* MD_SecVerification_3225 */
         pVerifyParam->sigState         = SEC_HASH_COMPUTE;

         while (remainderLength > 0u)
         {
            /* Serve watchdog every loop cycle */
            SEC_WATCHDOG_TRIGGER(pVerifyParam->wdTriggerFct); /* PRQA S 3109 */ /* MD_MSR_14.3 */

            /* Number of bytes to handle in this loop */
            verifyCount = SEC_VERIFY_BYTES / SEC_MEMORY_READ_ACCESS_WIDTH;
            if (remainderLength < (SEC_VERIFY_BYTES / SEC_MEMORY_READ_ACCESS_WIDTH))
            {
               /* Limit to remainder */
               verifyCount = remainderLength;
            }

            /* Copy data from memory to RAM buffer */
            readCount = pContext->readMemory(currentAddress, verifyBuffer, verifyCount);

#if defined( SEC_ENABLE_VERIFICATION_ASSERT_READ_COUNT )
# if defined( SEC_ENABLE_CRC_TOTAL )
            /* Update operation only necessary in case any data was read */
            if ( (readCount > 0u)
            /* Compare read count and requested length
               Have to match exactly if mask is completely set (intra-segment)
               Can have arbitrary values if mask is zero (inter-segment) */
#  if ( SEC_MEMORY_READ_ACCESS_WIDTH == 1u )
              && ((readCount & countMask) == (verifyCount & countMask)))
#  else
              && ((readCount & countMask) == ((SEC_MEMORY_READ_ACCESS_WIDTH * verifyCount) & countMask)))
#  endif
# else
            /* Verification only operates on inter-segment data
               So read count has to match the requested length, otherwise something went wrong */
            if (readCount == (SEC_MEMORY_READ_ACCESS_WIDTH * verifyCount)) /* PRQA S 2986 */ /* MD_SecVerification_2986 */
# endif /* SEC_ENABLE_CRC_TOTAL */
#else
            /* Update operation only necessary in case any data was read */
            if (readCount > 0u)
#endif /* SEC_ENABLE_VERIFICATION_ASSERT_READ_COUNT */
            {
               /* Pass read data to all verification primitives */
               pVerifyParam->sigByteCount = (SecM_LengthType)readCount;
               result = SecM_VerifyWrapper(pVerifyParam, pCfgList);
            }
            else
            {
#if defined( SEC_ENABLE_VERIFICATION_ASSERT_READ_COUNT )
# if defined( SEC_ENABLE_CRC_TOTAL )
               /* Report error in case of intra-segment data as either no data at all or not the expected length was read
                  Report no error in case of inter-segment data as there may be no actual memory at the requested address,
                  resulting in a read count of zero */
               result = countResult;
# else
               /* Read operation did not return expeced length, report error */
               result = SECM_VER_ERROR;
# endif /* SEC_ENABLE_CRC_TOTAL */
#else
               /* Continue operation */
#endif /* SEC_ENABLE_VERIFICATION_ASSERT_READ_COUNT */
            }

            /* Update address information */
            currentAddress  += verifyCount;
            remainderLength -= verifyCount;   /* PRQA S 3382 */ /* MD_SecVerification_3382 */

            if (SECM_VER_OK != result)
            {
               /* Operation failed, abort further processing */
               break;
            }
         }
      }
   }
   else
   {
      /* No matching configurations given (e.g. CRC total calculation disabled at run-time)
         Continue without performing any actual operation */
   }

   return result;
}

#if defined( SEC_ENABLE_VERIFICATION_ADDRESS_LENGTH )
/***********************************************************************************************************************
 *  SecM_UpdateSegmentAddress
 **********************************************************************************************************************/
/*! \brief         Pass serialized address and length information of one segment to update operation of given primitives
 *  \param[in,out] pContext Pointer to verification context containing segment information
 *  \param[in]     pCfgList Pointer to list of verification primitives
 *  \param[in]     pSegmentInfo Pointer to segment information (address and length)
 *  \return        SECM_VER_OK if update operation successful
 *                 SECM_VER_ERROR if error occured during update
 **********************************************************************************************************************/
static SecM_StatusType SecM_UpdateSegmentAddress( V_MEMRAM1 SecM_VerifyContextType V_MEMRAM2 V_MEMRAM3 * pContext,
   V_MEMRAM1 SecM_VerifyConfigPairType V_MEMRAM2 V_MEMRAM3 * pCfgList,
   const V_MEMRAM1 FL_SegmentInfoType V_MEMRAM2 V_MEMRAM3 * pSegmentInfo )
{
   SecM_StatusType   result;
   SecM_ByteType     addressBuffer[2u * SEC_ADDRESS_LENGTH_INPUT_SIZE];
   V_MEMRAM1 SecM_SignatureParamType V_MEMRAM2 V_MEMRAM3 * pVerifyParam;

   result = SECM_VER_OK;

   if (pCfgList->count > 0u)
   {
      /* Convert address and length of current segment to big-endian byte array */
      SecM_SetInteger(SEC_ADDRESS_LENGTH_INPUT_SIZE, pSegmentInfo->transferredAddress, &addressBuffer[0]);
      SecM_SetInteger(SEC_ADDRESS_LENGTH_INPUT_SIZE, pSegmentInfo->length, &addressBuffer[SEC_ADDRESS_LENGTH_INPUT_SIZE]);

      pVerifyParam = &pContext->sigParam;

      pVerifyParam->sigSourceBuffer = addressBuffer;                     /* PRQA S 3225 */ /* MD_SecVerification_3225 */
      pVerifyParam->sigByteCount    = 2u * SEC_ADDRESS_LENGTH_INPUT_SIZE;
      pVerifyParam->sigState        = SEC_HASH_COMPUTE;

      /* Update verification using address and length information */
      result = SecM_VerifyWrapper(pVerifyParam, pCfgList);
   }
   else
   {
      /* No matching configurations given, continue without performing any actual operation */
   }

   return result;
}
#endif /* SEC_ENABLE_VERIFICATION_ADDRESS_LENGTH */

/***********************************************************************************************************************
 *  SecM_PopulateCfgList
 **********************************************************************************************************************/
/*! \brief         Populate configuration list with all verification primitives matching given criteria
 *  \param[in]     pSourceList Pointer to list containing all verification primitives
 *  \param[out]    pTargetList Pointer to list filled with verification primitive pairs matching criteria
 *  \param[in]     mask Criteria mask (0x00u if all primitives shall be included)
 **********************************************************************************************************************/
static void SecM_PopulateCfgList( const V_MEMRAM1 SecM_VerifyConfigListType V_MEMRAM2 V_MEMRAM3 * pSourceList,
   V_MEMRAM1 SecM_VerifyConfigPairType V_MEMRAM2 V_MEMRAM3 * pTargetList, SecM_ByteType mask )
{
   SecM_ByteFastType inIndex;
   SecM_ByteFastType outIndex;
   V_MEMROM1 SecM_VerifyOperationType V_MEMROM2 V_MEMROM3 * pSourceOperation;
   V_MEMRAM1 SecM_SignatureParamType V_MEMRAM2 V_MEMRAM3 *  pSourceParam;
   V_MEMRAM1 SecM_VerifyConfigType V_MEMRAM2 V_MEMRAM3 *    pTarget;

   /* Index for output list */
   outIndex = 0u;
   /* Loop all input primitives */
   for (inIndex = 0u; inIndex < pSourceList->count; inIndex++)
   {
      /* Take matching operation and context from the individual lists */
      pSourceOperation  = &pSourceList->pPrimitives.pOperation[inIndex];
      pSourceParam      = &pSourceList->pPrimitives.pContext[inIndex];

      /* Check whether primitive matches criteria
         In case mask == 0x00u all primitives will be included */
      if (mask == (pSourceOperation->mask & mask))
      {
         /* Pair associated operation and context pointers to configuration */
         pTarget = &pTargetList->pPrimitives[outIndex];

         pTarget->pOperation  = pSourceOperation;
         pTarget->pContext    = pSourceParam;

         outIndex++;
      }
   }

   /* Number of verification primitives matching criteria */
   pTargetList->count = outIndex;
}

/***********************************************************************************************************************
 *  SecM_VerificationWrapper
 **********************************************************************************************************************/
/*! \brief         Performs a verification operation for a given set of verification primitives
 *  \details       Loops all segments present in the verification parameter and passes the information and data to the
 *                 verification primitives given in list.
 *                 Depending on the criteria given in the mask member of the primitive the following operations are
 *                 carried out:
 *                 - Initialization and update with intra-segment data (SEC_UPDATE_OPERATION_DEFAULT - all primitives)
 *                 - Update with inter-segment data (SEC_UPDATE_OPERATION_INTER_SEGMENT)
 *                 - Update with address and length of segments (SEC_UPDATE_OPERATION_ADDRESS_LENGTH)
 *                 - Verification against given signature/checksum (SEC_UPDATE_OPERATION_VERIFICATION)
 *  \pre           Segments in member segmentList of pVerifyParam have to be sorted in ascending order
 *  \param[in]     pVerifyParam Pointer to parameter structure for signature verification
 *  \param[in]     pCfgList Pointer to list of verification primitives
 *  \return        SECM_VER_OK if signature verification successful
 *                 SECM_VER_ERROR if error occured during verification
 *                 SECM_VER_CRC if CRC verification failed
 *                 SECM_VER_SIG if MAC/Signature verification failed
 **********************************************************************************************************************/
/* PRQA S 3673, 6030, 6080 6 */ /* MD_MSR_Rule8.13, MD_MSR_STCYC, MD_MSR_STMIF */
#if defined( SEC_ENABLE_VERIFICATION_WRAPPER )
SecM_StatusType SecM_VerificationWrapper( V_MEMRAM1 SecM_VerifyParamType V_MEMRAM2 V_MEMRAM3 * pVerifyParam,
   const V_MEMRAM1 SecM_VerifyConfigListType V_MEMRAM2 V_MEMRAM3 * pCfgList )
#else
static SecM_StatusType SecM_VerificationWrapper( V_MEMRAM1 SecM_VerifyParamType V_MEMRAM2 V_MEMRAM3 * pVerifyParam,
   const V_MEMRAM1 SecM_VerifyConfigListType V_MEMRAM2 V_MEMRAM3 * pCfgList )
#endif /* SEC_ENABLE_VERIFICATION_WRAPPER */
{
   SecM_StatusType            result;
   /* Context of verification passed to helper function */
   SecM_VerifyContextType     context;    /* PRQA S 0781 */ /* MD_SecVerification_0781 */
   SecM_ByteFastType          index;
   /* Local pointer to segments */
   V_MEMRAM1 FL_SegmentListType V_MEMRAM2 V_MEMRAM3 * pSegmentList; /* PRQA S 3678 */ /* MD_MSR_Rule8.13 */
   /* Pointer to current segment */
   V_MEMRAM1 FL_SegmentInfoType V_MEMRAM2 V_MEMRAM3 * pSegmentInfo; /* PRQA S 3678 */ /* MD_MSR_Rule8.13 */
   /* Pointers to all primitives */
   SecM_VerifyConfigPairType  cfgListAll = {0};
   /* Pointers to primitives executing final verification */
   SecM_VerifyConfigPairType  cfgListVerify = {0};
#if defined( SEC_ENABLE_VERIFICATION_ADDRESS_LENGTH )
   /* Pointers to primitives updated with address and length information */
   SecM_VerifyConfigPairType   cfgListAddr = {0};
#endif /* SEC_ENABLE_VERIFICATION_ADDRESS_LENGTH */
#if defined( SEC_ENABLE_CRC_TOTAL )
   /* Pointers to primitives additionally updated with inter-segment data */
   SecM_VerifyConfigPairType  cfgListInter = {0};
   /* Pointer to primitive list involved in update operation */
   V_MEMRAM1 SecM_VerifyConfigPairType V_MEMRAM2 V_MEMRAM3 * pCfgListUpdate;
   SecM_AddrType              currentAddress;
   SecM_SizeType              remainderLength;
   SecM_SizeType              currentLength;
#endif /* SEC_ENABLE_CRC_TOTAL */

#if defined( SEC_ENABLE_VERIFICATION_WRAPPER )
   result = SECM_VER_ERROR;

   /* Verify list contains any primitives and does not exceed maximum configured count */
   if ((pCfgList->count > 0u) && (pCfgList->count <= SEC_VER_MAX_CONFIG_COUNT))
#endif /* SEC_ENABLE_VERIFICATION_WRAPPER */
   {
      /* Convert list of all primitives into matching format (structure of arrays -> array of structures) */
      SecM_PopulateCfgList(pCfgList, &cfgListAll,     SEC_UPDATE_OPERATION_DEFAULT);

      /* Get all primitives contributing to final verification */
      SecM_PopulateCfgList(pCfgList, &cfgListVerify,  SEC_UPDATE_OPERATION_VERIFICATION);
#if defined( SEC_ENABLE_VERIFICATION_ADDRESS_LENGTH )
      /* Get all primitives updated with address and lenght information of segment */
      SecM_PopulateCfgList(pCfgList, &cfgListAddr,    SEC_UPDATE_OPERATION_ADDRESS_LENGTH);
#endif /* SEC_ENABLE_VERIFICATION_ADDRESS_LENGTH */
#if defined( SEC_ENABLE_CRC_TOTAL )
      /* Get all primitives additionally updated with inter-segment data */
      SecM_PopulateCfgList(pCfgList, &cfgListInter,   SEC_UPDATE_OPERATION_INTER_SEGMENT);
#endif /* SEC_ENABLE_CRC_TOTAL */

      /* Ease the access of segment data by local variable */
      /* According to HIS specification */
      pSegmentList = &pVerifyParam->segmentList;

      /* Setup verification parameter in context
         Uninitialized/unchanged values not relevant for initialization */
      context.sigParam.sigState           = SEC_HASH_INIT;
      context.sigParam.sigByteCount       = 0u; /* sigByteCount is not used for SEC_HASH_INIT */
      context.sigParam.wdTriggerFct       = pVerifyParam->wdTriggerFct;
      context.readMemory                  = pVerifyParam->readMemory;
#if defined( SEC_ENABLE_VERIFICATION_DATA_LENGTH )
      context.sigParam.currentDataLength  = SEC_DATA_LENGTH_NULL;
#endif /* SEC_ENABLE_VERIFICATION_DATA_LENGTH */
      /* Pass external key to verify wrapper */
      context.sigParam.key = pVerifyParam->key;
      /* Pass external workspace to verify wrapper */
      context.sigParam.currentHash.sigResultBuffer  = (SecM_ResultBufferType)pVerifyParam->workspace.data; /* PRQA S 0306 */ /* MD_SecVerification_0306 */
      context.sigParam.currentHash.length           = pVerifyParam->workspace.size;

      /* Initialize all verification primitives */
      result = SecM_VerifyWrapper(&context.sigParam, &cfgListAll);

      if (SECM_VER_OK == result)
      {
#if defined( SEC_ENABLE_CRC_TOTAL )
         /* CRC total option enabled
            Process full block including inter-segment data */
         currentAddress  = pVerifyParam->blockStartAddress;
         remainderLength = pVerifyParam->blockLength;

         /* Check for range overflow */
# if defined( SEC_ENABLE_VERIFICATION_RANGE_CHECK )
         if (SECM_OK == SecM_CheckRangeOverflow(currentAddress, remainderLength))
         {
            /* Invalid memory range */
            result = SECM_VER_ERROR;
         }
         else
# endif /* SEC_ENABLE_VERIFICATION_RANGE_CHECK */
         {
            /* Initialize segment index */
            index = 0u;

            /* Process all bytes of block */
            while (remainderLength > 0u)
            {
               /* Default to inter-segment handling */
               pCfgListUpdate = &cfgListInter;
# if defined( SEC_ENABLE_VERIFICATION_ASSERT_READ_COUNT )
               /* Ignore mismatch of read count and requested length */
               context.readCountMask   = SEC_READ_COUNT_MASK_IGNORE;
               /* Continue operation in case no data was read at all (memory gap) */
               context.readCountResult = SEC_READ_COUNT_RESULT_IGNORE;
# endif /* SEC_ENABLE_VERIFICATION_ASSERT_READ_COUNT */

               /* Still segments left? */
               if (index < pSegmentList->nrOfSegments)
               {
                  /* Get current segment information */
                  pSegmentInfo = &pSegmentList->segmentInfo[index];

                  /* Check whether address lays in front of segment */
                  if (currentAddress < pSegmentInfo->targetAddress)
                  {
                     /* Inter-segment area (gap) or beginning of block
                        Bytes till beginning of next segment */
                     currentLength = pSegmentInfo->targetAddress - currentAddress;
                  }
                  else
                  {
                     /* Intra-segment area
                        Bytes till end of segment */
                     currentLength = pSegmentInfo->length;

                     /* Apply to all verification primitives */
                     pCfgListUpdate = &cfgListAll;
# if defined( SEC_ENABLE_VERIFICATION_ASSERT_READ_COUNT )
                     /* Assert equality of read count and requested length */
                     context.readCountMask   = SEC_READ_COUNT_MASK_ASSERT;
                     /* Abort operation in case read count differs from requested length */
                     context.readCountResult = SEC_READ_COUNT_RESULT_ASSERT;
# endif /* SEC_ENABLE_VERIFICATION_ASSERT_READ_COUNT */

# if defined( SEC_ENABLE_VERIFICATION_ADDRESS_LENGTH )
                     /* Update verification with address and length of segment */
                     result = SecM_UpdateSegmentAddress(&context, &cfgListAddr, pSegmentInfo);
# endif /* SEC_ENABLE_VERIFICATION_ADDRESS_LENGTH */

                     /* Switch to next segment in following iteration */
                     index++;
                  }
               }
               else
               {
                  /* End of block reached */
                  currentLength = remainderLength;
               }

               if (SECM_VER_OK == result)
               {
                  /* Address and length passed in context */
                  context.verifyAddress   = currentAddress;
                  context.remainingBytes  = currentLength;

                  /* Update verification with intra- or inter-segment data */
                  result = SecM_UpdateSegment(&context, pCfgListUpdate);

                  /* Update local address and remainder  */
                  if (currentLength < remainderLength)
                  {
                     remainderLength -= currentLength;
                     currentAddress  += currentLength;
                  }
                  else
                  {
                     /* Segment lies exactly at end or outside of block
                        Prevent integer overflow
                        Address not relevant any more */
                     remainderLength = 0u;
                  }
               }

               /* This is not the else of the if above */
               if (SECM_VER_OK != result)
               {
                  /* Operation failed, abort processing */
                  break;
               }
            }
         }
#else
         /* CRC total option disabled
            Use optimized implementation which only handles inter-segment data
            Loop all segments */
         for (index = 0u; index < pSegmentList->nrOfSegments; index++)
         {
            /* Get current segment information */
            pSegmentInfo = &pSegmentList->segmentInfo[index];

            /* Pass segment information in context */
            context.verifyAddress  = pSegmentInfo->targetAddress;
            context.remainingBytes = pSegmentInfo->length;

# if defined( SEC_ENABLE_VERIFICATION_ADDRESS_LENGTH )
            /* Update verification with address and length of segment */
            result = SecM_UpdateSegmentAddress(&context, &cfgListAddr, pSegmentInfo);

            if (SECM_VER_OK == result)
# endif /* SEC_ENABLE_VERIFICATION_ADDRESS_LENGTH */
            {
               /* Update verification with inter-segment data */
               result = SecM_UpdateSegment(&context, &cfgListAll);
            }

            /* This is not the else of the if above */
            if (SECM_VER_OK != result)
            {
               /* Operation failed, abort processing */
               break;
            }
         }
#endif /* SEC_ENABLE_CRC_TOTAL */
      }

      if (SECM_VER_OK == result)
      {
         /* Finalize calculation */
         context.sigParam.sigState        = SEC_HASH_FINALIZE;

         result = SecM_VerifyWrapper(&context.sigParam, &cfgListAll);

         if (SECM_VER_OK == result)
         {
            /* Finalize verification */
            context.sigParam.sigSourceBuffer = pVerifyParam->verificationData;
            context.sigParam.sigState        = SEC_SIG_VERIFY;

            result = SecM_VerifyWrapper(&context.sigParam, &cfgListVerify);
         }
      }
   }

   return result;
}

#if defined( SEC_ENABLE_VERIFY_HASH )
/***********************************************************************************************************************
 *  SecM_CopyDigest
 **********************************************************************************************************************/
/*! \brief         Copy calculated messages digest into provided buffer
 *  \details       Output buffer has to be large enough to hold message digest
 *  \param[in]     pCalculatedData Pointer to calculated message digest
 *  \param[in]     calculatedSize Size of calculated message digest
 *  \param[in]     pOutputData Pointer to output buffer
 *  \param[in]     outputSize Size of output buffer
 *  \return        SECM_VER_OK if operation successful
 *                 SECM_VER_ERROR if output size insufficient
 **********************************************************************************************************************/
static SecM_StatusType SecM_CopyDigest( SecM_ConstRamDataType pCalculatedData, SecM_LengthType calculatedSize,
   SecM_RamDataType pOutputData, SecM_LengthType outputSize )
{
   SecM_StatusType result;

   result = SECM_VER_ERROR;

   /* Provided buffer has to be large enough to hold digest */
   if (outputSize >= calculatedSize)
   {
      /* Copy into provided buffer */
      SecM_CopyBuffer(pCalculatedData, pOutputData, calculatedSize);

      result = SECM_VER_OK;
   }

   return result;
}

/**********************************************************************************************************************
 *  SecM_CompareDigest
 *********************************************************************************************************************/
/*! \brief         Compare calculated messages digest against provided one
 *  \details       Digests have to be of same size, byte-wise comparison performed
 *  \param[in]     pCalculatedData Pointer to calculated message digest
 *  \param[in]     calculatedSize Size of calculated message digest
 *  \param[in]     pProvidedData Pointer to provided message digest
 *  \param[in]     providedSize Size of provided message digest
 *  \return        SECM_VER_OK if digest values match
 *                 SECM_VER_ERROR if digest have differing size
 *                 SECM_VER_SIG if digest values differ
 *********************************************************************************************************************/
static SecM_StatusType SecM_CompareDigest( SecM_ConstRamDataType pCalculatedData, SecM_LengthType calculatedSize,
   SecM_ConstRamDataType pProvidedData, SecM_LengthType providedSize )
{
   SecM_StatusType result;
   SecM_LengthType index;
   SecM_ByteType   accumulated;

   result = SECM_VER_ERROR;

   /* Sizes have to be equal for a match */
   if (calculatedSize == providedSize)
   {
      accumulated = 0u;

      /* Compare all bytes */
      for (index = 0u; index < calculatedSize; index++)
      {
         accumulated |= pCalculatedData[index] ^ pProvidedData[index];
      }

      if (accumulated == 0u)
      {
         /* Values match */
         result = SECM_VER_OK;
      }
      else
      {
         /* Values differ, report error */
         result = SECM_VER_SIG;
      }
   }

   return result;
}
#endif /* SEC_ENABLE_VERIFY_HASH */

#if defined( SEC_ENABLE_VERIFY_CRC )
/**********************************************************************************************************************
 *  SecM_CopyCrcParam
 *********************************************************************************************************************/
/*! \brief         Copies the CRC parameters to the specific CRC structure
 *  \param[in]     pVerifyParam Pointer to parameter structure for signature verification
 *                   Member currentHash must contain reference to buffer used as workspace
 *                   (size at least equal pPrimitive->common.workspaceSize)
 *  \param[in]     crcAction New CRC state
 *  \param[in]     pPrimitive Pointer to parameter structure for hash primitive
 *  \return        SECM_OK if copy operation was successful
 *                 SECM_NOT_OK otherwise
 *********************************************************************************************************************/
/* PRQA S 3673 1 */ /* MD_MSR_Rule8.13 */
static SecM_StatusType SecM_CopyCrcParam( V_MEMRAM1 SecM_SignatureParamType V_MEMRAM2 V_MEMRAM3 * pVerifyParam,
   SecM_ByteType crcAction, V_MEMROM1 SecM_CrcPrimitiveType V_MEMROM2 V_MEMROM3 * pPrimitive )
{
   SecM_StatusType result = SECM_NOT_OK;

   if (pPrimitive->crcType == SEC_CRC16)
   {
      if (pVerifyParam->currentHash.length == sizeof(SecM_CRC16ParamType))
      {
         /* Cast CRC param structure to CRC16 specific and copy data */ /* PRQA S 0306 1 */ /* MD_SecVerification_0306 */
         SecM_CRC16ParamType * pCrcParam = (SecM_CRC16ParamType*)pVerifyParam->currentHash.sigResultBuffer;
         pCrcParam->crcByteCount = pVerifyParam->sigByteCount;
         pCrcParam->crcSourceBuffer = pVerifyParam->sigSourceBuffer;
         pCrcParam->crcOutputBuffer = pVerifyParam->sigSourceBuffer;
         pCrcParam->wdTriggerFct = pVerifyParam->wdTriggerFct;
         pCrcParam->crcState = crcAction;
         result = SECM_OK;
      }
   }
   else if (pPrimitive->crcType == SEC_CRC32)
   {
      if (pVerifyParam->currentHash.length == sizeof(SecM_CRC32ParamType))
      {
         /* Cast CRC param structure to CRC32 specific and copy data */ /* PRQA S 0306 1 */ /* MD_SecVerification_0306 */
         SecM_CRC32ParamType * pCrcParam = (SecM_CRC32ParamType*)pVerifyParam->currentHash.sigResultBuffer;
         pCrcParam->crcByteCount = pVerifyParam->sigByteCount;
         pCrcParam->crcSourceBuffer = pVerifyParam->sigSourceBuffer;
         pCrcParam->crcOutputBuffer = pVerifyParam->sigSourceBuffer;
         pCrcParam->wdTriggerFct = pVerifyParam->wdTriggerFct;
         pCrcParam->crcState = crcAction;
         result = SECM_OK;
      }
   }
   else if (pPrimitive->crcType == SEC_CRC64)
   {
      if (pVerifyParam->currentHash.length == sizeof(SecM_CRC64ParamType))
      {
         /* Cast CRC param structure to CRC64 specific and copy data */ /* PRQA S 0306 1 */ /* MD_SecVerification_0306 */
         SecM_CRC64ParamType * pCrcParam = (SecM_CRC64ParamType*)pVerifyParam->currentHash.sigResultBuffer;
         pCrcParam->crcByteCount = pVerifyParam->sigByteCount;
         pCrcParam->crcSourceBuffer = pVerifyParam->sigSourceBuffer;
         pCrcParam->crcOutputBuffer = pVerifyParam->sigSourceBuffer;
         pCrcParam->wdTriggerFct = pVerifyParam->wdTriggerFct;
         pCrcParam->crcState = crcAction;
         result = SECM_OK;
      }
   }
   else
   {
      /* Unknown CRC type */
   }

   return result;
}
#endif /* SEC_ENABLE_VERIFY_CRC */

# if defined( SEC_ENABLE_VERIFY_MAC_CONTEXT_HANDLING ) || \
     defined( SEC_ENABLE_VERIFY_SIGNATURE_CONTEXT_HANDLING )
/**********************************************************************************************************************
 *  SecM_VerifyContextHandling
 *********************************************************************************************************************/
/*! \brief         Handling store and restore of the context for verification
 *  \details       See SecM_VerifySignature for details
 *  \param[in]     jobId id of the Smh Job
 *  \param[in]     ctxBuffSize Size of the context buffer
 *  \param[in,out] pSize Pointer to the current stored context size
 *  \param[in]     pData Pointer to the context buffer
 *  \return        SECM_VER_OK if context storage or resume was successful
 *                 SECM_VER_ERROR if context storage or resume was not successful
 *********************************************************************************************************************/
static SecM_StatusType SecM_VerifyContextHandling( SecM_WordType jobId, SecM_WordType ctxBuffSize, SecM_WordType *pSize, SecM_ByteType *pData )
{
   SecM_StatusType result = SECM_VER_OK;

   if (*pSize == 0u)
   {
      *pSize = ctxBuffSize;
#if defined ( SEC_ENABLE_CSM )
      if (Csm_SaveContextJob(SecM_JobInfo[jobId].csmJobId, pData, pSize) != E_OK)
#endif
      {
         result = SECM_VER_ERROR;
      }
   }
   else
   {
#if defined ( SEC_ENABLE_CSM )
      if (Csm_RestoreContextJob(SecM_JobInfo[jobId].csmJobId, pData, *pSize) != E_OK)
#endif
      {
         result = SECM_VER_ERROR;
      }
   }

   return result;
}
#endif /* SEC_ENABLE_VERIFY_MAC_CONTEXT_HANDLING || SEC_ENABLE_VERIFY_SIGNATURE_CONTEXT_HANDLING */

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/

/***********************************************************************************************************************
 *  SecM_InitPowerOnVerification
 **********************************************************************************************************************/
 /*! \brief         Initialize Verification module
 **********************************************************************************************************************/
void SecM_InitPowerOnVerification(void)
{
#if defined( SEC_ENABLE_VERIFY_MAC_CONTEXT_HANDLING ) || \
    defined( SEC_ENABLE_VERIFY_SIGNATURE_CONTEXT_HANDLING )
   SecM_WordType idx;
#endif

#if defined( SEC_ENABLE_VERIFY_MAC_CONTEXT_HANDLING )
   for (idx = 0; idx < SecM_GetSizeOfMacPrimitives(); idx++)
   {
      if (SecM_MacPrimitives[idx].pVerWks != V_NULL)
      {
         SecM_MacPrimitives[idx].pVerWks->data = SecM_MacPrimitivesContextBuffs[idx];
         SecM_MacPrimitives[idx].pVerWks->size = 0u;
      }
   }
#endif

#if defined( SEC_ENABLE_VERIFY_SIGNATURE_CONTEXT_HANDLING )
   for (idx = 0; idx < SecM_GetSizeOfSignaturePrimitives(); idx++)
   {
      if (SecM_SignaturePrimitives[idx].pVerWks != V_NULL)
      {
         SecM_SignaturePrimitives[idx].pVerWks->data = SecM_SignaturePrimitivesContextBuffs[idx];
         SecM_SignaturePrimitives[idx].pVerWks->size = 0u;
      }
   }
#endif
}

/***********************************************************************************************************************
 *  SecM_VerificationBase
 **********************************************************************************************************************/
/*! \brief         Calculate and verify checksum or signature using passed primitive
 *  \details       Beside the passed base operation, auxiliary operations are included (if configured) in the
 *                 following order:
 *                 - CRC total
 *                 - Vendor specific checksum
 *                 - CRC written
 *                 - ...
 *                 Additional details see SecM_Verification
 *  \param[in]     pVerifyParam Pointer to parameter structure for signature verification
 *  \param[in]     pCfgList Pointer to list of verification primitives
 *  \return        SECM_VER_OK if signature verification successful
 *                 SECM_VER_ERROR if error occured during verification
 *                 SECM_VER_CRC if CRC verification failed
 *                 SECM_VER_SIG if MAC/Signature verification failed
 **********************************************************************************************************************/
SecM_StatusType SecM_VerificationBase( V_MEMRAM1 SecM_VerifyParamType V_MEMRAM2 V_MEMRAM3 * pVerifyParam,
   const V_MEMRAM1 SecM_VerifyConfigListType V_MEMRAM2 V_MEMRAM3 * pCfgList )
{
   SecM_StatusType   result;
   V_MEMRAM1 SecM_SignatureParamType V_MEMRAM2 V_MEMRAM3 * pVerifyContext;
#if defined( SEC_ENABLE_CRC_TOTAL ) || \
    defined( SEC_ENABLE_CRC_WRITTEN )
   SecM_ByteFastType index;
   SecM_ByteFastType cfgCount;
#endif /* SEC_ENABLE_CRC_TOTAL || SEC_ENABLE_CRC_WRITTEN */
#if defined( SEC_ENABLE_CRC_TOTAL )
   SecM_CRCParamType crcTotalParam;
#endif /* SEC_ENABLE_CRC_TOTAL */
#if defined( SEC_ENABLE_CRC_WRITTEN )
   SecM_CRCParamType crcWrittenParam; /* PRQA S 3196 */ /* MD_SecVerification_3196 */
#endif /* SEC_ENABLE_CRC_WRITTEN */

   pVerifyContext = pCfgList->pPrimitives.pContext;

   /* Use default workspace, data length not relevant */
   pVerifyContext[0u].currentHash.sigResultBuffer  = (SecM_ResultBufferType)SEC_DEFAULT_WORKSPACE; /* PRQA S 0306 */ /* MD_SecVerification_0306 */
   pVerifyContext[0u].currentHash.length           = SEC_DEFAULT_WORKSPACE_SIZE;
#if defined( SEC_ENABLE_VERIFICATION_DATA_LENGTH )
   pVerifyContext[0u].currentDataLength            = SEC_DATA_LENGTH_NULL;
#endif /* SEC_ENABLE_VERIFICATION_DATA_LENGTH */

#if defined( SEC_ENABLE_CRC_TOTAL ) || \
    defined( SEC_ENABLE_CRC_WRITTEN )
   cfgCount       = pCfgList->count;

   /* Start with entry after primary primitive */
   index          = 1u;
#endif /* SEC_ENABLE_CRC_TOTAL || SEC_ENABLE_CRC_WRITTEN */

#if defined( SEC_ENABLE_CRC_TOTAL )
   /* Initialize CRC total value to prevent compiler confusion */
   crcTotalParam.currentCRC = crcZeroValue;

   /* Entry for CRC total included in configuration list? */
   if (index < cfgCount)
   {
      /* Use local variable as workspace */
      pVerifyContext[index].currentHash.sigResultBuffer  = (SecM_ResultBufferType)&crcTotalParam;  /* PRQA S 0306 */ /* MD_SecVerification_0306 */
      pVerifyContext[index].currentHash.length           = sizeof(SecM_CRCParamType);
# if defined( SEC_ENABLE_VERIFICATION_DATA_LENGTH )
      pVerifyContext[index].currentDataLength            = SEC_DATA_LENGTH_NULL;
# endif /* SEC_ENABLE_VERIFICATION_DATA_LENGTH */

# if defined( SEC_ENABLE_CRC_WRITTEN )
      /* Continue with next entry */
      index++;
# endif /* SEC_ENABLE_CRC_WRITTEN */
   }
#endif /* SEC_ENABLE_CRC_TOTAL */

#if defined( SEC_ENABLE_CRC_WRITTEN )
# if defined( SEC_ENABLE_VENDOR_CHECKSUM )
   /* Skip entry of vendor specific checksum */
   index++;
# endif /* SEC_ENABLE_VENDOR_CHECKSUM */

   /* Entry for CRC written included in configuration list? */
   if (index < cfgCount)
   {
      /* Use local variable as workspace */
      pVerifyContext[index].currentHash.sigResultBuffer  = (SecM_ResultBufferType)&crcWrittenParam;   /* PRQA S 0306 */ /* MD_SecVerification_0306 */
      pVerifyContext[index].currentHash.length           = sizeof(SecM_CRCParamType);
# if defined( SEC_ENABLE_VERIFICATION_DATA_LENGTH )
      pVerifyContext[index].currentDataLength            = SEC_DATA_LENGTH_NULL;
# endif /* SEC_ENABLE_VERIFICATION_DATA_LENGTH */
   }
#endif /* SEC_ENABLE_CRC_WRITTEN */

   /* Perform verification with configuration list */
   result = SecM_VerificationWrapper(pVerifyParam, pCfgList);
#if defined( SEC_ENABLE_CRC )
# if defined( SEC_ENABLE_CRC_TOTAL )
   /* Store calculated CRC total */
   pVerifyParam->crcTotal = crcTotalParam.currentCRC;
# else
   pVerifyParam->crcTotal = crcZeroValue;
# endif /* SEC_ENABLE_CRC_TOTAL */
#endif /* SEC_ENABLE_CRC */
   return result;
}

#if defined( SEC_ENABLE_VERIFICATION_DATA_LENGTH )
/***********************************************************************************************************************
 *  SecM_UpdateDataLength
 **********************************************************************************************************************/
/*! \brief         Update data length of signature parameter
 *  \param[in]     pVerifyParam Pointer to parameter structure for signature verification
 **********************************************************************************************************************/
/* PRQA S 3673 1 */ /* MD_MSR_Rule8.13 */
void SecM_UpdateDataLength( V_MEMRAM1 SecM_SignatureParamType V_MEMRAM2 V_MEMRAM3 * pVerifyParam )
{
   SecM_SizeType dataLength;

   /* Disable update if not available (NULL pointer) */
   if (SEC_DATA_LENGTH_NULL != pVerifyParam->currentDataLength)
   {
      /* Load current value into local variable */
      dataLength = *(pVerifyParam->currentDataLength);

      switch (pVerifyParam->sigState)
      {
         case SEC_HASH_INIT:
         {
            /* Reset processed data length */
            dataLength = 0u;

            break;
         }
         case SEC_HASH_COMPUTE:
         {
            /* Update processed data length (temporarily holding byte count) */
            dataLength += pVerifyParam->sigByteCount;

            break;
         }
         case SEC_HASH_FINALIZE:
         {
            /* Data length expected in multiples of 64 byte */
            dataLength >>= 6u;

            break;
         }
         case SEC_SIG_VERIFY:
         default:
         {
            /* Nothing to do */
            break;
         }
      }

      /* Store possibly modified value */
      *(pVerifyParam->currentDataLength) = dataLength;
   }
}
#endif /* SEC_ENABLE_VERIFICATION_DATA_LENGTH */

/***********************************************************************************************************************
 *  SecM_InitVerification
 **********************************************************************************************************************/
/*! \brief         Intializes the verification
 *  \param[in]     init Dummy pointer (currently not used)
 *  \return        SECM_OK if initalization successful
 *                 SECM_NOT_OK if error occured during initalization
 **********************************************************************************************************************/
SecM_StatusType SecM_InitVerification( SecM_VerifyInitType init )
{
# if defined( V_ENABLE_USE_DUMMY_STATEMENT )
   /* Parameters not used: avoid compiler warning */ /* PRQA S 3112 1 */ /* MD_MSR_DummyStmt */
   (void)init;
# endif /* V_ENABLE_USE_DUMMY_STATEMENT */

   return SECM_OK;
}

/***********************************************************************************************************************
 *  SecM_DeinitVerification
 **********************************************************************************************************************/
/*! \brief         Deintializes the verification
 *  \param[in]     deinit Dummy pointer (currently not used)
 *  \return        SECM_OK if deinitalization successful
 *                 SECM_NOT_OK if error occured during deinitalization
 **********************************************************************************************************************/
SecM_StatusType SecM_DeinitVerification( SecM_VerifyDeinitType deinit )
{
# if defined( V_ENABLE_USE_DUMMY_STATEMENT )
   /* Parameters not used: avoid compiler warning */ /* PRQA S 3112 1 */ /* MD_MSR_DummyStmt */
   (void)deinit;
# endif /* V_ENABLE_USE_DUMMY_STATEMENT */

   return SECM_OK;
}

#if defined( SEC_ENABLE_CRC_TOTAL ) || \
    defined( SEC_ENABLE_CRC_WRITTEN )
/**********************************************************************************************************************
 *  SecM_VerifyChecksumCrc
 *********************************************************************************************************************/
/*! \brief         Calculate and verify CRC checksum
 *  \details       See SecM_VerifySignature for details
 *  \param[in]     pVerifyParam Pointer to parameter structure for signature verification
 *                   Member currentHash must contain reference to SecM_CRCParamType or aligned buffer of equal size
 *                   used as workspace
 *  \return        SECM_VER_OK if verification operation successful
 *                 SECM_VER_ERROR if error occured during verification
 *                 SECM_VER_CRC if CRC verification failed
 *                 SECM_VER_SIG if MAC/Signature verification failed
 *********************************************************************************************************************/
/* PRQA S 3673 1 */ /* MD_MSR_Rule8.13 */
SecM_StatusType SecM_VerifyChecksumCrc( V_MEMRAM1 SecM_SignatureParamType V_MEMRAM2 V_MEMRAM3 * pVerifyParam )
{
   SecM_StatusType result;
   V_MEMRAM1 SecM_CRCParamType V_MEMRAM2 V_MEMRAM3 * pCrcParam;
   SecM_ByteType  crcAction;

   result      = SECM_VER_ERROR;
   crcAction   = SEC_CRC_NONE;

   /* Member currentHash must contain reference to SecM_CRCParamType used as workspace
      Check length requirements */
   if (pVerifyParam->currentHash.length >= sizeof(SecM_CRCParamType))
   {
      /* Store workspace pointer for easier access */
      pCrcParam = (V_MEMRAM1 SecM_CRCParamType V_MEMRAM2 V_MEMRAM3 *)(pVerifyParam->currentHash.sigResultBuffer); /* PRQA S 0306 */ /* MD_SecVerification_0306 */

      /* Map signature operation to matching CRC counterpart */
      switch (pVerifyParam->sigState)
      {
         case SEC_HASH_INIT:
         {
            /* Initialize CRC */
            crcAction = SEC_CRC_INIT;

            break;
         }
         case SEC_HASH_COMPUTE:
         {
            /* Update CRC using data passed in source buffer */
            crcAction = SEC_CRC_COMPUTE;

            break;
         }
         case SEC_HASH_FINALIZE:
         {
            /* Finalize CRC */
            crcAction = SEC_CRC_FINALIZE;

            break;
         }
         case SEC_SIG_VERIFY:
         {
# if defined( SEC_ENABLE_CRC_WRITTEN_GET )
            /* Actual verification is performed externally using calculated value
               Convert CRC into big-endian byte array and store in provided buffer */
            pCrcParam->crcOutputBuffer = pVerifyParam->sigSourceBuffer;
            crcAction = SEC_CRC_GET;
# else
            /* Passed data has to be large enough to hold CRC value */
            if (pVerifyParam->sigByteCount >= SEC_SIZE_CHECKSUM_CRC)
            {
               /* Compare given CRC against calculated one */
               crcAction = SEC_CRC_VERIFY;
            }
# endif /* SEC_ENABLE_CRC_WRITTEN_GET */
            break;
         }
         default:
         {
            /* Unknown state - result already set */
            break;
         }
      }

      if (SEC_CRC_NONE != crcAction)
      {
         /* Copy given parameters to CRC parameter */
         pCrcParam->crcByteCount    = pVerifyParam->sigByteCount;
         pCrcParam->crcSourceBuffer = pVerifyParam->sigSourceBuffer;
         pCrcParam->wdTriggerFct    = pVerifyParam->wdTriggerFct;
         pCrcParam->crcState        = crcAction;

         result = SecM_ComputeCRC(pCrcParam);
      }
   }

   return result;
}
#endif /* SEC_ENABLE_CRC_TOTAL || SEC_ENABLE_CRC_WRITTEN */

#if defined( SEC_ENABLE_VERIFY_CRC )
/***********************************************************************************************************************
 *  SecM_VerifyCrc
 **********************************************************************************************************************/
/*! \brief         Calculate and verify CRC using given CRC algorithm
 *  \details       See SecM_VerifySignature for details
 *  \param[in]     pVerifyParam Pointer to parameter structure for signature verification
 *                   Member currentHash must contain reference to SecM_CRCParamType or aligned buffer of equal size
 *                   used as workspace
 *  \param[in]     primitiveId ID of the CRC primitive
 *  \return        SECM_VER_OK if verification operation successful
 *                 SECM_VER_ERROR if error occured during verification
 *                 SECM_VER_CRC if CRC verification failed
 **********************************************************************************************************************/
/* PRQA S 6030, 6080 1 */ /* MD_MSR_STCYC, MD_MSR_STMIF */
SecM_StatusType SecM_VerifyCrc( V_MEMRAM1 SecM_SignatureParamType V_MEMRAM2 V_MEMRAM3 * pVerifyParam, SecM_WordType primitiveId )
{
   SecM_StatusType result;
   V_MEMROM1 SecM_CrcPrimitiveType V_MEMROM2 V_MEMROM3 * pPrimitive;
   SecM_ByteType  crcAction;

   result = SECM_VER_ERROR;

   if (primitiveId < SecM_GetSizeOfCrcPrimitives())
   {
      pPrimitive = &SecM_CrcPrimitives[primitiveId];
      crcAction = SEC_CRC_NONE;

# if defined( SEC_ENABLE_VERIFICATION_DATA_LENGTH )
      if (pPrimitive->updateVerifiedData == TRUE)
      {
         /* Update member currentDataLength of verification parameter */
         SecM_UpdateDataLength(pVerifyParam);
      }
# endif /* SEC_ENABLE_VERIFICATION_DATA_LENGTH */

      /* Map signature operation to matching CRC counterpart */
      switch (pVerifyParam->sigState)
      {
         case SEC_HASH_INIT:
         {
            /* Initialize CRC */
            crcAction = SEC_CRC_INIT;

            break;
         }
         case SEC_HASH_COMPUTE:
         {
            /* Update CRC using data passed in source buffer */
            crcAction = SEC_CRC_COMPUTE;

            break;
         }
         case SEC_HASH_FINALIZE:
         {
            /* Finalize CRC */
            crcAction = SEC_CRC_FINALIZE;

            break;
         }
         case SEC_SIG_VERIFY:
         {
            /* Passed data has to be large enough to hold CRC value */
            if (pVerifyParam->sigByteCount >= pPrimitive->crcSize)
            {
               if (pPrimitive->computationOnly == TRUE)
               {
                  /* Computation is only possible for configured default CRC */
                  if (pPrimitive->crcType == SEC_CRC_TYPE)
                  {
                     /* Actual verification is performed externally using calculated value
                        Convert CRC into big-endian byte array and store in provided buffer */
                     crcAction = SEC_CRC_GET;
                  }
               }
               else
               {
                  /* Compare given CRC against calculated one */
                  crcAction = SEC_CRC_VERIFY;
               }
            }

            break;
         }
         default:
         {
            /* Unknown state - result already set */
            break;
         }
      }

      if (SEC_CRC_NONE != crcAction)
      {
         /* Copy given parameters to CRC parameter */
         if (SecM_CopyCrcParam(pVerifyParam, crcAction, pPrimitive) == SECM_OK)
         {
            /* PRQA S 0326 1 */ /* MD_SecVerification_0326 */
            result = pPrimitive->pCrcFunc((void*)pVerifyParam->currentHash.sigResultBuffer);
         }
      }
   }

   return result;
}
#endif /* SEC_ENABLE_VERIFY_CRC */

#if defined( SEC_ENABLE_VERIFY_HASH )
/**********************************************************************************************************************
 *  SecM_VerifyHash
 *********************************************************************************************************************/
/*! \brief         Calculate and verify hash using given hash algorithm
 *  \details       See SecM_VerifySignature for details
 *  \param[in]     pVerifyParam Pointer to parameter structure for signature verification
 *  \param[in]     primitiveId ID of the hash primitive
 *  \return        SECM_VER_OK if verification operation successful
 *                 SECM_VER_ERROR if error occured during verification
 *                 SECM_VER_CRC if CRC verification failed
 *                 SECM_VER_SIG if MAC/Signature verification failed
 *********************************************************************************************************************/
SecM_StatusType SecM_VerifyHash( V_MEMRAM1 SecM_SignatureParamType V_MEMRAM2 V_MEMRAM3 * pVerifyParam, SecM_WordType primitiveId )
{
   SecM_StatusType result;
   V_MEMROM1 SecM_HashPrimitiveType V_MEMROM2 V_MEMROM3 * pPrimitive;

   result = SECM_VER_ERROR;

   if (primitiveId < SecM_GetSizeOfHashPrimitives())
   {
      pPrimitive = &SecM_HashPrimitives[primitiveId];

# if defined( SEC_ENABLE_VERIFICATION_DATA_LENGTH )
      if (pPrimitive->updateVerifiedData == TRUE)
      {
         /* Update member currentDataLength of verification parameter */
         SecM_UpdateDataLength(pVerifyParam);
      }
# endif /* SEC_ENABLE_VERIFICATION_DATA_LENGTH */

      switch (pVerifyParam->sigState)
      {
         case SEC_HASH_INIT:
         {
            /* Init verification */
            result = SecM_HashJob(pPrimitive->jobId, SECM_OPERATIONMODE_START, NULL_PTR, 0, NULL_PTR, NULL_PTR);

            break;
         }
         case SEC_HASH_COMPUTE:
         {
            /* Update verification with data in buffer */
            result = SecM_HashJob(pPrimitive->jobId, SECM_OPERATIONMODE_UPDATE, pVerifyParam->sigSourceBuffer,
               pVerifyParam->sigByteCount, NULL_PTR, NULL_PTR);

            break;
         }
         case SEC_HASH_FINALIZE:
         {
            uint32 hashResultLength = pPrimitive->digestLength;
            /* Finalize verification
               Remark: Digest value located at very beginning of workspace */
            if (SecM_HashJob(pPrimitive->jobId, SECM_OPERATIONMODE_FINISH, NULL_PTR, 0u, pPrimitive->digest,
               &hashResultLength) == SECM_OK)
            {
               /* Check if the resulting length is as expected */
               if (hashResultLength == pPrimitive->digestLength)
               {
                  result = SECM_VER_OK;
               }
            }

            break;
         }
         case SEC_SIG_VERIFY:
         {
            if (pPrimitive->computationOnly == TRUE)
            {
               /* Actual verification is performed externally using calculated value
                  Copy digest into provided buffer
                  Remark: Digest value located at very beginning of workspace */
               result = SecM_CopyDigest(pPrimitive->digest, pPrimitive->digestLength, pVerifyParam->sigSourceBuffer,
                  pVerifyParam->sigByteCount);
               /* Overwrite with hash actual size */
               pVerifyParam->sigByteCount = pPrimitive->digestLength;
            }
            else
            {
               /* Finalize verification by comparing calculated and provided digest
                  Remark: Digest value located at very beginning of workspace */
               result = SecM_CompareDigest(pPrimitive->digest, pPrimitive->digestLength,
                  pVerifyParam->sigSourceBuffer, pVerifyParam->sigByteCount);
            }

            break;
         }
         default:
         {
            /* Unknown state - result already set */
            break;
         }
      }
   }

   return result;
}
#endif /* SEC_ENABLE_VERIFY_HASH */

#if defined( SEC_ENABLE_VERIFY_MAC )
/**********************************************************************************************************************
 *  SecM_VerifyMac
 *********************************************************************************************************************/
/*! \brief         Calculate and verify MAC using given hash algorithm
 *  \details       See SecM_VerifySignature for details
 *  \param[in]     pVerifyParam Pointer to parameter structure for signature verification
 *  \param[in]     primitiveId ID of the MAC primitive
 *  \return        SECM_VER_OK if verification operation successful
 *                 SECM_VER_ERROR if error occured during verification
 *                 SECM_VER_CRC if CRC verification failed
 *                 SECM_VER_SIG if MAC/Signature verification failed
 *********************************************************************************************************************/
/* PRQA S 3673, 6030 1 */  /* MD_MSR_Rule8.13, MD_MSR_STCYC */
SecM_StatusType SecM_VerifyMac( V_MEMRAM1 SecM_SignatureParamType V_MEMRAM2 V_MEMRAM3 * pVerifyParam, SecM_WordType primitiveId )
{
   SecM_StatusType result;
   V_MEMROM1 SecM_MacPrimitiveType V_MEMROM2 V_MEMROM3 * pPrimitive;

   result = SECM_VER_ERROR;

   if (primitiveId < SecM_GetSizeOfMacPrimitives())
   {
      pPrimitive = &SecM_MacPrimitives[primitiveId];

# if defined( SEC_ENABLE_VERIFICATION_DATA_LENGTH )
      if (pPrimitive->updateVerifiedData == TRUE)
      {
         /* Update member currentDataLength of verification parameter */
         SecM_UpdateDataLength(pVerifyParam);
      }
# endif /* SEC_ENABLE_VERIFICATION_DATA_LENGTH */

      switch (pVerifyParam->sigState)
      {
         case SEC_HASH_INIT:
         {
# if defined( SEC_ENABLE_VERIFY_MAC_CONTEXT_HANDLING )
            if (pPrimitive->pVerWks != V_NULL)
            {
               /* Clear the context of the previous operation */
               pPrimitive->pVerWks->size = 0u;
            }
# endif
            if (pPrimitive->computationOnly == TRUE)
            {
# if defined( SEC_ENABLE_JOB_MACGENERATE )
               /* Init generation */
               result = SecM_MacGenerateJob(pPrimitive->jobId, SECM_OPERATIONMODE_START, pVerifyParam->key,
                  NULL_PTR, 0u, NULL_PTR, NULL_PTR);
# endif /* SEC_ENABLE_JOB_MACGENERATE */
            }
            else
            {
# if defined( SEC_ENABLE_JOB_MACVERIFY )
               /* Init verification */
               result = SecM_MacVerifyJob(pPrimitive->jobId, SECM_OPERATIONMODE_START, pVerifyParam->key,
                  NULL_PTR, 0u, NULL_PTR, 0u);
# endif /* SEC_ENABLE_JOB_MACVERIFY */
            }

            break;
         }
         case SEC_HASH_COMPUTE:
         {
            if (pPrimitive->computationOnly == TRUE)
            {
# if defined( SEC_ENABLE_JOB_MACGENERATE )
               /* Update generation with data in buffer */
               result = SecM_MacGenerateJob(pPrimitive->jobId, SECM_OPERATIONMODE_UPDATE, NULL_PTR, pVerifyParam->sigSourceBuffer,
                  pVerifyParam->sigByteCount, NULL_PTR, NULL_PTR);
# endif /* SEC_ENABLE_JOB_MACGENERATE */
            }
            else
            {
# if defined( SEC_ENABLE_JOB_MACVERIFY )
               /* Update verification with data in buffer */
               result = SecM_MacVerifyJob(pPrimitive->jobId, SECM_OPERATIONMODE_UPDATE, NULL_PTR, pVerifyParam->sigSourceBuffer,
                  pVerifyParam->sigByteCount, NULL_PTR, 0u);
# endif /* SEC_ENABLE_JOB_MACVERIFY */
            }

            break;
         }
         case SEC_HASH_FINALIZE:
         {
            /* No explicit finalization step - implicitely done in verification step */
            result = SECM_VER_OK;

            break;
         }
         case SEC_SIG_VERIFY:
         {
            SecM_StatusType ctxResult = SECM_VER_OK;

# if defined( SEC_ENABLE_VERIFY_MAC_CONTEXT_HANDLING )
            if (pPrimitive->pVerWks != V_NULL)
            {
               ctxResult = SecM_VerifyContextHandling(pPrimitive->jobId, pPrimitive->contextBufferSize, &(pPrimitive->pVerWks->size), pPrimitive->pVerWks->data);
            }
# endif
            /* PRQA S 2991, 2995 1 */ /* MD_SecVerification_2991_2992_2995_2996 */
            if (ctxResult == SECM_VER_OK)
            {
               if (pPrimitive->computationOnly == TRUE)
               {
# if defined( SEC_ENABLE_JOB_MACGENERATE )
                  SecM_WordType macResultLength = pVerifyParam->sigByteCount;

                  /* Finalize generation
                   * Actual verification is performed externally using calculated value
                   * Copy digest into provided buffer
                   */
                  result = SecM_MacGenerateJob(pPrimitive->jobId, SECM_OPERATIONMODE_FINISH, NULL_PTR, NULL_PTR, 0,
                     pVerifyParam->sigSourceBuffer, &macResultLength);

                  /* Overwrite with hash actual size */
                  pVerifyParam->sigByteCount = (SecM_LengthType)macResultLength;
# endif /* SEC_ENABLE_JOB_MACGENERATE */
               }
               else
               {
# if defined( SEC_ENABLE_JOB_MACVERIFY )
                  result = SecM_MacVerifyJob(pPrimitive->jobId, SECM_OPERATIONMODE_FINISH, NULL_PTR, NULL_PTR, 0u, pVerifyParam->sigSourceBuffer,
                     pVerifyParam->sigByteCount);
# endif /* SEC_ENABLE_JOB_MACVERIFY */
               }
            }

            break;
         }
         default:
         {
            /* Unknown state - result already set */
            break;
         }
      }
   }

   return result;
}
#endif /* SEC_ENABLE_VERIFY_MAC */

#if defined( SEC_ENABLE_VERIFY_SIGNATURE )
/**********************************************************************************************************************
 *  SecM_VerifySig
 *********************************************************************************************************************/
/*! \brief         Calculate and verify signature using given hash algorithm
 *  \details       See SecM_VerifySignature for details
 *  \param[in]     pVerifyParam Pointer to parameter structure for signature verification
 *  \param[in]     primitiveId ID of the signature primitive
 *  \return        SECM_VER_OK if verification operation successful
 *                 SECM_VER_ERROR if error occured during verification
 *                 SECM_VER_CRC if CRC verification failed
 *                 SECM_VER_SIG if MAC/Signature verification failed
 *********************************************************************************************************************/
/* PRQA S 3673, 6030, 6080 1 */ /* MD_MSR_Rule8.13, MD_MSR_STCYC, MD_MSR_STMIF */
SecM_StatusType SecM_VerifySig( V_MEMRAM1 SecM_SignatureParamType V_MEMRAM2 V_MEMRAM3 * pVerifyParam, SecM_WordType primitiveId )
{
   SecM_StatusType result;
   V_MEMROM1 SecM_SigPrimitiveType V_MEMROM2 V_MEMROM3 * pPrimitive;

   result = SECM_VER_ERROR;

   if (primitiveId < SecM_GetSizeOfSignaturePrimitives())
   {
      pPrimitive = &SecM_SignaturePrimitives[primitiveId];

# if defined( SEC_ENABLE_VERIFICATION_DATA_LENGTH )
      if (pPrimitive->updateVerifiedData == TRUE)
      {
         /* Update member currentDataLength of verification parameter */
         SecM_UpdateDataLength(pVerifyParam);
      }
# endif /* SEC_ENABLE_VERIFICATION_DATA_LENGTH */

      switch (pVerifyParam->sigState)
      {
         case SEC_HASH_INIT:
         {
# if defined( SEC_ENABLE_VERIFY_SIGNATURE_CONTEXT_HANDLING )
            /* Clear the context of the previous operation */
            if (pPrimitive->pVerWks != V_NULL)
            {
               pPrimitive->pVerWks->size = 0u;
            }
# endif
            if (pPrimitive->hashJobId == SEC_INVALID_SMH_JOB_ID)
            {
               /* Init verification */
               result = SecM_SignatureVerifyJob(pPrimitive->jobId, SECM_OPERATIONMODE_START, pVerifyParam->key,
                  NULL_PTR, 0u, NULL_PTR, 0u);
            }
# if defined( SEC_ENABLE_VERIFICATION_DISCRETE_HASH_CALC )
            else
            {
               /* Call hash init function */
               result = SecM_HashJob(pPrimitive->hashJobId, SECM_OPERATIONMODE_START, NULL_PTR, 0u, NULL_PTR, NULL_PTR);
            }
# endif /* SEC_ENABLE_VERIFICATION_DISCRETE_HASH_CALC */

            break;
         }
         case SEC_HASH_COMPUTE:
         {
            if (pPrimitive->hashJobId == SEC_INVALID_SMH_JOB_ID)
            {
               /* Update verification with data in buffer */
               result = SecM_SignatureVerifyJob(pPrimitive->jobId, SECM_OPERATIONMODE_UPDATE, NULL_PTR,
                  pVerifyParam->sigSourceBuffer, pVerifyParam->sigByteCount, NULL_PTR, 0u);
            }
# if defined( SEC_ENABLE_VERIFICATION_DISCRETE_HASH_CALC )
            else
            {
               /* Call hash update function */
               result = SecM_HashJob(pPrimitive->hashJobId, SECM_OPERATIONMODE_UPDATE,
                  pVerifyParam->sigSourceBuffer, pVerifyParam->sigByteCount, NULL_PTR, NULL_PTR);
            }
# endif /* SEC_ENABLE_VERIFICATION_DISCRETE_HASH_CALC */

            break;
         }
         case SEC_HASH_FINALIZE:
         {
            /* No explicit finalization step - implicitely done in verification step */
            result = SECM_VER_OK;
            break;
         }
         case SEC_SIG_VERIFY:
         {
            SecM_StatusType ctxResult = SECM_VER_OK;
# if defined( SEC_ENABLE_VERIFY_SIGNATURE_CONTEXT_HANDLING )
            SecM_WordType localJobId;

            if (pPrimitive->pVerWks != V_NULL)
            {
               /* PRQA S 2983 1 */ /* MD_SecVerification_2983 */
               localJobId = pPrimitive->jobId;
#  if defined( SEC_ENABLE_VERIFICATION_DISCRETE_HASH_CALC )
               if (pPrimitive->hashJobId != SEC_INVALID_SMH_JOB_ID)
               {
                  localJobId = pPrimitive->hashJobId;
               }
#  endif
               ctxResult = SecM_VerifyContextHandling(localJobId, pPrimitive->contextBufferSize, &(pPrimitive->pVerWks->size), pPrimitive->pVerWks->data);
            }
# endif
            /* PRQA S 2991, 2995 1 */ /* MD_SecVerification_2991_2992_2995_2996 */
            if (ctxResult == SECM_VER_OK)
            {
               if (pPrimitive->hashJobId == SEC_INVALID_SMH_JOB_ID)
               {
                  SecM_ByteType dummy[1u] = { 0u }; /* PRQA S 3678 */ /* MD_MSR_Rule8.13 */

                  result = SecM_SignatureVerifyJob(pPrimitive->jobId, SECM_OPERATIONMODE_FINISH, NULL_PTR, dummy, 0u,
                     pVerifyParam->sigSourceBuffer, pVerifyParam->sigByteCount);
               }
# if defined( SEC_ENABLE_VERIFICATION_DISCRETE_HASH_CALC )
               else
               {
                  /* Finalize hash calculation */
                  SecM_WordType hashLength = pPrimitive->hashDigestLength;

                  if (SecM_HashJob(pPrimitive->hashJobId, SECM_OPERATIONMODE_FINISH, NULL_PTR, 0u, pPrimitive->hashDigest, &hashLength) == SECM_OK)
                  {
                     /* Check if the resulting length is as expected */
                     if (hashLength == pPrimitive->hashDigestLength)
                     {
                        /* Verify signature using previously calculated message digest */
                        result = SecM_SignatureVerifyJob(pPrimitive->jobId, SECM_OPERATIONMODE_SINGLECALL, pVerifyParam->key, pPrimitive->hashDigest, pPrimitive->hashDigestLength, pVerifyParam->sigSourceBuffer, pVerifyParam->sigByteCount);
                     }
                  }
               }
# endif /* SEC_ENABLE_VERIFICATION_DISCRETE_HASH_CALC */
            }
            break;
         }
         default:
         {
            /* Unknown state - result already set */
            break;
         }
      }
   }

   return result;
}
#endif /* SEC_ENABLE_VERIFY_SIGNATURE */

#define SECM_STOP_SEC_CODE
#include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_MemMap */

/***********************************************************************************************************************
 *  MISRA
 **********************************************************************************************************************/

/* Module specific MISRA deviations:

   MD_SecVerification_0306:
      Reason:     HIS security module specification defines reference to buffer to be stored as unsigned 32-bit value
                  instead of pointer type.
      Risk:       The size of integer required to hold the result of a pointer cast is implementation defined.
      Prevention: 32 bit handles all current use-cases. Pay special attention when 64 bit ECUs are introduced.

   MD_SecVerification_0326:
      Reason:     Casting to void pointer required, as actual type not known here.
      Risk:       No identifiable risk.
      Prevention: No prevention required.

   MD_SecVerification_0781:
      Reason:     The name is being used as a structure/union member as well as being a label, tag or ordinary identifier.
                  This way it is more clear to the reader which purpose the variable has.
      Risk:       No identifiable risk.
      Prevention: No prevention required.

   MD_SecVerification_2983:
      Reason:     The assignment is redundant only on some configurations.
      Risk:       No risk.
      Prevention: No prevention.

   MD_SecVerification_2986:
      Reason: Value is constant depending on configuration aspects or platform specific implementation. This leads to constant control expressions, unreachable code or redundant operations.
      Risk:       No identifiable risk.
      Prevention: No prevention required.

   MD_SecVerification_2991_2992_2995_2996:
      Reason:     The value of the if-controlling expression or logical operation depends on the configuration.
      Risk:       No risk.
      Prevention: No prevention necessary.

   MD_SecVerification_3196:
      Reason:     Variable used as context to remove the need for global variables. Initialization takes place in called
                  function.
      Risk:       Callee does not perform complete initializaton, but accesses those un-initialized parts of the variabl
                  anyway. Implies same risk as use of global variable.
      Prevention: Perform code analysis of callee to make sure no un-initialized parts are accessed.

   MD_SecVerification_3218:
      Reason:     The local variables of this module are kept at a central location for a better overview and maintenance.
      Risk:       Scope is larger than required (whole file instead of one function). Some other function could access
                  the variable.
      Prevention: Restrict the functionality in this module to the intended purpose. Don't add functions which shall not
                  be able to access the local data buffers.

   MD_SecVerification_3225:
      Reason:     Input buffer placed on stack to remove the need for global variables. Reference only used in
                  SecM_Verify* functions executed in context of declaring function.
      Risk:       Buffer reference used outside of context of declaring function.
      Prevention: Ensure correct use of buffer in called functions through code inspection.

   MD_SecVerification_3382:
      Reason:     Subtraction from unsigned value without explicit range check directly before operation.
                  Instead limitation of subtracted value is located above as it is required before.
      Risk:       Distance between limitation and subtraction makes correlation less obvious.
      Prevention: Ensure correct limitation of subtracted value through code inspection..

*/

/***********************************************************************************************************************
 *  END OF FILE: SEC_VERIFICATION.C
 **********************************************************************************************************************/
