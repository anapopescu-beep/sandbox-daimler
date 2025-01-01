/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *             File:  Rte_Ct_MBBL_SsaAppl_General.h
 *           Config:  StartApplication.dpa
 *      ECU-Project:  StartApplication
 *
 *        Generator:  MICROSAR RTE Generator Version 4.32.0
 *                    RTE Core Version 4.32.0
 *          License:  CBD2200333
 *
 *      Description:  Application header file for SW-C <Ct_MBBL_SsaAppl_General>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef RTE_CT_MBBL_SSAAPPL_GENERAL_H
# define RTE_CT_MBBL_SSAAPPL_GENERAL_H

# ifndef RTE_CORE
#  ifdef RTE_APPLICATION_HEADER_FILE
#   error Multiple application header files included.
#  endif
#  define RTE_APPLICATION_HEADER_FILE
#  ifndef RTE_PTR2ARRAYBASETYPE_PASSING
#   define RTE_PTR2ARRAYBASETYPE_PASSING
#  endif
# endif

# ifdef __cplusplus
extern "C"
{
# endif /* __cplusplus */

/* include files */

# include "Rte_Ct_MBBL_SsaAppl_General_Type.h"
# include "Rte_DataHandleType.h"


# ifndef RTE_CORE

/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (unmapped) for synchronous C/S communication
 *********************************************************************************************************************/
#  define Rte_Call_NvM_Ssa_TrustModelEcuCert_EraseBlock() (RTE_E_UNCONNECTED)
#  define Rte_Call_NvM_Ssa_TrustModelEcuCert_GetErrorStatus(arg1) (RTE_E_UNCONNECTED)
#  define Rte_Call_NvM_Ssa_TrustModelEcuCert_InvalidateNvBlock() (RTE_E_UNCONNECTED)
#  define Rte_Call_NvM_Ssa_TrustModelEcuCert_ReadBlock(arg1) (RTE_E_UNCONNECTED)
#  define Rte_Call_NvM_Ssa_TrustModelEcuCert_SetRamBlockStatus(arg1) (RTE_E_UNCONNECTED)
#  define Rte_Call_NvM_Ssa_TrustModelEcuCert_WriteBlock(arg1) (RTE_E_UNCONNECTED)
#  define Rte_Call_NvM_Ssa_TrustModelIntermediateCert_EraseBlock() (RTE_E_UNCONNECTED)
#  define Rte_Call_NvM_Ssa_TrustModelIntermediateCert_GetErrorStatus(arg1) (RTE_E_UNCONNECTED)
#  define Rte_Call_NvM_Ssa_TrustModelIntermediateCert_InvalidateNvBlock() (RTE_E_UNCONNECTED)
#  define Rte_Call_NvM_Ssa_TrustModelIntermediateCert_ReadBlock(arg1) (RTE_E_UNCONNECTED)
#  define Rte_Call_NvM_Ssa_TrustModelIntermediateCert_SetRamBlockStatus(arg1) (RTE_E_UNCONNECTED)
#  define Rte_Call_NvM_Ssa_TrustModelIntermediateCert_WriteBlock(arg1) (RTE_E_UNCONNECTED)
#  define Rte_Call_Nvm_Ssa_TrustModelBackendCert_EraseBlock() (RTE_E_UNCONNECTED)
#  define Rte_Call_Nvm_Ssa_TrustModelBackendCert_GetErrorStatus(arg1) (RTE_E_UNCONNECTED)
#  define Rte_Call_Nvm_Ssa_TrustModelBackendCert_InvalidateNvBlock() (RTE_E_UNCONNECTED)
#  define Rte_Call_Nvm_Ssa_TrustModelBackendCert_ReadBlock(arg1) (RTE_E_UNCONNECTED)
#  define Rte_Call_Nvm_Ssa_TrustModelBackendCert_SetRamBlockStatus(arg1) (RTE_E_UNCONNECTED)
#  define Rte_Call_Nvm_Ssa_TrustModelBackendCert_WriteBlock(arg1) (RTE_E_UNCONNECTED)
#  define Rte_Call_Nvm_Ssa_TrustModelRootCert_EraseBlock() (RTE_E_UNCONNECTED)
#  define Rte_Call_Nvm_Ssa_TrustModelRootCert_GetErrorStatus(arg1) (RTE_E_UNCONNECTED)
#  define Rte_Call_Nvm_Ssa_TrustModelRootCert_InvalidateNvBlock() (RTE_E_UNCONNECTED)
#  define Rte_Call_Nvm_Ssa_TrustModelRootCert_ReadBlock(arg1) (RTE_E_UNCONNECTED)
#  define Rte_Call_Nvm_Ssa_TrustModelRootCert_SetRamBlockStatus(arg1) (RTE_E_UNCONNECTED)
#  define Rte_Call_Nvm_Ssa_TrustModelRootCert_WriteBlock(arg1) (RTE_E_UNCONNECTED)

/**********************************************************************************************************************
 * Rte_Prm (Calibration component calibration parameters)
 *********************************************************************************************************************/

#  ifndef RTE_MICROSAR_PIM_EXPORT
#   define RTE_START_SEC_CONST_DEFAULT_RTE_CALPRM_GROUP_UNSPECIFIED
#   include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern CONST(uint8, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP) Rte_Ct_ProjectInformation_Pp_InputFileVersions_DiagnosticVariant;
extern CONST(uint8, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP) Rte_Ct_ProjectInformation_Pp_InputFileVersions_DiagnosticVersion;

#   define RTE_STOP_SEC_CONST_DEFAULT_RTE_CALPRM_GROUP_UNSPECIFIED
#   include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  endif

#  define Rte_Prm_Pp_InputFileVersions_DiagnosticVariant() (Rte_Ct_ProjectInformation_Pp_InputFileVersions_DiagnosticVariant)

#  define Rte_Prm_Pp_InputFileVersions_DiagnosticVersion() (Rte_Ct_ProjectInformation_Pp_InputFileVersions_DiagnosticVersion)

# endif /* !defined(RTE_CORE) */


# define Ct_MBBL_SsaAppl_General_START_SEC_CODE
# include "Ct_MBBL_SsaAppl_General_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

# ifndef RTE_CORE
#  define RTE_RUNNABLE_Ct_MBBL_SsaAppl_General_Init Ct_MBBL_SsaAppl_General_Init
#  define RTE_RUNNABLE_KeyMCertificateNotification_Ssa_TrustModelCert_Server_CertificateVerifyCallbackNotification KeyMCertificateNotification_Ssa_TrustModelCert_Server_CertificateVerifyCallbackNotification
#  define RTE_RUNNABLE_KeyMCertificateNotification_Ssa_TrustModelCert_Server_ServiceCertificateCallbackNotification KeyMCertificateNotification_Ssa_TrustModelCert_Server_ServiceCertificateCallbackNotification
#  define RTE_RUNNABLE_R_ICS_DiagInfo_ST3_Get R_ICS_DiagInfo_ST3_Get
#  define RTE_RUNNABLE_R_ICS_KeyStorage_ST3_StorePermanently R_ICS_KeyStorage_ST3_StorePermanently
# endif

FUNC(void, Ct_MBBL_SsaAppl_General_CODE) Ct_MBBL_SsaAppl_General_Init(void); /* PRQA S 3451, 0786, 3449 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449 */
FUNC(void, Ct_MBBL_SsaAppl_General_CODE) KeyMCertificateNotification_Ssa_TrustModelCert_Server_CertificateVerifyCallbackNotification(KeyM_CertificateStatusType Result); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, Ct_MBBL_SsaAppl_General_CODE) KeyMCertificateNotification_Ssa_TrustModelCert_Server_ServiceCertificateCallbackNotification(KeyM_ResultType Result, uint16 ResponseDataLength, KeyM_const_CryptoKeyDataType ResponseData); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, Ct_MBBL_SsaAppl_General_CODE) R_ICS_DiagInfo_ST3_Get(P2VAR(uint8, AUTOMATIC, RTE_CT_MBBL_SSAAPPL_GENERAL_APPL_VAR) diagVersion, P2VAR(uint8, AUTOMATIC, RTE_CT_MBBL_SSAAPPL_GENERAL_APPL_VAR) diagVariant); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, Ct_MBBL_SsaAppl_General_CODE) R_ICS_KeyStorage_ST3_StorePermanently(Ssa_KeyStorageUseCaseType keyStorageUseCase, Ssa_KeyStorageTaskType keyStorageTask); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */

# define Ct_MBBL_SsaAppl_General_STOP_SEC_CODE
# include "Ct_MBBL_SsaAppl_General_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Application errors
 *********************************************************************************************************************/

#  define RTE_E_NvMService_AC3_SRBS_E_NOT_OK (1U)

#  define RTE_E_Ssa_KeyStorage_E_NOT_OK (1U)

#  define RTE_E_Ssa_KeyStorage_E_PENDING (2U)

#  define RTE_E_Ssa_RightsM_DiagnosticInformation_E_NOT_OK (1U)
# endif /* !defined(RTE_CORE) */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* RTE_CT_MBBL_SSAAPPL_GENERAL_H */

/**********************************************************************************************************************
 MISRA 2012 violations and justifications
 *********************************************************************************************************************/

/* module specific MISRA deviations:
   MD_Rte_0624:  MISRA rule: Rule8.3
     Reason:     This MISRA violation is a consequence from the RTE requirements [SWS_Rte_01007] [SWS_Rte_01150].
                 The typedefs are never used in the same context.
     Risk:       No functional risk. Only a cast to uint8* is performed.
     Prevention: Not required.

   MD_Rte_0786:  MISRA rule: Rule5.5
     Reason:     Same macro and idintifier names in first 63 characters are required to meet AUTOSAR spec.
     Risk:       No functional risk.
     Prevention: Not required.

   MD_Rte_3449:  MISRA rule: Rule8.5
     Reason:     Schedulable entities are declared by the RTE and also by the BSW modules.
     Risk:       No functional risk.
     Prevention: Not required.

   MD_Rte_3451:  MISRA rule: Rule8.5
     Reason:     Schedulable entities are declared by the RTE and also by the BSW modules.
     Risk:       No functional risk.
     Prevention: Not required.

*/
