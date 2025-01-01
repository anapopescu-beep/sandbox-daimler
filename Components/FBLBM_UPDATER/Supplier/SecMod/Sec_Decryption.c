/***********************************************************************************************************************
 *  FILE DESCRIPTION
 *  ------------------------------------------------------------------------------------------------------------------*/
/** \file
 *  \brief        Implementation of the HIS security module - Decryption
 *
 *  \description  Offers API for decryption and encryption
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

#define SEC_DECRYPTION_SOURCE

/***********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/

/* Security module configuration settings */
#include "Sec_Inc.h"

/* Global definitions for security module */
#include "Sec_Types.h"

/* Decryption interface */
#include "Sec_Decryption.h"

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/

#define SECM_START_SEC_CODE
#include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_MemMap */

#if defined( SEC_ENABLE_DECRYPTION ) || defined( SEC_ENABLE_ENCRYPTION )
/**********************************************************************************************************************
 *  SecM_DecryptionUpdate
 *********************************************************************************************************************/
/*! \brief         Decrypt/encrypt given data into provided output buffer using the selected mode
 *  \details       Output buffer should be 16 byte larger than input buffer to hold all decrypted data
 *  \param[in]     pInBlock Reference to input data
 *  \param[in,out] pOutBlock Reference to output data
 *                   Length contains available buffer size as input and length of decrypted data as output
 *  \param[in]     pDecParam Decryption parameters (segmentAddress and segmentLength not used yet)
 *                   Valid mode values are
 *                   - SEC_DECRYPTION_MODE_DEFAULT: Use implicit initialization vector (= 0) if applicable
 *                   - SEC_DECRYPTION_MODE_IV: Use first 16 byte of input data as explicit IV
 *                   The following modifiers can be added to the mode:
 *                   - SEC_DECRYPTION_MODE_INIT: Perform initialization, including IV
 *                   - SEC_DECRYPTION_MODE_FINALIZE: Perform de-initialization and handle padding
 *  \param[in]     pPrimitive Pointer to parameter structure for decryption/encryption primitive
 *  \param[in]     blockMode Block cipher mode of operation
 *  \param[in]     paddingMode Padding mode
 *  \return        SECM_OK if decryption successful
 *                 SECM_NOT_OK if error occurred during decryption
 *********************************************************************************************************************/
SecM_StatusType SecM_DecryptionUpdate(const V_MEMRAM1 SecM_DecInputParamType V_MEMRAM2 V_MEMRAM3 * pInBlock,
   V_MEMRAM1 SecM_DecOutputParamType V_MEMRAM2 V_MEMRAM3 * pOutBlock,
   const V_MEMRAM1 SecM_DecParamType V_MEMRAM2 V_MEMRAM3 * pDecParam,
   SecM_WordType smhId)
{
   SecM_StatusType result;
   SecM_ByteType opMode;
   uint32 outLength;
   SecM_OperationModeType operationMode;
   SecM_AesKeyType aesKey;
   V_MEMROM1 SecM_DecPrimitiveType V_MEMROM2 V_MEMROM3 * pPrimitive;

   /* Initialize variables */
   result = SECM_NOT_OK;

   if (smhId < SecM_GetSizeOfDecryptionPrimitives())
   {
      /* Copy parameter values to local variables */
      opMode = pDecParam->mode;
      pPrimitive = &SecM_DecryptionPrimitives[smhId];
      operationMode = SECM_OPERATIONMODE_NONE;

      /* Perform initialization */
      if (SEC_DECRYPTION_MODE_INIT == (opMode & SEC_DECRYPTION_MODE_INIT))
      {
         operationMode |= SECM_OPERATIONMODE_START;
         if (SEC_DECRYPTION_MODE_IV == (opMode & SEC_DECRYPTION_MODE_IV))
         {
            operationMode |= SECM_OPERATIONMODE_IV;
         }

         /* Copy key to aes key structure */
         aesKey.key.data = pDecParam->key.data;
         aesKey.key.size = pDecParam->key.size;
         /* IV is handled in the underlaying function */
      }

      /* Encrypt / Decrypt data */
      if (pInBlock->Length != 0u)
      {
         operationMode |= SECM_OPERATIONMODE_UPDATE;
      }

      /* Finalize decryption */
      if (SEC_DECRYPTION_MODE_FINALIZE == (opMode & SEC_DECRYPTION_MODE_FINALIZE))
      {
         operationMode |= SECM_OPERATIONMODE_FINISH;
      }

      if (operationMode != 0u)
      {
         outLength = pOutBlock->Length;
         /* PRQA S 0314 1 */ /* MD_SecDecryption_0314 */
         result = pPrimitive->func(pPrimitive->jobId, operationMode, (SecM_VoidPtrType)&aesKey, pInBlock->DataBuffer, pInBlock->Length, pOutBlock->DataBuffer, &outLength);
         pOutBlock->Length = (SecM_LengthType)outLength;
      }
   }

   return result;
} /* PRQA S 6060 */ /* MD_MSR_STPAR */

/***********************************************************************************************************************
 *  SecM_InitDecryption
 **********************************************************************************************************************/
/*! \brief         Initialize decryption
 *  \param[in]     init Dummy pointer (currently not used)
 *  \return        SECM_OK if initialization successful
 *                 SECM_NOT_OK if error occurred during initialization
 **********************************************************************************************************************/
SecM_StatusType SecM_InitDecryption( SecM_DecInitType init )
{
# if defined( V_ENABLE_USE_DUMMY_STATEMENT )
   /* Parameters not used: avoid compiler warning */ /* PRQA S 3112 1 */ /* MD_MSR_DummyStmt */
   (void)init;
# endif /* V_ENABLE_USE_DUMMY_STATEMENT */

# if defined( SEC_ENABLE_DECRYPTION )
   return SECM_OK;
# else
   return SECM_NOT_OK;
# endif /* SEC_ENABLE_DECRYPTION */
}

/***********************************************************************************************************************
 *  SecM_DeinitDecryption
 **********************************************************************************************************************/
/*! \brief         Deinitialize decryption
 *  \param[in]     deinit Dummy pointer (currently not used)
 *  \return        SECM_OK if deinitialization successful
 *                 SECM_NOT_OK if error occurred during deinitialization
 **********************************************************************************************************************/
SecM_StatusType SecM_DeinitDecryption( SecM_DecDeinitType deinit )
{
# if defined( V_ENABLE_USE_DUMMY_STATEMENT )
   /* Parameters not used: avoid compiler warning */ /* PRQA S 3112 1 */ /* MD_MSR_DummyStmt */
   (void)deinit;
# endif /* V_ENABLE_USE_DUMMY_STATEMENT */

# if defined( SEC_ENABLE_DECRYPTION )
   return SECM_OK;
# else
   return SECM_NOT_OK;
# endif /* SEC_ENABLE_DECRYPTION */
}

/***********************************************************************************************************************
 *  SecM_Decryption
 **********************************************************************************************************************/
/*! \brief         Decrypt given data into provided output buffer
 *  \details       Decrypts all encrypted data referenced in input block into buffer provided in output block
 *                 Operation reports an error in case the output buffer isn't large enough
 *  \param[in]     pInBlock Reference to input data
 *  \param[in,out] pOutBlock Reference to output data
 *                   Length contains available buffer size as input and length of decrypted data as output
 *  \param[in]     pDecParam Decryption parameters (segmentAddress and segmentLength not used yet)
 *  \return        SECM_OK if decryption successful
 *                 SECM_NOT_OK if error occurred during decryption
 **********************************************************************************************************************/
/* PRQA S 3673 3 */ /* MD_MSR_Rule8.13 */
SecM_StatusType SecM_Decryption( const V_MEMRAM1 SecM_DecInputParamType V_MEMRAM2 V_MEMRAM3 * pInBlock,
   V_MEMRAM1 SecM_DecOutputParamType V_MEMRAM2 V_MEMRAM3 * pOutBlock,
   V_MEMRAM1 SecM_DecParamType V_MEMRAM2 V_MEMRAM3 * pDecParam )
{
# if defined( SEC_ENABLE_DECRYPTION ) && defined( SEC_DEFAULT_DECRYPTION_CONFIG )
   return SecM_DecryptionUpdate(pInBlock, pOutBlock, pDecParam, SEC_DEFAULT_DECRYPTION_CONFIG);
# else
#  if defined( V_ENABLE_USE_DUMMY_STATEMENT )
   /* Parameters not used: avoid compiler warning */ /* PRQA S 3112 3 */ /* MD_MSR_DummyStmt */
   (void)pInBlock;
   (void)pOutBlock;
   (void)pDecParam;
#  endif /* V_ENABLE_USE_DUMMY_STATEMENT */

   return SECM_NOT_OK;
# endif /* SEC_ENABLE_DECRYPTION */
}

/***********************************************************************************************************************
 *  SecM_InitEncryption
 **********************************************************************************************************************/
/*! \brief         Initialize encryption
 *  \param[in]     init Dummy pointer (currently not used)
 *  \return        SECM_OK if initialization successful
 *                 SECM_NOT_OK if error occurred during initialization
 **********************************************************************************************************************/
SecM_StatusType SecM_InitEncryption( SecM_DecInitType init )
{
# if defined( V_ENABLE_USE_DUMMY_STATEMENT )
   /* Parameters not used: avoid compiler warning */ /* PRQA S 3112 1 */ /* MD_MSR_DummyStmt */
   (void)init;
# endif /* V_ENABLE_USE_DUMMY_STATEMENT */

# if defined( SEC_ENABLE_ENCRYPTION )
   return SECM_OK;
# else
   return SECM_NOT_OK;
# endif /* SEC_ENABLE_ENCRYPTION */
}

/***********************************************************************************************************************
 *  SecM_DeinitEncryption
 **********************************************************************************************************************/
/*! \brief         Deinitialize encryption
 *  \param[in]     deinit Dummy pointer (currently not used)
 *  \return        SECM_OK if deinitialization successful
 *                 SECM_NOT_OK if error occurred during deinitialization
 **********************************************************************************************************************/
SecM_StatusType SecM_DeinitEncryption( SecM_DecDeinitType deinit )
{
# if defined( V_ENABLE_USE_DUMMY_STATEMENT )
   /* Parameters not used: avoid compiler warning */ /* PRQA S 3112 1 */ /* MD_MSR_DummyStmt */
   (void)deinit;
# endif /* V_ENABLE_USE_DUMMY_STATEMENT */

# if defined( SEC_ENABLE_ENCRYPTION )
   return SECM_OK;
# else
   return SECM_NOT_OK;
# endif /* SEC_ENABLE_ENCRYPTION */
}

/***********************************************************************************************************************
 *  SecM_Encryption
 **********************************************************************************************************************/
/*! \brief         Encrypt given data into provided output buffer
 *  \details       Encrypts all data referenced in input block into buffer provided in output block.
 *                 Operation reports an error in case the output buffer isn't large enough.
 *  \param[in]     pInBlock Reference to input data
 *  \param[in,out] pOutBlock Reference to output data
 *                   Length contains available buffer size as input and length of encrypted data as output
 *  \param[in]     pEncParam Encryption parameters (segmentAddress and segmentLength not used yet)
 *  \return        SECM_OK if encryption successful
 *                 SECM_NOT_OK if error occurred during encryption
 **********************************************************************************************************************/
/* PRQA S 3673 3 */ /* MD_MSR_Rule8.13 */
SecM_StatusType SecM_Encryption( const V_MEMRAM1 SecM_DecInputParamType V_MEMRAM2 V_MEMRAM3 * pInBlock,
   V_MEMRAM1 SecM_DecOutputParamType V_MEMRAM2 V_MEMRAM3 * pOutBlock,
   V_MEMRAM1 SecM_DecParamType V_MEMRAM2 V_MEMRAM3 * pEncParam )
{
# if defined( SEC_ENABLE_ENCRYPTION ) && defined( SEC_DEFAULT_ENCRYPTION_CONFIG )
   return SecM_DecryptionUpdate(pInBlock, pOutBlock, pEncParam, SEC_DEFAULT_ENCRYPTION_CONFIG);
# else
#  if defined( V_ENABLE_USE_DUMMY_STATEMENT )
   /* Parameters not used: avoid compiler warning */ /* PRQA S 3112 3 */ /* MD_MSR_DummyStmt */
   (void)pInBlock;
   (void)pOutBlock;
   (void)pEncParam;
#  endif /* V_ENABLE_USE_DUMMY_STATEMENT */

   return SECM_NOT_OK;
# endif /* SEC_ENABLE_ENCRYPTION */
}
#endif /* SEC_ENABLE_DECRYPTION || SEC_ENABLE_ENCRYPTION */
#define SECM_STOP_SEC_CODE
#include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_MemMap */

/***********************************************************************************************************************
 *  MISRA
 **********************************************************************************************************************/

/* Module specific MISRA deviations:

   MD_SecDecryption_0314:
      Reason:     The job functions have a void pointer as a key parameter.
      Risk:       No risk, because the underlying pointer type is known and the cast is safe.
      Prevention: No prevention necessary.

*/

/***********************************************************************************************************************
 *  END OF FILE: SEC_DECRYPTION.C
 **********************************************************************************************************************/
