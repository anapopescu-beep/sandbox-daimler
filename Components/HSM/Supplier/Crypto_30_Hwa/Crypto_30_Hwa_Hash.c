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
/*!        \file  Crypto_30_Hwa_Hash.c
 *        \brief  Crypto Hwa Hash implementation
 *
 *      \details  This file implements Hash crypto algorithm.
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 *********************************************************************************************************************/

#define CRYPTO_30_HWA_HASH_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

#include "Crypto_30_Hwa.h"
#include "Crypto_30_Hwa_Private.h"
#include "Crypto_30_Hwa_Hw.h"

#include "vstdlib.h"

/**********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 *********************************************************************************************************************/
#if !defined (CRYPTO_30_HWA_LOCAL) /* COV_CRYPTO_30_HWA_LOCAL_DEFINE */
# define CRYPTO_30_HWA_LOCAL                                              static
#endif

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

#define CRYPTO_30_HWA_STOP_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

#define CRYPTO_30_HWA_START_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define CRYPTO_30_HWA_STOP_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/

#define CRYPTO_30_HWA_START_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#if (CRYPTO_30_HWA_PRIMITIVE_SHA2_256 == STD_ON) /* COV_CRYPTO_30_HWA_HARDWARE_DEPENDENT_FEATURE */
/**********************************************************************************************************************
 *  Crypto_30_Hwa_Sha256Start()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(Std_ReturnType, CRYPTO_30_HWA_CODE) Crypto_30_Hwa_Sha256Start(
  Crypto_30_Hwa_WorkSpaceSHA256_PtrType workspace)
{
  Std_ReturnType retVal = E_NOT_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  /* #20 Clear context information */
  workspace->totalLength = 0u;
  workspace->bufferFillLevel = 0u;

  SchM_Enter_Crypto_30_Hwa_CRYPTO_30_HWA_EXCLUSIVE_AREA_2();
  retVal = Crypto_30_Hwa_Hw_Sha256Start(workspace);
  SchM_Exit_Crypto_30_Hwa_CRYPTO_30_HWA_EXCLUSIVE_AREA_2();

  return retVal;
} /* Crypto_30_Hwa_Sha256Start() */

/**********************************************************************************************************************
 *  Crypto_30_Hwa_Sha256Update()
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
FUNC(Std_ReturnType, CRYPTO_30_HWA_CODE) Crypto_30_Hwa_Sha256Update(
  Crypto_30_Hwa_WorkSpaceSHA256_PtrType workspace,
  P2CONST(uint8, AUTOMATIC, CRYPTO_30_HWA_APPL_DATA) inputPtr,
  uint32 inputLength)
{
  Std_ReturnType retVal = E_NOT_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */
  uint32_least inputProcessed;

  inputProcessed = 0u;

  /* #20 While >=64 byte are available in buffer and input, process them */
  retVal = E_OK;
  while ((workspace->bufferFillLevel + (inputLength - inputProcessed)) >= CRYPTO_30_HWA_HASH_BLOCK_SIZE_BYTES)
  {
    /* #30 Process buffered data first if available */
    if (workspace->bufferFillLevel > 0u)
    {
      /* Complete buffer with input data */
      VStdLib_MemCpy(&workspace->buffer[workspace->bufferFillLevel], &inputPtr[inputProcessed], (CRYPTO_30_HWA_HASH_BLOCK_SIZE_BYTES - workspace->bufferFillLevel)); /* PRQA S 0315 */ /* MD_MSR_VStdLibCopy */
      inputProcessed += (CRYPTO_30_HWA_HASH_BLOCK_SIZE_BYTES - workspace->bufferFillLevel);
      /* Push data to hardware */
      SchM_Enter_Crypto_30_Hwa_CRYPTO_30_HWA_EXCLUSIVE_AREA_2();
      retVal |= Crypto_30_Hwa_Hw_Sha256ProcessBlocks(workspace, workspace->buffer, CRYPTO_30_HWA_HASH_BLOCK_SIZE_BYTES);
      SchM_Exit_Crypto_30_Hwa_CRYPTO_30_HWA_EXCLUSIVE_AREA_2();
      workspace->bufferFillLevel = 0u;
      /* Remember total input data length for padding at finish step */
      workspace->totalLength += CRYPTO_30_HWA_HASH_BLOCK_SIZE_BYTES;
    }

    /* #40 Process input data in SHA256 blocks (64 byte) */
    if ((inputLength - inputProcessed) >= CRYPTO_30_HWA_HASH_BLOCK_SIZE_BYTES)
    {
      SchM_Enter_Crypto_30_Hwa_CRYPTO_30_HWA_EXCLUSIVE_AREA_2();
      retVal |= Crypto_30_Hwa_Hw_Sha256ProcessBlocks(workspace, &inputPtr[inputProcessed], CRYPTO_30_HWA_HASH_BLOCK_SIZE_BYTES);
      SchM_Exit_Crypto_30_Hwa_CRYPTO_30_HWA_EXCLUSIVE_AREA_2();
      inputProcessed += CRYPTO_30_HWA_HASH_BLOCK_SIZE_BYTES;
      /* Remember total input data length for padding at finish step */
      workspace->totalLength += CRYPTO_30_HWA_HASH_BLOCK_SIZE_BYTES;
    }
  }

  /* #50 The rest is not a full block, copy to buffer */
  if ((inputProcessed < inputLength) && (retVal == E_OK))
  {
    VStdLib_MemCpy(&(workspace->buffer[workspace->bufferFillLevel]), &inputPtr[inputProcessed], (inputLength - inputProcessed)); /* PRQA S 0315 */ /* MD_MSR_VStdLibCopy */
    workspace->bufferFillLevel += (inputLength - inputProcessed);
  }

  return retVal;
} /* Crypto_30_Hwa_Sha256Update() */

/**********************************************************************************************************************
 *  Crypto_30_Hwa_Sha256Finish()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(Std_ReturnType, CRYPTO_30_HWA_CODE) Crypto_30_Hwa_Sha256Finish(
  Crypto_30_Hwa_WorkSpaceSHA256_PtrType workspace,
  P2VAR(uint8, AUTOMATIC, CRYPTO_30_HWA_APPL_DATA) hashsum,
  P2VAR(uint32, AUTOMATIC, CRYPTO_30_HWA_APPL_DATA) hashsumLength)
{
  Std_ReturnType retVal = E_NOT_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  /* Remember total input data length for padding at finish step */
  workspace->totalLength += workspace->bufferFillLevel;

  /* Call platform specific finish, note that this must process remaining data in buffer */
  SchM_Enter_Crypto_30_Hwa_CRYPTO_30_HWA_EXCLUSIVE_AREA_2();
  retVal = Crypto_30_Hwa_Hw_Sha256Finish(workspace, hashsum, hashsumLength);
  SchM_Exit_Crypto_30_Hwa_CRYPTO_30_HWA_EXCLUSIVE_AREA_2();

  /* Clear workspace if configured */
# if (CRYPTO_30_HWA_CLEAR_WORKSPACE_BUFFERS == STD_ON)
  VStdLib_MemClr(workspace->buffer, sizeof(workspace->buffer)); /* PRQA S 0315 */ /* MD_MSR_VStdLibCopy */
# endif

  return retVal;
} /* Crypto_30_Hwa_Sha256Finish() */ /* PRQA S 6010 */ /* MD_MSR_STPTH */

/**********************************************************************************************************************
 *  Crypto_30_Hwa_ProcessSha256Job()
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
FUNC(Std_ReturnType, CRYPTO_30_HWA_CODE) Crypto_30_Hwa_ProcessSha256Job(
  uint32 objectId,
  P2VAR(uint8, AUTOMATIC, CRYPTO_30_HWA_APPL_DATA) errorIdPtr,
  Crypto_30_Hwa_JobPtrType job)
{
  Std_ReturnType retVal = E_NOT_OK;
  Crypto_30_Hwa_WorkSpaceSHA256_PtrType workspace;

  /* #10 Verify whether primitive info is correct */
  if (job->jobPrimitiveInfo->primitiveInfo->algorithm.family == CRYPTO_ALGOFAM_SHA2_256)
  {
    /* #20 Get workspace */
    workspace = Crypto_30_Hwa_GetWorkspaceOfSHA256(Crypto_30_Hwa_GetSHA256IdxOfObjectInfo(objectId));

    /* [SWS_Crypto_00017] [SWS_Crypto_00020] START while IDLE or ACTIVE */
    if (((job->state == CRYPTO_JOBSTATE_IDLE) || (job->state == CRYPTO_JOBSTATE_ACTIVE))
      && Crypto_30_Hwa_IsJobMode(job, CRYPTO_OPERATIONMODE_START))
    {
      /* #30 Handle start of hash operation */
      workspace->primitiveInfo = job->jobPrimitiveInfo->primitiveInfo;
      workspace->driverObjectId = objectId;
      retVal = Crypto_30_Hwa_Sha256Start(workspace);
      Crypto_30_Hwa_UpdateJobState(retVal, job); /* SBSW_CRYPTO_30_HWA_FORWARDING_OF_JOB_PTR */
    }

    /* UPDATE while ACTIVE */
    if ((job->state == CRYPTO_JOBSTATE_ACTIVE)
      && Crypto_30_Hwa_IsJobMode(job, CRYPTO_OPERATIONMODE_UPDATE)) /* [SWS_Crypto_00024] */
    {
      /* #40 Handle update of hash operation */
      retVal = Crypto_30_Hwa_Sha256Update(workspace, job->jobPrimitiveInputOutput.inputPtr, job->jobPrimitiveInputOutput.inputLength);
      Crypto_30_Hwa_UpdateJobState(retVal, job); /* SBSW_CRYPTO_30_HWA_FORWARDING_OF_JOB_PTR */
    }

    /* [SWS_Crypto_00023] FINISH while ACTIVE */
    if ((job->state == CRYPTO_JOBSTATE_ACTIVE)
      && Crypto_30_Hwa_IsJobMode(job, CRYPTO_OPERATIONMODE_FINISH)) /* [SWS_Crypto_00024] */
    {
      /* #50 Handle finish of hash operation */
      retVal = Crypto_30_Hwa_Sha256Finish(workspace, job->jobPrimitiveInputOutput.outputPtr, job->jobPrimitiveInputOutput.outputLengthPtr);
      job->state = CRYPTO_JOBSTATE_IDLE; /* SBSW_CRYPTO_30_HWA_DIRECT_ACCESS_TO_JOB_STATE */
    }

    *errorIdPtr = CRYPTO_E_NO_ERROR;
  }

  return retVal;
} /* Crypto_30_Hwa_ProcessSha256Job() */

#endif /* (CRYPTO_30_HWA_PRIMITIVE_SHA2_256 == STD_ON) */

#define CRYPTO_30_HWA_STOP_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  END OF FILE: Crypto_30_Hwa_Hash.c
 *********************************************************************************************************************/
