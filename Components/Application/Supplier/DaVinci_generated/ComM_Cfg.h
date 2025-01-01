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
 *            Module: ComM
 *           Program: MSR_Daimler_SLP11
 *          Customer: Mercedes-Benz AG
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: TC3xx
 *    License Scope : The usage is restricted to CBD2200333_D05
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: ComM_Cfg.h
 *   Generation Time: 2023-07-10 14:36:05
 *           Project: StartApplication - Version 1.0
 *          Delivery: CBD2200333_D05
 *      Tool Version: DaVinci Configurator Classic 5.25.50 SP5
 *
 *
 *********************************************************************************************************************/


#if !defined(COMM_CFG_H)
#define COMM_CFG_H

/* -----------------------------------------------------------------------------
    &&&~ INCLUDES
 ----------------------------------------------------------------------------- */

#include "ComM_Types.h"
#include "Com_Types.h"
#include "Os.h"
/* -----------------------------------------------------------------------------
    &&&~ CONFIGURATION DEFINES
 ----------------------------------------------------------------------------- */

#ifndef COMM_USE_DUMMY_STATEMENT
#define COMM_USE_DUMMY_STATEMENT STD_OFF /* /MICROSAR/vSet/vSetGeneral/vSetDummyStatementKind */
#endif
#ifndef COMM_DUMMY_STATEMENT
#define COMM_DUMMY_STATEMENT(v)  /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */  /* /MICROSAR/vSet/vSetGeneral/vSetDummyStatementKind */
#endif
#ifndef COMM_DUMMY_STATEMENT_CONST
#define COMM_DUMMY_STATEMENT_CONST(v)  /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */  /* /MICROSAR/vSet/vSetGeneral/vSetDummyStatementKind */
#endif
#ifndef COMM_ATOMIC_BIT_ACCESS_IN_BITFIELD
#define COMM_ATOMIC_BIT_ACCESS_IN_BITFIELD STD_OFF /* /MICROSAR/EcuC/EcucGeneral/AtomicBitAccessInBitfield */
#endif
#ifndef COMM_ATOMIC_VARIABLE_ACCESS
#define COMM_ATOMIC_VARIABLE_ACCESS 32u /* /MICROSAR/EcuC/EcucGeneral/AtomicVariableAccess */
#endif
#ifndef COMM_PROCESSOR_TC322L
#define COMM_PROCESSOR_TC322L
#endif
#ifndef COMM_COMP_TASKING
#define COMM_COMP_TASKING
#endif
#ifndef COMM_GEN_GENERATOR_MSR
#define COMM_GEN_GENERATOR_MSR
#endif
#ifndef COMM_CPUTYPE_BITORDER_LSB2MSB
#define COMM_CPUTYPE_BITORDER_LSB2MSB /* /MICROSAR/vSet/vSetPlatform/vSetBitOrder */
#endif
#ifndef COMM_CONFIGURATION_VARIANT_PRECOMPILE
#define COMM_CONFIGURATION_VARIANT_PRECOMPILE 1
#endif
#ifndef COMM_CONFIGURATION_VARIANT_LINKTIME
#define COMM_CONFIGURATION_VARIANT_LINKTIME 2
#endif
#ifndef COMM_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE
#define COMM_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE 3
#endif
#ifndef COMM_CONFIGURATION_VARIANT
#define COMM_CONFIGURATION_VARIANT COMM_CONFIGURATION_VARIANT_PRECOMPILE
#endif
#ifndef COMM_POSTBUILD_VARIANT_SUPPORT
#define COMM_POSTBUILD_VARIANT_SUPPORT STD_ON
#endif

#ifndef COMM_DEV_ERROR_DETECT
#define COMM_DEV_ERROR_DETECT STD_ON
#endif
#ifndef COMM_DEV_ERROR_REPORT
#define COMM_DEV_ERROR_REPORT STD_OFF
#endif

#define COMM_VERSION_INFO_API                                             STD_OFF

#define COMM_MODE_LIMITATION                                              STD_ON
#define COMM_WAKEUP_INHIBITION                                            STD_ON

#define COMM_PNC_SUPPORT                                                  STD_ON
#define COMM_PNC_ACTIVE_COORD                                             STD_OFF
#define COMM_PNC_PS_TIMER                                                 260u
#define COMM_ACTIVE_PNC                                                   2u
#define COMM_PNC_EXTENDED_FUNCTIONALITY_ENABLED                           STD_OFF

#define COMM_SYNCHRONIZED_PNC_SHUTDOWN_ENABLED                            STD_OFF

#define COMM_PNC_TO_CHANNEL_ROUTING_LIMITATION_ENABLED                    STD_OFF
#define COMM_PNC_PASSIVE_GW_SUPPORT                                       STD_OFF
#define COMM_PNC_EXISTS_COORD_PNC_WITH_GW_PASSIVE_AND_MANAGED_CHANNELS    STD_OFF
#define COMM_PNC_EXISTS_GATEWAY_TYPE_ACTIVE                               STD_OFF
#define COMM_PNC_EXISTS_GATEWAY_TYPE_NONE                                 STD_OFF
#define COMM_PNC_SIGNAL_LENGTH                                            7u
#define COMM_PNC_MAX_NUMBER_OF_EIRA_RX                                    1u
#define COMM_PNC_CHECK_ENABLED_AT_RUNTIME                                 STD_OFF
#define COMM_PNC_0_VECTOR_AVOIDANCE                                       STD_OFF

#define COMM_NM_GW_EXT_ENABLED                                            STD_OFF
#define COMM_KEEP_AWAKE_CHANNELS_SUPPORT                                  STD_ON
#define COMM_BUS_TYPE_INTERNAL_PRESENT                                    STD_OFF
#define COMM_BUS_TYPE_FR_PRESENT                                          STD_OFF
#define COMM_BUS_TYPE_LIN_PRESENT                                         STD_OFF
#define COMM_EXISTS_ONLY_NONE_NMTYPEOFCHANNEL                             STD_OFF

#define COMM_FULL_COMM_REQUEST_NOTIF                                      STD_OFF
#define COMM_MAX_NUMBER_OF_USERS                                          3u
#define COMM_DCM_INDICATION                                               STD_ON
#define COMM_USERMODENOTIFUNC_PNC_USER_ONLY                               STD_ON
#define COMM_EXISTS_USER_WITH_SINGLE_PNC                                  STD_ON

#define COMM_SYNCHRONOUS_WAKE_UP                                          STD_ON
#define COMM_EXTENDED_RAM_CHECK                                           STD_OFF

#define COMM_NVM_SUPPORT                                                  STD_OFF

#define COMM_MULTIPARTITION                                               STD_OFF
#define COMM_EXISTS_CHANNEL_ON_MASTER_PARTITION                           STD_ON
#define COMM_EXISTS_USER_ON_SATELLITE_PARTITION                           STD_OFF
#define COMM_EXISTS_USER_ON_MASTER_PARTITION                              STD_ON



#define COMM_MASTER_PARTITION_IDX                       0u
#define COMM_SINGLEPARTITION                            0u

#define COMM_NO_SYMBOLICNAMEVALUE                       65535u
/* -----------------------------------------------------------------------------
    &&&~ USER HANDLES
 ----------------------------------------------------------------------------- */

#define ComMConf_ComMUser_PNC_00_MAPPING_60241c9f                          1u 
#define ComMConf_ComMUser_PNC_20_MAPPING_4fe27ecf                          2u 
#define ComMConf_ComMUser_RBTM_FL_BODY3_8uqv9blm85ehm0msat385m76v_a4eabb6e 0u 
#define ComMConf_ComMUser_RBTM_FR_BODY3_4xwwtd59665s787n6ctawh7k8_1f2180a7 0u 


/* -----------------------------------------------------------------------------
    &&&~ CHANNEL HANDLES
 ----------------------------------------------------------------------------- */

#define ComMConf_ComMChannel_RBTM_FL_BODY3_8uqv9blm85ehm0msat385m76v_03d5f5f6 0u 
#define ComMConf_ComMChannel_RBTM_FR_BODY3_4xwwtd59665s787n6ctawh7k8_23a94727 1u 


/* -----------------------------------------------------------------------------
    &&&~ PNC HANDLES
 ----------------------------------------------------------------------------- */

#define ComMConf_ComMPnc_PNC_00_MAPPING_b2c42696 8u 
#define ComMConf_ComMPnc_PNC_20_MAPPING_796df885 28u 


/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL CONSTANT MACROS
**********************************************************************************************************************/
/** 
  \defgroup  ComMPCDataSwitches  ComM Data Switches  (PRE_COMPILE)
  \brief  These defines are used to deactivate data and their processing.
  \{
*/ 
#define COMM_ACTIVECOMMODE                                                                          STD_ON
#define COMM_ACTIVEPNCCOMMODE                                                                       STD_ON
#define COMM_BUSCOMMODEREQ                                                                          STD_ON
#define COMM_BUSCOMMODEREQFRSHUTDOWN                                                                STD_OFF  /**< Deactivateable: 'ComM_BusComModeReqFrShutdown' Reason: 'Fr support is not present' and Deactivateable: 'ComM_BusComModeReqFrShutdown' Reason: 'Fr support is not present' */
#define COMM_BUSPNCCOMMODEREQ                                                                       STD_ON
#define COMM_BUSSLEEPMODEINDICATED                                                                  STD_OFF  /**< Deactivateable: 'ComM_BusSleepModeIndicated' Reason: 'NM variant LINSLAVE is not present' and Deactivateable: 'ComM_BusSleepModeIndicated' Reason: 'NM variant LINSLAVE is not present' */
#define COMM_BUSSMSTATE                                                                             STD_ON
#define COMM_CHANNEL                                                                                STD_ON
#define COMM_BUSTYPEOFCHANNEL                                                                       STD_ON
#define COMM_ENABLEDOFCHANNEL                                                                       STD_ON
#define COMM_GETCURRENTBUSSMMODEAPIOFCHANNEL                                                        STD_ON
#define COMM_GWTYPEOFCHANNEL                                                                        STD_ON
#define COMM_INHIBITIONINITVALUEOFCHANNEL                                                           STD_ON
#define COMM_J1939SUPPORTOFCHANNEL                                                                  STD_OFF  /**< Deactivateable: 'ComM_ChannelLeft.J1939Support' Reason: 'the value of ComM_J1939SupportOfChannel is always 'false' due to this, the array is deactivated.' and Deactivateable: 'ComM_ChannelRight.J1939Support' Reason: 'the value of ComM_J1939SupportOfChannel is always 'false' due to this, the array is deactivated.' */
#define COMM_MAINFUNCTIONNEEDSSYNCOFCHANNEL                                                         STD_OFF  /**< Deactivateable: 'ComM_ChannelLeft.MainFunctionNeedsSync' Reason: 'Configuration is single partition.' and Deactivateable: 'ComM_ChannelRight.MainFunctionNeedsSync' Reason: 'Configuration is single partition.' */
#define COMM_MANAGINGCHANNELIDOFCHANNEL                                                             STD_OFF  /**< Deactivateable: 'ComM_ChannelLeft.ManagingChannelId' Reason: 'the value of ComM_ManagingChannelIdOfChannel is always 'COMM_NO_MANAGINGCHANNELIDOFCHANNEL' due to this, the array is deactivated.' and Deactivateable: 'ComM_ChannelRight.ManagingChannelId' Reason: 'the value of ComM_ManagingChannelIdOfChannel is always 'COMM_NO_MANAGINGCHANNELIDOFCHANNEL' due to this, the array is deactivated.' */
#define COMM_MANAGINGCHANNELOFCHANNEL                                                               STD_OFF  /**< Deactivateable: 'ComM_ChannelLeft.ManagingChannel' Reason: 'the value of ComM_ManagingChannelOfChannel is always 'false' due to this, the array is deactivated.' and Deactivateable: 'ComM_ChannelRight.ManagingChannel' Reason: 'the value of ComM_ManagingChannelOfChannel is always 'false' due to this, the array is deactivated.' */
#define COMM_MANAGINGUSEROFCHANNEL                                                                  STD_OFF  /**< Deactivateable: 'ComM_ChannelLeft.ManagingUser' Reason: 'the value of ComM_ManagingUserOfChannel is always 'COMM_NO_MANAGINGUSEROFCHANNEL' due to this, the array is deactivated.' and Deactivateable: 'ComM_ChannelRight.ManagingUser' Reason: 'the value of ComM_ManagingUserOfChannel is always 'COMM_NO_MANAGINGUSEROFCHANNEL' due to this, the array is deactivated.' */
#define COMM_MINFULLCOMTIMEOFCHANNEL                                                                STD_OFF  /**< Deactivateable: 'ComM_ChannelLeft.MinFullComTime' Reason: 'the value of ComM_MinFullComTimeOfChannel is always '0' due to this, the array is deactivated.' and Deactivateable: 'ComM_ChannelRight.MinFullComTime' Reason: 'the value of ComM_MinFullComTimeOfChannel is always '0' due to this, the array is deactivated.' */
#define COMM_NMLIGHTDURATIONOFCHANNEL                                                               STD_OFF  /**< Deactivateable: 'ComM_ChannelLeft.NmLightDuration' Reason: 'the value of ComM_NmLightDurationOfChannel is always '0' due to this, the array is deactivated.' and Deactivateable: 'ComM_ChannelRight.NmLightDuration' Reason: 'the value of ComM_NmLightDurationOfChannel is always '0' due to this, the array is deactivated.' */
#define COMM_NMLIGHTSILENTDURATIONOFCHANNEL                                                         STD_OFF  /**< Deactivateable: 'ComM_ChannelLeft.NmLightSilentDuration' Reason: 'the value of ComM_NmLightSilentDurationOfChannel is always '0' due to this, the array is deactivated.' and Deactivateable: 'ComM_ChannelRight.NmLightSilentDuration' Reason: 'the value of ComM_NmLightSilentDurationOfChannel is always '0' due to this, the array is deactivated.' */
#define COMM_NMSUPPORTOFCHANNEL                                                                     STD_ON
#define COMM_NMTYPEOFCHANNEL                                                                        STD_ON
#define COMM_PARTITIONCONFIGIDXOFCHANNEL                                                            STD_ON
#define COMM_PASSIVEORLINSLAVEOFCHANNEL                                                             STD_OFF  /**< Deactivateable: 'ComM_ChannelLeft.PassiveOrLinSlave' Reason: 'the value of ComM_PassiveOrLinSlaveOfChannel is always 'false' due to this, the array is deactivated.' and Deactivateable: 'ComM_ChannelRight.PassiveOrLinSlave' Reason: 'the value of ComM_PassiveOrLinSlaveOfChannel is always 'false' due to this, the array is deactivated.' */
#define COMM_PNCNMREQUESTOFCHANNEL                                                                  STD_ON
#define COMM_REQUESTBUSSMMODEAPIOFCHANNEL                                                           STD_ON
#define COMM_RESETAFTERFORCINGNOCOMMOFCHANNEL                                                       STD_ON
#define COMM_SILENTSUPPORTOFCHANNEL                                                                 STD_ON
#define COMM_WAKEUPSTATEOFCHANNEL                                                                   STD_ON
#define COMM_CHANNELPB                                                                              STD_ON
#define COMM_PNCPBINDENDIDXOFCHANNELPB                                                              STD_ON
#define COMM_PNCPBINDSTARTIDXOFCHANNELPB                                                            STD_ON
#define COMM_PNCPBINDUSEDOFCHANNELPB                                                                STD_ON
#define COMM_USERREQFULLCOMENDIDXOFCHANNELPB                                                        STD_ON
#define COMM_USERREQFULLCOMSTARTIDXOFCHANNELPB                                                      STD_ON
#define COMM_USERREQFULLCOMUSEDOFCHANNELPB                                                          STD_ON
#define COMM_COMALLOWED                                                                             STD_ON
#define COMM_DCMREQUESTACTIVE                                                                       STD_ON
#define COMM_ECUMWAKEUPINDICATED                                                                    STD_ON
#define COMM_EIRATXSIGNALINDIRECTION                                                                STD_ON
#define COMM_SYMBOLICNAMEVALUEOFEIRATXSIGNALINDIRECTION                                             STD_ON
#define COMM_FINALMAGICNUMBER                                                                       STD_OFF  /**< Deactivateable: 'ComM_FinalMagicNumber' Reason: 'the module configuration does not support flashing of data.' */
#define COMM_FORWARDSYNCHRONIZEDPNCSHUTDOWNINDICATED                                                STD_OFF  /**< Deactivateable: 'ComM_ForwardSynchronizedPncShutdownIndicated' Reason: 'Synchronized PNC Shutdown is disabled or no Intermediate PNC Coordinator exists.' and Deactivateable: 'ComM_ForwardSynchronizedPncShutdownIndicated' Reason: 'Synchronized PNC Shutdown is disabled or no Intermediate PNC Coordinator exists.' */
#define COMM_FRSHUTDOWN                                                                             STD_OFF  /**< Deactivateable: 'ComM_FrShutdown' Reason: 'Fr support is not present' and Deactivateable: 'ComM_FrShutdown' Reason: 'Fr support is not present' */
#define COMM_FULLCOMREQUESTERS                                                                      STD_OFF  /**< Deactivateable: 'ComM_FullComRequesters' Reason: 'Deactivated because no channel had ComMFullCommRequestNoficiation enabled' and Deactivateable: 'ComM_FullComRequesters' Reason: 'Deactivated because no channel had ComMFullCommRequestNoficiation enabled' */
#define COMM_INHIBITION                                                                             STD_ON
#define COMM_INITDATAHASHCODE                                                                       STD_OFF  /**< Deactivateable: 'ComM_InitDataHashCode' Reason: 'the module configuration does not support flashing of data.' */
#define COMM_INITSTATUS                                                                             STD_ON
#define COMM_LASTSTATECHANGE                                                                        STD_OFF  /**< Deactivateable: 'ComM_LastStateChange' Reason: 'No user mode Notification configured.' and Deactivateable: 'ComM_LastStateChange' Reason: 'No user mode Notification configured.' */
#define COMM_MINFULLCOMMODETIMER                                                                    STD_OFF  /**< Deactivateable: 'ComM_MinFullComModeTimer' Reason: 'Min Full Com Timer is disabled' and Deactivateable: 'ComM_MinFullComModeTimer' Reason: 'Min Full Com Timer is disabled' */
#define COMM_NMLIGHTTIMER                                                                           STD_OFF  /**< Deactivateable: 'ComM_NmLightTimer' Reason: 'Nm Light and Nm Light Silent Timers are disabled' and Deactivateable: 'ComM_NmLightTimer' Reason: 'Nm Light and Nm Light Silent Timers are disabled' */
#define COMM_NMSTARTUPINDICATED                                                                     STD_ON
#define COMM_NOTIFYPNCSTATECHANGE                                                                   STD_OFF  /**< Deactivateable: 'ComM_NotifyPncStateChange' Reason: 'No user mode Notification configured.' and Deactivateable: 'ComM_NotifyPncStateChange' Reason: 'No user mode Notification configured.' */
#define COMM_NVMSTOREREQ                                                                            STD_OFF  /**< Deactivateable: 'ComM_NvMStoreReq' Reason: 'NvM support is disabled' and Deactivateable: 'ComM_NvMStoreReq' Reason: 'NvM support is disabled' */
#define COMM_PARTITIONIDENTIFIERS                                                                   STD_ON
#define COMM_PCPARTITIONCONFIGIDXOFPARTITIONIDENTIFIERS                                             STD_ON
#define COMM_PARTITIONSNVOFPARTITIONIDENTIFIERS                                                     STD_ON
#define COMM_PNC                                                                                    STD_ON
#define COMM_CLEARMASKOFPNC                                                                         STD_ON
#define COMM_COORDINATEDOFPNC                                                                       STD_OFF  /**< Deactivateable: 'ComM_PncLeft.Coordinated' Reason: 'the value of ComM_CoordinatedOfPnc is always 'false' due to this, the array is deactivated.' and Deactivateable: 'ComM_PncRight.Coordinated' Reason: 'the value of ComM_CoordinatedOfPnc is always 'false' due to this, the array is deactivated.' */
#define COMM_INTERMEDIATEPNCCOORDINATOROFPNC                                                        STD_OFF  /**< Deactivateable: 'ComM_PncLeft.IntermediatePncCoordinator' Reason: 'the value of ComM_IntermediatePncCoordinatorOfPnc is always 'false' due to this, the array is deactivated.' and Deactivateable: 'ComM_PncRight.IntermediatePncCoordinator' Reason: 'the value of ComM_IntermediatePncCoordinatorOfPnc is always 'false' due to this, the array is deactivated.' */
#define COMM_PNCIDOFPNC                                                                             STD_ON
#define COMM_SETMASKOFPNC                                                                           STD_ON
#define COMM_SYSTEMUSEROFPNC                                                                        STD_OFF  /**< Deactivateable: 'ComM_PncLeft.SystemUser' Reason: 'the value of ComM_SystemUserOfPnc is always '65535' due to this, the array is deactivated.' and Deactivateable: 'ComM_PncRight.SystemUser' Reason: 'the value of ComM_SystemUserOfPnc is always '65535' due to this, the array is deactivated.' */
#define COMM_TOPLEVELPNCCOORDINATOROFPNC                                                            STD_OFF  /**< Deactivateable: 'ComM_PncLeft.TopLevelPncCoordinator' Reason: 'the value of ComM_TopLevelPncCoordinatorOfPnc is always 'false' due to this, the array is deactivated.' and Deactivateable: 'ComM_PncRight.TopLevelPncCoordinator' Reason: 'the value of ComM_TopLevelPncCoordinatorOfPnc is always 'false' due to this, the array is deactivated.' */
#define COMM_WAKEUPENABLEDOFPNC                                                                     STD_OFF  /**< Deactivateable: 'ComM_PncLeft.WakeupEnabled' Reason: 'the value of ComM_WakeupEnabledOfPnc is always 'false' due to this, the array is deactivated.' and Deactivateable: 'ComM_PncRight.WakeupEnabled' Reason: 'the value of ComM_WakeupEnabledOfPnc is always 'false' due to this, the array is deactivated.' */
#define COMM_PNCCHANNELMAPPING                                                                      STD_ON
#define COMM_PNCPSLEEPTIMER                                                                         STD_ON
#define COMM_PNCPB                                                                                  STD_ON
#define COMM_PNCCHANNELMAPPINGENDIDXOFPNCPB                                                         STD_ON
#define COMM_PNCCHANNELMAPPINGSTARTIDXOFPNCPB                                                       STD_ON
#define COMM_PNCCHANNELMAPPINGUSEDOFPNCPB                                                           STD_ON
#define COMM_PNCSIGNALINDENDIDXOFPNCPB                                                              STD_ON
#define COMM_PNCSIGNALINDSTARTIDXOFPNCPB                                                            STD_ON
#define COMM_PNCSIGNALINDUSEDOFPNCPB                                                                STD_ON
#define COMM_SIGNALBYTEINDEXOFPNCPB                                                                 STD_ON
#define COMM_USERREQPNCFULLCOMENDIDXOFPNCPB                                                         STD_ON
#define COMM_USERREQPNCFULLCOMSTARTIDXOFPNCPB                                                       STD_ON
#define COMM_PNCPBIND                                                                               STD_ON
#define COMM_PNCSIGNAL                                                                              STD_ON
#define COMM_BUSTYPEIDOFPNCSIGNAL                                                                   STD_ON
#define COMM_CHANNELIDXOFPNCSIGNAL                                                                  STD_ON
#define COMM_CHANNELUSEDOFPNCSIGNAL                                                                 STD_ON
#define COMM_PNCSIGNALVALUESENDIDXOFPNCSIGNAL                                                       STD_ON
#define COMM_PNCSIGNALVALUESSTARTIDXOFPNCSIGNAL                                                     STD_ON
#define COMM_PNCSIGNALVALUESUSEDOFPNCSIGNAL                                                         STD_ON
#define COMM_TYPEOFPNCSIGNAL                                                                        STD_ON
#define COMM_PNCSIGNALIND                                                                           STD_ON
#define COMM_PNCSIGNALVALUES                                                                        STD_ON
#define COMM_PNCTOCHANNELROUTINGSTATE                                                               STD_ON
#define COMM_POSTINITIALIZED                                                                        STD_ON
#define COMM_RESETREQUIRED                                                                          STD_ON
#define COMM_SIMULATEDSMMODE                                                                        STD_OFF  /**< Deactivateable: 'ComM_SimulatedSmMode' Reason: 'No channel of type 'internal' is present' and Deactivateable: 'ComM_SimulatedSmMode' Reason: 'No channel of type 'internal' is present' */
#define COMM_SIZEOFACTIVECOMMODE                                                                    STD_ON
#define COMM_SIZEOFACTIVEPNCCOMMODE                                                                 STD_ON
#define COMM_SIZEOFBUSCOMMODEREQ                                                                    STD_ON
#define COMM_SIZEOFBUSCOMMODEREQFRSHUTDOWN                                                          STD_OFF  /**< Deactivateable: 'ComM_SizeOfBusComModeReqFrShutdown' Reason: 'Deactivateable: 'BusComModeReqFrShutdown' Reason: 'Deactivateable: 'ComM_BusComModeReqFrShutdown' Reason: 'Fr support is not present' and Deactivateable: 'ComM_BusComModeReqFrShutdown' Reason: 'Fr support is not present''' and Deactivateable: 'ComM_SizeOfBusComModeReqFrShutdown' Reason: 'Deactivateable: 'BusComModeReqFrShutdown' Reason: 'Deactivateable: 'ComM_BusComModeReqFrShutdown' Reason: 'Fr support is not present' and Deactivateable: 'ComM_BusComModeReqFrShutdown' Reason: 'Fr support is not present''' */
#define COMM_SIZEOFBUSPNCCOMMODEREQ                                                                 STD_ON
#define COMM_SIZEOFBUSSLEEPMODEINDICATED                                                            STD_OFF  /**< Deactivateable: 'ComM_SizeOfBusSleepModeIndicated' Reason: 'Deactivateable: 'BusSleepModeIndicated' Reason: 'Deactivateable: 'ComM_BusSleepModeIndicated' Reason: 'NM variant LINSLAVE is not present' and Deactivateable: 'ComM_BusSleepModeIndicated' Reason: 'NM variant LINSLAVE is not present''' and Deactivateable: 'ComM_SizeOfBusSleepModeIndicated' Reason: 'Deactivateable: 'BusSleepModeIndicated' Reason: 'Deactivateable: 'ComM_BusSleepModeIndicated' Reason: 'NM variant LINSLAVE is not present' and Deactivateable: 'ComM_BusSleepModeIndicated' Reason: 'NM variant LINSLAVE is not present''' */
#define COMM_SIZEOFBUSSMSTATE                                                                       STD_ON
#define COMM_SIZEOFCHANNEL                                                                          STD_ON
#define COMM_SIZEOFCHANNELPB                                                                        STD_ON
#define COMM_SIZEOFCOMALLOWED                                                                       STD_ON
#define COMM_SIZEOFDCMREQUESTACTIVE                                                                 STD_ON
#define COMM_SIZEOFECUMWAKEUPINDICATED                                                              STD_ON
#define COMM_SIZEOFEIRATXSIGNALINDIRECTION                                                          STD_ON
#define COMM_SIZEOFFORWARDSYNCHRONIZEDPNCSHUTDOWNINDICATED                                          STD_OFF  /**< Deactivateable: 'ComM_SizeOfForwardSynchronizedPncShutdownIndicated' Reason: 'Deactivateable: 'ForwardSynchronizedPncShutdownIndicated' Reason: 'Deactivateable: 'ComM_ForwardSynchronizedPncShutdownIndicated' Reason: 'Synchronized PNC Shutdown is disabled or no Intermediate PNC Coordinator exists.' and Deactivateable: 'ComM_ForwardSynchronizedPncShutdownIndicated' Reason: 'Synchronized PNC Shutdown is disabled or no Intermediate PNC Coordinator exists.''' and Deactivateable: 'ComM_SizeOfForwardSynchronizedPncShutdownIndicated' Reason: 'Deactivateable: 'ForwardSynchronizedPncShutdownIndicated' Reason: 'Deactivateable: 'ComM_ForwardSynchronizedPncShutdownIndicated' Reason: 'Synchronized PNC Shutdown is disabled or no Intermediate PNC Coordinator exists.' and Deactivateable: 'ComM_ForwardSynchronizedPncShutdownIndicated' Reason: 'Synchronized PNC Shutdown is disabled or no Intermediate PNC Coordinator exists.''' */
#define COMM_SIZEOFFRSHUTDOWN                                                                       STD_OFF  /**< Deactivateable: 'ComM_SizeOfFrShutdown' Reason: 'Deactivateable: 'FrShutdown' Reason: 'Deactivateable: 'ComM_FrShutdown' Reason: 'Fr support is not present' and Deactivateable: 'ComM_FrShutdown' Reason: 'Fr support is not present''' and Deactivateable: 'ComM_SizeOfFrShutdown' Reason: 'Deactivateable: 'FrShutdown' Reason: 'Deactivateable: 'ComM_FrShutdown' Reason: 'Fr support is not present' and Deactivateable: 'ComM_FrShutdown' Reason: 'Fr support is not present''' */
#define COMM_SIZEOFFULLCOMREQUESTERS                                                                STD_OFF  /**< Deactivateable: 'ComM_SizeOfFullComRequesters' Reason: 'Deactivateable: 'FullComRequesters' Reason: 'Deactivateable: 'ComM_FullComRequesters' Reason: 'Deactivated because no channel had ComMFullCommRequestNoficiation enabled' and Deactivateable: 'ComM_FullComRequesters' Reason: 'Deactivated because no channel had ComMFullCommRequestNoficiation enabled''' and Deactivateable: 'ComM_SizeOfFullComRequesters' Reason: 'Deactivateable: 'FullComRequesters' Reason: 'Deactivateable: 'ComM_FullComRequesters' Reason: 'Deactivated because no channel had ComMFullCommRequestNoficiation enabled' and Deactivateable: 'ComM_FullComRequesters' Reason: 'Deactivated because no channel had ComMFullCommRequestNoficiation enabled''' */
#define COMM_SIZEOFLASTSTATECHANGE                                                                  STD_OFF  /**< Deactivateable: 'ComM_SizeOfLastStateChange' Reason: 'Deactivateable: 'LastStateChange' Reason: 'Deactivateable: 'ComM_LastStateChange' Reason: 'No user mode Notification configured.' and Deactivateable: 'ComM_LastStateChange' Reason: 'No user mode Notification configured.''' and Deactivateable: 'ComM_SizeOfLastStateChange' Reason: 'Deactivateable: 'LastStateChange' Reason: 'Deactivateable: 'ComM_LastStateChange' Reason: 'No user mode Notification configured.' and Deactivateable: 'ComM_LastStateChange' Reason: 'No user mode Notification configured.''' */
#define COMM_SIZEOFMINFULLCOMMODETIMER                                                              STD_OFF  /**< Deactivateable: 'ComM_SizeOfMinFullComModeTimer' Reason: 'Deactivateable: 'MinFullComModeTimer' Reason: 'Deactivateable: 'ComM_MinFullComModeTimer' Reason: 'Min Full Com Timer is disabled' and Deactivateable: 'ComM_MinFullComModeTimer' Reason: 'Min Full Com Timer is disabled''' and Deactivateable: 'ComM_SizeOfMinFullComModeTimer' Reason: 'Deactivateable: 'MinFullComModeTimer' Reason: 'Deactivateable: 'ComM_MinFullComModeTimer' Reason: 'Min Full Com Timer is disabled' and Deactivateable: 'ComM_MinFullComModeTimer' Reason: 'Min Full Com Timer is disabled''' */
#define COMM_SIZEOFNMLIGHTTIMER                                                                     STD_OFF  /**< Deactivateable: 'ComM_SizeOfNmLightTimer' Reason: 'Deactivateable: 'NmLightTimer' Reason: 'Deactivateable: 'ComM_NmLightTimer' Reason: 'Nm Light and Nm Light Silent Timers are disabled' and Deactivateable: 'ComM_NmLightTimer' Reason: 'Nm Light and Nm Light Silent Timers are disabled''' and Deactivateable: 'ComM_SizeOfNmLightTimer' Reason: 'Deactivateable: 'NmLightTimer' Reason: 'Deactivateable: 'ComM_NmLightTimer' Reason: 'Nm Light and Nm Light Silent Timers are disabled' and Deactivateable: 'ComM_NmLightTimer' Reason: 'Nm Light and Nm Light Silent Timers are disabled''' */
#define COMM_SIZEOFNMSTARTUPINDICATED                                                               STD_ON
#define COMM_SIZEOFPARTITIONIDENTIFIERS                                                             STD_ON
#define COMM_SIZEOFPNC                                                                              STD_ON
#define COMM_SIZEOFPNCCHANNELMAPPING                                                                STD_ON
#define COMM_SIZEOFPNCPSLEEPTIMER                                                                   STD_ON
#define COMM_SIZEOFPNCPB                                                                            STD_ON
#define COMM_SIZEOFPNCPBIND                                                                         STD_ON
#define COMM_SIZEOFPNCSIGNAL                                                                        STD_ON
#define COMM_SIZEOFPNCSIGNALIND                                                                     STD_ON
#define COMM_SIZEOFPNCSIGNALVALUES                                                                  STD_ON
#define COMM_SIZEOFPNCTOCHANNELROUTINGSTATE                                                         STD_ON
#define COMM_SIZEOFPOSTINITIALIZED                                                                  STD_ON
#define COMM_SIZEOFRESETREQUIRED                                                                    STD_ON
#define COMM_SIZEOFSIMULATEDSMMODE                                                                  STD_OFF  /**< Deactivateable: 'ComM_SizeOfSimulatedSmMode' Reason: 'Deactivateable: 'SimulatedSmMode' Reason: 'Deactivateable: 'ComM_SimulatedSmMode' Reason: 'No channel of type 'internal' is present' and Deactivateable: 'ComM_SimulatedSmMode' Reason: 'No channel of type 'internal' is present''' and Deactivateable: 'ComM_SizeOfSimulatedSmMode' Reason: 'Deactivateable: 'SimulatedSmMode' Reason: 'Deactivateable: 'ComM_SimulatedSmMode' Reason: 'No channel of type 'internal' is present' and Deactivateable: 'ComM_SimulatedSmMode' Reason: 'No channel of type 'internal' is present''' */
#define COMM_SIZEOFSTATECHANGE                                                                      STD_OFF  /**< Deactivateable: 'ComM_SizeOfStateChange' Reason: 'Deactivateable: 'StateChange' Reason: 'Deactivateable: 'ComM_StateChange' Reason: 'No user mode Notification configured.' and Deactivateable: 'ComM_StateChange' Reason: 'No user mode Notification configured.''' and Deactivateable: 'ComM_SizeOfStateChange' Reason: 'Deactivateable: 'StateChange' Reason: 'Deactivateable: 'ComM_StateChange' Reason: 'No user mode Notification configured.' and Deactivateable: 'ComM_StateChange' Reason: 'No user mode Notification configured.''' */
#define COMM_SIZEOFUSER                                                                             STD_ON
#define COMM_SIZEOFUSERBYTEMASK                                                                     STD_ON
#define COMM_SIZEOFUSERMODENOTIFUNC                                                                 STD_OFF  /**< Deactivateable: 'ComM_SizeOfUserModeNotiFunc' Reason: 'Deactivateable: 'UserModeNotiFunc' Reason: 'Deactivateable: 'ComM_UserModeNotiFunc' Reason: 'No user mode Notification configured.' and Deactivateable: 'ComM_UserModeNotiFunc' Reason: 'No user mode Notification configured.''' and Deactivateable: 'ComM_SizeOfUserModeNotiFunc' Reason: 'Deactivateable: 'UserModeNotiFunc' Reason: 'Deactivateable: 'ComM_UserModeNotiFunc' Reason: 'No user mode Notification configured.' and Deactivateable: 'ComM_UserModeNotiFunc' Reason: 'No user mode Notification configured.''' */
#define COMM_SIZEOFUSERPNCBYTEMASK                                                                  STD_ON
#define COMM_SIZEOFUSERREQFULLCOM                                                                   STD_ON
#define COMM_SIZEOFUSERREQPNCFULLCOM                                                                STD_ON
#define COMM_STATECHANGE                                                                            STD_OFF  /**< Deactivateable: 'ComM_StateChange' Reason: 'No user mode Notification configured.' and Deactivateable: 'ComM_StateChange' Reason: 'No user mode Notification configured.' */
#define COMM_USER                                                                                   STD_ON
#define COMM_PARTITIONCONFIGIDXOFUSER                                                               STD_ON
#define COMM_PNCUSEROFUSER                                                                          STD_ON
#define COMM_USERBYTEMASKENDIDXOFUSER                                                               STD_ON
#define COMM_USERBYTEMASKSTARTIDXOFUSER                                                             STD_ON
#define COMM_USERBYTEMASKUSEDOFUSER                                                                 STD_ON
#define COMM_USERPNCBYTEMASKENDIDXOFUSER                                                            STD_ON
#define COMM_USERPNCBYTEMASKLENGTHOFUSER                                                            STD_ON
#define COMM_USERPNCBYTEMASKSTARTIDXOFUSER                                                          STD_ON
#define COMM_USERPNCBYTEMASKUSEDOFUSER                                                              STD_ON
#define COMM_USERBYTEMASK                                                                           STD_ON
#define COMM_CHANNELOFUSERBYTEMASK                                                                  STD_ON
#define COMM_CLEARMASKOFUSERBYTEMASK                                                                STD_ON
#define COMM_SETMASKOFUSERBYTEMASK                                                                  STD_ON
#define COMM_USERREQFULLCOMIDXOFUSERBYTEMASK                                                        STD_ON
#define COMM_USERMODENOTIFUNC                                                                       STD_OFF  /**< Deactivateable: 'ComM_UserModeNotiFunc' Reason: 'No user mode Notification configured.' and Deactivateable: 'ComM_UserModeNotiFunc' Reason: 'No user mode Notification configured.' */
#define COMM_USERPNCBYTEMASK                                                                        STD_ON
#define COMM_CLEARMASKOFUSERPNCBYTEMASK                                                             STD_ON
#define COMM_PNCIDOFUSERPNCBYTEMASK                                                                 STD_ON
#define COMM_PNCIDXOFUSERPNCBYTEMASK                                                                STD_ON
#define COMM_SETMASKOFUSERPNCBYTEMASK                                                               STD_ON
#define COMM_USERREQPNCFULLCOMIDXOFUSERPNCBYTEMASK                                                  STD_ON
#define COMM_USERREQFULLCOM                                                                         STD_ON
#define COMM_USERREQPNCFULLCOM                                                                      STD_ON
#define COMM_PCCONFIG                                                                               STD_ON
#define COMM_FINALMAGICNUMBEROFPCCONFIG                                                             STD_OFF  /**< Deactivateable: 'ComM_PCConfig.FinalMagicNumber' Reason: 'the module configuration does not support flashing of data.' */
#define COMM_INITDATAHASHCODEOFPCCONFIG                                                             STD_OFF  /**< Deactivateable: 'ComM_PCConfig.InitDataHashCode' Reason: 'the module configuration does not support flashing of data.' */
#define COMM_PCPARTITIONCONFIGOFPCCONFIG                                                            STD_ON
#define COMM_PARTITIONIDENTIFIERSOFPCCONFIG                                                         STD_ON
#define COMM_SIZEOFPARTITIONIDENTIFIERSOFPCCONFIG                                                   STD_ON
#define COMM_PCPARTITIONCONFIG                                                                      STD_ON
#define COMM_ACTIVECOMMODEOFPCPARTITIONCONFIG                                                       STD_ON
#define COMM_ACTIVEPNCCOMMODEOFPCPARTITIONCONFIG                                                    STD_ON
#define COMM_BUSCOMMODEREQOFPCPARTITIONCONFIG                                                       STD_ON
#define COMM_BUSPNCCOMMODEREQOFPCPARTITIONCONFIG                                                    STD_ON
#define COMM_BUSSMSTATEOFPCPARTITIONCONFIG                                                          STD_ON
#define COMM_CHANNELOFPCPARTITIONCONFIG                                                             STD_ON
#define COMM_CHANNELPBOFPCPARTITIONCONFIG                                                           STD_ON
#define COMM_COMALLOWEDOFPCPARTITIONCONFIG                                                          STD_ON
#define COMM_DCMREQUESTACTIVEOFPCPARTITIONCONFIG                                                    STD_ON
#define COMM_ECUMWAKEUPINDICATEDOFPCPARTITIONCONFIG                                                 STD_ON
#define COMM_EIRATXSIGNALINDIRECTIONOFPCPARTITIONCONFIG                                             STD_ON
#define COMM_INHIBITIONOFPCPARTITIONCONFIG                                                          STD_ON
#define COMM_INITSTATUSOFPCPARTITIONCONFIG                                                          STD_ON
#define COMM_NMSTARTUPINDICATEDOFPCPARTITIONCONFIG                                                  STD_ON
#define COMM_PNCCHANNELMAPPINGOFPCPARTITIONCONFIG                                                   STD_ON
#define COMM_PNCOFPCPARTITIONCONFIG                                                                 STD_ON
#define COMM_PNCPSLEEPTIMEROFPCPARTITIONCONFIG                                                      STD_ON
#define COMM_PNCPBINDOFPCPARTITIONCONFIG                                                            STD_ON
#define COMM_PNCPBOFPCPARTITIONCONFIG                                                               STD_ON
#define COMM_PNCSIGNALINDOFPCPARTITIONCONFIG                                                        STD_ON
#define COMM_PNCSIGNALOFPCPARTITIONCONFIG                                                           STD_ON
#define COMM_PNCSIGNALVALUESOFPCPARTITIONCONFIG                                                     STD_ON
#define COMM_PNCTOCHANNELROUTINGSTATEOFPCPARTITIONCONFIG                                            STD_ON
#define COMM_POSTINITIALIZEDOFPCPARTITIONCONFIG                                                     STD_ON
#define COMM_RESETREQUIREDOFPCPARTITIONCONFIG                                                       STD_ON
#define COMM_SIZEOFACTIVECOMMODEOFPCPARTITIONCONFIG                                                 STD_ON
#define COMM_SIZEOFACTIVEPNCCOMMODEOFPCPARTITIONCONFIG                                              STD_ON
#define COMM_SIZEOFBUSCOMMODEREQFRSHUTDOWNOFPCPARTITIONCONFIG                                       STD_OFF  /**< Deactivateable: 'ComM_PCPartitionConfigLeft.SizeOfBusComModeReqFrShutdown' Reason: 'Deactivateable: 'BusComModeReqFrShutdown' Reason: 'Deactivateable: 'ComM_BusComModeReqFrShutdown' Reason: 'Fr support is not present' and Deactivateable: 'ComM_BusComModeReqFrShutdown' Reason: 'Fr support is not present''' and Deactivateable: 'ComM_PCPartitionConfigRight.SizeOfBusComModeReqFrShutdown' Reason: 'Deactivateable: 'BusComModeReqFrShutdown' Reason: 'Deactivateable: 'ComM_BusComModeReqFrShutdown' Reason: 'Fr support is not present' and Deactivateable: 'ComM_BusComModeReqFrShutdown' Reason: 'Fr support is not present''' */
#define COMM_SIZEOFBUSCOMMODEREQOFPCPARTITIONCONFIG                                                 STD_ON
#define COMM_SIZEOFBUSPNCCOMMODEREQOFPCPARTITIONCONFIG                                              STD_ON
#define COMM_SIZEOFBUSSLEEPMODEINDICATEDOFPCPARTITIONCONFIG                                         STD_OFF  /**< Deactivateable: 'ComM_PCPartitionConfigLeft.SizeOfBusSleepModeIndicated' Reason: 'Deactivateable: 'BusSleepModeIndicated' Reason: 'Deactivateable: 'ComM_BusSleepModeIndicated' Reason: 'NM variant LINSLAVE is not present' and Deactivateable: 'ComM_BusSleepModeIndicated' Reason: 'NM variant LINSLAVE is not present''' and Deactivateable: 'ComM_PCPartitionConfigRight.SizeOfBusSleepModeIndicated' Reason: 'Deactivateable: 'BusSleepModeIndicated' Reason: 'Deactivateable: 'ComM_BusSleepModeIndicated' Reason: 'NM variant LINSLAVE is not present' and Deactivateable: 'ComM_BusSleepModeIndicated' Reason: 'NM variant LINSLAVE is not present''' */
#define COMM_SIZEOFBUSSMSTATEOFPCPARTITIONCONFIG                                                    STD_ON
#define COMM_SIZEOFCHANNELOFPCPARTITIONCONFIG                                                       STD_ON
#define COMM_SIZEOFCHANNELPBOFPCPARTITIONCONFIG                                                     STD_ON
#define COMM_SIZEOFCOMALLOWEDOFPCPARTITIONCONFIG                                                    STD_ON
#define COMM_SIZEOFDCMREQUESTACTIVEOFPCPARTITIONCONFIG                                              STD_ON
#define COMM_SIZEOFECUMWAKEUPINDICATEDOFPCPARTITIONCONFIG                                           STD_ON
#define COMM_SIZEOFEIRATXSIGNALINDIRECTIONOFPCPARTITIONCONFIG                                       STD_ON
#define COMM_SIZEOFFORWARDSYNCHRONIZEDPNCSHUTDOWNINDICATEDOFPCPARTITIONCONFIG                       STD_OFF  /**< Deactivateable: 'ComM_PCPartitionConfigLeft.SizeOfForwardSynchronizedPncShutdownIndicated' Reason: 'Deactivateable: 'ForwardSynchronizedPncShutdownIndicated' Reason: 'Deactivateable: 'ComM_ForwardSynchronizedPncShutdownIndicated' Reason: 'Synchronized PNC Shutdown is disabled or no Intermediate PNC Coordinator exists.' and Deactivateable: 'ComM_ForwardSynchronizedPncShutdownIndicated' Reason: 'Synchronized PNC Shutdown is disabled or no Intermediate PNC Coordinator exists.''' and Deactivateable: 'ComM_PCPartitionConfigRight.SizeOfForwardSynchronizedPncShutdownIndicated' Reason: 'Deactivateable: 'ForwardSynchronizedPncShutdownIndicated' Reason: 'Deactivateable: 'ComM_ForwardSynchronizedPncShutdownIndicated' Reason: 'Synchronized PNC Shutdown is disabled or no Intermediate PNC Coordinator exists.' and Deactivateable: 'ComM_ForwardSynchronizedPncShutdownIndicated' Reason: 'Synchronized PNC Shutdown is disabled or no Intermediate PNC Coordinator exists.''' */
#define COMM_SIZEOFFRSHUTDOWNOFPCPARTITIONCONFIG                                                    STD_OFF  /**< Deactivateable: 'ComM_PCPartitionConfigLeft.SizeOfFrShutdown' Reason: 'Deactivateable: 'FrShutdown' Reason: 'Deactivateable: 'ComM_FrShutdown' Reason: 'Fr support is not present' and Deactivateable: 'ComM_FrShutdown' Reason: 'Fr support is not present''' and Deactivateable: 'ComM_PCPartitionConfigRight.SizeOfFrShutdown' Reason: 'Deactivateable: 'FrShutdown' Reason: 'Deactivateable: 'ComM_FrShutdown' Reason: 'Fr support is not present' and Deactivateable: 'ComM_FrShutdown' Reason: 'Fr support is not present''' */
#define COMM_SIZEOFFULLCOMREQUESTERSOFPCPARTITIONCONFIG                                             STD_OFF  /**< Deactivateable: 'ComM_PCPartitionConfigLeft.SizeOfFullComRequesters' Reason: 'Deactivateable: 'FullComRequesters' Reason: 'Deactivateable: 'ComM_FullComRequesters' Reason: 'Deactivated because no channel had ComMFullCommRequestNoficiation enabled' and Deactivateable: 'ComM_FullComRequesters' Reason: 'Deactivated because no channel had ComMFullCommRequestNoficiation enabled''' and Deactivateable: 'ComM_PCPartitionConfigRight.SizeOfFullComRequesters' Reason: 'Deactivateable: 'FullComRequesters' Reason: 'Deactivateable: 'ComM_FullComRequesters' Reason: 'Deactivated because no channel had ComMFullCommRequestNoficiation enabled' and Deactivateable: 'ComM_FullComRequesters' Reason: 'Deactivated because no channel had ComMFullCommRequestNoficiation enabled''' */
#define COMM_SIZEOFLASTSTATECHANGEOFPCPARTITIONCONFIG                                               STD_OFF  /**< Deactivateable: 'ComM_PCPartitionConfigLeft.SizeOfLastStateChange' Reason: 'Deactivateable: 'LastStateChange' Reason: 'Deactivateable: 'ComM_LastStateChange' Reason: 'No user mode Notification configured.' and Deactivateable: 'ComM_LastStateChange' Reason: 'No user mode Notification configured.''' and Deactivateable: 'ComM_PCPartitionConfigRight.SizeOfLastStateChange' Reason: 'Deactivateable: 'LastStateChange' Reason: 'Deactivateable: 'ComM_LastStateChange' Reason: 'No user mode Notification configured.' and Deactivateable: 'ComM_LastStateChange' Reason: 'No user mode Notification configured.''' */
#define COMM_SIZEOFMINFULLCOMMODETIMEROFPCPARTITIONCONFIG                                           STD_OFF  /**< Deactivateable: 'ComM_PCPartitionConfigLeft.SizeOfMinFullComModeTimer' Reason: 'Deactivateable: 'MinFullComModeTimer' Reason: 'Deactivateable: 'ComM_MinFullComModeTimer' Reason: 'Min Full Com Timer is disabled' and Deactivateable: 'ComM_MinFullComModeTimer' Reason: 'Min Full Com Timer is disabled''' and Deactivateable: 'ComM_PCPartitionConfigRight.SizeOfMinFullComModeTimer' Reason: 'Deactivateable: 'MinFullComModeTimer' Reason: 'Deactivateable: 'ComM_MinFullComModeTimer' Reason: 'Min Full Com Timer is disabled' and Deactivateable: 'ComM_MinFullComModeTimer' Reason: 'Min Full Com Timer is disabled''' */
#define COMM_SIZEOFNMLIGHTTIMEROFPCPARTITIONCONFIG                                                  STD_OFF  /**< Deactivateable: 'ComM_PCPartitionConfigLeft.SizeOfNmLightTimer' Reason: 'Deactivateable: 'NmLightTimer' Reason: 'Deactivateable: 'ComM_NmLightTimer' Reason: 'Nm Light and Nm Light Silent Timers are disabled' and Deactivateable: 'ComM_NmLightTimer' Reason: 'Nm Light and Nm Light Silent Timers are disabled''' and Deactivateable: 'ComM_PCPartitionConfigRight.SizeOfNmLightTimer' Reason: 'Deactivateable: 'NmLightTimer' Reason: 'Deactivateable: 'ComM_NmLightTimer' Reason: 'Nm Light and Nm Light Silent Timers are disabled' and Deactivateable: 'ComM_NmLightTimer' Reason: 'Nm Light and Nm Light Silent Timers are disabled''' */
#define COMM_SIZEOFNMSTARTUPINDICATEDOFPCPARTITIONCONFIG                                            STD_ON
#define COMM_SIZEOFPNCCHANNELMAPPINGOFPCPARTITIONCONFIG                                             STD_ON
#define COMM_SIZEOFPNCOFPCPARTITIONCONFIG                                                           STD_ON
#define COMM_SIZEOFPNCPSLEEPTIMEROFPCPARTITIONCONFIG                                                STD_ON
#define COMM_SIZEOFPNCPBINDOFPCPARTITIONCONFIG                                                      STD_ON
#define COMM_SIZEOFPNCPBOFPCPARTITIONCONFIG                                                         STD_ON
#define COMM_SIZEOFPNCSIGNALINDOFPCPARTITIONCONFIG                                                  STD_ON
#define COMM_SIZEOFPNCSIGNALOFPCPARTITIONCONFIG                                                     STD_ON
#define COMM_SIZEOFPNCSIGNALVALUESOFPCPARTITIONCONFIG                                               STD_ON
#define COMM_SIZEOFPNCTOCHANNELROUTINGSTATEOFPCPARTITIONCONFIG                                      STD_ON
#define COMM_SIZEOFPOSTINITIALIZEDOFPCPARTITIONCONFIG                                               STD_ON
#define COMM_SIZEOFRESETREQUIREDOFPCPARTITIONCONFIG                                                 STD_ON
#define COMM_SIZEOFSIMULATEDSMMODEOFPCPARTITIONCONFIG                                               STD_OFF  /**< Deactivateable: 'ComM_PCPartitionConfigLeft.SizeOfSimulatedSmMode' Reason: 'Deactivateable: 'SimulatedSmMode' Reason: 'Deactivateable: 'ComM_SimulatedSmMode' Reason: 'No channel of type 'internal' is present' and Deactivateable: 'ComM_SimulatedSmMode' Reason: 'No channel of type 'internal' is present''' and Deactivateable: 'ComM_PCPartitionConfigRight.SizeOfSimulatedSmMode' Reason: 'Deactivateable: 'SimulatedSmMode' Reason: 'Deactivateable: 'ComM_SimulatedSmMode' Reason: 'No channel of type 'internal' is present' and Deactivateable: 'ComM_SimulatedSmMode' Reason: 'No channel of type 'internal' is present''' */
#define COMM_SIZEOFSTATECHANGEOFPCPARTITIONCONFIG                                                   STD_OFF  /**< Deactivateable: 'ComM_PCPartitionConfigLeft.SizeOfStateChange' Reason: 'Deactivateable: 'StateChange' Reason: 'Deactivateable: 'ComM_StateChange' Reason: 'No user mode Notification configured.' and Deactivateable: 'ComM_StateChange' Reason: 'No user mode Notification configured.''' and Deactivateable: 'ComM_PCPartitionConfigRight.SizeOfStateChange' Reason: 'Deactivateable: 'StateChange' Reason: 'Deactivateable: 'ComM_StateChange' Reason: 'No user mode Notification configured.' and Deactivateable: 'ComM_StateChange' Reason: 'No user mode Notification configured.''' */
#define COMM_SIZEOFUSERBYTEMASKOFPCPARTITIONCONFIG                                                  STD_ON
#define COMM_SIZEOFUSERMODENOTIFUNCOFPCPARTITIONCONFIG                                              STD_OFF  /**< Deactivateable: 'ComM_PCPartitionConfigLeft.SizeOfUserModeNotiFunc' Reason: 'Deactivateable: 'UserModeNotiFunc' Reason: 'Deactivateable: 'ComM_UserModeNotiFunc' Reason: 'No user mode Notification configured.' and Deactivateable: 'ComM_UserModeNotiFunc' Reason: 'No user mode Notification configured.''' and Deactivateable: 'ComM_PCPartitionConfigRight.SizeOfUserModeNotiFunc' Reason: 'Deactivateable: 'UserModeNotiFunc' Reason: 'Deactivateable: 'ComM_UserModeNotiFunc' Reason: 'No user mode Notification configured.' and Deactivateable: 'ComM_UserModeNotiFunc' Reason: 'No user mode Notification configured.''' */
#define COMM_SIZEOFUSEROFPCPARTITIONCONFIG                                                          STD_ON
#define COMM_SIZEOFUSERPNCBYTEMASKOFPCPARTITIONCONFIG                                               STD_ON
#define COMM_SIZEOFUSERREQFULLCOMOFPCPARTITIONCONFIG                                                STD_ON
#define COMM_SIZEOFUSERREQPNCFULLCOMOFPCPARTITIONCONFIG                                             STD_ON
#define COMM_USERBYTEMASKOFPCPARTITIONCONFIG                                                        STD_ON
#define COMM_USEROFPCPARTITIONCONFIG                                                                STD_ON
#define COMM_USERPNCBYTEMASKOFPCPARTITIONCONFIG                                                     STD_ON
#define COMM_USERREQFULLCOMOFPCPARTITIONCONFIG                                                      STD_ON
#define COMM_USERREQPNCFULLCOMOFPCPARTITIONCONFIG                                                   STD_ON
/** 
  \}
*/ 

/** 
  \defgroup  ComMPCMinNumericValueDefines  ComM Min Numeric Value Defines (PRE_COMPILE)
  \brief  These defines are used to implement against the minimum value in numerical based data.
  \{
*/ 
#define COMM_MIN_PNCPSLEEPTIMER                                                                     0u
#define COMM_MIN_PNCSIGNALVALUES                                                                    0u
#define COMM_MIN_PNCTOCHANNELROUTINGSTATE                                                           0u
#define COMM_MIN_USERREQFULLCOM                                                                     0u
#define COMM_MIN_USERREQPNCFULLCOM                                                                  0u
/** 
  \}
*/ 

/** 
  \defgroup  ComMPCMaxNumericValueDefines  ComM Max Numeric Value Defines (PRE_COMPILE)
  \brief  These defines are used to implement against the maximum value in numerical based data.
  \{
*/ 
#define COMM_MAX_PNCPSLEEPTIMER                                                                     65535u
#define COMM_MAX_PNCSIGNALVALUES                                                                    255u
#define COMM_MAX_PNCTOCHANNELROUTINGSTATE                                                           255u
#define COMM_MAX_USERREQFULLCOM                                                                     255u
#define COMM_MAX_USERREQPNCFULLCOM                                                                  255u
/** 
  \}
*/ 

/** 
  \defgroup  ComMPCNoReferenceDefines  ComM No Reference Defines (PRE_COMPILE)
  \brief  These defines are used to indicate unused indexes in data relations.
  \{
*/ 
#define COMM_NO_PNCPBINDENDIDXOFCHANNELPB                                                           255u
#define COMM_NO_PNCPBINDSTARTIDXOFCHANNELPB                                                         255u
#define COMM_NO_USERREQFULLCOMENDIDXOFCHANNELPB                                                     255u
#define COMM_NO_USERREQFULLCOMSTARTIDXOFCHANNELPB                                                   255u
#define COMM_NO_PNCCHANNELMAPPINGENDIDXOFPNCPB                                                      255u
#define COMM_NO_PNCCHANNELMAPPINGSTARTIDXOFPNCPB                                                    255u
#define COMM_NO_PNCSIGNALINDENDIDXOFPNCPB                                                           255u
#define COMM_NO_PNCSIGNALINDSTARTIDXOFPNCPB                                                         255u
#define COMM_NO_CHANNELIDXOFPNCSIGNAL                                                               255u
#define COMM_NO_PNCSIGNALVALUESENDIDXOFPNCSIGNAL                                                    255u
#define COMM_NO_PNCSIGNALVALUESSTARTIDXOFPNCSIGNAL                                                  255u
#define COMM_NO_USERBYTEMASKENDIDXOFUSER                                                            255u
#define COMM_NO_USERBYTEMASKSTARTIDXOFUSER                                                          255u
#define COMM_NO_USERPNCBYTEMASKENDIDXOFUSER                                                         255u
#define COMM_NO_USERPNCBYTEMASKSTARTIDXOFUSER                                                       255u
/** 
  \}
*/ 

/** 
  \defgroup  ComMPCEnumExistsDefines  ComM Enum Exists Defines (PRE_COMPILE)
  \brief  These defines can be used to deactivate enumeration based code sequences if the enumeration value does not exist in the configuration data.
  \{
*/ 
#define COMM_EXISTS_NOT_USED_IN_THIS_VARIANT_NMTYPEOFCHANNEL                                        STD_ON
#define COMM_EXISTS_FULL_NMTYPEOFCHANNEL                                                            STD_ON
#define COMM_EXISTS_PASSIVE_NMTYPEOFCHANNEL                                                         STD_OFF
#define COMM_EXISTS_LIGHT_NMTYPEOFCHANNEL                                                           STD_OFF
#define COMM_EXISTS_NONE_NMTYPEOFCHANNEL                                                            STD_OFF
#define COMM_EXISTS_LINSLAVE_NMTYPEOFCHANNEL                                                        STD_OFF
#define COMM_EXISTS_EIRA_RX_TYPEOFPNCSIGNAL                                                         STD_ON
#define COMM_EXISTS_EIRA_TX_TYPEOFPNCSIGNAL                                                         STD_ON
#define COMM_EXISTS_ERA_RX_TYPEOFPNCSIGNAL                                                          STD_OFF
#define COMM_EXISTS_NOT_USED_IN_THIS_VARIANT_TYPEOFPNCSIGNAL                                        STD_ON
/** 
  \}
*/ 

/** 
  \defgroup  ComMPCEnumDefines  ComM Enum Defines (PRE_COMPILE)
  \brief  These defines are the enumeration values of enumeration based CONST and VAR data.
  \{
*/ 
#define COMM_NOT_USED_IN_THIS_VARIANT_NMTYPEOFCHANNEL                                               0x00u
#define COMM_FULL_NMTYPEOFCHANNEL                                                                   0x01u
#define COMM_EIRA_RX_TYPEOFPNCSIGNAL                                                                0x00u
#define COMM_EIRA_TX_TYPEOFPNCSIGNAL                                                                0x01u
#define COMM_NOT_USED_IN_THIS_VARIANT_TYPEOFPNCSIGNAL                                               0x03u
/** 
  \}
*/ 

/** 
  \defgroup  ComMPCIsReducedToDefineDefines  ComM Is Reduced To Define Defines (PRE_COMPILE)
  \brief  If all values in a CONST array or an element in a CONST array of structs are equal, the define is STD_ON else STD_OFF.
  \{
*/ 
#define COMM_ISDEF_BUSTYPEOFCHANNEL                                                                 STD_ON
#define COMM_ISDEF_ENABLEDOFCHANNEL                                                                 STD_OFF
#define COMM_ISDEF_GETCURRENTBUSSMMODEAPIOFCHANNEL                                                  STD_OFF
#define COMM_ISDEF_GWTYPEOFCHANNEL                                                                  STD_ON
#define COMM_ISDEF_INHIBITIONINITVALUEOFCHANNEL                                                     STD_ON
#define COMM_ISDEF_NMSUPPORTOFCHANNEL                                                               STD_ON
#define COMM_ISDEF_NMTYPEOFCHANNEL                                                                  STD_OFF
#define COMM_ISDEF_PARTITIONCONFIGIDXOFCHANNEL                                                      STD_ON
#define COMM_ISDEF_PNCNMREQUESTOFCHANNEL                                                            STD_ON
#define COMM_ISDEF_REQUESTBUSSMMODEAPIOFCHANNEL                                                     STD_OFF
#define COMM_ISDEF_RESETAFTERFORCINGNOCOMMOFCHANNEL                                                 STD_ON
#define COMM_ISDEF_SILENTSUPPORTOFCHANNEL                                                           STD_ON
#define COMM_ISDEF_WAKEUPSTATEOFCHANNEL                                                             STD_ON
#define COMM_ISDEF_PNCPBINDENDIDXOFCHANNELPB                                                        STD_OFF
#define COMM_ISDEF_PNCPBINDSTARTIDXOFCHANNELPB                                                      STD_OFF
#define COMM_ISDEF_PNCPBINDUSEDOFCHANNELPB                                                          STD_OFF
#define COMM_ISDEF_USERREQFULLCOMENDIDXOFCHANNELPB                                                  STD_OFF
#define COMM_ISDEF_USERREQFULLCOMSTARTIDXOFCHANNELPB                                                STD_OFF
#define COMM_ISDEF_USERREQFULLCOMUSEDOFCHANNELPB                                                    STD_OFF
#define COMM_ISDEF_SYMBOLICNAMEVALUEOFEIRATXSIGNALINDIRECTION                                       STD_OFF
#define COMM_ISDEF_PCPARTITIONCONFIGIDXOFPARTITIONIDENTIFIERS                                       STD_OFF
#define COMM_ISDEF_PARTITIONSNVOFPARTITIONIDENTIFIERS                                               STD_OFF
#define COMM_ISDEF_CLEARMASKOFPNC                                                                   STD_OFF
#define COMM_ISDEF_PNCIDOFPNC                                                                       STD_OFF
#define COMM_ISDEF_SETMASKOFPNC                                                                     STD_OFF
#define COMM_ISDEF_PNCCHANNELMAPPING                                                                STD_OFF
#define COMM_ISDEF_PNCCHANNELMAPPINGENDIDXOFPNCPB                                                   STD_OFF
#define COMM_ISDEF_PNCCHANNELMAPPINGSTARTIDXOFPNCPB                                                 STD_OFF
#define COMM_ISDEF_PNCCHANNELMAPPINGUSEDOFPNCPB                                                     STD_ON
#define COMM_ISDEF_PNCSIGNALINDENDIDXOFPNCPB                                                        STD_OFF
#define COMM_ISDEF_PNCSIGNALINDSTARTIDXOFPNCPB                                                      STD_OFF
#define COMM_ISDEF_PNCSIGNALINDUSEDOFPNCPB                                                          STD_ON
#define COMM_ISDEF_SIGNALBYTEINDEXOFPNCPB                                                           STD_OFF
#define COMM_ISDEF_USERREQPNCFULLCOMENDIDXOFPNCPB                                                   STD_OFF
#define COMM_ISDEF_USERREQPNCFULLCOMSTARTIDXOFPNCPB                                                 STD_OFF
#define COMM_ISDEF_PNCPBIND                                                                         STD_OFF
#define COMM_ISDEF_BUSTYPEIDOFPNCSIGNAL                                                             STD_ON
#define COMM_ISDEF_CHANNELIDXOFPNCSIGNAL                                                            STD_OFF
#define COMM_ISDEF_CHANNELUSEDOFPNCSIGNAL                                                           STD_OFF
#define COMM_ISDEF_PNCSIGNALVALUESENDIDXOFPNCSIGNAL                                                 STD_OFF
#define COMM_ISDEF_PNCSIGNALVALUESSTARTIDXOFPNCSIGNAL                                               STD_OFF
#define COMM_ISDEF_PNCSIGNALVALUESUSEDOFPNCSIGNAL                                                   STD_OFF
#define COMM_ISDEF_TYPEOFPNCSIGNAL                                                                  STD_OFF
#define COMM_ISDEF_PNCSIGNALIND                                                                     STD_OFF
#define COMM_ISDEF_PARTITIONCONFIGIDXOFUSER                                                         STD_ON
#define COMM_ISDEF_PNCUSEROFUSER                                                                    STD_OFF
#define COMM_ISDEF_USERBYTEMASKENDIDXOFUSER                                                         STD_OFF
#define COMM_ISDEF_USERBYTEMASKSTARTIDXOFUSER                                                       STD_OFF
#define COMM_ISDEF_USERBYTEMASKUSEDOFUSER                                                           STD_ON
#define COMM_ISDEF_USERPNCBYTEMASKENDIDXOFUSER                                                      STD_OFF
#define COMM_ISDEF_USERPNCBYTEMASKLENGTHOFUSER                                                      STD_OFF
#define COMM_ISDEF_USERPNCBYTEMASKSTARTIDXOFUSER                                                    STD_OFF
#define COMM_ISDEF_USERPNCBYTEMASKUSEDOFUSER                                                        STD_OFF
#define COMM_ISDEF_CHANNELOFUSERBYTEMASK                                                            STD_OFF
#define COMM_ISDEF_CLEARMASKOFUSERBYTEMASK                                                          STD_OFF
#define COMM_ISDEF_SETMASKOFUSERBYTEMASK                                                            STD_OFF
#define COMM_ISDEF_USERREQFULLCOMIDXOFUSERBYTEMASK                                                  STD_ON
#define COMM_ISDEF_CLEARMASKOFUSERPNCBYTEMASK                                                       STD_ON
#define COMM_ISDEF_PNCIDOFUSERPNCBYTEMASK                                                           STD_OFF
#define COMM_ISDEF_PNCIDXOFUSERPNCBYTEMASK                                                          STD_OFF
#define COMM_ISDEF_SETMASKOFUSERPNCBYTEMASK                                                         STD_ON
#define COMM_ISDEF_USERREQPNCFULLCOMIDXOFUSERPNCBYTEMASK                                            STD_OFF
#define COMM_ISDEF_PCPARTITIONCONFIGOFPCCONFIG                                                      STD_OFF
#define COMM_ISDEF_PARTITIONIDENTIFIERSOFPCCONFIG                                                   STD_ON
#define COMM_ISDEF_ACTIVECOMMODEOFPCPARTITIONCONFIG                                                 STD_ON
#define COMM_ISDEF_ACTIVEPNCCOMMODEOFPCPARTITIONCONFIG                                              STD_ON
#define COMM_ISDEF_BUSCOMMODEREQOFPCPARTITIONCONFIG                                                 STD_ON
#define COMM_ISDEF_BUSPNCCOMMODEREQOFPCPARTITIONCONFIG                                              STD_ON
#define COMM_ISDEF_BUSSMSTATEOFPCPARTITIONCONFIG                                                    STD_ON
#define COMM_ISDEF_CHANNELOFPCPARTITIONCONFIG                                                       STD_OFF
#define COMM_ISDEF_CHANNELPBOFPCPARTITIONCONFIG                                                     STD_OFF
#define COMM_ISDEF_COMALLOWEDOFPCPARTITIONCONFIG                                                    STD_ON
#define COMM_ISDEF_DCMREQUESTACTIVEOFPCPARTITIONCONFIG                                              STD_ON
#define COMM_ISDEF_ECUMWAKEUPINDICATEDOFPCPARTITIONCONFIG                                           STD_ON
#define COMM_ISDEF_EIRATXSIGNALINDIRECTIONOFPCPARTITIONCONFIG                                       STD_ON
#define COMM_ISDEF_INHIBITIONOFPCPARTITIONCONFIG                                                    STD_ON
#define COMM_ISDEF_INITSTATUSOFPCPARTITIONCONFIG                                                    STD_ON
#define COMM_ISDEF_NMSTARTUPINDICATEDOFPCPARTITIONCONFIG                                            STD_ON
#define COMM_ISDEF_PNCCHANNELMAPPINGOFPCPARTITIONCONFIG                                             STD_OFF
#define COMM_ISDEF_PNCOFPCPARTITIONCONFIG                                                           STD_ON
#define COMM_ISDEF_PNCPSLEEPTIMEROFPCPARTITIONCONFIG                                                STD_ON
#define COMM_ISDEF_PNCPBINDOFPCPARTITIONCONFIG                                                      STD_ON
#define COMM_ISDEF_PNCPBOFPCPARTITIONCONFIG                                                         STD_ON
#define COMM_ISDEF_PNCSIGNALINDOFPCPARTITIONCONFIG                                                  STD_OFF
#define COMM_ISDEF_PNCSIGNALOFPCPARTITIONCONFIG                                                     STD_OFF
#define COMM_ISDEF_PNCSIGNALVALUESOFPCPARTITIONCONFIG                                               STD_ON
#define COMM_ISDEF_PNCTOCHANNELROUTINGSTATEOFPCPARTITIONCONFIG                                      STD_ON
#define COMM_ISDEF_POSTINITIALIZEDOFPCPARTITIONCONFIG                                               STD_ON
#define COMM_ISDEF_RESETREQUIREDOFPCPARTITIONCONFIG                                                 STD_ON
#define COMM_ISDEF_USERBYTEMASKOFPCPARTITIONCONFIG                                                  STD_OFF
#define COMM_ISDEF_USEROFPCPARTITIONCONFIG                                                          STD_ON
#define COMM_ISDEF_USERPNCBYTEMASKOFPCPARTITIONCONFIG                                               STD_ON
#define COMM_ISDEF_USERREQFULLCOMOFPCPARTITIONCONFIG                                                STD_ON
#define COMM_ISDEF_USERREQPNCFULLCOMOFPCPARTITIONCONFIG                                             STD_ON
/** 
  \}
*/ 

/** 
  \defgroup  ComMPCEqualsAlwaysToDefines  ComM Equals Always To Defines (PRE_COMPILE)
  \brief  If all values in a CONST array or an element in a CONST array of structs are equal, the define contains the always equals value.
  \{
*/ 
#define COMM_EQ2_BUSTYPEOFCHANNEL                                                                   COMM_BUS_TYPE_CAN
#define COMM_EQ2_ENABLEDOFCHANNEL                                                                   
#define COMM_EQ2_GETCURRENTBUSSMMODEAPIOFCHANNEL                                                    
#define COMM_EQ2_GWTYPEOFCHANNEL                                                                    COMM_GATEWAY_TYPE_NONE
#define COMM_EQ2_INHIBITIONINITVALUEOFCHANNEL                                                       0x00u
#define COMM_EQ2_NMSUPPORTOFCHANNEL                                                                 TRUE
#define COMM_EQ2_NMTYPEOFCHANNEL                                                                    
#define COMM_EQ2_PARTITIONCONFIGIDXOFCHANNEL                                                        0u
#define COMM_EQ2_PNCNMREQUESTOFCHANNEL                                                              TRUE
#define COMM_EQ2_REQUESTBUSSMMODEAPIOFCHANNEL                                                       
#define COMM_EQ2_RESETAFTERFORCINGNOCOMMOFCHANNEL                                                   TRUE
#define COMM_EQ2_SILENTSUPPORTOFCHANNEL                                                             TRUE
#define COMM_EQ2_WAKEUPSTATEOFCHANNEL                                                               COMM_FULL_COM_READY_SLEEP
#define COMM_EQ2_PNCPBINDENDIDXOFCHANNELPB                                                          
#define COMM_EQ2_PNCPBINDSTARTIDXOFCHANNELPB                                                        
#define COMM_EQ2_PNCPBINDUSEDOFCHANNELPB                                                            
#define COMM_EQ2_USERREQFULLCOMENDIDXOFCHANNELPB                                                    
#define COMM_EQ2_USERREQFULLCOMSTARTIDXOFCHANNELPB                                                  
#define COMM_EQ2_USERREQFULLCOMUSEDOFCHANNELPB                                                      
#define COMM_EQ2_SYMBOLICNAMEVALUEOFEIRATXSIGNALINDIRECTION                                         
#define COMM_EQ2_PCPARTITIONCONFIGIDXOFPARTITIONIDENTIFIERS                                         
#define COMM_EQ2_PARTITIONSNVOFPARTITIONIDENTIFIERS                                                 
#define COMM_EQ2_CLEARMASKOFPNC                                                                     
#define COMM_EQ2_PNCIDOFPNC                                                                         
#define COMM_EQ2_SETMASKOFPNC                                                                       
#define COMM_EQ2_PNCCHANNELMAPPING                                                                  
#define COMM_EQ2_PNCCHANNELMAPPINGENDIDXOFPNCPB                                                     
#define COMM_EQ2_PNCCHANNELMAPPINGSTARTIDXOFPNCPB                                                   
#define COMM_EQ2_PNCCHANNELMAPPINGUSEDOFPNCPB                                                       TRUE
#define COMM_EQ2_PNCSIGNALINDENDIDXOFPNCPB                                                          
#define COMM_EQ2_PNCSIGNALINDSTARTIDXOFPNCPB                                                        
#define COMM_EQ2_PNCSIGNALINDUSEDOFPNCPB                                                            TRUE
#define COMM_EQ2_SIGNALBYTEINDEXOFPNCPB                                                             
#define COMM_EQ2_USERREQPNCFULLCOMENDIDXOFPNCPB                                                     
#define COMM_EQ2_USERREQPNCFULLCOMSTARTIDXOFPNCPB                                                   
#define COMM_EQ2_PNCPBIND                                                                           
#define COMM_EQ2_BUSTYPEIDOFPNCSIGNAL                                                               0u
#define COMM_EQ2_CHANNELIDXOFPNCSIGNAL                                                              
#define COMM_EQ2_CHANNELUSEDOFPNCSIGNAL                                                             
#define COMM_EQ2_PNCSIGNALVALUESENDIDXOFPNCSIGNAL                                                   
#define COMM_EQ2_PNCSIGNALVALUESSTARTIDXOFPNCSIGNAL                                                 
#define COMM_EQ2_PNCSIGNALVALUESUSEDOFPNCSIGNAL                                                     
#define COMM_EQ2_TYPEOFPNCSIGNAL                                                                    
#define COMM_EQ2_PNCSIGNALIND                                                                       
#define COMM_EQ2_PARTITIONCONFIGIDXOFUSER                                                           0u
#define COMM_EQ2_PNCUSEROFUSER                                                                      
#define COMM_EQ2_USERBYTEMASKENDIDXOFUSER                                                           
#define COMM_EQ2_USERBYTEMASKSTARTIDXOFUSER                                                         
#define COMM_EQ2_USERBYTEMASKUSEDOFUSER                                                             TRUE
#define COMM_EQ2_USERPNCBYTEMASKENDIDXOFUSER                                                        
#define COMM_EQ2_USERPNCBYTEMASKLENGTHOFUSER                                                        
#define COMM_EQ2_USERPNCBYTEMASKSTARTIDXOFUSER                                                      
#define COMM_EQ2_USERPNCBYTEMASKUSEDOFUSER                                                          
#define COMM_EQ2_CHANNELOFUSERBYTEMASK                                                              
#define COMM_EQ2_CLEARMASKOFUSERBYTEMASK                                                            
#define COMM_EQ2_SETMASKOFUSERBYTEMASK                                                              
#define COMM_EQ2_USERREQFULLCOMIDXOFUSERBYTEMASK                                                    0u
#define COMM_EQ2_CLEARMASKOFUSERPNCBYTEMASK                                                         0xFEu
#define COMM_EQ2_PNCIDOFUSERPNCBYTEMASK                                                             
#define COMM_EQ2_PNCIDXOFUSERPNCBYTEMASK                                                            
#define COMM_EQ2_SETMASKOFUSERPNCBYTEMASK                                                           0x01u
#define COMM_EQ2_USERREQPNCFULLCOMIDXOFUSERPNCBYTEMASK                                              
#define COMM_EQ2_PCPARTITIONCONFIGOFPCCONFIG                                                        
#define COMM_EQ2_PARTITIONIDENTIFIERSOFPCCONFIG                                                     ComM_PartitionIdentifiers
#define COMM_EQ2_ACTIVECOMMODEOFPCPARTITIONCONFIG                                                   ComM_ActiveComMode.raw
#define COMM_EQ2_ACTIVEPNCCOMMODEOFPCPARTITIONCONFIG                                                ComM_ActivePncComMode.raw
#define COMM_EQ2_BUSCOMMODEREQOFPCPARTITIONCONFIG                                                   ComM_BusComModeReq.raw
#define COMM_EQ2_BUSPNCCOMMODEREQOFPCPARTITIONCONFIG                                                ComM_BusPncComModeReq.raw
#define COMM_EQ2_BUSSMSTATEOFPCPARTITIONCONFIG                                                      ComM_BusSmState.raw
#define COMM_EQ2_CHANNELOFPCPARTITIONCONFIG                                                         
#define COMM_EQ2_CHANNELPBOFPCPARTITIONCONFIG                                                       
#define COMM_EQ2_COMALLOWEDOFPCPARTITIONCONFIG                                                      ComM_ComAllowed.raw
#define COMM_EQ2_DCMREQUESTACTIVEOFPCPARTITIONCONFIG                                                ComM_DcmRequestActive.raw
#define COMM_EQ2_ECUMWAKEUPINDICATEDOFPCPARTITIONCONFIG                                             ComM_EcuMWakeUpIndicated
#define COMM_EQ2_EIRATXSIGNALINDIRECTIONOFPCPARTITIONCONFIG                                         ComM_EiraTxSignalIndirection
#define COMM_EQ2_INHIBITIONOFPCPARTITIONCONFIG                                                      (&(ComM_Inhibition))
#define COMM_EQ2_INITSTATUSOFPCPARTITIONCONFIG                                                      (&(ComM_InitStatus))
#define COMM_EQ2_NMSTARTUPINDICATEDOFPCPARTITIONCONFIG                                              ComM_NmStartUpIndicated
#define COMM_EQ2_PNCCHANNELMAPPINGOFPCPARTITIONCONFIG                                               
#define COMM_EQ2_PNCOFPCPARTITIONCONFIG                                                             ComM_Pnc
#define COMM_EQ2_PNCPSLEEPTIMEROFPCPARTITIONCONFIG                                                  ComM_PncPSleepTimer.raw
#define COMM_EQ2_PNCPBINDOFPCPARTITIONCONFIG                                                        ComM_PncPbInd
#define COMM_EQ2_PNCPBOFPCPARTITIONCONFIG                                                           ComM_PncPb
#define COMM_EQ2_PNCSIGNALINDOFPCPARTITIONCONFIG                                                    
#define COMM_EQ2_PNCSIGNALOFPCPARTITIONCONFIG                                                       
#define COMM_EQ2_PNCSIGNALVALUESOFPCPARTITIONCONFIG                                                 ComM_PncSignalValues.raw
#define COMM_EQ2_PNCTOCHANNELROUTINGSTATEOFPCPARTITIONCONFIG                                        ComM_PncToChannelRoutingState.raw
#define COMM_EQ2_POSTINITIALIZEDOFPCPARTITIONCONFIG                                                 ComM_PostInitialized
#define COMM_EQ2_RESETREQUIREDOFPCPARTITIONCONFIG                                                   ComM_ResetRequired.raw
#define COMM_EQ2_USERBYTEMASKOFPCPARTITIONCONFIG                                                    
#define COMM_EQ2_USEROFPCPARTITIONCONFIG                                                            ComM_User
#define COMM_EQ2_USERPNCBYTEMASKOFPCPARTITIONCONFIG                                                 ComM_UserPncByteMask
#define COMM_EQ2_USERREQFULLCOMOFPCPARTITIONCONFIG                                                  ComM_UserReqFullCom
#define COMM_EQ2_USERREQPNCFULLCOMOFPCPARTITIONCONFIG                                               ComM_UserReqPncFullCom
/** 
  \}
*/ 

/** 
  \defgroup  ComMPCSymbolicInitializationPointers  ComM Symbolic Initialization Pointers (PRE_COMPILE)
  \brief  Symbolic initialization pointers to be used in the call of a preinit or init function.
  \{
*/ 
#define ComM_Config_Left_Ptr                                                                        &(ComM_PCConfig.Config_Left)  /**< symbolic identifier which shall be used to initialize 'ComM' */
#define ComM_Config_Right_Ptr                                                                       &(ComM_PCConfig.Config_Right)  /**< symbolic identifier which shall be used to initialize 'ComM' */
/** 
  \}
*/ 

/** 
  \defgroup  ComMPCInitializationSymbols  ComM Initialization Symbols (PRE_COMPILE)
  \brief  Symbolic initialization pointers which may be used in the call of a preinit or init function. Please note, that the defined value can be a 'NULL_PTR' and the address operator is not usable.
  \{
*/ 
#define ComM_Config_Left                                                                            ComM_PCConfig.Config_Left  /**< symbolic identifier which could be used to initialize 'ComM */
#define ComM_Config_Right                                                                           ComM_PCConfig.Config_Right  /**< symbolic identifier which could be used to initialize 'ComM */
/** 
  \}
*/ 

/** 
  \defgroup  ComMPCGeneral  ComM General (PRE_COMPILE)
  \brief  General constant defines not associated with a group of defines.
  \{
*/ 
#define COMM_CHECK_INIT_POINTER                                                                     STD_ON  /**< STD_ON if the init pointer shall not be used as NULL_PTR and a check shall validate this. */
#define COMM_FINAL_MAGIC_NUMBER                                                                     0x0C1Eu  /**< the precompile constant to validate the size of the initialization structure at initialization time of ComM */
#define COMM_INDIVIDUAL_POSTBUILD                                                                   STD_OFF  /**< the precompile constant to check, that the module is individual postbuildable. The module 'ComM' is not configured to be postbuild capable. */
#define COMM_INIT_DATA                                                                              COMM_CONST  /**< CompilerMemClassDefine for the initialization data. */
#define COMM_INIT_DATA_HASH_CODE                                                                    -1019381215  /**< the precompile constant to validate the initialization structure at initialization time of ComM with a hashcode. The seed value is '0x0C1Eu' */
#define COMM_USE_ECUM_BSW_ERROR_HOOK                                                                STD_OFF  /**< STD_ON if the EcuM_BswErrorHook shall be called in the ConfigPtr check. */
#define COMM_USE_INIT_POINTER                                                                       STD_ON  /**< STD_ON if the init pointer ComM shall be used. */
/** 
  \}
*/ 


/**********************************************************************************************************************
  CONFIGURATION CLASS: POST_BUILD
  SECTION: GLOBAL CONSTANT MACROS
**********************************************************************************************************************/
/** 
  \defgroup  ComMPBDataSwitches  ComM Data Switches  (POST_BUILD)
  \brief  These defines are used to deactivate data and their processing.
  \{
*/ 
#define COMM_PBCONFIG                                                                               STD_OFF  /**< Deactivateable: 'ComM_PBConfig' Reason: 'the module configuration is VARIANT_PRE_COMPILE.' */
#define COMM_LTCONFIGIDXOFPBCONFIG                                                                  STD_OFF  /**< Deactivateable: 'ComM_PBConfig.LTConfigIdx' Reason: 'the module configuration is VARIANT_PRE_COMPILE.' */
#define COMM_PBPARTITIONCONFIGOFPBCONFIG                                                            STD_OFF  /**< Deactivateable: 'ComM_PBConfig.PBPartitionConfig' Reason: 'the module configuration is VARIANT_PRE_COMPILE.' */
#define COMM_PCCONFIGIDXOFPBCONFIG                                                                  STD_OFF  /**< Deactivateable: 'ComM_PBConfig.PCConfigIdx' Reason: 'the module configuration is VARIANT_PRE_COMPILE.' */
#define COMM_PBPARTITIONCONFIG                                                                      STD_OFF  /**< Deactivateable: 'ComM_PBPartitionConfigLeft' Reason: 'the module configuration is VARIANT_PRE_COMPILE.' and Deactivateable: 'ComM_PBPartitionConfigRight' Reason: 'the module configuration is VARIANT_PRE_COMPILE.' */
/** 
  \}
*/ 



/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
**********************************************************************************************************************/
typedef P2FUNC(Std_ReturnType, COMM_CODE, RequestBusSMModeApiType) (NetworkHandleType Channel, ComM_ModeType ComMode);
typedef P2FUNC(Std_ReturnType, COMM_CODE, GetCurrentBusSMModeApiType) (NetworkHandleType Channel, P2VAR(ComM_ModeType, AUTOMATIC, AUTOMATIC) ComMode);
typedef P2FUNC(Std_ReturnType, COMM_CODE, ComM_ForwardingFunctionPtrType) (CONST(NetworkHandleType, AUTOMATIC)); /* PRQA S 1336 */ /* MD_ComM_1336 */

/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: SIZEOF DATA TYPES
**********************************************************************************************************************/
/** 
  \defgroup  ComMPCSizeOfTypes  ComM SizeOf Types (PRE_COMPILE)
  \brief  These type definitions are used for the SizeOf information.
  \{
*/ 
/**   \brief  value based type definition for ComM_SizeOfActiveComMode */
typedef uint8 ComM_SizeOfActiveComModeType;

/**   \brief  value based type definition for ComM_SizeOfActivePncComMode */
typedef uint8 ComM_SizeOfActivePncComModeType;

/**   \brief  value based type definition for ComM_SizeOfBusComModeReq */
typedef uint8 ComM_SizeOfBusComModeReqType;

/**   \brief  value based type definition for ComM_SizeOfBusPncComModeReq */
typedef uint8 ComM_SizeOfBusPncComModeReqType;

/**   \brief  value based type definition for ComM_SizeOfBusSmState */
typedef uint8 ComM_SizeOfBusSmStateType;

/**   \brief  value based type definition for ComM_SizeOfChannel */
typedef uint8 ComM_SizeOfChannelType;

/**   \brief  value based type definition for ComM_SizeOfChannelPb */
typedef uint8 ComM_SizeOfChannelPbType;

/**   \brief  value based type definition for ComM_SizeOfComAllowed */
typedef uint8 ComM_SizeOfComAllowedType;

/**   \brief  value based type definition for ComM_SizeOfDcmRequestActive */
typedef uint8 ComM_SizeOfDcmRequestActiveType;

/**   \brief  value based type definition for ComM_SizeOfEcuMWakeUpIndicated */
typedef uint8 ComM_SizeOfEcuMWakeUpIndicatedType;

/**   \brief  value based type definition for ComM_SizeOfEiraTxSignalIndirection */
typedef uint8 ComM_SizeOfEiraTxSignalIndirectionType;

/**   \brief  value based type definition for ComM_SizeOfNmStartUpIndicated */
typedef uint8 ComM_SizeOfNmStartUpIndicatedType;

/**   \brief  value based type definition for ComM_SizeOfPartitionIdentifiers */
typedef uint8 ComM_SizeOfPartitionIdentifiersType;

/**   \brief  value based type definition for ComM_SizeOfPnc */
typedef uint8 ComM_SizeOfPncType;

/**   \brief  value based type definition for ComM_SizeOfPncChannelMapping */
typedef uint8 ComM_SizeOfPncChannelMappingType;

/**   \brief  value based type definition for ComM_SizeOfPncPSleepTimer */
typedef uint8 ComM_SizeOfPncPSleepTimerType;

/**   \brief  value based type definition for ComM_SizeOfPncPb */
typedef uint8 ComM_SizeOfPncPbType;

/**   \brief  value based type definition for ComM_SizeOfPncPbInd */
typedef uint8 ComM_SizeOfPncPbIndType;

/**   \brief  value based type definition for ComM_SizeOfPncSignal */
typedef uint8 ComM_SizeOfPncSignalType;

/**   \brief  value based type definition for ComM_SizeOfPncSignalInd */
typedef uint8 ComM_SizeOfPncSignalIndType;

/**   \brief  value based type definition for ComM_SizeOfPncSignalValues */
typedef uint8 ComM_SizeOfPncSignalValuesType;

/**   \brief  value based type definition for ComM_SizeOfPncToChannelRoutingState */
typedef uint8 ComM_SizeOfPncToChannelRoutingStateType;

/**   \brief  value based type definition for ComM_SizeOfPostInitialized */
typedef uint8 ComM_SizeOfPostInitializedType;

/**   \brief  value based type definition for ComM_SizeOfResetRequired */
typedef uint8 ComM_SizeOfResetRequiredType;

/**   \brief  value based type definition for ComM_SizeOfUser */
typedef uint8 ComM_SizeOfUserType;

/**   \brief  value based type definition for ComM_SizeOfUserByteMask */
typedef uint8 ComM_SizeOfUserByteMaskType;

/**   \brief  value based type definition for ComM_SizeOfUserPncByteMask */
typedef uint8 ComM_SizeOfUserPncByteMaskType;

/**   \brief  value based type definition for ComM_SizeOfUserReqFullCom */
typedef uint8 ComM_SizeOfUserReqFullComType;

/**   \brief  value based type definition for ComM_SizeOfUserReqPncFullCom */
typedef uint8 ComM_SizeOfUserReqPncFullComType;

/** 
  \}
*/ 

/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL SIMPLE DATA TYPES AND STRUCTURES
**********************************************************************************************************************/
/** 
  \defgroup  ComMPCIterableTypes  ComM Iterable Types (PRE_COMPILE)
  \brief  These type definitions are used to iterate over an array with least processor cycles for variable access as possible.
  \{
*/ 
/**   \brief  type used to iterate ComM_Channel */
typedef uint8_least ComM_ChannelIterType;

/**   \brief  type used to iterate ComM_ChannelPb */
typedef uint8_least ComM_ChannelPbIterType;

/**   \brief  type used to iterate ComM_EcuMWakeUpIndicated */
typedef uint8_least ComM_EcuMWakeUpIndicatedIterType;

/**   \brief  type used to iterate ComM_EiraTxSignalIndirection */
typedef uint8_least ComM_EiraTxSignalIndirectionIterType;

/**   \brief  type used to iterate ComM_NmStartUpIndicated */
typedef uint8_least ComM_NmStartUpIndicatedIterType;

/**   \brief  type used to iterate ComM_PartitionIdentifiers */
typedef uint8_least ComM_PartitionIdentifiersIterType;

/**   \brief  type used to iterate ComM_Pnc */
typedef uint8_least ComM_PncIterType;

/**   \brief  type used to iterate ComM_PncChannelMapping */
typedef uint8_least ComM_PncChannelMappingIterType;

/**   \brief  type used to iterate ComM_PncPb */
typedef uint8_least ComM_PncPbIterType;

/**   \brief  type used to iterate ComM_PncPbInd */
typedef uint8_least ComM_PncPbIndIterType;

/**   \brief  type used to iterate ComM_PncSignal */
typedef uint8_least ComM_PncSignalIterType;

/**   \brief  type used to iterate ComM_PncSignalInd */
typedef uint8_least ComM_PncSignalIndIterType;

/**   \brief  type used to iterate ComM_PncSignalValues */
typedef uint8_least ComM_PncSignalValuesIterType;

/**   \brief  type used to iterate ComM_PostInitialized */
typedef uint8_least ComM_PostInitializedIterType;

/**   \brief  type used to iterate ComM_User */
typedef uint8_least ComM_UserIterType;

/**   \brief  type used to iterate ComM_UserByteMask */
typedef uint8_least ComM_UserByteMaskIterType;

/**   \brief  type used to iterate ComM_UserPncByteMask */
typedef uint8_least ComM_UserPncByteMaskIterType;

/**   \brief  type used to iterate ComM_UserReqFullCom */
typedef uint8_least ComM_UserReqFullComIterType;

/**   \brief  type used to iterate ComM_UserReqPncFullCom */
typedef uint8_least ComM_UserReqPncFullComIterType;

/**   \brief  type used to iterate ComM_PCPartitionConfig */
typedef uint8_least ComM_PCPartitionConfigIterType;

/** 
  \}
*/ 

/** 
  \defgroup  ComMPCIterableTypesWithSizeRelations  ComM Iterable Types With Size Relations (PRE_COMPILE)
  \brief  These type definitions are used to iterate over a VAR based array with the same iterator as the related CONST array.
  \{
*/ 
/**   \brief  type used to iterate ComM_ActiveComMode */
typedef ComM_ChannelIterType ComM_ActiveComModeIterType;

/**   \brief  type used to iterate ComM_ActivePncComMode */
typedef ComM_PncIterType ComM_ActivePncComModeIterType;

/**   \brief  type used to iterate ComM_BusComModeReq */
typedef ComM_ChannelIterType ComM_BusComModeReqIterType;

/**   \brief  type used to iterate ComM_BusPncComModeReq */
typedef ComM_PncIterType ComM_BusPncComModeReqIterType;

/**   \brief  type used to iterate ComM_BusSmState */
typedef ComM_ChannelIterType ComM_BusSmStateIterType;

/**   \brief  type used to iterate ComM_ComAllowed */
typedef ComM_ChannelIterType ComM_ComAllowedIterType;

/**   \brief  type used to iterate ComM_DcmRequestActive */
typedef ComM_ChannelIterType ComM_DcmRequestActiveIterType;

/**   \brief  type used to iterate ComM_PncPSleepTimer */
typedef ComM_PncIterType ComM_PncPSleepTimerIterType;

/**   \brief  type used to iterate ComM_PncToChannelRoutingState */
typedef ComM_ChannelIterType ComM_PncToChannelRoutingStateIterType;

/**   \brief  type used to iterate ComM_ResetRequired */
typedef ComM_ChannelIterType ComM_ResetRequiredIterType;

/** 
  \}
*/ 

/** 
  \defgroup  ComMPCValueTypes  ComM Value Types (PRE_COMPILE)
  \brief  These type definitions are used for value based data representations.
  \{
*/ 
/**   \brief  value based type definition for ComM_EnabledOfChannel */
typedef boolean ComM_EnabledOfChannelType;

/**   \brief  value based type definition for ComM_GwTypeOfChannel */
typedef uint8 ComM_GwTypeOfChannelType;

/**   \brief  value based type definition for ComM_InhibitionInitValueOfChannel */
typedef uint8 ComM_InhibitionInitValueOfChannelType;

/**   \brief  value based type definition for ComM_NmSupportOfChannel */
typedef boolean ComM_NmSupportOfChannelType;

/**   \brief  value based type definition for ComM_NmTypeOfChannel */
typedef uint8 ComM_NmTypeOfChannelType;

/**   \brief  value based type definition for ComM_PartitionConfigIdxOfChannel */
typedef uint8 ComM_PartitionConfigIdxOfChannelType;

/**   \brief  value based type definition for ComM_PncNmRequestOfChannel */
typedef boolean ComM_PncNmRequestOfChannelType;

/**   \brief  value based type definition for ComM_ResetAfterForcingNoCommOfChannel */
typedef boolean ComM_ResetAfterForcingNoCommOfChannelType;

/**   \brief  value based type definition for ComM_SilentSupportOfChannel */
typedef boolean ComM_SilentSupportOfChannelType;

/**   \brief  value based type definition for ComM_WakeupStateOfChannel */
typedef uint8 ComM_WakeupStateOfChannelType;

/**   \brief  value based type definition for ComM_PncPbIndEndIdxOfChannelPb */
typedef uint8 ComM_PncPbIndEndIdxOfChannelPbType;

/**   \brief  value based type definition for ComM_PncPbIndStartIdxOfChannelPb */
typedef uint8 ComM_PncPbIndStartIdxOfChannelPbType;

/**   \brief  value based type definition for ComM_PncPbIndUsedOfChannelPb */
typedef boolean ComM_PncPbIndUsedOfChannelPbType;

/**   \brief  value based type definition for ComM_UserReqFullComEndIdxOfChannelPb */
typedef uint8 ComM_UserReqFullComEndIdxOfChannelPbType;

/**   \brief  value based type definition for ComM_UserReqFullComStartIdxOfChannelPb */
typedef uint8 ComM_UserReqFullComStartIdxOfChannelPbType;

/**   \brief  value based type definition for ComM_UserReqFullComUsedOfChannelPb */
typedef boolean ComM_UserReqFullComUsedOfChannelPbType;

/**   \brief  value based type definition for ComM_ComAllowed */
typedef boolean ComM_ComAllowedType;

/**   \brief  value based type definition for ComM_DcmRequestActive */
typedef boolean ComM_DcmRequestActiveType;

/**   \brief  value based type definition for ComM_EcuMWakeUpIndicated */
typedef boolean ComM_EcuMWakeUpIndicatedType;

/**   \brief  value based type definition for ComM_NmStartUpIndicated */
typedef boolean ComM_NmStartUpIndicatedType;

/**   \brief  value based type definition for ComM_PCPartitionConfigIdxOfPartitionIdentifiers */
typedef uint8 ComM_PCPartitionConfigIdxOfPartitionIdentifiersType;

/**   \brief  value based type definition for ComM_PartitionSNVOfPartitionIdentifiers */
typedef uint32 ComM_PartitionSNVOfPartitionIdentifiersType;

/**   \brief  value based type definition for ComM_ClearMaskOfPnc */
typedef uint8 ComM_ClearMaskOfPncType;

/**   \brief  value based type definition for ComM_PncIdOfPnc */
typedef uint8 ComM_PncIdOfPncType;

/**   \brief  value based type definition for ComM_SetMaskOfPnc */
typedef uint8 ComM_SetMaskOfPncType;

/**   \brief  value based type definition for ComM_PncChannelMapping */
typedef uint8 ComM_PncChannelMappingType;

/**   \brief  value based type definition for ComM_PncPSleepTimer */
typedef uint16 ComM_PncPSleepTimerType;

/**   \brief  value based type definition for ComM_PncChannelMappingEndIdxOfPncPb */
typedef uint8 ComM_PncChannelMappingEndIdxOfPncPbType;

/**   \brief  value based type definition for ComM_PncChannelMappingStartIdxOfPncPb */
typedef uint8 ComM_PncChannelMappingStartIdxOfPncPbType;

/**   \brief  value based type definition for ComM_PncChannelMappingUsedOfPncPb */
typedef boolean ComM_PncChannelMappingUsedOfPncPbType;

/**   \brief  value based type definition for ComM_PncSignalIndEndIdxOfPncPb */
typedef uint8 ComM_PncSignalIndEndIdxOfPncPbType;

/**   \brief  value based type definition for ComM_PncSignalIndStartIdxOfPncPb */
typedef uint8 ComM_PncSignalIndStartIdxOfPncPbType;

/**   \brief  value based type definition for ComM_PncSignalIndUsedOfPncPb */
typedef boolean ComM_PncSignalIndUsedOfPncPbType;

/**   \brief  value based type definition for ComM_SignalByteIndexOfPncPb */
typedef uint8 ComM_SignalByteIndexOfPncPbType;

/**   \brief  value based type definition for ComM_UserReqPncFullComEndIdxOfPncPb */
typedef uint8 ComM_UserReqPncFullComEndIdxOfPncPbType;

/**   \brief  value based type definition for ComM_UserReqPncFullComStartIdxOfPncPb */
typedef uint8 ComM_UserReqPncFullComStartIdxOfPncPbType;

/**   \brief  value based type definition for ComM_PncPbInd */
typedef uint8 ComM_PncPbIndType;

/**   \brief  value based type definition for ComM_BusTypeIdOfPncSignal */
typedef uint8 ComM_BusTypeIdOfPncSignalType;

/**   \brief  value based type definition for ComM_ChannelIdxOfPncSignal */
typedef uint8 ComM_ChannelIdxOfPncSignalType;

/**   \brief  value based type definition for ComM_ChannelUsedOfPncSignal */
typedef boolean ComM_ChannelUsedOfPncSignalType;

/**   \brief  value based type definition for ComM_PncSignalValuesEndIdxOfPncSignal */
typedef uint8 ComM_PncSignalValuesEndIdxOfPncSignalType;

/**   \brief  value based type definition for ComM_PncSignalValuesStartIdxOfPncSignal */
typedef uint8 ComM_PncSignalValuesStartIdxOfPncSignalType;

/**   \brief  value based type definition for ComM_PncSignalValuesUsedOfPncSignal */
typedef boolean ComM_PncSignalValuesUsedOfPncSignalType;

/**   \brief  value based type definition for ComM_TypeOfPncSignal */
typedef uint8 ComM_TypeOfPncSignalType;

/**   \brief  value based type definition for ComM_PncSignalInd */
typedef uint8 ComM_PncSignalIndType;

/**   \brief  value based type definition for ComM_PncSignalValues */
typedef uint8 ComM_PncSignalValuesType;

/**   \brief  value based type definition for ComM_PncToChannelRoutingState */
typedef uint8 ComM_PncToChannelRoutingStateType;

/**   \brief  value based type definition for ComM_PostInitialized */
typedef boolean ComM_PostInitializedType;

/**   \brief  value based type definition for ComM_ResetRequired */
typedef boolean ComM_ResetRequiredType;

/**   \brief  value based type definition for ComM_PartitionConfigIdxOfUser */
typedef uint8 ComM_PartitionConfigIdxOfUserType;

/**   \brief  value based type definition for ComM_PncUserOfUser */
typedef boolean ComM_PncUserOfUserType;

/**   \brief  value based type definition for ComM_UserByteMaskEndIdxOfUser */
typedef uint8 ComM_UserByteMaskEndIdxOfUserType;

/**   \brief  value based type definition for ComM_UserByteMaskStartIdxOfUser */
typedef uint8 ComM_UserByteMaskStartIdxOfUserType;

/**   \brief  value based type definition for ComM_UserByteMaskUsedOfUser */
typedef boolean ComM_UserByteMaskUsedOfUserType;

/**   \brief  value based type definition for ComM_UserPncByteMaskEndIdxOfUser */
typedef uint8 ComM_UserPncByteMaskEndIdxOfUserType;

/**   \brief  value based type definition for ComM_UserPncByteMaskLengthOfUser */
typedef uint8 ComM_UserPncByteMaskLengthOfUserType;

/**   \brief  value based type definition for ComM_UserPncByteMaskStartIdxOfUser */
typedef uint8 ComM_UserPncByteMaskStartIdxOfUserType;

/**   \brief  value based type definition for ComM_UserPncByteMaskUsedOfUser */
typedef boolean ComM_UserPncByteMaskUsedOfUserType;

/**   \brief  value based type definition for ComM_ChannelOfUserByteMask */
typedef uint8 ComM_ChannelOfUserByteMaskType;

/**   \brief  value based type definition for ComM_ClearMaskOfUserByteMask */
typedef uint8 ComM_ClearMaskOfUserByteMaskType;

/**   \brief  value based type definition for ComM_SetMaskOfUserByteMask */
typedef uint8 ComM_SetMaskOfUserByteMaskType;

/**   \brief  value based type definition for ComM_UserReqFullComIdxOfUserByteMask */
typedef uint8 ComM_UserReqFullComIdxOfUserByteMaskType;

/**   \brief  value based type definition for ComM_ClearMaskOfUserPncByteMask */
typedef uint8 ComM_ClearMaskOfUserPncByteMaskType;

/**   \brief  value based type definition for ComM_PncIDOfUserPncByteMask */
typedef uint8 ComM_PncIDOfUserPncByteMaskType;

/**   \brief  value based type definition for ComM_PncIdxOfUserPncByteMask */
typedef uint8 ComM_PncIdxOfUserPncByteMaskType;

/**   \brief  value based type definition for ComM_SetMaskOfUserPncByteMask */
typedef uint8 ComM_SetMaskOfUserPncByteMaskType;

/**   \brief  value based type definition for ComM_UserReqPncFullComIdxOfUserPncByteMask */
typedef uint8 ComM_UserReqPncFullComIdxOfUserPncByteMaskType;

/**   \brief  value based type definition for ComM_UserReqFullCom */
typedef uint8 ComM_UserReqFullComType;

/**   \brief  value based type definition for ComM_UserReqPncFullCom */
typedef uint8 ComM_UserReqPncFullComType;

/** 
  \}
*/ 


/* PRQA S 0639, 0779 POSTBUILDGLOBALDATATYPES */ /* MD_MSR_1.1_639, MD_MSR_Rule5.2_0779 */
/**********************************************************************************************************************
  CONFIGURATION CLASS: POST_BUILD
  SECTION: SIZEOF DATA TYPES
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: POST_BUILD
  SECTION: GLOBAL SIMPLE DATA TYPES AND STRUCTURES
**********************************************************************************************************************/

/* PRQA L:POSTBUILDGLOBALDATATYPES */

/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL COMPLEX DATA TYPES AND STRUCTURES
**********************************************************************************************************************/
/** 
  \defgroup  ComMPCStructTypes  ComM Struct Types (PRE_COMPILE)
  \brief  These type definitions are used for structured data representations.
  \{
*/ 
/**   \brief  type used in ComM_Channel */
typedef struct sComM_ChannelType
{
  ComM_EnabledOfChannelType EnabledOfChannel;  /**< Decides if the channel is enabled in the variant */
  ComM_NmTypeOfChannelType NmTypeOfChannel;  /**< The Network Management type of the channel */
  GetCurrentBusSMModeApiType GetCurrentBusSMModeApiOfChannel;  /**< Query the current communication mode from the corresponding BusSM */
  RequestBusSMModeApiType RequestBusSMModeApiOfChannel;  /**< Request the communication mode from the corresponding BusSM */
} ComM_ChannelType;

/**   \brief  type used in ComM_ChannelPb */
typedef struct sComM_ChannelPbType
{
  ComM_PncPbIndEndIdxOfChannelPbType PncPbIndEndIdxOfChannelPb;  /**< the end index of the 0:n relation pointing to ComM_PncPbInd */
  ComM_PncPbIndStartIdxOfChannelPbType PncPbIndStartIdxOfChannelPb;  /**< the start index of the 0:n relation pointing to ComM_PncPbInd */
  ComM_UserReqFullComEndIdxOfChannelPbType UserReqFullComEndIdxOfChannelPb;  /**< the end index of the 0:n relation pointing to ComM_UserReqFullCom */
  ComM_UserReqFullComStartIdxOfChannelPbType UserReqFullComStartIdxOfChannelPb;  /**< the start index of the 0:n relation pointing to ComM_UserReqFullCom */
} ComM_ChannelPbType;

/**   \brief  type used in ComM_EiraTxSignalIndirection */
typedef struct sComM_EiraTxSignalIndirectionType
{
  Com_SignalIdType SymbolicNameValueOfEiraTxSignalIndirection;  /**< SymbolicNameValue of Tx Eira Signal */
} ComM_EiraTxSignalIndirectionType;

/**   \brief  type used in ComM_PartitionIdentifiers */
typedef struct sComM_PartitionIdentifiersType
{
  ComM_PartitionSNVOfPartitionIdentifiersType PartitionSNVOfPartitionIdentifiers;
  ComM_PCPartitionConfigIdxOfPartitionIdentifiersType PCPartitionConfigIdxOfPartitionIdentifiers;  /**< the index of the 1:1 relation pointing to ComM_PCPartitionConfig */
} ComM_PartitionIdentifiersType;

/**   \brief  type used in ComM_Pnc */
typedef struct sComM_PncType
{
  ComM_ClearMaskOfPncType ClearMaskOfPnc;  /**< Clear mask for the partial network related signals (EIRA, ERA) */
  ComM_PncIdOfPncType PncIdOfPnc;  /**< System ID of the partial network */
  ComM_SetMaskOfPncType SetMaskOfPnc;  /**< Set mask for the partial network related signals (EIRA, ERA) */
} ComM_PncType;

/**   \brief  type used in ComM_PncPb */
typedef struct sComM_PncPbType
{
  ComM_PncChannelMappingEndIdxOfPncPbType PncChannelMappingEndIdxOfPncPb;  /**< the end index of the 0:n relation pointing to ComM_PncChannelMapping */
  ComM_PncChannelMappingStartIdxOfPncPbType PncChannelMappingStartIdxOfPncPb;  /**< the start index of the 0:n relation pointing to ComM_PncChannelMapping */
  ComM_PncSignalIndEndIdxOfPncPbType PncSignalIndEndIdxOfPncPb;  /**< the end index of the 0:n relation pointing to ComM_PncSignalInd */
  ComM_PncSignalIndStartIdxOfPncPbType PncSignalIndStartIdxOfPncPb;  /**< the start index of the 0:n relation pointing to ComM_PncSignalInd */
  ComM_SignalByteIndexOfPncPbType SignalByteIndexOfPncPb;  /**< Byte index in the partial network related signals (EIRA, ERA) */
  ComM_UserReqPncFullComEndIdxOfPncPbType UserReqPncFullComEndIdxOfPncPb;  /**< the end index of the 1:n relation pointing to ComM_UserReqPncFullCom */
  ComM_UserReqPncFullComStartIdxOfPncPbType UserReqPncFullComStartIdxOfPncPb;  /**< the start index of the 1:n relation pointing to ComM_UserReqPncFullCom */
} ComM_PncPbType;

/**   \brief  type used in ComM_PncSignal */
typedef struct sComM_PncSignalType
{
  ComM_ChannelIdxOfPncSignalType ChannelIdxOfPncSignal;  /**< the index of the 0:1 relation pointing to ComM_Channel */
  ComM_PncSignalValuesEndIdxOfPncSignalType PncSignalValuesEndIdxOfPncSignal;  /**< the end index of the 0:n relation pointing to ComM_PncSignalValues */
  ComM_PncSignalValuesStartIdxOfPncSignalType PncSignalValuesStartIdxOfPncSignal;  /**< the start index of the 0:n relation pointing to ComM_PncSignalValues */
  ComM_TypeOfPncSignalType TypeOfPncSignal;  /**< Partial network signal type */
} ComM_PncSignalType;

/**   \brief  type used in ComM_User */
typedef struct sComM_UserType
{
  ComM_PncUserOfUserType PncUserOfUser;  /**< decides if a user is a partial network user or a direct channel user */
  ComM_UserByteMaskEndIdxOfUserType UserByteMaskEndIdxOfUser;  /**< the end index of the 0:n relation pointing to ComM_UserByteMask */
  ComM_UserByteMaskStartIdxOfUserType UserByteMaskStartIdxOfUser;  /**< the start index of the 0:n relation pointing to ComM_UserByteMask */
  ComM_UserPncByteMaskEndIdxOfUserType UserPncByteMaskEndIdxOfUser;  /**< the end index of the 0:n relation pointing to ComM_UserPncByteMask */
  ComM_UserPncByteMaskLengthOfUserType UserPncByteMaskLengthOfUser;  /**< the number of relations pointing to ComM_UserPncByteMask */
  ComM_UserPncByteMaskStartIdxOfUserType UserPncByteMaskStartIdxOfUser;  /**< the start index of the 0:n relation pointing to ComM_UserPncByteMask */
} ComM_UserType;

/**   \brief  type used in ComM_UserByteMask */
typedef struct sComM_UserByteMaskType
{
  ComM_ChannelOfUserByteMaskType ChannelOfUserByteMask;  /**< ID of the channel which is requested by this entry. */
  ComM_ClearMaskOfUserByteMaskType ClearMaskOfUserByteMask;  /**< Clear-mask for clearing the bit which corresponds to this user */
  ComM_SetMaskOfUserByteMaskType SetMaskOfUserByteMask;  /**< Set-mask for setting the bit which corresponds to this user */
} ComM_UserByteMaskType;

/**   \brief  type used in ComM_UserPncByteMask */
typedef struct sComM_UserPncByteMaskType
{
  ComM_PncIDOfUserPncByteMaskType PncIDOfUserPncByteMask;  /**< System Id of the partial network which is requested by this entry */
  ComM_PncIdxOfUserPncByteMaskType PncIdxOfUserPncByteMask;  /**< the index of the 1:1 relation pointing to ComM_Pnc */
  ComM_UserReqPncFullComIdxOfUserPncByteMaskType UserReqPncFullComIdxOfUserPncByteMask;  /**< the index of the 1:1 relation pointing to ComM_UserReqPncFullCom */
} ComM_UserPncByteMaskType;

/** 
  \}
*/ 

/** 
  \defgroup  ComMPCSymbolicStructTypes  ComM Symbolic Struct Types (PRE_COMPILE)
  \brief  These structs are used in unions to have a symbol based data representation style.
  \{
*/ 
/**   \brief  type to be used as symbolic data element access to ComM_ActiveComMode in the predefined variant Left in the partition context  */
typedef struct ComM_ActiveComModeLeftStructSTag
{
  ComM_StateType ComMChannel_0;
  ComM_StateType ComMChannel_1;
} ComM_ActiveComModeLeftStructSType;

/**   \brief  type to be used as symbolic data element access to ComM_ActiveComMode in the predefined variant Right in the partition context  */
typedef struct ComM_ActiveComModeRightStructSTag
{
  ComM_StateType ComMChannel_0;
  ComM_StateType ComMChannel_1;
} ComM_ActiveComModeRightStructSType;

/**   \brief  type to be used as symbolic data element access to ComM_ActivePncComMode in the predefined variant Left in the partition context  */
typedef struct ComM_ActivePncComModeLeftStructSTag
{
  ComM_PncModeType PNC_00_MAPPING_b2c42696;
  ComM_PncModeType PNC_20_MAPPING_796df885;
} ComM_ActivePncComModeLeftStructSType;

/**   \brief  type to be used as symbolic data element access to ComM_ActivePncComMode in the predefined variant Right in the partition context  */
typedef struct ComM_ActivePncComModeRightStructSTag
{
  ComM_PncModeType PNC_00_MAPPING_b2c42696;
  ComM_PncModeType PNC_20_MAPPING_796df885;
} ComM_ActivePncComModeRightStructSType;

/**   \brief  type to be used as symbolic data element access to ComM_BusComModeReq in the predefined variant Left in the partition context  */
typedef struct ComM_BusComModeReqLeftStructSTag
{
  ComM_StateType ComMChannel_0;
  ComM_StateType ComMChannel_1;
} ComM_BusComModeReqLeftStructSType;

/**   \brief  type to be used as symbolic data element access to ComM_BusComModeReq in the predefined variant Right in the partition context  */
typedef struct ComM_BusComModeReqRightStructSTag
{
  ComM_StateType ComMChannel_0;
  ComM_StateType ComMChannel_1;
} ComM_BusComModeReqRightStructSType;

/**   \brief  type to be used as symbolic data element access to ComM_BusPncComModeReq in the predefined variant Left in the partition context  */
typedef struct ComM_BusPncComModeReqLeftStructSTag
{
  ComM_PncModeType PNC_00_MAPPING_b2c42696;
  ComM_PncModeType PNC_20_MAPPING_796df885;
} ComM_BusPncComModeReqLeftStructSType;

/**   \brief  type to be used as symbolic data element access to ComM_BusPncComModeReq in the predefined variant Right in the partition context  */
typedef struct ComM_BusPncComModeReqRightStructSTag
{
  ComM_PncModeType PNC_00_MAPPING_b2c42696;
  ComM_PncModeType PNC_20_MAPPING_796df885;
} ComM_BusPncComModeReqRightStructSType;

/**   \brief  type to be used as symbolic data element access to ComM_BusSmState in the predefined variant Left in the partition context  */
typedef struct ComM_BusSmStateLeftStructSTag
{
  ComM_ModeType ComMChannel_0;
  ComM_ModeType ComMChannel_1;
} ComM_BusSmStateLeftStructSType;

/**   \brief  type to be used as symbolic data element access to ComM_BusSmState in the predefined variant Right in the partition context  */
typedef struct ComM_BusSmStateRightStructSTag
{
  ComM_ModeType ComMChannel_0;
  ComM_ModeType ComMChannel_1;
} ComM_BusSmStateRightStructSType;

/**   \brief  type to be used as symbolic data element access to ComM_ComAllowed in the predefined variant Left in the partition context  */
typedef struct ComM_ComAllowedLeftStructSTag
{
  ComM_ComAllowedType ComMChannel_0;
  ComM_ComAllowedType ComMChannel_1;
} ComM_ComAllowedLeftStructSType;

/**   \brief  type to be used as symbolic data element access to ComM_ComAllowed in the predefined variant Right in the partition context  */
typedef struct ComM_ComAllowedRightStructSTag
{
  ComM_ComAllowedType ComMChannel_0;
  ComM_ComAllowedType ComMChannel_1;
} ComM_ComAllowedRightStructSType;

/**   \brief  type to be used as symbolic data element access to ComM_DcmRequestActive in the predefined variant Left in the partition context  */
typedef struct ComM_DcmRequestActiveLeftStructSTag
{
  ComM_DcmRequestActiveType ComMChannel_0;
  ComM_DcmRequestActiveType ComMChannel_1;
} ComM_DcmRequestActiveLeftStructSType;

/**   \brief  type to be used as symbolic data element access to ComM_DcmRequestActive in the predefined variant Right in the partition context  */
typedef struct ComM_DcmRequestActiveRightStructSTag
{
  ComM_DcmRequestActiveType ComMChannel_0;
  ComM_DcmRequestActiveType ComMChannel_1;
} ComM_DcmRequestActiveRightStructSType;

/**   \brief  type to be used as symbolic data element access to ComM_PncPSleepTimer in the predefined variant Left in the partition context  */
typedef struct ComM_PncPSleepTimerLeftStructSTag
{
  ComM_PncPSleepTimerType PNC_00_MAPPING_b2c42696;
  ComM_PncPSleepTimerType PNC_20_MAPPING_796df885;
} ComM_PncPSleepTimerLeftStructSType;

/**   \brief  type to be used as symbolic data element access to ComM_PncPSleepTimer in the predefined variant Right in the partition context  */
typedef struct ComM_PncPSleepTimerRightStructSTag
{
  ComM_PncPSleepTimerType PNC_00_MAPPING_b2c42696;
  ComM_PncPSleepTimerType PNC_20_MAPPING_796df885;
} ComM_PncPSleepTimerRightStructSType;

/**   \brief  type to be used as symbolic data element access to ComM_PncSignalValues in the predefined variant Left in the partition context  */
typedef struct ComM_PncSignalValuesLeftStructSTag
{
  ComM_PncSignalValuesType ComM_ComConf_ComSignal_NM_RBTM_FL_ST3_PNC_785a2d76_Tx[7];
  ComM_PncSignalValuesType ComM_ComConf_ComSignal_ComSignalPnc_EIRA_CAN_Rx[7];
} ComM_PncSignalValuesLeftStructSType;

/**   \brief  type to be used as symbolic data element access to ComM_PncSignalValues in the predefined variant Right in the partition context  */
typedef struct ComM_PncSignalValuesRightStructSTag
{
  ComM_PncSignalValuesType ComM_ComConf_ComSignal_ComSignalPnc_EIRA_CAN_Rx[7];
  ComM_PncSignalValuesType ComM_ComConf_ComSignal_NM_RBTM_FR_ST3_PNC_0103a546_Tx[7];
} ComM_PncSignalValuesRightStructSType;

/**   \brief  type to be used as symbolic data element access to ComM_PncToChannelRoutingState in the predefined variant Left in the partition context  */
typedef struct ComM_PncToChannelRoutingStateLeftStructSTag
{
  ComM_PncToChannelRoutingStateType ComMChannel_0;
  ComM_PncToChannelRoutingStateType ComMChannel_1;
} ComM_PncToChannelRoutingStateLeftStructSType;

/**   \brief  type to be used as symbolic data element access to ComM_PncToChannelRoutingState in the predefined variant Right in the partition context  */
typedef struct ComM_PncToChannelRoutingStateRightStructSTag
{
  ComM_PncToChannelRoutingStateType ComMChannel_0;
  ComM_PncToChannelRoutingStateType ComMChannel_1;
} ComM_PncToChannelRoutingStateRightStructSType;

/**   \brief  type to be used as symbolic data element access to ComM_ResetRequired in the predefined variant Left in the partition context  */
typedef struct ComM_ResetRequiredLeftStructSTag
{
  ComM_ResetRequiredType ComMChannel_0;
  ComM_ResetRequiredType ComMChannel_1;
} ComM_ResetRequiredLeftStructSType;

/**   \brief  type to be used as symbolic data element access to ComM_ResetRequired in the predefined variant Right in the partition context  */
typedef struct ComM_ResetRequiredRightStructSTag
{
  ComM_ResetRequiredType ComMChannel_0;
  ComM_ResetRequiredType ComMChannel_1;
} ComM_ResetRequiredRightStructSType;

/** 
  \}
*/ 

/** 
  \defgroup  ComMPCUnionIndexAndSymbolTypes  ComM Union Index And Symbol Types (PRE_COMPILE)
  \brief  These unions are used to access arrays in an index and symbol based style.
  \{
*/ 
/**   \brief  type to access ComM_ActiveComMode in an index and symbol based style. */
typedef union ComM_ActiveComModeUTag
{  /* PRQA S 0750 */  /* MD_CSL_Union */
  ComM_StateType raw[2];
  ComM_ActiveComModeLeftStructSType strLeft;
  ComM_ActiveComModeRightStructSType strRight;
} ComM_ActiveComModeUType;

/**   \brief  type to access ComM_ActivePncComMode in an index and symbol based style. */
typedef union ComM_ActivePncComModeUTag
{  /* PRQA S 0750 */  /* MD_CSL_Union */
  ComM_PncModeType raw[2];
  ComM_ActivePncComModeLeftStructSType strLeft;
  ComM_ActivePncComModeRightStructSType strRight;
} ComM_ActivePncComModeUType;

/**   \brief  type to access ComM_BusComModeReq in an index and symbol based style. */
typedef union ComM_BusComModeReqUTag
{  /* PRQA S 0750 */  /* MD_CSL_Union */
  ComM_StateType raw[2];
  ComM_BusComModeReqLeftStructSType strLeft;
  ComM_BusComModeReqRightStructSType strRight;
} ComM_BusComModeReqUType;

/**   \brief  type to access ComM_BusPncComModeReq in an index and symbol based style. */
typedef union ComM_BusPncComModeReqUTag
{  /* PRQA S 0750 */  /* MD_CSL_Union */
  ComM_PncModeType raw[2];
  ComM_BusPncComModeReqLeftStructSType strLeft;
  ComM_BusPncComModeReqRightStructSType strRight;
} ComM_BusPncComModeReqUType;

/**   \brief  type to access ComM_BusSmState in an index and symbol based style. */
typedef union ComM_BusSmStateUTag
{  /* PRQA S 0750 */  /* MD_CSL_Union */
  ComM_ModeType raw[2];
  ComM_BusSmStateLeftStructSType strLeft;
  ComM_BusSmStateRightStructSType strRight;
} ComM_BusSmStateUType;

/**   \brief  type to access ComM_ComAllowed in an index and symbol based style. */
typedef union ComM_ComAllowedUTag
{  /* PRQA S 0750 */  /* MD_CSL_Union */
  ComM_ComAllowedType raw[2];
  ComM_ComAllowedLeftStructSType strLeft;
  ComM_ComAllowedRightStructSType strRight;
} ComM_ComAllowedUType;

/**   \brief  type to access ComM_DcmRequestActive in an index and symbol based style. */
typedef union ComM_DcmRequestActiveUTag
{  /* PRQA S 0750 */  /* MD_CSL_Union */
  ComM_DcmRequestActiveType raw[2];
  ComM_DcmRequestActiveLeftStructSType strLeft;
  ComM_DcmRequestActiveRightStructSType strRight;
} ComM_DcmRequestActiveUType;

/**   \brief  type to access ComM_PncPSleepTimer in an index and symbol based style. */
typedef union ComM_PncPSleepTimerUTag
{  /* PRQA S 0750 */  /* MD_CSL_Union */
  ComM_PncPSleepTimerType raw[2];
  ComM_PncPSleepTimerLeftStructSType strLeft;
  ComM_PncPSleepTimerRightStructSType strRight;
} ComM_PncPSleepTimerUType;

/**   \brief  type to access ComM_PncSignalValues in an index and symbol based style. */
typedef union ComM_PncSignalValuesUTag
{  /* PRQA S 0750 */  /* MD_CSL_Union */
  ComM_PncSignalValuesType raw[14];
  ComM_PncSignalValuesLeftStructSType strLeft;
  ComM_PncSignalValuesRightStructSType strRight;
} ComM_PncSignalValuesUType;

/**   \brief  type to access ComM_PncToChannelRoutingState in an index and symbol based style. */
typedef union ComM_PncToChannelRoutingStateUTag
{  /* PRQA S 0750 */  /* MD_CSL_Union */
  ComM_PncToChannelRoutingStateType raw[2];
  ComM_PncToChannelRoutingStateLeftStructSType strLeft;
  ComM_PncToChannelRoutingStateRightStructSType strRight;
} ComM_PncToChannelRoutingStateUType;

/**   \brief  type to access ComM_ResetRequired in an index and symbol based style. */
typedef union ComM_ResetRequiredUTag
{  /* PRQA S 0750 */  /* MD_CSL_Union */
  ComM_ResetRequiredType raw[2];
  ComM_ResetRequiredLeftStructSType strLeft;
  ComM_ResetRequiredRightStructSType strRight;
} ComM_ResetRequiredUType;

/** 
  \}
*/ 

/** 
  \defgroup  ComMPCRootPointerTypes  ComM Root Pointer Types (PRE_COMPILE)
  \brief  These type definitions are used to point from the config root to symbol instances.
  \{
*/ 
/**   \brief  type used to point to ComM_ActiveComMode */
typedef P2VAR(ComM_StateType, TYPEDEF, COMM_VAR_NO_INIT) ComM_ActiveComModePtrType;

/**   \brief  type used to point to ComM_ActivePncComMode */
typedef P2VAR(ComM_PncModeType, TYPEDEF, COMM_VAR_NO_INIT) ComM_ActivePncComModePtrType;

/**   \brief  type used to point to ComM_BusComModeReq */
typedef P2VAR(ComM_StateType, TYPEDEF, COMM_VAR_NO_INIT) ComM_BusComModeReqPtrType;

/**   \brief  type used to point to ComM_BusPncComModeReq */
typedef P2VAR(ComM_PncModeType, TYPEDEF, COMM_VAR_NO_INIT) ComM_BusPncComModeReqPtrType;

/**   \brief  type used to point to ComM_BusSmState */
typedef P2VAR(ComM_ModeType, TYPEDEF, COMM_VAR_NO_INIT) ComM_BusSmStatePtrType;

/**   \brief  type used to point to ComM_Channel */
typedef P2CONST(ComM_ChannelType, TYPEDEF, COMM_CONST) ComM_ChannelPtrType;

/**   \brief  type used to point to ComM_ChannelPb */
typedef P2CONST(ComM_ChannelPbType, TYPEDEF, COMM_CONST) ComM_ChannelPbPtrType;

/**   \brief  type used to point to ComM_ComAllowed */
typedef P2VAR(ComM_ComAllowedType, TYPEDEF, COMM_VAR_NO_INIT) ComM_ComAllowedPtrType;

/**   \brief  type used to point to ComM_DcmRequestActive */
typedef P2VAR(ComM_DcmRequestActiveType, TYPEDEF, COMM_VAR_NO_INIT) ComM_DcmRequestActivePtrType;

/**   \brief  type used to point to ComM_EcuMWakeUpIndicated */
typedef P2VAR(volatile ComM_EcuMWakeUpIndicatedType, TYPEDEF, COMM_VAR_NO_INIT) ComM_EcuMWakeUpIndicatedPtrType;

/**   \brief  type used to point to ComM_EiraTxSignalIndirection */
typedef P2CONST(ComM_EiraTxSignalIndirectionType, TYPEDEF, COMM_CONST) ComM_EiraTxSignalIndirectionPtrType;

/**   \brief  type used to point to ComM_Inhibition */
typedef P2VAR(ComM_InhibitionType, TYPEDEF, COMM_NVM_DATA_NO_INIT) ComM_InhibitionPtrType;

/**   \brief  type used to point to ComM_InitStatus */
typedef P2VAR(ComM_InitStatusType, TYPEDEF, COMM_VAR_NO_INIT) ComM_InitStatusPtrType;

/**   \brief  type used to point to ComM_NmStartUpIndicated */
typedef P2VAR(volatile ComM_NmStartUpIndicatedType, TYPEDEF, COMM_VAR_NO_INIT) ComM_NmStartUpIndicatedPtrType;

/**   \brief  type used to point to ComM_PartitionIdentifiers */
typedef P2CONST(ComM_PartitionIdentifiersType, TYPEDEF, COMM_CONST) ComM_PartitionIdentifiersPtrType;

/**   \brief  type used to point to ComM_Pnc */
typedef P2CONST(ComM_PncType, TYPEDEF, COMM_CONST) ComM_PncPtrType;

/**   \brief  type used to point to ComM_PncChannelMapping */
typedef P2CONST(ComM_PncChannelMappingType, TYPEDEF, COMM_CONST) ComM_PncChannelMappingPtrType;

/**   \brief  type used to point to ComM_PncPSleepTimer */
typedef P2VAR(ComM_PncPSleepTimerType, TYPEDEF, COMM_VAR_NO_INIT) ComM_PncPSleepTimerPtrType;

/**   \brief  type used to point to ComM_PncPb */
typedef P2CONST(ComM_PncPbType, TYPEDEF, COMM_CONST) ComM_PncPbPtrType;

/**   \brief  type used to point to ComM_PncPbInd */
typedef P2CONST(ComM_PncPbIndType, TYPEDEF, COMM_CONST) ComM_PncPbIndPtrType;

/**   \brief  type used to point to ComM_PncSignal */
typedef P2CONST(ComM_PncSignalType, TYPEDEF, COMM_CONST) ComM_PncSignalPtrType;

/**   \brief  type used to point to ComM_PncSignalInd */
typedef P2CONST(ComM_PncSignalIndType, TYPEDEF, COMM_CONST) ComM_PncSignalIndPtrType;

/**   \brief  type used to point to ComM_PncSignalValues */
typedef P2VAR(ComM_PncSignalValuesType, TYPEDEF, COMM_VAR_NO_INIT) ComM_PncSignalValuesPtrType;

/**   \brief  type used to point to ComM_PncToChannelRoutingState */
typedef P2VAR(ComM_PncToChannelRoutingStateType, TYPEDEF, COMM_VAR_NO_INIT) ComM_PncToChannelRoutingStatePtrType;

/**   \brief  type used to point to ComM_PostInitialized */
typedef P2VAR(ComM_PostInitializedType, TYPEDEF, COMM_VAR_NO_INIT) ComM_PostInitializedPtrType;

/**   \brief  type used to point to ComM_ResetRequired */
typedef P2VAR(ComM_ResetRequiredType, TYPEDEF, COMM_VAR_NO_INIT) ComM_ResetRequiredPtrType;

/**   \brief  type used to point to ComM_User */
typedef P2CONST(ComM_UserType, TYPEDEF, COMM_CONST) ComM_UserPtrType;

/**   \brief  type used to point to ComM_UserByteMask */
typedef P2CONST(ComM_UserByteMaskType, TYPEDEF, COMM_CONST) ComM_UserByteMaskPtrType;

/**   \brief  type used to point to ComM_UserPncByteMask */
typedef P2CONST(ComM_UserPncByteMaskType, TYPEDEF, COMM_CONST) ComM_UserPncByteMaskPtrType;

/**   \brief  type used to point to ComM_UserReqFullCom */
typedef P2VAR(ComM_UserReqFullComType, TYPEDEF, COMM_VAR_NO_INIT) ComM_UserReqFullComPtrType;

/**   \brief  type used to point to ComM_UserReqPncFullCom */
typedef P2VAR(ComM_UserReqPncFullComType, TYPEDEF, COMM_VAR_NO_INIT) ComM_UserReqPncFullComPtrType;

/** 
  \}
*/ 

/** 
  \defgroup  ComMPCPartitionRootPointer  ComM Partition Root Pointer (PRE_COMPILE)
  \brief  This type definitions are used for partition specific instance.
  \{
*/ 
/**   \brief  type used in ComM_PCPartitionConfig */
typedef struct sComM_PCPartitionConfigType
{
  ComM_ChannelPtrType ChannelOfPCPartitionConfig;  /**< the pointer to ComM_Channel */
  ComM_ChannelPbPtrType ChannelPbOfPCPartitionConfig;  /**< the pointer to ComM_ChannelPb */
  ComM_PncChannelMappingPtrType PncChannelMappingOfPCPartitionConfig;  /**< the pointer to ComM_PncChannelMapping */
  ComM_PncSignalPtrType PncSignalOfPCPartitionConfig;  /**< the pointer to ComM_PncSignal */
  ComM_PncSignalIndPtrType PncSignalIndOfPCPartitionConfig;  /**< the pointer to ComM_PncSignalInd */
  ComM_UserByteMaskPtrType UserByteMaskOfPCPartitionConfig;  /**< the pointer to ComM_UserByteMask */
} ComM_PCPartitionConfigType;

/**   \brief  type used to point to ComM_PCPartitionConfig */
typedef P2CONST(ComM_PCPartitionConfigType, TYPEDEF, COMM_CONST) ComM_PCPartitionConfigPtrType;

/** 
  \}
*/ 

/** 
  \defgroup  ComMPCRootValueTypes  ComM Root Value Types (PRE_COMPILE)
  \brief  These type definitions are used for value representations in root arrays.
  \{
*/ 
/**   \brief  type used in ComM_PCConfig */
typedef struct sComM_PCConfigType
{
  ComM_PCPartitionConfigPtrType PCPartitionConfigOfPCConfig;  /**< the pointer to ComM_PCPartitionConfig */
} ComM_PCConfigType;

typedef ComM_PCConfigType ComM_ConfigType;  /**< A structure type is present for data in each configuration class. This typedef redefines the probably different name to the specified one. */

/**   \brief  type to access ComM_PCConfig in a symbol based style. */
typedef struct sComM_PCConfigsType
{
  ComM_PCConfigType Config_Left;  /**< [Config_Left] */
  ComM_PCConfigType Config_Right;  /**< [Config_Right] */
} ComM_PCConfigsType;

/** 
  \}
*/ 


/* PRQA S 0639, 0779 POSTBUILDGLOBALDATATYPES */ /* MD_MSR_1.1_639, MD_MSR_Rule5.2_0779 */
/**********************************************************************************************************************
  CONFIGURATION CLASS: POST_BUILD
  SECTION: GLOBAL COMPLEX DATA TYPES AND STRUCTURES
**********************************************************************************************************************/

/* PRQA L:POSTBUILDGLOBALDATATYPES */

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
**********************************************************************************************************************/
/* PRQA S 3451 EXTERNDECLARATIONS */ /* MD_ComM_3451_3449 */
/* PRQA S 3449 EXTERNALDECLARATIONS_3449 */ /* MD_ComM_3451_3449 */
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL DATA PROTOTYPES
**********************************************************************************************************************/
/**********************************************************************************************************************
  ComM_ChannelLeft
**********************************************************************************************************************/
/** 
  \var    ComM_ChannelLeft
  \brief  Contains PreCompile configuration parameters of channels
  \details
  Element                   Description
  Enabled                   Decides if the channel is enabled in the variant
  NmType                    The Network Management type of the channel
  GetCurrentBusSMModeApi    Query the current communication mode from the corresponding BusSM
  RequestBusSMModeApi       Request the communication mode from the corresponding BusSM
*/ 
#define COMM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(ComM_ChannelType, COMM_CONST) ComM_ChannelLeft[2];
#define COMM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  ComM_ChannelRight
**********************************************************************************************************************/
/** 
  \var    ComM_ChannelRight
  \brief  Contains PreCompile configuration parameters of channels
  \details
  Element                   Description
  Enabled                   Decides if the channel is enabled in the variant
  NmType                    The Network Management type of the channel
  GetCurrentBusSMModeApi    Query the current communication mode from the corresponding BusSM
  RequestBusSMModeApi       Request the communication mode from the corresponding BusSM
*/ 
#define COMM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(ComM_ChannelType, COMM_CONST) ComM_ChannelRight[2];
#define COMM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  ComM_ChannelPbLeft
**********************************************************************************************************************/
/** 
  \var    ComM_ChannelPbLeft
  \brief  Contains PostBuild configuration parameters of channels
  \details
  Element                   Description
  PncPbIndEndIdx            the end index of the 0:n relation pointing to ComM_PncPbInd
  PncPbIndStartIdx          the start index of the 0:n relation pointing to ComM_PncPbInd
  UserReqFullComEndIdx      the end index of the 0:n relation pointing to ComM_UserReqFullCom
  UserReqFullComStartIdx    the start index of the 0:n relation pointing to ComM_UserReqFullCom
*/ 
#define COMM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(ComM_ChannelPbType, COMM_CONST) ComM_ChannelPbLeft[2];
#define COMM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  ComM_ChannelPbRight
**********************************************************************************************************************/
/** 
  \var    ComM_ChannelPbRight
  \brief  Contains PostBuild configuration parameters of channels
  \details
  Element                   Description
  PncPbIndEndIdx            the end index of the 0:n relation pointing to ComM_PncPbInd
  PncPbIndStartIdx          the start index of the 0:n relation pointing to ComM_PncPbInd
  UserReqFullComEndIdx      the end index of the 0:n relation pointing to ComM_UserReqFullCom
  UserReqFullComStartIdx    the start index of the 0:n relation pointing to ComM_UserReqFullCom
*/ 
#define COMM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(ComM_ChannelPbType, COMM_CONST) ComM_ChannelPbRight[2];
#define COMM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  ComM_EiraTxSignalIndirection
**********************************************************************************************************************/
/** 
  \var    ComM_EiraTxSignalIndirection
  \brief  Indirection of internal signal id to the actual Eira Tx Symbolic Name Value
  \details
  Element              Description
  SymbolicNameValue    SymbolicNameValue of Tx Eira Signal
*/ 
#define COMM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(ComM_EiraTxSignalIndirectionType, COMM_CONST) ComM_EiraTxSignalIndirection[3];
#define COMM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  ComM_PartitionIdentifiers
**********************************************************************************************************************/
/** 
  \var    ComM_PartitionIdentifiers
  \brief  the partition context in Config_Left
  \details
  Element                 Description
  PartitionSNV        
  PCPartitionConfigIdx    the index of the 1:1 relation pointing to ComM_PCPartitionConfig
*/ 
#define COMM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(ComM_PartitionIdentifiersType, COMM_CONST) ComM_PartitionIdentifiers[1];
#define COMM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  ComM_Pnc
**********************************************************************************************************************/
/** 
  \var    ComM_Pnc
  \brief  Contains PreCompile configuration parameters of partial networks
  \details
  Element      Description
  ClearMask    Clear mask for the partial network related signals (EIRA, ERA)
  PncId        System ID of the partial network
  SetMask      Set mask for the partial network related signals (EIRA, ERA)
*/ 
#define COMM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(ComM_PncType, COMM_CONST) ComM_Pnc[2];
#define COMM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  ComM_PncChannelMappingLeft
**********************************************************************************************************************/
#define COMM_START_SEC_CONST_8
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(ComM_PncChannelMappingType, COMM_CONST) ComM_PncChannelMappingLeft[2];
#define COMM_STOP_SEC_CONST_8
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  ComM_PncChannelMappingRight
**********************************************************************************************************************/
#define COMM_START_SEC_CONST_8
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(ComM_PncChannelMappingType, COMM_CONST) ComM_PncChannelMappingRight[2];
#define COMM_STOP_SEC_CONST_8
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  ComM_PncPb
**********************************************************************************************************************/
/** 
  \var    ComM_PncPb
  \brief  Contains PostBuild configuration parameters of partial networks
  \details
  Element                      Description
  PncChannelMappingEndIdx      the end index of the 0:n relation pointing to ComM_PncChannelMapping
  PncChannelMappingStartIdx    the start index of the 0:n relation pointing to ComM_PncChannelMapping
  PncSignalIndEndIdx           the end index of the 0:n relation pointing to ComM_PncSignalInd
  PncSignalIndStartIdx         the start index of the 0:n relation pointing to ComM_PncSignalInd
  SignalByteIndex              Byte index in the partial network related signals (EIRA, ERA)
  UserReqPncFullComEndIdx      the end index of the 1:n relation pointing to ComM_UserReqPncFullCom
  UserReqPncFullComStartIdx    the start index of the 1:n relation pointing to ComM_UserReqPncFullCom
*/ 
#define COMM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(ComM_PncPbType, COMM_CONST) ComM_PncPb[2];
#define COMM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  ComM_PncPbInd
**********************************************************************************************************************/
/** 
  \var    ComM_PncPbInd
  \brief  the indexes of the 1:1 sorted relation pointing to ComM_PncPb
*/ 
#define COMM_START_SEC_CONST_8
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(ComM_PncPbIndType, COMM_CONST) ComM_PncPbInd[2];
#define COMM_STOP_SEC_CONST_8
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  ComM_PncSignalLeft
**********************************************************************************************************************/
/** 
  \var    ComM_PncSignalLeft
  \brief  Information about partial network signals (EIRA, ERA)
  \details
  Element                    Description
  ChannelIdx                 the index of the 0:1 relation pointing to ComM_Channel
  PncSignalValuesEndIdx      the end index of the 0:n relation pointing to ComM_PncSignalValues
  PncSignalValuesStartIdx    the start index of the 0:n relation pointing to ComM_PncSignalValues
  Type                       Partial network signal type
*/ 
#define COMM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(ComM_PncSignalType, COMM_CONST) ComM_PncSignalLeft[3];
#define COMM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  ComM_PncSignalRight
**********************************************************************************************************************/
/** 
  \var    ComM_PncSignalRight
  \brief  Information about partial network signals (EIRA, ERA)
  \details
  Element                    Description
  ChannelIdx                 the index of the 0:1 relation pointing to ComM_Channel
  PncSignalValuesEndIdx      the end index of the 0:n relation pointing to ComM_PncSignalValues
  PncSignalValuesStartIdx    the start index of the 0:n relation pointing to ComM_PncSignalValues
  Type                       Partial network signal type
*/ 
#define COMM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(ComM_PncSignalType, COMM_CONST) ComM_PncSignalRight[3];
#define COMM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  ComM_PncSignalIndLeft
**********************************************************************************************************************/
/** 
  \var    ComM_PncSignalIndLeft
  \brief  the indexes of the 1:1 sorted relation pointing to ComM_PncSignal
*/ 
#define COMM_START_SEC_CONST_8
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(ComM_PncSignalIndType, COMM_CONST) ComM_PncSignalIndLeft[2];
#define COMM_STOP_SEC_CONST_8
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  ComM_PncSignalIndRight
**********************************************************************************************************************/
/** 
  \var    ComM_PncSignalIndRight
  \brief  the indexes of the 1:1 sorted relation pointing to ComM_PncSignal
*/ 
#define COMM_START_SEC_CONST_8
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(ComM_PncSignalIndType, COMM_CONST) ComM_PncSignalIndRight[2];
#define COMM_STOP_SEC_CONST_8
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  ComM_User
**********************************************************************************************************************/
/** 
  \var    ComM_User
  \brief  Information about ComM users
  \details
  Element                    Description
  PncUser                    decides if a user is a partial network user or a direct channel user
  UserByteMaskEndIdx         the end index of the 0:n relation pointing to ComM_UserByteMask
  UserByteMaskStartIdx       the start index of the 0:n relation pointing to ComM_UserByteMask
  UserPncByteMaskEndIdx      the end index of the 0:n relation pointing to ComM_UserPncByteMask
  UserPncByteMaskLength      the number of relations pointing to ComM_UserPncByteMask
  UserPncByteMaskStartIdx    the start index of the 0:n relation pointing to ComM_UserPncByteMask
*/ 
#define COMM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(ComM_UserType, COMM_CONST) ComM_User[3];
#define COMM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  ComM_UserByteMaskLeft
**********************************************************************************************************************/
/** 
  \var    ComM_UserByteMaskLeft
  \brief  Each user has N entries in this array (N = # channels attached to this user, directly or through PNC). Each entry describes a Byte Position and a Mask for storing/clearing the user request in UserReqFullCom
  \details
  Element      Description
  Channel      ID of the channel which is requested by this entry.
  ClearMask    Clear-mask for clearing the bit which corresponds to this user
  SetMask      Set-mask for setting the bit which corresponds to this user
*/ 
#define COMM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(ComM_UserByteMaskType, COMM_CONST) ComM_UserByteMaskLeft[3];
#define COMM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  ComM_UserByteMaskRight
**********************************************************************************************************************/
/** 
  \var    ComM_UserByteMaskRight
  \brief  Each user has N entries in this array (N = # channels attached to this user, directly or through PNC). Each entry describes a Byte Position and a Mask for storing/clearing the user request in UserReqFullCom
  \details
  Element      Description
  Channel      ID of the channel which is requested by this entry.
  ClearMask    Clear-mask for clearing the bit which corresponds to this user
  SetMask      Set-mask for setting the bit which corresponds to this user
*/ 
#define COMM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(ComM_UserByteMaskType, COMM_CONST) ComM_UserByteMaskRight[3];
#define COMM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  ComM_UserPncByteMask
**********************************************************************************************************************/
/** 
  \var    ComM_UserPncByteMask
  \brief  Each partial network user has N entries in this array (N = # pncs attached to this user). Each entry describes a Byte Position and a Mask for storing/clearing the user request in UserReqPncFullCom
  \details
  Element                 Description
  PncID                   System Id of the partial network which is requested by this entry
  PncIdx                  the index of the 1:1 relation pointing to ComM_Pnc
  UserReqPncFullComIdx    the index of the 1:1 relation pointing to ComM_UserReqPncFullCom
*/ 
#define COMM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(ComM_UserPncByteMaskType, COMM_CONST) ComM_UserPncByteMask[2];
#define COMM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  ComM_ActiveComMode
**********************************************************************************************************************/
/** 
  \var    ComM_ActiveComMode
  \brief  Current state of a channel
*/ 
#define COMM_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(ComM_ActiveComModeUType, COMM_VAR_NO_INIT) ComM_ActiveComMode;  /* PRQA S 0759 */  /* MD_CSL_Union */
#define COMM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  ComM_ActivePncComMode
**********************************************************************************************************************/
/** 
  \var    ComM_ActivePncComMode
  \brief  stores the current partial network state
*/ 
#define COMM_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(ComM_ActivePncComModeUType, COMM_VAR_NO_INIT) ComM_ActivePncComMode;  /* PRQA S 0759 */  /* MD_CSL_Union */
#define COMM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  ComM_BusComModeReq
**********************************************************************************************************************/
/** 
  \var    ComM_BusComModeReq
  \brief  State requested externally (bus)
*/ 
#define COMM_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(ComM_BusComModeReqUType, COMM_VAR_NO_INIT) ComM_BusComModeReq;  /* PRQA S 0759 */  /* MD_CSL_Union */
#define COMM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  ComM_BusPncComModeReq
**********************************************************************************************************************/
/** 
  \var    ComM_BusPncComModeReq
  \brief  Stores the partial network state requested by external requests
*/ 
#define COMM_START_SEC_VAR_NO_INIT_8
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(ComM_BusPncComModeReqUType, COMM_VAR_NO_INIT) ComM_BusPncComModeReq;  /* PRQA S 0759 */  /* MD_CSL_Union */
#define COMM_STOP_SEC_VAR_NO_INIT_8
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  ComM_BusSmState
**********************************************************************************************************************/
/** 
  \var    ComM_BusSmState
  \brief  Communication state of a channel provided by BusSM
*/ 
#define COMM_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(ComM_BusSmStateUType, COMM_VAR_NO_INIT) ComM_BusSmState;  /* PRQA S 0759 */  /* MD_CSL_Union */
#define COMM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  ComM_ComAllowed
**********************************************************************************************************************/
/** 
  \var    ComM_ComAllowed
  \brief  Communication allowed status of a channel
*/ 
#define COMM_START_SEC_VAR_NO_INIT_8
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(ComM_ComAllowedUType, COMM_VAR_NO_INIT) ComM_ComAllowed;  /* PRQA S 0759 */  /* MD_CSL_Union */
#define COMM_STOP_SEC_VAR_NO_INIT_8
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  ComM_DcmRequestActive
**********************************************************************************************************************/
/** 
  \var    ComM_DcmRequestActive
  \brief  Status of Dcm active diagnostic request, TRUE if requested, FALSE otherwise
*/ 
#define COMM_START_SEC_VAR_NO_INIT_8
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(ComM_DcmRequestActiveUType, COMM_VAR_NO_INIT) ComM_DcmRequestActive;  /* PRQA S 0759 */  /* MD_CSL_Union */
#define COMM_STOP_SEC_VAR_NO_INIT_8
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  ComM_EcuMWakeUpIndicated
**********************************************************************************************************************/
/** 
  \var    ComM_EcuMWakeUpIndicated
  \brief  Passive Wakeup indicated by EcuM (ComM_EcuM_WakeUpIndication()). TRUE if indicated, FALSE otherwise.
*/ 
#define COMM_START_SEC_VAR_NOCACHE_NO_INIT_8
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern volatile VAR(ComM_EcuMWakeUpIndicatedType, COMM_VAR_NO_INIT) ComM_EcuMWakeUpIndicated[1];
#define COMM_STOP_SEC_VAR_NOCACHE_NO_INIT_8
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  ComM_Inhibition
**********************************************************************************************************************/
/** 
  \var    ComM_Inhibition
  \brief  Status of mode limitation (inhibition)
*/ 
#define COMM_START_SEC_VAR_SAVED_ZONE0_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(ComM_InhibitionType, COMM_NVM_DATA_NO_INIT) ComM_Inhibition;
#define COMM_STOP_SEC_VAR_SAVED_ZONE0_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  ComM_InitStatus
**********************************************************************************************************************/
/** 
  \var    ComM_InitStatus
  \brief  Initialization state of ComM
*/ 
#define COMM_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(ComM_InitStatusType, COMM_VAR_NO_INIT) ComM_InitStatus;
#define COMM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  ComM_NmStartUpIndicated
**********************************************************************************************************************/
/** 
  \var    ComM_NmStartUpIndicated
  \brief  Passive Wakeup indicated by Nm (ComM_Nm_NetworkStartIndication() or ComM_Nm_RestartIndication()). TRUE if indicated, FALSE otherwise.
*/ 
#define COMM_START_SEC_VAR_NOCACHE_NO_INIT_8
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern volatile VAR(ComM_NmStartUpIndicatedType, COMM_VAR_NO_INIT) ComM_NmStartUpIndicated[1];
#define COMM_STOP_SEC_VAR_NOCACHE_NO_INIT_8
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  ComM_PncPSleepTimer
**********************************************************************************************************************/
/** 
  \var    ComM_PncPSleepTimer
  \brief  partial network prepare sleep timer
*/ 
#define COMM_START_SEC_VAR_NO_INIT_16
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(ComM_PncPSleepTimerUType, COMM_VAR_NO_INIT) ComM_PncPSleepTimer;  /* PRQA S 0759 */  /* MD_CSL_Union */
#define COMM_STOP_SEC_VAR_NO_INIT_16
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  ComM_PncSignalValues
**********************************************************************************************************************/
#define COMM_START_SEC_VAR_NO_INIT_8
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(ComM_PncSignalValuesUType, COMM_VAR_NO_INIT) ComM_PncSignalValues;  /* PRQA S 0759 */  /* MD_CSL_Union */
#define COMM_STOP_SEC_VAR_NO_INIT_8
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  ComM_PncToChannelRoutingState
**********************************************************************************************************************/
/** 
  \var    ComM_PncToChannelRoutingState
  \brief  Bit flags describing the current PNC Routing state per channel
*/ 
#define COMM_START_SEC_VAR_NO_INIT_8
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(ComM_PncToChannelRoutingStateUType, COMM_VAR_NO_INIT) ComM_PncToChannelRoutingState;  /* PRQA S 0759 */  /* MD_CSL_Union */
#define COMM_STOP_SEC_VAR_NO_INIT_8
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  ComM_PostInitialized
**********************************************************************************************************************/
/** 
  \var    ComM_PostInitialized
  \brief  Post-Initialized state
*/ 
#define COMM_START_SEC_VAR_NO_INIT_8
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(ComM_PostInitializedType, COMM_VAR_NO_INIT) ComM_PostInitialized[1];
#define COMM_STOP_SEC_VAR_NO_INIT_8
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  ComM_ResetRequired
**********************************************************************************************************************/
/** 
  \var    ComM_ResetRequired
  \brief  TRUE if a reset has to be performed
*/ 
#define COMM_START_SEC_VAR_NO_INIT_8
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(ComM_ResetRequiredUType, COMM_VAR_NO_INIT) ComM_ResetRequired;  /* PRQA S 0759 */  /* MD_CSL_Union */
#define COMM_STOP_SEC_VAR_NO_INIT_8
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  ComM_UserReqFullCom
**********************************************************************************************************************/
/** 
  \var    ComM_UserReqFullCom
  \brief  RAM array used to store user requests for channels as bitmasks. Each channel 'owns' 1..n bytes in this array, depending on the number of users assigned to it.
*/ 
#define COMM_START_SEC_VAR_NO_INIT_8
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(ComM_UserReqFullComType, COMM_VAR_NO_INIT) ComM_UserReqFullCom[1];
#define COMM_STOP_SEC_VAR_NO_INIT_8
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  ComM_UserReqPncFullCom
**********************************************************************************************************************/
/** 
  \var    ComM_UserReqPncFullCom
  \brief  RAM array used to store user requests for PNCs as bitmasks. Each PNC 'owns' 1..n bytes in this array, depending on the number of users assigned to it.
*/ 
#define COMM_START_SEC_VAR_NO_INIT_8
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(ComM_UserReqPncFullComType, COMM_VAR_NO_INIT) ComM_UserReqPncFullCom[2];
#define COMM_STOP_SEC_VAR_NO_INIT_8
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  ComM_PCConfig
**********************************************************************************************************************/
/** 
  \var    ComM_PCConfig
  \details
  Element              Description
  PCPartitionConfig    the pointer to ComM_PCPartitionConfig
*/ 
#define COMM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(ComM_PCConfigsType, COMM_CONST) ComM_PCConfig;
#define COMM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  ComM_PCPartitionConfigLeft
**********************************************************************************************************************/
/** 
  \var    ComM_PCPartitionConfigLeft
  \details
  Element              Description
  Channel              the pointer to ComM_Channel
  ChannelPb            the pointer to ComM_ChannelPb
  PncChannelMapping    the pointer to ComM_PncChannelMapping
  PncSignal            the pointer to ComM_PncSignal
  PncSignalInd         the pointer to ComM_PncSignalInd
  UserByteMask         the pointer to ComM_UserByteMask
*/ 
#define COMM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(ComM_PCPartitionConfigType, COMM_CONST) ComM_PCPartitionConfigLeft[1];
#define COMM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  ComM_PCPartitionConfigRight
**********************************************************************************************************************/
/** 
  \var    ComM_PCPartitionConfigRight
  \details
  Element              Description
  Channel              the pointer to ComM_Channel
  ChannelPb            the pointer to ComM_ChannelPb
  PncChannelMapping    the pointer to ComM_PncChannelMapping
  PncSignal            the pointer to ComM_PncSignal
  PncSignalInd         the pointer to ComM_PncSignalInd
  UserByteMask         the pointer to ComM_UserByteMask
*/ 
#define COMM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(ComM_PCPartitionConfigType, COMM_CONST) ComM_PCPartitionConfigRight[1];
#define COMM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */



/**********************************************************************************************************************
  CONFIGURATION CLASS: POST_BUILD
  SECTION: GLOBAL DATA PROTOTYPES
**********************************************************************************************************************/

/* PRQA L:EXTERNALDECLARATIONS_3449 */
/* PRQA L:EXTERNDECLARATIONS */

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






#endif /* COMM_CFG_H */

