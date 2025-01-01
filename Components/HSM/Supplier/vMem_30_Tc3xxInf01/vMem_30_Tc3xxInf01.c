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
/*!        \file  vMem_30_Tc3xxInf01.c
 *        \brief  vMem_30_Tc3xxInf01 source file
 *
 *      \details  See vMem_30_Tc3xxInf01.h
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

#define VMEM_30_TC3XXINF01_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "vMem_30_Tc3xxInf01.h"
#include "vMem_30_Tc3xxInf01_Int.h"
#include "vMem_30_Tc3xxInf01_LL.h"
#include "vMem_30_Tc3xxInf01_DetChecks.h"
#if (VMEM_30_TC3XXINF01_DEV_ERROR_REPORT == STD_ON)
# include "Det.h"
#endif

/**********************************************************************************************************************
 *  VERSION CHECK
 *********************************************************************************************************************/

/* Check the version of vMem_30_Tc3xxInf01 header file */
#if (  (VMEM_30_TC3XXINF01_SW_MAJOR_VERSION != (3u)) \
    || (VMEM_30_TC3XXINF01_SW_MINOR_VERSION != (1u)) \
    || (VMEM_30_TC3XXINF01_SW_PATCH_VERSION != (0u)) )
# error "Vendor specific version numbers of vMem_30_Tc3xxInf01.c and vMem_30_Tc3xxInf01.h are inconsistent"
#endif

/* Check the version of the configuration header file */
#if (  (VMEM_30_TC3XXINF01_CFG_COMP_MAJOR_VERSION != (1u)) \
    || (VMEM_30_TC3XXINF01_CFG_COMP_MINOR_VERSION != (5u)) )
# error "Version numbers of vMem_30_Tc3xxInf01.c and vMem_30_Tc3xxInf01_Cfg.h are inconsistent!"
#endif

/* Check the version of vMemAccM_vMemApi file */
#if (  (VMEMACCM_VMEMAPI_MAJOR_VERSION != (4u)) \
    || (VMEMACCM_VMEMAPI_MINOR_VERSION != (0u)) )
# error "Version numbers of vMem_30_Tc3xxInf01.c and vMemAccM_vMemApi.h are inconsistent!"
#endif

/**********************************************************************************************************************
 *  LOCAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

#if !defined (VMEM_30_TC3XXINF01_LOCAL) /* COV_VMEM_30_TC3XXINF01_COMPATIBILITY */
# define VMEM_30_TC3XXINF01_LOCAL static
#endif

/**********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 *********************************************************************************************************************/
/*! The lower 20-bits of the generated identifier are used as the unique driver identifier. */
# define VMEM_30_TC3XXINF01_ID_MASK_VALUE  0x000FFFFFuL

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
/*! Unique identifier of the vMem_30_Tc3xxInf01 based on the below identifiers.
 * VMEM_30_TC3XXINF01_DRIVER_ID -> Unique vMem_30_Tc3xxInf01 driver identifier. This value is generated.
 * VMEMACCM_VMEMAPI_MAJOR_VERSION -> vMemAccM to vMem_30_Tc3xxInf01 interface version. */

# define VMEM_30_TC3XXINF01_UNIQUEID (uint32)(0u | (((uint32)VMEMACCM_VMEMAPI_MAJOR_VERSION) << 24u) | (VMEM_30_TC3XXINF01_DRIVER_ID & VMEM_30_TC3XXINF01_ID_MASK_VALUE))

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

#define VMEM_30_TC3XXINF01_START_SEC_FOOTER_CONST_32BIT
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
/*! The vMem_30_Tc3xxInf01 footer will be placed at the end of the vMem_30_Tc3xxInf01 (after the code, data, etc.) and marks the end of the driver.
 * Since, this variable is not used outside of vMem_30_Tc3xxInf01 and accessed only via FPT, this can be made static. */
VMEM_30_TC3XXINF01_LOCAL CONST(uint32, AUTOMATIC) vMem_30_Tc3xxInf01_Footer = VMEM_30_TC3XXINF01_UNIQUEID;

#define VMEM_30_TC3XXINF01_STOP_SEC_FOOTER_CONST_32BIT
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define VMEM_30_TC3XXINF01_START_SEC_HEADER_CONST_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! Global API pointer table definition.
 * The vMem_30_Tc3xxInf01 hardware specific extended functionality is defined within LowLevel. */
CONST(vMemAccM_vMemApiType, AUTOMATIC) vMem_30_Tc3xxInf01_FunctionPointerTable = {
  VMEM_30_TC3XXINF01_UNIQUEID,
  &vMem_30_Tc3xxInf01_FunctionPointerTable.Header,
  &vMem_30_Tc3xxInf01_Footer,
  {
    VMEM_30_TC3XXINF01_EXTENDED_FUNCTION_COUNT,
    VMEM_30_TC3XXINF01_EXTENDED_FUNCTION_TABLE
  },
  &vMem_30_Tc3xxInf01_Init,
  &vMem_30_Tc3xxInf01_Read,
  &vMem_30_Tc3xxInf01_Write,
  &vMem_30_Tc3xxInf01_Erase,
  &vMem_30_Tc3xxInf01_IsBlank,
  &vMem_30_Tc3xxInf01_GetJobResult,
  &vMem_30_Tc3xxInf01_MainFunction
};

#define VMEM_30_TC3XXINF01_STOP_SEC_HEADER_CONST_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/
#define VMEM_30_TC3XXINF01_START_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
/**********************************************************************************************************************
 *  vMem_30_Tc3xxInf01_Read()
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
FUNC(Std_ReturnType, VMEM_30_TC3XXINF01_CODE) vMem_30_Tc3xxInf01_Read(
  vMem_30_Tc3xxInf01_InstanceIdType InstanceId,
  vMem_30_Tc3xxInf01_AddressType SourceAddress,
  vMem_30_Tc3xxInf01_DataPtrType TargetAddressPtr,
  vMem_30_Tc3xxInf01_LengthType Length
  )
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 errorId = VMEM_30_TC3XXINF01_E_NO_ERROR;
  Std_ReturnType retVal = E_NOT_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */
  
  /* ----- Development Error Checks ------------------------------------- */
#if (VMEM_30_TC3XXINF01_DEV_ERROR_DETECT == STD_ON)
  if (vMem_30_Tc3xxInf01_IsInstanceIdValid(InstanceId) == FALSE)
  {
    errorId = VMEM_30_TC3XXINF01_E_PARAM_INSTANCE_ID;
  }
  else if (vMem_30_Tc3xxInf01_InstancePendingCheck(InstanceId) == TRUE)
  {
    errorId = VMEM_30_TC3XXINF01_E_PENDING;
  }
  else if (TargetAddressPtr == NULL_PTR)
  {
    errorId = VMEM_30_TC3XXINF01_E_PARAM_POINTER;
  }
  else if(vMem_30_Tc3xxInf01_ReadAddressCheck(InstanceId, SourceAddress) == FALSE)
  {
      errorId = VMEM_30_TC3XXINF01_E_PARAM_ADDRESS;
  }
  else if (vMem_30_Tc3xxInf01_ReadLengthCheck(InstanceId, SourceAddress, Length) == FALSE)
  {
      errorId = VMEM_30_TC3XXINF01_E_PARAM_LENGTH;
  }
  else
#endif
  {
    /* ----- Implementation ----------------------------------------------- */
    retVal = vMem_30_Tc3xxInf01_LLRead(InstanceId, SourceAddress, TargetAddressPtr, Length); /* SBSW_vMem_30_Tc3xxInf01_UserPointer */
  }
  
  /* ----- Development Error Report --------------------------------------- */
#if (VMEM_30_TC3XXINF01_DEV_ERROR_REPORT == STD_ON)
  if (errorId != VMEM_30_TC3XXINF01_E_NO_ERROR)
  {
    (void)Det_ReportError(VMEM_30_TC3XXINF01_MODULE_ID, VMEM_30_TC3XXINF01_INSTANCE_ID_DET, VMEM_30_TC3XXINF01_SID_READ, errorId);
  }
#else
  VMEM_30_TC3XXINF01_DUMMY_STATEMENT(errorId); /* PRQA S 2983 */ /* MD_MSR_DummyStmt */
#endif

  return retVal;
} /* vMem_30_Tc3xxInf01_Read() */ /* PRQA S 6080 */ /* MD_MSR_STMIF */

/**********************************************************************************************************************
 *  vMem_30_Tc3xxInf01_Write()
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
FUNC(Std_ReturnType, VMEM_30_TC3XXINF01_CODE) vMem_30_Tc3xxInf01_Write(
  vMem_30_Tc3xxInf01_InstanceIdType InstanceId,
  vMem_30_Tc3xxInf01_AddressType TargetAddress,
  vMem_30_Tc3xxInf01_ConstDataPtrType SourceAddressPtr,
  vMem_30_Tc3xxInf01_LengthType Length
  )
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 errorId = VMEM_30_TC3XXINF01_E_NO_ERROR;
  Std_ReturnType retVal = E_NOT_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  /* ----- Development Error Checks ------------------------------------- */
#if (VMEM_30_TC3XXINF01_DEV_ERROR_DETECT == STD_ON)
  if (vMem_30_Tc3xxInf01_IsInstanceIdValid(InstanceId) == FALSE)
  {
    errorId = VMEM_30_TC3XXINF01_E_PARAM_INSTANCE_ID;
  }
  else if (vMem_30_Tc3xxInf01_InstancePendingCheck(InstanceId) == TRUE)
  {
    errorId = VMEM_30_TC3XXINF01_E_PENDING;
  }
  else if (SourceAddressPtr == NULL_PTR)
  {
    errorId = VMEM_30_TC3XXINF01_E_PARAM_POINTER;
  }
  else if(vMem_30_Tc3xxInf01_IsAddressPageAligned(InstanceId, TargetAddress) == FALSE)
  {
      errorId = VMEM_30_TC3XXINF01_E_PARAM_ADDRESS;
  }
  else if (vMem_30_Tc3xxInf01_WriteLengthCheck(InstanceId, TargetAddress, Length) == FALSE)
  {
      errorId = VMEM_30_TC3XXINF01_E_PARAM_LENGTH;
  }
  else
#endif
  {
    /* ----- Implementation ----------------------------------------------- */
    retVal = vMem_30_Tc3xxInf01_LLWrite(InstanceId, TargetAddress, SourceAddressPtr, Length); /* SBSW_vMem_30_Tc3xxInf01_UserPointer */
  }

  /* ----- Development Error Report --------------------------------------- */
#if (VMEM_30_TC3XXINF01_DEV_ERROR_REPORT == STD_ON)
  if (errorId != VMEM_30_TC3XXINF01_E_NO_ERROR)
  {
    (void)Det_ReportError(VMEM_30_TC3XXINF01_MODULE_ID, VMEM_30_TC3XXINF01_INSTANCE_ID_DET, VMEM_30_TC3XXINF01_SID_WRITE, errorId);
  }
#else
  VMEM_30_TC3XXINF01_DUMMY_STATEMENT(errorId); /* PRQA S 2983 */ /* MD_MSR_DummyStmt */
#endif

  return retVal;
} /* vMem_30_Tc3xxInf01_Write() */ /* PRQA S 6080 */ /* MD_MSR_STMIF */


/**********************************************************************************************************************
 *  vMem_30_Tc3xxInf01_Erase()
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
FUNC(Std_ReturnType, VMEM_30_TC3XXINF01_CODE) vMem_30_Tc3xxInf01_Erase(
  vMem_30_Tc3xxInf01_InstanceIdType InstanceId,
  vMem_30_Tc3xxInf01_AddressType TargetAddress,
  vMem_30_Tc3xxInf01_LengthType Length
  )
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 errorId = VMEM_30_TC3XXINF01_E_NO_ERROR;
  Std_ReturnType retVal = E_NOT_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  /* ----- Development Error Checks ------------------------------------- */
#if (VMEM_30_TC3XXINF01_DEV_ERROR_DETECT == STD_ON)
  if (vMem_30_Tc3xxInf01_IsInstanceIdValid(InstanceId) == FALSE)
  {
    errorId = VMEM_30_TC3XXINF01_E_PARAM_INSTANCE_ID;
  }
  else if (vMem_30_Tc3xxInf01_InstancePendingCheck(InstanceId) == TRUE)
  {
    errorId = VMEM_30_TC3XXINF01_E_PENDING;
  }
  else if(vMem_30_Tc3xxInf01_IsAddressSectorAligned(InstanceId, TargetAddress) == FALSE)
  {
      errorId = VMEM_30_TC3XXINF01_E_PARAM_ADDRESS;
  }
  else if (vMem_30_Tc3xxInf01_EraseLengthCheck(InstanceId, TargetAddress, Length) == FALSE)
  {
      errorId = VMEM_30_TC3XXINF01_E_PARAM_LENGTH;
  }
  else
#endif
  {
    /* ----- Implementation ----------------------------------------------- */
    retVal = vMem_30_Tc3xxInf01_LLErase(InstanceId, TargetAddress, Length);
  }

  /* ----- Development Error Report --------------------------------------- */
#if (VMEM_30_TC3XXINF01_DEV_ERROR_REPORT == STD_ON)
  if (errorId != VMEM_30_TC3XXINF01_E_NO_ERROR)
  {
    (void)Det_ReportError(VMEM_30_TC3XXINF01_MODULE_ID, VMEM_30_TC3XXINF01_INSTANCE_ID_DET, VMEM_30_TC3XXINF01_SID_ERASE, errorId);
  }
#else
  VMEM_30_TC3XXINF01_DUMMY_STATEMENT(errorId); /* PRQA S 2983 */ /* MD_MSR_DummyStmt */
#endif

  return retVal;
} /* vMem_30_Tc3xxInf01_Erase() */ /* PRQA S 6080 */ /* MD_MSR_STMIF */

/**********************************************************************************************************************
 *  vMem_30_Tc3xxInf01_IsBlank()
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
FUNC(Std_ReturnType, VMEM_30_TC3XXINF01_CODE) vMem_30_Tc3xxInf01_IsBlank(
  vMem_30_Tc3xxInf01_InstanceIdType InstanceId,
  vMem_30_Tc3xxInf01_AddressType TargetAddress,
  vMem_30_Tc3xxInf01_LengthType Length
  )
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 errorId = VMEM_30_TC3XXINF01_E_NO_ERROR;
  Std_ReturnType retVal = E_NOT_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  /* ----- Development Error Checks ------------------------------------- */
#if (VMEM_30_TC3XXINF01_DEV_ERROR_DETECT == STD_ON)
  if (vMem_30_Tc3xxInf01_IsInstanceIdValid(InstanceId) == FALSE)
  {
    errorId = VMEM_30_TC3XXINF01_E_PARAM_INSTANCE_ID;
  }
  else if (vMem_30_Tc3xxInf01_InstancePendingCheck(InstanceId) == TRUE)
  {
    errorId = VMEM_30_TC3XXINF01_E_PENDING;
  }
  else if(vMem_30_Tc3xxInf01_IsAddressPageAligned(InstanceId, TargetAddress) == FALSE)
  {
      errorId = VMEM_30_TC3XXINF01_E_PARAM_ADDRESS;
  }
  else if (vMem_30_Tc3xxInf01_IsBlankLengthCheck(InstanceId, TargetAddress, Length) == FALSE)
  {
      errorId = VMEM_30_TC3XXINF01_E_PARAM_LENGTH;
  }
  else
#endif
  {
    /* ----- Implementation ----------------------------------------------- */
    retVal = vMem_30_Tc3xxInf01_LLIsBlank(InstanceId, TargetAddress, Length);
  }

  /* ----- Development Error Report --------------------------------------- */
#if (VMEM_30_TC3XXINF01_DEV_ERROR_REPORT == STD_ON)
  if (errorId != VMEM_30_TC3XXINF01_E_NO_ERROR)
  {
    (void)Det_ReportError(VMEM_30_TC3XXINF01_MODULE_ID, VMEM_30_TC3XXINF01_INSTANCE_ID_DET, VMEM_30_TC3XXINF01_SID_IS_BLANK, errorId);
  }
#else
  VMEM_30_TC3XXINF01_DUMMY_STATEMENT(errorId); /* PRQA S 2983 */ /* MD_MSR_DummyStmt */
#endif

  return retVal;
} /* vMem_30_Tc3xxInf01_IsBlank() */ /* PRQA S 6080 */ /* MD_MSR_STMIF */

/**********************************************************************************************************************
 *  vMem_30_Tc3xxInf01_GetJobResult()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(vMem_30_Tc3xxInf01_JobResultType, VMEM_30_TC3XXINF01_CODE) vMem_30_Tc3xxInf01_GetJobResult(
  vMem_30_Tc3xxInf01_InstanceIdType InstanceId)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 errorId = VMEM_30_TC3XXINF01_E_NO_ERROR;
  vMem_30_Tc3xxInf01_JobResultType jobResult = VMEM_JOB_FAILED; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  /* ----- Development Error Checks ------------------------------------- */
#if (VMEM_30_TC3XXINF01_DEV_ERROR_DETECT == STD_ON)
  if (vMem_30_Tc3xxInf01_IsInstanceIdValid(InstanceId) == FALSE)
  {
    errorId = VMEM_30_TC3XXINF01_E_PARAM_INSTANCE_ID;
  }
  else
#endif
  {
  /* ----- Implementation ----------------------------------------------- */
    jobResult = vMem_30_Tc3xxInf01_LLGetJobResult(InstanceId);
  }

  /* ----- Development Error Report --------------------------------------- */
#if (VMEM_30_TC3XXINF01_DEV_ERROR_REPORT == STD_ON)
  if (errorId != VMEM_30_TC3XXINF01_E_NO_ERROR)
  {
    (void)Det_ReportError(VMEM_30_TC3XXINF01_MODULE_ID, VMEM_30_TC3XXINF01_INSTANCE_ID_DET, VMEM_30_TC3XXINF01_SID_GET_JOB_RESULT, errorId);
  }
#else
  VMEM_30_TC3XXINF01_DUMMY_STATEMENT(errorId); /* PRQA S 2983 */ /* MD_MSR_DummyStmt */
#endif

  return jobResult;
} /* vMem_30_Tc3xxInf01_GetJobResult() */


/**********************************************************************************************************************
 *  vMem_30_Tc3xxInf01_Init()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(void, VMEM_30_TC3XXINF01_CODE) vMem_30_Tc3xxInf01_Init(vMem_30_Tc3xxInf01_ConfigPtrType ConfigPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 errorId = VMEM_30_TC3XXINF01_E_NO_ERROR;

  /* ----- Implementation ----------------------------------------------- */
  /* Do not use the ConfigPtr, simply ignore the parameter (vMem_30_Tc3xxInf01 is not post build capable yet). */
  if (vMem_30_Tc3xxInf01_LLInit() == E_NOT_OK)
  {
    errorId = VMEM_30_TC3XXINF01_E_INITIALIZATION_FAILED;
  }
#if (VMEM_30_TC3XXINF01_DEV_ERROR_REPORT == STD_ON)
  if (errorId != VMEM_30_TC3XXINF01_E_NO_ERROR)
  {
    (void)Det_ReportError(VMEM_30_TC3XXINF01_MODULE_ID, VMEM_30_TC3XXINF01_INSTANCE_ID_DET, VMEM_30_TC3XXINF01_SID_INIT, errorId);
  }
#else
  VMEM_30_TC3XXINF01_DUMMY_STATEMENT(errorId); /* PRQA S 2983 */ /* MD_MSR_DummyStmt */
#endif
  VMEM_30_TC3XXINF01_DUMMY_STATEMENT(ConfigPtr); /* PRQA S 1338, 2983 */ /* MD_MSR_DummyStmt */
} /* vMem_30_Tc3xxInf01_Init() */


/***********************************************************************************************************************
 *  vMem_30_Tc3xxInf01_MainFunction
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, VMEM_30_TC3XXINF01_CODE) vMem_30_Tc3xxInf01_MainFunction(void)
{
  /* ----- Implementation ----------------------------------------------- */
  vMem_30_Tc3xxInf01_LLProcessing();
} /* vMem_30_Tc3xxInf01_MainFunction */


/**********************************************************************************************************************
 *  vMem_30_Tc3xxInf01_GetVersionInfo()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(void, VMEM_30_TC3XXINF01_CODE) vMem_30_Tc3xxInf01_GetVersionInfo(P2VAR(Std_VersionInfoType, AUTOMATIC, VMEM_30_TC3XXINF01_APPL_VAR) VersionInfo)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 errorId = VMEM_30_TC3XXINF01_E_NO_ERROR;

  if (VersionInfo == NULL_PTR)
  {
    errorId = VMEM_30_TC3XXINF01_E_PARAM_POINTER;
  }
  else
  {
    /* ----- Implementation ----------------------------------------------- */
    VersionInfo->vendorID = (VMEM_30_TC3XXINF01_VENDOR_ID); /* SBSW_vMem_30_Tc3xxInf01_UserPointer */
    VersionInfo->moduleID = (VMEM_30_TC3XXINF01_MODULE_ID); /* SBSW_vMem_30_Tc3xxInf01_UserPointer */
    VersionInfo->sw_major_version = (VMEM_30_TC3XXINF01_SW_MAJOR_VERSION); /* SBSW_vMem_30_Tc3xxInf01_UserPointer */
    VersionInfo->sw_minor_version = (VMEM_30_TC3XXINF01_SW_MINOR_VERSION); /* SBSW_vMem_30_Tc3xxInf01_UserPointer */
    VersionInfo->sw_patch_version = (VMEM_30_TC3XXINF01_SW_PATCH_VERSION); /* SBSW_vMem_30_Tc3xxInf01_UserPointer */
  }

  /* ----- Development Error Report --------------------------------------- */
# if (VMEM_30_TC3XXINF01_DEV_ERROR_REPORT == STD_ON)
  if (errorId != VMEM_30_TC3XXINF01_E_NO_ERROR)
  {
    (void)Det_ReportError(VMEM_30_TC3XXINF01_MODULE_ID, VMEM_30_TC3XXINF01_INSTANCE_ID_DET, VMEM_30_TC3XXINF01_SID_GET_VERSION_INFO, errorId);
  }
# else
    VMEM_30_TC3XXINF01_DUMMY_STATEMENT(errorId); /* PRQA S 2983 */ /* MD_MSR_DummyStmt */
# endif
  }


#define VMEM_30_TC3XXINF01_STOP_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* Module specific MISRA deviations:

MD_CRC_2.1_StaticFunctionNotUsed:
    Reason: This inline functions are defined as a utility functionality and shall be accessible by each translation
            unit of the component. In some cases this functionality might not be used. This is not a problem as the
            compiler will optimize this code away in this case.
    Risk: No risk.
    Prevention: A compile switch could be introduced.
    
MD_VMEM_30_TC3XXINF01_CORE_13.5_queries:
     Reason: Functions at right hand of || or && are defined to have no side-effects. Therefore it is intended to omit
             unnecessary calls. Avoiding this deviation would degrade code structure without benefits (nesting of
             IF-clauses).
     Risk: A function HAS side effects, leading to unexpected behavior, if call is omitted.
     Prevention: Review; make sure, that these functions do not change any global value,
                 and that they do not access "volatile" values.

*/


/* SBSW_JUSTIFICATION_BEGIN

\ID SBSW_vMem_30_Tc3xxInf01_UserPointer
 \DESCRIPTION Pointer write access or function call: vMem_30_Tc3xxInf01 gets a pointer to write information to. vMem_30_Tc3xxInf01 expects the pointer to be typed
              correctly and will use it, if it is != NULL_PTR. vMem_30_Tc3xxInf01 writes to the pointer or forwards it to another component internal function.
 \COUNTERMEASURE \R vMem_30_Tc3xxInf01 checks the passed pointer to be != NULL_PTR. User is responsible for pointer correctness.

SBSW_JUSTIFICATION_END */

/* START_COVERAGE_JUSTIFICATION

Variant coverage:

\ID COV_VMEM_30_TC3XXINF01_COMPATIBILITY
 \ACCEPT TX
 \REASON COV_MSR_COMPATIBILITY

\ID COV_VMEM_30_TC3XXINF01_UTILITYCODE_UNUSED
 \ACCEPT X
 \REASON vMem_30_Tc3xxInf01_core is the hardware independent base (and template) for all hardware dependent versions. It provides a
         header file vMem_30_Tc3xxInf01_IntShared.h with shared utility code that may be used from all subcomponents of vMem_30_Tc3xxInf01. The
         core variant uses this code only for development error checks and therefore is not used in some configuration
         variants at all.

END_COVERAGE_JUSTIFICATION
*/

/**********************************************************************************************************************
 *  END OF FILE: vMem_30_Tc3xxInf01.c
 *********************************************************************************************************************/
