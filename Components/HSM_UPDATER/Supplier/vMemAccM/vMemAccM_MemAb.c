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
/*!        \file  vMemAccM_MemAb.c
 *        \brief  vMemAccM memory abstraction submodule source file
 *
 *      \details  See vMemAccM_MemAb.h.
 *
 *********************************************************************************************************************/

#define VMEMACCM_MEMAB_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "vMemAccM_IntCfg.h"
#include "vMemAccM_MemAb.h"

/**********************************************************************************************************************
 *  LOCAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
#if !defined (VMEMACCM_LOCAL_INLINE) /* COV_VMEMACCM_COMPATIBILITY */
# define VMEMACCM_LOCAL_INLINE LOCAL_INLINE
#endif

#define VMEMACCM_START_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#if (VMEMACCM_MULTI_PARTITION_SATELLITE == STD_OFF)

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  vMemAccM_MemAbCalcJobLength
 *********************************************************************************************************************/
/*!
 * \brief       Calculates the job length to be used for the vMem job depending on passed parameters.
 * \details     -
 * \param[in]   RequestedLength holding any value to be adjusted to a compatible job length (in bytes).
 * \param[in]   NormalSize holding the job length without burst, i.e. page or sector size (in bytes).
 * \param[in]   BurstSize holding the job burst length, i.e. page burst or sector burst size (in bytes).
 * \param[in]   UseBurst decides whether the burst size is relevant.
 * \return      Returns the calculated job length in bytes.
 * \pre         vMemAccM is not the satellite within a multi partition configuration.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */
VMEMACCM_LOCAL_INLINE FUNC(vMemAccM_LengthType, VMEMACCM_CODE) vMemAccM_MemAbCalcJobLength
(
  vMemAccM_LengthType RequestedLength,
  vMemAccM_LengthType NormalSize,
  vMemAccM_LengthType BurstSize,
  boolean UseBurst
);

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  vMemAccM_MemAbCalcJobLength
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
VMEMACCM_LOCAL_INLINE FUNC(vMemAccM_LengthType, VMEMACCM_CODE) vMemAccM_MemAbCalcJobLength
(
  vMemAccM_LengthType RequestedLength,
  vMemAccM_LengthType NormalSize,
  vMemAccM_LengthType BurstSize,
  boolean UseBurst
)
{
  /* In case the RequestedLength is not aligned, vMemAccM will forward the wrong length to vMem and the vMem will reject
   * the request because of alignment checks. vMemAccM does not take care about the alignment and also cannot
   * align the request! */
  vMemAccM_LengthType jobLength;
  /* #10 Burst enabled and the requested length > burst => use burst size. */
  if((UseBurst == TRUE) && (RequestedLength >= BurstSize))
  {
    jobLength = BurstSize;
  }
  /* #20 Burst disabled, requested length > normal size => use the normal size for the next request. */
  else if (RequestedLength >= NormalSize)
  {
    jobLength = NormalSize;
  }
  /* #13 Burst disabled, requested length < normal size => Use the requested length for the next request. */
  else
  {
    /* this shall never be reached - the requested length always has to be aligned to a page / sector size! */
    jobLength = RequestedLength;
  }

  return jobLength;
}

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  vMemAccM_MemAbWrite
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
FUNC(vMemAccM_LengthType, VMEMACCM_CODE) vMemAccM_MemAbWrite
(
  vMemAccM_AddressAreaIdType SubAddressAreaId,
  vMemAccM_AddressType Offset,
  vMemAccM_ConstDataPtrType DataPtr,
  vMemAccM_LengthType Length
)
{
  /* #100 Calculate required values (e.g. job length and physical address). */
  vMemAccM_LengthType burstSize = vMemAccM_GetPageBurstSizeOfSubAddressArea(SubAddressAreaId);
  vMemAccM_LengthType normalSize = vMemAccM_GetPageSizeOfSubAddressArea(SubAddressAreaId);
  vMemAccM_LengthType jobLength = vMemAccM_MemAbCalcJobLength(Length, normalSize, burstSize,
    (boolean)vMemAccM_IsUsePageBurstOfSubAddressArea(SubAddressAreaId));
  vMemAccM_AddressType address = vMemAccM_GetPhysicalStartAddressOfSubAddressArea(SubAddressAreaId) + Offset;
  /* #200 Forward the job to the vMem. */
  if(vMemAccM_GetvMemApiTableOfSubAddressArea(SubAddressAreaId)->
    Write(vMemAccM_GetvMemInstanceIdOfSubAddressArea(SubAddressAreaId), address, DataPtr, jobLength) == E_NOT_OK) /* SBSW_vMemAccM_vMemApi */
  {
    /* #210 vMem rejected a burst request -> retry. */
    if((jobLength == burstSize) && (vMemAccM_GetvMemApiTableOfSubAddressArea(SubAddressAreaId)->Write( /* PRQA S 3415 */ /* MD_vMemAccM_SideEffects */ /* SBSW_vMemAccM_vMemApi */
        vMemAccM_GetvMemInstanceIdOfSubAddressArea(SubAddressAreaId), address, DataPtr, normalSize) == E_OK))
    {
      /* #211 Retry with normal size worked, accepted number of bytes == normal size. */
      jobLength = normalSize;
    }
    else
    {
      /* #212 vMem rejected the request and the retry -> accepted number of bytes == 0. */
      jobLength = 0u;
    }
  }
  /* #300 Return the number of accepted bytes. */
  return jobLength;
}

/**********************************************************************************************************************
 *  vMemAccM_MemAbRead
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
FUNC(vMemAccM_LengthType, VMEMACCM_CODE) vMemAccM_MemAbRead
(
  vMemAccM_AddressAreaIdType SubAddressAreaId,
  vMemAccM_AddressType Offset,
  vMemAccM_DataPtrType DataPtr,
  vMemAccM_LengthType Length
)
{
  vMemAccM_LengthType processedNrOfBytes = Length;
  /* #10 Calculate the physical address. */
  vMemAccM_AddressType address = vMemAccM_GetPhysicalStartAddressOfSubAddressArea(SubAddressAreaId) + Offset;
  /* #20 Forward the job to vMem. */
  if(vMemAccM_GetvMemApiTableOfSubAddressArea(SubAddressAreaId)->
    Read(vMemAccM_GetvMemInstanceIdOfSubAddressArea(SubAddressAreaId), address, DataPtr, processedNrOfBytes) == E_NOT_OK) /* SBSW_vMemAccM_vMemApi */
  {
    /* #21 Job rejected == failed == 0 processed bytes. */
    processedNrOfBytes = 0u;
  }
  /* #30 Return the number of accepted bytes. */
  return processedNrOfBytes;
}

/**********************************************************************************************************************
 *  vMemAccM_MemAbErase
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
FUNC(vMemAccM_LengthType, VMEMACCM_CODE) vMemAccM_MemAbErase
(
  vMemAccM_AddressAreaIdType SubAddressAreaId,
  vMemAccM_AddressType Offset,
  vMemAccM_LengthType Length
)
{
  /* #100 Calculate required values (e.g. job length and physical address). */
  vMemAccM_LengthType burstSize = vMemAccM_GetSectorBurstSizeOfSubAddressArea(SubAddressAreaId);
  vMemAccM_LengthType normalSize = vMemAccM_GetSectorSizeOfSubAddressArea(SubAddressAreaId);
  vMemAccM_LengthType jobLength = vMemAccM_MemAbCalcJobLength(Length, normalSize, burstSize,
      (boolean)vMemAccM_IsUseSectorBurstOfSubAddressArea(SubAddressAreaId));
  vMemAccM_AddressType address = vMemAccM_GetPhysicalStartAddressOfSubAddressArea(SubAddressAreaId) + Offset;
  /* #200 Forward the job to the vMem. */
  if(vMemAccM_GetvMemApiTableOfSubAddressArea(SubAddressAreaId)->
    Erase(vMemAccM_GetvMemInstanceIdOfSubAddressArea(SubAddressAreaId), address, jobLength) == E_NOT_OK) /* SBSW_vMemAccM_vMemApi */
  {
    /* #210 vMem rejected a burst request -> retry. */
    if((jobLength == burstSize) && (vMemAccM_GetvMemApiTableOfSubAddressArea(SubAddressAreaId)-> /* PRQA S 3415 */ /* MD_vMemAccM_SideEffects */ /* SBSW_vMemAccM_vMemApi */
        Erase(vMemAccM_GetvMemInstanceIdOfSubAddressArea(SubAddressAreaId), address, normalSize) == E_OK))
    {
      /* #211 Retry with normal size worked, accepted number of bytes == normal size. */
      jobLength = normalSize;
    }
    else
    {
      /* #212 vMem rejected the request and the retry -> accepted number of bytes == 0. */
      jobLength = 0u;
    }
  }
  /* #300 Return the number of accepted bytes. */
  return jobLength;
}

/**********************************************************************************************************************
 *  vMemAccM_MemAbIsBlank
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(vMemAccM_LengthType, VMEMACCM_CODE) vMemAccM_MemAbIsBlank
(
  vMemAccM_AddressAreaIdType SubAddressAreaId,
  vMemAccM_AddressType Offset,
  vMemAccM_LengthType Length
)
{
  vMemAccM_LengthType jobLength = vMemAccM_MemAbCalcJobLength(Length,
    vMemAccM_GetPageSizeOfSubAddressArea(SubAddressAreaId), vMemAccM_GetPageSizeOfSubAddressArea(SubAddressAreaId), (boolean)FALSE);
  /* #10 Setup the vMem request and validate the return value: return the used vMem job length, if the vMem accepted
   * the request, otherwise return 0u. */
  if(vMemAccM_GetvMemApiTableOfSubAddressArea(SubAddressAreaId)->IsBlank( /* SBSW_vMemAccM_vMemApi */
    vMemAccM_GetvMemInstanceIdOfSubAddressArea(SubAddressAreaId),
    (vMemAccM_GetPhysicalStartAddressOfSubAddressArea(SubAddressAreaId) + Offset), jobLength) == E_NOT_OK)
  {
    jobLength = 0u;
  }

  return jobLength;
}

/**********************************************************************************************************************
 *  vMemAccM_MemAbHWSpecificReq
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(Std_ReturnType, VMEMACCM_CODE) vMemAccM_MemAbHWSpecificReq
(
  vMemAccM_AddressAreaIdType SubAddressAreaId,
  vMemAccM_vMemHwSpecificFuncIndexType vMemHwSpecificFuncIndex,
  vMemAccM_DataPtrType DataPtr,
  vMemAccM_LengthType DataSize
)
{
  /* #10 Forward the request to vMem and return the result. */
  return vMemAccM_GetvMemApiTableOfSubAddressArea(SubAddressAreaId)->HwFunctions.
    Table[vMemHwSpecificFuncIndex](vMemAccM_GetvMemInstanceIdOfSubAddressArea(SubAddressAreaId), DataPtr, DataSize); /* SBSW_vMemAccM_vMemApi */
}

/**********************************************************************************************************************
 *  vMemAccM_MemAbIsBusy
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(vMemAccM_JobResultType, VMEMACCM_CODE) vMemAccM_MemAbGetJobResult(vMemAccM_AddressAreaIdType SubAddressAreaId)
{
  vMemAccM_JobResultType retVal;
  switch(vMemAccM_GetvMemApiTableOfSubAddressArea(SubAddressAreaId)->
      GetJobResult(vMemAccM_GetvMemInstanceIdOfSubAddressArea(SubAddressAreaId))) /* SBSW_vMemAccM_vMemApi */
  {
    case VMEM_JOB_OK:
      retVal = VMEMACCM_JOB_OK;
      break;
    case VMEM_JOB_PENDING:
      retVal = VMEMACCM_JOB_PENDING;
      break;
    case VMEM_READ_CORRECTED_ERRORS:
      retVal = VMEMACCM_READ_CORRECTED_ERRORS;
      break;
    case VMEM_READ_UNCORRECTABLE_ERRORS:
      retVal = VMEMACCM_READ_UNCORRECTABLE_ERRORS;
      break;
    case VMEM_MEM_NOT_BLANK:
      retVal = VMEMACCM_MEM_NOT_BLANK;
      break;
    default:
      /* Something unknown returned or even really failed job. */
      retVal = VMEMACCM_JOB_FAILED;
      break;
    }

  return retVal;
}

#endif /* (VMEMACCM_MULTI_PARTITION_SATELLITE == STD_OFF) */

#define VMEMACCM_STOP_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  END OF FILE: vMemAccM_MemAb.c
 *********************************************************************************************************************/
