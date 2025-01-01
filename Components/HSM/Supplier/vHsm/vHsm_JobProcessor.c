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
/*      \file     vHsm_JobProcessor.c
 *      \brief    Vector Hardware Security Module Firmware Jobs
 *
 *      \details  Implementation of the Vector Hardware Security Module Firmware Jobs
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 *********************************************************************************************************************/

#define VHSM_JOBPROCESSOR_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "vHsm.h"
#include "vHsm_JobProcessor.h"
#include "vHsm_KeyM.h"
#include "vHsm_Ipc.h"
#include "vHsm_Trace.h"

#include "SchM_vHsm.h"
#include "vHsm_Hal.h"

#include "CryIf_Cfg.h"

/**********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 *********************************************************************************************************************/

#if !defined (VHSM_LOCAL) /* COV_VHSM_LOCAL_DEFINE */
# define VHSM_LOCAL                                                   static
#endif

#if !defined (VHSM_LOCAL_INLINE) /* COV_VHSM_LOCAL_DEFINE */
# define VHSM_LOCAL_INLINE                                            LOCAL_INLINE
#endif

#define VHSM_MEMAREA_GLOBALRAM_AND_NULLPTR_ALLOWED                    (0u)
#define VHSM_MEMAREA_DATAFLASH_ALLOWED                                (1u)
#define VHSM_MEMAREA_CODEFLASH_ALLOWED                                (2u)

#define VHSM_32BIT_ALIGNMENT_MASK                                     (3u)

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

 /**********************************************************************************************************************
 *  vHsm_JobProcessor_ExecuteCryptoJob()
 *********************************************************************************************************************/
 /*! \brief      Process crypto job.
 *  \details     -
 *  \param[in]   jobObjectId     Id of the object
 *  \return      TRUE if the job was processed correctly, otherwise E_NOT_OK
 *  \pre         -
 *  \context     ANY
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
VHSM_LOCAL_INLINE FUNC(Std_ReturnType, VHSM_CODE) vHsm_JobProcessor_ExecuteCryptoJob(
  vHsm_JobObjectIdType jobObjectId);

/**********************************************************************************************************************
 *  vHsm_JobProcessor_ExecuteKeyMJob()
 *********************************************************************************************************************/
/*! \brief       Process key management job.
 *  \details     -
 *  \param[in]   jobObjectId     Id of the object
 *  \return      TRUE if the job was processed correctly, otherwise E_NOT_OK
 *  \pre         -
 *  \context     ANY
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
VHSM_LOCAL_INLINE FUNC(Std_ReturnType, VHSM_CODE) vHsm_JobProcessor_ExecuteKeyMJob(
  vHsm_JobObjectIdType jobObjectId);

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

#define VHSM_START_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  vHsm_JobProcessor_ExecuteCryptoJob()
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
 */
VHSM_LOCAL_INLINE FUNC(Std_ReturnType, VHSM_CODE) vHsm_JobProcessor_ExecuteCryptoJob(
  vHsm_JobObjectIdType jobObjectId)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal;
  uint32 cryIfChannelIdTmp = jobObjectId;
  P2VAR(vHsm_Api_TempJobType, AUTOMATIC, VHSM_APPL_VAR) job = &vHsm_GetJobDataOfJobObjects(jobObjectId).crypto_Job;

  /* ----- Implementation ----------------------------------------------- */

  /* #20 Check if the request is marked as valid (has valid input/output pointers */
  if (vHsm_IsValidRequestFlagOfJobObjects(jobObjectId) == FALSE)
  {
    /* VHSM_DEBUG_BREAKPOINT_2:
     * When the breakpoint is hit, have a look at the DET or debug the corresponding vHsm_Ipc_Is<...>JobBuffersValid() function.
     * Often, the cryptoKeyId is not accepted/valid or some pointers are not inside the memory area whitelist.
     */

    /* #21 If the job request was invalid, fill the result with E_NOT_OK */
    vHsm_SetJobRetValOfJobObjects(jobObjectId, E_NOT_OK);
  }
  else
  {
    /* #30 Check if the application core tries to issue a command to a driver object which is allowed to be used */
    /* Do not allow restricted channels */
    if ((job->jobInfo.jobId & VHSM_API_EXTERNAL_JOB_FLAG) != VHSM_API_EXTERNAL_JOB_FLAG)
    {
      vHsm_SetJobRetValOfJobObjects(jobObjectId, E_NOT_OK);
    }
    /* #40 Check if the command is a cancel command */
    else if (vHsm_IsCancelFlagOfJobObjects(jobObjectId) == TRUE)
    {
      /* #45 Cancel the job in the corresponding driver */
      vHsm_SetJobRetValOfJobObjects(jobObjectId, vHsm_GetCancelJobOfCryptoFunctions(vHsm_GetCryptoFunctionsIdxOfChannelInfo(cryIfChannelIdTmp))(
        vHsm_GetDriverObjectRefOfChannelInfo(cryIfChannelIdTmp),
        &job->job));
    }
    else /* #50 Process Job */
    {
      /* #53 Process the Crypto job in the corresponding driver */
      vHsm_SetJobRetValOfJobObjects(jobObjectId, vHsm_GetProcessJobOfCryptoFunctions(vHsm_GetCryptoFunctionsIdxOfChannelInfo(cryIfChannelIdTmp))(
        vHsm_GetDriverObjectRefOfChannelInfo(cryIfChannelIdTmp),
        &job->job));
    }

    /* #60 Store the local copy of the outputLength to the final destination */
#if (VHSM_IPC_PROTOCOL_VERSION == 2u)
    if (vHsm_GetLocalOutputOfJobObjects(jobObjectId).output.lengthPtr != NULL_PTR)
    {
      *vHsm_GetLocalOutputOfJobObjects(jobObjectId).output.lengthPtr = vHsm_GetLocalOutputOfJobObjects(jobObjectId).output.length;
    }
    if (vHsm_GetLocalOutputOfJobObjects(jobObjectId).secondaryOutput.lengthPtr != NULL_PTR)
    {
      *vHsm_GetLocalOutputOfJobObjects(jobObjectId).secondaryOutput.lengthPtr = vHsm_GetLocalOutputOfJobObjects(jobObjectId).secondaryOutput.length;
    }
#endif
  }

  /* #80 Prepare response for Host */
  vHsm_Api_TempJob_SetJobId(job, vHsm_Ipc_UnmaskIpcChannelFromJobId(job->jobInfo.jobId));

  /* #90 Transmit the result as response */
  retVal = vHsm_Ipc_TransmitJobResponse(jobObjectId, VHSM_CRYPTO_JOBRESULTTYPE_SERIALIZED_BUF_SIZE + VHSM_JOBRESPONSE_HEADER_SIZE);

  return retVal;
} /* PRQA S 6080 */ /* MD_MSR_STMIF */

/**********************************************************************************************************************
 *  vHsm_JobProcessor_ExecuteKeyMJob()
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
VHSM_LOCAL_INLINE FUNC(Std_ReturnType, VHSM_CODE) vHsm_JobProcessor_ExecuteKeyMJob(
  vHsm_JobObjectIdType jobObjectId)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal;
  P2VAR(vHsm_KeyM_JobType, AUTOMATIC, VHSM_APPL_VAR) job = &vHsm_GetJobDataOfJobObjects(jobObjectId).keyM_Job;

  /* ----- Implementation ----------------------------------------------- */

  /* #10 Check if the request is marked as valid (has valid input/output pointers */
  if (vHsm_IsValidRequestFlagOfJobObjects(jobObjectId) == FALSE)
  {
    /* VHSM_DEBUG_BREAKPOINT_3:
     * When the breakpoint is hit, have a look at the DET or debug the corresponding vHsm_Ipc_Is<...>JobBuffersValid() function.
     * Often, the cryptoKeyId is not accepted/valid or some pointers are not inside the memory area whitelist.
     */

    /* #11 If the job request was invalid, fill the result with E_NOT_OK */
    vHsm_SetJobRetValOfJobObjects(jobObjectId, E_NOT_OK);
  }
  else
  {
    /* #30 Process KeyM Job */
    vHsm_SetJobRetValOfJobObjects(jobObjectId, vHsm_KeyM_ProcessJob(job));

    /* #35 Store the local copy of the outputLength to the final destination */
#if (VHSM_IPC_PROTOCOL_VERSION == 2u)
    if (vHsm_GetLocalOutputOfJobObjects(jobObjectId).output.lengthPtr != NULL_PTR)
    {
      *vHsm_GetLocalOutputOfJobObjects(jobObjectId).output.lengthPtr = vHsm_GetLocalOutputOfJobObjects(jobObjectId).output.length;
    }
#endif
  }

  /* Check if the most recent KeyM job has set the stayInRamFlag */
  if ( (vHsm_State.vHsm_StayInRamFlag == TRUE)
    && (vHsm_State.vHsm_StayInRamIpcChannel == VHSM_INVALID_IPC_CHANNEL))
  {
    vHsm_State.vHsm_StayInRamIpcChannel = vHsm_Ipc_Idx;
  }

  /* #60 Transmit the result as response */
  retVal = vHsm_Ipc_TransmitJobResponse(jobObjectId, VHSM_KEYM_JOBRESULTTYPE_SERIALIZED_BUF_SIZE + VHSM_JOBRESPONSE_HEADER_SIZE);

  return retVal;
}

#define VHSM_STOP_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/

#define VHSM_START_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  vHsm_JobProcessor_Execute()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(void, VHSM_CODE) vHsm_JobProcessor_Execute(
  vHsm_JobObjectIdType jobObjectId)
{
  Std_ReturnType retVal;

  /* VHSM_DEBUG_BREAKPOINT_4:
   * Set a breakpoint here to check if a job has been received and is about to be executed.
   */

  /* #10 Decide depending on the kind of the job, how it shall be processed */
  if (vHsm_GetProcessKindOfJobObjects(jobObjectId) == VHSM_CRYPTO_JOBKIND)
  {
    retVal = vHsm_JobProcessor_ExecuteCryptoJob(jobObjectId);
  }
  else
  {
    retVal = vHsm_JobProcessor_ExecuteKeyMJob(jobObjectId);
  }

  if (retVal != E_OK)
  {
    /* #30 Write to the error log if an error occurred */
    vHsm_Trace(VHSM_TRACETYPE_ERROR, "An error occurred during processing of the job (retval=%i)\n", retVal);
    (void)vHsm_WriteErrorLog(VHSM_LOG_ID_JOBPROCESSING_ERROR, VHSM_LOG_DATA_NO_ERROR_DATA); /*lint !e522 */
  }
}

#if (VHSM_INTERRUPT_MODE == STD_ON)
/**********************************************************************************************************************
 *  vHsm_JobProcessor_MainFunction()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(void, VHSM_CODE) vHsm_JobProcessor_MainFunction(uint32 schedEntityIdx)
{
  /* #10 Iterate over all objects referenced in the current schedulable entity container */
  vHsm_SchedulableEntitiesIterType schedIdx;
  uint32 jobObjectId;

  SchM_Enter_vHsm_VHSM_EXCLUSIVE_AREA_0();

  for (schedIdx = vHsm_GetScheduledChannelsStartIdxOfSchedulableEntities(schedEntityIdx); schedIdx < vHsm_GetScheduledChannelsEndIdxOfSchedulableEntities(schedEntityIdx); schedIdx++)
  {
    jobObjectId = vHsm_GetScheduledChannels(schedIdx);

    /* #20 Check if a job is pending */
    if (vHsm_GetStateOfJobObjects(jobObjectId) > VHSM_JOB_STATE_PROCESSING) /* == activated or pending */
    {
      vHsm_SetStateOfJobObjects(jobObjectId, VHSM_JOB_STATE_PROCESSING);

      SchM_Exit_vHsm_VHSM_EXCLUSIVE_AREA_0();
      /* fetching was done from ISR and this is an ISR job. Process it. */
      /* #30 Process the received job */
      vHsm_JobProcessor_Execute(jobObjectId);

      SchM_Enter_vHsm_VHSM_EXCLUSIVE_AREA_0();
    }
  }

  SchM_Exit_vHsm_VHSM_EXCLUSIVE_AREA_0();
}
#endif

#define VHSM_STOP_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  END OF FILE: vHsm_JobProcessor.c
 *********************************************************************************************************************/
