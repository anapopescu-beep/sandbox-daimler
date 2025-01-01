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
 *              File: BswM_Cfg.h
 *   Generation Time: 2024-02-15 14:31:25
 *           Project: StartApplication - Version 1.0
 *          Delivery: CBD2200333_D05
 *      Tool Version: DaVinci Configurator Classic 5.25.50 SP5
 *
 *
 *********************************************************************************************************************/


#if !defined(BSWM_CFG_H)
#define BSWM_CFG_H

/* -----------------------------------------------------------------------------
    &&&~ INCLUDE
 ----------------------------------------------------------------------------- */
#include "Std_Types.h"
#include "ComStack_Types.h"
#include "BswM_ComM.h"
#include "BswM_CanSM.h"
#include "BswM_Dcm.h"
#include "BswM_EcuM.h"
#include "BswM_NvM.h"
#include "BswM_PduR.h"
#include "Rte_BswM_Type.h"
#include "Com_Types.h" 
#include "EcuM_Generated_Types.h" 
#include "Dem.h" 






/* -----------------------------------------------------------------------------
    &&&~ GENERAL DEFINES
 ----------------------------------------------------------------------------- */
#ifndef BSWM_DEV_ERROR_DETECT
#define BSWM_DEV_ERROR_DETECT STD_ON
#endif
#ifndef BSWM_DEV_ERROR_REPORT
#define BSWM_DEV_ERROR_REPORT STD_OFF
#endif
#ifndef BSWM_USE_DUMMY_STATEMENT
#define BSWM_USE_DUMMY_STATEMENT STD_OFF /* /MICROSAR/vSet/vSetGeneral/vSetDummyStatementKind */
#endif
#ifndef BSWM_DUMMY_STATEMENT
#define BSWM_DUMMY_STATEMENT(v)  /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */  /* /MICROSAR/vSet/vSetGeneral/vSetDummyStatementKind */
#endif
#ifndef BSWM_DUMMY_STATEMENT_CONST
#define BSWM_DUMMY_STATEMENT_CONST(v)  /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */  /* /MICROSAR/vSet/vSetGeneral/vSetDummyStatementKind */
#endif
#ifndef BSWM_ATOMIC_BIT_ACCESS_IN_BITFIELD
#define BSWM_ATOMIC_BIT_ACCESS_IN_BITFIELD STD_OFF /* /MICROSAR/EcuC/EcucGeneral/AtomicBitAccessInBitfield */
#endif
#ifndef BSWM_ATOMIC_VARIABLE_ACCESS
#define BSWM_ATOMIC_VARIABLE_ACCESS 32u /* /MICROSAR/EcuC/EcucGeneral/AtomicVariableAccess */
#endif
#ifndef BSWM_PROCESSOR_TC322L
#define BSWM_PROCESSOR_TC322L
#endif
#ifndef BSWM_COMP_TASKING
#define BSWM_COMP_TASKING
#endif
#ifndef BSWM_GEN_GENERATOR_MSR
#define BSWM_GEN_GENERATOR_MSR
#endif
#ifndef BSWM_CPUTYPE_BITORDER_LSB2MSB
#define BSWM_CPUTYPE_BITORDER_LSB2MSB /* /MICROSAR/vSet/vSetPlatform/vSetBitOrder */
#endif
#ifndef BSWM_CONFIGURATION_VARIANT_PRECOMPILE
#define BSWM_CONFIGURATION_VARIANT_PRECOMPILE 1
#endif
#ifndef BSWM_CONFIGURATION_VARIANT_LINKTIME
#define BSWM_CONFIGURATION_VARIANT_LINKTIME 2
#endif
#ifndef BSWM_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE
#define BSWM_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE 3
#endif
#ifndef BSWM_CONFIGURATION_VARIANT
#define BSWM_CONFIGURATION_VARIANT BSWM_CONFIGURATION_VARIANT_PRECOMPILE
#endif
#ifndef BSWM_POSTBUILD_VARIANT_SUPPORT
#define BSWM_POSTBUILD_VARIANT_SUPPORT STD_ON
#endif


#if !defined (BSWM_DUMMY_STATEMENT)
# define BSWM_DUMMY_STATEMENT(statement) (void)statement
#endif

/* -----------------------------------------------------------------------------
    &&&~ CONFIGURATION DEFINES
 ----------------------------------------------------------------------------- */

/* START of Checksum include for */
/* START of Checksum include for - SysService_Asr4BswMCfg5PrecompileCRC */

#define BSWM_MODE_CHECK                      STD_ON
#define BSWM_ENABLE_CANSM                    STD_ON
#define BSWM_ENABLE_FRSM                     STD_OFF
#define BSWM_ENABLE_LINSM                    STD_OFF
#define BSWM_ENABLE_ETHIF                    STD_OFF
#define BSWM_ENABLE_ETHSM                    STD_OFF
#define BSWM_ENABLE_LINTP                    STD_OFF
#define BSWM_ENABLE_DCM                      STD_ON
#define BSWM_ENABLE_NVM                      STD_ON
#define BSWM_ENABLE_ECUM                     STD_ON
#define BSWM_ENABLE_COMM                     STD_ON
#define BSWM_ENABLE_J1939DCM                 STD_OFF
#define BSWM_ENABLE_J1939NM                  STD_OFF
#define BSWM_ENABLE_SD                       STD_OFF
#define BSWM_ENABLE_NM                       STD_OFF
#define BSWM_ENABLE_PDUR                     STD_ON
#define BSWM_ENABLE_WDGM                     STD_ON
#define BSWM_ENABLE_RULE_CONTROL             STD_OFF
#define BSWM_VERSION_INFO_API                STD_OFF
#define BSWM_COMM_PNC_SUPPORT                STD_ON
#define BSWM_COMM_INITIATE_RESET             STD_ON
#define BSWM_CHANNEL_COUNT                   2u
#define BSWM_WAKEUP_SOURCE_COUNT             6u
#define BSWM_IPDU_GROUP_CONTROL              STD_OFF
#define BSWM_ECUM_MODE_HANDLING              STD_ON
#define BSWM_MULTIPARTITION                  STD_OFF



/* END of Checksum include for - SysService_Asr4BswMCfg5PrecompileCRC */

/* END of Checksum include for */

/* -----------------------------------------------------------------------------
    &&&~ RULE DEFINES
 ----------------------------------------------------------------------------- */
#define BswMConf_BswMRule_BswMRule_SwcDiagComMState (0) 
#define BswMConf_BswMRule_CC_RBTM_FL_BODY3_8uqv9blm85ehm0msat385m76v_03d5f5f6_PNC_00_MAPPING_b2c42696_RX (13) 
#define BswMConf_BswMRule_CC_RBTM_FL_BODY3_8uqv9blm85ehm0msat385m76v_03d5f5f6_PNC_00_MAPPING_b2c42696_RX_DM (14) 
#define BswMConf_BswMRule_CC_RBTM_FL_BODY3_8uqv9blm85ehm0msat385m76v_03d5f5f6_PNC_00_MAPPING_b2c42696_TX (15) 
#define BswMConf_BswMRule_CC_RBTM_FL_BODY3_8uqv9blm85ehm0msat385m76v_03d5f5f6_PNC_20_MAPPING_796df885_RX (16) 
#define BswMConf_BswMRule_CC_RBTM_FL_BODY3_8uqv9blm85ehm0msat385m76v_03d5f5f6_PNC_20_MAPPING_796df885_RX_DM (17) 
#define BswMConf_BswMRule_CC_RBTM_FL_BODY3_8uqv9blm85ehm0msat385m76v_03d5f5f6_PNC_20_MAPPING_796df885_TX (18) 
#define BswMConf_BswMRule_CC_RBTM_FL_BODY3_8uqv9blm85ehm0msat385m76v_03d5f5f6_TX (19) 
#define BswMConf_BswMRule_CC_RBTM_FR_BODY3_4xwwtd59665s787n6ctawh7k8_23a94727_PNC_00_MAPPING_b2c42696_RX (13) 
#define BswMConf_BswMRule_CC_RBTM_FR_BODY3_4xwwtd59665s787n6ctawh7k8_23a94727_PNC_00_MAPPING_b2c42696_RX_DM (14) 
#define BswMConf_BswMRule_CC_RBTM_FR_BODY3_4xwwtd59665s787n6ctawh7k8_23a94727_PNC_00_MAPPING_b2c42696_TX (15) 
#define BswMConf_BswMRule_CC_RBTM_FR_BODY3_4xwwtd59665s787n6ctawh7k8_23a94727_PNC_20_MAPPING_796df885_RX (16) 
#define BswMConf_BswMRule_CC_RBTM_FR_BODY3_4xwwtd59665s787n6ctawh7k8_23a94727_PNC_20_MAPPING_796df885_RX_DM (17) 
#define BswMConf_BswMRule_CC_RBTM_FR_BODY3_4xwwtd59665s787n6ctawh7k8_23a94727_PNC_20_MAPPING_796df885_TX (18) 
#define BswMConf_BswMRule_CC_RBTM_FR_BODY3_4xwwtd59665s787n6ctawh7k8_23a94727_TX (19) 
#define BswMConf_BswMRule_ESH_DemInit (1) 
#define BswMConf_BswMRule_ESH_InitToWakeup (2) 
#define BswMConf_BswMRule_ESH_PostRun (3) 
#define BswMConf_BswMRule_ESH_PostRunNested (4) 
#define BswMConf_BswMRule_ESH_PostRunToPrepNested (5) 
#define BswMConf_BswMRule_ESH_PrepToWait (6) 
#define BswMConf_BswMRule_ESH_RunToPostRun (7) 
#define BswMConf_BswMRule_ESH_RunToPostRunNested (8) 
#define BswMConf_BswMRule_ESH_WaitToShutdown (9) 
#define BswMConf_BswMRule_ESH_WaitToWakeup (10) 
#define BswMConf_BswMRule_ESH_WakeupToPrep (11) 
#define BswMConf_BswMRule_ESH_WakeupToRun (12) 


/* -----------------------------------------------------------------------------
    &&&~ GENERIC DEFINES
 ----------------------------------------------------------------------------- */
#define BSWM_GENERIC_ESH_ComMPendingRequests 232u 
#define BSWM_GENERIC_ESH_DemInitStatus       231u 
#define BSWM_GENERIC_ESH_DemPostRunRequested 233u 
#define BSWM_GENERIC_ESH_State               230u 

#define BSWM_GENERICVALUE_ESH_ComMPendingRequests_ESH_COMM_NO_REQUEST      0x0000u 
#define BSWM_GENERICVALUE_ESH_ComMPendingRequests_ESH_COMM_PENDING_REQUEST 0x0001u 
#define BSWM_GENERICVALUE_ESH_DemInitStatus_DEM_INITIALIZED                0x0000u 
#define BSWM_GENERICVALUE_ESH_DemInitStatus_DEM_NOT_INITIALIZED            0x0001u 
#define BSWM_GENERICVALUE_ESH_DemPostRunRequested_FALSE                    0x0001u 
#define BSWM_GENERICVALUE_ESH_DemPostRunRequested_TRUE                     0x0000u 
#define BSWM_GENERICVALUE_ESH_State_ESH_INIT                               0x0000u 
#define BSWM_GENERICVALUE_ESH_State_ESH_POST_RUN                           0x0002u 
#define BSWM_GENERICVALUE_ESH_State_ESH_PREP_SHUTDOWN                      0x0003u 
#define BSWM_GENERICVALUE_ESH_State_ESH_RUN                                0x0001u 
#define BSWM_GENERICVALUE_ESH_State_ESH_SHUTDOWN                           0x0005u 
#define BSWM_GENERICVALUE_ESH_State_ESH_WAIT_FOR_NVM                       0x0004u 
#define BSWM_GENERICVALUE_ESH_State_ESH_WAKEUP                             0x0006u 


/* -----------------------------------------------------------------------------
    &&&~ TIMER DEFINES
 ----------------------------------------------------------------------------- */
#define BSWM_TMR_ESH_SelfRunRequestTimer_Left  0u 
#define BSWM_TMR_ESH_SelfRunRequestTimer_Right 0u 



/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL CONSTANT MACROS
**********************************************************************************************************************/
/** 
  \defgroup  BswMPCDataSwitches  BswM Data Switches  (PRE_COMPILE)
  \brief  These defines are used to deactivate data and their processing.
  \{
*/ 
#define BSWM_ACTIONITEMS                                                                            STD_ON
#define BSWM_ABORTOFACTIONITEMS                                                                     STD_OFF  /**< Deactivateable: 'BswM_ActionItemsLeft.Abort' Reason: 'the value of BswM_AbortOfActionItems is always 'false' due to this, the array is deactivated.' and Deactivateable: 'BswM_ActionItemsRight.Abort' Reason: 'the value of BswM_AbortOfActionItems is always 'false' due to this, the array is deactivated.' */
#define BSWM_ACTIONSIDXOFACTIONITEMS                                                                STD_ON
#define BSWM_PARAMETERIDXOFACTIONITEMS                                                              STD_ON
#define BSWM_PARAMETEROFACTIONITEMS                                                                 STD_ON
#define BSWM_PARAMETERUSEDOFACTIONITEMS                                                             STD_ON
#define BSWM_REPORTOFACTIONITEMS                                                                    STD_OFF  /**< Deactivateable: 'BswM_ActionItemsLeft.Report' Reason: 'No Dem event is configured.' and Deactivateable: 'BswM_ActionItemsRight.Report' Reason: 'No Dem event is configured.' */
#define BSWM_ACTIONLISTPRIORITYQUEUE                                                                STD_OFF  /**< Deactivateable: 'BswM_ActionListPriorityQueue' Reason: 'Action List Queue Search Algorithm is not equal to PRIORITY_QUEUE' and Deactivateable: 'BswM_ActionListPriorityQueue' Reason: 'Action List Queue Search Algorithm is not equal to PRIORITY_QUEUE' */
#define BSWM_ACTIONLISTQUEUE                                                                        STD_ON
#define BSWM_ACTIONLISTS                                                                            STD_ON
#define BSWM_ACTIONITEMSENDIDXOFACTIONLISTS                                                         STD_ON
#define BSWM_ACTIONITEMSSTARTIDXOFACTIONLISTS                                                       STD_ON
#define BSWM_ACTIONITEMSUSEDOFACTIONLISTS                                                           STD_ON
#define BSWM_CONDITIONALOFACTIONLISTS                                                               STD_ON
#define BSWM_ACTIONS                                                                                STD_ON
#define BSWM_CANSMCHANNELMAPPING                                                                    STD_ON
#define BSWM_EXTERNALIDOFCANSMCHANNELMAPPING                                                        STD_ON
#define BSWM_IMMEDIATEUSERENDIDXOFCANSMCHANNELMAPPING                                               STD_ON
#define BSWM_IMMEDIATEUSERSTARTIDXOFCANSMCHANNELMAPPING                                             STD_ON
#define BSWM_IMMEDIATEUSERUSEDOFCANSMCHANNELMAPPING                                                 STD_ON
#define BSWM_INITVALUEOFCANSMCHANNELMAPPING                                                         STD_ON
#define BSWM_CANSMCHANNELSTATE                                                                      STD_ON
#define BSWM_COMDMCONTROLPARAMETERS                                                                 STD_OFF  /**< Deactivateable: 'BswM_ComDMControlParameters' Reason: 'Action of type 'ComDMControl' not in configuration.' and Deactivateable: 'BswM_ComDMControlParameters' Reason: 'Action of type 'ComDMControl' not in configuration.' */
#define BSWM_COMDMCONTROLSUBPARAMETERSENDIDXOFCOMDMCONTROLPARAMETERS                                STD_OFF  /**< Deactivateable: 'BswM_ComDMControlParameters.ComDMControlSubParametersEndIdx' Reason: 'Action of type 'ComDMControl' not in configuration.' and Deactivateable: 'BswM_ComDMControlParameters.ComDMControlSubParametersEndIdx' Reason: 'Action of type 'ComDMControl' not in configuration.' */
#define BSWM_COMDMCONTROLSUBPARAMETERSSTARTIDXOFCOMDMCONTROLPARAMETERS                              STD_OFF  /**< Deactivateable: 'BswM_ComDMControlParameters.ComDMControlSubParametersStartIdx' Reason: 'Action of type 'ComDMControl' not in configuration.' and Deactivateable: 'BswM_ComDMControlParameters.ComDMControlSubParametersStartIdx' Reason: 'Action of type 'ComDMControl' not in configuration.' */
#define BSWM_COMDMCONTROLSUBPARAMETERSUSEDOFCOMDMCONTROLPARAMETERS                                  STD_OFF  /**< Deactivateable: 'BswM_ComDMControlParameters.ComDMControlSubParametersUsed' Reason: 'Action of type 'ComDMControl' not in configuration.' and Deactivateable: 'BswM_ComDMControlParameters.ComDMControlSubParametersUsed' Reason: 'Action of type 'ComDMControl' not in configuration.' */
#define BSWM_COMDMCONTROLSUBPARAMETERS                                                              STD_OFF  /**< Deactivateable: 'BswM_ComDMControlSubParameters' Reason: 'Action of type 'ComDMControl' not in configuration.' and Deactivateable: 'BswM_ComDMControlSubParameters' Reason: 'Action of type 'ComDMControl' not in configuration.' */
#define BSWM_BITVALOFCOMDMCONTROLSUBPARAMETERS                                                      STD_OFF  /**< Deactivateable: 'BswM_ComDMControlSubParameters.BitVal' Reason: 'Action of type 'ComDMControl' not in configuration.' and Deactivateable: 'BswM_ComDMControlSubParameters.BitVal' Reason: 'Action of type 'ComDMControl' not in configuration.' */
#define BSWM_IPDUGROUPIDOFCOMDMCONTROLSUBPARAMETERS                                                 STD_OFF  /**< Deactivateable: 'BswM_ComDMControlSubParameters.IpduGroupId' Reason: 'Action of type 'ComDMControl' not in configuration.' and Deactivateable: 'BswM_ComDMControlSubParameters.IpduGroupId' Reason: 'Action of type 'ComDMControl' not in configuration.' */
#define BSWM_COMDMHANDLINGDISABLEPARAMETERS                                                         STD_ON
#define BSWM_IPDUGROUPIDOFCOMDMHANDLINGDISABLEPARAMETERS                                            STD_ON
#define BSWM_COMDMHANDLINGENABLEPARAMETERS                                                          STD_ON
#define BSWM_IPDUGROUPIDOFCOMDMHANDLINGENABLEPARAMETERS                                             STD_ON
#define BSWM_COMDMHANDLINGPARAMETERS                                                                STD_ON
#define BSWM_COMDMHANDLINGDISABLEPARAMETERSENDIDXOFCOMDMHANDLINGPARAMETERS                          STD_ON
#define BSWM_COMDMHANDLINGDISABLEPARAMETERSSTARTIDXOFCOMDMHANDLINGPARAMETERS                        STD_ON
#define BSWM_COMDMHANDLINGDISABLEPARAMETERSUSEDOFCOMDMHANDLINGPARAMETERS                            STD_ON
#define BSWM_COMDMHANDLINGENABLEPARAMETERSENDIDXOFCOMDMHANDLINGPARAMETERS                           STD_ON
#define BSWM_COMDMHANDLINGENABLEPARAMETERSSTARTIDXOFCOMDMHANDLINGPARAMETERS                         STD_ON
#define BSWM_COMDMHANDLINGENABLEPARAMETERSUSEDOFCOMDMHANDLINGPARAMETERS                             STD_ON
#define BSWM_COMMALLOWCOMPARAMETERS                                                                 STD_ON
#define BSWM_ALLOWEDOFCOMMALLOWCOMPARAMETERS                                                        STD_ON
#define BSWM_CHANNELOFCOMMALLOWCOMPARAMETERS                                                        STD_ON
#define BSWM_COMMCHANNELMAPPING                                                                     STD_ON
#define BSWM_EXTERNALIDOFCOMMCHANNELMAPPING                                                         STD_ON
#define BSWM_IMMEDIATEUSERENDIDXOFCOMMCHANNELMAPPING                                                STD_ON
#define BSWM_IMMEDIATEUSERSTARTIDXOFCOMMCHANNELMAPPING                                              STD_ON
#define BSWM_IMMEDIATEUSERUSEDOFCOMMCHANNELMAPPING                                                  STD_ON
#define BSWM_INITVALUEOFCOMMCHANNELMAPPING                                                          STD_ON
#define BSWM_COMMCHANNELSTATE                                                                       STD_ON
#define BSWM_COMMINITIATERESETMAPPING                                                               STD_OFF  /**< Deactivateable: 'BswM_ComMInitiateResetMapping' Reason: 'No Mode Request for BswMComMInitiateReset configured.' and Deactivateable: 'BswM_ComMInitiateResetMapping' Reason: 'No Mode Request for BswMComMInitiateReset configured.' */
#define BSWM_IMMEDIATEUSERENDIDXOFCOMMINITIATERESETMAPPING                                          STD_OFF  /**< Deactivateable: 'BswM_ComMInitiateResetMapping.ImmediateUserEndIdx' Reason: 'No Mode Request for BswMComMInitiateReset configured.' and Deactivateable: 'BswM_ComMInitiateResetMapping.ImmediateUserEndIdx' Reason: 'No Mode Request for BswMComMInitiateReset configured.' */
#define BSWM_IMMEDIATEUSERSTARTIDXOFCOMMINITIATERESETMAPPING                                        STD_OFF  /**< Deactivateable: 'BswM_ComMInitiateResetMapping.ImmediateUserStartIdx' Reason: 'No Mode Request for BswMComMInitiateReset configured.' and Deactivateable: 'BswM_ComMInitiateResetMapping.ImmediateUserStartIdx' Reason: 'No Mode Request for BswMComMInitiateReset configured.' */
#define BSWM_IMMEDIATEUSERUSEDOFCOMMINITIATERESETMAPPING                                            STD_OFF  /**< Deactivateable: 'BswM_ComMInitiateResetMapping.ImmediateUserUsed' Reason: 'No Mode Request for BswMComMInitiateReset configured.' and Deactivateable: 'BswM_ComMInitiateResetMapping.ImmediateUserUsed' Reason: 'No Mode Request for BswMComMInitiateReset configured.' */
#define BSWM_INITVALUEOFCOMMINITIATERESETMAPPING                                                    STD_OFF  /**< Deactivateable: 'BswM_ComMInitiateResetMapping.InitValue' Reason: 'No Mode Request for BswMComMInitiateReset configured.' and Deactivateable: 'BswM_ComMInitiateResetMapping.InitValue' Reason: 'No Mode Request for BswMComMInitiateReset configured.' */
#define BSWM_COMMINITIATERESETSTATE                                                                 STD_OFF  /**< Deactivateable: 'BswM_ComMInitiateResetState' Reason: 'No Mode Request for BswMComMInitiateReset configured.' and Deactivateable: 'BswM_ComMInitiateResetState' Reason: 'No Mode Request for BswMComMInitiateReset configured.' */
#define BSWM_COMMMODELIMITATIONPARAMETERS                                                           STD_OFF  /**< Deactivateable: 'BswM_ComMModeLimitationParameters' Reason: 'Action of type 'ComMModeLimitation' not in configuration.' and Deactivateable: 'BswM_ComMModeLimitationParameters' Reason: 'Action of type 'ComMModeLimitation' not in configuration.' */
#define BSWM_CHANNELOFCOMMMODELIMITATIONPARAMETERS                                                  STD_OFF  /**< Deactivateable: 'BswM_ComMModeLimitationParameters.Channel' Reason: 'Action of type 'ComMModeLimitation' not in configuration.' and Deactivateable: 'BswM_ComMModeLimitationParameters.Channel' Reason: 'Action of type 'ComMModeLimitation' not in configuration.' */
#define BSWM_STATUSOFCOMMMODELIMITATIONPARAMETERS                                                   STD_OFF  /**< Deactivateable: 'BswM_ComMModeLimitationParameters.Status' Reason: 'Action of type 'ComMModeLimitation' not in configuration.' and Deactivateable: 'BswM_ComMModeLimitationParameters.Status' Reason: 'Action of type 'ComMModeLimitation' not in configuration.' */
#define BSWM_COMMMODESWITCHPARAMETERS                                                               STD_OFF  /**< Deactivateable: 'BswM_ComMModeSwitchParameters' Reason: 'Action of type 'ComMModeSwitch' not in configuration.' and Deactivateable: 'BswM_ComMModeSwitchParameters' Reason: 'Action of type 'ComMModeSwitch' not in configuration.' */
#define BSWM_COMMODEOFCOMMMODESWITCHPARAMETERS                                                      STD_OFF  /**< Deactivateable: 'BswM_ComMModeSwitchParameters.ComMode' Reason: 'Action of type 'ComMModeSwitch' not in configuration.' and Deactivateable: 'BswM_ComMModeSwitchParameters.ComMode' Reason: 'Action of type 'ComMModeSwitch' not in configuration.' */
#define BSWM_USEROFCOMMMODESWITCHPARAMETERS                                                         STD_OFF  /**< Deactivateable: 'BswM_ComMModeSwitchParameters.User' Reason: 'Action of type 'ComMModeSwitch' not in configuration.' and Deactivateable: 'BswM_ComMModeSwitchParameters.User' Reason: 'Action of type 'ComMModeSwitch' not in configuration.' */
#define BSWM_COMMPNCMAPPING                                                                         STD_ON
#define BSWM_EXTERNALIDOFCOMMPNCMAPPING                                                             STD_ON
#define BSWM_IMMEDIATEUSERENDIDXOFCOMMPNCMAPPING                                                    STD_ON
#define BSWM_IMMEDIATEUSERSTARTIDXOFCOMMPNCMAPPING                                                  STD_ON
#define BSWM_IMMEDIATEUSERUSEDOFCOMMPNCMAPPING                                                      STD_ON
#define BSWM_INITVALUEOFCOMMPNCMAPPING                                                              STD_ON
#define BSWM_COMMPNCSTATE                                                                           STD_ON
#define BSWM_COMPDUGROUPHANDLINGPARAMETERS                                                          STD_ON
#define BSWM_COMPDUGROUPHANDLINGSTARTPARAMETERSENDIDXOFCOMPDUGROUPHANDLINGPARAMETERS                STD_ON
#define BSWM_COMPDUGROUPHANDLINGSTARTPARAMETERSSTARTIDXOFCOMPDUGROUPHANDLINGPARAMETERS              STD_ON
#define BSWM_COMPDUGROUPHANDLINGSTARTPARAMETERSUSEDOFCOMPDUGROUPHANDLINGPARAMETERS                  STD_ON
#define BSWM_COMPDUGROUPHANDLINGSTOPPARAMETERSENDIDXOFCOMPDUGROUPHANDLINGPARAMETERS                 STD_ON
#define BSWM_COMPDUGROUPHANDLINGSTOPPARAMETERSSTARTIDXOFCOMPDUGROUPHANDLINGPARAMETERS               STD_ON
#define BSWM_COMPDUGROUPHANDLINGSTOPPARAMETERSUSEDOFCOMPDUGROUPHANDLINGPARAMETERS                   STD_ON
#define BSWM_COMPDUGROUPHANDLINGSTARTPARAMETERS                                                     STD_ON
#define BSWM_INITIALIZEOFCOMPDUGROUPHANDLINGSTARTPARAMETERS                                         STD_ON
#define BSWM_IPDUGROUPIDOFCOMPDUGROUPHANDLINGSTARTPARAMETERS                                        STD_ON
#define BSWM_COMPDUGROUPHANDLINGSTOPPARAMETERS                                                      STD_ON
#define BSWM_IPDUGROUPIDOFCOMPDUGROUPHANDLINGSTOPPARAMETERS                                         STD_ON
#define BSWM_COMPDUGROUPSWITCHPARAMETERS                                                            STD_OFF  /**< Deactivateable: 'BswM_ComPduGroupSwitchParameters' Reason: 'Action of type 'ComPduGroupSwitch' not in configuration.' and Deactivateable: 'BswM_ComPduGroupSwitchParameters' Reason: 'Action of type 'ComPduGroupSwitch' not in configuration.' */
#define BSWM_COMPDUGROUPSWITCHSUBPARAMETERSENDIDXOFCOMPDUGROUPSWITCHPARAMETERS                      STD_OFF  /**< Deactivateable: 'BswM_ComPduGroupSwitchParameters.ComPduGroupSwitchSubParametersEndIdx' Reason: 'Action of type 'ComPduGroupSwitch' not in configuration.' and Deactivateable: 'BswM_ComPduGroupSwitchParameters.ComPduGroupSwitchSubParametersEndIdx' Reason: 'Action of type 'ComPduGroupSwitch' not in configuration.' */
#define BSWM_COMPDUGROUPSWITCHSUBPARAMETERSSTARTIDXOFCOMPDUGROUPSWITCHPARAMETERS                    STD_OFF  /**< Deactivateable: 'BswM_ComPduGroupSwitchParameters.ComPduGroupSwitchSubParametersStartIdx' Reason: 'Action of type 'ComPduGroupSwitch' not in configuration.' and Deactivateable: 'BswM_ComPduGroupSwitchParameters.ComPduGroupSwitchSubParametersStartIdx' Reason: 'Action of type 'ComPduGroupSwitch' not in configuration.' */
#define BSWM_COMPDUGROUPSWITCHSUBPARAMETERSUSEDOFCOMPDUGROUPSWITCHPARAMETERS                        STD_OFF  /**< Deactivateable: 'BswM_ComPduGroupSwitchParameters.ComPduGroupSwitchSubParametersUsed' Reason: 'Action of type 'ComPduGroupSwitch' not in configuration.' and Deactivateable: 'BswM_ComPduGroupSwitchParameters.ComPduGroupSwitchSubParametersUsed' Reason: 'Action of type 'ComPduGroupSwitch' not in configuration.' */
#define BSWM_CONTROLOFCOMPDUGROUPSWITCHPARAMETERS                                                   STD_OFF  /**< Deactivateable: 'BswM_ComPduGroupSwitchParameters.Control' Reason: 'Action of type 'ComPduGroupSwitch' not in configuration.' and Deactivateable: 'BswM_ComPduGroupSwitchParameters.Control' Reason: 'Action of type 'ComPduGroupSwitch' not in configuration.' */
#define BSWM_COMPDUGROUPSWITCHSUBPARAMETERS                                                         STD_OFF  /**< Deactivateable: 'BswM_ComPduGroupSwitchSubParameters' Reason: 'Action of type 'ComPduGroupSwitch' not in configuration.' and Deactivateable: 'BswM_ComPduGroupSwitchSubParameters' Reason: 'Action of type 'ComPduGroupSwitch' not in configuration.' */
#define BSWM_BITVALOFCOMPDUGROUPSWITCHSUBPARAMETERS                                                 STD_OFF  /**< Deactivateable: 'BswM_ComPduGroupSwitchSubParameters.BitVal' Reason: 'Action of type 'ComPduGroupSwitch' not in configuration.' and Deactivateable: 'BswM_ComPduGroupSwitchSubParameters.BitVal' Reason: 'Action of type 'ComPduGroupSwitch' not in configuration.' */
#define BSWM_IPDUGROUPIDOFCOMPDUGROUPSWITCHSUBPARAMETERS                                            STD_OFF  /**< Deactivateable: 'BswM_ComPduGroupSwitchSubParameters.IpduGroupId' Reason: 'Action of type 'ComPduGroupSwitch' not in configuration.' and Deactivateable: 'BswM_ComPduGroupSwitchSubParameters.IpduGroupId' Reason: 'Action of type 'ComPduGroupSwitch' not in configuration.' */
#define BSWM_COMSWITCHIPDUMODEPARAMETERS                                                            STD_OFF  /**< Deactivateable: 'BswM_ComSwitchIPduModeParameters' Reason: 'Action of type 'ComSwitchIPduMode' not in configuration.' and Deactivateable: 'BswM_ComSwitchIPduModeParameters' Reason: 'Action of type 'ComSwitchIPduMode' not in configuration.' */
#define BSWM_MODEOFCOMSWITCHIPDUMODEPARAMETERS                                                      STD_OFF  /**< Deactivateable: 'BswM_ComSwitchIPduModeParameters.Mode' Reason: 'Action of type 'ComSwitchIPduMode' not in configuration.' and Deactivateable: 'BswM_ComSwitchIPduModeParameters.Mode' Reason: 'Action of type 'ComSwitchIPduMode' not in configuration.' */
#define BSWM_PDUIDOFCOMSWITCHIPDUMODEPARAMETERS                                                     STD_OFF  /**< Deactivateable: 'BswM_ComSwitchIPduModeParameters.PduId' Reason: 'Action of type 'ComSwitchIPduMode' not in configuration.' and Deactivateable: 'BswM_ComSwitchIPduModeParameters.PduId' Reason: 'Action of type 'ComSwitchIPduMode' not in configuration.' */
#define BSWM_COMTRIGGERIPDUSENDPARAMETERS                                                           STD_OFF  /**< Deactivateable: 'BswM_ComTriggerIPduSendParameters' Reason: 'Action of type 'ComTriggerIPduSend' not in configuration.' and Deactivateable: 'BswM_ComTriggerIPduSendParameters' Reason: 'Action of type 'ComTriggerIPduSend' not in configuration.' */
#define BSWM_COMTRIGGERIPDUSENDSUBPARAMETERSENDIDXOFCOMTRIGGERIPDUSENDPARAMETERS                    STD_OFF  /**< Deactivateable: 'BswM_ComTriggerIPduSendParameters.ComTriggerIPduSendSubParametersEndIdx' Reason: 'Action of type 'ComTriggerIPduSend' not in configuration.' and Deactivateable: 'BswM_ComTriggerIPduSendParameters.ComTriggerIPduSendSubParametersEndIdx' Reason: 'Action of type 'ComTriggerIPduSend' not in configuration.' */
#define BSWM_COMTRIGGERIPDUSENDSUBPARAMETERSSTARTIDXOFCOMTRIGGERIPDUSENDPARAMETERS                  STD_OFF  /**< Deactivateable: 'BswM_ComTriggerIPduSendParameters.ComTriggerIPduSendSubParametersStartIdx' Reason: 'Action of type 'ComTriggerIPduSend' not in configuration.' and Deactivateable: 'BswM_ComTriggerIPduSendParameters.ComTriggerIPduSendSubParametersStartIdx' Reason: 'Action of type 'ComTriggerIPduSend' not in configuration.' */
#define BSWM_COMTRIGGERIPDUSENDSUBPARAMETERSUSEDOFCOMTRIGGERIPDUSENDPARAMETERS                      STD_OFF  /**< Deactivateable: 'BswM_ComTriggerIPduSendParameters.ComTriggerIPduSendSubParametersUsed' Reason: 'Action of type 'ComTriggerIPduSend' not in configuration.' and Deactivateable: 'BswM_ComTriggerIPduSendParameters.ComTriggerIPduSendSubParametersUsed' Reason: 'Action of type 'ComTriggerIPduSend' not in configuration.' */
#define BSWM_COMTRIGGERIPDUSENDSUBPARAMETERS                                                        STD_OFF  /**< Deactivateable: 'BswM_ComTriggerIPduSendSubParameters' Reason: 'Action of type 'ComTriggerIPduSend' not in configuration.' and Deactivateable: 'BswM_ComTriggerIPduSendSubParameters' Reason: 'Action of type 'ComTriggerIPduSend' not in configuration.' */
#define BSWM_PDUIDOFCOMTRIGGERIPDUSENDSUBPARAMETERS                                                 STD_OFF  /**< Deactivateable: 'BswM_ComTriggerIPduSendSubParameters.PduId' Reason: 'Action of type 'ComTriggerIPduSend' not in configuration.' and Deactivateable: 'BswM_ComTriggerIPduSendSubParameters.PduId' Reason: 'Action of type 'ComTriggerIPduSend' not in configuration.' */
#define BSWM_DCMAPPLUPDATEMAPPING                                                                   STD_OFF  /**< Deactivateable: 'BswM_DcmApplUpdateMapping' Reason: 'No Mode Request for BswMDcmApplicationUpdatedIndication configured.' and Deactivateable: 'BswM_DcmApplUpdateMapping' Reason: 'No Mode Request for BswMDcmApplicationUpdatedIndication configured.' */
#define BSWM_IMMEDIATEUSERENDIDXOFDCMAPPLUPDATEMAPPING                                              STD_OFF  /**< Deactivateable: 'BswM_DcmApplUpdateMapping.ImmediateUserEndIdx' Reason: 'No Mode Request for BswMDcmApplicationUpdatedIndication configured.' and Deactivateable: 'BswM_DcmApplUpdateMapping.ImmediateUserEndIdx' Reason: 'No Mode Request for BswMDcmApplicationUpdatedIndication configured.' */
#define BSWM_IMMEDIATEUSERSTARTIDXOFDCMAPPLUPDATEMAPPING                                            STD_OFF  /**< Deactivateable: 'BswM_DcmApplUpdateMapping.ImmediateUserStartIdx' Reason: 'No Mode Request for BswMDcmApplicationUpdatedIndication configured.' and Deactivateable: 'BswM_DcmApplUpdateMapping.ImmediateUserStartIdx' Reason: 'No Mode Request for BswMDcmApplicationUpdatedIndication configured.' */
#define BSWM_IMMEDIATEUSERUSEDOFDCMAPPLUPDATEMAPPING                                                STD_OFF  /**< Deactivateable: 'BswM_DcmApplUpdateMapping.ImmediateUserUsed' Reason: 'No Mode Request for BswMDcmApplicationUpdatedIndication configured.' and Deactivateable: 'BswM_DcmApplUpdateMapping.ImmediateUserUsed' Reason: 'No Mode Request for BswMDcmApplicationUpdatedIndication configured.' */
#define BSWM_INITVALUEOFDCMAPPLUPDATEMAPPING                                                        STD_OFF  /**< Deactivateable: 'BswM_DcmApplUpdateMapping.InitValue' Reason: 'No Mode Request for BswMDcmApplicationUpdatedIndication configured.' and Deactivateable: 'BswM_DcmApplUpdateMapping.InitValue' Reason: 'No Mode Request for BswMDcmApplicationUpdatedIndication configured.' */
#define BSWM_DCMAPPLUPDATESTATE                                                                     STD_OFF  /**< Deactivateable: 'BswM_DcmApplUpdateState' Reason: 'No Mode Request for BswMDcmApplicationUpdatedIndication configured.' and Deactivateable: 'BswM_DcmApplUpdateState' Reason: 'No Mode Request for BswMDcmApplicationUpdatedIndication configured.' */
#define BSWM_DCMCOMMAPPING                                                                          STD_ON
#define BSWM_EXTERNALIDOFDCMCOMMAPPING                                                              STD_ON
#define BSWM_IMMEDIATEUSERENDIDXOFDCMCOMMAPPING                                                     STD_ON
#define BSWM_IMMEDIATEUSERSTARTIDXOFDCMCOMMAPPING                                                   STD_ON
#define BSWM_IMMEDIATEUSERUSEDOFDCMCOMMAPPING                                                       STD_ON
#define BSWM_INITVALUEOFDCMCOMMAPPING                                                               STD_ON
#define BSWM_DCMCOMSTATE                                                                            STD_ON
#define BSWM_DEFERREDRULES                                                                          STD_ON
#define BSWM_RULESIDXOFDEFERREDRULES                                                                STD_ON
#define BSWM_ECUMMODEMAPPING                                                                        STD_ON
#define BSWM_IMMEDIATEUSERENDIDXOFECUMMODEMAPPING                                                   STD_OFF  /**< Deactivateable: 'BswM_EcuMModeMapping.ImmediateUserEndIdx' Reason: 'the optional indirection is deactivated because ImmediateUserUsedOfEcuMModeMapping is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' and Deactivateable: 'BswM_EcuMModeMapping.ImmediateUserEndIdx' Reason: 'the optional indirection is deactivated because ImmediateUserUsedOfEcuMModeMapping is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define BSWM_IMMEDIATEUSERSTARTIDXOFECUMMODEMAPPING                                                 STD_OFF  /**< Deactivateable: 'BswM_EcuMModeMapping.ImmediateUserStartIdx' Reason: 'the optional indirection is deactivated because ImmediateUserUsedOfEcuMModeMapping is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' and Deactivateable: 'BswM_EcuMModeMapping.ImmediateUserStartIdx' Reason: 'the optional indirection is deactivated because ImmediateUserUsedOfEcuMModeMapping is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define BSWM_IMMEDIATEUSERUSEDOFECUMMODEMAPPING                                                     STD_OFF  /**< Deactivateable: 'BswM_EcuMModeMapping.ImmediateUserUsed' Reason: 'the optional indirection is deactivated because ImmediateUserUsedOfEcuMModeMapping is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' and Deactivateable: 'BswM_EcuMModeMapping.ImmediateUserUsed' Reason: 'the optional indirection is deactivated because ImmediateUserUsedOfEcuMModeMapping is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define BSWM_INITVALUEOFECUMMODEMAPPING                                                             STD_ON
#define BSWM_ECUMMODESTATE                                                                          STD_ON
#define BSWM_ECUMRUNREQUESTMAPPING                                                                  STD_ON
#define BSWM_EXTERNALIDOFECUMRUNREQUESTMAPPING                                                      STD_ON
#define BSWM_IMMEDIATEUSERENDIDXOFECUMRUNREQUESTMAPPING                                             STD_OFF  /**< Deactivateable: 'BswM_EcuMRunRequestMapping.ImmediateUserEndIdx' Reason: 'the optional indirection is deactivated because ImmediateUserUsedOfEcuMRunRequestMapping is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' and Deactivateable: 'BswM_EcuMRunRequestMapping.ImmediateUserEndIdx' Reason: 'the optional indirection is deactivated because ImmediateUserUsedOfEcuMRunRequestMapping is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define BSWM_IMMEDIATEUSERSTARTIDXOFECUMRUNREQUESTMAPPING                                           STD_OFF  /**< Deactivateable: 'BswM_EcuMRunRequestMapping.ImmediateUserStartIdx' Reason: 'the optional indirection is deactivated because ImmediateUserUsedOfEcuMRunRequestMapping is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' and Deactivateable: 'BswM_EcuMRunRequestMapping.ImmediateUserStartIdx' Reason: 'the optional indirection is deactivated because ImmediateUserUsedOfEcuMRunRequestMapping is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define BSWM_IMMEDIATEUSERUSEDOFECUMRUNREQUESTMAPPING                                               STD_OFF  /**< Deactivateable: 'BswM_EcuMRunRequestMapping.ImmediateUserUsed' Reason: 'the optional indirection is deactivated because ImmediateUserUsedOfEcuMRunRequestMapping is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' and Deactivateable: 'BswM_EcuMRunRequestMapping.ImmediateUserUsed' Reason: 'the optional indirection is deactivated because ImmediateUserUsedOfEcuMRunRequestMapping is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define BSWM_INITVALUEOFECUMRUNREQUESTMAPPING                                                       STD_ON
#define BSWM_ECUMRUNREQUESTSTATE                                                                    STD_ON
#define BSWM_ECUMSELECTSHUTDOWNTARGETPARAMETERS                                                     STD_OFF  /**< Deactivateable: 'BswM_EcuMSelectShutdownTargetParameters' Reason: 'Action of type 'EcuMSelectShutdownTarget' not in configuration.' and Deactivateable: 'BswM_EcuMSelectShutdownTargetParameters' Reason: 'Action of type 'EcuMSelectShutdownTarget' not in configuration.' */
#define BSWM_RESETSLEEPMODEOFECUMSELECTSHUTDOWNTARGETPARAMETERS                                     STD_OFF  /**< Deactivateable: 'BswM_EcuMSelectShutdownTargetParameters.ResetSleepMode' Reason: 'Action of type 'EcuMSelectShutdownTarget' not in configuration.' and Deactivateable: 'BswM_EcuMSelectShutdownTargetParameters.ResetSleepMode' Reason: 'Action of type 'EcuMSelectShutdownTarget' not in configuration.' */
#define BSWM_TARGETSTATEOFECUMSELECTSHUTDOWNTARGETPARAMETERS                                        STD_OFF  /**< Deactivateable: 'BswM_EcuMSelectShutdownTargetParameters.TargetState' Reason: 'Action of type 'EcuMSelectShutdownTarget' not in configuration.' and Deactivateable: 'BswM_EcuMSelectShutdownTargetParameters.TargetState' Reason: 'Action of type 'EcuMSelectShutdownTarget' not in configuration.' */
#define BSWM_ECUMSTATESWITCHPARAMETERS                                                              STD_ON
#define BSWM_TARGETSTATEOFECUMSTATESWITCHPARAMETERS                                                 STD_ON
#define BSWM_ECUMWAKEUPMAPPING                                                                      STD_OFF  /**< Deactivateable: 'BswM_EcuMWakeupMapping' Reason: 'No Mode Request for BswMEcuMWakeupSource configured.' and Deactivateable: 'BswM_EcuMWakeupMapping' Reason: 'No Mode Request for BswMEcuMWakeupSource configured.' */
#define BSWM_EXTERNALIDOFECUMWAKEUPMAPPING                                                          STD_OFF  /**< Deactivateable: 'BswM_EcuMWakeupMapping.ExternalId' Reason: 'No Mode Request for BswMEcuMWakeupSource configured.' and Deactivateable: 'BswM_EcuMWakeupMapping.ExternalId' Reason: 'No Mode Request for BswMEcuMWakeupSource configured.' */
#define BSWM_IMMEDIATEUSERENDIDXOFECUMWAKEUPMAPPING                                                 STD_OFF  /**< Deactivateable: 'BswM_EcuMWakeupMapping.ImmediateUserEndIdx' Reason: 'No Mode Request for BswMEcuMWakeupSource configured.' and Deactivateable: 'BswM_EcuMWakeupMapping.ImmediateUserEndIdx' Reason: 'No Mode Request for BswMEcuMWakeupSource configured.' */
#define BSWM_IMMEDIATEUSERSTARTIDXOFECUMWAKEUPMAPPING                                               STD_OFF  /**< Deactivateable: 'BswM_EcuMWakeupMapping.ImmediateUserStartIdx' Reason: 'No Mode Request for BswMEcuMWakeupSource configured.' and Deactivateable: 'BswM_EcuMWakeupMapping.ImmediateUserStartIdx' Reason: 'No Mode Request for BswMEcuMWakeupSource configured.' */
#define BSWM_IMMEDIATEUSERUSEDOFECUMWAKEUPMAPPING                                                   STD_OFF  /**< Deactivateable: 'BswM_EcuMWakeupMapping.ImmediateUserUsed' Reason: 'No Mode Request for BswMEcuMWakeupSource configured.' and Deactivateable: 'BswM_EcuMWakeupMapping.ImmediateUserUsed' Reason: 'No Mode Request for BswMEcuMWakeupSource configured.' */
#define BSWM_INITVALUEOFECUMWAKEUPMAPPING                                                           STD_OFF  /**< Deactivateable: 'BswM_EcuMWakeupMapping.InitValue' Reason: 'No Mode Request for BswMEcuMWakeupSource configured.' and Deactivateable: 'BswM_EcuMWakeupMapping.InitValue' Reason: 'No Mode Request for BswMEcuMWakeupSource configured.' */
#define BSWM_ECUMWAKEUPSTATE                                                                        STD_OFF  /**< Deactivateable: 'BswM_EcuMWakeupState' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'BswM_EcuMWakeupState' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define BSWM_ETHIFPORTMAPPING                                                                       STD_OFF  /**< Deactivateable: 'BswM_EthIfPortMapping' Reason: 'No Mode Request for BswMEthIfPortGroupLinkStateChg configured.' and Deactivateable: 'BswM_EthIfPortMapping' Reason: 'No Mode Request for BswMEthIfPortGroupLinkStateChg configured.' */
#define BSWM_EXTERNALIDOFETHIFPORTMAPPING                                                           STD_OFF  /**< Deactivateable: 'BswM_EthIfPortMapping.ExternalId' Reason: 'No Mode Request for BswMEthIfPortGroupLinkStateChg configured.' and Deactivateable: 'BswM_EthIfPortMapping.ExternalId' Reason: 'No Mode Request for BswMEthIfPortGroupLinkStateChg configured.' */
#define BSWM_IMMEDIATEUSERENDIDXOFETHIFPORTMAPPING                                                  STD_OFF  /**< Deactivateable: 'BswM_EthIfPortMapping.ImmediateUserEndIdx' Reason: 'No Mode Request for BswMEthIfPortGroupLinkStateChg configured.' and Deactivateable: 'BswM_EthIfPortMapping.ImmediateUserEndIdx' Reason: 'No Mode Request for BswMEthIfPortGroupLinkStateChg configured.' */
#define BSWM_IMMEDIATEUSERSTARTIDXOFETHIFPORTMAPPING                                                STD_OFF  /**< Deactivateable: 'BswM_EthIfPortMapping.ImmediateUserStartIdx' Reason: 'No Mode Request for BswMEthIfPortGroupLinkStateChg configured.' and Deactivateable: 'BswM_EthIfPortMapping.ImmediateUserStartIdx' Reason: 'No Mode Request for BswMEthIfPortGroupLinkStateChg configured.' */
#define BSWM_IMMEDIATEUSERUSEDOFETHIFPORTMAPPING                                                    STD_OFF  /**< Deactivateable: 'BswM_EthIfPortMapping.ImmediateUserUsed' Reason: 'No Mode Request for BswMEthIfPortGroupLinkStateChg configured.' and Deactivateable: 'BswM_EthIfPortMapping.ImmediateUserUsed' Reason: 'No Mode Request for BswMEthIfPortGroupLinkStateChg configured.' */
#define BSWM_INITVALUEOFETHIFPORTMAPPING                                                            STD_OFF  /**< Deactivateable: 'BswM_EthIfPortMapping.InitValue' Reason: 'No Mode Request for BswMEthIfPortGroupLinkStateChg configured.' and Deactivateable: 'BswM_EthIfPortMapping.InitValue' Reason: 'No Mode Request for BswMEthIfPortGroupLinkStateChg configured.' */
#define BSWM_ETHIFPORTSTATE                                                                         STD_OFF  /**< Deactivateable: 'BswM_EthIfPortState' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'BswM_EthIfPortState' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define BSWM_ETHSMMAPPING                                                                           STD_OFF  /**< Deactivateable: 'BswM_EthSMMapping' Reason: 'No Mode Request for BswMEthSMIndication configured.' and Deactivateable: 'BswM_EthSMMapping' Reason: 'No Mode Request for BswMEthSMIndication configured.' */
#define BSWM_EXTERNALIDOFETHSMMAPPING                                                               STD_OFF  /**< Deactivateable: 'BswM_EthSMMapping.ExternalId' Reason: 'No Mode Request for BswMEthSMIndication configured.' and Deactivateable: 'BswM_EthSMMapping.ExternalId' Reason: 'No Mode Request for BswMEthSMIndication configured.' */
#define BSWM_IMMEDIATEUSERENDIDXOFETHSMMAPPING                                                      STD_OFF  /**< Deactivateable: 'BswM_EthSMMapping.ImmediateUserEndIdx' Reason: 'No Mode Request for BswMEthSMIndication configured.' and Deactivateable: 'BswM_EthSMMapping.ImmediateUserEndIdx' Reason: 'No Mode Request for BswMEthSMIndication configured.' */
#define BSWM_IMMEDIATEUSERSTARTIDXOFETHSMMAPPING                                                    STD_OFF  /**< Deactivateable: 'BswM_EthSMMapping.ImmediateUserStartIdx' Reason: 'No Mode Request for BswMEthSMIndication configured.' and Deactivateable: 'BswM_EthSMMapping.ImmediateUserStartIdx' Reason: 'No Mode Request for BswMEthSMIndication configured.' */
#define BSWM_IMMEDIATEUSERUSEDOFETHSMMAPPING                                                        STD_OFF  /**< Deactivateable: 'BswM_EthSMMapping.ImmediateUserUsed' Reason: 'No Mode Request for BswMEthSMIndication configured.' and Deactivateable: 'BswM_EthSMMapping.ImmediateUserUsed' Reason: 'No Mode Request for BswMEthSMIndication configured.' */
#define BSWM_INITVALUEOFETHSMMAPPING                                                                STD_OFF  /**< Deactivateable: 'BswM_EthSMMapping.InitValue' Reason: 'No Mode Request for BswMEthSMIndication configured.' and Deactivateable: 'BswM_EthSMMapping.InitValue' Reason: 'No Mode Request for BswMEthSMIndication configured.' */
#define BSWM_ETHSMSTATE                                                                             STD_OFF  /**< Deactivateable: 'BswM_EthSMState' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'BswM_EthSMState' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define BSWM_EXPRESSIONS                                                                            STD_ON
#define BSWM_FINALMAGICNUMBER                                                                       STD_OFF  /**< Deactivateable: 'BswM_FinalMagicNumber' Reason: 'the module configuration does not support flashing of data.' */
#define BSWM_FORCEDACTIONLISTPRIORITY                                                               STD_ON
#define BSWM_FRSMMAPPING                                                                            STD_OFF  /**< Deactivateable: 'BswM_FrSMMapping' Reason: 'No Mode Request for BswMFrSMIndication configured.' and Deactivateable: 'BswM_FrSMMapping' Reason: 'No Mode Request for BswMFrSMIndication configured.' */
#define BSWM_EXTERNALIDOFFRSMMAPPING                                                                STD_OFF  /**< Deactivateable: 'BswM_FrSMMapping.ExternalId' Reason: 'No Mode Request for BswMFrSMIndication configured.' and Deactivateable: 'BswM_FrSMMapping.ExternalId' Reason: 'No Mode Request for BswMFrSMIndication configured.' */
#define BSWM_IMMEDIATEUSERENDIDXOFFRSMMAPPING                                                       STD_OFF  /**< Deactivateable: 'BswM_FrSMMapping.ImmediateUserEndIdx' Reason: 'No Mode Request for BswMFrSMIndication configured.' and Deactivateable: 'BswM_FrSMMapping.ImmediateUserEndIdx' Reason: 'No Mode Request for BswMFrSMIndication configured.' */
#define BSWM_IMMEDIATEUSERSTARTIDXOFFRSMMAPPING                                                     STD_OFF  /**< Deactivateable: 'BswM_FrSMMapping.ImmediateUserStartIdx' Reason: 'No Mode Request for BswMFrSMIndication configured.' and Deactivateable: 'BswM_FrSMMapping.ImmediateUserStartIdx' Reason: 'No Mode Request for BswMFrSMIndication configured.' */
#define BSWM_IMMEDIATEUSERUSEDOFFRSMMAPPING                                                         STD_OFF  /**< Deactivateable: 'BswM_FrSMMapping.ImmediateUserUsed' Reason: 'No Mode Request for BswMFrSMIndication configured.' and Deactivateable: 'BswM_FrSMMapping.ImmediateUserUsed' Reason: 'No Mode Request for BswMFrSMIndication configured.' */
#define BSWM_INITVALUEOFFRSMMAPPING                                                                 STD_OFF  /**< Deactivateable: 'BswM_FrSMMapping.InitValue' Reason: 'No Mode Request for BswMFrSMIndication configured.' and Deactivateable: 'BswM_FrSMMapping.InitValue' Reason: 'No Mode Request for BswMFrSMIndication configured.' */
#define BSWM_FRSMSTATE                                                                              STD_OFF  /**< Deactivateable: 'BswM_FrSMState' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'BswM_FrSMState' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define BSWM_GENERICMAPPING                                                                         STD_ON
#define BSWM_EXTERNALIDOFGENERICMAPPING                                                             STD_ON
#define BSWM_IMMEDIATEUSERENDIDXOFGENERICMAPPING                                                    STD_ON
#define BSWM_IMMEDIATEUSERSTARTIDXOFGENERICMAPPING                                                  STD_ON
#define BSWM_IMMEDIATEUSERUSEDOFGENERICMAPPING                                                      STD_ON
#define BSWM_INITVALUEOFGENERICMAPPING                                                              STD_ON
#define BSWM_GENERICMODEPARAMETERS                                                                  STD_ON
#define BSWM_MODEOFGENERICMODEPARAMETERS                                                            STD_ON
#define BSWM_USEROFGENERICMODEPARAMETERS                                                            STD_ON
#define BSWM_GENERICMODEREFPARAMETERS                                                               STD_OFF  /**< Deactivateable: 'BswM_GenericModeRefParameters' Reason: 'Action of type 'GenericModeRef' not in configuration.' and Deactivateable: 'BswM_GenericModeRefParameters' Reason: 'Action of type 'GenericModeRef' not in configuration.' */
#define BSWM_MODEOFGENERICMODEREFPARAMETERS                                                         STD_OFF  /**< Deactivateable: 'BswM_GenericModeRefParameters.Mode' Reason: 'Action of type 'GenericModeRef' not in configuration.' and Deactivateable: 'BswM_GenericModeRefParameters.Mode' Reason: 'Action of type 'GenericModeRef' not in configuration.' */
#define BSWM_USEROFGENERICMODEREFPARAMETERS                                                         STD_OFF  /**< Deactivateable: 'BswM_GenericModeRefParameters.User' Reason: 'Action of type 'GenericModeRef' not in configuration.' and Deactivateable: 'BswM_GenericModeRefParameters.User' Reason: 'Action of type 'GenericModeRef' not in configuration.' */
#define BSWM_GENERICSTATE                                                                           STD_ON
#define BSWM_IDSMBLOCKSTATECHANGEREQUESTPARAMETERS                                                  STD_OFF  /**< Deactivateable: 'BswM_IdsmBlockStateChangeRequestParameters' Reason: 'Action of type 'IdsmBlockStateChangeRequest' not in configuration.' and Deactivateable: 'BswM_IdsmBlockStateChangeRequestParameters' Reason: 'Action of type 'IdsmBlockStateChangeRequest' not in configuration.' */
#define BSWM_STATEOFIDSMBLOCKSTATECHANGEREQUESTPARAMETERS                                           STD_OFF  /**< Deactivateable: 'BswM_IdsmBlockStateChangeRequestParameters.state' Reason: 'Action of type 'IdsmBlockStateChangeRequest' not in configuration.' and Deactivateable: 'BswM_IdsmBlockStateChangeRequestParameters.state' Reason: 'Action of type 'IdsmBlockStateChangeRequest' not in configuration.' */
#define BSWM_IMMEDIATEUSER                                                                          STD_ON
#define BSWM_FORCEDOFIMMEDIATEUSER                                                                  STD_OFF  /**< Deactivateable: 'BswM_ImmediateUser.Forced' Reason: 'the value of BswM_ForcedOfImmediateUser is always 'false' due to this, the array is deactivated.' and Deactivateable: 'BswM_ImmediateUser.Forced' Reason: 'the value of BswM_ForcedOfImmediateUser is always 'false' due to this, the array is deactivated.' */
#define BSWM_ONINITOFIMMEDIATEUSER                                                                  STD_ON
#define BSWM_RULESINDENDIDXOFIMMEDIATEUSER                                                          STD_ON
#define BSWM_RULESINDSTARTIDXOFIMMEDIATEUSER                                                        STD_ON
#define BSWM_RULESINDUSEDOFIMMEDIATEUSER                                                            STD_ON
#define BSWM_INITACTIONLISTS                                                                        STD_ON
#define BSWM_INITDATAHASHCODE                                                                       STD_OFF  /**< Deactivateable: 'BswM_InitDataHashCode' Reason: 'the module configuration does not support flashing of data.' */
#define BSWM_INITGENVARANDINITAL                                                                    STD_ON
#define BSWM_INITVALUES                                                                             STD_ON
#define BSWM_INITIALIZED                                                                            STD_ON
#define BSWM_J1939DCMMAPPING                                                                        STD_OFF  /**< Deactivateable: 'BswM_J1939DcmMapping' Reason: 'No Mode Request for BswMJ1939DcmBroadcastStatus configured.' and Deactivateable: 'BswM_J1939DcmMapping' Reason: 'No Mode Request for BswMJ1939DcmBroadcastStatus configured.' */
#define BSWM_IMMEDIATEUSERENDIDXOFJ1939DCMMAPPING                                                   STD_OFF  /**< Deactivateable: 'BswM_J1939DcmMapping.ImmediateUserEndIdx' Reason: 'No Mode Request for BswMJ1939DcmBroadcastStatus configured.' and Deactivateable: 'BswM_J1939DcmMapping.ImmediateUserEndIdx' Reason: 'No Mode Request for BswMJ1939DcmBroadcastStatus configured.' */
#define BSWM_IMMEDIATEUSERSTARTIDXOFJ1939DCMMAPPING                                                 STD_OFF  /**< Deactivateable: 'BswM_J1939DcmMapping.ImmediateUserStartIdx' Reason: 'No Mode Request for BswMJ1939DcmBroadcastStatus configured.' and Deactivateable: 'BswM_J1939DcmMapping.ImmediateUserStartIdx' Reason: 'No Mode Request for BswMJ1939DcmBroadcastStatus configured.' */
#define BSWM_IMMEDIATEUSERUSEDOFJ1939DCMMAPPING                                                     STD_OFF  /**< Deactivateable: 'BswM_J1939DcmMapping.ImmediateUserUsed' Reason: 'No Mode Request for BswMJ1939DcmBroadcastStatus configured.' and Deactivateable: 'BswM_J1939DcmMapping.ImmediateUserUsed' Reason: 'No Mode Request for BswMJ1939DcmBroadcastStatus configured.' */
#define BSWM_INITVALUEOFJ1939DCMMAPPING                                                             STD_OFF  /**< Deactivateable: 'BswM_J1939DcmMapping.InitValue' Reason: 'No Mode Request for BswMJ1939DcmBroadcastStatus configured.' and Deactivateable: 'BswM_J1939DcmMapping.InitValue' Reason: 'No Mode Request for BswMJ1939DcmBroadcastStatus configured.' */
#define BSWM_J1939DCMSTATE                                                                          STD_OFF  /**< Deactivateable: 'BswM_J1939DcmState' Reason: 'No Mode Request for BswMJ1939DcmBroadcastStatus configured.' and Deactivateable: 'BswM_J1939DcmState' Reason: 'No Mode Request for BswMJ1939DcmBroadcastStatus configured.' */
#define BSWM_J1939DCMSTATEPARAMETERS                                                                STD_OFF  /**< Deactivateable: 'BswM_J1939DcmStateParameters' Reason: 'Action of type 'J1939DcmState' not in configuration.' and Deactivateable: 'BswM_J1939DcmStateParameters' Reason: 'Action of type 'J1939DcmState' not in configuration.' */
#define BSWM_NETWORKOFJ1939DCMSTATEPARAMETERS                                                       STD_OFF  /**< Deactivateable: 'BswM_J1939DcmStateParameters.Network' Reason: 'Action of type 'J1939DcmState' not in configuration.' and Deactivateable: 'BswM_J1939DcmStateParameters.Network' Reason: 'Action of type 'J1939DcmState' not in configuration.' */
#define BSWM_NODEOFJ1939DCMSTATEPARAMETERS                                                          STD_OFF  /**< Deactivateable: 'BswM_J1939DcmStateParameters.Node' Reason: 'Action of type 'J1939DcmState' not in configuration.' and Deactivateable: 'BswM_J1939DcmStateParameters.Node' Reason: 'Action of type 'J1939DcmState' not in configuration.' */
#define BSWM_STATEOFJ1939DCMSTATEPARAMETERS                                                         STD_OFF  /**< Deactivateable: 'BswM_J1939DcmStateParameters.State' Reason: 'Action of type 'J1939DcmState' not in configuration.' and Deactivateable: 'BswM_J1939DcmStateParameters.State' Reason: 'Action of type 'J1939DcmState' not in configuration.' */
#define BSWM_J1939NMMAPPING                                                                         STD_OFF  /**< Deactivateable: 'BswM_J1939NmMapping' Reason: 'No Mode Request for BswMJ1939NmIndication configured.' and Deactivateable: 'BswM_J1939NmMapping' Reason: 'No Mode Request for BswMJ1939NmIndication configured.' */
#define BSWM_EXTERNALIDOFJ1939NMMAPPING                                                             STD_OFF  /**< Deactivateable: 'BswM_J1939NmMapping.ExternalId' Reason: 'No Mode Request for BswMJ1939NmIndication configured.' and Deactivateable: 'BswM_J1939NmMapping.ExternalId' Reason: 'No Mode Request for BswMJ1939NmIndication configured.' */
#define BSWM_IMMEDIATEUSERENDIDXOFJ1939NMMAPPING                                                    STD_OFF  /**< Deactivateable: 'BswM_J1939NmMapping.ImmediateUserEndIdx' Reason: 'No Mode Request for BswMJ1939NmIndication configured.' and Deactivateable: 'BswM_J1939NmMapping.ImmediateUserEndIdx' Reason: 'No Mode Request for BswMJ1939NmIndication configured.' */
#define BSWM_IMMEDIATEUSERSTARTIDXOFJ1939NMMAPPING                                                  STD_OFF  /**< Deactivateable: 'BswM_J1939NmMapping.ImmediateUserStartIdx' Reason: 'No Mode Request for BswMJ1939NmIndication configured.' and Deactivateable: 'BswM_J1939NmMapping.ImmediateUserStartIdx' Reason: 'No Mode Request for BswMJ1939NmIndication configured.' */
#define BSWM_IMMEDIATEUSERUSEDOFJ1939NMMAPPING                                                      STD_OFF  /**< Deactivateable: 'BswM_J1939NmMapping.ImmediateUserUsed' Reason: 'No Mode Request for BswMJ1939NmIndication configured.' and Deactivateable: 'BswM_J1939NmMapping.ImmediateUserUsed' Reason: 'No Mode Request for BswMJ1939NmIndication configured.' */
#define BSWM_INITVALUEOFJ1939NMMAPPING                                                              STD_OFF  /**< Deactivateable: 'BswM_J1939NmMapping.InitValue' Reason: 'No Mode Request for BswMJ1939NmIndication configured.' and Deactivateable: 'BswM_J1939NmMapping.InitValue' Reason: 'No Mode Request for BswMJ1939NmIndication configured.' */
#define BSWM_J1939NMSTATE                                                                           STD_OFF  /**< Deactivateable: 'BswM_J1939NmState' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'BswM_J1939NmState' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define BSWM_J1939RMSTATEPARAMETERS                                                                 STD_OFF  /**< Deactivateable: 'BswM_J1939RmStateParameters' Reason: 'Action of type 'J1939RmState' not in configuration.' and Deactivateable: 'BswM_J1939RmStateParameters' Reason: 'Action of type 'J1939RmState' not in configuration.' */
#define BSWM_NETWORKOFJ1939RMSTATEPARAMETERS                                                        STD_OFF  /**< Deactivateable: 'BswM_J1939RmStateParameters.Network' Reason: 'Action of type 'J1939RmState' not in configuration.' and Deactivateable: 'BswM_J1939RmStateParameters.Network' Reason: 'Action of type 'J1939RmState' not in configuration.' */
#define BSWM_NODEOFJ1939RMSTATEPARAMETERS                                                           STD_OFF  /**< Deactivateable: 'BswM_J1939RmStateParameters.Node' Reason: 'Action of type 'J1939RmState' not in configuration.' and Deactivateable: 'BswM_J1939RmStateParameters.Node' Reason: 'Action of type 'J1939RmState' not in configuration.' */
#define BSWM_STATEOFJ1939RMSTATEPARAMETERS                                                          STD_OFF  /**< Deactivateable: 'BswM_J1939RmStateParameters.State' Reason: 'Action of type 'J1939RmState' not in configuration.' and Deactivateable: 'BswM_J1939RmStateParameters.State' Reason: 'Action of type 'J1939RmState' not in configuration.' */
#define BSWM_LENGTHOFACTIONLISTPRIORITYQUEUE                                                        STD_OFF  /**< Deactivateable: 'BswM_LengthOfActionListPriorityQueue' Reason: 'ActionListPriorityQueue not enabled' and Deactivateable: 'BswM_LengthOfActionListPriorityQueue' Reason: 'ActionListPriorityQueue not enabled' */
#define BSWM_LINSMMAPPING                                                                           STD_OFF  /**< Deactivateable: 'BswM_LinSMMapping' Reason: 'No Mode Request for BswMLinSMIndication configured.' and Deactivateable: 'BswM_LinSMMapping' Reason: 'No Mode Request for BswMLinSMIndication configured.' */
#define BSWM_EXTERNALIDOFLINSMMAPPING                                                               STD_OFF  /**< Deactivateable: 'BswM_LinSMMapping.ExternalId' Reason: 'No Mode Request for BswMLinSMIndication configured.' and Deactivateable: 'BswM_LinSMMapping.ExternalId' Reason: 'No Mode Request for BswMLinSMIndication configured.' */
#define BSWM_IMMEDIATEUSERENDIDXOFLINSMMAPPING                                                      STD_OFF  /**< Deactivateable: 'BswM_LinSMMapping.ImmediateUserEndIdx' Reason: 'No Mode Request for BswMLinSMIndication configured.' and Deactivateable: 'BswM_LinSMMapping.ImmediateUserEndIdx' Reason: 'No Mode Request for BswMLinSMIndication configured.' */
#define BSWM_IMMEDIATEUSERSTARTIDXOFLINSMMAPPING                                                    STD_OFF  /**< Deactivateable: 'BswM_LinSMMapping.ImmediateUserStartIdx' Reason: 'No Mode Request for BswMLinSMIndication configured.' and Deactivateable: 'BswM_LinSMMapping.ImmediateUserStartIdx' Reason: 'No Mode Request for BswMLinSMIndication configured.' */
#define BSWM_IMMEDIATEUSERUSEDOFLINSMMAPPING                                                        STD_OFF  /**< Deactivateable: 'BswM_LinSMMapping.ImmediateUserUsed' Reason: 'No Mode Request for BswMLinSMIndication configured.' and Deactivateable: 'BswM_LinSMMapping.ImmediateUserUsed' Reason: 'No Mode Request for BswMLinSMIndication configured.' */
#define BSWM_INITVALUEOFLINSMMAPPING                                                                STD_OFF  /**< Deactivateable: 'BswM_LinSMMapping.InitValue' Reason: 'No Mode Request for BswMLinSMIndication configured.' and Deactivateable: 'BswM_LinSMMapping.InitValue' Reason: 'No Mode Request for BswMLinSMIndication configured.' */
#define BSWM_LINSMSTATE                                                                             STD_OFF  /**< Deactivateable: 'BswM_LinSMState' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'BswM_LinSMState' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define BSWM_LINSCHEDULEENDMAPPING                                                                  STD_OFF  /**< Deactivateable: 'BswM_LinScheduleEndMapping' Reason: 'No Mode Request for BswMLinScheduleEndNotification configured.' and Deactivateable: 'BswM_LinScheduleEndMapping' Reason: 'No Mode Request for BswMLinScheduleEndNotification configured.' */
#define BSWM_EXTERNALIDOFLINSCHEDULEENDMAPPING                                                      STD_OFF  /**< Deactivateable: 'BswM_LinScheduleEndMapping.ExternalId' Reason: 'No Mode Request for BswMLinScheduleEndNotification configured.' and Deactivateable: 'BswM_LinScheduleEndMapping.ExternalId' Reason: 'No Mode Request for BswMLinScheduleEndNotification configured.' */
#define BSWM_IMMEDIATEUSERENDIDXOFLINSCHEDULEENDMAPPING                                             STD_OFF  /**< Deactivateable: 'BswM_LinScheduleEndMapping.ImmediateUserEndIdx' Reason: 'No Mode Request for BswMLinScheduleEndNotification configured.' and Deactivateable: 'BswM_LinScheduleEndMapping.ImmediateUserEndIdx' Reason: 'No Mode Request for BswMLinScheduleEndNotification configured.' */
#define BSWM_IMMEDIATEUSERSTARTIDXOFLINSCHEDULEENDMAPPING                                           STD_OFF  /**< Deactivateable: 'BswM_LinScheduleEndMapping.ImmediateUserStartIdx' Reason: 'No Mode Request for BswMLinScheduleEndNotification configured.' and Deactivateable: 'BswM_LinScheduleEndMapping.ImmediateUserStartIdx' Reason: 'No Mode Request for BswMLinScheduleEndNotification configured.' */
#define BSWM_IMMEDIATEUSERUSEDOFLINSCHEDULEENDMAPPING                                               STD_OFF  /**< Deactivateable: 'BswM_LinScheduleEndMapping.ImmediateUserUsed' Reason: 'No Mode Request for BswMLinScheduleEndNotification configured.' and Deactivateable: 'BswM_LinScheduleEndMapping.ImmediateUserUsed' Reason: 'No Mode Request for BswMLinScheduleEndNotification configured.' */
#define BSWM_INITVALUEOFLINSCHEDULEENDMAPPING                                                       STD_OFF  /**< Deactivateable: 'BswM_LinScheduleEndMapping.InitValue' Reason: 'No Mode Request for BswMLinScheduleEndNotification configured.' and Deactivateable: 'BswM_LinScheduleEndMapping.InitValue' Reason: 'No Mode Request for BswMLinScheduleEndNotification configured.' */
#define BSWM_LINSCHEDULEENDSTATE                                                                    STD_OFF  /**< Deactivateable: 'BswM_LinScheduleEndState' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'BswM_LinScheduleEndState' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define BSWM_LINSCHEDULEMAPPING                                                                     STD_OFF  /**< Deactivateable: 'BswM_LinScheduleMapping' Reason: 'No Mode Request for BswMLinScheduleIndication configured.' and Deactivateable: 'BswM_LinScheduleMapping' Reason: 'No Mode Request for BswMLinScheduleIndication configured.' */
#define BSWM_EXTERNALIDOFLINSCHEDULEMAPPING                                                         STD_OFF  /**< Deactivateable: 'BswM_LinScheduleMapping.ExternalId' Reason: 'No Mode Request for BswMLinScheduleIndication configured.' and Deactivateable: 'BswM_LinScheduleMapping.ExternalId' Reason: 'No Mode Request for BswMLinScheduleIndication configured.' */
#define BSWM_IMMEDIATEUSERENDIDXOFLINSCHEDULEMAPPING                                                STD_OFF  /**< Deactivateable: 'BswM_LinScheduleMapping.ImmediateUserEndIdx' Reason: 'No Mode Request for BswMLinScheduleIndication configured.' and Deactivateable: 'BswM_LinScheduleMapping.ImmediateUserEndIdx' Reason: 'No Mode Request for BswMLinScheduleIndication configured.' */
#define BSWM_IMMEDIATEUSERSTARTIDXOFLINSCHEDULEMAPPING                                              STD_OFF  /**< Deactivateable: 'BswM_LinScheduleMapping.ImmediateUserStartIdx' Reason: 'No Mode Request for BswMLinScheduleIndication configured.' and Deactivateable: 'BswM_LinScheduleMapping.ImmediateUserStartIdx' Reason: 'No Mode Request for BswMLinScheduleIndication configured.' */
#define BSWM_IMMEDIATEUSERUSEDOFLINSCHEDULEMAPPING                                                  STD_OFF  /**< Deactivateable: 'BswM_LinScheduleMapping.ImmediateUserUsed' Reason: 'No Mode Request for BswMLinScheduleIndication configured.' and Deactivateable: 'BswM_LinScheduleMapping.ImmediateUserUsed' Reason: 'No Mode Request for BswMLinScheduleIndication configured.' */
#define BSWM_INITVALUEOFLINSCHEDULEMAPPING                                                          STD_OFF  /**< Deactivateable: 'BswM_LinScheduleMapping.InitValue' Reason: 'No Mode Request for BswMLinScheduleIndication configured.' and Deactivateable: 'BswM_LinScheduleMapping.InitValue' Reason: 'No Mode Request for BswMLinScheduleIndication configured.' */
#define BSWM_LINSCHEDULEREQUESTPARAMETERS                                                           STD_OFF  /**< Deactivateable: 'BswM_LinScheduleRequestParameters' Reason: 'Action of type 'LinScheduleRequest' not in configuration.' and Deactivateable: 'BswM_LinScheduleRequestParameters' Reason: 'Action of type 'LinScheduleRequest' not in configuration.' */
#define BSWM_NETWORKOFLINSCHEDULEREQUESTPARAMETERS                                                  STD_OFF  /**< Deactivateable: 'BswM_LinScheduleRequestParameters.Network' Reason: 'Action of type 'LinScheduleRequest' not in configuration.' and Deactivateable: 'BswM_LinScheduleRequestParameters.Network' Reason: 'Action of type 'LinScheduleRequest' not in configuration.' */
#define BSWM_SCHEDULEOFLINSCHEDULEREQUESTPARAMETERS                                                 STD_OFF  /**< Deactivateable: 'BswM_LinScheduleRequestParameters.Schedule' Reason: 'Action of type 'LinScheduleRequest' not in configuration.' and Deactivateable: 'BswM_LinScheduleRequestParameters.Schedule' Reason: 'Action of type 'LinScheduleRequest' not in configuration.' */
#define BSWM_LINSCHEDULESTATE                                                                       STD_OFF  /**< Deactivateable: 'BswM_LinScheduleState' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'BswM_LinScheduleState' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define BSWM_LINTPMAPPING                                                                           STD_OFF  /**< Deactivateable: 'BswM_LinTPMapping' Reason: 'No Mode Request for BswMLinTpModeRequest configured.' and Deactivateable: 'BswM_LinTPMapping' Reason: 'No Mode Request for BswMLinTpModeRequest configured.' */
#define BSWM_EXTERNALIDOFLINTPMAPPING                                                               STD_OFF  /**< Deactivateable: 'BswM_LinTPMapping.ExternalId' Reason: 'No Mode Request for BswMLinTpModeRequest configured.' and Deactivateable: 'BswM_LinTPMapping.ExternalId' Reason: 'No Mode Request for BswMLinTpModeRequest configured.' */
#define BSWM_IMMEDIATEUSERENDIDXOFLINTPMAPPING                                                      STD_OFF  /**< Deactivateable: 'BswM_LinTPMapping.ImmediateUserEndIdx' Reason: 'No Mode Request for BswMLinTpModeRequest configured.' and Deactivateable: 'BswM_LinTPMapping.ImmediateUserEndIdx' Reason: 'No Mode Request for BswMLinTpModeRequest configured.' */
#define BSWM_IMMEDIATEUSERSTARTIDXOFLINTPMAPPING                                                    STD_OFF  /**< Deactivateable: 'BswM_LinTPMapping.ImmediateUserStartIdx' Reason: 'No Mode Request for BswMLinTpModeRequest configured.' and Deactivateable: 'BswM_LinTPMapping.ImmediateUserStartIdx' Reason: 'No Mode Request for BswMLinTpModeRequest configured.' */
#define BSWM_IMMEDIATEUSERUSEDOFLINTPMAPPING                                                        STD_OFF  /**< Deactivateable: 'BswM_LinTPMapping.ImmediateUserUsed' Reason: 'No Mode Request for BswMLinTpModeRequest configured.' and Deactivateable: 'BswM_LinTPMapping.ImmediateUserUsed' Reason: 'No Mode Request for BswMLinTpModeRequest configured.' */
#define BSWM_INITVALUEOFLINTPMAPPING                                                                STD_OFF  /**< Deactivateable: 'BswM_LinTPMapping.InitValue' Reason: 'No Mode Request for BswMLinTpModeRequest configured.' and Deactivateable: 'BswM_LinTPMapping.InitValue' Reason: 'No Mode Request for BswMLinTpModeRequest configured.' */
#define BSWM_LINTPSTATE                                                                             STD_OFF  /**< Deactivateable: 'BswM_LinTPState' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'BswM_LinTPState' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define BSWM_MODENOTIFICATIONFCT                                                                    STD_ON
#define BSWM_MODENOTIFICATIONMAPPING                                                                STD_OFF  /**< Deactivateable: 'BswM_ModeNotificationMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'BswM_ModeNotificationMapping' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define BSWM_IMMEDIATEUSERENDIDXOFMODENOTIFICATIONMAPPING                                           STD_OFF  /**< Deactivateable: 'BswM_ModeNotificationMapping.ImmediateUserEndIdx' Reason: 'the optional indirection is deactivated because ImmediateUserUsedOfModeNotificationMapping is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' and Deactivateable: 'BswM_ModeNotificationMapping.ImmediateUserEndIdx' Reason: 'the optional indirection is deactivated because ImmediateUserUsedOfModeNotificationMapping is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define BSWM_IMMEDIATEUSERSTARTIDXOFMODENOTIFICATIONMAPPING                                         STD_OFF  /**< Deactivateable: 'BswM_ModeNotificationMapping.ImmediateUserStartIdx' Reason: 'the optional indirection is deactivated because ImmediateUserUsedOfModeNotificationMapping is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' and Deactivateable: 'BswM_ModeNotificationMapping.ImmediateUserStartIdx' Reason: 'the optional indirection is deactivated because ImmediateUserUsedOfModeNotificationMapping is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define BSWM_IMMEDIATEUSERUSEDOFMODENOTIFICATIONMAPPING                                             STD_OFF  /**< Deactivateable: 'BswM_ModeNotificationMapping.ImmediateUserUsed' Reason: 'the optional indirection is deactivated because ImmediateUserUsedOfModeNotificationMapping is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' and Deactivateable: 'BswM_ModeNotificationMapping.ImmediateUserUsed' Reason: 'the optional indirection is deactivated because ImmediateUserUsedOfModeNotificationMapping is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define BSWM_MODEREQUESTMAPPING                                                                     STD_OFF  /**< Deactivateable: 'BswM_ModeRequestMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'BswM_ModeRequestMapping' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define BSWM_IMMEDIATEUSERENDIDXOFMODEREQUESTMAPPING                                                STD_OFF  /**< Deactivateable: 'BswM_ModeRequestMapping.ImmediateUserEndIdx' Reason: 'the optional indirection is deactivated because ImmediateUserUsedOfModeRequestMapping is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' and Deactivateable: 'BswM_ModeRequestMapping.ImmediateUserEndIdx' Reason: 'the optional indirection is deactivated because ImmediateUserUsedOfModeRequestMapping is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define BSWM_IMMEDIATEUSERSTARTIDXOFMODEREQUESTMAPPING                                              STD_OFF  /**< Deactivateable: 'BswM_ModeRequestMapping.ImmediateUserStartIdx' Reason: 'the optional indirection is deactivated because ImmediateUserUsedOfModeRequestMapping is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' and Deactivateable: 'BswM_ModeRequestMapping.ImmediateUserStartIdx' Reason: 'the optional indirection is deactivated because ImmediateUserUsedOfModeRequestMapping is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define BSWM_IMMEDIATEUSERUSEDOFMODEREQUESTMAPPING                                                  STD_OFF  /**< Deactivateable: 'BswM_ModeRequestMapping.ImmediateUserUsed' Reason: 'the optional indirection is deactivated because ImmediateUserUsedOfModeRequestMapping is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' and Deactivateable: 'BswM_ModeRequestMapping.ImmediateUserUsed' Reason: 'the optional indirection is deactivated because ImmediateUserUsedOfModeRequestMapping is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define BSWM_MODEREQUESTQUEUE                                                                       STD_ON
#define BSWM_NMCONTROLPARAMETERS                                                                    STD_OFF  /**< Deactivateable: 'BswM_NmControlParameters' Reason: 'Action of type 'NmControl' not in configuration.' and Deactivateable: 'BswM_NmControlParameters' Reason: 'Action of type 'NmControl' not in configuration.' */
#define BSWM_CHANNELOFNMCONTROLPARAMETERS                                                           STD_OFF  /**< Deactivateable: 'BswM_NmControlParameters.Channel' Reason: 'Action of type 'NmControl' not in configuration.' and Deactivateable: 'BswM_NmControlParameters.Channel' Reason: 'Action of type 'NmControl' not in configuration.' */
#define BSWM_CONTROLOFNMCONTROLPARAMETERS                                                           STD_OFF  /**< Deactivateable: 'BswM_NmControlParameters.Control' Reason: 'Action of type 'NmControl' not in configuration.' and Deactivateable: 'BswM_NmControlParameters.Control' Reason: 'Action of type 'NmControl' not in configuration.' */
#define BSWM_NMMAPPING                                                                              STD_OFF  /**< Deactivateable: 'BswM_NmMapping' Reason: 'No Mode Request for BswMNmIndication configured.' and Deactivateable: 'BswM_NmMapping' Reason: 'No Mode Request for BswMNmIndication configured.' */
#define BSWM_EXTERNALIDOFNMMAPPING                                                                  STD_OFF  /**< Deactivateable: 'BswM_NmMapping.ExternalId' Reason: 'No Mode Request for BswMNmIndication configured.' and Deactivateable: 'BswM_NmMapping.ExternalId' Reason: 'No Mode Request for BswMNmIndication configured.' */
#define BSWM_IMMEDIATEUSERENDIDXOFNMMAPPING                                                         STD_OFF  /**< Deactivateable: 'BswM_NmMapping.ImmediateUserEndIdx' Reason: 'No Mode Request for BswMNmIndication configured.' and Deactivateable: 'BswM_NmMapping.ImmediateUserEndIdx' Reason: 'No Mode Request for BswMNmIndication configured.' */
#define BSWM_IMMEDIATEUSERSTARTIDXOFNMMAPPING                                                       STD_OFF  /**< Deactivateable: 'BswM_NmMapping.ImmediateUserStartIdx' Reason: 'No Mode Request for BswMNmIndication configured.' and Deactivateable: 'BswM_NmMapping.ImmediateUserStartIdx' Reason: 'No Mode Request for BswMNmIndication configured.' */
#define BSWM_IMMEDIATEUSERUSEDOFNMMAPPING                                                           STD_OFF  /**< Deactivateable: 'BswM_NmMapping.ImmediateUserUsed' Reason: 'No Mode Request for BswMNmIndication configured.' and Deactivateable: 'BswM_NmMapping.ImmediateUserUsed' Reason: 'No Mode Request for BswMNmIndication configured.' */
#define BSWM_INITVALUEOFNMMAPPING                                                                   STD_OFF  /**< Deactivateable: 'BswM_NmMapping.InitValue' Reason: 'No Mode Request for BswMNmIndication configured.' and Deactivateable: 'BswM_NmMapping.InitValue' Reason: 'No Mode Request for BswMNmIndication configured.' */
#define BSWM_NMSTATE                                                                                STD_OFF  /**< Deactivateable: 'BswM_NmState' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'BswM_NmState' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define BSWM_NVMBLOCKMAPPING                                                                        STD_OFF  /**< Deactivateable: 'BswM_NvMBlockMapping' Reason: 'No Mode Request for BswMNvMRequest configured.' and Deactivateable: 'BswM_NvMBlockMapping' Reason: 'No Mode Request for BswMNvMRequest configured.' */
#define BSWM_EXTERNALIDOFNVMBLOCKMAPPING                                                            STD_OFF  /**< Deactivateable: 'BswM_NvMBlockMapping.ExternalId' Reason: 'No Mode Request for BswMNvMRequest configured.' and Deactivateable: 'BswM_NvMBlockMapping.ExternalId' Reason: 'No Mode Request for BswMNvMRequest configured.' */
#define BSWM_IMMEDIATEUSERENDIDXOFNVMBLOCKMAPPING                                                   STD_OFF  /**< Deactivateable: 'BswM_NvMBlockMapping.ImmediateUserEndIdx' Reason: 'No Mode Request for BswMNvMRequest configured.' and Deactivateable: 'BswM_NvMBlockMapping.ImmediateUserEndIdx' Reason: 'No Mode Request for BswMNvMRequest configured.' */
#define BSWM_IMMEDIATEUSERSTARTIDXOFNVMBLOCKMAPPING                                                 STD_OFF  /**< Deactivateable: 'BswM_NvMBlockMapping.ImmediateUserStartIdx' Reason: 'No Mode Request for BswMNvMRequest configured.' and Deactivateable: 'BswM_NvMBlockMapping.ImmediateUserStartIdx' Reason: 'No Mode Request for BswMNvMRequest configured.' */
#define BSWM_IMMEDIATEUSERUSEDOFNVMBLOCKMAPPING                                                     STD_OFF  /**< Deactivateable: 'BswM_NvMBlockMapping.ImmediateUserUsed' Reason: 'No Mode Request for BswMNvMRequest configured.' and Deactivateable: 'BswM_NvMBlockMapping.ImmediateUserUsed' Reason: 'No Mode Request for BswMNvMRequest configured.' */
#define BSWM_INITVALUEOFNVMBLOCKMAPPING                                                             STD_OFF  /**< Deactivateable: 'BswM_NvMBlockMapping.InitValue' Reason: 'No Mode Request for BswMNvMRequest configured.' and Deactivateable: 'BswM_NvMBlockMapping.InitValue' Reason: 'No Mode Request for BswMNvMRequest configured.' */
#define BSWM_NVMBLOCKSTATE                                                                          STD_OFF  /**< Deactivateable: 'BswM_NvMBlockState' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'BswM_NvMBlockState' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define BSWM_NVMJOBMAPPING                                                                          STD_OFF  /**< Deactivateable: 'BswM_NvMJobMapping' Reason: 'No Mode Request for BswMNvMJobModeIndication configured.' and Deactivateable: 'BswM_NvMJobMapping' Reason: 'No Mode Request for BswMNvMJobModeIndication configured.' */
#define BSWM_EXTERNALIDOFNVMJOBMAPPING                                                              STD_OFF  /**< Deactivateable: 'BswM_NvMJobMapping.ExternalId' Reason: 'No Mode Request for BswMNvMJobModeIndication configured.' and Deactivateable: 'BswM_NvMJobMapping.ExternalId' Reason: 'No Mode Request for BswMNvMJobModeIndication configured.' */
#define BSWM_IMMEDIATEUSERENDIDXOFNVMJOBMAPPING                                                     STD_OFF  /**< Deactivateable: 'BswM_NvMJobMapping.ImmediateUserEndIdx' Reason: 'No Mode Request for BswMNvMJobModeIndication configured.' and Deactivateable: 'BswM_NvMJobMapping.ImmediateUserEndIdx' Reason: 'No Mode Request for BswMNvMJobModeIndication configured.' */
#define BSWM_IMMEDIATEUSERSTARTIDXOFNVMJOBMAPPING                                                   STD_OFF  /**< Deactivateable: 'BswM_NvMJobMapping.ImmediateUserStartIdx' Reason: 'No Mode Request for BswMNvMJobModeIndication configured.' and Deactivateable: 'BswM_NvMJobMapping.ImmediateUserStartIdx' Reason: 'No Mode Request for BswMNvMJobModeIndication configured.' */
#define BSWM_IMMEDIATEUSERUSEDOFNVMJOBMAPPING                                                       STD_OFF  /**< Deactivateable: 'BswM_NvMJobMapping.ImmediateUserUsed' Reason: 'No Mode Request for BswMNvMJobModeIndication configured.' and Deactivateable: 'BswM_NvMJobMapping.ImmediateUserUsed' Reason: 'No Mode Request for BswMNvMJobModeIndication configured.' */
#define BSWM_INITVALUEOFNVMJOBMAPPING                                                               STD_OFF  /**< Deactivateable: 'BswM_NvMJobMapping.InitValue' Reason: 'No Mode Request for BswMNvMJobModeIndication configured.' and Deactivateable: 'BswM_NvMJobMapping.InitValue' Reason: 'No Mode Request for BswMNvMJobModeIndication configured.' */
#define BSWM_NVMJOBSTATE                                                                            STD_OFF  /**< Deactivateable: 'BswM_NvMJobState' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'BswM_NvMJobState' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define BSWM_PARTITIONIDENTIFIERS                                                                   STD_ON
#define BSWM_PCPARTITIONCONFIGIDXOFPARTITIONIDENTIFIERS                                             STD_ON
#define BSWM_PARTITIONSNVOFPARTITIONIDENTIFIERS                                                     STD_ON
#define BSWM_PDURPRETRANSMITMAPPING                                                                 STD_OFF  /**< Deactivateable: 'BswM_PduRPreTransmitMapping' Reason: 'No Mode Request for BswMPduRPreTransmit configured.' and Deactivateable: 'BswM_PduRPreTransmitMapping' Reason: 'No Mode Request for BswMPduRPreTransmit configured.' */
#define BSWM_EXTERNALIDOFPDURPRETRANSMITMAPPING                                                     STD_OFF  /**< Deactivateable: 'BswM_PduRPreTransmitMapping.ExternalId' Reason: 'No Mode Request for BswMPduRPreTransmit configured.' and Deactivateable: 'BswM_PduRPreTransmitMapping.ExternalId' Reason: 'No Mode Request for BswMPduRPreTransmit configured.' */
#define BSWM_IMMEDIATEUSERENDIDXOFPDURPRETRANSMITMAPPING                                            STD_OFF  /**< Deactivateable: 'BswM_PduRPreTransmitMapping.ImmediateUserEndIdx' Reason: 'No Mode Request for BswMPduRPreTransmit configured.' and Deactivateable: 'BswM_PduRPreTransmitMapping.ImmediateUserEndIdx' Reason: 'No Mode Request for BswMPduRPreTransmit configured.' */
#define BSWM_IMMEDIATEUSERSTARTIDXOFPDURPRETRANSMITMAPPING                                          STD_OFF  /**< Deactivateable: 'BswM_PduRPreTransmitMapping.ImmediateUserStartIdx' Reason: 'No Mode Request for BswMPduRPreTransmit configured.' and Deactivateable: 'BswM_PduRPreTransmitMapping.ImmediateUserStartIdx' Reason: 'No Mode Request for BswMPduRPreTransmit configured.' */
#define BSWM_IMMEDIATEUSERUSEDOFPDURPRETRANSMITMAPPING                                              STD_OFF  /**< Deactivateable: 'BswM_PduRPreTransmitMapping.ImmediateUserUsed' Reason: 'No Mode Request for BswMPduRPreTransmit configured.' and Deactivateable: 'BswM_PduRPreTransmitMapping.ImmediateUserUsed' Reason: 'No Mode Request for BswMPduRPreTransmit configured.' */
#define BSWM_INITVALUEOFPDURPRETRANSMITMAPPING                                                      STD_OFF  /**< Deactivateable: 'BswM_PduRPreTransmitMapping.InitValue' Reason: 'No Mode Request for BswMPduRPreTransmit configured.' and Deactivateable: 'BswM_PduRPreTransmitMapping.InitValue' Reason: 'No Mode Request for BswMPduRPreTransmit configured.' */
#define BSWM_PDURPRETRANSMITSTATEIDXOFPDURPRETRANSMITMAPPING                                        STD_OFF  /**< Deactivateable: 'BswM_PduRPreTransmitMapping.PduRPreTransmitStateIdx' Reason: 'No Mode Request for BswMPduRPreTransmit configured.' and Deactivateable: 'BswM_PduRPreTransmitMapping.PduRPreTransmitStateIdx' Reason: 'No Mode Request for BswMPduRPreTransmit configured.' */
#define BSWM_PDURPRETRANSMITSTATE                                                                   STD_OFF  /**< Deactivateable: 'BswM_PduRPreTransmitState' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'BswM_PduRPreTransmitState' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define BSWM_PDURRXINDICATIONMAPPING                                                                STD_OFF  /**< Deactivateable: 'BswM_PduRRxIndicationMapping' Reason: 'No Mode Request for BswMPduRRxIndication configured.' and Deactivateable: 'BswM_PduRRxIndicationMapping' Reason: 'No Mode Request for BswMPduRRxIndication configured.' */
#define BSWM_EXTERNALIDOFPDURRXINDICATIONMAPPING                                                    STD_OFF  /**< Deactivateable: 'BswM_PduRRxIndicationMapping.ExternalId' Reason: 'No Mode Request for BswMPduRRxIndication configured.' and Deactivateable: 'BswM_PduRRxIndicationMapping.ExternalId' Reason: 'No Mode Request for BswMPduRRxIndication configured.' */
#define BSWM_IMMEDIATEUSERENDIDXOFPDURRXINDICATIONMAPPING                                           STD_OFF  /**< Deactivateable: 'BswM_PduRRxIndicationMapping.ImmediateUserEndIdx' Reason: 'No Mode Request for BswMPduRRxIndication configured.' and Deactivateable: 'BswM_PduRRxIndicationMapping.ImmediateUserEndIdx' Reason: 'No Mode Request for BswMPduRRxIndication configured.' */
#define BSWM_IMMEDIATEUSERSTARTIDXOFPDURRXINDICATIONMAPPING                                         STD_OFF  /**< Deactivateable: 'BswM_PduRRxIndicationMapping.ImmediateUserStartIdx' Reason: 'No Mode Request for BswMPduRRxIndication configured.' and Deactivateable: 'BswM_PduRRxIndicationMapping.ImmediateUserStartIdx' Reason: 'No Mode Request for BswMPduRRxIndication configured.' */
#define BSWM_IMMEDIATEUSERUSEDOFPDURRXINDICATIONMAPPING                                             STD_OFF  /**< Deactivateable: 'BswM_PduRRxIndicationMapping.ImmediateUserUsed' Reason: 'No Mode Request for BswMPduRRxIndication configured.' and Deactivateable: 'BswM_PduRRxIndicationMapping.ImmediateUserUsed' Reason: 'No Mode Request for BswMPduRRxIndication configured.' */
#define BSWM_INITVALUEOFPDURRXINDICATIONMAPPING                                                     STD_OFF  /**< Deactivateable: 'BswM_PduRRxIndicationMapping.InitValue' Reason: 'No Mode Request for BswMPduRRxIndication configured.' and Deactivateable: 'BswM_PduRRxIndicationMapping.InitValue' Reason: 'No Mode Request for BswMPduRRxIndication configured.' */
#define BSWM_PDURRXINDICATIONSTATEIDXOFPDURRXINDICATIONMAPPING                                      STD_OFF  /**< Deactivateable: 'BswM_PduRRxIndicationMapping.PduRRxIndicationStateIdx' Reason: 'No Mode Request for BswMPduRRxIndication configured.' and Deactivateable: 'BswM_PduRRxIndicationMapping.PduRRxIndicationStateIdx' Reason: 'No Mode Request for BswMPduRRxIndication configured.' */
#define BSWM_PDURRXINDICATIONSTATE                                                                  STD_OFF  /**< Deactivateable: 'BswM_PduRRxIndicationState' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'BswM_PduRRxIndicationState' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define BSWM_PDURTPRXINDICATIONMAPPING                                                              STD_OFF  /**< Deactivateable: 'BswM_PduRTpRxIndicationMapping' Reason: 'No Mode Request for BswMPduRTpRxIndication configured.' and Deactivateable: 'BswM_PduRTpRxIndicationMapping' Reason: 'No Mode Request for BswMPduRTpRxIndication configured.' */
#define BSWM_EXTERNALIDOFPDURTPRXINDICATIONMAPPING                                                  STD_OFF  /**< Deactivateable: 'BswM_PduRTpRxIndicationMapping.ExternalId' Reason: 'No Mode Request for BswMPduRTpRxIndication configured.' and Deactivateable: 'BswM_PduRTpRxIndicationMapping.ExternalId' Reason: 'No Mode Request for BswMPduRTpRxIndication configured.' */
#define BSWM_IMMEDIATEUSERENDIDXOFPDURTPRXINDICATIONMAPPING                                         STD_OFF  /**< Deactivateable: 'BswM_PduRTpRxIndicationMapping.ImmediateUserEndIdx' Reason: 'No Mode Request for BswMPduRTpRxIndication configured.' and Deactivateable: 'BswM_PduRTpRxIndicationMapping.ImmediateUserEndIdx' Reason: 'No Mode Request for BswMPduRTpRxIndication configured.' */
#define BSWM_IMMEDIATEUSERSTARTIDXOFPDURTPRXINDICATIONMAPPING                                       STD_OFF  /**< Deactivateable: 'BswM_PduRTpRxIndicationMapping.ImmediateUserStartIdx' Reason: 'No Mode Request for BswMPduRTpRxIndication configured.' and Deactivateable: 'BswM_PduRTpRxIndicationMapping.ImmediateUserStartIdx' Reason: 'No Mode Request for BswMPduRTpRxIndication configured.' */
#define BSWM_IMMEDIATEUSERUSEDOFPDURTPRXINDICATIONMAPPING                                           STD_OFF  /**< Deactivateable: 'BswM_PduRTpRxIndicationMapping.ImmediateUserUsed' Reason: 'No Mode Request for BswMPduRTpRxIndication configured.' and Deactivateable: 'BswM_PduRTpRxIndicationMapping.ImmediateUserUsed' Reason: 'No Mode Request for BswMPduRTpRxIndication configured.' */
#define BSWM_INITVALUEOFPDURTPRXINDICATIONMAPPING                                                   STD_OFF  /**< Deactivateable: 'BswM_PduRTpRxIndicationMapping.InitValue' Reason: 'No Mode Request for BswMPduRTpRxIndication configured.' and Deactivateable: 'BswM_PduRTpRxIndicationMapping.InitValue' Reason: 'No Mode Request for BswMPduRTpRxIndication configured.' */
#define BSWM_PDURTPRXINDICATIONSTATEIDXOFPDURTPRXINDICATIONMAPPING                                  STD_OFF  /**< Deactivateable: 'BswM_PduRTpRxIndicationMapping.PduRTpRxIndicationStateIdx' Reason: 'No Mode Request for BswMPduRTpRxIndication configured.' and Deactivateable: 'BswM_PduRTpRxIndicationMapping.PduRTpRxIndicationStateIdx' Reason: 'No Mode Request for BswMPduRTpRxIndication configured.' */
#define BSWM_PDURTPRXINDICATIONSTATE                                                                STD_OFF  /**< Deactivateable: 'BswM_PduRTpRxIndicationState' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'BswM_PduRTpRxIndicationState' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define BSWM_PDURTPSTARTOFRECEPTIONMAPPING                                                          STD_OFF  /**< Deactivateable: 'BswM_PduRTpStartOfReceptionMapping' Reason: 'No Mode Request for BswMPduRTpStartOfReception configured.' and Deactivateable: 'BswM_PduRTpStartOfReceptionMapping' Reason: 'No Mode Request for BswMPduRTpStartOfReception configured.' */
#define BSWM_EXTERNALIDOFPDURTPSTARTOFRECEPTIONMAPPING                                              STD_OFF  /**< Deactivateable: 'BswM_PduRTpStartOfReceptionMapping.ExternalId' Reason: 'No Mode Request for BswMPduRTpStartOfReception configured.' and Deactivateable: 'BswM_PduRTpStartOfReceptionMapping.ExternalId' Reason: 'No Mode Request for BswMPduRTpStartOfReception configured.' */
#define BSWM_IMMEDIATEUSERENDIDXOFPDURTPSTARTOFRECEPTIONMAPPING                                     STD_OFF  /**< Deactivateable: 'BswM_PduRTpStartOfReceptionMapping.ImmediateUserEndIdx' Reason: 'No Mode Request for BswMPduRTpStartOfReception configured.' and Deactivateable: 'BswM_PduRTpStartOfReceptionMapping.ImmediateUserEndIdx' Reason: 'No Mode Request for BswMPduRTpStartOfReception configured.' */
#define BSWM_IMMEDIATEUSERSTARTIDXOFPDURTPSTARTOFRECEPTIONMAPPING                                   STD_OFF  /**< Deactivateable: 'BswM_PduRTpStartOfReceptionMapping.ImmediateUserStartIdx' Reason: 'No Mode Request for BswMPduRTpStartOfReception configured.' and Deactivateable: 'BswM_PduRTpStartOfReceptionMapping.ImmediateUserStartIdx' Reason: 'No Mode Request for BswMPduRTpStartOfReception configured.' */
#define BSWM_IMMEDIATEUSERUSEDOFPDURTPSTARTOFRECEPTIONMAPPING                                       STD_OFF  /**< Deactivateable: 'BswM_PduRTpStartOfReceptionMapping.ImmediateUserUsed' Reason: 'No Mode Request for BswMPduRTpStartOfReception configured.' and Deactivateable: 'BswM_PduRTpStartOfReceptionMapping.ImmediateUserUsed' Reason: 'No Mode Request for BswMPduRTpStartOfReception configured.' */
#define BSWM_INITVALUEOFPDURTPSTARTOFRECEPTIONMAPPING                                               STD_OFF  /**< Deactivateable: 'BswM_PduRTpStartOfReceptionMapping.InitValue' Reason: 'No Mode Request for BswMPduRTpStartOfReception configured.' and Deactivateable: 'BswM_PduRTpStartOfReceptionMapping.InitValue' Reason: 'No Mode Request for BswMPduRTpStartOfReception configured.' */
#define BSWM_PDURTPSTARTOFRECEPTIONSTATEIDXOFPDURTPSTARTOFRECEPTIONMAPPING                          STD_OFF  /**< Deactivateable: 'BswM_PduRTpStartOfReceptionMapping.PduRTpStartOfReceptionStateIdx' Reason: 'No Mode Request for BswMPduRTpStartOfReception configured.' and Deactivateable: 'BswM_PduRTpStartOfReceptionMapping.PduRTpStartOfReceptionStateIdx' Reason: 'No Mode Request for BswMPduRTpStartOfReception configured.' */
#define BSWM_PDURTPSTARTOFRECEPTIONSTATE                                                            STD_OFF  /**< Deactivateable: 'BswM_PduRTpStartOfReceptionState' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'BswM_PduRTpStartOfReceptionState' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define BSWM_PDURTPTXCONFIRMATIONMAPPING                                                            STD_OFF  /**< Deactivateable: 'BswM_PduRTpTxConfirmationMapping' Reason: 'No Mode Request for BswMPduRTpTxConfirmation configured.' and Deactivateable: 'BswM_PduRTpTxConfirmationMapping' Reason: 'No Mode Request for BswMPduRTpTxConfirmation configured.' */
#define BSWM_EXTERNALIDOFPDURTPTXCONFIRMATIONMAPPING                                                STD_OFF  /**< Deactivateable: 'BswM_PduRTpTxConfirmationMapping.ExternalId' Reason: 'No Mode Request for BswMPduRTpTxConfirmation configured.' and Deactivateable: 'BswM_PduRTpTxConfirmationMapping.ExternalId' Reason: 'No Mode Request for BswMPduRTpTxConfirmation configured.' */
#define BSWM_IMMEDIATEUSERENDIDXOFPDURTPTXCONFIRMATIONMAPPING                                       STD_OFF  /**< Deactivateable: 'BswM_PduRTpTxConfirmationMapping.ImmediateUserEndIdx' Reason: 'No Mode Request for BswMPduRTpTxConfirmation configured.' and Deactivateable: 'BswM_PduRTpTxConfirmationMapping.ImmediateUserEndIdx' Reason: 'No Mode Request for BswMPduRTpTxConfirmation configured.' */
#define BSWM_IMMEDIATEUSERSTARTIDXOFPDURTPTXCONFIRMATIONMAPPING                                     STD_OFF  /**< Deactivateable: 'BswM_PduRTpTxConfirmationMapping.ImmediateUserStartIdx' Reason: 'No Mode Request for BswMPduRTpTxConfirmation configured.' and Deactivateable: 'BswM_PduRTpTxConfirmationMapping.ImmediateUserStartIdx' Reason: 'No Mode Request for BswMPduRTpTxConfirmation configured.' */
#define BSWM_IMMEDIATEUSERUSEDOFPDURTPTXCONFIRMATIONMAPPING                                         STD_OFF  /**< Deactivateable: 'BswM_PduRTpTxConfirmationMapping.ImmediateUserUsed' Reason: 'No Mode Request for BswMPduRTpTxConfirmation configured.' and Deactivateable: 'BswM_PduRTpTxConfirmationMapping.ImmediateUserUsed' Reason: 'No Mode Request for BswMPduRTpTxConfirmation configured.' */
#define BSWM_INITVALUEOFPDURTPTXCONFIRMATIONMAPPING                                                 STD_OFF  /**< Deactivateable: 'BswM_PduRTpTxConfirmationMapping.InitValue' Reason: 'No Mode Request for BswMPduRTpTxConfirmation configured.' and Deactivateable: 'BswM_PduRTpTxConfirmationMapping.InitValue' Reason: 'No Mode Request for BswMPduRTpTxConfirmation configured.' */
#define BSWM_PDURTPTXCONFIRMATIONSTATEIDXOFPDURTPTXCONFIRMATIONMAPPING                              STD_OFF  /**< Deactivateable: 'BswM_PduRTpTxConfirmationMapping.PduRTpTxConfirmationStateIdx' Reason: 'No Mode Request for BswMPduRTpTxConfirmation configured.' and Deactivateable: 'BswM_PduRTpTxConfirmationMapping.PduRTpTxConfirmationStateIdx' Reason: 'No Mode Request for BswMPduRTpTxConfirmation configured.' */
#define BSWM_PDURTPTXCONFIRMATIONSTATE                                                              STD_OFF  /**< Deactivateable: 'BswM_PduRTpTxConfirmationState' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'BswM_PduRTpTxConfirmationState' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define BSWM_PDURTRANSMITMAPPING                                                                    STD_OFF  /**< Deactivateable: 'BswM_PduRTransmitMapping' Reason: 'No Mode Request for BswMPduRTransmit configured.' and Deactivateable: 'BswM_PduRTransmitMapping' Reason: 'No Mode Request for BswMPduRTransmit configured.' */
#define BSWM_EXTERNALIDOFPDURTRANSMITMAPPING                                                        STD_OFF  /**< Deactivateable: 'BswM_PduRTransmitMapping.ExternalId' Reason: 'No Mode Request for BswMPduRTransmit configured.' and Deactivateable: 'BswM_PduRTransmitMapping.ExternalId' Reason: 'No Mode Request for BswMPduRTransmit configured.' */
#define BSWM_IMMEDIATEUSERENDIDXOFPDURTRANSMITMAPPING                                               STD_OFF  /**< Deactivateable: 'BswM_PduRTransmitMapping.ImmediateUserEndIdx' Reason: 'No Mode Request for BswMPduRTransmit configured.' and Deactivateable: 'BswM_PduRTransmitMapping.ImmediateUserEndIdx' Reason: 'No Mode Request for BswMPduRTransmit configured.' */
#define BSWM_IMMEDIATEUSERSTARTIDXOFPDURTRANSMITMAPPING                                             STD_OFF  /**< Deactivateable: 'BswM_PduRTransmitMapping.ImmediateUserStartIdx' Reason: 'No Mode Request for BswMPduRTransmit configured.' and Deactivateable: 'BswM_PduRTransmitMapping.ImmediateUserStartIdx' Reason: 'No Mode Request for BswMPduRTransmit configured.' */
#define BSWM_IMMEDIATEUSERUSEDOFPDURTRANSMITMAPPING                                                 STD_OFF  /**< Deactivateable: 'BswM_PduRTransmitMapping.ImmediateUserUsed' Reason: 'No Mode Request for BswMPduRTransmit configured.' and Deactivateable: 'BswM_PduRTransmitMapping.ImmediateUserUsed' Reason: 'No Mode Request for BswMPduRTransmit configured.' */
#define BSWM_INITVALUEOFPDURTRANSMITMAPPING                                                         STD_OFF  /**< Deactivateable: 'BswM_PduRTransmitMapping.InitValue' Reason: 'No Mode Request for BswMPduRTransmit configured.' and Deactivateable: 'BswM_PduRTransmitMapping.InitValue' Reason: 'No Mode Request for BswMPduRTransmit configured.' */
#define BSWM_PDURTRANSMITSTATEIDXOFPDURTRANSMITMAPPING                                              STD_OFF  /**< Deactivateable: 'BswM_PduRTransmitMapping.PduRTransmitStateIdx' Reason: 'No Mode Request for BswMPduRTransmit configured.' and Deactivateable: 'BswM_PduRTransmitMapping.PduRTransmitStateIdx' Reason: 'No Mode Request for BswMPduRTransmit configured.' */
#define BSWM_PDURTRANSMITSTATE                                                                      STD_OFF  /**< Deactivateable: 'BswM_PduRTransmitState' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'BswM_PduRTransmitState' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define BSWM_PDURTXCONFIRMATIONMAPPING                                                              STD_OFF  /**< Deactivateable: 'BswM_PduRTxConfirmationMapping' Reason: 'No Mode Request for BswMPduRTxConfirmation configured.' and Deactivateable: 'BswM_PduRTxConfirmationMapping' Reason: 'No Mode Request for BswMPduRTxConfirmation configured.' */
#define BSWM_EXTERNALIDOFPDURTXCONFIRMATIONMAPPING                                                  STD_OFF  /**< Deactivateable: 'BswM_PduRTxConfirmationMapping.ExternalId' Reason: 'No Mode Request for BswMPduRTxConfirmation configured.' and Deactivateable: 'BswM_PduRTxConfirmationMapping.ExternalId' Reason: 'No Mode Request for BswMPduRTxConfirmation configured.' */
#define BSWM_IMMEDIATEUSERENDIDXOFPDURTXCONFIRMATIONMAPPING                                         STD_OFF  /**< Deactivateable: 'BswM_PduRTxConfirmationMapping.ImmediateUserEndIdx' Reason: 'No Mode Request for BswMPduRTxConfirmation configured.' and Deactivateable: 'BswM_PduRTxConfirmationMapping.ImmediateUserEndIdx' Reason: 'No Mode Request for BswMPduRTxConfirmation configured.' */
#define BSWM_IMMEDIATEUSERSTARTIDXOFPDURTXCONFIRMATIONMAPPING                                       STD_OFF  /**< Deactivateable: 'BswM_PduRTxConfirmationMapping.ImmediateUserStartIdx' Reason: 'No Mode Request for BswMPduRTxConfirmation configured.' and Deactivateable: 'BswM_PduRTxConfirmationMapping.ImmediateUserStartIdx' Reason: 'No Mode Request for BswMPduRTxConfirmation configured.' */
#define BSWM_IMMEDIATEUSERUSEDOFPDURTXCONFIRMATIONMAPPING                                           STD_OFF  /**< Deactivateable: 'BswM_PduRTxConfirmationMapping.ImmediateUserUsed' Reason: 'No Mode Request for BswMPduRTxConfirmation configured.' and Deactivateable: 'BswM_PduRTxConfirmationMapping.ImmediateUserUsed' Reason: 'No Mode Request for BswMPduRTxConfirmation configured.' */
#define BSWM_INITVALUEOFPDURTXCONFIRMATIONMAPPING                                                   STD_OFF  /**< Deactivateable: 'BswM_PduRTxConfirmationMapping.InitValue' Reason: 'No Mode Request for BswMPduRTxConfirmation configured.' and Deactivateable: 'BswM_PduRTxConfirmationMapping.InitValue' Reason: 'No Mode Request for BswMPduRTxConfirmation configured.' */
#define BSWM_PDURTXCONFIRMATIONSTATEIDXOFPDURTXCONFIRMATIONMAPPING                                  STD_OFF  /**< Deactivateable: 'BswM_PduRTxConfirmationMapping.PduRTxConfirmationStateIdx' Reason: 'No Mode Request for BswMPduRTxConfirmation configured.' and Deactivateable: 'BswM_PduRTxConfirmationMapping.PduRTxConfirmationStateIdx' Reason: 'No Mode Request for BswMPduRTxConfirmation configured.' */
#define BSWM_PDURTXCONFIRMATIONSTATE                                                                STD_OFF  /**< Deactivateable: 'BswM_PduRTxConfirmationState' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'BswM_PduRTxConfirmationState' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define BSWM_PDUROUTERCONTROLPARAMETERS                                                             STD_OFF  /**< Deactivateable: 'BswM_PduRouterControlParameters' Reason: 'Action of type 'PduRouterControl' not in configuration.' and Deactivateable: 'BswM_PduRouterControlParameters' Reason: 'Action of type 'PduRouterControl' not in configuration.' */
#define BSWM_PDUROUTERCONTROLSUBPARAMETERSENDIDXOFPDUROUTERCONTROLPARAMETERS                        STD_OFF  /**< Deactivateable: 'BswM_PduRouterControlParameters.PduRouterControlSubParametersEndIdx' Reason: 'Action of type 'PduRouterControl' not in configuration.' and Deactivateable: 'BswM_PduRouterControlParameters.PduRouterControlSubParametersEndIdx' Reason: 'Action of type 'PduRouterControl' not in configuration.' */
#define BSWM_PDUROUTERCONTROLSUBPARAMETERSSTARTIDXOFPDUROUTERCONTROLPARAMETERS                      STD_OFF  /**< Deactivateable: 'BswM_PduRouterControlParameters.PduRouterControlSubParametersStartIdx' Reason: 'Action of type 'PduRouterControl' not in configuration.' and Deactivateable: 'BswM_PduRouterControlParameters.PduRouterControlSubParametersStartIdx' Reason: 'Action of type 'PduRouterControl' not in configuration.' */
#define BSWM_PDUROUTERCONTROLSUBPARAMETERSUSEDOFPDUROUTERCONTROLPARAMETERS                          STD_OFF  /**< Deactivateable: 'BswM_PduRouterControlParameters.PduRouterControlSubParametersUsed' Reason: 'Action of type 'PduRouterControl' not in configuration.' and Deactivateable: 'BswM_PduRouterControlParameters.PduRouterControlSubParametersUsed' Reason: 'Action of type 'PduRouterControl' not in configuration.' */
#define BSWM_ROUTINGOFPDUROUTERCONTROLPARAMETERS                                                    STD_OFF  /**< Deactivateable: 'BswM_PduRouterControlParameters.Routing' Reason: 'Action of type 'PduRouterControl' not in configuration.' and Deactivateable: 'BswM_PduRouterControlParameters.Routing' Reason: 'Action of type 'PduRouterControl' not in configuration.' */
#define BSWM_PDUROUTERCONTROLSUBPARAMETERS                                                          STD_OFF  /**< Deactivateable: 'BswM_PduRouterControlSubParameters' Reason: 'Action of type 'PduRouterControl' not in configuration.' and Deactivateable: 'BswM_PduRouterControlSubParameters' Reason: 'Action of type 'PduRouterControl' not in configuration.' */
#define BSWM_IDOFPDUROUTERCONTROLSUBPARAMETERS                                                      STD_OFF  /**< Deactivateable: 'BswM_PduRouterControlSubParameters.Id' Reason: 'Action of type 'PduRouterControl' not in configuration.' and Deactivateable: 'BswM_PduRouterControlSubParameters.Id' Reason: 'Action of type 'PduRouterControl' not in configuration.' */
#define BSWM_QUEUESEMAPHORE                                                                         STD_ON
#define BSWM_QUEUEWRITTEN                                                                           STD_ON
#define BSWM_RULECONTROLPARAMETERS                                                                  STD_OFF  /**< Deactivateable: 'BswM_RuleControlParameters' Reason: 'Action of type 'RuleControl' not in configuration.' and Deactivateable: 'BswM_RuleControlParameters' Reason: 'Action of type 'RuleControl' not in configuration.' */
#define BSWM_RULEIDOFRULECONTROLPARAMETERS                                                          STD_OFF  /**< Deactivateable: 'BswM_RuleControlParameters.RuleId' Reason: 'Action of type 'RuleControl' not in configuration.' and Deactivateable: 'BswM_RuleControlParameters.RuleId' Reason: 'Action of type 'RuleControl' not in configuration.' */
#define BSWM_STATEOFRULECONTROLPARAMETERS                                                           STD_OFF  /**< Deactivateable: 'BswM_RuleControlParameters.State' Reason: 'Action of type 'RuleControl' not in configuration.' and Deactivateable: 'BswM_RuleControlParameters.State' Reason: 'Action of type 'RuleControl' not in configuration.' */
#define BSWM_RULESTATES                                                                             STD_ON
#define BSWM_RULES                                                                                  STD_ON
#define BSWM_ACTIONLISTSFALSEIDXOFRULES                                                             STD_ON
#define BSWM_ACTIONLISTSFALSEUSEDOFRULES                                                            STD_ON
#define BSWM_ACTIONLISTSTRUEIDXOFRULES                                                              STD_ON
#define BSWM_ACTIONLISTSTRUEUSEDOFRULES                                                             STD_ON
#define BSWM_EXPRESSIONSIDXOFRULES                                                                  STD_ON
#define BSWM_IDOFRULES                                                                              STD_ON
#define BSWM_INITOFRULES                                                                            STD_ON
#define BSWM_RULESTATESIDXOFRULES                                                                   STD_ON
#define BSWM_RULESIND                                                                               STD_ON
#define BSWM_SDCLIENTPARAMETERS                                                                     STD_OFF  /**< Deactivateable: 'BswM_SdClientParameters' Reason: 'Action of type 'SdClient' not in configuration.' and Deactivateable: 'BswM_SdClientParameters' Reason: 'Action of type 'SdClient' not in configuration.' */
#define BSWM_IDOFSDCLIENTPARAMETERS                                                                 STD_OFF  /**< Deactivateable: 'BswM_SdClientParameters.Id' Reason: 'Action of type 'SdClient' not in configuration.' and Deactivateable: 'BswM_SdClientParameters.Id' Reason: 'Action of type 'SdClient' not in configuration.' */
#define BSWM_STATEOFSDCLIENTPARAMETERS                                                              STD_OFF  /**< Deactivateable: 'BswM_SdClientParameters.State' Reason: 'Action of type 'SdClient' not in configuration.' and Deactivateable: 'BswM_SdClientParameters.State' Reason: 'Action of type 'SdClient' not in configuration.' */
#define BSWM_SDCLIENTSERVICEMAPPING                                                                 STD_OFF  /**< Deactivateable: 'BswM_SdClientServiceMapping' Reason: 'No Mode Request for BswMSdClientServiceCurrentState configured.' and Deactivateable: 'BswM_SdClientServiceMapping' Reason: 'No Mode Request for BswMSdClientServiceCurrentState configured.' */
#define BSWM_EXTERNALIDOFSDCLIENTSERVICEMAPPING                                                     STD_OFF  /**< Deactivateable: 'BswM_SdClientServiceMapping.ExternalId' Reason: 'No Mode Request for BswMSdClientServiceCurrentState configured.' and Deactivateable: 'BswM_SdClientServiceMapping.ExternalId' Reason: 'No Mode Request for BswMSdClientServiceCurrentState configured.' */
#define BSWM_IMMEDIATEUSERENDIDXOFSDCLIENTSERVICEMAPPING                                            STD_OFF  /**< Deactivateable: 'BswM_SdClientServiceMapping.ImmediateUserEndIdx' Reason: 'No Mode Request for BswMSdClientServiceCurrentState configured.' and Deactivateable: 'BswM_SdClientServiceMapping.ImmediateUserEndIdx' Reason: 'No Mode Request for BswMSdClientServiceCurrentState configured.' */
#define BSWM_IMMEDIATEUSERSTARTIDXOFSDCLIENTSERVICEMAPPING                                          STD_OFF  /**< Deactivateable: 'BswM_SdClientServiceMapping.ImmediateUserStartIdx' Reason: 'No Mode Request for BswMSdClientServiceCurrentState configured.' and Deactivateable: 'BswM_SdClientServiceMapping.ImmediateUserStartIdx' Reason: 'No Mode Request for BswMSdClientServiceCurrentState configured.' */
#define BSWM_IMMEDIATEUSERUSEDOFSDCLIENTSERVICEMAPPING                                              STD_OFF  /**< Deactivateable: 'BswM_SdClientServiceMapping.ImmediateUserUsed' Reason: 'No Mode Request for BswMSdClientServiceCurrentState configured.' and Deactivateable: 'BswM_SdClientServiceMapping.ImmediateUserUsed' Reason: 'No Mode Request for BswMSdClientServiceCurrentState configured.' */
#define BSWM_INITVALUEOFSDCLIENTSERVICEMAPPING                                                      STD_OFF  /**< Deactivateable: 'BswM_SdClientServiceMapping.InitValue' Reason: 'No Mode Request for BswMSdClientServiceCurrentState configured.' and Deactivateable: 'BswM_SdClientServiceMapping.InitValue' Reason: 'No Mode Request for BswMSdClientServiceCurrentState configured.' */
#define BSWM_SDCLIENTSERVICESTATE                                                                   STD_OFF  /**< Deactivateable: 'BswM_SdClientServiceState' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'BswM_SdClientServiceState' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define BSWM_SDCONSUMEDEVENTMAPPING                                                                 STD_OFF  /**< Deactivateable: 'BswM_SdConsumedEventMapping' Reason: 'No Mode Request for BswMSdConsumedEventGroupCurrentState configured.' and Deactivateable: 'BswM_SdConsumedEventMapping' Reason: 'No Mode Request for BswMSdConsumedEventGroupCurrentState configured.' */
#define BSWM_EXTERNALIDOFSDCONSUMEDEVENTMAPPING                                                     STD_OFF  /**< Deactivateable: 'BswM_SdConsumedEventMapping.ExternalId' Reason: 'No Mode Request for BswMSdConsumedEventGroupCurrentState configured.' and Deactivateable: 'BswM_SdConsumedEventMapping.ExternalId' Reason: 'No Mode Request for BswMSdConsumedEventGroupCurrentState configured.' */
#define BSWM_IMMEDIATEUSERENDIDXOFSDCONSUMEDEVENTMAPPING                                            STD_OFF  /**< Deactivateable: 'BswM_SdConsumedEventMapping.ImmediateUserEndIdx' Reason: 'No Mode Request for BswMSdConsumedEventGroupCurrentState configured.' and Deactivateable: 'BswM_SdConsumedEventMapping.ImmediateUserEndIdx' Reason: 'No Mode Request for BswMSdConsumedEventGroupCurrentState configured.' */
#define BSWM_IMMEDIATEUSERSTARTIDXOFSDCONSUMEDEVENTMAPPING                                          STD_OFF  /**< Deactivateable: 'BswM_SdConsumedEventMapping.ImmediateUserStartIdx' Reason: 'No Mode Request for BswMSdConsumedEventGroupCurrentState configured.' and Deactivateable: 'BswM_SdConsumedEventMapping.ImmediateUserStartIdx' Reason: 'No Mode Request for BswMSdConsumedEventGroupCurrentState configured.' */
#define BSWM_IMMEDIATEUSERUSEDOFSDCONSUMEDEVENTMAPPING                                              STD_OFF  /**< Deactivateable: 'BswM_SdConsumedEventMapping.ImmediateUserUsed' Reason: 'No Mode Request for BswMSdConsumedEventGroupCurrentState configured.' and Deactivateable: 'BswM_SdConsumedEventMapping.ImmediateUserUsed' Reason: 'No Mode Request for BswMSdConsumedEventGroupCurrentState configured.' */
#define BSWM_INITVALUEOFSDCONSUMEDEVENTMAPPING                                                      STD_OFF  /**< Deactivateable: 'BswM_SdConsumedEventMapping.InitValue' Reason: 'No Mode Request for BswMSdConsumedEventGroupCurrentState configured.' and Deactivateable: 'BswM_SdConsumedEventMapping.InitValue' Reason: 'No Mode Request for BswMSdConsumedEventGroupCurrentState configured.' */
#define BSWM_SDCONSUMEDEVENTSTATE                                                                   STD_OFF  /**< Deactivateable: 'BswM_SdConsumedEventState' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'BswM_SdConsumedEventState' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define BSWM_SDCONSUMEDPARAMETERS                                                                   STD_OFF  /**< Deactivateable: 'BswM_SdConsumedParameters' Reason: 'Action of type 'SdConsumed' not in configuration.' and Deactivateable: 'BswM_SdConsumedParameters' Reason: 'Action of type 'SdConsumed' not in configuration.' */
#define BSWM_IDOFSDCONSUMEDPARAMETERS                                                               STD_OFF  /**< Deactivateable: 'BswM_SdConsumedParameters.Id' Reason: 'Action of type 'SdConsumed' not in configuration.' and Deactivateable: 'BswM_SdConsumedParameters.Id' Reason: 'Action of type 'SdConsumed' not in configuration.' */
#define BSWM_STATEOFSDCONSUMEDPARAMETERS                                                            STD_OFF  /**< Deactivateable: 'BswM_SdConsumedParameters.State' Reason: 'Action of type 'SdConsumed' not in configuration.' and Deactivateable: 'BswM_SdConsumedParameters.State' Reason: 'Action of type 'SdConsumed' not in configuration.' */
#define BSWM_SDEVENTHANDLERMAPPING                                                                  STD_OFF  /**< Deactivateable: 'BswM_SdEventHandlerMapping' Reason: 'No Mode Request for BswMSdEventHandlerCurrentState configured.' and Deactivateable: 'BswM_SdEventHandlerMapping' Reason: 'No Mode Request for BswMSdEventHandlerCurrentState configured.' */
#define BSWM_EXTERNALIDOFSDEVENTHANDLERMAPPING                                                      STD_OFF  /**< Deactivateable: 'BswM_SdEventHandlerMapping.ExternalId' Reason: 'No Mode Request for BswMSdEventHandlerCurrentState configured.' and Deactivateable: 'BswM_SdEventHandlerMapping.ExternalId' Reason: 'No Mode Request for BswMSdEventHandlerCurrentState configured.' */
#define BSWM_IMMEDIATEUSERENDIDXOFSDEVENTHANDLERMAPPING                                             STD_OFF  /**< Deactivateable: 'BswM_SdEventHandlerMapping.ImmediateUserEndIdx' Reason: 'No Mode Request for BswMSdEventHandlerCurrentState configured.' and Deactivateable: 'BswM_SdEventHandlerMapping.ImmediateUserEndIdx' Reason: 'No Mode Request for BswMSdEventHandlerCurrentState configured.' */
#define BSWM_IMMEDIATEUSERSTARTIDXOFSDEVENTHANDLERMAPPING                                           STD_OFF  /**< Deactivateable: 'BswM_SdEventHandlerMapping.ImmediateUserStartIdx' Reason: 'No Mode Request for BswMSdEventHandlerCurrentState configured.' and Deactivateable: 'BswM_SdEventHandlerMapping.ImmediateUserStartIdx' Reason: 'No Mode Request for BswMSdEventHandlerCurrentState configured.' */
#define BSWM_IMMEDIATEUSERUSEDOFSDEVENTHANDLERMAPPING                                               STD_OFF  /**< Deactivateable: 'BswM_SdEventHandlerMapping.ImmediateUserUsed' Reason: 'No Mode Request for BswMSdEventHandlerCurrentState configured.' and Deactivateable: 'BswM_SdEventHandlerMapping.ImmediateUserUsed' Reason: 'No Mode Request for BswMSdEventHandlerCurrentState configured.' */
#define BSWM_INITVALUEOFSDEVENTHANDLERMAPPING                                                       STD_OFF  /**< Deactivateable: 'BswM_SdEventHandlerMapping.InitValue' Reason: 'No Mode Request for BswMSdEventHandlerCurrentState configured.' and Deactivateable: 'BswM_SdEventHandlerMapping.InitValue' Reason: 'No Mode Request for BswMSdEventHandlerCurrentState configured.' */
#define BSWM_SDEVENTHANDLERSTATE                                                                    STD_OFF  /**< Deactivateable: 'BswM_SdEventHandlerState' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'BswM_SdEventHandlerState' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define BSWM_SDSERVERPARAMETERS                                                                     STD_OFF  /**< Deactivateable: 'BswM_SdServerParameters' Reason: 'Action of type 'SdServer' not in configuration.' and Deactivateable: 'BswM_SdServerParameters' Reason: 'Action of type 'SdServer' not in configuration.' */
#define BSWM_IDOFSDSERVERPARAMETERS                                                                 STD_OFF  /**< Deactivateable: 'BswM_SdServerParameters.Id' Reason: 'Action of type 'SdServer' not in configuration.' and Deactivateable: 'BswM_SdServerParameters.Id' Reason: 'Action of type 'SdServer' not in configuration.' */
#define BSWM_STATEOFSDSERVERPARAMETERS                                                              STD_OFF  /**< Deactivateable: 'BswM_SdServerParameters.State' Reason: 'Action of type 'SdServer' not in configuration.' and Deactivateable: 'BswM_SdServerParameters.State' Reason: 'Action of type 'SdServer' not in configuration.' */
#define BSWM_SDSERVICEGROUPSWITCHPARAMETERS                                                         STD_OFF  /**< Deactivateable: 'BswM_SdServiceGroupSwitchParameters' Reason: 'Action of type 'SdServiceGroupSwitch' not in configuration.' and Deactivateable: 'BswM_SdServiceGroupSwitchParameters' Reason: 'Action of type 'SdServiceGroupSwitch' not in configuration.' */
#define BSWM_SDSERVICEGROUPSWITCHSUBPARAMETERSENDIDXOFSDSERVICEGROUPSWITCHPARAMETERS                STD_OFF  /**< Deactivateable: 'BswM_SdServiceGroupSwitchParameters.SdServiceGroupSwitchSubParametersEndIdx' Reason: 'Action of type 'SdServiceGroupSwitch' not in configuration.' and Deactivateable: 'BswM_SdServiceGroupSwitchParameters.SdServiceGroupSwitchSubParametersEndIdx' Reason: 'Action of type 'SdServiceGroupSwitch' not in configuration.' */
#define BSWM_SDSERVICEGROUPSWITCHSUBPARAMETERSSTARTIDXOFSDSERVICEGROUPSWITCHPARAMETERS              STD_OFF  /**< Deactivateable: 'BswM_SdServiceGroupSwitchParameters.SdServiceGroupSwitchSubParametersStartIdx' Reason: 'Action of type 'SdServiceGroupSwitch' not in configuration.' and Deactivateable: 'BswM_SdServiceGroupSwitchParameters.SdServiceGroupSwitchSubParametersStartIdx' Reason: 'Action of type 'SdServiceGroupSwitch' not in configuration.' */
#define BSWM_SDSERVICEGROUPSWITCHSUBPARAMETERSUSEDOFSDSERVICEGROUPSWITCHPARAMETERS                  STD_OFF  /**< Deactivateable: 'BswM_SdServiceGroupSwitchParameters.SdServiceGroupSwitchSubParametersUsed' Reason: 'Action of type 'SdServiceGroupSwitch' not in configuration.' and Deactivateable: 'BswM_SdServiceGroupSwitchParameters.SdServiceGroupSwitchSubParametersUsed' Reason: 'Action of type 'SdServiceGroupSwitch' not in configuration.' */
#define BSWM_SDSERVICEGROUPSWITCHSUBPARAMETERS                                                      STD_OFF  /**< Deactivateable: 'BswM_SdServiceGroupSwitchSubParameters' Reason: 'Action of type 'SdServiceGroupSwitch' not in configuration.' and Deactivateable: 'BswM_SdServiceGroupSwitchSubParameters' Reason: 'Action of type 'SdServiceGroupSwitch' not in configuration.' */
#define BSWM_SERVICEGROUPIDOFSDSERVICEGROUPSWITCHSUBPARAMETERS                                      STD_OFF  /**< Deactivateable: 'BswM_SdServiceGroupSwitchSubParameters.ServiceGroupId' Reason: 'Action of type 'SdServiceGroupSwitch' not in configuration.' and Deactivateable: 'BswM_SdServiceGroupSwitchSubParameters.ServiceGroupId' Reason: 'Action of type 'SdServiceGroupSwitch' not in configuration.' */
#define BSWM_SIZEOFACTIONITEMS                                                                      STD_ON
#define BSWM_SIZEOFACTIONLISTQUEUE                                                                  STD_ON
#define BSWM_SIZEOFACTIONLISTS                                                                      STD_ON
#define BSWM_SIZEOFACTIONS                                                                          STD_ON
#define BSWM_SIZEOFCANSMCHANNELMAPPING                                                              STD_ON
#define BSWM_SIZEOFCANSMCHANNELSTATE                                                                STD_ON
#define BSWM_SIZEOFCOMDMHANDLINGDISABLEPARAMETERS                                                   STD_ON
#define BSWM_SIZEOFCOMDMHANDLINGENABLEPARAMETERS                                                    STD_ON
#define BSWM_SIZEOFCOMDMHANDLINGPARAMETERS                                                          STD_ON
#define BSWM_SIZEOFCOMMALLOWCOMPARAMETERS                                                           STD_ON
#define BSWM_SIZEOFCOMMCHANNELMAPPING                                                               STD_ON
#define BSWM_SIZEOFCOMMCHANNELSTATE                                                                 STD_ON
#define BSWM_SIZEOFCOMMPNCMAPPING                                                                   STD_ON
#define BSWM_SIZEOFCOMMPNCSTATE                                                                     STD_ON
#define BSWM_SIZEOFCOMPDUGROUPHANDLINGPARAMETERS                                                    STD_ON
#define BSWM_SIZEOFCOMPDUGROUPHANDLINGSTARTPARAMETERS                                               STD_ON
#define BSWM_SIZEOFCOMPDUGROUPHANDLINGSTOPPARAMETERS                                                STD_ON
#define BSWM_SIZEOFDCMCOMMAPPING                                                                    STD_ON
#define BSWM_SIZEOFDCMCOMSTATE                                                                      STD_ON
#define BSWM_SIZEOFDEFERREDRULES                                                                    STD_ON
#define BSWM_SIZEOFECUMMODEMAPPING                                                                  STD_ON
#define BSWM_SIZEOFECUMRUNREQUESTMAPPING                                                            STD_ON
#define BSWM_SIZEOFECUMRUNREQUESTSTATE                                                              STD_ON
#define BSWM_SIZEOFECUMSTATESWITCHPARAMETERS                                                        STD_ON
#define BSWM_SIZEOFEXPRESSIONS                                                                      STD_ON
#define BSWM_SIZEOFGENERICMAPPING                                                                   STD_ON
#define BSWM_SIZEOFGENERICMODEPARAMETERS                                                            STD_ON
#define BSWM_SIZEOFGENERICSTATE                                                                     STD_ON
#define BSWM_SIZEOFIMMEDIATEUSER                                                                    STD_ON
#define BSWM_SIZEOFINITACTIONLISTS                                                                  STD_ON
#define BSWM_SIZEOFINITGENVARANDINITAL                                                              STD_ON
#define BSWM_SIZEOFINITVALUES                                                                       STD_ON
#define BSWM_SIZEOFMODENOTIFICATIONFCT                                                              STD_ON
#define BSWM_SIZEOFMODEREQUESTQUEUE                                                                 STD_ON
#define BSWM_SIZEOFPARTITIONIDENTIFIERS                                                             STD_ON
#define BSWM_SIZEOFRULESTATES                                                                       STD_ON
#define BSWM_SIZEOFRULES                                                                            STD_ON
#define BSWM_SIZEOFRULESIND                                                                         STD_ON
#define BSWM_SIZEOFSWCMODEREQUESTUPDATEFCT                                                          STD_ON
#define BSWM_SIZEOFTIMERCONTROLPARAMETERS                                                           STD_ON
#define BSWM_SIZEOFTIMERSTATE                                                                       STD_ON
#define BSWM_SIZEOFTIMERVALUE                                                                       STD_ON
#define BSWM_SWCMODEREQUESTUPDATEFCT                                                                STD_ON
#define BSWM_TIMERCONTROLPARAMETERS                                                                 STD_ON
#define BSWM_TIMEROFTIMERCONTROLPARAMETERS                                                          STD_ON
#define BSWM_VALUEOFTIMERCONTROLPARAMETERS                                                          STD_ON
#define BSWM_TIMERSTATE                                                                             STD_ON
#define BSWM_TIMERVALUE                                                                             STD_ON
#define BSWM_WDGMMAPPING                                                                            STD_OFF  /**< Deactivateable: 'BswM_WdgMMapping' Reason: 'No Mode Request for BswMWdgMRequestPartitionReset configured.' and Deactivateable: 'BswM_WdgMMapping' Reason: 'No Mode Request for BswMWdgMRequestPartitionReset configured.' */
#define BSWM_EXTERNALIDOFWDGMMAPPING                                                                STD_OFF  /**< Deactivateable: 'BswM_WdgMMapping.ExternalId' Reason: 'No Mode Request for BswMWdgMRequestPartitionReset configured.' and Deactivateable: 'BswM_WdgMMapping.ExternalId' Reason: 'No Mode Request for BswMWdgMRequestPartitionReset configured.' */
#define BSWM_IMMEDIATEUSERENDIDXOFWDGMMAPPING                                                       STD_OFF  /**< Deactivateable: 'BswM_WdgMMapping.ImmediateUserEndIdx' Reason: 'No Mode Request for BswMWdgMRequestPartitionReset configured.' and Deactivateable: 'BswM_WdgMMapping.ImmediateUserEndIdx' Reason: 'No Mode Request for BswMWdgMRequestPartitionReset configured.' */
#define BSWM_IMMEDIATEUSERSTARTIDXOFWDGMMAPPING                                                     STD_OFF  /**< Deactivateable: 'BswM_WdgMMapping.ImmediateUserStartIdx' Reason: 'No Mode Request for BswMWdgMRequestPartitionReset configured.' and Deactivateable: 'BswM_WdgMMapping.ImmediateUserStartIdx' Reason: 'No Mode Request for BswMWdgMRequestPartitionReset configured.' */
#define BSWM_IMMEDIATEUSERUSEDOFWDGMMAPPING                                                         STD_OFF  /**< Deactivateable: 'BswM_WdgMMapping.ImmediateUserUsed' Reason: 'No Mode Request for BswMWdgMRequestPartitionReset configured.' and Deactivateable: 'BswM_WdgMMapping.ImmediateUserUsed' Reason: 'No Mode Request for BswMWdgMRequestPartitionReset configured.' */
#define BSWM_INITVALUEOFWDGMMAPPING                                                                 STD_OFF  /**< Deactivateable: 'BswM_WdgMMapping.InitValue' Reason: 'No Mode Request for BswMWdgMRequestPartitionReset configured.' and Deactivateable: 'BswM_WdgMMapping.InitValue' Reason: 'No Mode Request for BswMWdgMRequestPartitionReset configured.' */
#define BSWM_WDGMSTATE                                                                              STD_OFF  /**< Deactivateable: 'BswM_WdgMState' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'BswM_WdgMState' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define BSWM_PCCONFIG                                                                               STD_ON
#define BSWM_FINALMAGICNUMBEROFPCCONFIG                                                             STD_OFF  /**< Deactivateable: 'BswM_PCConfig.FinalMagicNumber' Reason: 'the module configuration does not support flashing of data.' */
#define BSWM_INITDATAHASHCODEOFPCCONFIG                                                             STD_OFF  /**< Deactivateable: 'BswM_PCConfig.InitDataHashCode' Reason: 'the module configuration does not support flashing of data.' */
#define BSWM_PCPARTITIONCONFIGOFPCCONFIG                                                            STD_ON
#define BSWM_PARTITIONIDENTIFIERSOFPCCONFIG                                                         STD_ON
#define BSWM_SIZEOFPARTITIONIDENTIFIERSOFPCCONFIG                                                   STD_ON
#define BSWM_PCPARTITIONCONFIG                                                                      STD_ON
#define BSWM_ACTIONITEMSOFPCPARTITIONCONFIG                                                         STD_ON
#define BSWM_ACTIONLISTQUEUEOFPCPARTITIONCONFIG                                                     STD_ON
#define BSWM_ACTIONLISTSOFPCPARTITIONCONFIG                                                         STD_ON
#define BSWM_ACTIONSOFPCPARTITIONCONFIG                                                             STD_ON
#define BSWM_CANSMCHANNELMAPPINGOFPCPARTITIONCONFIG                                                 STD_ON
#define BSWM_CANSMCHANNELSTATEOFPCPARTITIONCONFIG                                                   STD_ON
#define BSWM_COMDMHANDLINGDISABLEPARAMETERSOFPCPARTITIONCONFIG                                      STD_ON
#define BSWM_COMDMHANDLINGENABLEPARAMETERSOFPCPARTITIONCONFIG                                       STD_ON
#define BSWM_COMDMHANDLINGPARAMETERSOFPCPARTITIONCONFIG                                             STD_ON
#define BSWM_COMMALLOWCOMPARAMETERSOFPCPARTITIONCONFIG                                              STD_ON
#define BSWM_COMMCHANNELMAPPINGOFPCPARTITIONCONFIG                                                  STD_ON
#define BSWM_COMMCHANNELSTATEOFPCPARTITIONCONFIG                                                    STD_ON
#define BSWM_COMMPNCMAPPINGOFPCPARTITIONCONFIG                                                      STD_ON
#define BSWM_COMMPNCSTATEOFPCPARTITIONCONFIG                                                        STD_ON
#define BSWM_COMPDUGROUPHANDLINGPARAMETERSOFPCPARTITIONCONFIG                                       STD_ON
#define BSWM_COMPDUGROUPHANDLINGSTARTPARAMETERSOFPCPARTITIONCONFIG                                  STD_ON
#define BSWM_COMPDUGROUPHANDLINGSTOPPARAMETERSOFPCPARTITIONCONFIG                                   STD_ON
#define BSWM_DCMCOMMAPPINGOFPCPARTITIONCONFIG                                                       STD_ON
#define BSWM_DCMCOMSTATEOFPCPARTITIONCONFIG                                                         STD_ON
#define BSWM_DEFERREDRULESOFPCPARTITIONCONFIG                                                       STD_ON
#define BSWM_ECUMMODEMAPPINGOFPCPARTITIONCONFIG                                                     STD_ON
#define BSWM_ECUMMODESTATEOFPCPARTITIONCONFIG                                                       STD_ON
#define BSWM_ECUMRUNREQUESTMAPPINGOFPCPARTITIONCONFIG                                               STD_ON
#define BSWM_ECUMRUNREQUESTSTATEOFPCPARTITIONCONFIG                                                 STD_ON
#define BSWM_ECUMSTATESWITCHPARAMETERSOFPCPARTITIONCONFIG                                           STD_ON
#define BSWM_EXPRESSIONSOFPCPARTITIONCONFIG                                                         STD_ON
#define BSWM_FORCEDACTIONLISTPRIORITYOFPCPARTITIONCONFIG                                            STD_ON
#define BSWM_GENERICMAPPINGOFPCPARTITIONCONFIG                                                      STD_ON
#define BSWM_GENERICMODEPARAMETERSOFPCPARTITIONCONFIG                                               STD_ON
#define BSWM_GENERICSTATEOFPCPARTITIONCONFIG                                                        STD_ON
#define BSWM_IMMEDIATEUSEROFPCPARTITIONCONFIG                                                       STD_ON
#define BSWM_INITACTIONLISTSOFPCPARTITIONCONFIG                                                     STD_ON
#define BSWM_INITGENVARANDINITALOFPCPARTITIONCONFIG                                                 STD_ON
#define BSWM_INITVALUESOFPCPARTITIONCONFIG                                                          STD_ON
#define BSWM_INITIALIZEDOFPCPARTITIONCONFIG                                                         STD_ON
#define BSWM_MODENOTIFICATIONFCTOFPCPARTITIONCONFIG                                                 STD_ON
#define BSWM_MODEREQUESTQUEUEOFPCPARTITIONCONFIG                                                    STD_ON
#define BSWM_QUEUESEMAPHOREOFPCPARTITIONCONFIG                                                      STD_ON
#define BSWM_QUEUEWRITTENOFPCPARTITIONCONFIG                                                        STD_ON
#define BSWM_RULESTATESOFPCPARTITIONCONFIG                                                          STD_ON
#define BSWM_RULESINDOFPCPARTITIONCONFIG                                                            STD_ON
#define BSWM_RULESOFPCPARTITIONCONFIG                                                               STD_ON
#define BSWM_SIZEOFACTIONITEMSOFPCPARTITIONCONFIG                                                   STD_ON
#define BSWM_SIZEOFACTIONLISTQUEUEOFPCPARTITIONCONFIG                                               STD_ON
#define BSWM_SIZEOFACTIONLISTSOFPCPARTITIONCONFIG                                                   STD_ON
#define BSWM_SIZEOFACTIONSOFPCPARTITIONCONFIG                                                       STD_ON
#define BSWM_SIZEOFCANSMCHANNELMAPPINGOFPCPARTITIONCONFIG                                           STD_ON
#define BSWM_SIZEOFCANSMCHANNELSTATEOFPCPARTITIONCONFIG                                             STD_ON
#define BSWM_SIZEOFCOMDMHANDLINGDISABLEPARAMETERSOFPCPARTITIONCONFIG                                STD_ON
#define BSWM_SIZEOFCOMDMHANDLINGENABLEPARAMETERSOFPCPARTITIONCONFIG                                 STD_ON
#define BSWM_SIZEOFCOMDMHANDLINGPARAMETERSOFPCPARTITIONCONFIG                                       STD_ON
#define BSWM_SIZEOFCOMMALLOWCOMPARAMETERSOFPCPARTITIONCONFIG                                        STD_ON
#define BSWM_SIZEOFCOMMCHANNELMAPPINGOFPCPARTITIONCONFIG                                            STD_ON
#define BSWM_SIZEOFCOMMCHANNELSTATEOFPCPARTITIONCONFIG                                              STD_ON
#define BSWM_SIZEOFCOMMPNCMAPPINGOFPCPARTITIONCONFIG                                                STD_ON
#define BSWM_SIZEOFCOMMPNCSTATEOFPCPARTITIONCONFIG                                                  STD_ON
#define BSWM_SIZEOFCOMPDUGROUPHANDLINGPARAMETERSOFPCPARTITIONCONFIG                                 STD_ON
#define BSWM_SIZEOFCOMPDUGROUPHANDLINGSTARTPARAMETERSOFPCPARTITIONCONFIG                            STD_ON
#define BSWM_SIZEOFCOMPDUGROUPHANDLINGSTOPPARAMETERSOFPCPARTITIONCONFIG                             STD_ON
#define BSWM_SIZEOFDCMCOMMAPPINGOFPCPARTITIONCONFIG                                                 STD_ON
#define BSWM_SIZEOFDCMCOMSTATEOFPCPARTITIONCONFIG                                                   STD_ON
#define BSWM_SIZEOFDEFERREDRULESOFPCPARTITIONCONFIG                                                 STD_ON
#define BSWM_SIZEOFECUMMODEMAPPINGOFPCPARTITIONCONFIG                                               STD_ON
#define BSWM_SIZEOFECUMRUNREQUESTMAPPINGOFPCPARTITIONCONFIG                                         STD_ON
#define BSWM_SIZEOFECUMRUNREQUESTSTATEOFPCPARTITIONCONFIG                                           STD_ON
#define BSWM_SIZEOFECUMSTATESWITCHPARAMETERSOFPCPARTITIONCONFIG                                     STD_ON
#define BSWM_SIZEOFEXPRESSIONSOFPCPARTITIONCONFIG                                                   STD_ON
#define BSWM_SIZEOFGENERICMAPPINGOFPCPARTITIONCONFIG                                                STD_ON
#define BSWM_SIZEOFGENERICMODEPARAMETERSOFPCPARTITIONCONFIG                                         STD_ON
#define BSWM_SIZEOFGENERICSTATEOFPCPARTITIONCONFIG                                                  STD_ON
#define BSWM_SIZEOFIMMEDIATEUSEROFPCPARTITIONCONFIG                                                 STD_ON
#define BSWM_SIZEOFINITACTIONLISTSOFPCPARTITIONCONFIG                                               STD_ON
#define BSWM_SIZEOFINITGENVARANDINITALOFPCPARTITIONCONFIG                                           STD_ON
#define BSWM_SIZEOFINITVALUESOFPCPARTITIONCONFIG                                                    STD_ON
#define BSWM_SIZEOFMODENOTIFICATIONFCTOFPCPARTITIONCONFIG                                           STD_ON
#define BSWM_SIZEOFMODEREQUESTQUEUEOFPCPARTITIONCONFIG                                              STD_ON
#define BSWM_SIZEOFRULESTATESOFPCPARTITIONCONFIG                                                    STD_ON
#define BSWM_SIZEOFRULESINDOFPCPARTITIONCONFIG                                                      STD_ON
#define BSWM_SIZEOFRULESOFPCPARTITIONCONFIG                                                         STD_ON
#define BSWM_SIZEOFSWCMODEREQUESTUPDATEFCTOFPCPARTITIONCONFIG                                       STD_ON
#define BSWM_SIZEOFTIMERCONTROLPARAMETERSOFPCPARTITIONCONFIG                                        STD_ON
#define BSWM_SIZEOFTIMERSTATEOFPCPARTITIONCONFIG                                                    STD_ON
#define BSWM_SIZEOFTIMERVALUEOFPCPARTITIONCONFIG                                                    STD_ON
#define BSWM_SWCMODEREQUESTUPDATEFCTOFPCPARTITIONCONFIG                                             STD_ON
#define BSWM_TIMERCONTROLPARAMETERSOFPCPARTITIONCONFIG                                              STD_ON
#define BSWM_TIMERSTATEOFPCPARTITIONCONFIG                                                          STD_ON
#define BSWM_TIMERVALUEOFPCPARTITIONCONFIG                                                          STD_ON
/** 
  \}
*/ 

/** 
  \defgroup  BswMPCMinNumericValueDefines  BswM Min Numeric Value Defines (PRE_COMPILE)
  \brief  These defines are used to implement against the minimum value in numerical based data.
  \{
*/ 
#define BSWM_MIN_ACTIONLISTQUEUE                                                                    0u
#define BSWM_MIN_ECUMMODESTATE                                                                      0u
#define BSWM_MIN_FORCEDACTIONLISTPRIORITY                                                           0u
#define BSWM_MIN_MODEREQUESTQUEUE                                                                   0u
#define BSWM_MIN_QUEUESEMAPHORE                                                                     0u
#define BSWM_MIN_RULESTATES                                                                         0u
#define BSWM_MIN_TIMERSTATE                                                                         0u
#define BSWM_MIN_TIMERVALUE                                                                         0u
/** 
  \}
*/ 

/** 
  \defgroup  BswMPCMaxNumericValueDefines  BswM Max Numeric Value Defines (PRE_COMPILE)
  \brief  These defines are used to implement against the maximum value in numerical based data.
  \{
*/ 
#define BSWM_MAX_ACTIONLISTQUEUE                                                                    255u
#define BSWM_MAX_ECUMMODESTATE                                                                      255u
#define BSWM_MAX_FORCEDACTIONLISTPRIORITY                                                           255u
#define BSWM_MAX_MODEREQUESTQUEUE                                                                   255u
#define BSWM_MAX_QUEUESEMAPHORE                                                                     255u
#define BSWM_MAX_RULESTATES                                                                         255u
#define BSWM_MAX_TIMERSTATE                                                                         255u
#define BSWM_MAX_TIMERVALUE                                                                         4294967295u
/** 
  \}
*/ 

/** 
  \defgroup  BswMPCNoReferenceDefines  BswM No Reference Defines (PRE_COMPILE)
  \brief  These defines are used to indicate unused indexes in data relations.
  \{
*/ 
#define BSWM_NO_PARAMETERIDXOFACTIONITEMS                                                           255u
#define BSWM_NO_ACTIONITEMSENDIDXOFACTIONLISTS                                                      255u
#define BSWM_NO_ACTIONITEMSSTARTIDXOFACTIONLISTS                                                    255u
#define BSWM_NO_IMMEDIATEUSERENDIDXOFCANSMCHANNELMAPPING                                            255u
#define BSWM_NO_IMMEDIATEUSERSTARTIDXOFCANSMCHANNELMAPPING                                          255u
#define BSWM_NO_COMDMHANDLINGDISABLEPARAMETERSENDIDXOFCOMDMHANDLINGPARAMETERS                       255u
#define BSWM_NO_COMDMHANDLINGDISABLEPARAMETERSSTARTIDXOFCOMDMHANDLINGPARAMETERS                     255u
#define BSWM_NO_COMDMHANDLINGENABLEPARAMETERSENDIDXOFCOMDMHANDLINGPARAMETERS                        255u
#define BSWM_NO_COMDMHANDLINGENABLEPARAMETERSSTARTIDXOFCOMDMHANDLINGPARAMETERS                      255u
#define BSWM_NO_IMMEDIATEUSERENDIDXOFCOMMCHANNELMAPPING                                             255u
#define BSWM_NO_IMMEDIATEUSERSTARTIDXOFCOMMCHANNELMAPPING                                           255u
#define BSWM_NO_IMMEDIATEUSERENDIDXOFCOMMPNCMAPPING                                                 255u
#define BSWM_NO_IMMEDIATEUSERSTARTIDXOFCOMMPNCMAPPING                                               255u
#define BSWM_NO_COMPDUGROUPHANDLINGSTARTPARAMETERSENDIDXOFCOMPDUGROUPHANDLINGPARAMETERS             255u
#define BSWM_NO_COMPDUGROUPHANDLINGSTARTPARAMETERSSTARTIDXOFCOMPDUGROUPHANDLINGPARAMETERS           255u
#define BSWM_NO_COMPDUGROUPHANDLINGSTOPPARAMETERSENDIDXOFCOMPDUGROUPHANDLINGPARAMETERS              255u
#define BSWM_NO_COMPDUGROUPHANDLINGSTOPPARAMETERSSTARTIDXOFCOMPDUGROUPHANDLINGPARAMETERS            255u
#define BSWM_NO_IMMEDIATEUSERENDIDXOFDCMCOMMAPPING                                                  255u
#define BSWM_NO_IMMEDIATEUSERSTARTIDXOFDCMCOMMAPPING                                                255u
#define BSWM_NO_IMMEDIATEUSERENDIDXOFGENERICMAPPING                                                 255u
#define BSWM_NO_IMMEDIATEUSERSTARTIDXOFGENERICMAPPING                                               255u
#define BSWM_NO_RULESINDENDIDXOFIMMEDIATEUSER                                                       255u
#define BSWM_NO_RULESINDSTARTIDXOFIMMEDIATEUSER                                                     255u
#define BSWM_NO_ACTIONLISTSFALSEIDXOFRULES                                                          255u
#define BSWM_NO_ACTIONLISTSTRUEIDXOFRULES                                                           255u
#define BSWM_NO_IDOFRULES                                                                           255u
/** 
  \}
*/ 

/** 
  \defgroup  BswMPCEnumExistsDefines  BswM Enum Exists Defines (PRE_COMPILE)
  \brief  These defines can be used to deactivate enumeration based code sequences if the enumeration value does not exist in the configuration data.
  \{
*/ 
#define BSWM_EXISTS_COMMALLOWCOMPARAMETERS_PARAMETEROFACTIONITEMS                                   STD_ON
#define BSWM_EXISTS_COMMMODELIMITATIONPARAMETERS_PARAMETEROFACTIONITEMS                             STD_OFF
#define BSWM_EXISTS_COMMMODESWITCHPARAMETERS_PARAMETEROFACTIONITEMS                                 STD_OFF
#define BSWM_EXISTS_COMDMCONTROLPARAMETERS_PARAMETEROFACTIONITEMS                                   STD_OFF
#define BSWM_EXISTS_ECUMSELECTSHUTDOWNTARGETPARAMETERS_PARAMETEROFACTIONITEMS                       STD_OFF
#define BSWM_EXISTS_ECUMSTATESWITCHPARAMETERS_PARAMETEROFACTIONITEMS                                STD_ON
#define BSWM_EXISTS_IDSMBLOCKSTATECHANGEREQUESTPARAMETERS_PARAMETEROFACTIONITEMS                    STD_OFF
#define BSWM_EXISTS_LINSCHEDULEREQUESTPARAMETERS_PARAMETEROFACTIONITEMS                             STD_OFF
#define BSWM_EXISTS_NMCONTROLPARAMETERS_PARAMETEROFACTIONITEMS                                      STD_OFF
#define BSWM_EXISTS_COMSWITCHIPDUMODEPARAMETERS_PARAMETEROFACTIONITEMS                              STD_OFF
#define BSWM_EXISTS_COMPDUGROUPSWITCHPARAMETERS_PARAMETEROFACTIONITEMS                              STD_OFF
#define BSWM_EXISTS_COMPDUGROUPHANDLINGPARAMETERS_PARAMETEROFACTIONITEMS                            STD_ON
#define BSWM_EXISTS_COMDMHANDLINGPARAMETERS_PARAMETEROFACTIONITEMS                                  STD_ON
#define BSWM_EXISTS_COMTRIGGERIPDUSENDPARAMETERS_PARAMETEROFACTIONITEMS                             STD_OFF
#define BSWM_EXISTS_PDUROUTERCONTROLPARAMETERS_PARAMETEROFACTIONITEMS                               STD_OFF
#define BSWM_EXISTS_TIMERCONTROLPARAMETERS_PARAMETEROFACTIONITEMS                                   STD_ON
#define BSWM_EXISTS_GENERICMODEPARAMETERS_PARAMETEROFACTIONITEMS                                    STD_ON
#define BSWM_EXISTS_GENERICMODEREFPARAMETERS_PARAMETEROFACTIONITEMS                                 STD_OFF
#define BSWM_EXISTS_J1939DCMSTATEPARAMETERS_PARAMETEROFACTIONITEMS                                  STD_OFF
#define BSWM_EXISTS_J1939RMSTATEPARAMETERS_PARAMETEROFACTIONITEMS                                   STD_OFF
#define BSWM_EXISTS_SDCLIENTPARAMETERS_PARAMETEROFACTIONITEMS                                       STD_OFF
#define BSWM_EXISTS_SDCONSUMEDPARAMETERS_PARAMETEROFACTIONITEMS                                     STD_OFF
#define BSWM_EXISTS_SDSERVERPARAMETERS_PARAMETEROFACTIONITEMS                                       STD_OFF
#define BSWM_EXISTS_SDSERVICEGROUPSWITCHPARAMETERS_PARAMETEROFACTIONITEMS                           STD_OFF
#define BSWM_EXISTS_RULECONTROLPARAMETERS_PARAMETEROFACTIONITEMS                                    STD_OFF
#define BSWM_EXISTS_ACTIONLISTS_PARAMETEROFACTIONITEMS                                              STD_OFF
#define BSWM_EXISTS_RULES_PARAMETEROFACTIONITEMS                                                    STD_ON
#define BSWM_EXISTS_NO_PARAMETEROFACTIONITEMS                                                       STD_ON
/** 
  \}
*/ 

/** 
  \defgroup  BswMPCEnumDefines  BswM Enum Defines (PRE_COMPILE)
  \brief  These defines are the enumeration values of enumeration based CONST and VAR data.
  \{
*/ 
#define BSWM_COMMALLOWCOMPARAMETERS_PARAMETEROFACTIONITEMS                                          0x00u
#define BSWM_ECUMSTATESWITCHPARAMETERS_PARAMETEROFACTIONITEMS                                       0x05u
#define BSWM_COMPDUGROUPHANDLINGPARAMETERS_PARAMETEROFACTIONITEMS                                   0x0Bu
#define BSWM_COMDMHANDLINGPARAMETERS_PARAMETEROFACTIONITEMS                                         0x0Cu
#define BSWM_TIMERCONTROLPARAMETERS_PARAMETEROFACTIONITEMS                                          0x0Fu
#define BSWM_GENERICMODEPARAMETERS_PARAMETEROFACTIONITEMS                                           0x10u
#define BSWM_RULES_PARAMETEROFACTIONITEMS                                                           0x1Au
#define BSWM_NO_PARAMETEROFACTIONITEMS                                                              0xFFu
/** 
  \}
*/ 

/** 
  \defgroup  BswMPCIsReducedToDefineDefines  BswM Is Reduced To Define Defines (PRE_COMPILE)
  \brief  If all values in a CONST array or an element in a CONST array of structs are equal, the define is STD_ON else STD_OFF.
  \{
*/ 
#define BSWM_ISDEF_ACTIONSIDXOFACTIONITEMS                                                          STD_OFF
#define BSWM_ISDEF_PARAMETERIDXOFACTIONITEMS                                                        STD_OFF
#define BSWM_ISDEF_PARAMETEROFACTIONITEMS                                                           STD_OFF
#define BSWM_ISDEF_PARAMETERUSEDOFACTIONITEMS                                                       STD_OFF
#define BSWM_ISDEF_ACTIONITEMSENDIDXOFACTIONLISTS                                                   STD_OFF
#define BSWM_ISDEF_ACTIONITEMSSTARTIDXOFACTIONLISTS                                                 STD_OFF
#define BSWM_ISDEF_ACTIONITEMSUSEDOFACTIONLISTS                                                     STD_ON
#define BSWM_ISDEF_CONDITIONALOFACTIONLISTS                                                         STD_OFF
#define BSWM_ISDEF_ACTIONS                                                                          STD_OFF
#define BSWM_ISDEF_EXTERNALIDOFCANSMCHANNELMAPPING                                                  STD_OFF
#define BSWM_ISDEF_IMMEDIATEUSERENDIDXOFCANSMCHANNELMAPPING                                         STD_ON
#define BSWM_ISDEF_IMMEDIATEUSERSTARTIDXOFCANSMCHANNELMAPPING                                       STD_ON
#define BSWM_ISDEF_IMMEDIATEUSERUSEDOFCANSMCHANNELMAPPING                                           STD_ON
#define BSWM_ISDEF_INITVALUEOFCANSMCHANNELMAPPING                                                   STD_ON
#define BSWM_ISDEF_IPDUGROUPIDOFCOMDMHANDLINGDISABLEPARAMETERS                                      STD_OFF
#define BSWM_ISDEF_IPDUGROUPIDOFCOMDMHANDLINGENABLEPARAMETERS                                       STD_OFF
#define BSWM_ISDEF_COMDMHANDLINGDISABLEPARAMETERSENDIDXOFCOMDMHANDLINGPARAMETERS                    STD_OFF
#define BSWM_ISDEF_COMDMHANDLINGDISABLEPARAMETERSSTARTIDXOFCOMDMHANDLINGPARAMETERS                  STD_OFF
#define BSWM_ISDEF_COMDMHANDLINGDISABLEPARAMETERSUSEDOFCOMDMHANDLINGPARAMETERS                      STD_OFF
#define BSWM_ISDEF_COMDMHANDLINGENABLEPARAMETERSENDIDXOFCOMDMHANDLINGPARAMETERS                     STD_OFF
#define BSWM_ISDEF_COMDMHANDLINGENABLEPARAMETERSSTARTIDXOFCOMDMHANDLINGPARAMETERS                   STD_OFF
#define BSWM_ISDEF_COMDMHANDLINGENABLEPARAMETERSUSEDOFCOMDMHANDLINGPARAMETERS                       STD_OFF
#define BSWM_ISDEF_ALLOWEDOFCOMMALLOWCOMPARAMETERS                                                  STD_OFF
#define BSWM_ISDEF_CHANNELOFCOMMALLOWCOMPARAMETERS                                                  STD_OFF
#define BSWM_ISDEF_EXTERNALIDOFCOMMCHANNELMAPPING                                                   STD_OFF
#define BSWM_ISDEF_IMMEDIATEUSERENDIDXOFCOMMCHANNELMAPPING                                          STD_ON
#define BSWM_ISDEF_IMMEDIATEUSERSTARTIDXOFCOMMCHANNELMAPPING                                        STD_ON
#define BSWM_ISDEF_IMMEDIATEUSERUSEDOFCOMMCHANNELMAPPING                                            STD_ON
#define BSWM_ISDEF_INITVALUEOFCOMMCHANNELMAPPING                                                    STD_ON
#define BSWM_ISDEF_EXTERNALIDOFCOMMPNCMAPPING                                                       STD_OFF
#define BSWM_ISDEF_IMMEDIATEUSERENDIDXOFCOMMPNCMAPPING                                              STD_OFF
#define BSWM_ISDEF_IMMEDIATEUSERSTARTIDXOFCOMMPNCMAPPING                                            STD_OFF
#define BSWM_ISDEF_IMMEDIATEUSERUSEDOFCOMMPNCMAPPING                                                STD_ON
#define BSWM_ISDEF_INITVALUEOFCOMMPNCMAPPING                                                        STD_ON
#define BSWM_ISDEF_COMPDUGROUPHANDLINGSTARTPARAMETERSENDIDXOFCOMPDUGROUPHANDLINGPARAMETERS          STD_OFF
#define BSWM_ISDEF_COMPDUGROUPHANDLINGSTARTPARAMETERSSTARTIDXOFCOMPDUGROUPHANDLINGPARAMETERS        STD_OFF
#define BSWM_ISDEF_COMPDUGROUPHANDLINGSTARTPARAMETERSUSEDOFCOMPDUGROUPHANDLINGPARAMETERS            STD_OFF
#define BSWM_ISDEF_COMPDUGROUPHANDLINGSTOPPARAMETERSENDIDXOFCOMPDUGROUPHANDLINGPARAMETERS           STD_OFF
#define BSWM_ISDEF_COMPDUGROUPHANDLINGSTOPPARAMETERSSTARTIDXOFCOMPDUGROUPHANDLINGPARAMETERS         STD_OFF
#define BSWM_ISDEF_COMPDUGROUPHANDLINGSTOPPARAMETERSUSEDOFCOMPDUGROUPHANDLINGPARAMETERS             STD_OFF
#define BSWM_ISDEF_INITIALIZEOFCOMPDUGROUPHANDLINGSTARTPARAMETERS                                   STD_ON
#define BSWM_ISDEF_IPDUGROUPIDOFCOMPDUGROUPHANDLINGSTARTPARAMETERS                                  STD_OFF
#define BSWM_ISDEF_IPDUGROUPIDOFCOMPDUGROUPHANDLINGSTOPPARAMETERS                                   STD_OFF
#define BSWM_ISDEF_EXTERNALIDOFDCMCOMMAPPING                                                        STD_OFF
#define BSWM_ISDEF_IMMEDIATEUSERENDIDXOFDCMCOMMAPPING                                               STD_ON
#define BSWM_ISDEF_IMMEDIATEUSERSTARTIDXOFDCMCOMMAPPING                                             STD_ON
#define BSWM_ISDEF_IMMEDIATEUSERUSEDOFDCMCOMMAPPING                                                 STD_ON
#define BSWM_ISDEF_INITVALUEOFDCMCOMMAPPING                                                         STD_ON
#define BSWM_ISDEF_RULESIDXOFDEFERREDRULES                                                          STD_OFF
#define BSWM_ISDEF_INITVALUEOFECUMMODEMAPPING                                                       STD_ON
#define BSWM_ISDEF_EXTERNALIDOFECUMRUNREQUESTMAPPING                                                STD_OFF
#define BSWM_ISDEF_INITVALUEOFECUMRUNREQUESTMAPPING                                                 STD_ON
#define BSWM_ISDEF_TARGETSTATEOFECUMSTATESWITCHPARAMETERS                                           STD_OFF
#define BSWM_ISDEF_EXPRESSIONS                                                                      STD_OFF
#define BSWM_ISDEF_EXTERNALIDOFGENERICMAPPING                                                       STD_OFF
#define BSWM_ISDEF_IMMEDIATEUSERENDIDXOFGENERICMAPPING                                              STD_OFF
#define BSWM_ISDEF_IMMEDIATEUSERSTARTIDXOFGENERICMAPPING                                            STD_OFF
#define BSWM_ISDEF_IMMEDIATEUSERUSEDOFGENERICMAPPING                                                STD_OFF
#define BSWM_ISDEF_INITVALUEOFGENERICMAPPING                                                        STD_OFF
#define BSWM_ISDEF_MODEOFGENERICMODEPARAMETERS                                                      STD_OFF
#define BSWM_ISDEF_USEROFGENERICMODEPARAMETERS                                                      STD_OFF
#define BSWM_ISDEF_ONINITOFIMMEDIATEUSER                                                            STD_OFF
#define BSWM_ISDEF_RULESINDENDIDXOFIMMEDIATEUSER                                                    STD_OFF
#define BSWM_ISDEF_RULESINDSTARTIDXOFIMMEDIATEUSER                                                  STD_OFF
#define BSWM_ISDEF_RULESINDUSEDOFIMMEDIATEUSER                                                      STD_OFF
#define BSWM_ISDEF_INITACTIONLISTS                                                                  STD_OFF
#define BSWM_ISDEF_INITGENVARANDINITAL                                                              STD_OFF
#define BSWM_ISDEF_INITVALUES                                                                       STD_OFF
#define BSWM_ISDEF_MODENOTIFICATIONFCT                                                              STD_OFF
#define BSWM_ISDEF_PCPARTITIONCONFIGIDXOFPARTITIONIDENTIFIERS                                       STD_OFF
#define BSWM_ISDEF_PARTITIONSNVOFPARTITIONIDENTIFIERS                                               STD_OFF
#define BSWM_ISDEF_ACTIONLISTSFALSEIDXOFRULES                                                       STD_OFF
#define BSWM_ISDEF_ACTIONLISTSFALSEUSEDOFRULES                                                      STD_OFF
#define BSWM_ISDEF_ACTIONLISTSTRUEIDXOFRULES                                                        STD_OFF
#define BSWM_ISDEF_ACTIONLISTSTRUEUSEDOFRULES                                                       STD_ON
#define BSWM_ISDEF_EXPRESSIONSIDXOFRULES                                                            STD_OFF
#define BSWM_ISDEF_IDOFRULES                                                                        STD_OFF
#define BSWM_ISDEF_INITOFRULES                                                                      STD_ON
#define BSWM_ISDEF_RULESTATESIDXOFRULES                                                             STD_OFF
#define BSWM_ISDEF_RULESIND                                                                         STD_OFF
#define BSWM_ISDEF_SWCMODEREQUESTUPDATEFCT                                                          STD_OFF
#define BSWM_ISDEF_TIMEROFTIMERCONTROLPARAMETERS                                                    STD_OFF
#define BSWM_ISDEF_VALUEOFTIMERCONTROLPARAMETERS                                                    STD_ON
#define BSWM_ISDEF_PCPARTITIONCONFIGOFPCCONFIG                                                      STD_OFF
#define BSWM_ISDEF_PARTITIONIDENTIFIERSOFPCCONFIG                                                   STD_ON
#define BSWM_ISDEF_ACTIONITEMSOFPCPARTITIONCONFIG                                                   STD_OFF
#define BSWM_ISDEF_ACTIONLISTQUEUEOFPCPARTITIONCONFIG                                               STD_ON
#define BSWM_ISDEF_ACTIONLISTSOFPCPARTITIONCONFIG                                                   STD_OFF
#define BSWM_ISDEF_ACTIONSOFPCPARTITIONCONFIG                                                       STD_OFF
#define BSWM_ISDEF_CANSMCHANNELMAPPINGOFPCPARTITIONCONFIG                                           STD_OFF
#define BSWM_ISDEF_CANSMCHANNELSTATEOFPCPARTITIONCONFIG                                             STD_ON
#define BSWM_ISDEF_COMDMHANDLINGDISABLEPARAMETERSOFPCPARTITIONCONFIG                                STD_OFF
#define BSWM_ISDEF_COMDMHANDLINGENABLEPARAMETERSOFPCPARTITIONCONFIG                                 STD_OFF
#define BSWM_ISDEF_COMDMHANDLINGPARAMETERSOFPCPARTITIONCONFIG                                       STD_ON
#define BSWM_ISDEF_COMMALLOWCOMPARAMETERSOFPCPARTITIONCONFIG                                        STD_OFF
#define BSWM_ISDEF_COMMCHANNELMAPPINGOFPCPARTITIONCONFIG                                            STD_OFF
#define BSWM_ISDEF_COMMCHANNELSTATEOFPCPARTITIONCONFIG                                              STD_ON
#define BSWM_ISDEF_COMMPNCMAPPINGOFPCPARTITIONCONFIG                                                STD_ON
#define BSWM_ISDEF_COMMPNCSTATEOFPCPARTITIONCONFIG                                                  STD_ON
#define BSWM_ISDEF_COMPDUGROUPHANDLINGPARAMETERSOFPCPARTITIONCONFIG                                 STD_ON
#define BSWM_ISDEF_COMPDUGROUPHANDLINGSTARTPARAMETERSOFPCPARTITIONCONFIG                            STD_OFF
#define BSWM_ISDEF_COMPDUGROUPHANDLINGSTOPPARAMETERSOFPCPARTITIONCONFIG                             STD_OFF
#define BSWM_ISDEF_DCMCOMMAPPINGOFPCPARTITIONCONFIG                                                 STD_OFF
#define BSWM_ISDEF_DCMCOMSTATEOFPCPARTITIONCONFIG                                                   STD_ON
#define BSWM_ISDEF_DEFERREDRULESOFPCPARTITIONCONFIG                                                 STD_OFF
#define BSWM_ISDEF_ECUMMODEMAPPINGOFPCPARTITIONCONFIG                                               STD_ON
#define BSWM_ISDEF_ECUMMODESTATEOFPCPARTITIONCONFIG                                                 STD_ON
#define BSWM_ISDEF_ECUMRUNREQUESTMAPPINGOFPCPARTITIONCONFIG                                         STD_ON
#define BSWM_ISDEF_ECUMRUNREQUESTSTATEOFPCPARTITIONCONFIG                                           STD_ON
#define BSWM_ISDEF_ECUMSTATESWITCHPARAMETERSOFPCPARTITIONCONFIG                                     STD_ON
#define BSWM_ISDEF_EXPRESSIONSOFPCPARTITIONCONFIG                                                   STD_OFF
#define BSWM_ISDEF_FORCEDACTIONLISTPRIORITYOFPCPARTITIONCONFIG                                      STD_ON
#define BSWM_ISDEF_GENERICMAPPINGOFPCPARTITIONCONFIG                                                STD_ON
#define BSWM_ISDEF_GENERICMODEPARAMETERSOFPCPARTITIONCONFIG                                         STD_ON
#define BSWM_ISDEF_GENERICSTATEOFPCPARTITIONCONFIG                                                  STD_ON
#define BSWM_ISDEF_IMMEDIATEUSEROFPCPARTITIONCONFIG                                                 STD_ON
#define BSWM_ISDEF_INITACTIONLISTSOFPCPARTITIONCONFIG                                               STD_OFF
#define BSWM_ISDEF_INITGENVARANDINITALOFPCPARTITIONCONFIG                                           STD_ON
#define BSWM_ISDEF_INITVALUESOFPCPARTITIONCONFIG                                                    STD_ON
#define BSWM_ISDEF_INITIALIZEDOFPCPARTITIONCONFIG                                                   STD_ON
#define BSWM_ISDEF_MODENOTIFICATIONFCTOFPCPARTITIONCONFIG                                           STD_ON
#define BSWM_ISDEF_MODEREQUESTQUEUEOFPCPARTITIONCONFIG                                              STD_ON
#define BSWM_ISDEF_QUEUESEMAPHOREOFPCPARTITIONCONFIG                                                STD_ON
#define BSWM_ISDEF_QUEUEWRITTENOFPCPARTITIONCONFIG                                                  STD_ON
#define BSWM_ISDEF_RULESTATESOFPCPARTITIONCONFIG                                                    STD_ON
#define BSWM_ISDEF_RULESINDOFPCPARTITIONCONFIG                                                      STD_OFF
#define BSWM_ISDEF_RULESOFPCPARTITIONCONFIG                                                         STD_OFF
#define BSWM_ISDEF_SWCMODEREQUESTUPDATEFCTOFPCPARTITIONCONFIG                                       STD_ON
#define BSWM_ISDEF_TIMERCONTROLPARAMETERSOFPCPARTITIONCONFIG                                        STD_OFF
#define BSWM_ISDEF_TIMERSTATEOFPCPARTITIONCONFIG                                                    STD_ON
#define BSWM_ISDEF_TIMERVALUEOFPCPARTITIONCONFIG                                                    STD_ON
/** 
  \}
*/ 

/** 
  \defgroup  BswMPCEqualsAlwaysToDefines  BswM Equals Always To Defines (PRE_COMPILE)
  \brief  If all values in a CONST array or an element in a CONST array of structs are equal, the define contains the always equals value.
  \{
*/ 
#define BSWM_EQ2_ACTIONSIDXOFACTIONITEMS                                                            
#define BSWM_EQ2_PARAMETERIDXOFACTIONITEMS                                                          
#define BSWM_EQ2_PARAMETEROFACTIONITEMS                                                             
#define BSWM_EQ2_PARAMETERUSEDOFACTIONITEMS                                                         
#define BSWM_EQ2_ACTIONITEMSENDIDXOFACTIONLISTS                                                     
#define BSWM_EQ2_ACTIONITEMSSTARTIDXOFACTIONLISTS                                                   
#define BSWM_EQ2_ACTIONITEMSUSEDOFACTIONLISTS                                                       TRUE
#define BSWM_EQ2_CONDITIONALOFACTIONLISTS                                                           
#define BSWM_EQ2_ACTIONS                                                                            
#define BSWM_EQ2_EXTERNALIDOFCANSMCHANNELMAPPING                                                    
#define BSWM_EQ2_IMMEDIATEUSERENDIDXOFCANSMCHANNELMAPPING                                           1u
#define BSWM_EQ2_IMMEDIATEUSERSTARTIDXOFCANSMCHANNELMAPPING                                         0u
#define BSWM_EQ2_IMMEDIATEUSERUSEDOFCANSMCHANNELMAPPING                                             TRUE
#define BSWM_EQ2_INITVALUEOFCANSMCHANNELMAPPING                                                     CANSM_BSWM_NO_COMMUNICATION
#define BSWM_EQ2_IPDUGROUPIDOFCOMDMHANDLINGDISABLEPARAMETERS                                        
#define BSWM_EQ2_IPDUGROUPIDOFCOMDMHANDLINGENABLEPARAMETERS                                         
#define BSWM_EQ2_COMDMHANDLINGDISABLEPARAMETERSENDIDXOFCOMDMHANDLINGPARAMETERS                      
#define BSWM_EQ2_COMDMHANDLINGDISABLEPARAMETERSSTARTIDXOFCOMDMHANDLINGPARAMETERS                    
#define BSWM_EQ2_COMDMHANDLINGDISABLEPARAMETERSUSEDOFCOMDMHANDLINGPARAMETERS                        
#define BSWM_EQ2_COMDMHANDLINGENABLEPARAMETERSENDIDXOFCOMDMHANDLINGPARAMETERS                       
#define BSWM_EQ2_COMDMHANDLINGENABLEPARAMETERSSTARTIDXOFCOMDMHANDLINGPARAMETERS                     
#define BSWM_EQ2_COMDMHANDLINGENABLEPARAMETERSUSEDOFCOMDMHANDLINGPARAMETERS                         
#define BSWM_EQ2_ALLOWEDOFCOMMALLOWCOMPARAMETERS                                                    
#define BSWM_EQ2_CHANNELOFCOMMALLOWCOMPARAMETERS                                                    
#define BSWM_EQ2_EXTERNALIDOFCOMMCHANNELMAPPING                                                     
#define BSWM_EQ2_IMMEDIATEUSERENDIDXOFCOMMCHANNELMAPPING                                            2u
#define BSWM_EQ2_IMMEDIATEUSERSTARTIDXOFCOMMCHANNELMAPPING                                          1u
#define BSWM_EQ2_IMMEDIATEUSERUSEDOFCOMMCHANNELMAPPING                                              TRUE
#define BSWM_EQ2_INITVALUEOFCOMMCHANNELMAPPING                                                      COMM_NO_COMMUNICATION
#define BSWM_EQ2_EXTERNALIDOFCOMMPNCMAPPING                                                         
#define BSWM_EQ2_IMMEDIATEUSERENDIDXOFCOMMPNCMAPPING                                                
#define BSWM_EQ2_IMMEDIATEUSERSTARTIDXOFCOMMPNCMAPPING                                              
#define BSWM_EQ2_IMMEDIATEUSERUSEDOFCOMMPNCMAPPING                                                  TRUE
#define BSWM_EQ2_INITVALUEOFCOMMPNCMAPPING                                                          COMM_PNC_NO_COMMUNICATION
#define BSWM_EQ2_COMPDUGROUPHANDLINGSTARTPARAMETERSENDIDXOFCOMPDUGROUPHANDLINGPARAMETERS            
#define BSWM_EQ2_COMPDUGROUPHANDLINGSTARTPARAMETERSSTARTIDXOFCOMPDUGROUPHANDLINGPARAMETERS          
#define BSWM_EQ2_COMPDUGROUPHANDLINGSTARTPARAMETERSUSEDOFCOMPDUGROUPHANDLINGPARAMETERS              
#define BSWM_EQ2_COMPDUGROUPHANDLINGSTOPPARAMETERSENDIDXOFCOMPDUGROUPHANDLINGPARAMETERS             
#define BSWM_EQ2_COMPDUGROUPHANDLINGSTOPPARAMETERSSTARTIDXOFCOMPDUGROUPHANDLINGPARAMETERS           
#define BSWM_EQ2_COMPDUGROUPHANDLINGSTOPPARAMETERSUSEDOFCOMPDUGROUPHANDLINGPARAMETERS               
#define BSWM_EQ2_INITIALIZEOFCOMPDUGROUPHANDLINGSTARTPARAMETERS                                     FALSE
#define BSWM_EQ2_IPDUGROUPIDOFCOMPDUGROUPHANDLINGSTARTPARAMETERS                                    
#define BSWM_EQ2_IPDUGROUPIDOFCOMPDUGROUPHANDLINGSTOPPARAMETERS                                     
#define BSWM_EQ2_EXTERNALIDOFDCMCOMMAPPING                                                          
#define BSWM_EQ2_IMMEDIATEUSERENDIDXOFDCMCOMMAPPING                                                 5u
#define BSWM_EQ2_IMMEDIATEUSERSTARTIDXOFDCMCOMMAPPING                                               4u
#define BSWM_EQ2_IMMEDIATEUSERUSEDOFDCMCOMMAPPING                                                   TRUE
#define BSWM_EQ2_INITVALUEOFDCMCOMMAPPING                                                           DCM_ENABLE_RX_TX_NORM_NM
#define BSWM_EQ2_RULESIDXOFDEFERREDRULES                                                            
#define BSWM_EQ2_INITVALUEOFECUMMODEMAPPING                                                         ECUM_STATE_OFF
#define BSWM_EQ2_EXTERNALIDOFECUMRUNREQUESTMAPPING                                                  
#define BSWM_EQ2_INITVALUEOFECUMRUNREQUESTMAPPING                                                   ECUM_RUNSTATUS_RELEASED
#define BSWM_EQ2_TARGETSTATEOFECUMSTATESWITCHPARAMETERS                                             
#define BSWM_EQ2_EXPRESSIONS                                                                        
#define BSWM_EQ2_EXTERNALIDOFGENERICMAPPING                                                         
#define BSWM_EQ2_IMMEDIATEUSERENDIDXOFGENERICMAPPING                                                
#define BSWM_EQ2_IMMEDIATEUSERSTARTIDXOFGENERICMAPPING                                              
#define BSWM_EQ2_IMMEDIATEUSERUSEDOFGENERICMAPPING                                                  
#define BSWM_EQ2_INITVALUEOFGENERICMAPPING                                                          
#define BSWM_EQ2_MODEOFGENERICMODEPARAMETERS                                                        
#define BSWM_EQ2_USEROFGENERICMODEPARAMETERS                                                        
#define BSWM_EQ2_ONINITOFIMMEDIATEUSER                                                              
#define BSWM_EQ2_RULESINDENDIDXOFIMMEDIATEUSER                                                      
#define BSWM_EQ2_RULESINDSTARTIDXOFIMMEDIATEUSER                                                    
#define BSWM_EQ2_RULESINDUSEDOFIMMEDIATEUSER                                                        
#define BSWM_EQ2_INITACTIONLISTS                                                                    
#define BSWM_EQ2_INITGENVARANDINITAL                                                                
#define BSWM_EQ2_INITVALUES                                                                         
#define BSWM_EQ2_MODENOTIFICATIONFCT                                                                
#define BSWM_EQ2_PCPARTITIONCONFIGIDXOFPARTITIONIDENTIFIERS                                         
#define BSWM_EQ2_PARTITIONSNVOFPARTITIONIDENTIFIERS                                                 
#define BSWM_EQ2_ACTIONLISTSFALSEIDXOFRULES                                                         
#define BSWM_EQ2_ACTIONLISTSFALSEUSEDOFRULES                                                        
#define BSWM_EQ2_ACTIONLISTSTRUEIDXOFRULES                                                          
#define BSWM_EQ2_ACTIONLISTSTRUEUSEDOFRULES                                                         TRUE
#define BSWM_EQ2_EXPRESSIONSIDXOFRULES                                                              
#define BSWM_EQ2_IDOFRULES                                                                          
#define BSWM_EQ2_INITOFRULES                                                                        BSWM_FALSE
#define BSWM_EQ2_RULESTATESIDXOFRULES                                                               
#define BSWM_EQ2_RULESIND                                                                           
#define BSWM_EQ2_SWCMODEREQUESTUPDATEFCT                                                            
#define BSWM_EQ2_TIMEROFTIMERCONTROLPARAMETERS                                                      
#define BSWM_EQ2_VALUEOFTIMERCONTROLPARAMETERS                                                      200u
#define BSWM_EQ2_PCPARTITIONCONFIGOFPCCONFIG                                                        
#define BSWM_EQ2_PARTITIONIDENTIFIERSOFPCCONFIG                                                     BswM_PartitionIdentifiers
#define BSWM_EQ2_ACTIONITEMSOFPCPARTITIONCONFIG                                                     
#define BSWM_EQ2_ACTIONLISTQUEUEOFPCPARTITIONCONFIG                                                 BswM_ActionListQueue.raw
#define BSWM_EQ2_ACTIONLISTSOFPCPARTITIONCONFIG                                                     
#define BSWM_EQ2_ACTIONSOFPCPARTITIONCONFIG                                                         
#define BSWM_EQ2_CANSMCHANNELMAPPINGOFPCPARTITIONCONFIG                                             
#define BSWM_EQ2_CANSMCHANNELSTATEOFPCPARTITIONCONFIG                                               BswM_CanSMChannelState
#define BSWM_EQ2_COMDMHANDLINGDISABLEPARAMETERSOFPCPARTITIONCONFIG                                  
#define BSWM_EQ2_COMDMHANDLINGENABLEPARAMETERSOFPCPARTITIONCONFIG                                   
#define BSWM_EQ2_COMDMHANDLINGPARAMETERSOFPCPARTITIONCONFIG                                         BswM_ComDMHandlingParameters
#define BSWM_EQ2_COMMALLOWCOMPARAMETERSOFPCPARTITIONCONFIG                                          
#define BSWM_EQ2_COMMCHANNELMAPPINGOFPCPARTITIONCONFIG                                              
#define BSWM_EQ2_COMMCHANNELSTATEOFPCPARTITIONCONFIG                                                BswM_ComMChannelState
#define BSWM_EQ2_COMMPNCMAPPINGOFPCPARTITIONCONFIG                                                  BswM_ComMPncMapping
#define BSWM_EQ2_COMMPNCSTATEOFPCPARTITIONCONFIG                                                    BswM_ComMPncState
#define BSWM_EQ2_COMPDUGROUPHANDLINGPARAMETERSOFPCPARTITIONCONFIG                                   BswM_ComPduGroupHandlingParameters
#define BSWM_EQ2_COMPDUGROUPHANDLINGSTARTPARAMETERSOFPCPARTITIONCONFIG                              
#define BSWM_EQ2_COMPDUGROUPHANDLINGSTOPPARAMETERSOFPCPARTITIONCONFIG                               
#define BSWM_EQ2_DCMCOMMAPPINGOFPCPARTITIONCONFIG                                                   
#define BSWM_EQ2_DCMCOMSTATEOFPCPARTITIONCONFIG                                                     BswM_DcmComState
#define BSWM_EQ2_DEFERREDRULESOFPCPARTITIONCONFIG                                                   
#define BSWM_EQ2_ECUMMODEMAPPINGOFPCPARTITIONCONFIG                                                 BswM_EcuMModeMapping
#define BSWM_EQ2_ECUMMODESTATEOFPCPARTITIONCONFIG                                                   (&(BswM_EcuMModeState))
#define BSWM_EQ2_ECUMRUNREQUESTMAPPINGOFPCPARTITIONCONFIG                                           BswM_EcuMRunRequestMapping
#define BSWM_EQ2_ECUMRUNREQUESTSTATEOFPCPARTITIONCONFIG                                             BswM_EcuMRunRequestState
#define BSWM_EQ2_ECUMSTATESWITCHPARAMETERSOFPCPARTITIONCONFIG                                       BswM_EcuMStateSwitchParameters
#define BSWM_EQ2_EXPRESSIONSOFPCPARTITIONCONFIG                                                     
#define BSWM_EQ2_FORCEDACTIONLISTPRIORITYOFPCPARTITIONCONFIG                                        (&(BswM_ForcedActionListPriority))
#define BSWM_EQ2_GENERICMAPPINGOFPCPARTITIONCONFIG                                                  BswM_GenericMapping
#define BSWM_EQ2_GENERICMODEPARAMETERSOFPCPARTITIONCONFIG                                           BswM_GenericModeParameters
#define BSWM_EQ2_GENERICSTATEOFPCPARTITIONCONFIG                                                    BswM_GenericState
#define BSWM_EQ2_IMMEDIATEUSEROFPCPARTITIONCONFIG                                                   BswM_ImmediateUser
#define BSWM_EQ2_INITACTIONLISTSOFPCPARTITIONCONFIG                                                 
#define BSWM_EQ2_INITGENVARANDINITALOFPCPARTITIONCONFIG                                             BswM_InitGenVarAndInitAL
#define BSWM_EQ2_INITVALUESOFPCPARTITIONCONFIG                                                      BswM_InitValues
#define BSWM_EQ2_INITIALIZEDOFPCPARTITIONCONFIG                                                     (&(BswM_Initialized))
#define BSWM_EQ2_MODENOTIFICATIONFCTOFPCPARTITIONCONFIG                                             BswM_ModeNotificationFct
#define BSWM_EQ2_MODEREQUESTQUEUEOFPCPARTITIONCONFIG                                                BswM_ModeRequestQueue
#define BSWM_EQ2_QUEUESEMAPHOREOFPCPARTITIONCONFIG                                                  (&(BswM_QueueSemaphore))
#define BSWM_EQ2_QUEUEWRITTENOFPCPARTITIONCONFIG                                                    (&(BswM_QueueWritten))
#define BSWM_EQ2_RULESTATESOFPCPARTITIONCONFIG                                                      BswM_RuleStates.raw
#define BSWM_EQ2_RULESINDOFPCPARTITIONCONFIG                                                        
#define BSWM_EQ2_RULESOFPCPARTITIONCONFIG                                                           
#define BSWM_EQ2_SWCMODEREQUESTUPDATEFCTOFPCPARTITIONCONFIG                                         BswM_SwcModeRequestUpdateFct
#define BSWM_EQ2_TIMERCONTROLPARAMETERSOFPCPARTITIONCONFIG                                          
#define BSWM_EQ2_TIMERSTATEOFPCPARTITIONCONFIG                                                      BswM_TimerState.raw
#define BSWM_EQ2_TIMERVALUEOFPCPARTITIONCONFIG                                                      BswM_TimerValue.raw
/** 
  \}
*/ 

/** 
  \defgroup  BswMPCSymbolicNonDereferenciateablePointers  BswM Symbolic Non Dereferenciateable Pointers (PRE_COMPILE)
  \brief  Symbolic non dereferenciateable pointers to be used if all values are optimized to a defined and to return a correct value for has macros in variants.
  \{
*/ 
#define BswM_EcuMModeMapping                                                                        ((BswM_EcuMModeMappingPtrType)(&(BswM_PCPartitionConfigRight)))  /**< Non derefenciateable valid pointer */
/** 
  \}
*/ 

/** 
  \defgroup  BswMPCSymbolicInitializationPointers  BswM Symbolic Initialization Pointers (PRE_COMPILE)
  \brief  Symbolic initialization pointers to be used in the call of a preinit or init function.
  \{
*/ 
#define BswM_Config_Left_Ptr                                                                        &(BswM_PCConfig.Config_Left)  /**< symbolic identifier which shall be used to initialize 'BswM' */
#define BswM_Config_Right_Ptr                                                                       &(BswM_PCConfig.Config_Right)  /**< symbolic identifier which shall be used to initialize 'BswM' */
/** 
  \}
*/ 

/** 
  \defgroup  BswMPCInitializationSymbols  BswM Initialization Symbols (PRE_COMPILE)
  \brief  Symbolic initialization pointers which may be used in the call of a preinit or init function. Please note, that the defined value can be a 'NULL_PTR' and the address operator is not usable.
  \{
*/ 
#define BswM_Config_Left                                                                            BswM_PCConfig.Config_Left  /**< symbolic identifier which could be used to initialize 'BswM */
#define BswM_Config_Right                                                                           BswM_PCConfig.Config_Right  /**< symbolic identifier which could be used to initialize 'BswM */
/** 
  \}
*/ 

/** 
  \defgroup  BswMPCGeneral  BswM General (PRE_COMPILE)
  \brief  General constant defines not associated with a group of defines.
  \{
*/ 
#define BSWM_CHECK_INIT_POINTER                                                                     STD_ON  /**< STD_ON if the init pointer shall not be used as NULL_PTR and a check shall validate this. */
#define BSWM_FINAL_MAGIC_NUMBER                                                                     0x2A1Eu  /**< the precompile constant to validate the size of the initialization structure at initialization time of BswM */
#define BSWM_INDIVIDUAL_POSTBUILD                                                                   STD_OFF  /**< the precompile constant to check, that the module is individual postbuildable. The module 'BswM' is not configured to be postbuild capable. */
#define BSWM_INIT_DATA                                                                              BSWM_CONST  /**< CompilerMemClassDefine for the initialization data. */
#define BSWM_INIT_DATA_HASH_CODE                                                                    1523858111  /**< the precompile constant to validate the initialization structure at initialization time of BswM with a hashcode. The seed value is '0x2A1Eu' */
#define BSWM_USE_ECUM_BSW_ERROR_HOOK                                                                STD_OFF  /**< STD_ON if the EcuM_BswErrorHook shall be called in the ConfigPtr check. */
#define BSWM_USE_INIT_POINTER                                                                       STD_ON  /**< STD_ON if the init pointer BswM shall be used. */
/** 
  \}
*/ 


/**********************************************************************************************************************
  CONFIGURATION CLASS: POST_BUILD
  SECTION: GLOBAL CONSTANT MACROS
**********************************************************************************************************************/
/** 
  \defgroup  BswMPBDataSwitches  BswM Data Switches  (POST_BUILD)
  \brief  These defines are used to deactivate data and their processing.
  \{
*/ 
#define BSWM_PBCONFIG                                                                               STD_OFF  /**< Deactivateable: 'BswM_PBConfig' Reason: 'the module configuration is VARIANT_PRE_COMPILE.' */
#define BSWM_LTCONFIGIDXOFPBCONFIG                                                                  STD_OFF  /**< Deactivateable: 'BswM_PBConfig.LTConfigIdx' Reason: 'the module configuration is VARIANT_PRE_COMPILE.' */
#define BSWM_PBPARTITIONCONFIGOFPBCONFIG                                                            STD_OFF  /**< Deactivateable: 'BswM_PBConfig.PBPartitionConfig' Reason: 'the module configuration is VARIANT_PRE_COMPILE.' */
#define BSWM_PCCONFIGIDXOFPBCONFIG                                                                  STD_OFF  /**< Deactivateable: 'BswM_PBConfig.PCConfigIdx' Reason: 'the module configuration is VARIANT_PRE_COMPILE.' */
#define BSWM_PBPARTITIONCONFIG                                                                      STD_OFF  /**< Deactivateable: 'BswM_PBPartitionConfigLeft' Reason: 'the module configuration is VARIANT_PRE_COMPILE.' and Deactivateable: 'BswM_PBPartitionConfigRight' Reason: 'the module configuration is VARIANT_PRE_COMPILE.' */
/** 
  \}
*/ 



/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
**********************************************************************************************************************/
/* PRQA S 0639, 0779 PRECOMPILEGLOBALDATATYPES */ /* MD_MSR_1.1_639, MD_MSR_Rule5.2_0779 */
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: SIZEOF DATA TYPES
**********************************************************************************************************************/
/** 
  \defgroup  BswMPCSizeOfTypes  BswM SizeOf Types (PRE_COMPILE)
  \brief  These type definitions are used for the SizeOf information.
  \{
*/ 
/**   \brief  value based type definition for BswM_SizeOfActionItems */
typedef uint8 BswM_SizeOfActionItemsType;

/**   \brief  value based type definition for BswM_SizeOfActionListQueue */
typedef uint8 BswM_SizeOfActionListQueueType;

/**   \brief  value based type definition for BswM_SizeOfActionLists */
typedef uint8 BswM_SizeOfActionListsType;

/**   \brief  value based type definition for BswM_SizeOfActions */
typedef uint8 BswM_SizeOfActionsType;

/**   \brief  value based type definition for BswM_SizeOfCanSMChannelMapping */
typedef uint8 BswM_SizeOfCanSMChannelMappingType;

/**   \brief  value based type definition for BswM_SizeOfCanSMChannelState */
typedef uint8 BswM_SizeOfCanSMChannelStateType;

/**   \brief  value based type definition for BswM_SizeOfComDMHandlingDisableParameters */
typedef uint8 BswM_SizeOfComDMHandlingDisableParametersType;

/**   \brief  value based type definition for BswM_SizeOfComDMHandlingEnableParameters */
typedef uint8 BswM_SizeOfComDMHandlingEnableParametersType;

/**   \brief  value based type definition for BswM_SizeOfComDMHandlingParameters */
typedef uint8 BswM_SizeOfComDMHandlingParametersType;

/**   \brief  value based type definition for BswM_SizeOfComMAllowComParameters */
typedef uint8 BswM_SizeOfComMAllowComParametersType;

/**   \brief  value based type definition for BswM_SizeOfComMChannelMapping */
typedef uint8 BswM_SizeOfComMChannelMappingType;

/**   \brief  value based type definition for BswM_SizeOfComMChannelState */
typedef uint8 BswM_SizeOfComMChannelStateType;

/**   \brief  value based type definition for BswM_SizeOfComMPncMapping */
typedef uint8 BswM_SizeOfComMPncMappingType;

/**   \brief  value based type definition for BswM_SizeOfComMPncState */
typedef uint8 BswM_SizeOfComMPncStateType;

/**   \brief  value based type definition for BswM_SizeOfComPduGroupHandlingParameters */
typedef uint8 BswM_SizeOfComPduGroupHandlingParametersType;

/**   \brief  value based type definition for BswM_SizeOfComPduGroupHandlingStartParameters */
typedef uint8 BswM_SizeOfComPduGroupHandlingStartParametersType;

/**   \brief  value based type definition for BswM_SizeOfComPduGroupHandlingStopParameters */
typedef uint8 BswM_SizeOfComPduGroupHandlingStopParametersType;

/**   \brief  value based type definition for BswM_SizeOfDcmComMapping */
typedef uint8 BswM_SizeOfDcmComMappingType;

/**   \brief  value based type definition for BswM_SizeOfDcmComState */
typedef uint8 BswM_SizeOfDcmComStateType;

/**   \brief  value based type definition for BswM_SizeOfDeferredRules */
typedef uint8 BswM_SizeOfDeferredRulesType;

/**   \brief  value based type definition for BswM_SizeOfEcuMModeMapping */
typedef uint8 BswM_SizeOfEcuMModeMappingType;

/**   \brief  value based type definition for BswM_SizeOfEcuMRunRequestMapping */
typedef uint8 BswM_SizeOfEcuMRunRequestMappingType;

/**   \brief  value based type definition for BswM_SizeOfEcuMRunRequestState */
typedef uint8 BswM_SizeOfEcuMRunRequestStateType;

/**   \brief  value based type definition for BswM_SizeOfEcuMStateSwitchParameters */
typedef uint8 BswM_SizeOfEcuMStateSwitchParametersType;

/**   \brief  value based type definition for BswM_SizeOfExpressions */
typedef uint8 BswM_SizeOfExpressionsType;

/**   \brief  value based type definition for BswM_SizeOfGenericMapping */
typedef uint8 BswM_SizeOfGenericMappingType;

/**   \brief  value based type definition for BswM_SizeOfGenericModeParameters */
typedef uint8 BswM_SizeOfGenericModeParametersType;

/**   \brief  value based type definition for BswM_SizeOfGenericState */
typedef uint8 BswM_SizeOfGenericStateType;

/**   \brief  value based type definition for BswM_SizeOfImmediateUser */
typedef uint8 BswM_SizeOfImmediateUserType;

/**   \brief  value based type definition for BswM_SizeOfInitActionLists */
typedef uint8 BswM_SizeOfInitActionListsType;

/**   \brief  value based type definition for BswM_SizeOfInitGenVarAndInitAL */
typedef uint8 BswM_SizeOfInitGenVarAndInitALType;

/**   \brief  value based type definition for BswM_SizeOfInitValues */
typedef uint8 BswM_SizeOfInitValuesType;

/**   \brief  value based type definition for BswM_SizeOfModeNotificationFct */
typedef uint8 BswM_SizeOfModeNotificationFctType;

/**   \brief  value based type definition for BswM_SizeOfModeRequestQueue */
typedef uint8 BswM_SizeOfModeRequestQueueType;

/**   \brief  value based type definition for BswM_SizeOfPartitionIdentifiers */
typedef uint8 BswM_SizeOfPartitionIdentifiersType;

/**   \brief  value based type definition for BswM_SizeOfRuleStates */
typedef uint8 BswM_SizeOfRuleStatesType;

/**   \brief  value based type definition for BswM_SizeOfRules */
typedef uint8 BswM_SizeOfRulesType;

/**   \brief  value based type definition for BswM_SizeOfRulesInd */
typedef uint8 BswM_SizeOfRulesIndType;

/**   \brief  value based type definition for BswM_SizeOfSwcModeRequestUpdateFct */
typedef uint8 BswM_SizeOfSwcModeRequestUpdateFctType;

/**   \brief  value based type definition for BswM_SizeOfTimerControlParameters */
typedef uint8 BswM_SizeOfTimerControlParametersType;

/**   \brief  value based type definition for BswM_SizeOfTimerState */
typedef uint8 BswM_SizeOfTimerStateType;

/**   \brief  value based type definition for BswM_SizeOfTimerValue */
typedef uint8 BswM_SizeOfTimerValueType;

/** 
  \}
*/ 

/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL SIMPLE DATA TYPES AND STRUCTURES
**********************************************************************************************************************/
/** 
  \defgroup  BswMPCIterableTypes  BswM Iterable Types (PRE_COMPILE)
  \brief  These type definitions are used to iterate over an array with least processor cycles for variable access as possible.
  \{
*/ 
/**   \brief  type used to iterate BswM_ActionItems */
typedef uint8_least BswM_ActionItemsIterType;

/**   \brief  type used to iterate BswM_ActionLists */
typedef uint8_least BswM_ActionListsIterType;

/**   \brief  type used to iterate BswM_Actions */
typedef uint8_least BswM_ActionsIterType;

/**   \brief  type used to iterate BswM_CanSMChannelMapping */
typedef uint8_least BswM_CanSMChannelMappingIterType;

/**   \brief  type used to iterate BswM_CanSMChannelState */
typedef uint8_least BswM_CanSMChannelStateIterType;

/**   \brief  type used to iterate BswM_ComDMHandlingDisableParameters */
typedef uint8_least BswM_ComDMHandlingDisableParametersIterType;

/**   \brief  type used to iterate BswM_ComDMHandlingEnableParameters */
typedef uint8_least BswM_ComDMHandlingEnableParametersIterType;

/**   \brief  type used to iterate BswM_ComDMHandlingParameters */
typedef uint8_least BswM_ComDMHandlingParametersIterType;

/**   \brief  type used to iterate BswM_ComMAllowComParameters */
typedef uint8_least BswM_ComMAllowComParametersIterType;

/**   \brief  type used to iterate BswM_ComMChannelMapping */
typedef uint8_least BswM_ComMChannelMappingIterType;

/**   \brief  type used to iterate BswM_ComMChannelState */
typedef uint8_least BswM_ComMChannelStateIterType;

/**   \brief  type used to iterate BswM_ComMPncMapping */
typedef uint8_least BswM_ComMPncMappingIterType;

/**   \brief  type used to iterate BswM_ComMPncState */
typedef uint8_least BswM_ComMPncStateIterType;

/**   \brief  type used to iterate BswM_ComPduGroupHandlingParameters */
typedef uint8_least BswM_ComPduGroupHandlingParametersIterType;

/**   \brief  type used to iterate BswM_ComPduGroupHandlingStartParameters */
typedef uint8_least BswM_ComPduGroupHandlingStartParametersIterType;

/**   \brief  type used to iterate BswM_ComPduGroupHandlingStopParameters */
typedef uint8_least BswM_ComPduGroupHandlingStopParametersIterType;

/**   \brief  type used to iterate BswM_DcmComMapping */
typedef uint8_least BswM_DcmComMappingIterType;

/**   \brief  type used to iterate BswM_DcmComState */
typedef uint8_least BswM_DcmComStateIterType;

/**   \brief  type used to iterate BswM_DeferredRules */
typedef uint8_least BswM_DeferredRulesIterType;

/**   \brief  type used to iterate BswM_EcuMModeMapping */
typedef uint8_least BswM_EcuMModeMappingIterType;

/**   \brief  type used to iterate BswM_EcuMRunRequestMapping */
typedef uint8_least BswM_EcuMRunRequestMappingIterType;

/**   \brief  type used to iterate BswM_EcuMRunRequestState */
typedef uint8_least BswM_EcuMRunRequestStateIterType;

/**   \brief  type used to iterate BswM_EcuMStateSwitchParameters */
typedef uint8_least BswM_EcuMStateSwitchParametersIterType;

/**   \brief  type used to iterate BswM_Expressions */
typedef uint8_least BswM_ExpressionsIterType;

/**   \brief  type used to iterate BswM_GenericMapping */
typedef uint8_least BswM_GenericMappingIterType;

/**   \brief  type used to iterate BswM_GenericModeParameters */
typedef uint8_least BswM_GenericModeParametersIterType;

/**   \brief  type used to iterate BswM_GenericState */
typedef uint8_least BswM_GenericStateIterType;

/**   \brief  type used to iterate BswM_ImmediateUser */
typedef uint8_least BswM_ImmediateUserIterType;

/**   \brief  type used to iterate BswM_InitActionLists */
typedef uint8_least BswM_InitActionListsIterType;

/**   \brief  type used to iterate BswM_InitGenVarAndInitAL */
typedef uint8_least BswM_InitGenVarAndInitALIterType;

/**   \brief  type used to iterate BswM_InitValues */
typedef uint8_least BswM_InitValuesIterType;

/**   \brief  type used to iterate BswM_ModeNotificationFct */
typedef uint8_least BswM_ModeNotificationFctIterType;

/**   \brief  type used to iterate BswM_PartitionIdentifiers */
typedef uint8_least BswM_PartitionIdentifiersIterType;

/**   \brief  type used to iterate BswM_RuleStates */
typedef uint8_least BswM_RuleStatesIterType;

/**   \brief  type used to iterate BswM_Rules */
typedef uint8_least BswM_RulesIterType;

/**   \brief  type used to iterate BswM_RulesInd */
typedef uint8_least BswM_RulesIndIterType;

/**   \brief  type used to iterate BswM_SwcModeRequestUpdateFct */
typedef uint8_least BswM_SwcModeRequestUpdateFctIterType;

/**   \brief  type used to iterate BswM_TimerControlParameters */
typedef uint8_least BswM_TimerControlParametersIterType;

/**   \brief  type used to iterate BswM_TimerState */
typedef uint8_least BswM_TimerStateIterType;

/**   \brief  type used to iterate BswM_TimerValue */
typedef uint8_least BswM_TimerValueIterType;

/**   \brief  type used to iterate BswM_PCPartitionConfig */
typedef uint8_least BswM_PCPartitionConfigIterType;

/** 
  \}
*/ 

/** 
  \defgroup  BswMPCIterableTypesWithSizeRelations  BswM Iterable Types With Size Relations (PRE_COMPILE)
  \brief  These type definitions are used to iterate over a VAR based array with the same iterator as the related CONST array.
  \{
*/ 
/**   \brief  type used to iterate BswM_ActionListQueue */
typedef BswM_ActionListsIterType BswM_ActionListQueueIterType;

/**   \brief  type used to iterate BswM_ModeRequestQueue */
typedef BswM_ImmediateUserIterType BswM_ModeRequestQueueIterType;

/** 
  \}
*/ 

/** 
  \defgroup  BswMPCValueTypes  BswM Value Types (PRE_COMPILE)
  \brief  These type definitions are used for value based data representations.
  \{
*/ 
/**   \brief  value based type definition for BswM_ActionsIdxOfActionItems */
typedef uint8 BswM_ActionsIdxOfActionItemsType;

/**   \brief  value based type definition for BswM_ParameterIdxOfActionItems */
typedef uint8 BswM_ParameterIdxOfActionItemsType;

/**   \brief  value based type definition for BswM_ParameterOfActionItems */
typedef uint8 BswM_ParameterOfActionItemsType;

/**   \brief  value based type definition for BswM_ParameterUsedOfActionItems */
typedef boolean BswM_ParameterUsedOfActionItemsType;

/**   \brief  value based type definition for BswM_ActionListQueue */
typedef uint8 BswM_ActionListQueueType;

/**   \brief  value based type definition for BswM_ActionItemsEndIdxOfActionLists */
typedef uint8 BswM_ActionItemsEndIdxOfActionListsType;

/**   \brief  value based type definition for BswM_ActionItemsStartIdxOfActionLists */
typedef uint8 BswM_ActionItemsStartIdxOfActionListsType;

/**   \brief  value based type definition for BswM_ActionItemsUsedOfActionLists */
typedef boolean BswM_ActionItemsUsedOfActionListsType;

/**   \brief  value based type definition for BswM_ConditionalOfActionLists */
typedef boolean BswM_ConditionalOfActionListsType;

/**   \brief  value based type definition for BswM_ExternalIdOfCanSMChannelMapping */
typedef uint32 BswM_ExternalIdOfCanSMChannelMappingType;

/**   \brief  value based type definition for BswM_ImmediateUserEndIdxOfCanSMChannelMapping */
typedef uint8 BswM_ImmediateUserEndIdxOfCanSMChannelMappingType;

/**   \brief  value based type definition for BswM_ImmediateUserStartIdxOfCanSMChannelMapping */
typedef uint8 BswM_ImmediateUserStartIdxOfCanSMChannelMappingType;

/**   \brief  value based type definition for BswM_ImmediateUserUsedOfCanSMChannelMapping */
typedef boolean BswM_ImmediateUserUsedOfCanSMChannelMappingType;

/**   \brief  value based type definition for BswM_ComDMHandlingDisableParametersEndIdxOfComDMHandlingParameters */
typedef uint8 BswM_ComDMHandlingDisableParametersEndIdxOfComDMHandlingParametersType;

/**   \brief  value based type definition for BswM_ComDMHandlingDisableParametersStartIdxOfComDMHandlingParameters */
typedef uint8 BswM_ComDMHandlingDisableParametersStartIdxOfComDMHandlingParametersType;

/**   \brief  value based type definition for BswM_ComDMHandlingDisableParametersUsedOfComDMHandlingParameters */
typedef boolean BswM_ComDMHandlingDisableParametersUsedOfComDMHandlingParametersType;

/**   \brief  value based type definition for BswM_ComDMHandlingEnableParametersEndIdxOfComDMHandlingParameters */
typedef uint8 BswM_ComDMHandlingEnableParametersEndIdxOfComDMHandlingParametersType;

/**   \brief  value based type definition for BswM_ComDMHandlingEnableParametersStartIdxOfComDMHandlingParameters */
typedef uint8 BswM_ComDMHandlingEnableParametersStartIdxOfComDMHandlingParametersType;

/**   \brief  value based type definition for BswM_ComDMHandlingEnableParametersUsedOfComDMHandlingParameters */
typedef boolean BswM_ComDMHandlingEnableParametersUsedOfComDMHandlingParametersType;

/**   \brief  value based type definition for BswM_ExternalIdOfComMChannelMapping */
typedef uint32 BswM_ExternalIdOfComMChannelMappingType;

/**   \brief  value based type definition for BswM_ImmediateUserEndIdxOfComMChannelMapping */
typedef uint8 BswM_ImmediateUserEndIdxOfComMChannelMappingType;

/**   \brief  value based type definition for BswM_ImmediateUserStartIdxOfComMChannelMapping */
typedef uint8 BswM_ImmediateUserStartIdxOfComMChannelMappingType;

/**   \brief  value based type definition for BswM_ImmediateUserUsedOfComMChannelMapping */
typedef boolean BswM_ImmediateUserUsedOfComMChannelMappingType;

/**   \brief  value based type definition for BswM_ExternalIdOfComMPncMapping */
typedef uint32 BswM_ExternalIdOfComMPncMappingType;

/**   \brief  value based type definition for BswM_ImmediateUserEndIdxOfComMPncMapping */
typedef uint8 BswM_ImmediateUserEndIdxOfComMPncMappingType;

/**   \brief  value based type definition for BswM_ImmediateUserStartIdxOfComMPncMapping */
typedef uint8 BswM_ImmediateUserStartIdxOfComMPncMappingType;

/**   \brief  value based type definition for BswM_ImmediateUserUsedOfComMPncMapping */
typedef boolean BswM_ImmediateUserUsedOfComMPncMappingType;

/**   \brief  value based type definition for BswM_ComPduGroupHandlingStartParametersEndIdxOfComPduGroupHandlingParameters */
typedef uint8 BswM_ComPduGroupHandlingStartParametersEndIdxOfComPduGroupHandlingParametersType;

/**   \brief  value based type definition for BswM_ComPduGroupHandlingStartParametersStartIdxOfComPduGroupHandlingParameters */
typedef uint8 BswM_ComPduGroupHandlingStartParametersStartIdxOfComPduGroupHandlingParametersType;

/**   \brief  value based type definition for BswM_ComPduGroupHandlingStartParametersUsedOfComPduGroupHandlingParameters */
typedef boolean BswM_ComPduGroupHandlingStartParametersUsedOfComPduGroupHandlingParametersType;

/**   \brief  value based type definition for BswM_ComPduGroupHandlingStopParametersEndIdxOfComPduGroupHandlingParameters */
typedef uint8 BswM_ComPduGroupHandlingStopParametersEndIdxOfComPduGroupHandlingParametersType;

/**   \brief  value based type definition for BswM_ComPduGroupHandlingStopParametersStartIdxOfComPduGroupHandlingParameters */
typedef uint8 BswM_ComPduGroupHandlingStopParametersStartIdxOfComPduGroupHandlingParametersType;

/**   \brief  value based type definition for BswM_ComPduGroupHandlingStopParametersUsedOfComPduGroupHandlingParameters */
typedef boolean BswM_ComPduGroupHandlingStopParametersUsedOfComPduGroupHandlingParametersType;

/**   \brief  value based type definition for BswM_ExternalIdOfDcmComMapping */
typedef uint32 BswM_ExternalIdOfDcmComMappingType;

/**   \brief  value based type definition for BswM_ImmediateUserEndIdxOfDcmComMapping */
typedef uint8 BswM_ImmediateUserEndIdxOfDcmComMappingType;

/**   \brief  value based type definition for BswM_ImmediateUserStartIdxOfDcmComMapping */
typedef uint8 BswM_ImmediateUserStartIdxOfDcmComMappingType;

/**   \brief  value based type definition for BswM_ImmediateUserUsedOfDcmComMapping */
typedef boolean BswM_ImmediateUserUsedOfDcmComMappingType;

/**   \brief  value based type definition for BswM_RulesIdxOfDeferredRules */
typedef uint8 BswM_RulesIdxOfDeferredRulesType;

/**   \brief  value based type definition for BswM_InitValueOfEcuMModeMapping */
typedef uint8 BswM_InitValueOfEcuMModeMappingType;

/**   \brief  value based type definition for BswM_EcuMModeState */
typedef uint8 BswM_EcuMModeStateType;

/**   \brief  value based type definition for BswM_ExternalIdOfEcuMRunRequestMapping */
typedef uint32 BswM_ExternalIdOfEcuMRunRequestMappingType;

/**   \brief  value based type definition for BswM_ForcedActionListPriority */
typedef uint8 BswM_ForcedActionListPriorityType;

/**   \brief  value based type definition for BswM_ExternalIdOfGenericMapping */
typedef uint32 BswM_ExternalIdOfGenericMappingType;

/**   \brief  value based type definition for BswM_ImmediateUserEndIdxOfGenericMapping */
typedef uint8 BswM_ImmediateUserEndIdxOfGenericMappingType;

/**   \brief  value based type definition for BswM_ImmediateUserStartIdxOfGenericMapping */
typedef uint8 BswM_ImmediateUserStartIdxOfGenericMappingType;

/**   \brief  value based type definition for BswM_ImmediateUserUsedOfGenericMapping */
typedef boolean BswM_ImmediateUserUsedOfGenericMappingType;

/**   \brief  value based type definition for BswM_OnInitOfImmediateUser */
typedef boolean BswM_OnInitOfImmediateUserType;

/**   \brief  value based type definition for BswM_RulesIndEndIdxOfImmediateUser */
typedef uint8 BswM_RulesIndEndIdxOfImmediateUserType;

/**   \brief  value based type definition for BswM_RulesIndStartIdxOfImmediateUser */
typedef uint8 BswM_RulesIndStartIdxOfImmediateUserType;

/**   \brief  value based type definition for BswM_RulesIndUsedOfImmediateUser */
typedef boolean BswM_RulesIndUsedOfImmediateUserType;

/**   \brief  value based type definition for BswM_InitActionLists */
typedef uint8 BswM_InitActionListsType;

/**   \brief  value based type definition for BswM_InitValues */
typedef uint16 BswM_InitValuesType;

/**   \brief  value based type definition for BswM_Initialized */
typedef boolean BswM_InitializedType;

/**   \brief  value based type definition for BswM_ModeRequestQueue */
typedef uint8 BswM_ModeRequestQueueType;

/**   \brief  value based type definition for BswM_PCPartitionConfigIdxOfPartitionIdentifiers */
typedef uint8 BswM_PCPartitionConfigIdxOfPartitionIdentifiersType;

/**   \brief  value based type definition for BswM_PartitionSNVOfPartitionIdentifiers */
typedef uint32 BswM_PartitionSNVOfPartitionIdentifiersType;

/**   \brief  value based type definition for BswM_QueueSemaphore */
typedef uint8 BswM_QueueSemaphoreType;

/**   \brief  value based type definition for BswM_QueueWritten */
typedef boolean BswM_QueueWrittenType;

/**   \brief  value based type definition for BswM_RuleStates */
typedef uint8 BswM_RuleStatesType;

/**   \brief  value based type definition for BswM_ActionListsFalseIdxOfRules */
typedef uint8 BswM_ActionListsFalseIdxOfRulesType;

/**   \brief  value based type definition for BswM_ActionListsFalseUsedOfRules */
typedef boolean BswM_ActionListsFalseUsedOfRulesType;

/**   \brief  value based type definition for BswM_ActionListsTrueIdxOfRules */
typedef uint8 BswM_ActionListsTrueIdxOfRulesType;

/**   \brief  value based type definition for BswM_ActionListsTrueUsedOfRules */
typedef boolean BswM_ActionListsTrueUsedOfRulesType;

/**   \brief  value based type definition for BswM_ExpressionsIdxOfRules */
typedef uint8 BswM_ExpressionsIdxOfRulesType;

/**   \brief  value based type definition for BswM_IdOfRules */
typedef uint8 BswM_IdOfRulesType;

/**   \brief  value based type definition for BswM_InitOfRules */
typedef uint8 BswM_InitOfRulesType;

/**   \brief  value based type definition for BswM_RuleStatesIdxOfRules */
typedef uint8 BswM_RuleStatesIdxOfRulesType;

/**   \brief  value based type definition for BswM_RulesInd */
typedef uint8 BswM_RulesIndType;

/**   \brief  value based type definition for BswM_TimerState */
typedef uint8 BswM_TimerStateType;

/**   \brief  value based type definition for BswM_TimerValue */
typedef uint32 BswM_TimerValueType;

/** 
  \}
*/ 


/* PRQA L:PRECOMPILEGLOBALDATATYPES */

typedef uint8 BswM_UserDomainType; /* user domain: CanSM, LinSM... */

/* It is possible to configure any user number from 0 to 65535 */
typedef uint16 BswM_UserType;
typedef uint16 BswM_ModeType;
typedef uint8 BswM_HandleType;
typedef P2FUNC (void, BSWM_CODE, BswM_InitGenVarAndInitALType)(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
typedef P2FUNC (uint8, BSWM_CODE, BswM_ExpressionFuncType)(BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);
typedef P2FUNC (Std_ReturnType, BSWM_CODE, BswM_ActionFuncType)(BswM_HandleType handleId, BswM_PCPartitionConfigIdxOfPartitionIdentifiersType partitionIdx);

typedef P2FUNC (void, BSWM_CODE, BswM_PartitionFunctionType)(void);

/* PRQA S 0639, 0779 PRECOMPILEGLOBALDATATYPES */ /* MD_MSR_1.1_639, MD_MSR_Rule5.2_0779 */
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL COMPLEX DATA TYPES AND STRUCTURES
**********************************************************************************************************************/
/** 
  \defgroup  BswMPCStructTypes  BswM Struct Types (PRE_COMPILE)
  \brief  These type definitions are used for structured data representations.
  \{
*/ 
/**   \brief  type used in BswM_ActionItems */
typedef struct sBswM_ActionItemsType
{
  BswM_ActionsIdxOfActionItemsType ActionsIdxOfActionItems;  /**< the index of the 1:1 relation pointing to BswM_Actions */
  BswM_ParameterOfActionItemsType ParameterOfActionItems;  /**< the enum value of the according target of the 0:1 relation pointing to BswM_ComMAllowComParameters,BswM_ComMModeLimitationParameters,BswM_ComMModeSwitchParameters,BswM_ComDMControlParameters,BswM_EcuMSelectShutdownTargetParameters,BswM_EcuMStateSwitchParameters,BswM_IdsmBlockStateChangeRequestParameters,BswM_LinScheduleRequestParameters,BswM_NmControlParameters,BswM_ComSwitchIPduModeParameters,BswM_ComPduGroupSwitchParameters,BswM_ComPduGroupHandlingParameters,BswM_ComDMHandlingParameters,BswM_ComTriggerIPduSendParameters,BswM_PduRouterControlParameters,BswM_TimerControlParameters,BswM_GenericModeParameters,BswM_GenericModeRefParameters,BswM_J1939DcmStateParameters,BswM_J1939RmStateParameters,BswM_SdClientParameters,BswM_SdConsumedParameters,BswM_SdServerParameters,BswM_SdServiceGroupSwitchParameters,BswM_RuleControlParameters,BswM_ActionLists,BswM_Rules */
  BswM_ParameterIdxOfActionItemsType ParameterIdxOfActionItems;  /**< the index of the 0:1 relation pointing to BswM_ComMAllowComParameters,BswM_ComMModeLimitationParameters,BswM_ComMModeSwitchParameters,BswM_ComDMControlParameters,BswM_EcuMSelectShutdownTargetParameters,BswM_EcuMStateSwitchParameters,BswM_IdsmBlockStateChangeRequestParameters,BswM_LinScheduleRequestParameters,BswM_NmControlParameters,BswM_ComSwitchIPduModeParameters,BswM_ComPduGroupSwitchParameters,BswM_ComPduGroupHandlingParameters,BswM_ComDMHandlingParameters,BswM_ComTriggerIPduSendParameters,BswM_PduRouterControlParameters,BswM_TimerControlParameters,BswM_GenericModeParameters,BswM_GenericModeRefParameters,BswM_J1939DcmStateParameters,BswM_J1939RmStateParameters,BswM_SdClientParameters,BswM_SdConsumedParameters,BswM_SdServerParameters,BswM_SdServiceGroupSwitchParameters,BswM_RuleControlParameters,BswM_ActionLists,BswM_Rules */
} BswM_ActionItemsType;

/**   \brief  type used in BswM_ActionLists */
typedef struct sBswM_ActionListsType
{
  BswM_ConditionalOfActionListsType ConditionalOfActionLists;  /**< If true, action list is executed on condition else on trigger. */
  BswM_ActionItemsEndIdxOfActionListsType ActionItemsEndIdxOfActionLists;  /**< the end index of the 0:n relation pointing to BswM_ActionItems */
  BswM_ActionItemsStartIdxOfActionListsType ActionItemsStartIdxOfActionLists;  /**< the start index of the 0:n relation pointing to BswM_ActionItems */
} BswM_ActionListsType;

/**   \brief  type used in BswM_CanSMChannelMapping */
typedef struct sBswM_CanSMChannelMappingType
{
  BswM_ExternalIdOfCanSMChannelMappingType ExternalIdOfCanSMChannelMapping;  /**< External id of BswMCanSMIndication. */
} BswM_CanSMChannelMappingType;

/**   \brief  type used in BswM_ComDMHandlingDisableParameters */
typedef struct sBswM_ComDMHandlingDisableParametersType
{
  Com_IpduGroupIdType IpduGroupIdOfComDMHandlingDisableParameters;
} BswM_ComDMHandlingDisableParametersType;

/**   \brief  type used in BswM_ComDMHandlingEnableParameters */
typedef struct sBswM_ComDMHandlingEnableParametersType
{
  Com_IpduGroupIdType IpduGroupIdOfComDMHandlingEnableParameters;
} BswM_ComDMHandlingEnableParametersType;

/**   \brief  type used in BswM_ComDMHandlingParameters */
typedef struct sBswM_ComDMHandlingParametersType
{
  BswM_ComDMHandlingDisableParametersEndIdxOfComDMHandlingParametersType ComDMHandlingDisableParametersEndIdxOfComDMHandlingParameters;  /**< the end index of the 0:n relation pointing to BswM_ComDMHandlingDisableParameters */
  BswM_ComDMHandlingDisableParametersStartIdxOfComDMHandlingParametersType ComDMHandlingDisableParametersStartIdxOfComDMHandlingParameters;  /**< the start index of the 0:n relation pointing to BswM_ComDMHandlingDisableParameters */
  BswM_ComDMHandlingEnableParametersEndIdxOfComDMHandlingParametersType ComDMHandlingEnableParametersEndIdxOfComDMHandlingParameters;  /**< the end index of the 0:n relation pointing to BswM_ComDMHandlingEnableParameters */
  BswM_ComDMHandlingEnableParametersStartIdxOfComDMHandlingParametersType ComDMHandlingEnableParametersStartIdxOfComDMHandlingParameters;  /**< the start index of the 0:n relation pointing to BswM_ComDMHandlingEnableParameters */
} BswM_ComDMHandlingParametersType;

/**   \brief  type used in BswM_ComMAllowComParameters */
typedef struct sBswM_ComMAllowComParametersType
{
  NetworkHandleType ChannelOfComMAllowComParameters;
  boolean AllowedOfComMAllowComParameters;
} BswM_ComMAllowComParametersType;

/**   \brief  type used in BswM_ComMChannelMapping */
typedef struct sBswM_ComMChannelMappingType
{
  BswM_ExternalIdOfComMChannelMappingType ExternalIdOfComMChannelMapping;  /**< External id of BswMComMIndication. */
} BswM_ComMChannelMappingType;

/**   \brief  type used in BswM_ComMPncMapping */
typedef struct sBswM_ComMPncMappingType
{
  BswM_ExternalIdOfComMPncMappingType ExternalIdOfComMPncMapping;  /**< External id of BswMComMPncRequest. */
  BswM_ImmediateUserEndIdxOfComMPncMappingType ImmediateUserEndIdxOfComMPncMapping;  /**< the end index of the 0:n relation pointing to BswM_ImmediateUser */
  BswM_ImmediateUserStartIdxOfComMPncMappingType ImmediateUserStartIdxOfComMPncMapping;  /**< the start index of the 0:n relation pointing to BswM_ImmediateUser */
} BswM_ComMPncMappingType;

/**   \brief  type used in BswM_ComPduGroupHandlingParameters */
typedef struct sBswM_ComPduGroupHandlingParametersType
{
  BswM_ComPduGroupHandlingStartParametersEndIdxOfComPduGroupHandlingParametersType ComPduGroupHandlingStartParametersEndIdxOfComPduGroupHandlingParameters;  /**< the end index of the 0:n relation pointing to BswM_ComPduGroupHandlingStartParameters */
  BswM_ComPduGroupHandlingStartParametersStartIdxOfComPduGroupHandlingParametersType ComPduGroupHandlingStartParametersStartIdxOfComPduGroupHandlingParameters;  /**< the start index of the 0:n relation pointing to BswM_ComPduGroupHandlingStartParameters */
  BswM_ComPduGroupHandlingStopParametersEndIdxOfComPduGroupHandlingParametersType ComPduGroupHandlingStopParametersEndIdxOfComPduGroupHandlingParameters;  /**< the end index of the 0:n relation pointing to BswM_ComPduGroupHandlingStopParameters */
  BswM_ComPduGroupHandlingStopParametersStartIdxOfComPduGroupHandlingParametersType ComPduGroupHandlingStopParametersStartIdxOfComPduGroupHandlingParameters;  /**< the start index of the 0:n relation pointing to BswM_ComPduGroupHandlingStopParameters */
} BswM_ComPduGroupHandlingParametersType;

/**   \brief  type used in BswM_ComPduGroupHandlingStartParameters */
typedef struct sBswM_ComPduGroupHandlingStartParametersType
{
  Com_IpduGroupIdType IpduGroupIdOfComPduGroupHandlingStartParameters;
} BswM_ComPduGroupHandlingStartParametersType;

/**   \brief  type used in BswM_ComPduGroupHandlingStopParameters */
typedef struct sBswM_ComPduGroupHandlingStopParametersType
{
  Com_IpduGroupIdType IpduGroupIdOfComPduGroupHandlingStopParameters;
} BswM_ComPduGroupHandlingStopParametersType;

/**   \brief  type used in BswM_DcmComMapping */
typedef struct sBswM_DcmComMappingType
{
  BswM_ExternalIdOfDcmComMappingType ExternalIdOfDcmComMapping;  /**< External id of BswMDcmComModeRequest. */
} BswM_DcmComMappingType;

/**   \brief  type used in BswM_DeferredRules */
typedef struct sBswM_DeferredRulesType
{
  BswM_RulesIdxOfDeferredRulesType RulesIdxOfDeferredRules;  /**< the index of the 1:1 relation pointing to BswM_Rules */
} BswM_DeferredRulesType;

/**   \brief  type used in BswM_EcuMModeMapping */
typedef struct sBswM_EcuMModeMappingType
{
  uint8 BswM_EcuMModeMappingNeverUsed;  /**< dummy entry for the structure in the configuration variant precompile which is not used by the code. */
} BswM_EcuMModeMappingType;

/**   \brief  type used in BswM_EcuMRunRequestMapping */
typedef struct sBswM_EcuMRunRequestMappingType
{
  BswM_ExternalIdOfEcuMRunRequestMappingType ExternalIdOfEcuMRunRequestMapping;  /**< External id of BswMEcuMRUNRequestIndication. */
} BswM_EcuMRunRequestMappingType;

/**   \brief  type used in BswM_EcuMStateSwitchParameters */
typedef struct sBswM_EcuMStateSwitchParametersType
{
  EcuM_StateType TargetStateOfEcuMStateSwitchParameters;
} BswM_EcuMStateSwitchParametersType;

/**   \brief  type used in BswM_GenericMapping */
typedef struct sBswM_GenericMappingType
{
  BswM_ExternalIdOfGenericMappingType ExternalIdOfGenericMapping;  /**< External id of BswMGenericRequest. */
  BswM_ImmediateUserEndIdxOfGenericMappingType ImmediateUserEndIdxOfGenericMapping;  /**< the end index of the 0:n relation pointing to BswM_ImmediateUser */
  BswM_ImmediateUserStartIdxOfGenericMappingType ImmediateUserStartIdxOfGenericMapping;  /**< the start index of the 0:n relation pointing to BswM_ImmediateUser */
  BswM_ModeType InitValueOfGenericMapping;  /**< Initialization value of port. */
} BswM_GenericMappingType;

/**   \brief  type used in BswM_GenericModeParameters */
typedef struct sBswM_GenericModeParametersType
{
  BswM_ModeType ModeOfGenericModeParameters;
  BswM_UserType UserOfGenericModeParameters;
} BswM_GenericModeParametersType;

/**   \brief  type used in BswM_ImmediateUser */
typedef struct sBswM_ImmediateUserType
{
  BswM_OnInitOfImmediateUserType OnInitOfImmediateUser;  /**< Arbitrate depending rules on initialization. */
  BswM_RulesIndEndIdxOfImmediateUserType RulesIndEndIdxOfImmediateUser;  /**< the end index of the 0:n relation pointing to BswM_RulesInd */
  BswM_RulesIndStartIdxOfImmediateUserType RulesIndStartIdxOfImmediateUser;  /**< the start index of the 0:n relation pointing to BswM_RulesInd */
} BswM_ImmediateUserType;

/**   \brief  type used in BswM_PartitionIdentifiers */
typedef struct sBswM_PartitionIdentifiersType
{
  BswM_PartitionSNVOfPartitionIdentifiersType PartitionSNVOfPartitionIdentifiers;
  BswM_PCPartitionConfigIdxOfPartitionIdentifiersType PCPartitionConfigIdxOfPartitionIdentifiers;  /**< the index of the 1:1 relation pointing to BswM_PCPartitionConfig */
} BswM_PartitionIdentifiersType;

/**   \brief  type used in BswM_Rules */
typedef struct sBswM_RulesType
{
  BswM_ActionListsFalseIdxOfRulesType ActionListsFalseIdxOfRules;  /**< the index of the 0:1 relation pointing to BswM_ActionLists */
  BswM_ActionListsTrueIdxOfRulesType ActionListsTrueIdxOfRules;  /**< the index of the 0:1 relation pointing to BswM_ActionLists */
  BswM_ExpressionsIdxOfRulesType ExpressionsIdxOfRules;  /**< the index of the 1:1 relation pointing to BswM_Expressions */
  BswM_IdOfRulesType IdOfRules;  /**< External id of rule. */
  BswM_RuleStatesIdxOfRulesType RuleStatesIdxOfRules;  /**< the index of the 1:1 relation pointing to BswM_RuleStates */
} BswM_RulesType;

/**   \brief  type used in BswM_TimerControlParameters */
typedef struct sBswM_TimerControlParametersType
{
  uint8 TimerOfTimerControlParameters;
} BswM_TimerControlParametersType;

/** 
  \}
*/ 

/** 
  \defgroup  BswMPCSymbolicStructTypes  BswM Symbolic Struct Types (PRE_COMPILE)
  \brief  These structs are used in unions to have a symbol based data representation style.
  \{
*/ 
/**   \brief  type to be used as symbolic data element access to BswM_ActionListQueue in the predefined variant Left in the partition context  */
typedef struct BswM_ActionListQueueLeftStructSTag
{
  BswM_ActionListQueueType AL_CC_AL_RBTM_FL_BODY3_8uqv9blm85ehm0msat385m76v_03d5f5f6_TX_Disable;
  BswM_ActionListQueueType AL_CC_AL_RBTM_FL_BODY3_8uqv9blm85ehm0msat385m76v_03d5f5f6_TX_EnableNoinit;
  BswM_ActionListQueueType AL_ESH_AL_ExitRun;
  BswM_ActionListQueueType AL_ESH_AL_RunToPostRun;
  BswM_ActionListQueueType AL_ESH_AL_WaitForNvMToShutdown;
  BswM_ActionListQueueType AL_ESH_AL_WakeupToPrep;
  BswM_ActionListQueueType AL_ESH_AL_WaitForNvMWakeup;
  BswM_ActionListQueueType AL_ESH_AL_WakeupToRun;
  BswM_ActionListQueueType AL_ESH_AL_DemInit;
  BswM_ActionListQueueType AL_ESH_AL_InitToWakeup;
  BswM_ActionListQueueType AL_ESH_AL_PostRunToPrepShutdown;
  BswM_ActionListQueueType AL_ESH_AL_ESH_PostRunToPrepCheck;
  BswM_ActionListQueueType AL_ESH_AL_PostRunToRun;
  BswM_ActionListQueueType AL_ESH_AL_ExitPostRun;
  BswM_ActionListQueueType AL_ESH_AL_PrepShutdownToWaitForNvM;
  BswM_ActionListQueueType AL_INIT_AL_Initialize;
  BswM_ActionListQueueType AL_CC_AL_RBTM_FL_BODY3_8uqv9blm85ehm0msat385m76v_03d5f5f6_PNC_00_MAPPING_b2c42696_RX_Disable;
  BswM_ActionListQueueType AL_CC_AL_RBTM_FL_BODY3_8uqv9blm85ehm0msat385m76v_03d5f5f6_PNC_00_MAPPING_b2c42696_RX_EnableNoinit;
  BswM_ActionListQueueType AL_CC_AL_RBTM_FL_BODY3_8uqv9blm85ehm0msat385m76v_03d5f5f6_PNC_00_MAPPING_b2c42696_Disable_DM;
  BswM_ActionListQueueType AL_CC_AL_RBTM_FL_BODY3_8uqv9blm85ehm0msat385m76v_03d5f5f6_PNC_00_MAPPING_b2c42696_Enable_DM;
  BswM_ActionListQueueType AL_CC_AL_RBTM_FL_BODY3_8uqv9blm85ehm0msat385m76v_03d5f5f6_PNC_00_MAPPING_b2c42696_TX_Disable;
  BswM_ActionListQueueType AL_CC_AL_RBTM_FL_BODY3_8uqv9blm85ehm0msat385m76v_03d5f5f6_PNC_00_MAPPING_b2c42696_TX_EnableNoinit;
  BswM_ActionListQueueType AL_CC_AL_RBTM_FL_BODY3_8uqv9blm85ehm0msat385m76v_03d5f5f6_PNC_20_MAPPING_796df885_Disable_DM;
  BswM_ActionListQueueType AL_CC_AL_RBTM_FL_BODY3_8uqv9blm85ehm0msat385m76v_03d5f5f6_PNC_20_MAPPING_796df885_Enable_DM;
  BswM_ActionListQueueType AL_CC_AL_RBTM_FL_BODY3_8uqv9blm85ehm0msat385m76v_03d5f5f6_PNC_20_MAPPING_796df885_TX_Disable;
  BswM_ActionListQueueType AL_CC_AL_RBTM_FL_BODY3_8uqv9blm85ehm0msat385m76v_03d5f5f6_PNC_20_MAPPING_796df885_TX_EnableNoinit;
  BswM_ActionListQueueType AL_CC_AL_RBTM_FL_BODY3_8uqv9blm85ehm0msat385m76v_03d5f5f6_PNC_20_MAPPING_796df885_RX_Disable;
  BswM_ActionListQueueType AL_CC_AL_RBTM_FL_BODY3_8uqv9blm85ehm0msat385m76v_03d5f5f6_PNC_20_MAPPING_796df885_RX_EnableNoinit;
  BswM_ActionListQueueType AL_AL_SwcDiag_FullCom;
  BswM_ActionListQueueType AL_AL_SwcDiag_NotFullCom;
} BswM_ActionListQueueLeftStructSType;

/**   \brief  type to be used as symbolic data element access to BswM_ActionListQueue in the predefined variant Right in the partition context  */
typedef struct BswM_ActionListQueueRightStructSTag
{
  BswM_ActionListQueueType AL_ESH_AL_ExitRun;
  BswM_ActionListQueueType AL_ESH_AL_RunToPostRun;
  BswM_ActionListQueueType AL_ESH_AL_WaitForNvMToShutdown;
  BswM_ActionListQueueType AL_ESH_AL_WakeupToPrep;
  BswM_ActionListQueueType AL_ESH_AL_WaitForNvMWakeup;
  BswM_ActionListQueueType AL_ESH_AL_WakeupToRun;
  BswM_ActionListQueueType AL_ESH_AL_DemInit;
  BswM_ActionListQueueType AL_ESH_AL_InitToWakeup;
  BswM_ActionListQueueType AL_ESH_AL_PostRunToPrepShutdown;
  BswM_ActionListQueueType AL_ESH_AL_ESH_PostRunToPrepCheck;
  BswM_ActionListQueueType AL_ESH_AL_PostRunToRun;
  BswM_ActionListQueueType AL_ESH_AL_ExitPostRun;
  BswM_ActionListQueueType AL_ESH_AL_PrepShutdownToWaitForNvM;
  BswM_ActionListQueueType AL_INIT_AL_Initialize;
  BswM_ActionListQueueType AL_CC_AL_RBTM_FR_BODY3_4xwwtd59665s787n6ctawh7k8_23a94727_PNC_00_MAPPING_b2c42696_Disable_DM;
  BswM_ActionListQueueType AL_CC_AL_RBTM_FR_BODY3_4xwwtd59665s787n6ctawh7k8_23a94727_PNC_00_MAPPING_b2c42696_Enable_DM;
  BswM_ActionListQueueType AL_CC_AL_RBTM_FR_BODY3_4xwwtd59665s787n6ctawh7k8_23a94727_PNC_00_MAPPING_b2c42696_RX_Disable;
  BswM_ActionListQueueType AL_CC_AL_RBTM_FR_BODY3_4xwwtd59665s787n6ctawh7k8_23a94727_PNC_00_MAPPING_b2c42696_RX_EnableNoinit;
  BswM_ActionListQueueType AL_CC_AL_RBTM_FR_BODY3_4xwwtd59665s787n6ctawh7k8_23a94727_TX_Disable;
  BswM_ActionListQueueType AL_CC_AL_RBTM_FR_BODY3_4xwwtd59665s787n6ctawh7k8_23a94727_TX_EnableNoinit;
  BswM_ActionListQueueType AL_CC_AL_RBTM_FR_BODY3_4xwwtd59665s787n6ctawh7k8_23a94727_PNC_20_MAPPING_796df885_TX_Disable;
  BswM_ActionListQueueType AL_CC_AL_RBTM_FR_BODY3_4xwwtd59665s787n6ctawh7k8_23a94727_PNC_20_MAPPING_796df885_TX_EnableNoinit;
  BswM_ActionListQueueType AL_CC_AL_RBTM_FR_BODY3_4xwwtd59665s787n6ctawh7k8_23a94727_PNC_00_MAPPING_b2c42696_TX_Disable;
  BswM_ActionListQueueType AL_CC_AL_RBTM_FR_BODY3_4xwwtd59665s787n6ctawh7k8_23a94727_PNC_00_MAPPING_b2c42696_TX_EnableNoinit;
  BswM_ActionListQueueType AL_CC_AL_RBTM_FR_BODY3_4xwwtd59665s787n6ctawh7k8_23a94727_PNC_20_MAPPING_796df885_Disable_DM;
  BswM_ActionListQueueType AL_CC_AL_RBTM_FR_BODY3_4xwwtd59665s787n6ctawh7k8_23a94727_PNC_20_MAPPING_796df885_Enable_DM;
  BswM_ActionListQueueType AL_CC_AL_RBTM_FR_BODY3_4xwwtd59665s787n6ctawh7k8_23a94727_PNC_20_MAPPING_796df885_RX_Disable;
  BswM_ActionListQueueType AL_CC_AL_RBTM_FR_BODY3_4xwwtd59665s787n6ctawh7k8_23a94727_PNC_20_MAPPING_796df885_RX_EnableNoinit;
  BswM_ActionListQueueType AL_AL_SwcDiag_FullCom;
  BswM_ActionListQueueType AL_AL_SwcDiag_NotFullCom;
} BswM_ActionListQueueRightStructSType;

/**   \brief  type to be used as symbolic data element access to BswM_RuleStates in the predefined variant Left in the partition context  */
typedef struct BswM_RuleStatesLeftStructSTag
{
  BswM_RuleStatesType R_CC_RBTM_FL_BODY3_8uqv9blm85ehm0msat385m76v_03d5f5f6_TX;
  BswM_RuleStatesType R_ESH_RunToPostRun;
  BswM_RuleStatesType R_ESH_RunToPostRunNested;
  BswM_RuleStatesType R_ESH_WaitToShutdown;
  BswM_RuleStatesType R_ESH_WakeupToPrep;
  BswM_RuleStatesType R_ESH_WaitToWakeup;
  BswM_RuleStatesType R_ESH_WakeupToRun;
  BswM_RuleStatesType R_ESH_DemInit;
  BswM_RuleStatesType R_ESH_InitToWakeup;
  BswM_RuleStatesType R_ESH_PostRunToPrepNested;
  BswM_RuleStatesType R_ESH_PostRunNested;
  BswM_RuleStatesType R_ESH_PostRun;
  BswM_RuleStatesType R_ESH_PrepToWait;
  BswM_RuleStatesType R_CC_RBTM_FL_BODY3_8uqv9blm85ehm0msat385m76v_03d5f5f6_PNC_00_MAPPING_b2c42696_RX;
  BswM_RuleStatesType R_CC_RBTM_FL_BODY3_8uqv9blm85ehm0msat385m76v_03d5f5f6_PNC_00_MAPPING_b2c42696_RX_DM;
  BswM_RuleStatesType R_CC_RBTM_FL_BODY3_8uqv9blm85ehm0msat385m76v_03d5f5f6_PNC_00_MAPPING_b2c42696_TX;
  BswM_RuleStatesType R_CC_RBTM_FL_BODY3_8uqv9blm85ehm0msat385m76v_03d5f5f6_PNC_20_MAPPING_796df885_RX_DM;
  BswM_RuleStatesType R_CC_RBTM_FL_BODY3_8uqv9blm85ehm0msat385m76v_03d5f5f6_PNC_20_MAPPING_796df885_TX;
  BswM_RuleStatesType R_CC_RBTM_FL_BODY3_8uqv9blm85ehm0msat385m76v_03d5f5f6_PNC_20_MAPPING_796df885_RX;
  BswM_RuleStatesType R_BswMRule_SwcDiagComMState;
} BswM_RuleStatesLeftStructSType;

/**   \brief  type to be used as symbolic data element access to BswM_RuleStates in the predefined variant Right in the partition context  */
typedef struct BswM_RuleStatesRightStructSTag
{
  BswM_RuleStatesType R_ESH_RunToPostRun;
  BswM_RuleStatesType R_ESH_RunToPostRunNested;
  BswM_RuleStatesType R_ESH_WaitToShutdown;
  BswM_RuleStatesType R_ESH_WakeupToPrep;
  BswM_RuleStatesType R_ESH_WaitToWakeup;
  BswM_RuleStatesType R_ESH_WakeupToRun;
  BswM_RuleStatesType R_ESH_DemInit;
  BswM_RuleStatesType R_ESH_InitToWakeup;
  BswM_RuleStatesType R_ESH_PostRunToPrepNested;
  BswM_RuleStatesType R_ESH_PostRunNested;
  BswM_RuleStatesType R_ESH_PostRun;
  BswM_RuleStatesType R_ESH_PrepToWait;
  BswM_RuleStatesType R_CC_RBTM_FR_BODY3_4xwwtd59665s787n6ctawh7k8_23a94727_PNC_00_MAPPING_b2c42696_RX_DM;
  BswM_RuleStatesType R_CC_RBTM_FR_BODY3_4xwwtd59665s787n6ctawh7k8_23a94727_PNC_00_MAPPING_b2c42696_RX;
  BswM_RuleStatesType R_CC_RBTM_FR_BODY3_4xwwtd59665s787n6ctawh7k8_23a94727_TX;
  BswM_RuleStatesType R_CC_RBTM_FR_BODY3_4xwwtd59665s787n6ctawh7k8_23a94727_PNC_20_MAPPING_796df885_TX;
  BswM_RuleStatesType R_CC_RBTM_FR_BODY3_4xwwtd59665s787n6ctawh7k8_23a94727_PNC_00_MAPPING_b2c42696_TX;
  BswM_RuleStatesType R_CC_RBTM_FR_BODY3_4xwwtd59665s787n6ctawh7k8_23a94727_PNC_20_MAPPING_796df885_RX_DM;
  BswM_RuleStatesType R_CC_RBTM_FR_BODY3_4xwwtd59665s787n6ctawh7k8_23a94727_PNC_20_MAPPING_796df885_RX;
  BswM_RuleStatesType R_BswMRule_SwcDiagComMState;
} BswM_RuleStatesRightStructSType;

/**   \brief  type to be used as symbolic data element access to BswM_TimerState in the predefined variant Left in the partition context  */
typedef struct BswM_TimerStateLeftStructSTag
{
  BswM_TimerStateType MRP_ESH_SelfRunRequestTimer;
} BswM_TimerStateLeftStructSType;

/**   \brief  type to be used as symbolic data element access to BswM_TimerState in the predefined variant Right in the partition context  */
typedef struct BswM_TimerStateRightStructSTag
{
  BswM_TimerStateType MRP_ESH_SelfRunRequestTimer;
} BswM_TimerStateRightStructSType;

/**   \brief  type to be used as symbolic data element access to BswM_TimerValue in the predefined variant Left in the partition context  */
typedef struct BswM_TimerValueLeftStructSTag
{
  BswM_TimerValueType MRP_ESH_SelfRunRequestTimer;
} BswM_TimerValueLeftStructSType;

/**   \brief  type to be used as symbolic data element access to BswM_TimerValue in the predefined variant Right in the partition context  */
typedef struct BswM_TimerValueRightStructSTag
{
  BswM_TimerValueType MRP_ESH_SelfRunRequestTimer;
} BswM_TimerValueRightStructSType;

/** 
  \}
*/ 

/** 
  \defgroup  BswMPCUnionIndexAndSymbolTypes  BswM Union Index And Symbol Types (PRE_COMPILE)
  \brief  These unions are used to access arrays in an index and symbol based style.
  \{
*/ 
/**   \brief  type to access BswM_ActionListQueue in an index and symbol based style. */
typedef union BswM_ActionListQueueUTag
{  /* PRQA S 0750 */  /* MD_CSL_Union */
  BswM_ActionListQueueType raw[30];
  BswM_ActionListQueueLeftStructSType strLeft;
  BswM_ActionListQueueRightStructSType strRight;
} BswM_ActionListQueueUType;

/**   \brief  type to access BswM_RuleStates in an index and symbol based style. */
typedef union BswM_RuleStatesUTag
{  /* PRQA S 0750 */  /* MD_CSL_Union */
  BswM_RuleStatesType raw[20];
  BswM_RuleStatesLeftStructSType strLeft;
  BswM_RuleStatesRightStructSType strRight;
} BswM_RuleStatesUType;

/**   \brief  type to access BswM_TimerState in an index and symbol based style. */
typedef union BswM_TimerStateUTag
{  /* PRQA S 0750 */  /* MD_CSL_Union */
  BswM_TimerStateType raw[1];
  BswM_TimerStateLeftStructSType strLeft;
  BswM_TimerStateRightStructSType strRight;
} BswM_TimerStateUType;

/**   \brief  type to access BswM_TimerValue in an index and symbol based style. */
typedef union BswM_TimerValueUTag
{  /* PRQA S 0750 */  /* MD_CSL_Union */
  BswM_TimerValueType raw[1];
  BswM_TimerValueLeftStructSType strLeft;
  BswM_TimerValueRightStructSType strRight;
} BswM_TimerValueUType;

/** 
  \}
*/ 

/** 
  \defgroup  BswMPCRootPointerTypes  BswM Root Pointer Types (PRE_COMPILE)
  \brief  These type definitions are used to point from the config root to symbol instances.
  \{
*/ 
/**   \brief  type used to point to BswM_ActionItems */
typedef P2CONST(BswM_ActionItemsType, TYPEDEF, BSWM_CONST) BswM_ActionItemsPtrType;

/**   \brief  type used to point to BswM_ActionListQueue */
typedef P2VAR(BswM_ActionListQueueType, TYPEDEF, BSWM_VAR_NO_INIT) BswM_ActionListQueuePtrType;

/**   \brief  type used to point to BswM_ActionLists */
typedef P2CONST(BswM_ActionListsType, TYPEDEF, BSWM_CONST) BswM_ActionListsPtrType;

/**   \brief  type used to point to BswM_Actions */
typedef P2CONST(BswM_ActionFuncType, TYPEDEF, BSWM_CONST) BswM_ActionsPtrType;

/**   \brief  type used to point to BswM_CanSMChannelMapping */
typedef P2CONST(BswM_CanSMChannelMappingType, TYPEDEF, BSWM_CONST) BswM_CanSMChannelMappingPtrType;

/**   \brief  type used to point to BswM_CanSMChannelState */
typedef P2VAR(CanSM_BswMCurrentStateType, TYPEDEF, BSWM_VAR_NO_INIT) BswM_CanSMChannelStatePtrType;

/**   \brief  type used to point to BswM_ComDMHandlingDisableParameters */
typedef P2CONST(BswM_ComDMHandlingDisableParametersType, TYPEDEF, BSWM_CONST) BswM_ComDMHandlingDisableParametersPtrType;

/**   \brief  type used to point to BswM_ComDMHandlingEnableParameters */
typedef P2CONST(BswM_ComDMHandlingEnableParametersType, TYPEDEF, BSWM_CONST) BswM_ComDMHandlingEnableParametersPtrType;

/**   \brief  type used to point to BswM_ComDMHandlingParameters */
typedef P2CONST(BswM_ComDMHandlingParametersType, TYPEDEF, BSWM_CONST) BswM_ComDMHandlingParametersPtrType;

/**   \brief  type used to point to BswM_ComMAllowComParameters */
typedef P2CONST(BswM_ComMAllowComParametersType, TYPEDEF, BSWM_CONST) BswM_ComMAllowComParametersPtrType;

/**   \brief  type used to point to BswM_ComMChannelMapping */
typedef P2CONST(BswM_ComMChannelMappingType, TYPEDEF, BSWM_CONST) BswM_ComMChannelMappingPtrType;

/**   \brief  type used to point to BswM_ComMChannelState */
typedef P2VAR(ComM_ModeType, TYPEDEF, BSWM_VAR_NO_INIT) BswM_ComMChannelStatePtrType;

/**   \brief  type used to point to BswM_ComMPncMapping */
typedef P2CONST(BswM_ComMPncMappingType, TYPEDEF, BSWM_CONST) BswM_ComMPncMappingPtrType;

/**   \brief  type used to point to BswM_ComMPncState */
typedef P2VAR(ComM_PncModeType, TYPEDEF, BSWM_VAR_NO_INIT) BswM_ComMPncStatePtrType;

/**   \brief  type used to point to BswM_ComPduGroupHandlingParameters */
typedef P2CONST(BswM_ComPduGroupHandlingParametersType, TYPEDEF, BSWM_CONST) BswM_ComPduGroupHandlingParametersPtrType;

/**   \brief  type used to point to BswM_ComPduGroupHandlingStartParameters */
typedef P2CONST(BswM_ComPduGroupHandlingStartParametersType, TYPEDEF, BSWM_CONST) BswM_ComPduGroupHandlingStartParametersPtrType;

/**   \brief  type used to point to BswM_ComPduGroupHandlingStopParameters */
typedef P2CONST(BswM_ComPduGroupHandlingStopParametersType, TYPEDEF, BSWM_CONST) BswM_ComPduGroupHandlingStopParametersPtrType;

/**   \brief  type used to point to BswM_DcmComMapping */
typedef P2CONST(BswM_DcmComMappingType, TYPEDEF, BSWM_CONST) BswM_DcmComMappingPtrType;

/**   \brief  type used to point to BswM_DcmComState */
typedef P2VAR(Dcm_CommunicationModeType, TYPEDEF, BSWM_VAR_NO_INIT) BswM_DcmComStatePtrType;

/**   \brief  type used to point to BswM_DeferredRules */
typedef P2CONST(BswM_DeferredRulesType, TYPEDEF, BSWM_CONST) BswM_DeferredRulesPtrType;

/**   \brief  type used to point to BswM_EcuMModeMapping */
typedef P2CONST(BswM_EcuMModeMappingType, TYPEDEF, BSWM_CONST) BswM_EcuMModeMappingPtrType;

/**   \brief  type used to point to BswM_EcuMModeState */
typedef P2VAR(BswM_EcuMModeStateType, TYPEDEF, BSWM_VAR_NO_INIT) BswM_EcuMModeStatePtrType;

/**   \brief  type used to point to BswM_EcuMRunRequestMapping */
typedef P2CONST(BswM_EcuMRunRequestMappingType, TYPEDEF, BSWM_CONST) BswM_EcuMRunRequestMappingPtrType;

/**   \brief  type used to point to BswM_EcuMRunRequestState */
typedef P2VAR(EcuM_RunStatusType, TYPEDEF, BSWM_VAR_NO_INIT) BswM_EcuMRunRequestStatePtrType;

/**   \brief  type used to point to BswM_EcuMStateSwitchParameters */
typedef P2CONST(BswM_EcuMStateSwitchParametersType, TYPEDEF, BSWM_CONST) BswM_EcuMStateSwitchParametersPtrType;

/**   \brief  type used to point to BswM_Expressions */
typedef P2CONST(BswM_ExpressionFuncType, TYPEDEF, BSWM_CONST) BswM_ExpressionsPtrType;

/**   \brief  type used to point to BswM_ForcedActionListPriority */
typedef P2VAR(BswM_ForcedActionListPriorityType, TYPEDEF, BSWM_VAR_NO_INIT) BswM_ForcedActionListPriorityPtrType;

/**   \brief  type used to point to BswM_GenericMapping */
typedef P2CONST(BswM_GenericMappingType, TYPEDEF, BSWM_CONST) BswM_GenericMappingPtrType;

/**   \brief  type used to point to BswM_GenericModeParameters */
typedef P2CONST(BswM_GenericModeParametersType, TYPEDEF, BSWM_CONST) BswM_GenericModeParametersPtrType;

/**   \brief  type used to point to BswM_GenericState */
typedef P2VAR(BswM_ModeType, TYPEDEF, BSWM_VAR_NO_INIT) BswM_GenericStatePtrType;

/**   \brief  type used to point to BswM_ImmediateUser */
typedef P2CONST(BswM_ImmediateUserType, TYPEDEF, BSWM_CONST) BswM_ImmediateUserPtrType;

/**   \brief  type used to point to BswM_InitActionLists */
typedef P2CONST(BswM_InitActionListsType, TYPEDEF, BSWM_CONST) BswM_InitActionListsPtrType;

/**   \brief  type used to point to BswM_InitGenVarAndInitAL */
typedef P2CONST(BswM_InitGenVarAndInitALType, TYPEDEF, BSWM_CONST) BswM_InitGenVarAndInitALPtrType;

/**   \brief  type used to point to BswM_InitValues */
typedef P2CONST(BswM_InitValuesType, TYPEDEF, BSWM_CONST) BswM_InitValuesPtrType;

/**   \brief  type used to point to BswM_Initialized */
typedef P2VAR(BswM_InitializedType, TYPEDEF, BSWM_VAR_NO_INIT) BswM_InitializedPtrType;

/**   \brief  type used to point to BswM_ModeNotificationFct */
typedef P2CONST(BswM_PartitionFunctionType, TYPEDEF, BSWM_CONST) BswM_ModeNotificationFctPtrType;

/**   \brief  type used to point to BswM_ModeRequestQueue */
typedef P2VAR(BswM_ModeRequestQueueType, TYPEDEF, BSWM_VAR_NO_INIT) BswM_ModeRequestQueuePtrType;

/**   \brief  type used to point to BswM_PartitionIdentifiers */
typedef P2CONST(BswM_PartitionIdentifiersType, TYPEDEF, BSWM_CONST) BswM_PartitionIdentifiersPtrType;

/**   \brief  type used to point to BswM_QueueSemaphore */
typedef P2VAR(BswM_QueueSemaphoreType, TYPEDEF, BSWM_VAR_NO_INIT) BswM_QueueSemaphorePtrType;

/**   \brief  type used to point to BswM_QueueWritten */
typedef P2VAR(BswM_QueueWrittenType, TYPEDEF, BSWM_VAR_NO_INIT) BswM_QueueWrittenPtrType;

/**   \brief  type used to point to BswM_RuleStates */
typedef P2VAR(BswM_RuleStatesType, TYPEDEF, BSWM_VAR_NO_INIT) BswM_RuleStatesPtrType;

/**   \brief  type used to point to BswM_Rules */
typedef P2CONST(BswM_RulesType, TYPEDEF, BSWM_CONST) BswM_RulesPtrType;

/**   \brief  type used to point to BswM_RulesInd */
typedef P2CONST(BswM_RulesIndType, TYPEDEF, BSWM_CONST) BswM_RulesIndPtrType;

/**   \brief  type used to point to BswM_SwcModeRequestUpdateFct */
typedef P2CONST(BswM_PartitionFunctionType, TYPEDEF, BSWM_CONST) BswM_SwcModeRequestUpdateFctPtrType;

/**   \brief  type used to point to BswM_TimerControlParameters */
typedef P2CONST(BswM_TimerControlParametersType, TYPEDEF, BSWM_CONST) BswM_TimerControlParametersPtrType;

/**   \brief  type used to point to BswM_TimerState */
typedef P2VAR(BswM_TimerStateType, TYPEDEF, BSWM_VAR_NO_INIT) BswM_TimerStatePtrType;

/**   \brief  type used to point to BswM_TimerValue */
typedef P2VAR(BswM_TimerValueType, TYPEDEF, BSWM_VAR_NO_INIT) BswM_TimerValuePtrType;

/** 
  \}
*/ 

/** 
  \defgroup  BswMPCPartitionRootPointer  BswM Partition Root Pointer (PRE_COMPILE)
  \brief  This type definitions are used for partition specific instance.
  \{
*/ 
/**   \brief  type used in BswM_PCPartitionConfig */
typedef struct sBswM_PCPartitionConfigType
{
  BswM_ActionItemsPtrType ActionItemsOfPCPartitionConfig;  /**< the pointer to BswM_ActionItems */
  BswM_ActionListsPtrType ActionListsOfPCPartitionConfig;  /**< the pointer to BswM_ActionLists */
  BswM_ActionsPtrType ActionsOfPCPartitionConfig;  /**< the pointer to BswM_Actions */
  BswM_CanSMChannelMappingPtrType CanSMChannelMappingOfPCPartitionConfig;  /**< the pointer to BswM_CanSMChannelMapping */
  BswM_ComDMHandlingDisableParametersPtrType ComDMHandlingDisableParametersOfPCPartitionConfig;  /**< the pointer to BswM_ComDMHandlingDisableParameters */
  BswM_ComDMHandlingEnableParametersPtrType ComDMHandlingEnableParametersOfPCPartitionConfig;  /**< the pointer to BswM_ComDMHandlingEnableParameters */
  BswM_ComMAllowComParametersPtrType ComMAllowComParametersOfPCPartitionConfig;  /**< the pointer to BswM_ComMAllowComParameters */
  BswM_ComMChannelMappingPtrType ComMChannelMappingOfPCPartitionConfig;  /**< the pointer to BswM_ComMChannelMapping */
  BswM_ComPduGroupHandlingStartParametersPtrType ComPduGroupHandlingStartParametersOfPCPartitionConfig;  /**< the pointer to BswM_ComPduGroupHandlingStartParameters */
  BswM_ComPduGroupHandlingStopParametersPtrType ComPduGroupHandlingStopParametersOfPCPartitionConfig;  /**< the pointer to BswM_ComPduGroupHandlingStopParameters */
  BswM_DcmComMappingPtrType DcmComMappingOfPCPartitionConfig;  /**< the pointer to BswM_DcmComMapping */
  BswM_DeferredRulesPtrType DeferredRulesOfPCPartitionConfig;  /**< the pointer to BswM_DeferredRules */
  BswM_ExpressionsPtrType ExpressionsOfPCPartitionConfig;  /**< the pointer to BswM_Expressions */
  BswM_InitActionListsPtrType InitActionListsOfPCPartitionConfig;  /**< the pointer to BswM_InitActionLists */
  BswM_RulesPtrType RulesOfPCPartitionConfig;  /**< the pointer to BswM_Rules */
  BswM_RulesIndPtrType RulesIndOfPCPartitionConfig;  /**< the pointer to BswM_RulesInd */
  BswM_TimerControlParametersPtrType TimerControlParametersOfPCPartitionConfig;  /**< the pointer to BswM_TimerControlParameters */
} BswM_PCPartitionConfigType;

/**   \brief  type used to point to BswM_PCPartitionConfig */
typedef P2CONST(BswM_PCPartitionConfigType, TYPEDEF, BSWM_CONST) BswM_PCPartitionConfigPtrType;

/** 
  \}
*/ 

/** 
  \defgroup  BswMPCRootValueTypes  BswM Root Value Types (PRE_COMPILE)
  \brief  These type definitions are used for value representations in root arrays.
  \{
*/ 
/**   \brief  type used in BswM_PCConfig */
typedef struct sBswM_PCConfigType
{
  BswM_PCPartitionConfigPtrType PCPartitionConfigOfPCConfig;  /**< the pointer to BswM_PCPartitionConfig */
} BswM_PCConfigType;

typedef BswM_PCConfigType BswM_ConfigType;  /**< A structure type is present for data in each configuration class. This typedef redefines the probably different name to the specified one. */

/**   \brief  type to access BswM_PCConfig in a symbol based style. */
typedef struct sBswM_PCConfigsType
{
  BswM_PCConfigType Config_Left;  /**< [Config_Left] */
  BswM_PCConfigType Config_Right;  /**< [Config_Right] */
} BswM_PCConfigsType;

/** 
  \}
*/ 


/* PRQA L:PRECOMPILEGLOBALDATATYPES */





/* PRQA S 0639, 0779 POSTBUILDGLOBALDATATYPES */ /* MD_MSR_1.1_639, MD_MSR_Rule5.2_0779 */
/**********************************************************************************************************************
  CONFIGURATION CLASS: POST_BUILD
  SECTION: SIZEOF DATA TYPES
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: POST_BUILD
  SECTION: GLOBAL SIMPLE DATA TYPES AND STRUCTURES
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: POST_BUILD
  SECTION: GLOBAL COMPLEX DATA TYPES AND STRUCTURES
**********************************************************************************************************************/

/* PRQA L:POSTBUILDGLOBALDATATYPES */

/**********************************************************************************************************************
  GLOBAL DATA PROTOTYPES
**********************************************************************************************************************/
/* PRQA S 3449, 3451 EXTERNDECLARATIONS */ /* MD_BSWM_3449, MD_BSWM_3451 */
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


/* PRQA L:EXTERNDECLARATIONS */



/**********************************************************************************************************************
 *  GLOBAL DATA
**********************************************************************************************************************/
/**********************************************************************************************************************
  BswM_OsApplicationToBswM
**********************************************************************************************************************/


#define BSWM_START_SEC_VAR_NO_INIT_UNSPECIFIED
/* PRQA S 5087 1 */ /* MD_MSR_MemMap */
#include "BswM_MemMap.h"

extern VAR(Rte_ModeType_ESH_Mode, BSWM_VAR_NO_INIT) BswM_Switch_ESH_ModeSwitch_BswM_MDGP_ESH_Mode;
extern VAR(Rte_ModeType_CommunicationMode, BSWM_VAR_NO_INIT) BswM_Switch_BswMSwitchPort_SwcDiagCommunicationMode_Mode;
extern VAR(BswM_ESH_RunRequest, BSWM_VAR_NO_INIT) Request_ESH_RunRequest_0_requestedMode;
extern VAR(BswM_ESH_RunRequest, BSWM_VAR_NO_INIT) Request_ESH_RunRequest_1_requestedMode;
extern VAR(BswM_ESH_RunRequest, BSWM_VAR_NO_INIT) Request_ESH_PostRunRequest_0_requestedMode;
extern VAR(BswM_ESH_RunRequest, BSWM_VAR_NO_INIT) Request_ESH_PostRunRequest_1_requestedMode;
extern VAR(BswM_ESH_KillAllRun, BSWM_VAR_NO_INIT) Request_ESH_KillAllRunRequest_requestedMode;
extern VAR(Rte_ModeType_ESH_Mode, BSWM_VAR_NO_INIT) BswM_Mode_Notification_ESH_ModeNotification_BswM_MDGP_ESH_Mode;


extern VAR(boolean, BSWM_VAR_NO_INIT) BswM_PreInitialized;
#define BSWM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/* PRQA S 5087 1 */ /* MD_MSR_MemMap */
#include "BswM_MemMap.h"


/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
**********************************************************************************************************************/
#define BSWM_START_SEC_CODE
/* PRQA S 5087 1 */ /* MD_MSR_MemMap */
#include "BswM_MemMap.h"

/* -----------------------------------------------------------------------------
&&&~ USER CALLOUT DECLARATIONS
----------------------------------------------------------------------------- */
/* PRQA S 0777 CALLOUTDECLARATIONS */ /* MD_MSR_Rule5.2_0779 */
extern FUNC(void, BSWM_CODE) BswM_AL_SetProgrammableInterrupts(void);
extern FUNC(void, BSWM_CODE) BswM_ESH_OnEnterPostRun(void);
extern FUNC(void, BSWM_CODE) BswM_ESH_OnEnterPrepShutdown(void);
extern FUNC(void, BSWM_CODE) BswM_ESH_OnEnterRun(void);
extern FUNC(void, BSWM_CODE) BswM_ESH_OnEnterShutdown(void);
extern FUNC(void, BSWM_CODE) BswM_ESH_OnEnterWaitForNvm(void);
extern FUNC(void, BSWM_CODE) BswM_ESH_OnEnterWakeup(void);
extern FUNC(void, BSWM_CODE) BswM_INIT_NvMReadAll(void);
extern FUNC(void, BSWM_CODE) ESH_ComM_CheckPendingRequests_Left(void);
extern FUNC(void, BSWM_CODE) ESH_Dem_PostRunRequested_Left(void);
extern FUNC(void, BSWM_CODE) Rtm_CpuLoadMeasurementStart(void);
extern FUNC(void, BSWM_CODE) ESH_ComM_CheckPendingRequests_Right(void);
extern FUNC(void, BSWM_CODE) ESH_Dem_PostRunRequested_Right(void);
/* PRQA L:CALLOUTDECLARATIONS */

/* -----------------------------------------------------------------------------
&&&~ USER CALLOUT DECLARATIONS
----------------------------------------------------------------------------- */
#define BSWM_STOP_SEC_CODE
/* PRQA S 5087 1 */ /* MD_MSR_MemMap */
#include "BswM_MemMap.h"

#endif /* BSWM_CFG_H */

