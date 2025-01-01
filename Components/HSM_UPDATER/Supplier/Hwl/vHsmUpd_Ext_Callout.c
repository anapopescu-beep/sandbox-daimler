/**********************************************************************************************************************
  COPYRIGHT
-----------------------------------------------------------------------------------------------------------------------
-----------------------------------------------------------------------------------------------------------------------
  FILE DESCRIPTION
-----------------------------------------------------------------------------------------------------------------------
  \file  File:  _vHsmUpd_Ext_Callout.h
      Project:  vHsmUpd_Ext_Vector
       Module:  vHsmUpd_Ext_Vector

  \brief Description:   This file contains a template implementation for some callouts, which needs no special 
                        implementation.
**********************************************************************************************************************/

#define VHSMUPD_EXT_CALLOUT_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "vHsmUpd_Ext_Callout.h"
/**********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

#define VHSMUPD_EXT_START_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FUNC(void, VHSMUPD_EXT_CODE) vHsmUpd_Ext_StateCallbackNotification_Callout(vHsmUpd_Ext_IpcUpdateStateType currentState)
{
  /* No implementation needed. You can implement a host comunication to inform the host about the update state. */
}

FUNC(void, VHSMUPD_EXT_CODE) vHsmUpd_Ext_WaitForHost_Callout(vHsmUpd_Ext_BooleanPtrType waitForHostVariable)
{
  /* No implementation needed. */
}

FUNC(boolean, VHSMUPD_EXT_CODE)
vHsm_FirmwareUpdate_VersionCompare_Callout(
    uint32 currentUpdateHeaderVersion,
    uint32 maxVersionOnActivePartition,
    uint32 maxVersionOnInactivePartition)
{
  return TRUE;
}

#define VHSMUPD_EXT_STOP_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
