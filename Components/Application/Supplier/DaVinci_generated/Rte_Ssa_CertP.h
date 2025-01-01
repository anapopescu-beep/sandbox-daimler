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
 *             File:  Rte_Ssa_CertP.h
 *           Config:  StartApplication.dpa
 *      ECU-Project:  StartApplication
 *
 *        Generator:  MICROSAR RTE Generator Version 4.32.0
 *                    RTE Core Version 4.32.0
 *          License:  CBD2200333
 *
 *      Description:  Application header file for SW-C <Ssa_CertP>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef RTE_SSA_CERTP_H
# define RTE_SSA_CERTP_H

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

# include "Rte_Ssa_CertP_Type.h"
# include "Rte_DataHandleType.h"


# ifndef RTE_CORE

/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (unmapped) for synchronous C/S communication
 *********************************************************************************************************************/
#  define RTE_START_SEC_CSM_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_CSM_APPL_CODE) Csm_KeyElementSet(uint32 parg0, uint32 keyElementId, P2CONST(uint8, AUTOMATIC, RTE_CSM_APPL_DATA) keyPtr, uint32 keyLength); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_CSM_APPL_CODE) Csm_KeyElementSet(uint32 parg0, uint32 keyElementId, P2CONST(Csm_KeyDataType_Ssa_SignatureRamKey, AUTOMATIC, RTE_CSM_APPL_DATA) keyPtr, uint32 keyLength); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
FUNC(Std_ReturnType, RTE_CSM_APPL_CODE) Csm_KeySetValid(uint32 parg0); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */

#  define RTE_STOP_SEC_CSM_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define RTE_START_SEC_SSA_CDD_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FUNC(Std_ReturnType, RTE_SSA_CDD_APPL_CODE) Ssa_Cdd_Csm_SignatureVerify(uint32 jobId, Crypto_OperationModeType operationMode, Ssa_ConstDataPtr dataBuffer, uint32 dataLength, Ssa_ConstDataPtr compareBuffer, uint32 compareLength, Ssa_VerifyResultPtr resultBuffer); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */

#  define RTE_STOP_SEC_SSA_CDD_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define RTE_START_SEC_SSA_CODING_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_SSA_CODING_APPL_CODE) Ssa_Coding_VIN_Get(P2VAR(uint8, AUTOMATIC, RTE_SSA_CODING_APPL_VAR) vin); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_SSA_CODING_APPL_CODE) Ssa_Coding_VIN_Get(P2VAR(Coding_VINDataType, AUTOMATIC, RTE_SSA_CODING_APPL_VAR) vin); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif

#  define RTE_STOP_SEC_SSA_CODING_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define RTE_START_SEC_SSA_SECLOG_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FUNC(Std_ReturnType, RTE_SSA_SECLOG_APPL_CODE) Ssa_SecLog_LogEvent_FailedCertificateVerification(CertP_PkiRoleType pkiRole, CertP_VerificationResultType validationResult); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_SSA_SECLOG_APPL_CODE) Ssa_SecLog_LogEvent_SuccessfulCertificateVerification(P2CONST(uint8, AUTOMATIC, RTE_SSA_SECLOG_APPL_DATA) certId, CertP_PkiRoleType pkiRole); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_SSA_SECLOG_APPL_CODE) Ssa_SecLog_LogEvent_SuccessfulCertificateVerification(P2CONST(RightsM_SerialNumberType, AUTOMATIC, RTE_SSA_SECLOG_APPL_DATA) certId, CertP_PkiRoleType pkiRole); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif

#  define RTE_STOP_SEC_SSA_SECLOG_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define RTE_START_SEC_SSA_TIMEM_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FUNC(Std_ReturnType, RTE_SSA_TIMEM_APPL_CODE) Ssa_TimeM_RealTime_Compare(P2CONST(TimeM_DateTimeType, AUTOMATIC, RTE_SSA_TIMEM_APPL_DATA) t1, TimeM_CompareOperatorType compareOp, P2CONST(TimeM_DateTimeType, AUTOMATIC, RTE_SSA_TIMEM_APPL_DATA) t2, P2VAR(boolean, AUTOMATIC, RTE_SSA_TIMEM_APPL_VAR) result); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_SSA_TIMEM_APPL_CODE) Ssa_TimeM_RealTime_Get(P2VAR(TimeM_DateTimeType, AUTOMATIC, RTE_SSA_TIMEM_APPL_VAR) realTime); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */

#  define RTE_STOP_SEC_SSA_TIMEM_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define Rte_Call_Coding_VIN_Get Ssa_Coding_VIN_Get
#  define Rte_Call_Key_SignatureRamKey_KeyElementSet(arg1, arg2, arg3) (Csm_KeyElementSet((uint32)47, arg1, arg2, arg3))
#  define Rte_Call_Key_SignatureRamKey_KeySetValid() (Csm_KeySetValid((uint32)47))
#  define Rte_Call_SecLog_FailedCertVerificationEvent_FailedCertificateVerification Ssa_SecLog_LogEvent_FailedCertificateVerification
#  define Rte_Call_SecLog_SuccessfulCertVerificationEvent_SuccessfulCertificateVerification Ssa_SecLog_LogEvent_SuccessfulCertificateVerification
#  define Rte_Call_SsaCdd_Csm_SignatureVerify Ssa_Cdd_Csm_SignatureVerify
#  define Rte_Call_TimeM_RealTime_Compare Ssa_TimeM_RealTime_Compare
#  define Rte_Call_TimeM_RealTime_Get Ssa_TimeM_RealTime_Get

# endif /* !defined(RTE_CORE) */


# define Ssa_CertP_START_SEC_CODE
# include "Ssa_CertP_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

# ifndef RTE_CORE
#  define RTE_RUNNABLE_Ssa_CertP_AttributeCertificate_Parse Ssa_CertP_AttributeCertificate_Parse
#  define RTE_RUNNABLE_Ssa_CertP_Certificate_Compare Ssa_CertP_Certificate_Compare
#  define RTE_RUNNABLE_Ssa_CertP_Certificate_Parse Ssa_CertP_Certificate_Parse
#  define RTE_RUNNABLE_Ssa_CertP_Certificate_Verify Ssa_CertP_Certificate_Verify
#  define RTE_RUNNABLE_Ssa_CertP_Certificate_Verify_Extended Ssa_CertP_Certificate_Verify_Extended
#  define RTE_RUNNABLE_Ssa_CertP_CsmCallbackNotification_SignatureVerify Ssa_CertP_CsmCallbackNotification_SignatureVerify
#  define RTE_RUNNABLE_Ssa_CertP_Init Ssa_CertP_Init
#  define RTE_RUNNABLE_Ssa_CertP_ParseTime Ssa_CertP_ParseTime
# endif

FUNC(Std_ReturnType, Ssa_CertP_CODE) Ssa_CertP_AttributeCertificate_Parse(P2CONST(uint8, AUTOMATIC, RTE_SSA_CERTP_APPL_DATA) rawCertData, uint16 rawCertLength, P2VAR(CertP_ParsedCertStructureType, AUTOMATIC, RTE_SSA_CERTP_APPL_VAR) parsedCert); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, Ssa_CertP_CODE) Ssa_CertP_Certificate_Compare(P2CONST(uint8, AUTOMATIC, RTE_SSA_CERTP_APPL_DATA) rawCertData1, P2CONST(CertP_ParsedCertStructureType, AUTOMATIC, RTE_SSA_CERTP_APPL_DATA) parsedCert1, CertP_PkiRoleType pkiRole1, P2CONST(uint8, AUTOMATIC, RTE_SSA_CERTP_APPL_DATA) rawCertData2, P2CONST(CertP_ParsedCertStructureType, AUTOMATIC, RTE_SSA_CERTP_APPL_DATA) parsedCert2, CertP_PkiRoleType pkiRole2, P2VAR(boolean, AUTOMATIC, RTE_SSA_CERTP_APPL_VAR) isEqual); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, Ssa_CertP_CODE) Ssa_CertP_Certificate_Parse(P2CONST(uint8, AUTOMATIC, RTE_SSA_CERTP_APPL_DATA) rawCertData, uint16 rawCertLength, P2VAR(CertP_ParsedCertStructureType, AUTOMATIC, RTE_SSA_CERTP_APPL_VAR) parsedCert); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, Ssa_CertP_CODE) Ssa_CertP_Certificate_Verify(P2CONST(uint8, AUTOMATIC, RTE_SSA_CERTP_APPL_DATA) rawCertData, P2VAR(CertP_ParsedCertStructureType, AUTOMATIC, RTE_SSA_CERTP_APPL_VAR) parsedCert, P2CONST(uint8, AUTOMATIC, RTE_SSA_CERTP_APPL_DATA) rawCertIssuer, P2CONST(CertP_ParsedCertStructureType, AUTOMATIC, RTE_SSA_CERTP_APPL_DATA) parsedCertIssuer, CertP_PkiRoleType expectedPkiRole); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, Ssa_CertP_CODE) Ssa_CertP_Certificate_Verify_Extended(P2CONST(uint8, AUTOMATIC, RTE_SSA_CERTP_APPL_DATA) rawCertData, P2VAR(CertP_ParsedCertStructureType, AUTOMATIC, RTE_SSA_CERTP_APPL_VAR) parsedCert, P2CONST(uint8, AUTOMATIC, RTE_SSA_CERTP_APPL_DATA) rawCertIssuer, P2CONST(CertP_ParsedCertStructureType, AUTOMATIC, RTE_SSA_CERTP_APPL_DATA) parsedCertIssuer, CertP_PkiRoleType expectedPkiRole, P2CONST(RightsM_AuthNonceType, AUTOMATIC, RTE_SSA_CERTP_APPL_DATA) expectedNonce); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, Ssa_CertP_CODE) Ssa_CertP_CsmCallbackNotification_SignatureVerify(Csm_ResultType result); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, Ssa_CertP_CODE) Ssa_CertP_Init(void); /* PRQA S 3451, 0786, 3449 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449 */
FUNC(Std_ReturnType, Ssa_CertP_CODE) Ssa_CertP_ParseTime(P2CONST(uint8, AUTOMATIC, RTE_SSA_CERTP_APPL_DATA) data, uint16 dataLength, P2VAR(TimeM_DateTimeType, AUTOMATIC, RTE_SSA_CERTP_APPL_VAR) dateTime); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */

# define Ssa_CertP_STOP_SEC_CODE
# include "Ssa_CertP_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Application errors
 *********************************************************************************************************************/

#  define RTE_E_CertP_Functions_E_NOT_OK (1U)

#  define RTE_E_CertP_Functions_E_PENDING (10U)

#  define RTE_E_Coding_VIN_E_NOT_OK (1U)

#  define RTE_E_CsmKeyManagement_Ssa_SignatureRamKey_CSM_E_BUSY (2U)

#  define RTE_E_CsmKeyManagement_Ssa_SignatureRamKey_CSM_E_KEY_NOT_AVAILABLE (8U)

#  define RTE_E_CsmKeyManagement_Ssa_SignatureRamKey_CSM_E_KEY_SIZE_MISMATCH (10U)

#  define RTE_E_CsmKeyManagement_Ssa_SignatureRamKey_CSM_E_KEY_WRITE_FAIL (7U)

#  define RTE_E_CsmKeyManagement_Ssa_SignatureRamKey_CSM_E_SMALL_BUFFER (3U)

#  define RTE_E_CsmKeyManagement_Ssa_SignatureRamKey_E_NOT_OK (1U)

#  define RTE_E_SecLog_FailedCertVerificationEvent_E_NOT_OK (1U)

#  define RTE_E_SecLog_SuccessfulCertVerificationEvent_E_NOT_OK (1U)

#  define RTE_E_SsaCdd_CryptoInterface_E_NOT_OK (1U)

#  define RTE_E_TimeM_RealTime_E_NOT_OK (1U)
# endif /* !defined(RTE_CORE) */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* RTE_SSA_CERTP_H */

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
