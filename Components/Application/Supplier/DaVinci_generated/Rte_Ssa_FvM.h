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
 *             File:  Rte_Ssa_FvM.h
 *           Config:  StartApplication.dpa
 *      ECU-Project:  StartApplication
 *
 *        Generator:  MICROSAR RTE Generator Version 4.32.0
 *                    RTE Core Version 4.32.0
 *          License:  CBD2200333
 *
 *      Description:  Application header file for SW-C <Ssa_FvM>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef RTE_SSA_FVM_H
# define RTE_SSA_FVM_H

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

# include "Rte_Ssa_FvM_Type.h"
# include "Rte_DataHandleType.h"

# include "Rte_Hook.h"


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

#  define Rte_InitValue_FvM_Com_ReceiveTickCountTimeout_state (0U)
#  define Rte_InitValue_SendChangeTickCountEvent_Id (4U)
# endif


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Buffers for inter-runnable variables
 *********************************************************************************************************************/

#  define RTE_START_SEC_VAR_NOINIT_UNSPECIFIED
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern VAR(uint8, RTE_VAR_NOINIT) Rte_Irv_Ssa_FvM_FvM_IrvCountUpSecTimeMsg;
extern VAR(boolean, RTE_VAR_NOINIT) Rte_Irv_Ssa_FvM_FvM_IrvFirstTickCountMessageAfterStartUpReceived;
extern VAR(Ssa_TickCountSyncStateType, RTE_VAR_NOINIT) Rte_Irv_Ssa_FvM_FvM_IrvTickCountSyncState;

#  define RTE_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
# endif /* !defined(RTE_CORE) */


# define RTE_START_SEC_CODE
# include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Ssa_FvM_FvM_Com_ReceiveTickCount_tickCount(P2VAR(uint8, AUTOMATIC, RTE_SSA_FVM_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Ssa_FvM_FvM_Com_ReceiveTickCount_tickCount(P2VAR(Ssa_Data6ByteType, AUTOMATIC, RTE_SSA_FVM_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Ssa_FvM_FvM_SendLocalTickCountAndSyncStatus_Data(P2CONST(Ssa_LocalTickCountAndSyncStatusType, AUTOMATIC, RTE_SSA_FVM_APPL_DATA) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Ssa_FvM_SendChangeTickCountEvent_Id(Ssa_ChangeTickCountEventIdType data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Ssa_FvM_SendChangeTickCountEvent_TickCount(P2CONST(uint8, AUTOMATIC, RTE_SSA_FVM_APPL_DATA) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Ssa_FvM_SendChangeTickCountEvent_TickCount(P2CONST(Ssa_Data5ByteType, AUTOMATIC, RTE_SSA_FVM_APPL_DATA) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif


# define RTE_STOP_SEC_CODE
# include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# ifndef RTE_CORE

/**********************************************************************************************************************
 * Rte_Read_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Read_FvM_Com_ReceiveTickCount_tickCount Rte_Read_Ssa_FvM_FvM_Com_ReceiveTickCount_tickCount


/**********************************************************************************************************************
 * Rte_Write_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Write_FvM_SendLocalTickCountAndSyncStatus_Data Rte_Write_Ssa_FvM_FvM_SendLocalTickCountAndSyncStatus_Data
#  define Rte_Write_SendChangeTickCountEvent_Id Rte_Write_Ssa_FvM_SendChangeTickCountEvent_Id
#  define Rte_Write_SendChangeTickCountEvent_TickCount Rte_Write_Ssa_FvM_SendChangeTickCountEvent_TickCount


/**********************************************************************************************************************
 * Exclusive Areas
 *********************************************************************************************************************/

#  define Rte_Enter_FvM_ExclusiveArea() SuspendAllInterrupts() /* RteAnalyzer(ExclusiveArea, ALL_INTERRUPT_BLOCKING) */

#  define Rte_Exit_FvM_ExclusiveArea() ResumeAllInterrupts()  /* RteAnalyzer(ExclusiveArea, ALL_INTERRUPT_BLOCKING) */


/**********************************************************************************************************************
 * Inter-runnable variables
 *********************************************************************************************************************/

/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IrvRead_Ssa_FvM_Com_ReceiveTickCount_FvM_IrvFirstTickCountMessageAfterStartUpReceived() \
  Rte_Irv_Ssa_FvM_FvM_IrvFirstTickCountMessageAfterStartUpReceived
/* PRQA L:L1 */

/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IrvWrite_Ssa_FvM_Com_ReceiveTickCount_FvM_IrvFirstTickCountMessageAfterStartUpReceived(data) \
  (Rte_Irv_Ssa_FvM_FvM_IrvFirstTickCountMessageAfterStartUpReceived = (data))
/* PRQA L:L1 */

/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IrvWrite_Ssa_FvM_Com_ReceiveTickCount_FvM_IrvTickCountSyncState(data) \
  (Rte_Irv_Ssa_FvM_FvM_IrvTickCountSyncState = (data))
/* PRQA L:L1 */

/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IrvWrite_Ssa_FvM_Init_FvM_IrvCountUpSecTimeMsg(data) \
  (Rte_Irv_Ssa_FvM_FvM_IrvCountUpSecTimeMsg = (data))
/* PRQA L:L1 */

/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IrvWrite_Ssa_FvM_Init_FvM_IrvFirstTickCountMessageAfterStartUpReceived(data) \
  (Rte_Irv_Ssa_FvM_FvM_IrvFirstTickCountMessageAfterStartUpReceived = (data))
/* PRQA L:L1 */

/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IrvWrite_Ssa_FvM_Init_FvM_IrvTickCountSyncState(data) \
  (Rte_Irv_Ssa_FvM_FvM_IrvTickCountSyncState = (data))
/* PRQA L:L1 */

/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IrvRead_Ssa_FvM_LocalTickCountSyncStatus_Get_FvM_IrvTickCountSyncState() \
  Rte_Irv_Ssa_FvM_FvM_IrvTickCountSyncState
/* PRQA L:L1 */

/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IrvRead_Ssa_FvM_Mainfunction_FvM_IrvCountUpSecTimeMsg() \
  Rte_Irv_Ssa_FvM_FvM_IrvCountUpSecTimeMsg
/* PRQA L:L1 */

/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IrvRead_Ssa_FvM_Mainfunction_FvM_IrvTickCountSyncState() \
  Rte_Irv_Ssa_FvM_FvM_IrvTickCountSyncState
/* PRQA L:L1 */

/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IrvWrite_Ssa_FvM_Mainfunction_FvM_IrvCountUpSecTimeMsg(data) \
  (Rte_Irv_Ssa_FvM_FvM_IrvCountUpSecTimeMsg = (data))
/* PRQA L:L1 */

/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IrvWrite_Ssa_FvM_Mainfunction_FvM_IrvTickCountSyncState(data) \
  (Rte_Irv_Ssa_FvM_FvM_IrvTickCountSyncState = (data))
/* PRQA L:L1 */


/**********************************************************************************************************************
 * Rte_Pim (Per-Instance Memory)
 *********************************************************************************************************************/

#  ifndef RTE_MICROSAR_PIM_EXPORT
#   define RTE_START_SEC_VAR_DEFAULT_RTE_PIM_GROUP_UNSPECIFIED
#   include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern VAR(uint64, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_Ssa_FvM_LastSecuredTickCount;
extern VAR(uint64, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_Ssa_FvM_TickCount;

#   define RTE_STOP_SEC_VAR_DEFAULT_RTE_PIM_GROUP_UNSPECIFIED
#   include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  endif

/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Pim_LastSecuredTickCount() \
  (&Rte_Ssa_FvM_LastSecuredTickCount)
/* PRQA L:L1 */

/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Pim_TickCount() \
  (&Rte_Ssa_FvM_TickCount)
/* PRQA L:L1 */


# endif /* !defined(RTE_CORE) */


# define Ssa_FvM_START_SEC_CODE
# include "Ssa_FvM_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

# ifndef RTE_CORE
#  define RTE_RUNNABLE_Ssa_FvM_Com_ReceiveTickCount Ssa_FvM_Com_ReceiveTickCount
#  define RTE_RUNNABLE_Ssa_FvM_Com_ReceiveTickCountTimeout Ssa_FvM_Com_ReceiveTickCountTimeout
#  define RTE_RUNNABLE_Ssa_FvM_GetRxFreshness Ssa_FvM_GetRxFreshness
#  define RTE_RUNNABLE_Ssa_FvM_GetTxFreshness Ssa_FvM_GetTxFreshness
#  define RTE_RUNNABLE_Ssa_FvM_GetTxFreshnessTruncData Ssa_FvM_GetTxFreshnessTruncData
#  define RTE_RUNNABLE_Ssa_FvM_Init Ssa_FvM_Init
#  define RTE_RUNNABLE_Ssa_FvM_InitMonitorForEvent_DTC_0xD12081 Ssa_FvM_InitMonitorForEvent_DTC_0xD12081
#  define RTE_RUNNABLE_Ssa_FvM_InitMonitorForEvent_DTC_0xD12087 Ssa_FvM_InitMonitorForEvent_DTC_0xD12087
#  define RTE_RUNNABLE_Ssa_FvM_InitialTickCount_Set Ssa_FvM_InitialTickCount_Set
#  define RTE_RUNNABLE_Ssa_FvM_LocalTickCountSyncStatus_Get Ssa_FvM_LocalTickCountSyncStatus_Get
#  define RTE_RUNNABLE_Ssa_FvM_Mainfunction Ssa_FvM_Mainfunction
#  define RTE_RUNNABLE_Ssa_FvM_SPduTxConfirmation Ssa_FvM_SPduTxConfirmation
# endif

FUNC(void, Ssa_FvM_CODE) Ssa_FvM_Com_ReceiveTickCount(void); /* PRQA S 3451, 0786, 3449 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449 */
FUNC(void, Ssa_FvM_CODE) Ssa_FvM_Com_ReceiveTickCountTimeout(void); /* PRQA S 3451, 0786, 3449 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449 */
FUNC(Std_ReturnType, Ssa_FvM_CODE) Ssa_FvM_GetRxFreshness(uint16 freshnessValueId, P2CONST(uint8, AUTOMATIC, RTE_SSA_FVM_APPL_DATA) truncatedFreshnessValue, uint32 truncatedFreshnessValueLength, uint16 authVerifyAttempts, P2VAR(uint8, AUTOMATIC, RTE_SSA_FVM_APPL_VAR) freshnessValue, P2VAR(uint32, AUTOMATIC, RTE_SSA_FVM_APPL_VAR) freshnessValueLength); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, Ssa_FvM_CODE) Ssa_FvM_GetTxFreshness(uint16 freshnessValueId, P2VAR(uint8, AUTOMATIC, RTE_SSA_FVM_APPL_VAR) freshnessValue, P2VAR(uint32, AUTOMATIC, RTE_SSA_FVM_APPL_VAR) freshnessValueLength); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, Ssa_FvM_CODE) Ssa_FvM_GetTxFreshnessTruncData(uint16 freshnessValueId, P2VAR(uint8, AUTOMATIC, RTE_SSA_FVM_APPL_VAR) freshnessValue, P2VAR(uint32, AUTOMATIC, RTE_SSA_FVM_APPL_VAR) freshnessValueLength, P2VAR(uint8, AUTOMATIC, RTE_SSA_FVM_APPL_VAR) truncatedFreshnessValue, P2VAR(uint32, AUTOMATIC, RTE_SSA_FVM_APPL_VAR) truncatedFreshnessValueLength); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, Ssa_FvM_CODE) Ssa_FvM_Init(void); /* PRQA S 3451, 0786, 3449 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449 */
FUNC(Std_ReturnType, Ssa_FvM_CODE) Ssa_FvM_InitMonitorForEvent_DTC_0xD12081(Dem_InitMonitorReasonType InitMonitorReason); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, Ssa_FvM_CODE) Ssa_FvM_InitMonitorForEvent_DTC_0xD12087(Dem_InitMonitorReasonType InitMonitorReason); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, Ssa_FvM_CODE) Ssa_FvM_InitialTickCount_Set(uint64 tickCount); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, Ssa_FvM_CODE) Ssa_FvM_LocalTickCountSyncStatus_Get(P2VAR(Ssa_TickCountSyncStateType, AUTOMATIC, RTE_SSA_FVM_APPL_VAR) syncState); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, Ssa_FvM_CODE) Ssa_FvM_Mainfunction(void); /* PRQA S 3451, 0786, 3449 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449 */
FUNC(Std_ReturnType, Ssa_FvM_CODE) Ssa_FvM_SPduTxConfirmation(uint16 freshnessValueId); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */

# define Ssa_FvM_STOP_SEC_CODE
# include "Ssa_FvM_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Application errors
 *********************************************************************************************************************/

#  define RTE_E_CallbackInitMonitorForEvent_E_NOT_OK (1U)

#  define RTE_E_FvM_FreshnessManagement_E_BUSY (2U)

#  define RTE_E_FvM_FreshnessManagement_E_NOT_OK (1U)

#  define RTE_E_FvM_FreshnessManagement_E_OK (0U)

#  define RTE_E_FvM_InitialTickCount_E_NOT_OK (1U)

#  define RTE_E_FvM_LocalTickCountSyncStatus_E_NOT_OK (1U)

#  define RTE_E_SecOC_FreshnessManagement_E_BUSY (2U)

#  define RTE_E_SecOC_FreshnessManagement_E_NOT_OK (1U)

#  define RTE_E_SecOC_FreshnessManagement_E_OK (0U)
# endif /* !defined(RTE_CORE) */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* RTE_SSA_FVM_H */

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
