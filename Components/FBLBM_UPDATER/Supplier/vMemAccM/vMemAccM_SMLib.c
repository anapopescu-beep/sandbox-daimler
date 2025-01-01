/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2022 by Vector Informatik GmbH.                                                  All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/*!        \file  vMemAccM_SMLib.c
 *        \brief  vMemAccM state machine library source file.
 *
 *      \details  See vMemAccM_SMLib.h.
 *         \unit  vMemAccM_SMLib
 *
 *********************************************************************************************************************/

#define VMEMACCM_SMLIB_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "vMemAccM_SMLib.h"


/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/
#define VMEMACCM_START_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  vMemAccM_SMLibCalcJobParams
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(void, VMEMACCM_CODE) vMemAccM_SMLibCalcJobParams
(
    vMemAccM_SubAddrAreaJobParamsPtrType JobParamsPtr,
    vMemAccM_AddressAreaIdType SubAddrAreaId,
    vMemAccM_AddressType Address,
    vMemAccM_LengthType Length,
    vMemAccM_AddressType Offset
)
{
  /* #10 Calculate the offset within the sub address area (= virtual job start address - virtual sub address are start address). */
  vMemAccM_AddressType virtualJobStepStartAddress = (Address + Offset);
  vMemAccM_LengthType subAddrAreaOffset = (virtualJobStepStartAddress - vMemAccM_GetVirtualStartAddressOfSubAddressArea(SubAddrAreaId));
  /* #20 Get the maximum job step length (remaining length in sub address area or even the remaining job length). */
  /* So many bytes still can be written into the sub address area. */
  vMemAccM_LengthType subAddrAreaRemainingLength = (vMemAccM_GetVirtualEndAddressOfSubAddressArea(SubAddrAreaId)
      - vMemAccM_GetVirtualStartAddressOfSubAddressArea(SubAddrAreaId)) - subAddrAreaOffset + 1u;
  /* So many bytes have to be written until the job is done. */
  vMemAccM_LengthType jobRemainingLength = Length - Offset;
  /* Calculate the job length to forward to MemAb. */
  JobParamsPtr->Length = (jobRemainingLength > subAddrAreaRemainingLength) ? subAddrAreaRemainingLength : jobRemainingLength; /* SBSW_vMemAccM_JobParams */
  /* Store the offset value in job. */
  JobParamsPtr->Offset = subAddrAreaOffset; /* SBSW_vMemAccM_JobParams */
}


/**********************************************************************************************************************
 *  vMemAccM_SMLibCalcJobPointer
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(void, VMEMACCM_CODE) vMemAccM_SMLibCalcJobPointer
(
  vMemAccM_SubAddrAreaJobParamsPtrType JobParamsPtr,
  vMemAccM_DataPtrType DataPtr,
  vMemAccM_AddressType Offset 
)
{
  /* PRQA S 0315, 0316 1 */ /* MD_vMemAccM_VoidPtrTypedPtr */
  JobParamsPtr->DataPtr = &(((vMemAccM_Uint8PtrType)DataPtr)[Offset]); /* SBSW_vMemAccM_JobParams */
}

#define VMEMACCM_STOP_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  END OF FILE: vMemAccM_SMLib.c
 *********************************************************************************************************************/
