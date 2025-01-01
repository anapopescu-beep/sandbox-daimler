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
 *            Module: CanNm
 *           Program: MSR_Daimler_SLP11
 *          Customer: Mercedes-Benz AG
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: TC3xx
 *    License Scope : The usage is restricted to CBD2200333_D05
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: CanNm_Cfg.h
 *   Generation Time: 2023-07-10 14:36:08
 *           Project: StartApplication - Version 1.0
 *          Delivery: CBD2200333_D05
 *      Tool Version: DaVinci Configurator Classic 5.25.50 SP5
 *
 *
 *********************************************************************************************************************/


#if !defined (CANNM_CFG_H)
# define CANNM_CFG_H

/**********************************************************************************************************************
 * MISRA JUSTIFICATION
 *********************************************************************************************************************/
/* PRQA S 0779 EOF */ /* MD_MSR_Rule5.2_0779 */

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "ComStack_Types.h"
#include "NmStack_Types.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

#define CANNM_NUMBER_OF_CANNM_CHANNELS        1u
/* Symbolic name defines for CanNmTxPdus */



/**
 * \defgroup CanNmHandleIds Handle IDs.
 * \{
 */

/* Handle IDs active in a single predefined variant */
/*      Symbolic Name                                                 Value   Active in predefined variant(s) */
#define CanNmConf_CanNmTxPdu_NM_RBTM_FL_ST3_b7c99fb7_Tx               0       /**< [Left] */
#define CanNmConf_CanNmTxPdu_NM_RBTM_FR_ST3_6c247ca6_Tx               0       /**< [Right] */
/**\} */

/* Symbolic name defines for CanNmTxUserDataPdus */



/**
 * \defgroup CanNmHandleIds Handle IDs.
 * \{
 */

/* Handle IDs active in a single predefined variant */
/*      Symbolic Name                                                 Value   Active in predefined variant(s) */
#define CanNmConf_CanNmUserDataTxPdu_NM_RBTM_FL_ST3_e414ee7b          0       /**< [Left] */
#define CanNmConf_CanNmUserDataTxPdu_NM_RBTM_FR_ST3_f94fffa8          0       /**< [Right] */
/**\} */

/* Symbolic name defines for CanNmRxPdus */



/**
 * \defgroup CanNmHandleIds Handle IDs.
 * \{
 */

/* Handle IDs active in all predefined variants (the application has not to take the active variant into account) */
/*      Symbolic Name                                                 Value   Active in predefined variant(s) */
#define CanNmConf_CanNmRxPdu_BODY3_8b033453_Rx                        0       /**< [Left, Right] */
/**\} */

/* Options */
#define CANNM_BUS_LOAD_REDUCTION_ENABLED                STD_OFF
#define CANNM_IMMEDIATE_TXCONF_ENABLED                  STD_OFF
#define CANNM_USER_DATA_ENABLED                         STD_OFF
#define CANNM_PASSIVE_MODE_ENABLED                      STD_OFF
#define CANNM_VERSION_INFO_API                          STD_OFF
#define CANNM_DISABLE_TX_ERR_REPORT                     STD_OFF
#define CANNM_PDU_RX_INDICATION_ENABLED                 STD_OFF
#define CANNM_STATE_CHANGE_IND_ENABLED                  STD_ON
#define CANNM_REMOTE_SLEEP_IND_ENABLED                  STD_ON
#define CANNM_BUS_SYNCHRONIZATION_ENABLED               STD_OFF
#define CANNM_COM_USER_DATA_SUPPORT                     STD_ON
#define CANNM_COORDINATOR_SYNC_SUPPORT                  STD_OFF
#define CANNM_RUNTIME_MEASUREMENT_SUPPORT               STD_ON
#define CANNM_RUNTIME_ERROR_REPORT                      STD_ON
#define CANNM_PDUR_CANNM_TXCONFIRMATION                 STD_ON
#define CANNM_CAR_WUP_RX_FEATURE_ENABLED                STD_OFF
#define CANNM_CAR_WUP_FILTER_FEATURE_ENABLED            STD_OFF
#define CANNM_IMMEDIATE_NM_TX_FEATURE_ENABLED           STD_ON
#define CANNM_ACTIVE_WUP_BIT_FEATURE_ENABLED            STD_ON
#define CANNM_PN_FEATURE_ENABLED                        STD_ON
#define CANNM_PN_ERA_CALC_FEATURE_ENABLED               STD_OFF
#define CANNM_PN_EIRA_CALC_FEATURE_ENABLED              STD_ON
#define CANNM_PN_TX_TIMEOUT_EXCEPTION_FEATURE_ENABLED   STD_OFF
#define CANNM_BUSNM_SPECIFIC_PDU_RX_INDICATION_ENABLED  STD_OFF
#define CANNM_ALLOW_TRIGGERED_MSG_TRANSMISSION          STD_ON

#define CANNM_SYNC_SHUTDOWN_FEATURE_TX_ENABLED          STD_OFF
#define CANNM_SYNC_SHUTDOWN_FEATURE_RX_ENABLED          STD_OFF
#define CANNM_PNSR_MSG_TIMEOUT_TICK_EQ_ONE              STD_OFF
#define CANNM_PNC_ID_COUNTING_START_FROM_PNC_VECTOR     STD_OFF
/* Integration */

#define CANNM_OPTIMIZE_CHANNEL_ENABLED

#define CANNM_EXPECTED_GENERATOR_COMPATIBILITY_VERSION  0x1200u


/* Invalid Channel Handle */
#define CANNM_INVALID_CHANNEL  0xFFu

/* Pdu CBV / NID Position Defines */
#define CANNM_PDU_OFF          0xFFu
#define CANNM_PDU_BYTE_0       0x00u
#define CANNM_PDU_BYTE_1       0x01u

/* PN Calculation */
#if ( CANNM_PN_EIRA_CALC_FEATURE_ENABLED == STD_ON ) || ( CANNM_PN_ERA_CALC_FEATURE_ENABLED == STD_ON )
# define CANNM_PN_CALC_FEATURE_ENABLED
#endif

#if defined (CANNM_ISDEF_PNEIRACALCENABLED)
#else
# define CANNM_ISDEF_PNEIRACALCENABLED                     STD_ON
#endif

#if defined (CANNM_ISDEF_PNINFOLENGTH)
#else
# define CANNM_ISDEF_PNINFOLENGTH                          STD_ON
#endif

/**********************************************************************************************************************
    General Defines
**********************************************************************************************************************/
#ifndef CANNM_DEV_ERROR_DETECT
#define CANNM_DEV_ERROR_DETECT STD_ON
#endif
#ifndef CANNM_DEV_ERROR_REPORT
#define CANNM_DEV_ERROR_REPORT STD_OFF
#endif
#ifndef CANNM_USE_DUMMY_STATEMENT
#define CANNM_USE_DUMMY_STATEMENT STD_OFF /* /MICROSAR/vSet/vSetGeneral/vSetDummyStatementKind */
#endif
#ifndef CANNM_DUMMY_STATEMENT
#define CANNM_DUMMY_STATEMENT(v)  /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */  /* /MICROSAR/vSet/vSetGeneral/vSetDummyStatementKind */
#endif
#ifndef CANNM_DUMMY_STATEMENT_CONST
#define CANNM_DUMMY_STATEMENT_CONST(v)  /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */  /* /MICROSAR/vSet/vSetGeneral/vSetDummyStatementKind */
#endif
#ifndef CANNM_ATOMIC_BIT_ACCESS_IN_BITFIELD
#define CANNM_ATOMIC_BIT_ACCESS_IN_BITFIELD STD_OFF /* /MICROSAR/EcuC/EcucGeneral/AtomicBitAccessInBitfield */
#endif
#ifndef CANNM_ATOMIC_VARIABLE_ACCESS
#define CANNM_ATOMIC_VARIABLE_ACCESS 32u /* /MICROSAR/EcuC/EcucGeneral/AtomicVariableAccess */
#endif
#ifndef CANNM_PROCESSOR_TC322L
#define CANNM_PROCESSOR_TC322L
#endif
#ifndef CANNM_COMP_TASKING
#define CANNM_COMP_TASKING
#endif
#ifndef CANNM_GEN_GENERATOR_MSR
#define CANNM_GEN_GENERATOR_MSR
#endif
#ifndef CANNM_CPUTYPE_BITORDER_LSB2MSB
#define CANNM_CPUTYPE_BITORDER_LSB2MSB /* /MICROSAR/vSet/vSetPlatform/vSetBitOrder */
#endif
#ifndef CANNM_CONFIGURATION_VARIANT_PRECOMPILE
#define CANNM_CONFIGURATION_VARIANT_PRECOMPILE 1
#endif
#ifndef CANNM_CONFIGURATION_VARIANT_LINKTIME
#define CANNM_CONFIGURATION_VARIANT_LINKTIME 2
#endif
#ifndef CANNM_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE
#define CANNM_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE 3
#endif
#ifndef CANNM_CONFIGURATION_VARIANT
#define CANNM_CONFIGURATION_VARIANT CANNM_CONFIGURATION_VARIANT_PRECOMPILE
#endif
#ifndef CANNM_POSTBUILD_VARIANT_SUPPORT
#define CANNM_POSTBUILD_VARIANT_SUPPORT STD_ON
#endif
 

/**********************************************************************************************************************
  GLOBAL CONSTANT MACROS
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL CONSTANT MACROS
**********************************************************************************************************************/
/** 
  \defgroup  CanNmPCDataSwitches  CanNm Data Switches  (PRE_COMPILE)
  \brief  These defines are used to deactivate data and their processing.
  \{
*/ 
#define CANNM_CHANNELCONFIG                                           STD_ON
#define CANNM_ACTIVEPNCCOORDINATORCHANNELOFCHANNELCONFIG              STD_OFF  /**< Deactivateable: 'CanNm_ChannelConfigLeft.ActivePncCoordinatorChannel' Reason: 'Request Synchronization Pnc Shutdown is disabled.' and Deactivateable: 'CanNm_ChannelConfigRight.ActivePncCoordinatorChannel' Reason: 'Request Synchronization Pnc Shutdown is disabled.' */
#define CANNM_ACTIVEWAKEUPBITENABLEDOFCHANNELCONFIG                   STD_ON
#define CANNM_ALLMESSAGESKEEPAWAKEOFCHANNELCONFIG                     STD_ON
#define CANNM_BUSLOADREDUCTIONACTIVEOFCHANNELCONFIG                   STD_OFF  /**< Deactivateable: 'CanNm_ChannelConfigLeft.BusLoadReductionActive' Reason: 'BusLoadReduction is disabled' and Deactivateable: 'CanNm_ChannelConfigRight.BusLoadReductionActive' Reason: 'BusLoadReduction is disabled' */
#define CANNM_CARWAKEUPBITMASKOFCHANNELCONFIG                         STD_OFF  /**< Deactivateable: 'CanNm_ChannelConfigLeft.CarWakeUpBitMask' Reason: 'CarWupRx is disabled' and Deactivateable: 'CanNm_ChannelConfigRight.CarWakeUpBitMask' Reason: 'CarWupRx is disabled' */
#define CANNM_CARWAKEUPBYTEPOSITIONOFCHANNELCONFIG                    STD_OFF  /**< Deactivateable: 'CanNm_ChannelConfigLeft.CarWakeUpBytePosition' Reason: 'CarWupRx is disabled' and Deactivateable: 'CanNm_ChannelConfigRight.CarWakeUpBytePosition' Reason: 'CarWupRx is disabled' */
#define CANNM_CARWAKEUPFILTERENABLEDOFCHANNELCONFIG                   STD_OFF  /**< Deactivateable: 'CanNm_ChannelConfigLeft.CarWakeUpFilterEnabled' Reason: 'CarWupFilterFeature is disabled' and Deactivateable: 'CanNm_ChannelConfigRight.CarWakeUpFilterEnabled' Reason: 'CarWupFilterFeature is disabled' */
#define CANNM_CARWAKEUPFILTERNODEIDOFCHANNELCONFIG                    STD_OFF  /**< Deactivateable: 'CanNm_ChannelConfigLeft.CarWakeUpFilterNodeId' Reason: 'CarWupFilterFeature is disabled' and Deactivateable: 'CanNm_ChannelConfigRight.CarWakeUpFilterNodeId' Reason: 'CarWupFilterFeature is disabled' */
#define CANNM_CARWAKEUPRXENABLEDOFCHANNELCONFIG                       STD_OFF  /**< Deactivateable: 'CanNm_ChannelConfigLeft.CarWakeUpRxEnabled' Reason: 'CarWupRx is disabled' and Deactivateable: 'CanNm_ChannelConfigRight.CarWakeUpRxEnabled' Reason: 'CarWupRx is disabled' */
#define CANNM_CHANNELIDOFCHANNELCONFIG                                STD_ON
#define CANNM_COMCONTROLENABLEDOFCHANNELCONFIG                        STD_ON
#define CANNM_CRIBITALWAYSENABLEDOFCHANNELCONFIG                      STD_OFF  /**< Deactivateable: 'CanNm_ChannelConfigLeft.CriBitAlwaysEnabled' Reason: 'the value of CanNm_CriBitAlwaysEnabledOfChannelConfig is always 'false' due to this, the array is deactivated.' and Deactivateable: 'CanNm_ChannelConfigRight.CriBitAlwaysEnabled' Reason: 'the value of CanNm_CriBitAlwaysEnabledOfChannelConfig is always 'false' due to this, the array is deactivated.' */
#define CANNM_ERRORWAITBUSSLEEPTIMEOFCHANNELCONFIG                    STD_OFF  /**< Deactivateable: 'CanNm_ChannelConfigLeft.ErrorWaitBusSleepTime' Reason: 'the value of CanNm_ErrorWaitBusSleepTimeOfChannelConfig is always '0' due to this, the array is deactivated.' and Deactivateable: 'CanNm_ChannelConfigRight.ErrorWaitBusSleepTime' Reason: 'the value of CanNm_ErrorWaitBusSleepTimeOfChannelConfig is always '0' due to this, the array is deactivated.' */
#define CANNM_IMMEDIATENMCYCLETIMEOFCHANNELCONFIG                     STD_ON
#define CANNM_IMMEDIATENMTRANSMISSIONSOFCHANNELCONFIG                 STD_ON
#define CANNM_IMMEDIATERESTARTENABLEDOFCHANNELCONFIG                  STD_OFF  /**< Deactivateable: 'CanNm_ChannelConfigLeft.ImmediateRestartEnabled' Reason: 'Immediate Restart is disabled' and Deactivateable: 'CanNm_ChannelConfigRight.ImmediateRestartEnabled' Reason: 'Immediate Restart is disabled' */
#define CANNM_MSGCYCLETIMEOFCHANNELCONFIG                             STD_ON
#define CANNM_MSGTIMEOUTTIMEOFCHANNELCONFIG                           STD_ON
#define CANNM_NODEDETECTIONENABLEDOFCHANNELCONFIG                     STD_OFF  /**< Deactivateable: 'CanNm_ChannelConfigLeft.NodeDetectionEnabled' Reason: 'Node Detection is disabled' and Deactivateable: 'CanNm_ChannelConfigRight.NodeDetectionEnabled' Reason: 'Node Detection is disabled' */
#define CANNM_NODEIDENABLEDOFCHANNELCONFIG                            STD_OFF  /**< Deactivateable: 'CanNm_ChannelConfigLeft.NodeIdEnabled' Reason: 'Node Id is disabled' and Deactivateable: 'CanNm_ChannelConfigRight.NodeIdEnabled' Reason: 'Node Id is disabled' */
#define CANNM_PDUCBVPOSITIONOFCHANNELCONFIG                           STD_ON
#define CANNM_PDUNIDPOSITIONOFCHANNELCONFIG                           STD_OFF  /**< Deactivateable: 'CanNm_ChannelConfigLeft.PduNidPosition' Reason: '' and Deactivateable: 'CanNm_ChannelConfigRight.PduNidPosition' Reason: '' */
#define CANNM_PNCALLTXTIMEOUTEXCEPTIONOFCHANNELCONFIG                 STD_OFF  /**< Deactivateable: 'CanNm_ChannelConfigLeft.PnCallTxTimeoutException' Reason: 'PnTxTimeout Feature is disabled' and Deactivateable: 'CanNm_ChannelConfigRight.PnCallTxTimeoutException' Reason: 'PnTxTimeout Feature is disabled' */
#define CANNM_PNERACALCENABLEDOFCHANNELCONFIG                         STD_OFF  /**< Deactivateable: 'CanNm_ChannelConfigLeft.PnEraCalcEnabled' Reason: 'EraCalcFeature is disabled' and Deactivateable: 'CanNm_ChannelConfigRight.PnEraCalcEnabled' Reason: 'EraCalcFeature is disabled' */
#define CANNM_PNERARXPDUIDOFCHANNELCONFIG                             STD_OFF  /**< Deactivateable: 'CanNm_ChannelConfigLeft.PnEraRxPduId' Reason: 'EraCalcFeature is disabled' and Deactivateable: 'CanNm_ChannelConfigRight.PnEraRxPduId' Reason: 'EraCalcFeature is disabled' */
#define CANNM_PNHANDLEMULTIPLENETWORKREQUESTOFCHANNELCONFIG           STD_ON
#define CANNM_REMOTESLEEPINDTIMEOFCHANNELCONFIG                       STD_ON
#define CANNM_REPEATMESSAGETIMEOFCHANNELCONFIG                        STD_ON
#define CANNM_REPEATMSGINDENABLEDOFCHANNELCONFIG                      STD_OFF  /**< Deactivateable: 'CanNm_ChannelConfigLeft.RepeatMsgIndEnabled' Reason: 'the value of CanNm_RepeatMsgIndEnabledOfChannelConfig is always 'false' due to this, the array is deactivated.' and Deactivateable: 'CanNm_ChannelConfigRight.RepeatMsgIndEnabled' Reason: 'the value of CanNm_RepeatMsgIndEnabledOfChannelConfig is always 'false' due to this, the array is deactivated.' */
#define CANNM_RETRYFIRSTMESSAGEREQUESTOFCHANNELCONFIG                 STD_OFF  /**< Deactivateable: 'CanNm_ChannelConfigLeft.RetryFirstMessageRequest' Reason: 'Retry First Message Request is disabled' and Deactivateable: 'CanNm_ChannelConfigRight.RetryFirstMessageRequest' Reason: 'Retry First Message Request is disabled' */
#define CANNM_SYNCHRONIZEDPNCSHUTDOWNENABLEDOFCHANNELCONFIG           STD_OFF  /**< Deactivateable: 'CanNm_ChannelConfigLeft.SynchronizedPncShutdownEnabled' Reason: 'Request Synchronization Pnc Shutdown is disabled.' and Deactivateable: 'CanNm_ChannelConfigRight.SynchronizedPncShutdownEnabled' Reason: 'Request Synchronization Pnc Shutdown is disabled.' */
#define CANNM_TIMEOUTTIMEOFCHANNELCONFIG                              STD_ON
#define CANNM_WAITBUSSLEEPTIMEOFCHANNELCONFIG                         STD_ON
#define CANNM_COMMSTATE                                               STD_ON
#define CANNM_COORDREADYTOSLEEPSTATE                                  STD_ON
#define CANNM_FINALMAGICNUMBER                                        STD_OFF  /**< Deactivateable: 'CanNm_FinalMagicNumber' Reason: 'the module configuration does not support flashing of data.' */
#define CANNM_GENERATORCOMPATIBILITYVERSION                           STD_OFF  /**< Deactivateable: 'CanNm_GeneratorCompatibilityVersion' Reason: 'Variant is not VARIANT-POST-BUILD-LOADABLE' */
#define CANNM_IMMEDIATENMMSGCOUNT                                     STD_ON
#define CANNM_IMMEDIATERESTARTFAILED                                  STD_OFF  /**< Deactivateable: 'CanNm_ImmediateRestartFailedLeft' Reason: 'Immediate Restart is disabled' and Deactivateable: 'CanNm_ImmediateRestartFailedRight' Reason: 'Immediate Restart is disabled' */
#define CANNM_INITDATAHASHCODE                                        STD_OFF  /**< Deactivateable: 'CanNm_InitDataHashCode' Reason: 'the module configuration does not support flashing of data.' */
#define CANNM_MODULEINITIALIZED                                       STD_ON
#define CANNM_MSGCONFIRMATIONFLAG                                     STD_ON
#define CANNM_MSGINDICATIONFLAG                                       STD_ON
#define CANNM_MSGREQUEST                                              STD_ON
#define CANNM_MSGTIMEOUTTIMER                                         STD_ON
#define CANNM_MSGTIMER                                                STD_ON
#define CANNM_NETWORKRESTARTFLAG                                      STD_ON
#define CANNM_NMSTATE                                                 STD_ON
#define CANNM_PBCHANNELCONFIG                                         STD_ON
#define CANNM_ALLOWTRIGGEREDMSGTRANSMISSIONOFPBCHANNELCONFIG          STD_OFF  /**< Deactivateable: 'CanNm_PbChannelConfig.AllowTriggeredMsgTransmission' Reason: 'the value of CanNm_AllowTriggeredMsgTransmissionOfPbChannelConfig is always 'false' due to this, the array is deactivated.' and Deactivateable: 'CanNm_PbChannelConfig.AllowTriggeredMsgTransmission' Reason: 'the value of CanNm_AllowTriggeredMsgTransmissionOfPbChannelConfig is always 'false' due to this, the array is deactivated.' */
#define CANNM_MSGCYCLEOFFSETOFPBCHANNELCONFIG                         STD_ON
#define CANNM_MSGREDUCEDTIMEOFPBCHANNELCONFIG                         STD_OFF  /**< Deactivateable: 'CanNm_PbChannelConfig.MsgReducedTime' Reason: 'BusLoadReduction is disabled' and Deactivateable: 'CanNm_PbChannelConfig.MsgReducedTime' Reason: 'BusLoadReduction is disabled' */
#define CANNM_NODEIDOFPBCHANNELCONFIG                                 STD_OFF  /**< Deactivateable: 'CanNm_PbChannelConfig.NodeId' Reason: 'Node Id is disabled' and Deactivateable: 'CanNm_PbChannelConfig.NodeId' Reason: 'Node Id is disabled' */
#define CANNM_PNENABLEDOFPBCHANNELCONFIG                              STD_ON
#define CANNM_RXMESSAGEDATAENDIDXOFPBCHANNELCONFIG                    STD_OFF  /**< Deactivateable: 'CanNm_PbChannelConfig.RxMessageDataEndIdx' Reason: 'RxMessageDataBuffer is disabled' and Deactivateable: 'CanNm_PbChannelConfig.RxMessageDataEndIdx' Reason: 'RxMessageDataBuffer is disabled' */
#define CANNM_RXMESSAGEDATALENGTHOFPBCHANNELCONFIG                    STD_OFF  /**< Deactivateable: 'CanNm_PbChannelConfig.RxMessageDataLength' Reason: 'RxMessageDataBuffer is disabled' and Deactivateable: 'CanNm_PbChannelConfig.RxMessageDataLength' Reason: 'RxMessageDataBuffer is disabled' */
#define CANNM_RXMESSAGEDATASTARTIDXOFPBCHANNELCONFIG                  STD_OFF  /**< Deactivateable: 'CanNm_PbChannelConfig.RxMessageDataStartIdx' Reason: 'RxMessageDataBuffer is disabled' and Deactivateable: 'CanNm_PbChannelConfig.RxMessageDataStartIdx' Reason: 'RxMessageDataBuffer is disabled' */
#define CANNM_RXMESSAGEDATAUSEDOFPBCHANNELCONFIG                      STD_OFF  /**< Deactivateable: 'CanNm_PbChannelConfig.RxMessageDataUsed' Reason: 'RxMessageDataBuffer is disabled' and Deactivateable: 'CanNm_PbChannelConfig.RxMessageDataUsed' Reason: 'RxMessageDataBuffer is disabled' */
#define CANNM_RXMESSAGEDATA_CBVIDXOFPBCHANNELCONFIG                   STD_OFF  /**< Deactivateable: 'CanNm_PbChannelConfig.RxMessageData_CBVIdx' Reason: 'RxMessageDataBuffer is disabled' and Deactivateable: 'CanNm_PbChannelConfig.RxMessageData_CBVIdx' Reason: 'RxMessageDataBuffer is disabled' */
#define CANNM_RXMESSAGEDATA_CBVUSEDOFPBCHANNELCONFIG                  STD_OFF  /**< Deactivateable: 'CanNm_PbChannelConfig.RxMessageData_CBVUsed' Reason: 'RxMessageDataBuffer is disabled' and Deactivateable: 'CanNm_PbChannelConfig.RxMessageData_CBVUsed' Reason: 'RxMessageDataBuffer is disabled' */
#define CANNM_RXMESSAGEDATA_CARWAKEUPBYTEIDXOFPBCHANNELCONFIG         STD_OFF  /**< Deactivateable: 'CanNm_PbChannelConfig.RxMessageData_CarWakeUpByteIdx' Reason: 'RxMessageDataBuffer is disabled' and Deactivateable: 'CanNm_PbChannelConfig.RxMessageData_CarWakeUpByteIdx' Reason: 'RxMessageDataBuffer is disabled' */
#define CANNM_RXMESSAGEDATA_CARWAKEUPBYTEUSEDOFPBCHANNELCONFIG        STD_OFF  /**< Deactivateable: 'CanNm_PbChannelConfig.RxMessageData_CarWakeUpByteUsed' Reason: 'RxMessageDataBuffer is disabled' and Deactivateable: 'CanNm_PbChannelConfig.RxMessageData_CarWakeUpByteUsed' Reason: 'RxMessageDataBuffer is disabled' */
#define CANNM_RXMESSAGEDATA_NIDIDXOFPBCHANNELCONFIG                   STD_OFF  /**< Deactivateable: 'CanNm_PbChannelConfig.RxMessageData_NIDIdx' Reason: 'RxMessageDataBuffer is disabled' and Deactivateable: 'CanNm_PbChannelConfig.RxMessageData_NIDIdx' Reason: 'RxMessageDataBuffer is disabled' */
#define CANNM_RXMESSAGEDATA_NIDUSEDOFPBCHANNELCONFIG                  STD_OFF  /**< Deactivateable: 'CanNm_PbChannelConfig.RxMessageData_NIDUsed' Reason: 'RxMessageDataBuffer is disabled' and Deactivateable: 'CanNm_PbChannelConfig.RxMessageData_NIDUsed' Reason: 'RxMessageDataBuffer is disabled' */
#define CANNM_RXMESSAGEDATA_USERDATAENDIDXOFPBCHANNELCONFIG           STD_OFF  /**< Deactivateable: 'CanNm_PbChannelConfig.RxMessageData_UserDataEndIdx' Reason: 'RxMessageDataBuffer is disabled' and Deactivateable: 'CanNm_PbChannelConfig.RxMessageData_UserDataEndIdx' Reason: 'RxMessageDataBuffer is disabled' */
#define CANNM_RXMESSAGEDATA_USERDATALENGTHOFPBCHANNELCONFIG           STD_OFF  /**< Deactivateable: 'CanNm_PbChannelConfig.RxMessageData_UserDataLength' Reason: 'RxMessageDataBuffer is disabled' and Deactivateable: 'CanNm_PbChannelConfig.RxMessageData_UserDataLength' Reason: 'RxMessageDataBuffer is disabled' */
#define CANNM_RXMESSAGEDATA_USERDATASTARTIDXOFPBCHANNELCONFIG         STD_OFF  /**< Deactivateable: 'CanNm_PbChannelConfig.RxMessageData_UserDataStartIdx' Reason: 'RxMessageDataBuffer is disabled' and Deactivateable: 'CanNm_PbChannelConfig.RxMessageData_UserDataStartIdx' Reason: 'RxMessageDataBuffer is disabled' */
#define CANNM_RXMESSAGEDATA_USERDATAUSEDOFPBCHANNELCONFIG             STD_OFF  /**< Deactivateable: 'CanNm_PbChannelConfig.RxMessageData_UserDataUsed' Reason: 'RxMessageDataBuffer is disabled' and Deactivateable: 'CanNm_PbChannelConfig.RxMessageData_UserDataUsed' Reason: 'RxMessageDataBuffer is disabled' */
#define CANNM_TXMESSAGEDATAENDIDXOFPBCHANNELCONFIG                    STD_ON
#define CANNM_TXMESSAGEDATALENGTHOFPBCHANNELCONFIG                    STD_ON
#define CANNM_TXMESSAGEDATASTARTIDXOFPBCHANNELCONFIG                  STD_ON
#define CANNM_TXMESSAGEDATAUSEDOFPBCHANNELCONFIG                      STD_ON
#define CANNM_TXMESSAGEDATA_CBVIDXOFPBCHANNELCONFIG                   STD_ON
#define CANNM_TXMESSAGEDATA_CBVUSEDOFPBCHANNELCONFIG                  STD_ON
#define CANNM_TXMESSAGEDATA_NIDIDXOFPBCHANNELCONFIG                   STD_OFF  /**< Deactivateable: 'CanNm_PbChannelConfig.TxMessageData_NIDIdx' Reason: 'the optional indirection is deactivated because TxMessageData_NIDUsedOfPbChannelConfig is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' and Deactivateable: 'CanNm_PbChannelConfig.TxMessageData_NIDIdx' Reason: 'the optional indirection is deactivated because TxMessageData_NIDUsedOfPbChannelConfig is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CANNM_TXMESSAGEDATA_NIDUSEDOFPBCHANNELCONFIG                  STD_OFF  /**< Deactivateable: 'CanNm_PbChannelConfig.TxMessageData_NIDUsed' Reason: 'the optional indirection is deactivated because TxMessageData_NIDUsedOfPbChannelConfig is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' and Deactivateable: 'CanNm_PbChannelConfig.TxMessageData_NIDUsed' Reason: 'the optional indirection is deactivated because TxMessageData_NIDUsedOfPbChannelConfig is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CANNM_TXMESSAGEDATA_PNFILTERMASKENDIDXOFPBCHANNELCONFIG       STD_ON
#define CANNM_TXMESSAGEDATA_PNFILTERMASKSTARTIDXOFPBCHANNELCONFIG     STD_ON
#define CANNM_TXMESSAGEDATA_PNFILTERMASKUSEDOFPBCHANNELCONFIG         STD_ON
#define CANNM_TXMESSAGEDATA_USERDATAENDIDXOFPBCHANNELCONFIG           STD_ON
#define CANNM_TXMESSAGEDATA_USERDATALENGTHOFPBCHANNELCONFIG           STD_ON
#define CANNM_TXMESSAGEDATA_USERDATASTARTIDXOFPBCHANNELCONFIG         STD_ON
#define CANNM_TXMESSAGEDATA_USERDATAUSEDOFPBCHANNELCONFIG             STD_ON
#define CANNM_TXPDUIDOFPBCHANNELCONFIG                                STD_ON
#define CANNM_TXUSERDATAPDUIDOFPBCHANNELCONFIG                        STD_ON
#define CANNM_PBPNCCLUSTERCONFIGEXT                                   STD_OFF  /**< Deactivateable: 'CanNm_PbPncClusterConfigExtLeft' Reason: 'EraCalcFeature is disabled' and Deactivateable: 'CanNm_PbPncClusterConfigExtRight' Reason: 'EraCalcFeature is disabled' */
#define CANNM_PDUIDTOCHINDEX                                          STD_OFF  /**< Deactivateable: 'CanNm_PduIdToChIndexLeft' Reason: 'PB-S is not active or channel reference is invariant over all channels' and Deactivateable: 'CanNm_PduIdToChIndexRight' Reason: 'PB-S is not active or channel reference is invariant over all channels' */
#define CANNM_PNCLUSTERREQ                                            STD_ON
#define CANNM_PNCLUSTERREQEXT                                         STD_OFF  /**< Deactivateable: 'CanNm_PnClusterReqExtLeft' Reason: 'EraCalcFeature is disabled' and Deactivateable: 'CanNm_PnClusterReqExtRight' Reason: 'EraCalcFeature is disabled' */
#define CANNM_PNCLUSTERREQEXTNEW                                      STD_OFF  /**< Deactivateable: 'CanNm_PnClusterReqExtNewLeft' Reason: 'EraCalcFeature is disabled' and Deactivateable: 'CanNm_PnClusterReqExtNewRight' Reason: 'EraCalcFeature is disabled' */
#define CANNM_PNCLUSTERREQNEW                                         STD_ON
#define CANNM_PNCLUSTERRESETTIMER                                     STD_ON
#define CANNM_PNCLUSTERRESETTIMEREXT                                  STD_OFF  /**< Deactivateable: 'CanNm_PnClusterResetTimerExtLeft' Reason: 'EraCalcFeature is disabled' and Deactivateable: 'CanNm_PnClusterResetTimerExtRight' Reason: 'EraCalcFeature is disabled' */
#define CANNM_PNEIRACALCENABLED                                       STD_ON
#define CANNM_PNEIRARXPDUID                                           STD_ON
#define CANNM_PNINFOBYTECONFIG                                        STD_ON
#define CANNM_PNCLUSTERRESETTIMERENDIDXOFPNINFOBYTECONFIG             STD_ON
#define CANNM_PNCLUSTERRESETTIMERSTARTIDXOFPNINFOBYTECONFIG           STD_ON
#define CANNM_PNCLUSTERRESETTIMERUSEDOFPNINFOBYTECONFIG               STD_ON
#define CANNM_PNFILTERMASKOFPNINFOBYTECONFIG                          STD_ON
#define CANNM_PNINFOLENGTH                                            STD_ON
#define CANNM_PNINFOOFFSET                                            STD_ON
#define CANNM_PNMESSAGEFILTERDEACTIVATIONINDICATED                    STD_ON
#define CANNM_PNMESSAGEFILTERENABLED                                  STD_ON
#define CANNM_PNRESETTIME                                             STD_ON
#define CANNM_PNSYNCSHUTDOWNERRORREACTIONENABLED                      STD_OFF  /**< Deactivateable: 'CanNm_PnSyncShutdownErrorReactionEnabled' Reason: 'Request Synchronization Pnc Shutdown Tx feature is disabled.' */
#define CANNM_PNSYNCSHUTDOWNMESSAGETIMEOUTTIME                        STD_OFF  /**< Deactivateable: 'CanNm_PnSyncShutdownMessageTimeoutTime' Reason: 'Request Synchronization Pnc Shutdown Tx feature is disabled.' */
#define CANNM_PNSYNCSHUTDOWNRETRANSMISSIONDURATION                    STD_OFF  /**< Deactivateable: 'CanNm_PnSyncShutdownRetransmissionDuration' Reason: 'Pn Shutdown Message Retransmission Duration is not configured.' */
#define CANNM_PNSRMESSAGETRANSMISSIONONGOING                          STD_OFF  /**< Deactivateable: 'CanNm_PnsrMessageTransmissionOngoingLeft' Reason: 'Request Synchronization Pnc Shutdown is disabled.' and Deactivateable: 'CanNm_PnsrMessageTransmissionOngoingRight' Reason: 'Request Synchronization Pnc Shutdown is disabled.' */
#define CANNM_REMOTESLEEPINDSTATE                                     STD_ON
#define CANNM_REMOTESLEEPTIMER                                        STD_ON
#define CANNM_REPEATMSGBITINDFLAG                                     STD_OFF  /**< Deactivateable: 'CanNm_RepeatMsgBitIndFlagLeft' Reason: 'Node Detection is disabled' and Deactivateable: 'CanNm_RepeatMsgBitIndFlagRight' Reason: 'Node Detection is disabled' */
#define CANNM_REPEATMSGREQFLAG                                        STD_OFF  /**< Deactivateable: 'CanNm_RepeatMsgReqFlagLeft' Reason: 'Node Detection is disabled' and Deactivateable: 'CanNm_RepeatMsgReqFlagRight' Reason: 'Node Detection is disabled' */
#define CANNM_REPEATMSGTIMER                                          STD_ON
#define CANNM_RETRYFIRSTMESSAGEREQUESTFLAG                            STD_OFF  /**< Deactivateable: 'CanNm_RetryFirstMessageRequestFlagLeft' Reason: 'Retry First Message Request is disabled' and Deactivateable: 'CanNm_RetryFirstMessageRequestFlagRight' Reason: 'Retry First Message Request is disabled' */
#define CANNM_RXMESSAGEDATA                                           STD_OFF  /**< Deactivateable: 'CanNm_RxMessageDataLeft' Reason: 'RxMessageDataBuffer is disabled' and Deactivateable: 'CanNm_RxMessageDataRight' Reason: 'RxMessageDataBuffer is disabled' */
#define CANNM_SIZEOFCHANNELCONFIG                                     STD_ON
#define CANNM_SIZEOFCOMMSTATE                                         STD_ON
#define CANNM_SIZEOFCOORDREADYTOSLEEPSTATE                            STD_ON
#define CANNM_SIZEOFIMMEDIATENMMSGCOUNT                               STD_ON
#define CANNM_SIZEOFMSGCONFIRMATIONFLAG                               STD_ON
#define CANNM_SIZEOFMSGINDICATIONFLAG                                 STD_ON
#define CANNM_SIZEOFMSGREQUEST                                        STD_ON
#define CANNM_SIZEOFMSGTIMEOUTTIMER                                   STD_ON
#define CANNM_SIZEOFMSGTIMER                                          STD_ON
#define CANNM_SIZEOFNETWORKRESTARTFLAG                                STD_ON
#define CANNM_SIZEOFNMSTATE                                           STD_ON
#define CANNM_SIZEOFPBCHANNELCONFIG                                   STD_ON
#define CANNM_SIZEOFPNCLUSTERREQ                                      STD_ON
#define CANNM_SIZEOFPNCLUSTERREQNEW                                   STD_ON
#define CANNM_SIZEOFPNINFOBYTECONFIG                                  STD_ON
#define CANNM_SIZEOFPNMESSAGEFILTERDEACTIVATIONINDICATED              STD_ON
#define CANNM_SIZEOFPNMESSAGEFILTERENABLED                            STD_ON
#define CANNM_SIZEOFREMOTESLEEPINDSTATE                               STD_ON
#define CANNM_SIZEOFREMOTESLEEPTIMER                                  STD_ON
#define CANNM_SIZEOFREPEATMSGTIMER                                    STD_ON
#define CANNM_SIZEOFTIMEOUTTIMER                                      STD_ON
#define CANNM_SIZEOFTXCONTROLSTATE                                    STD_ON
#define CANNM_SIZEOFTXCONTROLSTATEREQUEST                             STD_ON
#define CANNM_SIZEOFTXMESSAGEDATA                                     STD_ON
#define CANNM_SIZEOFWAITBUSSLEEPTIMER                                 STD_ON
#define CANNM_SYNCPNCSHUTDOWNREQ                                      STD_OFF  /**< Deactivateable: 'CanNm_SyncPncShutdownReqLeft' Reason: 'Request Synchronization Pnc Shutdown is disabled.' and Deactivateable: 'CanNm_SyncPncShutdownReqRight' Reason: 'Request Synchronization Pnc Shutdown is disabled.' */
#define CANNM_SYNCPNCSHUTDOWNREQEXT                                   STD_OFF  /**< Deactivateable: 'CanNm_SyncPncShutdownReqExtLeft' Reason: 'Request Synchronization Pnc Shutdown is disabled.' and Deactivateable: 'CanNm_SyncPncShutdownReqExtRight' Reason: 'Request Synchronization Pnc Shutdown is disabled.' */
#define CANNM_SYNCPNCSHUTDOWNREQNEW                                   STD_OFF  /**< Deactivateable: 'CanNm_SyncPncShutdownReqNewLeft' Reason: 'Request Synchronization Pnc Shutdown is disabled.' and Deactivateable: 'CanNm_SyncPncShutdownReqNewRight' Reason: 'Request Synchronization Pnc Shutdown is disabled.' */
#define CANNM_SYSTONMCHIND                                            STD_OFF  /**< Deactivateable: 'CanNm_SysToNmChIndLeft' Reason: 'Channel Indirection not needed' and Deactivateable: 'CanNm_SysToNmChIndRight' Reason: 'Channel Indirection not needed' */
#define CANNM_TIMEOUTTIMER                                            STD_ON
#define CANNM_TXCONTROLSTATE                                          STD_ON
#define CANNM_TXCONTROLSTATEREQUEST                                   STD_ON
#define CANNM_TXMESSAGEDATA                                           STD_ON
#define CANNM_WAITBUSSLEEPTIMER                                       STD_ON
#define CANNM_PCCONFIG                                                STD_ON
#define CANNM_CHANNELCONFIGOFPCCONFIG                                 STD_ON
#define CANNM_COMMSTATEOFPCCONFIG                                     STD_ON
#define CANNM_COORDREADYTOSLEEPSTATEOFPCCONFIG                        STD_ON
#define CANNM_FINALMAGICNUMBEROFPCCONFIG                              STD_OFF  /**< Deactivateable: 'CanNm_PCConfig.FinalMagicNumber' Reason: 'the module configuration does not support flashing of data.' */
#define CANNM_GENERATORCOMPATIBILITYVERSIONOFPCCONFIG                 STD_OFF  /**< Deactivateable: 'CanNm_PCConfig.GeneratorCompatibilityVersion' Reason: 'Variant is not VARIANT-POST-BUILD-LOADABLE' */
#define CANNM_IMMEDIATENMMSGCOUNTOFPCCONFIG                           STD_ON
#define CANNM_INITDATAHASHCODEOFPCCONFIG                              STD_OFF  /**< Deactivateable: 'CanNm_PCConfig.InitDataHashCode' Reason: 'the module configuration does not support flashing of data.' */
#define CANNM_MODULEINITIALIZEDOFPCCONFIG                             STD_ON
#define CANNM_MSGCONFIRMATIONFLAGOFPCCONFIG                           STD_ON
#define CANNM_MSGINDICATIONFLAGOFPCCONFIG                             STD_ON
#define CANNM_MSGREQUESTOFPCCONFIG                                    STD_ON
#define CANNM_MSGTIMEOUTTIMEROFPCCONFIG                               STD_ON
#define CANNM_MSGTIMEROFPCCONFIG                                      STD_ON
#define CANNM_NETWORKRESTARTFLAGOFPCCONFIG                            STD_ON
#define CANNM_NMSTATEOFPCCONFIG                                       STD_ON
#define CANNM_PBCHANNELCONFIGOFPCCONFIG                               STD_ON
#define CANNM_PNCLUSTERREQNEWOFPCCONFIG                               STD_ON
#define CANNM_PNCLUSTERREQOFPCCONFIG                                  STD_ON
#define CANNM_PNCLUSTERRESETTIMEROFPCCONFIG                           STD_ON
#define CANNM_PNEIRACALCENABLEDOFPCCONFIG                             STD_ON
#define CANNM_PNEIRARXPDUIDOFPCCONFIG                                 STD_ON
#define CANNM_PNINFOBYTECONFIGOFPCCONFIG                              STD_ON
#define CANNM_PNINFOLENGTHOFPCCONFIG                                  STD_ON
#define CANNM_PNINFOOFFSETOFPCCONFIG                                  STD_ON
#define CANNM_PNMESSAGEFILTERDEACTIVATIONINDICATEDOFPCCONFIG          STD_ON
#define CANNM_PNMESSAGEFILTERENABLEDOFPCCONFIG                        STD_ON
#define CANNM_PNRESETTIMEOFPCCONFIG                                   STD_ON
#define CANNM_PNSYNCSHUTDOWNERRORREACTIONENABLEDOFPCCONFIG            STD_OFF  /**< Deactivateable: 'CanNm_PCConfig.PnSyncShutdownErrorReactionEnabled' Reason: 'Request Synchronization Pnc Shutdown Tx feature is disabled.' */
#define CANNM_PNSYNCSHUTDOWNMESSAGETIMEOUTTIMEOFPCCONFIG              STD_OFF  /**< Deactivateable: 'CanNm_PCConfig.PnSyncShutdownMessageTimeoutTime' Reason: 'Request Synchronization Pnc Shutdown Tx feature is disabled.' */
#define CANNM_PNSYNCSHUTDOWNRETRANSMISSIONDURATIONOFPCCONFIG          STD_OFF  /**< Deactivateable: 'CanNm_PCConfig.PnSyncShutdownRetransmissionDuration' Reason: 'Pn Shutdown Message Retransmission Duration is not configured.' */
#define CANNM_REMOTESLEEPINDSTATEOFPCCONFIG                           STD_ON
#define CANNM_REMOTESLEEPTIMEROFPCCONFIG                              STD_ON
#define CANNM_REPEATMSGTIMEROFPCCONFIG                                STD_ON
#define CANNM_SIZEOFCHANNELCONFIGOFPCCONFIG                           STD_ON
#define CANNM_SIZEOFCOMMSTATEOFPCCONFIG                               STD_ON
#define CANNM_SIZEOFCOORDREADYTOSLEEPSTATEOFPCCONFIG                  STD_ON
#define CANNM_SIZEOFIMMEDIATENMMSGCOUNTOFPCCONFIG                     STD_ON
#define CANNM_SIZEOFMSGCONFIRMATIONFLAGOFPCCONFIG                     STD_ON
#define CANNM_SIZEOFMSGINDICATIONFLAGOFPCCONFIG                       STD_ON
#define CANNM_SIZEOFMSGREQUESTOFPCCONFIG                              STD_ON
#define CANNM_SIZEOFMSGTIMEOUTTIMEROFPCCONFIG                         STD_ON
#define CANNM_SIZEOFMSGTIMEROFPCCONFIG                                STD_ON
#define CANNM_SIZEOFNETWORKRESTARTFLAGOFPCCONFIG                      STD_ON
#define CANNM_SIZEOFNMSTATEOFPCCONFIG                                 STD_ON
#define CANNM_SIZEOFPBCHANNELCONFIGOFPCCONFIG                         STD_ON
#define CANNM_SIZEOFPNCLUSTERREQNEWOFPCCONFIG                         STD_ON
#define CANNM_SIZEOFPNCLUSTERREQOFPCCONFIG                            STD_ON
#define CANNM_SIZEOFPNINFOBYTECONFIGOFPCCONFIG                        STD_ON
#define CANNM_SIZEOFPNMESSAGEFILTERDEACTIVATIONINDICATEDOFPCCONFIG    STD_ON
#define CANNM_SIZEOFPNMESSAGEFILTERENABLEDOFPCCONFIG                  STD_ON
#define CANNM_SIZEOFREMOTESLEEPINDSTATEOFPCCONFIG                     STD_ON
#define CANNM_SIZEOFREMOTESLEEPTIMEROFPCCONFIG                        STD_ON
#define CANNM_SIZEOFREPEATMSGTIMEROFPCCONFIG                          STD_ON
#define CANNM_SIZEOFTIMEOUTTIMEROFPCCONFIG                            STD_ON
#define CANNM_SIZEOFTXCONTROLSTATEOFPCCONFIG                          STD_ON
#define CANNM_SIZEOFTXCONTROLSTATEREQUESTOFPCCONFIG                   STD_ON
#define CANNM_SIZEOFTXMESSAGEDATAOFPCCONFIG                           STD_ON
#define CANNM_SIZEOFWAITBUSSLEEPTIMEROFPCCONFIG                       STD_ON
#define CANNM_TIMEOUTTIMEROFPCCONFIG                                  STD_ON
#define CANNM_TXCONTROLSTATEOFPCCONFIG                                STD_ON
#define CANNM_TXCONTROLSTATEREQUESTOFPCCONFIG                         STD_ON
#define CANNM_TXMESSAGEDATAOFPCCONFIG                                 STD_ON
#define CANNM_WAITBUSSLEEPTIMEROFPCCONFIG                             STD_ON
/** 
  \}
*/ 

/** 
  \defgroup  CanNmPCMinNumericValueDefines  CanNm Min Numeric Value Defines (PRE_COMPILE)
  \brief  These defines are used to implement against the minimum value in numerical based data.
  \{
*/ 
#define CANNM_MIN_COMMSTATE                                           0u
#define CANNM_MIN_COORDREADYTOSLEEPSTATE                              0u
#define CANNM_MIN_IMMEDIATENMMSGCOUNT                                 0u
#define CANNM_MIN_MSGREQUEST                                          0u
#define CANNM_MIN_MSGTIMEOUTTIMER                                     0u
#define CANNM_MIN_MSGTIMER                                            0u
#define CANNM_MIN_NETWORKRESTARTFLAG                                  0u
#define CANNM_MIN_NMSTATE                                             0u
#define CANNM_MIN_PNCLUSTERREQ                                        0u
#define CANNM_MIN_PNCLUSTERREQNEW                                     0u
#define CANNM_MIN_PNCLUSTERRESETTIMER                                 0u
#define CANNM_MIN_REMOTESLEEPTIMER                                    0u
#define CANNM_MIN_REPEATMSGTIMER                                      0u
#define CANNM_MIN_TIMEOUTTIMER                                        0u
#define CANNM_MIN_TXCONTROLSTATE                                      0u
#define CANNM_MIN_TXCONTROLSTATEREQUEST                               0u
#define CANNM_MIN_TXMESSAGEDATA                                       0u
#define CANNM_MIN_WAITBUSSLEEPTIMER                                   0u
/** 
  \}
*/ 

/** 
  \defgroup  CanNmPCMaxNumericValueDefines  CanNm Max Numeric Value Defines (PRE_COMPILE)
  \brief  These defines are used to implement against the maximum value in numerical based data.
  \{
*/ 
#define CANNM_MAX_COMMSTATE                                           255u
#define CANNM_MAX_COORDREADYTOSLEEPSTATE                              255u
#define CANNM_MAX_IMMEDIATENMMSGCOUNT                                 255u
#define CANNM_MAX_MSGREQUEST                                          255u
#define CANNM_MAX_MSGTIMEOUTTIMER                                     65535u
#define CANNM_MAX_MSGTIMER                                            65535u
#define CANNM_MAX_NETWORKRESTARTFLAG                                  255u
#define CANNM_MAX_NMSTATE                                             255u
#define CANNM_MAX_PNCLUSTERREQ                                        255u
#define CANNM_MAX_PNCLUSTERREQNEW                                     255u
#define CANNM_MAX_PNCLUSTERRESETTIMER                                 65535u
#define CANNM_MAX_REMOTESLEEPTIMER                                    65535u
#define CANNM_MAX_REPEATMSGTIMER                                      65535u
#define CANNM_MAX_TIMEOUTTIMER                                        65535u
#define CANNM_MAX_TXCONTROLSTATE                                      255u
#define CANNM_MAX_TXCONTROLSTATEREQUEST                               255u
#define CANNM_MAX_TXMESSAGEDATA                                       255u
#define CANNM_MAX_WAITBUSSLEEPTIMER                                   65535u
/** 
  \}
*/ 

/** 
  \defgroup  CanNmPCNoReferenceDefines  CanNm No Reference Defines (PRE_COMPILE)
  \brief  These defines are used to indicate unused indexes in data relations.
  \{
*/ 
#define CANNM_NO_TXMESSAGEDATAENDIDXOFPBCHANNELCONFIG                 255u
#define CANNM_NO_TXMESSAGEDATASTARTIDXOFPBCHANNELCONFIG               255u
#define CANNM_NO_TXMESSAGEDATA_CBVIDXOFPBCHANNELCONFIG                255u
#define CANNM_NO_TXMESSAGEDATA_PNFILTERMASKENDIDXOFPBCHANNELCONFIG    255u
#define CANNM_NO_TXMESSAGEDATA_PNFILTERMASKSTARTIDXOFPBCHANNELCONFIG  255u
#define CANNM_NO_TXMESSAGEDATA_USERDATAENDIDXOFPBCHANNELCONFIG        255u
#define CANNM_NO_TXMESSAGEDATA_USERDATASTARTIDXOFPBCHANNELCONFIG      255u
#define CANNM_NO_TXPDUIDOFPBCHANNELCONFIG                             255u
#define CANNM_NO_TXUSERDATAPDUIDOFPBCHANNELCONFIG                     255u
#define CANNM_NO_PNCLUSTERRESETTIMERENDIDXOFPNINFOBYTECONFIG          255u
#define CANNM_NO_PNCLUSTERRESETTIMERSTARTIDXOFPNINFOBYTECONFIG        255u
/** 
  \}
*/ 

/** 
  \defgroup  CanNmPCIsReducedToDefineDefines  CanNm Is Reduced To Define Defines (PRE_COMPILE)
  \brief  If all values in a CONST array or an element in a CONST array of structs are equal, the define is STD_ON else STD_OFF.
  \{
*/ 
#define CANNM_ISDEF_ACTIVEWAKEUPBITENABLEDOFCHANNELCONFIG             STD_OFF
#define CANNM_ISDEF_ALLMESSAGESKEEPAWAKEOFCHANNELCONFIG               STD_OFF
#define CANNM_ISDEF_CHANNELIDOFCHANNELCONFIG                          STD_OFF
#define CANNM_ISDEF_COMCONTROLENABLEDOFCHANNELCONFIG                  STD_OFF
#define CANNM_ISDEF_IMMEDIATENMCYCLETIMEOFCHANNELCONFIG               STD_OFF
#define CANNM_ISDEF_IMMEDIATENMTRANSMISSIONSOFCHANNELCONFIG           STD_OFF
#define CANNM_ISDEF_MSGCYCLETIMEOFCHANNELCONFIG                       STD_OFF
#define CANNM_ISDEF_MSGTIMEOUTTIMEOFCHANNELCONFIG                     STD_OFF
#define CANNM_ISDEF_PDUCBVPOSITIONOFCHANNELCONFIG                     STD_OFF
#define CANNM_ISDEF_PNHANDLEMULTIPLENETWORKREQUESTOFCHANNELCONFIG     STD_OFF
#define CANNM_ISDEF_REMOTESLEEPINDTIMEOFCHANNELCONFIG                 STD_OFF
#define CANNM_ISDEF_REPEATMESSAGETIMEOFCHANNELCONFIG                  STD_OFF
#define CANNM_ISDEF_TIMEOUTTIMEOFCHANNELCONFIG                        STD_OFF
#define CANNM_ISDEF_WAITBUSSLEEPTIMEOFCHANNELCONFIG                   STD_OFF
#define CANNM_ISDEF_MSGCYCLEOFFSETOFPBCHANNELCONFIG                   STD_OFF
#define CANNM_ISDEF_PNENABLEDOFPBCHANNELCONFIG                        STD_OFF
#define CANNM_ISDEF_TXMESSAGEDATAENDIDXOFPBCHANNELCONFIG              STD_OFF
#define CANNM_ISDEF_TXMESSAGEDATALENGTHOFPBCHANNELCONFIG              STD_OFF
#define CANNM_ISDEF_TXMESSAGEDATASTARTIDXOFPBCHANNELCONFIG            STD_OFF
#define CANNM_ISDEF_TXMESSAGEDATAUSEDOFPBCHANNELCONFIG                STD_OFF
#define CANNM_ISDEF_TXMESSAGEDATA_CBVIDXOFPBCHANNELCONFIG             STD_OFF
#define CANNM_ISDEF_TXMESSAGEDATA_CBVUSEDOFPBCHANNELCONFIG            STD_OFF
#define CANNM_ISDEF_TXMESSAGEDATA_PNFILTERMASKENDIDXOFPBCHANNELCONFIG STD_OFF
#define CANNM_ISDEF_TXMESSAGEDATA_PNFILTERMASKSTARTIDXOFPBCHANNELCONFIG STD_OFF
#define CANNM_ISDEF_TXMESSAGEDATA_PNFILTERMASKUSEDOFPBCHANNELCONFIG   STD_OFF
#define CANNM_ISDEF_TXMESSAGEDATA_USERDATAENDIDXOFPBCHANNELCONFIG     STD_OFF
#define CANNM_ISDEF_TXMESSAGEDATA_USERDATALENGTHOFPBCHANNELCONFIG     STD_OFF
#define CANNM_ISDEF_TXMESSAGEDATA_USERDATASTARTIDXOFPBCHANNELCONFIG   STD_OFF
#define CANNM_ISDEF_TXMESSAGEDATA_USERDATAUSEDOFPBCHANNELCONFIG       STD_OFF
#define CANNM_ISDEF_TXPDUIDOFPBCHANNELCONFIG                          STD_OFF
#define CANNM_ISDEF_TXUSERDATAPDUIDOFPBCHANNELCONFIG                  STD_OFF
#define CANNM_ISDEF_PNCLUSTERRESETTIMERENDIDXOFPNINFOBYTECONFIG       STD_OFF
#define CANNM_ISDEF_PNCLUSTERRESETTIMERSTARTIDXOFPNINFOBYTECONFIG     STD_OFF
#define CANNM_ISDEF_PNCLUSTERRESETTIMERUSEDOFPNINFOBYTECONFIG         STD_OFF
#define CANNM_ISDEF_PNFILTERMASKOFPNINFOBYTECONFIG                    STD_OFF
#define CANNM_ISDEF_CHANNELCONFIGOFPCCONFIG                           STD_OFF
#define CANNM_ISDEF_COMMSTATEOFPCCONFIG                               STD_ON
#define CANNM_ISDEF_COORDREADYTOSLEEPSTATEOFPCCONFIG                  STD_ON
#define CANNM_ISDEF_IMMEDIATENMMSGCOUNTOFPCCONFIG                     STD_ON
#define CANNM_ISDEF_MODULEINITIALIZEDOFPCCONFIG                       STD_ON
#define CANNM_ISDEF_MSGCONFIRMATIONFLAGOFPCCONFIG                     STD_ON
#define CANNM_ISDEF_MSGINDICATIONFLAGOFPCCONFIG                       STD_ON
#define CANNM_ISDEF_MSGREQUESTOFPCCONFIG                              STD_ON
#define CANNM_ISDEF_MSGTIMEOUTTIMEROFPCCONFIG                         STD_ON
#define CANNM_ISDEF_MSGTIMEROFPCCONFIG                                STD_ON
#define CANNM_ISDEF_NETWORKRESTARTFLAGOFPCCONFIG                      STD_ON
#define CANNM_ISDEF_NMSTATEOFPCCONFIG                                 STD_ON
#define CANNM_ISDEF_PBCHANNELCONFIGOFPCCONFIG                         STD_ON
#define CANNM_ISDEF_PNCLUSTERREQNEWOFPCCONFIG                         STD_ON
#define CANNM_ISDEF_PNCLUSTERREQOFPCCONFIG                            STD_ON
#define CANNM_ISDEF_PNCLUSTERRESETTIMEROFPCCONFIG                     STD_ON
#define CANNM_ISDEF_PNINFOBYTECONFIGOFPCCONFIG                        STD_ON
#define CANNM_ISDEF_PNMESSAGEFILTERDEACTIVATIONINDICATEDOFPCCONFIG    STD_ON
#define CANNM_ISDEF_PNMESSAGEFILTERENABLEDOFPCCONFIG                  STD_ON
#define CANNM_ISDEF_REMOTESLEEPINDSTATEOFPCCONFIG                     STD_ON
#define CANNM_ISDEF_REMOTESLEEPTIMEROFPCCONFIG                        STD_ON
#define CANNM_ISDEF_REPEATMSGTIMEROFPCCONFIG                          STD_ON
#define CANNM_ISDEF_TIMEOUTTIMEROFPCCONFIG                            STD_ON
#define CANNM_ISDEF_TXCONTROLSTATEOFPCCONFIG                          STD_ON
#define CANNM_ISDEF_TXCONTROLSTATEREQUESTOFPCCONFIG                   STD_ON
#define CANNM_ISDEF_TXMESSAGEDATAOFPCCONFIG                           STD_ON
#define CANNM_ISDEF_WAITBUSSLEEPTIMEROFPCCONFIG                       STD_ON
/** 
  \}
*/ 

/** 
  \defgroup  CanNmPCEqualsAlwaysToDefines  CanNm Equals Always To Defines (PRE_COMPILE)
  \brief  If all values in a CONST array or an element in a CONST array of structs are equal, the define contains the always equals value.
  \{
*/ 
#define CANNM_EQ2_ACTIVEWAKEUPBITENABLEDOFCHANNELCONFIG               
#define CANNM_EQ2_ALLMESSAGESKEEPAWAKEOFCHANNELCONFIG                 
#define CANNM_EQ2_CHANNELIDOFCHANNELCONFIG                            
#define CANNM_EQ2_COMCONTROLENABLEDOFCHANNELCONFIG                    
#define CANNM_EQ2_IMMEDIATENMCYCLETIMEOFCHANNELCONFIG                 
#define CANNM_EQ2_IMMEDIATENMTRANSMISSIONSOFCHANNELCONFIG             
#define CANNM_EQ2_MSGCYCLETIMEOFCHANNELCONFIG                         
#define CANNM_EQ2_MSGTIMEOUTTIMEOFCHANNELCONFIG                       
#define CANNM_EQ2_PDUCBVPOSITIONOFCHANNELCONFIG                       
#define CANNM_EQ2_PNHANDLEMULTIPLENETWORKREQUESTOFCHANNELCONFIG       
#define CANNM_EQ2_REMOTESLEEPINDTIMEOFCHANNELCONFIG                   
#define CANNM_EQ2_REPEATMESSAGETIMEOFCHANNELCONFIG                    
#define CANNM_EQ2_TIMEOUTTIMEOFCHANNELCONFIG                          
#define CANNM_EQ2_WAITBUSSLEEPTIMEOFCHANNELCONFIG                     
#define CANNM_EQ2_MSGCYCLEOFFSETOFPBCHANNELCONFIG                     
#define CANNM_EQ2_PNENABLEDOFPBCHANNELCONFIG                          
#define CANNM_EQ2_TXMESSAGEDATAENDIDXOFPBCHANNELCONFIG                
#define CANNM_EQ2_TXMESSAGEDATALENGTHOFPBCHANNELCONFIG                
#define CANNM_EQ2_TXMESSAGEDATASTARTIDXOFPBCHANNELCONFIG              
#define CANNM_EQ2_TXMESSAGEDATAUSEDOFPBCHANNELCONFIG                  
#define CANNM_EQ2_TXMESSAGEDATA_CBVIDXOFPBCHANNELCONFIG               
#define CANNM_EQ2_TXMESSAGEDATA_CBVUSEDOFPBCHANNELCONFIG              
#define CANNM_EQ2_TXMESSAGEDATA_PNFILTERMASKENDIDXOFPBCHANNELCONFIG   
#define CANNM_EQ2_TXMESSAGEDATA_PNFILTERMASKSTARTIDXOFPBCHANNELCONFIG 
#define CANNM_EQ2_TXMESSAGEDATA_PNFILTERMASKUSEDOFPBCHANNELCONFIG     
#define CANNM_EQ2_TXMESSAGEDATA_USERDATAENDIDXOFPBCHANNELCONFIG       
#define CANNM_EQ2_TXMESSAGEDATA_USERDATALENGTHOFPBCHANNELCONFIG       
#define CANNM_EQ2_TXMESSAGEDATA_USERDATASTARTIDXOFPBCHANNELCONFIG     
#define CANNM_EQ2_TXMESSAGEDATA_USERDATAUSEDOFPBCHANNELCONFIG         
#define CANNM_EQ2_TXPDUIDOFPBCHANNELCONFIG                            
#define CANNM_EQ2_TXUSERDATAPDUIDOFPBCHANNELCONFIG                    
#define CANNM_EQ2_PNCLUSTERRESETTIMERENDIDXOFPNINFOBYTECONFIG         
#define CANNM_EQ2_PNCLUSTERRESETTIMERSTARTIDXOFPNINFOBYTECONFIG       
#define CANNM_EQ2_PNCLUSTERRESETTIMERUSEDOFPNINFOBYTECONFIG           
#define CANNM_EQ2_PNFILTERMASKOFPNINFOBYTECONFIG                      
#define CANNM_EQ2_CHANNELCONFIGOFPCCONFIG                             
#define CANNM_EQ2_COMMSTATEOFPCCONFIG                                 CanNm_CommState.raw
#define CANNM_EQ2_COORDREADYTOSLEEPSTATEOFPCCONFIG                    CanNm_CoordReadyToSleepState.raw
#define CANNM_EQ2_IMMEDIATENMMSGCOUNTOFPCCONFIG                       CanNm_ImmediateNmMsgCount.raw
#define CANNM_EQ2_MODULEINITIALIZEDOFPCCONFIG                         (&(CanNm_ModuleInitialized))
#define CANNM_EQ2_MSGCONFIRMATIONFLAGOFPCCONFIG                       CanNm_MsgConfirmationFlag.raw
#define CANNM_EQ2_MSGINDICATIONFLAGOFPCCONFIG                         CanNm_MsgIndicationFlag.raw
#define CANNM_EQ2_MSGREQUESTOFPCCONFIG                                CanNm_MsgRequest.raw
#define CANNM_EQ2_MSGTIMEOUTTIMEROFPCCONFIG                           CanNm_MsgTimeoutTimer.raw
#define CANNM_EQ2_MSGTIMEROFPCCONFIG                                  CanNm_MsgTimer.raw
#define CANNM_EQ2_NETWORKRESTARTFLAGOFPCCONFIG                        CanNm_NetworkRestartFlag.raw
#define CANNM_EQ2_NMSTATEOFPCCONFIG                                   CanNm_NmState.raw
#define CANNM_EQ2_PBCHANNELCONFIGOFPCCONFIG                           CanNm_PbChannelConfig
#define CANNM_EQ2_PNCLUSTERREQNEWOFPCCONFIG                           CanNm_PnClusterReqNew.raw
#define CANNM_EQ2_PNCLUSTERREQOFPCCONFIG                              CanNm_PnClusterReq.raw
#define CANNM_EQ2_PNCLUSTERRESETTIMEROFPCCONFIG                       CanNm_PnClusterResetTimer.raw
#define CANNM_EQ2_PNINFOBYTECONFIGOFPCCONFIG                          CanNm_PnInfoByteConfig
#define CANNM_EQ2_PNMESSAGEFILTERDEACTIVATIONINDICATEDOFPCCONFIG      CanNm_PnMessageFilterDeactivationIndicated.raw
#define CANNM_EQ2_PNMESSAGEFILTERENABLEDOFPCCONFIG                    CanNm_PnMessageFilterEnabled.raw
#define CANNM_EQ2_REMOTESLEEPINDSTATEOFPCCONFIG                       CanNm_RemoteSleepIndState.raw
#define CANNM_EQ2_REMOTESLEEPTIMEROFPCCONFIG                          CanNm_RemoteSleepTimer.raw
#define CANNM_EQ2_REPEATMSGTIMEROFPCCONFIG                            CanNm_RepeatMsgTimer.raw
#define CANNM_EQ2_TIMEOUTTIMEROFPCCONFIG                              CanNm_TimeoutTimer.raw
#define CANNM_EQ2_TXCONTROLSTATEOFPCCONFIG                            CanNm_TxControlState.raw
#define CANNM_EQ2_TXCONTROLSTATEREQUESTOFPCCONFIG                     CanNm_TxControlStateRequest.raw
#define CANNM_EQ2_TXMESSAGEDATAOFPCCONFIG                             CanNm_TxMessageData
#define CANNM_EQ2_WAITBUSSLEEPTIMEROFPCCONFIG                         CanNm_WaitBusSleepTimer.raw
/** 
  \}
*/ 

/** 
  \defgroup  CanNmPCSymbolicInitializationPointers  CanNm Symbolic Initialization Pointers (PRE_COMPILE)
  \brief  Symbolic initialization pointers to be used in the call of a preinit or init function.
  \{
*/ 
#define CanNm_Config_Left_Ptr                                         &(CanNm_PCConfig.Config_Left)  /**< symbolic identifier which shall be used to initialize 'CanNm' */
#define CanNm_Config_Right_Ptr                                        &(CanNm_PCConfig.Config_Right)  /**< symbolic identifier which shall be used to initialize 'CanNm' */
/** 
  \}
*/ 

/** 
  \defgroup  CanNmPCInitializationSymbols  CanNm Initialization Symbols (PRE_COMPILE)
  \brief  Symbolic initialization pointers which may be used in the call of a preinit or init function. Please note, that the defined value can be a 'NULL_PTR' and the address operator is not usable.
  \{
*/ 
#define CanNm_Config_Left                                             CanNm_PCConfig.Config_Left  /**< symbolic identifier which could be used to initialize 'CanNm */
#define CanNm_Config_Right                                            CanNm_PCConfig.Config_Right  /**< symbolic identifier which could be used to initialize 'CanNm */
/** 
  \}
*/ 

/** 
  \defgroup  CanNmPCGeneral  CanNm General (PRE_COMPILE)
  \brief  General constant defines not associated with a group of defines.
  \{
*/ 
#define CANNM_CHECK_INIT_POINTER                                      STD_ON  /**< STD_ON if the init pointer shall not be used as NULL_PTR and a check shall validate this. */
#define CANNM_FINAL_MAGIC_NUMBER                                      0x1F1Eu  /**< the precompile constant to validate the size of the initialization structure at initialization time of CanNm */
#define CANNM_INDIVIDUAL_POSTBUILD                                    STD_OFF  /**< the precompile constant to check, that the module is individual postbuildable. The module 'CanNm' is not configured to be postbuild capable. */
#define CANNM_INIT_DATA                                               CANNM_CONST  /**< CompilerMemClassDefine for the initialization data. */
#define CANNM_INIT_DATA_HASH_CODE                                     1518192245  /**< the precompile constant to validate the initialization structure at initialization time of CanNm with a hashcode. The seed value is '0x1F1Eu' */
#define CANNM_USE_ECUM_BSW_ERROR_HOOK                                 STD_OFF  /**< STD_ON if the EcuM_BswErrorHook shall be called in the ConfigPtr check. */
#define CANNM_USE_INIT_POINTER                                        STD_ON  /**< STD_ON if the init pointer CanNm shall be used. */
/** 
  \}
*/ 


/**********************************************************************************************************************
  CONFIGURATION CLASS: POST_BUILD
  SECTION: GLOBAL CONSTANT MACROS
**********************************************************************************************************************/
/** 
  \defgroup  CanNmPBDataSwitches  CanNm Data Switches  (POST_BUILD)
  \brief  These defines are used to deactivate data and their processing.
  \{
*/ 
#define CANNM_PBCONFIG                                                STD_OFF  /**< Deactivateable: 'CanNm_PBConfig' Reason: 'the module configuration is VARIANT_PRE_COMPILE.' */
#define CANNM_LTCONFIGIDXOFPBCONFIG                                   STD_OFF  /**< Deactivateable: 'CanNm_PBConfig.LTConfigIdx' Reason: 'the module configuration is VARIANT_PRE_COMPILE.' */
#define CANNM_PCCONFIGIDXOFPBCONFIG                                   STD_OFF  /**< Deactivateable: 'CanNm_PBConfig.PCConfigIdx' Reason: 'the module configuration is VARIANT_PRE_COMPILE.' */
/** 
  \}
*/ 



/**********************************************************************************************************************
  GLOBAL FUNCTION MACROS
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
  \defgroup  CanNmPCGetRootDataMacros  CanNm Get Root Data Macros (PRE_COMPILE)
  \brief  These macros are used to get data pointers of root data.
  \{
*/ 
#define CanNm_GetChannelConfigOfPCConfig()                            CanNm_ConfigDataPtr->ChannelConfigOfPCConfig
/** 
  \}
*/ 

/** 
  \defgroup  CanNmPCGetConstantDuplicatedRootDataMacros  CanNm Get Constant Duplicated Root Data Macros (PRE_COMPILE)
  \brief  These macros can be used to read deduplicated by constance root data elements.
  \{
*/ 
#define CanNm_GetCommStateOfPCConfig()                                CanNm_CommState.raw  /**< the pointer to CanNm_CommState */
#define CanNm_GetCoordReadyToSleepStateOfPCConfig()                   CanNm_CoordReadyToSleepState.raw  /**< the pointer to CanNm_CoordReadyToSleepState */
#define CanNm_GetImmediateNmMsgCountOfPCConfig()                      CanNm_ImmediateNmMsgCount.raw  /**< the pointer to CanNm_ImmediateNmMsgCount */
#define CanNm_GetModuleInitializedOfPCConfig()                        (&(CanNm_ModuleInitialized))  /**< the pointer to CanNm_ModuleInitialized */
#define CanNm_GetMsgConfirmationFlagOfPCConfig()                      CanNm_MsgConfirmationFlag.raw  /**< the pointer to CanNm_MsgConfirmationFlag */
#define CanNm_GetMsgIndicationFlagOfPCConfig()                        CanNm_MsgIndicationFlag.raw  /**< the pointer to CanNm_MsgIndicationFlag */
#define CanNm_GetMsgRequestOfPCConfig()                               CanNm_MsgRequest.raw  /**< the pointer to CanNm_MsgRequest */
#define CanNm_GetMsgTimeoutTimerOfPCConfig()                          CanNm_MsgTimeoutTimer.raw  /**< the pointer to CanNm_MsgTimeoutTimer */
#define CanNm_GetMsgTimerOfPCConfig()                                 CanNm_MsgTimer.raw  /**< the pointer to CanNm_MsgTimer */
#define CanNm_GetNetworkRestartFlagOfPCConfig()                       CanNm_NetworkRestartFlag.raw  /**< the pointer to CanNm_NetworkRestartFlag */
#define CanNm_GetNmStateOfPCConfig()                                  CanNm_NmState.raw  /**< the pointer to CanNm_NmState */
#define CanNm_GetPbChannelConfigOfPCConfig()                          CanNm_PbChannelConfig  /**< the pointer to CanNm_PbChannelConfig */
#define CanNm_GetPnClusterReqNewOfPCConfig()                          CanNm_PnClusterReqNew.raw  /**< the pointer to CanNm_PnClusterReqNew */
#define CanNm_GetPnClusterReqOfPCConfig()                             CanNm_PnClusterReq.raw  /**< the pointer to CanNm_PnClusterReq */
#define CanNm_GetPnClusterResetTimerOfPCConfig()                      CanNm_PnClusterResetTimer.raw  /**< the pointer to CanNm_PnClusterResetTimer */
#define CanNm_IsPnEiraCalcEnabledOfPCConfig()                         (((TRUE)) != FALSE)  /**< Determines if PN EIRA Calculation is active or not */
#define CanNm_GetPnEiraRxPduIdOfPCConfig()                            PduRConf_PduRSrcPdu_PduRSrcPdu_bb7efc37  /**< I-PDU handle of Com PDU for EIRA */
#define CanNm_GetPnInfoByteConfigOfPCConfig()                         CanNm_PnInfoByteConfig  /**< the pointer to CanNm_PnInfoByteConfig */
#define CanNm_GetPnInfoLengthOfPCConfig()                             7u  /**< PnInfoLength value */
#define CanNm_GetPnInfoOffsetOfPCConfig()                             1u  /**< PnInfoOffset value */
#define CanNm_GetPnMessageFilterDeactivationIndicatedOfPCConfig()     CanNm_PnMessageFilterDeactivationIndicated.raw  /**< the pointer to CanNm_PnMessageFilterDeactivationIndicated */
#define CanNm_GetPnMessageFilterEnabledOfPCConfig()                   CanNm_PnMessageFilterEnabled.raw  /**< the pointer to CanNm_PnMessageFilterEnabled */
#define CanNm_GetPnResetTimeOfPCConfig()                              110u  /**< PnResetTimer value */
#define CanNm_GetRemoteSleepIndStateOfPCConfig()                      CanNm_RemoteSleepIndState.raw  /**< the pointer to CanNm_RemoteSleepIndState */
#define CanNm_GetRemoteSleepTimerOfPCConfig()                         CanNm_RemoteSleepTimer.raw  /**< the pointer to CanNm_RemoteSleepTimer */
#define CanNm_GetRepeatMsgTimerOfPCConfig()                           CanNm_RepeatMsgTimer.raw  /**< the pointer to CanNm_RepeatMsgTimer */
#define CanNm_GetSizeOfChannelConfigOfPCConfig()                      1u  /**< the number of accomplishable value elements in CanNm_ChannelConfig */
#define CanNm_GetSizeOfPbChannelConfigOfPCConfig()                    1u  /**< the number of accomplishable value elements in CanNm_PbChannelConfig */
#define CanNm_GetSizeOfPnInfoByteConfigOfPCConfig()                   7u  /**< the number of accomplishable value elements in CanNm_PnInfoByteConfig */
#define CanNm_GetSizeOfTxMessageDataOfPCConfig()                      8u  /**< the number of accomplishable value elements in CanNm_TxMessageData */
#define CanNm_GetTimeoutTimerOfPCConfig()                             CanNm_TimeoutTimer.raw  /**< the pointer to CanNm_TimeoutTimer */
#define CanNm_GetTxControlStateOfPCConfig()                           CanNm_TxControlState.raw  /**< the pointer to CanNm_TxControlState */
#define CanNm_GetTxControlStateRequestOfPCConfig()                    CanNm_TxControlStateRequest.raw  /**< the pointer to CanNm_TxControlStateRequest */
#define CanNm_GetTxMessageDataOfPCConfig()                            CanNm_TxMessageData  /**< the pointer to CanNm_TxMessageData */
#define CanNm_GetWaitBusSleepTimerOfPCConfig()                        CanNm_WaitBusSleepTimer.raw  /**< the pointer to CanNm_WaitBusSleepTimer */
/** 
  \}
*/ 

/** 
  \defgroup  CanNmPCGetDuplicatedRootDataMacros  CanNm Get Duplicated Root Data Macros (PRE_COMPILE)
  \brief  These macros can be used to read deduplicated root data elements.
  \{
*/ 
#define CanNm_GetSizeOfCommStateOfPCConfig()                          CanNm_GetSizeOfChannelConfigOfPCConfig()  /**< the number of accomplishable value elements in CanNm_CommState */
#define CanNm_GetSizeOfCoordReadyToSleepStateOfPCConfig()             CanNm_GetSizeOfChannelConfigOfPCConfig()  /**< the number of accomplishable value elements in CanNm_CoordReadyToSleepState */
#define CanNm_GetSizeOfImmediateNmMsgCountOfPCConfig()                CanNm_GetSizeOfChannelConfigOfPCConfig()  /**< the number of accomplishable value elements in CanNm_ImmediateNmMsgCount */
#define CanNm_GetSizeOfMsgConfirmationFlagOfPCConfig()                CanNm_GetSizeOfChannelConfigOfPCConfig()  /**< the number of accomplishable value elements in CanNm_MsgConfirmationFlag */
#define CanNm_GetSizeOfMsgIndicationFlagOfPCConfig()                  CanNm_GetSizeOfChannelConfigOfPCConfig()  /**< the number of accomplishable value elements in CanNm_MsgIndicationFlag */
#define CanNm_GetSizeOfMsgRequestOfPCConfig()                         CanNm_GetSizeOfChannelConfigOfPCConfig()  /**< the number of accomplishable value elements in CanNm_MsgRequest */
#define CanNm_GetSizeOfMsgTimeoutTimerOfPCConfig()                    CanNm_GetSizeOfChannelConfigOfPCConfig()  /**< the number of accomplishable value elements in CanNm_MsgTimeoutTimer */
#define CanNm_GetSizeOfMsgTimerOfPCConfig()                           CanNm_GetSizeOfChannelConfigOfPCConfig()  /**< the number of accomplishable value elements in CanNm_MsgTimer */
#define CanNm_GetSizeOfNetworkRestartFlagOfPCConfig()                 CanNm_GetSizeOfChannelConfigOfPCConfig()  /**< the number of accomplishable value elements in CanNm_NetworkRestartFlag */
#define CanNm_GetSizeOfNmStateOfPCConfig()                            CanNm_GetSizeOfChannelConfigOfPCConfig()  /**< the number of accomplishable value elements in CanNm_NmState */
#define CanNm_GetSizeOfPnClusterReqNewOfPCConfig()                    CanNm_GetSizeOfPnInfoByteConfigOfPCConfig()  /**< the number of accomplishable value elements in CanNm_PnClusterReqNew */
#define CanNm_GetSizeOfPnClusterReqOfPCConfig()                       CanNm_GetSizeOfPnInfoByteConfigOfPCConfig()  /**< the number of accomplishable value elements in CanNm_PnClusterReq */
#define CanNm_GetSizeOfPnMessageFilterDeactivationIndicatedOfPCConfig() CanNm_GetSizeOfChannelConfigOfPCConfig()  /**< the number of accomplishable value elements in CanNm_PnMessageFilterDeactivationIndicated */
#define CanNm_GetSizeOfPnMessageFilterEnabledOfPCConfig()             CanNm_GetSizeOfChannelConfigOfPCConfig()  /**< the number of accomplishable value elements in CanNm_PnMessageFilterEnabled */
#define CanNm_GetSizeOfRemoteSleepIndStateOfPCConfig()                CanNm_GetSizeOfChannelConfigOfPCConfig()  /**< the number of accomplishable value elements in CanNm_RemoteSleepIndState */
#define CanNm_GetSizeOfRemoteSleepTimerOfPCConfig()                   CanNm_GetSizeOfChannelConfigOfPCConfig()  /**< the number of accomplishable value elements in CanNm_RemoteSleepTimer */
#define CanNm_GetSizeOfRepeatMsgTimerOfPCConfig()                     CanNm_GetSizeOfChannelConfigOfPCConfig()  /**< the number of accomplishable value elements in CanNm_RepeatMsgTimer */
#define CanNm_GetSizeOfTimeoutTimerOfPCConfig()                       CanNm_GetSizeOfChannelConfigOfPCConfig()  /**< the number of accomplishable value elements in CanNm_TimeoutTimer */
#define CanNm_GetSizeOfTxControlStateOfPCConfig()                     CanNm_GetSizeOfChannelConfigOfPCConfig()  /**< the number of accomplishable value elements in CanNm_TxControlState */
#define CanNm_GetSizeOfTxControlStateRequestOfPCConfig()              CanNm_GetSizeOfChannelConfigOfPCConfig()  /**< the number of accomplishable value elements in CanNm_TxControlStateRequest */
#define CanNm_GetSizeOfWaitBusSleepTimerOfPCConfig()                  CanNm_GetSizeOfChannelConfigOfPCConfig()  /**< the number of accomplishable value elements in CanNm_WaitBusSleepTimer */
/** 
  \}
*/ 

/** 
  \defgroup  CanNmPCGetDataMacros  CanNm Get Data Macros (PRE_COMPILE)
  \brief  These macros can be used to read CONST and VAR data.
  \{
*/ 
#define CanNm_IsActiveWakeUpBitEnabledOfChannelConfig(Index)          ((CanNm_GetChannelConfigOfPCConfig()[(Index)].ActiveWakeUpBitEnabledOfChannelConfig) != FALSE)
#define CanNm_IsAllMessagesKeepAwakeOfChannelConfig(Index)            ((CanNm_GetChannelConfigOfPCConfig()[(Index)].AllMessagesKeepAwakeOfChannelConfig) != FALSE)
#define CanNm_GetChannelIdOfChannelConfig(Index)                      ((NetworkHandleType)CanNm_GetChannelConfigOfPCConfig()[(Index)].ChannelIdOfChannelConfig)
#define CanNm_IsComControlEnabledOfChannelConfig(Index)               ((CanNm_GetChannelConfigOfPCConfig()[(Index)].ComControlEnabledOfChannelConfig) != FALSE)
#define CanNm_GetImmediateNmCycleTimeOfChannelConfig(Index)           (CanNm_GetChannelConfigOfPCConfig()[(Index)].ImmediateNmCycleTimeOfChannelConfig)
#define CanNm_GetImmediateNmTransmissionsOfChannelConfig(Index)       (CanNm_GetChannelConfigOfPCConfig()[(Index)].ImmediateNmTransmissionsOfChannelConfig)
#define CanNm_GetMsgCycleTimeOfChannelConfig(Index)                   (CanNm_GetChannelConfigOfPCConfig()[(Index)].MsgCycleTimeOfChannelConfig)
#define CanNm_GetMsgTimeoutTimeOfChannelConfig(Index)                 (CanNm_GetChannelConfigOfPCConfig()[(Index)].MsgTimeoutTimeOfChannelConfig)
#define CanNm_GetPduCbvPositionOfChannelConfig(Index)                 (CanNm_GetChannelConfigOfPCConfig()[(Index)].PduCbvPositionOfChannelConfig)
#define CanNm_IsPnHandleMultipleNetworkRequestOfChannelConfig(Index)  ((CanNm_GetChannelConfigOfPCConfig()[(Index)].PnHandleMultipleNetworkRequestOfChannelConfig) != FALSE)
#define CanNm_GetRemoteSleepIndTimeOfChannelConfig(Index)             (CanNm_GetChannelConfigOfPCConfig()[(Index)].RemoteSleepIndTimeOfChannelConfig)
#define CanNm_GetRepeatMessageTimeOfChannelConfig(Index)              (CanNm_GetChannelConfigOfPCConfig()[(Index)].RepeatMessageTimeOfChannelConfig)
#define CanNm_GetTimeoutTimeOfChannelConfig(Index)                    (CanNm_GetChannelConfigOfPCConfig()[(Index)].TimeoutTimeOfChannelConfig)
#define CanNm_GetWaitBusSleepTimeOfChannelConfig(Index)               (CanNm_GetChannelConfigOfPCConfig()[(Index)].WaitBusSleepTimeOfChannelConfig)
#define CanNm_GetCommState(Index)                                     (CanNm_GetCommStateOfPCConfig()[(Index)])
#define CanNm_GetCoordReadyToSleepState(Index)                        (CanNm_GetCoordReadyToSleepStateOfPCConfig()[(Index)])
#define CanNm_GetImmediateNmMsgCount(Index)                           (CanNm_GetImmediateNmMsgCountOfPCConfig()[(Index)])
#define CanNm_IsModuleInitialized()                                   (((*(CanNm_GetModuleInitializedOfPCConfig()))) != FALSE)
#define CanNm_IsMsgConfirmationFlag(Index)                            ((CanNm_GetMsgConfirmationFlagOfPCConfig()[(Index)]) != FALSE)
#define CanNm_IsMsgIndicationFlag(Index)                              ((CanNm_GetMsgIndicationFlagOfPCConfig()[(Index)]) != FALSE)
#define CanNm_GetMsgRequest(Index)                                    (CanNm_GetMsgRequestOfPCConfig()[(Index)])
#define CanNm_GetMsgTimeoutTimer(Index)                               (CanNm_GetMsgTimeoutTimerOfPCConfig()[(Index)])
#define CanNm_GetMsgTimer(Index)                                      (CanNm_GetMsgTimerOfPCConfig()[(Index)])
#define CanNm_GetNetworkRestartFlag(Index)                            (CanNm_GetNetworkRestartFlagOfPCConfig()[(Index)])
#define CanNm_GetNmState(Index)                                       (CanNm_GetNmStateOfPCConfig()[(Index)])
#define CanNm_GetMsgCycleOffsetOfPbChannelConfig(Index)               (CanNm_GetPbChannelConfigOfPCConfig()[(Index)].MsgCycleOffsetOfPbChannelConfig)
#define CanNm_IsPnEnabledOfPbChannelConfig(Index)                     ((CanNm_GetPbChannelConfigOfPCConfig()[(Index)].PnEnabledOfPbChannelConfig) != FALSE)
#define CanNm_GetTxMessageDataEndIdxOfPbChannelConfig(Index)          (CanNm_GetPbChannelConfigOfPCConfig()[(Index)].TxMessageDataEndIdxOfPbChannelConfig)
#define CanNm_GetTxMessageDataLengthOfPbChannelConfig(Index)          (CanNm_GetPbChannelConfigOfPCConfig()[(Index)].TxMessageDataLengthOfPbChannelConfig)
#define CanNm_GetTxMessageDataStartIdxOfPbChannelConfig(Index)        (CanNm_GetPbChannelConfigOfPCConfig()[(Index)].TxMessageDataStartIdxOfPbChannelConfig)
#define CanNm_GetTxMessageData_CBVIdxOfPbChannelConfig(Index)         (CanNm_GetPbChannelConfigOfPCConfig()[(Index)].TxMessageData_CBVIdxOfPbChannelConfig)
#define CanNm_GetTxMessageData_PnFilterMaskEndIdxOfPbChannelConfig(Index) (CanNm_GetPbChannelConfigOfPCConfig()[(Index)].TxMessageData_PnFilterMaskEndIdxOfPbChannelConfig)
#define CanNm_GetTxMessageData_PnFilterMaskStartIdxOfPbChannelConfig(Index) (CanNm_GetPbChannelConfigOfPCConfig()[(Index)].TxMessageData_PnFilterMaskStartIdxOfPbChannelConfig)
#define CanNm_GetTxMessageData_UserDataEndIdxOfPbChannelConfig(Index) (CanNm_GetPbChannelConfigOfPCConfig()[(Index)].TxMessageData_UserDataEndIdxOfPbChannelConfig)
#define CanNm_GetTxMessageData_UserDataLengthOfPbChannelConfig(Index) (CanNm_GetPbChannelConfigOfPCConfig()[(Index)].TxMessageData_UserDataLengthOfPbChannelConfig)
#define CanNm_GetTxMessageData_UserDataStartIdxOfPbChannelConfig(Index) (CanNm_GetPbChannelConfigOfPCConfig()[(Index)].TxMessageData_UserDataStartIdxOfPbChannelConfig)
#define CanNm_GetTxPduIdOfPbChannelConfig(Index)                      (CanNm_GetPbChannelConfigOfPCConfig()[(Index)].TxPduIdOfPbChannelConfig)
#define CanNm_GetTxUserDataPduIdOfPbChannelConfig(Index)              (CanNm_GetPbChannelConfigOfPCConfig()[(Index)].TxUserDataPduIdOfPbChannelConfig)
#define CanNm_GetPnClusterReq(Index)                                  (CanNm_GetPnClusterReqOfPCConfig()[(Index)])
#define CanNm_GetPnClusterReqNew(Index)                               (CanNm_GetPnClusterReqNewOfPCConfig()[(Index)])
#define CanNm_GetPnClusterResetTimer(Index)                           (CanNm_GetPnClusterResetTimerOfPCConfig()[(Index)])
#define CanNm_GetPnClusterResetTimerEndIdxOfPnInfoByteConfig(Index)   (CanNm_GetPnInfoByteConfigOfPCConfig()[(Index)].PnClusterResetTimerEndIdxOfPnInfoByteConfig)
#define CanNm_GetPnClusterResetTimerStartIdxOfPnInfoByteConfig(Index) (CanNm_GetPnInfoByteConfigOfPCConfig()[(Index)].PnClusterResetTimerStartIdxOfPnInfoByteConfig)
#define CanNm_GetPnFilterMaskOfPnInfoByteConfig(Index)                (CanNm_GetPnInfoByteConfigOfPCConfig()[(Index)].PnFilterMaskOfPnInfoByteConfig)
#define CanNm_IsPnMessageFilterDeactivationIndicated(Index)           ((CanNm_GetPnMessageFilterDeactivationIndicatedOfPCConfig()[(Index)]) != FALSE)
#define CanNm_IsPnMessageFilterEnabled(Index)                         ((CanNm_GetPnMessageFilterEnabledOfPCConfig()[(Index)]) != FALSE)
#define CanNm_IsRemoteSleepIndState(Index)                            ((CanNm_GetRemoteSleepIndStateOfPCConfig()[(Index)]) != FALSE)
#define CanNm_GetRemoteSleepTimer(Index)                              (CanNm_GetRemoteSleepTimerOfPCConfig()[(Index)])
#define CanNm_GetRepeatMsgTimer(Index)                                (CanNm_GetRepeatMsgTimerOfPCConfig()[(Index)])
#define CanNm_GetTimeoutTimer(Index)                                  (CanNm_GetTimeoutTimerOfPCConfig()[(Index)])
#define CanNm_GetTxControlState(Index)                                (CanNm_GetTxControlStateOfPCConfig()[(Index)])
#define CanNm_GetTxControlStateRequest(Index)                         (CanNm_GetTxControlStateRequestOfPCConfig()[(Index)])
#define CanNm_GetTxMessageData(Index)                                 (CanNm_GetTxMessageDataOfPCConfig()[(Index)])
#define CanNm_GetWaitBusSleepTimer(Index)                             (CanNm_GetWaitBusSleepTimerOfPCConfig()[(Index)])
/** 
  \}
*/ 

/** 
  \defgroup  CanNmPCGetDeduplicatedDataMacros  CanNm Get Deduplicated Data Macros (PRE_COMPILE)
  \brief  These macros can be used to read deduplicated data elements.
  \{
*/ 
#define CanNm_IsTxMessageDataUsedOfPbChannelConfig(Index)             (((boolean)(CanNm_GetTxMessageDataLengthOfPbChannelConfig(Index) != 0u)) != FALSE)  /**< TRUE, if the 0:n relation has 1 relation pointing to CanNm_TxMessageData */
#define CanNm_IsTxMessageData_CBVUsedOfPbChannelConfig(Index)         (((boolean)(CanNm_GetTxMessageData_CBVIdxOfPbChannelConfig(Index) != CANNM_NO_TXMESSAGEDATA_CBVIDXOFPBCHANNELCONFIG)) != FALSE)  /**< TRUE, if the 0:1 relation has minimum 1 relation pointing to CanNm_TxMessageData */
#define CanNm_IsTxMessageData_PnFilterMaskUsedOfPbChannelConfig(Index) (((boolean)(CanNm_GetTxMessageData_PnFilterMaskStartIdxOfPbChannelConfig(Index) != CANNM_NO_TXMESSAGEDATA_PNFILTERMASKSTARTIDXOFPBCHANNELCONFIG)) != FALSE)  /**< TRUE, if the 0:n relation has 1 relation pointing to CanNm_TxMessageData */
#define CanNm_IsTxMessageData_UserDataUsedOfPbChannelConfig(Index)    (((boolean)(CanNm_GetTxMessageData_UserDataLengthOfPbChannelConfig(Index) != 0u)) != FALSE)  /**< TRUE, if the 0:n relation has 1 relation pointing to CanNm_TxMessageData */
#define CanNm_IsPnEiraCalcEnabled()                                   CanNm_IsPnEiraCalcEnabledOfPCConfig()
#define CanNm_GetPnEiraRxPduId()                                      CanNm_GetPnEiraRxPduIdOfPCConfig()
#define CanNm_IsPnClusterResetTimerUsedOfPnInfoByteConfig(Index)      (((boolean)(CanNm_GetPnClusterResetTimerStartIdxOfPnInfoByteConfig(Index) != CANNM_NO_PNCLUSTERRESETTIMERSTARTIDXOFPNINFOBYTECONFIG)) != FALSE)  /**< TRUE, if the 0:n relation has 1 relation pointing to CanNm_PnClusterResetTimer */
#define CanNm_GetPnInfoLength()                                       CanNm_GetPnInfoLengthOfPCConfig()
#define CanNm_GetPnInfoOffset()                                       CanNm_GetPnInfoOffsetOfPCConfig()
#define CanNm_GetPnResetTime()                                        CanNm_GetPnResetTimeOfPCConfig()
#define CanNm_GetSizeOfChannelConfig()                                CanNm_GetSizeOfChannelConfigOfPCConfig()
#define CanNm_GetSizeOfCommState()                                    CanNm_GetSizeOfCommStateOfPCConfig()
#define CanNm_GetSizeOfCoordReadyToSleepState()                       CanNm_GetSizeOfCoordReadyToSleepStateOfPCConfig()
#define CanNm_GetSizeOfImmediateNmMsgCount()                          CanNm_GetSizeOfImmediateNmMsgCountOfPCConfig()
#define CanNm_GetSizeOfMsgConfirmationFlag()                          CanNm_GetSizeOfMsgConfirmationFlagOfPCConfig()
#define CanNm_GetSizeOfMsgIndicationFlag()                            CanNm_GetSizeOfMsgIndicationFlagOfPCConfig()
#define CanNm_GetSizeOfMsgRequest()                                   CanNm_GetSizeOfMsgRequestOfPCConfig()
#define CanNm_GetSizeOfMsgTimeoutTimer()                              CanNm_GetSizeOfMsgTimeoutTimerOfPCConfig()
#define CanNm_GetSizeOfMsgTimer()                                     CanNm_GetSizeOfMsgTimerOfPCConfig()
#define CanNm_GetSizeOfNetworkRestartFlag()                           CanNm_GetSizeOfNetworkRestartFlagOfPCConfig()
#define CanNm_GetSizeOfNmState()                                      CanNm_GetSizeOfNmStateOfPCConfig()
#define CanNm_GetSizeOfPbChannelConfig()                              CanNm_GetSizeOfPbChannelConfigOfPCConfig()
#define CanNm_GetSizeOfPnClusterReq()                                 CanNm_GetSizeOfPnClusterReqOfPCConfig()
#define CanNm_GetSizeOfPnClusterReqNew()                              CanNm_GetSizeOfPnClusterReqNewOfPCConfig()
#define CanNm_GetSizeOfPnInfoByteConfig()                             CanNm_GetSizeOfPnInfoByteConfigOfPCConfig()
#define CanNm_GetSizeOfPnMessageFilterDeactivationIndicated()         CanNm_GetSizeOfPnMessageFilterDeactivationIndicatedOfPCConfig()
#define CanNm_GetSizeOfPnMessageFilterEnabled()                       CanNm_GetSizeOfPnMessageFilterEnabledOfPCConfig()
#define CanNm_GetSizeOfRemoteSleepIndState()                          CanNm_GetSizeOfRemoteSleepIndStateOfPCConfig()
#define CanNm_GetSizeOfRemoteSleepTimer()                             CanNm_GetSizeOfRemoteSleepTimerOfPCConfig()
#define CanNm_GetSizeOfRepeatMsgTimer()                               CanNm_GetSizeOfRepeatMsgTimerOfPCConfig()
#define CanNm_GetSizeOfTimeoutTimer()                                 CanNm_GetSizeOfTimeoutTimerOfPCConfig()
#define CanNm_GetSizeOfTxControlState()                               CanNm_GetSizeOfTxControlStateOfPCConfig()
#define CanNm_GetSizeOfTxControlStateRequest()                        CanNm_GetSizeOfTxControlStateRequestOfPCConfig()
#define CanNm_GetSizeOfTxMessageData()                                CanNm_GetSizeOfTxMessageDataOfPCConfig()
#define CanNm_GetSizeOfWaitBusSleepTimer()                            CanNm_GetSizeOfWaitBusSleepTimerOfPCConfig()
/** 
  \}
*/ 

/** 
  \defgroup  CanNmPCSetDataMacros  CanNm Set Data Macros (PRE_COMPILE)
  \brief  These macros can be used to write data.
  \{
*/ 
#define CanNm_SetCommState(Index, Value)                              CanNm_GetCommStateOfPCConfig()[(Index)] = (Value)
#define CanNm_SetCoordReadyToSleepState(Index, Value)                 CanNm_GetCoordReadyToSleepStateOfPCConfig()[(Index)] = (Value)
#define CanNm_SetImmediateNmMsgCount(Index, Value)                    CanNm_GetImmediateNmMsgCountOfPCConfig()[(Index)] = (Value)
#define CanNm_SetModuleInitialized(Value)                             (*(CanNm_GetModuleInitializedOfPCConfig())) = (Value)
#define CanNm_SetMsgConfirmationFlag(Index, Value)                    CanNm_GetMsgConfirmationFlagOfPCConfig()[(Index)] = (Value)
#define CanNm_SetMsgIndicationFlag(Index, Value)                      CanNm_GetMsgIndicationFlagOfPCConfig()[(Index)] = (Value)
#define CanNm_SetMsgRequest(Index, Value)                             CanNm_GetMsgRequestOfPCConfig()[(Index)] = (Value)
#define CanNm_SetMsgTimeoutTimer(Index, Value)                        CanNm_GetMsgTimeoutTimerOfPCConfig()[(Index)] = (Value)
#define CanNm_SetMsgTimer(Index, Value)                               CanNm_GetMsgTimerOfPCConfig()[(Index)] = (Value)
#define CanNm_SetNetworkRestartFlag(Index, Value)                     CanNm_GetNetworkRestartFlagOfPCConfig()[(Index)] = (Value)
#define CanNm_SetNmState(Index, Value)                                CanNm_GetNmStateOfPCConfig()[(Index)] = (Value)
#define CanNm_SetPnClusterReq(Index, Value)                           CanNm_GetPnClusterReqOfPCConfig()[(Index)] = (Value)
#define CanNm_SetPnClusterReqNew(Index, Value)                        CanNm_GetPnClusterReqNewOfPCConfig()[(Index)] = (Value)
#define CanNm_SetPnClusterResetTimer(Index, Value)                    CanNm_GetPnClusterResetTimerOfPCConfig()[(Index)] = (Value)
#define CanNm_SetPnMessageFilterDeactivationIndicated(Index, Value)   CanNm_GetPnMessageFilterDeactivationIndicatedOfPCConfig()[(Index)] = (Value)
#define CanNm_SetPnMessageFilterEnabled(Index, Value)                 CanNm_GetPnMessageFilterEnabledOfPCConfig()[(Index)] = (Value)
#define CanNm_SetRemoteSleepIndState(Index, Value)                    CanNm_GetRemoteSleepIndStateOfPCConfig()[(Index)] = (Value)
#define CanNm_SetRemoteSleepTimer(Index, Value)                       CanNm_GetRemoteSleepTimerOfPCConfig()[(Index)] = (Value)
#define CanNm_SetRepeatMsgTimer(Index, Value)                         CanNm_GetRepeatMsgTimerOfPCConfig()[(Index)] = (Value)
#define CanNm_SetTimeoutTimer(Index, Value)                           CanNm_GetTimeoutTimerOfPCConfig()[(Index)] = (Value)
#define CanNm_SetTxControlState(Index, Value)                         CanNm_GetTxControlStateOfPCConfig()[(Index)] = (Value)
#define CanNm_SetTxControlStateRequest(Index, Value)                  CanNm_GetTxControlStateRequestOfPCConfig()[(Index)] = (Value)
#define CanNm_SetTxMessageData(Index, Value)                          CanNm_GetTxMessageDataOfPCConfig()[(Index)] = (Value)
#define CanNm_SetWaitBusSleepTimer(Index, Value)                      CanNm_GetWaitBusSleepTimerOfPCConfig()[(Index)] = (Value)
/** 
  \}
*/ 

/** 
  \defgroup  CanNmPCGetAddressOfDataMacros  CanNm Get Address Of Data Macros (PRE_COMPILE)
  \brief  These macros can be used to get the data by the address operator.
  \{
*/ 
#define CanNm_GetAddrNmState(Index)                                   (&CanNm_GetNmState(Index))
#define CanNm_GetAddrPnClusterReq(Index)                              (&CanNm_GetPnClusterReq(Index))
#define CanNm_GetAddrPnClusterReqNew(Index)                           (&CanNm_GetPnClusterReqNew(Index))
#define CanNm_GetAddrTxMessageData(Index)                             (&CanNm_GetTxMessageData(Index))
/** 
  \}
*/ 

/** 
  \defgroup  CanNmPCHasMacros  CanNm Has Macros (PRE_COMPILE)
  \brief  These macros can be used to detect at runtime a deactivated piece of information. TRUE in the CONFIGURATION_VARIANT PRE-COMPILE, TRUE or FALSE in the CONFIGURATION_VARIANT POST-BUILD.
  \{
*/ 
#define CanNm_HasChannelConfig()                                      (CanNm_GetChannelConfigOfPCConfig() != NULL_PTR)
#define CanNm_HasActiveWakeUpBitEnabledOfChannelConfig()              (TRUE != FALSE)
#define CanNm_HasAllMessagesKeepAwakeOfChannelConfig()                (TRUE != FALSE)
#define CanNm_HasChannelIdOfChannelConfig()                           (TRUE != FALSE)
#define CanNm_HasComControlEnabledOfChannelConfig()                   (TRUE != FALSE)
#define CanNm_HasImmediateNmCycleTimeOfChannelConfig()                (TRUE != FALSE)
#define CanNm_HasImmediateNmTransmissionsOfChannelConfig()            (TRUE != FALSE)
#define CanNm_HasMsgCycleTimeOfChannelConfig()                        (TRUE != FALSE)
#define CanNm_HasMsgTimeoutTimeOfChannelConfig()                      (TRUE != FALSE)
#define CanNm_HasPduCbvPositionOfChannelConfig()                      (TRUE != FALSE)
#define CanNm_HasPnHandleMultipleNetworkRequestOfChannelConfig()      (TRUE != FALSE)
#define CanNm_HasRemoteSleepIndTimeOfChannelConfig()                  (TRUE != FALSE)
#define CanNm_HasRepeatMessageTimeOfChannelConfig()                   (TRUE != FALSE)
#define CanNm_HasTimeoutTimeOfChannelConfig()                         (TRUE != FALSE)
#define CanNm_HasWaitBusSleepTimeOfChannelConfig()                    (TRUE != FALSE)
#define CanNm_HasCommState()                                          (TRUE != FALSE)
#define CanNm_HasCoordReadyToSleepState()                             (TRUE != FALSE)
#define CanNm_HasImmediateNmMsgCount()                                (TRUE != FALSE)
#define CanNm_HasModuleInitialized()                                  (TRUE != FALSE)
#define CanNm_HasMsgConfirmationFlag()                                (TRUE != FALSE)
#define CanNm_HasMsgIndicationFlag()                                  (TRUE != FALSE)
#define CanNm_HasMsgRequest()                                         (TRUE != FALSE)
#define CanNm_HasMsgTimeoutTimer()                                    (TRUE != FALSE)
#define CanNm_HasMsgTimer()                                           (TRUE != FALSE)
#define CanNm_HasNetworkRestartFlag()                                 (TRUE != FALSE)
#define CanNm_HasNmState()                                            (TRUE != FALSE)
#define CanNm_HasPbChannelConfig()                                    (TRUE != FALSE)
#define CanNm_HasMsgCycleOffsetOfPbChannelConfig()                    (TRUE != FALSE)
#define CanNm_HasPnEnabledOfPbChannelConfig()                         (TRUE != FALSE)
#define CanNm_HasTxMessageDataEndIdxOfPbChannelConfig()               (TRUE != FALSE)
#define CanNm_HasTxMessageDataLengthOfPbChannelConfig()               (TRUE != FALSE)
#define CanNm_HasTxMessageDataStartIdxOfPbChannelConfig()             (TRUE != FALSE)
#define CanNm_HasTxMessageDataUsedOfPbChannelConfig()                 (TRUE != FALSE)
#define CanNm_HasTxMessageData_CBVIdxOfPbChannelConfig()              (TRUE != FALSE)
#define CanNm_HasTxMessageData_CBVUsedOfPbChannelConfig()             (TRUE != FALSE)
#define CanNm_HasTxMessageData_PnFilterMaskEndIdxOfPbChannelConfig()  (TRUE != FALSE)
#define CanNm_HasTxMessageData_PnFilterMaskStartIdxOfPbChannelConfig() (TRUE != FALSE)
#define CanNm_HasTxMessageData_PnFilterMaskUsedOfPbChannelConfig()    (TRUE != FALSE)
#define CanNm_HasTxMessageData_UserDataEndIdxOfPbChannelConfig()      (TRUE != FALSE)
#define CanNm_HasTxMessageData_UserDataLengthOfPbChannelConfig()      (TRUE != FALSE)
#define CanNm_HasTxMessageData_UserDataStartIdxOfPbChannelConfig()    (TRUE != FALSE)
#define CanNm_HasTxMessageData_UserDataUsedOfPbChannelConfig()        (TRUE != FALSE)
#define CanNm_HasTxPduIdOfPbChannelConfig()                           (TRUE != FALSE)
#define CanNm_HasTxUserDataPduIdOfPbChannelConfig()                   (TRUE != FALSE)
#define CanNm_HasPnClusterReq()                                       (TRUE != FALSE)
#define CanNm_HasPnClusterReqNew()                                    (TRUE != FALSE)
#define CanNm_HasPnClusterResetTimer()                                (TRUE != FALSE)
#define CanNm_HasPnEiraCalcEnabled()                                  (TRUE != FALSE)
#define CanNm_HasPnEiraRxPduId()                                      (TRUE != FALSE)
#define CanNm_HasPnInfoByteConfig()                                   (TRUE != FALSE)
#define CanNm_HasPnClusterResetTimerEndIdxOfPnInfoByteConfig()        (TRUE != FALSE)
#define CanNm_HasPnClusterResetTimerStartIdxOfPnInfoByteConfig()      (TRUE != FALSE)
#define CanNm_HasPnClusterResetTimerUsedOfPnInfoByteConfig()          (TRUE != FALSE)
#define CanNm_HasPnFilterMaskOfPnInfoByteConfig()                     (TRUE != FALSE)
#define CanNm_HasPnInfoLength()                                       (TRUE != FALSE)
#define CanNm_HasPnInfoOffset()                                       (TRUE != FALSE)
#define CanNm_HasPnMessageFilterDeactivationIndicated()               (TRUE != FALSE)
#define CanNm_HasPnMessageFilterEnabled()                             (TRUE != FALSE)
#define CanNm_HasPnResetTime()                                        (TRUE != FALSE)
#define CanNm_HasRemoteSleepIndState()                                (TRUE != FALSE)
#define CanNm_HasRemoteSleepTimer()                                   (TRUE != FALSE)
#define CanNm_HasRepeatMsgTimer()                                     (TRUE != FALSE)
#define CanNm_HasSizeOfChannelConfig()                                (TRUE != FALSE)
#define CanNm_HasSizeOfCommState()                                    (TRUE != FALSE)
#define CanNm_HasSizeOfCoordReadyToSleepState()                       (TRUE != FALSE)
#define CanNm_HasSizeOfImmediateNmMsgCount()                          (TRUE != FALSE)
#define CanNm_HasSizeOfMsgConfirmationFlag()                          (TRUE != FALSE)
#define CanNm_HasSizeOfMsgIndicationFlag()                            (TRUE != FALSE)
#define CanNm_HasSizeOfMsgRequest()                                   (TRUE != FALSE)
#define CanNm_HasSizeOfMsgTimeoutTimer()                              (TRUE != FALSE)
#define CanNm_HasSizeOfMsgTimer()                                     (TRUE != FALSE)
#define CanNm_HasSizeOfNetworkRestartFlag()                           (TRUE != FALSE)
#define CanNm_HasSizeOfNmState()                                      (TRUE != FALSE)
#define CanNm_HasSizeOfPbChannelConfig()                              (TRUE != FALSE)
#define CanNm_HasSizeOfPnClusterReq()                                 (TRUE != FALSE)
#define CanNm_HasSizeOfPnClusterReqNew()                              (TRUE != FALSE)
#define CanNm_HasSizeOfPnInfoByteConfig()                             (TRUE != FALSE)
#define CanNm_HasSizeOfPnMessageFilterDeactivationIndicated()         (TRUE != FALSE)
#define CanNm_HasSizeOfPnMessageFilterEnabled()                       (TRUE != FALSE)
#define CanNm_HasSizeOfRemoteSleepIndState()                          (TRUE != FALSE)
#define CanNm_HasSizeOfRemoteSleepTimer()                             (TRUE != FALSE)
#define CanNm_HasSizeOfRepeatMsgTimer()                               (TRUE != FALSE)
#define CanNm_HasSizeOfTimeoutTimer()                                 (TRUE != FALSE)
#define CanNm_HasSizeOfTxControlState()                               (TRUE != FALSE)
#define CanNm_HasSizeOfTxControlStateRequest()                        (TRUE != FALSE)
#define CanNm_HasSizeOfTxMessageData()                                (TRUE != FALSE)
#define CanNm_HasSizeOfWaitBusSleepTimer()                            (TRUE != FALSE)
#define CanNm_HasTimeoutTimer()                                       (TRUE != FALSE)
#define CanNm_HasTxControlState()                                     (TRUE != FALSE)
#define CanNm_HasTxControlStateRequest()                              (TRUE != FALSE)
#define CanNm_HasTxMessageData()                                      (TRUE != FALSE)
#define CanNm_HasWaitBusSleepTimer()                                  (TRUE != FALSE)
#define CanNm_HasPCConfig()                                           (TRUE != FALSE)
#define CanNm_HasChannelConfigOfPCConfig()                            (TRUE != FALSE)
#define CanNm_HasCommStateOfPCConfig()                                (TRUE != FALSE)
#define CanNm_HasCoordReadyToSleepStateOfPCConfig()                   (TRUE != FALSE)
#define CanNm_HasImmediateNmMsgCountOfPCConfig()                      (TRUE != FALSE)
#define CanNm_HasModuleInitializedOfPCConfig()                        (TRUE != FALSE)
#define CanNm_HasMsgConfirmationFlagOfPCConfig()                      (TRUE != FALSE)
#define CanNm_HasMsgIndicationFlagOfPCConfig()                        (TRUE != FALSE)
#define CanNm_HasMsgRequestOfPCConfig()                               (TRUE != FALSE)
#define CanNm_HasMsgTimeoutTimerOfPCConfig()                          (TRUE != FALSE)
#define CanNm_HasMsgTimerOfPCConfig()                                 (TRUE != FALSE)
#define CanNm_HasNetworkRestartFlagOfPCConfig()                       (TRUE != FALSE)
#define CanNm_HasNmStateOfPCConfig()                                  (TRUE != FALSE)
#define CanNm_HasPbChannelConfigOfPCConfig()                          (TRUE != FALSE)
#define CanNm_HasPnClusterReqNewOfPCConfig()                          (TRUE != FALSE)
#define CanNm_HasPnClusterReqOfPCConfig()                             (TRUE != FALSE)
#define CanNm_HasPnClusterResetTimerOfPCConfig()                      (TRUE != FALSE)
#define CanNm_HasPnEiraCalcEnabledOfPCConfig()                        (TRUE != FALSE)
#define CanNm_HasPnEiraRxPduIdOfPCConfig()                            (TRUE != FALSE)
#define CanNm_HasPnInfoByteConfigOfPCConfig()                         (TRUE != FALSE)
#define CanNm_HasPnInfoLengthOfPCConfig()                             (TRUE != FALSE)
#define CanNm_HasPnInfoOffsetOfPCConfig()                             (TRUE != FALSE)
#define CanNm_HasPnMessageFilterDeactivationIndicatedOfPCConfig()     (TRUE != FALSE)
#define CanNm_HasPnMessageFilterEnabledOfPCConfig()                   (TRUE != FALSE)
#define CanNm_HasPnResetTimeOfPCConfig()                              (TRUE != FALSE)
#define CanNm_HasRemoteSleepIndStateOfPCConfig()                      (TRUE != FALSE)
#define CanNm_HasRemoteSleepTimerOfPCConfig()                         (TRUE != FALSE)
#define CanNm_HasRepeatMsgTimerOfPCConfig()                           (TRUE != FALSE)
#define CanNm_HasSizeOfChannelConfigOfPCConfig()                      (TRUE != FALSE)
#define CanNm_HasSizeOfCommStateOfPCConfig()                          (TRUE != FALSE)
#define CanNm_HasSizeOfCoordReadyToSleepStateOfPCConfig()             (TRUE != FALSE)
#define CanNm_HasSizeOfImmediateNmMsgCountOfPCConfig()                (TRUE != FALSE)
#define CanNm_HasSizeOfMsgConfirmationFlagOfPCConfig()                (TRUE != FALSE)
#define CanNm_HasSizeOfMsgIndicationFlagOfPCConfig()                  (TRUE != FALSE)
#define CanNm_HasSizeOfMsgRequestOfPCConfig()                         (TRUE != FALSE)
#define CanNm_HasSizeOfMsgTimeoutTimerOfPCConfig()                    (TRUE != FALSE)
#define CanNm_HasSizeOfMsgTimerOfPCConfig()                           (TRUE != FALSE)
#define CanNm_HasSizeOfNetworkRestartFlagOfPCConfig()                 (TRUE != FALSE)
#define CanNm_HasSizeOfNmStateOfPCConfig()                            (TRUE != FALSE)
#define CanNm_HasSizeOfPbChannelConfigOfPCConfig()                    (TRUE != FALSE)
#define CanNm_HasSizeOfPnClusterReqNewOfPCConfig()                    (TRUE != FALSE)
#define CanNm_HasSizeOfPnClusterReqOfPCConfig()                       (TRUE != FALSE)
#define CanNm_HasSizeOfPnInfoByteConfigOfPCConfig()                   (TRUE != FALSE)
#define CanNm_HasSizeOfPnMessageFilterDeactivationIndicatedOfPCConfig() (TRUE != FALSE)
#define CanNm_HasSizeOfPnMessageFilterEnabledOfPCConfig()             (TRUE != FALSE)
#define CanNm_HasSizeOfRemoteSleepIndStateOfPCConfig()                (TRUE != FALSE)
#define CanNm_HasSizeOfRemoteSleepTimerOfPCConfig()                   (TRUE != FALSE)
#define CanNm_HasSizeOfRepeatMsgTimerOfPCConfig()                     (TRUE != FALSE)
#define CanNm_HasSizeOfTimeoutTimerOfPCConfig()                       (TRUE != FALSE)
#define CanNm_HasSizeOfTxControlStateOfPCConfig()                     (TRUE != FALSE)
#define CanNm_HasSizeOfTxControlStateRequestOfPCConfig()              (TRUE != FALSE)
#define CanNm_HasSizeOfTxMessageDataOfPCConfig()                      (TRUE != FALSE)
#define CanNm_HasSizeOfWaitBusSleepTimerOfPCConfig()                  (TRUE != FALSE)
#define CanNm_HasTimeoutTimerOfPCConfig()                             (TRUE != FALSE)
#define CanNm_HasTxControlStateOfPCConfig()                           (TRUE != FALSE)
#define CanNm_HasTxControlStateRequestOfPCConfig()                    (TRUE != FALSE)
#define CanNm_HasTxMessageDataOfPCConfig()                            (TRUE != FALSE)
#define CanNm_HasWaitBusSleepTimerOfPCConfig()                        (TRUE != FALSE)
/** 
  \}
*/ 

/** 
  \defgroup  CanNmPCIncrementDataMacros  CanNm Increment Data Macros (PRE_COMPILE)
  \brief  These macros can be used to increment VAR data with numerical nature.
  \{
*/ 
#define CanNm_IncCommState(Index)                                     CanNm_GetCommState(Index)++
#define CanNm_IncCoordReadyToSleepState(Index)                        CanNm_GetCoordReadyToSleepState(Index)++
#define CanNm_IncImmediateNmMsgCount(Index)                           CanNm_GetImmediateNmMsgCount(Index)++
#define CanNm_IncMsgRequest(Index)                                    CanNm_GetMsgRequest(Index)++
#define CanNm_IncMsgTimeoutTimer(Index)                               CanNm_GetMsgTimeoutTimer(Index)++
#define CanNm_IncMsgTimer(Index)                                      CanNm_GetMsgTimer(Index)++
#define CanNm_IncNetworkRestartFlag(Index)                            CanNm_GetNetworkRestartFlag(Index)++
#define CanNm_IncNmState(Index)                                       CanNm_GetNmState(Index)++
#define CanNm_IncPnClusterReq(Index)                                  CanNm_GetPnClusterReq(Index)++
#define CanNm_IncPnClusterReqNew(Index)                               CanNm_GetPnClusterReqNew(Index)++
#define CanNm_IncPnClusterResetTimer(Index)                           CanNm_GetPnClusterResetTimer(Index)++
#define CanNm_IncRemoteSleepTimer(Index)                              CanNm_GetRemoteSleepTimer(Index)++
#define CanNm_IncRepeatMsgTimer(Index)                                CanNm_GetRepeatMsgTimer(Index)++
#define CanNm_IncTimeoutTimer(Index)                                  CanNm_GetTimeoutTimer(Index)++
#define CanNm_IncTxControlState(Index)                                CanNm_GetTxControlState(Index)++
#define CanNm_IncTxControlStateRequest(Index)                         CanNm_GetTxControlStateRequest(Index)++
#define CanNm_IncTxMessageData(Index)                                 CanNm_GetTxMessageData(Index)++
#define CanNm_IncWaitBusSleepTimer(Index)                             CanNm_GetWaitBusSleepTimer(Index)++
/** 
  \}
*/ 

/** 
  \defgroup  CanNmPCDecrementDataMacros  CanNm Decrement Data Macros (PRE_COMPILE)
  \brief  These macros can be used to decrement VAR data with numerical nature.
  \{
*/ 
#define CanNm_DecCommState(Index)                                     CanNm_GetCommState(Index)--
#define CanNm_DecCoordReadyToSleepState(Index)                        CanNm_GetCoordReadyToSleepState(Index)--
#define CanNm_DecImmediateNmMsgCount(Index)                           CanNm_GetImmediateNmMsgCount(Index)--
#define CanNm_DecMsgRequest(Index)                                    CanNm_GetMsgRequest(Index)--
#define CanNm_DecMsgTimeoutTimer(Index)                               CanNm_GetMsgTimeoutTimer(Index)--
#define CanNm_DecMsgTimer(Index)                                      CanNm_GetMsgTimer(Index)--
#define CanNm_DecNetworkRestartFlag(Index)                            CanNm_GetNetworkRestartFlag(Index)--
#define CanNm_DecNmState(Index)                                       CanNm_GetNmState(Index)--
#define CanNm_DecPnClusterReq(Index)                                  CanNm_GetPnClusterReq(Index)--
#define CanNm_DecPnClusterReqNew(Index)                               CanNm_GetPnClusterReqNew(Index)--
#define CanNm_DecPnClusterResetTimer(Index)                           CanNm_GetPnClusterResetTimer(Index)--
#define CanNm_DecRemoteSleepTimer(Index)                              CanNm_GetRemoteSleepTimer(Index)--
#define CanNm_DecRepeatMsgTimer(Index)                                CanNm_GetRepeatMsgTimer(Index)--
#define CanNm_DecTimeoutTimer(Index)                                  CanNm_GetTimeoutTimer(Index)--
#define CanNm_DecTxControlState(Index)                                CanNm_GetTxControlState(Index)--
#define CanNm_DecTxControlStateRequest(Index)                         CanNm_GetTxControlStateRequest(Index)--
#define CanNm_DecTxMessageData(Index)                                 CanNm_GetTxMessageData(Index)--
#define CanNm_DecWaitBusSleepTimer(Index)                             CanNm_GetWaitBusSleepTimer(Index)--
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


/**********************************************************************************************************************
  GLOBAL DATA TYPES AND STRUCTURES
**********************************************************************************************************************/

#if ( CANNM_SYNCHRONIZEDPNCSHUTDOWNENABLEDOFCHANNELCONFIG == STD_ON )
# define CANNM_MAX_PN_INFO_LENGTH                          7u
#endif

/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL SIMPLE DATA TYPES AND STRUCTURES
**********************************************************************************************************************/
/** 
  \defgroup  CanNmPCIterableTypes  CanNm Iterable Types (PRE_COMPILE)
  \brief  These type definitions are used to iterate over an array with least processor cycles for variable access as possible.
  \{
*/ 
/**   \brief  type used to iterate CanNm_ChannelConfig */
typedef uint8_least CanNm_ChannelConfigIterType;

/**   \brief  type used to iterate CanNm_PbChannelConfig */
typedef uint8_least CanNm_PbChannelConfigIterType;

/**   \brief  type used to iterate CanNm_PnClusterResetTimer */
typedef uint8_least CanNm_PnClusterResetTimerIterType;

/**   \brief  type used to iterate CanNm_PnInfoByteConfig */
typedef uint8_least CanNm_PnInfoByteConfigIterType;

/**   \brief  type used to iterate CanNm_TxMessageData */
typedef uint8_least CanNm_TxMessageDataIterType;

/** 
  \}
*/ 

/** 
  \defgroup  CanNmPCIterableTypesWithSizeRelations  CanNm Iterable Types With Size Relations (PRE_COMPILE)
  \brief  These type definitions are used to iterate over a VAR based array with the same iterator as the related CONST array.
  \{
*/ 
/**   \brief  type used to iterate CanNm_CommState */
typedef CanNm_ChannelConfigIterType CanNm_CommStateIterType;

/**   \brief  type used to iterate CanNm_CoordReadyToSleepState */
typedef CanNm_ChannelConfigIterType CanNm_CoordReadyToSleepStateIterType;

/**   \brief  type used to iterate CanNm_ImmediateNmMsgCount */
typedef CanNm_ChannelConfigIterType CanNm_ImmediateNmMsgCountIterType;

/**   \brief  type used to iterate CanNm_MsgConfirmationFlag */
typedef CanNm_ChannelConfigIterType CanNm_MsgConfirmationFlagIterType;

/**   \brief  type used to iterate CanNm_MsgIndicationFlag */
typedef CanNm_ChannelConfigIterType CanNm_MsgIndicationFlagIterType;

/**   \brief  type used to iterate CanNm_MsgRequest */
typedef CanNm_ChannelConfigIterType CanNm_MsgRequestIterType;

/**   \brief  type used to iterate CanNm_MsgTimeoutTimer */
typedef CanNm_ChannelConfigIterType CanNm_MsgTimeoutTimerIterType;

/**   \brief  type used to iterate CanNm_MsgTimer */
typedef CanNm_ChannelConfigIterType CanNm_MsgTimerIterType;

/**   \brief  type used to iterate CanNm_NetworkRestartFlag */
typedef CanNm_ChannelConfigIterType CanNm_NetworkRestartFlagIterType;

/**   \brief  type used to iterate CanNm_NmState */
typedef CanNm_ChannelConfigIterType CanNm_NmStateIterType;

/**   \brief  type used to iterate CanNm_PnClusterReq */
typedef CanNm_PnInfoByteConfigIterType CanNm_PnClusterReqIterType;

/**   \brief  type used to iterate CanNm_PnClusterReqNew */
typedef CanNm_PnInfoByteConfigIterType CanNm_PnClusterReqNewIterType;

/**   \brief  type used to iterate CanNm_PnMessageFilterDeactivationIndicated */
typedef CanNm_ChannelConfigIterType CanNm_PnMessageFilterDeactivationIndicatedIterType;

/**   \brief  type used to iterate CanNm_PnMessageFilterEnabled */
typedef CanNm_ChannelConfigIterType CanNm_PnMessageFilterEnabledIterType;

/**   \brief  type used to iterate CanNm_RemoteSleepIndState */
typedef CanNm_ChannelConfigIterType CanNm_RemoteSleepIndStateIterType;

/**   \brief  type used to iterate CanNm_RemoteSleepTimer */
typedef CanNm_ChannelConfigIterType CanNm_RemoteSleepTimerIterType;

/**   \brief  type used to iterate CanNm_RepeatMsgTimer */
typedef CanNm_ChannelConfigIterType CanNm_RepeatMsgTimerIterType;

/**   \brief  type used to iterate CanNm_TimeoutTimer */
typedef CanNm_ChannelConfigIterType CanNm_TimeoutTimerIterType;

/**   \brief  type used to iterate CanNm_TxControlState */
typedef CanNm_ChannelConfigIterType CanNm_TxControlStateIterType;

/**   \brief  type used to iterate CanNm_TxControlStateRequest */
typedef CanNm_ChannelConfigIterType CanNm_TxControlStateRequestIterType;

/**   \brief  type used to iterate CanNm_WaitBusSleepTimer */
typedef CanNm_ChannelConfigIterType CanNm_WaitBusSleepTimerIterType;

/** 
  \}
*/ 

/** 
  \defgroup  CanNmPCValueTypes  CanNm Value Types (PRE_COMPILE)
  \brief  These type definitions are used for value based data representations.
  \{
*/ 
/**   \brief  value based type definition for CanNm_ActiveWakeUpBitEnabledOfChannelConfig */
typedef boolean CanNm_ActiveWakeUpBitEnabledOfChannelConfigType;

/**   \brief  value based type definition for CanNm_AllMessagesKeepAwakeOfChannelConfig */
typedef boolean CanNm_AllMessagesKeepAwakeOfChannelConfigType;

/**   \brief  value based type definition for CanNm_ChannelIdOfChannelConfig */
typedef uint8 CanNm_ChannelIdOfChannelConfigType;

/**   \brief  value based type definition for CanNm_ComControlEnabledOfChannelConfig */
typedef boolean CanNm_ComControlEnabledOfChannelConfigType;

/**   \brief  value based type definition for CanNm_ImmediateNmCycleTimeOfChannelConfig */
typedef uint8 CanNm_ImmediateNmCycleTimeOfChannelConfigType;

/**   \brief  value based type definition for CanNm_ImmediateNmTransmissionsOfChannelConfig */
typedef uint8 CanNm_ImmediateNmTransmissionsOfChannelConfigType;

/**   \brief  value based type definition for CanNm_MsgCycleTimeOfChannelConfig */
typedef uint8 CanNm_MsgCycleTimeOfChannelConfigType;

/**   \brief  value based type definition for CanNm_MsgTimeoutTimeOfChannelConfig */
typedef uint8 CanNm_MsgTimeoutTimeOfChannelConfigType;

/**   \brief  value based type definition for CanNm_PduCbvPositionOfChannelConfig */
typedef uint8 CanNm_PduCbvPositionOfChannelConfigType;

/**   \brief  value based type definition for CanNm_PnHandleMultipleNetworkRequestOfChannelConfig */
typedef boolean CanNm_PnHandleMultipleNetworkRequestOfChannelConfigType;

/**   \brief  value based type definition for CanNm_RemoteSleepIndTimeOfChannelConfig */
typedef uint8 CanNm_RemoteSleepIndTimeOfChannelConfigType;

/**   \brief  value based type definition for CanNm_RepeatMessageTimeOfChannelConfig */
typedef uint16 CanNm_RepeatMessageTimeOfChannelConfigType;

/**   \brief  value based type definition for CanNm_TimeoutTimeOfChannelConfig */
typedef uint8 CanNm_TimeoutTimeOfChannelConfigType;

/**   \brief  value based type definition for CanNm_WaitBusSleepTimeOfChannelConfig */
typedef uint8 CanNm_WaitBusSleepTimeOfChannelConfigType;

/**   \brief  value based type definition for CanNm_CommState */
typedef uint8 CanNm_CommStateType;

/**   \brief  value based type definition for CanNm_CoordReadyToSleepState */
typedef uint8 CanNm_CoordReadyToSleepStateType;

/**   \brief  value based type definition for CanNm_ImmediateNmMsgCount */
typedef uint8 CanNm_ImmediateNmMsgCountType;

/**   \brief  value based type definition for CanNm_ModuleInitialized */
typedef boolean CanNm_ModuleInitializedType;

/**   \brief  value based type definition for CanNm_MsgConfirmationFlag */
typedef boolean CanNm_MsgConfirmationFlagType;

/**   \brief  value based type definition for CanNm_MsgIndicationFlag */
typedef boolean CanNm_MsgIndicationFlagType;

/**   \brief  value based type definition for CanNm_MsgRequest */
typedef uint8 CanNm_MsgRequestType;

/**   \brief  value based type definition for CanNm_MsgTimeoutTimer */
typedef uint16 CanNm_MsgTimeoutTimerType;

/**   \brief  value based type definition for CanNm_MsgTimer */
typedef uint16 CanNm_MsgTimerType;

/**   \brief  value based type definition for CanNm_NetworkRestartFlag */
typedef uint8 CanNm_NetworkRestartFlagType;

/**   \brief  value based type definition for CanNm_NmState */
typedef uint8 CanNm_NmStateType;

/**   \brief  value based type definition for CanNm_MsgCycleOffsetOfPbChannelConfig */
typedef uint8 CanNm_MsgCycleOffsetOfPbChannelConfigType;

/**   \brief  value based type definition for CanNm_PnEnabledOfPbChannelConfig */
typedef boolean CanNm_PnEnabledOfPbChannelConfigType;

/**   \brief  value based type definition for CanNm_TxMessageDataEndIdxOfPbChannelConfig */
typedef uint8 CanNm_TxMessageDataEndIdxOfPbChannelConfigType;

/**   \brief  value based type definition for CanNm_TxMessageDataLengthOfPbChannelConfig */
typedef uint8 CanNm_TxMessageDataLengthOfPbChannelConfigType;

/**   \brief  value based type definition for CanNm_TxMessageDataStartIdxOfPbChannelConfig */
typedef uint8 CanNm_TxMessageDataStartIdxOfPbChannelConfigType;

/**   \brief  value based type definition for CanNm_TxMessageDataUsedOfPbChannelConfig */
typedef boolean CanNm_TxMessageDataUsedOfPbChannelConfigType;

/**   \brief  value based type definition for CanNm_TxMessageData_CBVIdxOfPbChannelConfig */
typedef uint8 CanNm_TxMessageData_CBVIdxOfPbChannelConfigType;

/**   \brief  value based type definition for CanNm_TxMessageData_CBVUsedOfPbChannelConfig */
typedef boolean CanNm_TxMessageData_CBVUsedOfPbChannelConfigType;

/**   \brief  value based type definition for CanNm_TxMessageData_PnFilterMaskEndIdxOfPbChannelConfig */
typedef uint8 CanNm_TxMessageData_PnFilterMaskEndIdxOfPbChannelConfigType;

/**   \brief  value based type definition for CanNm_TxMessageData_PnFilterMaskStartIdxOfPbChannelConfig */
typedef uint8 CanNm_TxMessageData_PnFilterMaskStartIdxOfPbChannelConfigType;

/**   \brief  value based type definition for CanNm_TxMessageData_PnFilterMaskUsedOfPbChannelConfig */
typedef boolean CanNm_TxMessageData_PnFilterMaskUsedOfPbChannelConfigType;

/**   \brief  value based type definition for CanNm_TxMessageData_UserDataEndIdxOfPbChannelConfig */
typedef uint8 CanNm_TxMessageData_UserDataEndIdxOfPbChannelConfigType;

/**   \brief  value based type definition for CanNm_TxMessageData_UserDataLengthOfPbChannelConfig */
typedef uint8 CanNm_TxMessageData_UserDataLengthOfPbChannelConfigType;

/**   \brief  value based type definition for CanNm_TxMessageData_UserDataStartIdxOfPbChannelConfig */
typedef uint8 CanNm_TxMessageData_UserDataStartIdxOfPbChannelConfigType;

/**   \brief  value based type definition for CanNm_TxMessageData_UserDataUsedOfPbChannelConfig */
typedef boolean CanNm_TxMessageData_UserDataUsedOfPbChannelConfigType;

/**   \brief  value based type definition for CanNm_TxPduIdOfPbChannelConfig */
typedef uint8 CanNm_TxPduIdOfPbChannelConfigType;

/**   \brief  value based type definition for CanNm_TxUserDataPduIdOfPbChannelConfig */
typedef uint8 CanNm_TxUserDataPduIdOfPbChannelConfigType;

/**   \brief  value based type definition for CanNm_PnClusterReq */
typedef uint8 CanNm_PnClusterReqType;

/**   \brief  value based type definition for CanNm_PnClusterReqNew */
typedef uint8 CanNm_PnClusterReqNewType;

/**   \brief  value based type definition for CanNm_PnClusterResetTimer */
typedef uint16 CanNm_PnClusterResetTimerType;

/**   \brief  value based type definition for CanNm_PnEiraCalcEnabled */
typedef boolean CanNm_PnEiraCalcEnabledType;

/**   \brief  value based type definition for CanNm_PnEiraRxPduId */
typedef uint8 CanNm_PnEiraRxPduIdType;

/**   \brief  value based type definition for CanNm_PnClusterResetTimerEndIdxOfPnInfoByteConfig */
typedef uint8 CanNm_PnClusterResetTimerEndIdxOfPnInfoByteConfigType;

/**   \brief  value based type definition for CanNm_PnClusterResetTimerStartIdxOfPnInfoByteConfig */
typedef uint8 CanNm_PnClusterResetTimerStartIdxOfPnInfoByteConfigType;

/**   \brief  value based type definition for CanNm_PnClusterResetTimerUsedOfPnInfoByteConfig */
typedef boolean CanNm_PnClusterResetTimerUsedOfPnInfoByteConfigType;

/**   \brief  value based type definition for CanNm_PnFilterMaskOfPnInfoByteConfig */
typedef uint8 CanNm_PnFilterMaskOfPnInfoByteConfigType;

/**   \brief  value based type definition for CanNm_PnInfoLength */
typedef uint8 CanNm_PnInfoLengthType;

/**   \brief  value based type definition for CanNm_PnInfoOffset */
typedef uint8 CanNm_PnInfoOffsetType;

/**   \brief  value based type definition for CanNm_PnMessageFilterDeactivationIndicated */
typedef boolean CanNm_PnMessageFilterDeactivationIndicatedType;

/**   \brief  value based type definition for CanNm_PnMessageFilterEnabled */
typedef boolean CanNm_PnMessageFilterEnabledType;

/**   \brief  value based type definition for CanNm_PnResetTime */
typedef uint8 CanNm_PnResetTimeType;

/**   \brief  value based type definition for CanNm_RemoteSleepIndState */
typedef boolean CanNm_RemoteSleepIndStateType;

/**   \brief  value based type definition for CanNm_RemoteSleepTimer */
typedef uint16 CanNm_RemoteSleepTimerType;

/**   \brief  value based type definition for CanNm_RepeatMsgTimer */
typedef uint16 CanNm_RepeatMsgTimerType;

/**   \brief  value based type definition for CanNm_SizeOfChannelConfig */
typedef uint8 CanNm_SizeOfChannelConfigType;

/**   \brief  value based type definition for CanNm_SizeOfCommState */
typedef uint8 CanNm_SizeOfCommStateType;

/**   \brief  value based type definition for CanNm_SizeOfCoordReadyToSleepState */
typedef uint8 CanNm_SizeOfCoordReadyToSleepStateType;

/**   \brief  value based type definition for CanNm_SizeOfImmediateNmMsgCount */
typedef uint8 CanNm_SizeOfImmediateNmMsgCountType;

/**   \brief  value based type definition for CanNm_SizeOfMsgConfirmationFlag */
typedef uint8 CanNm_SizeOfMsgConfirmationFlagType;

/**   \brief  value based type definition for CanNm_SizeOfMsgIndicationFlag */
typedef uint8 CanNm_SizeOfMsgIndicationFlagType;

/**   \brief  value based type definition for CanNm_SizeOfMsgRequest */
typedef uint8 CanNm_SizeOfMsgRequestType;

/**   \brief  value based type definition for CanNm_SizeOfMsgTimeoutTimer */
typedef uint8 CanNm_SizeOfMsgTimeoutTimerType;

/**   \brief  value based type definition for CanNm_SizeOfMsgTimer */
typedef uint8 CanNm_SizeOfMsgTimerType;

/**   \brief  value based type definition for CanNm_SizeOfNetworkRestartFlag */
typedef uint8 CanNm_SizeOfNetworkRestartFlagType;

/**   \brief  value based type definition for CanNm_SizeOfNmState */
typedef uint8 CanNm_SizeOfNmStateType;

/**   \brief  value based type definition for CanNm_SizeOfPbChannelConfig */
typedef uint8 CanNm_SizeOfPbChannelConfigType;

/**   \brief  value based type definition for CanNm_SizeOfPnClusterReq */
typedef uint8 CanNm_SizeOfPnClusterReqType;

/**   \brief  value based type definition for CanNm_SizeOfPnClusterReqNew */
typedef uint8 CanNm_SizeOfPnClusterReqNewType;

/**   \brief  value based type definition for CanNm_SizeOfPnInfoByteConfig */
typedef uint8 CanNm_SizeOfPnInfoByteConfigType;

/**   \brief  value based type definition for CanNm_SizeOfPnMessageFilterDeactivationIndicated */
typedef uint8 CanNm_SizeOfPnMessageFilterDeactivationIndicatedType;

/**   \brief  value based type definition for CanNm_SizeOfPnMessageFilterEnabled */
typedef uint8 CanNm_SizeOfPnMessageFilterEnabledType;

/**   \brief  value based type definition for CanNm_SizeOfRemoteSleepIndState */
typedef uint8 CanNm_SizeOfRemoteSleepIndStateType;

/**   \brief  value based type definition for CanNm_SizeOfRemoteSleepTimer */
typedef uint8 CanNm_SizeOfRemoteSleepTimerType;

/**   \brief  value based type definition for CanNm_SizeOfRepeatMsgTimer */
typedef uint8 CanNm_SizeOfRepeatMsgTimerType;

/**   \brief  value based type definition for CanNm_SizeOfTimeoutTimer */
typedef uint8 CanNm_SizeOfTimeoutTimerType;

/**   \brief  value based type definition for CanNm_SizeOfTxControlState */
typedef uint8 CanNm_SizeOfTxControlStateType;

/**   \brief  value based type definition for CanNm_SizeOfTxControlStateRequest */
typedef uint8 CanNm_SizeOfTxControlStateRequestType;

/**   \brief  value based type definition for CanNm_SizeOfTxMessageData */
typedef uint8 CanNm_SizeOfTxMessageDataType;

/**   \brief  value based type definition for CanNm_SizeOfWaitBusSleepTimer */
typedef uint8 CanNm_SizeOfWaitBusSleepTimerType;

/**   \brief  value based type definition for CanNm_TimeoutTimer */
typedef uint16 CanNm_TimeoutTimerType;

/**   \brief  value based type definition for CanNm_TxControlState */
typedef uint8 CanNm_TxControlStateType;

/**   \brief  value based type definition for CanNm_TxControlStateRequest */
typedef uint8 CanNm_TxControlStateRequestType;

/**   \brief  value based type definition for CanNm_TxMessageData */
typedef uint8 CanNm_TxMessageDataType;

/**   \brief  value based type definition for CanNm_WaitBusSleepTimer */
typedef uint16 CanNm_WaitBusSleepTimerType;

/** 
  \}
*/ 

/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL COMPLEX DATA TYPES AND STRUCTURES
**********************************************************************************************************************/
/** 
  \defgroup  CanNmPCStructTypes  CanNm Struct Types (PRE_COMPILE)
  \brief  These type definitions are used for structured data representations.
  \{
*/ 
/**   \brief  type used in CanNm_ChannelConfig */
typedef struct sCanNm_ChannelConfigType
{
  CanNm_RepeatMessageTimeOfChannelConfigType RepeatMessageTimeOfChannelConfig;  /**< Timeout for Repeat Message State [ms]. */
  CanNm_ActiveWakeUpBitEnabledOfChannelConfigType ActiveWakeUpBitEnabledOfChannelConfig;  /**< Determines if Active WUP Bit Handling is active or not */
  CanNm_AllMessagesKeepAwakeOfChannelConfigType AllMessagesKeepAwakeOfChannelConfig;  /**< Determines if all NM PDUs are relevant or not */
  CanNm_ComControlEnabledOfChannelConfigType ComControlEnabledOfChannelConfig;  /**< Determines if Com Control is active or not */
  CanNm_PnHandleMultipleNetworkRequestOfChannelConfigType PnHandleMultipleNetworkRequestOfChannelConfig;  /**< Determines whether a call of CanNm_NetworkRequest leads to a transition to Repeat Message from Network Mode */
  CanNm_ChannelIdOfChannelConfigType ChannelIdOfChannelConfig;  /**< Channel ID configured for the respective instance of the NM. */
  CanNm_ImmediateNmCycleTimeOfChannelConfigType ImmediateNmCycleTimeOfChannelConfig;  /**< Fast NM PDU Transmission Time during WUP */
  CanNm_ImmediateNmTransmissionsOfChannelConfigType ImmediateNmTransmissionsOfChannelConfig;  /**< Number of fast NM PDU Transmissions during WUP */
  CanNm_MsgCycleTimeOfChannelConfigType MsgCycleTimeOfChannelConfig;  /**< Period of a NM message [ms]. It determines the periodic rate in the periodic transmission mode. */
  CanNm_MsgTimeoutTimeOfChannelConfigType MsgTimeoutTimeOfChannelConfig;  /**< Transmission Timeout [ms] of NM message. If there is no transmission confirmation by the CAN Interface within this timeout, the CAN NM module shall give an error notification. */
  CanNm_PduCbvPositionOfChannelConfigType PduCbvPositionOfChannelConfig;  /**< Control Bit Vector Position in the PDU */
  CanNm_RemoteSleepIndTimeOfChannelConfigType RemoteSleepIndTimeOfChannelConfig;  /**< Timeout for Remote Sleep Indication [ms]. */
  CanNm_TimeoutTimeOfChannelConfigType TimeoutTimeOfChannelConfig;  /**< Timeout for the NM messages [ms]. */
  CanNm_WaitBusSleepTimeOfChannelConfigType WaitBusSleepTimeOfChannelConfig;  /**< Timeout for bus calm down phase [ms]. */
} CanNm_ChannelConfigType;

/**   \brief  type used in CanNm_PbChannelConfig */
typedef struct sCanNm_PbChannelConfigType
{
  CanNm_PnEnabledOfPbChannelConfigType PnEnabledOfPbChannelConfig;
  CanNm_MsgCycleOffsetOfPbChannelConfigType MsgCycleOffsetOfPbChannelConfig;
  CanNm_TxMessageDataEndIdxOfPbChannelConfigType TxMessageDataEndIdxOfPbChannelConfig;  /**< the end index of the 0:n relation pointing to CanNm_TxMessageData */
  CanNm_TxMessageDataLengthOfPbChannelConfigType TxMessageDataLengthOfPbChannelConfig;  /**< the number of relations pointing to CanNm_TxMessageData */
  CanNm_TxMessageDataStartIdxOfPbChannelConfigType TxMessageDataStartIdxOfPbChannelConfig;  /**< the start index of the 0:n relation pointing to CanNm_TxMessageData */
  CanNm_TxMessageData_CBVIdxOfPbChannelConfigType TxMessageData_CBVIdxOfPbChannelConfig;  /**< the index of the 0:1 relation pointing to CanNm_TxMessageData */
  CanNm_TxMessageData_PnFilterMaskEndIdxOfPbChannelConfigType TxMessageData_PnFilterMaskEndIdxOfPbChannelConfig;  /**< the end index of the 0:n relation pointing to CanNm_TxMessageData */
  CanNm_TxMessageData_PnFilterMaskStartIdxOfPbChannelConfigType TxMessageData_PnFilterMaskStartIdxOfPbChannelConfig;  /**< the start index of the 0:n relation pointing to CanNm_TxMessageData */
  CanNm_TxMessageData_UserDataEndIdxOfPbChannelConfigType TxMessageData_UserDataEndIdxOfPbChannelConfig;  /**< the end index of the 0:n relation pointing to CanNm_TxMessageData */
  CanNm_TxMessageData_UserDataLengthOfPbChannelConfigType TxMessageData_UserDataLengthOfPbChannelConfig;  /**< the number of relations pointing to CanNm_TxMessageData */
  CanNm_TxMessageData_UserDataStartIdxOfPbChannelConfigType TxMessageData_UserDataStartIdxOfPbChannelConfig;  /**< the start index of the 0:n relation pointing to CanNm_TxMessageData */
  CanNm_TxPduIdOfPbChannelConfigType TxPduIdOfPbChannelConfig;
  CanNm_TxUserDataPduIdOfPbChannelConfigType TxUserDataPduIdOfPbChannelConfig;
} CanNm_PbChannelConfigType;

/**   \brief  type used in CanNm_PnInfoByteConfig */
typedef struct sCanNm_PnInfoByteConfigType
{
  CanNm_PnClusterResetTimerEndIdxOfPnInfoByteConfigType PnClusterResetTimerEndIdxOfPnInfoByteConfig;  /**< the end index of the 0:n relation pointing to CanNm_PnClusterResetTimer */
  CanNm_PnClusterResetTimerStartIdxOfPnInfoByteConfigType PnClusterResetTimerStartIdxOfPnInfoByteConfig;  /**< the start index of the 0:n relation pointing to CanNm_PnClusterResetTimer */
  CanNm_PnFilterMaskOfPnInfoByteConfigType PnFilterMaskOfPnInfoByteConfig;  /**< PnFilterMask for PnInfoBytes */
} CanNm_PnInfoByteConfigType;

/** 
  \}
*/ 

/** 
  \defgroup  CanNmPCSymbolicStructTypes  CanNm Symbolic Struct Types (PRE_COMPILE)
  \brief  These structs are used in unions to have a symbol based data representation style.
  \{
*/ 
/**   \brief  type to be used as symbolic data element access to CanNm_CommState in the predefined variant Left */
typedef struct CanNm_CommStateLeftStructSTag
{
  CanNm_CommStateType RBTM_FL_BODY3_8uqv9blm85ehm0msat385m76v_03d5f5f6;
} CanNm_CommStateLeftStructSType;

/**   \brief  type to be used as symbolic data element access to CanNm_CommState in the predefined variant Right */
typedef struct CanNm_CommStateRightStructSTag
{
  CanNm_CommStateType RBTM_FR_BODY3_4xwwtd59665s787n6ctawh7k8_23a94727;
} CanNm_CommStateRightStructSType;

/**   \brief  type to be used as symbolic data element access to CanNm_CoordReadyToSleepState in the predefined variant Left */
typedef struct CanNm_CoordReadyToSleepStateLeftStructSTag
{
  CanNm_CoordReadyToSleepStateType RBTM_FL_BODY3_8uqv9blm85ehm0msat385m76v_03d5f5f6;
} CanNm_CoordReadyToSleepStateLeftStructSType;

/**   \brief  type to be used as symbolic data element access to CanNm_CoordReadyToSleepState in the predefined variant Right */
typedef struct CanNm_CoordReadyToSleepStateRightStructSTag
{
  CanNm_CoordReadyToSleepStateType RBTM_FR_BODY3_4xwwtd59665s787n6ctawh7k8_23a94727;
} CanNm_CoordReadyToSleepStateRightStructSType;

/**   \brief  type to be used as symbolic data element access to CanNm_ImmediateNmMsgCount in the predefined variant Left */
typedef struct CanNm_ImmediateNmMsgCountLeftStructSTag
{
  CanNm_ImmediateNmMsgCountType RBTM_FL_BODY3_8uqv9blm85ehm0msat385m76v_03d5f5f6;
} CanNm_ImmediateNmMsgCountLeftStructSType;

/**   \brief  type to be used as symbolic data element access to CanNm_ImmediateNmMsgCount in the predefined variant Right */
typedef struct CanNm_ImmediateNmMsgCountRightStructSTag
{
  CanNm_ImmediateNmMsgCountType RBTM_FR_BODY3_4xwwtd59665s787n6ctawh7k8_23a94727;
} CanNm_ImmediateNmMsgCountRightStructSType;

/**   \brief  type to be used as symbolic data element access to CanNm_MsgConfirmationFlag in the predefined variant Left */
typedef struct CanNm_MsgConfirmationFlagLeftStructSTag
{
  CanNm_MsgConfirmationFlagType RBTM_FL_BODY3_8uqv9blm85ehm0msat385m76v_03d5f5f6;
} CanNm_MsgConfirmationFlagLeftStructSType;

/**   \brief  type to be used as symbolic data element access to CanNm_MsgConfirmationFlag in the predefined variant Right */
typedef struct CanNm_MsgConfirmationFlagRightStructSTag
{
  CanNm_MsgConfirmationFlagType RBTM_FR_BODY3_4xwwtd59665s787n6ctawh7k8_23a94727;
} CanNm_MsgConfirmationFlagRightStructSType;

/**   \brief  type to be used as symbolic data element access to CanNm_MsgIndicationFlag in the predefined variant Left */
typedef struct CanNm_MsgIndicationFlagLeftStructSTag
{
  CanNm_MsgIndicationFlagType RBTM_FL_BODY3_8uqv9blm85ehm0msat385m76v_03d5f5f6;
} CanNm_MsgIndicationFlagLeftStructSType;

/**   \brief  type to be used as symbolic data element access to CanNm_MsgIndicationFlag in the predefined variant Right */
typedef struct CanNm_MsgIndicationFlagRightStructSTag
{
  CanNm_MsgIndicationFlagType RBTM_FR_BODY3_4xwwtd59665s787n6ctawh7k8_23a94727;
} CanNm_MsgIndicationFlagRightStructSType;

/**   \brief  type to be used as symbolic data element access to CanNm_MsgRequest in the predefined variant Left */
typedef struct CanNm_MsgRequestLeftStructSTag
{
  CanNm_MsgRequestType RBTM_FL_BODY3_8uqv9blm85ehm0msat385m76v_03d5f5f6;
} CanNm_MsgRequestLeftStructSType;

/**   \brief  type to be used as symbolic data element access to CanNm_MsgRequest in the predefined variant Right */
typedef struct CanNm_MsgRequestRightStructSTag
{
  CanNm_MsgRequestType RBTM_FR_BODY3_4xwwtd59665s787n6ctawh7k8_23a94727;
} CanNm_MsgRequestRightStructSType;

/**   \brief  type to be used as symbolic data element access to CanNm_MsgTimeoutTimer in the predefined variant Left */
typedef struct CanNm_MsgTimeoutTimerLeftStructSTag
{
  CanNm_MsgTimeoutTimerType RBTM_FL_BODY3_8uqv9blm85ehm0msat385m76v_03d5f5f6;
} CanNm_MsgTimeoutTimerLeftStructSType;

/**   \brief  type to be used as symbolic data element access to CanNm_MsgTimeoutTimer in the predefined variant Right */
typedef struct CanNm_MsgTimeoutTimerRightStructSTag
{
  CanNm_MsgTimeoutTimerType RBTM_FR_BODY3_4xwwtd59665s787n6ctawh7k8_23a94727;
} CanNm_MsgTimeoutTimerRightStructSType;

/**   \brief  type to be used as symbolic data element access to CanNm_MsgTimer in the predefined variant Left */
typedef struct CanNm_MsgTimerLeftStructSTag
{
  CanNm_MsgTimerType RBTM_FL_BODY3_8uqv9blm85ehm0msat385m76v_03d5f5f6;
} CanNm_MsgTimerLeftStructSType;

/**   \brief  type to be used as symbolic data element access to CanNm_MsgTimer in the predefined variant Right */
typedef struct CanNm_MsgTimerRightStructSTag
{
  CanNm_MsgTimerType RBTM_FR_BODY3_4xwwtd59665s787n6ctawh7k8_23a94727;
} CanNm_MsgTimerRightStructSType;

/**   \brief  type to be used as symbolic data element access to CanNm_NetworkRestartFlag in the predefined variant Left */
typedef struct CanNm_NetworkRestartFlagLeftStructSTag
{
  CanNm_NetworkRestartFlagType RBTM_FL_BODY3_8uqv9blm85ehm0msat385m76v_03d5f5f6;
} CanNm_NetworkRestartFlagLeftStructSType;

/**   \brief  type to be used as symbolic data element access to CanNm_NetworkRestartFlag in the predefined variant Right */
typedef struct CanNm_NetworkRestartFlagRightStructSTag
{
  CanNm_NetworkRestartFlagType RBTM_FR_BODY3_4xwwtd59665s787n6ctawh7k8_23a94727;
} CanNm_NetworkRestartFlagRightStructSType;

/**   \brief  type to be used as symbolic data element access to CanNm_NmState in the predefined variant Left */
typedef struct CanNm_NmStateLeftStructSTag
{
  CanNm_NmStateType RBTM_FL_BODY3_8uqv9blm85ehm0msat385m76v_03d5f5f6;
} CanNm_NmStateLeftStructSType;

/**   \brief  type to be used as symbolic data element access to CanNm_NmState in the predefined variant Right */
typedef struct CanNm_NmStateRightStructSTag
{
  CanNm_NmStateType RBTM_FR_BODY3_4xwwtd59665s787n6ctawh7k8_23a94727;
} CanNm_NmStateRightStructSType;

/**   \brief  type to be used as symbolic data element access to CanNm_PnClusterReq in the predefined variant Left */
typedef struct CanNm_PnClusterReqLeftStructSTag
{
  CanNm_PnClusterReqType CanNmPnFilterMaskByte_2;
  CanNm_PnClusterReqType CanNmPnFilterMaskByte_3;
  CanNm_PnClusterReqType CanNmPnFilterMaskByte_4;
  CanNm_PnClusterReqType CanNmPnFilterMaskByte_5;
  CanNm_PnClusterReqType CanNmPnFilterMaskByte_0;
  CanNm_PnClusterReqType CanNmPnFilterMaskByte_1;
  CanNm_PnClusterReqType CanNmPnFilterMaskByte_6;
} CanNm_PnClusterReqLeftStructSType;

/**   \brief  type to be used as symbolic data element access to CanNm_PnClusterReq in the predefined variant Right */
typedef struct CanNm_PnClusterReqRightStructSTag
{
  CanNm_PnClusterReqType CanNmPnFilterMaskByte_2;
  CanNm_PnClusterReqType CanNmPnFilterMaskByte_3;
  CanNm_PnClusterReqType CanNmPnFilterMaskByte_4;
  CanNm_PnClusterReqType CanNmPnFilterMaskByte_5;
  CanNm_PnClusterReqType CanNmPnFilterMaskByte_0;
  CanNm_PnClusterReqType CanNmPnFilterMaskByte_1;
  CanNm_PnClusterReqType CanNmPnFilterMaskByte_6;
} CanNm_PnClusterReqRightStructSType;

/**   \brief  type to be used as symbolic data element access to CanNm_PnClusterReqNew in the predefined variant Left */
typedef struct CanNm_PnClusterReqNewLeftStructSTag
{
  CanNm_PnClusterReqNewType CanNmPnFilterMaskByte_2;
  CanNm_PnClusterReqNewType CanNmPnFilterMaskByte_3;
  CanNm_PnClusterReqNewType CanNmPnFilterMaskByte_4;
  CanNm_PnClusterReqNewType CanNmPnFilterMaskByte_5;
  CanNm_PnClusterReqNewType CanNmPnFilterMaskByte_0;
  CanNm_PnClusterReqNewType CanNmPnFilterMaskByte_1;
  CanNm_PnClusterReqNewType CanNmPnFilterMaskByte_6;
} CanNm_PnClusterReqNewLeftStructSType;

/**   \brief  type to be used as symbolic data element access to CanNm_PnClusterReqNew in the predefined variant Right */
typedef struct CanNm_PnClusterReqNewRightStructSTag
{
  CanNm_PnClusterReqNewType CanNmPnFilterMaskByte_2;
  CanNm_PnClusterReqNewType CanNmPnFilterMaskByte_3;
  CanNm_PnClusterReqNewType CanNmPnFilterMaskByte_4;
  CanNm_PnClusterReqNewType CanNmPnFilterMaskByte_5;
  CanNm_PnClusterReqNewType CanNmPnFilterMaskByte_0;
  CanNm_PnClusterReqNewType CanNmPnFilterMaskByte_1;
  CanNm_PnClusterReqNewType CanNmPnFilterMaskByte_6;
} CanNm_PnClusterReqNewRightStructSType;

/**   \brief  type to be used as symbolic data element access to CanNm_PnClusterResetTimer in the predefined variant Left */
typedef struct CanNm_PnClusterResetTimerLeftStructSTag
{
  CanNm_PnClusterResetTimerType CanNmPnFilterMaskByte_2[8];
  CanNm_PnClusterResetTimerType CanNmPnFilterMaskByte_3[8];
  CanNm_PnClusterResetTimerType CanNmPnFilterMaskByte_4[8];
  CanNm_PnClusterResetTimerType CanNmPnFilterMaskByte_5[8];
  CanNm_PnClusterResetTimerType CanNmPnFilterMaskByte_0[8];
  CanNm_PnClusterResetTimerType CanNmPnFilterMaskByte_1[8];
  CanNm_PnClusterResetTimerType CanNmPnFilterMaskByte_6[8];
} CanNm_PnClusterResetTimerLeftStructSType;

/**   \brief  type to be used as symbolic data element access to CanNm_PnClusterResetTimer in the predefined variant Right */
typedef struct CanNm_PnClusterResetTimerRightStructSTag
{
  CanNm_PnClusterResetTimerType CanNmPnFilterMaskByte_2[8];
  CanNm_PnClusterResetTimerType CanNmPnFilterMaskByte_3[8];
  CanNm_PnClusterResetTimerType CanNmPnFilterMaskByte_4[8];
  CanNm_PnClusterResetTimerType CanNmPnFilterMaskByte_5[8];
  CanNm_PnClusterResetTimerType CanNmPnFilterMaskByte_0[8];
  CanNm_PnClusterResetTimerType CanNmPnFilterMaskByte_1[8];
  CanNm_PnClusterResetTimerType CanNmPnFilterMaskByte_6[8];
} CanNm_PnClusterResetTimerRightStructSType;

/**   \brief  type to be used as symbolic data element access to CanNm_PnMessageFilterDeactivationIndicated in the predefined variant Left */
typedef struct CanNm_PnMessageFilterDeactivationIndicatedLeftStructSTag
{
  CanNm_PnMessageFilterDeactivationIndicatedType RBTM_FL_BODY3_8uqv9blm85ehm0msat385m76v_03d5f5f6;
} CanNm_PnMessageFilterDeactivationIndicatedLeftStructSType;

/**   \brief  type to be used as symbolic data element access to CanNm_PnMessageFilterDeactivationIndicated in the predefined variant Right */
typedef struct CanNm_PnMessageFilterDeactivationIndicatedRightStructSTag
{
  CanNm_PnMessageFilterDeactivationIndicatedType RBTM_FR_BODY3_4xwwtd59665s787n6ctawh7k8_23a94727;
} CanNm_PnMessageFilterDeactivationIndicatedRightStructSType;

/**   \brief  type to be used as symbolic data element access to CanNm_PnMessageFilterEnabled in the predefined variant Left */
typedef struct CanNm_PnMessageFilterEnabledLeftStructSTag
{
  CanNm_PnMessageFilterEnabledType RBTM_FL_BODY3_8uqv9blm85ehm0msat385m76v_03d5f5f6;
} CanNm_PnMessageFilterEnabledLeftStructSType;

/**   \brief  type to be used as symbolic data element access to CanNm_PnMessageFilterEnabled in the predefined variant Right */
typedef struct CanNm_PnMessageFilterEnabledRightStructSTag
{
  CanNm_PnMessageFilterEnabledType RBTM_FR_BODY3_4xwwtd59665s787n6ctawh7k8_23a94727;
} CanNm_PnMessageFilterEnabledRightStructSType;

/**   \brief  type to be used as symbolic data element access to CanNm_RemoteSleepIndState in the predefined variant Left */
typedef struct CanNm_RemoteSleepIndStateLeftStructSTag
{
  CanNm_RemoteSleepIndStateType RBTM_FL_BODY3_8uqv9blm85ehm0msat385m76v_03d5f5f6;
} CanNm_RemoteSleepIndStateLeftStructSType;

/**   \brief  type to be used as symbolic data element access to CanNm_RemoteSleepIndState in the predefined variant Right */
typedef struct CanNm_RemoteSleepIndStateRightStructSTag
{
  CanNm_RemoteSleepIndStateType RBTM_FR_BODY3_4xwwtd59665s787n6ctawh7k8_23a94727;
} CanNm_RemoteSleepIndStateRightStructSType;

/**   \brief  type to be used as symbolic data element access to CanNm_RemoteSleepTimer in the predefined variant Left */
typedef struct CanNm_RemoteSleepTimerLeftStructSTag
{
  CanNm_RemoteSleepTimerType RBTM_FL_BODY3_8uqv9blm85ehm0msat385m76v_03d5f5f6;
} CanNm_RemoteSleepTimerLeftStructSType;

/**   \brief  type to be used as symbolic data element access to CanNm_RemoteSleepTimer in the predefined variant Right */
typedef struct CanNm_RemoteSleepTimerRightStructSTag
{
  CanNm_RemoteSleepTimerType RBTM_FR_BODY3_4xwwtd59665s787n6ctawh7k8_23a94727;
} CanNm_RemoteSleepTimerRightStructSType;

/**   \brief  type to be used as symbolic data element access to CanNm_RepeatMsgTimer in the predefined variant Left */
typedef struct CanNm_RepeatMsgTimerLeftStructSTag
{
  CanNm_RepeatMsgTimerType RBTM_FL_BODY3_8uqv9blm85ehm0msat385m76v_03d5f5f6;
} CanNm_RepeatMsgTimerLeftStructSType;

/**   \brief  type to be used as symbolic data element access to CanNm_RepeatMsgTimer in the predefined variant Right */
typedef struct CanNm_RepeatMsgTimerRightStructSTag
{
  CanNm_RepeatMsgTimerType RBTM_FR_BODY3_4xwwtd59665s787n6ctawh7k8_23a94727;
} CanNm_RepeatMsgTimerRightStructSType;

/**   \brief  type to be used as symbolic data element access to CanNm_TimeoutTimer in the predefined variant Left */
typedef struct CanNm_TimeoutTimerLeftStructSTag
{
  CanNm_TimeoutTimerType RBTM_FL_BODY3_8uqv9blm85ehm0msat385m76v_03d5f5f6;
} CanNm_TimeoutTimerLeftStructSType;

/**   \brief  type to be used as symbolic data element access to CanNm_TimeoutTimer in the predefined variant Right */
typedef struct CanNm_TimeoutTimerRightStructSTag
{
  CanNm_TimeoutTimerType RBTM_FR_BODY3_4xwwtd59665s787n6ctawh7k8_23a94727;
} CanNm_TimeoutTimerRightStructSType;

/**   \brief  type to be used as symbolic data element access to CanNm_TxControlState in the predefined variant Left */
typedef struct CanNm_TxControlStateLeftStructSTag
{
  CanNm_TxControlStateType RBTM_FL_BODY3_8uqv9blm85ehm0msat385m76v_03d5f5f6;
} CanNm_TxControlStateLeftStructSType;

/**   \brief  type to be used as symbolic data element access to CanNm_TxControlState in the predefined variant Right */
typedef struct CanNm_TxControlStateRightStructSTag
{
  CanNm_TxControlStateType RBTM_FR_BODY3_4xwwtd59665s787n6ctawh7k8_23a94727;
} CanNm_TxControlStateRightStructSType;

/**   \brief  type to be used as symbolic data element access to CanNm_TxControlStateRequest in the predefined variant Left */
typedef struct CanNm_TxControlStateRequestLeftStructSTag
{
  CanNm_TxControlStateRequestType RBTM_FL_BODY3_8uqv9blm85ehm0msat385m76v_03d5f5f6;
} CanNm_TxControlStateRequestLeftStructSType;

/**   \brief  type to be used as symbolic data element access to CanNm_TxControlStateRequest in the predefined variant Right */
typedef struct CanNm_TxControlStateRequestRightStructSTag
{
  CanNm_TxControlStateRequestType RBTM_FR_BODY3_4xwwtd59665s787n6ctawh7k8_23a94727;
} CanNm_TxControlStateRequestRightStructSType;

/**   \brief  type to be used as symbolic data element access to CanNm_WaitBusSleepTimer in the predefined variant Left */
typedef struct CanNm_WaitBusSleepTimerLeftStructSTag
{
  CanNm_WaitBusSleepTimerType RBTM_FL_BODY3_8uqv9blm85ehm0msat385m76v_03d5f5f6;
} CanNm_WaitBusSleepTimerLeftStructSType;

/**   \brief  type to be used as symbolic data element access to CanNm_WaitBusSleepTimer in the predefined variant Right */
typedef struct CanNm_WaitBusSleepTimerRightStructSTag
{
  CanNm_WaitBusSleepTimerType RBTM_FR_BODY3_4xwwtd59665s787n6ctawh7k8_23a94727;
} CanNm_WaitBusSleepTimerRightStructSType;

/** 
  \}
*/ 

/** 
  \defgroup  CanNmPCUnionIndexAndSymbolTypes  CanNm Union Index And Symbol Types (PRE_COMPILE)
  \brief  These unions are used to access arrays in an index and symbol based style.
  \{
*/ 
/**   \brief  type to access CanNm_CommState in an index and symbol based style. */
typedef union CanNm_CommStateUTag
{  /* PRQA S 0750 */  /* MD_CSL_Union */
  CanNm_CommStateType raw[1];
  CanNm_CommStateLeftStructSType strLeft;
  CanNm_CommStateRightStructSType strRight;
} CanNm_CommStateUType;

/**   \brief  type to access CanNm_CoordReadyToSleepState in an index and symbol based style. */
typedef union CanNm_CoordReadyToSleepStateUTag
{  /* PRQA S 0750 */  /* MD_CSL_Union */
  CanNm_CoordReadyToSleepStateType raw[1];
  CanNm_CoordReadyToSleepStateLeftStructSType strLeft;
  CanNm_CoordReadyToSleepStateRightStructSType strRight;
} CanNm_CoordReadyToSleepStateUType;

/**   \brief  type to access CanNm_ImmediateNmMsgCount in an index and symbol based style. */
typedef union CanNm_ImmediateNmMsgCountUTag
{  /* PRQA S 0750 */  /* MD_CSL_Union */
  CanNm_ImmediateNmMsgCountType raw[1];
  CanNm_ImmediateNmMsgCountLeftStructSType strLeft;
  CanNm_ImmediateNmMsgCountRightStructSType strRight;
} CanNm_ImmediateNmMsgCountUType;

/**   \brief  type to access CanNm_MsgConfirmationFlag in an index and symbol based style. */
typedef union CanNm_MsgConfirmationFlagUTag
{  /* PRQA S 0750 */  /* MD_CSL_Union */
  CanNm_MsgConfirmationFlagType raw[1];
  CanNm_MsgConfirmationFlagLeftStructSType strLeft;
  CanNm_MsgConfirmationFlagRightStructSType strRight;
} CanNm_MsgConfirmationFlagUType;

/**   \brief  type to access CanNm_MsgIndicationFlag in an index and symbol based style. */
typedef union CanNm_MsgIndicationFlagUTag
{  /* PRQA S 0750 */  /* MD_CSL_Union */
  CanNm_MsgIndicationFlagType raw[1];
  CanNm_MsgIndicationFlagLeftStructSType strLeft;
  CanNm_MsgIndicationFlagRightStructSType strRight;
} CanNm_MsgIndicationFlagUType;

/**   \brief  type to access CanNm_MsgRequest in an index and symbol based style. */
typedef union CanNm_MsgRequestUTag
{  /* PRQA S 0750 */  /* MD_CSL_Union */
  CanNm_MsgRequestType raw[1];
  CanNm_MsgRequestLeftStructSType strLeft;
  CanNm_MsgRequestRightStructSType strRight;
} CanNm_MsgRequestUType;

/**   \brief  type to access CanNm_MsgTimeoutTimer in an index and symbol based style. */
typedef union CanNm_MsgTimeoutTimerUTag
{  /* PRQA S 0750 */  /* MD_CSL_Union */
  CanNm_MsgTimeoutTimerType raw[1];
  CanNm_MsgTimeoutTimerLeftStructSType strLeft;
  CanNm_MsgTimeoutTimerRightStructSType strRight;
} CanNm_MsgTimeoutTimerUType;

/**   \brief  type to access CanNm_MsgTimer in an index and symbol based style. */
typedef union CanNm_MsgTimerUTag
{  /* PRQA S 0750 */  /* MD_CSL_Union */
  CanNm_MsgTimerType raw[1];
  CanNm_MsgTimerLeftStructSType strLeft;
  CanNm_MsgTimerRightStructSType strRight;
} CanNm_MsgTimerUType;

/**   \brief  type to access CanNm_NetworkRestartFlag in an index and symbol based style. */
typedef union CanNm_NetworkRestartFlagUTag
{  /* PRQA S 0750 */  /* MD_CSL_Union */
  CanNm_NetworkRestartFlagType raw[1];
  CanNm_NetworkRestartFlagLeftStructSType strLeft;
  CanNm_NetworkRestartFlagRightStructSType strRight;
} CanNm_NetworkRestartFlagUType;

/**   \brief  type to access CanNm_NmState in an index and symbol based style. */
typedef union CanNm_NmStateUTag
{  /* PRQA S 0750 */  /* MD_CSL_Union */
  CanNm_NmStateType raw[1];
  CanNm_NmStateLeftStructSType strLeft;
  CanNm_NmStateRightStructSType strRight;
} CanNm_NmStateUType;

/**   \brief  type to access CanNm_PnClusterReq in an index and symbol based style. */
typedef union CanNm_PnClusterReqUTag
{  /* PRQA S 0750 */  /* MD_CSL_Union */
  CanNm_PnClusterReqType raw[7];
  CanNm_PnClusterReqLeftStructSType strLeft;
  CanNm_PnClusterReqRightStructSType strRight;
} CanNm_PnClusterReqUType;

/**   \brief  type to access CanNm_PnClusterReqNew in an index and symbol based style. */
typedef union CanNm_PnClusterReqNewUTag
{  /* PRQA S 0750 */  /* MD_CSL_Union */
  CanNm_PnClusterReqNewType raw[7];
  CanNm_PnClusterReqNewLeftStructSType strLeft;
  CanNm_PnClusterReqNewRightStructSType strRight;
} CanNm_PnClusterReqNewUType;

/**   \brief  type to access CanNm_PnClusterResetTimer in an index and symbol based style. */
typedef union CanNm_PnClusterResetTimerUTag
{  /* PRQA S 0750 */  /* MD_CSL_Union */
  CanNm_PnClusterResetTimerType raw[56];
  CanNm_PnClusterResetTimerLeftStructSType strLeft;
  CanNm_PnClusterResetTimerRightStructSType strRight;
} CanNm_PnClusterResetTimerUType;

/**   \brief  type to access CanNm_PnMessageFilterDeactivationIndicated in an index and symbol based style. */
typedef union CanNm_PnMessageFilterDeactivationIndicatedUTag
{  /* PRQA S 0750 */  /* MD_CSL_Union */
  CanNm_PnMessageFilterDeactivationIndicatedType raw[1];
  CanNm_PnMessageFilterDeactivationIndicatedLeftStructSType strLeft;
  CanNm_PnMessageFilterDeactivationIndicatedRightStructSType strRight;
} CanNm_PnMessageFilterDeactivationIndicatedUType;

/**   \brief  type to access CanNm_PnMessageFilterEnabled in an index and symbol based style. */
typedef union CanNm_PnMessageFilterEnabledUTag
{  /* PRQA S 0750 */  /* MD_CSL_Union */
  CanNm_PnMessageFilterEnabledType raw[1];
  CanNm_PnMessageFilterEnabledLeftStructSType strLeft;
  CanNm_PnMessageFilterEnabledRightStructSType strRight;
} CanNm_PnMessageFilterEnabledUType;

/**   \brief  type to access CanNm_RemoteSleepIndState in an index and symbol based style. */
typedef union CanNm_RemoteSleepIndStateUTag
{  /* PRQA S 0750 */  /* MD_CSL_Union */
  CanNm_RemoteSleepIndStateType raw[1];
  CanNm_RemoteSleepIndStateLeftStructSType strLeft;
  CanNm_RemoteSleepIndStateRightStructSType strRight;
} CanNm_RemoteSleepIndStateUType;

/**   \brief  type to access CanNm_RemoteSleepTimer in an index and symbol based style. */
typedef union CanNm_RemoteSleepTimerUTag
{  /* PRQA S 0750 */  /* MD_CSL_Union */
  CanNm_RemoteSleepTimerType raw[1];
  CanNm_RemoteSleepTimerLeftStructSType strLeft;
  CanNm_RemoteSleepTimerRightStructSType strRight;
} CanNm_RemoteSleepTimerUType;

/**   \brief  type to access CanNm_RepeatMsgTimer in an index and symbol based style. */
typedef union CanNm_RepeatMsgTimerUTag
{  /* PRQA S 0750 */  /* MD_CSL_Union */
  CanNm_RepeatMsgTimerType raw[1];
  CanNm_RepeatMsgTimerLeftStructSType strLeft;
  CanNm_RepeatMsgTimerRightStructSType strRight;
} CanNm_RepeatMsgTimerUType;

/**   \brief  type to access CanNm_TimeoutTimer in an index and symbol based style. */
typedef union CanNm_TimeoutTimerUTag
{  /* PRQA S 0750 */  /* MD_CSL_Union */
  CanNm_TimeoutTimerType raw[1];
  CanNm_TimeoutTimerLeftStructSType strLeft;
  CanNm_TimeoutTimerRightStructSType strRight;
} CanNm_TimeoutTimerUType;

/**   \brief  type to access CanNm_TxControlState in an index and symbol based style. */
typedef union CanNm_TxControlStateUTag
{  /* PRQA S 0750 */  /* MD_CSL_Union */
  CanNm_TxControlStateType raw[1];
  CanNm_TxControlStateLeftStructSType strLeft;
  CanNm_TxControlStateRightStructSType strRight;
} CanNm_TxControlStateUType;

/**   \brief  type to access CanNm_TxControlStateRequest in an index and symbol based style. */
typedef union CanNm_TxControlStateRequestUTag
{  /* PRQA S 0750 */  /* MD_CSL_Union */
  CanNm_TxControlStateRequestType raw[1];
  CanNm_TxControlStateRequestLeftStructSType strLeft;
  CanNm_TxControlStateRequestRightStructSType strRight;
} CanNm_TxControlStateRequestUType;

/**   \brief  type to access CanNm_WaitBusSleepTimer in an index and symbol based style. */
typedef union CanNm_WaitBusSleepTimerUTag
{  /* PRQA S 0750 */  /* MD_CSL_Union */
  CanNm_WaitBusSleepTimerType raw[1];
  CanNm_WaitBusSleepTimerLeftStructSType strLeft;
  CanNm_WaitBusSleepTimerRightStructSType strRight;
} CanNm_WaitBusSleepTimerUType;

/** 
  \}
*/ 

/** 
  \defgroup  CanNmPCRootPointerTypes  CanNm Root Pointer Types (PRE_COMPILE)
  \brief  These type definitions are used to point from the config root to symbol instances.
  \{
*/ 
/**   \brief  type used to point to CanNm_ChannelConfig */
typedef P2CONST(CanNm_ChannelConfigType, TYPEDEF, CANNM_CONST) CanNm_ChannelConfigPtrType;

/**   \brief  type used to point to CanNm_CommState */
typedef P2VAR(CanNm_CommStateType, TYPEDEF, CANNM_VAR_NOINIT) CanNm_CommStatePtrType;

/**   \brief  type used to point to CanNm_CoordReadyToSleepState */
typedef P2VAR(CanNm_CoordReadyToSleepStateType, TYPEDEF, CANNM_VAR_NOINIT) CanNm_CoordReadyToSleepStatePtrType;

/**   \brief  type used to point to CanNm_ImmediateNmMsgCount */
typedef P2VAR(CanNm_ImmediateNmMsgCountType, TYPEDEF, CANNM_VAR_NOINIT) CanNm_ImmediateNmMsgCountPtrType;

/**   \brief  type used to point to CanNm_ModuleInitialized */
typedef P2VAR(CanNm_ModuleInitializedType, TYPEDEF, CANNM_VAR_ZERO_INIT) CanNm_ModuleInitializedPtrType;

/**   \brief  type used to point to CanNm_MsgConfirmationFlag */
typedef P2VAR(CanNm_MsgConfirmationFlagType, TYPEDEF, CANNM_VAR_NOINIT) CanNm_MsgConfirmationFlagPtrType;

/**   \brief  type used to point to CanNm_MsgIndicationFlag */
typedef P2VAR(CanNm_MsgIndicationFlagType, TYPEDEF, CANNM_VAR_NOINIT) CanNm_MsgIndicationFlagPtrType;

/**   \brief  type used to point to CanNm_MsgRequest */
typedef P2VAR(CanNm_MsgRequestType, TYPEDEF, CANNM_VAR_NOINIT) CanNm_MsgRequestPtrType;

/**   \brief  type used to point to CanNm_MsgTimeoutTimer */
typedef P2VAR(CanNm_MsgTimeoutTimerType, TYPEDEF, CANNM_VAR_NOINIT) CanNm_MsgTimeoutTimerPtrType;

/**   \brief  type used to point to CanNm_MsgTimer */
typedef P2VAR(CanNm_MsgTimerType, TYPEDEF, CANNM_VAR_NOINIT) CanNm_MsgTimerPtrType;

/**   \brief  type used to point to CanNm_NetworkRestartFlag */
typedef P2VAR(CanNm_NetworkRestartFlagType, TYPEDEF, CANNM_VAR_NOINIT) CanNm_NetworkRestartFlagPtrType;

/**   \brief  type used to point to CanNm_NmState */
typedef P2VAR(CanNm_NmStateType, TYPEDEF, CANNM_VAR_NOINIT) CanNm_NmStatePtrType;

/**   \brief  type used to point to CanNm_PbChannelConfig */
typedef P2CONST(CanNm_PbChannelConfigType, TYPEDEF, CANNM_CONST) CanNm_PbChannelConfigPtrType;

/**   \brief  type used to point to CanNm_PnClusterReq */
typedef P2VAR(CanNm_PnClusterReqType, TYPEDEF, CANNM_VAR_NOINIT) CanNm_PnClusterReqPtrType;

/**   \brief  type used to point to CanNm_PnClusterReqNew */
typedef P2VAR(CanNm_PnClusterReqNewType, TYPEDEF, CANNM_VAR_NOINIT) CanNm_PnClusterReqNewPtrType;

/**   \brief  type used to point to CanNm_PnClusterResetTimer */
typedef P2VAR(CanNm_PnClusterResetTimerType, TYPEDEF, CANNM_VAR_NOINIT) CanNm_PnClusterResetTimerPtrType;

/**   \brief  type used to point to CanNm_PnInfoByteConfig */
typedef P2CONST(CanNm_PnInfoByteConfigType, TYPEDEF, CANNM_CONST) CanNm_PnInfoByteConfigPtrType;

/**   \brief  type used to point to CanNm_PnMessageFilterDeactivationIndicated */
typedef P2VAR(CanNm_PnMessageFilterDeactivationIndicatedType, TYPEDEF, CANNM_VAR_NOINIT) CanNm_PnMessageFilterDeactivationIndicatedPtrType;

/**   \brief  type used to point to CanNm_PnMessageFilterEnabled */
typedef P2VAR(CanNm_PnMessageFilterEnabledType, TYPEDEF, CANNM_VAR_NOINIT) CanNm_PnMessageFilterEnabledPtrType;

/**   \brief  type used to point to CanNm_RemoteSleepIndState */
typedef P2VAR(CanNm_RemoteSleepIndStateType, TYPEDEF, CANNM_VAR_NOINIT) CanNm_RemoteSleepIndStatePtrType;

/**   \brief  type used to point to CanNm_RemoteSleepTimer */
typedef P2VAR(CanNm_RemoteSleepTimerType, TYPEDEF, CANNM_VAR_NOINIT) CanNm_RemoteSleepTimerPtrType;

/**   \brief  type used to point to CanNm_RepeatMsgTimer */
typedef P2VAR(CanNm_RepeatMsgTimerType, TYPEDEF, CANNM_VAR_NOINIT) CanNm_RepeatMsgTimerPtrType;

/**   \brief  type used to point to CanNm_TimeoutTimer */
typedef P2VAR(CanNm_TimeoutTimerType, TYPEDEF, CANNM_VAR_NOINIT) CanNm_TimeoutTimerPtrType;

/**   \brief  type used to point to CanNm_TxControlState */
typedef P2VAR(CanNm_TxControlStateType, TYPEDEF, CANNM_VAR_NOINIT) CanNm_TxControlStatePtrType;

/**   \brief  type used to point to CanNm_TxControlStateRequest */
typedef P2VAR(CanNm_TxControlStateRequestType, TYPEDEF, CANNM_VAR_NOINIT) CanNm_TxControlStateRequestPtrType;

/**   \brief  type used to point to CanNm_TxMessageData */
typedef P2VAR(CanNm_TxMessageDataType, TYPEDEF, CANNM_VAR_NOINIT) CanNm_TxMessageDataPtrType;

/**   \brief  type used to point to CanNm_WaitBusSleepTimer */
typedef P2VAR(CanNm_WaitBusSleepTimerType, TYPEDEF, CANNM_VAR_NOINIT) CanNm_WaitBusSleepTimerPtrType;

/** 
  \}
*/ 

/** 
  \defgroup  CanNmPCRootValueTypes  CanNm Root Value Types (PRE_COMPILE)
  \brief  These type definitions are used for value representations in root arrays.
  \{
*/ 
/**   \brief  type used in CanNm_PCConfig */
typedef struct sCanNm_PCConfigType
{
  CanNm_ChannelConfigPtrType ChannelConfigOfPCConfig;  /**< the pointer to CanNm_ChannelConfig */
} CanNm_PCConfigType;

typedef CanNm_PCConfigType CanNm_ConfigType;  /**< A structure type is present for data in each configuration class. This typedef redefines the probably different name to the specified one. */

/**   \brief  type to access CanNm_PCConfig in a symbol based style. */
typedef struct sCanNm_PCConfigsType
{
  CanNm_PCConfigType Config_Left;  /**< [Config_Left] */
  CanNm_PCConfigType Config_Right;  /**< [Config_Right] */
} CanNm_PCConfigsType;

/** 
  \}
*/ 


/**********************************************************************************************************************
  CONFIGURATION CLASS: POST_BUILD
  SECTION: GLOBAL SIMPLE DATA TYPES AND STRUCTURES
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: POST_BUILD
  SECTION: GLOBAL COMPLEX DATA TYPES AND STRUCTURES
**********************************************************************************************************************/


/**********************************************************************************************************************
  GLOBAL DATA PROTOTYPES
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL DATA PROTOTYPES
**********************************************************************************************************************/
/**********************************************************************************************************************
  CanNm_ChannelConfigLeft
**********************************************************************************************************************/
/** 
  \var    CanNm_ChannelConfigLeft
  \details
  Element                           Description
  RepeatMessageTime                 Timeout for Repeat Message State [ms].
  ActiveWakeUpBitEnabled            Determines if Active WUP Bit Handling is active or not
  AllMessagesKeepAwake              Determines if all NM PDUs are relevant or not
  ComControlEnabled                 Determines if Com Control is active or not
  PnHandleMultipleNetworkRequest    Determines whether a call of CanNm_NetworkRequest leads to a transition to Repeat Message from Network Mode
  ChannelId                         Channel ID configured for the respective instance of the NM.
  ImmediateNmCycleTime              Fast NM PDU Transmission Time during WUP
  ImmediateNmTransmissions          Number of fast NM PDU Transmissions during WUP
  MsgCycleTime                      Period of a NM message [ms]. It determines the periodic rate in the periodic transmission mode.
  MsgTimeoutTime                    Transmission Timeout [ms] of NM message. If there is no transmission confirmation by the CAN Interface within this timeout, the CAN NM module shall give an error notification.
  PduCbvPosition                    Control Bit Vector Position in the PDU
  RemoteSleepIndTime                Timeout for Remote Sleep Indication [ms].
  TimeoutTime                       Timeout for the NM messages [ms].
  WaitBusSleepTime                  Timeout for bus calm down phase [ms].
*/ 
#define CANNM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(CanNm_ChannelConfigType, CANNM_CONST) CanNm_ChannelConfigLeft[1];
#define CANNM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanNm_ChannelConfigRight
**********************************************************************************************************************/
/** 
  \var    CanNm_ChannelConfigRight
  \details
  Element                           Description
  RepeatMessageTime                 Timeout for Repeat Message State [ms].
  ActiveWakeUpBitEnabled            Determines if Active WUP Bit Handling is active or not
  AllMessagesKeepAwake              Determines if all NM PDUs are relevant or not
  ComControlEnabled                 Determines if Com Control is active or not
  PnHandleMultipleNetworkRequest    Determines whether a call of CanNm_NetworkRequest leads to a transition to Repeat Message from Network Mode
  ChannelId                         Channel ID configured for the respective instance of the NM.
  ImmediateNmCycleTime              Fast NM PDU Transmission Time during WUP
  ImmediateNmTransmissions          Number of fast NM PDU Transmissions during WUP
  MsgCycleTime                      Period of a NM message [ms]. It determines the periodic rate in the periodic transmission mode.
  MsgTimeoutTime                    Transmission Timeout [ms] of NM message. If there is no transmission confirmation by the CAN Interface within this timeout, the CAN NM module shall give an error notification.
  PduCbvPosition                    Control Bit Vector Position in the PDU
  RemoteSleepIndTime                Timeout for Remote Sleep Indication [ms].
  TimeoutTime                       Timeout for the NM messages [ms].
  WaitBusSleepTime                  Timeout for bus calm down phase [ms].
*/ 
#define CANNM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(CanNm_ChannelConfigType, CANNM_CONST) CanNm_ChannelConfigRight[1];
#define CANNM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanNm_PbChannelConfig
**********************************************************************************************************************/
/** 
  \var    CanNm_PbChannelConfig
  \details
  Element                               Description
  PnEnabled                         
  MsgCycleOffset                    
  TxMessageDataEndIdx                   the end index of the 0:n relation pointing to CanNm_TxMessageData
  TxMessageDataLength                   the number of relations pointing to CanNm_TxMessageData
  TxMessageDataStartIdx                 the start index of the 0:n relation pointing to CanNm_TxMessageData
  TxMessageData_CBVIdx                  the index of the 0:1 relation pointing to CanNm_TxMessageData
  TxMessageData_PnFilterMaskEndIdx      the end index of the 0:n relation pointing to CanNm_TxMessageData
  TxMessageData_PnFilterMaskStartIdx    the start index of the 0:n relation pointing to CanNm_TxMessageData
  TxMessageData_UserDataEndIdx          the end index of the 0:n relation pointing to CanNm_TxMessageData
  TxMessageData_UserDataLength          the number of relations pointing to CanNm_TxMessageData
  TxMessageData_UserDataStartIdx        the start index of the 0:n relation pointing to CanNm_TxMessageData
  TxPduId                           
  TxUserDataPduId                   
*/ 
#define CANNM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(CanNm_PbChannelConfigType, CANNM_CONST) CanNm_PbChannelConfig[1];
#define CANNM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanNm_PnInfoByteConfig
**********************************************************************************************************************/
/** 
  \var    CanNm_PnInfoByteConfig
  \details
  Element                        Description
  PnClusterResetTimerEndIdx      the end index of the 0:n relation pointing to CanNm_PnClusterResetTimer
  PnClusterResetTimerStartIdx    the start index of the 0:n relation pointing to CanNm_PnClusterResetTimer
  PnFilterMask                   PnFilterMask for PnInfoBytes
*/ 
#define CANNM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(CanNm_PnInfoByteConfigType, CANNM_CONST) CanNm_PnInfoByteConfig[7];
#define CANNM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanNm_CommState
**********************************************************************************************************************/
/** 
  \var    CanNm_CommState
  \brief  Internal state for the application's need for communication.
*/ 
#define CANNM_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(CanNm_CommStateUType, CANNM_VAR_NOINIT) CanNm_CommState;  /* PRQA S 0759 */  /* MD_CSL_Union */
#define CANNM_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanNm_CoordReadyToSleepState
**********************************************************************************************************************/
/** 
  \var    CanNm_CoordReadyToSleepState
  \brief  State for Rx of Coordinator Sleep Ready Bit:
*/ 
#define CANNM_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(CanNm_CoordReadyToSleepStateUType, CANNM_VAR_NOINIT) CanNm_CoordReadyToSleepState;  /* PRQA S 0759 */  /* MD_CSL_Union */
#define CANNM_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanNm_ImmediateNmMsgCount
**********************************************************************************************************************/
#define CANNM_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(CanNm_ImmediateNmMsgCountUType, CANNM_VAR_NOINIT) CanNm_ImmediateNmMsgCount;  /* PRQA S 0759 */  /* MD_CSL_Union */
#define CANNM_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanNm_ModuleInitialized
**********************************************************************************************************************/
#define CANNM_START_SEC_VAR_ZERO_INIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(CanNm_ModuleInitializedType, CANNM_VAR_ZERO_INIT) CanNm_ModuleInitialized;
#define CANNM_STOP_SEC_VAR_ZERO_INIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanNm_MsgConfirmationFlag
**********************************************************************************************************************/
/** 
  \var    CanNm_MsgConfirmationFlag
  \brief  Message Confirmation Flag
*/ 
#define CANNM_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(CanNm_MsgConfirmationFlagUType, CANNM_VAR_NOINIT) CanNm_MsgConfirmationFlag;  /* PRQA S 0759 */  /* MD_CSL_Union */
#define CANNM_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanNm_MsgIndicationFlag
**********************************************************************************************************************/
/** 
  \var    CanNm_MsgIndicationFlag
  \brief  Message Indication Flag
*/ 
#define CANNM_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(CanNm_MsgIndicationFlagUType, CANNM_VAR_NOINIT) CanNm_MsgIndicationFlag;  /* PRQA S 0759 */  /* MD_CSL_Union */
#define CANNM_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanNm_MsgRequest
**********************************************************************************************************************/
/** 
  \var    CanNm_MsgRequest
  \brief  Internal Message Request Variable
*/ 
#define CANNM_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(CanNm_MsgRequestUType, CANNM_VAR_NOINIT) CanNm_MsgRequest;  /* PRQA S 0759 */  /* MD_CSL_Union */
#define CANNM_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanNm_MsgTimeoutTimer
**********************************************************************************************************************/
#define CANNM_START_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(CanNm_MsgTimeoutTimerUType, CANNM_VAR_NOINIT) CanNm_MsgTimeoutTimer;  /* PRQA S 0759 */  /* MD_CSL_Union */
#define CANNM_STOP_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanNm_MsgTimer
**********************************************************************************************************************/
/** 
  \var    CanNm_MsgTimer
  \brief  Timer for NM message transmission.
*/ 
#define CANNM_START_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(CanNm_MsgTimerUType, CANNM_VAR_NOINIT) CanNm_MsgTimer;  /* PRQA S 0759 */  /* MD_CSL_Union */
#define CANNM_STOP_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanNm_NetworkRestartFlag
**********************************************************************************************************************/
#define CANNM_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(CanNm_NetworkRestartFlagUType, CANNM_VAR_NOINIT) CanNm_NetworkRestartFlag;  /* PRQA S 0759 */  /* MD_CSL_Union */
#define CANNM_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanNm_NmState
**********************************************************************************************************************/
/** 
  \var    CanNm_NmState
  \brief  Current state of the state machine
*/ 
#define CANNM_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(CanNm_NmStateUType, CANNM_VAR_NOINIT) CanNm_NmState;  /* PRQA S 0759 */  /* MD_CSL_Union */
#define CANNM_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanNm_PnClusterReq
**********************************************************************************************************************/
/** 
  \var    CanNm_PnClusterReq
  \brief  Internal Cluster Request Buffer
*/ 
#define CANNM_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(CanNm_PnClusterReqUType, CANNM_VAR_NOINIT) CanNm_PnClusterReq;  /* PRQA S 0759 */  /* MD_CSL_Union */
#define CANNM_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanNm_PnClusterReqNew
**********************************************************************************************************************/
/** 
  \var    CanNm_PnClusterReqNew
  \brief  Internal Cluster Request Buffer
*/ 
#define CANNM_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(CanNm_PnClusterReqNewUType, CANNM_VAR_NOINIT) CanNm_PnClusterReqNew;  /* PRQA S 0759 */  /* MD_CSL_Union */
#define CANNM_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanNm_PnClusterResetTimer
**********************************************************************************************************************/
/** 
  \var    CanNm_PnClusterResetTimer
  \brief  Pn Cluster Reset Timer
*/ 
#define CANNM_START_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(CanNm_PnClusterResetTimerUType, CANNM_VAR_NOINIT) CanNm_PnClusterResetTimer;  /* PRQA S 0759 */  /* MD_CSL_Union */
#define CANNM_STOP_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanNm_PnMessageFilterDeactivationIndicated
**********************************************************************************************************************/
/** 
  \var    CanNm_PnMessageFilterDeactivationIndicated
  \brief  Partial Networking: Message Reception Filter shall be disabled.
*/ 
#define CANNM_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(CanNm_PnMessageFilterDeactivationIndicatedUType, CANNM_VAR_NOINIT) CanNm_PnMessageFilterDeactivationIndicated;  /* PRQA S 0777, 0759 */  /* MD_MSR_Rule5.1, MD_CSL_Union */
#define CANNM_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanNm_PnMessageFilterEnabled
**********************************************************************************************************************/
/** 
  \var    CanNm_PnMessageFilterEnabled
  \brief  Partial Networking: Message Reception Filter is enabled.
*/ 
#define CANNM_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(CanNm_PnMessageFilterEnabledUType, CANNM_VAR_NOINIT) CanNm_PnMessageFilterEnabled;  /* PRQA S 0759 */  /* MD_CSL_Union */
#define CANNM_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanNm_RemoteSleepIndState
**********************************************************************************************************************/
/** 
  \var    CanNm_RemoteSleepIndState
  \brief  State of remote sleep indication.
*/ 
#define CANNM_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(CanNm_RemoteSleepIndStateUType, CANNM_VAR_NOINIT) CanNm_RemoteSleepIndState;  /* PRQA S 0759 */  /* MD_CSL_Union */
#define CANNM_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanNm_RemoteSleepTimer
**********************************************************************************************************************/
#define CANNM_START_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(CanNm_RemoteSleepTimerUType, CANNM_VAR_NOINIT) CanNm_RemoteSleepTimer;  /* PRQA S 0759 */  /* MD_CSL_Union */
#define CANNM_STOP_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanNm_RepeatMsgTimer
**********************************************************************************************************************/
#define CANNM_START_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(CanNm_RepeatMsgTimerUType, CANNM_VAR_NOINIT) CanNm_RepeatMsgTimer;  /* PRQA S 0759 */  /* MD_CSL_Union */
#define CANNM_STOP_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanNm_TimeoutTimer
**********************************************************************************************************************/
/** 
  \var    CanNm_TimeoutTimer
  \brief  Timer for NM Algorithm.
*/ 
#define CANNM_START_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(CanNm_TimeoutTimerUType, CANNM_VAR_NOINIT) CanNm_TimeoutTimer;  /* PRQA S 0759 */  /* MD_CSL_Union */
#define CANNM_STOP_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanNm_TxControlState
**********************************************************************************************************************/
/** 
  \var    CanNm_TxControlState
  \brief  Message transmission control state.
*/ 
#define CANNM_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(CanNm_TxControlStateUType, CANNM_VAR_NOINIT) CanNm_TxControlState;  /* PRQA S 0759 */  /* MD_CSL_Union */
#define CANNM_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanNm_TxControlStateRequest
**********************************************************************************************************************/
/** 
  \var    CanNm_TxControlStateRequest
  \brief  Message transmission control state request.
*/ 
#define CANNM_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(CanNm_TxControlStateRequestUType, CANNM_VAR_NOINIT) CanNm_TxControlStateRequest;  /* PRQA S 0759 */  /* MD_CSL_Union */
#define CANNM_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanNm_TxMessageData
**********************************************************************************************************************/
#define CANNM_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(CanNm_TxMessageDataType, CANNM_VAR_NOINIT) CanNm_TxMessageData[8];
#define CANNM_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanNm_WaitBusSleepTimer
**********************************************************************************************************************/
#define CANNM_START_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(CanNm_WaitBusSleepTimerUType, CANNM_VAR_NOINIT) CanNm_WaitBusSleepTimer;  /* PRQA S 0759 */  /* MD_CSL_Union */
#define CANNM_STOP_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanNm_PCConfig
**********************************************************************************************************************/
/** 
  \var    CanNm_PCConfig
  \details
  Element          Description
  ChannelConfig    the pointer to CanNm_ChannelConfig
*/ 
#define CANNM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(CanNm_PCConfigsType, CANNM_CONST) CanNm_PCConfig;
#define CANNM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */


/**********************************************************************************************************************
  CONFIGURATION CLASS: POST_BUILD
  SECTION: GLOBAL DATA PROTOTYPES
**********************************************************************************************************************/




/**********************************************************************************************************************
  END OF FILE: CanNm_Cfg.h
**********************************************************************************************************************/
#endif /* CANNM_CFG_H */

