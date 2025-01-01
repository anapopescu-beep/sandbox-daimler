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
 *             File:  Rte_Ssa_TimeM.h
 *           Config:  StartApplication.dpa
 *      ECU-Project:  StartApplication
 *
 *        Generator:  MICROSAR RTE Generator Version 4.32.0
 *                    RTE Core Version 4.32.0
 *          License:  CBD2200333
 *
 *      Description:  Application header file for SW-C <Ssa_TimeM>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef RTE_SSA_TIMEM_H
# define RTE_SSA_TIMEM_H

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

# include "Rte_Ssa_TimeM_Type.h"
# include "Rte_DataHandleType.h"

# include "Rte_Hook.h"

# ifndef RTE_CORE

#  include "Com.h"


/**********************************************************************************************************************
 * extern declaration of RTE buffers for optimized macro implementation
 *********************************************************************************************************************/
#  define RTE_START_SEC_VAR_NOINIT_UNSPECIFIED
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern VAR(Ssa_ChangeTickCountEventIdType, RTE_VAR_NOINIT) Rte_Ssa_FvM_SendChangeTickCountEvent_Id;

#  define RTE_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

# endif /* !defined(RTE_CORE) */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

#  define Rte_InitValue_ReceiveChangeTickCountEvent_Id (4U)
#  define Rte_InitValue_Ssa_PowernetMgmtState_PN14_DDP_Sw_Stat_ST3 (0U)
# endif


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Buffers for inter-runnable variables
 *********************************************************************************************************************/

#  define RTE_START_SEC_VAR_NOINIT_UNSPECIFIED
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern VAR(Ssa_TickCountSyncStateType, RTE_VAR_NOINIT) Rte_Irv_Ssa_TimeM_TimeM_IrvTickCountSyncState;

#  define RTE_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
# endif /* !defined(RTE_CORE) */


# define RTE_START_SEC_CODE
# include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Ssa_TimeM_ReceiveChangeTickCountEvent_TickCount(P2VAR(uint8, AUTOMATIC, RTE_SSA_TIMEM_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Ssa_TimeM_ReceiveChangeTickCountEvent_TickCount(P2VAR(Ssa_Data5ByteType, AUTOMATIC, RTE_SSA_TIMEM_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Ssa_TimeM_ReceiveLocalTickCountAndSyncStatus_Data(P2VAR(Ssa_LocalTickCountAndSyncStatusType, AUTOMATIC, RTE_SSA_TIMEM_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Ssa_TimeM_TimeM_Com_ReceiveRealTimeOffset_realTimeOffset(P2VAR(uint8, AUTOMATIC, RTE_SSA_TIMEM_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Ssa_TimeM_TimeM_Com_ReceiveRealTimeOffset_realTimeOffset(P2VAR(Ssa_Data12ByteType, AUTOMATIC, RTE_SSA_TIMEM_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif


# define RTE_STOP_SEC_CODE
# include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# ifndef RTE_CORE

/**********************************************************************************************************************
 * Rte_Read_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Read_ReceiveChangeTickCountEvent_Id Rte_Read_Ssa_TimeM_ReceiveChangeTickCountEvent_Id
#  define Rte_Read_Ssa_TimeM_ReceiveChangeTickCountEvent_Id(data) (*(data) = Rte_Ssa_FvM_SendChangeTickCountEvent_Id, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_ReceiveChangeTickCountEvent_TickCount Rte_Read_Ssa_TimeM_ReceiveChangeTickCountEvent_TickCount
#  define Rte_Read_ReceiveLocalTickCountAndSyncStatus_Data Rte_Read_Ssa_TimeM_ReceiveLocalTickCountAndSyncStatus_Data
#  define Rte_Read_Ssa_PowernetMgmtState_PN14_DDP_Sw_Stat_ST3 Rte_Read_Ssa_TimeM_Ssa_PowernetMgmtState_PN14_DDP_Sw_Stat_ST3
#  define Rte_Read_Ssa_TimeM_Ssa_PowernetMgmtState_PN14_DDP_Sw_Stat_ST3(data) (Com_ReceiveSignal(ComConf_ComSignal_PN14_DDP_Sw_Stat_ST3_568ad7e6_Rx, (data)))
#  define Rte_Read_TimeM_Com_ReceiveRealTimeOffset_realTimeOffset Rte_Read_Ssa_TimeM_TimeM_Com_ReceiveRealTimeOffset_realTimeOffset


/**********************************************************************************************************************
 * Rte_Mode_<p>_<m>
 *********************************************************************************************************************/
#  define Rte_Mode_Ssa_TimeM_OperationMode_Mode() (RTE_MODE_Ssa_OperationMode_SSA_ACTIVE)


/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (unmapped) for synchronous C/S communication
 *********************************************************************************************************************/
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

#  define RTE_START_SEC_SSA_FVM_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FUNC(Std_ReturnType, RTE_SSA_FVM_APPL_CODE) Ssa_FvM_InitialTickCount_Set(uint64 tickCount); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */

#  define RTE_STOP_SEC_SSA_FVM_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define RTE_START_SEC_SSA_SECLOG_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_SSA_SECLOG_APPL_CODE) Ssa_SecLog_LogEvent_ChangeTickCountOrDateAndTime(uint8 contextDateTimeChange, P2CONST(uint8, AUTOMATIC, RTE_SSA_SECLOG_APPL_DATA) deltaTimeChange); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_SSA_SECLOG_APPL_CODE) Ssa_SecLog_LogEvent_ChangeTickCountOrDateAndTime(uint8 contextDateTimeChange, P2CONST(Ssa_Data5ByteType, AUTOMATIC, RTE_SSA_SECLOG_APPL_DATA) deltaTimeChange); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif

#  define RTE_STOP_SEC_SSA_SECLOG_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define Rte_Call_DTC_0xD12081_SetEventStatus(arg1) (Dem_SetEventStatus((Dem_EventIdType)30, arg1))
#  define Rte_Call_DTC_0xD12087_SetEventStatus(arg1) (Dem_SetEventStatus((Dem_EventIdType)32, arg1))
#  define Rte_Call_FvM_InitialTickCount_Set Ssa_FvM_InitialTickCount_Set
#  define Rte_Call_NvMService_RealTimeOffset_GetErrorStatus(arg1) (NvM_GetErrorStatus((NvM_BlockIdType)24, arg1))
#  define Rte_Call_NvMService_RealTimeOffset_WriteBlock(arg1) (NvM_WriteBlock((NvM_BlockIdType)24, arg1))
#  define Rte_Call_NvMService_TickCount_GetErrorStatus(arg1) (NvM_GetErrorStatus((NvM_BlockIdType)25, arg1))
#  define Rte_Call_NvMService_TickCount_SetRamBlockStatus(arg1) (NvM_SetRamBlockStatus((NvM_BlockIdType)25, arg1))
#  define Rte_Call_NvMService_TickCount_WriteBlock(arg1) (NvM_WriteBlock((NvM_BlockIdType)25, arg1))
#  define Rte_Call_SecLog_ChangeTickCountOrDateAndTimeEvent_ChangeTickCountOrDateAndTime Ssa_SecLog_LogEvent_ChangeTickCountOrDateAndTime

/**********************************************************************************************************************
 * Exclusive Areas
 *********************************************************************************************************************/

#  define Rte_Enter_TimeM_ExclusiveArea() SuspendAllInterrupts() /* RteAnalyzer(ExclusiveArea, ALL_INTERRUPT_BLOCKING) */

#  define Rte_Exit_TimeM_ExclusiveArea() ResumeAllInterrupts()  /* RteAnalyzer(ExclusiveArea, ALL_INTERRUPT_BLOCKING) */


/**********************************************************************************************************************
 * Inter-runnable variables
 *********************************************************************************************************************/

/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IrvRead_Ssa_TimeM_DataServices_DID_018A_TickCount_ReadData_TimeM_IrvTickCountSyncState() \
  Rte_Irv_Ssa_TimeM_TimeM_IrvTickCountSyncState
/* PRQA L:L1 */

/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IrvWrite_Ssa_TimeM_Init_TimeM_IrvTickCountSyncState(data) \
  (Rte_Irv_Ssa_TimeM_TimeM_IrvTickCountSyncState = (data))
/* PRQA L:L1 */

/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IrvWrite_Ssa_TimeM_Mainfunction_TimeM_IrvTickCountSyncState(data) \
  (Rte_Irv_Ssa_TimeM_TimeM_IrvTickCountSyncState = (data))
/* PRQA L:L1 */


/**********************************************************************************************************************
 * Rte_CData (SW-C local calibration parameters)
 *********************************************************************************************************************/

#  ifndef RTE_MICROSAR_PIM_EXPORT

#   define RTE_START_SEC_CONST_DEFAULT_RTE_CDATA_GROUP_UNSPECIFIED
#   include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern CONST(uint64, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_Ssa_TimeM_NvM_TimeM_LocalTimeBase_DefaultValue;
extern CONST(TimeM_RealTimeOffsetType, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_Ssa_TimeM_NvM_TimeM_RealTimeOffset_DefaultValue;

#   define RTE_STOP_SEC_CONST_DEFAULT_RTE_CDATA_GROUP_UNSPECIFIED
#   include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  endif

#  define Rte_CData_NvM_TimeM_LocalTimeBase_DefaultValue() (Rte_Ssa_TimeM_NvM_TimeM_LocalTimeBase_DefaultValue)

#  define Rte_CData_NvM_TimeM_RealTimeOffset_DefaultValue() (&Rte_Ssa_TimeM_NvM_TimeM_RealTimeOffset_DefaultValue)

/**********************************************************************************************************************
 * Rte_Pim (Per-Instance Memory)
 *********************************************************************************************************************/

#  ifndef RTE_MICROSAR_PIM_EXPORT
#   define RTE_START_SEC_VAR_DEFAULT_RTE_PIM_GROUP_UNSPECIFIED
#   include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern VAR(uint64, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_Ssa_TimeM_TickCount;
extern VAR(uint64, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_Ssa_TimeM_TickCountMirror;
extern VAR(uint64, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_Ssa_TimeM_TickCountValueToBeStoredToNvM;
extern VAR(TimeM_RealTimeOffsetType, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_Ssa_TimeM_RealTimeOffset;
extern VAR(TimeM_RealTimeOffsetType, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_Ssa_TimeM_RealTimeOffsetMirror;

#   define RTE_STOP_SEC_VAR_DEFAULT_RTE_PIM_GROUP_UNSPECIFIED
#   include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  endif

/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Pim_TickCount() \
  (&Rte_Ssa_TimeM_TickCount)
/* PRQA L:L1 */

/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Pim_TickCountMirror() \
  (&Rte_Ssa_TimeM_TickCountMirror)
/* PRQA L:L1 */

/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Pim_TickCountValueToBeStoredToNvM() \
  (&Rte_Ssa_TimeM_TickCountValueToBeStoredToNvM)
/* PRQA L:L1 */

/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Pim_RealTimeOffset() \
  (&Rte_Ssa_TimeM_RealTimeOffset)
/* PRQA L:L1 */

/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Pim_RealTimeOffsetMirror() \
  (&Rte_Ssa_TimeM_RealTimeOffsetMirror)
/* PRQA L:L1 */


# endif /* !defined(RTE_CORE) */


# define Ssa_TimeM_START_SEC_CODE
# include "Ssa_TimeM_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

# ifndef RTE_CORE
#  define RTE_RUNNABLE_Ssa_TimeM_Com_ReceiveRealTimeOffset Ssa_TimeM_Com_ReceiveRealTimeOffset
#  define RTE_RUNNABLE_Ssa_TimeM_DataServices_DID_018A_TickCount_ConditionCheckRead Ssa_TimeM_DataServices_DID_018A_TickCount_ConditionCheckRead
#  define RTE_RUNNABLE_Ssa_TimeM_DataServices_DID_018A_TickCount_ReadData Ssa_TimeM_DataServices_DID_018A_TickCount_ReadData
#  define RTE_RUNNABLE_Ssa_TimeM_DataServices_DID_018D_RealTimeOffset_DateTime_ConditionCheckRead Ssa_TimeM_DataServices_DID_018D_RealTimeOffset_DateTime_ConditionCheckRead
#  define RTE_RUNNABLE_Ssa_TimeM_DataServices_DID_018D_RealTimeOffset_DateTime_ReadData Ssa_TimeM_DataServices_DID_018D_RealTimeOffset_DateTime_ReadData
#  define RTE_RUNNABLE_Ssa_TimeM_DataServices_DID_018D_RealTimeOffset_TickCount_ConditionCheckRead Ssa_TimeM_DataServices_DID_018D_RealTimeOffset_TickCount_ConditionCheckRead
#  define RTE_RUNNABLE_Ssa_TimeM_DataServices_DID_018D_RealTimeOffset_TickCount_ReadData Ssa_TimeM_DataServices_DID_018D_RealTimeOffset_TickCount_ReadData
#  define RTE_RUNNABLE_Ssa_TimeM_DataServices_Secured_System_Date_and_Time_Read_GeneralizedTime_ConditionCheckRead Ssa_TimeM_DataServices_Secured_System_Date_and_Time_Read_GeneralizedTime_ConditionCheckRead
#  define RTE_RUNNABLE_Ssa_TimeM_DataServices_Secured_System_Date_and_Time_Read_GeneralizedTime_ReadData Ssa_TimeM_DataServices_Secured_System_Date_and_Time_Read_GeneralizedTime_ReadData
#  define RTE_RUNNABLE_Ssa_TimeM_Init Ssa_TimeM_Init
#  define RTE_RUNNABLE_Ssa_TimeM_Mainfunction Ssa_TimeM_Mainfunction
#  define RTE_RUNNABLE_Ssa_TimeM_PowernetMgmtStateChanged Ssa_TimeM_PowernetMgmtStateChanged
#  define RTE_RUNNABLE_Ssa_TimeM_RealTime_Compare Ssa_TimeM_RealTime_Compare
#  define RTE_RUNNABLE_Ssa_TimeM_RealTime_Get Ssa_TimeM_RealTime_Get
#  define RTE_RUNNABLE_Ssa_TimeM_RealTime_Set Ssa_TimeM_RealTime_Set
#  define RTE_RUNNABLE_Ssa_TimeM_ReceiveChangeTickCountEvent Ssa_TimeM_ReceiveChangeTickCountEvent
#  define RTE_RUNNABLE_Ssa_TimeM_TickCount_Get Ssa_TimeM_TickCount_Get
#  define RTE_RUNNABLE_Ssa_TimeM_TimeRawData_Get Ssa_TimeM_TimeRawData_Get
#  define RTE_RUNNABLE_Ssa_TimeM_TimeRawData_ResetLocalTickCount Ssa_TimeM_TimeRawData_ResetLocalTickCount
#  define RTE_RUNNABLE_Ssa_TimeM_TimeRawData_Set Ssa_TimeM_TimeRawData_Set
# endif

FUNC(void, Ssa_TimeM_CODE) Ssa_TimeM_Com_ReceiveRealTimeOffset(void); /* PRQA S 3451, 0786, 3449 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449 */
FUNC(Std_ReturnType, Ssa_TimeM_CODE) Ssa_TimeM_DataServices_DID_018A_TickCount_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_TIMEM_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, Ssa_TimeM_CODE) Ssa_TimeM_DataServices_DID_018A_TickCount_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_SSA_TIMEM_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, Ssa_TimeM_CODE) Ssa_TimeM_DataServices_DID_018D_RealTimeOffset_DateTime_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_TIMEM_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, Ssa_TimeM_CODE) Ssa_TimeM_DataServices_DID_018D_RealTimeOffset_DateTime_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_SSA_TIMEM_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, Ssa_TimeM_CODE) Ssa_TimeM_DataServices_DID_018D_RealTimeOffset_DateTime_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data15ByteType, AUTOMATIC, RTE_SSA_TIMEM_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
FUNC(Std_ReturnType, Ssa_TimeM_CODE) Ssa_TimeM_DataServices_DID_018D_RealTimeOffset_TickCount_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_TIMEM_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, Ssa_TimeM_CODE) Ssa_TimeM_DataServices_DID_018D_RealTimeOffset_TickCount_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_SSA_TIMEM_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, Ssa_TimeM_CODE) Ssa_TimeM_DataServices_DID_018D_RealTimeOffset_TickCount_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data5ByteType, AUTOMATIC, RTE_SSA_TIMEM_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
FUNC(Std_ReturnType, Ssa_TimeM_CODE) Ssa_TimeM_DataServices_Secured_System_Date_and_Time_Read_GeneralizedTime_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_TIMEM_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, Ssa_TimeM_CODE) Ssa_TimeM_DataServices_Secured_System_Date_and_Time_Read_GeneralizedTime_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_SSA_TIMEM_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, Ssa_TimeM_CODE) Ssa_TimeM_Init(void); /* PRQA S 3451, 0786, 3449 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449 */
FUNC(void, Ssa_TimeM_CODE) Ssa_TimeM_Mainfunction(void); /* PRQA S 3451, 0786, 3449 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449 */
FUNC(void, Ssa_TimeM_CODE) Ssa_TimeM_PowernetMgmtStateChanged(void); /* PRQA S 3451, 0786, 3449 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449 */
FUNC(Std_ReturnType, Ssa_TimeM_CODE) Ssa_TimeM_RealTime_Compare(P2CONST(TimeM_DateTimeType, AUTOMATIC, RTE_SSA_TIMEM_APPL_DATA) t1, TimeM_CompareOperatorType compareOp, P2CONST(TimeM_DateTimeType, AUTOMATIC, RTE_SSA_TIMEM_APPL_DATA) t2, P2VAR(boolean, AUTOMATIC, RTE_SSA_TIMEM_APPL_VAR) result); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, Ssa_TimeM_CODE) Ssa_TimeM_RealTime_Get(P2VAR(TimeM_DateTimeType, AUTOMATIC, RTE_SSA_TIMEM_APPL_VAR) realTime); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, Ssa_TimeM_CODE) Ssa_TimeM_RealTime_Set(P2CONST(TimeM_DateTimeType, AUTOMATIC, RTE_SSA_TIMEM_APPL_DATA) realTime, TimeM_RealTimeChangeReasonType changeReason); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, Ssa_TimeM_CODE) Ssa_TimeM_ReceiveChangeTickCountEvent(void); /* PRQA S 3451, 0786, 3449 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449 */
FUNC(Std_ReturnType, Ssa_TimeM_CODE) Ssa_TimeM_TickCount_Get(P2VAR(uint64, AUTOMATIC, RTE_SSA_TIMEM_APPL_VAR) tickCount); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, Ssa_TimeM_CODE) Ssa_TimeM_TimeRawData_Get(P2VAR(uint8, AUTOMATIC, RTE_SSA_TIMEM_APPL_VAR) dateTimeOffset, P2VAR(uint8, AUTOMATIC, RTE_SSA_TIMEM_APPL_VAR) tickCountOffset, P2VAR(uint8, AUTOMATIC, RTE_SSA_TIMEM_APPL_VAR) tickCount); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, Ssa_TimeM_CODE) Ssa_TimeM_TimeRawData_ResetLocalTickCount(void); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, Ssa_TimeM_CODE) Ssa_TimeM_TimeRawData_Set(P2CONST(uint8, AUTOMATIC, RTE_SSA_TIMEM_APPL_DATA) dateTimeOffset, P2CONST(uint8, AUTOMATIC, RTE_SSA_TIMEM_APPL_DATA) tickCountOffset, P2CONST(uint8, AUTOMATIC, RTE_SSA_TIMEM_APPL_DATA) tickCount); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */

# define Ssa_TimeM_STOP_SEC_CODE
# include "Ssa_TimeM_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Application errors
 *********************************************************************************************************************/

#  define RTE_E_DataServices_DID_018A_TickCount_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_DID_018A_TickCount_E_NOT_OK (1U)

#  define RTE_E_DataServices_DID_018D_Real_Time_Offset_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_DID_018D_Real_Time_Offset_E_NOT_OK (1U)

#  define RTE_E_DataServices_DID_018D_TickCount_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_DID_018D_TickCount_E_NOT_OK (1U)

#  define RTE_E_DataServices_Secured_System_Date_and_Time_Read_GeneralizedTime_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Secured_System_Date_and_Time_Read_GeneralizedTime_E_NOT_OK (1U)

#  define RTE_E_DiagnosticMonitor_E_NOT_OK (1U)

#  define RTE_E_FvM_InitialTickCount_E_NOT_OK (1U)

#  define RTE_E_NvMService_AC2_SRBS_E_NOT_OK (1U)

#  define RTE_E_SecLog_ChangeTickCountOrDateAndTimeEvent_E_NOT_OK (1U)

#  define RTE_E_TimeM_RealTime_E_NOT_OK (1U)

#  define RTE_E_TimeM_TickCount_E_NOT_OK (1U)

#  define RTE_E_TimeM_TimeRawData_E_NOT_OK (1U)
# endif /* !defined(RTE_CORE) */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* RTE_SSA_TIMEM_H */

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
