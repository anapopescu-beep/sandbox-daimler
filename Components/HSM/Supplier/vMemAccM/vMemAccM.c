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
/*!        \file  vMemAccM.c
 *        \brief  vMemAccM source file
 *
 *      \details  See vMemAccM.h.
 *
 *********************************************************************************************************************/

#define VMEMACCM_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

#include "vMemAccM.h"
#include "vMemAccM_IntCfg.h"

#if (VMEMACCM_MINIMAL_SYNC == STD_ON)
# include "vMemAccM_SchedSync.h"
#else
# include "vMemAccM_Sched.h"
#endif /* VMEMACCM_MINIMAL_SYNC == STD_ON */


#include "vMemAccM_CfgAb.h"
#include "vMemAccM_MemAb.h"
#include "vMemAccM_ErrorNotification.h"
#include "SchM_vMemAccM.h"

#if (VMEMACCM_DEV_ERROR_REPORT == STD_ON)
# include "Det.h"
#endif

/**********************************************************************************************************************
 *  VERSION CHECK
 *********************************************************************************************************************/
#if (  (VMEMACCM_SW_MAJOR_VERSION != (7u)) \
    || (VMEMACCM_SW_MINOR_VERSION != (2u)) \
    || (VMEMACCM_SW_PATCH_VERSION != (0u)) )
# error "Vendor specific version numbers of vMemAccM.c and vMemAccM.h are inconsistent"
#endif

#if (  (VMEMACCM_CFG_MAJOR_VERSION != (5u)) \
    || (VMEMACCM_CFG_MINOR_VERSION != (2u)) )
# error "Vendor specific version numbers of vMemAccM.c and vMemAccM_Cfg.h are inconsistent!"
#endif

/**********************************************************************************************************************
 *  LOCAL DATA TYPES AND STRUCTURES
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
# if (VMEMACCM_MINIMAL_SYNC == STD_OFF)
#define VMEMACCM_START_SEC_VAR_ZERO_INIT_8BIT
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

VMEMACCM_LOCAL VAR(boolean, VMEMACCM_VAR_ZERO_INIT) vMemAccM_RejectRequests = FALSE;

#define VMEMACCM_STOP_SEC_VAR_ZERO_INIT_8BIT
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
# endif /* (VMEMACCM_MINIMAL_SYNC == STD_OFF) */

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

#define VMEMACCM_START_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#if (VMEMACCM_DEV_ERROR_DETECT == STD_ON)
/**********************************************************************************************************************
 *  vMemAccM_PointerValid
 *********************************************************************************************************************/
/*!
 * \brief       Check whether the pointer != NULL_PTR.
 * \details     -
 * \param[in]   Ptr to check.
 * \return      TRUE, if the pointer != NULL_PTR;
 *              FALSE otherwise.
 * \pre         VMEMACCM_DEV_ERROR_DETECT == STD_ON
 * \context     ANY
 * \reentrant   FALSE
 * \synchronous TRUE
 */
VMEMACCM_LOCAL_INLINE FUNC(boolean, VMEMACCM_CODE) vMemAccM_PointerValid(vMemAccM_ConstDataPtrType Ptr);
#endif /* (VMEMACCM_DEV_ERROR_DETECT == STD_ON) */


# if (VMEMACCM_MINIMAL_SYNC == STD_OFF)
/**********************************************************************************************************************
 *  vMemAccM_RequestAllowed
 *********************************************************************************************************************/
/*!
 * \brief       Check whether to reject a request.
 * \details     -
 * \return      TRUE, if request shall be rejected;
 *              FALSE otherwise.
 * \pre         -
 * \context     ANY
 * \reentrant   FALSE
 * \synchronous TRUE
 */
VMEMACCM_LOCAL_INLINE FUNC(boolean, VMEMACCM_CODE) vMemAccM_RequestAllowed(void);

/**********************************************************************************************************************
 *  vMemAccM_AddressAreaReadOnly
 *********************************************************************************************************************/
/*!
 * \brief       Checks address areas read only status.
 * \details     -
 * \param[in]   AddressAreaId as array index, used to access the virtual information.
 * \return      TRUE, if address area is read only;
 *              FALSE otherwise.
 * \pre         -
 * \context     ANY
 * \reentrant   FALSE
 * \synchronous TRUE
 */
VMEMACCM_LOCAL_INLINE FUNC(boolean, VMEMACCM_CODE) vMemAccM_AddressAreaReadOnly
(
  vMemAccM_AddressAreaIdType AddressAreaId
);
# endif /* (VMEMACCM_MINIMAL_SYNC == STD_OFF) */

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

#if (VMEMACCM_DEV_ERROR_DETECT == STD_ON)
/**********************************************************************************************************************
 *  vMemAccM_PointerValid
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
VMEMACCM_LOCAL_INLINE FUNC(boolean, VMEMACCM_CODE) vMemAccM_PointerValid(vMemAccM_ConstDataPtrType Ptr)
{
  return (Ptr != NULL_PTR);
}
#endif /* (VMEMACCM_DEV_ERROR_DETECT == STD_ON) */

# if (VMEMACCM_MINIMAL_SYNC == STD_OFF)
/**********************************************************************************************************************
 *  vMemAccM_RequestAllowed
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
VMEMACCM_LOCAL_INLINE FUNC(boolean, VMEMACCM_CODE) vMemAccM_RequestAllowed(void)
{
    return (vMemAccM_RejectRequests == FALSE);
}

/**********************************************************************************************************************
 *  vMemAccM_AddressAreaReadOnly
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
VMEMACCM_LOCAL_INLINE FUNC(boolean, VMEMACCM_CODE) vMemAccM_AddressAreaReadOnly
(
  vMemAccM_AddressAreaIdType AddressAreaId
)
{
  return (vMemAccM_MngmtAreas[AddressAreaId].Flags.ReadOnly == VMEMACCM_BITSET);
}
# endif /* (VMEMACCM_MINIMAL_SYNC == STD_OFF) */

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  vMemAccM_InitMemory
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, VMEMACCM_CODE) vMemAccM_InitMemory(void)
{
#if (VMEMACCM_DEV_ERROR_DETECT == STD_ON)
  vMemAccM_SchedSetInitState(VMEMACCM_UNINIT);
#endif
}

/**********************************************************************************************************************
 *  vMemAccM_Init
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
FUNC(void, VMEMACCM_CODE) vMemAccM_Init(void)
{
#if (VMEMACCM_MULTI_PARTITION_SATELLITE == STD_OFF)
  vMemAccM_vMemPointerTableIterType i;
  for(i = 0u; i < vMemAccM_GetSizeOfvMemPointerTable(); i++)
  {
#if (VMEMACCM_MINIMAL_SYNC == STD_OFF)
    vMemAccM_MemAbResetAlternatevMemPtrTable(i);
#endif /* (VMEMACCM_MINIMAL_SYNC == STD_OFF) */
    vMemAccM_MemAbInit(i);
  }
#endif /* (VMEMACCM_MULTI_PARTITION_SATELLITE == STD_OFF) */

  vMemAccM_SchedInit();
  vMemAccM_CfgAbInit();
  
#if (VMEMACCM_MINIMAL_SYNC == STD_OFF)  
  vMemAccM_RejectRequests = FALSE;
#endif /* (VMEMACCM_MINIMAL_SYNC == STD_OFF) */

#if (VMEMACCM_DEV_ERROR_DETECT == STD_ON)
  vMemAccM_SchedSetInitState(VMEMACCM_INIT);
#endif    
}

/**********************************************************************************************************************
 *  vMemAccM_GetJobResult
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
FUNC(vMemAccM_JobResultType, VMEMACCM_CODE) vMemAccM_GetJobResult(vMemAccM_AddressAreaIdType AddressAreaId)
{
  uint8 errorId = VMEMACCM_E_NO_ERROR;
  vMemAccM_JobResultType result = VMEMACCM_JOB_FAILED; /* PRQA S 2981 */ /* MD_MSR_RetVal */

#if (VMEMACCM_DEV_ERROR_DETECT == STD_ON)
  if (vMemAccM_SchedIsInitialized() == FALSE)
  {
    errorId = VMEMACCM_E_UNINIT;
  }
  else if (vMemAccM_CfgAbAddressAreaIdValid(AddressAreaId) == FALSE)
  {
    errorId = VMEMACCM_E_PARAM_ADDRESS_AREA_ID;
  }
  else
#endif
  {
    result = vMemAccM_MngmtAreas[AddressAreaId].JobResult;
  }

#if (VMEMACCM_DEV_ERROR_REPORT == STD_ON)
  if (errorId != VMEMACCM_E_NO_ERROR)
  {
    (void)Det_ReportError(VMEMACCM_MODULE_ID, VMEMACCM_INSTANCE_ID, VMEMACCM_SID_GET_JOB_RESULT, errorId);
  }
#else
  VMEMACCM_DUMMY_STATEMENT(errorId); /* PRQA S 3112 */ /* MD_MSR_DummyStmt */
#endif

  return result;
}

/**********************************************************************************************************************
 *  vMemAccM_Read
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
 */
FUNC(Std_ReturnType, VMEMACCM_CODE) vMemAccM_Read
(
  vMemAccM_AddressAreaIdType AddressAreaId,
  vMemAccM_AddressType SourceAddress,
  vMemAccM_DataPtrType DestinationPtr,
  vMemAccM_LengthType Length
)
{
  uint8 errorId = VMEMACCM_E_NO_ERROR;
  Std_ReturnType retVal = E_NOT_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

#if (VMEMACCM_DEV_ERROR_DETECT == STD_ON)
  if (vMemAccM_SchedIsInitialized() == FALSE)
  {
    errorId = VMEMACCM_E_UNINIT;
  }
  else if (vMemAccM_CfgAbAddressAreaIdValid(AddressAreaId) == FALSE)
  {
    errorId = VMEMACCM_E_PARAM_ADDRESS_AREA_ID;
  }
  else if (vMemAccM_SchedIsAddressAreaPending(AddressAreaId) == TRUE)
  {
    errorId = VMEMACCM_E_PENDING;
  }
  else if (vMemAccM_PointerValid(DestinationPtr) == FALSE) /* SBSW_vMemAccM_PointerChecker */
  {
    errorId = VMEMACCM_E_PARAM_POINTER;
  }
  else if (vMemAccM_CfgAbAddressAndLengthValid(AddressAreaId, SourceAddress, Length) == FALSE)
  {
    errorId = VMEMACCM_E_PARAM_ADDRESS_LENGTH;
  }
  else
#endif
  {
# if (VMEMACCM_MINIMAL_SYNC == STD_OFF)
    if(vMemAccM_RequestAllowed() == TRUE)
# endif /* (VMEMACCM_MINIMAL_SYNC == STD_OFF) */
    {
      retVal = vMemAccM_SchedQueueJob(VMEMACCM_READJOB, AddressAreaId, SourceAddress, DestinationPtr, Length); /* SBSW_vMemAccM_UserDataPointer */
    }
  }

#if (VMEMACCM_DEV_ERROR_REPORT == STD_ON)
  if (errorId != VMEMACCM_E_NO_ERROR)
  {
    (void)Det_ReportError(VMEMACCM_MODULE_ID, VMEMACCM_INSTANCE_ID, VMEMACCM_SID_READ, errorId);
  }
#else
  VMEMACCM_DUMMY_STATEMENT(errorId); /* PRQA S 3112 */ /* MD_MSR_DummyStmt */
#endif

  return retVal;
} /* PRQA S 6050, 6080 */ /* MD_MSR_STCAL , MD_MSR_STMIF */

/**********************************************************************************************************************
 *  vMemAccM_Write
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
 */
FUNC(Std_ReturnType, VMEMACCM_CODE) vMemAccM_Write
(
  vMemAccM_AddressAreaIdType AddressAreaId,
  vMemAccM_AddressType TargetAddress,
  vMemAccM_ConstDataPtrType SourcePtr,
  vMemAccM_LengthType Length
)
{
  uint8 errorId = VMEMACCM_E_NO_ERROR;
  Std_ReturnType retVal = E_NOT_OK;

#if (VMEMACCM_DEV_ERROR_DETECT == STD_ON)
  if (vMemAccM_SchedIsInitialized() == FALSE)
  {
    errorId = VMEMACCM_E_UNINIT;
  }
  else if (vMemAccM_CfgAbAddressAreaIdValid(AddressAreaId) == FALSE)
  {
    errorId = VMEMACCM_E_PARAM_ADDRESS_AREA_ID;
  }
  else if (vMemAccM_SchedIsAddressAreaPending(AddressAreaId) == TRUE)
  {
    errorId = VMEMACCM_E_PENDING;
  }
  else if (vMemAccM_PointerValid(SourcePtr) == FALSE) /* SBSW_vMemAccM_PointerChecker */
  {
    errorId = VMEMACCM_E_PARAM_POINTER;
  }
  else if (vMemAccM_CfgAbAddressAndLengthValid(AddressAreaId, TargetAddress, Length) == FALSE)
  {
    errorId = VMEMACCM_E_PARAM_ADDRESS_LENGTH;
  }
  else
#endif
  {
# if (VMEMACCM_MINIMAL_SYNC == STD_OFF)
    if ((vMemAccM_AddressAreaReadOnly(AddressAreaId) == FALSE) && (vMemAccM_RequestAllowed() == TRUE))
# endif /* (VMEMACCM_MINIMAL_SYNC == STD_OFF) */
    {
      retVal = vMemAccM_SchedQueueJob(VMEMACCM_WRITEJOB, AddressAreaId, TargetAddress,
        (vMemAccM_DataPtrType)SourcePtr, Length); /* PRQA S 0311 */ /* MD_vMemAccM_CastPtrToNonConst */ /* SBSW_vMemAccM_UserDataPointer */
    }
  }

#if (VMEMACCM_DEV_ERROR_REPORT == STD_ON)
  if (errorId != VMEMACCM_E_NO_ERROR)
  {
    (void)Det_ReportError(VMEMACCM_MODULE_ID, VMEMACCM_INSTANCE_ID, VMEMACCM_SID_WRITE, errorId);
  }
#else
  VMEMACCM_DUMMY_STATEMENT(errorId); /* PRQA S 3112 */ /* MD_MSR_DummyStmt */
#endif

  return retVal;
} /* PRQA S 6050, 6080 */ /* MD_MSR_STCAL , MD_MSR_STMIF */

/**********************************************************************************************************************
 *  vMemAccM_Erase
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
 */
FUNC(Std_ReturnType, VMEMACCM_CODE) vMemAccM_Erase
(
  vMemAccM_AddressAreaIdType AddressAreaId,
  vMemAccM_AddressType TargetAddress,
  vMemAccM_LengthType Length
)
{
  uint8 errorId = VMEMACCM_E_NO_ERROR;
  Std_ReturnType retVal = E_NOT_OK;

#if (VMEMACCM_DEV_ERROR_DETECT == STD_ON)
  if (vMemAccM_SchedIsInitialized() == FALSE)
  {
    errorId = VMEMACCM_E_UNINIT;
  }
  else if (vMemAccM_CfgAbAddressAreaIdValid(AddressAreaId) == FALSE)
  {
    errorId = VMEMACCM_E_PARAM_ADDRESS_AREA_ID;
  }
  else if (vMemAccM_SchedIsAddressAreaPending(AddressAreaId) == TRUE)
  {
    errorId = VMEMACCM_E_PENDING;
  }
  else if (vMemAccM_CfgAbAddressAndLengthValid(AddressAreaId, TargetAddress, Length) == FALSE)
  {
    errorId = VMEMACCM_E_PARAM_ADDRESS_LENGTH;
  }
  else
#endif
  {
# if (VMEMACCM_MINIMAL_SYNC == STD_OFF)
    if ((vMemAccM_AddressAreaReadOnly(AddressAreaId) == FALSE) && (vMemAccM_RequestAllowed() == TRUE))
# endif /* (VMEMACCM_MINIMAL_SYNC == STD_OFF) */
    {
      /* Since Erase does not need and/or use any user buffer an NULL_PTR can be used to queue and handle the job. */
      retVal = vMemAccM_SchedQueueJob(VMEMACCM_ERASEJOB, AddressAreaId, TargetAddress, NULL_PTR, Length); /* SBSW_vMemAccM_UserDataPointer */
    }
  }

#if (VMEMACCM_DEV_ERROR_REPORT == STD_ON)
  if (errorId != VMEMACCM_E_NO_ERROR)
  {
    (void)Det_ReportError(VMEMACCM_MODULE_ID, VMEMACCM_INSTANCE_ID, VMEMACCM_SID_ERASE, errorId);
  }
#else
  VMEMACCM_DUMMY_STATEMENT(errorId); /* PRQA S 3112 */ /* MD_MSR_DummyStmt */
#endif

  return retVal;
} /* PRQA S 6050, 6080 */ /* MD_MSR_STCAL , MD_MSR_STMIF */

#if (VMEMACCM_COMPARE_API == STD_ON)
/**********************************************************************************************************************
 *  vMemAccM_Compare
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
FUNC(Std_ReturnType, VMEMACCM_CODE) vMemAccM_Compare
(
  vMemAccM_AddressAreaIdType AddressAreaId,
  vMemAccM_AddressType SourceAddress,
  vMemAccM_ConstDataPtrType DataPtr,
  vMemAccM_LengthType Length
)
{
  uint8 errorId = VMEMACCM_E_NO_ERROR;
  Std_ReturnType retVal = E_NOT_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

# if (VMEMACCM_DEV_ERROR_DETECT == STD_ON)
  if (vMemAccM_SchedIsInitialized() == FALSE)
  {
    errorId = VMEMACCM_E_UNINIT;
  }
  else if (vMemAccM_CfgAbAddressAreaIdValid(AddressAreaId) == FALSE)
  {
    errorId = VMEMACCM_E_PARAM_ADDRESS_AREA_ID;
  }
  else if (vMemAccM_SchedIsAddressAreaPending(AddressAreaId) == TRUE)
  {
    errorId = VMEMACCM_E_PENDING;
  }
  else if (vMemAccM_PointerValid(DataPtr) == FALSE) /* SBSW_vMemAccM_PointerChecker */
  {
    errorId = VMEMACCM_E_PARAM_POINTER;
  }
  else if (vMemAccM_CfgAbAddressAndLengthValid(AddressAreaId, SourceAddress, Length) == FALSE)
  {
    errorId = VMEMACCM_E_PARAM_ADDRESS_LENGTH;
  }
  else
# endif
  {
    if(vMemAccM_RequestAllowed() == TRUE)
    {
      retVal = vMemAccM_SchedQueueJob(
        VMEMACCM_COMPAREJOB, AddressAreaId, SourceAddress, (vMemAccM_DataPtrType)DataPtr, Length); /* PRQA S 0311 */ /* MD_vMemAccM_CastPtrToNonConst */ /* SBSW_vMemAccM_UserDataPointer */
    }
  }

# if (VMEMACCM_DEV_ERROR_REPORT == STD_ON)
  if (errorId != VMEMACCM_E_NO_ERROR)
  {
      (void)Det_ReportError(VMEMACCM_MODULE_ID, VMEMACCM_INSTANCE_ID, VMEMACCM_SID_COMPARE, errorId);
  }
# else
  VMEMACCM_DUMMY_STATEMENT(errorId); /* PRQA S 3112 */ /* MD_MSR_DummyStmt */
# endif

  return retVal;
} /* PRQA S 6050, 6080 */ /* MD_MSR_STCAL , MD_MSR_STMIF */
#endif /* (VMEMACCM_COMPARE_API == STD_ON) */

/**********************************************************************************************************************
 * vMemAccM_IsBlank
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
FUNC(Std_ReturnType, VMEMACCM_CODE) vMemAccM_IsBlank
(
  vMemAccM_AddressAreaIdType AddressAreaId,
  vMemAccM_AddressType TargetAddress,
  vMemAccM_LengthType Length
)
{
  uint8 errorId = VMEMACCM_E_NO_ERROR;
  Std_ReturnType retVal = E_NOT_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

#if (VMEMACCM_DEV_ERROR_DETECT == STD_ON)
  if (vMemAccM_SchedIsInitialized() == FALSE)
  {
    errorId = VMEMACCM_E_UNINIT;
  }
  else if (vMemAccM_CfgAbAddressAreaIdValid(AddressAreaId) == FALSE)
  {
    errorId = VMEMACCM_E_PARAM_ADDRESS_AREA_ID;
  }
  else if (vMemAccM_SchedIsAddressAreaPending(AddressAreaId) == TRUE)
  {
    errorId = VMEMACCM_E_PENDING;
  }
  else if (vMemAccM_CfgAbAddressAndLengthValid(AddressAreaId, TargetAddress, Length) == FALSE)
  {
    errorId = VMEMACCM_E_PARAM_ADDRESS_LENGTH;
  }
  else
#endif
  {
# if (VMEMACCM_MINIMAL_SYNC == STD_OFF)
    if(vMemAccM_RequestAllowed() == TRUE)
# endif /* (VMEMACCM_MINIMAL_SYNC == STD_OFF) */
    {
    /* Since IsBlank does not need and/or use any user buffer an NULL_PTR can be used to queue and handle the job. */
      retVal = vMemAccM_SchedQueueJob(VMEMACCM_ISBLANKJOB, AddressAreaId, TargetAddress, NULL_PTR, Length); /* SBSW_vMemAccM_UserDataPointer */
    }
  }

#if (VMEMACCM_DEV_ERROR_REPORT == STD_ON)
  if (errorId != VMEMACCM_E_NO_ERROR)
  {
    (void)Det_ReportError(VMEMACCM_MODULE_ID, VMEMACCM_INSTANCE_ID, VMEMACCM_SID_IS_BLANK, errorId);
  }
#else
  VMEMACCM_DUMMY_STATEMENT(errorId); /* PRQA S 3112 */ /* MD_MSR_DummyStmt */
#endif

  return retVal;
} /* PRQA S 6080 */ /* MD_MSR_STMIF */

/**********************************************************************************************************************
 *  vMemAccM_MainFunction
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(void, VMEMACCM_CODE) vMemAccM_MainFunction(void)
{
  uint8 errorId = VMEMACCM_E_NO_ERROR;

# if (VMEMACCM_DEV_ERROR_DETECT == STD_ON)
  if (vMemAccM_SchedIsInitialized() == FALSE)
  {
    errorId = VMEMACCM_E_UNINIT;
  }
  else
# endif
  {
    vMemAccM_SchedMainFunction();
  }

# if (VMEMACCM_DEV_ERROR_REPORT == STD_ON)
  if (errorId != VMEMACCM_E_NO_ERROR)
  {
    (void)Det_ReportError(VMEMACCM_MODULE_ID, VMEMACCM_INSTANCE_ID, VMEMACCM_SID_MAINFUNCTION, errorId);
  }
# else
  VMEMACCM_DUMMY_STATEMENT(errorId); /* PRQA S 3112 */ /* MD_MSR_DummyStmt */
# endif
} /* vMemAccM_MainFunction */

#if (VMEMACCM_MINIMAL_SYNC == STD_OFF)
#if (VMEMACCM_MULTI_PARTITION_SATELLITE == STD_OFF)
/**********************************************************************************************************************
 * vMemAccM_HwSpecificReq
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
FUNC(Std_ReturnType, VMEMACCM_CODE) vMemAccM_HwSpecificReq
(
  vMemAccM_AddressAreaIdType AddressAreaId,
  vMemAccM_HwIdType HwId,
  vMemAccM_vMemHwSpecificFuncIndexType vMemHwSpecificFuncIndex,
  vMemAccM_DataPtrType DataPtr,
  vMemAccM_LengthType DataSize
)
{
  uint8 errorId = VMEMACCM_E_NO_ERROR;
  Std_ReturnType retVal = E_NOT_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

# if (VMEMACCM_DEV_ERROR_DETECT == STD_ON)
  if (vMemAccM_SchedIsInitialized() == FALSE)
  {
    errorId = VMEMACCM_E_UNINIT;
  }
  else if (vMemAccM_CfgAbAddressAreaIdValid(AddressAreaId) == FALSE)
  {
    errorId = VMEMACCM_E_PARAM_ADDRESS_AREA_ID;
  }
  else if (vMemAccM_CfgAbHwIdValid(AddressAreaId, HwId) == FALSE)
  {
    errorId = VMEMACCM_E_PARAM_HW_ID;
  }
  else if (vMemAccM_CfgAbHwFuncIndexValid(AddressAreaId, HwId, vMemHwSpecificFuncIndex) == FALSE)
  {
    errorId = VMEMACCM_E_PARAM_HW_SPECIFIC_FUNC_INDEX;
  }
  else if (vMemAccM_SchedIsAddressAreaPending(AddressAreaId) == TRUE)
  {
    errorId = VMEMACCM_E_PENDING;
  }
  else
# endif
  {
    if(vMemAccM_RequestAllowed() == TRUE)
    {
      /* Note: DataPtr and DataSize won't be checked, completely up to the user and the related vMem, can be 0 and NULL_PTR! */
      retVal = vMemAccM_SchedQueueHwSpecificJob(
        VMEMACCM_VMEMJOB, AddressAreaId, HwId, DataPtr, DataSize, vMemHwSpecificFuncIndex); /* SBSW_vMemAccM_UserDataPointer */
    }
  }

# if (VMEMACCM_DEV_ERROR_REPORT == STD_ON)
  if (errorId != VMEMACCM_E_NO_ERROR)
  {
    (void)Det_ReportError(VMEMACCM_MODULE_ID, VMEMACCM_INSTANCE_ID, VMEMACCM_SID_HW_SPECIFIC_REQ, errorId);
  }
# else
  VMEMACCM_DUMMY_STATEMENT(errorId); /* PRQA S 3112 */ /* MD_MSR_DummyStmt */
# endif

  return retVal;
} /* PRQA S 6050, 6080 */ /* MD_MSR_STCAL, MD_MSR_STMIF */
#endif /* (VMEMACCM_MULTI_PARTITION_SATELLITE == STD_OFF) */


/**********************************************************************************************************************
 *  vMemAccM_ReadBlank
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
FUNC(Std_ReturnType, VMEMACCM_CODE) vMemAccM_ReadBlank
(
  vMemAccM_AddressAreaIdType AddressAreaId,
  vMemAccM_AddressType SourceAddress,
  vMemAccM_DataPtrType DestinationPtr,
  vMemAccM_LengthType Length
)
{
  uint8 errorId = VMEMACCM_E_NO_ERROR;
  Std_ReturnType retVal = E_NOT_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

#if (VMEMACCM_DEV_ERROR_DETECT == STD_ON)
  if (vMemAccM_SchedIsInitialized() == FALSE)
  {
    errorId = VMEMACCM_E_UNINIT;
  }
  else if (vMemAccM_CfgAbAddressAreaIdValid(AddressAreaId) == FALSE)
  {
    errorId = VMEMACCM_E_PARAM_ADDRESS_AREA_ID;
  }
  else if (vMemAccM_SchedIsAddressAreaPending(AddressAreaId) == TRUE)
  {
    errorId = VMEMACCM_E_PENDING;
  }
  else if (vMemAccM_PointerValid(DestinationPtr) == FALSE) /* SBSW_vMemAccM_PointerChecker */
  {
    errorId = VMEMACCM_E_PARAM_POINTER;
  }
  else if (vMemAccM_CfgAbAddressAndLengthValid(AddressAreaId, SourceAddress, Length) == FALSE)
  {
    errorId = VMEMACCM_E_PARAM_ADDRESS_LENGTH;
  }
  else
#endif
  {
    if(vMemAccM_RequestAllowed() == TRUE)
    {
      retVal = vMemAccM_SchedQueueJob(VMEMACCM_READBLANKJOB, AddressAreaId, SourceAddress, DestinationPtr, Length); /* SBSW_vMemAccM_UserDataPointer */
    }
  }

#if (VMEMACCM_DEV_ERROR_REPORT == STD_ON)
  if (errorId != VMEMACCM_E_NO_ERROR)
  {
    (void)Det_ReportError(VMEMACCM_MODULE_ID, VMEMACCM_INSTANCE_ID, VMEMACCM_SID_READ_BLANK, errorId);
  }
#else
  VMEMACCM_DUMMY_STATEMENT(errorId); /* PRQA S 3112 */ /* MD_MSR_DummyStmt */
#endif

  return retVal;
} /* PRQA S 6050, 6080 */ /* MD_MSR_STCAL , MD_MSR_STMIF */

/**********************************************************************************************************************
 *  vMemAccM_Cancel
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
FUNC(void, VMEMACCM_CODE) vMemAccM_Cancel(vMemAccM_AddressAreaIdType AddressAreaId)
{
  uint8 errorId = VMEMACCM_E_NO_ERROR;

#if (VMEMACCM_DEV_ERROR_DETECT == STD_ON)
  if (vMemAccM_SchedIsInitialized() == FALSE)
  {
    errorId = VMEMACCM_E_UNINIT;
  }
  else if (vMemAccM_CfgAbAddressAreaIdValid(AddressAreaId) == FALSE)
  {
    errorId = VMEMACCM_E_PARAM_ADDRESS_AREA_ID;
  }
  else
#endif
  {
    vMemAccM_SchedCancelJob(AddressAreaId);
  }

#if (VMEMACCM_DEV_ERROR_REPORT == STD_ON)
  if (errorId != VMEMACCM_E_NO_ERROR)
  {
    (void)Det_ReportError(VMEMACCM_MODULE_ID, VMEMACCM_INSTANCE_ID, VMEMACCM_SID_CANCEL, errorId);
  }
#else
  VMEMACCM_DUMMY_STATEMENT(errorId); /* PRQA S 3112 */ /* MD_MSR_DummyStmt */
#endif
}

/**********************************************************************************************************************
 *  vMemAccM_GetMemoryInfo
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
FUNC(Std_ReturnType, VMEMACCM_CODE) vMemAccM_GetMemoryInfo
(
  vMemAccM_AddressAreaIdType AddressAreaId,
  vMemAccM_AddressType Address,
  vMemAccM_LengthType Length,
  vMemAccM_MemoryInfoPtrType MemoryInfoPtr
)
{
  uint8 errorId = VMEMACCM_E_NO_ERROR;
  Std_ReturnType retVal = E_NOT_OK;

#if (VMEMACCM_DEV_ERROR_DETECT == STD_ON)
  if (vMemAccM_SchedIsInitialized() == FALSE)
  {
    errorId = VMEMACCM_E_UNINIT;
  }
  else if (vMemAccM_CfgAbAddressAreaIdValid(AddressAreaId) == FALSE)
  {
    errorId = VMEMACCM_E_PARAM_ADDRESS_AREA_ID;
  }
  else if (MemoryInfoPtr == NULL_PTR)
  {
    errorId = VMEMACCM_E_PARAM_POINTER;
  }
  else
#endif
  {
    if (vMemAccM_CfgAbAddressAndLengthValid(AddressAreaId, Address, Length) == TRUE)
    {
      /* At this point we know the address is valid, no need to check the sub address area Id. */
      /* No need to check the subAddressAreaId to be valid -> AddressAreaId, Address and Length are checked above. */
      vMemAccM_AddressAreaIdType subAddressAreaId = vMemAccM_CfgAbGetSubAddrAreaId(AddressAreaId, Address);
      boolean pageBurstEnabled = vMemAccM_IsUsePageBurstOfSubAddressArea(subAddressAreaId);
      /* Fill the structure */
      MemoryInfoPtr->VirtualStartAddress = vMemAccM_GetVirtualStartAddressOfSubAddressArea(subAddressAreaId); /* SBSW_vMemAccM_UserPointer */
      MemoryInfoPtr->PhysicalStartAddress = vMemAccM_GetPhysicalStartAddressOfSubAddressArea(subAddressAreaId); /* SBSW_vMemAccM_UserPointer */
      MemoryInfoPtr->MaxOffset = vMemAccM_GetVirtualEndAddressOfSubAddressArea(subAddressAreaId) /* SBSW_vMemAccM_UserPointer */
          - vMemAccM_GetVirtualStartAddressOfSubAddressArea(subAddressAreaId);

      MemoryInfoPtr->NumberOfSectors = vMemAccM_GetNumberOfSectorsOfSubAddressArea(subAddressAreaId); /* SBSW_vMemAccM_UserPointer */
      MemoryInfoPtr->SectorSize = vMemAccM_GetSectorSizeOfSubAddressArea(subAddressAreaId); /* SBSW_vMemAccM_UserPointer */
      MemoryInfoPtr->SectorBurstSize = vMemAccM_IsUseSectorBurstOfSubAddressArea(subAddressAreaId) ? /* SBSW_vMemAccM_UserPointer */
          vMemAccM_GetSectorBurstSizeOfSubAddressArea(subAddressAreaId) : vMemAccM_GetSectorSizeOfSubAddressArea(subAddressAreaId);

      MemoryInfoPtr->PageSize = vMemAccM_GetPageSizeOfSubAddressArea(subAddressAreaId); /* SBSW_vMemAccM_UserPointer */
      MemoryInfoPtr->PageBurstSize = (pageBurstEnabled == TRUE) ? /* SBSW_vMemAccM_UserPointer */
          vMemAccM_GetPageBurstSizeOfSubAddressArea(subAddressAreaId) : vMemAccM_GetPageSizeOfSubAddressArea(subAddressAreaId);
      MemoryInfoPtr->PageBurstRamAlignment = (pageBurstEnabled == TRUE) ? /* SBSW_vMemAccM_UserPointer */
          vMemAccM_GetPageBurstRamAlignmentOfSubAddressArea(subAddressAreaId) : 1u;

      MemoryInfoPtr->HwId = vMemAccM_GetHardwareIdOfSubAddressArea(subAddressAreaId); /* SBSW_vMemAccM_UserPointer */

      retVal = E_OK;
    }
   }

#if (VMEMACCM_DEV_ERROR_REPORT == STD_ON)
    if (errorId != VMEMACCM_E_NO_ERROR)
    {
      (void)Det_ReportError(VMEMACCM_MODULE_ID, VMEMACCM_INSTANCE_ID, VMEMACCM_SID_GET_MEMORY_INFO, errorId);
    }
#else
  VMEMACCM_DUMMY_STATEMENT(errorId); /* PRQA S 3112 */ /* MD_MSR_DummyStmt */
#endif

  return retVal;
}

/**********************************************************************************************************************
 *  vMemAccM_SetReadOnlyMode
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
FUNC(Std_ReturnType, VMEMACCM_CODE) vMemAccM_SetReadOnlyMode
(
  vMemAccM_AddressAreaIdType AddressAreaId,
  boolean ReadOnly
)
{
  uint8 errorId = VMEMACCM_E_NO_ERROR;
  Std_ReturnType retVal = E_NOT_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

#if (VMEMACCM_DEV_ERROR_DETECT == STD_ON)
  if (vMemAccM_SchedIsInitialized() == FALSE)
  {
    errorId = VMEMACCM_E_UNINIT;
  }
  else if (vMemAccM_CfgAbAddressAreaIdValid(AddressAreaId) == FALSE)
  {
    errorId = VMEMACCM_E_PARAM_ADDRESS_AREA_ID;
  }
  else
#endif
  {
    SchM_Enter_vMemAccM_VMEMACCM_EXCLUSIVE_AREA_0();
    /* ReadOnly is just a byte, assigning the boolean, which is uint8, may lead to compiler warnings -> use 0 or 1 for assignment. */
    vMemAccM_MngmtAreas[AddressAreaId].Flags.ReadOnly = (ReadOnly == TRUE) ? VMEMACCM_BITSET : VMEMACCM_BITUNSET; /* SBSW_vMemAccM_MngmtAreas */
    SchM_Exit_vMemAccM_VMEMACCM_EXCLUSIVE_AREA_0();

    retVal = E_OK;
  }

#if (VMEMACCM_DEV_ERROR_REPORT == STD_ON)
  if (errorId != VMEMACCM_E_NO_ERROR)
  {
    (void)Det_ReportError(VMEMACCM_MODULE_ID, VMEMACCM_INSTANCE_ID, VMEMACCM_SID_SET_READ_ONLY_MODE, errorId);
  }
#else
  VMEMACCM_DUMMY_STATEMENT(errorId); /* PRQA S 3112 */ /* MD_MSR_DummyStmt */
#endif

  return retVal;
}

/**********************************************************************************************************************
 *  vMemAccM_GetProcessedLength
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
FUNC(Std_ReturnType, VMEMACCM_CODE) vMemAccM_GetProcessedLength
(
  vMemAccM_AddressAreaIdType AddressAreaId,
  vMemAccM_LengthPtrType LengthPtr
)
{
  uint8 errorId = VMEMACCM_E_NO_ERROR;
  Std_ReturnType retVal = E_NOT_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

#if (VMEMACCM_DEV_ERROR_DETECT == STD_ON)
  if (vMemAccM_SchedIsInitialized() == FALSE)
  {
    errorId = VMEMACCM_E_UNINIT;
  }
  else if (vMemAccM_CfgAbAddressAreaIdValid(AddressAreaId) == FALSE)
  {
    errorId = VMEMACCM_E_PARAM_ADDRESS_AREA_ID;
  }
  else if (LengthPtr == NULL_PTR)
  {
    errorId = VMEMACCM_E_PARAM_POINTER;
  }
  else
#endif
  {
    *LengthPtr = vMemAccM_MngmtAreas[AddressAreaId].Offset; /* SBSW_vMemAccM_UserPointer */
    retVal = E_OK;
  }

#if (VMEMACCM_DEV_ERROR_REPORT == STD_ON)
  if (errorId != VMEMACCM_E_NO_ERROR)
  {
    (void)Det_ReportError(VMEMACCM_MODULE_ID, VMEMACCM_INSTANCE_ID, VMEMACCM_SID_GET_PROCESSED_LENGTH, errorId);
  }
#else
  VMEMACCM_DUMMY_STATEMENT(errorId); /* PRQA S 3112 */ /* MD_MSR_DummyStmt */
#endif

  return retVal;
}

/**********************************************************************************************************************
 * vMemAccM_GetState
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
FUNC(Std_ReturnType, VMEMACCM_CODE) vMemAccM_GetState
(
  vMemAccM_AddressAreaIdType AddressAreaId,
  vMemAccM_StatePtrType StatePtr
)
{
  uint8 errorId = VMEMACCM_E_NO_ERROR;
  Std_ReturnType retVal = E_NOT_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

#if (VMEMACCM_DEV_ERROR_DETECT == STD_ON)
  if (vMemAccM_SchedIsInitialized() == FALSE)
  {
    errorId = VMEMACCM_E_UNINIT;
  }
  else if (vMemAccM_CfgAbAddressAreaIdValid(AddressAreaId) == FALSE)
  {
    errorId = VMEMACCM_E_PARAM_ADDRESS_AREA_ID;
  }
  else if (StatePtr == NULL_PTR)
  {
    errorId = VMEMACCM_E_PARAM_POINTER;
  }
  else
#endif
  {
    vMemAccM_SchedGetState(AddressAreaId, StatePtr); /* SBSW_vMemAccM_UserPointer */
    retVal = E_OK;
  }

#if (VMEMACCM_DEV_ERROR_REPORT == STD_ON)
  if (errorId != VMEMACCM_E_NO_ERROR)
  {
    (void)Det_ReportError(VMEMACCM_MODULE_ID, VMEMACCM_INSTANCE_ID, VMEMACCM_SID_GET_STATE, errorId);
  }
#else
  VMEMACCM_DUMMY_STATEMENT(errorId); /* PRQA S 3112 */ /* MD_MSR_DummyStmt */
#endif

  return retVal;
}

/**********************************************************************************************************************
 * vMemAccM_SetActiveVariant
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
FUNC(Std_ReturnType, VMEMACCM_CODE) vMemAccM_SetActiveVariant(vMemAccM_VariantIdType VariantId)
{
  uint8 errorId = VMEMACCM_E_NO_ERROR;
  Std_ReturnType retVal = E_NOT_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

#if (VMEMACCM_DEV_ERROR_DETECT == STD_ON)
  if (vMemAccM_SchedIsInitialized() == FALSE)
  {
    errorId = VMEMACCM_E_UNINIT;
  }
  else if (VariantId >= VMEMACCM_VARIANT_NROFAVAILABLEVARIANTS)
  {
    errorId = VMEMACCM_E_PARAM_VARIANT_ID;
  }
  else if (vMemAccM_SchedIsVariantAddressAreaPending() == TRUE)
  {
    errorId = VMEMACCM_E_PENDING;
  }
  else
#endif
  {
    vMemAccM_CfgAbSetActiveVariantId(VariantId);
    retVal = E_OK;
  }

#if (VMEMACCM_DEV_ERROR_REPORT == STD_ON)
  if (errorId != VMEMACCM_E_NO_ERROR)
  {
    (void)Det_ReportError(VMEMACCM_MODULE_ID, VMEMACCM_INSTANCE_ID, VMEMACCM_SID_SET_ACTIVE_VARIANT, errorId);
  }
#else
  VMEMACCM_DUMMY_STATEMENT(errorId); /* PRQA S 3112 */ /* MD_MSR_DummyStmt */
#endif

  return retVal;
}

/**********************************************************************************************************************
 * vMemAccM_ErrorNotification()
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
FUNC(Std_ReturnType, VMEMACCM_CODE) vMemAccM_ErrorNotification
(
  vMemAccM_AddressAreaIdType AddressAreaId,
  vMemAccM_AddressType Address,
  vMemAccM_ErrorNotifResultType Result
)
{
  uint8 errorId = VMEMACCM_E_NO_ERROR;
  Std_ReturnType retVal = E_NOT_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

#if (VMEMACCM_DEV_ERROR_DETECT == STD_ON)
  if (vMemAccM_SchedIsInitialized() == FALSE)
  {
    errorId = VMEMACCM_E_UNINIT;
  }
  else if (vMemAccM_CfgAbAddressAreaIdValid(AddressAreaId) == FALSE)
  {
    errorId = VMEMACCM_E_PARAM_ADDRESS_AREA_ID;
  }
  else
#endif
  {
    if(vMemAccM_SchedSetErrorNotifResult(AddressAreaId, Address, (vMemAccM_JobResultType)Result, VMEMACCM_READJOB) == TRUE) /* PRQA S 4322 */ /* MD_vMemAccM_ErrorNotifResultTypeToResultType */
    {
      retVal = E_OK;
    }
#if (VMEMACCM_DEV_ERROR_DETECT == STD_ON)
    else
    {
      errorId = VMEMACCM_E_ADDRESS_AREA_NOT_ACTIVE;
    }
#endif
  }

#if (VMEMACCM_DEV_ERROR_REPORT == STD_ON)
  if (errorId != VMEMACCM_E_NO_ERROR)
  {
    (void)Det_ReportError(VMEMACCM_MODULE_ID, VMEMACCM_INSTANCE_ID, VMEMACCM_SID_ERROR_NOTIFICATION, errorId);
  }
#else
  VMEMACCM_DUMMY_STATEMENT(errorId); /* PRQA S 3112 */ /* MD_MSR_DummyStmt */
#endif

  return retVal;
}

/**********************************************************************************************************************
 *  vMemAccM_RejectNvRamRequests
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(Std_ReturnType, VMEMACCM_CODE) vMemAccM_RejectNvRamRequests(boolean RejectRequests)
{  
  uint8 errorId = VMEMACCM_E_NO_ERROR;
  Std_ReturnType retVal = E_NOT_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

#if (VMEMACCM_DEV_ERROR_DETECT == STD_ON)
  if (vMemAccM_SchedIsInitialized() == FALSE)
  {
    errorId = VMEMACCM_E_UNINIT;
  }
  else
#endif
  {
      if(vMemAccM_SchedIsAnyAddressAreaPending() == FALSE)
      {
        retVal = E_OK;
        vMemAccM_RejectRequests = RejectRequests;
      }
  }

# if (VMEMACCM_DEV_ERROR_REPORT == STD_ON)
  if (errorId != VMEMACCM_E_NO_ERROR)
  {
    (void)Det_ReportError(VMEMACCM_MODULE_ID, VMEMACCM_INSTANCE_ID, VMEMACCM_SID_REJECT_NVRAM_REQUESTS, errorId);
  }
# else
  VMEMACCM_DUMMY_STATEMENT(errorId); /* PRQA S 3112 */ /* MD_MSR_DummyStmt */
# endif

  return retVal;
}
#endif /* (VMEMACCM_MINIMAL_SYNC == STD_OFF) */

#if (VMEMACCM_VERSION_INFO_API == STD_ON)
/**********************************************************************************************************************
 *  vMemAccM_GetVersionInfo
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(void, VMEMACCM_CODE) vMemAccM_GetVersionInfo(P2VAR(Std_VersionInfoType, AUTOMATIC, VMEMACCM_APPL_VAR) VersionInfo)
{
  uint8 errorId = VMEMACCM_E_NO_ERROR;

# if (VMEMACCM_DEV_ERROR_DETECT == STD_ON)
  if (VersionInfo == NULL_PTR)
  {
    errorId = VMEMACCM_E_PARAM_POINTER;
  }
  else
# endif
  {
    VersionInfo->vendorID = (VMEMACCM_VENDOR_ID); /* SBSW_vMemAccM_UserPointer */
    VersionInfo->moduleID = (VMEMACCM_MODULE_ID); /* SBSW_vMemAccM_UserPointer */
    VersionInfo->sw_major_version = (VMEMACCM_SW_MAJOR_VERSION); /* SBSW_vMemAccM_UserPointer */
    VersionInfo->sw_minor_version = (VMEMACCM_SW_MINOR_VERSION); /* SBSW_vMemAccM_UserPointer */
    VersionInfo->sw_patch_version = (VMEMACCM_SW_PATCH_VERSION); /* SBSW_vMemAccM_UserPointer */
  }

# if (VMEMACCM_DEV_ERROR_REPORT == STD_ON)
  if (errorId != VMEMACCM_E_NO_ERROR)
  {
    (void)Det_ReportError(VMEMACCM_MODULE_ID, VMEMACCM_INSTANCE_ID, VMEMACCM_SID_GET_VERSION_INFO, errorId);
  }
# else
  VMEMACCM_DUMMY_STATEMENT(errorId); /* PRQA S 3112 */ /* MD_MSR_DummyStmt */
# endif
}
#endif /* (VMEMACCM_VERSION_INFO_API == STD_ON) */


#define VMEMACCM_STOP_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* Justification for module-specific MISRA deviations:    
  MD_vMemAccM_NonConstContextPtr: rule 8.13
    Reason:     The context pointer is not const, it is merely used as a dummy which has to match the same signature as the "real" state handler implementations. 
                Since the default state handler does not use the function parameter it could be declared const. Since the signature of the function has
                to match the other state handler functions this is not possible.
    Risk:       No risk, the function is empty, it does not use the parameters.
    Prevention: No prevention. 

  MD_vMemAccM_DereferenceOfInvalidPointerValue: rule 4.1
    Reason:     With enabled development or SafeBSW mode vMemAccM's public APIs check the input parameters to be valid - that includes
                an address area ID check. The queue sub module expects the passed address area ID to be valid and uses it directly to access the configuration
                and then directly the priority value from configuration to access queue elements.
                With disabled parameter checks the user is responsible to pass only valid address area IDs to vMemAccM.
    Risk:       vMemAccM may read out of its memory (configuration) and then write out of its memory (queue).
    Prevention: Always pass valid address area IDs, enable SafeBSW or development mode.
  
  MD_vMemAccM_CastToHwIdType: rule 10.5
    Reason:     vMemAccM HwSpecificReq requires a HwId, provided by vMemAccM, which will be queued as "address" (casted to address type), because
                we use the same queue for all requests. Only in case of HwSpecificReq job the address value will be casted back to the
                origin HwIdType.
    Risk:       If anything else than a HW identifier was queued, this cast would not lead to correct HW identifier. At this point
                vMemAccM excepts the values to be valid and uses them directly -> out of range access.
    Prevention: No prevention.
  
  MD_vMemAccM_ErrorNotifResultTypeToResultType: rule 10.5
    Reason:     vMemAccM implements all job results contained in vMemAccM_JobResultType. Its Error Notification implementation supports only two of them -
                therefore the vMemAccM_ErrorNotifResultType was introduced and contains only the allowed result values. The enumeration constants have the same
                values within vMemAccM_JobResultType and vMemAccM_ErrorNotifResultType - ensured via assignment of JobResultType constants to ErrorNotifResultType constants.
    Risk:       No risk.
    Prevention: Component test ensures that the values matches and the results are used correctly.

  MD_vMemAccM_MultiPartitionSatelliteJobResultCast: rule 10.5
   Reason:      vMemAccM multi partition solution uses uint32 values (in shared RAM) to exchange data between the (satellite) partition and the master partition.
                One of the exchanged values is the job result, which is defined as enum. vMemAccM needs to cast the enum to the uint32 value and vice versa,
                depending on shared RAM accessor: the master or the (satellite) partition.
   Risk:        Out of bounds value cast.
   Prevention:  Component test ensures that the values matches and the results are used correctly.

  MD_vMemAccM_VoidPtrTypedPtr: rule 1.1, 11.5
    Reason:     vMemAccM accepts untyped void pointers for user buffers. vMemAccM takes care about splitting requests into smaller peaces,
                therefore it has to move the data pointer to forward to lower layer - this is no allowed for void pointers, therefore
                vMemAccM cast the passed void pointer to uint8 pointer, moves the address and finally forwards the pointer as void pointer to the vMem.
                vMemAccM also uses its internal buffer to read data during comparison - the internal buffer has to be forwarded as void pointer because
                of the already mentioned void pointer vMem interface.
                During data comparison vMemAccM has to loop over user data buffer to compare the content to the NV RAM content - to implement this a cast
                to uint8 pointer was implemented.
                Within the multi partition single NV RAM accessor use case data needs to copied from internal RAM to shared RAM and vice versa.
                The copy function has a void pointer interface to be able to use both as source and target: internal and shared RAM pointers.
    Risk:       No risk.
    Prevention: Component tests ensures that the vMemAccM forwards and accesses the RAM buffers correctly.
  
  MD_vMemAccM_VoidPtrTypedPtrAltvMem: rule 1.1
    Reason:     When validating an alternate vMem, a uint32 header, a pointer to the header and a pointer to the footer needs to be read out.
                The local vMemAccM_AltvMem structure is directly forwarded as the read target buffer to the void pointer vMem interface, 
                because the first three members of the vMemAccM_AltvMem structure match exactly with the first three members of the vMem Function pointer table
                (header, header pointer and footer pointer).
    Risk:       Read request will not target the three members completely.
    Prevention: The order of the members within a c structure is fix. 
                The total read out length will be determinded by the size of the type from each member, so the three members will be read out completely.
                Within 32 bit system padding is out of question for the uint32 header and the two pointers.
                Component test ensures correct handling.

  MD_vMemAccM_CastPtrToNonConst: rule 11.8
    Reason:     vMemAccM internally stores user buffers as non const pointers, therefore the passed pointer has to be casted. vMemAccM does not
                modify the buffer, this is just done because the module shall not store different buffer pointers in parallel - const and non const.
    Risk:       vMemAccM may modify the buffer erroneously.
    Prevention: Component tests ensures that the vMemAccM forwards the data to vMem without modifications.

  MD_vMemAccM_SideEffects: rule 13.5
    Reason:     In case the vMem rejects the request with burst length, vMemAccM retries the request with normal size. However no matter which one
                was rejected, the accepted number of bytes == 0. To avoid high statement depth and to avoid code repetition, the two preconditions for a
                successful retry were added to one single statement: if the rejected request was burst, retry, otherwise do not. C first checks the
                left decision and will not check the second one, if the first is already false, because AND.
    Risk:       No risk.
    Prevention: No prevention.

  MD_vMemAccM_Uint32ToEnumToUint32Cast: rule 10.3, 10.4, 10.5
   Reason:     vMemAccM uses uint32 values to store information in shared RAM (multi partition synchronization use case). Some of the types needed to be shared
               are enums, e.g. the JobResultType. During the publishing to shared RAM the enum will be casted to uint32 and then when getting the value from
               shared RAM to lokal RAM is will be casted from uint32 to enum.
   Risk:       Out of enum range value casts.
   Prevention: Verification via test and review, no other prevention.

  MD_vMemAccM_Uint32PtrToConstvMemApiPtrTypeCast: rule 11.3
   Reason:     vMemAccM reads out directly a header pointer to an alternate vMem. This header pointer is later on casted to a vMemApi pointer type, 
               which also points to the first member of the vMem function pointer table: The header.
   Risk:       vMem header pointer does not point to a valid vMemApiTable.
   Prevention: It is ensured that a valid vMem function pointer table (vMem) exists at the target address by checking the header and footer beforehand.

  MD_vMemAccM_AltvMemPointerArithmetic: rule 18.4
   Reason:     vMemAccM allows the activation of vMems, which can be added at runtime. The vMemAccM will read all relevant data, e.g. the header and footer from memory.
               The vMemAccM uses the header and footer addresses to determine the size of the alternate vMem.
               The user is responsible to ensure the footer's address is higher than the header's address.
               Should be footer's address be invalid in relation to the header, the service will not accept the request.
   Risk:       Header and footer addresses in memory are not correct, e.g. due to incorrect usage.
   Prevention: The vMemAccM checks the addresses to ensure correct usage.
*/

/* SBSW_JUSTIFICATION_BEGIN  

  \ID SBSW_vMemAccM_CfgAbJobEndNotification
   \DESCRIPTION Function pointer call: The vMemAccM provides the option to call a configured job end notification.
                This can be configured for each address area and thus needs to be done via a function pointer.
   \COUNTERMEASURE \N The function which shall be called is configurable, so vMemAccM cannot check the pointer 
                      correctness.

  \ID SBSW_vMemAccM_vMemApi
   \DESCRIPTION Function pointer call: Each vMem shall provide its public APIs via a function pointer table, which the vMemAccM uses
                to forward jobs to the vMem.
   \COUNTERMEASURE \N The vMem module is responsible to provide all necessary function pointers/ valid function pointer table,
                      vMemAccM cannot check the pointer correctness.
  
  \ID SBSW_vMemAccM_LocalVarAsPtrFuncParam
   \DESCRIPTION Function call with pointer parameter: Function local, or file local variable passed to a function as pointer to avoid
                global variables. The called function is allowed to modify the parameter.
   \COUNTERMEASURE \N Caller ensures parameter correctness. Component tests and review shall help to detect issues.
  
  \ID SBSW_vMemAccM_JobParams
   \DESCRIPTION Pointer write access: vMemAccM state machines use a structure parameter containing all required value to setup a MemAb
                sub module job. The structure will be forwarded to helper functions within as pointer - they modify/
                calculate/ set the included values.
   \COUNTERMEASURE \N The structure parameter will always be created locally within a state function, will be forwarded as pointer and finally
                      "destroyed" at the end of the state. The vMemAccM module is responsible for correctness.
                      Component tests and review shall help to detect issues.
  
  \ID SBSW_vMemAccM_JobParamsFuncCall
   \DESCRIPTION Function call with pointer parameter: vMemAccM state machines use a structure parameter containing all required values to setup a MemAb
                sub module job. The structure will be forwarded to helper functions module as pointer - sometimes one
                function forwards the pointer to other helper functions - the variable creator is responsible for correctness, helper
                functions assume the pointer is valid.
   \COUNTERMEASURE \N The structure parameter will always be created locally within a state function, will be forwarded as pointer and finally
                      "destroyed" at the end of the state. The vMemAccM module is responsible for correctness.
                      Component tests and review shall help to detect issues.
  
  \ID SBSW_vMemAccM_SchedContextPtr
   \DESCRIPTION vMemAccM scheduler state machine functions exchange data via a context pointer. The variable vMemAccM_SchedState
                (within vMemAccM_Sched.c) is the one passed to the functions as a pointer (to avoid global variable accesses).
                The scheduler state machine sets and uses the values within the structure. The entry point is vMemAccM_SchedMainFunction.
                The variable holder, the scheduler module, and the state machines themselves are responsible for correct initialization and accesses.
                This fits to function calls with a ContextPtr and to writing to the ContextPtr too.
                There may be multiple contexts, depending on the configuration of the user.
   \COUNTERMEASURE \N The vMemAccM scheduler functionality depends on this variable and the pointers pointing to it. If there are any issues,
                   the vMemAccM will not run correctly or even not compile at all.
                   All test cases running the module ensure the correct pointer usage within the module.

  \ID SBSW_vMemAccM_SMContextPtr
   \DESCRIPTION vMemAccM scheduler module and the job state machine functions exchange data via a context pointer. The variable vMemAccM_SchedState
                (within vMemAccM_Sched.c) holds the scheduler context and the state machine context too - this state machine context part
                will be forwarded to the state machine function (to avoid global variable accesses). Because the state machines need read-write access,
                the context is a pointer.
                The variable holder, the scheduler module, is responsible for correct initialization and accesses.
                This fits to function calls with a ContextPtr and to writing to the ContextPtr too.
   \COUNTERMEASURE \N The vMemAccM job state machine depends on this variable and the pointers pointing to it. If there are any issues,
                   the vMemAccM will not run correctly or even not compile at all.
                   All test cases running the module ensure the correct pointer usage within the module.

  \ID SBSW_vMemAccM_SMFuncPtr
   \DESCRIPTION To store the current job state machine state the scheduler module holds a function pointer pointing to the next
                job state machine state. The variable is stored within the queue per address area, will be initialized during job queuing
                and will then be forwarded to the job state machine functions via the context pointer.
                The variable holder, the scheduler module, and the state machines themselves are responsible for correct initialization and accesses.
                This fits to function calls via the pointer, using the pointer as function parameter and writing to the pointer (modifying it when
                moving from one to another state machine state.
   \COUNTERMEASURE \N The vMemAccM scheduler module ensures the state machine function pointer is initialized each time a new job is queued.
                  With wrong behavior the vMemAccM will not run correctly or even not compile at all.
                  All test cases running the module ensure the correct pointer usage within the module.

  \ID SBSW_vMemAccM_MultiPartitionTokenAndPublishReqPtr
   \DESCRIPTION During the multi partition use case the vMemAccM uses two variables: a NV RAM access token and a request publish variable.
                Depending on configuration the variables are only available as addresses (slave partition) or are declared by the vMemAccM module
                (master partition). To provide one single interface to the implementation the module uses pointers pointing to
                either the address or the variable.
                The pointers are never null and shall always point to a valid value.
   \COUNTERMEASURE \S SMI-439608: validity must be ensured by user.

  \ID SBSW_vMemAccM_MultiPartitionJobPointer
   \DESCRIPTION During the multi partiton use case "single NV RAM accessor" the vMemAccM satellite partition exchanged job parameters
                with the master partition.
                Depending on configuration the variables are only available as addresses (slave partition) or are declared by the vMemAccM module
                (master partition). To provide one single interface to the implementation the module uses pointers pointing to
                either the address or the variable.
                The pointers are never null and shall always point to a valid value.
   \COUNTERMEASURE \S SMI-439608: validity must be ensured by user.

  \ID SBSW_vMemAccM_MngmtAreas
   \DESCRIPTION Array write access: vMemAccM stores runtime information about each address area within an array. It will be
                setup/ initialized during the module initialization for all address areas and accessed via address area ID during runtime.
   \COUNTERMEASURE \R vMemAccM access the management array via address area IDs passed to the module as parameters. Parameter checks ensure
                      correctness.
  
  \ID SBSW_vMemAccM_Queue
   \DESCRIPTION Array write access: vMemAccM stores its jobs within a queue, implemented as an array. The queue will be
                setup/ initialized during the module initialization for all address areas and accessed via address area priority.
   \COUNTERMEASURE \R vMemAccM access the queue array via address area priorities mapped directly via address area IDs. Parameter checks ensure
                      correctness of each passed address area ID. vMemAccM is responsible for queue usage.

  \ID SBSW_vMemAccM_BufferOverwrite
   \DESCRIPTION Array write access: The ReadBlank service needs to directly access the data pointer given by the user to fill it with appropriate
                values in case the page is blank.
   \COUNTERMEASURE \R vMemAccM makes sure that the parameters used for copying will always be in range of the user data buffer for a given job.
  
  \ID SBSW_vMemAccM_UserDataPointer
   \DESCRIPTION Function call with pointer parameter: vMemAccM gets an user buffer as pointer parameter, stores the pointer in its job queue,
                forwards the parameter through its sub modules and finally forwards the parameter to the vMem. vMemAccM never writes into
                the buffer, it just reads from the buffer during a compare job.
   \COUNTERMEASURE \R vMemAccM checks the passed user buffer to be != NULL_PTR. User is responsible for buffer correctness.
  
  \ID SBSW_vMemAccM_LocalDataPointer
   \DESCRIPTION Function call with pointer as parameter.
                vMemAccM_MemAbRead() is forwarded a local read buffer together with the corresponding buffer length.
   \COUNTERMEASURE \N The forwarding of a valid pointer towards the read buffer can be easily checked by review.

  \ID SBSW_vMemAccM_PointerPassedToMemAb
   \DESCRIPTION Memory Abstraction function are called with pointer parameter. 
                MemAb Read, Write, Erase, IsBlank set the processed length within a variable which was forwarded as pointer.
                MemAb Read and Write additionally are forwarded required user buffers for the write or read job execution.
   \COUNTERMEASURE \N The forwarding of a valid pointer can be easily checked by review.
                      The variable for the processed length is created locally.
                      The user buffer is checked by vMemAccM to be != NULL_PTR. User is responsible for buffer correctness.

  \ID SBSW_vMemAccM_UserPointer
   \DESCRIPTION Pointer write access: vMemAccM gets a pointer to write information to. vMemAccM expects the pointer to be
                typed correctly and will use it, if it is != NULL_PTR.
   \COUNTERMEASURE \R vMemAccM checks the passed pointer to be != NULL_PTR. User is responsible for pointer correctness.
  
  \ID SBSW_vMemAccM_PointerChecker
   \DESCRIPTION Function call with pointer parameter: vMemAccM uses a pointer checker function to implement the != NULL check.
                All void* pointers will be forwarded to the function.
   \COUNTERMEASURE \R vMemAccM pointer checker function does not access the pointer, it just checks the pointer to be != NULL
                      (the function implements the runtime pointer check).

  \ID SBSW_vMemAccM_SMTransitionFunction
    \DESCRIPTION Function Pointer Call: A function pointer is used to determine the transitions which shall follow the function call.
                 This measure was taken to make it possible to reuse the same functionality, where only the following transitions differ.
    \COUNTERMEASURE \R The user is responsible for providing the correct functions which shall follow. Tests shall verify the correct behavior.

  \ID SBSW_vMemAccM_AlternatevMemPointerTable
    \DESCRIPTION Array write acces, Function Pointer Call: An additional array of function pointer tables allows the usage of alternate vMems during runtime. 
                 Therefore a function pointer table of an alternate vMem must be set and reset within the array by forwarding correct pointer and index.
    \COUNTERMEASURE \R Forwarding a valid pointer to a vMem function pointer table is ensured by previous explicit verification of vMem header and footer.
                       Forwarding a valid index is ensured by comparing the header value of the alternate with the available pre-configured vMems:
                       It is ensured only a valid index will be forwarded.

SBSW_JUSTIFICATION_END */

/* COV_JUSTIFICATION_BEGIN

Code coverage:
  - none

Variant coverage:

  \ID COV_VMEMACCM_COMPATIBILITY
   \ACCEPT TX
   \REASON COV_MSR_COMPATIBILITY

\ID COV_VMEMACCM_ERASEVALUE
   \ACCEPT TX
   \REASON VMEMACCM_ERASEVALUE is a macro with default value 0xFF. For special use cases where 0xFF does not match the actual 
           erase value, the integrator is allowed to overwrite the macro. vMemAccM does not take care about the value.
           The erase value does not affect the vMemAccM functionality.
  

COV_JUSTIFICATION_END */


/**********************************************************************************************************************
 *  END OF FILE: vMemAccM.c
 *********************************************************************************************************************/
