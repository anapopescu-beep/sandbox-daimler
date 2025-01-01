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
/*!        \file  vMem_30_Tc3xxInf01.c
 *        \brief  vMem_30_Tc3xxInf01 source file
 *
 *      \details  See vMem_30_Tc3xxInf01.h
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

#define VMEM_30_TC3XXINF01_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "vMem_30_Tc3xxInf01.h"
#include "vMem_30_Tc3xxInf01_Int.h"
#include "vMem_30_Tc3xxInf01_LL.h"
#include "vMem_30_Tc3xxInf01_IntShared.h"

#if (VMEM_30_TC3XXINF01_DEV_ERROR_REPORT == STD_ON)
# include "Det.h"
#endif

/**********************************************************************************************************************
 *  VERSION CHECK
 *********************************************************************************************************************/

/* Check the version of vMem_30_Tc3xxInf01 header file */
#if (  (VMEM_30_TC3XXINF01_SW_MAJOR_VERSION != (2u)) \
    || (VMEM_30_TC3XXINF01_SW_MINOR_VERSION != (1u)) \
    || (VMEM_30_TC3XXINF01_SW_PATCH_VERSION != (0u)) )
# error "Vendor specific version numbers of vMem_30_Tc3xxInf01.c and vMem_30_Tc3xxInf01.h are inconsistent"
#endif

/* Check the version of the configuration header file */
#if (  (VMEM_30_TC3XXINF01_CFG_COMP_MAJOR_VERSION != (1u)) \
    || (VMEM_30_TC3XXINF01_CFG_COMP_MINOR_VERSION != (4u)) )
# error "Version numbers of vMem_30_Tc3xxInf01.c and vMem_30_Tc3xxInf01_Cfg.h are inconsistent!"
#endif

/* Check the version of vMemAccM_vMemApi file */
#if (  (VMEMACCM_VMEMAPI_MAJOR_VERSION != (3u)) \
    || (VMEMACCM_VMEMAPI_MINOR_VERSION != (0u)) )
# error "Version numbers of vMem_30_Tc3xxInf01.c and vMemAccM_vMemApi.h are inconsistent!"
#endif

/**********************************************************************************************************************
 *  LOCAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

#if !defined (VMEM_30_TC3XXINF01_LOCAL) /* COV_VMEM_30_TC3XXINF01_COMPATIBILITY */
# define VMEM_30_TC3XXINF01_LOCAL static
#endif

#if !defined (VMEM_30_TC3XXINF01_LOCAL_INLINE) /* COV_VMEM_30_TC3XXINF01_COMPATIBILITY */
# define VMEM_30_TC3XXINF01_LOCAL_INLINE LOCAL_INLINE
#endif


/**********************************************************************************************************************
 *  LOCAL DATA PROTOTYPES
 *********************************************************************************************************************/

#define VMEM_30_TC3XXINF01_START_SEC_VAR_ZERO_INIT_8BIT
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#if (VMEM_30_TC3XXINF01_DEV_ERROR_DETECT == STD_ON)
/*! Initialization state of the module */
# define VMEM_30_TC3XXINF01_UNINIT                              (0x00u)
# define VMEM_30_TC3XXINF01_INIT                                (0x01u)

VMEM_30_TC3XXINF01_LOCAL VAR(uint8, VMEM_30_TC3XXINF01_VAR_ZERO_INIT) vMem_30_Tc3xxInf01_ModuleInitialized = VMEM_30_TC3XXINF01_UNINIT;
#endif /* (VMEM_30_TC3XXINF01_DEV_ERROR_DETECT == STD_ON) */

#define VMEM_30_TC3XXINF01_STOP_SEC_VAR_ZERO_INIT_8BIT
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

#define VMEM_30_TC3XXINF01_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! Global API pointer table definition.
 * The vMem_30_Tc3xxInf01 hardware specific extended functionality is defined within LowLevel. */
CONST(vMemAccM_vMemApiType, AUTOMATIC) vMem_30_Tc3xxInf01_FunctionPointerTable = {
  {
    VMEM_30_TC3XXINF01_EXTENDED_FUNCTION_COUNT,
    VMEM_30_TC3XXINF01_EXTENDED_FUNCTION_TABLE
  },
  &vMem_30_Tc3xxInf01_Read,
  &vMem_30_Tc3xxInf01_Write,
  &vMem_30_Tc3xxInf01_Erase,
  &vMem_30_Tc3xxInf01_IsBlank,
  &vMem_30_Tc3xxInf01_GetJobResult
};

#define VMEM_30_TC3XXINF01_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

#define VMEM_30_TC3XXINF01_START_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


#if (VMEM_30_TC3XXINF01_DEV_ERROR_DETECT == STD_ON)

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
VMEM_30_TC3XXINF01_LOCAL_INLINE FUNC(boolean, VMEM_30_TC3XXINF01_CODE) vMem_30_Tc3xxInf01_InstancePendingCheck(vMem_30_Tc3xxInf01_InstanceIdType InstanceId);

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
VMEM_30_TC3XXINF01_LOCAL_INLINE FUNC(boolean, VMEM_30_TC3XXINF01_CODE) vMem_30_Tc3xxInf01_ReadAddressCheck(
  vMem_30_Tc3xxInf01_InstanceIdType InstanceId, vMem_30_Tc3xxInf01_AddressType Address);

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
VMEM_30_TC3XXINF01_LOCAL_INLINE FUNC(boolean, VMEM_30_TC3XXINF01_CODE) vMem_30_Tc3xxInf01_ReadLengthCheck(
  vMem_30_Tc3xxInf01_InstanceIdType InstanceId, vMem_30_Tc3xxInf01_AddressType Address, vMem_30_Tc3xxInf01_LengthType Length);

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
VMEM_30_TC3XXINF01_LOCAL_INLINE FUNC(boolean, VMEM_30_TC3XXINF01_CODE) vMem_30_Tc3xxInf01_WriteLengthCheck(
  vMem_30_Tc3xxInf01_InstanceIdType InstanceId, vMem_30_Tc3xxInf01_AddressType Address, vMem_30_Tc3xxInf01_LengthType Length);

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
VMEM_30_TC3XXINF01_LOCAL_INLINE FUNC(boolean, VMEM_30_TC3XXINF01_CODE) vMem_30_Tc3xxInf01_EraseLengthCheck(
  vMem_30_Tc3xxInf01_InstanceIdType InstanceId, vMem_30_Tc3xxInf01_AddressType Address, vMem_30_Tc3xxInf01_LengthType Length);

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
VMEM_30_TC3XXINF01_LOCAL_INLINE FUNC(boolean, VMEM_30_TC3XXINF01_CODE) vMem_30_Tc3xxInf01_IsBlankLengthCheck(
  vMem_30_Tc3xxInf01_InstanceIdType InstanceId, vMem_30_Tc3xxInf01_AddressType Address, vMem_30_Tc3xxInf01_LengthType Length);

/**********************************************************************************************************************
 *  vMem_30_Tc3xxInf01_InitPendingCheck()
 *********************************************************************************************************************/
/*!
 * \brief       In case of re-initialization check that no instance is pending.
 * \details     -
 * \return      TRUE, if every vMem_30_Tc3xxInf01 instance is idle; FALSE otherwise.
 * \pre         VMEM_30_TC3XXINF01_DEV_ERROR_DETECT enabled
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */
VMEM_30_TC3XXINF01_LOCAL_INLINE FUNC(boolean, VMEM_30_TC3XXINF01_CODE) vMem_30_Tc3xxInf01_InitPendingCheck(void);


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
VMEM_30_TC3XXINF01_LOCAL_INLINE FUNC(boolean, VMEM_30_TC3XXINF01_CODE) vMem_30_Tc3xxInf01_IsAddressPageAligned(
  vMem_30_Tc3xxInf01_InstanceIdType InstanceId, vMem_30_Tc3xxInf01_AddressType Address);

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
VMEM_30_TC3XXINF01_LOCAL_INLINE FUNC(boolean, VMEM_30_TC3XXINF01_CODE) vMem_30_Tc3xxInf01_IsAddressSectorAligned(
  vMem_30_Tc3xxInf01_InstanceIdType InstanceId, vMem_30_Tc3xxInf01_AddressType Address);

/**********************************************************************************************************************
 *  vMem_30_Tc3xxInf01_IsAligned()
 *********************************************************************************************************************/
/*!
 * \brief       Checks the passed value to be aligned to passed alignment.
 * \details     -
 * \param[in]   Value           Value that shall be verified, e.g. NV memory address.
 * \param[in]   Alignment       Specified alignment, e.g. sector size.
 * \return      TRUE, if the value is aligned; FALSE otherwise.
 * \pre         VMEM_30_TC3XXINF01_DEV_ERROR_DETECT enabled
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */
VMEM_30_TC3XXINF01_LOCAL_INLINE FUNC(boolean, VMEM_30_TC3XXINF01_CODE) vMem_30_Tc3xxInf01_IsAligned(
  uint32 Value, uint32 Alignment);

/**********************************************************************************************************************
 *  vMem_30_Tc3xxInf01_IsSectorIndexValid()
 *********************************************************************************************************************/
/*!
 * \brief       Checks whether the passed sector index is lower than the number of configured sectors for the
 *              referenced instance.
 * \details     Does not check whether the passed index bigger than the lower sector index threshold of the referenced
 *              instance. Therefore, this local function shall only be used, when sector index is computed with
 *              function vMem_30_Tc3xxInf01_GetSectorIndex.
 * \param[in]   InstanceId        ID of the related vMem_30_Tc3xxInf01 instance, must be valid.
 * \param[in]   SectorIndex       Index of the sector (batch) which shall be validated.
 * \return      TRUE; if the sector index is valid; FALSE otherwise.
 * \pre         VMEM_30_TC3XXINF01_DEV_ERROR_DETECT enabled
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */
VMEM_30_TC3XXINF01_LOCAL_INLINE FUNC(boolean, VMEM_30_TC3XXINF01_CODE) vMem_30_Tc3xxInf01_IsSectorIndexValid(
  vMem_30_Tc3xxInf01_InstanceIdType InstanceId, uint32 SectorIndex);


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
VMEM_30_TC3XXINF01_LOCAL_INLINE FUNC(boolean, VMEM_30_TC3XXINF01_CODE) vMem_30_Tc3xxInf01_IsInstanceIdValid(
   vMem_30_Tc3xxInf01_InstanceIdType InstanceId);
   
  /**********************************************************************************************************************
 *  vMem_30_Tc3xxInf01_GetRemainingSectorBatchLength()
 *********************************************************************************************************************/
/*!
 * \brief       Calculate the remaining sector batch length, started from given address to end-address ob sector batch.
 * \details     -
 * \param[in]   SectorIndex       Index of the sector (batch) which shall be validated.
 * \param[in]   Address           NV memory address
 * \return      uint32            calculated remaining sector batch length
 * \pre         VMEM_30_TC3XXINF01_DEV_ERROR_DETECT enabled
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */
VMEM_30_TC3XXINF01_LOCAL_INLINE FUNC(uint32, VMEM_30_TC3XXINF01_CODE) vMem_30_Tc3xxInf01_GetRemainingSectorBatchLength(
  uint32 SectorIndex, vMem_30_Tc3xxInf01_AddressType Address);

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  vMem_30_Tc3xxInf01_InstancePendingCheck
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
VMEM_30_TC3XXINF01_LOCAL_INLINE FUNC(boolean, VMEM_30_TC3XXINF01_CODE) vMem_30_Tc3xxInf01_InstancePendingCheck(
  vMem_30_Tc3xxInf01_InstanceIdType InstanceId)
{
  return (boolean)(vMem_30_Tc3xxInf01_LLGetJobResult(InstanceId) == VMEM_JOB_PENDING);
}

/**********************************************************************************************************************
 *  vMem_30_Tc3xxInf01_ReadAddressCheck()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
VMEM_30_TC3XXINF01_LOCAL_INLINE FUNC(boolean, VMEM_30_TC3XXINF01_CODE) vMem_30_Tc3xxInf01_ReadAddressCheck(
  vMem_30_Tc3xxInf01_InstanceIdType InstanceId, vMem_30_Tc3xxInf01_AddressType Address)
{
  return (boolean)(vMem_30_Tc3xxInf01_IsSectorIndexValid(InstanceId, vMem_30_Tc3xxInf01_GetSectorIndex(InstanceId, Address)));
}

/**********************************************************************************************************************
 *  vMem_30_Tc3xxInf01_GetRemainingSectorBatchLength()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
VMEM_30_TC3XXINF01_LOCAL_INLINE FUNC(uint32, VMEM_30_TC3XXINF01_CODE) vMem_30_Tc3xxInf01_GetRemainingSectorBatchLength(
  uint32 SectorIndex, vMem_30_Tc3xxInf01_AddressType Address)
{
  uint32 remainingSectorBatchLength = (((vMem_30_Tc3xxInf01_AddressType)vMem_30_Tc3xxInf01_GetSectorSizeOfMemSector(SectorIndex) * (vMem_30_Tc3xxInf01_AddressType)vMem_30_Tc3xxInf01_GetNrOfSectorsOfMemSector(SectorIndex))
    - (Address - vMem_30_Tc3xxInf01_GetStartAddressOfMemSector(SectorIndex)));
  return (remainingSectorBatchLength); 
}

/**********************************************************************************************************************
 *  vMem_30_Tc3xxInf01_ReadLengthCheck()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
VMEM_30_TC3XXINF01_LOCAL_INLINE FUNC(boolean, VMEM_30_TC3XXINF01_CODE) vMem_30_Tc3xxInf01_ReadLengthCheck(
  vMem_30_Tc3xxInf01_InstanceIdType InstanceId, vMem_30_Tc3xxInf01_AddressType Address, vMem_30_Tc3xxInf01_LengthType Length)
{
  /* We already know that the passed address is valid. */
  uint32 sectorIndex = vMem_30_Tc3xxInf01_GetSectorIndex(InstanceId, Address);
  /* The passed Length has to point to the same sector batch as the address itself. */
  return (boolean)(Length <= vMem_30_Tc3xxInf01_GetRemainingSectorBatchLength(sectorIndex, Address));

}

/**********************************************************************************************************************
 *  vMem_30_Tc3xxInf01_WriteLengthCheck()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
VMEM_30_TC3XXINF01_LOCAL_INLINE FUNC(boolean, VMEM_30_TC3XXINF01_CODE) vMem_30_Tc3xxInf01_WriteLengthCheck(
  vMem_30_Tc3xxInf01_InstanceIdType InstanceId, vMem_30_Tc3xxInf01_AddressType Address, vMem_30_Tc3xxInf01_LengthType Length)
{
  /* Note: We already know that the passed address is valid.
   * If burst is not enabled, generated write burst size equals page size. */
  uint32 sectorIndex = vMem_30_Tc3xxInf01_GetSectorIndex(InstanceId, Address);
  return (boolean)((Length == vMem_30_Tc3xxInf01_GetPageSizeOfMemSector(sectorIndex)) ||
                   ((Length == vMem_30_Tc3xxInf01_GetWriteBurstSizeOfMemSector(sectorIndex)) &&
                    (Length <= vMem_30_Tc3xxInf01_GetRemainingSectorBatchLength(sectorIndex, Address)) /* PRQA S 3415 */ /* MD_VMEM_30_TC3XXINF01_CORE_13.5_queries */
                   )
                  ); 
}


/**********************************************************************************************************************
 *  vMem_30_Tc3xxInf01_EraseLengthCheck()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
VMEM_30_TC3XXINF01_LOCAL_INLINE FUNC(boolean, VMEM_30_TC3XXINF01_CODE) vMem_30_Tc3xxInf01_EraseLengthCheck(
  vMem_30_Tc3xxInf01_InstanceIdType InstanceId, vMem_30_Tc3xxInf01_AddressType Address, vMem_30_Tc3xxInf01_LengthType Length)
{
  /* Note: We already know that the passed address is valid.
   * If burst is not enabled, generated erase burst size equals sector size. */
  uint32 sectorIndex = vMem_30_Tc3xxInf01_GetSectorIndex(InstanceId, Address);
  return (boolean)((Length == vMem_30_Tc3xxInf01_GetSectorSizeOfMemSector(sectorIndex)) ||
                   ((Length == vMem_30_Tc3xxInf01_GetEraseBurstSizeOfMemSector(sectorIndex)) &&
                    (Length <= vMem_30_Tc3xxInf01_GetRemainingSectorBatchLength(sectorIndex, Address)) /* PRQA S 3415 */ /* MD_VMEM_30_TC3XXINF01_CORE_13.5_queries */
                   )
                  ); 
}

/**********************************************************************************************************************
 *  vMem_30_Tc3xxInf01_IsBlankLengthCheck()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
VMEM_30_TC3XXINF01_LOCAL_INLINE FUNC(boolean, VMEM_30_TC3XXINF01_CODE) vMem_30_Tc3xxInf01_IsBlankLengthCheck(
  vMem_30_Tc3xxInf01_InstanceIdType InstanceId, vMem_30_Tc3xxInf01_AddressType Address, vMem_30_Tc3xxInf01_LengthType Length)
{
  /* Note: We already know that the passed address is valid. */
  uint32 sectorIndex = vMem_30_Tc3xxInf01_GetSectorIndex(InstanceId, Address);
  return (boolean)((Length == vMem_30_Tc3xxInf01_GetPageSizeOfMemSector(sectorIndex)));
}

/**********************************************************************************************************************
 *  vMem_30_Tc3xxInf01_InitPendingCheck()
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
VMEM_30_TC3XXINF01_LOCAL_INLINE FUNC(boolean, VMEM_30_TC3XXINF01_CODE) vMem_30_Tc3xxInf01_InitPendingCheck(void)
{
  boolean retVal = TRUE;
  uint32 instanceIndex;
  if(vMem_30_Tc3xxInf01_ModuleInitialized == VMEM_30_TC3XXINF01_INIT)
  {
    for(instanceIndex = 0; instanceIndex < vMem_30_Tc3xxInf01_GetSizeOfvMemInstanceOfPCConfig(); instanceIndex++)
    {
      if(vMem_30_Tc3xxInf01_InstancePendingCheck(instanceIndex) == TRUE)
      {
        retVal = FALSE;
        break;
      }
    }
  }
  return retVal;
}

/**********************************************************************************************************************
 *  vMem_30_Tc3xxInf01_IsAddressPageAligned()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
VMEM_30_TC3XXINF01_LOCAL_INLINE FUNC(boolean, VMEM_30_TC3XXINF01_CODE) vMem_30_Tc3xxInf01_IsAddressPageAligned(vMem_30_Tc3xxInf01_InstanceIdType InstanceId, vMem_30_Tc3xxInf01_AddressType Address)
{
  boolean retVal = FALSE;
  uint32 sectorIndex = vMem_30_Tc3xxInf01_GetSectorIndex(InstanceId, Address);
  if(vMem_30_Tc3xxInf01_IsSectorIndexValid(InstanceId, sectorIndex) == TRUE)
  {
    /* StartAddress of SectorBatch is not always aligned to PageSize. Take offset into account for alignment check. */
    retVal = vMem_30_Tc3xxInf01_IsAligned(Address - vMem_30_Tc3xxInf01_GetStartAddressOfMemSector(sectorIndex), vMem_30_Tc3xxInf01_GetPageSizeOfMemSector(sectorIndex));
  }

  return retVal;
}

/**********************************************************************************************************************
 *  vMem_30_Tc3xxInf01_IsAddressSectorAligned()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
VMEM_30_TC3XXINF01_LOCAL_INLINE FUNC(boolean, VMEM_30_TC3XXINF01_CODE) vMem_30_Tc3xxInf01_IsAddressSectorAligned(vMem_30_Tc3xxInf01_InstanceIdType InstanceId, vMem_30_Tc3xxInf01_AddressType Address)
{   
  boolean retVal = FALSE;
  uint32 sectorIndex = vMem_30_Tc3xxInf01_GetSectorIndex(InstanceId, Address);
  if(vMem_30_Tc3xxInf01_IsSectorIndexValid(InstanceId, sectorIndex) == TRUE)
  {
    /* StartAddress of SectorBatch is not always aligned to SectorSize. Take offset into account for alignment check. */
    retVal = vMem_30_Tc3xxInf01_IsAligned(Address - vMem_30_Tc3xxInf01_GetStartAddressOfMemSector(sectorIndex), vMem_30_Tc3xxInf01_GetSectorSizeOfMemSector(sectorIndex));
  }

  return retVal;
}

/**********************************************************************************************************************
 *  vMem_30_Tc3xxInf01_IsAligned()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
VMEM_30_TC3XXINF01_LOCAL_INLINE FUNC(boolean, VMEM_30_TC3XXINF01_CODE) vMem_30_Tc3xxInf01_IsAligned(uint32 Value, uint32 Alignment)
{
  return (boolean)((Value % Alignment) == 0u);
}

/**********************************************************************************************************************
 *  vMem_30_Tc3xxInf01_IsSectorIndexValid()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
VMEM_30_TC3XXINF01_LOCAL_INLINE FUNC(boolean, VMEM_30_TC3XXINF01_CODE) vMem_30_Tc3xxInf01_IsSectorIndexValid(vMem_30_Tc3xxInf01_InstanceIdType InstanceId, uint32 SectorIndex)
{

  /* By now it has already been checked, that InstanceId is valid. */
  return (boolean)(SectorIndex < vMem_30_Tc3xxInf01_GetMemSectorEndIdxOfvMemInstance(InstanceId));
}

/**********************************************************************************************************************
 *  vMem_30_Tc3xxInf01_IsInstanceIdValid()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
 VMEM_30_TC3XXINF01_LOCAL_INLINE FUNC(boolean, VMEM_30_TC3XXINF01_CODE) vMem_30_Tc3xxInf01_IsInstanceIdValid(vMem_30_Tc3xxInf01_InstanceIdType InstanceId)
 {
   return (boolean)(InstanceId < vMem_30_Tc3xxInf01_GetSizeOfvMemInstance());
 }
#endif /* (VMEM_30_TC3XXINF01_DEV_ERROR_DETECT == STD_ON) */

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  vMem_30_Tc3xxInf01_Read()
 *********************************************************************************************************************/
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
 */
FUNC(Std_ReturnType, VMEM_30_TC3XXINF01_CODE) vMem_30_Tc3xxInf01_Read(
  vMem_30_Tc3xxInf01_InstanceIdType InstanceId,
  vMem_30_Tc3xxInf01_AddressType SourceAddress,
  vMem_30_Tc3xxInf01_DataPtrType TargetAddressPtr,
  vMem_30_Tc3xxInf01_LengthType Length
  )
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 errorId = VMEM_30_TC3XXINF01_E_NO_ERROR;
  Std_ReturnType retVal = E_NOT_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */
  
  /* ----- Development Error Checks ------------------------------------- */
#if (VMEM_30_TC3XXINF01_DEV_ERROR_DETECT == STD_ON)
  /* Check initialization state of the component */
  if (vMem_30_Tc3xxInf01_ModuleInitialized == VMEM_30_TC3XXINF01_UNINIT)
  {
    errorId = VMEM_30_TC3XXINF01_E_UNINIT;
  }
  else if (vMem_30_Tc3xxInf01_IsInstanceIdValid(InstanceId) == FALSE)
  {
    errorId = VMEM_30_TC3XXINF01_E_PARAM_INSTANCE_ID;
  }
  else if (vMem_30_Tc3xxInf01_InstancePendingCheck(InstanceId) == TRUE)
  {
    errorId = VMEM_30_TC3XXINF01_E_PENDING;
  }
  else if (TargetAddressPtr == NULL_PTR)
  {
    errorId = VMEM_30_TC3XXINF01_E_PARAM_POINTER;
  }
  else if(vMem_30_Tc3xxInf01_ReadAddressCheck(InstanceId, SourceAddress) == FALSE)
  {
      errorId = VMEM_30_TC3XXINF01_E_PARAM_ADDRESS;
  }
  else if (vMem_30_Tc3xxInf01_ReadLengthCheck(InstanceId, SourceAddress, Length) == FALSE)
  {
      errorId = VMEM_30_TC3XXINF01_E_PARAM_LENGTH;
  }
  else
#endif
  {
    /* ----- Implementation ----------------------------------------------- */
    retVal = vMem_30_Tc3xxInf01_LLRead(InstanceId, SourceAddress, TargetAddressPtr, Length); /* SBSW_vMem_30_Tc3xxInf01_UserPointer */
  }
  
  /* ----- Development Error Report --------------------------------------- */
#if (VMEM_30_TC3XXINF01_DEV_ERROR_REPORT == STD_ON)
  if (errorId != VMEM_30_TC3XXINF01_E_NO_ERROR)
  {
    (void)Det_ReportError(VMEM_30_TC3XXINF01_MODULE_ID, VMEM_30_TC3XXINF01_INSTANCE_ID_DET, VMEM_30_TC3XXINF01_SID_READ, errorId);
  }
#else
  VMEM_30_TC3XXINF01_DUMMY_STATEMENT(errorId); /* PRQA S 3112 */ /* MD_MSR_DummyStmt */
#endif

  return retVal;
} /* vMem_30_Tc3xxInf01_Read() */ /* PRQA S 6080 */ /* MD_MSR_STMIF */

/**********************************************************************************************************************
 *  vMem_30_Tc3xxInf01_Write()
 *********************************************************************************************************************/
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
 */
FUNC(Std_ReturnType, VMEM_30_TC3XXINF01_CODE) vMem_30_Tc3xxInf01_Write(
  vMem_30_Tc3xxInf01_InstanceIdType InstanceId,
  vMem_30_Tc3xxInf01_AddressType TargetAddress,
  vMem_30_Tc3xxInf01_ConstDataPtrType SourceAddressPtr,
  vMem_30_Tc3xxInf01_LengthType Length
  )
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 errorId = VMEM_30_TC3XXINF01_E_NO_ERROR;
  Std_ReturnType retVal = E_NOT_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  /* ----- Development Error Checks ------------------------------------- */
#if (VMEM_30_TC3XXINF01_DEV_ERROR_DETECT == STD_ON)
  /* Check initialization state of the component */
  if (vMem_30_Tc3xxInf01_ModuleInitialized == VMEM_30_TC3XXINF01_UNINIT)
  {
    errorId = VMEM_30_TC3XXINF01_E_UNINIT;
  }
  else if (vMem_30_Tc3xxInf01_IsInstanceIdValid(InstanceId) == FALSE)
  {
    errorId = VMEM_30_TC3XXINF01_E_PARAM_INSTANCE_ID;
  }
  else if (vMem_30_Tc3xxInf01_InstancePendingCheck(InstanceId) == TRUE)
  {
    errorId = VMEM_30_TC3XXINF01_E_PENDING;
  }
  else if (SourceAddressPtr == NULL_PTR)
  {
    errorId = VMEM_30_TC3XXINF01_E_PARAM_POINTER;
  }
  else if(vMem_30_Tc3xxInf01_IsAddressPageAligned(InstanceId, TargetAddress) == FALSE)
  {
      errorId = VMEM_30_TC3XXINF01_E_PARAM_ADDRESS;
  }
  else if (vMem_30_Tc3xxInf01_WriteLengthCheck(InstanceId, TargetAddress, Length) == FALSE)
  {
      errorId = VMEM_30_TC3XXINF01_E_PARAM_LENGTH;
  }
  else
#endif
  {
    /* ----- Implementation ----------------------------------------------- */
    retVal = vMem_30_Tc3xxInf01_LLWrite(InstanceId, TargetAddress, SourceAddressPtr, Length); /* SBSW_vMem_30_Tc3xxInf01_UserPointer */
  }

  /* ----- Development Error Report --------------------------------------- */
#if (VMEM_30_TC3XXINF01_DEV_ERROR_REPORT == STD_ON)
  if (errorId != VMEM_30_TC3XXINF01_E_NO_ERROR)
  {
    (void)Det_ReportError(VMEM_30_TC3XXINF01_MODULE_ID, VMEM_30_TC3XXINF01_INSTANCE_ID_DET, VMEM_30_TC3XXINF01_SID_WRITE, errorId);
  }
#else
  VMEM_30_TC3XXINF01_DUMMY_STATEMENT(errorId); /* PRQA S 3112 */ /* MD_MSR_DummyStmt */
#endif

  return retVal;
} /* vMem_30_Tc3xxInf01_Write() */ /* PRQA S 6080 */ /* MD_MSR_STMIF */


/**********************************************************************************************************************
 *  vMem_30_Tc3xxInf01_Erase()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 */
FUNC(Std_ReturnType, VMEM_30_TC3XXINF01_CODE) vMem_30_Tc3xxInf01_Erase(
  vMem_30_Tc3xxInf01_InstanceIdType InstanceId,
  vMem_30_Tc3xxInf01_AddressType TargetAddress,
  vMem_30_Tc3xxInf01_LengthType Length
  )
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 errorId = VMEM_30_TC3XXINF01_E_NO_ERROR;
  Std_ReturnType retVal = E_NOT_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */
  
  /* ----- Development Error Checks ------------------------------------- */
#if (VMEM_30_TC3XXINF01_DEV_ERROR_DETECT == STD_ON)
  /* Check initialization state of the component */
  if (vMem_30_Tc3xxInf01_ModuleInitialized == VMEM_30_TC3XXINF01_UNINIT)
  {
    errorId = VMEM_30_TC3XXINF01_E_UNINIT;
  }
  else if (vMem_30_Tc3xxInf01_IsInstanceIdValid(InstanceId) == FALSE)
  {
    errorId = VMEM_30_TC3XXINF01_E_PARAM_INSTANCE_ID;
  }
  else if (vMem_30_Tc3xxInf01_InstancePendingCheck(InstanceId) == TRUE)
  {
    errorId = VMEM_30_TC3XXINF01_E_PENDING;
  }
  else if(vMem_30_Tc3xxInf01_IsAddressSectorAligned(InstanceId, TargetAddress) == FALSE)
  {
      errorId = VMEM_30_TC3XXINF01_E_PARAM_ADDRESS;
  }
  else if (vMem_30_Tc3xxInf01_EraseLengthCheck(InstanceId, TargetAddress, Length) == FALSE)
  {
      errorId = VMEM_30_TC3XXINF01_E_PARAM_LENGTH;
  }
  else
#endif
  {
    /* ----- Implementation ----------------------------------------------- */
    retVal = vMem_30_Tc3xxInf01_LLErase(InstanceId, TargetAddress, Length);
  }

  /* ----- Development Error Report --------------------------------------- */
#if (VMEM_30_TC3XXINF01_DEV_ERROR_REPORT == STD_ON)
  if (errorId != VMEM_30_TC3XXINF01_E_NO_ERROR)
  {
    (void)Det_ReportError(VMEM_30_TC3XXINF01_MODULE_ID, VMEM_30_TC3XXINF01_INSTANCE_ID_DET, VMEM_30_TC3XXINF01_SID_ERASE, errorId);
  }
#else
  VMEM_30_TC3XXINF01_DUMMY_STATEMENT(errorId); /* PRQA S 3112 */ /* MD_MSR_DummyStmt */
#endif

  return retVal;
} /* vMem_30_Tc3xxInf01_Erase() */ /* PRQA S 6080 */ /* MD_MSR_STMIF */

/**********************************************************************************************************************
 *  vMem_30_Tc3xxInf01_IsBlank()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 */
FUNC(Std_ReturnType, VMEM_30_TC3XXINF01_CODE) vMem_30_Tc3xxInf01_IsBlank(
  vMem_30_Tc3xxInf01_InstanceIdType InstanceId,
  vMem_30_Tc3xxInf01_AddressType TargetAddress,
  vMem_30_Tc3xxInf01_LengthType Length
  )
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 errorId = VMEM_30_TC3XXINF01_E_NO_ERROR;
  Std_ReturnType retVal = E_NOT_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  /* ----- Development Error Checks ------------------------------------- */
#if (VMEM_30_TC3XXINF01_DEV_ERROR_DETECT == STD_ON)
  /* Check initialization state of the component */
  if (vMem_30_Tc3xxInf01_ModuleInitialized == VMEM_30_TC3XXINF01_UNINIT)
  {
    errorId = VMEM_30_TC3XXINF01_E_UNINIT;
  }
  else if (vMem_30_Tc3xxInf01_IsInstanceIdValid(InstanceId) == FALSE)
  {
    errorId = VMEM_30_TC3XXINF01_E_PARAM_INSTANCE_ID;
  }
  else if (vMem_30_Tc3xxInf01_InstancePendingCheck(InstanceId) == TRUE)
  {
    errorId = VMEM_30_TC3XXINF01_E_PENDING;
  }
  else if(vMem_30_Tc3xxInf01_IsAddressPageAligned(InstanceId, TargetAddress) == FALSE)
  {
      errorId = VMEM_30_TC3XXINF01_E_PARAM_ADDRESS;
  }
  else if (vMem_30_Tc3xxInf01_IsBlankLengthCheck(InstanceId, TargetAddress, Length) == FALSE)
  {
      errorId = VMEM_30_TC3XXINF01_E_PARAM_LENGTH;
  }
  else
#endif
  {
    /* ----- Implementation ----------------------------------------------- */
    retVal = vMem_30_Tc3xxInf01_LLIsBlank(InstanceId, TargetAddress, Length);
  }

  /* ----- Development Error Report --------------------------------------- */
#if (VMEM_30_TC3XXINF01_DEV_ERROR_REPORT == STD_ON)
  if (errorId != VMEM_30_TC3XXINF01_E_NO_ERROR)
  {
    (void)Det_ReportError(VMEM_30_TC3XXINF01_MODULE_ID, VMEM_30_TC3XXINF01_INSTANCE_ID_DET, VMEM_30_TC3XXINF01_SID_IS_BLANK, errorId);
  }
#else
  VMEM_30_TC3XXINF01_DUMMY_STATEMENT(errorId); /* PRQA S 3112 */ /* MD_MSR_DummyStmt */
#endif

  return retVal;
} /* vMem_30_Tc3xxInf01_IsBlank() */ /* PRQA S 6080 */ /* MD_MSR_STMIF */

/**********************************************************************************************************************
 *  vMem_30_Tc3xxInf01_GetJobResult()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
FUNC(vMem_30_Tc3xxInf01_JobResultType, VMEM_30_TC3XXINF01_CODE) vMem_30_Tc3xxInf01_GetJobResult(
  vMem_30_Tc3xxInf01_InstanceIdType InstanceId)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 errorId = VMEM_30_TC3XXINF01_E_NO_ERROR;
  vMem_30_Tc3xxInf01_JobResultType jobResult = VMEM_JOB_FAILED; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  /* ----- Development Error Checks ------------------------------------- */
#if (VMEM_30_TC3XXINF01_DEV_ERROR_DETECT == STD_ON)
  /* Check initialization state of the component */
  if (vMem_30_Tc3xxInf01_ModuleInitialized == VMEM_30_TC3XXINF01_UNINIT)
  {
    errorId = VMEM_30_TC3XXINF01_E_UNINIT;
  }
  else if (vMem_30_Tc3xxInf01_IsInstanceIdValid(InstanceId) == FALSE)
  {
    errorId = VMEM_30_TC3XXINF01_E_PARAM_INSTANCE_ID;
  }
  else
#endif
  {
  /* ----- Implementation ----------------------------------------------- */
    jobResult = vMem_30_Tc3xxInf01_LLGetJobResult(InstanceId);
  }

  /* ----- Development Error Report --------------------------------------- */
#if (VMEM_30_TC3XXINF01_DEV_ERROR_REPORT == STD_ON)
  if (errorId != VMEM_30_TC3XXINF01_E_NO_ERROR)
  {
    (void)Det_ReportError(VMEM_30_TC3XXINF01_MODULE_ID, VMEM_30_TC3XXINF01_INSTANCE_ID_DET, VMEM_30_TC3XXINF01_SID_GET_JOB_RESULT, errorId);
  }
#else
  VMEM_30_TC3XXINF01_DUMMY_STATEMENT(errorId); /* PRQA S 3112 */ /* MD_MSR_DummyStmt */
#endif

  return jobResult;
} /* vMem_30_Tc3xxInf01_GetJobResult() */



/**********************************************************************************************************************
 *  vMem_30_Tc3xxInf01_InitMemory()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(void, VMEM_30_TC3XXINF01_CODE) vMem_30_Tc3xxInf01_InitMemory(void)
{
  /* ----- Implementation ----------------------------------------------- */
#if (VMEM_30_TC3XXINF01_DEV_ERROR_DETECT == STD_ON)
  vMem_30_Tc3xxInf01_ModuleInitialized = VMEM_30_TC3XXINF01_UNINIT;
#endif
}  /* vMem_30_Tc3xxInf01_InitMemory() */


/**********************************************************************************************************************
 *  vMem_30_Tc3xxInf01_Init()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
FUNC(void, VMEM_30_TC3XXINF01_CODE) vMem_30_Tc3xxInf01_Init(P2CONST(vMem_30_Tc3xxInf01_ConfigType, AUTOMATIC, VMEM_30_TC3XXINF01_PBCFG) ConfigPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 errorId = VMEM_30_TC3XXINF01_E_NO_ERROR;

  /* ----- Development Error Checks ------------------------------------- */
#if (VMEM_30_TC3XXINF01_DEV_ERROR_DETECT == STD_ON)
  if (vMem_30_Tc3xxInf01_InitPendingCheck() == FALSE)
  {
    errorId = VMEM_30_TC3XXINF01_E_PENDING;
  }
  else
#endif
  {
  /* ----- Implementation ----------------------------------------------- */
  /* Do not use the ConfigPtr, simply ignore the parameter (vMem_30_Tc3xxInf01 is not post build capable yet). */
    if (vMem_30_Tc3xxInf01_LLInit() == E_NOT_OK)
    {
      errorId = VMEM_30_TC3XXINF01_E_INITIALIZATION_FAILED;
    }
  }
#if (VMEM_30_TC3XXINF01_DEV_ERROR_DETECT == STD_ON)
  if (errorId == VMEM_30_TC3XXINF01_E_NO_ERROR)
  {
    vMem_30_Tc3xxInf01_ModuleInitialized = VMEM_30_TC3XXINF01_INIT;
  }
#endif
#if (VMEM_30_TC3XXINF01_DEV_ERROR_REPORT == STD_ON)
  else
  {
    (void)Det_ReportError(VMEM_30_TC3XXINF01_MODULE_ID, VMEM_30_TC3XXINF01_INSTANCE_ID_DET, VMEM_30_TC3XXINF01_SID_INIT, errorId);
  }
#else
  VMEM_30_TC3XXINF01_DUMMY_STATEMENT(errorId); /* PRQA S 3112 */ /* MD_MSR_DummyStmt */
#endif
  VMEM_30_TC3XXINF01_DUMMY_STATEMENT(ConfigPtr); /* PRQA S 3112 */ /* MD_MSR_DummyStmt */
} /* vMem_30_Tc3xxInf01_Init() */


/***********************************************************************************************************************
 *  vMem_30_Tc3xxInf01_MainFunction
 **********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(void, VMEM_30_TC3XXINF01_CODE) vMem_30_Tc3xxInf01_MainFunction(void)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 errorId = VMEM_30_TC3XXINF01_E_NO_ERROR;

  /* ----- Development Error Checks ------------------------------------- */
#if (VMEM_30_TC3XXINF01_DEV_ERROR_DETECT == STD_ON)
  /* Check initialization state of the component */
  if (vMem_30_Tc3xxInf01_ModuleInitialized == VMEM_30_TC3XXINF01_UNINIT)
  {
    errorId = VMEM_30_TC3XXINF01_E_UNINIT;
  }
  else
#endif
  {
    vMem_30_Tc3xxInf01_LLProcessing();
  }
  /* ----- Development Error Report --------------------------------------- */
#if (VMEM_30_TC3XXINF01_DEV_ERROR_REPORT == STD_ON)
  if (errorId != VMEM_30_TC3XXINF01_E_NO_ERROR)
  {
    (void)Det_ReportError(VMEM_30_TC3XXINF01_MODULE_ID, VMEM_30_TC3XXINF01_INSTANCE_ID_DET, VMEM_30_TC3XXINF01_SID_MAIN_FUNCTION, errorId);
  }
#else
  VMEM_30_TC3XXINF01_DUMMY_STATEMENT(errorId); /* PRQA S 3112 */ /* MD_MSR_DummyStmt */
#endif
} /* vMem_30_Tc3xxInf01_MainFunction */


#if (VMEM_30_TC3XXINF01_VERSION_INFO_API == STD_ON)
/**********************************************************************************************************************
 *  vMem_30_Tc3xxInf01_GetVersionInfo()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(void, VMEM_30_TC3XXINF01_CODE) vMem_30_Tc3xxInf01_GetVersionInfo(P2VAR(Std_VersionInfoType, AUTOMATIC, VMEM_30_TC3XXINF01_APPL_VAR) VersionInfo)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 errorId = VMEM_30_TC3XXINF01_E_NO_ERROR;
  
  /* ----- Development Error Checks ------------------------------------- */
# if (VMEM_30_TC3XXINF01_DEV_ERROR_DETECT == STD_ON)
  if (VersionInfo == NULL_PTR)
  {
    errorId = VMEM_30_TC3XXINF01_E_PARAM_POINTER;
  }
  else
# endif
  {
    /* ----- Implementation ----------------------------------------------- */
    VersionInfo->vendorID = (VMEM_30_TC3XXINF01_VENDOR_ID); /* SBSW_vMem_30_Tc3xxInf01_UserPointer */
    VersionInfo->moduleID = (VMEM_30_TC3XXINF01_MODULE_ID); /* SBSW_vMem_30_Tc3xxInf01_UserPointer */
    VersionInfo->sw_major_version = (VMEM_30_TC3XXINF01_SW_MAJOR_VERSION); /* SBSW_vMem_30_Tc3xxInf01_UserPointer */
    VersionInfo->sw_minor_version = (VMEM_30_TC3XXINF01_SW_MINOR_VERSION); /* SBSW_vMem_30_Tc3xxInf01_UserPointer */
    VersionInfo->sw_patch_version = (VMEM_30_TC3XXINF01_SW_PATCH_VERSION); /* SBSW_vMem_30_Tc3xxInf01_UserPointer */
  }

  /* ----- Development Error Report --------------------------------------- */
# if (VMEM_30_TC3XXINF01_DEV_ERROR_REPORT == STD_ON)
  if (errorId != VMEM_30_TC3XXINF01_E_NO_ERROR)
  {
    (void)Det_ReportError(VMEM_30_TC3XXINF01_MODULE_ID, VMEM_30_TC3XXINF01_INSTANCE_ID_DET, VMEM_30_TC3XXINF01_SID_GET_VERSION_INFO, errorId);
  }
# else
  VMEM_30_TC3XXINF01_DUMMY_STATEMENT(errorId); /* PRQA S 3112 */ /* MD_MSR_DummyStmt */
# endif
}
#endif


#define VMEM_30_TC3XXINF01_STOP_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* Module specific MISRA deviations:

MD_CRC_2.1_StaticFunctionNotUsed:
    Reason: This inline functions are defined as a utility functionality and shall be accessible by each translation
            unit of the component. In some cases this functionality might not be used. This is not a problem as the
            compiler will optimize this code away in this case.
    Risk: No risk.
    Prevention: A compile switch could be introduced.
    
MD_VMEM_30_TC3XXINF01_CORE_13.5_queries:
     Reason: Functions at right hand of || or && are defined to have no side-effects. Therefore it is intended to omit
             unnecessary calls. Avoiding this deviation would degrade code structure without benefits (nesting of
             IF-clauses).
     Risk: A function HAS side effects, leading to unexpected behavior, if call is omitted.
     Prevention: Review; make sure, that these functions do not change any global value,
                 and that they do not access "volatile" values.

*/


/* SBSW_JUSTIFICATION_BEGIN

\ID SBSW_vMem_30_Tc3xxInf01_UserPointer
 \DESCRIPTION Pointer write access or function call: vMem_30_Tc3xxInf01 gets a pointer to write information to. vMem_30_Tc3xxInf01 expects the pointer to be typed
              correctly and will use it, if it is != NULL_PTR. vMem_30_Tc3xxInf01 writes to the pointer or forwards it to another component internal function.
 \COUNTERMEASURE \R vMem_30_Tc3xxInf01 checks the passed pointer to be != NULL_PTR. User is responsible for pointer correctness.

SBSW_JUSTIFICATION_END */

/* START_COVERAGE_JUSTIFICATION

Variant coverage:

\ID COV_VMEM_30_TC3XXINF01_COMPATIBILITY
 \ACCEPT TX
 \REASON COV_MSR_COMPATIBILITY

\ID COV_VMEM_30_TC3XXINF01_UTILITYCODE_UNUSED
 \ACCEPT X
 \REASON vMem_core is the hardware independent base (and template) for all hardware dependent versions. It provides a
         header file vMem_30_Tc3xxInf01_IntShared.h with shared utility code that may be used from all subcomponents of vMem_30_Tc3xxInf01. The
         core variant uses this code only for development error checks and therefore is not used in some configuration
         variants at all.

END_COVERAGE_JUSTIFICATION
*/

/**********************************************************************************************************************
 *  END OF FILE: vMem_30_Tc3xxInf01.c
 *********************************************************************************************************************/
