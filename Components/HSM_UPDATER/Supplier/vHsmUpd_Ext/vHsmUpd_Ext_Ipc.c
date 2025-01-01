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
/*!        \file  vHsmUpd_Ext_Ipc.c
 *        \brief  vHsmUpd_Ipc source file
 *
 *      \details  see vHsmUpd_Ipc.h
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 *

 *********************************************************************************************************************/

#define VHSMUPD_EXT_IPC_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "vHsmUpd_Ext_Private.h"

/**********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTION MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
#if !defined (VHSMUPD_EXT_LOCAL) /* COV_VHSMUPD_EXT_COMPATIBILITY */
# define VHSMUPD_EXT_LOCAL static
#endif

#if !defined (VHSMUPD_EXT_LOCAL_INLINE) /* COV_VHSMUPD_EXT_COMPATIBILITY */
# define VHSMUPD_EXT_LOCAL_INLINE LOCAL_INLINE
#endif

#define VHSMUPD_EXT_START_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define VHSMUPD_EXT_HSM_TO_HOST_REG                 (*(volatile uint32 *) (VHSMUPD_EXT_IPC_HSM_TO_HOST))
#define VHSMUPD_EXT_HOST_TO_HSM_REG                 (*(volatile uint32 *) (VHSMUPD_EXT_IPC_HOST_TO_HSM))

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
 *  vHsmUpd_GetMaskForIpcState()
 *********************************************************************************************************************/
/*!
 * \brief       This function returns the bit mask of the current state given as uint32 value.
 * \details     -
 * \param[in]   state is the current state of the Hsm or the Host.
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */
VHSMUPD_EXT_LOCAL_INLINE FUNC(uint32, VHSMUPD_EXT_CODE) vHsmUpd_GetMaskForIpcState(uint32 state);

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/
/**********************************************************************************************************************
 *  vHsmUpd_GetMaskForIpcState()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
VHSMUPD_EXT_LOCAL_INLINE FUNC(uint32, VHSMUPD_EXT_CODE) vHsmUpd_GetMaskForIpcState(uint32 state)
{
  /* Shift the 1bit value to the corresponding bit position in the Hsm or Host state type
   * in vHsmUpd_Ext_IpcHsmStateShiftValuesType or vHsmUpd_Ext_IpcHostStateShiftValuesType. Each of these
   * values represents a state. */
  /* #10 Returns the mask of the state requested (just the state bit is 1 others are zero) */
  return ((uint32)1u << state);
}

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/
/**********************************************************************************************************************
 *  vHsmUpd_Ext_StateCallbackNotification()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, VHSMUPD_EXT_CODE) vHsmUpd_Ext_StateCallbackNotification(vHsmUpd_Ext_IpcUpdateStateType currentState) /* PRQA S 3206 */ /* MD_vHsmUpd_Ext_HwConfDependentClause */
{
  vHsmUpd_Ext_StateCallbackNotification_Callout(currentState);
}

/**********************************************************************************************************************
 *  vHsmUpd_Ext_IsHostStateSet()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(boolean, VHSMUPD_EXT_CODE) vHsmUpd_Ext_IsHostStateSet(vHsmUpd_Ext_IpcHostStateValuesType state)
{
  /* #10 Check if the IPC address, which shall indicate the Host status (Host to Hsm), contains the state to check
   * and return true in that case */
  return ((VHSMUPD_EXT_HOST_TO_HSM_REG & ((uint32)state)) == /* PRQA S 0306, 0303 */ /* MD_vHsmUpd_Ext_MemoryAccess */
      (uint32)state) ? TRUE : FALSE;
}

/**********************************************************************************************************************
 *  vHsmUpd_Ext_IsHsmStateSet()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(Std_ReturnType, VHSMUPD_EXT_CODE) vHsmUpd_Ext_IsHsmStateSet(vHsmUpd_Ext_IpcHsmStateShiftValuesType state)
{
  Std_ReturnType retVal = E_NOT_OK;
  /* #10 Check if the IPC address, which shall indicate the Hsm status (Hsm to Host), contains the state bit to check
   * and return true in that case */

  if((VHSMUPD_EXT_HSM_TO_HOST_REG & (vHsmUpd_GetMaskForIpcState((uint32)state))) == /* PRQA S 0306, 0303 */ /* MD_vHsmUpd_Ext_MemoryAccess */
      vHsmUpd_GetMaskForIpcState((uint32)state))
  {
    retVal = E_OK;
  }

  return retVal;
}

/**********************************************************************************************************************
 *  vHsmUpd_Ext_ClearHsmState()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(void, VHSMUPD_EXT_CODE) vHsmUpd_Ext_ClearHsmState(vHsmUpd_Ext_IpcHsmStateShiftValuesType state)
{
  /* HW independent solution for a HW dependent problem: Write 0 to clear the register and check if the bit is cleared.
   * If still not cleared write 1 to the register to clear it now. More possibilities do not exist for current vHsm(s) */
  /* #10 Write 0 to the Hsm to Host memory */
  VHSMUPD_EXT_HSM_TO_HOST_REG &= ~(vHsmUpd_GetMaskForIpcState((uint32)state)); /* PRQA S 0306, 0303 */ /* MD_vHsmUpd_Ext_MemoryAccess */

  /* #20 Check if the state is still set. If yes write the 1 value to the bit location to clear it */
  if( vHsmUpd_Ext_IsHsmStateSet(state) == E_OK )
  {
    vHsmUpd_Ext_SetHsmState(state);
  }
}

/**********************************************************************************************************************
 *  vHsmUpd_Ext_SetHsmState()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, VHSMUPD_EXT_CODE) vHsmUpd_Ext_SetHsmState(vHsmUpd_Ext_IpcHsmStateShiftValuesType state)
{
  /* #10 Write 1 to the Hsm to Host memory */
  VHSMUPD_EXT_HSM_TO_HOST_REG |= vHsmUpd_GetMaskForIpcState((uint32)state); /* PRQA S 0306, 0303 */ /* MD_vHsmUpd_Ext_MemoryAccess */
}

#define VHSMUPD_EXT_STOP_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  END OF FILE: vHsmUpd_Ext_Ipc.c
 *********************************************************************************************************************/
