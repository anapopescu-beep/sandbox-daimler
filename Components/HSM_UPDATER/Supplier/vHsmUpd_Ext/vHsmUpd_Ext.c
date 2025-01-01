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
/*!        \file  vHsmUpd_Ext.c
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

#define VHSMUPD_EXT_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "vHsmUpd_Ext.h"
#include "vHsmUpd_Ext_Private.h"
#include "vHsmUpd.h"

/**********************************************************************************************************************
 *  VERSION CHECK
 *********************************************************************************************************************/
/* Check the version of vHsmUpd header file */
#if (  (VHSMUPD_EXT_SW_MAJOR_VERSION != (4u)) \
    || (VHSMUPD_EXT_SW_MINOR_VERSION != (1u)) \
    || (VHSMUPD_EXT_SW_PATCH_VERSION != (0u)) )
# error "Vendor specific version numbers of vHsmUpd.c and vHsmUpd.h are inconsistent"
#endif

/**********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 *********************************************************************************************************************/
#define VHSMUPD_EXT_FILLDATAVALUE                                     ((uint8)0xAAu)

/**********************************************************************************************************************
 *  LOCAL FUNCTION MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
#if !defined (VHSMUPD_EXT_LOCAL) /* COV_VHSMUPD_EXT_COMPATIBILITY */
# define VHSMUPD_EXT_LOCAL                                            static
#endif

#if !defined (VHSMUPD_EXT_LOCAL_INLINE) /* COV_VHSMUPD_EXT_COMPATIBILITY */
# define VHSMUPD_EXT_LOCAL_INLINE                                     LOCAL_INLINE
#endif

#define VHSMUPD_EXT_START_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

VAR(vHsmUpd_Ext_ProcInfoType, VHSMUPD_EXT_VAR_NOINIT)     vHsmUpd_Ext_UpdState;       /* PRQA S 1514 */ /* MD_vHsmUpd_Ext_ConstConfigData */
VAR(vHsmUpd_Ext_StateInfoType, VHSMUPD_EXT_VAR_NOINIT)    vHsmUpd_Ext_ValidityInfo;

#define VHSMUPD_EXT_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define VHSMUPD_EXT_START_SEC_CONST_8BIT
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

VHSMUPD_EXT_LOCAL CONST(boolean, AUTOMATIC) vHsmUpd_Ext_AlwaysTrue = TRUE;        /* PRQA S 3218 */ /* MD_vHsmUpd_Ext_ConstConfigData */

#define VHSMUPD_EXT_STOP_SEC_CONST_8BIT
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  LOCAL DATA PROTOTYPES
 *********************************************************************************************************************/
#define VHSMUPD_EXT_START_SEC_VAR_NOINIT_RAM_BUFFER
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! The buffer used for processing the update. Align this buffer to 4 byte. */
VAR(uint8, VHSMUPD_EXT_VAR_NOINIT) vHsmUpd_Ext_ProcessingDataBuffer[VHSMUPD_EXT_DECRYPTION_RAM_BUFFER_SIZE];

#define VHSMUPD_EXT_STOP_SEC_VAR_NOINIT_RAM_BUFFER
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
#define VHSMUPD_EXT_START_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  vHsmUpd_Ext_WaitForHost()
 *********************************************************************************************************************/
/*!
 * \brief       Checks if the Host is ready for the update
 * \details     -
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */
VHSMUPD_EXT_LOCAL_INLINE FUNC(void, VHSMUPD_EXT_CODE) vHsmUpd_Ext_WaitForHost(void);

/**********************************************************************************************************************
 *  vHsmUpd_Ext_PrepareUpdate()
 *********************************************************************************************************************/
/*!
 * \brief       Prepares the update by checking the image and erasing the flash.
 * \details     -
 * \return      E_OK if the preparation was ok, E_NOT_OK otherwise.
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */
VHSMUPD_EXT_LOCAL_INLINE FUNC(Std_ReturnType, VHSMUPD_EXT_CODE) vHsmUpd_Ext_PrepareUpdate(void);

/**********************************************************************************************************************
 *  vHsmUpd_Ext_InitializeUpdateProcess()
 *********************************************************************************************************************/
/*!
 * \brief       Evaluate the update header and set internal status for processing the update. Setups the decryption
 *              process for the given update image.
 * \details     -
 * \return      E_OK, if the update process was initialized successfully, E_NOT_OK otherwise.
 * \pre         An update image available, which is at least the size of the configured buffer size.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */
VHSMUPD_EXT_LOCAL_INLINE FUNC(Std_ReturnType, VHSMUPD_EXT_CODE) vHsmUpd_Ext_InitializeUpdateProcess(void);

/**********************************************************************************************************************
 *  vHsmUpd_Ext_DecryptAndWriteImage()
 *********************************************************************************************************************/
/*!
 * \brief       Decrypts the image partwise and writes it decrypted to the codeflash of the hsm.
 * \details     -
 * \return      E_OK The decryption and write process was successfull.
 * \param[in]   regionHeader    The current region.
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */
VHSMUPD_EXT_LOCAL_INLINE FUNC(Std_ReturnType, VHSMUPD_EXT_CODE) vHsmUpd_Ext_DecryptAndWriteImage(
  vHsmUpd_Ext_ModuleUpdateHeaderConstPtrType regionHeader);

/**********************************************************************************************************************
 *  vHsmUpd_Ext_WriteUpdateVersion()
 *********************************************************************************************************************/
/*!
 * \brief       Writes the update version into the codeflash
 * \details     -
 * \return      E_OK If the write process was successfull.
 * \param[in]   regionHeader    The current region.
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */
VHSMUPD_EXT_LOCAL_INLINE FUNC(Std_ReturnType, VHSMUPD_EXT_CODE) vHsmUpd_Ext_WriteUpdateVersion(
  vHsmUpd_Ext_ModuleUpdateHeaderConstPtrType regionHeader);

/**********************************************************************************************************************
 *  vHsmUpd_Ext_GetMaxVersionOfPartitionId()
 *********************************************************************************************************************/
/*!
 * \brief       Iterates over all regions of a partition and evaluates the maximum update version.
 * \details     -
 * \return      E_OK If processing was successfull.
 * \param[in]   partitionId     The partition id to read on.
 * \param[out]  maxVersion      Maximum update version on the partition.
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */
VHSMUPD_EXT_LOCAL FUNC(Std_ReturnType, VHSMUPD_EXT_CODE) vHsmUpd_Ext_GetMaxVersionOfPartitionId(
  vHsmUpd_Ext_PartitionIdOfPartitionsType partitionId,
  vHsmUpd_Ext_VersionPtrType maxVersion);

#define VHSMUPD_EXT_STOP_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/
#define VHSMUPD_EXT_START_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  vHsmUpd_Ext_WaitForHost()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
VHSMUPD_EXT_LOCAL_INLINE FUNC(void, VHSMUPD_EXT_CODE) vHsmUpd_Ext_WaitForHost(void)
{
  boolean waitState = FALSE;

  /* #10 Do nothing as long as the Host is not ready. */
  while(waitState == FALSE)
  {
    waitState = vHsmUpd_Ext_IsHostStateSet(vHsmUpd_Ext_HostToHsmIpcInitialized);

    /* #20 Trigger the callout in the loop */
    vHsmUpd_Ext_WaitForHost_Callout(&waitState);
  }
}

/**********************************************************************************************************************
 *  vHsmUpd_Ext_PrepareUpdate()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
VHSMUPD_EXT_LOCAL_INLINE FUNC(Std_ReturnType, VHSMUPD_EXT_CODE) vHsmUpd_Ext_PrepareUpdate(void)
{
  Std_ReturnType retVal = E_NOT_OK;

  /* Start update process (decrypting) */
  if(vHsmUpd_Ext_InitializeUpdateProcess() == E_NOT_OK)
  {
    /* Nothing to do. RetVal already set. */
  }
  else if(vHsmUpd_Ext_DecryptSBL() == E_NOT_OK)
  {
    /* Nothing to do. RetVal already set. */
  }
  else if(vHsmUpd_Ext_SizeOfRegionUpdate() == E_OK)
  {
    retVal = E_OK;
  }
  else
  {
    /* Misra Compliant */
  }

  return retVal;
}

/**********************************************************************************************************************
 *  vHsmUpd_Ext_InitializeUpdateProcess()
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
VHSMUPD_EXT_LOCAL_INLINE FUNC(Std_ReturnType, VHSMUPD_EXT_CODE) vHsmUpd_Ext_InitializeUpdateProcess(void)
{
  Std_ReturnType retVal = E_NOT_OK;

  /* #10 Set the needed values for the update process */
  vHsmUpd_Ext_UpdState.BlockLength = sizeof(vHsmUpd_Ext_ProcessingDataBuffer);
  vHsmUpd_Ext_UpdState.CurrentUpdateFwImageAddress = vHsmUpd_Ext_GetImageStartAddress();
  /* #20 Setup decryption of the image */
  if( vHsmUpd_Ext_InitDecryption() == E_NOT_OK )
  {
    /* nothing to do */
  }
  /* #21 After successfully starting, decrypt the first two block informations: FwOffset and Crc offset */
  else if( vHsmUpd_Ext_DecryptImageBlock(vHsmUpd_Ext_ProcessingDataBuffer, VHSMUPD_EXT_SIZE_OF_IMAGE_INFO, vHsmUpd_Ext_UpdState.CurrentUpdateFwImageAddress) == E_OK )
  {
    vHsmUpd_Ext_UpdState.CurrentUpdateFwImageAddress += VHSMUPD_EXT_SIZE_OF_IMAGE_INFO;
    /* Decrypted data available, use it to determine the vHsm firmware size */
    vHsmUpd_Ext_ParseUpdateImageInformation(vHsmUpd_Ext_ProcessingDataBuffer);
    retVal = E_OK;
  }
  else
  {
    /* Nothing to do */
  }

  return retVal;
}

/**********************************************************************************************************************
 *  vHsmUpd_Ext_DecryptAndWriteImage()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
VHSMUPD_EXT_LOCAL_INLINE FUNC(Std_ReturnType, VHSMUPD_EXT_CODE) vHsmUpd_Ext_DecryptAndWriteImage(vHsmUpd_Ext_ModuleUpdateHeaderConstPtrType regionHeader)
{
  Std_ReturnType retVal;
  vHsmUpd_Ext_AddressType targetAddress = regionHeader->VirtualRegionAddress;
  vHsmUpd_Ext_AddressType imageSourceAddress = vHsmUpd_Ext_GetAddressOfFwDataInUpdateImage() + regionHeader->ModuleUpdateImageOffset;
  vHsmUpd_Ext_LengthType  remainingImageLength = regionHeader->ModuleUpdateImageLength;
  vHsmUpd_Ext_LengthType  lengthToWrite;
  vHsmUpd_Ext_LengthType  paddedLength;

  retVal = vHsmUpd_Ext_CheckCurrentDecryptionPoint(imageSourceAddress);

  while((remainingImageLength > 0u) && (retVal == E_OK))
  {
    /* Check if the full Blocksize is available */
    if(remainingImageLength > VHSMUPD_EXT_DECRYPTION_RAM_BUFFER_SIZE)
    {
      retVal = vHsmUpd_Ext_DecryptImageBlock(vHsmUpd_Ext_ProcessingDataBuffer, VHSMUPD_EXT_DECRYPTION_RAM_BUFFER_SIZE, vHsmUpd_Ext_UpdState.CurrentUpdateFwImageAddress);
      vHsmUpd_Ext_UpdState.CurrentUpdateFwImageAddress += VHSMUPD_EXT_DECRYPTION_RAM_BUFFER_SIZE;
      lengthToWrite = VHSMUPD_EXT_DECRYPTION_RAM_BUFFER_SIZE;
      remainingImageLength -= VHSMUPD_EXT_DECRYPTION_RAM_BUFFER_SIZE;
    }
    else
    {
      /* Check aes block alignment in update image */
      if((remainingImageLength % VHSMUPD_EXT_AES_BLOCKSIZE) == 0u)
      {
        retVal = vHsmUpd_Ext_DecryptImageBlock(vHsmUpd_Ext_ProcessingDataBuffer, remainingImageLength, vHsmUpd_Ext_UpdState.CurrentUpdateFwImageAddress);
        vHsmUpd_Ext_UpdState.CurrentUpdateFwImageAddress += remainingImageLength;
        paddedLength = remainingImageLength;

      }
      else
      {
        paddedLength = ((remainingImageLength / VHSMUPD_EXT_AES_BLOCKSIZE) + 1u) * VHSMUPD_EXT_AES_BLOCKSIZE;
        retVal = vHsmUpd_Ext_DecryptImageBlock(vHsmUpd_Ext_ProcessingDataBuffer, paddedLength, vHsmUpd_Ext_UpdState.CurrentUpdateFwImageAddress);
        vHsmUpd_Ext_UpdState.CurrentUpdateFwImageAddress += paddedLength;
      }
      /* Check Platform pagesize alignment */
      lengthToWrite = vHsmUpd_Ext_CheckPagesizeAlignmentAndPad(vHsmUpd_Ext_ProcessingDataBuffer, remainingImageLength, paddedLength);
      remainingImageLength = 0u;
    }

    if(retVal == E_OK)
    {
      retVal = vHsmUpd_WriteData(vHsmUpd_Ext_GetAddressAreaRefOfPartitions(regionHeader->TargetInformations.IndexOfTargetPartition), vHsmUpd_Ext_ProcessingDataBuffer, lengthToWrite, targetAddress);
      targetAddress += lengthToWrite;
    }
  }

  return retVal;
}

/**********************************************************************************************************************
 *  vHsmUpd_Ext_WriteUpdateVersion()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
VHSMUPD_EXT_LOCAL_INLINE FUNC(Std_ReturnType, VHSMUPD_EXT_CODE) vHsmUpd_Ext_WriteUpdateVersion(vHsmUpd_Ext_ModuleUpdateHeaderConstPtrType regionHeader)
{
  Std_ReturnType retVal;
  uint8 versionInformationToWrite[VHSMUPD_EXT_PLATFORM_PAGESIZE] = {0u};
  uint16 index;

  /* Check if we are in the last loop of the current updated Region */
  if(vHsmUpd_Ext_UpdState.CurrentUpdateModule == (vHsmUpd_Ext_UpdState.NumberOfModulesToUpdate - 1u))
  {
    /* In the last loop, the image header version is written into the second part of the version information */
    for(index = 0u; index < VHSMUPD_EXT_UPDATEHEADER_VERSIONINFO_SIZE; index++)
    {
      versionInformationToWrite[index] = vHsmUpd_Ext_CurrentUpdHdr.VersionInfo[index];
    }
  }

  /* Write the version information into the codeflash */
  retVal = vHsmUpd_WriteData(vHsmUpd_Ext_GetAddressAreaRefOfPartitions(regionHeader->TargetInformations.IndexOfTargetPartition),
                            versionInformationToWrite,
                            VHSMUPD_EXT_PLATFORM_PAGESIZE,
                            vHsmUpd_Ext_GetStartAddressOfRegion(regionHeader->TargetInformations.IndexOfTargetRegion) + (2u* VHSMUPD_EXT_PLATFORM_PAGESIZE));

  return retVal;
}

/**********************************************************************************************************************
 *  vHsmUpd_Ext_GetMaxVersionOfPartitionId()
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
VHSMUPD_EXT_LOCAL FUNC(Std_ReturnType, VHSMUPD_EXT_CODE) vHsmUpd_Ext_GetMaxVersionOfPartitionId(
  vHsmUpd_Ext_PartitionIdOfPartitionsType partitionId, 
  vHsmUpd_Ext_VersionPtrType maxVersion)
{
  Std_ReturnType retVal = E_OK;
  Std_ReturnType validState;
  uint8 readBuffer[sizeof(vHsmUpd_Ext_VersionType)];
  vHsmUpd_Ext_OffsetType updateVersionOffset = 2u * VHSMUPD_EXT_PLATFORM_PAGESIZE;
  uint16 loopIndex;

  /* Get maximum update version number from partition */
  for(loopIndex = 0u; (loopIndex < vHsmUpd_Ext_GetSizeOfRegion()) && (retVal == E_OK); loopIndex++)
  {
    /* Check the presence pattern of each region. */
    validState = vHsmUpd_ReadPresencePattern(vHsmUpd_Ext_GetAddressAreaRefOfPartitions(partitionId), 
                      vHsmUpd_Ext_GetStartAddressOfRegion(loopIndex),
                      TARGET_HSM);
    /* Do not abort the update if the region is not valid */
    if(validState == E_OK)
    {
      /* Read the version information from the region. */
      retVal = vHsmUpd_Read_Callout(vHsmUpd_Ext_GetAddressAreaRefOfPartitions(partitionId),
                        readBuffer,
                        sizeof(vHsmUpd_Ext_VersionType),
                        (vHsmUpd_Ext_GetStartAddressOfRegion(loopIndex) + updateVersionOffset), 
                        TARGET_HSM);
      /* Compare the region version. */
      if(*maxVersion < vHsmUpd_BigEndianByteArrayToUint32(readBuffer))
      {
        *maxVersion = vHsmUpd_BigEndianByteArrayToUint32(readBuffer);
      }
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
 *  vHsmUpd_Ext_Init()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, VHSMUPD_EXT_CODE) vHsmUpd_Ext_Init(void)
{
  vHsmUpd_Ext_ValidityInfo.validFirmwareAvailable = FALSE;
  vHsmUpd_Ext_UpdState.NumberOfModulesToUpdate = 0u;
  /* Write update not started to shared memory location and set Hsm state to HsmUpdRunning */
  vHsmUpd_Ext_StateCallbackNotification(VHSMUPD_EXT_UPDATE_NOT_STARTED);
  vHsmUpd_Ext_SetHsmState(vHsmUpd_Ext_HsmToHostUpdRunning);
}

/**********************************************************************************************************************
 *  vHsmUpd_Ext_HsmStateClear()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, VHSMUPD_EXT_CODE) vHsmUpd_Ext_HsmStateClear(void)
{

  vHsmUpd_Ext_ClearHsmState(vHsmUpd_Ext_HsmToHostReady);
  vHsmUpd_Ext_ClearHsmState(vHsmUpd_Ext_HsmToHostAvailable);
}

/**********************************************************************************************************************
 *  vHsmUpd_Ext_CompatibilityCheck()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(Std_ReturnType, VHSMUPD_EXT_CODE) vHsmUpd_Ext_CompatibilityCheck(void)
{
  Std_ReturnType retVal;
  vHsmUpd_Ext_VersionType maxVersionActivePartition = 0u;
  vHsmUpd_Ext_VersionType maxVersionInactivePartition = 0u;
  vHsmUpd_Ext_VersionType updateVersionFromHeader;

  vHsmUpd_Ext_PartitionIdOfPartitionsType activePartitionIndex;

  updateVersionFromHeader = vHsmUpd_BigEndianByteArrayToUint32(vHsmUpd_Ext_CurrentUpdHdr.VersionInfo);

  retVal = vHsmUpd_Ext_GetActivePartitionId(&activePartitionIndex);

  if(retVal == E_OK)
  {
    /* Get maximum update version number from active partition */
    retVal = vHsmUpd_Ext_GetMaxVersionOfPartitionId(activePartitionIndex, &maxVersionActivePartition);

    /* Get maximum update version number from inactive partition */
#if(vHsmUpd_Ext_GetSizeOfPartitions() > 1u)
    {
      vHsmUpd_Ext_PartitionIdOfPartitionsType inactivePartitionIndex = activePartitionIndex ^ (vHsmUpd_Ext_PartitionIdOfPartitionsType)1u;

      retVal |= vHsmUpd_Ext_GetMaxVersionOfPartitionId(inactivePartitionIndex, &maxVersionInactivePartition);

    }
#endif

    if(retVal == E_OK)
    {
      retVal = E_NOT_OK;
#if (VHSMUPD_EXT_ENABLE_USER_COMPARE_MECHANISM == STD_ON)
      if(vHsm_FirmwareUpdate_VersionCompare_Callout(updateVersionFromHeader, maxVersionActivePartition, maxVersionInactivePartition) == TRUE)
      {
        retVal = E_OK;
      }
#else
      if((updateVersionFromHeader > maxVersionActivePartition) &&  (updateVersionFromHeader > maxVersionInactivePartition)) /* PRQA S 2995 */ /* MD_vHsmUpd_Ext_AlwaysTrue */
      {
        retVal = E_OK;
      }
#endif
    }
  }

  return retVal;
}

/**********************************************************************************************************************
 *  vHsmUpd_Ext_GetUpdateHeaderLocation()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
FUNC(vHsmUpd_Ext_AddressType, VHSMUPD_EXT_CODE) vHsmUpd_Ext_GetUpdateHeaderLocation(void)
{
  vHsmUpd_Ext_AddressType retVal = (uint32)VHSMUPD_EXT_UPDHEADER_INVALID;

#if (VHSMUPD_EXT_UPDATE_HEADER_FIX_ADDRESS == STD_ON)
  /* Check locations A and B for valid update headers, use the first valid. */
  if( vHsmUpd_ReadPresencePattern(VHSMUPD_ADDRESS_AREA_OF_HOST, (uint32)VHSMUPD_EXT_HEADER_LOCATION_A, TARGET_HOST) == E_OK )
  {
    retVal = (uint32)VHSMUPD_EXT_HEADER_LOCATION_A;
  }
  else if( vHsmUpd_ReadPresencePattern(VHSMUPD_ADDRESS_AREA_OF_HOST, (uint32)VHSMUPD_EXT_HEADER_LOCATION_B, TARGET_HOST) == E_OK)
  {
    retVal = (uint32)VHSMUPD_EXT_HEADER_LOCATION_B;
  }
  else
  {
    /* MISRA compliance */
  }
#else
  /* If a flash memory area shall be used: Search for maximal the number of configured locations for the update header,
  use also the first one found to be valid. */
  uint32 remainingNumberOfHeaderLocations = (uint32)VHSMUPD_EXT_NUMBER_OF_POSSIBLE_HEADERS;
  vHsmUpd_Ext_AddressType currentHeaderSearchAddress = (vHsmUpd_Ext_AddressType)VHSMUPD_EXT_FIRST_HEADER_ADDRESS;

  do
  {
    if(vHsmUpd_ReadPresencePattern(VHSMUPD_ADDRESS_AREA_OF_HOST, currentHeaderSearchAddress, TARGET_HOST) == E_OK)
    {
      retVal = currentHeaderSearchAddress;
      break;
    }
    --remainingNumberOfHeaderLocations;
    /* Calculate the next address to parse for pp:
     * pp-length = 2 * flash page size + 44Bytes header length which must be filled with padding bytes (if needed) */
    currentHeaderSearchAddress += ((2u * VHSMUPD_EXT_PLATFORM_PAGESIZE) + ( vHsmUpd_Ext_HeaderLengthInPages * VHSMUPD_EXT_PLATFORM_PAGESIZE ));
  } while(remainingNumberOfHeaderLocations > 0u);

#endif
  return retVal;
}

/**********************************************************************************************************************
 *  vHsmUpd_Ext_CheckUpdateCondition()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(Std_ReturnType, VHSMUPD_EXT_CODE) vHsmUpd_Ext_CheckUpdateCondition(void)
{
  Std_ReturnType retVal = E_NOT_OK;
  if((vHsmUpd_Ext_ValidityInfo.validFirmwareAvailable == FALSE)
    || (vHsmUpd_Ext_IsHsmStateSet(vHsmUpd_Ext_HsmToHostReady) == E_OK))     /* PRQA S 3415 */ /* MD_vHsmUpd_Ext_OperatorOrder */
  {
    vHsmUpd_Ext_HsmStateClear();
    /* Check if there is a valid image header and the compatibility */
    if( vHsmUpd_Ext_CheckUpdateRequest() == E_OK )
    {
      retVal = E_OK;
    }
  }
  return retVal;
}

/**********************************************************************************************************************
 *  vHsmUpd_Ext_CheckUpdateRequest()
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
FUNC(Std_ReturnType, VHSMUPD_EXT_CODE) vHsmUpd_Ext_CheckUpdateRequest(void)
{
  Std_ReturnType retVal = E_NOT_OK;

   /* #10 Check if valid update is available, */
  if( vHsmUpd_Ext_CheckValidUpdate() == TRUE )
  {
  /* On multiple modules, the version compairson is done for each update module while the update is processed. */
    /* #11 Then check if the current firmware is available */
    if (vHsmUpd_Ext_ValidityInfo.validFirmwareAvailable == TRUE)
    {
      /* #111 Both true, then get update version from internal Memory Abstraction */
      /* #112 And check if version is greater than the current installed one */
      if( vHsmUpd_Ext_CompatibilityCheck() == E_OK ) /* PRQA S 3415 */ /* MD_vHsmUpd_Ext_OperatorOrder */
      {
        /* #1121 set to E_OK if an update is requested */
        retVal = E_OK;
      }
    }
    else
    {
      /* #121 No firmware is available so just return with update request */
      retVal = E_OK;
    }
  }
  return retVal;
}

/**********************************************************************************************************************
 *  vHsmUpd_Ext_CheckValidUpdate()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
FUNC(boolean, VHSMUPD_EXT_CODE) vHsmUpd_Ext_CheckValidUpdate(void)
{
  vHsmUpd_Ext_AddressType updateHeaderLocation = vHsmUpd_Ext_GetUpdateHeaderLocation();
  boolean retVal = FALSE;

  /* #10 Check for which location to search for valid update header */
  if( updateHeaderLocation != VHSMUPD_EXT_UPDHEADER_INVALID )
  {
    /* #20 If an valid update header was found, read it */
    if(vHsmUpd_Ext_ReadUpdateHeader(updateHeaderLocation) == E_NOT_OK)
    {

    }
    /* #30 The update header could be read than check for update header tag
     * and set result to TRUE if the tag is valid */
    else if( vHsmUpd_Ext_CheckUpdateHeader() == E_OK )
    {
      retVal = TRUE;
    }
    else
    {
      /* Misra compliant */
    }

  }
  return retVal;
}

/**********************************************************************************************************************
 *  vHsmUpd_Ext_PrepareAndVerifyUpdate()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
FUNC(Std_ReturnType, VHSMUPD_EXT_CODE) vHsmUpd_Ext_PrepareAndVerifyUpdate(void)
{
  Std_ReturnType retVal;

  if(vHsmUpd_Ext_ValidityInfo.validFirmwareAvailable == TRUE)
  {
    retVal = E_OK;
    vHsmUpd_Ext_ValidityInfo.isRecoveryMode = FALSE;
  }
  else
  {
    vHsmUpd_Ext_ValidityInfo.isRecoveryMode = TRUE;

    /* Start the application cores if necessary */
    retVal = vHsm_FirmwareUpdate_Update_Callout();

    /* Wait for the host application to startup and go to ram loop. */
    vHsmUpd_Ext_WaitForHost();
  }

  if((vHsmUpd_Ext_VerifyUpdateImage() == E_OK)
    && (retVal == E_OK))
  {
    /* Nothing to do */
  }
  else
  {
    vHsm_FirmwareUpdate_Error_Callout(VHSMUPD_EXT_NO_DATA_ERROR);
    retVal = E_NOT_OK;
  }

  return retVal;
}

/**********************************************************************************************************************
 *  vHsmUpd_Ext_ProcessUpdateParts()
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
 *
 *
 *
 *
 *
 */
FUNC(Std_ReturnType, VHSMUPD_EXT_CODE) vHsmUpd_Ext_ProcessUpdateParts(void)
{
  Std_ReturnType retVal;
  uint32 retries = 0u;
  uint32 loopIndex;

  do
  {
    retVal = vHsmUpd_Ext_PrepareUpdate();

    for(loopIndex = 0u; (loopIndex < vHsmUpd_Ext_UpdState.NumberOfModulesToUpdate) && (retVal == E_OK); loopIndex++)
    {
      retVal = E_NOT_OK;
      vHsmUpd_Ext_UpdState.CurrentUpdateModule = loopIndex;

      if(vHsmUpd_Ext_InvalidatePresencePatternOfModule(&vHsmUpd_Ext_ModularUpdateHeader[vHsmUpd_Ext_UpdState.CurrentUpdateModule]) == E_NOT_OK)
      {
        /* Nothing to do */
      }
      else if(vHsmUpd_Ext_EraseRegion(&vHsmUpd_Ext_ModularUpdateHeader[vHsmUpd_Ext_UpdState.CurrentUpdateModule]) == E_NOT_OK)
      {
         /* Nothing to do */
      }
      else if (vHsmUpd_Ext_DecryptAndWriteImage(&vHsmUpd_Ext_ModularUpdateHeader[vHsmUpd_Ext_UpdState.CurrentUpdateModule]) == E_NOT_OK)
      {
         /* Nothing to do */
      }
      else if (vHsmUpd_Ext_VerifyWrittenRegionImage(&vHsmUpd_Ext_ModularUpdateHeader[vHsmUpd_Ext_UpdState.CurrentUpdateModule]) == E_NOT_OK)
      {
         /* Nothing to do */
      }
      else if (vHsmUpd_Ext_WriteUpdateVersion(&vHsmUpd_Ext_ModularUpdateHeader[vHsmUpd_Ext_UpdState.CurrentUpdateModule]) == E_NOT_OK)
      {
        /* Nothing to do */
      }
      else if (vHsmUpd_Ext_ValidatePresencePatternOfRegion(&vHsmUpd_Ext_ModularUpdateHeader[vHsmUpd_Ext_UpdState.CurrentUpdateModule]) == E_OK)
      {
        retVal = E_OK;
      }
      else
      {
        /* Misra compliant */
      }
    }

    /* Save update try and check if retries left. If no retry left fail the update otherwise do update again. */
    retries++;
  } while ((retries <= VHSMUPD_EXT_RETRY_COUNTER) && (retVal == E_NOT_OK)); /* PRQA S 2996, 2993 */ /* MD_vHsmUpd_Ext_RetryCounter */

  if(retVal == E_NOT_OK)
  {
    vHsm_FirmwareUpdate_Error_Callout(VHSMUPD_EXT_UPDATE_ERROR);
    /* Before calling the update fail callout, ensure that there is no recovery possible. If the firmware is still available just start the firmware. */
    if( (vHsmUpd_Ext_ValidityInfo.validFirmwareAvailable == FALSE) )
    {
      while(vHsmUpd_Ext_AlwaysTrue == TRUE) /*lint !e506 */ /* COV_VHSMUPD_EXT_ENDLESSLOOP */ /* PRQA S 2871, 2990, 2995 */ /* MD_vHsmUpd_Ext_Endlessloop */
      {

      }
    }
  }
  return retVal;
} /* PRQA S 6030, 6050, 6080 */ /* MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

/**********************************************************************************************************************
 *  vHsmUpd_Ext_PostUpdateProcessing()
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
FUNC(Std_ReturnType, VHSMUPD_EXT_CODE) vHsmUpd_Ext_PostUpdateProcessing(void)
{
  /* #10 Write update completed to shared memory location */
  vHsmUpd_Ext_StateCallbackNotification(VHSMUPD_EXT_UPDATE_COMPLETED);

  /* #20 If Recovery mode is active */
  if(vHsmUpd_Ext_ValidityInfo.isRecoveryMode == TRUE)
  {
    /* #21 Trigger firmware reset */
    vHsmUpd_TriggerSoftwareReset_Callout();
  }
  else
  {
    /* #30 Otherwise start vHsm firmware */
    vHsmUpd_Ext_StartHsmFw();
  }
  /* Never reached */
  return E_OK;
}

/**********************************************************************************************************************
 *  vHsmUpd_Ext_ErrorHandling()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, VHSMUPD_EXT_CODE) vHsmUpd_Ext_ErrorHandling(void)
{
  /* No image and update available trigger a callout, which should not return */
  vHsm_FirmwareUpdate_Error_Callout(VHSMUPD_EXT_NO_DATA_ERROR);
}

#define VHSMUPD_EXT_STOP_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* Justification for module-specific MISRA deviations:

MD_vHsmUpd_Ext_OperatorOrder:
  Reason:       The operator order was chosen exactly the order intended to be. If the first operand of the comparison was not successful
                the right hand operation shall not be executed. Can be ensured by the C standard.
  Risk:         No risk.
  Prevention:   No prevention.

MD_vHsmUpd_Ext_DriverInterface:
  Reason:       The memory driver interface and the crypto library expect uint16 as length parameter. The type used for the
                internal calculation of the length is uint32.
  Risk:         The calculation with uint32 and uint16 in one assignment could lead to truncation. This would prevent buffer overflow, but could
                lead to an unsuccessful operation of the module. We assume that the smallest writable unit of flash is smaller than 32KB.
  Prevention:   Explicit check for truncation within the implementation.

MD_vHsmUpd_Ext_MemoryAccess:
  Reason:       The vHsmUpd uses a memory mapped read from flash. This involves a cast between a pointer to a volatile object and an integral type.
                The address configured for the Ipc base address is used as a RAM location where the vHsmUpd communicates it's current update state.
  Risk:         Size of pointer type is hardware specific - not compatible between platforms. Invalid memory access.
  Prevention:   No prevention.

MD_MSR_STMIF:
  Reason:       A lower nesting lowers the readability of the function.
  Risk:         None
  Prevention:   Covered by code review and tests.

MD_MSR_STCYC:
  Reason:       A lower complexity lowers the readability of the function.
  Risk:         None
  Prevention:   Covered by code review and tests.

MD_MSR_STCAL
  Reason:       A lower number of distinct function calls lowers the readability of the function.
  Risk:         None
  Prevention:   Covered by code review and tests.

MD_vHsmUpd_Ext_ConstConfigData:
  Reason:       Configuration constants/tables are kept at a central location for a better overview and maintenance.
  Risk:         Scope is larger than required (whole file instead of one function). Some other function could access
                the variable.
  Prevention:   Take care that this deviation is used for constant data only (which cannot be modified).

MD_vHsmUpd_Ext_HwConfDependentClause:
  Reason:       The Code and the clauses around are hardware and or configuration dependent
  Risk:         The Code isn't executed in every configuration
  Prevention:   Covered by code review and tests.

MD_vHsmUpd_Ext_ConstConfigData:
  Reason:     Configuration constants/tables are kept at a central location for a better overview and maintenance.
  Risk:       Scope is larger than required (whole file instead of one function). Some other function could access
              the variable.
  Prevention: Take care that this deviation is used for constant data only (which cannot be modified).

MD_vHsmUpd_Ext_DataType:
  Reason:     All external used addresses and its content are interpreted as big endian byte stream. Some data is then reinterpreted as
              firmware information for the vHsmUpd module.
  Risk:       Pointer type mismatch, which could lead to wrong interpretation of data.
  Prevention: Correct memory layout of external build update image.

MD_vHsmUpd_Ext_RetryCounter:
  Reason: The retry counter is configurable by the user, but the code part to check for it's value is always there. If no retries are
  configured the while-statement result will always be false.
  updFncPtrTableIdx assignment then also is redundant since the while condition will be false.
  Risk: Execution of unneeded code.
  Prevention: Encapsulate the while-statement with a preprocessor switch to disable the code part.

MD_vHsmUpd_Ext_Endlessloop
  Reason:     Endless loop, which caches the execution on unhandable fail.
  Risk:       None
  Prevention: Covered by code review and tests.

MD_vHsmUpd_Ext_AlwaysTrue
  Reason:     Configuration dependent. Depending on the configuration, the expression or a part of the expression is statically 
              TRUE or FALSE.
  Risk:       None
  Prevention: Covered by code review and tests.
 */

/* COV_JUSTIFICATION_BEGIN

\ID COV_VHSMUPD_EXT_COMPATIBILITY
 \ACCEPT TX
 \ACCEPT XF
 \REASON COV_MSR_COMPATIBILITY

\ID COV_VHSMUPD_EXT_TEST
  \ACCEPT TX
  \REASON This define must be used when the component is under test. Must be disabled for production.

\ID COV_VHSMUPD_EXT_ENDLESSLOOP
  \ACCEPT XF
  \ACCEPT XX
  \REASON Endless loop, which caches the execution on unhandable fail.

COV_JUSTIFICATION_END */

/**********************************************************************************************************************
 *  END OF FILE: vHsmUpd_Ext.c
 *********************************************************************************************************************/
