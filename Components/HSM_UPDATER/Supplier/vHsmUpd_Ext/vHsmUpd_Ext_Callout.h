/***********************************************************************************************************************
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
/*!        \file  vHsmUpd_Ext_Callout.h
 *        \brief  vHsmUpd extension callout header file
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 *
 *  FILE VERSION
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the VERSION CHECK below.
 **********************************************************************************************************************/

#ifndef VHSMUPD_EXT_CALLOUT_H
#define VHSMUPD_EXT_CALLOUT_H

/***********************************************************************************************************************
 * INCLUDES
 **********************************************************************************************************************/
#include "vHsmUpd_Ext_Types.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/

/***********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 **********************************************************************************************************************/

#ifndef VHSMUPD_EXT_UPDATE_ERROR                        /* COV_VHSMUPD_EXT_COMPATIBILITY */
#define VHSMUPD_EXT_UPDATE_ERROR                        (0u) /*!< Any error ocurred during the update process and the retry counter is exceeded */
#endif

#ifndef VHSMUPD_EXT_NO_DATA_ERROR                       /* COV_VHSMUPD_EXT_COMPATIBILITY */
#define VHSMUPD_EXT_NO_DATA_ERROR                       (1u) /* No data available for processing, i.e. no vHsm firmware and no valid update image. */
#endif                                                       /* This error also occurs if the update image could not processed correctly. */

/*!< Error type used for the vHsm_FirmwareUpdate_Error_Callout. Helps the user to determine which
kind of uncorrectable error occurred. */
typedef uint8 vHsmUpd_Ext_ErrorType;

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

/***********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 **********************************************************************************************************************/
# define VHSMUPD_EXT_START_SEC_CODE_MAC_CALLOUT
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  vHsm_FirmwareUpdate_GetMacKey_Callout()
 *********************************************************************************************************************/
/*!
 * \brief          The user shall implement this callout to store the key used for the MAC calculation in the given
 *                 buffer. This key will be used later to verify the update image.
 * \details        -
 * \param[out]     keyPtr      where the key is stored.
 * \param[in,out]  length      is the length available for the key and can be set to the length used.
 * \return         E_OK if a valid key was found, E_NOT_OK otherwise.
 * \pre            -
 * \context        TASK
 * \reentrant      TRUE
 * \synchronous    TRUE
 */
FUNC(Std_ReturnType, VHSMUPD_EXT_CODE) vHsm_FirmwareUpdate_GetMacKey_Callout(
  vHsmUpd_Ext_DataPtrType keyPtr,
  vHsmUpd_Ext_LengthPtrType length);

# define VHSMUPD_EXT_STOP_SEC_CODE_MAC_CALLOUT
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

# define VHSMUPD_EXT_START_SEC_CODE_CIPHER_CALLOUT
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  vHsm_FirmwareUpdate_GetCipherKey_Callout()
 *********************************************************************************************************************/
/*!
 * \brief          The user shall implement this callout to store the key used for the encrypted update image in the given
 *                 buffer. This key will be used later to decrypt the update image.
 * \details        -
 * \param[out]     keyPtr    where the key is stored.
 * \param[in,out]  length    is the length available for the key and can be set to the length used.
 * \return         E_OK if a valid key was found, E_NOT_OK otherwise.
 * \pre            -
 * \context        TASK
 * \reentrant      TRUE
 * \synchronous    TRUE
 */
FUNC(Std_ReturnType, VHSMUPD_EXT_CODE) vHsm_FirmwareUpdate_GetCipherKey_Callout(
  vHsmUpd_Ext_DataPtrType keyPtr,
  vHsmUpd_Ext_LengthPtrType length);

# define VHSMUPD_EXT_STOP_SEC_CODE_CIPHER_CALLOUT
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

# define VHSMUPD_EXT_START_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  vHsm_FirmwareUpdate_Update_Callout()
 *********************************************************************************************************************/
/*!
 * \brief       Gets called when the update process is started.
 * \details     If an update is requested, this callout is invoked before the actual update process is started.
 *              The user has at this state the possibility e.g. to start a host core which trigger watchdogs.
 *              vHsmUpd will not check the state of the "application" which then runs on the Host,
 *              e.g. problems with the Host application in general are not recognized
 * \return      E_OK if host core is prepared for update process, E_NOT_OK otherwise.
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */
FUNC(Std_ReturnType, VHSMUPD_EXT_CODE) vHsm_FirmwareUpdate_Update_Callout(void);

/**********************************************************************************************************************
 *  vHsm_FirmwareUpdate_Error_Callout()
 *********************************************************************************************************************/
/*!
 * \brief       Gets called when an uncorrectable error occurred.
 * \details     This can happen on two occasions. The update is broken, e.g. any error occurred during the verification
 *              of the update and installing it and the retry counter is exceeded. Or there is no update image
 *              available, but also no valid vHsm firmware image.
 *              The Callout is also triggered if the update of one region was aborted by an error, but the vHsmFw
 *              module is still available. The aborted region remains in invalid state.
 *              In case, the vHsmFw is not affected by the update, or the update related to the inactive side,
 *              this callout should inform the Host core about the failed update and can return. The vHsmFw is started
 *              afterwards.
 *              In case the vHsmFw on the active partition was part of the update and remains invalid,
 *              the callout should not return to normal execution as this leads to an endless loop.
 *              Could be used to start the host cores without secure boot to do more advanced error processing.
 * \param[in]   error which indicates the kind of error happened.
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */
FUNC(void, VHSMUPD_EXT_CODE) vHsm_FirmwareUpdate_Error_Callout(const vHsmUpd_Ext_ErrorType error);

#if (VHSMUPD_EXT_ENABLE_USER_COMPARE_MECHANISM == STD_ON)
/**********************************************************************************************************************
 *  vHsm_FirmwareUpdate_VersionCompare_Callout()
 *********************************************************************************************************************/
/*!
 * \brief       Gets called when the vHsmUpd wants to determine if the installed firmware version is outdated.
 *              Within the versionBuffer there will be the read value from flash, which than can be
 *              used by the function to check, whether an update shall be requested or not.
 * \details     -
 * \param[in]   currentUpdateHeaderVersion      The Version read from the update header
 * \param[in]   maxVersionOnActivePartition     The maximum updateVersion, written on the active partition codeflash
 * \param[in]   maxVersionOnInactivePartition   The maximum updateVersion, written on the inactive partition codeflash.
 *                                              If just one partition is configured, this value is passed as zero.
 * \return      Shall return TRUE if an update of the firmware is requested and FALSE otherwise.
 * \config      VHSMUPD_EXT_ENABLE_USER_COMPARE_MECHANISM must be switched on, otherwise this callout won't get triggered.
 *              If the switch is off the vHsmUpd will use the pure values for comparison of the firmware version.
 * \pre         -
 * \context     TASK
 * \reentrant   TRUE
 * \synchronous TRUE
 */
FUNC(boolean, VHSMUPD_EXT_CODE) vHsm_FirmwareUpdate_VersionCompare_Callout(
  uint32 currentUpdateHeaderVersion,
  uint32 maxVersionOnActivePartition,
  uint32 maxVersionOnInactivePartition);
#endif

/**********************************************************************************************************************
 *  vHsmUpd_Ext_StateCallbackNotification_Callout()
 *********************************************************************************************************************/
/*!
 * \brief       Callout which provides the current update state
 * \details     Provides the three states of the update:
 *              - No update started
 *              - Update in progress
 *              - Update completed
 *              This callout needs no implementation. The callout can be used to inform the host core about the
 *              update state.
 * \param[in]   currentState  The current update state.
 * \pre         -
 * \context     TASK
 * \reentrant   TRUE
 * \synchronous TRUE
 */
FUNC(void, VHSMUPD_EXT_CODE) vHsmUpd_Ext_StateCallbackNotification_Callout(vHsmUpd_Ext_IpcUpdateStateType currentState);

/**********************************************************************************************************************
 *  vHsmUpd_Ext_WaitForHost_Callout()
 *********************************************************************************************************************/
/*!
 * \brief       Callout which is triggered in the wait for host loop.
 * \details     This callout is invented for later use and needs no implementation.
 *              It can be used to trigger a hsm watchdog or set a own condition to leave the loop.
 * \param[in]   waitForHostVariable  The Loop variable of the wait loop. The loop is left if the value is set to TRUE.
 * \pre         -
 * \context     TASK
 * \reentrant   TRUE
 * \synchronous TRUE
 */
FUNC(void, VHSMUPD_EXT_CODE) vHsmUpd_Ext_WaitForHost_Callout(vHsmUpd_Ext_BooleanPtrType waitForHostVariable);

# define VHSMUPD_EXT_STOP_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */  /* MD_MSR_MemMap */

#endif  /* VHSMUPD_EXT_CALLOUT_H */

/***********************************************************************************************************************
 *  END OF FILE: vHsmUpd_Ext_Callout.h
 **********************************************************************************************************************/
