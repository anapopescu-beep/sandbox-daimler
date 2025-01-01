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
/*!        \file  vHsmUpd_Ext_MemAb.c
 *        \brief  vHsmUpd Vector Extension memory related source file
 *
 *      \details  Defines the Memory related functions in the vHsmUpd_Ext
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 *********************************************************************************************************************/

#define VHSMUPD_EXT_MEMAB_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "vHsmUpd_Ext_Private.h"
#include "vHsmUpd.h"

/**********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 *********************************************************************************************************************/

#define VHSMUPD_EXT_FILLDATAVALUE                                         ((uint8)0xAAu)
#define VHSMUPD_EXT_MODULAR_UPDATE_PATTERN_LENGTH                         (4u)
#define VHSMUPD_EXT_AKTIVEPARTITION_PATTERN                               (0x00u)
#define VHSMUPD_EXT_INAKTIVEPARTITION_PATTERN                             (0x01u)

/**********************************************************************************************************************
 *  LOCAL FUNCTION MACROS
 *********************************************************************************************************************/
/* The vHsmUpd supports two partitions (Id 0 and 1). The inverse can be calculated by XOR 1 to the value 1 or 0 */
#define VHSMUPD_EXT_INVERSE_PARTITION_ID(value)                           ((value) ^ 1u)

/**********************************************************************************************************************
 *  LOCAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
#if !defined (VHSMUPD_EXT_LOCAL) /* COV_VHSMUPD_EXT_COMPATIBILITY */
# define VHSMUPD_EXT_LOCAL static
#endif

#if !defined (VHSMUPD_EXT_LOCAL_INLINE) /* COV_VHSMUPD_EXT_COMPATIBILITY */
# define VHSMUPD_EXT_LOCAL_INLINE LOCAL_INLINE
#endif

typedef P2FUNC(void, VHSMUPD_EXT_CODE, vHsmUpd_Ext_FunctionPtrType)( void );

/**********************************************************************************************************************
 *  LOCAL DATA PROTOTYPES
 *********************************************************************************************************************/
#define VHSMUPD_EXT_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

CONST(uint8, VHSMUPD_EXT_CONST) vHsmUp_HeaderTag[VHSMUPD_EXT_HEADER_TAG_SIZE] = { /*!< Header tag, which indicates an valid vHsm update header */ /* PRQA S 3408, 1514 */ /* MD_vHsmUpd_Ext_ConstConfigData */
    0x56u, 0x45u, 0x43u, 0x5Fu, 0x45u, 0x50u, 0x50u, 0x5Fu, 0x48u, 0x53u, 0x4Du, 0x00u, 0x00u, 0x00u, 0x00u, 0x01u};

#define VHSMUPD_EXT_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define VHSMUPD_START_SEC_CONST_8BIT
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
/* PRQA S 1514, 3218 1 */ /* MD_vHsmUpd_Ext_ConstConfigData */
VHSMUPD_EXT_LOCAL CONST(uint8, VHSMUPD_EXT_CONST) vHsmUpd_Ext_ppValue[VHSMUPD_SIZE_OF_PP] = { /*!< Value of the presence pattern for the vHsm firmware and update header */
    0x73u, 0x6Au, 0x25u, 0x3Eu
};

/* PRQA S 1514, 3218 1 */ /* MD_vHsmUpd_Ext_ConstConfigData */
VHSMUPD_EXT_LOCAL CONST(uint8, VHSMUPD_EXT_CONST) vHsmUpd_Ext_ModularUpdatePattern[VHSMUPD_EXT_MODULAR_UPDATE_PATTERN_LENGTH] = { /*!< Value of the presence pattern for the vHsm firmware and update header */
    0x4Du, 0x4Fu, 0x44u, 0x55u
};

#define VHSMUPD_STOP_SEC_CONST_8BIT
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define VHSMUPD_EXT_START_SEC_VAR_NOINIT_RAM_BUFFER_TMP
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

VHSMUPD_EXT_LOCAL VAR(uint8, VHSMUPD_EXT_VAR_NOINIT) vHsmUpd_Ext_tmpWriteBuffer[VHSMUPD_EXT_PLATFORM_PAGESIZE]; /*!< Write buffer, which is used for temporary data of the HSM Updater */

#define VHSMUPD_EXT_STOP_SEC_VAR_NOINIT_RAM_BUFFER_TMP
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/
#define VHSMUPD_EXT_START_SEC_CONST_32BIT
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

CONST(vHsmUpd_Ext_LengthType, AUTOMATIC) vHsmUpd_Ext_HeaderLengthInPages /* PRQA S 1514 */ /* MD_vHsmUpd_Ext_ConstConfigData */
  = ((VHSMUPD_EXT_UPDATEHEADER_COMPLETEHEADER_SIZE + VHSMUPD_EXT_PLATFORM_PAGESIZE - 1u) / VHSMUPD_EXT_PLATFORM_PAGESIZE);

#define VHSMUPD_EXT_STOP_SEC_CONST_32BIT
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define VHSMUPD_EXT_START_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

VAR(vHsmUpd_Ext_UpdateHeaderType, VHSMUPD_EXT_VAR_NOINIT) vHsmUpd_Ext_CurrentUpdHdr; /*!< Structure used for storing the update header */
VHSMUPD_EXT_LOCAL VAR(vHsmUpd_Ext_UpdateImageType, VHSMUPD_EXT_VAR_NOINIT) vHsmUpd_Ext_CurrentUpdImg;  /*!< Structure used for storing the update image information */

/* Structure to hold the maximum number of module headers */
VAR(vHsmUpd_Ext_ModuleUpdateHeaderType, VHSMUPD_EXT_VAR_NOINIT) vHsmUpd_Ext_ModularUpdateHeader[vHsmUpd_Ext_GetSizeOfRegion() * vHsmUpd_Ext_GetSizeOfPartitions()];

#define VHSMUPD_EXT_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
#define VHSMUPD_EXT_START_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  vHsmUpd_Ext_SetTargetRegionIndex()
 *********************************************************************************************************************/
/*!
 * \brief       Searches for the region where the update image should be written.
 * \details     -
 * \return      E_OK if a region is found.
 * \param[in]   regionHeader    The header for which the region should be found.
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */
VHSMUPD_EXT_LOCAL_INLINE FUNC(Std_ReturnType, VHSMUPD_EXT_CODE) vHsmUpd_Ext_SetTargetRegionIndex(vHsmUpd_Ext_ModuleUpdateHeaderPtrType regionHeader);

/**********************************************************************************************************************
 *  vHsmUpd_Ext_SetTargetPartitionIndex()
 *********************************************************************************************************************/
/*!
 * \brief       Searches for the partition where the update image should be written.
 * \details     -
 * \return      E_OK if a partition is found.
 * \param[in]   regionHeader    The header for which the partition should be found.
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */
VHSMUPD_EXT_LOCAL_INLINE FUNC(Std_ReturnType, VHSMUPD_EXT_CODE) vHsmUpd_Ext_SetTargetPartitionIndex(vHsmUpd_Ext_ModuleUpdateHeaderPtrType regionHeader);

/**********************************************************************************************************************
 *  vHsmUpd_Ext_IsNotVHsmUpdModuleType()
 *********************************************************************************************************************/
/*!
 * \brief       Checks if the module which will become updated is related to the vHsmUpd.
 * \details     Called of a update region relates to a active partition.
 * \return      E_OK if the update module is not related to vHsmUpd.
 * \param[in]   regionHeader    The header for which defines the target module.
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */
VHSMUPD_EXT_LOCAL_INLINE FUNC(Std_ReturnType, VHSMUPD_EXT_CODE) vHsmUpd_Ext_IsNotVHsmUpdModuleType(vHsmUpd_Ext_ModuleUpdateHeaderConstPtrType regionHeader);

/**********************************************************************************************************************
 *  vHsmUpd_Ext_IsVHsmFwModuleType()
 *********************************************************************************************************************/
/*!
 * \brief       Checks if the module which will become updated is related to the vHsmFw.
 * \details     Called of a update region relates to a active partition.
 * \return      E_OK if the update module is not related to the vHsmFw Module.
 * \param[in]   regionHeader    The header for which defines the target module.
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */
VHSMUPD_EXT_LOCAL_INLINE FUNC(Std_ReturnType, VHSMUPD_EXT_CODE) vHsmUpd_Ext_IsVHsmFwModuleType(vHsmUpd_Ext_ModuleUpdateHeaderConstPtrType regionHeader);

#define VHSMUPD_EXT_STOP_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

#define VHSMUPD_EXT_START_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  vHsmUpd_Ext_SetTargetRegionIndex()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
VHSMUPD_EXT_LOCAL_INLINE FUNC(Std_ReturnType, VHSMUPD_EXT_CODE) vHsmUpd_Ext_SetTargetRegionIndex(vHsmUpd_Ext_ModuleUpdateHeaderPtrType regionHeader)
{
  Std_ReturnType retVal = E_NOT_OK;
  uint8 index;

  /* Iterate over all regions */
  for (index = 0; index < vHsmUpd_Ext_GetSizeOfRegion(); index++)
  {
    /* Check if the target address of the image matches a region */
    if((regionHeader->VirtualRegionAddress >= vHsmUpd_Ext_GetStartAddressOfRegion(index))
      && (regionHeader->VirtualRegionAddress < (vHsmUpd_Ext_GetStartAddressOfRegion(index) + vHsmUpd_Ext_GetLengthOfRegion(index))))
    {
      /* Set the index of the region in the global region header */
      regionHeader->TargetInformations.IndexOfTargetRegion = index;
      retVal = E_OK;

      /* Leave the loop */
      break;
    }
  }

  return retVal;
}

/**********************************************************************************************************************
 *  vHsmUpd_Ext_SetTargetPartitionIndex()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
VHSMUPD_EXT_LOCAL_INLINE FUNC(Std_ReturnType, VHSMUPD_EXT_CODE) vHsmUpd_Ext_SetTargetPartitionIndex(vHsmUpd_Ext_ModuleUpdateHeaderPtrType regionHeader)
{
  Std_ReturnType retVal;
  vHsmUpd_Ext_PartitionIdOfPartitionsType indexOfActivePartition;

  retVal = vHsmUpd_Ext_GetActivePartitionId(&indexOfActivePartition);

  if(retVal == E_OK)
  {
    /* Check if the pattern is known */
    if(regionHeader->UpdPartition == VHSMUPD_EXT_AKTIVEPARTITION_PATTERN)
    {
      /* Set the target index */
      regionHeader->TargetInformations.IndexOfTargetPartition = (vHsmUpd_Ext_IndexType)indexOfActivePartition;

      /* Check if the update tries to update a vHsmUpd in the active partition */
      retVal = vHsmUpd_Ext_IsNotVHsmUpdModuleType(regionHeader);
    }
    else if(regionHeader->UpdPartition == VHSMUPD_EXT_INAKTIVEPARTITION_PATTERN)
    {
      regionHeader->TargetInformations.IndexOfTargetPartition = (VHSMUPD_EXT_INVERSE_PARTITION_ID((vHsmUpd_Ext_IndexType)indexOfActivePartition));
      /* retVal is already set to E_OK */
    }
    else
    {
      /* Misra compliant */
    }
  }

  return retVal;
}

/**********************************************************************************************************************
 *  vHsmUpd_Ext_IsNotVHsmUpdModuleType()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
VHSMUPD_EXT_LOCAL_INLINE FUNC(Std_ReturnType, VHSMUPD_EXT_CODE) vHsmUpd_Ext_IsNotVHsmUpdModuleType(vHsmUpd_Ext_ModuleUpdateHeaderConstPtrType regionHeader)
{
  Std_ReturnType retVal = E_OK;
  if(vHsmUpd_Ext_GetModuleTypeRefOfModules(vHsmUpd_Ext_GetModuleRefOfRegion(regionHeader->TargetInformations.IndexOfTargetRegion))
      == vHsmUpd_ExtConf_vHsmUpd_ExtModuleType_vHsmUpd_ExtvHsmUpd)
  {
    retVal = E_NOT_OK;
  }

  return retVal;
}

/**********************************************************************************************************************
 *  vHsmUpd_Ext_IsVHsmFwModuleType()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
VHSMUPD_EXT_LOCAL_INLINE FUNC(Std_ReturnType, VHSMUPD_EXT_CODE) vHsmUpd_Ext_IsVHsmFwModuleType(vHsmUpd_Ext_ModuleUpdateHeaderConstPtrType regionHeader)
{
  Std_ReturnType retVal = E_NOT_OK;
  if(regionHeader->UpdPartition == VHSMUPD_EXT_AKTIVEPARTITION_PATTERN)
  {
    if(vHsmUpd_Ext_GetModuleTypeRefOfModules(vHsmUpd_Ext_GetModuleRefOfRegion(regionHeader->TargetInformations.IndexOfTargetRegion))
        == vHsmUpd_ExtConf_vHsmUpd_ExtModuleType_vHsmUpd_ExtvHsmFirmware)
    {
      /* The region relates to the vHsmFirmware module */
      retVal = E_OK;
    }
  }
  return retVal;
}

#define VHSMUPD_EXT_STOP_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/

#define VHSMUPD_EXT_START_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  vHsmUpd_Ext_ReadUpdateHeader()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(Std_ReturnType, VHSMUPD_EXT_CODE) vHsmUpd_Ext_ReadUpdateHeader(vHsmUpd_Ext_AddressType headerAddress)
{
  Std_ReturnType retVal;
  /* headerAddress shall be one of the configured header addresses. This address is the pp address of the header.
   * To get the correct update header content address calculate the length of the update header and check for padding.
   * Padding is needed when the flash page size is not aligned to update header length.
   * At this point the UpdateHeader is known to be valid, so no check necessary. */
  vHsmUpd_Ext_AddressType currentReadAddress;

  currentReadAddress = headerAddress - (vHsmUpd_Ext_HeaderLengthInPages * VHSMUPD_EXT_PLATFORM_PAGESIZE);

    /* #10 Read all parts of the update header */
  retVal = vHsmUpd_Read_Callout(VHSMUPD_EXT_ADDRESS_AREA_OF_HOST,
                      vHsmUpd_Ext_CurrentUpdHdr.HeaderTag,
                      VHSMUPD_EXT_HEADER_TAG_SIZE,
                      currentReadAddress,
                      TARGET_HOST);
  currentReadAddress += VHSMUPD_EXT_HEADER_TAG_SIZE;

  retVal |= vHsmUpd_Read_Callout(VHSMUPD_EXT_ADDRESS_AREA_OF_HOST,
                      vHsmUpd_Ext_CurrentUpdHdr.VersionInfo,
                      VHSMUPD_EXT_UPDATEHEADER_VERSIONINFO_SIZE,
                      currentReadAddress,
                      TARGET_HOST);
  currentReadAddress += VHSMUPD_EXT_UPDATEHEADER_VERSIONINFO_SIZE;

  retVal |= vHsmUpd_Read_Callout(VHSMUPD_EXT_ADDRESS_AREA_OF_HOST,
                      vHsmUpd_Ext_CurrentUpdHdr.UpdateFWImageAddress,
                      VHSMUPD_EXT_UPDATEHEADER_IMAGEADDRESS_SIZE,
                      currentReadAddress,
                      TARGET_HOST);
  currentReadAddress += VHSMUPD_EXT_UPDATEHEADER_IMAGEADDRESS_SIZE;

  retVal |= vHsmUpd_Read_Callout(VHSMUPD_EXT_ADDRESS_AREA_OF_HOST,
                      vHsmUpd_Ext_CurrentUpdHdr.UpdateFWImageLength,
                      VHSMUPD_EXT_UPDATEHEADER_IMAGELENGTH_SIZE,
                      currentReadAddress,
                      TARGET_HOST);
  currentReadAddress += VHSMUPD_EXT_UPDATEHEADER_IMAGELENGTH_SIZE;

  retVal |= vHsmUpd_Read_Callout(VHSMUPD_EXT_ADDRESS_AREA_OF_HOST,
                      vHsmUpd_Ext_CurrentUpdHdr.Signature,
                      VHSMUPD_EXT_SIGNATURE_SIZE,
                      currentReadAddress,
                      TARGET_HOST);
  return retVal;
}

/**********************************************************************************************************************
 *  vHsmUpd_Ext_EraseRegion()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(Std_ReturnType, VHSMUPD_EXT_CODE) vHsmUpd_Ext_EraseRegion(vHsmUpd_Ext_ModuleUpdateHeaderConstPtrType regionHeader)
{
  Std_ReturnType retVal;
  /* Erase the complete region */
  retVal = vHsmUpd_EraseData((vHsmUpd_Ext_AreaIdType)vHsmUpd_Ext_GetAddressAreaRefOfPartitions(regionHeader->TargetInformations.IndexOfTargetPartition),
                            (vHsmUpd_Ext_LengthType)(vHsmUpd_Ext_GetLengthOfRegion(regionHeader->TargetInformations.IndexOfTargetRegion)),
                            (vHsmUpd_Ext_AddressType)(vHsmUpd_Ext_GetStartAddressOfRegion(regionHeader->TargetInformations.IndexOfTargetRegion))
                            );
  return retVal;
}

/**********************************************************************************************************************
 *  vHsmUpd_Ext_CheckUpdateHeader()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(Std_ReturnType, VHSMUPD_EXT_CODE) vHsmUpd_Ext_CheckUpdateHeader(void)
{
 /* #10 Check whether the update tag fulfills condition for an update, i.e. UUID and version are valid */
  return (Std_ReturnType)( (vHsmUpd_CompareBuffers(vHsmUpd_Ext_CurrentUpdHdr.HeaderTag, vHsmUp_HeaderTag, sizeof(vHsmUp_HeaderTag)) == TRUE) ? E_OK : E_NOT_OK);
}

/**********************************************************************************************************************
 *  vHsmUpd_Ext_ParseUpdateImageInformation()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(void, VHSMUPD_EXT_CODE) vHsmUpd_Ext_ParseUpdateImageInformation(vHsmUpd_Ext_ConstDataPtrType dataIn)
{
  /* The values in dataIn are read from flash and must be stored here. The first 4 bytes are the Fw Offset */
  vHsmUpd_Ext_CurrentUpdImg.FwOffset = vHsmUpd_BigEndianByteArrayToUint32(&dataIn[0u]); /* PRQA S 0310, 3305 */ /* MD_vHsmUpd_Ext_DataType */
  vHsmUpd_Ext_CurrentUpdImg.CalculatedFwAddress = vHsmUpd_Ext_GetImageStartAddress() + vHsmUpd_Ext_CurrentUpdImg.FwOffset;

  /* The second 4 bytes are the CrC Offset */
  vHsmUpd_Ext_CurrentUpdImg.CrcOffset = vHsmUpd_BigEndianByteArrayToUint32(&dataIn[4u]); /* PRQA S 0310, 3305 */ /* MD_vHsmUpd_Ext_DataType */
  vHsmUpd_Ext_CurrentUpdImg.CalculatedCrcAddress = vHsmUpd_Ext_GetImageStartAddress() + vHsmUpd_Ext_CurrentUpdImg.CrcOffset;
}

/**********************************************************************************************************************
 *  vHsmUpd_Ext_GetAddressOfFwDataInUpdateImage()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(vHsmUpd_Ext_AddressType, VHSMUPD_EXT_CODE) vHsmUpd_Ext_GetAddressOfFwDataInUpdateImage(void)
{
  /* #10 Return the start address of the firmware within the update image */
  return vHsmUpd_Ext_CurrentUpdImg.CalculatedFwAddress;
}

/**********************************************************************************************************************
 *  vHsmUpd_Ext_GetAddressOfCrcInUpdateImage()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(vHsmUpd_Ext_AddressType, VHSMUPD_EXT_CODE) vHsmUpd_Ext_GetAddressOfCrcInUpdateImage(void)
{
  /* #10 Return the start address of the crc value within the update image */
  return vHsmUpd_Ext_CurrentUpdImg.CalculatedCrcAddress;
}

/**********************************************************************************************************************
 *  vHsmUpd_Ext_StartHsmFw()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(void, VHSMUPD_EXT_CODE) vHsmUpd_Ext_StartHsmFw(void)
{
  /* Clear Hsm state which indicates that vHsmUpd is running */
    vHsmUpd_Ext_ClearHsmState(vHsmUpd_Ext_HsmToHostUpdRunning);

    /* Jump to entry point of Hsm Fw */
    /* It must have the given function signature, i.e. no return value and no input parameters.
     * Otherwise a reset of the controller is necessary,
     * which could then jump directly to the Hsm Fw, e.g. by setting reset addresses. */
    ((vHsmUpd_Ext_FunctionPtrType)(vHsmUpd_Ext_GetFwStartOfGeneral()))();
}

/**********************************************************************************************************************
 *  vHsmUpd_Ext_GetRawVersionValueInUpdHdr()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, VHSMUPD_EXT_CODE) vHsmUpd_Ext_GetRawVersionValueInUpdHdr(
  vHsmUpd_Ext_PtrToConstDataPtrType valuePtr,
  vHsmUpd_Ext_LengthPtrType length)
{
  *valuePtr = vHsmUpd_Ext_CurrentUpdHdr.VersionInfo;
  *length = VHSMUPD_EXT_UPDATEHEADER_VERSIONINFO_SIZE;
}

/**********************************************************************************************************************
 *  vHsmUpd_Ext_GetSizeOfImage()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(vHsmUpd_Ext_LengthType, VHSMUPD_EXT_CODE) vHsmUpd_Ext_GetSizeOfImage(void)
{
  /* #10 Return the length of the update image */
  vHsmUpd_Ext_LengthType length = vHsmUpd_BigEndianByteArrayToUint32(vHsmUpd_Ext_CurrentUpdHdr.UpdateFWImageLength);
  
  return length;
}

/**********************************************************************************************************************
 *  vHsmUpd_Ext_GetRawAddressValueInUpdHdr()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, VHSMUPD_EXT_CODE) vHsmUpd_Ext_GetRawAddressValueInUpdHdr(
  vHsmUpd_Ext_PtrToConstDataPtrType valuePtr,
    vHsmUpd_Ext_LengthPtrType length)
{
  *valuePtr = vHsmUpd_Ext_CurrentUpdHdr.UpdateFWImageAddress;
  *length = VHSMUPD_EXT_UPDATEHEADER_IMAGEADDRESS_SIZE;
}

/**********************************************************************************************************************
 *  vHsmUpd_Ext_GetRawLengthValueInUpdHdr()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, VHSMUPD_EXT_CODE) vHsmUpd_Ext_GetRawLengthValueInUpdHdr(
  vHsmUpd_Ext_PtrToConstDataPtrType valuePtr,
    vHsmUpd_Ext_LengthPtrType length)
{
  *valuePtr = vHsmUpd_Ext_CurrentUpdHdr.UpdateFWImageLength;
  *length = VHSMUPD_EXT_UPDATEHEADER_IMAGELENGTH_SIZE;
}

/**********************************************************************************************************************
 *  vHsmUpd_Ext_GetUpdateSignature()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, VHSMUPD_EXT_CODE) vHsmUpd_Ext_GetUpdateSignature(
  vHsmUpd_Ext_DataPtrType cmac)
{
  uint32 idx;

  /* #10 Copy the read update image signature to the given buffer */
  for(idx = 0u; idx < VHSMUPD_EXT_SIGNATURE_SIZE; ++idx)
  {
    cmac[idx] = vHsmUpd_Ext_CurrentUpdHdr.Signature[idx];
  }
}

/**********************************************************************************************************************
 *  vHsmUpd_Ext_GetImageStartAddress()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(vHsmUpd_Ext_AddressType, VHSMUPD_EXT_CODE) vHsmUpd_Ext_GetImageStartAddress(void)
{
  /* #10 Return the start address of the update image */
  vHsmUpd_Ext_AddressType address = vHsmUpd_BigEndianByteArrayToUint32(vHsmUpd_Ext_CurrentUpdHdr.UpdateFWImageAddress);

  return address;
}

/**********************************************************************************************************************
 *  vHsmUpd_Ext_CheckForValidFirmware()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(Std_ReturnType, VHSMUPD_EXT_CODE) vHsmUpd_Ext_CheckForValidFirmware(void)
{
  Std_ReturnType retVal;
  vHsmUpd_Ext_RegionIterType regionIdx;
  vHsmUpd_Ext_AreaIdType activeAreaId;
  boolean hsmFwFound = FALSE;
  vHsmUpd_Ext_PartitionIdOfPartitionsType partitionId;

  retVal = vHsmUpd_Ext_GetActivePartitionId(&partitionId);
  if(retVal == E_OK)
  {
    activeAreaId = vHsmUpd_Ext_GetAddressAreaRefOfPartitions(partitionId);

    for(regionIdx = 0u; regionIdx < vHsmUpd_Ext_GetSizeOfRegion(); regionIdx++)
    {
      vHsmUpd_Ext_ModuleRefOfRegionType module = vHsmUpd_Ext_GetModuleRefOfRegion(regionIdx);
      if(vHsmUpd_Ext_GetModuleTypeRefOfModules(module) == vHsmUpd_ExtConf_vHsmUpd_ExtModuleType_vHsmUpd_ExtvHsmFirmware)
      {
        hsmFwFound = TRUE;
        if(vHsmUpd_ReadPresencePattern(activeAreaId, vHsmUpd_Ext_GetStartAddressOfRegion(regionIdx), TARGET_HSM) == E_NOT_OK)
        {
          retVal |= E_NOT_OK;
          break;
        }
      }
    }
  }

  if(hsmFwFound == TRUE)
  {
    if(retVal == E_OK)
    {
      vHsmUpd_Ext_ValidityInfo.validFirmwareAvailable = TRUE;
    }
  }
  else
  {
    retVal = E_NOT_OK;
  }

  return retVal;
}

/**********************************************************************************************************************
 *  vHsmUpd_Ext_CheckForModularUpdatePattern()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(Std_ReturnType, VHSMUPD_EXT_CODE) vHsmUpd_Ext_CheckForModularUpdatePattern(vHsmUpd_Ext_ConstDataPtrType data)
{
  Std_ReturnType retVal = E_NOT_OK;
  if(vHsmUpd_CompareBuffers(vHsmUpd_Ext_ModularUpdatePattern, data, VHSMUPD_EXT_MODULAR_UPDATE_PATTERN_LENGTH) == TRUE)
  {
    vHsmUpd_Ext_UpdState.NumberOfModulesToUpdate  = vHsmUpd_BigEndianByteArrayToUint32(&data[8u]);
    vHsmUpd_Ext_UpdState.CurrentUpdateModule      = 0u;
    retVal = E_OK;
  }
  return retVal;
}

/**********************************************************************************************************************
 *  vHsmUpd_Ext_ParseModularUpdateHeader()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(Std_ReturnType, VHSMUPD_EXT_CODE) vHsmUpd_Ext_ParseModularUpdateHeader(
  vHsmUpd_Ext_ConstDataPtrType updateHeaderBinary,
  uint8 index)
{
  Std_ReturnType retVal;

  /* Parse the complete module update header */
  vHsmUpd_Ext_ModularUpdateHeader[index].UpdPartition             = vHsmUpd_BigEndianByteArrayToUint32(&updateHeaderBinary[0u]);
  vHsmUpd_Ext_ModularUpdateHeader[index].VirtualRegionAddress     = vHsmUpd_BigEndianByteArrayToUint32(&updateHeaderBinary[4u]);
  vHsmUpd_Ext_ModularUpdateHeader[index].ModuleUpdateImageOffset  = vHsmUpd_BigEndianByteArrayToUint32(&updateHeaderBinary[8u]);
  vHsmUpd_Ext_ModularUpdateHeader[index].ModuleUpdateImageLength  = vHsmUpd_BigEndianByteArrayToUint32(&updateHeaderBinary[12u]);
  vHsmUpd_Ext_ModularUpdateHeader[index].ModuleCrcValue           = vHsmUpd_BigEndianByteArrayToUint32(&updateHeaderBinary[16u]);

  retVal = vHsmUpd_Ext_SetTargetRegionIndex(&vHsmUpd_Ext_ModularUpdateHeader[index]);
  retVal |= vHsmUpd_Ext_SetTargetPartitionIndex(&vHsmUpd_Ext_ModularUpdateHeader[index]);

  return retVal;
}

/**********************************************************************************************************************
 *  vHsmUpd_Ext_ParseStandardHeaderToModule()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, VHSMUPD_EXT_CODE) vHsmUpd_Ext_ParseStandardHeaderToModule(void)
{
  vHsmUpd_Ext_UpdState.NumberOfModulesToUpdate = 1u;
  vHsmUpd_Ext_UpdState.CurrentUpdateModule     = 0u;

  /* In the standard update just one region (index = 0) is available. */
  vHsmUpd_Ext_ModularUpdateHeader[0u].UpdPartition            = VHSMUPD_EXT_AKTIVEPARTITION_PATTERN;
  vHsmUpd_Ext_ModularUpdateHeader[0u].VirtualRegionAddress    = vHsmUpd_Ext_GetStartAddressOfRegion(0u) + (3u * VHSMUPD_EXT_PLATFORM_PAGESIZE);
  vHsmUpd_Ext_ModularUpdateHeader[0u].ModuleUpdateImageOffset = 0u;
  vHsmUpd_Ext_ModularUpdateHeader[0u].ModuleUpdateImageLength = vHsmUpd_Ext_GetAddressOfCrcInUpdateImage() - vHsmUpd_Ext_GetAddressOfFwDataInUpdateImage();
  vHsmUpd_Ext_ModularUpdateHeader[0u].ModuleCrcValue          = 0u;
  vHsmUpd_Ext_ModularUpdateHeader[0u].TargetInformations.IndexOfTargetRegion    = 0u;
  vHsmUpd_Ext_ModularUpdateHeader[0u].TargetInformations.IndexOfTargetPartition = 0u;
}

/**********************************************************************************************************************
 *  vHsmUpd_Ext_SizeOfRegionUpdate()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(Std_ReturnType, VHSMUPD_EXT_CODE) vHsmUpd_Ext_SizeOfRegionUpdate(void)
{
  Std_ReturnType retVal = E_OK;
  uint8 index;
  vHsmUpd_Ext_AddressType startAddressRegion;
  vHsmUpd_Ext_LengthType  lengthRegion;

  for(index = 0; index < vHsmUpd_Ext_UpdState.NumberOfModulesToUpdate; index++)
  {
    /* Check if the update image fits into the region codeflash */
    startAddressRegion = vHsmUpd_Ext_GetStartAddressOfRegion(vHsmUpd_Ext_ModularUpdateHeader[index].TargetInformations.IndexOfTargetRegion);
    lengthRegion = vHsmUpd_Ext_GetLengthOfRegion(vHsmUpd_Ext_ModularUpdateHeader[index].TargetInformations.IndexOfTargetRegion);

    /* The image region start address has already been checked and lays inside of the region */
    if(((vHsmUpd_Ext_ModularUpdateHeader[index].VirtualRegionAddress - startAddressRegion) >= (3u * VHSMUPD_EXT_PLATFORM_PAGESIZE)) /* Enough space for presence pattern */
      && ((vHsmUpd_Ext_ModularUpdateHeader[index].VirtualRegionAddress + vHsmUpd_Ext_ModularUpdateHeader[index].ModuleUpdateImageLength)
          < (startAddressRegion + lengthRegion)))
    {
      /* Nothing to do if the image is not too big */
    }
    else
    {
      retVal = E_NOT_OK;
      /* Not necessary to process the other header parts */
      break;
    }
  }

  return retVal;
}

/**********************************************************************************************************************
 *  vHsmUpd_Ext_InvalidatePresencePatternOfModule()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
FUNC(Std_ReturnType, VHSMUPD_EXT_CODE) vHsmUpd_Ext_InvalidatePresencePatternOfModule(vHsmUpd_Ext_ModuleUpdateHeaderConstPtrType regionHeader)
{
  Std_ReturnType retVal = E_NOT_OK;
  vHsmUpd_Ext_AddressType ppAddressForInvalidation;
  uint8 patternIdx;
  boolean isBlank;

  ppAddressForInvalidation = vHsmUpd_Ext_GetStartAddressOfRegion(regionHeader->TargetInformations.IndexOfTargetRegion) + VHSMUPD_EXT_PLATFORM_PAGESIZE;

  /* Check if the invalidated presence pattern relates to a vHsmFirmware on the active partition */
  if(vHsmUpd_Ext_IsVHsmFwModuleType(regionHeader) == E_OK)
  {
    /* Set global state to invalid Firmware */
    vHsmUpd_Ext_ValidityInfo.validFirmwareAvailable = FALSE;
  }

  /* Check if the installed firmware is already invalidated, then just return with E_OK */
  if( vHsmUpd_IsBlank_Callout(vHsmUpd_Ext_GetAddressAreaRefOfPartitions(regionHeader->TargetInformations.IndexOfTargetPartition),
                      VHSMUPD_EXT_PLATFORM_PAGESIZE,
                      ppAddressForInvalidation,
                      &isBlank,
                      TARGET_HSM) == E_OK )
  {
    if(isBlank == TRUE)
    {
      /* Fill temp buffer with inverse of presence pattern */
      for(patternIdx = 0u; patternIdx < VHSMUPD_EXT_SIZE_OF_PP; ++patternIdx)
      {
        vHsmUpd_Ext_tmpWriteBuffer[patternIdx] = (uint8)(~(vHsmUpd_Ext_ppValue[patternIdx]));
      }

      /* Try to write the pattern to flash. An unsuccessful operation does not matter here because than the state of the flash is unknown and the vHsmUpd
      * has to go on with normal operation. */
      (void)vHsmUpd_WriteData(vHsmUpd_Ext_GetAddressAreaRefOfPartitions(regionHeader->TargetInformations.IndexOfTargetPartition),
                            vHsmUpd_Ext_tmpWriteBuffer,
                            sizeof(vHsmUpd_Ext_tmpWriteBuffer),
                            ppAddressForInvalidation);

      /* Verify that the given address at least is no longer blank, otherwise fail. */
      if( vHsmUpd_IsBlank_Callout(vHsmUpd_Ext_GetAddressAreaRefOfPartitions(regionHeader->TargetInformations.IndexOfTargetPartition),
                        VHSMUPD_EXT_PLATFORM_PAGESIZE,
                        ppAddressForInvalidation,
                        &isBlank,
                        TARGET_HSM) == E_OK )
      {
        if(isBlank == FALSE)
        {
          retVal = E_OK;
        }
      }

      /* Reject case: The blank check will not be performed and leave result to E_NOT_OK */
    }
    else
    {
      retVal = E_OK;
    }
  }
  return retVal;
}

/**********************************************************************************************************************
 *  vHsmUpd_Ext_ValidatePresencePatternOfRegion()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(Std_ReturnType, VHSMUPD_EXT_CODE) vHsmUpd_Ext_ValidatePresencePatternOfRegion(vHsmUpd_Ext_ModuleUpdateHeaderConstPtrType regionHeader)
{
  Std_ReturnType retVal = E_NOT_OK;
  uint16 index;
  boolean isBlank;

  /* Check that the presence pattern location is blank */
  if(vHsmUpd_IsBlank_Callout(vHsmUpd_Ext_GetAddressAreaRefOfPartitions(regionHeader->TargetInformations.IndexOfTargetPartition),
                            VHSMUPD_EXT_PLATFORM_PAGESIZE,
                            vHsmUpd_Ext_GetStartAddressOfRegion(regionHeader->TargetInformations.IndexOfTargetRegion),
                            &isBlank,
                            TARGET_HSM) == E_OK)
  {
    if(isBlank == TRUE)
    {
      /* Setup the write buffer for the first page of the presence pattern */
      for(index = 0; index < VHSMUPD_EXT_SIZE_OF_PP; index++)
      {
        vHsmUpd_Ext_tmpWriteBuffer[index] = vHsmUpd_Ext_ppValue[index];
      }
      for(;index < VHSMUPD_EXT_PLATFORM_PAGESIZE; index++)
      {
        vHsmUpd_Ext_tmpWriteBuffer[index] = 0x00;
      }

      /* Write the pp value at the start address of the partition */
      if(vHsmUpd_WriteData(vHsmUpd_Ext_GetAddressAreaRefOfPartitions(regionHeader->TargetInformations.IndexOfTargetPartition),
                                vHsmUpd_Ext_tmpWriteBuffer,
                                VHSMUPD_EXT_PLATFORM_PAGESIZE,
                                vHsmUpd_Ext_GetStartAddressOfRegion(regionHeader->TargetInformations.IndexOfTargetRegion)) == E_NOT_OK)
      {
        /* Nothing to do on error */
      }
      /* Check if the presence pattern is valid */
      else if(vHsmUpd_ReadPresencePattern(vHsmUpd_Ext_GetAddressAreaRefOfPartitions(regionHeader->TargetInformations.IndexOfTargetPartition),
                                vHsmUpd_Ext_GetStartAddressOfRegion(regionHeader->TargetInformations.IndexOfTargetRegion),
                                TARGET_HSM) == E_OK)
      {
        /* All steps successfull processed */
        retVal = E_OK;
      }
      else
      {
        /* Misra compliant */
      }
    }
  }

  return retVal;
}

/**********************************************************************************************************************
 *  vHsmUpd_Ext_GetActivePartitionId()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(Std_ReturnType, VHSMUPD_EXT_CODE) vHsmUpd_Ext_GetActivePartitionId(vHsmUpd_Ext_PartitionIndexPtrType id)
{
  Std_ReturnType retVal;
  boolean isSwapped;
  vHsmUpd_Ext_PartitionIdOfPartitionsType activePartition;
  uint8 partitionTypeIdOfMainActivePartition = vHsmUpd_Ext_GetPartitonTypeIdOfPartitionType(vHsmUpd_ExtConf_vHsmUpd_ExtPartitionType_vHsmUpd_ExtMainActive);

  /* Get partition index of main active partition */
  if(vHsmUpd_Ext_GetPartitionTypeRefIdxOfPartitions(0u) == partitionTypeIdOfMainActivePartition)
  {
    activePartition = 0u;
  }
  else
  {
    activePartition = 1u;
  }

  /* Check if the partitions are swapped currently */
  retVal = vHsmUpd_IsSwapped_Callout(&isSwapped);

  if(retVal == E_OK)
  {
    if(isSwapped == TRUE)
    {
      activePartition = (vHsmUpd_Ext_PartitionIdOfPartitionsType)VHSMUPD_EXT_INVERSE_PARTITION_ID(activePartition);
    }

    *id = activePartition;
  }

  return retVal;
}

/**********************************************************************************************************************
 *  vHsmUpd_Ext_CheckPagesizeAlignmentAndPad()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(vHsmUpd_Ext_LengthType, VHSMUPD_EXT_CODE) vHsmUpd_Ext_CheckPagesizeAlignmentAndPad(
  vHsmUpd_Ext_DataPtrType processingDataBuffer,
  vHsmUpd_Ext_LengthType  dataLength,
  vHsmUpd_Ext_LengthType  paddedLength)
{
  vHsmUpd_Ext_LengthType retVal;
  uint32 counter;

  /* Check the alignment of the platform pagesize */
  if((paddedLength % VHSMUPD_EXT_PLATFORM_PAGESIZE) == 0u)
  {
    retVal = paddedLength;
  }
  else
  {
    retVal = ((paddedLength / VHSMUPD_EXT_PLATFORM_PAGESIZE) + 1u) * VHSMUPD_EXT_PLATFORM_PAGESIZE;
  }

  /* Fill the buffer with fillbyte value */
  for(counter = dataLength; counter < retVal; counter++)
  {
    processingDataBuffer[counter] = VHSMUPD_EXT_FILLDATAVALUE; /*lint !e661 */
  }
  return retVal;
}

#define VHSMUPD_EXT_STOP_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  END OF FILE: vHsmUpd_Ext_MemAb.c
 *********************************************************************************************************************/
