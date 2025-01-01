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
/*!        \file  vHsm_Api.c
 *        \brief  Api functions which can be used by the crypto drivers to minimize dependencies to the LibCv driver
 *
 *      \details
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 *********************************************************************************************************************/

#define VHSM_API_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "vHsm_Api.h"
#include "vHsm_ApiInternal.h"
#include "vHsm.h"
#include "vHsm_KeyM.h"
#include "vHsm_Nvm.h"
#include "vHsm_Core_SecureBoot.h"

#include "vHsm_Ipc.h"

#include "CryIf.h"
#include "Crypto_30_LibCv.h"
#include "Crypto_30_LibCv_KeyManagement.h"

/**********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 *********************************************************************************************************************/

#if !defined (VHSM_LOCAL) /* COV_VHSM_LOCAL_DEFINE */
# define VHSM_LOCAL                                                   static
#endif

#if !defined (VHSM_LOCAL_INLINE) /* COV_VHSM_LOCAL_DEFINE */
# define VHSM_LOCAL_INLINE                                            LOCAL_INLINE
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

#define VHSM_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

VHSM_LOCAL VAR(uint16, VHSM_VAR_ZERO_INIT) vHsm_Api_TmpJobId = 0u; /* PRQA S 3218 */ /* MD_VHSM_3218_WORKSPACE_VAR */

#define VHSM_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/

#define VHSM_START_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  vHsm_Api_Local_KeyElementGet()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(Std_ReturnType, VHSM_CODE) vHsm_Api_Local_KeyElementGet(
  uint32 cryptoKeyId,
  uint32 keyElementId,
  P2VAR(vHsm_Api_KeyStorageIndexType, AUTOMATIC, VHSM_APPL_VAR) resultIndexPtr,
  P2VAR(uint32, AUTOMATIC, VHSM_APPL_VAR) resultLengthPtr)
{
  /* #10 Forward request to LibCv */
  return Crypto_30_LibCv_Local_KeyElementGetStorageIndexExtended(cryptoKeyId, keyElementId, resultIndexPtr, resultLengthPtr, VHSM_API_LENGTH_CHECK_MAX, VHSM_API_SHE_SERVICE_OTHER);
}

/**********************************************************************************************************************
 *  vHsm_Api_KeyElementSet_Unchecked()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(Std_ReturnType, VHSM_CODE) vHsm_Api_KeyElementSet_Unchecked(
  uint32 cryptoKeyId,
  uint32 keyElementId,
  P2CONST(uint8, AUTOMATIC, VHSM_APPL_VAR) keyPtr,
  uint32 keyLength)
{
  Std_ReturnType retVal = E_OK;
  vHsm_Api_SizeOfKeyElementsType elementIndex;

  if (vHsm_Api_Local_KeyElementSearch(cryptoKeyId, keyElementId, &elementIndex) != E_OK)
  {
    retVal = CRYPTO_E_KEY_NOT_AVAILABLE;
  }
  else if (vHsm_Api_GetKeyElementLength(elementIndex) < keyLength)
  {
    retVal = CRYPTO_E_KEY_SIZE_MISMATCH;
  }
  else
  {
    vHsm_Api_KeyElementSetInternalStandard(elementIndex, keyPtr, keyLength);
    vHsm_Api_ClearKeyElementStateByMask(elementIndex, VHSM_API_KEYELEMENTSTATE_CLEAR_NORMAL_MASK);
  }

  return retVal;
}

/**********************************************************************************************************************
 *  vHsm_Api_InitializeTempJob()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, VHSM_CODE) vHsm_Api_InitializeTempJob(
  P2VAR(vHsm_Api_TempJobType, AUTOMATIC, VHSM_APPL_VAR) tmpJob,
  uint32 cryptoKeyId)
{
  /* #10 Prepare a temporary job */
  tmpJob->jobPrimitiveInfo.primitiveInfo = &tmpJob->primitiveInfo;
  tmpJob->job.jobPrimitiveInfo = &tmpJob->jobPrimitiveInfo;
  tmpJob->job.jobInfo = &tmpJob->jobInfo;

  vHsm_Api_TempJob_SetProcessing(tmpJob, CRYPTO_PROCESSING_SYNC);
  vHsm_Api_TempJob_SetCryptoKeyId(tmpJob, cryptoKeyId);
  vHsm_Api_TempJob_SetJobId(tmpJob, (VHSM_API_INTERNAL_JOB_FLAG | vHsm_Api_TmpJobId));

  tmpJob->job.jobState = CRYPTO_JOBSTATE_IDLE;
  tmpJob->job.state = CRYPTO_JOBSTATE_IDLE;
  tmpJob->job.jobPrimitiveInputOutput.mode = CRYPTO_OPERATIONMODE_SINGLECALL;
#if(VHSM_REDIRECTION == STD_ON)
  tmpJob->job.jobRedirectionInfoRef = NULL_PTR;
#endif

  /* Overflow is considered and does not cause issues */
  vHsm_Api_TmpJobId++;
}

/**********************************************************************************************************************
 *  vHsm_Api_ProcessTempJob()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(Std_ReturnType, VHSM_CODE) vHsm_Api_ProcessTempJob(
  uint32 cryIfChannelId,
  P2VAR(vHsm_Api_TempJobType, AUTOMATIC, VHSM_APPL_VAR) tmpJob)
{
  Std_ReturnType retVal;
  if (tmpJob->job.jobInfo == &tmpJob->jobInfo)
  {
    /* #10 Process the job in the crypto driver */
    retVal = vHsm_GetProcessJobOfCryptoFunctions(vHsm_GetCryptoFunctionsIdxOfChannelInfo(cryIfChannelId))(
      vHsm_GetDriverObjectRefOfChannelInfo(cryIfChannelId),
      &tmpJob->job);
  }
  else
  {
    retVal = E_NOT_OK;
  }

  return retVal;
}

/**********************************************************************************************************************
 *  vHsm_Api_CancelTempJob()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(Std_ReturnType, VHSM_CODE) vHsm_Api_CancelTempJob(
  uint32 cryIfChannelId,
  P2VAR(vHsm_Api_TempJobType, AUTOMATIC, VHSM_APPL_VAR) tmpJob)
{
  Std_ReturnType retVal;
  if (tmpJob->job.jobInfo == &tmpJob->jobInfo)
  {
    /* #10 Cancel the job in the crypto driver */
    retVal = vHsm_GetCancelJobOfCryptoFunctions(vHsm_GetCryptoFunctionsIdxOfChannelInfo(cryIfChannelId))(
      vHsm_GetDriverObjectRefOfChannelInfo(cryIfChannelId),
      &tmpJob->job);
  }
  else
  {
    retVal = E_NOT_OK;
  }

  return retVal;
}

/**********************************************************************************************************************
 *  vHsm_Api_KeyElementGetForCryptoJobs()
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
FUNC(Std_ReturnType, VHSM_CODE) vHsm_Api_KeyElementGetForCryptoJobs(
    uint32 cryptoKeyId,
    uint32 keyElementId,
    P2VAR(vHsm_Api_KeyStorageIndexType, AUTOMATIC, VHSM_APPL_VAR) resultIndexPtr,
    uint32 resultLength,
    uint8 serviceType)
{
  Std_ReturnType retVal;
  uint32 keyLengthTmp = resultLength;

  /* #10 Check for valid cryptoKeyId */
  if (cryptoKeyId >= Crypto_30_LibCv_GetSizeOfKey())
  {
    retVal = E_NOT_OK;
  }
  else
  {
    /* #11 Get the key element */
    retVal = Crypto_30_LibCv_Local_KeyElementGetStorageIndexExtended(cryptoKeyId, keyElementId, resultIndexPtr, &keyLengthTmp, VHSM_API_LENGTH_CHECK_MAX, serviceType);

    /* #12 Check if no error happened  */
    if (retVal == E_OK)
    {
      /* Return was E_OK, but still length needs to be checked */
      if (keyLengthTmp != resultLength)
      {
        retVal = CRYPTO_E_KEY_SIZE_MISMATCH;
      }
    }
    /* #13 Handle other error codes */
    else if (retVal == CRYPTO_E_KEY_NOT_VALID)
    {
      /* Known retVal */
    }
    else if (retVal == CRYPTO_E_SMALL_BUFFER)
    {
      retVal = CRYPTO_E_KEY_SIZE_MISMATCH;
    }
    else if (retVal == CRYPTO_E_KEY_SIZE_MISMATCH)
    {
      /* Known retVal */
    }
    else
    {
      /* Unknown retval - convert to E_NOT_OK */
      retVal = E_NOT_OK;
    }
  }

  /* #30 Return the result */
  return retVal;
} /* PRQA S 6080 */ /* MD_MSR_STMIF */

/**********************************************************************************************************************
 *  vHsm_Api_SetKeyElementValidAndPersist()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(Std_ReturnType, VHSM_CODE) vHsm_Api_SetKeyElementValidAndPersist(
  uint32 cryptoKeyId,
  uint32 keyElementId,
  boolean persist)
{
  Std_ReturnType retVal;
  vHsm_Api_SizeOfKeyElementsType elementIndex;

  /* #10 Find the key element */
  if (cryptoKeyId >= vHsm_Api_GetSizeOfKey())
  {
    retVal = CRYPTO_E_KEY_NOT_AVAILABLE;
  }
  else if (vHsm_Api_Local_KeyElementSearch(cryptoKeyId, keyElementId, &elementIndex) != E_OK)
  {
    retVal = CRYPTO_E_KEY_NOT_AVAILABLE;
  }
  else
  {
    /* #20 Set the only the key element to valid */
    vHsm_Api_SetKeyElementStateByMask(elementIndex, VHSM_API_KEYELEMENTSTATE_VALID_MASK);

    /* #21 Persist the key */
#if (VHSM_API_NVM_USED == STD_ON)
    if (persist && vHsm_Api_IsPersistOfKeyElementInfo(vHsm_Api_GetKeyElementInfoIdxOfKeyElements(elementIndex)))
    {
      vHsm_Api_NvM_Persist(cryptoKeyId);
    }
#else
    VHSM_DUMMY_STATEMENT(persist); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
#endif

    retVal = E_OK;
  }

  return retVal;
}

/**********************************************************************************************************************
 *  vHsm_Api_DisallowKeyUsage()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(Std_ReturnType, VHSM_CODE) vHsm_Api_DisallowKeyUsage(uint32 cryIfKeyId)
{
  Std_ReturnType retVal = E_NOT_OK;

  /* check that cryIfKeyId is in a valid range */
  if (cryIfKeyId < vHsm_GetSizeOfKeyInfo())
  {
    /* #10  Safe old valid state of the key element to a buffer */
    vHsm_State.vHsm_KeyUsageRestriction[cryIfKeyId] |= VHSM_KEY_USAGE_API_RESTRICTION;
    retVal = E_OK;
  }
  return retVal;
}

/**********************************************************************************************************************
 *  vHsm_Api_AllowKeyUsage()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(Std_ReturnType, VHSM_CODE) vHsm_Api_AllowKeyUsage(uint32 cryIfKeyId)
{
  Std_ReturnType retVal = E_NOT_OK;
  /* check that cryIfKeyId is in a valid range */
  if (cryIfKeyId < vHsm_GetSizeOfKeyInfo())
  {
    /* #10  Restore the old valid state of the key element from the buffer */
    vHsm_State.vHsm_KeyUsageRestriction[cryIfKeyId] &= (uint8)(~VHSM_KEY_USAGE_API_RESTRICTION);
    retVal = E_OK;
  }
  return retVal;
}

/**********************************************************************************************************************
 *  vHsm_Api_Ramloop_PrepareExecution()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(void, VHSM_CODE) vHsm_Api_Ramloop_PrepareExecution(void)
{
  /* #10  Set flag to enter ram loop in the next main cycle */
  vHsm_State.vHsm_StayInRamFlag = TRUE;
  /* #20  Tell driver that we are not in RAM yet */
  vHsm_Ipc_LeaveRamExec(); /* PRQA S 0310, 3305 */ /* MD_VHSM_IPC_MACRO */
  /* #30  Delete flag from driver that RAM loop shall be exited */
  vHsm_Ipc_EndRamExec(); /* PRQA S 0310, 3305 */ /* MD_VHSM_IPC_MACRO */
}

/**********************************************************************************************************************
 *  vHsm_Api_Ramloop_Exit()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, VHSM_CODE) vHsm_Api_Ramloop_Exit(void)
{
  /* #10  Set flag from driver that RAM loop shall be exited */
  vHsm_Ipc_SetEndRamExecFlag(1u); /* PRQA S 0310, 3305 */ /* MD_VHSM_IPC_MACRO */
}

#if (VHSM_SECURE_BOOT == STD_ON)
/**********************************************************************************************************************
 *  vHsm_Api_SecureBoot_ResetTag()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(Std_ReturnType, VHSM_CODE) vHsm_Api_SecureBoot_ResetTag(vHsm_SecureBootGroupIterType groupIdx)
{
  Std_ReturnType retVal;

# if (VHSM_VERMETHOD_COMPARE_INTERNAL_TAG_AVAILABLE == STD_ON)
  vHsm_SecureBootSegmentIterType segmentIdx;
  retVal = E_OK;
  if (vHsm_IsCompInternalOfSecureBootGroup(groupIdx))
  {
    for (segmentIdx = vHsm_GetSecureBootSegmentStartIdxOfSecureBootGroup(groupIdx); segmentIdx < vHsm_GetSecureBootSegmentEndIdxOfSecureBootGroup(groupIdx); segmentIdx++)
    {
      retVal |= vHsm_SecureBoot_SetTag(segmentIdx, NULL_PTR, 0u, FALSE);
    }

    /* #10 Delete current tag */
    if (retVal == E_OK)
    {
      vHsm_SecureBootInfoType infotype;
      infotype.isCyclicVerification = FALSE;

      infotype.verMethod = VHSM_VERMETHOD_COMPARE_INTERNAL_TAG;
      /* #20 Process group sequentially and create tag */
      retVal = vHsm_SecureBoot_ProcessAllSegmentsOfGroup(
        groupIdx,
        TRUE,
        &infotype);
    }
  }
  else
# else
  VHSM_DUMMY_STATEMENT(groupIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
# endif
  {
    /* There is no tag. No reset necessary. */
    retVal = E_OK;
  }

  return retVal;
}
#endif /* (VHSM_SECURE_BOOT == STD_ON) */

#if (VHSM_NVM_SUPPORT == STD_ON)
/**********************************************************************************************************************
 *  vHsm_Api_NvM_WriteBlock()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(Std_ReturnType, VHSM_CODE) vHsm_Api_NvM_WriteBlock(
  NvM_BlockIdType BlockId,
  P2CONST(void, AUTOMATIC, VHSM_APPL_VAR) NvM_SrcPtr)
{
  /* #10 Forward request to vHsm internal API */
  return vHsm_NvM_WriteBlock(BlockId, NvM_SrcPtr);
}
#endif

/**********************************************************************************************************************
 *  vHsm_Api_DeactivateChannel()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(Std_ReturnType, VHSM_CODE) vHsm_Api_DeactivateChannel(uint32 channelId)
{
  Std_ReturnType retVal = E_NOT_OK;

  /* #10 Check channelId */
  if (channelId < vHsm_GetSizeOfJobObjects())
  {
    /* #20 Deactivate driver object */
    vHsm_JoinUsageRestrictionOfJobObjects(channelId, VHSM_DEACTIVATEJOBOBJECTS_API);
    retVal = E_OK;
  }
  return retVal;
}

/**********************************************************************************************************************
 *  vHsm_Api_ActivateChannel()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(Std_ReturnType, VHSM_CODE) vHsm_Api_ActivateChannel(uint32 channelId)
{
  Std_ReturnType retVal = E_NOT_OK;
  /* #10 Check channelId */
  if (channelId < vHsm_GetSizeOfJobObjects())
  {
    /* #20 Activate driver object */
    vHsm_DeleteUsageRestrictionOfJobObjects(channelId, VHSM_DEACTIVATEJOBOBJECTS_API);
    retVal = E_OK;
  }
  return retVal;
}

#define VHSM_STOP_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  END OF FILE: vHsm_Api.c
 *********************************************************************************************************************/
