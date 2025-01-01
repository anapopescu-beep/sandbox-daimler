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
 *             File:  Rte_Ssa_BcTp.h
 *           Config:  StartApplication.dpa
 *      ECU-Project:  StartApplication
 *
 *        Generator:  MICROSAR RTE Generator Version 4.32.0
 *                    RTE Core Version 4.32.0
 *          License:  CBD2200333
 *
 *      Description:  Application header file for SW-C <Ssa_BcTp>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef RTE_SSA_BCTP_H
# define RTE_SSA_BCTP_H

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

# include "Rte_Ssa_BcTp_Type.h"
# include "Rte_DataHandleType.h"


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

#  define Rte_InitValue_Coding_ReceiveVINTimeout_state (0U)
#  define Rte_InitValue_FvM_ReceiveTickCountTimeout_state (0U)
# endif


# define RTE_START_SEC_CODE
# include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Ssa_BcTp_ReceiveDiagnosticAuthentication_VSS_TP_Auth_ST3(P2VAR(uint8, AUTOMATIC, RTE_SSA_BCTP_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Ssa_BcTp_ReceiveDiagnosticAuthentication_VSS_TP_Auth_ST3(P2VAR(Ssa_Data8ByteType, AUTOMATIC, RTE_SSA_BCTP_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Ssa_BcTp_ReceiveRealTimeOffset_VSS_TP_RealTmOffset_ST3(P2VAR(uint8, AUTOMATIC, RTE_SSA_BCTP_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Ssa_BcTp_ReceiveRealTimeOffset_VSS_TP_RealTmOffset_ST3(P2VAR(Ssa_Data8ByteType, AUTOMATIC, RTE_SSA_BCTP_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Ssa_BcTp_ReceiveSharedSecret_VSS_TP_SharedSecret_ST3(P2VAR(uint8, AUTOMATIC, RTE_SSA_BCTP_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Ssa_BcTp_ReceiveSharedSecret_VSS_TP_SharedSecret_ST3(P2VAR(Ssa_Data8ByteType, AUTOMATIC, RTE_SSA_BCTP_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Ssa_BcTp_ReceiveTickCount_VSS_TP_SecTickCount_ST3(P2VAR(uint8, AUTOMATIC, RTE_SSA_BCTP_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Ssa_BcTp_ReceiveTickCount_VSS_TP_SecTickCount_ST3(P2VAR(Ssa_Data8ByteType, AUTOMATIC, RTE_SSA_BCTP_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Ssa_BcTp_ReceiveVIN_VSS_TP_VIN_ST3(P2VAR(uint8, AUTOMATIC, RTE_SSA_BCTP_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Ssa_BcTp_ReceiveVIN_VSS_TP_VIN_ST3(P2VAR(Ssa_Data8ByteType, AUTOMATIC, RTE_SSA_BCTP_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Ssa_BcTp_Coding_ReceiveVIN_VIN(P2CONST(uint8, AUTOMATIC, RTE_SSA_BCTP_APPL_DATA) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Ssa_BcTp_Coding_ReceiveVIN_VIN(P2CONST(Coding_VINDataType, AUTOMATIC, RTE_SSA_BCTP_APPL_DATA) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Ssa_BcTp_Coding_ReceiveVINTimeout_state(uint8 data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Ssa_BcTp_FvM_ReceiveTickCount_tickCount(P2CONST(uint8, AUTOMATIC, RTE_SSA_BCTP_APPL_DATA) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Ssa_BcTp_FvM_ReceiveTickCount_tickCount(P2CONST(Ssa_Data6ByteType, AUTOMATIC, RTE_SSA_BCTP_APPL_DATA) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Ssa_BcTp_FvM_ReceiveTickCountTimeout_state(uint8 data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Ssa_BcTp_KeyM_ReceiveSharedSecret_sharedSecret(P2CONST(uint8, AUTOMATIC, RTE_SSA_BCTP_APPL_DATA) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Ssa_BcTp_KeyM_ReceiveSharedSecret_sharedSecret(P2CONST(KeyM_SharedSecretType, AUTOMATIC, RTE_SSA_BCTP_APPL_DATA) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Ssa_BcTp_RightsM_ReceiveAuthenticationBroadcast_authentication(P2CONST(uint8, AUTOMATIC, RTE_SSA_BCTP_APPL_DATA) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Ssa_BcTp_RightsM_ReceiveAuthenticationBroadcast_authentication(P2CONST(RightsM_AuthenticationBroadcastType, AUTOMATIC, RTE_SSA_BCTP_APPL_DATA) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Ssa_BcTp_SecLog_MacVerificationSecureBroadcastEvent_verificationStatus(P2CONST(SecOC_VerificationStatusType, AUTOMATIC, RTE_SSA_BCTP_APPL_DATA) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Ssa_BcTp_TimeM_ReceiveRealTimeOffset_realTimeOffset(P2CONST(uint8, AUTOMATIC, RTE_SSA_BCTP_APPL_DATA) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Ssa_BcTp_TimeM_ReceiveRealTimeOffset_realTimeOffset(P2CONST(Ssa_Data12ByteType, AUTOMATIC, RTE_SSA_BCTP_APPL_DATA) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ssa_BcTp_MacVerify_Authentication_MacVerify(P2CONST(uint8, AUTOMATIC, RTE_SSA_BCTP_APPL_DATA) dataBuffer, uint32 dataLength, P2CONST(uint8, AUTOMATIC, RTE_SSA_BCTP_APPL_DATA) macBuffer, uint32 macLength, P2VAR(Crypto_VerifyResultType, AUTOMATIC, RTE_SSA_BCTP_APPL_VAR) verifyBuffer); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ssa_BcTp_MacVerify_Authentication_MacVerify(P2CONST(Csm_DataType_MacAesCmacAuth, AUTOMATIC, RTE_SSA_BCTP_APPL_DATA) dataBuffer, uint32 dataLength, P2CONST(Csm_MacVerifyCompareType_MacVerifyAesCmac, AUTOMATIC, RTE_SSA_BCTP_APPL_DATA) macBuffer, uint32 macLength, P2VAR(Crypto_VerifyResultType, AUTOMATIC, RTE_SSA_BCTP_APPL_VAR) verifyBuffer); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ssa_BcTp_MacVerify_RealTime_MacVerify(P2CONST(uint8, AUTOMATIC, RTE_SSA_BCTP_APPL_DATA) dataBuffer, uint32 dataLength, P2CONST(uint8, AUTOMATIC, RTE_SSA_BCTP_APPL_DATA) macBuffer, uint32 macLength, P2VAR(Crypto_VerifyResultType, AUTOMATIC, RTE_SSA_BCTP_APPL_VAR) verifyBuffer); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ssa_BcTp_MacVerify_RealTime_MacVerify(P2CONST(Csm_DataType_MacAesCmacRealTimeOffset, AUTOMATIC, RTE_SSA_BCTP_APPL_DATA) dataBuffer, uint32 dataLength, P2CONST(Csm_MacVerifyCompareType_MacVerifyAesCmac, AUTOMATIC, RTE_SSA_BCTP_APPL_DATA) macBuffer, uint32 macLength, P2VAR(Crypto_VerifyResultType, AUTOMATIC, RTE_SSA_BCTP_APPL_VAR) verifyBuffer); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ssa_BcTp_MacVerify_TickCount_MacVerify(P2CONST(uint8, AUTOMATIC, RTE_SSA_BCTP_APPL_DATA) dataBuffer, uint32 dataLength, P2CONST(uint8, AUTOMATIC, RTE_SSA_BCTP_APPL_DATA) macBuffer, uint32 macLength, P2VAR(Crypto_VerifyResultType, AUTOMATIC, RTE_SSA_BCTP_APPL_VAR) verifyBuffer); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ssa_BcTp_MacVerify_TickCount_MacVerify(P2CONST(Csm_DataType_MacAesCmacTickCount, AUTOMATIC, RTE_SSA_BCTP_APPL_DATA) dataBuffer, uint32 dataLength, P2CONST(Csm_MacVerifyCompareType_MacVerifyAesCmac, AUTOMATIC, RTE_SSA_BCTP_APPL_DATA) macBuffer, uint32 macLength, P2VAR(Crypto_VerifyResultType, AUTOMATIC, RTE_SSA_BCTP_APPL_VAR) verifyBuffer); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ssa_BcTp_MacVerify_VIN_MacVerify(P2CONST(uint8, AUTOMATIC, RTE_SSA_BCTP_APPL_DATA) dataBuffer, uint32 dataLength, P2CONST(uint8, AUTOMATIC, RTE_SSA_BCTP_APPL_DATA) macBuffer, uint32 macLength, P2VAR(Crypto_VerifyResultType, AUTOMATIC, RTE_SSA_BCTP_APPL_VAR) verifyBuffer); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ssa_BcTp_MacVerify_VIN_MacVerify(P2CONST(Csm_DataType_MacAesCmacVin, AUTOMATIC, RTE_SSA_BCTP_APPL_DATA) dataBuffer, uint32 dataLength, P2CONST(Csm_MacVerifyCompareType_MacVerifyAesCmac, AUTOMATIC, RTE_SSA_BCTP_APPL_DATA) macBuffer, uint32 macLength, P2VAR(Crypto_VerifyResultType, AUTOMATIC, RTE_SSA_BCTP_APPL_VAR) verifyBuffer); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif

# define RTE_STOP_SEC_CODE
# include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# ifndef RTE_CORE

/**********************************************************************************************************************
 * Rte_Read_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Read_ReceiveDiagnosticAuthentication_VSS_TP_Auth_ST3 Rte_Read_Ssa_BcTp_ReceiveDiagnosticAuthentication_VSS_TP_Auth_ST3
#  define Rte_Read_ReceiveRealTimeOffset_VSS_TP_RealTmOffset_ST3 Rte_Read_Ssa_BcTp_ReceiveRealTimeOffset_VSS_TP_RealTmOffset_ST3
#  define Rte_Read_ReceiveSharedSecret_VSS_TP_SharedSecret_ST3 Rte_Read_Ssa_BcTp_ReceiveSharedSecret_VSS_TP_SharedSecret_ST3
#  define Rte_Read_ReceiveTickCount_VSS_TP_SecTickCount_ST3 Rte_Read_Ssa_BcTp_ReceiveTickCount_VSS_TP_SecTickCount_ST3
#  define Rte_Read_ReceiveVIN_VSS_TP_VIN_ST3 Rte_Read_Ssa_BcTp_ReceiveVIN_VSS_TP_VIN_ST3


/**********************************************************************************************************************
 * Rte_Write_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Write_Coding_ReceiveVIN_VIN Rte_Write_Ssa_BcTp_Coding_ReceiveVIN_VIN
#  define Rte_Write_Coding_ReceiveVINTimeout_state Rte_Write_Ssa_BcTp_Coding_ReceiveVINTimeout_state
#  define Rte_Write_FvM_ReceiveTickCount_tickCount Rte_Write_Ssa_BcTp_FvM_ReceiveTickCount_tickCount
#  define Rte_Write_FvM_ReceiveTickCountTimeout_state Rte_Write_Ssa_BcTp_FvM_ReceiveTickCountTimeout_state
#  define Rte_Write_KeyM_ReceiveSharedSecret_sharedSecret Rte_Write_Ssa_BcTp_KeyM_ReceiveSharedSecret_sharedSecret
#  define Rte_Write_RightsM_ReceiveAuthenticationBroadcast_authentication Rte_Write_Ssa_BcTp_RightsM_ReceiveAuthenticationBroadcast_authentication
#  define Rte_Write_SecLog_MacVerificationSecureBroadcastEvent_verificationStatus Rte_Write_Ssa_BcTp_SecLog_MacVerificationSecureBroadcastEvent_verificationStatus
#  define Rte_Write_TimeM_ReceiveRealTimeOffset_realTimeOffset Rte_Write_Ssa_BcTp_TimeM_ReceiveRealTimeOffset_realTimeOffset


/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (unmapped) for synchronous C/S communication
 *********************************************************************************************************************/
#  define RTE_START_SEC_SSA_FVM_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_SSA_FVM_APPL_CODE) Ssa_FvM_GetRxFreshness(uint16 freshnessValueId, P2CONST(uint8, AUTOMATIC, RTE_SSA_FVM_APPL_DATA) truncatedFreshnessValue, uint32 truncatedFreshnessValueLength, uint16 authVerifyAttempts, P2VAR(uint8, AUTOMATIC, RTE_SSA_FVM_APPL_VAR) freshnessValue, P2VAR(uint32, AUTOMATIC, RTE_SSA_FVM_APPL_VAR) freshnessValueLength); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_SSA_FVM_APPL_CODE) Ssa_FvM_GetRxFreshness(uint16 freshnessValueId, P2CONST(freshnessValueType, AUTOMATIC, RTE_SSA_FVM_APPL_DATA) truncatedFreshnessValue, uint32 truncatedFreshnessValueLength, uint16 authVerifyAttempts, P2VAR(freshnessValueType, AUTOMATIC, RTE_SSA_FVM_APPL_VAR) freshnessValue, P2VAR(uint32, AUTOMATIC, RTE_SSA_FVM_APPL_VAR) freshnessValueLength); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif

#  define RTE_STOP_SEC_SSA_FVM_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define Rte_Call_FvM_FreshnessManagement_GetRxFreshness Ssa_FvM_GetRxFreshness
#  define Rte_Call_MacVerify_Authentication_MacVerify Rte_Call_Ssa_BcTp_MacVerify_Authentication_MacVerify
#  define Rte_Call_MacVerify_RealTime_MacVerify Rte_Call_Ssa_BcTp_MacVerify_RealTime_MacVerify
#  define Rte_Call_MacVerify_TickCount_MacVerify Rte_Call_Ssa_BcTp_MacVerify_TickCount_MacVerify
#  define Rte_Call_MacVerify_VIN_MacVerify Rte_Call_Ssa_BcTp_MacVerify_VIN_MacVerify

# endif /* !defined(RTE_CORE) */


# define Ssa_BcTp_START_SEC_CODE
# include "Ssa_BcTp_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

# ifndef RTE_CORE
#  define RTE_RUNNABLE_Ssa_BcTp_Init Ssa_BcTp_Init
#  define RTE_RUNNABLE_Ssa_BcTp_ReceiveDiagnosticAuthentication Ssa_BcTp_ReceiveDiagnosticAuthentication
#  define RTE_RUNNABLE_Ssa_BcTp_ReceiveRealTimeOffset Ssa_BcTp_ReceiveRealTimeOffset
#  define RTE_RUNNABLE_Ssa_BcTp_ReceiveSharedSecret Ssa_BcTp_ReceiveSharedSecret
#  define RTE_RUNNABLE_Ssa_BcTp_ReceiveTickCount Ssa_BcTp_ReceiveTickCount
#  define RTE_RUNNABLE_Ssa_BcTp_ReceiveTickCountTimeout Ssa_BcTp_ReceiveTickCountTimeout
#  define RTE_RUNNABLE_Ssa_BcTp_ReceiveVIN Ssa_BcTp_ReceiveVIN
#  define RTE_RUNNABLE_Ssa_BcTp_ReceiveVINTimeout Ssa_BcTp_ReceiveVINTimeout
# endif

FUNC(void, Ssa_BcTp_CODE) Ssa_BcTp_Init(void); /* PRQA S 3451, 0786, 3449 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449 */
FUNC(void, Ssa_BcTp_CODE) Ssa_BcTp_ReceiveDiagnosticAuthentication(void); /* PRQA S 3451, 0786, 3449 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449 */
FUNC(void, Ssa_BcTp_CODE) Ssa_BcTp_ReceiveRealTimeOffset(void); /* PRQA S 3451, 0786, 3449 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449 */
FUNC(void, Ssa_BcTp_CODE) Ssa_BcTp_ReceiveSharedSecret(void); /* PRQA S 3451, 0786, 3449 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449 */
FUNC(void, Ssa_BcTp_CODE) Ssa_BcTp_ReceiveTickCount(void); /* PRQA S 3451, 0786, 3449 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449 */
FUNC(void, Ssa_BcTp_CODE) Ssa_BcTp_ReceiveTickCountTimeout(void); /* PRQA S 3451, 0786, 3449 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449 */
FUNC(void, Ssa_BcTp_CODE) Ssa_BcTp_ReceiveVIN(void); /* PRQA S 3451, 0786, 3449 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449 */
FUNC(void, Ssa_BcTp_CODE) Ssa_BcTp_ReceiveVINTimeout(void); /* PRQA S 3451, 0786, 3449 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449 */

# define Ssa_BcTp_STOP_SEC_CODE
# include "Ssa_BcTp_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Application errors
 *********************************************************************************************************************/

#  define RTE_E_CsmMacVerify_MacVerifyAesCmacAuth_CSM_E_BUSY (2U)

#  define RTE_E_CsmMacVerify_MacVerifyAesCmacAuth_CSM_E_KEY_EMPTY (13U)

#  define RTE_E_CsmMacVerify_MacVerifyAesCmacAuth_CSM_E_KEY_NOT_VALID (9U)

#  define RTE_E_CsmMacVerify_MacVerifyAesCmacAuth_CSM_E_KEY_SIZE_MISMATCH (10U)

#  define RTE_E_CsmMacVerify_MacVerifyAesCmacAuth_CSM_E_SMALL_BUFFER (3U)

#  define RTE_E_CsmMacVerify_MacVerifyAesCmacAuth_E_NOT_OK (1U)

#  define RTE_E_CsmMacVerify_MacVerifyAesCmacRealTimeOffset_CSM_E_BUSY (2U)

#  define RTE_E_CsmMacVerify_MacVerifyAesCmacRealTimeOffset_CSM_E_KEY_EMPTY (13U)

#  define RTE_E_CsmMacVerify_MacVerifyAesCmacRealTimeOffset_CSM_E_KEY_NOT_VALID (9U)

#  define RTE_E_CsmMacVerify_MacVerifyAesCmacRealTimeOffset_CSM_E_KEY_SIZE_MISMATCH (10U)

#  define RTE_E_CsmMacVerify_MacVerifyAesCmacRealTimeOffset_CSM_E_SMALL_BUFFER (3U)

#  define RTE_E_CsmMacVerify_MacVerifyAesCmacRealTimeOffset_E_NOT_OK (1U)

#  define RTE_E_CsmMacVerify_MacVerifyAesCmacTickCount_CSM_E_BUSY (2U)

#  define RTE_E_CsmMacVerify_MacVerifyAesCmacTickCount_CSM_E_KEY_EMPTY (13U)

#  define RTE_E_CsmMacVerify_MacVerifyAesCmacTickCount_CSM_E_KEY_NOT_VALID (9U)

#  define RTE_E_CsmMacVerify_MacVerifyAesCmacTickCount_CSM_E_KEY_SIZE_MISMATCH (10U)

#  define RTE_E_CsmMacVerify_MacVerifyAesCmacTickCount_CSM_E_SMALL_BUFFER (3U)

#  define RTE_E_CsmMacVerify_MacVerifyAesCmacTickCount_E_NOT_OK (1U)

#  define RTE_E_CsmMacVerify_MacVerifyAesCmacVin_CSM_E_BUSY (2U)

#  define RTE_E_CsmMacVerify_MacVerifyAesCmacVin_CSM_E_KEY_EMPTY (13U)

#  define RTE_E_CsmMacVerify_MacVerifyAesCmacVin_CSM_E_KEY_NOT_VALID (9U)

#  define RTE_E_CsmMacVerify_MacVerifyAesCmacVin_CSM_E_KEY_SIZE_MISMATCH (10U)

#  define RTE_E_CsmMacVerify_MacVerifyAesCmacVin_CSM_E_SMALL_BUFFER (3U)

#  define RTE_E_CsmMacVerify_MacVerifyAesCmacVin_E_NOT_OK (1U)

#  define RTE_E_FvM_FreshnessManagement_E_BUSY (2U)

#  define RTE_E_FvM_FreshnessManagement_E_NOT_OK (1U)

#  define RTE_E_FvM_FreshnessManagement_E_OK (0U)
# endif /* !defined(RTE_CORE) */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* RTE_SSA_BCTP_H */

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
