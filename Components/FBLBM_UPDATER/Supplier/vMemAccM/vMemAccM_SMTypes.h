/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2022 by Vector Informatik GmbH.                                              All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/*!        \file  vMemAccM_SMTypes.h
 *        \brief  vMemAccM state machines related types header.
 *
 *      \details  Defines vMemAccM state machine related types.
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 *********************************************************************************************************************/

#ifndef VMEMACCM_SMTYPES_H
#define VMEMACCM_SMTYPES_H

#include "vMemAccM_Types.h"

typedef uint8 vMemAccM_CounterType;
typedef uint32 vMemAccM_QueueIndexType;

typedef P2VAR(uint8, AUTOMATIC, VMEMACCM_APPL_VAR) vMemAccM_Uint8PtrType;
typedef P2CONST(uint8, AUTOMATIC, VMEMACCM_APPL_VAR) vMemAccM_Uint8ConstPtrType;

typedef struct
{
  vMemAccM_BitfieldType ReadOnly:1;   /*!< address area is writable;  1: address area is read only. */
} vMemAccM_MngmtFlagsType;            /*!< Stores runtime flags */

typedef struct
{
  vMemAccM_CounterType NrOfStepRetries;             /*!< Stores the retry counter of the current processing step.
                                                           Always shows the next retry, for example 1 means the next
                                                           vMem request is the first retry. */
  vMemAccM_JobResultType JobResult;                 /*!< Stores the latest published address area job result. */
  vMemAccM_JobResultType InternalJobResult;         /*!< Stores the current processing address area job result. */
  vMemAccM_AddressType Offset;                      /*!< Stores the current job progress (already done bytes)
                                                         from start address. */
  vMemAccM_LengthType NrOfNormalSizeRetryRequests;  /*!< Stores the counter for the steps that have to be processed
                                                         with normal size in case a burst size step has failed. */
  vMemAccM_MngmtFlagsType Flags;                    /*!< Stores runtime flags. */
} vMemAccM_MngmtAreaType; /*!< Stores runtime information about one single address area. */

typedef P2VAR(vMemAccM_MngmtAreaType, AUTOMATIC, VMEMACCM_VAR_NOINIT) vMemAccM_MngmtAreaPtrType;
typedef P2CONST(vMemAccM_MngmtAreaType, AUTOMATIC, VMEMACCM_VAR_NOINIT) vMemAccM_MngmtAreaConstPtrType;

struct vMemAccM_SMStateContextStruct; /*!< Stores the current state data. Needed for vMemAccM_StateFunctionPtr.  */
typedef P2VAR(struct vMemAccM_SMStateContextStruct, AUTOMATIC, VMEMACCM_VAR_NOINIT) vMemAccM_SMStateContextPtrType;
typedef P2CONST(struct vMemAccM_SMStateContextStruct, AUTOMATIC, VMEMACCM_VAR_NOINIT) vMemAccM_SMStateContextConstPtrType;

typedef P2FUNC(boolean, VMEMACCM_CODE, vMemAccM_SMStateFunctionPtrType) (vMemAccM_SMStateContextPtrType ContextPtr);

typedef struct
{
  vMemAccM_SMStateFunctionPtrType StateFuncPtr;
} vMemAccM_SMFunctionsType;

typedef P2VAR(vMemAccM_SMFunctionsType, AUTOMATIC, VMEMACCM_VAR_NOINIT) vMemAccM_SMFunctionsPtrType;

typedef struct
{
  vMemAccM_AddressAreaIdType AddressAreaId; /*!< Address area Id the job shall be done for. */
  vMemAccM_JobType JobType;                 /*!< Job to be done for this queue element. */
  vMemAccM_AddressType Address;             /*!< Address the job shall be done for. */
  vMemAccM_LengthType Length;               /*!< Job length. */
  vMemAccM_vMemHwSpecificFuncIndexType vMemHwSpecificFuncIndex; /*!< Used only for HW specific request */
  vMemAccM_DataPtrType DataPtr;             /*!< The used data buffer. */
  vMemAccM_SMFunctionsType SMFuncs; /*! Holds all job processing relevant information. */
} vMemAccM_SchedJobType;

typedef P2VAR(vMemAccM_SchedJobType, AUTOMATIC, VMEMACCM_VAR_NOINIT) vMemAccM_QueueJobPtrType;
typedef P2CONST(vMemAccM_SchedJobType, AUTOMATIC, VMEMACCM_VAR_NOINIT) vMemAccM_QueueJobConstPtrType;

typedef struct
{
  vMemAccM_BitfieldType Canceled:1;   /*!< 0: continue job processing; 1: job shall be canceled as soon as possible. */
} vMemAccM_SMFlagsType;               /*!< Stores flags used to exchange information between the scheduler and
                                           the state machine. Kind of events. */

typedef struct vMemAccM_SMStateContextStruct
{
  vMemAccM_AddressAreaIdType SubAddrAreaId;        /*!< Stores the currently used sub address area ID. */
  vMemAccM_AddressType vMemNrOfBytes;              /*!< Stores the number of bytes passed to the vMem. */
  vMemAccM_JobResultType ErrorNotifResult;         /*!< Stores the current job result. */
  vMemAccM_JobResultType Result;                   /*!< Stores the current job result. */
  vMemAccM_SchedJobType Job;                       /*!< Stores the base information about the job - address, length, job type and data buffer. */
  vMemAccM_MngmtAreaPtrType MgmtArea;              /*!< Points to the management area belonging to current address area. */
  vMemAccM_SMFlagsType Flags;                      /*!< Stores all state machine related flags. */
} vMemAccM_SMStateContextType;                     /*!< Stores the current state data. */

/*! Pointer to constant vMemAccM_SchedJobType. */
typedef P2CONST(vMemAccM_SchedJobType, AUTOMATIC, VMEMACCM_VAR_NOINIT) vMemAccM_SchedJobConstPtrType;

struct vMemAccM_SchedStateStruct;
/*! Pointer to the processing sub module state context type. */
typedef P2VAR(struct vMemAccM_SchedStateStruct, AUTOMATIC, VMEMACCM_VAR_NOINIT) vMemAccM_SchedStateContextPtrType;
typedef P2CONST(struct vMemAccM_SchedStateStruct, AUTOMATIC, VMEMACCM_VAR_NOINIT) vMemAccM_SchedStateContextPtrToConstType;

typedef P2FUNC(boolean, VMEMACCM_CODE, vMemAccM_SchedStateDoFuncPtrType) (vMemAccM_SchedStateContextPtrType ContextPtr);
typedef P2FUNC(void, VMEMACCM_CODE, vMemAccM_SchedStateTransitionToIdleFuncPtrType) (vMemAccM_SMStateContextPtrType ContextPtr);
typedef P2FUNC(void, VMEMACCM_CODE, vMemAccM_SchedStateTransitionToWaitFuncPtrType) (vMemAccM_SMStateContextPtrType ContextPtr);

typedef struct vMemAccM_SchedStateStruct
{
  uint8 ContextId;                                      /*!< Id, which is unique for this context. */
  vMemAccM_QueueIndexType CurrentQueueIndex;            /*!< Index to the current index of the job within the queue. */
#if (VMEMACCM_MULTI_PARTITION_SINGLE_ACCESSOR_MASTER == STD_ON)
  vMemAccM_MultiPartitionPartitionIdType PartitionIndex;/*!< As single accessor master: Indicates the partition 
                                                              which shall be used for processing */
#endif
  vMemAccM_SMStateContextType SubSMContext;            /*!< Context the StateMachine unit will use for processing.
                                                             Also used as communication structure between Scheduler
                                                             and StateMachine unit. */
  vMemAccM_SchedStateDoFuncPtrType NextSchedStatePtr;  /*!< Pointer to the next scheduler state to process. */
  uint8 NrOfvMemJobsInThisMainFunction;                /*!< Number of times new vMem jobs may be setup within a 
                                                             vMemAccM_MainFunction call. */
} vMemAccM_SchedStateContextType;

typedef struct
{
  vMemAccM_LengthType Offset;           /*!< Offset from sub address area start. */
  vMemAccM_DataPtrType DataPtr;         /*!< Pointing to position where to write or read from during the current job 
                                             step. */
  vMemAccM_LengthType Length;           /*!< Number of bytes that may be processed in current job step. */
} vMemAccM_SubAddrAreaJobParamsType; /*!< Stores job parameters depending on current job progress/ processing step. */

/*! Pointer to the sub address area parameter structure. */
typedef P2VAR(vMemAccM_SubAddrAreaJobParamsType, AUTOMATIC, VMEMACCM_VAR_NOINIT) vMemAccM_SubAddrAreaJobParamsPtrType;
/*! Constant pointer to the sub address area parameter structure. */
typedef P2CONST(vMemAccM_SubAddrAreaJobParamsType, AUTOMATIC, VMEMACCM_VAR_NOINIT) vMemAccM_SubAddrAreaJobParamsConstPtrType;

#endif /* VMEMACCM_SMTYPES_H */

/**********************************************************************************************************************
 *  END OF FILE: vMemAccM_SMTypes.h
 *********************************************************************************************************************/
