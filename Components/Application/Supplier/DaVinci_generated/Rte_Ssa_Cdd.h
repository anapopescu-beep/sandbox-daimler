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
 *             File:  Rte_Ssa_Cdd.h
 *           Config:  StartApplication.dpa
 *      ECU-Project:  StartApplication
 *
 *        Generator:  MICROSAR RTE Generator Version 4.32.0
 *                    RTE Core Version 4.32.0
 *          License:  CBD2200333
 *
 *      Description:  Application header file for SW-C <Ssa_Cdd>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef RTE_SSA_CDD_H
# define RTE_SSA_CDD_H

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

# include "Rte_Ssa_Cdd_Type.h"
# include "Rte_DataHandleType.h"


# ifndef RTE_CORE

/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (unmapped) for synchronous C/S communication
 *********************************************************************************************************************/
#  define RTE_START_SEC_SSA_PROCCTRL_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FUNC(Std_ReturnType, RTE_SSA_PROCCTRL_APPL_CODE) Ssa_ProcCtrl_DiagnosticService_Authentication_0x29_Authenticate(Dcm_OpStatusType OpStatus, Ssa_ConstDataPtr ReqData, uint32 ReqBufSize, uint32 ReqDataLen, Ssa_DataPtr ResData, uint32 ResBufSize, P2VAR(uint32, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) ResDataLen, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */

#  define RTE_STOP_SEC_SSA_PROCCTRL_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define Rte_Call_DiagnosticService_Authentication_0x29_Authenticate Ssa_ProcCtrl_DiagnosticService_Authentication_0x29_Authenticate

# endif /* !defined(RTE_CORE) */


# define Ssa_Cdd_START_SEC_CODE
# include "Ssa_Cdd_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

# ifndef RTE_CORE
#  define RTE_RUNNABLE_Ssa_Cdd_Csm_CancelJob Ssa_Cdd_Csm_CancelJob
#  define RTE_RUNNABLE_Ssa_Cdd_Csm_Hash Ssa_Cdd_Csm_Hash
#  define RTE_RUNNABLE_Ssa_Cdd_Csm_KeyElementCopy Ssa_Cdd_Csm_KeyElementCopy
#  define RTE_RUNNABLE_Ssa_Cdd_Csm_KeyElementGet Ssa_Cdd_Csm_KeyElementGet
#  define RTE_RUNNABLE_Ssa_Cdd_Csm_KeyElementSet Ssa_Cdd_Csm_KeyElementSet
#  define RTE_RUNNABLE_Ssa_Cdd_Csm_KeySetValid Ssa_Cdd_Csm_KeySetValid
#  define RTE_RUNNABLE_Ssa_Cdd_Csm_SignatureGenerate Ssa_Cdd_Csm_SignatureGenerate
#  define RTE_RUNNABLE_Ssa_Cdd_Csm_SignatureVerify Ssa_Cdd_Csm_SignatureVerify
#  define RTE_RUNNABLE_Ssa_Cdd_Init Ssa_Cdd_Init
#  define RTE_RUNNABLE_Ssa_Cdd_KeyM_CsrElementSet Ssa_Cdd_KeyM_CsrElementSet
#  define RTE_RUNNABLE_Ssa_Cdd_KeyM_GetCertificate Ssa_Cdd_KeyM_GetCertificate
#  define RTE_RUNNABLE_Ssa_Cdd_KeyM_ServiceCertificate Ssa_Cdd_KeyM_ServiceCertificate
#  define RTE_RUNNABLE_Ssa_Cdd_KeyM_SetCertificate Ssa_Cdd_KeyM_SetCertificate
#  define RTE_RUNNABLE_Ssa_Cdd_MainFunction Ssa_Cdd_MainFunction
#  define RTE_RUNNABLE_Ssa_Cdd_NvM_GetErrorStatus Ssa_Cdd_NvM_GetErrorStatus
#  define RTE_RUNNABLE_Ssa_Cdd_NvM_ReadBlock Ssa_Cdd_NvM_ReadBlock
#  define RTE_RUNNABLE_Ssa_Cdd_NvM_SetRamBlockStatus Ssa_Cdd_NvM_SetRamBlockStatus
#  define RTE_RUNNABLE_Ssa_Cdd_NvM_WriteBlock Ssa_Cdd_NvM_WriteBlock
# endif

FUNC(Std_ReturnType, Ssa_Cdd_CODE) Ssa_Cdd_Csm_CancelJob(uint32 jobId, Crypto_OperationModeType operationMode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, Ssa_Cdd_CODE) Ssa_Cdd_Csm_Hash(uint32 jobId, Crypto_OperationModeType operationMode, Ssa_ConstDataPtr dataBuffer, uint32 dataLength, Ssa_DataPtr resultBuffer, Ssa_LengthPtr resultLength); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, Ssa_Cdd_CODE) Ssa_Cdd_Csm_KeyElementCopy(uint32 keyId, uint32 keyElementId, uint32 targetKeyId, uint32 targetKeyElementId); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, Ssa_Cdd_CODE) Ssa_Cdd_Csm_KeyElementGet(uint32 keyId, uint32 keyElementId, Ssa_DataPtr keyPtr, Ssa_LengthPtr keyLengthPtr); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, Ssa_Cdd_CODE) Ssa_Cdd_Csm_KeyElementSet(uint32 keyId, uint32 keyElementId, Ssa_ConstDataPtr keyPtr, uint32 keyLength); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, Ssa_Cdd_CODE) Ssa_Cdd_Csm_KeySetValid(uint32 keyId); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, Ssa_Cdd_CODE) Ssa_Cdd_Csm_SignatureGenerate(uint32 jobId, Crypto_OperationModeType operationMode, Ssa_ConstDataPtr dataBuffer, uint32 dataLength, Ssa_DataPtr resultBuffer, Ssa_LengthPtr resultLength); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, Ssa_Cdd_CODE) Ssa_Cdd_Csm_SignatureVerify(uint32 jobId, Crypto_OperationModeType operationMode, Ssa_ConstDataPtr dataBuffer, uint32 dataLength, Ssa_ConstDataPtr compareBuffer, uint32 compareLength, Ssa_VerifyResultPtr resultBuffer); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, Ssa_Cdd_CODE) Ssa_Cdd_Init(void); /* PRQA S 3451, 0786, 3449 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449 */
FUNC(Std_ReturnType, Ssa_Cdd_CODE) Ssa_Cdd_KeyM_CsrElementSet(KeyM_CertificateIdType CertId, KeyM_CertElementIdType CertElementId, KeyM_CsrEncodingType EncodingType, Ssa_ConstDataPtr ElementData, uint32 ElementDataLength); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, Ssa_Cdd_CODE) Ssa_Cdd_KeyM_GetCertificate(KeyM_CertificateIdType CertId, Ssa_DataPtr CertData, Ssa_LengthPtr CertDataLength); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, Ssa_Cdd_CODE) Ssa_Cdd_KeyM_ServiceCertificate(KeyM_ServiceCertificateType Service, Ssa_ConstDataPtr CertNamePtr, uint32 CertNameLength, Ssa_ConstDataPtr RequestData, uint32 RequestDataLength, Ssa_DataPtr ResponseData, uint32 ResponseDataLength); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, Ssa_Cdd_CODE) Ssa_Cdd_KeyM_SetCertificate(KeyM_CertificateIdType CertId, Ssa_DataPtr CertData, uint32 CertDataLength); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, Ssa_Cdd_CODE) Ssa_Cdd_MainFunction(void); /* PRQA S 3451, 0786, 3449 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449 */
FUNC(Std_ReturnType, Ssa_Cdd_CODE) Ssa_Cdd_NvM_GetErrorStatus(P2VAR(NvM_RequestResultType, AUTOMATIC, RTE_SSA_CDD_APPL_VAR) ErrorStatus); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, Ssa_Cdd_CODE) Ssa_Cdd_NvM_ReadBlock(dtRef_VOID DstPtr); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, Ssa_Cdd_CODE) Ssa_Cdd_NvM_SetRamBlockStatus(boolean RamBlockStatus); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, Ssa_Cdd_CODE) Ssa_Cdd_NvM_WriteBlock(dtRef_const_VOID SrcPtr); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */

# define Ssa_Cdd_STOP_SEC_CODE
# include "Ssa_Cdd_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Application errors
 *********************************************************************************************************************/

#  define RTE_E_DiagnosticService_Authentication_0x29_DCM_E_FORCE_RCRRP (12U)

#  define RTE_E_DiagnosticService_Authentication_0x29_DCM_E_PENDING (10U)

#  define RTE_E_DiagnosticService_Authentication_0x29_E_NOT_OK (1U)

#  define RTE_E_NvMService_AC2_SRBS_E_NOT_OK (1U)

#  define RTE_E_SsaCdd_CryptoInterface_E_NOT_OK (1U)

#  define RTE_E_SsaCdd_Csm_KeyInterface_E_BUSY (2U)

#  define RTE_E_SsaCdd_Csm_KeyInterface_E_NOT_OK (1U)

#  define RTE_E_SsaCdd_KeyM_CertInterface_E_NOT_OK (1U)

#  define RTE_E_SsaCdd_KeyM_CertInterface_KEYM_E_BUSY (2U)

#  define RTE_E_SsaCdd_KeyM_CertInterface_KEYM_E_CERT_INVALID_CHAIN_OF_TRUST (9U)

#  define RTE_E_SsaCdd_KeyM_CertInterface_KEYM_E_KEY_CERT_EMPTY (8U)

#  define RTE_E_SsaCdd_KeyM_CertInterface_KEYM_E_KEY_CERT_READ_FAIL (7U)

#  define RTE_E_SsaCdd_KeyM_CertInterface_KEYM_E_KEY_CERT_SIZE_MISMATCH (4U)

#  define RTE_E_SsaCdd_KeyM_CertInterface_KEYM_E_PARAMETER_MISMATCH (5U)
# endif /* !defined(RTE_CORE) */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* RTE_SSA_CDD_H */

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
