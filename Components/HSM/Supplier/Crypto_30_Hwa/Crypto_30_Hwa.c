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
/*!        \file  Crypto_30_Hwa.c
 *        \brief  vHsm platform hardware abstraction library
 *
 *      \details  This file implements the hardware abstraction library which is used by the vHsm Core.
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 *********************************************************************************************************************/

#define CRYPTO_30_HWA_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

#include "Crypto_30_Hwa.h"
#include "Crypto_30_Hwa_Hw.h"
#include "Crypto_30_Hwa_Private.h"
#include "Crypto_30_Hwa_Custom.h"

#include "vHsm_Api.h"
#include "Det.h"
#include "CryIf_Cbk.h"

/**********************************************************************************************************************
 *  VERSION CHECK
 *********************************************************************************************************************/

/* vendor specific version information is BCD coded */
#if (  (CRYPTO_30_HWA_SW_MAJOR_VERSION != (0x01)) \
    || (CRYPTO_30_HWA_SW_MINOR_VERSION != (0x04)) \
    || (CRYPTO_30_HWA_SW_PATCH_VERSION != (0x00)) )
# error "Vendor specific version numbers of Crypto_30_Hwa.c and Crypto_30_Hwa.h are inconsistent"
#endif

/**********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 *********************************************************************************************************************/
#if !defined (CRYPTO_30_HWA_LOCAL) /* COV_CRYPTO_30_HWA_LOCAL_DEFINE */
# define CRYPTO_30_HWA_LOCAL                                                 static
#endif

#if !defined (CRYPTO_30_HWA_LOCAL_INLINE) /* COV_CRYPTO_30_HWA_LOCAL_DEFINE */
# define CRYPTO_30_HWA_LOCAL_INLINE                                          LOCAL_INLINE
#endif

/* Driver Object states */
#define CRYPTO_30_HWA_DRIVEROBJECTSTATE_IDLE                                 (0x00u)
#define CRYPTO_30_HWA_DRIVEROBJECTSTATE_PROCESSING                           (0x01u)

/**********************************************************************************************************************
 *  LOCAL FUNCTION MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA PROTOTYPES
 *********************************************************************************************************************/

#define CRYPTO_30_HWA_START_SEC_VAR_ZERO_INIT_8BIT
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#if (CRYPTO_30_HWA_DEV_ERROR_DETECT == STD_ON)
/*! Initialization state of the module */
CRYPTO_30_HWA_LOCAL VAR(uint8, CRYPTO_30_HWA_VAR_ZERO_INIT) Crypto_30_Hwa_ModuleInitialized = CRYPTO_30_HWA_UNINIT;
#endif

#define CRYPTO_30_HWA_STOP_SEC_VAR_ZERO_INIT_8BIT
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

#define CRYPTO_30_HWA_START_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#if (CRYPTO_30_HWA_OBJECTINFO == STD_ON)
/**********************************************************************************************************************
 *  Crypto_30_Hwa_TryObtainingLock()
 *********************************************************************************************************************/
/*! \brief          Try to lock driver object.
 *  \details        Try to lock the workspace and the key for the job.
 *  \param[in]      objectId          Driver object to be locked.
 *  \param[in]      jobId             Job that wants to lock the driver object.
 *  \param[in]      cryptoKeyId       Key to be locked.
 *  \param[in]      mode              Operation mode of job.
 *  \return         E_OK              Lock is obtained or was already obtained.
 *  \return         E_NOT_OK          Request Failed
 *  \return         CRYPTO_E_BUSY     Lock is occupied by other job.
 *  \pre            objectId has to be valid.
 *                  Has to be called inside an exclusive area which protects the lock.
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
CRYPTO_30_HWA_LOCAL_INLINE FUNC(Std_ReturnType, CRYPTO_30_HWA_CODE) Crypto_30_Hwa_TryObtainingLock(
  uint32 objectId,
  uint32 jobId,
  uint32 cryptoKeyId,
  Crypto_OperationModeType mode);

/**********************************************************************************************************************
 *  Crypto_30_Hwa_DispatchService()
 *********************************************************************************************************************/
/*! \brief         Dispatches the job to a service
 *  \details       This function dispatches the provided job to the service as specified in the job configuration.
 *  \param[in]     objectId           Holds the identifier of the Crypto Driver Object.
 *  \param[in,out] job                Pointer to the job which shall be dispatched.
 *  \return        E_OK               Dispatching was successful.
 *  \return        E_NOT_OK           Dispatching failed.
 *  \pre           objectId has to be a valid driver object handle.
 *  \context       TASK
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
CRYPTO_30_HWA_LOCAL_INLINE FUNC(Std_ReturnType, CRYPTO_30_HWA_CODE) Crypto_30_Hwa_DispatchService(
  uint32 objectId,
  Crypto_30_Hwa_JobPtrType job);
#endif /* (CRYPTO_30_HWA_OBJECTINFO == STD_ON) */

#if (CRYPTO_30_HWA_DEV_ERROR_DETECT == STD_ON)
# if (CRYPTO_30_HWA_SERVICE_HASH == STD_ON) /* COV_CRYPTO_30_HWA_HARDWARE_DEPENDENT_FEATURE */
/**********************************************************************************************************************
 *  Crypto_30_Hwa_Local_DetChecksServiceValues_Hash()
 *********************************************************************************************************************/
/*! \brief         Det Checks for the Hash service parameters.
 *  \details       This function checks the Det-Checks for all required in- and output-values.
 *  \param[in]     job                Pointer to the job which shall be dispatched.
 *  \return        CRYPTO_E_NO_ERROR        No Det error detected.
 *  \return        CRYPTO_E_PARAM_POINTER   Parameter is a invalid pointer error.
 *  \return        CRYPTO_E_PARAM_VALUE     Parameter is a invalid value error.
 *  \pre           job has to be a valid job object.
 *  \context       TASK
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
CRYPTO_30_HWA_LOCAL_INLINE FUNC(uint8, CRYPTO_30_HWA_CODE) Crypto_30_Hwa_Local_DetChecksServiceValues_Hash(
  P2CONST(Crypto_JobType, AUTOMATIC, CRYPTO_30_HWA_APPL_VAR) job);
# endif /* (CRYPTO_30_HWA_SERVICE_HASH == STD_ON) */

# if (CRYPTO_30_HWA_SERVICE_MAC_GENERATE == STD_ON) /* COV_CRYPTO_30_HWA_HARDWARE_DEPENDENT_FEATURE */
/**********************************************************************************************************************
 *  Crypto_30_Hwa_Local_DetChecksServiceValues_MacGenerate()
 *********************************************************************************************************************/
/*! \brief         Det Checks for the Mac generate service parameters.
 *  \details       This function checks the Det-Checks for all required in- and output-values.
 *  \param[in]     job                Pointer to the job which shall be dispatched.
 *  \return        CRYPTO_E_NO_ERROR        No Det error detected.
 *  \return        CRYPTO_E_PARAM_POINTER   Parameter is a invalid pointer error.
 *  \return        CRYPTO_E_PARAM_VALUE     Parameter is a invalid value error.
 *  \pre           job has to be a valid job object.
 *  \context       TASK
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
CRYPTO_30_HWA_LOCAL_INLINE FUNC(uint8, CRYPTO_30_HWA_CODE) Crypto_30_Hwa_Local_DetChecksServiceValues_MacGenerate(
  P2CONST(Crypto_JobType, AUTOMATIC, CRYPTO_30_HWA_APPL_VAR) job);
# endif /* (CRYPTO_30_HWA_SERVICE_MAC_GENERATE == STD_ON) */

# if (CRYPTO_30_HWA_SERVICE_MAC_VERIFY == STD_ON) /* COV_CRYPTO_30_HWA_HARDWARE_DEPENDENT_FEATURE */
/**********************************************************************************************************************
 *  Crypto_30_Hwa_Local_DetChecksServiceValues_MacVerify()
 *********************************************************************************************************************/
/*! \brief         Det Checks for the Mac verify service parameters.
 *  \details       This function checks the Det-Checks for all required in- and output-values.
 *  \param[in]     job                Pointer to the job which shall be dispatched.
 *  \return        CRYPTO_E_NO_ERROR        No Det error detected.
 *  \return        CRYPTO_E_PARAM_POINTER   Parameter is a invalid pointer error.
 *  \return        CRYPTO_E_PARAM_VALUE     Parameter is a invalid value error.
 *  \pre           job has to be a valid job object.
 *  \context       TASK
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
CRYPTO_30_HWA_LOCAL_INLINE FUNC(uint8, CRYPTO_30_HWA_CODE) Crypto_30_Hwa_Local_DetChecksServiceValues_MacVerify(
  P2CONST(Crypto_JobType, AUTOMATIC, CRYPTO_30_HWA_APPL_VAR) job);
# endif /* (CRYPTO_30_HWA_SERVICE_MAC_VERIFY == STD_ON) */

# if (CRYPTO_30_HWA_SERVICE_ENCRYPT == STD_ON) /* COV_CRYPTO_30_HWA_HARDWARE_DEPENDENT_FEATURE */
/**********************************************************************************************************************
 *  Crypto_30_Hwa_Local_DetChecksServiceValues_Encrypt()
 *********************************************************************************************************************/
/*! \brief         Det Checks for the encrypt service parameters.
 *  \details       This function checks the Det-Checks for all required in- and output-values.
 *  \param[in]     job                Pointer to the job which shall be dispatched.
 *  \return        CRYPTO_E_NO_ERROR        No Det error detected.
 *  \return        CRYPTO_E_PARAM_POINTER   Parameter is a invalid pointer error.
 *  \return        CRYPTO_E_PARAM_VALUE     Parameter is a invalid value error.
 *  \pre           job has to be a valid job object.
 *  \context       TASK
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
CRYPTO_30_HWA_LOCAL_INLINE FUNC(uint8, CRYPTO_30_HWA_CODE) Crypto_30_Hwa_Local_DetChecksServiceValues_Encrypt(
  P2CONST(Crypto_JobType, AUTOMATIC, CRYPTO_30_HWA_APPL_VAR) job);
# endif /* (CRYPTO_30_HWA_SERVICE_ENCRYPT == STD_ON) */

# if (CRYPTO_30_HWA_SERVICE_DECRYPT == STD_ON) /* COV_CRYPTO_30_HWA_HARDWARE_DEPENDENT_FEATURE */
/**********************************************************************************************************************
 *  Crypto_30_Hwa_Local_DetChecksServiceValues_Decrypt()
 *********************************************************************************************************************/
/*! \brief         Det Checks for the decrypt service parameters.
 *  \details       This function checks the Det-Checks for all required in- and output-values.
 *  \param[in]     job                Pointer to the job which shall be dispatched.
 *  \return        CRYPTO_E_NO_ERROR        No Det error detected.
 *  \return        CRYPTO_E_PARAM_POINTER   Parameter is a invalid pointer error.
 *  \return        CRYPTO_E_PARAM_VALUE     Parameter is a invalid value error.
 *  \pre           job has to be a valid job object.
 *  \context       TASK
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
CRYPTO_30_HWA_LOCAL_INLINE FUNC(uint8, CRYPTO_30_HWA_CODE) Crypto_30_Hwa_Local_DetChecksServiceValues_Decrypt(
  P2CONST(Crypto_JobType, AUTOMATIC, CRYPTO_30_HWA_APPL_VAR) job);
# endif /* (CRYPTO_30_HWA_SERVICE_DECRYPT == STD_ON) */

# if (CRYPTO_30_HWA_SERVICE_AEADENCRYPT == STD_ON) /* COV_CRYPTO_30_HWA_HARDWARE_DEPENDENT_FEATURE */
/**********************************************************************************************************************
 *  Crypto_30_Hwa_Local_DetChecksServiceValues_AeadEncrypt()
 *********************************************************************************************************************/
/*! \brief         Det Checks for the AEAD Encrypt service parameters.
 *  \details       This function checks the Det-Checks for all required in- and output-values.
 *  \param[in]     job                      Pointer to the job which shall be dispatched.
 *  \return        CRYPTO_E_NO_ERROR        No Det error detected.
 *  \return        CRYPTO_E_PARAM_HANDLE    Parameter is not supported by crypto driver.
 *  \pre           job has to be a valid job object.
 *  \context       TASK
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
CRYPTO_30_HWA_LOCAL_INLINE FUNC(uint8, CRYPTO_30_HWA_CODE) Crypto_30_Hwa_Local_DetChecksServiceValues_AeadEncrypt(
  P2CONST(Crypto_JobType, AUTOMATIC, CRYPTO_30_HWA_APPL_VAR) job);
#endif /* (CRYPTO_30_HWA_SERVICE_AEADENCRYPT == STD_ON)  */

# if (CRYPTO_30_HWA_SERVICE_AEADDECRYPT == STD_ON) /* COV_CRYPTO_30_HWA_HARDWARE_DEPENDENT_FEATURE */
/**********************************************************************************************************************
 * Crypto_30_Hwa_Local_DetChecksServiceValues_AeadDecrypt()
 **********************************************************************************************************************/
/*! \brief         Det Checks for the AEAD decrypt service parameters.
 *  \details       This function checks the Det-Checks for all required in- and output-values.
 *  \param[in]     job                      Pointer to the job which shall be dispatched.
 *  \return        CRYPTO_E_NO_ERROR        No Det error detected.
 *  \return        CRYPTO_E_PARAM_HANDLE    Parameter is not supported by crypto driver.
 *  \pre           job has to be a valid job object.
 *  \context       TASK
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
CRYPTO_30_HWA_LOCAL_INLINE FUNC(uint8, CRYPTO_30_HWA_CODE) Crypto_30_Hwa_Local_DetChecksServiceValues_AeadDecrypt(
  P2CONST(Crypto_JobType, AUTOMATIC, CRYPTO_30_HWA_APPL_VAR) job);
#endif /* (CRYPTO_30_HWA_SERVICE_AEADDECRYPT == STD_ON) */

# if (CRYPTO_30_HWA_SERVICE_SIGNATURE_GENERATE == STD_ON) /* COV_CRYPTO_30_HWA_HARDWARE_DEPENDENT_FEATURE */
/**********************************************************************************************************************
 * Crypto_30_Hwa_Local_DetChecksServiceValues_SignatureGenerate()
 **********************************************************************************************************************/
/*! \brief         Det Checks for the Signature Verify service parameters.
 *  \details       This function checks the Det-Checks for all required in- and output-values.
 *  \param[in]     job                      Pointer to the job which shall be dispatched.
 *  \return        CRYPTO_E_NO_ERROR        No Det error detected.
 *  \return        CRYPTO_E_PARAM_HANDLE    Parameter is not supported by crypto driver.
 *  \pre           job has to be a valid job object.
 *  \context       TASK
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
CRYPTO_30_HWA_LOCAL_INLINE FUNC(uint8, CRYPTO_30_HWA_CODE) Crypto_30_Hwa_Local_DetChecksServiceValues_SignatureGenerate(
  P2CONST(Crypto_JobType, AUTOMATIC, CRYPTO_30_HWA_APPL_VAR) job);
#endif /* (CRYPTO_30_HWA_SERVICE_SIGNATURE_GENERATE == STD_ON) */

# if (CRYPTO_30_HWA_SERVICE_SIGNATURE_VERIFY == STD_ON) /* COV_CRYPTO_30_HWA_HARDWARE_DEPENDENT_FEATURE */
/**********************************************************************************************************************
 * Crypto_30_Hwa_Local_DetChecksServiceValues_SignatureVerify()
 **********************************************************************************************************************/
/*! \brief         Det Checks for the Signature Verify service parameters.
 *  \details       This function checks the Det-Checks for all required in- and output-values.
 *  \param[in]     job                      Pointer to the job which shall be dispatched.
 *  \return        CRYPTO_E_NO_ERROR        No Det error detected.
 *  \return        CRYPTO_E_PARAM_HANDLE    Parameter is not supported by crypto driver.
 *  \pre           job has to be a valid job object.
 *  \context       TASK
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
CRYPTO_30_HWA_LOCAL_INLINE FUNC(uint8, CRYPTO_30_HWA_CODE) Crypto_30_Hwa_Local_DetChecksServiceValues_SignatureVerify(
  P2CONST(Crypto_JobType, AUTOMATIC, CRYPTO_30_HWA_APPL_VAR) job);
#endif /* (CRYPTO_30_HWA_SERVICE_SIGNATURE_VERIFY == STD_ON) */

# if (CRYPTO_30_HWA_SERVICE_RANDOM == STD_ON) /* COV_CRYPTO_30_HWA_HARDWARE_DEPENDENT_FEATURE */
/**********************************************************************************************************************
 *  Crypto_30_Hwa_Local_DetChecksServiceValues_Random()
 *********************************************************************************************************************/
/*! \brief         Det Checks for the random service parameters.
 *  \details       This function checks the Det-Checks for all required in- and output-values.
 *  \param[in]     job                Pointer to the job which shall be dispatched.
 *  \return        CRYPTO_E_NO_ERROR        No Det error detected.
 *  \return        CRYPTO_E_PARAM_POINTER   Parameter is a invalid pointer error.
 *  \return        CRYPTO_E_PARAM_VALUE     Parameter is a invalid value error.
 *  \pre           job has to be a valid job object.
 *  \context       TASK
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
CRYPTO_30_HWA_LOCAL_INLINE FUNC(uint8, CRYPTO_30_HWA_CODE) Crypto_30_Hwa_Local_DetChecksServiceValues_Random(
  P2CONST(Crypto_JobType, AUTOMATIC, CRYPTO_30_HWA_APPL_VAR) job);
# endif /* (CRYPTO_30_HWA_SERVICE_RANDOM == STD_ON) */

# if (CRYPTO_30_HWA_OBJECTINFO == STD_ON)
/**********************************************************************************************************************
 *  Crypto_30_Hwa_Local_DetChecksServiceValues()
 *********************************************************************************************************************/
/*! \brief         Det Checks for the Service parameters.
 *  \details       This function checks the Det-Checks for all required in- and output-values.
 *  \param[in]     job                Pointer to the job which shall be dispatched.
 *  \param[out]    errorId            Output Pointer to the detected Error-Type-Id
 *  \return        E_OK               No Det error detected.
 *  \return        E_NOT_OK           Det error detected.
 *  \pre           objectId has to be a valid driver object handle.
 *                 errorId has to be a valid pointer.
 *                 job has to be a valid job object.
 *  \context       TASK
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
CRYPTO_30_HWA_LOCAL_INLINE FUNC(Std_ReturnType, CRYPTO_30_HWA_CODE) Crypto_30_Hwa_Local_DetChecksServiceValues(
  P2CONST(Crypto_JobType, AUTOMATIC, CRYPTO_30_HWA_APPL_VAR) job,
  P2VAR(uint8, AUTOMATIC, CRYPTO_30_HWA_APPL_VAR) errorId);
# endif /* (CRYPTO_30_HWA_OBJECTINFO == STD_ON) */
#endif /* (CRYPTO_30_HWA_DEV_ERROR_DETECT == STD_ON) */

#if (CRYPTO_30_HWA_OBJECTINFO == STD_ON)
/**********************************************************************************************************************
 *  Crypto_30_Hwa_Process()
 *********************************************************************************************************************/
/*! \brief         Processes the received job
 *  \details       Performs the crypto primitive, that is configured in the job parameter. Takes care of jobs operation mode.
 *  \param[in]     objectId                Holds the identifier of the Crypto Driver Object.
 *  \param[in,out] job                     Pointer to the configuration of the job. Contains structures with job and
 *                                         primitive relevant information but also pointer to result buffers.
 *  \return        E_OK                    Request successful.
 *  \return        E_NOT_OK                Request failed.
 *  \return        CRYPTO_E_BUSY           Request failed, Crypto Driver Object is busy.
 *  \return        CRYPTO_E_KEY_NOT_VALID  Request failed, the key is not valid.
 *  \return        CRYPTO_E_QUEUE_FULL     Request failed, the queue is full.
 *  \return        CRYPTO_E_SMALL_BUFFER   Request failed, the provided buffer is too small to store the result.
 *  \pre           Lock has to be reserved for the job object.
 *                 objectId has to be a valid driver object handle.
 *                 job has to be a job object handle.
 *  \context       TASK
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
CRYPTO_30_HWA_LOCAL_INLINE FUNC(Std_ReturnType, CRYPTO_30_HWA_CODE) Crypto_30_Hwa_Process(
  uint32 objectId,
  Crypto_30_Hwa_JobPtrType job);
#endif

#define CRYPTO_30_HWA_STOP_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

#define CRYPTO_30_HWA_START_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#if (CRYPTO_30_HWA_OBJECTINFO == STD_ON)
/**********************************************************************************************************************
 *  Crypto_30_Hwa_TryObtainingLock()
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
CRYPTO_30_HWA_LOCAL_INLINE FUNC(Std_ReturnType, CRYPTO_30_HWA_CODE) Crypto_30_Hwa_TryObtainingLock(
  uint32 objectId,
  uint32 jobId,
  uint32 cryptoKeyId,
  Crypto_OperationModeType mode)
{
  Std_ReturnType retVal, localRetVal;

  /* Is driver object already locked by job? */
  if (Crypto_30_Hwa_IsLockOccupiedByJob(objectId, jobId))
  {
    retVal = E_OK;
  }
  else if ((mode & CRYPTO_OPERATIONMODE_START) == CRYPTO_OPERATIONMODE_START)
  {
    retVal = CRYPTO_E_BUSY;
    if (Crypto_30_Hwa_IsLockFree(objectId))
    {
      /* Try to lock aggregated key in case of Rom key id */
#if (CRYPTO_30_HWA_ROMKEY == STD_ON) /* COV_CRYPTO_30_HWA_HARDWARE_DEPENDENT_FEATURE */
      /* Verify that key is hardware key */
      if (cryptoKeyId >= CRYPTO_30_HWA_ROMKEY_MASK)
      {
        if ((Crypto_30_Hwa_GetAggregatedCryptoKeyIdOfKeyMap(cryptoKeyId - CRYPTO_30_HWA_ROMKEY_MASK)) != 0xFFFFFFFFu)
        {
          localRetVal = vHsm_Api_KeyReadLockGetNotProtected(Crypto_30_Hwa_GetAggregatedCryptoKeyIdOfKeyMap(cryptoKeyId - CRYPTO_30_HWA_ROMKEY_MASK));
        }
        else
        {
          localRetVal = E_OK;
        }
      }
      else
#endif
      {
        localRetVal = vHsm_Api_KeyReadLockGetNotProtected(cryptoKeyId);
      }

      if (localRetVal == E_OK)
      {
        /* Lock driver object for job */
        Crypto_30_Hwa_SetLock(objectId, jobId); /* SBSW_CRYPTO_30_HWA_CSL01_OBJECTID */
        retVal = E_OK;
      }
    }
  }
  else
  {
    /* [SWS_Crypto_00118] No Start flag while in idle mode */
    retVal = E_NOT_OK;
  }

  return retVal;
} /* Crypto_30_Hwa_TryObtainingLock() */ /* PRQA S 6080 */ /* MD_MSR_STMIF */

/**********************************************************************************************************************
 * Crypto_30_Hwa_Process()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
CRYPTO_30_HWA_LOCAL_INLINE FUNC(Std_ReturnType, CRYPTO_30_HWA_CODE) Crypto_30_Hwa_Process(
  uint32 objectId,
  Crypto_30_Hwa_JobPtrType job)
{
  Std_ReturnType retVal;
#if (CRYPTO_30_HWA_ROMKEY == STD_ON) /* COV_CRYPTO_30_HWA_HARDWARE_DEPENDENT_FEATURE */
  uint32 cryptoKeyIdTemp = job->cryptoKeyId;
#endif

  retVal = Crypto_30_Hwa_DispatchService(objectId, job); /* SBSWCRYPTO_30_HWA_FORWARDING_OF_JOB_PTR */

  /* Free workspace in case of an error or if FINISH mode completed. */
  if ((retVal != E_OK)
    || ((job->state == CRYPTO_JOBSTATE_IDLE)
         && Crypto_30_Hwa_IsJobMode(job, CRYPTO_OPERATIONMODE_FINISH)))
  {
    SchM_Enter_Crypto_30_Hwa_CRYPTO_30_HWA_EXCLUSIVE_AREA_0();
    Crypto_30_Hwa_FreeLock(objectId); /* SBSW_CRYPTO_30_HWA_CSL01_OBJECTID */

#if (CRYPTO_30_HWA_ROMKEY == STD_ON) /* COV_CRYPTO_30_HWA_HARDWARE_DEPENDENT_FEATURE */
    /* Verify that key is hardware key */
    if (Crypto_30_Hwa_CheckAggregatedKeyId(&cryptoKeyIdTemp) == E_OK)
    {
      vHsm_Api_KeyReadLockReleaseNotProtected(cryptoKeyIdTemp);
    }
#else
    vHsm_Api_KeyReadLockReleaseNotProtected(job->cryptoKeyId);
#endif

    SchM_Exit_Crypto_30_Hwa_CRYPTO_30_HWA_EXCLUSIVE_AREA_0();
  }

  return retVal;
} /* Crypto_30_Hwa_Process() */ /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

/**********************************************************************************************************************
 *  Crypto_30_Hwa_DispatchService()
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
 *
 */
CRYPTO_30_HWA_LOCAL_INLINE FUNC(Std_ReturnType, CRYPTO_30_HWA_CODE) Crypto_30_Hwa_DispatchService(
  uint32 objectId,
  Crypto_30_Hwa_JobPtrType job)
{
  Std_ReturnType retVal = E_NOT_OK;
  uint8 errorId = CRYPTO_E_PARAM_HANDLE;

  /* #10 Dispatch service */
  switch(job->jobPrimitiveInfo->primitiveInfo->service)
  {

    /* #20 Check if requested service is encryption/decryption service */
#if (CRYPTO_30_HWA_PRIMITIVE_AES_CIPHER == STD_ON) /* COV_CRYPTO_30_HWA_HARDWARE_DEPENDENT_FEATURE */
# if (CRYPTO_30_HWA_SERVICE_ENCRYPT == STD_ON) /* COV_CRYPTO_30_HWA_HARDWARE_DEPENDENT_FEATURE */
    case CRYPTO_ENCRYPT:
    {
      if (Crypto_30_Hwa_IsAesEncryptUsedOfObjectInfo(objectId) == TRUE)
      {
        Crypto_30_Hwa_WorkSpaceAES_PtrType workspace;
        /* #21 Get workspace and forward request to AES encryption service */
        workspace = Crypto_30_Hwa_GetWorkspaceOfAesEncrypt(Crypto_30_Hwa_GetAesEncryptIdxOfObjectInfo(objectId));
        retVal = Crypto_30_Hwa_ProcessAesJob(objectId, &errorId, job, workspace);
      }
      break;
    }
# endif /* (CRYPTO_30_HWA_SERVICE_ENCRYPT == STD_ON) */

# if (CRYPTO_30_HWA_SERVICE_DECRYPT == STD_ON)  /* COV_CRYPTO_30_HWA_HARDWARE_DEPENDENT_FEATURE */
    case CRYPTO_DECRYPT:
    {
      if(Crypto_30_Hwa_IsAesDecryptUsedOfObjectInfo(objectId) == TRUE)
      {
        Crypto_30_Hwa_WorkSpaceAES_PtrType workspace;
        /* #25 Get workspace and forward request to AES decryption service */
        workspace = Crypto_30_Hwa_GetWorkspaceOfAesDecrypt(Crypto_30_Hwa_GetAesDecryptIdxOfObjectInfo(objectId));
        retVal = Crypto_30_Hwa_ProcessAesJob(objectId, &errorId, job, workspace);
      }
      break;
    }
# endif /* (CRYPTO_30_HWA_SERVICE_DECRYPT == STD_ON) */
#endif /* (CRYPTO_30_HWA_PRIMITIVE_AES_CIPHER == STD_ON) */

    /* #30 Check if requested service is AEAD encryption/decryption service */
#if(CRYPTO_30_HWA_SERVICE_AEADENCRYPT == STD_ON) /* COV_CRYPTO_30_HWA_HARDWARE_DEPENDENT_FEATURE */
    case CRYPTO_AEADENCRYPT:
    {
      if (job->jobPrimitiveInfo->primitiveInfo->algorithm.family == CRYPTO_ALGOFAM_AES)
      {
        /* Check which algorithm mode to use */
        if (job->jobPrimitiveInfo->primitiveInfo->algorithm.mode == CRYPTO_ALGOMODE_GCM)
        {
# if (CRYPTO_30_HWA_AESGCMENCRYPT == STD_ON) /* COV_CRYPTO_30_HWA_HARDWARE_DEPENDENT_FEATURE */
          if (Crypto_30_Hwa_IsAesGcmEncryptUsedOfObjectInfo(objectId) == TRUE)
          {
            Crypto_30_Hwa_WorkSpaceGCM_PtrType workspace;

            /* #31 Get workspace and forward request to AES GCM encryption service */
            workspace = Crypto_30_Hwa_GetWorkspaceOfAesGcmEncrypt(Crypto_30_Hwa_GetAesGcmEncryptIdxOfObjectInfo(objectId));
            retVal = Crypto_30_Hwa_ProcessAeadJobAesGcm(objectId, &errorId, job, workspace);
          }
# endif /* (CRYPTO_30_HWA_AESGCMENCRYPT == STD_ON) */
        }
        else if(job->jobPrimitiveInfo->primitiveInfo->algorithm.mode == CRYPTO_ALGOMODE_CUSTOM_AES_GSM_SIV)
        {
# if (CRYPTO_30_HWA_AESGCMSIVENCRYPT == STD_ON) /* COV_CRYPTO_30_HWA_HARDWARE_DEPENDENT_FEATURE */
          if (Crypto_30_Hwa_IsAesGcmSivEncryptUsedOfObjectInfo(objectId) == TRUE)
          {
            Crypto_30_Hwa_WorkSpaceGCMSIV_PtrType workspace;

            /* #32 Get workspace and forward request to AES GCM SIV encryption service */
            workspace = Crypto_30_Hwa_GetWorkspaceOfAesGcmSivEncrypt(Crypto_30_Hwa_GetAesGcmSivEncryptIdxOfObjectInfo(objectId));
            retVal = Crypto_30_Hwa_ProcessAeadJobAesGcmSiv(objectId, &errorId, job, workspace);
          }
# endif /* (CRYPTO_30_HWA_AESGCMSIVENCRYPT == STD_ON) */
        }
        else
        {
          /* Unknown algorithm mode */
        }
      }

      break;
    }
#endif /*(CRYPTO_30_HWA_SERVICE_AEADENCRYPT == STD_ON)*/

#if(CRYPTO_30_HWA_SERVICE_AEADDECRYPT == STD_ON) /* COV_CRYPTO_30_HWA_HARDWARE_DEPENDENT_FEATURE */
    case CRYPTO_AEADDECRYPT:
    {
      if (job->jobPrimitiveInfo->primitiveInfo->algorithm.family == CRYPTO_ALGOFAM_AES)
      {
        /* Check which algorithm mode to use */
        if (job->jobPrimitiveInfo->primitiveInfo->algorithm.mode == CRYPTO_ALGOMODE_GCM)
        {
# if (CRYPTO_30_HWA_AESGCMDECRYPT == STD_ON) /* COV_CRYPTO_30_HWA_HARDWARE_DEPENDENT_FEATURE */
          if (Crypto_30_Hwa_IsAesGcmDecryptUsedOfObjectInfo(objectId) == TRUE)
          {
            Crypto_30_Hwa_WorkSpaceGCM_PtrType workspace;

            /* #35 Get workspace and forward request to AES GCM decryption service */
            workspace = Crypto_30_Hwa_GetWorkspaceOfAesGcmDecrypt(Crypto_30_Hwa_GetAesGcmDecryptIdxOfObjectInfo(objectId));
            retVal = Crypto_30_Hwa_ProcessAeadJobAesGcm(objectId, &errorId, job, workspace);
          }
# endif /* (CRYPTO_30_HWA_AESGCMDECRYPT == STD_ON) */
        }
        else if(job->jobPrimitiveInfo->primitiveInfo->algorithm.mode == CRYPTO_ALGOMODE_CUSTOM_AES_GSM_SIV)
        {
# if (CRYPTO_30_HWA_AESGCMSIVDECRYPT == STD_ON) /* COV_CRYPTO_30_HWA_HARDWARE_DEPENDENT_FEATURE */
          if (Crypto_30_Hwa_IsAesGcmSivDecryptUsedOfObjectInfo(objectId) == TRUE)
          {
            Crypto_30_Hwa_WorkSpaceGCMSIV_PtrType workspace;

            /* #36 Get workspace and forward request to AES GCM SIV decryption service */
            workspace = Crypto_30_Hwa_GetWorkspaceOfAesGcmSivDecrypt(Crypto_30_Hwa_GetAesGcmSivDecryptIdxOfObjectInfo(objectId));
            retVal = Crypto_30_Hwa_ProcessAeadJobAesGcmSiv(objectId, &errorId, job, workspace);
          }
# endif /* (CRYPTO_30_HWA_AESGCMSIVDECRYPT == STD_ON) */
        }
        else
        {
          /* Unknown algorithm mode */
        }
      }
      break;
    }
#endif /* (CRYPTO_30_HWA_SERVICE_AEADDECRYPT == STD_ON) */

    /* #40 Check if requested service is MAC service */
#if(CRYPTO_30_HWA_PRIMITIVE_AES_CMAC == STD_ON) /* COV_CRYPTO_30_HWA_HARDWARE_DEPENDENT_FEATURE */
# if(CRYPTO_30_HWA_SERVICE_MAC_GENERATE == STD_ON) /* COV_CRYPTO_30_HWA_HARDWARE_DEPENDENT_FEATURE */
    case CRYPTO_MACGENERATE:
    {
      if (Crypto_30_Hwa_IsCmacAesGenerateUsedOfObjectInfo(objectId) == TRUE)
      {
        Crypto_30_Hwa_WorkSpaceCMACAES_PtrType workspace;

        /* #41 Get workspace and forward request to CMAC generate service */
        workspace = Crypto_30_Hwa_GetWorkspaceOfCmacAesGenerate(Crypto_30_Hwa_GetCmacAesGenerateIdxOfObjectInfo(objectId));
        retVal = Crypto_30_Hwa_ProcessCmacJob(objectId, &errorId, job, FALSE, workspace);
      }
      break;
    }
# endif /* (CRYPTO_30_HWA_SERVICE_MAC_GENERATE == STD_ON) */

# if(CRYPTO_30_HWA_SERVICE_MAC_VERIFY== STD_ON)
    case CRYPTO_MACVERIFY:
    {
      if (Crypto_30_Hwa_IsCmacAesVerifyUsedOfObjectInfo(objectId) == TRUE)
      {
        Crypto_30_Hwa_WorkSpaceCMACAES_PtrType workspace;

        /* #45 Get workspace and forward request to CMAC verify service */
        workspace = Crypto_30_Hwa_GetWorkspaceOfCmacAesVerify(Crypto_30_Hwa_GetCmacAesVerifyIdxOfObjectInfo(objectId));
        retVal = Crypto_30_Hwa_ProcessCmacJob(objectId, &errorId, job, TRUE, workspace);
      }
      break;
    }
# endif /* (CRYPTO_30_HWA_SERVICE_MAC_VERIFY == STD_ON) */
#endif /* (CRYPTO_30_HWA_SERVICE_MAC_GENERATE == STD_ON) */

    /* #60 Check if requested service is random number generation service */
#if (CRYPTO_30_HWA_PRIMITIVE_RNG == STD_ON) /* COV_CRYPTO_30_HWA_HARDWARE_DEPENDENT_FEATURE */
    case CRYPTO_RANDOMGENERATE:
    {
      /* #61 Forward request to random number generation service */
      if (Crypto_30_Hwa_IsTrngUsedOfObjectInfo(objectId) == TRUE)
      {
        retVal = Crypto_30_Hwa_ProcessTrngJob(&errorId, job);

      }
      break;
    }
#endif /* (CRYPTO_30_HWA_PRIMITIVE_RNG == STD_ON) */

    /* #70 Check if requested service is hash service */
#if (CRYPTO_30_HWA_PRIMITIVE_SHA2_256 == STD_ON) /* COV_CRYPTO_30_HWA_HARDWARE_DEPENDENT_FEATURE */
    case CRYPTO_HASH:
    {
      if (Crypto_30_Hwa_IsSHA256UsedOfObjectInfo(objectId) == TRUE)
      {
        /* #71 Forward request to hash service */
        retVal = Crypto_30_Hwa_ProcessSha256Job(objectId, &errorId, job);
      }
      break;
    }
#endif /* (CRYPTO_30_HWA_PRIMITIVE_SHA2_256 == STD_ON) */

    /* #80 Check if requested service is signature validate */
#if ((CRYPTO_30_HWA_PRIMITIVE_ECCNIST == STD_ON) || (CRYPTO_30_HWA_PRIMITIVE_ED25519 == STD_ON)) /* COV_CRYPTO_30_HWA_HARDWARE_DEPENDENT_FEATURE */
# if (CRYPTO_30_HWA_SERVICE_SIGNATURE_VERIFY) /* COV_CRYPTO_30_HWA_HARDWARE_DEPENDENT_FEATURE */
    case CRYPTO_SIGNATUREVERIFY:

#  if (CRYPTO_30_HWA_ECP256VERIFY == STD_ON) /* COV_CRYPTO_30_HWA_HARDWARE_DEPENDENT_FEATURE */
      if ((job->jobPrimitiveInfo->primitiveInfo->algorithm.family == CRYPTO_ALGOFAM_ECCNIST) &&
          (Crypto_30_Hwa_IsEcP256VerifyUsedOfObjectInfo(objectId) == TRUE))
      {
        /* #81 Get workspace and forward request to signature verification service */
        Crypto_30_Hwa_WorkSpaceSignature_PtrType workspace;
        workspace = Crypto_30_Hwa_GetWorkspaceOfEcP256Verify(objectId);

        retVal = Crypto_30_Hwa_ProcessEcdsaSignatureVerifyJob(objectId, &errorId, job, workspace);
      }
#  endif /* (CRYPTO_30_HWA_ECP256VERIFY == STD_ON) */

#  if(CRYPTO_30_HWA_ED25519VERIFY == STD_ON) /* COV_CRYPTO_30_HWA_HARDWARE_DEPENDENT_FEATURE */
      if ((job->jobPrimitiveInfo->primitiveInfo->algorithm.family == CRYPTO_ALGOFAM_ED25519) &&
          (Crypto_30_Hwa_IsEd25519VerifyUsedOfObjectInfo(objectId) == TRUE))
      {
        /* #81 Get workspace and forward request to signature verification service */
        Crypto_30_Hwa_WorkSpaceSignature_PtrType workspace;
        workspace = Crypto_30_Hwa_GetWorkspaceOfEd25519Verify(objectId);

        retVal = Crypto_30_Hwa_ProcessEddsaSignatureVerifyJob(objectId, &errorId, job, workspace);
      }
#  endif /* (CRYPTO_30_HWA_ED25519VERIFY) */

      break;
# endif /* (CRYPTO_30_HWA_SERVICE_SIGNATURE_VERIFY == STD_ON) */

    /* #90 Check if requested service is signature generate */
# if (CRYPTO_30_HWA_SERVICE_SIGNATURE_GENERATE) /* COV_CRYPTO_30_HWA_HARDWARE_DEPENDENT_FEATURE */
    case CRYPTO_SIGNATUREGENERATE:

#  if (CRYPTO_30_HWA_ECP256GENERATE == STD_ON) /* COV_CRYPTO_30_HWA_HARDWARE_DEPENDENT_FEATURE */
      if ((job->jobPrimitiveInfo->primitiveInfo->algorithm.family == CRYPTO_ALGOFAM_ECCNIST) &&
          (Crypto_30_Hwa_IsEcP256GenerateUsedOfObjectInfo(objectId) == TRUE))
      {
        /* #81 Get workspace and forward request to signature verification service */
        Crypto_30_Hwa_WorkSpaceSignature_PtrType workspace;
        workspace = Crypto_30_Hwa_GetWorkspaceOfEcP256Generate(objectId);

        retVal = Crypto_30_Hwa_ProcessEcdsaSignatureGenerateJob(objectId, &errorId, job, workspace);
      }
#  endif /* (CRYPTO_30_HWA_ECP256GENERATE == STD_ON) */

#  if(CRYPTO_30_HWA_ED25519GENERATE) /* COV_CRYPTO_30_HWA_HARDWARE_DEPENDENT_FEATURE */
      if ((job->jobPrimitiveInfo->primitiveInfo->algorithm.family == CRYPTO_ALGOFAM_ED25519) &&
          (Crypto_30_Hwa_IsEd25519GenerateUsedOfObjectInfo(objectId) == TRUE))
      {
        /* #81 Get workspace and forward request to signature verification service */
        Crypto_30_Hwa_WorkSpaceSignature_PtrType workspace;
        workspace = Crypto_30_Hwa_GetWorkspaceOfEd25519Generate(objectId);

        retVal = Crypto_30_Hwa_ProcessEddsaSignatureGenerateJob(objectId, &errorId, job, workspace);
      }
#  endif /* (CRYPTO_30_HWA_ED25519GENERATE) */
      break;
# endif /* (CRYPTO_30_HWA_SERVICE_SIGNATURE_GENERATE == STD_ON) */
#endif /* ((CRYPTO_30_HWA_PRIMITIVE_ECCNIST == STD_ON) || (CRYPTO_30_HWA_PRIMITIVE_ED25519)) */

    default: /* COV_CRYPTO_30_HWA_CASE_DEFAULT */
      break;
  }

# if (CRYPTO_30_HWA_DEV_ERROR_REPORT == STD_ON)
  if (errorId != CRYPTO_E_NO_ERROR)
  {
    (void)Det_ReportError(CRYPTO_30_HWA_MODULE_ID, CRYPTO_30_HWA_INSTANCE_ID, CRYPTO_30_HWA_SID_PROCESS_JOB, errorId);
  }
# else
  CRYPTO_30_HWA_DUMMY_STATEMENT(errorId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
# endif /* (CRYPTO_30_HWA_DEV_ERROR_REPORT == STD_ON) */

  return retVal;
} /* Crypto_30_Hwa_DispatchService() */ /* PRQA S 6030, 6050, 6080 */ /* MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */
#endif /* (CRYPTO_30_HWA_OBJECTINFO == STD_ON) */

#if (CRYPTO_30_HWA_DEV_ERROR_DETECT == STD_ON)
# if (CRYPTO_30_HWA_SERVICE_HASH == STD_ON) /* COV_CRYPTO_30_HWA_HARDWARE_DEPENDENT_FEATURE */
/**********************************************************************************************************************
 * Crypto_30_Hwa_Local_DetChecksServiceValues_Hash()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
CRYPTO_30_HWA_LOCAL_INLINE FUNC(uint8, CRYPTO_30_HWA_CODE) Crypto_30_Hwa_Local_DetChecksServiceValues_Hash(
  P2CONST(Crypto_JobType, AUTOMATIC, CRYPTO_30_HWA_APPL_VAR) job)
{
  uint8 errorId = CRYPTO_E_NO_ERROR;

  /* #1 Check Hash Pointers and Length Parameter */
  /* [SWS_Crypto_00071] [SWS_Crypto_00070] Check Pointer */
  /* Optional check of inputPtr and inputLength for finish mode is not required. */
  if (((job->jobPrimitiveInputOutput.inputPtr == NULL_PTR) && Crypto_30_Hwa_IsJobMode(job, CRYPTO_OPERATIONMODE_UPDATE)) ||
    (((job->jobPrimitiveInputOutput.outputPtr == NULL_PTR) || (job->jobPrimitiveInputOutput.outputLengthPtr == NULL_PTR)) && Crypto_30_Hwa_IsJobMode(job, CRYPTO_OPERATIONMODE_FINISH)))
  {
    errorId = CRYPTO_E_PARAM_POINTER; /* SBSW_CRYPTO_30_HWA_ACCESS_TO_ERRORID_PTR */
  }
  /* [SWS_Crypto_00071] [SWS_Crypto_00142] Check Length */
  else if ((Crypto_30_Hwa_IsJobMode(job, CRYPTO_OPERATIONMODE_UPDATE) && (job->jobPrimitiveInputOutput.inputLength == 0u)) ||
    (Crypto_30_Hwa_IsJobMode(job, CRYPTO_OPERATIONMODE_FINISH) && (*(job->jobPrimitiveInputOutput.outputLengthPtr) == 0u))) /* PRQA S 2812 */ /* MD_CRYPTO_30_HWA_2812_DET_CHECK_NULLPOINTER */
  {
    errorId = CRYPTO_E_PARAM_VALUE; /* SBSW_CRYPTO_30_HWA_ACCESS_TO_ERRORID_PTR */
  }
  else
  {
    /* Det Checks passed. Nothing has to be done. */
  }

  return errorId;
} /* Crypto_30_Hwa_Local_DetChecksServiceValues_Hash() */
# endif /* (CRYPTO_30_HWA_SERVICE_HASH == STD_ON) */

# if (CRYPTO_30_HWA_SERVICE_MAC_GENERATE == STD_ON) /* COV_CRYPTO_30_HWA_HARDWARE_DEPENDENT_FEATURE */
/**********************************************************************************************************************
 * Crypto_30_Hwa_Local_DetChecksServiceValues_MacGenerate()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
CRYPTO_30_HWA_LOCAL_INLINE FUNC(uint8, CRYPTO_30_HWA_CODE) Crypto_30_Hwa_Local_DetChecksServiceValues_MacGenerate(
  P2CONST(Crypto_JobType, AUTOMATIC, CRYPTO_30_HWA_APPL_VAR) job)
{
  uint8 errorId = CRYPTO_E_NO_ERROR;

  /* #2 Check MAC Generate Pointers and Length Parameter */
  /* [SWS_Crypto_00071] [SWS_Crypto_00070] Check Pointer */
  /* Optional check of inputPtr and inputLength for finish mode is not required. */
  if (((job->jobPrimitiveInputOutput.inputPtr == NULL_PTR) && Crypto_30_Hwa_IsJobMode(job, CRYPTO_OPERATIONMODE_UPDATE)) ||
    (((job->jobPrimitiveInputOutput.outputPtr == NULL_PTR) || (job->jobPrimitiveInputOutput.outputLengthPtr == NULL_PTR)) && Crypto_30_Hwa_IsJobMode(job, CRYPTO_OPERATIONMODE_FINISH)))
  {
    errorId = CRYPTO_E_PARAM_POINTER; /* SBSW_CRYPTO_30_HWA_ACCESS_TO_ERRORID_PTR */
  }
  /* [SWS_Crypto_00071] [SWS_Crypto_00142] Check Length */
  else if ((Crypto_30_Hwa_IsJobMode(job, CRYPTO_OPERATIONMODE_UPDATE) && (job->jobPrimitiveInputOutput.inputLength == 0u)) ||
    (Crypto_30_Hwa_IsJobMode(job, CRYPTO_OPERATIONMODE_FINISH) && (*(job->jobPrimitiveInputOutput.outputLengthPtr) == 0u))) /* PRQA S 2812 */ /* MD_CRYPTO_30_HWA_2812_DET_CHECK_NULLPOINTER */
  {
    errorId = CRYPTO_E_PARAM_VALUE; /* SBSW_CRYPTO_30_HWA_ACCESS_TO_ERRORID_PTR */
  }
  else
  {
    /* Det Checks passed. Nothing has to be done. */
  }
  return errorId;
} /* Crypto_30_Hwa_Local_DetChecksServiceValues_MacGenerate() */
# endif /* (CRYPTO_30_HWA_SERVICE_MAC_GENERATE == STD_ON) */

# if (CRYPTO_30_HWA_SERVICE_MAC_VERIFY == STD_ON) /* COV_CRYPTO_30_HWA_HARDWARE_DEPENDENT_FEATURE */
/**********************************************************************************************************************
 * Crypto_30_Hwa_Local_DetChecksServiceValues_MacVerify()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
CRYPTO_30_HWA_LOCAL_INLINE FUNC(uint8, CRYPTO_30_HWA_CODE) Crypto_30_Hwa_Local_DetChecksServiceValues_MacVerify(
  P2CONST(Crypto_JobType, AUTOMATIC, CRYPTO_30_HWA_APPL_VAR) job)
{
  uint8 errorId = CRYPTO_E_NO_ERROR;

  /* #3 Check MAC Verify Pointers and Length Parameter */
  /* [SWS_Crypto_00071] [SWS_Crypto_00070] Check Pointer */
  /* Optional check of inputPtr and inputLength for finish mode is not required. */
  if (((job->jobPrimitiveInputOutput.inputPtr == NULL_PTR) && Crypto_30_Hwa_IsJobMode(job, CRYPTO_OPERATIONMODE_UPDATE)) ||
    (((job->jobPrimitiveInputOutput.secondaryInputPtr == NULL_PTR) || (job->jobPrimitiveInputOutput.verifyPtr == NULL_PTR)) && Crypto_30_Hwa_IsJobMode(job, CRYPTO_OPERATIONMODE_FINISH)))
  {
    errorId = CRYPTO_E_PARAM_POINTER; /* SBSW_CRYPTO_30_HWA_ACCESS_TO_ERRORID_PTR */
  }
  /* [SWS_Crypto_00071] [SWS_Crypto_00142] Check Length */
  else if ((Crypto_30_Hwa_IsJobMode(job, CRYPTO_OPERATIONMODE_UPDATE) && (job->jobPrimitiveInputOutput.inputLength == 0u)) ||
    (Crypto_30_Hwa_IsJobMode(job, CRYPTO_OPERATIONMODE_FINISH) && (job->jobPrimitiveInputOutput.secondaryInputLength == 0u)))
  {
    errorId = CRYPTO_E_PARAM_VALUE; /* SBSW_CRYPTO_30_HWA_ACCESS_TO_ERRORID_PTR */
  }
  else
  {
    /* Det Checks passed. Nothing has to be done. */
  }
  return errorId;

} /* Crypto_30_Hwa_Local_DetChecksServiceValues_MacVerify() */
# endif /* (CRYPTO_30_HWA_SERVICE_MAC_VERIFY == STD_ON) */

# if (CRYPTO_30_HWA_SERVICE_ENCRYPT == STD_ON) /* COV_CRYPTO_30_HWA_HARDWARE_DEPENDENT_FEATURE */
/**********************************************************************************************************************
 * Crypto_30_Hwa_Local_DetChecksServiceValues_Encrypt()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
CRYPTO_30_HWA_LOCAL_INLINE FUNC(uint8, CRYPTO_30_HWA_CODE) Crypto_30_Hwa_Local_DetChecksServiceValues_Encrypt(
  P2CONST(Crypto_JobType, AUTOMATIC, CRYPTO_30_HWA_APPL_VAR) job)
{
  uint8 errorId = CRYPTO_E_NO_ERROR;

  /* #4 Check Encrypt Pointers and Length Parameter */
  /* [SWS_Crypto_00071] [SWS_Crypto_00070] Check Pointer */
  /* Optional check of inputPtr and inputLength for finish mode is not required. */
  if (((job->jobPrimitiveInputOutput.inputPtr == NULL_PTR) && Crypto_30_Hwa_IsJobMode(job, CRYPTO_OPERATIONMODE_UPDATE)) ||
    (((job->jobPrimitiveInputOutput.outputPtr == NULL_PTR) || (job->jobPrimitiveInputOutput.outputLengthPtr == NULL_PTR)) &&
    Crypto_30_Hwa_IsJobMode(job, CRYPTO_OPERATIONMODE_UPDATE)))
  {
    errorId = CRYPTO_E_PARAM_POINTER;
  }
  /* In finish step, output can be null if no padding is used. */
  else if (((job->jobPrimitiveInputOutput.outputPtr == NULL_PTR) || (job->jobPrimitiveInputOutput.outputLengthPtr == NULL_PTR)) &&
    Crypto_30_Hwa_IsJobMode(job, CRYPTO_OPERATIONMODE_FINISH) &&
    (job->jobPrimitiveInfo->primitiveInfo->algorithm.secondaryFamily != CRYPTO_ALGOFAM_CUSTOM_PADDING_NONE))
  {
    errorId = CRYPTO_E_PARAM_POINTER;
  }
  /* [SWS_Crypto_00071] [SWS_Crypto_00142] Check Length */
  else if (Crypto_30_Hwa_IsJobMode(job, CRYPTO_OPERATIONMODE_UPDATE) &&
    ((job->jobPrimitiveInputOutput.inputLength == 0u) || (*(job->jobPrimitiveInputOutput.outputLengthPtr) == 0u))) /* PRQA S 2812 */ /* MD_CRYPTO_30_HWA_2812_DET_CHECK_NULLPOINTER */
  {
    errorId = CRYPTO_E_PARAM_VALUE;
  }
  else
  {
    /* Det Checks passed. Nothing has to be done. */
  }
  return errorId;
} /* Crypto_30_Hwa_Local_DetChecksServiceValues_Encrypt() */
# endif /* (CRYPTO_30_HWA_SERVICE_ENCRYPT == STD_ON) */

# if (CRYPTO_30_HWA_SERVICE_DECRYPT == STD_ON) /* COV_CRYPTO_30_HWA_HARDWARE_DEPENDENT_FEATURE */
/**********************************************************************************************************************
 * Crypto_30_Hwa_Local_DetChecksServiceValues_Decrypt()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
CRYPTO_30_HWA_LOCAL_INLINE FUNC(uint8, CRYPTO_30_HWA_CODE) Crypto_30_Hwa_Local_DetChecksServiceValues_Decrypt(
  P2CONST(Crypto_JobType, AUTOMATIC, CRYPTO_30_HWA_APPL_VAR) job)
{
  uint8 errorId = CRYPTO_E_NO_ERROR;

  /* #5 Check Decrypt Pointers and Length Parameter */
  /* [SWS_Crypto_00071] [SWS_Crypto_00070] Check Pointer */
  /* Optional check of inputPtr and inputLength for finish mode is not required. */
  if (((job->jobPrimitiveInputOutput.inputPtr == NULL_PTR) && Crypto_30_Hwa_IsJobMode(job, CRYPTO_OPERATIONMODE_UPDATE)) ||
    (((job->jobPrimitiveInputOutput.outputPtr == NULL_PTR) || (job->jobPrimitiveInputOutput.outputLengthPtr == NULL_PTR)) &&
    Crypto_30_Hwa_IsJobMode(job, CRYPTO_OPERATIONMODE_UPDATE)))
  {
    errorId = CRYPTO_E_PARAM_POINTER;
  }
    /* In finish step, output can be null if no padding is used. */
  else if (((job->jobPrimitiveInputOutput.outputPtr == NULL_PTR) || (job->jobPrimitiveInputOutput.outputLengthPtr == NULL_PTR)) &&
    Crypto_30_Hwa_IsJobMode(job, CRYPTO_OPERATIONMODE_FINISH) &&
    (job->jobPrimitiveInfo->primitiveInfo->algorithm.secondaryFamily != CRYPTO_ALGOFAM_CUSTOM_PADDING_NONE))
  {
    errorId = CRYPTO_E_PARAM_POINTER;
  }
  /* [SWS_Crypto_00071] [SWS_Crypto_00142] Check Length */
  else if (Crypto_30_Hwa_IsJobMode(job, CRYPTO_OPERATIONMODE_UPDATE) &&
    ((job->jobPrimitiveInputOutput.inputLength == 0u) || (*(job->jobPrimitiveInputOutput.outputLengthPtr) == 0u))) /* PRQA S 2812 */ /* MD_CRYPTO_30_HWA_2812_DET_CHECK_NULLPOINTER */
  {
    errorId = CRYPTO_E_PARAM_VALUE;
  }
  else
  {
    /* Det Checks passed. Nothing has to be done. */
  }
  return errorId;
} /* Crypto_30_Hwa_Local_DetChecksServiceValues_Decrypt() */
# endif /* (CRYPTO_30_HWA_SERVICE_DECRYPT == STD_ON) */

# if (CRYPTO_30_HWA_SERVICE_AEADENCRYPT == STD_ON) /* COV_CRYPTO_30_HWA_HARDWARE_DEPENDENT_FEATURE */
/**********************************************************************************************************************
 * Crypto_30_Hwa_Local_DetChecksServiceValues_AeadEncrypt()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
CRYPTO_30_HWA_LOCAL_INLINE FUNC(uint8, CRYPTO_30_HWA_CODE) Crypto_30_Hwa_Local_DetChecksServiceValues_AeadEncrypt(
  P2CONST(Crypto_JobType, AUTOMATIC, CRYPTO_30_HWA_APPL_VAR) job)
{
  uint8 errorId = CRYPTO_E_NO_ERROR;

  /* #4 Check Encrypt Pointers and Length Parameter */
  /* [SWS_Crypto_00071] [SWS_Crypto_00070] Check Pointer */
  /* Optional check of inputPtr and inputLength for finish mode is not required. */
  if (Crypto_30_Hwa_IsJobMode(job, CRYPTO_OPERATIONMODE_UPDATE) &&
       ((job->jobPrimitiveInputOutput.inputPtr == NULL_PTR) ||
        (job->jobPrimitiveInputOutput.outputPtr == NULL_PTR)))
  {
    errorId = CRYPTO_E_PARAM_POINTER;
  }
  /* [SWS_Crypto_00071] [SWS_Crypto_00070] Check Pointer */
  else if (Crypto_30_Hwa_IsJobMode(job, CRYPTO_OPERATIONMODE_FINISH) &&
    ((job->jobPrimitiveInputOutput.outputPtr == NULL_PTR) ||
     (job->jobPrimitiveInputOutput.secondaryOutputPtr == NULL_PTR)))
  {
    errorId = CRYPTO_E_PARAM_POINTER;
  }
  /* [SWS_Crypto_00071] [SWS_Crypto_00142] Check Length */
  else if (Crypto_30_Hwa_IsJobMode(job, CRYPTO_OPERATIONMODE_UPDATE) &&
    ((job->jobPrimitiveInputOutput.inputLength == 0u) ||
     (job->jobPrimitiveInputOutput.outputLengthPtr == NULL_PTR))) /* PRQA S 2812 */ /* MD_CRYPTO_30_HWA_2812_DET_CHECK_NULLPOINTER */
  {
    errorId = CRYPTO_E_PARAM_VALUE;
  }
  else if (Crypto_30_Hwa_IsJobMode(job, CRYPTO_OPERATIONMODE_FINISH) &&
    ((job->jobPrimitiveInputOutput.outputLengthPtr == NULL_PTR) ||         /* PRQA S 2812 */ /* MD_CRYPTO_30_HWA_2812_DET_CHECK_NULLPOINTER */
     (job->jobPrimitiveInputOutput.secondaryOutputLengthPtr == NULL_PTR))) /* PRQA S 2812 */ /* MD_CRYPTO_30_HWA_2812_DET_CHECK_NULLPOINTER */
  {
    errorId = CRYPTO_E_PARAM_VALUE;
  }
  else
  {
    /* Det Checks passed. Nothing has to be done. */
  }
  return errorId;
} /* Crypto_30_Hwa_Local_DetChecksServiceValues_AeadEncrypt() */
# endif /* (CRYPTO_30_HWA_SERVICE_AEADENCRYPT == STD_ON) */

# if (CRYPTO_30_HWA_SERVICE_AEADDECRYPT == STD_ON) /* COV_CRYPTO_30_HWA_HARDWARE_DEPENDENT_FEATURE */
/**********************************************************************************************************************
 * Crypto_30_Hwa_Local_DetChecksServiceValues_AeadDecrypt()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
CRYPTO_30_HWA_LOCAL_INLINE FUNC(uint8, CRYPTO_30_HWA_CODE) Crypto_30_Hwa_Local_DetChecksServiceValues_AeadDecrypt(
  P2CONST(Crypto_JobType, AUTOMATIC, CRYPTO_30_HWA_APPL_VAR) job)
{
  uint8 errorId = CRYPTO_E_NO_ERROR;

  /* #5 Check Decrypt Pointers and Length Parameter */
  /* [SWS_Crypto_00071] [SWS_Crypto_00070] Check Pointer */
  /* Optional check of inputPtr and inputLength for finish mode is not required. */
  if (Crypto_30_Hwa_IsJobMode(job, CRYPTO_OPERATIONMODE_UPDATE) &&
    ((job->jobPrimitiveInputOutput.inputPtr == NULL_PTR) ||
    (job->jobPrimitiveInputOutput.outputPtr == NULL_PTR)))
  {
    errorId = CRYPTO_E_PARAM_POINTER;
  }
  /* [SWS_Crypto_00071] [SWS_Crypto_00070] Check Pointer */
  else if (Crypto_30_Hwa_IsJobMode(job, CRYPTO_OPERATIONMODE_FINISH) &&
    ((job->jobPrimitiveInputOutput.tertiaryInputPtr == NULL_PTR) ||
     (job->jobPrimitiveInputOutput.outputPtr == NULL_PTR) ||
     (job->jobPrimitiveInputOutput.verifyPtr == NULL_PTR)))
  {
    errorId = CRYPTO_E_PARAM_POINTER;
  }
  /* [SWS_Crypto_00071] [SWS_Crypto_00142] Check Length */
  else if (Crypto_30_Hwa_IsJobMode(job, CRYPTO_OPERATIONMODE_UPDATE) &&
    ((job->jobPrimitiveInputOutput.inputLength == 0u) ||
    (job->jobPrimitiveInputOutput.outputLengthPtr == NULL_PTR))) /* PRQA S 2812 */ /* MD_CRYPTO_30_HWA_2812_DET_CHECK_NULLPOINTER */
  {
    errorId = CRYPTO_E_PARAM_VALUE;
  }
  else if (Crypto_30_Hwa_IsJobMode(job, CRYPTO_OPERATIONMODE_FINISH) &&
    ((job->jobPrimitiveInputOutput.tertiaryInputLength == 0u) ||
    (job->jobPrimitiveInputOutput.outputLengthPtr == NULL_PTR))) /* PRQA S 2812 */ /* MD_CRYPTO_30_HWA_2812_DET_CHECK_NULLPOINTER */
  {
    errorId = CRYPTO_E_PARAM_VALUE;
  }
  else
  {
    /* Det Checks passed. Nothing has to be done. */
  }

return errorId;
} /* Crypto_30_Hwa_Local_DetChecksServiceValues_AeadDecrypt() */
# endif /* (CRYPTO_30_HWA_SERVICE_AEADDECRYPT == STD_ON) */

# if (CRYPTO_30_HWA_SERVICE_SIGNATURE_GENERATE == STD_ON) /* COV_CRYPTO_30_HWA_HARDWARE_DEPENDENT_FEATURE */
/**********************************************************************************************************************
 * Crypto_30_Hwa_Local_DetChecksServiceValues_SignatureGenerate()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
CRYPTO_30_HWA_LOCAL_INLINE FUNC(uint8, CRYPTO_30_HWA_CODE) Crypto_30_Hwa_Local_DetChecksServiceValues_SignatureGenerate(
  P2CONST(Crypto_JobType, AUTOMATIC, CRYPTO_30_HWA_APPL_VAR) job)
{
  uint8 errorId = CRYPTO_E_NO_ERROR;

  /* #5 Check Signature Generate Pointers and Length Parameter */
  /* [SWS_Crypto_00071] [SWS_Crypto_00070] Check Pointer */
  /* Optional check of inputPtr and inputLength for finish mode is not required. */
  if (Crypto_30_Hwa_IsJobMode(job, CRYPTO_OPERATIONMODE_UPDATE) &&
    (job->jobPrimitiveInputOutput.inputPtr == NULL_PTR))
  {
    errorId = CRYPTO_E_PARAM_POINTER;
  }
  /* [SWS_Crypto_00071] [SWS_Crypto_00070] Check Pointer */
  else if (Crypto_30_Hwa_IsJobMode(job, CRYPTO_OPERATIONMODE_FINISH) &&
    ((job->jobPrimitiveInputOutput.outputPtr == NULL_PTR) ||
    (job->jobPrimitiveInputOutput.outputLengthPtr == NULL_PTR)))
  {
    errorId = CRYPTO_E_PARAM_POINTER;
  }
  /* [SWS_Crypto_00071] [SWS_Crypto_00142] Check Length */
  else if (Crypto_30_Hwa_IsJobMode(job, CRYPTO_OPERATIONMODE_UPDATE) &&
    (job->jobPrimitiveInputOutput.inputLength == 0u))
  {
    errorId = CRYPTO_E_PARAM_VALUE;
  }
  /* [SWS_Crypto_00071] [SWS_Crypto_00142] Check Length */
  else if (Crypto_30_Hwa_IsJobMode(job, CRYPTO_OPERATIONMODE_FINISH) &&
    (*(job->jobPrimitiveInputOutput.outputLengthPtr) == 0u))
  {
    errorId = CRYPTO_E_PARAM_VALUE;
  }
  else
  {
    /* Det Checks passed. Nothing has to be done. */
  }

  return errorId;
} /* Crypto_30_Hwa_Local_DetChecksServiceValues_SignatureVerify() */
# endif /* (CRYPTO_30_HWA_SERVICE_SIGNATURE_VERIFY == STD_ON) */

# if (CRYPTO_30_HWA_SERVICE_SIGNATURE_VERIFY == STD_ON) /* COV_CRYPTO_30_HWA_HARDWARE_DEPENDENT_FEATURE */
/**********************************************************************************************************************
 * Crypto_30_Hwa_Local_DetChecksServiceValues_SignatureVerify()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
CRYPTO_30_HWA_LOCAL_INLINE FUNC(uint8, CRYPTO_30_HWA_CODE) Crypto_30_Hwa_Local_DetChecksServiceValues_SignatureVerify(
  P2CONST(Crypto_JobType, AUTOMATIC, CRYPTO_30_HWA_APPL_VAR) job)
{
  uint8 errorId = CRYPTO_E_NO_ERROR;

  /* #5 Check Signature Verify Pointers and Length Parameter */
  /* [SWS_Crypto_00071] [SWS_Crypto_00070] Check Pointer */
  /* Optional check of inputPtr and inputLength for finish mode is not required. */
  if (Crypto_30_Hwa_IsJobMode(job, CRYPTO_OPERATIONMODE_UPDATE) &&
    (job->jobPrimitiveInputOutput.inputPtr == NULL_PTR))
  {
    errorId = CRYPTO_E_PARAM_POINTER;
  }
  /* [SWS_Crypto_00071] [SWS_Crypto_00070] Check Pointer */
  else if (Crypto_30_Hwa_IsJobMode(job, CRYPTO_OPERATIONMODE_FINISH) &&
    ((job->jobPrimitiveInputOutput.secondaryInputPtr == NULL_PTR) ||
      (job->jobPrimitiveInputOutput.verifyPtr == NULL_PTR)))
  {
    errorId = CRYPTO_E_PARAM_POINTER;
  }
  /* [SWS_Crypto_00071] [SWS_Crypto_00142] Check Length */
  else if (Crypto_30_Hwa_IsJobMode(job, CRYPTO_OPERATIONMODE_UPDATE) &&
    (job->jobPrimitiveInputOutput.inputLength == 0u))
  {
    errorId = CRYPTO_E_PARAM_VALUE;
  }
  else if (Crypto_30_Hwa_IsJobMode(job, CRYPTO_OPERATIONMODE_FINISH) &&
    (job->jobPrimitiveInputOutput.secondaryInputLength == 0u))
  {
    errorId = CRYPTO_E_PARAM_VALUE;
  }
  else
  {
    /* Det Checks passed. Nothing has to be done. */
  }

  return errorId;
} /* Crypto_30_Hwa_Local_DetChecksServiceValues_SignatureVerify() */
# endif /* (CRYPTO_30_HWA_SERVICE_SIGNATURE_VERIFY == STD_ON) */

# if (CRYPTO_30_HWA_SERVICE_RANDOM == STD_ON) /* COV_CRYPTO_30_HWA_HARDWARE_DEPENDENT_FEATURE */
/**********************************************************************************************************************
 * Crypto_30_Hwa_Local_DetChecksServiceValues_Random()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
CRYPTO_30_HWA_LOCAL_INLINE FUNC(uint8, CRYPTO_30_HWA_CODE) Crypto_30_Hwa_Local_DetChecksServiceValues_Random(
  P2CONST(Crypto_JobType, AUTOMATIC, CRYPTO_30_HWA_APPL_VAR) job)
{
  uint8 errorId = CRYPTO_E_NO_ERROR;

  /* #10 Check Random Generate Pointers and Length Parameter */
  /* [SWS_Crypto_00071] [SWS_Crypto_00070] Check Pointer */
  if (((job->jobPrimitiveInputOutput.outputPtr == NULL_PTR) || (job->jobPrimitiveInputOutput.outputLengthPtr == NULL_PTR)) && Crypto_30_Hwa_IsJobMode(job, CRYPTO_OPERATIONMODE_FINISH))
  {
    errorId = CRYPTO_E_PARAM_POINTER; /* SBSW_CRYPTO_30_HWA_ACCESS_TO_ERRORID_PTR */
  }
  else if (Crypto_30_Hwa_IsJobMode(job, CRYPTO_OPERATIONMODE_FINISH) && (*(job->jobPrimitiveInputOutput.outputLengthPtr) == 0u)) /* PRQA S 2812 */ /* MD_CRYPTO_30_HWA_2812_DET_CHECK_NULLPOINTER */
  {
    errorId = CRYPTO_E_PARAM_VALUE; /* SBSW_CRYPTO_30_HWA_ACCESS_TO_ERRORID_PTR */
  }
  else
  {
    /* Det Checks passed. Nothing has to be done. */
  }
  return errorId;
} /* Crypto_30_Hwa_Local_DetChecksServiceValues_Random() */
# endif /* (CRYPTO_30_HWA_SERVICE_RANDOM == STD_ON) */

/**********************************************************************************************************************
 *  Crypto_30_Hwa_Local_DetChecksServiceValues()
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
 *
 *
 */
# if (CRYPTO_30_HWA_OBJECTINFO == STD_ON)
CRYPTO_30_HWA_LOCAL_INLINE FUNC(Std_ReturnType, CRYPTO_30_HWA_CODE) Crypto_30_Hwa_Local_DetChecksServiceValues(
  P2CONST(Crypto_JobType, AUTOMATIC, CRYPTO_30_HWA_APPL_VAR) job,
  P2VAR(uint8, AUTOMATIC, CRYPTO_30_HWA_APPL_VAR) errorId)
{
  Std_ReturnType retVal = E_OK;

  /* #0 Check plausibility of parameters */
  switch (job->jobPrimitiveInfo->primitiveInfo->service)
  {
# if (CRYPTO_30_HWA_SERVICE_HASH == STD_ON) /* COV_CRYPTO_30_HWA_HARDWARE_DEPENDENT_FEATURE */
  case CRYPTO_HASH:
    *errorId = Crypto_30_Hwa_Local_DetChecksServiceValues_Hash(job); /* SBSW_CRYPTO_30_HWA_ACCESS_TO_ERRORID_PTR */ /* SBSW_CRYPTO_30_HWA_FORWARDING_OF_JOB_PTR */
    break;

# endif
# if (CRYPTO_30_HWA_SERVICE_MAC_GENERATE == STD_ON) /* COV_CRYPTO_30_HWA_HARDWARE_DEPENDENT_FEATURE */
  case CRYPTO_MACGENERATE:
    *errorId = Crypto_30_Hwa_Local_DetChecksServiceValues_MacGenerate(job); /* SBSW_CRYPTO_30_HWA_ACCESS_TO_ERRORID_PTR */ /* SBSW_CRYPTO_30_HWA_FORWARDING_OF_JOB_PTR */
    break;

# endif
# if (CRYPTO_30_HWA_SERVICE_MAC_VERIFY == STD_ON) /* COV_CRYPTO_30_HWA_HARDWARE_DEPENDENT_FEATURE */
  case CRYPTO_MACVERIFY:
    *errorId = Crypto_30_Hwa_Local_DetChecksServiceValues_MacVerify(job); /* SBSW_CRYPTO_30_HWA_ACCESS_TO_ERRORID_PTR */ /* SBSW_CRYPTO_30_HWA_FORWARDING_OF_JOB_PTR */
    break;

# endif
# if (CRYPTO_30_HWA_SERVICE_ENCRYPT == STD_ON) /* COV_CRYPTO_30_HWA_HARDWARE_DEPENDENT_FEATURE */
  case CRYPTO_ENCRYPT:
    *errorId = Crypto_30_Hwa_Local_DetChecksServiceValues_Encrypt(job); /* SBSW_CRYPTO_30_HWA_ACCESS_TO_ERRORID_PTR */ /* SBSW_CRYPTO_30_HWA_FORWARDING_OF_JOB_PTR */
    break;

# endif
# if (CRYPTO_30_HWA_SERVICE_DECRYPT == STD_ON) /* COV_CRYPTO_30_HWA_HARDWARE_DEPENDENT_FEATURE */
  case CRYPTO_DECRYPT:
    *errorId = Crypto_30_Hwa_Local_DetChecksServiceValues_Decrypt(job); /* SBSW_CRYPTO_30_HWA_ACCESS_TO_ERRORID_PTR */ /* SBSW_CRYPTO_30_HWA_FORWARDING_OF_JOB_PTR */
    break;

# endif
# if (CRYPTO_30_HWA_SERVICE_RANDOM == STD_ON) /* COV_CRYPTO_30_HWA_HARDWARE_DEPENDENT_FEATURE */
  case CRYPTO_RANDOMGENERATE:
    *errorId = Crypto_30_Hwa_Local_DetChecksServiceValues_Random(job); /* SBSW_CRYPTO_30_HWA_ACCESS_TO_ERRORID_PTR */ /* SBSW_CRYPTO_30_HWA_FORWARDING_OF_JOB_PTR */
    break;

# endif
# if (CRYPTO_30_HWA_SERVICE_AEADENCRYPT == STD_ON) /* COV_CRYPTO_30_HWA_HARDWARE_DEPENDENT_FEATURE */
  case CRYPTO_AEADENCRYPT:
    *errorId = Crypto_30_Hwa_Local_DetChecksServiceValues_AeadEncrypt(job); /* SBSW_CRYPTO_30_HWA_ACCESS_TO_ERRORID_PTR */ /* SBSW_CRYPTO_30_HWA_FORWARDING_OF_JOB_PTR */
    break;

# endif
# if (CRYPTO_30_HWA_SERVICE_AEADDECRYPT == STD_ON) /* COV_CRYPTO_30_HWA_HARDWARE_DEPENDENT_FEATURE */
  case CRYPTO_AEADDECRYPT:
    *errorId = Crypto_30_Hwa_Local_DetChecksServiceValues_AeadDecrypt(job); /* SBSW_CRYPTO_30_HWA_ACCESS_TO_ERRORID_PTR */ /* SBSW_CRYPTO_30_HWA_FORWARDING_OF_JOB_PTR */
    break;

# endif

# if (CRYPTO_30_HWA_SERVICE_SIGNATURE_VERIFY == STD_ON) /* COV_CRYPTO_30_HWA_HARDWARE_DEPENDENT_FEATURE */
  case CRYPTO_SIGNATUREVERIFY:
    *errorId = Crypto_30_Hwa_Local_DetChecksServiceValues_SignatureVerify(job); /* SBSW_CRYPTO_30_HWA_ACCESS_TO_ERRORID_PTR */ /* SBSW_CRYPTO_30_HWA_FORWARDING_OF_JOB_PTR */
    break;

# endif

# if (CRYPTO_30_HWA_SERVICE_SIGNATURE_GENERATE == STD_ON) /* COV_CRYPTO_30_HWA_HARDWARE_DEPENDENT_FEATURE */
  case CRYPTO_SIGNATUREGENERATE:
    *errorId = Crypto_30_Hwa_Local_DetChecksServiceValues_SignatureGenerate(job); /* SBSW_CRYPTO_30_HWA_ACCESS_TO_ERRORID_PTR */ /* SBSW_CRYPTO_30_HWA_FORWARDING_OF_JOB_PTR */
    break;

# endif

  default:
    /* #11 Service is not supported by Crypto Driver Object */
    /* [SWS_Crypto_00064] check if job->jobPrimitiveInfo->primitiveInfo->service is supported by Crypto Driver Object */
    *errorId = CRYPTO_E_PARAM_HANDLE; /* SBSW_CRYPTO_30_HWA_ACCESS_TO_ERRORID_PTR */
    break;

  }

  /* #12 Set return Value to E_NOT_OK if a failure was detected. */
  if ((*errorId == CRYPTO_E_PARAM_POINTER) || (*errorId == CRYPTO_E_PARAM_VALUE) || (*errorId == CRYPTO_E_PARAM_HANDLE))
  {
    retVal = E_NOT_OK;
  }

  return retVal;
} /* Crypto_30_Hwa_Local_DetChecksServiceValues() */ /* PRQA S 6030, 6050 */ /* MD_MSR_STCYC, MD_MSR_STCAL */
# endif /* (CRYPTO_30_HWA_OBJECTINFO == STD_ON) */
#endif /* (CRYPTO_30_HWA_DEV_ERROR_DETECT == STD_ON) */

#define CRYPTO_30_HWA_STOP_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/

#define CRYPTO_30_HWA_START_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  Crypto_30_Hwa_Init()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(void, CRYPTO_30_HWA_CODE) Crypto_30_Hwa_Init(void)
{
  uint8 errorId = CRYPTO_E_NO_ERROR;
#if (CRYPTO_30_HWA_OBJECTINFO == STD_ON)
  Crypto_30_Hwa_LockIterType lockIdx;
#endif

#if (CRYPTO_30_HWA_DEV_ERROR_DETECT == STD_ON)
  /* Check initialization state of the component */
  if (Crypto_30_Hwa_ModuleInitialized == (uint8)CRYPTO_30_HWA_INITIALIZED)
  {
    errorId = CRYPTO_E_INIT_FAILED;
  }

  /* Set module state to initialized */
  Crypto_30_Hwa_ModuleInitialized = CRYPTO_30_HWA_INITIALIZED;
#endif

#if(CRYPTO_30_HWA_TRNG_PREFETCHING == STD_ON) /* COV_CRYPTO_30_HWA_HARDWARE_DEPENDENT_FEATURE */
  Crypto_30_Hwa_InitTrngPrefetching();
#endif

  Crypto_30_Hwa_Hw_Init();

#if (CRYPTO_30_HWA_OBJECTINFO == STD_ON)
  /* Free all locks of workspaces */
  for (lockIdx = 0u; lockIdx < Crypto_30_Hwa_GetSizeOfLock(); lockIdx++)
  {
    Crypto_30_Hwa_FreeLock(lockIdx);
  }
#endif

#if (CRYPTO_30_HWA_DEV_ERROR_REPORT == STD_ON)
  if (errorId != CRYPTO_E_NO_ERROR)
  {
    /* Call Det if error occurred */
    (void)Det_ReportError(CRYPTO_30_HWA_MODULE_ID, CRYPTO_30_HWA_INSTANCE_ID, CRYPTO_30_HWA_SID_INIT, errorId);
  }
#else
  CRYPTO_30_HWA_DUMMY_STATEMENT(errorId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
#endif
} /* Crypto_30_Hwa_Init() */

/**********************************************************************************************************************
 *  Crypto_30_Hwa_InitMemory()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(void, CRYPTO_30_HWA_CODE) Crypto_30_Hwa_InitMemory(void)
{
  Crypto_30_Hwa_Hw_InitMemory();

  /* Set the mode to uninitialized */
#if (CRYPTO_30_HWA_DEV_ERROR_DETECT == STD_ON)
  Crypto_30_Hwa_ModuleInitialized = (uint8)CRYPTO_30_HWA_UNINIT;
#endif
} /* Crypto_30_Hwa_InitMemory() */

/**********************************************************************************************************************
 *  Crypto_30_Hwa_MainFunction()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(void, CRYPTO_30_HWA_CODE) Crypto_30_Hwa_MainFunction(void)
{
  Crypto_30_Hwa_Hw_MainFunction();

#if (CRYPTO_30_HWA_TRNG_PREFETCHING == STD_ON) /* COV_CRYPTO_30_HWA_HARDWARE_DEPENDENT_FEATURE */
#if (CRYPTO_30_HWA_TRNG_PREFETCH_WITH_INTERRUPT == STD_OFF) /* COV_CRYPTO_30_HWA_HARDWARE_DEPENDENT_FEATURE */
  Crypto_30_Hwa_TrngPrefetch();
#endif
#endif
} /* Crypto_30_Hwa_MainFunction() */

/**********************************************************************************************************************
 *  Crypto_30_Hwa_ProcessJob()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(Std_ReturnType, CRYPTO_30_HWA_CODE) Crypto_30_Hwa_ProcessJob(
  uint32 objectId,
  Crypto_30_Hwa_JobPtrType job) /* PRQA S 3673 */ /* MD_MSR_Rule8.13 */
{
  Std_ReturnType retVal;
  uint8 errorId = CRYPTO_E_NO_ERROR; /* PRQA S 2981 */ /* MD_MSR_RetVal */

#if (CRYPTO_30_HWA_DEV_ERROR_DETECT == STD_ON)
  retVal = E_NOT_OK;
  /* [SWS_Crypto_00057] */
  /* #5 Check initialization state of the component. */
  if (Crypto_30_Hwa_ModuleInitialized != (uint8)CRYPTO_30_HWA_INITIALIZED)
  {
    errorId = CRYPTO_E_UNINIT;
  }
# if (CRYPTO_30_HWA_OBJECTINFO == STD_ON)
  /* [SWS_Crypto_00058] */
  /* #10 Check plausibility of parameters. */
  else if (objectId >= Crypto_30_Hwa_GetSizeOfObjectInfo())
  {
    errorId = CRYPTO_E_PARAM_HANDLE;
  }

  /* [SWS_Crypto_00059] Check if job is a null pointer */
  else if (job == NULL_PTR)
  {
    errorId = CRYPTO_E_PARAM_POINTER;
  }
#  if(CRYPTO_30_HWA_ROMKEY == STD_ON) /* COV_CRYPTO_30_HWA_HARDWARE_DEPENDENT_FEATURE */
  else if ((job->cryptoKeyId >= CRYPTO_30_HWA_ROMKEY_MASK) && ((job->cryptoKeyId - CRYPTO_30_HWA_ROMKEY_MASK) >= Crypto_30_Hwa_GetSizeOfKeyMap()))
  {
    errorId = CRYPTO_E_KEY_NOT_VALID;
  }
#  endif /* (CRYPTO_30_HWA_ROMKEY == STD_ON) */
  else if (Crypto_30_Hwa_Local_DetChecksServiceValues(job, &errorId) == E_NOT_OK) /* SBSW_CRYPTO_30_HWA_FORWARDING_OF_JOB_PTR */
  {
    /* Error Id is set by sub-function */
  }
# endif /* (CRYPTO_30_HWA_OBJECTINFO == STD_ON) */
  else
#endif /* (CRYPTO_30_HWA_DEV_ERROR_DETECT == STD_ON) */
  {
#if (CRYPTO_30_HWA_OBJECTINFO == STD_ON)
    /* #15 Synchronously process job if it is synchronous or asynchronous */
    SchM_Enter_Crypto_30_Hwa_CRYPTO_30_HWA_EXCLUSIVE_AREA_0();
    retVal = Crypto_30_Hwa_TryObtainingLock(objectId, job->jobInfo->jobId, job->cryptoKeyId, job->jobPrimitiveInputOutput.mode);

    if (retVal == E_OK)
    {
      Crypto_30_Hwa_SetDriverObjectState(objectId, CRYPTO_30_HWA_DRIVEROBJECTSTATE_PROCESSING); /* SBSW_CRYPTO_30_HWA_CSL01_OBJECTID */
      SchM_Exit_Crypto_30_Hwa_CRYPTO_30_HWA_EXCLUSIVE_AREA_0();

      retVal = Crypto_30_Hwa_Process(objectId, job); /* SBSW_CRYPTO_30_HWA_FORWARDING_OF_JOB_PTR */

      /* Remove job from queue and release processing */
      Crypto_30_Hwa_SetDriverObjectState(objectId, CRYPTO_30_HWA_DRIVEROBJECTSTATE_IDLE); /* SBSW_CRYPTO_30_HWA_CSL01_OBJECTID */
    }
    else
    {
      SchM_Exit_Crypto_30_Hwa_CRYPTO_30_HWA_EXCLUSIVE_AREA_0();
    }

    if (job->jobPrimitiveInfo->processingType == CRYPTO_PROCESSING_ASYNC)
    {
      /* Invoke CryIf callback in case of an asynchronous job */
      CryIf_CallbackNotification(job, retVal);
    }
#else /* (CRYPTO_30_HWA_OBJECTINFO == STD_ON) */
  retVal = E_NOT_OK;
  errorId = CRYPTO_E_PARAM_HANDLE;

  CRYPTO_30_HWA_DUMMY_STATEMENT(objectId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  CRYPTO_30_HWA_DUMMY_STATEMENT(job); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
#endif /* (CRYPTO_30_HWA_OBJECTINFO == STD_ON) */
  }

#if (CRYPTO_30_HWA_DEV_ERROR_REPORT == STD_ON)
# if (CRYPTO_30_HWA_OBJECTINFO == STD_ON)
  if (errorId != CRYPTO_E_NO_ERROR)
# endif /* (CRYPTO_30_HWA_OBJECTINFO == STD_ON) */
  {
    (void)Det_ReportError(CRYPTO_30_HWA_MODULE_ID, CRYPTO_30_HWA_INSTANCE_ID, CRYPTO_30_HWA_SID_PROCESS_JOB, errorId);
  }
#else /* (CRYPTO_30_HWA_DEV_ERROR_REPORT == STD_ON) */
  CRYPTO_30_HWA_DUMMY_STATEMENT(errorId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
#endif /* (CRYPTO_30_HWA_DEV_ERROR_REPORT == STD_ON) */

  return retVal;
} /* Crypto_30_Hwa_ProcessJob() */ /* PRQA S 6080 */ /* MD_MSR_STMIF */

/**********************************************************************************************************************
 *  Crypto_30_Hwa_CancelJob()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(Std_ReturnType, CRYPTO_30_HWA_CODE) Crypto_30_Hwa_CancelJob(
  uint32 objectId,
  Crypto_30_Hwa_JobPtrType job) /* PRQA S 3673 */ /* MD_MSR_Rule8.13 */
{
  Std_ReturnType retVal = E_NOT_OK;
  uint8 errorId = CRYPTO_E_NO_ERROR; /* PRQA S 2981 */ /* MD_MSR_RetVal */

#if (CRYPTO_30_HWA_OBJECTINFO == STD_ON)
# if (CRYPTO_30_HWA_ROMKEY == STD_ON) /* COV_CRYPTO_30_HWA_HARDWARE_DEPENDENT_FEATURE */
  uint32 cryptoKeyIdTemp;
# endif /* (CRYPTO_30_HWA_ROMKEY == STD_ON) */
#endif /* (CRYPTO_30_HWA_OBJECTINFO == STD_ON) */

#if (CRYPTO_30_HWA_DEV_ERROR_DETECT == STD_ON)
  /* [SWS_Crypto_00123] */
  /* Check initialization state of the component. */
  if (Crypto_30_Hwa_ModuleInitialized != (uint8)CRYPTO_30_HWA_INITIALIZED)
  {
    errorId = CRYPTO_E_UNINIT;
  }
  /* [SWS_Crypto_00124] */
  /* Check plausibility of parameters. */
# if (CRYPTO_30_HWA_OBJECTINFO == STD_ON)
  else if (objectId >= Crypto_30_Hwa_GetSizeOfObjectInfo())
  {
    errorId = CRYPTO_E_PARAM_HANDLE;
  }
  /* [SWS_Crypto_00125] Check if job is a null pointer */
  else if (job == NULL_PTR)
  {
    errorId = CRYPTO_E_PARAM_POINTER;
  }
# endif /* (CRYPTO_30_HWA_OBJECTINFO == STD_ON) */
  else
#endif /* (CRYPTO_30_HWA_DEV_ERROR_DETECT == STD_ON) */
  {
#if (CRYPTO_30_HWA_OBJECTINFO == STD_ON)
    SchM_Enter_Crypto_30_Hwa_CRYPTO_30_HWA_EXCLUSIVE_AREA_0();
    /* Check if driver object is idle */
    if (Crypto_30_Hwa_GetDriverObjectState(objectId) == CRYPTO_30_HWA_DRIVEROBJECTSTATE_IDLE)
    {
      if (Crypto_30_Hwa_IsLockOccupiedByJob(objectId, job->jobInfo->jobId))
      {
        /* Hardware specific cleanup */
        retVal = Crypto_30_Hwa_Hw_CancelJob(objectId, job);

        /* Unlock driver object */
        Crypto_30_Hwa_FreeLock(objectId);
        job->state = CRYPTO_JOBSTATE_IDLE;

# if (CRYPTO_30_HWA_ROMKEY == STD_ON) /* COV_CRYPTO_30_HWA_HARDWARE_DEPENDENT_FEATURE */
        /* Verify that key is hardware key */
        cryptoKeyIdTemp = job->cryptoKeyId;
        if (Crypto_30_Hwa_CheckAggregatedKeyId(&cryptoKeyIdTemp) == E_OK)
        {
          vHsm_Api_KeyReadLockReleaseNotProtected(cryptoKeyIdTemp);
        }
# else /* (CRYPTO_30_HWA_ROMKEY == STD_ON) */
        vHsm_Api_KeyReadLockReleaseNotProtected(job->cryptoKeyId);
# endif /* (CRYPTO_30_HWA_ROMKEY == STD_ON) */
      }
    }
    SchM_Exit_Crypto_30_Hwa_CRYPTO_30_HWA_EXCLUSIVE_AREA_0();
#else /* (CRYPTO_30_HWA_OBJECTINFO == STD_ON) */
  errorId = CRYPTO_E_PARAM_HANDLE;

  CRYPTO_30_HWA_DUMMY_STATEMENT(objectId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  CRYPTO_30_HWA_DUMMY_STATEMENT(job); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
#endif /* (CRYPTO_30_HWA_OBJECTINFO == STD_ON) */
  }

#if (CRYPTO_30_HWA_DEV_ERROR_REPORT == STD_ON)
# if (CRYPTO_30_HWA_OBJECTINFO == STD_ON)
  if (errorId != CRYPTO_E_NO_ERROR)
# endif /* (CRYPTO_30_HWA_OBJECTINFO == STD_ON) */
  {
    (void)Det_ReportError(CRYPTO_30_HWA_MODULE_ID, CRYPTO_30_HWA_INSTANCE_ID, CRYPTO_30_HWA_SID_CANCEL_JOB, errorId);
  }
#else /* (CRYPTO_30_HWA_DEV_ERROR_REPORT == STD_ON) */
  CRYPTO_30_HWA_DUMMY_STATEMENT(errorId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
#endif /* (CRYPTO_30_HWA_DEV_ERROR_REPORT == STD_ON) */

  return retVal;
} /* Crypto_30_Hwa_CancelJob() */ /* PRQA S 6030, 6080 */ /* MD_MSR_STCYC, MD_MSR_STMIF */

/**********************************************************************************************************************
 *  Crypto_30_Hwa_UpdateJobState()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, CRYPTO_30_HWA_CODE) Crypto_30_Hwa_UpdateJobState(
  Std_ReturnType retVal,
  Crypto_30_Hwa_JobPtrType job)
{
  if (retVal == E_OK)
  {
    job->state = CRYPTO_JOBSTATE_ACTIVE;
  }
  else
  {
    /* [SWS_Crypto_00025] [SWS_Crypto_00119] Set job to IDLE if error occurred */
    job->state = CRYPTO_JOBSTATE_IDLE;
  }
} /* Crypto_30_Hwa_UpdateJobState() */

#define CRYPTO_30_HWA_STOP_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*!
 * \exclusivearea CRYPTO_30_HWA_EXCLUSIVE_AREA_0
 *                Protects the HWA driver objects on locking and freeing. Also LibCv key read locking is done
 *                with the protection of this exclusive area.
 * \protects      Crypto_30_Hwa_ObjectInfo
 * \usedin        Crypto_30_Hwa_Process(), Crypto_30_Hwa_ProcessJob(), Crypto_30_Hwa_CancelJob()
 * \exclude       -
 * \length        SHORT usually not more than 20 LOC
 * \endexclusivearea

 * \exclusivearea CRYPTO_30_HWA_EXCLUSIVE_AREA_1
 *                Protects hardware access to AES/AEAD/CMAC crypto accelerators
 * \protects      Access to hardware
 * \usedin        Crypto_30_Hwa_AesProcessBlocksSlicing, Crypto_30_Hwa_AesStart, Crypto_30_Hwa_AesEncUpdate, Crypto_30_Hwa_AesDecUpdate,
 *                Crypto_30_Hwa_AesDecFinish, Crypto_30_Hwa_AesEncFinish, Crypto_30_Hwa_AesGcmProcessBlocksAadSlicing,
 *                Crypto_30_Hwa_AesGcmProcessBlocksSlicing, Crypto_30_Hwa_AesGcmUpdateAad, Crypto_30_Hwa_AesGcmUpdateInput,
 *                Crypto_30_Hwa_AesGcmFinish, Crypto_30_Hwa_CmacSubKeyGeneration_k1, Crypto_30_Hwa_CmacProcessBlocksSlicing,
 *                Crypto_30_Hwa_CmacStart, Crypto_30_Hwa_CmacFinish
 * \exclude       -
 * \length        LONG depending on the input data and the slicing threshold CRYPTO_30_HWA_NON_PREEMPTIVE_CHUNK_SIZE
 * \endexclusivearea

 * \exclusivearea CRYPTO_30_HWA_EXCLUSIVE_AREA_2
 *                Protects hardware access to Hash crypto accelerators
 * \protects      Access to hardware
 * \usedin        Crypto_30_Hwa_Sha256Start, Crypto_30_Hwa_Sha256Update, Crypto_30_Hwa_Sha256Finish
 * \exclude       -
 * \length        LONG depending on the input data and the slicing threshold CRYPTO_30_HWA_NON_PREEMPTIVE_CHUNK_SIZE
 * \endexclusivearea

 * \exclusivearea CRYPTO_30_HWA_EXCLUSIVE_AREA_3
 *                Protects hardware access to Trng crypto accelerators
 * \protects      Access to hardware
 * \usedin        Crypto_30_Hwa_MemRandSlicing, Crypto_30_Hwa_TrngProcessDataReady, Crypto_30_Hwa_TrngPrefetch,
 * \exclude       -
 * \length        LONG depending on the input data and the slicing threshold CRYPTO_30_HWA_NON_PREEMPTIVE_CHUNK_SIZE
 * \endexclusivearea
 */

/* Module specific MISRA deviations

MD_CRYPTO_30_HWA_2812_DET_CHECK_NULLPOINTER
Reason:           Length pointer is dereferences to check its value
Risk:             Dereferencing a null pointer
Prevention:       Code review and tests. Pointer is checked in if-statement before.

MD_CRYPTO_30_HWA_0310_3305_PERFORMANCE
Reason:           Atomic register access or performance improvement. Cast to e.g. 32 bit required to generate load/store instructions with native word size.
Risk:             Casting to different object pointer type can result in runtime errors (out of bounds, missalignment).
Prevention:       Code review, tests. Access boundaries and alignment are checked before cast. Some hardware can handle unaligned access.

MD_CRYPTO_30_HWA_2986_REDUNDANT_OP
Reason:           Value is ORed with default assigned E_OK which is 0. The result is always the right hand operand.
Risk:             None
Prevention:       Code review and tests. The statement depends on enabled/disabled code parts.

MD_CRYPTO_30_HWA_2992_EXPRESSION_FALSE
Reason:           The expression includes an configurable Define. In other Configurations this expression have other results.
Risk:             None
Prevention:       None

MD_CRYPTO_30_HWA_2996_EXPRESSION_FALSE
Reason:           The expression includes an configurable Define. In other Configurations this expression have other results.
Risk:             None
Prevention:       None

MD_CRYPTO_30_HWA_3218_REDUCTION_TABLE
Reason:           Reduction table needs to be static, although it is only accessed in one function.
Risk:             None
Prevention:       Tests on hardware and review

MD_CRYPTO_30_HWA_3218_DOM2_DATA
Reason:           Dom2 string for Ed25519 signature calculation needs to be static, although it is only accessed in one function.
Risk:             None
Prevention:       Tests on hardware and review

MD_CRYPTO_30_HWA_2985_REDUNDANT_OP:
Reason:           The redundant operation is a side effect of a better readability of the code.
Risk:             None
Prevention:       N/A

MD_CRYPTO_30_HWA_2981_REDUNDANT_INITIALIZATION:
Reason:           The redundant initialization exist in some configuration to avoid increased complexity of the code
Risk:             Decreased performance due to double initialization if the compiler does not optimize it.
Prevention:       N/A

 */

/* COV_JUSTIFICATION_BEGIN

\ID COV_CRYPTO_30_HWA_LOCAL_DEFINE
\ACCEPT           XF
\ACCEPT           TX
\ACCEPT           XX
\REASON           Ensures that LOCAL and LOCAL_INLINE are always set if not set yet from outside.

\ID COV_CRYPTO_30_HWA_CSM_DEFINES
\ACCEPT           TX
\ACCEPT           XF
\REASON           Ensures that CRYPTO defines are always set. Normally done by CSM which is not necessarily present.

\ID COV_CRYPTO_30_HWA_CUSTOM_KEY_ELEMENTS
\ACCEPT           TX
\REASON           The Crypto needs custom key elements, which could be defined in other modules as well.

\ID COV_CRYPTO_30_HWA_CUSTOM_ALGORITHM
\ACCEPT           TX
\ACCEPT           XF
\REASON           The Crypto needs custom algorithm and algorithm mode defines, which could be defined in other modules as well.

\ID COV_CRYPTO_30_HWA_CASE_DEFAULT
\ACCEPT           X
\REASON           The default case is sometimes never reached because not supported cases are not forwarded to this function because of DET checks.
\PREVENTION       Covered by code review and tests

\ID COV_CRYPTO_30_HWA_ENDIANESS
\ACCEPT           XF
\ACCEPT           TX
\REASON           This encapsulation is for different hardware platforms with different endianess.
\PREVENTION       Covered by code review and tests

\ID COV_CRYPTO_30_HWA_HARDWARE_DEPENDENT_FEATURE
\ACCEPT           XX
\ACCEPT           XF
\ACCEPT           TX
\ACCEPT           TF tf xf xf
\ACCEPT           TF tf tf xf
\ACCEPT           TF tf xf tf
\ACCEPT           XF xf xf
\ACCEPT           XF tf xf
\ACCEPT           TX tx tx
\REASON           Feature is not supported on some platforms and will not be enabled on those.
\PREVENTION       Covered by code review and tests. The configuration cannot be changed by the user.

\ID COV_CRYPTO_30_HWA_AESGCM_ALGORITHM_REQUIREMENT
\ACCEPT           TX
\REASON           AES GCM requires the processing of the last block in the finish step
\PREVENTION       Covered by code review and tests. The implementation always processes last block in finish step.

\ID COV_CRYPTO_30_HWA_VSECPRIM_HASH_ALGORITHM
\ACCEPT           TX
\ACCEPT           XF
\REASON           Ensures that vSecPrim dependent values can be defined in other modules as well.

\ID COV_CRYPTO_30_HWA_GHASH_SPEED_UP
\ACCEPT           TX
\ACCEPT           XF
\REASON           This check always has the same result since the switch CRYPTO_30_HWA_GHASH_SPEED_UP is constantly defined to the value 1.
\PREVENTION       Covered by code review.

\ID COV_CRYPTO_30_HWA_MEMMAP_EXAMPLE
\ACCEPT           TX
\REASON           Examples for different compilers are given in the MemMap file. Project is only compiled with one compiler in all configs.

COV_JUSTIFICATION_END */

/**********************************************************************************************************************
 *  END OF FILE: Crypto_30_Hwa.c
 *********************************************************************************************************************/
