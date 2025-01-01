/**********************************************************************************************************************
 *  FILE REQUIRES USER MODIFICATIONS
 *  Template Scope: sections marked with Start and End comments
 *  -------------------------------------------------------------------------------------------------------------------
 *  This file includes template code that must be completed and/or adapted during BSW integration.
 *  The template code is incomplete and only intended for providing a signature and an empty implementation.
 *  It is neither intended nor qualified for use in series production without applying suitable quality measures.
 *  The template code must be completed as described in the instructions given within this file and/or in the.
 *  Technical Reference.
 *  The completed implementation must be tested with diligent care and must comply with all quality requirements which.
 *  are necessary according to the state of the art before its use.
 *********************************************************************************************************************/



/**********************************************************************************************************************
 *  BETA MODULE
 *  -------------------------------------------------------------------------------------------------------------------
 *  Beta Modules and Beta Features are basically operable, but not sufficiently tested, verified and/or qualified
 *  for use in series production and/or in vehicles operating on public or non-public roads.
 *  Please consult the Product Information for details.
 *********************************************************************************************************************/



/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *             File:  Ct_MBBL_SsaAppl_General.c
 *           Config:  D:/starter_kit_classic_aurix/examples/can_lin_eth/msr/MBBL_EthCanLin.dpa
 *        SW-C Type:  Ct_MBBL_SsaAppl_General
 *  Generation Time:  2021-03-24 14:58:25
 *
 *        Generator:  MICROSAR RTE Generator Version 4.24.0.34012
 *                    RTE Core Version 1.24.0
 *          License:  PAI194
 *
 *      Description:  C-Code implementation template for SW-C <Ct_MBBL_SsaAppl_General>
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of version logging area >>                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 *  -------------------------------------------------------------------------------------------------------------------
 *  EXAMPLE CODE ONLY
 *  -------------------------------------------------------------------------------------------------------------------
 *  This Example Code is only intended for illustrating an example of a possible BSW integration and BSW
 *  configuration. The Example Code has not passed any quality control measures and may be incomplete. The
 *  Example Code is neither intended nor qualified for use in series production. The Example Code as well
 *  as any of its modifications and/or implementations must be tested with diligent care and must comply
 *  with all quality requirements which are necessary according to the state of the art before their use.
 *********************************************************************************************************************/
/* PRQA S 0777, 0779 EOF */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of version logging area >>                  DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *
 * AUTOSAR Modelling Object Descriptions
 *
 **********************************************************************************************************************
 *
 * Data Types:
 * ===========
 * NvM_RequestResultType
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * Ssa_KeyStorageTaskType
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * Ssa_KeyStorageUseCaseType
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 *
 * Port Prototypes:
 * ================
 * R_ICS_KeyStorage_ST3
 *   Requests for storing the key material or certificates permanently i.e. for making them persistent.
 *
 *
 * Mode Declaration Groups:
 * ========================
 * Coding_MemoryStatus
 *   Notifies the Ssa of memory status changes while storing or restoring the Variant Coding Data to or from non-volatile memory.
 *
 * Coding_Mode
 *   Coding state
 *
 * Coding_Mode
 *   Notifies application about an ongoing, successful or failed coding attempt.
 *
 * RightsM_AuthenticationMode
 *   RIGHTSM_AUTHENTICATED - A Tester was successfully authenticated
 *      RIGHTSM_UNAUTHENTICATED - No tester was authenticated
 *
 * WdgM_Mode
 *   The mode declaration group WdgMMode represents the modes of the Watchdog Manager module that will be notified to the SW-Cs / CDDs and the RTE.
 *
 *
 * Mode Declarations:
 * ==================
 * CODING_ACTIVE of Mode Declaration Group Coding_Mode
 *   Active
 *
 * CODING_FAILED of Mode Declaration Group Coding_Mode
 *   Failed
 *
 * CODING_OK of Mode Declaration Group Coding_Mode
 *   Ok
 *
 *********************************************************************************************************************/

#include "Rte_Ct_MBBL_SsaAppl_General.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
#include "vstdlib.h"
#include "DiagFunction_Public.h"
#include "Csm.h"
#include "Crypto_30_vHsm.h"
#include "Ssa.h"

FUNC(Std_ReturnType, Ct_MBBL_SsaAppl_General_CODE) R_ICS_KeyStorage_ST3_Initial(Ssa_KeyStorageUseCaseType keyStorageUseCase);
FUNC(Std_ReturnType, Ct_MBBL_SsaAppl_General_CODE) R_ICS_KeyStorage_ST3_CheckState(Ssa_KeyStorageUseCaseType keyStorageUseCase);

/* EXTERN Variables */
extern tAppCommonData DiagCommonData;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of include and declaration area >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *
 * Used AUTOSAR Data Types
 *
 **********************************************************************************************************************
 *
 * Primitive Types:
 * ================
 * boolean: Boolean (standard type)
 * dtRef_VOID: DataReference
 * dtRef_const_VOID: DataReference
 * uint8: Integer in interval [0...255] (standard type)
 *
 * Enumeration Types:
 * ==================
 * NvM_RequestResultType: Enumeration of integer in interval [0...8] with enumerators
 *   NVM_REQ_OK (0U)
 *   NVM_REQ_NOT_OK (1U)
 *   NVM_REQ_PENDING (2U)
 *   NVM_REQ_INTEGRITY_FAILED (3U)
 *   NVM_REQ_BLOCK_SKIPPED (4U)
 *   NVM_REQ_NV_INVALIDATED (5U)
 *   NVM_REQ_CANCELED (6U)
 *   NVM_REQ_REDUNDANCY_FAILED (7U)
 *   NVM_REQ_RESTORED_FROM_ROM (8U)
 * Ssa_KeyStorageTaskType: Enumeration of integer in interval [0...255] with enumerators
 *   SSA_KEYSTORAGE_TASK_INITIAL (0U)
 *   SSA_KEYSTORAGE_TASK_CHECKSTATE (1U)
 *   SSA_KEYSTORAGE_TASK_CANCEL (2U)
 * Ssa_KeyStorageUseCaseType: Enumeration of integer in interval [0...255] with enumerators
 *   SSA_KEYSTORAGE_USECASE_CRYPTO (0U)
 *   SSA_KEYSTORAGE_USECASE_CERTIFICATES (1U)
 *   SSA_KEYSTORAGE_USECASE_TRUST_MODEL_CERTIFICATES (2U)
 *   SSA_KEYSTORAGE_USECASE_TRUST_MODEL_ROOT_CERTIFICATE (3U)
 *
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *
 * APIs which are accessible from all runnable entities of the SW-C
 *
 **********************************************************************************************************************
 * Calibration Parameters:
 * =======================
 *   Calibration Component Calibration Parameters:
 *   ---------------------------------------------
 *   uint8 Rte_Prm_Pp_InputFileVersions_DiagnosticVariant(void)
 *   uint8 Rte_Prm_Pp_InputFileVersions_DiagnosticVersion(void)
 *
 *********************************************************************************************************************/


#define Ct_MBBL_SsaAppl_General_START_SEC_CODE
#include "Ct_MBBL_SsaAppl_General_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Ct_MBBL_SsaAppl_General_Init
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Ct_MBBL_SsaAppl_General_Init_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, Ct_MBBL_SsaAppl_General_CODE) Ct_MBBL_SsaAppl_General_Init(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Ct_MBBL_SsaAppl_General_Init
 *********************************************************************************************************************/
  //uint8 DummyVal[32];
  //VStdLib_MemSet(DummyVal, 0x55, 32);

  //(void)Rte_Call_Ssa_RandomSeed_RandomSeed(DummyVal, 32);

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: KeyMCertificateNotification_Ssa_TrustModelCert_Server_CertificateVerifyCallbackNotification
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <CertificateVerifyCallbackNotification> of PortPrototype <KeyMCertificateNotification_Ssa_TrustModelCert_Server>
 *
 **********************************************************************************************************************
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
 *   Std_ReturnType Rte_Call_KeyMCertificateNotification_Ssa_TrustModelCert_Client_CertificateVerifyCallbackNotification(KeyM_CertificateStatusType Result)
 *     Synchronous Service Invocation. Timeout: None
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void KeyMCertificateNotification_Ssa_TrustModelCert_Server_CertificateVerifyCallbackNotification(KeyM_CertificateStatusType Result)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: KeyMCertificateNotification_Ssa_TrustModelCert_Server_CertificateVerifyCallbackNotification_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, Ct_MBBL_SsaAppl_General_CODE) KeyMCertificateNotification_Ssa_TrustModelCert_Server_CertificateVerifyCallbackNotification(KeyM_CertificateStatusType Result) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: KeyMCertificateNotification_Ssa_TrustModelCert_Server_CertificateVerifyCallbackNotification
 *********************************************************************************************************************/
 /* discard if result indicates no error, workaround for ESCAN00111234 */
/* 	if (Result != KEYM_RT_OK)
	{
		Ssa_KeyM_KeyMCertificateVerifyCallback(Result);
	} */

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: KeyMCertificateNotification_Ssa_TrustModelCert_Server_ServiceCertificateCallbackNotification
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ServiceCertificateCallbackNotification> of PortPrototype <KeyMCertificateNotification_Ssa_TrustModelCert_Server>
 *
 **********************************************************************************************************************
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
 *   Std_ReturnType Rte_Call_KeyMCertificateNotification_Ssa_TrustModelCert_Client_ServiceCertificateCallbackNotification(KeyM_ResultType Result, uint16 ResponseDataLength, KeyM_const_CryptoKeyDataType ResponseData)
 *     Synchronous Service Invocation. Timeout: None
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void KeyMCertificateNotification_Ssa_TrustModelCert_Server_ServiceCertificateCallbackNotification(KeyM_ResultType Result, uint16 ResponseDataLength, KeyM_const_CryptoKeyDataType ResponseData)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: KeyMCertificateNotification_Ssa_TrustModelCert_Server_ServiceCertificateCallbackNotification_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, Ct_MBBL_SsaAppl_General_CODE) KeyMCertificateNotification_Ssa_TrustModelCert_Server_ServiceCertificateCallbackNotification(KeyM_ResultType Result, uint16 ResponseDataLength, KeyM_const_CryptoKeyDataType ResponseData) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: KeyMCertificateNotification_Ssa_TrustModelCert_Server_ServiceCertificateCallbackNotification
 *********************************************************************************************************************/
 /* forward */
	/* Ssa_KeyM_KeyMServiceCertificateCallback(Result, ResponseDataLength, ResponseData); */

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: R_ICS_DiagInfo_ST3_Get
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Get> of PortPrototype <R_ICS_DiagInfo_ST3>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType R_ICS_DiagInfo_ST3_Get(uint8 *diagVersion, uint8 *diagVariant)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_Ssa_RightsM_DiagnosticInformation_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: R_ICS_DiagInfo_ST3_Get_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, Ct_MBBL_SsaAppl_General_CODE) R_ICS_DiagInfo_ST3_Get(P2VAR(uint8, AUTOMATIC, RTE_CT_MBBL_SSAAPPL_GENERAL_APPL_VAR) diagVersion, P2VAR(uint8, AUTOMATIC, RTE_CT_MBBL_SSAAPPL_GENERAL_APPL_VAR) diagVariant) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: R_ICS_DiagInfo_ST3_Get (returns application error)
 *********************************************************************************************************************/
  *diagVariant = DiagCommonData.ActiveDiagnosticInformation[1u]; /* 1u = variant */
  *diagVersion = DiagCommonData.ActiveDiagnosticInformation[2u]; /* 2u = version */

  return RTE_E_OK;
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: R_ICS_KeyStorage_ST3_StorePermanently
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <StorePermanently> of PortPrototype <R_ICS_KeyStorage_ST3>
 *
 **********************************************************************************************************************
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
 *   Std_ReturnType Rte_Call_NvM_Ssa_TrustModelEcuCert_EraseBlock(void)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvM_Ssa_TrustModelEcuCert_GetErrorStatus(NvM_RequestResultType *ErrorStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvM_Ssa_TrustModelEcuCert_InvalidateNvBlock(void)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvM_Ssa_TrustModelEcuCert_ReadBlock(dtRef_VOID DstPtr)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvM_Ssa_TrustModelEcuCert_SetRamBlockStatus(boolean RamBlockStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvM_Ssa_TrustModelEcuCert_WriteBlock(dtRef_const_VOID SrcPtr)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvM_Ssa_TrustModelIntermediateCert_EraseBlock(void)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvM_Ssa_TrustModelIntermediateCert_GetErrorStatus(NvM_RequestResultType *ErrorStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvM_Ssa_TrustModelIntermediateCert_InvalidateNvBlock(void)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvM_Ssa_TrustModelIntermediateCert_ReadBlock(dtRef_VOID DstPtr)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvM_Ssa_TrustModelIntermediateCert_SetRamBlockStatus(boolean RamBlockStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvM_Ssa_TrustModelIntermediateCert_WriteBlock(dtRef_const_VOID SrcPtr)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_E_NOT_OK
 *   Std_ReturnType Rte_Call_Nvm_Ssa_TrustModelBackendCert_EraseBlock(void)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_E_NOT_OK
 *   Std_ReturnType Rte_Call_Nvm_Ssa_TrustModelBackendCert_GetErrorStatus(NvM_RequestResultType *ErrorStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_E_NOT_OK
 *   Std_ReturnType Rte_Call_Nvm_Ssa_TrustModelBackendCert_InvalidateNvBlock(void)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_E_NOT_OK
 *   Std_ReturnType Rte_Call_Nvm_Ssa_TrustModelBackendCert_ReadBlock(dtRef_VOID DstPtr)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_E_NOT_OK
 *   Std_ReturnType Rte_Call_Nvm_Ssa_TrustModelBackendCert_SetRamBlockStatus(boolean RamBlockStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_E_NOT_OK
 *   Std_ReturnType Rte_Call_Nvm_Ssa_TrustModelBackendCert_WriteBlock(dtRef_const_VOID SrcPtr)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_E_NOT_OK
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType R_ICS_KeyStorage_ST3_StorePermanently(Ssa_KeyStorageUseCaseType keyStorageUseCase, Ssa_KeyStorageTaskType keyStorageTask)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_Ssa_KeyStorage_E_NOT_OK
 *   RTE_E_Ssa_KeyStorage_E_PENDING
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: R_ICS_KeyStorage_ST3_StorePermanently_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, Ct_MBBL_SsaAppl_General_CODE) R_ICS_KeyStorage_ST3_StorePermanently(Ssa_KeyStorageUseCaseType keyStorageUseCase, Ssa_KeyStorageTaskType keyStorageTask) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: R_ICS_KeyStorage_ST3_StorePermanently (returns application error)
 *********************************************************************************************************************/
  Std_ReturnType retval = RTE_E_OK;

  switch (keyStorageTask)
  {
    case SSA_KEYSTORAGE_TASK_INITIAL:
      retval = R_ICS_KeyStorage_ST3_Initial(keyStorageUseCase);
      break;
    case SSA_KEYSTORAGE_TASK_CHECKSTATE:
      retval = R_ICS_KeyStorage_ST3_CheckState(keyStorageUseCase);
      break;
    case SSA_KEYSTORAGE_TASK_CANCEL:
      /* It is up to you to decide how to proceed in this case. */
      break;
    default:
      break;
  }

  return retval;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}


#define Ct_MBBL_SsaAppl_General_STOP_SEC_CODE
#include "Ct_MBBL_SsaAppl_General_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of function definition area >>            DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
FUNC(Std_ReturnType, Ct_MBBL_SsaAppl_General_CODE) R_ICS_KeyStorage_ST3_Initial(Ssa_KeyStorageUseCaseType keyStorageUseCase)
{
  Std_ReturnType retVal = E_NOT_OK;
  uint8 keyPtr[1] = { 0 };
  switch (keyStorageUseCase)
  {
    case SSA_KEYSTORAGE_USECASE_CRYPTO:
	case SSA_KEYSTORAGE_USECASE_TRUST_MODEL_CERTIFICATES:
	case SSA_KEYSTORAGE_USECASE_TRUST_MODEL_ROOT_CERTIFICATE:
      /* Dispatch the write job for the crypto keys */
	  // The job triggers a synchronous write to the HSM. by the time the function returns the job is finished
      retVal = Csm_KeyElementSet(CsmConf_CsmKey_CsmKey_vHsm_Info, CryptoConf_CryptoKeyElement_Crypto_30_vHsm_vHsm_Core_vHsmInfo_PerformPersist, &keyPtr[0], 1);
      break;
	case SSA_KEYSTORAGE_USECASE_CERTIFICATES:
		/* Dispatch the write job for the crypto keys */
		//The Diagnostic Certificate chain is set to be stored directly when changed, no job is needed.
		retVal = E_OK;
		break;
    default:
      break;
  }
  return retVal;
}


FUNC(Std_ReturnType, Ct_MBBL_SsaAppl_General_CODE) R_ICS_KeyStorage_ST3_CheckState(Ssa_KeyStorageUseCaseType keyStorageUseCase)
{
  Std_ReturnType retval = E_NOT_OK;
  switch (keyStorageUseCase)
  {
    case SSA_KEYSTORAGE_USECASE_CRYPTO:
	case SSA_KEYSTORAGE_USECASE_CERTIFICATES:
	case SSA_KEYSTORAGE_USECASE_TRUST_MODEL_CERTIFICATES:
	case SSA_KEYSTORAGE_USECASE_TRUST_MODEL_ROOT_CERTIFICATE:
      /* Check the JobState of the write job for the crypto keys, and Fall Through for DiagChain handled in HSM */
      // JobState = ...
		return E_OK;
      break;
    default:
      break;
  }

  return retval;
}




/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of function definition area >>              DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of removed code area >>                   DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/



#if 0
/***  Start of saved code (symbol: runnable implementation:R_ICS_RngSeed_ST3_GetTrueRandom)  ****************/
  Std_ReturnType retval;
  uint32 rngDataLength = 32;
#if(1)
  retval = Rte_Call_CsmJob_TRNG_RandomGenerate_RandomGenerate(data, &rngDataLength);
#else
  retval = 0;
#endif
  *dataLength = (uint16)rngDataLength;

  return retval;

/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: documentation area:R_ICS_RngSeed_ST3_GetTrueRandom_doc)  *****************/


/***  End of saved code  ************************************************************************************/
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of removed code area >>                     DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 MISRA 2012 violations and justifications
 *********************************************************************************************************************/

/* module specific MISRA deviations:
   MD_Rte_0624:  MISRA rule: Rule8.3
     Reason:     This MISRA violation is a consequence from the RTE requirements [SWS_Rte_01007] [SWS_Rte_01150].
                 The typedefs are never used in the same context.
     Risk:       No functional risk. Only a cast to uint8* is performed.
     Prevention: Not required.

   MD_Rte_3206:  MISRA rule: Rule2.7
     Reason:     The parameter are not used by the code in all possible code variants.
     Risk:       No functional risk.
     Prevention: Not required.

*/
