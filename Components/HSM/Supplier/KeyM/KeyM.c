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
/*!        \file  KeyM.c
 *         \unit  *
 *        \brief  KeyM source file
 *      \details  Implementation of AUTOSAR Key Manager
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

#define KEYM_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "KeyM.h"
#include "KeyM_Cert.h"
#include "KeyM_Remote.h"
#include "KeyM_Utils.h"

#if (KEYM_DEV_ERROR_REPORT == STD_ON)
# include "Det.h"
#endif

#include "vstdlib.h"

/**********************************************************************************************************************
 *  VERSION CHECK
 *********************************************************************************************************************/
/* Check the version of KeyM header file */
#if (  (KEYM_SW_MAJOR_VERSION != (4u)) \
    || (KEYM_SW_MINOR_VERSION != (2u)) \
    || (KEYM_SW_PATCH_VERSION != (1u)) )
# error "Vendor specific version numbers of KeyM.c and KeyM.h are inconsistent"
#endif

/**********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 *********************************************************************************************************************/
#if !defined (KEYM_LOCAL) /* COV_KEYM_LOCAL_DEFINE */
# define KEYM_LOCAL                                                   static
#endif

#if !defined (KEYM_LOCAL_INLINE) /* COV_KEYM_LOCAL_DEFINE */
# define KEYM_LOCAL_INLINE                                            LOCAL_INLINE
#endif

#if !defined (KEYM_E_GLOBAL_LOCK) /* COV_KEYM_LOCAL_DEFINE */
# define KEYM_E_GLOBAL_LOCK                                           E_NOT_OK
#endif
/**********************************************************************************************************************
 *  LOCAL DATA PROTOTYPES
 *********************************************************************************************************************/

#define KEYM_START_SEC_VAR_CLEARED_8
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* Initialization state of the module */
#if (KEYM_DEV_ERROR_DETECT == STD_ON)
VAR(uint8, KEYM_VAR_ZERO_INIT) KeyM_ModuleInitialized = KEYM_UNINIT;
#endif

#define KEYM_STOP_SEC_VAR_CLEARED_8
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define KEYM_START_SEC_VAR_NO_INIT_8
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* KeyM_MainFunctionLock used for controlling calling of KeyM_Cert_MainFunction
 * in either KeyM_MainBackgroundFunction or KeyM_MainFunction.
 * Needed if both main functions are mapped to different tasks
 * No effect if both main functions are mapped to same task. */
KEYM_LOCAL VAR(boolean, KEYM_VAR_NO_INIT) KeyM_MainFunctionLock;

#define KEYM_STOP_SEC_VAR_NO_INIT_8
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * KeyM_SetCertificateInternal()
 *********************************************************************************************************************/
/*! \copydoc KeyM_SetCertificateWithConstPtr()
 *  \param[out]    errorId                              Det error code that shall be reported by the caller.
 *  Implements the functionality of KeyM_SetCertificateWithConstPtr and, if applicable, outputs the Det error
 *  to report. Is called by KeyM_SetCertificate and KeyM_SetCertificateWithConstPtr and each function uses its own
 *  API ID to report any Det error that might have occurred.
 * \pre errorId must be a valid pointer
 *********************************************************************************************************************/
KEYM_LOCAL FUNC(Std_ReturnType, KEYM_CODE) KeyM_SetCertificateInternal(
  KeyM_CertificateIdType CertId,
  P2CONST(KeyM_ConstCertDataType, AUTOMATIC, KEYM_APPL_DATA) CertificateDataPtr,
  P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) errorId);

/**********************************************************************************************************************
 * KeyM_VerifyCertificateChainInternal()
 *********************************************************************************************************************/
/*! \copydoc KeyM_VerifyCertificateChainWithConstPtr()
 *  \param[out]    errorId                              Det error code that shall be reported by the caller.
 *  Implements the functionality of KeyM_VerifyCertificateChainWithConstPtr and, if applicable, outputs the Det error
 *  to report. Is called by KeyM_VerifyCertificateChain and KeyM_VerifyCertificateChainWithConstPtr and each function
 *  uses its own API ID to report any Det error that might have occurred.
 * \pre errorId must be a valid pointer
 *********************************************************************************************************************/
KEYM_LOCAL FUNC(Std_ReturnType, KEYM_CODE) KeyM_VerifyCertificateChainInternal(
  KeyM_CertificateIdType CertId,
  P2CONST(KeyM_ConstCertDataType, AUTOMATIC, KEYM_APPL_DATA) certChainData,
  uint8 NumberOfCertificates,
  P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) errorId);

/**********************************************************************************************************************
 * KeyM_CheckVerifyCertificateChainData()
 *********************************************************************************************************************/
/*! \brief         Checks the passed certChainData elements for integrity
 *  \details       Returns E_NOT_OK if NumberOfCertificates is > KEYM_CERTIFICATE_CHAIN_MAX_DEPTH or
 *                 one or more of certChainData's elements has a NULL_PTR as certData member.
 *  \param[in]     certChainData                        Pointer to an array of certificates.
 *  \param[in]     NumberOfCertificates                 Number of elements in certChainData.
 *  \param[out]    errorId                              Det error code that shall be reported by the caller.
 *  \return        E_OK                                 certChainData and NumberOfCertificates have valid values.
 *                 E_NOT_OK                             NumberOfCertificates is > KEYM_CERTIFICATE_CHAIN_MAX_DEPTH or
 *                                                      one or more of certChainData's elements has a NULL_PTR
 *                                                      as certData member.
 *  \pre           All provided pointers must be valid.
 *                 Note: The pointers contained in certChainData can be nullpointers, as this is checked at runtime.
 *  \context       TASK
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
KEYM_LOCAL_INLINE FUNC(Std_ReturnType, KEYM_CODE) KeyM_CheckVerifyCertificateChainData(
  P2CONST(KeyM_ConstCertDataType, AUTOMATIC, KEYM_APPL_DATA) certChainData,
  uint8 NumberOfCertificates,
  P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) errorId);

/**********************************************************************************************************************
 * KeyM_GetGlobalLock()
 *********************************************************************************************************************/
/*! \brief         Requests global lock for processing synchronous API calls.
 *  \details       -
 *  \return        TRUE  Lock obtained
 *                 FALSE Lock not obtained
 *  \pre           -
 *  \context       TASK
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_GetGlobalLock(void);

/**********************************************************************************************************************
 * KeyM_FreeGlobalLock()
 *********************************************************************************************************************/
/*! \brief         Frees the previously obtained global lock.
 *  \details       -
 *  \pre           Only to be called when lock has been previously obtained
 *  \note          To be used for API calls that read-modify-write the KeyM_Cert_TaskState.
 *  \context       TASK
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
KEYM_LOCAL_INLINE FUNC(void, KEYM_CODE) KeyM_FreeGlobalLock(void);

/**********************************************************************************************************************
 * KeyM_GetGlobalLock_CheckTaskState()
 *********************************************************************************************************************/
/*! \brief         Requests the global lock for processing synchronous calls if KeyM_Cert_TaskState is IDLE.
 *  \details       -
 *  \return        TRUE  Lock obtained
 *                 FALSE Lock not obtained
 *  \pre           -
 *  \note          To be used for API calls that do not read-modify-write the KeyM_Cert_TaskState.
 *  \context       TASK
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_GetGlobalLock_CheckTaskState(void);

#if (KEYM_CERTIFICATE_SIGNING_REQUEST_ENABLED == STD_ON)
/**********************************************************************************************************************
 * KeyM_CheckCsrInfoData()
 *********************************************************************************************************************/
/*! \brief         Checks the passed CsrInfo elements for integrity
 *  \details       Returns E_NOT_OK if one or more CsrInfo's elements has a NULL_PTR as certData member.
 *  \param[in]     CsrInfo                              Points to an array of request data objects.
 *  \param[in]     numOfReqObjects                      Number of elements in CsrInfo.
 *  \param[out]    errorId                              Det error code that shall be reported by the caller.
 *  \return        E_OK                                 CsrInfo has valid values.
 *                 E_NOT_OK                             One or more of CsrInfo's elements has a NULL_PTR
 *                                                      as dataPtr member.
 *  \pre           All provided pointers must be valid.
 *                 Note: The pointers contained in CsrInfo can be nullpointers, as this is checked at runtime.
 *  \context       TASK
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
KEYM_LOCAL_INLINE FUNC(Std_ReturnType, KEYM_CODE) KeyM_CheckCsrInfoData(
  P2CONST(KeyM_CSRInfoType, AUTOMATIC, KEYM_APPL_DATA) CsrInfo,
  uint8 numOfReqObjects,
  P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) errorId);
#endif

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

#ifndef KEYM_NOUNIT_CERTIFICATESERVICES /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_SetCertificateInternal()
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
KEYM_LOCAL FUNC(Std_ReturnType, KEYM_CODE) KeyM_SetCertificateInternal(
  KeyM_CertificateIdType CertId,
  P2CONST(KeyM_ConstCertDataType, AUTOMATIC, KEYM_APPL_DATA) CertificateDataPtr,
  P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) errorId)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */
  *errorId = KEYM_E_NO_ERROR;

  /* ----- Development Error Checks ------------------------------------- */
# if (KEYM_DEV_ERROR_DETECT == STD_ON)
  /* # Check initialization state of the component */
  if (!KeyM_IsInitialized())
  {
    *errorId = KEYM_E_UNINIT;
  }
  else if ((CertificateDataPtr == NULL_PTR)
    || (CertificateDataPtr->certData == NULL_PTR))
  {
    /* [SWS_KeyM_00146] */
    *errorId = KEYM_E_PARAM_POINTER;
  }
  else
# endif
  {
    /* ----- Implementation ----------------------------------------------- */
    /* # Check if provided certificate ID is valid and return an error code otherwise */
    if (CertId >= KeyM_GetSizeOfCertificate())
    {
      retVal = KEYM_E_PARAMETER_MISMATCH;
    }
    /* # If certificate is configured for remote handling, redirect remote service request */
# if (KEYM_REMOTE_REDIRECTION_ENABLED == STD_ON)
    else if (KeyM_GetStorageOfCertificate((KeyM_CertificateIterType)CertId) == KEYM_STORAGE_REMOTE)
    {
      retVal = KeyM_Remote_RedirectSetCertificate(CertId, CertificateDataPtr);
    }
# endif /* KEYM_REMOTE_REDIRECTION_ENABLED */
    /* # Else, call local implementation of KeyM_SetCertificate */
    else
    {
      retVal = KeyM_Cert_SetCertificate(CertId, CertificateDataPtr);
    }
  }

  return retVal;
} /* KeyM_SetCertificateInternal() */
#endif /* ifndef KEYM_NOUNIT_CERTIFICATESERVICES */

#ifndef KEYM_NOUNIT_CERTIFICATESERVICES /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_VerifyCertificateChainInternal()
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
/* PRQA S 6080 1 */ /* MD_MSR_STMIF */
KEYM_LOCAL FUNC(Std_ReturnType, KEYM_CODE) KeyM_VerifyCertificateChainInternal(
  KeyM_CertificateIdType CertId,
  P2CONST(KeyM_ConstCertDataType, AUTOMATIC, KEYM_APPL_DATA) certChainData,
  uint8 NumberOfCertificates,
  P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) errorId)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */
  *errorId = KEYM_E_NO_ERROR; /* PRQA S 2982 */ /* MD_KEYM_2.2 */

  /* ----- Development Error Checks ------------------------------------- */
# if (KEYM_DEV_ERROR_DETECT == STD_ON)
  /* # Check initialization state of the component */
  if (!KeyM_IsInitialized())
  {
    *errorId = KEYM_E_UNINIT;
  }
  /* # Check if provided pointer is a null pointer */
  else if (certChainData == NULL_PTR)
  {
    /* [SWS_KeyM_00146] */
    *errorId = KEYM_E_PARAM_POINTER;
  }
  else
# endif
  {
    /* ----- Implementation ----------------------------------------------- */
    /* # Call KeyM_CheckVerifyCertificateChainData() to check integrity of passed certificate chain data */
    retVal = KeyM_CheckVerifyCertificateChainData(certChainData, NumberOfCertificates, errorId);

    if (retVal == E_OK)
    {
      /* # Check if provided certificate ID is valid and return an error code otherwise */
      if (CertId >= KeyM_GetSizeOfCertificate())
      {
        retVal = KEYM_E_PARAMETER_MISMATCH;
      }
      /* # If certificate is configured for remote handling, redirect remote service request */
# if (KEYM_REMOTE_REDIRECTION_ENABLED == STD_ON)
      else if (KeyM_GetStorageOfCertificate((KeyM_CertificateIterType)CertId) == KEYM_STORAGE_REMOTE)
      {
        retVal = KeyM_Remote_RedirectVerifyCertificateChain(CertId, certChainData, NumberOfCertificates);
      }
# endif /* KEYM_REMOTE_REDIRECTION_ENABLED */
      /* # Else, call local implementation of KeyM_VerifyCertificateChain */
      else
      {
        retVal = KeyM_Cert_VerifyCertificateChain(CertId, certChainData, NumberOfCertificates);
      }
    }
  }

  return retVal;
} /* KeyM_VerifyCertificateChainInternal() */
#endif /* ifndef KEYM_NOUNIT_CERTIFICATESERVICES */

#ifndef KEYM_NOUNIT_CERTIFICATESERVICES /* COV_KEYM_UNITTEST_DEFINE */
 /**********************************************************************************************************************
 *  KeyM_CheckVerifyCertificateChainData()
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
KEYM_LOCAL_INLINE FUNC(Std_ReturnType, KEYM_CODE) KeyM_CheckVerifyCertificateChainData(
  P2CONST(KeyM_ConstCertDataType, AUTOMATIC, KEYM_APPL_DATA) certChainData,
  uint8 NumberOfCertificates,
  P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) errorId)
{
  Std_ReturnType retVal = E_NOT_OK;
  *errorId = KEYM_E_NO_ERROR;

  if (NumberOfCertificates > KEYM_CERTIFICATE_CHAIN_MAX_DEPTH)
  {
    /* leave retVal at E_NOT_OK */
  }
  else
  {
    uint8_least i;
    retVal = E_OK;

    for (i = 0u; i < NumberOfCertificates; i++)
    {
      if (certChainData[i].certData == NULL_PTR)
      {
        retVal = E_NOT_OK;
        *errorId = KEYM_E_PARAM_POINTER; /* [SWS_KeyM_00146] */
        break;
      }
    }
  }

  return retVal;
} /* KeyM_CheckVerifyCertificateChainData() */
#endif /* ifndef KEYM_NOUNIT_CERTIFICATESERVICES */

#if (KEYM_CERTIFICATE_SIGNING_REQUEST_ENABLED == STD_ON)
# ifndef KEYM_NOUNIT_CERTIFICATESERVICES /* COV_KEYM_UNITTEST_DEFINE */
 /**********************************************************************************************************************
 *  KeyM_CheckCsrInfoData()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
KEYM_LOCAL_INLINE FUNC(Std_ReturnType, KEYM_CODE) KeyM_CheckCsrInfoData(
  P2CONST(KeyM_CSRInfoType, AUTOMATIC, KEYM_APPL_DATA) CsrInfo,
  uint8 numOfReqObjects,
  P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) errorId)
{
  Std_ReturnType retVal = E_OK;
  uint8_least i;

  for (i = 0u; i < numOfReqObjects; i++)
  {
    if (CsrInfo[i].dataPtr == NULL_PTR)
    {
      retVal = E_NOT_OK;
      *errorId = KEYM_E_PARAM_POINTER; /* [SWS_KeyM_00146] */
      break;
    }
  }

  return retVal;
} /* KeyM_CheckCsrInfoData() */
# endif /* ifndef KEYM_NOUNIT_CERTIFICATESERVICES */
#endif

#ifndef KEYM_NOUNIT_GENERAL /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_GetGlobalLock()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_GetGlobalLock(void)
{
  boolean gotLock = FALSE;

  /* Check if KeyM is currently busy with other jobs */
  SchM_Enter_KeyM_KEYM_EXCLUSIVE_AREA_0();
  if (KeyM_Cert_GlobalState == KEYM_CERT_TASKSTATE_IDLE)
  {
    KeyM_Cert_GlobalState = KEYM_CERT_TASKSTATE_BUSY;
    gotLock = TRUE;
  }
  SchM_Exit_KeyM_KEYM_EXCLUSIVE_AREA_0();

  return gotLock;
} /* KeyM_GetGlobalLock() */
#endif /* ifndef KEYM_NOUNIT_GENERAL */

#ifndef KEYM_NOUNIT_GENERAL /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_GetGlobalLock_CheckTaskState()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
KEYM_LOCAL_INLINE FUNC(boolean, KEYM_CODE) KeyM_GetGlobalLock_CheckTaskState(void)
{
  boolean gotLock = FALSE;

  /* Check if KeyM is currently busy with other jobs */
  SchM_Enter_KeyM_KEYM_EXCLUSIVE_AREA_0();
  if ((KeyM_Cert_GlobalState == KEYM_CERT_TASKSTATE_IDLE) && (KeyM_Cert_TaskState == KEYM_CERT_TASKSTATE_IDLE))
  {
    KeyM_Cert_GlobalState = KEYM_CERT_TASKSTATE_BUSY;
    gotLock = TRUE;
  }
  SchM_Exit_KeyM_KEYM_EXCLUSIVE_AREA_0();

  return gotLock;
} /* KeyM_GetGlobalLock_CheckTaskState() */
#endif /* ifndef KEYM_NOUNIT_GENERAL */

#ifndef KEYM_NOUNIT_GENERAL /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_FreeGlobalLock()
 *********************************************************************************************************************/
/*!
  * Internal comment removed.
 *
 *
  */
KEYM_LOCAL_INLINE FUNC(void, KEYM_CODE) KeyM_FreeGlobalLock(void)
{
  KeyM_Cert_GlobalState = KEYM_CERT_TASKSTATE_IDLE;
} /* KeyM_FreeGlobalLock() */
#endif /* ifndef KEYM_NOUNIT_GENERAL */

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/
#define KEYM_START_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#ifndef KEYM_NOUNIT_GENERAL /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_InitMemory()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, KEYM_CODE) KeyM_InitMemory(void)
{
  /* ----- Implementation ----------------------------------------------- */
# if (KEYM_DEV_ERROR_DETECT == STD_ON)
  /* # Uninitialize module. */
  KeyM_SetUninitialized();
# endif
} /* KeyM_InitMemory() */
#endif /* ifndef KEYM_NOUNIT_GENERAL */

#ifndef KEYM_NOUNIT_GENERAL /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_Init()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
FUNC(void, KEYM_CODE) KeyM_Init(P2CONST(KeyM_ConfigType, AUTOMATIC, KEYM_APPL_DATA) ConfigPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 errorId = KEYM_E_NO_ERROR;

  /* ----- Development Error Checks ------------------------------------- */
# if (KEYM_DEV_ERROR_DETECT == STD_ON)
  /* # Check initialization state of the component */
  if(KeyM_IsInitialized())
  {
    errorId = KEYM_E_INIT_FAILED;
  }
  else if (ConfigPtr != NULL_PTR)
  {
    /* A Configuration of the Key Manager at initialization is currently not used */
    errorId = KEYM_E_PARAM_POINTER;
  }
  /* # Perform consistency check of configuration */
  else if (KeyM_Cert_Init() != E_OK)
  {
    /* Configuration consistency check of cert submodule failed --> KeyM should not be used */
    errorId = KEYM_E_INVALID_CONFIGURATION;
  }
  else
# endif
  {
    /* ----- Implementation ----------------------------------------------- */
    KeyM_MainFunctionLock = FALSE;

    /* # Call local implementation of KeyM_Init */
# if (KEYM_DEV_ERROR_DETECT == STD_ON)
    /* KeyM_Cert_Init() has already been called in Development Error Checks section */
# else
    (void)KeyM_Cert_Init();
# endif
    KEYM_DUMMY_STATEMENT(ConfigPtr); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */

# if (KEYM_DEV_ERROR_DETECT == STD_ON)
    KeyM_SetInitialized();
# endif
  }

  /* ----- Development Error Report --------------------------------------- */
# if (KEYM_DEV_ERROR_REPORT == STD_ON)
  /* # Report error if applicable */
  if (errorId != KEYM_E_NO_ERROR)
  {
    (void)Det_ReportError(KEYM_MODULE_ID, KEYM_INSTANCE_ID_DET, KEYM_SID_INIT, errorId);
  }
# else
  KEYM_DUMMY_STATEMENT(errorId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
# endif

} /* KeyM_Init() */
#endif /* ifndef KEYM_NOUNIT_GENERAL */

#ifndef KEYM_NOUNIT_GENERAL /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_Deinit()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(void, KEYM_CODE) KeyM_Deinit(void)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 errorId = KEYM_E_NO_ERROR;

  /* ----- Development Error Checks ------------------------------------- */
# if (KEYM_DEV_ERROR_DETECT == STD_ON)
  /* # Check initialization state of the component */
  if(!KeyM_IsInitialized())
  {
    errorId = KEYM_E_UNINIT;
  }
  else
# endif
  {
    /* ----- Implementation ----------------------------------------------- */
    /* # Uninitialize module. */
# if (KEYM_DEV_ERROR_DETECT == STD_ON)
    KeyM_SetUninitialized();
# endif
  }

  /* ----- Development Error Report --------------------------------------- */
# if (KEYM_DEV_ERROR_REPORT == STD_ON)
  /* # Report error if applicable */
  if (errorId != KEYM_E_NO_ERROR)
  {
    (void)Det_ReportError(KEYM_MODULE_ID, KEYM_INSTANCE_ID_DET, KEYM_SID_DEINIT, errorId);
  }
# else
  KEYM_DUMMY_STATEMENT(errorId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
# endif

} /* KeyM_Deinit() */
#endif /* ifndef KEYM_NOUNIT_GENERAL */

#if (KEYM_VERSION_INFO_API == STD_ON)
# ifndef KEYM_NOUNIT_GENERAL /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_GetVersionInfo()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
FUNC(void, KEYM_CODE) KeyM_GetVersionInfo(P2VAR(Std_VersionInfoType, AUTOMATIC, KEYM_APPL_VAR) VersionInfo)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 errorId = KEYM_E_NO_ERROR;

  /* ----- Development Error Checks ------------------------------------- */
#  if (KEYM_DEV_ERROR_DETECT == STD_ON)
  /* # Check initialization state of the component */
  if(!KeyM_IsInitialized())
  {
    errorId = KEYM_E_UNINIT;
  }
  /* # Check if provided pointer is a null pointer */
  else if ((VersionInfo == NULL_PTR))
  {
    /* [SWS_KeyM_00146] */
    errorId = KEYM_E_PARAM_POINTER;
  }
  else
#  endif
  {
    /* ----- Implementation ----------------------------------------------- */
    /* # Write versionInfo pointer with modules versions. */
    VersionInfo->vendorID = (uint16)KEYM_VENDOR_ID;
    VersionInfo->moduleID = (uint8)KEYM_MODULE_ID;
    VersionInfo->sw_major_version = (uint8)KEYM_SW_MAJOR_VERSION;
    VersionInfo->sw_minor_version = (uint8)KEYM_SW_MINOR_VERSION;
    VersionInfo->sw_patch_version = (uint8)KEYM_SW_PATCH_VERSION;
  }

  /* ----- Development Error Report --------------------------------------- */
#  if (KEYM_DEV_ERROR_REPORT == STD_ON)
  /* # Report error if applicable */
  if (errorId != KEYM_E_NO_ERROR)
  {
    (void)Det_ReportError(KEYM_MODULE_ID, KEYM_INSTANCE_ID_DET, KEYM_SID_GET_VERSION_INFO, errorId);
  }
#  else
  KEYM_DUMMY_STATEMENT(errorId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
#  endif

} /* KeyM_GetVersionInfo() */
# endif /* ifndef KEYM_NOUNIT_GENERAL */
#endif /* (KEYM_VERSION_INFO_API == STD_ON) */

#if (KEYM_CRYPTO_KEY_START_FINALIZE_FUNCTION_ENABLED == STD_ON) /* COV_KEYM_CRYPTO_KEY_SUBMODULE */
# ifndef KEYM_NOUNIT_KEYSERVICES /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_Start()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(Std_ReturnType, KEYM_CODE) KeyM_Start(
  KeyM_StartType StartType,
  P2CONST(uint8, AUTOMATIC, KEYM_APPL_DATA) RequestData,
  uint32 RequestDataLength,
  P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) ResponseData,
  P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) ResponseDataLength)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 errorId = KEYM_E_NO_ERROR;
  Std_ReturnType retVal = E_NOT_OK;

  /* ----- Development Error Checks ------------------------------------- */
#  if (KEYM_DEV_ERROR_DETECT == STD_ON)
  /* # Check initialization state of the component */
  if(!KeyM_IsInitialized())
  {
    errorId = KEYM_E_UNINIT;
  }
  /* # Check if provided pointer is a null pointer */
  else if ((RequestData == NULL_PTR)
           || (ResponseData == NULL_PTR)
           || (ResponseDataLength == NULL_PTR))
  {
    /* [SWS_KeyM_00146] */
    errorId = KEYM_E_PARAM_POINTER;
  }
  else
#  endif
  {
    /* ----- Implementation ----------------------------------------------- */
    KEYM_DUMMY_STATEMENT(StartType); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
    KEYM_DUMMY_STATEMENT(RequestData); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
    KEYM_DUMMY_STATEMENT(RequestDataLength); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
    KEYM_DUMMY_STATEMENT(ResponseData); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
    KEYM_DUMMY_STATEMENT(ResponseDataLength); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  }

  /* ----- Development Error Report --------------------------------------- */
#  if (KEYM_DEV_ERROR_REPORT == STD_ON)
  /* # Report error if applicable */
  if (errorId != KEYM_E_NO_ERROR)
  {
    (void)Det_ReportError(KEYM_MODULE_ID, KEYM_INSTANCE_ID_DET, KEYM_SID_START, errorId);
  }
#  else
  KEYM_DUMMY_STATEMENT(errorId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
#  endif

  return retVal;
} /* KeyM_Start() */
# endif /* ifndef KEYM_NOUNIT_KEYSERVICES */
#endif /* (KEYM_CRYPTO_KEY_START_FINALIZE_FUNCTION_ENABLED == STD_ON) */

#if (KEYM_CRYPTO_KEY_PREPARE_FUNCTION_ENABLED == STD_ON) /* COV_KEYM_CRYPTO_KEY_SUBMODULE */
# ifndef KEYM_NOUNIT_KEYSERVICES /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_Prepare()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(Std_ReturnType, KEYM_CODE) KeyM_Prepare(
  P2CONST(uint8, AUTOMATIC, KEYM_APPL_DATA) RequestData,
  uint32 RequestDataLength,
  P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) ResponseData,
  P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) ResponseDataLength)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 errorId = KEYM_E_NO_ERROR;
  Std_ReturnType retVal = E_NOT_OK;

  /* ----- Development Error Checks ------------------------------------- */
#  if (KEYM_DEV_ERROR_DETECT == STD_ON)
  /* # Check initialization state of the component */
  if(!KeyM_IsInitialized())
  {
    errorId = KEYM_E_UNINIT;
  }
  /* # Check if provided pointer is a null pointer */
  else if ((RequestData == NULL_PTR)
           || (ResponseData == NULL_PTR)
           || (ResponseDataLength == NULL_PTR))
  {
    /* [SWS_KeyM_00146] */
    errorId = KEYM_E_PARAM_POINTER;
  }
  else
#  endif
  {
    /* ----- Implementation ----------------------------------------------- */
    KEYM_DUMMY_STATEMENT(RequestData); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
    KEYM_DUMMY_STATEMENT(RequestDataLength); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
    KEYM_DUMMY_STATEMENT(ResponseData); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
    KEYM_DUMMY_STATEMENT(ResponseDataLength); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  }

  /* ----- Development Error Report --------------------------------------- */
#  if (KEYM_DEV_ERROR_REPORT == STD_ON)
  /* # Report error if applicable */
  if (errorId != KEYM_E_NO_ERROR)
  {
    (void)Det_ReportError(KEYM_MODULE_ID, KEYM_INSTANCE_ID_DET, KEYM_SID_PREPARE, errorId);
  }
#  else
  KEYM_DUMMY_STATEMENT(errorId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
#  endif

  return retVal;
} /* KeyM_Prepare() */
# endif /* ifndef KEYM_NOUNIT_KEYSERVICES */
#endif /* (KEYM_CRYPTO_KEY_PREPARE_FUNCTION_ENABLED == STD_ON) */

#ifndef KEYM_NOUNIT_KEYSERVICES /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_Update()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
/* PRQA S 3673, 6060 7 */ /* MD_KEYM_8.13_AutosarAPI, MD_MSR_STPAR */
FUNC(Std_ReturnType, KEYM_CODE) KeyM_Update(
  P2CONST(uint8, AUTOMATIC, KEYM_APPL_DATA) KeyNamePtr,
  uint32 KeyNameLength,
  P2CONST(uint8, AUTOMATIC, KEYM_APPL_DATA) RequestDataPtr,
  uint32 RequestDataLength,
  P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) ResultDataPtr,
  uint32 ResultDataMaxLength)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 errorId = KEYM_E_NO_ERROR;
  Std_ReturnType retVal = E_NOT_OK;

  /* ----- Development Error Checks ------------------------------------- */
# if (KEYM_DEV_ERROR_DETECT == STD_ON)
  /* # Check initialization state of the component */
  if(!KeyM_IsInitialized())
  {
    errorId = KEYM_E_UNINIT;
  }
  /* # Check if provided pointer is a null pointer */
  else if ((KeyNamePtr == NULL_PTR)
           || (RequestDataPtr == NULL_PTR)
           || (ResultDataPtr == NULL_PTR))
  {
    /* [SWS_KeyM_00146] */
    errorId = KEYM_E_PARAM_POINTER;
  }
  else
# endif
  {
    /* ----- Implementation ----------------------------------------------- */
    KEYM_DUMMY_STATEMENT(KeyNamePtr); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
    KEYM_DUMMY_STATEMENT(KeyNameLength); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
    KEYM_DUMMY_STATEMENT(RequestDataPtr); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
    KEYM_DUMMY_STATEMENT(RequestDataLength); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
    KEYM_DUMMY_STATEMENT(ResultDataPtr); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
    KEYM_DUMMY_STATEMENT(ResultDataMaxLength); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  }

  /* ----- Development Error Report --------------------------------------- */
# if (KEYM_DEV_ERROR_REPORT == STD_ON)
  /* # Report error if applicable */
  if (errorId != KEYM_E_NO_ERROR)
  {
    (void)Det_ReportError(KEYM_MODULE_ID, KEYM_INSTANCE_ID_DET, KEYM_SID_UPDATE, errorId);
  }
# else
  KEYM_DUMMY_STATEMENT(errorId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
# endif

  return retVal;
}
#endif /* ifndef KEYM_NOUNIT_KEYSERVICES */

#if (KEYM_CRYPTO_KEY_START_FINALIZE_FUNCTION_ENABLED == STD_ON) /* COV_KEYM_CRYPTO_KEY_SUBMODULE */
# ifndef KEYM_NOUNIT_KEYSERVICES /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_Finalize()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(Std_ReturnType, KEYM_CODE) KeyM_Finalize(void)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 errorId = KEYM_E_NO_ERROR;
  Std_ReturnType retVal = E_NOT_OK;

  /* ----- Development Error Checks ------------------------------------- */
#  if (KEYM_DEV_ERROR_DETECT == STD_ON)
  /* # Check initialization state of the component */
  if(!KeyM_IsInitialized())
  {
    errorId = KEYM_E_UNINIT;
  }
  else
#  endif
  {
    /* ----- Implementation ----------------------------------------------- */
  }

  /* ----- Development Error Report --------------------------------------- */
#  if (KEYM_DEV_ERROR_REPORT == STD_ON)
  /* # Report error if applicable */
  if (errorId != KEYM_E_NO_ERROR)
  {
    (void)Det_ReportError(KEYM_MODULE_ID, KEYM_INSTANCE_ID_DET, KEYM_SID_FINALIZE, errorId);
  }
#  else
  KEYM_DUMMY_STATEMENT(errorId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
#  endif

  return retVal;
} /* KeyM_Finalize() */
# endif /* ifndef KEYM_NOUNIT_KEYSERVICES */
#endif /* (KEYM_CRYPTO_KEY_START_FINALIZE_FUNCTION_ENABLED == STD_ON) */

#if (KEYM_CRYPTO_KEY_VERIFY_FUNCTION_ENABLED == STD_ON) /* COV_KEYM_CRYPTO_KEY_SUBMODULE */
# ifndef KEYM_NOUNIT_KEYSERVICES /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_Verify()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(Std_ReturnType, KEYM_CODE) KeyM_Verify(
  P2CONST(uint8, AUTOMATIC, KEYM_APPL_DATA) KeyNamePtr,
  uint32 KeyNameLength,
  P2CONST(uint8, AUTOMATIC, KEYM_APPL_DATA) RequestData,
  uint32 RequestDataLength,
  P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) ResponseData,
  P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) ResponseDataLength)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 errorId = KEYM_E_NO_ERROR;
  Std_ReturnType retVal = E_NOT_OK;

  /* ----- Development Error Checks ------------------------------------- */
#  if (KEYM_DEV_ERROR_DETECT == STD_ON)
  /* # Check initialization state of the component */
  if(!KeyM_IsInitialized())
  {
    errorId = KEYM_E_UNINIT;
  }
  /* # Check if provided pointer is a null pointer */
  else if((KeyNamePtr == NULL_PTR)
          || (RequestData == NULL_PTR)
          || (ResponseData == NULL_PTR)
          || (ResponseDataLength == NULL_PTR))
  {
    /* [SWS_KeyM_00146] */
    errorId = KEYM_E_PARAM_POINTER;
  }
  else
#  endif
  {
    /* ----- Implementation ----------------------------------------------- */
    KEYM_DUMMY_STATEMENT(KeyNamePtr); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
    KEYM_DUMMY_STATEMENT(KeyNameLength); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
    KEYM_DUMMY_STATEMENT(RequestData); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
    KEYM_DUMMY_STATEMENT(RequestDataLength); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
    KEYM_DUMMY_STATEMENT(ResponseData); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
    KEYM_DUMMY_STATEMENT(ResponseDataLength); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  }

  /* ----- Development Error Report --------------------------------------- */
#  if (KEYM_DEV_ERROR_REPORT == STD_ON)
  /* # Report error if applicable */
  if (errorId != KEYM_E_NO_ERROR)
  {
    (void)Det_ReportError(KEYM_MODULE_ID, KEYM_INSTANCE_ID_DET, KEYM_SID_VERIFY, errorId);
  }
#  else
  KEYM_DUMMY_STATEMENT(errorId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
#  endif

  return retVal;
} /* KeyM_Verify() */
# endif /* ifndef KEYM_NOUNIT_KEYSERVICES */
#endif /* (KEYM_CRYPTO_KEY_VERIFY_FUNCTION_ENABLED == STD_ON) */

#if (KEYM_SERVICE_CERTIFICATE_FUNCTION_ENABLED == STD_ON) /* COV_KEYM_REQUIRED_FOR_SAFE */
# ifndef KEYM_NOUNIT_CERTIFICATESERVICES /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_ServiceCertificate()
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
/* PRQA S 6060 8 */ /* MD_MSR_STPAR */
FUNC(Std_ReturnType, KEYM_CODE) KeyM_ServiceCertificate(
  KeyM_ServiceCertificateType Service,
  P2CONST(uint8, AUTOMATIC, KEYM_APPL_DATA) CertNamePtr,
  uint32 CertNameLength,
  P2CONST(uint8, AUTOMATIC, KEYM_APPL_DATA) RequestData,
  uint32 RequestDataLength,
  P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) ResponseData,
  uint32 ResponseDataLength)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 errorId = KEYM_E_NO_ERROR;
  Std_ReturnType retVal = E_NOT_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  /* ----- Development Error Checks ------------------------------------- */
#  if (KEYM_DEV_ERROR_DETECT == STD_ON)
  /* # Check initialization state of the component */
  if(!KeyM_IsInitialized())
  {
    errorId = KEYM_E_UNINIT;
  }
  /* # Check if provided pointer is a null pointer */
  else if ((CertNamePtr == NULL_PTR)
        || (RequestData == NULL_PTR)
        || (ResponseData == NULL_PTR))
  {
    /* [SWS_KeyM_00146] */
    errorId = KEYM_E_PARAM_POINTER;
  }
  else
#  endif
  if (!KeyM_GetGlobalLock())
  {
    retVal = KEYM_E_BUSY;
  }
  else
  {
    /* ----- Implementation ----------------------------------------------- */
    /* # Call local implementation of KeyM_ServiceCertificate */
    retVal = KeyM_Cert_ServiceCertificate(Service, CertNamePtr, CertNameLength, RequestData, RequestDataLength, ResponseData, ResponseDataLength);

    KeyM_FreeGlobalLock();
  }

  /* ----- Development Error Report --------------------------------------- */
#  if (KEYM_DEV_ERROR_REPORT == STD_ON)
  /* # Report error if applicable */
  if (errorId != KEYM_E_NO_ERROR)
  {
    (void)Det_ReportError(KEYM_MODULE_ID, KEYM_INSTANCE_ID_DET, KEYM_SID_SERVICE_CERTIFICATE, errorId);
  }
#  else
  KEYM_DUMMY_STATEMENT(errorId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
#  endif

  return retVal;
}
# endif /* ifndef KEYM_NOUNIT_CERTIFICATESERVICES */
#endif /* (KEYM_SERVICE_CERTIFICATE_FUNCTION_ENABLED == STD_ON) */

#ifndef KEYM_NOUNIT_CERTIFICATESERVICES /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_SetCertificate()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
FUNC(Std_ReturnType, KEYM_CODE) KeyM_SetCertificate(
  KeyM_CertificateIdType CertId,
  P2CONST(KeyM_CertDataType, AUTOMATIC, KEYM_APPL_DATA) CertificateDataPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 errorId = KEYM_E_NO_ERROR;
  Std_ReturnType retVal = E_NOT_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */
  KeyM_ConstCertDataType certificateConstData;

  /* ----- Development Error Checks ------------------------------------- */
# if (KEYM_DEV_ERROR_DETECT == STD_ON)
  /* # Check if provided pointer is a null pointer */
  if (CertificateDataPtr == NULL_PTR)
  {
    /* [SWS_KeyM_00146] */
    errorId = KEYM_E_PARAM_POINTER;
  }
  else
# endif
  if (!KeyM_GetGlobalLock_CheckTaskState())
  {
    retVal = KEYM_E_GLOBAL_LOCK;
  }
  else
  {
    /* ----- Implementation ----------------------------------------------- */
    /* # Convert CertificateDataPtr from a KeyM_CertDataType to a KeyM_ConstCertDataType */
    certificateConstData.certData = CertificateDataPtr->certData;
    certificateConstData.certDataLength = CertificateDataPtr->certDataLength;

    /* # Forward call to KeyM_SetCertificateInternal with the converted parameter value */
    retVal = KeyM_SetCertificateInternal(CertId, &certificateConstData, &errorId);

    KeyM_FreeGlobalLock();
  }

  /* ----- Development Error Report --------------------------------------- */
# if (KEYM_DEV_ERROR_REPORT == STD_ON)
  /* # Report error if applicable */
  if (errorId != KEYM_E_NO_ERROR)
  {
    (void)Det_ReportError(KEYM_MODULE_ID, KEYM_INSTANCE_ID_DET, KEYM_SID_SET_CERTIFICATE, errorId);
  }
# else
  KEYM_DUMMY_STATEMENT(errorId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
# endif

  return retVal;
} /* KeyM_SetCertificate() */
#endif /* ifndef KEYM_NOUNIT_CERTIFICATESERVICES */

#ifndef KEYM_NOUNIT_CERTIFICATESERVICES /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_SetCertificateWithConstPtr()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(Std_ReturnType, KEYM_CODE) KeyM_SetCertificateWithConstPtr(
  KeyM_CertificateIdType CertId,
  P2CONST(KeyM_ConstCertDataType, AUTOMATIC, KEYM_APPL_DATA) CertificateDataPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 errorId = KEYM_E_NO_ERROR;
  Std_ReturnType retVal = E_NOT_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  /* ----- Implementation ----------------------------------------------- */
  if (!KeyM_GetGlobalLock_CheckTaskState())
  {
    retVal = KEYM_E_GLOBAL_LOCK;
  }
  else
  {
    /* # Forward call to KeyM_SetCertificateInternal */
    retVal = KeyM_SetCertificateInternal(CertId, CertificateDataPtr, &errorId);

    KeyM_FreeGlobalLock();
  }

  /* ----- Development Error Report --------------------------------------- */
# if (KEYM_DEV_ERROR_REPORT == STD_ON)
  /* # Report error if applicable */
  if (errorId != KEYM_E_NO_ERROR)
  {
    (void)Det_ReportError(KEYM_MODULE_ID, KEYM_INSTANCE_ID_DET, KEYM_SID_SET_CERTIFICATEWITHCONSTPTR, errorId);
  }
# else
  KEYM_DUMMY_STATEMENT(errorId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
# endif

  return retVal;
} /* KeyM_SetCertificateWithConstPtr() */
#endif /* ifndef KEYM_NOUNIT_CERTIFICATESERVICES */

#if (KEYM_CERTIFICATEGROUPUSEDOFCERTIFICATE == STD_ON)
# ifndef KEYM_NOUNIT_CERTIFICATESERVICES /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_SetCertificateInGroup()
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
/* PRQA S 6050, 6080 1 */ /* MD_MSR_STCAL, MD_MSR_STMIF */
FUNC(Std_ReturnType, KEYM_CODE) KeyM_SetCertificateInGroup(
  KeyM_CertificateGroupIdType GroupId,
  P2CONST(uint8, AUTOMATIC, KEYM_APPL_DATA) RequestData,
  uint32 RequestDataLength,
  P2VAR(KeyM_CertificateIdType, AUTOMATIC, KEYM_APPL_VAR) CertId)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 errorId = KEYM_E_NO_ERROR;
  Std_ReturnType retVal = E_NOT_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  /* ----- Development Error Checks ------------------------------------- */
#  if (KEYM_DEV_ERROR_DETECT == STD_ON)
  /* # Check initialization state of the component */
  if (!KeyM_IsInitialized())
  {
    errorId = KEYM_E_UNINIT;
  }
  /* # Check if provided pointer is a null pointer */
  else if ((RequestData == NULL_PTR)
    || (CertId == NULL_PTR))
  {
    /* [SWS_KeyM_00146] */
    errorId = KEYM_E_PARAM_POINTER;
  }
  else
#  endif
  {
    /* ----- Implementation ----------------------------------------------- */
    /* # Check if provided group ID is valid and return an error code otherwise */
    if (GroupId >= KeyM_GetSizeOfCertificateGroupExt())
    {
      retVal = KEYM_E_PARAMETER_MISMATCH;
    }
    /* # If group is configured for remote handling, redirect remote service request */
#  if (KEYM_REMOTE_REDIRECTION_ENABLED == STD_ON)
    else if (KeyM_GetStorageOfCertificate(KeyM_GetCertificateIdxOfGroupInd(KeyM_GetGroupIndCertStartIdxOfCertificateGroup((KeyM_CertificateGroupIterType)KeyM_GetCertificateGroupStartIdxOfCertificateGroupExt((KeyM_CertificateGroupExtIterType)GroupId)))) == KEYM_STORAGE_REMOTE)
    {
      retVal = KeyM_Remote_RedirectSetCertificateInGroup(GroupId, RequestData, RequestDataLength, CertId);
    }
#  endif /* KEYM_REMOTE_REDIRECTION_ENABLED */
    else if (!KeyM_GetGlobalLock())
    {
      retVal = KEYM_E_BUSY;
    }
    /* # Else, call local implementation of KeyM_SetCertificateInGroup */
    else
    {
      retVal = KeyM_Cert_SetCertificateInGroup(GroupId, RequestData, RequestDataLength, CertId);

      KeyM_FreeGlobalLock();
    }
  }

  /* ----- Development Error Report --------------------------------------- */
#  if (KEYM_DEV_ERROR_REPORT == STD_ON)
  /* # Report error if applicable */
  if (errorId != KEYM_E_NO_ERROR)
  {
    (void)Det_ReportError(KEYM_MODULE_ID, KEYM_INSTANCE_ID_DET, KEYM_SID_SET_CERTIFICATE_IN_GROUP, errorId);
  }
#  else
  KEYM_DUMMY_STATEMENT(errorId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
#  endif

  return retVal;
} /* KeyM_SetCertificateInGroup() */
# endif /* ifndef KEYM_NOUNIT_CERTIFICATESERVICES */
#endif

#if (KEYM_CERTIFICATEGROUPUSEDOFCERTIFICATE == STD_ON)
# ifndef KEYM_NOUNIT_CERTIFICATESERVICES /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 * KeyM_GetGroupCertId()
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
FUNC(Std_ReturnType, KEYM_CODE) KeyM_GetGroupCertId(
  KeyM_CertificateGroupIdType GroupId,
  P2CONST(uint8, AUTOMATIC, KEYM_APPL_DATA) SubjectCommonNameData,
  uint32 SubjectCommonNameDataLength,
  P2VAR(KeyM_CertificateIdType, AUTOMATIC, KEYM_APPL_VAR) CertId)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 errorId = KEYM_E_NO_ERROR;
  Std_ReturnType retVal = E_NOT_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  /* ----- Development Error Checks ------------------------------------- */
#  if (KEYM_DEV_ERROR_DETECT == STD_ON)
  /* # Check initialization state of the component */
  if (!KeyM_IsInitialized())
  {
    errorId = KEYM_E_UNINIT;
  }
  /* # Check if provided pointer is a null pointer */
  else if ((SubjectCommonNameData == NULL_PTR)
    || (CertId == NULL_PTR))
  {
    /* [SWS_KeyM_00146] */
    errorId = KEYM_E_PARAM_POINTER;
  }
  else
#  endif
  {
    /* ----- Implementation ----------------------------------------------- */
    /* # Check if provided group ID is valid and return an error code otherwise */
    if (GroupId >= KeyM_GetSizeOfCertificateGroupExt())
    {
      retVal = KEYM_E_PARAMETER_MISMATCH;
    }
    else if (!KeyM_GetGlobalLock_CheckTaskState())
    {
      retVal = KEYM_E_GLOBAL_LOCK;
    }
    else
    {
      /* # Call local implementation of KeyM_GetGroupCertId */
      retVal = KeyM_Cert_GetGroupCertId(GroupId, SubjectCommonNameData, SubjectCommonNameDataLength, CertId);

      KeyM_FreeGlobalLock();
    }
  }

  /* ----- Development Error Report --------------------------------------- */
#  if (KEYM_DEV_ERROR_REPORT == STD_ON)
  /* # Report error if applicable */
  if (errorId != KEYM_E_NO_ERROR)
  {
    (void)Det_ReportError(KEYM_MODULE_ID, KEYM_INSTANCE_ID_DET, KEYM_SID_GET_GROUP_CERT_ID, errorId);
  }
#  else
  KEYM_DUMMY_STATEMENT(errorId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
#  endif

  return retVal;
} /* KeyM_GetGroupCertId() */
# endif /* ifndef KEYM_NOUNIT_CERTIFICATESERVICES */
#endif

#ifndef KEYM_NOUNIT_CERTIFICATESERVICES /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_VerifyCertificates()
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
FUNC(Std_ReturnType, KEYM_CODE) KeyM_VerifyCertificates(
  KeyM_CertificateIdType CertId,
  KeyM_CertificateIdType CertUpperId)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 errorId = KEYM_E_NO_ERROR;
  Std_ReturnType retVal = E_NOT_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  /* ----- Development Error Checks ------------------------------------- */
# if (KEYM_DEV_ERROR_DETECT == STD_ON)
  /* # Check initialization state of the component */
  if (!KeyM_IsInitialized())
  {
    errorId = KEYM_E_UNINIT;
  }
  else
# endif
  {
    /* ----- Implementation ----------------------------------------------- */
    /* # Check if provided certificate IDs are valid and return an error code otherwise */
    if ((CertId >= KeyM_GetSizeOfCertificate()) || (CertUpperId >= KeyM_GetSizeOfCertificate())                                                                     /* certificates IDs must both be valid */
    || ((KeyM_GetStorageOfCertificate((KeyM_CertificateIterType)CertId) == KEYM_STORAGE_REMOTE) != (KeyM_GetStorageOfCertificate((KeyM_CertificateIterType)CertUpperId) == KEYM_STORAGE_REMOTE))) /* certificates must either both be local or remote */
    {
      retVal = KEYM_E_PARAMETER_MISMATCH;
    }
    /* # If certificate is configured for remote handling, redirect remote service request */
# if (KEYM_REMOTE_REDIRECTION_ENABLED == STD_ON)
    else if (KeyM_GetStorageOfCertificate((KeyM_CertificateIterType)CertId) == KEYM_STORAGE_REMOTE) /* if CertId is remote, this means that CertUpperId is also remote due to the check above */
    {
      retVal = KeyM_Remote_RedirectVerifyCertificates(CertId, CertUpperId);
    }
# endif /* KEYM_REMOTE_REDIRECTION_ENABLED */
    /* # Request the global lock */
    else if (!KeyM_GetGlobalLock())
    {
      retVal = KEYM_E_BUSY;
    }
    /* # Else, call local implementation of KeyM_VerifyCertificates */
    else
    {
      retVal = KeyM_Cert_VerifyCertificates(CertId, CertUpperId);

      KeyM_FreeGlobalLock();
    }
  }

  /* ----- Development Error Report --------------------------------------- */
# if (KEYM_DEV_ERROR_REPORT == STD_ON)
  /* # Report error if applicable */
  if (errorId != KEYM_E_NO_ERROR)
  {
    (void)Det_ReportError(KEYM_MODULE_ID, KEYM_INSTANCE_ID_DET, KEYM_SID_VERIFY_CERTIFICATES, errorId);
  }
# else
  KEYM_DUMMY_STATEMENT(errorId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
# endif

  return retVal;
} /* KeyM_VerifyCertificates() */
#endif /* ifndef KEYM_NOUNIT_CERTIFICATESERVICES */

#ifndef KEYM_NOUNIT_CERTIFICATESERVICES /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_VerifyCertificate()
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
FUNC(Std_ReturnType, KEYM_CODE) KeyM_VerifyCertificate(
  KeyM_CertificateIdType CertId)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 errorId = KEYM_E_NO_ERROR;
  Std_ReturnType retVal = E_NOT_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  /* ----- Development Error Checks ------------------------------------- */
# if (KEYM_DEV_ERROR_DETECT == STD_ON)
  /* # Check initialization state of the component */
  if (!KeyM_IsInitialized())
  {
    errorId = KEYM_E_UNINIT;
  }
  else
# endif
  {
    /* ----- Implementation ----------------------------------------------- */
    /* # Check if provided certificate ID is valid and return an error code otherwise */
    if (CertId >= KeyM_GetSizeOfCertificate())
    {
      retVal = KEYM_E_PARAMETER_MISMATCH;
    }
    /* # If certificate is configured for remote handling, redirect remote service request */
# if (KEYM_REMOTE_REDIRECTION_ENABLED == STD_ON)
    else if (KeyM_GetStorageOfCertificate((KeyM_CertificateIterType)CertId) == KEYM_STORAGE_REMOTE)
    {
      retVal = KeyM_Remote_RedirectVerifyCertificate(CertId);
    }
# endif /* KEYM_REMOTE_REDIRECTION_ENABLED */
    /* # Request the global lock */
    else if (!KeyM_GetGlobalLock())
    {
      retVal = KEYM_E_BUSY;
    }
    /* # Else, call local implementation of KeyM_VerifyCertificate */
    else
    {
      retVal = KeyM_Cert_VerifyCertificate(CertId);

      KeyM_FreeGlobalLock();
    }
  }

  /* ----- Development Error Report --------------------------------------- */
# if (KEYM_DEV_ERROR_REPORT == STD_ON)
  /* # Report error if applicable */
  if (errorId != KEYM_E_NO_ERROR)
  {
    (void)Det_ReportError(KEYM_MODULE_ID, KEYM_INSTANCE_ID_DET, KEYM_SID_VERIFY_CERTIFICATE, errorId);
  }
# else
  KEYM_DUMMY_STATEMENT(errorId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
# endif

  return retVal;
} /* KeyM_Cert_VerifyCertificate() */
#endif /* ifndef KEYM_NOUNIT_CERTIFICATESERVICES */

#ifndef KEYM_NOUNIT_CERTIFICATESERVICES /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_VerifyCertificateChain()
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
FUNC(Std_ReturnType, KEYM_CODE) KeyM_VerifyCertificateChain(
  KeyM_CertificateIdType CertId,
  P2CONST(KeyM_CertDataType, AUTOMATIC, KEYM_APPL_DATA) certChainData,
  uint8 NumberOfCertificates)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 errorId = KEYM_E_NO_ERROR;
  Std_ReturnType retVal = E_NOT_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */
  KeyM_ConstCertDataType chainConstData[KEYM_CERTIFICATE_CHAIN_MAX_DEPTH] = { 0u };

  /* ----- Development Error Checks ------------------------------------- */
# if (KEYM_DEV_ERROR_DETECT == STD_ON)
  /* # Check if provided pointer is a null pointer */
  if (certChainData == NULL_PTR)
  {
    /* [SWS_KeyM_00146] */
    errorId = KEYM_E_PARAM_POINTER;
  }
  else
# endif
  {
    /* ----- Implementation ----------------------------------------------- */
    /* # Check that NumberOfCertificates is <= KEYM_CERTIFICATE_CHAIN_MAX_DEPTH */
    if (NumberOfCertificates > KEYM_CERTIFICATE_CHAIN_MAX_DEPTH)
    {
      /* leave retVal at E_NOT_OK */
    }
    else
    {
      if (!KeyM_GetGlobalLock())
      {
        retVal = KEYM_E_BUSY;
      }
      else
      {
        uint8_least i;

        /* # Convert certChainData elements to KeyM_ConstCertDataType */
        for (i = 0u; i < NumberOfCertificates; i++)
        {
          chainConstData[i].certData = certChainData[i].certData;
          chainConstData[i].certDataLength = certChainData[i].certDataLength;
        }

        /* # Call KeyM_VerifyCertificateChainInternal with converted parameter */
        retVal = KeyM_VerifyCertificateChainInternal(CertId, chainConstData, NumberOfCertificates, &errorId);

        KeyM_FreeGlobalLock();
      }
    }
  }

  /* ----- Development Error Report --------------------------------------- */
# if (KEYM_DEV_ERROR_REPORT == STD_ON)
  /* # Report error if applicable */
  if (errorId != KEYM_E_NO_ERROR)
  {
    (void)Det_ReportError(KEYM_MODULE_ID, KEYM_INSTANCE_ID_DET, KEYM_SID_VERIFY_CERTIFICATE_CHAIN, errorId);
  }
# else
  KEYM_DUMMY_STATEMENT(errorId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
# endif

  return retVal;
} /* KeyM_VerifyCertificateChain() */
#endif /* ifndef KEYM_NOUNIT_CERTIFICATESERVICES */

#ifndef KEYM_NOUNIT_CERTIFICATESERVICES /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_VerifyCertificateChainWithConstPtr()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(Std_ReturnType, KEYM_CODE) KeyM_VerifyCertificateChainWithConstPtr(
  KeyM_CertificateIdType CertId,
  P2CONST(KeyM_ConstCertDataType, AUTOMATIC, KEYM_APPL_DATA) certChainData,
  uint8 NumberOfCertificates)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 errorId = KEYM_E_NO_ERROR;
  Std_ReturnType retVal = E_NOT_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  /* ----- Implementation ----------------------------------------------- */
  if (!KeyM_GetGlobalLock())
  {
    retVal = KEYM_E_BUSY;
  }
  else
  {
    /* # Forward call to KeyM_VerifyCertificateChainInternal */
    retVal = KeyM_VerifyCertificateChainInternal(CertId, certChainData, NumberOfCertificates, &errorId);
    KeyM_FreeGlobalLock();
  }

  /* ----- Development Error Report --------------------------------------- */
# if (KEYM_DEV_ERROR_REPORT == STD_ON)
  /* # Report error if applicable */
  if (errorId != KEYM_E_NO_ERROR)
  {
    (void)Det_ReportError(KEYM_MODULE_ID, KEYM_INSTANCE_ID_DET, KEYM_SID_VERIFY_CERTIFICATE_CHAINWITHCONSTPTR, errorId);
  }
# else
  KEYM_DUMMY_STATEMENT(errorId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
# endif

  return retVal;
} /* KeyM_VerifyCertificateChainWithConstPtr() */
#endif /* ifndef KEYM_NOUNIT_CERTIFICATESERVICES */

#if (KEYM_CERTIFICATEGROUPUSEDOFCERTIFICATE == STD_ON)
# ifndef KEYM_NOUNIT_CERTIFICATESERVICES /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_VerifyGroup()
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
/* PRQA S 6050 1 */ /* MD_MSR_STCAL */
FUNC(Std_ReturnType, KEYM_CODE) KeyM_VerifyGroup(
  KeyM_CertificateGroupIdType GroupId)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 errorId = KEYM_E_NO_ERROR;
  Std_ReturnType retVal = E_NOT_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  /* ----- Development Error Checks ------------------------------------- */
#  if (KEYM_DEV_ERROR_DETECT == STD_ON)
  /* # Check initialization state of the component */
  if (!KeyM_IsInitialized())
  {
    errorId = KEYM_E_UNINIT;
  }
  else
#  endif
  {
    /* ----- Implementation ----------------------------------------------- */
    /* # Check if provided group ID is valid and return an error code otherwise */
    if (GroupId >= KeyM_GetSizeOfCertificateGroupExt())
    {
      retVal = E_NOT_OK; /* API does not advertise error code KEYM_E_PARAMETER_MISMATCH */
    }
    /* # If certificate is configured for remote handling, redirect remote service request */
#  if (KEYM_REMOTE_REDIRECTION_ENABLED == STD_ON)
    else if (KeyM_GetStorageOfCertificate(KeyM_GetCertificateIdxOfGroupInd(KeyM_GetGroupIndCertStartIdxOfCertificateGroup((KeyM_CertificateGroupIterType)KeyM_GetCertificateGroupStartIdxOfCertificateGroupExt((KeyM_CertificateGroupExtIterType)GroupId)))) == KEYM_STORAGE_REMOTE)
    {
      retVal = KeyM_Remote_RedirectVerifyGroup(GroupId);
    }
#  endif /* KEYM_REMOTE_REDIRECTION_ENABLED */
    else if (!KeyM_GetGlobalLock())
    {
      retVal = KEYM_E_GLOBAL_LOCK;
    }
    /* # Else, call local implementation of KeyM_VerifyGroup */
    else
    {
      retVal = KeyM_Cert_VerifyGroup(GroupId);

      KeyM_FreeGlobalLock();
    }
  }

  /* ----- Development Error Report --------------------------------------- */
#  if (KEYM_DEV_ERROR_REPORT == STD_ON)
  /* # Report error if applicable */
  if (errorId != KEYM_E_NO_ERROR)
  {
    (void)Det_ReportError(KEYM_MODULE_ID, KEYM_INSTANCE_ID_DET, KEYM_SID_VERIFY_GROUP, errorId);
  }
#  else
  KEYM_DUMMY_STATEMENT(errorId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
#  endif

  return retVal;
} /* KeyM_VerifyGroup() */
# endif /* ifndef KEYM_NOUNIT_CERTIFICATESERVICES */
#endif

#ifndef KEYM_NOUNIT_CERTIFICATESERVICES /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_GetCertificate()
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
/* PRQA S 6080 1 */ /* MD_MSR_STMIF */
FUNC(Std_ReturnType, KEYM_CODE) KeyM_GetCertificate(
  KeyM_CertificateIdType CertId,
  P2VAR(KeyM_CertDataType, AUTOMATIC, KEYM_APPL_VAR) CertificateDataPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 errorId = KEYM_E_NO_ERROR;
  Std_ReturnType retVal = E_NOT_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  /* ----- Development Error Checks ------------------------------------- */
# if (KEYM_DEV_ERROR_DETECT == STD_ON)
  /* # Check initialization state of the component */
  if(!KeyM_IsInitialized())
  {
    errorId = KEYM_E_UNINIT;
  }
  /* # Check if provided pointer is a null pointer */
  else if ((CertificateDataPtr == NULL_PTR) || (CertificateDataPtr->certData == NULL_PTR))
  {
    /* [SWS_KeyM_00146] */
    errorId = KEYM_E_PARAM_POINTER;
  }
  else
# endif
  {
    /* ----- Implementation ----------------------------------------------- */
    /* # Check if provided certificate ID is valid and return an error code otherwise */
    if (CertId >= KeyM_GetSizeOfCertificate())
    {
      retVal = KEYM_E_PARAMETER_MISMATCH;
    }
    /* # If certificate is configured for remote handling, redirect remote service request */
# if (KEYM_REMOTE_REDIRECTION_ENABLED == STD_ON)
    else if (KeyM_GetStorageOfCertificate((KeyM_CertificateIterType)CertId) == KEYM_STORAGE_REMOTE)
    {
      retVal = KeyM_Remote_RedirectGetCertificate(CertId, CertificateDataPtr);
    }
# endif /* KEYM_REMOTE_REDIRECTION_ENABLED */
    /* # Request the global lock */
    else if (!KeyM_GetGlobalLock_CheckTaskState())
    {
      retVal = KEYM_E_GLOBAL_LOCK;
    }
    /* # Else, call local implementation of KeyM_GetCertificate */
    else
    {
      retVal = KeyM_Cert_GetCertificate(CertId, CertificateDataPtr);

      KeyM_FreeGlobalLock();
    }

# if (KEYM_DEV_ERROR_DETECT == STD_ON)
    if (retVal == KEYM_E_KEY_CERT_SIZE_MISMATCH)
    {
      /* [SWS_KeyM_00145] */
      errorId = KEYM_E_SMALL_BUFFER;
    }
# endif
  }

  /* ----- Development Error Report --------------------------------------- */
# if (KEYM_DEV_ERROR_REPORT == STD_ON)
  /* # Report error if applicable */
  if (errorId != KEYM_E_NO_ERROR)
  {
    (void)Det_ReportError(KEYM_MODULE_ID, KEYM_INSTANCE_ID_DET, KEYM_SID_GET_CERTIFICATE, errorId);
  }
# else
  KEYM_DUMMY_STATEMENT(errorId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
# endif

  return retVal;
} /* KeyM_GetCertificate() */
#endif /* ifndef KEYM_NOUNIT_CERTIFICATESERVICES */

#ifndef KEYM_NOUNIT_CERTIFICATESERVICES /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_CertElementGet()
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
/* PRQA S 6080 1 */ /* MD_MSR_STMIF */
FUNC(Std_ReturnType, KEYM_CODE) KeyM_CertElementGet(
  KeyM_CertificateIdType CertId,
  KeyM_CertElementIdType CertElementId,
  P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) CertElementData,
  P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) CertElementDataLength)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 errorId = KEYM_E_NO_ERROR;
  Std_ReturnType retVal = E_NOT_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  /* ----- Development Error Checks ------------------------------------- */
# if (KEYM_DEV_ERROR_DETECT == STD_ON)
  /* # Check initialization state of the component */
  if(!KeyM_IsInitialized())
  {
    errorId = KEYM_E_UNINIT;
  }
  /* # Check if provided pointer is a null pointer */
  else if ((CertElementData == NULL_PTR)
        || (CertElementDataLength == NULL_PTR))
  {
    /* [SWS_KeyM_00146] */
    errorId = KEYM_E_PARAM_POINTER;
  }
  else
# endif
  {
    /* ----- Implementation ----------------------------------------------- */
    /* # Check if provided certificate ID is valid and return an error code otherwise */
    if (CertId >= KeyM_GetSizeOfCertificate())
    {
      retVal = KEYM_E_PARAMETER_MISMATCH;
    }
    /* # If certificate is configured for remote handling, redirect remote service request */
# if (KEYM_REMOTE_REDIRECTION_ENABLED == STD_ON)
    else if (KeyM_GetStorageOfCertificate((KeyM_CertificateIterType)CertId) == KEYM_STORAGE_REMOTE)
    {
      retVal = KeyM_Remote_RedirectCertElementGet(CertId, CertElementId, CertElementData, CertElementDataLength);
    }
# endif /* KEYM_REMOTE_REDIRECTION_ENABLED */
    /* # Request the global lock */
    else if (!KeyM_GetGlobalLock_CheckTaskState())
    {
      retVal = KEYM_E_GLOBAL_LOCK;
    }
    /* # Else, call local implementation of KeyM_CertElementGet */
    else
    {
      retVal = KeyM_Cert_CertElementGet(CertId, CertElementId, CertElementData, CertElementDataLength);

      KeyM_FreeGlobalLock();
    }

# if (KEYM_DEV_ERROR_DETECT == STD_ON)
    if (retVal == KEYM_E_KEY_CERT_SIZE_MISMATCH)
    {
      /* [SWS_KeyM_00145] */
      errorId = KEYM_E_SMALL_BUFFER;
    }
# endif
  }

  /* ----- Development Error Report --------------------------------------- */
# if (KEYM_DEV_ERROR_REPORT == STD_ON)
  /* # Report error if applicable */
  if (errorId != KEYM_E_NO_ERROR)
  {
    (void)Det_ReportError(KEYM_MODULE_ID, KEYM_INSTANCE_ID_DET, KEYM_SID_CERT_ELEMENT_GET, errorId);
  }
# else
  KEYM_DUMMY_STATEMENT(errorId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
# endif

  return retVal;
} /* KeyM_CertElementGet() */
#endif /* ifndef KEYM_NOUNIT_CERTIFICATESERVICES */

#ifndef KEYM_NOUNIT_CERTIFICATESERVICES /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_CertElementGetByStructureType()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
FUNC(Std_ReturnType, KEYM_CODE) KeyM_CertElementGetByStructureType(
  P2CONST(uint8, AUTOMATIC, KEYM_APPL_DATA) CertData,
  uint32 CertDataLength,
  KeyM_CertificateStructureType CertStructure,
  P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) CertElementData,
  P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) CertElementDataLength)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 errorId = KEYM_E_NO_ERROR;
  Std_ReturnType retVal = E_NOT_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  /* ----- Development Error Checks ------------------------------------- */
# if (KEYM_DEV_ERROR_DETECT == STD_ON)
  /* # Check initialization state of the component */
  if(!KeyM_IsInitialized())
  {
    errorId = KEYM_E_UNINIT;
  }
  /* # Check if provided pointer is a null pointer */
  else if ((CertData == NULL_PTR)
        || (CertElementData == NULL_PTR)
        || (CertElementDataLength == NULL_PTR))
  {
    /* [SWS_KeyM_00146] */
    errorId = KEYM_E_PARAM_POINTER;
  }
  else
# endif
  {
    /* ----- Implementation ----------------------------------------------- */
    /* # Call local implementation of KeyM_CertElementGetByStructureType */
    retVal = KeyM_Cert_CertElementGetByStructureType(CertData, CertDataLength, CertStructure, CertElementData, CertElementDataLength);
  }

  /* ----- Development Error Report --------------------------------------- */
# if (KEYM_DEV_ERROR_REPORT == STD_ON)
  /* # Report error if applicable */
  if (errorId != KEYM_E_NO_ERROR)
  {
    (void)Det_ReportError(KEYM_MODULE_ID, KEYM_INSTANCE_ID_DET, KEYM_SID_CERT_ELEMENT_GET_BY_STRUCTURETYPE, errorId);
  }
# else
  KEYM_DUMMY_STATEMENT(errorId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
# endif

  return retVal;
} /* KeyM_CertElementGetByStructureType() */
#endif /* ifndef KEYM_NOUNIT_CERTIFICATESERVICES */

#ifndef KEYM_NOUNIT_CERTIFICATESERVICES /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_CertElementGetFirst()
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
/* PRQA S 3673, 6080 6 */ /* MD_KEYM_8.13_AutosarAPI, MD_MSR_STMIF */
FUNC(Std_ReturnType, KEYM_CODE) KeyM_CertElementGetFirst(
  KeyM_CertificateIdType CertId,
  KeyM_CertElementIdType CertElementId,
  P2VAR(KeyM_CertElementIteratorType, AUTOMATIC, KEYM_APPL_VAR) CertElementIterator,
  P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) CertElementData,
  P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) CertElementDataLength)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 errorId = KEYM_E_NO_ERROR;
  Std_ReturnType retVal = E_NOT_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  /* ----- Development Error Checks ------------------------------------- */
# if (KEYM_DEV_ERROR_DETECT == STD_ON)
  /* # Check initialization state of the component */
  if(!KeyM_IsInitialized())
  {
    errorId = KEYM_E_UNINIT;
  }
  /* # Check if provided pointer is a null pointer */
  else if ((CertElementIterator == NULL_PTR)
           || (CertElementData == NULL_PTR)
           || (CertElementDataLength == NULL_PTR))
  {
    /* [SWS_KeyM_00146] */
    errorId = KEYM_E_PARAM_POINTER;
  }
  else
# endif
  {
    /* ----- Implementation ----------------------------------------------- */
    /* # Check if provided certificate ID is valid and return an error code otherwise */
    if (CertId >= KeyM_GetSizeOfCertificate())
    {
      retVal = KEYM_E_PARAMETER_MISMATCH;
    }
    /* # Request the global lock */
    else if (!KeyM_GetGlobalLock_CheckTaskState())
    {
      retVal = KEYM_E_GLOBAL_LOCK;
    }
    /* # Call local implementation of KeyM_CertElementGetFirst */
    else
    {
      retVal = KeyM_Cert_CertElementGetFirst(CertId, CertElementId, CertElementIterator, CertElementData, CertElementDataLength);

      KeyM_FreeGlobalLock();

# if (KEYM_DEV_ERROR_DETECT == STD_ON)
      if (retVal == KEYM_E_KEY_CERT_SIZE_MISMATCH)
      {
        /* [SWS_KeyM_00145] */
        errorId = KEYM_E_SMALL_BUFFER;
      }
# endif
    }
  }

  /* ----- Development Error Report --------------------------------------- */
# if (KEYM_DEV_ERROR_REPORT == STD_ON)
  /* # Report error if applicable */
  if (errorId != KEYM_E_NO_ERROR)
  {
    (void)Det_ReportError(KEYM_MODULE_ID, KEYM_INSTANCE_ID_DET, KEYM_SID_CERT_ELEMENT_GET_FIRST, errorId);
  }
# else
  KEYM_DUMMY_STATEMENT(errorId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
# endif

  return retVal;
} /* KeyM_CertElementGetFirst() */
#endif /* ifndef KEYM_NOUNIT_CERTIFICATESERVICES */

#ifndef KEYM_NOUNIT_CERTIFICATESERVICES /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_CertElementGetNext()
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
/* PRQA S 3673 4 */ /* MD_KEYM_8.13_AutosarAPI */
FUNC(Std_ReturnType, KEYM_CODE) KeyM_CertElementGetNext(
  P2VAR(KeyM_CertElementIteratorType, AUTOMATIC, KEYM_APPL_VAR) CertElementIterator,
  P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) CertElementData,
  P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) CertElementDataLength)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 errorId = KEYM_E_NO_ERROR;
  Std_ReturnType retVal = E_NOT_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  /* ----- Development Error Checks ------------------------------------- */
# if (KEYM_DEV_ERROR_DETECT == STD_ON)
  /* # Check initialization state of the component */
  if(!KeyM_IsInitialized())
  {
    errorId = KEYM_E_UNINIT;
  }
  /* # Check if provided pointer is a null pointer */
  else if ((CertElementIterator == NULL_PTR)
        || (CertElementData == NULL_PTR)
        || (CertElementDataLength == NULL_PTR))
  {
    /* [SWS_KeyM_00146] */
    errorId = KEYM_E_PARAM_POINTER;
  }
  else
# endif
  {
    /* ----- Implementation ----------------------------------------------- */
    /* # Check if provided certificate ID is valid and return an error code otherwise */
    if (CertElementIterator->certId >= KeyM_GetSizeOfCertificate())
    {
      retVal = KEYM_E_PARAMETER_MISMATCH;
    }
    /* # Request the global lock */
    else if (!KeyM_GetGlobalLock_CheckTaskState())
    {
      retVal = KEYM_E_GLOBAL_LOCK;
    }
    else
    {
      /* # Call local implementation of KeyM_CertElementGetNext */
      retVal = KeyM_Cert_CertElementGetNext(CertElementIterator, CertElementData, CertElementDataLength);

      KeyM_FreeGlobalLock();
    }

# if (KEYM_DEV_ERROR_DETECT == STD_ON)
    if (retVal == KEYM_E_KEY_CERT_SIZE_MISMATCH)
    {
      /* [SWS_KeyM_00145] */
      errorId = KEYM_E_SMALL_BUFFER;
    }
# endif
  }

  /* ----- Development Error Report --------------------------------------- */
# if (KEYM_DEV_ERROR_REPORT == STD_ON)
  /* # Report error if applicable */
  if (errorId != KEYM_E_NO_ERROR)
  {
    (void)Det_ReportError(KEYM_MODULE_ID, KEYM_INSTANCE_ID_DET, KEYM_SID_CERT_ELEMENT_GET_NEXT, errorId);
  }
# else
  KEYM_DUMMY_STATEMENT(errorId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
# endif

  return retVal;
} /* KeyM_CertElementGetNext() */
#endif /* ifndef KEYM_NOUNIT_CERTIFICATESERVICES */

#ifndef KEYM_NOUNIT_CERTIFICATESERVICES /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_CertGetStatus()
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
FUNC(Std_ReturnType, KEYM_CODE) KeyM_CertGetStatus(
  KeyM_CertificateIdType CertId,
  P2VAR(KeyM_CertificateStatusType, AUTOMATIC, KEYM_APPL_VAR) Status)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 errorId = KEYM_E_NO_ERROR;
  Std_ReturnType retVal = E_NOT_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  /* ----- Development Error Checks ------------------------------------- */
# if (KEYM_DEV_ERROR_DETECT == STD_ON)
  /* # Check initialization state of the component */
  if(!KeyM_IsInitialized())
  {
    errorId = KEYM_E_UNINIT;
  }
  /* # Check if provided pointer is a null pointer */
  else if (Status == NULL_PTR)
  {
    /* [SWS_KeyM_00146] */
    errorId = KEYM_E_PARAM_POINTER;
  }
  else
# endif
  {
    /* ----- Implementation ----------------------------------------------- */
    /* # Check if provided certificate ID is valid and return an error code otherwise */
    if (CertId >= KeyM_GetSizeOfCertificate())
    {
      retVal = KEYM_E_PARAMETER_MISMATCH;
    }
    /* # If certificate is configured for remote handling, redirect remote service request */
# if (KEYM_REMOTE_REDIRECTION_ENABLED == STD_ON)
    else if (KeyM_GetStorageOfCertificate((KeyM_CertificateIterType)CertId) == KEYM_STORAGE_REMOTE)
    {
      retVal = KeyM_Remote_RedirectCertGetStatus(CertId, Status);
    }
# endif /* KEYM_REMOTE_REDIRECTION_ENABLED */
    /* # Else, call local implementation of KeyM_CertGetStatus */
    else
    {
      retVal = KeyM_Cert_CertGetStatus(CertId, Status);
    }
  }

  /* ----- Development Error Report --------------------------------------- */
# if (KEYM_DEV_ERROR_REPORT == STD_ON)
  /* # Report error if applicable */
  if (errorId != KEYM_E_NO_ERROR)
  {
    (void)Det_ReportError(KEYM_MODULE_ID, KEYM_INSTANCE_ID_DET, KEYM_SID_CERT_GET_STATUS, errorId);
  }
# else
  KEYM_DUMMY_STATEMENT(errorId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
# endif

  return retVal;
} /* KeyM_CertGetStatus() */
#endif /* ifndef KEYM_NOUNIT_CERTIFICATESERVICES */

#ifndef KEYM_NOUNIT_GENERAL /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_MainFunction()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, KEYM_CODE) KeyM_MainFunction(void)
{
  /* ----- Local Variables ---------------------------------------------- */
  /* ----- Implementation ----------------------------------------------- */
# if (KEYM_DEV_ERROR_DETECT == STD_ON)
  if (KeyM_IsInitialized())
# endif
  {
    SchM_Enter_KeyM_KEYM_EXCLUSIVE_AREA_0();
    if (!KeyM_MainFunctionLock)
    {
      KeyM_MainFunctionLock = TRUE;
      SchM_Exit_KeyM_KEYM_EXCLUSIVE_AREA_0();

      /* # Call local implementation of KeyM_MainFunction */
      KeyM_Cert_MainFunction();

      KeyM_MainFunctionLock = FALSE;
    }
    else
    {
      SchM_Exit_KeyM_KEYM_EXCLUSIVE_AREA_0();
    }
  }
} /* KeyM_MainFunction() */
#endif /* ifndef KEYM_NOUNIT_GENERAL */

#ifndef KEYM_NOUNIT_GENERAL /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_MainBackgroundFunction()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(void, KEYM_CODE) KeyM_MainBackgroundFunction(void)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 errorId = KEYM_E_NO_ERROR;

  /* ----- Development Error Checks ------------------------------------- */
# if (KEYM_DEV_ERROR_DETECT == STD_ON)
  /* # Check initialization state of the component */
  if(!KeyM_IsInitialized())
  {
    errorId = KEYM_E_UNINIT;
  }
  else
# endif
  {
    /* ----- Implementation ----------------------------------------------- */
    /* # Call local implementation of KeyM_MainBackgroundFunction */
    SchM_Enter_KeyM_KEYM_EXCLUSIVE_AREA_0();
    if (!KeyM_MainFunctionLock)
    {
      KeyM_MainFunctionLock = TRUE;
      SchM_Exit_KeyM_KEYM_EXCLUSIVE_AREA_0();

      KeyM_Cert_MainFunction();

      KeyM_MainFunctionLock = FALSE;
    }
    else
    {
      SchM_Exit_KeyM_KEYM_EXCLUSIVE_AREA_0();
    }
  }

  /* ----- Development Error Report --------------------------------------- */
# if (KEYM_DEV_ERROR_REPORT == STD_ON)
  /* # Report error if applicable */
  if (errorId != KEYM_E_NO_ERROR)
  {
    (void)Det_ReportError(KEYM_MODULE_ID, KEYM_INSTANCE_ID_DET, KEYM_SID_MAIN_BACKGROUND_FUNCTION, errorId);
  }
# else
  KEYM_DUMMY_STATEMENT(errorId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
# endif

} /* KeyM_MainBackgroundFunction() */
#endif /* ifndef KEYM_NOUNIT_GENERAL */

#ifndef KEYM_NOUNIT_CERTIFICATESERVICES /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_CertificateElementGetByIndex()
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
 */
/* PRQA S 3673, 6050, 6080 6 */ /* MD_KEYM_8.13_DeactivateableFeature, MD_MSR_STCAL, MD_MSR_STMIF */
FUNC(Std_ReturnType, KEYM_CODE) KeyM_CertificateElementGetByIndex(
  KeyM_CertificateIdType CertId,
  KeyM_CertElementIdType CertElementId,
  uint16 Index,
  P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) CertElementData,
  P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) CertElementDataLength)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 errorId = KEYM_E_NO_ERROR;
  Std_ReturnType retVal = E_NOT_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  KeyM_CertElementIteratorType CertElementIterator;
  KeyM_CertificateElementIterType elementIdx;

  /* ----- Development Error Checks ------------------------------------- */
# if (KEYM_DEV_ERROR_DETECT == STD_ON)
  /* # Check initialization state of the component */
  if (!KeyM_IsInitialized())
  {
    errorId = KEYM_E_UNINIT;
  }
  /* # Check if provided pointer is a null pointer */
  else if ((CertElementData == NULL_PTR)
    || (CertElementDataLength == NULL_PTR))
  {
    /* [SWS_KeyM_00146] */
    errorId = KEYM_E_PARAM_POINTER;
  }
  else
# endif
  {
    /* ----- Implementation ----------------------------------------------- */
    /* # Check if provided certificate ID is valid and return an error code otherwise */
    if (CertId >= KeyM_GetSizeOfCertificate())
    {
      retVal = KEYM_E_PARAMETER_MISMATCH;
    }
    /* # If certificate is configured for remote handling, redirect remote service request */
# if (KEYM_REMOTE_REDIRECTION_ENABLED == STD_ON)
    else if (KeyM_GetStorageOfCertificate((KeyM_CertificateIterType)CertId) == KEYM_STORAGE_REMOTE)
    {
      retVal = KeyM_Remote_RedirectCertificateElementGetByIndex(CertId, CertElementId, Index, CertElementData, CertElementDataLength);
    }
# endif /* KEYM_REMOTE_REDIRECTION_ENABLED */
    /* # Request the global lock */
    else if (!KeyM_GetGlobalLock_CheckTaskState())
    {
      retVal = KEYM_E_GLOBAL_LOCK;
    }
    /* # Else, iterate through certificate's elements until the requested element is found and return it */
    else
    {
      /* # Initialize iterator for first element */
      retVal = KeyM_Cert_CertElementGetFirstInitializeIterator(CertId, CertElementId, &CertElementIterator);
      /* # Iterate through iterable certificate elements until elementIdx is used or an error is encountered */
      for (elementIdx = 0; (elementIdx < Index) && (retVal == E_OK); elementIdx++)
      {
        /*@ assert CertElementIterator.certId < KeyM_GetSizeOfCertificate(); */ /* VCA_KEYM_CERT_CERTELEMENTFIRSTINITIALIZEITERATOR_RETURNED_E_OK */
        /*@ assert CertElementIterator.rootElementIdx < KeyM_GetSizeOfCertificateElement(); */ /* VCA_KEYM_CERT_CERTELEMENTFIRSTINITIALIZEITERATOR_RETURNED_E_OK */
        retVal = KeyM_Cert_CertElementGetNextUpdateIterator(&CertElementIterator);
      }

      /* # If no error was encountered, copy data of requested element to out parameters */
      if (retVal == E_OK)
      {
        /*@ assert CertElementIterator.certId < KeyM_GetSizeOfCertificate(); */ /* VCA_KEYM_CERT_CERTELEMENTFIRSTINITIALIZEITERATOR_RETURNED_E_OK */
        /*@ assert CertElementIterator.rootElementIdx < KeyM_GetSizeOfCertificateElement(); */ /* VCA_KEYM_CERT_CERTELEMENTFIRSTINITIALIZEITERATOR_RETURNED_E_OK */
        retVal = KeyM_Cert_CertElementGetNextCopyData(&CertElementIterator, CertElementData, CertElementDataLength);
      }

      KeyM_FreeGlobalLock();
    }

# if (KEYM_DEV_ERROR_DETECT == STD_ON)
    if (retVal == KEYM_E_KEY_CERT_SIZE_MISMATCH)
    {
      /* [SWS_KeyM_00145] */
      errorId = KEYM_E_SMALL_BUFFER;
    }
# endif
  }

  /* ----- Development Error Report --------------------------------------- */
# if (KEYM_DEV_ERROR_REPORT == STD_ON)
  /* # Report error if applicable */
  if (errorId != KEYM_E_NO_ERROR)
  {
    (void)Det_ReportError(KEYM_MODULE_ID, KEYM_INSTANCE_ID_DET, KEYM_SID_CERT_ELEMENT_GET_BY_INDEX, errorId);
  }
# else
  KEYM_DUMMY_STATEMENT(errorId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
# endif

  return retVal;
}
#endif /* ifndef KEYM_NOUNIT_CERTIFICATESERVICES */

#ifndef KEYM_NOUNIT_CERTIFICATESERVICES /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_CertificateElementGetCount()
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
/* PRQA S 3673, 6080 1 */ /* MD_KEYM_8.13_DeactivateableFeature, MD_MSR_STMIF */
FUNC(Std_ReturnType, KEYM_CODE) KeyM_CertificateElementGetCount(
  KeyM_CertificateIdType CertId,
  KeyM_CertElementIdType CertElementId,
  P2VAR(uint16, AUTOMATIC, KEYM_APPL_VAR) Count)
{
  uint8 errorId = KEYM_E_NO_ERROR;
  Std_ReturnType retVal = E_NOT_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  /* ----- Development Error Checks ------------------------------------- */
# if (KEYM_DEV_ERROR_DETECT == STD_ON)
  /* # Check initialization state of the component */
  if (!KeyM_IsInitialized())
  {
    errorId = KEYM_E_UNINIT;
  }
  /* # Check if provided pointer is a null pointer */
  else if ((Count == NULL_PTR))
  {
    /* [SWS_KeyM_00146] */
    errorId = KEYM_E_PARAM_POINTER;
  }
  else
# endif
  {
    /* ----- Implementation ----------------------------------------------- */
    /* # Check if provided certificate ID is valid and return an error code otherwise */
    if (CertId >= KeyM_GetSizeOfCertificate())
    {
      retVal = KEYM_E_PARAMETER_MISMATCH;
    }
    /* # If certificate is configured for remote handling, redirect remote service request */
# if (KEYM_REMOTE_REDIRECTION_ENABLED == STD_ON)
    else if (KeyM_GetStorageOfCertificate((KeyM_CertificateIterType)CertId) == KEYM_STORAGE_REMOTE)
    {
      retVal = KeyM_Remote_RedirectCertificateElementGetCount(CertId, CertElementId, Count);
    }
# endif /* KEYM_REMOTE_REDIRECTION_ENABLED */
    /* # Request the global lock */
    else if (!KeyM_GetGlobalLock_CheckTaskState())
    {
      retVal = KEYM_E_GLOBAL_LOCK;
    }
    /* # Else, call local implementation of KeyM_CertificateElementGetCount */
    else
    {
      retVal = KeyM_Cert_CertificateElementGetCount(CertId, CertElementId, Count);

      KeyM_FreeGlobalLock();
    }
  }

  /* ----- Development Error Report --------------------------------------- */
# if (KEYM_DEV_ERROR_REPORT == STD_ON)
  /* # Report error if applicable */
  if (errorId != KEYM_E_NO_ERROR)
  {
    (void)Det_ReportError(KEYM_MODULE_ID, KEYM_INSTANCE_ID_DET, KEYM_SID_CERT_ELEMENT_GET_COUNT, errorId);
  }
# else
  KEYM_DUMMY_STATEMENT(errorId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
# endif

  return retVal;
}
#endif /* ifndef KEYM_NOUNIT_CERTIFICATESERVICES */

#if (KEYM_CERTIFICATE_SIGNING_REQUEST_ENABLED == STD_ON)
# ifndef KEYM_NOUNIT_CERTIFICATESERVICES /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_InitCSR()
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
/* PRQA S 6060 7 */ /* MD_KEYM_6060_LOCAL */
FUNC(Std_ReturnType, KEYM_CODE) KeyM_InitCSR(
  P2CONST(uint8, AUTOMATIC, KEYM_APPL_DATA) CertNamePtr,
  uint32 CertNameLength,
  P2CONST(KeyM_CSRInfoType, AUTOMATIC, KEYM_APPL_DATA) CsrInfo,
  uint8 numOfReqObjects,
  P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) ResponseData,
  P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) ResponseDataLength)
{
  uint8 errorId = KEYM_E_NO_ERROR;
  Std_ReturnType retVal = E_NOT_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  /* ----- Development Error Checks ------------------------------------- */
#  if (KEYM_DEV_ERROR_DETECT == STD_ON)
  /* # Check initialization state of the component */
  if (!KeyM_IsInitialized())
  {
    errorId = KEYM_E_UNINIT;
  }
  /* # Check if provided pointer is a null pointer */
  else if ((CertNamePtr == NULL_PTR)
    || (CsrInfo == NULL_PTR)
    || (ResponseData == NULL_PTR)
    || (ResponseDataLength == NULL_PTR))
  {
    /* [SWS_KeyM_00146] */
    errorId = KEYM_E_PARAM_POINTER;
  }
  else
#  endif
  if (!KeyM_GetGlobalLock_CheckTaskState())
  {
    retVal = KEYM_E_GLOBAL_LOCK;
  }
  else
  {
    /* ----- Implementation ----------------------------------------------- */
    /* # Call KeyM_CheckCsrInfoData() to check integrity of passed CsrInfo data */
    retVal = KeyM_CheckCsrInfoData(CsrInfo, numOfReqObjects, &errorId);

    if (retVal == E_OK)
    {
      /* # Call local implementation of KeyM_InitCSR */
      retVal = KeyM_Cert_InitCSR(CertNamePtr, CertNameLength, CsrInfo, numOfReqObjects, ResponseData, ResponseDataLength);
    }
    KeyM_FreeGlobalLock();
  }

  /* ----- Development Error Report --------------------------------------- */
#  if (KEYM_DEV_ERROR_REPORT == STD_ON)
  /* # Report error if applicable */
  if (errorId != KEYM_E_NO_ERROR)
  {
    (void)Det_ReportError(KEYM_MODULE_ID, KEYM_INSTANCE_ID_DET, KEYM_SID_CERT_INIT_CSR, errorId);
  }
#  else
  KEYM_DUMMY_STATEMENT(errorId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
#  endif

  return retVal;
}
# endif /* ifndef KEYM_NOUNIT_CERTIFICATESERVICES */
#endif

#if (KEYM_CERTIFICATE_SIGNING_REQUEST_ENABLED == STD_ON)
# ifndef KEYM_NOUNIT_CERTIFICATESERVICES /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_CsrElementSet()
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
/* PRQA S 6080 1 */ /* MD_MSR_STMIF */
FUNC(Std_ReturnType, KEYM_CODE) KeyM_CsrElementSet(
  KeyM_CertificateIdType CertId,
  KeyM_CertElementIdType CertElementId,
  KeyM_CsrEncodingType EncodingType,
  P2CONST(uint8, AUTOMATIC, KEYM_APPL_DATA) ElementData,
  uint32 ElementDataLength)
{
  uint8 errorId = KEYM_E_NO_ERROR;
  Std_ReturnType retVal = E_NOT_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  /* ----- Development Error Checks ------------------------------------- */
#  if (KEYM_DEV_ERROR_DETECT == STD_ON)
  /* # Check initialization state of the component */
  if (!KeyM_IsInitialized())
  {
    errorId = KEYM_E_UNINIT;
  }
  /* # Check if provided pointer is a null pointer */
  else if (ElementData == NULL_PTR)
  {
    /* [SWS_KeyM_00146] */
    errorId = KEYM_E_PARAM_POINTER;
  }
  else
#  endif
  {
    /* ----- Implementation ----------------------------------------------- */
    /* # Check if provided certificate ID is valid and return an error code otherwise */
    if (CertId >= KeyM_GetSizeOfCertificate())
    {
      retVal = KEYM_E_PARAMETER_MISMATCH;
    }
    /* # If certificate is configured for remote handling, redirect remote service request */
#  if (KEYM_REMOTE_REDIRECTION_ENABLED == STD_ON)
    else if (KeyM_GetStorageOfCertificate((KeyM_CertificateIterType)CertId) == KEYM_STORAGE_REMOTE)
    {
      retVal = KeyM_Remote_RedirectCsrElementSet(CertId, CertElementId, EncodingType, ElementData, ElementDataLength);
    }
#  endif /* KEYM_REMOTE_REDIRECTION_ENABLED */
    else if (!KeyM_GetGlobalLock_CheckTaskState())
    {
      retVal = KEYM_E_GLOBAL_LOCK;
    }
    /* # Else, call local implementation of KeyM_CsrElementSet */
    else
    {
      retVal = KeyM_Cert_CsrElementSet(CertId, CertElementId, EncodingType, ElementData, ElementDataLength);

      KeyM_FreeGlobalLock();
    }
  }

  /* ----- Development Error Report --------------------------------------- */
#  if (KEYM_DEV_ERROR_REPORT == STD_ON)
  /* # Report error if applicable */
  if (errorId != KEYM_E_NO_ERROR)
  {
    (void)Det_ReportError(KEYM_MODULE_ID, KEYM_INSTANCE_ID_DET, KEYM_SID_CSR_ELEMENT_SET, errorId);
  }
#  else
  KEYM_DUMMY_STATEMENT(errorId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
#  endif

  return retVal;
}
# endif /* ifndef KEYM_NOUNIT_CERTIFICATESERVICES */
#endif

#if (KEYM_SERVICE_CERTIFICATE_FUNCTION_ENABLED == STD_ON) /* COV_KEYM_REQUIRED_FOR_SAFE */
# ifndef KEYM_NOUNIT_CERTIFICATESERVICES /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_ServiceCertificateById()
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
/* PRQA S 6060, 6080 7 */ /* MD_KEYM_6060_LOCAL, MD_MSR_STMIF */
FUNC(Std_ReturnType, KEYM_CODE) KeyM_ServiceCertificateById(
  KeyM_ServiceCertificateType Service,
  KeyM_CertificateIdType CertId,
  P2CONST(uint8, AUTOMATIC, KEYM_APPL_DATA) RequestData,
  uint32 RequestDataLength,
  P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) ResponseData,
  uint32 ResponseDataLength)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 errorId = KEYM_E_NO_ERROR;
  Std_ReturnType retVal = E_NOT_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  /* ----- Development Error Checks ------------------------------------- */
#  if (KEYM_DEV_ERROR_DETECT == STD_ON)
  /* # Check initialization state of the component */
  if (!KeyM_IsInitialized())
  {
    errorId = KEYM_E_UNINIT;
  }
  /* # Check if provided pointer is a null pointer */
  else if ((RequestData == NULL_PTR)
    || (ResponseData == NULL_PTR))
  {
    /* [SWS_KeyM_00146] */
    errorId = KEYM_E_PARAM_POINTER;
  }
  else
#  endif
  {
    /* ----- Implementation ----------------------------------------------- */
    /* # Check if provided certificate ID is valid and return an error code otherwise */
    if (CertId >= KeyM_GetSizeOfCertificate())
    {
      retVal = KEYM_E_PARAMETER_MISMATCH;
    }
    /* # If certificate is configured for remote handling, redirect remote service request */
#  if (KEYM_REMOTE_REDIRECTION_ENABLED == STD_ON)
    else if (KeyM_GetStorageOfCertificate((KeyM_CertificateIterType)CertId) == KEYM_STORAGE_REMOTE)
    {
      retVal = KeyM_Remote_RedirectServiceCertificateById(Service, CertId, RequestData, RequestDataLength, ResponseData, ResponseDataLength);
    }
#  endif /* KEYM_REMOTE_REDIRECTION_ENABLED */
    else if (!KeyM_GetGlobalLock())
    {
      retVal = KEYM_E_BUSY;
    }
    /* # Else, call local implementation of KeyM_ServiceCertificateById */
    else
    {
      retVal = KeyM_Cert_ServiceCertificateById(Service, CertId, RequestData, RequestDataLength, ResponseData, ResponseDataLength);

      KeyM_FreeGlobalLock();
    }
  }

  /* ----- Development Error Report --------------------------------------- */
#  if (KEYM_DEV_ERROR_REPORT == STD_ON)
  /* # Report error if applicable */
  if (errorId != KEYM_E_NO_ERROR)
  {
    (void)Det_ReportError(KEYM_MODULE_ID, KEYM_INSTANCE_ID_DET, KEYM_SID_SERVICE_CERTIFICATE_BY_ID, errorId);
  }
#  else
  KEYM_DUMMY_STATEMENT(errorId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
#  endif

  return retVal;
}
# endif /* ifndef KEYM_NOUNIT_CERTIFICATESERVICES */
#endif /* (KEYM_SERVICE_CERTIFICATE_FUNCTION_ENABLED == STD_ON) */

#if (KEYM_SERVICE_CERTIFICATE_FUNCTION_ENABLED == STD_ON) /* COV_KEYM_REQUIRED_FOR_SAFE */
# ifndef KEYM_NOUNIT_CERTIFICATESERVICES /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_ServiceCertificateByIdRteAdpt()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
/* PRQA S 6060 7 */ /* MD_KEYM_6060_LOCAL */
FUNC(Std_ReturnType, KEYM_CODE) KeyM_ServiceCertificateByIdRteAdpt(
  KeyM_CertificateIdType CertId,
  KeyM_ServiceCertificateType Service,
  P2CONST(uint8, AUTOMATIC, KEYM_APPL_DATA) RequestData,
  uint32 RequestDataLength,
  P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) ResponseData,
  uint32 ResponseDataLength)
{
  /* # Call KeyM_ServiceCertificateById */
  return KeyM_ServiceCertificateById(Service, CertId, RequestData, RequestDataLength, ResponseData, ResponseDataLength);
}
# endif /* ifndef KEYM_NOUNIT_CERTIFICATESERVICES */
#endif /* (KEYM_SERVICE_CERTIFICATE_FUNCTION_ENABLED == STD_ON) */

#if (KEYM_CRE == STD_ON)
# ifndef KEYM_NOUNIT_CERTIFICATESERVICES /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_SetCRE()
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
FUNC(Std_ReturnType, KEYM_CODE) KeyM_SetCRE(
  P2CONST(uint8, AUTOMATIC, KEYM_APPL_DATA) IssuerNameData,
  uint16 IssuerNameDataLength,
  P2CONST(uint8, AUTOMATIC, KEYM_APPL_DATA) SerialNumberData,
  uint16 SerialNumberDataLength)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 errorId = KEYM_E_NO_ERROR;
  Std_ReturnType retVal = E_NOT_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  /* ----- Development Error Checks ------------------------------------- */
#  if (KEYM_DEV_ERROR_DETECT == STD_ON)
  /* # Check initialization state of the component */
  if (!KeyM_IsInitialized())
  {
    errorId = KEYM_E_UNINIT;
  }
  /* # Check if provided pointer is a null pointer */
  else if ((IssuerNameData == NULL_PTR)
    || (SerialNumberData == NULL_PTR))
  {
    /* [SWS_KeyM_00146] */
    errorId = KEYM_E_PARAM_POINTER;
  }
  else
#  endif
  {
    /* ----- Implementation ----------------------------------------------- */
      /* # If certificate is configured for remote handling, redirect remote service request */
#  if (KEYM_CRE_APPL == STD_OFF) /* COV_KEYM_REQUIRED_FOR_SAFE */
      retVal = KeyM_Remote_RedirectSetCRE(IssuerNameData, IssuerNameDataLength, SerialNumberData, SerialNumberDataLength);
#  else
      if (!KeyM_GetGlobalLock_CheckTaskState())
      {
        retVal = KEYM_E_GLOBAL_LOCK;
      }
      else
      {
        /* # Else, call local implementation of KeyM_SetCRE */
        retVal = KeyM_Cert_SetCRE(IssuerNameData, IssuerNameDataLength, SerialNumberData, SerialNumberDataLength);

        KeyM_FreeGlobalLock();
      }
#  endif /* KEYM_REMOTE_REDIRECTION_ENABLED && KEYM_REMOTE_CREENABLED */
  }

  /* ----- Development Error Report --------------------------------------- */
#  if (KEYM_DEV_ERROR_REPORT == STD_ON)
  /* # Report error if applicable */
  if (errorId != KEYM_E_NO_ERROR)
  {
    (void)Det_ReportError(KEYM_MODULE_ID, KEYM_INSTANCE_ID_DET, KEYM_SID_SET_CRE, errorId);
  }
#  else
  KEYM_DUMMY_STATEMENT(errorId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
#  endif

  return retVal;
}
# endif /* ifndef KEYM_NOUNIT_CERTIFICATESERVICES */
#endif

#ifndef KEYM_NOUNIT_CERTIFICATESERVICES /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_CertStructureGet()
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
/* PRQA S 6080 1 */ /* MD_MSR_STMIF */
FUNC(Std_ReturnType, KEYM_CODE) KeyM_CertStructureGet(
  KeyM_CertificateIdType CertId,
  KeyM_CertificateStructureType CertStructure,
  P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) CertStructureData,
  P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) CertStructureDataLength)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 errorId = KEYM_E_NO_ERROR;
  Std_ReturnType retVal = E_NOT_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  /* ----- Development Error Checks ------------------------------------- */
# if (KEYM_DEV_ERROR_DETECT == STD_ON)
  /* # Check initialization state of the component */
  if (!KeyM_IsInitialized())
  {
    errorId = KEYM_E_UNINIT;
  }
  /* # Check if provided pointer is a null pointer */
  else if ((CertStructureData == NULL_PTR)
    || (CertStructureDataLength == NULL_PTR))
  {
    /* [SWS_KeyM_00146] */
    errorId = KEYM_E_PARAM_POINTER;
  }
  else
# endif
  {
    /* ----- Implementation ----------------------------------------------- */
    /* # Check if provided certificate ID is valid and return an error code otherwise */
    if (CertId >= KeyM_GetSizeOfCertificate())
    {
      retVal = KEYM_E_PARAMETER_MISMATCH;
    }
    /* # If certificate is configured for remote handling, redirect remote service request */
# if (KEYM_REMOTE_REDIRECTION_ENABLED == STD_ON)
    else if (KeyM_GetStorageOfCertificate((KeyM_CertificateIterType)CertId) == KEYM_STORAGE_REMOTE)
    {
      retVal = KeyM_Remote_RedirectCertStructureGet(CertId, CertStructure, CertStructureData, CertStructureDataLength);
    }
# endif /* KEYM_REMOTE_REDIRECTION_ENABLED */
    /* # Request the global lock */
    else if (!KeyM_GetGlobalLock_CheckTaskState())
    {
      retVal = KEYM_E_GLOBAL_LOCK;
    }
    /* # Else, call local implementation of KeyM_CertStructureGet */
    else
    {
      retVal = KeyM_Cert_CertStructureGet(CertId, CertStructure, CertStructureData, CertStructureDataLength);

      KeyM_FreeGlobalLock();
    }
  }

  /* ----- Development Error Report --------------------------------------- */
# if (KEYM_DEV_ERROR_REPORT == STD_ON)
  /* # Report error if applicable */
  if (errorId != KEYM_E_NO_ERROR)
  {
    (void)Det_ReportError(KEYM_MODULE_ID, KEYM_INSTANCE_ID_DET, KEYM_SID_CERT_STRUCTURE_GET, errorId);
  }
# else
  KEYM_DUMMY_STATEMENT(errorId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
# endif

  return retVal;
}
#endif /* ifndef KEYM_NOUNIT_CERTIFICATESERVICES */

#ifndef KEYM_NOUNIT_CERTIFICATESERVICES /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_GetIssuerCertId()
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
/* PRQA S 6080 1 */ /* MD_MSR_STMIF */
FUNC(Std_ReturnType, KEYM_CODE) KeyM_GetIssuerCertId(
  KeyM_CertificateIdType CertId,
  P2VAR(KeyM_CertificateIdType, AUTOMATIC, KEYM_APPL_VAR) IssuerCertId)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 errorId = KEYM_E_NO_ERROR;
  Std_ReturnType retVal = E_NOT_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  /* ----- Development Error Checks ------------------------------------- */
# if (KEYM_DEV_ERROR_DETECT == STD_ON)
  /* # Check initialization state of the component */
  if (!KeyM_IsInitialized())
  {
    errorId = KEYM_E_UNINIT;
  }
  /* # Check if provided pointer is a null pointer */
  else if (IssuerCertId == NULL_PTR)
  {
    /* [SWS_KeyM_00146] */
    errorId = KEYM_E_PARAM_POINTER;
  }
  else
# endif
  {
    /* ----- Implementation ----------------------------------------------- */
    /* # Check if provided certificate ID is valid and return an error code otherwise */
    if (CertId >= KeyM_GetSizeOfCertificate())
    {
      retVal = E_NOT_OK; /* API does not advertise error code KEYM_E_PARAMETER_MISMATCH */
    }
    /* # If certificate is configured for remote handling, redirect remote service request */
# if (KEYM_REMOTE_REDIRECTION_ENABLED == STD_ON)
    else if (KeyM_GetStorageOfCertificate((KeyM_CertificateIterType)CertId) == KEYM_STORAGE_REMOTE)
    {
      retVal = KeyM_Remote_RedirectGetIssuerCertId(CertId, IssuerCertId);
    }
# endif /* KEYM_REMOTE_REDIRECTION_ENABLED */
    /* # Request the global lock */
    else if (!KeyM_GetGlobalLock_CheckTaskState())
    {
      retVal = KEYM_E_GLOBAL_LOCK;
    }
    /* # Else, call local implementation of KeyM_GetIssuerCertId */
    else
    {
      retVal = KeyM_Cert_GetIssuerCertId(CertId, IssuerCertId);

      KeyM_FreeGlobalLock();
    }

  }

  /* ----- Development Error Report --------------------------------------- */
# if (KEYM_DEV_ERROR_REPORT == STD_ON)
  /* # Report error if applicable */
  if (errorId != KEYM_E_NO_ERROR)
  {
    (void)Det_ReportError(KEYM_MODULE_ID, KEYM_INSTANCE_ID_DET, KEYM_SID_GET_ISSUER_CERT_ID, errorId);
  }
# else
  KEYM_DUMMY_STATEMENT(errorId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
# endif

  return retVal;
}
#endif /* ifndef KEYM_NOUNIT_CERTIFICATESERVICES */

#ifndef KEYM_NOUNIT_CERTIFICATESERVICES /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_GetCertHash()
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
/* PRQA S 3673, 6080 4 */ /* MD_KEYM_8.13_DeactivateableFeature, MD_MSR_STMIF */
FUNC(Std_ReturnType, KEYM_CODE) KeyM_GetCertHash(
  KeyM_CertificateIdType CertId,
  P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) HashData,
  P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) HashDataLength)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 errorId = KEYM_E_NO_ERROR;
  Std_ReturnType retVal = E_NOT_OK; /* PRQA S 2981 */ /* MD_KEYM_2.2 */

  /* ----- Development Error Checks ------------------------------------- */
# if (KEYM_DEV_ERROR_DETECT == STD_ON)
  /* # Check initialization state of the component */
  if (!KeyM_IsInitialized())
  {
    errorId = KEYM_E_UNINIT;
  }
  /* # Check if provided pointer is a null pointer */
  else if ((HashData == NULL_PTR)
    || (HashDataLength == NULL_PTR))
  {
    /* [SWS_KeyM_00146] */
    errorId = KEYM_E_PARAM_POINTER;
  }
  else
# endif
  {
    /* ----- Implementation ----------------------------------------------- */
    /* # Check if provided certificate ID is valid and return an error code otherwise */
    if (CertId >= KeyM_GetSizeOfCertificate())
    {
      retVal = KEYM_E_PARAMETER_MISMATCH;
    }
    /* # If certificate is configured for remote handling, redirect remote service request */
# if (KEYM_REMOTE_REDIRECTION_ENABLED == STD_ON)
    else if (KeyM_GetStorageOfCertificate((KeyM_CertificateIterType)CertId) == KEYM_STORAGE_REMOTE)
    {
      retVal = KeyM_Remote_RedirectGetCertHash(CertId, HashData, HashDataLength);
    }
# endif /* KEYM_REMOTE_REDIRECTION_ENABLED */
    else
# if (KEYM_CERTCSMHASHJOBREFOFCERTIFICATE == STD_ON)
    /* # Request the global lock */
    if (!KeyM_GetGlobalLock_CheckTaskState())
    {
      retVal = KEYM_E_BUSY;
    }
    /* # Else, call local implementation of KeyM_GetCertHash */
    else
    {
      retVal = KeyM_Cert_GetCertHash(CertId, HashData, HashDataLength);
      KeyM_FreeGlobalLock();
    }
# else
    {
      KEYM_DUMMY_STATEMENT(HashData); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
      KEYM_DUMMY_STATEMENT(HashDataLength); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
    }
# endif
  }

  /* ----- Development Error Report --------------------------------------- */
# if (KEYM_DEV_ERROR_REPORT == STD_ON)
  /* # Report error if applicable */
  if (errorId != KEYM_E_NO_ERROR)
  {
    (void)Det_ReportError(KEYM_MODULE_ID, KEYM_INSTANCE_ID_DET, KEYM_SID_GET_CERT_HASH, errorId);
  }
# else
  KEYM_DUMMY_STATEMENT(errorId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
# endif

  return retVal;
}
#endif /* ifndef KEYM_NOUNIT_CERTIFICATESERVICES */

#ifndef KEYM_NOUNIT_CERTIFICATESERVICES /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_DispatchRemoteJob()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
FUNC(Std_ReturnType, KEYM_CODE) KeyM_DispatchRemoteJob(
  P2CONST(Crypto_JobType, AUTOMATIC, KEYM_APPL_VAR) job)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 errorId = KEYM_E_NO_ERROR;
  Std_ReturnType retVal = E_NOT_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  /* ----- Development Error Checks ------------------------------------- */
# if (KEYM_DEV_ERROR_DETECT == STD_ON)
   /* # Check initialization state of the component */
  if (!KeyM_IsInitialized())
  {
    errorId = KEYM_E_UNINIT;
  }
  /* # Check if provided pointer is a null pointer */
  else if (job == NULL_PTR)
  {
    /* [SWS_KeyM_00146] */
    errorId = KEYM_E_PARAM_POINTER;
  }
  else
# endif
  {
    /*@ assert $external(job); */ /* VCA_KEYM_DISPATCHREMOTEJOB */

    /* ----- Implementation ----------------------------------------------- */
    /* # Call local implementation of KeyM_DispatchRemoteJob */
# if (KEYM_REMOTE_DISPATCHING_ENABLED == STD_ON) /* COV_KEYM_UNSUPPORTED */
    retVal = KeyM_Remote_DispatchRemoteJob(job);
# else
    KEYM_DUMMY_STATEMENT(job); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
# endif
  }

  /* ----- Development Error Report --------------------------------------- */
# if (KEYM_DEV_ERROR_REPORT == STD_ON)
  /* # Report error if applicable */
  if (errorId != KEYM_E_NO_ERROR)
  {
    (void)Det_ReportError(KEYM_MODULE_ID, KEYM_INSTANCE_ID_DET, KEYM_SID_DISPATCH_REMOTE_JOB, errorId);
  }
# else
  KEYM_DUMMY_STATEMENT(errorId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
# endif

  return retVal;
}
#endif /* ifndef KEYM_NOUNIT_CERTIFICATESERVICES */

#ifndef KEYM_NOUNIT_CERTIFICATESERVICES /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_DispatchRemoteKeyElementSet()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
FUNC(Std_ReturnType, KEYM_CODE) KeyM_DispatchRemoteKeyElementSet(
  uint32 cryptoKeyId,
  uint32 keyElementId,
  P2CONST(uint8, AUTOMATIC, KEYM_APPL_VAR) keyPtr,
  uint32 keyLength)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 errorId = KEYM_E_NO_ERROR;
  Std_ReturnType retVal = E_NOT_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

/* ----- Development Error Checks ------------------------------------- */
# if (KEYM_DEV_ERROR_DETECT == STD_ON)
/* # Check initialization state of the component */
  if (!KeyM_IsInitialized())
  {
    errorId = KEYM_E_UNINIT;
  }
  /* # Check if provided pointer is a null pointer */
  else if (keyPtr == NULL_PTR)
  {
    /* [SWS_KeyM_00146] */
    errorId = KEYM_E_PARAM_POINTER;
  }
  else
# endif
  {
    /*@ assert $external(keyPtr); */ /* VCA_KEYM_DISPATCHREMOTEKEYELEMENTSET */

    /* ----- Implementation ----------------------------------------------- */
    /* # Call local implementation of KeyM_DispatchRemoteKeyElementSet */
# if (KEYM_REMOTE_DISPATCHING_ENABLED == STD_ON) /* COV_KEYM_UNSUPPORTED */
    retVal = KeyM_Remote_DispatchRemoteKeyElementSet(cryptoKeyId, keyElementId, keyPtr, keyLength);
# else
    KEYM_DUMMY_STATEMENT(cryptoKeyId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
    KEYM_DUMMY_STATEMENT(keyElementId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
    KEYM_DUMMY_STATEMENT(keyPtr); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
    KEYM_DUMMY_STATEMENT(keyLength); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
# endif
  }

  /* ----- Development Error Report --------------------------------------- */
# if (KEYM_DEV_ERROR_REPORT == STD_ON)
  /* # Report error if applicable */
  if (errorId != KEYM_E_NO_ERROR)
  {
    (void)Det_ReportError(KEYM_MODULE_ID, KEYM_INSTANCE_ID_DET, KEYM_SID_DISPATCH_REMOTE_KEYELEMENTSET, errorId);
  }
# else
  KEYM_DUMMY_STATEMENT(errorId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
# endif

  return retVal;
}
#endif /* ifndef KEYM_NOUNIT_CERTIFICATESERVICES */

#ifndef KEYM_NOUNIT_CERTIFICATESERVICES /* COV_KEYM_UNITTEST_DEFINE */
/**********************************************************************************************************************
 *  KeyM_DispatchRemoteKeyElementGet()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
/* PRQA S 3673 5 */ /* MD_KEYM_8.13_DeactivateableFeature */
FUNC(Std_ReturnType, KEYM_CODE) KeyM_DispatchRemoteKeyElementGet(
  uint32 cryptoKeyId,
  uint32 keyElementId,
  P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) keyPtr,
  P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) keyLengthPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 errorId = KEYM_E_NO_ERROR;
  Std_ReturnType retVal = E_NOT_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

/* ----- Development Error Checks ------------------------------------- */
# if (KEYM_DEV_ERROR_DETECT == STD_ON)
/* # Check initialization state of the component */
  if (!KeyM_IsInitialized())
  {
    errorId = KEYM_E_UNINIT;
  }
  /* # Check if provided pointer is a null pointer */
  else if ((keyPtr == NULL_PTR)
    || (keyLengthPtr == NULL_PTR))
  {
    /* [SWS_KeyM_00146] */
    errorId = KEYM_E_PARAM_POINTER;
  }
  else
# endif
  {
    /*@ assert $external(keyPtr); */ /* VCA_KEYM_DISPATCHREMOTEKEYELEMENTGET */

    /* ----- Implementation ----------------------------------------------- */
    /* # Call local implementation of KeyM_DispatchRemoteKeyElementGet */
# if (KEYM_REMOTE_DISPATCHING_ENABLED == STD_ON) /* COV_KEYM_UNSUPPORTED */
    retVal = KeyM_Remote_DispatchRemoteKeyElementGet(cryptoKeyId, keyElementId, keyPtr, keyLengthPtr);
# else
    KEYM_DUMMY_STATEMENT(cryptoKeyId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
    KEYM_DUMMY_STATEMENT(keyElementId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
    KEYM_DUMMY_STATEMENT(keyPtr); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
    KEYM_DUMMY_STATEMENT(keyLengthPtr); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
# endif
  }

  /* ----- Development Error Report --------------------------------------- */
# if (KEYM_DEV_ERROR_REPORT == STD_ON)
  /* # Report error if applicable */
  if (errorId != KEYM_E_NO_ERROR)
  {
    (void)Det_ReportError(KEYM_MODULE_ID, KEYM_INSTANCE_ID_DET, KEYM_SID_DISPATCH_REMOTE_KEYELEMENTGET, errorId);
  }
# else
  KEYM_DUMMY_STATEMENT(errorId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
# endif

  return retVal;
}
#endif /* ifndef KEYM_NOUNIT_CERTIFICATESERVICES */

#define KEYM_STOP_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * Module specific MISRA deviations
 *********************************************************************************************************************/
/* Module specific MISRA deviations:

MD_KEYM_0316:
Reason:       Cast is needed since upper layer NvM expects super type as parameter.
Risk:         Wrong type is casted or size does not match.
Prevention:   Covered by code review.

MD_KEYM_6060_LOCAL:
Reason:       API requires several parameters but structures and global variables shall be avoided.
Risk:         Stack usage and runtime too high for target uC. Usage of function is not easily comprehensible.
Prevention:   Test of resulting code on target uC. User must check stack usage in project context.

MD_KEYM_2.2:
Description:  Rule 2.2: There shall be no dead code.
Reason:       Dead code is caused due to specific configuration variant.
Risk:         None.
Prevention:   None.

MD_KEYM_14.3:
Description:  Rule 14.3: Controlling expressions shall not be invariant.
Reason:       Invariance is caused due to configuration with root certificates only.
Risk:         None.
Prevention:   None.

MD_KEYM_8.9:
Description:  Rule 8.9 An object should be defined at block scope if its identifier only appears in a single function.
Reason:       Objects are out of the function scope, to increase readability and to be reusable in future implementations.
Risk:         None.
Prevention:   None.

MD_KEYM_8.13_AutosarAPI:
Description:  Rule 8.13: A pointer should point to a const-qualified type whenever possible
Reason:       Function prototype is specified by AUTOSAR
Risk:         No risk.
Prevention:   Program flow has been verified by component tests and review.

MD_KEYM_8.13_DeactivateableFeature:
Description:  Rule 8.13: A pointer should point to a const-qualified type whenever possible
Reason:       Pointer can only be const when the respective feature is deactivated
Risk:         No risk.
Prevention:   Program flow has been verified by component tests and review.

MD_KEYM_DoubleDeclarationRte:
Description:  Rule 8.5: An external object or function shall be declared once in one and only one file
Reason:       Schedulable entities are declared by the RTE and also by the BSW modules.
Risk:         No functional risk.
Prevention:   Not required.

MD_KEYM_CFG_SWC_1330:
Description:  Rule 8.3 All declarations of an object or function shall use the same names and type qualifiers
Reason:       The RTE Generator uses default names for parameter identifiers of port defined arguments of service modules.
              Therefore the parameter identifiers in the function declaration differs from those of the implementation of the BSW module.
Risk:         No functional risk.
Prevention:   Not required.

MD_KEYM_16.3_Fallthrough:
Description:  Rule 16.3: An unconditional break statement shall terminate every switch-clause
Reason:       To use optimal design and improve binary size and performance, switch-case dispatchers use fall-through cases.
Risk:         Erroneous control flow.
Prevention:   Covered by code review. All fall-through cases are explicitly documented in the code as such.

MD_KEYM_STPAR_VERIFYOCSPRESPONSEDATA:
Description:  Number of function parameters defined by HIS shall be in range 0..5
Reason:       Input and output data require separate parameters for data pointer and data length.
Risk:         Stack usage and runtime too high for target ECU.
              Usage of function is not easily comprehensible.
Prevention:   Test of resulting code on target ECU.
              User must check stack usage in project context.

 */

/* COV_JUSTIFICATION_BEGIN

\ID COV_KEYM_NON_RTE
\ACCEPT TX
\ACCEPT XF
\REASON Ensures the variable or error code define exists if the KeyM is used without RTE.

\ID COV_KEYM_LOCAL_DEFINE
\ACCEPT XF
\ACCEPT TX
\REASON KEYM_LOCAL is always defined externally.

\ID COV_KEYM_CRYPTO_KEY_SUBMODULE
\ACCEPT XF
\REASON Crypto key submodule is not supported.

\ID COV_KEYM_COMPATIBILITY_DEFINE
\ACCEPT TX
\REASON Define is always defined internally but can be overwritten for compatibility.

\ID COV_KEYM_UNITTEST_DEFINE
\ACCEPT TX
\ACCEPT XX
\REASON Define is never defined but only for internal unit testing.

\ID COV_KEYM_UNSUPPORTED
\ACCEPT XF
\ACCEPT XF xf xf
\ACCEPT XF xf tx
\ACCEPT XF tf tf
\REASON The encapsulated features are not supported by KeyM in SafeBSW usecase and the
        corresponding preprocessor switches must be disabled (i.e. STD_OFF).
        This is guaranteed by the MSSV plugin and described in SMI-803893.

\ID COV_KEYM_REQUIRED_FOR_SAFE
\ACCEPT TX
\ACCEPT TX tx xf
\ACCEPT TX tx tf
\ACCEPT TX tx tx
\REASON The encapsulated features must be enabled for KeyM in SafeBSW usecase and the
        corresponding preprocessor switches must be enabled (i.e. STD_ON).
        This is guaranteed by the MSSV plugin and described in SMI-803893.

\ID COV_REMOTE_OCSP
\ACCEPT TF xf tf
\ACCEPT TF tf xf
\REASON For SafeBSW, OCSP is only supported remotely.
        This is guaranteed by the MSSV plugin and described in SMI-803893.

\ID COV_KEYM_CRE_APPL
\ACCEPT TF tf xf
\ACCEPT TF tf tx
\REASON For SafeBSW, CRE is only supported remotely.
        This is guaranteed by the MSSV plugin and described in SMI-803893.

\ID COV_KEYM_MISRA
\ACCEPT X
\REASON Misra is forcing default states in switch cases even if they are not reachable as all possible values has
        there own case.

\ID COV_KEYM_VECTOR_CODE_ANALYZER_CONFIGURABLE_STUB
\ACCEPT XF
\ACCEPT XX
\REASON For VCA analysis, stubs for user-configured callout and callback functions are used in order to properly
        simulate their parameter requirements, side-effects and results.

\ID COV_KEYM_VECTOR_CODE_ANALYZER_INTERNAL_STUB
\ACCEPT XF
\ACCEPT XX
\REASON KeyM_Cert_GetDynamicIssuerCertId is stubbed internally for VCA analysis. The stub (over-)approximates the
        real implementation's parameter requirements, results and side-effects. This significantly speeds up
        the analysis. For details on why this is sound, consult the CDD of KeyM_Cert_GetDynamicIssuerCertIdVcaStub.

COV_JUSTIFICATION_END */

/**********************************************************************************************************************
 *  SAFEBSW JUSTIFICATIONS
 *********************************************************************************************************************/
/* VCA_JUSTIFICATION_BEGIN

  \ID  VCA_KEYM_POINTERLENGTH_APICONTRACT
    \DESCRIPTION      According to VCA, assertion somePointerLength <= $lengthOf(somePointer) or
                                                  somePointerLength == $lengthOf(somePointer) may fail.
    \COUNTERMEASURE   \R somePointer points to a buffer that was passed to KeyM via an API function call.
                         The contract of the API states that the (minimum) length of that buffer must also be passed
                         to the API as a parameter l. This contract is described in the API's doxygen description.
                         somePointer and l are passed down to the subfunction containing this justification without
                         modification.
                         A runtime check that ensures that (somePointerLength == l) or (somePointerLength >= l)
                         precedes this assertion.

  \ID  VCA_KEYM_REMOTE_VERIFYCERTIFICATECHAIN_NUMOFCERTIFICATES
    \DESCRIPTION      According to VCA, assertion i < KEYM_CERTIFICATE_CHAIN_MAX_DEPTH may fail.
    \COUNTERMEASURE   \R The loop is only entered if two conditions are fulfilled: i < numOfCertificates and
                      retVal == E_OK. There is a check right before the loop that sets retVal to E_NOT_OK if
                      numOfCertificates > KEYM_CERTIFICATE_CHAIN_MAX_DEPTH. The loop is thus only entered if
                      numOfCertificates is <= KEYM_CERTIFICATE_CHAIN_MAX_DEPTH and i is < numOfCertificates.
                      This directly implies that i is also < KEYM_CERTIFICATE_CHAIN_MAX_DEPTH.

  \ID  VCA_KEYM_CERT_NUMLEAFCERTSTOVERIFY
    \DESCRIPTION      According to VCA, the following assertion may fail:
                      KeyM_Cert_NumLeafCertsToVerify <= KeyM_GetSizeOfCert_LeafCertsToVerify()
    \COUNTERMEASURE   \R The global variable KeyM_Cert_NumLeafCertsToVerify is only ever manipulated in the following
                      functions: KeyM_Cert_ClearLeafCertsToVerify, KeyM_Cert_PushLeafCertToVerify,
                      and KeyM_Cert_PopLeafCertToVerify.
                      KeyM_Cert_ClearLeafCertsToVerify always sets the variable to a valid value (see assertion there).
                      If the variable has a valid value at the beginning for KeyM_Cert_PushLeafCertToVerify and
                      KeyM_Cert_PopLeafCertToVerify, the respective functions always leave the variable with a valid
                      value (see justified assertion at the beginning and unjustified assertion at the end of the
                      functions).
                      KeyM_Cert_ClearLeafCertsToVerify is called in KeyM_Init and initializes the variable with a
                      valid value. Since all functions that manipulate the variable leave it in a good state if it
                      was in a good state previously, the value of the variable is always valid.

  \ID  VCA_KEYM_CERT_LEAFCERTSTOVERIFY_ELEMENTS
    \DESCRIPTION      According to VCA, the following assertion may fail: poppedCertId < KeyM_GetSizeOfCertificate()
    \COUNTERMEASURE   \R The variable in question was read from a buffer. That buffer is only ever written in
                      the function KeyM_Cert_PushLeafCertToVerify. Right before the write operation, there is an
                      assertion that ensures that the written value is < KeyM_GetSizeOfCertificate().
                      The control flow in KeyM_Cert_PushLeafCertToVerify and KeyM_Cert_PopLeafCertToVerify guarantees
                      that only buffer elements that have previously been initialized via
                      KeyM_Cert_PushLeafCertToVerify are read from the buffer (i.e., no uninitialized data is read).

  \ID  VCA_KEYM_CERT_NUMLINKSINVERIFYCHAIN
    \DESCRIPTION      According to VCA, the following assertion may fail:
                      KeyM_Cert_NumLinksInVerifyChain <= KeyM_GetSizeOfCert_VerifyChain()
    \COUNTERMEASURE   \R The global variable KeyM_Cert_NumLinksInVerifyChain is only ever manipulated in the following
                      functions: KeyM_Cert_ClearVerifyChain, KeyM_Cert_PushVerifyChainLink,
                      and KeyM_Cert_PopVerifyChainLink.
                      KeyM_Cert_ClearVerifyChain always sets the variable to a valid value (see assertion there).
                      If the variable has a valid value at the beginning for KeyM_Cert_PushVerifyChainLink and
                      KeyM_Cert_PopVerifyChainLink, the respective functions always leave the variable with a valid
                      value (see justified assertion at the beginning and unjustified assertion at the end of the
                      functions).
                      KeyM_Cert_ClearVerifyChain is called in KeyM_Init and initializes the variable with a
                      valid value. Since all functions that manipulate the variable leave it in a good state if it
                      was in a good state previously, the value of the variable is always valid.

  \ID  VCA_KEYM_CERT_VERIFYCHAIN_ELEMENTS
    \DESCRIPTION      According to VCA, the following assertion may fail: poppedCertId < KeyM_GetSizeOfCertificate()
    \COUNTERMEASURE   \R The variable in question was read from a buffer. That buffer is only ever written in
                      the function KeyM_Cert_PushVerifyChainLink. Right before the write operation, there is an
                      assertion that ensures that the written value is < KeyM_GetSizeOfCertificate().
                      The control flow in KeyM_Cert_PushVerifyChainLink and KeyM_Cert_PopVerifyChainLink guarantees
                      that only buffer elements that have previously been initialized via
                      KeyM_Cert_PushVerifyChainLink are read from the buffer (i.e., no uninitialized data is read).

  \ID  VCA_KEYM_CSL03_LENGTHASSERTION
    \DESCRIPTION      Assertion that the target of a 1:N or 0:N CSL indirection has the length (EndIdx - StartIdx)
    \COUNTERMEASURE   \N Qualified use-case CSL03 of ComStackLib

  \ID  VCA_KEYM_CERT_INITVALUECALLOUT
    \DESCRIPTION      Assertion that buffer provided by init value callout is valid and has specified length
    \COUNTERMEASURE   \S User needs to ensure that returned buffer and length provided by init value callout are
                      valid. SMI-787814

  \ID  VCA_KEYM_REPEATED_ASSERTION
    \DESCRIPTION      Assertion may fail according to VCA.
    \COUNTERMEASURE   \N This exact same assertion exists in all of the control flows above this assertion.
                      The asserted values have not been changed since the last assertion.

  \ID  VCA_KEYM_CERT_USING_STORAGELENGTH
    \DESCRIPTION      Using length retrieved from KeyM_Cert_GetCertStorageLength() as length of
                      CertStorageUsedOfCertificate buffer
    \COUNTERMEASURE   \N GetCertStorageLength() guarantees that the returned length corresponds to the length of the
                      CertStorage buffer of the certificate. See VCA_KEYM_CERT_STORAGELENGTH

  \ID  VCA_KEYM_CERT_SETWRITTENLENGTH
    \DESCRIPTION      Assertion that length of CertStorage for the certificate is <= lengthToWrite
    \COUNTERMEASURE   \R KeyM_GetCertStorageLengthOfCertificate() returns the length of CertStorage
                      (Qualified use-case CSL03 of ComStackLib). The control flow in this function ensures
                      that lengthToWrite is always <= this value.

  \ID  VCA_KEYM_CERT_GETWRITTENLENGTH
    \DESCRIPTION      Assertion that length of CertStorage for the certificate is <= retVal
    \COUNTERMEASURE   \N retVal has been deserialized from the certificate's CertStorageWrittenLength buffer.
                      The only place where this buffer is written to is KeyM_Cert_SetCertificateWrittenLength().
                      KeyM_Cert_SetCertificateWrittenLength() ensures via VCA assertion that all written values
                      conform with this assertion (before writing the value, it uses the exact same assertion as this
                      one). Furthermore, it is impossible that the buffer contains uninitialized data because
                      KeyM_Cert_SetCertificateWrittenLength() is called for every certificate in KeyM_Cert_Init().
                      Because all written data conforms to this assertion and there is always initialized data in the
                      buffer, all data that is read from the buffer must also conform to this assertion.

  \ID  VCA_KEYM_CERT_GETWRITTENLENGTH2
    \DESCRIPTION      Assertion that length of CertStorage for the certificate is <= retVal
    \COUNTERMEASURE   \N The value of retVal is either the value that has been plausibilized in
                      VCA_KEYM_CERT_GETWRITTENLENGTH or 0 for certificates that do not have a CertStorage.
                      0 is considered a valid length for such certificates, since it effectively means that
                      no bytes may be read from that certificate's (nonexistent) CertStorage.

  \ID  VCA_KEYM_CERT_COMMONCERTDATA_READ
    \DESCRIPTION      Assertions that readBufferData contains a pointer to a valid buffer and a length that is
                      <= the length of that buffer
    \COUNTERMEASURE   \N readBufferData was read from a buffer. That buffer is only ever written in
                      the function KeyM_Cert_InitCertificateReadBufferData().
                      There, right before write operation, there are assertions that the saved pointer is a valid
                      pointer and the set length is <= the length of the buffer.
                      The function initializes the buffer in this way for every certificate and is called in
                      KeyM_Cert_Init(). Because of this, it is ensured that the read values for every possible
                      certificate contain valid values.

  \ID  VCA_KEYM_CERT_GETCERTIFICATEREADBUFFERDATA_WRITTENLENGTH
    \DESCRIPTION      Assertion that the length retrieved from KeyM_Cert_GetCertificateWrittenLength() is
                      <= the length of the buffer referenced in readBufferData
    \COUNTERMEASURE   \N It is established via VCA_KEYM_CERT_COMMONCERTDATA_READ at the beginning of this function that
                      the pointer in readBufferData is the pointer that was set in KeyM_Cert_InitCertificateReadBufferData().
                      For non-ROM certificates, KeyM_Cert_InitCertificateReadBufferData() sets this pointer to the
                      certificate's CertStorage. Since this assertion is located in an if body that is only executed for
                      non-ROM certificates, it is ensured that the buffer referenced in readBufferData at this point
                      is the certificate's CertStorage.
                      The value retrieved from KeyM_Cert_GetCertificateWrittenLength() is a length that is <= the
                      certificate's CertStorage. This is established in KeyM_Cert_GetCertificateWrittenLength()
                      by assertions.

  \ID  VCA_KEYM_CSL03_PASSING_BUFFER
    \DESCRIPTION      Passing a pointer and length to another function for a write and/or read operation
    \COUNTERMEASURE   \N The passed buffer resides in Cfg.c and is generated by ComStackLib.
                      The buffer pointer was retrieved from CSL via CSL's official interfaces. The length that is passed
                      along with the buffer was retrieved from CSL either via the respective GetLength() function
                      or checked to be <= the value retrieved from the respective GetLength function.
                      This is qualified use-case CSL03 of ComStackLib.

  \ID  VCA_KEYM_CSL03_PASSING_BUFFER_WITH_OFFSET
    \DESCRIPTION      Passing a pointer and length to another function for a write and/or read operation
    \COUNTERMEASURE   \N The pointer that is passed is calculated from a ComStackLib buffer and an offset.
                      Refer to VCA_KEYM_CSL03_PASSING_BUFFER for a justification why the ComStackLib buffer is valid.
                      The used offset was checked to be < the size of the CSL buffer. This ensures that the passed pointer
                      is a valid location within the buffer. The control flow of the function ensures that the length
                      that is passed along with the buffer is a value <= (length of the CSL buffer - offset).
                      This ensures that the write and/or read operation will not exceed the ComStackLib buffer.

  \ID  VCA_KEYM_OID_EXISTENCE_WAS_CHECKED_BEFORE
    \DESCRIPTION      The configured OID of an element is accessed by the element's index.
    \COUNTERMEASURE   \R The same function checks whether an OID exists for an element in question.
                         If no OID exists, the call is not made.

  \ID VCA_KEYM_ASN1CSR_BOUNDS_OF_ELEMENTSTARTIDX
    \DESCRIPTION      Assertion localElementStartIdx < KeyM_GetSizeOfCertificateElement() may fail according to VCA
    \COUNTERMEASURE   \R localElementStartIdx is either 0 or assigned once to elementId which is constrained by the loop
                         bounds: elementIdx < KeyM_GetCertificateElementEndIdxOfCertificate(certId).

  \ID VCA_KEYM_ASN1CSR_BOUNDS_OF_CONFELEMENTENDIDX
    \DESCRIPTION      Assertion confElementEndIdx <= KeyM_GetSizeOfCertificateElement() may fail according to VCA
    \COUNTERMEASURE   \R KeyM_Asn1_GetConfSubjectNameInfo() guarantees this inequality:
                         firstConfElementIdx  + numOfConfSubjectNameObjects <= KeyM_GetSizeOfCertificateElement()

  \ID VCA_KEYM_ASN1CSR_BOUNDS_OF_OIDELEMENTIDX
    \DESCRIPTION      Assertion oidElementIndex < KeyM_GetSizeOfCertificateElement() may fail according to VCA
    \COUNTERMEASURE   \R As oidElementIndex = confElementEndIdx - i - 1 and confElementEndIdx <= KeyM_GetSizeOfCertificateElement(),
                         oidElement may only be >= KeyM_GetSizeOfCertificateElement() if the subtraction underflows.
                         From the loop condition, we get i <= numOfConfSubjectNameObjects - 1 and from the assignment to
                         confElementEndIdx, we get confElementEndIdx >= numOfConfSubjectNameObjects.
                         Hence, confElementEndIdx >= i holds and the subtraction cannot underflow.

  \ID VCA_KEYM_ASN1CSR_USER_SUPPLIED_BUFFER_AND_LENGTH
    \DESCRIPTION      Function 'KeyM_Asn1_AppendToDescr' is possibly called outside its specification according to VCA
    \COUNTERMEASURE   \N dataPtr and dataLength are read from the csrInfo buffer, which is provided to the unit's
                         interface function KeyM_Asn1_InitCSR by either:
                           - KeyM_Cert_CsrInfoGenerate (for the KeyM_CsrElementSet use case)
                             In this case, KeyM_Cert_CsrInfoGenerate ensures that the buffer length is not larger than
                             the buffer size. This is ensured by an assertion there.
                           - KeyM_Cert_InitCSR (for the KeyM_InitCSR use case)
                             In this case, buffer and length are provided directly by the API user. Any invalid pointer
                             and length constitute a break of the API contract.

  \ID VCA_KEYM_ASN1CSR_READ_OID_FROM_CSL
    \DESCRIPTION      Function 'KeyM_Asn1_AppendToDescr' is possibly called outside its specification according to VCA
    \COUNTERMEASURE   \N Function has two requirements:
                          - nestingLevel <= KEYM_ASN1_PARSE_MAX_NESTING_LEVEL is checked by an assertion right before the call
                          - - $lengthOf(dataPtr) >= dataLength is given because of qualified use-case CSL03 of ComStackLib

  \ID VCA_KEYM_ASN1CSR_MEMCPY_INTO_TAGBUFFER
    \DESCRIPTION      Function 'VStdLib_MemCpy' is possibly called outside its specification according to VCA
    \COUNTERMEASURE   \N The specification poses these requirements:
                           - pDst != NULL_PTR is guaranteed as pDst points to a buffer on the calling function's stack.
                           - pSrc != NULL_PTR is guaranteed because:
                             - pSrc is element.dataPtr
                             - element is copied from the certReqDescr buffer which is only ever manipulated using
                               KeyM_Asn1_AppendToDescr().
                             - We can only get into this branch in the calling function if element.elementType ==
                               KEYM_ASN1_CSR_ELEMENT_CERTREQINFO_SEQUENCE.
                             - The only call setting the element type to KEYM_ASN1_CSR_ELEMENT_CERTREQINFO_SEQUENCE also
                               sets the dataPtr to a non-NULL value.
                           - $lengthOf(pDst) >= nCnt is guaranteed because:
                             - Analogous to the argumentation above, for elementType == KEYM_ASN1_CSR_ELEMENT_CERTREQINFO_SEQUENCE
                           - $lengthOf(pSrc) >= nCnt is guaranteed because:
                             - element is copied from certReqDescr
                             - certReqDescr is only ever written to by KeyM_Asn1_AppendToDescr
                             - $lengthOf(dataPtr) >= dataLength is part of the precondition of KeyM_Asn1_AppendToDescr.

  \ID VCA_KEYM_ASN1CSR_MEMCPY_INTO_CERTREQ
    \DESCRIPTION      Function 'VStdLib_MemCpy' is possibly called outside its specification according to VCA
    \COUNTERMEASURE   \N The specification poses these requirements:
                           - pDst != NULL_PTR is guaranteed because:
                             - certReq != NULL_PTR is guaranteed by the calling function's precondition.
                             - "data" is a direct member of certReq's pointee, so it cannot be NULL.
                             - KEYM_ASN1_MAX_CSR_SIZE - certReqPos <= KEYM_ASN1_MAX_CSR_SIZE holds true because the
                               calling function contains a runtime check verifying that certReqPos is no greater than
                               KEYM_MAX_ASN1_CSR_SIZE. So the subtraction cannot underflow.
                             - KEYM_ASN1_MAX_CSR_SIZE <= $lengthOf(certReq) is guaranteed by an unjustified assertion.
                           - pSrc != NULL_PTR is guaranteed because pSrc is a buffer on the calling function's stack.
                           - $lengthOf(pDst) >= nCnt is guaranteed because:
                             - The explanation of the pDst above shows that $lengthOf(pDst) == certReqPos.
                             - tagBufferLength was added to certReq before, so certReqPos >= tagBufferLength.
                           - $lengthOf(pSrc) >= nCnt is equivalent to tagBufferLength <= $lengthOf(tagBuffer).
                             This holds true because a runtime check in the caller guarantees:
                                 tagBufferLength <= certReqPos <= KEYM_ASN1_MAX_CSR_SIZE
                             Furthermore, an unjustified assertion in the caller verifies that:
                                 KEYM_ASN1_MAX_CSR_SIZE <= $lengthOf(tagBuffer)
                             In result: tagBufferLength <= $lengthOf(tagBuffer)

  \ID VCA_KEYM_ASN1CSR_MEMCPY_ELEMENT_INTO_RESPONSEDATA
    \DESCRIPTION      Function 'VStdLib_MemCpy' is possibly called outside its specification according to VCA
    \COUNTERMEASURE   \N The specification poses these requirements:
                           - pDst != NULL_PTR is guaranteed because:
                               - responseData != NULL_PTR is verified by the calling function's precondition.
                               - pos <= pos + tagDataLength <= *responseDataLength is verified by a runtime check in the
                                 calling function.
                               - *responseDataLength <= $lengthOf(responseData) is guaranteed by the calling function's
                                 precondition.
                           - pSrc != NULL_PTR is guaranteed by a runtime check in the calling function.
                           - $lengthOf(pDst) >= nCnt is guaranteed by a runtime check in the calling function:
                             tagDataLength <= tagDataLength + pos <= *responseDataLength <= $lengthOf(responseData)

  \ID VCA_KEYM_ASN1CSR_MEMCPY_INTO_CSRINFOASN1
    \DESCRIPTION      Function 'VStdLib_MemCpy' is possibly called outside its specification according to VCA
    \COUNTERMEASURE   \N The specification poses these requirements:
                           - pDst != NULL_PTR is guaranteed because:
                               - csrInfoAsn1 is a buffer on the calling function's stack.
                               - An unjustified assertion guarantees that its size is at least KEYM_ASN1_MAX_CSR_SIZE.
                               - A runtime check guarantees that csrInfoAsn1Pos <= KEYM_ASN1_MAX_CSR_SIZE, so
                                 KEYM_ASN1_MAX_CSR_SIZE - csrInfoAsn1Pos does not underflow.
                           - pSrc != NULL_PTR is guaranteed because tmpBuffer lies on the calling function's stack.
                           - $lengthOf(pDst) >= nCnt is guaranteed because:
                             - $lengthOf(csrInfoAsn1) >= KEYM_ASN1_MAX_CSR_SIZE (see above)
                             - KEYM_ASN1_MAX_CSR_SIZE >= csrInfoAsn1Pos         (see above)
                             - csrInfoAsn1Pos         >= tmpBufferLength        (tmpBufferLength was added to
                                                                                 csrInfoAsn1Pos before)
                           - $lengthOf(pSrc) >= nCnt is guaranteed because:
                             - $lengthOf(tmpBuffer) >= KEYM_ASN1_MAX_CSR_SIZE is guaranteed by an unjustified assertion
                             - Now, the same argumentation as for the destination buffer applies.

  \ID VCA_KEYM_ASN1CSR_MEMCPY_CSRINFOASN1_INTO_RESPONSEDATA
    \DESCRIPTION      Function 'VStdLib_MemCpy' is possibly called outside its specification according to VCA
    \COUNTERMEASURE   \N When we arrive at this point of code, retVal must be E_OK which implies that the loop above
                         finished successfully. So we can rely on the fact that csrInfoAsn1Pos <= KEYM_ASN1_MAX_CSR_SIZE
                         since it is checked in the loop.
                         The specification poses these requirements:
                           - pDst != NULL_PTR is guaranteed by the calling function's precondition.
                           - pSrc != NULL_PTR is guaranteed because:
                               - csrInfoAsn1 is a buffer on the calling function's stack.
                               - It is at least KEYM_ASN1_MAX_CSR_SIZE bytes large, as guaranteed by an unjustified
                                 assertion.
                               - As csrInfoAsn1Pos <= KEYM_ASN1_MAX_CSR_SIZE, the subtraction cannot underflow.
                           - $lengthOf(pDst) >= nCnt is guaranteed because:
                             - $lengthOf(responseData) >= *responseDataLength is guaranteed by the calling function's
                               precondition.
                             - *responseDataLength >= csrInfoAsn1Pos is guaranteed by a runtime check in the calling
                               function.
                           - $lengthOf(pSrc) >= nCnt is guaranteed because:
                               - An unjustified assertion guarantees that its size is at least KEYM_ASN1_MAX_CSR_SIZE.
                               - csrInfoAsn1Pos < KEYM_ASN1_MAX_CSR_SIZE (see above)

  \ID VCA_KEYM_ASN1CSR_MEMCPY_CERTREQ_INTO_RESPONSEDATA
    \DESCRIPTION      Function 'VStdLib_MemCpy' is possibly called outside its specification according to VCA
    \COUNTERMEASURE   \N When we arrive at this point of code, retVal must be E_OK which implies that the loop above
                         finished successfully. So we can rely on the fact that csrInfoAsn1Pos <= KEYM_ASN1_MAX_CSR_SIZE
                         since it is checked in the loop.
                         The specification poses these requirements:
                           - pDst != NULL_PTR is guaranteed by the calling function's precondition.
                           - pSrc != NULL_PTR is guaranteed because:
                               - csrInfoAsn1 is a buffer on the calling function's stack.
                               - $lengthOf(csrInfoAsn1) >= KEYM_ASN1_MAX_CSR_SIZE is guaranteed by an unjustified
                                 assertion in the calling function.
                               - certReq.dataLength <= KEYM_ASN1_MAX_CSR_SIZE is guaranteed by an unjustified assertion
                                 in the calling function.
                           - $lengthOf(pDst) >= nCnt is guaranteed because:
                             - $lengthOf(responseData) >= responseDataLength is guaranteed by the API contract of the
                               KeyM_ServiceCertificate[ById] functions. The code is only called from these functions and
                               both responseData and responseDataLength have been passed through without modification.
                             - responseDataLength >= certReq.dataLength is guaranteed by a runtime check in the calling
                               function.
                           - $lengthOf(pSrc) >= nCnt is guaranteed because:
                               - An unjustified assertion guarantees that its size is at least KEYM_ASN1_MAX_CSR_SIZE.
                               - csrInfoAsn1Pos < KEYM_ASN1_MAX_CSR_SIZE (see above)

  \ID VCA_KEYM_ASN1CSR_NESTINGLEVEL_IS_IN_VALID_RANGE
    \DESCRIPTION      Assertion currentNestingLevel <= KEYM_ASN1_PARSE_MAX_NESTING_LEVEL may fail according to VCA
    \COUNTERMEASURE   \N Each write to the csrInfoDescr buffer is done through the KeyM_Asn1_AppendToDescr() function
                         which verifies as part of its precondition that the written nesting level is at most
                         KEYM_ASN1_PARSE_MAX_NESTING_LEVEL.

  \ID VCA_KEYM_SERVICECERT_CALLBACK_NOTIFICATION
    \DESCRIPTION      Function may possibly be called out of specification according to VCA
    \COUNTERMEASURE   \N The specification, as defined in KeyM_Appl.vcaspecs for Tsc_Appl_ServiceCallbackFunc poses
                         these requirements:
                           - CertId < KeyM_GetSizeOfCertificate() is guaranteed by an unjustified assertion in the
                             calling function.
                           - ResultDataPtr is guaranteed to be a non-NULL, valid pointer because:
                             - certReq.data lies on the stack of the calling function.
                             - $lengthOf(certReq.data) >= KEYM_ASN1_MAX_CSR_SIZE is guaranteed by an unjustified
                               assertion in the calling function.
                             - KEYM_ASN1_MAX_CSR_SIZE >= certReq.dataLength is guaranteed by an unjustified
                               assertion in the calling function. So the subtraction cannot underflow.
                           - $lengthOf(ResultDataPtr) >= ResultDataLength is guaranteed because:
                             - The maximum legal index for ResultDataPtr is certReq.dataLength - 1.
                             - With this index,
                               certReq.data[KEYM_ASN1_MAX_CSR_SIZE - certReq.DataLength + (certReq.dataLength - 1)] ==
                               certReq.data[KEYM_ASN1_MAX_CSR_SIZE - 1] is accessed.
                             - $lengthOf(certReq.data) >= KEYM_ASN1_MAX_CSR_SIZE (see above)
                             - Thus, certReq.data[KEYM_ASN1_MAX_CSR_SIZE - 1] is a valid address into certReq.data.

  \ID  VCA_KEYM_CERT_CHECKCHAINSTORAGE_CERTCHAINID
    \DESCRIPTION      Reading a valid certificate ID from a previously filled array
    \COUNTERMEASURE   \N The array certChain is filled with valid certificate IDs in the for loop at the beginning of the function.
                          The control flow in and after the for loop ensures that
                            - all array entries from index 0 to index certIdx are valid certificate IDs
                            - certIdx is set to the index of the last valid certificate ID in certChain
                          else, the second for loop is not reached. Before the second for loop, certNum is set to (certIdx + 1u).
                          The index calculation and loop control condition ensure that the certChain array is processed
                          entry-by-entry starting from index (certNum - 1) to 0. As explained above, all entries from
                          0 to (certNum - 1) have previously been set to valid certificate IDs.
                          Thus, the read certificate ID at this point is valid.

  \ID VCA_KEYM_DISPATCHREMOTEJOB
    \DESCRIPTION      Assertion $external(job) may fail according to VCA
    \COUNTERMEASURE   \R This assertion only means that the job pointer passed to this API function points to a
                         valid external (i.e., not in KeyM's memory) location. This is part of this function's API
                         contract. This assertion in this place helps VCA with the analysis further down the call tree.
                         It is guaranteed that the pointer is not a NULL_PTR at this point because a null pointer check
                         precedes this assertion.

  \ID VCA_KEYM_DISPATCHREMOTEKEYELEMENTSET
    \DESCRIPTION      Assertion $external(keyPtr) may fail according to VCA
    \COUNTERMEASURE   \R This assertion only means that the keyPtr passed to this API function points to a
                         valid external (i.e., not in KeyM's memory) location. This is part of this function's API
                         contract. This assertion in this place helps VCA with the analysis further down the call tree.
                         It is guaranteed that the pointer is not a NULL_PTR at this point because a null pointer check
                         precedes this assertion.

  \ID VCA_KEYM_DISPATCHREMOTEKEYELEMENTGET
    \DESCRIPTION      Assertion $external(keyPtr) may fail according to VCA
    \COUNTERMEASURE   \R This assertion only means that the keyPtr passed to this API function points to a
                         valid external (i.e., not in KeyM's memory) location. This is part of this function's API
                         contract. This assertion in this place helps VCA with the analysis further down the call tree.
                         It is guaranteed that the pointer is not a NULL_PTR at this point because a null pointer check
                         precedes this assertion.

  \ID VCA_KEYM_REMOTE_JOBDISPATCHING_INPUTOUTPUTLENGTH
    \DESCRIPTION      Assertion $lengthOf(job->jobPrimitiveInputOutput.<foo>Ptr) == <someLength>
                      may fail according to VCA
    \COUNTERMEASURE   \R A check that job->jobPrimitiveInputOutput.<foo>Length <= <someLength> precedes this assertion.
                         job was passed to KeyM as a parameter of the API KeyM_DispatchRemoteJob. The pointer
                         was passed down to this function from KeyM_DispatchRemoteJob without manipulation.
                         It is part of KeyM_DispatchRemoteJob's API contract that the lengths and pointers
                         in job->jobPrimitiveInputOutput are consistent, i.e.,
                         jobPrimitiveInputOutput.<foo>Ptr must reference a buffer with at least
                         jobPrimitiveInputOutput.<foo>Length bytes.
                         This is true for <foo> = {input || secondaryInput || tertiaryInput || output}.

  \ID VCA_KEYM_REMOTE_VERIFYCERTIFICATECHAIN_TERTIARYBUFFERACCESS
    \DESCRIPTION      Call KeyM_Utils_ConvertUint8ArrayToUint16BigEndian(&job->jobPrimitiveInputOutput.tertiaryInputPtr[offset])
                      is outside of KeyM_Utils_ConvertUint8ArrayToUint16BigEndian's specification
    \COUNTERMEASURE   \R A check that ensures that (offset + KEYM_REMOTE_CERTIFICATE_CHAIN_POS_CERTDATA)
                         is <= job->jobPrimitiveInputOutput.tertiaryInputLength precedes this call. It is part of
                         KeyM_DispatchRemoteJob's API contract that the passed
                         job->jobPrimitiveInputOutput.tertiaryInputPtr has a length of at least
                         job->jobPrimitiveInputOutput.tertiaryInputLength. This function is only called in the call tree
                         of KeyM_DispatchRemoteJob. The job parameter is passed through without manipulation.
                         The define KEYM_REMOTE_CERTIFICATE_CHAIN_POS_CERTDATA is set to 2.
                         The check that precedes this call ensures that the buffer locaton identified by the offset
                         still has 2 bytes to read. This matches the specification of
                         KeyM_Utils_ConvertUint8ArrayToUint16BigEndian.

  \ID VCA_KEYM_CERT_MEMCPY_WRITEBUFFER
    \DESCRIPTION      VStdLib_MemCpy is possibly called outside its specification
    \COUNTERMEASURE   \R The buffer that is passed to VStdLib_MemCpy has been retrieved via
                         KeyM_Cert_GetCertificateWriteBufferData(). There are assertions in place in
                         KeyM_Cert_GetCertificateWriteBufferData() that ensure that the buffer pointer is valid
                         and the returned length matches the buffer.
                         The length that is passed to MemCpy has been checked via a runtime check to be <= the
                         returned length.
                         The source buffer and the length have been provided by the user. It is part of the respective
                         API's contract that the length matches the length of the provided buffer.

  \ID VCA_KEYM_CERT_KEYELEMENTSET_READBUFFER
    \DESCRIPTION      Csm_KeyElementSet is possibly called outside its specification
    \COUNTERMEASURE   \R The buffer and length that are passed to Csm_KeyElementSet have been retrieved via
                         KeyM_Cert_GetCertificateReadBufferData(). There are assertions in place in
                         KeyM_Cert_GetCertificateReadBufferData() that ensure that the buffer pointer is valid
                         and the returned length matches the buffer.

  \ID VCA_KEYM_CERT_GETCERTIFICATE_MEMCPY
    \DESCRIPTION      VStdLib_MemCpy is possibly called outside its specification
    \COUNTERMEASURE   \R The passed source pointer and length have been retrieved via
                         KeyM_Cert_GetCertificateReadBufferData(). There are assertions in place in
                         KeyM_Cert_GetCertificateReadBufferData() that ensure that the buffer pointer is valid
                         and the returned length matches the buffer.
                         The passed destination pointer was provided by the user. It is part of
                         KeyM_GetCertificate's API contract that the passed pointer has a length that matches at least
                         a certain length that was passed along with the pointer. This length was checked to be
                         <= the length that is passed to MemCpy. This function is only called in the call tree of
                         KeyM_GetCertificate. The CertificateDataPtr parameter has been passed through to this function
                         without manipulation.

  \ID VCA_KEYM_LENGTH_FROM_CSL
    \DESCRIPTION      Assertion that retrieved length from ComStackLib 0:N or 1:N indirection is < size of corresponding table
    \COUNTERMEASURE   \N The length in question was retrieved from ComStackLib via KeyM_GetXLengthOfY with a correct
                         index for table Y. This is qualified use-case CSL03 of ComStackLib.

  \ID VCA_KEYM_IDX_FROM_OPTIONAL_CSL_INDIRECTION
    \DESCRIPTION      Assertion that retrieved index from ComStackLib 0:1 indirection is < size of indirection target's table
    \COUNTERMEASURE   \N The index in question was retrieved from ComStackLib via KeyM_GetXOfY or KeyM_GetXStartIdxOfY with
                         a correct index for table Y. There is a runtime check or VCA assertion that ensures that
                         KeyM_IsXUsedOfY is TRUE. This is qualified use-case CSL03 of ComStackLib.

  \ID VCA_KEYM_ASSERTION_MATCHES_REQUIREMENT
    \DESCRIPTION      Assertion may fail according to VCA
    \COUNTERMEASURE   \N The assertion in question matches the function's specified requirement and must thus hold.

  \ID VCA_KEYM_FUNCTION_REQUIREMENT_CHECKED
    \DESCRIPTION      Function is possibly called outside its specification according to VCA
    \COUNTERMEASURE   \R There is a runtime check immediately before the call that checks that the function's requirements hold.

  \ID VCA_KEYM_CALLEE_REQUIREMENTS_IDENTICAL_TO_CALLER
    \DESCRIPTION      Function is possibly called outside its specification according to VCA
    \COUNTERMEASURE   \N The callee's requirements are identical to the caller's requirements.
                         None of the variables checked by the requirement have been manipulated in the caller
                         function before the callee is called.

  \ID VCA_KEYM_IDX_FROM_OPTIONAL_CSL_INDIRECTION_WITH_REQUIREMENT
    \DESCRIPTION      Assertion that retrieved index from ComStackLib 0:1 indirection is < size of indirection target's table
    \COUNTERMEASURE   \N The index in question was retrieved from ComStackLib via KeyM_GetXOfY or KeyM_GetXStartIdxOfY with
                         a correct index for table Y. KeyM_IsXUsedOfY is a specified requirement of this function and
                         must thus hold. This is qualified use-case CSL03 of ComStackLib.

  \ID VCA_KEYM_CERT_LOADCERTIFICATEINITVALUE_MEMCPY
    \DESCRIPTION      Function is possibly called outside its specification according to VCA
    \COUNTERMEASURE   \R Destination buffer was retrieved from KeyM_Cert_GetCertificateReadBufferData() and is therefore valid
                         (see assertions there). Length was checked to be <= the retrieved length. Via runtime check.
                         Source buffer and length have been established to be valid and of correct lengths via assertions
                         in this function.

  \ID VCA_KEYM_CERT_ISREFERENCEELEMENTFOUND_ELEMENTIDXLOCAL
    \DESCRIPTION      Assertion elementIdxLocal < KeyM_GetSizeOfCertificateElement() may fail according to VCA
    \COUNTERMEASURE   \N elementIdxLocal is initialized as 0 which is < KeyM_GetSizeOfCertificateElement().
                         In the loop it may be assigned the value of i. Within the loop body, i always has a value
                         < KeyM_GetSizeOfCertificateElement() (cf. the assertion in the loop body).

  \ID VCA_KEYM_REMOTE_AEADDECRYPT_SERVICECERTIFICATE
    \DESCRIPTION      Function Csm_AEADDecrypt is possibly called outside its specification according to VCA
    \COUNTERMEASURE   \N The pointers CertNamePtr, CertNameLength, RequestData, RequestDataLength and ResponseData
                         are passed through to Csm_AEADDecrypt directly from the API KeyM_ServiceCertificate
                         without manipulation. KeyM_ServiceCertificate's API contract states that the pointers in
                         question must be valid and, in case of the length pointers, must contain the correct length
                         of the corresponding buffers. (Furthermore, there are Det checks that ensure that the pointers
                         are not null in the calling functions.)
                         The remaining two pointer parameters that are passed to Csm_AEADDecrypt point to stack
                         variables in this function and are thus valid.

  \ID VCA_KEYM_REMOTE_AEADDECRYPT_SERVICECERTIFICATEBYID
    \DESCRIPTION      Function Csm_AEADDecrypt is possibly called outside its specification according to VCA
    \COUNTERMEASURE   \N The pointers RequestData, RequestDataLength and ResponseData
                         are passed through to Csm_AEADDecrypt directly from the API KeyM_ServiceCertificateById
                         without manipulation. KeyM_ServiceCertificate's API contract states that the pointers in
                         question must be valid and, in case of the length pointers, must contain the correct length
                         of the corresponding buffers. (Furthermore, there are Det checks that ensure that the pointers
                         are not null in the calling functions.)
                         The remaining three pointer parameters that are passed to Csm_AEADDecrypt point to stack
                         variables in this function and are thus valid.

  \ID VCA_KEYM_REMOTE_AEADDECRYPT_SERVICECERTIFICATEOCSP
    \DESCRIPTION      Function Csm_AEADDecrypt is possibly called outside its specification according to VCA
    \COUNTERMEASURE   \N The pointers CertNamePtr, CertNameLength, RequestData, RequestDataLength and ResponseData
                         are passed through to Csm_AEADDecrypt directly from the API KeyM_ServiceCertificate
                         without manipulation. KeyM_ServiceCertificate's API contract states that the pointers in
                         question must be valid and, in case of the length pointers, must contain the correct length
                         of the corresponding buffers. (Furthermore, there are Det checks that ensure that the pointers
                         are not null in the calling functions.)
                         The remaining two pointer parameters that are passed to Csm_AEADDecrypt point to stack
                         variables in this function and are thus valid.

  \ID VCA_KEYM_REMOTE_KEYELEMENTSET_SETCERTIFICATE
    \DESCRIPTION      Function Csm_KeyElementSet is possibly called outside its specification according to VCA
    \COUNTERMEASURE   \N CertificateDataPtr's member's values are passed through to this function directly from the
                         API KeyM_SetCertificate or KeyM_SetCertificateWithConstPtr without manipulation.
                         KeyM_SetCertificate's API contract requires that contained certData is valid and
                         certDataLength matches the buffer's length. Also, there is a NULL_PTR check for certData
                         in the calling function.

  \ID VCA_KEYM_REMOTE_KEYELEMENTGET_GETCERTIFICATE
    \DESCRIPTION      Function Csm_KeyElementGet is possibly called outside its specification according to VCA
    \COUNTERMEASURE   \N CertificateDataPtr's member's values are passed through to this function directly from the
                         API KeyM_GetCertificate without manipulation.
                         KeyM_GetCertificate's API contract requires that contained certData is valid and
                         certDataLength matches the buffer's length. Also, there is a NULL_PTR check for certData
                         in the calling function.

  \ID VCA_KEYM_REMOTE_KEYELEMENTGET_CERTELEMENTGET
    \DESCRIPTION      Function Csm_KeyElementGet is possibly called outside its specification according to VCA
    \COUNTERMEASURE   \N CertElementData and CertElementDataLength are passed through to this function directly from the
                         API KeyM_CertElementGet without manipulation.
                         KeyM_CertElementGet's API contract requires that both pointers are valid and
                         CertElementDataLength's content matches CertElementData's length. Also, there is a NULL_PTR
                         check for both pointers in the calling function.

  \ID VCA_KEYM_REMOTE_KEYELEMENTGET_CERTSTRUCTUREGET
    \DESCRIPTION      Function Csm_KeyElementGet is possibly called outside its specification according to VCA
    \COUNTERMEASURE   \N CertStructureData and CertStructureDataLength are passed through to this function directly from the
                         API KeyM_CertStructureGet without manipulation.
                         KeyM_CertStructureGet's API contract requires that both pointers are valid and
                         CertStructureDataLength's content matches CertStructureData's length. Also, there is a NULL_PTR
                         check for both pointers in the calling function.

  \ID VCA_KEYM_REMOTE_KEYELEMENTGET_CERTIFICATEELEMENTGETBYINDEX
    \DESCRIPTION      Function Csm_KeyElementGet is possibly called outside its specification according to VCA
    \COUNTERMEASURE   \N CertElementData and CertElementDataLength are passed through to this function directly from the
                         API KeyM_CertificateElementGetByIndex without manipulation.
                         KeyM_CertificateElementGetByIndex's API contract requires that both pointers are valid and
                         CertElementDataLength's content matches CertElementData's length. Also, there is a NULL_PTR
                         check for both pointers in the calling function.

  \ID VCA_KEYM_KEYELEMENTGET_STACKBUFFER
    \DESCRIPTION      Function Csm_KeyElementGet is possibly called outside its specification according to VCA
    \COUNTERMEASURE   \N The arguments passed as keyPtr and keyLengthPtr are pointers to an array on the stack
                         and an uint32 on the stack. The uint32 value has been initialized to match the size of
                         the array.

  \ID VCA_KEYM_REMOTE_KEYELEMENTGET_GETCERTHASH
    \DESCRIPTION      Function Csm_KeyElementGet is possibly called outside its specification according to VCA
    \COUNTERMEASURE   \N HashData and HashDataLength are passed through to this function directly from the
                         API KeyM_Cert_GetCertHash without manipulation.
                         KeyM_Cert_GetCertHash's API contract requires that both pointers are valid and
                         HashDataLength's content matches HashData's length. Also, there is a NULL_PTR
                         check for both pointers in the calling function.

  \ID VCA_KEYM_REMOTE_KEYELEMENTGET_CERTGETSTATUS
    \DESCRIPTION      Function Csm_KeyElementGet is possibly called outside its specification according to VCA
    \COUNTERMEASURE   \N The pointer Status is passed to this function from KeyM_CertGetStatus, where it has been
                         checked not to be a NULL_PTR. keyLength is a pointer to a stack variable in this function
                         and was set to 1.

  \ID VCA_KEYM_REMOTE_KEYELEMENTSET_CSRELEMENTSET
    \DESCRIPTION      Function Csm_KeyElementSet is possibly called outside its specification according to VCA
    \COUNTERMEASURE   \N ElementData and ElementDataLength are passed through to this function directly from the
                         API KeyM_CsrElementSet without manipulation.
                         KeyM_CsrElementSet's API contract requires the pointer pointer ElementData is valid and
                         ElementDataLength's content matches ElementData's length. Also, there is a NULL_PTR
                         check for the pointer in the calling function.

  \ID VCA_KEYM_REMOTE_REDIRECTVERIFYCHAIN_CONVERTUINT16
    \DESCRIPTION      Function KeyM_Utils_ConvertUint16ToUint8ArrayBigEndian is possibly called outside its
                      specification according to VCA
    \COUNTERMEASURE   \N The buffer in question is &serializedCertChainData[writtenLength]. The length of
                         the stack array serializedCertChainData is KEYM_REMOTE_CERTIFICATE_CHAIN_MAX_LENGTH.
                         writtenLength + 2 has been checked to be <= KEYM_REMOTE_CERTIFICATE_CHAIN_MAX_LENGTH
                         by an if expression right before this call.

  \ID VCA_KEYM_REMOTE_REDIRECTVERIFYCHAIN_MEMCPY
    \DESCRIPTION      Function VStdLib_MemCpy is possibly called outside its specification according to VCA
    \COUNTERMEASURE   \N The array certChainData and its contents have been passed to this function directly from
                      the API KeyM_VerifyCertificateChain or KeyM_VerifyCertificateChainWithConstPtr without
                      manipulation. It is part of the APIs' contract that the certDataLength member of every array
                      entry must match the length of the buffer behind the certData member. It has been checked
                      in the calling function that none of the array entries' certData members is a NULL_PTR.
                      i is limited by the loop condition to be < NumberOfCertificates and the API contract
                      states that the length of the certChainData array must be <= NumberOfCertificates, so the
                      array access is always legal.
                      serializedCertChainData is an array on the stack with a length of
                      KEYM_REMOTE_CERTIFICATE_CHAIN_MAX_LENGTH.
                      writtenLength + (certChainData[i].certDataLength) +
                      KEYM_REMOTE_CERTIFICATE_CHAIN_POS_CERTDATA has been checked by an if statement before
                      this call to be <= KEYM_REMOTE_CERTIFICATE_CHAIN_MAX_LENGTH.
                      Thus, the write access for (certChainData[i].certDataLength) bytes at
                      &serializedCertChainData[writtenLength + KEYM_REMOTE_CERTIFICATE_CHAIN_POS_CERTDATA]
                      is legal.

  \ID VCA_KEYM_REMOTE_AEADDECRYPT_SETCERTIFICATEINGROUP
    \DESCRIPTION      Function Csm_AEADDecrypt is possibly called outside its specification according to VCA
    \COUNTERMEASURE   \N RequestData and RequestDataLength are passed through to this function directly from the
                         API KeyM_SetCertificateInGroup without manipulation.
                         KeyM_SetCertificateInGroup's API contract requires that the pointer is valid and
                         RequestDataLength matches RequestData's length. Also, there is a NULL_PTR
                         check for the pointer in the calling function.
                         All other pointers that are passed to the function point to local variables of
                         this function and the respective passed lengths match the length of the respective
                         buffers.

  \ID VCA_KEYM_REMOTE_AEADDECRYPT_VERIFYCERTIFICATECHAIN
    \DESCRIPTION      Function Csm_AEADDecrypt is possibly called outside its specification according to VCA
    \COUNTERMEASURE   \R All passed pointers point to local variables of this function and the respective passed
                         lengths match the length of the respective buffers.
                         This is valid with the exception of serializedCertChainDataLength. This length is ensured to
                         be <= the length of serializedCertChainData by the control flow in the for loop that precedes
                         this call. Check justification VCA_KEYM_REMOTE_REDIRECTVERIFYCHAIN_MEMCPY for details.

  \ID VCA_KEYM_CERT_CERTELEMENTFIRSTINITIALIZEITERATOR_RETURNED_E_OK
    \DESCRIPTION      Assertions may fail according to  VCA
    \COUNTERMEASURE   \R There is a runtime check that ensures that this location can only be reached if
                         KeyM_Cert_CertElementGetFirstInitializeIterator returned E_OK.
                         There is only one control path in KeyM_Cert_CertElementGetFirstInitializeIterator that
                         results in E_OK being returned. At the end of this control path, the two assertions are also
                         present (without justification) and they hold.

  \ID VCA_KEYM_CERT_CERTELEMENTGETNEXTSTATICCHECKS_ROOTELEMENTIDX
    \DESCRIPTION      Assertion CertElementIterator->rootElementIdx < KeyM_GetSizeOfCertificateElement()
                      may fail according to  VCA
    \COUNTERMEASURE   \N This assertion is preceded by a check that ensures that this location is only reached if
                         CertElementIterator->rootElementIdx is less than
                         KeyM_GetCertificateElementEndIdxOfCertificate(CertElementIterator->certId).
                         Since VCA knows that CertElementIterator->certId is a valid certificate ID (there is a
                         VCA specification at KeyM_GetCertificateElementEndIdxOfCertificate that would fail otherwise)
                         and Use-Case CSL03 ensures that indices that are < EndIdx are valid, this location can
                         only be reached if CertElementIterator->rootElementIdx is valid, i.e., less than
                         KeyM_GetSizeOfCertificateElement().

  \ID VCA_KEYM_CERT_CERTELEMENTGETNEXTSTATICCHECKS_ROOTELEMENTIDX
    \DESCRIPTION      Assertion CertElementIterator->rootElementIdx < KeyM_GetSizeOfCertificateElement()
                      may fail according to  VCA
    \COUNTERMEASURE   \N CertElementIterator->rootElementIdx has been checked by KeyM_Cert_CertElementGetNextStaticChecks
                         to have a value < KeyM_GetSizeOfCertificateElement() (see assertions there).
                         The function only returns E_OK if this check is successful.
                         There is a check that E_OK was returned before this line, therefore the assertion must hold.

  \ID VCA_KEYM_CERT_CERTELEMENTGETNEXT
    \DESCRIPTION      Assertions may fail according to  VCA
    \COUNTERMEASURE   \N This location can only be reached if KeyM_Cert_CertElementGetNextUpdateIterator returned
                         E_OK. There is only one control path in KeyM_Cert_CertElementGetNextUpdateIterator that
                         results in E_OK being returned. At the end of this control path, this assertion is also
                         present and holds.

  \ID VCA_KEYM_CERT_CSRELEMENTSET_CONVERTUINT16
    \DESCRIPTION      KeyM_Utils_ConvertUint16ToUint8ArrayBigEndian is possibly called outside its specification
    \COUNTERMEASURE   \R The buffer that is passed to KeyM_Utils_ConvertUint16ToUint8ArrayBigEndian for write access
                         in question has been retrieved via KeyM_Cert_GetCertificateWriteBufferData.
                         There are assertions in place in KeyM_Cert_GetCertificateWriteBufferData that ensure that the
                         buffer pointer is valid and the returned length matches the buffer.
                         The buffer's length has been checked before this call to be >= (writtenLength +
                         elementDataLength + 4). Thus, a write access with 2 bytes to &ramBuffer.certData[writtenLength]
                         and &ramBuffer.certData[writtenLength + 2] is in bounds.

  \ID VCA_KEYM_CERT_CSRELEMENTSET_MEMCPY
    \DESCRIPTION      VStdLib_MemCpy is possibly called outside its specification
    \COUNTERMEASURE   \R The buffer that is passed to VStdLib_MemCpy for write access
                         in question has been retrieved via KeyM_Cert_GetCertificateWriteBufferData.
                         There are assertions in place in KeyM_Cert_GetCertificateWriteBufferData that ensure that the
                         buffer pointer is valid and the returned length matches the buffer.
                         The buffer's length has been checked before this call to be >= (writtenLength +
                         elementDataLength + 4). Thus, a write access with elementDataLength bytes to
                         &ramBuffer.certData[writtenLength + 4] is in bounds.
                         The buffer and the length that are passed for read access are passed down to this function from
                         the API KeyM_CsrElementSet. Its API contract states that elementData's length must be <=
                         elementDataLength.

  \ID VCA_KEYM_CERT_ISCSRELEMENTSET_CONVERTUINT16
    \DESCRIPTION      KeyM_Utils_ConvertUint8ArrayToUint16BigEndian is possibly called outside its specification
    \COUNTERMEASURE   \R The loop condition ensures that the loop is only entered if offset + 4 < certData.certDataLength.
                         KeyM_Cert_GetCertificateReadBufferData ensures that the returned pointer is at least of the
                         length of the contained buffer (see justifications there). Thus, a 2-byte read access at
                         certData.certData[offset] and certData.certData[offset + 2] is within the buffer's bounds.

  \ID VCA_KEYM_CERT_UPDATECSRELEMENT_REMAINDERBACKUP
    \DESCRIPTION      VStdLib_MemCpy from  &csrDataPtr[remainderCsrDataOffset] to remainderCsrData with length
                      remainderCsrDataLength
    \COUNTERMEASURE   \R Destination buffer:
                         remainderCsrData is a local buffer in this variable with a length of KEYM_ASN1_MAX_CSR_SIZE.
                         remainderCsrDataLength has been checked to be <= KEYM_ASN1_MAX_CSR_SIZE in a runtime check
                         before this call to VStdLib_MemCpy.
                         Source buffer:
                         csrDataPtr was retrieved together with the length certificateSlotLength from
                         KeyM_Cert_GetCertificateWriteBufferData and is thus a valid pointer. oldCsrLength was retrieved
                         via KeyM_Cert_GetCertificateWrittenLength for the same certificate. That function ensures
                         via assertions that the returned length is <= the size of the certificate's RAM buffer.
                         remainderCsrDataLength was calculated by subtracting another value from oldCsrLength.
                         There is a runtime check in place that ensures that the subtraction did now underflow before
                         this call to VStdLib_MemCpy.

  \ID VCA_KEYM_CERT_UPDATECSRELEMENT_NEWELEMENTCOPY
    \DESCRIPTION      VStdLib_MemCpy from  newCsrElementData to &csrDataPtr[csrElementOffset] with length
                      newCsrElementDataLength
    \COUNTERMEASURE   \R Destination buffer:
                         csrDataPtr and certificateSlotLength were retrieved from KeyM_Cert_GetCertificateWriteBufferData,
                         which has assertions in place that ensure that the retrieved length is <= the referenced
                         buffer's length.
                         There is a runtime check before this call to VStdLib_MemCpy that ensures that
                         (csrElementOffset + newCsrElementDataLength) <= certificateSlotLength.
                         Source buffer:
                         newCsrElementData and newCsrElementDataLength are passed to this function without modification
                         from the API KeyM_Cert_CsrElementSet. The API's contract states that the length of elementData
                         must be <= elementDataLength.

  \ID VCA_KEYM_CERT_UPDATECSRELEMENT_REMAINDERRESTORE
    \DESCRIPTION      VStdLib_MemCpy from  remainderCsrData to &csrDataPtr[csrElementOffset + newCsrElementDataLength]
                      with length remainderCsrDataLength
    \COUNTERMEASURE   \R Destination buffer:
                         csrDataPtr and certificateSlotLength were retrieved from KeyM_Cert_GetCertificateWriteBufferData,
                         which has assertions in place that ensure that the retrieved length is <= the referenced
                         buffer's length.
                         There is a runtime check before this call to VStdLib_MemCpy that ensures that
                         (csrElementOffset + newCsrElementDataLength + remainderCsrDataLength) <= certificateSlotLength.
                         Source buffer:
                         remainderCsrData is a local buffer in this variable with a length of KEYM_ASN1_MAX_CSR_SIZE.
                         remainderCsrDataLength has been checked to be <= KEYM_ASN1_MAX_CSR_SIZE in a runtime check
                         before this call to VStdLib_MemCpy.

  \ID VCA_KEYM_CERT_CSRINFOGENERATE_CONVERTUINT16
    \DESCRIPTION      KeyM_Utils_ConvertUint8ArrayToUint16BigEndian is possibly called outside its specification
                      &ramBuffer.certData[offset] and &ramBuffer.certData[offset + 2]
    \COUNTERMEASURE   \R There is a runtime check before this function call that ensures that
                         (offset + 4) >= writtenLength.
                         ramBuffer has been retrieved via KeyM_Cert_GetCertificateWriteBufferData and
                         writtenLength has been retrieved via KeyM_Cert_GetCertificateWrittenLength for the same
                         certificate ID. ramBuffer.certData is a pointer to the certificate's RAM mirror.
                         KeyM_Cert_GetCertificateWrittenLength has assertions in place that ensure that the returned
                         length is <= the certificate's RAM mirror's length.

  \ID VCA_KEYM_CERT_CSRINFOGENERATE_CSRINFOELEMENTS
    \DESCRIPTION      Assertion $lengthOf(CsrInfoElements[i].dataPtr) >= CsrInfoElements[i].dataLength may fail
    \COUNTERMEASURE   \R CsrInfoElements[i].dataPtr has been assigned the value &ramBuffer.certData[offset].
                         CsrInfoElements[i].dataLength has been assigned the value elementDataLength.
                         A runtime check before this assertion ensures that
                         (offset + elementDataLength) <= writtenLength. writtenLength is guaranteed to be a value
                         that is <= the length of ramBuffer.certData because
                         - KeyM_Cert_GetCertificateWriteBufferData returns a pointer to the certificate's RAM buffer
                         - KeyM_Cert_GetCertificateWrittenLength has assertions in place that ensure that the returned
                           length is a value <= the length of the certificate's RAM buffer

  \ID VCA_KEYM_NVBLOCK_WRITETOBLOCK_COPY_WRITEHEADER
    \DESCRIPTION      KeyM_NvBlock_WriteToBlock_Header is called for a 4-byte write access on NvMBufferPtr
    \COUNTERMEASURE   \S SMI-789741 ensures that NvMBufferPtr is valid and has a length of at least nvmBlockLength.
                      \R A run-time check ensures that nvmBlockLength is at least 4 bytes.

  \ID VCA_KEYM_NVBLOCK_WRITETOBLOCK_COPY_WRITEDATA
    \DESCRIPTION      VStdLib_MemCpy from certData.certData to &NvMBufferPtr[KEYM_CERT_SIZEOF_NVBLOCK_HEADER] with
                      a length of certData.certDataLength bytes
    \COUNTERMEASURE   \S SMI-789741 ensures that NvMBufferPtr is valid and has a length of at least nvmBlockLength.
                      \R Destination buffer:
                         A run-time check ensures that nvmBlockLength is at least certData.certDataLength bytes.
                         Source buffer:
                         certData was retrieved via KeyM_Cert_GetCertificateReadBufferData(). That function ensures
                         via assertions that certData.certDataLength is <= the length of the buffer referenced by
                         certData.certData.

  \ID VCA_KEYM_NVBLOCK_WRITETOBLOCK_COPY_WRITEZEROS
    \DESCRIPTION      VStdLib_MemClr on &NvMBufferPtr[nvmDataLength] a length of (nvmBlockLength - nvmDataLength) bytes
    \COUNTERMEASURE   \S SMI-789741 ensures that NvMBufferPtr is valid and has a length of at least nvmBlockLength.
                      \R A run-time check ensures that nvmBlockLength - nvmDataLength cannot underflow (i.e.,
                         nvmBlockLength >= nvmDataLength).

  \ID VCA_KEYM_NVBLOCK_READFROMBLOCK_COPY_READHEADER
    \DESCRIPTION      KeyM_Utils_ConvertUint8ArrayToUint16BigEndian is called for a 2-byte read access on
                      &NvMBufferPtr[KEYM_CERT_POS_NVBLOCK_LENGTH]
    \COUNTERMEASURE   \S SMI-789741 ensures that NvMBufferPtr is valid and has a length of at least nvmBlockLength.
                      \R A run-time check ensures that nvmBlockLength is at least 4 bytes.

  \ID VCA_KEYM_NVBLOCK_READFROMBLOCK_COPY_COPYDATA
    \DESCRIPTION      VStdLib_MemCpy from &NvMBufferPtr[KEYM_CERT_SIZEOF_NVBLOCK_HEADER] to ramBuffer.certData with
                      a length of certLength bytes
    \COUNTERMEASURE   \S SMI-789741 ensures that NvMBufferPtr is valid and has a length of at least nvmBlockLength.
                      \R Destination buffer:
                         ramBuffer was retrieved from KeyM_Cert_GetCertificateWriteBufferData. That function has
                         assertions in place that ensure that ramBuffer.certData has a length that is
                         >= ramBuffer.certDataLength. A runtime check ensures that
                         certLength <= ramBuffer.certDataLength.
                         Source buffer:
                         A run-time check ensures that nvmBlockLength is at least
                         (KEYM_CERT_SIZEOF_NVBLOCK_HEADER + certLength) bytes.

  \ID VCA_KEYM_CERT_KEYELEMENTGET_WRITEBUFFER
    \DESCRIPTION      Calling Csm_KeyElementGet with ramBuffer.certData as output buffer and &ramBuffer.certDataLength
                      as length pointer
    \COUNTERMEASURE   \N ramBuffer has been retrieved via KeyM_Cert_GetCertificateWriteBufferData.
                         KeyM_Cert_GetCertificateWriteBufferData has assertions in place that ensure that the
                         returned certData's length is >= the returned certDataLength.

  \ID VCA_KEYM_CERT_INITCHECK01
    \DESCRIPTION      Assertion KeyM_IsCertificateInitValueInfoUsedOfCertificate(certIdx)
    \COUNTERMEASURE   \R There is a check KeyM_Init() that ensures that the module is only successfully initialized
                         if for all certificates where (KeyM_GetStorageOfCertificate(certIdx) == KEYM_STORAGE_IN_ROM)
                         holds, KeyM_IsCertificateInitValueInfoUsedOfCertificate(certIdx) also holds.
                         The check is located in the subfunction KeyM_Cert_InitChecks().
                         Since all APIs abort immediately if the module is not initialized and the values are in
                         question are constant, it is ensured that the checked condition still holds when this
                         assertion is checked.
                         There is a runtime check that (KeyM_GetStorageOfCertificate(certIdx) == KEYM_STORAGE_IN_ROM)
                         before this assertion. For the above mentioned reasons, this implies that
                         KeyM_IsCertificateInitValueInfoUsedOfCertificate(certIdx) is TRUE.

  \ID VCA_KEYM_CERT_INITCHECK02
    \DESCRIPTION      Assertion KeyM_IsCertStorageUsedOfCertificate(certIdx)
    \COUNTERMEASURE   \R There is a check KeyM_Init() that ensures that the module is only successfully initialized
                         if for all certificates where (KeyM_GetStorageOfCertificate(certIdx) != KEYM_STORAGE_IN_ROM)
                         holds, KeyM_IsCertStorageUsedOfCertificate(certIdx) also holds.
                         The check is located in the subfunction KeyM_Cert_InitChecks().
                         Since all APIs abort immediately if the module is not initialized and the values are in
                         question are constant, it is ensured that the checked condition still holds when this
                         assertion is checked.
                         There is a runtime check that (KeyM_GetStorageOfCertificate(certIdx) != KEYM_STORAGE_IN_ROM)
                         before this assertion. For the above mentioned reasons, this implies that
                         KeyM_IsCertStorageUsedOfCertificate(certIdx) is TRUE.

  \ID VCA_KEYM_CERT_INITCHECK03_CERTSTORAGE
    \DESCRIPTION      Assertion KeyM_IsCertStorageUsedOfCertificate(certIdx)
    \COUNTERMEASURE   \R There is a check KeyM_Init() that ensures that the module is only successfully initialized
                         if for all certificates where KeyM_IsCertStorageWrittenLengthUsedOfCertificate(certIdx)
                         holds, KeyM_IsCertStorageUsedOfCertificate(certIdx) also holds.
                         The check is located in the subfunction KeyM_Cert_InitChecks().
                         Since all APIs abort immediately if the module is not initialized and the values are in
                         question are constant, it is ensured that the checked condition still holds when this
                         assertion is checked.
                         There is a runtime check that KeyM_IsCertStorageWrittenLengthUsedOfCertificate(certIdx)
                         before this assertion. For the above mentioned reasons, this implies that
                         KeyM_IsCertStorageUsedOfCertificate(certIdx) is TRUE.

  \ID VCA_KEYM_CERT_INITCHECK04
    \DESCRIPTION      length <= KEYM_MAX_NUM_CERT_ELEMENTS
                      with length = KeyM_GetCertificateElementLengthOfCertificate(certId)
    \COUNTERMEASURE   \R There is a check KeyM_Init() that ensures that the module is only successfully initialized
                         if the following holds for for all certificates:
                         KeyM_GetCertificateElementLengthOfCertificate <= KEYM_MAX_NUM_CERT_ELEMENTS.

  \ID VCA_KEYM_CERT_STORAGEWRITTENLENGTHSTARTIDX
    \DESCRIPTION      Assertion storageWrittenLengthStartIdx <= (KeyM_GetSizeOfCertStorage() - 2u)
    \COUNTERMEASURE   \R There is a runtime check that
                         (KeyM_GetCertStorageWrittenLengthLengthOfCertificate(CertId) >= 2u) before this assertion.
                         This is an implication of Qualified Use-Case CSL03 of ComStackLib.
                         Note that Certificate -> CertStorageWrittenLength is a 0:N indirection.
                         If the indirection was not present for the certificate, its length would be 0.

  \ID VCA_KEYM_CERT_GETHASH_MEMCPY
    \DESCRIPTION      VStdLib_MemCpy from KeyM_GetAddrCertHashStorage(hashStorageStartIdx) to hashData
                      with length hashLength
    \COUNTERMEASURE   \R Destination buffer:
                         hashData was provided by the user in an API call to KeyM_GetHash and was passed down to this
                         function without manipulation. It is part of KeyM_GetHash's API contract that the buffer
                         has a length of at least *hashDataLength.
                         There is a runtime check that ensures (*hashDataLength >= hashLength).
                         Source buffer: See VCA_KEYM_CSL03_PASSING_BUFFER.

  \ID VCA_KEYM_CERT_COMPUTECERTHASH_CSMHASH
    \DESCRIPTION      Calling Csm_Hash with
                          dataPtr =         certData.certData
                          dataLength =      certData.certDataLength
                          resultPtr =       KeyM_GetAddrCertHashStorage(hashStorageStartIdx)
                          resultLengthPtr = &hashLength
    \COUNTERMEASURE   \R Data:
                         certData was retrieved from KeyM_Cert_GetCertificateReadBufferData, which has assertions
                         in place that ensure that certData.certData has a length of >= certData.certDataLength.
                         Result:
                         At this point, hashLength has a value of KeyM_GetCertHashStorageLengthOfCertificate().
                         This is qualified use-case CSL03 of ComStackLib.

  \ID VCA_CERT_SERVICECERTIFICATECALLBACKNOTIFICATION_REQUESTID
    \DESCRIPTION      Assertion KeyM_Cert_RequestId < KeyM_GetSizeOfCertificate()
    \COUNTERMEASURE   \R There is a runtime check that ensures that
                         KeyM_Cert_IsCertRequestEqualTo(KEYM_CERT_REQUEST_SERVICE) has returned with TRUE.
                         KeyM_Cert_IsCertRequestEqualTo(KEYM_CERT_REQUEST_SERVICE) only returns with TRUE if
                         KeyM_Cert_RequestId < KeyM_GetSizeOfCertificate().

  \ID VCA_KEYM_CERT_PARSE_INIT
    \DESCRIPTION      Function call KeyM_Asn1_ParseInit is possibly called outside its specification
    \COUNTERMEASURE   \N The function's requirements (asn1ParseParam != NULL_PTR) and (asn1ParseDerivedBuffers != NULL_PTR)
                         hold since both parameters point to local variables.
                         The violation at this point is due to the type invariant of KeyM_Asn1_ParseType
                         that requires the asn1_nestingLevel member to be < KEYM_ASN1_PARSE_MAX_NESTING_LEVEL.
                         The violation is acceptable at this point because asn1ParseParam is an out-parameter of
                         KeyM_Asn1_ParseInit and its input values are not used. KeyM_Asn1_ParseInit merely
                         initializes asn1ParseParam with sensible values.

  \ID VCA_KEYM_CERT_PARSE
    \DESCRIPTION      Function call KeyM_Asn1_ParseData(certId, &asn1Parse, &asn1Param, start, length)
                      is possibly called outside its specification
    \COUNTERMEASURE   \N All of the function's requirements have been checked before the function call in an
                         assertion except the following:
                         - parameters &asn1Parse and &asn1Param are not NULL_PTR since they reference local variables
                         - (start + length) is <= KeyM_GetSizeOfCertificateElement() because start is a startIdx
                           and length a length of the same 1:N CSL indirection. This is qualified use-case CSL03
                           of ComStackLib.

  \ID VCA_KEYM_ASN1_PARSEDATA_PARSEPROCESSING
    \DESCRIPTION      Function KeyM_Asn1_ParseProcessing is possibly called outside its specification
    \COUNTERMEASURE   \N This call occurs in the function KeyM_Asn1_ParseData.
                         One of KeyM_Asn1_ParseData's function requirements is:
                         (elementList + noOfElementList) < KeyM_GetSizeOfCertificateElement().
                         Before the call to KeyM_Asn1_ParseProcessing, asn1ParseParam->elementList is set to
                         elementList and asn1ParseParam->noOfElementList is set to noOfElementList.
                         Therefore, KeyM_Asn1_ParseProcessing's requirement
                         (asn1ParseParam->elementList + asn1ParseParam->noOfElementList)
                         < KeyM_GetSizeOfCertificateElement() holds.


  \ID VCA_KEYM_ASN1_PARSEPROCESSING_CHECKPARSEDCERTELEMENTS
    \DESCRIPTION      Function KeyM_Asn1_CheckParsedCertElements is possibly called outside its specification
    \COUNTERMEASURE   \N This call occurs in the function KeyM_Asn1_ParseProcessing.
                         One of KeyM_Asn1_ParseProcessing's function requirements is:
                         (elementList + noOfElementList) < KeyM_GetSizeOfCertificateElement().
                         There is only one place in the program where the two values in question are writen, and that is KeyM_Asn1_ParseData.
                         KeyM_Asn1_ParseData is not in the call tree of KeyM_Asn1_ParseProcessing.
                         Since the condition was fulfilled when KeyM_Asn1_ParseProcessing was called and no modification of the parameteres
                         occurred, the condition still holds.


  \ID VCA_KEYM_ASN1_ASN1PARAM_ASN1ELEMENTIDX
    \DESCRIPTION      Assertion asn1ParseParam->asn1_element_idx < KEYM_MAX_NUM_CERT_ELEMENTS
    \COUNTERMEASURE   \R The value of asn1ParseParam->asn1_element_idx is limited by the for-loop condition to a value
                         < asn1ParseParam->noOfElementList. Right before the loop, asn1ParseParam->noOfElementList
                         has been asserted to have a value <= KEYM_MAX_NUM_CERT_ELEMENTS.
                         Therefore, asn1ParseParam->asn1_element_idx must be < KEYM_MAX_NUM_CERT_ELEMENTS.

  \ID VCA_KEYM_ASN1_ASN1PARAM_CURRENTELEMENTIDX
    \DESCRIPTION      Assertion asn1ParseParam->currentElementIdx < KeyM_GetSizeOfCertificateElement()
    \COUNTERMEASURE   \R The surrounding for loop ensures that asn1ParseParam->currentElementIdx at this place has a
                         value between asn1ParseParam->elementList and
                         ((asn1ParseParam->elementList + asn1ParseParam->noOfElementList) - 1).
                         It is requirement of this function that
                         (asn1ParseParam->elementList + asn1ParseParam->noOfElementList) <= KeyM_GetSizeOfCertificateElement().
                         Note furthermore that the only place in KeyM where a noOfElementList or elementList member
                         of a KeyM_Asn1_ParseType struct is manipulated is in KeyM_Asn1_ParseData, which is not in the
                         call tree below (but above) this function. Therefore, the values asn1ParseParam->elementList
                         and asn1ParseParam->noOfElementList cannot have changed since function entry.
                         Therefore, asn1ParseParam->currentElementIdx must have a value < KeyM_GetSizeOfCertificateElement().

  \ID VCA_KEYM_ASN1_PARSEPRIMITIVETAG_LOOPRETVAL_OK
    \DESCRIPTION      Assertion may fail
    \COUNTERMEASURE   \R This assertion is preceded by a check that (retVal == KEYM_ASN1_RC_OK).
                         The control flow of the for-loop above ensures that this can only happen via the loop's
                         break statement.
                         This exact same assertion is also present at the start of the for-loop's body.
                         Since the loop has exited via a break statement, the loop operation (i.e., incrementation)
                         has not manipulated the asserted value since the assertion at the top of the loop's body.
                         The value is also not altered by any function called in the loop or between the loop and
                         this assertion.
                         The assertion must thus still hold.

  \ID VCA_KEYM_CERT_GETELEMENTBYSTRUCTURETYPE_MEMCPY
    \DESCRIPTION      MemCpy to dataPtr with length elementLength
    \COUNTERMEASURE   \R This function has a requirement that ensures that $lengthOf(dataPtr) >= *dataLengthPtr.
                         A runtime check ensures that elementLength is <= *dataLengthPtr. pDst != NULL_PTR is ensured
                         by the function's specified requirements.

  \ID VCA_KEYM_CERT_CERTELEMENTGETNEXTCOPYDATA_MEMCPY
    \DESCRIPTION      MemCpy to CertElementData with length CertElementIterator->elementLength
    \COUNTERMEASURE   \R This function is called in the call trees of KeyM_CertElementGetFirst,
                         KeyM_CertElementGetNext and KeyM_CertificateElementGetByIndex.
                         All 3 APIs have parameters CertElementData and CertElementDataLength that are passed down
                         to this function. All APIs' API contract requires that the length of the buffer referenced
                         by CertElementData is >= *CertElementDataLength.
                         There is a runtime check in this function that ensures that
                         *CertElementDataLength >= CertElementIterator->elementLength.

  \ID VCA_KEYM_CERT_CERTSTRUCTUREGET_GETELEMENTBYSTRUCTURETYPE
    \DESCRIPTION      Called function's requirement *dataLengthPtr >= $lengthOf(dataPtr) may be violated
                      Passed values are dataPtr = CertStructureData, dataLengthPtr = CertStructureDataLength.
    \COUNTERMEASURE   \R This function is only called from KeyM_CertStructureGet. The parameters CertStructureData
                         and CertStructureDataLength are passed through to this function from the API.
                         The API's contract requires that the length of the buffer referenced by CertStructureData
                         must be >= *CertStructureDataLength. CertStructureData != NULL_PTR is verified on the API level
                         at runtime.

  \ID VCA_KEYM_CERT_CERTSTRUCTUREGET_MEMCPY
    \DESCRIPTION      MemCpy to CertStructureData with length structureLength
    \COUNTERMEASURE   \R This function is only called from KeyM_CertStructureGet. The parameters CertStructureData
                         and CertStructureDataLength are passed through to this function from the API.
                         The API's contract requires that the length of the buffer referenced by CertStructureData
                         must be >= *CertStructureDataLength.
                         There is a runtime check that ensures that *CertStructureDataLength >= structureLength.
                         CertStructureData != NULL_PTR is verified on the API level at runtime.

  \ID VCA_KEYM_CERT_CERTELEMENTGET_MEMCPY
    \DESCRIPTION      MemCpy to CertElementData with length parsedElementLength
    \COUNTERMEASURE   \R This function is only called from KeyM_CertElementGet. The parameters CertElementData
                         and CertElementDataLength are passed through to this function from the API.
                         The API's contract requires that the length of the buffer referenced by CertElementData
                         must be >= *CertElementDataLength.
                         There is a runtime check that ensures that *CertElementDataLength >= parsedElementLength.

  \ID VCA_KEYM_CERT_GETSUBJECTCOMMONNAME_MEMCPY
    \DESCRIPTION      MemCpy to subjectCommonNameData with length asn1Param.last_tag_len
    \COUNTERMEASURE   \R This function has a requirement that ensures that $lengthOf(subjectCommonNameData) >= *subjectCommonNameDataLength.
                         A runtime check ensures that asn1Param.last_tag_len is <= *subjectCommonNameDataLength.
                         pSrc is guaranteed to not NULL because requestData is passed through directly from
                         KeyM_SetCertificateInGroup which includes a runtime check for NULL.

  \ID VCA_KEYM_CERT_SEARCHELEMENTBYSTRUCTURETYPE
    \DESCRIPTION      Assertion elementIdxLocal < KeyM_GetSizeOfCertificateElement()
    \COUNTERMEASURE   \N At this point elementIdxLocal, either has its initial value of 0 (which is less than
                         KeyM_GetSizeOfCertificateElement()) or a value that was assigned in the loop from i.
                         i is limited in the loop body by the loop condition to be less than
                         KeyM_GetCertificateElementEndIdxOfCertificate().
                         Qualified use-case CSL03 of ComStackLib guarantees that
                         KeyM_GetCertificateElementEndIdxOfCertificate() <= KeyM_GetSizeOfCertificateElement().

  \ID VCA_KEYM_ASN1_INITDERIVED_BASEPTR
    \DESCRIPTION      Assertion rootParamDataPtr->base_data_ptr != NULL_PTR
    \COUNTERMEASURE   \R This function contains a runtime check for rootParamDataPtr->baseDataPtr == NULL. If that is
                         the case, the assertion is not reached.

  \ID VCA_KEYM_CERT_APPENDCRE_MEMCPY_ISSUERNAME
    \DESCRIPTION MemCpy to creStorageIssuer from IssuerNameData with length IssuerNameDataLength
    \COUNTERMEASURE \N Destination buffer: see VCA_KEYM_CSL03_PASSING_BUFFER
                       Source buffer: IssuerNameData and IssuerNameDataLength have been passed down to this
                       function from KeyM_SetCRE without modification. KeyM_SetCRE's API contract ensures that
                       IssuerNameData is valid (there is also a run-time null-check in the API) and has a length
                       of at least IssuerNameDataLength bytes.

  \ID VCA_KEYM_CERT_APPENDCRE_MEMCPY_SERIAL
    \DESCRIPTION MemCpy to creStorageIssuer from SerialNumberData with length SerialNumberDataLength
    \COUNTERMEASURE \N Destination buffer: see VCA_KEYM_CSL03_PASSING_BUFFER
                       Source buffer: SerialNumberData and SerialNumberDataLength have been passed down to this
                       function from KeyM_SetCRE without modification. KeyM_SetCRE's API contract ensures that
                       SerialNumberData is valid (there is also a run-time null-check in the API) and has a length
                       of at least SerialNumberDataLength bytes.

  \ID VCA_KEYM_CERT_INITCSR
    \DESCRIPTION      Function KeyM_Asn1_InitCSR is possibly called outside its specification
    \COUNTERMEASURE   \N All of the function's requirements have been checked via assertions right before the
                         function call except for the requirement ($lengthOf(responseData) >= *responseDataLength).
                         At this point, responseData=ResponseData and responseDataLength=ResponseDataLength.
                         ResponseData and ResponseDataLength are passed to this function from the API KeyM_InitCSR.
                         Its API contract requires that both pointers are valid (this is also checked in a runtime-check
                         in the API function) and *ResponseDataLength is >= the length of the buffer referenced by
                         ResponseData.

  \ID VCA_KEYM_CERT_CSRINFOGENERATE_INITCSR
    \DESCRIPTION      Function KeyM_Asn1_InitCSR is possibly called outside its specification
    \COUNTERMEASURE   \N All of the function's requirements have been checked via assertions right before the
                         function call except for the requirements ($lengthOf(responseData) >= *responseDataLength),
                         (responseData != NULL_PTR) and (responseDataLength != NULL_PTR).
                         These three requirements are fulfilled because they directly match this function's
                         requirements for the passed parameters csrInfo and csrInfoLength.

  \ID VCA_KEYM_CERT_SERVICEREQUESTCSR_CSRINFOGENERATE
    \DESCRIPTION      Function KeyM_Cert_CsrInfoGenerate is possibly called outside its specification
    \COUNTERMEASURE   \N The function's requirements are ($lengthOf(csrInfo) >= *csrInfoLength),
                         (csrInfo != NULL_PTR) and (csrInfoLength != NULL_PTR).
                         It is guaranteed that (csrInfoLength != NULL_PTR) because it is a pointer to
                         ramBuffer.certDataLength, which is located on the stack.
                         ramBuffer has been retrieved via KeyM_Cert_GetCertificateWriteBufferData, which has
                         assertions in place that ensure that ramBuffer.certData is != NULL_PTR and has a length
                         of >= ramBuffer.certDataLength.

  \ID VCA_KEYM_ASN1_CERTELEMENTGETBYSTRUCTURETYPE_MEMCPY
    \DESCRIPTION      Function call VStdLib_MemCpyLarge(certElementData, &basePtr[elementOffset], elementDataLength)
                      is possibly outside its specification
    \COUNTERMEASURE   \N The function's requirements are ($lengthOf(certElementData) >= elementDataLength),
                         (certElementData != NULL_PTR) and (&basePtr[elementOffset] != NULL_PTR).
                         - elementDataLength is ensured by control flow to be <= elementDataLength *certElementDataLength.
                           One of the calling function's requirements is $lengthOf(certElementData) >= *certElementDataLength.
                           This ensure that $lengthOf(certElementData) >= elementDataLength.
                         - An assertion ensures that certElementData != NULL_PTR.
                         - An assertion ensures that basePtr != NULL_PTR. This means that &basePtr[elementOffset]
                           cannot be a NULL_PTR.

  \ID VCA_KEYM_CERT_CERTELEMENTGETBYSTRUCTURETYPE_ASN1CALL
    \DESCRIPTION      Function call KeyM_Asn1_CertElementGetByStructureType(&asn1Parse, &asn1Param, CertStructure,
                      CertElementData, CertElementDataLength) is possibly outside its specification
    \COUNTERMEASURE   \N The function's requirements are (ptr != NULL_PTR) for ptr in {&asn1Parse, &asn1Param,
                         CertElementData, CertElementDataLength}, and
                         ($lengthOf(CertElementData) >= *CertElementDataLength).
                         - An assertion ensures that CertElementData != NULL_PTR.
                         - An assertion ensures that CertElementDataLength != NULL_PTR.
                         - &asn1Parse points to an element on the calling function's stack frame and is thus != NULL_PTR
                         - &asn1Param points to an element on the calling function's stack frame and is thus != NULL_PTR
                         - $lengthOf(CertElementData) >= *CertElementDataLength is part of the calling function's
                           API contract and documented in its doxygen.

  VCA_JUSTIFICATION_END */

/**********************************************************************************************************************
 *  END OF FILE
 *********************************************************************************************************************/
