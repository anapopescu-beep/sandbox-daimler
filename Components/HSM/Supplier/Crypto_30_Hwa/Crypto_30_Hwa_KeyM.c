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
/*!        \file  Crypto_30_Hwa_KeyM.c
 *        \brief  Crypto Hwa Key Management implementation
 *
 *      \details  This implements the Key Management API.
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 *********************************************************************************************************************/

#define CRYPTO_30_HWA_KEYM_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

#include "Crypto_30_Hwa.h"
#include "Crypto_30_Hwa_Private.h"
#include "Crypto_30_Hwa_Custom.h"

#include "vHsm_ApiInternal.h"
#include "CryIf.h"
#include "vstdlib.h"

/**********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 *********************************************************************************************************************/
#if !defined (CRYPTO_30_HWA_LOCAL) /* COV_CRYPTO_30_HWA_LOCAL_DEFINE */
# define CRYPTO_30_HWA_LOCAL                                              static
#endif

 /* Defines KeyDerivation */
#define CRYPTO_30_HWA_KEYDERIVATION_ALGORITHM_SIZE_BLOCKS                   (1u)

#if !defined (CRYPTO_30_HWA_LOCAL_INLINE) /* COV_CRYPTO_30_HWA_LOCAL_DEFINE */
# define CRYPTO_30_HWA_LOCAL_INLINE                                       LOCAL_INLINE
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

#if (CRYPTO_30_HWA_KEY_DERIVE == STD_ON)
/**********************************************************************************************************************
 *  Crypto_30_Hwa_GetKeyElementPtr()
 *********************************************************************************************************************/
/*! \brief         Returns an pointer to the data of the requested keyelement of the given key.
 *  \details       Returns an pointer to the data of the requested keyelement of the given key. The length of the data
 *                 in the keyelement is written to the resultLengthPtr.
 *  \param[in]     cryptoKeyId                     The Id of the Key
 *  \param[in]     cryptoKeyElementId              The Id of the Element
 *  \param[in,out] resultLengthPtr                 Input:  The max number of expected elements. Output: The actual
 *                                                 number of elements.
 *  \return        returns a pointer to the keyelement data
 *  \pre           -
 *  \context       TASK
 *  \reentrant     TRUE, for different crypto keys.
 *  \synchronous   TRUE
 *********************************************************************************************************************/
CRYPTO_30_HWA_LOCAL FUNC(P2VAR(uint8, AUTOMATIC, CRYPTO_30_HWA_APPL_DATA), CRYPTO_30_HWA_CODE) Crypto_30_Hwa_GetKeyElementPtr(
  uint32 cryptoKeyId,
  uint32 cryptoKeyElementId,
  P2VAR(uint32, AUTOMATIC, AUTOMATIC) resultLengthPtr);

/**********************************************************************************************************************
 *  Crypto_30_Hwa_GetNumberKdfIterations()
 *********************************************************************************************************************/
/*! \brief         Calculates the required number of iterations to reach the key length
 *  \details       Calculates the required number of iterations to reach the key length
 *  \param[out]    numberOfIterations            number of Iterations integer length.
 *  \param[in]     targetKeyLengthNumeric        Required target key length in Bits
 *  \pre           -
 *  \context       TASK
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
CRYPTO_30_HWA_LOCAL_INLINE FUNC(void, CRYPTO_30_HWA_CODE) Crypto_30_Hwa_GetNumberKdfIterations(
  P2VAR(uint32, AUTOMATIC, AUTOMATIC) numberOfIterations,
  uint32 targetKeyLengthNumeric);

/**********************************************************************************************************************
 *  Crypto_30_Hwa_GetKeyDerivationFromCMAC()
 *********************************************************************************************************************/
/*! \brief         Derives a Key from a given source Key
 *  \details       Initializes a temporary CMAC Job with the given source key and Input. Concatenates the output until the
 *                 requested length is reached.
 *  \param[in]     cryptoKeyId                   The ID of the Source Key
 *  \param[in]     numberOfIterations            The number of iterations to reach the requested keylength
 *  \param[in,out] inputData                     The concatenated input data. (label||0x00||context||[L])
 *  \param[in]     inputSizeBlocks               Size of the inputData-Array in Byte
 *  \param[in]     targetKeyLengthNumeric        The length of the requested key in bits
 *  \param[out]    targetKey                     Array to store the derived Key
 *  \param[out]    blocksWrittenToTargetKey      The number of blocks which were written to the targetkey array
 *  \return        E_OK                          Request successful.
 *                 E_NOT_OK                      Request failed.
 *  \pre           The source key has to be valid. CMAC has to be enabled.
 *  \context       TASK
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
CRYPTO_30_HWA_LOCAL_INLINE FUNC(Std_ReturnType, CRYPTO_30_HWA_CODE) Crypto_30_Hwa_GetKeyDerivationFromCMAC(
  uint32 cryptoKeyId,
  uint32 numberOfIterations,
  P2VAR(uint8, AUTOMATIC, AUTOMATIC) inputData,
  uint32 inputSizeBlocks,
  uint32 targetKeyLengthNumeric,
  P2VAR(uint8, AUTOMATIC, AUTOMATIC) targetKey,
  P2VAR(uint32, AUTOMATIC, AUTOMATIC) blocksWrittenToTargetKey
);

/**********************************************************************************************************************
 *  Crypto_30_Hwa_SetupTempCmacJob()
 *********************************************************************************************************************/
/*! \brief         Initializes a CMAC Temp Job
 *  \details       Initializes a temporary CMAC Job. Connect the TmpJob Structure to the given pointers and set the
 *                 parameters for the CMAC.
 *  \param[out]    tmpCMACJob                    Pointer to the temp job structure, which becomes initialized
 *  \param[in]     cryptoKeyId                   The ID of the Source Key
 *  \param[in]     inputDataPtr                  The concatenated input data. (label||0x00||context||[L])
 *  \param[in]     inputLength                   Size of the inputData-Array in Byte
 *  \param[out]    outputDataPtr                 Array to store the derived Key
 *  \param[out]    outputLength                  The Size of the OutputData-Array
 *  \pre           -
 *  \context       TASK
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
CRYPTO_30_HWA_LOCAL_INLINE FUNC(void, CRYPTO_30_HWA_CODE) Crypto_30_Hwa_SetupTempCmacJob(
  P2VAR(vHsm_Api_TempJobType, AUTOMATIC, CRYPTO_30_HWA_APPL_VAR) tmpCMACJob,
  uint32 cryptoKeyId,
  P2CONST(uint8, AUTOMATIC, CRYPTO_30_HWA_APPL_DATA) inputDataPtr,
  uint32 inputLength,
  P2VAR(uint8, AUTOMATIC, CRYPTO_30_HWA_APPL_VAR) outputDataPtr,
  P2VAR(uint32, AUTOMATIC, CRYPTO_30_HWA_APPL_VAR) outputLength
);

/**********************************************************************************************************************
 *  Crypto_30_Hwa_UintToArray()
 *********************************************************************************************************************/
/*! \brief         Splits a integer to the coresponding uint8 outputArray.
 *  \details       Using shift operation to split the integer.
 *  \param[in]     integerInput                  The integer variable to be splitted
 *  \param[out]    outputArray                         Pointer to the uint8 outputArray
 *  \param[in]     arrayLength                   Length of the outputArray in Bytes. The length should corespond to the integer length.
 *  \pre           -
 *  \context       TASK
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
CRYPTO_30_HWA_LOCAL_INLINE FUNC(void, CRYPTO_30_HWA_CODE) Crypto_30_Hwa_UintToArray(
  uint32 integerInput,
  P2VAR(uint8, AUTOMATIC, CRYPTO_30_HWA_APPL_DATA) outputArray,
  uint32 arrayLength);

/**********************************************************************************************************************
 *  Crypto_30_Hwa_ConcatenateKDFInputString()
 *********************************************************************************************************************/
/*! \brief         Concatenate the input for the keyderivation
 *  \details       Concatenate the label, zero octet, context
 *  \param[in]     cryptoKeyId                   The key id of the key to derive from
 *  \param[out] inputString                      Input string for the KDF. The elemnts are concatenated inside.
 *  \param[in,out] iterator                      Points where to write in the inputString. On return gives the
 *                                               actual length of the inputString back.
 *  \return        E_OK                          Request successful.
 *  \pre           -
 *  \context       TASK
 *  \reentrant     TRUE, on different cryptoKeyId
 *  \synchronous   TRUE
 *********************************************************************************************************************/
CRYPTO_30_HWA_LOCAL_INLINE FUNC(Std_ReturnType, CRYPTO_30_HWA_CODE) Crypto_30_Hwa_ConcatenateKDFInputString(
  uint32 cryptoKeyId,
  P2VAR(uint8, AUTOMATIC, AUTOMATIC) inputString,
  P2VAR(uint32, AUTOMATIC, AUTOMATIC) iterator);

#endif /* CRYPTO_30_HWA_KEY_DERIVE */

#define CRYPTO_30_HWA_STOP_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

#define CRYPTO_30_HWA_START_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  Crypto_30_Hwa_KeyValidSet()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(Std_ReturnType, CRYPTO_30_HWA_CODE) Crypto_30_Hwa_KeyValidSet(uint32 cryptoKeyId)
{
  Std_ReturnType retVal = E_NOT_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */
#if (CRYPTO_30_HWA_ROMKEY == STD_ON) /* COV_CRYPTO_30_HWA_HARDWARE_DEPENDENT_FEATURE */
  uint32 cryptoKeyIdTemp = cryptoKeyId;

  if (Crypto_30_Hwa_CheckAggregatedKeyId(&cryptoKeyIdTemp) == E_OK)
  {
    retVal = vHsm_Api_KeyValidSet(cryptoKeyIdTemp);
  }
#else
  retVal = vHsm_Api_KeyValidSet(cryptoKeyId);
#endif

  return retVal;
} /* Crypto_30_Hwa_KeyValidSet() */

/**********************************************************************************************************************
 *  Crypto_30_Hwa_CheckAggregatedKeyId()
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
FUNC(Std_ReturnType, CRYPTO_30_HWA_CODE) Crypto_30_Hwa_CheckAggregatedKeyId(P2VAR(uint32, AUTOMATIC, CRYPTO_30_HWA_APPL_DATA) cryptoKeyIdPtr) /* PRQA S 3673 */ /* MD_MSR_Rule8.13 */
{
  Std_ReturnType retVal = E_NOT_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

#if (CRYPTO_30_HWA_ROMKEY == STD_ON) /* COV_CRYPTO_30_HWA_HARDWARE_DEPENDENT_FEATURE */

  /* #10 Verify if key is ROM_KEY or LibCv_Key */
  if (*cryptoKeyIdPtr >= CRYPTO_30_HWA_ROMKEY_MASK)
  {
    /* #11 Verify if ROM_KEY has valid key and if ROM_KEY has aggregated key set */
    if (((*cryptoKeyIdPtr - CRYPTO_30_HWA_ROMKEY_MASK) < Crypto_30_Hwa_GetSizeOfKeyMap()) && ((Crypto_30_Hwa_GetAggregatedCryptoKeyIdOfKeyMap(*cryptoKeyIdPtr - CRYPTO_30_HWA_ROMKEY_MASK)) != 0xFFFFFFFFu))
    {
      /* #12 Get key ID for aggregated key */
      *cryptoKeyIdPtr = Crypto_30_Hwa_GetAggregatedCryptoKeyIdOfKeyMap(*cryptoKeyIdPtr - CRYPTO_30_HWA_ROMKEY_MASK);
      retVal = E_OK;
    }
    else
    {
      /* #15 ROM_KEY has no aggregated key set, return error */
      retVal = E_NOT_OK;
    }
  }
  else
#else
  CRYPTO_30_HWA_DUMMY_STATEMENT(cryptoKeyIdPtr); /* PRQA S 1338, 2983 */ /* MD_MSR_DummyStmt */
#endif /* (CRYPTO_30_HWA_ROMKEY == STD_ON) */
  {
    /* #20 Key is LibCV_Key, no further action needed */
    retVal = E_OK;
  }

  return retVal;
} /* Crypto_30_Hwa_CheckAggregatedKeyId() */

#if (CRYPTO_30_HWA_KEY_DERIVE == STD_ON)
/**********************************************************************************************************************
 *  Crypto_30_Hwa_GetKeyElementPtr()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
CRYPTO_30_HWA_LOCAL FUNC(P2VAR(uint8, AUTOMATIC, CRYPTO_30_HWA_APPL_DATA), CRYPTO_30_HWA_CODE) Crypto_30_Hwa_GetKeyElementPtr(
  uint32 cryptoKeyId,
  uint32 cryptoKeyElementId,
  P2VAR(uint32, AUTOMATIC, AUTOMATIC) resultLengthPtr)
{
  vHsm_Api_KeyStorageIndexType keyElementIndex;
  P2VAR(uint8, AUTOMATIC, CRYPTO_30_HWA_APPL_DATA) keyElementPtr;
  Std_ReturnType retVal;

  /* Get index of key element from key */
  retVal = vHsm_Api_Local_KeyElementGetStorageIndex(cryptoKeyId, cryptoKeyElementId, &keyElementIndex, resultLengthPtr,
    VHSM_API_LENGTH_CHECK_MAX);

  /* Check if context is valid */
  if (retVal != E_OK)
  {
    *resultLengthPtr = 0u;
    keyElementPtr = NULL_PTR;
  }
  else
  {
    keyElementPtr = vHsm_Api_GetAddrKeyStorage(keyElementIndex);
  }

  return keyElementPtr;
}

/**********************************************************************************************************************
 *  Crypto_30_Hwa_GetNumberKdfIterations()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
CRYPTO_30_HWA_LOCAL_INLINE FUNC(void, CRYPTO_30_HWA_CODE) Crypto_30_Hwa_GetNumberKdfIterations(
  P2VAR(uint32, AUTOMATIC, AUTOMATIC) numberOfIterations,
  uint32 targetKeyLengthNumeric)
{
  /* Calculate the number of iterations for the required keylength */
  if ((targetKeyLengthNumeric % CRYPTO_30_HWA_AES_BLOCK_SIZE_BITS) == 0u)
  {
    *numberOfIterations = (uint32)(targetKeyLengthNumeric / CRYPTO_30_HWA_AES_BLOCK_SIZE_BITS);
  }
  else
  {
    *numberOfIterations = (uint32)(targetKeyLengthNumeric / CRYPTO_30_HWA_AES_BLOCK_SIZE_BITS) + 1u;
  }
}

/**********************************************************************************************************************
 *  Crypto_30_Hwa_GetKeyDerivationFromCMAC()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 */
CRYPTO_30_HWA_LOCAL_INLINE FUNC(Std_ReturnType, CRYPTO_30_HWA_CODE) Crypto_30_Hwa_GetKeyDerivationFromCMAC(
  uint32 cryptoKeyId,
  uint32 numberOfIterations,
  P2VAR(uint8, AUTOMATIC, AUTOMATIC) inputData,
  uint32 inputSizeBlocks,
  uint32 targetKeyLengthNumeric,
  P2VAR(uint8, AUTOMATIC, AUTOMATIC) targetKey,
  P2VAR(uint32, AUTOMATIC, AUTOMATIC) blocksWrittenToTargetKey)
{
  Std_ReturnType retVal = E_OK;
  uint8 keyBuffer[CRYPTO_30_HWA_AES_BLOCK_SIZE_BYTES];

  uint32 keyBytesLeft;
  vHsm_Api_TempJobType tempCMACJob;
  uint32 outputlength = CRYPTO_30_HWA_AES_BLOCK_SIZE_BYTES;
  uint32 counter;

  for (counter = 1u; counter <= numberOfIterations; counter++)                                                      /* PRQA S 1338 */ /* MD_MSR_DummyStmt */
  {
    /* Split counter to Array */
    Crypto_30_Hwa_UintToArray(counter, inputData, CRYPTO_30_HWA_SIZE_OF_ITERATION_COUNTER);

    /* Perform CMAC Job */
    Crypto_30_Hwa_SetupTempCmacJob(&tempCMACJob, cryptoKeyId, inputData, inputSizeBlocks, keyBuffer, &outputlength);
    retVal = vHsm_Api_ProcessTempJob(CRYPTO_30_HWA_KEY_DERIVE_CRYIF_CHANNEL, &tempCMACJob);
    if (retVal != E_OK)
    {
      break;
    }
    if (counter == numberOfIterations)
    {
      if ((targetKeyLengthNumeric % CRYPTO_30_HWA_AES_BLOCK_SIZE_BITS) == 0u)
      {
        VStdLib_MemCpy(&targetKey[*blocksWrittenToTargetKey], keyBuffer, CRYPTO_30_HWA_AES_BLOCK_SIZE_BYTES);      /* PRQA S 0315 */ /* MD_MSR_VStdLibCopy */
        *blocksWrittenToTargetKey += CRYPTO_30_HWA_AES_BLOCK_SIZE_BYTES;
      }
      else
      {
        keyBytesLeft = (uint32)((targetKeyLengthNumeric % CRYPTO_30_HWA_AES_BLOCK_SIZE_BITS) / 8u);
        VStdLib_MemCpy(&targetKey[*blocksWrittenToTargetKey], keyBuffer, keyBytesLeft);                           /* PRQA S 0315 */ /* MD_MSR_VStdLibCopy */
        *blocksWrittenToTargetKey += keyBytesLeft;
      }
    }
    else
    {
      VStdLib_MemCpy(&targetKey[*blocksWrittenToTargetKey], keyBuffer, CRYPTO_30_HWA_AES_BLOCK_SIZE_BYTES);        /* PRQA S 0315 */ /* MD_MSR_VStdLibCopy */
      *blocksWrittenToTargetKey += CRYPTO_30_HWA_AES_BLOCK_SIZE_BYTES;
    }
  }

  return retVal;
} /* PRQA S 6060 */ /* MD_MSR_STPAR */

/**********************************************************************************************************************
 *  Crypto_30_Hwa_SetupTempCmacJob()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
CRYPTO_30_HWA_LOCAL_INLINE FUNC(void, CRYPTO_30_HWA_CODE) Crypto_30_Hwa_SetupTempCmacJob(
  P2VAR(vHsm_Api_TempJobType, AUTOMATIC, CRYPTO_30_HWA_APPL_VAR) tmpCMACJob,
  uint32 cryptoKeyId,
  P2CONST(uint8, AUTOMATIC, CRYPTO_30_HWA_APPL_DATA) inputDataPtr,
  uint32 inputLength,
  P2VAR(uint8, AUTOMATIC, CRYPTO_30_HWA_APPL_VAR) outputDataPtr,
  P2VAR(uint32, AUTOMATIC, CRYPTO_30_HWA_APPL_VAR) outputLength)
{
  vHsm_Api_InitializeTempJob(tmpCMACJob, cryptoKeyId);
  vHsm_Api_TempJob_SetPrimitive(tmpCMACJob,
    CRYPTO_MACGENERATE,
    CRYPTO_ALGOFAM_AES,
    CRYPTO_ALGOMODE_CMAC,
    CRYPTO_ALGOFAM_NOT_SET);

  tmpCMACJob->job.jobPrimitiveInputOutput.mode = CRYPTO_OPERATIONMODE_SINGLECALL;
  tmpCMACJob->job.jobPrimitiveInputOutput.inputPtr = inputDataPtr;
  tmpCMACJob->job.jobPrimitiveInputOutput.inputLength = inputLength;
  tmpCMACJob->job.jobPrimitiveInputOutput.outputPtr = outputDataPtr;
  tmpCMACJob->job.jobPrimitiveInputOutput.outputLengthPtr = outputLength;
} /* PRQA S 6060 */ /* MD_MSR_STPAR */

/**********************************************************************************************************************
 *  Crypto_30_Hwa_UintToArray()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
CRYPTO_30_HWA_LOCAL_INLINE FUNC(void, CRYPTO_30_HWA_CODE) Crypto_30_Hwa_UintToArray(
  uint32 integerInput,
  P2VAR(uint8, AUTOMATIC, CRYPTO_30_HWA_APPL_DATA) outputArray,
  uint32 arrayLength)
{
  uint8 i;
  for (i = 0u; i < arrayLength; i++)
  {
    outputArray[arrayLength - 1u - i] = (uint8)(integerInput >> (i * 8u));
  }
}

/**********************************************************************************************************************
 *  Crypto_30_Hwa_ConcatenateKDFInputString()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
CRYPTO_30_HWA_LOCAL_INLINE FUNC(Std_ReturnType, CRYPTO_30_HWA_CODE) Crypto_30_Hwa_ConcatenateKDFInputString(
  uint32 cryptoKeyId,
  P2VAR(uint8, AUTOMATIC, AUTOMATIC) inputString,
  P2VAR(uint32, AUTOMATIC, AUTOMATIC) iterator)
{
  Std_ReturnType retVal = E_OK;
  uint32 keyElementDataLength;
  P2CONST(uint8, AUTOMATIC, CRYPTO_30_HWA_APPL_DATA) keyElementDataPtr;

  keyElementDataLength = CRYPTO_30_HWA_MAX_INPUT_LENGTH;
  keyElementDataPtr = Crypto_30_Hwa_GetKeyElementPtr(cryptoKeyId, CRYPTO_KE_KEYDERIVATION_LABEL, &keyElementDataLength);

  /* check if the elements fit into the inputData array  (+1u for zero octet)*/
  if ((keyElementDataLength + CRYPTO_30_HWA_SIZE_OF_ITERATION_COUNTER + CRYPTO_30_HWA_SIZE_OF_TARGET_KEY_LENGTH + 1u) > CRYPTO_30_HWA_MAX_INPUT_LENGTH)
  {
    retVal = E_NOT_OK;
  }
  else
  {
    /* Add the label to the fixed input data */
    VStdLib_MemCpy(&inputString[*iterator], keyElementDataPtr, keyElementDataLength);  /* PRQA S 0315 */ /* MD_MSR_VStdLibCopy */
    *iterator += keyElementDataLength;

#if(CRYPTO_30_HWA_ADD_ZERO_OCTET == STD_ON)
    /* Add the zero octet to the fixed input data */
    inputString[*iterator] = 0x00u;
    *iterator += 1u;
#endif

    keyElementDataLength = CRYPTO_30_HWA_MAX_INPUT_LENGTH;
    keyElementDataPtr = Crypto_30_Hwa_GetKeyElementPtr(cryptoKeyId, CRYPTO_KE_KEYDERIVATION_CONTEXT, &keyElementDataLength);

    if ((keyElementDataLength + *iterator + CRYPTO_30_HWA_SIZE_OF_TARGET_KEY_LENGTH) > CRYPTO_30_HWA_MAX_INPUT_LENGTH)
    {
      retVal = E_NOT_OK;
    }
    else
    {
      /* Add the context to the fixed input data */
      VStdLib_MemCpy(&inputString[*iterator], keyElementDataPtr, keyElementDataLength);  /* PRQA S 0315 */ /* MD_MSR_VStdLibCopy */
      *iterator += keyElementDataLength;
    }
  }
  return retVal;
}
#endif /* CRYPTO_30_HWA_KEY_DERIVE */

#define CRYPTO_30_HWA_STOP_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/

#define CRYPTO_30_HWA_START_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  Crypto_30_Hwa_KeyElementSet()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(Std_ReturnType, CRYPTO_30_HWA_CODE) Crypto_30_Hwa_KeyElementSet(
  uint32 cryptoKeyId,
  uint32 keyElementId,
  P2CONST(uint8, AUTOMATIC, CRYPTO_30_HWA_APPL_DATA) keyPtr,
  uint32 keyLength)
{
  Std_ReturnType retVal = E_NOT_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */
#if (CRYPTO_30_HWA_ROMKEY == STD_ON) /* COV_CRYPTO_30_HWA_HARDWARE_DEPENDENT_FEATURE */
  uint32 cryptoKeyIdTemp = cryptoKeyId;
#endif

  /* Filter for custom key elements */
  retVal = Crypto_30_Hwa_Hw_KeyElementSet(cryptoKeyId, keyElementId, keyPtr, keyLength);

  /* Not filtered */
  if (retVal == CRYPTO_E_NOT_HANDLED)
  {
    /* Forward request to LibCv */
#if (CRYPTO_30_HWA_ROMKEY == STD_ON) /* COV_CRYPTO_30_HWA_HARDWARE_DEPENDENT_FEATURE */
    if (Crypto_30_Hwa_CheckAggregatedKeyId(&cryptoKeyIdTemp) == E_OK)
    {
      retVal = vHsm_Api_KeyElementSet(cryptoKeyIdTemp, keyElementId, keyPtr, keyLength);
    }
#else
    retVal = vHsm_Api_KeyElementSet(cryptoKeyId, keyElementId, keyPtr, keyLength);
#endif
  }

  return retVal;
} /* Crypto_30_Hwa_KeyElementSet() */

/**********************************************************************************************************************
 *  Crypto_30_Hwa_KeyElementGet()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(Std_ReturnType, CRYPTO_30_HWA_CODE) Crypto_30_Hwa_KeyElementGet(
  uint32 cryptoKeyId,
  uint32 keyElementId,
  P2VAR(uint8, AUTOMATIC, CRYPTO_30_HWA_APPL_DATA) resultPtr,
  P2VAR(uint32, AUTOMATIC, CRYPTO_30_HWA_APPL_DATA) resultLengthPtr)
{
  Std_ReturnType retVal = E_NOT_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */
#if (CRYPTO_30_HWA_ROMKEY == STD_ON) /* COV_CRYPTO_30_HWA_HARDWARE_DEPENDENT_FEATURE */
  uint32 cryptoKeyIdTemp = cryptoKeyId;
#endif

  /* Filter for custom key elements */
  retVal = Crypto_30_Hwa_Hw_KeyElementGet(cryptoKeyId, keyElementId, resultPtr, resultLengthPtr);

  /* Not filtered */
  if (retVal == CRYPTO_E_NOT_HANDLED)
  {
    /* Forward request to LibCv */
#if (CRYPTO_30_HWA_ROMKEY == STD_ON) /* COV_CRYPTO_30_HWA_HARDWARE_DEPENDENT_FEATURE */
    if (Crypto_30_Hwa_CheckAggregatedKeyId(&cryptoKeyIdTemp) == E_OK)
    {
      retVal = vHsm_Api_KeyElementGet(cryptoKeyIdTemp, keyElementId, resultPtr, resultLengthPtr);
    }
#else
    retVal = vHsm_Api_KeyElementGet(cryptoKeyId, keyElementId, resultPtr, resultLengthPtr);
#endif
  }

  return retVal;
} /* Crypto_30_Hwa_KeyElementGet() */

/**********************************************************************************************************************
 *  Crypto_30_Hwa_KeyDerive()
 *********************************************************************************************************************/
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
 *
 */
FUNC(Std_ReturnType, CRYPTO_30_HWA_CODE) Crypto_30_Hwa_KeyDerive(
  uint32 cryptoKeyId,
  uint32 targetCryptoKeyId)
{
  Std_ReturnType retVal = E_NOT_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */
#if (CRYPTO_30_HWA_KEY_DERIVE == STD_ON)

  /* Variables to get information about KeyElements */
  vHsm_Api_KeyStorageIndexType keyElementIndex;
  vHsm_Api_SizeOfKeyElementsType indexOfKeyElement;
  P2CONST(uint8, AUTOMATIC, CRYPTO_30_HWA_APPL_DATA) keyElementDataPtr;
  uint32 keyElementDataLength;

  /* Reserve some space for the binary string of the counter i */
  uint32 inputSizeBlocks = CRYPTO_30_HWA_SIZE_OF_ITERATION_COUNTER;

  /* Variables for key derivation */
  uint8 InputData[CRYPTO_30_HWA_MAX_INPUT_LENGTH] = { 0u };
  uint8 targetKey[CRYPTO_30_HWA_MAX_OUTPUT_KEY_LENGTH];
  uint32 blocksWrittenToTargetKey = 0u;
  uint32 targetKeyLengthBit;
  uint32 numberOfIterations = 0u;

  /* Copy of cryptoKeyId, to check if the key is a hardware key */
  uint32 aggKeyId = cryptoKeyId;

  /* Check chosen algorithm from source key */
  keyElementDataLength = CRYPTO_30_HWA_KEYDERIVATION_ALGORITHM_SIZE_BLOCKS;

# if (CRYPTO_30_HWA_ROMKEY == STD_ON) /* COV_CRYPTO_30_HWA_HARDWARE_DEPENDENT_FEATURE */
  retVal = Crypto_30_Hwa_CheckAggregatedKeyId(&aggKeyId);
# endif  /* if (CRYPTO_30_HWA_ROMKEY == STD_ON) */

  if (
# if (CRYPTO_30_HWA_ROMKEY == STD_ON) /* COV_CRYPTO_30_HWA_HARDWARE_DEPENDENT_FEATURE */
      (retVal == E_OK) &&
# endif  /* if (CRYPTO_30_HWA_ROMKEY == STD_ON) */
      (targetCryptoKeyId < vHsm_Api_GetSizeOfKey()))
  {
    retVal = vHsm_Api_Local_KeyElementGetStorageIndex( /* PRQA S 2986 */ /* MD_CRYPTO_30_HWA_2986_REDUNDANT_OP */
      aggKeyId, CRYPTO_KE_CUSTOM_VHSM_KEYDERIVATION_ALGORITHM, &keyElementIndex, &keyElementDataLength, VHSM_API_LENGTH_CHECK_EQUAL);

    if (retVal == E_OK)
    {
      keyElementDataPtr = vHsm_Api_GetAddrKeyStorage(keyElementIndex);
      if (keyElementDataPtr[0] == CRYPTO_30_VHSM_ALGO_KDF_NIST_800_108_CMAC)
      {
        retVal = Crypto_30_Hwa_ConcatenateKDFInputString(aggKeyId, InputData, &inputSizeBlocks);

        /* Get length of the targetkey password element */
        retVal |= vHsm_Api_Local_KeyElementSearch(targetCryptoKeyId, CRYPTO_KE_KEYDERIVATION_TARGET_KEY, &indexOfKeyElement);
        if (retVal == E_OK)
        {
          /* Get configured target key length */
          targetKeyLengthBit = (uint32)(vHsm_Api_GetKeyElementLength(indexOfKeyElement) * 8uL);

          /* Calculate number of iterations */
          Crypto_30_Hwa_GetNumberKdfIterations(&numberOfIterations, targetKeyLengthBit);

          if ((numberOfIterations > (uint32)((1Lu << (uint32)(CRYPTO_30_HWA_SIZE_OF_ITERATION_COUNTER * 8uL)) - 1Lu))      /* PRQA S 2992, 2996 2 */ /* MD_CRYPTO_30_HWA_2992_EXPRESSION_FALSE, MD_CRYPTO_30_HWA_2996_EXPRESSION_FALSE */
            || ((targetKeyLengthBit / 8u) > CRYPTO_30_HWA_MAX_OUTPUT_KEY_LENGTH))
          {
            /* Counter is too small for the number of iterations or the buffer for the targetkey is too small */
            retVal = E_NOT_OK;
          }
          else
          {
            /* Concatenate the target key length to the fixed input */
            Crypto_30_Hwa_UintToArray(targetKeyLengthBit, &InputData[inputSizeBlocks], CRYPTO_30_HWA_SIZE_OF_TARGET_KEY_LENGTH);
            inputSizeBlocks += CRYPTO_30_HWA_SIZE_OF_TARGET_KEY_LENGTH;

            retVal = Crypto_30_Hwa_GetKeyDerivationFromCMAC(
              cryptoKeyId,
              numberOfIterations,
              InputData,
              inputSizeBlocks,
              targetKeyLengthBit,
              targetKey,
              &blocksWrittenToTargetKey
            );

            if (retVal == E_OK)
            {
              retVal = vHsm_Api_KeyElementSet_Unchecked(targetCryptoKeyId, CRYPTO_KE_KEYDERIVATION_TARGET_KEY, targetKey, blocksWrittenToTargetKey);
              retVal |= vHsm_Api_KeyValidSet(targetCryptoKeyId);
            }
          }
        }
      }
      else
      {
        retVal = E_NOT_OK;
      }
    }
    else
    {
      retVal = E_NOT_OK;
    }
  }
#else
  CRYPTO_30_HWA_DUMMY_STATEMENT(cryptoKeyId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  CRYPTO_30_HWA_DUMMY_STATEMENT(targetCryptoKeyId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
#endif /* CRYPTO_30_HWA_KEY_DERIVE */

  return retVal;
} /* PRQA S 6080, 6050 */ /* MD_MSR_STMIF, MD_MSR_STCAL */

#define CRYPTO_30_HWA_STOP_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  END OF FILE: Crypto_30_Hwa_KeyM.c
 *********************************************************************************************************************/
