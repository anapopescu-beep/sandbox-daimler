/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2021 by Vector Informatik GmbH.                                              All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/*!        \file  vHsmUpd_Ext_Ipc.h
 *        \brief  Extension header file for the ipc handling. Functions must be implemented in extension implementation.
 *
 *      \details  Header file for the Extension callouts.
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 *********************************************************************************************************************/

#ifndef VHSMUPD_EXT_IPC_H
#define VHSMUPD_EXT_IPC_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "vHsmUpd_Ext_Types.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
typedef enum
{
  vHsmUpd_Ext_HsmToHostReady = 0u,        /*!< Represents the bit position for the Ready signal of the Hsm */
  vHsmUpd_Ext_HsmToHostAvailable = 1u,    /*!< Represents the bit position for the Available signal of the Hsm */
  vHsmUpd_Ext_HsmToHostUpdRunning = 15u   /*!< Represents the bit position for the signal that indicates that vHsmUpd is running. */
} vHsmUpd_Ext_IpcHsmStateShiftValuesType; /*!< Type used for the mandatory Ipc communication between Hsm and Host. Write from Hsm */

typedef enum
{
  vHsmUpd_Ext_HostToHsmIpcInitialized = VHSMUPD_EXT_IPC_WAIT_MASK  /*!< Represents the wait mask for the Ipc initialized signal of the Host */
} vHsmUpd_Ext_IpcHostStateValuesType; /*!< Type used for the mandatory Ipc communication between Host and Hsm. Write from Host */

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
# define VHSMUPD_EXT_START_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  vHsmUpd_Ext_ClearHsmState()
 *********************************************************************************************************************/
/*!
 * \brief       This function clears the given state of the Hsm.
 * \details     -
 * \param[in]   state is the Hsm state which shall be cleared.
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */
FUNC(void, VHSMUPD_EXT_CODE) vHsmUpd_Ext_ClearHsmState(vHsmUpd_Ext_IpcHsmStateShiftValuesType state);

/**********************************************************************************************************************
 *  vHsmUpd_Ext_IsHostStateSet()
 *********************************************************************************************************************/
/*!
 * \brief       This function checks whether the given state of the Host is set.
 * \details     -
 * \return      TRUE if the Host state is set and otherwise FALSE
 * \param[in]   state       is the current state to check for.
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */
FUNC(boolean, VHSMUPD_EXT_CODE) vHsmUpd_Ext_IsHostStateSet(vHsmUpd_Ext_IpcHostStateValuesType state);

/**********************************************************************************************************************
 *  vHsmUpd_Ext_IsHsmStateSet()
 *********************************************************************************************************************/
/*!
 * \brief       This function checks whether the given state of the Hsm is set.
 * \details     -
 * \return      E_OK if the Hsm state is set and otherwise E_NOT_OK
 * \param[in]   state       is the current state to check for.
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */
FUNC(Std_ReturnType, VHSMUPD_EXT_CODE) vHsmUpd_Ext_IsHsmStateSet(vHsmUpd_Ext_IpcHsmStateShiftValuesType state);

/**********************************************************************************************************************
 *  vHsmUpd_Ext_SetHsmState()
 *********************************************************************************************************************/
/*!
 * \brief       This function sets the given state of the Hsm.
 * \details     -
 * \param[in]   state       is the Hsm state which shall be set
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */
FUNC(void, VHSMUPD_EXT_CODE) vHsmUpd_Ext_SetHsmState(vHsmUpd_Ext_IpcHsmStateShiftValuesType state);

# define VHSMUPD_EXT_STOP_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */  /* MD_MSR_MemMap */

#endif /* VHSMUPD_EXT_IPC_H */

/**********************************************************************************************************************
 *  END OF FILE: vHsmUpd_Ext_Ipc.h
 *********************************************************************************************************************/
