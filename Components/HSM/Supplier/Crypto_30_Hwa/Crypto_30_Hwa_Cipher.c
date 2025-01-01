/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2021 by Vector Informatik GmbH.                                                  All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/*!        \file  Crypto_30_Hwa_Cipher.c
 *        \brief  Crypto Hwa Cipher implementation
 *
 *      \details  This file implements cipher crypto algorithm.
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 *********************************************************************************************************************/

#define CRYPTO_30_HWA_CIPHER_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

#include "Crypto_30_Hwa.h"
#include "Crypto_30_Hwa_Private.h"
#include "Crypto_30_Hwa_Hw.h"
#include "Crypto_30_Hwa_Custom.h"

#include "vHsm_Api.h"
#include "vstdlib.h"

/**********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 *********************************************************************************************************************/
#if !defined (CRYPTO_30_HWA_LOCAL) /* COV_CRYPTO_30_HWA_LOCAL_DEFINE */
# define CRYPTO_30_HWA_LOCAL                                               static
#endif

#if !defined (CRYPTO_30_HWA_LOCAL_INLINE) /* COV_CRYPTO_30_HWA_LOCAL_DEFINE */
# define CRYPTO_30_HWA_LOCAL_INLINE                                        LOCAL_INLINE
#endif

/**********************************************************************************************************************
 *  LOCAL FUNCTION MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

#define CRYPTO_30_HWA_START_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#if (CRYPTO_30_HWA_PRIMITIVE_AES_CIPHER == STD_ON) /* COV_CRYPTO_30_HWA_HARDWARE_DEPENDENT_FEATURE */
/**********************************************************************************************************************
 *  Crypto_30_Hwa_AesProcessBlocksSlicing()
 *********************************************************************************************************************/
/*! \brief          Splits data blocks according a threashold and sends it to the hardware
 *  \details        -
 *  \param[in,out]  workspace          AES workspace.
 *  \param[in]      in                 Pointer to input data with (blockCount * CRYPTO_30_HWA_AES_BLOCK_SIZE_BYTES) bytes.
 *  \param[in]      blockCount         Number of complete blocks that should be processed. Must be at least 1.
 *  \param[out]     out                Pointer to output data with (blockCount * CRYPTO_30_HWA_AES_BLOCK_SIZE_BYTES) bytes.
 *  \return         E_OK               Processing was successful.
 *                  E_NOT_OK           Processing failed.
 *  \pre            -
 *  \context        TASK
 *  \reentrant      TRUE, on different driver objects
 *  \synchronous    TRUE
 *********************************************************************************************************************/
CRYPTO_30_HWA_LOCAL FUNC(Std_ReturnType, CRYPTO_30_HWA_CODE) Crypto_30_Hwa_AesProcessBlocksSlicing(
  Crypto_30_Hwa_WorkSpaceAES_PtrType workspace, /* PRQA S 3673 */ /* MD_MSR_Rule8.13 */
  P2CONST(uint8, AUTOMATIC, CRYPTO_30_HWA_APPL_DATA) in,
  uint32 blockCount,
  P2VAR(uint8, AUTOMATIC, CRYPTO_30_HWA_APPL_DATA) out);

/**********************************************************************************************************************
 *  Crypto_30_Hwa_CheckCipherPrimitiveInfo()
 *********************************************************************************************************************/
/*! \brief          Checks if primitive info is correct to process cipher job
 *  \details        -
 *  \param[in]      job       Cipher job.
 *  \return         E_OK      Primitive info is correct.
 *                  E_NOT_OK  Primitive info is not correct.
 *  \pre            Crypto_30_Hwa_DispatchService() called before.
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
CRYPTO_30_HWA_LOCAL_INLINE FUNC(Std_ReturnType, CRYPTO_30_HWA_CODE) Crypto_30_Hwa_CheckCipherPrimitiveInfo(
  Crypto_30_Hwa_JobPtrType job);

/**********************************************************************************************************************
 *  Crypto_30_Hwa_AesStart()
 *********************************************************************************************************************/
/*! \brief          Initializes AES calculation.
 *  \details        Sets the key and the IV. Sets the cipher block operation mode and encryption.
 *                  Starts the AES operation.
 *  \param[in,out]  workspace          AES Workspace.
 *  \param[in]      cryptoKeyId        Crypto Key ID.
 *  \return         E_OK               Starting AES was successful.
 *                  E_NOT_OK           Starting AES failed.
 *  \pre            -
 *  \context        TASK
 *  \reentrant      TRUE, on different driver objects
 *  \synchronous    TRUE
 *********************************************************************************************************************/
CRYPTO_30_HWA_LOCAL_INLINE FUNC(Std_ReturnType, CRYPTO_30_HWA_CODE) Crypto_30_Hwa_AesStart(
  Crypto_30_Hwa_WorkSpaceAES_PtrType workspace,
  uint32 cryptoKeyId);

# if(CRYPTO_30_HWA_HARDWARE_AES_CTR == STD_OFF) /* COV_CRYPTO_30_HWA_HARDWARE_DEPENDENT_FEATURE */
/**********************************************************************************************************************
 *  Crypto_30_Hwa_CtrWithEcbMode()
 *********************************************************************************************************************/
/*! \brief         Computes AES-CTR with ECB encryption on hardware.
 *  \details        AES-CTR abstraction for hardware platforms without native AES-CTR support but with AES-ECB mode.
 *  \param[in,out]  workspace          AES Workspace.
 *  \param[in]      inputPtr           Input data buffer (Contains IV).
 *  \param[out]     outputPtr          Output data buffer (Contains Keystream when operation was successful).
 *  \return         E_OK               CTR encryption was successful.
 *  \pre            -
 *  \context        TASK
 *  \reentrant      TRUE, on different driver objects
 *  \synchronous    TRUE
 *********************************************************************************************************************/
CRYPTO_30_HWA_LOCAL FUNC(Std_ReturnType, CRYPTO_30_HWA_CODE) Crypto_30_Hwa_CtrWithEcbMode(
  Crypto_30_Hwa_WorkSpaceAES_PtrType workspace,
  P2CONST(uint8, AUTOMATIC, CRYPTO_30_HWA_APPL_DATA) inputPtr,
  P2VAR(uint8, AUTOMATIC, CRYPTO_30_HWA_APPL_DATA) outputPtr);
# endif /* (CRYPTO_30_HWA_HARDWARE_AES_CTR == STD_OFF) */

/**********************************************************************************************************************
 *  Crypto_30_Hwa_AesEncUpdate()
 *********************************************************************************************************************/
/*! \brief          Performs AES operation on input data and writes to output buffer.
 *  \details        -
 *  \param[in,out]  workspace          AES Workspace.
 *  \param[in]      inputPtr           Input data buffer.
 *  \param[in]      inputLength        Input data length.
 *  \param[out]     outputPtr          Output data buffer.
 *  \param[in,out]  outputLengthPtr    Output data length.
 *  \return         E_OK               Update was successful.
 *                  E_NOT_OK           Update failed.
 *  \pre            Crypto_30_Hwa_AesStart() called before.
 *  \context        TASK
 *  \reentrant      TRUE, on different driver objects
 *  \synchronous    TRUE
 *********************************************************************************************************************/
CRYPTO_30_HWA_LOCAL_INLINE FUNC(Std_ReturnType, CRYPTO_30_HWA_CODE) Crypto_30_Hwa_AesEncUpdate(
  Crypto_30_Hwa_WorkSpaceAES_PtrType workspace,
  P2CONST(uint8, AUTOMATIC, CRYPTO_30_HWA_APPL_DATA) inputPtr,
  uint32 inputLength,
  P2VAR(uint8, AUTOMATIC, CRYPTO_30_HWA_APPL_DATA) outputPtr,
  P2VAR(uint32, AUTOMATIC, CRYPTO_30_HWA_APPL_DATA) outputLengthPtr);

/**********************************************************************************************************************
 *  Crypto_30_Hwa_AesEncFinish()
 *********************************************************************************************************************/
/*! \brief          Finishes an AES encryption operation.
 *  \details        Eventually adds padding to the block and encrypts data and padding.
 *  \param[in,out]  workspace          AES Workspace.
 *  \param[out]     outputPtr          Output data buffer.
 *  \param[in,out]  outputLengthPtr    Output data length.
 *  \return         E_OK               Finish was successful.
 *                  E_NOT_OK           Finish failed.
 *  \pre            Crypto_30_Hwa_AesStart() called before.
 *  \context        TASK
 *  \reentrant      TRUE, on different driver objects
 *  \synchronous    TRUE
 *********************************************************************************************************************/
CRYPTO_30_HWA_LOCAL_INLINE FUNC(Std_ReturnType, CRYPTO_30_HWA_CODE) Crypto_30_Hwa_AesEncFinish(
  Crypto_30_Hwa_WorkSpaceAES_PtrType workspace,
  P2VAR(uint8, AUTOMATIC, CRYPTO_30_HWA_APPL_DATA) outputPtr,
  P2VAR(uint32, AUTOMATIC, CRYPTO_30_HWA_APPL_DATA) outputLengthPtr);

/**********************************************************************************************************************
 *  Crypto_30_Hwa_AesDecUpdate()
 *********************************************************************************************************************/
/*! \brief          Performs AES operation on input data and writes to output buffer.
 *  \details        -
 *  \param[in,out]  workspace          Workspace.
 *  \param[in]      inputPtr           Input data buffer.
 *  \param[in]      inputLength        Input data length.
 *  \param[out]     outputPtr          Output data buffer.
 *  \param[in,out]  outputLengthPtr    Output data length.
 *  \return         E_OK               Update was successful.
 *                  E_NOT_OK           Update failed.
 *  \pre            Crypto_30_Hwa_AesStart() called before.
 *  \context        TASK
 *  \reentrant      TRUE, on different driver objects
 *  \synchronous    TRUE
 *********************************************************************************************************************/
CRYPTO_30_HWA_LOCAL FUNC(Std_ReturnType, CRYPTO_30_HWA_CODE) Crypto_30_Hwa_AesDecUpdate(
  Crypto_30_Hwa_WorkSpaceAES_PtrType workspace,
  P2CONST(uint8, AUTOMATIC, CRYPTO_30_HWA_APPL_DATA) inputPtr,
  uint32 inputLength,
  P2VAR(uint8, AUTOMATIC, CRYPTO_30_HWA_APPL_DATA) outputPtr,
  P2VAR(uint32, AUTOMATIC, CRYPTO_30_HWA_APPL_DATA) outputLengthPtr);

/**********************************************************************************************************************
 *  Crypto_30_Hwa_AesDecFinish()
 *********************************************************************************************************************/
/*! \brief          Finishes AES decryption operation.
 *  \details        Decrypts last block and eventually removes padding.
 *  \param[in,out]  workspace          AES Workspace.
 *  \param[out]     outputPtr          Output data buffer.
 *  \param[in,out]  outputLengthPtr    Output data length.
 *  \return         E_OK               Finish was successful.
 *                  E_NOT_OK           Finish failed.
 *  \pre            Crypto_30_Hwa_AesDecUpdate() called before.
 *  \context        TASK
 *  \reentrant      TRUE, on different driver objects
 *  \synchronous    TRUE
 *********************************************************************************************************************/
CRYPTO_30_HWA_LOCAL_INLINE FUNC(Std_ReturnType, CRYPTO_30_HWA_CODE) Crypto_30_Hwa_AesDecFinish(
  Crypto_30_Hwa_WorkSpaceAES_PtrType workspace,
  P2VAR(uint8, AUTOMATIC, CRYPTO_30_HWA_APPL_DATA) outputPtr,
  P2VAR(uint32, AUTOMATIC, CRYPTO_30_HWA_APPL_DATA) outputLengthPtr);
#endif /* (CRYPTO_30_HWA_PRIMITIVE_AES_CIPHER == STD_ON)*/

#define CRYPTO_30_HWA_STOP_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

#define CRYPTO_30_HWA_START_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#if (CRYPTO_30_HWA_PRIMITIVE_AES_CIPHER == STD_ON) /* COV_CRYPTO_30_HWA_HARDWARE_DEPENDENT_FEATURE */
/**********************************************************************************************************************
 *  Crypto_30_Hwa_AesProcessBlocksSlicing()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
CRYPTO_30_HWA_LOCAL FUNC(Std_ReturnType, CRYPTO_30_HWA_CODE) Crypto_30_Hwa_AesProcessBlocksSlicing(
  Crypto_30_Hwa_WorkSpaceAES_PtrType workspace, /* PRQA S 3673 */ /* MD_MSR_Rule8.13 */
  P2CONST(uint8, AUTOMATIC, CRYPTO_30_HWA_APPL_DATA) in,
  uint32 blockCount,
  P2VAR(uint8, AUTOMATIC, CRYPTO_30_HWA_APPL_DATA) out)
{
  Std_ReturnType retVal = E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */
#if (CRYPTO_30_HWA_DATA_SLICING == STD_ON)
  uint32 i;
  uint32 offset;
  uint32 reminder = blockCount % CRYPTO_30_HWA_NON_PREEMPTIVE_BLOCK_COUNT_ROUNDED_AES;

  /* Process multiples of CRYPTO_30_HWA_NON_PREEMPTIVE_BLOCK_COUNT_ROUNDED_AES */
  for (i = 0; i < (blockCount / CRYPTO_30_HWA_NON_PREEMPTIVE_BLOCK_COUNT_ROUNDED_AES); ++i)
  {
    offset = i * CRYPTO_30_HWA_AES_BLOCK_SIZE_BYTES * CRYPTO_30_HWA_NON_PREEMPTIVE_BLOCK_COUNT_ROUNDED_AES;
    SchM_Enter_Crypto_30_Hwa_CRYPTO_30_HWA_EXCLUSIVE_AREA_1();
    retVal |= Crypto_30_Hwa_Hw_AesProcessBlocks(workspace, &in[offset], CRYPTO_30_HWA_NON_PREEMPTIVE_BLOCK_COUNT_ROUNDED_AES, &out[offset]);
    SchM_Exit_Crypto_30_Hwa_CRYPTO_30_HWA_EXCLUSIVE_AREA_1();
  }

  /* Process not multiples of CRYPTO_30_HWA_NON_PREEMPTIVE_BLOCK_COUNT_ROUNDED_AES */
  if (reminder > 0u)
  {
    offset = i * CRYPTO_30_HWA_AES_BLOCK_SIZE_BYTES * CRYPTO_30_HWA_NON_PREEMPTIVE_BLOCK_COUNT_ROUNDED_AES;
    SchM_Enter_Crypto_30_Hwa_CRYPTO_30_HWA_EXCLUSIVE_AREA_1();
    retVal |= Crypto_30_Hwa_Hw_AesProcessBlocks(workspace, &in[offset], reminder, &out[offset]);
    SchM_Exit_Crypto_30_Hwa_CRYPTO_30_HWA_EXCLUSIVE_AREA_1();
  }

#else
  retVal = Crypto_30_Hwa_Hw_AesProcessBlocks(workspace, in, blockCount, out);
#endif /* (CRYPTO_30_HWA_DATA_SLICING == STD_ON) */

  return retVal;
}

/**********************************************************************************************************************
 *  Crypto_30_Hwa_CheckCipherPrimitiveInfo()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 */
CRYPTO_30_HWA_LOCAL_INLINE FUNC(Std_ReturnType, CRYPTO_30_HWA_CODE) Crypto_30_Hwa_CheckCipherPrimitiveInfo(
  Crypto_30_Hwa_JobPtrType job) /* PRQA S 3673 */ /* MD_MSR_Rule8.13 */
{
  Std_ReturnType retVal = E_OK;

  /* #10 Verify whether family is correct */
  if (job->jobPrimitiveInfo->primitiveInfo->algorithm.family != CRYPTO_ALGOFAM_AES)
  {
    retVal = E_NOT_OK;
  }
  /* #11 Verify whether mode is correct */
  else if ((job->jobPrimitiveInfo->primitiveInfo->algorithm.mode != CRYPTO_ALGOMODE_CBC)
         && (job->jobPrimitiveInfo->primitiveInfo->algorithm.mode != CRYPTO_ALGOMODE_ECB)
         && (job->jobPrimitiveInfo->primitiveInfo->algorithm.mode != CRYPTO_ALGOMODE_CTR))
  {
    retVal = E_NOT_OK;
  }
  /* #12 Verify whether secondary family is correct */
  else if ((job->jobPrimitiveInfo->primitiveInfo->algorithm.secondaryFamily != CRYPTO_ALGOFAM_CUSTOM_PADDING_NONE)
         && (job->jobPrimitiveInfo->primitiveInfo->algorithm.secondaryFamily != CRYPTO_ALGOFAM_CUSTOM_PADDING_PKCS7))
  {
    retVal = E_NOT_OK;
  }
  else
  {
    /* Nothing to do here */
  }

  return retVal;
}

/**********************************************************************************************************************
 *  Crypto_30_Hwa_AesStart()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
CRYPTO_30_HWA_LOCAL_INLINE FUNC(Std_ReturnType, CRYPTO_30_HWA_CODE) Crypto_30_Hwa_AesStart(
  Crypto_30_Hwa_WorkSpaceAES_PtrType workspace,
  uint32 cryptoKeyId)
{
  Std_ReturnType retVal = E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */
  vHsm_Api_KeyStorageIndexType index = 0u;
  P2CONST(uint8, AUTOMATIC, CRYPTO_30_HWA_APPL_DATA) key = NULL_PTR; /* PRQA S 2981 */ /* MD_CRYPTO_30_HWA_2981_REDUNDANT_INITIALIZATION */
  P2CONST(uint8, AUTOMATIC, CRYPTO_30_HWA_APPL_DATA) iv = NULL_PTR;
  uint8 ivLength = 0u;

  /* Init workspace */
  workspace->bufferFillLevel = 0u;
  workspace->bufferOutFull = FALSE;
  workspace->outputLength = 0u;
  workspace->cryptoKeyId = cryptoKeyId;
  workspace->keySize = 0u;
#if (CRYPTO_30_HWA_ROMKEY == STD_ON) /* COV_CRYPTO_30_HWA_HARDWARE_DEPENDENT_FEATURE */
  workspace->romKeyMapIndex = 0;

  Crypto_30_Hwa_CheckRomKeyUsage(workspace->cryptoKeyId, &workspace->romKeyMapIndex);

  if (workspace->romKeyMapIndex == CRYPTO_30_HWA_ROMKEY_USE_IMPORTED_KEY)
#endif /* (CRYPTO_30_HWA_ROMKEY == STD_ON) */
  {
    /* Get AES key */
    retVal = vHsm_Api_KeyElementGetForCryptoJobs(cryptoKeyId, CRYPTO_KE_CIPHER_KEY,
      &index, CRYPTO_30_HWA_AES_KEY_SIZE, VHSM_API_SHE_SERVICE_ENCRYPT_DECRYPT);

    /* Set keysize if keylength was 128 bit. */
    if (retVal == E_OK)
    {
      workspace->keySize = CRYPTO_30_HWA_AES_KEY_SIZE;
    }

#if (CRYPTO_30_HWA_HARDWARE_AES192 == STD_ON)   /* COV_CRYPTO_30_HWA_HARDWARE_DEPENDENT_FEATURE */
    /* Check the keylength if the key was no 128 bit key */
    if (retVal == CRYPTO_E_KEY_SIZE_MISMATCH)
    {
      retVal = vHsm_Api_KeyElementGetForCryptoJobs(cryptoKeyId, CRYPTO_KE_CIPHER_KEY,
        &index, CRYPTO_30_HWA_AES192_KEY_SIZE_BYTES, VHSM_API_SHE_SERVICE_ENCRYPT_DECRYPT);
      workspace->keySize = CRYPTO_30_HWA_AES192_KEY_SIZE_BYTES;
    }
#endif  /* CRYPTO_30_HWA_HARDWARE_AES192 == STD_ON */

#if (CRYPTO_30_HWA_HARDWARE_AES256 == STD_ON)   /* COV_CRYPTO_30_HWA_HARDWARE_DEPENDENT_FEATURE */
    /* Check the keylength if the key was no 192 bit key */
    if (retVal == CRYPTO_E_KEY_SIZE_MISMATCH)
    {
      retVal = vHsm_Api_KeyElementGetForCryptoJobs(cryptoKeyId, CRYPTO_KE_CIPHER_KEY,
        &index, CRYPTO_30_HWA_AES256_KEY_SIZE_BYTES, VHSM_API_SHE_SERVICE_ENCRYPT_DECRYPT);
      workspace->keySize = CRYPTO_30_HWA_AES256_KEY_SIZE_BYTES;
    }
#endif  /* CRYPTO_30_HWA_HARDWARE_AES256 == STD_ON */

    if (retVal == E_OK)
    {
      key = vHsm_Api_GetAddrKeyStorage(index);
    }
  }

  if (retVal == E_OK)
  {
    if( (workspace->primitiveInfo->algorithm.mode == CRYPTO_ALGOMODE_CBC)
    || (workspace->primitiveInfo->algorithm.mode == CRYPTO_ALGOMODE_CTR) )
    {
      uint32 ivKeyId = cryptoKeyId;

      /* Get IV */
#if (CRYPTO_30_HWA_ROMKEY == STD_ON) /* COV_CRYPTO_30_HWA_HARDWARE_DEPENDENT_FEATURE */
      index = 0u;
      if (workspace->romKeyMapIndex != CRYPTO_30_HWA_ROMKEY_USE_IMPORTED_KEY)
      {
        ivKeyId = Crypto_30_Hwa_GetAggregatedCryptoKeyIdOfKeyMap(workspace->romKeyMapIndex);
      }
#endif /* (CRYPTO_30_HWA_ROMKEY == STD_ON) */

      retVal = vHsm_Api_KeyElementGetForCryptoJobs(ivKeyId,
        CRYPTO_KE_CIPHER_IV, &index, CRYPTO_30_HWA_AES_KEY_SIZE, VHSM_API_SHE_SERVICE_ENCRYPT_DECRYPT);

      ivLength = CRYPTO_30_HWA_AES_KEY_SIZE;
      if (retVal == E_OK)
      {
        iv = vHsm_Api_GetAddrKeyStorage(index);

        /* copy IV to workspace, so that CTR is supported on hardware platforms that provide ECB mode */
        if (workspace->primitiveInfo->algorithm.mode == CRYPTO_ALGOMODE_CTR)
        {
          VStdLib_MemCpy(workspace->bufferOut, iv, CRYPTO_30_HWA_AES_BLOCK_SIZE_BYTES); /* PRQA S 0315 */ /* MD_MSR_VStdLibCopy */
        }
      }
    }

    if (retVal == E_OK)
    {
      /* Call platform specific Aes start function */
      if(workspace->primitiveInfo->algorithm.mode == CRYPTO_ALGOMODE_CTR)
      {
        SchM_Enter_Crypto_30_Hwa_CRYPTO_30_HWA_EXCLUSIVE_AREA_1();
#if(CRYPTO_30_HWA_HARDWARE_AES_CTR == STD_OFF) /* COV_CRYPTO_30_HWA_HARDWARE_DEPENDENT_FEATURE */
        retVal = Crypto_30_Hwa_Hw_AesStart(workspace, key, iv, ivLength, CRYPTO_ALGOMODE_ECB, CRYPTO_ENCRYPT);
#else
        retVal = Crypto_30_Hwa_Hw_AesStart(workspace, key, iv, ivLength, CRYPTO_ALGOMODE_CTR, CRYPTO_ENCRYPT);
#endif
        SchM_Exit_Crypto_30_Hwa_CRYPTO_30_HWA_EXCLUSIVE_AREA_1();
      }
      else
      {
        SchM_Enter_Crypto_30_Hwa_CRYPTO_30_HWA_EXCLUSIVE_AREA_1();
        retVal = Crypto_30_Hwa_Hw_AesStart(workspace, key, iv, ivLength, workspace->primitiveInfo->algorithm.mode, workspace->primitiveInfo->service);
        SchM_Exit_Crypto_30_Hwa_CRYPTO_30_HWA_EXCLUSIVE_AREA_1();
      }
    }
  }

  return retVal;
} /* Crypto_30_Hwa_AesStart() */ /* PRQA S 6010, 6030 */ /* MD_MSR_STPTH, MD_MSR_STCYC */

#if(CRYPTO_30_HWA_HARDWARE_AES_CTR == STD_OFF) /* COV_CRYPTO_30_HWA_HARDWARE_DEPENDENT_FEATURE */
/**********************************************************************************************************************
 *  Crypto_30_Hwa_CtrWithEcbMode()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
CRYPTO_30_HWA_LOCAL FUNC(Std_ReturnType, CRYPTO_30_HWA_CODE) Crypto_30_Hwa_CtrWithEcbMode(
  Crypto_30_Hwa_WorkSpaceAES_PtrType workspace,
  P2CONST(uint8, AUTOMATIC, CRYPTO_30_HWA_APPL_DATA) inputPtr,
  P2VAR(uint8, AUTOMATIC, CRYPTO_30_HWA_APPL_DATA) outputPtr)
{
  Std_ReturnType retVal;
  uint32 blockIdx;
  uint32 counterValue;

  /* Get Keystream with ECB encryption of the IV */
  SchM_Enter_Crypto_30_Hwa_CRYPTO_30_HWA_EXCLUSIVE_AREA_1();
  retVal = Crypto_30_Hwa_Hw_AesProcessBlocks(workspace, workspace->bufferOut, 1u, outputPtr);
  SchM_Exit_Crypto_30_Hwa_CRYPTO_30_HWA_EXCLUSIVE_AREA_1();

  /* Get Cipher by computing Keystream XOR Input */
  for (blockIdx = 0; blockIdx < CRYPTO_30_HWA_AES_BLOCK_SIZE_BYTES; blockIdx++)
  {
    outputPtr[blockIdx] = outputPtr[blockIdx] ^ inputPtr[blockIdx];
  }
  /* Increase IV Counter value for next round
  * The CTR-IV last 4 byte contains a counter value
  * use a 4 byte pointer to interpret them as one integer value
  * the bytes are stored in big endian format, so convert to little endian, then increment and write back */
  counterValue =        (((uint32)workspace->bufferOut[12]) << 24u)
                      | (((uint32)workspace->bufferOut[13]) << 16u)
                      | (((uint32)workspace->bufferOut[14]) << 8u)
                      |  ((uint32)workspace->bufferOut[15]);
  counterValue++;
  workspace->bufferOut[12] = (uint8)(counterValue >> 24u);
  workspace->bufferOut[13] = (uint8)((counterValue >> 16u) & 0xFFu);
  workspace->bufferOut[14] = (uint8)((counterValue >> 8u) & 0xFFu);
  workspace->bufferOut[15] = (uint8)((counterValue) & 0xFFu);

  return retVal;
}
#endif /* (CRYPTO_30_HWA_HARDWARE_AES_CTR == STD_OFF) */

/**********************************************************************************************************************
 *  Crypto_30_Hwa_AesEncUpdate()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 */
CRYPTO_30_HWA_LOCAL_INLINE FUNC(Std_ReturnType, CRYPTO_30_HWA_CODE) Crypto_30_Hwa_AesEncUpdate(
  Crypto_30_Hwa_WorkSpaceAES_PtrType workspace,
  P2CONST(uint8, AUTOMATIC, CRYPTO_30_HWA_APPL_DATA) inputPtr,
  uint32 inputLength,
  P2VAR(uint8, AUTOMATIC, CRYPTO_30_HWA_APPL_DATA) outputPtr,
  P2VAR(uint32, AUTOMATIC, CRYPTO_30_HWA_APPL_DATA) outputLengthPtr)
{
  Std_ReturnType retVal = E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */
  uint32 inputProcessed = 0u;
  uint32 outputWritten = 0u;
  uint32 blockCount;

  /* Check for sufficient output buffer */
  if (*outputLengthPtr < (workspace->bufferFillLevel + inputLength))
  {
    retVal = E_NOT_OK;
  }
  else
  {
    blockCount = CRYPTO_30_HWA_AES_BYTES_TO_BLOCKS(workspace->bufferFillLevel + inputLength);

    /* Process buffered data first if available */
    if ((workspace->bufferFillLevel > 0u) && (blockCount > 0u))
    {
      /* Complete buffer with input data */
      inputProcessed = (CRYPTO_30_HWA_AES_BLOCK_SIZE_BYTES - workspace->bufferFillLevel);
      VStdLib_MemCpy(&workspace->buffer[workspace->bufferFillLevel], inputPtr, inputProcessed); /* PRQA S 0315 */ /* MD_MSR_VStdLibCopy */
      /* Push data to hardware */
#if(CRYPTO_30_HWA_HARDWARE_AES_CTR == STD_OFF) /* COV_CRYPTO_30_HWA_HARDWARE_DEPENDENT_FEATURE */
      if (workspace->primitiveInfo->algorithm.mode == CRYPTO_ALGOMODE_CTR)
      {
        retVal = Crypto_30_Hwa_CtrWithEcbMode(workspace, workspace->buffer, outputPtr);
      }
      else
#endif /* (CRYPTO_30_HWA_HARDWARE_AES_CTR == STD_OFF) */
      {
        SchM_Enter_Crypto_30_Hwa_CRYPTO_30_HWA_EXCLUSIVE_AREA_1();
        retVal = Crypto_30_Hwa_Hw_AesProcessBlocks(workspace, workspace->buffer, 1u, outputPtr);
        SchM_Exit_Crypto_30_Hwa_CRYPTO_30_HWA_EXCLUSIVE_AREA_1();
      }
      blockCount--;
      workspace->bufferFillLevel = 0u;
      outputWritten = CRYPTO_30_HWA_AES_BLOCK_SIZE_BYTES;
    }

    if (blockCount > 0u)
    {
#if(CRYPTO_30_HWA_HARDWARE_AES_CTR == STD_OFF) /* COV_CRYPTO_30_HWA_HARDWARE_DEPENDENT_FEATURE */
      if (workspace->primitiveInfo->algorithm.mode == CRYPTO_ALGOMODE_CTR)
      {
        uint8* outPtr;
        P2CONST(uint8, AUTOMATIC, CRYPTO_30_HWA_APPL_DATA) inPtr;
        uint32 blockNo;
        uint32 idx;

        for (blockNo = 0; blockNo < blockCount; blockNo++)
        {
          idx = blockNo * CRYPTO_30_HWA_AES_BLOCK_SIZE_BYTES;
          outPtr = &outputPtr[outputWritten + idx];
          inPtr = (P2CONST(uint8, AUTOMATIC, CRYPTO_30_HWA_APPL_DATA))&inputPtr[inputProcessed + idx];
          retVal |= Crypto_30_Hwa_CtrWithEcbMode(workspace, inPtr, outPtr);
        }
      }
      else
#endif  /* (CRYPTO_30_HWA_HARDWARE_AES_CTR == STD_OFF) */
      {
        /* Process input data */
        retVal |= Crypto_30_Hwa_AesProcessBlocksSlicing(workspace, &inputPtr[inputProcessed], blockCount, &outputPtr[outputWritten]);
      }
      inputProcessed += CRYPTO_30_HWA_AES_BLOCKS_TO_BYTES(blockCount);
      outputWritten += CRYPTO_30_HWA_AES_BLOCKS_TO_BYTES(blockCount);
    }
  }

  /* Rest is not a full AES byte block, copy to workspace */
  if ((inputProcessed < inputLength) && (retVal == E_OK))
  {
    VStdLib_MemCpy(&(workspace->buffer[workspace->bufferFillLevel]), &inputPtr[inputProcessed], (inputLength - inputProcessed)); /* PRQA S 0315 */ /* MD_MSR_VStdLibCopy */
    workspace->bufferFillLevel += (inputLength - inputProcessed);
  }

  *outputLengthPtr = outputWritten;
  return retVal;
} /* Crypto_30_Hwa_AesEncUpdate() */

/**********************************************************************************************************************
 *  Crypto_30_Hwa_AesEncFinish()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 */
CRYPTO_30_HWA_LOCAL_INLINE FUNC(Std_ReturnType, CRYPTO_30_HWA_CODE) Crypto_30_Hwa_AesEncFinish(
  Crypto_30_Hwa_WorkSpaceAES_PtrType workspace,  /* PRQA S 3673 */ /* MD_MSR_Rule8.13 */
  P2VAR(uint8, AUTOMATIC, CRYPTO_30_HWA_APPL_DATA) outputPtr,
  P2VAR(uint32, AUTOMATIC, CRYPTO_30_HWA_APPL_DATA) outputLengthPtr)
{
  Std_ReturnType retVal = E_NOT_OK;
  uint32 outputWritten = 0u;

  switch (workspace->primitiveInfo->algorithm.secondaryFamily)
  {
  case CRYPTO_ALGOFAM_CUSTOM_PADDING_NONE:
    if (workspace->bufferFillLevel == 0u)
    {
      /* Nothing to do here, full blocks were already processed in update step */
      retVal = E_OK;
    }
    else if ( (workspace->primitiveInfo->algorithm.mode == CRYPTO_ALGOMODE_CTR) )
    {
      if (*outputLengthPtr < workspace->bufferFillLevel)
      {
        retVal = E_NOT_OK;
      }
      else
      {
        /* process one additional block */
#if(CRYPTO_30_HWA_HARDWARE_AES_CTR == STD_OFF) /* COV_CRYPTO_30_HWA_HARDWARE_DEPENDENT_FEATURE */
        retVal = Crypto_30_Hwa_CtrWithEcbMode(workspace, workspace->buffer, outputPtr);
#else
        SchM_Enter_Crypto_30_Hwa_CRYPTO_30_HWA_EXCLUSIVE_AREA_1();
        retVal = Crypto_30_Hwa_Hw_AesProcessBlocks(workspace, workspace->buffer, 1u, outputPtr);
        SchM_Exit_Crypto_30_Hwa_CRYPTO_30_HWA_EXCLUSIVE_AREA_1();
#endif  /* (CRYPTO_30_HWA_HARDWARE_AES_CTR == STD_OFF) */
        /* update bytes written */
        outputWritten = *outputLengthPtr;
      }
    }
    else
    {
      /* Error */
    }
    break;

  case CRYPTO_ALGOFAM_CUSTOM_PADDING_PKCS7:
    /* Handle data with PKCS7 padding */
    if ((*outputLengthPtr) >= CRYPTO_30_HWA_AES_BLOCK_SIZE_BYTES)
    {
      /* Append padding and push to hardware */
      uint32 bufferFree = CRYPTO_30_HWA_AES_BLOCK_SIZE_BYTES - workspace->bufferFillLevel;
      VStdLib_MemSet(&workspace->buffer[workspace->bufferFillLevel], (uint8)bufferFree, bufferFree); /* PRQA S 0315 */ /* MD_MSR_VStdLibCopy */
      SchM_Enter_Crypto_30_Hwa_CRYPTO_30_HWA_EXCLUSIVE_AREA_1();
      retVal = Crypto_30_Hwa_Hw_AesProcessBlocks(workspace, workspace->buffer, 1u, outputPtr);
      SchM_Exit_Crypto_30_Hwa_CRYPTO_30_HWA_EXCLUSIVE_AREA_1();
      workspace->bufferFillLevel = 0u;
      outputWritten = CRYPTO_30_HWA_AES_BLOCK_SIZE_BYTES;
    }
    break;

  default: /* COV_CRYPTO_30_HWA_CASE_DEFAULT */
    break;
  }

  /* Clean up the workspace and disable AES */
  SchM_Enter_Crypto_30_Hwa_CRYPTO_30_HWA_EXCLUSIVE_AREA_1();
  retVal |= Crypto_30_Hwa_Hw_AesFinish(workspace);
  SchM_Exit_Crypto_30_Hwa_CRYPTO_30_HWA_EXCLUSIVE_AREA_1();

  *outputLengthPtr = outputWritten;

# if (CRYPTO_30_HWA_CLEAR_WORKSPACE_BUFFERS == STD_ON)
  /* PRQA S 0315 2 */ /* MD_MSR_VStdLibCopy */
  VStdLib_MemClr(workspace->buffer, sizeof(workspace->buffer));
  VStdLib_MemClr(workspace->bufferOut, sizeof(workspace->bufferOut));
# endif

  return retVal;
} /* Crypto_30_Hwa_AesEncFinish() */

/**********************************************************************************************************************
 *  Crypto_30_Hwa_AesDecUpdate()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */
CRYPTO_30_HWA_LOCAL FUNC(Std_ReturnType, CRYPTO_30_HWA_CODE) Crypto_30_Hwa_AesDecUpdate(
  Crypto_30_Hwa_WorkSpaceAES_PtrType workspace,
  P2CONST(uint8, AUTOMATIC, CRYPTO_30_HWA_APPL_DATA) inputPtr,
  uint32 inputLength,
  P2VAR(uint8, AUTOMATIC, CRYPTO_30_HWA_APPL_DATA) outputPtr,
  P2VAR(uint32, AUTOMATIC, CRYPTO_30_HWA_APPL_DATA) outputLengthPtr)
{
  Std_ReturnType retVal = E_OK;
  uint32 inputProcessed = 0u;
  uint32 outputWritten = 0u;
  uint32 blockCount;

  /* If there is buffered output data from last update, write it to output */
  if (workspace->bufferOutFull == TRUE)
  {
    if (*outputLengthPtr >= CRYPTO_30_HWA_AES_BLOCK_SIZE_BYTES)
    {
      VStdLib_MemCpy(outputPtr, workspace->bufferOut, CRYPTO_30_HWA_AES_BLOCK_SIZE_BYTES); /* PRQA S 0315 */ /* MD_MSR_VStdLibCopy */
      outputWritten = CRYPTO_30_HWA_AES_BLOCK_SIZE_BYTES;
      workspace->bufferOutFull = FALSE;
    }
    else
    {
      retVal = E_NOT_OK;
    }
  }

  /* Calculate block count, up to one block is left over */
  blockCount = CRYPTO_30_HWA_AES_BYTES_TO_BLOCKS(workspace->bufferFillLevel + inputLength - 1u);

  if (blockCount > 0u)
  {
    if (*outputLengthPtr < (CRYPTO_30_HWA_AES_BLOCKS_TO_BYTES(blockCount) + outputWritten))
    {
      retVal = E_NOT_OK;
    }
    else
    {
      /* If there is something in the buffer, process it first */
      if (workspace->bufferFillLevel > 0u)
      {
        /* Complete buffer with input data */
        inputProcessed = (CRYPTO_30_HWA_AES_BLOCK_SIZE_BYTES - workspace->bufferFillLevel);
        VStdLib_MemCpy(&workspace->buffer[workspace->bufferFillLevel], inputPtr, inputProcessed); /* PRQA S 0315 */ /* MD_MSR_VStdLibCopy */
        SchM_Enter_Crypto_30_Hwa_CRYPTO_30_HWA_EXCLUSIVE_AREA_1();
        retVal = Crypto_30_Hwa_Hw_AesProcessBlocks(workspace, workspace->buffer, 1u, &outputPtr[outputWritten]);
        SchM_Exit_Crypto_30_Hwa_CRYPTO_30_HWA_EXCLUSIVE_AREA_1();
        blockCount--;
        workspace->bufferFillLevel = 0u;
        outputWritten += CRYPTO_30_HWA_AES_BLOCK_SIZE_BYTES;
        if (blockCount > 0u)
        {
          retVal |= Crypto_30_Hwa_AesProcessBlocksSlicing(workspace, &inputPtr[inputProcessed], blockCount, &outputPtr[outputWritten]);
        }
      }
      else
      {
        /* If there are still blocks left, process them */
        retVal = Crypto_30_Hwa_AesProcessBlocksSlicing(workspace, &inputPtr[inputProcessed], blockCount, &outputPtr[outputWritten]);
      }
      outputWritten += CRYPTO_30_HWA_AES_BLOCKS_TO_BYTES(blockCount);
      inputProcessed += CRYPTO_30_HWA_AES_BLOCKS_TO_BYTES(blockCount);
    }
  }

  /* If there is a complete block left over, process it */
  if ((inputLength + workspace->bufferFillLevel - inputProcessed) >= CRYPTO_30_HWA_AES_BLOCK_SIZE_BYTES)
  {
    /* Complete buffer with input data */
    VStdLib_MemCpy(&workspace->buffer[workspace->bufferFillLevel], &inputPtr[inputProcessed], (CRYPTO_30_HWA_AES_BLOCK_SIZE_BYTES - workspace->bufferFillLevel)); /* PRQA S 0315 */ /* MD_MSR_VStdLibCopy */

    if (workspace->primitiveInfo->algorithm.secondaryFamily == CRYPTO_ALGOFAM_CUSTOM_PADDING_NONE)
    {
      /* No padding used, write data to output */
      if ((*outputLengthPtr - outputWritten) >= CRYPTO_30_HWA_AES_BLOCK_SIZE_BYTES)
      {
        retVal |= Crypto_30_Hwa_AesProcessBlocksSlicing(workspace, workspace->buffer, 1u, &outputPtr[outputWritten]);
        outputWritten += CRYPTO_30_HWA_AES_BLOCK_SIZE_BYTES;
        inputProcessed += CRYPTO_30_HWA_AES_BLOCK_SIZE_BYTES;
      }
      else
      {
        /* Output length too small */
        retVal = E_NOT_OK;
      }
    }
    else
    {
      /* Padding used, store data in workspace */
      retVal |= Crypto_30_Hwa_AesProcessBlocksSlicing(workspace, workspace->buffer, 1u, workspace->bufferOut);
      workspace->bufferOutFull = TRUE;
      inputProcessed += CRYPTO_30_HWA_AES_BLOCK_SIZE_BYTES;
    }
    workspace->bufferFillLevel = 0u;
  }

  /* The rest is not a full AES block, copy to buffer */
  if ((inputProcessed < inputLength) && (retVal == E_OK))
  {
    VStdLib_MemCpy(&(workspace->buffer[workspace->bufferFillLevel]), &inputPtr[inputProcessed], (inputLength - inputProcessed)); /* PRQA S 0315 */ /* MD_MSR_VStdLibCopy */
    workspace->bufferFillLevel += (inputLength - inputProcessed);
  }

  *outputLengthPtr = outputWritten;
  return retVal;
} /* Crypto_30_Hwa_AesDecUpdate() */ /* PRQA S 6010, 6030 */ /* MD_MSR_STPTH, MD_MSR_STCYC */

/**********************************************************************************************************************
 *  Crypto_30_Hwa_AesDecFinish()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 */
CRYPTO_30_HWA_LOCAL_INLINE FUNC(Std_ReturnType, CRYPTO_30_HWA_CODE) Crypto_30_Hwa_AesDecFinish(
  Crypto_30_Hwa_WorkSpaceAES_PtrType workspace, /* PRQA S 3673 */ /* MD_MSR_Rule8.13 */
  P2VAR(uint8, AUTOMATIC, CRYPTO_30_HWA_APPL_DATA) outputPtr,
  P2VAR(uint32, AUTOMATIC, CRYPTO_30_HWA_APPL_DATA) outputLengthPtr)
{
  Std_ReturnType retVal = E_NOT_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */
  uint8 msgSize;
  uint8_least i;
  uint8 paddingByte;
  boolean paddingError;
  uint32 outputWritten = 0u;

  /* Check for multiple of blocksize */
  if (workspace->bufferFillLevel == 0u)
  {
    switch (workspace->primitiveInfo->algorithm.secondaryFamily)
    {
    case CRYPTO_ALGOFAM_CUSTOM_PADDING_NONE:
      /* Nothing to do here, full blocks were already processed in update step */
      retVal = E_OK;
      break;

    case CRYPTO_ALGOFAM_CUSTOM_PADDING_PKCS7:
      /* Read and verify padding */
      paddingByte = workspace->bufferOut[CRYPTO_30_HWA_AES_BLOCK_SIZE_BYTES - 1u];
      paddingError = (boolean)((paddingByte == 0u) || (paddingByte > CRYPTO_30_HWA_AES_BLOCK_SIZE_BYTES));
      for (i = (uint8)(CRYPTO_30_HWA_AES_BLOCK_SIZE_BYTES - paddingByte); i < CRYPTO_30_HWA_AES_BLOCK_SIZE_BYTES; i++)
      {
        if (workspace->bufferOut[i] != paddingByte)
        {
          paddingError = TRUE;
        }
      }
      if (paddingError == FALSE)
      {
        msgSize = (uint8)(CRYPTO_30_HWA_AES_BLOCK_SIZE_BYTES - paddingByte);
        if (msgSize > 0u)
        {
          if (*outputLengthPtr >= msgSize)
          {
            /* Copy part of buffered block to output */
            VStdLib_MemCpy(outputPtr, workspace->bufferOut, msgSize); /* PRQA S 0315 */ /* MD_MSR_VStdLibCopy */
            outputWritten = msgSize;
            retVal = E_OK;
          }
          else
          {
            /* output size not sufficient */
          }
        }
        else
        {
          /* The whole block is padding */
          outputWritten = 0u;
          retVal = E_OK;
        }
      }
      else
      {
        /* padding error */
      }
      break;

    default: /* COV_CRYPTO_30_HWA_CASE_DEFAULT */
      break;
    }
  }

  /* Clean up the workspace and disable AES */
  SchM_Enter_Crypto_30_Hwa_CRYPTO_30_HWA_EXCLUSIVE_AREA_1();
  retVal |= Crypto_30_Hwa_Hw_AesFinish(workspace);
  SchM_Exit_Crypto_30_Hwa_CRYPTO_30_HWA_EXCLUSIVE_AREA_1();

  *outputLengthPtr = outputWritten;

# if (CRYPTO_30_HWA_CLEAR_WORKSPACE_BUFFERS == STD_ON)
  /* PRQA S 0315 2 */ /* MD_MSR_VStdLibCopy */
  VStdLib_MemClr(workspace->buffer, sizeof(workspace->buffer));
  VStdLib_MemClr(workspace->bufferOut, sizeof(workspace->bufferOut));
# endif

  return retVal;
} /* Crypto_30_Hwa_AesDecFinish() */ /* PRQA S 6010, 6080 */ /* MD_MSR_STPTH, MD_MSR_STMIF */
#endif /* (CRYPTO_30_HWA_PRIMITIVE_AES_CIPHER == STD_ON) */

#define CRYPTO_30_HWA_STOP_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/
#define CRYPTO_30_HWA_START_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#if(CRYPTO_30_HWA_PRIMITIVE_AES_CIPHER == STD_ON) /* COV_CRYPTO_30_HWA_HARDWARE_DEPENDENT_FEATURE */
/**********************************************************************************************************************
 *  Crypto_30_Hwa_ProcessAesJob()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */
FUNC(Std_ReturnType, CRYPTO_30_HWA_CODE) Crypto_30_Hwa_ProcessAesJob(
  uint32 objectId,
  P2VAR(uint8, AUTOMATIC, CRYPTO_30_HWA_APPL_DATA) errorIdPtr,
  Crypto_30_Hwa_JobPtrType job,
  Crypto_30_Hwa_WorkSpaceAES_PtrType workspace)
{
  Std_ReturnType retVal = E_NOT_OK;

  /* #10 Verify whether primitive info is correct */
  if (Crypto_30_Hwa_CheckCipherPrimitiveInfo(job) == E_OK)
  {
    /* [SWS_Crypto_00017] [SWS_Crypto_00020] START while IDLE or ACTIVE */
    if (((job->state == CRYPTO_JOBSTATE_IDLE) || (job->state == CRYPTO_JOBSTATE_ACTIVE))
      && Crypto_30_Hwa_IsJobMode(job, CRYPTO_OPERATIONMODE_START))
    {
      /* #20 Prepare workspace  */
      workspace->primitiveInfo = job->jobPrimitiveInfo->primitiveInfo;
      workspace->driverObjectId = objectId;

      /* #21 Call start operation */
      retVal = Crypto_30_Hwa_AesStart(workspace, job->cryptoKeyId);
      Crypto_30_Hwa_UpdateJobState(retVal, job); /* SBSW_CRYPTO_30_HWA_FORWARDING_OF_JOB_PTR */
    }

    /* UPDATE while ACTIVE */
    if ((job->state == CRYPTO_JOBSTATE_ACTIVE)
      && Crypto_30_Hwa_IsJobMode(job, CRYPTO_OPERATIONMODE_UPDATE)) /* [SWS_Crypto_00024] */
    {
      uint32 tmpOutputLength = *job->jobPrimitiveInputOutput.outputLengthPtr;

      /* #30 Call update operation */
      /* Ensure that if CTR Mode is enabled we go to encryption in both cases ENCRYPT/DECRYPT */
      if ((job->jobPrimitiveInfo->primitiveInfo->service == CRYPTO_ENCRYPT)
        || (workspace->primitiveInfo->algorithm.mode == CRYPTO_ALGOMODE_CTR))
      {
        retVal = Crypto_30_Hwa_AesEncUpdate(workspace,
          job->jobPrimitiveInputOutput.inputPtr, job->jobPrimitiveInputOutput.inputLength,
          job->jobPrimitiveInputOutput.outputPtr, &tmpOutputLength);
      }
      else if (job->jobPrimitiveInfo->primitiveInfo->service == CRYPTO_DECRYPT)
      {
        retVal = Crypto_30_Hwa_AesDecUpdate(workspace,
          job->jobPrimitiveInputOutput.inputPtr, job->jobPrimitiveInputOutput.inputLength,
          job->jobPrimitiveInputOutput.outputPtr, &tmpOutputLength);
      }
      else
      {
        /* Not supported service */
      }

      /* #31 Handle output length information */
      if (Crypto_30_Hwa_IsJobMode(job, CRYPTO_OPERATIONMODE_FINISH))
      {
        /* For single call store output length in workspace */
        workspace->outputLength += tmpOutputLength;
      }
      else
      {
        *job->jobPrimitiveInputOutput.outputLengthPtr = tmpOutputLength;
      }
      Crypto_30_Hwa_UpdateJobState(retVal, job); /* SBSW_CRYPTO_30_HWA_FORWARDING_OF_JOB_PTR */
    }

    /* [SWS_Crypto_00023] FINISH while ACTIVE */
    if ((job->state == CRYPTO_JOBSTATE_ACTIVE)
      && Crypto_30_Hwa_IsJobMode(job, CRYPTO_OPERATIONMODE_FINISH)) /* [SWS_Crypto_00024] */
    {
      /* #40 For single call: calculate remaining output length and new position in output buffer */
      uint32 tmpOutputLength = (*job->jobPrimitiveInputOutput.outputLengthPtr) - workspace->outputLength;
      uint8 *tmpOutputPtr = &(job->jobPrimitiveInputOutput.outputPtr[workspace->outputLength]);

      /* #41 Call finish operation */
      /* Ensure that if CTR Mode is enabled we go to encryption in both cases ENCRYPT/DECRYPT */
      if ((job->jobPrimitiveInfo->primitiveInfo->service == CRYPTO_ENCRYPT)
        || (workspace->primitiveInfo->algorithm.mode == CRYPTO_ALGOMODE_CTR))
      {
        retVal = Crypto_30_Hwa_AesEncFinish(workspace, tmpOutputPtr, &tmpOutputLength);
      }
      else if (job->jobPrimitiveInfo->primitiveInfo->service == CRYPTO_DECRYPT)
      {
        retVal = Crypto_30_Hwa_AesDecFinish(workspace, tmpOutputPtr, &tmpOutputLength);
      }
      else
      {
        /* Not supported service */
      }

      /* #42 Handle output length information */
      *job->jobPrimitiveInputOutput.outputLengthPtr = tmpOutputLength;
      if (Crypto_30_Hwa_IsJobMode(job, CRYPTO_OPERATIONMODE_UPDATE))
      {
        /* For single call, calculate written output length */
        *job->jobPrimitiveInputOutput.outputLengthPtr += workspace->outputLength;
      }
      job->state = CRYPTO_JOBSTATE_IDLE; /* SBSW_CRYPTO_30_HWA_DIRECT_ACCESS_TO_JOB_STATE */
    }

    *errorIdPtr = CRYPTO_E_NO_ERROR;
  }

  return retVal;
} /* Crypto_30_Hwa_ProcessAesJob() */ /* PRQA S 6010, 6030 */ /* MD_MSR_STCYC, MD_MSR_STPTH */
#endif /* (CRYPTO_30_HWA_PRIMITIVE_AES_CIPHER == STD_ON) */

#define CRYPTO_30_HWA_STOP_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  END OF FILE: Crypto_30_Hwa_Cipher.c
 *********************************************************************************************************************/
