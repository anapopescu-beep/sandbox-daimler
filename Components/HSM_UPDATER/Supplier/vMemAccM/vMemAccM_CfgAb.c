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
/*!        \file  vMemAccM_CfgAb.c
 *        \brief  vMemAccM configuration abstraction submodule source file.
 *      \details  See vMemAccM_CfgAb.h
 *********************************************************************************************************************/

#define VMEMACCM_CFGAB_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "vMemAccM_Types.h"
#include "vMemAccM_Sched.h"
#include "vMemAccM_CfgAb.h"

/**********************************************************************************************************************
 *  LOCAL FUNCTION MACROS
 *********************************************************************************************************************/
#if !defined (VMEMACCM_LOCAL) /* COV_VMEMACCM_COMPATIBILITY */
# define VMEMACCM_LOCAL static
#endif

#if !defined (VMEMACCM_LOCAL_INLINE) /* COV_VMEMACCM_COMPATIBILITY */
# define VMEMACCM_LOCAL_INLINE LOCAL_INLINE
#endif

/**********************************************************************************************************************
 *  LOCAL DATA PROTOTYPES
 *********************************************************************************************************************/
#define VMEMACCM_START_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! Holds the currently set memory mapping variant. */
VMEMACCM_LOCAL VAR(vMemAccM_VariantIdType, VMEMACCM_VAR_NOINIT) vMemAccM_CfgAbActiveVariantId;

#define VMEMACCM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
#define VMEMACCM_START_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  vMemAccM_CfgAbInit
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, VMEMACCM_CODE) vMemAccM_CfgAbInit(void)
{
  vMemAccM_CfgAbActiveVariantId = VMEMACCM_VARIANT_ID_STARTUP;
}

#if (VMEMACCM_DEV_ERROR_DETECT == STD_ON)
/**********************************************************************************************************************
 *  vMemAccM_CfgAbAddressAreaIdValid
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(boolean, VMEMACCM_CODE) vMemAccM_CfgAbAddressAreaIdValid(vMemAccM_AddressAreaIdType AddressAreaId)
{
  return (AddressAreaId < vMemAccM_GetSizeOfAddressAreaOfPCConfig());
}

# if (VMEMACCM_MULTI_PARTITION_SATELLITE == STD_ON)
/**********************************************************************************************************************
 *  vMemAccM_CfgAbMpGetSatelliteDataPtr
 *********************************************************************************************************************/
 /*!
 * Internal comment removed.
 *
 *
 */
FUNC(vMemAccM_PublishRequestDataPtrType, VMEMACCM_CODE) vMemAccM_CfgAbMpGetSatelliteDataPtr(void)
{
    return vMemAccM_SatellitePartitionDataPtr;
}
# endif

# if (VMEMACCM_MULTI_PARTITION_SATELLITE == STD_OFF)
/**********************************************************************************************************************
 *  vMemAccM_CfgAbHwFuncIndexValid
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(boolean, VMEMACCM_CODE) vMemAccM_CfgAbHwFuncIndexValid
(
  vMemAccM_AddressAreaIdType AddressAreaId,
  vMemAccM_HwIdType HwId,
  vMemAccM_vMemHwSpecificFuncIndexType vMemHwSpecificFuncIndex
)
{
  return (vMemHwSpecificFuncIndex <
           vMemAccM_GetvMemApiTableOfSubAddressArea(vMemAccM_CfgAbGetSubAddrAreaIdViaHwId(AddressAreaId, HwId))->HwFunctions.FunctionCount);
}

/**********************************************************************************************************************
 *  vMemAccM_CfgAbHwIdValid
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(boolean, VMEMACCM_CODE) vMemAccM_CfgAbHwIdValid
(
  vMemAccM_AddressAreaIdType AddressAreaId,
  vMemAccM_HwIdType HwId
)
{
  /* HwId has to point to one of the sub address areas belonging to passed AddressAreaId, otherwise it is invalid. */
  return vMemAccM_CfgAbSubAddressAreaIdValid(AddressAreaId, vMemAccM_CfgAbGetSubAddrAreaIdViaHwId(AddressAreaId, HwId));
}

# endif /* (VMEMACCM_MULTI_PARTITION_SATELLITE == STD_OFF) */
#endif /* (VMEMACCM_DEV_ERROR_DETECT == STD_ON) */

/**********************************************************************************************************************
 *  vMemAccM_CfgAbSubAddressAreaIdValid
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(boolean, VMEMACCM_CODE) vMemAccM_CfgAbSubAddressAreaIdValid
(
  vMemAccM_AddressAreaIdType AddressAreaId,
  vMemAccM_AddressAreaIdType SubAddressAreaId
)
{
  return (SubAddressAreaId <
    vMemAccM_GetSubAddressAreaEndIdxOfAddressAreaVariant(vMemAccM_CfgAbGetAddressAreaVariantId(AddressAreaId)));
}

/**********************************************************************************************************************
 *  vMemAccM_CfgAbAddressAndLengthValid
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
FUNC(boolean, VMEMACCM_CODE) vMemAccM_CfgAbAddressAndLengthValid
(
  vMemAccM_AddressAreaIdType AddressAreaId,
  vMemAccM_AddressType Address,
  vMemAccM_LengthType Length
)
{
  boolean retVal = FALSE;
  boolean breakLoop = FALSE;
  vMemAccM_LengthType remainingLength = Length;
  vMemAccM_AddressType address = Address;
  /* #100 Go through the passed address space and check. */
  /* No indexes to loop over, execute checks and decide whether to continue or not -> do-while loop. */
  do
  {
    /* #110 Check whether the current address belongs to any sub address area. */
    vMemAccM_AddressAreaIdType subAddrAreaId = vMemAccM_CfgAbGetSubAddrAreaId(AddressAreaId, address);
    if(vMemAccM_CfgAbSubAddressAreaIdValid(AddressAreaId, subAddrAreaId) == TRUE)
    {
      /* Number of bytes within current sub address area from Address to the end. */
      vMemAccM_LengthType remainingSAALength = ((vMemAccM_LengthType)(vMemAccM_GetVirtualEndAddressOfSubAddressArea(subAddrAreaId) - address + 1u));

      /* #111 Address is valid, the requested address space belongs to one single sub address area (is max the remaining
       * size within the SAA) -> abort and return successfully. */
      if(remainingLength <= remainingSAALength)
      {
        retVal = TRUE;
        breakLoop = TRUE;
      }
      /* #112 Requested length > current sub address area, we need to check the following sub address area
       * (if there is any) -> adjust address and length. */
      else
      {
        /* Subtract the already checked number of bytes from requested length. */
        remainingLength -= remainingSAALength;
        /* Calculate the next address - shall always point to the first byte after the current sub address area. */
        address = ((vMemAccM_AddressType)(vMemAccM_GetVirtualEndAddressOfSubAddressArea(subAddrAreaId) + 1u));
      }
    }
    /* #120 Address invalid, abort and return unsuccessfully. */
    else
    {
      breakLoop = TRUE;
    }
  } while (breakLoop == FALSE);

  return retVal;
}

/**********************************************************************************************************************
 *  vMemAccM_CfgAbGetSubAddrAreaId
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(vMemAccM_AddressAreaIdType, VMEMACCM_CODE) vMemAccM_CfgAbGetSubAddrAreaId
(
  vMemAccM_AddressAreaIdType AddressAreaId,
  vMemAccM_AddressType Address
)
{
  /* #10 Initialize the sub address area index with an out of range value. */
  vMemAccM_VariantIdType variantId = vMemAccM_CfgAbGetAddressAreaVariantId(AddressAreaId);
  vMemAccM_AddressAreaIdType subAddrAreaId = vMemAccM_GetSubAddressAreaEndIdxOfAddressAreaVariant(variantId);
  vMemAccM_IndexType i = vMemAccM_GetSubAddressAreaStartIdxOfAddressAreaVariant(variantId);
  /* #20 Search for the address area belonging to the address. */
  for(; i < vMemAccM_GetSubAddressAreaEndIdxOfAddressAreaVariant(variantId); i++)
  {
    /* Subtract the 1 to point to the last valid address within the sub address area,
     * because of the uint32 maximum: address + length = the first byte after the current sub address area.
     * If the sub address area is located at the end of the uint32 address space, this leads to
     * uint32 max + 1. */
    if((Address >= vMemAccM_GetVirtualStartAddressOfSubAddressArea(i)) &&
        (Address <= vMemAccM_GetVirtualEndAddressOfSubAddressArea(i)))
    {
      /* #21 Sub address area found, return its index. */
      subAddrAreaId = (vMemAccM_AddressAreaIdType)i;
      break;
    }
  }

  return subAddrAreaId;
}

/**********************************************************************************************************************
 *  vMemAccM_CfgAbGetSubAddrAreaIdViaHwId
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(vMemAccM_AddressAreaIdType, VMEMACCM_CODE) vMemAccM_CfgAbGetSubAddrAreaIdViaHwId
(
  vMemAccM_AddressAreaIdType AddressAreaId,
  vMemAccM_HwIdType HwId
)
{
  /* #10 Initialize the sub address area index with an out of range value. */
  vMemAccM_VariantIdType variantId = vMemAccM_CfgAbGetAddressAreaVariantId(AddressAreaId);
  vMemAccM_AddressAreaIdType subAddrAreaId = vMemAccM_GetSubAddressAreaEndIdxOfAddressAreaVariant(variantId);
  vMemAccM_IndexType i = vMemAccM_GetSubAddressAreaStartIdxOfAddressAreaVariant(variantId);
  /* #20 Search for the sub address area belonging to the HwId. */
  for(; i < vMemAccM_GetSubAddressAreaEndIdxOfAddressAreaVariant(variantId); i++)
  {
    if(HwId == vMemAccM_GetHardwareIdOfSubAddressArea(i))
    {
      /* #21 HwId fits to the HwId of the sub address area - return current sub address area index. */
      subAddrAreaId = (vMemAccM_AddressAreaIdType)i;
      break;
    }
  }

  return subAddrAreaId;
}

/**********************************************************************************************************************
 *  vMemAccM_CfgAbGetAddressAreaVariantId
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(vMemAccM_VariantIdType, VMEMACCM_CODE) vMemAccM_CfgAbGetAddressAreaVariantId
(
  vMemAccM_AddressAreaIdType AddressAreaId
)
{
  /* All address areas without memory mapping variants use the startup variant;
     * for all address areas with memory mapping variants use the currently active variant. */
  vMemAccM_VariantIdType variantOffset = (vMemAccM_GetAddressAreaVariantLengthOfAddressArea(AddressAreaId) >
    VMEMACCM_VARIANT_LENGTHOFNOVARIANT) ? vMemAccM_CfgAbActiveVariantId : VMEMACCM_VARIANT_ID_STARTUP;
  return (vMemAccM_VariantIdType)(vMemAccM_GetAddressAreaVariantStartIdxOfAddressArea(AddressAreaId) + variantOffset);
}

/**********************************************************************************************************************
 *  vMemAccM_CfgAbSetActiveVariantId
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, VMEMACCM_CODE) vMemAccM_CfgAbSetActiveVariantId(vMemAccM_VariantIdType VariantId)
{
  vMemAccM_CfgAbActiveVariantId = VariantId;
}

#if ((VMEMACCM_PARTITION_USECASE == VMEMACCM_MULTI_PARTITION_MULTI_ACCESSORS) || \
     (VMEMACCM_PARTITION_USECASE == VMEMACCM_MULTI_PARTITION_SINGLE_ACCESSOR))
/**********************************************************************************************************************
 *  Multi partition shared functions
 *********************************************************************************************************************/
/**********************************************************************************************************************
 *  vMemAccM_CfgAbMpGetToken
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(vMemAccM_NVRAMAccessTokenType, VMEMACCM_CODE) vMemAccM_CfgAbMpGetToken(void)
{
  return *vMemAccM_NVRAMAccessTokenPtr;
}

/**********************************************************************************************************************
 *  vMemAccM_CfgAbMpGetLastActivePartitionFromToken
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(vMemAccM_MultiPartitionPartitionIdType, VMEMACCM_CODE) vMemAccM_CfgAbMpGetLastActivePartitionFromToken(
    vMemAccM_NVRAMAccessTokenType Token
)
{
  return ((vMemAccM_MultiPartitionPartitionIdType)((Token & 0xFF00u) >> 8u));
}

/**********************************************************************************************************************
 *  vMemAccM_CfgAbMpGetCurrentActivePartitionFromToken
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(vMemAccM_MultiPartitionPartitionIdType, VMEMACCM_CODE) vMemAccM_CfgAbMpGetCurrentActivePartitionFromToken(
    vMemAccM_NVRAMAccessTokenType Token
)
{
  return (vMemAccM_MultiPartitionPartitionIdType)(Token & 0xFFu);
}

/**********************************************************************************************************************
 *  vMemAccM_CfgAbSetPublishedPriority
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, VMEMACCM_CODE) vMemAccM_CfgAbSetPublishedPriority(
    vMemAccM_PublishPriorityType Priority
)
{
  vMemAccM_PartitionPublishRequestPtr->Priority = Priority; /* SBSW_vMemAccM_MultiPartitionTokenAndPublishReqPtr */
}

# if (VMEMACCM_MULTIPARTITION_PARTITION_ID == VMEMACCM_MULTIPARTITION_MASTER_PARTITION_ID)
/**********************************************************************************************************************
 *  vMemAccM_CfgAbGetMpTokenPriority
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(vMemAccM_PublishPriorityType, VMEMACCM_CODE) vMemAccM_CfgAbGetMpTokenPriority(vMemAccM_NVRAMAccessTokenType Token)
{
  return vMemAccM_MultiPartitionPublishedRequests[Token]->Priority;
}

/**********************************************************************************************************************
 *  vMemAccM_CfgAbMpSetToken
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, VMEMACCM_CODE) vMemAccM_CfgAbMpSetToken(
    vMemAccM_NVRAMAccessTokenType CurrentToken, 
    vMemAccM_NVRAMAccessTokenType PreviousToken
)
{
  *vMemAccM_NVRAMAccessTokenPtr = (vMemAccM_NVRAMAccessTokenType)((PreviousToken << 8u) | CurrentToken); /* SBSW_vMemAccM_MultiPartitionTokenAndPublishReqPtr */
}
# endif /* (VMEMACCM_MULTIPARTITION_PARTITION_ID == VMEMACCM_MULTIPARTITION_MASTER_PARTITION_ID) */

#endif /* ((VMEMACCM_PARTITION_USECASE == VMEMACCM_MULTI_PARTITION_MULTI_ACCESSORS) || \
           (VMEMACCM_PARTITION_USECASE == VMEMACCM_MULTI_PARTITION_SINGLE_ACCESSOR)) */

# define VMEMACCM_STOP_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */  /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  END OF FILE: vMemAccM_CfgAb.c
 *********************************************************************************************************************/
