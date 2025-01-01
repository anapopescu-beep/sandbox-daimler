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
/*!        \file  vHsmUpd.c
 *        \brief  vHsmUpd source file
 *
 *      \details  see vHsmUpd.h
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

#define VHSMUPD_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "vHsmUpd.h"
#include "vHsmUpd_MemAb.h"
#include "vHsmUpd_Ext.h"

/**********************************************************************************************************************
 *  VERSION CHECK
 *********************************************************************************************************************/
/* Check the version of vHsmUpd header file */
#if (  (VHSMUPD_SW_MAJOR_VERSION != (2u)) \
    || (VHSMUPD_SW_MINOR_VERSION != (1u)) \
    || (VHSMUPD_SW_PATCH_VERSION != (0u)) )
# error "Vendor specific version numbers of vHsmUpd.c and vHsmUpd.h are inconsistent"
#endif

/**********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA PROTOTYPES
 *********************************************************************************************************************/
/**********************************************************************************************************************
 *  LOCAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
#if !defined (VHSMUPD_LOCAL) /* COV_VHSMUPD_COMPATIBILITY */
# define VHSMUPD_LOCAL static
#endif

#if !defined (VHSMUPD_LOCAL_INLINE) /* COV_VHSMUPD_COMPATIBILITY */
# define VHSMUPD_LOCAL_INLINE LOCAL_INLINE
#endif

#define VHSMUPD_START_SEC_CONST_8BIT
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

VHSMUPD_LOCAL CONST(boolean, AUTOMATIC) vHsmUpd_AlwaysTrue = TRUE;  /* PRQA S 1514, 3218 */ /* MD_vHsmUpd_ConstConfigData */

#define VHSMUPD_STOP_SEC_CONST_8BIT
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
#define VHSMUPD_START_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  vHsmUpd_Update()
 *********************************************************************************************************************/
/*!
 * \brief       Defines the update steps, which should be processed for the update.
 * \details     Defines three steps, which are implemented in the used extension.
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */
VHSMUPD_LOCAL_INLINE FUNC(void, VHSMUPD_CODE) vHsmUpd_Update(void);

#define VHSMUPD_STOP_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/
#define VHSMUPD_START_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  vHsmUpd_Update()
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
VHSMUPD_LOCAL_INLINE FUNC(void, VHSMUPD_CODE) vHsmUpd_Update(void)
{

  /* Write update in progress to shared memory location */
  vHsmUpd_Ext_StateCallbackNotification(VHSMUPD_UPDATE_IN_PROGRESS);

  /* Start the verfication and preparation of the update image */
  if(vHsmUpd_Ext_PrepareAndVerifyUpdate() == E_NOT_OK)
  {
    /* Nothing to do on Error */
  }
  /* Processing of the single update parts */
  else if(vHsmUpd_Ext_ProcessUpdateParts() == E_NOT_OK)
  {
    /* Nothing to do on Error */
  }
  /* Post processing of the update. Could start the vHsm Firmware internally. */
  else if(vHsmUpd_Ext_PostUpdateProcessing() == E_NOT_OK)
  {
    /* Nothing to do on Error */
  }
  else
  {
    /* Nothing to do */
  }

}

#define VHSMUPD_STOP_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/
#define VHSMUPD_START_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/***********************************************************************************************************************
 *  vHsmUpd_Init()
 **********************************************************************************************************************/
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
FUNC(void, VHSMUPD_CODE) vHsmUpd_Init( void )
{
  /* Prevent from checking the available firmware twice, the result of the first check is saved.
  Especially if there is no update to be processed. */
  boolean isFirmwareAvailableTemp = FALSE;

  /* Initialize the MemDriver. Has to be initialized before blank check function is called. */
  vHsmUpd_InitializeMemDriver();

  /* Call Extension initialization */
  vHsmUpd_Ext_Init();

  /* Evaluate if valid installed firmware is available */
  if(vHsmUpd_Ext_CheckForValidFirmware() == E_OK)
  {
    isFirmwareAvailableTemp = TRUE;
  }

  /* Check if an update has to be processed */
  if(vHsmUpd_Ext_CheckUpdateCondition() == E_OK)
  {
    isFirmwareAvailableTemp = FALSE;
    vHsmUpd_Update();
  }

  /* Write update not started to shared memory location, when update failure or nothing to update */
  vHsmUpd_Ext_StateCallbackNotification(VHSMUPD_UPDATE_NOT_STARTED);

  /* No update, than start the firmware if available */
  if( (isFirmwareAvailableTemp == TRUE) )
  {
    vHsmUpd_Ext_StartHsmFw();
  }
  else if(vHsmUpd_Ext_CheckForValidFirmware() == E_OK)
  {
    vHsmUpd_Ext_StartHsmFw();
  }
  else
  {
    vHsmUpd_Ext_ErrorHandling();
  }

  /* This point should never be reached.
   * 1. Firmware was started
   * 2. Update completed and firmware started
   * 3. No Firmware or update failed -> The Updater should stay in communication handling.
   * 4. Error, than the user should implement appropriate error handling which starts Host and/or resets device */
  while(vHsmUpd_AlwaysTrue == TRUE) /* COV_VHSMUPD_ENDLESSLOOP */ /* PRQA S 2871, 2990 */ /* MD_vHsmUpd_Endlessloop */
  {
    /* Catch the Program on error */
  }
} /* PRQA S 6050 */ /* MD_MSR_STCAL */

#define VHSMUPD_STOP_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* Justification for module-specific MISRA deviations:

  MD_vHsmUpd_MemoryAccess: rule  11.4
    Reason: The vHsmUpd uses a memory mapped read from flash. This involves a cast between a pointer to a volatile object and an integral type.
    The address configured for the Ipc base address is used as a RAM location where the vHsmUpd communicates it's current update state.
    Risk: Size of pointer type is hardware specific - not compatible between platforms. Invalid memory access.
    Prevention: No prevention.

  MD_vHsmUpd_vMemAccMInteraction:
    Reason: The used vMemAccM expects untyped void pointers as user buffers and forwards it directly to the vMem. vMem uses the buffer
    as needed.
    Risk: As the original buffer is of type uint8* the cast to void and back to object does not lead to alignment problems. No risk seen.
    Prevention: Interface is defined and cannot be changed. Tests ensure that the cast does not lead to alignment problems.

  MD_vHsmUpd_Endlessloop
    Reason:     Endless loop, which caches the execution on unhandable fail.
    Risk:       None
    Prevention: Covered by code review and tests.

  MD_vHsmUpd_ConstConfigData:
      Reason:     Configuration constants/tables are kept at a central location for a better overview and maintenance.
      Risk:       Scope is larger than required (whole file instead of one function). Some other function could access
                  the variable.
      Prevention: Take care that this deviation is used for constant data only (which cannot be modified).

 */

/* START_COVERAGE_JUSTIFICATION

Variant coverage:

\ID COV_VHSMUPD_COMPATIBILITY
 \ACCEPT TX
 \REASON COV_MSR_COMPATIBILITY

\ID COV_VHSMUPD_TEST
  \ACCEPT TX
  \REASON This define must be used when the component is under test. Must be disabled for production.

\ID COV_VHSMUPD_ENDLESSLOOP
  \ACCEPT XF
  \REASON Endless loop, which caches the execution on unhandable fail.

END_COVERAGE_JUSTIFICATION
 */

/**********************************************************************************************************************
 *  END OF FILE: vHsmUpd.c
 *********************************************************************************************************************/
