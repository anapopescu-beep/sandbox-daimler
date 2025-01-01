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
/*!        \file  vHsmUpd_Ext.h
 *        \brief  vHsmUpd Vector Extension header file
 *
 *      \details  Header file for the vHsmUpd extension. Defines the public API.
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Version   Date        Author  Change Id                 Description
 *  -------------------------------------------------------------------------------------------------------------------
 *  01.00.00  2018-12-04  virstl  STORYC-7078/STORYC-7126   Create vHSM Updater
 *  01.01.00  2019-03-22  virstl  STORY-10323               vHsmUpd shall search at multiple addresses for an update header
 *            2019-03-28  virstl  STORY-8706                vHsmUpd: Inform Host-Core about pending update
 *  02.00.00  2019-04-17  virstl  STORY-12014               vHsmUpd shall support platform pagesizes < 16Bytes
                                  STORY-10995               vHsmUpd shall use Core/LL concept to minimize
 *                                                          development effort for new platforms
 *  02.01.00  2019-05-13  virbka  STORY-11970               vHsmUpd shall support startup of Host-Cores (TriCore 3xx)
 *            2019-05-16  virstl  STORY-9512                vHsmUpd shall use new memory interface (vMemAccM and vMem)
 *  02.01.02  2019-07-15  virstl  ESCAN00103544             HSM Updaters try to start the HSM firmware might lead to
 *                                                          exception resulting in a dead ECU
 *  02.02.00  2019-07-18  virstl  MWDG-40                   vHsmUpd shall use write/erase retry strategy of vMemAccM
 *  02.02.01  2019-08-01  virstl  MWDG-1569                 HSM Updater solution shall take care of RAM alignment
 *                                                          of data buffers
 *  03.00.00  2019-08-09  virstl  MWDG-94                   HSM Updater shall evaluate execution reason to decide for
 *                                                          update request
 *  03.00.01  2019-11-05  virstl  ESCAN00104801             HSM Updater can give unaligned write buffers to underlying
 *                                                          Memory Abstraction module which leads to exception
 *  03.00.02  2020-03-11  virstl  ESCAN00105679             HSM Update writes to areas not specified for update process
 *                                                          which leads to failed update resulting in a not responding ECU
 *  03.00.03  2020-04-15  visfnn  ESCAN00105855             Use uint32 access for HSM2Host register.
 *                                HSM-827                   Use eslt_Length instead of uint16 for crypto-functions
 *  03.00.04  2020-05-06  visfnn  ESCAN00106321             Update fails if the last block of the image is bigger than
 *                                                          one pagesize and not a full rambuffer size.
 *  04.00.00  2020-10-07  visfnn  HSM-1179                  Create vHSM Updater Extension Vector
 *            2020-12-18  visfnn  ESCAN00108188             Fix memory section of ram function declaration.
 *            2021-01-15  visfnn  HSM-1327                  Restructure new core-extension design.
 *  04.01.00  2021-02-15  visfpt  HSM-1524                  Implement multi module updates
 *********************************************************************************************************************/

#if !defined (VHSMUPD_EXT_H)
# define VHSMUPD_EXT_H

/***********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/
#include "vHsmUpd_Ext_Types.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/* ----- Component version information (decimal version of ALM implementation package) ----- */
# define VHSMUPD_EXT_SW_MAJOR_VERSION                    (4u)
# define VHSMUPD_EXT_SW_MINOR_VERSION                    (1u)
# define VHSMUPD_EXT_SW_PATCH_VERSION                    (0u)

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPE
 *********************************************************************************************************************/

#define VHSMUPD_EXT_START_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  vHsmUpd_Ext_StateCallbackNotification()
 *********************************************************************************************************************/
/*!
 * \brief       This function writes to the configured base address (and only the base address) of the Ipc memory location.
 * \details     If the base is not available within the configuration this function does nothing.
 * \param[in]   currentState     represents current state as uint8 value, which will be written to the Ipc base address.
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */
FUNC(void, VHSMUPD_EXT_CODE) vHsmUpd_Ext_StateCallbackNotification(vHsmUpd_Ext_IpcUpdateStateType currentState);

/**********************************************************************************************************************
 *  vHsmUpd_Ext_PrepareAndVerifyUpdate()
 *********************************************************************************************************************/
/*!
 * \brief       Prepare the update process and verify the update image.
 * \details     -
 * \return      E_OK if successfull.
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */
FUNC(Std_ReturnType, VHSMUPD_EXT_CODE) vHsmUpd_Ext_PrepareAndVerifyUpdate(void);

/**********************************************************************************************************************
 *  vHsmUpd_Ext_ProcessUpdateParts()
 *********************************************************************************************************************/
/*!
 * \brief       This function processes the single update parts.
 * \details     -
 * \return      E_OK if successfull.
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */
FUNC(Std_ReturnType, VHSMUPD_EXT_CODE) vHsmUpd_Ext_ProcessUpdateParts(void);

/**********************************************************************************************************************
 *  vHsmUpd_Ext_PostUpdateProcessing()
 *********************************************************************************************************************/
/*!
 * \brief       Do the last steps of the update. Start the vHsmFw on successfull update
 * \details     -
 * \return      E_OK if successfull.
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */
FUNC(Std_ReturnType, VHSMUPD_EXT_CODE) vHsmUpd_Ext_PostUpdateProcessing(void);

/**********************************************************************************************************************
 *  vHsmUpd_Ext_Init()
 *********************************************************************************************************************/
/*!
 * \brief       Initialisation of the vHsmUpd
 * \details     -
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */
FUNC(void, VHSMUPD_EXT_CODE) vHsmUpd_Ext_Init(void);

/**********************************************************************************************************************
 *  vHsmUpd_Ext_CheckForValidFirmware()
 *********************************************************************************************************************/
/*!
 * \brief       Checks if the presence pattern on the given address is valid
 * \details     -
 * \return      E_OK if the presence pattern is valid
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */
FUNC(Std_ReturnType, VHSMUPD_EXT_CODE) vHsmUpd_Ext_CheckForValidFirmware(void);

/**********************************************************************************************************************
 *  vHsmUpd_Ext_CheckUpdateCondition()
 *********************************************************************************************************************/
/*!
 * \brief       Checks the Common conditions to start the update process.
 * \details     -
 * \return      E_OK if a valid update header is found at the configured address.
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */
FUNC(Std_ReturnType, VHSMUPD_EXT_CODE) vHsmUpd_Ext_CheckUpdateCondition(void);

/**********************************************************************************************************************
 *  vHsmUpd_Ext_StartHsmFw()
 *********************************************************************************************************************/
/*!
 * \brief       Starts the installed Hsm Firmware.
 * \details     -
 * \return      Does not return.
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous FALSE
 */
FUNC(void, VHSMUPD_EXT_CODE) vHsmUpd_Ext_StartHsmFw(void);

/**********************************************************************************************************************
 *  vHsmUpd_Ext_ErrorHandling()
 *********************************************************************************************************************/
/*!
 * \brief       If the update is failed, this functions calls the error callout.
 * \details     -
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */
FUNC(void, VHSMUPD_EXT_CODE) vHsmUpd_Ext_ErrorHandling(void);

#define VHSMUPD_EXT_STOP_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#endif /* VHSMUPD_EXT_H */

/**********************************************************************************************************************
 *  END OF FILE: vHsmUpd_Ext.h
 *********************************************************************************************************************/
