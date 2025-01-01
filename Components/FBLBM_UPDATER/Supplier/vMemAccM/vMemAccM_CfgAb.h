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
/*!        \file  vMemAccM_CfgAb.h
 *        \brief  vMemAccM configuration abstraction submodule header file.
 *      \details  vMemAccM configuration abstraction submodule provides functions to "convert" one or more values
 *                to other (e.g. address area identifier and address to a subaddress area identifier),
 *                some value checker functions and the submodule takes care about the memory mapping variant handling.
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 *********************************************************************************************************************/

#if !defined (VMEMACCM_CFGAB_H)
# define VMEMACCM_CFGAB_H

# include "vMemAccM_Cfg.h"
# include "vMemAccM_IntCfg.h"

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
# define VMEMACCM_START_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  vMemAccM_CfgAbInit
 *********************************************************************************************************************/
/*!
 * \brief       Initializes the configuration abstraction submodule.
 * \details     -
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */
FUNC(void, VMEMACCM_CODE) vMemAccM_CfgAbInit(void);

/**********************************************************************************************************************
 *  vMemAccM_CfgAbAddressAndLengthValid
 *********************************************************************************************************************/
/*!
 * \brief       Checks whether the address and length fits to the address area and do not include gaps.
 * \details     -
 * \param[in]   AddressAreaId as array index, used to access the virtual information.
 * \param[in]   Address pointing to the first byte of the request (virtual address space).
 * \param[in]   Length of the job.
 * \return      TRUE, if the address and length fits to the address area;
 *              FALSE otherwise.
 * \pre         -
 * \context     ANY
 * \reentrant   FALSE
 * \synchronous TRUE
 */
FUNC(boolean, VMEMACCM_CODE) vMemAccM_CfgAbAddressAndLengthValid
(
  vMemAccM_AddressAreaIdType AddressAreaId,
  vMemAccM_AddressType Address,
  vMemAccM_LengthType Length
);

/**********************************************************************************************************************
 *  vMemAccM_CfgAbGetSubAddrAreaId
 *********************************************************************************************************************/
/*!
 * \brief       Returns the sub address area ID where the address belongs to.
 * \details     -
 * \param[in]   AddressAreaId as array index, used to access the virtual information.
 * \param[in]   Address to be used to find the related sub address area identifier.
 * \return      Sub address area ID (out of range/ end index, if the Address could not be assigned).
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */
FUNC(vMemAccM_AddressAreaIdType, VMEMACCM_CODE) vMemAccM_CfgAbGetSubAddrAreaId
(
  vMemAccM_AddressAreaIdType AddressAreaId,
  vMemAccM_AddressType Address
);

/**********************************************************************************************************************
 *  vMemAccM_CfgAbGetAddressAreaVariantId
 *********************************************************************************************************************/
/*!
 * \brief       Returns the current address area variant ID.
 * \details     Since an address area can have static or dynamic memory mapping, the function returns always the same
 *              variant ID (static address area), or the currently active variant ID (dynamic address area).
 * \param[in]   AddressAreaId as array index, used to get the virtual information.
 * \return      Address area variant ID (always valid).
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */
FUNC(vMemAccM_VariantIdType, VMEMACCM_CODE) vMemAccM_CfgAbGetAddressAreaVariantId
(
  vMemAccM_AddressAreaIdType AddressAreaId
);

#if (VMEMACCM_DEV_ERROR_DETECT == STD_ON)
/**********************************************************************************************************************
 *  vMemAccM_CfgAbAddressAreaIdValid
 *********************************************************************************************************************/
/*!
 * \brief       Checks the address area ID to be valid (within range).
 * \details     -
 * \param[in]   AddressAreaId as array index, used to access the virtual information.
 * \return      TRUE, if the address area ID is valid;
 *              FALSE otherwise.
 * \pre         VMEMACCM_DEV_ERROR_DETECT == STD_ON
 * \context     ANY
 * \reentrant   FALSE
 * \synchronous TRUE
 */
FUNC(boolean, VMEMACCM_CODE) vMemAccM_CfgAbAddressAreaIdValid
(
  vMemAccM_AddressAreaIdType AddressAreaId
);
#endif /* (VMEMACCM_DEV_ERROR_DETECT == STD_ON) */

#if (VMEMACCM_MINIMAL_SYNC == STD_OFF)
# if (VMEMACCM_DEV_ERROR_DETECT == STD_ON)
#  if (VMEMACCM_MULTI_PARTITION_SATELLITE == STD_OFF)
/**********************************************************************************************************************
 *  vMemAccM_CfgAbHwFuncIndexValid
 *********************************************************************************************************************/
/*!
 * \brief       Checks whether the passed HW specific function index belongs to a sub address area of the address area.
 * \details     -
 * \param[in]   AddressAreaId as array index, used to access the virtual information.
 * \param[in]   HwId pointing to the hardware driver the job shall be forwarded to.
 * \param[in]   vMemHwSpecificFuncIndex as an array index pointing to the hardware specific function pointer.
 * \return      TRUE, if the HW specific index is valid;
 *              FALSE otherwise.
 * \pre         VMEMACCM_DEV_ERROR_DETECT == STD_ON && vMemAccM is not the satellite within a multi partition configuration.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \note        The function expects the AddressAreaId and the HwId to be valid and does not check the values!
 *              Caller has to ensure parameter correctness (e.g. parameter checks in public API).
 */
FUNC(boolean, VMEMACCM_CODE) vMemAccM_CfgAbHwFuncIndexValid
(
  vMemAccM_AddressAreaIdType AddressAreaId,
  vMemAccM_HwIdType HwId,
  vMemAccM_vMemHwSpecificFuncIndexType vMemHwSpecificFuncIndex
);

/**********************************************************************************************************************
 *  vMemAccM_CfgAbHwIdValid
 *********************************************************************************************************************/
/*!
 * \brief       Checks the passed HwId to exist/ be configured.
 * \details     -
 * \param[in]   AddressAreaId as array index, used to access the virtual information.
 * \param[in]   HwId pointing to the hardware driver the job shall be forwarded to.
 * \return      TRUE, if HwId is valid;
 *              FALSE otherwise.
 * \pre         VMEMACCM_DEV_ERROR_DETECT == STD_ON && vMemAccM is not the satellite within a multi partition configuration.
 * \context     ANY
 * \reentrant   FALSE
 * \synchronous TRUE
 */
FUNC(boolean, VMEMACCM_CODE) vMemAccM_CfgAbHwIdValid
(
  vMemAccM_AddressAreaIdType AddressAreaId,
  vMemAccM_HwIdType HwId
);

#  endif /* (VMEMACCM_MULTI_PARTITION_SATELLITE == STD_ON) */
# endif /* (VMEMACCM_DEV_ERROR_DETECT == STD_ON) */

/**********************************************************************************************************************
 *  vMemAccM_CfgAbIsAddressRangeInSubAddressArea
 *********************************************************************************************************************/
/*!
 * \brief       Checks if the given address and length fit completely into the given sub address area.
 * \details     -
 * \param[in]   SubAddressAreaId as array index, used to access the physical information.
 * \param[in]   Address as the virtual address to check.
 * \param[in]   Length as the length to check.
 * \return      TRUE, if the address and length fits into the sub address area completely;
 *              FALSE otherwise.
 * \pre         -
 * \context     ANY
 * \reentrant   FALSE
 * \synchronous TRUE
 */
FUNC(boolean, VMEMACCM_CODE) vMemAccM_CfgAbIsAddressRangeInSubAddressArea
(
  vMemAccM_AddressAreaIdType SubAddressAreaId,
  vMemAccM_AddressType Address,
  vMemAccM_LengthType Length
);

/**********************************************************************************************************************
 *  vMemAccM_CfgAbGetSubAddrAreaIdViaHwId
 *********************************************************************************************************************/
/*!
 * \brief       Returns the sub address area ID where the vMem identifier belongs to.
 * \details     -
 * \param[in]   AddressAreaId as array index, used to access the virtual information.
 * \param[in]   HwId to be used to find the related sub address area identifier.
 * \return      Sub address area ID (out of range/ end index, if the HwId could not be assigned).
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */
FUNC(vMemAccM_AddressAreaIdType, VMEMACCM_CODE) vMemAccM_CfgAbGetSubAddrAreaIdViaHwId
(
  vMemAccM_AddressAreaIdType AddressAreaId,
  vMemAccM_HwIdType HwId
);

/**********************************************************************************************************************
 *  vMemAccM_CfgAbSetActiveVariantId
 *********************************************************************************************************************/
/*!
 * \brief       Sets the currently active memory mapping variant to passed value.
 * \details     -
 * \param[in]   VariantId as the variant identifier to be active.
 * \pre         -
 * \context     TASK
 * \reentrant   TRUE
 * \synchronous TRUE
 * \note        The function expects the variant identifier to be valid and will not check the value.
 */
FUNC(void, VMEMACCM_CODE) vMemAccM_CfgAbSetActiveVariantId
(
  vMemAccM_VariantIdType VariantId
);

# if ( (VMEMACCM_PARTITION_USECASE == VMEMACCM_MULTI_PARTITION_MULTI_ACCESSORS) || \
      (VMEMACCM_PARTITION_USECASE == VMEMACCM_MULTI_PARTITION_SINGLE_ACCESSOR))
/**********************************************************************************************************************
 *  Multi partition shared functions
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  vMemAccM_CfgAbSetPublishedPriority
 *********************************************************************************************************************/
/*!
 * \brief       Sets the published priority of the currently active partition.
 * \details     -
 * \param[in]   Priority as the priority to be published to the current partition.
 * \pre         Multi partition use case.
 * \context     TASK
 * \reentrant   TRUE
 * \synchronous TRUE
 * \note        The function expects the token to be valid and will not check the value.
 */
FUNC(void, VMEMACCM_CODE) vMemAccM_CfgAbSetPublishedPriority
(
    vMemAccM_PublishPriorityType Priority
);

#  if (VMEMACCM_MULTIPARTITION_PARTITION_ID == VMEMACCM_MULTIPARTITION_MASTER_PARTITION_ID)
/**********************************************************************************************************************
 *  vMemAccM_CfgAbMpSetToken
 *********************************************************************************************************************/
/*!
 * \brief       Sets the multipartition token to the given value.
 * \details     -
 * \param[in]   CurrentToken holding the current partition number.
 * \param[in]   PreviousToken holding the last active partition number.
 * \pre         Multi partition master.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */
FUNC(void, VMEMACCM_CODE) vMemAccM_CfgAbMpSetToken
(
    vMemAccM_NVRAMAccessTokenType CurrentToken, 
    vMemAccM_NVRAMAccessTokenType PreviousToken
);
#  endif /* (VMEMACCM_MULTIPARTITION_PARTITION_ID == VMEMACCM_MULTIPARTITION_MASTER_PARTITION_ID) */

# endif /* ((VMEMACCM_PARTITION_USECASE == VMEMACCM_MULTI_PARTITION_MULTI_ACCESSORS) || \
      (VMEMACCM_PARTITION_USECASE == VMEMACCM_MULTI_PARTITION_SINGLE_ACCESSOR)) */
 
/**********************************************************************************************************************
 *  Multi partition multi accessor use case
 *********************************************************************************************************************/

# if (VMEMACCM_PARTITION_USECASE == VMEMACCM_MULTI_PARTITION_MULTI_ACCESSORS)
/**********************************************************************************************************************
 *  vMemAccM_CfgAbGetMpPartitionPriority
 *********************************************************************************************************************/
/*!
 * \brief       Retrieves the priority of the partition with the given id.
 * \details     -
 * \param[in]   PartitionId as the partition identifier. Valid range: 0-253 (NOT uint32)
 * \pre         Multi partition use case.
 * \context     TASK
 * \reentrant   TRUE
 * \synchronous TRUE
 * \note        The function expects the token to be valid and will not check the value.
 */
FUNC(vMemAccM_PublishPriorityType, VMEMACCM_CODE) vMemAccM_CfgAbGetMpPartitionPriority
(
  vMemAccM_NVRAMAccessTokenType PartitionId
);

/**********************************************************************************************************************
 *  vMemAccM_CfgAbMpGetToken
 *********************************************************************************************************************/
/*!
 * \brief       Returns the value of the multipartition token.
 * \details     -
 * \return      Returns the value of the token.
 * \pre         Multi partition use case.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */
FUNC(vMemAccM_NVRAMAccessTokenType, VMEMACCM_CODE) vMemAccM_CfgAbMpGetToken(void);

/**********************************************************************************************************************
 *  vMemAccM_CfgAbMpGetLastActivePartitionFromToken
 *********************************************************************************************************************/
/*!
 * \brief       Gets the last active partition, which is stored in the token.
 * \details     -
 * \return      Returns the value of the last active partition.
 * \param[in]   Token holding the current information of the multipartition use case.
 * \pre         Multi partition use case.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */
FUNC(vMemAccM_MultiPartitionPartitionIdType, VMEMACCM_CODE) vMemAccM_CfgAbMpGetLastActivePartitionFromToken
(
    vMemAccM_NVRAMAccessTokenType Token
);

/**********************************************************************************************************************
 *  vMemAccM_CfgAbMpGetCurrentActivePartitionFromToken
 *********************************************************************************************************************/
/*!
 * \brief       Gets the current active partition, which is stored in the token.
 * \details     -
 * \return      Returns the value of the current active partition.
 * \param[in]   Token holding the current information of the multipartition use case.
 * \pre         Multi partition use case.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */
FUNC(vMemAccM_MultiPartitionPartitionIdType, VMEMACCM_CODE) vMemAccM_CfgAbMpGetCurrentActivePartitionFromToken
(
    vMemAccM_NVRAMAccessTokenType Token
);

# endif /* (VMEMACCM_PARTITION_USECASE == VMEMACCM_MULTI_PARTITION_MULTI_ACCESSORS) */

# if (VMEMACCM_MULTI_PARTITION_SATELLITE == STD_ON)
/**********************************************************************************************************************
 *  vMemAccM_CfgAbMpGetSatelliteDataPtr
 *********************************************************************************************************************/
/*!
 * \brief       Gets the data pointer for the multipartition satellite.
 * \details     -
 * \return      Returns the pointer to the partition data.
 * \pre         Multi partition satellite use case.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */
FUNC(vMemAccM_PublishRequestDataPtrType, VMEMACCM_CODE) vMemAccM_CfgAbMpGetSatelliteDataPtr(void);
# endif /* (VMEMACCM_MULTI_PARTITION_SATELLITE == STD_ON) */

# if (VMEMACCM_PARTITION_USECASE == VMEMACCM_MULTI_PARTITION_SINGLE_ACCESSOR)
/**********************************************************************************************************************
 *  vMemAccM_CfgAbGetMpPartitionPriority
 *********************************************************************************************************************/
/*!
 * \brief       Retrieves the priority of the partition with the given id.
 * \details     -
 * \param[in]   PartitionId as the partition identifier. Valid range: 0-253 (NOT uint32)
 * \pre         Multi partition use case.
 * \context     TASK
 * \reentrant   TRUE
 * \synchronous TRUE
 * \note        The function expects the token to be valid and will not check the value.
 */
FUNC(vMemAccM_PublishPriorityType, VMEMACCM_CODE) vMemAccM_CfgAbGetMpPartitionPriority
(
  vMemAccM_NVRAMAccessTokenType PartitionId
);
#  if (VMEMACCM_MULTI_PARTITION_SINGLE_ACCESSOR_MASTER == STD_ON)
/**********************************************************************************************************************
 *  vMemAccM_CfgAbMpGetToken
 *********************************************************************************************************************/
/*!
 * \brief       Returns the value of the multipartition token.
 * \details     -
 * \return      Returns the value of the token.
 * \pre         Multi partition use case.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */
FUNC(vMemAccM_NVRAMAccessTokenType, VMEMACCM_CODE) vMemAccM_CfgAbMpGetToken(void);

/**********************************************************************************************************************
 *  vMemAccM_CfgAbMpGetCurrentActivePartitionFromToken
 *********************************************************************************************************************/
/*!
 * \brief       Gets the current active partition, which is stored in the token.
 * \details     -
 * \return      Returns the value of the current active partition.
 * \param[in]   Token holding the current information of the multipartition use case.
 * \pre         Multi partition use case.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */
FUNC(vMemAccM_MultiPartitionPartitionIdType, VMEMACCM_CODE) vMemAccM_CfgAbMpGetCurrentActivePartitionFromToken
(
    vMemAccM_NVRAMAccessTokenType Token
);
#  endif /* (VMEMACCM_MULTI_PARTITION_SINGLE_ACCESSOR_MASTER == STD_ON) */
# endif /* (VMEMACCM_MULTI_PARTITION_SATELLITE == STD_ON) */


/**********************************************************************************************************************
 *  vMemAccM_CfgAbJobEndNotification
 *********************************************************************************************************************/
/*!
 * \brief       Notifies the user that a job has been completed if it was configured for the given address area.
 * \details     -
 * \param[in]   AddressAreaId as the id of the address area. 
                              Must be valid and less than vMemAccM_GetSizeOfAddressAreaOfPCConfig.
 * \param[in]   Result as the job result of the address area.
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */
FUNC(void, VMEMACCM_CODE) vMemAccM_CfgAbJobEndNotification(
    vMemAccM_AddressAreaIdType AddressAreaId, 
    vMemAccM_JobResultType Result
);

/**********************************************************************************************************************
 *  vMemAccM_CfgAbGetMaxNrOfJobSetupsInMainFunction
 *********************************************************************************************************************/
/*!
 * \brief       Gets the number of allowed job setups within a single MainFunction call of the vMemAccM.
 * \details     -
 * \return      The number of job setups allowed.
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */
FUNC(uint8, VMEMACCM_CODE) vMemAccM_CfgAbGetMaxNrOfJobSetupsInMainFunction(void);

/**********************************************************************************************************************
 *  vMemAccM_CfgAbGetSubAddrAreaIdViaJobType
 *********************************************************************************************************************/
/*!
 * \brief       Returns the sub address area ID of the "Address" parameter.
 * \details     Take care: the "Address" value depends on passed "JobType": we need to differ between VMEMJOB and
 *              any other job!
 *              VMEMJOB: Address == HwId
 *              any other: Address == virtual address.
 * \param[in]   JobType as the requested job type. It must not be NO_JOB! This function only differs between VMEM_JOB 
 *                      and other requested jobs!
 * \param[in]   AddressAreaId as array index, used to access the virtual information.
 * \param[in]   Address holds the virtual address or the HwId of the request. Both must be in valid range.
 * \param[in]   Offset to be used to find the related sub address area identifier. Only used if JobType != VMEMJOB.
 * \return      Sub address area ID (out of range/ end index, if the Address could not be assigned).
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */
FUNC(vMemAccM_AddressAreaIdType, VMEMACCM_CODE) vMemAccM_CfgAbGetSubAddrAreaIdViaJobType
(
  vMemAccM_JobType JobType,
  vMemAccM_AddressAreaIdType AddressAreaId,
  vMemAccM_AddressType Address,
  vMemAccM_LengthType Offset
);

#endif /* (VMEMACCM_MINIMAL_SYNC == STD_OFF) */

# define VMEMACCM_STOP_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#endif /* VMEMACCM_CFGAB_H */

/**********************************************************************************************************************
 *  END OF FILE: vMemAccM_CfgAb.h
 *********************************************************************************************************************/
