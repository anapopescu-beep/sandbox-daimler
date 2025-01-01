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
#include "vMemAccM_MemAb.h"


/**********************************************************************************************************************
 *  LOCAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
#if !defined (VMEMACCM_LOCAL) /* COV_VMEMACCM_COMPATIBILITY */
# define VMEMACCM_LOCAL static
#endif

#if !defined (VMEMACCM_LOCAL_INLINE) /* COV_VMEMACCM_COMPATIBILITY */
# define VMEMACCM_LOCAL_INLINE LOCAL_INLINE
#endif

#if (VMEMACCM_MULTI_PARTITION_SATELLITE == STD_OFF)
/**********************************************************************************************************************
 *  LOCAL DATA PROTOTYPES
 *********************************************************************************************************************/
# if (VMEMACCM_MINIMAL_SYNC == STD_OFF)
#define VMEMACCM_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */

/*! Table containing all alternate vMem function pointer tables. Size must be identical to the original table */
VMEMACCM_LOCAL VAR(vMemAccM_ConstvMemApiPtrType, VMEMACCM_VAR_ZERO_INIT) vMemAccM_AlternatevMemPointerTable[vMemAccM_GetSizeOfvMemPointerTable()];

#define VMEMACCM_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
# endif /* (VMEMACCM_MINIMAL_SYNC == STD_OFF) */

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
#define VMEMACCM_START_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

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
 *  vMemAccM_MemAbGetFunctionPointerTable
 *********************************************************************************************************************/
/*!
 * \brief       Returns the target FunctionPointerTable (vMem). 
 * \details     Default: FunctionPointerTable within configured, therefore generated vMemPointerTable.
 *              If alternate vMem was explicitly set: FunctionPointerTable within local vMemAccM_AlternatevMemPointerTable.
 * \param[in]   vMemIndex as array index, used to identify the target function pointer table.
 *              Must be in the range of [0,vMemAccM_GetSizeOfvMemPointerTable()-1].
 * \return      Correct target FunctionPointerTable.
 * \pre         vMemAccM is not the satellite within a multi partition configuration.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */
VMEMACCM_LOCAL_INLINE FUNC(vMemAccM_ConstvMemApiPtrType, VMEMACCM_CODE) vMemAccM_MemAbGetFunctionPointerTable
(
  vMemAccM_vMemPointerTableIterType vMemIndex
);

/**********************************************************************************************************************
 *  vMemAccM_MemAbGetJobResult
 *********************************************************************************************************************/
/*!
 * \brief       Returns the current vMem job result mapped to vMemAccM job result type.
 * \details     -
 * \param[in]   SubAddressAreaId as array index, used to access the physical information.
 * \return      Current vMem job result. Returns VMEMACCM_JOB_FAILED in case of an unknown vMem job result.
 * \pre         vMemAccM is not the satellite within a multi partition configuration.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */
VMEMACCM_LOCAL_INLINE FUNC(vMemAccM_JobResultType, VMEMACCM_CODE) vMemAccM_MemAbGetJobResult
(
  vMemAccM_AddressAreaIdType SubAddressAreaId
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
 *  vMemAccM_MemAbGetFunctionPointerTable
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
VMEMACCM_LOCAL_INLINE FUNC(vMemAccM_ConstvMemApiPtrType, VMEMACCM_CODE) vMemAccM_MemAbGetFunctionPointerTable
(
  vMemAccM_vMemPointerTableIterType vMemIndex
)
{
  vMemAccM_ConstvMemApiPtrType fctPtrTable;
# if (VMEMACCM_MINIMAL_SYNC == STD_OFF)
  if(vMemAccM_AlternatevMemPointerTable[vMemIndex] == NULL_PTR)
  {
    fctPtrTable = vMemAccM_GetvMemPointerTable(vMemIndex);
  }
  else
  {
    fctPtrTable = vMemAccM_AlternatevMemPointerTable[vMemIndex];
  }
# else
  fctPtrTable = vMemAccM_GetvMemPointerTable(vMemIndex);
# endif /* (VMEMACCM_MINIMAL_SYNC == STD_OFF) */

  return fctPtrTable;
}

/**********************************************************************************************************************
 *  vMemAccM_MemAbGetJobResult
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
VMEMACCM_LOCAL_INLINE FUNC(vMemAccM_JobResultType, VMEMACCM_CODE) vMemAccM_MemAbGetJobResult(vMemAccM_AddressAreaIdType SubAddressAreaId)
{
  vMemAccM_JobResultType retVal;
  switch(vMemAccM_MemAbGetFunctionPointerTable(vMemAccM_GetvMemTableIndexOfSubAddressArea(SubAddressAreaId))->
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
FUNC(void, VMEMACCM_CODE) vMemAccM_MemAbWrite
(
  vMemAccM_AddressAreaIdType SubAddressAreaId,
  vMemAccM_AddressType Offset,
  vMemAccM_ConstDataPtrType DataPtr,
  vMemAccM_LengthType Length,
  vMemAccM_LengthPtrType OutLength
)
{
  vMemAccM_LengthType burstSize = vMemAccM_GetPageBurstSizeOfSubAddressArea(SubAddressAreaId);
  vMemAccM_LengthType normalSize = vMemAccM_GetPageSizeOfSubAddressArea(SubAddressAreaId);
  vMemAccM_AddressType address = vMemAccM_GetPhysicalStartAddressOfSubAddressArea(SubAddressAreaId) + Offset;
  *OutLength = vMemAccM_MemAbCalcJobLength(Length, normalSize, burstSize, /* SBSW_vMemAccM_UserDataPointer */
    (boolean)vMemAccM_IsUsePageBurstOfSubAddressArea(SubAddressAreaId));
  if(vMemAccM_MemAbGetFunctionPointerTable(vMemAccM_GetvMemTableIndexOfSubAddressArea(SubAddressAreaId))->
    Write(vMemAccM_GetvMemInstanceIdOfSubAddressArea(SubAddressAreaId), address, DataPtr, *OutLength) == E_NOT_OK) /* SBSW_vMemAccM_vMemApi */
  {
    if((*OutLength == burstSize) && (vMemAccM_MemAbGetFunctionPointerTable(vMemAccM_GetvMemTableIndexOfSubAddressArea(SubAddressAreaId))->Write( /* PRQA S 3415 */ /* MD_vMemAccM_SideEffects */ /* SBSW_vMemAccM_vMemApi */
        vMemAccM_GetvMemInstanceIdOfSubAddressArea(SubAddressAreaId), address, DataPtr, normalSize) == E_OK))
    {
      *OutLength = normalSize; /* SBSW_vMemAccM_UserDataPointer */
    }
    else
    {
      *OutLength = 0u; /* SBSW_vMemAccM_UserDataPointer */
    }
  }
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
FUNC(void, VMEMACCM_CODE) vMemAccM_MemAbRead
(
  vMemAccM_AddressAreaIdType SubAddressAreaId,
  vMemAccM_AddressType Offset,
  vMemAccM_DataPtrType DataPtr,
  vMemAccM_LengthType Length,
  vMemAccM_LengthPtrType OutLength,
  vMemAccM_LengthType AlignmentSize
)
{
  vMemAccM_AddressType address = vMemAccM_GetPhysicalStartAddressOfSubAddressArea(SubAddressAreaId) + Offset;

  *OutLength = vMemAccM_MemAbCalcJobLength(Length, /* SBSW_vMemAccM_UserDataPointer */
    AlignmentSize, 
    AlignmentSize, 
    (boolean)FALSE);

  if(vMemAccM_MemAbGetFunctionPointerTable(vMemAccM_GetvMemTableIndexOfSubAddressArea(SubAddressAreaId))->Read(
    vMemAccM_GetvMemInstanceIdOfSubAddressArea(SubAddressAreaId), address, DataPtr, *OutLength) == E_NOT_OK) /* SBSW_vMemAccM_vMemApi */
  {
    *OutLength = 0u; /* SBSW_vMemAccM_UserDataPointer */
  }
} /* PRQA S 6060 */ /* MD_MSR_STPAR */

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
FUNC(void, VMEMACCM_CODE) vMemAccM_MemAbErase
(
  vMemAccM_AddressAreaIdType SubAddressAreaId,
  vMemAccM_AddressType Offset,
  vMemAccM_LengthType Length,
  vMemAccM_LengthPtrType OutLength
)
{
  vMemAccM_LengthType burstSize = vMemAccM_GetSectorBurstSizeOfSubAddressArea(SubAddressAreaId);
  vMemAccM_LengthType normalSize = vMemAccM_GetSectorSizeOfSubAddressArea(SubAddressAreaId);
  vMemAccM_AddressType address = vMemAccM_GetPhysicalStartAddressOfSubAddressArea(SubAddressAreaId) + Offset;
  *OutLength = vMemAccM_MemAbCalcJobLength(Length, normalSize, burstSize, /* SBSW_vMemAccM_UserDataPointer */
      (boolean)vMemAccM_IsUseSectorBurstOfSubAddressArea(SubAddressAreaId));
  if(vMemAccM_MemAbGetFunctionPointerTable(vMemAccM_GetvMemTableIndexOfSubAddressArea(SubAddressAreaId))->
    Erase(vMemAccM_GetvMemInstanceIdOfSubAddressArea(SubAddressAreaId), address, *OutLength) == E_NOT_OK) /* SBSW_vMemAccM_vMemApi */
  {
    if((*OutLength == burstSize) && (vMemAccM_MemAbGetFunctionPointerTable(vMemAccM_GetvMemTableIndexOfSubAddressArea(SubAddressAreaId))-> /* PRQA S 3415 */ /* MD_vMemAccM_SideEffects */ /* SBSW_vMemAccM_vMemApi */
        Erase(vMemAccM_GetvMemInstanceIdOfSubAddressArea(SubAddressAreaId), address, normalSize) == E_OK))
    {
      *OutLength = normalSize; /* SBSW_vMemAccM_UserDataPointer */
    }
    else
    {
      *OutLength = 0u; /* SBSW_vMemAccM_UserDataPointer */
    }
  }
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
FUNC(void, VMEMACCM_CODE) vMemAccM_MemAbIsBlank
(
  vMemAccM_AddressAreaIdType SubAddressAreaId,
  vMemAccM_AddressType Offset,
  vMemAccM_LengthType Length,
  vMemAccM_LengthPtrType OutLength
)
{
  *OutLength = vMemAccM_MemAbCalcJobLength(Length, /* SBSW_vMemAccM_UserDataPointer */
    vMemAccM_GetPageSizeOfSubAddressArea(SubAddressAreaId), vMemAccM_GetPageSizeOfSubAddressArea(SubAddressAreaId), (boolean)FALSE);
  if(vMemAccM_MemAbGetFunctionPointerTable(vMemAccM_GetvMemTableIndexOfSubAddressArea(SubAddressAreaId))->IsBlank( /* SBSW_vMemAccM_vMemApi */
    vMemAccM_GetvMemInstanceIdOfSubAddressArea(SubAddressAreaId),
    (vMemAccM_GetPhysicalStartAddressOfSubAddressArea(SubAddressAreaId) + Offset), (*OutLength)) == E_NOT_OK)
  {
    *OutLength = 0u; /* SBSW_vMemAccM_UserDataPointer */
  }
}

#if (VMEMACCM_MINIMAL_SYNC == STD_OFF)
/**********************************************************************************************************************
 *  vMemAccM_MemAbHWSpecificReq
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(Std_ReturnType, VMEMACCM_CODE) vMemAccM_MemAbHWSpecificReq
(
  vMemAccM_AddressAreaIdType SubAddressAreaId,
  vMemAccM_vMemHwSpecificFuncIndexType vMemHwSpecificFuncIndex,
  vMemAccM_DataPtrType DataPtr,
  vMemAccM_LengthType DataSize,
  vMemAccM_LengthPtrType OutLength
)
{
  Std_ReturnType retVal;
  *OutLength = DataSize; /* SBSW_vMemAccM_UserDataPointer */
  retVal = vMemAccM_MemAbGetFunctionPointerTable(vMemAccM_GetvMemTableIndexOfSubAddressArea(SubAddressAreaId))->HwFunctions.
     Table[vMemHwSpecificFuncIndex](vMemAccM_GetvMemInstanceIdOfSubAddressArea(SubAddressAreaId), DataPtr, (*OutLength)); /* SBSW_vMemAccM_UserDataPointer */
  if(retVal == E_NOT_OK)
  {
      *OutLength = 0u; /* SBSW_vMemAccM_UserDataPointer */
  }
  return retVal;
}
#endif /* (VMEMACCM_MINIMAL_SYNC == STD_OFF) */

/**********************************************************************************************************************
 *  vMemAccM_MemAbProcessing
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(vMemAccM_JobResultType, VMEMACCM_CODE) vMemAccM_MemAbProcessing
(
  vMemAccM_AddressAreaIdType SubAddressAreaId
)
{
  vMemAccM_JobResultType jobResult = vMemAccM_MemAbGetJobResult(SubAddressAreaId); 
  
  /* Even if job is cancelled in between, vMem Job needs to be triggered till it is not PENDING anymore */
  if(jobResult == VMEMACCM_JOB_PENDING)
  {
    vMemAccM_MemAbGetFunctionPointerTable(vMemAccM_GetvMemTableIndexOfSubAddressArea(SubAddressAreaId))->MainFunction(); /* SBSW_vMemAccM_vMemApi */
    jobResult = vMemAccM_MemAbGetJobResult(SubAddressAreaId);
  }

  return jobResult;
}

/**********************************************************************************************************************
 *  vMemAccM_MemAbInit 
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, VMEMACCM_CODE) vMemAccM_MemAbInit 
(
  vMemAccM_vMemPointerTableIterType vMemIndex
)
{
  /* NULL_PTR as vMem(s) are not post build capable */
  vMemAccM_MemAbGetFunctionPointerTable(vMemIndex)->Init(NULL_PTR); /* SBSW_vMemAccM_vMemApi */
}

#if (VMEMACCM_MINIMAL_SYNC == STD_OFF)
/**********************************************************************************************************************
 *  vMemAccM_MemAbResetAlternatevMemPtrTable
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, VMEMACCM_CODE) vMemAccM_MemAbResetAlternatevMemPtrTable
(
  vMemAccM_vMemPointerTableIterType vMemIndex
)
{
  vMemAccM_AlternatevMemPointerTable[vMemIndex] = NULL_PTR; /* SBSW_vMemAccM_AlternatevMemPointerTable */
}

/**********************************************************************************************************************
 *  vMemAccM_MemAbSetAlternatevMemPtrTable
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, VMEMACCM_CODE) vMemAccM_MemAbSetAlternatevMemPtrTable
(
  vMemAccM_vMemPointerTableIterType vMemIndex,
  vMemAccM_ConstvMemApiPtrType  vMemFunctionPointerTable
)
{
  vMemAccM_AlternatevMemPointerTable[vMemIndex] = vMemFunctionPointerTable; /* SBSW_vMemAccM_AlternatevMemPointerTable */
}
#endif /* (VMEMACCM_MINIMAL_SYNC == STD_OFF) */

#define VMEMACCM_STOP_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#endif /* (VMEMACCM_MULTI_PARTITION_SATELLITE == STD_OFF) */

/**********************************************************************************************************************
 *  END OF FILE: vMemAccM_MemAb.c
 *********************************************************************************************************************/
