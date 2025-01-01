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
/*!        \file  vMemAccM_ErrorNotification.h
 *        \brief  vMemAccM header file.
 *      \details  vMemAccM header file providing the ErrorNotification declaration. The user/ caller has to include
 *                this file only.
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 *********************************************************************************************************************/

#if !defined (VMEMACCM_ERRORNOTIFICATION_H)
# define VMEMACCM_ERRORNOTIFICATION_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
# include "vMemAccM_Types.h"

#if (VMEMACCM_MINIMAL_SYNC == STD_OFF)

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
# define VMEMACCM_START_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * vMemAccM_ErrorNotification()
 *********************************************************************************************************************/
/*!
 * \brief       Notifies vMemAccM about a specific error occurred during the execution of a vMem job.
 * \details     The function is meant to be used to notify the vMem about specific errors, which cannot be checked/
 *              reported by the vMem. For example the ECC correctable and uncorrectable errors.
 *              The function can be called from any context - a task, or even a ECC interrupt.
 * \param[in]   AddressAreaId as array index, used to access the virtual information.
 * \param[in]   Address pointing to the byte causing the Result (virtual address space).
 * \param[in]   Result to be combined with the actual vMem job result.
 * \return      E_OK job accepted and the Result stored internally.
 *              E_NOT_OK otherwise.
 * \pre         -
 * \context     ANY
 * \reentrant   FALSE
 * \synchronous TRUE
 * \trace       CREQ-204402
 */
FUNC(Std_ReturnType, VMEMACCM_CODE) vMemAccM_ErrorNotification
(
  vMemAccM_AddressAreaIdType AddressAreaId,
  vMemAccM_AddressType Address,
  vMemAccM_ErrorNotifResultType Result
);

# define VMEMACCM_STOP_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#endif /* (VMEMACCM_MINIMAL_SYNC == STD_OFF) */

#endif /* VMEMACCM_ERRORNOTIFICATION_H */

/**********************************************************************************************************************
 *  END OF FILE: vMemAccM_ErrorNotification.h
 *********************************************************************************************************************/
