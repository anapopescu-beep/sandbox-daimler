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
/*!        \file  vMemAccM_SchedSync.h
 *        \brief  vMemAccM synchronous job scheduler sub module header file
 *
 *      \details  The vMemAccM synchronous job scheduler sub component implements the synchronous processing
 *                of a minimal vMemAccM.
 *
 *         \unit  vMemAccM_SchedSync
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 *********************************************************************************************************************/

#if !defined (VMEMACCM_SCHEDSYNC_H)
# define VMEMACCM_SCHEDSYNC_H

/***********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/
 
#include "vMemAccM_Types.h"
#include "vMemAccM_IntCfg.h"
#include "vMemAccM_SMTypes.h"

#if (VMEMACCM_MINIMAL_SYNC == STD_ON)

/***********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 **********************************************************************************************************************/
# define VMEMACCM_UNINIT                              (0x0u)
# define VMEMACCM_INIT                                (0x1u)

# define VMEMACCM_MNGMTAREA_SIZE vMemAccM_GetSizeOfAddressArea()


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/


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

/* Following function prototypes does have "Sched" instead of the expected "SchedSync" as Name prefix, 
   because either this unit or the default "Sched" unit is used, function replaces each other. */

# define VMEMACCM_START_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  vMemAccM_SchedInit
 *********************************************************************************************************************/
/*!
 * \brief       Initialize the synchronous scheduler submodule.
 * \details     -
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */
FUNC(void, VMEMACCM_CODE) vMemAccM_SchedInit(void);

/**********************************************************************************************************************
 *  vMemAccM_SchedQueueJob
 *********************************************************************************************************************/
/*!
 * \brief         For synchronous scheduler: Within this function the job will be immediately executed synchronously.
 * \details       -
 * \param[in]     JobType identifying the job as read, write, erase or blankcheck job.
 * \param[in]     AddressAreaId as array index, used to access the virtual information.
 * \param[in]     Address pointing to the first byte of the request (virtual address space).
 * \param[in]     DataPtr pointing to the job buffer. Parameter must not be NULL_PTR. (in for write, out for read)
 * \param[in]     Length of the data in bytes.
 * \return        Always E_OK: Job was executed;
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
 *  vMemAccM_SchedMainFunction
 *********************************************************************************************************************/
/*!
 * \brief       Dummy function for compatibility reasons.
 * \details     -
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */
FUNC(void, VMEMACCM_CODE) vMemAccM_SchedMainFunction(void);


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
 *  vMemAccM_SchedIsAddressAreaPending
 *********************************************************************************************************************/
/*!
 * \brief       Check whether the passed address area is in pending state.
 * \details     -
 * \param[in]   AddressAreaId as array index, used to access the virtual information.
 * \return      TRUE, if the address area is pending;
 *              FALSE otherwise.
 * \pre         VMEMACCM_DEV_ERROR_DETECT == STD_ON
 * \context     ANY
 * \reentrant   FALSE
 * \synchronous TRUE
 */
FUNC(boolean, VMEMACCM_CODE) vMemAccM_SchedIsAddressAreaPending(vMemAccM_AddressAreaIdType AddressAreaId);
#endif

# define VMEMACCM_STOP_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */  /* MD_MSR_MemMap */

# endif /* (VMEMACCM_MINIMAL_SYNC == STD_ON) */

#endif /* VMEMACCM_SCHEDSYNC_H */

/**********************************************************************************************************************
 *  END OF FILE: vMemAccM_SchedSync.h
 *********************************************************************************************************************/
