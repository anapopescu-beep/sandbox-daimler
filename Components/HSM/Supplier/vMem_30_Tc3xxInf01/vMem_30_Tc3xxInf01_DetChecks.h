/**********************************************************************************************************************
 *  COPYRIGHT
 *  --------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2022 by Vector Informatik GmbH.                                              All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  --------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  ------------------------------------------------------------------------------------------------------------------*/
/*!        \file  vMem_30_Tc3xxInf01_DetChecks.h
 *        \brief  Header file for declaration of DET checks functions for vMem_30_Tc3xxInf01.
 *      \details  Provides the declarations for DET check functions of API parameters. These checks may be useful for
 *                hardware specific services for all subcomponents of vMem_30_Tc3xxInf01.
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 **********************************************************************************************************************/
#if !defined (VMEM_30_TC3XXINF01_DETCHECKS_H)
# define VMEM_30_TC3XXINF01_DETCHECKS_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
# include "vMem_30_Tc3xxInf01_IntShared.h"

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
# define VMEM_30_TC3XXINF01_START_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
#if (VMEM_30_TC3XXINF01_DEV_ERROR_DETECT == STD_ON)
/**********************************************************************************************************************
 *  vMem_30_Tc3xxInf01_IsInstanceIdValid()
 *********************************************************************************************************************/
/*!
 * \brief       Checks the passed instance id - not to be out of range.
 * \details     -
 * \param[in]   InstanceId       id equal to index of the related vMem_30_Tc3xxInf01 instance in configuration structure.
 * \return      TRUE; if the instance id is valid; FALSE otherwise.
 * \pre         VMEM_30_TC3XXINF01_DEV_ERROR_DETECT enabled
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */
FUNC(boolean, VMEM_30_TC3XXINF01_CODE) vMem_30_Tc3xxInf01_IsInstanceIdValid(vMem_30_Tc3xxInf01_InstanceIdType InstanceId);

/**********************************************************************************************************************
 *  vMem_30_Tc3xxInf01_InstancePendingCheck()
 *********************************************************************************************************************/
/*!
 * \brief       Check whether the requested instance is in a pending state.
 * \details     Calls LowLevel GetJobResult service, to retrieve current state of vMem_30_Tc3xxInf01 instance.
 * \param[in]   InstanceId        Id of vMem_30_Tc3xxInf01 instance is passed on to LowLevel, must be valid.
 * \return      TRUE, if the instance is pending; FALSE otherwise
 * \pre         VMEM_30_TC3XXINF01_DEV_ERROR_DETECT enabled
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */
FUNC(boolean, VMEM_30_TC3XXINF01_CODE) vMem_30_Tc3xxInf01_InstancePendingCheck(vMem_30_Tc3xxInf01_InstanceIdType InstanceId);

/**********************************************************************************************************************
 *  vMem_30_Tc3xxInf01_IsAddressPageAligned()
 *********************************************************************************************************************/
/*!
 * \brief       Checks whether the passed address is aligned to page size of the referenced sector.
 * \details     -
 * \param[in]   InstanceId        ID of the related vMem_30_Tc3xxInf01 instance, must be valid.
 * \param[in]   Address           NV memory address to check.
 * \return      TRUE, if the address is page aligned; FALSE otherwise
 * \pre         VMEM_30_TC3XXINF01_DEV_ERROR_DETECT enabled
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */
FUNC(boolean, VMEM_30_TC3XXINF01_CODE) vMem_30_Tc3xxInf01_IsAddressPageAligned(vMem_30_Tc3xxInf01_InstanceIdType InstanceId, vMem_30_Tc3xxInf01_AddressType Address);
/**********************************************************************************************************************
 *  vMem_30_Tc3xxInf01_IsBlankLengthCheck()
 *********************************************************************************************************************/
/*!
 * \brief       Checks if the passed Length matches the configured pagesize of the sector referenced by the address.
 * \details     -
 * \param[in]   InstanceId        ID of the related vMem_30_Tc3xxInf01 instance, must be valid.
 * \param[in]   Address           Address of the page that the given length shall be checked for, must be valid.
 * \param[in]   Length            Length of the page in bytes.
 * \return      TRUE, if the Length matches the configured pagesize; FALSE otherwise.
 * \pre         VMEM_30_TC3XXINF01_DEV_ERROR_DETECT enabled
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */
FUNC(boolean, VMEM_30_TC3XXINF01_CODE) vMem_30_Tc3xxInf01_IsBlankLengthCheck(vMem_30_Tc3xxInf01_InstanceIdType InstanceId, vMem_30_Tc3xxInf01_AddressType Address, vMem_30_Tc3xxInf01_LengthType Length);

/**********************************************************************************************************************
 *  vMem_30_Tc3xxInf01_IsAddressSectorAligned()
 *********************************************************************************************************************/
/*!
 * \brief       Checks whether the passed address is aligned to the sector size.
 * \details     -
 * \param[in]   InstanceId        ID of the related vMem_30_Tc3xxInf01 instance, must be valid.
 * \param[in]   Address           NV memory address to check.
 * \return      TRUE, if the address is sector aligned; FALSE otherwise
 * \pre         VMEM_30_TC3XXINF01_DEV_ERROR_DETECT enabled
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */
FUNC(boolean, VMEM_30_TC3XXINF01_CODE) vMem_30_Tc3xxInf01_IsAddressSectorAligned(vMem_30_Tc3xxInf01_InstanceIdType InstanceId, vMem_30_Tc3xxInf01_AddressType Address);
/**********************************************************************************************************************
 *  vMem_30_Tc3xxInf01_EraseLengthCheck()
 *********************************************************************************************************************/
/*!
 * \brief       Checks whether the passed Length matches the sector size or the erase burst size of the sector
 *              referenced by passed address.
 * \details     -
 * \param[in]   InstanceId        ID of the related vMem_30_Tc3xxInf01 instance, must be valid.
 * \param[in]   Address           NV memory address to erase, must be valid.
 * \param[in]   Length            Length in bytes to erase.
 * \return      TRUE, if the Length matches the sector size or erase burst size; FALSE otherwise.
 * \pre         VMEM_30_TC3XXINF01_DEV_ERROR_DETECT enabled
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */
FUNC(boolean, VMEM_30_TC3XXINF01_CODE) vMem_30_Tc3xxInf01_EraseLengthCheck(vMem_30_Tc3xxInf01_InstanceIdType InstanceId, vMem_30_Tc3xxInf01_AddressType Address, vMem_30_Tc3xxInf01_LengthType Length);
/**********************************************************************************************************************
 *  vMem_30_Tc3xxInf01_WriteLengthCheck()
 *********************************************************************************************************************/
/*!
 * \brief       Checks whether the passed Length matches the page size or the write burst size of the sector
 *              referenced by passed address.
 * \details     -
 * \param[in]   InstanceId        ID of the related vMem_30_Tc3xxInf01 instance, must be valid.
 * \param[in]   Address           NV memory address to write to, must be valid.
 * \param[in]   Length            Length in bytes to write.
 * \return      TRUE, if the Length matches the page size or write burst size; FALSE otherwise.
 * \pre         VMEM_30_TC3XXINF01_DEV_ERROR_DETECT enabled
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */
FUNC(boolean, VMEM_30_TC3XXINF01_CODE) vMem_30_Tc3xxInf01_WriteLengthCheck(
  vMem_30_Tc3xxInf01_InstanceIdType InstanceId, vMem_30_Tc3xxInf01_AddressType Address, vMem_30_Tc3xxInf01_LengthType Length);

/**********************************************************************************************************************
 *  vMem_30_Tc3xxInf01_ReadLengthCheck()
 *********************************************************************************************************************/
/*!
 * \brief       Checks whether the passed Length is valid, that is if it is contained in the same sector batch as the
 *              passed Address.
 * \details     -
 * \param[in]   InstanceId        ID of the related vMem_30_Tc3xxInf01 instance, must be valid.
 * \param[in]   Address           NV memory address to read from, must be valid.
 * \param[in]   Length            Length in bytes to read.
 * \return      E_OK, if the Length is valid; E_NOT_OK otherwise
 * \pre         VMEM_30_TC3XXINF01_DEV_ERROR_DETECT enabled
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */
FUNC(boolean, VMEM_30_TC3XXINF01_CODE) vMem_30_Tc3xxInf01_ReadLengthCheck(
  vMem_30_Tc3xxInf01_InstanceIdType InstanceId, vMem_30_Tc3xxInf01_AddressType Address, vMem_30_Tc3xxInf01_LengthType Length);

/**********************************************************************************************************************
 *  vMem_30_Tc3xxInf01_ReadAddressCheck()
 *********************************************************************************************************************/
/*!
 * \brief       Check whether the passed address points to any configured sector.
 * \details     -
 * \param[in]   InstanceId        ID of the related vMem_30_Tc3xxInf01 instance, must be valid.
 * \param[in]   Address           NV memory address to read from.
 * \return      TRUE, if the address is valid; FALSE otherwise
 * \pre         VMEM_30_TC3XXINF01_DEV_ERROR_DETECT enabled
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */
FUNC(boolean, VMEM_30_TC3XXINF01_CODE) vMem_30_Tc3xxInf01_ReadAddressCheck(
  vMem_30_Tc3xxInf01_InstanceIdType InstanceId, vMem_30_Tc3xxInf01_AddressType Address);

#endif /* (VMEM_30_TC3XXINF01_DEV_ERROR_DETECT == STD_ON) */

# define VMEM_30_TC3XXINF01_STOP_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */  /* MD_MSR_MemMap */

#endif /* VMEM_30_TC3XXINF01_DETCHECKS_H */
/**********************************************************************************************************************
 *  END OF FILE: vMem_30_Tc3xxInf01_DetChecks.h
 *********************************************************************************************************************/
