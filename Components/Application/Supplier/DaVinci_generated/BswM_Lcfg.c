/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *
 *                 This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                 Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                 All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  LICENSE
 *  -------------------------------------------------------------------------------------------------------------------
 *            Module: BswM
 *           Program: MSR_Daimler_SLP11
 *          Customer: Mercedes-Benz AG
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: TC3xx
 *    License Scope : The usage is restricted to CBD2200333_D05
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: BswM_Lcfg.c
 *   Generation Time: 2024-02-15 14:31:27
 *           Project: StartApplication - Version 1.0
 *          Delivery: CBD2200333_D05
 *      Tool Version: DaVinci Configurator Classic 5.25.50 SP5
 *
 *
 *********************************************************************************************************************/

#define BSWM_LCFG_SOURCE

/* -----------------------------------------------------------------------------
    &&&~ MISRA JUSTIFICATION
 ----------------------------------------------------------------------------- */
/* PRQA S 0785, 0786 EOF */ /* MD_CSL_DistinctIdentifiers */

/* -----------------------------------------------------------------------------
    &&&~ INCLUDE
 ----------------------------------------------------------------------------- */
/* PRQA S 0857 EOF */ /* MD_MSR_1.1_857 */
#include "BswM.h"
#include "BswM_Private_Cfg.h"
#include "SchM_BswM.h"

#if !defined (BSWM_LOCAL)
# define BSWM_LOCAL static
#endif

#if !defined (BSWM_LOCAL_INLINE) /* COV_BSWM_LOCAL_INLINE */
# define BSWM_LOCAL_INLINE LOCAL_INLINE
#endif



#define BSWM_START_SEC_CODE
/* PRQA S 5087 1 */ /* MD_MSR_MemMap */
#include "BswM_MemMap.h"

/* -----------------------------------------------------------------------------
    &&&~ LOCAL FUNCTION DECLARATIONS
 ----------------------------------------------------------------------------- */
/**********************************************************************************************************************
 *  BswM_Action_RuleHandler()
 **********************************************************************************************************************/
/*!
 * \brief       Executes a rule.
 * \details     Arbitrates a rule and executes corresponding action list.
 * \param[in]   handleId       Id of the rule to execute.
 * \param[in]   partitionIdx   Current partition context.
 * \return      E_OK      No action list was executed or corresponding action list was completely executed.
 * \return      E_NOT_OK  Action list was aborted because an action failed.
 * \pre         -
 * \context     ANY
 * \reentrant   TRUE
 * \synchronous TRUE
 */
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_RuleHandler(BswM_HandleType handleId,
                                                                   BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);


/**********************************************************************************************************************
 *  BswM_UpdateTimer()
 **********************************************************************************************************************/
/*!
 * \brief       Updates a timer.
 * \details     Set timer value of passed timerId to passed value and calculates the new state.
 * \param[in]   timerId        Id of the timer to update.
 * \param[in]   value          New value of the timer.
 * \param[in]   partitionIdx   Current partition context.
 * \pre         -
 * \context     ANY
 * \reentrant   TRUE
 * \synchronous TRUE
 */
BSWM_LOCAL_INLINE FUNC(void, BSWM_CODE) BswM_UpdateTimer(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx,
                                                         BswM_SizeOfTimerValueType timerId,
                                                         BswM_TimerValueType value);

/*! \addtogroup    BswMGeneratedFunctions BswM Generated Functions
 * \{
 */
/* PRQA S 0779 FUNCTIONDECLARATIONS */ /* MD_MSR_Rule5.2_0779 */

/**********************************************************************************************************************
 *  Init
 *********************************************************************************************************************/
/*! \defgroup    Init
 * \{
 */
/**********************************************************************************************************************
 *  BswM_InitGenVarAndInitAL_BSWM_SINGLEPARTITION
 *********************************************************************************************************************/
/*!
 * \brief       Initializes BswM.
 * \details     Part of the BswM_Init. Initializes all generated variables and executes action lists for initialization.
 * \pre         -
 * \reentrant   FALSE
 * \synchronous TRUE
 * \note        May only be called by BswM_Init.
 */
BSWM_LOCAL FUNC(void, BSWM_CODE) BswM_InitGenVarAndInitAL_BSWM_SINGLEPARTITION(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
/*! \} */ /* End of group Init */

/**********************************************************************************************************************
 *  Common
 *********************************************************************************************************************/
/*! \defgroup    Common
 * \{
 */
/**********************************************************************************************************************
 *  BswM_ModeNotificationFct_BSWM_SINGLEPARTITION
 *********************************************************************************************************************/
/*!
 * \brief       Switch Modes of RTE and writes RTE values.
 * \details     Forwards a BswM Switch Action to the RTE and writes value of RteRequestPorts to RTE.
 * \pre         -
 * \context     TASK
 * \reentrant   TRUE
 * \synchronous TRUE
 * \note        May only be called by BswM_MainFunction.
 */
BSWM_LOCAL FUNC(void, BSWM_CODE) BswM_ModeNotificationFct_BSWM_SINGLEPARTITION(void);
/*! \} */ /* End of group Common */

/**********************************************************************************************************************
 *  SwcModeRequestUpdate
 *********************************************************************************************************************/
/*! \defgroup    SwcModeRequestUpdate
 * \{
 */
/**********************************************************************************************************************
 *  BswM_SwcModeRequestUpdateFct_BSWM_SINGLEPARTITION
 *********************************************************************************************************************/
/*!
 * \brief       Reads port values from RTE.
 * \details     Gets the current value of SwcModeRequest Ports and SwcNotification Ports from RTE.
 * \pre         -
 * \context     TASK
 * \reentrant   TRUE
 * \synchronous TRUE
 * \note        May only be called by BswM_MainFunction.
 */
BSWM_LOCAL FUNC(void, BSWM_CODE) BswM_SwcModeRequestUpdateFct_BSWM_SINGLEPARTITION(void);
/*! \} */ /* End of group SwcModeRequestUpdate */

/**********************************************************************************************************************
 *  BswMActionFunctions
 *********************************************************************************************************************/
/*! \defgroup    BswMActionFunctions
 * \{
 */

/*!
 * \{
 * \brief       Executes an action.
 * \details     Generated function which executes the configured action.
 * \param[IN]   handleId      ID of the parameter set which shall be used for calling the action.
 * \param[IN]   partitionIdx  Current partition context
 * \return      E_OK      Action was successfully executed.
 * \return      E_NOT_OK  Execution of Action failed
 * \pre         -
 * \context     ANY
 * \reentrant   TRUE
 * \synchronous TRUE
 */
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_INIT_Action_SecOC_Init_Left(BswM_HandleType handleId, BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_ESH_Action_EnterExclusiveArea_Left(BswM_HandleType handleId, BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_ESH_Action_EcuMClearValidatedWakeupEvents_Left(BswM_HandleType handleId, BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_ESH_Action_OnEnterPostRun_Left(BswM_HandleType handleId, BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_ESH_Action_SwitchPostRun_Left(BswM_HandleType handleId, BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_ESH_Action_ExitExclusiveArea_Left(BswM_HandleType handleId, BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_ESH_Action_OnEnterShutdown_Left(BswM_HandleType handleId, BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_ESH_Action_EcuMGoToSelectedShutdownTarget_Left(BswM_HandleType handleId, BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_ESH_Action_OnEnterPrepShutdown_Left(BswM_HandleType handleId, BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_ESH_Action_SwitchShutdown_Left(BswM_HandleType handleId, BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_ESH_Action_OnEnterWakeup_Left(BswM_HandleType handleId, BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_ESH_Action_SwitchWakeup_Left(BswM_HandleType handleId, BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_ESH_Action_DemInit_Left(BswM_HandleType handleId, BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_ESH_Action_OnEnterRun_Left(BswM_HandleType handleId, BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_ESH_Action_SwitchRun_Left(BswM_HandleType handleId, BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_ESH_Action_DemShutdown_Left(BswM_HandleType handleId, BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_ESH_Action_OnEnterWaitForNvm_Left(BswM_HandleType handleId, BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_INIT_Action_Can_Init_Left(BswM_HandleType handleId, BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_INIT_Action_CanIf_Init_Left(BswM_HandleType handleId, BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_INIT_Action_Com_Init_Left(BswM_HandleType handleId, BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_INIT_Action_IpduM_Init_Left(BswM_HandleType handleId, BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_INIT_Action_PduR_Init_Left(BswM_HandleType handleId, BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_INIT_Action_CanSM_Init_Left(BswM_HandleType handleId, BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_INIT_Action_CanNm_Init_Left(BswM_HandleType handleId, BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_INIT_Action_Nm_Init_Left(BswM_HandleType handleId, BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_INIT_Action_CanTp_Init_Left(BswM_HandleType handleId, BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_INIT_Action_EnableInterrupts_Left(BswM_HandleType handleId, BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_INIT_Action_ComM_Init_Left(BswM_HandleType handleId, BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_INIT_Action_Dcm_Init_Left(BswM_HandleType handleId, BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_INIT_Action_Rte_Start_Left(BswM_HandleType handleId, BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_INIT_Action_Port_Init_Left(BswM_HandleType handleId, BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_INIT_Action_Dma_Init_Left(BswM_HandleType handleId, BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_INIT_Action_Spi_Init_Left(BswM_HandleType handleId, BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_INIT_Action_Wdg_17_Scu_Init_Left(BswM_HandleType handleId, BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_INIT_Action_Icu_17_TimerIp_Init_Left(BswM_HandleType handleId, BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_INIT_Action_WdgM_Init_Left(BswM_HandleType handleId, BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_INIT_Action_Csm_Init_Left(BswM_HandleType handleId, BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_INIT_Action_Crypto_30_LibCv_Init_Left(BswM_HandleType handleId, BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_INIT_Action_Crypto_30_vHsm_Init_Left(BswM_HandleType handleId, BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_INIT_Action_CryIf_Init_Left(BswM_HandleType handleId, BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_INIT_Action_KeyM_Init_Left(BswM_HandleType handleId, BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_INIT_Action_NvMReadAll_Left(BswM_HandleType handleId, BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_INIT_Action_SBC_Init_Left(BswM_HandleType handleId, BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_INIT_Action_Adc_Init_Left(BswM_HandleType handleId, BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_INIT_Action_AdcIf_Init_Left(BswM_HandleType handleId, BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_INIT_Action_Gpt_Init_Left(BswM_HandleType handleId, BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_INIT_Action_Pwm_17_GtmCcu6_Init_Left(BswM_HandleType handleId, BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_ESH_Action_ComMCheckPendingRequests_Left_Left(BswM_HandleType handleId, BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_ESH_Action_DemPostRunRequested_Left_Left(BswM_HandleType handleId, BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_INIT_Action_ComM_PreInit_Left(BswM_HandleType handleId, BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_INIT_Action_Nm_PreInit_Left(BswM_HandleType handleId, BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_INIT_Action_ComM_PostInit_Left(BswM_HandleType handleId, BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_INIT_Action_Nm_PostInit_Left(BswM_HandleType handleId, BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_INIT_Action_StbM_Init_Left(BswM_HandleType handleId, BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_INIT_Action_CanTSyn_Init_Left(BswM_HandleType handleId, BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_INIT_Action_Smu_Init_Left(BswM_HandleType handleId, BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_INIT_Action_RCM_Init_Left(BswM_HandleType handleId, BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_INIT_Action_StbM_PreInit_Left(BswM_HandleType handleId, BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_INIT_Action_StbM_PostInit_Left(BswM_HandleType handleId, BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_INIT_Action_Rtm_Init_Left(BswM_HandleType handleId, BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_Rtm_CpuLoadMeasurementStart_Left(BswM_HandleType handleId, BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_Action_Rtm_Shutdown_Left(BswM_HandleType handleId, BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_INIT_Action_CanTSyn_PreInit_Left(BswM_HandleType handleId, BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_Action_RTE_SWITCH_BswMSwitchPort_SwcDiagCommunicationMode_COMM_FULL_COMMUNICATION_Left(BswM_HandleType handleId, BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_Action_RTE_SWITCH_BswMSwitchPort_SwcDiagCommunicationMode_COMM_NO_COMMUNICATION_Left(BswM_HandleType handleId, BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_INIT_Action_CanTSyn_Init_Right(BswM_HandleType handleId, BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_ESH_Action_ComMCheckPendingRequests_Right_Right(BswM_HandleType handleId, BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_ESH_Action_DemPostRunRequested_Right_Right(BswM_HandleType handleId, BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
/*! \} */ /* End of sharing description for BswMActionFunctions */
#define BswM_Action_INIT_Action_SecOC_Init_Right BswM_Action_INIT_Action_SecOC_Init_Left
#define BswM_Action_ESH_Action_EnterExclusiveArea_Right BswM_Action_ESH_Action_EnterExclusiveArea_Left
#define BswM_Action_ESH_Action_EcuMClearValidatedWakeupEvents_Right BswM_Action_ESH_Action_EcuMClearValidatedWakeupEvents_Left
#define BswM_Action_ESH_Action_OnEnterPostRun_Right BswM_Action_ESH_Action_OnEnterPostRun_Left
#define BswM_Action_ESH_Action_SwitchPostRun_Right BswM_Action_ESH_Action_SwitchPostRun_Left
#define BswM_Action_ESH_Action_ExitExclusiveArea_Right BswM_Action_ESH_Action_ExitExclusiveArea_Left
#define BswM_Action_ESH_Action_OnEnterShutdown_Right BswM_Action_ESH_Action_OnEnterShutdown_Left
#define BswM_Action_ESH_Action_EcuMGoToSelectedShutdownTarget_Right BswM_Action_ESH_Action_EcuMGoToSelectedShutdownTarget_Left
#define BswM_Action_ESH_Action_OnEnterPrepShutdown_Right BswM_Action_ESH_Action_OnEnterPrepShutdown_Left
#define BswM_Action_ESH_Action_SwitchShutdown_Right BswM_Action_ESH_Action_SwitchShutdown_Left
#define BswM_Action_ESH_Action_OnEnterWakeup_Right BswM_Action_ESH_Action_OnEnterWakeup_Left
#define BswM_Action_ESH_Action_SwitchWakeup_Right BswM_Action_ESH_Action_SwitchWakeup_Left
#define BswM_Action_INIT_Action_Dem_Init_Left BswM_Action_ESH_Action_DemInit_Left
#define BswM_Action_ESH_Action_DemInit_Right BswM_Action_ESH_Action_DemInit_Left
#define BswM_Action_INIT_Action_Dem_Init_Right BswM_Action_ESH_Action_DemInit_Left
#define BswM_Action_ESH_Action_OnEnterRun_Right BswM_Action_ESH_Action_OnEnterRun_Left
#define BswM_Action_ESH_Action_SwitchRun_Right BswM_Action_ESH_Action_SwitchRun_Left
#define BswM_Action_ESH_Action_DemShutdown_Right BswM_Action_ESH_Action_DemShutdown_Left
#define BswM_Action_ESH_Action_OnEnterWaitForNvm_Right BswM_Action_ESH_Action_OnEnterWaitForNvm_Left
#define BswM_Action_INIT_Action_Can_Init_Right BswM_Action_INIT_Action_Can_Init_Left
#define BswM_Action_INIT_Action_CanIf_Init_Right BswM_Action_INIT_Action_CanIf_Init_Left
#define BswM_Action_INIT_Action_Com_Init_Right BswM_Action_INIT_Action_Com_Init_Left
#define BswM_Action_INIT_Action_IpduM_Init_Right BswM_Action_INIT_Action_IpduM_Init_Left
#define BswM_Action_INIT_Action_PduR_Init_Right BswM_Action_INIT_Action_PduR_Init_Left
#define BswM_Action_INIT_Action_CanSM_Init_Right BswM_Action_INIT_Action_CanSM_Init_Left
#define BswM_Action_INIT_Action_CanNm_Init_Right BswM_Action_INIT_Action_CanNm_Init_Left
#define BswM_Action_INIT_Action_Nm_Init_Right BswM_Action_INIT_Action_Nm_Init_Left
#define BswM_Action_INIT_Action_CanTp_Init_Right BswM_Action_INIT_Action_CanTp_Init_Left
#define BswM_Action_INIT_Action_EnableInterrupts_Right BswM_Action_INIT_Action_EnableInterrupts_Left
#define BswM_Action_INIT_Action_ComM_Init_Right BswM_Action_INIT_Action_ComM_Init_Left
#define BswM_Action_INIT_Action_Dcm_Init_Right BswM_Action_INIT_Action_Dcm_Init_Left
#define BswM_Action_INIT_Action_Rte_Start_Right BswM_Action_INIT_Action_Rte_Start_Left
#define BswM_Action_INIT_Action_Port_Init_Right BswM_Action_INIT_Action_Port_Init_Left
#define BswM_Action_INIT_Action_Dma_Init_Right BswM_Action_INIT_Action_Dma_Init_Left
#define BswM_Action_INIT_Action_Spi_Init_Right BswM_Action_INIT_Action_Spi_Init_Left
#define BswM_Action_INIT_Action_Wdg_17_Scu_Init_Right BswM_Action_INIT_Action_Wdg_17_Scu_Init_Left
#define BswM_Action_INIT_Action_Icu_17_TimerIp_Init_Right BswM_Action_INIT_Action_Icu_17_TimerIp_Init_Left
#define BswM_Action_INIT_Action_WdgM_Init_Right BswM_Action_INIT_Action_WdgM_Init_Left
#define BswM_Action_INIT_Action_Csm_Init_Right BswM_Action_INIT_Action_Csm_Init_Left
#define BswM_Action_INIT_Action_Crypto_30_LibCv_Init_Right BswM_Action_INIT_Action_Crypto_30_LibCv_Init_Left
#define BswM_Action_INIT_Action_Crypto_30_vHsm_Init_Right BswM_Action_INIT_Action_Crypto_30_vHsm_Init_Left
#define BswM_Action_INIT_Action_CryIf_Init_Right BswM_Action_INIT_Action_CryIf_Init_Left
#define BswM_Action_INIT_Action_KeyM_Init_Right BswM_Action_INIT_Action_KeyM_Init_Left
#define BswM_Action_INIT_Action_NvMReadAll_Right BswM_Action_INIT_Action_NvMReadAll_Left
#define BswM_Action_INIT_Action_SBC_Init_Right BswM_Action_INIT_Action_SBC_Init_Left
#define BswM_Action_INIT_Action_Adc_Init_Right BswM_Action_INIT_Action_Adc_Init_Left
#define BswM_Action_INIT_Action_AdcIf_Init_Right BswM_Action_INIT_Action_AdcIf_Init_Left
#define BswM_Action_INIT_Action_Gpt_Init_Right BswM_Action_INIT_Action_Gpt_Init_Left
#define BswM_Action_INIT_Action_Pwm_17_GtmCcu6_Init_Right BswM_Action_INIT_Action_Pwm_17_GtmCcu6_Init_Left
#define BswM_Action_INIT_Action_ComM_PreInit_Right BswM_Action_INIT_Action_ComM_PreInit_Left
#define BswM_Action_INIT_Action_Nm_PreInit_Right BswM_Action_INIT_Action_Nm_PreInit_Left
#define BswM_Action_INIT_Action_ComM_PostInit_Right BswM_Action_INIT_Action_ComM_PostInit_Left
#define BswM_Action_INIT_Action_Nm_PostInit_Right BswM_Action_INIT_Action_Nm_PostInit_Left
#define BswM_Action_INIT_Action_StbM_Init_Right BswM_Action_INIT_Action_StbM_Init_Left
#define BswM_Action_INIT_Action_Smu_Init_Right BswM_Action_INIT_Action_Smu_Init_Left
#define BswM_Action_INIT_Action_RCM_Init_Right BswM_Action_INIT_Action_RCM_Init_Left
#define BswM_Action_INIT_Action_StbM_PreInit_Right BswM_Action_INIT_Action_StbM_PreInit_Left
#define BswM_Action_INIT_Action_StbM_PostInit_Right BswM_Action_INIT_Action_StbM_PostInit_Left
#define BswM_Action_INIT_Action_Rtm_Init_Right BswM_Action_INIT_Action_Rtm_Init_Left
#define BswM_Action_Rtm_CpuLoadMeasurementStart_Right BswM_Action_Rtm_CpuLoadMeasurementStart_Left
#define BswM_Action_Action_Rtm_Shutdown_Right BswM_Action_Action_Rtm_Shutdown_Left
#define BswM_Action_INIT_Action_CanTSyn_PreInit_Right BswM_Action_INIT_Action_CanTSyn_PreInit_Left
#define BswM_Action_Action_RTE_SWITCH_BswMSwitchPort_SwcDiagCommunicationMode_COMM_FULL_COMMUNICATION_Right BswM_Action_Action_RTE_SWITCH_BswMSwitchPort_SwcDiagCommunicationMode_COMM_FULL_COMMUNICATION_Left
#define BswM_Action_Action_RTE_SWITCH_BswMSwitchPort_SwcDiagCommunicationMode_COMM_NO_COMMUNICATION_Right BswM_Action_Action_RTE_SWITCH_BswMSwitchPort_SwcDiagCommunicationMode_COMM_NO_COMMUNICATION_Left
/*! \} */ /* End of group BswMActionFunctions */

/**********************************************************************************************************************
 *  BswMExpressionFunctions
 *********************************************************************************************************************/
/*! \defgroup    BswMExpressionFunctions
 * \{
 */

/*!
 * \{
 * \brief       Evaluates a logical expression.
 * \details     Generated function which evaluates the configured logical expression.
 * \return      1  If logical expression evaluates to true
 * \return      0  If logical expression evaluates to false
 * \pre         -
 * \context     ANY
 * \reentrant   TRUE
 * \synchronous TRUE
 */
BSWM_LOCAL FUNC(uint8, BSWM_CODE) BswM_ExpFct_CC_LE_RBTM_FL_BODY3_8uqv9blm85ehm0msat385m76v_03d5f5f6_TX_Left(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(uint8, BSWM_CODE) BswM_ExpFct_ESH_LE_RunToPostRunTransition_Left(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(uint8, BSWM_CODE) BswM_ExpFct_ESH_LE_RunReached_Left(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(uint8, BSWM_CODE) BswM_ExpFct_ESH_LE_NoRunAndNoKillAllRequest_Left(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(uint8, BSWM_CODE) BswM_ExpFct_ESH_LE_NoRunReasons_Left(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(uint8, BSWM_CODE) BswM_ExpFct_ESH_LE_AllChannelsNoCom_Left(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(uint8, BSWM_CODE) BswM_ExpFct_ESH_LE_RunReleased_Left(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(uint8, BSWM_CODE) BswM_ExpFct_ESH_LE_ComMNoPendingRequests_Left(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(uint8, BSWM_CODE) BswM_ExpFct_ESH_LE_WaitForNvMToShutdown_Left(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(uint8, BSWM_CODE) BswM_ExpFct_ESH_LE_NoWakeupOrKillAll_Left(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(uint8, BSWM_CODE) BswM_ExpFct_ESH_LE_NoWakeup_Left(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(uint8, BSWM_CODE) BswM_ExpFct_ESH_LE_WakeupToPrepShutdown_Left(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(uint8, BSWM_CODE) BswM_ExpFct_ESH_LE_WaitForNvMToWakeup_Left(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(uint8, BSWM_CODE) BswM_ExpFct_ESH_LE_ValidWakeup_Left(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(uint8, BSWM_CODE) BswM_ExpFct_ESH_LE_WakeupToRun_Left(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(uint8, BSWM_CODE) BswM_ExpFct_ESH_LE_DemNotInitialized_Left(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(uint8, BSWM_CODE) BswM_ExpFct_ESH_LE_InitToWakeup_Left(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(uint8, BSWM_CODE) BswM_ExpFct_ESH_LE_Dem_PostRunRequested_Left(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(uint8, BSWM_CODE) BswM_ExpFct_ESH_LE_PostRunToPrep_Left(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(uint8, BSWM_CODE) BswM_ExpFct_ESH_LE_PostRunReleased_Left(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(uint8, BSWM_CODE) BswM_ExpFct_ESH_LE_PostRunToRun_Left(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(uint8, BSWM_CODE) BswM_ExpFct_ESH_LE_RunRequestsOrWakeup_Left(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(uint8, BSWM_CODE) BswM_ExpFct_ESH_LE_RunRequested_Left(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(uint8, BSWM_CODE) BswM_ExpFct_ESH_LE_PostRun_Left(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(uint8, BSWM_CODE) BswM_ExpFct_ESH_LE_PrepShutdownToWaitForNvM_Left(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(uint8, BSWM_CODE) BswM_ExpFct_ESH_LE_EcuMStateSleepOrShutdown_Left(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(uint8, BSWM_CODE) BswM_ExpFct_CC_LE_RBTM_FL_BODY3_8uqv9blm85ehm0msat385m76v_03d5f5f6_PNC_00_MAPPING_b2c42696_RX_Left(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(uint8, BSWM_CODE) BswM_ExpFct_CC_LE_PNC_RBTM_FL_BODY3_8uqv9blm85ehm0msat385m76v_03d5f5f6_PNC_00_MAPPING_b2c42696_NEQ_NOCOM_Left(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(uint8, BSWM_CODE) BswM_ExpFct_CC_LE_RBTM_FL_BODY3_8uqv9blm85ehm0msat385m76v_03d5f5f6_PNC_00_MAPPING_b2c42696_RX_DM_Left(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(uint8, BSWM_CODE) BswM_ExpFct_CC_LE_RBTM_FL_BODY3_8uqv9blm85ehm0msat385m76v_03d5f5f6_PNC_00_MAPPING_b2c42696_TX_Left(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(uint8, BSWM_CODE) BswM_ExpFct_CC_LE_RBTM_FL_BODY3_8uqv9blm85ehm0msat385m76v_03d5f5f6_PNC_20_MAPPING_796df885_RX_DM_Left(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(uint8, BSWM_CODE) BswM_ExpFct_CC_LE_PNC_RBTM_FL_BODY3_8uqv9blm85ehm0msat385m76v_03d5f5f6_PNC_20_MAPPING_796df885_NEQ_NOCOM_Left(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(uint8, BSWM_CODE) BswM_ExpFct_CC_LE_RBTM_FL_BODY3_8uqv9blm85ehm0msat385m76v_03d5f5f6_PNC_20_MAPPING_796df885_TX_Left(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(uint8, BSWM_CODE) BswM_ExpFct_CC_LE_RBTM_FL_BODY3_8uqv9blm85ehm0msat385m76v_03d5f5f6_PNC_20_MAPPING_796df885_RX_Left(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(uint8, BSWM_CODE) BswM_ExpFct_LE_BswMRule_SwcDiagComMState_Left(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(uint8, BSWM_CODE) BswM_ExpFct_ESH_LE_RunToPostRunTransition_Right(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(uint8, BSWM_CODE) BswM_ExpFct_ESH_LE_NoRunAndNoKillAllRequest_Right(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(uint8, BSWM_CODE) BswM_ExpFct_ESH_LE_NoRunReasons_Right(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(uint8, BSWM_CODE) BswM_ExpFct_ESH_LE_WaitForNvMToShutdown_Right(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(uint8, BSWM_CODE) BswM_ExpFct_ESH_LE_NoWakeupOrKillAll_Right(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(uint8, BSWM_CODE) BswM_ExpFct_ESH_LE_WakeupToPrepShutdown_Right(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(uint8, BSWM_CODE) BswM_ExpFct_ESH_LE_WaitForNvMToWakeup_Right(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(uint8, BSWM_CODE) BswM_ExpFct_ESH_LE_WakeupToRun_Right(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(uint8, BSWM_CODE) BswM_ExpFct_ESH_LE_Dem_PostRunRequested_Right(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(uint8, BSWM_CODE) BswM_ExpFct_ESH_LE_PostRunToPrep_Right(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(uint8, BSWM_CODE) BswM_ExpFct_ESH_LE_PostRunToRun_Right(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(uint8, BSWM_CODE) BswM_ExpFct_ESH_LE_RunRequestsOrWakeup_Right(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(uint8, BSWM_CODE) BswM_ExpFct_ESH_LE_PrepShutdownToWaitForNvM_Right(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(uint8, BSWM_CODE) BswM_ExpFct_CC_LE_RBTM_FR_BODY3_4xwwtd59665s787n6ctawh7k8_23a94727_PNC_00_MAPPING_b2c42696_RX_DM_Right(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(uint8, BSWM_CODE) BswM_ExpFct_CC_LE_RBTM_FR_BODY3_4xwwtd59665s787n6ctawh7k8_23a94727_PNC_00_MAPPING_b2c42696_RX_Right(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(uint8, BSWM_CODE) BswM_ExpFct_CC_LE_RBTM_FR_BODY3_4xwwtd59665s787n6ctawh7k8_23a94727_PNC_20_MAPPING_796df885_TX_Right(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(uint8, BSWM_CODE) BswM_ExpFct_CC_LE_RBTM_FR_BODY3_4xwwtd59665s787n6ctawh7k8_23a94727_PNC_00_MAPPING_b2c42696_TX_Right(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(uint8, BSWM_CODE) BswM_ExpFct_CC_LE_RBTM_FR_BODY3_4xwwtd59665s787n6ctawh7k8_23a94727_PNC_20_MAPPING_796df885_RX_DM_Right(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
BSWM_LOCAL FUNC(uint8, BSWM_CODE) BswM_ExpFct_CC_LE_RBTM_FR_BODY3_4xwwtd59665s787n6ctawh7k8_23a94727_PNC_20_MAPPING_796df885_RX_Right(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
/*! \} */ /* End of sharing description for BswMExpressionFunctions */
#define BswM_ExpFct_CC_LE_RBTM_FR_BODY3_4xwwtd59665s787n6ctawh7k8_23a94727_TX_Right BswM_ExpFct_CC_LE_RBTM_FL_BODY3_8uqv9blm85ehm0msat385m76v_03d5f5f6_TX_Left
#define BswM_ExpFct_ESH_LE_RunReached_Right BswM_ExpFct_ESH_LE_RunReached_Left
#define BswM_ExpFct_ESH_LE_AllChannelsNoCom_Right BswM_ExpFct_ESH_LE_AllChannelsNoCom_Left
#define BswM_ExpFct_ESH_LE_RunReleased_Right BswM_ExpFct_ESH_LE_RunReleased_Left
#define BswM_ExpFct_ESH_LE_ComMNoPendingRequests_Right BswM_ExpFct_ESH_LE_ComMNoPendingRequests_Left
#define BswM_ExpFct_ESH_LE_NoWakeup_Right BswM_ExpFct_ESH_LE_NoWakeup_Left
#define BswM_ExpFct_ESH_LE_ValidWakeup_Right BswM_ExpFct_ESH_LE_ValidWakeup_Left
#define BswM_ExpFct_ESH_LE_DemNotInitialized_Right BswM_ExpFct_ESH_LE_DemNotInitialized_Left
#define BswM_ExpFct_ESH_LE_InitToWakeup_Right BswM_ExpFct_ESH_LE_InitToWakeup_Left
#define BswM_ExpFct_ESH_LE_PostRunReleased_Right BswM_ExpFct_ESH_LE_PostRunReleased_Left
#define BswM_ExpFct_ESH_LE_RunRequested_Right BswM_ExpFct_ESH_LE_RunRequested_Left
#define BswM_ExpFct_ESH_LE_PostRun_Right BswM_ExpFct_ESH_LE_PostRun_Left
#define BswM_ExpFct_ESH_LE_EcuMStateSleepOrShutdown_Right BswM_ExpFct_ESH_LE_EcuMStateSleepOrShutdown_Left
#define BswM_ExpFct_CC_LE_PNC_RBTM_FR_BODY3_4xwwtd59665s787n6ctawh7k8_23a94727_PNC_00_MAPPING_b2c42696_NEQ_NOCOM_Right BswM_ExpFct_CC_LE_PNC_RBTM_FL_BODY3_8uqv9blm85ehm0msat385m76v_03d5f5f6_PNC_00_MAPPING_b2c42696_NEQ_NOCOM_Left
#define BswM_ExpFct_CC_LE_PNC_RBTM_FR_BODY3_4xwwtd59665s787n6ctawh7k8_23a94727_PNC_20_MAPPING_796df885_NEQ_NOCOM_Right BswM_ExpFct_CC_LE_PNC_RBTM_FL_BODY3_8uqv9blm85ehm0msat385m76v_03d5f5f6_PNC_20_MAPPING_796df885_NEQ_NOCOM_Left
#define BswM_ExpFct_LE_BswMRule_SwcDiagComMState_001_Right BswM_ExpFct_LE_BswMRule_SwcDiagComMState_Left
/*! \} */ /* End of group BswMExpressionFunctions */
/* PRQA L:FUNCTIONDECLARATIONS */
/*! \} */ /* End of group BswMGeneratedFunctions */

#define BSWM_STOP_SEC_CODE
/* PRQA S 5087 1 */ /* MD_MSR_MemMap */
#include "BswM_MemMap.h"


/* -----------------------------------------------------------------------------
    &&&~ LOCAL VARIABLE DECLARATIONS
 ----------------------------------------------------------------------------- */

/**********************************************************************************************************************
 *  LOCAL DATA PROTOTYPES
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: LOCAL DATA PROTOTYPES
**********************************************************************************************************************/



/**********************************************************************************************************************
 *  LOCAL DATA
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: LOCAL DATA
**********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA
**********************************************************************************************************************/


/* PRQA S 0310 GLOBALDATADECLARATIONS */ /* MD_BSWM_0310 */
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL DATA
**********************************************************************************************************************/
/**********************************************************************************************************************
  BswM_ActionItemsLeft
**********************************************************************************************************************/
/** 
  \var    BswM_ActionItemsLeft
  \details
  Element         Description
  ActionsIdx      the index of the 1:1 relation pointing to BswM_Actions
  Parameter       the enum value of the according target of the 0:1 relation pointing to BswM_ComMAllowComParameters,BswM_ComMModeLimitationParameters,BswM_ComMModeSwitchParameters,BswM_ComDMControlParameters,BswM_EcuMSelectShutdownTargetParameters,BswM_EcuMStateSwitchParameters,BswM_IdsmBlockStateChangeRequestParameters,BswM_LinScheduleRequestParameters,BswM_NmControlParameters,BswM_ComSwitchIPduModeParameters,BswM_ComPduGroupSwitchParameters,BswM_ComPduGroupHandlingParameters,BswM_ComDMHandlingParameters,BswM_ComTriggerIPduSendParameters,BswM_PduRouterControlParameters,BswM_TimerControlParameters,BswM_GenericModeParameters,BswM_GenericModeRefParameters,BswM_J1939DcmStateParameters,BswM_J1939RmStateParameters,BswM_SdClientParameters,BswM_SdConsumedParameters,BswM_SdServerParameters,BswM_SdServiceGroupSwitchParameters,BswM_RuleControlParameters,BswM_ActionLists,BswM_Rules
  ParameterIdx    the index of the 0:1 relation pointing to BswM_ComMAllowComParameters,BswM_ComMModeLimitationParameters,BswM_ComMModeSwitchParameters,BswM_ComDMControlParameters,BswM_EcuMSelectShutdownTargetParameters,BswM_EcuMStateSwitchParameters,BswM_IdsmBlockStateChangeRequestParameters,BswM_LinScheduleRequestParameters,BswM_NmControlParameters,BswM_ComSwitchIPduModeParameters,BswM_ComPduGroupSwitchParameters,BswM_ComPduGroupHandlingParameters,BswM_ComDMHandlingParameters,BswM_ComTriggerIPduSendParameters,BswM_PduRouterControlParameters,BswM_TimerControlParameters,BswM_GenericModeParameters,BswM_GenericModeRefParameters,BswM_J1939DcmStateParameters,BswM_J1939RmStateParameters,BswM_SdClientParameters,BswM_SdConsumedParameters,BswM_SdServerParameters,BswM_SdServiceGroupSwitchParameters,BswM_RuleControlParameters,BswM_ActionLists,BswM_Rules
*/ 
#define BSWM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(BswM_ActionItemsType, BSWM_CONST) BswM_ActionItemsLeft[114] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    ActionsIdx  Parameter                                                  ParameterIdx                             Referable Keys */
  { /*     0 */        67u, BSWM_COMPDUGROUPHANDLINGPARAMETERS_PARAMETEROFACTIONITEMS,                                0u },  /* [AL_CC_AL_RBTM_FL_BODY3_8uqv9blm85ehm0msat385m76v_03d5f5f6_TX_Disable] */
  { /*     1 */        67u, BSWM_COMPDUGROUPHANDLINGPARAMETERS_PARAMETEROFACTIONITEMS,                                1u },  /* [AL_CC_AL_RBTM_FL_BODY3_8uqv9blm85ehm0msat385m76v_03d5f5f6_TX_EnableNoinit] */
  { /*     2 */        58u,                            BSWM_NO_PARAMETEROFACTIONITEMS, BSWM_NO_PARAMETERIDXOFACTIONITEMS },  /* [AL_ESH_AL_ExitRun] */
  { /*     3 */        65u,                            BSWM_NO_PARAMETEROFACTIONITEMS, BSWM_NO_PARAMETERIDXOFACTIONITEMS },  /* [AL_ESH_AL_ExitRun] */
  { /*     4 */         0u,                         BSWM_RULES_PARAMETEROFACTIONITEMS,                                2u },  /* [AL_ESH_AL_ExitRun] */
  { /*     5 */        57u,                            BSWM_NO_PARAMETEROFACTIONITEMS, BSWM_NO_PARAMETERIDXOFACTIONITEMS },  /* [AL_ESH_AL_ExitRun] */
  { /*     6 */        66u,        BSWM_COMMALLOWCOMPARAMETERS_PARAMETEROFACTIONITEMS,                                0u },  /* [AL_ESH_AL_RunToPostRun] */
  { /*     7 */        60u,                            BSWM_NO_PARAMETEROFACTIONITEMS, BSWM_NO_PARAMETERIDXOFACTIONITEMS },  /* [AL_ESH_AL_RunToPostRun] */
  { /*     8 */        56u,                            BSWM_NO_PARAMETEROFACTIONITEMS, BSWM_NO_PARAMETERIDXOFACTIONITEMS },  /* [AL_ESH_AL_RunToPostRun] */
  { /*     9 */         1u,     BSWM_ECUMSTATESWITCHPARAMETERS_PARAMETEROFACTIONITEMS,                                0u },  /* [AL_ESH_AL_RunToPostRun] */
  { /*    10 */        49u,                            BSWM_NO_PARAMETEROFACTIONITEMS, BSWM_NO_PARAMETERIDXOFACTIONITEMS },  /* [AL_ESH_AL_RunToPostRun] */
  { /*    11 */        63u,         BSWM_GENERICMODEPARAMETERS_PARAMETEROFACTIONITEMS,                                0u },  /* [AL_ESH_AL_RunToPostRun] */
  { /*    12 */        53u,                            BSWM_NO_PARAMETEROFACTIONITEMS, BSWM_NO_PARAMETERIDXOFACTIONITEMS },  /* [AL_ESH_AL_WaitForNvMToShutdown] */
  { /*    13 */        59u,                            BSWM_NO_PARAMETEROFACTIONITEMS, BSWM_NO_PARAMETERIDXOFACTIONITEMS },  /* [AL_ESH_AL_WaitForNvMToShutdown] */
  { /*    14 */        55u,                            BSWM_NO_PARAMETEROFACTIONITEMS, BSWM_NO_PARAMETERIDXOFACTIONITEMS },  /* [AL_ESH_AL_WakeupToPrep] */
  { /*    15 */         1u,     BSWM_ECUMSTATESWITCHPARAMETERS_PARAMETEROFACTIONITEMS,                                1u },  /* [AL_ESH_AL_WakeupToPrep] */
  { /*    16 */        47u,                            BSWM_NO_PARAMETEROFACTIONITEMS, BSWM_NO_PARAMETERIDXOFACTIONITEMS },  /* [AL_ESH_AL_WakeupToPrep] */
  { /*    17 */        63u,         BSWM_GENERICMODEPARAMETERS_PARAMETEROFACTIONITEMS,                                1u },  /* [AL_ESH_AL_WakeupToPrep] */
  { /*    18 */        51u,                            BSWM_NO_PARAMETEROFACTIONITEMS, BSWM_NO_PARAMETERIDXOFACTIONITEMS },  /* [AL_ESH_AL_WaitForNvMWakeup] */
  { /*    19 */        46u,                            BSWM_NO_PARAMETEROFACTIONITEMS, BSWM_NO_PARAMETERIDXOFACTIONITEMS },  /* [AL_ESH_AL_WaitForNvMWakeup] */
  { /*    20 */        63u,         BSWM_GENERICMODEPARAMETERS_PARAMETEROFACTIONITEMS,                                2u },  /* [AL_ESH_AL_WaitForNvMWakeup] */
  { /*    21 */         0u,                         BSWM_RULES_PARAMETEROFACTIONITEMS,                                7u },  /* [AL_ESH_AL_WakeupToRun] */
  { /*    22 */        66u,        BSWM_COMMALLOWCOMPARAMETERS_PARAMETEROFACTIONITEMS,                                1u },  /* [AL_ESH_AL_WakeupToRun] */
  { /*    23 */        50u,        BSWM_TIMERCONTROLPARAMETERS_PARAMETEROFACTIONITEMS,                                0u },  /* [AL_ESH_AL_WakeupToRun] */
  { /*    24 */        54u,                            BSWM_NO_PARAMETEROFACTIONITEMS, BSWM_NO_PARAMETERIDXOFACTIONITEMS },  /* [AL_ESH_AL_WakeupToRun] */
  { /*    25 */         1u,     BSWM_ECUMSTATESWITCHPARAMETERS_PARAMETEROFACTIONITEMS,                                2u },  /* [AL_ESH_AL_WakeupToRun] */
  { /*    26 */        48u,                            BSWM_NO_PARAMETEROFACTIONITEMS, BSWM_NO_PARAMETERIDXOFACTIONITEMS },  /* [AL_ESH_AL_WakeupToRun] */
  { /*    27 */        63u,         BSWM_GENERICMODEPARAMETERS_PARAMETEROFACTIONITEMS,                                4u },  /* [AL_ESH_AL_WakeupToRun] */
  { /*    28 */        64u,                            BSWM_NO_PARAMETEROFACTIONITEMS, BSWM_NO_PARAMETERIDXOFACTIONITEMS },  /* [AL_ESH_AL_DemInit] */
  { /*    29 */        63u,         BSWM_GENERICMODEPARAMETERS_PARAMETEROFACTIONITEMS,                                3u },  /* [AL_ESH_AL_DemInit] */
  { /*    30 */        51u,                            BSWM_NO_PARAMETEROFACTIONITEMS, BSWM_NO_PARAMETERIDXOFACTIONITEMS },  /* [AL_ESH_AL_InitToWakeup] */
  { /*    31 */        46u,                            BSWM_NO_PARAMETEROFACTIONITEMS, BSWM_NO_PARAMETERIDXOFACTIONITEMS },  /* [AL_ESH_AL_InitToWakeup] */
  { /*    32 */        63u,         BSWM_GENERICMODEPARAMETERS_PARAMETEROFACTIONITEMS,                                2u },  /* [AL_ESH_AL_InitToWakeup] */
  { /*    33 */        61u,                            BSWM_NO_PARAMETEROFACTIONITEMS, BSWM_NO_PARAMETERIDXOFACTIONITEMS },  /* [AL_ESH_AL_PostRunToPrepShutdown] */
  { /*    34 */        63u,         BSWM_GENERICMODEPARAMETERS_PARAMETEROFACTIONITEMS,                                5u },  /* [AL_ESH_AL_PostRunToPrepShutdown] */
  { /*    35 */        55u,                            BSWM_NO_PARAMETEROFACTIONITEMS, BSWM_NO_PARAMETERIDXOFACTIONITEMS },  /* [AL_ESH_AL_PostRunToPrepShutdown] */
  { /*    36 */         1u,     BSWM_ECUMSTATESWITCHPARAMETERS_PARAMETEROFACTIONITEMS,                                1u },  /* [AL_ESH_AL_PostRunToPrepShutdown] */
  { /*    37 */        47u,                            BSWM_NO_PARAMETEROFACTIONITEMS, BSWM_NO_PARAMETERIDXOFACTIONITEMS },  /* [AL_ESH_AL_PostRunToPrepShutdown] */
  { /*    38 */        63u,         BSWM_GENERICMODEPARAMETERS_PARAMETEROFACTIONITEMS,                                1u },  /* [AL_ESH_AL_PostRunToPrepShutdown] */
  { /*    39 */        69u,                            BSWM_NO_PARAMETEROFACTIONITEMS, BSWM_NO_PARAMETERIDXOFACTIONITEMS },  /* [AL_ESH_AL_PostRunToPrepShutdown] */
  { /*    40 */         0u,                         BSWM_RULES_PARAMETEROFACTIONITEMS,                                9u },  /* [AL_ESH_AL_ESH_PostRunToPrepCheck] */
  { /*    41 */        66u,        BSWM_COMMALLOWCOMPARAMETERS_PARAMETEROFACTIONITEMS,                                1u },  /* [AL_ESH_AL_PostRunToRun] */
  { /*    42 */        50u,        BSWM_TIMERCONTROLPARAMETERS_PARAMETEROFACTIONITEMS,                                0u },  /* [AL_ESH_AL_PostRunToRun] */
  { /*    43 */        54u,                            BSWM_NO_PARAMETEROFACTIONITEMS, BSWM_NO_PARAMETERIDXOFACTIONITEMS },  /* [AL_ESH_AL_PostRunToRun] */
  { /*    44 */         1u,     BSWM_ECUMSTATESWITCHPARAMETERS_PARAMETEROFACTIONITEMS,                                2u },  /* [AL_ESH_AL_PostRunToRun] */
  { /*    45 */        48u,                            BSWM_NO_PARAMETEROFACTIONITEMS, BSWM_NO_PARAMETERIDXOFACTIONITEMS },  /* [AL_ESH_AL_PostRunToRun] */
  { /*    46 */        63u,         BSWM_GENERICMODEPARAMETERS_PARAMETEROFACTIONITEMS,                                4u },  /* [AL_ESH_AL_PostRunToRun] */
  { /*    47 */        58u,                            BSWM_NO_PARAMETEROFACTIONITEMS, BSWM_NO_PARAMETERIDXOFACTIONITEMS },  /* [AL_ESH_AL_ExitPostRun] */
  { /*    48 */        65u,                            BSWM_NO_PARAMETEROFACTIONITEMS, BSWM_NO_PARAMETERIDXOFACTIONITEMS },  /* [AL_ESH_AL_ExitPostRun] */
  { /*    49 */        62u,                            BSWM_NO_PARAMETEROFACTIONITEMS, BSWM_NO_PARAMETERIDXOFACTIONITEMS },  /* [AL_ESH_AL_ExitPostRun] */
    /* Index    ActionsIdx  Parameter                                                  ParameterIdx                             Referable Keys */
  { /*    50 */         0u,                         BSWM_RULES_PARAMETEROFACTIONITEMS,                               10u },  /* [AL_ESH_AL_ExitPostRun] */
  { /*    51 */        57u,                            BSWM_NO_PARAMETEROFACTIONITEMS, BSWM_NO_PARAMETERIDXOFACTIONITEMS },  /* [AL_ESH_AL_ExitPostRun] */
  { /*    52 */        65u,                            BSWM_NO_PARAMETEROFACTIONITEMS, BSWM_NO_PARAMETERIDXOFACTIONITEMS },  /* [AL_ESH_AL_PrepShutdownToWaitForNvM] */
  { /*    53 */        52u,                            BSWM_NO_PARAMETEROFACTIONITEMS, BSWM_NO_PARAMETERIDXOFACTIONITEMS },  /* [AL_ESH_AL_PrepShutdownToWaitForNvM] */
  { /*    54 */        63u,         BSWM_GENERICMODEPARAMETERS_PARAMETEROFACTIONITEMS,                                6u },  /* [AL_ESH_AL_PrepShutdownToWaitForNvM] */
  { /*    55 */        16u,                            BSWM_NO_PARAMETEROFACTIONITEMS, BSWM_NO_PARAMETERIDXOFACTIONITEMS },  /* [AL_INIT_AL_Initialize] */
  { /*    56 */        39u,                            BSWM_NO_PARAMETEROFACTIONITEMS, BSWM_NO_PARAMETERIDXOFACTIONITEMS },  /* [AL_INIT_AL_Initialize] */
  { /*    57 */        34u,                            BSWM_NO_PARAMETEROFACTIONITEMS, BSWM_NO_PARAMETERIDXOFACTIONITEMS },  /* [AL_INIT_AL_Initialize] */
  { /*    58 */        27u,                            BSWM_NO_PARAMETEROFACTIONITEMS, BSWM_NO_PARAMETERIDXOFACTIONITEMS },  /* [AL_INIT_AL_Initialize] */
  { /*    59 */        25u,                            BSWM_NO_PARAMETEROFACTIONITEMS, BSWM_NO_PARAMETERIDXOFACTIONITEMS },  /* [AL_INIT_AL_Initialize] */
  { /*    60 */        19u,                            BSWM_NO_PARAMETEROFACTIONITEMS, BSWM_NO_PARAMETERIDXOFACTIONITEMS },  /* [AL_INIT_AL_Initialize] */
  { /*    61 */        15u,                            BSWM_NO_PARAMETEROFACTIONITEMS, BSWM_NO_PARAMETERIDXOFACTIONITEMS },  /* [AL_INIT_AL_Initialize] */
  { /*    62 */         9u,                            BSWM_NO_PARAMETEROFACTIONITEMS, BSWM_NO_PARAMETERIDXOFACTIONITEMS },  /* [AL_INIT_AL_Initialize] */
  { /*    63 */         8u,                            BSWM_NO_PARAMETEROFACTIONITEMS, BSWM_NO_PARAMETERIDXOFACTIONITEMS },  /* [AL_INIT_AL_Initialize] */
  { /*    64 */         5u,                            BSWM_NO_PARAMETEROFACTIONITEMS, BSWM_NO_PARAMETERIDXOFACTIONITEMS },  /* [AL_INIT_AL_Initialize] */
  { /*    65 */         3u,                            BSWM_NO_PARAMETEROFACTIONITEMS, BSWM_NO_PARAMETERIDXOFACTIONITEMS },  /* [AL_INIT_AL_Initialize] */
  { /*    66 */        44u,                            BSWM_NO_PARAMETEROFACTIONITEMS, BSWM_NO_PARAMETERIDXOFACTIONITEMS },  /* [AL_INIT_AL_Initialize] */
  { /*    67 */        24u,                            BSWM_NO_PARAMETEROFACTIONITEMS, BSWM_NO_PARAMETERIDXOFACTIONITEMS },  /* [AL_INIT_AL_Initialize] */
  { /*    68 */        37u,                            BSWM_NO_PARAMETEROFACTIONITEMS, BSWM_NO_PARAMETERIDXOFACTIONITEMS },  /* [AL_INIT_AL_Initialize] */
  { /*    69 */        31u,                            BSWM_NO_PARAMETEROFACTIONITEMS, BSWM_NO_PARAMETERIDXOFACTIONITEMS },  /* [AL_INIT_AL_Initialize] */
  { /*    70 */        30u,                            BSWM_NO_PARAMETEROFACTIONITEMS, BSWM_NO_PARAMETERIDXOFACTIONITEMS },  /* [AL_INIT_AL_Initialize] */
  { /*    71 */        43u,                            BSWM_NO_PARAMETEROFACTIONITEMS, BSWM_NO_PARAMETERIDXOFACTIONITEMS },  /* [AL_INIT_AL_Initialize] */
  { /*    72 */        32u,                            BSWM_NO_PARAMETEROFACTIONITEMS, BSWM_NO_PARAMETERIDXOFACTIONITEMS },  /* [AL_INIT_AL_Initialize] */
  { /*    73 */         4u,                            BSWM_NO_PARAMETEROFACTIONITEMS, BSWM_NO_PARAMETERIDXOFACTIONITEMS },  /* [AL_INIT_AL_Initialize] */
  { /*    74 */        33u,                            BSWM_NO_PARAMETEROFACTIONITEMS, BSWM_NO_PARAMETERIDXOFACTIONITEMS },  /* [AL_INIT_AL_Initialize] */
  { /*    75 */        23u,                            BSWM_NO_PARAMETEROFACTIONITEMS, BSWM_NO_PARAMETERIDXOFACTIONITEMS },  /* [AL_INIT_AL_Initialize] */
  { /*    76 */        17u,                            BSWM_NO_PARAMETEROFACTIONITEMS, BSWM_NO_PARAMETERIDXOFACTIONITEMS },  /* [AL_INIT_AL_Initialize] */
  { /*    77 */        10u,                            BSWM_NO_PARAMETEROFACTIONITEMS, BSWM_NO_PARAMETERIDXOFACTIONITEMS },  /* [AL_INIT_AL_Initialize] */
  { /*    78 */        41u,                            BSWM_NO_PARAMETEROFACTIONITEMS, BSWM_NO_PARAMETERIDXOFACTIONITEMS },  /* [AL_INIT_AL_Initialize] */
  { /*    79 */        42u,                            BSWM_NO_PARAMETEROFACTIONITEMS, BSWM_NO_PARAMETERIDXOFACTIONITEMS },  /* [AL_INIT_AL_Initialize] */
  { /*    80 */        21u,                            BSWM_NO_PARAMETEROFACTIONITEMS, BSWM_NO_PARAMETERIDXOFACTIONITEMS },  /* [AL_INIT_AL_Initialize] */
  { /*    81 */        38u,                            BSWM_NO_PARAMETEROFACTIONITEMS, BSWM_NO_PARAMETERIDXOFACTIONITEMS },  /* [AL_INIT_AL_Initialize] */
  { /*    82 */        40u,                            BSWM_NO_PARAMETEROFACTIONITEMS, BSWM_NO_PARAMETERIDXOFACTIONITEMS },  /* [AL_INIT_AL_Initialize] */
  { /*    83 */        29u,                            BSWM_NO_PARAMETEROFACTIONITEMS, BSWM_NO_PARAMETERIDXOFACTIONITEMS },  /* [AL_INIT_AL_Initialize] */
  { /*    84 */        22u,                            BSWM_NO_PARAMETEROFACTIONITEMS, BSWM_NO_PARAMETERIDXOFACTIONITEMS },  /* [AL_INIT_AL_Initialize] */
  { /*    85 */         7u,                            BSWM_NO_PARAMETEROFACTIONITEMS, BSWM_NO_PARAMETERIDXOFACTIONITEMS },  /* [AL_INIT_AL_Initialize] */
  { /*    86 */        18u,                            BSWM_NO_PARAMETEROFACTIONITEMS, BSWM_NO_PARAMETERIDXOFACTIONITEMS },  /* [AL_INIT_AL_Initialize] */
  { /*    87 */        26u,                            BSWM_NO_PARAMETEROFACTIONITEMS, BSWM_NO_PARAMETERIDXOFACTIONITEMS },  /* [AL_INIT_AL_Initialize] */
  { /*    88 */        36u,                            BSWM_NO_PARAMETEROFACTIONITEMS, BSWM_NO_PARAMETERIDXOFACTIONITEMS },  /* [AL_INIT_AL_Initialize] */
  { /*    89 */        28u,                            BSWM_NO_PARAMETEROFACTIONITEMS, BSWM_NO_PARAMETERIDXOFACTIONITEMS },  /* [AL_INIT_AL_Initialize] */
  { /*    90 */        64u,                            BSWM_NO_PARAMETEROFACTIONITEMS, BSWM_NO_PARAMETERIDXOFACTIONITEMS },  /* [AL_INIT_AL_Initialize] */
  { /*    91 */         2u,                            BSWM_NO_PARAMETEROFACTIONITEMS, BSWM_NO_PARAMETERIDXOFACTIONITEMS },  /* [AL_INIT_AL_Initialize] */
  { /*    92 */        12u,                            BSWM_NO_PARAMETEROFACTIONITEMS, BSWM_NO_PARAMETERIDXOFACTIONITEMS },  /* [AL_INIT_AL_Initialize] */
  { /*    93 */        35u,                            BSWM_NO_PARAMETEROFACTIONITEMS, BSWM_NO_PARAMETERIDXOFACTIONITEMS },  /* [AL_INIT_AL_Initialize] */
  { /*    94 */        20u,                            BSWM_NO_PARAMETEROFACTIONITEMS, BSWM_NO_PARAMETERIDXOFACTIONITEMS },  /* [AL_INIT_AL_Initialize] */
  { /*    95 */        13u,                            BSWM_NO_PARAMETEROFACTIONITEMS, BSWM_NO_PARAMETERIDXOFACTIONITEMS },  /* [AL_INIT_AL_Initialize] */
  { /*    96 */         6u,                            BSWM_NO_PARAMETEROFACTIONITEMS, BSWM_NO_PARAMETERIDXOFACTIONITEMS },  /* [AL_INIT_AL_Initialize] */
  { /*    97 */        45u,                            BSWM_NO_PARAMETEROFACTIONITEMS, BSWM_NO_PARAMETERIDXOFACTIONITEMS },  /* [AL_INIT_AL_Initialize] */
  { /*    98 */        11u,                            BSWM_NO_PARAMETEROFACTIONITEMS, BSWM_NO_PARAMETERIDXOFACTIONITEMS },  /* [AL_INIT_AL_Initialize] */
  { /*    99 */        14u,                            BSWM_NO_PARAMETEROFACTIONITEMS, BSWM_NO_PARAMETERIDXOFACTIONITEMS },  /* [AL_INIT_AL_Initialize] */
    /* Index    ActionsIdx  Parameter                                                  ParameterIdx                             Referable Keys */
  { /*   100 */        67u, BSWM_COMPDUGROUPHANDLINGPARAMETERS_PARAMETEROFACTIONITEMS,                                2u },  /* [AL_CC_AL_RBTM_FL_BODY3_8uqv9blm85ehm0msat385m76v_03d5f5f6_PNC_00_MAPPING_b2c42696_RX_Disable] */
  { /*   101 */        67u, BSWM_COMPDUGROUPHANDLINGPARAMETERS_PARAMETEROFACTIONITEMS,                                3u },  /* [AL_CC_AL_RBTM_FL_BODY3_8uqv9blm85ehm0msat385m76v_03d5f5f6_PNC_00_MAPPING_b2c42696_RX_EnableNoinit] */
  { /*   102 */        68u,       BSWM_COMDMHANDLINGPARAMETERS_PARAMETEROFACTIONITEMS,                                0u },  /* [AL_CC_AL_RBTM_FL_BODY3_8uqv9blm85ehm0msat385m76v_03d5f5f6_PNC_00_MAPPING_b2c42696_Disable_DM] */
  { /*   103 */        68u,       BSWM_COMDMHANDLINGPARAMETERS_PARAMETEROFACTIONITEMS,                                1u },  /* [AL_CC_AL_RBTM_FL_BODY3_8uqv9blm85ehm0msat385m76v_03d5f5f6_PNC_00_MAPPING_b2c42696_Enable_DM] */
  { /*   104 */        67u, BSWM_COMPDUGROUPHANDLINGPARAMETERS_PARAMETEROFACTIONITEMS,                                4u },  /* [AL_CC_AL_RBTM_FL_BODY3_8uqv9blm85ehm0msat385m76v_03d5f5f6_PNC_00_MAPPING_b2c42696_TX_Disable] */
  { /*   105 */        67u, BSWM_COMPDUGROUPHANDLINGPARAMETERS_PARAMETEROFACTIONITEMS,                                5u },  /* [AL_CC_AL_RBTM_FL_BODY3_8uqv9blm85ehm0msat385m76v_03d5f5f6_PNC_00_MAPPING_b2c42696_TX_EnableNoinit] */
  { /*   106 */        68u,       BSWM_COMDMHANDLINGPARAMETERS_PARAMETEROFACTIONITEMS,                                2u },  /* [AL_CC_AL_RBTM_FL_BODY3_8uqv9blm85ehm0msat385m76v_03d5f5f6_PNC_20_MAPPING_796df885_Disable_DM] */
  { /*   107 */        68u,       BSWM_COMDMHANDLINGPARAMETERS_PARAMETEROFACTIONITEMS,                                3u },  /* [AL_CC_AL_RBTM_FL_BODY3_8uqv9blm85ehm0msat385m76v_03d5f5f6_PNC_20_MAPPING_796df885_Enable_DM] */
  { /*   108 */        67u, BSWM_COMPDUGROUPHANDLINGPARAMETERS_PARAMETEROFACTIONITEMS,                                6u },  /* [AL_CC_AL_RBTM_FL_BODY3_8uqv9blm85ehm0msat385m76v_03d5f5f6_PNC_20_MAPPING_796df885_TX_Disable] */
  { /*   109 */        67u, BSWM_COMPDUGROUPHANDLINGPARAMETERS_PARAMETEROFACTIONITEMS,                                7u },  /* [AL_CC_AL_RBTM_FL_BODY3_8uqv9blm85ehm0msat385m76v_03d5f5f6_PNC_20_MAPPING_796df885_TX_EnableNoinit] */
  { /*   110 */        67u, BSWM_COMPDUGROUPHANDLINGPARAMETERS_PARAMETEROFACTIONITEMS,                                8u },  /* [AL_CC_AL_RBTM_FL_BODY3_8uqv9blm85ehm0msat385m76v_03d5f5f6_PNC_20_MAPPING_796df885_RX_Disable] */
  { /*   111 */        67u, BSWM_COMPDUGROUPHANDLINGPARAMETERS_PARAMETEROFACTIONITEMS,                                9u },  /* [AL_CC_AL_RBTM_FL_BODY3_8uqv9blm85ehm0msat385m76v_03d5f5f6_PNC_20_MAPPING_796df885_RX_EnableNoinit] */
  { /*   112 */        71u,                            BSWM_NO_PARAMETEROFACTIONITEMS, BSWM_NO_PARAMETERIDXOFACTIONITEMS },  /* [AL_AL_SwcDiag_FullCom] */
  { /*   113 */        70u,                            BSWM_NO_PARAMETEROFACTIONITEMS, BSWM_NO_PARAMETERIDXOFACTIONITEMS }   /* [AL_AL_SwcDiag_NotFullCom] */
};
#define BSWM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  BswM_ActionItemsRight
**********************************************************************************************************************/
/** 
  \var    BswM_ActionItemsRight
  \details
  Element         Description
  ActionsIdx      the index of the 1:1 relation pointing to BswM_Actions
  Parameter       the enum value of the according target of the 0:1 relation pointing to BswM_ComMAllowComParameters,BswM_ComMModeLimitationParameters,BswM_ComMModeSwitchParameters,BswM_ComDMControlParameters,BswM_EcuMSelectShutdownTargetParameters,BswM_EcuMStateSwitchParameters,BswM_IdsmBlockStateChangeRequestParameters,BswM_LinScheduleRequestParameters,BswM_NmControlParameters,BswM_ComSwitchIPduModeParameters,BswM_ComPduGroupSwitchParameters,BswM_ComPduGroupHandlingParameters,BswM_ComDMHandlingParameters,BswM_ComTriggerIPduSendParameters,BswM_PduRouterControlParameters,BswM_TimerControlParameters,BswM_GenericModeParameters,BswM_GenericModeRefParameters,BswM_J1939DcmStateParameters,BswM_J1939RmStateParameters,BswM_SdClientParameters,BswM_SdConsumedParameters,BswM_SdServerParameters,BswM_SdServiceGroupSwitchParameters,BswM_RuleControlParameters,BswM_ActionLists,BswM_Rules
  ParameterIdx    the index of the 0:1 relation pointing to BswM_ComMAllowComParameters,BswM_ComMModeLimitationParameters,BswM_ComMModeSwitchParameters,BswM_ComDMControlParameters,BswM_EcuMSelectShutdownTargetParameters,BswM_EcuMStateSwitchParameters,BswM_IdsmBlockStateChangeRequestParameters,BswM_LinScheduleRequestParameters,BswM_NmControlParameters,BswM_ComSwitchIPduModeParameters,BswM_ComPduGroupSwitchParameters,BswM_ComPduGroupHandlingParameters,BswM_ComDMHandlingParameters,BswM_ComTriggerIPduSendParameters,BswM_PduRouterControlParameters,BswM_TimerControlParameters,BswM_GenericModeParameters,BswM_GenericModeRefParameters,BswM_J1939DcmStateParameters,BswM_J1939RmStateParameters,BswM_SdClientParameters,BswM_SdConsumedParameters,BswM_SdServerParameters,BswM_SdServiceGroupSwitchParameters,BswM_RuleControlParameters,BswM_ActionLists,BswM_Rules
*/ 
#define BSWM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(BswM_ActionItemsType, BSWM_CONST) BswM_ActionItemsRight[114] = {  /* PRQA S 1514, 1533, 1504 */  /* MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ExternalMcData */
    /* Index    ActionsIdx  Parameter                                                  ParameterIdx                             Referable Keys */
  { /*     0 */        58u,                            BSWM_NO_PARAMETEROFACTIONITEMS, BSWM_NO_PARAMETERIDXOFACTIONITEMS },  /* [AL_ESH_AL_ExitRun] */
  { /*     1 */        65u,                            BSWM_NO_PARAMETEROFACTIONITEMS, BSWM_NO_PARAMETERIDXOFACTIONITEMS },  /* [AL_ESH_AL_ExitRun] */
  { /*     2 */         0u,                         BSWM_RULES_PARAMETEROFACTIONITEMS,                                1u },  /* [AL_ESH_AL_ExitRun] */
  { /*     3 */        57u,                            BSWM_NO_PARAMETEROFACTIONITEMS, BSWM_NO_PARAMETERIDXOFACTIONITEMS },  /* [AL_ESH_AL_ExitRun] */
  { /*     4 */        66u,        BSWM_COMMALLOWCOMPARAMETERS_PARAMETEROFACTIONITEMS,                                0u },  /* [AL_ESH_AL_RunToPostRun] */
  { /*     5 */        60u,                            BSWM_NO_PARAMETEROFACTIONITEMS, BSWM_NO_PARAMETERIDXOFACTIONITEMS },  /* [AL_ESH_AL_RunToPostRun] */
  { /*     6 */        56u,                            BSWM_NO_PARAMETEROFACTIONITEMS, BSWM_NO_PARAMETERIDXOFACTIONITEMS },  /* [AL_ESH_AL_RunToPostRun] */
  { /*     7 */         1u,     BSWM_ECUMSTATESWITCHPARAMETERS_PARAMETEROFACTIONITEMS,                                0u },  /* [AL_ESH_AL_RunToPostRun] */
  { /*     8 */        49u,                            BSWM_NO_PARAMETEROFACTIONITEMS, BSWM_NO_PARAMETERIDXOFACTIONITEMS },  /* [AL_ESH_AL_RunToPostRun] */
  { /*     9 */        63u,         BSWM_GENERICMODEPARAMETERS_PARAMETEROFACTIONITEMS,                                0u },  /* [AL_ESH_AL_RunToPostRun] */
  { /*    10 */        53u,                            BSWM_NO_PARAMETEROFACTIONITEMS, BSWM_NO_PARAMETERIDXOFACTIONITEMS },  /* [AL_ESH_AL_WaitForNvMToShutdown] */
  { /*    11 */        59u,                            BSWM_NO_PARAMETEROFACTIONITEMS, BSWM_NO_PARAMETERIDXOFACTIONITEMS },  /* [AL_ESH_AL_WaitForNvMToShutdown] */
  { /*    12 */        55u,                            BSWM_NO_PARAMETEROFACTIONITEMS, BSWM_NO_PARAMETERIDXOFACTIONITEMS },  /* [AL_ESH_AL_WakeupToPrep] */
  { /*    13 */         1u,     BSWM_ECUMSTATESWITCHPARAMETERS_PARAMETEROFACTIONITEMS,                                1u },  /* [AL_ESH_AL_WakeupToPrep] */
  { /*    14 */        47u,                            BSWM_NO_PARAMETEROFACTIONITEMS, BSWM_NO_PARAMETERIDXOFACTIONITEMS },  /* [AL_ESH_AL_WakeupToPrep] */
  { /*    15 */        63u,         BSWM_GENERICMODEPARAMETERS_PARAMETEROFACTIONITEMS,                                1u },  /* [AL_ESH_AL_WakeupToPrep] */
  { /*    16 */        51u,                            BSWM_NO_PARAMETEROFACTIONITEMS, BSWM_NO_PARAMETERIDXOFACTIONITEMS },  /* [AL_ESH_AL_WaitForNvMWakeup] */
  { /*    17 */        46u,                            BSWM_NO_PARAMETEROFACTIONITEMS, BSWM_NO_PARAMETERIDXOFACTIONITEMS },  /* [AL_ESH_AL_WaitForNvMWakeup] */
  { /*    18 */        63u,         BSWM_GENERICMODEPARAMETERS_PARAMETEROFACTIONITEMS,                                2u },  /* [AL_ESH_AL_WaitForNvMWakeup] */
  { /*    19 */         0u,                         BSWM_RULES_PARAMETEROFACTIONITEMS,                                6u },  /* [AL_ESH_AL_WakeupToRun] */
  { /*    20 */        66u,        BSWM_COMMALLOWCOMPARAMETERS_PARAMETEROFACTIONITEMS,                                1u },  /* [AL_ESH_AL_WakeupToRun] */
  { /*    21 */        50u,        BSWM_TIMERCONTROLPARAMETERS_PARAMETEROFACTIONITEMS,                                0u },  /* [AL_ESH_AL_WakeupToRun] */
  { /*    22 */        54u,                            BSWM_NO_PARAMETEROFACTIONITEMS, BSWM_NO_PARAMETERIDXOFACTIONITEMS },  /* [AL_ESH_AL_WakeupToRun] */
  { /*    23 */         1u,     BSWM_ECUMSTATESWITCHPARAMETERS_PARAMETEROFACTIONITEMS,                                2u },  /* [AL_ESH_AL_WakeupToRun] */
  { /*    24 */        48u,                            BSWM_NO_PARAMETEROFACTIONITEMS, BSWM_NO_PARAMETERIDXOFACTIONITEMS },  /* [AL_ESH_AL_WakeupToRun] */
  { /*    25 */        63u,         BSWM_GENERICMODEPARAMETERS_PARAMETEROFACTIONITEMS,                                4u },  /* [AL_ESH_AL_WakeupToRun] */
  { /*    26 */        64u,                            BSWM_NO_PARAMETEROFACTIONITEMS, BSWM_NO_PARAMETERIDXOFACTIONITEMS },  /* [AL_ESH_AL_DemInit] */
  { /*    27 */        63u,         BSWM_GENERICMODEPARAMETERS_PARAMETEROFACTIONITEMS,                                3u },  /* [AL_ESH_AL_DemInit] */
  { /*    28 */        51u,                            BSWM_NO_PARAMETEROFACTIONITEMS, BSWM_NO_PARAMETERIDXOFACTIONITEMS },  /* [AL_ESH_AL_InitToWakeup] */
  { /*    29 */        46u,                            BSWM_NO_PARAMETEROFACTIONITEMS, BSWM_NO_PARAMETERIDXOFACTIONITEMS },  /* [AL_ESH_AL_InitToWakeup] */
  { /*    30 */        63u,         BSWM_GENERICMODEPARAMETERS_PARAMETEROFACTIONITEMS,                                2u },  /* [AL_ESH_AL_InitToWakeup] */
  { /*    31 */        61u,                            BSWM_NO_PARAMETEROFACTIONITEMS, BSWM_NO_PARAMETERIDXOFACTIONITEMS },  /* [AL_ESH_AL_PostRunToPrepShutdown] */
  { /*    32 */        63u,         BSWM_GENERICMODEPARAMETERS_PARAMETEROFACTIONITEMS,                                5u },  /* [AL_ESH_AL_PostRunToPrepShutdown] */
  { /*    33 */        55u,                            BSWM_NO_PARAMETEROFACTIONITEMS, BSWM_NO_PARAMETERIDXOFACTIONITEMS },  /* [AL_ESH_AL_PostRunToPrepShutdown] */
  { /*    34 */         1u,     BSWM_ECUMSTATESWITCHPARAMETERS_PARAMETEROFACTIONITEMS,                                1u },  /* [AL_ESH_AL_PostRunToPrepShutdown] */
  { /*    35 */        47u,                            BSWM_NO_PARAMETEROFACTIONITEMS, BSWM_NO_PARAMETERIDXOFACTIONITEMS },  /* [AL_ESH_AL_PostRunToPrepShutdown] */
  { /*    36 */        63u,         BSWM_GENERICMODEPARAMETERS_PARAMETEROFACTIONITEMS,                                1u },  /* [AL_ESH_AL_PostRunToPrepShutdown] */
  { /*    37 */        69u,                            BSWM_NO_PARAMETEROFACTIONITEMS, BSWM_NO_PARAMETERIDXOFACTIONITEMS },  /* [AL_ESH_AL_PostRunToPrepShutdown] */
  { /*    38 */         0u,                         BSWM_RULES_PARAMETEROFACTIONITEMS,                                8u },  /* [AL_ESH_AL_ESH_PostRunToPrepCheck] */
  { /*    39 */        66u,        BSWM_COMMALLOWCOMPARAMETERS_PARAMETEROFACTIONITEMS,                                1u },  /* [AL_ESH_AL_PostRunToRun] */
  { /*    40 */        50u,        BSWM_TIMERCONTROLPARAMETERS_PARAMETEROFACTIONITEMS,                                0u },  /* [AL_ESH_AL_PostRunToRun] */
  { /*    41 */        54u,                            BSWM_NO_PARAMETEROFACTIONITEMS, BSWM_NO_PARAMETERIDXOFACTIONITEMS },  /* [AL_ESH_AL_PostRunToRun] */
  { /*    42 */         1u,     BSWM_ECUMSTATESWITCHPARAMETERS_PARAMETEROFACTIONITEMS,                                2u },  /* [AL_ESH_AL_PostRunToRun] */
  { /*    43 */        48u,                            BSWM_NO_PARAMETEROFACTIONITEMS, BSWM_NO_PARAMETERIDXOFACTIONITEMS },  /* [AL_ESH_AL_PostRunToRun] */
  { /*    44 */        63u,         BSWM_GENERICMODEPARAMETERS_PARAMETEROFACTIONITEMS,                                4u },  /* [AL_ESH_AL_PostRunToRun] */
  { /*    45 */        58u,                            BSWM_NO_PARAMETEROFACTIONITEMS, BSWM_NO_PARAMETERIDXOFACTIONITEMS },  /* [AL_ESH_AL_ExitPostRun] */
  { /*    46 */        65u,                            BSWM_NO_PARAMETEROFACTIONITEMS, BSWM_NO_PARAMETERIDXOFACTIONITEMS },  /* [AL_ESH_AL_ExitPostRun] */
  { /*    47 */        62u,                            BSWM_NO_PARAMETEROFACTIONITEMS, BSWM_NO_PARAMETERIDXOFACTIONITEMS },  /* [AL_ESH_AL_ExitPostRun] */
  { /*    48 */         0u,                         BSWM_RULES_PARAMETEROFACTIONITEMS,                                9u },  /* [AL_ESH_AL_ExitPostRun] */
  { /*    49 */        57u,                            BSWM_NO_PARAMETEROFACTIONITEMS, BSWM_NO_PARAMETERIDXOFACTIONITEMS },  /* [AL_ESH_AL_ExitPostRun] */
    /* Index    ActionsIdx  Parameter                                                  ParameterIdx                             Referable Keys */
  { /*    50 */        65u,                            BSWM_NO_PARAMETEROFACTIONITEMS, BSWM_NO_PARAMETERIDXOFACTIONITEMS },  /* [AL_ESH_AL_PrepShutdownToWaitForNvM] */
  { /*    51 */        52u,                            BSWM_NO_PARAMETEROFACTIONITEMS, BSWM_NO_PARAMETERIDXOFACTIONITEMS },  /* [AL_ESH_AL_PrepShutdownToWaitForNvM] */
  { /*    52 */        63u,         BSWM_GENERICMODEPARAMETERS_PARAMETEROFACTIONITEMS,                                6u },  /* [AL_ESH_AL_PrepShutdownToWaitForNvM] */
  { /*    53 */        16u,                            BSWM_NO_PARAMETEROFACTIONITEMS, BSWM_NO_PARAMETERIDXOFACTIONITEMS },  /* [AL_INIT_AL_Initialize] */
  { /*    54 */        39u,                            BSWM_NO_PARAMETEROFACTIONITEMS, BSWM_NO_PARAMETERIDXOFACTIONITEMS },  /* [AL_INIT_AL_Initialize] */
  { /*    55 */        34u,                            BSWM_NO_PARAMETEROFACTIONITEMS, BSWM_NO_PARAMETERIDXOFACTIONITEMS },  /* [AL_INIT_AL_Initialize] */
  { /*    56 */        27u,                            BSWM_NO_PARAMETEROFACTIONITEMS, BSWM_NO_PARAMETERIDXOFACTIONITEMS },  /* [AL_INIT_AL_Initialize] */
  { /*    57 */        25u,                            BSWM_NO_PARAMETEROFACTIONITEMS, BSWM_NO_PARAMETERIDXOFACTIONITEMS },  /* [AL_INIT_AL_Initialize] */
  { /*    58 */        19u,                            BSWM_NO_PARAMETEROFACTIONITEMS, BSWM_NO_PARAMETERIDXOFACTIONITEMS },  /* [AL_INIT_AL_Initialize] */
  { /*    59 */        15u,                            BSWM_NO_PARAMETEROFACTIONITEMS, BSWM_NO_PARAMETERIDXOFACTIONITEMS },  /* [AL_INIT_AL_Initialize] */
  { /*    60 */         9u,                            BSWM_NO_PARAMETEROFACTIONITEMS, BSWM_NO_PARAMETERIDXOFACTIONITEMS },  /* [AL_INIT_AL_Initialize] */
  { /*    61 */         8u,                            BSWM_NO_PARAMETEROFACTIONITEMS, BSWM_NO_PARAMETERIDXOFACTIONITEMS },  /* [AL_INIT_AL_Initialize] */
  { /*    62 */         5u,                            BSWM_NO_PARAMETEROFACTIONITEMS, BSWM_NO_PARAMETERIDXOFACTIONITEMS },  /* [AL_INIT_AL_Initialize] */
  { /*    63 */         3u,                            BSWM_NO_PARAMETEROFACTIONITEMS, BSWM_NO_PARAMETERIDXOFACTIONITEMS },  /* [AL_INIT_AL_Initialize] */
  { /*    64 */        44u,                            BSWM_NO_PARAMETEROFACTIONITEMS, BSWM_NO_PARAMETERIDXOFACTIONITEMS },  /* [AL_INIT_AL_Initialize] */
  { /*    65 */        24u,                            BSWM_NO_PARAMETEROFACTIONITEMS, BSWM_NO_PARAMETERIDXOFACTIONITEMS },  /* [AL_INIT_AL_Initialize] */
  { /*    66 */        37u,                            BSWM_NO_PARAMETEROFACTIONITEMS, BSWM_NO_PARAMETERIDXOFACTIONITEMS },  /* [AL_INIT_AL_Initialize] */
  { /*    67 */        31u,                            BSWM_NO_PARAMETEROFACTIONITEMS, BSWM_NO_PARAMETERIDXOFACTIONITEMS },  /* [AL_INIT_AL_Initialize] */
  { /*    68 */        30u,                            BSWM_NO_PARAMETEROFACTIONITEMS, BSWM_NO_PARAMETERIDXOFACTIONITEMS },  /* [AL_INIT_AL_Initialize] */
  { /*    69 */        43u,                            BSWM_NO_PARAMETEROFACTIONITEMS, BSWM_NO_PARAMETERIDXOFACTIONITEMS },  /* [AL_INIT_AL_Initialize] */
  { /*    70 */        32u,                            BSWM_NO_PARAMETEROFACTIONITEMS, BSWM_NO_PARAMETERIDXOFACTIONITEMS },  /* [AL_INIT_AL_Initialize] */
  { /*    71 */         4u,                            BSWM_NO_PARAMETEROFACTIONITEMS, BSWM_NO_PARAMETERIDXOFACTIONITEMS },  /* [AL_INIT_AL_Initialize] */
  { /*    72 */        33u,                            BSWM_NO_PARAMETEROFACTIONITEMS, BSWM_NO_PARAMETERIDXOFACTIONITEMS },  /* [AL_INIT_AL_Initialize] */
  { /*    73 */        23u,                            BSWM_NO_PARAMETEROFACTIONITEMS, BSWM_NO_PARAMETERIDXOFACTIONITEMS },  /* [AL_INIT_AL_Initialize] */
  { /*    74 */        17u,                            BSWM_NO_PARAMETEROFACTIONITEMS, BSWM_NO_PARAMETERIDXOFACTIONITEMS },  /* [AL_INIT_AL_Initialize] */
  { /*    75 */        10u,                            BSWM_NO_PARAMETEROFACTIONITEMS, BSWM_NO_PARAMETERIDXOFACTIONITEMS },  /* [AL_INIT_AL_Initialize] */
  { /*    76 */        41u,                            BSWM_NO_PARAMETEROFACTIONITEMS, BSWM_NO_PARAMETERIDXOFACTIONITEMS },  /* [AL_INIT_AL_Initialize] */
  { /*    77 */        42u,                            BSWM_NO_PARAMETEROFACTIONITEMS, BSWM_NO_PARAMETERIDXOFACTIONITEMS },  /* [AL_INIT_AL_Initialize] */
  { /*    78 */        21u,                            BSWM_NO_PARAMETEROFACTIONITEMS, BSWM_NO_PARAMETERIDXOFACTIONITEMS },  /* [AL_INIT_AL_Initialize] */
  { /*    79 */        38u,                            BSWM_NO_PARAMETEROFACTIONITEMS, BSWM_NO_PARAMETERIDXOFACTIONITEMS },  /* [AL_INIT_AL_Initialize] */
  { /*    80 */        40u,                            BSWM_NO_PARAMETEROFACTIONITEMS, BSWM_NO_PARAMETERIDXOFACTIONITEMS },  /* [AL_INIT_AL_Initialize] */
  { /*    81 */        29u,                            BSWM_NO_PARAMETEROFACTIONITEMS, BSWM_NO_PARAMETERIDXOFACTIONITEMS },  /* [AL_INIT_AL_Initialize] */
  { /*    82 */        22u,                            BSWM_NO_PARAMETEROFACTIONITEMS, BSWM_NO_PARAMETERIDXOFACTIONITEMS },  /* [AL_INIT_AL_Initialize] */
  { /*    83 */         7u,                            BSWM_NO_PARAMETEROFACTIONITEMS, BSWM_NO_PARAMETERIDXOFACTIONITEMS },  /* [AL_INIT_AL_Initialize] */
  { /*    84 */        18u,                            BSWM_NO_PARAMETEROFACTIONITEMS, BSWM_NO_PARAMETERIDXOFACTIONITEMS },  /* [AL_INIT_AL_Initialize] */
  { /*    85 */        26u,                            BSWM_NO_PARAMETEROFACTIONITEMS, BSWM_NO_PARAMETERIDXOFACTIONITEMS },  /* [AL_INIT_AL_Initialize] */
  { /*    86 */        36u,                            BSWM_NO_PARAMETEROFACTIONITEMS, BSWM_NO_PARAMETERIDXOFACTIONITEMS },  /* [AL_INIT_AL_Initialize] */
  { /*    87 */        28u,                            BSWM_NO_PARAMETEROFACTIONITEMS, BSWM_NO_PARAMETERIDXOFACTIONITEMS },  /* [AL_INIT_AL_Initialize] */
  { /*    88 */        64u,                            BSWM_NO_PARAMETEROFACTIONITEMS, BSWM_NO_PARAMETERIDXOFACTIONITEMS },  /* [AL_INIT_AL_Initialize] */
  { /*    89 */         2u,                            BSWM_NO_PARAMETEROFACTIONITEMS, BSWM_NO_PARAMETERIDXOFACTIONITEMS },  /* [AL_INIT_AL_Initialize] */
  { /*    90 */        12u,                            BSWM_NO_PARAMETEROFACTIONITEMS, BSWM_NO_PARAMETERIDXOFACTIONITEMS },  /* [AL_INIT_AL_Initialize] */
  { /*    91 */        35u,                            BSWM_NO_PARAMETEROFACTIONITEMS, BSWM_NO_PARAMETERIDXOFACTIONITEMS },  /* [AL_INIT_AL_Initialize] */
  { /*    92 */        20u,                            BSWM_NO_PARAMETEROFACTIONITEMS, BSWM_NO_PARAMETERIDXOFACTIONITEMS },  /* [AL_INIT_AL_Initialize] */
  { /*    93 */        13u,                            BSWM_NO_PARAMETEROFACTIONITEMS, BSWM_NO_PARAMETERIDXOFACTIONITEMS },  /* [AL_INIT_AL_Initialize] */
  { /*    94 */         6u,                            BSWM_NO_PARAMETEROFACTIONITEMS, BSWM_NO_PARAMETERIDXOFACTIONITEMS },  /* [AL_INIT_AL_Initialize] */
  { /*    95 */        45u,                            BSWM_NO_PARAMETEROFACTIONITEMS, BSWM_NO_PARAMETERIDXOFACTIONITEMS },  /* [AL_INIT_AL_Initialize] */
  { /*    96 */        11u,                            BSWM_NO_PARAMETEROFACTIONITEMS, BSWM_NO_PARAMETERIDXOFACTIONITEMS },  /* [AL_INIT_AL_Initialize] */
  { /*    97 */        14u,                            BSWM_NO_PARAMETEROFACTIONITEMS, BSWM_NO_PARAMETERIDXOFACTIONITEMS },  /* [AL_INIT_AL_Initialize] */
  { /*    98 */        68u,       BSWM_COMDMHANDLINGPARAMETERS_PARAMETEROFACTIONITEMS,                                0u },  /* [AL_CC_AL_RBTM_FR_BODY3_4xwwtd59665s787n6ctawh7k8_23a94727_PNC_00_MAPPING_b2c42696_Disable_DM] */
  { /*    99 */        68u,       BSWM_COMDMHANDLINGPARAMETERS_PARAMETEROFACTIONITEMS,                                1u },  /* [AL_CC_AL_RBTM_FR_BODY3_4xwwtd59665s787n6ctawh7k8_23a94727_PNC_00_MAPPING_b2c42696_Enable_DM] */
    /* Index    ActionsIdx  Parameter                                                  ParameterIdx                             Referable Keys */
  { /*   100 */        67u, BSWM_COMPDUGROUPHANDLINGPARAMETERS_PARAMETEROFACTIONITEMS,                                0u },  /* [AL_CC_AL_RBTM_FR_BODY3_4xwwtd59665s787n6ctawh7k8_23a94727_PNC_00_MAPPING_b2c42696_RX_Disable] */
  { /*   101 */        67u, BSWM_COMPDUGROUPHANDLINGPARAMETERS_PARAMETEROFACTIONITEMS,                                1u },  /* [AL_CC_AL_RBTM_FR_BODY3_4xwwtd59665s787n6ctawh7k8_23a94727_PNC_00_MAPPING_b2c42696_RX_EnableNoinit] */
  { /*   102 */        67u, BSWM_COMPDUGROUPHANDLINGPARAMETERS_PARAMETEROFACTIONITEMS,                                2u },  /* [AL_CC_AL_RBTM_FR_BODY3_4xwwtd59665s787n6ctawh7k8_23a94727_TX_Disable] */
  { /*   103 */        67u, BSWM_COMPDUGROUPHANDLINGPARAMETERS_PARAMETEROFACTIONITEMS,                                3u },  /* [AL_CC_AL_RBTM_FR_BODY3_4xwwtd59665s787n6ctawh7k8_23a94727_TX_EnableNoinit] */
  { /*   104 */        67u, BSWM_COMPDUGROUPHANDLINGPARAMETERS_PARAMETEROFACTIONITEMS,                                4u },  /* [AL_CC_AL_RBTM_FR_BODY3_4xwwtd59665s787n6ctawh7k8_23a94727_PNC_20_MAPPING_796df885_TX_Disable] */
  { /*   105 */        67u, BSWM_COMPDUGROUPHANDLINGPARAMETERS_PARAMETEROFACTIONITEMS,                                5u },  /* [AL_CC_AL_RBTM_FR_BODY3_4xwwtd59665s787n6ctawh7k8_23a94727_PNC_20_MAPPING_796df885_TX_EnableNoinit] */
  { /*   106 */        67u, BSWM_COMPDUGROUPHANDLINGPARAMETERS_PARAMETEROFACTIONITEMS,                                6u },  /* [AL_CC_AL_RBTM_FR_BODY3_4xwwtd59665s787n6ctawh7k8_23a94727_PNC_00_MAPPING_b2c42696_TX_Disable] */
  { /*   107 */        67u, BSWM_COMPDUGROUPHANDLINGPARAMETERS_PARAMETEROFACTIONITEMS,                                7u },  /* [AL_CC_AL_RBTM_FR_BODY3_4xwwtd59665s787n6ctawh7k8_23a94727_PNC_00_MAPPING_b2c42696_TX_EnableNoinit] */
  { /*   108 */        68u,       BSWM_COMDMHANDLINGPARAMETERS_PARAMETEROFACTIONITEMS,                                2u },  /* [AL_CC_AL_RBTM_FR_BODY3_4xwwtd59665s787n6ctawh7k8_23a94727_PNC_20_MAPPING_796df885_Disable_DM] */
  { /*   109 */        68u,       BSWM_COMDMHANDLINGPARAMETERS_PARAMETEROFACTIONITEMS,                                3u },  /* [AL_CC_AL_RBTM_FR_BODY3_4xwwtd59665s787n6ctawh7k8_23a94727_PNC_20_MAPPING_796df885_Enable_DM] */
  { /*   110 */        67u, BSWM_COMPDUGROUPHANDLINGPARAMETERS_PARAMETEROFACTIONITEMS,                                8u },  /* [AL_CC_AL_RBTM_FR_BODY3_4xwwtd59665s787n6ctawh7k8_23a94727_PNC_20_MAPPING_796df885_RX_Disable] */
  { /*   111 */        67u, BSWM_COMPDUGROUPHANDLINGPARAMETERS_PARAMETEROFACTIONITEMS,                                9u },  /* [AL_CC_AL_RBTM_FR_BODY3_4xwwtd59665s787n6ctawh7k8_23a94727_PNC_20_MAPPING_796df885_RX_EnableNoinit] */
  { /*   112 */        71u,                            BSWM_NO_PARAMETEROFACTIONITEMS, BSWM_NO_PARAMETERIDXOFACTIONITEMS },  /* [AL_AL_SwcDiag_FullCom] */
  { /*   113 */        70u,                            BSWM_NO_PARAMETEROFACTIONITEMS, BSWM_NO_PARAMETERIDXOFACTIONITEMS }   /* [AL_AL_SwcDiag_NotFullCom] */
};
#define BSWM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  BswM_ActionListsLeft
**********************************************************************************************************************/
/** 
  \var    BswM_ActionListsLeft
  \details
  Element                Description
  Conditional            If true, action list is executed on condition else on trigger.
  ActionItemsEndIdx      the end index of the 0:n relation pointing to BswM_ActionItems
  ActionItemsStartIdx    the start index of the 0:n relation pointing to BswM_ActionItems
*/ 
#define BSWM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(BswM_ActionListsType, BSWM_CONST) BswM_ActionListsLeft[30] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    Conditional  ActionItemsEndIdx  ActionItemsStartIdx        Comment                   Referable Keys */
  { /*     0 */       FALSE,                1u,                  0u },  /* [Priority: 0] */  /* [AL_CC_AL_RBTM_FL_BODY3_8uqv9blm85ehm0msat385m76v_03d5f5f6_TX_Disable] */
  { /*     1 */       FALSE,                2u,                  1u },  /* [Priority: 0] */  /* [AL_CC_AL_RBTM_FL_BODY3_8uqv9blm85ehm0msat385m76v_03d5f5f6_TX_EnableNoinit] */
  { /*     2 */        TRUE,                6u,                  2u },  /* [Priority: 0] */  /* [AL_ESH_AL_ExitRun] */
  { /*     3 */        TRUE,               12u,                  6u },  /* [Priority: 0] */  /* [AL_ESH_AL_RunToPostRun] */
  { /*     4 */        TRUE,               14u,                 12u },  /* [Priority: 0] */  /* [AL_ESH_AL_WaitForNvMToShutdown] */
  { /*     5 */        TRUE,               18u,                 14u },  /* [Priority: 0] */  /* [AL_ESH_AL_WakeupToPrep] */
  { /*     6 */        TRUE,               21u,                 18u },  /* [Priority: 0] */  /* [AL_ESH_AL_WaitForNvMWakeup] */
  { /*     7 */        TRUE,               28u,                 21u },  /* [Priority: 0] */  /* [AL_ESH_AL_WakeupToRun] */
  { /*     8 */        TRUE,               30u,                 28u },  /* [Priority: 0] */  /* [AL_ESH_AL_DemInit] */
  { /*     9 */        TRUE,               33u,                 30u },  /* [Priority: 0] */  /* [AL_ESH_AL_InitToWakeup] */
  { /*    10 */        TRUE,               40u,                 33u },  /* [Priority: 0] */  /* [AL_ESH_AL_PostRunToPrepShutdown] */
  { /*    11 */        TRUE,               41u,                 40u },  /* [Priority: 0] */  /* [AL_ESH_AL_ESH_PostRunToPrepCheck] */
  { /*    12 */        TRUE,               47u,                 41u },  /* [Priority: 0] */  /* [AL_ESH_AL_PostRunToRun] */
  { /*    13 */        TRUE,               52u,                 47u },  /* [Priority: 0] */  /* [AL_ESH_AL_ExitPostRun] */
  { /*    14 */        TRUE,               55u,                 52u },  /* [Priority: 0] */  /* [AL_ESH_AL_PrepShutdownToWaitForNvM] */
  { /*    15 */        TRUE,              100u,                 55u },  /* [Priority: 0] */  /* [AL_INIT_AL_Initialize] */
  { /*    16 */       FALSE,              101u,                100u },  /* [Priority: 0] */  /* [AL_CC_AL_RBTM_FL_BODY3_8uqv9blm85ehm0msat385m76v_03d5f5f6_PNC_00_MAPPING_b2c42696_RX_Disable] */
  { /*    17 */       FALSE,              102u,                101u },  /* [Priority: 0] */  /* [AL_CC_AL_RBTM_FL_BODY3_8uqv9blm85ehm0msat385m76v_03d5f5f6_PNC_00_MAPPING_b2c42696_RX_EnableNoinit] */
  { /*    18 */       FALSE,              103u,                102u },  /* [Priority: 0] */  /* [AL_CC_AL_RBTM_FL_BODY3_8uqv9blm85ehm0msat385m76v_03d5f5f6_PNC_00_MAPPING_b2c42696_Disable_DM] */
  { /*    19 */       FALSE,              104u,                103u },  /* [Priority: 0] */  /* [AL_CC_AL_RBTM_FL_BODY3_8uqv9blm85ehm0msat385m76v_03d5f5f6_PNC_00_MAPPING_b2c42696_Enable_DM] */
  { /*    20 */       FALSE,              105u,                104u },  /* [Priority: 0] */  /* [AL_CC_AL_RBTM_FL_BODY3_8uqv9blm85ehm0msat385m76v_03d5f5f6_PNC_00_MAPPING_b2c42696_TX_Disable] */
  { /*    21 */       FALSE,              106u,                105u },  /* [Priority: 0] */  /* [AL_CC_AL_RBTM_FL_BODY3_8uqv9blm85ehm0msat385m76v_03d5f5f6_PNC_00_MAPPING_b2c42696_TX_EnableNoinit] */
  { /*    22 */       FALSE,              107u,                106u },  /* [Priority: 0] */  /* [AL_CC_AL_RBTM_FL_BODY3_8uqv9blm85ehm0msat385m76v_03d5f5f6_PNC_20_MAPPING_796df885_Disable_DM] */
  { /*    23 */       FALSE,              108u,                107u },  /* [Priority: 0] */  /* [AL_CC_AL_RBTM_FL_BODY3_8uqv9blm85ehm0msat385m76v_03d5f5f6_PNC_20_MAPPING_796df885_Enable_DM] */
  { /*    24 */       FALSE,              109u,                108u },  /* [Priority: 0] */  /* [AL_CC_AL_RBTM_FL_BODY3_8uqv9blm85ehm0msat385m76v_03d5f5f6_PNC_20_MAPPING_796df885_TX_Disable] */
  { /*    25 */       FALSE,              110u,                109u },  /* [Priority: 0] */  /* [AL_CC_AL_RBTM_FL_BODY3_8uqv9blm85ehm0msat385m76v_03d5f5f6_PNC_20_MAPPING_796df885_TX_EnableNoinit] */
  { /*    26 */       FALSE,              111u,                110u },  /* [Priority: 0] */  /* [AL_CC_AL_RBTM_FL_BODY3_8uqv9blm85ehm0msat385m76v_03d5f5f6_PNC_20_MAPPING_796df885_RX_Disable] */
  { /*    27 */       FALSE,              112u,                111u },  /* [Priority: 0] */  /* [AL_CC_AL_RBTM_FL_BODY3_8uqv9blm85ehm0msat385m76v_03d5f5f6_PNC_20_MAPPING_796df885_RX_EnableNoinit] */
  { /*    28 */       FALSE,              113u,                112u },  /* [Priority: 0] */  /* [AL_AL_SwcDiag_FullCom] */
  { /*    29 */       FALSE,              114u,                113u }   /* [Priority: 0] */  /* [AL_AL_SwcDiag_NotFullCom] */
};
#define BSWM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  BswM_ActionListsRight
**********************************************************************************************************************/
/** 
  \var    BswM_ActionListsRight
  \details
  Element                Description
  Conditional            If true, action list is executed on condition else on trigger.
  ActionItemsEndIdx      the end index of the 0:n relation pointing to BswM_ActionItems
  ActionItemsStartIdx    the start index of the 0:n relation pointing to BswM_ActionItems
*/ 
#define BSWM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(BswM_ActionListsType, BSWM_CONST) BswM_ActionListsRight[30] = {  /* PRQA S 1514, 1533, 1504 */  /* MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ExternalMcData */
    /* Index    Conditional  ActionItemsEndIdx  ActionItemsStartIdx        Comment                   Referable Keys */
  { /*     0 */        TRUE,                4u,                  0u },  /* [Priority: 0] */  /* [AL_ESH_AL_ExitRun] */
  { /*     1 */        TRUE,               10u,                  4u },  /* [Priority: 0] */  /* [AL_ESH_AL_RunToPostRun] */
  { /*     2 */        TRUE,               12u,                 10u },  /* [Priority: 0] */  /* [AL_ESH_AL_WaitForNvMToShutdown] */
  { /*     3 */        TRUE,               16u,                 12u },  /* [Priority: 0] */  /* [AL_ESH_AL_WakeupToPrep] */
  { /*     4 */        TRUE,               19u,                 16u },  /* [Priority: 0] */  /* [AL_ESH_AL_WaitForNvMWakeup] */
  { /*     5 */        TRUE,               26u,                 19u },  /* [Priority: 0] */  /* [AL_ESH_AL_WakeupToRun] */
  { /*     6 */        TRUE,               28u,                 26u },  /* [Priority: 0] */  /* [AL_ESH_AL_DemInit] */
  { /*     7 */        TRUE,               31u,                 28u },  /* [Priority: 0] */  /* [AL_ESH_AL_InitToWakeup] */
  { /*     8 */        TRUE,               38u,                 31u },  /* [Priority: 0] */  /* [AL_ESH_AL_PostRunToPrepShutdown] */
  { /*     9 */        TRUE,               39u,                 38u },  /* [Priority: 0] */  /* [AL_ESH_AL_ESH_PostRunToPrepCheck] */
  { /*    10 */        TRUE,               45u,                 39u },  /* [Priority: 0] */  /* [AL_ESH_AL_PostRunToRun] */
  { /*    11 */        TRUE,               50u,                 45u },  /* [Priority: 0] */  /* [AL_ESH_AL_ExitPostRun] */
  { /*    12 */        TRUE,               53u,                 50u },  /* [Priority: 0] */  /* [AL_ESH_AL_PrepShutdownToWaitForNvM] */
  { /*    13 */        TRUE,               98u,                 53u },  /* [Priority: 0] */  /* [AL_INIT_AL_Initialize] */
  { /*    14 */       FALSE,               99u,                 98u },  /* [Priority: 0] */  /* [AL_CC_AL_RBTM_FR_BODY3_4xwwtd59665s787n6ctawh7k8_23a94727_PNC_00_MAPPING_b2c42696_Disable_DM] */
  { /*    15 */       FALSE,              100u,                 99u },  /* [Priority: 0] */  /* [AL_CC_AL_RBTM_FR_BODY3_4xwwtd59665s787n6ctawh7k8_23a94727_PNC_00_MAPPING_b2c42696_Enable_DM] */
  { /*    16 */       FALSE,              101u,                100u },  /* [Priority: 0] */  /* [AL_CC_AL_RBTM_FR_BODY3_4xwwtd59665s787n6ctawh7k8_23a94727_PNC_00_MAPPING_b2c42696_RX_Disable] */
  { /*    17 */       FALSE,              102u,                101u },  /* [Priority: 0] */  /* [AL_CC_AL_RBTM_FR_BODY3_4xwwtd59665s787n6ctawh7k8_23a94727_PNC_00_MAPPING_b2c42696_RX_EnableNoinit] */
  { /*    18 */       FALSE,              103u,                102u },  /* [Priority: 0] */  /* [AL_CC_AL_RBTM_FR_BODY3_4xwwtd59665s787n6ctawh7k8_23a94727_TX_Disable] */
  { /*    19 */       FALSE,              104u,                103u },  /* [Priority: 0] */  /* [AL_CC_AL_RBTM_FR_BODY3_4xwwtd59665s787n6ctawh7k8_23a94727_TX_EnableNoinit] */
  { /*    20 */       FALSE,              105u,                104u },  /* [Priority: 0] */  /* [AL_CC_AL_RBTM_FR_BODY3_4xwwtd59665s787n6ctawh7k8_23a94727_PNC_20_MAPPING_796df885_TX_Disable] */
  { /*    21 */       FALSE,              106u,                105u },  /* [Priority: 0] */  /* [AL_CC_AL_RBTM_FR_BODY3_4xwwtd59665s787n6ctawh7k8_23a94727_PNC_20_MAPPING_796df885_TX_EnableNoinit] */
  { /*    22 */       FALSE,              107u,                106u },  /* [Priority: 0] */  /* [AL_CC_AL_RBTM_FR_BODY3_4xwwtd59665s787n6ctawh7k8_23a94727_PNC_00_MAPPING_b2c42696_TX_Disable] */
  { /*    23 */       FALSE,              108u,                107u },  /* [Priority: 0] */  /* [AL_CC_AL_RBTM_FR_BODY3_4xwwtd59665s787n6ctawh7k8_23a94727_PNC_00_MAPPING_b2c42696_TX_EnableNoinit] */
  { /*    24 */       FALSE,              109u,                108u },  /* [Priority: 0] */  /* [AL_CC_AL_RBTM_FR_BODY3_4xwwtd59665s787n6ctawh7k8_23a94727_PNC_20_MAPPING_796df885_Disable_DM] */
  { /*    25 */       FALSE,              110u,                109u },  /* [Priority: 0] */  /* [AL_CC_AL_RBTM_FR_BODY3_4xwwtd59665s787n6ctawh7k8_23a94727_PNC_20_MAPPING_796df885_Enable_DM] */
  { /*    26 */       FALSE,              111u,                110u },  /* [Priority: 0] */  /* [AL_CC_AL_RBTM_FR_BODY3_4xwwtd59665s787n6ctawh7k8_23a94727_PNC_20_MAPPING_796df885_RX_Disable] */
  { /*    27 */       FALSE,              112u,                111u },  /* [Priority: 0] */  /* [AL_CC_AL_RBTM_FR_BODY3_4xwwtd59665s787n6ctawh7k8_23a94727_PNC_20_MAPPING_796df885_RX_EnableNoinit] */
  { /*    28 */       FALSE,              113u,                112u },  /* [Priority: 0] */  /* [AL_AL_SwcDiag_FullCom] */
  { /*    29 */       FALSE,              114u,                113u }   /* [Priority: 0] */  /* [AL_AL_SwcDiag_NotFullCom] */
};
#define BSWM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  BswM_ActionsLeft
**********************************************************************************************************************/
/** 
  \var    BswM_ActionsLeft
  \brief  Holds pointer to all action functions.
*/ 
#define BSWM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(BswM_ActionFuncType, BSWM_CONST) BswM_ActionsLeft[72] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     Actions                                                                                                 Referable Keys */
  /*     0 */ BswM_Action_RuleHandler                                                                            ,  /* [R_ESH_DemInit, R_ESH_PostRunNested, R_ESH_PostRunToPrepNested, R_ESH_RunToPostRunNested] */
  /*     1 */ BswM_Action_EcuMStateSwitch                                                                        ,  /* [A_SwitchEcuMStateTo_POST_RUN, A_SwitchEcuMStateTo_RUN, A_SwitchEcuMStateTo_SHUTDOWN] */
  /*     2 */ BswM_Action_Rtm_CpuLoadMeasurementStart_Left                                                       ,  /* [A_Rtm_CpuLoadMeasurementStart] */
  /*     3 */ BswM_Action_INIT_Action_Wdg_17_Scu_Init_Left                                                       ,  /* [A_INIT_Action_Wdg_17_Scu_Init] */
  /*     4 */ BswM_Action_INIT_Action_WdgM_Init_Left                                                             ,  /* [A_INIT_Action_WdgM_Init] */
  /*     5 */ BswM_Action_INIT_Action_StbM_PreInit_Left                                                          ,  /* [A_INIT_Action_StbM_PreInit] */
  /*     6 */ BswM_Action_INIT_Action_StbM_PostInit_Left                                                         ,  /* [A_INIT_Action_StbM_PostInit] */
  /*     7 */ BswM_Action_INIT_Action_StbM_Init_Left                                                             ,  /* [A_INIT_Action_StbM_Init] */
  /*     8 */ BswM_Action_INIT_Action_Spi_Init_Left                                                              ,  /* [A_INIT_Action_Spi_Init] */
  /*     9 */ BswM_Action_INIT_Action_Smu_Init_Left                                                              ,  /* [A_INIT_Action_Smu_Init] */
  /*    10 */ BswM_Action_INIT_Action_SecOC_Init_Left                                                            ,  /* [A_INIT_Action_SecOC_Init] */
  /*    11 */ BswM_Action_INIT_Action_SBC_Init_Left                                                              ,  /* [A_INIT_Action_SBC_Init] */
  /*    12 */ BswM_Action_INIT_Action_Rtm_Init_Left                                                              ,  /* [A_INIT_Action_Rtm_Init] */
  /*    13 */ BswM_Action_INIT_Action_Rte_Start_Left                                                             ,  /* [A_INIT_Action_Rte_Start] */
  /*    14 */ BswM_Action_INIT_Action_RCM_Init_Left                                                              ,  /* [A_INIT_Action_RCM_Init] */
  /*    15 */ BswM_Action_INIT_Action_Pwm_17_GtmCcu6_Init_Left                                                   ,  /* [A_INIT_Action_Pwm_17_GtmCcu6_Init] */
  /*    16 */ BswM_Action_INIT_Action_Port_Init_Left                                                             ,  /* [A_INIT_Action_Port_Init] */
  /*    17 */ BswM_Action_INIT_Action_PduR_Init_Left                                                             ,  /* [A_INIT_Action_PduR_Init] */
  /*    18 */ BswM_Action_INIT_Action_NvMReadAll_Left                                                            ,  /* [A_INIT_Action_NvMReadAll] */
  /*    19 */ BswM_Action_INIT_Action_Nm_PreInit_Left                                                            ,  /* [A_INIT_Action_Nm_PreInit] */
  /*    20 */ BswM_Action_INIT_Action_Nm_PostInit_Left                                                           ,  /* [A_INIT_Action_Nm_PostInit] */
  /*    21 */ BswM_Action_INIT_Action_Nm_Init_Left                                                               ,  /* [A_INIT_Action_Nm_Init] */
  /*    22 */ BswM_Action_INIT_Action_KeyM_Init_Left                                                             ,  /* [A_INIT_Action_KeyM_Init] */
  /*    23 */ BswM_Action_INIT_Action_IpduM_Init_Left                                                            ,  /* [A_INIT_Action_IpduM_Init] */
  /*    24 */ BswM_Action_INIT_Action_Icu_17_TimerIp_Init_Left                                                   ,  /* [A_INIT_Action_Icu_17_TimerIp_Init] */
  /*    25 */ BswM_Action_INIT_Action_Gpt_Init_Left                                                              ,  /* [A_INIT_Action_Gpt_Init] */
  /*    26 */ BswM_Action_INIT_Action_EnableInterrupts_Left                                                      ,  /* [A_INIT_Action_EnableInterrupts] */
  /*    27 */ BswM_Action_INIT_Action_Dma_Init_Left                                                              ,  /* [A_INIT_Action_Dma_Init] */
  /*    28 */ BswM_Action_INIT_Action_Dcm_Init_Left                                                              ,  /* [A_INIT_Action_Dcm_Init] */
  /*    29 */ BswM_Action_INIT_Action_Csm_Init_Left                                                              ,  /* [A_INIT_Action_Csm_Init] */
  /*    30 */ BswM_Action_INIT_Action_Crypto_30_vHsm_Init_Left                                                   ,  /* [A_INIT_Action_Crypto_30_vHsm_Init] */
  /*    31 */ BswM_Action_INIT_Action_Crypto_30_LibCv_Init_Left                                                  ,  /* [A_INIT_Action_Crypto_30_LibCv_Init] */
  /*    32 */ BswM_Action_INIT_Action_CryIf_Init_Left                                                            ,  /* [A_INIT_Action_CryIf_Init] */
  /*    33 */ BswM_Action_INIT_Action_Com_Init_Left                                                              ,  /* [A_INIT_Action_Com_Init] */
  /*    34 */ BswM_Action_INIT_Action_ComM_PreInit_Left                                                          ,  /* [A_INIT_Action_ComM_PreInit] */
  /*    35 */ BswM_Action_INIT_Action_ComM_PostInit_Left                                                         ,  /* [A_INIT_Action_ComM_PostInit] */
  /*    36 */ BswM_Action_INIT_Action_ComM_Init_Left                                                             ,  /* [A_INIT_Action_ComM_Init] */
  /*    37 */ BswM_Action_INIT_Action_Can_Init_Left                                                              ,  /* [A_INIT_Action_Can_Init] */
  /*    38 */ BswM_Action_INIT_Action_CanTp_Init_Left                                                            ,  /* [A_INIT_Action_CanTp_Init] */
  /*    39 */ BswM_Action_INIT_Action_CanTSyn_PreInit_Left                                                       ,  /* [A_INIT_Action_CanTSyn_PreInit] */
  /*    40 */ BswM_Action_INIT_Action_CanTSyn_Init_Left                                                          ,  /* [A_INIT_Action_CanTSyn_Init] */
  /*    41 */ BswM_Action_INIT_Action_CanSM_Init_Left                                                            ,  /* [A_INIT_Action_CanSM_Init] */
  /*    42 */ BswM_Action_INIT_Action_CanNm_Init_Left                                                            ,  /* [A_INIT_Action_CanNm_Init] */
  /*    43 */ BswM_Action_INIT_Action_CanIf_Init_Left                                                            ,  /* [A_INIT_Action_CanIf_Init] */
  /*    44 */ BswM_Action_INIT_Action_Adc_Init_Left                                                              ,  /* [A_INIT_Action_Adc_Init] */
  /*    45 */ BswM_Action_INIT_Action_AdcIf_Init_Left                                                            ,  /* [A_INIT_Action_AdcIf_Init] */
  /*    46 */ BswM_Action_ESH_Action_SwitchWakeup_Left                                                           ,  /* [A_ESH_Action_SwitchWakeup] */
  /*    47 */ BswM_Action_ESH_Action_SwitchShutdown_Left                                                         ,  /* [A_ESH_Action_SwitchShutdown] */
  /*    48 */ BswM_Action_ESH_Action_SwitchRun_Left                                                              ,  /* [A_ESH_Action_SwitchRun] */
  /*    49 */ BswM_Action_ESH_Action_SwitchPostRun_Left                                                          ,  /* [A_ESH_Action_SwitchPostRun] */
  /* Index     Actions                                                                                                 Referable Keys */
  /*    50 */ BswM_Action_TimerControl                                                                           ,  /* [A_ESH_Action_SelfRunRequestTimer_Start] */
  /*    51 */ BswM_Action_ESH_Action_OnEnterWakeup_Left                                                          ,  /* [A_ESH_Action_OnEnterWakeup] */
  /*    52 */ BswM_Action_ESH_Action_OnEnterWaitForNvm_Left                                                      ,  /* [A_ESH_Action_OnEnterWaitForNvm] */
  /*    53 */ BswM_Action_ESH_Action_OnEnterShutdown_Left                                                        ,  /* [A_ESH_Action_OnEnterShutdown] */
  /*    54 */ BswM_Action_ESH_Action_OnEnterRun_Left                                                             ,  /* [A_ESH_Action_OnEnterRun] */
  /*    55 */ BswM_Action_ESH_Action_OnEnterPrepShutdown_Left                                                    ,  /* [A_ESH_Action_OnEnterPrepShutdown] */
  /*    56 */ BswM_Action_ESH_Action_OnEnterPostRun_Left                                                         ,  /* [A_ESH_Action_OnEnterPostRun] */
  /*    57 */ BswM_Action_ESH_Action_ExitExclusiveArea_Left                                                      ,  /* [A_ESH_Action_ExitExclusiveArea] */
  /*    58 */ BswM_Action_ESH_Action_EnterExclusiveArea_Left                                                     ,  /* [A_ESH_Action_EnterExclusiveArea] */
  /*    59 */ BswM_Action_ESH_Action_EcuMGoToSelectedShutdownTarget_Left                                         ,  /* [A_ESH_Action_EcuMGoToSelectedShutdownTarget] */
  /*    60 */ BswM_Action_ESH_Action_EcuMClearValidatedWakeupEvents_Left                                         ,  /* [A_ESH_Action_EcuMClearValidatedWakeupEvents] */
  /*    61 */ BswM_Action_ESH_Action_DemShutdown_Left                                                            ,  /* [A_ESH_Action_DemShutdown] */
  /*    62 */ BswM_Action_ESH_Action_DemPostRunRequested_Left_Left                                               ,  /* [A_ESH_Action_DemPostRunRequested_Left] */
  /*    63 */ BswM_Action_GenericMode                                                                            ,  /* [A_ESH_Action_DemInitialized, A_ESH_Action_DemNotInitialized, A_ESH_Action_ESH_PostRun, A_ESH_Action_ESH_PrepShutdown, A_ESH_Action_ESH_Run, A_ESH_Action_ESH_WaitForNvm, A_ESH_Action_ESH_Wakeup] */
  /*    64 */ BswM_Action_ESH_Action_DemInit_Left                                                                ,  /* [A_ESH_Action_DemInit, A_INIT_Action_Dem_Init] */
  /*    65 */ BswM_Action_ESH_Action_ComMCheckPendingRequests_Left_Left                                          ,  /* [A_ESH_Action_ComMCheckPendingRequests_Left] */
  /*    66 */ BswM_Action_ComMAllowCom                                                                           ,  /* [A_ESH_Action_ComMAllow_RBTM_FL_BODY3_8uqv9blm85ehm0msat385m76v_03d5f5f6, A_ESH_Action_ComMDisallow_RBTM_FL_BODY3_8uqv9blm85ehm0msat385m76v_03d5f5f6] */
  /*    67 */ BswM_Action_ComPduGroupHandling                                                                    ,  /* [A_CC_DisablePDUGroup_RBTM_FL_BODY3_Rx_PNC_20_54c591d6, A_CC_DisablePDUGroup_RBTM_FL_BODY3_Rx_PNC_All_Active_46e8c3b2, A_CC_DisablePDUGroup_RBTM_FL_BODY3_Tx_PNC_20_27dfe85c, A_CC_DisablePDUGroup_RBTM_FL_BODY3_Tx_PNC_All_Active_e1dc74ba, A_CC_DisablePDUGroup_TxMess_RBTM_FL_BODY3_e804245a, A_CC_EnablePDUGroup_RBTM_FL_BODY3_Rx_PNC_20_54c591d6, A_CC_EnablePDUGroup_RBTM_FL_BODY3_Rx_PNC_All_Active_46e8c3b2, A_CC_EnablePDUGroup_RBTM_FL_BODY3_Tx_PNC_20_27dfe85c, A_CC_EnablePDUGroup_RBTM_FL_BODY3_Tx_PNC_All_Active_e1dc74ba, A_CC_EnablePDUGroup_TxMess_RBTM_FL_BODY3_e804245a] */
  /*    68 */ BswM_Action_ComDMHandling                                                                          ,  /* [A_CC_DisableDM_RBTM_FL_BODY3_Rx_PNC_20_54c591d6, A_CC_DisableDM_RBTM_FL_BODY3_Rx_PNC_All_Active_46e8c3b2, A_CC_EnableDM_RBTM_FL_BODY3_Rx_PNC_20_54c591d6, A_CC_EnableDM_RBTM_FL_BODY3_Rx_PNC_All_Active_46e8c3b2] */
  /*    69 */ BswM_Action_Action_Rtm_Shutdown_Left                                                               ,  /* [A_Action_Rtm_Shutdown] */
  /*    70 */ BswM_Action_Action_RTE_SWITCH_BswMSwitchPort_SwcDiagCommunicationMode_COMM_NO_COMMUNICATION_Left   ,  /* [A_Action_RTE_SWITCH_BswMSwitchPort_SwcDiagCommunicationMode_COMM_NO_COMMUNICATION] */
  /*    71 */ BswM_Action_Action_RTE_SWITCH_BswMSwitchPort_SwcDiagCommunicationMode_COMM_FULL_COMMUNICATION_Left    /* [A_Action_RTE_SWITCH_BswMSwitchPort_SwcDiagCommunicationMode_COMM_FULL_COMMUNICATION] */
};
#define BSWM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  BswM_ActionsRight
**********************************************************************************************************************/
/** 
  \var    BswM_ActionsRight
  \brief  Holds pointer to all action functions.
*/ 
#define BSWM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(BswM_ActionFuncType, BSWM_CONST) BswM_ActionsRight[72] = {  /* PRQA S 1514, 1533, 1504 */  /* MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ExternalMcData */
  /* Index     Actions                                                                                                 Referable Keys */
  /*     0 */ BswM_Action_RuleHandler                                                                            ,  /* [R_ESH_DemInit, R_ESH_PostRunNested, R_ESH_PostRunToPrepNested, R_ESH_RunToPostRunNested] */
  /*     1 */ BswM_Action_EcuMStateSwitch                                                                        ,  /* [A_SwitchEcuMStateTo_POST_RUN, A_SwitchEcuMStateTo_RUN, A_SwitchEcuMStateTo_SHUTDOWN] */
  /*     2 */ BswM_Action_Rtm_CpuLoadMeasurementStart_Left                                                       ,  /* [A_Rtm_CpuLoadMeasurementStart] */
  /*     3 */ BswM_Action_INIT_Action_Wdg_17_Scu_Init_Left                                                       ,  /* [A_INIT_Action_Wdg_17_Scu_Init] */
  /*     4 */ BswM_Action_INIT_Action_WdgM_Init_Left                                                             ,  /* [A_INIT_Action_WdgM_Init] */
  /*     5 */ BswM_Action_INIT_Action_StbM_PreInit_Left                                                          ,  /* [A_INIT_Action_StbM_PreInit] */
  /*     6 */ BswM_Action_INIT_Action_StbM_PostInit_Left                                                         ,  /* [A_INIT_Action_StbM_PostInit] */
  /*     7 */ BswM_Action_INIT_Action_StbM_Init_Left                                                             ,  /* [A_INIT_Action_StbM_Init] */
  /*     8 */ BswM_Action_INIT_Action_Spi_Init_Left                                                              ,  /* [A_INIT_Action_Spi_Init] */
  /*     9 */ BswM_Action_INIT_Action_Smu_Init_Left                                                              ,  /* [A_INIT_Action_Smu_Init] */
  /*    10 */ BswM_Action_INIT_Action_SecOC_Init_Left                                                            ,  /* [A_INIT_Action_SecOC_Init] */
  /*    11 */ BswM_Action_INIT_Action_SBC_Init_Left                                                              ,  /* [A_INIT_Action_SBC_Init] */
  /*    12 */ BswM_Action_INIT_Action_Rtm_Init_Left                                                              ,  /* [A_INIT_Action_Rtm_Init] */
  /*    13 */ BswM_Action_INIT_Action_Rte_Start_Left                                                             ,  /* [A_INIT_Action_Rte_Start] */
  /*    14 */ BswM_Action_INIT_Action_RCM_Init_Left                                                              ,  /* [A_INIT_Action_RCM_Init] */
  /*    15 */ BswM_Action_INIT_Action_Pwm_17_GtmCcu6_Init_Left                                                   ,  /* [A_INIT_Action_Pwm_17_GtmCcu6_Init] */
  /*    16 */ BswM_Action_INIT_Action_Port_Init_Left                                                             ,  /* [A_INIT_Action_Port_Init] */
  /*    17 */ BswM_Action_INIT_Action_PduR_Init_Left                                                             ,  /* [A_INIT_Action_PduR_Init] */
  /*    18 */ BswM_Action_INIT_Action_NvMReadAll_Left                                                            ,  /* [A_INIT_Action_NvMReadAll] */
  /*    19 */ BswM_Action_INIT_Action_Nm_PreInit_Left                                                            ,  /* [A_INIT_Action_Nm_PreInit] */
  /*    20 */ BswM_Action_INIT_Action_Nm_PostInit_Left                                                           ,  /* [A_INIT_Action_Nm_PostInit] */
  /*    21 */ BswM_Action_INIT_Action_Nm_Init_Left                                                               ,  /* [A_INIT_Action_Nm_Init] */
  /*    22 */ BswM_Action_INIT_Action_KeyM_Init_Left                                                             ,  /* [A_INIT_Action_KeyM_Init] */
  /*    23 */ BswM_Action_INIT_Action_IpduM_Init_Left                                                            ,  /* [A_INIT_Action_IpduM_Init] */
  /*    24 */ BswM_Action_INIT_Action_Icu_17_TimerIp_Init_Left                                                   ,  /* [A_INIT_Action_Icu_17_TimerIp_Init] */
  /*    25 */ BswM_Action_INIT_Action_Gpt_Init_Left                                                              ,  /* [A_INIT_Action_Gpt_Init] */
  /*    26 */ BswM_Action_INIT_Action_EnableInterrupts_Left                                                      ,  /* [A_INIT_Action_EnableInterrupts] */
  /*    27 */ BswM_Action_INIT_Action_Dma_Init_Left                                                              ,  /* [A_INIT_Action_Dma_Init] */
  /*    28 */ BswM_Action_INIT_Action_Dcm_Init_Left                                                              ,  /* [A_INIT_Action_Dcm_Init] */
  /*    29 */ BswM_Action_INIT_Action_Csm_Init_Left                                                              ,  /* [A_INIT_Action_Csm_Init] */
  /*    30 */ BswM_Action_INIT_Action_Crypto_30_vHsm_Init_Left                                                   ,  /* [A_INIT_Action_Crypto_30_vHsm_Init] */
  /*    31 */ BswM_Action_INIT_Action_Crypto_30_LibCv_Init_Left                                                  ,  /* [A_INIT_Action_Crypto_30_LibCv_Init] */
  /*    32 */ BswM_Action_INIT_Action_CryIf_Init_Left                                                            ,  /* [A_INIT_Action_CryIf_Init] */
  /*    33 */ BswM_Action_INIT_Action_Com_Init_Left                                                              ,  /* [A_INIT_Action_Com_Init] */
  /*    34 */ BswM_Action_INIT_Action_ComM_PreInit_Left                                                          ,  /* [A_INIT_Action_ComM_PreInit] */
  /*    35 */ BswM_Action_INIT_Action_ComM_PostInit_Left                                                         ,  /* [A_INIT_Action_ComM_PostInit] */
  /*    36 */ BswM_Action_INIT_Action_ComM_Init_Left                                                             ,  /* [A_INIT_Action_ComM_Init] */
  /*    37 */ BswM_Action_INIT_Action_Can_Init_Left                                                              ,  /* [A_INIT_Action_Can_Init] */
  /*    38 */ BswM_Action_INIT_Action_CanTp_Init_Left                                                            ,  /* [A_INIT_Action_CanTp_Init] */
  /*    39 */ BswM_Action_INIT_Action_CanTSyn_PreInit_Left                                                       ,  /* [A_INIT_Action_CanTSyn_PreInit] */
  /*    40 */ BswM_Action_INIT_Action_CanTSyn_Init_Right                                                         ,  /* [A_INIT_Action_CanTSyn_Init] */
  /*    41 */ BswM_Action_INIT_Action_CanSM_Init_Left                                                            ,  /* [A_INIT_Action_CanSM_Init] */
  /*    42 */ BswM_Action_INIT_Action_CanNm_Init_Left                                                            ,  /* [A_INIT_Action_CanNm_Init] */
  /*    43 */ BswM_Action_INIT_Action_CanIf_Init_Left                                                            ,  /* [A_INIT_Action_CanIf_Init] */
  /*    44 */ BswM_Action_INIT_Action_Adc_Init_Left                                                              ,  /* [A_INIT_Action_Adc_Init] */
  /*    45 */ BswM_Action_INIT_Action_AdcIf_Init_Left                                                            ,  /* [A_INIT_Action_AdcIf_Init] */
  /*    46 */ BswM_Action_ESH_Action_SwitchWakeup_Left                                                           ,  /* [A_ESH_Action_SwitchWakeup] */
  /*    47 */ BswM_Action_ESH_Action_SwitchShutdown_Left                                                         ,  /* [A_ESH_Action_SwitchShutdown] */
  /*    48 */ BswM_Action_ESH_Action_SwitchRun_Left                                                              ,  /* [A_ESH_Action_SwitchRun] */
  /*    49 */ BswM_Action_ESH_Action_SwitchPostRun_Left                                                          ,  /* [A_ESH_Action_SwitchPostRun] */
  /* Index     Actions                                                                                                 Referable Keys */
  /*    50 */ BswM_Action_TimerControl                                                                           ,  /* [A_ESH_Action_SelfRunRequestTimer_Start] */
  /*    51 */ BswM_Action_ESH_Action_OnEnterWakeup_Left                                                          ,  /* [A_ESH_Action_OnEnterWakeup] */
  /*    52 */ BswM_Action_ESH_Action_OnEnterWaitForNvm_Left                                                      ,  /* [A_ESH_Action_OnEnterWaitForNvm] */
  /*    53 */ BswM_Action_ESH_Action_OnEnterShutdown_Left                                                        ,  /* [A_ESH_Action_OnEnterShutdown] */
  /*    54 */ BswM_Action_ESH_Action_OnEnterRun_Left                                                             ,  /* [A_ESH_Action_OnEnterRun] */
  /*    55 */ BswM_Action_ESH_Action_OnEnterPrepShutdown_Left                                                    ,  /* [A_ESH_Action_OnEnterPrepShutdown] */
  /*    56 */ BswM_Action_ESH_Action_OnEnterPostRun_Left                                                         ,  /* [A_ESH_Action_OnEnterPostRun] */
  /*    57 */ BswM_Action_ESH_Action_ExitExclusiveArea_Left                                                      ,  /* [A_ESH_Action_ExitExclusiveArea] */
  /*    58 */ BswM_Action_ESH_Action_EnterExclusiveArea_Left                                                     ,  /* [A_ESH_Action_EnterExclusiveArea] */
  /*    59 */ BswM_Action_ESH_Action_EcuMGoToSelectedShutdownTarget_Left                                         ,  /* [A_ESH_Action_EcuMGoToSelectedShutdownTarget] */
  /*    60 */ BswM_Action_ESH_Action_EcuMClearValidatedWakeupEvents_Left                                         ,  /* [A_ESH_Action_EcuMClearValidatedWakeupEvents] */
  /*    61 */ BswM_Action_ESH_Action_DemShutdown_Left                                                            ,  /* [A_ESH_Action_DemShutdown] */
  /*    62 */ BswM_Action_ESH_Action_DemPostRunRequested_Right_Right                                             ,  /* [A_ESH_Action_DemPostRunRequested_Right] */
  /*    63 */ BswM_Action_GenericMode                                                                            ,  /* [A_ESH_Action_DemInitialized, A_ESH_Action_DemNotInitialized, A_ESH_Action_ESH_PostRun, A_ESH_Action_ESH_PrepShutdown, A_ESH_Action_ESH_Run, A_ESH_Action_ESH_WaitForNvm, A_ESH_Action_ESH_Wakeup] */
  /*    64 */ BswM_Action_ESH_Action_DemInit_Left                                                                ,  /* [A_ESH_Action_DemInit, A_INIT_Action_Dem_Init] */
  /*    65 */ BswM_Action_ESH_Action_ComMCheckPendingRequests_Right_Right                                        ,  /* [A_ESH_Action_ComMCheckPendingRequests_Right] */
  /*    66 */ BswM_Action_ComMAllowCom                                                                           ,  /* [A_ESH_Action_ComMAllow_RBTM_FR_BODY3_4xwwtd59665s787n6ctawh7k8_23a94727, A_ESH_Action_ComMDisallow_RBTM_FR_BODY3_4xwwtd59665s787n6ctawh7k8_23a94727] */
  /*    67 */ BswM_Action_ComPduGroupHandling                                                                    ,  /* [A_CC_DisablePDUGroup_RBTM_FR_BODY3_Rx_PNC_20_02b0f03d, A_CC_DisablePDUGroup_RBTM_FR_BODY3_Rx_PNC_All_Active_592f1bcd, A_CC_DisablePDUGroup_RBTM_FR_BODY3_Tx_PNC_20_71aa89b7, A_CC_DisablePDUGroup_RBTM_FR_BODY3_Tx_PNC_All_Active_fe1bacc5, A_CC_DisablePDUGroup_TxMess_RBTM_FR_BODY3_dfe5c3c9, A_CC_EnablePDUGroup_RBTM_FR_BODY3_Rx_PNC_20_02b0f03d, A_CC_EnablePDUGroup_RBTM_FR_BODY3_Rx_PNC_All_Active_592f1bcd, A_CC_EnablePDUGroup_RBTM_FR_BODY3_Tx_PNC_20_71aa89b7, A_CC_EnablePDUGroup_RBTM_FR_BODY3_Tx_PNC_All_Active_fe1bacc5, A_CC_EnablePDUGroup_TxMess_RBTM_FR_BODY3_dfe5c3c9] */
  /*    68 */ BswM_Action_ComDMHandling                                                                          ,  /* [A_CC_DisableDM_RBTM_FR_BODY3_Rx_PNC_20_02b0f03d, A_CC_DisableDM_RBTM_FR_BODY3_Rx_PNC_All_Active_592f1bcd, A_CC_EnableDM_RBTM_FR_BODY3_Rx_PNC_20_02b0f03d, A_CC_EnableDM_RBTM_FR_BODY3_Rx_PNC_All_Active_592f1bcd] */
  /*    69 */ BswM_Action_Action_Rtm_Shutdown_Left                                                               ,  /* [A_Action_Rtm_Shutdown] */
  /*    70 */ BswM_Action_Action_RTE_SWITCH_BswMSwitchPort_SwcDiagCommunicationMode_COMM_NO_COMMUNICATION_Left   ,  /* [A_Action_RTE_SWITCH_BswMSwitchPort_SwcDiagCommunicationMode_COMM_NO_COMMUNICATION] */
  /*    71 */ BswM_Action_Action_RTE_SWITCH_BswMSwitchPort_SwcDiagCommunicationMode_COMM_FULL_COMMUNICATION_Left    /* [A_Action_RTE_SWITCH_BswMSwitchPort_SwcDiagCommunicationMode_COMM_FULL_COMMUNICATION] */
};
#define BSWM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  BswM_CanSMChannelMappingLeft
**********************************************************************************************************************/
/** 
  \var    BswM_CanSMChannelMappingLeft
  \brief  Maps the external id of BswMCanSMIndication to an internal id and references immediate request ports.
  \details
  Element       Description
  ExternalId    External id of BswMCanSMIndication.
*/ 
#define BSWM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(BswM_CanSMChannelMappingType, BSWM_CONST) BswM_CanSMChannelMappingLeft[1] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    ExternalId                                                                   Referable Keys */
  { /*     0 */ ComMConf_ComMChannel_RBTM_FL_BODY3_8uqv9blm85ehm0msat385m76v_03d5f5f6 }   /* [CANSM_CHANNEL_0, MRP_CC_CanSMIndication_RBTM_FL_BODY3_8uqv9blm85ehm0msat385m76v_03d5f5f6] */
};
#define BSWM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  BswM_CanSMChannelMappingRight
**********************************************************************************************************************/
/** 
  \var    BswM_CanSMChannelMappingRight
  \brief  Maps the external id of BswMCanSMIndication to an internal id and references immediate request ports.
  \details
  Element       Description
  ExternalId    External id of BswMCanSMIndication.
*/ 
#define BSWM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(BswM_CanSMChannelMappingType, BSWM_CONST) BswM_CanSMChannelMappingRight[1] = {  /* PRQA S 1514, 1533, 1504 */  /* MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ExternalMcData */
    /* Index    ExternalId                                                                   Referable Keys */
  { /*     0 */ ComMConf_ComMChannel_RBTM_FR_BODY3_4xwwtd59665s787n6ctawh7k8_23a94727 }   /* [CANSM_CHANNEL_0, MRP_CC_CanSMIndication_RBTM_FR_BODY3_4xwwtd59665s787n6ctawh7k8_23a94727] */
};
#define BSWM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  BswM_ComDMHandlingDisableParametersLeft
**********************************************************************************************************************/
/** 
  \var    BswM_ComDMHandlingDisableParametersLeft
  \details
  Element        Description
  IpduGroupId
*/ 
#define BSWM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(BswM_ComDMHandlingDisableParametersType, BSWM_CONST) BswM_ComDMHandlingDisableParametersLeft[2] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    IpduGroupId                                                          Referable Keys */
  { /*     0 */ ComConf_ComIPduGroup_RBTM_FL_BODY3_Rx_PNC_All_Active_46e8c3b2 },  /* [A_CC_DisableDM_RBTM_FL_BODY3_Rx_PNC_All_Active_46e8c3b2] */
  { /*     1 */ ComConf_ComIPduGroup_RBTM_FL_BODY3_Rx_PNC_20_54c591d6         }   /* [A_CC_DisableDM_RBTM_FL_BODY3_Rx_PNC_20_54c591d6] */
};
#define BSWM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  BswM_ComDMHandlingDisableParametersRight
**********************************************************************************************************************/
/** 
  \var    BswM_ComDMHandlingDisableParametersRight
  \details
  Element        Description
  IpduGroupId
*/ 
#define BSWM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(BswM_ComDMHandlingDisableParametersType, BSWM_CONST) BswM_ComDMHandlingDisableParametersRight[2] = {  /* PRQA S 1514, 1533, 1504 */  /* MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ExternalMcData */
    /* Index    IpduGroupId                                                          Referable Keys */
  { /*     0 */ ComConf_ComIPduGroup_RBTM_FR_BODY3_Rx_PNC_All_Active_592f1bcd },  /* [A_CC_DisableDM_RBTM_FR_BODY3_Rx_PNC_All_Active_592f1bcd] */
  { /*     1 */ ComConf_ComIPduGroup_RBTM_FR_BODY3_Rx_PNC_20_02b0f03d         }   /* [A_CC_DisableDM_RBTM_FR_BODY3_Rx_PNC_20_02b0f03d] */
};
#define BSWM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  BswM_ComDMHandlingEnableParametersLeft
**********************************************************************************************************************/
/** 
  \var    BswM_ComDMHandlingEnableParametersLeft
  \details
  Element        Description
  IpduGroupId
*/ 
#define BSWM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(BswM_ComDMHandlingEnableParametersType, BSWM_CONST) BswM_ComDMHandlingEnableParametersLeft[2] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    IpduGroupId                                                          Referable Keys */
  { /*     0 */ ComConf_ComIPduGroup_RBTM_FL_BODY3_Rx_PNC_All_Active_46e8c3b2 },  /* [A_CC_EnableDM_RBTM_FL_BODY3_Rx_PNC_All_Active_46e8c3b2] */
  { /*     1 */ ComConf_ComIPduGroup_RBTM_FL_BODY3_Rx_PNC_20_54c591d6         }   /* [A_CC_EnableDM_RBTM_FL_BODY3_Rx_PNC_20_54c591d6] */
};
#define BSWM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  BswM_ComDMHandlingEnableParametersRight
**********************************************************************************************************************/
/** 
  \var    BswM_ComDMHandlingEnableParametersRight
  \details
  Element        Description
  IpduGroupId
*/ 
#define BSWM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(BswM_ComDMHandlingEnableParametersType, BSWM_CONST) BswM_ComDMHandlingEnableParametersRight[2] = {  /* PRQA S 1514, 1533, 1504 */  /* MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ExternalMcData */
    /* Index    IpduGroupId                                                          Referable Keys */
  { /*     0 */ ComConf_ComIPduGroup_RBTM_FR_BODY3_Rx_PNC_All_Active_592f1bcd },  /* [A_CC_EnableDM_RBTM_FR_BODY3_Rx_PNC_All_Active_592f1bcd] */
  { /*     1 */ ComConf_ComIPduGroup_RBTM_FR_BODY3_Rx_PNC_20_02b0f03d         }   /* [A_CC_EnableDM_RBTM_FR_BODY3_Rx_PNC_20_02b0f03d] */
};
#define BSWM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  BswM_ComDMHandlingParameters
**********************************************************************************************************************/
/** 
  \var    BswM_ComDMHandlingParameters
  \details
  Element                                   Description
  ComDMHandlingDisableParametersEndIdx      the end index of the 0:n relation pointing to BswM_ComDMHandlingDisableParameters
  ComDMHandlingDisableParametersStartIdx    the start index of the 0:n relation pointing to BswM_ComDMHandlingDisableParameters
  ComDMHandlingEnableParametersEndIdx       the end index of the 0:n relation pointing to BswM_ComDMHandlingEnableParameters
  ComDMHandlingEnableParametersStartIdx     the start index of the 0:n relation pointing to BswM_ComDMHandlingEnableParameters
*/ 
#define BSWM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(BswM_ComDMHandlingParametersType, BSWM_CONST) BswM_ComDMHandlingParameters[4] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    ComDMHandlingDisableParametersEndIdx                                   ComDMHandlingDisableParametersStartIdx                                   ComDMHandlingEnableParametersEndIdx                                   ComDMHandlingEnableParametersStartIdx                                         Referable Keys */
  { /*     0 */                                                                    1u,                                                                      0u, BSWM_NO_COMDMHANDLINGENABLEPARAMETERSENDIDXOFCOMDMHANDLINGPARAMETERS, BSWM_NO_COMDMHANDLINGENABLEPARAMETERSSTARTIDXOFCOMDMHANDLINGPARAMETERS },  /* [A_CC_DisableDM_RBTM_FL_BODY3_Rx_PNC_All_Active_46e8c3b2] */
  { /*     1 */ BSWM_NO_COMDMHANDLINGDISABLEPARAMETERSENDIDXOFCOMDMHANDLINGPARAMETERS, BSWM_NO_COMDMHANDLINGDISABLEPARAMETERSSTARTIDXOFCOMDMHANDLINGPARAMETERS,                                                                   1u,                                                                     0u },  /* [A_CC_EnableDM_RBTM_FL_BODY3_Rx_PNC_All_Active_46e8c3b2] */
  { /*     2 */                                                                    2u,                                                                      1u, BSWM_NO_COMDMHANDLINGENABLEPARAMETERSENDIDXOFCOMDMHANDLINGPARAMETERS, BSWM_NO_COMDMHANDLINGENABLEPARAMETERSSTARTIDXOFCOMDMHANDLINGPARAMETERS },  /* [A_CC_DisableDM_RBTM_FL_BODY3_Rx_PNC_20_54c591d6] */
  { /*     3 */ BSWM_NO_COMDMHANDLINGDISABLEPARAMETERSENDIDXOFCOMDMHANDLINGPARAMETERS, BSWM_NO_COMDMHANDLINGDISABLEPARAMETERSSTARTIDXOFCOMDMHANDLINGPARAMETERS,                                                                   2u,                                                                     1u }   /* [A_CC_EnableDM_RBTM_FL_BODY3_Rx_PNC_20_54c591d6] */
};
#define BSWM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  BswM_ComMAllowComParametersLeft
**********************************************************************************************************************/
/** 
  \var    BswM_ComMAllowComParametersLeft
  \details
  Element    Description
  Channel
  Allowed
*/ 
#define BSWM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(BswM_ComMAllowComParametersType, BSWM_CONST) BswM_ComMAllowComParametersLeft[2] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    Channel                                                                Allowed        Referable Keys */
  { /*     0 */ ComMConf_ComMChannel_RBTM_FL_BODY3_8uqv9blm85ehm0msat385m76v_03d5f5f6, FALSE   },  /* [A_ESH_Action_ComMDisallow_RBTM_FL_BODY3_8uqv9blm85ehm0msat385m76v_03d5f5f6] */
  { /*     1 */ ComMConf_ComMChannel_RBTM_FL_BODY3_8uqv9blm85ehm0msat385m76v_03d5f5f6, TRUE    }   /* [A_ESH_Action_ComMAllow_RBTM_FL_BODY3_8uqv9blm85ehm0msat385m76v_03d5f5f6] */
};
#define BSWM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  BswM_ComMAllowComParametersRight
**********************************************************************************************************************/
/** 
  \var    BswM_ComMAllowComParametersRight
  \details
  Element    Description
  Channel
  Allowed
*/ 
#define BSWM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(BswM_ComMAllowComParametersType, BSWM_CONST) BswM_ComMAllowComParametersRight[2] = {  /* PRQA S 1514, 1533, 1504 */  /* MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ExternalMcData */
    /* Index    Channel                                                                Allowed        Referable Keys */
  { /*     0 */ ComMConf_ComMChannel_RBTM_FR_BODY3_4xwwtd59665s787n6ctawh7k8_23a94727, FALSE   },  /* [A_ESH_Action_ComMDisallow_RBTM_FR_BODY3_4xwwtd59665s787n6ctawh7k8_23a94727] */
  { /*     1 */ ComMConf_ComMChannel_RBTM_FR_BODY3_4xwwtd59665s787n6ctawh7k8_23a94727, TRUE    }   /* [A_ESH_Action_ComMAllow_RBTM_FR_BODY3_4xwwtd59665s787n6ctawh7k8_23a94727] */
};
#define BSWM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  BswM_ComMChannelMappingLeft
**********************************************************************************************************************/
/** 
  \var    BswM_ComMChannelMappingLeft
  \brief  Maps the external id of BswMComMIndication to an internal id and references immediate request ports.
  \details
  Element       Description
  ExternalId    External id of BswMComMIndication.
*/ 
#define BSWM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(BswM_ComMChannelMappingType, BSWM_CONST) BswM_ComMChannelMappingLeft[1] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    ExternalId                                                                   Referable Keys */
  { /*     0 */ ComMConf_ComMChannel_RBTM_FL_BODY3_8uqv9blm85ehm0msat385m76v_03d5f5f6 }   /* [COMM_CHANNEL_0, MRP_ESH_ComMIndication_RBTM_FL_BODY3_8uqv9blm85ehm0msat385m76v_03d5f5f6, MRP_ComMIndication_RBTM_FL_BODY3_8uqv9blm85ehm0msat385m76v_03d5f5f6] */
};
#define BSWM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  BswM_ComMChannelMappingRight
**********************************************************************************************************************/
/** 
  \var    BswM_ComMChannelMappingRight
  \brief  Maps the external id of BswMComMIndication to an internal id and references immediate request ports.
  \details
  Element       Description
  ExternalId    External id of BswMComMIndication.
*/ 
#define BSWM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(BswM_ComMChannelMappingType, BSWM_CONST) BswM_ComMChannelMappingRight[1] = {  /* PRQA S 1514, 1533, 1504 */  /* MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ExternalMcData */
    /* Index    ExternalId                                                                   Referable Keys */
  { /*     0 */ ComMConf_ComMChannel_RBTM_FR_BODY3_4xwwtd59665s787n6ctawh7k8_23a94727 }   /* [COMM_CHANNEL_0, MRP_ESH_ComMIndication_RBTM_FR_BODY3_4xwwtd59665s787n6ctawh7k8_23a94727, MRP_ComMIndication_RBTM_FR_BODY3_4xwwtd59665s787n6ctawh7k8_23a94727] */
};
#define BSWM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  BswM_ComMPncMapping
**********************************************************************************************************************/
/** 
  \var    BswM_ComMPncMapping
  \brief  Maps the external id of BswMComMPncRequest to an internal id and references immediate request ports.
  \details
  Element                  Description
  ExternalId               External id of BswMComMPncRequest.
  ImmediateUserEndIdx      the end index of the 0:n relation pointing to BswM_ImmediateUser
  ImmediateUserStartIdx    the start index of the 0:n relation pointing to BswM_ImmediateUser
*/ 
#define BSWM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(BswM_ComMPncMappingType, BSWM_CONST) BswM_ComMPncMapping[2] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    ExternalId                                ImmediateUserEndIdx  ImmediateUserStartIdx        Referable Keys */
  { /*     0 */ ComMConf_ComMPnc_PNC_00_MAPPING_b2c42696,                  3u,                    2u },  /* [COMM_PNC_0, MRP_CC_PNC_PNC_00_MAPPING_b2c42696] */
  { /*     1 */ ComMConf_ComMPnc_PNC_20_MAPPING_796df885,                  4u,                    3u }   /* [COMM_PNC_1, MRP_CC_PNC_PNC_20_MAPPING_796df885] */
};
#define BSWM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  BswM_ComPduGroupHandlingParameters
**********************************************************************************************************************/
/** 
  \var    BswM_ComPduGroupHandlingParameters
  \details
  Element                                       Description
  ComPduGroupHandlingStartParametersEndIdx      the end index of the 0:n relation pointing to BswM_ComPduGroupHandlingStartParameters
  ComPduGroupHandlingStartParametersStartIdx    the start index of the 0:n relation pointing to BswM_ComPduGroupHandlingStartParameters
  ComPduGroupHandlingStopParametersEndIdx       the end index of the 0:n relation pointing to BswM_ComPduGroupHandlingStopParameters
  ComPduGroupHandlingStopParametersStartIdx     the start index of the 0:n relation pointing to BswM_ComPduGroupHandlingStopParameters
*/ 
#define BSWM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(BswM_ComPduGroupHandlingParametersType, BSWM_CONST) BswM_ComPduGroupHandlingParameters[10] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    ComPduGroupHandlingStartParametersEndIdx                                         ComPduGroupHandlingStartParametersStartIdx                                         ComPduGroupHandlingStopParametersEndIdx                                         ComPduGroupHandlingStopParametersStartIdx                                               Referable Keys */
  { /*     0 */ BSWM_NO_COMPDUGROUPHANDLINGSTARTPARAMETERSENDIDXOFCOMPDUGROUPHANDLINGPARAMETERS, BSWM_NO_COMPDUGROUPHANDLINGSTARTPARAMETERSSTARTIDXOFCOMPDUGROUPHANDLINGPARAMETERS,                                                                             1u,                                                                               0u },  /* [A_CC_DisablePDUGroup_TxMess_RBTM_FL_BODY3_e804245a] */
  { /*     1 */                                                                              1u,                                                                                0u, BSWM_NO_COMPDUGROUPHANDLINGSTOPPARAMETERSENDIDXOFCOMPDUGROUPHANDLINGPARAMETERS, BSWM_NO_COMPDUGROUPHANDLINGSTOPPARAMETERSSTARTIDXOFCOMPDUGROUPHANDLINGPARAMETERS },  /* [A_CC_EnablePDUGroup_TxMess_RBTM_FL_BODY3_e804245a] */
  { /*     2 */ BSWM_NO_COMPDUGROUPHANDLINGSTARTPARAMETERSENDIDXOFCOMPDUGROUPHANDLINGPARAMETERS, BSWM_NO_COMPDUGROUPHANDLINGSTARTPARAMETERSSTARTIDXOFCOMPDUGROUPHANDLINGPARAMETERS,                                                                             2u,                                                                               1u },  /* [A_CC_DisablePDUGroup_RBTM_FL_BODY3_Rx_PNC_All_Active_46e8c3b2] */
  { /*     3 */                                                                              2u,                                                                                1u, BSWM_NO_COMPDUGROUPHANDLINGSTOPPARAMETERSENDIDXOFCOMPDUGROUPHANDLINGPARAMETERS, BSWM_NO_COMPDUGROUPHANDLINGSTOPPARAMETERSSTARTIDXOFCOMPDUGROUPHANDLINGPARAMETERS },  /* [A_CC_EnablePDUGroup_RBTM_FL_BODY3_Rx_PNC_All_Active_46e8c3b2] */
  { /*     4 */ BSWM_NO_COMPDUGROUPHANDLINGSTARTPARAMETERSENDIDXOFCOMPDUGROUPHANDLINGPARAMETERS, BSWM_NO_COMPDUGROUPHANDLINGSTARTPARAMETERSSTARTIDXOFCOMPDUGROUPHANDLINGPARAMETERS,                                                                             3u,                                                                               2u },  /* [A_CC_DisablePDUGroup_RBTM_FL_BODY3_Tx_PNC_All_Active_e1dc74ba] */
  { /*     5 */                                                                              3u,                                                                                2u, BSWM_NO_COMPDUGROUPHANDLINGSTOPPARAMETERSENDIDXOFCOMPDUGROUPHANDLINGPARAMETERS, BSWM_NO_COMPDUGROUPHANDLINGSTOPPARAMETERSSTARTIDXOFCOMPDUGROUPHANDLINGPARAMETERS },  /* [A_CC_EnablePDUGroup_RBTM_FL_BODY3_Tx_PNC_All_Active_e1dc74ba] */
  { /*     6 */ BSWM_NO_COMPDUGROUPHANDLINGSTARTPARAMETERSENDIDXOFCOMPDUGROUPHANDLINGPARAMETERS, BSWM_NO_COMPDUGROUPHANDLINGSTARTPARAMETERSSTARTIDXOFCOMPDUGROUPHANDLINGPARAMETERS,                                                                             4u,                                                                               3u },  /* [A_CC_DisablePDUGroup_RBTM_FL_BODY3_Tx_PNC_20_27dfe85c] */
  { /*     7 */                                                                              4u,                                                                                3u, BSWM_NO_COMPDUGROUPHANDLINGSTOPPARAMETERSENDIDXOFCOMPDUGROUPHANDLINGPARAMETERS, BSWM_NO_COMPDUGROUPHANDLINGSTOPPARAMETERSSTARTIDXOFCOMPDUGROUPHANDLINGPARAMETERS },  /* [A_CC_EnablePDUGroup_RBTM_FL_BODY3_Tx_PNC_20_27dfe85c] */
  { /*     8 */ BSWM_NO_COMPDUGROUPHANDLINGSTARTPARAMETERSENDIDXOFCOMPDUGROUPHANDLINGPARAMETERS, BSWM_NO_COMPDUGROUPHANDLINGSTARTPARAMETERSSTARTIDXOFCOMPDUGROUPHANDLINGPARAMETERS,                                                                             5u,                                                                               4u },  /* [A_CC_DisablePDUGroup_RBTM_FL_BODY3_Rx_PNC_20_54c591d6] */
  { /*     9 */                                                                              5u,                                                                                4u, BSWM_NO_COMPDUGROUPHANDLINGSTOPPARAMETERSENDIDXOFCOMPDUGROUPHANDLINGPARAMETERS, BSWM_NO_COMPDUGROUPHANDLINGSTOPPARAMETERSSTARTIDXOFCOMPDUGROUPHANDLINGPARAMETERS }   /* [A_CC_EnablePDUGroup_RBTM_FL_BODY3_Rx_PNC_20_54c591d6] */
};
#define BSWM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  BswM_ComPduGroupHandlingStartParametersLeft
**********************************************************************************************************************/
/** 
  \var    BswM_ComPduGroupHandlingStartParametersLeft
  \details
  Element        Description
  IpduGroupId
*/ 
#define BSWM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(BswM_ComPduGroupHandlingStartParametersType, BSWM_CONST) BswM_ComPduGroupHandlingStartParametersLeft[5] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    IpduGroupId                                                          Referable Keys */
  { /*     0 */ ComConf_ComIPduGroup_TxMess_RBTM_FL_BODY3_e804245a            },  /* [A_CC_EnablePDUGroup_TxMess_RBTM_FL_BODY3_e804245a] */
  { /*     1 */ ComConf_ComIPduGroup_RBTM_FL_BODY3_Rx_PNC_All_Active_46e8c3b2 },  /* [A_CC_EnablePDUGroup_RBTM_FL_BODY3_Rx_PNC_All_Active_46e8c3b2] */
  { /*     2 */ ComConf_ComIPduGroup_RBTM_FL_BODY3_Tx_PNC_All_Active_e1dc74ba },  /* [A_CC_EnablePDUGroup_RBTM_FL_BODY3_Tx_PNC_All_Active_e1dc74ba] */
  { /*     3 */ ComConf_ComIPduGroup_RBTM_FL_BODY3_Tx_PNC_20_27dfe85c         },  /* [A_CC_EnablePDUGroup_RBTM_FL_BODY3_Tx_PNC_20_27dfe85c] */
  { /*     4 */ ComConf_ComIPduGroup_RBTM_FL_BODY3_Rx_PNC_20_54c591d6         }   /* [A_CC_EnablePDUGroup_RBTM_FL_BODY3_Rx_PNC_20_54c591d6] */
};
#define BSWM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  BswM_ComPduGroupHandlingStartParametersRight
**********************************************************************************************************************/
/** 
  \var    BswM_ComPduGroupHandlingStartParametersRight
  \details
  Element        Description
  IpduGroupId
*/ 
#define BSWM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(BswM_ComPduGroupHandlingStartParametersType, BSWM_CONST) BswM_ComPduGroupHandlingStartParametersRight[5] = {  /* PRQA S 1514, 1533, 1504 */  /* MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ExternalMcData */
    /* Index    IpduGroupId                                                          Referable Keys */
  { /*     0 */ ComConf_ComIPduGroup_RBTM_FR_BODY3_Rx_PNC_All_Active_592f1bcd },  /* [A_CC_EnablePDUGroup_RBTM_FR_BODY3_Rx_PNC_All_Active_592f1bcd] */
  { /*     1 */ ComConf_ComIPduGroup_TxMess_RBTM_FR_BODY3_dfe5c3c9            },  /* [A_CC_EnablePDUGroup_TxMess_RBTM_FR_BODY3_dfe5c3c9] */
  { /*     2 */ ComConf_ComIPduGroup_RBTM_FR_BODY3_Tx_PNC_20_71aa89b7         },  /* [A_CC_EnablePDUGroup_RBTM_FR_BODY3_Tx_PNC_20_71aa89b7] */
  { /*     3 */ ComConf_ComIPduGroup_RBTM_FR_BODY3_Tx_PNC_All_Active_fe1bacc5 },  /* [A_CC_EnablePDUGroup_RBTM_FR_BODY3_Tx_PNC_All_Active_fe1bacc5] */
  { /*     4 */ ComConf_ComIPduGroup_RBTM_FR_BODY3_Rx_PNC_20_02b0f03d         }   /* [A_CC_EnablePDUGroup_RBTM_FR_BODY3_Rx_PNC_20_02b0f03d] */
};
#define BSWM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  BswM_ComPduGroupHandlingStopParametersLeft
**********************************************************************************************************************/
/** 
  \var    BswM_ComPduGroupHandlingStopParametersLeft
  \details
  Element        Description
  IpduGroupId
*/ 
#define BSWM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(BswM_ComPduGroupHandlingStopParametersType, BSWM_CONST) BswM_ComPduGroupHandlingStopParametersLeft[5] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    IpduGroupId                                                          Referable Keys */
  { /*     0 */ ComConf_ComIPduGroup_TxMess_RBTM_FL_BODY3_e804245a            },  /* [A_CC_DisablePDUGroup_TxMess_RBTM_FL_BODY3_e804245a] */
  { /*     1 */ ComConf_ComIPduGroup_RBTM_FL_BODY3_Rx_PNC_All_Active_46e8c3b2 },  /* [A_CC_DisablePDUGroup_RBTM_FL_BODY3_Rx_PNC_All_Active_46e8c3b2] */
  { /*     2 */ ComConf_ComIPduGroup_RBTM_FL_BODY3_Tx_PNC_All_Active_e1dc74ba },  /* [A_CC_DisablePDUGroup_RBTM_FL_BODY3_Tx_PNC_All_Active_e1dc74ba] */
  { /*     3 */ ComConf_ComIPduGroup_RBTM_FL_BODY3_Tx_PNC_20_27dfe85c         },  /* [A_CC_DisablePDUGroup_RBTM_FL_BODY3_Tx_PNC_20_27dfe85c] */
  { /*     4 */ ComConf_ComIPduGroup_RBTM_FL_BODY3_Rx_PNC_20_54c591d6         }   /* [A_CC_DisablePDUGroup_RBTM_FL_BODY3_Rx_PNC_20_54c591d6] */
};
#define BSWM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  BswM_ComPduGroupHandlingStopParametersRight
**********************************************************************************************************************/
/** 
  \var    BswM_ComPduGroupHandlingStopParametersRight
  \details
  Element        Description
  IpduGroupId
*/ 
#define BSWM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(BswM_ComPduGroupHandlingStopParametersType, BSWM_CONST) BswM_ComPduGroupHandlingStopParametersRight[5] = {  /* PRQA S 1514, 1533, 1504 */  /* MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ExternalMcData */
    /* Index    IpduGroupId                                                          Referable Keys */
  { /*     0 */ ComConf_ComIPduGroup_RBTM_FR_BODY3_Rx_PNC_All_Active_592f1bcd },  /* [A_CC_DisablePDUGroup_RBTM_FR_BODY3_Rx_PNC_All_Active_592f1bcd] */
  { /*     1 */ ComConf_ComIPduGroup_TxMess_RBTM_FR_BODY3_dfe5c3c9            },  /* [A_CC_DisablePDUGroup_TxMess_RBTM_FR_BODY3_dfe5c3c9] */
  { /*     2 */ ComConf_ComIPduGroup_RBTM_FR_BODY3_Tx_PNC_20_71aa89b7         },  /* [A_CC_DisablePDUGroup_RBTM_FR_BODY3_Tx_PNC_20_71aa89b7] */
  { /*     3 */ ComConf_ComIPduGroup_RBTM_FR_BODY3_Tx_PNC_All_Active_fe1bacc5 },  /* [A_CC_DisablePDUGroup_RBTM_FR_BODY3_Tx_PNC_All_Active_fe1bacc5] */
  { /*     4 */ ComConf_ComIPduGroup_RBTM_FR_BODY3_Rx_PNC_20_02b0f03d         }   /* [A_CC_DisablePDUGroup_RBTM_FR_BODY3_Rx_PNC_20_02b0f03d] */
};
#define BSWM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  BswM_DcmComMappingLeft
**********************************************************************************************************************/
/** 
  \var    BswM_DcmComMappingLeft
  \brief  Maps the external id of BswMDcmComModeRequest to an internal id and references immediate request ports.
  \details
  Element       Description
  ExternalId    External id of BswMDcmComModeRequest.
*/ 
#define BSWM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(BswM_DcmComMappingType, BSWM_CONST) BswM_DcmComMappingLeft[1] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    ExternalId                                                                   Referable Keys */
  { /*     0 */ ComMConf_ComMChannel_RBTM_FL_BODY3_8uqv9blm85ehm0msat385m76v_03d5f5f6 }   /* [DCM_COM_0, MRP_CC_DcmComIndication_RBTM_FL_BODY3_8uqv9blm85ehm0msat385m76v_03d5f5f6] */
};
#define BSWM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  BswM_DcmComMappingRight
**********************************************************************************************************************/
/** 
  \var    BswM_DcmComMappingRight
  \brief  Maps the external id of BswMDcmComModeRequest to an internal id and references immediate request ports.
  \details
  Element       Description
  ExternalId    External id of BswMDcmComModeRequest.
*/ 
#define BSWM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(BswM_DcmComMappingType, BSWM_CONST) BswM_DcmComMappingRight[1] = {  /* PRQA S 1514, 1533, 1504 */  /* MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ExternalMcData */
    /* Index    ExternalId                                                                   Referable Keys */
  { /*     0 */ ComMConf_ComMChannel_RBTM_FR_BODY3_4xwwtd59665s787n6ctawh7k8_23a94727 }   /* [DCM_COM_0, MRP_CC_DcmComIndication_RBTM_FR_BODY3_4xwwtd59665s787n6ctawh7k8_23a94727] */
};
#define BSWM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  BswM_DeferredRulesLeft
**********************************************************************************************************************/
/** 
  \var    BswM_DeferredRulesLeft
  \details
  Element     Description
  RulesIdx    the index of the 1:1 relation pointing to BswM_Rules
*/ 
#define BSWM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(BswM_DeferredRulesType, BSWM_CONST) BswM_DeferredRulesLeft[8] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    RulesIdx        Referable Keys */
  { /*     0 */       1u },  /* [R_ESH_RunToPostRun] */
  { /*     1 */       3u },  /* [R_ESH_WaitToShutdown] */
  { /*     2 */       4u },  /* [R_ESH_WakeupToPrep] */
  { /*     3 */       5u },  /* [R_ESH_WaitToWakeup] */
  { /*     4 */       6u },  /* [R_ESH_WakeupToRun] */
  { /*     5 */       8u },  /* [R_ESH_InitToWakeup] */
  { /*     6 */      11u },  /* [R_ESH_PostRun] */
  { /*     7 */      12u }   /* [R_ESH_PrepToWait] */
};
#define BSWM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  BswM_DeferredRulesRight
**********************************************************************************************************************/
/** 
  \var    BswM_DeferredRulesRight
  \details
  Element     Description
  RulesIdx    the index of the 1:1 relation pointing to BswM_Rules
*/ 
#define BSWM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(BswM_DeferredRulesType, BSWM_CONST) BswM_DeferredRulesRight[8] = {  /* PRQA S 1514, 1533, 1504 */  /* MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ExternalMcData */
    /* Index    RulesIdx        Referable Keys */
  { /*     0 */       0u },  /* [R_ESH_RunToPostRun] */
  { /*     1 */       2u },  /* [R_ESH_WaitToShutdown] */
  { /*     2 */       3u },  /* [R_ESH_WakeupToPrep] */
  { /*     3 */       4u },  /* [R_ESH_WaitToWakeup] */
  { /*     4 */       5u },  /* [R_ESH_WakeupToRun] */
  { /*     5 */       7u },  /* [R_ESH_InitToWakeup] */
  { /*     6 */      10u },  /* [R_ESH_PostRun] */
  { /*     7 */      11u }   /* [R_ESH_PrepToWait] */
};
#define BSWM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  BswM_EcuMRunRequestMapping
**********************************************************************************************************************/
/** 
  \var    BswM_EcuMRunRequestMapping
  \brief  Maps the external id of BswMEcuMRUNRequestIndication to an internal id and references immediate request ports.
  \details
  Element       Description
  ExternalId    External id of BswMEcuMRUNRequestIndication.
*/ 
#define BSWM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(BswM_EcuMRunRequestMappingType, BSWM_CONST) BswM_EcuMRunRequestMapping[2] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    ExternalId                     Referable Keys */
  { /*     0 */ ECUM_STATE_APP_POST_RUN },  /* [ECUM_RUNREQUEST_0, MRP_ESH_EcuMRequest_POSTRUN] */
  { /*     1 */ ECUM_STATE_APP_RUN      }   /* [ECUM_RUNREQUEST_1, MRP_ESH_EcuMRequest_RUN] */
};
#define BSWM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  BswM_EcuMStateSwitchParameters
**********************************************************************************************************************/
/** 
  \var    BswM_EcuMStateSwitchParameters
  \details
  Element        Description
  TargetState
*/ 
#define BSWM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(BswM_EcuMStateSwitchParametersType, BSWM_CONST) BswM_EcuMStateSwitchParameters[3] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    TargetState                    Referable Keys */
  { /*     0 */ ECUM_STATE_APP_POST_RUN },  /* [A_SwitchEcuMStateTo_POST_RUN] */
  { /*     1 */ ECUM_STATE_SHUTDOWN     },  /* [A_SwitchEcuMStateTo_SHUTDOWN] */
  { /*     2 */ ECUM_STATE_APP_RUN      }   /* [A_SwitchEcuMStateTo_RUN] */
};
#define BSWM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  BswM_ExpressionsLeft
**********************************************************************************************************************/
/** 
  \var    BswM_ExpressionsLeft
  \brief  Holds pointer to all expression functions.
*/ 
#define BSWM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(BswM_ExpressionFuncType, BSWM_CONST) BswM_ExpressionsLeft[35] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     Expressions                                                                                                        Referable Keys */
  /*     0 */ BswM_ExpFct_CC_LE_RBTM_FL_BODY3_8uqv9blm85ehm0msat385m76v_03d5f5f6_TX_Left                                    ,  /* [LE_CC_LE_RBTM_FL_BODY3_8uqv9blm85ehm0msat385m76v_03d5f5f6_TX] */
  /*     1 */ BswM_ExpFct_ESH_LE_RunToPostRunTransition_Left                                                                ,  /* [LE_ESH_LE_RunToPostRunTransition] */
  /*     2 */ BswM_ExpFct_ESH_LE_RunReached_Left                                                                            ,  /* [LE_ESH_LE_RunReached] */
  /*     3 */ BswM_ExpFct_ESH_LE_NoRunAndNoKillAllRequest_Left                                                              ,  /* [LE_ESH_LE_NoRunAndNoKillAllRequest] */
  /*     4 */ BswM_ExpFct_ESH_LE_NoRunReasons_Left                                                                          ,  /* [LE_ESH_LE_NoRunReasons] */
  /*     5 */ BswM_ExpFct_ESH_LE_AllChannelsNoCom_Left                                                                      ,  /* [LE_ESH_LE_AllChannelsNoCom] */
  /*     6 */ BswM_ExpFct_ESH_LE_RunReleased_Left                                                                           ,  /* [LE_ESH_LE_RunReleased] */
  /*     7 */ BswM_ExpFct_ESH_LE_ComMNoPendingRequests_Left                                                                 ,  /* [LE_ESH_LE_ComMNoPendingRequests] */
  /*     8 */ BswM_ExpFct_ESH_LE_WaitForNvMToShutdown_Left                                                                  ,  /* [LE_ESH_LE_WaitForNvMToShutdown] */
  /*     9 */ BswM_ExpFct_ESH_LE_NoWakeupOrKillAll_Left                                                                     ,  /* [LE_ESH_LE_NoWakeupOrKillAll] */
  /*    10 */ BswM_ExpFct_ESH_LE_NoWakeup_Left                                                                              ,  /* [LE_ESH_LE_NoWakeup] */
  /*    11 */ BswM_ExpFct_ESH_LE_WakeupToPrepShutdown_Left                                                                  ,  /* [LE_ESH_LE_WakeupToPrepShutdown] */
  /*    12 */ BswM_ExpFct_ESH_LE_WaitForNvMToWakeup_Left                                                                    ,  /* [LE_ESH_LE_WaitForNvMToWakeup] */
  /*    13 */ BswM_ExpFct_ESH_LE_ValidWakeup_Left                                                                           ,  /* [LE_ESH_LE_ValidWakeup] */
  /*    14 */ BswM_ExpFct_ESH_LE_WakeupToRun_Left                                                                           ,  /* [LE_ESH_LE_WakeupToRun] */
  /*    15 */ BswM_ExpFct_ESH_LE_DemNotInitialized_Left                                                                     ,  /* [LE_ESH_LE_DemNotInitialized] */
  /*    16 */ BswM_ExpFct_ESH_LE_InitToWakeup_Left                                                                          ,  /* [LE_ESH_LE_InitToWakeup] */
  /*    17 */ BswM_ExpFct_ESH_LE_Dem_PostRunRequested_Left                                                                  ,  /* [LE_ESH_LE_Dem_PostRunRequested] */
  /*    18 */ BswM_ExpFct_ESH_LE_PostRunToPrep_Left                                                                         ,  /* [LE_ESH_LE_PostRunToPrep] */
  /*    19 */ BswM_ExpFct_ESH_LE_PostRunReleased_Left                                                                       ,  /* [LE_ESH_LE_PostRunReleased] */
  /*    20 */ BswM_ExpFct_ESH_LE_PostRunToRun_Left                                                                          ,  /* [LE_ESH_LE_PostRunToRun] */
  /*    21 */ BswM_ExpFct_ESH_LE_RunRequestsOrWakeup_Left                                                                   ,  /* [LE_ESH_LE_RunRequestsOrWakeup] */
  /*    22 */ BswM_ExpFct_ESH_LE_RunRequested_Left                                                                          ,  /* [LE_ESH_LE_RunRequested] */
  /*    23 */ BswM_ExpFct_ESH_LE_PostRun_Left                                                                               ,  /* [LE_ESH_LE_PostRun] */
  /*    24 */ BswM_ExpFct_ESH_LE_PrepShutdownToWaitForNvM_Left                                                              ,  /* [LE_ESH_LE_PrepShutdownToWaitForNvM] */
  /*    25 */ BswM_ExpFct_ESH_LE_EcuMStateSleepOrShutdown_Left                                                              ,  /* [LE_ESH_LE_EcuMStateSleepOrShutdown] */
  /*    26 */ BswM_ExpFct_CC_LE_RBTM_FL_BODY3_8uqv9blm85ehm0msat385m76v_03d5f5f6_PNC_00_MAPPING_b2c42696_RX_Left            ,  /* [LE_CC_LE_RBTM_FL_BODY3_8uqv9blm85ehm0msat385m76v_03d5f5f6_PNC_00_MAPPING_b2c42696_RX] */
  /*    27 */ BswM_ExpFct_CC_LE_PNC_RBTM_FL_BODY3_8uqv9blm85ehm0msat385m76v_03d5f5f6_PNC_00_MAPPING_b2c42696_NEQ_NOCOM_Left ,  /* [LE_CC_LE_PNC_RBTM_FL_BODY3_8uqv9blm85ehm0msat385m76v_03d5f5f6_PNC_00_MAPPING_b2c42696_NEQ_NOCOM] */
  /*    28 */ BswM_ExpFct_CC_LE_RBTM_FL_BODY3_8uqv9blm85ehm0msat385m76v_03d5f5f6_PNC_00_MAPPING_b2c42696_RX_DM_Left         ,  /* [LE_CC_LE_RBTM_FL_BODY3_8uqv9blm85ehm0msat385m76v_03d5f5f6_PNC_00_MAPPING_b2c42696_RX_DM] */
  /*    29 */ BswM_ExpFct_CC_LE_RBTM_FL_BODY3_8uqv9blm85ehm0msat385m76v_03d5f5f6_PNC_00_MAPPING_b2c42696_TX_Left            ,  /* [LE_CC_LE_RBTM_FL_BODY3_8uqv9blm85ehm0msat385m76v_03d5f5f6_PNC_00_MAPPING_b2c42696_TX] */
  /*    30 */ BswM_ExpFct_CC_LE_RBTM_FL_BODY3_8uqv9blm85ehm0msat385m76v_03d5f5f6_PNC_20_MAPPING_796df885_RX_DM_Left         ,  /* [LE_CC_LE_RBTM_FL_BODY3_8uqv9blm85ehm0msat385m76v_03d5f5f6_PNC_20_MAPPING_796df885_RX_DM] */
  /*    31 */ BswM_ExpFct_CC_LE_PNC_RBTM_FL_BODY3_8uqv9blm85ehm0msat385m76v_03d5f5f6_PNC_20_MAPPING_796df885_NEQ_NOCOM_Left ,  /* [LE_CC_LE_PNC_RBTM_FL_BODY3_8uqv9blm85ehm0msat385m76v_03d5f5f6_PNC_20_MAPPING_796df885_NEQ_NOCOM] */
  /*    32 */ BswM_ExpFct_CC_LE_RBTM_FL_BODY3_8uqv9blm85ehm0msat385m76v_03d5f5f6_PNC_20_MAPPING_796df885_TX_Left            ,  /* [LE_CC_LE_RBTM_FL_BODY3_8uqv9blm85ehm0msat385m76v_03d5f5f6_PNC_20_MAPPING_796df885_TX] */
  /*    33 */ BswM_ExpFct_CC_LE_RBTM_FL_BODY3_8uqv9blm85ehm0msat385m76v_03d5f5f6_PNC_20_MAPPING_796df885_RX_Left            ,  /* [LE_CC_LE_RBTM_FL_BODY3_8uqv9blm85ehm0msat385m76v_03d5f5f6_PNC_20_MAPPING_796df885_RX] */
  /*    34 */ BswM_ExpFct_LE_BswMRule_SwcDiagComMState_Left                                                                    /* [LE_LE_BswMRule_SwcDiagComMState] */
};
#define BSWM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  BswM_ExpressionsRight
**********************************************************************************************************************/
/** 
  \var    BswM_ExpressionsRight
  \brief  Holds pointer to all expression functions.
*/ 
#define BSWM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(BswM_ExpressionFuncType, BSWM_CONST) BswM_ExpressionsRight[35] = {  /* PRQA S 1514, 1533, 1504 */  /* MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ExternalMcData */
  /* Index     Expressions                                                                                                        Referable Keys */
  /*     0 */ BswM_ExpFct_ESH_LE_RunToPostRunTransition_Right                                                               ,  /* [LE_ESH_LE_RunToPostRunTransition] */
  /*     1 */ BswM_ExpFct_ESH_LE_RunReached_Left                                                                            ,  /* [LE_ESH_LE_RunReached] */
  /*     2 */ BswM_ExpFct_ESH_LE_NoRunAndNoKillAllRequest_Right                                                             ,  /* [LE_ESH_LE_NoRunAndNoKillAllRequest] */
  /*     3 */ BswM_ExpFct_ESH_LE_NoRunReasons_Right                                                                         ,  /* [LE_ESH_LE_NoRunReasons] */
  /*     4 */ BswM_ExpFct_ESH_LE_AllChannelsNoCom_Left                                                                      ,  /* [LE_ESH_LE_AllChannelsNoCom] */
  /*     5 */ BswM_ExpFct_ESH_LE_RunReleased_Left                                                                           ,  /* [LE_ESH_LE_RunReleased] */
  /*     6 */ BswM_ExpFct_ESH_LE_ComMNoPendingRequests_Left                                                                 ,  /* [LE_ESH_LE_ComMNoPendingRequests] */
  /*     7 */ BswM_ExpFct_ESH_LE_WaitForNvMToShutdown_Right                                                                 ,  /* [LE_ESH_LE_WaitForNvMToShutdown] */
  /*     8 */ BswM_ExpFct_ESH_LE_NoWakeupOrKillAll_Right                                                                    ,  /* [LE_ESH_LE_NoWakeupOrKillAll] */
  /*     9 */ BswM_ExpFct_ESH_LE_NoWakeup_Left                                                                              ,  /* [LE_ESH_LE_NoWakeup] */
  /*    10 */ BswM_ExpFct_ESH_LE_WakeupToPrepShutdown_Right                                                                 ,  /* [LE_ESH_LE_WakeupToPrepShutdown] */
  /*    11 */ BswM_ExpFct_ESH_LE_WaitForNvMToWakeup_Right                                                                   ,  /* [LE_ESH_LE_WaitForNvMToWakeup] */
  /*    12 */ BswM_ExpFct_ESH_LE_ValidWakeup_Left                                                                           ,  /* [LE_ESH_LE_ValidWakeup] */
  /*    13 */ BswM_ExpFct_ESH_LE_WakeupToRun_Right                                                                          ,  /* [LE_ESH_LE_WakeupToRun] */
  /*    14 */ BswM_ExpFct_ESH_LE_DemNotInitialized_Left                                                                     ,  /* [LE_ESH_LE_DemNotInitialized] */
  /*    15 */ BswM_ExpFct_ESH_LE_InitToWakeup_Left                                                                          ,  /* [LE_ESH_LE_InitToWakeup] */
  /*    16 */ BswM_ExpFct_ESH_LE_Dem_PostRunRequested_Right                                                                 ,  /* [LE_ESH_LE_Dem_PostRunRequested] */
  /*    17 */ BswM_ExpFct_ESH_LE_PostRunToPrep_Right                                                                        ,  /* [LE_ESH_LE_PostRunToPrep] */
  /*    18 */ BswM_ExpFct_ESH_LE_PostRunReleased_Left                                                                       ,  /* [LE_ESH_LE_PostRunReleased] */
  /*    19 */ BswM_ExpFct_ESH_LE_PostRunToRun_Right                                                                         ,  /* [LE_ESH_LE_PostRunToRun] */
  /*    20 */ BswM_ExpFct_ESH_LE_RunRequestsOrWakeup_Right                                                                  ,  /* [LE_ESH_LE_RunRequestsOrWakeup] */
  /*    21 */ BswM_ExpFct_ESH_LE_RunRequested_Left                                                                          ,  /* [LE_ESH_LE_RunRequested] */
  /*    22 */ BswM_ExpFct_ESH_LE_PostRun_Left                                                                               ,  /* [LE_ESH_LE_PostRun] */
  /*    23 */ BswM_ExpFct_ESH_LE_PrepShutdownToWaitForNvM_Right                                                             ,  /* [LE_ESH_LE_PrepShutdownToWaitForNvM] */
  /*    24 */ BswM_ExpFct_ESH_LE_EcuMStateSleepOrShutdown_Left                                                              ,  /* [LE_ESH_LE_EcuMStateSleepOrShutdown] */
  /*    25 */ BswM_ExpFct_CC_LE_RBTM_FR_BODY3_4xwwtd59665s787n6ctawh7k8_23a94727_PNC_00_MAPPING_b2c42696_RX_DM_Right        ,  /* [LE_CC_LE_RBTM_FR_BODY3_4xwwtd59665s787n6ctawh7k8_23a94727_PNC_00_MAPPING_b2c42696_RX_DM] */
  /*    26 */ BswM_ExpFct_CC_LE_PNC_RBTM_FL_BODY3_8uqv9blm85ehm0msat385m76v_03d5f5f6_PNC_00_MAPPING_b2c42696_NEQ_NOCOM_Left ,  /* [LE_CC_LE_PNC_RBTM_FR_BODY3_4xwwtd59665s787n6ctawh7k8_23a94727_PNC_00_MAPPING_b2c42696_NEQ_NOCOM] */
  /*    27 */ BswM_ExpFct_CC_LE_RBTM_FR_BODY3_4xwwtd59665s787n6ctawh7k8_23a94727_PNC_00_MAPPING_b2c42696_RX_Right           ,  /* [LE_CC_LE_RBTM_FR_BODY3_4xwwtd59665s787n6ctawh7k8_23a94727_PNC_00_MAPPING_b2c42696_RX] */
  /*    28 */ BswM_ExpFct_CC_LE_RBTM_FL_BODY3_8uqv9blm85ehm0msat385m76v_03d5f5f6_TX_Left                                    ,  /* [LE_CC_LE_RBTM_FR_BODY3_4xwwtd59665s787n6ctawh7k8_23a94727_TX] */
  /*    29 */ BswM_ExpFct_CC_LE_RBTM_FR_BODY3_4xwwtd59665s787n6ctawh7k8_23a94727_PNC_20_MAPPING_796df885_TX_Right           ,  /* [LE_CC_LE_RBTM_FR_BODY3_4xwwtd59665s787n6ctawh7k8_23a94727_PNC_20_MAPPING_796df885_TX] */
  /*    30 */ BswM_ExpFct_CC_LE_PNC_RBTM_FL_BODY3_8uqv9blm85ehm0msat385m76v_03d5f5f6_PNC_20_MAPPING_796df885_NEQ_NOCOM_Left ,  /* [LE_CC_LE_PNC_RBTM_FR_BODY3_4xwwtd59665s787n6ctawh7k8_23a94727_PNC_20_MAPPING_796df885_NEQ_NOCOM] */
  /*    31 */ BswM_ExpFct_CC_LE_RBTM_FR_BODY3_4xwwtd59665s787n6ctawh7k8_23a94727_PNC_00_MAPPING_b2c42696_TX_Right           ,  /* [LE_CC_LE_RBTM_FR_BODY3_4xwwtd59665s787n6ctawh7k8_23a94727_PNC_00_MAPPING_b2c42696_TX] */
  /*    32 */ BswM_ExpFct_CC_LE_RBTM_FR_BODY3_4xwwtd59665s787n6ctawh7k8_23a94727_PNC_20_MAPPING_796df885_RX_DM_Right        ,  /* [LE_CC_LE_RBTM_FR_BODY3_4xwwtd59665s787n6ctawh7k8_23a94727_PNC_20_MAPPING_796df885_RX_DM] */
  /*    33 */ BswM_ExpFct_CC_LE_RBTM_FR_BODY3_4xwwtd59665s787n6ctawh7k8_23a94727_PNC_20_MAPPING_796df885_RX_Right           ,  /* [LE_CC_LE_RBTM_FR_BODY3_4xwwtd59665s787n6ctawh7k8_23a94727_PNC_20_MAPPING_796df885_RX] */
  /*    34 */ BswM_ExpFct_LE_BswMRule_SwcDiagComMState_Left                                                                    /* [LE_LE_BswMRule_SwcDiagComMState_001] */
};
#define BSWM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  BswM_GenericMapping
**********************************************************************************************************************/
/** 
  \var    BswM_GenericMapping
  \brief  Maps the external id of BswMGenericRequest to an internal id and references immediate request ports.
  \details
  Element                  Description
  ExternalId               External id of BswMGenericRequest.
  ImmediateUserEndIdx      the end index of the 0:n relation pointing to BswM_ImmediateUser
  ImmediateUserStartIdx    the start index of the 0:n relation pointing to BswM_ImmediateUser
  InitValue                Initialization value of port.
*/ 
#define BSWM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(BswM_GenericMappingType, BSWM_CONST) BswM_GenericMapping[4] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    ExternalId                            ImmediateUserEndIdx                          ImmediateUserStartIdx                          InitValue                                                            Referable Keys */
  { /*     0 */ BSWM_GENERIC_ESH_ComMPendingRequests, BSWM_NO_IMMEDIATEUSERENDIDXOFGENERICMAPPING, BSWM_NO_IMMEDIATEUSERSTARTIDXOFGENERICMAPPING, BSWM_GENERICVALUE_ESH_ComMPendingRequests_ESH_COMM_NO_REQUEST },  /* [GENERIC_0, MRP_ESH_ComMPendingRequests] */
  { /*     1 */ BSWM_GENERIC_ESH_DemInitStatus      ,                                          6u,                                            5u, BSWM_GENERICVALUE_ESH_DemInitStatus_DEM_INITIALIZED           },  /* [GENERIC_1, MRP_ESH_DemInitStatus] */
  { /*     2 */ BSWM_GENERIC_ESH_DemPostRunRequested, BSWM_NO_IMMEDIATEUSERENDIDXOFGENERICMAPPING, BSWM_NO_IMMEDIATEUSERSTARTIDXOFGENERICMAPPING, BSWM_GENERICVALUE_ESH_DemPostRunRequested_TRUE                },  /* [GENERIC_2, MRP_ESH_DemPostRunRequested] */
  { /*     3 */ BSWM_GENERIC_ESH_State              ,                                          7u,                                            6u, BSWM_GENERICVALUE_ESH_State_ESH_INIT                          }   /* [GENERIC_3, MRP_ESH_State] */
};
#define BSWM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  BswM_GenericModeParameters
**********************************************************************************************************************/
/** 
  \var    BswM_GenericModeParameters
  \details
  Element    Description
  Mode   
  User   
*/ 
#define BSWM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(BswM_GenericModeParametersType, BSWM_CONST) BswM_GenericModeParameters[7] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    Mode                                                     User                                  Referable Keys */
  { /*     0 */ BSWM_GENERICVALUE_ESH_State_ESH_POST_RUN               , BSWM_GENERIC_ESH_State         },  /* [A_ESH_Action_ESH_PostRun] */
  { /*     1 */ BSWM_GENERICVALUE_ESH_State_ESH_PREP_SHUTDOWN          , BSWM_GENERIC_ESH_State         },  /* [A_ESH_Action_ESH_PrepShutdown] */
  { /*     2 */ BSWM_GENERICVALUE_ESH_State_ESH_WAKEUP                 , BSWM_GENERIC_ESH_State         },  /* [A_ESH_Action_ESH_Wakeup] */
  { /*     3 */ BSWM_GENERICVALUE_ESH_DemInitStatus_DEM_INITIALIZED    , BSWM_GENERIC_ESH_DemInitStatus },  /* [A_ESH_Action_DemInitialized] */
  { /*     4 */ BSWM_GENERICVALUE_ESH_State_ESH_RUN                    , BSWM_GENERIC_ESH_State         },  /* [A_ESH_Action_ESH_Run] */
  { /*     5 */ BSWM_GENERICVALUE_ESH_DemInitStatus_DEM_NOT_INITIALIZED, BSWM_GENERIC_ESH_DemInitStatus },  /* [A_ESH_Action_DemNotInitialized] */
  { /*     6 */ BSWM_GENERICVALUE_ESH_State_ESH_WAIT_FOR_NVM           , BSWM_GENERIC_ESH_State         }   /* [A_ESH_Action_ESH_WaitForNvm] */
};
#define BSWM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  BswM_ImmediateUser
**********************************************************************************************************************/
/** 
  \var    BswM_ImmediateUser
  \brief  Contains all immediate request ports.
  \details
  Element             Description
  OnInit              Arbitrate depending rules on initialization.
  RulesIndEndIdx      the end index of the 0:n relation pointing to BswM_RulesInd
  RulesIndStartIdx    the start index of the 0:n relation pointing to BswM_RulesInd
*/ 
#define BSWM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(BswM_ImmediateUserType, BSWM_CONST) BswM_ImmediateUser[7] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    OnInit  RulesIndEndIdx                         RulesIndStartIdx                               Comment                                                                                  Referable Keys */
  { /*     0 */  FALSE,                                    7u,                                      0u },  /* [Name: CC_CanSMIndication_RBTM_FL_BODY3_8uqv9blm85ehm0msat385m76v_03d5f5f6]  */  /* [MRP_CC_CanSMIndication_RBTM_FL_BODY3_8uqv9blm85ehm0msat385m76v_03d5f5f6, CANSM_CHANNEL_0] */
  { /*     1 */  FALSE,                                    8u,                                      7u },  /* [Name: ComMIndication_RBTM_FL_BODY3_8uqv9blm85ehm0msat385m76v_03d5f5f6]      */  /* [MRP_ComMIndication_RBTM_FL_BODY3_8uqv9blm85ehm0msat385m76v_03d5f5f6, COMM_CHANNEL_0] */
  { /*     2 */  FALSE,                                   11u,                                      8u },  /* [Name: CC_PNC_PNC_00_MAPPING_b2c42696]                                       */  /* [MRP_CC_PNC_PNC_00_MAPPING_b2c42696, COMM_PNC_0] */
  { /*     3 */  FALSE,                                   14u,                                     11u },  /* [Name: CC_PNC_PNC_20_MAPPING_796df885]                                       */  /* [MRP_CC_PNC_PNC_20_MAPPING_796df885, COMM_PNC_1] */
  { /*     4 */  FALSE,                                   17u,                                     14u },  /* [Name: CC_DcmComIndication_RBTM_FL_BODY3_8uqv9blm85ehm0msat385m76v_03d5f5f6] */  /* [MRP_CC_DcmComIndication_RBTM_FL_BODY3_8uqv9blm85ehm0msat385m76v_03d5f5f6, DCM_COM_0] */
  { /*     5 */  FALSE, BSWM_NO_RULESINDENDIDXOFIMMEDIATEUSER, BSWM_NO_RULESINDSTARTIDXOFIMMEDIATEUSER },  /* [Name: ESH_DemInitStatus]                                                    */  /* [MRP_ESH_DemInitStatus, GENERIC_1] */
  { /*     6 */   TRUE,                                   25u,                                     17u }   /* [Name: ESH_State]                                                            */  /* [MRP_ESH_State, GENERIC_3] */
};
#define BSWM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  BswM_InitActionListsLeft
**********************************************************************************************************************/
/** 
  \var    BswM_InitActionListsLeft
  \brief  List of all action lists which shall be executed at end of Bswm_Init.
*/ 
#define BSWM_START_SEC_CONST_8
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(BswM_InitActionListsType, BSWM_CONST) BswM_InitActionListsLeft[1] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     InitActionLists  */
  /*     0 */              15u
};
#define BSWM_STOP_SEC_CONST_8
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  BswM_InitActionListsRight
**********************************************************************************************************************/
/** 
  \var    BswM_InitActionListsRight
  \brief  List of all action lists which shall be executed at end of Bswm_Init.
*/ 
#define BSWM_START_SEC_CONST_8
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(BswM_InitActionListsType, BSWM_CONST) BswM_InitActionListsRight[1] = {  /* PRQA S 1514, 1533, 1504 */  /* MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ExternalMcData */
  /* Index     InitActionLists  */
  /*     0 */              13u
};
#define BSWM_STOP_SEC_CONST_8
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  BswM_InitGenVarAndInitAL
**********************************************************************************************************************/
#define BSWM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(BswM_InitGenVarAndInitALType, BSWM_CONST) BswM_InitGenVarAndInitAL[1] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     InitGenVarAndInitAL                            */
  /*     0 */ BswM_InitGenVarAndInitAL_BSWM_SINGLEPARTITION 
};
#define BSWM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  BswM_InitValues
**********************************************************************************************************************/
/** 
  \var    BswM_InitValues
  \brief  Holds initialization values for generic modes.
*/ 
#define BSWM_START_SEC_CONST_16
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(BswM_InitValuesType, BSWM_CONST) BswM_InitValues[4] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     InitValues                                                         Referable Keys */
  /*     0 */ BSWM_GENERICVALUE_ESH_State_ESH_INIT                          ,  /* [MRP_ESH_State] */
  /*     1 */ BSWM_GENERICVALUE_ESH_ComMPendingRequests_ESH_COMM_NO_REQUEST ,  /* [MRP_ESH_ComMPendingRequests] */
  /*     2 */ BSWM_GENERICVALUE_ESH_DemInitStatus_DEM_INITIALIZED           ,  /* [MRP_ESH_DemInitStatus] */
  /*     3 */ BSWM_GENERICVALUE_ESH_DemPostRunRequested_TRUE                   /* [MRP_ESH_DemPostRunRequested] */
};
#define BSWM_STOP_SEC_CONST_16
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  BswM_ModeNotificationFct
**********************************************************************************************************************/
#define BSWM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(BswM_PartitionFunctionType, BSWM_CONST) BswM_ModeNotificationFct[1] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     ModeNotificationFct                            */
  /*     0 */ BswM_ModeNotificationFct_BSWM_SINGLEPARTITION 
};
#define BSWM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  BswM_PartitionIdentifiers
**********************************************************************************************************************/
/** 
  \var    BswM_PartitionIdentifiers
  \brief  the partition context in Config_Left
  \details
  Element                 Description
  PartitionSNV        
  PCPartitionConfigIdx    the index of the 1:1 relation pointing to BswM_PCPartitionConfig
*/ 
#define BSWM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(BswM_PartitionIdentifiersType, BSWM_CONST) BswM_PartitionIdentifiers[1] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    PartitionSNV          PCPartitionConfigIdx */
  { /*     0 */ BSWM_SINGLEPARTITION,                   0u }
};
#define BSWM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  BswM_RulesLeft
**********************************************************************************************************************/
/** 
  \var    BswM_RulesLeft
  \details
  Element                Description
  ActionListsFalseIdx    the index of the 0:1 relation pointing to BswM_ActionLists
  ActionListsTrueIdx     the index of the 0:1 relation pointing to BswM_ActionLists
  ExpressionsIdx         the index of the 1:1 relation pointing to BswM_Expressions
  Id                     External id of rule.
  RuleStatesIdx          the index of the 1:1 relation pointing to BswM_RuleStates
*/ 
#define BSWM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(BswM_RulesType, BSWM_CONST) BswM_RulesLeft[20] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    ActionListsFalseIdx                 ActionListsTrueIdx  ExpressionsIdx  Id   RuleStatesIdx        Referable Keys */
  { /*     0 */                                 0u,                 1u,             0u, 19u,            0u },  /* [R_CC_RBTM_FL_BODY3_8uqv9blm85ehm0msat385m76v_03d5f5f6_TX, MRP_CC_CanSMIndication_RBTM_FL_BODY3_8uqv9blm85ehm0msat385m76v_03d5f5f6, MRP_CC_DcmComIndication_RBTM_FL_BODY3_8uqv9blm85ehm0msat385m76v_03d5f5f6] */
  { /*     1 */ BSWM_NO_ACTIONLISTSFALSEIDXOFRULES,                 2u,             1u,  7u,            1u },  /* [R_ESH_RunToPostRun, MRP_ESH_State, MRP_ESH_ModeNotification, MRP_ESH_EcuMState, MRP_ESH_ComMIndication_RBTM_FL_BODY3_8uqv9blm85ehm0msat385m76v_03d5f5f6, MRP_ESH_RunRequest_0, MRP_ESH_RunRequest_1, MRP_ESH_EcuMRequest_RUN, MRP_ESH_SelfRunRequestTimer, MRP_ESH_KillAllRunRequest] */
  { /*     2 */ BSWM_NO_ACTIONLISTSFALSEIDXOFRULES,                 3u,             7u,  8u,            2u },  /* [R_ESH_RunToPostRunNested] */
  { /*     3 */ BSWM_NO_ACTIONLISTSFALSEIDXOFRULES,                 4u,             8u,  9u,            3u },  /* [R_ESH_WaitToShutdown, MRP_ESH_State, MRP_ESH_KillAllRunRequest, MRP_ESH_EcuM_GetValidatedWakeupEvents, MRP_ESH_ComMPendingRequests] */
  { /*     4 */ BSWM_NO_ACTIONLISTSFALSEIDXOFRULES,                 5u,            11u, 11u,            4u },  /* [R_ESH_WakeupToPrep, MRP_ESH_State, MRP_ESH_EcuM_GetPendingWakeupEvents, MRP_ESH_EcuM_GetValidatedWakeupEvents, MRP_ESH_ComMPendingRequests, MRP_ESH_ModeNotification] */
  { /*     5 */ BSWM_NO_ACTIONLISTSFALSEIDXOFRULES,                 6u,            12u, 10u,            5u },  /* [R_ESH_WaitToWakeup, MRP_ESH_State, MRP_ESH_EcuM_GetValidatedWakeupEvents, MRP_ESH_ComMPendingRequests, MRP_ESH_KillAllRunRequest] */
  { /*     6 */ BSWM_NO_ACTIONLISTSFALSEIDXOFRULES,                 7u,            14u, 12u,            6u },  /* [R_ESH_WakeupToRun, MRP_ESH_State, MRP_ESH_EcuM_GetValidatedWakeupEvents, MRP_ESH_ComMPendingRequests, MRP_ESH_ModeNotification] */
  { /*     7 */ BSWM_NO_ACTIONLISTSFALSEIDXOFRULES,                 8u,            15u,  1u,            7u },  /* [R_ESH_DemInit] */
  { /*     8 */ BSWM_NO_ACTIONLISTSFALSEIDXOFRULES,                 9u,            16u,  2u,            8u },  /* [R_ESH_InitToWakeup, MRP_ESH_State, MRP_ESH_EcuMState] */
  { /*     9 */ BSWM_NO_ACTIONLISTSFALSEIDXOFRULES,                10u,            17u,  5u,            9u },  /* [R_ESH_PostRunToPrepNested] */
  { /*    10 */                                11u,                12u,            20u,  4u,           10u },  /* [R_ESH_PostRunNested] */
  { /*    11 */ BSWM_NO_ACTIONLISTSFALSEIDXOFRULES,                13u,            23u,  3u,           11u },  /* [R_ESH_PostRun, MRP_ESH_State, MRP_ESH_ModeNotification, MRP_ESH_EcuMState] */
  { /*    12 */ BSWM_NO_ACTIONLISTSFALSEIDXOFRULES,                14u,            24u,  6u,           12u },  /* [R_ESH_PrepToWait, MRP_ESH_State, MRP_ESH_ModeNotification, MRP_ESH_EcuMState] */
  { /*    13 */                                16u,                17u,            26u, 13u,           13u },  /* [R_CC_RBTM_FL_BODY3_8uqv9blm85ehm0msat385m76v_03d5f5f6_PNC_00_MAPPING_b2c42696_RX, MRP_CC_PNC_PNC_00_MAPPING_b2c42696, MRP_CC_CanSMIndication_RBTM_FL_BODY3_8uqv9blm85ehm0msat385m76v_03d5f5f6] */
  { /*    14 */                                18u,                19u,            28u, 14u,           14u },  /* [R_CC_RBTM_FL_BODY3_8uqv9blm85ehm0msat385m76v_03d5f5f6_PNC_00_MAPPING_b2c42696_RX_DM, MRP_CC_PNC_PNC_00_MAPPING_b2c42696, MRP_CC_CanSMIndication_RBTM_FL_BODY3_8uqv9blm85ehm0msat385m76v_03d5f5f6] */
  { /*    15 */                                20u,                21u,            29u, 15u,           15u },  /* [R_CC_RBTM_FL_BODY3_8uqv9blm85ehm0msat385m76v_03d5f5f6_PNC_00_MAPPING_b2c42696_TX, MRP_CC_PNC_PNC_00_MAPPING_b2c42696, MRP_CC_CanSMIndication_RBTM_FL_BODY3_8uqv9blm85ehm0msat385m76v_03d5f5f6, MRP_CC_DcmComIndication_RBTM_FL_BODY3_8uqv9blm85ehm0msat385m76v_03d5f5f6] */
  { /*    16 */                                22u,                23u,            30u, 17u,           16u },  /* [R_CC_RBTM_FL_BODY3_8uqv9blm85ehm0msat385m76v_03d5f5f6_PNC_20_MAPPING_796df885_RX_DM, MRP_CC_PNC_PNC_20_MAPPING_796df885, MRP_CC_CanSMIndication_RBTM_FL_BODY3_8uqv9blm85ehm0msat385m76v_03d5f5f6] */
  { /*    17 */                                24u,                25u,            32u, 18u,           17u },  /* [R_CC_RBTM_FL_BODY3_8uqv9blm85ehm0msat385m76v_03d5f5f6_PNC_20_MAPPING_796df885_TX, MRP_CC_PNC_PNC_20_MAPPING_796df885, MRP_CC_CanSMIndication_RBTM_FL_BODY3_8uqv9blm85ehm0msat385m76v_03d5f5f6, MRP_CC_DcmComIndication_RBTM_FL_BODY3_8uqv9blm85ehm0msat385m76v_03d5f5f6] */
  { /*    18 */                                26u,                27u,            33u, 16u,           18u },  /* [R_CC_RBTM_FL_BODY3_8uqv9blm85ehm0msat385m76v_03d5f5f6_PNC_20_MAPPING_796df885_RX, MRP_CC_PNC_PNC_20_MAPPING_796df885, MRP_CC_CanSMIndication_RBTM_FL_BODY3_8uqv9blm85ehm0msat385m76v_03d5f5f6] */
  { /*    19 */                                29u,                28u,            34u,  0u,           19u }   /* [R_BswMRule_SwcDiagComMState, MRP_ComMIndication_RBTM_FL_BODY3_8uqv9blm85ehm0msat385m76v_03d5f5f6] */
};
#define BSWM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  BswM_RulesRight
**********************************************************************************************************************/
/** 
  \var    BswM_RulesRight
  \details
  Element                Description
  ActionListsFalseIdx    the index of the 0:1 relation pointing to BswM_ActionLists
  ActionListsTrueIdx     the index of the 0:1 relation pointing to BswM_ActionLists
  ExpressionsIdx         the index of the 1:1 relation pointing to BswM_Expressions
  Id                     External id of rule.
  RuleStatesIdx          the index of the 1:1 relation pointing to BswM_RuleStates
*/ 
#define BSWM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(BswM_RulesType, BSWM_CONST) BswM_RulesRight[20] = {  /* PRQA S 1514, 1533, 1504 */  /* MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ExternalMcData */
    /* Index    ActionListsFalseIdx                 ActionListsTrueIdx  ExpressionsIdx  Id   RuleStatesIdx        Referable Keys */
  { /*     0 */ BSWM_NO_ACTIONLISTSFALSEIDXOFRULES,                 0u,             0u,  7u,            0u },  /* [R_ESH_RunToPostRun, MRP_ESH_State, MRP_ESH_ModeNotification, MRP_ESH_EcuMState, MRP_ESH_ComMIndication_RBTM_FR_BODY3_4xwwtd59665s787n6ctawh7k8_23a94727, MRP_ESH_RunRequest_0, MRP_ESH_RunRequest_1, MRP_ESH_EcuMRequest_RUN, MRP_ESH_SelfRunRequestTimer, MRP_ESH_KillAllRunRequest] */
  { /*     1 */ BSWM_NO_ACTIONLISTSFALSEIDXOFRULES,                 1u,             6u,  8u,            1u },  /* [R_ESH_RunToPostRunNested] */
  { /*     2 */ BSWM_NO_ACTIONLISTSFALSEIDXOFRULES,                 2u,             7u,  9u,            2u },  /* [R_ESH_WaitToShutdown, MRP_ESH_State, MRP_ESH_KillAllRunRequest, MRP_ESH_EcuM_GetValidatedWakeupEvents, MRP_ESH_ComMPendingRequests] */
  { /*     3 */ BSWM_NO_ACTIONLISTSFALSEIDXOFRULES,                 3u,            10u, 11u,            3u },  /* [R_ESH_WakeupToPrep, MRP_ESH_State, MRP_ESH_EcuM_GetPendingWakeupEvents, MRP_ESH_EcuM_GetValidatedWakeupEvents, MRP_ESH_ComMPendingRequests, MRP_ESH_ModeNotification] */
  { /*     4 */ BSWM_NO_ACTIONLISTSFALSEIDXOFRULES,                 4u,            11u, 10u,            4u },  /* [R_ESH_WaitToWakeup, MRP_ESH_State, MRP_ESH_EcuM_GetValidatedWakeupEvents, MRP_ESH_ComMPendingRequests, MRP_ESH_KillAllRunRequest] */
  { /*     5 */ BSWM_NO_ACTIONLISTSFALSEIDXOFRULES,                 5u,            13u, 12u,            5u },  /* [R_ESH_WakeupToRun, MRP_ESH_State, MRP_ESH_EcuM_GetValidatedWakeupEvents, MRP_ESH_ComMPendingRequests, MRP_ESH_ModeNotification] */
  { /*     6 */ BSWM_NO_ACTIONLISTSFALSEIDXOFRULES,                 6u,            14u,  1u,            6u },  /* [R_ESH_DemInit] */
  { /*     7 */ BSWM_NO_ACTIONLISTSFALSEIDXOFRULES,                 7u,            15u,  2u,            7u },  /* [R_ESH_InitToWakeup, MRP_ESH_State, MRP_ESH_EcuMState] */
  { /*     8 */ BSWM_NO_ACTIONLISTSFALSEIDXOFRULES,                 8u,            16u,  5u,            8u },  /* [R_ESH_PostRunToPrepNested] */
  { /*     9 */                                 9u,                10u,            19u,  4u,            9u },  /* [R_ESH_PostRunNested] */
  { /*    10 */ BSWM_NO_ACTIONLISTSFALSEIDXOFRULES,                11u,            22u,  3u,           10u },  /* [R_ESH_PostRun, MRP_ESH_State, MRP_ESH_ModeNotification, MRP_ESH_EcuMState] */
  { /*    11 */ BSWM_NO_ACTIONLISTSFALSEIDXOFRULES,                12u,            23u,  6u,           11u },  /* [R_ESH_PrepToWait, MRP_ESH_State, MRP_ESH_ModeNotification, MRP_ESH_EcuMState] */
  { /*    12 */                                14u,                15u,            25u, 14u,           12u },  /* [R_CC_RBTM_FR_BODY3_4xwwtd59665s787n6ctawh7k8_23a94727_PNC_00_MAPPING_b2c42696_RX_DM, MRP_CC_PNC_PNC_00_MAPPING_b2c42696, MRP_CC_CanSMIndication_RBTM_FR_BODY3_4xwwtd59665s787n6ctawh7k8_23a94727] */
  { /*    13 */                                16u,                17u,            27u, 13u,           13u },  /* [R_CC_RBTM_FR_BODY3_4xwwtd59665s787n6ctawh7k8_23a94727_PNC_00_MAPPING_b2c42696_RX, MRP_CC_PNC_PNC_00_MAPPING_b2c42696, MRP_CC_CanSMIndication_RBTM_FR_BODY3_4xwwtd59665s787n6ctawh7k8_23a94727] */
  { /*    14 */                                18u,                19u,            28u, 19u,           14u },  /* [R_CC_RBTM_FR_BODY3_4xwwtd59665s787n6ctawh7k8_23a94727_TX, MRP_CC_CanSMIndication_RBTM_FR_BODY3_4xwwtd59665s787n6ctawh7k8_23a94727, MRP_CC_DcmComIndication_RBTM_FR_BODY3_4xwwtd59665s787n6ctawh7k8_23a94727] */
  { /*    15 */                                20u,                21u,            29u, 18u,           15u },  /* [R_CC_RBTM_FR_BODY3_4xwwtd59665s787n6ctawh7k8_23a94727_PNC_20_MAPPING_796df885_TX, MRP_CC_PNC_PNC_20_MAPPING_796df885, MRP_CC_CanSMIndication_RBTM_FR_BODY3_4xwwtd59665s787n6ctawh7k8_23a94727, MRP_CC_DcmComIndication_RBTM_FR_BODY3_4xwwtd59665s787n6ctawh7k8_23a94727] */
  { /*    16 */                                22u,                23u,            31u, 15u,           16u },  /* [R_CC_RBTM_FR_BODY3_4xwwtd59665s787n6ctawh7k8_23a94727_PNC_00_MAPPING_b2c42696_TX, MRP_CC_PNC_PNC_00_MAPPING_b2c42696, MRP_CC_CanSMIndication_RBTM_FR_BODY3_4xwwtd59665s787n6ctawh7k8_23a94727, MRP_CC_DcmComIndication_RBTM_FR_BODY3_4xwwtd59665s787n6ctawh7k8_23a94727] */
  { /*    17 */                                24u,                25u,            32u, 17u,           17u },  /* [R_CC_RBTM_FR_BODY3_4xwwtd59665s787n6ctawh7k8_23a94727_PNC_20_MAPPING_796df885_RX_DM, MRP_CC_PNC_PNC_20_MAPPING_796df885, MRP_CC_CanSMIndication_RBTM_FR_BODY3_4xwwtd59665s787n6ctawh7k8_23a94727] */
  { /*    18 */                                26u,                27u,            33u, 16u,           18u },  /* [R_CC_RBTM_FR_BODY3_4xwwtd59665s787n6ctawh7k8_23a94727_PNC_20_MAPPING_796df885_RX, MRP_CC_PNC_PNC_20_MAPPING_796df885, MRP_CC_CanSMIndication_RBTM_FR_BODY3_4xwwtd59665s787n6ctawh7k8_23a94727] */
  { /*    19 */                                29u,                28u,            34u,  0u,           19u }   /* [R_BswMRule_SwcDiagComMState, MRP_ComMIndication_RBTM_FR_BODY3_4xwwtd59665s787n6ctawh7k8_23a94727] */
};
#define BSWM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  BswM_RulesIndLeft
**********************************************************************************************************************/
/** 
  \var    BswM_RulesIndLeft
  \brief  the indexes of the 1:1 sorted relation pointing to BswM_Rules
*/ 
#define BSWM_START_SEC_CONST_8
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(BswM_RulesIndType, BSWM_CONST) BswM_RulesIndLeft[25] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     RulesInd      Referable Keys */
  /*     0 */        0u,  /* [MRP_CC_CanSMIndication_RBTM_FL_BODY3_8uqv9blm85ehm0msat385m76v_03d5f5f6] */
  /*     1 */       13u,  /* [MRP_CC_CanSMIndication_RBTM_FL_BODY3_8uqv9blm85ehm0msat385m76v_03d5f5f6] */
  /*     2 */       14u,  /* [MRP_CC_CanSMIndication_RBTM_FL_BODY3_8uqv9blm85ehm0msat385m76v_03d5f5f6] */
  /*     3 */       15u,  /* [MRP_CC_CanSMIndication_RBTM_FL_BODY3_8uqv9blm85ehm0msat385m76v_03d5f5f6] */
  /*     4 */       16u,  /* [MRP_CC_CanSMIndication_RBTM_FL_BODY3_8uqv9blm85ehm0msat385m76v_03d5f5f6] */
  /*     5 */       17u,  /* [MRP_CC_CanSMIndication_RBTM_FL_BODY3_8uqv9blm85ehm0msat385m76v_03d5f5f6] */
  /*     6 */       18u,  /* [MRP_CC_CanSMIndication_RBTM_FL_BODY3_8uqv9blm85ehm0msat385m76v_03d5f5f6] */
  /*     7 */       19u,  /* [MRP_ComMIndication_RBTM_FL_BODY3_8uqv9blm85ehm0msat385m76v_03d5f5f6] */
  /*     8 */       13u,  /* [MRP_CC_PNC_PNC_00_MAPPING_b2c42696] */
  /*     9 */       14u,  /* [MRP_CC_PNC_PNC_00_MAPPING_b2c42696] */
  /*    10 */       15u,  /* [MRP_CC_PNC_PNC_00_MAPPING_b2c42696] */
  /*    11 */       16u,  /* [MRP_CC_PNC_PNC_20_MAPPING_796df885] */
  /*    12 */       17u,  /* [MRP_CC_PNC_PNC_20_MAPPING_796df885] */
  /*    13 */       18u,  /* [MRP_CC_PNC_PNC_20_MAPPING_796df885] */
  /*    14 */        0u,  /* [MRP_CC_DcmComIndication_RBTM_FL_BODY3_8uqv9blm85ehm0msat385m76v_03d5f5f6] */
  /*    15 */       15u,  /* [MRP_CC_DcmComIndication_RBTM_FL_BODY3_8uqv9blm85ehm0msat385m76v_03d5f5f6] */
  /*    16 */       17u,  /* [MRP_CC_DcmComIndication_RBTM_FL_BODY3_8uqv9blm85ehm0msat385m76v_03d5f5f6] */
  /*    17 */        1u,  /* [MRP_ESH_State] */
  /*    18 */        3u,  /* [MRP_ESH_State] */
  /*    19 */        4u,  /* [MRP_ESH_State] */
  /*    20 */        5u,  /* [MRP_ESH_State] */
  /*    21 */        6u,  /* [MRP_ESH_State] */
  /*    22 */        8u,  /* [MRP_ESH_State] */
  /*    23 */       11u,  /* [MRP_ESH_State] */
  /*    24 */       12u   /* [MRP_ESH_State] */
};
#define BSWM_STOP_SEC_CONST_8
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  BswM_RulesIndRight
**********************************************************************************************************************/
/** 
  \var    BswM_RulesIndRight
  \brief  the indexes of the 1:1 sorted relation pointing to BswM_Rules
*/ 
#define BSWM_START_SEC_CONST_8
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(BswM_RulesIndType, BSWM_CONST) BswM_RulesIndRight[25] = {  /* PRQA S 1514, 1533, 1504 */  /* MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ExternalMcData */
  /* Index     RulesInd      Referable Keys */
  /*     0 */       12u,  /* [MRP_CC_CanSMIndication_RBTM_FR_BODY3_4xwwtd59665s787n6ctawh7k8_23a94727] */
  /*     1 */       13u,  /* [MRP_CC_CanSMIndication_RBTM_FR_BODY3_4xwwtd59665s787n6ctawh7k8_23a94727] */
  /*     2 */       14u,  /* [MRP_CC_CanSMIndication_RBTM_FR_BODY3_4xwwtd59665s787n6ctawh7k8_23a94727] */
  /*     3 */       15u,  /* [MRP_CC_CanSMIndication_RBTM_FR_BODY3_4xwwtd59665s787n6ctawh7k8_23a94727] */
  /*     4 */       16u,  /* [MRP_CC_CanSMIndication_RBTM_FR_BODY3_4xwwtd59665s787n6ctawh7k8_23a94727] */
  /*     5 */       17u,  /* [MRP_CC_CanSMIndication_RBTM_FR_BODY3_4xwwtd59665s787n6ctawh7k8_23a94727] */
  /*     6 */       18u,  /* [MRP_CC_CanSMIndication_RBTM_FR_BODY3_4xwwtd59665s787n6ctawh7k8_23a94727] */
  /*     7 */       19u,  /* [MRP_ComMIndication_RBTM_FR_BODY3_4xwwtd59665s787n6ctawh7k8_23a94727] */
  /*     8 */       12u,  /* [MRP_CC_PNC_PNC_00_MAPPING_b2c42696] */
  /*     9 */       13u,  /* [MRP_CC_PNC_PNC_00_MAPPING_b2c42696] */
  /*    10 */       16u,  /* [MRP_CC_PNC_PNC_00_MAPPING_b2c42696] */
  /*    11 */       15u,  /* [MRP_CC_PNC_PNC_20_MAPPING_796df885] */
  /*    12 */       17u,  /* [MRP_CC_PNC_PNC_20_MAPPING_796df885] */
  /*    13 */       18u,  /* [MRP_CC_PNC_PNC_20_MAPPING_796df885] */
  /*    14 */       14u,  /* [MRP_CC_DcmComIndication_RBTM_FR_BODY3_4xwwtd59665s787n6ctawh7k8_23a94727] */
  /*    15 */       15u,  /* [MRP_CC_DcmComIndication_RBTM_FR_BODY3_4xwwtd59665s787n6ctawh7k8_23a94727] */
  /*    16 */       16u,  /* [MRP_CC_DcmComIndication_RBTM_FR_BODY3_4xwwtd59665s787n6ctawh7k8_23a94727] */
  /*    17 */        0u,  /* [MRP_ESH_State] */
  /*    18 */        2u,  /* [MRP_ESH_State] */
  /*    19 */        3u,  /* [MRP_ESH_State] */
  /*    20 */        4u,  /* [MRP_ESH_State] */
  /*    21 */        5u,  /* [MRP_ESH_State] */
  /*    22 */        7u,  /* [MRP_ESH_State] */
  /*    23 */       10u,  /* [MRP_ESH_State] */
  /*    24 */       11u   /* [MRP_ESH_State] */
};
#define BSWM_STOP_SEC_CONST_8
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  BswM_SwcModeRequestUpdateFct
**********************************************************************************************************************/
#define BSWM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(BswM_PartitionFunctionType, BSWM_CONST) BswM_SwcModeRequestUpdateFct[1] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     SwcModeRequestUpdateFct                            */
  /*     0 */ BswM_SwcModeRequestUpdateFct_BSWM_SINGLEPARTITION 
};
#define BSWM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  BswM_TimerControlParametersLeft
**********************************************************************************************************************/
/** 
  \var    BswM_TimerControlParametersLeft
  \details
  Element    Description
  Timer  
*/ 
#define BSWM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(BswM_TimerControlParametersType, BSWM_CONST) BswM_TimerControlParametersLeft[1] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    Timer                                        Referable Keys */
  { /*     0 */ BSWM_TMR_ESH_SelfRunRequestTimer_Left }   /* [A_ESH_Action_SelfRunRequestTimer_Start] */
};
#define BSWM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  BswM_TimerControlParametersRight
**********************************************************************************************************************/
/** 
  \var    BswM_TimerControlParametersRight
  \details
  Element    Description
  Timer  
*/ 
#define BSWM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(BswM_TimerControlParametersType, BSWM_CONST) BswM_TimerControlParametersRight[1] = {  /* PRQA S 1514, 1533, 1504 */  /* MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ExternalMcData */
    /* Index    Timer                                         Referable Keys */
  { /*     0 */ BSWM_TMR_ESH_SelfRunRequestTimer_Right }   /* [A_ESH_Action_SelfRunRequestTimer_Start] */
};
#define BSWM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  BswM_ActionListQueue
**********************************************************************************************************************/
/** 
  \var    BswM_ActionListQueue
  \brief  Variable to store action lists which shall be executed.
*/ 
#define BSWM_START_SEC_VAR_NO_INIT_8
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(BswM_ActionListQueueUType, BSWM_VAR_NO_INIT) BswM_ActionListQueue;  /* PRQA S 0759, 1514, 1533 */  /* MD_CSL_Union, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys   Left */
  /*     0 */  /* [AL_CC_AL_RBTM_FL_BODY3_8uqv9blm85ehm0msat385m76v_03d5f5f6_TX_Disable] */
  /*     1 */  /* [AL_CC_AL_RBTM_FL_BODY3_8uqv9blm85ehm0msat385m76v_03d5f5f6_TX_EnableNoinit] */
  /*     2 */  /* [AL_ESH_AL_ExitRun] */
  /*     3 */  /* [AL_ESH_AL_RunToPostRun] */
  /*     4 */  /* [AL_ESH_AL_WaitForNvMToShutdown] */
  /*     5 */  /* [AL_ESH_AL_WakeupToPrep] */
  /*     6 */  /* [AL_ESH_AL_WaitForNvMWakeup] */
  /*     7 */  /* [AL_ESH_AL_WakeupToRun] */
  /*     8 */  /* [AL_ESH_AL_DemInit] */
  /*     9 */  /* [AL_ESH_AL_InitToWakeup] */
  /*    10 */  /* [AL_ESH_AL_PostRunToPrepShutdown] */
  /*    11 */  /* [AL_ESH_AL_ESH_PostRunToPrepCheck] */
  /*    12 */  /* [AL_ESH_AL_PostRunToRun] */
  /*    13 */  /* [AL_ESH_AL_ExitPostRun] */
  /*    14 */  /* [AL_ESH_AL_PrepShutdownToWaitForNvM] */
  /*    15 */  /* [AL_INIT_AL_Initialize] */
  /*    16 */  /* [AL_CC_AL_RBTM_FL_BODY3_8uqv9blm85ehm0msat385m76v_03d5f5f6_PNC_00_MAPPING_b2c42696_RX_Disable] */
  /*    17 */  /* [AL_CC_AL_RBTM_FL_BODY3_8uqv9blm85ehm0msat385m76v_03d5f5f6_PNC_00_MAPPING_b2c42696_RX_EnableNoinit] */
  /*    18 */  /* [AL_CC_AL_RBTM_FL_BODY3_8uqv9blm85ehm0msat385m76v_03d5f5f6_PNC_00_MAPPING_b2c42696_Disable_DM] */
  /*    19 */  /* [AL_CC_AL_RBTM_FL_BODY3_8uqv9blm85ehm0msat385m76v_03d5f5f6_PNC_00_MAPPING_b2c42696_Enable_DM] */
  /*    20 */  /* [AL_CC_AL_RBTM_FL_BODY3_8uqv9blm85ehm0msat385m76v_03d5f5f6_PNC_00_MAPPING_b2c42696_TX_Disable] */
  /*    21 */  /* [AL_CC_AL_RBTM_FL_BODY3_8uqv9blm85ehm0msat385m76v_03d5f5f6_PNC_00_MAPPING_b2c42696_TX_EnableNoinit] */
  /*    22 */  /* [AL_CC_AL_RBTM_FL_BODY3_8uqv9blm85ehm0msat385m76v_03d5f5f6_PNC_20_MAPPING_796df885_Disable_DM] */
  /*    23 */  /* [AL_CC_AL_RBTM_FL_BODY3_8uqv9blm85ehm0msat385m76v_03d5f5f6_PNC_20_MAPPING_796df885_Enable_DM] */
  /*    24 */  /* [AL_CC_AL_RBTM_FL_BODY3_8uqv9blm85ehm0msat385m76v_03d5f5f6_PNC_20_MAPPING_796df885_TX_Disable] */
  /*    25 */  /* [AL_CC_AL_RBTM_FL_BODY3_8uqv9blm85ehm0msat385m76v_03d5f5f6_PNC_20_MAPPING_796df885_TX_EnableNoinit] */
  /*    26 */  /* [AL_CC_AL_RBTM_FL_BODY3_8uqv9blm85ehm0msat385m76v_03d5f5f6_PNC_20_MAPPING_796df885_RX_Disable] */
  /*    27 */  /* [AL_CC_AL_RBTM_FL_BODY3_8uqv9blm85ehm0msat385m76v_03d5f5f6_PNC_20_MAPPING_796df885_RX_EnableNoinit] */
  /*    28 */  /* [AL_AL_SwcDiag_FullCom] */
  /*    29 */  /* [AL_AL_SwcDiag_NotFullCom] */
  /* Index        Referable Keys   Right */
  /*     0 */  /* [AL_ESH_AL_ExitRun] */
  /*     1 */  /* [AL_ESH_AL_RunToPostRun] */
  /*     2 */  /* [AL_ESH_AL_WaitForNvMToShutdown] */
  /*     3 */  /* [AL_ESH_AL_WakeupToPrep] */
  /*     4 */  /* [AL_ESH_AL_WaitForNvMWakeup] */
  /*     5 */  /* [AL_ESH_AL_WakeupToRun] */
  /*     6 */  /* [AL_ESH_AL_DemInit] */
  /*     7 */  /* [AL_ESH_AL_InitToWakeup] */
  /*     8 */  /* [AL_ESH_AL_PostRunToPrepShutdown] */
  /*     9 */  /* [AL_ESH_AL_ESH_PostRunToPrepCheck] */
  /*    10 */  /* [AL_ESH_AL_PostRunToRun] */
  /*    11 */  /* [AL_ESH_AL_ExitPostRun] */
  /*    12 */  /* [AL_ESH_AL_PrepShutdownToWaitForNvM] */
  /*    13 */  /* [AL_INIT_AL_Initialize] */
  /*    14 */  /* [AL_CC_AL_RBTM_FR_BODY3_4xwwtd59665s787n6ctawh7k8_23a94727_PNC_00_MAPPING_b2c42696_Disable_DM] */
  /*    15 */  /* [AL_CC_AL_RBTM_FR_BODY3_4xwwtd59665s787n6ctawh7k8_23a94727_PNC_00_MAPPING_b2c42696_Enable_DM] */
  /*    16 */  /* [AL_CC_AL_RBTM_FR_BODY3_4xwwtd59665s787n6ctawh7k8_23a94727_PNC_00_MAPPING_b2c42696_RX_Disable] */
  /*    17 */  /* [AL_CC_AL_RBTM_FR_BODY3_4xwwtd59665s787n6ctawh7k8_23a94727_PNC_00_MAPPING_b2c42696_RX_EnableNoinit] */
  /*    18 */  /* [AL_CC_AL_RBTM_FR_BODY3_4xwwtd59665s787n6ctawh7k8_23a94727_TX_Disable] */
  /*    19 */  /* [AL_CC_AL_RBTM_FR_BODY3_4xwwtd59665s787n6ctawh7k8_23a94727_TX_EnableNoinit] */
  /*    20 */  /* [AL_CC_AL_RBTM_FR_BODY3_4xwwtd59665s787n6ctawh7k8_23a94727_PNC_20_MAPPING_796df885_TX_Disable] */
  /*    21 */  /* [AL_CC_AL_RBTM_FR_BODY3_4xwwtd59665s787n6ctawh7k8_23a94727_PNC_20_MAPPING_796df885_TX_EnableNoinit] */
  /*    22 */  /* [AL_CC_AL_RBTM_FR_BODY3_4xwwtd59665s787n6ctawh7k8_23a94727_PNC_00_MAPPING_b2c42696_TX_Disable] */
  /*    23 */  /* [AL_CC_AL_RBTM_FR_BODY3_4xwwtd59665s787n6ctawh7k8_23a94727_PNC_00_MAPPING_b2c42696_TX_EnableNoinit] */
  /*    24 */  /* [AL_CC_AL_RBTM_FR_BODY3_4xwwtd59665s787n6ctawh7k8_23a94727_PNC_20_MAPPING_796df885_Disable_DM] */
  /*    25 */  /* [AL_CC_AL_RBTM_FR_BODY3_4xwwtd59665s787n6ctawh7k8_23a94727_PNC_20_MAPPING_796df885_Enable_DM] */
  /*    26 */  /* [AL_CC_AL_RBTM_FR_BODY3_4xwwtd59665s787n6ctawh7k8_23a94727_PNC_20_MAPPING_796df885_RX_Disable] */
  /*    27 */  /* [AL_CC_AL_RBTM_FR_BODY3_4xwwtd59665s787n6ctawh7k8_23a94727_PNC_20_MAPPING_796df885_RX_EnableNoinit] */
  /*    28 */  /* [AL_AL_SwcDiag_FullCom] */
  /*    29 */  /* [AL_AL_SwcDiag_NotFullCom] */

#define BSWM_STOP_SEC_VAR_NO_INIT_8
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  BswM_CanSMChannelState
**********************************************************************************************************************/
/** 
  \var    BswM_CanSMChannelState
  \brief  Variable to store current mode of BswMCanSMIndication mode request ports.
*/ 
#define BSWM_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(CanSM_BswMCurrentStateType, BSWM_VAR_NO_INIT) BswM_CanSMChannelState[1];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys   Left */
  /*     0 */  /* [CANSM_CHANNEL_0, MRP_CC_CanSMIndication_RBTM_FL_BODY3_8uqv9blm85ehm0msat385m76v_03d5f5f6] */
  /* Index        Referable Keys   Right */
  /*     0 */  /* [CANSM_CHANNEL_0, MRP_CC_CanSMIndication_RBTM_FR_BODY3_4xwwtd59665s787n6ctawh7k8_23a94727] */

#define BSWM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  BswM_ComMChannelState
**********************************************************************************************************************/
/** 
  \var    BswM_ComMChannelState
  \brief  Variable to store current mode of BswMComMIndication mode request ports.
*/ 
#define BSWM_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(ComM_ModeType, BSWM_VAR_NO_INIT) BswM_ComMChannelState[1];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys   Left */
  /*     0 */  /* [COMM_CHANNEL_0, MRP_ESH_ComMIndication_RBTM_FL_BODY3_8uqv9blm85ehm0msat385m76v_03d5f5f6, MRP_ComMIndication_RBTM_FL_BODY3_8uqv9blm85ehm0msat385m76v_03d5f5f6] */
  /* Index        Referable Keys   Right */
  /*     0 */  /* [COMM_CHANNEL_0, MRP_ESH_ComMIndication_RBTM_FR_BODY3_4xwwtd59665s787n6ctawh7k8_23a94727, MRP_ComMIndication_RBTM_FR_BODY3_4xwwtd59665s787n6ctawh7k8_23a94727] */

#define BSWM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  BswM_ComMPncState
**********************************************************************************************************************/
/** 
  \var    BswM_ComMPncState
  \brief  Variable to store current mode of BswMComMPncRequest mode request ports.
*/ 
#define BSWM_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(ComM_PncModeType, BSWM_VAR_NO_INIT) BswM_ComMPncState[2];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys   Left */
  /*     0 */  /* [COMM_PNC_0, MRP_CC_PNC_PNC_00_MAPPING_b2c42696] */
  /*     1 */  /* [COMM_PNC_1, MRP_CC_PNC_PNC_20_MAPPING_796df885] */
  /* Index        Referable Keys   Right */
  /*     0 */  /* [COMM_PNC_0, MRP_CC_PNC_PNC_00_MAPPING_b2c42696] */
  /*     1 */  /* [COMM_PNC_1, MRP_CC_PNC_PNC_20_MAPPING_796df885] */

#define BSWM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  BswM_DcmComState
**********************************************************************************************************************/
/** 
  \var    BswM_DcmComState
  \brief  Variable to store current mode of BswMDcmComModeRequest mode request ports.
*/ 
#define BSWM_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Dcm_CommunicationModeType, BSWM_VAR_NO_INIT) BswM_DcmComState[1];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys   Left */
  /*     0 */  /* [DCM_COM_0, MRP_CC_DcmComIndication_RBTM_FL_BODY3_8uqv9blm85ehm0msat385m76v_03d5f5f6] */
  /* Index        Referable Keys   Right */
  /*     0 */  /* [DCM_COM_0, MRP_CC_DcmComIndication_RBTM_FR_BODY3_4xwwtd59665s787n6ctawh7k8_23a94727] */

#define BSWM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  BswM_EcuMModeState
**********************************************************************************************************************/
/** 
  \var    BswM_EcuMModeState
  \brief  Variable to store the current mode of the BswMEcuMIndication mode request port.
*/ 
#define BSWM_START_SEC_VAR_NO_INIT_8
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(BswM_EcuMModeStateType, BSWM_VAR_NO_INIT) BswM_EcuMModeState;  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define BSWM_STOP_SEC_VAR_NO_INIT_8
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  BswM_EcuMRunRequestState
**********************************************************************************************************************/
/** 
  \var    BswM_EcuMRunRequestState
  \brief  Variable to store current mode of BswMEcuMRUNRequestIndication mode request ports.
*/ 
#define BSWM_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(EcuM_RunStatusType, BSWM_VAR_NO_INIT) BswM_EcuMRunRequestState[2];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys   Left */
  /*     0 */  /* [ECUM_RUNREQUEST_0, MRP_ESH_EcuMRequest_POSTRUN] */
  /*     1 */  /* [ECUM_RUNREQUEST_1, MRP_ESH_EcuMRequest_RUN] */
  /* Index        Referable Keys   Right */
  /*     0 */  /* [ECUM_RUNREQUEST_0, MRP_ESH_EcuMRequest_POSTRUN] */
  /*     1 */  /* [ECUM_RUNREQUEST_1, MRP_ESH_EcuMRequest_RUN] */

#define BSWM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  BswM_ForcedActionListPriority
**********************************************************************************************************************/
#define BSWM_START_SEC_VAR_NO_INIT_8
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(BswM_ForcedActionListPriorityType, BSWM_VAR_NO_INIT) BswM_ForcedActionListPriority;  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define BSWM_STOP_SEC_VAR_NO_INIT_8
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  BswM_GenericState
**********************************************************************************************************************/
/** 
  \var    BswM_GenericState
  \brief  Variable to store current mode of BswMGenericRequest mode request ports.
*/ 
#define BSWM_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(BswM_ModeType, BSWM_VAR_NO_INIT) BswM_GenericState[4];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys   Left */
  /*     0 */  /* [GENERIC_0, MRP_ESH_ComMPendingRequests] */
  /*     1 */  /* [GENERIC_1, MRP_ESH_DemInitStatus] */
  /*     2 */  /* [GENERIC_2, MRP_ESH_DemPostRunRequested] */
  /*     3 */  /* [GENERIC_3, MRP_ESH_State] */
  /* Index        Referable Keys   Right */
  /*     0 */  /* [GENERIC_0, MRP_ESH_ComMPendingRequests] */
  /*     1 */  /* [GENERIC_1, MRP_ESH_DemInitStatus] */
  /*     2 */  /* [GENERIC_2, MRP_ESH_DemPostRunRequested] */
  /*     3 */  /* [GENERIC_3, MRP_ESH_State] */

#define BSWM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  BswM_Initialized
**********************************************************************************************************************/
#define BSWM_START_SEC_VAR_NO_INIT_8
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(BswM_InitializedType, BSWM_VAR_NO_INIT) BswM_Initialized;  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define BSWM_STOP_SEC_VAR_NO_INIT_8
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  BswM_ModeRequestQueue
**********************************************************************************************************************/
/** 
  \var    BswM_ModeRequestQueue
  \brief  Variable to store an immediate mode request which must be queued because of a current active arbitration.
*/ 
#define BSWM_START_SEC_VAR_NO_INIT_8
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(BswM_ModeRequestQueueType, BSWM_VAR_NO_INIT) BswM_ModeRequestQueue[7];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys   Left */
  /*     0 */  /* [MRP_CC_CanSMIndication_RBTM_FL_BODY3_8uqv9blm85ehm0msat385m76v_03d5f5f6, CANSM_CHANNEL_0] */
  /*     1 */  /* [MRP_ComMIndication_RBTM_FL_BODY3_8uqv9blm85ehm0msat385m76v_03d5f5f6, COMM_CHANNEL_0] */
  /*     2 */  /* [MRP_CC_PNC_PNC_00_MAPPING_b2c42696, COMM_PNC_0] */
  /*     3 */  /* [MRP_CC_PNC_PNC_20_MAPPING_796df885, COMM_PNC_1] */
  /*     4 */  /* [MRP_CC_DcmComIndication_RBTM_FL_BODY3_8uqv9blm85ehm0msat385m76v_03d5f5f6, DCM_COM_0] */
  /*     5 */  /* [MRP_ESH_DemInitStatus, GENERIC_1] */
  /*     6 */  /* [MRP_ESH_State, GENERIC_3] */
  /* Index        Referable Keys   Right */
  /*     0 */  /* [MRP_CC_CanSMIndication_RBTM_FR_BODY3_4xwwtd59665s787n6ctawh7k8_23a94727, CANSM_CHANNEL_0] */
  /*     1 */  /* [MRP_ComMIndication_RBTM_FR_BODY3_4xwwtd59665s787n6ctawh7k8_23a94727, COMM_CHANNEL_0] */
  /*     2 */  /* [MRP_CC_PNC_PNC_00_MAPPING_b2c42696, COMM_PNC_0] */
  /*     3 */  /* [MRP_CC_PNC_PNC_20_MAPPING_796df885, COMM_PNC_1] */
  /*     4 */  /* [MRP_CC_DcmComIndication_RBTM_FR_BODY3_4xwwtd59665s787n6ctawh7k8_23a94727, DCM_COM_0] */
  /*     5 */  /* [MRP_ESH_DemInitStatus, GENERIC_1] */
  /*     6 */  /* [MRP_ESH_State, GENERIC_3] */

#define BSWM_STOP_SEC_VAR_NO_INIT_8
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  BswM_QueueSemaphore
**********************************************************************************************************************/
#define BSWM_START_SEC_VAR_NO_INIT_8
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(BswM_QueueSemaphoreType, BSWM_VAR_NO_INIT) BswM_QueueSemaphore;  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define BSWM_STOP_SEC_VAR_NO_INIT_8
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  BswM_QueueWritten
**********************************************************************************************************************/
#define BSWM_START_SEC_VAR_NO_INIT_8
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(BswM_QueueWrittenType, BSWM_VAR_NO_INIT) BswM_QueueWritten;  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define BSWM_STOP_SEC_VAR_NO_INIT_8
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  BswM_RuleStates
**********************************************************************************************************************/
/** 
  \var    BswM_RuleStates
  \brief  Stores the last execution state of the rule.
*/ 
#define BSWM_START_SEC_VAR_NO_INIT_8
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(BswM_RuleStatesUType, BSWM_VAR_NO_INIT) BswM_RuleStates;  /* PRQA S 0759, 1514, 1533 */  /* MD_CSL_Union, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys   Left */
  /*     0 */  /* [R_CC_RBTM_FL_BODY3_8uqv9blm85ehm0msat385m76v_03d5f5f6_TX] */
  /*     1 */  /* [R_ESH_RunToPostRun] */
  /*     2 */  /* [R_ESH_RunToPostRunNested] */
  /*     3 */  /* [R_ESH_WaitToShutdown] */
  /*     4 */  /* [R_ESH_WakeupToPrep] */
  /*     5 */  /* [R_ESH_WaitToWakeup] */
  /*     6 */  /* [R_ESH_WakeupToRun] */
  /*     7 */  /* [R_ESH_DemInit] */
  /*     8 */  /* [R_ESH_InitToWakeup] */
  /*     9 */  /* [R_ESH_PostRunToPrepNested] */
  /*    10 */  /* [R_ESH_PostRunNested] */
  /*    11 */  /* [R_ESH_PostRun] */
  /*    12 */  /* [R_ESH_PrepToWait] */
  /*    13 */  /* [R_CC_RBTM_FL_BODY3_8uqv9blm85ehm0msat385m76v_03d5f5f6_PNC_00_MAPPING_b2c42696_RX] */
  /*    14 */  /* [R_CC_RBTM_FL_BODY3_8uqv9blm85ehm0msat385m76v_03d5f5f6_PNC_00_MAPPING_b2c42696_RX_DM] */
  /*    15 */  /* [R_CC_RBTM_FL_BODY3_8uqv9blm85ehm0msat385m76v_03d5f5f6_PNC_00_MAPPING_b2c42696_TX] */
  /*    16 */  /* [R_CC_RBTM_FL_BODY3_8uqv9blm85ehm0msat385m76v_03d5f5f6_PNC_20_MAPPING_796df885_RX_DM] */
  /*    17 */  /* [R_CC_RBTM_FL_BODY3_8uqv9blm85ehm0msat385m76v_03d5f5f6_PNC_20_MAPPING_796df885_TX] */
  /*    18 */  /* [R_CC_RBTM_FL_BODY3_8uqv9blm85ehm0msat385m76v_03d5f5f6_PNC_20_MAPPING_796df885_RX] */
  /*    19 */  /* [R_BswMRule_SwcDiagComMState] */
  /* Index        Referable Keys   Right */
  /*     0 */  /* [R_ESH_RunToPostRun] */
  /*     1 */  /* [R_ESH_RunToPostRunNested] */
  /*     2 */  /* [R_ESH_WaitToShutdown] */
  /*     3 */  /* [R_ESH_WakeupToPrep] */
  /*     4 */  /* [R_ESH_WaitToWakeup] */
  /*     5 */  /* [R_ESH_WakeupToRun] */
  /*     6 */  /* [R_ESH_DemInit] */
  /*     7 */  /* [R_ESH_InitToWakeup] */
  /*     8 */  /* [R_ESH_PostRunToPrepNested] */
  /*     9 */  /* [R_ESH_PostRunNested] */
  /*    10 */  /* [R_ESH_PostRun] */
  /*    11 */  /* [R_ESH_PrepToWait] */
  /*    12 */  /* [R_CC_RBTM_FR_BODY3_4xwwtd59665s787n6ctawh7k8_23a94727_PNC_00_MAPPING_b2c42696_RX_DM] */
  /*    13 */  /* [R_CC_RBTM_FR_BODY3_4xwwtd59665s787n6ctawh7k8_23a94727_PNC_00_MAPPING_b2c42696_RX] */
  /*    14 */  /* [R_CC_RBTM_FR_BODY3_4xwwtd59665s787n6ctawh7k8_23a94727_TX] */
  /*    15 */  /* [R_CC_RBTM_FR_BODY3_4xwwtd59665s787n6ctawh7k8_23a94727_PNC_20_MAPPING_796df885_TX] */
  /*    16 */  /* [R_CC_RBTM_FR_BODY3_4xwwtd59665s787n6ctawh7k8_23a94727_PNC_00_MAPPING_b2c42696_TX] */
  /*    17 */  /* [R_CC_RBTM_FR_BODY3_4xwwtd59665s787n6ctawh7k8_23a94727_PNC_20_MAPPING_796df885_RX_DM] */
  /*    18 */  /* [R_CC_RBTM_FR_BODY3_4xwwtd59665s787n6ctawh7k8_23a94727_PNC_20_MAPPING_796df885_RX] */
  /*    19 */  /* [R_BswMRule_SwcDiagComMState] */

#define BSWM_STOP_SEC_VAR_NO_INIT_8
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  BswM_TimerState
**********************************************************************************************************************/
/** 
  \var    BswM_TimerState
  \brief  Variable to store current state of BswMTimer (STARTED, STOPPER OR EXPIRED).
*/ 
#define BSWM_START_SEC_VAR_NO_INIT_8
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(BswM_TimerStateUType, BSWM_VAR_NO_INIT) BswM_TimerState;  /* PRQA S 0759, 1514, 1533 */  /* MD_CSL_Union, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys   Left */
  /*     0 */  /* [MRP_ESH_SelfRunRequestTimer] */
  /* Index        Referable Keys   Right */
  /*     0 */  /* [MRP_ESH_SelfRunRequestTimer] */

#define BSWM_STOP_SEC_VAR_NO_INIT_8
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  BswM_TimerValue
**********************************************************************************************************************/
/** 
  \var    BswM_TimerValue
  \brief  Variable to store current timer values.
*/ 
#define BSWM_START_SEC_VAR_NO_INIT_32
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(BswM_TimerValueUType, BSWM_VAR_NO_INIT) BswM_TimerValue;  /* PRQA S 0759, 1514, 1533 */  /* MD_CSL_Union, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys   Left */
  /*     0 */  /* [MRP_ESH_SelfRunRequestTimer] */
  /* Index        Referable Keys   Right */
  /*     0 */  /* [MRP_ESH_SelfRunRequestTimer] */

#define BSWM_STOP_SEC_VAR_NO_INIT_32
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  BswM_PCConfig
**********************************************************************************************************************/
/** 
  \var    BswM_PCConfig
  \details
  Element              Description
  PCPartitionConfig    the pointer to BswM_PCPartitionConfig
*/ 
#define BSWM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(BswM_PCConfigsType, BSWM_CONST) BswM_PCConfig = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  { /* Index: 0 Keys: [Config_Left] */
      BswM_PCPartitionConfigLeft   /**< the pointer to BswM_PCPartitionConfig in Config_Left */
  },
  { /* Index: 1 Keys: [Config_Right] */
      BswM_PCPartitionConfigRight  /**< the pointer to BswM_PCPartitionConfig in Config_Right */
  }
};
#define BSWM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  BswM_PCPartitionConfigLeft
**********************************************************************************************************************/
/** 
  \var    BswM_PCPartitionConfigLeft
  \details
  Element                               Description
  ActionItems                           the pointer to BswM_ActionItems
  ActionLists                           the pointer to BswM_ActionLists
  Actions                               the pointer to BswM_Actions
  CanSMChannelMapping                   the pointer to BswM_CanSMChannelMapping
  ComDMHandlingDisableParameters        the pointer to BswM_ComDMHandlingDisableParameters
  ComDMHandlingEnableParameters         the pointer to BswM_ComDMHandlingEnableParameters
  ComMAllowComParameters                the pointer to BswM_ComMAllowComParameters
  ComMChannelMapping                    the pointer to BswM_ComMChannelMapping
  ComPduGroupHandlingStartParameters    the pointer to BswM_ComPduGroupHandlingStartParameters
  ComPduGroupHandlingStopParameters     the pointer to BswM_ComPduGroupHandlingStopParameters
  DcmComMapping                         the pointer to BswM_DcmComMapping
  DeferredRules                         the pointer to BswM_DeferredRules
  Expressions                           the pointer to BswM_Expressions
  InitActionLists                       the pointer to BswM_InitActionLists
  Rules                                 the pointer to BswM_Rules
  RulesInd                              the pointer to BswM_RulesInd
  TimerControlParameters                the pointer to BswM_TimerControlParameters
*/ 
#define BSWM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(BswM_PCPartitionConfigType, BSWM_CONST) BswM_PCPartitionConfigLeft[1] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  { /* Index: 0 Keys: [BSWM_SINGLEPARTITION] */
      BswM_ActionItemsLeft                         /**< the pointer to BswM_ActionItems in Config_Left */
    , BswM_ActionListsLeft                         /**< the pointer to BswM_ActionLists in Config_Left */
    , BswM_ActionsLeft                             /**< the pointer to BswM_Actions in Config_Left */
    , BswM_CanSMChannelMappingLeft                 /**< the pointer to BswM_CanSMChannelMapping in Config_Left */
    , BswM_ComDMHandlingDisableParametersLeft      /**< the pointer to BswM_ComDMHandlingDisableParameters in Config_Left */
    , BswM_ComDMHandlingEnableParametersLeft       /**< the pointer to BswM_ComDMHandlingEnableParameters in Config_Left */
    , BswM_ComMAllowComParametersLeft              /**< the pointer to BswM_ComMAllowComParameters in Config_Left */
    , BswM_ComMChannelMappingLeft                  /**< the pointer to BswM_ComMChannelMapping in Config_Left */
    , BswM_ComPduGroupHandlingStartParametersLeft  /**< the pointer to BswM_ComPduGroupHandlingStartParameters in Config_Left */
    , BswM_ComPduGroupHandlingStopParametersLeft   /**< the pointer to BswM_ComPduGroupHandlingStopParameters in Config_Left */
    , BswM_DcmComMappingLeft                       /**< the pointer to BswM_DcmComMapping in Config_Left */
    , BswM_DeferredRulesLeft                       /**< the pointer to BswM_DeferredRules in Config_Left */
    , BswM_ExpressionsLeft                         /**< the pointer to BswM_Expressions in Config_Left */
    , BswM_InitActionListsLeft                     /**< the pointer to BswM_InitActionLists in Config_Left */
    , BswM_RulesLeft                               /**< the pointer to BswM_Rules in Config_Left */
    , BswM_RulesIndLeft                            /**< the pointer to BswM_RulesInd in Config_Left */
    , BswM_TimerControlParametersLeft              /**< the pointer to BswM_TimerControlParameters in Config_Left */
  }
};
#define BSWM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  BswM_PCPartitionConfigRight
**********************************************************************************************************************/
/** 
  \var    BswM_PCPartitionConfigRight
  \details
  Element                               Description
  ActionItems                           the pointer to BswM_ActionItems
  ActionLists                           the pointer to BswM_ActionLists
  Actions                               the pointer to BswM_Actions
  CanSMChannelMapping                   the pointer to BswM_CanSMChannelMapping
  ComDMHandlingDisableParameters        the pointer to BswM_ComDMHandlingDisableParameters
  ComDMHandlingEnableParameters         the pointer to BswM_ComDMHandlingEnableParameters
  ComMAllowComParameters                the pointer to BswM_ComMAllowComParameters
  ComMChannelMapping                    the pointer to BswM_ComMChannelMapping
  ComPduGroupHandlingStartParameters    the pointer to BswM_ComPduGroupHandlingStartParameters
  ComPduGroupHandlingStopParameters     the pointer to BswM_ComPduGroupHandlingStopParameters
  DcmComMapping                         the pointer to BswM_DcmComMapping
  DeferredRules                         the pointer to BswM_DeferredRules
  Expressions                           the pointer to BswM_Expressions
  InitActionLists                       the pointer to BswM_InitActionLists
  Rules                                 the pointer to BswM_Rules
  RulesInd                              the pointer to BswM_RulesInd
  TimerControlParameters                the pointer to BswM_TimerControlParameters
*/ 
#define BSWM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(BswM_PCPartitionConfigType, BSWM_CONST) BswM_PCPartitionConfigRight[1] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  { /* Index: 0 Keys: [BSWM_SINGLEPARTITION] */
      BswM_ActionItemsRight                         /**< the pointer to BswM_ActionItems in Config_Right */
    , BswM_ActionListsRight                         /**< the pointer to BswM_ActionLists in Config_Right */
    , BswM_ActionsRight                             /**< the pointer to BswM_Actions in Config_Right */
    , BswM_CanSMChannelMappingRight                 /**< the pointer to BswM_CanSMChannelMapping in Config_Right */
    , BswM_ComDMHandlingDisableParametersRight      /**< the pointer to BswM_ComDMHandlingDisableParameters in Config_Right */
    , BswM_ComDMHandlingEnableParametersRight       /**< the pointer to BswM_ComDMHandlingEnableParameters in Config_Right */
    , BswM_ComMAllowComParametersRight              /**< the pointer to BswM_ComMAllowComParameters in Config_Right */
    , BswM_ComMChannelMappingRight                  /**< the pointer to BswM_ComMChannelMapping in Config_Right */
    , BswM_ComPduGroupHandlingStartParametersRight  /**< the pointer to BswM_ComPduGroupHandlingStartParameters in Config_Right */
    , BswM_ComPduGroupHandlingStopParametersRight   /**< the pointer to BswM_ComPduGroupHandlingStopParameters in Config_Right */
    , BswM_DcmComMappingRight                       /**< the pointer to BswM_DcmComMapping in Config_Right */
    , BswM_DeferredRulesRight                       /**< the pointer to BswM_DeferredRules in Config_Right */
    , BswM_ExpressionsRight                         /**< the pointer to BswM_Expressions in Config_Right */
    , BswM_InitActionListsRight                     /**< the pointer to BswM_InitActionLists in Config_Right */
    , BswM_RulesRight                               /**< the pointer to BswM_Rules in Config_Right */
    , BswM_RulesIndRight                            /**< the pointer to BswM_RulesInd in Config_Right */
    , BswM_TimerControlParametersRight              /**< the pointer to BswM_TimerControlParameters in Config_Right */
  }
};
#define BSWM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */


/* PRQA L:GLOBALDATADECLARATIONS */

#define BSWM_START_SEC_VAR_NO_INIT_UNSPECIFIED
/* PRQA S 5087 1 */ /* MD_MSR_MemMap */
#include "BswM_MemMap.h"

VAR(Rte_ModeType_ESH_Mode, BSWM_VAR_NO_INIT) BswM_Switch_ESH_ModeSwitch_BswM_MDGP_ESH_Mode;
VAR(Rte_ModeType_CommunicationMode, BSWM_VAR_NO_INIT) BswM_Switch_BswMSwitchPort_SwcDiagCommunicationMode_Mode;

VAR(BswM_ESH_RunRequest, BSWM_VAR_NO_INIT) Request_ESH_RunRequest_0_requestedMode;
VAR(BswM_ESH_RunRequest, BSWM_VAR_NO_INIT) Request_ESH_RunRequest_1_requestedMode;
VAR(BswM_ESH_RunRequest, BSWM_VAR_NO_INIT) Request_ESH_PostRunRequest_0_requestedMode;
VAR(BswM_ESH_RunRequest, BSWM_VAR_NO_INIT) Request_ESH_PostRunRequest_1_requestedMode;
VAR(BswM_ESH_KillAllRun, BSWM_VAR_NO_INIT) Request_ESH_KillAllRunRequest_requestedMode;
VAR(Rte_ModeType_ESH_Mode, BSWM_VAR_NO_INIT) BswM_Mode_Notification_ESH_ModeNotification_BswM_MDGP_ESH_Mode;


VAR(boolean, BSWM_VAR_NO_INIT) BswM_PreInitialized;
#define BSWM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/* PRQA S 5087 1 */ /* MD_MSR_MemMap */
#include "BswM_MemMap.h"


#define BSWM_START_SEC_CODE
/* PRQA S 5087 1 */ /* MD_MSR_MemMap */
#include "BswM_MemMap.h"

/* -----------------------------------------------------------------------------
    &&&~ FUNCTIONS
 ----------------------------------------------------------------------------- */


/**********************************************************************************************************************
 *  BswM_Action_RuleHandler()
 **********************************************************************************************************************/
BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_RuleHandler(BswM_HandleType handleId, BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BswM_HandleType actionListIndex;
  Std_ReturnType retVal = E_NOT_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

#if ( BSWM_DEV_ERROR_DETECT == STD_ON )
  if (handleId < BswM_GetSizeOfRules(partitionIdx))
#endif
  {
    SchM_Enter_BswM_BSWM_EXCLUSIVE_AREA_0(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    actionListIndex = BswM_ArbitrateRule(handleId, partitionIdx);
    SchM_Exit_BswM_BSWM_EXCLUSIVE_AREA_0(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    if(actionListIndex < BswM_GetSizeOfActionLists(partitionIdx))
    {
      retVal = BswM_Action_ActionListHandler(actionListIndex, partitionIdx);
    }
    else
    {
      retVal = E_OK;
    }
  }
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */

  return retVal;
}


/**********************************************************************************************************************
 *  BswM_UpdateTimer()
 **********************************************************************************************************************/
BSWM_LOCAL_INLINE FUNC(void, BSWM_CODE) BswM_UpdateTimer(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx,
                                                              BswM_SizeOfTimerValueType timerId,
                                                              BswM_TimerValueType value)
{
  if (timerId < BswM_GetSizeOfTimerValue(partitionIdx))
  {
      SchM_Enter_BswM_BSWM_EXCLUSIVE_AREA_0(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
      BswM_SetTimerValue(timerId, value, partitionIdx); /* SBSW_BSWM_SETTIMER */
      BswM_SetTimerState(timerId, (BswM_TimerStateType)((value != 0u) ? BSWM_TIMER_STARTED : BSWM_TIMER_STOPPED), partitionIdx); /* SBSW_BSWM_SETTIMER */
      SchM_Exit_BswM_BSWM_EXCLUSIVE_AREA_0(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  }
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
}

/**********************************************************************************************************************
 *  BswM_InitGenVarAndInitAL_BSWM_SINGLEPARTITION
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(void, BSWM_CODE) BswM_InitGenVarAndInitAL_BSWM_SINGLEPARTITION(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  uint16 uIndex;

  BswM_Switch_ESH_ModeSwitch_BswM_MDGP_ESH_Mode = 0xFFu;
  BswM_Switch_BswMSwitchPort_SwcDiagCommunicationMode_Mode = 0xFFu;
  Request_ESH_RunRequest_0_requestedMode = RELEASED;
  Request_ESH_RunRequest_1_requestedMode = RELEASED;
  Request_ESH_PostRunRequest_0_requestedMode = RELEASED;
  Request_ESH_PostRunRequest_1_requestedMode = RELEASED;
  Request_ESH_KillAllRunRequest_requestedMode = RELEASED;
  BswM_Mode_Notification_ESH_ModeNotification_BswM_MDGP_ESH_Mode = RTE_MODE_ESH_Mode_STARTUP;

  for(uIndex = 0u; uIndex < BswM_GetSizeOfInitActionLists(partitionIdx); uIndex++) /* COV_BSWM_INITACTIONLISTS XF */ 
  {
    (void)BswM_Action_ActionListHandler((BswM_HandleType)BswM_GetInitActionLists(uIndex, partitionIdx), partitionIdx);
  }
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
}

/**********************************************************************************************************************
 *  BswM_ModeNotificationFct_BSWM_SINGLEPARTITION
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(void, BSWM_CODE) BswM_ModeNotificationFct_BSWM_SINGLEPARTITION(void)
{
  if(BswM_Switch_ESH_ModeSwitch_BswM_MDGP_ESH_Mode != 0xFFu)
  {
    if(Rte_Switch_Switch_ESH_ModeSwitch_BswM_MDGP_ESH_Mode(BswM_Switch_ESH_ModeSwitch_BswM_MDGP_ESH_Mode) == RTE_E_OK)
    {
      BswM_Switch_ESH_ModeSwitch_BswM_MDGP_ESH_Mode = 0xFFu;
    }
  }
  if(BswM_Switch_BswMSwitchPort_SwcDiagCommunicationMode_Mode != 0xFFu)
  {
    if(Rte_Switch_Switch_BswMSwitchPort_SwcDiagCommunicationMode_Mode(BswM_Switch_BswMSwitchPort_SwcDiagCommunicationMode_Mode) == RTE_E_OK)
    {
      BswM_Switch_BswMSwitchPort_SwcDiagCommunicationMode_Mode = 0xFFu;
    }
  }
}

/**********************************************************************************************************************
 *  BswM_SwcModeRequestUpdateFct_BSWM_SINGLEPARTITION
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(void, BSWM_CODE) BswM_SwcModeRequestUpdateFct_BSWM_SINGLEPARTITION(void)
{
  uint32 mode;
  mode = Rte_Mode_Notification_ESH_ModeNotification_BswM_MDGP_ESH_Mode();
  if (mode != RTE_TRANSITION_ESH_Mode)
  {
    BswM_Mode_Notification_ESH_ModeNotification_BswM_MDGP_ESH_Mode = (Rte_ModeType_ESH_Mode)mode;
  }
  (void)Rte_Read_Request_ESH_RunRequest_0_requestedMode(&Request_ESH_RunRequest_0_requestedMode); /* SBSW_BSWM_RTE_READ */
  (void)Rte_Read_Request_ESH_RunRequest_1_requestedMode(&Request_ESH_RunRequest_1_requestedMode); /* SBSW_BSWM_RTE_READ */
  (void)Rte_Read_Request_ESH_PostRunRequest_0_requestedMode(&Request_ESH_PostRunRequest_0_requestedMode); /* SBSW_BSWM_RTE_READ */
  (void)Rte_Read_Request_ESH_PostRunRequest_1_requestedMode(&Request_ESH_PostRunRequest_1_requestedMode); /* SBSW_BSWM_RTE_READ */
  (void)Rte_Read_Request_ESH_KillAllRunRequest_requestedMode(&Request_ESH_KillAllRunRequest_requestedMode); /* SBSW_BSWM_RTE_READ */
}

/**********************************************************************************************************************
 *  BswMActionFunctions
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  BswM_Action_INIT_Action_SecOC_Init_Left
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_INIT_Action_SecOC_Init_Left(BswM_HandleType handleId, BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BSWM_DUMMY_STATEMENT(handleId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */

  /*lint -save -e534 *//* PRQA S 3109, 3200 1 */ /* MD_MSR_14.3, MD_BSWM_3200 */
  SecOC_Init(SecOC_Config_Ptr);
  /*lint -restore */
  return E_OK;
}

/**********************************************************************************************************************
 *  BswM_Action_ComPduGroupHandling
 *********************************************************************************************************************/

FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_ComPduGroupHandling(BswM_HandleType handleId, BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{

  BswM_SizeOfComPduGroupHandlingStartParametersType idxStart;
  BswM_SizeOfComPduGroupHandlingStopParametersType idxStop;
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  BSWM_DUMMY_STATEMENT(handleId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  for(idxStart = BswM_GetComPduGroupHandlingStartParametersStartIdxOfComPduGroupHandlingParameters(handleId, partitionIdx); idxStart < BswM_GetComPduGroupHandlingStartParametersEndIdxOfComPduGroupHandlingParameters(handleId, partitionIdx); idxStart++)
  {
    Com_IpduGroupStart(BswM_GetIpduGroupIdOfComPduGroupHandlingStartParameters(idxStart, partitionIdx), BswM_GetInitializeOfComPduGroupHandlingStartParameters(idxStart, partitionIdx));
  }
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  BSWM_DUMMY_STATEMENT(handleId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  for(idxStop = BswM_GetComPduGroupHandlingStopParametersStartIdxOfComPduGroupHandlingParameters(handleId, partitionIdx); idxStop < BswM_GetComPduGroupHandlingStopParametersEndIdxOfComPduGroupHandlingParameters(handleId, partitionIdx); idxStop++)
  {
    Com_IpduGroupStop(BswM_GetIpduGroupIdOfComPduGroupHandlingStopParameters(idxStop, partitionIdx));
  }
  return E_OK;
}

/**********************************************************************************************************************
 *  BswM_Action_ESH_Action_EnterExclusiveArea_Left
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_ESH_Action_EnterExclusiveArea_Left(BswM_HandleType handleId, BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BSWM_DUMMY_STATEMENT(handleId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */

  /*lint -save -e534 *//* PRQA S 3109, 3200 1 */ /* MD_MSR_14.3, MD_BSWM_3200 */
  SchM_Enter_BswM_BSWM_EXCLUSIVE_AREA_0();
  /*lint -restore */
  return E_OK;
}

/**********************************************************************************************************************
 *  BswM_Action_ComMAllowCom
 *********************************************************************************************************************/

FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_ComMAllowCom(BswM_HandleType handleId, BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{

  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  BSWM_DUMMY_STATEMENT(handleId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  ComM_CommunicationAllowed(BswM_GetChannelOfComMAllowComParameters(handleId, partitionIdx), BswM_GetAllowedOfComMAllowComParameters(handleId, partitionIdx));
  return E_OK;
}

/**********************************************************************************************************************
 *  BswM_Action_ESH_Action_EcuMClearValidatedWakeupEvents_Left
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_ESH_Action_EcuMClearValidatedWakeupEvents_Left(BswM_HandleType handleId, BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BSWM_DUMMY_STATEMENT(handleId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */

  /*lint -save -e534 *//* PRQA S 3109, 3200 1 */ /* MD_MSR_14.3, MD_BSWM_3200 */
  EcuM_ClearValidatedWakeupEvent(ECUM_WKSOURCE_ALL_SOURCES);
  /*lint -restore */
  return E_OK;
}

/**********************************************************************************************************************
 *  BswM_Action_ESH_Action_OnEnterPostRun_Left
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_ESH_Action_OnEnterPostRun_Left(BswM_HandleType handleId, BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BSWM_DUMMY_STATEMENT(handleId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */

  BswM_ESH_OnEnterPostRun();
  return E_OK;
}

/**********************************************************************************************************************
 *  BswM_Action_EcuMStateSwitch
 *********************************************************************************************************************/

FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_EcuMStateSwitch(BswM_HandleType handleId, BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{

  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  BSWM_DUMMY_STATEMENT(handleId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  EcuM_SetState(BswM_GetTargetStateOfEcuMStateSwitchParameters(handleId, partitionIdx));
  return E_OK;
}

/**********************************************************************************************************************
 *  BswM_Action_ESH_Action_SwitchPostRun_Left
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_ESH_Action_SwitchPostRun_Left(BswM_HandleType handleId, BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BSWM_DUMMY_STATEMENT(handleId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */

  BswM_Switch_ESH_ModeSwitch_BswM_MDGP_ESH_Mode = RTE_MODE_ESH_Mode_POSTRUN;
  return E_OK;
}

/**********************************************************************************************************************
 *  BswM_Action_GenericMode
 *********************************************************************************************************************/

FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_GenericMode(BswM_HandleType handleId, BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{

  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  BSWM_DUMMY_STATEMENT(handleId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  BswM_RequestMode(BswM_GetUserOfGenericModeParameters(handleId, partitionIdx), BswM_GetModeOfGenericModeParameters(handleId, partitionIdx));
  return E_OK;
}

/**********************************************************************************************************************
 *  BswM_Action_ESH_Action_ExitExclusiveArea_Left
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_ESH_Action_ExitExclusiveArea_Left(BswM_HandleType handleId, BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BSWM_DUMMY_STATEMENT(handleId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */

  /*lint -save -e534 *//* PRQA S 3109, 3200 1 */ /* MD_MSR_14.3, MD_BSWM_3200 */
  SchM_Exit_BswM_BSWM_EXCLUSIVE_AREA_0();
  /*lint -restore */
  return E_OK;
}

/**********************************************************************************************************************
 *  BswM_Action_ESH_Action_OnEnterShutdown_Left
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_ESH_Action_OnEnterShutdown_Left(BswM_HandleType handleId, BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BSWM_DUMMY_STATEMENT(handleId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */

  BswM_ESH_OnEnterShutdown();
  return E_OK;
}

/**********************************************************************************************************************
 *  BswM_Action_ESH_Action_EcuMGoToSelectedShutdownTarget_Left
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_ESH_Action_EcuMGoToSelectedShutdownTarget_Left(BswM_HandleType handleId, BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BSWM_DUMMY_STATEMENT(handleId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */

  /*lint -save -e534 *//* PRQA S 3109, 3200 1 */ /* MD_MSR_14.3, MD_BSWM_3200 */
  (void)EcuM_GoToSelectedShutdownTarget();
  /*lint -restore */
  return E_OK;
}

/**********************************************************************************************************************
 *  BswM_Action_ESH_Action_OnEnterPrepShutdown_Left
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_ESH_Action_OnEnterPrepShutdown_Left(BswM_HandleType handleId, BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BSWM_DUMMY_STATEMENT(handleId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */

  BswM_ESH_OnEnterPrepShutdown();
  return E_OK;
}

/**********************************************************************************************************************
 *  BswM_Action_ESH_Action_SwitchShutdown_Left
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_ESH_Action_SwitchShutdown_Left(BswM_HandleType handleId, BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BSWM_DUMMY_STATEMENT(handleId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */

  BswM_Switch_ESH_ModeSwitch_BswM_MDGP_ESH_Mode = RTE_MODE_ESH_Mode_SHUTDOWN;
  return E_OK;
}

/**********************************************************************************************************************
 *  BswM_Action_ESH_Action_OnEnterWakeup_Left
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_ESH_Action_OnEnterWakeup_Left(BswM_HandleType handleId, BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BSWM_DUMMY_STATEMENT(handleId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */

  BswM_ESH_OnEnterWakeup();
  return E_OK;
}

/**********************************************************************************************************************
 *  BswM_Action_ESH_Action_SwitchWakeup_Left
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_ESH_Action_SwitchWakeup_Left(BswM_HandleType handleId, BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BSWM_DUMMY_STATEMENT(handleId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */

  BswM_Switch_ESH_ModeSwitch_BswM_MDGP_ESH_Mode = RTE_MODE_ESH_Mode_WAKEUP;
  return E_OK;
}

/**********************************************************************************************************************
 *  BswM_Action_ESH_Action_DemInit_Left
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_ESH_Action_DemInit_Left(BswM_HandleType handleId, BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BSWM_DUMMY_STATEMENT(handleId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */

  /*lint -save -e534 *//* PRQA S 3109, 3200 1 */ /* MD_MSR_14.3, MD_BSWM_3200 */
  Dem_Init(Dem_Config_Ptr);
  /*lint -restore */
  return E_OK;
}

/**********************************************************************************************************************
 *  BswM_Action_TimerControl
 *********************************************************************************************************************/

FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_TimerControl(BswM_HandleType handleId, BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{

  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  BSWM_DUMMY_STATEMENT(handleId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  BswM_UpdateTimer(partitionIdx, BswM_GetTimerOfTimerControlParameters(handleId, partitionIdx), BswM_GetValueOfTimerControlParameters(handleId, partitionIdx));
  return E_OK;
}

/**********************************************************************************************************************
 *  BswM_Action_ESH_Action_OnEnterRun_Left
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_ESH_Action_OnEnterRun_Left(BswM_HandleType handleId, BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BSWM_DUMMY_STATEMENT(handleId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */

  BswM_ESH_OnEnterRun();
  return E_OK;
}

/**********************************************************************************************************************
 *  BswM_Action_ESH_Action_SwitchRun_Left
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_ESH_Action_SwitchRun_Left(BswM_HandleType handleId, BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BSWM_DUMMY_STATEMENT(handleId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */

  BswM_Switch_ESH_ModeSwitch_BswM_MDGP_ESH_Mode = RTE_MODE_ESH_Mode_RUN;
  return E_OK;
}

/**********************************************************************************************************************
 *  BswM_Action_ESH_Action_DemShutdown_Left
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_ESH_Action_DemShutdown_Left(BswM_HandleType handleId, BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BSWM_DUMMY_STATEMENT(handleId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */

  /*lint -save -e534 *//* PRQA S 3109, 3200 1 */ /* MD_MSR_14.3, MD_BSWM_3200 */
  Dem_Shutdown();
  /*lint -restore */
  return E_OK;
}

/**********************************************************************************************************************
 *  BswM_Action_ESH_Action_OnEnterWaitForNvm_Left
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_ESH_Action_OnEnterWaitForNvm_Left(BswM_HandleType handleId, BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BSWM_DUMMY_STATEMENT(handleId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */

  BswM_ESH_OnEnterWaitForNvm();
  return E_OK;
}

/**********************************************************************************************************************
 *  BswM_Action_INIT_Action_Can_Init_Left
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_INIT_Action_Can_Init_Left(BswM_HandleType handleId, BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BSWM_DUMMY_STATEMENT(handleId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */

  /*lint -save -e534 *//* PRQA S 3109, 3200 1 */ /* MD_MSR_14.3, MD_BSWM_3200 */
  Can_Init(EcuM_GlobalPCConfig_Ptr->CfgPtr_Can_Init);
  /*lint -restore */
  return E_OK;
}

/**********************************************************************************************************************
 *  BswM_Action_INIT_Action_CanIf_Init_Left
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_INIT_Action_CanIf_Init_Left(BswM_HandleType handleId, BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BSWM_DUMMY_STATEMENT(handleId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */

  /*lint -save -e534 *//* PRQA S 3109, 3200 1 */ /* MD_MSR_14.3, MD_BSWM_3200 */
  CanIf_Init(EcuM_GlobalPCConfig_Ptr->CfgPtr_CanIf_Init);
  /*lint -restore */
  return E_OK;
}

/**********************************************************************************************************************
 *  BswM_Action_INIT_Action_Com_Init_Left
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_INIT_Action_Com_Init_Left(BswM_HandleType handleId, BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BSWM_DUMMY_STATEMENT(handleId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */

  /*lint -save -e534 *//* PRQA S 3109, 3200 1 */ /* MD_MSR_14.3, MD_BSWM_3200 */
  Com_Init(EcuM_GlobalPCConfig_Ptr->CfgPtr_Com_Init);
  /*lint -restore */
  return E_OK;
}

/**********************************************************************************************************************
 *  BswM_Action_INIT_Action_IpduM_Init_Left
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_INIT_Action_IpduM_Init_Left(BswM_HandleType handleId, BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BSWM_DUMMY_STATEMENT(handleId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */

  /*lint -save -e534 *//* PRQA S 3109, 3200 1 */ /* MD_MSR_14.3, MD_BSWM_3200 */
  IpduM_Init(IpduM_Config_Ptr);
  /*lint -restore */
  return E_OK;
}

/**********************************************************************************************************************
 *  BswM_Action_INIT_Action_PduR_Init_Left
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_INIT_Action_PduR_Init_Left(BswM_HandleType handleId, BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BSWM_DUMMY_STATEMENT(handleId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */

  /*lint -save -e534 *//* PRQA S 3109, 3200 1 */ /* MD_MSR_14.3, MD_BSWM_3200 */
  PduR_Init(EcuM_GlobalPCConfig_Ptr->CfgPtr_PduR_Init);
  /*lint -restore */
  return E_OK;
}

/**********************************************************************************************************************
 *  BswM_Action_INIT_Action_CanSM_Init_Left
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_INIT_Action_CanSM_Init_Left(BswM_HandleType handleId, BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BSWM_DUMMY_STATEMENT(handleId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */

  /*lint -save -e534 *//* PRQA S 3109, 3200 1 */ /* MD_MSR_14.3, MD_BSWM_3200 */
  CanSM_Init(EcuM_GlobalPCConfig_Ptr->CfgPtr_CanSM_Init);
  /*lint -restore */
  return E_OK;
}

/**********************************************************************************************************************
 *  BswM_Action_INIT_Action_CanNm_Init_Left
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_INIT_Action_CanNm_Init_Left(BswM_HandleType handleId, BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BSWM_DUMMY_STATEMENT(handleId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */

  /*lint -save -e534 *//* PRQA S 3109, 3200 1 */ /* MD_MSR_14.3, MD_BSWM_3200 */
  CanNm_Init(EcuM_GlobalPCConfig_Ptr->CfgPtr_CanNm_Init);
  /*lint -restore */
  return E_OK;
}

/**********************************************************************************************************************
 *  BswM_Action_INIT_Action_Nm_Init_Left
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_INIT_Action_Nm_Init_Left(BswM_HandleType handleId, BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BSWM_DUMMY_STATEMENT(handleId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */

  /*lint -save -e534 *//* PRQA S 3109, 3200 1 */ /* MD_MSR_14.3, MD_BSWM_3200 */
  Nm_Init(EcuM_GlobalPCConfig_Ptr->CfgPtr_Nm_Init);
  /*lint -restore */
  return E_OK;
}

/**********************************************************************************************************************
 *  BswM_Action_INIT_Action_CanTp_Init_Left
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_INIT_Action_CanTp_Init_Left(BswM_HandleType handleId, BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BSWM_DUMMY_STATEMENT(handleId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */

  /*lint -save -e534 *//* PRQA S 3109, 3200 1 */ /* MD_MSR_14.3, MD_BSWM_3200 */
  CanTp_Init(EcuM_GlobalPCConfig_Ptr->CfgPtr_CanTp_Init);
  /*lint -restore */
  return E_OK;
}

/**********************************************************************************************************************
 *  BswM_Action_INIT_Action_EnableInterrupts_Left
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_INIT_Action_EnableInterrupts_Left(BswM_HandleType handleId, BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BSWM_DUMMY_STATEMENT(handleId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */

  BswM_AL_SetProgrammableInterrupts();
  return E_OK;
}

/**********************************************************************************************************************
 *  BswM_Action_INIT_Action_ComM_Init_Left
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_INIT_Action_ComM_Init_Left(BswM_HandleType handleId, BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BSWM_DUMMY_STATEMENT(handleId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */

  /*lint -save -e534 *//* PRQA S 3109, 3200 1 */ /* MD_MSR_14.3, MD_BSWM_3200 */
  ComM_Init(EcuM_GlobalPCConfig_Ptr->CfgPtr_ComM_Init);
  /*lint -restore */
  return E_OK;
}

/**********************************************************************************************************************
 *  BswM_Action_INIT_Action_Dcm_Init_Left
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_INIT_Action_Dcm_Init_Left(BswM_HandleType handleId, BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BSWM_DUMMY_STATEMENT(handleId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */

  /*lint -save -e534 *//* PRQA S 3109, 3200 1 */ /* MD_MSR_14.3, MD_BSWM_3200 */
  Dcm_Init(EcuM_GlobalPCConfig_Ptr->CfgPtr_Dcm_Init);
  /*lint -restore */
  return E_OK;
}

/**********************************************************************************************************************
 *  BswM_Action_INIT_Action_Rte_Start_Left
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_INIT_Action_Rte_Start_Left(BswM_HandleType handleId, BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BSWM_DUMMY_STATEMENT(handleId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */

  /*lint -save -e534 *//* PRQA S 3109, 3200 1 */ /* MD_MSR_14.3, MD_BSWM_3200 */
  Rte_Start();
  /*lint -restore */
  return E_OK;
}

/**********************************************************************************************************************
 *  BswM_Action_INIT_Action_Port_Init_Left
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_INIT_Action_Port_Init_Left(BswM_HandleType handleId, BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BSWM_DUMMY_STATEMENT(handleId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */

  /*lint -save -e534 *//* PRQA S 3109, 3200 1 */ /* MD_MSR_14.3, MD_BSWM_3200 */
  Port_Init(&Port_Config);
  /*lint -restore */
  return E_OK;
}

/**********************************************************************************************************************
 *  BswM_Action_INIT_Action_Dma_Init_Left
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_INIT_Action_Dma_Init_Left(BswM_HandleType handleId, BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BSWM_DUMMY_STATEMENT(handleId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */

  /*lint -save -e534 *//* PRQA S 3109, 3200 1 */ /* MD_MSR_14.3, MD_BSWM_3200 */
  Dma_Init(&Dma_Config);
  /*lint -restore */
  return E_OK;
}

/**********************************************************************************************************************
 *  BswM_Action_INIT_Action_Spi_Init_Left
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_INIT_Action_Spi_Init_Left(BswM_HandleType handleId, BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BSWM_DUMMY_STATEMENT(handleId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */

  /*lint -save -e534 *//* PRQA S 3109, 3200 1 */ /* MD_MSR_14.3, MD_BSWM_3200 */
  Spi_Init(&Spi_Config);
  /*lint -restore */
  return E_OK;
}

/**********************************************************************************************************************
 *  BswM_Action_INIT_Action_Wdg_17_Scu_Init_Left
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_INIT_Action_Wdg_17_Scu_Init_Left(BswM_HandleType handleId, BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BSWM_DUMMY_STATEMENT(handleId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */

  /*lint -save -e534 *//* PRQA S 3109, 3200 1 */ /* MD_MSR_14.3, MD_BSWM_3200 */
  Wdg_17_Scu_Init(&Wdg_17_Scu_Config_0);
  /*lint -restore */
  return E_OK;
}

/**********************************************************************************************************************
 *  BswM_Action_INIT_Action_Icu_17_TimerIp_Init_Left
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_INIT_Action_Icu_17_TimerIp_Init_Left(BswM_HandleType handleId, BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BSWM_DUMMY_STATEMENT(handleId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */

  /*lint -save -e534 *//* PRQA S 3109, 3200 1 */ /* MD_MSR_14.3, MD_BSWM_3200 */
  Icu_17_TimerIp_Init(&Icu_17_TimerIp_Config);
  /*lint -restore */
  return E_OK;
}

/**********************************************************************************************************************
 *  BswM_Action_INIT_Action_WdgM_Init_Left
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_INIT_Action_WdgM_Init_Left(BswM_HandleType handleId, BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BSWM_DUMMY_STATEMENT(handleId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */

  /*lint -save -e534 *//* PRQA S 3109, 3200 1 */ /* MD_MSR_14.3, MD_BSWM_3200 */
  WdgM_Init(&WdgMConfig_Mode0_core0);
  /*lint -restore */
  return E_OK;
}

/**********************************************************************************************************************
 *  BswM_Action_INIT_Action_Csm_Init_Left
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_INIT_Action_Csm_Init_Left(BswM_HandleType handleId, BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BSWM_DUMMY_STATEMENT(handleId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */

  /*lint -save -e534 *//* PRQA S 3109, 3200 1 */ /* MD_MSR_14.3, MD_BSWM_3200 */
  Csm_Init();
  /*lint -restore */
  return E_OK;
}

/**********************************************************************************************************************
 *  BswM_Action_INIT_Action_Crypto_30_LibCv_Init_Left
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_INIT_Action_Crypto_30_LibCv_Init_Left(BswM_HandleType handleId, BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BSWM_DUMMY_STATEMENT(handleId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */

  /*lint -save -e534 *//* PRQA S 3109, 3200 1 */ /* MD_MSR_14.3, MD_BSWM_3200 */
  Crypto_30_LibCv_Init();
  /*lint -restore */
  return E_OK;
}

/**********************************************************************************************************************
 *  BswM_Action_INIT_Action_Crypto_30_vHsm_Init_Left
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_INIT_Action_Crypto_30_vHsm_Init_Left(BswM_HandleType handleId, BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BSWM_DUMMY_STATEMENT(handleId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */

  /*lint -save -e534 *//* PRQA S 3109, 3200 1 */ /* MD_MSR_14.3, MD_BSWM_3200 */
  Crypto_30_vHsm_Init();
  /*lint -restore */
  return E_OK;
}

/**********************************************************************************************************************
 *  BswM_Action_INIT_Action_CryIf_Init_Left
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_INIT_Action_CryIf_Init_Left(BswM_HandleType handleId, BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BSWM_DUMMY_STATEMENT(handleId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */

  /*lint -save -e534 *//* PRQA S 3109, 3200 1 */ /* MD_MSR_14.3, MD_BSWM_3200 */
  CryIf_Init();
  /*lint -restore */
  return E_OK;
}

/**********************************************************************************************************************
 *  BswM_Action_INIT_Action_KeyM_Init_Left
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_INIT_Action_KeyM_Init_Left(BswM_HandleType handleId, BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BSWM_DUMMY_STATEMENT(handleId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */

  /*lint -save -e534 *//* PRQA S 3109, 3200 1 */ /* MD_MSR_14.3, MD_BSWM_3200 */
  KeyM_Init(NULL_PTR);
  /*lint -restore */
  return E_OK;
}

/**********************************************************************************************************************
 *  BswM_Action_INIT_Action_NvMReadAll_Left
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_INIT_Action_NvMReadAll_Left(BswM_HandleType handleId, BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BSWM_DUMMY_STATEMENT(handleId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */

  BswM_INIT_NvMReadAll();
  return E_OK;
}

/**********************************************************************************************************************
 *  BswM_Action_ComDMHandling
 *********************************************************************************************************************/

FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_ComDMHandling(BswM_HandleType handleId, BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{

  BswM_SizeOfComDMHandlingEnableParametersType idxEnable;
  BswM_SizeOfComDMHandlingDisableParametersType idxDisable;
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  BSWM_DUMMY_STATEMENT(handleId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  for(idxEnable = BswM_GetComDMHandlingEnableParametersStartIdxOfComDMHandlingParameters(handleId, partitionIdx); idxEnable < BswM_GetComDMHandlingEnableParametersEndIdxOfComDMHandlingParameters(handleId, partitionIdx); idxEnable++)
  {
    Com_EnableReceptionDM(BswM_GetIpduGroupIdOfComDMHandlingEnableParameters(idxEnable, partitionIdx));
  }
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  BSWM_DUMMY_STATEMENT(handleId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  for(idxDisable = BswM_GetComDMHandlingDisableParametersStartIdxOfComDMHandlingParameters(handleId, partitionIdx); idxDisable < BswM_GetComDMHandlingDisableParametersEndIdxOfComDMHandlingParameters(handleId, partitionIdx); idxDisable++)
  {
    Com_DisableReceptionDM(BswM_GetIpduGroupIdOfComDMHandlingDisableParameters(idxDisable, partitionIdx));
  }
  return E_OK;
}

/**********************************************************************************************************************
 *  BswM_Action_INIT_Action_SBC_Init_Left
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_INIT_Action_SBC_Init_Left(BswM_HandleType handleId, BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BSWM_DUMMY_STATEMENT(handleId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */

  /*lint -save -e534 *//* PRQA S 3109, 3200 1 */ /* MD_MSR_14.3, MD_BSWM_3200 */
  SBC_Init();
  /*lint -restore */
  return E_OK;
}

/**********************************************************************************************************************
 *  BswM_Action_INIT_Action_Adc_Init_Left
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_INIT_Action_Adc_Init_Left(BswM_HandleType handleId, BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BSWM_DUMMY_STATEMENT(handleId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */

  /*lint -save -e534 *//* PRQA S 3109, 3200 1 */ /* MD_MSR_14.3, MD_BSWM_3200 */
  Adc_Init(&Adc_Config);
  /*lint -restore */
  return E_OK;
}

/**********************************************************************************************************************
 *  BswM_Action_INIT_Action_AdcIf_Init_Left
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_INIT_Action_AdcIf_Init_Left(BswM_HandleType handleId, BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BSWM_DUMMY_STATEMENT(handleId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */

  /*lint -save -e534 *//* PRQA S 3109, 3200 1 */ /* MD_MSR_14.3, MD_BSWM_3200 */
  AdcIf_Init();
  /*lint -restore */
  return E_OK;
}

/**********************************************************************************************************************
 *  BswM_Action_INIT_Action_Gpt_Init_Left
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_INIT_Action_Gpt_Init_Left(BswM_HandleType handleId, BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BSWM_DUMMY_STATEMENT(handleId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */

  /*lint -save -e534 *//* PRQA S 3109, 3200 1 */ /* MD_MSR_14.3, MD_BSWM_3200 */
  Gpt_Init(&Gpt_Config);
  /*lint -restore */
  return E_OK;
}

/**********************************************************************************************************************
 *  BswM_Action_INIT_Action_Pwm_17_GtmCcu6_Init_Left
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_INIT_Action_Pwm_17_GtmCcu6_Init_Left(BswM_HandleType handleId, BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BSWM_DUMMY_STATEMENT(handleId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */

  /*lint -save -e534 *//* PRQA S 3109, 3200 1 */ /* MD_MSR_14.3, MD_BSWM_3200 */
  Pwm_17_GtmCcu6_Init(&Pwm_17_GtmCcu6_Config);
  /*lint -restore */
  return E_OK;
}

/**********************************************************************************************************************
 *  BswM_Action_ESH_Action_ComMCheckPendingRequests_Left_Left
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_ESH_Action_ComMCheckPendingRequests_Left_Left(BswM_HandleType handleId, BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BSWM_DUMMY_STATEMENT(handleId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */

  ESH_ComM_CheckPendingRequests_Left();
  return E_OK;
}

/**********************************************************************************************************************
 *  BswM_Action_ESH_Action_DemPostRunRequested_Left_Left
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_ESH_Action_DemPostRunRequested_Left_Left(BswM_HandleType handleId, BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BSWM_DUMMY_STATEMENT(handleId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */

  ESH_Dem_PostRunRequested_Left();
  return E_OK;
}

/**********************************************************************************************************************
 *  BswM_Action_INIT_Action_ComM_PreInit_Left
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_INIT_Action_ComM_PreInit_Left(BswM_HandleType handleId, BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BSWM_DUMMY_STATEMENT(handleId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */

  /*lint -save -e534 *//* PRQA S 3109, 3200 1 */ /* MD_MSR_14.3, MD_BSWM_3200 */
  ComM_PreInit(EcuM_GlobalPCConfig_Ptr->CfgPtr_ComM_PreInit);
  /*lint -restore */
  return E_OK;
}

/**********************************************************************************************************************
 *  BswM_Action_INIT_Action_Nm_PreInit_Left
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_INIT_Action_Nm_PreInit_Left(BswM_HandleType handleId, BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BSWM_DUMMY_STATEMENT(handleId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */

  /*lint -save -e534 *//* PRQA S 3109, 3200 1 */ /* MD_MSR_14.3, MD_BSWM_3200 */
  Nm_PreInit(EcuM_GlobalPCConfig_Ptr->CfgPtr_Nm_PreInit);
  /*lint -restore */
  return E_OK;
}

/**********************************************************************************************************************
 *  BswM_Action_INIT_Action_ComM_PostInit_Left
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_INIT_Action_ComM_PostInit_Left(BswM_HandleType handleId, BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BSWM_DUMMY_STATEMENT(handleId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */

  /*lint -save -e534 *//* PRQA S 3109, 3200 1 */ /* MD_MSR_14.3, MD_BSWM_3200 */
  ComM_PostInit();
  /*lint -restore */
  return E_OK;
}

/**********************************************************************************************************************
 *  BswM_Action_INIT_Action_Nm_PostInit_Left
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_INIT_Action_Nm_PostInit_Left(BswM_HandleType handleId, BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BSWM_DUMMY_STATEMENT(handleId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */

  /*lint -save -e534 *//* PRQA S 3109, 3200 1 */ /* MD_MSR_14.3, MD_BSWM_3200 */
  Nm_PostInit();
  /*lint -restore */
  return E_OK;
}

/**********************************************************************************************************************
 *  BswM_Action_INIT_Action_StbM_Init_Left
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_INIT_Action_StbM_Init_Left(BswM_HandleType handleId, BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BSWM_DUMMY_STATEMENT(handleId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */

  /*lint -save -e534 *//* PRQA S 3109, 3200 1 */ /* MD_MSR_14.3, MD_BSWM_3200 */
  StbM_Init(StbM_Config_Ptr);
  /*lint -restore */
  return E_OK;
}

/**********************************************************************************************************************
 *  BswM_Action_INIT_Action_CanTSyn_Init_Left
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_INIT_Action_CanTSyn_Init_Left(BswM_HandleType handleId, BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BSWM_DUMMY_STATEMENT(handleId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */

  /*lint -save -e534 *//* PRQA S 3109, 3200 1 */ /* MD_MSR_14.3, MD_BSWM_3200 */
  CanTSyn_Init(NULL_PTR);
  /*lint -restore */
  return E_OK;
}

/**********************************************************************************************************************
 *  BswM_Action_INIT_Action_Smu_Init_Left
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_INIT_Action_Smu_Init_Left(BswM_HandleType handleId, BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BSWM_DUMMY_STATEMENT(handleId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */

  /*lint -save -e534 *//* PRQA S 3109, 3200 1 */ /* MD_MSR_14.3, MD_BSWM_3200 */
  RCM_PreInit();
  /*lint -restore */
  return E_OK;
}

/**********************************************************************************************************************
 *  BswM_Action_INIT_Action_RCM_Init_Left
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_INIT_Action_RCM_Init_Left(BswM_HandleType handleId, BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BSWM_DUMMY_STATEMENT(handleId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */

  /*lint -save -e534 *//* PRQA S 3109, 3200 1 */ /* MD_MSR_14.3, MD_BSWM_3200 */
  RCM_runDetermineResetCause();
  /*lint -restore */
  return E_OK;
}

/**********************************************************************************************************************
 *  BswM_Action_INIT_Action_StbM_PreInit_Left
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_INIT_Action_StbM_PreInit_Left(BswM_HandleType handleId, BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BSWM_DUMMY_STATEMENT(handleId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */

  /*lint -save -e534 *//* PRQA S 3109, 3200 1 */ /* MD_MSR_14.3, MD_BSWM_3200 */
  StbM_PreInit(StbM_Config_Ptr);
  /*lint -restore */
  return E_OK;
}

/**********************************************************************************************************************
 *  BswM_Action_INIT_Action_StbM_PostInit_Left
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_INIT_Action_StbM_PostInit_Left(BswM_HandleType handleId, BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BSWM_DUMMY_STATEMENT(handleId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */

  /*lint -save -e534 *//* PRQA S 3109, 3200 1 */ /* MD_MSR_14.3, MD_BSWM_3200 */
  StbM_PostInit();
  /*lint -restore */
  return E_OK;
}

/**********************************************************************************************************************
 *  BswM_Action_INIT_Action_Rtm_Init_Left
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_INIT_Action_Rtm_Init_Left(BswM_HandleType handleId, BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BSWM_DUMMY_STATEMENT(handleId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */

  /*lint -save -e534 *//* PRQA S 3109, 3200 1 */ /* MD_MSR_14.3, MD_BSWM_3200 */
  Rtm_Init();
  /*lint -restore */
  return E_OK;
}

/**********************************************************************************************************************
 *  BswM_Action_Rtm_CpuLoadMeasurementStart_Left
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_Rtm_CpuLoadMeasurementStart_Left(BswM_HandleType handleId, BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BSWM_DUMMY_STATEMENT(handleId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */

  Rtm_CpuLoadMeasurementStart();
  return E_OK;
}

/**********************************************************************************************************************
 *  BswM_Action_Action_Rtm_Shutdown_Left
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_Action_Rtm_Shutdown_Left(BswM_HandleType handleId, BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BSWM_DUMMY_STATEMENT(handleId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */

  /*lint -save -e534 *//* PRQA S 3109, 3200 1 */ /* MD_MSR_14.3, MD_BSWM_3200 */
  Rtm_Shutdown();
  /*lint -restore */
  return E_OK;
}

/**********************************************************************************************************************
 *  BswM_Action_INIT_Action_CanTSyn_PreInit_Left
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_INIT_Action_CanTSyn_PreInit_Left(BswM_HandleType handleId, BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BSWM_DUMMY_STATEMENT(handleId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */

  /*lint -save -e534 *//* PRQA S 3109, 3200 1 */ /* MD_MSR_14.3, MD_BSWM_3200 */
  CanTSyn_PreInit(CanTSyn_Config_Ptr);
  /*lint -restore */
  return E_OK;
}

/**********************************************************************************************************************
 *  BswM_Action_Action_RTE_SWITCH_BswMSwitchPort_SwcDiagCommunicationMode_COMM_FULL_COMMUNICATION_Left
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_Action_RTE_SWITCH_BswMSwitchPort_SwcDiagCommunicationMode_COMM_FULL_COMMUNICATION_Left(BswM_HandleType handleId, BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BSWM_DUMMY_STATEMENT(handleId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */

  BswM_Switch_BswMSwitchPort_SwcDiagCommunicationMode_Mode = RTE_MODE_CommunicationMode_COMM_FULL_COMMUNICATION;
  return E_OK;
}

/**********************************************************************************************************************
 *  BswM_Action_Action_RTE_SWITCH_BswMSwitchPort_SwcDiagCommunicationMode_COMM_NO_COMMUNICATION_Left
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_Action_RTE_SWITCH_BswMSwitchPort_SwcDiagCommunicationMode_COMM_NO_COMMUNICATION_Left(BswM_HandleType handleId, BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BSWM_DUMMY_STATEMENT(handleId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */

  BswM_Switch_BswMSwitchPort_SwcDiagCommunicationMode_Mode = RTE_MODE_CommunicationMode_COMM_NO_COMMUNICATION;
  return E_OK;
}

/**********************************************************************************************************************
 *  BswM_Action_INIT_Action_CanTSyn_Init_Right
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_INIT_Action_CanTSyn_Init_Right(BswM_HandleType handleId, BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BSWM_DUMMY_STATEMENT(handleId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */

  /*lint -save -e534 *//* PRQA S 3109, 3200 1 */ /* MD_MSR_14.3, MD_BSWM_3200 */
  CanTSyn_Init(CanTSyn_Config_Ptr);
  /*lint -restore */
  return E_OK;
}

/**********************************************************************************************************************
 *  BswM_Action_ESH_Action_ComMCheckPendingRequests_Right_Right
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_ESH_Action_ComMCheckPendingRequests_Right_Right(BswM_HandleType handleId, BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BSWM_DUMMY_STATEMENT(handleId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */

  ESH_ComM_CheckPendingRequests_Right();
  return E_OK;
}

/**********************************************************************************************************************
 *  BswM_Action_ESH_Action_DemPostRunRequested_Right_Right
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_ESH_Action_DemPostRunRequested_Right_Right(BswM_HandleType handleId, BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BSWM_DUMMY_STATEMENT(handleId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */

  ESH_Dem_PostRunRequested_Right();
  return E_OK;
}

/**********************************************************************************************************************
 *  BswMExpressionFunctions
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  BswM_ExpFct_CC_LE_RBTM_FL_BODY3_8uqv9blm85ehm0msat385m76v_03d5f5f6_TX_Left
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(uint8, BSWM_CODE) BswM_ExpFct_CC_LE_RBTM_FL_BODY3_8uqv9blm85ehm0msat385m76v_03d5f5f6_TX_Left(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  return (uint8)(((BswM_GetCanSMChannelState(0, 0u) == CANSM_BSWM_FULL_COMMUNICATION) && (BswM_GetDcmComState(0, 0u) != DCM_ENABLE_RX_DISABLE_TX_NORM)) ? 1u : 0u);
}

/**********************************************************************************************************************
 *  BswM_ExpFct_ESH_LE_RunToPostRunTransition_Left
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(uint8, BSWM_CODE) BswM_ExpFct_ESH_LE_RunToPostRunTransition_Left(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  /* PRQA S 3415 1 */ /* MD_BSWM_3415 */
  return (uint8)(((BswM_ExpFct_ESH_LE_RunReached_Left(partitionIdx) != 0u) && (BswM_ExpFct_ESH_LE_NoRunAndNoKillAllRequest_Left(partitionIdx) != 0u)) ? 1u : 0u);
}

/**********************************************************************************************************************
 *  BswM_ExpFct_ESH_LE_RunReached_Left
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(uint8, BSWM_CODE) BswM_ExpFct_ESH_LE_RunReached_Left(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  return (uint8)(((BswM_GetGenericState(3, 0u) == BSWM_GENERICVALUE_ESH_State_ESH_RUN) && (BswM_Mode_Notification_ESH_ModeNotification_BswM_MDGP_ESH_Mode == RTE_MODE_ESH_Mode_RUN) && (BswM_GetEcuMModeState(0u) == ECUM_STATE_APP_RUN)) ? 1u : 0u);
}

/**********************************************************************************************************************
 *  BswM_ExpFct_ESH_LE_NoRunAndNoKillAllRequest_Left
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(uint8, BSWM_CODE) BswM_ExpFct_ESH_LE_NoRunAndNoKillAllRequest_Left(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  /* PRQA S 3415 1 */ /* MD_BSWM_3415 */
  return (uint8)(((BswM_ExpFct_ESH_LE_NoRunReasons_Left(partitionIdx) != 0u) || (Request_ESH_KillAllRunRequest_requestedMode == REQUESTED)) ? 1u : 0u);
}

/**********************************************************************************************************************
 *  BswM_ExpFct_ESH_LE_NoRunReasons_Left
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(uint8, BSWM_CODE) BswM_ExpFct_ESH_LE_NoRunReasons_Left(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  /* PRQA S 3415 1 */ /* MD_BSWM_3415 */
  return (uint8)(((BswM_ExpFct_ESH_LE_AllChannelsNoCom_Left(partitionIdx) != 0u) && (BswM_ExpFct_ESH_LE_RunReleased_Left(partitionIdx) != 0u) && (BswM_GetEcuMRunRequestState(1, 0u) == ECUM_RUNSTATUS_RELEASED) && (BswM_GetTimerState(0, 0u) == BSWM_TIMER_EXPIRED)) ? 1u : 0u);
}

/**********************************************************************************************************************
 *  BswM_ExpFct_ESH_LE_AllChannelsNoCom_Left
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(uint8, BSWM_CODE) BswM_ExpFct_ESH_LE_AllChannelsNoCom_Left(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  return (uint8)((BswM_GetComMChannelState(0, 0u) == COMM_NO_COMMUNICATION) ? 1u : 0u);
}

/**********************************************************************************************************************
 *  BswM_ExpFct_ESH_LE_RunReleased_Left
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(uint8, BSWM_CODE) BswM_ExpFct_ESH_LE_RunReleased_Left(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  return (uint8)(((Request_ESH_RunRequest_0_requestedMode == RELEASED) && (Request_ESH_RunRequest_1_requestedMode == RELEASED)) ? 1u : 0u);
}

/**********************************************************************************************************************
 *  BswM_ExpFct_ESH_LE_ComMNoPendingRequests_Left
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(uint8, BSWM_CODE) BswM_ExpFct_ESH_LE_ComMNoPendingRequests_Left(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  return (uint8)(((BswM_GetGenericState(0, 0u) == BSWM_GENERICVALUE_ESH_ComMPendingRequests_ESH_COMM_NO_REQUEST) || (Request_ESH_KillAllRunRequest_requestedMode == REQUESTED)) ? 1u : 0u);
}

/**********************************************************************************************************************
 *  BswM_ExpFct_ESH_LE_WaitForNvMToShutdown_Left
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(uint8, BSWM_CODE) BswM_ExpFct_ESH_LE_WaitForNvMToShutdown_Left(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  /* PRQA S 3415 1 */ /* MD_BSWM_3415 */
  return (uint8)(((BswM_GetGenericState(3, 0u) == BSWM_GENERICVALUE_ESH_State_ESH_WAIT_FOR_NVM) && (BswM_ExpFct_ESH_LE_NoWakeupOrKillAll_Left(partitionIdx) != 0u)) ? 1u : 0u);
}

/**********************************************************************************************************************
 *  BswM_ExpFct_ESH_LE_NoWakeupOrKillAll_Left
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(uint8, BSWM_CODE) BswM_ExpFct_ESH_LE_NoWakeupOrKillAll_Left(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  /* PRQA S 3415 1 */ /* MD_BSWM_3415 */
  return (uint8)(((Request_ESH_KillAllRunRequest_requestedMode == REQUESTED) || (BswM_ExpFct_ESH_LE_NoWakeup_Left(partitionIdx) != 0u)) ? 1u : 0u);
}

/**********************************************************************************************************************
 *  BswM_ExpFct_ESH_LE_NoWakeup_Left
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(uint8, BSWM_CODE) BswM_ExpFct_ESH_LE_NoWakeup_Left(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  return (uint8)(((EcuM_GetValidatedWakeupEvents() == 0u) && (BswM_GetGenericState(0, 0u) == BSWM_GENERICVALUE_ESH_ComMPendingRequests_ESH_COMM_NO_REQUEST)) ? 1u : 0u);
}

/**********************************************************************************************************************
 *  BswM_ExpFct_ESH_LE_WakeupToPrepShutdown_Left
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(uint8, BSWM_CODE) BswM_ExpFct_ESH_LE_WakeupToPrepShutdown_Left(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  /* PRQA S 3415 1 */ /* MD_BSWM_3415 */
  return (uint8)(((BswM_GetGenericState(3, 0u) == BSWM_GENERICVALUE_ESH_State_ESH_WAKEUP) && (EcuM_GetPendingWakeupEvents() == 0u) && (BswM_ExpFct_ESH_LE_NoWakeup_Left(partitionIdx) != 0u) && (BswM_Mode_Notification_ESH_ModeNotification_BswM_MDGP_ESH_Mode == RTE_MODE_ESH_Mode_WAKEUP)) ? 1u : 0u);
}

/**********************************************************************************************************************
 *  BswM_ExpFct_ESH_LE_WaitForNvMToWakeup_Left
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(uint8, BSWM_CODE) BswM_ExpFct_ESH_LE_WaitForNvMToWakeup_Left(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  /* PRQA S 3415 1 */ /* MD_BSWM_3415 */
  return (uint8)(((BswM_GetGenericState(3, 0u) == BSWM_GENERICVALUE_ESH_State_ESH_WAIT_FOR_NVM) && (BswM_ExpFct_ESH_LE_ValidWakeup_Left(partitionIdx) != 0u) && (Request_ESH_KillAllRunRequest_requestedMode == RELEASED)) ? 1u : 0u);
}

/**********************************************************************************************************************
 *  BswM_ExpFct_ESH_LE_ValidWakeup_Left
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(uint8, BSWM_CODE) BswM_ExpFct_ESH_LE_ValidWakeup_Left(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  return (uint8)(((EcuM_GetValidatedWakeupEvents() != 0u) || (BswM_GetGenericState(0, 0u) == BSWM_GENERICVALUE_ESH_ComMPendingRequests_ESH_COMM_PENDING_REQUEST)) ? 1u : 0u);
}

/**********************************************************************************************************************
 *  BswM_ExpFct_ESH_LE_WakeupToRun_Left
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(uint8, BSWM_CODE) BswM_ExpFct_ESH_LE_WakeupToRun_Left(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  /* PRQA S 3415 1 */ /* MD_BSWM_3415 */
  return (uint8)(((BswM_GetGenericState(3, 0u) == BSWM_GENERICVALUE_ESH_State_ESH_WAKEUP) && (BswM_ExpFct_ESH_LE_ValidWakeup_Left(partitionIdx) != 0u) && (BswM_Mode_Notification_ESH_ModeNotification_BswM_MDGP_ESH_Mode == RTE_MODE_ESH_Mode_WAKEUP)) ? 1u : 0u);
}

/**********************************************************************************************************************
 *  BswM_ExpFct_ESH_LE_DemNotInitialized_Left
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(uint8, BSWM_CODE) BswM_ExpFct_ESH_LE_DemNotInitialized_Left(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  return (uint8)((BswM_GetGenericState(1, 0u) == BSWM_GENERICVALUE_ESH_DemInitStatus_DEM_NOT_INITIALIZED) ? 1u : 0u);
}

/**********************************************************************************************************************
 *  BswM_ExpFct_ESH_LE_InitToWakeup_Left
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(uint8, BSWM_CODE) BswM_ExpFct_ESH_LE_InitToWakeup_Left(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  return (uint8)(((BswM_GetGenericState(3, 0u) == BSWM_GENERICVALUE_ESH_State_ESH_INIT) && (BswM_GetEcuMModeState(0u) == ECUM_STATE_STARTUP)) ? 1u : 0u);
}

/**********************************************************************************************************************
 *  BswM_ExpFct_ESH_LE_Dem_PostRunRequested_Left
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(uint8, BSWM_CODE) BswM_ExpFct_ESH_LE_Dem_PostRunRequested_Left(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  return (uint8)(((BswM_ExpFct_ESH_LE_PostRunToPrep_Left(partitionIdx) != 0u) && (BswM_GetGenericState(2, 0u) == BSWM_GENERICVALUE_ESH_DemPostRunRequested_FALSE)) ? 1u : 0u);
}

/**********************************************************************************************************************
 *  BswM_ExpFct_ESH_LE_PostRunToPrep_Left
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(uint8, BSWM_CODE) BswM_ExpFct_ESH_LE_PostRunToPrep_Left(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  return (uint8)(((BswM_ExpFct_ESH_LE_PostRunReleased_Left(partitionIdx) != 0u) || (Request_ESH_KillAllRunRequest_requestedMode == REQUESTED)) ? 1u : 0u);
}

/**********************************************************************************************************************
 *  BswM_ExpFct_ESH_LE_PostRunReleased_Left
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(uint8, BSWM_CODE) BswM_ExpFct_ESH_LE_PostRunReleased_Left(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  return (uint8)(((Request_ESH_PostRunRequest_0_requestedMode == RELEASED) && (Request_ESH_PostRunRequest_1_requestedMode == RELEASED) && (BswM_GetEcuMRunRequestState(0, 0u) == ECUM_RUNSTATUS_RELEASED)) ? 1u : 0u);
}

/**********************************************************************************************************************
 *  BswM_ExpFct_ESH_LE_PostRunToRun_Left
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(uint8, BSWM_CODE) BswM_ExpFct_ESH_LE_PostRunToRun_Left(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  /* PRQA S 3415 1 */ /* MD_BSWM_3415 */
  return (uint8)(((BswM_ExpFct_ESH_LE_RunRequestsOrWakeup_Left(partitionIdx) != 0u) && (Request_ESH_KillAllRunRequest_requestedMode == RELEASED)) ? 1u : 0u);
}

/**********************************************************************************************************************
 *  BswM_ExpFct_ESH_LE_RunRequestsOrWakeup_Left
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(uint8, BSWM_CODE) BswM_ExpFct_ESH_LE_RunRequestsOrWakeup_Left(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  /* PRQA S 3415 1 */ /* MD_BSWM_3415 */
  return (uint8)(((BswM_ExpFct_ESH_LE_RunRequested_Left(partitionIdx) != 0u) || (BswM_GetEcuMRunRequestState(1, 0u) == ECUM_RUNSTATUS_REQUESTED) || (BswM_ExpFct_ESH_LE_ValidWakeup_Left(partitionIdx) != 0u)) ? 1u : 0u);
}

/**********************************************************************************************************************
 *  BswM_ExpFct_ESH_LE_RunRequested_Left
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(uint8, BSWM_CODE) BswM_ExpFct_ESH_LE_RunRequested_Left(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  return (uint8)(((Request_ESH_RunRequest_0_requestedMode == REQUESTED) || (Request_ESH_RunRequest_1_requestedMode == REQUESTED)) ? 1u : 0u);
}

/**********************************************************************************************************************
 *  BswM_ExpFct_ESH_LE_PostRun_Left
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(uint8, BSWM_CODE) BswM_ExpFct_ESH_LE_PostRun_Left(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  return (uint8)(((BswM_GetGenericState(3, 0u) == BSWM_GENERICVALUE_ESH_State_ESH_POST_RUN) && (BswM_Mode_Notification_ESH_ModeNotification_BswM_MDGP_ESH_Mode == RTE_MODE_ESH_Mode_POSTRUN) && (BswM_GetEcuMModeState(0u) == ECUM_STATE_APP_POST_RUN)) ? 1u : 0u);
}

/**********************************************************************************************************************
 *  BswM_ExpFct_ESH_LE_PrepShutdownToWaitForNvM_Left
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(uint8, BSWM_CODE) BswM_ExpFct_ESH_LE_PrepShutdownToWaitForNvM_Left(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  /* PRQA S 3415 1 */ /* MD_BSWM_3415 */
  return (uint8)(((BswM_GetGenericState(3, 0u) == BSWM_GENERICVALUE_ESH_State_ESH_PREP_SHUTDOWN) && (BswM_Mode_Notification_ESH_ModeNotification_BswM_MDGP_ESH_Mode == RTE_MODE_ESH_Mode_SHUTDOWN) && (BswM_ExpFct_ESH_LE_EcuMStateSleepOrShutdown_Left(partitionIdx) != 0u)) ? 1u : 0u);
}

/**********************************************************************************************************************
 *  BswM_ExpFct_ESH_LE_EcuMStateSleepOrShutdown_Left
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(uint8, BSWM_CODE) BswM_ExpFct_ESH_LE_EcuMStateSleepOrShutdown_Left(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  return (uint8)(((BswM_GetEcuMModeState(0u) == ECUM_STATE_SHUTDOWN) || (BswM_GetEcuMModeState(0u) == ECUM_STATE_SLEEP)) ? 1u : 0u);
}

/**********************************************************************************************************************
 *  BswM_ExpFct_CC_LE_RBTM_FL_BODY3_8uqv9blm85ehm0msat385m76v_03d5f5f6_PNC_00_MAPPING_b2c42696_RX_Left
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(uint8, BSWM_CODE) BswM_ExpFct_CC_LE_RBTM_FL_BODY3_8uqv9blm85ehm0msat385m76v_03d5f5f6_PNC_00_MAPPING_b2c42696_RX_Left(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  return (uint8)(((BswM_ExpFct_CC_LE_PNC_RBTM_FL_BODY3_8uqv9blm85ehm0msat385m76v_03d5f5f6_PNC_00_MAPPING_b2c42696_NEQ_NOCOM_Left(partitionIdx) != 0u) && (BswM_GetCanSMChannelState(0, 0u) != CANSM_BSWM_NO_COMMUNICATION)) ? 1u : 0u);
}

/**********************************************************************************************************************
 *  BswM_ExpFct_CC_LE_PNC_RBTM_FL_BODY3_8uqv9blm85ehm0msat385m76v_03d5f5f6_PNC_00_MAPPING_b2c42696_NEQ_NOCOM_Left
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(uint8, BSWM_CODE) BswM_ExpFct_CC_LE_PNC_RBTM_FL_BODY3_8uqv9blm85ehm0msat385m76v_03d5f5f6_PNC_00_MAPPING_b2c42696_NEQ_NOCOM_Left(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  return (uint8)((BswM_GetComMPncState(0, 0u) != COMM_PNC_NO_COMMUNICATION) ? 1u : 0u);
}

/**********************************************************************************************************************
 *  BswM_ExpFct_CC_LE_RBTM_FL_BODY3_8uqv9blm85ehm0msat385m76v_03d5f5f6_PNC_00_MAPPING_b2c42696_RX_DM_Left
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(uint8, BSWM_CODE) BswM_ExpFct_CC_LE_RBTM_FL_BODY3_8uqv9blm85ehm0msat385m76v_03d5f5f6_PNC_00_MAPPING_b2c42696_RX_DM_Left(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  return (uint8)(((BswM_ExpFct_CC_LE_PNC_RBTM_FL_BODY3_8uqv9blm85ehm0msat385m76v_03d5f5f6_PNC_00_MAPPING_b2c42696_NEQ_NOCOM_Left(partitionIdx) != 0u) && (BswM_GetCanSMChannelState(0, 0u) == CANSM_BSWM_FULL_COMMUNICATION)) ? 1u : 0u);
}

/**********************************************************************************************************************
 *  BswM_ExpFct_CC_LE_RBTM_FL_BODY3_8uqv9blm85ehm0msat385m76v_03d5f5f6_PNC_00_MAPPING_b2c42696_TX_Left
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(uint8, BSWM_CODE) BswM_ExpFct_CC_LE_RBTM_FL_BODY3_8uqv9blm85ehm0msat385m76v_03d5f5f6_PNC_00_MAPPING_b2c42696_TX_Left(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  return (uint8)(((BswM_ExpFct_CC_LE_PNC_RBTM_FL_BODY3_8uqv9blm85ehm0msat385m76v_03d5f5f6_PNC_00_MAPPING_b2c42696_NEQ_NOCOM_Left(partitionIdx) != 0u) && (BswM_GetCanSMChannelState(0, 0u) == CANSM_BSWM_FULL_COMMUNICATION) && (BswM_GetDcmComState(0, 0u) != DCM_ENABLE_RX_DISABLE_TX_NORM)) ? 1u : 0u);
}

/**********************************************************************************************************************
 *  BswM_ExpFct_CC_LE_RBTM_FL_BODY3_8uqv9blm85ehm0msat385m76v_03d5f5f6_PNC_20_MAPPING_796df885_RX_DM_Left
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(uint8, BSWM_CODE) BswM_ExpFct_CC_LE_RBTM_FL_BODY3_8uqv9blm85ehm0msat385m76v_03d5f5f6_PNC_20_MAPPING_796df885_RX_DM_Left(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  return (uint8)(((BswM_ExpFct_CC_LE_PNC_RBTM_FL_BODY3_8uqv9blm85ehm0msat385m76v_03d5f5f6_PNC_20_MAPPING_796df885_NEQ_NOCOM_Left(partitionIdx) != 0u) && (BswM_GetCanSMChannelState(0, 0u) == CANSM_BSWM_FULL_COMMUNICATION)) ? 1u : 0u);
}

/**********************************************************************************************************************
 *  BswM_ExpFct_CC_LE_PNC_RBTM_FL_BODY3_8uqv9blm85ehm0msat385m76v_03d5f5f6_PNC_20_MAPPING_796df885_NEQ_NOCOM_Left
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(uint8, BSWM_CODE) BswM_ExpFct_CC_LE_PNC_RBTM_FL_BODY3_8uqv9blm85ehm0msat385m76v_03d5f5f6_PNC_20_MAPPING_796df885_NEQ_NOCOM_Left(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  return (uint8)((BswM_GetComMPncState(1, 0u) != COMM_PNC_NO_COMMUNICATION) ? 1u : 0u);
}

/**********************************************************************************************************************
 *  BswM_ExpFct_CC_LE_RBTM_FL_BODY3_8uqv9blm85ehm0msat385m76v_03d5f5f6_PNC_20_MAPPING_796df885_TX_Left
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(uint8, BSWM_CODE) BswM_ExpFct_CC_LE_RBTM_FL_BODY3_8uqv9blm85ehm0msat385m76v_03d5f5f6_PNC_20_MAPPING_796df885_TX_Left(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  return (uint8)(((BswM_ExpFct_CC_LE_PNC_RBTM_FL_BODY3_8uqv9blm85ehm0msat385m76v_03d5f5f6_PNC_20_MAPPING_796df885_NEQ_NOCOM_Left(partitionIdx) != 0u) && (BswM_GetCanSMChannelState(0, 0u) == CANSM_BSWM_FULL_COMMUNICATION) && (BswM_GetDcmComState(0, 0u) != DCM_ENABLE_RX_DISABLE_TX_NORM)) ? 1u : 0u);
}

/**********************************************************************************************************************
 *  BswM_ExpFct_CC_LE_RBTM_FL_BODY3_8uqv9blm85ehm0msat385m76v_03d5f5f6_PNC_20_MAPPING_796df885_RX_Left
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(uint8, BSWM_CODE) BswM_ExpFct_CC_LE_RBTM_FL_BODY3_8uqv9blm85ehm0msat385m76v_03d5f5f6_PNC_20_MAPPING_796df885_RX_Left(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  return (uint8)(((BswM_ExpFct_CC_LE_PNC_RBTM_FL_BODY3_8uqv9blm85ehm0msat385m76v_03d5f5f6_PNC_20_MAPPING_796df885_NEQ_NOCOM_Left(partitionIdx) != 0u) && (BswM_GetCanSMChannelState(0, 0u) != CANSM_BSWM_NO_COMMUNICATION)) ? 1u : 0u);
}

/**********************************************************************************************************************
 *  BswM_ExpFct_LE_BswMRule_SwcDiagComMState_Left
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(uint8, BSWM_CODE) BswM_ExpFct_LE_BswMRule_SwcDiagComMState_Left(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  return (uint8)((BswM_GetComMChannelState(0, 0u) == COMM_FULL_COMMUNICATION) ? 1u : 0u);
}

/**********************************************************************************************************************
 *  BswM_ExpFct_ESH_LE_RunToPostRunTransition_Right
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(uint8, BSWM_CODE) BswM_ExpFct_ESH_LE_RunToPostRunTransition_Right(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  /* PRQA S 3415 1 */ /* MD_BSWM_3415 */
  return (uint8)(((BswM_ExpFct_ESH_LE_RunReached_Right(partitionIdx) != 0u) && (BswM_ExpFct_ESH_LE_NoRunAndNoKillAllRequest_Right(partitionIdx) != 0u)) ? 1u : 0u);
}

/**********************************************************************************************************************
 *  BswM_ExpFct_ESH_LE_NoRunAndNoKillAllRequest_Right
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(uint8, BSWM_CODE) BswM_ExpFct_ESH_LE_NoRunAndNoKillAllRequest_Right(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  /* PRQA S 3415 1 */ /* MD_BSWM_3415 */
  return (uint8)(((BswM_ExpFct_ESH_LE_NoRunReasons_Right(partitionIdx) != 0u) || (Request_ESH_KillAllRunRequest_requestedMode == REQUESTED)) ? 1u : 0u);
}

/**********************************************************************************************************************
 *  BswM_ExpFct_ESH_LE_NoRunReasons_Right
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(uint8, BSWM_CODE) BswM_ExpFct_ESH_LE_NoRunReasons_Right(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  /* PRQA S 3415 1 */ /* MD_BSWM_3415 */
  return (uint8)(((BswM_ExpFct_ESH_LE_AllChannelsNoCom_Right(partitionIdx) != 0u) && (BswM_ExpFct_ESH_LE_RunReleased_Right(partitionIdx) != 0u) && (BswM_GetEcuMRunRequestState(1, 0u) == ECUM_RUNSTATUS_RELEASED) && (BswM_GetTimerState(0, 0u) == BSWM_TIMER_EXPIRED)) ? 1u : 0u);
}

/**********************************************************************************************************************
 *  BswM_ExpFct_ESH_LE_WaitForNvMToShutdown_Right
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(uint8, BSWM_CODE) BswM_ExpFct_ESH_LE_WaitForNvMToShutdown_Right(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  /* PRQA S 3415 1 */ /* MD_BSWM_3415 */
  return (uint8)(((BswM_GetGenericState(3, 0u) == BSWM_GENERICVALUE_ESH_State_ESH_WAIT_FOR_NVM) && (BswM_ExpFct_ESH_LE_NoWakeupOrKillAll_Right(partitionIdx) != 0u)) ? 1u : 0u);
}

/**********************************************************************************************************************
 *  BswM_ExpFct_ESH_LE_NoWakeupOrKillAll_Right
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(uint8, BSWM_CODE) BswM_ExpFct_ESH_LE_NoWakeupOrKillAll_Right(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  /* PRQA S 3415 1 */ /* MD_BSWM_3415 */
  return (uint8)(((Request_ESH_KillAllRunRequest_requestedMode == REQUESTED) || (BswM_ExpFct_ESH_LE_NoWakeup_Right(partitionIdx) != 0u)) ? 1u : 0u);
}

/**********************************************************************************************************************
 *  BswM_ExpFct_ESH_LE_WakeupToPrepShutdown_Right
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(uint8, BSWM_CODE) BswM_ExpFct_ESH_LE_WakeupToPrepShutdown_Right(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  /* PRQA S 3415 1 */ /* MD_BSWM_3415 */
  return (uint8)(((BswM_GetGenericState(3, 0u) == BSWM_GENERICVALUE_ESH_State_ESH_WAKEUP) && (EcuM_GetPendingWakeupEvents() == 0u) && (BswM_ExpFct_ESH_LE_NoWakeup_Right(partitionIdx) != 0u) && (BswM_Mode_Notification_ESH_ModeNotification_BswM_MDGP_ESH_Mode == RTE_MODE_ESH_Mode_WAKEUP)) ? 1u : 0u);
}

/**********************************************************************************************************************
 *  BswM_ExpFct_ESH_LE_WaitForNvMToWakeup_Right
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(uint8, BSWM_CODE) BswM_ExpFct_ESH_LE_WaitForNvMToWakeup_Right(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  /* PRQA S 3415 1 */ /* MD_BSWM_3415 */
  return (uint8)(((BswM_GetGenericState(3, 0u) == BSWM_GENERICVALUE_ESH_State_ESH_WAIT_FOR_NVM) && (BswM_ExpFct_ESH_LE_ValidWakeup_Right(partitionIdx) != 0u) && (Request_ESH_KillAllRunRequest_requestedMode == RELEASED)) ? 1u : 0u);
}

/**********************************************************************************************************************
 *  BswM_ExpFct_ESH_LE_WakeupToRun_Right
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(uint8, BSWM_CODE) BswM_ExpFct_ESH_LE_WakeupToRun_Right(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  /* PRQA S 3415 1 */ /* MD_BSWM_3415 */
  return (uint8)(((BswM_GetGenericState(3, 0u) == BSWM_GENERICVALUE_ESH_State_ESH_WAKEUP) && (BswM_ExpFct_ESH_LE_ValidWakeup_Right(partitionIdx) != 0u) && (BswM_Mode_Notification_ESH_ModeNotification_BswM_MDGP_ESH_Mode == RTE_MODE_ESH_Mode_WAKEUP)) ? 1u : 0u);
}

/**********************************************************************************************************************
 *  BswM_ExpFct_ESH_LE_Dem_PostRunRequested_Right
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(uint8, BSWM_CODE) BswM_ExpFct_ESH_LE_Dem_PostRunRequested_Right(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  return (uint8)(((BswM_ExpFct_ESH_LE_PostRunToPrep_Right(partitionIdx) != 0u) && (BswM_GetGenericState(2, 0u) == BSWM_GENERICVALUE_ESH_DemPostRunRequested_FALSE)) ? 1u : 0u);
}

/**********************************************************************************************************************
 *  BswM_ExpFct_ESH_LE_PostRunToPrep_Right
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(uint8, BSWM_CODE) BswM_ExpFct_ESH_LE_PostRunToPrep_Right(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  return (uint8)(((BswM_ExpFct_ESH_LE_PostRunReleased_Right(partitionIdx) != 0u) || (Request_ESH_KillAllRunRequest_requestedMode == REQUESTED)) ? 1u : 0u);
}

/**********************************************************************************************************************
 *  BswM_ExpFct_ESH_LE_PostRunToRun_Right
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(uint8, BSWM_CODE) BswM_ExpFct_ESH_LE_PostRunToRun_Right(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  /* PRQA S 3415 1 */ /* MD_BSWM_3415 */
  return (uint8)(((BswM_ExpFct_ESH_LE_RunRequestsOrWakeup_Right(partitionIdx) != 0u) && (Request_ESH_KillAllRunRequest_requestedMode == RELEASED)) ? 1u : 0u);
}

/**********************************************************************************************************************
 *  BswM_ExpFct_ESH_LE_RunRequestsOrWakeup_Right
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(uint8, BSWM_CODE) BswM_ExpFct_ESH_LE_RunRequestsOrWakeup_Right(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  /* PRQA S 3415 1 */ /* MD_BSWM_3415 */
  return (uint8)(((BswM_ExpFct_ESH_LE_RunRequested_Right(partitionIdx) != 0u) || (BswM_GetEcuMRunRequestState(1, 0u) == ECUM_RUNSTATUS_REQUESTED) || (BswM_ExpFct_ESH_LE_ValidWakeup_Right(partitionIdx) != 0u)) ? 1u : 0u);
}

/**********************************************************************************************************************
 *  BswM_ExpFct_ESH_LE_PrepShutdownToWaitForNvM_Right
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(uint8, BSWM_CODE) BswM_ExpFct_ESH_LE_PrepShutdownToWaitForNvM_Right(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  /* PRQA S 3415 1 */ /* MD_BSWM_3415 */
  return (uint8)(((BswM_GetGenericState(3, 0u) == BSWM_GENERICVALUE_ESH_State_ESH_PREP_SHUTDOWN) && (BswM_Mode_Notification_ESH_ModeNotification_BswM_MDGP_ESH_Mode == RTE_MODE_ESH_Mode_SHUTDOWN) && (BswM_ExpFct_ESH_LE_EcuMStateSleepOrShutdown_Right(partitionIdx) != 0u)) ? 1u : 0u);
}

/**********************************************************************************************************************
 *  BswM_ExpFct_CC_LE_RBTM_FR_BODY3_4xwwtd59665s787n6ctawh7k8_23a94727_PNC_00_MAPPING_b2c42696_RX_DM_Right
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(uint8, BSWM_CODE) BswM_ExpFct_CC_LE_RBTM_FR_BODY3_4xwwtd59665s787n6ctawh7k8_23a94727_PNC_00_MAPPING_b2c42696_RX_DM_Right(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  return (uint8)(((BswM_ExpFct_CC_LE_PNC_RBTM_FR_BODY3_4xwwtd59665s787n6ctawh7k8_23a94727_PNC_00_MAPPING_b2c42696_NEQ_NOCOM_Right(partitionIdx) != 0u) && (BswM_GetCanSMChannelState(0, 0u) == CANSM_BSWM_FULL_COMMUNICATION)) ? 1u : 0u);
}

/**********************************************************************************************************************
 *  BswM_ExpFct_CC_LE_RBTM_FR_BODY3_4xwwtd59665s787n6ctawh7k8_23a94727_PNC_00_MAPPING_b2c42696_RX_Right
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(uint8, BSWM_CODE) BswM_ExpFct_CC_LE_RBTM_FR_BODY3_4xwwtd59665s787n6ctawh7k8_23a94727_PNC_00_MAPPING_b2c42696_RX_Right(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  return (uint8)(((BswM_ExpFct_CC_LE_PNC_RBTM_FR_BODY3_4xwwtd59665s787n6ctawh7k8_23a94727_PNC_00_MAPPING_b2c42696_NEQ_NOCOM_Right(partitionIdx) != 0u) && (BswM_GetCanSMChannelState(0, 0u) != CANSM_BSWM_NO_COMMUNICATION)) ? 1u : 0u);
}

/**********************************************************************************************************************
 *  BswM_ExpFct_CC_LE_RBTM_FR_BODY3_4xwwtd59665s787n6ctawh7k8_23a94727_PNC_20_MAPPING_796df885_TX_Right
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(uint8, BSWM_CODE) BswM_ExpFct_CC_LE_RBTM_FR_BODY3_4xwwtd59665s787n6ctawh7k8_23a94727_PNC_20_MAPPING_796df885_TX_Right(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  return (uint8)(((BswM_ExpFct_CC_LE_PNC_RBTM_FR_BODY3_4xwwtd59665s787n6ctawh7k8_23a94727_PNC_20_MAPPING_796df885_NEQ_NOCOM_Right(partitionIdx) != 0u) && (BswM_GetCanSMChannelState(0, 0u) == CANSM_BSWM_FULL_COMMUNICATION) && (BswM_GetDcmComState(0, 0u) != DCM_ENABLE_RX_DISABLE_TX_NORM)) ? 1u : 0u);
}

/**********************************************************************************************************************
 *  BswM_ExpFct_CC_LE_RBTM_FR_BODY3_4xwwtd59665s787n6ctawh7k8_23a94727_PNC_00_MAPPING_b2c42696_TX_Right
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(uint8, BSWM_CODE) BswM_ExpFct_CC_LE_RBTM_FR_BODY3_4xwwtd59665s787n6ctawh7k8_23a94727_PNC_00_MAPPING_b2c42696_TX_Right(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  return (uint8)(((BswM_ExpFct_CC_LE_PNC_RBTM_FR_BODY3_4xwwtd59665s787n6ctawh7k8_23a94727_PNC_00_MAPPING_b2c42696_NEQ_NOCOM_Right(partitionIdx) != 0u) && (BswM_GetCanSMChannelState(0, 0u) == CANSM_BSWM_FULL_COMMUNICATION) && (BswM_GetDcmComState(0, 0u) != DCM_ENABLE_RX_DISABLE_TX_NORM)) ? 1u : 0u);
}

/**********************************************************************************************************************
 *  BswM_ExpFct_CC_LE_RBTM_FR_BODY3_4xwwtd59665s787n6ctawh7k8_23a94727_PNC_20_MAPPING_796df885_RX_DM_Right
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(uint8, BSWM_CODE) BswM_ExpFct_CC_LE_RBTM_FR_BODY3_4xwwtd59665s787n6ctawh7k8_23a94727_PNC_20_MAPPING_796df885_RX_DM_Right(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  return (uint8)(((BswM_ExpFct_CC_LE_PNC_RBTM_FR_BODY3_4xwwtd59665s787n6ctawh7k8_23a94727_PNC_20_MAPPING_796df885_NEQ_NOCOM_Right(partitionIdx) != 0u) && (BswM_GetCanSMChannelState(0, 0u) == CANSM_BSWM_FULL_COMMUNICATION)) ? 1u : 0u);
}

/**********************************************************************************************************************
 *  BswM_ExpFct_CC_LE_RBTM_FR_BODY3_4xwwtd59665s787n6ctawh7k8_23a94727_PNC_20_MAPPING_796df885_RX_Right
 *********************************************************************************************************************/

BSWM_LOCAL FUNC(uint8, BSWM_CODE) BswM_ExpFct_CC_LE_RBTM_FR_BODY3_4xwwtd59665s787n6ctawh7k8_23a94727_PNC_20_MAPPING_796df885_RX_Right(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx)
{
  BSWM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  return (uint8)(((BswM_ExpFct_CC_LE_PNC_RBTM_FR_BODY3_4xwwtd59665s787n6ctawh7k8_23a94727_PNC_20_MAPPING_796df885_NEQ_NOCOM_Right(partitionIdx) != 0u) && (BswM_GetCanSMChannelState(0, 0u) != CANSM_BSWM_NO_COMMUNICATION)) ? 1u : 0u);
}


#define BSWM_STOP_SEC_CODE
/* PRQA S 5087 1 */ /* MD_MSR_MemMap */
#include "BswM_MemMap.h"

