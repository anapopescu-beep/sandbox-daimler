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
/*!        \file  vHsmUpd_Ext_Common.h
 *        \brief  Extension header file. Functions must be implemented in extension implementation.
 *
 *      \details  Header file for the common extension callouts.
 *
 *********************************************************************************************************************/

#ifndef VHSMUPD_EXT_COMMON_H
#define VHSMUPD_EXT_COMMON_H

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
#define VHSMUPD_EXT_START_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern VAR(vHsmUpd_Ext_ProcInfoType, VHSMUPD_EXT_VAR_NOINIT) vHsmUpd_Ext_UpdState;
extern VAR(vHsmUpd_Ext_StateInfoType, VHSMUPD_EXT_VAR_NOINIT) vHsmUpd_Ext_ValidityInfo;

#define VHSMUPD_EXT_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define VHSMUPD_EXT_START_SEC_VAR_NOINIT_RAM_BUFFER
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! The buffer used for processing the update. Align to 4 Byte */
extern VAR(uint8, VHSMUPD_EXT_VAR_NOINIT) vHsmUpd_Ext_ProcessingDataBuffer[VHSMUPD_EXT_DECRYPTION_RAM_BUFFER_SIZE];

#define VHSMUPD_EXT_STOP_SEC_VAR_NOINIT_RAM_BUFFER
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPE
 *********************************************************************************************************************/

#define VHSMUPD_EXT_START_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  vHsmUpd_Ext_CompatibilityCheck()
 *********************************************************************************************************************/
/*!
 * \brief       Checks compatibility of the update
 * \details     Compares the installed version to the update version.
 * \return      E_OK if the compatibility check was successfull.
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */
FUNC(Std_ReturnType, VHSMUPD_EXT_CODE) vHsmUpd_Ext_CompatibilityCheck(void);

/**********************************************************************************************************************
 *  vHsmUpd_Ext_GetUpdateHeaderLocation()
 *********************************************************************************************************************/
/*!
 * \brief       Check the location of the updateheader
 * \details     -
 * \return      The header location
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */
FUNC(vHsmUpd_Ext_AddressType, VHSMUPD_EXT_CODE) vHsmUpd_Ext_GetUpdateHeaderLocation(void);

/**********************************************************************************************************************
 *  vHsmUpd_Ext_HsmStateClear()
 *********************************************************************************************************************/
/*!
 * \brief       Checks the communication to the host system
 * \details     -
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */
FUNC(void, VHSMUPD_EXT_CODE) vHsmUpd_Ext_HsmStateClear(void);

/**********************************************************************************************************************
 *  vHsmUpd_Ext_CheckUpdateRequest()
 *********************************************************************************************************************/
/*!
 * \brief       Check whether an update of the vHsm is requested through the version numbering.
 * \details     -
 * \return      E_OK, if the update version is greater than the installed one; E_NOT_OK otherwise
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */
FUNC(Std_ReturnType, VHSMUPD_EXT_CODE) vHsmUpd_Ext_CheckUpdateRequest(void);

/**********************************************************************************************************************
 *  vHsmUpd_Ext_CheckValidUpdate()
 *********************************************************************************************************************/
/*!
 * \brief       Checks whether the update header is valid and was successfully read.
 * \details     -
 * \return      TRUE if update header is correct and valid and could be read completely, FALSE otherwise.
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */
FUNC(boolean, VHSMUPD_EXT_CODE) vHsmUpd_Ext_CheckValidUpdate(void);

#define VHSMUPD_EXT_STOP_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#endif /* VHSMUPD_EXT_COMMON_H */

/**********************************************************************************************************************
 *  END OF FILE: vHsmUpd_Ext_Common.h
 *********************************************************************************************************************/
