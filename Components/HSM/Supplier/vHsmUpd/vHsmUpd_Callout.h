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
/*!        \file  vHsmUpd_Callout.h
 *        \brief  vHsmUpd Callout header file
 *
 *      \details  Header file for the vHsmUpd callouts.
 *
 *********************************************************************************************************************/

#if !defined (VHSMUPD_CALLOUT_H)
# define VHSMUPD_CALLOUT_H

/***********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/
#include "vHsmUpd_Types.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPE
 *********************************************************************************************************************/
#define VHSMUPD_START_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  vHsmUpd_Read_Callout()
 *********************************************************************************************************************/
/*!
 * \brief         Reads from flash memory.
 * \details       Reading on the code flash must be performed regarding the configured address and regions.
 *                If the regions are configured in the vHsmUpd configuration and the vMemAccM is configured
 *                regarding this configuration the vMemAccM and vMem will take the address handling.
 *                Therefore, the vMemAccM_Read function can be used to read in the HSM code flash.
 *
 *                The read access on the host code flash can be performed by the
 *                vMemAccM or by a pointer to an address. If the vMem / vMemAccM is used to access
 *                the code flash on the host side, the code flash of the host side must be configured
 *                in the vMem and vMemAccM.
 *
 *                Otherwise, the vHsmUpd_MemRead function can be used, which
 *                reads the memory with a pointer to the given address. In OTA use case the
 *                remapping of the code flash needs attention.
 * \param[in]     areaId    Memory Area ID.
 * \param[in]     buffer    pointer to buffer.
 * \param[in]     length    Length to be checked in bytes.
 * \param[in]     address   Memory Address.
 * \param[in]     target    Specifies if the address is from application core or hsm core.
 * \pre           -
 * \context       TASK
 * \reentrant     FALSE
 * \synchronous   TRUE
 */
FUNC(Std_ReturnType, VHSMUPD_CODE) vHsmUpd_Read_Callout(
  vHsmUpd_MemoryAreaIdType areaId,
  vHsmUpd_DataPtrType buffer,
  vHsmUpd_LengthType length,
  vHsmUpd_AddressType address,
  vHsmUpd_TargetCoreType target);

/**********************************************************************************************************************
 *  vHsmUpd_IsBlank_Callout()
 *********************************************************************************************************************/
/*!
 * \brief         Checks if memory is blank
 * \details       This callout should check if the code flash at the given address is blank.
 *                Means, the code flash is in erased state. Reading such an address will lead to an exception,
 *                therefore a special handling of the reading is necessary.
 *
 *                In OTA use case the blank check in the HSM code flash must be performed by the vMem.
 *                Therefore, the vMem can be used in the callout to perform the blank check.
 *
 *                In some cases the blank check must be performed in the host code flash.
 *                Depending on the configuration and the derivate the blank check can be performed by the vMem.
 *                On some derivates and depending on the configuration it would be easier to use the blank check
 *                function provided by the vHsmUpd_Hal-module. The behavior can be chosen by the target parameter,
 *                which signals if the target address is in the HSM- or the host-code flash. If the derivate is
 *                not supported by the vMem to perform the blank check in the host code flash and no vHsmUpd_Hal
 *                is available for the derivate, the customer has to implement this callout.
 * \param[in]     areaId    Memory Area ID.
 * \param[in]     length    Length to be checked in bytes.
 * \param[in]     address   Memory Address.
 * \param[out]    blank     blank check result.
 * \param[in]     target    Specifies if the address is from application core or hsm core.
 * \return        E_OK      Blank check successful
 *                E_NOT_OK  Blank check failed
 * \pre           -
 * \context       TASK
 * \reentrant     FALSE
 * \synchronous   TRUE
 */
FUNC(Std_ReturnType, VHSMUPD_CODE) vHsmUpd_IsBlank_Callout(
  vHsmUpd_MemoryAreaIdType areaId,
  vHsmUpd_LengthType length,
  vHsmUpd_AddressType address,
  vHsmUpdBooleanResultPtrType blank,
  vHsmUpd_TargetCoreType target);

/**********************************************************************************************************************
 *  vHsmUpd_IsSwapped_Callout()
 *********************************************************************************************************************/
/*!
 * \brief         In OTA use case the swapped state is needed to process the update correctly.
 * \details       The callout should write to the isSwapped variable if the codeflash is currently mapped in standard
 *                address mapping or if the coodeflash is swapped.
 * \param[in,out] isSwapped      returns true if standard address map is active. Otherwise return false.
 * \return        E_OK if the result in isSwapped is valid. E_NOT_OK, else.
 * \pre           -
 * \context       TASK
 * \reentrant     FALSE
 * \synchronous   TRUE
 */
FUNC(Std_ReturnType, VHSMUPD_CODE) vHsmUpd_IsSwapped_Callout(vHsmUpdBooleanResultPtrType isSwapped);

/**********************************************************************************************************************
 *  vHsmUpd_TriggerSoftwareReset_Callout()
 *********************************************************************************************************************/
/*!
 * \brief       If the precondition is fulfilled, the user shall implement this callout to reset the device.
 * \details     A reset of the device is triggered in case that the HSM firmware is invalid before the update.
 *              This callout shall not return to the vHsmUpd context. The HSM platforms' function
 *              vHsm_Hal_TriggerSoftwareReset() can be used as a guide for the implementation of this callout.
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */
FUNC(void, VHSMUPD_CODE) vHsmUpd_TriggerSoftwareReset_Callout(void);

#define VHSMUPD_STOP_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define VHSMUPD_START_SEC_CODE_RAM
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * vHsmUpd_vMemDriver_Init_Callout
 *********************************************************************************************************************/
 /*!
 * \brief       Take care of the initialization of the vMemAccM and vMem if necessarry.
 * \details     -
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */
FUNC(void, VHSMUPD_CODE) vHsmUpd_vMemDriver_Init_Callout(void);

/**********************************************************************************************************************
 * vHsmUpd_vMemDriver_Processing_Callout
 *********************************************************************************************************************/
 /*!
 * \brief       Trigger the main function until the vMemAccM/vMem processing is done.
 * \details     -
 * \param[in]   AddressAreaId   The Address AreadId which is processed currently.
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */
FUNC(void, VHSMUPD_CODE) vHsmUpd_vMemDriver_Processing_Callout(vHsmUpd_MemoryAreaIdType AddressAreaId);

#define VHSMUPD_STOP_SEC_CODE_RAM
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#endif /* VHSMUPD_H */

/**********************************************************************************************************************
 *  END OF FILE: vHsmUpd_Callout.h
 *********************************************************************************************************************/
