#define VHSMUPD_CALLOUT_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "vHsmUpd.h"
#include "vHsmUpd_Cfg.h"
#include "vHsmUpd_Hal.h"
#include "vHsmUpd_Ext_Callout.h"
#include "vMemAccM.h"
#include "vHsmUpd_MemAb.h"
#include "vMem_30_Tc3xxInf01_Extended_Func.h"

/**********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 *********************************************************************************************************************/
#define VHSMUPD_VMEM   (0u)
#define VHSMUPD_HAL    (1u)

/* Define flash access method for Reads on HSM and HOST */
#define VHSMUPD_ACCESS_READ_HSM   VHSMUPD_VMEM
#define VHSMUPD_ACCESS_READ_HOST  VHSMUPD_HAL

/* Define flash access method for Blank checks on HSM and HOST */
#define VHSMUPD_ACCESS_BLANK_HSM  VHSMUPD_VMEM
#define VHSMUPD_ACCESS_BLANK_HOST VHSMUPD_HAL

/* activate TC3 specific code */
#define BRS_DERIVATIVE_TC3xx

#ifndef VMEM_30_TC3XXINF01_ACTIVE_ADDRESS_REGION
  #define VMEM_30_TC3XXINF01_ACTIVE_ADDRESS_REGION 0u
#endif

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

#define VHSMUPD_START_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  vHsmUpd_Read_Callout()
 *********************************************************************************************************************/
FUNC(Std_ReturnType, VHSMUPD_CODE) vHsmUpd_Read_Callout(
  vHsmUpd_MemoryAreaIdType areaId,
  vHsmUpd_DataPtrType buffer,
  vHsmUpd_LengthType length,
  vHsmUpd_AddressType address,
  vHsmUpd_TargetCoreType target)
{
  Std_ReturnType retVal = E_NOT_OK;

  if(target == TARGET_HSM)
  {
    #if (VHSMUPD_ACCESS_READ_HSM == VHSMUPD_VMEM)
      /* Use vAccessManager and vMem driver to read data */
      retVal = vHsmUpd_ReadData(areaId, buffer, length, address);
    #else
      /* Use direct pointers to read data */
      vHsmUpd_MemRead(buffer, length, address);
      retVal = E_OK;
    #endif
  }
  else if(target == TARGET_HOST)
  {
    #if (VHSMUPD_ACCESS_READ_HOST == VHSMUPD_VMEM)
      /* Use vAccessManager and vMem driver to read flash memory */
      retVal = vHsmUpd_ReadData(areaId, buffer, length, address);
    #else
      /* Use direct pointers to read data */
      vHsmUpd_MemRead(buffer, length, address);
      retVal = E_OK;
    #endif
  }
  else
  {
    /* Misra compliant */
  }
  

  return retVal;
}

/**********************************************************************************************************************
 *  vHsmUpd_IsBlank_Callout()
 *********************************************************************************************************************/
FUNC(Std_ReturnType, VHSMUPD_CODE) vHsmUpd_IsBlank_Callout(
  vHsmUpd_MemoryAreaIdType areaId,
  vHsmUpd_LengthType length,
  vHsmUpd_AddressType address,
  vHsmUpdBooleanResultPtrType blank,
  vHsmUpd_TargetCoreType target)
{
  Std_ReturnType retVal = E_OK;

  if(target == TARGET_HSM)
  {
    #if (VHSMUPD_ACCESS_BLANK_HSM == VHSMUPD_VMEM)
      /* Use vAccessManager and vMem driver to perform blank check */
      /* May not be implemented on all platforms */
      retVal = vHsmUpd_IsBlank(areaId, length, address, blank);
    #else
      /* If blank check is not implemented by vMem and the vHsmUpd_Hal module is available for your derivative you can use vHsmUpd_Hal_IsBlank */
      *blank = vHsmUpd_Hal_IsBlank((uint32)address);
    #endif
  }
  else if(target == TARGET_HOST)
  {
    #if (VHSMUPD_ACCESS_BLANK_HOST == VHSMUPD_VMEM)
      /* Use vAccessManager and vMem driver to perform blank check */
      /* May not be supported on all platforms */
      retVal = vHsmUpd_IsBlank(areaId, length, address, blank);
    #else
      /* If blank check is not implemented by vMem and the vHsmUpd_Hal module is available for your derivative you can use vHsmUpd_Hal_IsBlank */
      *blank = vHsmUpd_Hal_IsBlank((uint32)address);
    #endif
  }
  else
  {
    /* Misra compliant */
  }
  

  return retVal;
}

/**********************************************************************************************************************
 *  vHsmUpd_IsSwapped_Callout()
 *********************************************************************************************************************/
FUNC(Std_ReturnType, VHSMUPD_CODE) vHsmUpd_IsSwapped_Callout(vHsmUpdBooleanResultPtrType isSwapped)
{
  Std_ReturnType retVal = E_NOT_OK;

#if defined (BRS_DERIVATIVE_TC3xx) /* TC3 specific */
  vMem_30_Tc3xxInf01_AddressRegionType isSwappedResult;

  /* Setup asynchronous vMemAccM job */
  retVal = vMemAccM_MemAbHWSpecificReq(0u, 0u, VMEM_30_TC3XXINF01_ACTIVE_ADDRESS_REGION, (vMemAccM_DataPtrType)(&isSwappedResult), sizeof(vMem_30_Tc3xxInf01_AddressRegionType));

  if(retVal == E_OK)
  {
    /* Wait for the processing of the IsBlank job */
    vHsmUpd_vMemDriver_Processing(VMEM_30_TC3XXINF01_ACTIVE_ADDRESS_REGION);

    /* Check if the result of the vMemAccM_IsBlank job was successfull */
    if (vMemAccM_GetJobResult(0u) == VMEMACCM_JOB_OK)
    {
      *isSwapped = (isSwappedResult == VMEM_30_TC3XXINF01_ADDRESS_REGION_B);
    }
    else
    {
      retVal = E_NOT_OK;
    }
  }
#else
VHSMUPD_DUMMY_STATEMENT(isSwapped);
#endif

  return retVal;
}

/**********************************************************************************************************************
 *  vHsmUpd_TriggerSoftwareReset_Callout()
 *********************************************************************************************************************/
FUNC(void, VHSMUPD_EXT_CODE) vHsmUpd_TriggerSoftwareReset_Callout(void)
{
#ifdef VHSMUPD_HAL_ENABLE_RESET
  /* In some cases the vHsmUpd_Hal provides a implementation of the software reset function */
  vHsmUpd_Hal_TriggerSoftwareReset();
#endif
  /* If the trigger software reset is not provided by the vHsmUpd_Hal, it can be implemented here. */

}

const uint8 key[] = {0x00u, 0x01u, 0x02u, 0x03u, 0x04u, 0x05u, 0x06u, 0x07u, 0x08u, 0x09u, 0x0Au, 0x0Bu, 0x0Cu, 0x0Du, 0x0Eu, 0x0Fu};



FUNC(Std_ReturnType, VHSMUPD_CODE) vHsm_FirmwareUpdate_GetMacKey_Callout(vHsmUpd_DataPtrType keyPtr, vHsmUpd_LengthPtrType length)
{
  uint8 i;
  for(i=0u; i < *length; i++)
  {
    keyPtr[i] = key[i];
  }

  return E_OK;
}
	
		
FUNC(Std_ReturnType, VHSMUPD_CODE) vHsm_FirmwareUpdate_GetCipherKey_Callout(vHsmUpd_DataPtrType keyPtr, vHsmUpd_LengthPtrType length)
{
  uint8 i;
  for(i=0u; i < *length; i++)
  {
    keyPtr[i] = key[i];
  }

  return E_OK;
}
	
//#include "vMemAccM.h"
//#include "vHsmUpd_MemAb.h"
//#include "vHsmUpd_Callout.h"
//#include "vHsmUpd_Ipc.h"

FUNC(void, VHSMUPD_EXT_CODE) vHsm_FirmwareUpdate_Error_Callout(const vHsmUpd_Ext_ErrorType error)
{
  while (1);
}


#define VHSMUPD_STOP_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
