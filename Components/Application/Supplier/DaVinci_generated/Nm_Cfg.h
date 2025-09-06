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
 *            Module: Nm
 *           Program: MSR_Daimler_SLP11
 *          Customer: Mercedes-Benz AG
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: TC3xx
 *    License Scope : The usage is restricted to CBD2200333_D05
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: Nm_Cfg.h
 *   Generation Time: 2023-07-10 14:36:15
 *           Project: StartApplication - Version 1.0
 *          Delivery: CBD2200333_D05
 *      Tool Version: DaVinci Configurator Classic 5.25.50 SP5
 *
 *
 *********************************************************************************************************************/

/* \trace SPEC-19592 */
#if !defined(NM_CFG_H)
#define NM_CFG_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "ComStack_Types.h"
#include "NmStack_Types.h"

#include "Os.h"
#include "App_Nm.h"
#include "Cdd_MBBL_EcuStatHandler.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
/* Global Properties */
#ifndef NM_DEV_ERROR_DETECT
#define NM_DEV_ERROR_DETECT STD_ON
#endif
#ifndef NM_DEV_ERROR_REPORT
#define NM_DEV_ERROR_REPORT STD_OFF
#endif
#define NM_VERSION_INFO_API                            STD_OFF

/* ------ Global Features ----------*/
/* Macro Layer Optimization */ 
#define NM_MACRO_LAYER_ENABLED                         STD_OFF

#define NM_PASSIVE_MODE_ENABLED                        STD_OFF
#define NM_STATE_CHANGE_REPORT_ENABLED                 STD_OFF

#define NM_COM_CONTROL_ENABLED                         STD_ON
#define NM_COM_USER_DATA_SUPPORT                       STD_ON
#define NM_NODE_DETECTION_ENABLED                      STD_OFF

#define NM_NODE_ID_ENABLED                             STD_OFF
#define NM_USER_DATA_ENABLED                           STD_OFF

#define NM_RUNTIME_MEASUREMENT_SUPPORT                 STD_ON

#define NM_SYNCHRONIZED_PNC_SHUTDOWN_ENABLED           STD_OFF

/* Coordinator */
#define NM_COORDINATOR_SUPPORT_ENABLED                 STD_OFF
#define NM_BUS_SYNCHRONIZATION_ENABLED                 STD_OFF
#define NM_COORDINATOR_SYNC_SUPPORT                    STD_OFF
#define NM_SYNCHRONIZATION_TIMEOUT_TIME                0u
#define NM_COORDINATOR_REQUEST_CHANNELS_IN_BUS_SLEEP   STD_OFF
#define NM_PASSIVE_STARTUP_FORWARDING_ENABLED          STD_OFF

/* Indications */
#define NM_PDU_RX_INDICATION_ENABLED                   STD_OFF
#define NM_BUSNM_SPECIFIC_PDU_RX_INDICATION_ENABLED    STD_OFF
#define NM_REMOTE_SLEEP_IND_ENABLED                    STD_ON
#define NM_REPEAT_MSG_IND_ENABLED                      STD_OFF
#define NM_STATE_CHANGE_IND_ENABLED                    STD_ON

#define NM_CAR_WAKE_UP_RX_ENABLED                      STD_OFF

#define NM_ENABLE_CHANNELTYPE_COORDINATED_NMFIATC      STD_OFF


#define NM_BUSNM_FRNM_ENABLED                          STD_OFF

#define NM_WAIT_BUS_SLEEP_EXTENSIONS                   STD_OFF


/* Callbacks to Upper Layer */
/* Indication that the Nm State has changed */
#define UL_Nm_StateChangeNotification                  EcuStatHandler_NmStateChangeInd


/* Optimizations */

/*! Optimization that is turned ON if and only if there is at most one coordinator cluster */
#define NM_OPTIMIZE_ONLY_ONE_COORD                     STD_ON

/*! Optimization that is turned ON if and only if every channel equipped with Nm is coordinated */
#define NM_OPTIMIZE_ALL_CHANNEL_COORD                  STD_ON

/*! Optimization that is turned ON if and only if no channel is passively coordinated */
#define NM_OPTIMIZE_NO_PASSIVE_COORD                   STD_ON

/*! Optimization that is turned ON if and only if there is no coordinated channel configured as 'Synchronizing Network' */
#define NM_OPTIMIZE_NO_SYNC_CHANNEL                    STD_ON

/*! Optimization that is turned ON if and only if every coordinated channel configured as 'Synchronizing Network' */
#define NM_OPTIMIZE_ALL_SYNC_CHANNEL                   STD_ON

/*! Optimization that is turned ON if and only if no channel has 'Passive Mode Enabled' turned ON */
#define NM_OPTIMIZE_NO_PASSIVE_CHANNEL                 STD_ON

/*! Optimization that is turned ON if and only if no coordinated channel is completely configured as
 *  'Channel Sleep Master', i.e.
 *  - 'Channel Sleep Master' is turned OFF for every coordinated channel,
 *    if NM_OPTIMIZE_ONE_BUSNM_ON_A_CHANNEL is defined to STD_ON
 *  - 'Channel Sleep Master' is either turned OFF for a coordinated channel or
 *    not every BusNm on a coordinated channel is a 'Channel Sleep Master', otherwise.
 */
#define NM_OPTIMIZE_NO_SLEEP_MASTER                    STD_ON

/*! Optimization that is turned ON if and only if every coordinated channel is configured as 'Channel Sleep Master' */
#define NM_OPTIMIZE_ALL_SLEEP_MASTER                   STD_ON

/*! Optimization that is turned ON if and only if every channel does not have the Prepare Bus Sleep Mode (i.e. neither
 * CanNm, UdpNm nor a GenericBusNm on a CAN/Ethernet channel is configured)
 */
#define NM_OPTIMIZE_NO_PREPARE_BUS_SLEEP_MODE          STD_OFF

/*! Optimization that is turned ON if and only if exactly one underlying BusNm is configured for each channel */
#define NM_OPTIMIZE_ONE_BUSNM_ON_A_CHANNEL             STD_ON

/*! Optimization that is turned ON if and only if in each variant every channel completely belongs to Coordinator
 *  Cluster 0 or every channel does not belong to any Coordinator Cluster
 */
#define NM_OPTIMIZE_ALL_OR_NONE_COORD_IN_VARIANT       STD_ON

/*! Optimization that is turned ON if and only if every shutdown delay timer start value is equal to one (1). */
#define NM_OPTIMIZE_ALL_SHUTDOWN_DELAY_TIMER_ARE_ONE   STD_ON

/*! Optimization that is turned ON if and only if the Nm exists in every configuration variant. */
#define NM_OPTIMIZE_NM_EXISTS_IN_ALL_VARIANTS          STD_ON

/*! Optimization that is turned ON if and only if no passively coordinated channel exists on a satellite partition. */
#define NM_OPTIMIZE_NO_PASSIVE_COORD_ON_SATELLITE_PARTITION   STD_ON

#define NM_SYS_CHANNELS_PC                             2u
#define NM_NM_CHANNELS_PC                              1u
#define NM_COORD_PC                                    0u
#define NM_BUSNMS_PC                                   1u

/* NmChannelId symbolic name defines */
#define NmConf_NmChannelConfig_RBTM_FL_BODY3_8uqv9blm85ehm0msat385m76v_03d5f5f6 0u 
#define NmConf_NmChannelConfig_RBTM_FR_BODY3_4xwwtd59665s787n6ctawh7k8_23a94727 1u 



/* General Module Defines */
#ifndef NM_USE_DUMMY_STATEMENT
#define NM_USE_DUMMY_STATEMENT STD_OFF /* /MICROSAR/vSet/vSetGeneral/vSetDummyStatementKind */
#endif
#ifndef NM_DUMMY_STATEMENT
#define NM_DUMMY_STATEMENT(v)  /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */  /* /MICROSAR/vSet/vSetGeneral/vSetDummyStatementKind */
#endif
#ifndef NM_DUMMY_STATEMENT_CONST
#define NM_DUMMY_STATEMENT_CONST(v)  /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */  /* /MICROSAR/vSet/vSetGeneral/vSetDummyStatementKind */
#endif
#ifndef NM_ATOMIC_BIT_ACCESS_IN_BITFIELD
#define NM_ATOMIC_BIT_ACCESS_IN_BITFIELD STD_OFF /* /MICROSAR/EcuC/EcucGeneral/AtomicBitAccessInBitfield */
#endif
#ifndef NM_ATOMIC_VARIABLE_ACCESS
#define NM_ATOMIC_VARIABLE_ACCESS 32u /* /MICROSAR/EcuC/EcucGeneral/AtomicVariableAccess */
#endif
#ifndef NM_PROCESSOR_TC322L
#define NM_PROCESSOR_TC322L
#endif
#ifndef NM_COMP_TASKING
#define NM_COMP_TASKING
#endif
#ifndef NM_GEN_GENERATOR_MSR
#define NM_GEN_GENERATOR_MSR
#endif
#ifndef NM_CPUTYPE_BITORDER_LSB2MSB
#define NM_CPUTYPE_BITORDER_LSB2MSB /* /MICROSAR/vSet/vSetPlatform/vSetBitOrder */
#endif
#ifndef NM_CONFIGURATION_VARIANT_PRECOMPILE
#define NM_CONFIGURATION_VARIANT_PRECOMPILE 1
#endif
#ifndef NM_CONFIGURATION_VARIANT_LINKTIME
#define NM_CONFIGURATION_VARIANT_LINKTIME 2
#endif
#ifndef NM_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE
#define NM_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE 3
#endif
#ifndef NM_CONFIGURATION_VARIANT
#define NM_CONFIGURATION_VARIANT NM_CONFIGURATION_VARIANT_PRECOMPILE
#endif
#ifndef NM_POSTBUILD_VARIANT_SUPPORT
#define NM_POSTBUILD_VARIANT_SUPPORT STD_ON
#endif


#if ( NM_CONFIGURATION_VARIANT == NM_CONFIGURATION_VARIANT_PRECOMPILE )
# define NM_CHANNEL_SYS_ARRAY_SIZE                     NM_SYS_CHANNELS_PC
# define NM_CHANNEL_NM_ARRAY_SIZE                      NM_NM_CHANNELS_PC
# define NM_COORDINATOR_ARRAY_SIZE                     NM_COORD_PC
# define NM_BUSNM_ARRAY_SIZE                           NM_BUSNMS_PC
#else
# define NM_CHANNEL_SYS_ARRAY_SIZE
# define NM_CHANNEL_NM_ARRAY_SIZE
# define NM_COORDINATOR_ARRAY_SIZE
# define NM_BUSNM_ARRAY_SIZE
#endif

#define NM_NUMBER_OF_CHANNEL_MODES                            3u

/* Multi-Partition */
#define NM_MULTIPARTITION                                     STD_OFF
#define NM_EXISTS_CHANNEL_ON_MASTER_PARTITION                 STD_ON
#define NM_MASTER_PARTITION_IDX                               0u
#define NM_SINGLE_PARTITION                                   0u
#define NM_MAIN_FUNCTION_SATELLITE_ENABLED                    STD_OFF

/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL CONSTANT MACROS
**********************************************************************************************************************/
/** 
  \defgroup  NmPCDataSwitches  Nm Data Switches  (PRE_COMPILE)
  \brief  These defines are used to deactivate data and their processing.
  \{
*/ 
#define NM_BUSNMCHIDXTOBUSNMIDXINDS                                                                 STD_OFF  /**< Deactivateable: 'Nm_BusNmChIdxToBusNmIdxInds' Reason: 'There is no BusNmAssociationTable available if NM_OPTIMIZE_ONE_BUSNM_ON_A_CHANNEL == STD_ON' and Deactivateable: 'Nm_BusNmChIdxToBusNmIdxInds' Reason: 'There is no BusNmAssociationTable available if NM_OPTIMIZE_ONE_BUSNM_ON_A_CHANNEL == STD_ON' */
#define NM_CARWAKEUPCALLBACKFCTPTR                                                                  STD_ON
#define NM_CHPREVBUSNMSTATE                                                                         STD_OFF  /**< Deactivateable: 'Nm_ChPrevBusNmState' Reason: 'Only one BusNm can be found on each channel or State Change Ind Enabled is OFF' and Deactivateable: 'Nm_ChPrevBusNmState' Reason: 'Only one BusNm can be found on each channel or State Change Ind Enabled is OFF' */
#define NM_CHREMSLEEPSTATE                                                                          STD_OFF  /**< Deactivateable: 'Nm_ChRemSleepState' Reason: 'Only one BusNm can be found on each channel or (Remote Sleep Ind Enabled is OFF and Coordinator Sync Support is OFF)' and Deactivateable: 'Nm_ChRemSleepState' Reason: 'Only one BusNm can be found on each channel or (Remote Sleep Ind Enabled is OFF and Coordinator Sync Support is OFF)' */
#define NM_CHANNELACTIVETIMER                                                                       STD_OFF  /**< Deactivateable: 'Nm_ChannelActiveTimer' Reason: 'Coordinator Support Enabled is OFF' and Deactivateable: 'Nm_ChannelActiveTimer' Reason: 'Coordinator Support Enabled is OFF' */
#define NM_CHANNELBUSNMSTATE                                                                        STD_OFF  /**< Deactivateable: 'Nm_ChannelBusNmState' Reason: 'Only one BusNm can be found on each channel or State Change Ind Enabled is OFF' and Deactivateable: 'Nm_ChannelBusNmState' Reason: 'Only one BusNm can be found on each channel or State Change Ind Enabled is OFF' */
#define NM_CHANNELCONFIG                                                                            STD_ON
#define NM_APPLICATIONIDOFCHANNELCONFIG                                                             STD_OFF  /**< Deactivateable: 'Nm_ChannelConfigLeft.ApplicationId' Reason: 'Only Single Partition use case configured' and Deactivateable: 'Nm_ChannelConfigRight.ApplicationId' Reason: 'Only Single Partition use case configured' */
#define NM_COORDINATORSTATECLUSTERIDXOFCHANNELCONFIG                                                STD_OFF  /**< Deactivateable: 'Nm_ChannelConfigLeft.CoordinatorStateClusterIdx' Reason: 'Coordinator Support Enabled is OFF' and Deactivateable: 'Nm_ChannelConfigRight.CoordinatorStateClusterIdx' Reason: 'Coordinator Support Enabled is OFF' */
#define NM_COORDINATORSTATECLUSTERUSEDOFCHANNELCONFIG                                               STD_OFF  /**< Deactivateable: 'Nm_ChannelConfigLeft.CoordinatorStateClusterUsed' Reason: 'Coordinator Support Enabled is OFF' and Deactivateable: 'Nm_ChannelConfigRight.CoordinatorStateClusterUsed' Reason: 'Coordinator Support Enabled is OFF' */
#define NM_NMACTIVECOORDINATOROFCHANNELCONFIG                                                       STD_OFF  /**< Deactivateable: 'Nm_ChannelConfigLeft.NmActiveCoordinator' Reason: 'Coordinator Support is not enabled' and Deactivateable: 'Nm_ChannelConfigRight.NmActiveCoordinator' Reason: 'Coordinator Support is not enabled' */
#define NM_NMCHANNELIDOFCHANNELCONFIG                                                               STD_ON
#define NM_NMCHANNELSLEEPMASTEROFCHANNELCONFIG                                                      STD_OFF  /**< Deactivateable: 'Nm_ChannelConfigLeft.NmChannelSleepMaster' Reason: 'Coordinator Support Enabled is turned OFF or Channel Sleep Master is turned ON for all BusNms on every coordinated channel' and Deactivateable: 'Nm_ChannelConfigRight.NmChannelSleepMaster' Reason: 'Coordinator Support Enabled is turned OFF or Channel Sleep Master is turned ON for all BusNms on every coordinated channel' */
#define NM_NMCONTAINSNMOSEKOFCHANNELCONFIG                                                          STD_OFF  /**< Deactivateable: 'Nm_ChannelConfigLeft.NmContainsNmOsek' Reason: 'Wait bus sleep extension is not enabled or Coordinator Support is not enabled' and Deactivateable: 'Nm_ChannelConfigRight.NmContainsNmOsek' Reason: 'Wait bus sleep extension is not enabled or Coordinator Support is not enabled' */
#define NM_NMFUNCTIONTABLEIDXOFCHANNELCONFIG                                                        STD_ON
#define NM_NMPASSIVEMODEENABLEDOFCHANNELCONFIG                                                      STD_OFF  /**< Deactivateable: 'Nm_ChannelConfigLeft.NmPassiveModeEnabled' Reason: 'Passive Mode Enabled is OFF on all channels' and Deactivateable: 'Nm_ChannelConfigRight.NmPassiveModeEnabled' Reason: 'Passive Mode Enabled is OFF on all channels' */
#define NM_NMSHUTDOWNDELAYTIMEROFCHANNELCONFIG                                                      STD_OFF  /**< Deactivateable: 'Nm_ChannelConfigLeft.NmShutdownDelayTimer' Reason: 'Coordinator Support is not enabled' and Deactivateable: 'Nm_ChannelConfigRight.NmShutdownDelayTimer' Reason: 'Coordinator Support is not enabled' */
#define NM_NMSHUTDOWNLIMPHOMETIMEROFCHANNELCONFIG                                                   STD_OFF  /**< Deactivateable: 'Nm_ChannelConfigLeft.NmShutdownLimpHomeTimer' Reason: 'Wait bus sleep extension is not enabled or Coordinator Support is not enabled' and Deactivateable: 'Nm_ChannelConfigRight.NmShutdownLimpHomeTimer' Reason: 'Wait bus sleep extension is not enabled or Coordinator Support is not enabled' */
#define NM_NMSHUTDOWNNORMALDELAYTIMEROFCHANNELCONFIG                                                STD_OFF  /**< Deactivateable: 'Nm_ChannelConfigLeft.NmShutdownNormalDelayTimer' Reason: 'Wait bus sleep extension is not enabled or Coordinator Support is not enabled' and Deactivateable: 'Nm_ChannelConfigRight.NmShutdownNormalDelayTimer' Reason: 'Wait bus sleep extension is not enabled or Coordinator Support is not enabled' */
#define NM_NMSTATEREPORTENABLEDOFCHANNELCONFIG                                                      STD_OFF  /**< Deactivateable: 'Nm_ChannelConfigLeft.NmStateReportEnabled' Reason: 'StateReporting is not enabled' and Deactivateable: 'Nm_ChannelConfigRight.NmStateReportEnabled' Reason: 'StateReporting is not enabled' */
#define NM_NMSTATEREPORTSIGNALREFOFCHANNELCONFIG                                                    STD_OFF  /**< Deactivateable: 'Nm_ChannelConfigLeft.NmStateReportSignalRef' Reason: 'StateReporting is not enabled' and Deactivateable: 'Nm_ChannelConfigRight.NmStateReportSignalRef' Reason: 'StateReporting is not enabled' */
#define NM_NMSYNCHRONIZINGNETWORKOFCHANNELCONFIG                                                    STD_OFF  /**< Deactivateable: 'Nm_ChannelConfigLeft.NmSynchronizingNetwork' Reason: 'Coordinator Support Enabled is turned OFF or Synchronizing Network is turned ON on every coordinated channel' and Deactivateable: 'Nm_ChannelConfigRight.NmSynchronizingNetwork' Reason: 'Coordinator Support Enabled is turned OFF or Synchronizing Network is turned ON on every coordinated channel' */
#define NM_PARTITIONCONFIGIDXOFCHANNELCONFIG                                                        STD_ON
#define NM_PDURXINDICATIONOFCHANNELCONFIG                                                           STD_ON
#define NM_CHANNELMODE                                                                              STD_OFF  /**< Deactivateable: 'Nm_ChannelMode' Reason: 'Only one BusNm can be found on each channel' and Deactivateable: 'Nm_ChannelMode' Reason: 'Only one BusNm can be found on each channel' */
#define NM_CHANNELREQUESTED                                                                         STD_OFF  /**< Deactivateable: 'Nm_ChannelRequested' Reason: 'Coordinator Support Enabled is OFF' and Deactivateable: 'Nm_ChannelRequested' Reason: 'Coordinator Support Enabled is OFF' */
#define NM_CHANNELSTATE                                                                             STD_OFF  /**< Deactivateable: 'Nm_ChannelState' Reason: 'Coordinator Support Enabled is OFF' and Deactivateable: 'Nm_ChannelState' Reason: 'Coordinator Support Enabled is OFF' */
#define NM_COORDCLUSTER                                                                             STD_OFF  /**< Deactivateable: 'Nm_CoordCluster' Reason: 'Nm Gw Ext Enabled is turned OFF' and Deactivateable: 'Nm_CoordCluster' Reason: 'Nm Gw Ext Enabled is turned OFF' */
#define NM_CHANNELACTIVETIMERIDXOFCOORDCLUSTER                                                      STD_OFF  /**< Deactivateable: 'Nm_CoordCluster.ChannelActiveTimerIdx' Reason: 'Nm Gw Ext Enabled is turned OFF' and Deactivateable: 'Nm_CoordCluster.ChannelActiveTimerIdx' Reason: 'Nm Gw Ext Enabled is turned OFF' */
#define NM_NMPARTECUMAPPINGENDIDXOFCOORDCLUSTER                                                     STD_OFF  /**< Deactivateable: 'Nm_CoordCluster.NmPartEcuMappingEndIdx' Reason: 'Nm Gw Ext Enabled is turned OFF' and Deactivateable: 'Nm_CoordCluster.NmPartEcuMappingEndIdx' Reason: 'Nm Gw Ext Enabled is turned OFF' */
#define NM_NMPARTECUMAPPINGSTARTIDXOFCOORDCLUSTER                                                   STD_OFF  /**< Deactivateable: 'Nm_CoordCluster.NmPartEcuMappingStartIdx' Reason: 'Nm Gw Ext Enabled is turned OFF' and Deactivateable: 'Nm_CoordCluster.NmPartEcuMappingStartIdx' Reason: 'Nm Gw Ext Enabled is turned OFF' */
#define NM_NMPARTECUMAPPINGUSEDOFCOORDCLUSTER                                                       STD_OFF  /**< Deactivateable: 'Nm_CoordCluster.NmPartEcuMappingUsed' Reason: 'Nm Gw Ext Enabled is turned OFF' and Deactivateable: 'Nm_CoordCluster.NmPartEcuMappingUsed' Reason: 'Nm Gw Ext Enabled is turned OFF' */
#define NM_COORDINATORSTATE                                                                         STD_OFF  /**< Deactivateable: 'Nm_CoordinatorState' Reason: 'Coordinator Support Enabled is OFF' and Deactivateable: 'Nm_CoordinatorState' Reason: 'Coordinator Support Enabled is OFF' */
#define NM_EXTERNALWAKEUPPROCESSED                                                                  STD_OFF  /**< Deactivateable: 'Nm_ExternalWakeupProcessed' Reason: 'Nm Gw Ext Enabled is turned OFF' and Deactivateable: 'Nm_ExternalWakeupProcessed' Reason: 'Nm Gw Ext Enabled is turned OFF' */
#define NM_FINALMAGICNUMBER                                                                         STD_OFF  /**< Deactivateable: 'Nm_FinalMagicNumber' Reason: 'the module configuration does not support flashing of data.' */
#define NM_INITDATAHASHCODE                                                                         STD_OFF  /**< Deactivateable: 'Nm_InitDataHashCode' Reason: 'the module configuration does not support flashing of data.' */
#define NM_INITIALIZED                                                                              STD_ON
#define NM_NMCOORDINATORWITHNMFIATC                                                                 STD_OFF  /**< Deactivateable: 'Nm_NmCoordinatorWithNmFiatC' Reason: 'Coordinator Support Enabled is OFF or there is no coordinated channel with NmFiatC' and Deactivateable: 'Nm_NmCoordinatorWithNmFiatC' Reason: 'Coordinator Support Enabled is OFF or there is no coordinated channel with NmFiatC' */
#define NM_NMFUNCTIONTABLE                                                                          STD_ON
#define NM_CHECKREMOTESLEEPINDICATIONOFNMFUNCTIONTABLE                                              STD_ON
#define NM_DISABLECOMMUNICATIONOFNMFUNCTIONTABLE                                                    STD_ON
#define NM_ENABLECOMMUNICATIONOFNMFUNCTIONTABLE                                                     STD_ON
#define NM_GETLOCALNODEIDENTIFIEROFNMFUNCTIONTABLE                                                  STD_OFF  /**< Deactivateable: 'Nm_NmFunctionTable.GetLocalNodeIdentifier' Reason: 'Function is not available due to pre-compile settings' */
#define NM_GETNODEIDENTIFIEROFNMFUNCTIONTABLE                                                       STD_OFF  /**< Deactivateable: 'Nm_NmFunctionTable.GetNodeIdentifier' Reason: 'Function is not available due to pre-compile settings' */
#define NM_GETPDUDATAOFNMFUNCTIONTABLE                                                              STD_OFF  /**< Deactivateable: 'Nm_NmFunctionTable.GetPduData' Reason: 'Function is not available due to pre-compile settings' */
#define NM_GETSTATEOFNMFUNCTIONTABLE                                                                STD_ON
#define NM_GETUSERDATAOFNMFUNCTIONTABLE                                                             STD_OFF  /**< Deactivateable: 'Nm_NmFunctionTable.GetUserData' Reason: 'Function is not available due to pre-compile settings' */
#define NM_NETWORKRELEASEOFNMFUNCTIONTABLE                                                          STD_ON
#define NM_NETWORKREQUESTOFNMFUNCTIONTABLE                                                          STD_ON
#define NM_PASSIVESTARTUPOFNMFUNCTIONTABLE                                                          STD_ON
#define NM_REPEATMESSAGEREQUESTOFNMFUNCTIONTABLE                                                    STD_OFF  /**< Deactivateable: 'Nm_NmFunctionTable.RepeatMessageRequest' Reason: 'Function is not available due to pre-compile settings' */
#define NM_REQUESTBUSSYNCHRONIZATIONOFNMFUNCTIONTABLE                                               STD_OFF  /**< Deactivateable: 'Nm_NmFunctionTable.RequestBusSynchronization' Reason: 'Function is not available due to pre-compile settings' */
#define NM_REQUESTSYNCHRONIZEDPNCSHUTDOWNOFNMFUNCTIONTABLE                                          STD_OFF  /**< Deactivateable: 'Nm_NmFunctionTable.RequestSynchronizedPncShutdown' Reason: 'Function is not available due to pre-compile settings' */
#define NM_SETSLEEPREADYBITOFNMFUNCTIONTABLE                                                        STD_OFF  /**< Deactivateable: 'Nm_NmFunctionTable.SetSleepReadyBit' Reason: 'Function is not available due to pre-compile settings' */
#define NM_SETUSERDATAOFNMFUNCTIONTABLE                                                             STD_OFF  /**< Deactivateable: 'Nm_NmFunctionTable.SetUserData' Reason: 'Function is not available due to pre-compile settings' */
#define NM_NMPARTECUMAPPING                                                                         STD_OFF  /**< Deactivateable: 'Nm_NmPartEcuMapping' Reason: 'Nm Gw Ext Enabled is turned OFF' and Deactivateable: 'Nm_NmPartEcuMapping' Reason: 'Nm Gw Ext Enabled is turned OFF' */
#define NM_MAPPARTECUTOACTCHOFNMPARTECUMAPPING                                                      STD_OFF  /**< Deactivateable: 'Nm_NmPartEcuMapping.MapPartEcuToActCh' Reason: 'Nm Gw Ext Enabled is turned OFF' and Deactivateable: 'Nm_NmPartEcuMapping.MapPartEcuToActCh' Reason: 'Nm Gw Ext Enabled is turned OFF' */
#define NM_OSEKNORMAL                                                                               STD_OFF  /**< Deactivateable: 'Nm_OsekNormal' Reason: 'Wait bus sleep extension is not enabled or Coordinator Support is not enabled' and Deactivateable: 'Nm_OsekNormal' Reason: 'Wait bus sleep extension is not enabled or Coordinator Support is not enabled' */
#define NM_PARTECUACTIVECHANNELS                                                                    STD_OFF  /**< Deactivateable: 'Nm_PartEcuActiveChannels' Reason: 'Nm Gw Ext Enabled is turned OFF' and Deactivateable: 'Nm_PartEcuActiveChannels' Reason: 'Nm Gw Ext Enabled is turned OFF' */
#define NM_PARTECUREQCHANNELS                                                                       STD_OFF  /**< Deactivateable: 'Nm_PartEcuReqChannels' Reason: 'Gw Ext Enabled is turned OFF or Nm Gw Ext Proxy Bits Enabled is turned OFF' and Deactivateable: 'Nm_PartEcuReqChannels' Reason: 'Gw Ext Enabled is turned OFF or Nm Gw Ext Proxy Bits Enabled is turned OFF' */
#define NM_PARTECUTOACTTONODEID                                                                     STD_OFF  /**< Deactivateable: 'Nm_PartEcuToActToNodeId' Reason: 'Nm Gw Ext Enabled is turned OFF' and Deactivateable: 'Nm_PartEcuToActToNodeId' Reason: 'Nm Gw Ext Enabled is turned OFF' */
#define NM_PARTITIONIDENTIFIERS                                                                     STD_ON
#define NM_PCPARTITIONCONFIGIDXOFPARTITIONIDENTIFIERS                                               STD_ON
#define NM_PARTITIONSNVOFPARTITIONIDENTIFIERS                                                       STD_ON
#define NM_POSTINITIALIZED                                                                          STD_ON
#define NM_REMOTESLEEPFILTER                                                                        STD_OFF  /**< Deactivateable: 'Nm_RemoteSleepFilter' Reason: 'Nm Gw Ext Enabled is turned OFF' and Deactivateable: 'Nm_RemoteSleepFilter' Reason: 'Nm Gw Ext Enabled is turned OFF' */
#define NM_REMOTEWAKEUPFILTER                                                                       STD_OFF  /**< Deactivateable: 'Nm_RemoteWakeupFilter' Reason: 'Nm Gw Ext Enabled is turned OFF' and Deactivateable: 'Nm_RemoteWakeupFilter' Reason: 'Nm Gw Ext Enabled is turned OFF' */
#define NM_SIZEOFCHANNELCONFIG                                                                      STD_ON
#define NM_SIZEOFNMFUNCTIONTABLE                                                                    STD_ON
#define NM_SIZEOFPARTITIONIDENTIFIERS                                                               STD_ON
#define NM_SIZEOFPOSTINITIALIZED                                                                    STD_ON
#define NM_SIZEOFSYSTONMCHIND                                                                       STD_ON
#define NM_SYSTONMCHIND                                                                             STD_ON
#define NM_WAKEUPDETECTED                                                                           STD_OFF  /**< Deactivateable: 'Nm_WakeupDetected' Reason: 'Nm Gw Ext Enabled is turned OFF' and Deactivateable: 'Nm_WakeupDetected' Reason: 'Nm Gw Ext Enabled is turned OFF' */
#define NM_PCCONFIG                                                                                 STD_ON
#define NM_FINALMAGICNUMBEROFPCCONFIG                                                               STD_OFF  /**< Deactivateable: 'Nm_PCConfig.FinalMagicNumber' Reason: 'the module configuration does not support flashing of data.' */
#define NM_INITDATAHASHCODEOFPCCONFIG                                                               STD_OFF  /**< Deactivateable: 'Nm_PCConfig.InitDataHashCode' Reason: 'the module configuration does not support flashing of data.' */
#define NM_PCPARTITIONCONFIGOFPCCONFIG                                                              STD_ON
#define NM_PARTITIONIDENTIFIERSOFPCCONFIG                                                           STD_ON
#define NM_SIZEOFPARTITIONIDENTIFIERSOFPCCONFIG                                                     STD_ON
#define NM_PCPARTITIONCONFIG                                                                        STD_ON
#define NM_CARWAKEUPCALLBACKFCTPTROFPCPARTITIONCONFIG                                               STD_ON
#define NM_CHANNELCONFIGOFPCPARTITIONCONFIG                                                         STD_ON
#define NM_INITIALIZEDOFPCPARTITIONCONFIG                                                           STD_ON
#define NM_NMCOORDINATORWITHNMFIATCOFPCPARTITIONCONFIG                                              STD_OFF  /**< Deactivateable: 'Nm_PCPartitionConfigLeft.NmCoordinatorWithNmFiatC' Reason: 'Coordinator Support Enabled is OFF or there is no coordinated channel with NmFiatC' and Deactivateable: 'Nm_PCPartitionConfigRight.NmCoordinatorWithNmFiatC' Reason: 'Coordinator Support Enabled is OFF or there is no coordinated channel with NmFiatC' */
#define NM_NMFUNCTIONTABLEOFPCPARTITIONCONFIG                                                       STD_ON
#define NM_POSTINITIALIZEDOFPCPARTITIONCONFIG                                                       STD_ON
#define NM_SIZEOFCHANNELCONFIGOFPCPARTITIONCONFIG                                                   STD_ON
#define NM_SIZEOFNMFUNCTIONTABLEOFPCPARTITIONCONFIG                                                 STD_ON
#define NM_SIZEOFPOSTINITIALIZEDOFPCPARTITIONCONFIG                                                 STD_ON
#define NM_SIZEOFSYSTONMCHINDOFPCPARTITIONCONFIG                                                    STD_ON
#define NM_SYSTONMCHINDOFPCPARTITIONCONFIG                                                          STD_ON
/** 
  \}
*/ 

/** 
  \defgroup  NmPCNoReferenceDefines  Nm No Reference Defines (PRE_COMPILE)
  \brief  These defines are used to indicate unused indexes in data relations.
  \{
*/ 
#define NM_NO_SYSTONMCHIND                                                                          255u
/** 
  \}
*/ 

/** 
  \defgroup  NmPCIsReducedToDefineDefines  Nm Is Reduced To Define Defines (PRE_COMPILE)
  \brief  If all values in a CONST array or an element in a CONST array of structs are equal, the define is STD_ON else STD_OFF.
  \{
*/ 
#define NM_ISDEF_NMCHANNELIDOFCHANNELCONFIG                                                         STD_OFF
#define NM_ISDEF_NMFUNCTIONTABLEIDXOFCHANNELCONFIG                                                  STD_OFF
#define NM_ISDEF_PARTITIONCONFIGIDXOFCHANNELCONFIG                                                  STD_OFF
#define NM_ISDEF_PDURXINDICATIONOFCHANNELCONFIG                                                     STD_OFF
#define NM_ISDEF_CHECKREMOTESLEEPINDICATIONOFNMFUNCTIONTABLE                                        STD_OFF
#define NM_ISDEF_DISABLECOMMUNICATIONOFNMFUNCTIONTABLE                                              STD_OFF
#define NM_ISDEF_ENABLECOMMUNICATIONOFNMFUNCTIONTABLE                                               STD_OFF
#define NM_ISDEF_GETSTATEOFNMFUNCTIONTABLE                                                          STD_OFF
#define NM_ISDEF_NETWORKRELEASEOFNMFUNCTIONTABLE                                                    STD_OFF
#define NM_ISDEF_NETWORKREQUESTOFNMFUNCTIONTABLE                                                    STD_OFF
#define NM_ISDEF_PASSIVESTARTUPOFNMFUNCTIONTABLE                                                    STD_OFF
#define NM_ISDEF_PCPARTITIONCONFIGIDXOFPARTITIONIDENTIFIERS                                         STD_OFF
#define NM_ISDEF_PARTITIONSNVOFPARTITIONIDENTIFIERS                                                 STD_OFF
#define NM_ISDEF_SYSTONMCHIND                                                                       STD_OFF
#define NM_ISDEF_PCPARTITIONCONFIGOFPCCONFIG                                                        STD_OFF
#define NM_ISDEF_PARTITIONIDENTIFIERSOFPCCONFIG                                                     STD_ON
#define NM_ISDEF_CARWAKEUPCALLBACKFCTPTROFPCPARTITIONCONFIG                                         STD_ON
#define NM_ISDEF_CHANNELCONFIGOFPCPARTITIONCONFIG                                                   STD_OFF
#define NM_ISDEF_INITIALIZEDOFPCPARTITIONCONFIG                                                     STD_ON
#define NM_ISDEF_NMFUNCTIONTABLEOFPCPARTITIONCONFIG                                                 STD_ON
#define NM_ISDEF_POSTINITIALIZEDOFPCPARTITIONCONFIG                                                 STD_ON
#define NM_ISDEF_SIZEOFSYSTONMCHINDOFPCPARTITIONCONFIG                                              STD_OFF
#define NM_ISDEF_SYSTONMCHINDOFPCPARTITIONCONFIG                                                    STD_OFF
/** 
  \}
*/ 

/** 
  \defgroup  NmPCEqualsAlwaysToDefines  Nm Equals Always To Defines (PRE_COMPILE)
  \brief  If all values in a CONST array or an element in a CONST array of structs are equal, the define contains the always equals value.
  \{
*/ 
#define NM_EQ2_NMCHANNELIDOFCHANNELCONFIG                                                           
#define NM_EQ2_NMFUNCTIONTABLEIDXOFCHANNELCONFIG                                                    
#define NM_EQ2_PARTITIONCONFIGIDXOFCHANNELCONFIG                                                    
#define NM_EQ2_PDURXINDICATIONOFCHANNELCONFIG                                                       
#define NM_EQ2_CHECKREMOTESLEEPINDICATIONOFNMFUNCTIONTABLE                                          
#define NM_EQ2_DISABLECOMMUNICATIONOFNMFUNCTIONTABLE                                                
#define NM_EQ2_ENABLECOMMUNICATIONOFNMFUNCTIONTABLE                                                 
#define NM_EQ2_GETSTATEOFNMFUNCTIONTABLE                                                            
#define NM_EQ2_NETWORKRELEASEOFNMFUNCTIONTABLE                                                      
#define NM_EQ2_NETWORKREQUESTOFNMFUNCTIONTABLE                                                      
#define NM_EQ2_PASSIVESTARTUPOFNMFUNCTIONTABLE                                                      
#define NM_EQ2_PCPARTITIONCONFIGIDXOFPARTITIONIDENTIFIERS                                           
#define NM_EQ2_PARTITIONSNVOFPARTITIONIDENTIFIERS                                                   
#define NM_EQ2_SYSTONMCHIND                                                                         
#define NM_EQ2_PCPARTITIONCONFIGOFPCCONFIG                                                          
#define NM_EQ2_PARTITIONIDENTIFIERSOFPCCONFIG                                                       Nm_PartitionIdentifiers
#define NM_EQ2_CARWAKEUPCALLBACKFCTPTROFPCPARTITIONCONFIG                                           (&(Nm_CarWakeUpCallbackFctPtr))
#define NM_EQ2_CHANNELCONFIGOFPCPARTITIONCONFIG                                                     
#define NM_EQ2_INITIALIZEDOFPCPARTITIONCONFIG                                                       (&(Nm_Initialized))
#define NM_EQ2_NMFUNCTIONTABLEOFPCPARTITIONCONFIG                                                   Nm_NmFunctionTable
#define NM_EQ2_POSTINITIALIZEDOFPCPARTITIONCONFIG                                                   Nm_PostInitialized
#define NM_EQ2_SIZEOFSYSTONMCHINDOFPCPARTITIONCONFIG                                                
#define NM_EQ2_SYSTONMCHINDOFPCPARTITIONCONFIG                                                      
/** 
  \}
*/ 

/** 
  \defgroup  NmPCSymbolicInitializationPointers  Nm Symbolic Initialization Pointers (PRE_COMPILE)
  \brief  Symbolic initialization pointers to be used in the call of a preinit or init function.
  \{
*/ 
#define Nm_Config_Left_Ptr                                                                          &(Nm_PCConfig.Config_Left)  /**< symbolic identifier which shall be used to initialize 'Nm' */
#define Nm_Config_Right_Ptr                                                                         &(Nm_PCConfig.Config_Right)  /**< symbolic identifier which shall be used to initialize 'Nm' */
/** 
  \}
*/ 

/** 
  \defgroup  NmPCInitializationSymbols  Nm Initialization Symbols (PRE_COMPILE)
  \brief  Symbolic initialization pointers which may be used in the call of a preinit or init function. Please note, that the defined value can be a 'NULL_PTR' and the address operator is not usable.
  \{
*/ 
#define Nm_Config_Left                                                                              Nm_PCConfig.Config_Left  /**< symbolic identifier which could be used to initialize 'Nm */
#define Nm_Config_Right                                                                             Nm_PCConfig.Config_Right  /**< symbolic identifier which could be used to initialize 'Nm */
/** 
  \}
*/ 

/** 
  \defgroup  NmPCGeneral  Nm General (PRE_COMPILE)
  \brief  General constant defines not associated with a group of defines.
  \{
*/ 
#define NM_CHECK_INIT_POINTER                                                                       STD_ON  /**< STD_ON if the init pointer shall not be used as NULL_PTR and a check shall validate this. */
#define NM_FINAL_MAGIC_NUMBER                                                                       0x201Eu  /**< the precompile constant to validate the size of the initialization structure at initialization time of Nm */
#define NM_INDIVIDUAL_POSTBUILD                                                                     STD_OFF  /**< the precompile constant to check, that the module is individual postbuildable. The module 'Nm' is not configured to be postbuild capable. */
#define NM_INIT_DATA                                                                                NM_CONST  /**< CompilerMemClassDefine for the initialization data. */
#define NM_INIT_DATA_HASH_CODE                                                                      -2025196613  /**< the precompile constant to validate the initialization structure at initialization time of Nm with a hashcode. The seed value is '0x201Eu' */
#define NM_USE_ECUM_BSW_ERROR_HOOK                                                                  STD_OFF  /**< STD_ON if the EcuM_BswErrorHook shall be called in the ConfigPtr check. */
#define NM_USE_INIT_POINTER                                                                         STD_ON  /**< STD_ON if the init pointer Nm shall be used. */
/** 
  \}
*/ 


/**********************************************************************************************************************
  CONFIGURATION CLASS: LINK
  SECTION: GLOBAL CONSTANT MACROS
**********************************************************************************************************************/
/** 
  \defgroup  NmLTDataSwitches  Nm Data Switches  (LINK)
  \brief  These defines are used to deactivate data and their processing.
  \{
*/ 
#define NM_LTCONFIG                                                                                 STD_OFF  /**< Deactivateable: 'Nm_LTConfig' Reason: 'deactivated because PartitionConfig is deactivated.' */
#define NM_LTPARTITIONCONFIGOFLTCONFIG                                                              STD_OFF  /**< Deactivateable: 'Nm_LTConfig.LTPartitionConfig' Reason: 'deactivated because PartitionConfig is deactivated.' */
#define NM_LTPARTITIONCONFIG                                                                        STD_OFF  /**< Deactivateable: 'Nm_LTPartitionConfigLeft' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' and Deactivateable: 'Nm_LTPartitionConfigRight' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
/** 
  \}
*/ 


/**********************************************************************************************************************
  CONFIGURATION CLASS: POST_BUILD
  SECTION: GLOBAL CONSTANT MACROS
**********************************************************************************************************************/
/** 
  \defgroup  NmPBDataSwitches  Nm Data Switches  (POST_BUILD)
  \brief  These defines are used to deactivate data and their processing.
  \{
*/ 
#define NM_PBCONFIG                                                                                 STD_OFF  /**< Deactivateable: 'Nm_PBConfig' Reason: 'the module configuration is VARIANT_PRE_COMPILE.' */
#define NM_LTCONFIGIDXOFPBCONFIG                                                                    STD_OFF  /**< Deactivateable: 'Nm_PBConfig.LTConfigIdx' Reason: 'the module configuration is VARIANT_PRE_COMPILE.' */
#define NM_PBPARTITIONCONFIGOFPBCONFIG                                                              STD_OFF  /**< Deactivateable: 'Nm_PBConfig.PBPartitionConfig' Reason: 'the module configuration is VARIANT_PRE_COMPILE.' */
#define NM_PCCONFIGIDXOFPBCONFIG                                                                    STD_OFF  /**< Deactivateable: 'Nm_PBConfig.PCConfigIdx' Reason: 'the module configuration is VARIANT_PRE_COMPILE.' */
#define NM_PBPARTITIONCONFIG                                                                        STD_OFF  /**< Deactivateable: 'Nm_PBPartitionConfigLeft' Reason: 'the module configuration is VARIANT_PRE_COMPILE.' and Deactivateable: 'Nm_PBPartitionConfigRight' Reason: 'the module configuration is VARIANT_PRE_COMPILE.' */
/** 
  \}
*/ 



/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/
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
  \defgroup  NmPCGetRootDataMacros  Nm Get Root Data Macros (PRE_COMPILE)
  \brief  These macros are used to get data pointers of root data.
  \{
*/ 
#define Nm_GetPCPartitionConfigOfPCConfig()                                                         Nm_ConfigPtr->PCPartitionConfigOfPCConfig
#define Nm_GetChannelConfigOfPCPartitionConfig()                                                    Nm_GetPCPartitionConfigOfPCConfig()[(0)].ChannelConfigOfPCPartitionConfig
#define Nm_GetSizeOfSysToNmChIndOfPCPartitionConfig()                                               Nm_GetPCPartitionConfigOfPCConfig()[(0)].SizeOfSysToNmChIndOfPCPartitionConfig
#define Nm_GetSysToNmChIndOfPCPartitionConfig()                                                     Nm_GetPCPartitionConfigOfPCConfig()[(0)].SysToNmChIndOfPCPartitionConfig
/** 
  \}
*/ 

/** 
  \defgroup  NmPCGetConstantDuplicatedRootDataMacros  Nm Get Constant Duplicated Root Data Macros (PRE_COMPILE)
  \brief  These macros can be used to read deduplicated by constance root data elements.
  \{
*/ 
#define Nm_GetPartitionIdentifiersOfPCConfig()                                                      Nm_PartitionIdentifiers  /**< the pointer to Nm_PartitionIdentifiers */
#define Nm_GetSizeOfPartitionIdentifiersOfPCConfig()                                                1u  /**< the number of accomplishable value elements in Nm_PartitionIdentifiers */
#define Nm_GetCarWakeUpCallbackFctPtrOfPCPartitionConfig(partitionIndex)                            (&(Nm_CarWakeUpCallbackFctPtr))  /**< the pointer to Nm_CarWakeUpCallbackFctPtr */
#define Nm_GetInitializedOfPCPartitionConfig(partitionIndex)                                        (&(Nm_Initialized))  /**< the pointer to Nm_Initialized */
#define Nm_GetNmFunctionTableOfPCPartitionConfig()                                                  Nm_NmFunctionTable  /**< the pointer to Nm_NmFunctionTable */
#define Nm_GetPostInitializedOfPCPartitionConfig(partitionIndex)                                    Nm_PostInitialized  /**< the pointer to Nm_PostInitialized */
#define Nm_GetSizeOfChannelConfigOfPCPartitionConfig()                                              1u  /**< the number of accomplishable value elements in Nm_ChannelConfig */
#define Nm_GetSizeOfNmFunctionTableOfPCPartitionConfig()                                            1u  /**< the number of accomplishable value elements in Nm_NmFunctionTable */
#define Nm_GetSizeOfPostInitializedOfPCPartitionConfig(partitionIndex)                              1u  /**< the number of accomplishable value elements in Nm_PostInitialized */
/** 
  \}
*/ 

/** 
  \defgroup  NmPCGetDataMacros  Nm Get Data Macros (PRE_COMPILE)
  \brief  These macros can be used to read CONST and VAR data.
  \{
*/ 
#define Nm_GetCarWakeUpCallbackFctPtr(partitionIndex)                                               ((*(Nm_GetCarWakeUpCallbackFctPtrOfPCPartitionConfig(partitionIndex))))
#define Nm_GetNmChannelIdOfChannelConfig(Index)                                                     (Nm_GetChannelConfigOfPCPartitionConfig()[(Index)].NmChannelIdOfChannelConfig)
#define Nm_GetNmFunctionTableIdxOfChannelConfig(Index)                                              (Nm_GetChannelConfigOfPCPartitionConfig()[(Index)].NmFunctionTableIdxOfChannelConfig)
#define Nm_GetPartitionConfigIdxOfChannelConfig(Index)                                              (Nm_GetChannelConfigOfPCPartitionConfig()[(Index)].PartitionConfigIdxOfChannelConfig)
#define Nm_GetPduRxIndicationOfChannelConfig(Index)                                                 (Nm_GetChannelConfigOfPCPartitionConfig()[(Index)].PduRxIndicationOfChannelConfig)
#define Nm_IsInitialized(partitionIndex)                                                            (((*(Nm_GetInitializedOfPCPartitionConfig(partitionIndex)))) != FALSE)
#define Nm_GetCheckRemoteSleepIndicationOfNmFunctionTable(Index)                                    (Nm_GetNmFunctionTableOfPCPartitionConfig()[(Index)].CheckRemoteSleepIndicationOfNmFunctionTable)
#define Nm_GetDisableCommunicationOfNmFunctionTable(Index)                                          (Nm_GetNmFunctionTableOfPCPartitionConfig()[(Index)].DisableCommunicationOfNmFunctionTable)
#define Nm_GetEnableCommunicationOfNmFunctionTable(Index)                                           (Nm_GetNmFunctionTableOfPCPartitionConfig()[(Index)].EnableCommunicationOfNmFunctionTable)
#define Nm_GetGetStateOfNmFunctionTable(Index)                                                      (Nm_GetNmFunctionTableOfPCPartitionConfig()[(Index)].GetStateOfNmFunctionTable)
#define Nm_GetNetworkReleaseOfNmFunctionTable(Index)                                                (Nm_GetNmFunctionTableOfPCPartitionConfig()[(Index)].NetworkReleaseOfNmFunctionTable)
#define Nm_GetNetworkRequestOfNmFunctionTable(Index)                                                (Nm_GetNmFunctionTableOfPCPartitionConfig()[(Index)].NetworkRequestOfNmFunctionTable)
#define Nm_GetPassiveStartUpOfNmFunctionTable(Index)                                                (Nm_GetNmFunctionTableOfPCPartitionConfig()[(Index)].PassiveStartUpOfNmFunctionTable)
#define Nm_GetPCPartitionConfigIdxOfPartitionIdentifiers(Index)                                     (Nm_GetPartitionIdentifiersOfPCConfig()[(Index)].PCPartitionConfigIdxOfPartitionIdentifiers)
#define Nm_GetPartitionSNVOfPartitionIdentifiers(Index)                                             (Nm_GetPartitionIdentifiersOfPCConfig()[(Index)].PartitionSNVOfPartitionIdentifiers)
#define Nm_IsPostInitialized(Index, partitionIndex)                                                 ((Nm_GetPostInitializedOfPCPartitionConfig(partitionIndex)[(Index)]) != FALSE)
#define Nm_GetSysToNmChInd(Index)                                                                   (Nm_GetSysToNmChIndOfPCPartitionConfig()[(Index)])
/** 
  \}
*/ 

/** 
  \defgroup  NmPCGetDeduplicatedDataMacros  Nm Get Deduplicated Data Macros (PRE_COMPILE)
  \brief  These macros can be used to read deduplicated data elements.
  \{
*/ 
#define Nm_GetSizeOfChannelConfig()                                                                 Nm_GetSizeOfChannelConfigOfPCPartitionConfig()
#define Nm_GetSizeOfNmFunctionTable()                                                               Nm_GetSizeOfNmFunctionTableOfPCPartitionConfig()
#define Nm_GetSizeOfPartitionIdentifiers()                                                          Nm_GetSizeOfPartitionIdentifiersOfPCConfig()
#define Nm_GetSizeOfPostInitialized(partitionIndex)                                                 Nm_GetSizeOfPostInitializedOfPCPartitionConfig(partitionIndex)
#define Nm_GetSizeOfSysToNmChInd()                                                                  Nm_GetSizeOfSysToNmChIndOfPCPartitionConfig()
/** 
  \}
*/ 

/** 
  \defgroup  NmPCSetDataMacros  Nm Set Data Macros (PRE_COMPILE)
  \brief  These macros can be used to write data.
  \{
*/ 
#define Nm_SetInitialized(Value, partitionIndex)                                                    (*(Nm_GetInitializedOfPCPartitionConfig(partitionIndex))) = (Value)
#define Nm_SetPostInitialized(Index, Value, partitionIndex)                                         Nm_GetPostInitializedOfPCPartitionConfig(partitionIndex)[(Index)] = (Value)
/** 
  \}
*/ 

/** 
  \defgroup  NmPCHasMacros  Nm Has Macros (PRE_COMPILE)
  \brief  These macros can be used to detect at runtime a deactivated piece of information. TRUE in the CONFIGURATION_VARIANT PRE-COMPILE, TRUE or FALSE in the CONFIGURATION_VARIANT POST-BUILD.
  \{
*/ 
#define Nm_HasCarWakeUpCallbackFctPtr(partitionIndex)                                               (TRUE != FALSE)
#define Nm_HasChannelConfig()                                                                       (Nm_GetChannelConfigOfPCPartitionConfig() != NULL_PTR)
#define Nm_HasNmChannelIdOfChannelConfig()                                                          (TRUE != FALSE)
#define Nm_HasNmFunctionTableIdxOfChannelConfig()                                                   (TRUE != FALSE)
#define Nm_HasPartitionConfigIdxOfChannelConfig()                                                   (TRUE != FALSE)
#define Nm_HasPduRxIndicationOfChannelConfig()                                                      (TRUE != FALSE)
#define Nm_HasInitialized(partitionIndex)                                                           (TRUE != FALSE)
#define Nm_HasNmFunctionTable()                                                                     (TRUE != FALSE)
#define Nm_HasCheckRemoteSleepIndicationOfNmFunctionTable()                                         (TRUE != FALSE)
#define Nm_HasDisableCommunicationOfNmFunctionTable()                                               (TRUE != FALSE)
#define Nm_HasEnableCommunicationOfNmFunctionTable()                                                (TRUE != FALSE)
#define Nm_HasGetStateOfNmFunctionTable()                                                           (TRUE != FALSE)
#define Nm_HasNetworkReleaseOfNmFunctionTable()                                                     (TRUE != FALSE)
#define Nm_HasNetworkRequestOfNmFunctionTable()                                                     (TRUE != FALSE)
#define Nm_HasPassiveStartUpOfNmFunctionTable()                                                     (TRUE != FALSE)
#define Nm_HasPartitionIdentifiers()                                                                (TRUE != FALSE)
#define Nm_HasPCPartitionConfigIdxOfPartitionIdentifiers()                                          (TRUE != FALSE)
#define Nm_HasPartitionSNVOfPartitionIdentifiers()                                                  (TRUE != FALSE)
#define Nm_HasPostInitialized(partitionIndex)                                                       (TRUE != FALSE)
#define Nm_HasSizeOfChannelConfig()                                                                 (TRUE != FALSE)
#define Nm_HasSizeOfNmFunctionTable()                                                               (TRUE != FALSE)
#define Nm_HasSizeOfPartitionIdentifiers()                                                          (TRUE != FALSE)
#define Nm_HasSizeOfPostInitialized(partitionIndex)                                                 (TRUE != FALSE)
#define Nm_HasSizeOfSysToNmChInd()                                                                  (TRUE != FALSE)
#define Nm_HasSysToNmChInd()                                                                        (Nm_GetSysToNmChIndOfPCPartitionConfig() != NULL_PTR)
#define Nm_HasPCConfig()                                                                            (TRUE != FALSE)
#define Nm_HasPCPartitionConfigOfPCConfig()                                                         (TRUE != FALSE)
#define Nm_HasPartitionIdentifiersOfPCConfig()                                                      (TRUE != FALSE)
#define Nm_HasSizeOfPartitionIdentifiersOfPCConfig()                                                (TRUE != FALSE)
#define Nm_HasPCPartitionConfig()                                                                   (Nm_GetPCPartitionConfigOfPCConfig() != NULL_PTR)
#define Nm_HasCarWakeUpCallbackFctPtrOfPCPartitionConfig(partitionIndex)                            (TRUE != FALSE)
#define Nm_HasChannelConfigOfPCPartitionConfig()                                                    (TRUE != FALSE)
#define Nm_HasInitializedOfPCPartitionConfig(partitionIndex)                                        (TRUE != FALSE)
#define Nm_HasNmFunctionTableOfPCPartitionConfig()                                                  (TRUE != FALSE)
#define Nm_HasPostInitializedOfPCPartitionConfig(partitionIndex)                                    (TRUE != FALSE)
#define Nm_HasSizeOfChannelConfigOfPCPartitionConfig()                                              (TRUE != FALSE)
#define Nm_HasSizeOfNmFunctionTableOfPCPartitionConfig()                                            (TRUE != FALSE)
#define Nm_HasSizeOfPostInitializedOfPCPartitionConfig(partitionIndex)                              (TRUE != FALSE)
#define Nm_HasSizeOfSysToNmChIndOfPCPartitionConfig()                                               (TRUE != FALSE)
#define Nm_HasSysToNmChIndOfPCPartitionConfig()                                                     (TRUE != FALSE)
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
  CONFIGURATION CLASS: LINK
  SECTION: GLOBAL FUNCTION MACROS
**********************************************************************************************************************/
  /* PRQA L:Macros_3453 */
/** 
  \}
*/ 

/**********************************************************************************************************************
  CONFIGURATION CLASS: LINK
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
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
typedef uint8 Nm_ChannelModeType[NM_NUMBER_OF_CHANNEL_MODES];
typedef uint8 Nm_ChannelBusNmStateType[NM_STATE_NUMBER_OF_STATES];

/* Function Table Types */
typedef P2FUNC ( Std_ReturnType, NM_CODE, Nm_CallBusFuncTypeStandard )( CONST( NetworkHandleType, AUTOMATIC ) ); /* PRQA S 1336 */ /* MD_NM_Rule8.2 */
typedef P2FUNC ( Std_ReturnType, NM_CODE, Nm_CallBusFuncTypeSetUserData )( CONST( NetworkHandleType, AUTOMATIC ), CONSTP2CONST( uint8, AUTOMATIC, NM_APPL_VAR ) ); /* PRQA S 1336 */ /* MD_NM_Rule8.2 */
typedef P2FUNC ( Std_ReturnType, NM_CODE, Nm_CallBusFuncTypeGetData )( CONST( NetworkHandleType, AUTOMATIC ), CONSTP2VAR( uint8, AUTOMATIC, NM_APPL_VAR ) ); /* PRQA S 1336 */ /* MD_NM_Rule8.2 */
typedef P2FUNC ( Std_ReturnType, NM_CODE, Nm_CallBusFuncTypeGetState )( CONST( NetworkHandleType, AUTOMATIC ), CONSTP2VAR( Nm_StateType, AUTOMATIC, NM_APPL_VAR ), CONSTP2VAR( Nm_ModeType, AUTOMATIC, NM_APPL_VAR ) ); /* PRQA S 1336 */ /* MD_NM_Rule8.2 */
typedef P2FUNC ( Std_ReturnType, NM_CODE, Nm_CallBusFuncTypeSetSleepReady )( CONST( NetworkHandleType, AUTOMATIC ), CONST( uint8, AUTOMATIC) ); /* PRQA S 1336 */ /* MD_NM_Rule8.2 */
typedef P2FUNC ( Std_ReturnType, NM_CODE, Nm_CallBusFuncTypeRequestSyncPncShutdown )( CONST( NetworkHandleType, AUTOMATIC ), CONST( PNCHandleType, AUTOMATIC) ); /* PRQA S 1336 */ /* MD_NM_Rule8.2 */
typedef P2FUNC ( void, NM_APPL_CODE, Nm_CallbackFunction )( CONST( NetworkHandleType, AUTOMATIC ) ); /* PRQA S 1336 */ /* MD_NM_Rule8.2 */
typedef P2FUNC ( void, NM_APPL_CODE, Nm_CallbackFunctionWithPduInfoType )( CONST( NetworkHandleType, AUTOMATIC ), CONSTP2CONST( PduInfoType, AUTOMATIC, AUTOMATIC ) ); /* PRQA S 1336 */ /* MD_NM_Rule8.2 */
typedef P2FUNC ( void, NM_CODE, Nm_ForwardingFunctionPtrType ) (CONST( NetworkHandleType, AUTOMATIC ) ); /* PRQA S 1336 */ /* MD_NM_Rule8.2 */
typedef P2FUNC ( void, NM_CODE, Nm_ForwardingFunctionPtrBusNmType ) (CONST( NetworkHandleType, AUTOMATIC ), CONST( uint8_least, AUTOMATIC )); /* PRQA S 1336 */ /* MD_NM_Rule8.2 */


/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: SIZEOF DATA TYPES
**********************************************************************************************************************/
/** 
  \defgroup  NmPCSizeOfTypes  Nm SizeOf Types (PRE_COMPILE)
  \brief  These type definitions are used for the SizeOf information.
  \{
*/ 
/**   \brief  value based type definition for Nm_SizeOfChannelConfig */
typedef uint8 Nm_SizeOfChannelConfigType;

/**   \brief  value based type definition for Nm_SizeOfNmFunctionTable */
typedef uint8 Nm_SizeOfNmFunctionTableType;

/**   \brief  value based type definition for Nm_SizeOfPartitionIdentifiers */
typedef uint8 Nm_SizeOfPartitionIdentifiersType;

/**   \brief  value based type definition for Nm_SizeOfPostInitialized */
typedef uint8 Nm_SizeOfPostInitializedType;

/**   \brief  value based type definition for Nm_SizeOfSysToNmChInd */
typedef uint8 Nm_SizeOfSysToNmChIndType;

/** 
  \}
*/ 

/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL SIMPLE DATA TYPES AND STRUCTURES
**********************************************************************************************************************/
/** 
  \defgroup  NmPCIterableTypes  Nm Iterable Types (PRE_COMPILE)
  \brief  These type definitions are used to iterate over an array with least processor cycles for variable access as possible.
  \{
*/ 
/**   \brief  type used to iterate Nm_ChannelConfig */
typedef uint8_least Nm_ChannelConfigIterType;

/**   \brief  type used to iterate Nm_NmFunctionTable */
typedef uint8_least Nm_NmFunctionTableIterType;

/**   \brief  type used to iterate Nm_PartitionIdentifiers */
typedef uint8_least Nm_PartitionIdentifiersIterType;

/**   \brief  type used to iterate Nm_PostInitialized */
typedef uint8_least Nm_PostInitializedIterType;

/**   \brief  type used to iterate Nm_SysToNmChInd */
typedef uint8_least Nm_SysToNmChIndIterType;

/**   \brief  type used to iterate Nm_PCPartitionConfig */
typedef uint8_least Nm_PCPartitionConfigIterType;

/** 
  \}
*/ 

/** 
  \defgroup  NmPCValueTypes  Nm Value Types (PRE_COMPILE)
  \brief  These type definitions are used for value based data representations.
  \{
*/ 
/**   \brief  value based type definition for Nm_NmChannelIdOfChannelConfig */
typedef uint8 Nm_NmChannelIdOfChannelConfigType;

/**   \brief  value based type definition for Nm_NmFunctionTableIdxOfChannelConfig */
typedef uint8 Nm_NmFunctionTableIdxOfChannelConfigType;

/**   \brief  value based type definition for Nm_PartitionConfigIdxOfChannelConfig */
typedef uint8 Nm_PartitionConfigIdxOfChannelConfigType;

/**   \brief  value based type definition for Nm_Initialized */
typedef boolean Nm_InitializedType;

/**   \brief  value based type definition for Nm_PCPartitionConfigIdxOfPartitionIdentifiers */
typedef uint8 Nm_PCPartitionConfigIdxOfPartitionIdentifiersType;

/**   \brief  value based type definition for Nm_PartitionSNVOfPartitionIdentifiers */
typedef uint32 Nm_PartitionSNVOfPartitionIdentifiersType;

/**   \brief  value based type definition for Nm_PostInitialized */
typedef boolean Nm_PostInitializedType;

/**   \brief  value based type definition for Nm_SysToNmChInd */
typedef uint8 Nm_SysToNmChIndType;

/** 
  \}
*/ 

/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL COMPLEX DATA TYPES AND STRUCTURES
**********************************************************************************************************************/
/** 
  \defgroup  NmPCStructTypes  Nm Struct Types (PRE_COMPILE)
  \brief  These type definitions are used for structured data representations.
  \{
*/ 
/**   \brief  type used in Nm_ChannelConfig */
typedef struct sNm_ChannelConfigType
{
  Nm_NmChannelIdOfChannelConfigType NmChannelIdOfChannelConfig;
  Nm_NmFunctionTableIdxOfChannelConfigType NmFunctionTableIdxOfChannelConfig;  /**< the index of the 1:1 relation pointing to Nm_NmFunctionTable */
  Nm_PartitionConfigIdxOfChannelConfigType PartitionConfigIdxOfChannelConfig;  /**< the index of the 1:1 relation pointing to Nm_PCPartitionConfig */
  Nm_CallbackFunctionWithPduInfoType PduRxIndicationOfChannelConfig;
} Nm_ChannelConfigType;

/**   \brief  type used in Nm_NmFunctionTable */
typedef struct sNm_NmFunctionTableType
{
  Nm_CallBusFuncTypeGetData CheckRemoteSleepIndicationOfNmFunctionTable;
  Nm_CallBusFuncTypeGetState GetStateOfNmFunctionTable;
  Nm_CallBusFuncTypeStandard DisableCommunicationOfNmFunctionTable;
  Nm_CallBusFuncTypeStandard EnableCommunicationOfNmFunctionTable;
  Nm_CallBusFuncTypeStandard NetworkReleaseOfNmFunctionTable;
  Nm_CallBusFuncTypeStandard NetworkRequestOfNmFunctionTable;
  Nm_CallBusFuncTypeStandard PassiveStartUpOfNmFunctionTable;
} Nm_NmFunctionTableType;

/**   \brief  type used in Nm_PartitionIdentifiers */
typedef struct sNm_PartitionIdentifiersType
{
  Nm_PartitionSNVOfPartitionIdentifiersType PartitionSNVOfPartitionIdentifiers;
  Nm_PCPartitionConfigIdxOfPartitionIdentifiersType PCPartitionConfigIdxOfPartitionIdentifiers;  /**< the index of the 1:1 relation pointing to Nm_PCPartitionConfig */
} Nm_PartitionIdentifiersType;

/** 
  \}
*/ 

/** 
  \defgroup  NmPCRootPointerTypes  Nm Root Pointer Types (PRE_COMPILE)
  \brief  These type definitions are used to point from the config root to symbol instances.
  \{
*/ 
/**   \brief  type used to point to Nm_CarWakeUpCallbackFctPtr */
typedef P2CONST(Nm_CallbackFunction, TYPEDEF, NM_CONST) Nm_CarWakeUpCallbackFctPtrPtrType;

/**   \brief  type used to point to Nm_ChannelConfig */
typedef P2CONST(Nm_ChannelConfigType, TYPEDEF, NM_CONST) Nm_ChannelConfigPtrType;

/**   \brief  type used to point to Nm_Initialized */
typedef P2VAR(Nm_InitializedType, TYPEDEF, NM_VAR_NO_INIT) Nm_InitializedPtrType;

/**   \brief  type used to point to Nm_NmFunctionTable */
typedef P2CONST(Nm_NmFunctionTableType, TYPEDEF, NM_CONST) Nm_NmFunctionTablePtrType;

/**   \brief  type used to point to Nm_PartitionIdentifiers */
typedef P2CONST(Nm_PartitionIdentifiersType, TYPEDEF, NM_CONST) Nm_PartitionIdentifiersPtrType;

/**   \brief  type used to point to Nm_PostInitialized */
typedef P2VAR(Nm_PostInitializedType, TYPEDEF, NM_VAR_NO_INIT) Nm_PostInitializedPtrType;

/**   \brief  type used to point to Nm_SysToNmChInd */
typedef P2CONST(Nm_SysToNmChIndType, TYPEDEF, NM_CONST) Nm_SysToNmChIndPtrType;

/** 
  \}
*/ 

/** 
  \defgroup  NmPCPartitionRootPointer  Nm Partition Root Pointer (PRE_COMPILE)
  \brief  This type definitions are used for partition specific instance.
  \{
*/ 
/**   \brief  type used in Nm_PCPartitionConfig */
typedef struct sNm_PCPartitionConfigType
{
  Nm_ChannelConfigPtrType ChannelConfigOfPCPartitionConfig;  /**< the pointer to Nm_ChannelConfig */
  Nm_SysToNmChIndPtrType SysToNmChIndOfPCPartitionConfig;  /**< the pointer to Nm_SysToNmChInd */
  Nm_SizeOfSysToNmChIndType SizeOfSysToNmChIndOfPCPartitionConfig;  /**< the number of accomplishable value elements in Nm_SysToNmChInd */
} Nm_PCPartitionConfigType;

/**   \brief  type used to point to Nm_PCPartitionConfig */
typedef P2CONST(Nm_PCPartitionConfigType, TYPEDEF, NM_CONST) Nm_PCPartitionConfigPtrType;

/** 
  \}
*/ 

/** 
  \defgroup  NmPCRootValueTypes  Nm Root Value Types (PRE_COMPILE)
  \brief  These type definitions are used for value representations in root arrays.
  \{
*/ 
/**   \brief  type used in Nm_PCConfig */
typedef struct sNm_PCConfigType
{
  Nm_PCPartitionConfigPtrType PCPartitionConfigOfPCConfig;  /**< the pointer to Nm_PCPartitionConfig */
} Nm_PCConfigType;

typedef Nm_PCConfigType Nm_ConfigType;  /**< A structure type is present for data in each configuration class. This typedef redefines the probably different name to the specified one. */

/**   \brief  type to access Nm_PCConfig in a symbol based style. */
typedef struct sNm_PCConfigsType
{
  Nm_PCConfigType Config_Left;  /**< [Config_Left] */
  Nm_PCConfigType Config_Right;  /**< [Config_Right] */
} Nm_PCConfigsType;

/** 
  \}
*/ 


/**********************************************************************************************************************
  CONFIGURATION CLASS: LINK
  SECTION: SIZEOF DATA TYPES
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: LINK
  SECTION: GLOBAL SIMPLE DATA TYPES AND STRUCTURES
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: LINK
  SECTION: GLOBAL COMPLEX DATA TYPES AND STRUCTURES
**********************************************************************************************************************/

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


/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/
/* \trace SPEC-4203, SPEC-4204, SPEC-4205, SPEC-4208 */
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL DATA PROTOTYPES
**********************************************************************************************************************/
/**********************************************************************************************************************
  Nm_CarWakeUpCallbackFctPtr
**********************************************************************************************************************/
/** 
  \var    Nm_CarWakeUpCallbackFctPtr
  \brief  Car Wake Up Callback
*/ 
#define NM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Nm_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(Nm_CallbackFunction, NM_CONST) Nm_CarWakeUpCallbackFctPtr;
#define NM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Nm_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Nm_ChannelConfigLeft
**********************************************************************************************************************/
/** 
  \var    Nm_ChannelConfigLeft
  \brief  Structure for channel specific configuration parameters
  \details
  Element               Description
  NmChannelId       
  NmFunctionTableIdx    the index of the 1:1 relation pointing to Nm_NmFunctionTable
  PartitionConfigIdx    the index of the 1:1 relation pointing to Nm_PCPartitionConfig
  PduRxIndication   
*/ 
#define NM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Nm_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(Nm_ChannelConfigType, NM_CONST) Nm_ChannelConfigLeft[1];
#define NM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Nm_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Nm_ChannelConfigRight
**********************************************************************************************************************/
/** 
  \var    Nm_ChannelConfigRight
  \brief  Structure for channel specific configuration parameters
  \details
  Element               Description
  NmChannelId       
  NmFunctionTableIdx    the index of the 1:1 relation pointing to Nm_NmFunctionTable
  PartitionConfigIdx    the index of the 1:1 relation pointing to Nm_PCPartitionConfig
  PduRxIndication   
*/ 
#define NM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Nm_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(Nm_ChannelConfigType, NM_CONST) Nm_ChannelConfigRight[1];
#define NM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Nm_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Nm_NmFunctionTable
**********************************************************************************************************************/
/** 
  \var    Nm_NmFunctionTable
  \details
  Element                       Description
  CheckRemoteSleepIndication
  GetState                  
  DisableCommunication      
  EnableCommunication       
  NetworkRelease            
  NetworkRequest            
  PassiveStartUp            
*/ 
#define NM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Nm_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(Nm_NmFunctionTableType, NM_CONST) Nm_NmFunctionTable[1];
#define NM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Nm_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Nm_PartitionIdentifiers
**********************************************************************************************************************/
/** 
  \var    Nm_PartitionIdentifiers
  \brief  the partition context in Config_Left
  \details
  Element                 Description
  PartitionSNV        
  PCPartitionConfigIdx    the index of the 1:1 relation pointing to Nm_PCPartitionConfig
*/ 
#define NM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Nm_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(Nm_PartitionIdentifiersType, NM_CONST) Nm_PartitionIdentifiers[1];
#define NM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Nm_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Nm_SysToNmChInd
**********************************************************************************************************************/
/** 
  \var    Nm_SysToNmChInd
  \brief  Channel indirection: System Channel handle to NM channel handle
*/ 
#define NM_START_SEC_CONST_8
/*lint -save -esym(961, 19.1) */
#include "Nm_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(Nm_SysToNmChIndType, NM_CONST) Nm_SysToNmChInd[2];
#define NM_STOP_SEC_CONST_8
/*lint -save -esym(961, 19.1) */
#include "Nm_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Nm_Initialized
**********************************************************************************************************************/
/** 
  \var    Nm_Initialized
  \brief  Initialized state
*/ 
#define NM_START_SEC_VAR_NO_INIT_8
/*lint -save -esym(961, 19.1) */
#include "Nm_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(Nm_InitializedType, NM_VAR_NO_INIT) Nm_Initialized;
#define NM_STOP_SEC_VAR_NO_INIT_8
/*lint -save -esym(961, 19.1) */
#include "Nm_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Nm_PostInitialized
**********************************************************************************************************************/
/** 
  \var    Nm_PostInitialized
  \brief  Post-Initialized state
*/ 
#define NM_START_SEC_VAR_NO_INIT_8
/*lint -save -esym(961, 19.1) */
#include "Nm_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(Nm_PostInitializedType, NM_VAR_NO_INIT) Nm_PostInitialized[1];
#define NM_STOP_SEC_VAR_NO_INIT_8
/*lint -save -esym(961, 19.1) */
#include "Nm_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Nm_PCConfig
**********************************************************************************************************************/
/** 
  \var    Nm_PCConfig
  \details
  Element              Description
  PCPartitionConfig    the pointer to Nm_PCPartitionConfig
*/ 
#define NM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Nm_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(Nm_PCConfigsType, NM_CONST) Nm_PCConfig;
#define NM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Nm_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Nm_PCPartitionConfigLeft
**********************************************************************************************************************/
/** 
  \var    Nm_PCPartitionConfigLeft
  \details
  Element               Description
  ChannelConfig         the pointer to Nm_ChannelConfig
  SysToNmChInd          the pointer to Nm_SysToNmChInd
  SizeOfSysToNmChInd    the number of accomplishable value elements in Nm_SysToNmChInd
*/ 
#define NM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Nm_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(Nm_PCPartitionConfigType, NM_CONST) Nm_PCPartitionConfigLeft[1];
#define NM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Nm_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Nm_PCPartitionConfigRight
**********************************************************************************************************************/
/** 
  \var    Nm_PCPartitionConfigRight
  \details
  Element               Description
  ChannelConfig         the pointer to Nm_ChannelConfig
  SysToNmChInd          the pointer to Nm_SysToNmChInd
  SizeOfSysToNmChInd    the number of accomplishable value elements in Nm_SysToNmChInd
*/ 
#define NM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Nm_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(Nm_PCPartitionConfigType, NM_CONST) Nm_PCPartitionConfigRight[1];
#define NM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Nm_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */


/**********************************************************************************************************************
  CONFIGURATION CLASS: LINK
  SECTION: GLOBAL DATA PROTOTYPES
**********************************************************************************************************************/


/**********************************************************************************************************************
  CONFIGURATION CLASS: POST_BUILD
  SECTION: GLOBAL DATA PROTOTYPES
**********************************************************************************************************************/



#if ( NM_USE_INIT_POINTER == STD_ON )
# define NM_START_SEC_VAR_INIT_UNSPECIFIED
# include "Nm_MemMap.h"    /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* Pointer to Postbuild configuration */
extern P2CONST(Nm_ConfigType, NM_VAR_INIT, NM_CONST) Nm_ConfigPtr;

# define NM_STOP_SEC_VAR_INIT_UNSPECIFIED
# include "Nm_MemMap.h"    /* PRQA S 5087 */ /* MD_MSR_MemMap */
#endif

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/





#endif /* NM_CFG_H */

/**********************************************************************************************************************
 *  END OF FILE: Nm_Cfg.h
 *********************************************************************************************************************/

