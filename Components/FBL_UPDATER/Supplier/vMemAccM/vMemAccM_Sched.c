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
#include "vMemAccM_Sched.h"
#include "vMemAccM_StateMachines.h"
#include "vMemAccM_CfgAb.h"
#include "vMemAccM_SMLib.h"
#include "SchM_vMemAccM.h"

#if (VMEMACCM_MINIMAL_SYNC == STD_OFF)

/**********************************************************************************************************************
 *  LOCAL FUNCTION MACROS
 *********************************************************************************************************************/

#if !defined (VMEMACCM_LOCAL) /* COV_VMEMACCM_COMPATIBILITY */
# define VMEMACCM_LOCAL static
#endif

#if !defined (VMEMACCM_LOCAL_INLINE) /* COV_VMEMACCM_COMPATIBILITY */
# define VMEMACCM_LOCAL_INLINE LOCAL_INLINE
#endif


/***********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 **********************************************************************************************************************/

/*! Size of the queue/ number of elements, end of the iteration. */
#define VMEMACCM_QUEUE_SIZE (vMemAccM_GetSizeOfAddressArea())
/*! Queue empty, nothing to do, next queue job will update this value. */
#define VMEMACCM_QUEUE_EMPTY (VMEMACCM_QUEUE_SIZE)

/**********************************************************************************************************************
 *  LOCAL DATA PROTOTYPES
 *********************************************************************************************************************/
#define VMEMACCM_START_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! Queue array - one element per address area */
VMEMACCM_LOCAL VAR(vMemAccM_SchedJobType, VMEMACCM_VAR_NOINIT) vMemAccM_Queue[VMEMACCM_QUEUE_SIZE];

/*! Holds the information about current processing status. */
VMEMACCM_LOCAL VAR(vMemAccM_SchedStateContextType, VMEMACCM_VAR_NOINIT) vMemAccM_SchedState[VMEMACCM_NR_OF_SYNCHRONIZATION_GROUPS];

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
    vMemAccM_JobType JobType, 
    vMemAccM_SMFunctionsPtrType SMFuncs
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
 * \param[in]   SyncGroupId indicating the synchronization group id which the job shall belong to.
 * \return      VMEMACCM_QUEUE_EMPTY: queue is empty.
 *              Index < VMEMACCM_QUEUE_EMPTY: index points to a valid queue entry.
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */
VMEMACCM_LOCAL_INLINE FUNC(vMemAccM_QueueIndexType, VMEMACCM_CODE) vMemAccM_SchedQueueGetNextJob(uint8 SyncGroupId);

/**********************************************************************************************************************
 * vMemAccM_SchedInitGetState
 *********************************************************************************************************************/
/*!
 * \brief       Initializes the given state pointer with default values.
 * \details     -
 * \param[out]  StatePtr pointing to the current state structure. Pointer must be valid.
 * \pre         -
 * \context     TASK
 * \reentrant   TRUE
 * \synchronous TRUE
 */
VMEMACCM_LOCAL_INLINE FUNC(void, VMEMACCM_CODE) vMemAccM_SchedInitGetState
(
    vMemAccM_StatePtrType StatePtr
);

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

#if (VMEMACCM_PARTITION_USECASE != VMEMACCM_SINGLE_PARTITION)

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

/**********************************************************************************************************************
 *  vMemAccM_SchedMpUpdatePublishedRequest
 *********************************************************************************************************************/
/*!
 * \brief       Publishes the highest priority job or no job if the partition's queue is empty.
 * \details     -
 * \param[in]   ContextPtr pointing to the current state machine context. Pointer must be valid.
 * \pre         Multi partition use case.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */
VMEMACCM_LOCAL_INLINE FUNC(void, VMEMACCM_CODE) vMemAccM_SchedMpUpdatePublishedRequest(vMemAccM_SchedStateContextPtrToConstType ContextPtr);

# endif /* (VMEMACCM_MULTIPARTITION_PARTITION_ID == VMEMACCM_MULTIPARTITION_MASTER_PARTITION_ID) */

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
 * \param[in]   ContextPtr pointing to the current state machine context. Pointer must be valid.
 * \pre         Multi partition use case.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */
FUNC(boolean, VMEMACCM_CODE) vMemAccm_SchedMpPartitionDo(vMemAccM_SchedStateContextPtrType ContextPtr);

#endif /* (VMEMACCM_PARTITION_USECASE != VMEMACCM_SINGLE_PARTITION) */

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
  SchM_Enter_vMemAccM_VMEMACCM_EXCLUSIVE_AREA_0();
  if(vMemAccM_MngmtAreas[AddressAreaId].JobResult != VMEMACCM_JOB_PENDING)
  {
    boolean setupSuccessful;
    vMemAccM_QueueIndexType queueIndex = vMemAccM_SchedQueueAddrAreaIdToIndex(AddressAreaId);

    vMemAccM_Queue[queueIndex].JobType = JobType; /* PRQA S 2842 */ /* MD_vMemAccM_DereferenceOfInvalidPointerValue */ /* SBSW_vMemAccM_Queue */
    vMemAccM_Queue[queueIndex].AddressAreaId = AddressAreaId; /* PRQA S 2842 */ /* MD_vMemAccM_DereferenceOfInvalidPointerValue */ /* SBSW_vMemAccM_Queue */
    vMemAccM_Queue[queueIndex].Address = Address; /* PRQA S 2842 */ /* MD_vMemAccM_DereferenceOfInvalidPointerValue */ /* SBSW_vMemAccM_Queue */
    vMemAccM_Queue[queueIndex].DataPtr = DataPtr; /* PRQA S 2842 */ /* MD_vMemAccM_DereferenceOfInvalidPointerValue */ /* SBSW_vMemAccM_Queue */
    vMemAccM_Queue[queueIndex].Length = Length; /* PRQA S 2842 */ /* MD_vMemAccM_DereferenceOfInvalidPointerValue */ /* SBSW_vMemAccM_Queue */
    vMemAccM_Queue[queueIndex].vMemHwSpecificFuncIndex = vMemHwSpecificFuncIndex; /* PRQA S 2842 */ /* MD_vMemAccM_DereferenceOfInvalidPointerValue */ /* SBSW_vMemAccM_Queue */
    
    setupSuccessful = vMemAccM_SchedSetupStateMachine(JobType, &vMemAccM_Queue[queueIndex].SMFuncs); /* SBSW_vMemAccM_SMFuncPtr */

    if(setupSuccessful == TRUE)
    {
      vMemAccM_MngmtAreas[AddressAreaId].JobResult = VMEMACCM_JOB_PENDING; /* SBSW_vMemAccM_MngmtAreas */
      vMemAccM_MngmtAreas[AddressAreaId].InternalJobResult = VMEMACCM_JOB_OK; /* SBSW_vMemAccM_MngmtAreas */
      vMemAccM_MngmtAreas[AddressAreaId].Offset = 0u; /* SBSW_vMemAccM_MngmtAreas */
      vMemAccM_MngmtAreas[AddressAreaId].NrOfStepRetries = 0u; /* SBSW_vMemAccM_MngmtAreas */
      vMemAccM_MngmtAreas[AddressAreaId].NrOfNormalSizeRetryRequests = 0u; /* SBSW_vMemAccM_MngmtAreas */
      /* Do not modify the ReadOnly flag - ReadOnly will be set and checked in vMemAccM main sub module, a ReadOnly
       * Address shall never reach this function with another job than read! */
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
 */
VMEMACCM_LOCAL_INLINE FUNC(vMemAccM_QueueIndexType, VMEMACCM_CODE) vMemAccM_SchedQueueGetNextJob(uint8 SyncGroupId)
{
  vMemAccM_QueueIndexType i;
  vMemAccM_QueueIndexType queueIndex = VMEMACCM_QUEUE_EMPTY;
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
      uint8 syncGroupId = vMemAccM_GetSynchronizationGroupIdOfSubAddressArea(
                            vMemAccM_CfgAbGetSubAddrAreaIdViaJobType
                            (
                                vMemAccM_Queue[tmpIndex].JobType,
                                vMemAccM_Queue[tmpIndex].AddressAreaId,
                                vMemAccM_Queue[tmpIndex].Address,
                                vMemAccM_MngmtAreas[vMemAccM_Queue[tmpIndex].AddressAreaId].Offset
                            )
                          );
      if(syncGroupId == SyncGroupId)
      {
        queueIndex = tmpIndex;
        break;
      }
    }
  }
  return queueIndex;
} /* PRQA S 6080 */ /* MD_MSR_STMIF */

/**********************************************************************************************************************
 * vMemAccM_SchedInitGetState
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
VMEMACCM_LOCAL_INLINE FUNC(void, VMEMACCM_CODE) vMemAccM_SchedInitGetState(vMemAccM_StatePtrType StatePtr)
{
  StatePtr->CurrentJob = VMEMACCM_NO_JOB; /* SBSW_vMemAccM_UserPointer */
  StatePtr->Address = 0u; /* SBSW_vMemAccM_UserPointer */
  StatePtr->Length = 0u; /* SBSW_vMemAccM_UserPointer */
  StatePtr->vMemResult = VMEMACCM_JOB_OK; /* SBSW_vMemAccM_UserPointer */
  StatePtr->vMemInstanceId = 0u; /* SBSW_vMemAccM_UserPointer */
  StatePtr->vMemAddress = 0u; /* SBSW_vMemAccM_UserPointer */
  StatePtr->vMemLength = 0u; /* SBSW_vMemAccM_UserPointer */
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
 *
 *
 */
FUNC(boolean, VMEMACCM_CODE) vMemAccM_SchedStateSchedDo(vMemAccM_SchedStateContextPtrType ContextPtr)
{
  boolean exitMainFunction = TRUE;
  uint8 maxNrOfvMemJobSetups = vMemAccM_CfgAbGetMaxNrOfJobSetupsInMainFunction();
  if(ContextPtr->NrOfvMemJobsInThisMainFunction < maxNrOfvMemJobSetups)
  {
    vMemAccM_QueueIndexType nextQueueIndex = vMemAccM_SchedQueueGetNextJob(ContextPtr->ContextId);
    if(nextQueueIndex < VMEMACCM_QUEUE_EMPTY)
    {
      ContextPtr->CurrentQueueIndex = nextQueueIndex;   /* SBSW_vMemAccM_SchedContextPtr */
      ContextPtr->NrOfvMemJobsInThisMainFunction++;     /* SBSW_vMemAccM_SchedContextPtr */
      vMemAccM_SchedStateTransitionToProc(ContextPtr);  /* SBSW_vMemAccM_SchedContextPtr */
      exitMainFunction = FALSE;
    }
  }
  return exitMainFunction;
}
#endif /* (VMEMACCM_PARTITION_USECASE == VMEMACCM_SINGLE_PARTITION) */

#if ( VMEMACCM_PARTITION_USECASE != VMEMACCM_SINGLE_PARTITION )
/**********************************************************************************************************************
 *  Multi partition shared functions
 *********************************************************************************************************************/

# if ( VMEMACCM_PARTITION_USECASE == VMEMACCM_MULTI_PARTITION_SINGLE_ACCESSOR ) || \
     ( VMEMACCM_MULTIPARTITION_PARTITION_ID == VMEMACCM_MULTIPARTITION_MASTER_PARTITION_ID )
/**********************************************************************************************************************
 *  vMemAccM_SchedMpUpdatePublishedRequest
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
VMEMACCM_LOCAL_INLINE FUNC(void, VMEMACCM_CODE) vMemAccM_SchedMpUpdatePublishedRequest(vMemAccM_SchedStateContextPtrToConstType ContextPtr)
{
  /* #10 Get the next job in the queue */
    vMemAccM_QueueIndexType nextQueueIndex = vMemAccM_SchedQueueGetNextJob(ContextPtr->ContextId);
  /* #20 If a job was found publish it */
  if(nextQueueIndex < VMEMACCM_QUEUE_EMPTY)
  {
    vMemAccM_SchedMpPublishRequestPriority(nextQueueIndex);
#  if (VMEMACCM_MULTI_PARTITION_SINGLE_ACCESSOR_MASTER == STD_ON)
    /* #21 If the use case is single accessor master, indicate that there is a pending job */
    /* This needs to be done, because the main partition uses its internal queue to get jobs, but the Statemachine unit will 
       always check the published result, however the internal queue does not publish any jobs. */
    vMemAccM_PartitionPublishRequestPtr->Result = (vMemAccM_PublishJobResultType)VMEMACCM_JOB_PENDING; /* SBSW_vMemAccM_MultiPartitionTokenAndPublishReqPtr */
#  endif
  }
  /* #30 If no job was found reset the published job */
  else
  {
    vMemAccM_SchedMpPublishRequestPriority(VMEMACCM_MULTIPARTITION_PUBLISH_NOREQUEST);
#  if (VMEMACCM_MULTI_PARTITION_SINGLE_ACCESSOR_MASTER == STD_ON)
    /* #31 If the use case is single accessor master, indicate that there is no pending job */
    /* This needs to be done, because the main partition uses its internal queue to get jobs, but the Statemachine unit will 
       always check the published result, however the internal queue does not publish any jobs. */
    vMemAccM_PartitionPublishRequestPtr->Result = (vMemAccM_PublishJobResultType)VMEMACCM_JOB_OK; /* SBSW_vMemAccM_MultiPartitionTokenAndPublishReqPtr */
#  endif
  }
}
# endif /* ( VMEMACCM_PARTITION_USECASE == VMEMACCM_MULTI_PARTITION_SINGLE_ACCESSOR ) || \
           ( VMEMACCM_MULTIPARTITION_PARTITION_ID == VMEMACCM_MULTIPARTITION_MASTER_PARTITION_ID ) */

/**********************************************************************************************************************
 *  vMemAccM_SchedStateSchedDo
 *********************************************************************************************************************/
/*!
 * Internal comment removed. *
 *
 *
 *
 *
 *
 *
 */
FUNC(boolean, VMEMACCM_CODE) vMemAccM_SchedStateSchedDo(vMemAccM_SchedStateContextPtrType ContextPtr)
{
  boolean exitMainFunction = TRUE;
  uint8 maxNrOfvMemJobSetups = vMemAccM_CfgAbGetMaxNrOfJobSetupsInMainFunction();
  if(ContextPtr->NrOfvMemJobsInThisMainFunction < maxNrOfvMemJobSetups)
  {
    ContextPtr->NrOfvMemJobsInThisMainFunction++;     /* SBSW_vMemAccM_SchedContextPtr */
# if (VMEMACCM_PARTITION_USECASE == VMEMACCM_MULTI_PARTITION_SINGLE_ACCESSOR) || ( VMEMACCM_MULTIPARTITION_PARTITION_ID == VMEMACCM_MULTIPARTITION_MASTER_PARTITION_ID )
    vMemAccM_SchedMpUpdatePublishedRequest(ContextPtr); /* SBSW_vMemAccM_SchedContextPtr */
# endif
# if (VMEMACCM_MULTIPARTITION_PARTITION_ID == VMEMACCM_MULTIPARTITION_MASTER_PARTITION_ID)
    vMemAccM_SchedMpSynchronizeToken();
# endif
    exitMainFunction = vMemAccm_SchedMpPartitionDo(ContextPtr); /* SBSW_vMemAccM_SchedContextPtr */
  }
  return exitMainFunction;
}
#endif /* ( VMEMACCM_PARTITION_USECASE != VMEMACCM_SINGLE_PARTITION ) */

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
 *
 */
FUNC(boolean, VMEMACCM_CODE) vMemAccm_SchedMpPartitionDo(vMemAccM_SchedStateContextPtrType ContextPtr)
{
  boolean exitMainFunction = TRUE;
  /* #10 Search for the next job. */
    vMemAccM_QueueIndexType nextQueueIndex = vMemAccM_SchedQueueGetNextJob(ContextPtr->ContextId);
  vMemAccM_PublishPriorityType toBePublishedPriority = ((nextQueueIndex < VMEMACCM_QUEUE_EMPTY)
    ? nextQueueIndex : VMEMACCM_MULTIPARTITION_PUBLISH_NOREQUEST);

  vMemAccM_NVRAMAccessTokenType token = vMemAccM_CfgAbMpGetToken();
  vMemAccM_MultiPartitionPartitionIdType currentPartition = vMemAccM_CfgAbMpGetCurrentActivePartitionFromToken(token);
  vMemAccM_MultiPartitionPartitionIdType lastPartition = vMemAccM_CfgAbMpGetLastActivePartitionFromToken(token);

  /* A higher priority job was found on a different partition */
  boolean resyncNecessary = (currentPartition == VMEMACCM_MULTIPARTITION_RESYNC_TOKEN) && \
       (lastPartition == VMEMACCM_MULTIPARTITION_PARTITION_ID);

  /* #20 Resynchronization is signaled and this was the current partition -> Remove any published jobs */
  if( resyncNecessary )
  {
    vMemAccM_SchedMpPublishRequestPriority(VMEMACCM_MULTIPARTITION_PUBLISH_NOREQUEST);
  }
  /* #21 No job needs to be published -> Remove any published job */
  else if(toBePublishedPriority == VMEMACCM_MULTIPARTITION_PUBLISH_NOREQUEST)
  { 
    vMemAccM_SchedMpPublishRequestPriority(VMEMACCM_MULTIPARTITION_PUBLISH_NOREQUEST); 
  }
  /* #22 Otherwise publish the found job */
  else
  { 
    vMemAccM_SchedMpPublishRequestPriority(toBePublishedPriority); 
    if(currentPartition == VMEMACCM_MULTIPARTITION_PARTITION_ID)
    {
      /* #30 If partition may access the NVRAM -> Prepare the statemachine */
      ContextPtr->CurrentQueueIndex = nextQueueIndex; /* SBSW_vMemAccM_SchedContextPtr */
      vMemAccM_SchedStateTransitionToProc(ContextPtr); /* SBSW_vMemAccM_SchedContextPtr */
      exitMainFunction = FALSE;
    }
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
    vMemAccM_PublishPriorityType currentPriority = vMemAccM_CfgAbGetMpPartitionPriority((vMemAccM_NVRAMAccessTokenType)queueIndex);
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

    /* #210 Token indicates a re-synchronization: check the last running partition synchronization status. */
    if( currentPartition == VMEMACCM_MULTIPARTITION_RESYNC_TOKEN )
    {
      vMemAccM_MultiPartitionPartitionIdType previousPartition = vMemAccM_CfgAbMpGetLastActivePartitionFromToken(token);
      if( vMemAccM_CfgAbGetMpPartitionPriority(previousPartition) == VMEMACCM_MULTIPARTITION_PUBLISH_NOREQUEST )
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
      if( vMemAccM_CfgAbGetMpPartitionPriority(currentPartition) == VMEMACCM_MULTIPARTITION_PUBLISH_NOREQUEST )
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
 */
VMEMACCM_LOCAL_INLINE FUNC(void, VMEMACCM_CODE) vMemAccM_SchedMpPublishRequestPriority(vMemAccM_PublishPriorityType Priority)
{
  vMemAccM_CfgAbSetPublishedPriority(Priority);
}

# endif /* (VMEMACCM_PARTITION_USECASE != VMEMACCM_SINGLE_PARTITION) */

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
      ContextPtr->CurrentQueueIndex = vMemAccM_SchedQueueGetNextJob(ContextPtr->ContextId); /* SBSW_vMemAccM_SchedContextPtr */
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
      vMemAccM_PublishPriorityType currentPriority = vMemAccM_CfgAbGetMpPartitionPriority((vMemAccM_NVRAMAccessTokenType)queueIndex);
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
  vMemAccM_QueueIndexType nextQueueIndex = vMemAccM_SchedQueueGetNextJob(ContextPtr->ContextId);
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

  ContextPtr->SubSMContext.Result = VMEMACCM_JOB_PENDING; /* SBSW_vMemAccM_SchedContextPtr */
  ContextPtr->SubSMContext.ErrorNotifResult = VMEMACCM_JOB_OK; /* SBSW_vMemAccM_SchedContextPtr */
  ContextPtr->SubSMContext.MgmtArea = &vMemAccM_MngmtAreas[ContextPtr->SubSMContext.Job.AddressAreaId]; /* SBSW_vMemAccM_SchedContextPtr */
  ContextPtr->SubSMContext.vMemNrOfBytes = 0u; /* SBSW_vMemAccM_SchedContextPtr */
  ContextPtr->SubSMContext.Flags.Canceled = VMEMACCM_BITUNSET; /* SBSW_vMemAccM_SchedContextPtr */

  /* MgmtArea->Offset is initialized with 0 when a job is setup. */
  ContextPtr->SubSMContext.SubAddrAreaId = 
    vMemAccM_CfgAbGetSubAddrAreaIdViaJobType(
        ContextPtr->SubSMContext.Job.JobType, /* SBSW_vMemAccM_SchedContextPtr */
        ContextPtr->SubSMContext.Job.AddressAreaId,
        ContextPtr->SubSMContext.Job.Address,
        ContextPtr->SubSMContext.MgmtArea->Offset
    );
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
  boolean exitMainFunction = TRUE;
  
  vMemAccM_SMMainFunction(&(ContextPtr->SubSMContext)); /* SBSW_vMemAccM_SMContextPtr */

  if(ContextPtr->SubSMContext.Result != VMEMACCM_JOB_PENDING)
  {
    vMemAccM_SchedStateTransitionToSched(ContextPtr); /* SBSW_vMemAccM_SchedContextPtr */
    exitMainFunction = FALSE;
  }
  /* Otherwise go to the next scheduler state in the following MainFunction */
  
  return exitMainFunction;
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
  VMEMACCM_DUMMY_STATEMENT(ContextPtr); /* PRQA S 3112 */ /* MD_MSR_DummyStmt */
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
  uint8 currentSynchronizationGroup;
  vMemAccM_QueueIndexType i = 0u;
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
  for(currentSynchronizationGroup = 0; currentSynchronizationGroup < VMEMACCM_NR_OF_SYNCHRONIZATION_GROUPS; currentSynchronizationGroup++)
  {
    vMemAccM_SchedState[currentSynchronizationGroup].ContextId = currentSynchronizationGroup; /* SBSW_vMemAccM_SchedContextPtr */
    vMemAccM_SchedState[currentSynchronizationGroup].NextSchedStatePtr = vMemAccM_SchedStateSchedDo; /* SBSW_vMemAccM_SchedContextPtr */
    vMemAccM_SchedStateSchedEnter(&vMemAccM_SchedState[currentSynchronizationGroup]); /* SBSW_vMemAccM_SchedContextPtr */
  }
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
  vMemAccM_vMemHwSpecificFuncIndexType vMemHwSpecificFuncIndex
)
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
}

/**********************************************************************************************************************
 *  vMemAccM_SchedMainFunction
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(void, VMEMACCM_CODE) vMemAccM_SchedMainFunction(void)
{
  uint8 currentSynchronizationGroup;
  for(currentSynchronizationGroup = 0; currentSynchronizationGroup < VMEMACCM_NR_OF_SYNCHRONIZATION_GROUPS; currentSynchronizationGroup++)
  {
    vMemAccM_SchedState[currentSynchronizationGroup].NrOfvMemJobsInThisMainFunction = 0u; /* SBSW_vMemAccM_SchedContextPtr */
    while(vMemAccM_SchedState[currentSynchronizationGroup].NextSchedStatePtr(&vMemAccM_SchedState[currentSynchronizationGroup]) == FALSE) /* SBSW_vMemAccM_SchedContextPtr */
    {
      /* Nothing to do, simply trigger the state machine until it is not busy any more. */
    }
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
 *
 *
 *
 */
FUNC(void, VMEMACCM_CODE) vMemAccM_SchedCancelJob(vMemAccM_AddressAreaIdType AddressAreaId)
{
  /* #100 Cancel only pending jobs. */
  if(vMemAccM_MngmtAreas[AddressAreaId].JobResult == VMEMACCM_JOB_PENDING)
  {
    uint8 synchronizationGroup;
    /* #110 Critical section (Reason: protect access to internal variables against interruptions) */
    SchM_Enter_vMemAccM_VMEMACCM_EXCLUSIVE_AREA_0();
    for(synchronizationGroup = 0; synchronizationGroup < VMEMACCM_NR_OF_SYNCHRONIZATION_GROUPS; synchronizationGroup++)
    {
      if((vMemAccM_SchedState[synchronizationGroup].SubSMContext.Job.AddressAreaId == AddressAreaId) &&
        (vMemAccM_SchedState[synchronizationGroup].SubSMContext.Job.JobType != VMEMACCM_NO_JOB))
      {
        vMemAccM_SchedState[synchronizationGroup].SubSMContext.Flags.Canceled = VMEMACCM_BITSET; /* SBSW_vMemAccM_SchedContextPtr */
        break;
      }
    }
    vMemAccM_SchedQueueRemoveJob(AddressAreaId);
    vMemAccM_MngmtAreas[AddressAreaId].JobResult = VMEMACCM_JOB_CANCELED; /* SBSW_vMemAccM_MngmtAreas */
    SchM_Exit_vMemAccM_VMEMACCM_EXCLUSIVE_AREA_0();

    vMemAccM_CfgAbJobEndNotification(AddressAreaId, VMEMACCM_JOB_CANCELED);
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
  uint8 synchronizationGroup;

  for(synchronizationGroup = 0; synchronizationGroup < VMEMACCM_NR_OF_SYNCHRONIZATION_GROUPS; synchronizationGroup++)
  {
    if((vMemAccM_SchedState[synchronizationGroup].SubSMContext.Job.JobType == JobType) &&
      (vMemAccM_SchedState[synchronizationGroup].SubSMContext.Job.AddressAreaId == AddressAreaId) &&
      (vMemAccM_SchedState[synchronizationGroup].SubSMContext.Job.Address <= Address) &&
      ((vMemAccM_SchedState[synchronizationGroup].SubSMContext.Job.Address +
          vMemAccM_SchedState[synchronizationGroup].SubSMContext.Job.Length) > Address))
    {
      vMemAccM_SchedState[synchronizationGroup].SubSMContext.ErrorNotifResult = Result; /* SBSW_vMemAccM_SchedContextPtr */
      retVal = TRUE;
      break;
    }
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
 *
 *
 */
FUNC(void, VMEMACCM_CODE) vMemAccM_SchedGetState
(
  vMemAccM_AddressAreaIdType AddressAreaId,
  vMemAccM_StatePtrType StatePtr
  )
{
  uint8 synchronizationGroup;
  vMemAccM_SchedInitGetState(StatePtr); /* SBSW_vMemAccM_UserPointer */

  for(synchronizationGroup = 0; synchronizationGroup < VMEMACCM_NR_OF_SYNCHRONIZATION_GROUPS; synchronizationGroup++)
  {
    if((vMemAccM_SchedState[synchronizationGroup].SubSMContext.Job.AddressAreaId == AddressAreaId) &&
      (vMemAccM_SchedState[synchronizationGroup].SubSMContext.Job.JobType != VMEMACCM_NO_JOB))
    {
      StatePtr->CurrentJob = vMemAccM_SchedState[synchronizationGroup].SubSMContext.Job.JobType; /* SBSW_vMemAccM_UserPointer */
      StatePtr->Address = vMemAccM_SchedState[synchronizationGroup].SubSMContext.Job.Address; /* SBSW_vMemAccM_UserPointer */
      StatePtr->Length = vMemAccM_SchedState[synchronizationGroup].SubSMContext.Job.Length; /* SBSW_vMemAccM_UserPointer */
      StatePtr->vMemResult = vMemAccM_SchedState[synchronizationGroup].SubSMContext.Result; /* SBSW_vMemAccM_UserPointer */

      if(StatePtr->vMemResult == VMEMACCM_JOB_PENDING)
      {
        vMemAccM_SubAddrAreaJobParamsType jobParams;
        vMemAccM_SMLibCalcJobParams(
          &jobParams, 
          vMemAccM_SchedState[synchronizationGroup].SubSMContext.SubAddrAreaId,
          vMemAccM_SchedState[synchronizationGroup].SubSMContext.Job.Address,
          vMemAccM_SchedState[synchronizationGroup].SubSMContext.Job.Length,
          vMemAccM_SchedState[synchronizationGroup].SubSMContext.MgmtArea->Offset
        ); /* SBSW_vMemAccM_LocalVarAsPtrFuncParam */
        StatePtr->vMemInstanceId = vMemAccM_GetvMemInstanceIdOfSubAddressArea(vMemAccM_SchedState[synchronizationGroup].SubSMContext.SubAddrAreaId); /* SBSW_vMemAccM_UserPointer */
        StatePtr->vMemAddress = vMemAccM_GetPhysicalStartAddressOfSubAddressArea(vMemAccM_SchedState[synchronizationGroup].SubSMContext.SubAddrAreaId) + jobParams.Offset; /* SBSW_vMemAccM_UserPointer */
        StatePtr->vMemLength = vMemAccM_SchedState[synchronizationGroup].SubSMContext.vMemNrOfBytes; /* SBSW_vMemAccM_UserPointer */
      }
  
      break;
    }
  }
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
 *  vMemAccM_SchedIsVariantAddressAreaPending
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(boolean, VMEMACCM_CODE) vMemAccM_SchedIsVariantAddressAreaPending(void)
{
  boolean anyVariantAAPending = FALSE;
  vMemAccM_AddressAreaIdType aaId = 0;
  for(; aaId < vMemAccM_GetSizeOfAddressAreaOfPCConfig(); aaId++)
  {
    /* length == 1 -> one variant, no switching possible; length > 1 -> variants, switching possible, must not be pending. */
    if((vMemAccM_GetAddressAreaVariantLengthOfAddressArea(aaId) > VMEMACCM_VARIANT_LENGTHOFNOVARIANT) &&
      (vMemAccM_MngmtAreas[aaId].JobResult == VMEMACCM_JOB_PENDING))
    {
      anyVariantAAPending = TRUE;
      break;
    }
  }

  return anyVariantAAPending;
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

/**********************************************************************************************************************
 *  vMemAccM_SchedIsAnyAddressAreaPending
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(boolean, VMEMACCM_CODE) vMemAccM_SchedIsAnyAddressAreaPending(void)
{
  boolean anyAAPending = FALSE;
  vMemAccM_AddressAreaIdType aaId = 0;
  for(; aaId < vMemAccM_GetSizeOfAddressAreaOfPCConfig(); aaId++)
  {
    if(vMemAccM_MngmtAreas[aaId].JobResult == VMEMACCM_JOB_PENDING)
    {
      anyAAPending = TRUE;
      break;
    }
  }

  return anyAAPending;
}


#define VMEMACCM_STOP_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#endif /* (VMEMACCM_MINIMAL_SYNC == STD_OFF) */

/**********************************************************************************************************************
 *  END OF FILE: vMemAccM_Sched.c
 *********************************************************************************************************************/
