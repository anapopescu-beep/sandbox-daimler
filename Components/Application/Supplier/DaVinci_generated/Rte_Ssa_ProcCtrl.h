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
 *             File:  Rte_Ssa_ProcCtrl.h
 *           Config:  StartApplication.dpa
 *      ECU-Project:  StartApplication
 *
 *        Generator:  MICROSAR RTE Generator Version 4.32.0
 *                    RTE Core Version 4.32.0
 *          License:  CBD2200333
 *
 *      Description:  Application header file for SW-C <Ssa_ProcCtrl>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef RTE_SSA_PROCCTRL_H
# define RTE_SSA_PROCCTRL_H

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

# include "Rte_Ssa_ProcCtrl_Type.h"
# include "Rte_DataHandleType.h"

# include "Rte_Hook.h"

# ifndef RTE_CORE

/**********************************************************************************************************************
 * extern declaration of RTE buffers for optimized macro implementation
 *********************************************************************************************************************/
#  define RTE_START_SEC_VAR_NOINIT_UNSPECIFIED
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern VAR(uint8, RTE_VAR_NOINIT) Rte_Ssa_ProcCtrl_ProcCtrl_DispatchServices_Sender_ServiceId;

#  define RTE_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

# endif /* !defined(RTE_CORE) */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

#  define Rte_InitValue_ProcCtrl_DispatchServices_Receiver_ServiceId (0U)
#  define Rte_InitValue_ProcCtrl_DispatchServices_Sender_ServiceId (0U)
# endif


# define RTE_START_SEC_CODE
# include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Ssa_ProcCtrl_ProcCtrl_DispatchServices_Sender_ServiceId(uint8 data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */


# define RTE_STOP_SEC_CODE
# include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# ifndef RTE_CORE

/**********************************************************************************************************************
 * Rte_Read_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Read_ProcCtrl_DispatchServices_Receiver_ServiceId Rte_Read_Ssa_ProcCtrl_ProcCtrl_DispatchServices_Receiver_ServiceId
#  define Rte_Read_Ssa_ProcCtrl_ProcCtrl_DispatchServices_Receiver_ServiceId(data) (*(data) = Rte_Ssa_ProcCtrl_ProcCtrl_DispatchServices_Sender_ServiceId, ((Std_ReturnType)RTE_E_OK))


/**********************************************************************************************************************
 * Rte_Write_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Write_ProcCtrl_DispatchServices_Sender_ServiceId Rte_Write_Ssa_ProcCtrl_ProcCtrl_DispatchServices_Sender_ServiceId


/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (unmapped) for synchronous C/S communication
 *********************************************************************************************************************/
#  define RTE_START_SEC_SSA_CODING_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_SSA_CODING_APPL_CODE) Ssa_Coding_RoutineServices_Routine_Evaluate_Data_Verification_Certificate_Start(P2CONST(uint8, AUTOMATIC, RTE_SSA_CODING_APPL_DATA) Data_Verification_Certificate, Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_SSA_CODING_APPL_VAR) routineInfo, P2VAR(uint8, AUTOMATIC, RTE_SSA_CODING_APPL_VAR) Verification_Result, uint16 DataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_CODING_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_SSA_CODING_APPL_CODE) Ssa_Coding_RoutineServices_Routine_Evaluate_Data_Verification_Certificate_Start(P2CONST(Dcm_Data2002ByteType, AUTOMATIC, RTE_SSA_CODING_APPL_DATA) Data_Verification_Certificate, Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_SSA_CODING_APPL_VAR) routineInfo, P2VAR(uint8, AUTOMATIC, RTE_SSA_CODING_APPL_VAR) Verification_Result, uint16 DataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_CODING_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
FUNC(Std_ReturnType, RTE_SSA_CODING_APPL_CODE) Ssa_Coding_RoutineServices_Routine_Reset_VIN_Values_Start(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_SSA_CODING_APPL_VAR) routineInfo, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_CODING_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_SSA_CODING_APPL_CODE) Ssa_Coding_RoutineServices_Routine_Verify_Signature_Start(uint8 Data_to_be_checked, P2CONST(uint8, AUTOMATIC, RTE_SSA_CODING_APPL_DATA) Signature_Value, Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_SSA_CODING_APPL_VAR) routineInfo, P2VAR(uint8, AUTOMATIC, RTE_SSA_CODING_APPL_VAR) Verification_Result, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_CODING_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_SSA_CODING_APPL_CODE) Ssa_Coding_RoutineServices_Routine_Verify_Signature_Start(uint8 Data_to_be_checked, P2CONST(Dcm_Data64ByteType, AUTOMATIC, RTE_SSA_CODING_APPL_DATA) Signature_Value, Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_SSA_CODING_APPL_VAR) routineInfo, P2VAR(uint8, AUTOMATIC, RTE_SSA_CODING_APPL_VAR) Verification_Result, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_CODING_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif

#  define RTE_STOP_SEC_SSA_CODING_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define RTE_START_SEC_SSA_KEYM_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FUNC(Std_ReturnType, RTE_SSA_KEYM_APPL_CODE) Ssa_KeyM_DataServices_DID_018F_Secured_PDU_Data_IDs_and_Key_CMACs_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_SSA_KEYM_APPL_CODE) Ssa_KeyM_DataServices_DID_018F_Secured_PDU_Data_IDs_and_Key_CMACs_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_SSA_KEYM_APPL_CODE) Ssa_KeyM_DataServices_DID_018F_Secured_PDU_Data_IDs_and_Key_CMACs_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data4092ByteType, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
FUNC(Std_ReturnType, RTE_SSA_KEYM_APPL_CODE) Ssa_KeyM_DataServices_DID_018F_Secured_PDU_Data_IDs_and_Key_CMACs_ReadDataLength(Dcm_OpStatusType OpStatus, P2VAR(uint16, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) DataLength); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_SSA_KEYM_APPL_CODE) Ssa_KeyM_DataServices_DID_0191_Generated_Random_Number_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_SSA_KEYM_APPL_CODE) Ssa_KeyM_DataServices_DID_0191_Generated_Random_Number_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_SSA_KEYM_APPL_CODE) Ssa_KeyM_DataServices_DID_0191_Generated_Random_Number_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data32ByteType, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
FUNC(Std_ReturnType, RTE_SSA_KEYM_APPL_CODE) Ssa_KeyM_DataServices_DID_0191_Generated_Random_Number_Result_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_SSA_KEYM_APPL_CODE) Ssa_KeyM_DataServices_DID_0191_Generated_Random_Number_Result_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_SSA_KEYM_APPL_CODE) Ssa_KeyM_DataServices_DID_0191_Generated_Random_Number_Result_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data1ByteType, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
FUNC(Std_ReturnType, RTE_SSA_KEYM_APPL_CODE) Ssa_KeyM_DataServices_DID_0199_Certificates_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_SSA_KEYM_APPL_CODE) Ssa_KeyM_DataServices_DID_0199_Certificates_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_SSA_KEYM_APPL_CODE) Ssa_KeyM_DataServices_DID_0199_Certificates_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data3006ByteType, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
FUNC(Std_ReturnType, RTE_SSA_KEYM_APPL_CODE) Ssa_KeyM_DataServices_DID_0199_Certificates_ReadDataLength(Dcm_OpStatusType OpStatus, P2VAR(uint16, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) DataLength); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_SSA_KEYM_APPL_CODE) Ssa_KeyM_DataServices_DID_0199_Data_Signature_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_SSA_KEYM_APPL_CODE) Ssa_KeyM_DataServices_DID_0199_Data_Signature_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_SSA_KEYM_APPL_CODE) Ssa_KeyM_DataServices_DID_0199_Data_Signature_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data64ByteType, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
FUNC(Std_ReturnType, RTE_SSA_KEYM_APPL_CODE) Ssa_KeyM_DataServices_DID_0199_Ephemeral_ECU_Public_Key_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_SSA_KEYM_APPL_CODE) Ssa_KeyM_DataServices_DID_0199_Ephemeral_ECU_Public_Key_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_SSA_KEYM_APPL_CODE) Ssa_KeyM_DataServices_DID_0199_Ephemeral_ECU_Public_Key_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data32ByteType, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
FUNC(Std_ReturnType, RTE_SSA_KEYM_APPL_CODE) Ssa_KeyM_DataServices_DID_0199_Nonce_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_SSA_KEYM_APPL_CODE) Ssa_KeyM_DataServices_DID_0199_Nonce_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_SSA_KEYM_APPL_CODE) Ssa_KeyM_DataServices_DID_0199_Nonce_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data32ByteType, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
FUNC(Std_ReturnType, RTE_SSA_KEYM_APPL_CODE) Ssa_KeyM_DataServices_DID_019A_Trust_model_ECU_CSR_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_SSA_KEYM_APPL_CODE) Ssa_KeyM_DataServices_DID_019A_Trust_model_ECU_CSR_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_SSA_KEYM_APPL_CODE) Ssa_KeyM_DataServices_DID_019A_Trust_model_ECU_CSR_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data1002ByteType, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
FUNC(Std_ReturnType, RTE_SSA_KEYM_APPL_CODE) Ssa_KeyM_DataServices_DID_019A_Trust_model_ECU_CSR_ReadDataLength(Dcm_OpStatusType OpStatus, P2VAR(uint16, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) DataLength); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_SSA_KEYM_APPL_CODE) Ssa_KeyM_DataServices_DID_019B_Trust_model_ECU_Certificate_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_SSA_KEYM_APPL_CODE) Ssa_KeyM_DataServices_DID_019B_Trust_model_ECU_Certificate_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_SSA_KEYM_APPL_CODE) Ssa_KeyM_DataServices_DID_019B_Trust_model_ECU_Certificate_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data1002ByteType, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
FUNC(Std_ReturnType, RTE_SSA_KEYM_APPL_CODE) Ssa_KeyM_DataServices_DID_019B_Trust_model_ECU_Certificate_ReadDataLength(Dcm_OpStatusType OpStatus, P2VAR(uint16, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) DataLength); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_SSA_KEYM_APPL_CODE) Ssa_KeyM_DataServices_DID_019C_Trust_model_Intermediate_CA_Certificate_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_SSA_KEYM_APPL_CODE) Ssa_KeyM_DataServices_DID_019C_Trust_model_Intermediate_CA_Certificate_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_SSA_KEYM_APPL_CODE) Ssa_KeyM_DataServices_DID_019C_Trust_model_Intermediate_CA_Certificate_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data1002ByteType, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
FUNC(Std_ReturnType, RTE_SSA_KEYM_APPL_CODE) Ssa_KeyM_DataServices_DID_019C_Trust_model_Intermediate_CA_Certificate_ReadDataLength(Dcm_OpStatusType OpStatus, P2VAR(uint16, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) DataLength); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_SSA_KEYM_APPL_CODE) Ssa_KeyM_DataServices_DID_019D_Trust_model_Backend_CA_certificate_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_SSA_KEYM_APPL_CODE) Ssa_KeyM_DataServices_DID_019D_Trust_model_Backend_CA_certificate_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_SSA_KEYM_APPL_CODE) Ssa_KeyM_DataServices_DID_019D_Trust_model_Backend_CA_certificate_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data1002ByteType, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
FUNC(Std_ReturnType, RTE_SSA_KEYM_APPL_CODE) Ssa_KeyM_DataServices_DID_019D_Trust_model_Backend_CA_certificate_ReadDataLength(Dcm_OpStatusType OpStatus, P2VAR(uint16, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) DataLength); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_SSA_KEYM_APPL_CODE) Ssa_KeyM_DataServices_DID_019E_Trust_model_Root_CA_certificate_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_SSA_KEYM_APPL_CODE) Ssa_KeyM_DataServices_DID_019E_Trust_model_Root_CA_certificate_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_SSA_KEYM_APPL_CODE) Ssa_KeyM_DataServices_DID_019E_Trust_model_Root_CA_certificate_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data1002ByteType, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
FUNC(Std_ReturnType, RTE_SSA_KEYM_APPL_CODE) Ssa_KeyM_DataServices_DID_019E_Trust_model_Root_CA_certificate_ReadDataLength(Dcm_OpStatusType OpStatus, P2VAR(uint16, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) DataLength); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_SSA_KEYM_APPL_CODE) Ssa_KeyM_DataServices_DID_019F_Trust_model_certificates_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_SSA_KEYM_APPL_CODE) Ssa_KeyM_DataServices_DID_019F_Trust_model_certificates_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_SSA_KEYM_APPL_CODE) Ssa_KeyM_DataServices_DID_019F_Trust_model_certificates_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data4008ByteType, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
FUNC(Std_ReturnType, RTE_SSA_KEYM_APPL_CODE) Ssa_KeyM_DataServices_DID_019F_Trust_model_certificates_ReadDataLength(Dcm_OpStatusType OpStatus, P2VAR(uint16, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) DataLength); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_SSA_KEYM_APPL_CODE) Ssa_KeyM_RoutineServices_Routine_Certificate_Self_Check(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) routineInfo, P2VAR(uint8, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) Verification_Result, P2VAR(uint16, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) DataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_SSA_KEYM_APPL_CODE) Ssa_KeyM_RoutineServices_Routine_Certificate_Self_Check(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) routineInfo, P2VAR(Dcm_Data18ByteType, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) Verification_Result, P2VAR(uint16, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) DataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_SSA_KEYM_APPL_CODE) Ssa_KeyM_RoutineServices_Inject_Seed(P2CONST(uint8, AUTOMATIC, RTE_SSA_KEYM_APPL_DATA) Ephemeral_Backend_Public_Key_In, P2CONST(uint8, AUTOMATIC, RTE_SSA_KEYM_APPL_DATA) Data_Signature_In, P2CONST(uint8, AUTOMATIC, RTE_SSA_KEYM_APPL_DATA) Encrypted_Seed_In, Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) routineInfo_Out, P2VAR(uint8, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) Verification_Result_Out, uint16 DataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_SSA_KEYM_APPL_CODE) Ssa_KeyM_RoutineServices_Inject_Seed(P2CONST(Dcm_Data32ByteType, AUTOMATIC, RTE_SSA_KEYM_APPL_DATA) Ephemeral_Backend_Public_Key_In, P2CONST(Dcm_Data64ByteType, AUTOMATIC, RTE_SSA_KEYM_APPL_DATA) Data_Signature_In, P2CONST(Dcm_Data1058ByteType, AUTOMATIC, RTE_SSA_KEYM_APPL_DATA) Encrypted_Seed_In, Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) routineInfo_Out, P2VAR(uint8, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) Verification_Result_Out, uint16 DataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_SSA_KEYM_APPL_CODE) Ssa_KeyM_RoutineServices_Replace_Certificates(P2CONST(uint8, AUTOMATIC, RTE_SSA_KEYM_APPL_DATA) Certificates, Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) routineInfo, P2VAR(uint8, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) Verification_Result, uint16 DataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_SSA_KEYM_APPL_CODE) Ssa_KeyM_RoutineServices_Replace_Certificates(P2CONST(Dcm_Data4008ByteType, AUTOMATIC, RTE_SSA_KEYM_APPL_DATA) Certificates, Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) routineInfo, P2VAR(uint8, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) Verification_Result, uint16 DataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_SSA_KEYM_APPL_CODE) Ssa_KeyM_RoutineServices_Replace_Trust_model_Certificates(P2CONST(uint8, AUTOMATIC, RTE_SSA_KEYM_APPL_DATA) Trust_Certificates_In, Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) routineInfo_Out, P2VAR(uint8, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) Verification_Result_Out, uint16 DataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_SSA_KEYM_APPL_CODE) Ssa_KeyM_RoutineServices_Replace_Trust_model_Certificates(P2CONST(Dcm_Data3006ByteType, AUTOMATIC, RTE_SSA_KEYM_APPL_DATA) Trust_Certificates_In, Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) routineInfo_Out, P2VAR(uint8, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) Verification_Result_Out, uint16 DataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_SSA_KEYM_APPL_CODE) Ssa_KeyM_RoutineServices_Replace_Trust_model_Root_Certificate(P2CONST(uint8, AUTOMATIC, RTE_SSA_KEYM_APPL_DATA) signature_new_Root_In, P2CONST(uint8, AUTOMATIC, RTE_SSA_KEYM_APPL_DATA) signature_In, P2CONST(uint8, AUTOMATIC, RTE_SSA_KEYM_APPL_DATA) Certificates_In, Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) routineInfo_Out, P2VAR(uint8, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) Verification_Result_Out, uint16 DataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_SSA_KEYM_APPL_CODE) Ssa_KeyM_RoutineServices_Replace_Trust_model_Root_Certificate(P2CONST(Dcm_Data64ByteType, AUTOMATIC, RTE_SSA_KEYM_APPL_DATA) signature_new_Root_In, P2CONST(Dcm_Data64ByteType, AUTOMATIC, RTE_SSA_KEYM_APPL_DATA) signature_In, P2CONST(Dcm_Data2004ByteType, AUTOMATIC, RTE_SSA_KEYM_APPL_DATA) Certificates_In, Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) routineInfo_Out, P2VAR(uint8, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) Verification_Result_Out, uint16 DataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_SSA_KEYM_APPL_CODE) Ssa_KeyM_RoutineServices_Trust_Model_Generate_Key_Pair(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) routineInfo_Out, P2VAR(uint8, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) Verification_Result_Out, P2VAR(uint8, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) CSR_Signature_Out, P2VAR(uint8, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) Trust_Model_ECU_CSR_Out, P2VAR(uint16, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) DataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_SSA_KEYM_APPL_CODE) Ssa_KeyM_RoutineServices_Trust_Model_Generate_Key_Pair(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) routineInfo_Out, P2VAR(uint8, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) Verification_Result_Out, P2VAR(Dcm_Data64ByteType, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) CSR_Signature_Out, P2VAR(Dcm_Data1002ByteType, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) Trust_Model_ECU_CSR_Out, P2VAR(uint16, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) DataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_SSA_KEYM_APPL_CODE) Ssa_KeyM_RoutineServices_Trust_Model_SecOC_ECU_Shared_Secret_Distribution(P2CONST(uint8, AUTOMATIC, RTE_SSA_KEYM_APPL_DATA) Date_and_Time_In, P2CONST(uint8, AUTOMATIC, RTE_SSA_KEYM_APPL_DATA) Tick_Count_In, P2CONST(uint8, AUTOMATIC, RTE_SSA_KEYM_APPL_DATA) Tick_Count_Offset_In, P2CONST(uint8, AUTOMATIC, RTE_SSA_KEYM_APPL_DATA) Encrypted_Nonce_and_Shared_Secret_In, P2CONST(uint8, AUTOMATIC, RTE_SSA_KEYM_APPL_DATA) Ephemeral_VSM_Public_Key_In, P2CONST(uint8, AUTOMATIC, RTE_SSA_KEYM_APPL_DATA) Data_Signature_In, P2CONST(uint8, AUTOMATIC, RTE_SSA_KEYM_APPL_DATA) Certificates_In, Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) routineInfo_Out, P2VAR(uint8, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) Verification_Result_Out, uint16 DataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_SSA_KEYM_APPL_CODE) Ssa_KeyM_RoutineServices_Trust_Model_SecOC_ECU_Shared_Secret_Distribution(P2CONST(Dcm_Data7ByteType, AUTOMATIC, RTE_SSA_KEYM_APPL_DATA) Date_and_Time_In, P2CONST(Dcm_Data5ByteType, AUTOMATIC, RTE_SSA_KEYM_APPL_DATA) Tick_Count_In, P2CONST(Dcm_Data5ByteType, AUTOMATIC, RTE_SSA_KEYM_APPL_DATA) Tick_Count_Offset_In, P2CONST(Dcm_Data80ByteType, AUTOMATIC, RTE_SSA_KEYM_APPL_DATA) Encrypted_Nonce_and_Shared_Secret_In, P2CONST(Dcm_Data32ByteType, AUTOMATIC, RTE_SSA_KEYM_APPL_DATA) Ephemeral_VSM_Public_Key_In, P2CONST(Dcm_Data64ByteType, AUTOMATIC, RTE_SSA_KEYM_APPL_DATA) Data_Signature_In, P2CONST(Dcm_Data3006ByteType, AUTOMATIC, RTE_SSA_KEYM_APPL_DATA) Certificates_In, Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) routineInfo_Out, P2VAR(uint8, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) Verification_Result_Out, uint16 DataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif

#  define RTE_STOP_SEC_SSA_KEYM_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define RTE_START_SEC_SSA_RIGHTSM_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_SSA_RIGHTSM_APPL_CODE) Ssa_RightsM_RoutineServices_Routine_Authenticate_Diagnostic_User_or_Tester_Start(uint8 Configuration, uint8 Task, P2CONST(uint8, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_DATA) Challenge_Certificate_Proof_of_Ownership, Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_VAR) routineInfo, P2VAR(uint8, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_VAR) Verification_Result, P2VAR(uint8, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_VAR) Authentication_Result, P2VAR(uint16, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_VAR) DataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_SSA_RIGHTSM_APPL_CODE) Ssa_RightsM_RoutineServices_Routine_Authenticate_Diagnostic_User_or_Tester_Start(uint8 Configuration, uint8 Task, P2CONST(Dcm_Data4004ByteType, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_DATA) Challenge_Certificate_Proof_of_Ownership, Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_VAR) routineInfo, P2VAR(uint8, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_VAR) Verification_Result, P2VAR(Dcm_Data3006ByteType, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_VAR) Authentication_Result, P2VAR(uint16, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_VAR) DataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_SSA_RIGHTSM_APPL_CODE) Ssa_RightsM_RoutineServices_Routine_Enhance_Access_Rights_Start(P2CONST(uint8, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_DATA) Enhanced_Rights_Certificate, Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_VAR) routineInfo, P2VAR(uint8, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_VAR) Verification_Result, uint16 DataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_SSA_RIGHTSM_APPL_CODE) Ssa_RightsM_RoutineServices_Routine_Enhance_Access_Rights_Start(P2CONST(Dcm_Data2002ByteType, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_DATA) Enhanced_Rights_Certificate, Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_VAR) routineInfo, P2VAR(uint8, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_VAR) Verification_Result, uint16 DataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_SSA_RIGHTSM_APPL_CODE) Ssa_RightsM_RoutineServices_Routine_Synchronize_Secured_System_Date_and_Time_Start(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_VAR) routineInfo, P2VAR(uint8, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_VAR) Nonce, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_SSA_RIGHTSM_APPL_CODE) Ssa_RightsM_RoutineServices_Routine_Synchronize_Secured_System_Date_and_Time_Start(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_VAR) routineInfo, P2VAR(Dcm_Data32ByteType, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_VAR) Nonce, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_SSA_RIGHTSM_APPL_CODE) Ssa_RightsM_SecurityAccess_CompareKey(uint8 secLevel, P2CONST(uint8, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_DATA) key, Dcm_OpStatusType opStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_VAR) errorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_SSA_RIGHTSM_APPL_CODE) Ssa_RightsM_SecurityAccess_CompareKey(uint8 secLevel, P2CONST(Dcm_Data64ByteType, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_DATA) key, Dcm_OpStatusType opStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_VAR) errorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_SSA_RIGHTSM_APPL_CODE) Ssa_RightsM_SecurityAccess_GetSeed(uint8 secLevel, Dcm_OpStatusType opStatus, P2VAR(uint8, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_VAR) seed, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_VAR) errorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_SSA_RIGHTSM_APPL_CODE) Ssa_RightsM_SecurityAccess_GetSeed(uint8 secLevel, Dcm_OpStatusType opStatus, P2VAR(Dcm_Data32ByteType, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_VAR) seed, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_VAR) errorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif

#  define RTE_STOP_SEC_SSA_RIGHTSM_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define RTE_START_SEC_SSA_SECLOG_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FUNC(Std_ReturnType, RTE_SSA_SECLOG_APPL_CODE) Ssa_SecLog_DataServices_Security_Event_Log_Current_Counter_Values_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_SECLOG_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_SSA_SECLOG_APPL_CODE) Ssa_SecLog_DataServices_Security_Event_Log_Current_Counter_Values_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_SSA_SECLOG_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_SSA_SECLOG_APPL_CODE) Ssa_SecLog_DataServices_Security_Event_Log_Current_Counter_Values_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data1024ByteType, AUTOMATIC, RTE_SSA_SECLOG_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
FUNC(Std_ReturnType, RTE_SSA_SECLOG_APPL_CODE) Ssa_SecLog_DataServices_Security_Event_Log_Current_Counter_Values_ReadDataLength(Dcm_OpStatusType OpStatus, P2VAR(uint16, AUTOMATIC, RTE_SSA_SECLOG_APPL_VAR) DataLength); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_SSA_SECLOG_APPL_CODE) Ssa_SecLog_DataServices_Security_Event_Log_Read_Security_Event_Log_Entry_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_SECLOG_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_SSA_SECLOG_APPL_CODE) Ssa_SecLog_DataServices_Security_Event_Log_Read_Security_Event_Log_Entry_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_SSA_SECLOG_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_SSA_SECLOG_APPL_CODE) Ssa_SecLog_DataServices_Security_Event_Log_Read_Security_Event_Log_Entry_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data4092ByteType, AUTOMATIC, RTE_SSA_SECLOG_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
FUNC(Std_ReturnType, RTE_SSA_SECLOG_APPL_CODE) Ssa_SecLog_DataServices_Security_Event_Log_Read_Security_Event_Log_Entry_ReadDataLength(Dcm_OpStatusType OpStatus, P2VAR(uint16, AUTOMATIC, RTE_SSA_SECLOG_APPL_VAR) DataLength); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */

#  define RTE_STOP_SEC_SSA_SECLOG_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define Rte_Call_DS_DID_018F_Secured_PDU_Data_IDs_and_Key_CMACs_ConditionCheckRead Ssa_KeyM_DataServices_DID_018F_Secured_PDU_Data_IDs_and_Key_CMACs_ConditionCheckRead
#  define Rte_Call_DS_DID_018F_Secured_PDU_Data_IDs_and_Key_CMACs_ReadData Ssa_KeyM_DataServices_DID_018F_Secured_PDU_Data_IDs_and_Key_CMACs_ReadData
#  define Rte_Call_DS_DID_018F_Secured_PDU_Data_IDs_and_Key_CMACs_ReadDataLength Ssa_KeyM_DataServices_DID_018F_Secured_PDU_Data_IDs_and_Key_CMACs_ReadDataLength
#  define Rte_Call_DS_DID_0191_Generated_Random_Number_ConditionCheckRead Ssa_KeyM_DataServices_DID_0191_Generated_Random_Number_ConditionCheckRead
#  define Rte_Call_DS_DID_0191_Generated_Random_Number_ReadData Ssa_KeyM_DataServices_DID_0191_Generated_Random_Number_ReadData
#  define Rte_Call_DS_DID_0191_Generated_Random_Number_Result_ConditionCheckRead Ssa_KeyM_DataServices_DID_0191_Generated_Random_Number_Result_ConditionCheckRead
#  define Rte_Call_DS_DID_0191_Generated_Random_Number_Result_ReadData Ssa_KeyM_DataServices_DID_0191_Generated_Random_Number_Result_ReadData
#  define Rte_Call_DS_DID_0199_Certificates_ConditionCheckRead Ssa_KeyM_DataServices_DID_0199_Certificates_ConditionCheckRead
#  define Rte_Call_DS_DID_0199_Certificates_ReadData Ssa_KeyM_DataServices_DID_0199_Certificates_ReadData
#  define Rte_Call_DS_DID_0199_Certificates_ReadDataLength Ssa_KeyM_DataServices_DID_0199_Certificates_ReadDataLength
#  define Rte_Call_DS_DID_0199_Data_Signature_ConditionCheckRead Ssa_KeyM_DataServices_DID_0199_Data_Signature_ConditionCheckRead
#  define Rte_Call_DS_DID_0199_Data_Signature_ReadData Ssa_KeyM_DataServices_DID_0199_Data_Signature_ReadData
#  define Rte_Call_DS_DID_0199_Ephemeral_ECU_Public_Key_ConditionCheckRead Ssa_KeyM_DataServices_DID_0199_Ephemeral_ECU_Public_Key_ConditionCheckRead
#  define Rte_Call_DS_DID_0199_Ephemeral_ECU_Public_Key_ReadData Ssa_KeyM_DataServices_DID_0199_Ephemeral_ECU_Public_Key_ReadData
#  define Rte_Call_DS_DID_0199_Nonce_ConditionCheckRead Ssa_KeyM_DataServices_DID_0199_Nonce_ConditionCheckRead
#  define Rte_Call_DS_DID_0199_Nonce_ReadData Ssa_KeyM_DataServices_DID_0199_Nonce_ReadData
#  define Rte_Call_DS_DID_019A_Trust_model_ECU_CSR_ConditionCheckRead Ssa_KeyM_DataServices_DID_019A_Trust_model_ECU_CSR_ConditionCheckRead
#  define Rte_Call_DS_DID_019A_Trust_model_ECU_CSR_ReadData Ssa_KeyM_DataServices_DID_019A_Trust_model_ECU_CSR_ReadData
#  define Rte_Call_DS_DID_019A_Trust_model_ECU_CSR_ReadDataLength Ssa_KeyM_DataServices_DID_019A_Trust_model_ECU_CSR_ReadDataLength
#  define Rte_Call_DS_DID_019B_Trust_model_ECU_Certificate_ConditionCheckRead Ssa_KeyM_DataServices_DID_019B_Trust_model_ECU_Certificate_ConditionCheckRead
#  define Rte_Call_DS_DID_019B_Trust_model_ECU_Certificate_ReadData Ssa_KeyM_DataServices_DID_019B_Trust_model_ECU_Certificate_ReadData
#  define Rte_Call_DS_DID_019B_Trust_model_ECU_Certificate_ReadDataLength Ssa_KeyM_DataServices_DID_019B_Trust_model_ECU_Certificate_ReadDataLength
#  define Rte_Call_DS_DID_019C_Trust_model_Intermediate_CA_Certificate_ConditionCheckRead Ssa_KeyM_DataServices_DID_019C_Trust_model_Intermediate_CA_Certificate_ConditionCheckRead
#  define Rte_Call_DS_DID_019C_Trust_model_Intermediate_CA_Certificate_ReadData Ssa_KeyM_DataServices_DID_019C_Trust_model_Intermediate_CA_Certificate_ReadData
#  define Rte_Call_DS_DID_019C_Trust_model_Intermediate_CA_Certificate_ReadDataLength Ssa_KeyM_DataServices_DID_019C_Trust_model_Intermediate_CA_Certificate_ReadDataLength
#  define Rte_Call_DS_DID_019D_Trust_model_Backend_CA_certificate_ConditionCheckRead Ssa_KeyM_DataServices_DID_019D_Trust_model_Backend_CA_certificate_ConditionCheckRead
#  define Rte_Call_DS_DID_019D_Trust_model_Backend_CA_certificate_ReadData Ssa_KeyM_DataServices_DID_019D_Trust_model_Backend_CA_certificate_ReadData
#  define Rte_Call_DS_DID_019D_Trust_model_Backend_CA_certificate_ReadDataLength Ssa_KeyM_DataServices_DID_019D_Trust_model_Backend_CA_certificate_ReadDataLength
#  define Rte_Call_DS_DID_019E_Trust_model_Root_CA_certificate_ConditionCheckRead Ssa_KeyM_DataServices_DID_019E_Trust_model_Root_CA_certificate_ConditionCheckRead
#  define Rte_Call_DS_DID_019E_Trust_model_Root_CA_certificate_ReadData Ssa_KeyM_DataServices_DID_019E_Trust_model_Root_CA_certificate_ReadData
#  define Rte_Call_DS_DID_019E_Trust_model_Root_CA_certificate_ReadDataLength Ssa_KeyM_DataServices_DID_019E_Trust_model_Root_CA_certificate_ReadDataLength
#  define Rte_Call_DS_DID_019F_Trust_model_certificates_ConditionCheckRead Ssa_KeyM_DataServices_DID_019F_Trust_model_certificates_ConditionCheckRead
#  define Rte_Call_DS_DID_019F_Trust_model_certificates_ReadData Ssa_KeyM_DataServices_DID_019F_Trust_model_certificates_ReadData
#  define Rte_Call_DS_DID_019F_Trust_model_certificates_ReadDataLength Ssa_KeyM_DataServices_DID_019F_Trust_model_certificates_ReadDataLength
#  define Rte_Call_DS_Security_Event_Log_Current_Counter_Values_Read_Security_Event_Log_Current_Counter_Values_ConditionCheckRead Ssa_SecLog_DataServices_Security_Event_Log_Current_Counter_Values_ConditionCheckRead
#  define Rte_Call_DS_Security_Event_Log_Current_Counter_Values_Read_Security_Event_Log_Current_Counter_Values_ReadData Ssa_SecLog_DataServices_Security_Event_Log_Current_Counter_Values_ReadData
#  define Rte_Call_DS_Security_Event_Log_Current_Counter_Values_Read_Security_Event_Log_Current_Counter_Values_ReadDataLength Ssa_SecLog_DataServices_Security_Event_Log_Current_Counter_Values_ReadDataLength
#  define Rte_Call_DS_Security_Event_Log_Read_Security_Event_Log_Entry_ConditionCheckRead Ssa_SecLog_DataServices_Security_Event_Log_Read_Security_Event_Log_Entry_ConditionCheckRead
#  define Rte_Call_DS_Security_Event_Log_Read_Security_Event_Log_Entry_ReadData Ssa_SecLog_DataServices_Security_Event_Log_Read_Security_Event_Log_Entry_ReadData
#  define Rte_Call_DS_Security_Event_Log_Read_Security_Event_Log_Entry_ReadDataLength Ssa_SecLog_DataServices_Security_Event_Log_Read_Security_Event_Log_Entry_ReadDataLength
#  define Rte_Call_RC_Authenticate_Diagnostic_User_or_Tester_Start Ssa_RightsM_RoutineServices_Routine_Authenticate_Diagnostic_User_or_Tester_Start
#  define Rte_Call_RC_Certificate_Self_Check_Start Ssa_KeyM_RoutineServices_Routine_Certificate_Self_Check
#  define Rte_Call_RC_Enhance_Access_Rights_Start Ssa_RightsM_RoutineServices_Routine_Enhance_Access_Rights_Start
#  define Rte_Call_RC_Evaluate_Data_Verification_Certificate_Start Ssa_Coding_RoutineServices_Routine_Evaluate_Data_Verification_Certificate_Start
#  define Rte_Call_RC_Inject_Seed_Start Ssa_KeyM_RoutineServices_Inject_Seed
#  define Rte_Call_RC_Replace_Certificates_Start Ssa_KeyM_RoutineServices_Replace_Certificates
#  define Rte_Call_RC_Replace_Trust_model_Certificates_Start Ssa_KeyM_RoutineServices_Replace_Trust_model_Certificates
#  define Rte_Call_RC_Replace_Trust_model_Root_Certificate_Start Ssa_KeyM_RoutineServices_Replace_Trust_model_Root_Certificate
#  define Rte_Call_RC_Reset_VIN_Values_Start Ssa_Coding_RoutineServices_Routine_Reset_VIN_Values_Start
#  define Rte_Call_RC_Synchronize_Secured_System_Date_and_Time_Start Ssa_RightsM_RoutineServices_Routine_Synchronize_Secured_System_Date_and_Time_Start
#  define Rte_Call_RC_Trust_Model_Generate_Key_Pair_Start Ssa_KeyM_RoutineServices_Trust_Model_Generate_Key_Pair
#  define Rte_Call_RC_Trust_Model_SecOC_ECU_Shared_Secret_Distribution_Start Ssa_KeyM_RoutineServices_Trust_Model_SecOC_ECU_Shared_Secret_Distribution
#  define Rte_Call_RC_Verify_Signature_Start Ssa_Coding_RoutineServices_Routine_Verify_Signature_Start
#  define Rte_Call_SecurityAccess_Client_CompareKey Ssa_RightsM_SecurityAccess_CompareKey
#  define Rte_Call_SecurityAccess_Client_GetSeed Ssa_RightsM_SecurityAccess_GetSeed

/**********************************************************************************************************************
 * Exclusive Areas
 *********************************************************************************************************************/

#  define Rte_Enter_Ssa_ProcCtrl_ExclusiveArea() SuspendAllInterrupts() /* RteAnalyzer(ExclusiveArea, ALL_INTERRUPT_BLOCKING) */

#  define Rte_Exit_Ssa_ProcCtrl_ExclusiveArea() ResumeAllInterrupts()  /* RteAnalyzer(ExclusiveArea, ALL_INTERRUPT_BLOCKING) */


# endif /* !defined(RTE_CORE) */


# define Ssa_ProcCtrl_START_SEC_CODE
# include "Ssa_ProcCtrl_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

# ifndef RTE_CORE
#  define RTE_RUNNABLE_Ssa_ProcCtrl_DataServices_DID_018F_Secured_PDU_Data_IDs_and_Key_CMACs_ConditionCheckRead Ssa_ProcCtrl_DataServices_DID_018F_Secured_PDU_Data_IDs_and_Key_CMACs_ConditionCheckRead
#  define RTE_RUNNABLE_Ssa_ProcCtrl_DataServices_DID_018F_Secured_PDU_Data_IDs_and_Key_CMACs_ReadData Ssa_ProcCtrl_DataServices_DID_018F_Secured_PDU_Data_IDs_and_Key_CMACs_ReadData
#  define RTE_RUNNABLE_Ssa_ProcCtrl_DataServices_DID_018F_Secured_PDU_Data_IDs_and_Key_CMACs_ReadDataLength Ssa_ProcCtrl_DataServices_DID_018F_Secured_PDU_Data_IDs_and_Key_CMACs_ReadDataLength
#  define RTE_RUNNABLE_Ssa_ProcCtrl_DataServices_DID_0191_Generated_Random_Number_ConditionCheckRead Ssa_ProcCtrl_DataServices_DID_0191_Generated_Random_Number_ConditionCheckRead
#  define RTE_RUNNABLE_Ssa_ProcCtrl_DataServices_DID_0191_Generated_Random_Number_ReadData Ssa_ProcCtrl_DataServices_DID_0191_Generated_Random_Number_ReadData
#  define RTE_RUNNABLE_Ssa_ProcCtrl_DataServices_DID_0191_Generated_Random_Number_Result_ConditionCheckRead Ssa_ProcCtrl_DataServices_DID_0191_Generated_Random_Number_Result_ConditionCheckRead
#  define RTE_RUNNABLE_Ssa_ProcCtrl_DataServices_DID_0191_Generated_Random_Number_Result_ReadData Ssa_ProcCtrl_DataServices_DID_0191_Generated_Random_Number_Result_ReadData
#  define RTE_RUNNABLE_Ssa_ProcCtrl_DataServices_DID_0199_Certificates_ConditionCheckRead Ssa_ProcCtrl_DataServices_DID_0199_Certificates_ConditionCheckRead
#  define RTE_RUNNABLE_Ssa_ProcCtrl_DataServices_DID_0199_Certificates_ReadData Ssa_ProcCtrl_DataServices_DID_0199_Certificates_ReadData
#  define RTE_RUNNABLE_Ssa_ProcCtrl_DataServices_DID_0199_Certificates_ReadDataLength Ssa_ProcCtrl_DataServices_DID_0199_Certificates_ReadDataLength
#  define RTE_RUNNABLE_Ssa_ProcCtrl_DataServices_DID_0199_Data_Signature_ConditionCheckRead Ssa_ProcCtrl_DataServices_DID_0199_Data_Signature_ConditionCheckRead
#  define RTE_RUNNABLE_Ssa_ProcCtrl_DataServices_DID_0199_Data_Signature_ReadData Ssa_ProcCtrl_DataServices_DID_0199_Data_Signature_ReadData
#  define RTE_RUNNABLE_Ssa_ProcCtrl_DataServices_DID_0199_Ephemeral_ECU_Public_Key_ConditionCheckRead Ssa_ProcCtrl_DataServices_DID_0199_Ephemeral_ECU_Public_Key_ConditionCheckRead
#  define RTE_RUNNABLE_Ssa_ProcCtrl_DataServices_DID_0199_Ephemeral_ECU_Public_Key_ReadData Ssa_ProcCtrl_DataServices_DID_0199_Ephemeral_ECU_Public_Key_ReadData
#  define RTE_RUNNABLE_Ssa_ProcCtrl_DataServices_DID_0199_Nonce_ConditionCheckRead Ssa_ProcCtrl_DataServices_DID_0199_Nonce_ConditionCheckRead
#  define RTE_RUNNABLE_Ssa_ProcCtrl_DataServices_DID_0199_Nonce_ReadData Ssa_ProcCtrl_DataServices_DID_0199_Nonce_ReadData
#  define RTE_RUNNABLE_Ssa_ProcCtrl_DataServices_DID_019A_Trust_model_ECU_CSR_ConditionCheckRead Ssa_ProcCtrl_DataServices_DID_019A_Trust_model_ECU_CSR_ConditionCheckRead
#  define RTE_RUNNABLE_Ssa_ProcCtrl_DataServices_DID_019A_Trust_model_ECU_CSR_ReadData Ssa_ProcCtrl_DataServices_DID_019A_Trust_model_ECU_CSR_ReadData
#  define RTE_RUNNABLE_Ssa_ProcCtrl_DataServices_DID_019A_Trust_model_ECU_CSR_ReadDataLength Ssa_ProcCtrl_DataServices_DID_019A_Trust_model_ECU_CSR_ReadDataLength
#  define RTE_RUNNABLE_Ssa_ProcCtrl_DataServices_DID_019B_Trust_model_ECU_Certificate_ConditionCheckRead Ssa_ProcCtrl_DataServices_DID_019B_Trust_model_ECU_Certificate_ConditionCheckRead
#  define RTE_RUNNABLE_Ssa_ProcCtrl_DataServices_DID_019B_Trust_model_ECU_Certificate_ReadData Ssa_ProcCtrl_DataServices_DID_019B_Trust_model_ECU_Certificate_ReadData
#  define RTE_RUNNABLE_Ssa_ProcCtrl_DataServices_DID_019B_Trust_model_ECU_Certificate_ReadDataLength Ssa_ProcCtrl_DataServices_DID_019B_Trust_model_ECU_Certificate_ReadDataLength
#  define RTE_RUNNABLE_Ssa_ProcCtrl_DataServices_DID_019C_Trust_model_Intermediate_CA_Certificate_ConditionCheckRead Ssa_ProcCtrl_DataServices_DID_019C_Trust_model_Intermediate_CA_Certificate_ConditionCheckRead
#  define RTE_RUNNABLE_Ssa_ProcCtrl_DataServices_DID_019C_Trust_model_Intermediate_CA_Certificate_ReadData Ssa_ProcCtrl_DataServices_DID_019C_Trust_model_Intermediate_CA_Certificate_ReadData
#  define RTE_RUNNABLE_Ssa_ProcCtrl_DataServices_DID_019C_Trust_model_Intermediate_CA_Certificate_ReadDataLength Ssa_ProcCtrl_DataServices_DID_019C_Trust_model_Intermediate_CA_Certificate_ReadDataLength
#  define RTE_RUNNABLE_Ssa_ProcCtrl_DataServices_DID_019D_Trust_model_Backend_CA_certificate_ConditionCheckRead Ssa_ProcCtrl_DataServices_DID_019D_Trust_model_Backend_CA_certificate_ConditionCheckRead
#  define RTE_RUNNABLE_Ssa_ProcCtrl_DataServices_DID_019D_Trust_model_Backend_CA_certificate_ReadData Ssa_ProcCtrl_DataServices_DID_019D_Trust_model_Backend_CA_certificate_ReadData
#  define RTE_RUNNABLE_Ssa_ProcCtrl_DataServices_DID_019D_Trust_model_Backend_CA_certificate_ReadDataLength Ssa_ProcCtrl_DataServices_DID_019D_Trust_model_Backend_CA_certificate_ReadDataLength
#  define RTE_RUNNABLE_Ssa_ProcCtrl_DataServices_DID_019E_Trust_model_Root_CA_certificate_ConditionCheckRead Ssa_ProcCtrl_DataServices_DID_019E_Trust_model_Root_CA_certificate_ConditionCheckRead
#  define RTE_RUNNABLE_Ssa_ProcCtrl_DataServices_DID_019E_Trust_model_Root_CA_certificate_ReadData Ssa_ProcCtrl_DataServices_DID_019E_Trust_model_Root_CA_certificate_ReadData
#  define RTE_RUNNABLE_Ssa_ProcCtrl_DataServices_DID_019E_Trust_model_Root_CA_certificate_ReadDataLength Ssa_ProcCtrl_DataServices_DID_019E_Trust_model_Root_CA_certificate_ReadDataLength
#  define RTE_RUNNABLE_Ssa_ProcCtrl_DataServices_DID_019F_Trust_model_certificates_ConditionCheckRead Ssa_ProcCtrl_DataServices_DID_019F_Trust_model_certificates_ConditionCheckRead
#  define RTE_RUNNABLE_Ssa_ProcCtrl_DataServices_DID_019F_Trust_model_certificates_ReadData Ssa_ProcCtrl_DataServices_DID_019F_Trust_model_certificates_ReadData
#  define RTE_RUNNABLE_Ssa_ProcCtrl_DataServices_DID_019F_Trust_model_certificates_ReadDataLength Ssa_ProcCtrl_DataServices_DID_019F_Trust_model_certificates_ReadDataLength
#  define RTE_RUNNABLE_Ssa_ProcCtrl_DataServices_Security_Event_Log_Current_Counter_Values_ConditionCheckRead Ssa_ProcCtrl_DataServices_Security_Event_Log_Current_Counter_Values_ConditionCheckRead
#  define RTE_RUNNABLE_Ssa_ProcCtrl_DataServices_Security_Event_Log_Current_Counter_Values_ReadData Ssa_ProcCtrl_DataServices_Security_Event_Log_Current_Counter_Values_ReadData
#  define RTE_RUNNABLE_Ssa_ProcCtrl_DataServices_Security_Event_Log_Current_Counter_Values_ReadDataLength Ssa_ProcCtrl_DataServices_Security_Event_Log_Current_Counter_Values_ReadDataLength
#  define RTE_RUNNABLE_Ssa_ProcCtrl_DataServices_Security_Event_Log_Entry_ConditionCheckRead Ssa_ProcCtrl_DataServices_Security_Event_Log_Entry_ConditionCheckRead
#  define RTE_RUNNABLE_Ssa_ProcCtrl_DataServices_Security_Event_Log_Entry_ReadData Ssa_ProcCtrl_DataServices_Security_Event_Log_Entry_ReadData
#  define RTE_RUNNABLE_Ssa_ProcCtrl_DataServices_Security_Event_Log_Entry_ReadDataLength Ssa_ProcCtrl_DataServices_Security_Event_Log_Entry_ReadDataLength
#  define RTE_RUNNABLE_Ssa_ProcCtrl_DiagnosticService_Authentication_0x29_Authenticate Ssa_ProcCtrl_DiagnosticService_Authentication_0x29_Authenticate
#  define RTE_RUNNABLE_Ssa_ProcCtrl_Init Ssa_ProcCtrl_Init
#  define RTE_RUNNABLE_Ssa_ProcCtrl_RoutineServices_Routine_Authenticate_Diagnostic_User_or_Tester Ssa_ProcCtrl_RoutineServices_Routine_Authenticate_Diagnostic_User_or_Tester
#  define RTE_RUNNABLE_Ssa_ProcCtrl_RoutineServices_Routine_Certificate_Self_Check Ssa_ProcCtrl_RoutineServices_Routine_Certificate_Self_Check
#  define RTE_RUNNABLE_Ssa_ProcCtrl_RoutineServices_Routine_Enhance_Access_Rights Ssa_ProcCtrl_RoutineServices_Routine_Enhance_Access_Rights
#  define RTE_RUNNABLE_Ssa_ProcCtrl_RoutineServices_Routine_Evaluate_Data_Verification_Certificate Ssa_ProcCtrl_RoutineServices_Routine_Evaluate_Data_Verification_Certificate
#  define RTE_RUNNABLE_Ssa_ProcCtrl_RoutineServices_Routine_Inject_Seed Ssa_ProcCtrl_RoutineServices_Routine_Inject_Seed
#  define RTE_RUNNABLE_Ssa_ProcCtrl_RoutineServices_Routine_Replace_Certificates Ssa_ProcCtrl_RoutineServices_Routine_Replace_Certificates
#  define RTE_RUNNABLE_Ssa_ProcCtrl_RoutineServices_Routine_Replace_Trust_model_Certificates Ssa_ProcCtrl_RoutineServices_Routine_Replace_Trust_model_Certificates
#  define RTE_RUNNABLE_Ssa_ProcCtrl_RoutineServices_Routine_Replace_Trust_model_Root_Certificate Ssa_ProcCtrl_RoutineServices_Routine_Replace_Trust_model_Root_Certificate
#  define RTE_RUNNABLE_Ssa_ProcCtrl_RoutineServices_Routine_Reset_VIN_Values Ssa_ProcCtrl_RoutineServices_Routine_Reset_VIN_Values
#  define RTE_RUNNABLE_Ssa_ProcCtrl_RoutineServices_Routine_Synchronize_Secured_System_Date_and_Time Ssa_ProcCtrl_RoutineServices_Routine_Synchronize_Secured_System_Date_and_Time
#  define RTE_RUNNABLE_Ssa_ProcCtrl_RoutineServices_Routine_Trust_Model_Generate_Key_Pair Ssa_ProcCtrl_RoutineServices_Routine_Trust_Model_Generate_Key_Pair
#  define RTE_RUNNABLE_Ssa_ProcCtrl_RoutineServices_Routine_Trust_Model_SecOC_ECU_Shared_Secret_Distribution Ssa_ProcCtrl_RoutineServices_Routine_Trust_Model_SecOC_ECU_Shared_Secret_Distribution
#  define RTE_RUNNABLE_Ssa_ProcCtrl_RoutineServices_Routine_Verify_Signature Ssa_ProcCtrl_RoutineServices_Routine_Verify_Signature
#  define RTE_RUNNABLE_Ssa_ProcCtrl_SecurityAccess_CompareKey Ssa_ProcCtrl_SecurityAccess_CompareKey
#  define RTE_RUNNABLE_Ssa_ProcCtrl_SecurityAccess_GetSeed Ssa_ProcCtrl_SecurityAccess_GetSeed
#  define RTE_RUNNABLE_Ssa_ProcCtrl_ServiceDispatcher Ssa_ProcCtrl_ServiceDispatcher
# endif

FUNC(Std_ReturnType, Ssa_ProcCtrl_CODE) Ssa_ProcCtrl_DataServices_DID_018F_Secured_PDU_Data_IDs_and_Key_CMACs_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, Ssa_ProcCtrl_CODE) Ssa_ProcCtrl_DataServices_DID_018F_Secured_PDU_Data_IDs_and_Key_CMACs_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, Ssa_ProcCtrl_CODE) Ssa_ProcCtrl_DataServices_DID_018F_Secured_PDU_Data_IDs_and_Key_CMACs_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data4092ByteType, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
FUNC(Std_ReturnType, Ssa_ProcCtrl_CODE) Ssa_ProcCtrl_DataServices_DID_018F_Secured_PDU_Data_IDs_and_Key_CMACs_ReadDataLength(Dcm_OpStatusType OpStatus, P2VAR(uint16, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) DataLength); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, Ssa_ProcCtrl_CODE) Ssa_ProcCtrl_DataServices_DID_0191_Generated_Random_Number_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, Ssa_ProcCtrl_CODE) Ssa_ProcCtrl_DataServices_DID_0191_Generated_Random_Number_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, Ssa_ProcCtrl_CODE) Ssa_ProcCtrl_DataServices_DID_0191_Generated_Random_Number_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data32ByteType, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
FUNC(Std_ReturnType, Ssa_ProcCtrl_CODE) Ssa_ProcCtrl_DataServices_DID_0191_Generated_Random_Number_Result_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, Ssa_ProcCtrl_CODE) Ssa_ProcCtrl_DataServices_DID_0191_Generated_Random_Number_Result_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, Ssa_ProcCtrl_CODE) Ssa_ProcCtrl_DataServices_DID_0191_Generated_Random_Number_Result_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data1ByteType, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
FUNC(Std_ReturnType, Ssa_ProcCtrl_CODE) Ssa_ProcCtrl_DataServices_DID_0199_Certificates_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, Ssa_ProcCtrl_CODE) Ssa_ProcCtrl_DataServices_DID_0199_Certificates_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, Ssa_ProcCtrl_CODE) Ssa_ProcCtrl_DataServices_DID_0199_Certificates_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data3006ByteType, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
FUNC(Std_ReturnType, Ssa_ProcCtrl_CODE) Ssa_ProcCtrl_DataServices_DID_0199_Certificates_ReadDataLength(Dcm_OpStatusType OpStatus, P2VAR(uint16, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) DataLength); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, Ssa_ProcCtrl_CODE) Ssa_ProcCtrl_DataServices_DID_0199_Data_Signature_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, Ssa_ProcCtrl_CODE) Ssa_ProcCtrl_DataServices_DID_0199_Data_Signature_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, Ssa_ProcCtrl_CODE) Ssa_ProcCtrl_DataServices_DID_0199_Data_Signature_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data64ByteType, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
FUNC(Std_ReturnType, Ssa_ProcCtrl_CODE) Ssa_ProcCtrl_DataServices_DID_0199_Ephemeral_ECU_Public_Key_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, Ssa_ProcCtrl_CODE) Ssa_ProcCtrl_DataServices_DID_0199_Ephemeral_ECU_Public_Key_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, Ssa_ProcCtrl_CODE) Ssa_ProcCtrl_DataServices_DID_0199_Ephemeral_ECU_Public_Key_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data32ByteType, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
FUNC(Std_ReturnType, Ssa_ProcCtrl_CODE) Ssa_ProcCtrl_DataServices_DID_0199_Nonce_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, Ssa_ProcCtrl_CODE) Ssa_ProcCtrl_DataServices_DID_0199_Nonce_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, Ssa_ProcCtrl_CODE) Ssa_ProcCtrl_DataServices_DID_0199_Nonce_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data32ByteType, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
FUNC(Std_ReturnType, Ssa_ProcCtrl_CODE) Ssa_ProcCtrl_DataServices_DID_019A_Trust_model_ECU_CSR_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, Ssa_ProcCtrl_CODE) Ssa_ProcCtrl_DataServices_DID_019A_Trust_model_ECU_CSR_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, Ssa_ProcCtrl_CODE) Ssa_ProcCtrl_DataServices_DID_019A_Trust_model_ECU_CSR_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data1002ByteType, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
FUNC(Std_ReturnType, Ssa_ProcCtrl_CODE) Ssa_ProcCtrl_DataServices_DID_019A_Trust_model_ECU_CSR_ReadDataLength(Dcm_OpStatusType OpStatus, P2VAR(uint16, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) DataLength); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, Ssa_ProcCtrl_CODE) Ssa_ProcCtrl_DataServices_DID_019B_Trust_model_ECU_Certificate_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, Ssa_ProcCtrl_CODE) Ssa_ProcCtrl_DataServices_DID_019B_Trust_model_ECU_Certificate_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, Ssa_ProcCtrl_CODE) Ssa_ProcCtrl_DataServices_DID_019B_Trust_model_ECU_Certificate_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data1002ByteType, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
FUNC(Std_ReturnType, Ssa_ProcCtrl_CODE) Ssa_ProcCtrl_DataServices_DID_019B_Trust_model_ECU_Certificate_ReadDataLength(Dcm_OpStatusType OpStatus, P2VAR(uint16, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) DataLength); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, Ssa_ProcCtrl_CODE) Ssa_ProcCtrl_DataServices_DID_019C_Trust_model_Intermediate_CA_Certificate_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, Ssa_ProcCtrl_CODE) Ssa_ProcCtrl_DataServices_DID_019C_Trust_model_Intermediate_CA_Certificate_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, Ssa_ProcCtrl_CODE) Ssa_ProcCtrl_DataServices_DID_019C_Trust_model_Intermediate_CA_Certificate_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data1002ByteType, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
FUNC(Std_ReturnType, Ssa_ProcCtrl_CODE) Ssa_ProcCtrl_DataServices_DID_019C_Trust_model_Intermediate_CA_Certificate_ReadDataLength(Dcm_OpStatusType OpStatus, P2VAR(uint16, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) DataLength); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, Ssa_ProcCtrl_CODE) Ssa_ProcCtrl_DataServices_DID_019D_Trust_model_Backend_CA_certificate_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, Ssa_ProcCtrl_CODE) Ssa_ProcCtrl_DataServices_DID_019D_Trust_model_Backend_CA_certificate_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, Ssa_ProcCtrl_CODE) Ssa_ProcCtrl_DataServices_DID_019D_Trust_model_Backend_CA_certificate_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data1002ByteType, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
FUNC(Std_ReturnType, Ssa_ProcCtrl_CODE) Ssa_ProcCtrl_DataServices_DID_019D_Trust_model_Backend_CA_certificate_ReadDataLength(Dcm_OpStatusType OpStatus, P2VAR(uint16, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) DataLength); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, Ssa_ProcCtrl_CODE) Ssa_ProcCtrl_DataServices_DID_019E_Trust_model_Root_CA_certificate_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, Ssa_ProcCtrl_CODE) Ssa_ProcCtrl_DataServices_DID_019E_Trust_model_Root_CA_certificate_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, Ssa_ProcCtrl_CODE) Ssa_ProcCtrl_DataServices_DID_019E_Trust_model_Root_CA_certificate_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data1002ByteType, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
FUNC(Std_ReturnType, Ssa_ProcCtrl_CODE) Ssa_ProcCtrl_DataServices_DID_019E_Trust_model_Root_CA_certificate_ReadDataLength(Dcm_OpStatusType OpStatus, P2VAR(uint16, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) DataLength); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, Ssa_ProcCtrl_CODE) Ssa_ProcCtrl_DataServices_DID_019F_Trust_model_certificates_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, Ssa_ProcCtrl_CODE) Ssa_ProcCtrl_DataServices_DID_019F_Trust_model_certificates_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, Ssa_ProcCtrl_CODE) Ssa_ProcCtrl_DataServices_DID_019F_Trust_model_certificates_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data4008ByteType, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
FUNC(Std_ReturnType, Ssa_ProcCtrl_CODE) Ssa_ProcCtrl_DataServices_DID_019F_Trust_model_certificates_ReadDataLength(Dcm_OpStatusType OpStatus, P2VAR(uint16, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) DataLength); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, Ssa_ProcCtrl_CODE) Ssa_ProcCtrl_DataServices_Security_Event_Log_Current_Counter_Values_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, Ssa_ProcCtrl_CODE) Ssa_ProcCtrl_DataServices_Security_Event_Log_Current_Counter_Values_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, Ssa_ProcCtrl_CODE) Ssa_ProcCtrl_DataServices_Security_Event_Log_Current_Counter_Values_ReadDataLength(Dcm_OpStatusType OpStatus, P2VAR(uint16, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) DataLength); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, Ssa_ProcCtrl_CODE) Ssa_ProcCtrl_DataServices_Security_Event_Log_Entry_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, Ssa_ProcCtrl_CODE) Ssa_ProcCtrl_DataServices_Security_Event_Log_Entry_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, Ssa_ProcCtrl_CODE) Ssa_ProcCtrl_DataServices_Security_Event_Log_Entry_ReadDataLength(Dcm_OpStatusType OpStatus, P2VAR(uint16, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) DataLength); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, Ssa_ProcCtrl_CODE) Ssa_ProcCtrl_DiagnosticService_Authentication_0x29_Authenticate(Dcm_OpStatusType OpStatus, Ssa_ConstDataPtr ReqData, uint32 ReqBufSize, uint32 ReqDataLen, Ssa_DataPtr ResData, uint32 ResBufSize, P2VAR(uint32, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) ResDataLen, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, Ssa_ProcCtrl_CODE) Ssa_ProcCtrl_Init(void); /* PRQA S 3451, 0786, 3449 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449 */
FUNC(Std_ReturnType, Ssa_ProcCtrl_CODE) Ssa_ProcCtrl_RoutineServices_Routine_Authenticate_Diagnostic_User_or_Tester(uint8 Configuration, uint8 Task, P2CONST(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_DATA) Challenge_Certificate_Proof_of_Ownership, Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) routineInfo, P2VAR(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) Verification_Result, P2VAR(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) Authentication_Result, P2VAR(uint16, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) DataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, Ssa_ProcCtrl_CODE) Ssa_ProcCtrl_RoutineServices_Routine_Certificate_Self_Check(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) routineInfo, P2VAR(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) Verification_Result, P2VAR(uint16, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) DataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, Ssa_ProcCtrl_CODE) Ssa_ProcCtrl_RoutineServices_Routine_Certificate_Self_Check(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) routineInfo, P2VAR(Dcm_Data18ByteType, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) Verification_Result, P2VAR(uint16, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) DataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
FUNC(Std_ReturnType, Ssa_ProcCtrl_CODE) Ssa_ProcCtrl_RoutineServices_Routine_Enhance_Access_Rights(P2CONST(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_DATA) Enhanced_Rights_Certificate, Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) routineInfo, P2VAR(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) Verification_Result, uint16 DataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, Ssa_ProcCtrl_CODE) Ssa_ProcCtrl_RoutineServices_Routine_Evaluate_Data_Verification_Certificate(P2CONST(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_DATA) Data_Verification_Certificate, Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) routineInfo, P2VAR(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) Verification_Result, uint16 DataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, Ssa_ProcCtrl_CODE) Ssa_ProcCtrl_RoutineServices_Routine_Inject_Seed(P2CONST(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_DATA) Ephemeral_Backend_Public_Key_In, P2CONST(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_DATA) Data_Signature_In, P2CONST(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_DATA) Encrypted_Seed_In, Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) routineInfo_Out, P2VAR(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) Verification_Result_Out, uint16 DataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, Ssa_ProcCtrl_CODE) Ssa_ProcCtrl_RoutineServices_Routine_Inject_Seed(P2CONST(Dcm_Data32ByteType, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_DATA) Ephemeral_Backend_Public_Key_In, P2CONST(Dcm_Data64ByteType, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_DATA) Data_Signature_In, P2CONST(Dcm_Data1058ByteType, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_DATA) Encrypted_Seed_In, Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) routineInfo_Out, P2VAR(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) Verification_Result_Out, uint16 DataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
FUNC(Std_ReturnType, Ssa_ProcCtrl_CODE) Ssa_ProcCtrl_RoutineServices_Routine_Replace_Certificates(P2CONST(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_DATA) Certificates, Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) routineInfo, P2VAR(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) Verification_Result, uint16 DataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, Ssa_ProcCtrl_CODE) Ssa_ProcCtrl_RoutineServices_Routine_Replace_Trust_model_Certificates(P2CONST(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_DATA) Trust_Certificates_In, Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) routineInfo_Out, P2VAR(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) Verification_Result_Out, uint16 DataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, Ssa_ProcCtrl_CODE) Ssa_ProcCtrl_RoutineServices_Routine_Replace_Trust_model_Certificates(P2CONST(Dcm_Data3006ByteType, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_DATA) Trust_Certificates_In, Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) routineInfo_Out, P2VAR(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) Verification_Result_Out, uint16 DataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, Ssa_ProcCtrl_CODE) Ssa_ProcCtrl_RoutineServices_Routine_Replace_Trust_model_Root_Certificate(P2CONST(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_DATA) signature_new_Root_In, P2CONST(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_DATA) signature_In, P2CONST(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_DATA) Certificates_In, Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) routineInfo_Out, P2VAR(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) Verification_Result_Out, uint16 DataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, Ssa_ProcCtrl_CODE) Ssa_ProcCtrl_RoutineServices_Routine_Replace_Trust_model_Root_Certificate(P2CONST(Dcm_Data64ByteType, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_DATA) signature_new_Root_In, P2CONST(Dcm_Data64ByteType, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_DATA) signature_In, P2CONST(Dcm_Data2004ByteType, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_DATA) Certificates_In, Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) routineInfo_Out, P2VAR(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) Verification_Result_Out, uint16 DataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
FUNC(Std_ReturnType, Ssa_ProcCtrl_CODE) Ssa_ProcCtrl_RoutineServices_Routine_Reset_VIN_Values(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) routineInfo, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, Ssa_ProcCtrl_CODE) Ssa_ProcCtrl_RoutineServices_Routine_Synchronize_Secured_System_Date_and_Time(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) routineInfo, P2VAR(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) Nonce, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, Ssa_ProcCtrl_CODE) Ssa_ProcCtrl_RoutineServices_Routine_Trust_Model_Generate_Key_Pair(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) routineInfo_Out, P2VAR(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) Verification_Result_Out, P2VAR(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) CSR_Signature_Out, P2VAR(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) Trust_Model_ECU_CSR_Out, P2VAR(uint16, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) DataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, Ssa_ProcCtrl_CODE) Ssa_ProcCtrl_RoutineServices_Routine_Trust_Model_Generate_Key_Pair(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) routineInfo_Out, P2VAR(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) Verification_Result_Out, P2VAR(Dcm_Data64ByteType, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) CSR_Signature_Out, P2VAR(Dcm_Data1002ByteType, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) Trust_Model_ECU_CSR_Out, P2VAR(uint16, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) DataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, Ssa_ProcCtrl_CODE) Ssa_ProcCtrl_RoutineServices_Routine_Trust_Model_SecOC_ECU_Shared_Secret_Distribution(P2CONST(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_DATA) Date_and_Time_In, P2CONST(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_DATA) Tick_Count_In, P2CONST(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_DATA) Tick_Count_Offset_In, P2CONST(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_DATA) Encrypted_Nonce_and_Shared_Secret_In, P2CONST(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_DATA) Ephemeral_VSM_Public_Key_In, P2CONST(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_DATA) Data_Signature_In, P2CONST(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_DATA) Certificates_In, Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) routineInfo_Out, P2VAR(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) Verification_Result_Out, uint16 DataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, Ssa_ProcCtrl_CODE) Ssa_ProcCtrl_RoutineServices_Routine_Trust_Model_SecOC_ECU_Shared_Secret_Distribution(P2CONST(Dcm_Data7ByteType, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_DATA) Date_and_Time_In, P2CONST(Dcm_Data5ByteType, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_DATA) Tick_Count_In, P2CONST(Dcm_Data5ByteType, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_DATA) Tick_Count_Offset_In, P2CONST(Dcm_Data80ByteType, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_DATA) Encrypted_Nonce_and_Shared_Secret_In, P2CONST(Dcm_Data32ByteType, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_DATA) Ephemeral_VSM_Public_Key_In, P2CONST(Dcm_Data64ByteType, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_DATA) Data_Signature_In, P2CONST(Dcm_Data3006ByteType, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_DATA) Certificates_In, Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) routineInfo_Out, P2VAR(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) Verification_Result_Out, uint16 DataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
FUNC(Std_ReturnType, Ssa_ProcCtrl_CODE) Ssa_ProcCtrl_RoutineServices_Routine_Verify_Signature(uint8 Data_to_be_checked, P2CONST(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_DATA) Signature_Value, Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) routineInfo, P2VAR(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) Verification_Result, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, Ssa_ProcCtrl_CODE) Ssa_ProcCtrl_SecurityAccess_CompareKey(uint8 secLevel, P2CONST(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_DATA) key, Dcm_OpStatusType opStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) errorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, Ssa_ProcCtrl_CODE) Ssa_ProcCtrl_SecurityAccess_GetSeed(uint8 secLevel, Dcm_OpStatusType opStatus, P2VAR(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) seed, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) errorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, Ssa_ProcCtrl_CODE) Ssa_ProcCtrl_ServiceDispatcher(void); /* PRQA S 3451, 0786, 3449 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449 */

# define Ssa_ProcCtrl_STOP_SEC_CODE
# include "Ssa_ProcCtrl_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Application errors
 *********************************************************************************************************************/

#  define RTE_E_DataServices_DID_018F_Secured_PDU_Data_IDs_and_Key_CMACs_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_DID_018F_Secured_PDU_Data_IDs_and_Key_CMACs_E_NOT_OK (1U)

#  define RTE_E_DataServices_DID_0191_Generated_Random_Number_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_DID_0191_Generated_Random_Number_E_NOT_OK (1U)

#  define RTE_E_DataServices_DID_0191_Generated_Random_Number_Result_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_DID_0191_Generated_Random_Number_Result_E_NOT_OK (1U)

#  define RTE_E_DataServices_DID_0199_Certificates_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_DID_0199_Certificates_E_NOT_OK (1U)

#  define RTE_E_DataServices_DID_0199_Data_Signature_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_DID_0199_Data_Signature_E_NOT_OK (1U)

#  define RTE_E_DataServices_DID_0199_Ephemeral_ECU_Public_Key_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_DID_0199_Ephemeral_ECU_Public_Key_E_NOT_OK (1U)

#  define RTE_E_DataServices_DID_0199_Nonce_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_DID_0199_Nonce_E_NOT_OK (1U)

#  define RTE_E_DataServices_DID_019A_Trust_model_ECU_CSR_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_DID_019A_Trust_model_ECU_CSR_E_NOT_OK (1U)

#  define RTE_E_DataServices_DID_019B_Trust_model_ECU_Certificate_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_DID_019B_Trust_model_ECU_Certificate_E_NOT_OK (1U)

#  define RTE_E_DataServices_DID_019C_Trust_model_Intermediate_CA_Certificate_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_DID_019C_Trust_model_Intermediate_CA_Certificate_E_NOT_OK (1U)

#  define RTE_E_DataServices_DID_019D_Trust_model_Backend_CA_certificate_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_DID_019D_Trust_model_Backend_CA_certificate_E_NOT_OK (1U)

#  define RTE_E_DataServices_DID_019E_Trust_model_Root_CA_certificate_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_DID_019E_Trust_model_Root_CA_certificate_E_NOT_OK (1U)

#  define RTE_E_DataServices_DID_019F_Trust_model_certificates_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_DID_019F_Trust_model_certificates_E_NOT_OK (1U)

#  define RTE_E_DataServices_Security_Event_Log_Current_Counter_Values_Read_Security_Event_Log_Current_Counter_Values_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Security_Event_Log_Current_Counter_Values_Read_Security_Event_Log_Current_Counter_Values_E_NOT_OK (1U)

#  define RTE_E_DataServices_Security_Event_Log_Read_Security_Event_Log_Entry_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Security_Event_Log_Read_Security_Event_Log_Entry_E_NOT_OK (1U)

#  define RTE_E_DiagnosticService_Authentication_0x29_DCM_E_FORCE_RCRRP (12U)

#  define RTE_E_DiagnosticService_Authentication_0x29_DCM_E_PENDING (10U)

#  define RTE_E_DiagnosticService_Authentication_0x29_E_NOT_OK (1U)

#  define RTE_E_RoutineServices_Inject_Seed_DCM_E_FORCE_RCRRP (12U)

#  define RTE_E_RoutineServices_Inject_Seed_DCM_E_PENDING (10U)

#  define RTE_E_RoutineServices_Inject_Seed_E_NOT_OK (1U)

#  define RTE_E_RoutineServices_Replace_Trust_model_Certificates_DCM_E_FORCE_RCRRP (12U)

#  define RTE_E_RoutineServices_Replace_Trust_model_Certificates_DCM_E_PENDING (10U)

#  define RTE_E_RoutineServices_Replace_Trust_model_Certificates_E_NOT_OK (1U)

#  define RTE_E_RoutineServices_Replace_Trust_model_Root_Certificate_DCM_E_FORCE_RCRRP (12U)

#  define RTE_E_RoutineServices_Replace_Trust_model_Root_Certificate_DCM_E_PENDING (10U)

#  define RTE_E_RoutineServices_Replace_Trust_model_Root_Certificate_E_NOT_OK (1U)

#  define RTE_E_RoutineServices_Routine_Authenticate_Diagnostic_User_or_Tester_DCM_E_FORCE_RCRRP (12U)

#  define RTE_E_RoutineServices_Routine_Authenticate_Diagnostic_User_or_Tester_DCM_E_PENDING (10U)

#  define RTE_E_RoutineServices_Routine_Authenticate_Diagnostic_User_or_Tester_E_NOT_OK (1U)

#  define RTE_E_RoutineServices_Routine_Certificate_Self_Check_DCM_E_FORCE_RCRRP (12U)

#  define RTE_E_RoutineServices_Routine_Certificate_Self_Check_DCM_E_PENDING (10U)

#  define RTE_E_RoutineServices_Routine_Certificate_Self_Check_E_NOT_OK (1U)

#  define RTE_E_RoutineServices_Routine_Enhance_Access_Rights_DCM_E_FORCE_RCRRP (12U)

#  define RTE_E_RoutineServices_Routine_Enhance_Access_Rights_DCM_E_PENDING (10U)

#  define RTE_E_RoutineServices_Routine_Enhance_Access_Rights_E_NOT_OK (1U)

#  define RTE_E_RoutineServices_Routine_Evaluate_Data_Verification_Certificate_DCM_E_FORCE_RCRRP (12U)

#  define RTE_E_RoutineServices_Routine_Evaluate_Data_Verification_Certificate_DCM_E_PENDING (10U)

#  define RTE_E_RoutineServices_Routine_Evaluate_Data_Verification_Certificate_E_NOT_OK (1U)

#  define RTE_E_RoutineServices_Routine_Replace_Certificates_DCM_E_FORCE_RCRRP (12U)

#  define RTE_E_RoutineServices_Routine_Replace_Certificates_DCM_E_PENDING (10U)

#  define RTE_E_RoutineServices_Routine_Replace_Certificates_E_NOT_OK (1U)

#  define RTE_E_RoutineServices_Routine_Reset_VIN_Values_DCM_E_FORCE_RCRRP (12U)

#  define RTE_E_RoutineServices_Routine_Reset_VIN_Values_DCM_E_PENDING (10U)

#  define RTE_E_RoutineServices_Routine_Reset_VIN_Values_E_NOT_OK (1U)

#  define RTE_E_RoutineServices_Routine_Synchronize_Secured_System_Date_and_Time_DCM_E_FORCE_RCRRP (12U)

#  define RTE_E_RoutineServices_Routine_Synchronize_Secured_System_Date_and_Time_DCM_E_PENDING (10U)

#  define RTE_E_RoutineServices_Routine_Synchronize_Secured_System_Date_and_Time_E_NOT_OK (1U)

#  define RTE_E_RoutineServices_Routine_Verify_Signature_DCM_E_FORCE_RCRRP (12U)

#  define RTE_E_RoutineServices_Routine_Verify_Signature_DCM_E_PENDING (10U)

#  define RTE_E_RoutineServices_Routine_Verify_Signature_E_NOT_OK (1U)

#  define RTE_E_RoutineServices_Trust_Model_Generate_Key_Pair_DCM_E_FORCE_RCRRP (12U)

#  define RTE_E_RoutineServices_Trust_Model_Generate_Key_Pair_DCM_E_PENDING (10U)

#  define RTE_E_RoutineServices_Trust_Model_Generate_Key_Pair_E_NOT_OK (1U)

#  define RTE_E_RoutineServices_Trust_Model_SecOC_ECU_Shared_Secret_Distribution_DCM_E_FORCE_RCRRP (12U)

#  define RTE_E_RoutineServices_Trust_Model_SecOC_ECU_Shared_Secret_Distribution_DCM_E_PENDING (10U)

#  define RTE_E_RoutineServices_Trust_Model_SecOC_ECU_Shared_Secret_Distribution_E_NOT_OK (1U)

#  define RTE_E_SecurityAccessServices_GenericSecurityAccess_E_NOT_OK (1U)

#  define RTE_E_SecurityAccessServices_GenericSecurityAccess_E_PENDING (10U)
# endif /* !defined(RTE_CORE) */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* RTE_SSA_PROCCTRL_H */

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
