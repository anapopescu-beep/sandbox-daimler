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
/*!        \file  vMemAccM_SchedSync.c
 *        \brief  vMemAccM synchronous job scheduler sub module source file.
 *
 *      \details  See vMemAccM_SchedSync.h.
 *
 *         \unit  vMemAccM_SchedSync
 *
 *********************************************************************************************************************/

#define VMEMACCM_SCHEDSYNC_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "vMemAccM_SchedSync.h"
#include "vMemAccM_MemAb.h"
#include "vMemAccM_CfgAb.h"
#include "vMemAccM_SMLib.h"

#if (VMEMACCM_MINIMAL_SYNC == STD_ON)

/**********************************************************************************************************************
 *  LOCAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

#if !defined (VMEMACCM_LOCAL) /* COV_VMEMACCM_COMPATIBILITY */
# define VMEMACCM_LOCAL static
#endif

#if !defined (VMEMACCM_LOCAL_INLINE) /* COV_VMEMACCM_COMPATIBILITY */
# define VMEMACCM_LOCAL_INLINE LOCAL_INLINE
#endif

/**********************************************************************************************************************
 *  LOCAL DATA PROTOTYPES
 *********************************************************************************************************************/
#define VMEMACCM_START_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! Holds runtime information about each address area. */
VAR(vMemAccM_MngmtAreaType, VMEMACCM_VAR_NOINIT) vMemAccM_MngmtAreas[VMEMACCM_MNGMTAREA_SIZE];

#define VMEMACCM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#if (VMEMACCM_DEV_ERROR_DETECT == STD_ON)
#define VMEMACCM_START_SEC_VAR_ZERO_INIT_8BIT
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! Holds module initialization state. */
VMEMACCM_LOCAL VAR(uint8, VMEMACCM_VAR_ZERO_INIT) vMemAccM_ModuleInitialized = VMEMACCM_UNINIT;

#define VMEMACCM_STOP_SEC_VAR_ZERO_INIT_8BIT
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
#endif

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
#define VMEMACCM_START_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  vMemAccM_SchedSyncProcessJob
 *********************************************************************************************************************/
/*!
 * \brief       Process the jobs within the MemAb unit and therefore within the vMem.
 * \details     -
 * \param[in]   AddressAreaId as array index, used to access the virtual information.
 * \param[in]   SubAddressAreaId to determine the vMem to be processed.
 * \param[in]   JobLength to determine if whole job is finished.
 * \param[in]   vMemJobLength to know how much bytes are processed.
 * \return      TRUE job processing is finished.
 *              FALSE futher job steps needs to be processed
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */
VMEMACCM_LOCAL FUNC(boolean, VMEMACCM_CODE) vMemAccM_SchedSyncProcessJob
(
  vMemAccM_AddressAreaIdType AddressAreaId,
  vMemAccM_AddressAreaIdType SubAddressAreaId,
  vMemAccM_LengthType JobLength,
  vMemAccM_LengthType vMemJobLength
);

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  vMemAccM_SchedSyncProcessJob
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
VMEMACCM_LOCAL FUNC(boolean, VMEMACCM_CODE) vMemAccM_SchedSyncProcessJob
(
  vMemAccM_AddressAreaIdType AddressAreaId,
  vMemAccM_AddressAreaIdType SubAddressAreaId,
  vMemAccM_LengthType JobLength,
  vMemAccM_LengthType vMemJobLength
)
{
  boolean isJobFinished;
  vMemAccM_JobResultType memAbJobResult = VMEMACCM_JOB_PENDING;
  
  while(memAbJobResult == VMEMACCM_JOB_PENDING)
  {
    memAbJobResult = vMemAccM_MemAbProcessing(SubAddressAreaId);
  }

  if((memAbJobResult == VMEMACCM_JOB_OK) || (memAbJobResult == VMEMACCM_READ_CORRECTED_ERRORS))
  {
    /* Allow only to overwrite the internal result in case it is JOB_OK -> READ_CORRECTED_ERRORS must not be overwritten */
    if(vMemAccM_MngmtAreas[AddressAreaId].InternalJobResult == VMEMACCM_JOB_OK)
    {
      vMemAccM_MngmtAreas[AddressAreaId].InternalJobResult = memAbJobResult; /* SBSW_vMemAccM_MngmtAreas */
    }

    vMemAccM_MngmtAreas[AddressAreaId].Offset += vMemJobLength; /* SBSW_vMemAccM_MngmtAreas */

    /* Job not completely processed. Next job step processing is needed. */ 
    if(vMemAccM_MngmtAreas[AddressAreaId].Offset < JobLength)
    {
      isJobFinished = FALSE;
    }   
    /* Complete job was successfully processed */
    else if(vMemAccM_MngmtAreas[AddressAreaId].Offset == JobLength)
    {
      vMemAccM_MngmtAreas[AddressAreaId].JobResult = vMemAccM_MngmtAreas[AddressAreaId].InternalJobResult; /* SBSW_vMemAccM_MngmtAreas */
      isJobFinished = TRUE;
    }
    /* Offset > JobLength: Internal error scenario, shall never happen */
    else
    {
      vMemAccM_MngmtAreas[AddressAreaId].JobResult = VMEMACCM_JOB_FAILED; /* SBSW_vMemAccM_MngmtAreas */
      isJobFinished = TRUE;
    }
  }
  else 
  {
    vMemAccM_MngmtAreas[AddressAreaId].JobResult = memAbJobResult; /* SBSW_vMemAccM_MngmtAreas */
    isJobFinished = TRUE;
  }

  return isJobFinished;
}

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  vMemAccM_SchedInit
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, VMEMACCM_CODE) vMemAccM_SchedInit(void)
{
  vMemAccM_QueueIndexType i = 0u;
  for(i = 0; i < VMEMACCM_MNGMTAREA_SIZE; i++)
  {
    vMemAccM_MngmtAreas[i].Offset = 0u;  /* SBSW_vMemAccM_MngmtAreas */
    vMemAccM_MngmtAreas[i].JobResult = VMEMACCM_JOB_OK;  /* SBSW_vMemAccM_MngmtAreas */
    vMemAccM_MngmtAreas[i].InternalJobResult = VMEMACCM_JOB_OK; /* SBSW_vMemAccM_MngmtAreas */
    /* All the not listed members will not be used within synchronous processing */
  }
}


/**********************************************************************************************************************
 *  vMemAccM_SchedQueueJob
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
FUNC(Std_ReturnType, VMEMACCM_CODE) vMemAccM_SchedQueueJob
(
  vMemAccM_JobType JobType,
  vMemAccM_AddressAreaIdType AddressAreaId,
  vMemAccM_AddressType Address,
  vMemAccM_DataPtrType DataPtr,
  vMemAccM_LengthType Length
)
{
  boolean isJobFinished = FALSE;

  vMemAccM_MngmtAreas[AddressAreaId].JobResult = VMEMACCM_JOB_PENDING; /* SBSW_vMemAccM_MngmtAreas */
  /* Reset processing relevant management area members */
  vMemAccM_MngmtAreas[AddressAreaId].InternalJobResult = VMEMACCM_JOB_OK; /* SBSW_vMemAccM_MngmtAreas */
  vMemAccM_MngmtAreas[AddressAreaId].Offset = 0u; /* SBSW_vMemAccM_MngmtAreas */

  while (isJobFinished == FALSE)
  {
    vMemAccM_AddressAreaIdType currentSubAddressAreaId;
    vMemAccM_SubAddrAreaJobParamsType jobParams;
    vMemAccM_LengthType vMemJobLength = 0u;

    /* --- JOB STEP PREPERATION --- */
    currentSubAddressAreaId = vMemAccM_CfgAbGetSubAddrAreaId(AddressAreaId,
                                                             Address + vMemAccM_MngmtAreas[AddressAreaId].Offset);
    vMemAccM_SMLibCalcJobParams(&jobParams, /* SBSW_vMemAccM_JobParamsFuncCall */
                                currentSubAddressAreaId,
                                Address,
                                Length,
                                vMemAccM_MngmtAreas[AddressAreaId].Offset);
    
    if((JobType == VMEMACCM_READJOB) || (JobType == VMEMACCM_WRITEJOB))
    {
      vMemAccM_SMLibCalcJobPointer(&jobParams, /* SBSW_vMemAccM_JobParamsFuncCall */
                                   DataPtr,
                                   vMemAccM_MngmtAreas[AddressAreaId].Offset);
    }

    /* --- JOB STEP FORWARDING --- */
    switch(JobType)
    {
      case VMEMACCM_READJOB:
        vMemAccM_MemAbRead(currentSubAddressAreaId, /* SBSW_vMemAccM_SMContextPtr */
                           jobParams.Offset,
                           jobParams.DataPtr,
                           jobParams.Length,
                           &vMemJobLength,
                           jobParams.Length);
        break;

      case VMEMACCM_WRITEJOB:
        vMemAccM_MemAbWrite(currentSubAddressAreaId, /* SBSW_vMemAccM_PointerPassedToMemAb */
                            jobParams.Offset,
                            jobParams.DataPtr,
                            jobParams.Length,
                            &vMemJobLength);
        break;

      case VMEMACCM_ERASEJOB:
        vMemAccM_MemAbErase(currentSubAddressAreaId, /* SBSW_vMemAccM_PointerPassedToMemAb */
                            jobParams.Offset,
                            jobParams.Length,
                            &vMemJobLength);
        break;

      case VMEMACCM_ISBLANKJOB:
        vMemAccM_MemAbIsBlank(currentSubAddressAreaId, /* SBSW_vMemAccM_PointerPassedToMemAb */
                              jobParams.Offset,
                              jobParams.Length,
                              &vMemJobLength);
        break;

      default:
        vMemAccM_MngmtAreas[AddressAreaId].JobResult = VMEMACCM_JOB_FAILED; /* SBSW_vMemAccM_MngmtAreas */
        break;
    }

    /* --- JOB STEP PROCESSING --- */
    /* Job was accepted */
    if(vMemJobLength != 0u)
    {
      /* If job is finished, public job result will be updated directly within the function */
      isJobFinished = vMemAccM_SchedSyncProcessJob(AddressAreaId,
                                                   currentSubAddressAreaId,
                                                   Length,
                                                   vMemJobLength);
    }
    /* Job was rejected by underlying vMem driver */
    else
    {
      vMemAccM_MngmtAreas[AddressAreaId].JobResult = VMEMACCM_JOB_FAILED; /* SBSW_vMemAccM_MngmtAreas */
      isJobFinished = TRUE;
    }
  }

  return E_OK;
} /* PRQA S 6050 */ /* MD_MSR_STCAL */


/**********************************************************************************************************************
 *  vMemAccM_SchedMainFunction
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, VMEMACCM_CODE) vMemAccM_SchedMainFunction(void)
{
}


#if (VMEMACCM_DEV_ERROR_DETECT == STD_ON)
/**********************************************************************************************************************
 *  vMemAccM_SchedIsInitialized
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(boolean, VMEMACCM_CODE) vMemAccM_SchedIsInitialized(void)
{
  return (vMemAccM_ModuleInitialized == VMEMACCM_INIT);
}

/**********************************************************************************************************************
 *  vMemAccM_SchedSetInitState
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, VMEMACCM_CODE) vMemAccM_SchedSetInitState
(
  uint8 InitState
)
{
  vMemAccM_ModuleInitialized = InitState;
}


/**********************************************************************************************************************
 *  vMemAccM_SchedIsAddressAreaPending
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(boolean, VMEMACCM_CODE) vMemAccM_SchedIsAddressAreaPending
(
  vMemAccM_AddressAreaIdType AddressAreaId
)
{
  return (vMemAccM_MngmtAreas[AddressAreaId].JobResult == VMEMACCM_JOB_PENDING);
}
#endif


#define VMEMACCM_STOP_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

# endif /* (VMEMACCM_MINIMAL_SYNC == STD_ON) */

/**********************************************************************************************************************
 *  END OF FILE: vMemAccM_SchedSync.c
 *********************************************************************************************************************/
