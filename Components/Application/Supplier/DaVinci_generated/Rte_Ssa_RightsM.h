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
 *             File:  Rte_Ssa_RightsM.h
 *           Config:  StartApplication.dpa
 *      ECU-Project:  StartApplication
 *
 *        Generator:  MICROSAR RTE Generator Version 4.32.0
 *                    RTE Core Version 4.32.0
 *          License:  CBD2200333
 *
 *      Description:  Application header file for SW-C <Ssa_RightsM>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef RTE_SSA_RIGHTSM_H
# define RTE_SSA_RIGHTSM_H

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

# include "Rte_Ssa_RightsM_Type.h"
# include "Rte_DataHandleType.h"

# include "Rte_Hook.h"


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

#  define Rte_InitValue_RightsM_SecurityLevelChange_currentLevel (0U)
# endif


# define RTE_START_SEC_CODE
# include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Ssa_RightsM_RightsM_ReceiveAuthenticationBroadcast_authentication(P2VAR(uint8, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Ssa_RightsM_RightsM_ReceiveAuthenticationBroadcast_authentication(P2VAR(RightsM_AuthenticationBroadcastType, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Ssa_RightsM_Ssa_BusOdometer_DI_Odo_Pr5_ST3(P2VAR(Ssa_OdometerRecordType, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Dcm_DiagnosticSessionControlType, RTE_CODE) Rte_Mode_Ssa_RightsM_DcmDiagnosticSessionControl_DcmDiagnosticSessionControl(P2VAR(Dcm_DiagnosticSessionControlType, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_VAR) previousMode, P2VAR(Dcm_DiagnosticSessionControlType, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_VAR) nextMode);


# define RTE_STOP_SEC_CODE
# include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# ifndef RTE_CORE

/**********************************************************************************************************************
 * Rte_Read_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Read_RightsM_ReceiveAuthenticationBroadcast_authentication Rte_Read_Ssa_RightsM_RightsM_ReceiveAuthenticationBroadcast_authentication
#  define Rte_Read_Ssa_BusOdometer_DI_Odo_Pr5_ST3 Rte_Read_Ssa_RightsM_Ssa_BusOdometer_DI_Odo_Pr5_ST3


/**********************************************************************************************************************
 * Rte_Write_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Write_RightsM_SecurityLevelChange_currentLevel Rte_Write_Ssa_RightsM_RightsM_SecurityLevelChange_currentLevel
#  define Rte_Write_Ssa_RightsM_RightsM_SecurityLevelChange_currentLevel(data) (RTE_E_OK)


/**********************************************************************************************************************
 * Rte_Mode_<p>_<m>
 *********************************************************************************************************************/
#  define Rte_Mode_DcmDiagnosticSessionControl_DcmDiagnosticSessionControl Rte_Mode_Ssa_RightsM_DcmDiagnosticSessionControl_DcmDiagnosticSessionControl


/**********************************************************************************************************************
 * Rte_Switch_<p>_<m>
 *********************************************************************************************************************/
#  define Rte_Switch_Authentication_Mode Rte_Switch_Ssa_RightsM_Authentication_Mode
#  define Rte_Switch_Ssa_RightsM_Authentication_Mode(mode) (RTE_E_OK)


/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (unmapped) for synchronous C/S communication
 *********************************************************************************************************************/
#  define RTE_START_SEC_CSM_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_CSM_APPL_CODE) Csm_RandomGenerate(uint32 parg0, P2VAR(uint8, AUTOMATIC, RTE_CSM_APPL_VAR) resultBuffer, P2VAR(uint32, AUTOMATIC, RTE_CSM_APPL_VAR) resultLength); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_CSM_APPL_CODE) Csm_RandomGenerate(uint32 parg0, P2VAR(Csm_RandomGenerateResultType_Random_TRNG, AUTOMATIC, RTE_CSM_APPL_VAR) resultBuffer, P2VAR(uint32, AUTOMATIC, RTE_CSM_APPL_VAR) resultLength); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_CSM_APPL_CODE) Csm_KeyElementSet(uint32 parg0, uint32 keyElementId, P2CONST(uint8, AUTOMATIC, RTE_CSM_APPL_DATA) keyPtr, uint32 keyLength); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_CSM_APPL_CODE) Csm_KeyElementSet(uint32 parg0, uint32 keyElementId, P2CONST(Csm_KeyDataType_Ssa_SignatureRamKey, AUTOMATIC, RTE_CSM_APPL_DATA) keyPtr, uint32 keyLength); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
FUNC(Std_ReturnType, RTE_CSM_APPL_CODE) Csm_KeySetValid(uint32 parg0); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */

#  define RTE_STOP_SEC_CSM_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define RTE_START_SEC_CT_MBBL_SSAAPPL_GENERAL_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FUNC(Std_ReturnType, RTE_CT_MBBL_SSAAPPL_GENERAL_APPL_CODE) R_ICS_DiagInfo_ST3_Get(P2VAR(uint8, AUTOMATIC, RTE_CT_MBBL_SSAAPPL_GENERAL_APPL_VAR) diagVersion, P2VAR(uint8, AUTOMATIC, RTE_CT_MBBL_SSAAPPL_GENERAL_APPL_VAR) diagVariant); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */

#  define RTE_STOP_SEC_CT_MBBL_SSAAPPL_GENERAL_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define RTE_START_SEC_DEMSATELLITE_0_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FUNC(Std_ReturnType, RTE_DEMSATELLITE_0_APPL_CODE) Dem_SetEventStatus(Dem_EventIdType parg0, Dem_EventStatusType EventStatus); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */

#  define RTE_STOP_SEC_DEMSATELLITE_0_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define RTE_START_SEC_NVM_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FUNC(Std_ReturnType, RTE_NVM_APPL_CODE) NvM_GetErrorStatus(NvM_BlockIdType parg0, P2VAR(NvM_RequestResultType, AUTOMATIC, RTE_NVM_APPL_VAR) ErrorStatus); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_NVM_APPL_CODE) NvM_WriteBlock(NvM_BlockIdType parg0, dtRef_const_VOID SrcPtr); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_NVM_APPL_CODE) NvM_SetRamBlockStatus(NvM_BlockIdType parg0, boolean RamBlockStatus); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */

#  define RTE_STOP_SEC_NVM_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define RTE_START_SEC_SSA_CDD_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FUNC(Std_ReturnType, RTE_SSA_CDD_APPL_CODE) Ssa_Cdd_Csm_Hash(uint32 jobId, Crypto_OperationModeType operationMode, Ssa_ConstDataPtr dataBuffer, uint32 dataLength, Ssa_DataPtr resultBuffer, Ssa_LengthPtr resultLength); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_SSA_CDD_APPL_CODE) Ssa_Cdd_Csm_SignatureVerify(uint32 jobId, Crypto_OperationModeType operationMode, Ssa_ConstDataPtr dataBuffer, uint32 dataLength, Ssa_ConstDataPtr compareBuffer, uint32 compareLength, Ssa_VerifyResultPtr resultBuffer); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */

#  define RTE_STOP_SEC_SSA_CDD_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define RTE_START_SEC_SSA_CERTP_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_SSA_CERTP_APPL_CODE) Ssa_CertP_AttributeCertificate_Parse(P2CONST(uint8, AUTOMATIC, RTE_SSA_CERTP_APPL_DATA) rawCertData, uint16 rawCertLength, P2VAR(CertP_ParsedCertStructureType, AUTOMATIC, RTE_SSA_CERTP_APPL_VAR) parsedCert); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_SSA_CERTP_APPL_CODE) Ssa_CertP_AttributeCertificate_Parse(P2CONST(CertP_RawCertBufferType, AUTOMATIC, RTE_SSA_CERTP_APPL_DATA) rawCertData, uint16 rawCertLength, P2VAR(CertP_ParsedCertStructureType, AUTOMATIC, RTE_SSA_CERTP_APPL_VAR) parsedCert); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_SSA_CERTP_APPL_CODE) Ssa_CertP_Certificate_Parse(P2CONST(uint8, AUTOMATIC, RTE_SSA_CERTP_APPL_DATA) rawCertData, uint16 rawCertLength, P2VAR(CertP_ParsedCertStructureType, AUTOMATIC, RTE_SSA_CERTP_APPL_VAR) parsedCert); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_SSA_CERTP_APPL_CODE) Ssa_CertP_Certificate_Parse(P2CONST(CertP_RawCertBufferType, AUTOMATIC, RTE_SSA_CERTP_APPL_DATA) rawCertData, uint16 rawCertLength, P2VAR(CertP_ParsedCertStructureType, AUTOMATIC, RTE_SSA_CERTP_APPL_VAR) parsedCert); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif

#  define RTE_STOP_SEC_SSA_CERTP_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define RTE_START_SEC_SSA_KEYM_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_SSA_KEYM_APPL_CODE) Ssa_KeyM_Certificate_GetBackendSerialNumber(P2VAR(uint8, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) serialNumber, P2VAR(uint16, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) serialNumberLength); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_SSA_KEYM_APPL_CODE) Ssa_KeyM_Certificate_GetBackendSerialNumber(P2VAR(Ssa_Data2ByteType, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) serialNumber, P2VAR(uint16, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) serialNumberLength); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_SSA_KEYM_APPL_CODE) Ssa_KeyM_Certificate_GetBackendSubject(P2VAR(uint8, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) backendSubject, P2VAR(uint16, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) dataLength); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_SSA_KEYM_APPL_CODE) Ssa_KeyM_Certificate_GetBackendSubject(P2VAR(Ssa_Data30ByteType, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) backendSubject, P2VAR(uint16, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) dataLength); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_SSA_KEYM_APPL_CODE) Ssa_KeyM_Certificate_VerifyCertWithBackendCert(P2CONST(uint8, AUTOMATIC, RTE_SSA_KEYM_APPL_DATA) cert, P2VAR(CertP_ParsedCertStructureType, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) parsedCertStructure, uint16 certLength, CertP_PkiRoleType expectedPkiRole, P2CONST(RightsM_AuthNonceType, AUTOMATIC, RTE_SSA_KEYM_APPL_DATA) expectedNonce); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_SSA_KEYM_APPL_CODE) Ssa_KeyM_Certificate_VerifyCertWithBackendCert(P2CONST(CertP_RawCertBufferType, AUTOMATIC, RTE_SSA_KEYM_APPL_DATA) cert, P2VAR(CertP_ParsedCertStructureType, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) parsedCertStructure, uint16 certLength, CertP_PkiRoleType expectedPkiRole, P2CONST(RightsM_AuthNonceType, AUTOMATIC, RTE_SSA_KEYM_APPL_DATA) expectedNonce); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif

#  define RTE_STOP_SEC_SSA_KEYM_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define RTE_START_SEC_SSA_SECLOG_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FUNC(Std_ReturnType, RTE_SSA_SECLOG_APPL_CODE) Ssa_SecLog_LogEvent_AuthorizationBySecurityAccess(uint8 diagChanAuthStatus, uint8 securityLevel, uint8 securityAccessResult); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_SSA_SECLOG_APPL_CODE) Ssa_SecLog_LogEvent_EcuIndividualAclReplacement(P2CONST(uint8, AUTOMATIC, RTE_SSA_SECLOG_APPL_DATA) newAclVersion, uint8 compatibility); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_SSA_SECLOG_APPL_CODE) Ssa_SecLog_LogEvent_EcuIndividualAclReplacement(P2CONST(SecLog_AclVersionType, AUTOMATIC, RTE_SSA_SECLOG_APPL_DATA) newAclVersion, uint8 compatibility); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
FUNC(Std_ReturnType, RTE_SSA_SECLOG_APPL_CODE) Ssa_SecLog_LogEvent_RightsManagement(uint8 diagChanAuthStatus, uint8 serviceId, uint8 subFunction, uint16 dataIdOrRoutineId); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_SSA_SECLOG_APPL_CODE) Ssa_SecLog_LogEvent_SuccessfulAuthAndEnhanceRights(uint8 diagChanAuthStatus, CertP_PkiRoleType pkiRole, P2CONST(uint8, AUTOMATIC, RTE_SSA_SECLOG_APPL_DATA) authenticationContent); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_SSA_SECLOG_APPL_CODE) Ssa_SecLog_LogEvent_SuccessfulAuthAndEnhanceRights(uint8 diagChanAuthStatus, CertP_PkiRoleType pkiRole, P2CONST(SecLog_AuthenticationContentType, AUTOMATIC, RTE_SSA_SECLOG_APPL_DATA) authenticationContent); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
FUNC(Std_ReturnType, RTE_SSA_SECLOG_APPL_CODE) Ssa_SecLog_LogEvent_SuccessfulDiagServiceExecution(uint8 parg0, uint8 additionalInfo); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */

#  define RTE_STOP_SEC_SSA_SECLOG_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define RTE_START_SEC_SSA_TIMEM_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FUNC(Std_ReturnType, RTE_SSA_TIMEM_APPL_CODE) Ssa_TimeM_RealTime_Compare(P2CONST(TimeM_DateTimeType, AUTOMATIC, RTE_SSA_TIMEM_APPL_DATA) t1, TimeM_CompareOperatorType compareOp, P2CONST(TimeM_DateTimeType, AUTOMATIC, RTE_SSA_TIMEM_APPL_DATA) t2, P2VAR(boolean, AUTOMATIC, RTE_SSA_TIMEM_APPL_VAR) result); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_SSA_TIMEM_APPL_CODE) Ssa_TimeM_RealTime_Get(P2VAR(TimeM_DateTimeType, AUTOMATIC, RTE_SSA_TIMEM_APPL_VAR) realTime); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_SSA_TIMEM_APPL_CODE) Ssa_TimeM_RealTime_Set(P2CONST(TimeM_DateTimeType, AUTOMATIC, RTE_SSA_TIMEM_APPL_DATA) realTime, TimeM_RealTimeChangeReasonType changeReason); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_SSA_TIMEM_APPL_CODE) Ssa_TimeM_TickCount_Get(P2VAR(uint64, AUTOMATIC, RTE_SSA_TIMEM_APPL_VAR) tickCount); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */

#  define RTE_STOP_SEC_SSA_TIMEM_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define Rte_Call_CertP_Functions_AttributeCertificate_Parse Ssa_CertP_AttributeCertificate_Parse
#  define Rte_Call_CertP_Functions_Certificate_Parse Ssa_CertP_Certificate_Parse
#  define Rte_Call_CsmRandomGenerate_RandomGenerate(arg1, arg2) (Csm_RandomGenerate((uint32)33, arg1, arg2))
#  define Rte_Call_DTC_0x9A6857_SetEventStatus(arg1) (Dem_SetEventStatus((Dem_EventIdType)2, arg1))
#  define Rte_Call_KeyM_Certificate_GetBackendSerialNumber Ssa_KeyM_Certificate_GetBackendSerialNumber
#  define Rte_Call_KeyM_Certificate_GetBackendSubject Ssa_KeyM_Certificate_GetBackendSubject
#  define Rte_Call_KeyM_Certificate_VerifyCertWithBackendCert Ssa_KeyM_Certificate_VerifyCertWithBackendCert
#  define Rte_Call_Key_SignatureRamKey_KeyElementSet(arg1, arg2, arg3) (Csm_KeyElementSet((uint32)47, arg1, arg2, arg3))
#  define Rte_Call_Key_SignatureRamKey_KeySetValid() (Csm_KeySetValid((uint32)47))
#  define Rte_Call_NvMService_RightsM_AclVersion_GetErrorStatus(arg1) (NvM_GetErrorStatus((NvM_BlockIdType)5, arg1))
#  define Rte_Call_NvMService_RightsM_AclVersion_WriteBlock(arg1) (NvM_WriteBlock((NvM_BlockIdType)5, arg1))
#  define Rte_Call_NvMService_RightsM_Nonce_GetErrorStatus(arg1) (NvM_GetErrorStatus((NvM_BlockIdType)6, arg1))
#  define Rte_Call_NvMService_RightsM_Nonce_SetRamBlockStatus(arg1) (NvM_SetRamBlockStatus((NvM_BlockIdType)6, arg1))
#  define Rte_Call_NvMService_RightsM_Nonce_WriteBlock(arg1) (NvM_WriteBlock((NvM_BlockIdType)6, arg1))
#  define Rte_Call_NvMService_RightsM_PostProductionStatus_GetErrorStatus(arg1) (NvM_GetErrorStatus((NvM_BlockIdType)7, arg1))
#  define Rte_Call_NvMService_RightsM_PostProductionStatus_WriteBlock(arg1) (NvM_WriteBlock((NvM_BlockIdType)7, arg1))
#  define Rte_Call_SecLog_AuthorizationBySecurityAccess_AuthorizationBySecurityAccess Ssa_SecLog_LogEvent_AuthorizationBySecurityAccess
#  define Rte_Call_SecLog_EcuIndividualAclReplacementEvent_EcuIndividualAclReplacement Ssa_SecLog_LogEvent_EcuIndividualAclReplacement
#  define Rte_Call_SecLog_RightsManagementEvent_RightsManagement Ssa_SecLog_LogEvent_RightsManagement
#  define Rte_Call_SecLog_SuccessfulAuthAndEnhanceRights_SuccessfulAuthAndEnhanceRights Ssa_SecLog_LogEvent_SuccessfulAuthAndEnhanceRights
#  define Rte_Call_SecLog_SuccessfulDiagServiceExecutionEvent_ActivateDebugIf_SuccessfulDiagServiceExecution(arg1) (Ssa_SecLog_LogEvent_SuccessfulDiagServiceExecution((uint8)1, arg1))
#  define Rte_Call_SecLog_SuccessfulDiagServiceExecutionEvent_ClearSarMemory_SuccessfulDiagServiceExecution(arg1) (Ssa_SecLog_LogEvent_SuccessfulDiagServiceExecution((uint8)3, arg1))
#  define Rte_Call_SecLog_SuccessfulDiagServiceExecutionEvent_EnableSarMemOverwrite_SuccessfulDiagServiceExecution(arg1) (Ssa_SecLog_LogEvent_SuccessfulDiagServiceExecution((uint8)4, arg1))
#  define Rte_Call_SecLog_SuccessfulDiagServiceExecutionEvent_EraseMemory_SuccessfulDiagServiceExecution(arg1) (Ssa_SecLog_LogEvent_SuccessfulDiagServiceExecution((uint8)2, arg1))
#  define Rte_Call_SsaCdd_Csm_Hash Ssa_Cdd_Csm_Hash
#  define Rte_Call_SsaCdd_Csm_SignatureVerify Ssa_Cdd_Csm_SignatureVerify
#  define Rte_Call_Ssa_RightsM_DiagnosticInformation_Get R_ICS_DiagInfo_ST3_Get
#  define Rte_Call_TimeM_RealTime_Compare Ssa_TimeM_RealTime_Compare
#  define Rte_Call_TimeM_RealTime_Get Ssa_TimeM_RealTime_Get
#  define Rte_Call_TimeM_RealTime_Set Ssa_TimeM_RealTime_Set
#  define Rte_Call_TimeM_TickCount_Get Ssa_TimeM_TickCount_Get

/**********************************************************************************************************************
 * Exclusive Areas
 *********************************************************************************************************************/

#  define Rte_Enter_RightsM_ExclusiveArea() SuspendAllInterrupts() /* RteAnalyzer(ExclusiveArea, ALL_INTERRUPT_BLOCKING) */

#  define Rte_Exit_RightsM_ExclusiveArea() ResumeAllInterrupts()  /* RteAnalyzer(ExclusiveArea, ALL_INTERRUPT_BLOCKING) */


/**********************************************************************************************************************
 * Rte_CData (SW-C local calibration parameters)
 *********************************************************************************************************************/

#  ifndef RTE_MICROSAR_PIM_EXPORT

#   define RTE_START_SEC_CONST_DEFAULT_RTE_CDATA_GROUP_UNSPECIFIED
#   include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern CONST(Ssa_PostProductionStatusType, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_Ssa_RightsM_NvM_RightsM_PostProductionStatus_DefaultValue;
extern CONST(SecLog_AclVersionType, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_Ssa_RightsM_NvM_RightsM_AclVersion_DefaultValue;
extern CONST(RightsM_NonceType, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_Ssa_RightsM_NvM_RightsM_Nonce_DefaultValue;

#   define RTE_STOP_SEC_CONST_DEFAULT_RTE_CDATA_GROUP_UNSPECIFIED
#   include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  endif

#  define Rte_CData_NvM_RightsM_PostProductionStatus_DefaultValue() (Rte_Ssa_RightsM_NvM_RightsM_PostProductionStatus_DefaultValue)

#  ifndef RTE_PTR2ARRAYTYPE_PASSING
#   define Rte_CData_NvM_RightsM_AclVersion_DefaultValue() (&(Rte_Ssa_RightsM_NvM_RightsM_AclVersion_DefaultValue[0]))
#  else
#   define Rte_CData_NvM_RightsM_AclVersion_DefaultValue() (&Rte_Ssa_RightsM_NvM_RightsM_AclVersion_DefaultValue)
#  endif

#  define Rte_CData_NvM_RightsM_Nonce_DefaultValue() (&Rte_Ssa_RightsM_NvM_RightsM_Nonce_DefaultValue)

/**********************************************************************************************************************
 * Rte_Pim (Per-Instance Memory)
 *********************************************************************************************************************/

#  ifndef RTE_MICROSAR_PIM_EXPORT
#   define RTE_START_SEC_VAR_DEFAULT_RTE_PIM_GROUP_UNSPECIFIED
#   include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern VAR(Ssa_PostProductionStatusType, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_Ssa_RightsM_RightsMPostProductionStatus;
extern VAR(Ssa_PostProductionStatusType, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_Ssa_RightsM_RightsMPostProductionStatusMirror;
extern VAR(Ssa_PostProductionStatusType, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_Ssa_RightsM_RightsMPostProductionStatusMirror2;
extern VAR(SecLog_AclVersionType, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_Ssa_RightsM_RightsMAclVersion;
extern VAR(RightsM_NonceType, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_Ssa_RightsM_RightsMNonce;
extern VAR(RightsM_NonceType, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_Ssa_RightsM_RightsMNonceMirror;

#   define RTE_STOP_SEC_VAR_DEFAULT_RTE_PIM_GROUP_UNSPECIFIED
#   include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  endif

/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Pim_RightsMPostProductionStatus() \
  (&Rte_Ssa_RightsM_RightsMPostProductionStatus)
/* PRQA L:L1 */

/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Pim_RightsMPostProductionStatusMirror() \
  (&Rte_Ssa_RightsM_RightsMPostProductionStatusMirror)
/* PRQA L:L1 */

/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Pim_RightsMPostProductionStatusMirror2() \
  (&Rte_Ssa_RightsM_RightsMPostProductionStatusMirror2)
/* PRQA L:L1 */

/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
#   define Rte_Pim_RightsMAclVersion() (&((*RtePim_RightsMAclVersion())[0]))
#  else
#   define Rte_Pim_RightsMAclVersion() RtePim_RightsMAclVersion()
#  endif
#  define RtePim_RightsMAclVersion() \
  (&Rte_Ssa_RightsM_RightsMAclVersion)
/* PRQA L:L1 */

/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Pim_RightsMNonce() \
  (&Rte_Ssa_RightsM_RightsMNonce)
/* PRQA L:L1 */

/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Pim_RightsMNonceMirror() \
  (&Rte_Ssa_RightsM_RightsMNonceMirror)
/* PRQA L:L1 */


# endif /* !defined(RTE_CORE) */


# define Ssa_RightsM_START_SEC_CODE
# include "Ssa_RightsM_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

# ifndef RTE_CORE
#  define RTE_RUNNABLE_Ssa_RightsM_Certificate_GetDiagAuthCertSerialNumber_SecurityAccess Ssa_RightsM_Certificate_GetDiagAuthCertSerialNumber_SecurityAccess
#  define RTE_RUNNABLE_Ssa_RightsM_Com_ReceiveBroadcastAuthentication Ssa_RightsM_Com_ReceiveBroadcastAuthentication
#  define RTE_RUNNABLE_Ssa_RightsM_CsmCallbackNotification_RandomGenerate Ssa_RightsM_CsmCallbackNotification_RandomGenerate
#  define RTE_RUNNABLE_Ssa_RightsM_CsmCallbackNotification_SigVerify_SecurityAccess Ssa_RightsM_CsmCallbackNotification_SigVerify_SecurityAccess
#  define RTE_RUNNABLE_Ssa_RightsM_CsmCallbackNotification_SignatureVerify Ssa_RightsM_CsmCallbackNotification_SignatureVerify
#  define RTE_RUNNABLE_Ssa_RightsM_DataServices_DID_0185_Basic_ACL_Hash_ConditionCheckRead Ssa_RightsM_DataServices_DID_0185_Basic_ACL_Hash_ConditionCheckRead
#  define RTE_RUNNABLE_Ssa_RightsM_DataServices_DID_0185_Basic_ACL_Hash_ReadData Ssa_RightsM_DataServices_DID_0185_Basic_ACL_Hash_ReadData
#  define RTE_RUNNABLE_Ssa_RightsM_DataServices_DID_0185_Basic_ACL_Version_Candela_File_Version_Major_ConditionCheckRead Ssa_RightsM_DataServices_DID_0185_Basic_ACL_Version_Candela_File_Version_Major_ConditionCheckRead
#  define RTE_RUNNABLE_Ssa_RightsM_DataServices_DID_0185_Basic_ACL_Version_Candela_File_Version_Major_ReadData Ssa_RightsM_DataServices_DID_0185_Basic_ACL_Version_Candela_File_Version_Major_ReadData
#  define RTE_RUNNABLE_Ssa_RightsM_DataServices_DID_0185_Basic_ACL_Version_Candela_File_Version_Minor_ConditionCheckRead Ssa_RightsM_DataServices_DID_0185_Basic_ACL_Version_Candela_File_Version_Minor_ConditionCheckRead
#  define RTE_RUNNABLE_Ssa_RightsM_DataServices_DID_0185_Basic_ACL_Version_Candela_File_Version_Minor_ReadData Ssa_RightsM_DataServices_DID_0185_Basic_ACL_Version_Candela_File_Version_Minor_ReadData
#  define RTE_RUNNABLE_Ssa_RightsM_DataServices_DID_0185_Basic_ACL_Version_Candela_File_Version_Patch_ConditionCheckRead Ssa_RightsM_DataServices_DID_0185_Basic_ACL_Version_Candela_File_Version_Patch_ConditionCheckRead
#  define RTE_RUNNABLE_Ssa_RightsM_DataServices_DID_0185_Basic_ACL_Version_Candela_File_Version_Patch_ReadData Ssa_RightsM_DataServices_DID_0185_Basic_ACL_Version_Candela_File_Version_Patch_ReadData
#  define RTE_RUNNABLE_Ssa_RightsM_DataServices_DID_0185_Basic_ACL_Version_Generation_Time_GTC_ConditionCheckRead Ssa_RightsM_DataServices_DID_0185_Basic_ACL_Version_Generation_Time_GTC_ConditionCheckRead
#  define RTE_RUNNABLE_Ssa_RightsM_DataServices_DID_0185_Basic_ACL_Version_Generation_Time_GTC_ReadData Ssa_RightsM_DataServices_DID_0185_Basic_ACL_Version_Generation_Time_GTC_ReadData
#  define RTE_RUNNABLE_Ssa_RightsM_DataServices_DID_0185_ECU_individual_ACL_Hash_ConditionCheckRead Ssa_RightsM_DataServices_DID_0185_ECU_individual_ACL_Hash_ConditionCheckRead
#  define RTE_RUNNABLE_Ssa_RightsM_DataServices_DID_0185_ECU_individual_ACL_Hash_ReadData Ssa_RightsM_DataServices_DID_0185_ECU_individual_ACL_Hash_ReadData
#  define RTE_RUNNABLE_Ssa_RightsM_DataServices_DID_0185_ECU_individual_ACL_Version_Candela_File_Version_Major_ConditionCheckRead Ssa_RightsM_DataServices_DID_0185_ECU_individual_ACL_Version_Candela_File_Version_Major_ConditionCheckRead
#  define RTE_RUNNABLE_Ssa_RightsM_DataServices_DID_0185_ECU_individual_ACL_Version_Candela_File_Version_Major_ReadData Ssa_RightsM_DataServices_DID_0185_ECU_individual_ACL_Version_Candela_File_Version_Major_ReadData
#  define RTE_RUNNABLE_Ssa_RightsM_DataServices_DID_0185_ECU_individual_ACL_Version_Candela_File_Version_Minor_ConditionCheckRead Ssa_RightsM_DataServices_DID_0185_ECU_individual_ACL_Version_Candela_File_Version_Minor_ConditionCheckRead
#  define RTE_RUNNABLE_Ssa_RightsM_DataServices_DID_0185_ECU_individual_ACL_Version_Candela_File_Version_Minor_ReadData Ssa_RightsM_DataServices_DID_0185_ECU_individual_ACL_Version_Candela_File_Version_Minor_ReadData
#  define RTE_RUNNABLE_Ssa_RightsM_DataServices_DID_0185_ECU_individual_ACL_Version_Candela_File_Version_Patch_ConditionCheckRead Ssa_RightsM_DataServices_DID_0185_ECU_individual_ACL_Version_Candela_File_Version_Patch_ConditionCheckRead
#  define RTE_RUNNABLE_Ssa_RightsM_DataServices_DID_0185_ECU_individual_ACL_Version_Candela_File_Version_Patch_ReadData Ssa_RightsM_DataServices_DID_0185_ECU_individual_ACL_Version_Candela_File_Version_Patch_ReadData
#  define RTE_RUNNABLE_Ssa_RightsM_DataServices_DID_0185_ECU_individual_ACL_Version_Generation_Time_GTC_ConditionCheckRead Ssa_RightsM_DataServices_DID_0185_ECU_individual_ACL_Version_Generation_Time_GTC_ConditionCheckRead
#  define RTE_RUNNABLE_Ssa_RightsM_DataServices_DID_0185_ECU_individual_ACL_Version_Generation_Time_GTC_ReadData Ssa_RightsM_DataServices_DID_0185_ECU_individual_ACL_Version_Generation_Time_GTC_ReadData
#  define RTE_RUNNABLE_Ssa_RightsM_DataServices_DID_018C_Cebas_UserRole_ConditionCheckRead Ssa_RightsM_DataServices_DID_018C_Cebas_UserRole_ConditionCheckRead
#  define RTE_RUNNABLE_Ssa_RightsM_DataServices_DID_018C_Cebas_UserRole_ReadData Ssa_RightsM_DataServices_DID_018C_Cebas_UserRole_ReadData
#  define RTE_RUNNABLE_Ssa_RightsM_DataServices_Diagnostic_Authentication_Certificate_Identification_Read_Issuer_ConditionCheckRead Ssa_RightsM_DataServices_Diagnostic_Authentication_Certificate_Identification_Read_Issuer_ConditionCheckRead
#  define RTE_RUNNABLE_Ssa_RightsM_DataServices_Diagnostic_Authentication_Certificate_Identification_Read_Issuer_ReadData Ssa_RightsM_DataServices_Diagnostic_Authentication_Certificate_Identification_Read_Issuer_ReadData
#  define RTE_RUNNABLE_Ssa_RightsM_DataServices_Diagnostic_Authentication_Certificate_Identification_Read_Serial_Number_ConditionCheckRead Ssa_RightsM_DataServices_Diagnostic_Authentication_Certificate_Identification_Read_Serial_Number_ConditionCheckRead
#  define RTE_RUNNABLE_Ssa_RightsM_DataServices_Diagnostic_Authentication_Certificate_Identification_Read_Serial_Number_ReadData Ssa_RightsM_DataServices_Diagnostic_Authentication_Certificate_Identification_Read_Serial_Number_ReadData
#  define RTE_RUNNABLE_Ssa_RightsM_DataServices_Diagnostic_Authentication_Certificate_Identification_Read_Serial_Number_ReadDataLength Ssa_RightsM_DataServices_Diagnostic_Authentication_Certificate_Identification_Read_Serial_Number_ReadDataLength
#  define RTE_RUNNABLE_Ssa_RightsM_DiagnosticChannel_GetDiagChanAndAuthenticationState Ssa_RightsM_DiagnosticChannel_GetDiagChanAndAuthenticationState
#  define RTE_RUNNABLE_Ssa_RightsM_DiagnosticChannel_GetDiagnosticUserRole Ssa_RightsM_DiagnosticChannel_GetDiagnosticUserRole
#  define RTE_RUNNABLE_Ssa_RightsM_DiagnosticChannel_GetDiagnosticUserRolesBitMask Ssa_RightsM_DiagnosticChannel_GetDiagnosticUserRolesBitMask
#  define RTE_RUNNABLE_Ssa_RightsM_DiagnosticChannel_GetPostProductionStatus Ssa_RightsM_DiagnosticChannel_GetPostProductionStatus
#  define RTE_RUNNABLE_Ssa_RightsM_DiagnosticFirewall_GetDiagnosticUserRole Ssa_RightsM_DiagnosticFirewall_GetDiagnosticUserRole
#  define RTE_RUNNABLE_Ssa_RightsM_DiagnosticFirewall_IsEnhancedAccessRightGranted Ssa_RightsM_DiagnosticFirewall_IsEnhancedAccessRightGranted
#  define RTE_RUNNABLE_Ssa_RightsM_DiagnosticSessionChangeIndication Ssa_RightsM_DiagnosticSessionChangeIndication
#  define RTE_RUNNABLE_Ssa_RightsM_EnhancedRights_VerifySubjectKeyIdentifier Ssa_RightsM_EnhancedRights_VerifySubjectKeyIdentifier
#  define RTE_RUNNABLE_Ssa_RightsM_Init Ssa_RightsM_Init
#  define RTE_RUNNABLE_Ssa_RightsM_MainFunction Ssa_RightsM_MainFunction
#  define RTE_RUNNABLE_Ssa_RightsM_Nonce_Destroy Ssa_RightsM_Nonce_Destroy
#  define RTE_RUNNABLE_Ssa_RightsM_Nonce_Get Ssa_RightsM_Nonce_Get
#  define RTE_RUNNABLE_Ssa_RightsM_RoutineServices_Routine_Authenticate_Diagnostic_User_or_Tester_Start Ssa_RightsM_RoutineServices_Routine_Authenticate_Diagnostic_User_or_Tester_Start
#  define RTE_RUNNABLE_Ssa_RightsM_RoutineServices_Routine_Enhance_Access_Rights_Start Ssa_RightsM_RoutineServices_Routine_Enhance_Access_Rights_Start
#  define RTE_RUNNABLE_Ssa_RightsM_RoutineServices_Routine_Synchronize_Secured_System_Date_and_Time_Start Ssa_RightsM_RoutineServices_Routine_Synchronize_Secured_System_Date_and_Time_Start
#  define RTE_RUNNABLE_Ssa_RightsM_RoutineServices_Status_of_Post_Production_Flag_RequestResults Ssa_RightsM_RoutineServices_Status_of_Post_Production_Flag_RequestResults
#  define RTE_RUNNABLE_Ssa_RightsM_RoutineServices_Status_of_Post_Production_Flag_Start Ssa_RightsM_RoutineServices_Status_of_Post_Production_Flag_Start
#  define RTE_RUNNABLE_Ssa_RightsM_RoutineServices_Status_of_Post_Production_Flag_Stop Ssa_RightsM_RoutineServices_Status_of_Post_Production_Flag_Stop
#  define RTE_RUNNABLE_Ssa_RightsM_SecurityAccess_CompareKey Ssa_RightsM_SecurityAccess_CompareKey
#  define RTE_RUNNABLE_Ssa_RightsM_SecurityAccess_GetSeed Ssa_RightsM_SecurityAccess_GetSeed
#  define RTE_RUNNABLE_Ssa_RightsM_ServiceRequestNotification_Confirmation Ssa_RightsM_ServiceRequestNotification_Confirmation
#  define RTE_RUNNABLE_Ssa_RightsM_ServiceRequestNotification_Indication Ssa_RightsM_ServiceRequestNotification_Indication
# endif

FUNC(Std_ReturnType, Ssa_RightsM_CODE) Ssa_RightsM_Certificate_GetDiagAuthCertSerialNumber_SecurityAccess(P2VAR(uint8, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_VAR) serialNumber); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, Ssa_RightsM_CODE) Ssa_RightsM_Com_ReceiveBroadcastAuthentication(void); /* PRQA S 3451, 0786, 3449 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449 */
FUNC(void, Ssa_RightsM_CODE) Ssa_RightsM_CsmCallbackNotification_RandomGenerate(Csm_ResultType result); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, Ssa_RightsM_CODE) Ssa_RightsM_CsmCallbackNotification_SigVerify_SecurityAccess(Csm_ResultType result); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, Ssa_RightsM_CODE) Ssa_RightsM_CsmCallbackNotification_SignatureVerify(Csm_ResultType result); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, Ssa_RightsM_CODE) Ssa_RightsM_DataServices_DID_0185_Basic_ACL_Hash_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, Ssa_RightsM_CODE) Ssa_RightsM_DataServices_DID_0185_Basic_ACL_Hash_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, Ssa_RightsM_CODE) Ssa_RightsM_DataServices_DID_0185_Basic_ACL_Version_Candela_File_Version_Major_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, Ssa_RightsM_CODE) Ssa_RightsM_DataServices_DID_0185_Basic_ACL_Version_Candela_File_Version_Major_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, Ssa_RightsM_CODE) Ssa_RightsM_DataServices_DID_0185_Basic_ACL_Version_Candela_File_Version_Minor_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, Ssa_RightsM_CODE) Ssa_RightsM_DataServices_DID_0185_Basic_ACL_Version_Candela_File_Version_Minor_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, Ssa_RightsM_CODE) Ssa_RightsM_DataServices_DID_0185_Basic_ACL_Version_Candela_File_Version_Patch_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, Ssa_RightsM_CODE) Ssa_RightsM_DataServices_DID_0185_Basic_ACL_Version_Candela_File_Version_Patch_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, Ssa_RightsM_CODE) Ssa_RightsM_DataServices_DID_0185_Basic_ACL_Version_Generation_Time_GTC_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, Ssa_RightsM_CODE) Ssa_RightsM_DataServices_DID_0185_Basic_ACL_Version_Generation_Time_GTC_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, Ssa_RightsM_CODE) Ssa_RightsM_DataServices_DID_0185_ECU_individual_ACL_Hash_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, Ssa_RightsM_CODE) Ssa_RightsM_DataServices_DID_0185_ECU_individual_ACL_Hash_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, Ssa_RightsM_CODE) Ssa_RightsM_DataServices_DID_0185_ECU_individual_ACL_Version_Candela_File_Version_Major_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, Ssa_RightsM_CODE) Ssa_RightsM_DataServices_DID_0185_ECU_individual_ACL_Version_Candela_File_Version_Major_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, Ssa_RightsM_CODE) Ssa_RightsM_DataServices_DID_0185_ECU_individual_ACL_Version_Candela_File_Version_Minor_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, Ssa_RightsM_CODE) Ssa_RightsM_DataServices_DID_0185_ECU_individual_ACL_Version_Candela_File_Version_Minor_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, Ssa_RightsM_CODE) Ssa_RightsM_DataServices_DID_0185_ECU_individual_ACL_Version_Candela_File_Version_Patch_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, Ssa_RightsM_CODE) Ssa_RightsM_DataServices_DID_0185_ECU_individual_ACL_Version_Candela_File_Version_Patch_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, Ssa_RightsM_CODE) Ssa_RightsM_DataServices_DID_0185_ECU_individual_ACL_Version_Generation_Time_GTC_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, Ssa_RightsM_CODE) Ssa_RightsM_DataServices_DID_0185_ECU_individual_ACL_Version_Generation_Time_GTC_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, Ssa_RightsM_CODE) Ssa_RightsM_DataServices_DID_018C_Cebas_UserRole_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, Ssa_RightsM_CODE) Ssa_RightsM_DataServices_DID_018C_Cebas_UserRole_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, Ssa_RightsM_CODE) Ssa_RightsM_DataServices_DID_018C_Cebas_UserRole_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data1ByteType, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
FUNC(Std_ReturnType, Ssa_RightsM_CODE) Ssa_RightsM_DataServices_Diagnostic_Authentication_Certificate_Identification_Read_Issuer_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, Ssa_RightsM_CODE) Ssa_RightsM_DataServices_Diagnostic_Authentication_Certificate_Identification_Read_Issuer_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, Ssa_RightsM_CODE) Ssa_RightsM_DataServices_Diagnostic_Authentication_Certificate_Identification_Read_Serial_Number_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, Ssa_RightsM_CODE) Ssa_RightsM_DataServices_Diagnostic_Authentication_Certificate_Identification_Read_Serial_Number_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, Ssa_RightsM_CODE) Ssa_RightsM_DataServices_Diagnostic_Authentication_Certificate_Identification_Read_Serial_Number_ReadDataLength(Dcm_OpStatusType OpStatus, P2VAR(uint16, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_VAR) DataLength); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, Ssa_RightsM_CODE) Ssa_RightsM_DiagnosticChannel_GetDiagChanAndAuthenticationState(P2VAR(uint8, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_VAR) diagChanAndAuthStatus); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, Ssa_RightsM_CODE) Ssa_RightsM_DiagnosticChannel_GetDiagnosticUserRole(P2VAR(RightsM_DiagnosticUserRoleType, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_VAR) userRole); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, Ssa_RightsM_CODE) Ssa_RightsM_DiagnosticChannel_GetDiagnosticUserRolesBitMask(P2VAR(RightsM_ACL_BitMaskType, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_VAR) userRolesBitMask); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, Ssa_RightsM_CODE) Ssa_RightsM_DiagnosticChannel_GetPostProductionStatus(P2VAR(Ssa_PostProductionStatusType, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_VAR) status); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, Ssa_RightsM_CODE) Ssa_RightsM_DiagnosticFirewall_GetDiagnosticUserRole(uint16 SourceAddress, P2VAR(RightsM_DiagnosticUserRoleType, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_VAR) UserRole); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, Ssa_RightsM_CODE) Ssa_RightsM_DiagnosticFirewall_IsEnhancedAccessRightGranted(uint16 SourceAddress, uint8 SID, P2VAR(boolean, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_VAR) AccessRightGranted); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, Ssa_RightsM_CODE) Ssa_RightsM_DiagnosticSessionChangeIndication(void); /* PRQA S 3451, 0786, 3449 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449 */
FUNC(Std_ReturnType, Ssa_RightsM_CODE) Ssa_RightsM_EnhancedRights_VerifySubjectKeyIdentifier(P2CONST(uint8, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_DATA) subjectKeyIdentifier); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, Ssa_RightsM_CODE) Ssa_RightsM_Init(void); /* PRQA S 3451, 0786, 3449 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449 */
FUNC(void, Ssa_RightsM_CODE) Ssa_RightsM_MainFunction(void); /* PRQA S 3451, 0786, 3449 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449 */
FUNC(Std_ReturnType, Ssa_RightsM_CODE) Ssa_RightsM_Nonce_Destroy(void); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, Ssa_RightsM_CODE) Ssa_RightsM_Nonce_Get(boolean generateNew, P2VAR(uint8, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_VAR) nonce); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, Ssa_RightsM_CODE) Ssa_RightsM_RoutineServices_Routine_Authenticate_Diagnostic_User_or_Tester_Start(uint8 Configuration, uint8 Task, P2CONST(uint8, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_DATA) Challenge_Certificate_Proof_of_Ownership, Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_VAR) routineInfo, P2VAR(uint8, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_VAR) Verification_Result, P2VAR(uint8, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_VAR) Authentication_Result, P2VAR(uint16, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_VAR) DataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, Ssa_RightsM_CODE) Ssa_RightsM_RoutineServices_Routine_Enhance_Access_Rights_Start(P2CONST(uint8, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_DATA) Enhanced_Rights_Certificate, Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_VAR) routineInfo, P2VAR(uint8, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_VAR) Verification_Result, uint16 DataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, Ssa_RightsM_CODE) Ssa_RightsM_RoutineServices_Routine_Synchronize_Secured_System_Date_and_Time_Start(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_VAR) routineInfo, P2VAR(uint8, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_VAR) Nonce, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, Ssa_RightsM_CODE) Ssa_RightsM_RoutineServices_Status_of_Post_Production_Flag_RequestResults(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_VAR) routineInfo_Out, P2VAR(uint8, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_VAR) Post_Production_Flag_Out, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, Ssa_RightsM_CODE) Ssa_RightsM_RoutineServices_Status_of_Post_Production_Flag_Start(uint8 In_Post_Production_Flag_In, Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_VAR) routineInfo_Out, P2VAR(uint8, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_VAR) Out_Post_Production_Flag_Out, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, Ssa_RightsM_CODE) Ssa_RightsM_RoutineServices_Status_of_Post_Production_Flag_Stop(uint8 In_Post_Production_Flag_In, Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_VAR) routineInfo_Out, P2VAR(uint8, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_VAR) Out_Post_Production_Flag_Out, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, Ssa_RightsM_CODE) Ssa_RightsM_SecurityAccess_CompareKey(uint8 secLevel, P2CONST(uint8, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_DATA) key, Dcm_OpStatusType opStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_VAR) errorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, Ssa_RightsM_CODE) Ssa_RightsM_SecurityAccess_GetSeed(uint8 secLevel, Dcm_OpStatusType opStatus, P2VAR(uint8, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_VAR) seed, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_VAR) errorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, Ssa_RightsM_CODE) Ssa_RightsM_ServiceRequestNotification_Confirmation(uint8 SID, uint8 ReqType, uint16 SourceAddress, Dcm_ConfirmationStatusType ConfirmationStatus); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, Ssa_RightsM_CODE) Ssa_RightsM_ServiceRequestNotification_Indication(uint8 SID, P2CONST(uint8, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_DATA) RequestData, uint16 DataSize, uint8 ReqType, uint16 SourceAddress, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */

# define Ssa_RightsM_STOP_SEC_CODE
# include "Ssa_RightsM_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Application errors
 *********************************************************************************************************************/

#  define RTE_E_CertP_Functions_E_NOT_OK (1U)

#  define RTE_E_CsmKeyManagement_Ssa_SignatureRamKey_CSM_E_BUSY (2U)

#  define RTE_E_CsmKeyManagement_Ssa_SignatureRamKey_CSM_E_KEY_NOT_AVAILABLE (8U)

#  define RTE_E_CsmKeyManagement_Ssa_SignatureRamKey_CSM_E_KEY_SIZE_MISMATCH (10U)

#  define RTE_E_CsmKeyManagement_Ssa_SignatureRamKey_CSM_E_KEY_WRITE_FAIL (7U)

#  define RTE_E_CsmKeyManagement_Ssa_SignatureRamKey_CSM_E_SMALL_BUFFER (3U)

#  define RTE_E_CsmKeyManagement_Ssa_SignatureRamKey_E_NOT_OK (1U)

#  define RTE_E_CsmRandomGenerate_Random_CSM_E_BUSY (2U)

#  define RTE_E_CsmRandomGenerate_Random_CSM_E_ENTROPY_EXHAUSTION (4U)

#  define RTE_E_CsmRandomGenerate_Random_E_NOT_OK (1U)

#  define RTE_E_DataServices_DID_0185_Basic_ACL_Hash_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_DID_0185_Basic_ACL_Hash_E_NOT_OK (1U)

#  define RTE_E_DataServices_DID_0185_Basic_ACL_Version_Candela_File_Version_Major_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_DID_0185_Basic_ACL_Version_Candela_File_Version_Major_E_NOT_OK (1U)

#  define RTE_E_DataServices_DID_0185_Basic_ACL_Version_Candela_File_Version_Minor_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_DID_0185_Basic_ACL_Version_Candela_File_Version_Minor_E_NOT_OK (1U)

#  define RTE_E_DataServices_DID_0185_Basic_ACL_Version_Candela_File_Version_Patch_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_DID_0185_Basic_ACL_Version_Candela_File_Version_Patch_E_NOT_OK (1U)

#  define RTE_E_DataServices_DID_0185_Basic_ACL_Version_Generation_Time_GTC_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_DID_0185_Basic_ACL_Version_Generation_Time_GTC_E_NOT_OK (1U)

#  define RTE_E_DataServices_DID_0185_ECU_individual_ACL_Hash_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_DID_0185_ECU_individual_ACL_Hash_E_NOT_OK (1U)

#  define RTE_E_DataServices_DID_0185_ECU_individual_ACL_Version_Candela_File_Version_Major_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_DID_0185_ECU_individual_ACL_Version_Candela_File_Version_Major_E_NOT_OK (1U)

#  define RTE_E_DataServices_DID_0185_ECU_individual_ACL_Version_Candela_File_Version_Minor_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_DID_0185_ECU_individual_ACL_Version_Candela_File_Version_Minor_E_NOT_OK (1U)

#  define RTE_E_DataServices_DID_0185_ECU_individual_ACL_Version_Candela_File_Version_Patch_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_DID_0185_ECU_individual_ACL_Version_Candela_File_Version_Patch_E_NOT_OK (1U)

#  define RTE_E_DataServices_DID_0185_ECU_individual_ACL_Version_Generation_Time_GTC_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_DID_0185_ECU_individual_ACL_Version_Generation_Time_GTC_E_NOT_OK (1U)

#  define RTE_E_DataServices_DID_018C_Cebas_UserRole_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_DID_018C_Cebas_UserRole_E_NOT_OK (1U)

#  define RTE_E_DataServices_Diagnostic_Authentication_Certificate_Identification_Read_Diagnostic_Authentication_Certificate_Issuer_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Diagnostic_Authentication_Certificate_Identification_Read_Diagnostic_Authentication_Certificate_Issuer_E_NOT_OK (1U)

#  define RTE_E_DataServices_Diagnostic_Authentication_Certificate_Identification_Read_Diagnostic_Authentication_Certificate_Serial_Number_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Diagnostic_Authentication_Certificate_Identification_Read_Diagnostic_Authentication_Certificate_Serial_Number_E_NOT_OK (1U)

#  define RTE_E_DiagnosticMonitor_E_NOT_OK (1U)

#  define RTE_E_KeyM_Certificate_E_NOT_OK (1U)

#  define RTE_E_KeyM_Certificate_E_PENDING (10U)

#  define RTE_E_NvMService_AC2_SRBS_E_NOT_OK (1U)

#  define RTE_E_RightsM_DiagnosticChannel_E_NOT_OK (1U)

#  define RTE_E_RightsM_DiagnosticFirewall_E_NOT_OK (1U)

#  define RTE_E_RightsM_EnhancedRights_E_NOT_OK (1U)

#  define RTE_E_RightsM_Nonce_E_INVALID (3U)

#  define RTE_E_RightsM_Nonce_E_NOT_OK (1U)

#  define RTE_E_RightsM_Nonce_E_PENDING (10U)

#  define RTE_E_RoutineServices_Routine_Authenticate_Diagnostic_User_or_Tester_DCM_E_FORCE_RCRRP (12U)

#  define RTE_E_RoutineServices_Routine_Authenticate_Diagnostic_User_or_Tester_DCM_E_PENDING (10U)

#  define RTE_E_RoutineServices_Routine_Authenticate_Diagnostic_User_or_Tester_E_NOT_OK (1U)

#  define RTE_E_RoutineServices_Routine_Enhance_Access_Rights_DCM_E_FORCE_RCRRP (12U)

#  define RTE_E_RoutineServices_Routine_Enhance_Access_Rights_DCM_E_PENDING (10U)

#  define RTE_E_RoutineServices_Routine_Enhance_Access_Rights_E_NOT_OK (1U)

#  define RTE_E_RoutineServices_Routine_Synchronize_Secured_System_Date_and_Time_DCM_E_FORCE_RCRRP (12U)

#  define RTE_E_RoutineServices_Routine_Synchronize_Secured_System_Date_and_Time_DCM_E_PENDING (10U)

#  define RTE_E_RoutineServices_Routine_Synchronize_Secured_System_Date_and_Time_E_NOT_OK (1U)

#  define RTE_E_RoutineServices_Status_of_Post_Production_Flag_DCM_E_FORCE_RCRRP (12U)

#  define RTE_E_RoutineServices_Status_of_Post_Production_Flag_DCM_E_PENDING (10U)

#  define RTE_E_RoutineServices_Status_of_Post_Production_Flag_E_NOT_OK (1U)

#  define RTE_E_SecLog_AuthorizationBySecurityAccess_E_NOT_OK (1U)

#  define RTE_E_SecLog_EcuIndividualAclReplacementEvent_E_NOT_OK (1U)

#  define RTE_E_SecLog_RightsManagementEvent_E_NOT_OK (1U)

#  define RTE_E_SecLog_SuccessfulAuthAndEnhanceRights_E_NOT_OK (1U)

#  define RTE_E_SecLog_SuccessfulDiagServiceExecutionEvent_E_NOT_OK (1U)

#  define RTE_E_SecurityAccessServices_GenericSecurityAccess_E_NOT_OK (1U)

#  define RTE_E_SecurityAccessServices_GenericSecurityAccess_E_PENDING (10U)

#  define RTE_E_ServiceRequestNotification_E_NOT_OK (1U)

#  define RTE_E_ServiceRequestNotification_E_REQUEST_NOT_ACCEPTED (8U)

#  define RTE_E_SsaCdd_CryptoInterface_E_NOT_OK (1U)

#  define RTE_E_Ssa_RightsM_Certificate_E_NOT_OK (1U)

#  define RTE_E_Ssa_RightsM_DiagnosticInformation_E_NOT_OK (1U)

#  define RTE_E_TimeM_RealTime_E_NOT_OK (1U)

#  define RTE_E_TimeM_TickCount_E_NOT_OK (1U)
# endif /* !defined(RTE_CORE) */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* RTE_SSA_RIGHTSM_H */

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
