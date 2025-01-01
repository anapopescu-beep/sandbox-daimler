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
/*!        \file  vMemAccM_StateMachines.c
 *        \brief  vMemAccM state machines submodule source file.
 *
 *      \details  See vMemAccM_StateMachines.h.
 *
 *********************************************************************************************************************/

#define VMEMACCM_STATEMACHINES_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "vMemAccM_Types.h"
#include "vMemAccM_Cfg.h"
#include "vMemAccM_IntCfg.h"
#include "vMemAccM_StateMachines.h"
#include "vMemAccM_MemAb.h"
#include "vMemAccM_CfgAb.h"
#include "SchM_vMemAccM.h"
#include "vMemAccM_Sched.h"
#include "vMemAccM_SMLib.h"

#if (VMEMACCM_MINIMAL_SYNC == STD_OFF)

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

# define VMEMACCM_START_SEC_VAR_NOINIT_8BIT
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#if (VMEMACCM_COMPARE_API == STD_ON)
/*! Internal buffer used for comparing the passed user buffer to NV RAM content. */
VMEMACCM_LOCAL VAR(uint8, VMEMACCM_VAR_NOINIT) vMemAccM_InternalBuffer[VMEMACCM_BUFFER_LENGTH];
#endif /* (VMEMACCM_COMPARE_API == STD_ON) */

# define VMEMACCM_STOP_SEC_VAR_NOINIT_8BIT
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

#define VMEMACCM_START_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  LOCAL STATE MACHINE HELPER FUNCTION PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  vMemAccM_SMCalcWriteJobParams
 *********************************************************************************************************************/
/*!
 * \brief       Prepares all non pointer values within the given structure (pointer) for a vMem write job.
 * \details     -
 * \param[out]  JobParamsPtr holding a structure with job relevant values. Parameter must not be NULL_PTR.
 * \param[in]   ContextPtr holding the current state machine context. Pointer must not be NULL_PTR.
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */
VMEMACCM_LOCAL_INLINE FUNC(void, VMEMACCM_CODE) vMemAccM_SMCalcWriteJobParams
(
  vMemAccM_SubAddrAreaJobParamsPtrType JobParamsPtr,
  vMemAccM_SMStateContextConstPtrType ContextPtr
);

/**********************************************************************************************************************
 *  vMemAccM_SMCalcEraseJobParams
 *********************************************************************************************************************/
/*!
 * \brief       Prepares all non pointer values within the given structure (pointer) for a vMem erase job.
 * \details     -
 * \param[out]  JobParamsPtr holding a structure with job relevant values. Parameter must not be NULL_PTR.
 * \param[in]   ContextPtr holding the current state machine context. Pointer must not be NULL_PTR.
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */
VMEMACCM_LOCAL_INLINE FUNC(void, VMEMACCM_CODE) vMemAccM_SMCalcEraseJobParams
(
  vMemAccM_SubAddrAreaJobParamsPtrType JobParamsPtr,
  vMemAccM_SMStateContextConstPtrType ContextPtr
);

/**********************************************************************************************************************
 *  vMemAccM_SMCalcReadBlankReadJobParams
 *********************************************************************************************************************/
/*!
 * \brief       Prepares all non pointer values within the given structure (pointer) for a vMem read job (within the
 *              ReadBlank state machine).
 * \details     -
 * \param[out]  JobParamsPtr holding a structure with job relevant values. Parameter must not be NULL_PTR.
 * \param[in]   ContextPtr holding the current state machine context. Pointer must not be NULL_PTR.
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */
FUNC(void, VMEMACCM_CODE) vMemAccM_SMCalcReadBlankReadJobParams
(
  vMemAccM_SubAddrAreaJobParamsPtrType ReadJobParamsPtr,
  vMemAccM_SMStateContextConstPtrType ContextPtr
);

/**********************************************************************************************************************
 *  vMemAccM_SMCalcJobParamsAlignAddressToPage
 *********************************************************************************************************************/
/*!
 * \brief       Prepares all non pointer values within the given structure (pointer) for a vMem IsBlank job (within the
 *              ReadBlank state machine).
 * \details     -
 * \param[out]  JobParamsPtr holding a structure with job relevant values. Parameter must not be NULL_PTR.
 * \param[in]   ContextPtr holding the current state machine context. Pointer must not be NULL_PTR.
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */
FUNC(void, VMEMACCM_CODE) vMemAccM_SMCalcJobParamsAlignAddressToPage
(
  vMemAccM_SubAddrAreaJobParamsPtrType JobParamsPtr,
  vMemAccM_SMStateContextConstPtrType ContextPtr
);

#if (VMEMACCM_MULTI_PARTITION_SATELLITE == STD_ON)
/**********************************************************************************************************************
 *  vMemAccM_SMAdjustJobLength
 *********************************************************************************************************************/
/*!
 * \brief       Adjusts the job length value according to passed maximum length.
 * \details     If the maximum length < job length, the job length will be overwritten with the maximum length.
 * \param[in,out]   JobParamsPtr holding the job length to be adjusted. Parameter must not be NULL_PTR.
 * \param[in]   MaxLength as the upper boundary for the job length. The job length will be assigned to this value, if
 *              the job length exceeds the MaxLength.
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \note        Some jobs require job length adjustment to (configured) boundaries - therefore this separate function.
 */
VMEMACCM_LOCAL_INLINE FUNC(void, VMEMACCM_CODE) vMemAccM_SMAdjustJobLength
(
  vMemAccM_SubAddrAreaJobParamsPtrType JobParamsPtr,
  vMemAccM_LengthType MaxLength
);
#endif /* (VMEMACCM_MULTI_PARTITION_SATELLITE == STD_ON) */

/**********************************************************************************************************************
 *  vMemAccM_SMFinalizeWriteErase
 *********************************************************************************************************************/
/*!
 * \brief       Finalizes a write or erase job step.
 * \details     Takes care about canceling, retries, burst avoid and finalizing of the job step.
 * \param[in]   MaxNrOfRetries as the maximum allowed number of retries.
 * \param[in]   NormalSize as page or sector size in bytes.
 * \param[in]   BurstSize as a page burst or sector burst size in bytes.
 * \param[in,out]   ContextPtr holding the current state machine context. Pointer must not be NULL_PTR.
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */
VMEMACCM_LOCAL_INLINE FUNC(void, VMEMACCM_CODE) vMemAccM_SMFinalizeWriteErase
(
  vMemAccM_CounterType MaxNrOfRetries,
  vMemAccM_LengthType NormalSize,
  vMemAccM_LengthType BurstSize,
  vMemAccM_SMStateContextConstPtrType ContextPtr
);

/**********************************************************************************************************************
 *  vMemAccM_SMFinalizeJobViaOffset
 *********************************************************************************************************************/
/*!
 * \brief       Finalizes the current job step depending on job offset.
 * \details     Updates the job offset, take care about canceling, finalizes job if the whole length was processed
 *              (removes the job from queue).
 * \param[in,out]   ContextPtr holding the current state machine context. Pointer must not be NULL_PTR.
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */
VMEMACCM_LOCAL_INLINE FUNC(void, VMEMACCM_CODE) vMemAccM_SMFinalizeJobViaOffset(vMemAccM_SMStateContextConstPtrType ContextPtr);

/**********************************************************************************************************************
 *  vMemAccM_SMFinalizeJob
 *********************************************************************************************************************/
/*!
 * \brief       Finalizes the current job step.
 * \details     Removes the job from queue, sets the job result to the internal result (!= PENDING). The next state
 *              is idle.
 * \param[in,out]   ContextPtr holding the current state machine context. Pointer must not be NULL_PTR.
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */
VMEMACCM_LOCAL_INLINE FUNC(void, VMEMACCM_CODE) vMemAccM_SMFinalizeJob(vMemAccM_SMStateContextConstPtrType ContextPtr);

/**********************************************************************************************************************
 *  vMemAccM_SMCreateReadJobResult
 *********************************************************************************************************************/
/*!
 * \brief       Combines the passed vMem job result with the Error Notification result.
 * \details     Since it is possible to notify the vMemAccM about a result out of vMem, the actual read job result of
 *              the current step has to be created from the vMem result and the (optionally) notification result.
 * \param[in]   vMemResult as the vMem job result.
 * \param[in]   ErrorNotifResult as the result value provided via error notification.
 * \return      Read job result.
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */
VMEMACCM_LOCAL_INLINE FUNC(vMemAccM_JobResultType, VMEMACCM_CODE) vMemAccM_SMCreateReadJobResult
(
  vMemAccM_JobResultType vMemResult,
  vMemAccM_JobResultType ErrorNotifResult
);

/**********************************************************************************************************************
 *  vMemAccM_SMWaitDo
 *********************************************************************************************************************/
/*!
 * \brief       Waits for the vMem until idle again (keep state) and moves the state machine to next state.
 * \details     In case of the vMemAccM satellite the vMem result == result of the published job (in shared RAM).
 * \param[in,out]   ContextPtr pointing to the job related data. The pointer must be valid.
 * \param[in,out]   TransitionToIdleFunction pointing to the function which shall be transitioned to when the vMem is
 *                  not busy anymore. The pointer must be valid.
 * \return      TRUE: the state machine is processing, trigger again.
 *              FALSE: the state machine is done, or waiting for vMem, exit MainFunction.
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */
VMEMACCM_LOCAL_INLINE FUNC(boolean, VMEMACCM_CODE) vMemAccM_SMWaitDo
(
    vMemAccM_SMStateContextPtrType ContextPtr, 
    vMemAccM_SchedStateTransitionToIdleFuncPtrType TransitionToIdleFunction
);

/**********************************************************************************************************************
 *  vMemAccM_SMIdleFinalize
 *********************************************************************************************************************/
/*!
 * \brief      Finalizes the idle state depending on vMem request setup result: let the job step fail, or move to
 *             wait state (via passed function pointer).
 * \details    -
 * \param[in,out]   ContextPtr pointing to the job related data. The pointer must be valid.
 * \param[in,out]   TransitionToWaitFunction pointing to the function which shall be transitioned to when the vMem is
 *                  not busy anymore. The pointer must be valid.
 * \return      TRUE: the state machine is processing, trigger again.
 *              FALSE: the state machine is done, or waiting for vMem, exit MainFunction.
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */
VMEMACCM_LOCAL_INLINE FUNC(boolean, VMEMACCM_CODE) vMemAccM_SMIdleFinalize
(
    vMemAccM_SMStateContextPtrType ContextPtr,
    vMemAccM_SchedStateTransitionToWaitFuncPtrType TransitionToWaitFunction
);

#if (VMEMACCM_MULTI_PARTITION_SATELLITE == STD_ON)
/**********************************************************************************************************************
 *  Multi partition synchronization
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  vMemAccM_SMMPSatellite_PublishJobParameter
 *********************************************************************************************************************/
/*!
 * \brief       Publishes the job to the master partition.
 * \details     Write all required parameters to the respective partition published job structure (located in shared RAM).
 * \param[in,out]   ContextPtr holds the main job information. Parameter must be valid.
 * \param[in]   JobParamsPtr holds the current job step parameter. Parameter must be valid.
 * \param[in]   JobType: the job type to publish. Used to differ between internal and published job type, e.g. ReadBlank.
 * \pre         Multi partition use case "single NV RAM accessor" and vMemAccM acts as satellite.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */
VMEMACCM_LOCAL FUNC(void, VMEMACCM_CODE) vMemAccM_SMMPSatellite_PublishJobParameter
(
  vMemAccM_SMStateContextPtrType ContextPtr,
  vMemAccM_SubAddrAreaJobParamsConstPtrType JobParamsPtr,
  vMemAccM_JobType JobType
);

/**********************************************************************************************************************
 *  vMemAccM_SMMPSatellite_GetJobResult
 *********************************************************************************************************************/
/*!
 * \brief       Return the current job result of the published job.
 * \details     Satellites prepares the job and sets it to PENDING. The master then processes the job and sets the
 *              result to != PENDING (the actual NV RAM access result).
 * \return      The job result stored in published job structure.
 * \pre         Multi partition use case "single NV RAM accessor" and vMemAccM acts as satellite.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */
VMEMACCM_LOCAL FUNC(vMemAccM_JobResultType, VMEMACCM_CODE) vMemAccM_SMMPSatellite_GetJobResult(void);

/**********************************************************************************************************************
 *  vMemAccM_SMMPSatellite_PublishData
 *********************************************************************************************************************/
/*!
 * \brief       Copy number of bytes from source to target. Always start with index 0.
 * \details     -
 * \param[in]   SourcePtr to copy data from. Pointer must be valid.
 * \param[in]   TargetPtr to copy data to. Pointer must be valid.
 * \param[in]   Length == number of bytes to copy.
 * \pre         Multi partition use case "single NV RAM accessor" and vMemAccM acts as satellite.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */
VMEMACCM_LOCAL FUNC(void, VMEMACCM_CODE) vMemAccM_SMMPSatellite_CopyData
(
  vMemAccM_ConstDataPtrType SourcePtr,
  vMemAccM_DataPtrType TargetPtr,
  vMemAccM_LengthType Length
);

#endif /* (VMEMACCM_MULTI_PARTITION_SATELLITE == STD_ON) */

/**********************************************************************************************************************
 *  State machines
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  State machine: Default
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  vMemAccM_SMTransitionToDefault
 *********************************************************************************************************************/
/*!
 * \brief       Moves the state machine to the default state.
 * \details     The default state does nothing. It shall be used to initialize state machines and to ensure
 *              the state machine does nothing wrong if triggered - for example after a cancel.
 * \param[in]   ContextPtr pointing to the job related data. The pointer must be valid.
 * \return      Always returns false.
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */
VMEMACCM_LOCAL FUNC(void, VMEMACCM_CODE) vMemAccM_SMTransitionToDefault(vMemAccM_SMStateContextPtrType ContextPtr);

/**********************************************************************************************************************
 *  vMemAccM_SMDefaultState
 *********************************************************************************************************************/
/*!
 * \brief       Default state, does nothing.
 * \details     Used to initialize and also finalize a job to ensure accidental call does not break anything.
 * \param[in]   ContextPtr pointing to the job related data. The pointer must be valid.
 * \return      Always returns false.
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */
VMEMACCM_LOCAL FUNC(boolean, VMEMACCM_CODE) vMemAccM_SMDefaultState(vMemAccM_SMStateContextPtrType ContextPtr);

/**********************************************************************************************************************
 *  State machine: Write
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  vMemAccM_SMWriteTransitionToIdle
 *********************************************************************************************************************/
/*!
 * \brief       Moves the state machine to the idle state.
 * \details     -
 * \param[out]   ContextPtr pointing to the job related data. The pointer must be valid.
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */
VMEMACCM_LOCAL FUNC(void, VMEMACCM_CODE) vMemAccM_SMWriteTransitionToIdle(vMemAccM_SMStateContextPtrType ContextPtr);

/**********************************************************************************************************************
 *  vMemAccM_SMWriteTransitionToWait
 *********************************************************************************************************************/
/*!
 * \brief       Moves the state machine to the wait state.
 * \details     -
 * \param[out]   ContextPtr pointing to the job related data. The pointer must be valid.
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */
VMEMACCM_LOCAL FUNC(void, VMEMACCM_CODE) vMemAccM_SMWriteTransitionToWait(vMemAccM_SMStateContextPtrType ContextPtr);

/**********************************************************************************************************************
 *  vMemAccM_SMWriteIdleDo
 *********************************************************************************************************************/
/*!
 * \brief       Sets up the vMem job. Depending on the setup result, abort the job step processing, or move
 *              to the next state.
 * \details     -
 * \param[in,out]   ContextPtr pointing to the job related data. The pointer must be valid.
 * \return      TRUE: the state machine is processing, trigger again.
 *              FALSE: the state machine is done, or waiting for vMem, exit MainFunction.
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */
VMEMACCM_LOCAL FUNC(boolean, VMEMACCM_CODE) vMemAccM_SMWriteIdleDo(vMemAccM_SMStateContextPtrType ContextPtr);

/**********************************************************************************************************************
 *  vMemAccM_SMWriteWaitDo
 *********************************************************************************************************************/
/*!
 * \brief       Waits for the vMem until idle again (keep state) and finalizes the job according to vMem result
 *              (go to idle state).
 * \details     -
 * \param[in,out]   ContextPtr pointing to the job related data. The pointer must be valid.
 * \return      TRUE: the state machine is processing, trigger again.
 *              FALSE: the state machine is done, or waiting for vMem, exit MainFunction.
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */
VMEMACCM_LOCAL FUNC(boolean, VMEMACCM_CODE) vMemAccM_SMWriteWaitDo(vMemAccM_SMStateContextPtrType ContextPtr);

/**********************************************************************************************************************
 *  vMemAccM_SMWriteWaitExit
 *********************************************************************************************************************/
/*!
 * \brief       Finalizes the state machine processing.
 * \details     This functions must be called on transition from wait to idle state.
 * \param[in,out]   ContextPtr pointing to the job related data. The pointer must be valid.
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */
VMEMACCM_LOCAL FUNC(void, VMEMACCM_CODE) vMemAccM_SMWriteWaitExit(vMemAccM_SMStateContextConstPtrType ContextPtr);

/**********************************************************************************************************************
 *  State machine: Erase
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  vMemAccM_SMEraseTransitionToIdle
 *********************************************************************************************************************/
/*!
 * \brief       Moves the state machine to the idle state.
 * \details     -
 * \param[out]   ContextPtr pointing to the job related data. The pointer must be valid.
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */
VMEMACCM_LOCAL FUNC(void, VMEMACCM_CODE) vMemAccM_SMEraseTransitionToIdle(vMemAccM_SMStateContextPtrType ContextPtr);

/**********************************************************************************************************************
 *  vMemAccM_SMEraseTransitionToWait
 *********************************************************************************************************************/
/*!
 * \brief       Moves the state machine to the wait state.
 * \details     -
 * \param[out]   ContextPtr pointing to the job related data. The pointer must be valid.
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */
VMEMACCM_LOCAL FUNC(void, VMEMACCM_CODE) vMemAccM_SMEraseTransitionToWait(vMemAccM_SMStateContextPtrType ContextPtr);

/**********************************************************************************************************************
 *  vMemAccM_SMEraseIdleDo
 *********************************************************************************************************************/
/*!
 * \brief       Sets up the vMem job. Depending on the setup result, abort the job step processing, or move
 *              to the next state.
 * \details     -
 * \param[in,out]   ContextPtr pointing to the job related data. The pointer must be valid.
 * \return      TRUE: the state machine is processing, trigger again.
 *              FALSE: the state machine is done, or waiting for vMem, exit MainFunction.
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */
VMEMACCM_LOCAL FUNC(boolean, VMEMACCM_CODE) vMemAccM_SMEraseIdleDo(vMemAccM_SMStateContextPtrType ContextPtr);

/**********************************************************************************************************************
 *  vMemAccM_SMEraseWaitDo
 *********************************************************************************************************************/
/*!
 * \brief       Waits for the vMem until idle again (keep state) and finalizes the job according to vMem result
 *              (go to idle state).
 * \details     -
 * \param[in,out]   ContextPtr pointing to the job related data. The pointer must be valid.
 * \return      TRUE: the state machine is processing, trigger again.
 *              FALSE: the state machine is done, or waiting for vMem, exit MainFunction.
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */
VMEMACCM_LOCAL FUNC(boolean, VMEMACCM_CODE) vMemAccM_SMEraseWaitDo(vMemAccM_SMStateContextPtrType ContextPtr);

/**********************************************************************************************************************
 *  vMemAccM_SMEraseWaitExit
 *********************************************************************************************************************/
/*!
 * \brief       Finalizes the state machine processing.
 * \details     This functions must be called on transition from wait to idle state.
 * \param[in,out]   ContextPtr pointing to the job related data. The pointer must be valid.
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */
VMEMACCM_LOCAL FUNC(void, VMEMACCM_CODE) vMemAccM_SMEraseWaitExit(vMemAccM_SMStateContextConstPtrType ContextPtr);

/**********************************************************************************************************************
 *  State machine: Read
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  vMemAccM_SMReadTransitionToIdle
 *********************************************************************************************************************/
/*!
 * \brief       Moves the state machine to the idle state.
 * \details     -
 * \param[out]   ContextPtr pointing to the job related data. The pointer must be valid.
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */
VMEMACCM_LOCAL FUNC(void, VMEMACCM_CODE) vMemAccM_SMReadTransitionToIdle(vMemAccM_SMStateContextPtrType ContextPtr);

/**********************************************************************************************************************
 *  vMemAccM_SMReadTransitionToWait
 *********************************************************************************************************************/
/*!
 * \brief       Moves the state machine to the wait state.
 * \details     -
 * \param[out]   ContextPtr pointing to the job related data. The pointer must be valid.
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */
VMEMACCM_LOCAL FUNC(void, VMEMACCM_CODE) vMemAccM_SMReadTransitionToWait(vMemAccM_SMStateContextPtrType ContextPtr);

/**********************************************************************************************************************
 *  vMemAccM_SMReadIdleDo
 *********************************************************************************************************************/
/*!
 * \brief       Sets up the vMem job. Depending on the setup result, abort the job step processing, or move
 *              to the next state.
 * \details     -
 * \param[in,out]   ContextPtr pointing to the job related data. The pointer must be valid.
 * \return      TRUE: the state machine is processing, trigger again.
 *              FALSE: the state machine is done, or waiting for vMem, exit MainFunction.
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */
VMEMACCM_LOCAL FUNC(boolean, VMEMACCM_CODE) vMemAccM_SMReadIdleDo(vMemAccM_SMStateContextPtrType ContextPtr);

/**********************************************************************************************************************
 *  vMemAccM_SMReadWaitDo
 *********************************************************************************************************************/
/*!
 * \brief       Waits for the vMem until idle again (keep state) and finalizes the job according to vMem result
 *              (go to idle state).
 * \details     -
 * \param[in,out]   ContextPtr pointing to the job related data. The pointer must be valid.
 * \return      TRUE: the state machine is processing, trigger again.
 *              FALSE: the state machine is done, or waiting for vMem, exit MainFunction.
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */
VMEMACCM_LOCAL FUNC(boolean, VMEMACCM_CODE) vMemAccM_SMReadWaitDo(vMemAccM_SMStateContextPtrType ContextPtr);

/**********************************************************************************************************************
 *  vMemAccM_SMReadWaitExit
 *********************************************************************************************************************/
/*!
 * \brief       Finalizes the state machine processing.
 * \details     This functions must be called on transition from wait to idle state.
 * \param[in,out]   ContextPtr pointing to the job related data. The pointer must be valid.
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */
VMEMACCM_LOCAL FUNC(void, VMEMACCM_CODE) vMemAccM_SMReadWaitExit(vMemAccM_SMStateContextPtrType ContextPtr);

/**********************************************************************************************************************
 *  State machine: ReadBlank
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  vMemAccM_SMReadBlankIsBlankTransitionToIdle
 *********************************************************************************************************************/
/*!
 * \brief       Move the state machine to the idle state (from IsBlank via loading erase value to idle).
 * \details     -
 * \param[in,out]   ContextPtr pointing to the job related data. The pointer must be valid.
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */
VMEMACCM_LOCAL FUNC(void, VMEMACCM_CODE) vMemAccM_SMReadBlankIsBlankTransitionToIdle(vMemAccM_SMStateContextPtrType ContextPtr);

/**********************************************************************************************************************
 *  vMemAccM_SMReadBlankIsBlankFailureTransitionToIdle
 *********************************************************************************************************************/
/*!
 * \brief       Move the state machine to the idle state (from IsBlank via failure to idle).
 * \details     -
 * \param[in,out]   ContextPtr pointing to the job related data. The pointer must be valid.
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */
VMEMACCM_LOCAL FUNC(void, VMEMACCM_CODE) vMemAccM_SMReadBlankIsBlankFailureTransitionToIdle(vMemAccM_SMStateContextPtrType ContextPtr);

/**********************************************************************************************************************
 *  vMemAccM_SMReadBlankIsBlankTransitionToWait
 *********************************************************************************************************************/
/*!
 * \brief       Move the state machine to the wait state (from IsBlank setup to wait for IsBlank).
 * \details     -
 * \param[in,out]   ContextPtr pointing to the job related data. The pointer must be valid.
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */
VMEMACCM_LOCAL FUNC(void, VMEMACCM_CODE) vMemAccM_SMReadBlankIsBlankTransitionToWait(vMemAccM_SMStateContextPtrType ContextPtr);

/**********************************************************************************************************************
 *  vMemAccM_SMReadBlankIsBlankTransitionToRead
 *********************************************************************************************************************/
/*!
 * \brief       Move the state machine to the idle state (from IsBlank via NOT_BLANK NV RAM to Read).
 * \details     -
 * \param[in,out]   ContextPtr pointing to the job related data. The pointer must be valid.
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */
VMEMACCM_LOCAL FUNC(void, VMEMACCM_CODE) vMemAccM_SMReadBlankIsBlankTransitionToRead(vMemAccM_SMStateContextPtrType ContextPtr);

/**********************************************************************************************************************
 *  vMemAccM_SMReadBlankReadTransitionToIdle
 *********************************************************************************************************************/
/*!
 * \brief       Move the state machine to the idle state (from Read to Idle).
 * \details     -
 * \param[in,out]   ContextPtr pointing to the job related data. The pointer must be valid.
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */
VMEMACCM_LOCAL FUNC(void, VMEMACCM_CODE) vMemAccM_SMReadBlankReadTransitionToIdle(vMemAccM_SMStateContextPtrType ContextPtr);

/**********************************************************************************************************************
 *  vMemAccM_SMReadBlankReadTransitionToWait
 *********************************************************************************************************************/
/*!
 * \brief       Move the state machine to the wait state (no exit or enter available).
 * \details     -
 * \param[in,out]   ContextPtr pointing to the job related data. The pointer must be valid.
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */
VMEMACCM_LOCAL FUNC(void, VMEMACCM_CODE) vMemAccM_SMReadBlankReadTransitionToWait(vMemAccM_SMStateContextPtrType ContextPtr);

/**********************************************************************************************************************
 *  vMemAccM_SMReadBlankIdleDo
 *********************************************************************************************************************/
/*!
 * \brief       Sets up the vMem job. Depending on the setup result, abort the job step processing, or move
 *              to the next state.
 * \details     -
 * \param[in,out]   ContextPtr pointing to the job related data. The pointer must be valid.
 * \return      TRUE: the state machine is processing, trigger again.
 *              FALSE: the state machine is done, or waiting for vMem, exit MainFunction.
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */
VMEMACCM_LOCAL FUNC(boolean, VMEMACCM_CODE) vMemAccM_SMReadBlankIdleDo(vMemAccM_SMStateContextPtrType ContextPtr);

/**********************************************************************************************************************
 *  vMemAccM_SMReadBlankIsBlankWaitDo
 *********************************************************************************************************************/
/*!
 * \brief       Waits for the vMem until idle again (keep state) and moves the state machine to next state.
 * \details     Depending on IsBlank result the state moves to
 *              - ReadBlankIdleDo: the page is blank, fill the related buffer area with erase value.
 *              - ReadBlankReadIdleDo: the page is not blank, read data from NV RAM.
 *              In case of the vMemAccM satellite the vMem result == result of the published job (in shared RAM).
 * \param[in]   ContextPtr pointing to the job related data. The pointer must be valid.
 * \return      TRUE: the state machine is processing, trigger again.
 *              FALSE: the state machine is done, or waiting for vMem, exit MainFunction.
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */
VMEMACCM_LOCAL FUNC(boolean, VMEMACCM_CODE) vMemAccM_SMReadBlankIsBlankWaitDo(vMemAccM_SMStateContextPtrType ContextPtr);

/**********************************************************************************************************************
 *  vMemAccM_SMReadBlankIsBlankWaitExit
 *********************************************************************************************************************/
/*!
 * \brief       Fill the user buffer with erase value and finalize job step.
 * \details     The state machine must behave the same as for reading from NV RAM. Take care about cancel: do not write
 *              to the user buffer, of the job was canceled before!
 * \param[in]   ContextPtr pointing to the job related data. The pointer must be valid.
 * \return      TRUE: the state machine is processing, trigger again.
 *              FALSE: the state machine is done, or waiting for vMem, exit MainFunction.
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */
VMEMACCM_LOCAL FUNC(void, VMEMACCM_CODE) vMemAccM_SMReadBlankIsBlankWaitExit(vMemAccM_SMStateContextPtrType ContextPtr);

/**********************************************************************************************************************
 *  vMemAccM_SMReadBlankReadIdleDo
 *********************************************************************************************************************/
/*!
 * \brief           Sets up the vMem job. Depending on the setup result, abort the job step processing, or move
 *                  to the next state.
 * \details         -
 * \param[in,out]   ContextPtr pointing to the job related data. The pointer must be valid.
 * \return          TRUE: the state machine is processing, trigger again.
 *                  FALSE: the state machine is done, or waiting for vMem, exit MainFunction.
 * \pre             -
 * \context         TASK
 * \reentrant       FALSE
 * \synchronous     TRUE
 */
VMEMACCM_LOCAL FUNC(boolean, VMEMACCM_CODE) vMemAccM_SMReadBlankReadIdleDo(vMemAccM_SMStateContextPtrType ContextPtr);

/**********************************************************************************************************************
 *  vMemAccM_SMReadBlankReadWaitDo
 *********************************************************************************************************************/
/*!
 * \brief           Waits for the vMem until idle again (keep state) and finalizes the job according to vMem result
 *                  (go to idle state).
 * \details         -
 * \param[in,out]   ContextPtr pointing to the job related data. The pointer must be valid.
 * \return          TRUE: the state machine is processing, trigger again.
 *                  FALSE: the state machine is done, or waiting for vMem, exit MainFunction.
 * \pre             -
 * \context         TASK
 * \reentrant       FALSE
 * \synchronous     TRUE
 */
VMEMACCM_LOCAL FUNC(boolean, VMEMACCM_CODE) vMemAccM_SMReadBlankReadWaitDo(vMemAccM_SMStateContextPtrType ContextPtr);


#if (VMEMACCM_COMPARE_API == STD_ON)
/**********************************************************************************************************************
 *  State machine: Compare
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  vMemAccM_SMCompareTransitionToIdle
 *********************************************************************************************************************/
/*!
 * \brief        Moves the state machine to the idle state.
 * \details      -
 * \param[out]   ContextPtr pointing to the job related data. The pointer must be valid.
 * \pre          VMEMACCM_COMPARE_API == STD_ON
 * \context      TASK
 * \reentrant    FALSE
 * \synchronous  TRUE
 */
VMEMACCM_LOCAL FUNC(void, VMEMACCM_CODE) vMemAccM_SMCompareTransitionToIdle(vMemAccM_SMStateContextPtrType ContextPtr);

/**********************************************************************************************************************
 *  vMemAccM_SMCompareTransitionToWait
 *********************************************************************************************************************/
/*!
 * \brief       Moves the state machine to the wait state.
 * \details     -
 * \param[out]   ContextPtr pointing to the job related data. The pointer must be valid.
 * \pre         VMEMACCM_COMPARE_API == STD_ON
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */
VMEMACCM_LOCAL FUNC(void, VMEMACCM_CODE) vMemAccM_SMCompareTransitionToWait(vMemAccM_SMStateContextPtrType ContextPtr);

/**********************************************************************************************************************
 *  vMemAccM_SMCompareIdleDo
 *********************************************************************************************************************/
/*!
 * \brief       Sets up the vMem job. Depending on the setup result, abort the job step processing, or move
 *              to the next state.
 * \details     -
 * \param[in,out]   ContextPtr pointing to the job related data. The pointer must be valid.
 * \return      TRUE: the state machine is processing, trigger again.
 *              FALSE: the state machine is done, or waiting for vMem, exit MainFunction.
 * \pre         VMEMACCM_COMPARE_API == STD_ON
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */
VMEMACCM_LOCAL FUNC(boolean, VMEMACCM_CODE) vMemAccM_SMCompareIdleDo(vMemAccM_SMStateContextPtrType ContextPtr);

/**********************************************************************************************************************
 *  vMemAccM_SMCompareWaitDo
 *********************************************************************************************************************/
/*!
 * \brief       Waits for the vMem until idle again (keep state) and finalizes the job according to vMem result
 *              (go to idle state).
 * \details     -
 * \param[in,out]   ContextPtr pointing to the job related data. The pointer must be valid.
 * \return      TRUE: the state machine is processing, trigger again.
 *              FALSE: the state machine is done, or waiting for vMem, exit MainFunction.
 * \pre         VMEMACCM_COMPARE_API == STD_ON
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */
VMEMACCM_LOCAL FUNC(boolean, VMEMACCM_CODE) vMemAccM_SMCompareWaitDo(vMemAccM_SMStateContextPtrType ContextPtr);

/**********************************************************************************************************************
 *  vMemAccM_SMCompareWaitExit
 *********************************************************************************************************************/
/*!
 * \brief       Finalizes the state machine processing.
 * \details     This functions must be called on transition from wait to idle state.
 * \param[in,out]   ContextPtr pointing to the job related data. The pointer must be valid.
 * \pre         VMEMACCM_COMPARE_API == STD_ON
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */
VMEMACCM_LOCAL FUNC(void, VMEMACCM_CODE) vMemAccM_SMCompareWaitExit(vMemAccM_SMStateContextPtrType ContextPtr);
#endif /* (VMEMACCM_COMPARE_API == STD_ON) */

/**********************************************************************************************************************
 *  State machine: IsBlank
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  vMemAccM_SMIsBlankTransitionToIdle
 *********************************************************************************************************************/
/*!
 * \brief       Moves the state machine to the idle state.
 * \details     -
 * \param[out]   ContextPtr pointing to the job related data. The pointer must be valid.
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */
VMEMACCM_LOCAL FUNC(void, VMEMACCM_CODE) vMemAccM_SMIsBlankTransitionToIdle(vMemAccM_SMStateContextPtrType ContextPtr);

/**********************************************************************************************************************
 *  vMemAccM_SMIsBlankTransitionToWait
 *********************************************************************************************************************/
/*!
 * \brief       Moves the state machine to the wait state.
 * \details     -
 * \param[out]   ContextPtr pointing to the job related data. The pointer must be valid.
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */
VMEMACCM_LOCAL FUNC(void, VMEMACCM_CODE) vMemAccM_SMIsBlankTransitionToWait(vMemAccM_SMStateContextPtrType ContextPtr);

/**********************************************************************************************************************
 *  vMemAccM_SMIsBlankIdleDo
 *********************************************************************************************************************/
/*!
 * \brief       Sets up the vMem job. Depending on the setup result, abort the job step processing, or move
 *              to the next state.
 * \details     -
 * \param[in,out]   ContextPtr pointing to the job related data. The pointer must be valid.
 * \return      TRUE: the state machine is processing, trigger again.
 *              FALSE: the state machine is done, or waiting for vMem, exit MainFunction.
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */
VMEMACCM_LOCAL FUNC(boolean, VMEMACCM_CODE) vMemAccM_SMIsBlankIdleDo(vMemAccM_SMStateContextPtrType ContextPtr);

/**********************************************************************************************************************
 *  vMemAccM_SMIsBlankWaitDo
 *********************************************************************************************************************/
/*!
 * \brief       Waits for the vMem until idle again (keep state) and finalizes the job according to vMem result
 *              (go to idle state).
 * \details     -
 * \param[in,out]   ContextPtr pointing to the job related data. The pointer must be valid.
 * \return      TRUE: the state machine is processing, trigger again.
 *              FALSE: the state machine is done, or waiting for vMem, exit MainFunction.
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */
VMEMACCM_LOCAL FUNC(boolean, VMEMACCM_CODE) vMemAccM_SMIsBlankWaitDo(vMemAccM_SMStateContextPtrType ContextPtr);

/**********************************************************************************************************************
 *  vMemAccM_SMIsBlankWaitExit
 *********************************************************************************************************************/
/*!
 * \brief       Finalizes the state machine processing.
 * \details     This functions must be called on transition from wait to idle state.
 * \param[in,out]   ContextPtr pointing to the job related data. The pointer must be valid.
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */
VMEMACCM_LOCAL FUNC(void, VMEMACCM_CODE) vMemAccM_SMIsBlankWaitExit(vMemAccM_SMStateContextConstPtrType ContextPtr);

#if (VMEMACCM_MULTI_PARTITION_SATELLITE == STD_OFF)
/**********************************************************************************************************************
 *  State machine: HwSpecificReq
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  vMemAccM_SMHwSpecificTransitionToIdle
 *********************************************************************************************************************/
/*!
 * \brief       Moves the state machine to the idle state.
 * \details     -
 * \param[out]  ContextPtr pointing to the job related data. The pointer must be valid.
 * \pre         vMemAccM is not the satellite within a multi partition configuration.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */
VMEMACCM_LOCAL FUNC(void, VMEMACCM_CODE) vMemAccM_SMHwSpecificTransitionToIdle(vMemAccM_SMStateContextPtrType ContextPtr);

/**********************************************************************************************************************
 *  vMemAccM_SMHwSpecificTransitionToWait
 *********************************************************************************************************************/
/*!
 * \brief       Moves the state machine to the wait state.
 * \details     -
 * \param[out]  ContextPtr pointing to the job related data. The pointer must be valid.
 * \pre         vMemAccM is not the satellite within a multi partition configuration.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */
VMEMACCM_LOCAL FUNC(void, VMEMACCM_CODE) vMemAccM_SMHwSpecificTransitionToWait(vMemAccM_SMStateContextPtrType ContextPtr);

/**********************************************************************************************************************
 *  vMemAccM_SMHwSpecificIdleDo
 *********************************************************************************************************************/
/*!
 * \brief       Sets up the vMem job. Depending on the setup result, abort the job step processing, or move
 *              to the next state.
 * \details     -
 * \param[in,out]   ContextPtr pointing to the job related data. The pointer must be valid.
 * \return      TRUE: the state machine is processing, trigger again.
 *              FALSE: the state machine is done, or waiting for vMem, exit MainFunction.
 * \pre         vMemAccM is not the satellite within a multi partition configuration.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */
VMEMACCM_LOCAL FUNC(boolean, VMEMACCM_CODE) vMemAccM_SMHwSpecificIdleDo(vMemAccM_SMStateContextPtrType ContextPtr);

/**********************************************************************************************************************
 *  vMemAccM_SMHwSpecificWaitDo
 *********************************************************************************************************************/
/*!
 * \brief       Waits for the vMem until idle again (keep state) and finalizes the job according to vMem result
 *              (go to idle state).
 * \details     -
 * \param[in,out]   ContextPtr pointing to the job related data. The pointer must be valid.
 * \return      TRUE: the state machine is processing, trigger again.
 *              FALSE: the state machine is done, or waiting for vMem, exit MainFunction.
 * \pre         vMemAccM is not the satellite within a multi partition configuration.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */
VMEMACCM_LOCAL FUNC(boolean, VMEMACCM_CODE) vMemAccM_SMHwSpecificWaitDo(vMemAccM_SMStateContextPtrType ContextPtr);

/**********************************************************************************************************************
 *  vMemAccM_SMHwSpecificWaitExit
 *********************************************************************************************************************/
/*!
 * \brief       Finalizes the state machine processing.
 * \details     This functions must be called on transition from wait to idle state.
 * \param[in,out]   ContextPtr pointing to the job related data. The pointer must be valid.
 * \pre         vMemAccM is not the satellite within a multi partition configuration.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */
VMEMACCM_LOCAL FUNC(void, VMEMACCM_CODE) vMemAccM_SMHwSpecificWaitExit(vMemAccM_SMStateContextConstPtrType ContextPtr);
#endif /* (VMEMACCM_MULTI_PARTITION_SATELLITE == STD_OFF) */

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL STATE MACHINE HELPER FUNCTION
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  vMemAccM_SMCalcWriteJobParams
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
VMEMACCM_LOCAL_INLINE FUNC(void, VMEMACCM_CODE) vMemAccM_SMCalcWriteJobParams
(
  vMemAccM_SubAddrAreaJobParamsPtrType JobParamsPtr,
  vMemAccM_SMStateContextConstPtrType ContextPtr
)
{
  vMemAccM_SMLibCalcJobParams (
    JobParamsPtr, /* SBSW_vMemAccM_JobParams */
    ContextPtr->SubAddrAreaId,
    ContextPtr->Job.Address,
    ContextPtr->Job.Length,
    ContextPtr->MgmtArea->Offset
  );

#if (VMEMACCM_MULTI_PARTITION_SATELLITE == STD_OFF)
  if(ContextPtr->MgmtArea->NrOfNormalSizeRetryRequests > 0u)
  {
    JobParamsPtr->Length = vMemAccM_GetPageSizeOfSubAddressArea(ContextPtr->SubAddrAreaId); /* SBSW_vMemAccM_JobParams */
  }
#endif /* (VMEMACCM_MULTI_PARTITION_SATELLITE == STD_OFF) */
}

/**********************************************************************************************************************
 *  vMemAccM_SMCalcEraseJobParams
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
VMEMACCM_LOCAL_INLINE FUNC(void, VMEMACCM_CODE) vMemAccM_SMCalcEraseJobParams
(
  vMemAccM_SubAddrAreaJobParamsPtrType JobParamsPtr,
  vMemAccM_SMStateContextConstPtrType ContextPtr
)
{      
  vMemAccM_SMLibCalcJobParams (
    JobParamsPtr, /* SBSW_vMemAccM_JobParams */
    ContextPtr->SubAddrAreaId,
    ContextPtr->Job.Address,
    ContextPtr->Job.Length,
    ContextPtr->MgmtArea->Offset
  );

#if (VMEMACCM_MULTI_PARTITION_SATELLITE == STD_OFF)
  if(ContextPtr->MgmtArea->NrOfNormalSizeRetryRequests > 0u)
  {
    JobParamsPtr->Length = vMemAccM_GetSectorSizeOfSubAddressArea(ContextPtr->SubAddrAreaId); /* SBSW_vMemAccM_JobParams */
  }
#endif /* (VMEMACCM_MULTI_PARTITION_SATELLITE == STD_OFF) */
}
/**********************************************************************************************************************
 *  vMemAccM_SMCalcReadBlankReadJobParams
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
FUNC(void, VMEMACCM_CODE) vMemAccM_SMCalcReadBlankReadJobParams
(
  vMemAccM_SubAddrAreaJobParamsPtrType ReadJobParamsPtr,
  vMemAccM_SMStateContextConstPtrType ContextPtr
)
{
  vMemAccM_LengthType jobRemainingLength = ContextPtr->Job.Length - ContextPtr->MgmtArea->Offset;
  ReadJobParamsPtr->Offset = ((ContextPtr->Job.Address + ContextPtr->MgmtArea->Offset) - /* SBSW_vMemAccM_JobParams */
      vMemAccM_GetVirtualStartAddressOfSubAddressArea(ContextPtr->SubAddrAreaId));
  /* The alignment issue when blank checking pagewise and reading byte wise (example):
   * IsBlank: |--Page--|--Page--|--Page--|--Page--|
   * Read:    |xxxxRead|ReadRead|ReadRead|Reaxxxxx|
   * The read may start and end unaligned to page boundaries -> calculate the required offsets and length. */
  if(jobRemainingLength < vMemAccM_GetPageSizeOfSubAddressArea(ContextPtr->SubAddrAreaId))
  {
    ReadJobParamsPtr->Length = jobRemainingLength; /* SBSW_vMemAccM_JobParams */
  }
  else
  {
    /* SM needs IsBlank parameter (executed previously) to get the not blank address space the vMemAccM shall read from. */
    vMemAccM_SubAddrAreaJobParamsType isBlankJobParams;
    vMemAccM_SMCalcJobParamsAlignAddressToPage(&isBlankJobParams, ContextPtr); /* SBSW_vMemAccM_LocalVarAsPtrFuncParam */
    /* a) Read address is aligned to page size: both offsets are same == Length == page size.
     * b) Read address is not aligned to page size (at the beginning of the job): read offset is higher than the
     * IsBlank offset, but the end of the page (IsBlank offset + length) is the same. */
    ReadJobParamsPtr->Length = (isBlankJobParams.Offset + isBlankJobParams.Length) - ReadJobParamsPtr->Offset; /* SBSW_vMemAccM_JobParams */
  }

  vMemAccM_SMLibCalcJobPointer(ReadJobParamsPtr, ContextPtr->Job.DataPtr, ContextPtr->MgmtArea->Offset); /* SBSW_vMemAccM_LocalVarAsPtrFuncParam */
}

/**********************************************************************************************************************
 *  vMemAccM_SMCalcJobParamsAlignAddressToPage
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(void, VMEMACCM_CODE) vMemAccM_SMCalcJobParamsAlignAddressToPage
(
  vMemAccM_SubAddrAreaJobParamsPtrType JobParamsPtr,
  vMemAccM_SMStateContextConstPtrType ContextPtr
)
{
  vMemAccM_AddressType virtualJobStepStartAddress = (ContextPtr->Job.Address + ContextPtr->MgmtArea->Offset);
  virtualJobStepStartAddress -= (virtualJobStepStartAddress % vMemAccM_GetPageSizeOfSubAddressArea(ContextPtr->SubAddrAreaId));
  JobParamsPtr->Offset = (virtualJobStepStartAddress - vMemAccM_GetVirtualStartAddressOfSubAddressArea(ContextPtr->SubAddrAreaId)); /* SBSW_vMemAccM_JobParams */

  JobParamsPtr->Length = vMemAccM_GetPageSizeOfSubAddressArea(ContextPtr->SubAddrAreaId); /* SBSW_vMemAccM_JobParams */
}

#if (VMEMACCM_MULTI_PARTITION_SATELLITE == STD_ON)
/**********************************************************************************************************************
 *  vMemAccM_SMAdjustJobLength
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
VMEMACCM_LOCAL_INLINE FUNC(void, VMEMACCM_CODE) vMemAccM_SMAdjustJobLength
(
  vMemAccM_SubAddrAreaJobParamsPtrType JobParamsPtr,
  vMemAccM_LengthType MaxLength
)
{
  if(JobParamsPtr->Length > MaxLength)
  {
    JobParamsPtr->Length = MaxLength; /* SBSW_vMemAccM_JobParams */
  }
}
#endif /* (VMEMACCM_MULTI_PARTITION_SATELLITE == STD_ON) */

/**********************************************************************************************************************
 *  vMemAccM_SMFinalizeWriteErase
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
VMEMACCM_LOCAL_INLINE FUNC(void, VMEMACCM_CODE) vMemAccM_SMFinalizeWriteErase
(
  vMemAccM_CounterType MaxNrOfRetries,
  vMemAccM_LengthType NormalSize,
  vMemAccM_LengthType BurstSize,
  vMemAccM_SMStateContextConstPtrType ContextPtr
)
{
  /* #100 vMem job successful -> finalize job step processing. */
  if(ContextPtr->Result == VMEMACCM_JOB_OK)
  {
#if (VMEMACCM_MULTI_PARTITION_SATELLITE == STD_OFF)
    if(ContextPtr->MgmtArea->NrOfNormalSizeRetryRequests > 0u)
    {
      ContextPtr->MgmtArea->NrOfNormalSizeRetryRequests--; /* SBSW_vMemAccM_MngmtAreas */
    }
#endif /* (VMEMACCM_MULTI_PARTITION_SATELLITE == STD_OFF) */
    /* #120 Finalize job step successfully, */
    vMemAccM_SMFinalizeJobViaOffset(ContextPtr); /* SBSW_vMemAccM_SMContextPtr */
  }
  /* #200 vMem job failed and retries available: finalize job, ensure next step is a retry (same offset). */
  else if (ContextPtr->MgmtArea->NrOfStepRetries < MaxNrOfRetries)
  {
#if (VMEMACCM_MULTI_PARTITION_SATELLITE == STD_OFF)
    if(ContextPtr->vMemNrOfBytes == BurstSize)
    {
      ContextPtr->MgmtArea->NrOfNormalSizeRetryRequests = BurstSize / NormalSize; /* SBSW_vMemAccM_MngmtAreas */
    }
    else
#endif /* (VMEMACCM_MULTI_PARTITION_SATELLITE == STD_OFF) */
    {
      ContextPtr->MgmtArea->NrOfStepRetries++; /* SBSW_vMemAccM_MngmtAreas */
    }
  }
  /* #300 vMem job failed and no retries available -> abort the job, finalize processing. */
  else
  {
    vMemAccM_SMFinalizeJob(ContextPtr); /* SBSW_vMemAccM_SMContextPtr */
  }

#if (VMEMACCM_MULTI_PARTITION_SATELLITE == STD_ON)
  VMEMACCM_DUMMY_STATEMENT(NormalSize); /* PRQA S 3112 */ /* MD_MSR_DummyStmt */
  VMEMACCM_DUMMY_STATEMENT(BurstSize); /* PRQA S 3112 */ /* MD_MSR_DummyStmt */
#endif /* (VMEMACCM_MULTI_PARTITION_SATELLITE == STD_ON) */

}

/**********************************************************************************************************************
 *  vMemAccM_SMFinalizeJobViaOffset
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
VMEMACCM_LOCAL_INLINE FUNC(void, VMEMACCM_CODE) vMemAccM_SMFinalizeJobViaOffset(vMemAccM_SMStateContextConstPtrType ContextPtr)
{
  /* #10 Critical section (Reason: protect access to internal variables against interruptions). */
  SchM_Enter_vMemAccM_VMEMACCM_EXCLUSIVE_AREA_0();
  /* #20 Add the successfully processed bytes to the offset (already processed bytes). Do only for successful jobs,
   *   for unsuccessful keep the previous Offset value. */
  ContextPtr->MgmtArea->Offset += ContextPtr->vMemNrOfBytes; /* SBSW_vMemAccM_SMContextPtr */
  /* #30 Allowed only to overwrite the internal result in case it is OK -> READ_CORRECTED_ERRORS must not be overwritten! */
  if(ContextPtr->MgmtArea->InternalJobResult == VMEMACCM_JOB_OK)
  {
    ContextPtr->MgmtArea->InternalJobResult = ContextPtr->Result; /* SBSW_vMemAccM_SMContextPtr */
  }

  /* #40 Job processing step successful, next step starts with new NrOfStepRetries => 0. */
  ContextPtr->MgmtArea->NrOfStepRetries = 0u; /* SBSW_vMemAccM_MngmtAreas */

  /* #50 Job finished completely: */
  if(ContextPtr->MgmtArea->Offset >= ContextPtr->Job.Length)
  {
    vMemAccM_SchedQueueRemoveJob(ContextPtr->Job.AddressAreaId);
    ContextPtr->MgmtArea->JobResult = ContextPtr->MgmtArea->InternalJobResult; /* SBSW_vMemAccM_SMContextPtr */
    SchM_Exit_vMemAccM_VMEMACCM_EXCLUSIVE_AREA_0();

    vMemAccM_CfgAbJobEndNotification(ContextPtr->Job.AddressAreaId, ContextPtr->MgmtArea->JobResult);
  }
  else
  {
    SchM_Exit_vMemAccM_VMEMACCM_EXCLUSIVE_AREA_0();
  }
}

/**********************************************************************************************************************
 *  vMemAccM_SMFinalizeJob
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
VMEMACCM_LOCAL_INLINE FUNC(void, VMEMACCM_CODE) vMemAccM_SMFinalizeJob(vMemAccM_SMStateContextConstPtrType ContextPtr)
{
  /* #10 Critical section (Reason: protect access to internal variables against interruptions). */
  SchM_Enter_vMemAccM_VMEMACCM_EXCLUSIVE_AREA_0();
  /* #20 Job abort because of a failure, job will be removed from queue -> no need for cancel handling,
   *   keep the failure result. */
  vMemAccM_SchedQueueRemoveJob(ContextPtr->Job.AddressAreaId);
  /* #30 assign job result at the end of the processing. */
  ContextPtr->MgmtArea->JobResult = ContextPtr->Result; /* SBSW_vMemAccM_SMContextPtr */
  SchM_Exit_vMemAccM_VMEMACCM_EXCLUSIVE_AREA_0();

  vMemAccM_CfgAbJobEndNotification(ContextPtr->Job.AddressAreaId, ContextPtr->Result);
}

/**********************************************************************************************************************
 *  vMemAccM_SMCreateReadJobResult
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
VMEMACCM_LOCAL_INLINE FUNC(vMemAccM_JobResultType, VMEMACCM_CODE) vMemAccM_SMCreateReadJobResult
    (vMemAccM_JobResultType vMemResult, vMemAccM_JobResultType ErrorNotifResult)
{
  vMemAccM_JobResultType result = vMemResult;

  if(ErrorNotifResult != VMEMACCM_JOB_OK)
  {
    if(vMemResult == VMEMACCM_JOB_OK)
    {
      result = ErrorNotifResult;
    }
    else if (vMemResult == VMEMACCM_JOB_FAILED)
    {
      result = vMemResult;
    }
    else if((vMemResult == VMEMACCM_READ_UNCORRECTABLE_ERRORS) || (ErrorNotifResult == VMEMACCM_READ_UNCORRECTABLE_ERRORS))
    {
      result = VMEMACCM_READ_UNCORRECTABLE_ERRORS;
    }
    else
    {
      result = VMEMACCM_READ_CORRECTED_ERRORS;
    }
  }

  return result;
}

/**********************************************************************************************************************
 *  vMemAccM_SMWaitDo
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
VMEMACCM_LOCAL_INLINE FUNC(boolean, VMEMACCM_CODE) vMemAccM_SMWaitDo
(
    vMemAccM_SMStateContextPtrType ContextPtr, 
    vMemAccM_SchedStateTransitionToIdleFuncPtrType TransitionToIdleFunction
)
{
#if (VMEMACCM_MULTI_PARTITION_SATELLITE == STD_ON)
  ContextPtr->Result = vMemAccM_SMMPSatellite_GetJobResult(); /* SBSW_vMemAccM_SMContextPtr */
#else
  ContextPtr->Result = vMemAccM_MemAbProcessing(ContextPtr->SubAddrAreaId); /* SBSW_vMemAccM_SMContextPtr */
#endif /* (VMEMACCM_MULTI_PARTITION_SATELLITE == STD_ON) */

  if(ContextPtr->Result != VMEMACCM_JOB_PENDING)
  {
    if(ContextPtr->Flags.Canceled == VMEMACCM_BITSET)
    {
      vMemAccM_SMTransitionToDefault(ContextPtr); /* SBSW_vMemAccM_SMContextPtr */
    }
    else
    {
      TransitionToIdleFunction(ContextPtr); /* SBSW_vMemAccM_SMTransitionFunction */
    }
  }

  return FALSE;
}

/**********************************************************************************************************************
 *  vMemAccM_SMIdleFinalize
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
VMEMACCM_LOCAL_INLINE FUNC(boolean, VMEMACCM_CODE) vMemAccM_SMIdleFinalize
(
    vMemAccM_SMStateContextPtrType ContextPtr,
    vMemAccM_SchedStateTransitionToWaitFuncPtrType TransitionToWaitFunction
)
{
  boolean smBusy = TRUE;
#if (VMEMACCM_MULTI_PARTITION_SATELLITE == STD_OFF)
  if(ContextPtr->vMemNrOfBytes == 0u)
  {
    ContextPtr->Result = VMEMACCM_JOB_FAILED; /* SBSW_vMemAccM_SMContextPtr */
    vMemAccM_SMFinalizeJob(ContextPtr); /* SBSW_vMemAccM_SMContextPtr */
    smBusy = FALSE;
  }
  else
#endif /* (VMEMACCM_MULTI_PARTITION_SATELLITE == STD_OFF) */
  {
    TransitionToWaitFunction(ContextPtr); /* SBSW_vMemAccM_SMTransitionFunction */
  }
  return smBusy;
}

#if (VMEMACCM_MULTI_PARTITION_SATELLITE == STD_ON)
/**********************************************************************************************************************
 *  Multi partition synchronization
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  vMemAccM_SMMPSatellite_PublishJobParameter
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
VMEMACCM_LOCAL FUNC(void, VMEMACCM_CODE) vMemAccM_SMMPSatellite_PublishJobParameter
(
  vMemAccM_SMStateContextPtrType ContextPtr,
  vMemAccM_SubAddrAreaJobParamsConstPtrType JobParamsPtr,
  vMemAccM_JobType JobType
)
{
  /* The priority was already published, this is a repetition, all parameters of the published job are set here.  */
  vMemAccM_PartitionPublishRequestPtr->Priority = vMemAccM_GetPriorityOfAddressArea(ContextPtr->Job.AddressAreaId); /* SBSW_vMemAccM_MultiPartitionJobPointer */
  vMemAccM_PartitionPublishRequestPtr->JobType = (uint32)JobType; /* SBSW_vMemAccM_MultiPartitionJobPointer */
  vMemAccM_PartitionPublishRequestPtr->AddressAreaId = ContextPtr->Job.AddressAreaId; /* SBSW_vMemAccM_MultiPartitionJobPointer */
  vMemAccM_PartitionPublishRequestPtr->Address =
    (vMemAccM_GetVirtualStartAddressOfSubAddressArea(ContextPtr->SubAddrAreaId) + JobParamsPtr->Offset); /* SBSW_vMemAccM_MultiPartitionJobPointer */
  vMemAccM_PartitionPublishRequestPtr->Length = JobParamsPtr->Length; /* SBSW_vMemAccM_MultiPartitionJobPointer */
  vMemAccM_PartitionPublishRequestPtr->Result = (uint32)VMEMACCM_JOB_PENDING; /* SBSW_vMemAccM_MultiPartitionJobPointer */
  /* #30 Pretend an accepted vMem job, master never rejects jobs! */
  ContextPtr->vMemNrOfBytes = JobParamsPtr->Length; /* SBSW_vMemAccM_SMContextPtr */
}

/**********************************************************************************************************************
 *  vMemAccM_SMMPSatellite_GetJobResult
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
VMEMACCM_LOCAL FUNC(vMemAccM_JobResultType, VMEMACCM_CODE) vMemAccM_SMMPSatellite_GetJobResult(void)
{
  /* PRQA S 4342 1 */ /* MD_vMemAccM_MultiPartitionSatelliteJobResultCast */
  return ((vMemAccM_JobResultType)vMemAccM_PartitionPublishRequestPtr->Result);
}

/**********************************************************************************************************************
 *  vMemAccM_SMMPSatellite_CopyData
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
VMEMACCM_LOCAL FUNC(void, VMEMACCM_CODE) vMemAccM_SMMPSatellite_CopyData
(
  vMemAccM_ConstDataPtrType SourcePtr,
  vMemAccM_DataPtrType TargetPtr,
  vMemAccM_LengthType Length
)
{
  vMemAccM_LengthType lengthDivider = 4u;
  vMemAccM_LengthType i;
  for(i = 0u; i < (Length / lengthDivider); i++)
  {
    /* PRQA S 0316 1 */ /* MD_vMemAccM_VoidPtrTypedPtr */
    ((vMemAccM_PublishRequestDataPtrType)TargetPtr)[i] = ((vMemAccM_PublishRequestDataConstPtrType)SourcePtr)[i]; /* SBSW_vMemAccM_MultiPartitionJobPointer */
  }

  if((Length % lengthDivider) != 0u)
  {
    vMemAccM_LengthType j;
    for(j = (i * lengthDivider); j < Length; j++)
    {
      /* PRQA S 0316 1 */ /* MD_vMemAccM_VoidPtrTypedPtr */
      ((vMemAccM_Uint8PtrType)TargetPtr)[j] = ((vMemAccM_Uint8ConstPtrType)SourcePtr)[j]; /* SBSW_vMemAccM_MultiPartitionJobPointer */
    }
  }
}

#endif /* (VMEMACCM_MULTI_PARTITION_SATELLITE == STD_OFF) */

/**********************************************************************************************************************
 *  STATE MACHINE FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  State machine: Default
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  vMemAccM_SMTransitionToDefault
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
VMEMACCM_LOCAL FUNC(void, VMEMACCM_CODE) vMemAccM_SMTransitionToDefault(vMemAccM_SMStateContextPtrType ContextPtr)
{
  /* No exit! */
  ContextPtr->Job.SMFuncs.StateFuncPtr = vMemAccM_SMDefaultState; /* SBSW_vMemAccM_SMContextPtr */
}

/**********************************************************************************************************************
 *  vMemAccM_SMDefaultState
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
VMEMACCM_LOCAL FUNC(boolean, VMEMACCM_CODE) vMemAccM_SMDefaultState(vMemAccM_SMStateContextPtrType ContextPtr) /* PRQA S 3673 */ /* MD_vMemAccM_NonConstContextPtr */
{
  VMEMACCM_DUMMY_STATEMENT (ContextPtr); /* PRQA S 3112 */ /* MD_MSR_DummyStmt */
  return FALSE;
}

/**********************************************************************************************************************
 *  State machine: Write
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  vMemAccM_SMWriteTransitionToIdle
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
VMEMACCM_LOCAL FUNC(void, VMEMACCM_CODE) vMemAccM_SMWriteTransitionToIdle(vMemAccM_SMStateContextPtrType ContextPtr)
{
  vMemAccM_SMWriteWaitExit(ContextPtr); /* SBSW_vMemAccM_SMContextPtr */
  ContextPtr->Job.SMFuncs.StateFuncPtr = vMemAccM_SMWriteIdleDo; /* SBSW_vMemAccM_SMContextPtr */
}

/**********************************************************************************************************************
 *  vMemAccM_SMWriteTransitionToWait
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
VMEMACCM_LOCAL FUNC(void, VMEMACCM_CODE) vMemAccM_SMWriteTransitionToWait(vMemAccM_SMStateContextPtrType ContextPtr)
{
  ContextPtr->Job.SMFuncs.StateFuncPtr = vMemAccM_SMWriteWaitDo; /* SBSW_vMemAccM_SMContextPtr */
}

/**********************************************************************************************************************
 *  vMemAccM_SMWriteIdleDo
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
VMEMACCM_LOCAL FUNC(boolean, VMEMACCM_CODE) vMemAccM_SMWriteIdleDo(vMemAccM_SMStateContextPtrType ContextPtr)
{
  vMemAccM_SubAddrAreaJobParamsType jobParams;
  vMemAccM_SMCalcWriteJobParams(&jobParams, ContextPtr); /* SBSW_vMemAccM_LocalVarAsPtrFuncParam */
  vMemAccM_SMLibCalcJobPointer(&jobParams, ContextPtr->Job.DataPtr, ContextPtr->MgmtArea->Offset); /* SBSW_vMemAccM_LocalVarAsPtrFuncParam */

#if (VMEMACCM_MULTI_PARTITION_SATELLITE == STD_ON)
  vMemAccM_SMAdjustJobLength(&jobParams, vMemAccM_GetPageSizeOfSubAddressArea(ContextPtr->SubAddrAreaId)); /* SBSW_vMemAccM_LocalVarAsPtrFuncParam */
  /* PRQA S 0315, 0316 1 */ /* MD_vMemAccM_VoidPtrTypedPtr */
  vMemAccM_SMMPSatellite_CopyData(jobParams.DataPtr, vMemAccM_CfgAbMpGetSatelliteDataPtr(), jobParams.Length); /* SBSW_vMemAccM_MultiPartitionJobPointer */
  vMemAccM_SMMPSatellite_PublishJobParameter(ContextPtr, &jobParams, ContextPtr->Job.JobType); /* SBSW_vMemAccM_LocalVarAsPtrFuncParam */
#else
   vMemAccM_MemAbWrite( /* SBSW_vMemAccM_SMContextPtr */
      ContextPtr->SubAddrAreaId, jobParams.Offset, jobParams.DataPtr, jobParams.Length, &ContextPtr->vMemNrOfBytes);
#endif /* (VMEMACCM_MULTI_PARTITION_SATELLITE == STD_ON) */

  return vMemAccM_SMIdleFinalize(ContextPtr, vMemAccM_SMWriteTransitionToWait); /* SBSW_vMemAccM_SMContextPtr */
}

/**********************************************************************************************************************
 *  vMemAccM_SMWriteWaitDo
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
VMEMACCM_LOCAL FUNC(boolean, VMEMACCM_CODE) vMemAccM_SMWriteWaitDo(vMemAccM_SMStateContextPtrType ContextPtr)
{
  return vMemAccM_SMWaitDo(ContextPtr, vMemAccM_SMWriteTransitionToIdle); /* SBSW_vMemAccM_SMContextPtr */
}

/**********************************************************************************************************************
 *  vMemAccM_SMWriteWaitExit
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
VMEMACCM_LOCAL FUNC(void, VMEMACCM_CODE) vMemAccM_SMWriteWaitExit(vMemAccM_SMStateContextConstPtrType ContextPtr)
{
  vMemAccM_SMFinalizeWriteErase(vMemAccM_GetNumberOfWriteRetriesOfSubAddressArea(ContextPtr->SubAddrAreaId), /* SBSW_vMemAccM_SMContextPtr */
    vMemAccM_GetPageSizeOfSubAddressArea(ContextPtr->SubAddrAreaId),
    vMemAccM_GetPageBurstSizeOfSubAddressArea(ContextPtr->SubAddrAreaId),
    ContextPtr);
}

/**********************************************************************************************************************
 *  State machine: Erase
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  vMemAccM_SMEraseTransitionToIdle
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
VMEMACCM_LOCAL FUNC(void, VMEMACCM_CODE) vMemAccM_SMEraseTransitionToIdle(vMemAccM_SMStateContextPtrType ContextPtr)
{
  vMemAccM_SMEraseWaitExit(ContextPtr); /* SBSW_vMemAccM_SMContextPtr */
  ContextPtr->Job.SMFuncs.StateFuncPtr = vMemAccM_SMEraseIdleDo; /* SBSW_vMemAccM_SMContextPtr */
}

/**********************************************************************************************************************
 *  vMemAccM_SMEraseTransitionToWait
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
VMEMACCM_LOCAL FUNC(void, VMEMACCM_CODE) vMemAccM_SMEraseTransitionToWait(vMemAccM_SMStateContextPtrType ContextPtr)
{
  ContextPtr->Job.SMFuncs.StateFuncPtr = vMemAccM_SMEraseWaitDo; /* SBSW_vMemAccM_SMContextPtr */
}

/**********************************************************************************************************************
 *  vMemAccM_SMEraseIdleDo
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
VMEMACCM_LOCAL FUNC(boolean, VMEMACCM_CODE) vMemAccM_SMEraseIdleDo(vMemAccM_SMStateContextPtrType ContextPtr)
{
  vMemAccM_SubAddrAreaJobParamsType jobParams;
  vMemAccM_SMCalcEraseJobParams(&jobParams, ContextPtr); /* SBSW_vMemAccM_LocalVarAsPtrFuncParam */

#if (VMEMACCM_MULTI_PARTITION_SATELLITE == STD_ON)
  vMemAccM_SMAdjustJobLength(&jobParams, vMemAccM_GetSectorSizeOfSubAddressArea(ContextPtr->SubAddrAreaId)); /* SBSW_vMemAccM_LocalVarAsPtrFuncParam */
  vMemAccM_SMMPSatellite_PublishJobParameter(ContextPtr, &jobParams, ContextPtr->Job.JobType); /* SBSW_vMemAccM_LocalVarAsPtrFuncParam */
#else
  vMemAccM_MemAbErase( /* SBSW_vMemAccM_SMContextPtr */
      ContextPtr->SubAddrAreaId, jobParams.Offset, jobParams.Length, &ContextPtr->vMemNrOfBytes);
#endif
  return vMemAccM_SMIdleFinalize(ContextPtr, vMemAccM_SMEraseTransitionToWait); /* SBSW_vMemAccM_SMContextPtr */
}

/**********************************************************************************************************************
 *  vMemAccM_SMEraseWaitDo
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
VMEMACCM_LOCAL FUNC(boolean, VMEMACCM_CODE) vMemAccM_SMEraseWaitDo(vMemAccM_SMStateContextPtrType ContextPtr)
{
  return vMemAccM_SMWaitDo(ContextPtr, vMemAccM_SMEraseTransitionToIdle); /* SBSW_vMemAccM_SMContextPtr */
}

/**********************************************************************************************************************
 *  vMemAccM_SMEraseWaitExit
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
VMEMACCM_LOCAL FUNC(void, VMEMACCM_CODE) vMemAccM_SMEraseWaitExit(vMemAccM_SMStateContextConstPtrType ContextPtr)
{
  vMemAccM_SMFinalizeWriteErase(vMemAccM_GetNumberOfEraseRetriesOfSubAddressArea(ContextPtr->SubAddrAreaId), /* SBSW_vMemAccM_SMContextPtr */
    vMemAccM_GetSectorSizeOfSubAddressArea(ContextPtr->SubAddrAreaId),
    vMemAccM_GetSectorBurstSizeOfSubAddressArea(ContextPtr->SubAddrAreaId),
    ContextPtr);
}

/**********************************************************************************************************************
 *  State machine: Read
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  vMemAccM_SMReadTransitionToIdle
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
VMEMACCM_LOCAL FUNC(void, VMEMACCM_CODE) vMemAccM_SMReadTransitionToIdle(vMemAccM_SMStateContextPtrType ContextPtr)
{
  vMemAccM_SMReadWaitExit(ContextPtr); /* SBSW_vMemAccM_SMContextPtr */
  ContextPtr->Job.SMFuncs.StateFuncPtr = vMemAccM_SMReadIdleDo; /* SBSW_vMemAccM_SMContextPtr */
}

/**********************************************************************************************************************
 *  vMemAccM_SMReadTransitionToWait
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
VMEMACCM_LOCAL FUNC(void, VMEMACCM_CODE) vMemAccM_SMReadTransitionToWait(vMemAccM_SMStateContextPtrType ContextPtr)
{
  ContextPtr->Job.SMFuncs.StateFuncPtr = vMemAccM_SMReadWaitDo; /* SBSW_vMemAccM_SMContextPtr */
}

/**********************************************************************************************************************
 *  vMemAccM_SMReadIdleDo
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
VMEMACCM_LOCAL FUNC(boolean, VMEMACCM_CODE) vMemAccM_SMReadIdleDo(vMemAccM_SMStateContextPtrType ContextPtr)
{
  vMemAccM_SubAddrAreaJobParamsType jobParams;
  vMemAccM_SMLibCalcJobParams(
    &jobParams, 
    ContextPtr->SubAddrAreaId,
    ContextPtr->Job.Address,
    ContextPtr->Job.Length,
    ContextPtr->MgmtArea->Offset
  ); /* SBSW_vMemAccM_LocalVarAsPtrFuncParam */

#if (VMEMACCM_MULTI_PARTITION_SATELLITE == STD_ON)
  vMemAccM_SMAdjustJobLength(&jobParams, vMemAccM_GetReadLengthOfAddressArea(ContextPtr->Job.AddressAreaId)); /* SBSW_vMemAccM_LocalVarAsPtrFuncParam */
  vMemAccM_SMMPSatellite_PublishJobParameter(ContextPtr, &jobParams, ContextPtr->Job.JobType); /* SBSW_vMemAccM_LocalVarAsPtrFuncParam */
#else
  vMemAccM_SMLibCalcJobPointer(&jobParams, ContextPtr->Job.DataPtr, ContextPtr->MgmtArea->Offset); /* SBSW_vMemAccM_LocalVarAsPtrFuncParam */

  vMemAccM_MemAbRead( /* SBSW_vMemAccM_SMContextPtr */
      ContextPtr->SubAddrAreaId, jobParams.Offset, jobParams.DataPtr, jobParams.Length, &ContextPtr->vMemNrOfBytes,
      vMemAccM_GetReadLengthOfAddressArea(ContextPtr->Job.AddressAreaId));
#endif
  return vMemAccM_SMIdleFinalize(ContextPtr, vMemAccM_SMReadTransitionToWait); /* SBSW_vMemAccM_SMContextPtr */
}

/**********************************************************************************************************************
 *  vMemAccM_SMReadWaitDo
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
VMEMACCM_LOCAL FUNC(boolean, VMEMACCM_CODE) vMemAccM_SMReadWaitDo(vMemAccM_SMStateContextPtrType ContextPtr)
{
  return vMemAccM_SMWaitDo(ContextPtr, vMemAccM_SMReadTransitionToIdle); /* SBSW_vMemAccM_SMContextPtr */
}

/**********************************************************************************************************************
 *  vMemAccM_SMReadWaitExit
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
VMEMACCM_LOCAL FUNC(void, VMEMACCM_CODE) vMemAccM_SMReadWaitExit(vMemAccM_SMStateContextPtrType ContextPtr)
{
  ContextPtr->Result = vMemAccM_SMCreateReadJobResult(ContextPtr->Result, ContextPtr->ErrorNotifResult); /* SBSW_vMemAccM_SMContextPtr */

  if((ContextPtr->Result == VMEMACCM_JOB_OK) || (ContextPtr->Result == VMEMACCM_READ_CORRECTED_ERRORS))
  {
#if (VMEMACCM_MULTI_PARTITION_SATELLITE == STD_ON)
    /* PRQA S 0315, 0316 1 */ /* MD_vMemAccM_VoidPtrTypedPtr */
    vMemAccM_Uint8PtrType dataPtr = &(((vMemAccM_Uint8PtrType)ContextPtr->Job.DataPtr)[ContextPtr->MgmtArea->Offset]);
    /* PRQA S 0315 1 */ /* MD_vMemAccM_VoidPtrTypedPtr */
    vMemAccM_SMMPSatellite_CopyData(vMemAccM_CfgAbMpGetSatelliteDataPtr(), dataPtr, ContextPtr->vMemNrOfBytes); /* SBSW_vMemAccM_MultiPartitionJobPointer */
#endif /* (VMEMACCM_MULTI_PARTITION_SATELLITE == STD_ON) */
    vMemAccM_SMFinalizeJobViaOffset(ContextPtr); /* SBSW_vMemAccM_SMContextPtr */
  }
  else
  {
    vMemAccM_SMFinalizeJob(ContextPtr); /* SBSW_vMemAccM_SMContextPtr */
  }
}

/**********************************************************************************************************************
 *  State machine: ReadBlank
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  vMemAccM_SMReadBlankIsBlankTransitionToIdle
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
VMEMACCM_LOCAL FUNC(void, VMEMACCM_CODE) vMemAccM_SMReadBlankIsBlankTransitionToIdle(vMemAccM_SMStateContextPtrType ContextPtr)
{
  vMemAccM_SMReadBlankIsBlankWaitExit(ContextPtr); /* SBSW_vMemAccM_SMContextPtr */
  ContextPtr->Job.SMFuncs.StateFuncPtr = vMemAccM_SMReadBlankIdleDo; /* SBSW_vMemAccM_SMContextPtr */
}

/**********************************************************************************************************************
 *  vMemAccM_SMReadBlankIsBlankFailureTransitionToIdle
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
VMEMACCM_LOCAL FUNC(void, VMEMACCM_CODE) vMemAccM_SMReadBlankIsBlankFailureTransitionToIdle(vMemAccM_SMStateContextPtrType ContextPtr)
{
  /* Intended re-use of IsBlank state machine! */
  vMemAccM_SMIsBlankWaitExit(ContextPtr); /* SBSW_vMemAccM_SMContextPtr */
  ContextPtr->Job.SMFuncs.StateFuncPtr = vMemAccM_SMReadBlankIdleDo; /* SBSW_vMemAccM_SMContextPtr */
}

/**********************************************************************************************************************
 *  vMemAccM_SMReadBlankTransitionToIsBlankWait
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
VMEMACCM_LOCAL FUNC(void, VMEMACCM_CODE) vMemAccM_SMReadBlankIsBlankTransitionToWait(vMemAccM_SMStateContextPtrType ContextPtr)
{
  ContextPtr->Job.SMFuncs.StateFuncPtr = vMemAccM_SMReadBlankIsBlankWaitDo; /* SBSW_vMemAccM_SMContextPtr */
}

/**********************************************************************************************************************
 *  vMemAccM_SMReadBlankIsBlankTransitionToRead
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
VMEMACCM_LOCAL FUNC(void, VMEMACCM_CODE) vMemAccM_SMReadBlankIsBlankTransitionToRead(vMemAccM_SMStateContextPtrType ContextPtr)
{
  ContextPtr->Job.SMFuncs.StateFuncPtr = vMemAccM_SMReadBlankReadIdleDo; /* SBSW_vMemAccM_SMContextPtr */
}

/**********************************************************************************************************************
 *  vMemAccM_SMReadBlankReadTransitionToIdle
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
VMEMACCM_LOCAL FUNC(void, VMEMACCM_CODE) vMemAccM_SMReadBlankReadTransitionToIdle(vMemAccM_SMStateContextPtrType ContextPtr)
{
  /* Intended re-use of Read state machine! */
  vMemAccM_SMReadWaitExit(ContextPtr); /* SBSW_vMemAccM_SMContextPtr */
  ContextPtr->Job.SMFuncs.StateFuncPtr = vMemAccM_SMReadBlankIdleDo; /* SBSW_vMemAccM_SMContextPtr */
}

/**********************************************************************************************************************
 *  vMemAccM_SMReadBlankTransitionToReadWait
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
VMEMACCM_LOCAL FUNC(void, VMEMACCM_CODE) vMemAccM_SMReadBlankReadTransitionToWait(vMemAccM_SMStateContextPtrType ContextPtr)
{
  ContextPtr->Job.SMFuncs.StateFuncPtr = vMemAccM_SMReadBlankReadWaitDo; /* SBSW_vMemAccM_SMContextPtr */
}

/**********************************************************************************************************************
 *  vMemAccM_SMReadBlankIdleDo
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
VMEMACCM_LOCAL FUNC(boolean, VMEMACCM_CODE) vMemAccM_SMReadBlankIdleDo(vMemAccM_SMStateContextPtrType ContextPtr)
{
  vMemAccM_SubAddrAreaJobParamsType jobParams;
  vMemAccM_SMCalcJobParamsAlignAddressToPage(&jobParams, ContextPtr); /* SBSW_vMemAccM_LocalVarAsPtrFuncParam */

#if (VMEMACCM_MULTI_PARTITION_SATELLITE == STD_ON)
  vMemAccM_SMAdjustJobLength(&jobParams, vMemAccM_GetPageSizeOfSubAddressArea(ContextPtr->SubAddrAreaId)); /* SBSW_vMemAccM_LocalVarAsPtrFuncParam */
  vMemAccM_SMMPSatellite_PublishJobParameter(ContextPtr, &jobParams, VMEMACCM_ISBLANKJOB); /* SBSW_vMemAccM_LocalVarAsPtrFuncParam */
#else
  vMemAccM_MemAbIsBlank( /* SBSW_vMemAccM_SMContextPtr */
      ContextPtr->SubAddrAreaId, jobParams.Offset, jobParams.Length, &ContextPtr->vMemNrOfBytes);
#endif
  return vMemAccM_SMIdleFinalize(ContextPtr, vMemAccM_SMReadBlankIsBlankTransitionToWait); /* SBSW_vMemAccM_SMContextPtr */
}

/**********************************************************************************************************************
 *  vMemAccM_SMReadBlankIsBlankWaitDo
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
VMEMACCM_LOCAL FUNC(boolean, VMEMACCM_CODE) vMemAccM_SMReadBlankIsBlankWaitDo(vMemAccM_SMStateContextPtrType ContextPtr)
{
  boolean retVal = FALSE;
#if (VMEMACCM_MULTI_PARTITION_SATELLITE == STD_ON)
  vMemAccM_JobResultType isBlankResult = vMemAccM_SMMPSatellite_GetJobResult();
#else
  vMemAccM_JobResultType isBlankResult = vMemAccM_MemAbProcessing(ContextPtr->SubAddrAreaId); 
#endif
  if(isBlankResult == VMEMACCM_JOB_PENDING)
  {
    ContextPtr->Result = VMEMACCM_JOB_PENDING; /* SBSW_vMemAccM_SMContextPtr */
  }
  else
  {
    if(ContextPtr->Flags.Canceled == VMEMACCM_BITSET)
    {
      ContextPtr->Result = VMEMACCM_JOB_CANCELED; /* SBSW_vMemAccM_SMContextPtr */
      vMemAccM_SMTransitionToDefault(ContextPtr); /* SBSW_vMemAccM_SMContextPtr */
    }
    else if(isBlankResult == VMEMACCM_JOB_OK)
    {
      vMemAccM_SMReadBlankIsBlankTransitionToIdle(ContextPtr); /* SBSW_vMemAccM_SMContextPtr */
    }
    else if(isBlankResult == VMEMACCM_MEM_NOT_BLANK)
    {
      vMemAccM_SMReadBlankIsBlankTransitionToRead(ContextPtr); /* SBSW_vMemAccM_SMContextPtr */
      retVal = TRUE;
    }
    else
    {
      ContextPtr->Result = isBlankResult; /* SBSW_vMemAccM_SMContextPtr */
      ContextPtr->vMemNrOfBytes = 0u; /* SBSW_vMemAccM_SMContextPtr */
      vMemAccM_SMReadBlankIsBlankFailureTransitionToIdle(ContextPtr); /* SBSW_vMemAccM_SMContextPtr */
    }
  }

  return retVal;
}

/**********************************************************************************************************************
 *  vMemAccM_SMReadBlankIsBlankWaitExit
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
VMEMACCM_LOCAL FUNC(void, VMEMACCM_CODE) vMemAccM_SMReadBlankIsBlankWaitExit(vMemAccM_SMStateContextPtrType ContextPtr)
{
  vMemAccM_LengthType i;
  vMemAccM_SubAddrAreaJobParamsType readJobParams;
  uint8 * targetPtr;
  /* Calculates the data pointer the erase value shall be written to. */
  vMemAccM_SMCalcReadBlankReadJobParams(&readJobParams, ContextPtr); /* SBSW_vMemAccM_LocalVarAsPtrFuncParam */
  /* Use a typed pointer to the data buffer (calculated above) (Improve readability of the code, avoid casts in loop). */
  targetPtr = (vMemAccM_Uint8PtrType)(readJobParams.DataPtr); /* PRQA S 0316 */ /* MD_vMemAccM_VoidPtrTypedPtr */

  for(i = 0; i < readJobParams.Length; i++)
  {
      targetPtr[i] = VMEMACCM_ERASEVALUE; /* SBSW_vMemAccM_BufferOverwrite */
  }

  ContextPtr->vMemNrOfBytes = readJobParams.Length; /* SBSW_vMemAccM_SMContextPtr */
  ContextPtr->Result = VMEMACCM_JOB_OK; /* SBSW_vMemAccM_SMContextPtr */
  /* Finalize the job step. Pretend to be a read! ErrorNotitifcation does not matter, we did not access the NV RAM!
   * This step cannot fail, there let it finish successful. */
  vMemAccM_SMFinalizeJobViaOffset(ContextPtr); /* SBSW_vMemAccM_SMContextPtr */
}

/**********************************************************************************************************************
 *  vMemAccM_SMReadBlankReadIdleDo
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
VMEMACCM_LOCAL FUNC(boolean, VMEMACCM_CODE) vMemAccM_SMReadBlankReadIdleDo(vMemAccM_SMStateContextPtrType ContextPtr)
{
  vMemAccM_SubAddrAreaJobParamsType jobParams;
  vMemAccM_SMCalcReadBlankReadJobParams(&jobParams, ContextPtr); /* SBSW_vMemAccM_LocalVarAsPtrFuncParam */
#if (VMEMACCM_MULTI_PARTITION_SATELLITE == STD_ON)
  vMemAccM_SMAdjustJobLength(&jobParams, vMemAccM_GetReadLengthOfAddressArea(ContextPtr->Job.AddressAreaId)); /* SBSW_vMemAccM_LocalVarAsPtrFuncParam */
  vMemAccM_SMMPSatellite_PublishJobParameter(ContextPtr, &jobParams, VMEMACCM_READJOB); /* SBSW_vMemAccM_LocalVarAsPtrFuncParam */
#else
  vMemAccM_MemAbRead( /* SBSW_vMemAccM_SMContextPtr */
      ContextPtr->SubAddrAreaId, jobParams.Offset, jobParams.DataPtr, jobParams.Length, &ContextPtr->vMemNrOfBytes,
      vMemAccM_GetPageSizeOfSubAddressArea(ContextPtr->SubAddrAreaId));
#endif
  return vMemAccM_SMIdleFinalize(ContextPtr, vMemAccM_SMReadBlankReadTransitionToWait); /* SBSW_vMemAccM_SMContextPtr */
}

/**********************************************************************************************************************
 *  vMemAccM_SMReadBlankReadWaitDo
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
VMEMACCM_LOCAL FUNC(boolean, VMEMACCM_CODE) vMemAccM_SMReadBlankReadWaitDo(vMemAccM_SMStateContextPtrType ContextPtr)
{
  return vMemAccM_SMWaitDo(ContextPtr, vMemAccM_SMReadBlankReadTransitionToIdle); /* SBSW_vMemAccM_SMContextPtr */
}

#if (VMEMACCM_COMPARE_API == STD_ON)
/**********************************************************************************************************************
 *  State machine: Compare
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  vMemAccM_SMCompareTransitionToIdle
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
VMEMACCM_LOCAL FUNC(void, VMEMACCM_CODE) vMemAccM_SMCompareTransitionToIdle(vMemAccM_SMStateContextPtrType ContextPtr)
{
  vMemAccM_SMCompareWaitExit(ContextPtr); /* SBSW_vMemAccM_SMContextPtr */
  ContextPtr->Job.SMFuncs.StateFuncPtr = vMemAccM_SMCompareIdleDo; /* SBSW_vMemAccM_SMContextPtr */
}

/**********************************************************************************************************************
 *  vMemAccM_SMCompareTransitionToWait
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
VMEMACCM_LOCAL FUNC(void, VMEMACCM_CODE) vMemAccM_SMCompareTransitionToWait(vMemAccM_SMStateContextPtrType ContextPtr)
{
  ContextPtr->Job.SMFuncs.StateFuncPtr = vMemAccM_SMCompareWaitDo; /* SBSW_vMemAccM_SMContextPtr */
}

/**********************************************************************************************************************
 *  vMemAccM_SMCompareIdleDo
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
VMEMACCM_LOCAL FUNC(boolean, VMEMACCM_CODE) vMemAccM_SMCompareIdleDo(vMemAccM_SMStateContextPtrType ContextPtr)
{
  vMemAccM_SubAddrAreaJobParamsType jobParams;
  vMemAccM_SMLibCalcJobParams(
    &jobParams, 
    ContextPtr->SubAddrAreaId,
    ContextPtr->Job.Address,
    ContextPtr->Job.Length,
    ContextPtr->MgmtArea->Offset
  ); /* SBSW_vMemAccM_LocalVarAsPtrFuncParam */
  jobParams.DataPtr = vMemAccM_InternalBuffer; /* PRQA S 0315 */ /* MD_vMemAccM_VoidPtrTypedPtr */
#if (VMEMACCM_MULTI_PARTITION_SATELLITE == STD_ON)
  /* Use the address area specific maximum read length for job step calculation (not allowed to read more in one step).
   * The internal buffer size has to be >= than the highest read length, which is ensured by GenTool_GeneratorMsr. */
  vMemAccM_SMAdjustJobLength(&jobParams, vMemAccM_GetReadLengthOfAddressArea(ContextPtr->Job.AddressAreaId)); /* SBSW_vMemAccM_LocalVarAsPtrFuncParam */
  vMemAccM_SMMPSatellite_PublishJobParameter(ContextPtr, &jobParams, VMEMACCM_READJOB); /* SBSW_vMemAccM_LocalVarAsPtrFuncParam */
#else
  vMemAccM_MemAbRead( /* SBSW_vMemAccM_SMContextPtr */
      ContextPtr->SubAddrAreaId, jobParams.Offset, jobParams.DataPtr, jobParams.Length, &ContextPtr->vMemNrOfBytes,
      vMemAccM_GetReadLengthOfAddressArea(ContextPtr->Job.AddressAreaId));
#endif /* (VMEMACCM_MULTI_PARTITION_SATELLITE == STD_ON) */
  return vMemAccM_SMIdleFinalize(ContextPtr, vMemAccM_SMCompareTransitionToWait); /* SBSW_vMemAccM_SMContextPtr */
}

/**********************************************************************************************************************
 *  vMemAccM_SMCompareWaitDo
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
VMEMACCM_LOCAL FUNC(boolean, VMEMACCM_CODE) vMemAccM_SMCompareWaitDo(vMemAccM_SMStateContextPtrType ContextPtr)
{
  return vMemAccM_SMWaitDo(ContextPtr, vMemAccM_SMCompareTransitionToIdle); /* SBSW_vMemAccM_SMContextPtr */
}

/**********************************************************************************************************************
 *  vMemAccM_SMCompareWaitExit
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
VMEMACCM_LOCAL FUNC(void, VMEMACCM_CODE) vMemAccM_SMCompareWaitExit(vMemAccM_SMStateContextPtrType ContextPtr)
{
  if((ContextPtr->Result == VMEMACCM_JOB_OK) || (ContextPtr->Result == VMEMACCM_READ_CORRECTED_ERRORS))
  {
    uint32 i;
    /* PRQA S 0316 1 */ /* MD_vMemAccM_VoidPtrTypedPtr */
    vMemAccM_Uint8ConstPtrType userBufferTyped = ((vMemAccM_Uint8PtrType)ContextPtr->Job.DataPtr);

#if (VMEMACCM_MULTI_PARTITION_SATELLITE == STD_ON)
    /* PRQA S 0315, 0316 1 */ /* MD_vMemAccM_VoidPtrTypedPtr */
    vMemAccM_SMMPSatellite_CopyData(vMemAccM_CfgAbMpGetSatelliteDataPtr(), vMemAccM_InternalBuffer,
        vMemAccM_GetReadLengthOfAddressArea(ContextPtr->Job.AddressAreaId)); /* SBSW_vMemAccM_MultiPartitionJobPointer */
#endif

    ContextPtr->Result = VMEMACCM_JOB_OK; /* SBSW_vMemAccM_SMContextPtr */
    for(i = 0u; i < ContextPtr->vMemNrOfBytes; i++)
    {
      if(userBufferTyped[ContextPtr->MgmtArea->Offset + i] != vMemAccM_InternalBuffer[i])
      {
        ContextPtr->Result = VMEMACCM_MEM_NOT_EQUAL; /* SBSW_vMemAccM_SMContextPtr */
        break;
      }
    }
  }
  else
  {
    ContextPtr->Result = VMEMACCM_JOB_FAILED; /* SBSW_vMemAccM_SMContextPtr */
  }
  /* Note: in case of different data the vMemAccM aborts processing immediately and therefore the offset is <
   * than the requested length => Do not use the "via offset" finalize function! */
  if(ContextPtr->Result == VMEMACCM_JOB_OK)
  {
    vMemAccM_SMFinalizeJobViaOffset(ContextPtr); /* SBSW_vMemAccM_SMContextPtr */
  }
  else
  {
    vMemAccM_SMFinalizeJob(ContextPtr); /* SBSW_vMemAccM_SMContextPtr */
  }
}

#endif /* (VMEMACCM_COMPARE_API == STD_ON) */

/**********************************************************************************************************************
 *  State machine: IsBlank
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  vMemAccM_SMIsBlankTransitionToIdle
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
VMEMACCM_LOCAL FUNC(void, VMEMACCM_CODE) vMemAccM_SMIsBlankTransitionToIdle(vMemAccM_SMStateContextPtrType ContextPtr)
{
  vMemAccM_SMIsBlankWaitExit(ContextPtr); /* SBSW_vMemAccM_SMContextPtr */
  ContextPtr->Job.SMFuncs.StateFuncPtr = vMemAccM_SMIsBlankIdleDo; /* SBSW_vMemAccM_SMContextPtr */
}

/**********************************************************************************************************************
 *  vMemAccM_SMIsBlankTransitionToWait
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
VMEMACCM_LOCAL FUNC(void, VMEMACCM_CODE) vMemAccM_SMIsBlankTransitionToWait(vMemAccM_SMStateContextPtrType ContextPtr)
{
  ContextPtr->Job.SMFuncs.StateFuncPtr = vMemAccM_SMIsBlankWaitDo; /* SBSW_vMemAccM_SMContextPtr */
}

/**********************************************************************************************************************
 *  vMemAccM_SMIsBlankIdleDo
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
VMEMACCM_LOCAL FUNC(boolean, VMEMACCM_CODE) vMemAccM_SMIsBlankIdleDo(vMemAccM_SMStateContextPtrType ContextPtr)
{
  vMemAccM_SubAddrAreaJobParamsType jobParams;
  vMemAccM_SMLibCalcJobParams(
    &jobParams, 
    ContextPtr->SubAddrAreaId,
    ContextPtr->Job.Address,
    ContextPtr->Job.Length,
    ContextPtr->MgmtArea->Offset
  ); /* SBSW_vMemAccM_LocalVarAsPtrFuncParam */
#if (VMEMACCM_MULTI_PARTITION_SATELLITE == STD_ON)
  vMemAccM_SMAdjustJobLength(&jobParams, vMemAccM_GetPageSizeOfSubAddressArea(ContextPtr->SubAddrAreaId)); /* SBSW_vMemAccM_LocalVarAsPtrFuncParam */
  vMemAccM_SMMPSatellite_PublishJobParameter(ContextPtr, &jobParams, ContextPtr->Job.JobType); /* SBSW_vMemAccM_LocalVarAsPtrFuncParam */
#else
  vMemAccM_MemAbIsBlank( /* SBSW_vMemAccM_SMContextPtr */
      ContextPtr->SubAddrAreaId, jobParams.Offset, jobParams.Length, &ContextPtr->vMemNrOfBytes);
#endif
  return vMemAccM_SMIdleFinalize(ContextPtr, vMemAccM_SMIsBlankTransitionToWait); /* SBSW_vMemAccM_SMContextPtr */
}

/**********************************************************************************************************************
 *  vMemAccM_SMIsBlankWaitDo
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
VMEMACCM_LOCAL FUNC(boolean, VMEMACCM_CODE) vMemAccM_SMIsBlankWaitDo(vMemAccM_SMStateContextPtrType ContextPtr)
{
  return vMemAccM_SMWaitDo(ContextPtr, vMemAccM_SMIsBlankTransitionToIdle); /* SBSW_vMemAccM_SMContextPtr */
}

/**********************************************************************************************************************
 *  vMemAccM_SMIsBlankWaitExit
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
VMEMACCM_LOCAL FUNC(void, VMEMACCM_CODE) vMemAccM_SMIsBlankWaitExit(vMemAccM_SMStateContextConstPtrType ContextPtr)
{
  if(ContextPtr->Result == VMEMACCM_JOB_OK)
  {
    vMemAccM_SMFinalizeJobViaOffset(ContextPtr); /* SBSW_vMemAccM_SMContextPtr */
  }
  else
  {
    vMemAccM_SMFinalizeJob(ContextPtr); /* SBSW_vMemAccM_SMContextPtr */
  }
}

#if (VMEMACCM_MULTI_PARTITION_SATELLITE == STD_OFF)
/**********************************************************************************************************************
 *  State machine: HwSpecific
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  vMemAccM_SMHwSpecificTransitionToIdle
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
VMEMACCM_LOCAL FUNC(void, VMEMACCM_CODE) vMemAccM_SMHwSpecificTransitionToIdle(vMemAccM_SMStateContextPtrType ContextPtr)
{
  vMemAccM_SMHwSpecificWaitExit(ContextPtr); /* SBSW_vMemAccM_SMContextPtr */
  ContextPtr->Job.SMFuncs.StateFuncPtr = vMemAccM_SMHwSpecificIdleDo; /* SBSW_vMemAccM_SMContextPtr */
}

/**********************************************************************************************************************
 *  vMemAccM_SMHwSpecificTransitionToWait
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
VMEMACCM_LOCAL FUNC(void, VMEMACCM_CODE) vMemAccM_SMHwSpecificTransitionToWait(vMemAccM_SMStateContextPtrType ContextPtr)
{
  ContextPtr->Job.SMFuncs.StateFuncPtr = vMemAccM_SMHwSpecificWaitDo; /* SBSW_vMemAccM_SMContextPtr */
}

/**********************************************************************************************************************
 *  vMemAccM_SMHwSpecificIdleDo
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
VMEMACCM_LOCAL FUNC(boolean, VMEMACCM_CODE) vMemAccM_SMHwSpecificIdleDo(vMemAccM_SMStateContextPtrType ContextPtr)
{
  /* Note: for HwSpecificReq we cannot apply the same handling as for the other asynchronous jobs.
   * For HwSpecificReq the passed Length could be 0 and thus the NrOfBytes accepted by vMem/MemAb
   * could be 0 but the job is not FAILED. */

  boolean smBusy = TRUE;
  if(vMemAccM_MemAbHWSpecificReq(ContextPtr->SubAddrAreaId, ContextPtr->Job.vMemHwSpecificFuncIndex, /* SBSW_vMemAccM_UserDataPointer */
    ContextPtr->Job.DataPtr, ContextPtr->Job.Length, &ContextPtr->vMemNrOfBytes) == E_OK)
  {
    vMemAccM_SMHwSpecificTransitionToWait(ContextPtr); /* SBSW_vMemAccM_SMContextPtr */
  }
  else
  {
    ContextPtr->Result = VMEMACCM_JOB_FAILED; /* SBSW_vMemAccM_SMContextPtr */
    vMemAccM_SMFinalizeJob(ContextPtr); /* SBSW_vMemAccM_SMContextPtr */
    smBusy = FALSE;
    /* No job setup, vMem idle: No Transition, keep state! */
  }

  return smBusy;
}

/**********************************************************************************************************************
 *  vMemAccM_SMHwSpecificWaitDo
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
VMEMACCM_LOCAL FUNC(boolean, VMEMACCM_CODE) vMemAccM_SMHwSpecificWaitDo(vMemAccM_SMStateContextPtrType ContextPtr)
{
  return vMemAccM_SMWaitDo(ContextPtr, vMemAccM_SMHwSpecificTransitionToIdle); /* SBSW_vMemAccM_SMContextPtr */
}

/**********************************************************************************************************************
 *  vMemAccM_SMHwSpecificWaitExit
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
VMEMACCM_LOCAL FUNC(void, VMEMACCM_CODE) vMemAccM_SMHwSpecificWaitExit(vMemAccM_SMStateContextConstPtrType ContextPtr)
{
  if(ContextPtr->Result == VMEMACCM_JOB_OK)
  {
    vMemAccM_SMFinalizeJobViaOffset(ContextPtr); /* SBSW_vMemAccM_SMContextPtr */
  }
  else
  {
    vMemAccM_SMFinalizeJob(ContextPtr); /* SBSW_vMemAccM_SMContextPtr */
  }
}
#endif /* (VMEMACCM_MULTI_PARTITION_SATELLITE == STD_OFF) */

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  vMemAccM_SMDefaultInit
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, VMEMACCM_CODE) vMemAccM_SMDefaultInit(vMemAccM_SMFunctionsPtrType SMFuncsPtr)
{
  SMFuncsPtr->StateFuncPtr = vMemAccM_SMDefaultState; /* SBSW_vMemAccM_SMFuncPtr */
}

/**********************************************************************************************************************
 *  vMemAccM_SMWriteInit
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, VMEMACCM_CODE) vMemAccM_SMWriteInit(vMemAccM_SMFunctionsPtrType SMFuncsPtr)
{
  SMFuncsPtr->StateFuncPtr = vMemAccM_SMWriteIdleDo; /* SBSW_vMemAccM_SMFuncPtr */
}

/**********************************************************************************************************************
 *  vMemAccM_SMEraseInit
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, VMEMACCM_CODE) vMemAccM_SMEraseInit(vMemAccM_SMFunctionsPtrType SMFuncsPtr)
{
  SMFuncsPtr->StateFuncPtr = vMemAccM_SMEraseIdleDo; /* SBSW_vMemAccM_SMFuncPtr */
}

/**********************************************************************************************************************
 *  vMemAccM_SMReadInit
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, VMEMACCM_CODE) vMemAccM_SMReadInit(vMemAccM_SMFunctionsPtrType SMFuncsPtr)
{
  SMFuncsPtr->StateFuncPtr = vMemAccM_SMReadIdleDo; /* SBSW_vMemAccM_SMFuncPtr */
}

/**********************************************************************************************************************
 *  vMemAccM_SMReadBlankInit
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, VMEMACCM_CODE) vMemAccM_SMReadBlankInit(vMemAccM_SMFunctionsPtrType SMFuncsPtr)
{
  SMFuncsPtr->StateFuncPtr = vMemAccM_SMReadBlankIdleDo; /* SBSW_vMemAccM_SMFuncPtr */
}

#if (VMEMACCM_COMPARE_API == STD_ON)
/**********************************************************************************************************************
 *  vMemAccM_SMCompareInit
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, VMEMACCM_CODE) vMemAccM_SMCompareInit(vMemAccM_SMFunctionsPtrType SMFuncsPtr)
{
  SMFuncsPtr->StateFuncPtr = vMemAccM_SMCompareIdleDo; /* SBSW_vMemAccM_SMFuncPtr */
}
#endif /* (VMEMACCM_COMPARE_API == STD_ON) */

/**********************************************************************************************************************
 *  vMemAccM_SMIsBlankInit
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, VMEMACCM_CODE) vMemAccM_SMIsBlankInit(vMemAccM_SMFunctionsPtrType SMFuncsPtr)
{
  SMFuncsPtr->StateFuncPtr = vMemAccM_SMIsBlankIdleDo; /* SBSW_vMemAccM_SMFuncPtr */
}

#if (VMEMACCM_MULTI_PARTITION_SATELLITE == STD_OFF)
/**********************************************************************************************************************
 *  vMemAccM_SMHwSpecificInit
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, VMEMACCM_CODE) vMemAccM_SMHwSpecificInit(vMemAccM_SMFunctionsPtrType SMFuncsPtr)
{
  SMFuncsPtr->StateFuncPtr = vMemAccM_SMHwSpecificIdleDo; /* SBSW_vMemAccM_SMFuncPtr */
}
#endif /* (VMEMACCM_MULTI_PARTITION_SATELLITE == STD_OFF) */

/**********************************************************************************************************************
 *  vMemAccM_SMMainFunction
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, VMEMACCM_CODE) vMemAccM_SMMainFunction(vMemAccM_SMStateContextPtrType ContextPtr)
{
  while(ContextPtr->Job.SMFuncs.StateFuncPtr(ContextPtr) == TRUE) /* SBSW_vMemAccM_SMFuncPtr */
  {
    /* Nothing to do, simply trigger the state machine until it is not busy any more. */
  }
}

#define VMEMACCM_STOP_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#endif /* (VMEMACCM_MINIMAL_SYNC == STD_OFF) */

/**********************************************************************************************************************
 *  END OF FILE: vMemAccM_StateMachines.c
 *********************************************************************************************************************/
