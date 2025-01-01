/**********************************************************************************************************************
* BETA MODULE
* -------------------------------------------------------------------------------------------------------------------
Beta Modules and Beta Features are basically operable, but not sufficiently tested, verified and/or qualified for 
use in series production and/or in vehicles operating on public or non-public roads. Please consult the Product
Information for details.
*********************************************************************************************************************/

/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2019 by Vector Informatik GmbH.                                                  All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/*!        \file  _vHsmUpd_Hal_CalloutHw.c
 *        \brief  Template file for platform specific callout implementation. Must be modified by the user to specific
 *                needs.
 *
 *      \details  -
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 * 
 *  FILE VERSION
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the VERSION CHECK below.
 *********************************************************************************************************************/

#define VHSMUPD_HAL_CALLOUT_HW_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "vHsmUpd_Callout.h"

#define VHSMUPD_HAL_START_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
/**********************************************************************************************************************
 *  vHsm_FirmwareUpdate_Update_Callout()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(Std_ReturnType, VHSMUPD_CODE) vHsm_FirmwareUpdate_Update_Callout(void)
{
  /* #10 Start Host Core by signal the SSW that the HSM is ready */
  /* HSMBRIDGE HSM2HTF Register */
  *((uint32*)(0xF0040000uL + 0x28u)) = 1u;
  /* Hints for the implementation of this callout: If the Host is configured to wait for the SSW the above
   * implementation sets the flag so the Host can starts its user-software.
   * Should the device be configured that the SSW does not wait for the HSM to set this flag, the Host already
   * runs, so the callout should "reset" the application so that the Host is in a safe state to update the 
   * vHsm software.
   *  */
#error "Example code: this implementation must be checked by the user. If sufficient just remove this line!"
  return E_OK;
}

#define VHSMUPD_HAL_STOP_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  END OF FILE: _vHsmUpd_Hal_CalloutHw.c
 *********************************************************************************************************************/
