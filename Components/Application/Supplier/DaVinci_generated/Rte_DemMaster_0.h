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
 *             File:  Rte_DemMaster_0.h
 *           Config:  StartApplication.dpa
 *      ECU-Project:  StartApplication
 *
 *        Generator:  MICROSAR RTE Generator Version 4.32.0
 *                    RTE Core Version 4.32.0
 *          License:  CBD2200333
 *
 *      Description:  Application header file for SW-C <DemMaster_0>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef RTE_DEMMASTER_0_H
# define RTE_DEMMASTER_0_H

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

# include "Rte_DemMaster_0_Type.h"
# include "Rte_DataHandleType.h"


# define RTE_START_SEC_CODE
# include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_DemMaster_0_CBReadData_Data_DID_0x133_Operating_Time_Status_ReadData(P2VAR(DataPrimitiveType_uint8, AUTOMATIC, RTE_DEMMASTER_0_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_DemMaster_0_DemSc_GetCurrentOdometer(P2VAR(uint32, AUTOMATIC, RTE_DEMMASTER_0_APPL_VAR) Odometer); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_DemMaster_0_DemSc_GetExternalTesterStatus(P2VAR(boolean, AUTOMATIC, RTE_DEMMASTER_0_APPL_VAR) TesterPresent); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */

# define RTE_STOP_SEC_CODE
# include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# ifndef RTE_CORE

/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (unmapped) for synchronous C/S communication
 *********************************************************************************************************************/
#  define RTE_START_SEC_DIAGFUNCTION_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FUNC(Std_ReturnType, RTE_DIAGFUNCTION_APPL_CODE) Snapshot_DataServices_Data_DID_0x10a_Vehicle_Odometer_in_Low_Resolution(P2VAR(DataPrimitiveType_uint16, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_DIAGFUNCTION_APPL_CODE) Snapshot_DataServices_Data_DID_0x133_Current_Operating_Time(P2VAR(DataPrimitiveType_uint32, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_DIAGFUNCTION_APPL_CODE) Snapshot_DataServices_Data_DID_0xfd05_Root_Causes(P2VAR(DataPrimitiveType_uint8, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_DIAGFUNCTION_APPL_CODE) RoELight_DTCStatusChanged_Callback(uint32 DTC, Dem_UdsStatusByteType DTCStatusOld, Dem_UdsStatusByteType DTCStatusNew); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */

#  define RTE_STOP_SEC_DIAGFUNCTION_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define RTE_START_SEC_SSA_CODING_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FUNC(Std_ReturnType, RTE_SSA_CODING_APPL_CODE) Ssa_Coding_InitMonitorForEvent_DTC_0x164456(Dem_InitMonitorReasonType InitMonitorReason); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */

#  define RTE_STOP_SEC_SSA_CODING_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define RTE_START_SEC_SSA_FVM_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FUNC(Std_ReturnType, RTE_SSA_FVM_APPL_CODE) Ssa_FvM_InitMonitorForEvent_DTC_0xD12081(Dem_InitMonitorReasonType InitMonitorReason); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_SSA_FVM_APPL_CODE) Ssa_FvM_InitMonitorForEvent_DTC_0xD12087(Dem_InitMonitorReasonType InitMonitorReason); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */

#  define RTE_STOP_SEC_SSA_FVM_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define RTE_START_SEC_SSA_SECLOG_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FUNC(Std_ReturnType, RTE_SSA_SECLOG_APPL_CODE) Ssa_SecLog_InitMonitorForEvent_DTC_0xD12083(Dem_InitMonitorReasonType InitMonitorReason); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_SSA_SECLOG_APPL_CODE) Ssa_SecLog_CSDataServices_DID_018B_SecOcDataID_ReadData(P2VAR(uint8, AUTOMATIC, RTE_SSA_SECLOG_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_SSA_SECLOG_APPL_CODE) Ssa_SecLog_CSDataServices_DID_018B_SecOcDataID_ReadData(P2VAR(DataArrayType_uint8_2, AUTOMATIC, RTE_SSA_SECLOG_APPL_VAR) Data); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif

#  define RTE_STOP_SEC_SSA_SECLOG_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define Rte_Call_CBInitEvt_DTC_0x164456_InitMonitorForEvent Ssa_Coding_InitMonitorForEvent_DTC_0x164456
#  define Rte_Call_CBInitEvt_DTC_0xd12081_InitMonitorForEvent Ssa_FvM_InitMonitorForEvent_DTC_0xD12081
#  define Rte_Call_CBInitEvt_DTC_0xd12083_InitMonitorForEvent Ssa_SecLog_InitMonitorForEvent_DTC_0xD12083
#  define Rte_Call_CBInitEvt_DTC_0xd12087_InitMonitorForEvent Ssa_FvM_InitMonitorForEvent_DTC_0xD12087
#  define Rte_Call_CBReadData_Data_DID_0x10a_Vehicle_Odometer_in_Low_Resolution_ReadData Snapshot_DataServices_Data_DID_0x10a_Vehicle_Odometer_in_Low_Resolution
#  define Rte_Call_CBReadData_Data_DID_0x133_Current_Operating_Time_ReadData Snapshot_DataServices_Data_DID_0x133_Current_Operating_Time
#  define Rte_Call_CBReadData_Data_DID_0x133_Operating_Time_Status_ReadData Rte_Call_DemMaster_0_CBReadData_Data_DID_0x133_Operating_Time_Status_ReadData
#  define Rte_Call_CBReadData_Data_DID_0x18b_SecOcDataID_ReadData Ssa_SecLog_CSDataServices_DID_018B_SecOcDataID_ReadData
#  define Rte_Call_CBReadData_Data_DID_0xfd05_Root_Causes_ReadData Snapshot_DataServices_Data_DID_0xfd05_Root_Causes
#  define Rte_Call_CBStatusDTC_RoELight_DTCStatusChanged RoELight_DTCStatusChanged_Callback
#  define Rte_Call_DemSc_GetCurrentOdometer Rte_Call_DemMaster_0_DemSc_GetCurrentOdometer
#  define Rte_Call_DemSc_GetExternalTesterStatus Rte_Call_DemMaster_0_DemSc_GetExternalTesterStatus

# endif /* !defined(RTE_CORE) */


# define DemMaster_0_START_SEC_CODE
# include "DemMaster_0_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

# ifndef RTE_CORE
#  define RTE_RUNNABLE_ClearDTC Dem_ClearDTC
#  define RTE_RUNNABLE_Dem_MasterMainFunction Dem_MasterMainFunction
#  define RTE_RUNNABLE_GetDTCOfEvent Dem_GetDTCOfEvent
#  define RTE_RUNNABLE_GetDTCStatusAvailabilityMask Dem_GetDTCStatusAvailabilityMask
#  define RTE_RUNNABLE_GetDTCSuppression Dem_GetDTCSuppression
#  define RTE_RUNNABLE_GetDebouncingOfEvent Dem_GetDebouncingOfEvent
#  define RTE_RUNNABLE_GetEventEnableCondition Dem_GetEventEnableCondition
#  define RTE_RUNNABLE_GetEventExtendedDataRecordEx Dem_GetEventExtendedDataRecordEx
#  define RTE_RUNNABLE_GetEventFailed Dem_GetEventFailed
#  define RTE_RUNNABLE_GetEventFreezeFrameDataEx Dem_GetEventFreezeFrameDataEx
#  define RTE_RUNNABLE_GetEventMemoryOverflow Dem_GetEventMemoryOverflow
#  define RTE_RUNNABLE_GetEventStatus Dem_GetEventUdsStatus
#  define RTE_RUNNABLE_GetEventTested Dem_GetEventTested
#  define RTE_RUNNABLE_GetEventUdsStatus Dem_GetEventUdsStatus
#  define RTE_RUNNABLE_GetFaultDetectionCounter Dem_GetFaultDetectionCounter
#  define RTE_RUNNABLE_GetIndicatorStatus Dem_GetIndicatorStatus
#  define RTE_RUNNABLE_GetMonitorStatus Dem_GetMonitorStatus
#  define RTE_RUNNABLE_GetNumberOfEventMemoryEntries Dem_GetNumberOfEventMemoryEntries
#  define RTE_RUNNABLE_GetOperationCycleState Dem_GetOperationCycleState
#  define RTE_RUNNABLE_PostRunRequested Dem_PostRunRequested
#  define RTE_RUNNABLE_SelectDTC Dem_SelectDTC
#  define RTE_RUNNABLE_SetDTCSuppression Dem_SetDTCSuppression
#  define RTE_RUNNABLE_SetEnableCondition Dem_SetEnableCondition
#  define RTE_RUNNABLE_SetOperationCycleState Dem_SetOperationCycleState
#  define RTE_RUNNABLE_SetStorageCondition Dem_SetStorageCondition
# endif

FUNC(Std_ReturnType, DemMaster_0_CODE) Dem_ClearDTC(uint8 parg0); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, DemMaster_0_CODE) Dem_MasterMainFunction(void); /* PRQA S 3451, 0786, 3449 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449 */
FUNC(Std_ReturnType, DemMaster_0_CODE) Dem_GetDTCOfEvent(Dem_EventIdType EventId, Dem_DTCFormatType DTCFormat, P2VAR(uint32, AUTOMATIC, RTE_DEMMASTER_0_APPL_VAR) DTCOfEvent); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, DemMaster_0_CODE) Dem_GetDTCStatusAvailabilityMask(uint8 ClientId, P2VAR(uint8, AUTOMATIC, RTE_DEMMASTER_0_APPL_VAR) DTCStatusMask); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, DemMaster_0_CODE) Dem_GetDTCSuppression(uint8 parg0, P2VAR(boolean, AUTOMATIC, RTE_DEMMASTER_0_APPL_VAR) SuppressionStatus); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, DemMaster_0_CODE) Dem_GetDebouncingOfEvent(Dem_EventIdType EventId, P2VAR(Dem_DebouncingStateType, AUTOMATIC, RTE_DEMMASTER_0_APPL_VAR) DebouncingState); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, DemMaster_0_CODE) Dem_GetEventEnableCondition(Dem_EventIdType EventId, P2VAR(boolean, AUTOMATIC, RTE_DEMMASTER_0_APPL_VAR) ConditionFullfilled); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, DemMaster_0_CODE) Dem_GetEventExtendedDataRecordEx(Dem_EventIdType EventId, uint8 RecordNumber, P2VAR(uint8, AUTOMATIC, RTE_DEMMASTER_0_APPL_VAR) DestBuffer, P2VAR(uint16, AUTOMATIC, RTE_DEMMASTER_0_APPL_VAR) BufSize); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, DemMaster_0_CODE) Dem_GetEventExtendedDataRecordEx(Dem_EventIdType EventId, uint8 RecordNumber, P2VAR(Dem_MaxDataValueType, AUTOMATIC, RTE_DEMMASTER_0_APPL_VAR) DestBuffer, P2VAR(uint16, AUTOMATIC, RTE_DEMMASTER_0_APPL_VAR) BufSize); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
FUNC(Std_ReturnType, DemMaster_0_CODE) Dem_GetEventFailed(Dem_EventIdType EventId, P2VAR(boolean, AUTOMATIC, RTE_DEMMASTER_0_APPL_VAR) EventFailed); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, DemMaster_0_CODE) Dem_GetEventFreezeFrameDataEx(Dem_EventIdType EventId, uint8 RecordNumber, uint16 DataId, P2VAR(uint8, AUTOMATIC, RTE_DEMMASTER_0_APPL_VAR) DestBuffer, P2VAR(uint16, AUTOMATIC, RTE_DEMMASTER_0_APPL_VAR) BufSize); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, DemMaster_0_CODE) Dem_GetEventFreezeFrameDataEx(Dem_EventIdType EventId, uint8 RecordNumber, uint16 DataId, P2VAR(Dem_MaxDataValueType, AUTOMATIC, RTE_DEMMASTER_0_APPL_VAR) DestBuffer, P2VAR(uint16, AUTOMATIC, RTE_DEMMASTER_0_APPL_VAR) BufSize); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
FUNC(Std_ReturnType, DemMaster_0_CODE) Dem_GetEventMemoryOverflow(uint8 parg0, Dem_DTCOriginType parg1, P2VAR(boolean, AUTOMATIC, RTE_DEMMASTER_0_APPL_VAR) OverflowIndication); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, DemMaster_0_CODE) Dem_GetEventUdsStatus(Dem_EventIdType EventId, P2VAR(Dem_UdsStatusByteType, AUTOMATIC, RTE_DEMMASTER_0_APPL_VAR) UDSStatusByte); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, DemMaster_0_CODE) Dem_GetEventTested(Dem_EventIdType EventId, P2VAR(boolean, AUTOMATIC, RTE_DEMMASTER_0_APPL_VAR) EventTested); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, DemMaster_0_CODE) Dem_GetEventUdsStatus(Dem_EventIdType EventId, P2VAR(Dem_UdsStatusByteType, AUTOMATIC, RTE_DEMMASTER_0_APPL_VAR) UDSStatusByte); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, DemMaster_0_CODE) Dem_GetFaultDetectionCounter(Dem_EventIdType EventId, P2VAR(sint8, AUTOMATIC, RTE_DEMMASTER_0_APPL_VAR) FaultDetectionCounter); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, DemMaster_0_CODE) Dem_GetIndicatorStatus(uint8 parg0, P2VAR(Dem_IndicatorStatusType, AUTOMATIC, RTE_DEMMASTER_0_APPL_VAR) IndicatorStatus); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, DemMaster_0_CODE) Dem_GetMonitorStatus(Dem_EventIdType EventId, P2VAR(Dem_MonitorStatusType, AUTOMATIC, RTE_DEMMASTER_0_APPL_VAR) MonitorStatus); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, DemMaster_0_CODE) Dem_GetNumberOfEventMemoryEntries(uint8 parg0, Dem_DTCOriginType parg1, P2VAR(uint8, AUTOMATIC, RTE_DEMMASTER_0_APPL_VAR) NumberOfEventMemoryEntries); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, DemMaster_0_CODE) Dem_GetOperationCycleState(uint8 parg0, P2VAR(Dem_OperationCycleStateType, AUTOMATIC, RTE_DEMMASTER_0_APPL_VAR) CycleState); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, DemMaster_0_CODE) Dem_PostRunRequested(P2VAR(boolean, AUTOMATIC, RTE_DEMMASTER_0_APPL_VAR) IsRequested); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, DemMaster_0_CODE) Dem_SelectDTC(uint8 parg0, uint32 DTC, Dem_DTCFormatType DTCFormat, Dem_DTCOriginType DTCOrigin); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, DemMaster_0_CODE) Dem_SetDTCSuppression(uint8 parg0, boolean SuppressionStatus); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, DemMaster_0_CODE) Dem_SetEnableCondition(uint8 parg0, boolean ConditionFulfilled); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, DemMaster_0_CODE) Dem_SetOperationCycleState(uint8 parg0, Dem_OperationCycleStateType CycleState); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, DemMaster_0_CODE) Dem_SetStorageCondition(uint8 parg0, boolean ConditionFulfilled); /* PRQA S 1330, 3451, 0786, 3449, 0624 */ /* MD_Rte_1330, MD_Rte_3451, MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */

# define DemMaster_0_STOP_SEC_CODE
# include "DemMaster_0_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Application errors
 *********************************************************************************************************************/

#  define RTE_E_CSDataServices_Data_DID_0x10a_Vehicle_Odometer_in_Low_Resolution_E_NOT_OK (1U)

#  define RTE_E_CSDataServices_Data_DID_0x133_Current_Operating_Time_E_NOT_OK (1U)

#  define RTE_E_CSDataServices_Data_DID_0x133_Operating_Time_Status_E_NOT_OK (1U)

#  define RTE_E_CSDataServices_Data_DID_0x18b_SecOcDataID_E_NOT_OK (1U)

#  define RTE_E_CSDataServices_Data_DID_0xfd05_Root_Causes_E_NOT_OK (1U)

#  define RTE_E_CallbackDTCStatusChange_E_NOT_OK (1U)

#  define RTE_E_CallbackInitMonitorForEvent_E_NOT_OK (1U)

#  define RTE_E_ClearDTC_DEM_CLEAR_BUSY (5U)

#  define RTE_E_ClearDTC_DEM_CLEAR_FAILED (7U)

#  define RTE_E_ClearDTC_DEM_CLEAR_MEMORY_ERROR (6U)

#  define RTE_E_ClearDTC_DEM_PENDING (4U)

#  define RTE_E_ClearDTC_DEM_WRONG_DTC (8U)

#  define RTE_E_ClearDTC_DEM_WRONG_DTCORIGIN (9U)

#  define RTE_E_ClearDTC_E_NOT_OK (1U)

#  define RTE_E_ClearDTC_E_OK (0U)

#  define RTE_E_DTCSuppression_DEM_PENDING (4U)

#  define RTE_E_DTCSuppression_DEM_WRONG_DTC (8U)

#  define RTE_E_DTCSuppression_DEM_WRONG_DTCORIGIN (9U)

#  define RTE_E_DTCSuppression_E_NOT_OK (1U)

#  define RTE_E_DemSc_E_NOT_OK (1U)

#  define RTE_E_DemServices_E_NOT_OK (1U)

#  define RTE_E_EnableCondition_E_NOT_OK (1U)

#  define RTE_E_EvMemOverflowIndication_E_NOT_OK (1U)

#  define RTE_E_GeneralDiagnosticInfo_DEM_BUFFER_TOO_SMALL (21U)

#  define RTE_E_GeneralDiagnosticInfo_DEM_E_NO_DTC_AVAILABLE (10U)

#  define RTE_E_GeneralDiagnosticInfo_DEM_E_NO_FDC_AVAILABLE (14U)

#  define RTE_E_GeneralDiagnosticInfo_DEM_NO_SUCH_ELEMENT (48U)

#  define RTE_E_GeneralDiagnosticInfo_E_NOT_OK (1U)

#  define RTE_E_IndicatorStatus_E_NOT_OK (1U)

#  define RTE_E_OperationCycle_E_NOT_OK (1U)

#  define RTE_E_OperationCycle_E_OK (0U)

#  define RTE_E_StorageCondition_E_NOT_OK (1U)
# endif /* !defined(RTE_CORE) */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* RTE_DEMMASTER_0_H */

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

   MD_Rte_1330:  MISRA rule: Rule8.3
     Reason:     The RTE Generator uses default names for parameter identifiers of port defined arguments of service modules.
                 Therefore the parameter identifiers in the function declaration differs from those of the implementation of the BSW module.
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
