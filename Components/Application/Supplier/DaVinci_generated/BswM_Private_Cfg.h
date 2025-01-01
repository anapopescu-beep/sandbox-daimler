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
 *              File: BswM_Private_Cfg.h
 *   Generation Time: 2024-02-15 14:31:27
 *           Project: StartApplication - Version 1.0
 *          Delivery: CBD2200333_D05
 *      Tool Version: DaVinci Configurator Classic 5.25.50 SP5
 *
 *
 *********************************************************************************************************************/


#if !defined(BSWM_PRIVATE_CFG_H)
#define BSWM_PRIVATE_CFG_H


/* -----------------------------------------------------------------------------
    &&&~ INCLUDE
 ----------------------------------------------------------------------------- */
#include "BswM_Cfg.h"
#include "Com.h" 
#include "Rte_BswM.h" 
#include "EcuM_Init_PBcfg.h" 
#include "SecOC.h" 
#include "SchM_BswM.h" 
#include "EcuM.h" 
#include "Dem.h" 
#include "Can.h" 
#include "CanIf.h" 
#include "IpduM.h" 
#include "PduR.h" 
#include "CanSM_EcuM.h" 
#include "CanNm.h" 
#include "Nm.h" 
#include "CanTp.h" 
#include "ComM.h" 
#include "Dcm.h" 
#include "Rte_Main.h" 
#include "Port.h" 
#include "Dma.h" 
#include "Spi.h" 
#include "Wdg_17_Scu.h" 
#include "Icu_17_TimerIp.h" 
#include "WdgM.h" 
#include "Csm.h" 
#include "Crypto_30_LibCv.h" 
#include "Crypto_30_vHsm.h" 
#include "CryIf.h" 
#include "KeyM.h" 
#include "SBC.h" 
#include "Adc.h" 
#include "AdcIf.h" 
#include "Gpt.h" 
#include "Pwm_17_GtmCcu6.h" 
#include "StbM.h" 
#include "CanTSyn.h" 
#include "Rcm.h" 
#include "RCM_Public.h" 
#include "Rtm.h" 



/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
**********************************************************************************************************************/
#define BSWM_ACTION_COMPDUGROUPHANDLING STD_ON 
#define BSWM_ACTION_COMMALLOWCOM        STD_ON 
#define BSWM_ACTION_ECUMSTATESWITCH     STD_ON 
#define BSWM_ACTION_GENERICMODE         STD_ON 
#define BSWM_ACTION_TIMERCONTROL        STD_ON 
#define BSWM_ACTION_COMDMHANDLING       STD_ON 


# define BSWM_FUNCTION_BASED STD_OFF

#if (defined (BSWM_ACTIONLISTSTRUEIDXOFRULES))
# if ((BSWM_ACTIONLISTSTRUEIDXOFRULES == STD_ON) && defined (BSWM_NO_ACTIONLISTSTRUEIDXOFRULES))
#  define BSWM_NO_ACTIONLIST(partition) BSWM_NO_ACTIONLISTSTRUEIDXOFRULES
# endif
#endif
#if (defined(BSWM_NO_ACTIONLIST))
#else
# if(defined(BSWM_ACTIONLISTSFALSEIDXOFRULES))
#  if ((BSWM_ACTIONLISTSFALSEIDXOFRULES == STD_ON) && defined (BSWM_NO_ACTIONLISTSFALSEIDXOFRULES))
#   define BSWM_NO_ACTIONLIST(partition) BSWM_NO_ACTIONLISTSFALSEIDXOFRULES
#  endif
# endif
#endif
#if (defined(BSWM_NO_ACTIONLIST))
#else
# if(defined(BSWM_SIZEOFACTIONLISTS))
#  if (BSWM_SIZEOFACTIONLISTS == STD_ON)
#   define BSWM_NO_ACTIONLIST(partition) BswM_GetSizeOfActionLists(partition) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  endif
# endif
#endif
#if (defined(BSWM_NO_ACTIONLIST))
#else
# define BSWM_NO_ACTIONLIST(partition) 255
#endif


#if BSWM_NVMJOBSTATE == STD_ON
#define NVM_SERVICE_ID_READALL   (uint8)0x0Cu
#define NVM_SERVICE_ID_WRITEALL  (uint8)0x0Du
#endif




/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
**********************************************************************************************************************/
/** 
  \defgroup  DataAccessMacros  Data Access Macros
  \brief  generated data access macros to abstract the generated data from the code to read and write CONST or VAR data.
  \{
*/ 
  /* PRQA S 3453 Macros_3453 */  /* MD_MSR_FctLikeMacro */
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL FUNCTION MACROS
**********************************************************************************************************************/
/** 
  \defgroup  BswMPCGetRootDataMacros  BswM Get Root Data Macros (PRE_COMPILE)
  \brief  These macros are used to get data pointers of root data.
  \{
*/ 
#define BswM_GetPCPartitionConfigOfPCConfig()                                                       BswM_ConfigPtr->PCPartitionConfigOfPCConfig
#define BswM_GetActionItemsOfPCPartitionConfig(partitionIndex)                                      BswM_GetPCPartitionConfigOfPCConfig()[(partitionIndex)].ActionItemsOfPCPartitionConfig
#define BswM_GetActionListsOfPCPartitionConfig(partitionIndex)                                      BswM_GetPCPartitionConfigOfPCConfig()[(partitionIndex)].ActionListsOfPCPartitionConfig
#define BswM_GetActionsOfPCPartitionConfig(partitionIndex)                                          BswM_GetPCPartitionConfigOfPCConfig()[(partitionIndex)].ActionsOfPCPartitionConfig
#define BswM_GetCanSMChannelMappingOfPCPartitionConfig(partitionIndex)                              BswM_GetPCPartitionConfigOfPCConfig()[(partitionIndex)].CanSMChannelMappingOfPCPartitionConfig
#define BswM_GetComDMHandlingDisableParametersOfPCPartitionConfig(partitionIndex)                   BswM_GetPCPartitionConfigOfPCConfig()[(partitionIndex)].ComDMHandlingDisableParametersOfPCPartitionConfig
#define BswM_GetComDMHandlingEnableParametersOfPCPartitionConfig(partitionIndex)                    BswM_GetPCPartitionConfigOfPCConfig()[(partitionIndex)].ComDMHandlingEnableParametersOfPCPartitionConfig
#define BswM_GetComMAllowComParametersOfPCPartitionConfig(partitionIndex)                           BswM_GetPCPartitionConfigOfPCConfig()[(partitionIndex)].ComMAllowComParametersOfPCPartitionConfig
#define BswM_GetComMChannelMappingOfPCPartitionConfig(partitionIndex)                               BswM_GetPCPartitionConfigOfPCConfig()[(partitionIndex)].ComMChannelMappingOfPCPartitionConfig
#define BswM_GetComPduGroupHandlingStartParametersOfPCPartitionConfig(partitionIndex)               BswM_GetPCPartitionConfigOfPCConfig()[(partitionIndex)].ComPduGroupHandlingStartParametersOfPCPartitionConfig
#define BswM_GetComPduGroupHandlingStopParametersOfPCPartitionConfig(partitionIndex)                BswM_GetPCPartitionConfigOfPCConfig()[(partitionIndex)].ComPduGroupHandlingStopParametersOfPCPartitionConfig
#define BswM_GetDcmComMappingOfPCPartitionConfig(partitionIndex)                                    BswM_GetPCPartitionConfigOfPCConfig()[(partitionIndex)].DcmComMappingOfPCPartitionConfig
#define BswM_GetDeferredRulesOfPCPartitionConfig(partitionIndex)                                    BswM_GetPCPartitionConfigOfPCConfig()[(partitionIndex)].DeferredRulesOfPCPartitionConfig
#define BswM_GetExpressionsOfPCPartitionConfig(partitionIndex)                                      BswM_GetPCPartitionConfigOfPCConfig()[(partitionIndex)].ExpressionsOfPCPartitionConfig
#define BswM_GetInitActionListsOfPCPartitionConfig(partitionIndex)                                  BswM_GetPCPartitionConfigOfPCConfig()[(partitionIndex)].InitActionListsOfPCPartitionConfig
#define BswM_GetRulesIndOfPCPartitionConfig(partitionIndex)                                         BswM_GetPCPartitionConfigOfPCConfig()[(partitionIndex)].RulesIndOfPCPartitionConfig
#define BswM_GetRulesOfPCPartitionConfig(partitionIndex)                                            BswM_GetPCPartitionConfigOfPCConfig()[(partitionIndex)].RulesOfPCPartitionConfig
#define BswM_GetTimerControlParametersOfPCPartitionConfig(partitionIndex)                           BswM_GetPCPartitionConfigOfPCConfig()[(partitionIndex)].TimerControlParametersOfPCPartitionConfig
/** 
  \}
*/ 

/** 
  \defgroup  BswMPCGetConstantDuplicatedRootDataMacros  BswM Get Constant Duplicated Root Data Macros (PRE_COMPILE)
  \brief  These macros can be used to read deduplicated by constance root data elements.
  \{
*/ 
#define BswM_GetPartitionIdentifiersOfPCConfig()                                                    BswM_PartitionIdentifiers  /**< the pointer to BswM_PartitionIdentifiers */
#define BswM_GetSizeOfPartitionIdentifiersOfPCConfig()                                              1u  /**< the number of accomplishable value elements in BswM_PartitionIdentifiers */
#define BswM_GetActionListQueueOfPCPartitionConfig(partitionIndex)                                  BswM_ActionListQueue.raw  /**< the pointer to BswM_ActionListQueue */
#define BswM_GetCanSMChannelStateOfPCPartitionConfig(partitionIndex)                                BswM_CanSMChannelState  /**< the pointer to BswM_CanSMChannelState */
#define BswM_GetComDMHandlingParametersOfPCPartitionConfig(partitionIndex)                          BswM_ComDMHandlingParameters  /**< the pointer to BswM_ComDMHandlingParameters */
#define BswM_GetComMChannelStateOfPCPartitionConfig(partitionIndex)                                 BswM_ComMChannelState  /**< the pointer to BswM_ComMChannelState */
#define BswM_GetComMPncMappingOfPCPartitionConfig(partitionIndex)                                   BswM_ComMPncMapping  /**< the pointer to BswM_ComMPncMapping */
#define BswM_GetComMPncStateOfPCPartitionConfig(partitionIndex)                                     BswM_ComMPncState  /**< the pointer to BswM_ComMPncState */
#define BswM_GetComPduGroupHandlingParametersOfPCPartitionConfig(partitionIndex)                    BswM_ComPduGroupHandlingParameters  /**< the pointer to BswM_ComPduGroupHandlingParameters */
#define BswM_GetDcmComStateOfPCPartitionConfig(partitionIndex)                                      BswM_DcmComState  /**< the pointer to BswM_DcmComState */
#define BswM_GetEcuMModeMappingOfPCPartitionConfig(partitionIndex)                                  BswM_EcuMModeMapping  /**< the pointer to BswM_EcuMModeMapping */
#define BswM_GetEcuMModeStateOfPCPartitionConfig(partitionIndex)                                    (&(BswM_EcuMModeState))  /**< the pointer to BswM_EcuMModeState */
#define BswM_GetEcuMRunRequestMappingOfPCPartitionConfig(partitionIndex)                            BswM_EcuMRunRequestMapping  /**< the pointer to BswM_EcuMRunRequestMapping */
#define BswM_GetEcuMRunRequestStateOfPCPartitionConfig(partitionIndex)                              BswM_EcuMRunRequestState  /**< the pointer to BswM_EcuMRunRequestState */
#define BswM_GetEcuMStateSwitchParametersOfPCPartitionConfig(partitionIndex)                        BswM_EcuMStateSwitchParameters  /**< the pointer to BswM_EcuMStateSwitchParameters */
#define BswM_GetForcedActionListPriorityOfPCPartitionConfig(partitionIndex)                         (&(BswM_ForcedActionListPriority))  /**< the pointer to BswM_ForcedActionListPriority */
#define BswM_GetGenericMappingOfPCPartitionConfig(partitionIndex)                                   BswM_GenericMapping  /**< the pointer to BswM_GenericMapping */
#define BswM_GetGenericModeParametersOfPCPartitionConfig(partitionIndex)                            BswM_GenericModeParameters  /**< the pointer to BswM_GenericModeParameters */
#define BswM_GetGenericStateOfPCPartitionConfig(partitionIndex)                                     BswM_GenericState  /**< the pointer to BswM_GenericState */
#define BswM_GetImmediateUserOfPCPartitionConfig(partitionIndex)                                    BswM_ImmediateUser  /**< the pointer to BswM_ImmediateUser */
#define BswM_GetInitGenVarAndInitALOfPCPartitionConfig(partitionIndex)                              BswM_InitGenVarAndInitAL  /**< the pointer to BswM_InitGenVarAndInitAL */
#define BswM_GetInitValuesOfPCPartitionConfig(partitionIndex)                                       BswM_InitValues  /**< the pointer to BswM_InitValues */
#define BswM_GetInitializedOfPCPartitionConfig(partitionIndex)                                      (&(BswM_Initialized))  /**< the pointer to BswM_Initialized */
#define BswM_GetModeNotificationFctOfPCPartitionConfig(partitionIndex)                              BswM_ModeNotificationFct  /**< the pointer to BswM_ModeNotificationFct */
#define BswM_GetModeRequestQueueOfPCPartitionConfig(partitionIndex)                                 BswM_ModeRequestQueue  /**< the pointer to BswM_ModeRequestQueue */
#define BswM_GetQueueSemaphoreOfPCPartitionConfig(partitionIndex)                                   (&(BswM_QueueSemaphore))  /**< the pointer to BswM_QueueSemaphore */
#define BswM_GetQueueWrittenOfPCPartitionConfig(partitionIndex)                                     (&(BswM_QueueWritten))  /**< the pointer to BswM_QueueWritten */
#define BswM_GetRuleStatesOfPCPartitionConfig(partitionIndex)                                       BswM_RuleStates.raw  /**< the pointer to BswM_RuleStates */
#define BswM_GetSizeOfActionItemsOfPCPartitionConfig(partitionIndex)                                114u  /**< the number of accomplishable value elements in BswM_ActionItems */
#define BswM_GetSizeOfActionListsOfPCPartitionConfig(partitionIndex)                                30u  /**< the number of accomplishable value elements in BswM_ActionLists */
#define BswM_GetSizeOfActionsOfPCPartitionConfig(partitionIndex)                                    72u  /**< the number of accomplishable value elements in BswM_Actions */
#define BswM_GetSizeOfCanSMChannelMappingOfPCPartitionConfig(partitionIndex)                        1u  /**< the number of accomplishable value elements in BswM_CanSMChannelMapping */
#define BswM_GetSizeOfCanSMChannelStateOfPCPartitionConfig(partitionIndex)                          1u  /**< the number of accomplishable value elements in BswM_CanSMChannelState */
#define BswM_GetSizeOfComDMHandlingDisableParametersOfPCPartitionConfig(partitionIndex)             2u  /**< the number of accomplishable value elements in BswM_ComDMHandlingDisableParameters */
#define BswM_GetSizeOfComDMHandlingEnableParametersOfPCPartitionConfig(partitionIndex)              2u  /**< the number of accomplishable value elements in BswM_ComDMHandlingEnableParameters */
#define BswM_GetSizeOfComDMHandlingParametersOfPCPartitionConfig(partitionIndex)                    4u  /**< the number of accomplishable value elements in BswM_ComDMHandlingParameters */
#define BswM_GetSizeOfComMAllowComParametersOfPCPartitionConfig(partitionIndex)                     2u  /**< the number of accomplishable value elements in BswM_ComMAllowComParameters */
#define BswM_GetSizeOfComMChannelMappingOfPCPartitionConfig(partitionIndex)                         1u  /**< the number of accomplishable value elements in BswM_ComMChannelMapping */
#define BswM_GetSizeOfComMChannelStateOfPCPartitionConfig(partitionIndex)                           1u  /**< the number of accomplishable value elements in BswM_ComMChannelState */
#define BswM_GetSizeOfComMPncMappingOfPCPartitionConfig(partitionIndex)                             2u  /**< the number of accomplishable value elements in BswM_ComMPncMapping */
#define BswM_GetSizeOfComMPncStateOfPCPartitionConfig(partitionIndex)                               2u  /**< the number of accomplishable value elements in BswM_ComMPncState */
#define BswM_GetSizeOfComPduGroupHandlingParametersOfPCPartitionConfig(partitionIndex)              10u  /**< the number of accomplishable value elements in BswM_ComPduGroupHandlingParameters */
#define BswM_GetSizeOfComPduGroupHandlingStartParametersOfPCPartitionConfig(partitionIndex)         5u  /**< the number of accomplishable value elements in BswM_ComPduGroupHandlingStartParameters */
#define BswM_GetSizeOfComPduGroupHandlingStopParametersOfPCPartitionConfig(partitionIndex)          5u  /**< the number of accomplishable value elements in BswM_ComPduGroupHandlingStopParameters */
#define BswM_GetSizeOfDcmComMappingOfPCPartitionConfig(partitionIndex)                              1u  /**< the number of accomplishable value elements in BswM_DcmComMapping */
#define BswM_GetSizeOfDcmComStateOfPCPartitionConfig(partitionIndex)                                1u  /**< the number of accomplishable value elements in BswM_DcmComState */
#define BswM_GetSizeOfDeferredRulesOfPCPartitionConfig(partitionIndex)                              8u  /**< the number of accomplishable value elements in BswM_DeferredRules */
#define BswM_GetSizeOfEcuMModeMappingOfPCPartitionConfig(partitionIndex)                            1u  /**< the number of accomplishable value elements in BswM_EcuMModeMapping */
#define BswM_GetSizeOfEcuMRunRequestMappingOfPCPartitionConfig(partitionIndex)                      2u  /**< the number of accomplishable value elements in BswM_EcuMRunRequestMapping */
#define BswM_GetSizeOfEcuMRunRequestStateOfPCPartitionConfig(partitionIndex)                        2u  /**< the number of accomplishable value elements in BswM_EcuMRunRequestState */
#define BswM_GetSizeOfEcuMStateSwitchParametersOfPCPartitionConfig(partitionIndex)                  3u  /**< the number of accomplishable value elements in BswM_EcuMStateSwitchParameters */
#define BswM_GetSizeOfExpressionsOfPCPartitionConfig(partitionIndex)                                35u  /**< the number of accomplishable value elements in BswM_Expressions */
#define BswM_GetSizeOfGenericMappingOfPCPartitionConfig(partitionIndex)                             4u  /**< the number of accomplishable value elements in BswM_GenericMapping */
#define BswM_GetSizeOfGenericModeParametersOfPCPartitionConfig(partitionIndex)                      7u  /**< the number of accomplishable value elements in BswM_GenericModeParameters */
#define BswM_GetSizeOfGenericStateOfPCPartitionConfig(partitionIndex)                               4u  /**< the number of accomplishable value elements in BswM_GenericState */
#define BswM_GetSizeOfImmediateUserOfPCPartitionConfig(partitionIndex)                              7u  /**< the number of accomplishable value elements in BswM_ImmediateUser */
#define BswM_GetSizeOfInitActionListsOfPCPartitionConfig(partitionIndex)                            1u  /**< the number of accomplishable value elements in BswM_InitActionLists */
#define BswM_GetSizeOfInitGenVarAndInitALOfPCPartitionConfig(partitionIndex)                        1u  /**< the number of accomplishable value elements in BswM_InitGenVarAndInitAL */
#define BswM_GetSizeOfInitValuesOfPCPartitionConfig(partitionIndex)                                 4u  /**< the number of accomplishable value elements in BswM_InitValues */
#define BswM_GetSizeOfModeNotificationFctOfPCPartitionConfig(partitionIndex)                        1u  /**< the number of accomplishable value elements in BswM_ModeNotificationFct */
#define BswM_GetSizeOfRuleStatesOfPCPartitionConfig(partitionIndex)                                 20u  /**< the number of accomplishable value elements in BswM_RuleStates */
#define BswM_GetSizeOfRulesIndOfPCPartitionConfig(partitionIndex)                                   25u  /**< the number of accomplishable value elements in BswM_RulesInd */
#define BswM_GetSizeOfRulesOfPCPartitionConfig(partitionIndex)                                      20u  /**< the number of accomplishable value elements in BswM_Rules */
#define BswM_GetSizeOfSwcModeRequestUpdateFctOfPCPartitionConfig(partitionIndex)                    1u  /**< the number of accomplishable value elements in BswM_SwcModeRequestUpdateFct */
#define BswM_GetSizeOfTimerControlParametersOfPCPartitionConfig(partitionIndex)                     1u  /**< the number of accomplishable value elements in BswM_TimerControlParameters */
#define BswM_GetSizeOfTimerStateOfPCPartitionConfig(partitionIndex)                                 1u  /**< the number of accomplishable value elements in BswM_TimerState */
#define BswM_GetSizeOfTimerValueOfPCPartitionConfig(partitionIndex)                                 1u  /**< the number of accomplishable value elements in BswM_TimerValue */
#define BswM_GetSwcModeRequestUpdateFctOfPCPartitionConfig(partitionIndex)                          BswM_SwcModeRequestUpdateFct  /**< the pointer to BswM_SwcModeRequestUpdateFct */
#define BswM_GetTimerStateOfPCPartitionConfig(partitionIndex)                                       BswM_TimerState.raw  /**< the pointer to BswM_TimerState */
#define BswM_GetTimerValueOfPCPartitionConfig(partitionIndex)                                       BswM_TimerValue.raw  /**< the pointer to BswM_TimerValue */
/** 
  \}
*/ 

/** 
  \defgroup  BswMPCGetDuplicatedRootDataMacros  BswM Get Duplicated Root Data Macros (PRE_COMPILE)
  \brief  These macros can be used to read deduplicated root data elements.
  \{
*/ 
#define BswM_GetSizeOfActionListQueueOfPCPartitionConfig(partitionIndex)                            BswM_GetSizeOfActionListsOfPCPartitionConfig(partitionIndex)  /**< the number of accomplishable value elements in BswM_ActionListQueue */
#define BswM_GetSizeOfModeRequestQueueOfPCPartitionConfig(partitionIndex)                           BswM_GetSizeOfImmediateUserOfPCPartitionConfig(partitionIndex)  /**< the number of accomplishable value elements in BswM_ModeRequestQueue */
/** 
  \}
*/ 

/** 
  \defgroup  BswMPCGetDataMacros  BswM Get Data Macros (PRE_COMPILE)
  \brief  These macros can be used to read CONST and VAR data.
  \{
*/ 
#define BswM_GetActionsIdxOfActionItems(Index, partitionIndex)                                      (BswM_GetActionItemsOfPCPartitionConfig(partitionIndex)[(Index)].ActionsIdxOfActionItems)
#define BswM_GetParameterIdxOfActionItems(Index, partitionIndex)                                    (BswM_GetActionItemsOfPCPartitionConfig(partitionIndex)[(Index)].ParameterIdxOfActionItems)
#define BswM_GetParameterOfActionItems(Index, partitionIndex)                                       (BswM_GetActionItemsOfPCPartitionConfig(partitionIndex)[(Index)].ParameterOfActionItems)
#define BswM_GetActionListQueue(Index, partitionIndex)                                              (BswM_GetActionListQueueOfPCPartitionConfig(partitionIndex)[(Index)])
#define BswM_GetActionItemsEndIdxOfActionLists(Index, partitionIndex)                               (BswM_GetActionListsOfPCPartitionConfig(partitionIndex)[(Index)].ActionItemsEndIdxOfActionLists)
#define BswM_GetActionItemsStartIdxOfActionLists(Index, partitionIndex)                             (BswM_GetActionListsOfPCPartitionConfig(partitionIndex)[(Index)].ActionItemsStartIdxOfActionLists)
#define BswM_IsConditionalOfActionLists(Index, partitionIndex)                                      ((BswM_GetActionListsOfPCPartitionConfig(partitionIndex)[(Index)].ConditionalOfActionLists) != FALSE)
#define BswM_GetActions(Index, partitionIndex)                                                      (BswM_GetActionsOfPCPartitionConfig(partitionIndex)[(Index)])
#define BswM_GetExternalIdOfCanSMChannelMapping(Index, partitionIndex)                              (BswM_GetCanSMChannelMappingOfPCPartitionConfig(partitionIndex)[(Index)].ExternalIdOfCanSMChannelMapping)
#define BswM_GetCanSMChannelState(Index, partitionIndex)                                            (BswM_GetCanSMChannelStateOfPCPartitionConfig(partitionIndex)[(Index)])
#define BswM_GetIpduGroupIdOfComDMHandlingDisableParameters(Index, partitionIndex)                  (BswM_GetComDMHandlingDisableParametersOfPCPartitionConfig(partitionIndex)[(Index)].IpduGroupIdOfComDMHandlingDisableParameters)
#define BswM_GetIpduGroupIdOfComDMHandlingEnableParameters(Index, partitionIndex)                   (BswM_GetComDMHandlingEnableParametersOfPCPartitionConfig(partitionIndex)[(Index)].IpduGroupIdOfComDMHandlingEnableParameters)
#define BswM_GetComDMHandlingDisableParametersEndIdxOfComDMHandlingParameters(Index, partitionIndex) (BswM_GetComDMHandlingParametersOfPCPartitionConfig(partitionIndex)[(Index)].ComDMHandlingDisableParametersEndIdxOfComDMHandlingParameters)
#define BswM_GetComDMHandlingDisableParametersStartIdxOfComDMHandlingParameters(Index, partitionIndex) (BswM_GetComDMHandlingParametersOfPCPartitionConfig(partitionIndex)[(Index)].ComDMHandlingDisableParametersStartIdxOfComDMHandlingParameters)
#define BswM_GetComDMHandlingEnableParametersEndIdxOfComDMHandlingParameters(Index, partitionIndex) (BswM_GetComDMHandlingParametersOfPCPartitionConfig(partitionIndex)[(Index)].ComDMHandlingEnableParametersEndIdxOfComDMHandlingParameters)
#define BswM_GetComDMHandlingEnableParametersStartIdxOfComDMHandlingParameters(Index, partitionIndex) (BswM_GetComDMHandlingParametersOfPCPartitionConfig(partitionIndex)[(Index)].ComDMHandlingEnableParametersStartIdxOfComDMHandlingParameters)
#define BswM_GetAllowedOfComMAllowComParameters(Index, partitionIndex)                              (BswM_GetComMAllowComParametersOfPCPartitionConfig(partitionIndex)[(Index)].AllowedOfComMAllowComParameters)
#define BswM_GetChannelOfComMAllowComParameters(Index, partitionIndex)                              (BswM_GetComMAllowComParametersOfPCPartitionConfig(partitionIndex)[(Index)].ChannelOfComMAllowComParameters)
#define BswM_GetExternalIdOfComMChannelMapping(Index, partitionIndex)                               (BswM_GetComMChannelMappingOfPCPartitionConfig(partitionIndex)[(Index)].ExternalIdOfComMChannelMapping)
#define BswM_GetComMChannelState(Index, partitionIndex)                                             (BswM_GetComMChannelStateOfPCPartitionConfig(partitionIndex)[(Index)])
#define BswM_GetExternalIdOfComMPncMapping(Index, partitionIndex)                                   (BswM_GetComMPncMappingOfPCPartitionConfig(partitionIndex)[(Index)].ExternalIdOfComMPncMapping)
#define BswM_GetImmediateUserEndIdxOfComMPncMapping(Index, partitionIndex)                          (BswM_GetComMPncMappingOfPCPartitionConfig(partitionIndex)[(Index)].ImmediateUserEndIdxOfComMPncMapping)
#define BswM_GetImmediateUserStartIdxOfComMPncMapping(Index, partitionIndex)                        (BswM_GetComMPncMappingOfPCPartitionConfig(partitionIndex)[(Index)].ImmediateUserStartIdxOfComMPncMapping)
#define BswM_GetComMPncState(Index, partitionIndex)                                                 (BswM_GetComMPncStateOfPCPartitionConfig(partitionIndex)[(Index)])
#define BswM_GetComPduGroupHandlingStartParametersEndIdxOfComPduGroupHandlingParameters(Index, partitionIndex) (BswM_GetComPduGroupHandlingParametersOfPCPartitionConfig(partitionIndex)[(Index)].ComPduGroupHandlingStartParametersEndIdxOfComPduGroupHandlingParameters)
#define BswM_GetComPduGroupHandlingStartParametersStartIdxOfComPduGroupHandlingParameters(Index, partitionIndex) (BswM_GetComPduGroupHandlingParametersOfPCPartitionConfig(partitionIndex)[(Index)].ComPduGroupHandlingStartParametersStartIdxOfComPduGroupHandlingParameters)
#define BswM_GetComPduGroupHandlingStopParametersEndIdxOfComPduGroupHandlingParameters(Index, partitionIndex) (BswM_GetComPduGroupHandlingParametersOfPCPartitionConfig(partitionIndex)[(Index)].ComPduGroupHandlingStopParametersEndIdxOfComPduGroupHandlingParameters)
#define BswM_GetComPduGroupHandlingStopParametersStartIdxOfComPduGroupHandlingParameters(Index, partitionIndex) (BswM_GetComPduGroupHandlingParametersOfPCPartitionConfig(partitionIndex)[(Index)].ComPduGroupHandlingStopParametersStartIdxOfComPduGroupHandlingParameters)
#define BswM_GetIpduGroupIdOfComPduGroupHandlingStartParameters(Index, partitionIndex)              (BswM_GetComPduGroupHandlingStartParametersOfPCPartitionConfig(partitionIndex)[(Index)].IpduGroupIdOfComPduGroupHandlingStartParameters)
#define BswM_GetIpduGroupIdOfComPduGroupHandlingStopParameters(Index, partitionIndex)               (BswM_GetComPduGroupHandlingStopParametersOfPCPartitionConfig(partitionIndex)[(Index)].IpduGroupIdOfComPduGroupHandlingStopParameters)
#define BswM_GetExternalIdOfDcmComMapping(Index, partitionIndex)                                    (BswM_GetDcmComMappingOfPCPartitionConfig(partitionIndex)[(Index)].ExternalIdOfDcmComMapping)
#define BswM_GetDcmComState(Index, partitionIndex)                                                  (BswM_GetDcmComStateOfPCPartitionConfig(partitionIndex)[(Index)])
#define BswM_GetRulesIdxOfDeferredRules(Index, partitionIndex)                                      (BswM_GetDeferredRulesOfPCPartitionConfig(partitionIndex)[(Index)].RulesIdxOfDeferredRules)
#define BswM_GetEcuMModeState(partitionIndex)                                                       ((*(BswM_GetEcuMModeStateOfPCPartitionConfig(partitionIndex))))
#define BswM_GetExternalIdOfEcuMRunRequestMapping(Index, partitionIndex)                            (BswM_GetEcuMRunRequestMappingOfPCPartitionConfig(partitionIndex)[(Index)].ExternalIdOfEcuMRunRequestMapping)
#define BswM_GetEcuMRunRequestState(Index, partitionIndex)                                          (BswM_GetEcuMRunRequestStateOfPCPartitionConfig(partitionIndex)[(Index)])
#define BswM_GetTargetStateOfEcuMStateSwitchParameters(Index, partitionIndex)                       (BswM_GetEcuMStateSwitchParametersOfPCPartitionConfig(partitionIndex)[(Index)].TargetStateOfEcuMStateSwitchParameters)
#define BswM_GetExpressions(Index, partitionIndex)                                                  (BswM_GetExpressionsOfPCPartitionConfig(partitionIndex)[(Index)])
#define BswM_GetForcedActionListPriority(partitionIndex)                                            ((*(BswM_GetForcedActionListPriorityOfPCPartitionConfig(partitionIndex))))
#define BswM_GetExternalIdOfGenericMapping(Index, partitionIndex)                                   (BswM_GetGenericMappingOfPCPartitionConfig(partitionIndex)[(Index)].ExternalIdOfGenericMapping)
#define BswM_GetImmediateUserEndIdxOfGenericMapping(Index, partitionIndex)                          (BswM_GetGenericMappingOfPCPartitionConfig(partitionIndex)[(Index)].ImmediateUserEndIdxOfGenericMapping)
#define BswM_GetImmediateUserStartIdxOfGenericMapping(Index, partitionIndex)                        (BswM_GetGenericMappingOfPCPartitionConfig(partitionIndex)[(Index)].ImmediateUserStartIdxOfGenericMapping)
#define BswM_GetInitValueOfGenericMapping(Index, partitionIndex)                                    (BswM_GetGenericMappingOfPCPartitionConfig(partitionIndex)[(Index)].InitValueOfGenericMapping)
#define BswM_GetModeOfGenericModeParameters(Index, partitionIndex)                                  (BswM_GetGenericModeParametersOfPCPartitionConfig(partitionIndex)[(Index)].ModeOfGenericModeParameters)
#define BswM_GetUserOfGenericModeParameters(Index, partitionIndex)                                  (BswM_GetGenericModeParametersOfPCPartitionConfig(partitionIndex)[(Index)].UserOfGenericModeParameters)
#define BswM_GetGenericState(Index, partitionIndex)                                                 (BswM_GetGenericStateOfPCPartitionConfig(partitionIndex)[(Index)])
#define BswM_IsOnInitOfImmediateUser(Index, partitionIndex)                                         ((BswM_GetImmediateUserOfPCPartitionConfig(partitionIndex)[(Index)].OnInitOfImmediateUser) != FALSE)
#define BswM_GetRulesIndEndIdxOfImmediateUser(Index, partitionIndex)                                (BswM_GetImmediateUserOfPCPartitionConfig(partitionIndex)[(Index)].RulesIndEndIdxOfImmediateUser)
#define BswM_GetRulesIndStartIdxOfImmediateUser(Index, partitionIndex)                              (BswM_GetImmediateUserOfPCPartitionConfig(partitionIndex)[(Index)].RulesIndStartIdxOfImmediateUser)
#define BswM_GetInitActionLists(Index, partitionIndex)                                              ((BswM_SizeOfActionListsType)BswM_GetInitActionListsOfPCPartitionConfig(partitionIndex)[(Index)])
#define BswM_GetInitGenVarAndInitAL(Index, partitionIndex)                                          (BswM_GetInitGenVarAndInitALOfPCPartitionConfig(partitionIndex)[(Index)])
#define BswM_GetInitValues(Index, partitionIndex)                                                   (BswM_GetInitValuesOfPCPartitionConfig(partitionIndex)[(Index)])
#define BswM_IsInitialized(partitionIndex)                                                          (((*(BswM_GetInitializedOfPCPartitionConfig(partitionIndex)))) != FALSE)
#define BswM_GetModeNotificationFct(Index, partitionIndex)                                          (BswM_GetModeNotificationFctOfPCPartitionConfig(partitionIndex)[(Index)])
#define BswM_GetModeRequestQueue(Index, partitionIndex)                                             (BswM_GetModeRequestQueueOfPCPartitionConfig(partitionIndex)[(Index)])
#define BswM_GetPCPartitionConfigIdxOfPartitionIdentifiers(Index)                                   (BswM_GetPartitionIdentifiersOfPCConfig()[(Index)].PCPartitionConfigIdxOfPartitionIdentifiers)
#define BswM_GetPartitionSNVOfPartitionIdentifiers(Index)                                           (BswM_GetPartitionIdentifiersOfPCConfig()[(Index)].PartitionSNVOfPartitionIdentifiers)
#define BswM_GetQueueSemaphore(partitionIndex)                                                      ((*(BswM_GetQueueSemaphoreOfPCPartitionConfig(partitionIndex))))
#define BswM_IsQueueWritten(partitionIndex)                                                         (((*(BswM_GetQueueWrittenOfPCPartitionConfig(partitionIndex)))) != FALSE)
#define BswM_GetRuleStates(Index, partitionIndex)                                                   (BswM_GetRuleStatesOfPCPartitionConfig(partitionIndex)[(Index)])
#define BswM_GetActionListsFalseIdxOfRules(Index, partitionIndex)                                   (BswM_GetRulesOfPCPartitionConfig(partitionIndex)[(Index)].ActionListsFalseIdxOfRules)
#define BswM_GetActionListsTrueIdxOfRules(Index, partitionIndex)                                    (BswM_GetRulesOfPCPartitionConfig(partitionIndex)[(Index)].ActionListsTrueIdxOfRules)
#define BswM_GetExpressionsIdxOfRules(Index, partitionIndex)                                        (BswM_GetRulesOfPCPartitionConfig(partitionIndex)[(Index)].ExpressionsIdxOfRules)
#define BswM_GetIdOfRules(Index, partitionIndex)                                                    (BswM_GetRulesOfPCPartitionConfig(partitionIndex)[(Index)].IdOfRules)
#define BswM_GetRuleStatesIdxOfRules(Index, partitionIndex)                                         (BswM_GetRulesOfPCPartitionConfig(partitionIndex)[(Index)].RuleStatesIdxOfRules)
#define BswM_GetRulesInd(Index, partitionIndex)                                                     (BswM_GetRulesIndOfPCPartitionConfig(partitionIndex)[(Index)])
#define BswM_GetSwcModeRequestUpdateFct(Index, partitionIndex)                                      (BswM_GetSwcModeRequestUpdateFctOfPCPartitionConfig(partitionIndex)[(Index)])
#define BswM_GetTimerOfTimerControlParameters(Index, partitionIndex)                                (BswM_GetTimerControlParametersOfPCPartitionConfig(partitionIndex)[(Index)].TimerOfTimerControlParameters)
#define BswM_GetTimerState(Index, partitionIndex)                                                   (BswM_GetTimerStateOfPCPartitionConfig(partitionIndex)[(Index)])
#define BswM_GetTimerValue(Index, partitionIndex)                                                   (BswM_GetTimerValueOfPCPartitionConfig(partitionIndex)[(Index)])
/** 
  \}
*/ 

/** 
  \defgroup  BswMPCGetDeduplicatedDataMacros  BswM Get Deduplicated Data Macros (PRE_COMPILE)
  \brief  These macros can be used to read deduplicated data elements.
  \{
*/ 
#define BswM_IsParameterUsedOfActionItems(Index, partitionIndex)                                    (((boolean)(BswM_GetParameterIdxOfActionItems(((Index)), (partitionIndex)) != BSWM_NO_PARAMETERIDXOFACTIONITEMS)) != FALSE)  /**< TRUE, if the 0:1 relation has minimum 1 relation pointing to BswM_ComMAllowComParameters,BswM_ComMModeLimitationParameters,BswM_ComMModeSwitchParameters,BswM_ComDMControlParameters,BswM_EcuMSelectShutdownTargetParameters,BswM_EcuMStateSwitchParameters,BswM_IdsmBlockStateChangeRequestParameters,BswM_LinScheduleRequestParameters,BswM_NmControlParameters,BswM_ComSwitchIPduModeParameters,BswM_ComPduGroupSwitchParameters,BswM_ComPduGroupHandlingParameters,BswM_ComDMHandlingParameters,BswM_ComTriggerIPduSendParameters,BswM_PduRouterControlParameters,BswM_TimerControlParameters,BswM_GenericModeParameters,BswM_GenericModeRefParameters,BswM_J1939DcmStateParameters,BswM_J1939RmStateParameters,BswM_SdClientParameters,BswM_SdConsumedParameters,BswM_SdServerParameters,BswM_SdServiceGroupSwitchParameters,BswM_RuleControlParameters,BswM_ActionLists,BswM_Rules */
#define BswM_IsActionItemsUsedOfActionLists(Index, partitionIndex)                                  (((TRUE)) != FALSE)  /**< TRUE, if the 0:n relation has 1 relation pointing to BswM_ActionItems */
#define BswM_GetImmediateUserEndIdxOfCanSMChannelMapping(Index, partitionIndex)                     1u  /**< the end index of the 0:n relation pointing to BswM_ImmediateUser */
#define BswM_GetImmediateUserStartIdxOfCanSMChannelMapping(Index, partitionIndex)                   0u  /**< the start index of the 0:n relation pointing to BswM_ImmediateUser */
#define BswM_IsImmediateUserUsedOfCanSMChannelMapping(Index, partitionIndex)                        (((TRUE)) != FALSE)  /**< TRUE, if the 0:n relation has 1 relation pointing to BswM_ImmediateUser */
#define BswM_GetInitValueOfCanSMChannelMapping(Index, partitionIndex)                               CANSM_BSWM_NO_COMMUNICATION  /**< Initialization value of port. */
#define BswM_IsComDMHandlingDisableParametersUsedOfComDMHandlingParameters(Index, partitionIndex)   (((boolean)(BswM_GetComDMHandlingDisableParametersStartIdxOfComDMHandlingParameters(((Index)), (partitionIndex)) != BSWM_NO_COMDMHANDLINGDISABLEPARAMETERSSTARTIDXOFCOMDMHANDLINGPARAMETERS)) != FALSE)  /**< TRUE, if the 0:n relation has 1 relation pointing to BswM_ComDMHandlingDisableParameters */
#define BswM_IsComDMHandlingEnableParametersUsedOfComDMHandlingParameters(Index, partitionIndex)    (((boolean)(BswM_GetComDMHandlingEnableParametersStartIdxOfComDMHandlingParameters(((Index)), (partitionIndex)) != BSWM_NO_COMDMHANDLINGENABLEPARAMETERSSTARTIDXOFCOMDMHANDLINGPARAMETERS)) != FALSE)  /**< TRUE, if the 0:n relation has 1 relation pointing to BswM_ComDMHandlingEnableParameters */
#define BswM_GetImmediateUserEndIdxOfComMChannelMapping(Index, partitionIndex)                      2u  /**< the end index of the 0:n relation pointing to BswM_ImmediateUser */
#define BswM_GetImmediateUserStartIdxOfComMChannelMapping(Index, partitionIndex)                    1u  /**< the start index of the 0:n relation pointing to BswM_ImmediateUser */
#define BswM_IsImmediateUserUsedOfComMChannelMapping(Index, partitionIndex)                         (((TRUE)) != FALSE)  /**< TRUE, if the 0:n relation has 1 relation pointing to BswM_ImmediateUser */
#define BswM_GetInitValueOfComMChannelMapping(Index, partitionIndex)                                COMM_NO_COMMUNICATION  /**< Initialization value of port. */
#define BswM_IsImmediateUserUsedOfComMPncMapping(Index, partitionIndex)                             (((TRUE)) != FALSE)  /**< TRUE, if the 0:n relation has 1 relation pointing to BswM_ImmediateUser */
#define BswM_GetInitValueOfComMPncMapping(Index, partitionIndex)                                    COMM_PNC_NO_COMMUNICATION  /**< Initialization value of port. */
#define BswM_IsComPduGroupHandlingStartParametersUsedOfComPduGroupHandlingParameters(Index, partitionIndex) (((boolean)(BswM_GetComPduGroupHandlingStartParametersStartIdxOfComPduGroupHandlingParameters(((Index)), (partitionIndex)) != BSWM_NO_COMPDUGROUPHANDLINGSTARTPARAMETERSSTARTIDXOFCOMPDUGROUPHANDLINGPARAMETERS)) != FALSE)  /**< TRUE, if the 0:n relation has 1 relation pointing to BswM_ComPduGroupHandlingStartParameters */
#define BswM_IsComPduGroupHandlingStopParametersUsedOfComPduGroupHandlingParameters(Index, partitionIndex) (((boolean)(BswM_GetComPduGroupHandlingStopParametersStartIdxOfComPduGroupHandlingParameters(((Index)), (partitionIndex)) != BSWM_NO_COMPDUGROUPHANDLINGSTOPPARAMETERSSTARTIDXOFCOMPDUGROUPHANDLINGPARAMETERS)) != FALSE)  /**< TRUE, if the 0:n relation has 1 relation pointing to BswM_ComPduGroupHandlingStopParameters */
#define BswM_GetInitializeOfComPduGroupHandlingStartParameters(Index, partitionIndex)               FALSE
#define BswM_GetImmediateUserEndIdxOfDcmComMapping(Index, partitionIndex)                           5u  /**< the end index of the 0:n relation pointing to BswM_ImmediateUser */
#define BswM_GetImmediateUserStartIdxOfDcmComMapping(Index, partitionIndex)                         4u  /**< the start index of the 0:n relation pointing to BswM_ImmediateUser */
#define BswM_IsImmediateUserUsedOfDcmComMapping(Index, partitionIndex)                              (((TRUE)) != FALSE)  /**< TRUE, if the 0:n relation has 1 relation pointing to BswM_ImmediateUser */
#define BswM_GetInitValueOfDcmComMapping(Index, partitionIndex)                                     DCM_ENABLE_RX_TX_NORM_NM  /**< Initialization value of port. */
#define BswM_GetInitValueOfEcuMModeMapping(Index, partitionIndex)                                   ECUM_STATE_OFF  /**< Initialization value of port. */
#define BswM_GetInitValueOfEcuMRunRequestMapping(Index, partitionIndex)                             ECUM_RUNSTATUS_RELEASED  /**< Initialization value of port. */
#define BswM_IsImmediateUserUsedOfGenericMapping(Index, partitionIndex)                             (((boolean)(BswM_GetImmediateUserStartIdxOfGenericMapping(((Index)), (partitionIndex)) != BSWM_NO_IMMEDIATEUSERSTARTIDXOFGENERICMAPPING)) != FALSE)  /**< TRUE, if the 0:n relation has 1 relation pointing to BswM_ImmediateUser */
#define BswM_IsRulesIndUsedOfImmediateUser(Index, partitionIndex)                                   (((boolean)(BswM_GetRulesIndStartIdxOfImmediateUser(((Index)), (partitionIndex)) != BSWM_NO_RULESINDSTARTIDXOFIMMEDIATEUSER)) != FALSE)  /**< TRUE, if the 0:n relation has 1 relation pointing to BswM_RulesInd */
#define BswM_IsActionListsFalseUsedOfRules(Index, partitionIndex)                                   (((boolean)(BswM_GetActionListsFalseIdxOfRules(((Index)), (partitionIndex)) != BSWM_NO_ACTIONLISTSFALSEIDXOFRULES)) != FALSE)  /**< TRUE, if the 0:1 relation has minimum 1 relation pointing to BswM_ActionLists */
#define BswM_IsActionListsTrueUsedOfRules(Index, partitionIndex)                                    (((TRUE)) != FALSE)  /**< TRUE, if the 0:1 relation has minimum 1 relation pointing to BswM_ActionLists */
#define BswM_GetInitOfRules(Index, partitionIndex)                                                  BSWM_FALSE  /**< Initialization value of rule state (TRUE, FALSE, UNDEFINED or DEACTIVATED). */
#define BswM_GetSizeOfActionItems(partitionIndex)                                                   BswM_GetSizeOfActionItemsOfPCPartitionConfig(partitionIndex)
#define BswM_GetSizeOfActionListQueue(partitionIndex)                                               BswM_GetSizeOfActionListQueueOfPCPartitionConfig(partitionIndex)
#define BswM_GetSizeOfActionLists(partitionIndex)                                                   BswM_GetSizeOfActionListsOfPCPartitionConfig(partitionIndex)
#define BswM_GetSizeOfActions(partitionIndex)                                                       BswM_GetSizeOfActionsOfPCPartitionConfig(partitionIndex)
#define BswM_GetSizeOfCanSMChannelMapping(partitionIndex)                                           BswM_GetSizeOfCanSMChannelMappingOfPCPartitionConfig(partitionIndex)
#define BswM_GetSizeOfCanSMChannelState(partitionIndex)                                             BswM_GetSizeOfCanSMChannelStateOfPCPartitionConfig(partitionIndex)
#define BswM_GetSizeOfComDMHandlingDisableParameters(partitionIndex)                                BswM_GetSizeOfComDMHandlingDisableParametersOfPCPartitionConfig(partitionIndex)
#define BswM_GetSizeOfComDMHandlingEnableParameters(partitionIndex)                                 BswM_GetSizeOfComDMHandlingEnableParametersOfPCPartitionConfig(partitionIndex)
#define BswM_GetSizeOfComDMHandlingParameters(partitionIndex)                                       BswM_GetSizeOfComDMHandlingParametersOfPCPartitionConfig(partitionIndex)
#define BswM_GetSizeOfComMAllowComParameters(partitionIndex)                                        BswM_GetSizeOfComMAllowComParametersOfPCPartitionConfig(partitionIndex)
#define BswM_GetSizeOfComMChannelMapping(partitionIndex)                                            BswM_GetSizeOfComMChannelMappingOfPCPartitionConfig(partitionIndex)
#define BswM_GetSizeOfComMChannelState(partitionIndex)                                              BswM_GetSizeOfComMChannelStateOfPCPartitionConfig(partitionIndex)
#define BswM_GetSizeOfComMPncMapping(partitionIndex)                                                BswM_GetSizeOfComMPncMappingOfPCPartitionConfig(partitionIndex)
#define BswM_GetSizeOfComMPncState(partitionIndex)                                                  BswM_GetSizeOfComMPncStateOfPCPartitionConfig(partitionIndex)
#define BswM_GetSizeOfComPduGroupHandlingParameters(partitionIndex)                                 BswM_GetSizeOfComPduGroupHandlingParametersOfPCPartitionConfig(partitionIndex)
#define BswM_GetSizeOfComPduGroupHandlingStartParameters(partitionIndex)                            BswM_GetSizeOfComPduGroupHandlingStartParametersOfPCPartitionConfig(partitionIndex)
#define BswM_GetSizeOfComPduGroupHandlingStopParameters(partitionIndex)                             BswM_GetSizeOfComPduGroupHandlingStopParametersOfPCPartitionConfig(partitionIndex)
#define BswM_GetSizeOfDcmComMapping(partitionIndex)                                                 BswM_GetSizeOfDcmComMappingOfPCPartitionConfig(partitionIndex)
#define BswM_GetSizeOfDcmComState(partitionIndex)                                                   BswM_GetSizeOfDcmComStateOfPCPartitionConfig(partitionIndex)
#define BswM_GetSizeOfDeferredRules(partitionIndex)                                                 BswM_GetSizeOfDeferredRulesOfPCPartitionConfig(partitionIndex)
#define BswM_GetSizeOfEcuMModeMapping(partitionIndex)                                               BswM_GetSizeOfEcuMModeMappingOfPCPartitionConfig(partitionIndex)
#define BswM_GetSizeOfEcuMRunRequestMapping(partitionIndex)                                         BswM_GetSizeOfEcuMRunRequestMappingOfPCPartitionConfig(partitionIndex)
#define BswM_GetSizeOfEcuMRunRequestState(partitionIndex)                                           BswM_GetSizeOfEcuMRunRequestStateOfPCPartitionConfig(partitionIndex)
#define BswM_GetSizeOfEcuMStateSwitchParameters(partitionIndex)                                     BswM_GetSizeOfEcuMStateSwitchParametersOfPCPartitionConfig(partitionIndex)
#define BswM_GetSizeOfExpressions(partitionIndex)                                                   BswM_GetSizeOfExpressionsOfPCPartitionConfig(partitionIndex)
#define BswM_GetSizeOfGenericMapping(partitionIndex)                                                BswM_GetSizeOfGenericMappingOfPCPartitionConfig(partitionIndex)
#define BswM_GetSizeOfGenericModeParameters(partitionIndex)                                         BswM_GetSizeOfGenericModeParametersOfPCPartitionConfig(partitionIndex)
#define BswM_GetSizeOfGenericState(partitionIndex)                                                  BswM_GetSizeOfGenericStateOfPCPartitionConfig(partitionIndex)
#define BswM_GetSizeOfImmediateUser(partitionIndex)                                                 BswM_GetSizeOfImmediateUserOfPCPartitionConfig(partitionIndex)
#define BswM_GetSizeOfInitActionLists(partitionIndex)                                               BswM_GetSizeOfInitActionListsOfPCPartitionConfig(partitionIndex)
#define BswM_GetSizeOfInitGenVarAndInitAL(partitionIndex)                                           BswM_GetSizeOfInitGenVarAndInitALOfPCPartitionConfig(partitionIndex)
#define BswM_GetSizeOfInitValues(partitionIndex)                                                    BswM_GetSizeOfInitValuesOfPCPartitionConfig(partitionIndex)
#define BswM_GetSizeOfModeNotificationFct(partitionIndex)                                           BswM_GetSizeOfModeNotificationFctOfPCPartitionConfig(partitionIndex)
#define BswM_GetSizeOfModeRequestQueue(partitionIndex)                                              BswM_GetSizeOfModeRequestQueueOfPCPartitionConfig(partitionIndex)
#define BswM_GetSizeOfPartitionIdentifiers()                                                        BswM_GetSizeOfPartitionIdentifiersOfPCConfig()
#define BswM_GetSizeOfRuleStates(partitionIndex)                                                    BswM_GetSizeOfRuleStatesOfPCPartitionConfig(partitionIndex)
#define BswM_GetSizeOfRules(partitionIndex)                                                         BswM_GetSizeOfRulesOfPCPartitionConfig(partitionIndex)
#define BswM_GetSizeOfRulesInd(partitionIndex)                                                      BswM_GetSizeOfRulesIndOfPCPartitionConfig(partitionIndex)
#define BswM_GetSizeOfSwcModeRequestUpdateFct(partitionIndex)                                       BswM_GetSizeOfSwcModeRequestUpdateFctOfPCPartitionConfig(partitionIndex)
#define BswM_GetSizeOfTimerControlParameters(partitionIndex)                                        BswM_GetSizeOfTimerControlParametersOfPCPartitionConfig(partitionIndex)
#define BswM_GetSizeOfTimerState(partitionIndex)                                                    BswM_GetSizeOfTimerStateOfPCPartitionConfig(partitionIndex)
#define BswM_GetSizeOfTimerValue(partitionIndex)                                                    BswM_GetSizeOfTimerValueOfPCPartitionConfig(partitionIndex)
#define BswM_GetValueOfTimerControlParameters(Index, partitionIndex)                                200u
/** 
  \}
*/ 

/** 
  \defgroup  BswMPCSetDataMacros  BswM Set Data Macros (PRE_COMPILE)
  \brief  These macros can be used to write data.
  \{
*/ 
#define BswM_SetActionListQueue(Index, Value, partitionIndex)                                       BswM_GetActionListQueueOfPCPartitionConfig(partitionIndex)[(Index)] = (Value)
#define BswM_SetCanSMChannelState(Index, Value, partitionIndex)                                     BswM_GetCanSMChannelStateOfPCPartitionConfig(partitionIndex)[(Index)] = (Value)
#define BswM_SetComMChannelState(Index, Value, partitionIndex)                                      BswM_GetComMChannelStateOfPCPartitionConfig(partitionIndex)[(Index)] = (Value)
#define BswM_SetComMPncState(Index, Value, partitionIndex)                                          BswM_GetComMPncStateOfPCPartitionConfig(partitionIndex)[(Index)] = (Value)
#define BswM_SetDcmComState(Index, Value, partitionIndex)                                           BswM_GetDcmComStateOfPCPartitionConfig(partitionIndex)[(Index)] = (Value)
#define BswM_SetEcuMModeState(Value, partitionIndex)                                                (*(BswM_GetEcuMModeStateOfPCPartitionConfig(partitionIndex))) = (Value)
#define BswM_SetEcuMRunRequestState(Index, Value, partitionIndex)                                   BswM_GetEcuMRunRequestStateOfPCPartitionConfig(partitionIndex)[(Index)] = (Value)
#define BswM_SetForcedActionListPriority(Value, partitionIndex)                                     (*(BswM_GetForcedActionListPriorityOfPCPartitionConfig(partitionIndex))) = (Value)
#define BswM_SetGenericState(Index, Value, partitionIndex)                                          BswM_GetGenericStateOfPCPartitionConfig(partitionIndex)[(Index)] = (Value)
#define BswM_SetInitialized(Value, partitionIndex)                                                  (*(BswM_GetInitializedOfPCPartitionConfig(partitionIndex))) = (Value)
#define BswM_SetModeRequestQueue(Index, Value, partitionIndex)                                      BswM_GetModeRequestQueueOfPCPartitionConfig(partitionIndex)[(Index)] = (Value)
#define BswM_SetQueueSemaphore(Value, partitionIndex)                                               (*(BswM_GetQueueSemaphoreOfPCPartitionConfig(partitionIndex))) = (Value)
#define BswM_SetQueueWritten(Value, partitionIndex)                                                 (*(BswM_GetQueueWrittenOfPCPartitionConfig(partitionIndex))) = (Value)
#define BswM_SetRuleStates(Index, Value, partitionIndex)                                            BswM_GetRuleStatesOfPCPartitionConfig(partitionIndex)[(Index)] = (Value)
#define BswM_SetTimerState(Index, Value, partitionIndex)                                            BswM_GetTimerStateOfPCPartitionConfig(partitionIndex)[(Index)] = (Value)
#define BswM_SetTimerValue(Index, Value, partitionIndex)                                            BswM_GetTimerValueOfPCPartitionConfig(partitionIndex)[(Index)] = (Value)
/** 
  \}
*/ 

/** 
  \defgroup  BswMPCHasMacros  BswM Has Macros (PRE_COMPILE)
  \brief  These macros can be used to detect at runtime a deactivated piece of information. TRUE in the CONFIGURATION_VARIANT PRE-COMPILE, TRUE or FALSE in the CONFIGURATION_VARIANT POST-BUILD.
  \{
*/ 
#define BswM_HasActionItems(partitionIndex)                                                         (BswM_GetActionItemsOfPCPartitionConfig(partitionIndex) != NULL_PTR)
#define BswM_HasActionsIdxOfActionItems(partitionIndex)                                             (TRUE != FALSE)
#define BswM_HasParameterIdxOfActionItems(partitionIndex)                                           (TRUE != FALSE)
#define BswM_HasParameterOfActionItems(partitionIndex)                                              (TRUE != FALSE)
#define BswM_HasParameterUsedOfActionItems(partitionIndex)                                          (TRUE != FALSE)
#define BswM_HasActionListQueue(partitionIndex)                                                     (TRUE != FALSE)
#define BswM_HasActionLists(partitionIndex)                                                         (BswM_GetActionListsOfPCPartitionConfig(partitionIndex) != NULL_PTR)
#define BswM_HasActionItemsEndIdxOfActionLists(partitionIndex)                                      (TRUE != FALSE)
#define BswM_HasActionItemsStartIdxOfActionLists(partitionIndex)                                    (TRUE != FALSE)
#define BswM_HasActionItemsUsedOfActionLists(partitionIndex)                                        (TRUE != FALSE)
#define BswM_HasConditionalOfActionLists(partitionIndex)                                            (TRUE != FALSE)
#define BswM_HasActions(partitionIndex)                                                             (BswM_GetActionsOfPCPartitionConfig(partitionIndex) != NULL_PTR)
#define BswM_HasCanSMChannelMapping(partitionIndex)                                                 (BswM_GetCanSMChannelMappingOfPCPartitionConfig(partitionIndex) != NULL_PTR)
#define BswM_HasExternalIdOfCanSMChannelMapping(partitionIndex)                                     (TRUE != FALSE)
#define BswM_HasImmediateUserEndIdxOfCanSMChannelMapping(partitionIndex)                            (TRUE != FALSE)
#define BswM_HasImmediateUserStartIdxOfCanSMChannelMapping(partitionIndex)                          (TRUE != FALSE)
#define BswM_HasImmediateUserUsedOfCanSMChannelMapping(partitionIndex)                              (TRUE != FALSE)
#define BswM_HasInitValueOfCanSMChannelMapping(partitionIndex)                                      (TRUE != FALSE)
#define BswM_HasCanSMChannelState(partitionIndex)                                                   (TRUE != FALSE)
#define BswM_HasComDMHandlingDisableParameters(partitionIndex)                                      (BswM_GetComDMHandlingDisableParametersOfPCPartitionConfig(partitionIndex) != NULL_PTR)
#define BswM_HasIpduGroupIdOfComDMHandlingDisableParameters(partitionIndex)                         (TRUE != FALSE)
#define BswM_HasComDMHandlingEnableParameters(partitionIndex)                                       (BswM_GetComDMHandlingEnableParametersOfPCPartitionConfig(partitionIndex) != NULL_PTR)
#define BswM_HasIpduGroupIdOfComDMHandlingEnableParameters(partitionIndex)                          (TRUE != FALSE)
#define BswM_HasComDMHandlingParameters(partitionIndex)                                             (TRUE != FALSE)
#define BswM_HasComDMHandlingDisableParametersEndIdxOfComDMHandlingParameters(partitionIndex)       (TRUE != FALSE)
#define BswM_HasComDMHandlingDisableParametersStartIdxOfComDMHandlingParameters(partitionIndex)     (TRUE != FALSE)
#define BswM_HasComDMHandlingDisableParametersUsedOfComDMHandlingParameters(partitionIndex)         (TRUE != FALSE)
#define BswM_HasComDMHandlingEnableParametersEndIdxOfComDMHandlingParameters(partitionIndex)        (TRUE != FALSE)
#define BswM_HasComDMHandlingEnableParametersStartIdxOfComDMHandlingParameters(partitionIndex)      (TRUE != FALSE)
#define BswM_HasComDMHandlingEnableParametersUsedOfComDMHandlingParameters(partitionIndex)          (TRUE != FALSE)
#define BswM_HasComMAllowComParameters(partitionIndex)                                              (BswM_GetComMAllowComParametersOfPCPartitionConfig(partitionIndex) != NULL_PTR)
#define BswM_HasAllowedOfComMAllowComParameters(partitionIndex)                                     (TRUE != FALSE)
#define BswM_HasChannelOfComMAllowComParameters(partitionIndex)                                     (TRUE != FALSE)
#define BswM_HasComMChannelMapping(partitionIndex)                                                  (BswM_GetComMChannelMappingOfPCPartitionConfig(partitionIndex) != NULL_PTR)
#define BswM_HasExternalIdOfComMChannelMapping(partitionIndex)                                      (TRUE != FALSE)
#define BswM_HasImmediateUserEndIdxOfComMChannelMapping(partitionIndex)                             (TRUE != FALSE)
#define BswM_HasImmediateUserStartIdxOfComMChannelMapping(partitionIndex)                           (TRUE != FALSE)
#define BswM_HasImmediateUserUsedOfComMChannelMapping(partitionIndex)                               (TRUE != FALSE)
#define BswM_HasInitValueOfComMChannelMapping(partitionIndex)                                       (TRUE != FALSE)
#define BswM_HasComMChannelState(partitionIndex)                                                    (TRUE != FALSE)
#define BswM_HasComMPncMapping(partitionIndex)                                                      (TRUE != FALSE)
#define BswM_HasExternalIdOfComMPncMapping(partitionIndex)                                          (TRUE != FALSE)
#define BswM_HasImmediateUserEndIdxOfComMPncMapping(partitionIndex)                                 (TRUE != FALSE)
#define BswM_HasImmediateUserStartIdxOfComMPncMapping(partitionIndex)                               (TRUE != FALSE)
#define BswM_HasImmediateUserUsedOfComMPncMapping(partitionIndex)                                   (TRUE != FALSE)
#define BswM_HasInitValueOfComMPncMapping(partitionIndex)                                           (TRUE != FALSE)
#define BswM_HasComMPncState(partitionIndex)                                                        (TRUE != FALSE)
#define BswM_HasComPduGroupHandlingParameters(partitionIndex)                                       (TRUE != FALSE)
#define BswM_HasComPduGroupHandlingStartParametersEndIdxOfComPduGroupHandlingParameters(partitionIndex) (TRUE != FALSE)
#define BswM_HasComPduGroupHandlingStartParametersStartIdxOfComPduGroupHandlingParameters(partitionIndex) (TRUE != FALSE)
#define BswM_HasComPduGroupHandlingStartParametersUsedOfComPduGroupHandlingParameters(partitionIndex) (TRUE != FALSE)
#define BswM_HasComPduGroupHandlingStopParametersEndIdxOfComPduGroupHandlingParameters(partitionIndex) (TRUE != FALSE)
#define BswM_HasComPduGroupHandlingStopParametersStartIdxOfComPduGroupHandlingParameters(partitionIndex) (TRUE != FALSE)
#define BswM_HasComPduGroupHandlingStopParametersUsedOfComPduGroupHandlingParameters(partitionIndex) (TRUE != FALSE)
#define BswM_HasComPduGroupHandlingStartParameters(partitionIndex)                                  (BswM_GetComPduGroupHandlingStartParametersOfPCPartitionConfig(partitionIndex) != NULL_PTR)
#define BswM_HasInitializeOfComPduGroupHandlingStartParameters(partitionIndex)                      (TRUE != FALSE)
#define BswM_HasIpduGroupIdOfComPduGroupHandlingStartParameters(partitionIndex)                     (TRUE != FALSE)
#define BswM_HasComPduGroupHandlingStopParameters(partitionIndex)                                   (BswM_GetComPduGroupHandlingStopParametersOfPCPartitionConfig(partitionIndex) != NULL_PTR)
#define BswM_HasIpduGroupIdOfComPduGroupHandlingStopParameters(partitionIndex)                      (TRUE != FALSE)
#define BswM_HasDcmComMapping(partitionIndex)                                                       (BswM_GetDcmComMappingOfPCPartitionConfig(partitionIndex) != NULL_PTR)
#define BswM_HasExternalIdOfDcmComMapping(partitionIndex)                                           (TRUE != FALSE)
#define BswM_HasImmediateUserEndIdxOfDcmComMapping(partitionIndex)                                  (TRUE != FALSE)
#define BswM_HasImmediateUserStartIdxOfDcmComMapping(partitionIndex)                                (TRUE != FALSE)
#define BswM_HasImmediateUserUsedOfDcmComMapping(partitionIndex)                                    (TRUE != FALSE)
#define BswM_HasInitValueOfDcmComMapping(partitionIndex)                                            (TRUE != FALSE)
#define BswM_HasDcmComState(partitionIndex)                                                         (TRUE != FALSE)
#define BswM_HasDeferredRules(partitionIndex)                                                       (BswM_GetDeferredRulesOfPCPartitionConfig(partitionIndex) != NULL_PTR)
#define BswM_HasRulesIdxOfDeferredRules(partitionIndex)                                             (TRUE != FALSE)
#define BswM_HasEcuMModeMapping(partitionIndex)                                                     (TRUE != FALSE)
#define BswM_HasInitValueOfEcuMModeMapping(partitionIndex)                                          (TRUE != FALSE)
#define BswM_HasEcuMModeState(partitionIndex)                                                       (TRUE != FALSE)
#define BswM_HasEcuMRunRequestMapping(partitionIndex)                                               (TRUE != FALSE)
#define BswM_HasExternalIdOfEcuMRunRequestMapping(partitionIndex)                                   (TRUE != FALSE)
#define BswM_HasInitValueOfEcuMRunRequestMapping(partitionIndex)                                    (TRUE != FALSE)
#define BswM_HasEcuMRunRequestState(partitionIndex)                                                 (TRUE != FALSE)
#define BswM_HasEcuMStateSwitchParameters(partitionIndex)                                           (TRUE != FALSE)
#define BswM_HasTargetStateOfEcuMStateSwitchParameters(partitionIndex)                              (TRUE != FALSE)
#define BswM_HasExpressions(partitionIndex)                                                         (BswM_GetExpressionsOfPCPartitionConfig(partitionIndex) != NULL_PTR)
#define BswM_HasForcedActionListPriority(partitionIndex)                                            (TRUE != FALSE)
#define BswM_HasGenericMapping(partitionIndex)                                                      (TRUE != FALSE)
#define BswM_HasExternalIdOfGenericMapping(partitionIndex)                                          (TRUE != FALSE)
#define BswM_HasImmediateUserEndIdxOfGenericMapping(partitionIndex)                                 (TRUE != FALSE)
#define BswM_HasImmediateUserStartIdxOfGenericMapping(partitionIndex)                               (TRUE != FALSE)
#define BswM_HasImmediateUserUsedOfGenericMapping(partitionIndex)                                   (TRUE != FALSE)
#define BswM_HasInitValueOfGenericMapping(partitionIndex)                                           (TRUE != FALSE)
#define BswM_HasGenericModeParameters(partitionIndex)                                               (TRUE != FALSE)
#define BswM_HasModeOfGenericModeParameters(partitionIndex)                                         (TRUE != FALSE)
#define BswM_HasUserOfGenericModeParameters(partitionIndex)                                         (TRUE != FALSE)
#define BswM_HasGenericState(partitionIndex)                                                        (TRUE != FALSE)
#define BswM_HasImmediateUser(partitionIndex)                                                       (TRUE != FALSE)
#define BswM_HasOnInitOfImmediateUser(partitionIndex)                                               (TRUE != FALSE)
#define BswM_HasRulesIndEndIdxOfImmediateUser(partitionIndex)                                       (TRUE != FALSE)
#define BswM_HasRulesIndStartIdxOfImmediateUser(partitionIndex)                                     (TRUE != FALSE)
#define BswM_HasRulesIndUsedOfImmediateUser(partitionIndex)                                         (TRUE != FALSE)
#define BswM_HasInitActionLists(partitionIndex)                                                     (BswM_GetInitActionListsOfPCPartitionConfig(partitionIndex) != NULL_PTR)
#define BswM_HasInitGenVarAndInitAL(partitionIndex)                                                 (TRUE != FALSE)
#define BswM_HasInitValues(partitionIndex)                                                          (TRUE != FALSE)
#define BswM_HasInitialized(partitionIndex)                                                         (TRUE != FALSE)
#define BswM_HasModeNotificationFct(partitionIndex)                                                 (TRUE != FALSE)
#define BswM_HasModeRequestQueue(partitionIndex)                                                    (TRUE != FALSE)
#define BswM_HasPartitionIdentifiers()                                                              (TRUE != FALSE)
#define BswM_HasPCPartitionConfigIdxOfPartitionIdentifiers()                                        (TRUE != FALSE)
#define BswM_HasPartitionSNVOfPartitionIdentifiers()                                                (TRUE != FALSE)
#define BswM_HasQueueSemaphore(partitionIndex)                                                      (TRUE != FALSE)
#define BswM_HasQueueWritten(partitionIndex)                                                        (TRUE != FALSE)
#define BswM_HasRuleStates(partitionIndex)                                                          (TRUE != FALSE)
#define BswM_HasRules(partitionIndex)                                                               (BswM_GetRulesOfPCPartitionConfig(partitionIndex) != NULL_PTR)
#define BswM_HasActionListsFalseIdxOfRules(partitionIndex)                                          (TRUE != FALSE)
#define BswM_HasActionListsFalseUsedOfRules(partitionIndex)                                         (TRUE != FALSE)
#define BswM_HasActionListsTrueIdxOfRules(partitionIndex)                                           (TRUE != FALSE)
#define BswM_HasActionListsTrueUsedOfRules(partitionIndex)                                          (TRUE != FALSE)
#define BswM_HasExpressionsIdxOfRules(partitionIndex)                                               (TRUE != FALSE)
#define BswM_HasIdOfRules(partitionIndex)                                                           (TRUE != FALSE)
#define BswM_HasInitOfRules(partitionIndex)                                                         (TRUE != FALSE)
#define BswM_HasRuleStatesIdxOfRules(partitionIndex)                                                (TRUE != FALSE)
#define BswM_HasRulesInd(partitionIndex)                                                            (BswM_GetRulesIndOfPCPartitionConfig(partitionIndex) != NULL_PTR)
#define BswM_HasSizeOfActionItems(partitionIndex)                                                   (TRUE != FALSE)
#define BswM_HasSizeOfActionListQueue(partitionIndex)                                               (TRUE != FALSE)
#define BswM_HasSizeOfActionLists(partitionIndex)                                                   (TRUE != FALSE)
#define BswM_HasSizeOfActions(partitionIndex)                                                       (TRUE != FALSE)
#define BswM_HasSizeOfCanSMChannelMapping(partitionIndex)                                           (TRUE != FALSE)
#define BswM_HasSizeOfCanSMChannelState(partitionIndex)                                             (TRUE != FALSE)
#define BswM_HasSizeOfComDMHandlingDisableParameters(partitionIndex)                                (TRUE != FALSE)
#define BswM_HasSizeOfComDMHandlingEnableParameters(partitionIndex)                                 (TRUE != FALSE)
#define BswM_HasSizeOfComDMHandlingParameters(partitionIndex)                                       (TRUE != FALSE)
#define BswM_HasSizeOfComMAllowComParameters(partitionIndex)                                        (TRUE != FALSE)
#define BswM_HasSizeOfComMChannelMapping(partitionIndex)                                            (TRUE != FALSE)
#define BswM_HasSizeOfComMChannelState(partitionIndex)                                              (TRUE != FALSE)
#define BswM_HasSizeOfComMPncMapping(partitionIndex)                                                (TRUE != FALSE)
#define BswM_HasSizeOfComMPncState(partitionIndex)                                                  (TRUE != FALSE)
#define BswM_HasSizeOfComPduGroupHandlingParameters(partitionIndex)                                 (TRUE != FALSE)
#define BswM_HasSizeOfComPduGroupHandlingStartParameters(partitionIndex)                            (TRUE != FALSE)
#define BswM_HasSizeOfComPduGroupHandlingStopParameters(partitionIndex)                             (TRUE != FALSE)
#define BswM_HasSizeOfDcmComMapping(partitionIndex)                                                 (TRUE != FALSE)
#define BswM_HasSizeOfDcmComState(partitionIndex)                                                   (TRUE != FALSE)
#define BswM_HasSizeOfDeferredRules(partitionIndex)                                                 (TRUE != FALSE)
#define BswM_HasSizeOfEcuMModeMapping(partitionIndex)                                               (TRUE != FALSE)
#define BswM_HasSizeOfEcuMRunRequestMapping(partitionIndex)                                         (TRUE != FALSE)
#define BswM_HasSizeOfEcuMRunRequestState(partitionIndex)                                           (TRUE != FALSE)
#define BswM_HasSizeOfEcuMStateSwitchParameters(partitionIndex)                                     (TRUE != FALSE)
#define BswM_HasSizeOfExpressions(partitionIndex)                                                   (TRUE != FALSE)
#define BswM_HasSizeOfGenericMapping(partitionIndex)                                                (TRUE != FALSE)
#define BswM_HasSizeOfGenericModeParameters(partitionIndex)                                         (TRUE != FALSE)
#define BswM_HasSizeOfGenericState(partitionIndex)                                                  (TRUE != FALSE)
#define BswM_HasSizeOfImmediateUser(partitionIndex)                                                 (TRUE != FALSE)
#define BswM_HasSizeOfInitActionLists(partitionIndex)                                               (TRUE != FALSE)
#define BswM_HasSizeOfInitGenVarAndInitAL(partitionIndex)                                           (TRUE != FALSE)
#define BswM_HasSizeOfInitValues(partitionIndex)                                                    (TRUE != FALSE)
#define BswM_HasSizeOfModeNotificationFct(partitionIndex)                                           (TRUE != FALSE)
#define BswM_HasSizeOfModeRequestQueue(partitionIndex)                                              (TRUE != FALSE)
#define BswM_HasSizeOfPartitionIdentifiers()                                                        (TRUE != FALSE)
#define BswM_HasSizeOfRuleStates(partitionIndex)                                                    (TRUE != FALSE)
#define BswM_HasSizeOfRules(partitionIndex)                                                         (TRUE != FALSE)
#define BswM_HasSizeOfRulesInd(partitionIndex)                                                      (TRUE != FALSE)
#define BswM_HasSizeOfSwcModeRequestUpdateFct(partitionIndex)                                       (TRUE != FALSE)
#define BswM_HasSizeOfTimerControlParameters(partitionIndex)                                        (TRUE != FALSE)
#define BswM_HasSizeOfTimerState(partitionIndex)                                                    (TRUE != FALSE)
#define BswM_HasSizeOfTimerValue(partitionIndex)                                                    (TRUE != FALSE)
#define BswM_HasSwcModeRequestUpdateFct(partitionIndex)                                             (TRUE != FALSE)
#define BswM_HasTimerControlParameters(partitionIndex)                                              (BswM_GetTimerControlParametersOfPCPartitionConfig(partitionIndex) != NULL_PTR)
#define BswM_HasTimerOfTimerControlParameters(partitionIndex)                                       (TRUE != FALSE)
#define BswM_HasValueOfTimerControlParameters(partitionIndex)                                       (TRUE != FALSE)
#define BswM_HasTimerState(partitionIndex)                                                          (TRUE != FALSE)
#define BswM_HasTimerValue(partitionIndex)                                                          (TRUE != FALSE)
#define BswM_HasPCConfig()                                                                          (TRUE != FALSE)
#define BswM_HasPCPartitionConfigOfPCConfig()                                                       (TRUE != FALSE)
#define BswM_HasPartitionIdentifiersOfPCConfig()                                                    (TRUE != FALSE)
#define BswM_HasSizeOfPartitionIdentifiersOfPCConfig()                                              (TRUE != FALSE)
#define BswM_HasPCPartitionConfig()                                                                 (BswM_GetPCPartitionConfigOfPCConfig() != NULL_PTR)
#define BswM_HasActionItemsOfPCPartitionConfig(partitionIndex)                                      (TRUE != FALSE)
#define BswM_HasActionListQueueOfPCPartitionConfig(partitionIndex)                                  (TRUE != FALSE)
#define BswM_HasActionListsOfPCPartitionConfig(partitionIndex)                                      (TRUE != FALSE)
#define BswM_HasActionsOfPCPartitionConfig(partitionIndex)                                          (TRUE != FALSE)
#define BswM_HasCanSMChannelMappingOfPCPartitionConfig(partitionIndex)                              (TRUE != FALSE)
#define BswM_HasCanSMChannelStateOfPCPartitionConfig(partitionIndex)                                (TRUE != FALSE)
#define BswM_HasComDMHandlingDisableParametersOfPCPartitionConfig(partitionIndex)                   (TRUE != FALSE)
#define BswM_HasComDMHandlingEnableParametersOfPCPartitionConfig(partitionIndex)                    (TRUE != FALSE)
#define BswM_HasComDMHandlingParametersOfPCPartitionConfig(partitionIndex)                          (TRUE != FALSE)
#define BswM_HasComMAllowComParametersOfPCPartitionConfig(partitionIndex)                           (TRUE != FALSE)
#define BswM_HasComMChannelMappingOfPCPartitionConfig(partitionIndex)                               (TRUE != FALSE)
#define BswM_HasComMChannelStateOfPCPartitionConfig(partitionIndex)                                 (TRUE != FALSE)
#define BswM_HasComMPncMappingOfPCPartitionConfig(partitionIndex)                                   (TRUE != FALSE)
#define BswM_HasComMPncStateOfPCPartitionConfig(partitionIndex)                                     (TRUE != FALSE)
#define BswM_HasComPduGroupHandlingParametersOfPCPartitionConfig(partitionIndex)                    (TRUE != FALSE)
#define BswM_HasComPduGroupHandlingStartParametersOfPCPartitionConfig(partitionIndex)               (TRUE != FALSE)
#define BswM_HasComPduGroupHandlingStopParametersOfPCPartitionConfig(partitionIndex)                (TRUE != FALSE)
#define BswM_HasDcmComMappingOfPCPartitionConfig(partitionIndex)                                    (TRUE != FALSE)
#define BswM_HasDcmComStateOfPCPartitionConfig(partitionIndex)                                      (TRUE != FALSE)
#define BswM_HasDeferredRulesOfPCPartitionConfig(partitionIndex)                                    (TRUE != FALSE)
#define BswM_HasEcuMModeMappingOfPCPartitionConfig(partitionIndex)                                  (TRUE != FALSE)
#define BswM_HasEcuMModeStateOfPCPartitionConfig(partitionIndex)                                    (TRUE != FALSE)
#define BswM_HasEcuMRunRequestMappingOfPCPartitionConfig(partitionIndex)                            (TRUE != FALSE)
#define BswM_HasEcuMRunRequestStateOfPCPartitionConfig(partitionIndex)                              (TRUE != FALSE)
#define BswM_HasEcuMStateSwitchParametersOfPCPartitionConfig(partitionIndex)                        (TRUE != FALSE)
#define BswM_HasExpressionsOfPCPartitionConfig(partitionIndex)                                      (TRUE != FALSE)
#define BswM_HasForcedActionListPriorityOfPCPartitionConfig(partitionIndex)                         (TRUE != FALSE)
#define BswM_HasGenericMappingOfPCPartitionConfig(partitionIndex)                                   (TRUE != FALSE)
#define BswM_HasGenericModeParametersOfPCPartitionConfig(partitionIndex)                            (TRUE != FALSE)
#define BswM_HasGenericStateOfPCPartitionConfig(partitionIndex)                                     (TRUE != FALSE)
#define BswM_HasImmediateUserOfPCPartitionConfig(partitionIndex)                                    (TRUE != FALSE)
#define BswM_HasInitActionListsOfPCPartitionConfig(partitionIndex)                                  (TRUE != FALSE)
#define BswM_HasInitGenVarAndInitALOfPCPartitionConfig(partitionIndex)                              (TRUE != FALSE)
#define BswM_HasInitValuesOfPCPartitionConfig(partitionIndex)                                       (TRUE != FALSE)
#define BswM_HasInitializedOfPCPartitionConfig(partitionIndex)                                      (TRUE != FALSE)
#define BswM_HasModeNotificationFctOfPCPartitionConfig(partitionIndex)                              (TRUE != FALSE)
#define BswM_HasModeRequestQueueOfPCPartitionConfig(partitionIndex)                                 (TRUE != FALSE)
#define BswM_HasQueueSemaphoreOfPCPartitionConfig(partitionIndex)                                   (TRUE != FALSE)
#define BswM_HasQueueWrittenOfPCPartitionConfig(partitionIndex)                                     (TRUE != FALSE)
#define BswM_HasRuleStatesOfPCPartitionConfig(partitionIndex)                                       (TRUE != FALSE)
#define BswM_HasRulesIndOfPCPartitionConfig(partitionIndex)                                         (TRUE != FALSE)
#define BswM_HasRulesOfPCPartitionConfig(partitionIndex)                                            (TRUE != FALSE)
#define BswM_HasSizeOfActionItemsOfPCPartitionConfig(partitionIndex)                                (TRUE != FALSE)
#define BswM_HasSizeOfActionListQueueOfPCPartitionConfig(partitionIndex)                            (TRUE != FALSE)
#define BswM_HasSizeOfActionListsOfPCPartitionConfig(partitionIndex)                                (TRUE != FALSE)
#define BswM_HasSizeOfActionsOfPCPartitionConfig(partitionIndex)                                    (TRUE != FALSE)
#define BswM_HasSizeOfCanSMChannelMappingOfPCPartitionConfig(partitionIndex)                        (TRUE != FALSE)
#define BswM_HasSizeOfCanSMChannelStateOfPCPartitionConfig(partitionIndex)                          (TRUE != FALSE)
#define BswM_HasSizeOfComDMHandlingDisableParametersOfPCPartitionConfig(partitionIndex)             (TRUE != FALSE)
#define BswM_HasSizeOfComDMHandlingEnableParametersOfPCPartitionConfig(partitionIndex)              (TRUE != FALSE)
#define BswM_HasSizeOfComDMHandlingParametersOfPCPartitionConfig(partitionIndex)                    (TRUE != FALSE)
#define BswM_HasSizeOfComMAllowComParametersOfPCPartitionConfig(partitionIndex)                     (TRUE != FALSE)
#define BswM_HasSizeOfComMChannelMappingOfPCPartitionConfig(partitionIndex)                         (TRUE != FALSE)
#define BswM_HasSizeOfComMChannelStateOfPCPartitionConfig(partitionIndex)                           (TRUE != FALSE)
#define BswM_HasSizeOfComMPncMappingOfPCPartitionConfig(partitionIndex)                             (TRUE != FALSE)
#define BswM_HasSizeOfComMPncStateOfPCPartitionConfig(partitionIndex)                               (TRUE != FALSE)
#define BswM_HasSizeOfComPduGroupHandlingParametersOfPCPartitionConfig(partitionIndex)              (TRUE != FALSE)
#define BswM_HasSizeOfComPduGroupHandlingStartParametersOfPCPartitionConfig(partitionIndex)         (TRUE != FALSE)
#define BswM_HasSizeOfComPduGroupHandlingStopParametersOfPCPartitionConfig(partitionIndex)          (TRUE != FALSE)
#define BswM_HasSizeOfDcmComMappingOfPCPartitionConfig(partitionIndex)                              (TRUE != FALSE)
#define BswM_HasSizeOfDcmComStateOfPCPartitionConfig(partitionIndex)                                (TRUE != FALSE)
#define BswM_HasSizeOfDeferredRulesOfPCPartitionConfig(partitionIndex)                              (TRUE != FALSE)
#define BswM_HasSizeOfEcuMModeMappingOfPCPartitionConfig(partitionIndex)                            (TRUE != FALSE)
#define BswM_HasSizeOfEcuMRunRequestMappingOfPCPartitionConfig(partitionIndex)                      (TRUE != FALSE)
#define BswM_HasSizeOfEcuMRunRequestStateOfPCPartitionConfig(partitionIndex)                        (TRUE != FALSE)
#define BswM_HasSizeOfEcuMStateSwitchParametersOfPCPartitionConfig(partitionIndex)                  (TRUE != FALSE)
#define BswM_HasSizeOfExpressionsOfPCPartitionConfig(partitionIndex)                                (TRUE != FALSE)
#define BswM_HasSizeOfGenericMappingOfPCPartitionConfig(partitionIndex)                             (TRUE != FALSE)
#define BswM_HasSizeOfGenericModeParametersOfPCPartitionConfig(partitionIndex)                      (TRUE != FALSE)
#define BswM_HasSizeOfGenericStateOfPCPartitionConfig(partitionIndex)                               (TRUE != FALSE)
#define BswM_HasSizeOfImmediateUserOfPCPartitionConfig(partitionIndex)                              (TRUE != FALSE)
#define BswM_HasSizeOfInitActionListsOfPCPartitionConfig(partitionIndex)                            (TRUE != FALSE)
#define BswM_HasSizeOfInitGenVarAndInitALOfPCPartitionConfig(partitionIndex)                        (TRUE != FALSE)
#define BswM_HasSizeOfInitValuesOfPCPartitionConfig(partitionIndex)                                 (TRUE != FALSE)
#define BswM_HasSizeOfModeNotificationFctOfPCPartitionConfig(partitionIndex)                        (TRUE != FALSE)
#define BswM_HasSizeOfModeRequestQueueOfPCPartitionConfig(partitionIndex)                           (TRUE != FALSE)
#define BswM_HasSizeOfRuleStatesOfPCPartitionConfig(partitionIndex)                                 (TRUE != FALSE)
#define BswM_HasSizeOfRulesIndOfPCPartitionConfig(partitionIndex)                                   (TRUE != FALSE)
#define BswM_HasSizeOfRulesOfPCPartitionConfig(partitionIndex)                                      (TRUE != FALSE)
#define BswM_HasSizeOfSwcModeRequestUpdateFctOfPCPartitionConfig(partitionIndex)                    (TRUE != FALSE)
#define BswM_HasSizeOfTimerControlParametersOfPCPartitionConfig(partitionIndex)                     (TRUE != FALSE)
#define BswM_HasSizeOfTimerStateOfPCPartitionConfig(partitionIndex)                                 (TRUE != FALSE)
#define BswM_HasSizeOfTimerValueOfPCPartitionConfig(partitionIndex)                                 (TRUE != FALSE)
#define BswM_HasSwcModeRequestUpdateFctOfPCPartitionConfig(partitionIndex)                          (TRUE != FALSE)
#define BswM_HasTimerControlParametersOfPCPartitionConfig(partitionIndex)                           (TRUE != FALSE)
#define BswM_HasTimerStateOfPCPartitionConfig(partitionIndex)                                       (TRUE != FALSE)
#define BswM_HasTimerValueOfPCPartitionConfig(partitionIndex)                                       (TRUE != FALSE)
/** 
  \}
*/ 

/** 
  \defgroup  BswMPCIncrementDataMacros  BswM Increment Data Macros (PRE_COMPILE)
  \brief  These macros can be used to increment VAR data with numerical nature.
  \{
*/ 
#define BswM_IncActionListQueue(Index, partitionIndex)                                              BswM_GetActionListQueue(((Index)), (partitionIndex))++
#define BswM_IncCanSMChannelState(Index, partitionIndex)                                            BswM_GetCanSMChannelState(((Index)), (partitionIndex))++
#define BswM_IncComMChannelState(Index, partitionIndex)                                             BswM_GetComMChannelState(((Index)), (partitionIndex))++
#define BswM_IncComMPncState(Index, partitionIndex)                                                 BswM_GetComMPncState(((Index)), (partitionIndex))++
#define BswM_IncDcmComState(Index, partitionIndex)                                                  BswM_GetDcmComState(((Index)), (partitionIndex))++
#define BswM_IncEcuMModeState(partitionIndex)                                                       BswM_GetEcuMModeState(partitionIndex)++
#define BswM_IncEcuMRunRequestState(Index, partitionIndex)                                          BswM_GetEcuMRunRequestState(((Index)), (partitionIndex))++
#define BswM_IncForcedActionListPriority(partitionIndex)                                            BswM_GetForcedActionListPriority(partitionIndex)++
#define BswM_IncGenericState(Index, partitionIndex)                                                 BswM_GetGenericState(((Index)), (partitionIndex))++
#define BswM_IncModeRequestQueue(Index, partitionIndex)                                             BswM_GetModeRequestQueue(((Index)), (partitionIndex))++
#define BswM_IncQueueSemaphore(partitionIndex)                                                      BswM_GetQueueSemaphore(partitionIndex)++
#define BswM_IncRuleStates(Index, partitionIndex)                                                   BswM_GetRuleStates(((Index)), (partitionIndex))++
#define BswM_IncTimerState(Index, partitionIndex)                                                   BswM_GetTimerState(((Index)), (partitionIndex))++
#define BswM_IncTimerValue(Index, partitionIndex)                                                   BswM_GetTimerValue(((Index)), (partitionIndex))++
/** 
  \}
*/ 

/** 
  \defgroup  BswMPCDecrementDataMacros  BswM Decrement Data Macros (PRE_COMPILE)
  \brief  These macros can be used to decrement VAR data with numerical nature.
  \{
*/ 
#define BswM_DecActionListQueue(Index, partitionIndex)                                              BswM_GetActionListQueue(((Index)), (partitionIndex))--
#define BswM_DecCanSMChannelState(Index, partitionIndex)                                            BswM_GetCanSMChannelState(((Index)), (partitionIndex))--
#define BswM_DecComMChannelState(Index, partitionIndex)                                             BswM_GetComMChannelState(((Index)), (partitionIndex))--
#define BswM_DecComMPncState(Index, partitionIndex)                                                 BswM_GetComMPncState(((Index)), (partitionIndex))--
#define BswM_DecDcmComState(Index, partitionIndex)                                                  BswM_GetDcmComState(((Index)), (partitionIndex))--
#define BswM_DecEcuMModeState(partitionIndex)                                                       BswM_GetEcuMModeState(partitionIndex)--
#define BswM_DecEcuMRunRequestState(Index, partitionIndex)                                          BswM_GetEcuMRunRequestState(((Index)), (partitionIndex))--
#define BswM_DecForcedActionListPriority(partitionIndex)                                            BswM_GetForcedActionListPriority(partitionIndex)--
#define BswM_DecGenericState(Index, partitionIndex)                                                 BswM_GetGenericState(((Index)), (partitionIndex))--
#define BswM_DecModeRequestQueue(Index, partitionIndex)                                             BswM_GetModeRequestQueue(((Index)), (partitionIndex))--
#define BswM_DecQueueSemaphore(partitionIndex)                                                      BswM_GetQueueSemaphore(partitionIndex)--
#define BswM_DecRuleStates(Index, partitionIndex)                                                   BswM_GetRuleStates(((Index)), (partitionIndex))--
#define BswM_DecTimerState(Index, partitionIndex)                                                   BswM_GetTimerState(((Index)), (partitionIndex))--
#define BswM_DecTimerValue(Index, partitionIndex)                                                   BswM_GetTimerValue(((Index)), (partitionIndex))--
/** 
  \}
*/ 

/** 
  \defgroup  BswMPCAddDataMacros  BswM Add Data Macros (PRE_COMPILE)
  \brief  These macros can be used to add VAR data with numerical nature.
  \{
*/ 
#define BswM_AddActionListQueue(Index, Value, partitionIndex)                                       BswM_SetActionListQueue(Index, (BswM_GetActionListQueue(((Index)), (partitionIndex)) + Value), partitionIndex)
#define BswM_AddCanSMChannelState(Index, Value, partitionIndex)                                     BswM_SetCanSMChannelState(Index, (BswM_GetCanSMChannelState(((Index)), (partitionIndex)) + Value), partitionIndex)
#define BswM_AddComMChannelState(Index, Value, partitionIndex)                                      BswM_SetComMChannelState(Index, (BswM_GetComMChannelState(((Index)), (partitionIndex)) + Value), partitionIndex)
#define BswM_AddComMPncState(Index, Value, partitionIndex)                                          BswM_SetComMPncState(Index, (BswM_GetComMPncState(((Index)), (partitionIndex)) + Value), partitionIndex)
#define BswM_AddDcmComState(Index, Value, partitionIndex)                                           BswM_SetDcmComState(Index, (BswM_GetDcmComState(((Index)), (partitionIndex)) + Value), partitionIndex)
#define BswM_AddEcuMModeState(Value, partitionIndex)                                                BswM_SetEcuMModeState((BswM_GetEcuMModeState(partitionIndex) + Value), partitionIndex)
#define BswM_AddEcuMRunRequestState(Index, Value, partitionIndex)                                   BswM_SetEcuMRunRequestState(Index, (BswM_GetEcuMRunRequestState(((Index)), (partitionIndex)) + Value), partitionIndex)
#define BswM_AddForcedActionListPriority(Value, partitionIndex)                                     BswM_SetForcedActionListPriority((BswM_GetForcedActionListPriority(partitionIndex) + Value), partitionIndex)
#define BswM_AddGenericState(Index, Value, partitionIndex)                                          BswM_SetGenericState(Index, (BswM_GetGenericState(((Index)), (partitionIndex)) + Value), partitionIndex)
#define BswM_AddModeRequestQueue(Index, Value, partitionIndex)                                      BswM_SetModeRequestQueue(Index, (BswM_GetModeRequestQueue(((Index)), (partitionIndex)) + Value), partitionIndex)
#define BswM_AddQueueSemaphore(Value, partitionIndex)                                               BswM_SetQueueSemaphore((BswM_GetQueueSemaphore(partitionIndex) + Value), partitionIndex)
#define BswM_AddRuleStates(Index, Value, partitionIndex)                                            BswM_SetRuleStates(Index, (BswM_GetRuleStates(((Index)), (partitionIndex)) + Value), partitionIndex)
#define BswM_AddTimerState(Index, Value, partitionIndex)                                            BswM_SetTimerState(Index, (BswM_GetTimerState(((Index)), (partitionIndex)) + Value), partitionIndex)
#define BswM_AddTimerValue(Index, Value, partitionIndex)                                            BswM_SetTimerValue(Index, (BswM_GetTimerValue(((Index)), (partitionIndex)) + Value), partitionIndex)
/** 
  \}
*/ 

/** 
  \defgroup  BswMPCSubstractDataMacros  BswM Substract Data Macros (PRE_COMPILE)
  \brief  These macros can be used to substract VAR data with numerical nature.
  \{
*/ 
#define BswM_SubActionListQueue(Index, Value, partitionIndex)                                       BswM_SetActionListQueue(Index, (BswM_GetActionListQueue(((Index)), (partitionIndex)) - Value), partitionIndex)
#define BswM_SubCanSMChannelState(Index, Value, partitionIndex)                                     BswM_SetCanSMChannelState(Index, (BswM_GetCanSMChannelState(((Index)), (partitionIndex)) - Value), partitionIndex)
#define BswM_SubComMChannelState(Index, Value, partitionIndex)                                      BswM_SetComMChannelState(Index, (BswM_GetComMChannelState(((Index)), (partitionIndex)) - Value), partitionIndex)
#define BswM_SubComMPncState(Index, Value, partitionIndex)                                          BswM_SetComMPncState(Index, (BswM_GetComMPncState(((Index)), (partitionIndex)) - Value), partitionIndex)
#define BswM_SubDcmComState(Index, Value, partitionIndex)                                           BswM_SetDcmComState(Index, (BswM_GetDcmComState(((Index)), (partitionIndex)) - Value), partitionIndex)
#define BswM_SubEcuMModeState(Value, partitionIndex)                                                BswM_SetEcuMModeState((BswM_GetEcuMModeState(partitionIndex) - Value), partitionIndex)
#define BswM_SubEcuMRunRequestState(Index, Value, partitionIndex)                                   BswM_SetEcuMRunRequestState(Index, (BswM_GetEcuMRunRequestState(((Index)), (partitionIndex)) - Value), partitionIndex)
#define BswM_SubForcedActionListPriority(Value, partitionIndex)                                     BswM_SetForcedActionListPriority((BswM_GetForcedActionListPriority(partitionIndex) - Value), partitionIndex)
#define BswM_SubGenericState(Index, Value, partitionIndex)                                          BswM_SetGenericState(Index, (BswM_GetGenericState(((Index)), (partitionIndex)) - Value), partitionIndex)
#define BswM_SubModeRequestQueue(Index, Value, partitionIndex)                                      BswM_SetModeRequestQueue(Index, (BswM_GetModeRequestQueue(((Index)), (partitionIndex)) - Value), partitionIndex)
#define BswM_SubQueueSemaphore(Value, partitionIndex)                                               BswM_SetQueueSemaphore((BswM_GetQueueSemaphore(partitionIndex) - Value), partitionIndex)
#define BswM_SubRuleStates(Index, Value, partitionIndex)                                            BswM_SetRuleStates(Index, (BswM_GetRuleStates(((Index)), (partitionIndex)) - Value), partitionIndex)
#define BswM_SubTimerState(Index, Value, partitionIndex)                                            BswM_SetTimerState(Index, (BswM_GetTimerState(((Index)), (partitionIndex)) - Value), partitionIndex)
#define BswM_SubTimerValue(Index, Value, partitionIndex)                                            BswM_SetTimerValue(Index, (BswM_GetTimerValue(((Index)), (partitionIndex)) - Value), partitionIndex)
/** 
  \}
*/ 

  /* PRQA L:Macros_3453 */
/** 
  \}
*/ 

/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL ACCESS FUNCTION MACROS
**********************************************************************************************************************/


/** 
  \defgroup  DataAccessMacros  Data Access Macros
  \brief  generated data access macros to abstract the generated data from the code to read and write CONST or VAR data.
  \{
*/ 
  /* PRQA S 3453 Macros_3453 */  /* MD_MSR_FctLikeMacro */
/**********************************************************************************************************************
  CONFIGURATION CLASS: POST_BUILD
  SECTION: GLOBAL FUNCTION MACROS
**********************************************************************************************************************/
  /* PRQA L:Macros_3453 */
/** 
  \}
*/ 

/**********************************************************************************************************************
  CONFIGURATION CLASS: POST_BUILD
  SECTION: GLOBAL ACCESS FUNCTION MACROS
**********************************************************************************************************************/


#define BswM_GetPartitionContext() 0u


/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
**********************************************************************************************************************/
/* PRQA S 3449, 3451 EXTERNDECLARATIONS */ /* MD_BSWM_3449, MD_BSWM_3451 */
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL DATA PROTOTYPES
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
extern CONST(BswM_ActionItemsType, BSWM_CONST) BswM_ActionItemsLeft[114];
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
extern CONST(BswM_ActionItemsType, BSWM_CONST) BswM_ActionItemsRight[114];
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
extern CONST(BswM_ActionListsType, BSWM_CONST) BswM_ActionListsLeft[30];
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
extern CONST(BswM_ActionListsType, BSWM_CONST) BswM_ActionListsRight[30];
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
extern CONST(BswM_ActionFuncType, BSWM_CONST) BswM_ActionsLeft[72];
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
extern CONST(BswM_ActionFuncType, BSWM_CONST) BswM_ActionsRight[72];
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
extern CONST(BswM_CanSMChannelMappingType, BSWM_CONST) BswM_CanSMChannelMappingLeft[1];
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
extern CONST(BswM_CanSMChannelMappingType, BSWM_CONST) BswM_CanSMChannelMappingRight[1];
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
extern CONST(BswM_ComDMHandlingDisableParametersType, BSWM_CONST) BswM_ComDMHandlingDisableParametersLeft[2];  /* PRQA S 0777 */  /* MD_MSR_Rule5.1 */
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
extern CONST(BswM_ComDMHandlingDisableParametersType, BSWM_CONST) BswM_ComDMHandlingDisableParametersRight[2];  /* PRQA S 0777 */  /* MD_MSR_Rule5.1 */
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
extern CONST(BswM_ComDMHandlingEnableParametersType, BSWM_CONST) BswM_ComDMHandlingEnableParametersLeft[2];  /* PRQA S 0777 */  /* MD_MSR_Rule5.1 */
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
extern CONST(BswM_ComDMHandlingEnableParametersType, BSWM_CONST) BswM_ComDMHandlingEnableParametersRight[2];  /* PRQA S 0777 */  /* MD_MSR_Rule5.1 */
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
extern CONST(BswM_ComDMHandlingParametersType, BSWM_CONST) BswM_ComDMHandlingParameters[4];
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
extern CONST(BswM_ComMAllowComParametersType, BSWM_CONST) BswM_ComMAllowComParametersLeft[2];
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
extern CONST(BswM_ComMAllowComParametersType, BSWM_CONST) BswM_ComMAllowComParametersRight[2];  /* PRQA S 0777 */  /* MD_MSR_Rule5.1 */
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
extern CONST(BswM_ComMChannelMappingType, BSWM_CONST) BswM_ComMChannelMappingLeft[1];
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
extern CONST(BswM_ComMChannelMappingType, BSWM_CONST) BswM_ComMChannelMappingRight[1];
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
extern CONST(BswM_ComMPncMappingType, BSWM_CONST) BswM_ComMPncMapping[2];
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
extern CONST(BswM_ComPduGroupHandlingParametersType, BSWM_CONST) BswM_ComPduGroupHandlingParameters[10];  /* PRQA S 0777 */  /* MD_MSR_Rule5.1 */
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
extern CONST(BswM_ComPduGroupHandlingStartParametersType, BSWM_CONST) BswM_ComPduGroupHandlingStartParametersLeft[5];  /* PRQA S 0777 */  /* MD_MSR_Rule5.1 */
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
extern CONST(BswM_ComPduGroupHandlingStartParametersType, BSWM_CONST) BswM_ComPduGroupHandlingStartParametersRight[5];  /* PRQA S 0777 */  /* MD_MSR_Rule5.1 */
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
extern CONST(BswM_ComPduGroupHandlingStopParametersType, BSWM_CONST) BswM_ComPduGroupHandlingStopParametersLeft[5];  /* PRQA S 0777 */  /* MD_MSR_Rule5.1 */
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
extern CONST(BswM_ComPduGroupHandlingStopParametersType, BSWM_CONST) BswM_ComPduGroupHandlingStopParametersRight[5];  /* PRQA S 0777 */  /* MD_MSR_Rule5.1 */
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
extern CONST(BswM_DcmComMappingType, BSWM_CONST) BswM_DcmComMappingLeft[1];
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
extern CONST(BswM_DcmComMappingType, BSWM_CONST) BswM_DcmComMappingRight[1];
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
extern CONST(BswM_DeferredRulesType, BSWM_CONST) BswM_DeferredRulesLeft[8];
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
extern CONST(BswM_DeferredRulesType, BSWM_CONST) BswM_DeferredRulesRight[8];
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
extern CONST(BswM_EcuMRunRequestMappingType, BSWM_CONST) BswM_EcuMRunRequestMapping[2];
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
extern CONST(BswM_EcuMStateSwitchParametersType, BSWM_CONST) BswM_EcuMStateSwitchParameters[3];
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
extern CONST(BswM_ExpressionFuncType, BSWM_CONST) BswM_ExpressionsLeft[35];
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
extern CONST(BswM_ExpressionFuncType, BSWM_CONST) BswM_ExpressionsRight[35];
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
extern CONST(BswM_GenericMappingType, BSWM_CONST) BswM_GenericMapping[4];
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
extern CONST(BswM_GenericModeParametersType, BSWM_CONST) BswM_GenericModeParameters[7];
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
extern CONST(BswM_ImmediateUserType, BSWM_CONST) BswM_ImmediateUser[7];
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
extern CONST(BswM_InitActionListsType, BSWM_CONST) BswM_InitActionListsLeft[1];
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
extern CONST(BswM_InitActionListsType, BSWM_CONST) BswM_InitActionListsRight[1];
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
extern CONST(BswM_InitGenVarAndInitALType, BSWM_CONST) BswM_InitGenVarAndInitAL[1];
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
extern CONST(BswM_InitValuesType, BSWM_CONST) BswM_InitValues[4];
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
extern CONST(BswM_PartitionFunctionType, BSWM_CONST) BswM_ModeNotificationFct[1];
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
extern CONST(BswM_PartitionIdentifiersType, BSWM_CONST) BswM_PartitionIdentifiers[1];
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
extern CONST(BswM_RulesType, BSWM_CONST) BswM_RulesLeft[20];
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
extern CONST(BswM_RulesType, BSWM_CONST) BswM_RulesRight[20];
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
extern CONST(BswM_RulesIndType, BSWM_CONST) BswM_RulesIndLeft[25];
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
extern CONST(BswM_RulesIndType, BSWM_CONST) BswM_RulesIndRight[25];
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
extern CONST(BswM_PartitionFunctionType, BSWM_CONST) BswM_SwcModeRequestUpdateFct[1];
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
extern CONST(BswM_TimerControlParametersType, BSWM_CONST) BswM_TimerControlParametersLeft[1];
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
extern CONST(BswM_TimerControlParametersType, BSWM_CONST) BswM_TimerControlParametersRight[1];  /* PRQA S 0777 */  /* MD_MSR_Rule5.1 */
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
extern VAR(BswM_ActionListQueueUType, BSWM_VAR_NO_INIT) BswM_ActionListQueue;  /* PRQA S 0759 */  /* MD_CSL_Union */
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
extern VAR(CanSM_BswMCurrentStateType, BSWM_VAR_NO_INIT) BswM_CanSMChannelState[1];
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
extern VAR(ComM_ModeType, BSWM_VAR_NO_INIT) BswM_ComMChannelState[1];
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
extern VAR(ComM_PncModeType, BSWM_VAR_NO_INIT) BswM_ComMPncState[2];
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
extern VAR(Dcm_CommunicationModeType, BSWM_VAR_NO_INIT) BswM_DcmComState[1];
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
extern VAR(BswM_EcuMModeStateType, BSWM_VAR_NO_INIT) BswM_EcuMModeState;
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
extern VAR(EcuM_RunStatusType, BSWM_VAR_NO_INIT) BswM_EcuMRunRequestState[2];
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
extern VAR(BswM_ForcedActionListPriorityType, BSWM_VAR_NO_INIT) BswM_ForcedActionListPriority;
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
extern VAR(BswM_ModeType, BSWM_VAR_NO_INIT) BswM_GenericState[4];
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
extern VAR(BswM_InitializedType, BSWM_VAR_NO_INIT) BswM_Initialized;
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
extern VAR(BswM_ModeRequestQueueType, BSWM_VAR_NO_INIT) BswM_ModeRequestQueue[7];
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
extern VAR(BswM_QueueSemaphoreType, BSWM_VAR_NO_INIT) BswM_QueueSemaphore;
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
extern VAR(BswM_QueueWrittenType, BSWM_VAR_NO_INIT) BswM_QueueWritten;
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
extern VAR(BswM_RuleStatesUType, BSWM_VAR_NO_INIT) BswM_RuleStates;  /* PRQA S 0759 */  /* MD_CSL_Union */
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
extern VAR(BswM_TimerStateUType, BSWM_VAR_NO_INIT) BswM_TimerState;  /* PRQA S 0759 */  /* MD_CSL_Union */
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
extern VAR(BswM_TimerValueUType, BSWM_VAR_NO_INIT) BswM_TimerValue;  /* PRQA S 0759 */  /* MD_CSL_Union */
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
extern CONST(BswM_PCConfigsType, BSWM_CONST) BswM_PCConfig;
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
extern CONST(BswM_PCPartitionConfigType, BSWM_CONST) BswM_PCPartitionConfigLeft[1];
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
extern CONST(BswM_PCPartitionConfigType, BSWM_CONST) BswM_PCPartitionConfigRight[1];
#define BSWM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "BswM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */



/**********************************************************************************************************************
  CONFIGURATION CLASS: POST_BUILD
  SECTION: GLOBAL DATA PROTOTYPES
**********************************************************************************************************************/

/* PRQA L:EXTERNDECLARATIONS */


#define BSWM_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "BswM_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#if (BSWM_USE_INIT_POINTER == STD_ON)
extern  P2CONST(BswM_ConfigType, AUTOMATIC, BSWM_PBCFG) BswM_ConfigPtr;
#endif

#define BSWM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "BswM_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define BswM_IsPreInitialized()                     (BswM_PreInitialized) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#define BswM_SetPreInitialized(Value)               (BswM_IsPreInitialized()) = (Value) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL FUNCTION PROTOTYPES
**********************************************************************************************************************/


/**********************************************************************************************************************
  CONFIGURATION CLASS: POST_BUILD
  SECTION: GLOBAL FUNCTION PROTOTYPES
**********************************************************************************************************************/


/* -----------------------------------------------------------------------------
    &&&~ EXTERNAL DECLARATIONS
 ----------------------------------------------------------------------------- */

#define BSWM_START_SEC_CODE
#include "BswM_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! \addtogroup    BswMGeneratedFunctions BswM Generated Functions
 * \{
 */
/* PRQA S 0779 FUNCTIONDECLARATIONS */ /* MD_MSR_Rule5.2_0779 */

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
extern FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_ComPduGroupHandling(BswM_HandleType handleId, BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
extern FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_ComMAllowCom(BswM_HandleType handleId, BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
extern FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_EcuMStateSwitch(BswM_HandleType handleId, BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
extern FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_GenericMode(BswM_HandleType handleId, BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
extern FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_TimerControl(BswM_HandleType handleId, BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
extern FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_ComDMHandling(BswM_HandleType handleId, BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
/*! \} */ /* End of sharing description for BswMActionFunctions */
/*! \} */ /* End of group BswMActionFunctions */
/* PRQA L:FUNCTIONDECLARATIONS */
/*! \} */ /* End of group BswMGeneratedFunctions */





#if (BSWM_FUNCTION_BASED == STD_OFF)
/**********************************************************************************************************************
 *  BswM_Action_ActionListHandler()
 **********************************************************************************************************************/
/*!
 * \brief       Executes an action list.
 * \details     Executes all actions of an action list.
 * \param[in]   handleId  Id of the action list to execute.
 * \param[in]   partitionIdx Index of current partition Context
 * \return      E_OK      Action list was completely executed.
 * \return      E_NOT_OK  Action list was aborted because an action failed.
 * \pre         -
 * \context     ANY
 * \reentrant   TRUE
 * \synchronous TRUE
 */
extern FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_ActionListHandler(BswM_HandleType handleId, BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
#endif

#if ((BSWM_RULES == STD_ON)  && (BSWM_FUNCTION_BASED == STD_OFF))
/**********************************************************************************************************************
 *  BswM_ArbitrateRule()
 **********************************************************************************************************************/
/*!
 * \brief       Arbitrates a rule.
 * \details     Evaluates the logical expression of the rule and determines the action list to execute.
 * \param[in]   ruleId  Id of the rule to arbitrate
 * \param[in]   partitionIdx  Index of current partition Context
 * \return      ID of action list to execute (BSWM_NO_ACTIONLIST if no action list shall be executed)
 * \pre         -
 * \context     ANY
 * \reentrant   TRUE
 * \synchronous TRUE
 */
extern FUNC(BswM_SizeOfActionListsType, BSWM_CODE) BswM_ArbitrateRule(BswM_HandleType ruleId, BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
#endif

#if(BSWM_IMMEDIATEUSER == STD_ON)
# if (BSWM_DEV_ERROR_REPORT == STD_ON)
/**********************************************************************************************************************
 *  BswM_ImmediateModeRequest()
 **********************************************************************************************************************/
/*!
 * \brief       Processes an immediate mode request.
 * \details     Queues mode request and starts arbitration of depending rules if no other request is currently active.
 * \param[in]   start   Handle of first mode request.
 * \param[in]   end     Handle of last mode request.
 * \param[in]   sid     Service Id of calling API. Only available if BSWM_DEV_ERROR_REPORT is STD_ON.
 * \param[in]   partitionIdx Index of current partition Context
 * \pre         -
 * \context     ANY
 * \reentrant   TRUE
 * \synchronous TRUE
 */
extern FUNC(void, BSWM_CODE) BswM_ImmediateModeRequest(BswM_SizeOfImmediateUserType start, BswM_SizeOfImmediateUserType end, uint8 sid, BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
# else
extern FUNC(void, BSWM_CODE) BswM_ImmediateModeRequest(BswM_SizeOfImmediateUserType start, BswM_SizeOfImmediateUserType end, BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
# endif
#endif

#define BSWM_STOP_SEC_CODE
#include "BswM_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#endif /* BSWM_PRIVATE_CFG_H */


