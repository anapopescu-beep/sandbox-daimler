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
 *             File:  Rte_Ssa_SecLog.h
 *           Config:  StartApplication.dpa
 *      ECU-Project:  StartApplication
 *
 *        Generator:  MICROSAR RTE Generator Version 4.32.0
 *                    RTE Core Version 4.32.0
 *          License:  CBD2200333
 *
 *      Description:  Application header file for SW-C <Ssa_SecLog>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef RTE_SSA_SECLOG_H
# define RTE_SSA_SECLOG_H

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

# include "Rte_Ssa_SecLog_Type.h"
# include "Rte_DataHandleType.h"

# include "Rte_Hook.h"


# define RTE_START_SEC_CODE
# include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Ssa_SecLog_BcTp_SecureBroadcastVerificationStatus_verificationStatus(P2VAR(SecOC_VerificationStatusType, AUTOMATIC, RTE_SSA_SECLOG_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Ssa_SecLog_ReceiveLocalTickCountAndSyncStatus_Data(P2VAR(Ssa_LocalTickCountAndSyncStatusType, AUTOMATIC, RTE_SSA_SECLOG_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Ssa_SecLog_Ssa_IgnitionStatus_Ign_Stat_Pr5_ST3(P2VAR(Ssa_IgnitionStatusType, AUTOMATIC, RTE_SSA_SECLOG_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Ssa_SecLog_SecLog_EventNotification_Data(P2CONST(uint8, AUTOMATIC, RTE_SSA_SECLOG_APPL_DATA) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Ssa_SecLog_SecLog_EventNotification_Data(P2CONST(Ssa_Data7ByteType, AUTOMATIC, RTE_SSA_SECLOG_APPL_DATA) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ssa_SecLog_NvMService_SecLog_LogDataEvnt10_FailedPduMacVerif_GetErrorStatus(P2VAR(NvM_RequestResultType, AUTOMATIC, RTE_SSA_SECLOG_APPL_VAR) ErrorStatus); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ssa_SecLog_NvMService_SecLog_LogDataEvnt10_FailedPduMacVerif_SetRamBlockStatus(boolean RamBlockStatus); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ssa_SecLog_NvMService_SecLog_LogDataEvnt10_FailedPduMacVerif_WriteBlock(dtRef_const_VOID SrcPtr); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ssa_SecLog_NvMService_SecLog_LogDataEvnt11_SecOrAuthBoot_GetErrorStatus(P2VAR(NvM_RequestResultType, AUTOMATIC, RTE_SSA_SECLOG_APPL_VAR) ErrorStatus); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ssa_SecLog_NvMService_SecLog_LogDataEvnt11_SecOrAuthBoot_SetRamBlockStatus(boolean RamBlockStatus); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ssa_SecLog_NvMService_SecLog_LogDataEvnt11_SecOrAuthBoot_WriteBlock(dtRef_const_VOID SrcPtr); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ssa_SecLog_NvMService_SecLog_LogDataEvnt12_ChangeOfVin_GetErrorStatus(P2VAR(NvM_RequestResultType, AUTOMATIC, RTE_SSA_SECLOG_APPL_VAR) ErrorStatus); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ssa_SecLog_NvMService_SecLog_LogDataEvnt12_ChangeOfVin_SetRamBlockStatus(boolean RamBlockStatus); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ssa_SecLog_NvMService_SecLog_LogDataEvnt12_ChangeOfVin_WriteBlock(dtRef_const_VOID SrcPtr); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ssa_SecLog_NvMService_SecLog_LogDataEvnt13_AclReplacement_GetErrorStatus(P2VAR(NvM_RequestResultType, AUTOMATIC, RTE_SSA_SECLOG_APPL_VAR) ErrorStatus); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ssa_SecLog_NvMService_SecLog_LogDataEvnt13_AclReplacement_SetRamBlockStatus(boolean RamBlockStatus); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ssa_SecLog_NvMService_SecLog_LogDataEvnt13_AclReplacement_WriteBlock(dtRef_const_VOID SrcPtr); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ssa_SecLog_NvMService_SecLog_LogDataEvnt1_FailedCertVerif_GetErrorStatus(P2VAR(NvM_RequestResultType, AUTOMATIC, RTE_SSA_SECLOG_APPL_VAR) ErrorStatus); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ssa_SecLog_NvMService_SecLog_LogDataEvnt1_FailedCertVerif_SetRamBlockStatus(boolean RamBlockStatus); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ssa_SecLog_NvMService_SecLog_LogDataEvnt1_FailedCertVerif_WriteBlock(dtRef_const_VOID SrcPtr); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ssa_SecLog_NvMService_SecLog_LogDataEvnt2_SucCertVerif_GetErrorStatus(P2VAR(NvM_RequestResultType, AUTOMATIC, RTE_SSA_SECLOG_APPL_VAR) ErrorStatus); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ssa_SecLog_NvMService_SecLog_LogDataEvnt2_SucCertVerif_SetRamBlockStatus(boolean RamBlockStatus); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ssa_SecLog_NvMService_SecLog_LogDataEvnt2_SucCertVerif_WriteBlock(dtRef_const_VOID SrcPtr); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ssa_SecLog_NvMService_SecLog_LogDataEvnt3_SucAuthAndEnhanceRights_GetErrorStatus(P2VAR(NvM_RequestResultType, AUTOMATIC, RTE_SSA_SECLOG_APPL_VAR) ErrorStatus); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ssa_SecLog_NvMService_SecLog_LogDataEvnt3_SucAuthAndEnhanceRights_SetRamBlockStatus(boolean RamBlockStatus); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ssa_SecLog_NvMService_SecLog_LogDataEvnt3_SucAuthAndEnhanceRights_WriteBlock(dtRef_const_VOID SrcPtr); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ssa_SecLog_NvMService_SecLog_LogDataEvnt4_AuthBySecAccess_GetErrorStatus(P2VAR(NvM_RequestResultType, AUTOMATIC, RTE_SSA_SECLOG_APPL_VAR) ErrorStatus); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ssa_SecLog_NvMService_SecLog_LogDataEvnt4_AuthBySecAccess_SetRamBlockStatus(boolean RamBlockStatus); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ssa_SecLog_NvMService_SecLog_LogDataEvnt4_AuthBySecAccess_WriteBlock(dtRef_const_VOID SrcPtr); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ssa_SecLog_NvMService_SecLog_LogDataEvnt5_SucDiagServiceExec_GetErrorStatus(P2VAR(NvM_RequestResultType, AUTOMATIC, RTE_SSA_SECLOG_APPL_VAR) ErrorStatus); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ssa_SecLog_NvMService_SecLog_LogDataEvnt5_SucDiagServiceExec_SetRamBlockStatus(boolean RamBlockStatus); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ssa_SecLog_NvMService_SecLog_LogDataEvnt5_SucDiagServiceExec_WriteBlock(dtRef_const_VOID SrcPtr); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ssa_SecLog_NvMService_SecLog_LogDataEvnt6_RightsMgmt_GetErrorStatus(P2VAR(NvM_RequestResultType, AUTOMATIC, RTE_SSA_SECLOG_APPL_VAR) ErrorStatus); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ssa_SecLog_NvMService_SecLog_LogDataEvnt6_RightsMgmt_SetRamBlockStatus(boolean RamBlockStatus); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ssa_SecLog_NvMService_SecLog_LogDataEvnt6_RightsMgmt_WriteBlock(dtRef_const_VOID SrcPtr); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ssa_SecLog_NvMService_SecLog_LogDataEvnt7_SigVerif_GetErrorStatus(P2VAR(NvM_RequestResultType, AUTOMATIC, RTE_SSA_SECLOG_APPL_VAR) ErrorStatus); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ssa_SecLog_NvMService_SecLog_LogDataEvnt7_SigVerif_SetRamBlockStatus(boolean RamBlockStatus); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ssa_SecLog_NvMService_SecLog_LogDataEvnt7_SigVerif_WriteBlock(dtRef_const_VOID SrcPtr); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ssa_SecLog_NvMService_SecLog_LogDataEvnt8_TickCountDateAndTime_GetErrorStatus(P2VAR(NvM_RequestResultType, AUTOMATIC, RTE_SSA_SECLOG_APPL_VAR) ErrorStatus); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ssa_SecLog_NvMService_SecLog_LogDataEvnt8_TickCountDateAndTime_SetRamBlockStatus(boolean RamBlockStatus); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ssa_SecLog_NvMService_SecLog_LogDataEvnt8_TickCountDateAndTime_WriteBlock(dtRef_const_VOID SrcPtr); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ssa_SecLog_NvMService_SecLog_LogDataEvnt9_SecOcMisconfig_GetErrorStatus(P2VAR(NvM_RequestResultType, AUTOMATIC, RTE_SSA_SECLOG_APPL_VAR) ErrorStatus); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ssa_SecLog_NvMService_SecLog_LogDataEvnt9_SecOcMisconfig_SetRamBlockStatus(boolean RamBlockStatus); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ssa_SecLog_NvMService_SecLog_LogDataEvnt9_SecOcMisconfig_WriteBlock(dtRef_const_VOID SrcPtr); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ssa_SecLog_NvMService_SecLog_LogFailedMacVerifCount_ExceededTh1_GetErrorStatus(P2VAR(NvM_RequestResultType, AUTOMATIC, RTE_SSA_SECLOG_APPL_VAR) ErrorStatus); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ssa_SecLog_NvMService_SecLog_LogFailedMacVerifCount_ExceededTh1_SetRamBlockStatus(boolean RamBlockStatus); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ssa_SecLog_NvMService_SecLog_LogFailedMacVerifCount_ExceededTh1_WriteBlock(dtRef_const_VOID SrcPtr); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ssa_SecLog_NvMService_SecLog_LogFailedMacVerifCount_ExceededTh2_GetErrorStatus(P2VAR(NvM_RequestResultType, AUTOMATIC, RTE_SSA_SECLOG_APPL_VAR) ErrorStatus); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ssa_SecLog_NvMService_SecLog_LogFailedMacVerifCount_ExceededTh2_SetRamBlockStatus(boolean RamBlockStatus); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ssa_SecLog_NvMService_SecLog_LogFailedMacVerifCount_ExceededTh2_WriteBlock(dtRef_const_VOID SrcPtr); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ssa_SecLog_NvMService_SecLog_LogFailedMacVerifCount_ExceededTh3_GetErrorStatus(P2VAR(NvM_RequestResultType, AUTOMATIC, RTE_SSA_SECLOG_APPL_VAR) ErrorStatus); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ssa_SecLog_NvMService_SecLog_LogFailedMacVerifCount_ExceededTh3_SetRamBlockStatus(boolean RamBlockStatus); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ssa_SecLog_NvMService_SecLog_LogFailedMacVerifCount_ExceededTh3_WriteBlock(dtRef_const_VOID SrcPtr); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */


# define RTE_STOP_SEC_CODE
# include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# ifndef RTE_CORE

/**********************************************************************************************************************
 * Rte_Read_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Read_BcTp_SecureBroadcastVerificationStatus_verificationStatus Rte_Read_Ssa_SecLog_BcTp_SecureBroadcastVerificationStatus_verificationStatus
#  define Rte_Read_ReceiveLocalTickCountAndSyncStatus_Data Rte_Read_Ssa_SecLog_ReceiveLocalTickCountAndSyncStatus_Data
#  define Rte_Read_Ssa_IgnitionStatus_Ign_Stat_Pr5_ST3 Rte_Read_Ssa_SecLog_Ssa_IgnitionStatus_Ign_Stat_Pr5_ST3


/**********************************************************************************************************************
 * Rte_Send_<p>_<d> (explicit S/R communication with isQueued = true)
 *********************************************************************************************************************/
#  define Rte_Send_Ssa_FailedMacVerifCounterEvent_Event Rte_Send_Ssa_SecLog_Ssa_FailedMacVerifCounterEvent_Event
#  define Rte_Send_Ssa_SecLog_Ssa_FailedMacVerifCounterEvent_Event(data) (RTE_E_OK)


/**********************************************************************************************************************
 * Rte_Write_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Write_SecLog_EventNotification_Data Rte_Write_Ssa_SecLog_SecLog_EventNotification_Data


/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (unmapped) for synchronous C/S communication
 *********************************************************************************************************************/
#  define RTE_START_SEC_DEMSATELLITE_0_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FUNC(Std_ReturnType, RTE_DEMSATELLITE_0_APPL_CODE) Dem_SetEventStatus(Dem_EventIdType parg0, Dem_EventStatusType EventStatus); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */

#  define RTE_STOP_SEC_DEMSATELLITE_0_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define RTE_START_SEC_SSA_KEYM_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_SSA_KEYM_APPL_CODE) Ssa_KeyM_Certificate_SignData1024ByteWithEcuPrivateKey(P2CONST(uint8, AUTOMATIC, RTE_SSA_KEYM_APPL_DATA) data, uint16 dataLength, P2VAR(uint8, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) signature); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_SSA_KEYM_APPL_CODE) Ssa_KeyM_Certificate_SignData1024ByteWithEcuPrivateKey(P2CONST(Ssa_Data1024ByteType, AUTOMATIC, RTE_SSA_KEYM_APPL_DATA) data, uint16 dataLength, P2VAR(Ssa_Data64ByteType, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) signature); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_SSA_KEYM_APPL_CODE) Ssa_KeyM_Certificate_SignData4092ByteWithEcuPrivateKey(P2CONST(uint8, AUTOMATIC, RTE_SSA_KEYM_APPL_DATA) data, uint16 dataLength, P2VAR(uint8, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) signature); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_SSA_KEYM_APPL_CODE) Ssa_KeyM_Certificate_SignData4092ByteWithEcuPrivateKey(P2CONST(Ssa_Data4092ByteType, AUTOMATIC, RTE_SSA_KEYM_APPL_DATA) data, uint16 dataLength, P2VAR(Ssa_Data64ByteType, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) signature); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif

#  define RTE_STOP_SEC_SSA_KEYM_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define RTE_START_SEC_SSA_RIGHTSM_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FUNC(Std_ReturnType, RTE_SSA_RIGHTSM_APPL_CODE) Ssa_RightsM_DiagnosticChannel_GetDiagChanAndAuthenticationState(P2VAR(uint8, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_VAR) diagChanAndAuthStatus); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */

#  define RTE_STOP_SEC_SSA_RIGHTSM_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define RTE_START_SEC_SSA_TIMEM_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FUNC(Std_ReturnType, RTE_SSA_TIMEM_APPL_CODE) Ssa_TimeM_RealTime_Get(P2VAR(TimeM_DateTimeType, AUTOMATIC, RTE_SSA_TIMEM_APPL_VAR) realTime); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_SSA_TIMEM_APPL_CODE) Ssa_TimeM_TickCount_Get(P2VAR(uint64, AUTOMATIC, RTE_SSA_TIMEM_APPL_VAR) tickCount); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */

#  define RTE_STOP_SEC_SSA_TIMEM_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define Rte_Call_DTC_0xD12083_SetEventStatus(arg1) (Dem_SetEventStatus((Dem_EventIdType)31, arg1))
#  define Rte_Call_KeyM_Certificate_SignData1024ByteWithEcuPrivateKey Ssa_KeyM_Certificate_SignData1024ByteWithEcuPrivateKey
#  define Rte_Call_KeyM_Certificate_SignData4092ByteWithEcuPrivateKey Ssa_KeyM_Certificate_SignData4092ByteWithEcuPrivateKey
#  define Rte_Call_NvMService_SecLog_LogDataEvnt10_FailedPduMacVerif_GetErrorStatus Rte_Call_Ssa_SecLog_NvMService_SecLog_LogDataEvnt10_FailedPduMacVerif_GetErrorStatus
#  define Rte_Call_NvMService_SecLog_LogDataEvnt10_FailedPduMacVerif_SetRamBlockStatus Rte_Call_Ssa_SecLog_NvMService_SecLog_LogDataEvnt10_FailedPduMacVerif_SetRamBlockStatus
#  define Rte_Call_NvMService_SecLog_LogDataEvnt10_FailedPduMacVerif_WriteBlock Rte_Call_Ssa_SecLog_NvMService_SecLog_LogDataEvnt10_FailedPduMacVerif_WriteBlock
#  define Rte_Call_NvMService_SecLog_LogDataEvnt11_SecOrAuthBoot_GetErrorStatus Rte_Call_Ssa_SecLog_NvMService_SecLog_LogDataEvnt11_SecOrAuthBoot_GetErrorStatus
#  define Rte_Call_NvMService_SecLog_LogDataEvnt11_SecOrAuthBoot_SetRamBlockStatus Rte_Call_Ssa_SecLog_NvMService_SecLog_LogDataEvnt11_SecOrAuthBoot_SetRamBlockStatus
#  define Rte_Call_NvMService_SecLog_LogDataEvnt11_SecOrAuthBoot_WriteBlock Rte_Call_Ssa_SecLog_NvMService_SecLog_LogDataEvnt11_SecOrAuthBoot_WriteBlock
#  define Rte_Call_NvMService_SecLog_LogDataEvnt12_ChangeOfVin_GetErrorStatus Rte_Call_Ssa_SecLog_NvMService_SecLog_LogDataEvnt12_ChangeOfVin_GetErrorStatus
#  define Rte_Call_NvMService_SecLog_LogDataEvnt12_ChangeOfVin_SetRamBlockStatus Rte_Call_Ssa_SecLog_NvMService_SecLog_LogDataEvnt12_ChangeOfVin_SetRamBlockStatus
#  define Rte_Call_NvMService_SecLog_LogDataEvnt12_ChangeOfVin_WriteBlock Rte_Call_Ssa_SecLog_NvMService_SecLog_LogDataEvnt12_ChangeOfVin_WriteBlock
#  define Rte_Call_NvMService_SecLog_LogDataEvnt13_AclReplacement_GetErrorStatus Rte_Call_Ssa_SecLog_NvMService_SecLog_LogDataEvnt13_AclReplacement_GetErrorStatus
#  define Rte_Call_NvMService_SecLog_LogDataEvnt13_AclReplacement_SetRamBlockStatus Rte_Call_Ssa_SecLog_NvMService_SecLog_LogDataEvnt13_AclReplacement_SetRamBlockStatus
#  define Rte_Call_NvMService_SecLog_LogDataEvnt13_AclReplacement_WriteBlock Rte_Call_Ssa_SecLog_NvMService_SecLog_LogDataEvnt13_AclReplacement_WriteBlock
#  define Rte_Call_NvMService_SecLog_LogDataEvnt1_FailedCertVerif_GetErrorStatus Rte_Call_Ssa_SecLog_NvMService_SecLog_LogDataEvnt1_FailedCertVerif_GetErrorStatus
#  define Rte_Call_NvMService_SecLog_LogDataEvnt1_FailedCertVerif_SetRamBlockStatus Rte_Call_Ssa_SecLog_NvMService_SecLog_LogDataEvnt1_FailedCertVerif_SetRamBlockStatus
#  define Rte_Call_NvMService_SecLog_LogDataEvnt1_FailedCertVerif_WriteBlock Rte_Call_Ssa_SecLog_NvMService_SecLog_LogDataEvnt1_FailedCertVerif_WriteBlock
#  define Rte_Call_NvMService_SecLog_LogDataEvnt2_SucCertVerif_GetErrorStatus Rte_Call_Ssa_SecLog_NvMService_SecLog_LogDataEvnt2_SucCertVerif_GetErrorStatus
#  define Rte_Call_NvMService_SecLog_LogDataEvnt2_SucCertVerif_SetRamBlockStatus Rte_Call_Ssa_SecLog_NvMService_SecLog_LogDataEvnt2_SucCertVerif_SetRamBlockStatus
#  define Rte_Call_NvMService_SecLog_LogDataEvnt2_SucCertVerif_WriteBlock Rte_Call_Ssa_SecLog_NvMService_SecLog_LogDataEvnt2_SucCertVerif_WriteBlock
#  define Rte_Call_NvMService_SecLog_LogDataEvnt3_SucAuthAndEnhanceRights_GetErrorStatus Rte_Call_Ssa_SecLog_NvMService_SecLog_LogDataEvnt3_SucAuthAndEnhanceRights_GetErrorStatus
#  define Rte_Call_NvMService_SecLog_LogDataEvnt3_SucAuthAndEnhanceRights_SetRamBlockStatus Rte_Call_Ssa_SecLog_NvMService_SecLog_LogDataEvnt3_SucAuthAndEnhanceRights_SetRamBlockStatus
#  define Rte_Call_NvMService_SecLog_LogDataEvnt3_SucAuthAndEnhanceRights_WriteBlock Rte_Call_Ssa_SecLog_NvMService_SecLog_LogDataEvnt3_SucAuthAndEnhanceRights_WriteBlock
#  define Rte_Call_NvMService_SecLog_LogDataEvnt4_AuthBySecAccess_GetErrorStatus Rte_Call_Ssa_SecLog_NvMService_SecLog_LogDataEvnt4_AuthBySecAccess_GetErrorStatus
#  define Rte_Call_NvMService_SecLog_LogDataEvnt4_AuthBySecAccess_SetRamBlockStatus Rte_Call_Ssa_SecLog_NvMService_SecLog_LogDataEvnt4_AuthBySecAccess_SetRamBlockStatus
#  define Rte_Call_NvMService_SecLog_LogDataEvnt4_AuthBySecAccess_WriteBlock Rte_Call_Ssa_SecLog_NvMService_SecLog_LogDataEvnt4_AuthBySecAccess_WriteBlock
#  define Rte_Call_NvMService_SecLog_LogDataEvnt5_SucDiagServiceExec_GetErrorStatus Rte_Call_Ssa_SecLog_NvMService_SecLog_LogDataEvnt5_SucDiagServiceExec_GetErrorStatus
#  define Rte_Call_NvMService_SecLog_LogDataEvnt5_SucDiagServiceExec_SetRamBlockStatus Rte_Call_Ssa_SecLog_NvMService_SecLog_LogDataEvnt5_SucDiagServiceExec_SetRamBlockStatus
#  define Rte_Call_NvMService_SecLog_LogDataEvnt5_SucDiagServiceExec_WriteBlock Rte_Call_Ssa_SecLog_NvMService_SecLog_LogDataEvnt5_SucDiagServiceExec_WriteBlock
#  define Rte_Call_NvMService_SecLog_LogDataEvnt6_RightsMgmt_GetErrorStatus Rte_Call_Ssa_SecLog_NvMService_SecLog_LogDataEvnt6_RightsMgmt_GetErrorStatus
#  define Rte_Call_NvMService_SecLog_LogDataEvnt6_RightsMgmt_SetRamBlockStatus Rte_Call_Ssa_SecLog_NvMService_SecLog_LogDataEvnt6_RightsMgmt_SetRamBlockStatus
#  define Rte_Call_NvMService_SecLog_LogDataEvnt6_RightsMgmt_WriteBlock Rte_Call_Ssa_SecLog_NvMService_SecLog_LogDataEvnt6_RightsMgmt_WriteBlock
#  define Rte_Call_NvMService_SecLog_LogDataEvnt7_SigVerif_GetErrorStatus Rte_Call_Ssa_SecLog_NvMService_SecLog_LogDataEvnt7_SigVerif_GetErrorStatus
#  define Rte_Call_NvMService_SecLog_LogDataEvnt7_SigVerif_SetRamBlockStatus Rte_Call_Ssa_SecLog_NvMService_SecLog_LogDataEvnt7_SigVerif_SetRamBlockStatus
#  define Rte_Call_NvMService_SecLog_LogDataEvnt7_SigVerif_WriteBlock Rte_Call_Ssa_SecLog_NvMService_SecLog_LogDataEvnt7_SigVerif_WriteBlock
#  define Rte_Call_NvMService_SecLog_LogDataEvnt8_TickCountDateAndTime_GetErrorStatus Rte_Call_Ssa_SecLog_NvMService_SecLog_LogDataEvnt8_TickCountDateAndTime_GetErrorStatus
#  define Rte_Call_NvMService_SecLog_LogDataEvnt8_TickCountDateAndTime_SetRamBlockStatus Rte_Call_Ssa_SecLog_NvMService_SecLog_LogDataEvnt8_TickCountDateAndTime_SetRamBlockStatus
#  define Rte_Call_NvMService_SecLog_LogDataEvnt8_TickCountDateAndTime_WriteBlock Rte_Call_Ssa_SecLog_NvMService_SecLog_LogDataEvnt8_TickCountDateAndTime_WriteBlock
#  define Rte_Call_NvMService_SecLog_LogDataEvnt9_SecOcMisconfig_GetErrorStatus Rte_Call_Ssa_SecLog_NvMService_SecLog_LogDataEvnt9_SecOcMisconfig_GetErrorStatus
#  define Rte_Call_NvMService_SecLog_LogDataEvnt9_SecOcMisconfig_SetRamBlockStatus Rte_Call_Ssa_SecLog_NvMService_SecLog_LogDataEvnt9_SecOcMisconfig_SetRamBlockStatus
#  define Rte_Call_NvMService_SecLog_LogDataEvnt9_SecOcMisconfig_WriteBlock Rte_Call_Ssa_SecLog_NvMService_SecLog_LogDataEvnt9_SecOcMisconfig_WriteBlock
#  define Rte_Call_NvMService_SecLog_LogFailedMacVerifCount_ExceededTh1_GetErrorStatus Rte_Call_Ssa_SecLog_NvMService_SecLog_LogFailedMacVerifCount_ExceededTh1_GetErrorStatus
#  define Rte_Call_NvMService_SecLog_LogFailedMacVerifCount_ExceededTh1_SetRamBlockStatus Rte_Call_Ssa_SecLog_NvMService_SecLog_LogFailedMacVerifCount_ExceededTh1_SetRamBlockStatus
#  define Rte_Call_NvMService_SecLog_LogFailedMacVerifCount_ExceededTh1_WriteBlock Rte_Call_Ssa_SecLog_NvMService_SecLog_LogFailedMacVerifCount_ExceededTh1_WriteBlock
#  define Rte_Call_NvMService_SecLog_LogFailedMacVerifCount_ExceededTh2_GetErrorStatus Rte_Call_Ssa_SecLog_NvMService_SecLog_LogFailedMacVerifCount_ExceededTh2_GetErrorStatus
#  define Rte_Call_NvMService_SecLog_LogFailedMacVerifCount_ExceededTh2_SetRamBlockStatus Rte_Call_Ssa_SecLog_NvMService_SecLog_LogFailedMacVerifCount_ExceededTh2_SetRamBlockStatus
#  define Rte_Call_NvMService_SecLog_LogFailedMacVerifCount_ExceededTh2_WriteBlock Rte_Call_Ssa_SecLog_NvMService_SecLog_LogFailedMacVerifCount_ExceededTh2_WriteBlock
#  define Rte_Call_NvMService_SecLog_LogFailedMacVerifCount_ExceededTh3_GetErrorStatus Rte_Call_Ssa_SecLog_NvMService_SecLog_LogFailedMacVerifCount_ExceededTh3_GetErrorStatus
#  define Rte_Call_NvMService_SecLog_LogFailedMacVerifCount_ExceededTh3_SetRamBlockStatus Rte_Call_Ssa_SecLog_NvMService_SecLog_LogFailedMacVerifCount_ExceededTh3_SetRamBlockStatus
#  define Rte_Call_NvMService_SecLog_LogFailedMacVerifCount_ExceededTh3_WriteBlock Rte_Call_Ssa_SecLog_NvMService_SecLog_LogFailedMacVerifCount_ExceededTh3_WriteBlock
#  define Rte_Call_RightsM_DiagnosticChannel_GetDiagChanAndAuthStatus Ssa_RightsM_DiagnosticChannel_GetDiagChanAndAuthenticationState
#  define Rte_Call_TimeM_RealTime_Get Ssa_TimeM_RealTime_Get
#  define Rte_Call_TimeM_TickCount_Get Ssa_TimeM_TickCount_Get

/**********************************************************************************************************************
 * Exclusive Areas
 *********************************************************************************************************************/

#  define Rte_Enter_SecLog_ExclusiveArea() SuspendAllInterrupts() /* RteAnalyzer(ExclusiveArea, ALL_INTERRUPT_BLOCKING) */

#  define Rte_Exit_SecLog_ExclusiveArea() ResumeAllInterrupts()  /* RteAnalyzer(ExclusiveArea, ALL_INTERRUPT_BLOCKING) */


/**********************************************************************************************************************
 * Rte_CData (SW-C local calibration parameters)
 *********************************************************************************************************************/

#  ifndef RTE_MICROSAR_PIM_EXPORT

#   define RTE_START_SEC_CONST_DEFAULT_RTE_CDATA_GROUP_UNSPECIFIED
#   include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern CONST(SecLog_CtrlDataType, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_Ssa_SecLog_NvM_SecLog_CtrlData_DefaultValue;

#   define RTE_STOP_SEC_CONST_DEFAULT_RTE_CDATA_GROUP_UNSPECIFIED
#   include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  endif

#  ifndef RTE_PTR2ARRAYTYPE_PASSING
#   define Rte_CData_NvM_SecLog_CtrlData_DefaultValue() (&(Rte_Ssa_SecLog_NvM_SecLog_CtrlData_DefaultValue[0]))
#  else
#   define Rte_CData_NvM_SecLog_CtrlData_DefaultValue() (&Rte_Ssa_SecLog_NvM_SecLog_CtrlData_DefaultValue)
#  endif

/**********************************************************************************************************************
 * Rte_Pim (Per-Instance Memory)
 *********************************************************************************************************************/

#  ifndef RTE_MICROSAR_PIM_EXPORT
#   define RTE_START_SEC_VAR_DEFAULT_RTE_PIM_GROUP_UNSPECIFIED
#   include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern VAR(SecLog_LogDataEvnt10_FailedPduMacVerifType, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_Ssa_SecLog_LogDataEvnt10_FailedPduMacVerif;
extern VAR(SecLog_LogDataEvnt10_FailedPduMacVerifType, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_Ssa_SecLog_LogDataEvnt10_FailedPduMacVerif_Mirror;
extern VAR(SecLog_LogDataEvnt11_SecOrAuthBootType, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_Ssa_SecLog_LogDataEvnt11_SecOrAuthBoot;
extern VAR(SecLog_LogDataEvnt11_SecOrAuthBootType, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_Ssa_SecLog_LogDataEvnt11_SecOrAuthBoot_Mirror;
extern VAR(SecLog_LogDataEvnt12_ChangeOfVinType, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_Ssa_SecLog_LogDataEvnt12_ChangeOfVin;
extern VAR(SecLog_LogDataEvnt12_ChangeOfVinType, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_Ssa_SecLog_LogDataEvnt12_ChangeOfVin_Mirror;
extern VAR(SecLog_LogDataEvnt13_AclReplacementType, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_Ssa_SecLog_LogDataEvnt13_AclReplacement;
extern VAR(SecLog_LogDataEvnt13_AclReplacementType, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_Ssa_SecLog_LogDataEvnt13_AclReplacement_Mirror;
extern VAR(SecLog_LogDataEvnt1_FailedCertVerifType, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_Ssa_SecLog_LogDataEvnt1_FailedCertVerif;
extern VAR(SecLog_LogDataEvnt1_FailedCertVerifType, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_Ssa_SecLog_LogDataEvnt1_FailedCertVerif_Mirror;
extern VAR(SecLog_LogDataEvnt2_SucCertVerifType, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_Ssa_SecLog_LogDataEvnt2_SucCertVerif;
extern VAR(SecLog_LogDataEvnt2_SucCertVerifType, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_Ssa_SecLog_LogDataEvnt2_SucCertVerif_Mirror;
extern VAR(SecLog_LogDataEvnt3_SucAuthAndEnhanceRightsType, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_Ssa_SecLog_LogDataEvnt3_SucAuthAndEnhanceRights;
extern VAR(SecLog_LogDataEvnt3_SucAuthAndEnhanceRightsType, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_Ssa_SecLog_LogDataEvnt3_SucAuthAndEnhanceRights_Mirror;
extern VAR(SecLog_LogDataEvnt4_AuthBySecAccessType, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_Ssa_SecLog_LogDataEvnt4_AuthBySecAccess;
extern VAR(SecLog_LogDataEvnt4_AuthBySecAccessType, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_Ssa_SecLog_LogDataEvnt4_AuthBySecAccess_Mirror;
extern VAR(SecLog_LogDataEvnt5_SucDiagServiceExecType, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_Ssa_SecLog_LogDataEvnt5_SucDiagServiceExec;
extern VAR(SecLog_LogDataEvnt5_SucDiagServiceExecType, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_Ssa_SecLog_LogDataEvnt5_SucDiagServiceExec_Mirror;
extern VAR(SecLog_LogDataEvnt6_RightsMgmtType, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_Ssa_SecLog_LogDataEvnt6_RightsMgmt;
extern VAR(SecLog_LogDataEvnt6_RightsMgmtType, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_Ssa_SecLog_LogDataEvnt6_RightsMgmt_Mirror;
extern VAR(SecLog_LogDataEvnt7_SigVerifType, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_Ssa_SecLog_LogDataEvnt7_SigVerif;
extern VAR(SecLog_LogDataEvnt7_SigVerifType, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_Ssa_SecLog_LogDataEvnt7_SigVerif_Mirror;
extern VAR(SecLog_LogDataEvnt8_TickCountDateAndTimeType, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_Ssa_SecLog_LogDataEvnt8_TickCountDateAndTime;
extern VAR(SecLog_LogDataEvnt8_TickCountDateAndTimeType, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_Ssa_SecLog_LogDataEvnt8_TickCountDateAndTime_Mirror;
extern VAR(SecLog_LogDataEvnt9_SecOcMisconfigType, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_Ssa_SecLog_LogDataEvnt9_SecOcMisconfig;
extern VAR(SecLog_LogDataEvnt9_SecOcMisconfigType, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_Ssa_SecLog_LogDataEvnt9_SecOcMisconfig_Mirror;
extern VAR(SecLog_LogFailedMacVerifCount_ExceededThType, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_Ssa_SecLog_LogFailedMacVerifCount_ExceededTh1;
extern VAR(SecLog_LogFailedMacVerifCount_ExceededThType, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_Ssa_SecLog_LogFailedMacVerifCount_ExceededTh1_Mirror;
extern VAR(SecLog_LogFailedMacVerifCount_ExceededThType, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_Ssa_SecLog_LogFailedMacVerifCount_ExceededTh2;
extern VAR(SecLog_LogFailedMacVerifCount_ExceededThType, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_Ssa_SecLog_LogFailedMacVerifCount_ExceededTh2_Mirror;
extern VAR(SecLog_LogFailedMacVerifCount_ExceededThType, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_Ssa_SecLog_LogFailedMacVerifCount_ExceededTh3;
extern VAR(SecLog_LogFailedMacVerifCount_ExceededThType, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_Ssa_SecLog_LogFailedMacVerifCount_ExceededTh3_Mirror;

#   define RTE_STOP_SEC_VAR_DEFAULT_RTE_PIM_GROUP_UNSPECIFIED
#   include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  endif

/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
#   define Rte_Pim_LogDataEvnt10_FailedPduMacVerif() (&((*RtePim_LogDataEvnt10_FailedPduMacVerif())[0]))
#  else
#   define Rte_Pim_LogDataEvnt10_FailedPduMacVerif() RtePim_LogDataEvnt10_FailedPduMacVerif()
#  endif
#  define RtePim_LogDataEvnt10_FailedPduMacVerif() \
  (&Rte_Ssa_SecLog_LogDataEvnt10_FailedPduMacVerif)
/* PRQA L:L1 */

/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
#   define Rte_Pim_LogDataEvnt10_FailedPduMacVerif_Mirror() (&((*RtePim_LogDataEvnt10_FailedPduMacVerif_Mirror())[0]))
#  else
#   define Rte_Pim_LogDataEvnt10_FailedPduMacVerif_Mirror() RtePim_LogDataEvnt10_FailedPduMacVerif_Mirror()
#  endif
#  define RtePim_LogDataEvnt10_FailedPduMacVerif_Mirror() \
  (&Rte_Ssa_SecLog_LogDataEvnt10_FailedPduMacVerif_Mirror)
/* PRQA L:L1 */

/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
#   define Rte_Pim_LogDataEvnt11_SecOrAuthBoot() (&((*RtePim_LogDataEvnt11_SecOrAuthBoot())[0]))
#  else
#   define Rte_Pim_LogDataEvnt11_SecOrAuthBoot() RtePim_LogDataEvnt11_SecOrAuthBoot()
#  endif
#  define RtePim_LogDataEvnt11_SecOrAuthBoot() \
  (&Rte_Ssa_SecLog_LogDataEvnt11_SecOrAuthBoot)
/* PRQA L:L1 */

/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
#   define Rte_Pim_LogDataEvnt11_SecOrAuthBoot_Mirror() (&((*RtePim_LogDataEvnt11_SecOrAuthBoot_Mirror())[0]))
#  else
#   define Rte_Pim_LogDataEvnt11_SecOrAuthBoot_Mirror() RtePim_LogDataEvnt11_SecOrAuthBoot_Mirror()
#  endif
#  define RtePim_LogDataEvnt11_SecOrAuthBoot_Mirror() \
  (&Rte_Ssa_SecLog_LogDataEvnt11_SecOrAuthBoot_Mirror)
/* PRQA L:L1 */

/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
#   define Rte_Pim_LogDataEvnt12_ChangeOfVin() (&((*RtePim_LogDataEvnt12_ChangeOfVin())[0]))
#  else
#   define Rte_Pim_LogDataEvnt12_ChangeOfVin() RtePim_LogDataEvnt12_ChangeOfVin()
#  endif
#  define RtePim_LogDataEvnt12_ChangeOfVin() \
  (&Rte_Ssa_SecLog_LogDataEvnt12_ChangeOfVin)
/* PRQA L:L1 */

/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
#   define Rte_Pim_LogDataEvnt12_ChangeOfVin_Mirror() (&((*RtePim_LogDataEvnt12_ChangeOfVin_Mirror())[0]))
#  else
#   define Rte_Pim_LogDataEvnt12_ChangeOfVin_Mirror() RtePim_LogDataEvnt12_ChangeOfVin_Mirror()
#  endif
#  define RtePim_LogDataEvnt12_ChangeOfVin_Mirror() \
  (&Rte_Ssa_SecLog_LogDataEvnt12_ChangeOfVin_Mirror)
/* PRQA L:L1 */

/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
#   define Rte_Pim_LogDataEvnt13_AclReplacement() (&((*RtePim_LogDataEvnt13_AclReplacement())[0]))
#  else
#   define Rte_Pim_LogDataEvnt13_AclReplacement() RtePim_LogDataEvnt13_AclReplacement()
#  endif
#  define RtePim_LogDataEvnt13_AclReplacement() \
  (&Rte_Ssa_SecLog_LogDataEvnt13_AclReplacement)
/* PRQA L:L1 */

/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
#   define Rte_Pim_LogDataEvnt13_AclReplacement_Mirror() (&((*RtePim_LogDataEvnt13_AclReplacement_Mirror())[0]))
#  else
#   define Rte_Pim_LogDataEvnt13_AclReplacement_Mirror() RtePim_LogDataEvnt13_AclReplacement_Mirror()
#  endif
#  define RtePim_LogDataEvnt13_AclReplacement_Mirror() \
  (&Rte_Ssa_SecLog_LogDataEvnt13_AclReplacement_Mirror)
/* PRQA L:L1 */

/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
#   define Rte_Pim_LogDataEvnt1_FailedCertVerif() (&((*RtePim_LogDataEvnt1_FailedCertVerif())[0]))
#  else
#   define Rte_Pim_LogDataEvnt1_FailedCertVerif() RtePim_LogDataEvnt1_FailedCertVerif()
#  endif
#  define RtePim_LogDataEvnt1_FailedCertVerif() \
  (&Rte_Ssa_SecLog_LogDataEvnt1_FailedCertVerif)
/* PRQA L:L1 */

/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
#   define Rte_Pim_LogDataEvnt1_FailedCertVerif_Mirror() (&((*RtePim_LogDataEvnt1_FailedCertVerif_Mirror())[0]))
#  else
#   define Rte_Pim_LogDataEvnt1_FailedCertVerif_Mirror() RtePim_LogDataEvnt1_FailedCertVerif_Mirror()
#  endif
#  define RtePim_LogDataEvnt1_FailedCertVerif_Mirror() \
  (&Rte_Ssa_SecLog_LogDataEvnt1_FailedCertVerif_Mirror)
/* PRQA L:L1 */

/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
#   define Rte_Pim_LogDataEvnt2_SucCertVerif() (&((*RtePim_LogDataEvnt2_SucCertVerif())[0]))
#  else
#   define Rte_Pim_LogDataEvnt2_SucCertVerif() RtePim_LogDataEvnt2_SucCertVerif()
#  endif
#  define RtePim_LogDataEvnt2_SucCertVerif() \
  (&Rte_Ssa_SecLog_LogDataEvnt2_SucCertVerif)
/* PRQA L:L1 */

/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
#   define Rte_Pim_LogDataEvnt2_SucCertVerif_Mirror() (&((*RtePim_LogDataEvnt2_SucCertVerif_Mirror())[0]))
#  else
#   define Rte_Pim_LogDataEvnt2_SucCertVerif_Mirror() RtePim_LogDataEvnt2_SucCertVerif_Mirror()
#  endif
#  define RtePim_LogDataEvnt2_SucCertVerif_Mirror() \
  (&Rte_Ssa_SecLog_LogDataEvnt2_SucCertVerif_Mirror)
/* PRQA L:L1 */

/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
#   define Rte_Pim_LogDataEvnt3_SucAuthAndEnhanceRights() (&((*RtePim_LogDataEvnt3_SucAuthAndEnhanceRights())[0]))
#  else
#   define Rte_Pim_LogDataEvnt3_SucAuthAndEnhanceRights() RtePim_LogDataEvnt3_SucAuthAndEnhanceRights()
#  endif
#  define RtePim_LogDataEvnt3_SucAuthAndEnhanceRights() \
  (&Rte_Ssa_SecLog_LogDataEvnt3_SucAuthAndEnhanceRights)
/* PRQA L:L1 */

/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
#   define Rte_Pim_LogDataEvnt3_SucAuthAndEnhanceRights_Mirror() (&((*RtePim_LogDataEvnt3_SucAuthAndEnhanceRights_Mirror())[0]))
#  else
#   define Rte_Pim_LogDataEvnt3_SucAuthAndEnhanceRights_Mirror() RtePim_LogDataEvnt3_SucAuthAndEnhanceRights_Mirror()
#  endif
#  define RtePim_LogDataEvnt3_SucAuthAndEnhanceRights_Mirror() \
  (&Rte_Ssa_SecLog_LogDataEvnt3_SucAuthAndEnhanceRights_Mirror)
/* PRQA L:L1 */

/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
#   define Rte_Pim_LogDataEvnt4_AuthBySecAccess() (&((*RtePim_LogDataEvnt4_AuthBySecAccess())[0]))
#  else
#   define Rte_Pim_LogDataEvnt4_AuthBySecAccess() RtePim_LogDataEvnt4_AuthBySecAccess()
#  endif
#  define RtePim_LogDataEvnt4_AuthBySecAccess() \
  (&Rte_Ssa_SecLog_LogDataEvnt4_AuthBySecAccess)
/* PRQA L:L1 */

/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
#   define Rte_Pim_LogDataEvnt4_AuthBySecAccess_Mirror() (&((*RtePim_LogDataEvnt4_AuthBySecAccess_Mirror())[0]))
#  else
#   define Rte_Pim_LogDataEvnt4_AuthBySecAccess_Mirror() RtePim_LogDataEvnt4_AuthBySecAccess_Mirror()
#  endif
#  define RtePim_LogDataEvnt4_AuthBySecAccess_Mirror() \
  (&Rte_Ssa_SecLog_LogDataEvnt4_AuthBySecAccess_Mirror)
/* PRQA L:L1 */

/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
#   define Rte_Pim_LogDataEvnt5_SucDiagServiceExec() (&((*RtePim_LogDataEvnt5_SucDiagServiceExec())[0]))
#  else
#   define Rte_Pim_LogDataEvnt5_SucDiagServiceExec() RtePim_LogDataEvnt5_SucDiagServiceExec()
#  endif
#  define RtePim_LogDataEvnt5_SucDiagServiceExec() \
  (&Rte_Ssa_SecLog_LogDataEvnt5_SucDiagServiceExec)
/* PRQA L:L1 */

/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
#   define Rte_Pim_LogDataEvnt5_SucDiagServiceExec_Mirror() (&((*RtePim_LogDataEvnt5_SucDiagServiceExec_Mirror())[0]))
#  else
#   define Rte_Pim_LogDataEvnt5_SucDiagServiceExec_Mirror() RtePim_LogDataEvnt5_SucDiagServiceExec_Mirror()
#  endif
#  define RtePim_LogDataEvnt5_SucDiagServiceExec_Mirror() \
  (&Rte_Ssa_SecLog_LogDataEvnt5_SucDiagServiceExec_Mirror)
/* PRQA L:L1 */

/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
#   define Rte_Pim_LogDataEvnt6_RightsMgmt() (&((*RtePim_LogDataEvnt6_RightsMgmt())[0]))
#  else
#   define Rte_Pim_LogDataEvnt6_RightsMgmt() RtePim_LogDataEvnt6_RightsMgmt()
#  endif
#  define RtePim_LogDataEvnt6_RightsMgmt() \
  (&Rte_Ssa_SecLog_LogDataEvnt6_RightsMgmt)
/* PRQA L:L1 */

/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
#   define Rte_Pim_LogDataEvnt6_RightsMgmt_Mirror() (&((*RtePim_LogDataEvnt6_RightsMgmt_Mirror())[0]))
#  else
#   define Rte_Pim_LogDataEvnt6_RightsMgmt_Mirror() RtePim_LogDataEvnt6_RightsMgmt_Mirror()
#  endif
#  define RtePim_LogDataEvnt6_RightsMgmt_Mirror() \
  (&Rte_Ssa_SecLog_LogDataEvnt6_RightsMgmt_Mirror)
/* PRQA L:L1 */

/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
#   define Rte_Pim_LogDataEvnt7_SigVerif() (&((*RtePim_LogDataEvnt7_SigVerif())[0]))
#  else
#   define Rte_Pim_LogDataEvnt7_SigVerif() RtePim_LogDataEvnt7_SigVerif()
#  endif
#  define RtePim_LogDataEvnt7_SigVerif() \
  (&Rte_Ssa_SecLog_LogDataEvnt7_SigVerif)
/* PRQA L:L1 */

/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
#   define Rte_Pim_LogDataEvnt7_SigVerif_Mirror() (&((*RtePim_LogDataEvnt7_SigVerif_Mirror())[0]))
#  else
#   define Rte_Pim_LogDataEvnt7_SigVerif_Mirror() RtePim_LogDataEvnt7_SigVerif_Mirror()
#  endif
#  define RtePim_LogDataEvnt7_SigVerif_Mirror() \
  (&Rte_Ssa_SecLog_LogDataEvnt7_SigVerif_Mirror)
/* PRQA L:L1 */

/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
#   define Rte_Pim_LogDataEvnt8_TickCountDateAndTime() (&((*RtePim_LogDataEvnt8_TickCountDateAndTime())[0]))
#  else
#   define Rte_Pim_LogDataEvnt8_TickCountDateAndTime() RtePim_LogDataEvnt8_TickCountDateAndTime()
#  endif
#  define RtePim_LogDataEvnt8_TickCountDateAndTime() \
  (&Rte_Ssa_SecLog_LogDataEvnt8_TickCountDateAndTime)
/* PRQA L:L1 */

/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
#   define Rte_Pim_LogDataEvnt8_TickCountDateAndTime_Mirror() (&((*RtePim_LogDataEvnt8_TickCountDateAndTime_Mirror())[0]))
#  else
#   define Rte_Pim_LogDataEvnt8_TickCountDateAndTime_Mirror() RtePim_LogDataEvnt8_TickCountDateAndTime_Mirror()
#  endif
#  define RtePim_LogDataEvnt8_TickCountDateAndTime_Mirror() \
  (&Rte_Ssa_SecLog_LogDataEvnt8_TickCountDateAndTime_Mirror)
/* PRQA L:L1 */

/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
#   define Rte_Pim_LogDataEvnt9_SecOcMisconfig() (&((*RtePim_LogDataEvnt9_SecOcMisconfig())[0]))
#  else
#   define Rte_Pim_LogDataEvnt9_SecOcMisconfig() RtePim_LogDataEvnt9_SecOcMisconfig()
#  endif
#  define RtePim_LogDataEvnt9_SecOcMisconfig() \
  (&Rte_Ssa_SecLog_LogDataEvnt9_SecOcMisconfig)
/* PRQA L:L1 */

/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
#   define Rte_Pim_LogDataEvnt9_SecOcMisconfig_Mirror() (&((*RtePim_LogDataEvnt9_SecOcMisconfig_Mirror())[0]))
#  else
#   define Rte_Pim_LogDataEvnt9_SecOcMisconfig_Mirror() RtePim_LogDataEvnt9_SecOcMisconfig_Mirror()
#  endif
#  define RtePim_LogDataEvnt9_SecOcMisconfig_Mirror() \
  (&Rte_Ssa_SecLog_LogDataEvnt9_SecOcMisconfig_Mirror)
/* PRQA L:L1 */

/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
#   define Rte_Pim_LogFailedMacVerifCount_ExceededTh1() (&((*RtePim_LogFailedMacVerifCount_ExceededTh1())[0]))
#  else
#   define Rte_Pim_LogFailedMacVerifCount_ExceededTh1() RtePim_LogFailedMacVerifCount_ExceededTh1()
#  endif
#  define RtePim_LogFailedMacVerifCount_ExceededTh1() \
  (&Rte_Ssa_SecLog_LogFailedMacVerifCount_ExceededTh1)
/* PRQA L:L1 */

/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
#   define Rte_Pim_LogFailedMacVerifCount_ExceededTh1_Mirror() (&((*RtePim_LogFailedMacVerifCount_ExceededTh1_Mirror())[0]))
#  else
#   define Rte_Pim_LogFailedMacVerifCount_ExceededTh1_Mirror() RtePim_LogFailedMacVerifCount_ExceededTh1_Mirror()
#  endif
#  define RtePim_LogFailedMacVerifCount_ExceededTh1_Mirror() \
  (&Rte_Ssa_SecLog_LogFailedMacVerifCount_ExceededTh1_Mirror)
/* PRQA L:L1 */

/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
#   define Rte_Pim_LogFailedMacVerifCount_ExceededTh2() (&((*RtePim_LogFailedMacVerifCount_ExceededTh2())[0]))
#  else
#   define Rte_Pim_LogFailedMacVerifCount_ExceededTh2() RtePim_LogFailedMacVerifCount_ExceededTh2()
#  endif
#  define RtePim_LogFailedMacVerifCount_ExceededTh2() \
  (&Rte_Ssa_SecLog_LogFailedMacVerifCount_ExceededTh2)
/* PRQA L:L1 */

/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
#   define Rte_Pim_LogFailedMacVerifCount_ExceededTh2_Mirror() (&((*RtePim_LogFailedMacVerifCount_ExceededTh2_Mirror())[0]))
#  else
#   define Rte_Pim_LogFailedMacVerifCount_ExceededTh2_Mirror() RtePim_LogFailedMacVerifCount_ExceededTh2_Mirror()
#  endif
#  define RtePim_LogFailedMacVerifCount_ExceededTh2_Mirror() \
  (&Rte_Ssa_SecLog_LogFailedMacVerifCount_ExceededTh2_Mirror)
/* PRQA L:L1 */

/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
#   define Rte_Pim_LogFailedMacVerifCount_ExceededTh3() (&((*RtePim_LogFailedMacVerifCount_ExceededTh3())[0]))
#  else
#   define Rte_Pim_LogFailedMacVerifCount_ExceededTh3() RtePim_LogFailedMacVerifCount_ExceededTh3()
#  endif
#  define RtePim_LogFailedMacVerifCount_ExceededTh3() \
  (&Rte_Ssa_SecLog_LogFailedMacVerifCount_ExceededTh3)
/* PRQA L:L1 */

/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
#   define Rte_Pim_LogFailedMacVerifCount_ExceededTh3_Mirror() (&((*RtePim_LogFailedMacVerifCount_ExceededTh3_Mirror())[0]))
#  else
#   define Rte_Pim_LogFailedMacVerifCount_ExceededTh3_Mirror() RtePim_LogFailedMacVerifCount_ExceededTh3_Mirror()
#  endif
#  define RtePim_LogFailedMacVerifCount_ExceededTh3_Mirror() \
  (&Rte_Ssa_SecLog_LogFailedMacVerifCount_ExceededTh3_Mirror)
/* PRQA L:L1 */


# endif /* !defined(RTE_CORE) */


# define Ssa_SecLog_START_SEC_CODE
# include "Ssa_SecLog_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

# ifndef RTE_CORE
#  define RTE_RUNNABLE_Ssa_SecLog_CSDataServices_DID_018B_SecOcDataID_ReadData Ssa_SecLog_CSDataServices_DID_018B_SecOcDataID_ReadData
#  define RTE_RUNNABLE_Ssa_SecLog_DataServices_Security_Event_Log_Current_Counter_Values_ConditionCheckRead Ssa_SecLog_DataServices_Security_Event_Log_Current_Counter_Values_ConditionCheckRead
#  define RTE_RUNNABLE_Ssa_SecLog_DataServices_Security_Event_Log_Current_Counter_Values_ReadData Ssa_SecLog_DataServices_Security_Event_Log_Current_Counter_Values_ReadData
#  define RTE_RUNNABLE_Ssa_SecLog_DataServices_Security_Event_Log_Current_Counter_Values_ReadDataLength Ssa_SecLog_DataServices_Security_Event_Log_Current_Counter_Values_ReadDataLength
#  define RTE_RUNNABLE_Ssa_SecLog_DataServices_Security_Event_Log_Read_Security_Event_Log_Entry_ConditionCheckRead Ssa_SecLog_DataServices_Security_Event_Log_Read_Security_Event_Log_Entry_ConditionCheckRead
#  define RTE_RUNNABLE_Ssa_SecLog_DataServices_Security_Event_Log_Read_Security_Event_Log_Entry_ReadData Ssa_SecLog_DataServices_Security_Event_Log_Read_Security_Event_Log_Entry_ReadData
#  define RTE_RUNNABLE_Ssa_SecLog_DataServices_Security_Event_Log_Read_Security_Event_Log_Entry_ReadDataLength Ssa_SecLog_DataServices_Security_Event_Log_Read_Security_Event_Log_Entry_ReadDataLength
#  define RTE_RUNNABLE_Ssa_SecLog_IgnitionStatusChanged Ssa_SecLog_IgnitionStatusChanged
#  define RTE_RUNNABLE_Ssa_SecLog_Init Ssa_SecLog_Init
#  define RTE_RUNNABLE_Ssa_SecLog_InitMonitorForEvent_DTC_0xD12083 Ssa_SecLog_InitMonitorForEvent_DTC_0xD12083
#  define RTE_RUNNABLE_Ssa_SecLog_LogEvent_AuthorizationBySecurityAccess Ssa_SecLog_LogEvent_AuthorizationBySecurityAccess
#  define RTE_RUNNABLE_Ssa_SecLog_LogEvent_ChangeTickCountOrDateAndTime Ssa_SecLog_LogEvent_ChangeTickCountOrDateAndTime
#  define RTE_RUNNABLE_Ssa_SecLog_LogEvent_ChangeVin Ssa_SecLog_LogEvent_ChangeVin
#  define RTE_RUNNABLE_Ssa_SecLog_LogEvent_EcuIndividualAclReplacement Ssa_SecLog_LogEvent_EcuIndividualAclReplacement
#  define RTE_RUNNABLE_Ssa_SecLog_LogEvent_FailedCertificateVerification Ssa_SecLog_LogEvent_FailedCertificateVerification
#  define RTE_RUNNABLE_Ssa_SecLog_LogEvent_FailedSecOcMacVerification Ssa_SecLog_LogEvent_FailedSecOcMacVerification
#  define RTE_RUNNABLE_Ssa_SecLog_LogEvent_FailedSecOcMacVerificationSecureBroadcast Ssa_SecLog_LogEvent_FailedSecOcMacVerificationSecureBroadcast
#  define RTE_RUNNABLE_Ssa_SecLog_LogEvent_RightsManagement Ssa_SecLog_LogEvent_RightsManagement
#  define RTE_RUNNABLE_Ssa_SecLog_LogEvent_SecureBootOrAuthenticatedBoot Ssa_SecLog_LogEvent_SecureBootOrAuthenticatedBoot
#  define RTE_RUNNABLE_Ssa_SecLog_LogEvent_SignatureVerification Ssa_SecLog_LogEvent_SignatureVerification
#  define RTE_RUNNABLE_Ssa_SecLog_LogEvent_SuccessfulAuthAndEnhanceRights Ssa_SecLog_LogEvent_SuccessfulAuthAndEnhanceRights
#  define RTE_RUNNABLE_Ssa_SecLog_LogEvent_SuccessfulCertificateVerification Ssa_SecLog_LogEvent_SuccessfulCertificateVerification
#  define RTE_RUNNABLE_Ssa_SecLog_LogEvent_SuccessfulDiagServiceExecution Ssa_SecLog_LogEvent_SuccessfulDiagServiceExecution
#  define RTE_RUNNABLE_Ssa_SecLog_MainFunction Ssa_SecLog_MainFunction
# endif

FUNC(Std_ReturnType, Ssa_SecLog_CODE) Ssa_SecLog_CSDataServices_DID_018B_SecOcDataID_ReadData(P2VAR(uint8, AUTOMATIC, RTE_SSA_SECLOG_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, Ssa_SecLog_CODE) Ssa_SecLog_DataServices_Security_Event_Log_Current_Counter_Values_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_SECLOG_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, Ssa_SecLog_CODE) Ssa_SecLog_DataServices_Security_Event_Log_Current_Counter_Values_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_SSA_SECLOG_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, Ssa_SecLog_CODE) Ssa_SecLog_DataServices_Security_Event_Log_Current_Counter_Values_ReadDataLength(Dcm_OpStatusType OpStatus, P2VAR(uint16, AUTOMATIC, RTE_SSA_SECLOG_APPL_VAR) DataLength); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, Ssa_SecLog_CODE) Ssa_SecLog_DataServices_Security_Event_Log_Read_Security_Event_Log_Entry_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_SECLOG_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, Ssa_SecLog_CODE) Ssa_SecLog_DataServices_Security_Event_Log_Read_Security_Event_Log_Entry_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_SSA_SECLOG_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, Ssa_SecLog_CODE) Ssa_SecLog_DataServices_Security_Event_Log_Read_Security_Event_Log_Entry_ReadDataLength(Dcm_OpStatusType OpStatus, P2VAR(uint16, AUTOMATIC, RTE_SSA_SECLOG_APPL_VAR) DataLength); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, Ssa_SecLog_CODE) Ssa_SecLog_IgnitionStatusChanged(void); /* PRQA S 3451, 0786, 3449 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449 */
FUNC(void, Ssa_SecLog_CODE) Ssa_SecLog_Init(void); /* PRQA S 3451, 0786, 3449 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449 */
FUNC(Std_ReturnType, Ssa_SecLog_CODE) Ssa_SecLog_InitMonitorForEvent_DTC_0xD12083(Dem_InitMonitorReasonType InitMonitorReason); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, Ssa_SecLog_CODE) Ssa_SecLog_LogEvent_AuthorizationBySecurityAccess(uint8 diagChanAuthStatus, uint8 securityLevel, uint8 securityAccessResult); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, Ssa_SecLog_CODE) Ssa_SecLog_LogEvent_ChangeTickCountOrDateAndTime(uint8 contextDateTimeChange, P2CONST(uint8, AUTOMATIC, RTE_SSA_SECLOG_APPL_DATA) deltaTimeChange); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, Ssa_SecLog_CODE) Ssa_SecLog_LogEvent_ChangeVin(P2CONST(uint8, AUTOMATIC, RTE_SSA_SECLOG_APPL_DATA) newVin); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, Ssa_SecLog_CODE) Ssa_SecLog_LogEvent_EcuIndividualAclReplacement(P2CONST(uint8, AUTOMATIC, RTE_SSA_SECLOG_APPL_DATA) newAclVersion, uint8 compatibility); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, Ssa_SecLog_CODE) Ssa_SecLog_LogEvent_FailedCertificateVerification(CertP_PkiRoleType pkiRole, CertP_VerificationResultType validationResult); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, Ssa_SecLog_CODE) Ssa_SecLog_LogEvent_FailedSecOcMacVerification(P2CONST(SecOC_VerificationStatusType, AUTOMATIC, RTE_SSA_SECLOG_APPL_DATA) verificationStatus); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, Ssa_SecLog_CODE) Ssa_SecLog_LogEvent_FailedSecOcMacVerificationSecureBroadcast(void); /* PRQA S 3451, 0786, 3449 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449 */
FUNC(Std_ReturnType, Ssa_SecLog_CODE) Ssa_SecLog_LogEvent_RightsManagement(uint8 diagChanAuthStatus, uint8 serviceId, uint8 subFunction, uint16 dataIdOrRoutineId); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, Ssa_SecLog_CODE) Ssa_SecLog_LogEvent_SecureBootOrAuthenticatedBoot(void); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, Ssa_SecLog_CODE) Ssa_SecLog_LogEvent_SignatureVerification(uint8 parg0, uint8 verificationResult); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, Ssa_SecLog_CODE) Ssa_SecLog_LogEvent_SuccessfulAuthAndEnhanceRights(uint8 diagChanAuthStatus, CertP_PkiRoleType pkiRole, P2CONST(uint8, AUTOMATIC, RTE_SSA_SECLOG_APPL_DATA) authenticationContent); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, Ssa_SecLog_CODE) Ssa_SecLog_LogEvent_SuccessfulCertificateVerification(P2CONST(uint8, AUTOMATIC, RTE_SSA_SECLOG_APPL_DATA) certId, CertP_PkiRoleType pkiRole); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, Ssa_SecLog_CODE) Ssa_SecLog_LogEvent_SuccessfulDiagServiceExecution(uint8 parg0, uint8 additionalInfo); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, Ssa_SecLog_CODE) Ssa_SecLog_MainFunction(void); /* PRQA S 3451, 0786, 3449 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449 */

# define Ssa_SecLog_STOP_SEC_CODE
# include "Ssa_SecLog_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Application errors
 *********************************************************************************************************************/

#  define RTE_E_CSDataServices_DID_018B_SecOcDataID_E_NOT_OK (1U)

#  define RTE_E_CallbackInitMonitorForEvent_E_NOT_OK (1U)

#  define RTE_E_DataServices_Security_Event_Log_Current_Counter_Values_Read_Security_Event_Log_Current_Counter_Values_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Security_Event_Log_Current_Counter_Values_Read_Security_Event_Log_Current_Counter_Values_E_NOT_OK (1U)

#  define RTE_E_DataServices_Security_Event_Log_Read_Security_Event_Log_Entry_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Security_Event_Log_Read_Security_Event_Log_Entry_E_NOT_OK (1U)

#  define RTE_E_DiagnosticMonitor_E_NOT_OK (1U)

#  define RTE_E_KeyM_Certificate_E_NOT_OK (1U)

#  define RTE_E_KeyM_Certificate_E_PENDING (10U)

#  define RTE_E_NvMService_AC2_SRBS_E_NOT_OK (1U)

#  define RTE_E_RightsM_DiagnosticChannel_E_NOT_OK (1U)

#  define RTE_E_SecLog_AuthorizationBySecurityAccess_E_NOT_OK (1U)

#  define RTE_E_SecLog_ChangeTickCountOrDateAndTimeEvent_E_NOT_OK (1U)

#  define RTE_E_SecLog_ChangeVinEvent_E_NOT_OK (1U)

#  define RTE_E_SecLog_EcuIndividualAclReplacementEvent_E_NOT_OK (1U)

#  define RTE_E_SecLog_FailedCertVerificationEvent_E_NOT_OK (1U)

#  define RTE_E_SecLog_RightsManagementEvent_E_NOT_OK (1U)

#  define RTE_E_SecLog_SecureBootOrAuthenticatedBootEvent_E_NOT_OK (1U)

#  define RTE_E_SecLog_SignatureVerificationEvent_E_NOT_OK (1U)

#  define RTE_E_SecLog_SuccessfulAuthAndEnhanceRights_E_NOT_OK (1U)

#  define RTE_E_SecLog_SuccessfulCertVerificationEvent_E_NOT_OK (1U)

#  define RTE_E_SecLog_SuccessfulDiagServiceExecutionEvent_E_NOT_OK (1U)

#  define RTE_E_TimeM_RealTime_E_NOT_OK (1U)

#  define RTE_E_TimeM_TickCount_E_NOT_OK (1U)

#  define RTE_E_VerificationStatusIndication_E_NOT_OK (1U)

#  define RTE_E_VerificationStatusIndication_E_OK (0U)
# endif /* !defined(RTE_CORE) */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* RTE_SSA_SECLOG_H */

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
