/**********************************************************************************************************************
 *  FILE REQUIRES USER MODIFICATIONS
 *  Template Scope: sections marked with Start and End comments
 *  -------------------------------------------------------------------------------------------------------------------
 *  This file includes template code that must be completed and/or adapted during BSW integration.
 *  The template code is incomplete and only intended for providing a signature and an empty implementation.
 *  It is neither intended nor qualified for use in series production without applying suitable quality measures.
 *  The template code must be completed as described in the instructions given within this file and/or in the.
 *  Technical Reference.
 *  The completed implementation must be tested with diligent care and must comply with all quality requirements which.
 *  are necessary according to the state of the art before its use.
 *********************************************************************************************************************/
/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *             File:  Cdd_MBBL_ResetExecutor.c
 *           Config:  S:\Tools\Vector_configuration\Workspace\Daimler MMA/S:/Tools/Vector_configuration/Workspace/Daimler MMA/StartApplication.dpa
 *        SW-C Type:  Cdd_MBBL_ResetExecutor
 *  Generation Time:  2021-10-26 17:23:54
 *
 *        Generator:  MICROSAR RTE Generator Version 4.24.0
 *                    RTE Core Version 1.24.0
 *          License:  PAI981
 *
 *      Description:  C-Code implementation template for SW-C <Cdd_MBBL_ResetExecutor>
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of version logging area >>                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/* PRQA S 0777, 0779 EOF */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of version logging area >>                  DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *
 * AUTOSAR Modelling Object Descriptions
 *
 **********************************************************************************************************************
 *
 * Data Types:
 * ===========
 * BswM_ESH_KillAllRun
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * EcuM_ModeType
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * EcuM_StateType
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 *
 * Operation Prototypes:
 * =====================
 * SelectShutdownTarget of Port Interface EcuM_ShutdownTarget
 *   The SW-C selects the cause corresponding to the next shutdown target.
 *
 *
 * Mode Declaration Groups:
 * ========================
 * Coding_MemoryStatus
 *   Notifies the Ssa of memory status changes while storing or restoring the Variant Coding Data to or from non-volatile memory.
 *
 * Coding_Mode
 *   Coding state
 *
 * Coding_Mode
 *   Notifies application about an ongoing, successful or failed coding attempt.
 *
 * RightsM_AuthenticationMode
 *   RIGHTSM_AUTHENTICATED - A Tester was successfully authenticated
 *      RIGHTSM_UNAUTHENTICATED - No tester was authenticated
 *
 * WdgM_Mode
 *   The mode declaration group WdgMMode represents the modes of the Watchdog Manager module that will be notified to the SW-Cs / CDDs and the RTE.
 *
 *
 * Mode Declarations:
 * ==================
 * CODING_ACTIVE of Mode Declaration Group Coding_Mode
 *   Active
 *
 * CODING_FAILED of Mode Declaration Group Coding_Mode
 *   Failed
 *
 * CODING_OK of Mode Declaration Group Coding_Mode
 *   Ok
 *
 *
 * Runnable Entities:
 * ==================
 * Cdd_MBBL_ResetExecutor_Init
 *      -------------------------------------------------------------------------------------
 *      This runnable is currently not used.
 *      -------------------------------------------------------------------------------------
 *
 * Pp_ResetExecution_HardReset
 *      -------------------------------------------------------------------------------------
 *      This runnable executes all required steps for a hard reset:
 *      - Preparation of Watchdog(s) for reset 
 *        --> optional step (depends on value of prepareWatchdog)
 *      
 *      - Call of Mcu_PerformReset
 *      
 *      If the Mcu-call fails it will try the second reset path by waiting for a 
 *      watchdog reset in an infinite loop with locked interrupts.
 *      
 *      This runnable should never return.
 *      -------------------------------------------------------------------------------------
 *
 * Pp_ResetExecution_SoftReset
 *      -------------------------------------------------------------------------------------
 *      This server runnable executes all required steps for a soft reset:
 *      - Set the ECUM shutdown target to MCU reset
 *        --> This ensures that after a successful shutdown the EcuM 
 *        performs a reset instead of a shutdown
 *      
 *      - Kill all BswM run requests
 *        --> This triggers the BswM to perform a regular shutdown
 *        ignoring all other reasons as to why the ECU might still be 
 *        awake
 *      
 *      If any of those requests fails the runnable will return a negative
 *      response code.
 *      -------------------------------------------------------------------------------------
 *
 *********************************************************************************************************************/

#include "Rte_Cdd_MBBL_ResetExecutor.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
#include "Mcu.h"
#include "WdgM.h"
#include "Can.h"

#ifdef _MICROSOFT_C_VTT_
#include "CANoeAPI.h"
#endif

/* How many ticks shall the call to DoIP_Shutdown be executed and return SOAD_E_INPROGRESS before shutdown
 * is initiated anyway. The macro OS_MS2TICKS_<Counter Name>(x) can be used for conversion of ms to ticks.
 */
#define TCP_CLOSURE_TIMEOUT_TIME  OS_MS2TICKS_OsCounter_Core0(5000)

/* Id of the OS counter which shall be used to measure the waiting period */
#define TCP_CLOSURE_TIMEOUT_COUNTER_ID OsCounter_Core0

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of include and declaration area >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *
 * Used AUTOSAR Data Types
 *
 **********************************************************************************************************************
 *
 * Primitive Types:
 * ================
 * boolean: Boolean (standard type)
 * uint8: Integer in interval [0...255] (standard type)
 *
 * Enumeration Types:
 * ==================
 * BswM_ESH_KillAllRun: Enumeration of integer in interval [0...255] with enumerators
 *   RELEASED (0U)
 *   REQUESTED (1U)
 * EcuM_ModeType: Enumeration of integer in interval [0...3] with enumerators
 *   EcuMConf_EcuMResetMode_ECUM_RESET_IO (2U)
 *   EcuMConf_EcuMResetMode_ECUM_RESET_MCU (0U)
 *   EcuMConf_EcuMResetMode_ECUM_RESET_WAKEUP (3U)
 *   EcuMConf_EcuMResetMode_ECUM_RESET_WDG (1U)
 * EcuM_StateType: Enumeration of integer in interval [0...144] with enumerators
 *   ECUM_STATE_SLEEP (80U)
 *   ECUM_STATE_OFF (128U)
 *   ECUM_STATE_RESET (144U)
 *
 *********************************************************************************************************************/


#define Cdd_MBBL_ResetExecutor_START_SEC_CODE
#include "Cdd_MBBL_ResetExecutor_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Cdd_MBBL_ResetExecutor_Init
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Cdd_MBBL_ResetExecutor_Init_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, Cdd_MBBL_ResetExecutor_CODE) Cdd_MBBL_ResetExecutor_Init(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Cdd_MBBL_ResetExecutor_Init
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Pp_ResetExecution_HardReset
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <HardReset> of PortPrototype <Pp_ResetExecution>
 *
 **********************************************************************************************************************
 *
 * Exclusive Area Access:
 * ======================
 *   void Rte_Enter_EA_IllegalMcuResetReturn(void)
 *   void Rte_Exit_EA_IllegalMcuResetReturn(void)
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void Pp_ResetExecution_HardReset(boolean prepareWatchdog)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Pp_ResetExecution_HardReset_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, Cdd_MBBL_ResetExecutor_CODE) Pp_ResetExecution_HardReset(boolean prepareWatchdog) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Pp_ResetExecution_HardReset
 *********************************************************************************************************************/
  Os_TickType currentCounterVal = 0, initialCounterVal = 0;

  /* Avoid error frames during hard reset */
  Can_SetControllerMode(0, CAN_T_SLEEP);

  if (prepareWatchdog == TRUE)
  {
    /* Not yet implemented */
  }

  Mcu_PerformReset();

  /* This part should never be reached! */
  Rte_Enter_EA_IllegalMcuResetReturn();
  /* Block all ISRs and wait for an external Watchdog Reset */
  while(1)
  {
    ;
#ifdef _MICROSOFT_C_VTT_
    CANoeAPI_ConsumeTicks(1);
#endif
  }
  Rte_Exit_EA_IllegalMcuResetReturn();

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Pp_ResetExecution_SoftReset
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <SoftReset> of PortPrototype <Pp_ResetExecution>
 *
 **********************************************************************************************************************
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_Request_ESH_KillAllRunRequest_requestedMode(BswM_ESH_KillAllRun data)
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
 *   Std_ReturnType Rte_Call_EcuM_ShutdownTarget_SelectShutdownTarget(EcuM_StateType targetState, EcuM_ModeType resetSleepMode)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_EcuM_ShutdownTarget_E_NOT_OK
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType Pp_ResetExecution_SoftReset(void)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_Pi_ResetExecution_EXECUTION_FAILED
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Pp_ResetExecution_SoftReset_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, Cdd_MBBL_ResetExecutor_CODE) Pp_ResetExecution_SoftReset(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Pp_ResetExecution_SoftReset (returns application error)
 *********************************************************************************************************************/
  Std_ReturnType retVal = RTE_E_OK;

  if (Rte_Call_EcuM_ShutdownTarget_SelectShutdownTarget(ECUM_STATE_RESET, EcuMConf_EcuMResetMode_ECUM_RESET_MCU) != RTE_E_OK)
  {
    retVal = RTE_E_Pi_ResetExecution_EXECUTION_FAILED;
  }

  if (Rte_Write_Request_ESH_KillAllRunRequest_requestedMode(REQUESTED) != RTE_E_OK)
  {
    retVal = RTE_E_Pi_ResetExecution_EXECUTION_FAILED;
  }

  return retVal;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}


#define Cdd_MBBL_ResetExecutor_STOP_SEC_CODE
#include "Cdd_MBBL_ResetExecutor_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of function definition area >>            DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of function definition area >>              DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of removed code area >>                   DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of removed code area >>                     DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 MISRA 2012 violations and justifications
 *********************************************************************************************************************/

/* module specific MISRA deviations:
   MD_Rte_0624:  MISRA rule: Rule8.3
     Reason:     This MISRA violation is a consequence from the RTE requirements [SWS_Rte_01007] [SWS_Rte_01150].
                 The typedefs are never used in the same context.
     Risk:       No functional risk. Only a cast to uint8* is performed.
     Prevention: Not required.

   MD_Rte_3206:  MISRA rule: Rule2.7
     Reason:     The parameter are not used by the code in all possible code variants.
     Risk:       No functional risk.
     Prevention: Not required.

*/
