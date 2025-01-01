/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2022 by Vector Informatik GmbH.                                                  All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/*!        \file  vHsm_Core.c
 *        \brief  Source file for the core driver
 *
 *      \details  Implements the driver API which provides basic functionalities like secure boot or reading the version
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 *********************************************************************************************************************/

#define VHSM_CORE_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "vHsm_Core.h"
#include "vHsm.h"
#include "vHsm_ApiInternal.h"
#include "vHsm_Nvm.h"
#include "vHsm_KeyM.h"
#include "vHsm_Trace.h"
#include "vHsm_Core_Custom.h"
#include "vHsm_Hal.h"

#include "Crypto_30_LibCv.h"
#include "Crypto_30_LibCv_Cfg.h"
#include "CryIf_Cfg.h"
#include "vstdlib.h"
#if (VHSM_DEV_ERROR_REPORT == STD_ON)
# include "Det.h"
#endif

/**********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 *********************************************************************************************************************/

#if !defined (VHSM_LOCAL) /* COV_VHSM_LOCAL_DEFINE */
# define VHSM_LOCAL                                                   static
#endif

#if !defined (VHSM_LOCAL_INLINE) /* COV_VHSM_LOCAL_DEFINE */
# define VHSM_LOCAL_INLINE                                            LOCAL_INLINE
#endif

/* Must be at least 32 bytes */
#define VHSM_FIRMWARE_UPDATE_BUFFER_SIZE                              32u
#define VHSM_FIRMWARE_UPDATE_CONTAINER_HEADER_VERSION_OFFSET          16u
#define VHSM_FIRMWARE_UPDATE_CONTAINER_HEADER_SIZE                    24u

/* This is the minimum size needed to get the address and size from the header */
#define VHSM_FIRMWARE_UPDATE_PAYLOAD_HEADER_VERSION_OFFSET            16u
#define VHSM_FIRMWARE_UPDATE_PAYLOAD_HEADER_ADDRESS_OFFSET            20u
#define VHSM_FIRMWARE_UPDATE_PAYLOAD_HEADER_LENGTH_OFFSET             24u
#define VHSM_FIRMWARE_UPDATE_PAYLOAD_HEADER_MIN_SIZE                  (VHSM_FIRMWARE_UPDATE_PAYLOAD_HEADER_LENGTH_OFFSET + sizeof(uint32))

#define VHSM_CORE_KEYID_START_OFFSET                                  30000uL
#define VHSM_CORE_NO_AGGREGATION_KEY                                  0xFFFFFFFFuL

/**********************************************************************************************************************
 *  LOCAL FUNCTION MACROS
 *********************************************************************************************************************/

 /* Job mode macro */
#define vHsm_Core_IsJobMode(Job, Mask)                                ((((Job)->jobPrimitiveInputOutput.mode) & (Mask)) == (Mask))

/**********************************************************************************************************************
 *  LOCAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

#define VHSM_START_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
#if (VHSM_FIRMWARE_UPDATE == STD_ON)
VHSM_LOCAL VAR(uint32, VHSM_VAR_NOINIT) vHsm_FirmwareUpdate_WrittenDuringUpdate; /* PRQA S 3218 */ /* MD_VHSM_3218_WORKSPACE_VAR */
VHSM_LOCAL VAR(uint8, VHSM_VAR_NOINIT) vHsm_FirmwareUpdate_HeaderBuffer[12]; /* PRQA S 3218 */ /* MD_VHSM_3218_WORKSPACE_VAR */
VHSM_LOCAL VAR(uint32, VHSM_VAR_NOINIT) vHsm_FirmwareUpdate_RecryptedDataSize; /* PRQA S 3218 */ /* MD_VHSM_3218_WORKSPACE_VAR */
#endif
#define VHSM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define VHSM_START_SEC_VAR_ZERO_INIT_8BIT
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
#if (VHSM_DEV_ERROR_DETECT == STD_ON)
/*! Initialization state of the module */
VHSM_LOCAL VAR( uint8, VHSM_VAR_ZERO_INIT ) vHsm_ModuleInitialized = VHSM_UNINIT;
#endif /* (VHSM_DEV_ERROR_DETECT == STD_ON) */
#define VHSM_STOP_SEC_VAR_ZERO_INIT_8BIT
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

#define VHSM_START_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#if ((VHSM_SECURE_BOOT == STD_ON) || (VHSM_FIRMWARE_UPDATE == STD_ON) || (VHSM_NVM_SUPPORT == STD_ON))
/**********************************************************************************************************************
 *  vHsm_Core_UpdateJobState()
 *********************************************************************************************************************/
/*!
 *
 * \brief       Update job state.
 * \details     Set job state based on parameter return value.
 * \param[in]   retVal              return value
 * \param[in]   job                 job
 * \pre         -
 * \context     ANY
 * \reentrant   FALSE
 * \synchronous TRUE
 */
VHSM_LOCAL FUNC(void, VHSM_CODE) vHsm_Core_UpdateJobState(
  Std_ReturnType retVal,
  P2VAR(Crypto_JobType, AUTOMATIC, VHSM_APPL_VAR) job);
# if (VHSM_DEV_ERROR_DETECT == STD_ON)
/**********************************************************************************************************************
 *  vHsm_Local_DetChecksServiceValues()
 *********************************************************************************************************************/
/*! \brief         Det Checks for the Service Parameters
 *  \details       This function checks the Det-Checks for all required in- and output-values.
 *  \param[in]     job                Pointer to the job which shall be dispatched.
 *  \param[out]    errorId            Output Pointer to the detected Error-Type-Id
 *  \return        E_OK               No Det error detected.
 *                 E_NOT_OK           Det error detected.
 *  \pre           objectId has to be a valid driver object handle.
 *                 errorId has to be a valid pointer.
 *                 job has to be a valid job object.
 *  \context       ANY
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
VHSM_LOCAL_INLINE FUNC(Std_ReturnType, VHSM_CODE) vHsm_Local_DetChecksServiceValues(
  P2CONST(Crypto_JobType, AUTOMATIC, VHSM_APPL_VAR) job,
  P2VAR(uint8, AUTOMATIC, VHSM_APPL_VAR) errorId);
# endif
# if (VHSM_FIRMWARE_UPDATE == STD_ON)

#  if (VHSM_DEV_ERROR_DETECT == STD_ON)
/**********************************************************************************************************************
 *  vHsm_Local_DetChecksServiceValues_AeadEncrypt()
 *********************************************************************************************************************/
/*! \brief         Det Checks for the Aead encrypt service parameters.
 *  \details       This function checks the Det-Checks for all required in- and output-values.
 *  \param[in]     job                Pointer to the job which shall be dispatched.
 *  \return        CRYPTO_E_NO_ERROR        No Det error detected.
 *                 CRYPTO_E_PARAM_POINTER   Parameter is a invalid pointer error.
 *                 CRYPTO_E_PARAM_VALUE     Parameter is a invalid value error.
 *  \pre           job has to be a valid job object.
 *  \context       ANY
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
VHSM_LOCAL_INLINE FUNC(uint8, VHSM_CODE) vHsm_Local_DetChecksServiceValues_AeadEncrypt(
  P2CONST(Crypto_JobType, AUTOMATIC, VHSM_APPL_VAR) job);
#  endif
# endif

# if (VHSM_DEV_ERROR_DETECT == STD_ON)
#  if (VHSM_SECURE_BOOT == STD_ON)
/**********************************************************************************************************************
 *  vHsm_Local_DetChecksServiceValues_MacVerify()
 *********************************************************************************************************************/
/*! \brief         Det Checks for the Mac verify service parameters.
 *  \details       This function checks the Det-Checks for all required in- and output-values.
 *  \param[in]     job                Pointer to the job which shall be dispatched.
 *  \return        CRYPTO_E_NO_ERROR        No Det error detected.
 *                 CRYPTO_E_PARAM_POINTER   Parameter is a invalid pointer error.
 *                 CRYPTO_E_PARAM_VALUE     Parameter is a invalid value error.
 *  \pre           job has to be a valid job object.
 *  \context       ANY
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
VHSM_LOCAL_INLINE FUNC(uint8, VHSM_CODE) vHsm_Local_DetChecksServiceValues_MacVerify(
  P2CONST(Crypto_JobType, AUTOMATIC, VHSM_APPL_VAR) job);

/**********************************************************************************************************************
 *  vHsm_Local_DetChecksServiceValues_SignatureVerify()
 *********************************************************************************************************************/
/*! \brief         Det Checks for the signature verify service parameters.
 *  \details       This function checks the Det-Checks for all required in- and output-values.
 *  \param[in]     job                Pointer to the job which shall be dispatched.
 *  \return        CRYPTO_E_NO_ERROR        No Det error detected.
 *                 CRYPTO_E_PARAM_POINTER   Parameter is a invalid pointer error.
 *                 CRYPTO_E_PARAM_VALUE     Parameter is a invalid value error.
 *  \pre           job has to be a valid job object.
 *  \context       ANY
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
VHSM_LOCAL_INLINE FUNC(uint8, VHSM_CODE) vHsm_Local_DetChecksServiceValues_SignatureVerify(
  P2CONST(Crypto_JobType, AUTOMATIC, VHSM_APPL_VAR) job);
#  endif
# endif
#endif

/**********************************************************************************************************************
 *  vHsm_Core_IsDestinationValid()
 *********************************************************************************************************************/
/*! \brief         Check if the destination length is valid
 *  \details       -
 *  \param[in]     resultLengthPtr          Pointer to the result length
 *  \param[in]     length                   requested length
 *  \return        TRUE if valid, otherwise FALSE
 *  \pre           -
 *  \context       ANY
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
VHSM_LOCAL FUNC(boolean, VHSM_CODE) vHsm_Core_IsDestinationValid(
  P2CONST(uint32, AUTOMATIC, VHSM_APPL_VAR) resultLengthPtr,
  uint32 length);

#if (VHSM_FIRMWARE_UPDATE_RECRYPTION == STD_ON)
/**********************************************************************************************************************
 *  vHsm_Core_PerformRecryption()
 *********************************************************************************************************************/
/*! \brief         Process the START of firmware update
 *  \details       -
 *  \param[in,out]     bufferSizePtr                            Pointer to the buffer size
 *  \param[in]         vHsm_FirmwareUpdateBufferPlaintextPtr    Pointer to the plaintext buffer
 *  \param[in,out]     vHsm_FirmwareUpdateBufferOutputPtr       Pointer to the output buffer
 *  \param[out]        jobBuffer                                Pointer to the buffer provided by the job
 *  \param[in]         remainingJobBuffer                       length of the jobBuffer
 *  \return        E_OK if valid, otherwise E_NOT_OK
 *  \pre           -
 *  \context       ANY
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
VHSM_LOCAL FUNC(Std_ReturnType, VHSM_CODE) vHsm_Core_PerformRecryption(
  P2VAR(uint32, AUTOMATIC, VHSM_APPL_VAR) bufferSizePtr,
  P2CONST(uint8, AUTOMATIC, VHSM_APPL_VAR) vHsm_FirmwareUpdateBufferPlaintextPtr,
  P2VAR(uint8, AUTOMATIC, VHSM_APPL_VAR) vHsm_FirmwareUpdateBufferOutputPtr,
  P2VAR(uint8, AUTOMATIC, VHSM_APPL_VAR) jobBuffer,
  uint32 remainingJobBuffer);
#endif

#if (VHSM_FIRMWARE_UPDATE == STD_ON)
/**********************************************************************************************************************
 *  vHsm_Core_DispatchFirmwareUpdate()
 *********************************************************************************************************************/
/*! \brief         Dispatch the command to process a firmware update
 *  \details       Calls the correspoding start Update or Finish function of the firmware update
 *  \param[in]     objectId            Id of the object
 *  \param[out]    job                 Pointer to the job
 *  \param[in]     mode                Processing mode
 *  \return        E_OK if successful, otherwise E_NOT_OK
 *  \pre           -
 *  \context       ANY
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
VHSM_LOCAL_INLINE FUNC(Std_ReturnType, VHSM_CODE) vHsm_Core_DispatchFirmwareUpdate(
  uint32 objectId,
  P2VAR(Crypto_JobType, AUTOMATIC, VHSM_APPL_VAR) job,
  Crypto_OperationModeType mode);

/**********************************************************************************************************************
 *  vHsm_Core_DispatchFirmwareUpdateStart()
 *********************************************************************************************************************/
/*! \brief         Process the START of firmware update
 *  \details       -
 *  \param[in,out] job          Pointer to the result length
 *  \return        E_OK if valid, otherwise E_NOT_OK
 *  \pre           -
 *  \context       ANY
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
VHSM_LOCAL_INLINE FUNC(Std_ReturnType, VHSM_CODE) vHsm_Core_DispatchFirmwareUpdateStart(
  P2VAR(Crypto_JobType, AUTOMATIC, VHSM_APPL_VAR) job);

/**********************************************************************************************************************
 *  vHsm_Core_DispatchFirmwareUpdateUpdate()
 *********************************************************************************************************************/
/*! \brief         Process the UPDATE of firmware update
 *  \details       -
 *  \param[in,out]     job          Pointer to the result length
 *  \return        E_OK if valid, otherwise E_NOT_OK
 *  \pre           -
 *  \context       ANY
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
VHSM_LOCAL_INLINE FUNC(Std_ReturnType, VHSM_CODE) vHsm_Core_DispatchFirmwareUpdateUpdate(
  P2VAR(Crypto_JobType, AUTOMATIC, VHSM_APPL_VAR) job);

/**********************************************************************************************************************
 *  vHsm_Core_DispatchFirmwareUpdateFinish()
 *********************************************************************************************************************/
/*! \brief         Process the FINISH of firmware update
 *  \details       -
 *  \param[in,out]     job          Pointer to the result length
 *  \return        E_OK if valid, otherwise E_NOT_OK
 *  \pre           -
 *  \context       ANY
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
VHSM_LOCAL_INLINE FUNC(Std_ReturnType, VHSM_CODE) vHsm_Core_DispatchFirmwareUpdateFinish(
  P2VAR(Crypto_JobType, AUTOMATIC, VHSM_APPL_VAR) job);
#endif

/**********************************************************************************************************************
 *  vHsm_Core_IsKey()
 *********************************************************************************************************************/
 /*! \brief        Check if the key is the the expected key
 *  \details       -
 *  \param[in]     expected          Expected key
 *  \param[in]     cryptoKeyId       Actual key
 *  \return        TRUE if key is as expected, otherwise FALSE
 *  \pre           -
 *  \context       ANY
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
VHSM_LOCAL_INLINE FUNC(boolean, VHSM_CODE) vHsm_Core_IsKey(
  uint32 expected,
  uint32 cryptoKeyId);

#if ((VHSM_SECURE_BOOT == STD_ON) || (VHSM_FIRMWARE_UPDATE == STD_ON) || (VHSM_NVM_SUPPORT == STD_ON))
/**********************************************************************************************************************
 *  vHsm_Core_DispatchService()
 *********************************************************************************************************************/
/*! \brief         Dispatches the job to a service
 *  \details       This function dispatches the provided job to the service as specified in the job configuration.
 *  \param[in]     objectId           Holds the identifier of the Crypto Driver Object.
 *  \param[in,out] job                Pointer to the job which shall be dispatched.
 *  \param[in]     mode               Operation mode in which the job currently is.
 *  \return        E_OK                         Request successful.
 *                 E_NOT_OK                     Request failed.
 *  \pre           objectId has to be a valid driver object handle.
 *                 job has to be a valid job object.
 *  \context       ANY
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
VHSM_LOCAL FUNC(Std_ReturnType, VHSM_CODE) vHsm_Core_DispatchService(
  uint32 objectId,
  P2VAR(Crypto_JobType, AUTOMATIC, VHSM_APPL_VAR) job,
  Crypto_OperationModeType mode);
#endif

#define VHSM_STOP_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

#define VHSM_START_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  vHsm_Core_IsDestinationValid()
 *********************************************************************************************************************/
 /*!
 *
 * Internal comment removed.
 *
 *
 *
 */
VHSM_LOCAL FUNC(boolean, VHSM_CODE) vHsm_Core_IsDestinationValid(
  P2CONST(uint32, AUTOMATIC, VHSM_APPL_VAR) resultLengthPtr,
  uint32 length)
{
  boolean retVal = FALSE;

  /* #10 Check if the destination is valid */
  if (resultLengthPtr == NULL_PTR)
  {
    /* Do nothing. Return value is already set. */
  }
  else if (*resultLengthPtr < length)
  {
    /* Do nothing. Return value is already set. */
  }
  else
  {
    retVal = TRUE;
  }

  /* #20 Return the result */
  return retVal;
}

#if (VHSM_FIRMWARE_UPDATE == STD_ON)
/**********************************************************************************************************************
 *  vHsm_Core_DispatchFirmwareUpdate()
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
 */
VHSM_LOCAL_INLINE FUNC(Std_ReturnType, VHSM_CODE) vHsm_Core_DispatchFirmwareUpdate(
  uint32 objectId,
  P2VAR(Crypto_JobType, AUTOMATIC, VHSM_APPL_VAR) job,
  Crypto_OperationModeType mode)
{
  Std_ReturnType retVal = E_NOT_OK;

  /* #10 Decide if the algorithm shall be processed */
  if (job->jobPrimitiveInfo->primitiveInfo->algorithm.family == CRYPTO_ALGOFAM_CUSTOM_VHSM_FIRMWARE_UPDATE)
  {
    /* #15 Distinguish modes */
    switch (mode)
    {
      /* #20 Handle operationmode START */
    case CRYPTO_OPERATIONMODE_START:
    {
      retVal = vHsm_Core_DispatchFirmwareUpdateStart(job);
      break;
    }
    /* #40 Handle operationmode UPDATE */
    case CRYPTO_OPERATIONMODE_UPDATE:
    {
      retVal = vHsm_Core_DispatchFirmwareUpdateUpdate(job);
      break;
    }
    /* #70 Handle operationmode FINISH */
    case CRYPTO_OPERATIONMODE_FINISH:
    {
      retVal = vHsm_Core_DispatchFirmwareUpdateFinish(job);
      break;
    }
    default: /* COV_VHSM_CASE_DEFAULT */
      break;
    }

    /* #100 Cancel all jobs if an error occurred */
    if (retVal != E_OK)
    {
# if (VHSM_FIRMWARE_UPDATE_RECRYPTION == STD_ON)
      (void)Csm_CancelJob(vHsm_GetCsmJobDecryptRefOfFirmwareUpdate(), CRYPTO_OPERATIONMODE_SINGLECALL);
      (void)Csm_CancelJob(vHsm_GetCsmJobEncryptRefOfFirmwareUpdate(), CRYPTO_OPERATIONMODE_SINGLECALL);
# endif
      (void)Csm_CancelJob(vHsm_GetCsmJobSignatureVerifyRefOfFirmwareUpdate(), CRYPTO_OPERATIONMODE_SINGLECALL);
      (void)Csm_CancelJob(vHsm_GetCsmJobMacGenerateRefOfFirmwareUpdate(), CRYPTO_OPERATIONMODE_SINGLECALL);

      /* Indicate that the firmware update was not successful */
      vHsm_State.vHsm_SuccessfulFirmwareUpdateFlag = FALSE;

      /* Always return E_NOT_OK as error value */
      retVal = E_NOT_OK;
    }
  }

  VHSM_DUMMY_STATEMENT(objectId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */

  return retVal;
}

# if (VHSM_FIRMWARE_UPDATE_RECRYPTION == STD_ON)
/**********************************************************************************************************************
 *  vHsm_Core_PerformRecryption()
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
 */
VHSM_LOCAL FUNC(Std_ReturnType, VHSM_CODE) vHsm_Core_PerformRecryption(
  P2VAR(uint32, AUTOMATIC, VHSM_APPL_VAR) bufferSizePtr,
  P2CONST(uint8, AUTOMATIC, VHSM_APPL_VAR) vHsm_FirmwareUpdateBufferPlaintextPtr,
  P2VAR(uint8, AUTOMATIC, VHSM_APPL_VAR) vHsm_FirmwareUpdateBufferOutputPtr,
  P2VAR(uint8, AUTOMATIC, VHSM_APPL_VAR) jobBuffer,
  uint32 remainingJobBuffer)
{
  Std_ReturnType retVal = E_OK;

  /* #10 Check if there is data in the buffer available for encryption */
  if (*bufferSizePtr > 0u) /* COV_VHSM_AES_DEC_OUTPUT_DATA */
  {
    /* #20 Encrypt the data in the buffer and write the result to the outputPtr of the job */
    uint32 tmpbufferSizePtr = *bufferSizePtr;
    *bufferSizePtr = VHSM_FIRMWARE_UPDATE_BUFFER_SIZE;

    retVal = Csm_Encrypt(vHsm_GetCsmJobEncryptRefOfFirmwareUpdate(),
      CRYPTO_OPERATIONMODE_UPDATE,
      vHsm_FirmwareUpdateBufferPlaintextPtr, tmpbufferSizePtr,
      vHsm_FirmwareUpdateBufferOutputPtr, bufferSizePtr);

    /* #30 Check if encrypt produced some data */
    if (*bufferSizePtr > 0u)
    {
      /* #35 Use the buffer for the MAC calculation */
      retVal |= Csm_MacGenerate(vHsm_GetCsmJobMacGenerateRefOfFirmwareUpdate(),
        CRYPTO_OPERATIONMODE_UPDATE,
        vHsm_FirmwareUpdateBufferOutputPtr, *bufferSizePtr,
        NULL_PTR, NULL_PTR);
    }

    /* #40 Check if output buffer is big enough */
    if (remainingJobBuffer >= *bufferSizePtr)
    {
      /* #41 Copy the recrypted data to the output */
      VStdMemCpy(&jobBuffer[vHsm_FirmwareUpdate_WrittenDuringUpdate], vHsm_FirmwareUpdateBufferOutputPtr, *bufferSizePtr); /* PRQA S 0315 */ /* MD_MSR_VStdLibCopy */
    }
    else
    {
      retVal = E_NOT_OK;
    }
  }

  return retVal;
}
# endif

/**********************************************************************************************************************
 *  vHsm_Core_DispatchFirmwareUpdateStart()
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
 */
VHSM_LOCAL_INLINE FUNC(Std_ReturnType, VHSM_CODE) vHsm_Core_DispatchFirmwareUpdateStart(
  P2VAR(Crypto_JobType, AUTOMATIC, VHSM_APPL_VAR) job) /* PRQA S 3673 */ /* MD_MSR_Rule8.13 */
{
  Std_ReturnType retVal = E_NOT_OK;
  uint8 vHsm_FirmwareUpdateBufferInput[VHSM_FIRMWARE_UPDATE_BUFFER_SIZE];

  vHsm_Api_SizeOfKeyElementsType macKeyElement;
  uint8 macKey[16] = {0u};
  uint32 macKeyLength = sizeof(macKey);
# if (VHSM_FIRMWARE_UPDATE_RECRYPTION == STD_ON)
  vHsm_Api_SizeOfKeyElementsType encryptKeyElement;
  uint8 encryptKey[16] = {0u};
  uint32 encryptKeyLength = sizeof(encryptKey);
# endif

  vHsm_FirmwareUpdate_RecryptedDataSize = 0u;

  /* #21 Check if enough data is provided to parse the needed header data */
  if (job->jobPrimitiveInputOutput.inputLength != VHSM_FIRMWARE_UPDATE_CONTAINER_HEADER_SIZE)
  {
    /* Do nothing. Return value is already set. */
  }
  else if (job->jobPrimitiveInputOutput.secondaryInputLength < VHSM_FIRMWARE_UPDATE_PAYLOAD_HEADER_MIN_SIZE)
  {
    /* Do nothing. Return value is already set. */
  }
  /* Get the MAC key data */
  else if (vHsm_FirmwareUpdate_GetMacKey_Callout(macKey, &macKeyLength) != E_OK)
  {
    /* Do nothing. Return value is already set. */
  }
  /* Check if enough data has been returned */
  else if (macKeyLength != sizeof(macKey))
  {
    /* Do nothing. Return value is already set. */
  }
# if (VHSM_FIRMWARE_UPDATE_RECRYPTION == STD_ON)
  /* Get the cipher key data */
  else if (vHsm_FirmwareUpdate_GetCipherKey_Callout(encryptKey, &encryptKeyLength) != E_OK)
  {
    /* Do nothing. Return value is already set. */
  }
  /* Check if enough data has been returned */
  else if (encryptKeyLength != sizeof(encryptKey))
  {
    /* Do nothing. Return value is already set. */
  }
# endif
  /* Find the key element used in the MAC Generate job */
  else if (vHsm_Api_Local_KeyElementSearch(vHsm_GetCryptoKeyIdOfKeyInfo(VHSM_FIRMWARE_UPDATE_MAC_KEY), CRYPTO_KE_MAC_KEY, &macKeyElement) != E_OK)
  {
    /* Do nothing. Return value is already set. */
  }
# if (VHSM_FIRMWARE_UPDATE_RECRYPTION == STD_ON)
  /* Find the key element used in the Encrypt job */
  else if (vHsm_Api_Local_KeyElementSearch(vHsm_GetCryptoKeyIdOfKeyInfo(VHSM_FIRMWARE_UPDATE_ENCRYPT_KEY), CRYPTO_KE_CIPHER_KEY, &encryptKeyElement) != E_OK)
  {
    /* Do nothing. Return value is already set. */
  }
# endif
  else
  {
    vHsm_Api_KeyElementSetInternalStandard(macKeyElement, macKey, sizeof(macKey)); /* PRQA S 0310 */ /* MD_VHSM_0310_API_SPECIFIC_CAST */
    VStdLib_MemClr(macKey, sizeof(macKey)); /* PRQA S 0315 */ /* MD_MSR_VStdLibCopy */

# if (VHSM_FIRMWARE_UPDATE_RECRYPTION == STD_ON)
    vHsm_Api_KeyElementSetInternalStandard(encryptKeyElement, encryptKey, sizeof(encryptKey)); /* PRQA S 0310 */ /* MD_VHSM_0310_API_SPECIFIC_CAST */
    VStdLib_MemClr(encryptKey, sizeof(encryptKey)); /* PRQA S 0315 */ /* MD_MSR_VStdLibCopy */
# endif

    /* #22 Copy Input to local buffer to make sure that Signature and CMAC use the same data */
    VStdLib_MemCpy(vHsm_FirmwareUpdateBufferInput, job->jobPrimitiveInputOutput.inputPtr, VHSM_FIRMWARE_UPDATE_CONTAINER_HEADER_SIZE); /* PRQA S 0315 */ /* MD_MSR_VStdLibCopy */
    VStdLib_MemCpy(&vHsm_FirmwareUpdate_HeaderBuffer[0], &vHsm_FirmwareUpdateBufferInput[VHSM_FIRMWARE_UPDATE_CONTAINER_HEADER_VERSION_OFFSET], sizeof(uint32)); /* Version */ /* PRQA S 0315 */ /* MD_MSR_VStdLibCopy */
    VStdLib_MemCpy(&vHsm_FirmwareUpdate_HeaderBuffer[4], &job->jobPrimitiveInputOutput.secondaryInputPtr[VHSM_FIRMWARE_UPDATE_PAYLOAD_HEADER_ADDRESS_OFFSET], sizeof(uint32)); /* Address */ /* PRQA S 0315 */ /* MD_MSR_VStdLibCopy */

    /* #23 Start the signature verification job */
    retVal = Csm_SignatureVerify(vHsm_GetCsmJobSignatureVerifyRefOfFirmwareUpdate(),
    CRYPTO_OPERATIONMODE_START,
    NULL_PTR, 0u,
    NULL_PTR, 0u,
    NULL_PTR);

# if (VHSM_FIRMWARE_UPDATE_RECRYPTION == STD_ON)
    /* #24 Start the decryption job */
    retVal |= Csm_Decrypt(vHsm_GetCsmJobDecryptRefOfFirmwareUpdate(),
      CRYPTO_OPERATIONMODE_START,
      NULL_PTR, 0u,
      NULL_PTR, NULL_PTR);

    /* #25 Start the encryption job */
    retVal |= Csm_Encrypt(vHsm_GetCsmJobEncryptRefOfFirmwareUpdate(),
      CRYPTO_OPERATIONMODE_START,
      NULL_PTR, 0u,
      NULL_PTR, NULL_PTR);
# endif

    /* #26 Start the MAC generation job */
    retVal |= Csm_MacGenerate(vHsm_GetCsmJobMacGenerateRefOfFirmwareUpdate(),
      CRYPTO_OPERATIONMODE_START,
      NULL_PTR, 0u,
      NULL_PTR, NULL_PTR);

    /* #27 Use the input data for the signature verification */
    retVal |= Csm_SignatureVerify(vHsm_GetCsmJobSignatureVerifyRefOfFirmwareUpdate(),
      CRYPTO_OPERATIONMODE_UPDATE,
      vHsm_FirmwareUpdateBufferInput, VHSM_FIRMWARE_UPDATE_CONTAINER_HEADER_SIZE,
      NULL_PTR, 0u,
      NULL_PTR);

  }

  return retVal;
} /* PRQA S 6050,6080 */ /* MD_MSR_STCAL */ /* MD_MSR_STMIF */

/**********************************************************************************************************************
 *  vHsm_Core_DispatchFirmwareUpdateUpdate()
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
 */
VHSM_LOCAL_INLINE FUNC(Std_ReturnType, VHSM_CODE) vHsm_Core_DispatchFirmwareUpdateUpdate(
  P2VAR(Crypto_JobType, AUTOMATIC, VHSM_APPL_VAR) job) /* PRQA S 3673 */ /* MD_MSR_Rule8.13 */
{
  Std_ReturnType retVal;
  uint32 inputLengthTmp = job->jobPrimitiveInputOutput.inputLength;
  uint32 block = 0u;
  uint32 inputForDecrypt;
  uint32 remainingInputData = inputLengthTmp;
  uint32 offset;
  uint8 vHsm_FirmwareUpdateBufferInput[VHSM_FIRMWARE_UPDATE_BUFFER_SIZE];
# if (VHSM_FIRMWARE_UPDATE_RECRYPTION == STD_ON)
  uint8 vHsm_FirmwareUpdateBufferPlaintext[VHSM_FIRMWARE_UPDATE_BUFFER_SIZE];
  uint8 vHsm_FirmwareUpdateBufferOutput[VHSM_FIRMWARE_UPDATE_BUFFER_SIZE];
  uint32 bufferSize;
# endif

  vHsm_FirmwareUpdate_WrittenDuringUpdate = 0u;

  /* #41 Loop while there is remaining input data and no error happend: */
  do
  {
    offset = block * VHSM_FIRMWARE_UPDATE_BUFFER_SIZE;

    /* #42 Calculate the number of bytes to decrypt */
    if (remainingInputData > VHSM_FIRMWARE_UPDATE_BUFFER_SIZE)
    {
      inputForDecrypt = VHSM_FIRMWARE_UPDATE_BUFFER_SIZE;
    }
    else
    {
      inputForDecrypt = remainingInputData;
    }

    /* #43 Copy the input data to the local buffer to make sure that signature and MAC use the same data */
    VStdLib_MemCpy(vHsm_FirmwareUpdateBufferInput, &job->jobPrimitiveInputOutput.inputPtr[offset], inputForDecrypt);/* PRQA S 0315 */ /* MD_MSR_VStdLibCopy */

    /* #44 Use the input data for the signature verification */
    retVal = Csm_SignatureVerify(vHsm_GetCsmJobSignatureVerifyRefOfFirmwareUpdate(),
    CRYPTO_OPERATIONMODE_UPDATE,
      vHsm_FirmwareUpdateBufferInput, inputForDecrypt, NULL_PTR, 0, NULL_PTR);

# if (VHSM_FIRMWARE_UPDATE_RECRYPTION == STD_ON)
    /* #45 Decrypt the input data to the buffer */
    bufferSize = VHSM_FIRMWARE_UPDATE_BUFFER_SIZE;

    retVal |= Csm_Decrypt(vHsm_GetCsmJobDecryptRefOfFirmwareUpdate(),
      CRYPTO_OPERATIONMODE_UPDATE,
      vHsm_FirmwareUpdateBufferInput, inputForDecrypt, vHsm_FirmwareUpdateBufferPlaintext, &bufferSize);

    retVal |= vHsm_Core_PerformRecryption(
      &bufferSize,
      vHsm_FirmwareUpdateBufferPlaintext,
      vHsm_FirmwareUpdateBufferOutput,
      job->jobPrimitiveInputOutput.outputPtr,
      *job->jobPrimitiveInputOutput.outputLengthPtr - vHsm_FirmwareUpdate_WrittenDuringUpdate);

    vHsm_FirmwareUpdate_WrittenDuringUpdate += bufferSize;
# else
    /* #50 Use the buffer for the MAC calculation */
    retVal |= Csm_MacGenerate(vHsm_GetCsmJobMacGenerateRefOfFirmwareUpdate(),
      CRYPTO_OPERATIONMODE_UPDATE,
      vHsm_FirmwareUpdateBufferInput, inputForDecrypt, NULL_PTR, NULL_PTR);
# endif

    remainingInputData = inputLengthTmp - (block * VHSM_FIRMWARE_UPDATE_BUFFER_SIZE) - inputForDecrypt;
    block++;
  } while ((retVal == E_OK) && (remainingInputData != 0u));

# if (VHSM_FIRMWARE_UPDATE_RECRYPTION == STD_OFF)
  /* #51 Copy the input buffer to the output buffer when recryption is disabled */
  if (job->jobPrimitiveInputOutput.inputLength <= *job->jobPrimitiveInputOutput.outputLengthPtr)
  {
    VStdLib_MemCpy(job->jobPrimitiveInputOutput.outputPtr, job->jobPrimitiveInputOutput.inputPtr, job->jobPrimitiveInputOutput.inputLength);/* PRQA S 0315 */ /* MD_MSR_VStdLibCopy */
    vHsm_FirmwareUpdate_WrittenDuringUpdate = job->jobPrimitiveInputOutput.inputLength;
  }
  else
  {
    retVal = E_NOT_OK;
  }
# endif

  if ((job->jobPrimitiveInputOutput.mode & CRYPTO_OPERATIONMODE_FINISH) != CRYPTO_OPERATIONMODE_FINISH)
  {
    /* #52 Write outputLength only when FINISH mode is not set, because otherwise it will be done inside FINISH */
    *job->jobPrimitiveInputOutput.outputLengthPtr = vHsm_FirmwareUpdate_WrittenDuringUpdate;
  }

  vHsm_FirmwareUpdate_RecryptedDataSize += vHsm_FirmwareUpdate_WrittenDuringUpdate;

  return retVal;
}

/**********************************************************************************************************************
 *  vHsm_Core_DispatchFirmwareUpdateFinish()
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
 *
 */
VHSM_LOCAL_INLINE FUNC(Std_ReturnType, VHSM_CODE) vHsm_Core_DispatchFirmwareUpdateFinish(
  P2VAR(Crypto_JobType, AUTOMATIC, VHSM_APPL_VAR) job) /* PRQA S 3673 */ /* MD_MSR_Rule8.13 */
{
  Std_ReturnType retVal;
  Crypto_VerifyResultType result = CRYPTO_E_VER_NOT_OK;
  uint32 bufferSize;
  uint8 dummyByte = 0u;
# if (VHSM_FIRMWARE_UPDATE_RECRYPTION == STD_ON)
  uint8 vHsm_FirmwareUpdateBufferPlaintext[VHSM_FIRMWARE_UPDATE_BUFFER_SIZE];
# endif
  uint8 vHsm_FirmwareUpdateBufferOutput[VHSM_FIRMWARE_UPDATE_BUFFER_SIZE];

  /* #71 Finish the signature verification */
  retVal = Csm_SignatureVerify(vHsm_GetCsmJobSignatureVerifyRefOfFirmwareUpdate(),
    CRYPTO_OPERATIONMODE_FINISH,
    &dummyByte,
    0u,
    job->jobPrimitiveInputOutput.secondaryInputPtr,
    job->jobPrimitiveInputOutput.secondaryInputLength,
    &result);

# if (VHSM_FIRMWARE_UPDATE_RECRYPTION == STD_ON)
  {
    uint8 dummy[16u];
    boolean dummyUsed = FALSE;
    uint32 remainingOutBuffer;
    Crypto_JobPrimitiveInputOutputType primitiveInputOutput;
    if ((job->jobPrimitiveInputOutput.mode & CRYPTO_OPERATIONMODE_UPDATE) != CRYPTO_OPERATIONMODE_UPDATE)
    {
      vHsm_FirmwareUpdate_WrittenDuringUpdate = 0u;
    }

    remainingOutBuffer = *job->jobPrimitiveInputOutput.outputLengthPtr - vHsm_FirmwareUpdate_WrittenDuringUpdate;

    /* #72 Finish the decryption job */
    bufferSize = VHSM_FIRMWARE_UPDATE_BUFFER_SIZE;

    retVal |= Csm_Decrypt(vHsm_GetCsmJobDecryptRefOfFirmwareUpdate(),
      CRYPTO_OPERATIONMODE_FINISH,
      NULL_PTR, 0u,
      vHsm_FirmwareUpdateBufferPlaintext, &bufferSize);

    retVal |= vHsm_Core_PerformRecryption(
      &bufferSize,
      vHsm_FirmwareUpdateBufferPlaintext,
      vHsm_FirmwareUpdateBufferOutput,
      job->jobPrimitiveInputOutput.outputPtr,
      remainingOutBuffer);

    /* Prevent underflow of variable */
    if (remainingOutBuffer >= bufferSize)
    {
      remainingOutBuffer -= bufferSize;
    }

    /* #76 Finish the encryption job and write the result to the outputPtr of the job */
    if (remainingOutBuffer != 0u)
    {
      primitiveInputOutput.outputPtr = &job->jobPrimitiveInputOutput.outputPtr[bufferSize + vHsm_FirmwareUpdate_WrittenDuringUpdate];
    }
    else
    {
      dummyUsed = TRUE;
      remainingOutBuffer = sizeof(dummy);
      primitiveInputOutput.outputPtr = dummy; /* PRQA S 3217 */ /* MD_VHSM_3217_JOB_POINTER */
    }
    primitiveInputOutput.outputLengthPtr = &remainingOutBuffer; /* PRQA S 3217 */ /* MD_VHSM_3217_JOB_POINTER */
    retVal |= Csm_Encrypt(vHsm_GetCsmJobEncryptRefOfFirmwareUpdate(),
      CRYPTO_OPERATIONMODE_FINISH,
      NULL_PTR, 0u,
      primitiveInputOutput.outputPtr,
      primitiveInputOutput.outputLengthPtr);

    /* #77 Check that the finish of the encryption did not produce unexpected data */
    if ((dummyUsed == TRUE)
      && (remainingOutBuffer != 0u)) /* COV_VHSM_AES_ENC_OUTPUT_DATA_DUMMY */
    {
      /* The dummy buffer should never be written. This is not expected to happen. */
      retVal = E_NOT_OK;
    }
    else
    {
      *job->jobPrimitiveInputOutput.outputLengthPtr = bufferSize + remainingOutBuffer + vHsm_FirmwareUpdate_WrittenDuringUpdate;
    }

    vHsm_FirmwareUpdate_RecryptedDataSize += bufferSize + remainingOutBuffer;
  }
# endif

  /* #78 Copy the length of the recrypted data to the header info as Big Endian byte array */
  vHsm_FirmwareUpdate_HeaderBuffer[8] = (uint8)((vHsm_FirmwareUpdate_RecryptedDataSize >> 24));
  vHsm_FirmwareUpdate_HeaderBuffer[9] = (uint8)((vHsm_FirmwareUpdate_RecryptedDataSize >> 16) & 0xFFu);
  vHsm_FirmwareUpdate_HeaderBuffer[10] = (uint8)((vHsm_FirmwareUpdate_RecryptedDataSize >> 8) & 0xFFu);
  vHsm_FirmwareUpdate_HeaderBuffer[11] = (uint8)(vHsm_FirmwareUpdate_RecryptedDataSize);

  /* #79 Use the info from the header as input data for the MAC generation job */
  retVal |= Csm_MacGenerate(vHsm_GetCsmJobMacGenerateRefOfFirmwareUpdate(),
    CRYPTO_OPERATIONMODE_UPDATE,
    vHsm_FirmwareUpdate_HeaderBuffer, sizeof(vHsm_FirmwareUpdate_HeaderBuffer), NULL_PTR, NULL_PTR);

  /* #80 Finish the MAC generation job and write the result to the buffer */
  bufferSize = VHSM_FIRMWARE_UPDATE_BUFFER_SIZE;
  retVal |= Csm_MacGenerate(vHsm_GetCsmJobMacGenerateRefOfFirmwareUpdate(),
    CRYPTO_OPERATIONMODE_FINISH,
    NULL_PTR, 0u,
    vHsm_FirmwareUpdateBufferOutput, &bufferSize);

  /* #81 Check that no errors occurred and if the signature verification was successful */
  if ((retVal == E_OK)
    && (result == CRYPTO_E_VER_OK))
  {
    /* #82 Set internal flag to allow jump to Updater */
    vHsm_State.vHsm_SuccessfulFirmwareUpdateFlag = TRUE;

    /* #83 Copy the CMAC to the output buffer (tag) of the job */
    VStdMemCpy(job->jobPrimitiveInputOutput.secondaryOutputPtr, vHsm_FirmwareUpdateBufferOutput, bufferSize); /* PRQA S 0315 */ /* MD_MSR_VStdLibCopy */
    *job->jobPrimitiveInputOutput.secondaryOutputLengthPtr = bufferSize;
  }
  else
  {
    retVal = E_NOT_OK;
  }

  return retVal;
}

#endif

#if ((VHSM_SECURE_BOOT == STD_ON) || (VHSM_FIRMWARE_UPDATE == STD_ON) || (VHSM_NVM_SUPPORT == STD_ON))
/**********************************************************************************************************************
 *  vHsm_Core_DispatchService()
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 */
VHSM_LOCAL FUNC(Std_ReturnType, VHSM_CODE) vHsm_Core_DispatchService(
  uint32 objectId,
  P2VAR(Crypto_JobType, AUTOMATIC, VHSM_APPL_VAR) job, /* PRQA S 3673 */ /* MD_MSR_Rule8.13 */
  Crypto_OperationModeType mode)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Decide which service shall be processed */
  switch (job->jobPrimitiveInfo->primitiveInfo->service)
  {
# if (VHSM_SECURE_BOOT == STD_ON)
  case CRYPTO_MACVERIFY:
    {
      /* #20 Perform secure Boot */
      retVal = vHsm_Core_DispatchSecureBoot(objectId, job, mode);
      break;
    }
  case CRYPTO_SIGNATUREVERIFY:
    {
#  if (VHSM_SECURE_SOFTWARE_DOWNLOAD == STD_ON)
      if (job->jobPrimitiveInfo->primitiveInfo->algorithm.family == CRYPTO_ALGOFAM_CUSTOM_VHSM_SOFTWARE_DOWNLOAD)
      {
        /* #30 Perform secure software download */
        retVal = vHsm_Core_DispatchSecureSoftwareDownload(objectId, job, mode);
      }
      else
#  endif
#  if (VHSM_SECURE_BOOT_UPDATE == STD_ON)
      if (job->jobPrimitiveInfo->primitiveInfo->algorithm.family == CRYPTO_ALGOFAM_CUSTOM_VHSM_SECURE_BOOT_UPDATE)
      {
        /* #40 Perform secure boot update */
        retVal = vHsm_Core_DispatchSecureBootUpdate(objectId, job, mode);
      }
      else
#  endif
#  if (VHSM_VERMETHOD_EXTERNAL_SL_AVAILABLE == STD_ON)
      if (job->jobPrimitiveInfo->primitiveInfo->algorithm.family == CRYPTO_ALGOFAM_CUSTOM_VHSM_SECURE_BOOT_CONFIRMATION)
      {
        /* #50 Perform secure boot confirmation */
        retVal = vHsm_Core_DispatchSecureBootConfirmation(objectId, job, mode);
      }
      else
#  endif /* VHSM_VERMETHOD_EXTERNAL_SL_AVAILABLE == STD_ON */
      {
        /* Do nothing. Return value is already set. */
      }
      break;
    }
# endif
# if (VHSM_FIRMWARE_UPDATE == STD_ON)
  case CRYPTO_AEADENCRYPT:
    {
      retVal = vHsm_Core_DispatchFirmwareUpdate(objectId, job, mode);
      break;
    }
# endif
# if (VHSM_NVM_SUPPORT == STD_ON)
  case CRYPTO_RANDOMGENERATE:
    if (mode != CRYPTO_OPERATIONMODE_FINISH)
    {
      retVal = E_OK;
    }
    else  if (job->jobPrimitiveInfo->primitiveInfo->algorithm.family != CRYPTO_ALGOFAM_CUSTOM_CRYPTO_30_VHSM_CORE_PERSISTENCY)
    {
      /* Nothing to do, retVal is already E_NOT_OK */
    }
    else if(job->jobPrimitiveInfo->primitiveInfo->algorithm.mode == CRYPTO_ALGOMODE_CUSTOM_CRYPTO_30_VHSM_CORE_PERSISTDEFERRED)
    {
      /* Check if persisting of keys shall be performed (lazy persist) */
       retVal = vHsm_NvM_PerformWriteAll();
    }
    else if (job->jobPrimitiveInfo->primitiveInfo->algorithm.mode == CRYPTO_ALGOMODE_CUSTOM_CRYPTO_30_VHSM_CORE_REPERSIST)
    {
      /* Check if repersisting of keys shall be performed */
      retVal = vHsm_NvM_Repersist();
    }
    else
    {
      /* Nothing to do, retVal is already E_NOT_OK */
    }
    break;
# endif
  default: /* COV_VHSM_CASE_DEFAULT */
    /* Nothing to do, retVal is already E_NOT_OK */
    break;
  } /* PRQA S 3315 */ /* MD_VHSM_3315_CONFIG_DEPENDENT_CASES */

  VHSM_DUMMY_STATEMENT(objectId); /* PRQA S 3112, 1338, 2983 */ /* MD_MSR_DummyStmt */
  VHSM_DUMMY_STATEMENT(mode); /* PRQA S 3112, 1338, 2983 */ /* MD_MSR_DummyStmt */

  return retVal;
} /* vHsm_Core_DispatchService() */ /* PRQA S 6030, 6080 */ /* MD_MSR_STCYC, MD_MSR_STMIF */
/* PRQA L:DISPATCH_SERVICE */
#endif

#if ((VHSM_SECURE_BOOT == STD_ON) || (VHSM_FIRMWARE_UPDATE == STD_ON) || (VHSM_NVM_SUPPORT == STD_ON))
/**********************************************************************************************************************
 *  vHsm_Core_UpdateJobState()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
VHSM_LOCAL FUNC(void, VHSM_CODE) vHsm_Core_UpdateJobState(
  Std_ReturnType retVal,
  P2VAR(Crypto_JobType, AUTOMATIC, VHSM_APPL_VAR) job)
{
  /* #10 Set job state based on parameter return value. */
  if (retVal == E_OK)
  {
    job->jobState = CRYPTO_JOBSTATE_ACTIVE;
  }
  else
  {
    /* Set job to IDLE if error occurred */
    job->jobState = CRYPTO_JOBSTATE_IDLE;
  }
} /* vHsm_Core_UpdateJobState() */
#endif

#if (VHSM_DEV_ERROR_DETECT == STD_ON)
# if (VHSM_SECURE_BOOT == STD_ON)
/**********************************************************************************************************************
 * vHsm_Local_DetChecksServiceValues_MacVerify()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
VHSM_LOCAL_INLINE FUNC(uint8, VHSM_CODE) vHsm_Local_DetChecksServiceValues_MacVerify(
  P2CONST(Crypto_JobType, AUTOMATIC, VHSM_APPL_VAR) job)
{
  uint8 errorId = CRYPTO_E_NO_ERROR;

  /* #3 Check MAC Verify Pointers */
  if ((job->jobPrimitiveInputOutput.verifyPtr == NULL_PTR) && ((job->jobPrimitiveInputOutput.mode & CRYPTO_OPERATIONMODE_FINISH) == CRYPTO_OPERATIONMODE_FINISH))
  {
    errorId = CRYPTO_E_PARAM_POINTER;
  }
  else
  {
    /* Det Checks passed. Nothing has to be done. */
  }

  return errorId;
}

/**********************************************************************************************************************
 * vHsm_Local_DetChecksServiceValues_SignatureVerify()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
VHSM_LOCAL_INLINE FUNC(uint8, VHSM_CODE) vHsm_Local_DetChecksServiceValues_SignatureVerify(
  P2CONST(Crypto_JobType, AUTOMATIC, VHSM_APPL_VAR) job)
{
  uint8 errorId = CRYPTO_E_NO_ERROR;

  /* #3 Check Signature Verify Pointers and Length Parameter */
  /* [SWS_Crypto_00071] [SWS_Crypto_00070] Check Pointer */
  /* Optional check of inputPtr and inputLength for finish mode is not required. */
  if ((job->jobPrimitiveInputOutput.inputPtr == NULL_PTR)
    || (((job->jobPrimitiveInputOutput.secondaryInputPtr == NULL_PTR) || (job->jobPrimitiveInputOutput.verifyPtr == NULL_PTR))
      && ((job->jobPrimitiveInputOutput.mode & CRYPTO_OPERATIONMODE_FINISH) == CRYPTO_OPERATIONMODE_FINISH)))
  {
    if ((job->jobPrimitiveInfo->primitiveInfo->algorithm.family == CRYPTO_ALGOFAM_CUSTOM_VHSM_SECURE_BOOT_UPDATE)
      && (job->jobPrimitiveInputOutput.inputPtr != NULL_PTR)
      && (job->jobPrimitiveInputOutput.verifyPtr != NULL_PTR))
    {
     /* Accept Nullpointer on secondary input for secureboot update */
    }
    else
    {
      errorId = CRYPTO_E_PARAM_POINTER;
    }
  }
  /* [SWS_Crypto_00071] [SWS_Crypto_00142] Check Length */
  else if ((((job->jobPrimitiveInputOutput.mode & CRYPTO_OPERATIONMODE_UPDATE) == CRYPTO_OPERATIONMODE_UPDATE) && (job->jobPrimitiveInputOutput.inputLength == 0u)) ||
    (((job->jobPrimitiveInputOutput.mode & CRYPTO_OPERATIONMODE_FINISH) == CRYPTO_OPERATIONMODE_FINISH) && (job->jobPrimitiveInputOutput.secondaryInputLength == 0u)))
  {
    errorId = CRYPTO_E_PARAM_VALUE;
  }
  else
  {
    /* Det Checks passed. Nothing has to be done. */
  }

  return errorId;
}
# endif
# if (VHSM_FIRMWARE_UPDATE == STD_ON)

/**********************************************************************************************************************
 * vHsm_Local_DetChecksServiceValues_AeadEncrypt()
 **********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
VHSM_LOCAL_INLINE FUNC(uint8, VHSM_CODE) vHsm_Local_DetChecksServiceValues_AeadEncrypt(
  P2CONST(Crypto_JobType, AUTOMATIC, VHSM_APPL_VAR) job)
{
  uint8 errorId = CRYPTO_E_NO_ERROR;

  /* #6 Check AEAD Encrypt Pointers and Length Parameter */
  /* [SWS_Crypto_00071] [SWS_Crypto_00070] Check Pointer */
  /* Optional check of inputPtr and inputLength for finish mode is not required. */
  if ((((job->jobPrimitiveInputOutput.inputPtr == NULL_PTR) || (job->jobPrimitiveInputOutput.secondaryInputPtr == NULL_PTR)) && vHsm_Core_IsJobMode(job, CRYPTO_OPERATIONMODE_START)) ||

    ((job->jobPrimitiveInputOutput.inputPtr == NULL_PTR) && vHsm_Core_IsJobMode(job, CRYPTO_OPERATIONMODE_UPDATE)) ||
    (((job->jobPrimitiveInputOutput.outputPtr == NULL_PTR) || (job->jobPrimitiveInputOutput.outputLengthPtr == NULL_PTR)) && vHsm_Core_IsJobMode(job, CRYPTO_OPERATIONMODE_UPDATE)) ||

    ((job->jobPrimitiveInputOutput.secondaryInputPtr == NULL_PTR) && vHsm_Core_IsJobMode(job, CRYPTO_OPERATIONMODE_FINISH)) ||
    (((job->jobPrimitiveInputOutput.outputPtr == NULL_PTR) || (job->jobPrimitiveInputOutput.outputLengthPtr == NULL_PTR) || (job->jobPrimitiveInputOutput.secondaryOutputPtr == NULL_PTR) || (job->jobPrimitiveInputOutput.secondaryOutputLengthPtr == NULL_PTR)) && vHsm_Core_IsJobMode(job, CRYPTO_OPERATIONMODE_FINISH))
    )
  {
    errorId = CRYPTO_E_PARAM_POINTER;
  }
  /* [SWS_Crypto_00071] [SWS_Crypto_00142] Check Length */
  else if (
    (vHsm_Core_IsJobMode(job, CRYPTO_OPERATIONMODE_START) && ((job->jobPrimitiveInputOutput.inputLength == 0u) || (job->jobPrimitiveInputOutput.secondaryInputLength == 0u))) ||
    (vHsm_Core_IsJobMode(job, CRYPTO_OPERATIONMODE_UPDATE) && (*(job->jobPrimitiveInputOutput.outputLengthPtr) == 0u)) || /* PRQA S 2812 */ /* MD_VHSM_2812_DET_CHECK_NULLPOINTER */
    (vHsm_Core_IsJobMode(job, CRYPTO_OPERATIONMODE_FINISH) && ( (job->jobPrimitiveInputOutput.secondaryInputLength == 0u) || (*(job->jobPrimitiveInputOutput.secondaryOutputLengthPtr) == 0u)))) /* PRQA S 2812 */ /* MD_VHSM_2812_DET_CHECK_NULLPOINTER */
  {
    errorId = CRYPTO_E_PARAM_VALUE;
  }
  else
  {
    /* Det Checks passed. Nothing has to be done. */
  }

  return errorId;
}
# endif

# if ((VHSM_SECURE_BOOT == STD_ON) || (VHSM_FIRMWARE_UPDATE == STD_ON) || (VHSM_NVM_SUPPORT == STD_ON))
/**********************************************************************************************************************
 *  vHsm_Local_DetChecksServiceValues()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
VHSM_LOCAL_INLINE FUNC(Std_ReturnType, VHSM_CODE) vHsm_Local_DetChecksServiceValues(
  P2CONST(Crypto_JobType, AUTOMATIC, VHSM_APPL_VAR) job,
  P2VAR(uint8, AUTOMATIC, VHSM_APPL_VAR) errorId)
{
  /* ----- Local Variables ------------------------------------------------ */
  Std_ReturnType retVal = E_OK;

  /* ----- Development Error Checks --------------------------------------- */
  /* #0 Check plausibility of parameters */
  switch (job->jobPrimitiveInfo->primitiveInfo->service)
  {
#  if (VHSM_SECURE_BOOT == STD_ON)
  case CRYPTO_MACVERIFY:
    *errorId = vHsm_Local_DetChecksServiceValues_MacVerify(job);
    break;
  case CRYPTO_SIGNATUREVERIFY:
    *errorId = vHsm_Local_DetChecksServiceValues_SignatureVerify(job);
    break;
#  endif
#  if (VHSM_FIRMWARE_UPDATE == STD_ON)
  case CRYPTO_AEADENCRYPT:
    *errorId = vHsm_Local_DetChecksServiceValues_AeadEncrypt(job);
    break;
#  endif
  case CRYPTO_RANDOMGENERATE:
    /* random generate is used to persist/repersist asynchronous */
    *errorId = CRYPTO_E_NO_ERROR;
    break;
  default:
    /* #11 Service is not supported by Crypto Driver Object */
    /* [SWS_Crypto_00064] check if job->jobPrimitiveInfo->primitiveInfo->service is supported by Crypto Driver Object */
    *errorId = CRYPTO_E_PARAM_HANDLE;
    break;
  } /* PRQA S 3315 */ /* MD_VHSM_3315_CONFIG_DEPENDENT_CASES */

  /* #12 Set return Value to E_NOT_OK if a failure was detected. */
  if ((*errorId == CRYPTO_E_PARAM_POINTER) || (*errorId == CRYPTO_E_PARAM_VALUE) || (*errorId == CRYPTO_E_PARAM_HANDLE)) /* PRQA S 2996 */ /* MD_VHSM_2996_CONDITION_TRUE_IN_OTHER_CONFIGS */
  {
    retVal = E_NOT_OK;
  }

  return retVal;
}
# endif
#endif /* (VHSM_DEV_ERROR_DETECT == STD_ON) */

/**********************************************************************************************************************
 *  vHsm_Core_IsKey()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
VHSM_LOCAL_INLINE FUNC(boolean, VHSM_CODE) vHsm_Core_IsKey(uint32 expected, uint32 cryptoKeyId)
{
  boolean found = FALSE;

  /* #10 Check if key is the expected local key */
  if ((expected == cryptoKeyId))
  {
    found = TRUE;
  }
  else
  {
    /* #20 Check if the aggregated key is the searched key */
    if (cryptoKeyId == vHsm_GetAggregatedCryptoKeyIdOfCoreKey(expected - VHSM_CORE_KEYID_START_OFFSET))
    {
        found = TRUE;
    }
  }

  /* #30 Return the result */
  return found;
}

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  esl_getBytesRNG()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(eslt_ErrorCode, VHSM_CODE) esl_getBytesRNG(
  const eslt_Length targetLength,
  P2VAR(eslt_Byte, AUTOMATIC, VHSM_APPL_VAR) target)
{
  eslt_ErrorCode retVal = ESL_ERC_PARAMETER_INVALID;
  /* #10 Generate a random number */
  if (vHsm_MemRand( target, targetLength ) == E_OK)
  {
    retVal = ESL_ERC_NO_ERROR;
  }
  return retVal;
}

/**********************************************************************************************************************
 *  vHsm_Core_Init()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, VHSM_CODE) vHsm_Core_Init(void)
{
  /* #10 Do nothing */
  uint8 errorId = CRYPTO_E_NO_ERROR;

  /* ----- Development Error Checks ------------------------------------- */
#if (VHSM_DEV_ERROR_DETECT == STD_ON)
  /* Check initialization state of the component */
  if (vHsm_ModuleInitialized == (uint8)VHSM_INITIALIZED)
  {
    errorId = CRYPTO_E_INIT_FAILED;
  }
  /* Set module state to initialized */
  vHsm_ModuleInitialized = VHSM_INITIALIZED;
#endif /* (VHSM_DEV_ERROR_DETECT == STD_ON) */

  /* ----- Development Error Report --------------------------------------- */
#if (VHSM_DEV_ERROR_REPORT == STD_ON)
  if (errorId != CRYPTO_E_NO_ERROR)
  {
    /* Call Det if error occurred */
    (void)Det_ReportError( VHSM_MODULE_ID, VHSM_INSTANCE_ID, VHSM_SID_INIT, errorId );
  }
#else /* (VHSM_DEV_ERROR_REPORT == STD_ON) */
  VHSM_DUMMY_STATEMENT(errorId); /* PRQA S 3112, 1338, 2983 */ /* MD_MSR_DummyStmt */
#endif /* (VHSM_DEV_ERROR_REPORT == STD_ON) */
} /* vHsm_Core_Init() */

/**********************************************************************************************************************
 *  vHsm_Core_InitMemory()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, VHSM_CODE) vHsm_Core_InitMemory(void)
{
  /* #10 Set the mode to uninitialized */
#if (VHSM_DEV_ERROR_DETECT == STD_ON)
  vHsm_ModuleInitialized = (uint8)VHSM_UNINIT;
#endif /* (VHSM_DEV_ERROR_DETECT == STD_ON) */
} /* vHsm_Core_InitMemory() */

/**********************************************************************************************************************
 *  vHsm_Core_MainFunction()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, VHSM_CODE) vHsm_Core_MainFunction(void)
{
#if (VHSM_SECURE_BOOT == STD_ON)
  /* #10 Process the secure boot groups in the queue */
  vHsm_Core_SecureBoot_MainFunction();
#endif /* (VHSM_SECURE_BOOT == STD_ON) */
}

/**********************************************************************************************************************
 *  vHsm_Core_ProcessJob()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(Std_ReturnType, VHSM_CODE) vHsm_Core_ProcessJob(
  uint32 objectId,
  P2VAR(Crypto_JobType, AUTOMATIC, VHSM_APPL_VAR) job) /* PRQA S 3673 */ /* MD_MSR_Rule8.13 */
{
  Std_ReturnType retVal = E_NOT_OK;

#if ((VHSM_SECURE_BOOT == STD_ON) || (VHSM_FIRMWARE_UPDATE == STD_ON) || (VHSM_NVM_SUPPORT == STD_ON))
  uint8 errorId = CRYPTO_E_NO_ERROR;

  /* ----- Development Error Checks ------------------------------------- */
# if (VHSM_DEV_ERROR_DETECT == STD_ON)
  /* [SWS_Crypto_00057] */
  /* #5 Check initialization state of the component. */
  if (vHsm_ModuleInitialized == (uint8)VHSM_UNINIT)
  {
    errorId = CRYPTO_E_UNINIT;
  }
  /* [SWS_Crypto_00059] Check if job is a null pointer */
  else if (job == NULL_PTR)
  {
    errorId = CRYPTO_E_PARAM_POINTER;
  }
  else if (vHsm_Local_DetChecksServiceValues( job, &errorId ) == E_NOT_OK)
  {
    /* Error Id is set by sub-function */
  }
  else
# endif /* (VHSM_DEV_ERROR_DETECT == STD_ON) */
  {
    /* #15 Dispatch job according to job mode in order START, UPDATE and FINISH. */
    /* [SWS_Crypto_00017] [SWS_Crypto_00020] START while IDLE or ACTIVE (no other states available)*/
    if ((job->jobPrimitiveInputOutput.mode & CRYPTO_OPERATIONMODE_START) == CRYPTO_OPERATIONMODE_START)
    {
      retVal = vHsm_Core_DispatchService( objectId, job, CRYPTO_OPERATIONMODE_START );
      vHsm_Core_UpdateJobState( retVal, job );
    }

    if ((job->jobState == CRYPTO_JOBSTATE_IDLE)
      && ((job->jobPrimitiveInputOutput.mode & CRYPTO_OPERATIONMODE_START) != CRYPTO_OPERATIONMODE_START)) /* PRQA S 2995 */ /* MD_VHSM_2995_CONDITION_FALSE_IN_OTHER_CONFIGS */
    {
      /* [SWS_Crypto_00118] No Start flag while in idle mode */
      retVal = E_NOT_OK;
    }

    /* UPDATE while ACTIVE */
    if ((job->jobState == CRYPTO_JOBSTATE_ACTIVE)
      && ((job->jobPrimitiveInputOutput.mode & CRYPTO_OPERATIONMODE_UPDATE) == CRYPTO_OPERATIONMODE_UPDATE)) /* [SWS_Crypto_00024] */
    {
      retVal = vHsm_Core_DispatchService( objectId, job, CRYPTO_OPERATIONMODE_UPDATE );
      vHsm_Core_UpdateJobState( retVal, job );
    }

    /* [SWS_Crypto_00023] FINISH while ACTIVE */
    if ((job->jobState == CRYPTO_JOBSTATE_ACTIVE)
      && ((job->jobPrimitiveInputOutput.mode & CRYPTO_OPERATIONMODE_FINISH) == CRYPTO_OPERATIONMODE_FINISH)) /* [SWS_Crypto_00024] */
    {
      retVal = vHsm_Core_DispatchService( objectId, job, CRYPTO_OPERATIONMODE_FINISH );
      job->jobState = CRYPTO_JOBSTATE_IDLE;
      /* unlockingNecessary = TRUE; */
    }
  }

  /* ----- Development Error Report --------------------------------------- */
# if (VHSM_DEV_ERROR_REPORT == STD_ON)
  if (errorId != CRYPTO_E_NO_ERROR)
  {
    (void)Det_ReportError( VHSM_MODULE_ID, VHSM_INSTANCE_ID, VHSM_SID_PROCESS_JOB, errorId );
  }
# else
  VHSM_DUMMY_STATEMENT(errorId); /* PRQA S 3112, 1338, 2983 */ /* MD_MSR_DummyStmt */
# endif
#else
  VHSM_DUMMY_STATEMENT(job); /* PRQA S 3112, 1338, 2983 */ /* MD_MSR_DummyStmt */
  VHSM_DUMMY_STATEMENT(objectId); /* PRQA S 3112, 1338, 2983 */ /* MD_MSR_DummyStmt */
#endif
  return retVal;
}

/**********************************************************************************************************************
 *  vHsm_Core_CancelJob()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(Std_ReturnType, VHSM_CODE) vHsm_Core_CancelJob(
  uint32 objectId,
  P2VAR(Crypto_JobType, AUTOMATIC, VHSM_APPL_VAR) job) /* PRQA S 3673 */ /* MD_MSR_Rule8.13 */
{
  /* ----- Local Variables ---------------------------------------------- */

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Return always with an error because core jobs can not be canceled */
  VHSM_DUMMY_STATEMENT(objectId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  VHSM_DUMMY_STATEMENT(job); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */

  return E_NOT_OK;
} /* vHsm_Core_CancelJob() */

/**********************************************************************************************************************
 *  vHsm_Core_KeyElementSet()
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
 */
FUNC(Std_ReturnType, VHSM_CODE) vHsm_Core_KeyElementSet(
  uint32 cryptoKeyId,
  uint32 keyElementId,
  P2CONST(uint8, AUTOMATIC, VHSM_APPL_VAR) keyPtr,
  uint32 keyLength)
{
  Std_ReturnType retVal = E_NOT_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  /* #10 Decide which key operation shall be performed */
  switch (keyElementId)
  {
    /* #20 Check if the end of secure boot is reached */
  case CRYPTO_KE_CUSTOM_VHSM_SECURE_BOOT_END:
    vHsm_State.vHsm_SecureBootEndIndicationFlag = TRUE;
    retVal = E_OK;
    break;

    /* #30 Check if the lazy persist keys shall be persisted */
  case CRYPTO_KE_CUSTOM_VHSM_PERFORM_PERSISTING:
#if (VHSM_NVM_SUPPORT == STD_ON)
    retVal = vHsm_NvM_PerformWriteAll();
#endif
    break;

    /* #40 Check if repersisting of keys shall be performed */
  case CRYPTO_KE_CUSTOM_VHSM_PERFORM_REPERSISTING:
#if (VHSM_NVM_SUPPORT == STD_ON)
    retVal = vHsm_NvM_Repersist();
#endif
    break;

    /* #50 Check if jump to update shall be performed */
  case CRYPTO_KE_CUSTOM_VHSM_FIRMWARE_UPDATE_START_UPDATER:
#if (VHSM_FIRMWARE_UPDATE == STD_ON)
# if (VHSM_JUMP_TO_UPDATER_RESTRICTION == STD_ON)
    /* #51 Check if a successful firmware update job has been performed before */
    if (vHsm_State.vHsm_SuccessfulFirmwareUpdateFlag == TRUE)
# endif
    {
      vHsm_State.vHsm_JumpToUpdaterFlag = TRUE;
      retVal = E_OK;
    }
#endif
    break;

    /* #100 If no custom element is requested, redirect the request to the Crypto_30_LibCv */
  default:
    {
      if (cryptoKeyId == CryptoConf_CryptoKey_vHsmInfo)
      {
        uint32 cryptoKeyIdLibCv = vHsm_GetAggregatedCryptoKeyIdOfCoreKey(cryptoKeyId - VHSM_CORE_KEYID_START_OFFSET);
        if (cryptoKeyIdLibCv != VHSM_CORE_NO_AGGREGATION_KEY)
        {
          retVal = vHsm_Api_KeyElementSet(cryptoKeyIdLibCv, keyElementId, keyPtr, keyLength);
        }
      }
      else
      {
        retVal = vHsm_Api_KeyElementSet(cryptoKeyId, keyElementId, keyPtr, keyLength);
      }
    }
    break;
  }
  return retVal;
}

/**********************************************************************************************************************
 *  vHsm_Core_KeyValidSet()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
FUNC(Std_ReturnType, VHSM_CODE) vHsm_Core_KeyValidSet(
  uint32 cryptoKeyId)
{
  Std_ReturnType retVal = E_NOT_OK;

  /* #10 Check if the key is a core key */
  if (cryptoKeyId == CryptoConf_CryptoKey_vHsmInfo)
  {
    /* #11 Check if an aggregated key is available */
    uint32 cryptoKeyIdLibCv = vHsm_GetAggregatedCryptoKeyIdOfCoreKey(cryptoKeyId - VHSM_CORE_KEYID_START_OFFSET);
    if (cryptoKeyIdLibCv != VHSM_CORE_NO_AGGREGATION_KEY)
    {
      /* #12 Forward the call to the aggregated key */
      retVal = vHsm_Api_KeyValidSet(cryptoKeyIdLibCv);
    }
  }
  else
  {
    /* #20 Forward the call */
    retVal = vHsm_Api_KeyValidSet(cryptoKeyId);
  }

  return retVal;
}

/**********************************************************************************************************************
 *  vHsm_Core_KeyElementGet()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(Std_ReturnType, VHSM_CODE) vHsm_Core_KeyElementGet(
  uint32 cryptoKeyId,
  uint32 keyElementId,
  P2VAR(uint8, AUTOMATIC, VHSM_APPL_VAR) resultPtr,
  P2VAR(uint32, AUTOMATIC, VHSM_APPL_VAR) resultLengthPtr)
{
  Std_ReturnType retVal = E_NOT_OK;

  if (vHsm_Core_IsKey(CryptoConf_CryptoKey_vHsmSecureBootGroupInfo, cryptoKeyId) == TRUE)
  {
#if (VHSM_SECURE_BOOT == STD_ON)
    if (vHsm_Core_IsDestinationValid(resultLengthPtr, 2u) == TRUE)
    {
      vHsm_SecureBootGroupIterType group;
      for (group = 0u; group < vHsm_GetSizeOfSecureBootGroup(); group++)
      {
        if (vHsm_GetIdOfSecureBootGroup(group) == keyElementId)
        {
          resultPtr[0] = (uint8)vHsm_State.vHsm_SecureBootState.groupFinished[group]; /* PRQA S 4304 */ /* MD_MSR_AutosarBoolean */
          resultPtr[1] = (uint8)vHsm_State.vHsm_SecureBootState.groupResult[group];
          *resultLengthPtr = 2u;
          retVal = E_OK;
          break;
        }
      }
    }
#endif
  }
  else if (vHsm_Core_IsKey(CryptoConf_CryptoKey_vHsmLog, cryptoKeyId) == TRUE)
  {
#if(VHSM_LOG == STD_ON)
    retVal = vHsm_Log_GetEntry(keyElementId, vHsm_GetExportStrategyOfLogEvent(keyElementId), resultPtr, resultLengthPtr);
#endif
  }
  else
  {
    /* #10 Decide which key operation shall be performed */
    switch (keyElementId)
    {
      /* #20 Check if the version number shall be written */
    case CRYPTO_KE_CUSTOM_VHSM_VERSION:
      if (vHsm_Core_IsDestinationValid(resultLengthPtr, 3u) == TRUE)
      {
        /* Write the version info to the output */
        resultPtr[0] = (uint8)VHSM_SW_MAJOR_VERSION;
        resultPtr[1] = VHSM_SW_MINOR_VERSION;
        resultPtr[2] = VHSM_SW_PATCH_VERSION;

        /* Set the number of written bytes */
        *resultLengthPtr = 3u;

        retVal = E_OK;
      }
      break;
    case CRYPTO_KE_CUSTOM_VHSM_SECURE_BOOT_RESULT:
      if (vHsm_State.vHsm_SecureBootDoneFlag == FALSE)
      {
        /* Do nothing. Return value is already set. */
      }
      else if (vHsm_Core_IsDestinationValid(resultLengthPtr, 1u) == FALSE)
      {
        /* Do nothing. Return value is already set. */
      }
      else
      {
#if (VHSM_SECURE_BOOT == STD_ON)
        resultPtr[0] = vHsm_State.vHsm_SecureBootResult;
#else
        resultPtr[0] = CRYPTO_E_VER_OK;
#endif
        *resultLengthPtr = 1u;
        retVal = E_OK;
      }
      break;
    case CRYPTO_KE_CUSTOM_VHSM_SECURE_BOOT_END:
      if (vHsm_Core_IsDestinationValid(resultLengthPtr, 1u) == TRUE)
      {
#if (VHSM_SECURE_BOOT == STD_ON)
        resultPtr[0] = (uint8)vHsm_State.vHsm_SecureBootDoneFlag; /* PRQA S 4304 */ /* MD_MSR_AutosarBoolean */
#else
        resultPtr[0] = 1u;
#endif
        *resultLengthPtr = 1u;
        retVal = E_OK;
      }
      break;
    case CRYPTO_KE_CUSTOM_VHSM_ERRORLOG:
      {
#if (VHSM_ERRORLOGEVENTLOGREFOFGENERAL == STD_ON)
      /* Get log events */
        retVal = vHsm_Log_GetEntry(vHsm_GetErrorLogEventLogRefOfGeneral(), VHSM_EXPORT_ALL_FILO, resultPtr, resultLengthPtr); /* PRQA S 0310 */ /* MD_VHSM_0310_API_SPECIFIC_CAST */
#endif
      }
      break;

      /* #100 If no custom element is requested, redirect the request to the Crypto_30_LibCv */
    default:
      {
        if (cryptoKeyId == CryptoConf_CryptoKey_vHsmInfo)
        {
          uint32 cryptoKeyIdLibCv = vHsm_GetAggregatedCryptoKeyIdOfCoreKey(cryptoKeyId - VHSM_CORE_KEYID_START_OFFSET);
          if (cryptoKeyIdLibCv != VHSM_CORE_NO_AGGREGATION_KEY)
          {
            retVal = vHsm_Api_KeyElementGet(cryptoKeyIdLibCv, keyElementId, resultPtr, resultLengthPtr);
          }
        }
        else
        {
          retVal = vHsm_Api_KeyElementGet(cryptoKeyId, keyElementId, resultPtr, resultLengthPtr);
        }
      }
      break;
    }
  }

  return retVal;
} /* PRQA S 6030, 6080 */ /* MD_MSR_STCYC */ /* MD_MSR_STMIF */

#if(VHSM_ERRORLOGEVENTLOGREFOFGENERAL == STD_ON)
/**********************************************************************************************************************
 *  vHsm_Core_WriteErrorLog()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
FUNC(Std_ReturnType, VHSM_CODE) vHsm_Core_WriteErrorLog(
  uint32 errorId,
  uint32 errorData)
{
  Std_ReturnType retVal;
  uint32 vHsm_ErrorLogBuffer[2u];

  vHsm_Trace(VHSM_TRACETYPE_ERROR, "New Error-Log Entry added (errorId=%i, errorData=%i)\n", errorId, errorData);

  /* Add log event */
  vHsm_ErrorLogBuffer[0] = errorId;
  vHsm_ErrorLogBuffer[1] = errorData;
  retVal = vHsm_Log_AddEntry(vHsm_GetErrorLogEventLogRefOfGeneral(), (P2VAR(uint8, AUTOMATIC, VHSM_APPL_VAR))vHsm_ErrorLogBuffer, 8u); /* PRQA S 0310 */ /* MD_VHSM_0310_API_SPECIFIC_CAST */

  return retVal;
}
#endif

/**********************************************************************************************************************
 * vHsm_Core_CertificateParse()
 **********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
FUNC(Std_ReturnType, VHSM_CODE) vHsm_Core_CertificateParse(
  uint32 cryptoKeyId)
{
  VHSM_DUMMY_STATEMENT(cryptoKeyId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  return E_NOT_OK;
}

/**********************************************************************************************************************
 * vHsm_Core_CertificateVerify()
 **********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
FUNC(Std_ReturnType, VHSM_CODE) vHsm_Core_CertificateVerify(
  uint32 cryptoKeyId,
  uint32 verifyCryptoKeyId,
  P2VAR(Crypto_VerifyResultType, AUTOMATIC, VHSM_APPL_VAR) verifyPtr) /* PRQA S 3673 */ /* MD_MSR_Rule8.13 */
{
  VHSM_DUMMY_STATEMENT(cryptoKeyId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  VHSM_DUMMY_STATEMENT(verifyCryptoKeyId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  VHSM_DUMMY_STATEMENT(verifyPtr); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  return E_NOT_OK;
}

/**********************************************************************************************************************
 * vHsm_Core_KeyCopy()
 **********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
FUNC(Std_ReturnType, VHSM_CODE) vHsm_Core_KeyCopy(
  uint32 cryptoKeyId,
  uint32 targetCryptoKeyId)
{
  VHSM_DUMMY_STATEMENT(cryptoKeyId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  VHSM_DUMMY_STATEMENT(targetCryptoKeyId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  return E_NOT_OK;
}

/**********************************************************************************************************************
 * vHsm_Core_KeyDerive()
 **********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
FUNC(Std_ReturnType, VHSM_CODE) vHsm_Core_KeyDerive(
  uint32 cryptoKeyId,
  uint32 targetCryptoKeyId)
{
  VHSM_DUMMY_STATEMENT(cryptoKeyId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  VHSM_DUMMY_STATEMENT(targetCryptoKeyId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  return E_NOT_OK;
}

/**********************************************************************************************************************
 * vHsm_Core_KeyElementCopy()
 **********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
FUNC(Std_ReturnType, VHSM_CODE) vHsm_Core_KeyElementCopy(
  uint32 cryptoKeyId,
  uint32 keyElementId,
  uint32 targetCryptoKeyId,
  uint32 targetKeyElementId)
{
  VHSM_DUMMY_STATEMENT(cryptoKeyId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  VHSM_DUMMY_STATEMENT(targetCryptoKeyId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  VHSM_DUMMY_STATEMENT(keyElementId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  VHSM_DUMMY_STATEMENT(targetKeyElementId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  return E_NOT_OK;
}


/**********************************************************************************************************************
 * vHsm_Core_KeyElementCopyPartial()
 **********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
FUNC(Std_ReturnType, VHSM_CODE) vHsm_Core_KeyElementCopyPartial(
  uint32 cryptoKeyId,
  uint32 keyElementId,
  uint32 keyElementSourceOffset,
  uint32 keyElementTargetOffset,
  uint32 keyElementCopyLength,
  uint32 targetCryptoKeyId,
  uint32 targetKeyElementId)
{
  VHSM_DUMMY_STATEMENT(cryptoKeyId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  VHSM_DUMMY_STATEMENT(keyElementId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  VHSM_DUMMY_STATEMENT(keyElementSourceOffset); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  VHSM_DUMMY_STATEMENT(keyElementTargetOffset); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  VHSM_DUMMY_STATEMENT(keyElementCopyLength); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  VHSM_DUMMY_STATEMENT(targetCryptoKeyId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  VHSM_DUMMY_STATEMENT(targetKeyElementId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */

  /* Function is not used and is also called as stub for modules which do not support this ASR4.4 API */
  return E_NOT_OK;
} /* PRQA S 6060 */ /* MD_MSR_STPAR */

/**********************************************************************************************************************
 * vHsm_Core_KeyElementIdsGet()
 **********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
FUNC(Std_ReturnType, VHSM_CODE) vHsm_Core_KeyElementIdsGet(
  uint32 cryptoKeyId,
  P2VAR(uint32, AUTOMATIC, VHSM_APPL_VAR) keyElementIdsPtr, /* PRQA S 3673 */ /* MD_MSR_Rule8.13 */
  P2VAR(uint32, AUTOMATIC, VHSM_APPL_VAR) keyElementIdsLengthPtr) /* PRQA S 3673 */ /* MD_MSR_Rule8.13 */
{
  VHSM_DUMMY_STATEMENT(cryptoKeyId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  VHSM_DUMMY_STATEMENT(keyElementIdsPtr); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  VHSM_DUMMY_STATEMENT(keyElementIdsLengthPtr); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  return E_NOT_OK;
}

/**********************************************************************************************************************
 * vHsm_Core_KeyExchangeCalcPubVal()
 **********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
FUNC(Std_ReturnType, VHSM_CODE) vHsm_Core_KeyExchangeCalcPubVal(
  uint32 cryptoKeyId,
  P2VAR(uint8, AUTOMATIC, VHSM_APPL_VAR) publicValuePtr, /* PRQA S 3673 */ /* MD_MSR_Rule8.13 */
  P2VAR(uint32, AUTOMATIC, VHSM_APPL_VAR) publicValueLengthPtr) /* PRQA S 3673 */ /* MD_MSR_Rule8.13 */
{
  VHSM_DUMMY_STATEMENT(cryptoKeyId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  VHSM_DUMMY_STATEMENT(publicValuePtr); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  VHSM_DUMMY_STATEMENT(publicValueLengthPtr); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  return E_NOT_OK;
}

/**********************************************************************************************************************
 * vHsm_Core_KeyExchangeCalcSecret()
 **********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
FUNC(Std_ReturnType, VHSM_CODE) vHsm_Core_KeyExchangeCalcSecret(
  uint32 cryptoKeyId,
  P2CONST(uint8, AUTOMATIC, VHSM_APPL_VAR) partnerPublicValuePtr,
  uint32 partnerPublicValueLength)
{
  VHSM_DUMMY_STATEMENT(cryptoKeyId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  VHSM_DUMMY_STATEMENT(partnerPublicValuePtr); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  VHSM_DUMMY_STATEMENT(partnerPublicValueLength); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  return E_NOT_OK;
}

/**********************************************************************************************************************
 * vHsm_Core_KeyGenerate()
 **********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
FUNC(Std_ReturnType, VHSM_CODE) vHsm_Core_KeyGenerate(
  uint32 cryptoKeyId)
{
  VHSM_DUMMY_STATEMENT(cryptoKeyId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  return E_NOT_OK;
}

/**********************************************************************************************************************
 * vHsm_Core_RandomSeed()
 **********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
FUNC(Std_ReturnType, VHSM_CODE) vHsm_Core_RandomSeed(
  uint32 cryptoKeyId,
  P2CONST(uint8, AUTOMATIC, VHSM_APPL_DATA) entropyPtr,
  uint32 entropyLength)
{
  VHSM_DUMMY_STATEMENT(cryptoKeyId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  VHSM_DUMMY_STATEMENT(entropyPtr); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  VHSM_DUMMY_STATEMENT(entropyLength); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  return E_NOT_OK;
}

#define VHSM_STOP_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  END OF FILE: vHsm_Core.c
 *********************************************************************************************************************/

