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
/*!        \file  vHsmUpd_Ext_Crypto.c
 *        \brief  vHsmUpd Vector Extension cryptographic related source file
 *
 *      \details  The cryptographic handling of the vHsmUpd_Ext
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 *********************************************************************************************************************/

#define VHSMUPD_EXT_CRYPTO_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "ESLib.h"
#include "Crc.h"
#include "vHsmUpd.h"
#include "vHsmUpd_Ext_Private.h"

/**********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTION MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
#if !defined (VHSMUPD_EXT_LOCAL) /* COV_VHSMUPD_EXT_COMPATIBILITY */
# define VHSMUPD_EXT_LOCAL static
#endif

#if !defined (VHSMUPD_EXT_LOCAL_INLINE) /* COV_VHSMUPD_EXT_COMPATIBILITY */
# define VHSMUPD_EXT_LOCAL_INLINE LOCAL_INLINE
#endif

typedef P2CONST(eslt_Byte, AUTOMATIC, VHSMUPD_EXT_APPL_CONST) vHsmUpd_Ext_ConstDataPtrEsltByteType;

/**********************************************************************************************************************
 *  LOCAL DATA PROTOTYPES
 *********************************************************************************************************************/
# define VHSMUPD_EXT_START_SEC_VAR_NOINIT_UNSPECIFIED
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

VHSMUPD_EXT_LOCAL VAR(eslt_WorkSpaceAES128, VHSMUPD_EXT_VAR_NOINIT) vHsmUpd_Ext_AESWorkspace;
VHSMUPD_EXT_LOCAL VAR(eslt_WorkSpaceCMACAES, VHSMUPD_EXT_VAR_NOINIT) vHsmUpd_Ext_MacWorkspace;

# define VHSMUPD_EXT_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
#define VHSMUPD_EXT_START_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  vHsmUpd_Ext_DecryptFirstBlock()
 *********************************************************************************************************************/
/*!
 * \brief       Starts the decryption with the first AES block. No data will be returned since the aes implementation
 *              buffers always one block internal.
 * \details     -
 * \return      E_OK, if the decryption was successful, E_NOT_OK otherwise
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */
VHSMUPD_EXT_LOCAL_INLINE FUNC(Std_ReturnType, VHSMUPD_EXT_CODE) vHsmUpd_Ext_DecryptFirstBlock(void);

/**********************************************************************************************************************
 *  vHsmUpd_Ext_GenerateMac()
 *********************************************************************************************************************/
/*!
 * \brief       Generates a CMAC over the given address area.
 * \details     -
 * \return      E_OK, if the CMAC generation was successful, E_NOT_OK otherwise
 * \param[in]   startAddress  The start address of the CMAC calculation within the flash.
 * \param[in]   length        The length of the data, which will be used for CMAC; must be aligned to 16Bytes.
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */
VHSMUPD_EXT_LOCAL_INLINE FUNC(Std_ReturnType, VHSMUPD_EXT_CODE) vHsmUpd_Ext_GenerateMac(
  vHsmUpd_Ext_AddressType startAddress,
  vHsmUpd_Ext_LengthType length);

/**********************************************************************************************************************
 *  vHsmUpd_Ext_CalculateHeaderInfoInMac()
 *********************************************************************************************************************/
/*!
 * \brief       Updates the CMAC calculation with all additional needed authenticated values.
 * \details     -
 * \return      E_OK, if the CMAC update was successful, E_NOT_OK otherwise
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */
VHSMUPD_EXT_LOCAL_INLINE FUNC(Std_ReturnType, VHSMUPD_EXT_CODE) vHsmUpd_Ext_CalculateHeaderInfoInMac(void);

#define VHSMUPD_EXT_STOP_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/
#define VHSMUPD_EXT_START_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  vHsmUpd_Ext_DecryptFirstBlock()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
VHSMUPD_EXT_LOCAL_INLINE FUNC(Std_ReturnType, VHSMUPD_EXT_CODE) vHsmUpd_Ext_DecryptFirstBlock(void)
{
  eslt_Byte DataStreamAESInput[ESL_SIZEOF_AES128_BLOCK] = { 0u };
  eslt_Length dummyOutput = 1u;
  eslt_Byte dummyOutputBuffer;
  Std_ReturnType retVal = E_NOT_OK;

  /* #10 Read the first AES block of the image */
  if(vHsmUpd_Read_Callout(VHSMUPD_EXT_ADDRESS_AREA_OF_HOST, DataStreamAESInput, sizeof(DataStreamAESInput), vHsmUpd_Ext_GetImageStartAddress(), TARGET_HOST) == E_NOT_OK)
  {
    /* Nothing to do on error */
  }
  /* #11 Start decryption of the data */
  /* #12 Check that first block decryption did not deliver any data */
  else if( (esl_decryptAES128(&vHsmUpd_Ext_AESWorkspace, ESL_SIZEOF_AES128_BLOCK, DataStreamAESInput, &dummyOutput, &dummyOutputBuffer)
      == ESL_ERC_NO_ERROR) && (dummyOutput == 0u) )
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
 *  vHsmUpd_Ext_GenerateMac()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
VHSMUPD_EXT_LOCAL_INLINE FUNC(Std_ReturnType, VHSMUPD_EXT_CODE) vHsmUpd_Ext_GenerateMac(
  vHsmUpd_Ext_AddressType startAddress,
  vHsmUpd_Ext_LengthType length)
{
  eslt_Byte CMACKey[ESL_SIZEOF_AES128_KEY];
  uint32 MACKeyLength = sizeof(CMACKey);
  Std_ReturnType retVal = E_NOT_OK;

  eslt_Byte DataStream[ESL_SIZEOF_AES128_BLOCK] = { 0u };
  uint32 currentReadAddress;
  uint32 NumberOfDataPackets;

  /* #10 Get the cipher key from the user */
  if( vHsm_FirmwareUpdate_GetMacKey_Callout(CMACKey, &MACKeyLength) == E_NOT_OK )
  {
    /* Nothing to do on Error */
  }
  else
  {
    /* #20 Evaluate firmware size if key available and buffer size sufficient */
    /* Length must be aligned to 16Bytes. If its not the case the update image is invalid.
     * This will be recognized as the CMAC verification will fail. */
    NumberOfDataPackets = length / ESL_SIZEOF_AES128_BLOCK;
    currentReadAddress = startAddress;

    /* #30 Generate MAC over the update image */
    if( (esl_initWorkSpaceHeader(&(vHsmUpd_Ext_MacWorkspace.header), ESL_MAXSIZEOF_WS_AES128, NULL_PTR) == ESL_ERC_NO_ERROR)
        && (esl_initCMACAES128(&vHsmUpd_Ext_MacWorkspace, ESL_SIZEOF_AES128_KEY, CMACKey) == ESL_ERC_NO_ERROR)) /* PRQA S 3415 */ /* MD_vHsmUpd_Ext_OperatorOrder */
    {
      retVal = E_OK;
      /* In general this could also be calculated within 64KB steps if the flash address would be the input for the calculation.
       * vHsmUpd shall be HW-independent therefore go over the memory driver interface to secure "working" read. */
      for(; ((NumberOfDataPackets > 0u) && (retVal == E_OK)); --NumberOfDataPackets)
      {
        retVal = vHsmUpd_Read_Callout(VHSMUPD_EXT_ADDRESS_AREA_OF_HOST, DataStream, ESL_SIZEOF_AES128_BLOCK, currentReadAddress, TARGET_HOST);
        if( (esl_updateCMACAES128(&vHsmUpd_Ext_MacWorkspace, ESL_SIZEOF_AES128_BLOCK, DataStream) == ESL_ERC_NO_ERROR) )
        {
          currentReadAddress += ESL_SIZEOF_AES128_BLOCK;
        }
        else
        {
          /* Error occurred within generation of CMAC */
          retVal = E_NOT_OK;
        }
      }
    }
  }

  return retVal;
} /* PRQA S 6080 */ /* MD_MSR_STMIF */

/**********************************************************************************************************************
 *  vHsmUpd_Ext_CalculateHeaderInfoInMac()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
VHSMUPD_EXT_LOCAL_INLINE FUNC(Std_ReturnType, VHSMUPD_EXT_CODE) vHsmUpd_Ext_CalculateHeaderInfoInMac(void)
{
  Std_ReturnType retVal = E_NOT_OK;
  uint32 length = 0u;
  vHsmUpd_Ext_ConstDataPtrEsltByteType ptrToValue = NULL_PTR;

  /* #10 get all additional needed values for the CMAC calculation and add them to the CMAC
   * If one of them throws an error abort and set negative result. */
  vHsmUpd_Ext_GetRawVersionValueInUpdHdr(&ptrToValue, &length);
  if(esl_updateCMACAES128(&vHsmUpd_Ext_MacWorkspace, (eslt_Length)length, ptrToValue) == ESL_ERC_NO_ERROR) /* PRQA S 4461 */ /* MD_vHsmUpd_Ext_DriverInterface */
  {
    vHsmUpd_Ext_GetRawAddressValueInUpdHdr(&ptrToValue, &length);
    if(esl_updateCMACAES128(&vHsmUpd_Ext_MacWorkspace, (eslt_Length)length, ptrToValue) == ESL_ERC_NO_ERROR) /* PRQA S 4461 */ /* MD_vHsmUpd_Ext_DriverInterface */
    {
      vHsmUpd_Ext_GetRawLengthValueInUpdHdr(&ptrToValue, &length);
      retVal = (Std_ReturnType)((esl_updateCMACAES128(&vHsmUpd_Ext_MacWorkspace, (eslt_Length)length, ptrToValue) == ESL_ERC_NO_ERROR) ? E_OK : E_NOT_OK); /* PRQA S 4461 */ /* MD_vHsmUpd_Ext_DriverInterface */
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
 *  vHsmUpd_Ext_VerifyWrittenRegionImage()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(Std_ReturnType, VHSMUPD_EXT_CODE) vHsmUpd_Ext_VerifyWrittenRegionImage(vHsmUpd_Ext_ModuleUpdateHeaderPtrType regionHeader)
{
  Std_ReturnType retVal = E_OK;
  vHsmUpd_Ext_AddressType targetAddress = regionHeader->VirtualRegionAddress;
  vHsmUpd_Ext_LengthType  remainingImageLength = regionHeader->ModuleUpdateImageLength;
  vHsmUpd_Ext_LengthType  lengthToAdd;
  uint32    crc32_CalculatedValue = 0u;
  uint8     crc32FromDecryption[ESL_SIZEOF_AES128_BLOCK];
  boolean   firstIteration = TRUE;

  while((remainingImageLength > 0u) && (retVal == E_OK))
  {
    /* Check if the full Blocksize is available */
    if(remainingImageLength > VHSMUPD_EXT_DECRYPTION_RAM_BUFFER_SIZE)
    {
      /* Read from Codeflash */
      retVal = vHsmUpd_Read_Callout(vHsmUpd_Ext_GetAddressAreaRefOfPartitions(regionHeader->TargetInformations.IndexOfTargetPartition),
                                                                          vHsmUpd_Ext_ProcessingDataBuffer,
                                                                          VHSMUPD_EXT_DECRYPTION_RAM_BUFFER_SIZE,
                                                                          targetAddress,
                                                                          TARGET_HSM);
      targetAddress += VHSMUPD_EXT_DECRYPTION_RAM_BUFFER_SIZE;
      lengthToAdd = VHSMUPD_EXT_DECRYPTION_RAM_BUFFER_SIZE;
      remainingImageLength -= VHSMUPD_EXT_DECRYPTION_RAM_BUFFER_SIZE;
    }
    else
    {
      /* read last part from codeflash */
      retVal = vHsmUpd_Read_Callout(vHsmUpd_Ext_GetAddressAreaRefOfPartitions(regionHeader->TargetInformations.IndexOfTargetPartition),
                                                                          vHsmUpd_Ext_ProcessingDataBuffer,
                                                                          remainingImageLength,
                                                                          targetAddress,
                                                                          TARGET_HSM);
      targetAddress += remainingImageLength;
      lengthToAdd = remainingImageLength;
      remainingImageLength = 0u;
    }

    if(retVal == E_OK)
    {
      /* Add data to crc value */
      crc32_CalculatedValue = Crc_CalculateCRC32((Crc_DataRefType) vHsmUpd_Ext_ProcessingDataBuffer, /* PRQA S 0306, 0310, 3305 2 */ /* MD_vHsmUpd_Ext_DataType */
                                                  lengthToAdd, crc32_CalculatedValue, firstIteration);
      firstIteration = FALSE;
    }
  }

  /* Standard Header, the crc value is encrypted in the last aes block */
  if(regionHeader->ModuleCrcValue == 0u)
  {
    if(vHsmUpd_Ext_DecryptLastBlock(crc32FromDecryption) == E_OK)
    {
      regionHeader->ModuleCrcValue = vHsmUpd_BigEndianByteArrayToUint32(&crc32FromDecryption[0]);
    }
  }

  /* Compare crc32 value */
  if(crc32_CalculatedValue != regionHeader->ModuleCrcValue)
  {
    retVal = E_NOT_OK;
  }

  return retVal;
}

/**********************************************************************************************************************
 *  vHsmUpd_Ext_DecryptImageBlock()
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
FUNC(Std_ReturnType, VHSMUPD_EXT_CODE) vHsmUpd_Ext_DecryptImageBlock(
  vHsmUpd_Ext_DataPtrType dataOut,
  vHsmUpd_Ext_LengthType dataLength,
  vHsmUpd_Ext_AddressType imageAddress)
{
  eslt_Byte DataStreamAESInput[VHSMUPD_EXT_DECRYPTION_RAM_BUFFER_SIZE] = { 0u };
  Std_ReturnType retVal = E_NOT_OK;
  eslt_Length outputLength = (eslt_Length)(dataLength);

  /* #10 Read the given memory location */
  /* Offset of one block must be added to the address. Crypto library still removes the first block of decryption for padding info,
   * even if there is no padding configured  */
  if(vHsmUpd_Read_Callout(VHSMUPD_EXT_ADDRESS_AREA_OF_HOST, DataStreamAESInput, dataLength, imageAddress + ESL_SIZEOF_AES128_BLOCK, TARGET_HOST) == E_NOT_OK)
  {
    /* Nothing to do on error */
  }
  /* #11 Start decryption of the data  */
  /* #12 Decryption was already started and therefore the result length must match the given one */
  else if( (esl_decryptAES128(&vHsmUpd_Ext_AESWorkspace, (eslt_Length)(dataLength), DataStreamAESInput, &outputLength, (eslt_Byte *)dataOut) == ESL_ERC_NO_ERROR)
      && (outputLength == dataLength) ) /* PRQA S 3415 */ /* MD_vHsmUpd_Ext_OperatorOrder */
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
 *  vHsmUpd_Ext_DecryptSBL()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(Std_ReturnType, VHSMUPD_EXT_CODE) vHsmUpd_Ext_DecryptSBL(void)
{
  Std_ReturnType retVal = E_OK;
  uint8 data[ESL_SIZEOF_AES128_BLOCK] = { 0u };
  uint8 modularUpdateHeaderBinary[VHSMUPD_EXT_MODULARHEADER_SIZE];
  uint32 dataLength = ESL_SIZEOF_AES128_BLOCK;
  uint8 index;

  /* First AES block is offset information */
  uint32 nrOfPackets = (vHsmUpd_Ext_GetAddressOfFwDataInUpdateImage() - vHsmUpd_Ext_UpdState.CurrentUpdateFwImageAddress) / ESL_SIZEOF_AES128_BLOCK;

  if(nrOfPackets > 1u)
  {
    /* Check first block for ModularUpdate pattern */
    if( vHsmUpd_Ext_DecryptImageBlock(data, dataLength, vHsmUpd_Ext_UpdState.CurrentUpdateFwImageAddress) == E_OK )
    {
      vHsmUpd_Ext_UpdState.CurrentUpdateFwImageAddress += ESL_SIZEOF_AES128_BLOCK;
      if(vHsmUpd_Ext_CheckForModularUpdatePattern(data) == E_OK)
      {
        /* Parse the single module update headers */
        for(index = 0u;
            (index < vHsmUpd_Ext_UpdState.NumberOfModulesToUpdate) && (retVal == E_OK);
            index++)
        {
          if(vHsmUpd_Ext_DecryptImageBlock(modularUpdateHeaderBinary, VHSMUPD_EXT_MODULARHEADER_SIZE, vHsmUpd_Ext_UpdState.CurrentUpdateFwImageAddress) == E_OK)
          {
            retVal = vHsmUpd_Ext_ParseModularUpdateHeader(modularUpdateHeaderBinary, index);
            vHsmUpd_Ext_UpdState.CurrentUpdateFwImageAddress += VHSMUPD_EXT_MODULARHEADER_SIZE;
          }
        }
      }
      else
      {
        vHsmUpd_Ext_ParseStandardHeaderToModule();
      }
    }
    else
    {
      retVal = E_NOT_OK;
    }
  }
  else
  {
    vHsmUpd_Ext_ParseStandardHeaderToModule();
  }

  /* The remaining unused sbl area is decrypted by the vHsmUpd_Ext_CheckCurrentDecryptionPoint function. */
  return retVal;
} /* PRQA S 6080 */ /* MD_MSR_STMIF */

/**********************************************************************************************************************
 *  vHsmUpd_Ext_DecryptLastBlock()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(Std_ReturnType, VHSMUPD_EXT_CODE) vHsmUpd_Ext_DecryptLastBlock(vHsmUpd_Ext_DataPtrType dataOut)
{
  eslt_Length outputLength = ESL_SIZEOF_AES128_BLOCK;

  /* #10 Finalize decryption and verify that one more data block was decrypted and returned */
  return (Std_ReturnType)( ((esl_finalizeDecryptAES128(&vHsmUpd_Ext_AESWorkspace, &outputLength, (eslt_Byte *)dataOut) == ESL_ERC_NO_ERROR)
      && (outputLength == ESL_SIZEOF_AES128_BLOCK)) ? E_OK : E_NOT_OK);
}

/**********************************************************************************************************************
 *  vHsmUpd_Ext_InitDecryption()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(Std_ReturnType, VHSMUPD_EXT_CODE) vHsmUpd_Ext_InitDecryption(void)
{
  Std_ReturnType retVal = E_NOT_OK;
  eslt_Byte AESKey[ESL_SIZEOF_AES128_KEY];
  uint32 AESKeyLength = sizeof(AESKey);
  /*!< Initialization vector used for AES */
  const eslt_Byte vHsmUpd_IV[ESL_SIZEOF_AES128_KEY] =
  { 0x53u, 0x70u, 0x65u, 0x7Au, 0x69u, 0x61u, 0x6Cu, 0x45u, 0x69u, 0x57u, 0x6Fu, 0x6Du, 0x69u, 0x73u, 0x61u, 0x75u };

  /* #10 Get the cipher key from the user */
  if( vHsm_FirmwareUpdate_GetCipherKey_Callout(AESKey, &AESKeyLength) == E_OK )
  {
    /* #20 Initialize the decryption job if key is successfully initialized  */
    if( (esl_initWorkSpaceHeader(&(vHsmUpd_Ext_AESWorkspace.header), ESL_MAXSIZEOF_WS_AES128, (void(*)(void))0u) == ESL_ERC_NO_ERROR)
        && (esl_initDecryptAES128(&vHsmUpd_Ext_AESWorkspace, AESKey, ESL_BM_CBC, ESL_PM_OFF, vHsmUpd_IV) == ESL_ERC_NO_ERROR) ) /* PRQA S 3415 */ /* MD_vHsmUpd_Ext_OperatorOrder */
    {
      /* #30 Start decryption of the first AES block when decryption was set up successfully */
      if( vHsmUpd_Ext_DecryptFirstBlock() == E_OK)
      {
        retVal = E_OK;
      }
    }
  }
  return retVal;
}

/**********************************************************************************************************************
 *  vHsmUpd_Ext_VerifyUpdateImage()
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
FUNC(Std_ReturnType, VHSMUPD_EXT_CODE) vHsmUpd_Ext_VerifyUpdateImage(void)
{
  Std_ReturnType retVal = E_NOT_OK;

  /* #10 Check whether the CMAC generation was successful */
  if( vHsmUpd_Ext_GenerateMac(vHsmUpd_Ext_GetImageStartAddress(), vHsmUpd_Ext_GetSizeOfImage()) == E_NOT_OK )
  {
  }
  /* #20 Yes, add all additional data to the CMAC calculation */
  else if(vHsmUpd_Ext_CalculateHeaderInfoInMac() == E_NOT_OK)
  {
    /* Nothing to do on error */
  }
  else
  {
    eslt_Byte CMACresult[ESL_SIZEOF_AES128_BLOCK];
    uint8 cmacInUpdateHeader[ESL_SIZEOF_AES128_BLOCK];

    /* #30 Get the result from the CMAC verification */
    if( esl_finalizeCMACAES128(&vHsmUpd_Ext_MacWorkspace, CMACresult) == ESL_ERC_NO_ERROR )
    {
      /* #31 Than get the already calculated MAC */
      vHsmUpd_Ext_GetUpdateSignature(cmacInUpdateHeader);
      /* #32 Compare the calculated MAC with the given MAC */
      if( vHsmUpd_CompareBuffers(cmacInUpdateHeader, CMACresult, sizeof(CMACresult)) == TRUE )
      {
        retVal = E_OK;
      }
    }
  }

  return retVal;
}

/**********************************************************************************************************************
 *  vHsmUpd_Ext_CheckCurrentDecryptionPoint()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(Std_ReturnType, VHSMUPD_EXT_CODE) vHsmUpd_Ext_CheckCurrentDecryptionPoint(vHsmUpd_Ext_AddressType imageSourceAddress)
{
  Std_ReturnType retVal = E_OK;
  uint8 decryptBuffer[ESL_SIZEOF_AES128_BLOCK];
  if(vHsmUpd_Ext_UpdState.CurrentUpdateFwImageAddress <= imageSourceAddress)
  {
    /* Forward to the requested position */
    while((vHsmUpd_Ext_UpdState.CurrentUpdateFwImageAddress < imageSourceAddress) && (retVal == E_OK))
    {
      retVal = vHsmUpd_Ext_DecryptImageBlock(decryptBuffer, ESL_SIZEOF_AES128_BLOCK, vHsmUpd_Ext_UpdState.CurrentUpdateFwImageAddress);
      vHsmUpd_Ext_UpdState.CurrentUpdateFwImageAddress += ESL_SIZEOF_AES128_BLOCK;
    }
  }
  else
  {
    /* reset global image address to the beginning */
    vHsmUpd_Ext_UpdState.CurrentUpdateFwImageAddress = vHsmUpd_Ext_GetImageStartAddress();
    retVal = vHsmUpd_Ext_InitDecryption();
    if(retVal == E_OK)
    {
      /* Go through the whole image to the requested possition */
      do
      {
        retVal = vHsmUpd_Ext_DecryptImageBlock(decryptBuffer, ESL_SIZEOF_AES128_BLOCK, vHsmUpd_Ext_UpdState.CurrentUpdateFwImageAddress);
        vHsmUpd_Ext_UpdState.CurrentUpdateFwImageAddress += ESL_SIZEOF_AES128_BLOCK;
      }while((vHsmUpd_Ext_UpdState.CurrentUpdateFwImageAddress < imageSourceAddress) && (retVal == E_OK));
    }
  }

  /* Check if the addresses are equal */
  if(imageSourceAddress != vHsmUpd_Ext_UpdState.CurrentUpdateFwImageAddress)
  {
    retVal = E_NOT_OK;
  }

  return retVal;
}

#define VHSMUPD_EXT_STOP_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  END OF FILE: vHsmUpd_Ext_Crypto.c
 *********************************************************************************************************************/
