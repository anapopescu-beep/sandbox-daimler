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
/*!        \file  vHsmUpd_MemAb.c
 *        \brief  vHsmUpd_MemAb source file
 *
 *      \details  see vHsmUpd_MemAb.h
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 *********************************************************************************************************************/

#define VHSMUPD_MEMAB_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "vMemAccM.h"
#include "vHsmUpd_MemAb.h"
#include "vHsmUpd_Ext.h"
#include "vHsmUpd_Cfg.h"
#include "vHsmUpd.h"

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
#if !defined (VHSMUPD_LOCAL) /* COV_VHSMUPD_COMPATIBILITY */
# define VHSMUPD_LOCAL static
#endif

#if !defined (VHSMUPD_LOCAL_INLINE) /* COV_VHSMUPD_COMPATIBILITY */
# define VHSMUPD_LOCAL_INLINE LOCAL_INLINE
#endif

/**********************************************************************************************************************
 *  LOCAL DATA PROTOTYPES
 *********************************************************************************************************************/

#define VHSMUPD_START_SEC_CONST_8BIT
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
/* PRQA S 1514, 3218 1 */ /* MD_vHsmUpd_ConstConfigData */
VHSMUPD_LOCAL CONST(uint8, VHSMUPD_CONST) vHsmUpd_ppValue[VHSMUPD_SIZE_OF_PP] = { /*!< Value of the presence pattern for the vHsm firmware and update header */
    0x73u, 0x6Au, 0x25u, 0x3Eu
};

#define VHSMUPD_STOP_SEC_CONST_8BIT
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/

#define VHSMUPD_START_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  vHsmUpd_CompareBuffers()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(boolean, VHSMUPD_CODE) vHsmUpd_CompareBuffers(
  vHsmUpd_ConstDataPtrType ptr1,
  vHsmUpd_ConstDataPtrType ptr2,
  uint32 length)
{
  uint32_least i;
  volatile boolean isEqual = TRUE;
  volatile boolean isEqualDummy = TRUE;

  /* #10 Securely compare memory */
  for (i = 0u; i < length; ++i)
  {
    if ((ptr1[i] != ptr2[i]))
    {
      isEqual = FALSE;
    }
    else
    {
      isEqualDummy = FALSE;
    }
  }

  VHSMUPD_DUMMY_STATEMENT(isEqualDummy); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  return isEqual;
}

/**********************************************************************************************************************
 *  vHsmUpd_ReadPresencePattern()
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
FUNC(Std_ReturnType, VHSMUPD_CODE) vHsmUpd_ReadPresencePattern(
  vHsmUpd_MemoryAreaIdType  addressAreaId,
  vHsmUpd_AddressType       ppAddress,
  vHsmUpd_TargetCoreType    target)
{
  Std_ReturnType retVal = E_NOT_OK;
  uint8 readBuffer[VHSMUPD_SIZE_OF_PP] = {0u};
  uint32 readAddress = ppAddress;
  boolean isBlank;

  /* The state of the pp is unknown at this time. Assume erased memory here. */
  /* #10 Check if the first part of the pp is erased */
  if( vHsmUpd_IsBlank_Callout(addressAreaId, VHSMUPD_PLATFORM_PAGESIZE, readAddress, &isBlank, target) == E_OK )
  {
    if(isBlank == FALSE)
    {
      /* #11 When not erased, read first page of presence pattern */
      (void)vHsmUpd_Read_Callout(addressAreaId, readBuffer, VHSMUPD_SIZE_OF_PP, readAddress, target);

      /* #12 Compare the read values with the presence pattern values
            and Check whether both values matched */
      if(vHsmUpd_CompareBuffers(readBuffer, vHsmUpd_ppValue, sizeof(vHsmUpd_ppValue)) == TRUE)
      {
        readAddress += VHSMUPD_PLATFORM_PAGESIZE;

        /* #121 The presence pattern value was correct, so check for erased value */
        if( vHsmUpd_IsBlank_Callout(addressAreaId, VHSMUPD_PLATFORM_PAGESIZE, readAddress, &isBlank, target) == E_OK )
        {
          /* #1211 Set result to E_OK if the second flash page was erased, data is valid */
          retVal = ((isBlank == TRUE) ? E_OK : E_NOT_OK);
        }
      }
    }
  }
  return retVal;
}

/**********************************************************************************************************************
 *  vHsmUpd_MemRead()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, VHSMUPD_CODE) vHsmUpd_MemRead(
  vHsmUpd_DataPtrType readBuffer,
  vHsmUpd_LengthType  readLength,
  vHsmUpd_AddressType readAddress)
{
  vHsmUpd_LengthType currLenProc;

  /* #10 Perform a memory mapped read and save it to the given buffer */
  for(currLenProc = 0u; currLenProc < readLength; currLenProc++)
  {
    readBuffer[currLenProc] = ((vHsmUpd_DataPtrType)readAddress)[currLenProc]; /* PRQA S 0306 */ /* MD_vHsmUpd_MemoryAccess */
  }
}

/**********************************************************************************************************************
 *  vHsmUpd_WriteData()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
FUNC(Std_ReturnType, VHSMUPD_CODE) vHsmUpd_WriteData(
  vHsmUpd_MemoryAreaIdType  addressAreaId,
  vHsmUpd_ConstDataPtrType  writeBuffer,
  vHsmUpd_LengthType        length,
  vHsmUpd_AddressType       address)
{
  Std_ReturnType retVal = E_NOT_OK;

  /* #10 Write the given buffer to the flash */
  if( vMemAccM_Write((vMemAccM_AddressAreaIdType)(addressAreaId), (vMemAccM_AddressType)(address), (vMemAccM_ConstDataPtrType)(writeBuffer), (vMemAccM_LengthType)(length) ) == E_OK ) /* PRQA S 0315, 0314 */ /* MD_vHsmUpd_vMemAccMInteraction */
  {
    /* #11 Trigger all vMemDriver to execute the current request
     * and check for result of the latest job */
    vHsmUpd_vMemDriver_Processing(addressAreaId);
    if(vMemAccM_GetJobResult((vMemAccM_AddressAreaIdType)(addressAreaId)) == VMEMACCM_JOB_OK)
    {
      /* #111 Data written successfully, set return value to E_OK and return */
      retVal = E_OK;
    }
  }
  return retVal;
}

/**********************************************************************************************************************
 *  vHsmUpd_EraseData()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
FUNC(Std_ReturnType, VHSMUPD_CODE) vHsmUpd_EraseData(
  vHsmUpd_MemoryAreaIdType  addressAreaId,
  vHsmUpd_LengthType        length,
  vHsmUpd_AddressType       address)
{
  Std_ReturnType retVal = E_NOT_OK;
  /* #10 Erase the area defined by the address and length */
  if( vMemAccM_Erase((vMemAccM_AddressAreaIdType)(addressAreaId), (vMemAccM_AddressType)(address), (vMemAccM_LengthType)(length))
      == E_OK)
  {
    /* #11 Trigger all vMemDriver to execute the current request
     * and check for result of the latest job */
    vHsmUpd_vMemDriver_Processing(addressAreaId);
    if(vMemAccM_GetJobResult((vMemAccM_AddressAreaIdType)(addressAreaId)) == VMEMACCM_JOB_OK)
    {
      /* #111 Data erased successfully, set return value to E_OK and return */
      retVal = E_OK;
    }
  }
  return retVal;
}

/**********************************************************************************************************************
 *  vHsmUpd_ReadData()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
FUNC(Std_ReturnType, VHSMUPD_CODE) vHsmUpd_ReadData(
  vHsmUpd_MemoryAreaIdType  addressAreaId,
  vHsmUpd_DataPtrType       readBuffer,
  vHsmUpd_LengthType        length,
  vHsmUpd_AddressType       address)
{
  Std_ReturnType retVal = E_NOT_OK;
  /* #10 Read the area defined by the address and length to the buffer */
  if( vMemAccM_Read((vMemAccM_AddressAreaIdType)(addressAreaId), (vMemAccM_AddressType)(address),(vMemAccM_DataPtrType)(readBuffer), (vMemAccM_LengthType)(length))
      == E_OK)
  {
    /* #11 Trigger all vMemDriver to execute the current request
     * and check for result of the latest job */
    vHsmUpd_vMemDriver_Processing(addressAreaId);
    if(vMemAccM_GetJobResult((vMemAccM_AddressAreaIdType)(addressAreaId)) == VMEMACCM_JOB_OK)
    {
      /* #111 Data read successfully, set return value to E_OK and return */
      retVal = E_OK;
    }
  }
  return retVal;
}

/**********************************************************************************************************************
 *  vHsmUpd_IsBlank()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(Std_ReturnType, VHSMUPD_CODE) vHsmUpd_IsBlank(
  vHsmUpd_MemoryAreaIdType        addressAreaId,
  vHsmUpd_LengthType              length,
  vHsmUpd_AddressType             address,
  vHsmUpdBooleanResultPtrType     isBlank)
{
  Std_ReturnType retVal = E_NOT_OK;

  /* Setup asynchronous vMemAccM job */
  if(vMemAccM_IsBlank((vMemAccM_AddressAreaIdType)addressAreaId, address, length) == E_OK)
  {
    /* Wait for the processing of the IsBlank job */
    vHsmUpd_vMemDriver_Processing(addressAreaId);

    /* Check if the result of the vMemAccM_IsBlank job was successfull */
    if (vMemAccM_GetJobResult((vMemAccM_AddressAreaIdType)addressAreaId) == VMEMACCM_JOB_OK)
    {
      *isBlank = TRUE;
      retVal = E_OK;
    }
    else if (vMemAccM_GetJobResult((vMemAccM_AddressAreaIdType)addressAreaId) == VMEMACCM_MEM_NOT_BLANK)
    {
      *isBlank = FALSE;
      retVal = E_OK;
    }
    else
    {
      /* Misra compliant */
    }

  }
  return retVal;
}

/**********************************************************************************************************************
 *  vHsmUpd_InitializeMemDriver()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(void, VHSMUPD_CODE) vHsmUpd_InitializeMemDriver(void)
{
  /* #10 Initialize memory driver parts */
  vHsmUpd_vMemDriver_Init();
}

/**********************************************************************************************************************
 *  vHsmUpd_BigEndianByteArrayToUint32()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(uint32, VHSMUPD_CODE) vHsmUpd_BigEndianByteArrayToUint32(
  vHsmUpd_ConstDataPtrType array)
{
  return (uint32)(((uint32)array[0u] << 24u) | ((uint32)array[1u] << 16u) | ((uint32)array[2u] << 8u) | ((uint32)array[3u]));
}

/**********************************************************************************************************************
 *  vHsmUpd_BigEndianByteArrayToUint16()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(uint16, VHSMUPD_CODE) vHsmUpd_BigEndianByteArrayToUint16(
  vHsmUpd_ConstDataPtrType array)
{
  return (uint16)(((uint32)array[0u] << 8u) | ((uint32)array[1u]));
}

/**********************************************************************************************************************
 * vHsmUpd_vMemDriver_Init
 *********************************************************************************************************************/
/*!
 * \fn vHsmUpd_vMemDriver_Init
 * Internal comment removed.
 *
 *
 *
 */

/**********************************************************************************************************************
 * vHsmUpd_vMemDriver_Processing
 *********************************************************************************************************************/
/*!
 * \fn vHsmUpd_vMemDriver_Processing
 * Internal comment removed.
 *
 *
 *
 */

#define VHSMUPD_STOP_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  END OF FILE: vHsmUpd_MemAb.c
 *********************************************************************************************************************/
