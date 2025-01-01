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
/*!        \file  vMemAccM_Sched.h
 *        \brief  vMemAccM job scheduler sub module header file
 *
 *      \details  The vMemAccM job scheduler sub component implements a simple queue mechanism where each address area
 *                has a queue entry. Position within the queue is the address area priority. An internal variable
 *                points to the highest priority address area - priority based processing.
 *                Current implementation does not care about jobs stacking within the queue because of low priority,
 *                or similar queue problems.
 *                The vMemAccM job scheduler sub component implements the asynchronous prosessing.
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 *********************************************************************************************************************/

#if !defined (VMEMACCM_SCHED_H)
# define VMEMACCM_SCHED_H

#include "vMemAccM_Types.h"
#include "vMemAccM_IntCfg.h"
#include "vMemAccM_SMTypes.h"

#if (VMEMACCM_MINIMAL_SYNC == STD_OFF)

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
# define VMEMACCM_MNGMTAREA_SIZE vMemAccM_GetSizeOfAddressArea()

# define VMEMACCM_UNINIT                              (0x0u)
# define VMEMACCM_INIT                                (0x1u)


/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/
#define VMEMACCM_START_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern VAR(vMemAccM_MngmtAreaType, VMEMACCM_VAR_NOINIT) vMemAccM_MngmtAreas[VMEMACCM_MNGMTAREA_SIZE];

#define VMEMACCM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

# define VMEMACCM_START_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  vMemAccM_SchedInit
 *********************************************************************************************************************/
/*!
 * \brief       Initialize the scheduler submodule.
 * \details     -
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */
FUNC(void, VMEMACCM_CODE) vMemAccM_SchedInit(void);

#if (VMEMACCM_MULTI_PARTITION_SATELLITE == STD_OFF)
/**********************************************************************************************************************
 *  vMemAccM_SchedQueueHwSpecificJob
 *********************************************************************************************************************/
/*!
 * \brief       Queues a new HW specific job for passed address area.
 * \details     -
 * \param[in]   JobType identifying the job to be a hardware specific one.
 * \param[in]   AddressAreaId as array index, used to access the virtual information.
 * \param[in]   HwId pointing to the hardware driver the job shall be forwarded to.
 * \param[in]   DataPtr holding the hardware specific data to be forwarded to the hardware driver.
 * \param[in]   DataSize of the data in bytes.
 * \param[in]   vMemHwSpecificFuncIndex as an array index pointing to the hardware specific function pointer.
 * \return      E_OK job was queued;
 *              E_NOT_OK otherwise.
 * \pre         vMemAccM is not the multi partition satellite.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */
FUNC(Std_ReturnType, VMEMACCM_CODE) vMemAccM_SchedQueueHwSpecificJob
(
  vMemAccM_JobType JobType,
  vMemAccM_AddressAreaIdType AddressAreaId,
  vMemAccM_HwIdType HwId,
  vMemAccM_DataPtrType DataPtr,
  vMemAccM_LengthType DataSize,
  vMemAccM_vMemHwSpecificFuncIndexType vMemHwSpecificFuncIndex
);
#endif /* (VMEMACCM_MULTI_PARTITION_SATELLITE == STD_OFF) */

/**********************************************************************************************************************
 *  vMemAccM_SchedQueueJob
 *********************************************************************************************************************/
/*!
 * \brief         Queues a new job for passed address area.
 * \details       -
 * \param[in]     JobType identifying the job as read, write, erase or compare job.
 * \param[in]     AddressAreaId as array index, used to access the virtual information.
 * \param[in]     Address pointing to the first byte of the request (virtual address space).
 * \param[in] DataPtr pointing to the job buffer. Parameter must not be NULL_PTR. (in for write and compare, out for read)
 * \param[in]     Length of the data in bytes.
 * \return        E_OK job was queued;
 *                E_NOT_OK otherwise.
 * \pre           -
 * \context       TASK
 * \reentrant     FALSE
 * \synchronous   TRUE
 */
FUNC(Std_ReturnType, VMEMACCM_CODE) vMemAccM_SchedQueueJob
(
  vMemAccM_JobType JobType,
  vMemAccM_AddressAreaIdType AddressAreaId,
  vMemAccM_AddressType Address,
  vMemAccM_DataPtrType DataPtr,
  vMemAccM_LengthType Length
);

/**********************************************************************************************************************
 *  vMemAccM_SchedQueueRemoveJob
 *********************************************************************************************************************/
/*!
 * \brief       Removes the AddressAreaId job from queue.
 * \details     -
 * \param[in]   AddressAreaId as array index, used to access the virtual information.
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */
FUNC(void, VMEMACCM_CODE) vMemAccM_SchedQueueRemoveJob(vMemAccM_AddressAreaIdType AddressAreaId);

/**********************************************************************************************************************
 *  vMemAccM_SchedMainFunction
 *********************************************************************************************************************/
/*!
 * \brief       Processes the vMemAccM state machines.
 * \details     Returns when vMemAccM is waiting for vMem or the job step is done, or even nothing to do (empty queue).
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */
FUNC(void, VMEMACCM_CODE) vMemAccM_SchedMainFunction(void);

/**********************************************************************************************************************
 *  vMemAccM_SchedCancelJob
 *********************************************************************************************************************/
/*!
 * \brief       Cancels the job of the passed AddressAreaId.
 * \details     -
 * \param[in]   AddressAreaId as array index, used to access the virtual information.
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */
FUNC(void, VMEMACCM_CODE) vMemAccM_SchedCancelJob(vMemAccM_AddressAreaIdType AddressAreaId);

/**********************************************************************************************************************
 *  vMemAccM_SchedSetErrorNotifResult
 *********************************************************************************************************************/
/*!
 * \brief       Stores the passed result within the current job storage.
 * \details     First the preconditions will be checked: is the address area active? does the address match the current
 *              active step? etc. Only if all the preconditions match, the result will be stored internally.
 * \param[in]   AddressAreaId as array index, used to access the virtual information.
 * \param[in]   Address as the virtual address.
 * \param[in]   Result as the result provided via Error Notification. Will be use to calculate the actual read step result.
 * \param[in]   JobType marking the job the ErrorNotification was called for. Currently only read jobs possible/ used.
 * \return      TRUE the passed result was stored internally (request accepted);
 *              FALSE otherwise.
 * \pre         -
 * \context     ANY
 * \reentrant   FALSE
 * \synchronous TRUE
 */
FUNC(boolean, VMEMACCM_CODE) vMemAccM_SchedSetErrorNotifResult
(
  vMemAccM_AddressAreaIdType AddressAreaId,
  vMemAccM_AddressType Address,
  vMemAccM_JobResultType Result,
  vMemAccM_JobType JobType
);

/**********************************************************************************************************************
 * vMemAccM_SchedGetState
 *********************************************************************************************************************/
/*!
 * \brief       Writes the information about the current state of an address area to the state structure.
 * \details     Internal function to provide the needed information to the public API. Parameter already checked within
 *              the API, this function only fills the structure.
 * \param[in]   AddressArea Identifier of the address area to be checked.
 * \param[out]  StatePtr pointing to a structure of type vMemAccM_StateType. Has to be valid.
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */
FUNC(void, VMEMACCM_CODE) vMemAccM_SchedGetState
(
  vMemAccM_AddressAreaIdType AddressAreaId,
  vMemAccM_StatePtrType StatePtr
);

#if (VMEMACCM_DEV_ERROR_DETECT == STD_ON)
/**********************************************************************************************************************
 *  vMemAccM_SchedIsInitialized
 *********************************************************************************************************************/
/*!
 * \brief       Checks the vMemAccM module to be initialized.
 * \details     -
 * \return      TRUE, if the module is initialized;
 *              FALSE otherwise.
 * \pre         VMEMACCM_DEV_ERROR_DETECT == STD_ON
 * \context     ANY
 * \reentrant   FALSE
 * \synchronous TRUE
 */
FUNC(boolean, VMEMACCM_CODE) vMemAccM_SchedIsInitialized(void);

/**********************************************************************************************************************
 *  vMemAccM_SchedSetInitState
 *********************************************************************************************************************/
/*!
 * \brief       Set initialization state of module
 * \details     -
 * \param[in]   InitState as state which shall be set.
 * \pre         VMEMACCM_DEV_ERROR_DETECT == STD_ON
 * \context     ANY
 * \reentrant   FALSE
 * \synchronous TRUE
 */
FUNC(void, VMEMACCM_CODE) vMemAccM_SchedSetInitState(uint8 InitState);

/**********************************************************************************************************************
 *  vMemAccM_SchedIsVariantAddressAreaPending
 *********************************************************************************************************************/
/*!
 * \brief       Check whether any variant address area is pending.
 * \details     -
 * \return      TRUE, if any variant address area is pending;
 *              FALSE otherwise.
 * \pre         VMEMACCM_DEV_ERROR_DETECT == STD_ON
 * \context     ANY
 * \reentrant   FALSE
 * \synchronous TRUE
 */
FUNC(boolean, VMEMACCM_CODE) vMemAccM_SchedIsVariantAddressAreaPending(void);

/**********************************************************************************************************************
 *  vMemAccM_SchedIsAddressAreaPending
 *********************************************************************************************************************/
/*!
 * \brief       Check whether the passed address area is in pending state.
 * \details     -
 * \param[in]   AddressAreaId as array index, used to access the virtual information.
 * \return      TRUE, of the address area is pending;
 *              FALSE otherwise.
 * \pre         VMEMACCM_DEV_ERROR_DETECT == STD_ON
 * \context     ANY
 * \reentrant   FALSE
 * \synchronous TRUE
 */
FUNC(boolean, VMEMACCM_CODE) vMemAccM_SchedIsAddressAreaPending(vMemAccM_AddressAreaIdType AddressAreaId);
#endif

/**********************************************************************************************************************
 *  vMemAccM_SchedIsAnyAddressAreaPending
 *********************************************************************************************************************/
/*!
 * \brief       Check whether any address area is pending.
 * \details     -
 * \return      TRUE, if any address area is pending;
 *              FALSE otherwise.
 * \pre         -
 * \context     ANY
 * \reentrant   FALSE
 * \synchronous TRUE
 */
FUNC(boolean, VMEMACCM_CODE) vMemAccM_SchedIsAnyAddressAreaPending(void);

# define VMEMACCM_STOP_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */  /* MD_MSR_MemMap */

#endif /* (VMEMACCM_MINIMAL_SYNC == STD_OFF) */

#endif /* VMEMACCM_SCHED_H */

/**********************************************************************************************************************
 *  END OF FILE: vMemAccM_Sched.h
 *********************************************************************************************************************/
