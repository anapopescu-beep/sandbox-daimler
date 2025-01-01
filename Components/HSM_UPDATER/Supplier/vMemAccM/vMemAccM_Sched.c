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
/*!        \file  vMemAccM_Sched.c
 *        \brief  vMemAccM job scheduler sub module source file.
 *
 *      \details  See vMemAccM_Sched.h.
 *
 *********************************************************************************************************************/

#define VMEMACCM_SCHED_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "vMemAccM_Types.h"
#include "vMemAccM_IntCfg.h"
#include "vMemAccM_Cfg.h"
#include "vMemAccM_StateMachines.h"
#include "vMemAccM_Sched.h"
#include "vMemAccM_CfgAb.h"
#include "SchM_vMemAccM.h"

/**********************************************************************************************************************
 *  LOCAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

#if !defined (VMEMACCM_LOCAL) /* COV_VMEMACCM_COMPATIBILITY */
# define VMEMACCM_LOCAL static
#endif

#if !defined (VMEMACCM_LOCAL_INLINE) /* COV_VMEMACCM_COMPATIBILITY */
# define VMEMACCM_LOCAL_INLINE LOCAL_INLINE
#endif

/*! Size of the queue/ number of elements, end of the iteration. */
#define VMEMACCM_QUEUE_SIZE (vMemAccM_GetSizeOfAddressArea())
/*! Queue empty, nothing to do, next queue job will update this value. */
#define VMEMACCM_QUEUE_EMPTY (VMEMACCM_QUEUE_SIZE)
/*! Each time a job finished it has to be checked whether there any other queued job. */
#define VMEMACCM_QUEUE_NEXTJOB_UNDEFINED (VMEMACCM_QUEUE_SIZE + 1u)

/**********************************************************************************************************************
 *  LOCAL DATA PROTOTYPES
 *********************************************************************************************************************/
#define VMEMACCM_START_SEC_VAR_NOINIT_32BIT
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! Index to the queue array, if the job with highest priority is known; to empty queue identifier, if there is
 * no job; or to unknown queue state, where the queue sub module has to check the queue content.
 * Use volatile: at least with vMemAccM_QueueGetNextJob the compiler must not replace the access to global variable
 * with a local copy (if(vMemAccM_QueueNextJobIndex < VMEMACCM_QUEUE_EMPTY)) but get the actual current value. */
VMEMACCM_LOCAL volatile vMemAccM_QueueIndexType vMemAccM_QueueNextJobIndex;

#define VMEMACCM_STOP_SEC_VAR_NOINIT_32BIT
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define VMEMACCM_START_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! Queue array - one element per address area */
VMEMACCM_LOCAL VAR(vMemAccM_SchedJobType, VMEMACCM_VAR_NOINIT) vMemAccM_Queue[VMEMACCM_QUEUE_SIZE];

/*! Holds the information about current processing status. */
VMEMACCM_LOCAL VAR(vMemAccM_SchedStateContextType, VMEMACCM_VAR_NOINIT) vMemAccM_SchedState;

/*! Holds runtime information about each address area. */
VAR(vMemAccM_MngmtAreaType, VMEMACCM_VAR_NOINIT) vMemAccM_MngmtAreas[VMEMACCM_MNGMTAREA_SIZE];

#define VMEMACCM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define VMEMACCM_START_SEC_VAR_INIT_32BIT
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define VMEMACCM_STOP_SEC_VAR_INIT_32BIT
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

#define VMEMACCM_START_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  vMemAccM_SchedQueueAddrAreaIdToIndex
 *********************************************************************************************************************/
/*!
 * \brief       Returns the queue index of the passed address area.
 * \details     Queue index == address area priority.
 * \param[in]   AddressAreaId as array index, used to access the virtual information.
 * \return      Returns the queue index of the passed address area.
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */
VMEMACCM_LOCAL_INLINE FUNC(vMemAccM_QueueIndexType, VMEMACCM_CODE) vMemAccM_SchedQueueAddrAreaIdToIndex
(
  vMemAccM_AddressAreaIdType AddressAreaId
);

/**********************************************************************************************************************
 *  vMemAccM_SchedSetupStateMachine
 *********************************************************************************************************************/
/*!
 * \brief       Sets up the state machine for the given job type.
 * \details     -
 * \param[in]   JobType Type of the job whose state machine shall be setup.
 * \param[in]   SMFuncs Pointer where the StateFuncPtr is stored and initialized.
 * \return      TRUE: Setup was successful
 *              FALSE: Setup was not successful => Can only happen if the job type is out of range or NO_JOB
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */
VMEMACCM_LOCAL_INLINE FUNC(boolean, VMEMACCM_CODE) vMemAccM_SchedSetupStateMachine
(
    vMemAccM_JobType JobType, vMemAccM_SMFunctionsPtrType SMFuncs
);

/**********************************************************************************************************************
 *  vMemAccM_SchedQueueJobInternal
 *********************************************************************************************************************/
/*!
 * \brief       Queues a new job with passed parameters.
 * \details     -
 * \param[in]   JobType identifying the job as read, write, erase, compare or hardware specific job.
 * \param[in]   AddressAreaId as array index, used to access the virtual information.
 * \param[in]   Address pointing to the first byte of the request, or in case of a hardware specific job: pointing to
 *              the hardware driver the job shall be forwarded to.
 * \param[in]   DataPtr pointing to the job buffer. Parameter must not be NULL_PTR.
 * \param[in]   Length of the data.
 * \param[in]   vMemHwSpecificFuncIndex as an array index pointing to the hardware specific function pointer.
 * \return      E_OK job was queued;
 *              E_NOT_OK otherwise
 * \pre         -
 * \context     ANY
 * \reentrant   FALSE
 * \synchronous TRUE
 */
VMEMACCM_LOCAL_INLINE FUNC(Std_ReturnType, VMEMACCM_CODE) vMemAccM_SchedQueueJobInternal
(
  vMemAccM_JobType JobType,
  vMemAccM_AddressAreaIdType AddressAreaId,
  vMemAccM_AddressType Address,
  vMemAccM_DataPtrType DataPtr,
  vMemAccM_LengthType Length,
  vMemAccM_vMemHwSpecificFuncIndexType vMemHwSpecificFuncIndex
);

/**********************************************************************************************************************
 *  vMemAccM_SchedQueueGetNextJob
 *********************************************************************************************************************/
/*!
 * \brief       Returns the index of the next job.
 * \details     -
 * \return      VMEMACCM_QUEUE_EMPTY: queue is empty.
 *              Index < VMEMACCM_QUEUE_EMPTY: index points to a valid queue entry.
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */
VMEMACCM_LOCAL_INLINE FUNC(vMemAccM_QueueIndexType, VMEMACCM_CODE) vMemAccM_SchedQueueGetNextJob(void);

/**********************************************************************************************************************
 *  State machine
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  vMemAccM_SchedStateSchedEnter
 *********************************************************************************************************************/
/*!
 * \brief       Enter function of the scheduling state.
 * \details     -
 * \param[in]   ContextPtr pointing to the current state machine context. Pointer must be valid.
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */
FUNC(void, VMEMACCM_CODE) vMemAccM_SchedStateSchedEnter(vMemAccM_SchedStateContextPtrType ContextPtr);

/**********************************************************************************************************************
 *  vMemAccM_SchedStateSchedDo
 *********************************************************************************************************************/
/*!
 * \brief       Do function of the scheduling state.
 * \details     -
 * \param[in]   ContextPtr pointing to the current state machine context. Pointer must be valid.
 * \return      TRUE: exit MainFunction.
 *              FALSE: Invoke the state function again.
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */
FUNC(boolean, VMEMACCM_CODE) vMemAccM_SchedStateSchedDo(vMemAccM_SchedStateContextPtrType ContextPtr);

/**********************************************************************************************************************
 *  vMemAccM_SchedStateTransitionToSched
 *********************************************************************************************************************/
/*!
 * \brief       Transition function from processing to the scheduling state.
 * \details     The function invokes the processing exit and the scheduling enter functions.
 *              In between the function sets the state pointer to the next state do function.
 * \param[in]   ContextPtr pointing to the current state machine context. Pointer must be valid.
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */
FUNC(void, VMEMACCM_CODE) vMemAccM_SchedStateTransitionToSched(vMemAccM_SchedStateContextPtrType ContextPtr);

/**********************************************************************************************************************
 *  vMemAccM_SchedStateProcEnter
 *********************************************************************************************************************/
/*!
 * \brief       Enter function of the processing state.
 * \details     -
 * \param[in]   ContextPtr pointing to the current state machine context. Pointer must be valid.
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */
FUNC(void, VMEMACCM_CODE) vMemAccM_SchedStateProcEnter(vMemAccM_SchedStateContextPtrType ContextPtr);

/**********************************************************************************************************************
 *  vMemAccM_SchedStateProcDo
 *********************************************************************************************************************/
/*!
 * \brief       Do function of the processing state.
 * \details     -
 * \param[in]   ContextPtr pointing to the current state machine context. Pointer must be valid.
 * \return      TRUE: exit MainFunction.
 *              FALSE: Invoke the state function again.
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */
FUNC(boolean, VMEMACCM_CODE) vMemAccM_SchedStateProcDo(vMemAccM_SchedStateContextPtrType ContextPtr);

/**********************************************************************************************************************
 *  vMemAccM_SchedStateProcExit
 *********************************************************************************************************************/
/*!
 * \brief       Exit function of the processing state.
 * \details     -
 * \param[in]   ContextPtr pointing to the current state machine context. Pointer must be valid.
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */
FUNC(void, VMEMACCM_CODE) vMemAccM_SchedStateProcExit(vMemAccM_SchedStateContextPtrToConstType ContextPtr);

/**********************************************************************************************************************
 *  vMemAccM_SchedStateTransitionToProc
 *********************************************************************************************************************/
/*!
 * \brief       Transition function from scheduling to processing state.
 * \details     The function invokes the scheduling exit (if there is any) and the processing enter functions.
 *              In between the function sets the state pointer to the next state do function.
 * \param[in]   ContextPtr pointing to the current state machine context. Pointer must be valid.
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */
FUNC(void, VMEMACCM_CODE) vMemAccM_SchedStateTransitionToProc(vMemAccM_SchedStateContextPtrType ContextPtr);

#if ((VMEMACCM_PARTITION_USECASE == VMEMACCM_MULTI_PARTITION_MULTI_ACCESSORS) || \
     (VMEMACCM_PARTITION_USECASE == VMEMACCM_MULTI_PARTITION_SINGLE_ACCESSOR))

# if (VMEMACCM_MULTIPARTITION_PARTITION_ID == VMEMACCM_MULTIPARTITION_MASTER_PARTITION_ID)

/**********************************************************************************************************************
 *  vMemAccM_SchedMpSynchronizeToken
 *********************************************************************************************************************/
/*!
 * \brief       Synchronizes the multi partition token with all users.
 * \details     The function is responsible for setting the multi partition token to the partition with the highest 
                priority.
 * \pre         Multi partition master.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */
FUNC(void, VMEMACCM_CODE) vMemAccM_SchedMpSynchronizeToken(void);

/**********************************************************************************************************************
 *  vMemAccM_SchedMpGetNextPartitionIndex
 *********************************************************************************************************************/
/*!
 * \brief       Returns the highest priority jobs out of all partitions.
 * \details     -
 * \return      Index == VMEMACCM_MULTIPARTITION_NR_OF_PARTITIONS: No job has been found
 *              Index < VMEMACCM_MULTIPARTITION_NR_OF_PARTITIONS: Job has been found
 * \pre         Multi partition master.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */
VMEMACCM_LOCAL_INLINE FUNC(vMemAccM_MultiPartitionPartitionIdType, VMEMACCM_CODE) vMemAccM_SchedMpGetNextPartitionIndex(void);

# endif /* (VMEMACCM_MULTIPARTITION_PARTITION_ID == VMEMACCM_MULTIPARTITION_MASTER_PARTITION_ID) */

/**********************************************************************************************************************
 *  vMemAccM_SchedMpUpdatePublishedRequest
 *********************************************************************************************************************/
/*!
 * \brief       Publishes the highest priority job or no job if the partition's queue is empty.
 * \details     -
 * \pre         Multi partition use case.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */
VMEMACCM_LOCAL_INLINE FUNC(void, VMEMACCM_CODE) vMemAccM_SchedMpUpdatePublishedRequest(void);

/**********************************************************************************************************************
 *  vMemAccM_SchedMpPublishRequestPriority
 *********************************************************************************************************************/
/*!
 * \brief       Sets the publish request priority to the provided priority value.
 * \details     -
 * \param[in]   Priority to be published.
 * \pre         Multi partition use case.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */
VMEMACCM_LOCAL_INLINE FUNC(void, VMEMACCM_CODE) vMemAccM_SchedMpPublishRequestPriority(
    vMemAccM_PublishPriorityType Priority
);

/**********************************************************************************************************************
 *  vMemAccm_SchedMpPartitionDo
 *********************************************************************************************************************/
/*!
 * \brief       Processes jobs if the token's value matches the current partition id.
 * \details     The function determines whether the partition may process a job and if it is allowed to do so it will 
                setup a job.
 * \pre         Multi partition use case.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */
FUNC(boolean, VMEMACCM_CODE) vMemAccm_SchedMpPartitionDo(vMemAccM_SchedStateContextPtrType ContextPtr);

#endif /* ((VMEMACCM_PARTITION_USECASE == VMEMACCM_MULTI_PARTITION_MULTI_ACCESSORS) || \
           (VMEMACCM_PARTITION_USECASE == VMEMACCM_MULTI_PARTITION_SINGLE_ACCESSOR)) */

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  vMemAccM_SchedQueueAddrAreaIdToIndex
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
VMEMACCM_LOCAL_INLINE FUNC(vMemAccM_QueueIndexType, VMEMACCM_CODE) vMemAccM_SchedQueueAddrAreaIdToIndex
(
  vMemAccM_AddressAreaIdType AddressAreaId
)
{
  return (vMemAccM_QueueIndexType)vMemAccM_GetPriorityOfAddressArea(AddressAreaId);
}

/**********************************************************************************************************************
 *  vMemAccM_SchedQueueAddrAreaIdToIndex
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
VMEMACCM_LOCAL_INLINE FUNC(boolean, VMEMACCM_CODE) vMemAccM_SchedSetupStateMachine(vMemAccM_JobType JobType, vMemAccM_SMFunctionsPtrType SMFuncs)
{
    boolean setupSuccessful = TRUE;
    switch(JobType)
    {
      case VMEMACCM_WRITEJOB:
        vMemAccM_SMWriteInit(SMFuncs); /* SBSW_vMemAccM_SMFuncPtr */
        break;
      case VMEMACCM_READJOB:
        vMemAccM_SMReadInit(SMFuncs); /* SBSW_vMemAccM_SMFuncPtr */
        break;
      case VMEMACCM_READBLANKJOB:
        vMemAccM_SMReadBlankInit(SMFuncs); /* SBSW_vMemAccM_SMFuncPtr */
        break;
      case VMEMACCM_ERASEJOB:
        vMemAccM_SMEraseInit(SMFuncs); /* SBSW_vMemAccM_SMFuncPtr */
        break;
#if (VMEMACCM_COMPARE_API == STD_ON)
      case VMEMACCM_COMPAREJOB:
        vMemAccM_SMCompareInit(SMFuncs); /* SBSW_vMemAccM_SMFuncPtr */
        break;
#endif /* (VMEMACCM_COMPARE_API == STD_ON) */
      case VMEMACCM_ISBLANKJOB:
        vMemAccM_SMIsBlankInit(SMFuncs); /* SBSW_vMemAccM_SMFuncPtr */
        break;
#if (VMEMACCM_MULTI_PARTITION_SATELLITE == STD_OFF)
      case VMEMACCM_VMEMJOB:
        vMemAccM_SMHwSpecificInit(SMFuncs); /* SBSW_vMemAccM_SMFuncPtr */
        break;
#endif /* (VMEMACCM_MULTI_PARTITION_SATELLITE == STD_ON) */
      default:
        /* Shall NEVER be reached => invalid input! */
        setupSuccessful = FALSE;
        break;
    }
    return setupSuccessful;
}

/**********************************************************************************************************************
 *  vMemAccM_SchedQueueJobInternal
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
VMEMACCM_LOCAL_INLINE FUNC(Std_ReturnType, VMEMACCM_CODE) vMemAccM_SchedQueueJobInternal
(
  vMemAccM_JobType JobType,
  vMemAccM_AddressAreaIdType AddressAreaId,
  vMemAccM_AddressType Address,
  vMemAccM_DataPtrType DataPtr,
  vMemAccM_LengthType Length,
  vMemAccM_vMemHwSpecificFuncIndexType vMemHwSpecificFuncIndex
)
{
  Std_ReturnType retVal = E_NOT_OK;
  /* #100 Critical section (Reason: protect vMemAccM queue update against interruption). */
  SchM_Enter_vMemAccM_VMEMACCM_EXCLUSIVE_AREA_0();
  /* #110 Queue the job only in case the AddressAreaId is not pending. This check is additional to the API parameter
   * checks and shall ensure that an interruption between API and the actual queuing does not lead to an overwrite
   * within the queue. */
  if(vMemAccM_MngmtAreas[AddressAreaId].JobResult != VMEMACCM_JOB_PENDING)
  {
    boolean setupSuccessful;
    /* #111 Copy the job parameters to the related queue element. */
    vMemAccM_QueueIndexType queueIndex = vMemAccM_SchedQueueAddrAreaIdToIndex(AddressAreaId);

    vMemAccM_Queue[queueIndex].JobType = JobType; /* PRQA S 2842 */ /* MD_vMemAccM_DereferenceOfInvalidPointerValue */ /* SBSW_vMemAccM_Queue */
    vMemAccM_Queue[queueIndex].AddressAreaId = AddressAreaId; /* PRQA S 2842 */ /* MD_vMemAccM_DereferenceOfInvalidPointerValue */ /* SBSW_vMemAccM_Queue */
    vMemAccM_Queue[queueIndex].Address = Address; /* PRQA S 2842 */ /* MD_vMemAccM_DereferenceOfInvalidPointerValue */ /* SBSW_vMemAccM_Queue */
    vMemAccM_Queue[queueIndex].DataPtr = DataPtr; /* PRQA S 2842 */ /* MD_vMemAccM_DereferenceOfInvalidPointerValue */ /* SBSW_vMemAccM_Queue */
    vMemAccM_Queue[queueIndex].Length = Length; /* PRQA S 2842 */ /* MD_vMemAccM_DereferenceOfInvalidPointerValue */ /* SBSW_vMemAccM_Queue */
    vMemAccM_Queue[queueIndex].vMemHwSpecificFuncIndex = vMemHwSpecificFuncIndex; /* PRQA S 2842 */ /* MD_vMemAccM_DereferenceOfInvalidPointerValue */ /* SBSW_vMemAccM_Queue */
    
    /* #112 Set up the state machine. */
    setupSuccessful = vMemAccM_SchedSetupStateMachine(JobType, &vMemAccM_Queue[queueIndex].SMFuncs); /* SBSW_vMemAccM_SMFuncPtr */

    /* #113 Update the QueueNextJobIndex -> points to the next job, this may be the new one, if it has the
     * highest priority within the queue! */
    if((vMemAccM_QueueNextJobIndex == VMEMACCM_QUEUE_EMPTY) || (vMemAccM_QueueNextJobIndex < queueIndex)) /* PRQA S 3415 */ /* MD_vMemAccM_UpdateQueueNextJobIndex_SideEffects */
    {
      vMemAccM_QueueNextJobIndex = queueIndex;
    }
    if(setupSuccessful == TRUE)
    {
      /* #114 Set up the AddressArea state (management area). */
      vMemAccM_MngmtAreas[AddressAreaId].JobResult = VMEMACCM_JOB_PENDING; /* SBSW_vMemAccM_MngmtAreas */
      vMemAccM_MngmtAreas[AddressAreaId].InternalJobResult = VMEMACCM_JOB_OK; /* SBSW_vMemAccM_MngmtAreas */
      vMemAccM_MngmtAreas[AddressAreaId].Offset = 0u; /* SBSW_vMemAccM_MngmtAreas */
      vMemAccM_MngmtAreas[AddressAreaId].NrOfStepRetries = 0u; /* SBSW_vMemAccM_MngmtAreas */
      vMemAccM_MngmtAreas[AddressAreaId].NrOfNormalSizeRetryRequests = 0u; /* SBSW_vMemAccM_MngmtAreas */
      /* Do not modify the ReadOnly flag - ReadOnly will be set and checked in vMemAccM main sub module, a ReadOnly
       * Address shall never reach this function with another job than read! */
      /* #115 Queuing successful, return E_OK. */
      retVal = E_OK;
    }
  }
  SchM_Exit_vMemAccM_VMEMACCM_EXCLUSIVE_AREA_0();

  return retVal;
} /* PRQA S 6050, 6060 */ /* MD_MSR_STCAL, MD_MSR_STPAR */

/**********************************************************************************************************************
 *  vMemAccM_SchedQueueGetNextJob
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
VMEMACCM_LOCAL_INLINE FUNC(vMemAccM_QueueIndexType, VMEMACCM_CODE) vMemAccM_SchedQueueGetNextJob(void)
{
  /* #100 Initialize next job with no job so we do not have to care about it later (e.g. because of empty queue). */
  vMemAccM_QueueIndexType queueIndex = VMEMACCM_QUEUE_EMPTY;
  /* #200 Queue is empty == nothing to do. Otherwise check the NextJobIndex. */
  if(vMemAccM_QueueNextJobIndex != VMEMACCM_QUEUE_EMPTY)
  {
    /* #210 Critical section (Reason: protect vMemAccM_QueueNextJobIndex update against interruption). */
    /* Note: critical section length is defined to be short - here it depends on QueueNextJobIndex,
     * on queue size (number of configured address areas), the highest priority job, etc.
     * Though this the normal critical section runtime shall be short. NextJobIndex will only
     * be UNDEFINED, if the cancel function was called -> searching for the next job needed. */
    SchM_Enter_vMemAccM_VMEMACCM_EXCLUSIVE_AREA_0();
    /* #220 NextJobIndex is undefined -> search for the next job (highest priority). */
    if(vMemAccM_QueueNextJobIndex == VMEMACCM_QUEUE_NEXTJOB_UNDEFINED)
    {
      /* #221 Search from highest priority to lowest priority -> always process jobs according to their priority. */
      vMemAccM_QueueIndexType i;
      vMemAccM_QueueNextJobIndex = VMEMACCM_QUEUE_EMPTY;
      /* Address area priority matches the queue index: higher priority will be processed first and is stored
       * at the highest queue index. Searching backwards ensures that the highest priority job will be found first
       * without comparing the priorities.
       * Since the queue index type is an unsigned, >= 0 cannot be used as a break condition (index is always > 0;
       * when decreased to 0, it will be first used, then decreased (wrap around) and then compared to be > 0 ->
       * infinite loop.
       * There is a nicer solution for(i=size; --i > 0;), but MISRA does not accept the decrease within the direct
       * usage. The used solution avoids MSIRA finding: use a second index, decrease the actual loop index and
       * use the > 0 break condition. */
      for(i = VMEMACCM_QUEUE_SIZE; i > 0u; i--)
      {
        vMemAccM_QueueIndexType tmpIndex = i - 1u;
        if(vMemAccM_Queue[tmpIndex].JobType != VMEMACCM_NO_JOB)
        {
          vMemAccM_QueueNextJobIndex = tmpIndex;
          break;
        }
      }
    }
    /* #230 NextJobIndex points to any job within the queue -> copy the job parameter to the passed structure.
     * Otherwise nothing to do, no job available. */
    if(vMemAccM_QueueNextJobIndex < VMEMACCM_QUEUE_EMPTY)
    {
      queueIndex = vMemAccM_QueueNextJobIndex;
    }
    SchM_Exit_vMemAccM_VMEMACCM_EXCLUSIVE_AREA_0();
  }

  return queueIndex;
}

/**********************************************************************************************************************
 *  State machine
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  State: Scheduling
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  vMemAccM_SchedStateSchedEnter
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, VMEMACCM_CODE) vMemAccM_SchedStateSchedEnter(vMemAccM_SchedStateContextPtrType ContextPtr)
{
  vMemAccM_SMDefaultInit(&ContextPtr->SubSMContext.Job.SMFuncs); /* SBSW_vMemAccM_SMFuncPtr */
  ContextPtr->CurrentQueueIndex = VMEMACCM_QUEUE_EMPTY; /* SBSW_vMemAccM_SchedContextPtr */
#if (VMEMACCM_MULTI_PARTITION_SINGLE_ACCESSOR_MASTER == STD_ON)
  ContextPtr->PartitionIndex = VMEMACCM_MULTIPARTITION_SYNC_TOKEN; /* SBSW_vMemAccM_SchedContextPtr */
#endif
  /* JobType and DataPtr shall be reset because the JobType is queried in state idle to check whether there is a new job
   * available. The other parameters of CurrentJob and CurrentJob.QueueJob are then all initialized in state idle, if there is
   * a job to process (JobType != NO_JOB). Therefore, they do not need to be initialized during init phase.*/
  ContextPtr->SubSMContext.Job.JobType = VMEMACCM_NO_JOB; /* SBSW_vMemAccM_SchedContextPtr */
  ContextPtr->SubSMContext.Job.DataPtr = NULL_PTR; /* SBSW_vMemAccM_SchedContextPtr */
  ContextPtr->SubSMContext.MgmtArea = NULL_PTR; /* SBSW_vMemAccM_SchedContextPtr */
}

#if (VMEMACCM_PARTITION_USECASE == VMEMACCM_SINGLE_PARTITION)
/**********************************************************************************************************************
 *  Single partition functions
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  vMemAccM_SchedStateSchedDo
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
FUNC(boolean, VMEMACCM_CODE) vMemAccM_SchedStateSchedDo(vMemAccM_SchedStateContextPtrType ContextPtr)
{
  boolean exitMainFunction = TRUE;
  /* #10 Check queue for the next job. */
  vMemAccM_QueueIndexType nextQueueIndex = vMemAccM_SchedQueueGetNextJob();
  if(nextQueueIndex < VMEMACCM_QUEUE_EMPTY)
  {
    /* #11 Job found -> transition to processing state (setting up the job). */
    ContextPtr->CurrentQueueIndex = nextQueueIndex; /* SBSW_vMemAccM_SchedContextPtr */
    vMemAccM_SchedStateTransitionToProc(ContextPtr); /* SBSW_vMemAccM_SchedContextPtr */
    /* #12 Stay in MainFunction, let the processing state setup the job. */
    exitMainFunction = FALSE;
  }
  /* #20 No job available: return from MainFunction, nothing to do. */
  return exitMainFunction;
}
#endif /* (VMEMACCM_PARTITION_USECASE == VMEMACCM_SINGLE_PARTITION) */

#if ((VMEMACCM_PARTITION_USECASE == VMEMACCM_MULTI_PARTITION_MULTI_ACCESSORS) || (VMEMACCM_PARTITION_USECASE == VMEMACCM_MULTI_PARTITION_SINGLE_ACCESSOR))
/**********************************************************************************************************************
 *  Multi partition shared functions
 *********************************************************************************************************************/
# if (VMEMACCM_PARTITION_USECASE == VMEMACCM_MULTI_PARTITION_SINGLE_ACCESSOR)
/**********************************************************************************************************************
 *  vMemAccM_SchedMpUpdatePublishedRequest
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
VMEMACCM_LOCAL_INLINE FUNC(void, VMEMACCM_CODE) vMemAccM_SchedMpUpdatePublishedRequest( void )
{
  /* #10 Get the next job in the queue */
  vMemAccM_QueueIndexType nextQueueIndex = vMemAccM_SchedQueueGetNextJob();
  /* #20 If a job was found publish it */
  if(nextQueueIndex < VMEMACCM_QUEUE_EMPTY)
  {
    vMemAccM_SchedMpPublishRequestPriority(nextQueueIndex);
  }
  /* #30 If no job was found reset the published job */
  else
  {
    vMemAccM_SchedMpPublishRequestPriority(VMEMACCM_MULTIPARTITION_PUBLISH_NOREQUEST);
  }
}
# endif /* (VMEMACCM_PARTITION_USECASE == VMEMACCM_MULTI_PARTITION_SINGLE_ACCESSOR) */

# if ( VMEMACCM_MULTIPARTITION_PARTITION_ID == VMEMACCM_MULTIPARTITION_MASTER_PARTITION_ID ) && \
     ( VMEMACCM_PARTITION_USECASE == VMEMACCM_MULTI_PARTITION_MULTI_ACCESSORS )
/**********************************************************************************************************************
 *  vMemAccM_SchedMpUpdatePublishedRequest
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
VMEMACCM_LOCAL_INLINE FUNC(void, VMEMACCM_CODE) vMemAccM_SchedMpUpdatePublishedRequest( void )
{
  /* #10 Get the next job in the queue */
  vMemAccM_QueueIndexType nextQueueIndex = vMemAccM_SchedQueueGetNextJob();
  /* #20 If a job was found publish it */
  if(nextQueueIndex < VMEMACCM_QUEUE_EMPTY)
  {
    vMemAccM_SchedMpPublishRequestPriority(nextQueueIndex);
  }
  /* #30 If no job was found reset the published job */
  else
  {
    vMemAccM_SchedMpPublishRequestPriority(VMEMACCM_MULTIPARTITION_PUBLISH_NOREQUEST);
  }
}
# endif /* ( VMEMACCM_MULTIPARTITION_PARTITION_ID == VMEMACCM_MULTIPARTITION_MASTER_PARTITION_ID ) && \
           ( VMEMACCM_PARTITION_USECASE == VMEMACCM_MULTI_PARTITION_MULTI_ACCESSORS ) */

/**********************************************************************************************************************
 *  vMemAccM_SchedStateSchedDo
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(boolean, VMEMACCM_CODE) vMemAccM_SchedStateSchedDo(vMemAccM_SchedStateContextPtrType ContextPtr)
{
# if (VMEMACCM_PARTITION_USECASE == VMEMACCM_MULTI_PARTITION_SINGLE_ACCESSOR) || ( VMEMACCM_MULTIPARTITION_PARTITION_ID == VMEMACCM_MULTIPARTITION_MASTER_PARTITION_ID )
  /* #100 If this is the master partition or single accessor use case: Update the request */
  vMemAccM_SchedMpUpdatePublishedRequest();
# endif
# if (VMEMACCM_MULTIPARTITION_PARTITION_ID == VMEMACCM_MULTIPARTITION_MASTER_PARTITION_ID)
 /* #200 If this is the master partition: Synchronize the token */
  vMemAccM_SchedMpSynchronizeToken();
# endif
  /* #300 Do the job handling */
  return vMemAccm_SchedMpPartitionDo(ContextPtr); /* SBSW_vMemAccM_SchedContextPtr */
}
#endif /* ((VMEMACCM_PARTITION_USECASE == VMEMACCM_MULTI_PARTITION_MULTI_ACCESSORS) || (VMEMACCM_PARTITION_USECASE == VMEMACCM_MULTI_PARTITION_SINGLE_ACCESSOR)) */

#if (VMEMACCM_PARTITION_USECASE == VMEMACCM_MULTI_PARTITION_MULTI_ACCESSORS)
/**********************************************************************************************************************
 *  Multi partition multi NV RAM accessors use case
 *********************************************************************************************************************/
 
/**********************************************************************************************************************
 *  vMemAccm_SchedMpPartitionDo
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
FUNC(boolean, VMEMACCM_CODE) vMemAccm_SchedMpPartitionDo(vMemAccM_SchedStateContextPtrType ContextPtr)
{
  boolean exitMainFunction = TRUE;
  boolean partitionHasNvRamAccess = FALSE;
  /* #10 Search for the next job. */
  vMemAccM_QueueIndexType nextQueueIndex = vMemAccM_SchedQueueGetNextJob();
  vMemAccM_PublishPriorityType toBePublishedPriority = ((nextQueueIndex < VMEMACCM_QUEUE_EMPTY)
    ? nextQueueIndex : VMEMACCM_MULTIPARTITION_PUBLISH_NOREQUEST);

  vMemAccM_NVRAMAccessTokenType token = vMemAccM_CfgAbMpGetToken();
  vMemAccM_MultiPartitionPartitionIdType currentPartition = vMemAccM_CfgAbMpGetCurrentActivePartitionFromToken(token);
  vMemAccM_MultiPartitionPartitionIdType lastPartition = vMemAccM_CfgAbMpGetLastActivePartitionFromToken(token);

  /* #20 Resynchronization is signaled and this was the current partition -> Remove any published jobs */
  if( (currentPartition == VMEMACCM_MULTIPARTITION_RESYNC_TOKEN) && \
       (lastPartition == VMEMACCM_MULTIPARTITION_PARTITION_ID) )
  {
    vMemAccM_SchedMpPublishRequestPriority(VMEMACCM_MULTIPARTITION_PUBLISH_NOREQUEST);
  }
  /* #21 Otherwise publish the found job */
  else
  {
    vMemAccM_SchedMpPublishRequestPriority(toBePublishedPriority);
    partitionHasNvRamAccess = ((currentPartition == VMEMACCM_MULTIPARTITION_PARTITION_ID) && \
                               (toBePublishedPriority < VMEMACCM_MULTIPARTITION_PUBLISH_NOREQUEST));
  }

  /* #30 If partition may access the NVRAM -> Prepare the statemachine */
  if(partitionHasNvRamAccess)
  {
    ContextPtr->CurrentQueueIndex = nextQueueIndex; /* SBSW_vMemAccM_SchedContextPtr */
    vMemAccM_SchedStateTransitionToProc(ContextPtr); /* SBSW_vMemAccM_SchedContextPtr */
    exitMainFunction = FALSE;
  }

  return exitMainFunction;
}

# if (VMEMACCM_MULTIPARTITION_PARTITION_ID == VMEMACCM_MULTIPARTITION_MASTER_PARTITION_ID)
/**********************************************************************************************************************
 *  vMemAccM_SchedMpGetNextPartitionIndex
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
VMEMACCM_LOCAL_INLINE FUNC( vMemAccM_MultiPartitionPartitionIdType, VMEMACCM_CODE ) vMemAccM_SchedMpGetNextPartitionIndex( void )
{
  vMemAccM_MultiPartitionPartitionIdType partitionIndex  = VMEMACCM_MULTIPARTITION_NR_OF_PARTITIONS;
  vMemAccM_PublishPriorityType highestPriority = VMEMACCM_MULTIPARTITION_PUBLISH_NOREQUEST;
  vMemAccM_MultiPartitionPartitionIdType queueIndex;
  /* #100 Iterate over all configured partitions. */
  for ( queueIndex = 0; queueIndex < VMEMACCM_MULTIPARTITION_NR_OF_PARTITIONS; queueIndex++ )
  {
    /* Since the index starts at 0 and the condition to overwrite the job is only given when the next job is greater than the previous job,
    it is ensured the master will always be taken if the priority is equal */
    vMemAccM_PublishPriorityType currentPriority = vMemAccM_CfgAbGetMpTokenPriority((vMemAccM_NVRAMAccessTokenType)queueIndex);
    /* #110 If the currently checked partition has the highest priority of all checked partitions save the current request and index */
    if ( (currentPriority != VMEMACCM_MULTIPARTITION_PUBLISH_NOREQUEST) &&
         ( (currentPriority > highestPriority) || (highestPriority == VMEMACCM_MULTIPARTITION_PUBLISH_NOREQUEST) ) )
    {
      partitionIndex = queueIndex;
      highestPriority = currentPriority;
    }
  }
  return partitionIndex;
}

/**********************************************************************************************************************
 *  vMemAccM_SchedMpSynchronizeToken
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
FUNC(void, VMEMACCM_CODE) vMemAccM_SchedMpSynchronizeToken( void )
{
  vMemAccM_MultiPartitionPartitionIdType partitionIndex = vMemAccM_SchedMpGetNextPartitionIndex();

  /* #100 All partitions are idle -> token is SYNC, nothing to do. */
  if( partitionIndex == VMEMACCM_MULTIPARTITION_NR_OF_PARTITIONS )
  {
    vMemAccM_CfgAbMpSetToken(VMEMACCM_MULTIPARTITION_SYNC_TOKEN, VMEMACCM_MULTIPARTITION_SYNC_TOKEN);
  }
  /* #200 A request found -> update token. */
  else
  {
    vMemAccM_NVRAMAccessTokenType token = vMemAccM_CfgAbMpGetToken();
    vMemAccM_MultiPartitionPartitionIdType currentPartition = vMemAccM_CfgAbMpGetCurrentActivePartitionFromToken(token);
    vMemAccM_MultiPartitionPartitionIdType previousPartition = vMemAccM_CfgAbMpGetLastActivePartitionFromToken(token);

    /* #210 Token indicates a re-synchronization: check the last running partition synchronization status. */
    if( currentPartition == VMEMACCM_MULTIPARTITION_RESYNC_TOKEN )
    {
      
      if( vMemAccM_CfgAbGetMpTokenPriority(previousPartition) == VMEMACCM_MULTIPARTITION_PUBLISH_NOREQUEST )
      {
      /* #211 The last partition that was processing removed its published job: Set the token to the synchronized value */
        vMemAccM_CfgAbMpSetToken(VMEMACCM_MULTIPARTITION_SYNC_TOKEN, VMEMACCM_MULTIPARTITION_SYNC_TOKEN);
      }
      /* Else: Nothing */
    }
    /* #220 Token indicates a synchronized state: set the token to the partition identifier wanting to access the NV RAM. */
    else if( currentPartition == VMEMACCM_MULTIPARTITION_SYNC_TOKEN )
    {
      vMemAccM_CfgAbMpSetToken(partitionIndex, partitionIndex);
    }
    /* #230 Token and the found partition value mismatch: A new job with higher priority was found */
    else if( currentPartition != partitionIndex )
    {
      /* PartitionIndex points to the highest priority in system, but the token points to another partition.
       * The highest priority partition publishes a job, otherwise the GetNextPartitionIndex function would not return the index! */
      /* #231 Check current partition -> If idle, the new job can instantly be setup */
      if( vMemAccM_CfgAbGetMpTokenPriority(currentPartition) == VMEMACCM_MULTIPARTITION_PUBLISH_NOREQUEST )
      {
        vMemAccM_CfgAbMpSetToken(partitionIndex, partitionIndex);
      }
      /* #232 Otherwise indicate a RESYNC */
      else
      {
        vMemAccM_CfgAbMpSetToken(VMEMACCM_MULTIPARTITION_RESYNC_TOKEN, currentPartition);
      }
    }
    else
    {
      /* Nothing to do. Token is already set to the partition. */
    }
  }
} /* PRQA S 6080 */ /* MD_MSR_STMIF */
# endif /* (VMEMACCM_MULTIPARTITION_PARTITION_ID == VMEMACCM_MULTIPARTITION_MASTER_PARTITION_ID) */
#endif /* (VMEMACCM_PARTITION_USECASE == VMEMACCM_MULTI_PARTITION_MULTI_ACCESSORS) */

# if (VMEMACCM_PARTITION_USECASE != VMEMACCM_SINGLE_PARTITION)
/**********************************************************************************************************************
 *  vMemAccM_SchedMpPublishRequestPriority
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
VMEMACCM_LOCAL_INLINE FUNC(void, VMEMACCM_CODE) vMemAccM_SchedMpPublishRequestPriority(vMemAccM_PublishPriorityType Priority)
{
  vMemAccM_CfgAbSetPublishedPriority(Priority);
# if(VMEMACCM_MULTI_PARTITION_SINGLE_ACCESSOR_MASTER == STD_ON)
    vMemAccM_PartitionPublishRequestPtr->Result = (vMemAccM_PublishJobResultType)
      ((Priority == VMEMACCM_MULTIPARTITION_PUBLISH_NOREQUEST) ? VMEMACCM_JOB_OK : VMEMACCM_JOB_PENDING); /* SBSW_vMemAccM_MultiPartitionTokenAndPublishReqPtr */
# endif /* VMEMACCM_MULTI_PARTITION_SINGLE_ACCESSOR_MASTER == STD_ON */
}

# endif /* ((VMEMACCM_PARTITION_USECASE != VMEMACCM_SINGLE_PARTITION) */

/**********************************************************************************************************************
 *  Multi partition single NV RAM accessor use case
 *********************************************************************************************************************/

# if (VMEMACCM_MULTI_PARTITION_SINGLE_ACCESSOR_MASTER == STD_ON)
/**********************************************************************************************************************
 *  vMemAccm_SchedMpPartitionDo
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
FUNC(boolean, VMEMACCM_CODE) vMemAccm_SchedMpPartitionDo(vMemAccM_SchedStateContextPtrType ContextPtr)
{
  boolean exitMainFunction = TRUE;
  vMemAccM_NVRAMAccessTokenType token = vMemAccM_CfgAbMpGetToken();
  vMemAccM_MultiPartitionPartitionIdType partition = vMemAccM_CfgAbMpGetCurrentActivePartitionFromToken(token);

  if(partition < VMEMACCM_MULTIPARTITION_SYNC_TOKEN)
  {
    if(partition == VMEMACCM_MULTIPARTITION_MASTER_PARTITION_ID)
    {
      ContextPtr->CurrentQueueIndex = vMemAccM_SchedQueueGetNextJob(); /* SBSW_vMemAccM_SchedContextPtr */
    }
    else
    {
      ContextPtr->CurrentQueueIndex = VMEMACCM_QUEUE_EMPTY; /* SBSW_vMemAccM_SchedContextPtr */
    }
    
    ContextPtr->PartitionIndex = partition; /* SBSW_vMemAccM_SchedContextPtr */

    vMemAccM_SchedStateTransitionToProc(ContextPtr); /* SBSW_vMemAccM_SchedContextPtr */
    
    exitMainFunction = FALSE;
  }
  return exitMainFunction;
}

/**********************************************************************************************************************
 *  vMemAccM_SchedMpGetNextPartitionIndex
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
VMEMACCM_LOCAL_INLINE FUNC( vMemAccM_MultiPartitionPartitionIdType, VMEMACCM_CODE ) vMemAccM_SchedMpGetNextPartitionIndex( void )
{
  vMemAccM_MultiPartitionPartitionIdType partitionIndex  = VMEMACCM_MULTIPARTITION_NR_OF_PARTITIONS;
  vMemAccM_PublishPriorityType highestPriority = VMEMACCM_MULTIPARTITION_PUBLISH_NOREQUEST;
  vMemAccM_MultiPartitionPartitionIdType queueIndex;
  /* #100 Iterate over all configured partitions and search for the one with fully published job and highest priority. */
  for ( queueIndex = 0; queueIndex < VMEMACCM_MULTIPARTITION_NR_OF_PARTITIONS; queueIndex++ )
  {
      vMemAccM_PublishPriorityType currentPriority = vMemAccM_CfgAbGetMpTokenPriority((vMemAccM_NVRAMAccessTokenType)queueIndex);
      vMemAccM_PublishJobResultType currentResult = vMemAccM_MultiPartitionPublishedRequests[queueIndex]->Result;
    /* #110 Consider only fully published jobs == the priority and the job result is set appropriately! */
    if((currentPriority < VMEMACCM_MULTIPARTITION_PUBLISH_NOREQUEST) &&
        (currentResult == (vMemAccM_PublishJobResultType)VMEMACCM_JOB_PENDING))
    {
      /* #111 If the current satellite's job has the currently highest priority, update the values. */
      if((highestPriority == VMEMACCM_MULTIPARTITION_PUBLISH_NOREQUEST) ||
          (currentPriority > highestPriority))
      {
        highestPriority = currentPriority;
        partitionIndex = queueIndex;
      }
    }
  }
  /* #120 Return the partition index with highest priority. VMEMACCM_MULTIPARTITION_NR_OF_PARTITIONS if nothing was published. */
  return partitionIndex;
}

/**********************************************************************************************************************
 *  vMemAccM_SchedMpSynchronizeToken
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(void, VMEMACCM_CODE) vMemAccM_SchedMpSynchronizeToken(void)
{
  vMemAccM_MultiPartitionPartitionIdType partitionIndex = vMemAccM_SchedMpGetNextPartitionIndex();
  /* #10 No published job, nothing to, partitions are in synchronized state, set the token appropriately. */
  if(partitionIndex == VMEMACCM_MULTIPARTITION_NR_OF_PARTITIONS)
  {
    vMemAccM_CfgAbMpSetToken(VMEMACCM_MULTIPARTITION_SYNC_TOKEN, VMEMACCM_MULTIPARTITION_SYNC_TOKEN);
  }
  /* #200 At least one partition publishes a job, the partition with highest published priority shall get the token. */
  else
  {
    vMemAccM_CfgAbMpSetToken(partitionIndex, partitionIndex);
  }
}

# elif (VMEMACCM_MULTI_PARTITION_SATELLITE == STD_ON)
/**********************************************************************************************************************
 *  vMemAccm_SchedMpPartitionDo
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
FUNC(boolean, VMEMACCM_CODE) vMemAccm_SchedMpPartitionDo(vMemAccM_SchedStateContextPtrType ContextPtr)
{
  boolean exitMainFunction = TRUE;
  /* #10 Search for the next job. */
  vMemAccM_QueueIndexType nextQueueIndex = vMemAccM_SchedQueueGetNextJob();
  uint32 toBePublishedPriority = ((nextQueueIndex < VMEMACCM_QUEUE_EMPTY)
    ? nextQueueIndex : VMEMACCM_MULTIPARTITION_PUBLISH_NOREQUEST);
  /* #20 Update the request publish (either the next job, or no request). */
  vMemAccM_SchedMpPublishRequestPriority(toBePublishedPriority);
  /* #30 If a job is available (priority was published previously), start the state machine. */
  if(toBePublishedPriority < VMEMACCM_MULTIPARTITION_PUBLISH_NOREQUEST)
  {
    ContextPtr->CurrentQueueIndex = nextQueueIndex; /* SBSW_vMemAccM_SchedContextPtr */
    vMemAccM_SchedStateTransitionToProc(ContextPtr); /* SBSW_vMemAccM_SchedContextPtr */
    /* #31 Don't forget to set keep in MainFunction to set up the vMem request directly. */
    exitMainFunction = FALSE;
  }

  return exitMainFunction;
}

# endif /* (VMEMACCM_MULTI_PARTITION_SINGLE_ACCESSOR_MASTER == STD_ON) */

/**********************************************************************************************************************
 *  vMemAccM_SchedStateTransitionToSched
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(void, VMEMACCM_CODE) vMemAccM_SchedStateTransitionToSched(vMemAccM_SchedStateContextPtrType ContextPtr)
{
  vMemAccM_SchedStateProcExit(ContextPtr); /* SBSW_vMemAccM_SchedContextPtr */
  ContextPtr->NextSchedStatePtr = vMemAccM_SchedStateSchedDo; /* SBSW_vMemAccM_SchedContextPtr */
  vMemAccM_SchedStateSchedEnter(ContextPtr); /* SBSW_vMemAccM_SchedContextPtr */
}

/**********************************************************************************************************************
 *  State: Processing
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  vMemAccM_SchedStateProcEnter
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
FUNC(void, VMEMACCM_CODE) vMemAccM_SchedStateProcEnter(vMemAccM_SchedStateContextPtrType ContextPtr)
{
#if (VMEMACCM_MULTI_PARTITION_SINGLE_ACCESSOR_MASTER == STD_ON)
  if(ContextPtr->CurrentQueueIndex == VMEMACCM_QUEUE_EMPTY)
  {
    ContextPtr->SubSMContext.Job.AddressAreaId = /* SBSW_vMemAccM_SchedContextPtr */
        (vMemAccM_AddressAreaIdType)vMemAccM_MultiPartitionPublishedRequests[ContextPtr->PartitionIndex]->AddressAreaId;
    ContextPtr->SubSMContext.Job.Address = /* SBSW_vMemAccM_SchedContextPtr */
        (vMemAccM_AddressType)vMemAccM_MultiPartitionPublishedRequests[ContextPtr->PartitionIndex]->Address;
    /* PRQA S 0315 1 */ /* MD_vMemAccM_VoidPtrTypedPtr */
    ContextPtr->SubSMContext.Job.DataPtr = vMemAccM_MultiPartitionPublishedRequests[ContextPtr->PartitionIndex]->Data; /* SBSW_vMemAccM_SchedContextPtr */
    ContextPtr->SubSMContext.Job.Length = /* SBSW_vMemAccM_SchedContextPtr */
        (vMemAccM_LengthType)vMemAccM_MultiPartitionPublishedRequests[ContextPtr->PartitionIndex]->Length;
    /* PRQA S 4342 2 */ /* MD_vMemAccM_Uint32ToEnumToUint32Cast */
    ContextPtr->SubSMContext.Job.JobType = /* SBSW_vMemAccM_SchedContextPtr */
        (vMemAccM_JobType)vMemAccM_MultiPartitionPublishedRequests[ContextPtr->PartitionIndex]->JobType;
    /* The JobType must be set correctly at this point, the return value shall always be "ok". */
    (void)vMemAccM_SchedSetupStateMachine(ContextPtr->SubSMContext.Job.JobType, &ContextPtr->SubSMContext.Job.SMFuncs); /* SBSW_vMemAccM_SMFuncPtr */
    /* A satellite always publishes one single job step, Offset = 0.
     * Set the address area to PENDING. Master shall never access the address area himself, the address area is != PENDING. */
    vMemAccM_MngmtAreas[ContextPtr->SubSMContext.Job.AddressAreaId].Offset = 0u;  /* SBSW_vMemAccM_MngmtAreas */
    vMemAccM_MngmtAreas[ContextPtr->SubSMContext.Job.AddressAreaId].JobResult = VMEMACCM_JOB_PENDING;  /* SBSW_vMemAccM_MngmtAreas */
  }
  else
#endif /* (VMEMACCM_MULTI_PARTITION_SINGLE_ACCESSOR_MASTER == STD_ON) */
  {
    ContextPtr->SubSMContext.Job = vMemAccM_Queue[ContextPtr->CurrentQueueIndex]; /* SBSW_vMemAccM_SchedContextPtr */
  }

  ContextPtr->SubSMContext.Result = VMEMACCM_JOB_OK; /* SBSW_vMemAccM_SchedContextPtr */
  ContextPtr->SubSMContext.ErrorNotifResult = VMEMACCM_JOB_OK; /* SBSW_vMemAccM_SchedContextPtr */
  ContextPtr->SubSMContext.MgmtArea = &vMemAccM_MngmtAreas[ContextPtr->SubSMContext.Job.AddressAreaId]; /* SBSW_vMemAccM_SchedContextPtr */
  ContextPtr->SubSMContext.vMemNrOfBytes = 0u; /* SBSW_vMemAccM_SchedContextPtr */
  ContextPtr->SubSMContext.Flags.Canceled = VMEMACCM_BITUNSET; /* SBSW_vMemAccM_SchedContextPtr */

#if (VMEMACCM_MULTI_PARTITION_SATELLITE == STD_OFF)
  /* Depending on job type differ how to get the sub address area identifier:
   * HwSpecificReq/ vMemJob: cast the Address back to the HwIdType enumeration and get the sub address area Id.
   * All other: calculate the actual job address and use it to get the sub address area Id. */
  if(ContextPtr->SubSMContext.Job.JobType == VMEMACCM_VMEMJOB)
  {
    ContextPtr->SubSMContext.SubAddrAreaId = /* SBSW_vMemAccM_SchedContextPtr */
      vMemAccM_CfgAbGetSubAddrAreaIdViaHwId(ContextPtr->SubSMContext.Job.AddressAreaId,
      (vMemAccM_HwIdType)ContextPtr->SubSMContext.Job.Address); /* PRQA S 4342 */ /* MD_vMemAccM_CastToHwIdType */
  }
  else
#endif /* (VMEMACCM_MULTI_PARTITION_SATELLITE == STD_OFF) */
  {
    ContextPtr->SubSMContext.SubAddrAreaId = /* SBSW_vMemAccM_SchedContextPtr */
      vMemAccM_CfgAbGetSubAddrAreaId(ContextPtr->SubSMContext.Job.AddressAreaId,
      (ContextPtr->SubSMContext.Job.Address + ContextPtr->SubSMContext.MgmtArea->Offset));
  }
}

/**********************************************************************************************************************
 *  vMemAccM_SchedStateProcDo
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(boolean, VMEMACCM_CODE) vMemAccM_SchedStateProcDo(vMemAccM_SchedStateContextPtrType ContextPtr)
{
  vMemAccM_SMMainFunction(&(ContextPtr->SubSMContext)); /* SBSW_vMemAccM_SMContextPtr */

  if(ContextPtr->SubSMContext.Result != VMEMACCM_JOB_PENDING)
  {
    vMemAccM_SchedStateTransitionToSched(ContextPtr); /* SBSW_vMemAccM_SchedContextPtr */
  }
  /* Always return true: the job is either setup and PENDING, or done. Next state is Scheduling. */
  return TRUE;
}

/**********************************************************************************************************************
 *  vMemAccM_SchedStateProcExit
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, VMEMACCM_CODE) vMemAccM_SchedStateProcExit(vMemAccM_SchedStateContextPtrToConstType ContextPtr)
{
#if (VMEMACCM_MULTI_PARTITION_SINGLE_ACCESSOR_MASTER == STD_ON)
  if(ContextPtr->PartitionIndex < VMEMACCM_MULTIPARTITION_SYNC_TOKEN)
  {
    vMemAccM_MultiPartitionPublishedRequests[ContextPtr->PartitionIndex]->Result = /* SBSW_vMemAccM_MultiPartitionJobPointer */
        (vMemAccM_PublishJobResultType)ContextPtr->SubSMContext.MgmtArea->JobResult;
  }
#else
  VMEMACCM_DUMMY_STATEMENT(ContextPtr);
#endif /* (VMEMACCM_MULTI_PARTITION_SINGLE_ACCESSOR_MASTER == STD_ON) */
}

/**********************************************************************************************************************
 *  vMemAccM_SchedStateTransitionToProc
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(void, VMEMACCM_CODE) vMemAccM_SchedStateTransitionToProc(vMemAccM_SchedStateContextPtrType ContextPtr)
{
  /* Scheduling state does not implement an exit function. */
  ContextPtr->NextSchedStatePtr = vMemAccM_SchedStateProcDo; /* SBSW_vMemAccM_SchedContextPtr */
  vMemAccM_SchedStateProcEnter(ContextPtr); /* SBSW_vMemAccM_SchedContextPtr */
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
 *
 *
 */
FUNC(void, VMEMACCM_CODE) vMemAccM_SchedInit(void)
{
  vMemAccM_QueueIndexType i = 0u;
  vMemAccM_QueueNextJobIndex = VMEMACCM_QUEUE_EMPTY;
  for(; i < VMEMACCM_QUEUE_SIZE; i++)
  {
    vMemAccM_Queue[i].JobType = VMEMACCM_NO_JOB;     /* SBSW_vMemAccM_Queue */
    vMemAccM_Queue[i].AddressAreaId = 0u;            /* SBSW_vMemAccM_Queue */
    vMemAccM_Queue[i].Address = 0u;                  /* SBSW_vMemAccM_Queue */
    vMemAccM_Queue[i].DataPtr = NULL_PTR;            /* SBSW_vMemAccM_Queue */
    vMemAccM_Queue[i].Length = 0u;                   /* SBSW_vMemAccM_Queue */
    vMemAccM_Queue[i].vMemHwSpecificFuncIndex = 0u;  /* SBSW_vMemAccM_Queue */
    vMemAccM_SMDefaultInit(&vMemAccM_Queue[i].SMFuncs); /* SBSW_vMemAccM_SMFuncPtr */
  }

  for(i = 0; i < VMEMACCM_MNGMTAREA_SIZE; i++)
  {
    vMemAccM_MngmtAreas[i].Offset = 0u;  /* SBSW_vMemAccM_MngmtAreas */
    vMemAccM_MngmtAreas[i].JobResult = VMEMACCM_JOB_OK;  /* SBSW_vMemAccM_MngmtAreas */
    vMemAccM_MngmtAreas[i].Flags.ReadOnly = VMEMACCM_BITUNSET;  /* SBSW_vMemAccM_MngmtAreas */
  }

  vMemAccM_SchedState.NextSchedStatePtr = vMemAccM_SchedStateSchedDo;
  vMemAccM_SchedStateSchedEnter(&vMemAccM_SchedState); /* SBSW_vMemAccM_SchedContextPtr */
}

#if (VMEMACCM_MULTI_PARTITION_SATELLITE == STD_OFF)
/**********************************************************************************************************************
 *  vMemAccM_SchedQueueHwSpecificJob
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(Std_ReturnType, VMEMACCM_CODE) vMemAccM_SchedQueueHwSpecificJob
(
  vMemAccM_JobType JobType,
  vMemAccM_AddressAreaIdType AddressAreaId,
  vMemAccM_HwIdType HwId,
  vMemAccM_DataPtrType DataPtr,
  vMemAccM_LengthType DataSize,
  vMemAccM_vMemHwSpecificFuncIndexType vMemHwSpecificFuncIndex)
{
  /* Casting the enumeration to AddressType (uint32) is ok: generated enumeration values are always > 0.
   * The HwSpecific state machine will cast the value back to the enumeration type.
   * We need this cast to avoid new parameters in queue.
   */
  return vMemAccM_SchedQueueJobInternal(JobType, AddressAreaId, (vMemAccM_AddressType)HwId, DataPtr, DataSize, vMemHwSpecificFuncIndex); /* SBSW_vMemAccM_UserDataPointer */
} /* PRQA S 6060 */ /* MD_MSR_STPAR */
#endif /* (VMEMACCM_MULTI_PARTITION_SATELLITE == STD_OFF) */

/**********************************************************************************************************************
 *  vMemAccM_SchedQueueJob
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
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
  /* There is not HwSpecific stuff for "normal" jobs, use 0 as dummy. */
  return vMemAccM_SchedQueueJobInternal(JobType, AddressAreaId, Address, DataPtr, Length, (vMemAccM_vMemHwSpecificFuncIndexType)0u); /* SBSW_vMemAccM_UserDataPointer */
}

/**********************************************************************************************************************
 *  vMemAccM_SchedQueueRemoveJob
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(void, VMEMACCM_CODE) vMemAccM_SchedQueueRemoveJob(vMemAccM_AddressAreaIdType AddressAreaId)
{
  /*
   * Note: the code does not need a critical section because currently calls to this function are implemented
   * within a critical section/ already protected section/ within an exclusive area.
   */
  vMemAccM_QueueIndexType queueIndex = vMemAccM_SchedQueueAddrAreaIdToIndex(AddressAreaId);
  vMemAccM_Queue[queueIndex].JobType = VMEMACCM_NO_JOB; /* SBSW_vMemAccM_Queue */
  vMemAccM_Queue[queueIndex].DataPtr = NULL_PTR; /* SBSW_vMemAccM_Queue */

  if(queueIndex == vMemAccM_QueueNextJobIndex)
  {
    vMemAccM_QueueNextJobIndex = VMEMACCM_QUEUE_NEXTJOB_UNDEFINED;
  }
}

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
  while(vMemAccM_SchedState.NextSchedStatePtr(&vMemAccM_SchedState) == FALSE) /* SBSW_vMemAccM_SchedContextPtr */
  {
    /* Nothing to do, simply trigger the state machine until it is not busy any more. */
  }
}

/**********************************************************************************************************************
 *  vMemAccM_SchedCancelJob
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
FUNC(void, VMEMACCM_CODE) vMemAccM_SchedCancelJob(vMemAccM_AddressAreaIdType AddressAreaId)
{
  /* #100 Cancel only pending jobs. */
  if(vMemAccM_MngmtAreas[AddressAreaId].JobResult == VMEMACCM_JOB_PENDING)
  {
    /* #110 Critical section (Reason: protect access to internal variables against interruptions) */
    SchM_Enter_vMemAccM_VMEMACCM_EXCLUSIVE_AREA_0();
    vMemAccM_SchedState.SubSMContext.Flags.Canceled = VMEMACCM_BITSET;
    vMemAccM_SchedQueueRemoveJob(AddressAreaId);
    vMemAccM_MngmtAreas[AddressAreaId].JobResult = VMEMACCM_JOB_CANCELED; /* SBSW_vMemAccM_MngmtAreas */
    SchM_Exit_vMemAccM_VMEMACCM_EXCLUSIVE_AREA_0();
  }
}

/**********************************************************************************************************************
 *  vMemAccM_SchedSetErrorNotifResult
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
FUNC(boolean, VMEMACCM_CODE) vMemAccM_SchedSetErrorNotifResult
(
  vMemAccM_AddressAreaIdType AddressAreaId,
  vMemAccM_AddressType Address,
  vMemAccM_JobResultType Result,
  vMemAccM_JobType JobType
)
{
  boolean retVal = FALSE;

  if((vMemAccM_SchedState.SubSMContext.Job.JobType == JobType) &&
    (vMemAccM_SchedState.SubSMContext.Job.AddressAreaId == AddressAreaId) &&
    (vMemAccM_SchedState.SubSMContext.Job.Address <= Address) &&
    ((vMemAccM_SchedState.SubSMContext.Job.Address +
        vMemAccM_SchedState.SubSMContext.Job.Length) > Address))
  {
    vMemAccM_SchedState.SubSMContext.ErrorNotifResult = Result;
    retVal = TRUE;
  }

  return retVal;
}

/**********************************************************************************************************************
 * vMemAccM_SchedGetState
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(void, VMEMACCM_CODE) vMemAccM_SchedGetState(vMemAccM_StatePtrType StatePtr)
{
  /* #100 First set the current job type. */
  StatePtr->CurrentJob = vMemAccM_SchedState.SubSMContext.Job.JobType; /* SBSW_vMemAccM_UserPointer */
  /* #200 Only in case the vMemAccM does anything other information can be provided. */
  if(StatePtr->CurrentJob != VMEMACCM_NO_JOB)
  {
    StatePtr->AddressAreaId = vMemAccM_SchedState.SubSMContext.Job.AddressAreaId; /* SBSW_vMemAccM_UserPointer */
    StatePtr->Address = vMemAccM_SchedState.SubSMContext.Job.Address; /* SBSW_vMemAccM_UserPointer */
    StatePtr->Length = vMemAccM_SchedState.SubSMContext.Job.Length; /* SBSW_vMemAccM_UserPointer */
    StatePtr->vMemResult = vMemAccM_SchedState.SubSMContext.Result; /* SBSW_vMemAccM_UserPointer */
    if(StatePtr->vMemResult == VMEMACCM_JOB_PENDING)
    {
      vMemAccM_SubAddrAreaJobParamsType jobParams;
      vMemAccM_SMCalcJobParams(&jobParams, &(vMemAccM_SchedState.SubSMContext)); /* SBSW_vMemAccM_LocalVarAsPtrFuncParam */
      StatePtr->vMemInstanceId = vMemAccM_GetvMemInstanceIdOfSubAddressArea(vMemAccM_SchedState.SubSMContext.SubAddrAreaId); /* SBSW_vMemAccM_UserPointer */
      StatePtr->vMemAddress = vMemAccM_GetPhysicalStartAddressOfSubAddressArea(vMemAccM_SchedState.SubSMContext.SubAddrAreaId) + jobParams.Offset; /* SBSW_vMemAccM_UserPointer */
      StatePtr->vMemLength = vMemAccM_SchedState.SubSMContext.vMemNrOfBytes; /* SBSW_vMemAccM_UserPointer */
    }
  }
}

#define VMEMACCM_STOP_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  END OF FILE: vMemAccM_Sched.c
 *********************************************************************************************************************/
