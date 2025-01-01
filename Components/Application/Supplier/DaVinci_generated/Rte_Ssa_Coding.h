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
 *             File:  Rte_Ssa_Coding.h
 *           Config:  StartApplication.dpa
 *      ECU-Project:  StartApplication
 *
 *        Generator:  MICROSAR RTE Generator Version 4.32.0
 *                    RTE Core Version 4.32.0
 *          License:  CBD2200333
 *
 *      Description:  Application header file for SW-C <Ssa_Coding>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef RTE_SSA_CODING_H
# define RTE_SSA_CODING_H

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

# include "Rte_Ssa_Coding_Type.h"
# include "Rte_DataHandleType.h"

# include "Rte_Hook.h"


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

#  define Rte_InitValue_Coding_ReceiveVINTimeout_state (0U)
#  define Rte_InitValue_Coding_VINStatus_status (1U)
# endif


# define RTE_START_SEC_CODE
# include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Ssa_Coding_Coding_Com_ReceiveVIN_VIN(P2VAR(uint8, AUTOMATIC, RTE_SSA_CODING_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Ssa_Coding_Coding_Com_ReceiveVIN_VIN(P2VAR(Coding_VINDataType, AUTOMATIC, RTE_SSA_CODING_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
FUNC(Std_ReturnType, RTE_CODE) Rte_Switch_Ssa_Coding_Coding_Mode_CodingStatus(Coding_ModeType nextMode);


# define RTE_STOP_SEC_CODE
# include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# ifndef RTE_CORE

/**********************************************************************************************************************
 * Rte_Read_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Read_Coding_Com_ReceiveVIN_VIN Rte_Read_Ssa_Coding_Coding_Com_ReceiveVIN_VIN


/**********************************************************************************************************************
 * Rte_Write_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Write_Coding_VINStatus_status Rte_Write_Ssa_Coding_Coding_VINStatus_status
#  define Rte_Write_Ssa_Coding_Coding_VINStatus_status(data) (RTE_E_OK)


/**********************************************************************************************************************
 * Rte_Mode_<p>_<m>
 *********************************************************************************************************************/
#  define Rte_Mode_Coding_MemoryStatus_MemoryStatus() (RTE_MODE_Coding_MemoryStatus_CODING_MEMSTAT_OK)


/**********************************************************************************************************************
 * Rte_Switch_<p>_<m>
 *********************************************************************************************************************/
#  define Rte_Switch_Coding_Mode_CodingStatus Rte_Switch_Ssa_Coding_Coding_Mode_CodingStatus


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

#  define RTE_START_SEC_DEMSATELLITE_0_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FUNC(Std_ReturnType, RTE_DEMSATELLITE_0_APPL_CODE) Dem_SetEventStatus(Dem_EventIdType parg0, Dem_EventStatusType EventStatus); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */

#  define RTE_STOP_SEC_DEMSATELLITE_0_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define RTE_START_SEC_NVM_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FUNC(Std_ReturnType, RTE_NVM_APPL_CODE) NvM_GetErrorStatus(NvM_BlockIdType parg0, P2VAR(NvM_RequestResultType, AUTOMATIC, RTE_NVM_APPL_VAR) ErrorStatus); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_NVM_APPL_CODE) NvM_WriteBlock(NvM_BlockIdType parg0, dtRef_const_VOID SrcPtr); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */

#  define RTE_STOP_SEC_NVM_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define RTE_START_SEC_SSA_CDD_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FUNC(Std_ReturnType, RTE_SSA_CDD_APPL_CODE) Ssa_Cdd_NvM_GetErrorStatus(P2VAR(NvM_RequestResultType, AUTOMATIC, RTE_SSA_CDD_APPL_VAR) ErrorStatus); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_SSA_CDD_APPL_CODE) Ssa_Cdd_NvM_ReadBlock(dtRef_VOID DstPtr); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_SSA_CDD_APPL_CODE) Ssa_Cdd_NvM_SetRamBlockStatus(boolean RamBlockStatus); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_SSA_CDD_APPL_CODE) Ssa_Cdd_NvM_WriteBlock(dtRef_const_VOID SrcPtr); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_SSA_CDD_APPL_CODE) Ssa_Cdd_Csm_CancelJob(uint32 jobId, Crypto_OperationModeType operationMode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_SSA_CDD_APPL_CODE) Ssa_Cdd_Csm_SignatureVerify(uint32 jobId, Crypto_OperationModeType operationMode, Ssa_ConstDataPtr dataBuffer, uint32 dataLength, Ssa_ConstDataPtr compareBuffer, uint32 compareLength, Ssa_VerifyResultPtr resultBuffer); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */

#  define RTE_STOP_SEC_SSA_CDD_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define RTE_START_SEC_SSA_CERTP_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_SSA_CERTP_APPL_CODE) Ssa_CertP_Certificate_Parse(P2CONST(uint8, AUTOMATIC, RTE_SSA_CERTP_APPL_DATA) rawCertData, uint16 rawCertLength, P2VAR(CertP_ParsedCertStructureType, AUTOMATIC, RTE_SSA_CERTP_APPL_VAR) parsedCert); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_SSA_CERTP_APPL_CODE) Ssa_CertP_Certificate_Parse(P2CONST(CertP_RawCertBufferType, AUTOMATIC, RTE_SSA_CERTP_APPL_DATA) rawCertData, uint16 rawCertLength, P2VAR(CertP_ParsedCertStructureType, AUTOMATIC, RTE_SSA_CERTP_APPL_VAR) parsedCert); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif

#  define RTE_STOP_SEC_SSA_CERTP_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define RTE_START_SEC_SSA_KEYM_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FUNC(Std_ReturnType, RTE_SSA_KEYM_APPL_CODE) Ssa_KeyM_Certificate_CheckTrustModelChainOfTrust(P2VAR(Ssa_TrustModelChainState_Type, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) state); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_SSA_KEYM_APPL_CODE) Ssa_KeyM_Certificate_VerifyCertWithBackendCert(P2CONST(uint8, AUTOMATIC, RTE_SSA_KEYM_APPL_DATA) cert, P2VAR(CertP_ParsedCertStructureType, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) parsedCertStructure, uint16 certLength, CertP_PkiRoleType expectedPkiRole, P2CONST(RightsM_AuthNonceType, AUTOMATIC, RTE_SSA_KEYM_APPL_DATA) expectedNonce); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_SSA_KEYM_APPL_CODE) Ssa_KeyM_Certificate_VerifyCertWithBackendCert(P2CONST(CertP_RawCertBufferType, AUTOMATIC, RTE_SSA_KEYM_APPL_DATA) cert, P2VAR(CertP_ParsedCertStructureType, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) parsedCertStructure, uint16 certLength, CertP_PkiRoleType expectedPkiRole, P2CONST(RightsM_AuthNonceType, AUTOMATIC, RTE_SSA_KEYM_APPL_DATA) expectedNonce); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif

#  define RTE_STOP_SEC_SSA_KEYM_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define RTE_START_SEC_SSA_SECLOG_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_SSA_SECLOG_APPL_CODE) Ssa_SecLog_LogEvent_ChangeVin(P2CONST(uint8, AUTOMATIC, RTE_SSA_SECLOG_APPL_DATA) newVin); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_SSA_SECLOG_APPL_CODE) Ssa_SecLog_LogEvent_ChangeVin(P2CONST(SecLog_VinType, AUTOMATIC, RTE_SSA_SECLOG_APPL_DATA) newVin); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
FUNC(Std_ReturnType, RTE_SSA_SECLOG_APPL_CODE) Ssa_SecLog_LogEvent_SignatureVerification(uint8 parg0, uint8 verificationResult); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */

#  define RTE_STOP_SEC_SSA_SECLOG_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define Rte_Call_CertP_Functions_Certificate_Parse Ssa_CertP_Certificate_Parse
#  define Rte_Call_DTC_0x164456_SetEventStatus(arg1) (Dem_SetEventStatus((Dem_EventIdType)3, arg1))
#  define Rte_Call_KeyM_Certificate_CheckTrustModelChainOfTrust Ssa_KeyM_Certificate_CheckTrustModelChainOfTrust
#  define Rte_Call_KeyM_Certificate_VerifyCertWithBackendCert Ssa_KeyM_Certificate_VerifyCertWithBackendCert
#  define Rte_Call_Key_SignatureRamKey_KeyElementSet(arg1, arg2, arg3) (Csm_KeyElementSet((uint32)47, arg1, arg2, arg3))
#  define Rte_Call_Key_SignatureRamKey_KeySetValid() (Csm_KeySetValid((uint32)47))
#  define Rte_Call_NvM_CodingVIN_GetErrorStatus(arg1) (NvM_GetErrorStatus((NvM_BlockIdType)3, arg1))
#  define Rte_Call_NvM_CodingVIN_WriteBlock(arg1) (NvM_WriteBlock((NvM_BlockIdType)3, arg1))
#  define Rte_Call_NvM_ControlLink_GetErrorStatus Ssa_Cdd_NvM_GetErrorStatus
#  define Rte_Call_NvM_ControlLink_ReadBlock Ssa_Cdd_NvM_ReadBlock
#  define Rte_Call_NvM_ControlLink_SetRamBlockStatus Ssa_Cdd_NvM_SetRamBlockStatus
#  define Rte_Call_NvM_ControlLink_WriteBlock Ssa_Cdd_NvM_WriteBlock
#  define Rte_Call_NvM_CurrentVIN_GetErrorStatus(arg1) (NvM_GetErrorStatus((NvM_BlockIdType)4, arg1))
#  define Rte_Call_NvM_CurrentVIN_WriteBlock(arg1) (NvM_WriteBlock((NvM_BlockIdType)4, arg1))
#  define Rte_Call_SecLog_ChangeVinEvent_ChangeVin Ssa_SecLog_LogEvent_ChangeVin
#  define Rte_Call_SecLog_SignatureVerificationEvent_VerifySignatureVariantCoding_SignatureVerification(arg1) (Ssa_SecLog_LogEvent_SignatureVerification((uint8)1, arg1))
#  define Rte_Call_SsaCdd_Csm_CancelJob Ssa_Cdd_Csm_CancelJob
#  define Rte_Call_SsaCdd_Csm_SignatureVerify Ssa_Cdd_Csm_SignatureVerify

/**********************************************************************************************************************
 * Exclusive Areas
 *********************************************************************************************************************/

#  define Rte_Enter_Coding_ExclusiveArea_VIN() SuspendAllInterrupts() /* RteAnalyzer(ExclusiveArea, ALL_INTERRUPT_BLOCKING) */

#  define Rte_Exit_Coding_ExclusiveArea_VIN() ResumeAllInterrupts()  /* RteAnalyzer(ExclusiveArea, ALL_INTERRUPT_BLOCKING) */


/**********************************************************************************************************************
 * Rte_CData (SW-C local calibration parameters)
 *********************************************************************************************************************/

#  ifndef RTE_MICROSAR_PIM_EXPORT

#   define RTE_START_SEC_CONST_DEFAULT_RTE_CDATA_GROUP_UNSPECIFIED
#   include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern CONST(Coding_StorageType, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_Ssa_Coding_Coding_Storage_DefaultValue;

#   define RTE_STOP_SEC_CONST_DEFAULT_RTE_CDATA_GROUP_UNSPECIFIED
#   include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  endif

#  define Rte_CData_Coding_Storage_DefaultValue() (&Rte_Ssa_Coding_Coding_Storage_DefaultValue)

/**********************************************************************************************************************
 * Rte_Pim (Per-Instance Memory)
 *********************************************************************************************************************/

#  ifndef RTE_MICROSAR_PIM_EXPORT
#   define RTE_START_SEC_VAR_DEFAULT_RTE_PIM_GROUP_UNSPECIFIED
#   include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern VAR(Coding_StorageType, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_Ssa_Coding_CodingVIN;
extern VAR(Coding_StorageType, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_Ssa_Coding_CodingVINMirror;
extern VAR(Coding_StorageType, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_Ssa_Coding_CurrentVIN;
extern VAR(Coding_StorageType, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_Ssa_Coding_CurrentVINMirror;

#   define RTE_STOP_SEC_VAR_DEFAULT_RTE_PIM_GROUP_UNSPECIFIED
#   include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  endif

/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Pim_CodingVIN() \
  (&Rte_Ssa_Coding_CodingVIN)
/* PRQA L:L1 */

/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Pim_CodingVINMirror() \
  (&Rte_Ssa_Coding_CodingVINMirror)
/* PRQA L:L1 */

/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Pim_CurrentVIN() \
  (&Rte_Ssa_Coding_CurrentVIN)
/* PRQA L:L1 */

/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Pim_CurrentVINMirror() \
  (&Rte_Ssa_Coding_CurrentVINMirror)
/* PRQA L:L1 */


# endif /* !defined(RTE_CORE) */


# define Ssa_Coding_START_SEC_CODE
# include "Ssa_Coding_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

# ifndef RTE_CORE
#  define RTE_RUNNABLE_Ssa_Coding_CsmCallbackNotification_SigVerify_Coding Ssa_Coding_CsmCallbackNotification_SigVerify_Coding
#  define RTE_RUNNABLE_Ssa_Coding_DataServices_DID_018E_VIN_Lock_Status_ConditionCheckRead Ssa_Coding_DataServices_DID_018E_VIN_Lock_Status_ConditionCheckRead
#  define RTE_RUNNABLE_Ssa_Coding_DataServices_DID_018E_VIN_Lock_Status_ReadData Ssa_Coding_DataServices_DID_018E_VIN_Lock_Status_ReadData
#  define RTE_RUNNABLE_Ssa_Coding_DataServices_DID_018E_VIN_Status_ConditionCheckRead Ssa_Coding_DataServices_DID_018E_VIN_Status_ConditionCheckRead
#  define RTE_RUNNABLE_Ssa_Coding_DataServices_DID_018E_VIN_Status_ReadData Ssa_Coding_DataServices_DID_018E_VIN_Status_ReadData
#  define RTE_RUNNABLE_Ssa_Coding_DataServices_DID_0197_Precompile_switch_ConditionCheckRead Ssa_Coding_DataServices_DID_0197_Precompile_switch_ConditionCheckRead
#  define RTE_RUNNABLE_Ssa_Coding_DataServices_DID_0197_Precompile_switch_ReadData Ssa_Coding_DataServices_DID_0197_Precompile_switch_ReadData
#  define RTE_RUNNABLE_Ssa_Coding_DataServices_DID_EF04_SSA_Major_Version_ConditionCheckRead Ssa_Coding_DataServices_DID_EF04_SSA_Major_Version_ConditionCheckRead
#  define RTE_RUNNABLE_Ssa_Coding_DataServices_DID_EF04_SSA_Major_Version_ReadData Ssa_Coding_DataServices_DID_EF04_SSA_Major_Version_ReadData
#  define RTE_RUNNABLE_Ssa_Coding_DataServices_DID_EF04_SSA_Minor_Version_ConditionCheckRead Ssa_Coding_DataServices_DID_EF04_SSA_Minor_Version_ConditionCheckRead
#  define RTE_RUNNABLE_Ssa_Coding_DataServices_DID_EF04_SSA_Minor_Version_ReadData Ssa_Coding_DataServices_DID_EF04_SSA_Minor_Version_ReadData
#  define RTE_RUNNABLE_Ssa_Coding_DataServices_DID_EF04_SSA_Patch_Level_ConditionCheckRead Ssa_Coding_DataServices_DID_EF04_SSA_Patch_Level_ConditionCheckRead
#  define RTE_RUNNABLE_Ssa_Coding_DataServices_DID_EF04_SSA_Patch_Level_ReadData Ssa_Coding_DataServices_DID_EF04_SSA_Patch_Level_ReadData
#  define RTE_RUNNABLE_Ssa_Coding_DataServices_VINDataIdentifier_ConditionCheckRead Ssa_Coding_DataServices_VINDataIdentifier_ConditionCheckRead
#  define RTE_RUNNABLE_Ssa_Coding_DataServices_VINDataIdentifier_ReadData Ssa_Coding_DataServices_VINDataIdentifier_ReadData
#  define RTE_RUNNABLE_Ssa_Coding_DataServices_VINDataIdentifier_WriteData Ssa_Coding_DataServices_VINDataIdentifier_WriteData
#  define RTE_RUNNABLE_Ssa_Coding_Init Ssa_Coding_Init
#  define RTE_RUNNABLE_Ssa_Coding_InitMonitorForEvent_DTC_0x164456 Ssa_Coding_InitMonitorForEvent_DTC_0x164456
#  define RTE_RUNNABLE_Ssa_Coding_MainFunction Ssa_Coding_MainFunction
#  define RTE_RUNNABLE_Ssa_Coding_RoutineServices_Routine_Evaluate_Data_Verification_Certificate_Start Ssa_Coding_RoutineServices_Routine_Evaluate_Data_Verification_Certificate_Start
#  define RTE_RUNNABLE_Ssa_Coding_RoutineServices_Routine_Reset_VIN_Values_Start Ssa_Coding_RoutineServices_Routine_Reset_VIN_Values_Start
#  define RTE_RUNNABLE_Ssa_Coding_RoutineServices_Routine_Verify_Signature_Start Ssa_Coding_RoutineServices_Routine_Verify_Signature_Start
#  define RTE_RUNNABLE_Ssa_Coding_ServiceRequestNotification_Confirmation Ssa_Coding_ServiceRequestNotification_Confirmation
#  define RTE_RUNNABLE_Ssa_Coding_ServiceRequestNotification_Indication Ssa_Coding_ServiceRequestNotification_Indication
#  define RTE_RUNNABLE_Ssa_Coding_VIN_Get Ssa_Coding_VIN_Get
#  define RTE_RUNNABLE_Ssa_Coding_VIN_GetStoreState Ssa_Coding_VIN_GetStoreState
#  define RTE_RUNNABLE_Ssa_Coding_VIN_Lock Ssa_Coding_VIN_Lock
#  define RTE_RUNNABLE_Ssa_Coding_VIN_Receive Ssa_Coding_VIN_Receive
#  define RTE_RUNNABLE_Ssa_Coding_VIN_Receive_Timeout Ssa_Coding_VIN_Receive_Timeout
#  define RTE_RUNNABLE_Ssa_Coding_VIN_Set Ssa_Coding_VIN_Set
# endif

FUNC(void, Ssa_Coding_CODE) Ssa_Coding_CsmCallbackNotification_SigVerify_Coding(Csm_ResultType result); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, Ssa_Coding_CODE) Ssa_Coding_DataServices_DID_018E_VIN_Lock_Status_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_CODING_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, Ssa_Coding_CODE) Ssa_Coding_DataServices_DID_018E_VIN_Lock_Status_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_SSA_CODING_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, Ssa_Coding_CODE) Ssa_Coding_DataServices_DID_018E_VIN_Lock_Status_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data1ByteType, AUTOMATIC, RTE_SSA_CODING_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
FUNC(Std_ReturnType, Ssa_Coding_CODE) Ssa_Coding_DataServices_DID_018E_VIN_Status_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_CODING_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, Ssa_Coding_CODE) Ssa_Coding_DataServices_DID_018E_VIN_Status_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_SSA_CODING_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, Ssa_Coding_CODE) Ssa_Coding_DataServices_DID_018E_VIN_Status_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data1ByteType, AUTOMATIC, RTE_SSA_CODING_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
FUNC(Std_ReturnType, Ssa_Coding_CODE) Ssa_Coding_DataServices_DID_0197_Precompile_switch_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_CODING_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, Ssa_Coding_CODE) Ssa_Coding_DataServices_DID_0197_Precompile_switch_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_SSA_CODING_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, Ssa_Coding_CODE) Ssa_Coding_DataServices_DID_0197_Precompile_switch_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data4ByteType, AUTOMATIC, RTE_SSA_CODING_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
FUNC(Std_ReturnType, Ssa_Coding_CODE) Ssa_Coding_DataServices_DID_EF04_SSA_Major_Version_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_CODING_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, Ssa_Coding_CODE) Ssa_Coding_DataServices_DID_EF04_SSA_Major_Version_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_SSA_CODING_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, Ssa_Coding_CODE) Ssa_Coding_DataServices_DID_EF04_SSA_Minor_Version_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_CODING_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, Ssa_Coding_CODE) Ssa_Coding_DataServices_DID_EF04_SSA_Minor_Version_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_SSA_CODING_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, Ssa_Coding_CODE) Ssa_Coding_DataServices_DID_EF04_SSA_Patch_Level_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_CODING_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, Ssa_Coding_CODE) Ssa_Coding_DataServices_DID_EF04_SSA_Patch_Level_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_SSA_CODING_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, Ssa_Coding_CODE) Ssa_Coding_DataServices_VINDataIdentifier_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_CODING_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, Ssa_Coding_CODE) Ssa_Coding_DataServices_VINDataIdentifier_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_SSA_CODING_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, Ssa_Coding_CODE) Ssa_Coding_DataServices_VINDataIdentifier_WriteData(P2CONST(uint8, AUTOMATIC, RTE_SSA_CODING_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_CODING_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, Ssa_Coding_CODE) Ssa_Coding_Init(void); /* PRQA S 3451, 0786, 3449 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449 */
FUNC(Std_ReturnType, Ssa_Coding_CODE) Ssa_Coding_InitMonitorForEvent_DTC_0x164456(Dem_InitMonitorReasonType InitMonitorReason); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, Ssa_Coding_CODE) Ssa_Coding_MainFunction(void); /* PRQA S 3451, 0786, 3449 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449 */
FUNC(Std_ReturnType, Ssa_Coding_CODE) Ssa_Coding_RoutineServices_Routine_Evaluate_Data_Verification_Certificate_Start(P2CONST(uint8, AUTOMATIC, RTE_SSA_CODING_APPL_DATA) Data_Verification_Certificate, Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_SSA_CODING_APPL_VAR) routineInfo, P2VAR(uint8, AUTOMATIC, RTE_SSA_CODING_APPL_VAR) Verification_Result, uint16 DataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_CODING_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, Ssa_Coding_CODE) Ssa_Coding_RoutineServices_Routine_Reset_VIN_Values_Start(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_SSA_CODING_APPL_VAR) routineInfo, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_CODING_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, Ssa_Coding_CODE) Ssa_Coding_RoutineServices_Routine_Verify_Signature_Start(uint8 Data_to_be_checked, P2CONST(uint8, AUTOMATIC, RTE_SSA_CODING_APPL_DATA) Signature_Value, Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_SSA_CODING_APPL_VAR) routineInfo, P2VAR(uint8, AUTOMATIC, RTE_SSA_CODING_APPL_VAR) Verification_Result, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_CODING_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, Ssa_Coding_CODE) Ssa_Coding_ServiceRequestNotification_Confirmation(uint8 SID, uint8 ReqType, uint16 SourceAddress, Dcm_ConfirmationStatusType ConfirmationStatus); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, Ssa_Coding_CODE) Ssa_Coding_ServiceRequestNotification_Indication(uint8 SID, P2CONST(uint8, AUTOMATIC, RTE_SSA_CODING_APPL_DATA) RequestData, uint16 DataSize, uint8 ReqType, uint16 SourceAddress, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_CODING_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, Ssa_Coding_CODE) Ssa_Coding_VIN_Get(P2VAR(uint8, AUTOMATIC, RTE_SSA_CODING_APPL_VAR) vin); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, Ssa_Coding_CODE) Ssa_Coding_VIN_GetStoreState(P2VAR(Ssa_VinStoreStateType, AUTOMATIC, RTE_SSA_CODING_APPL_VAR) state); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, Ssa_Coding_CODE) Ssa_Coding_VIN_Lock(boolean locked); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, Ssa_Coding_CODE) Ssa_Coding_VIN_Receive(void); /* PRQA S 3451, 0786, 3449 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449 */
FUNC(void, Ssa_Coding_CODE) Ssa_Coding_VIN_Receive_Timeout(void); /* PRQA S 3451, 0786, 3449 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449 */
FUNC(Std_ReturnType, Ssa_Coding_CODE) Ssa_Coding_VIN_Set(P2CONST(uint8, AUTOMATIC, RTE_SSA_CODING_APPL_DATA) vin); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */

# define Ssa_Coding_STOP_SEC_CODE
# include "Ssa_Coding_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Application errors
 *********************************************************************************************************************/

#  define RTE_E_CallbackInitMonitorForEvent_E_NOT_OK (1U)

#  define RTE_E_CertP_Functions_E_NOT_OK (1U)

#  define RTE_E_Coding_VIN_E_NOT_OK (1U)

#  define RTE_E_Coding_VINControl_E_NOT_OK (1U)

#  define RTE_E_CsmKeyManagement_Ssa_SignatureRamKey_CSM_E_BUSY (2U)

#  define RTE_E_CsmKeyManagement_Ssa_SignatureRamKey_CSM_E_KEY_NOT_AVAILABLE (8U)

#  define RTE_E_CsmKeyManagement_Ssa_SignatureRamKey_CSM_E_KEY_SIZE_MISMATCH (10U)

#  define RTE_E_CsmKeyManagement_Ssa_SignatureRamKey_CSM_E_KEY_WRITE_FAIL (7U)

#  define RTE_E_CsmKeyManagement_Ssa_SignatureRamKey_CSM_E_SMALL_BUFFER (3U)

#  define RTE_E_CsmKeyManagement_Ssa_SignatureRamKey_E_NOT_OK (1U)

#  define RTE_E_DataServices_DID_018E_VIN_Lock_Status_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_DID_018E_VIN_Lock_Status_E_NOT_OK (1U)

#  define RTE_E_DataServices_DID_018E_VIN_Status_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_DID_018E_VIN_Status_E_NOT_OK (1U)

#  define RTE_E_DataServices_DID_0197_Precompile_switch_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_DID_0197_Precompile_switch_E_NOT_OK (1U)

#  define RTE_E_DataServices_DID_EF04_SSA_Major_Version_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_DID_EF04_SSA_Major_Version_E_NOT_OK (1U)

#  define RTE_E_DataServices_DID_EF04_SSA_Minor_Version_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_DID_EF04_SSA_Minor_Version_E_NOT_OK (1U)

#  define RTE_E_DataServices_DID_EF04_SSA_Patch_Level_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_DID_EF04_SSA_Patch_Level_E_NOT_OK (1U)

#  define RTE_E_DataServices_VINDataIdentifier_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_VINDataIdentifier_E_NOT_OK (1U)

#  define RTE_E_DiagnosticMonitor_E_NOT_OK (1U)

#  define RTE_E_KeyM_Certificate_E_NOT_OK (1U)

#  define RTE_E_KeyM_Certificate_E_PENDING (10U)

#  define RTE_E_NvMService_AC2_SRBS_E_NOT_OK (1U)

#  define RTE_E_RoutineServices_Routine_Evaluate_Data_Verification_Certificate_DCM_E_FORCE_RCRRP (12U)

#  define RTE_E_RoutineServices_Routine_Evaluate_Data_Verification_Certificate_DCM_E_PENDING (10U)

#  define RTE_E_RoutineServices_Routine_Evaluate_Data_Verification_Certificate_E_NOT_OK (1U)

#  define RTE_E_RoutineServices_Routine_Reset_VIN_Values_DCM_E_FORCE_RCRRP (12U)

#  define RTE_E_RoutineServices_Routine_Reset_VIN_Values_DCM_E_PENDING (10U)

#  define RTE_E_RoutineServices_Routine_Reset_VIN_Values_E_NOT_OK (1U)

#  define RTE_E_RoutineServices_Routine_Verify_Signature_DCM_E_FORCE_RCRRP (12U)

#  define RTE_E_RoutineServices_Routine_Verify_Signature_DCM_E_PENDING (10U)

#  define RTE_E_RoutineServices_Routine_Verify_Signature_E_NOT_OK (1U)

#  define RTE_E_SecLog_ChangeVinEvent_E_NOT_OK (1U)

#  define RTE_E_SecLog_SignatureVerificationEvent_E_NOT_OK (1U)

#  define RTE_E_ServiceRequestNotification_E_NOT_OK (1U)

#  define RTE_E_ServiceRequestNotification_E_REQUEST_NOT_ACCEPTED (8U)

#  define RTE_E_SsaCdd_CryptoInterface_E_NOT_OK (1U)
# endif /* !defined(RTE_CORE) */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* RTE_SSA_CODING_H */

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
