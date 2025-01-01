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
 *             File:  Rte_ERH_AC_ErrorHandler.h
 *           Config:  StartApplication.dpa
 *      ECU-Project:  StartApplication
 *
 *        Generator:  MICROSAR RTE Generator Version 4.32.0
 *                    RTE Core Version 4.32.0
 *          License:  CBD2200333
 *
 *      Description:  Application header file for SW-C <ERH_AC_ErrorHandler>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef RTE_ERH_AC_ERRORHANDLER_H
# define RTE_ERH_AC_ERRORHANDLER_H

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

# include "Rte_ERH_AC_ErrorHandler_Type.h"
# include "Rte_DataHandleType.h"

# ifndef RTE_CORE

/**********************************************************************************************************************
 * extern declaration of RTE buffers for optimized macro implementation
 *********************************************************************************************************************/
#  define RTE_START_SEC_VAR_NOINIT_UNSPECIFIED
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern VAR(b8BooleanType, RTE_VAR_NOINIT) Rte_ERH_psrDTCConfirmed_b8DTCConfirmed;
extern VAR(uint8, RTE_VAR_NOINIT) Rte_ERH_psrSnapshotData_u8SnapshotAecId;
extern VAR(b8BooleanType, RTE_VAR_NOINIT) Rte_PMP_isrSupBatStatus_b8SupBatStatus;
extern VAR(b8BooleanType, RTE_VAR_NOINIT) Rte_CIL_psrEngStartStatus_b8EngStartStatus;
extern VAR(b8BooleanType, RTE_VAR_NOINIT) Rte_CIL_psrIgnitionStatus_b8TriggerIgnitionStatus;
extern VAR(b8BooleanType, RTE_VAR_NOINIT) Rte_CIL_psrIgnitionStatus_b8TriggerIgnitionStatusEnableStorageCondition;
extern VAR(b8BooleanType, RTE_VAR_NOINIT) Rte_CIL_psrProdModeStatus_b8TriggerProdModeStatus;
extern VAR(b8BooleanType, RTE_VAR_NOINIT) Rte_CIL_psrTransportationModeStatus_b8TransportationModeStatus;

#  define RTE_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

# endif /* !defined(RTE_CORE) */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

#  define Rte_InitValue_isrSupBatStatus_b8SupBatStatus (85U)
#  define Rte_InitValue_prrEngStartStatus_b8EngStartStatus (85U)
#  define Rte_InitValue_prrIgnitionStatus_b8TriggerIgnitionStatus (85U)
#  define Rte_InitValue_prrIgnitionStatus_b8TriggerIgnitionStatusEnableStorageCondition (85U)
#  define Rte_InitValue_prrProdModeStatus_b8TriggerProdModeStatus (170U)
#  define Rte_InitValue_prrTransportationModeStatus_b8TransportationModeStatus (170U)
#  define Rte_InitValue_psrDTCConfirmed_b8DTCConfirmed (85U)
#  define Rte_InitValue_psrDTCConfirmed_b8ExtTesterPresent (85U)
#  define Rte_InitValue_psrSnapshotData_u8SnapshotAecId (255U)
# endif


# define RTE_START_SEC_CODE
# include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ERH_AC_ErrorHandler_psrAECsBlockStatus_b8NVMBlockStatus(b8BooleanType data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(uint8, RTE_CODE) Rte_Mode_ERH_AC_ErrorHandler_prrControlAECSetting_DcmControlDtcSetting(void);

# define RTE_STOP_SEC_CODE
# include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# ifndef RTE_CORE

/**********************************************************************************************************************
 * Rte_Read_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Read_isrSupBatStatus_b8SupBatStatus Rte_Read_ERH_AC_ErrorHandler_isrSupBatStatus_b8SupBatStatus
#  define Rte_Read_ERH_AC_ErrorHandler_isrSupBatStatus_b8SupBatStatus(data) (*(data) = Rte_PMP_isrSupBatStatus_b8SupBatStatus, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_prrEngStartStatus_b8EngStartStatus Rte_Read_ERH_AC_ErrorHandler_prrEngStartStatus_b8EngStartStatus
#  define Rte_Read_ERH_AC_ErrorHandler_prrEngStartStatus_b8EngStartStatus(data) (*(data) = Rte_CIL_psrEngStartStatus_b8EngStartStatus, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_prrIgnitionStatus_b8TriggerIgnitionStatus Rte_Read_ERH_AC_ErrorHandler_prrIgnitionStatus_b8TriggerIgnitionStatus
#  define Rte_Read_ERH_AC_ErrorHandler_prrIgnitionStatus_b8TriggerIgnitionStatus(data) (*(data) = Rte_CIL_psrIgnitionStatus_b8TriggerIgnitionStatus, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_prrIgnitionStatus_b8TriggerIgnitionStatusEnableStorageCondition Rte_Read_ERH_AC_ErrorHandler_prrIgnitionStatus_b8TriggerIgnitionStatusEnableStorageCondition
#  define Rte_Read_ERH_AC_ErrorHandler_prrIgnitionStatus_b8TriggerIgnitionStatusEnableStorageCondition(data) (*(data) = Rte_CIL_psrIgnitionStatus_b8TriggerIgnitionStatusEnableStorageCondition, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_prrProdModeStatus_b8TriggerProdModeStatus Rte_Read_ERH_AC_ErrorHandler_prrProdModeStatus_b8TriggerProdModeStatus
#  define Rte_Read_ERH_AC_ErrorHandler_prrProdModeStatus_b8TriggerProdModeStatus(data) (*(data) = Rte_CIL_psrProdModeStatus_b8TriggerProdModeStatus, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_prrTransportationModeStatus_b8TransportationModeStatus Rte_Read_ERH_AC_ErrorHandler_prrTransportationModeStatus_b8TransportationModeStatus
#  define Rte_Read_ERH_AC_ErrorHandler_prrTransportationModeStatus_b8TransportationModeStatus(data) (*(data) = Rte_CIL_psrTransportationModeStatus_b8TransportationModeStatus, ((Std_ReturnType)RTE_E_OK))


/**********************************************************************************************************************
 * Rte_Write_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Write_psrAECsBlockStatus_b8NVMBlockStatus Rte_Write_ERH_AC_ErrorHandler_psrAECsBlockStatus_b8NVMBlockStatus
#  define Rte_Write_psrDTCConfirmed_b8DTCConfirmed Rte_Write_ERH_AC_ErrorHandler_psrDTCConfirmed_b8DTCConfirmed
#  define Rte_Write_ERH_AC_ErrorHandler_psrDTCConfirmed_b8DTCConfirmed(data) (Rte_ERH_psrDTCConfirmed_b8DTCConfirmed = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_psrSnapshotData_u8SnapshotAecId Rte_Write_ERH_AC_ErrorHandler_psrSnapshotData_u8SnapshotAecId
#  define Rte_Write_ERH_AC_ErrorHandler_psrSnapshotData_u8SnapshotAecId(data) (Rte_ERH_psrSnapshotData_u8SnapshotAecId = (data), ((Std_ReturnType)RTE_E_OK))


/**********************************************************************************************************************
 * Rte_Mode_<p>_<m>
 *********************************************************************************************************************/
#  define Rte_Mode_prrControlAECSetting_DcmControlDtcSetting Rte_Mode_ERH_AC_ErrorHandler_prrControlAECSetting_DcmControlDtcSetting


/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (unmapped) for synchronous C/S communication
 *********************************************************************************************************************/
#  define RTE_START_SEC_ATM_AC_AUTOTESTMANAGER_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FUNC(void, RTE_ATM_AC_AUTOTESTMANAGER_APPL_CODE) ATM_runGetTestResult(u8AutoTestIdType u8AutoTestId, P2VAR(u8TestResultType, AUTOMATIC, RTE_ATM_AC_AUTOTESTMANAGER_APPL_VAR) u8TestResult); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */

#  define RTE_STOP_SEC_ATM_AC_AUTOTESTMANAGER_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define RTE_START_SEC_COMM_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FUNC(Std_ReturnType, RTE_COMM_APPL_CODE) ComM_GetCurrentComMode(ComM_UserHandleType parg0, P2VAR(ComM_ModeType, AUTOMATIC, RTE_COMM_APPL_VAR) ComMode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */

#  define RTE_STOP_SEC_COMM_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define RTE_START_SEC_DEMMASTER_0_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FUNC(Std_ReturnType, RTE_DEMMASTER_0_APPL_CODE) Dem_SetOperationCycleState(uint8 parg0, Dem_OperationCycleStateType CycleState); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_DEMMASTER_0_APPL_CODE) Dem_SetStorageCondition(uint8 parg0, boolean ConditionFulfilled); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_DEMMASTER_0_APPL_CODE) Dem_GetEventUdsStatus(Dem_EventIdType EventId, P2VAR(Dem_UdsStatusByteType, AUTOMATIC, RTE_DEMMASTER_0_APPL_VAR) UDSStatusByte); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */

#  define RTE_STOP_SEC_DEMMASTER_0_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define RTE_START_SEC_DEMSATELLITE_0_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FUNC(Std_ReturnType, RTE_DEMSATELLITE_0_APPL_CODE) Dem_SetEventStatus(Dem_EventIdType parg0, Dem_EventStatusType EventStatus); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */

#  define RTE_STOP_SEC_DEMSATELLITE_0_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define RTE_START_SEC_NVM_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FUNC(Std_ReturnType, RTE_NVM_APPL_CODE) NvM_EraseNvBlock(NvM_BlockIdType parg0); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_NVM_APPL_CODE) NvM_GetErrorStatus(NvM_BlockIdType parg0, P2VAR(NvM_RequestResultType, AUTOMATIC, RTE_NVM_APPL_VAR) ErrorStatus); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_NVM_APPL_CODE) NvM_InvalidateNvBlock(NvM_BlockIdType parg0); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_NVM_APPL_CODE) NvM_ReadBlock(NvM_BlockIdType parg0, dtRef_VOID DstPtr); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_NVM_APPL_CODE) NvM_RestoreBlockDefaults(NvM_BlockIdType parg0, dtRef_VOID DstPtr); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_NVM_APPL_CODE) NvM_SetRamBlockStatus(NvM_BlockIdType parg0, boolean RamBlockStatus); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_NVM_APPL_CODE) NvM_WriteBlock(NvM_BlockIdType parg0, dtRef_const_VOID SrcPtr); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */

#  define RTE_STOP_SEC_NVM_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define Rte_Call_DTC_0x10d00_SetEventStatus(arg1) (Dem_SetEventStatus((Dem_EventIdType)6, arg1))
#  define Rte_Call_DTC_0x10e00_SetEventStatus(arg1) (Dem_SetEventStatus((Dem_EventIdType)7, arg1))
#  define Rte_Call_DTC_0x12287_SetEventStatus(arg1) (Dem_SetEventStatus((Dem_EventIdType)20, arg1))
#  define Rte_Call_DTC_0x15187_SetEventStatus(arg1) (Dem_SetEventStatus((Dem_EventIdType)21, arg1))
#  define Rte_Call_DTC_0x1ca000_SetEventStatus(arg1) (Dem_SetEventStatus((Dem_EventIdType)1, arg1))
#  define Rte_Call_DTC_0x28b16_SetEventStatus(arg1) (Dem_SetEventStatus((Dem_EventIdType)9, arg1))
#  define Rte_Call_DTC_0x28b17_SetEventStatus(arg1) (Dem_SetEventStatus((Dem_EventIdType)10, arg1))
#  define Rte_Call_DTC_0x28b45_SetEventStatus(arg1) (Dem_SetEventStatus((Dem_EventIdType)11, arg1))
#  define Rte_Call_DTC_0x28b47_SetEventStatus(arg1) (Dem_SetEventStatus((Dem_EventIdType)12, arg1))
#  define Rte_Call_DTC_0x28b49_SetEventStatus(arg1) (Dem_SetEventStatus((Dem_EventIdType)13, arg1))
#  define Rte_Call_DTC_0x28b4b_SetEventStatus(arg1) (Dem_SetEventStatus((Dem_EventIdType)8, arg1))
#  define Rte_Call_DTC_0x28b71_SetEventStatus(arg1) (Dem_SetEventStatus((Dem_EventIdType)14, arg1))
#  define Rte_Call_DTC_0x28b96_SetEventStatus(arg1) (Dem_SetEventStatus((Dem_EventIdType)15, arg1))
#  define Rte_Call_DTC_0x28b97_SetEventStatus(arg1) (Dem_SetEventStatus((Dem_EventIdType)16, arg1))
#  define Rte_Call_DTC_0x28bfa_SetEventStatus(arg1) (Dem_SetEventStatus((Dem_EventIdType)17, arg1))
#  define Rte_Call_DTC_0x41608_SetEventStatus(arg1) (Dem_SetEventStatus((Dem_EventIdType)26, arg1))
#  define Rte_Call_DTC_0x42708_SetEventStatus(arg1) (Dem_SetEventStatus((Dem_EventIdType)27, arg1))
#  define Rte_Call_DTC_0x45208_SetEventStatus(arg1) (Dem_SetEventStatus((Dem_EventIdType)29, arg1))
#  define Rte_Call_DTC_0xa10a00_SetEventStatus(arg1) (Dem_SetEventStatus((Dem_EventIdType)4, arg1))
#  define Rte_Call_DTC_0xa10b00_SetEventStatus(arg1) (Dem_SetEventStatus((Dem_EventIdType)5, arg1))
#  define Rte_Call_DTC_0xa20400_SetEventStatus(arg1) (Dem_SetEventStatus((Dem_EventIdType)18, arg1))
#  define Rte_Call_DTC_0xc11587_SetEventStatus(arg1) (Dem_SetEventStatus((Dem_EventIdType)19, arg1))
#  define Rte_Call_DTC_0xc15587_SetEventStatus(arg1) (Dem_SetEventStatus((Dem_EventIdType)22, arg1))
#  define Rte_Call_DTC_0xc16887_SetEventStatus(arg1) (Dem_SetEventStatus((Dem_EventIdType)23, arg1))
#  define Rte_Call_DTC_0xc20187_SetEventStatus(arg1) (Dem_SetEventStatus((Dem_EventIdType)24, arg1))
#  define Rte_Call_DTC_0xc20287_SetEventStatus(arg1) (Dem_SetEventStatus((Dem_EventIdType)25, arg1))
#  define Rte_Call_DTC_0xc44286_SetEventStatus(arg1) (Dem_SetEventStatus((Dem_EventIdType)28, arg1))
#  define Rte_Call_DTC_0xd88987_SetEventStatus(arg1) (Dem_SetEventStatus((Dem_EventIdType)34, arg1))
#  define Rte_Call_DTC_0xd88a08_SetEventStatus(arg1) (Dem_SetEventStatus((Dem_EventIdType)35, arg1))
#  define Rte_Call_pclNvmServicesAecBlock_EraseBlock() (NvM_EraseNvBlock((NvM_BlockIdType)81))
#  define Rte_Call_pclNvmServicesAecBlock_GetErrorStatus(arg1) (NvM_GetErrorStatus((NvM_BlockIdType)81, arg1))
#  define Rte_Call_pclNvmServicesAecBlock_InvalidateNvBlock() (NvM_InvalidateNvBlock((NvM_BlockIdType)81))
#  define Rte_Call_pclNvmServicesAecBlock_ReadBlock(arg1) (NvM_ReadBlock((NvM_BlockIdType)81, arg1))
#  define Rte_Call_pclNvmServicesAecBlock_RestoreBlockDefaults(arg1) (NvM_RestoreBlockDefaults((NvM_BlockIdType)81, arg1))
#  define Rte_Call_pclNvmServicesAecBlock_SetRamBlockStatus(arg1) (NvM_SetRamBlockStatus((NvM_BlockIdType)81, arg1))
#  define Rte_Call_pclNvmServicesAecBlock_WriteBlock(arg1) (NvM_WriteBlock((NvM_BlockIdType)81, arg1))
#  define Rte_Call_pclOperationCycle_SetOperationCycleState(arg1) (Dem_SetOperationCycleState((uint8)0, arg1))
#  define Rte_Call_pclStorageConditionSC1_SetStorageCondition(arg1) (Dem_SetStorageCondition((uint8)0, arg1))
#  define Rte_Call_pclStorageConditionSC10_0_SetStorageCondition(arg1) (Dem_SetStorageCondition((uint8)6, arg1))
#  define Rte_Call_pclStorageConditionSC10_1_SetStorageCondition(arg1) (Dem_SetStorageCondition((uint8)7, arg1))
#  define Rte_Call_pclStorageConditionSC10_2_SetStorageCondition(arg1) (Dem_SetStorageCondition((uint8)8, arg1))
#  define Rte_Call_pclStorageConditionSC11_SetStorageCondition(arg1) (Dem_SetStorageCondition((uint8)9, arg1))
#  define Rte_Call_pclStorageConditionSC12_SetStorageCondition(arg1) (Dem_SetStorageCondition((uint8)10, arg1))
#  define Rte_Call_pclStorageConditionSC2_SetStorageCondition(arg1) (Dem_SetStorageCondition((uint8)1, arg1))
#  define Rte_Call_pclStorageConditionSC3_SetStorageCondition(arg1) (Dem_SetStorageCondition((uint8)2, arg1))
#  define Rte_Call_pclStorageConditionSC4_SetStorageCondition(arg1) (Dem_SetStorageCondition((uint8)3, arg1))
#  define Rte_Call_pclStorageConditionSC5_SetStorageCondition(arg1) (Dem_SetStorageCondition((uint8)4, arg1))
#  define Rte_Call_pclStorageConditionSC8_SetStorageCondition(arg1) (Dem_SetStorageCondition((uint8)5, arg1))
#  define Rte_Call_pcl_GetDTCStatus_GetEventStatus Dem_GetEventUdsStatus
#  define Rte_Call_pcsAutotestServices_GetTestResult(arg1, arg2) (ATM_runGetTestResult(arg1, arg2), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Call_pcsGetComMStatus_GetCurrentComMode(arg1) (ComM_GetCurrentComMode((ComM_UserHandleType)0, arg1))

# endif /* !defined(RTE_CORE) */


# define ERH_AC_ErrorHandler_START_SEC_CODE
# include "ERH_AC_ErrorHandler_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

# ifndef RTE_CORE
#  define RTE_RUNNABLE_ERH_Init ERH_Init
#  define RTE_RUNNABLE_ERH_cyclic ERH_cyclic
#  define RTE_RUNNABLE_ERH_runGetAecDeskillThrs ERH_runGetAecDeskillThrs
#  define RTE_RUNNABLE_ERH_runGetAecGroupsStatus ERH_runGetAecGroupsStatus
#  define RTE_RUNNABLE_ERH_runGetAecNvpBlockRecordingStatus ERH_runGetAecNvpBlockRecordingStatus
#  define RTE_RUNNABLE_ERH_runGetAecQualificationCount ERH_runGetAecQualificationCount
#  define RTE_RUNNABLE_ERH_runGetAecStatus ERH_runGetAecStatus
#  define RTE_RUNNABLE_ERH_runGetNumberOfImplementedAec ERH_runGetNumberOfImplementedAec
#  define RTE_RUNNABLE_ERH_runSetAecEvent ERH_runSetAecEvent
#  define RTE_RUNNABLE_ERH_runStoreEverQualifiedAECsToNVP ERH_runStoreEverQualifiedAECsToNVP
# endif

FUNC(void, ERH_AC_ErrorHandler_CODE) ERH_Init(void); /* PRQA S 3451, 0786, 3449 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449 */
FUNC(void, ERH_AC_ErrorHandler_CODE) ERH_cyclic(void); /* PRQA S 3451, 0786, 3449 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449 */
FUNC(void, ERH_AC_ErrorHandler_CODE) ERH_runGetAecDeskillThrs(u8AecIdentifierType u8AecId, P2VAR(UInt16, AUTOMATIC, RTE_ERH_AC_ERRORHANDLER_APPL_VAR) pu16AecDeskillThrs); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, ERH_AC_ErrorHandler_CODE) ERH_runGetAecGroupsStatus(P2VAR(u32AecGroupsType, AUTOMATIC, RTE_ERH_AC_ERRORHANDLER_APPL_VAR) pu32AecGroupsStatus); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, ERH_AC_ErrorHandler_CODE) ERH_runGetAecNvpBlockRecordingStatus(P2VAR(b8BooleanType, AUTOMATIC, RTE_ERH_AC_ERRORHANDLER_APPL_VAR) b8AecNvpBlockRecordingStatus); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, ERH_AC_ErrorHandler_CODE) ERH_runGetAecQualificationCount(UInt8 u8AecId, P2VAR(UInt8, AUTOMATIC, RTE_ERH_AC_ERRORHANDLER_APPL_VAR) pu8AecQualificationCount); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, ERH_AC_ErrorHandler_CODE) ERH_runGetAecStatus(u8AecIdentifierType u8AecIdentifier, P2VAR(u8AecStatusType, AUTOMATIC, RTE_ERH_AC_ERRORHANDLER_APPL_VAR) pu8AecStatus); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, ERH_AC_ErrorHandler_CODE) ERH_runGetNumberOfImplementedAec(P2VAR(UInt8, AUTOMATIC, RTE_ERH_AC_ERRORHANDLER_APPL_VAR) pu8NbOfAec); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, ERH_AC_ErrorHandler_CODE) ERH_runSetAecEvent(u8AecIdentifierType u8AecIdentifier, u8AecCommandType u8Command); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, ERH_AC_ErrorHandler_CODE) ERH_runStoreEverQualifiedAECsToNVP(void); /* PRQA S 3451, 0786, 3449 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449 */

# define ERH_AC_ErrorHandler_STOP_SEC_CODE
# include "ERH_AC_ErrorHandler_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Application errors
 *********************************************************************************************************************/

#  define RTE_E_ComM_UserRequest_E_NOT_OK (1U)

#  define RTE_E_DiagnosticMonitor_E_NOT_OK (1U)

#  define RTE_E_GeneralDiagnosticInfo_E_NOT_OK (1U)

#  define RTE_E_NvMService_AC3_SRBS_Defs_E_NOT_OK (1U)

#  define RTE_E_OperationCycle_E_NOT_OK (1U)

#  define RTE_E_StorageCondition_E_NOT_OK (1U)
# endif /* !defined(RTE_CORE) */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* RTE_ERH_AC_ERRORHANDLER_H */

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
