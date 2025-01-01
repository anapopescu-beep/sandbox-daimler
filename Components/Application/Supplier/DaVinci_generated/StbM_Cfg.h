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
 *            Module: StbM
 *           Program: MSR_Daimler_SLP11
 *          Customer: Mercedes-Benz AG
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: TC3xx
 *    License Scope : The usage is restricted to CBD2200333_D05
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: StbM_Cfg.h
 *   Generation Time: 2023-07-10 14:36:14
 *           Project: StartApplication - Version 1.0
 *          Delivery: CBD2200333_D05
 *      Tool Version: DaVinci Configurator Classic 5.25.50 SP5
 *
 *
 *********************************************************************************************************************/


#if !defined (STBM_CFG_H)
# define STBM_CFG_H

/**********************************************************************************************************************
 * MISRA JUSTIFICATION
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
# include "StbM_Types.h"
# include "Gpt.h"
# include "Os.h"
/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
/* General defines */
#ifndef STBM_USE_DUMMY_STATEMENT
#define STBM_USE_DUMMY_STATEMENT STD_OFF /* /MICROSAR/vSet/vSetGeneral/vSetDummyStatementKind */
#endif
#ifndef STBM_DUMMY_STATEMENT
#define STBM_DUMMY_STATEMENT(v)  /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */  /* /MICROSAR/vSet/vSetGeneral/vSetDummyStatementKind */
#endif
#ifndef STBM_DUMMY_STATEMENT_CONST
#define STBM_DUMMY_STATEMENT_CONST(v)  /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */  /* /MICROSAR/vSet/vSetGeneral/vSetDummyStatementKind */
#endif
#ifndef STBM_ATOMIC_BIT_ACCESS_IN_BITFIELD
#define STBM_ATOMIC_BIT_ACCESS_IN_BITFIELD STD_OFF /* /MICROSAR/EcuC/EcucGeneral/AtomicBitAccessInBitfield */
#endif
#ifndef STBM_ATOMIC_VARIABLE_ACCESS
#define STBM_ATOMIC_VARIABLE_ACCESS 32u /* /MICROSAR/EcuC/EcucGeneral/AtomicVariableAccess */
#endif
#ifndef STBM_PROCESSOR_TC322L
#define STBM_PROCESSOR_TC322L
#endif
#ifndef STBM_COMP_TASKING
#define STBM_COMP_TASKING
#endif
#ifndef STBM_GEN_GENERATOR_MSR
#define STBM_GEN_GENERATOR_MSR
#endif
#ifndef STBM_CPUTYPE_BITORDER_LSB2MSB
#define STBM_CPUTYPE_BITORDER_LSB2MSB /* /MICROSAR/vSet/vSetPlatform/vSetBitOrder */
#endif
#ifndef STBM_CONFIGURATION_VARIANT_PRECOMPILE
#define STBM_CONFIGURATION_VARIANT_PRECOMPILE 1
#endif
#ifndef STBM_CONFIGURATION_VARIANT_LINKTIME
#define STBM_CONFIGURATION_VARIANT_LINKTIME 2
#endif
#ifndef STBM_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE
#define STBM_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE 3
#endif
#ifndef STBM_CONFIGURATION_VARIANT
#define STBM_CONFIGURATION_VARIANT STBM_CONFIGURATION_VARIANT_PRECOMPILE
#endif
#ifndef STBM_POSTBUILD_VARIANT_SUPPORT
#define STBM_POSTBUILD_VARIANT_SUPPORT STD_OFF
#endif


/* Version identification */
# define STBM_CFG_MAJOR_VERSION                              (9u)
# define STBM_CFG_MINOR_VERSION                              (5u)

/* AUTOSAR version */
# define STBM_AR_MAJOR_VERSION                               (4u)
# define STBM_AR_MINOR_VERSION                               (3u)
# define STBM_AR_PATCH_VERSION                               (1u)

# define STBM_DEV_ERROR_DETECT                               (STD_ON)    /**< /ActiveEcuC/StbM/StbMGeneral[0:StbMSafeBswChecks] || /ActiveEcuC/StbM/StbMGeneral[0:StbMDevErrorDetect] */
# define STBM_DEV_ERROR_REPORT                               (STD_OFF) 
# define STBM_VERSION_INFO_API                               (STD_OFF)    /**< /ActiveEcuC/StbM/StbMGeneral[0:StbMVersionInfoApi] */
# define STBM_MAIN_FUNCTION_CYCLE                            (5u /*  ms  */ )    /**< /ActiveEcuC/StbM/StbMGeneral[0:StbMMainFunctionPeriod] */
# define STBM_GET_CURRENT_TIME_EXTENDED_API                  (STD_OFF) /**< Deactivateable: 'StbMGetCurrentTimeExtendedAvailable' Reason: the module configuration does not support extended timestamp */

/* Symbolic Name Values of TimeBases */
#define StbMConf_StbMSynchronizedTimeBase_GTD_BODY3_0_14e64f11 0u 

# define STBM_UNUSED_INDEX                                   (0xFFFFu)

# define STBM_HAS_MULTIPLE_TIMEBASE_CONFIGS                   (STD_OFF)
# define STBM_HAS_RUNTIME_CHECKING                            (STD_OFF)
# define STBM_HAS_ALLOW_SYSTEM_WIDE_GLOBAL_TIME_MASTER        (STD_OFF)

/* Multi-Core/Multi-Partition configuration */
/* STD_ON, if the partition index has to be used, STD_OFF otherwise */
# define STBM_PARTITIONINDEX_USED                             (STD_ON)

/* STD_ON, if more than one partition is used, STD_OFF otherwise */
# define STBM_MULTIPARTITION_USED                             (STD_ON)

/* Max value for partition index */
# define STBM_MAX_PARTITION_INDEX_VALUE                       (255u)

/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL CONSTANT MACROS
**********************************************************************************************************************/
/** 
  \defgroup  StbMPCDataSwitches  StbM Data Switches  (PRE_COMPILE)
  \brief  These defines are used to deactivate data and their processing.
  \{
*/ 
#define STBM_DEFERREDCLONEREQUESTSTATE                                                              STD_OFF  /**< Deactivateable: 'StbM_DeferredCloneRequestState' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' and Deactivateable: 'StbM_DeferredCloneRequestState' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define STBM_CLONECONFIGOFDEFERREDCLONEREQUESTSTATE                                                 STD_OFF  /**< Deactivateable: 'StbM_DeferredCloneRequestState.CloneConfig' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' and Deactivateable: 'StbM_DeferredCloneRequestState.CloneConfig' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define STBM_DESTINATIONTIMEBASEIDXOFDEFERREDCLONEREQUESTSTATE                                      STD_OFF  /**< Deactivateable: 'StbM_DeferredCloneRequestState.DestinationTimeBaseIdx' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' and Deactivateable: 'StbM_DeferredCloneRequestState.DestinationTimeBaseIdx' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define STBM_REQUESTVALIDOFDEFERREDCLONEREQUESTSTATE                                                STD_OFF  /**< Deactivateable: 'StbM_DeferredCloneRequestState.RequestValid' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' and Deactivateable: 'StbM_DeferredCloneRequestState.RequestValid' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define STBM_STATUSMASKOFDEFERREDCLONEREQUESTSTATE                                                  STD_OFF  /**< Deactivateable: 'StbM_DeferredCloneRequestState.StatusMask' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' and Deactivateable: 'StbM_DeferredCloneRequestState.StatusMask' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define STBM_STATUSVALUEOFDEFERREDCLONEREQUESTSTATE                                                 STD_OFF  /**< Deactivateable: 'StbM_DeferredCloneRequestState.StatusValue' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' and Deactivateable: 'StbM_DeferredCloneRequestState.StatusValue' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define STBM_ETHCLOCKCONFIG                                                                         STD_OFF  /**< Deactivateable: 'StbM_EthClockConfig' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'StbM_EthClockConfig' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define STBM_ETHIFCTRLIDXOFETHCLOCKCONFIG                                                           STD_OFF  /**< Deactivateable: 'StbM_EthClockConfig.EthIfCtrlIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'StbM_EthClockConfig.EthIfCtrlIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define STBM_FINALMAGICNUMBER                                                                       STD_OFF  /**< Deactivateable: 'StbM_FinalMagicNumber' Reason: 'the module configuration does not support flashing of data.' */
#define STBM_GPTCLOCKCONFIG                                                                         STD_ON
#define STBM_GPTCHANNELSYMBOLICNAMEOFGPTCLOCKCONFIG                                                 STD_ON
#define STBM_MAXTICKVALUEOFGPTCLOCKCONFIG                                                           STD_ON
#define STBM_GPTCLOCKSTATE                                                                          STD_ON
#define STBM_GPTCHANNELACTIVEOFGPTCLOCKSTATE                                                        STD_ON
#define STBM_INITDATAHASHCODE                                                                       STD_OFF  /**< Deactivateable: 'StbM_InitDataHashCode' Reason: 'the module configuration does not support flashing of data.' */
#define STBM_INITIALIZED                                                                            STD_ON
#define STBM_LOCALCLOCKCONFIG                                                                       STD_ON
#define STBM_CLOCKTYPEOFLOCALCLOCKCONFIG                                                            STD_ON
#define STBM_DENOMINATOROFFACTORCLOCKTICKSTOLOCALTIMEOFLOCALCLOCKCONFIG                             STD_ON
#define STBM_ETHCLOCKCONFIGIDXOFLOCALCLOCKCONFIG                                                    STD_OFF  /**< Deactivateable: 'StbM_LocalClockConfig.EthClockConfigIdx' Reason: 'the optional indirection is deactivated because EthClockConfigUsedOfLocalClockConfig is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' and Deactivateable: 'StbM_LocalClockConfig.EthClockConfigIdx' Reason: 'the optional indirection is deactivated because EthClockConfigUsedOfLocalClockConfig is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define STBM_ETHCLOCKCONFIGUSEDOFLOCALCLOCKCONFIG                                                   STD_OFF  /**< Deactivateable: 'StbM_LocalClockConfig.EthClockConfigUsed' Reason: 'the optional indirection is deactivated because EthClockConfigUsedOfLocalClockConfig is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' and Deactivateable: 'StbM_LocalClockConfig.EthClockConfigUsed' Reason: 'the optional indirection is deactivated because EthClockConfigUsedOfLocalClockConfig is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define STBM_GPTCLOCKCONFIGIDXOFLOCALCLOCKCONFIG                                                    STD_ON
#define STBM_GPTCLOCKCONFIGUSEDOFLOCALCLOCKCONFIG                                                   STD_ON
#define STBM_HWFREQUENCYOFLOCALCLOCKCONFIG                                                          STD_ON
#define STBM_HWPRESCALEROFLOCALCLOCKCONFIG                                                          STD_ON
#define STBM_NUMERATOROFFACTORCLOCKTICKSTOLOCALTIMEOFLOCALCLOCKCONFIG                               STD_ON
#define STBM_OSCLOCKCONFIGIDXOFLOCALCLOCKCONFIG                                                     STD_OFF  /**< Deactivateable: 'StbM_LocalClockConfig.OsClockConfigIdx' Reason: 'the optional indirection is deactivated because OsClockConfigUsedOfLocalClockConfig is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' and Deactivateable: 'StbM_LocalClockConfig.OsClockConfigIdx' Reason: 'the optional indirection is deactivated because OsClockConfigUsedOfLocalClockConfig is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define STBM_OSCLOCKCONFIGUSEDOFLOCALCLOCKCONFIG                                                    STD_OFF  /**< Deactivateable: 'StbM_LocalClockConfig.OsClockConfigUsed' Reason: 'the optional indirection is deactivated because OsClockConfigUsedOfLocalClockConfig is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' and Deactivateable: 'StbM_LocalClockConfig.OsClockConfigUsed' Reason: 'the optional indirection is deactivated because OsClockConfigUsedOfLocalClockConfig is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define STBM_TIMEBASEPARTITIONMAPPINGIDXOFLOCALCLOCKCONFIG                                          STD_ON
#define STBM_LOCALCLOCKSTATE                                                                        STD_ON
#define STBM_ELAPSEDTIMEOFLOCALCLOCKSTATE                                                           STD_ON
#define STBM_LASTREADTIMEOFLOCALCLOCKSTATE                                                          STD_ON
#define STBM_LOCALTIMECONFIG                                                                        STD_ON
#define STBM_LOCALCLOCKCONFIGIDXOFLOCALTIMECONFIG                                                   STD_ON
#define STBM_LOCALCLOCKCONFIGUSEDOFLOCALTIMECONFIG                                                  STD_ON
#define STBM_TIMEBASECONFIGIDXOFLOCALTIMECONFIG                                                     STD_ON
#define STBM_TIMEBASEPARTITIONMAPPINGIDXOFLOCALTIMECONFIG                                           STD_ON
#define STBM_LOCALTIMESTATE                                                                         STD_ON
#define STBM_LOCALTIMEOFLOCALTIMESTATE                                                              STD_ON
#define STBM_LOCALTIMEUPDATEDOFLOCALTIMESTATE                                                       STD_ON
#define STBM_MAINTIMESTATE                                                                          STD_ON
#define STBM_GLOBALTIMESYNCOFMAINTIMESTATE                                                          STD_ON
#define STBM_VIRTUALLOCALTIMESYNCOFMAINTIMESTATE                                                    STD_ON
#define STBM_OFFSETTIMERECORDINGBLOCK                                                               STD_OFF  /**< Deactivateable: 'StbM_OffsetTimeRecordingBlock' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' and Deactivateable: 'StbM_OffsetTimeRecordingBlock' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define STBM_GLBNANOSECONDSOFOFFSETTIMERECORDINGBLOCK                                               STD_OFF  /**< Deactivateable: 'StbM_OffsetTimeRecordingBlock.GlbNanoSeconds' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' and Deactivateable: 'StbM_OffsetTimeRecordingBlock.GlbNanoSeconds' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define STBM_GLBSECONDSOFOFFSETTIMERECORDINGBLOCK                                                   STD_OFF  /**< Deactivateable: 'StbM_OffsetTimeRecordingBlock.GlbSeconds' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' and Deactivateable: 'StbM_OffsetTimeRecordingBlock.GlbSeconds' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define STBM_TIMEBASESTATUSOFOFFSETTIMERECORDINGBLOCK                                               STD_OFF  /**< Deactivateable: 'StbM_OffsetTimeRecordingBlock.TimeBaseStatus' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' and Deactivateable: 'StbM_OffsetTimeRecordingBlock.TimeBaseStatus' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define STBM_OFFSETTIMERECORDINGHEADER                                                              STD_OFF  /**< Deactivateable: 'StbM_OffsetTimeRecordingHeader' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'StbM_OffsetTimeRecordingHeader' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define STBM_OFFSETTIMEDOMAINOFOFFSETTIMERECORDINGHEADER                                            STD_OFF  /**< Deactivateable: 'StbM_OffsetTimeRecordingHeader.OffsetTimeDomain' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'StbM_OffsetTimeRecordingHeader.OffsetTimeDomain' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define STBM_OSCLOCKCONFIG                                                                          STD_OFF  /**< Deactivateable: 'StbM_OsClockConfig' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'StbM_OsClockConfig' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define STBM_OSCOUNTERSYMBOLICNAMEOFOSCLOCKCONFIG                                                   STD_OFF  /**< Deactivateable: 'StbM_OsClockConfig.OsCounterSymbolicName' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'StbM_OsClockConfig.OsCounterSymbolicName' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define STBM_PARTITIONIDENTIFIERS                                                                   STD_ON
#define STBM_PCPARTITIONCONFIGIDXOFPARTITIONIDENTIFIERS                                             STD_ON
#define STBM_PARTITIONSNVOFPARTITIONIDENTIFIERS                                                     STD_ON
#define STBM_RATEMEASUREMENTS                                                                       STD_OFF  /**< Deactivateable: 'StbM_RateMeasurements' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' and Deactivateable: 'StbM_RateMeasurements' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define STBM_STARTGLOBALTIMEOFRATEMEASUREMENTS                                                      STD_OFF  /**< Deactivateable: 'StbM_RateMeasurements.StartGlobalTime' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' and Deactivateable: 'StbM_RateMeasurements.StartGlobalTime' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define STBM_STARTSTATUSOFRATEMEASUREMENTS                                                          STD_OFF  /**< Deactivateable: 'StbM_RateMeasurements.StartStatus' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' and Deactivateable: 'StbM_RateMeasurements.StartStatus' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define STBM_STARTVIRTUALLOCALTIMEOFRATEMEASUREMENTS                                                STD_OFF  /**< Deactivateable: 'StbM_RateMeasurements.StartVirtualLocalTime' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' and Deactivateable: 'StbM_RateMeasurements.StartVirtualLocalTime' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define STBM_STOPGLOBALTIMEOFRATEMEASUREMENTS                                                       STD_OFF  /**< Deactivateable: 'StbM_RateMeasurements.StopGlobalTime' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' and Deactivateable: 'StbM_RateMeasurements.StopGlobalTime' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define STBM_STOPVIRTUALLOCALTIMEOFRATEMEASUREMENTS                                                 STD_OFF  /**< Deactivateable: 'StbM_RateMeasurements.StopVirtualLocalTime' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' and Deactivateable: 'StbM_RateMeasurements.StopVirtualLocalTime' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define STBM_VALIDOFRATEMEASUREMENTS                                                                STD_OFF  /**< Deactivateable: 'StbM_RateMeasurements.Valid' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' and Deactivateable: 'StbM_RateMeasurements.Valid' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define STBM_RECEIVEDTIMESTATE                                                                      STD_ON
#define STBM_GLOBALTIMERXOFRECEIVEDTIMESTATE                                                        STD_ON
#define STBM_LOCALTIMESYNCOFRECEIVEDTIMESTATE                                                       STD_ON
#define STBM_VIRTUALLOCALTIMERXOFRECEIVEDTIMESTATE                                                  STD_ON
#define STBM_SIZEOFGPTCLOCKCONFIG                                                                   STD_ON
#define STBM_SIZEOFGPTCLOCKSTATE                                                                    STD_ON
#define STBM_SIZEOFLOCALCLOCKCONFIG                                                                 STD_ON
#define STBM_SIZEOFLOCALCLOCKSTATE                                                                  STD_ON
#define STBM_SIZEOFLOCALTIMECONFIG                                                                  STD_ON
#define STBM_SIZEOFLOCALTIMESTATE                                                                   STD_ON
#define STBM_SIZEOFMAINTIMESTATE                                                                    STD_ON
#define STBM_SIZEOFPARTITIONIDENTIFIERS                                                             STD_ON
#define STBM_SIZEOFRECEIVEDTIMESTATE                                                                STD_ON
#define STBM_SIZEOFSTATUS                                                                           STD_ON
#define STBM_SIZEOFSYNCTIMERECORDINGBLOCK                                                           STD_ON
#define STBM_SIZEOFSYNCTIMERECORDINGHEADER                                                          STD_ON
#define STBM_SIZEOFTIMEBASECONFIG                                                                   STD_ON
#define STBM_SIZEOFTIMEBASEPARTITIONMAPPING                                                         STD_ON
#define STBM_SIZEOFTIMEBASESTATE                                                                    STD_ON
#define STBM_SIZEOFTIMELEAPCLEARSTATE                                                               STD_ON
#define STBM_SIZEOFTIMELEAPCONFIG                                                                   STD_ON
#define STBM_SIZEOFTIMELEAPSTATE                                                                    STD_ON
#define STBM_SIZEOFTIMERECORDINGCONFIG                                                              STD_ON
#define STBM_SIZEOFTIMERECORDINGSTATE                                                               STD_ON
#define STBM_SIZEOFTIMERECORDINGSYNCCALLBACK                                                        STD_ON
#define STBM_SIZEOFTIMEOUTCONFIG                                                                    STD_ON
#define STBM_SIZEOFTIMEOUTSTATE                                                                     STD_ON
#define STBM_SIZEOFUSERDATASTATE                                                                    STD_ON
#define STBM_SIZEOFVIRTUALLOCALTIMESTATE                                                            STD_ON
#define STBM_STATUS                                                                                 STD_ON
#define STBM_GLOBALTIMESTATUSOFSTATUS                                                               STD_ON
#define STBM_LOCALTIMESTATUSOFSTATUS                                                                STD_ON
#define STBM_STATUSNOTIFICATIONCUSTOMERCALLBACK                                                     STD_OFF  /**< Deactivateable: 'StbM_StatusNotificationCustomerCallback' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'StbM_StatusNotificationCustomerCallback' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define STBM_CALLBACKOFSTATUSNOTIFICATIONCUSTOMERCALLBACK                                           STD_OFF  /**< Deactivateable: 'StbM_StatusNotificationCustomerCallback.Callback' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'StbM_StatusNotificationCustomerCallback.Callback' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define STBM_STATUSNOTIFICATIONCUSTOMERCONFIG                                                       STD_OFF  /**< Deactivateable: 'StbM_StatusNotificationCustomerConfig' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'StbM_StatusNotificationCustomerConfig' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define STBM_STATUSNOTIFICATIONCUSTOMERCALLBACKIDXOFSTATUSNOTIFICATIONCUSTOMERCONFIG                STD_OFF  /**< Deactivateable: 'StbM_StatusNotificationCustomerConfig.StatusNotificationCustomerCallbackIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'StbM_StatusNotificationCustomerConfig.StatusNotificationCustomerCallbackIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define STBM_STATUSNOTIFICATIONEVENTMASKOFSTATUSNOTIFICATIONCUSTOMERCONFIG                          STD_OFF  /**< Deactivateable: 'StbM_StatusNotificationCustomerConfig.StatusNotificationEventMask' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'StbM_StatusNotificationCustomerConfig.StatusNotificationEventMask' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define STBM_STATUSNOTIFICATIONSTATE                                                                STD_OFF  /**< Deactivateable: 'StbM_StatusNotificationState' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' and Deactivateable: 'StbM_StatusNotificationState' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define STBM_EVENTSOFSTATUSNOTIFICATIONSTATE                                                        STD_OFF  /**< Deactivateable: 'StbM_StatusNotificationState.Events' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' and Deactivateable: 'StbM_StatusNotificationState.Events' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define STBM_LASTSTATUSOFSTATUSNOTIFICATIONSTATE                                                    STD_OFF  /**< Deactivateable: 'StbM_StatusNotificationState.LastStatus' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' and Deactivateable: 'StbM_StatusNotificationState.LastStatus' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define STBM_SYNCTIMERECORDINGBLOCK                                                                 STD_ON
#define STBM_GLBNANOSECONDSOFSYNCTIMERECORDINGBLOCK                                                 STD_ON
#define STBM_GLBSECONDSOFSYNCTIMERECORDINGBLOCK                                                     STD_ON
#define STBM_LOCNANOSECONDSOFSYNCTIMERECORDINGBLOCK                                                 STD_ON
#define STBM_LOCSECONDSOFSYNCTIMERECORDINGBLOCK                                                     STD_ON
#define STBM_PATHDELAYOFSYNCTIMERECORDINGBLOCK                                                      STD_ON
#define STBM_RATEDEVIATIONOFSYNCTIMERECORDINGBLOCK                                                  STD_ON
#define STBM_TIMEBASESTATUSOFSYNCTIMERECORDINGBLOCK                                                 STD_ON
#define STBM_VIRTUALLOCALTIMELOWOFSYNCTIMERECORDINGBLOCK                                            STD_ON
#define STBM_SYNCTIMERECORDINGHEADER                                                                STD_ON
#define STBM_HWFREQUENCYOFSYNCTIMERECORDINGHEADER                                                   STD_ON
#define STBM_HWPRESCALEROFSYNCTIMERECORDINGHEADER                                                   STD_ON
#define STBM_TIMEDOMAINOFSYNCTIMERECORDINGHEADER                                                    STD_ON
#define STBM_TIMEBASECONFIG                                                                         STD_ON
#define STBM_DEFERREDCLONEREQUESTSTATEENDIDXOFTIMEBASECONFIG                                        STD_OFF  /**< Deactivateable: 'StbM_TimeBaseConfig.DeferredCloneRequestStateEndIdx' Reason: 'the optional indirection is deactivated because DeferredCloneRequestStateUsedOfTimeBaseConfig is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' and Deactivateable: 'StbM_TimeBaseConfig.DeferredCloneRequestStateEndIdx' Reason: 'the optional indirection is deactivated because DeferredCloneRequestStateUsedOfTimeBaseConfig is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define STBM_DEFERREDCLONEREQUESTSTATESTARTIDXOFTIMEBASECONFIG                                      STD_OFF  /**< Deactivateable: 'StbM_TimeBaseConfig.DeferredCloneRequestStateStartIdx' Reason: 'the optional indirection is deactivated because DeferredCloneRequestStateUsedOfTimeBaseConfig is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' and Deactivateable: 'StbM_TimeBaseConfig.DeferredCloneRequestStateStartIdx' Reason: 'the optional indirection is deactivated because DeferredCloneRequestStateUsedOfTimeBaseConfig is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define STBM_DEFERREDCLONEREQUESTSTATEUSEDOFTIMEBASECONFIG                                          STD_OFF  /**< Deactivateable: 'StbM_TimeBaseConfig.DeferredCloneRequestStateUsed' Reason: 'the optional indirection is deactivated because DeferredCloneRequestStateUsedOfTimeBaseConfig is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' and Deactivateable: 'StbM_TimeBaseConfig.DeferredCloneRequestStateUsed' Reason: 'the optional indirection is deactivated because DeferredCloneRequestStateUsedOfTimeBaseConfig is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define STBM_DIFFERENTLOCALCLOCKSOURCEFORCLONINGOFTIMEBASECONFIG                                    STD_OFF  /**< Deactivateable: 'StbM_TimeBaseConfig.DifferentLocalClockSourceForCloning' Reason: 'the array is deactivated because time base cloning is deactivated in all variants.' and Deactivateable: 'StbM_TimeBaseConfig.DifferentLocalClockSourceForCloning' Reason: 'the array is deactivated because time base cloning is deactivated in all variants.' */
#define STBM_GLOBALTIMEMASTEROFTIMEBASECONFIG                                                       STD_OFF  /**< Deactivateable: 'StbM_TimeBaseConfig.GlobalTimeMaster' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'StbM_TimeBaseConfig.GlobalTimeMaster' Reason: 'the value of StbM_GlobalTimeMasterOfTimeBaseConfig is always 'false' due to this, the array is deactivated.' */
#define STBM_LOCALTIMECONFIGIDXOFTIMEBASECONFIG                                                     STD_ON
#define STBM_PARTITIONCONFIGIDXOFTIMEBASECONFIG                                                     STD_ON
#define STBM_PURELOCALTIMEBASEOFTIMEBASECONFIG                                                      STD_OFF  /**< Deactivateable: 'StbM_TimeBaseConfig.PureLocalTimeBase' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'StbM_TimeBaseConfig.PureLocalTimeBase' Reason: 'the value of StbM_PureLocalTimeBaseOfTimeBaseConfig is always 'false' due to this, the array is deactivated.' */
#define STBM_STATUSIDXOFTIMEBASECONFIG                                                              STD_ON
#define STBM_STATUSNOTIFICATIONCUSTOMERCONFIGIDXOFTIMEBASECONFIG                                    STD_OFF  /**< Deactivateable: 'StbM_TimeBaseConfig.StatusNotificationCustomerConfigIdx' Reason: 'the optional indirection is deactivated because StatusNotificationCustomerConfigUsedOfTimeBaseConfig is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' and Deactivateable: 'StbM_TimeBaseConfig.StatusNotificationCustomerConfigIdx' Reason: 'the optional indirection is deactivated because StatusNotificationCustomerConfigUsedOfTimeBaseConfig is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define STBM_STATUSNOTIFICATIONCUSTOMERCONFIGUSEDOFTIMEBASECONFIG                                   STD_OFF  /**< Deactivateable: 'StbM_TimeBaseConfig.StatusNotificationCustomerConfigUsed' Reason: 'the optional indirection is deactivated because StatusNotificationCustomerConfigUsedOfTimeBaseConfig is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' and Deactivateable: 'StbM_TimeBaseConfig.StatusNotificationCustomerConfigUsed' Reason: 'the optional indirection is deactivated because StatusNotificationCustomerConfigUsedOfTimeBaseConfig is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define STBM_SYNCHRONIZEDTIMEBASEOFTIMEBASECONFIG                                                   STD_ON
#define STBM_TIMEBASEIDOFTIMEBASECONFIG                                                             STD_ON
#define STBM_TIMEBASEPARTITIONMAPPINGOFFSETIDXOFTIMEBASECONFIG                                      STD_OFF  /**< Deactivateable: 'StbM_TimeBaseConfig.TimeBasePartitionMappingOffsetIdx' Reason: 'the optional indirection is deactivated because TimeBasePartitionMappingOffsetUsedOfTimeBaseConfig is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' and Deactivateable: 'StbM_TimeBaseConfig.TimeBasePartitionMappingOffsetIdx' Reason: 'the optional indirection is deactivated because TimeBasePartitionMappingOffsetUsedOfTimeBaseConfig is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define STBM_TIMEBASEPARTITIONMAPPINGOFFSETUSEDOFTIMEBASECONFIG                                     STD_OFF  /**< Deactivateable: 'StbM_TimeBaseConfig.TimeBasePartitionMappingOffsetUsed' Reason: 'the optional indirection is deactivated because TimeBasePartitionMappingOffsetUsedOfTimeBaseConfig is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' and Deactivateable: 'StbM_TimeBaseConfig.TimeBasePartitionMappingOffsetUsed' Reason: 'the optional indirection is deactivated because TimeBasePartitionMappingOffsetUsedOfTimeBaseConfig is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define STBM_TIMEBASEPARTITIONMAPPINGSOURCEIDXOFTIMEBASECONFIG                                      STD_OFF  /**< Deactivateable: 'StbM_TimeBaseConfig.TimeBasePartitionMappingSourceIdx' Reason: 'the optional indirection is deactivated because TimeBasePartitionMappingSourceUsedOfTimeBaseConfig is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' and Deactivateable: 'StbM_TimeBaseConfig.TimeBasePartitionMappingSourceIdx' Reason: 'the optional indirection is deactivated because TimeBasePartitionMappingSourceUsedOfTimeBaseConfig is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define STBM_TIMEBASEPARTITIONMAPPINGSOURCEUSEDOFTIMEBASECONFIG                                     STD_OFF  /**< Deactivateable: 'StbM_TimeBaseConfig.TimeBasePartitionMappingSourceUsed' Reason: 'the optional indirection is deactivated because TimeBasePartitionMappingSourceUsedOfTimeBaseConfig is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' and Deactivateable: 'StbM_TimeBaseConfig.TimeBasePartitionMappingSourceUsed' Reason: 'the optional indirection is deactivated because TimeBasePartitionMappingSourceUsedOfTimeBaseConfig is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define STBM_TIMECORRECTIONMASTERCONFIGIDXOFTIMEBASECONFIG                                          STD_OFF  /**< Deactivateable: 'StbM_TimeBaseConfig.TimeCorrectionMasterConfigIdx' Reason: 'the optional indirection is deactivated because TimeCorrectionMasterConfigUsedOfTimeBaseConfig is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' and Deactivateable: 'StbM_TimeBaseConfig.TimeCorrectionMasterConfigIdx' Reason: 'the optional indirection is deactivated because TimeCorrectionMasterConfigUsedOfTimeBaseConfig is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define STBM_TIMECORRECTIONMASTERCONFIGUSEDOFTIMEBASECONFIG                                         STD_OFF  /**< Deactivateable: 'StbM_TimeBaseConfig.TimeCorrectionMasterConfigUsed' Reason: 'the optional indirection is deactivated because TimeCorrectionMasterConfigUsedOfTimeBaseConfig is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' and Deactivateable: 'StbM_TimeBaseConfig.TimeCorrectionMasterConfigUsed' Reason: 'the optional indirection is deactivated because TimeCorrectionMasterConfigUsedOfTimeBaseConfig is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define STBM_TIMECORRECTIONSLAVECONFIGIDXOFTIMEBASECONFIG                                           STD_OFF  /**< Deactivateable: 'StbM_TimeBaseConfig.TimeCorrectionSlaveConfigIdx' Reason: 'the optional indirection is deactivated because TimeCorrectionSlaveConfigUsedOfTimeBaseConfig is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' and Deactivateable: 'StbM_TimeBaseConfig.TimeCorrectionSlaveConfigIdx' Reason: 'the optional indirection is deactivated because TimeCorrectionSlaveConfigUsedOfTimeBaseConfig is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define STBM_TIMECORRECTIONSLAVECONFIGUSEDOFTIMEBASECONFIG                                          STD_OFF  /**< Deactivateable: 'StbM_TimeBaseConfig.TimeCorrectionSlaveConfigUsed' Reason: 'the optional indirection is deactivated because TimeCorrectionSlaveConfigUsedOfTimeBaseConfig is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' and Deactivateable: 'StbM_TimeBaseConfig.TimeCorrectionSlaveConfigUsed' Reason: 'the optional indirection is deactivated because TimeCorrectionSlaveConfigUsedOfTimeBaseConfig is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define STBM_TIMEGATEWAYOFTIMEBASECONFIG                                                            STD_OFF  /**< Deactivateable: 'StbM_TimeBaseConfig.TimeGateway' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'StbM_TimeBaseConfig.TimeGateway' Reason: 'the value of StbM_TimeGatewayOfTimeBaseConfig is always 'false' due to this, the array is deactivated.' */
#define STBM_TIMELEAPCONFIGIDXOFTIMEBASECONFIG                                                      STD_ON
#define STBM_TIMELEAPCONFIGUSEDOFTIMEBASECONFIG                                                     STD_ON
#define STBM_TIMERECORDINGCONFIGIDXOFTIMEBASECONFIG                                                 STD_ON
#define STBM_TIMERECORDINGCONFIGUSEDOFTIMEBASECONFIG                                                STD_ON
#define STBM_TIMESLAVEOFTIMEBASECONFIG                                                              STD_ON
#define STBM_TIMEVALIDATIONCONFIGIDXOFTIMEBASECONFIG                                                STD_OFF  /**< Deactivateable: 'StbM_TimeBaseConfig.TimeValidationConfigIdx' Reason: 'the optional indirection is deactivated because TimeValidationConfigUsedOfTimeBaseConfig is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' and Deactivateable: 'StbM_TimeBaseConfig.TimeValidationConfigIdx' Reason: 'the optional indirection is deactivated because TimeValidationConfigUsedOfTimeBaseConfig is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define STBM_TIMEVALIDATIONCONFIGUSEDOFTIMEBASECONFIG                                               STD_OFF  /**< Deactivateable: 'StbM_TimeBaseConfig.TimeValidationConfigUsed' Reason: 'the optional indirection is deactivated because TimeValidationConfigUsedOfTimeBaseConfig is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' and Deactivateable: 'StbM_TimeBaseConfig.TimeValidationConfigUsed' Reason: 'the optional indirection is deactivated because TimeValidationConfigUsedOfTimeBaseConfig is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define STBM_TIMEOUTCONFIGIDXOFTIMEBASECONFIG                                                       STD_ON
#define STBM_TIMEOUTCONFIGUSEDOFTIMEBASECONFIG                                                      STD_ON
#define STBM_TRIGGEREDCUSTOMERCONFIGENDIDXOFTIMEBASECONFIG                                          STD_OFF  /**< Deactivateable: 'StbM_TimeBaseConfig.TriggeredCustomerConfigEndIdx' Reason: 'the optional indirection is deactivated because TriggeredCustomerConfigUsedOfTimeBaseConfig is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' and Deactivateable: 'StbM_TimeBaseConfig.TriggeredCustomerConfigEndIdx' Reason: 'the optional indirection is deactivated because TriggeredCustomerConfigUsedOfTimeBaseConfig is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define STBM_TRIGGEREDCUSTOMERCONFIGSTARTIDXOFTIMEBASECONFIG                                        STD_OFF  /**< Deactivateable: 'StbM_TimeBaseConfig.TriggeredCustomerConfigStartIdx' Reason: 'the optional indirection is deactivated because TriggeredCustomerConfigUsedOfTimeBaseConfig is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' and Deactivateable: 'StbM_TimeBaseConfig.TriggeredCustomerConfigStartIdx' Reason: 'the optional indirection is deactivated because TriggeredCustomerConfigUsedOfTimeBaseConfig is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define STBM_TRIGGEREDCUSTOMERCONFIGUSEDOFTIMEBASECONFIG                                            STD_OFF  /**< Deactivateable: 'StbM_TimeBaseConfig.TriggeredCustomerConfigUsed' Reason: 'the optional indirection is deactivated because TriggeredCustomerConfigUsedOfTimeBaseConfig is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' and Deactivateable: 'StbM_TimeBaseConfig.TriggeredCustomerConfigUsed' Reason: 'the optional indirection is deactivated because TriggeredCustomerConfigUsedOfTimeBaseConfig is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define STBM_USERDATASTATEIDXOFTIMEBASECONFIG                                                       STD_ON
#define STBM_TIMEBASEPARTITIONMAPPING                                                               STD_ON
#define STBM_INDIRECTIONTOGPTCLOCKSTATEIDXOFTIMEBASEPARTITIONMAPPING                                STD_ON
#define STBM_INDIRECTIONTOGPTCLOCKSTATEPARTITIONIDXOFTIMEBASEPARTITIONMAPPING                       STD_ON
#define STBM_INDIRECTIONTOGPTCLOCKSTATEUSEDOFTIMEBASEPARTITIONMAPPING                               STD_ON
#define STBM_INDIRECTIONTOLOCALCLOCKSTATEIDXOFTIMEBASEPARTITIONMAPPING                              STD_ON
#define STBM_INDIRECTIONTOLOCALCLOCKSTATEPARTITIONIDXOFTIMEBASEPARTITIONMAPPING                     STD_ON
#define STBM_INDIRECTIONTOLOCALCLOCKSTATEUSEDOFTIMEBASEPARTITIONMAPPING                             STD_ON
#define STBM_INDIRECTIONTOLOCALTIMESTATEIDXOFTIMEBASEPARTITIONMAPPING                               STD_ON
#define STBM_INDIRECTIONTOLOCALTIMESTATEPARTITIONIDXOFTIMEBASEPARTITIONMAPPING                      STD_ON
#define STBM_INDIRECTIONTOMAINTIMESTATEIDXOFTIMEBASEPARTITIONMAPPING                                STD_ON
#define STBM_INDIRECTIONTOMAINTIMESTATEPARTITIONIDXOFTIMEBASEPARTITIONMAPPING                       STD_ON
#define STBM_INDIRECTIONTOTIMEBASECONFIGIDXOFTIMEBASEPARTITIONMAPPING                               STD_ON
#define STBM_INDIRECTIONTOTIMEBASECONFIGPARTITIONIDXOFTIMEBASEPARTITIONMAPPING                      STD_ON
#define STBM_INDIRECTIONTOTIMECORRECTIONOFFSETSLAVESTATEIDXOFTIMEBASEPARTITIONMAPPING               STD_OFF  /**< Deactivateable: 'StbM_TimeBasePartitionMapping.IndirectionToTimeCorrectionOffsetSlaveStateIdx' Reason: 'the optional indirection is deactivated because IndirectionToTimeCorrectionOffsetSlaveStateUsedOfTimeBasePartitionMapping is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define STBM_INDIRECTIONTOTIMECORRECTIONOFFSETSLAVESTATEPARTITIONIDXOFTIMEBASEPARTITIONMAPPING      STD_OFF  /**< Deactivateable: 'StbM_TimeBasePartitionMapping.IndirectionToTimeCorrectionOffsetSlaveStatePartitionIdx' Reason: 'the value of StbM_IndirectionToTimeCorrectionOffsetSlaveStatePartitionIdxOfTimeBasePartitionMapping is always 'STBM_NO_INDIRECTIONTOTIMECORRECTIONOFFSETSLAVESTATEPARTITIONIDXOFTIMEBASEPARTITIONMAPPING' due to this, the array is deactivated.' */
#define STBM_INDIRECTIONTOTIMECORRECTIONOFFSETSLAVESTATEUSEDOFTIMEBASEPARTITIONMAPPING              STD_OFF  /**< Deactivateable: 'StbM_TimeBasePartitionMapping.IndirectionToTimeCorrectionOffsetSlaveStateUsed' Reason: 'the optional indirection is deactivated because IndirectionToTimeCorrectionOffsetSlaveStateUsedOfTimeBasePartitionMapping is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define STBM_INDIRECTIONTOVIRTUALLOCALTIMESTATEIDXOFTIMEBASEPARTITIONMAPPING                        STD_ON
#define STBM_INDIRECTIONTOVIRTUALLOCALTIMESTATEPARTITIONIDXOFTIMEBASEPARTITIONMAPPING               STD_ON
#define STBM_TIMEBASESTATE                                                                          STD_ON
#define STBM_UPDATECOUNTEROFTIMEBASESTATE                                                           STD_ON
#define STBM_TIMECORRECTIONMASTERCONFIG                                                             STD_OFF  /**< Deactivateable: 'StbM_TimeCorrectionMasterConfig' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'StbM_TimeCorrectionMasterConfig' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define STBM_MAXRATEDEVIATIONOFTIMECORRECTIONMASTERCONFIG                                           STD_OFF  /**< Deactivateable: 'StbM_TimeCorrectionMasterConfig.MaxRateDeviation' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'StbM_TimeCorrectionMasterConfig.MaxRateDeviation' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define STBM_TIMECORRECTIONMASTERSTATE                                                              STD_OFF  /**< Deactivateable: 'StbM_TimeCorrectionMasterState' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' and Deactivateable: 'StbM_TimeCorrectionMasterState' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define STBM_RATECORRECTIONRATEOFTIMECORRECTIONMASTERSTATE                                          STD_OFF  /**< Deactivateable: 'StbM_TimeCorrectionMasterState.RateCorrectionRate' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' and Deactivateable: 'StbM_TimeCorrectionMasterState.RateCorrectionRate' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define STBM_RATEDEVIATIONVALIDOFTIMECORRECTIONMASTERSTATE                                          STD_OFF  /**< Deactivateable: 'StbM_TimeCorrectionMasterState.RateDeviationValid' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' and Deactivateable: 'StbM_TimeCorrectionMasterState.RateDeviationValid' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define STBM_TIMECORRECTIONOFFSETSLAVESTATE                                                         STD_OFF  /**< Deactivateable: 'StbM_TimeCorrectionOffsetSlaveState' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' and Deactivateable: 'StbM_TimeCorrectionOffsetSlaveState' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define STBM_OFFSETCORRECTIONRATEVALIDOFTIMECORRECTIONOFFSETSLAVESTATE                              STD_OFF  /**< Deactivateable: 'StbM_TimeCorrectionOffsetSlaveState.OffsetCorrectionRateValid' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' and Deactivateable: 'StbM_TimeCorrectionOffsetSlaveState.OffsetCorrectionRateValid' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define STBM_OFFSETRATECORRECTIONOFTIMECORRECTIONOFFSETSLAVESTATE                                   STD_OFF  /**< Deactivateable: 'StbM_TimeCorrectionOffsetSlaveState.OffsetRateCorrection' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' and Deactivateable: 'StbM_TimeCorrectionOffsetSlaveState.OffsetRateCorrection' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define STBM_TIMECORRECTIONSLAVECONFIG                                                              STD_OFF  /**< Deactivateable: 'StbM_TimeCorrectionSlaveConfig' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'StbM_TimeCorrectionSlaveConfig' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define STBM_NUMBEROFSIMULTANEOUSRATEMEASUREMENTSOFTIMECORRECTIONSLAVECONFIG                        STD_OFF  /**< Deactivateable: 'StbM_TimeCorrectionSlaveConfig.NumberOfSimultaneousRateMeasurements' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'StbM_TimeCorrectionSlaveConfig.NumberOfSimultaneousRateMeasurements' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define STBM_OFFSETCORRECTIONADAPTIONINTERVALOFTIMECORRECTIONSLAVECONFIG                            STD_OFF  /**< Deactivateable: 'StbM_TimeCorrectionSlaveConfig.OffsetCorrectionAdaptionInterval' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'StbM_TimeCorrectionSlaveConfig.OffsetCorrectionAdaptionInterval' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define STBM_OFFSETCORRECTIONJUMPTHRESHOLDOFTIMECORRECTIONSLAVECONFIG                               STD_OFF  /**< Deactivateable: 'StbM_TimeCorrectionSlaveConfig.OffsetCorrectionJumpThreshold' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'StbM_TimeCorrectionSlaveConfig.OffsetCorrectionJumpThreshold' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define STBM_RATECORRECTIONMEASUREMENTDURATIONNANOSECONDSHIOFTIMECORRECTIONSLAVECONFIG              STD_OFF  /**< Deactivateable: 'StbM_TimeCorrectionSlaveConfig.RateCorrectionMeasurementDurationNanosecondsHi' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'StbM_TimeCorrectionSlaveConfig.RateCorrectionMeasurementDurationNanosecondsHi' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define STBM_RATECORRECTIONMEASUREMENTDURATIONNANOSECONDSLOOFTIMECORRECTIONSLAVECONFIG              STD_OFF  /**< Deactivateable: 'StbM_TimeCorrectionSlaveConfig.RateCorrectionMeasurementDurationNanosecondsLo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'StbM_TimeCorrectionSlaveConfig.RateCorrectionMeasurementDurationNanosecondsLo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define STBM_RATEMEASUREMENTSENDIDXOFTIMECORRECTIONSLAVECONFIG                                      STD_OFF  /**< Deactivateable: 'StbM_TimeCorrectionSlaveConfig.RateMeasurementsEndIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'StbM_TimeCorrectionSlaveConfig.RateMeasurementsEndIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define STBM_RATEMEASUREMENTSSTARTIDXOFTIMECORRECTIONSLAVECONFIG                                    STD_OFF  /**< Deactivateable: 'StbM_TimeCorrectionSlaveConfig.RateMeasurementsStartIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'StbM_TimeCorrectionSlaveConfig.RateMeasurementsStartIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define STBM_SINGLERATECORRECTIONMEASUREMENTDURATIONNANOSECONDSHIOFTIMECORRECTIONSLAVECONFIG        STD_OFF  /**< Deactivateable: 'StbM_TimeCorrectionSlaveConfig.SingleRateCorrectionMeasurementDurationNanosecondsHi' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'StbM_TimeCorrectionSlaveConfig.SingleRateCorrectionMeasurementDurationNanosecondsHi' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define STBM_SINGLERATECORRECTIONMEASUREMENTDURATIONNANOSECONDSLOOFTIMECORRECTIONSLAVECONFIG        STD_OFF  /**< Deactivateable: 'StbM_TimeCorrectionSlaveConfig.SingleRateCorrectionMeasurementDurationNanosecondsLo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'StbM_TimeCorrectionSlaveConfig.SingleRateCorrectionMeasurementDurationNanosecondsLo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define STBM_TIMEBASEPARTITIONMAPPINGIDXOFTIMECORRECTIONSLAVECONFIG                                 STD_OFF  /**< Deactivateable: 'StbM_TimeCorrectionSlaveConfig.TimeBasePartitionMappingIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'StbM_TimeCorrectionSlaveConfig.TimeBasePartitionMappingIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define STBM_TIMECORRECTIONSLAVESTATE                                                               STD_OFF  /**< Deactivateable: 'StbM_TimeCorrectionSlaveState' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' and Deactivateable: 'StbM_TimeCorrectionSlaveState' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define STBM_RATECORRECTIONOFTIMECORRECTIONSLAVESTATE                                               STD_OFF  /**< Deactivateable: 'StbM_TimeCorrectionSlaveState.RateCorrection' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' and Deactivateable: 'StbM_TimeCorrectionSlaveState.RateCorrection' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define STBM_RATEDEVIATIONVALIDOFTIMECORRECTIONSLAVESTATE                                           STD_OFF  /**< Deactivateable: 'StbM_TimeCorrectionSlaveState.RateDeviationValid' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' and Deactivateable: 'StbM_TimeCorrectionSlaveState.RateDeviationValid' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define STBM_TIMELEAPCLEARSTATE                                                                     STD_ON
#define STBM_CLEARCOUNTFUTUREOFTIMELEAPCLEARSTATE                                                   STD_ON
#define STBM_CLEARCOUNTPASTOFTIMELEAPCLEARSTATE                                                     STD_ON
#define STBM_TIMELEAPCONFIG                                                                         STD_ON
#define STBM_CLEARCOUNTOFTIMELEAPCONFIG                                                             STD_ON
#define STBM_FUTURETHRESHOLDOFTIMELEAPCONFIG                                                        STD_ON
#define STBM_PASTTHRESHOLDOFTIMELEAPCONFIG                                                          STD_ON
#define STBM_TIMELEAPSTATE                                                                          STD_ON
#define STBM_TIMELEAPOFTIMELEAPSTATE                                                                STD_ON
#define STBM_TIMELEAPVALIDOFTIMELEAPSTATE                                                           STD_ON
#define STBM_TIMENOTIFICATIONCALLBACK                                                               STD_OFF  /**< Deactivateable: 'StbM_TimeNotificationCallback' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'StbM_TimeNotificationCallback' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define STBM_CALLBACKOFTIMENOTIFICATIONCALLBACK                                                     STD_OFF  /**< Deactivateable: 'StbM_TimeNotificationCallback.Callback' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'StbM_TimeNotificationCallback.Callback' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define STBM_TIMENOTIFICATIONCONFIG                                                                 STD_OFF  /**< Deactivateable: 'StbM_TimeNotificationConfig' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'StbM_TimeNotificationConfig' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define STBM_TIMEBASEPARTITIONMAPPINGIDXOFTIMENOTIFICATIONCONFIG                                    STD_OFF  /**< Deactivateable: 'StbM_TimeNotificationConfig.TimeBasePartitionMappingIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'StbM_TimeNotificationConfig.TimeBasePartitionMappingIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define STBM_TIMENOTIFICATIONCALLBACKIDXOFTIMENOTIFICATIONCONFIG                                    STD_OFF  /**< Deactivateable: 'StbM_TimeNotificationConfig.TimeNotificationCallbackIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'StbM_TimeNotificationConfig.TimeNotificationCallbackIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define STBM_TIMENOTIFICATIONPARTITIONMAPPINGIDXOFTIMENOTIFICATIONCONFIG                            STD_OFF  /**< Deactivateable: 'StbM_TimeNotificationConfig.TimeNotificationPartitionMappingIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'StbM_TimeNotificationConfig.TimeNotificationPartitionMappingIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define STBM_TIMERSTARTTHRESHOLDNANOSECONDSOFTIMENOTIFICATIONCONFIG                                 STD_OFF  /**< Deactivateable: 'StbM_TimeNotificationConfig.TimerStartThresholdNanoseconds' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'StbM_TimeNotificationConfig.TimerStartThresholdNanoseconds' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define STBM_TIMERSTARTTHRESHOLDSECONDSOFTIMENOTIFICATIONCONFIG                                     STD_OFF  /**< Deactivateable: 'StbM_TimeNotificationConfig.TimerStartThresholdSeconds' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'StbM_TimeNotificationConfig.TimerStartThresholdSeconds' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define STBM_TIMENOTIFICATIONPARTITIONMAPPING                                                       STD_OFF  /**< Deactivateable: 'StbM_TimeNotificationPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'StbM_TimeNotificationPartitionMapping' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define STBM_INDIRECTIONTOTIMENOTIFICATIONCONFIGIDXOFTIMENOTIFICATIONPARTITIONMAPPING               STD_OFF  /**< Deactivateable: 'StbM_TimeNotificationPartitionMapping.IndirectionToTimeNotificationConfigIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define STBM_INDIRECTIONTOTIMENOTIFICATIONCONFIGPARTITIONIDXOFTIMENOTIFICATIONPARTITIONMAPPING      STD_OFF  /**< Deactivateable: 'StbM_TimeNotificationPartitionMapping.IndirectionToTimeNotificationConfigPartitionIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define STBM_INDIRECTIONTOTIMENOTIFICATIONSTATEIDXOFTIMENOTIFICATIONPARTITIONMAPPING                STD_OFF  /**< Deactivateable: 'StbM_TimeNotificationPartitionMapping.IndirectionToTimeNotificationStateIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define STBM_INDIRECTIONTOTIMENOTIFICATIONSTATEPARTITIONIDXOFTIMENOTIFICATIONPARTITIONMAPPING       STD_OFF  /**< Deactivateable: 'StbM_TimeNotificationPartitionMapping.IndirectionToTimeNotificationStatePartitionIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define STBM_TIMENOTIFICATIONSTATE                                                                  STD_OFF  /**< Deactivateable: 'StbM_TimeNotificationState' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' and Deactivateable: 'StbM_TimeNotificationState' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define STBM_EXPIRETIMEOFTIMENOTIFICATIONSTATE                                                      STD_OFF  /**< Deactivateable: 'StbM_TimeNotificationState.ExpireTime' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' and Deactivateable: 'StbM_TimeNotificationState.ExpireTime' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define STBM_STARTTIMEOFTIMENOTIFICATIONSTATE                                                       STD_OFF  /**< Deactivateable: 'StbM_TimeNotificationState.StartTime' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' and Deactivateable: 'StbM_TimeNotificationState.StartTime' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define STBM_TIMERSTATEOFTIMENOTIFICATIONSTATE                                                      STD_OFF  /**< Deactivateable: 'StbM_TimeNotificationState.TimerState' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' and Deactivateable: 'StbM_TimeNotificationState.TimerState' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define STBM_TIMERECORDINGCONFIG                                                                    STD_ON
#define STBM_BLOCKCOUNTOFTIMERECORDINGCONFIG                                                        STD_ON
#define STBM_OFFSETTIMERECORDINGBLOCKENDIDXOFTIMERECORDINGCONFIG                                    STD_OFF  /**< Deactivateable: 'StbM_TimeRecordingConfig.OffsetTimeRecordingBlockEndIdx' Reason: 'the optional indirection is deactivated because OffsetTimeRecordingBlockUsedOfTimeRecordingConfig is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' and Deactivateable: 'StbM_TimeRecordingConfig.OffsetTimeRecordingBlockEndIdx' Reason: 'the optional indirection is deactivated because OffsetTimeRecordingBlockUsedOfTimeRecordingConfig is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define STBM_OFFSETTIMERECORDINGBLOCKSTARTIDXOFTIMERECORDINGCONFIG                                  STD_OFF  /**< Deactivateable: 'StbM_TimeRecordingConfig.OffsetTimeRecordingBlockStartIdx' Reason: 'the optional indirection is deactivated because OffsetTimeRecordingBlockUsedOfTimeRecordingConfig is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' and Deactivateable: 'StbM_TimeRecordingConfig.OffsetTimeRecordingBlockStartIdx' Reason: 'the optional indirection is deactivated because OffsetTimeRecordingBlockUsedOfTimeRecordingConfig is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define STBM_OFFSETTIMERECORDINGBLOCKUSEDOFTIMERECORDINGCONFIG                                      STD_OFF  /**< Deactivateable: 'StbM_TimeRecordingConfig.OffsetTimeRecordingBlockUsed' Reason: 'the optional indirection is deactivated because OffsetTimeRecordingBlockUsedOfTimeRecordingConfig is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' and Deactivateable: 'StbM_TimeRecordingConfig.OffsetTimeRecordingBlockUsed' Reason: 'the optional indirection is deactivated because OffsetTimeRecordingBlockUsedOfTimeRecordingConfig is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define STBM_OFFSETTIMERECORDINGHEADERIDXOFTIMERECORDINGCONFIG                                      STD_OFF  /**< Deactivateable: 'StbM_TimeRecordingConfig.OffsetTimeRecordingHeaderIdx' Reason: 'the optional indirection is deactivated because OffsetTimeRecordingHeaderUsedOfTimeRecordingConfig is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' and Deactivateable: 'StbM_TimeRecordingConfig.OffsetTimeRecordingHeaderIdx' Reason: 'the optional indirection is deactivated because OffsetTimeRecordingHeaderUsedOfTimeRecordingConfig is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define STBM_OFFSETTIMERECORDINGHEADERUSEDOFTIMERECORDINGCONFIG                                     STD_OFF  /**< Deactivateable: 'StbM_TimeRecordingConfig.OffsetTimeRecordingHeaderUsed' Reason: 'the optional indirection is deactivated because OffsetTimeRecordingHeaderUsedOfTimeRecordingConfig is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' and Deactivateable: 'StbM_TimeRecordingConfig.OffsetTimeRecordingHeaderUsed' Reason: 'the optional indirection is deactivated because OffsetTimeRecordingHeaderUsedOfTimeRecordingConfig is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define STBM_SYNCTIMERECORDINGBLOCKENDIDXOFTIMERECORDINGCONFIG                                      STD_ON
#define STBM_SYNCTIMERECORDINGBLOCKSTARTIDXOFTIMERECORDINGCONFIG                                    STD_ON
#define STBM_SYNCTIMERECORDINGBLOCKUSEDOFTIMERECORDINGCONFIG                                        STD_ON
#define STBM_SYNCTIMERECORDINGHEADERIDXOFTIMERECORDINGCONFIG                                        STD_ON
#define STBM_SYNCTIMERECORDINGHEADERUSEDOFTIMERECORDINGCONFIG                                       STD_ON
#define STBM_TIMEBASECONFIGIDXOFTIMERECORDINGCONFIG                                                 STD_ON
#define STBM_TIMEBASECONFIGUSEDOFTIMERECORDINGCONFIG                                                STD_ON
#define STBM_TIMERECORDINGOFFSETCALLBACKIDXOFTIMERECORDINGCONFIG                                    STD_OFF  /**< Deactivateable: 'StbM_TimeRecordingConfig.TimeRecordingOffsetCallbackIdx' Reason: 'the optional indirection is deactivated because TimeRecordingOffsetCallbackUsedOfTimeRecordingConfig is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' and Deactivateable: 'StbM_TimeRecordingConfig.TimeRecordingOffsetCallbackIdx' Reason: 'the optional indirection is deactivated because TimeRecordingOffsetCallbackUsedOfTimeRecordingConfig is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define STBM_TIMERECORDINGOFFSETCALLBACKUSEDOFTIMERECORDINGCONFIG                                   STD_OFF  /**< Deactivateable: 'StbM_TimeRecordingConfig.TimeRecordingOffsetCallbackUsed' Reason: 'the optional indirection is deactivated because TimeRecordingOffsetCallbackUsedOfTimeRecordingConfig is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' and Deactivateable: 'StbM_TimeRecordingConfig.TimeRecordingOffsetCallbackUsed' Reason: 'the optional indirection is deactivated because TimeRecordingOffsetCallbackUsedOfTimeRecordingConfig is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define STBM_TIMERECORDINGSYNCCALLBACKIDXOFTIMERECORDINGCONFIG                                      STD_ON
#define STBM_TIMERECORDINGSYNCCALLBACKUSEDOFTIMERECORDINGCONFIG                                     STD_ON
#define STBM_TIMERECORDINGOFFSETCALLBACK                                                            STD_OFF  /**< Deactivateable: 'StbM_TimeRecordingOffsetCallback' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'StbM_TimeRecordingOffsetCallback' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define STBM_CALLBACKOFTIMERECORDINGOFFSETCALLBACK                                                  STD_OFF  /**< Deactivateable: 'StbM_TimeRecordingOffsetCallback.Callback' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'StbM_TimeRecordingOffsetCallback.Callback' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define STBM_TIMERECORDINGSTATE                                                                     STD_ON
#define STBM_CURRENTBLOCKIDXOFTIMERECORDINGSTATE                                                    STD_ON
#define STBM_PATHDELAYOFTIMERECORDINGSTATE                                                          STD_ON
#define STBM_RECORDEDBLOCKSCOUNTOFTIMERECORDINGSTATE                                                STD_ON
#define STBM_TIMERECORDINGSYNCCALLBACK                                                              STD_ON
#define STBM_CALLBACKOFTIMERECORDINGSYNCCALLBACK                                                    STD_ON
#define STBM_TIMEVALIDATIONCONFIG                                                                   STD_OFF  /**< Deactivateable: 'StbM_TimeValidationConfig' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'StbM_TimeValidationConfig' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define STBM_BLOCKCOUNTOFTIMEVALIDATIONCONFIG                                                       STD_OFF  /**< Deactivateable: 'StbM_TimeValidationConfig.BlockCount' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'StbM_TimeValidationConfig.BlockCount' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define STBM_TIMEVALIDATIONETHMASTERCONFIGENDIDXOFTIMEVALIDATIONCONFIG                              STD_OFF  /**< Deactivateable: 'StbM_TimeValidationConfig.TimeValidationEthMasterConfigEndIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'StbM_TimeValidationConfig.TimeValidationEthMasterConfigEndIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define STBM_TIMEVALIDATIONETHMASTERCONFIGLENGTHOFTIMEVALIDATIONCONFIG                              STD_OFF  /**< Deactivateable: 'StbM_TimeValidationConfig.TimeValidationEthMasterConfigLength' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'StbM_TimeValidationConfig.TimeValidationEthMasterConfigLength' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define STBM_TIMEVALIDATIONETHMASTERCONFIGSTARTIDXOFTIMEVALIDATIONCONFIG                            STD_OFF  /**< Deactivateable: 'StbM_TimeValidationConfig.TimeValidationEthMasterConfigStartIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'StbM_TimeValidationConfig.TimeValidationEthMasterConfigStartIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define STBM_TIMEVALIDATIONETHMASTERCONFIGUSEDOFTIMEVALIDATIONCONFIG                                STD_OFF  /**< Deactivateable: 'StbM_TimeValidationConfig.TimeValidationEthMasterConfigUsed' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'StbM_TimeValidationConfig.TimeValidationEthMasterConfigUsed' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define STBM_TIMEVALIDATIONETHSLAVECONFIGIDXOFTIMEVALIDATIONCONFIG                                  STD_OFF  /**< Deactivateable: 'StbM_TimeValidationConfig.TimeValidationEthSlaveConfigIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'StbM_TimeValidationConfig.TimeValidationEthSlaveConfigIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define STBM_TIMEVALIDATIONETHSLAVECONFIGUSEDOFTIMEVALIDATIONCONFIG                                 STD_OFF  /**< Deactivateable: 'StbM_TimeValidationConfig.TimeValidationEthSlaveConfigUsed' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'StbM_TimeValidationConfig.TimeValidationEthSlaveConfigUsed' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define STBM_TIMEVALIDATIONETHMASTERBLOCKDATA                                                       STD_OFF  /**< Deactivateable: 'StbM_TimeValidationEthMasterBlockData' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' and Deactivateable: 'StbM_TimeValidationEthMasterBlockData' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define STBM_ETHMASTERTIMINGDATAOFTIMEVALIDATIONETHMASTERBLOCKDATA                                  STD_OFF  /**< Deactivateable: 'StbM_TimeValidationEthMasterBlockData.EthMasterTimingData' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' and Deactivateable: 'StbM_TimeValidationEthMasterBlockData.EthMasterTimingData' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define STBM_TIMEVALIDATIONETHMASTERCALLBACK                                                        STD_OFF  /**< Deactivateable: 'StbM_TimeValidationEthMasterCallback' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'StbM_TimeValidationEthMasterCallback' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define STBM_CALLBACKOFTIMEVALIDATIONETHMASTERCALLBACK                                              STD_OFF  /**< Deactivateable: 'StbM_TimeValidationEthMasterCallback.Callback' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'StbM_TimeValidationEthMasterCallback.Callback' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define STBM_TIMEVALIDATIONETHMASTERCONFIG                                                          STD_OFF  /**< Deactivateable: 'StbM_TimeValidationEthMasterConfig' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'StbM_TimeValidationEthMasterConfig' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define STBM_TIMEVALIDATIONCONFIGIDXOFTIMEVALIDATIONETHMASTERCONFIG                                 STD_OFF  /**< Deactivateable: 'StbM_TimeValidationEthMasterConfig.TimeValidationConfigIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'StbM_TimeValidationEthMasterConfig.TimeValidationConfigIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define STBM_TIMEVALIDATIONETHMASTERBLOCKDATAENDIDXOFTIMEVALIDATIONETHMASTERCONFIG                  STD_OFF  /**< Deactivateable: 'StbM_TimeValidationEthMasterConfig.TimeValidationEthMasterBlockDataEndIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'StbM_TimeValidationEthMasterConfig.TimeValidationEthMasterBlockDataEndIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define STBM_TIMEVALIDATIONETHMASTERBLOCKDATASTARTIDXOFTIMEVALIDATIONETHMASTERCONFIG                STD_OFF  /**< Deactivateable: 'StbM_TimeValidationEthMasterConfig.TimeValidationEthMasterBlockDataStartIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'StbM_TimeValidationEthMasterConfig.TimeValidationEthMasterBlockDataStartIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define STBM_TIMEVALIDATIONETHMASTERCALLBACKIDXOFTIMEVALIDATIONETHMASTERCONFIG                      STD_OFF  /**< Deactivateable: 'StbM_TimeValidationEthMasterConfig.TimeValidationEthMasterCallbackIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'StbM_TimeValidationEthMasterConfig.TimeValidationEthMasterCallbackIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define STBM_TIMEVALIDATIONETHPDELAYRESPONDERBLOCKDATAENDIDXOFTIMEVALIDATIONETHMASTERCONFIG         STD_OFF  /**< Deactivateable: 'StbM_TimeValidationEthMasterConfig.TimeValidationEthPdelayResponderBlockDataEndIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'StbM_TimeValidationEthMasterConfig.TimeValidationEthPdelayResponderBlockDataEndIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define STBM_TIMEVALIDATIONETHPDELAYRESPONDERBLOCKDATASTARTIDXOFTIMEVALIDATIONETHMASTERCONFIG       STD_OFF  /**< Deactivateable: 'StbM_TimeValidationEthMasterConfig.TimeValidationEthPdelayResponderBlockDataStartIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'StbM_TimeValidationEthMasterConfig.TimeValidationEthPdelayResponderBlockDataStartIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define STBM_TIMEVALIDATIONETHPDELAYRESPONDERCALLBACKIDXOFTIMEVALIDATIONETHMASTERCONFIG             STD_OFF  /**< Deactivateable: 'StbM_TimeValidationEthMasterConfig.TimeValidationEthPdelayResponderCallbackIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'StbM_TimeValidationEthMasterConfig.TimeValidationEthPdelayResponderCallbackIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define STBM_TIMEVALIDATIONETHMASTERIDENTIFICATION                                                  STD_OFF  /**< Deactivateable: 'StbM_TimeValidationEthMasterIdentification' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' and Deactivateable: 'StbM_TimeValidationEthMasterIdentification' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define STBM_PORTIDOFTIMEVALIDATIONETHMASTERIDENTIFICATION                                          STD_OFF  /**< Deactivateable: 'StbM_TimeValidationEthMasterIdentification.PortId' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' and Deactivateable: 'StbM_TimeValidationEthMasterIdentification.PortId' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define STBM_TIMEVALIDATIONETHMASTERSTATE                                                           STD_OFF  /**< Deactivateable: 'StbM_TimeValidationEthMasterState' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' and Deactivateable: 'StbM_TimeValidationEthMasterState' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define STBM_CURRENTBLOCKIDXOFTIMEVALIDATIONETHMASTERSTATE                                          STD_OFF  /**< Deactivateable: 'StbM_TimeValidationEthMasterState.CurrentBlockIdx' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' and Deactivateable: 'StbM_TimeValidationEthMasterState.CurrentBlockIdx' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define STBM_RECORDEDBLOCKSCOUNTOFTIMEVALIDATIONETHMASTERSTATE                                      STD_OFF  /**< Deactivateable: 'StbM_TimeValidationEthMasterState.RecordedBlocksCount' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' and Deactivateable: 'StbM_TimeValidationEthMasterState.RecordedBlocksCount' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define STBM_TIMEVALIDATIONETHPDELAYINITIATORBLOCKDATA                                              STD_OFF  /**< Deactivateable: 'StbM_TimeValidationEthPdelayInitiatorBlockData' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' and Deactivateable: 'StbM_TimeValidationEthPdelayInitiatorBlockData' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define STBM_ETHPDELAYINITIATORTIMINGDATAOFTIMEVALIDATIONETHPDELAYINITIATORBLOCKDATA                STD_OFF  /**< Deactivateable: 'StbM_TimeValidationEthPdelayInitiatorBlockData.EthPdelayInitiatorTimingData' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' and Deactivateable: 'StbM_TimeValidationEthPdelayInitiatorBlockData.EthPdelayInitiatorTimingData' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define STBM_TIMEVALIDATIONETHPDELAYINITIATORCALLBACK                                               STD_OFF  /**< Deactivateable: 'StbM_TimeValidationEthPdelayInitiatorCallback' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'StbM_TimeValidationEthPdelayInitiatorCallback' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define STBM_CALLBACKOFTIMEVALIDATIONETHPDELAYINITIATORCALLBACK                                     STD_OFF  /**< Deactivateable: 'StbM_TimeValidationEthPdelayInitiatorCallback.Callback' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'StbM_TimeValidationEthPdelayInitiatorCallback.Callback' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define STBM_TIMEVALIDATIONETHPDELAYINITIATORSTATE                                                  STD_OFF  /**< Deactivateable: 'StbM_TimeValidationEthPdelayInitiatorState' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' and Deactivateable: 'StbM_TimeValidationEthPdelayInitiatorState' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define STBM_CURRENTBLOCKIDXOFTIMEVALIDATIONETHPDELAYINITIATORSTATE                                 STD_OFF  /**< Deactivateable: 'StbM_TimeValidationEthPdelayInitiatorState.CurrentBlockIdx' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' and Deactivateable: 'StbM_TimeValidationEthPdelayInitiatorState.CurrentBlockIdx' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define STBM_RECORDEDBLOCKSCOUNTOFTIMEVALIDATIONETHPDELAYINITIATORSTATE                             STD_OFF  /**< Deactivateable: 'StbM_TimeValidationEthPdelayInitiatorState.RecordedBlocksCount' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' and Deactivateable: 'StbM_TimeValidationEthPdelayInitiatorState.RecordedBlocksCount' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define STBM_TIMEVALIDATIONETHPDELAYRESPONDERBLOCKDATA                                              STD_OFF  /**< Deactivateable: 'StbM_TimeValidationEthPdelayResponderBlockData' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' and Deactivateable: 'StbM_TimeValidationEthPdelayResponderBlockData' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define STBM_ETHPDELAYRESPONDERTIMINGDATAOFTIMEVALIDATIONETHPDELAYRESPONDERBLOCKDATA                STD_OFF  /**< Deactivateable: 'StbM_TimeValidationEthPdelayResponderBlockData.EthPdelayResponderTimingData' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' and Deactivateable: 'StbM_TimeValidationEthPdelayResponderBlockData.EthPdelayResponderTimingData' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define STBM_TIMEVALIDATIONETHPDELAYRESPONDERCALLBACK                                               STD_OFF  /**< Deactivateable: 'StbM_TimeValidationEthPdelayResponderCallback' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'StbM_TimeValidationEthPdelayResponderCallback' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define STBM_CALLBACKOFTIMEVALIDATIONETHPDELAYRESPONDERCALLBACK                                     STD_OFF  /**< Deactivateable: 'StbM_TimeValidationEthPdelayResponderCallback.Callback' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'StbM_TimeValidationEthPdelayResponderCallback.Callback' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define STBM_TIMEVALIDATIONETHPDELAYRESPONDERSTATE                                                  STD_OFF  /**< Deactivateable: 'StbM_TimeValidationEthPdelayResponderState' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' and Deactivateable: 'StbM_TimeValidationEthPdelayResponderState' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define STBM_CURRENTBLOCKIDXOFTIMEVALIDATIONETHPDELAYRESPONDERSTATE                                 STD_OFF  /**< Deactivateable: 'StbM_TimeValidationEthPdelayResponderState.CurrentBlockIdx' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' and Deactivateable: 'StbM_TimeValidationEthPdelayResponderState.CurrentBlockIdx' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define STBM_RECORDEDBLOCKSCOUNTOFTIMEVALIDATIONETHPDELAYRESPONDERSTATE                             STD_OFF  /**< Deactivateable: 'StbM_TimeValidationEthPdelayResponderState.RecordedBlocksCount' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' and Deactivateable: 'StbM_TimeValidationEthPdelayResponderState.RecordedBlocksCount' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define STBM_TIMEVALIDATIONETHSLAVEBLOCKDATA                                                        STD_OFF  /**< Deactivateable: 'StbM_TimeValidationEthSlaveBlockData' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' and Deactivateable: 'StbM_TimeValidationEthSlaveBlockData' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define STBM_ETHSLAVETIMINGDATAOFTIMEVALIDATIONETHSLAVEBLOCKDATA                                    STD_OFF  /**< Deactivateable: 'StbM_TimeValidationEthSlaveBlockData.EthSlaveTimingData' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' and Deactivateable: 'StbM_TimeValidationEthSlaveBlockData.EthSlaveTimingData' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define STBM_TIMEVALIDATIONETHSLAVECALLBACK                                                         STD_OFF  /**< Deactivateable: 'StbM_TimeValidationEthSlaveCallback' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'StbM_TimeValidationEthSlaveCallback' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define STBM_CALLBACKOFTIMEVALIDATIONETHSLAVECALLBACK                                               STD_OFF  /**< Deactivateable: 'StbM_TimeValidationEthSlaveCallback.Callback' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'StbM_TimeValidationEthSlaveCallback.Callback' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define STBM_TIMEVALIDATIONETHSLAVECONFIG                                                           STD_OFF  /**< Deactivateable: 'StbM_TimeValidationEthSlaveConfig' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'StbM_TimeValidationEthSlaveConfig' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define STBM_TIMEVALIDATIONCONFIGIDXOFTIMEVALIDATIONETHSLAVECONFIG                                  STD_OFF  /**< Deactivateable: 'StbM_TimeValidationEthSlaveConfig.TimeValidationConfigIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'StbM_TimeValidationEthSlaveConfig.TimeValidationConfigIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define STBM_TIMEVALIDATIONETHPDELAYINITIATORBLOCKDATAENDIDXOFTIMEVALIDATIONETHSLAVECONFIG          STD_OFF  /**< Deactivateable: 'StbM_TimeValidationEthSlaveConfig.TimeValidationEthPdelayInitiatorBlockDataEndIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'StbM_TimeValidationEthSlaveConfig.TimeValidationEthPdelayInitiatorBlockDataEndIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define STBM_TIMEVALIDATIONETHPDELAYINITIATORBLOCKDATASTARTIDXOFTIMEVALIDATIONETHSLAVECONFIG        STD_OFF  /**< Deactivateable: 'StbM_TimeValidationEthSlaveConfig.TimeValidationEthPdelayInitiatorBlockDataStartIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'StbM_TimeValidationEthSlaveConfig.TimeValidationEthPdelayInitiatorBlockDataStartIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define STBM_TIMEVALIDATIONETHPDELAYINITIATORCALLBACKIDXOFTIMEVALIDATIONETHSLAVECONFIG              STD_OFF  /**< Deactivateable: 'StbM_TimeValidationEthSlaveConfig.TimeValidationEthPdelayInitiatorCallbackIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'StbM_TimeValidationEthSlaveConfig.TimeValidationEthPdelayInitiatorCallbackIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define STBM_TIMEVALIDATIONETHSLAVEBLOCKDATAENDIDXOFTIMEVALIDATIONETHSLAVECONFIG                    STD_OFF  /**< Deactivateable: 'StbM_TimeValidationEthSlaveConfig.TimeValidationEthSlaveBlockDataEndIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'StbM_TimeValidationEthSlaveConfig.TimeValidationEthSlaveBlockDataEndIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define STBM_TIMEVALIDATIONETHSLAVEBLOCKDATASTARTIDXOFTIMEVALIDATIONETHSLAVECONFIG                  STD_OFF  /**< Deactivateable: 'StbM_TimeValidationEthSlaveConfig.TimeValidationEthSlaveBlockDataStartIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'StbM_TimeValidationEthSlaveConfig.TimeValidationEthSlaveBlockDataStartIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define STBM_TIMEVALIDATIONETHSLAVECALLBACKIDXOFTIMEVALIDATIONETHSLAVECONFIG                        STD_OFF  /**< Deactivateable: 'StbM_TimeValidationEthSlaveConfig.TimeValidationEthSlaveCallbackIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'StbM_TimeValidationEthSlaveConfig.TimeValidationEthSlaveCallbackIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define STBM_TIMEVALIDATIONETHSLAVESTATE                                                            STD_OFF  /**< Deactivateable: 'StbM_TimeValidationEthSlaveState' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' and Deactivateable: 'StbM_TimeValidationEthSlaveState' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define STBM_CURRENTBLOCKIDXOFTIMEVALIDATIONETHSLAVESTATE                                           STD_OFF  /**< Deactivateable: 'StbM_TimeValidationEthSlaveState.CurrentBlockIdx' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' and Deactivateable: 'StbM_TimeValidationEthSlaveState.CurrentBlockIdx' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define STBM_RECORDEDBLOCKSCOUNTOFTIMEVALIDATIONETHSLAVESTATE                                       STD_OFF  /**< Deactivateable: 'StbM_TimeValidationEthSlaveState.RecordedBlocksCount' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' and Deactivateable: 'StbM_TimeValidationEthSlaveState.RecordedBlocksCount' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define STBM_TIMEOUTCONFIG                                                                          STD_ON
#define STBM_SYNCLOSSTIMEOUTCOUNTEROFTIMEOUTCONFIG                                                  STD_ON
#define STBM_TIMEBASECONFIGIDXOFTIMEOUTCONFIG                                                       STD_ON
#define STBM_TIMEOUTSTATE                                                                           STD_ON
#define STBM_SYNCLOSSTIMEOUTCOUNTEROFTIMEOUTSTATE                                                   STD_ON
#define STBM_TRIGGEREDCUSTOMERCONFIG                                                                STD_OFF  /**< Deactivateable: 'StbM_TriggeredCustomerConfig' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'StbM_TriggeredCustomerConfig' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define STBM_SCHEDULETABLECOUNTERTICKSPERUSOFTRIGGEREDCUSTOMERCONFIG                                STD_OFF  /**< Deactivateable: 'StbM_TriggeredCustomerConfig.ScheduleTableCounterTicksPerUs' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'StbM_TriggeredCustomerConfig.ScheduleTableCounterTicksPerUs' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define STBM_SCHEDULETABLEDURATIONOFTRIGGEREDCUSTOMERCONFIG                                         STD_OFF  /**< Deactivateable: 'StbM_TriggeredCustomerConfig.ScheduleTableDuration' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'StbM_TriggeredCustomerConfig.ScheduleTableDuration' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define STBM_SCHEDULETABLEIDOFTRIGGEREDCUSTOMERCONFIG                                               STD_OFF  /**< Deactivateable: 'StbM_TriggeredCustomerConfig.ScheduleTableID' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'StbM_TriggeredCustomerConfig.ScheduleTableID' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define STBM_TIMEBASECONFIGIDXOFTRIGGEREDCUSTOMERCONFIG                                             STD_OFF  /**< Deactivateable: 'StbM_TriggeredCustomerConfig.TimeBaseConfigIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'StbM_TriggeredCustomerConfig.TimeBaseConfigIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define STBM_TRIGGEREDCUSTOMERPERIODOFTRIGGEREDCUSTOMERCONFIG                                       STD_OFF  /**< Deactivateable: 'StbM_TriggeredCustomerConfig.TriggeredCustomerPeriod' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'StbM_TriggeredCustomerConfig.TriggeredCustomerPeriod' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define STBM_TRIGGEREDCUSTOMERSTATE                                                                 STD_OFF  /**< Deactivateable: 'StbM_TriggeredCustomerState' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' and Deactivateable: 'StbM_TriggeredCustomerState' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define STBM_PERIODCOUNTEROFTRIGGEREDCUSTOMERSTATE                                                  STD_OFF  /**< Deactivateable: 'StbM_TriggeredCustomerState.PeriodCounter' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' and Deactivateable: 'StbM_TriggeredCustomerState.PeriodCounter' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define STBM_USERDATASTATE                                                                          STD_ON
#define STBM_USERDATAOFUSERDATASTATE                                                                STD_ON
#define STBM_VIRTUALLOCALTIMESTATE                                                                  STD_ON
#define STBM_VIRTUALLOCALTIMEELAPSEDAFTERADAPTIONINTERVALOFVIRTUALLOCALTIMESTATE                    STD_ON
#define STBM_VIRTUALLOCALTIMEOFVIRTUALLOCALTIMESTATE                                                STD_ON
#define STBM_PCCONFIG                                                                               STD_ON
#define STBM_FINALMAGICNUMBEROFPCCONFIG                                                             STD_OFF  /**< Deactivateable: 'StbM_PCConfig.FinalMagicNumber' Reason: 'the module configuration does not support flashing of data.' */
#define STBM_INITDATAHASHCODEOFPCCONFIG                                                             STD_OFF  /**< Deactivateable: 'StbM_PCConfig.InitDataHashCode' Reason: 'the module configuration does not support flashing of data.' */
#define STBM_PCPARTITIONCONFIGOFPCCONFIG                                                            STD_ON
#define STBM_PARTITIONIDENTIFIERSOFPCCONFIG                                                         STD_ON
#define STBM_SIZEOFPARTITIONIDENTIFIERSOFPCCONFIG                                                   STD_ON
#define STBM_PCPARTITIONCONFIG                                                                      STD_ON
#define STBM_GPTCLOCKCONFIGOFPCPARTITIONCONFIG                                                      STD_ON
#define STBM_GPTCLOCKSTATEOFPCPARTITIONCONFIG                                                       STD_ON
#define STBM_INITIALIZEDOFPCPARTITIONCONFIG                                                         STD_ON
#define STBM_LOCALCLOCKCONFIGOFPCPARTITIONCONFIG                                                    STD_ON
#define STBM_LOCALCLOCKSTATEOFPCPARTITIONCONFIG                                                     STD_ON
#define STBM_LOCALTIMECONFIGOFPCPARTITIONCONFIG                                                     STD_ON
#define STBM_LOCALTIMESTATEOFPCPARTITIONCONFIG                                                      STD_ON
#define STBM_MAINTIMESTATEOFPCPARTITIONCONFIG                                                       STD_ON
#define STBM_RECEIVEDTIMESTATEOFPCPARTITIONCONFIG                                                   STD_ON
#define STBM_SIZEOFGPTCLOCKCONFIGOFPCPARTITIONCONFIG                                                STD_ON
#define STBM_SIZEOFGPTCLOCKSTATEOFPCPARTITIONCONFIG                                                 STD_ON
#define STBM_SIZEOFLOCALCLOCKCONFIGOFPCPARTITIONCONFIG                                              STD_ON
#define STBM_SIZEOFLOCALCLOCKSTATEOFPCPARTITIONCONFIG                                               STD_ON
#define STBM_SIZEOFLOCALTIMECONFIGOFPCPARTITIONCONFIG                                               STD_ON
#define STBM_SIZEOFLOCALTIMESTATEOFPCPARTITIONCONFIG                                                STD_ON
#define STBM_SIZEOFMAINTIMESTATEOFPCPARTITIONCONFIG                                                 STD_ON
#define STBM_SIZEOFRECEIVEDTIMESTATEOFPCPARTITIONCONFIG                                             STD_ON
#define STBM_SIZEOFSTATUSOFPCPARTITIONCONFIG                                                        STD_ON
#define STBM_SIZEOFSYNCTIMERECORDINGBLOCKOFPCPARTITIONCONFIG                                        STD_ON
#define STBM_SIZEOFSYNCTIMERECORDINGHEADEROFPCPARTITIONCONFIG                                       STD_ON
#define STBM_SIZEOFTIMEBASECONFIGOFPCPARTITIONCONFIG                                                STD_ON
#define STBM_SIZEOFTIMEBASEPARTITIONMAPPINGOFPCPARTITIONCONFIG                                      STD_ON
#define STBM_SIZEOFTIMEBASESTATEOFPCPARTITIONCONFIG                                                 STD_ON
#define STBM_SIZEOFTIMELEAPCLEARSTATEOFPCPARTITIONCONFIG                                            STD_ON
#define STBM_SIZEOFTIMELEAPCONFIGOFPCPARTITIONCONFIG                                                STD_ON
#define STBM_SIZEOFTIMELEAPSTATEOFPCPARTITIONCONFIG                                                 STD_ON
#define STBM_SIZEOFTIMERECORDINGCONFIGOFPCPARTITIONCONFIG                                           STD_ON
#define STBM_SIZEOFTIMERECORDINGSTATEOFPCPARTITIONCONFIG                                            STD_ON
#define STBM_SIZEOFTIMERECORDINGSYNCCALLBACKOFPCPARTITIONCONFIG                                     STD_ON
#define STBM_SIZEOFTIMEOUTCONFIGOFPCPARTITIONCONFIG                                                 STD_ON
#define STBM_SIZEOFTIMEOUTSTATEOFPCPARTITIONCONFIG                                                  STD_ON
#define STBM_SIZEOFUSERDATASTATEOFPCPARTITIONCONFIG                                                 STD_ON
#define STBM_SIZEOFVIRTUALLOCALTIMESTATEOFPCPARTITIONCONFIG                                         STD_ON
#define STBM_STATUSOFPCPARTITIONCONFIG                                                              STD_ON
#define STBM_SYNCTIMERECORDINGBLOCKOFPCPARTITIONCONFIG                                              STD_ON
#define STBM_SYNCTIMERECORDINGHEADEROFPCPARTITIONCONFIG                                             STD_ON
#define STBM_TIMEBASECONFIGOFPCPARTITIONCONFIG                                                      STD_ON
#define STBM_TIMEBASEPARTITIONMAPPINGOFPCPARTITIONCONFIG                                            STD_ON
#define STBM_TIMEBASESTATEOFPCPARTITIONCONFIG                                                       STD_ON
#define STBM_TIMELEAPCLEARSTATEOFPCPARTITIONCONFIG                                                  STD_ON
#define STBM_TIMELEAPCONFIGOFPCPARTITIONCONFIG                                                      STD_ON
#define STBM_TIMELEAPSTATEOFPCPARTITIONCONFIG                                                       STD_ON
#define STBM_TIMERECORDINGCONFIGOFPCPARTITIONCONFIG                                                 STD_ON
#define STBM_TIMERECORDINGSTATEOFPCPARTITIONCONFIG                                                  STD_ON
#define STBM_TIMERECORDINGSYNCCALLBACKOFPCPARTITIONCONFIG                                           STD_ON
#define STBM_TIMEOUTCONFIGOFPCPARTITIONCONFIG                                                       STD_ON
#define STBM_TIMEOUTSTATEOFPCPARTITIONCONFIG                                                        STD_ON
#define STBM_USERDATASTATEOFPCPARTITIONCONFIG                                                       STD_ON
#define STBM_VIRTUALLOCALTIMESTATEOFPCPARTITIONCONFIG                                               STD_ON
/** 
  \}
*/ 

/** 
  \defgroup  StbMPCMinNumericValueDefines  StbM Min Numeric Value Defines (PRE_COMPILE)
  \brief  These defines are used to implement against the minimum value in numerical based data.
  \{
*/ 
#define STBM_MIN_LOCALTIMEUPDATEDOFLOCALTIMESTATE                                                   0u
#define STBM_MIN_GLBNANOSECONDSOFSYNCTIMERECORDINGBLOCK                                             0u
#define STBM_MIN_GLBSECONDSOFSYNCTIMERECORDINGBLOCK                                                 0u
#define STBM_MIN_LOCNANOSECONDSOFSYNCTIMERECORDINGBLOCK                                             0u
#define STBM_MIN_LOCSECONDSOFSYNCTIMERECORDINGBLOCK                                                 0u
#define STBM_MIN_PATHDELAYOFSYNCTIMERECORDINGBLOCK                                                  0u
#define STBM_MIN_TIMEBASESTATUSOFSYNCTIMERECORDINGBLOCK                                             0u
#define STBM_MIN_VIRTUALLOCALTIMELOWOFSYNCTIMERECORDINGBLOCK                                        0u
#define STBM_MIN_UPDATECOUNTEROFTIMEBASESTATE                                                       0u
#define STBM_MIN_CLEARCOUNTFUTUREOFTIMELEAPCLEARSTATE                                               0u
#define STBM_MIN_CLEARCOUNTPASTOFTIMELEAPCLEARSTATE                                                 0u
#define STBM_MIN_TIMELEAPOFTIMELEAPSTATE                                                            -2147483648
#define STBM_MIN_CURRENTBLOCKIDXOFTIMERECORDINGSTATE                                                0u
#define STBM_MIN_PATHDELAYOFTIMERECORDINGSTATE                                                      0u
#define STBM_MIN_RECORDEDBLOCKSCOUNTOFTIMERECORDINGSTATE                                            0u
#define STBM_MIN_SYNCLOSSTIMEOUTCOUNTEROFTIMEOUTSTATE                                               0u
/** 
  \}
*/ 

/** 
  \defgroup  StbMPCMaxNumericValueDefines  StbM Max Numeric Value Defines (PRE_COMPILE)
  \brief  These defines are used to implement against the maximum value in numerical based data.
  \{
*/ 
#define STBM_MAX_LOCALTIMEUPDATEDOFLOCALTIMESTATE                                                   255u
#define STBM_MAX_GLBNANOSECONDSOFSYNCTIMERECORDINGBLOCK                                             4294967295u
#define STBM_MAX_GLBSECONDSOFSYNCTIMERECORDINGBLOCK                                                 4294967295u
#define STBM_MAX_LOCNANOSECONDSOFSYNCTIMERECORDINGBLOCK                                             4294967295u
#define STBM_MAX_LOCSECONDSOFSYNCTIMERECORDINGBLOCK                                                 4294967295u
#define STBM_MAX_PATHDELAYOFSYNCTIMERECORDINGBLOCK                                                  4294967295u
#define STBM_MAX_TIMEBASESTATUSOFSYNCTIMERECORDINGBLOCK                                             255u
#define STBM_MAX_VIRTUALLOCALTIMELOWOFSYNCTIMERECORDINGBLOCK                                        4294967295u
#define STBM_MAX_UPDATECOUNTEROFTIMEBASESTATE                                                       255u
#define STBM_MAX_CLEARCOUNTFUTUREOFTIMELEAPCLEARSTATE                                               65535u
#define STBM_MAX_CLEARCOUNTPASTOFTIMELEAPCLEARSTATE                                                 65535u
#define STBM_MAX_TIMELEAPOFTIMELEAPSTATE                                                            2147483647
#define STBM_MAX_CURRENTBLOCKIDXOFTIMERECORDINGSTATE                                                4294967295u
#define STBM_MAX_PATHDELAYOFTIMERECORDINGSTATE                                                      4294967295u
#define STBM_MAX_RECORDEDBLOCKSCOUNTOFTIMERECORDINGSTATE                                            65535u
#define STBM_MAX_SYNCLOSSTIMEOUTCOUNTEROFTIMEOUTSTATE                                               4294967295u
/** 
  \}
*/ 

/** 
  \defgroup  StbMPCNoReferenceDefines  StbM No Reference Defines (PRE_COMPILE)
  \brief  These defines are used to indicate unused indexes in data relations.
  \{
*/ 
#define STBM_NO_GPTCLOCKCONFIGIDXOFLOCALCLOCKCONFIG                                                 255u
#define STBM_NO_LOCALCLOCKCONFIGIDXOFLOCALTIMECONFIG                                                255u
#define STBM_NO_TIMEBASEIDOFTIMEBASECONFIG                                                          255u
#define STBM_NO_TIMELEAPCONFIGIDXOFTIMEBASECONFIG                                                   255u
#define STBM_NO_TIMERECORDINGCONFIGIDXOFTIMEBASECONFIG                                              255u
#define STBM_NO_TIMEOUTCONFIGIDXOFTIMEBASECONFIG                                                    255u
#define STBM_NO_INDIRECTIONTOGPTCLOCKSTATEIDXOFTIMEBASEPARTITIONMAPPING                             255u
#define STBM_NO_INDIRECTIONTOGPTCLOCKSTATEPARTITIONIDXOFTIMEBASEPARTITIONMAPPING                    255u
#define STBM_NO_INDIRECTIONTOLOCALCLOCKSTATEIDXOFTIMEBASEPARTITIONMAPPING                           255u
#define STBM_NO_INDIRECTIONTOLOCALCLOCKSTATEPARTITIONIDXOFTIMEBASEPARTITIONMAPPING                  255u
#define STBM_NO_INDIRECTIONTOLOCALTIMESTATEPARTITIONIDXOFTIMEBASEPARTITIONMAPPING                   255u
#define STBM_NO_INDIRECTIONTOMAINTIMESTATEPARTITIONIDXOFTIMEBASEPARTITIONMAPPING                    255u
#define STBM_NO_INDIRECTIONTOTIMEBASECONFIGPARTITIONIDXOFTIMEBASEPARTITIONMAPPING                   255u
#define STBM_NO_INDIRECTIONTOVIRTUALLOCALTIMESTATEPARTITIONIDXOFTIMEBASEPARTITIONMAPPING            255u
#define STBM_NO_SYNCTIMERECORDINGBLOCKENDIDXOFTIMERECORDINGCONFIG                                   255u
#define STBM_NO_SYNCTIMERECORDINGBLOCKSTARTIDXOFTIMERECORDINGCONFIG                                 255u
#define STBM_NO_SYNCTIMERECORDINGHEADERIDXOFTIMERECORDINGCONFIG                                     255u
#define STBM_NO_TIMEBASECONFIGIDXOFTIMERECORDINGCONFIG                                              255u
#define STBM_NO_TIMERECORDINGSYNCCALLBACKIDXOFTIMERECORDINGCONFIG                                   255u
/** 
  \}
*/ 

/** 
  \defgroup  StbMPCEnumExistsDefines  StbM Enum Exists Defines (PRE_COMPILE)
  \brief  These defines can be used to deactivate enumeration based code sequences if the enumeration value does not exist in the configuration data.
  \{
*/ 
#define STBM_EXISTS_NONE_LOCALCLOCK_CLOCKTYPEOFLOCALCLOCKCONFIG                                     STD_OFF
#define STBM_EXISTS_OS_LOCALCLOCK_CLOCKTYPEOFLOCALCLOCKCONFIG                                       STD_OFF
#define STBM_EXISTS_GPT_LOCALCLOCK_CLOCKTYPEOFLOCALCLOCKCONFIG                                      STD_ON
#define STBM_EXISTS_ETH_LOCALCLOCK_CLOCKTYPEOFLOCALCLOCKCONFIG                                      STD_OFF
/** 
  \}
*/ 

/** 
  \defgroup  StbMPCEnumDefines  StbM Enum Defines (PRE_COMPILE)
  \brief  These defines are the enumeration values of enumeration based CONST and VAR data.
  \{
*/ 
#define STBM_GPT_LOCALCLOCK_CLOCKTYPEOFLOCALCLOCKCONFIG                                             0x02u
/** 
  \}
*/ 

/** 
  \defgroup  StbMPCIsReducedToDefineDefines  StbM Is Reduced To Define Defines (PRE_COMPILE)
  \brief  If all values in a CONST array or an element in a CONST array of structs are equal, the define is STD_ON else STD_OFF.
  \{
*/ 
#define STBM_ISDEF_GPTCHANNELSYMBOLICNAMEOFGPTCLOCKCONFIG                                           STD_OFF
#define STBM_ISDEF_MAXTICKVALUEOFGPTCLOCKCONFIG                                                     STD_OFF
#define STBM_ISDEF_CLOCKTYPEOFLOCALCLOCKCONFIG                                                      STD_OFF
#define STBM_ISDEF_DENOMINATOROFFACTORCLOCKTICKSTOLOCALTIMEOFLOCALCLOCKCONFIG                       STD_OFF
#define STBM_ISDEF_GPTCLOCKCONFIGIDXOFLOCALCLOCKCONFIG                                              STD_OFF
#define STBM_ISDEF_GPTCLOCKCONFIGUSEDOFLOCALCLOCKCONFIG                                             STD_OFF
#define STBM_ISDEF_HWFREQUENCYOFLOCALCLOCKCONFIG                                                    STD_OFF
#define STBM_ISDEF_HWPRESCALEROFLOCALCLOCKCONFIG                                                    STD_OFF
#define STBM_ISDEF_NUMERATOROFFACTORCLOCKTICKSTOLOCALTIMEOFLOCALCLOCKCONFIG                         STD_OFF
#define STBM_ISDEF_TIMEBASEPARTITIONMAPPINGIDXOFLOCALCLOCKCONFIG                                    STD_OFF
#define STBM_ISDEF_LOCALCLOCKCONFIGIDXOFLOCALTIMECONFIG                                             STD_OFF
#define STBM_ISDEF_LOCALCLOCKCONFIGUSEDOFLOCALTIMECONFIG                                            STD_OFF
#define STBM_ISDEF_TIMEBASECONFIGIDXOFLOCALTIMECONFIG                                               STD_OFF
#define STBM_ISDEF_TIMEBASEPARTITIONMAPPINGIDXOFLOCALTIMECONFIG                                     STD_OFF
#define STBM_ISDEF_PCPARTITIONCONFIGIDXOFPARTITIONIDENTIFIERS                                       STD_OFF
#define STBM_ISDEF_PARTITIONSNVOFPARTITIONIDENTIFIERS                                               STD_OFF
#define STBM_ISDEF_HWFREQUENCYOFSYNCTIMERECORDINGHEADER                                             STD_OFF
#define STBM_ISDEF_HWPRESCALEROFSYNCTIMERECORDINGHEADER                                             STD_OFF
#define STBM_ISDEF_TIMEDOMAINOFSYNCTIMERECORDINGHEADER                                              STD_OFF
#define STBM_ISDEF_LOCALTIMECONFIGIDXOFTIMEBASECONFIG                                               STD_OFF
#define STBM_ISDEF_PARTITIONCONFIGIDXOFTIMEBASECONFIG                                               STD_OFF
#define STBM_ISDEF_STATUSIDXOFTIMEBASECONFIG                                                        STD_OFF
#define STBM_ISDEF_SYNCHRONIZEDTIMEBASEOFTIMEBASECONFIG                                             STD_OFF
#define STBM_ISDEF_TIMEBASEIDOFTIMEBASECONFIG                                                       STD_OFF
#define STBM_ISDEF_TIMELEAPCONFIGIDXOFTIMEBASECONFIG                                                STD_OFF
#define STBM_ISDEF_TIMELEAPCONFIGUSEDOFTIMEBASECONFIG                                               STD_OFF
#define STBM_ISDEF_TIMERECORDINGCONFIGIDXOFTIMEBASECONFIG                                           STD_OFF
#define STBM_ISDEF_TIMERECORDINGCONFIGUSEDOFTIMEBASECONFIG                                          STD_OFF
#define STBM_ISDEF_TIMESLAVEOFTIMEBASECONFIG                                                        STD_OFF
#define STBM_ISDEF_TIMEOUTCONFIGIDXOFTIMEBASECONFIG                                                 STD_OFF
#define STBM_ISDEF_TIMEOUTCONFIGUSEDOFTIMEBASECONFIG                                                STD_OFF
#define STBM_ISDEF_USERDATASTATEIDXOFTIMEBASECONFIG                                                 STD_OFF
#define STBM_ISDEF_INDIRECTIONTOGPTCLOCKSTATEIDXOFTIMEBASEPARTITIONMAPPING                          STD_OFF
#define STBM_ISDEF_INDIRECTIONTOGPTCLOCKSTATEPARTITIONIDXOFTIMEBASEPARTITIONMAPPING                 STD_OFF
#define STBM_ISDEF_INDIRECTIONTOGPTCLOCKSTATEUSEDOFTIMEBASEPARTITIONMAPPING                         STD_OFF
#define STBM_ISDEF_INDIRECTIONTOLOCALCLOCKSTATEIDXOFTIMEBASEPARTITIONMAPPING                        STD_OFF
#define STBM_ISDEF_INDIRECTIONTOLOCALCLOCKSTATEPARTITIONIDXOFTIMEBASEPARTITIONMAPPING               STD_OFF
#define STBM_ISDEF_INDIRECTIONTOLOCALCLOCKSTATEUSEDOFTIMEBASEPARTITIONMAPPING                       STD_OFF
#define STBM_ISDEF_INDIRECTIONTOLOCALTIMESTATEIDXOFTIMEBASEPARTITIONMAPPING                         STD_OFF
#define STBM_ISDEF_INDIRECTIONTOLOCALTIMESTATEPARTITIONIDXOFTIMEBASEPARTITIONMAPPING                STD_OFF
#define STBM_ISDEF_INDIRECTIONTOMAINTIMESTATEIDXOFTIMEBASEPARTITIONMAPPING                          STD_OFF
#define STBM_ISDEF_INDIRECTIONTOMAINTIMESTATEPARTITIONIDXOFTIMEBASEPARTITIONMAPPING                 STD_OFF
#define STBM_ISDEF_INDIRECTIONTOTIMEBASECONFIGIDXOFTIMEBASEPARTITIONMAPPING                         STD_OFF
#define STBM_ISDEF_INDIRECTIONTOTIMEBASECONFIGPARTITIONIDXOFTIMEBASEPARTITIONMAPPING                STD_OFF
#define STBM_ISDEF_INDIRECTIONTOVIRTUALLOCALTIMESTATEIDXOFTIMEBASEPARTITIONMAPPING                  STD_OFF
#define STBM_ISDEF_INDIRECTIONTOVIRTUALLOCALTIMESTATEPARTITIONIDXOFTIMEBASEPARTITIONMAPPING         STD_OFF
#define STBM_ISDEF_CLEARCOUNTOFTIMELEAPCONFIG                                                       STD_OFF
#define STBM_ISDEF_FUTURETHRESHOLDOFTIMELEAPCONFIG                                                  STD_OFF
#define STBM_ISDEF_PASTTHRESHOLDOFTIMELEAPCONFIG                                                    STD_OFF
#define STBM_ISDEF_BLOCKCOUNTOFTIMERECORDINGCONFIG                                                  STD_OFF
#define STBM_ISDEF_SYNCTIMERECORDINGBLOCKENDIDXOFTIMERECORDINGCONFIG                                STD_OFF
#define STBM_ISDEF_SYNCTIMERECORDINGBLOCKSTARTIDXOFTIMERECORDINGCONFIG                              STD_OFF
#define STBM_ISDEF_SYNCTIMERECORDINGBLOCKUSEDOFTIMERECORDINGCONFIG                                  STD_OFF
#define STBM_ISDEF_SYNCTIMERECORDINGHEADERIDXOFTIMERECORDINGCONFIG                                  STD_OFF
#define STBM_ISDEF_SYNCTIMERECORDINGHEADERUSEDOFTIMERECORDINGCONFIG                                 STD_OFF
#define STBM_ISDEF_TIMEBASECONFIGIDXOFTIMERECORDINGCONFIG                                           STD_OFF
#define STBM_ISDEF_TIMEBASECONFIGUSEDOFTIMERECORDINGCONFIG                                          STD_OFF
#define STBM_ISDEF_TIMERECORDINGSYNCCALLBACKIDXOFTIMERECORDINGCONFIG                                STD_OFF
#define STBM_ISDEF_TIMERECORDINGSYNCCALLBACKUSEDOFTIMERECORDINGCONFIG                               STD_OFF
#define STBM_ISDEF_CALLBACKOFTIMERECORDINGSYNCCALLBACK                                              STD_OFF
#define STBM_ISDEF_SYNCLOSSTIMEOUTCOUNTEROFTIMEOUTCONFIG                                            STD_OFF
#define STBM_ISDEF_TIMEBASECONFIGIDXOFTIMEOUTCONFIG                                                 STD_OFF
#define STBM_ISDEF_PCPARTITIONCONFIGOFPCCONFIG                                                      STD_ON
#define STBM_ISDEF_PARTITIONIDENTIFIERSOFPCCONFIG                                                   STD_ON
#define STBM_ISDEF_GPTCLOCKCONFIGOFPCPARTITIONCONFIG                                                STD_OFF
#define STBM_ISDEF_GPTCLOCKSTATEOFPCPARTITIONCONFIG                                                 STD_OFF
#define STBM_ISDEF_INITIALIZEDOFPCPARTITIONCONFIG                                                   STD_OFF
#define STBM_ISDEF_LOCALCLOCKCONFIGOFPCPARTITIONCONFIG                                              STD_OFF
#define STBM_ISDEF_LOCALCLOCKSTATEOFPCPARTITIONCONFIG                                               STD_OFF
#define STBM_ISDEF_LOCALTIMECONFIGOFPCPARTITIONCONFIG                                               STD_OFF
#define STBM_ISDEF_LOCALTIMESTATEOFPCPARTITIONCONFIG                                                STD_OFF
#define STBM_ISDEF_MAINTIMESTATEOFPCPARTITIONCONFIG                                                 STD_OFF
#define STBM_ISDEF_RECEIVEDTIMESTATEOFPCPARTITIONCONFIG                                             STD_OFF
#define STBM_ISDEF_SIZEOFGPTCLOCKCONFIGOFPCPARTITIONCONFIG                                          STD_OFF
#define STBM_ISDEF_SIZEOFGPTCLOCKSTATEOFPCPARTITIONCONFIG                                           STD_OFF
#define STBM_ISDEF_SIZEOFLOCALCLOCKCONFIGOFPCPARTITIONCONFIG                                        STD_OFF
#define STBM_ISDEF_SIZEOFLOCALCLOCKSTATEOFPCPARTITIONCONFIG                                         STD_OFF
#define STBM_ISDEF_SIZEOFLOCALTIMECONFIGOFPCPARTITIONCONFIG                                         STD_OFF
#define STBM_ISDEF_SIZEOFLOCALTIMESTATEOFPCPARTITIONCONFIG                                          STD_OFF
#define STBM_ISDEF_SIZEOFMAINTIMESTATEOFPCPARTITIONCONFIG                                           STD_OFF
#define STBM_ISDEF_SIZEOFSYNCTIMERECORDINGBLOCKOFPCPARTITIONCONFIG                                  STD_OFF
#define STBM_ISDEF_SIZEOFSYNCTIMERECORDINGHEADEROFPCPARTITIONCONFIG                                 STD_OFF
#define STBM_ISDEF_SIZEOFTIMEBASECONFIGOFPCPARTITIONCONFIG                                          STD_OFF
#define STBM_ISDEF_SIZEOFTIMELEAPCONFIGOFPCPARTITIONCONFIG                                          STD_OFF
#define STBM_ISDEF_SIZEOFTIMERECORDINGCONFIGOFPCPARTITIONCONFIG                                     STD_OFF
#define STBM_ISDEF_SIZEOFTIMERECORDINGSYNCCALLBACKOFPCPARTITIONCONFIG                               STD_OFF
#define STBM_ISDEF_SIZEOFTIMEOUTCONFIGOFPCPARTITIONCONFIG                                           STD_OFF
#define STBM_ISDEF_SIZEOFUSERDATASTATEOFPCPARTITIONCONFIG                                           STD_OFF
#define STBM_ISDEF_SIZEOFVIRTUALLOCALTIMESTATEOFPCPARTITIONCONFIG                                   STD_OFF
#define STBM_ISDEF_STATUSOFPCPARTITIONCONFIG                                                        STD_OFF
#define STBM_ISDEF_SYNCTIMERECORDINGBLOCKOFPCPARTITIONCONFIG                                        STD_OFF
#define STBM_ISDEF_SYNCTIMERECORDINGHEADEROFPCPARTITIONCONFIG                                       STD_OFF
#define STBM_ISDEF_TIMEBASECONFIGOFPCPARTITIONCONFIG                                                STD_OFF
#define STBM_ISDEF_TIMEBASEPARTITIONMAPPINGOFPCPARTITIONCONFIG                                      STD_ON
#define STBM_ISDEF_TIMEBASESTATEOFPCPARTITIONCONFIG                                                 STD_OFF
#define STBM_ISDEF_TIMELEAPCLEARSTATEOFPCPARTITIONCONFIG                                            STD_OFF
#define STBM_ISDEF_TIMELEAPCONFIGOFPCPARTITIONCONFIG                                                STD_OFF
#define STBM_ISDEF_TIMELEAPSTATEOFPCPARTITIONCONFIG                                                 STD_OFF
#define STBM_ISDEF_TIMERECORDINGCONFIGOFPCPARTITIONCONFIG                                           STD_OFF
#define STBM_ISDEF_TIMERECORDINGSTATEOFPCPARTITIONCONFIG                                            STD_OFF
#define STBM_ISDEF_TIMERECORDINGSYNCCALLBACKOFPCPARTITIONCONFIG                                     STD_OFF
#define STBM_ISDEF_TIMEOUTCONFIGOFPCPARTITIONCONFIG                                                 STD_OFF
#define STBM_ISDEF_TIMEOUTSTATEOFPCPARTITIONCONFIG                                                  STD_OFF
#define STBM_ISDEF_USERDATASTATEOFPCPARTITIONCONFIG                                                 STD_OFF
#define STBM_ISDEF_VIRTUALLOCALTIMESTATEOFPCPARTITIONCONFIG                                         STD_OFF
/** 
  \}
*/ 

/** 
  \defgroup  StbMPCEqualsAlwaysToDefines  StbM Equals Always To Defines (PRE_COMPILE)
  \brief  If all values in a CONST array or an element in a CONST array of structs are equal, the define contains the always equals value.
  \{
*/ 
#define STBM_EQ2_GPTCHANNELSYMBOLICNAMEOFGPTCLOCKCONFIG                                             
#define STBM_EQ2_MAXTICKVALUEOFGPTCLOCKCONFIG                                                       
#define STBM_EQ2_CLOCKTYPEOFLOCALCLOCKCONFIG                                                        
#define STBM_EQ2_DENOMINATOROFFACTORCLOCKTICKSTOLOCALTIMEOFLOCALCLOCKCONFIG                         
#define STBM_EQ2_GPTCLOCKCONFIGIDXOFLOCALCLOCKCONFIG                                                
#define STBM_EQ2_GPTCLOCKCONFIGUSEDOFLOCALCLOCKCONFIG                                               
#define STBM_EQ2_HWFREQUENCYOFLOCALCLOCKCONFIG                                                      
#define STBM_EQ2_HWPRESCALEROFLOCALCLOCKCONFIG                                                      
#define STBM_EQ2_NUMERATOROFFACTORCLOCKTICKSTOLOCALTIMEOFLOCALCLOCKCONFIG                           
#define STBM_EQ2_TIMEBASEPARTITIONMAPPINGIDXOFLOCALCLOCKCONFIG                                      
#define STBM_EQ2_LOCALCLOCKCONFIGIDXOFLOCALTIMECONFIG                                               
#define STBM_EQ2_LOCALCLOCKCONFIGUSEDOFLOCALTIMECONFIG                                              
#define STBM_EQ2_TIMEBASECONFIGIDXOFLOCALTIMECONFIG                                                 
#define STBM_EQ2_TIMEBASEPARTITIONMAPPINGIDXOFLOCALTIMECONFIG                                       
#define STBM_EQ2_PCPARTITIONCONFIGIDXOFPARTITIONIDENTIFIERS                                         
#define STBM_EQ2_PARTITIONSNVOFPARTITIONIDENTIFIERS                                                 
#define STBM_EQ2_HWFREQUENCYOFSYNCTIMERECORDINGHEADER                                               
#define STBM_EQ2_HWPRESCALEROFSYNCTIMERECORDINGHEADER                                               
#define STBM_EQ2_TIMEDOMAINOFSYNCTIMERECORDINGHEADER                                                
#define STBM_EQ2_LOCALTIMECONFIGIDXOFTIMEBASECONFIG                                                 
#define STBM_EQ2_PARTITIONCONFIGIDXOFTIMEBASECONFIG                                                 
#define STBM_EQ2_STATUSIDXOFTIMEBASECONFIG                                                          
#define STBM_EQ2_SYNCHRONIZEDTIMEBASEOFTIMEBASECONFIG                                               
#define STBM_EQ2_TIMEBASEIDOFTIMEBASECONFIG                                                         
#define STBM_EQ2_TIMELEAPCONFIGIDXOFTIMEBASECONFIG                                                  
#define STBM_EQ2_TIMELEAPCONFIGUSEDOFTIMEBASECONFIG                                                 
#define STBM_EQ2_TIMERECORDINGCONFIGIDXOFTIMEBASECONFIG                                             
#define STBM_EQ2_TIMERECORDINGCONFIGUSEDOFTIMEBASECONFIG                                            
#define STBM_EQ2_TIMESLAVEOFTIMEBASECONFIG                                                          
#define STBM_EQ2_TIMEOUTCONFIGIDXOFTIMEBASECONFIG                                                   
#define STBM_EQ2_TIMEOUTCONFIGUSEDOFTIMEBASECONFIG                                                  
#define STBM_EQ2_USERDATASTATEIDXOFTIMEBASECONFIG                                                   
#define STBM_EQ2_INDIRECTIONTOGPTCLOCKSTATEIDXOFTIMEBASEPARTITIONMAPPING                            
#define STBM_EQ2_INDIRECTIONTOGPTCLOCKSTATEPARTITIONIDXOFTIMEBASEPARTITIONMAPPING                   
#define STBM_EQ2_INDIRECTIONTOGPTCLOCKSTATEUSEDOFTIMEBASEPARTITIONMAPPING                           
#define STBM_EQ2_INDIRECTIONTOLOCALCLOCKSTATEIDXOFTIMEBASEPARTITIONMAPPING                          
#define STBM_EQ2_INDIRECTIONTOLOCALCLOCKSTATEPARTITIONIDXOFTIMEBASEPARTITIONMAPPING                 
#define STBM_EQ2_INDIRECTIONTOLOCALCLOCKSTATEUSEDOFTIMEBASEPARTITIONMAPPING                         
#define STBM_EQ2_INDIRECTIONTOLOCALTIMESTATEIDXOFTIMEBASEPARTITIONMAPPING                           
#define STBM_EQ2_INDIRECTIONTOLOCALTIMESTATEPARTITIONIDXOFTIMEBASEPARTITIONMAPPING                  
#define STBM_EQ2_INDIRECTIONTOMAINTIMESTATEIDXOFTIMEBASEPARTITIONMAPPING                            
#define STBM_EQ2_INDIRECTIONTOMAINTIMESTATEPARTITIONIDXOFTIMEBASEPARTITIONMAPPING                   
#define STBM_EQ2_INDIRECTIONTOTIMEBASECONFIGIDXOFTIMEBASEPARTITIONMAPPING                           
#define STBM_EQ2_INDIRECTIONTOTIMEBASECONFIGPARTITIONIDXOFTIMEBASEPARTITIONMAPPING                  
#define STBM_EQ2_INDIRECTIONTOVIRTUALLOCALTIMESTATEIDXOFTIMEBASEPARTITIONMAPPING                    
#define STBM_EQ2_INDIRECTIONTOVIRTUALLOCALTIMESTATEPARTITIONIDXOFTIMEBASEPARTITIONMAPPING           
#define STBM_EQ2_CLEARCOUNTOFTIMELEAPCONFIG                                                         
#define STBM_EQ2_FUTURETHRESHOLDOFTIMELEAPCONFIG                                                    
#define STBM_EQ2_PASTTHRESHOLDOFTIMELEAPCONFIG                                                      
#define STBM_EQ2_BLOCKCOUNTOFTIMERECORDINGCONFIG                                                    
#define STBM_EQ2_SYNCTIMERECORDINGBLOCKENDIDXOFTIMERECORDINGCONFIG                                  
#define STBM_EQ2_SYNCTIMERECORDINGBLOCKSTARTIDXOFTIMERECORDINGCONFIG                                
#define STBM_EQ2_SYNCTIMERECORDINGBLOCKUSEDOFTIMERECORDINGCONFIG                                    
#define STBM_EQ2_SYNCTIMERECORDINGHEADERIDXOFTIMERECORDINGCONFIG                                    
#define STBM_EQ2_SYNCTIMERECORDINGHEADERUSEDOFTIMERECORDINGCONFIG                                   
#define STBM_EQ2_TIMEBASECONFIGIDXOFTIMERECORDINGCONFIG                                             
#define STBM_EQ2_TIMEBASECONFIGUSEDOFTIMERECORDINGCONFIG                                            
#define STBM_EQ2_TIMERECORDINGSYNCCALLBACKIDXOFTIMERECORDINGCONFIG                                  
#define STBM_EQ2_TIMERECORDINGSYNCCALLBACKUSEDOFTIMERECORDINGCONFIG                                 
#define STBM_EQ2_CALLBACKOFTIMERECORDINGSYNCCALLBACK                                                
#define STBM_EQ2_SYNCLOSSTIMEOUTCOUNTEROFTIMEOUTCONFIG                                              
#define STBM_EQ2_TIMEBASECONFIGIDXOFTIMEOUTCONFIG                                                   
#define STBM_EQ2_PCPARTITIONCONFIGOFPCCONFIG                                                        StbM_PCPartitionConfig
#define STBM_EQ2_PARTITIONIDENTIFIERSOFPCCONFIG                                                     StbM_PartitionIdentifiers
#define STBM_EQ2_GPTCLOCKCONFIGOFPCPARTITIONCONFIG                                                  
#define STBM_EQ2_GPTCLOCKSTATEOFPCPARTITIONCONFIG                                                   
#define STBM_EQ2_INITIALIZEDOFPCPARTITIONCONFIG                                                     
#define STBM_EQ2_LOCALCLOCKCONFIGOFPCPARTITIONCONFIG                                                
#define STBM_EQ2_LOCALCLOCKSTATEOFPCPARTITIONCONFIG                                                 
#define STBM_EQ2_LOCALTIMECONFIGOFPCPARTITIONCONFIG                                                 
#define STBM_EQ2_LOCALTIMESTATEOFPCPARTITIONCONFIG                                                  
#define STBM_EQ2_MAINTIMESTATEOFPCPARTITIONCONFIG                                                   
#define STBM_EQ2_RECEIVEDTIMESTATEOFPCPARTITIONCONFIG                                               
#define STBM_EQ2_SIZEOFGPTCLOCKCONFIGOFPCPARTITIONCONFIG                                            
#define STBM_EQ2_SIZEOFGPTCLOCKSTATEOFPCPARTITIONCONFIG                                             
#define STBM_EQ2_SIZEOFLOCALCLOCKCONFIGOFPCPARTITIONCONFIG                                          
#define STBM_EQ2_SIZEOFLOCALCLOCKSTATEOFPCPARTITIONCONFIG                                           
#define STBM_EQ2_SIZEOFLOCALTIMECONFIGOFPCPARTITIONCONFIG                                           
#define STBM_EQ2_SIZEOFLOCALTIMESTATEOFPCPARTITIONCONFIG                                            
#define STBM_EQ2_SIZEOFMAINTIMESTATEOFPCPARTITIONCONFIG                                             
#define STBM_EQ2_SIZEOFSYNCTIMERECORDINGBLOCKOFPCPARTITIONCONFIG                                    
#define STBM_EQ2_SIZEOFSYNCTIMERECORDINGHEADEROFPCPARTITIONCONFIG                                   
#define STBM_EQ2_SIZEOFTIMEBASECONFIGOFPCPARTITIONCONFIG                                            
#define STBM_EQ2_SIZEOFTIMELEAPCONFIGOFPCPARTITIONCONFIG                                            
#define STBM_EQ2_SIZEOFTIMERECORDINGCONFIGOFPCPARTITIONCONFIG                                       
#define STBM_EQ2_SIZEOFTIMERECORDINGSYNCCALLBACKOFPCPARTITIONCONFIG                                 
#define STBM_EQ2_SIZEOFTIMEOUTCONFIGOFPCPARTITIONCONFIG                                             
#define STBM_EQ2_SIZEOFUSERDATASTATEOFPCPARTITIONCONFIG                                             
#define STBM_EQ2_SIZEOFVIRTUALLOCALTIMESTATEOFPCPARTITIONCONFIG                                     
#define STBM_EQ2_STATUSOFPCPARTITIONCONFIG                                                          
#define STBM_EQ2_SYNCTIMERECORDINGBLOCKOFPCPARTITIONCONFIG                                          
#define STBM_EQ2_SYNCTIMERECORDINGHEADEROFPCPARTITIONCONFIG                                         
#define STBM_EQ2_TIMEBASECONFIGOFPCPARTITIONCONFIG                                                  
#define STBM_EQ2_TIMEBASEPARTITIONMAPPINGOFPCPARTITIONCONFIG                                        StbM_TimeBasePartitionMapping
#define STBM_EQ2_TIMEBASESTATEOFPCPARTITIONCONFIG                                                   
#define STBM_EQ2_TIMELEAPCLEARSTATEOFPCPARTITIONCONFIG                                              
#define STBM_EQ2_TIMELEAPCONFIGOFPCPARTITIONCONFIG                                                  
#define STBM_EQ2_TIMELEAPSTATEOFPCPARTITIONCONFIG                                                   
#define STBM_EQ2_TIMERECORDINGCONFIGOFPCPARTITIONCONFIG                                             
#define STBM_EQ2_TIMERECORDINGSTATEOFPCPARTITIONCONFIG                                              
#define STBM_EQ2_TIMERECORDINGSYNCCALLBACKOFPCPARTITIONCONFIG                                       
#define STBM_EQ2_TIMEOUTCONFIGOFPCPARTITIONCONFIG                                                   
#define STBM_EQ2_TIMEOUTSTATEOFPCPARTITIONCONFIG                                                    
#define STBM_EQ2_USERDATASTATEOFPCPARTITIONCONFIG                                                   
#define STBM_EQ2_VIRTUALLOCALTIMESTATEOFPCPARTITIONCONFIG                                           
/** 
  \}
*/ 

/** 
  \defgroup  StbMPCSymbolicInitializationPointers  StbM Symbolic Initialization Pointers (PRE_COMPILE)
  \brief  Symbolic initialization pointers to be used in the call of a preinit or init function.
  \{
*/ 
#define StbM_Config_Ptr                                                                             NULL_PTR  /**< symbolic identifier which shall be used to initialize 'StbM' */
/** 
  \}
*/ 

/** 
  \defgroup  StbMPCInitializationSymbols  StbM Initialization Symbols (PRE_COMPILE)
  \brief  Symbolic initialization pointers which may be used in the call of a preinit or init function. Please note, that the defined value can be a 'NULL_PTR' and the address operator is not usable.
  \{
*/ 
#define StbM_Config                                                                                 NULL_PTR  /**< symbolic identifier which could be used to initialize 'StbM */
/** 
  \}
*/ 

/** 
  \defgroup  StbMPCGeneral  StbM General (PRE_COMPILE)
  \brief  General constant defines not associated with a group of defines.
  \{
*/ 
#define STBM_CHECK_INIT_POINTER                                                                     STD_OFF  /**< STD_ON if the init pointer shall not be used as NULL_PTR and a check shall validate this. */
#define STBM_FINAL_MAGIC_NUMBER                                                                     0xA01Eu  /**< the precompile constant to validate the size of the initialization structure at initialization time of StbM */
#define STBM_INDIVIDUAL_POSTBUILD                                                                   STD_OFF  /**< the precompile constant to check, that the module is individual postbuildable. The module 'StbM' is not configured to be postbuild capable. */
#define STBM_INIT_DATA                                                                              STBM_CONST  /**< CompilerMemClassDefine for the initialization data. */
#define STBM_INIT_DATA_HASH_CODE                                                                    132314632  /**< the precompile constant to validate the initialization structure at initialization time of StbM with a hashcode. The seed value is '0xA01Eu' */
#define STBM_USE_ECUM_BSW_ERROR_HOOK                                                                STD_OFF  /**< STD_ON if the EcuM_BswErrorHook shall be called in the ConfigPtr check. */
#define STBM_USE_INIT_POINTER                                                                       STD_OFF  /**< STD_ON if the init pointer StbM shall be used. */
#define StbM_PartitionIndexOfCSLForCommonSharedMemory                                               0u  /**< internal partition index of the ComStackLib for the partition CommonSharedMemory */
#define StbM_PartitionIndexOfCSLForOsApplication_Trusted_Core0                                      1u  /**< internal partition index of the ComStackLib for the partition OsApplication_Trusted_Core0 */
/** 
  \}
*/ 


/**********************************************************************************************************************
  CONFIGURATION CLASS: LINK
  SECTION: GLOBAL CONSTANT MACROS
**********************************************************************************************************************/
/** 
  \defgroup  StbMLTDataSwitches  StbM Data Switches  (LINK)
  \brief  These defines are used to deactivate data and their processing.
  \{
*/ 
#define STBM_LTCONFIG                                                                               STD_OFF  /**< Deactivateable: 'StbM_LTConfig' Reason: 'deactivated because PartitionConfig is deactivated.' */
#define STBM_LTPARTITIONCONFIGOFLTCONFIG                                                            STD_OFF  /**< Deactivateable: 'StbM_LTConfig.LTPartitionConfig' Reason: 'deactivated because PartitionConfig is deactivated.' */
#define STBM_LTPARTITIONCONFIG                                                                      STD_OFF  /**< Deactivateable: 'StbM_LTPartitionConfig' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
/** 
  \}
*/ 


/**********************************************************************************************************************
  CONFIGURATION CLASS: POST_BUILD
  SECTION: GLOBAL CONSTANT MACROS
**********************************************************************************************************************/
/** 
  \defgroup  StbMPBDataSwitches  StbM Data Switches  (POST_BUILD)
  \brief  These defines are used to deactivate data and their processing.
  \{
*/ 
#define STBM_PBCONFIG                                                                               STD_OFF  /**< Deactivateable: 'StbM_PBConfig' Reason: 'the module configuration is VARIANT_PRE_COMPILE.' */
#define STBM_LTCONFIGIDXOFPBCONFIG                                                                  STD_OFF  /**< Deactivateable: 'StbM_PBConfig.LTConfigIdx' Reason: 'the module configuration is VARIANT_PRE_COMPILE.' */
#define STBM_PBPARTITIONCONFIGOFPBCONFIG                                                            STD_OFF  /**< Deactivateable: 'StbM_PBConfig.PBPartitionConfig' Reason: 'the module configuration is VARIANT_PRE_COMPILE.' */
#define STBM_PCCONFIGIDXOFPBCONFIG                                                                  STD_OFF  /**< Deactivateable: 'StbM_PBConfig.PCConfigIdx' Reason: 'the module configuration is VARIANT_PRE_COMPILE.' */
#define STBM_PBPARTITIONCONFIG                                                                      STD_OFF  /**< Deactivateable: 'StbM_PBPartitionConfig' Reason: 'the module configuration is VARIANT_PRE_COMPILE.' */
/** 
  \}
*/ 



/**********************************************************************************************************************
 *  UNIT CONFIG MACROS
 *********************************************************************************************************************/
# define STBM_CONFIG_LOCAL_TIME                         (STBM_LOCALTIMECONFIGIDXOFTIMEBASECONFIG)
# define STBM_CONFIG_LOCAL_CLOCK                        (STBM_LOCALCLOCKCONFIGIDXOFLOCALTIMECONFIG)
# define STBM_CONFIG_OS_CLOCK                           (STBM_OSCLOCKCONFIGIDXOFLOCALCLOCKCONFIG)
# define STBM_CONFIG_GPT_CLOCK                          (STBM_GPTCLOCKCONFIGIDXOFLOCALCLOCKCONFIG)
# define STBM_CONFIG_ETH_CLOCK                          (STBM_ETHCLOCKCONFIGIDXOFLOCALCLOCKCONFIG)
# define STBM_CONFIG_STATUS                             (STBM_STATUSIDXOFTIMEBASECONFIG)
# define STBM_CONFIG_STATUS_NOTIFICATION                (STBM_STATUSNOTIFICATIONCUSTOMERCALLBACK)              /* Callbacks are available only for pre-compile. Therefore, the feature has to be configured in order to be STD_ON. Important for post build use-case. */
# define STBM_CONFIG_MASTER_RATE_CORRECTION             (STBM_TIMECORRECTIONMASTERCONFIGIDXOFTIMEBASECONFIG)
# define STBM_CONFIG_SLAVE_RATE_CORRECTION              (STBM_TIMECORRECTIONSLAVECONFIGIDXOFTIMEBASECONFIG)
# define STBM_CONFIG_TIME_LEAP                          (STBM_TIMELEAPCONFIGIDXOFTIMEBASECONFIG)
# define STBM_CONFIG_TIME_NOTIFICATION                  (STBM_TIMENOTIFICATIONCALLBACK)                        /* Callbacks are available only for pre-compile. Therefore, the feature has to be configured in order to be STD_ON. Important for post build use-case. */
# define STBM_CONFIG_TIMEOUT                            (STBM_TIMEOUTCONFIGIDXOFTIMEBASECONFIG)
# define STBM_CONFIG_TRIGGERED_CUSTOMER                 (STBM_TRIGGEREDCUSTOMERCONFIG)
# define STBM_CONFIG_USER_DATA                          (STBM_USERDATASTATEIDXOFTIMEBASECONFIG)
# define STBM_CONFIG_TIME_RECORDING                     (STBM_TIMERECORDINGSYNCCALLBACK)                       /* Callbacks are available only for pre-compile. Therefore, the feature has to be configured in order to be STD_ON. Important for post build use-case. */
# define STBM_CONFIG_TIME_RECORDING_SYNC                (STBM_TIMERECORDINGSYNCCALLBACK)                       /* Callbacks are available only for pre-compile. Therefore, the feature has to be configured in order to be STD_ON. Important for post build use-case. */
# define STBM_CONFIG_TIME_RECORDING_OFFSET              (STBM_TIMERECORDINGOFFSETCALLBACK)
# define STBM_CONFIG_TIME_VALIDATION                    (STBM_TIMEVALIDATIONCONFIG)
# define STBM_CONFIG_TIME_VALIDATION_ETH_MASTER         (STBM_TIMEVALIDATIONETHMASTERCALLBACK)                 /* Callbacks are available only for pre-compile. Therefore, the feature has to be configured in order to be STD_ON. Important for post build use-case. */
# define STBM_CONFIG_TIME_VALIDATION_ETH_SLAVE          (STBM_TIMEVALIDATIONETHSLAVECALLBACK)                  /* Callbacks are available only for pre-compile. Therefore, the feature has to be configured in order to be STD_ON. Important for post build use-case. */
# define STBM_CONFIG_OFFSET_TIMEBASE                    (STBM_TIMEBASEPARTITIONMAPPINGOFFSETIDXOFTIMEBASECONFIG)
# define STBM_CONFIG_SOURCE_TIMEBASE                    (STBM_TIMEBASEPARTITIONMAPPINGSOURCEIDXOFTIMEBASECONFIG)
# define STBM_CONFIG_GLOBAL_TIME_MASTER                 (STBM_GLOBALTIMEMASTEROFTIMEBASECONFIG)
# define STBM_CONFIG_TIME_SLAVE                         (STBM_TIMESLAVEOFTIMEBASECONFIG)
# define STBM_CONFIG_GATEWAY                            (STBM_TIMEGATEWAYOFTIMEBASECONFIG)
# define STBM_CONFIG_PURE_LOCAL_TIMEBASE                (STBM_PURELOCALTIMEBASEOFTIMEBASECONFIG)

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
  \defgroup  StbMPCGetRootDataMacros  StbM Get Root Data Macros (PRE_COMPILE)
  \brief  These macros are used to get data pointers of root data.
  \{
*/ 
#define StbM_GetGptClockConfigOfPCPartitionConfig(partitionIndex)                                   StbM_GetPCPartitionConfigOfPCConfig()[(partitionIndex)].GptClockConfigOfPCPartitionConfig
#define StbM_GetGptClockStateOfPCPartitionConfig(partitionIndex)                                    StbM_GetPCPartitionConfigOfPCConfig()[(partitionIndex)].GptClockStateOfPCPartitionConfig
#define StbM_GetInitializedOfPCPartitionConfig(partitionIndex)                                      StbM_GetPCPartitionConfigOfPCConfig()[(partitionIndex)].InitializedOfPCPartitionConfig
#define StbM_GetLocalClockConfigOfPCPartitionConfig(partitionIndex)                                 StbM_GetPCPartitionConfigOfPCConfig()[(partitionIndex)].LocalClockConfigOfPCPartitionConfig
#define StbM_GetLocalClockStateOfPCPartitionConfig(partitionIndex)                                  StbM_GetPCPartitionConfigOfPCConfig()[(partitionIndex)].LocalClockStateOfPCPartitionConfig
#define StbM_GetLocalTimeConfigOfPCPartitionConfig(partitionIndex)                                  StbM_GetPCPartitionConfigOfPCConfig()[(partitionIndex)].LocalTimeConfigOfPCPartitionConfig
#define StbM_GetLocalTimeStateOfPCPartitionConfig(partitionIndex)                                   StbM_GetPCPartitionConfigOfPCConfig()[(partitionIndex)].LocalTimeStateOfPCPartitionConfig
#define StbM_GetMainTimeStateOfPCPartitionConfig(partitionIndex)                                    StbM_GetPCPartitionConfigOfPCConfig()[(partitionIndex)].MainTimeStateOfPCPartitionConfig
#define StbM_GetReceivedTimeStateOfPCPartitionConfig(partitionIndex)                                StbM_GetPCPartitionConfigOfPCConfig()[(partitionIndex)].ReceivedTimeStateOfPCPartitionConfig
#define StbM_GetSizeOfGptClockConfigOfPCPartitionConfig(partitionIndex)                             StbM_GetPCPartitionConfigOfPCConfig()[(partitionIndex)].SizeOfGptClockConfigOfPCPartitionConfig
#define StbM_GetSizeOfGptClockStateOfPCPartitionConfig(partitionIndex)                              StbM_GetPCPartitionConfigOfPCConfig()[(partitionIndex)].SizeOfGptClockStateOfPCPartitionConfig
#define StbM_GetSizeOfLocalClockConfigOfPCPartitionConfig(partitionIndex)                           StbM_GetPCPartitionConfigOfPCConfig()[(partitionIndex)].SizeOfLocalClockConfigOfPCPartitionConfig
#define StbM_GetSizeOfLocalClockStateOfPCPartitionConfig(partitionIndex)                            StbM_GetPCPartitionConfigOfPCConfig()[(partitionIndex)].SizeOfLocalClockStateOfPCPartitionConfig
#define StbM_GetSizeOfLocalTimeConfigOfPCPartitionConfig(partitionIndex)                            StbM_GetPCPartitionConfigOfPCConfig()[(partitionIndex)].SizeOfLocalTimeConfigOfPCPartitionConfig
#define StbM_GetSizeOfLocalTimeStateOfPCPartitionConfig(partitionIndex)                             StbM_GetPCPartitionConfigOfPCConfig()[(partitionIndex)].SizeOfLocalTimeStateOfPCPartitionConfig
#define StbM_GetSizeOfMainTimeStateOfPCPartitionConfig(partitionIndex)                              StbM_GetPCPartitionConfigOfPCConfig()[(partitionIndex)].SizeOfMainTimeStateOfPCPartitionConfig
#define StbM_GetSizeOfSyncTimeRecordingBlockOfPCPartitionConfig(partitionIndex)                     StbM_GetPCPartitionConfigOfPCConfig()[(partitionIndex)].SizeOfSyncTimeRecordingBlockOfPCPartitionConfig
#define StbM_GetSizeOfSyncTimeRecordingHeaderOfPCPartitionConfig(partitionIndex)                    StbM_GetPCPartitionConfigOfPCConfig()[(partitionIndex)].SizeOfSyncTimeRecordingHeaderOfPCPartitionConfig
#define StbM_GetSizeOfTimeBaseConfigOfPCPartitionConfig(partitionIndex)                             StbM_GetPCPartitionConfigOfPCConfig()[(partitionIndex)].SizeOfTimeBaseConfigOfPCPartitionConfig
#define StbM_GetSizeOfTimeLeapConfigOfPCPartitionConfig(partitionIndex)                             StbM_GetPCPartitionConfigOfPCConfig()[(partitionIndex)].SizeOfTimeLeapConfigOfPCPartitionConfig
#define StbM_GetSizeOfTimeRecordingConfigOfPCPartitionConfig(partitionIndex)                        StbM_GetPCPartitionConfigOfPCConfig()[(partitionIndex)].SizeOfTimeRecordingConfigOfPCPartitionConfig
#define StbM_GetSizeOfTimeRecordingSyncCallbackOfPCPartitionConfig(partitionIndex)                  StbM_GetPCPartitionConfigOfPCConfig()[(partitionIndex)].SizeOfTimeRecordingSyncCallbackOfPCPartitionConfig
#define StbM_GetSizeOfTimeoutConfigOfPCPartitionConfig(partitionIndex)                              StbM_GetPCPartitionConfigOfPCConfig()[(partitionIndex)].SizeOfTimeoutConfigOfPCPartitionConfig
#define StbM_GetSizeOfUserDataStateOfPCPartitionConfig(partitionIndex)                              StbM_GetPCPartitionConfigOfPCConfig()[(partitionIndex)].SizeOfUserDataStateOfPCPartitionConfig
#define StbM_GetSizeOfVirtualLocalTimeStateOfPCPartitionConfig(partitionIndex)                      StbM_GetPCPartitionConfigOfPCConfig()[(partitionIndex)].SizeOfVirtualLocalTimeStateOfPCPartitionConfig
#define StbM_GetStatusOfPCPartitionConfig(partitionIndex)                                           StbM_GetPCPartitionConfigOfPCConfig()[(partitionIndex)].StatusOfPCPartitionConfig
#define StbM_GetSyncTimeRecordingBlockOfPCPartitionConfig(partitionIndex)                           StbM_GetPCPartitionConfigOfPCConfig()[(partitionIndex)].SyncTimeRecordingBlockOfPCPartitionConfig
#define StbM_GetSyncTimeRecordingHeaderOfPCPartitionConfig(partitionIndex)                          StbM_GetPCPartitionConfigOfPCConfig()[(partitionIndex)].SyncTimeRecordingHeaderOfPCPartitionConfig
#define StbM_GetTimeBaseConfigOfPCPartitionConfig(partitionIndex)                                   StbM_GetPCPartitionConfigOfPCConfig()[(partitionIndex)].TimeBaseConfigOfPCPartitionConfig
#define StbM_GetTimeBaseStateOfPCPartitionConfig(partitionIndex)                                    StbM_GetPCPartitionConfigOfPCConfig()[(partitionIndex)].TimeBaseStateOfPCPartitionConfig
#define StbM_GetTimeLeapClearStateOfPCPartitionConfig(partitionIndex)                               StbM_GetPCPartitionConfigOfPCConfig()[(partitionIndex)].TimeLeapClearStateOfPCPartitionConfig
#define StbM_GetTimeLeapConfigOfPCPartitionConfig(partitionIndex)                                   StbM_GetPCPartitionConfigOfPCConfig()[(partitionIndex)].TimeLeapConfigOfPCPartitionConfig
#define StbM_GetTimeLeapStateOfPCPartitionConfig(partitionIndex)                                    StbM_GetPCPartitionConfigOfPCConfig()[(partitionIndex)].TimeLeapStateOfPCPartitionConfig
#define StbM_GetTimeRecordingConfigOfPCPartitionConfig(partitionIndex)                              StbM_GetPCPartitionConfigOfPCConfig()[(partitionIndex)].TimeRecordingConfigOfPCPartitionConfig
#define StbM_GetTimeRecordingStateOfPCPartitionConfig(partitionIndex)                               StbM_GetPCPartitionConfigOfPCConfig()[(partitionIndex)].TimeRecordingStateOfPCPartitionConfig
#define StbM_GetTimeRecordingSyncCallbackOfPCPartitionConfig(partitionIndex)                        StbM_GetPCPartitionConfigOfPCConfig()[(partitionIndex)].TimeRecordingSyncCallbackOfPCPartitionConfig
#define StbM_GetTimeoutConfigOfPCPartitionConfig(partitionIndex)                                    StbM_GetPCPartitionConfigOfPCConfig()[(partitionIndex)].TimeoutConfigOfPCPartitionConfig
#define StbM_GetTimeoutStateOfPCPartitionConfig(partitionIndex)                                     StbM_GetPCPartitionConfigOfPCConfig()[(partitionIndex)].TimeoutStateOfPCPartitionConfig
#define StbM_GetUserDataStateOfPCPartitionConfig(partitionIndex)                                    StbM_GetPCPartitionConfigOfPCConfig()[(partitionIndex)].UserDataStateOfPCPartitionConfig
#define StbM_GetVirtualLocalTimeStateOfPCPartitionConfig(partitionIndex)                            StbM_GetPCPartitionConfigOfPCConfig()[(partitionIndex)].VirtualLocalTimeStateOfPCPartitionConfig
/** 
  \}
*/ 

/** 
  \defgroup  StbMPCGetConstantDuplicatedRootDataMacros  StbM Get Constant Duplicated Root Data Macros (PRE_COMPILE)
  \brief  These macros can be used to read deduplicated by constance root data elements.
  \{
*/ 
#define StbM_GetPCPartitionConfigOfPCConfig()                                                       StbM_PCPartitionConfig  /**< the pointer to StbM_PCPartitionConfig */
#define StbM_GetPartitionIdentifiersOfPCConfig()                                                    StbM_PartitionIdentifiers  /**< the pointer to StbM_PartitionIdentifiers */
#define StbM_GetSizeOfPartitionIdentifiersOfPCConfig()                                              2u  /**< the number of accomplishable value elements in StbM_PartitionIdentifiers */
#define StbM_GetSizeOfTimeBasePartitionMappingOfPCPartitionConfig()                                 1u  /**< the number of accomplishable value elements in StbM_TimeBasePartitionMapping */
#define StbM_GetTimeBasePartitionMappingOfPCPartitionConfig()                                       StbM_TimeBasePartitionMapping  /**< the pointer to StbM_TimeBasePartitionMapping */
/** 
  \}
*/ 

/** 
  \defgroup  StbMPCGetDuplicatedRootDataMacros  StbM Get Duplicated Root Data Macros (PRE_COMPILE)
  \brief  These macros can be used to read deduplicated root data elements.
  \{
*/ 
#define StbM_GetSizeOfReceivedTimeStateOfPCPartitionConfig(partitionIndex)                          StbM_GetSizeOfLocalTimeConfigOfPCPartitionConfig(partitionIndex)  /**< the number of accomplishable value elements in StbM_ReceivedTimeState */
#define StbM_GetSizeOfStatusOfPCPartitionConfig(partitionIndex)                                     StbM_GetSizeOfTimeBaseConfigOfPCPartitionConfig(partitionIndex)  /**< the number of accomplishable value elements in StbM_Status */
#define StbM_GetSizeOfTimeBaseStateOfPCPartitionConfig(partitionIndex)                              StbM_GetSizeOfTimeBaseConfigOfPCPartitionConfig(partitionIndex)  /**< the number of accomplishable value elements in StbM_TimeBaseState */
#define StbM_GetSizeOfTimeLeapClearStateOfPCPartitionConfig(partitionIndex)                         StbM_GetSizeOfTimeLeapConfigOfPCPartitionConfig(partitionIndex)  /**< the number of accomplishable value elements in StbM_TimeLeapClearState */
#define StbM_GetSizeOfTimeLeapStateOfPCPartitionConfig(partitionIndex)                              StbM_GetSizeOfLocalTimeConfigOfPCPartitionConfig(partitionIndex)  /**< the number of accomplishable value elements in StbM_TimeLeapState */
#define StbM_GetSizeOfTimeRecordingStateOfPCPartitionConfig(partitionIndex)                         StbM_GetSizeOfTimeRecordingConfigOfPCPartitionConfig(partitionIndex)  /**< the number of accomplishable value elements in StbM_TimeRecordingState */
#define StbM_GetSizeOfTimeoutStateOfPCPartitionConfig(partitionIndex)                               StbM_GetSizeOfTimeoutConfigOfPCPartitionConfig(partitionIndex)  /**< the number of accomplishable value elements in StbM_TimeoutState */
/** 
  \}
*/ 

/** 
  \defgroup  StbMPCGetDataMacros  StbM Get Data Macros (PRE_COMPILE)
  \brief  These macros can be used to read CONST and VAR data.
  \{
*/ 
#define StbM_GetGptChannelSymbolicNameOfGptClockConfig(Index, partitionIndex)                       (StbM_GetGptClockConfigOfPCPartitionConfig(partitionIndex)[(Index)].GptChannelSymbolicNameOfGptClockConfig)
#define StbM_GetMaxTickValueOfGptClockConfig(Index, partitionIndex)                                 (StbM_GetGptClockConfigOfPCPartitionConfig(partitionIndex)[(Index)].MaxTickValueOfGptClockConfig)
#define StbM_IsGptChannelActiveOfGptClockState(Index, partitionIndex)                               ((StbM_GetGptClockStateOfPCPartitionConfig(partitionIndex)[(Index)].GptChannelActiveOfGptClockState) != FALSE)
#define StbM_IsInitialized(partitionIndex)                                                          (((*(StbM_GetInitializedOfPCPartitionConfig(partitionIndex)))) != FALSE)
#define StbM_GetClockTypeOfLocalClockConfig(Index, partitionIndex)                                  (StbM_GetLocalClockConfigOfPCPartitionConfig(partitionIndex)[(Index)].ClockTypeOfLocalClockConfig)
#define StbM_GetDenominatorOfFactorClockTicksToLocalTimeOfLocalClockConfig(Index, partitionIndex)   (StbM_GetLocalClockConfigOfPCPartitionConfig(partitionIndex)[(Index)].DenominatorOfFactorClockTicksToLocalTimeOfLocalClockConfig)
#define StbM_GetGptClockConfigIdxOfLocalClockConfig(Index, partitionIndex)                          (StbM_GetLocalClockConfigOfPCPartitionConfig(partitionIndex)[(Index)].GptClockConfigIdxOfLocalClockConfig)
#define StbM_GetHwFrequencyOfLocalClockConfig(Index, partitionIndex)                                (StbM_GetLocalClockConfigOfPCPartitionConfig(partitionIndex)[(Index)].HwFrequencyOfLocalClockConfig)
#define StbM_GetHwPrescalerOfLocalClockConfig(Index, partitionIndex)                                (StbM_GetLocalClockConfigOfPCPartitionConfig(partitionIndex)[(Index)].HwPrescalerOfLocalClockConfig)
#define StbM_GetNumeratorOfFactorClockTicksToLocalTimeOfLocalClockConfig(Index, partitionIndex)     (StbM_GetLocalClockConfigOfPCPartitionConfig(partitionIndex)[(Index)].NumeratorOfFactorClockTicksToLocalTimeOfLocalClockConfig)
#define StbM_GetTimeBasePartitionMappingIdxOfLocalClockConfig(Index, partitionIndex)                (StbM_GetLocalClockConfigOfPCPartitionConfig(partitionIndex)[(Index)].TimeBasePartitionMappingIdxOfLocalClockConfig)
#define StbM_GetElapsedTimeOfLocalClockState(Index, partitionIndex)                                 (StbM_GetLocalClockStateOfPCPartitionConfig(partitionIndex)[(Index)].ElapsedTimeOfLocalClockState)
#define StbM_GetLastReadTimeOfLocalClockState(Index, partitionIndex)                                (StbM_GetLocalClockStateOfPCPartitionConfig(partitionIndex)[(Index)].LastReadTimeOfLocalClockState)
#define StbM_GetLocalClockConfigIdxOfLocalTimeConfig(Index, partitionIndex)                         (StbM_GetLocalTimeConfigOfPCPartitionConfig(partitionIndex)[(Index)].LocalClockConfigIdxOfLocalTimeConfig)
#define StbM_GetTimeBaseConfigIdxOfLocalTimeConfig(Index, partitionIndex)                           (StbM_GetLocalTimeConfigOfPCPartitionConfig(partitionIndex)[(Index)].TimeBaseConfigIdxOfLocalTimeConfig)
#define StbM_GetTimeBasePartitionMappingIdxOfLocalTimeConfig(Index, partitionIndex)                 (StbM_GetLocalTimeConfigOfPCPartitionConfig(partitionIndex)[(Index)].TimeBasePartitionMappingIdxOfLocalTimeConfig)
#define StbM_GetLocalTimeOfLocalTimeState(Index, partitionIndex)                                    (StbM_GetLocalTimeStateOfPCPartitionConfig(partitionIndex)[(Index)].LocalTimeOfLocalTimeState)
#define StbM_GetLocalTimeUpdatedOfLocalTimeState(Index, partitionIndex)                             (StbM_GetLocalTimeStateOfPCPartitionConfig(partitionIndex)[(Index)].LocalTimeUpdatedOfLocalTimeState)
#define StbM_GetGlobalTimeSyncOfMainTimeState(Index, partitionIndex)                                (StbM_GetMainTimeStateOfPCPartitionConfig(partitionIndex)[(Index)].GlobalTimeSyncOfMainTimeState)
#define StbM_GetVirtualLocalTimeSyncOfMainTimeState(Index, partitionIndex)                          (StbM_GetMainTimeStateOfPCPartitionConfig(partitionIndex)[(Index)].VirtualLocalTimeSyncOfMainTimeState)
#define StbM_GetPCPartitionConfigIdxOfPartitionIdentifiers(Index)                                   (StbM_GetPartitionIdentifiersOfPCConfig()[(Index)].PCPartitionConfigIdxOfPartitionIdentifiers)
#define StbM_GetPartitionSNVOfPartitionIdentifiers(Index)                                           (StbM_GetPartitionIdentifiersOfPCConfig()[(Index)].PartitionSNVOfPartitionIdentifiers)
#define StbM_GetGlobalTimeRxOfReceivedTimeState(Index, partitionIndex)                              (StbM_GetReceivedTimeStateOfPCPartitionConfig(partitionIndex)[(Index)].GlobalTimeRxOfReceivedTimeState)
#define StbM_GetLocalTimeSyncOfReceivedTimeState(Index, partitionIndex)                             (StbM_GetReceivedTimeStateOfPCPartitionConfig(partitionIndex)[(Index)].LocalTimeSyncOfReceivedTimeState)
#define StbM_GetVirtualLocalTimeRxOfReceivedTimeState(Index, partitionIndex)                        (StbM_GetReceivedTimeStateOfPCPartitionConfig(partitionIndex)[(Index)].VirtualLocalTimeRxOfReceivedTimeState)
#define StbM_GetGlobalTimeStatusOfStatus(Index, partitionIndex)                                     (StbM_GetStatusOfPCPartitionConfig(partitionIndex)[(Index)].GlobalTimeStatusOfStatus)
#define StbM_GetLocalTimeStatusOfStatus(Index, partitionIndex)                                      (StbM_GetStatusOfPCPartitionConfig(partitionIndex)[(Index)].LocalTimeStatusOfStatus)
#define StbM_GetGlbNanoSecondsOfSyncTimeRecordingBlock(Index, partitionIndex)                       (StbM_GetSyncTimeRecordingBlockOfPCPartitionConfig(partitionIndex)[(Index)].GlbNanoSecondsOfSyncTimeRecordingBlock)
#define StbM_GetGlbSecondsOfSyncTimeRecordingBlock(Index, partitionIndex)                           (StbM_GetSyncTimeRecordingBlockOfPCPartitionConfig(partitionIndex)[(Index)].GlbSecondsOfSyncTimeRecordingBlock)
#define StbM_GetLocNanoSecondsOfSyncTimeRecordingBlock(Index, partitionIndex)                       (StbM_GetSyncTimeRecordingBlockOfPCPartitionConfig(partitionIndex)[(Index)].LocNanoSecondsOfSyncTimeRecordingBlock)
#define StbM_GetLocSecondsOfSyncTimeRecordingBlock(Index, partitionIndex)                           (StbM_GetSyncTimeRecordingBlockOfPCPartitionConfig(partitionIndex)[(Index)].LocSecondsOfSyncTimeRecordingBlock)
#define StbM_GetPathDelayOfSyncTimeRecordingBlock(Index, partitionIndex)                            (StbM_GetSyncTimeRecordingBlockOfPCPartitionConfig(partitionIndex)[(Index)].PathDelayOfSyncTimeRecordingBlock)
#define StbM_GetRateDeviationOfSyncTimeRecordingBlock(Index, partitionIndex)                        (StbM_GetSyncTimeRecordingBlockOfPCPartitionConfig(partitionIndex)[(Index)].RateDeviationOfSyncTimeRecordingBlock)
#define StbM_GetTimeBaseStatusOfSyncTimeRecordingBlock(Index, partitionIndex)                       (StbM_GetSyncTimeRecordingBlockOfPCPartitionConfig(partitionIndex)[(Index)].TimeBaseStatusOfSyncTimeRecordingBlock)
#define StbM_GetVirtualLocalTimeLowOfSyncTimeRecordingBlock(Index, partitionIndex)                  (StbM_GetSyncTimeRecordingBlockOfPCPartitionConfig(partitionIndex)[(Index)].VirtualLocalTimeLowOfSyncTimeRecordingBlock)
#define StbM_GetHwFrequencyOfSyncTimeRecordingHeader(Index, partitionIndex)                         (StbM_GetSyncTimeRecordingHeaderOfPCPartitionConfig(partitionIndex)[(Index)].HwFrequencyOfSyncTimeRecordingHeader)
#define StbM_GetHwPrescalerOfSyncTimeRecordingHeader(Index, partitionIndex)                         (StbM_GetSyncTimeRecordingHeaderOfPCPartitionConfig(partitionIndex)[(Index)].HwPrescalerOfSyncTimeRecordingHeader)
#define StbM_GetTimeDomainOfSyncTimeRecordingHeader(Index, partitionIndex)                          (StbM_GetSyncTimeRecordingHeaderOfPCPartitionConfig(partitionIndex)[(Index)].TimeDomainOfSyncTimeRecordingHeader)
#define StbM_GetLocalTimeConfigIdxOfTimeBaseConfig(Index, partitionIndex)                           (StbM_GetTimeBaseConfigOfPCPartitionConfig(partitionIndex)[(Index)].LocalTimeConfigIdxOfTimeBaseConfig)
#define StbM_GetPartitionConfigIdxOfTimeBaseConfig(Index, partitionIndex)                           (StbM_GetTimeBaseConfigOfPCPartitionConfig(partitionIndex)[(Index)].PartitionConfigIdxOfTimeBaseConfig)
#define StbM_GetStatusIdxOfTimeBaseConfig(Index, partitionIndex)                                    (StbM_GetTimeBaseConfigOfPCPartitionConfig(partitionIndex)[(Index)].StatusIdxOfTimeBaseConfig)
#define StbM_IsSynchronizedTimeBaseOfTimeBaseConfig(Index, partitionIndex)                          ((StbM_GetTimeBaseConfigOfPCPartitionConfig(partitionIndex)[(Index)].SynchronizedTimeBaseOfTimeBaseConfig) != FALSE)
#define StbM_GetTimeBaseIdOfTimeBaseConfig(Index, partitionIndex)                                   (StbM_GetTimeBaseConfigOfPCPartitionConfig(partitionIndex)[(Index)].TimeBaseIdOfTimeBaseConfig)
#define StbM_GetTimeLeapConfigIdxOfTimeBaseConfig(Index, partitionIndex)                            (StbM_GetTimeBaseConfigOfPCPartitionConfig(partitionIndex)[(Index)].TimeLeapConfigIdxOfTimeBaseConfig)
#define StbM_GetTimeRecordingConfigIdxOfTimeBaseConfig(Index, partitionIndex)                       (StbM_GetTimeBaseConfigOfPCPartitionConfig(partitionIndex)[(Index)].TimeRecordingConfigIdxOfTimeBaseConfig)
#define StbM_IsTimeSlaveOfTimeBaseConfig(Index, partitionIndex)                                     ((StbM_GetTimeBaseConfigOfPCPartitionConfig(partitionIndex)[(Index)].TimeSlaveOfTimeBaseConfig) != FALSE)
#define StbM_GetTimeoutConfigIdxOfTimeBaseConfig(Index, partitionIndex)                             (StbM_GetTimeBaseConfigOfPCPartitionConfig(partitionIndex)[(Index)].TimeoutConfigIdxOfTimeBaseConfig)
#define StbM_GetUserDataStateIdxOfTimeBaseConfig(Index, partitionIndex)                             (StbM_GetTimeBaseConfigOfPCPartitionConfig(partitionIndex)[(Index)].UserDataStateIdxOfTimeBaseConfig)
#define StbM_GetIndirectionToGptClockStateIdxOfTimeBasePartitionMapping(Index)                      (StbM_GetTimeBasePartitionMappingOfPCPartitionConfig()[(Index)].IndirectionToGptClockStateIdxOfTimeBasePartitionMapping)
#define StbM_GetIndirectionToGptClockStatePartitionIdxOfTimeBasePartitionMapping(Index)             (StbM_GetTimeBasePartitionMappingOfPCPartitionConfig()[(Index)].IndirectionToGptClockStatePartitionIdxOfTimeBasePartitionMapping)
#define StbM_GetIndirectionToLocalClockStateIdxOfTimeBasePartitionMapping(Index)                    (StbM_GetTimeBasePartitionMappingOfPCPartitionConfig()[(Index)].IndirectionToLocalClockStateIdxOfTimeBasePartitionMapping)
#define StbM_GetIndirectionToLocalClockStatePartitionIdxOfTimeBasePartitionMapping(Index)           (StbM_GetTimeBasePartitionMappingOfPCPartitionConfig()[(Index)].IndirectionToLocalClockStatePartitionIdxOfTimeBasePartitionMapping)
#define StbM_GetIndirectionToLocalTimeStateIdxOfTimeBasePartitionMapping(Index)                     (StbM_GetTimeBasePartitionMappingOfPCPartitionConfig()[(Index)].IndirectionToLocalTimeStateIdxOfTimeBasePartitionMapping)
#define StbM_GetIndirectionToLocalTimeStatePartitionIdxOfTimeBasePartitionMapping(Index)            (StbM_GetTimeBasePartitionMappingOfPCPartitionConfig()[(Index)].IndirectionToLocalTimeStatePartitionIdxOfTimeBasePartitionMapping)
#define StbM_GetIndirectionToMainTimeStateIdxOfTimeBasePartitionMapping(Index)                      (StbM_GetTimeBasePartitionMappingOfPCPartitionConfig()[(Index)].IndirectionToMainTimeStateIdxOfTimeBasePartitionMapping)
#define StbM_GetIndirectionToMainTimeStatePartitionIdxOfTimeBasePartitionMapping(Index)             (StbM_GetTimeBasePartitionMappingOfPCPartitionConfig()[(Index)].IndirectionToMainTimeStatePartitionIdxOfTimeBasePartitionMapping)
#define StbM_GetIndirectionToTimeBaseConfigIdxOfTimeBasePartitionMapping(Index)                     (StbM_GetTimeBasePartitionMappingOfPCPartitionConfig()[(Index)].IndirectionToTimeBaseConfigIdxOfTimeBasePartitionMapping)
#define StbM_GetIndirectionToTimeBaseConfigPartitionIdxOfTimeBasePartitionMapping(Index)            (StbM_GetTimeBasePartitionMappingOfPCPartitionConfig()[(Index)].IndirectionToTimeBaseConfigPartitionIdxOfTimeBasePartitionMapping)
#define StbM_GetIndirectionToVirtualLocalTimeStateIdxOfTimeBasePartitionMapping(Index)              (StbM_GetTimeBasePartitionMappingOfPCPartitionConfig()[(Index)].IndirectionToVirtualLocalTimeStateIdxOfTimeBasePartitionMapping)
#define StbM_GetIndirectionToVirtualLocalTimeStatePartitionIdxOfTimeBasePartitionMapping(Index)     (StbM_GetTimeBasePartitionMappingOfPCPartitionConfig()[(Index)].IndirectionToVirtualLocalTimeStatePartitionIdxOfTimeBasePartitionMapping)
#define StbM_GetUpdateCounterOfTimeBaseState(Index, partitionIndex)                                 (StbM_GetTimeBaseStateOfPCPartitionConfig(partitionIndex)[(Index)].UpdateCounterOfTimeBaseState)
#define StbM_GetClearCountFutureOfTimeLeapClearState(Index, partitionIndex)                         (StbM_GetTimeLeapClearStateOfPCPartitionConfig(partitionIndex)[(Index)].ClearCountFutureOfTimeLeapClearState)
#define StbM_GetClearCountPastOfTimeLeapClearState(Index, partitionIndex)                           (StbM_GetTimeLeapClearStateOfPCPartitionConfig(partitionIndex)[(Index)].ClearCountPastOfTimeLeapClearState)
#define StbM_GetClearCountOfTimeLeapConfig(Index, partitionIndex)                                   (StbM_GetTimeLeapConfigOfPCPartitionConfig(partitionIndex)[(Index)].ClearCountOfTimeLeapConfig)
#define StbM_GetFutureThresholdOfTimeLeapConfig(Index, partitionIndex)                              (StbM_GetTimeLeapConfigOfPCPartitionConfig(partitionIndex)[(Index)].FutureThresholdOfTimeLeapConfig)
#define StbM_GetPastThresholdOfTimeLeapConfig(Index, partitionIndex)                                (StbM_GetTimeLeapConfigOfPCPartitionConfig(partitionIndex)[(Index)].PastThresholdOfTimeLeapConfig)
#define StbM_GetTimeLeapOfTimeLeapState(Index, partitionIndex)                                      (StbM_GetTimeLeapStateOfPCPartitionConfig(partitionIndex)[(Index)].TimeLeapOfTimeLeapState)
#define StbM_IsTimeLeapValidOfTimeLeapState(Index, partitionIndex)                                  ((StbM_GetTimeLeapStateOfPCPartitionConfig(partitionIndex)[(Index)].TimeLeapValidOfTimeLeapState) != FALSE)
#define StbM_GetBlockCountOfTimeRecordingConfig(Index, partitionIndex)                              (StbM_GetTimeRecordingConfigOfPCPartitionConfig(partitionIndex)[(Index)].BlockCountOfTimeRecordingConfig)
#define StbM_GetSyncTimeRecordingBlockEndIdxOfTimeRecordingConfig(Index, partitionIndex)            (StbM_GetTimeRecordingConfigOfPCPartitionConfig(partitionIndex)[(Index)].SyncTimeRecordingBlockEndIdxOfTimeRecordingConfig)
#define StbM_GetSyncTimeRecordingBlockStartIdxOfTimeRecordingConfig(Index, partitionIndex)          (StbM_GetTimeRecordingConfigOfPCPartitionConfig(partitionIndex)[(Index)].SyncTimeRecordingBlockStartIdxOfTimeRecordingConfig)
#define StbM_GetSyncTimeRecordingHeaderIdxOfTimeRecordingConfig(Index, partitionIndex)              (StbM_GetTimeRecordingConfigOfPCPartitionConfig(partitionIndex)[(Index)].SyncTimeRecordingHeaderIdxOfTimeRecordingConfig)
#define StbM_GetTimeBaseConfigIdxOfTimeRecordingConfig(Index, partitionIndex)                       (StbM_GetTimeRecordingConfigOfPCPartitionConfig(partitionIndex)[(Index)].TimeBaseConfigIdxOfTimeRecordingConfig)
#define StbM_GetTimeRecordingSyncCallbackIdxOfTimeRecordingConfig(Index, partitionIndex)            (StbM_GetTimeRecordingConfigOfPCPartitionConfig(partitionIndex)[(Index)].TimeRecordingSyncCallbackIdxOfTimeRecordingConfig)
#define StbM_GetCurrentBlockIdxOfTimeRecordingState(Index, partitionIndex)                          (StbM_GetTimeRecordingStateOfPCPartitionConfig(partitionIndex)[(Index)].CurrentBlockIdxOfTimeRecordingState)
#define StbM_GetPathDelayOfTimeRecordingState(Index, partitionIndex)                                (StbM_GetTimeRecordingStateOfPCPartitionConfig(partitionIndex)[(Index)].PathDelayOfTimeRecordingState)
#define StbM_GetRecordedBlocksCountOfTimeRecordingState(Index, partitionIndex)                      (StbM_GetTimeRecordingStateOfPCPartitionConfig(partitionIndex)[(Index)].RecordedBlocksCountOfTimeRecordingState)
#define StbM_GetCallbackOfTimeRecordingSyncCallback(Index, partitionIndex)                          (StbM_GetTimeRecordingSyncCallbackOfPCPartitionConfig(partitionIndex)[(Index)].CallbackOfTimeRecordingSyncCallback)
#define StbM_GetSyncLossTimeoutCounterOfTimeoutConfig(Index, partitionIndex)                        (StbM_GetTimeoutConfigOfPCPartitionConfig(partitionIndex)[(Index)].SyncLossTimeoutCounterOfTimeoutConfig)
#define StbM_GetTimeBaseConfigIdxOfTimeoutConfig(Index, partitionIndex)                             (StbM_GetTimeoutConfigOfPCPartitionConfig(partitionIndex)[(Index)].TimeBaseConfigIdxOfTimeoutConfig)
#define StbM_GetSyncLossTimeoutCounterOfTimeoutState(Index, partitionIndex)                         (StbM_GetTimeoutStateOfPCPartitionConfig(partitionIndex)[(Index)].SyncLossTimeoutCounterOfTimeoutState)
#define StbM_GetUserDataOfUserDataState(Index, partitionIndex)                                      (StbM_GetUserDataStateOfPCPartitionConfig(partitionIndex)[(Index)].UserDataOfUserDataState)
#define StbM_GetVirtualLocalTimeElapsedAfterAdaptionIntervalOfVirtualLocalTimeState(Index, partitionIndex) (StbM_GetVirtualLocalTimeStateOfPCPartitionConfig(partitionIndex)[(Index)].VirtualLocalTimeElapsedAfterAdaptionIntervalOfVirtualLocalTimeState)
#define StbM_GetVirtualLocalTimeOfVirtualLocalTimeState(Index, partitionIndex)                      (StbM_GetVirtualLocalTimeStateOfPCPartitionConfig(partitionIndex)[(Index)].VirtualLocalTimeOfVirtualLocalTimeState)
/** 
  \}
*/ 

/** 
  \defgroup  StbMPCGetDeduplicatedDataMacros  StbM Get Deduplicated Data Macros (PRE_COMPILE)
  \brief  These macros can be used to read deduplicated data elements.
  \{
*/ 
#define StbM_IsGptClockConfigUsedOfLocalClockConfig(Index, partitionIndex)                          (((boolean)(StbM_GetGptClockConfigIdxOfLocalClockConfig(((Index)), (partitionIndex)) != STBM_NO_GPTCLOCKCONFIGIDXOFLOCALCLOCKCONFIG)) != FALSE)  /**< TRUE, if the 0:1 relation has minimum 1 relation pointing to StbM_GptClockConfig */
#define StbM_IsLocalClockConfigUsedOfLocalTimeConfig(Index, partitionIndex)                         (((boolean)(StbM_GetLocalClockConfigIdxOfLocalTimeConfig(((Index)), (partitionIndex)) != STBM_NO_LOCALCLOCKCONFIGIDXOFLOCALTIMECONFIG)) != FALSE)  /**< TRUE, if the 0:1 relation has minimum 1 relation pointing to StbM_LocalClockConfig */
#define StbM_GetSizeOfGptClockConfig(partitionIndex)                                                StbM_GetSizeOfGptClockConfigOfPCPartitionConfig(partitionIndex)
#define StbM_GetSizeOfGptClockState(partitionIndex)                                                 StbM_GetSizeOfGptClockStateOfPCPartitionConfig(partitionIndex)
#define StbM_GetSizeOfLocalClockConfig(partitionIndex)                                              StbM_GetSizeOfLocalClockConfigOfPCPartitionConfig(partitionIndex)
#define StbM_GetSizeOfLocalClockState(partitionIndex)                                               StbM_GetSizeOfLocalClockStateOfPCPartitionConfig(partitionIndex)
#define StbM_GetSizeOfLocalTimeConfig(partitionIndex)                                               StbM_GetSizeOfLocalTimeConfigOfPCPartitionConfig(partitionIndex)
#define StbM_GetSizeOfLocalTimeState(partitionIndex)                                                StbM_GetSizeOfLocalTimeStateOfPCPartitionConfig(partitionIndex)
#define StbM_GetSizeOfMainTimeState(partitionIndex)                                                 StbM_GetSizeOfMainTimeStateOfPCPartitionConfig(partitionIndex)
#define StbM_GetSizeOfPartitionIdentifiers()                                                        StbM_GetSizeOfPartitionIdentifiersOfPCConfig()
#define StbM_GetSizeOfReceivedTimeState(partitionIndex)                                             StbM_GetSizeOfReceivedTimeStateOfPCPartitionConfig(partitionIndex)
#define StbM_GetSizeOfStatus(partitionIndex)                                                        StbM_GetSizeOfStatusOfPCPartitionConfig(partitionIndex)
#define StbM_GetSizeOfSyncTimeRecordingBlock(partitionIndex)                                        StbM_GetSizeOfSyncTimeRecordingBlockOfPCPartitionConfig(partitionIndex)
#define StbM_GetSizeOfSyncTimeRecordingHeader(partitionIndex)                                       StbM_GetSizeOfSyncTimeRecordingHeaderOfPCPartitionConfig(partitionIndex)
#define StbM_GetSizeOfTimeBaseConfig(partitionIndex)                                                StbM_GetSizeOfTimeBaseConfigOfPCPartitionConfig(partitionIndex)
#define StbM_GetSizeOfTimeBasePartitionMapping()                                                    StbM_GetSizeOfTimeBasePartitionMappingOfPCPartitionConfig()
#define StbM_GetSizeOfTimeBaseState(partitionIndex)                                                 StbM_GetSizeOfTimeBaseStateOfPCPartitionConfig(partitionIndex)
#define StbM_GetSizeOfTimeLeapClearState(partitionIndex)                                            StbM_GetSizeOfTimeLeapClearStateOfPCPartitionConfig(partitionIndex)
#define StbM_GetSizeOfTimeLeapConfig(partitionIndex)                                                StbM_GetSizeOfTimeLeapConfigOfPCPartitionConfig(partitionIndex)
#define StbM_GetSizeOfTimeLeapState(partitionIndex)                                                 StbM_GetSizeOfTimeLeapStateOfPCPartitionConfig(partitionIndex)
#define StbM_GetSizeOfTimeRecordingConfig(partitionIndex)                                           StbM_GetSizeOfTimeRecordingConfigOfPCPartitionConfig(partitionIndex)
#define StbM_GetSizeOfTimeRecordingState(partitionIndex)                                            StbM_GetSizeOfTimeRecordingStateOfPCPartitionConfig(partitionIndex)
#define StbM_GetSizeOfTimeRecordingSyncCallback(partitionIndex)                                     StbM_GetSizeOfTimeRecordingSyncCallbackOfPCPartitionConfig(partitionIndex)
#define StbM_GetSizeOfTimeoutConfig(partitionIndex)                                                 StbM_GetSizeOfTimeoutConfigOfPCPartitionConfig(partitionIndex)
#define StbM_GetSizeOfTimeoutState(partitionIndex)                                                  StbM_GetSizeOfTimeoutStateOfPCPartitionConfig(partitionIndex)
#define StbM_GetSizeOfUserDataState(partitionIndex)                                                 StbM_GetSizeOfUserDataStateOfPCPartitionConfig(partitionIndex)
#define StbM_GetSizeOfVirtualLocalTimeState(partitionIndex)                                         StbM_GetSizeOfVirtualLocalTimeStateOfPCPartitionConfig(partitionIndex)
#define StbM_IsTimeLeapConfigUsedOfTimeBaseConfig(Index, partitionIndex)                            (((boolean)(StbM_GetTimeLeapConfigIdxOfTimeBaseConfig(((Index)), (partitionIndex)) != STBM_NO_TIMELEAPCONFIGIDXOFTIMEBASECONFIG)) != FALSE)  /**< TRUE, if the 0:1 relation has minimum 1 relation pointing to StbM_TimeLeapConfig */
#define StbM_IsTimeRecordingConfigUsedOfTimeBaseConfig(Index, partitionIndex)                       (((boolean)(StbM_GetTimeRecordingConfigIdxOfTimeBaseConfig(((Index)), (partitionIndex)) != STBM_NO_TIMERECORDINGCONFIGIDXOFTIMEBASECONFIG)) != FALSE)  /**< TRUE, if the 0:1 relation has minimum 1 relation pointing to StbM_TimeRecordingConfig */
#define StbM_IsTimeoutConfigUsedOfTimeBaseConfig(Index, partitionIndex)                             (((boolean)(StbM_GetTimeoutConfigIdxOfTimeBaseConfig(((Index)), (partitionIndex)) != STBM_NO_TIMEOUTCONFIGIDXOFTIMEBASECONFIG)) != FALSE)  /**< TRUE, if the 0:1 relation has minimum 1 relation pointing to StbM_TimeoutConfig */
#define StbM_IsIndirectionToGptClockStateUsedOfTimeBasePartitionMapping(Index)                      (((boolean)(StbM_GetIndirectionToGptClockStateIdxOfTimeBasePartitionMapping(Index) != STBM_NO_INDIRECTIONTOGPTCLOCKSTATEIDXOFTIMEBASEPARTITIONMAPPING)) != FALSE)  /**< TRUE, if the 0:1 relation has minimum 1 relation pointing to StbM_GptClockState,StbM_GptClockState */
#define StbM_IsIndirectionToLocalClockStateUsedOfTimeBasePartitionMapping(Index)                    (((boolean)(StbM_GetIndirectionToLocalClockStateIdxOfTimeBasePartitionMapping(Index) != STBM_NO_INDIRECTIONTOLOCALCLOCKSTATEIDXOFTIMEBASEPARTITIONMAPPING)) != FALSE)  /**< TRUE, if the 0:1 relation has minimum 1 relation pointing to StbM_LocalClockState,StbM_LocalClockState */
#define StbM_IsSyncTimeRecordingBlockUsedOfTimeRecordingConfig(Index, partitionIndex)               (((boolean)(StbM_GetSyncTimeRecordingBlockStartIdxOfTimeRecordingConfig(((Index)), (partitionIndex)) != STBM_NO_SYNCTIMERECORDINGBLOCKSTARTIDXOFTIMERECORDINGCONFIG)) != FALSE)  /**< TRUE, if the 0:n relation has 1 relation pointing to StbM_SyncTimeRecordingBlock */
#define StbM_IsSyncTimeRecordingHeaderUsedOfTimeRecordingConfig(Index, partitionIndex)              (((boolean)(StbM_GetSyncTimeRecordingHeaderIdxOfTimeRecordingConfig(((Index)), (partitionIndex)) != STBM_NO_SYNCTIMERECORDINGHEADERIDXOFTIMERECORDINGCONFIG)) != FALSE)  /**< TRUE, if the 0:1 relation has minimum 1 relation pointing to StbM_SyncTimeRecordingHeader */
#define StbM_IsTimeBaseConfigUsedOfTimeRecordingConfig(Index, partitionIndex)                       (((boolean)(StbM_GetTimeBaseConfigIdxOfTimeRecordingConfig(((Index)), (partitionIndex)) != STBM_NO_TIMEBASECONFIGIDXOFTIMERECORDINGCONFIG)) != FALSE)  /**< TRUE, if the 0:1 relation has minimum 1 relation pointing to StbM_TimeBaseConfig */
#define StbM_IsTimeRecordingSyncCallbackUsedOfTimeRecordingConfig(Index, partitionIndex)            (((boolean)(StbM_GetTimeRecordingSyncCallbackIdxOfTimeRecordingConfig(((Index)), (partitionIndex)) != STBM_NO_TIMERECORDINGSYNCCALLBACKIDXOFTIMERECORDINGCONFIG)) != FALSE)  /**< TRUE, if the 0:1 relation has minimum 1 relation pointing to StbM_TimeRecordingSyncCallback */
/** 
  \}
*/ 

/** 
  \defgroup  StbMPCSetDataMacros  StbM Set Data Macros (PRE_COMPILE)
  \brief  These macros can be used to write data.
  \{
*/ 
#define StbM_SetGptChannelActiveOfGptClockState(Index, Value, partitionIndex)                       StbM_GetGptClockStateOfPCPartitionConfig(partitionIndex)[(Index)].GptChannelActiveOfGptClockState = (Value)
#define StbM_SetInitialized(Value, partitionIndex)                                                  (*(StbM_GetInitializedOfPCPartitionConfig(partitionIndex))) = (Value)
#define StbM_SetElapsedTimeOfLocalClockState(Index, Value, partitionIndex)                          StbM_GetLocalClockStateOfPCPartitionConfig(partitionIndex)[(Index)].ElapsedTimeOfLocalClockState = (Value)
#define StbM_SetLastReadTimeOfLocalClockState(Index, Value, partitionIndex)                         StbM_GetLocalClockStateOfPCPartitionConfig(partitionIndex)[(Index)].LastReadTimeOfLocalClockState = (Value)
#define StbM_SetLocalTimeOfLocalTimeState(Index, Value, partitionIndex)                             StbM_GetLocalTimeStateOfPCPartitionConfig(partitionIndex)[(Index)].LocalTimeOfLocalTimeState = (Value)
#define StbM_SetLocalTimeUpdatedOfLocalTimeState(Index, Value, partitionIndex)                      StbM_GetLocalTimeStateOfPCPartitionConfig(partitionIndex)[(Index)].LocalTimeUpdatedOfLocalTimeState = (Value)
#define StbM_SetGlobalTimeSyncOfMainTimeState(Index, Value, partitionIndex)                         StbM_GetMainTimeStateOfPCPartitionConfig(partitionIndex)[(Index)].GlobalTimeSyncOfMainTimeState = (Value)
#define StbM_SetVirtualLocalTimeSyncOfMainTimeState(Index, Value, partitionIndex)                   StbM_GetMainTimeStateOfPCPartitionConfig(partitionIndex)[(Index)].VirtualLocalTimeSyncOfMainTimeState = (Value)
#define StbM_SetGlobalTimeRxOfReceivedTimeState(Index, Value, partitionIndex)                       StbM_GetReceivedTimeStateOfPCPartitionConfig(partitionIndex)[(Index)].GlobalTimeRxOfReceivedTimeState = (Value)
#define StbM_SetLocalTimeSyncOfReceivedTimeState(Index, Value, partitionIndex)                      StbM_GetReceivedTimeStateOfPCPartitionConfig(partitionIndex)[(Index)].LocalTimeSyncOfReceivedTimeState = (Value)
#define StbM_SetVirtualLocalTimeRxOfReceivedTimeState(Index, Value, partitionIndex)                 StbM_GetReceivedTimeStateOfPCPartitionConfig(partitionIndex)[(Index)].VirtualLocalTimeRxOfReceivedTimeState = (Value)
#define StbM_SetGlobalTimeStatusOfStatus(Index, Value, partitionIndex)                              StbM_GetStatusOfPCPartitionConfig(partitionIndex)[(Index)].GlobalTimeStatusOfStatus = (Value)
#define StbM_SetLocalTimeStatusOfStatus(Index, Value, partitionIndex)                               StbM_GetStatusOfPCPartitionConfig(partitionIndex)[(Index)].LocalTimeStatusOfStatus = (Value)
#define StbM_SetGlbNanoSecondsOfSyncTimeRecordingBlock(Index, Value, partitionIndex)                StbM_GetSyncTimeRecordingBlockOfPCPartitionConfig(partitionIndex)[(Index)].GlbNanoSecondsOfSyncTimeRecordingBlock = (Value)
#define StbM_SetGlbSecondsOfSyncTimeRecordingBlock(Index, Value, partitionIndex)                    StbM_GetSyncTimeRecordingBlockOfPCPartitionConfig(partitionIndex)[(Index)].GlbSecondsOfSyncTimeRecordingBlock = (Value)
#define StbM_SetLocNanoSecondsOfSyncTimeRecordingBlock(Index, Value, partitionIndex)                StbM_GetSyncTimeRecordingBlockOfPCPartitionConfig(partitionIndex)[(Index)].LocNanoSecondsOfSyncTimeRecordingBlock = (Value)
#define StbM_SetLocSecondsOfSyncTimeRecordingBlock(Index, Value, partitionIndex)                    StbM_GetSyncTimeRecordingBlockOfPCPartitionConfig(partitionIndex)[(Index)].LocSecondsOfSyncTimeRecordingBlock = (Value)
#define StbM_SetPathDelayOfSyncTimeRecordingBlock(Index, Value, partitionIndex)                     StbM_GetSyncTimeRecordingBlockOfPCPartitionConfig(partitionIndex)[(Index)].PathDelayOfSyncTimeRecordingBlock = (Value)
#define StbM_SetRateDeviationOfSyncTimeRecordingBlock(Index, Value, partitionIndex)                 StbM_GetSyncTimeRecordingBlockOfPCPartitionConfig(partitionIndex)[(Index)].RateDeviationOfSyncTimeRecordingBlock = (Value)
#define StbM_SetTimeBaseStatusOfSyncTimeRecordingBlock(Index, Value, partitionIndex)                StbM_GetSyncTimeRecordingBlockOfPCPartitionConfig(partitionIndex)[(Index)].TimeBaseStatusOfSyncTimeRecordingBlock = (Value)
#define StbM_SetVirtualLocalTimeLowOfSyncTimeRecordingBlock(Index, Value, partitionIndex)           StbM_GetSyncTimeRecordingBlockOfPCPartitionConfig(partitionIndex)[(Index)].VirtualLocalTimeLowOfSyncTimeRecordingBlock = (Value)
#define StbM_SetUpdateCounterOfTimeBaseState(Index, Value, partitionIndex)                          StbM_GetTimeBaseStateOfPCPartitionConfig(partitionIndex)[(Index)].UpdateCounterOfTimeBaseState = (Value)
#define StbM_SetClearCountFutureOfTimeLeapClearState(Index, Value, partitionIndex)                  StbM_GetTimeLeapClearStateOfPCPartitionConfig(partitionIndex)[(Index)].ClearCountFutureOfTimeLeapClearState = (Value)
#define StbM_SetClearCountPastOfTimeLeapClearState(Index, Value, partitionIndex)                    StbM_GetTimeLeapClearStateOfPCPartitionConfig(partitionIndex)[(Index)].ClearCountPastOfTimeLeapClearState = (Value)
#define StbM_SetTimeLeapOfTimeLeapState(Index, Value, partitionIndex)                               StbM_GetTimeLeapStateOfPCPartitionConfig(partitionIndex)[(Index)].TimeLeapOfTimeLeapState = (Value)
#define StbM_SetTimeLeapValidOfTimeLeapState(Index, Value, partitionIndex)                          StbM_GetTimeLeapStateOfPCPartitionConfig(partitionIndex)[(Index)].TimeLeapValidOfTimeLeapState = (Value)
#define StbM_SetCurrentBlockIdxOfTimeRecordingState(Index, Value, partitionIndex)                   StbM_GetTimeRecordingStateOfPCPartitionConfig(partitionIndex)[(Index)].CurrentBlockIdxOfTimeRecordingState = (Value)
#define StbM_SetPathDelayOfTimeRecordingState(Index, Value, partitionIndex)                         StbM_GetTimeRecordingStateOfPCPartitionConfig(partitionIndex)[(Index)].PathDelayOfTimeRecordingState = (Value)
#define StbM_SetRecordedBlocksCountOfTimeRecordingState(Index, Value, partitionIndex)               StbM_GetTimeRecordingStateOfPCPartitionConfig(partitionIndex)[(Index)].RecordedBlocksCountOfTimeRecordingState = (Value)
#define StbM_SetSyncLossTimeoutCounterOfTimeoutState(Index, Value, partitionIndex)                  StbM_GetTimeoutStateOfPCPartitionConfig(partitionIndex)[(Index)].SyncLossTimeoutCounterOfTimeoutState = (Value)
#define StbM_SetUserDataOfUserDataState(Index, Value, partitionIndex)                               StbM_GetUserDataStateOfPCPartitionConfig(partitionIndex)[(Index)].UserDataOfUserDataState = (Value)
#define StbM_SetVirtualLocalTimeElapsedAfterAdaptionIntervalOfVirtualLocalTimeState(Index, Value, partitionIndex) StbM_GetVirtualLocalTimeStateOfPCPartitionConfig(partitionIndex)[(Index)].VirtualLocalTimeElapsedAfterAdaptionIntervalOfVirtualLocalTimeState = (Value)
#define StbM_SetVirtualLocalTimeOfVirtualLocalTimeState(Index, Value, partitionIndex)               StbM_GetVirtualLocalTimeStateOfPCPartitionConfig(partitionIndex)[(Index)].VirtualLocalTimeOfVirtualLocalTimeState = (Value)
/** 
  \}
*/ 

/** 
  \defgroup  StbMPCGetAddressOfDataMacros  StbM Get Address Of Data Macros (PRE_COMPILE)
  \brief  These macros can be used to get the data by the address operator.
  \{
*/ 
#define StbM_GetAddrUserDataOfUserDataState(Index, partitionIndex)                                  (&StbM_GetUserDataOfUserDataState(((Index)), (partitionIndex)))
/** 
  \}
*/ 

/** 
  \defgroup  StbMPCHasMacros  StbM Has Macros (PRE_COMPILE)
  \brief  These macros can be used to detect at runtime a deactivated piece of information. TRUE in the CONFIGURATION_VARIANT PRE-COMPILE, TRUE or FALSE in the CONFIGURATION_VARIANT POST-BUILD.
  \{
*/ 
#define StbM_HasGptClockConfig(partitionIndex)                                                      (StbM_GetGptClockConfigOfPCPartitionConfig(partitionIndex) != NULL_PTR)
#define StbM_HasGptChannelSymbolicNameOfGptClockConfig(partitionIndex)                              (TRUE != FALSE)
#define StbM_HasMaxTickValueOfGptClockConfig(partitionIndex)                                        (TRUE != FALSE)
#define StbM_HasGptClockState(partitionIndex)                                                       (StbM_GetGptClockStateOfPCPartitionConfig(partitionIndex) != NULL_PTR)
#define StbM_HasGptChannelActiveOfGptClockState(partitionIndex)                                     (TRUE != FALSE)
#define StbM_HasInitialized(partitionIndex)                                                         (StbM_GetInitializedOfPCPartitionConfig(partitionIndex) != NULL_PTR)
#define StbM_HasLocalClockConfig(partitionIndex)                                                    (StbM_GetLocalClockConfigOfPCPartitionConfig(partitionIndex) != NULL_PTR)
#define StbM_HasClockTypeOfLocalClockConfig(partitionIndex)                                         (TRUE != FALSE)
#define StbM_HasDenominatorOfFactorClockTicksToLocalTimeOfLocalClockConfig(partitionIndex)          (TRUE != FALSE)
#define StbM_HasGptClockConfigIdxOfLocalClockConfig(partitionIndex)                                 (TRUE != FALSE)
#define StbM_HasGptClockConfigUsedOfLocalClockConfig(partitionIndex)                                (TRUE != FALSE)
#define StbM_HasHwFrequencyOfLocalClockConfig(partitionIndex)                                       (TRUE != FALSE)
#define StbM_HasHwPrescalerOfLocalClockConfig(partitionIndex)                                       (TRUE != FALSE)
#define StbM_HasNumeratorOfFactorClockTicksToLocalTimeOfLocalClockConfig(partitionIndex)            (TRUE != FALSE)
#define StbM_HasTimeBasePartitionMappingIdxOfLocalClockConfig(partitionIndex)                       (TRUE != FALSE)
#define StbM_HasLocalClockState(partitionIndex)                                                     (StbM_GetLocalClockStateOfPCPartitionConfig(partitionIndex) != NULL_PTR)
#define StbM_HasElapsedTimeOfLocalClockState(partitionIndex)                                        (TRUE != FALSE)
#define StbM_HasLastReadTimeOfLocalClockState(partitionIndex)                                       (TRUE != FALSE)
#define StbM_HasLocalTimeConfig(partitionIndex)                                                     (StbM_GetLocalTimeConfigOfPCPartitionConfig(partitionIndex) != NULL_PTR)
#define StbM_HasLocalClockConfigIdxOfLocalTimeConfig(partitionIndex)                                (TRUE != FALSE)
#define StbM_HasLocalClockConfigUsedOfLocalTimeConfig(partitionIndex)                               (TRUE != FALSE)
#define StbM_HasTimeBaseConfigIdxOfLocalTimeConfig(partitionIndex)                                  (TRUE != FALSE)
#define StbM_HasTimeBasePartitionMappingIdxOfLocalTimeConfig(partitionIndex)                        (TRUE != FALSE)
#define StbM_HasLocalTimeState(partitionIndex)                                                      (StbM_GetLocalTimeStateOfPCPartitionConfig(partitionIndex) != NULL_PTR)
#define StbM_HasLocalTimeOfLocalTimeState(partitionIndex)                                           (TRUE != FALSE)
#define StbM_HasLocalTimeUpdatedOfLocalTimeState(partitionIndex)                                    (TRUE != FALSE)
#define StbM_HasMainTimeState(partitionIndex)                                                       (StbM_GetMainTimeStateOfPCPartitionConfig(partitionIndex) != NULL_PTR)
#define StbM_HasGlobalTimeSyncOfMainTimeState(partitionIndex)                                       (TRUE != FALSE)
#define StbM_HasVirtualLocalTimeSyncOfMainTimeState(partitionIndex)                                 (TRUE != FALSE)
#define StbM_HasPartitionIdentifiers()                                                              (TRUE != FALSE)
#define StbM_HasPCPartitionConfigIdxOfPartitionIdentifiers()                                        (TRUE != FALSE)
#define StbM_HasPartitionSNVOfPartitionIdentifiers()                                                (TRUE != FALSE)
#define StbM_HasReceivedTimeState(partitionIndex)                                                   (StbM_GetReceivedTimeStateOfPCPartitionConfig(partitionIndex) != NULL_PTR)
#define StbM_HasGlobalTimeRxOfReceivedTimeState(partitionIndex)                                     (TRUE != FALSE)
#define StbM_HasLocalTimeSyncOfReceivedTimeState(partitionIndex)                                    (TRUE != FALSE)
#define StbM_HasVirtualLocalTimeRxOfReceivedTimeState(partitionIndex)                               (TRUE != FALSE)
#define StbM_HasSizeOfGptClockConfig(partitionIndex)                                                (TRUE != FALSE)
#define StbM_HasSizeOfGptClockState(partitionIndex)                                                 (TRUE != FALSE)
#define StbM_HasSizeOfLocalClockConfig(partitionIndex)                                              (TRUE != FALSE)
#define StbM_HasSizeOfLocalClockState(partitionIndex)                                               (TRUE != FALSE)
#define StbM_HasSizeOfLocalTimeConfig(partitionIndex)                                               (TRUE != FALSE)
#define StbM_HasSizeOfLocalTimeState(partitionIndex)                                                (TRUE != FALSE)
#define StbM_HasSizeOfMainTimeState(partitionIndex)                                                 (TRUE != FALSE)
#define StbM_HasSizeOfPartitionIdentifiers()                                                        (TRUE != FALSE)
#define StbM_HasSizeOfReceivedTimeState(partitionIndex)                                             (TRUE != FALSE)
#define StbM_HasSizeOfStatus(partitionIndex)                                                        (TRUE != FALSE)
#define StbM_HasSizeOfSyncTimeRecordingBlock(partitionIndex)                                        (TRUE != FALSE)
#define StbM_HasSizeOfSyncTimeRecordingHeader(partitionIndex)                                       (TRUE != FALSE)
#define StbM_HasSizeOfTimeBaseConfig(partitionIndex)                                                (TRUE != FALSE)
#define StbM_HasSizeOfTimeBasePartitionMapping()                                                    (TRUE != FALSE)
#define StbM_HasSizeOfTimeBaseState(partitionIndex)                                                 (TRUE != FALSE)
#define StbM_HasSizeOfTimeLeapClearState(partitionIndex)                                            (TRUE != FALSE)
#define StbM_HasSizeOfTimeLeapConfig(partitionIndex)                                                (TRUE != FALSE)
#define StbM_HasSizeOfTimeLeapState(partitionIndex)                                                 (TRUE != FALSE)
#define StbM_HasSizeOfTimeRecordingConfig(partitionIndex)                                           (TRUE != FALSE)
#define StbM_HasSizeOfTimeRecordingState(partitionIndex)                                            (TRUE != FALSE)
#define StbM_HasSizeOfTimeRecordingSyncCallback(partitionIndex)                                     (TRUE != FALSE)
#define StbM_HasSizeOfTimeoutConfig(partitionIndex)                                                 (TRUE != FALSE)
#define StbM_HasSizeOfTimeoutState(partitionIndex)                                                  (TRUE != FALSE)
#define StbM_HasSizeOfUserDataState(partitionIndex)                                                 (TRUE != FALSE)
#define StbM_HasSizeOfVirtualLocalTimeState(partitionIndex)                                         (TRUE != FALSE)
#define StbM_HasStatus(partitionIndex)                                                              (StbM_GetStatusOfPCPartitionConfig(partitionIndex) != NULL_PTR)
#define StbM_HasGlobalTimeStatusOfStatus(partitionIndex)                                            (TRUE != FALSE)
#define StbM_HasLocalTimeStatusOfStatus(partitionIndex)                                             (TRUE != FALSE)
#define StbM_HasSyncTimeRecordingBlock(partitionIndex)                                              (StbM_GetSyncTimeRecordingBlockOfPCPartitionConfig(partitionIndex) != NULL_PTR)
#define StbM_HasGlbNanoSecondsOfSyncTimeRecordingBlock(partitionIndex)                              (TRUE != FALSE)
#define StbM_HasGlbSecondsOfSyncTimeRecordingBlock(partitionIndex)                                  (TRUE != FALSE)
#define StbM_HasLocNanoSecondsOfSyncTimeRecordingBlock(partitionIndex)                              (TRUE != FALSE)
#define StbM_HasLocSecondsOfSyncTimeRecordingBlock(partitionIndex)                                  (TRUE != FALSE)
#define StbM_HasPathDelayOfSyncTimeRecordingBlock(partitionIndex)                                   (TRUE != FALSE)
#define StbM_HasRateDeviationOfSyncTimeRecordingBlock(partitionIndex)                               (TRUE != FALSE)
#define StbM_HasTimeBaseStatusOfSyncTimeRecordingBlock(partitionIndex)                              (TRUE != FALSE)
#define StbM_HasVirtualLocalTimeLowOfSyncTimeRecordingBlock(partitionIndex)                         (TRUE != FALSE)
#define StbM_HasSyncTimeRecordingHeader(partitionIndex)                                             (StbM_GetSyncTimeRecordingHeaderOfPCPartitionConfig(partitionIndex) != NULL_PTR)
#define StbM_HasHwFrequencyOfSyncTimeRecordingHeader(partitionIndex)                                (TRUE != FALSE)
#define StbM_HasHwPrescalerOfSyncTimeRecordingHeader(partitionIndex)                                (TRUE != FALSE)
#define StbM_HasTimeDomainOfSyncTimeRecordingHeader(partitionIndex)                                 (TRUE != FALSE)
#define StbM_HasTimeBaseConfig(partitionIndex)                                                      (StbM_GetTimeBaseConfigOfPCPartitionConfig(partitionIndex) != NULL_PTR)
#define StbM_HasLocalTimeConfigIdxOfTimeBaseConfig(partitionIndex)                                  (TRUE != FALSE)
#define StbM_HasPartitionConfigIdxOfTimeBaseConfig(partitionIndex)                                  (TRUE != FALSE)
#define StbM_HasStatusIdxOfTimeBaseConfig(partitionIndex)                                           (TRUE != FALSE)
#define StbM_HasSynchronizedTimeBaseOfTimeBaseConfig(partitionIndex)                                (TRUE != FALSE)
#define StbM_HasTimeBaseIdOfTimeBaseConfig(partitionIndex)                                          (TRUE != FALSE)
#define StbM_HasTimeLeapConfigIdxOfTimeBaseConfig(partitionIndex)                                   (TRUE != FALSE)
#define StbM_HasTimeLeapConfigUsedOfTimeBaseConfig(partitionIndex)                                  (TRUE != FALSE)
#define StbM_HasTimeRecordingConfigIdxOfTimeBaseConfig(partitionIndex)                              (TRUE != FALSE)
#define StbM_HasTimeRecordingConfigUsedOfTimeBaseConfig(partitionIndex)                             (TRUE != FALSE)
#define StbM_HasTimeSlaveOfTimeBaseConfig(partitionIndex)                                           (TRUE != FALSE)
#define StbM_HasTimeoutConfigIdxOfTimeBaseConfig(partitionIndex)                                    (TRUE != FALSE)
#define StbM_HasTimeoutConfigUsedOfTimeBaseConfig(partitionIndex)                                   (TRUE != FALSE)
#define StbM_HasUserDataStateIdxOfTimeBaseConfig(partitionIndex)                                    (TRUE != FALSE)
#define StbM_HasTimeBasePartitionMapping()                                                          (TRUE != FALSE)
#define StbM_HasIndirectionToGptClockStateIdxOfTimeBasePartitionMapping()                           (TRUE != FALSE)
#define StbM_HasIndirectionToGptClockStatePartitionIdxOfTimeBasePartitionMapping()                  (TRUE != FALSE)
#define StbM_HasIndirectionToGptClockStateUsedOfTimeBasePartitionMapping()                          (TRUE != FALSE)
#define StbM_HasIndirectionToLocalClockStateIdxOfTimeBasePartitionMapping()                         (TRUE != FALSE)
#define StbM_HasIndirectionToLocalClockStatePartitionIdxOfTimeBasePartitionMapping()                (TRUE != FALSE)
#define StbM_HasIndirectionToLocalClockStateUsedOfTimeBasePartitionMapping()                        (TRUE != FALSE)
#define StbM_HasIndirectionToLocalTimeStateIdxOfTimeBasePartitionMapping()                          (TRUE != FALSE)
#define StbM_HasIndirectionToLocalTimeStatePartitionIdxOfTimeBasePartitionMapping()                 (TRUE != FALSE)
#define StbM_HasIndirectionToMainTimeStateIdxOfTimeBasePartitionMapping()                           (TRUE != FALSE)
#define StbM_HasIndirectionToMainTimeStatePartitionIdxOfTimeBasePartitionMapping()                  (TRUE != FALSE)
#define StbM_HasIndirectionToTimeBaseConfigIdxOfTimeBasePartitionMapping()                          (TRUE != FALSE)
#define StbM_HasIndirectionToTimeBaseConfigPartitionIdxOfTimeBasePartitionMapping()                 (TRUE != FALSE)
#define StbM_HasIndirectionToVirtualLocalTimeStateIdxOfTimeBasePartitionMapping()                   (TRUE != FALSE)
#define StbM_HasIndirectionToVirtualLocalTimeStatePartitionIdxOfTimeBasePartitionMapping()          (TRUE != FALSE)
#define StbM_HasTimeBaseState(partitionIndex)                                                       (StbM_GetTimeBaseStateOfPCPartitionConfig(partitionIndex) != NULL_PTR)
#define StbM_HasUpdateCounterOfTimeBaseState(partitionIndex)                                        (TRUE != FALSE)
#define StbM_HasTimeLeapClearState(partitionIndex)                                                  (StbM_GetTimeLeapClearStateOfPCPartitionConfig(partitionIndex) != NULL_PTR)
#define StbM_HasClearCountFutureOfTimeLeapClearState(partitionIndex)                                (TRUE != FALSE)
#define StbM_HasClearCountPastOfTimeLeapClearState(partitionIndex)                                  (TRUE != FALSE)
#define StbM_HasTimeLeapConfig(partitionIndex)                                                      (StbM_GetTimeLeapConfigOfPCPartitionConfig(partitionIndex) != NULL_PTR)
#define StbM_HasClearCountOfTimeLeapConfig(partitionIndex)                                          (TRUE != FALSE)
#define StbM_HasFutureThresholdOfTimeLeapConfig(partitionIndex)                                     (TRUE != FALSE)
#define StbM_HasPastThresholdOfTimeLeapConfig(partitionIndex)                                       (TRUE != FALSE)
#define StbM_HasTimeLeapState(partitionIndex)                                                       (StbM_GetTimeLeapStateOfPCPartitionConfig(partitionIndex) != NULL_PTR)
#define StbM_HasTimeLeapOfTimeLeapState(partitionIndex)                                             (TRUE != FALSE)
#define StbM_HasTimeLeapValidOfTimeLeapState(partitionIndex)                                        (TRUE != FALSE)
#define StbM_HasTimeRecordingConfig(partitionIndex)                                                 (StbM_GetTimeRecordingConfigOfPCPartitionConfig(partitionIndex) != NULL_PTR)
#define StbM_HasBlockCountOfTimeRecordingConfig(partitionIndex)                                     (TRUE != FALSE)
#define StbM_HasSyncTimeRecordingBlockEndIdxOfTimeRecordingConfig(partitionIndex)                   (TRUE != FALSE)
#define StbM_HasSyncTimeRecordingBlockStartIdxOfTimeRecordingConfig(partitionIndex)                 (TRUE != FALSE)
#define StbM_HasSyncTimeRecordingBlockUsedOfTimeRecordingConfig(partitionIndex)                     (TRUE != FALSE)
#define StbM_HasSyncTimeRecordingHeaderIdxOfTimeRecordingConfig(partitionIndex)                     (TRUE != FALSE)
#define StbM_HasSyncTimeRecordingHeaderUsedOfTimeRecordingConfig(partitionIndex)                    (TRUE != FALSE)
#define StbM_HasTimeBaseConfigIdxOfTimeRecordingConfig(partitionIndex)                              (TRUE != FALSE)
#define StbM_HasTimeBaseConfigUsedOfTimeRecordingConfig(partitionIndex)                             (TRUE != FALSE)
#define StbM_HasTimeRecordingSyncCallbackIdxOfTimeRecordingConfig(partitionIndex)                   (TRUE != FALSE)
#define StbM_HasTimeRecordingSyncCallbackUsedOfTimeRecordingConfig(partitionIndex)                  (TRUE != FALSE)
#define StbM_HasTimeRecordingState(partitionIndex)                                                  (StbM_GetTimeRecordingStateOfPCPartitionConfig(partitionIndex) != NULL_PTR)
#define StbM_HasCurrentBlockIdxOfTimeRecordingState(partitionIndex)                                 (TRUE != FALSE)
#define StbM_HasPathDelayOfTimeRecordingState(partitionIndex)                                       (TRUE != FALSE)
#define StbM_HasRecordedBlocksCountOfTimeRecordingState(partitionIndex)                             (TRUE != FALSE)
#define StbM_HasTimeRecordingSyncCallback(partitionIndex)                                           (StbM_GetTimeRecordingSyncCallbackOfPCPartitionConfig(partitionIndex) != NULL_PTR)
#define StbM_HasCallbackOfTimeRecordingSyncCallback(partitionIndex)                                 (TRUE != FALSE)
#define StbM_HasTimeoutConfig(partitionIndex)                                                       (StbM_GetTimeoutConfigOfPCPartitionConfig(partitionIndex) != NULL_PTR)
#define StbM_HasSyncLossTimeoutCounterOfTimeoutConfig(partitionIndex)                               (TRUE != FALSE)
#define StbM_HasTimeBaseConfigIdxOfTimeoutConfig(partitionIndex)                                    (TRUE != FALSE)
#define StbM_HasTimeoutState(partitionIndex)                                                        (StbM_GetTimeoutStateOfPCPartitionConfig(partitionIndex) != NULL_PTR)
#define StbM_HasSyncLossTimeoutCounterOfTimeoutState(partitionIndex)                                (TRUE != FALSE)
#define StbM_HasUserDataState(partitionIndex)                                                       (StbM_GetUserDataStateOfPCPartitionConfig(partitionIndex) != NULL_PTR)
#define StbM_HasUserDataOfUserDataState(partitionIndex)                                             (TRUE != FALSE)
#define StbM_HasVirtualLocalTimeState(partitionIndex)                                               (StbM_GetVirtualLocalTimeStateOfPCPartitionConfig(partitionIndex) != NULL_PTR)
#define StbM_HasVirtualLocalTimeElapsedAfterAdaptionIntervalOfVirtualLocalTimeState(partitionIndex) (TRUE != FALSE)
#define StbM_HasVirtualLocalTimeOfVirtualLocalTimeState(partitionIndex)                             (TRUE != FALSE)
#define StbM_HasPCConfig()                                                                          (TRUE != FALSE)
#define StbM_HasPCPartitionConfigOfPCConfig()                                                       (TRUE != FALSE)
#define StbM_HasPartitionIdentifiersOfPCConfig()                                                    (TRUE != FALSE)
#define StbM_HasSizeOfPartitionIdentifiersOfPCConfig()                                              (TRUE != FALSE)
#define StbM_HasPCPartitionConfig()                                                                 (TRUE != FALSE)
#define StbM_HasGptClockConfigOfPCPartitionConfig(partitionIndex)                                   (TRUE != FALSE)
#define StbM_HasGptClockStateOfPCPartitionConfig(partitionIndex)                                    (TRUE != FALSE)
#define StbM_HasInitializedOfPCPartitionConfig(partitionIndex)                                      (TRUE != FALSE)
#define StbM_HasLocalClockConfigOfPCPartitionConfig(partitionIndex)                                 (TRUE != FALSE)
#define StbM_HasLocalClockStateOfPCPartitionConfig(partitionIndex)                                  (TRUE != FALSE)
#define StbM_HasLocalTimeConfigOfPCPartitionConfig(partitionIndex)                                  (TRUE != FALSE)
#define StbM_HasLocalTimeStateOfPCPartitionConfig(partitionIndex)                                   (TRUE != FALSE)
#define StbM_HasMainTimeStateOfPCPartitionConfig(partitionIndex)                                    (TRUE != FALSE)
#define StbM_HasReceivedTimeStateOfPCPartitionConfig(partitionIndex)                                (TRUE != FALSE)
#define StbM_HasSizeOfGptClockConfigOfPCPartitionConfig(partitionIndex)                             (TRUE != FALSE)
#define StbM_HasSizeOfGptClockStateOfPCPartitionConfig(partitionIndex)                              (TRUE != FALSE)
#define StbM_HasSizeOfLocalClockConfigOfPCPartitionConfig(partitionIndex)                           (TRUE != FALSE)
#define StbM_HasSizeOfLocalClockStateOfPCPartitionConfig(partitionIndex)                            (TRUE != FALSE)
#define StbM_HasSizeOfLocalTimeConfigOfPCPartitionConfig(partitionIndex)                            (TRUE != FALSE)
#define StbM_HasSizeOfLocalTimeStateOfPCPartitionConfig(partitionIndex)                             (TRUE != FALSE)
#define StbM_HasSizeOfMainTimeStateOfPCPartitionConfig(partitionIndex)                              (TRUE != FALSE)
#define StbM_HasSizeOfReceivedTimeStateOfPCPartitionConfig(partitionIndex)                          (TRUE != FALSE)
#define StbM_HasSizeOfStatusOfPCPartitionConfig(partitionIndex)                                     (TRUE != FALSE)
#define StbM_HasSizeOfSyncTimeRecordingBlockOfPCPartitionConfig(partitionIndex)                     (TRUE != FALSE)
#define StbM_HasSizeOfSyncTimeRecordingHeaderOfPCPartitionConfig(partitionIndex)                    (TRUE != FALSE)
#define StbM_HasSizeOfTimeBaseConfigOfPCPartitionConfig(partitionIndex)                             (TRUE != FALSE)
#define StbM_HasSizeOfTimeBasePartitionMappingOfPCPartitionConfig()                                 (TRUE != FALSE)
#define StbM_HasSizeOfTimeBaseStateOfPCPartitionConfig(partitionIndex)                              (TRUE != FALSE)
#define StbM_HasSizeOfTimeLeapClearStateOfPCPartitionConfig(partitionIndex)                         (TRUE != FALSE)
#define StbM_HasSizeOfTimeLeapConfigOfPCPartitionConfig(partitionIndex)                             (TRUE != FALSE)
#define StbM_HasSizeOfTimeLeapStateOfPCPartitionConfig(partitionIndex)                              (TRUE != FALSE)
#define StbM_HasSizeOfTimeRecordingConfigOfPCPartitionConfig(partitionIndex)                        (TRUE != FALSE)
#define StbM_HasSizeOfTimeRecordingStateOfPCPartitionConfig(partitionIndex)                         (TRUE != FALSE)
#define StbM_HasSizeOfTimeRecordingSyncCallbackOfPCPartitionConfig(partitionIndex)                  (TRUE != FALSE)
#define StbM_HasSizeOfTimeoutConfigOfPCPartitionConfig(partitionIndex)                              (TRUE != FALSE)
#define StbM_HasSizeOfTimeoutStateOfPCPartitionConfig(partitionIndex)                               (TRUE != FALSE)
#define StbM_HasSizeOfUserDataStateOfPCPartitionConfig(partitionIndex)                              (TRUE != FALSE)
#define StbM_HasSizeOfVirtualLocalTimeStateOfPCPartitionConfig(partitionIndex)                      (TRUE != FALSE)
#define StbM_HasStatusOfPCPartitionConfig(partitionIndex)                                           (TRUE != FALSE)
#define StbM_HasSyncTimeRecordingBlockOfPCPartitionConfig(partitionIndex)                           (TRUE != FALSE)
#define StbM_HasSyncTimeRecordingHeaderOfPCPartitionConfig(partitionIndex)                          (TRUE != FALSE)
#define StbM_HasTimeBaseConfigOfPCPartitionConfig(partitionIndex)                                   (TRUE != FALSE)
#define StbM_HasTimeBasePartitionMappingOfPCPartitionConfig()                                       (TRUE != FALSE)
#define StbM_HasTimeBaseStateOfPCPartitionConfig(partitionIndex)                                    (TRUE != FALSE)
#define StbM_HasTimeLeapClearStateOfPCPartitionConfig(partitionIndex)                               (TRUE != FALSE)
#define StbM_HasTimeLeapConfigOfPCPartitionConfig(partitionIndex)                                   (TRUE != FALSE)
#define StbM_HasTimeLeapStateOfPCPartitionConfig(partitionIndex)                                    (TRUE != FALSE)
#define StbM_HasTimeRecordingConfigOfPCPartitionConfig(partitionIndex)                              (TRUE != FALSE)
#define StbM_HasTimeRecordingStateOfPCPartitionConfig(partitionIndex)                               (TRUE != FALSE)
#define StbM_HasTimeRecordingSyncCallbackOfPCPartitionConfig(partitionIndex)                        (TRUE != FALSE)
#define StbM_HasTimeoutConfigOfPCPartitionConfig(partitionIndex)                                    (TRUE != FALSE)
#define StbM_HasTimeoutStateOfPCPartitionConfig(partitionIndex)                                     (TRUE != FALSE)
#define StbM_HasUserDataStateOfPCPartitionConfig(partitionIndex)                                    (TRUE != FALSE)
#define StbM_HasVirtualLocalTimeStateOfPCPartitionConfig(partitionIndex)                            (TRUE != FALSE)
/** 
  \}
*/ 

/** 
  \defgroup  StbMPCIncrementDataMacros  StbM Increment Data Macros (PRE_COMPILE)
  \brief  These macros can be used to increment VAR data with numerical nature.
  \{
*/ 
#define StbM_IncLocalTimeUpdatedOfLocalTimeState(Index, partitionIndex)                             StbM_GetLocalTimeUpdatedOfLocalTimeState(((Index)), (partitionIndex))++
#define StbM_IncGlobalTimeStatusOfStatus(Index, partitionIndex)                                     StbM_GetGlobalTimeStatusOfStatus(((Index)), (partitionIndex))++
#define StbM_IncLocalTimeStatusOfStatus(Index, partitionIndex)                                      StbM_GetLocalTimeStatusOfStatus(((Index)), (partitionIndex))++
#define StbM_IncGlbNanoSecondsOfSyncTimeRecordingBlock(Index, partitionIndex)                       StbM_GetGlbNanoSecondsOfSyncTimeRecordingBlock(((Index)), (partitionIndex))++
#define StbM_IncGlbSecondsOfSyncTimeRecordingBlock(Index, partitionIndex)                           StbM_GetGlbSecondsOfSyncTimeRecordingBlock(((Index)), (partitionIndex))++
#define StbM_IncLocNanoSecondsOfSyncTimeRecordingBlock(Index, partitionIndex)                       StbM_GetLocNanoSecondsOfSyncTimeRecordingBlock(((Index)), (partitionIndex))++
#define StbM_IncLocSecondsOfSyncTimeRecordingBlock(Index, partitionIndex)                           StbM_GetLocSecondsOfSyncTimeRecordingBlock(((Index)), (partitionIndex))++
#define StbM_IncPathDelayOfSyncTimeRecordingBlock(Index, partitionIndex)                            StbM_GetPathDelayOfSyncTimeRecordingBlock(((Index)), (partitionIndex))++
#define StbM_IncRateDeviationOfSyncTimeRecordingBlock(Index, partitionIndex)                        StbM_GetRateDeviationOfSyncTimeRecordingBlock(((Index)), (partitionIndex))++
#define StbM_IncTimeBaseStatusOfSyncTimeRecordingBlock(Index, partitionIndex)                       StbM_GetTimeBaseStatusOfSyncTimeRecordingBlock(((Index)), (partitionIndex))++
#define StbM_IncVirtualLocalTimeLowOfSyncTimeRecordingBlock(Index, partitionIndex)                  StbM_GetVirtualLocalTimeLowOfSyncTimeRecordingBlock(((Index)), (partitionIndex))++
#define StbM_IncUpdateCounterOfTimeBaseState(Index, partitionIndex)                                 StbM_GetUpdateCounterOfTimeBaseState(((Index)), (partitionIndex))++
#define StbM_IncClearCountFutureOfTimeLeapClearState(Index, partitionIndex)                         StbM_GetClearCountFutureOfTimeLeapClearState(((Index)), (partitionIndex))++
#define StbM_IncClearCountPastOfTimeLeapClearState(Index, partitionIndex)                           StbM_GetClearCountPastOfTimeLeapClearState(((Index)), (partitionIndex))++
#define StbM_IncTimeLeapOfTimeLeapState(Index, partitionIndex)                                      StbM_GetTimeLeapOfTimeLeapState(((Index)), (partitionIndex))++
#define StbM_IncCurrentBlockIdxOfTimeRecordingState(Index, partitionIndex)                          StbM_GetCurrentBlockIdxOfTimeRecordingState(((Index)), (partitionIndex))++
#define StbM_IncPathDelayOfTimeRecordingState(Index, partitionIndex)                                StbM_GetPathDelayOfTimeRecordingState(((Index)), (partitionIndex))++
#define StbM_IncRecordedBlocksCountOfTimeRecordingState(Index, partitionIndex)                      StbM_GetRecordedBlocksCountOfTimeRecordingState(((Index)), (partitionIndex))++
#define StbM_IncSyncLossTimeoutCounterOfTimeoutState(Index, partitionIndex)                         StbM_GetSyncLossTimeoutCounterOfTimeoutState(((Index)), (partitionIndex))++
/** 
  \}
*/ 

/** 
  \defgroup  StbMPCDecrementDataMacros  StbM Decrement Data Macros (PRE_COMPILE)
  \brief  These macros can be used to decrement VAR data with numerical nature.
  \{
*/ 
#define StbM_DecLocalTimeUpdatedOfLocalTimeState(Index, partitionIndex)                             StbM_GetLocalTimeUpdatedOfLocalTimeState(((Index)), (partitionIndex))--
#define StbM_DecGlobalTimeStatusOfStatus(Index, partitionIndex)                                     StbM_GetGlobalTimeStatusOfStatus(((Index)), (partitionIndex))--
#define StbM_DecLocalTimeStatusOfStatus(Index, partitionIndex)                                      StbM_GetLocalTimeStatusOfStatus(((Index)), (partitionIndex))--
#define StbM_DecGlbNanoSecondsOfSyncTimeRecordingBlock(Index, partitionIndex)                       StbM_GetGlbNanoSecondsOfSyncTimeRecordingBlock(((Index)), (partitionIndex))--
#define StbM_DecGlbSecondsOfSyncTimeRecordingBlock(Index, partitionIndex)                           StbM_GetGlbSecondsOfSyncTimeRecordingBlock(((Index)), (partitionIndex))--
#define StbM_DecLocNanoSecondsOfSyncTimeRecordingBlock(Index, partitionIndex)                       StbM_GetLocNanoSecondsOfSyncTimeRecordingBlock(((Index)), (partitionIndex))--
#define StbM_DecLocSecondsOfSyncTimeRecordingBlock(Index, partitionIndex)                           StbM_GetLocSecondsOfSyncTimeRecordingBlock(((Index)), (partitionIndex))--
#define StbM_DecPathDelayOfSyncTimeRecordingBlock(Index, partitionIndex)                            StbM_GetPathDelayOfSyncTimeRecordingBlock(((Index)), (partitionIndex))--
#define StbM_DecRateDeviationOfSyncTimeRecordingBlock(Index, partitionIndex)                        StbM_GetRateDeviationOfSyncTimeRecordingBlock(((Index)), (partitionIndex))--
#define StbM_DecTimeBaseStatusOfSyncTimeRecordingBlock(Index, partitionIndex)                       StbM_GetTimeBaseStatusOfSyncTimeRecordingBlock(((Index)), (partitionIndex))--
#define StbM_DecVirtualLocalTimeLowOfSyncTimeRecordingBlock(Index, partitionIndex)                  StbM_GetVirtualLocalTimeLowOfSyncTimeRecordingBlock(((Index)), (partitionIndex))--
#define StbM_DecUpdateCounterOfTimeBaseState(Index, partitionIndex)                                 StbM_GetUpdateCounterOfTimeBaseState(((Index)), (partitionIndex))--
#define StbM_DecClearCountFutureOfTimeLeapClearState(Index, partitionIndex)                         StbM_GetClearCountFutureOfTimeLeapClearState(((Index)), (partitionIndex))--
#define StbM_DecClearCountPastOfTimeLeapClearState(Index, partitionIndex)                           StbM_GetClearCountPastOfTimeLeapClearState(((Index)), (partitionIndex))--
#define StbM_DecTimeLeapOfTimeLeapState(Index, partitionIndex)                                      StbM_GetTimeLeapOfTimeLeapState(((Index)), (partitionIndex))--
#define StbM_DecCurrentBlockIdxOfTimeRecordingState(Index, partitionIndex)                          StbM_GetCurrentBlockIdxOfTimeRecordingState(((Index)), (partitionIndex))--
#define StbM_DecPathDelayOfTimeRecordingState(Index, partitionIndex)                                StbM_GetPathDelayOfTimeRecordingState(((Index)), (partitionIndex))--
#define StbM_DecRecordedBlocksCountOfTimeRecordingState(Index, partitionIndex)                      StbM_GetRecordedBlocksCountOfTimeRecordingState(((Index)), (partitionIndex))--
#define StbM_DecSyncLossTimeoutCounterOfTimeoutState(Index, partitionIndex)                         StbM_GetSyncLossTimeoutCounterOfTimeoutState(((Index)), (partitionIndex))--
/** 
  \}
*/ 

/** 
  \defgroup  StbMPCAddDataMacros  StbM Add Data Macros (PRE_COMPILE)
  \brief  These macros can be used to add VAR data with numerical nature.
  \{
*/ 
#define StbM_AddLocalTimeUpdatedOfLocalTimeState(Index, Value, partitionIndex)                      StbM_SetLocalTimeUpdatedOfLocalTimeState(Index, (StbM_GetLocalTimeUpdatedOfLocalTimeState(((Index)), (partitionIndex)) + Value), partitionIndex)
#define StbM_AddGlobalTimeStatusOfStatus(Index, Value, partitionIndex)                              StbM_SetGlobalTimeStatusOfStatus(Index, (StbM_GetGlobalTimeStatusOfStatus(((Index)), (partitionIndex)) + Value), partitionIndex)
#define StbM_AddLocalTimeStatusOfStatus(Index, Value, partitionIndex)                               StbM_SetLocalTimeStatusOfStatus(Index, (StbM_GetLocalTimeStatusOfStatus(((Index)), (partitionIndex)) + Value), partitionIndex)
#define StbM_AddGlbNanoSecondsOfSyncTimeRecordingBlock(Index, Value, partitionIndex)                StbM_SetGlbNanoSecondsOfSyncTimeRecordingBlock(Index, (StbM_GetGlbNanoSecondsOfSyncTimeRecordingBlock(((Index)), (partitionIndex)) + Value), partitionIndex)
#define StbM_AddGlbSecondsOfSyncTimeRecordingBlock(Index, Value, partitionIndex)                    StbM_SetGlbSecondsOfSyncTimeRecordingBlock(Index, (StbM_GetGlbSecondsOfSyncTimeRecordingBlock(((Index)), (partitionIndex)) + Value), partitionIndex)
#define StbM_AddLocNanoSecondsOfSyncTimeRecordingBlock(Index, Value, partitionIndex)                StbM_SetLocNanoSecondsOfSyncTimeRecordingBlock(Index, (StbM_GetLocNanoSecondsOfSyncTimeRecordingBlock(((Index)), (partitionIndex)) + Value), partitionIndex)
#define StbM_AddLocSecondsOfSyncTimeRecordingBlock(Index, Value, partitionIndex)                    StbM_SetLocSecondsOfSyncTimeRecordingBlock(Index, (StbM_GetLocSecondsOfSyncTimeRecordingBlock(((Index)), (partitionIndex)) + Value), partitionIndex)
#define StbM_AddPathDelayOfSyncTimeRecordingBlock(Index, Value, partitionIndex)                     StbM_SetPathDelayOfSyncTimeRecordingBlock(Index, (StbM_GetPathDelayOfSyncTimeRecordingBlock(((Index)), (partitionIndex)) + Value), partitionIndex)
#define StbM_AddRateDeviationOfSyncTimeRecordingBlock(Index, Value, partitionIndex)                 StbM_SetRateDeviationOfSyncTimeRecordingBlock(Index, (StbM_GetRateDeviationOfSyncTimeRecordingBlock(((Index)), (partitionIndex)) + Value), partitionIndex)
#define StbM_AddTimeBaseStatusOfSyncTimeRecordingBlock(Index, Value, partitionIndex)                StbM_SetTimeBaseStatusOfSyncTimeRecordingBlock(Index, (StbM_GetTimeBaseStatusOfSyncTimeRecordingBlock(((Index)), (partitionIndex)) + Value), partitionIndex)
#define StbM_AddVirtualLocalTimeLowOfSyncTimeRecordingBlock(Index, Value, partitionIndex)           StbM_SetVirtualLocalTimeLowOfSyncTimeRecordingBlock(Index, (StbM_GetVirtualLocalTimeLowOfSyncTimeRecordingBlock(((Index)), (partitionIndex)) + Value), partitionIndex)
#define StbM_AddUpdateCounterOfTimeBaseState(Index, Value, partitionIndex)                          StbM_SetUpdateCounterOfTimeBaseState(Index, (StbM_GetUpdateCounterOfTimeBaseState(((Index)), (partitionIndex)) + Value), partitionIndex)
#define StbM_AddClearCountFutureOfTimeLeapClearState(Index, Value, partitionIndex)                  StbM_SetClearCountFutureOfTimeLeapClearState(Index, (StbM_GetClearCountFutureOfTimeLeapClearState(((Index)), (partitionIndex)) + Value), partitionIndex)
#define StbM_AddClearCountPastOfTimeLeapClearState(Index, Value, partitionIndex)                    StbM_SetClearCountPastOfTimeLeapClearState(Index, (StbM_GetClearCountPastOfTimeLeapClearState(((Index)), (partitionIndex)) + Value), partitionIndex)
#define StbM_AddTimeLeapOfTimeLeapState(Index, Value, partitionIndex)                               StbM_SetTimeLeapOfTimeLeapState(Index, (StbM_GetTimeLeapOfTimeLeapState(((Index)), (partitionIndex)) + Value), partitionIndex)
#define StbM_AddCurrentBlockIdxOfTimeRecordingState(Index, Value, partitionIndex)                   StbM_SetCurrentBlockIdxOfTimeRecordingState(Index, (StbM_GetCurrentBlockIdxOfTimeRecordingState(((Index)), (partitionIndex)) + Value), partitionIndex)
#define StbM_AddPathDelayOfTimeRecordingState(Index, Value, partitionIndex)                         StbM_SetPathDelayOfTimeRecordingState(Index, (StbM_GetPathDelayOfTimeRecordingState(((Index)), (partitionIndex)) + Value), partitionIndex)
#define StbM_AddRecordedBlocksCountOfTimeRecordingState(Index, Value, partitionIndex)               StbM_SetRecordedBlocksCountOfTimeRecordingState(Index, (StbM_GetRecordedBlocksCountOfTimeRecordingState(((Index)), (partitionIndex)) + Value), partitionIndex)
#define StbM_AddSyncLossTimeoutCounterOfTimeoutState(Index, Value, partitionIndex)                  StbM_SetSyncLossTimeoutCounterOfTimeoutState(Index, (StbM_GetSyncLossTimeoutCounterOfTimeoutState(((Index)), (partitionIndex)) + Value), partitionIndex)
/** 
  \}
*/ 

/** 
  \defgroup  StbMPCSubstractDataMacros  StbM Substract Data Macros (PRE_COMPILE)
  \brief  These macros can be used to substract VAR data with numerical nature.
  \{
*/ 
#define StbM_SubLocalTimeUpdatedOfLocalTimeState(Index, Value, partitionIndex)                      StbM_SetLocalTimeUpdatedOfLocalTimeState(Index, (StbM_GetLocalTimeUpdatedOfLocalTimeState(((Index)), (partitionIndex)) - Value), partitionIndex)
#define StbM_SubGlobalTimeStatusOfStatus(Index, Value, partitionIndex)                              StbM_SetGlobalTimeStatusOfStatus(Index, (StbM_GetGlobalTimeStatusOfStatus(((Index)), (partitionIndex)) - Value), partitionIndex)
#define StbM_SubLocalTimeStatusOfStatus(Index, Value, partitionIndex)                               StbM_SetLocalTimeStatusOfStatus(Index, (StbM_GetLocalTimeStatusOfStatus(((Index)), (partitionIndex)) - Value), partitionIndex)
#define StbM_SubGlbNanoSecondsOfSyncTimeRecordingBlock(Index, Value, partitionIndex)                StbM_SetGlbNanoSecondsOfSyncTimeRecordingBlock(Index, (StbM_GetGlbNanoSecondsOfSyncTimeRecordingBlock(((Index)), (partitionIndex)) - Value), partitionIndex)
#define StbM_SubGlbSecondsOfSyncTimeRecordingBlock(Index, Value, partitionIndex)                    StbM_SetGlbSecondsOfSyncTimeRecordingBlock(Index, (StbM_GetGlbSecondsOfSyncTimeRecordingBlock(((Index)), (partitionIndex)) - Value), partitionIndex)
#define StbM_SubLocNanoSecondsOfSyncTimeRecordingBlock(Index, Value, partitionIndex)                StbM_SetLocNanoSecondsOfSyncTimeRecordingBlock(Index, (StbM_GetLocNanoSecondsOfSyncTimeRecordingBlock(((Index)), (partitionIndex)) - Value), partitionIndex)
#define StbM_SubLocSecondsOfSyncTimeRecordingBlock(Index, Value, partitionIndex)                    StbM_SetLocSecondsOfSyncTimeRecordingBlock(Index, (StbM_GetLocSecondsOfSyncTimeRecordingBlock(((Index)), (partitionIndex)) - Value), partitionIndex)
#define StbM_SubPathDelayOfSyncTimeRecordingBlock(Index, Value, partitionIndex)                     StbM_SetPathDelayOfSyncTimeRecordingBlock(Index, (StbM_GetPathDelayOfSyncTimeRecordingBlock(((Index)), (partitionIndex)) - Value), partitionIndex)
#define StbM_SubRateDeviationOfSyncTimeRecordingBlock(Index, Value, partitionIndex)                 StbM_SetRateDeviationOfSyncTimeRecordingBlock(Index, (StbM_GetRateDeviationOfSyncTimeRecordingBlock(((Index)), (partitionIndex)) - Value), partitionIndex)
#define StbM_SubTimeBaseStatusOfSyncTimeRecordingBlock(Index, Value, partitionIndex)                StbM_SetTimeBaseStatusOfSyncTimeRecordingBlock(Index, (StbM_GetTimeBaseStatusOfSyncTimeRecordingBlock(((Index)), (partitionIndex)) - Value), partitionIndex)
#define StbM_SubVirtualLocalTimeLowOfSyncTimeRecordingBlock(Index, Value, partitionIndex)           StbM_SetVirtualLocalTimeLowOfSyncTimeRecordingBlock(Index, (StbM_GetVirtualLocalTimeLowOfSyncTimeRecordingBlock(((Index)), (partitionIndex)) - Value), partitionIndex)
#define StbM_SubUpdateCounterOfTimeBaseState(Index, Value, partitionIndex)                          StbM_SetUpdateCounterOfTimeBaseState(Index, (StbM_GetUpdateCounterOfTimeBaseState(((Index)), (partitionIndex)) - Value), partitionIndex)
#define StbM_SubClearCountFutureOfTimeLeapClearState(Index, Value, partitionIndex)                  StbM_SetClearCountFutureOfTimeLeapClearState(Index, (StbM_GetClearCountFutureOfTimeLeapClearState(((Index)), (partitionIndex)) - Value), partitionIndex)
#define StbM_SubClearCountPastOfTimeLeapClearState(Index, Value, partitionIndex)                    StbM_SetClearCountPastOfTimeLeapClearState(Index, (StbM_GetClearCountPastOfTimeLeapClearState(((Index)), (partitionIndex)) - Value), partitionIndex)
#define StbM_SubTimeLeapOfTimeLeapState(Index, Value, partitionIndex)                               StbM_SetTimeLeapOfTimeLeapState(Index, (StbM_GetTimeLeapOfTimeLeapState(((Index)), (partitionIndex)) - Value), partitionIndex)
#define StbM_SubCurrentBlockIdxOfTimeRecordingState(Index, Value, partitionIndex)                   StbM_SetCurrentBlockIdxOfTimeRecordingState(Index, (StbM_GetCurrentBlockIdxOfTimeRecordingState(((Index)), (partitionIndex)) - Value), partitionIndex)
#define StbM_SubPathDelayOfTimeRecordingState(Index, Value, partitionIndex)                         StbM_SetPathDelayOfTimeRecordingState(Index, (StbM_GetPathDelayOfTimeRecordingState(((Index)), (partitionIndex)) - Value), partitionIndex)
#define StbM_SubRecordedBlocksCountOfTimeRecordingState(Index, Value, partitionIndex)               StbM_SetRecordedBlocksCountOfTimeRecordingState(Index, (StbM_GetRecordedBlocksCountOfTimeRecordingState(((Index)), (partitionIndex)) - Value), partitionIndex)
#define StbM_SubSyncLossTimeoutCounterOfTimeoutState(Index, Value, partitionIndex)                  StbM_SetSyncLossTimeoutCounterOfTimeoutState(Index, (StbM_GetSyncLossTimeoutCounterOfTimeoutState(((Index)), (partitionIndex)) - Value), partitionIndex)
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
 
typedef uint32 StbM_NanosecondsType;
typedef uint32 StbM_SecondsType;
typedef uint16 StbM_SecondsHiType;

typedef struct
{
    StbM_NanosecondsType nanoseconds;
    StbM_SecondsType seconds;
    StbM_SecondsHiType secondsHi;
} StbM_InternalTimeStampType;

typedef struct
{
  StbM_TimeStampType StartGlobalTime;
  StbM_TimeStampType StartLocalTime;
  StbM_VirtualLocalTimeType StartVirtualLocalTime;
  boolean Discard;
} StbM_RateMeasurementType;

 

typedef P2FUNC(Std_ReturnType, STBM_APPL_CODE, StbM_SyncTimeRecordBlockCallbackFctType) (P2CONST(StbM_SyncRecordTableBlockType, AUTOMATIC, STBM_APPL_DATA) syncRecordTableBlock);

/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: SIZEOF DATA TYPES
**********************************************************************************************************************/
/** 
  \defgroup  StbMPCSizeOfTypes  StbM SizeOf Types (PRE_COMPILE)
  \brief  These type definitions are used for the SizeOf information.
  \{
*/ 
/**   \brief  value based type definition for StbM_SizeOfGptClockConfig */
typedef uint8 StbM_SizeOfGptClockConfigType;

/**   \brief  value based type definition for StbM_SizeOfGptClockState */
typedef uint8 StbM_SizeOfGptClockStateType;

/**   \brief  value based type definition for StbM_SizeOfLocalClockConfig */
typedef uint8 StbM_SizeOfLocalClockConfigType;

/**   \brief  value based type definition for StbM_SizeOfLocalClockState */
typedef uint8 StbM_SizeOfLocalClockStateType;

/**   \brief  value based type definition for StbM_SizeOfLocalTimeConfig */
typedef uint8 StbM_SizeOfLocalTimeConfigType;

/**   \brief  value based type definition for StbM_SizeOfLocalTimeState */
typedef uint8 StbM_SizeOfLocalTimeStateType;

/**   \brief  value based type definition for StbM_SizeOfMainTimeState */
typedef uint8 StbM_SizeOfMainTimeStateType;

/**   \brief  value based type definition for StbM_SizeOfPartitionIdentifiers */
typedef uint8 StbM_SizeOfPartitionIdentifiersType;

/**   \brief  value based type definition for StbM_SizeOfReceivedTimeState */
typedef uint8 StbM_SizeOfReceivedTimeStateType;

/**   \brief  value based type definition for StbM_SizeOfStatus */
typedef uint8 StbM_SizeOfStatusType;

/**   \brief  value based type definition for StbM_SizeOfSyncTimeRecordingBlock */
typedef uint8 StbM_SizeOfSyncTimeRecordingBlockType;

/**   \brief  value based type definition for StbM_SizeOfSyncTimeRecordingHeader */
typedef uint8 StbM_SizeOfSyncTimeRecordingHeaderType;

/**   \brief  value based type definition for StbM_SizeOfTimeBaseConfig */
typedef uint8 StbM_SizeOfTimeBaseConfigType;

/**   \brief  value based type definition for StbM_SizeOfTimeBasePartitionMapping */
typedef uint8 StbM_SizeOfTimeBasePartitionMappingType;

/**   \brief  value based type definition for StbM_SizeOfTimeBaseState */
typedef uint8 StbM_SizeOfTimeBaseStateType;

/**   \brief  value based type definition for StbM_SizeOfTimeLeapClearState */
typedef uint8 StbM_SizeOfTimeLeapClearStateType;

/**   \brief  value based type definition for StbM_SizeOfTimeLeapConfig */
typedef uint8 StbM_SizeOfTimeLeapConfigType;

/**   \brief  value based type definition for StbM_SizeOfTimeLeapState */
typedef uint8 StbM_SizeOfTimeLeapStateType;

/**   \brief  value based type definition for StbM_SizeOfTimeRecordingConfig */
typedef uint8 StbM_SizeOfTimeRecordingConfigType;

/**   \brief  value based type definition for StbM_SizeOfTimeRecordingState */
typedef uint8 StbM_SizeOfTimeRecordingStateType;

/**   \brief  value based type definition for StbM_SizeOfTimeRecordingSyncCallback */
typedef uint8 StbM_SizeOfTimeRecordingSyncCallbackType;

/**   \brief  value based type definition for StbM_SizeOfTimeoutConfig */
typedef uint8 StbM_SizeOfTimeoutConfigType;

/**   \brief  value based type definition for StbM_SizeOfTimeoutState */
typedef uint8 StbM_SizeOfTimeoutStateType;

/**   \brief  value based type definition for StbM_SizeOfUserDataState */
typedef uint8 StbM_SizeOfUserDataStateType;

/**   \brief  value based type definition for StbM_SizeOfVirtualLocalTimeState */
typedef uint8 StbM_SizeOfVirtualLocalTimeStateType;

/** 
  \}
*/ 

/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL SIMPLE DATA TYPES AND STRUCTURES
**********************************************************************************************************************/
/** 
  \defgroup  StbMPCIterableTypes  StbM Iterable Types (PRE_COMPILE)
  \brief  These type definitions are used to iterate over an array with least processor cycles for variable access as possible.
  \{
*/ 
/**   \brief  type used to iterate StbM_GptClockConfig */
typedef uint8_least StbM_GptClockConfigIterType;

/**   \brief  type used to iterate StbM_GptClockState */
typedef uint8_least StbM_GptClockStateIterType;

/**   \brief  type used to iterate StbM_LocalClockConfig */
typedef uint8_least StbM_LocalClockConfigIterType;

/**   \brief  type used to iterate StbM_LocalClockState */
typedef uint8_least StbM_LocalClockStateIterType;

/**   \brief  type used to iterate StbM_LocalTimeConfig */
typedef uint8_least StbM_LocalTimeConfigIterType;

/**   \brief  type used to iterate StbM_LocalTimeState */
typedef uint8_least StbM_LocalTimeStateIterType;

/**   \brief  type used to iterate StbM_MainTimeState */
typedef uint8_least StbM_MainTimeStateIterType;

/**   \brief  type used to iterate StbM_PartitionIdentifiers */
typedef uint8_least StbM_PartitionIdentifiersIterType;

/**   \brief  type used to iterate StbM_SyncTimeRecordingBlock */
typedef uint8_least StbM_SyncTimeRecordingBlockIterType;

/**   \brief  type used to iterate StbM_SyncTimeRecordingHeader */
typedef uint8_least StbM_SyncTimeRecordingHeaderIterType;

/**   \brief  type used to iterate StbM_TimeBaseConfig */
typedef uint8_least StbM_TimeBaseConfigIterType;

/**   \brief  type used to iterate StbM_TimeBasePartitionMapping */
typedef uint8_least StbM_TimeBasePartitionMappingIterType;

/**   \brief  type used to iterate StbM_TimeLeapConfig */
typedef uint8_least StbM_TimeLeapConfigIterType;

/**   \brief  type used to iterate StbM_TimeRecordingConfig */
typedef uint8_least StbM_TimeRecordingConfigIterType;

/**   \brief  type used to iterate StbM_TimeRecordingSyncCallback */
typedef uint8_least StbM_TimeRecordingSyncCallbackIterType;

/**   \brief  type used to iterate StbM_TimeoutConfig */
typedef uint8_least StbM_TimeoutConfigIterType;

/**   \brief  type used to iterate StbM_UserDataState */
typedef uint8_least StbM_UserDataStateIterType;

/**   \brief  type used to iterate StbM_VirtualLocalTimeState */
typedef uint8_least StbM_VirtualLocalTimeStateIterType;

/**   \brief  type used to iterate StbM_PCPartitionConfig */
typedef uint8_least StbM_PCPartitionConfigIterType;

/** 
  \}
*/ 

/** 
  \defgroup  StbMPCIterableTypesWithSizeRelations  StbM Iterable Types With Size Relations (PRE_COMPILE)
  \brief  These type definitions are used to iterate over a VAR based array with the same iterator as the related CONST array.
  \{
*/ 
/**   \brief  type used to iterate StbM_ReceivedTimeState */
typedef StbM_LocalTimeConfigIterType StbM_ReceivedTimeStateIterType;

/**   \brief  type used to iterate StbM_Status */
typedef StbM_TimeBaseConfigIterType StbM_StatusIterType;

/**   \brief  type used to iterate StbM_TimeBaseState */
typedef StbM_TimeBaseConfigIterType StbM_TimeBaseStateIterType;

/**   \brief  type used to iterate StbM_TimeLeapClearState */
typedef StbM_TimeLeapConfigIterType StbM_TimeLeapClearStateIterType;

/**   \brief  type used to iterate StbM_TimeLeapState */
typedef StbM_LocalTimeConfigIterType StbM_TimeLeapStateIterType;

/**   \brief  type used to iterate StbM_TimeRecordingState */
typedef StbM_TimeRecordingConfigIterType StbM_TimeRecordingStateIterType;

/**   \brief  type used to iterate StbM_TimeoutState */
typedef StbM_TimeoutConfigIterType StbM_TimeoutStateIterType;

/** 
  \}
*/ 

/** 
  \defgroup  StbMPCValueTypes  StbM Value Types (PRE_COMPILE)
  \brief  These type definitions are used for value based data representations.
  \{
*/ 
/**   \brief  value based type definition for StbM_MaxTickValueOfGptClockConfig */
typedef uint32 StbM_MaxTickValueOfGptClockConfigType;

/**   \brief  value based type definition for StbM_GptChannelActiveOfGptClockState */
typedef boolean StbM_GptChannelActiveOfGptClockStateType;

/**   \brief  value based type definition for StbM_Initialized */
typedef boolean StbM_InitializedType;

/**   \brief  value based type definition for StbM_ClockTypeOfLocalClockConfig */
typedef uint8 StbM_ClockTypeOfLocalClockConfigType;

/**   \brief  value based type definition for StbM_DenominatorOfFactorClockTicksToLocalTimeOfLocalClockConfig */
typedef uint8 StbM_DenominatorOfFactorClockTicksToLocalTimeOfLocalClockConfigType;

/**   \brief  value based type definition for StbM_GptClockConfigIdxOfLocalClockConfig */
typedef uint8 StbM_GptClockConfigIdxOfLocalClockConfigType;

/**   \brief  value based type definition for StbM_GptClockConfigUsedOfLocalClockConfig */
typedef boolean StbM_GptClockConfigUsedOfLocalClockConfigType;

/**   \brief  value based type definition for StbM_HwFrequencyOfLocalClockConfig */
typedef uint32 StbM_HwFrequencyOfLocalClockConfigType;

/**   \brief  value based type definition for StbM_HwPrescalerOfLocalClockConfig */
typedef uint8 StbM_HwPrescalerOfLocalClockConfigType;

/**   \brief  value based type definition for StbM_NumeratorOfFactorClockTicksToLocalTimeOfLocalClockConfig */
typedef uint8 StbM_NumeratorOfFactorClockTicksToLocalTimeOfLocalClockConfigType;

/**   \brief  value based type definition for StbM_TimeBasePartitionMappingIdxOfLocalClockConfig */
typedef uint8 StbM_TimeBasePartitionMappingIdxOfLocalClockConfigType;

/**   \brief  value based type definition for StbM_LocalClockConfigIdxOfLocalTimeConfig */
typedef uint8 StbM_LocalClockConfigIdxOfLocalTimeConfigType;

/**   \brief  value based type definition for StbM_LocalClockConfigUsedOfLocalTimeConfig */
typedef boolean StbM_LocalClockConfigUsedOfLocalTimeConfigType;

/**   \brief  value based type definition for StbM_TimeBaseConfigIdxOfLocalTimeConfig */
typedef uint8 StbM_TimeBaseConfigIdxOfLocalTimeConfigType;

/**   \brief  value based type definition for StbM_TimeBasePartitionMappingIdxOfLocalTimeConfig */
typedef uint8 StbM_TimeBasePartitionMappingIdxOfLocalTimeConfigType;

/**   \brief  value based type definition for StbM_LocalTimeUpdatedOfLocalTimeState */
typedef uint8 StbM_LocalTimeUpdatedOfLocalTimeStateType;

/**   \brief  value based type definition for StbM_PCPartitionConfigIdxOfPartitionIdentifiers */
typedef uint8 StbM_PCPartitionConfigIdxOfPartitionIdentifiersType;

/**   \brief  value based type definition for StbM_GlbNanoSecondsOfSyncTimeRecordingBlock */
typedef uint32 StbM_GlbNanoSecondsOfSyncTimeRecordingBlockType;

/**   \brief  value based type definition for StbM_GlbSecondsOfSyncTimeRecordingBlock */
typedef uint32 StbM_GlbSecondsOfSyncTimeRecordingBlockType;

/**   \brief  value based type definition for StbM_LocNanoSecondsOfSyncTimeRecordingBlock */
typedef uint32 StbM_LocNanoSecondsOfSyncTimeRecordingBlockType;

/**   \brief  value based type definition for StbM_LocSecondsOfSyncTimeRecordingBlock */
typedef uint32 StbM_LocSecondsOfSyncTimeRecordingBlockType;

/**   \brief  value based type definition for StbM_PathDelayOfSyncTimeRecordingBlock */
typedef uint32 StbM_PathDelayOfSyncTimeRecordingBlockType;

/**   \brief  value based type definition for StbM_TimeBaseStatusOfSyncTimeRecordingBlock */
typedef uint8 StbM_TimeBaseStatusOfSyncTimeRecordingBlockType;

/**   \brief  value based type definition for StbM_VirtualLocalTimeLowOfSyncTimeRecordingBlock */
typedef uint32 StbM_VirtualLocalTimeLowOfSyncTimeRecordingBlockType;

/**   \brief  value based type definition for StbM_HwFrequencyOfSyncTimeRecordingHeader */
typedef uint32 StbM_HwFrequencyOfSyncTimeRecordingHeaderType;

/**   \brief  value based type definition for StbM_HwPrescalerOfSyncTimeRecordingHeader */
typedef uint8 StbM_HwPrescalerOfSyncTimeRecordingHeaderType;

/**   \brief  value based type definition for StbM_TimeDomainOfSyncTimeRecordingHeader */
typedef uint8 StbM_TimeDomainOfSyncTimeRecordingHeaderType;

/**   \brief  value based type definition for StbM_LocalTimeConfigIdxOfTimeBaseConfig */
typedef uint8 StbM_LocalTimeConfigIdxOfTimeBaseConfigType;

/**   \brief  value based type definition for StbM_PartitionConfigIdxOfTimeBaseConfig */
typedef uint8 StbM_PartitionConfigIdxOfTimeBaseConfigType;

/**   \brief  value based type definition for StbM_StatusIdxOfTimeBaseConfig */
typedef uint8 StbM_StatusIdxOfTimeBaseConfigType;

/**   \brief  value based type definition for StbM_SynchronizedTimeBaseOfTimeBaseConfig */
typedef boolean StbM_SynchronizedTimeBaseOfTimeBaseConfigType;

/**   \brief  value based type definition for StbM_TimeBaseIdOfTimeBaseConfig */
typedef uint8 StbM_TimeBaseIdOfTimeBaseConfigType;

/**   \brief  value based type definition for StbM_TimeLeapConfigIdxOfTimeBaseConfig */
typedef uint8 StbM_TimeLeapConfigIdxOfTimeBaseConfigType;

/**   \brief  value based type definition for StbM_TimeLeapConfigUsedOfTimeBaseConfig */
typedef boolean StbM_TimeLeapConfigUsedOfTimeBaseConfigType;

/**   \brief  value based type definition for StbM_TimeRecordingConfigIdxOfTimeBaseConfig */
typedef uint8 StbM_TimeRecordingConfigIdxOfTimeBaseConfigType;

/**   \brief  value based type definition for StbM_TimeRecordingConfigUsedOfTimeBaseConfig */
typedef boolean StbM_TimeRecordingConfigUsedOfTimeBaseConfigType;

/**   \brief  value based type definition for StbM_TimeSlaveOfTimeBaseConfig */
typedef boolean StbM_TimeSlaveOfTimeBaseConfigType;

/**   \brief  value based type definition for StbM_TimeoutConfigIdxOfTimeBaseConfig */
typedef uint8 StbM_TimeoutConfigIdxOfTimeBaseConfigType;

/**   \brief  value based type definition for StbM_TimeoutConfigUsedOfTimeBaseConfig */
typedef boolean StbM_TimeoutConfigUsedOfTimeBaseConfigType;

/**   \brief  value based type definition for StbM_UserDataStateIdxOfTimeBaseConfig */
typedef uint8 StbM_UserDataStateIdxOfTimeBaseConfigType;

/**   \brief  value based type definition for StbM_IndirectionToGptClockStateIdxOfTimeBasePartitionMapping */
typedef uint8 StbM_IndirectionToGptClockStateIdxOfTimeBasePartitionMappingType;

/**   \brief  value based type definition for StbM_IndirectionToGptClockStatePartitionIdxOfTimeBasePartitionMapping */
typedef uint8 StbM_IndirectionToGptClockStatePartitionIdxOfTimeBasePartitionMappingType;

/**   \brief  value based type definition for StbM_IndirectionToGptClockStateUsedOfTimeBasePartitionMapping */
typedef boolean StbM_IndirectionToGptClockStateUsedOfTimeBasePartitionMappingType;

/**   \brief  value based type definition for StbM_IndirectionToLocalClockStateIdxOfTimeBasePartitionMapping */
typedef uint8 StbM_IndirectionToLocalClockStateIdxOfTimeBasePartitionMappingType;

/**   \brief  value based type definition for StbM_IndirectionToLocalClockStatePartitionIdxOfTimeBasePartitionMapping */
typedef uint8 StbM_IndirectionToLocalClockStatePartitionIdxOfTimeBasePartitionMappingType;

/**   \brief  value based type definition for StbM_IndirectionToLocalClockStateUsedOfTimeBasePartitionMapping */
typedef boolean StbM_IndirectionToLocalClockStateUsedOfTimeBasePartitionMappingType;

/**   \brief  value based type definition for StbM_IndirectionToLocalTimeStateIdxOfTimeBasePartitionMapping */
typedef uint8 StbM_IndirectionToLocalTimeStateIdxOfTimeBasePartitionMappingType;

/**   \brief  value based type definition for StbM_IndirectionToLocalTimeStatePartitionIdxOfTimeBasePartitionMapping */
typedef uint8 StbM_IndirectionToLocalTimeStatePartitionIdxOfTimeBasePartitionMappingType;

/**   \brief  value based type definition for StbM_IndirectionToMainTimeStateIdxOfTimeBasePartitionMapping */
typedef uint8 StbM_IndirectionToMainTimeStateIdxOfTimeBasePartitionMappingType;

/**   \brief  value based type definition for StbM_IndirectionToMainTimeStatePartitionIdxOfTimeBasePartitionMapping */
typedef uint8 StbM_IndirectionToMainTimeStatePartitionIdxOfTimeBasePartitionMappingType;

/**   \brief  value based type definition for StbM_IndirectionToTimeBaseConfigIdxOfTimeBasePartitionMapping */
typedef uint8 StbM_IndirectionToTimeBaseConfigIdxOfTimeBasePartitionMappingType;

/**   \brief  value based type definition for StbM_IndirectionToTimeBaseConfigPartitionIdxOfTimeBasePartitionMapping */
typedef uint8 StbM_IndirectionToTimeBaseConfigPartitionIdxOfTimeBasePartitionMappingType;

/**   \brief  value based type definition for StbM_IndirectionToVirtualLocalTimeStateIdxOfTimeBasePartitionMapping */
typedef uint8 StbM_IndirectionToVirtualLocalTimeStateIdxOfTimeBasePartitionMappingType;

/**   \brief  value based type definition for StbM_IndirectionToVirtualLocalTimeStatePartitionIdxOfTimeBasePartitionMapping */
typedef uint8 StbM_IndirectionToVirtualLocalTimeStatePartitionIdxOfTimeBasePartitionMappingType;

/**   \brief  value based type definition for StbM_UpdateCounterOfTimeBaseState */
typedef uint8 StbM_UpdateCounterOfTimeBaseStateType;

/**   \brief  value based type definition for StbM_ClearCountFutureOfTimeLeapClearState */
typedef uint16 StbM_ClearCountFutureOfTimeLeapClearStateType;

/**   \brief  value based type definition for StbM_ClearCountPastOfTimeLeapClearState */
typedef uint16 StbM_ClearCountPastOfTimeLeapClearStateType;

/**   \brief  value based type definition for StbM_ClearCountOfTimeLeapConfig */
typedef uint8 StbM_ClearCountOfTimeLeapConfigType;

/**   \brief  value based type definition for StbM_FutureThresholdOfTimeLeapConfig */
typedef uint32 StbM_FutureThresholdOfTimeLeapConfigType;

/**   \brief  value based type definition for StbM_PastThresholdOfTimeLeapConfig */
typedef uint32 StbM_PastThresholdOfTimeLeapConfigType;

/**   \brief  value based type definition for StbM_TimeLeapOfTimeLeapState */
typedef sint32 StbM_TimeLeapOfTimeLeapStateType;

/**   \brief  value based type definition for StbM_TimeLeapValidOfTimeLeapState */
typedef boolean StbM_TimeLeapValidOfTimeLeapStateType;

/**   \brief  value based type definition for StbM_BlockCountOfTimeRecordingConfig */
typedef uint8 StbM_BlockCountOfTimeRecordingConfigType;

/**   \brief  value based type definition for StbM_SyncTimeRecordingBlockEndIdxOfTimeRecordingConfig */
typedef uint8 StbM_SyncTimeRecordingBlockEndIdxOfTimeRecordingConfigType;

/**   \brief  value based type definition for StbM_SyncTimeRecordingBlockStartIdxOfTimeRecordingConfig */
typedef uint8 StbM_SyncTimeRecordingBlockStartIdxOfTimeRecordingConfigType;

/**   \brief  value based type definition for StbM_SyncTimeRecordingBlockUsedOfTimeRecordingConfig */
typedef boolean StbM_SyncTimeRecordingBlockUsedOfTimeRecordingConfigType;

/**   \brief  value based type definition for StbM_SyncTimeRecordingHeaderIdxOfTimeRecordingConfig */
typedef uint8 StbM_SyncTimeRecordingHeaderIdxOfTimeRecordingConfigType;

/**   \brief  value based type definition for StbM_SyncTimeRecordingHeaderUsedOfTimeRecordingConfig */
typedef boolean StbM_SyncTimeRecordingHeaderUsedOfTimeRecordingConfigType;

/**   \brief  value based type definition for StbM_TimeBaseConfigIdxOfTimeRecordingConfig */
typedef uint8 StbM_TimeBaseConfigIdxOfTimeRecordingConfigType;

/**   \brief  value based type definition for StbM_TimeBaseConfigUsedOfTimeRecordingConfig */
typedef boolean StbM_TimeBaseConfigUsedOfTimeRecordingConfigType;

/**   \brief  value based type definition for StbM_TimeRecordingSyncCallbackIdxOfTimeRecordingConfig */
typedef uint8 StbM_TimeRecordingSyncCallbackIdxOfTimeRecordingConfigType;

/**   \brief  value based type definition for StbM_TimeRecordingSyncCallbackUsedOfTimeRecordingConfig */
typedef boolean StbM_TimeRecordingSyncCallbackUsedOfTimeRecordingConfigType;

/**   \brief  value based type definition for StbM_CurrentBlockIdxOfTimeRecordingState */
typedef uint32 StbM_CurrentBlockIdxOfTimeRecordingStateType;

/**   \brief  value based type definition for StbM_PathDelayOfTimeRecordingState */
typedef uint32 StbM_PathDelayOfTimeRecordingStateType;

/**   \brief  value based type definition for StbM_RecordedBlocksCountOfTimeRecordingState */
typedef uint16 StbM_RecordedBlocksCountOfTimeRecordingStateType;

/**   \brief  value based type definition for StbM_SyncLossTimeoutCounterOfTimeoutConfig */
typedef uint16 StbM_SyncLossTimeoutCounterOfTimeoutConfigType;

/**   \brief  value based type definition for StbM_TimeBaseConfigIdxOfTimeoutConfig */
typedef uint8 StbM_TimeBaseConfigIdxOfTimeoutConfigType;

/**   \brief  value based type definition for StbM_SyncLossTimeoutCounterOfTimeoutState */
typedef uint32 StbM_SyncLossTimeoutCounterOfTimeoutStateType;

/** 
  \}
*/ 

/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL COMPLEX DATA TYPES AND STRUCTURES
**********************************************************************************************************************/
/** 
  \defgroup  StbMPCStructTypes  StbM Struct Types (PRE_COMPILE)
  \brief  These type definitions are used for structured data representations.
  \{
*/ 
/**   \brief  type used in StbM_GptClockConfig */
typedef struct sStbM_GptClockConfigType
{
  StbM_MaxTickValueOfGptClockConfigType MaxTickValueOfGptClockConfig;  /**< Maximum value in ticks, the timer channel is able to count. */
  Gpt_ChannelType GptChannelSymbolicNameOfGptClockConfig;  /**< Symbolic name of used Gpt channel as local reference clock. */
} StbM_GptClockConfigType;

/**   \brief  type used in StbM_GptClockState */
typedef struct sStbM_GptClockStateType
{
  StbM_GptChannelActiveOfGptClockStateType GptChannelActiveOfGptClockState;  /**< Indicates if the used Gpt channel is active. */
} StbM_GptClockStateType;

/**   \brief  type used in StbM_LocalClockConfig */
typedef struct sStbM_LocalClockConfigType
{
  StbM_HwFrequencyOfLocalClockConfigType HwFrequencyOfLocalClockConfig;  /**< Frequency of the hardware reference clock in Hz. */
  StbM_ClockTypeOfLocalClockConfigType ClockTypeOfLocalClockConfig;  /**< The type of local clock, which is used as hardware clock */
  StbM_DenominatorOfFactorClockTicksToLocalTimeOfLocalClockConfigType DenominatorOfFactorClockTicksToLocalTimeOfLocalClockConfig;  /**< Pre calculated denominator of the rational number of the calculation: (StbMClockPrescaler * 10^9) / StbMClockFrequency. */
  StbM_GptClockConfigIdxOfLocalClockConfigType GptClockConfigIdxOfLocalClockConfig;  /**< the index of the 0:1 relation pointing to StbM_GptClockConfig */
  StbM_HwPrescalerOfLocalClockConfigType HwPrescalerOfLocalClockConfig;  /**< Prescaler of hardware reference clock. */
  StbM_NumeratorOfFactorClockTicksToLocalTimeOfLocalClockConfigType NumeratorOfFactorClockTicksToLocalTimeOfLocalClockConfig;  /**< Pre calculated numerator of the rational number of the calculation: (StbMClockPrescaler * 10^9) / StbMClockFrequency. */
  StbM_TimeBasePartitionMappingIdxOfLocalClockConfigType TimeBasePartitionMappingIdxOfLocalClockConfig;  /**< the index of the 1:1 relation pointing to StbM_TimeBasePartitionMapping */
} StbM_LocalClockConfigType;

/**   \brief  type used in StbM_LocalClockState */
typedef struct sStbM_LocalClockStateType
{
  StbM_InternalTimeStampType ElapsedTimeOfLocalClockState;  /**< Elapsed time of the local clock since last synchronization event. This can be either a counter value or a real time. */
  StbM_InternalTimeStampType LastReadTimeOfLocalClockState;  /**< Last read time of the local clock. This can be either a counter value or a real time. */
} StbM_LocalClockStateType;

/**   \brief  type used in StbM_LocalTimeConfig */
typedef struct sStbM_LocalTimeConfigType
{
  StbM_LocalClockConfigIdxOfLocalTimeConfigType LocalClockConfigIdxOfLocalTimeConfig;  /**< the index of the 0:1 relation pointing to StbM_LocalClockConfig */
  StbM_TimeBaseConfigIdxOfLocalTimeConfigType TimeBaseConfigIdxOfLocalTimeConfig;  /**< the index of the 1:1 relation pointing to StbM_TimeBaseConfig */
  StbM_TimeBasePartitionMappingIdxOfLocalTimeConfigType TimeBasePartitionMappingIdxOfLocalTimeConfig;  /**< the index of the 1:1 relation pointing to StbM_TimeBasePartitionMapping */
} StbM_LocalTimeConfigType;

/**   \brief  type used in StbM_LocalTimeState */
typedef struct sStbM_LocalTimeStateType
{
  StbM_LocalTimeUpdatedOfLocalTimeStateType LocalTimeUpdatedOfLocalTimeState;  /**< Indicate if LocalTime is updated and therefore valid, hence can be used without recalculating it. (E_OK | E_NOT_OK) */
  StbM_InternalTimeStampType LocalTimeOfLocalTimeState;  /**< TL (current corrected local time). */
} StbM_LocalTimeStateType;

/**   \brief  type used in StbM_MainTimeState */
typedef struct sStbM_MainTimeStateType
{
  StbM_InternalTimeStampType GlobalTimeSyncOfMainTimeState;  /**< TGsync (local time after update). */
  StbM_VirtualLocalTimeType VirtualLocalTimeSyncOfMainTimeState;  /**< TVsync (virtual local time at last synchronization event). */
} StbM_MainTimeStateType;

/**   \brief  type used in StbM_PartitionIdentifiers */
typedef struct sStbM_PartitionIdentifiersType
{
  ApplicationType PartitionSNVOfPartitionIdentifiers;
  StbM_PCPartitionConfigIdxOfPartitionIdentifiersType PCPartitionConfigIdxOfPartitionIdentifiers;  /**< the index of the 1:1 relation pointing to StbM_PCPartitionConfig */
} StbM_PartitionIdentifiersType;

/**   \brief  type used in StbM_ReceivedTimeState */
typedef struct sStbM_ReceivedTimeStateType
{
  StbM_InternalTimeStampType GlobalTimeRxOfReceivedTimeState;  /**< TGrx (received global time). */
  StbM_InternalTimeStampType LocalTimeSyncOfReceivedTimeState;  /**< TLsync (local time before update). */
  StbM_VirtualLocalTimeType VirtualLocalTimeRxOfReceivedTimeState;  /**< TVrx (received virtual local time). */
} StbM_ReceivedTimeStateType;

/**   \brief  type used in StbM_Status */
typedef struct sStbM_StatusType
{
  StbM_TimeBaseStatusType GlobalTimeStatusOfStatus;  /**< Status of received global time. */
  StbM_TimeBaseStatusType LocalTimeStatusOfStatus;  /**< Status of local time. */
} StbM_StatusType;

/**   \brief  type used in StbM_SyncTimeRecordingBlock */
typedef struct sStbM_SyncTimeRecordingBlockType
{
  StbM_GlbNanoSecondsOfSyncTimeRecordingBlockType GlbNanoSecondsOfSyncTimeRecordingBlock;  /**< Nanoseconds of global time after update. */
  StbM_GlbSecondsOfSyncTimeRecordingBlockType GlbSecondsOfSyncTimeRecordingBlock;  /**< Seconds of global time after update. */
  StbM_LocNanoSecondsOfSyncTimeRecordingBlockType LocNanoSecondsOfSyncTimeRecordingBlock;  /**< Nanoseconds of local time before update. */
  StbM_LocSecondsOfSyncTimeRecordingBlockType LocSecondsOfSyncTimeRecordingBlock;  /**< Seconds of local time before update. */
  StbM_PathDelayOfSyncTimeRecordingBlockType PathDelayOfSyncTimeRecordingBlock;  /**< Received path delay. */
  StbM_VirtualLocalTimeLowOfSyncTimeRecordingBlockType VirtualLocalTimeLowOfSyncTimeRecordingBlock;  /**< Least significant 32 bit of the Virtual Local Time. */
  StbM_TimeBaseStatusOfSyncTimeRecordingBlockType TimeBaseStatusOfSyncTimeRecordingBlock;  /**< TimeBaseStatus. */
  StbM_RateDeviationType RateDeviationOfSyncTimeRecordingBlock;  /**< Rate deviation. */
} StbM_SyncTimeRecordingBlockType;

/**   \brief  type used in StbM_SyncTimeRecordingHeader */
typedef struct sStbM_SyncTimeRecordingHeaderType
{
  StbM_HwFrequencyOfSyncTimeRecordingHeaderType HwFrequencyOfSyncTimeRecordingHeader;  /**< Frequency of the hardware reference clock in Hz. */
  StbM_HwPrescalerOfSyncTimeRecordingHeaderType HwPrescalerOfSyncTimeRecordingHeader;  /**< Prescaler of hardware reference clock. */
  StbM_TimeDomainOfSyncTimeRecordingHeaderType TimeDomainOfSyncTimeRecordingHeader;  /**< Frequency of the hardware reference clock in Hz. */
} StbM_SyncTimeRecordingHeaderType;

/**   \brief  type used in StbM_TimeBaseConfig */
typedef struct sStbM_TimeBaseConfigType
{
  StbM_SynchronizedTimeBaseOfTimeBaseConfigType SynchronizedTimeBaseOfTimeBaseConfig;  /**< Indicates if the time base is a synchronized time base. */
  StbM_TimeSlaveOfTimeBaseConfigType TimeSlaveOfTimeBaseConfig;  /**< true if timebase has the role of a time slave */
  StbM_LocalTimeConfigIdxOfTimeBaseConfigType LocalTimeConfigIdxOfTimeBaseConfig;  /**< the index of the 1:1 relation pointing to StbM_LocalTimeConfig */
  StbM_PartitionConfigIdxOfTimeBaseConfigType PartitionConfigIdxOfTimeBaseConfig;  /**< the index of the 1:1 relation pointing to StbM_PCPartitionConfig */
  StbM_StatusIdxOfTimeBaseConfigType StatusIdxOfTimeBaseConfig;  /**< the index of the 1:1 relation pointing to StbM_Status */
  StbM_TimeBaseIdOfTimeBaseConfigType TimeBaseIdOfTimeBaseConfig;  /**< Id of the timebase. */
  StbM_TimeLeapConfigIdxOfTimeBaseConfigType TimeLeapConfigIdxOfTimeBaseConfig;  /**< the index of the 0:1 relation pointing to StbM_TimeLeapConfig */
  StbM_TimeRecordingConfigIdxOfTimeBaseConfigType TimeRecordingConfigIdxOfTimeBaseConfig;  /**< the index of the 0:1 relation pointing to StbM_TimeRecordingConfig */
  StbM_TimeoutConfigIdxOfTimeBaseConfigType TimeoutConfigIdxOfTimeBaseConfig;  /**< the index of the 0:1 relation pointing to StbM_TimeoutConfig */
  StbM_UserDataStateIdxOfTimeBaseConfigType UserDataStateIdxOfTimeBaseConfig;  /**< the index of the 1:1 relation pointing to StbM_UserDataState */
} StbM_TimeBaseConfigType;

/**   \brief  type used in StbM_TimeBasePartitionMapping */
typedef struct sStbM_TimeBasePartitionMappingType
{
  StbM_IndirectionToGptClockStateIdxOfTimeBasePartitionMappingType IndirectionToGptClockStateIdxOfTimeBasePartitionMapping;  /**< the index of the 0:1 relation pointing to StbM_GptClockState,StbM_GptClockState */
  StbM_IndirectionToGptClockStatePartitionIdxOfTimeBasePartitionMappingType IndirectionToGptClockStatePartitionIdxOfTimeBasePartitionMapping;  /**< the partition index of the 0:1 relation pointing to StbM_GptClockState,StbM_GptClockState */
  StbM_IndirectionToLocalClockStateIdxOfTimeBasePartitionMappingType IndirectionToLocalClockStateIdxOfTimeBasePartitionMapping;  /**< the index of the 0:1 relation pointing to StbM_LocalClockState,StbM_LocalClockState */
  StbM_IndirectionToLocalClockStatePartitionIdxOfTimeBasePartitionMappingType IndirectionToLocalClockStatePartitionIdxOfTimeBasePartitionMapping;  /**< the partition index of the 0:1 relation pointing to StbM_LocalClockState,StbM_LocalClockState */
  StbM_IndirectionToLocalTimeStateIdxOfTimeBasePartitionMappingType IndirectionToLocalTimeStateIdxOfTimeBasePartitionMapping;  /**< the index of the 1:1 relation pointing to one of StbM_LocalTimeState,StbM_LocalTimeState */
  StbM_IndirectionToLocalTimeStatePartitionIdxOfTimeBasePartitionMappingType IndirectionToLocalTimeStatePartitionIdxOfTimeBasePartitionMapping;  /**< the partition index of the 1:1 relation pointing to one of StbM_LocalTimeState,StbM_LocalTimeState */
  StbM_IndirectionToMainTimeStateIdxOfTimeBasePartitionMappingType IndirectionToMainTimeStateIdxOfTimeBasePartitionMapping;  /**< the index of the 1:1 relation pointing to one of StbM_MainTimeState,StbM_MainTimeState */
  StbM_IndirectionToMainTimeStatePartitionIdxOfTimeBasePartitionMappingType IndirectionToMainTimeStatePartitionIdxOfTimeBasePartitionMapping;  /**< the partition index of the 1:1 relation pointing to one of StbM_MainTimeState,StbM_MainTimeState */
  StbM_IndirectionToTimeBaseConfigIdxOfTimeBasePartitionMappingType IndirectionToTimeBaseConfigIdxOfTimeBasePartitionMapping;  /**< the index of the 1:1 relation pointing to one of StbM_TimeBaseConfig,StbM_TimeBaseConfig */
  StbM_IndirectionToTimeBaseConfigPartitionIdxOfTimeBasePartitionMappingType IndirectionToTimeBaseConfigPartitionIdxOfTimeBasePartitionMapping;  /**< the partition index of the 1:1 relation pointing to one of StbM_TimeBaseConfig,StbM_TimeBaseConfig */
  StbM_IndirectionToVirtualLocalTimeStateIdxOfTimeBasePartitionMappingType IndirectionToVirtualLocalTimeStateIdxOfTimeBasePartitionMapping;  /**< the index of the 1:1 relation pointing to one of StbM_VirtualLocalTimeState,StbM_VirtualLocalTimeState */
  StbM_IndirectionToVirtualLocalTimeStatePartitionIdxOfTimeBasePartitionMappingType IndirectionToVirtualLocalTimeStatePartitionIdxOfTimeBasePartitionMapping;  /**< the partition index of the 1:1 relation pointing to one of StbM_VirtualLocalTimeState,StbM_VirtualLocalTimeState */
} StbM_TimeBasePartitionMappingType;

/**   \brief  type used in StbM_TimeBaseState */
typedef struct sStbM_TimeBaseStateType
{
  StbM_UpdateCounterOfTimeBaseStateType UpdateCounterOfTimeBaseState;  /**< Actual counter value for immediate time synchronisation. */
} StbM_TimeBaseStateType;

/**   \brief  type used in StbM_TimeLeapClearState */
typedef struct sStbM_TimeLeapClearStateType
{
  StbM_ClearCountFutureOfTimeLeapClearStateType ClearCountFutureOfTimeLeapClearState;  /**< Clear counter to count until a detected timeleap to the future is reset. */
  StbM_ClearCountPastOfTimeLeapClearStateType ClearCountPastOfTimeLeapClearState;  /**< Clear counter to count until a detected timeleap to the past is reset. */
} StbM_TimeLeapClearStateType;

/**   \brief  type used in StbM_TimeLeapConfig */
typedef struct sStbM_TimeLeapConfigType
{
  StbM_FutureThresholdOfTimeLeapConfigType FutureThresholdOfTimeLeapConfig;  /**< Time leap threshold after which a future time leap is detected. */
  StbM_PastThresholdOfTimeLeapConfigType PastThresholdOfTimeLeapConfig;  /**< Time leap threshold after which a past time leap is detected. */
  StbM_ClearCountOfTimeLeapConfigType ClearCountOfTimeLeapConfig;  /**< Counter after which the a time leap is deleted. */
} StbM_TimeLeapConfigType;

/**   \brief  type used in StbM_TimeLeapState */
typedef struct sStbM_TimeLeapStateType
{
  StbM_TimeLeapOfTimeLeapStateType TimeLeapOfTimeLeapState;  /**< The last calculated time leap TGrx - TL. */
  StbM_TimeLeapValidOfTimeLeapStateType TimeLeapValidOfTimeLeapState;  /**< Flag which indicates if the calculated time leap is valid. */
} StbM_TimeLeapStateType;

/**   \brief  type used in StbM_TimeRecordingConfig */
typedef struct sStbM_TimeRecordingConfigType
{
  StbM_BlockCountOfTimeRecordingConfigType BlockCountOfTimeRecordingConfig;  /**< Number of configured recording blocks */
  StbM_SyncTimeRecordingBlockEndIdxOfTimeRecordingConfigType SyncTimeRecordingBlockEndIdxOfTimeRecordingConfig;  /**< the end index of the 0:n relation pointing to StbM_SyncTimeRecordingBlock */
  StbM_SyncTimeRecordingBlockStartIdxOfTimeRecordingConfigType SyncTimeRecordingBlockStartIdxOfTimeRecordingConfig;  /**< the start index of the 0:n relation pointing to StbM_SyncTimeRecordingBlock */
  StbM_SyncTimeRecordingHeaderIdxOfTimeRecordingConfigType SyncTimeRecordingHeaderIdxOfTimeRecordingConfig;  /**< the index of the 0:1 relation pointing to StbM_SyncTimeRecordingHeader */
  StbM_TimeBaseConfigIdxOfTimeRecordingConfigType TimeBaseConfigIdxOfTimeRecordingConfig;  /**< the index of the 0:1 relation pointing to StbM_TimeBaseConfig */
  StbM_TimeRecordingSyncCallbackIdxOfTimeRecordingConfigType TimeRecordingSyncCallbackIdxOfTimeRecordingConfig;  /**< the index of the 0:1 relation pointing to StbM_TimeRecordingSyncCallback */
} StbM_TimeRecordingConfigType;

/**   \brief  type used in StbM_TimeRecordingState */
typedef struct sStbM_TimeRecordingStateType
{
  StbM_CurrentBlockIdxOfTimeRecordingStateType CurrentBlockIdxOfTimeRecordingState;  /**< Current index of the next free block in timebase time recording blocks. */
  StbM_PathDelayOfTimeRecordingStateType PathDelayOfTimeRecordingState;  /**< Received path delay on last synchronization event. */
  StbM_RecordedBlocksCountOfTimeRecordingStateType RecordedBlocksCountOfTimeRecordingState;  /**< Number of recorded blocks. */
} StbM_TimeRecordingStateType;

/**   \brief  type used in StbM_TimeRecordingSyncCallback */
typedef struct sStbM_TimeRecordingSyncCallbackType
{
  StbM_SyncTimeRecordBlockCallbackFctType CallbackOfTimeRecordingSyncCallback;  /**< This function is called, once all recording blocks are updated. */
} StbM_TimeRecordingSyncCallbackType;

/**   \brief  type used in StbM_TimeoutConfig */
typedef struct sStbM_TimeoutConfigType
{
  StbM_SyncLossTimeoutCounterOfTimeoutConfigType SyncLossTimeoutCounterOfTimeoutConfig;  /**< Represents the amount of main functions until the timeout is expired. Calculated by Timeout(ns)/MainFunction(ns). */
  StbM_TimeBaseConfigIdxOfTimeoutConfigType TimeBaseConfigIdxOfTimeoutConfig;  /**< the index of the 1:1 relation pointing to StbM_TimeBaseConfig */
} StbM_TimeoutConfigType;

/**   \brief  type used in StbM_TimeoutState */
typedef struct sStbM_TimeoutStateType
{
  StbM_SyncLossTimeoutCounterOfTimeoutStateType SyncLossTimeoutCounterOfTimeoutState;  /**< Timeout for the synchronisation of the Time Base. */
} StbM_TimeoutStateType;

/**   \brief  type used in StbM_UserDataState */
typedef struct sStbM_UserDataStateType
{
  StbM_UserDataType UserDataOfUserDataState;  /**< User data. */
} StbM_UserDataStateType;

/**   \brief  type used in StbM_VirtualLocalTimeState */
typedef struct sStbM_VirtualLocalTimeStateType
{
  StbM_VirtualLocalTimeType VirtualLocalTimeOfVirtualLocalTimeState;  /**< TV (current virtual local time). */
  StbM_VirtualLocalTimeType VirtualLocalTimeElapsedAfterAdaptionIntervalOfVirtualLocalTimeState;  /**< TV elapsed after adaption interval (virtual local time elapsed after offset correction adaption interval). */
} StbM_VirtualLocalTimeStateType;

/** 
  \}
*/ 

/** 
  \defgroup  StbMPCSymbolicStructTypes  StbM Symbolic Struct Types (PRE_COMPILE)
  \brief  These structs are used in unions to have a symbol based data representation style.
  \{
*/ 
/**   \brief  type to be used as symbolic data element access to StbM_GptClockState in the partition context CommonSharedMemory */
typedef struct StbM_GptClockStateCommonSharedMemoryStructSTag
{
  StbM_GptClockStateType GptChannelConfiguration_StbM_LocalTime;
} StbM_GptClockStateCommonSharedMemoryStructSType;

/**   \brief  type to be used as symbolic data element access to StbM_LocalClockState in the partition context CommonSharedMemory */
typedef struct StbM_LocalClockStateCommonSharedMemoryStructSTag
{
  StbM_LocalClockStateType GTD_BODY3_0_14e64f11;
} StbM_LocalClockStateCommonSharedMemoryStructSType;

/**   \brief  type to be used as symbolic data element access to StbM_LocalTimeState in the partition context CommonSharedMemory */
typedef struct StbM_LocalTimeStateCommonSharedMemoryStructSTag
{
  StbM_LocalTimeStateType GTD_BODY3_0_14e64f11;
} StbM_LocalTimeStateCommonSharedMemoryStructSType;

/**   \brief  type to be used as symbolic data element access to StbM_MainTimeState in the partition context CommonSharedMemory */
typedef struct StbM_MainTimeStateCommonSharedMemoryStructSTag
{
  StbM_MainTimeStateType GTD_BODY3_0_14e64f11;
} StbM_MainTimeStateCommonSharedMemoryStructSType;

/**   \brief  type to be used as symbolic data element access to StbM_ReceivedTimeState in the partition context OsApplication_Trusted_Core0 */
typedef struct StbM_ReceivedTimeStateOsApplication_Trusted_Core0StructSTag
{
  StbM_ReceivedTimeStateType GTD_BODY3_0_14e64f11;
} StbM_ReceivedTimeStateOsApplication_Trusted_Core0StructSType;

/**   \brief  type to be used as symbolic data element access to StbM_Status in the partition context OsApplication_Trusted_Core0 */
typedef struct StbM_StatusOsApplication_Trusted_Core0StructSTag
{
  StbM_StatusType GTD_BODY3_0_14e64f11;
} StbM_StatusOsApplication_Trusted_Core0StructSType;

/**   \brief  type to be used as symbolic data element access to StbM_SyncTimeRecordingBlock in the partition context OsApplication_Trusted_Core0 */
typedef struct StbM_SyncTimeRecordingBlockOsApplication_Trusted_Core0StructSTag
{
  StbM_SyncTimeRecordingBlockType GTD_BODY3_0_14e64f11;
} StbM_SyncTimeRecordingBlockOsApplication_Trusted_Core0StructSType;

/**   \brief  type to be used as symbolic data element access to StbM_TimeBaseState in the partition context OsApplication_Trusted_Core0 */
typedef struct StbM_TimeBaseStateOsApplication_Trusted_Core0StructSTag
{
  StbM_TimeBaseStateType GTD_BODY3_0_14e64f11;
} StbM_TimeBaseStateOsApplication_Trusted_Core0StructSType;

/**   \brief  type to be used as symbolic data element access to StbM_TimeLeapClearState in the partition context OsApplication_Trusted_Core0 */
typedef struct StbM_TimeLeapClearStateOsApplication_Trusted_Core0StructSTag
{
  StbM_TimeLeapClearStateType GTD_BODY3_0_14e64f11;
} StbM_TimeLeapClearStateOsApplication_Trusted_Core0StructSType;

/**   \brief  type to be used as symbolic data element access to StbM_TimeLeapState in the partition context OsApplication_Trusted_Core0 */
typedef struct StbM_TimeLeapStateOsApplication_Trusted_Core0StructSTag
{
  StbM_TimeLeapStateType GTD_BODY3_0_14e64f11;
} StbM_TimeLeapStateOsApplication_Trusted_Core0StructSType;

/**   \brief  type to be used as symbolic data element access to StbM_TimeRecordingState in the partition context OsApplication_Trusted_Core0 */
typedef struct StbM_TimeRecordingStateOsApplication_Trusted_Core0StructSTag
{
  StbM_TimeRecordingStateType GTD_BODY3_0_14e64f11;
} StbM_TimeRecordingStateOsApplication_Trusted_Core0StructSType;

/**   \brief  type to be used as symbolic data element access to StbM_TimeoutState in the partition context OsApplication_Trusted_Core0 */
typedef struct StbM_TimeoutStateOsApplication_Trusted_Core0StructSTag
{
  StbM_TimeoutStateType GTD_BODY3_0_14e64f11;
} StbM_TimeoutStateOsApplication_Trusted_Core0StructSType;

/**   \brief  type to be used as symbolic data element access to StbM_UserDataState in the partition context OsApplication_Trusted_Core0 */
typedef struct StbM_UserDataStateOsApplication_Trusted_Core0StructSTag
{
  StbM_UserDataStateType GTD_BODY3_0_14e64f11;
} StbM_UserDataStateOsApplication_Trusted_Core0StructSType;

/**   \brief  type to be used as symbolic data element access to StbM_VirtualLocalTimeState in the partition context CommonSharedMemory */
typedef struct StbM_VirtualLocalTimeStateCommonSharedMemoryStructSTag
{
  StbM_VirtualLocalTimeStateType GTD_BODY3_0_14e64f11;
} StbM_VirtualLocalTimeStateCommonSharedMemoryStructSType;

/** 
  \}
*/ 

/** 
  \defgroup  StbMPCUnionIndexAndSymbolTypes  StbM Union Index And Symbol Types (PRE_COMPILE)
  \brief  These unions are used to access arrays in an index and symbol based style.
  \{
*/ 
/**   \brief  type to access StbM_GptClockState in an index and symbol based style. */
typedef union StbM_GptClockStateUTag
{  /* PRQA S 0750 */  /* MD_CSL_Union */
  StbM_GptClockStateType raw[1];
  StbM_GptClockStateCommonSharedMemoryStructSType strCommonSharedMemory;
} StbM_GptClockStateUType;

/**   \brief  type to access StbM_LocalClockState in an index and symbol based style. */
typedef union StbM_LocalClockStateUTag
{  /* PRQA S 0750 */  /* MD_CSL_Union */
  StbM_LocalClockStateType raw[1];
  StbM_LocalClockStateCommonSharedMemoryStructSType strCommonSharedMemory;
} StbM_LocalClockStateUType;

/**   \brief  type to access StbM_LocalTimeState in an index and symbol based style. */
typedef union StbM_LocalTimeStateUTag
{  /* PRQA S 0750 */  /* MD_CSL_Union */
  StbM_LocalTimeStateType raw[1];
  StbM_LocalTimeStateCommonSharedMemoryStructSType strCommonSharedMemory;
} StbM_LocalTimeStateUType;

/**   \brief  type to access StbM_MainTimeState in an index and symbol based style. */
typedef union StbM_MainTimeStateUTag
{  /* PRQA S 0750 */  /* MD_CSL_Union */
  StbM_MainTimeStateType raw[1];
  StbM_MainTimeStateCommonSharedMemoryStructSType strCommonSharedMemory;
} StbM_MainTimeStateUType;

/**   \brief  type to access StbM_ReceivedTimeState in an index and symbol based style. */
typedef union StbM_ReceivedTimeStateUTag
{  /* PRQA S 0750 */  /* MD_CSL_Union */
  StbM_ReceivedTimeStateType raw[1];
  StbM_ReceivedTimeStateOsApplication_Trusted_Core0StructSType strOsApplication_Trusted_Core0;
} StbM_ReceivedTimeStateUType;

/**   \brief  type to access StbM_Status in an index and symbol based style. */
typedef union StbM_StatusUTag
{  /* PRQA S 0750 */  /* MD_CSL_Union */
  StbM_StatusType raw[1];
  StbM_StatusOsApplication_Trusted_Core0StructSType strOsApplication_Trusted_Core0;
} StbM_StatusUType;

/**   \brief  type to access StbM_SyncTimeRecordingBlock in an index and symbol based style. */
typedef union StbM_SyncTimeRecordingBlockUTag
{  /* PRQA S 0750 */  /* MD_CSL_Union */
  StbM_SyncTimeRecordingBlockType raw[1];
  StbM_SyncTimeRecordingBlockOsApplication_Trusted_Core0StructSType strOsApplication_Trusted_Core0;
} StbM_SyncTimeRecordingBlockUType;

/**   \brief  type to access StbM_TimeBaseState in an index and symbol based style. */
typedef union StbM_TimeBaseStateUTag
{  /* PRQA S 0750 */  /* MD_CSL_Union */
  StbM_TimeBaseStateType raw[1];
  StbM_TimeBaseStateOsApplication_Trusted_Core0StructSType strOsApplication_Trusted_Core0;
} StbM_TimeBaseStateUType;

/**   \brief  type to access StbM_TimeLeapClearState in an index and symbol based style. */
typedef union StbM_TimeLeapClearStateUTag
{  /* PRQA S 0750 */  /* MD_CSL_Union */
  StbM_TimeLeapClearStateType raw[1];
  StbM_TimeLeapClearStateOsApplication_Trusted_Core0StructSType strOsApplication_Trusted_Core0;
} StbM_TimeLeapClearStateUType;

/**   \brief  type to access StbM_TimeLeapState in an index and symbol based style. */
typedef union StbM_TimeLeapStateUTag
{  /* PRQA S 0750 */  /* MD_CSL_Union */
  StbM_TimeLeapStateType raw[1];
  StbM_TimeLeapStateOsApplication_Trusted_Core0StructSType strOsApplication_Trusted_Core0;
} StbM_TimeLeapStateUType;

/**   \brief  type to access StbM_TimeRecordingState in an index and symbol based style. */
typedef union StbM_TimeRecordingStateUTag
{  /* PRQA S 0750 */  /* MD_CSL_Union */
  StbM_TimeRecordingStateType raw[1];
  StbM_TimeRecordingStateOsApplication_Trusted_Core0StructSType strOsApplication_Trusted_Core0;
} StbM_TimeRecordingStateUType;

/**   \brief  type to access StbM_TimeoutState in an index and symbol based style. */
typedef union StbM_TimeoutStateUTag
{  /* PRQA S 0750 */  /* MD_CSL_Union */
  StbM_TimeoutStateType raw[1];
  StbM_TimeoutStateOsApplication_Trusted_Core0StructSType strOsApplication_Trusted_Core0;
} StbM_TimeoutStateUType;

/**   \brief  type to access StbM_UserDataState in an index and symbol based style. */
typedef union StbM_UserDataStateUTag
{  /* PRQA S 0750 */  /* MD_CSL_Union */
  StbM_UserDataStateType raw[1];
  StbM_UserDataStateOsApplication_Trusted_Core0StructSType strOsApplication_Trusted_Core0;
} StbM_UserDataStateUType;

/**   \brief  type to access StbM_VirtualLocalTimeState in an index and symbol based style. */
typedef union StbM_VirtualLocalTimeStateUTag
{  /* PRQA S 0750 */  /* MD_CSL_Union */
  StbM_VirtualLocalTimeStateType raw[1];
  StbM_VirtualLocalTimeStateCommonSharedMemoryStructSType strCommonSharedMemory;
} StbM_VirtualLocalTimeStateUType;

/** 
  \}
*/ 

/** 
  \defgroup  StbMPCRootPointerTypes  StbM Root Pointer Types (PRE_COMPILE)
  \brief  These type definitions are used to point from the config root to symbol instances.
  \{
*/ 
/**   \brief  type used to point to StbM_GptClockConfig */
typedef P2CONST(StbM_GptClockConfigType, TYPEDEF, STBM_CONST) StbM_GptClockConfigPtrType;

/**   \brief  type used to point to StbM_GptClockState */
typedef P2VAR(StbM_GptClockStateType, TYPEDEF, STBM_VAR_NO_INIT) StbM_GptClockStatePtrType;

/**   \brief  type used to point to StbM_Initialized */
typedef P2VAR(StbM_InitializedType, TYPEDEF, STBM_VAR_CLEARED) StbM_InitializedPtrType;

/**   \brief  type used to point to StbM_LocalClockConfig */
typedef P2CONST(StbM_LocalClockConfigType, TYPEDEF, STBM_CONST) StbM_LocalClockConfigPtrType;

/**   \brief  type used to point to StbM_LocalClockState */
typedef P2VAR(StbM_LocalClockStateType, TYPEDEF, STBM_VAR_NO_INIT) StbM_LocalClockStatePtrType;

/**   \brief  type used to point to StbM_LocalTimeConfig */
typedef P2CONST(StbM_LocalTimeConfigType, TYPEDEF, STBM_CONST) StbM_LocalTimeConfigPtrType;

/**   \brief  type used to point to StbM_LocalTimeState */
typedef P2VAR(StbM_LocalTimeStateType, TYPEDEF, STBM_VAR_NO_INIT) StbM_LocalTimeStatePtrType;

/**   \brief  type used to point to StbM_MainTimeState */
typedef P2VAR(StbM_MainTimeStateType, TYPEDEF, STBM_VAR_NO_INIT) StbM_MainTimeStatePtrType;

/**   \brief  type used to point to StbM_PartitionIdentifiers */
typedef P2CONST(StbM_PartitionIdentifiersType, TYPEDEF, STBM_CONST) StbM_PartitionIdentifiersPtrType;

/**   \brief  type used to point to StbM_ReceivedTimeState */
typedef P2VAR(StbM_ReceivedTimeStateType, TYPEDEF, STBM_VAR_NO_INIT) StbM_ReceivedTimeStatePtrType;

/**   \brief  type used to point to StbM_Status */
typedef P2VAR(StbM_StatusType, TYPEDEF, STBM_VAR_NO_INIT) StbM_StatusPtrType;

/**   \brief  type used to point to StbM_SyncTimeRecordingBlock */
typedef P2VAR(StbM_SyncTimeRecordingBlockType, TYPEDEF, STBM_VAR_NO_INIT) StbM_SyncTimeRecordingBlockPtrType;

/**   \brief  type used to point to StbM_SyncTimeRecordingHeader */
typedef P2CONST(StbM_SyncTimeRecordingHeaderType, TYPEDEF, STBM_CONST) StbM_SyncTimeRecordingHeaderPtrType;

/**   \brief  type used to point to StbM_TimeBaseConfig */
typedef P2CONST(StbM_TimeBaseConfigType, TYPEDEF, STBM_CONST) StbM_TimeBaseConfigPtrType;

/**   \brief  type used to point to StbM_TimeBasePartitionMapping */
typedef P2CONST(StbM_TimeBasePartitionMappingType, TYPEDEF, STBM_CONST) StbM_TimeBasePartitionMappingPtrType;

/**   \brief  type used to point to StbM_TimeBaseState */
typedef P2VAR(StbM_TimeBaseStateType, TYPEDEF, STBM_VAR_NO_INIT) StbM_TimeBaseStatePtrType;

/**   \brief  type used to point to StbM_TimeLeapClearState */
typedef P2VAR(StbM_TimeLeapClearStateType, TYPEDEF, STBM_VAR_NO_INIT) StbM_TimeLeapClearStatePtrType;

/**   \brief  type used to point to StbM_TimeLeapConfig */
typedef P2CONST(StbM_TimeLeapConfigType, TYPEDEF, STBM_CONST) StbM_TimeLeapConfigPtrType;

/**   \brief  type used to point to StbM_TimeLeapState */
typedef P2VAR(StbM_TimeLeapStateType, TYPEDEF, STBM_VAR_NO_INIT) StbM_TimeLeapStatePtrType;

/**   \brief  type used to point to StbM_TimeRecordingConfig */
typedef P2CONST(StbM_TimeRecordingConfigType, TYPEDEF, STBM_CONST) StbM_TimeRecordingConfigPtrType;

/**   \brief  type used to point to StbM_TimeRecordingState */
typedef P2VAR(StbM_TimeRecordingStateType, TYPEDEF, STBM_VAR_NO_INIT) StbM_TimeRecordingStatePtrType;

/**   \brief  type used to point to StbM_TimeRecordingSyncCallback */
typedef P2CONST(StbM_TimeRecordingSyncCallbackType, TYPEDEF, STBM_CONST) StbM_TimeRecordingSyncCallbackPtrType;

/**   \brief  type used to point to StbM_TimeoutConfig */
typedef P2CONST(StbM_TimeoutConfigType, TYPEDEF, STBM_CONST) StbM_TimeoutConfigPtrType;

/**   \brief  type used to point to StbM_TimeoutState */
typedef P2VAR(StbM_TimeoutStateType, TYPEDEF, STBM_VAR_NO_INIT) StbM_TimeoutStatePtrType;

/**   \brief  type used to point to StbM_UserDataState */
typedef P2VAR(StbM_UserDataStateType, TYPEDEF, STBM_VAR_NO_INIT) StbM_UserDataStatePtrType;

/**   \brief  type used to point to StbM_UserDataOfUserDataState */
typedef P2VAR(StbM_UserDataType, TYPEDEF, STBM_VAR_NO_INIT) StbM_UserDataOfUserDataStatePtrType;

/**   \brief  type used to point to StbM_VirtualLocalTimeState */
typedef P2VAR(StbM_VirtualLocalTimeStateType, TYPEDEF, STBM_VAR_NO_INIT) StbM_VirtualLocalTimeStatePtrType;

/** 
  \}
*/ 

/** 
  \defgroup  StbMPCPartitionRootPointer  StbM Partition Root Pointer (PRE_COMPILE)
  \brief  This type definitions are used for partition specific instance.
  \{
*/ 
/**   \brief  type used in StbM_PCPartitionConfig */
typedef struct sStbM_PCPartitionConfigType
{
  StbM_GptClockConfigPtrType GptClockConfigOfPCPartitionConfig;  /**< the pointer to StbM_GptClockConfig */
  StbM_GptClockStatePtrType GptClockStateOfPCPartitionConfig;  /**< the pointer to StbM_GptClockState */
  StbM_InitializedPtrType InitializedOfPCPartitionConfig;  /**< the pointer to StbM_Initialized */
  StbM_LocalClockConfigPtrType LocalClockConfigOfPCPartitionConfig;  /**< the pointer to StbM_LocalClockConfig */
  StbM_LocalClockStatePtrType LocalClockStateOfPCPartitionConfig;  /**< the pointer to StbM_LocalClockState */
  StbM_LocalTimeConfigPtrType LocalTimeConfigOfPCPartitionConfig;  /**< the pointer to StbM_LocalTimeConfig */
  StbM_LocalTimeStatePtrType LocalTimeStateOfPCPartitionConfig;  /**< the pointer to StbM_LocalTimeState */
  StbM_MainTimeStatePtrType MainTimeStateOfPCPartitionConfig;  /**< the pointer to StbM_MainTimeState */
  StbM_ReceivedTimeStatePtrType ReceivedTimeStateOfPCPartitionConfig;  /**< the pointer to StbM_ReceivedTimeState */
  StbM_StatusPtrType StatusOfPCPartitionConfig;  /**< the pointer to StbM_Status */
  StbM_SyncTimeRecordingBlockPtrType SyncTimeRecordingBlockOfPCPartitionConfig;  /**< the pointer to StbM_SyncTimeRecordingBlock */
  StbM_SyncTimeRecordingHeaderPtrType SyncTimeRecordingHeaderOfPCPartitionConfig;  /**< the pointer to StbM_SyncTimeRecordingHeader */
  StbM_TimeBaseConfigPtrType TimeBaseConfigOfPCPartitionConfig;  /**< the pointer to StbM_TimeBaseConfig */
  StbM_TimeBaseStatePtrType TimeBaseStateOfPCPartitionConfig;  /**< the pointer to StbM_TimeBaseState */
  StbM_TimeLeapClearStatePtrType TimeLeapClearStateOfPCPartitionConfig;  /**< the pointer to StbM_TimeLeapClearState */
  StbM_TimeLeapConfigPtrType TimeLeapConfigOfPCPartitionConfig;  /**< the pointer to StbM_TimeLeapConfig */
  StbM_TimeLeapStatePtrType TimeLeapStateOfPCPartitionConfig;  /**< the pointer to StbM_TimeLeapState */
  StbM_TimeRecordingConfigPtrType TimeRecordingConfigOfPCPartitionConfig;  /**< the pointer to StbM_TimeRecordingConfig */
  StbM_TimeRecordingStatePtrType TimeRecordingStateOfPCPartitionConfig;  /**< the pointer to StbM_TimeRecordingState */
  StbM_TimeRecordingSyncCallbackPtrType TimeRecordingSyncCallbackOfPCPartitionConfig;  /**< the pointer to StbM_TimeRecordingSyncCallback */
  StbM_TimeoutConfigPtrType TimeoutConfigOfPCPartitionConfig;  /**< the pointer to StbM_TimeoutConfig */
  StbM_TimeoutStatePtrType TimeoutStateOfPCPartitionConfig;  /**< the pointer to StbM_TimeoutState */
  StbM_UserDataStatePtrType UserDataStateOfPCPartitionConfig;  /**< the pointer to StbM_UserDataState */
  StbM_VirtualLocalTimeStatePtrType VirtualLocalTimeStateOfPCPartitionConfig;  /**< the pointer to StbM_VirtualLocalTimeState */
  StbM_SizeOfGptClockConfigType SizeOfGptClockConfigOfPCPartitionConfig;  /**< the number of accomplishable value elements in StbM_GptClockConfig */
  StbM_SizeOfGptClockStateType SizeOfGptClockStateOfPCPartitionConfig;  /**< the number of accomplishable value elements in StbM_GptClockState */
  StbM_SizeOfLocalClockConfigType SizeOfLocalClockConfigOfPCPartitionConfig;  /**< the number of accomplishable value elements in StbM_LocalClockConfig */
  StbM_SizeOfLocalClockStateType SizeOfLocalClockStateOfPCPartitionConfig;  /**< the number of accomplishable value elements in StbM_LocalClockState */
  StbM_SizeOfLocalTimeConfigType SizeOfLocalTimeConfigOfPCPartitionConfig;  /**< the number of accomplishable value elements in StbM_LocalTimeConfig */
  StbM_SizeOfLocalTimeStateType SizeOfLocalTimeStateOfPCPartitionConfig;  /**< the number of accomplishable value elements in StbM_LocalTimeState */
  StbM_SizeOfMainTimeStateType SizeOfMainTimeStateOfPCPartitionConfig;  /**< the number of accomplishable value elements in StbM_MainTimeState */
  StbM_SizeOfSyncTimeRecordingBlockType SizeOfSyncTimeRecordingBlockOfPCPartitionConfig;  /**< the number of accomplishable value elements in StbM_SyncTimeRecordingBlock */
  StbM_SizeOfSyncTimeRecordingHeaderType SizeOfSyncTimeRecordingHeaderOfPCPartitionConfig;  /**< the number of accomplishable value elements in StbM_SyncTimeRecordingHeader */
  StbM_SizeOfTimeBaseConfigType SizeOfTimeBaseConfigOfPCPartitionConfig;  /**< the number of accomplishable value elements in StbM_TimeBaseConfig */
  StbM_SizeOfTimeLeapConfigType SizeOfTimeLeapConfigOfPCPartitionConfig;  /**< the number of accomplishable value elements in StbM_TimeLeapConfig */
  StbM_SizeOfTimeRecordingConfigType SizeOfTimeRecordingConfigOfPCPartitionConfig;  /**< the number of accomplishable value elements in StbM_TimeRecordingConfig */
  StbM_SizeOfTimeRecordingSyncCallbackType SizeOfTimeRecordingSyncCallbackOfPCPartitionConfig;  /**< the number of accomplishable value elements in StbM_TimeRecordingSyncCallback */
  StbM_SizeOfTimeoutConfigType SizeOfTimeoutConfigOfPCPartitionConfig;  /**< the number of accomplishable value elements in StbM_TimeoutConfig */
  StbM_SizeOfUserDataStateType SizeOfUserDataStateOfPCPartitionConfig;  /**< the number of accomplishable value elements in StbM_UserDataState */
  StbM_SizeOfVirtualLocalTimeStateType SizeOfVirtualLocalTimeStateOfPCPartitionConfig;  /**< the number of accomplishable value elements in StbM_VirtualLocalTimeState */
} StbM_PCPartitionConfigType;

/**   \brief  type used to point to StbM_PCPartitionConfig */
typedef P2CONST(StbM_PCPartitionConfigType, TYPEDEF, STBM_CONST) StbM_PCPartitionConfigPtrType;

/** 
  \}
*/ 

/** 
  \defgroup  StbMPCRootValueTypes  StbM Root Value Types (PRE_COMPILE)
  \brief  These type definitions are used for value representations in root arrays.
  \{
*/ 
/**   \brief  type used in StbM_PCConfig */
typedef struct sStbM_PCConfigType
{
  uint8 StbM_PCConfigNeverUsed;  /**< dummy entry for the structure in the configuration variant precompile which is not used by the code. */
} StbM_PCConfigType;

typedef StbM_PCConfigType StbM_ConfigType;  /**< A structure type is present for data in each configuration class. This typedef redefines the probably different name to the specified one. */

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
#define STBM_START_SEC_OsApplication_Trusted_Core0_VAR_NO_INIT_UNSPECIFIED
#include "StbM_MemMap.h"    /* PRQA S 5087 */        /* MD_MSR_MemMap */

extern VAR(boolean, STBM_VAR_NO_INIT) StbM_PreInitialized;
extern VAR(boolean, STBM_VAR_NO_INIT) StbM_PostInitialized;

#define STBM_STOP_SEC_OsApplication_Trusted_Core0_VAR_NO_INIT_UNSPECIFIED
#include "StbM_MemMap.h"    /* PRQA S 5087 */        /* MD_MSR_MemMap */

/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL DATA PROTOTYPES
**********************************************************************************************************************/
/**********************************************************************************************************************
  StbM_PartitionIdentifiers
**********************************************************************************************************************/
/** 
  \var    StbM_PartitionIdentifiers
  \brief  the partition context in Config
  \details
  Element                 Description
  PartitionSNV        
  PCPartitionConfigIdx    the index of the 1:1 relation pointing to StbM_PCPartitionConfig
*/ 
#define STBM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "StbM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(StbM_PartitionIdentifiersType, STBM_CONST) StbM_PartitionIdentifiers[2];
#define STBM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "StbM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  StbM_TimeBasePartitionMapping
**********************************************************************************************************************/
/** 
  \var    StbM_TimeBasePartitionMapping
  \brief  Time base to partition mapping
  \details
  Element                                           Description
  IndirectionToGptClockStateIdx                     the index of the 0:1 relation pointing to StbM_GptClockState,StbM_GptClockState
  IndirectionToGptClockStatePartitionIdx            the partition index of the 0:1 relation pointing to StbM_GptClockState,StbM_GptClockState
  IndirectionToLocalClockStateIdx                   the index of the 0:1 relation pointing to StbM_LocalClockState,StbM_LocalClockState
  IndirectionToLocalClockStatePartitionIdx          the partition index of the 0:1 relation pointing to StbM_LocalClockState,StbM_LocalClockState
  IndirectionToLocalTimeStateIdx                    the index of the 1:1 relation pointing to one of StbM_LocalTimeState,StbM_LocalTimeState
  IndirectionToLocalTimeStatePartitionIdx           the partition index of the 1:1 relation pointing to one of StbM_LocalTimeState,StbM_LocalTimeState
  IndirectionToMainTimeStateIdx                     the index of the 1:1 relation pointing to one of StbM_MainTimeState,StbM_MainTimeState
  IndirectionToMainTimeStatePartitionIdx            the partition index of the 1:1 relation pointing to one of StbM_MainTimeState,StbM_MainTimeState
  IndirectionToTimeBaseConfigIdx                    the index of the 1:1 relation pointing to one of StbM_TimeBaseConfig,StbM_TimeBaseConfig
  IndirectionToTimeBaseConfigPartitionIdx           the partition index of the 1:1 relation pointing to one of StbM_TimeBaseConfig,StbM_TimeBaseConfig
  IndirectionToVirtualLocalTimeStateIdx             the index of the 1:1 relation pointing to one of StbM_VirtualLocalTimeState,StbM_VirtualLocalTimeState
  IndirectionToVirtualLocalTimeStatePartitionIdx    the partition index of the 1:1 relation pointing to one of StbM_VirtualLocalTimeState,StbM_VirtualLocalTimeState
*/ 
#define STBM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "StbM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(StbM_TimeBasePartitionMappingType, STBM_CONST) StbM_TimeBasePartitionMapping[1];
#define STBM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "StbM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  StbM_PCPartitionConfig
**********************************************************************************************************************/
/** 
  \var    StbM_PCPartitionConfig
  \details
  Element                            Description
  GptClockConfig                     the pointer to StbM_GptClockConfig
  GptClockState                      the pointer to StbM_GptClockState
  Initialized                        the pointer to StbM_Initialized
  LocalClockConfig                   the pointer to StbM_LocalClockConfig
  LocalClockState                    the pointer to StbM_LocalClockState
  LocalTimeConfig                    the pointer to StbM_LocalTimeConfig
  LocalTimeState                     the pointer to StbM_LocalTimeState
  MainTimeState                      the pointer to StbM_MainTimeState
  ReceivedTimeState                  the pointer to StbM_ReceivedTimeState
  Status                             the pointer to StbM_Status
  SyncTimeRecordingBlock             the pointer to StbM_SyncTimeRecordingBlock
  SyncTimeRecordingHeader            the pointer to StbM_SyncTimeRecordingHeader
  TimeBaseConfig                     the pointer to StbM_TimeBaseConfig
  TimeBaseState                      the pointer to StbM_TimeBaseState
  TimeLeapClearState                 the pointer to StbM_TimeLeapClearState
  TimeLeapConfig                     the pointer to StbM_TimeLeapConfig
  TimeLeapState                      the pointer to StbM_TimeLeapState
  TimeRecordingConfig                the pointer to StbM_TimeRecordingConfig
  TimeRecordingState                 the pointer to StbM_TimeRecordingState
  TimeRecordingSyncCallback          the pointer to StbM_TimeRecordingSyncCallback
  TimeoutConfig                      the pointer to StbM_TimeoutConfig
  TimeoutState                       the pointer to StbM_TimeoutState
  UserDataState                      the pointer to StbM_UserDataState
  VirtualLocalTimeState              the pointer to StbM_VirtualLocalTimeState
  SizeOfGptClockConfig               the number of accomplishable value elements in StbM_GptClockConfig
  SizeOfGptClockState                the number of accomplishable value elements in StbM_GptClockState
  SizeOfLocalClockConfig             the number of accomplishable value elements in StbM_LocalClockConfig
  SizeOfLocalClockState              the number of accomplishable value elements in StbM_LocalClockState
  SizeOfLocalTimeConfig              the number of accomplishable value elements in StbM_LocalTimeConfig
  SizeOfLocalTimeState               the number of accomplishable value elements in StbM_LocalTimeState
  SizeOfMainTimeState                the number of accomplishable value elements in StbM_MainTimeState
  SizeOfSyncTimeRecordingBlock       the number of accomplishable value elements in StbM_SyncTimeRecordingBlock
  SizeOfSyncTimeRecordingHeader      the number of accomplishable value elements in StbM_SyncTimeRecordingHeader
  SizeOfTimeBaseConfig               the number of accomplishable value elements in StbM_TimeBaseConfig
  SizeOfTimeLeapConfig               the number of accomplishable value elements in StbM_TimeLeapConfig
  SizeOfTimeRecordingConfig          the number of accomplishable value elements in StbM_TimeRecordingConfig
  SizeOfTimeRecordingSyncCallback    the number of accomplishable value elements in StbM_TimeRecordingSyncCallback
  SizeOfTimeoutConfig                the number of accomplishable value elements in StbM_TimeoutConfig
  SizeOfUserDataState                the number of accomplishable value elements in StbM_UserDataState
  SizeOfVirtualLocalTimeState        the number of accomplishable value elements in StbM_VirtualLocalTimeState
*/ 
#define STBM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "StbM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(StbM_PCPartitionConfigType, STBM_CONST) StbM_PCPartitionConfig[2];
#define STBM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "StbM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */


/**********************************************************************************************************************
  CONFIGURATION CLASS: LINK
  SECTION: GLOBAL DATA PROTOTYPES
**********************************************************************************************************************/

/**********************************************************************************************************************
  CONFIGURATION CLASS: POST_BUILD
  SECTION: GLOBAL DATA PROTOTYPES
**********************************************************************************************************************/


/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL DATA PROTOTYPES
**********************************************************************************************************************/
/**********************************************************************************************************************
  StbM_GptClockState
**********************************************************************************************************************/
/** 
  \var    StbM_GptClockState
  \brief  All relevant state data for Gpt local clock.
  \details
  Element             Description
  GptChannelActive    Indicates if the used Gpt channel is active.
*/ 
#define STBM_START_SEC_CommonSharedMemory_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "StbM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(StbM_GptClockStateUType, STBM_VAR_NO_INIT) StbM_GptClockState;  /* PRQA S 0759 */  /* MD_CSL_Union */
#define STBM_STOP_SEC_CommonSharedMemory_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "StbM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  StbM_InitializedCommonSharedMemory
**********************************************************************************************************************/
/** 
  \var    StbM_InitializedCommonSharedMemory
  \brief  Initialization state of the StbM. TRUE, if StbM_Init() has been called, else FALSE.
*/ 
#define STBM_START_SEC_CommonSharedMemory_VAR_CLEARED_8
/*lint -save -esym(961, 19.1) */
#include "StbM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(StbM_InitializedType, STBM_VAR_CLEARED) StbM_InitializedCommonSharedMemory;  /* PRQA S 0777 */  /* MD_MSR_Rule5.1 */
#define STBM_STOP_SEC_CommonSharedMemory_VAR_CLEARED_8
/*lint -save -esym(961, 19.1) */
#include "StbM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  StbM_LocalClockState
**********************************************************************************************************************/
/** 
  \var    StbM_LocalClockState
  \brief  State table for Local Time unit.
  \details
  Element         Description
  ElapsedTime     Elapsed time of the local clock since last synchronization event. This can be either a counter value or a real time.
  LastReadTime    Last read time of the local clock. This can be either a counter value or a real time.
*/ 
#define STBM_START_SEC_CommonSharedMemory_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "StbM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(StbM_LocalClockStateUType, STBM_VAR_NO_INIT) StbM_LocalClockState;  /* PRQA S 0759 */  /* MD_CSL_Union */
#define STBM_STOP_SEC_CommonSharedMemory_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "StbM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  StbM_LocalTimeState
**********************************************************************************************************************/
/** 
  \var    StbM_LocalTimeState
  \brief  Local time state table.
  \details
  Element             Description
  LocalTimeUpdated    Indicate if LocalTime is updated and therefore valid, hence can be used without recalculating it. (E_OK | E_NOT_OK)
  LocalTime           TL (current corrected local time).
*/ 
#define STBM_START_SEC_CommonSharedMemory_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "StbM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(StbM_LocalTimeStateUType, STBM_VAR_NO_INIT) StbM_LocalTimeState;  /* PRQA S 0759 */  /* MD_CSL_Union */
#define STBM_STOP_SEC_CommonSharedMemory_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "StbM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  StbM_MainTimeState
**********************************************************************************************************************/
/** 
  \var    StbM_MainTimeState
  \brief  Main time state table.
  \details
  Element                 Description
  GlobalTimeSync          TGsync (local time after update).
  VirtualLocalTimeSync    TVsync (virtual local time at last synchronization event).
*/ 
#define STBM_START_SEC_CommonSharedMemory_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "StbM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(StbM_MainTimeStateUType, STBM_VAR_NO_INIT) StbM_MainTimeState;  /* PRQA S 0759 */  /* MD_CSL_Union */
#define STBM_STOP_SEC_CommonSharedMemory_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "StbM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  StbM_VirtualLocalTimeState
**********************************************************************************************************************/
/** 
  \var    StbM_VirtualLocalTimeState
  \brief  Virtual local time state table.
  \details
  Element                                         Description
  VirtualLocalTime                                TV (current virtual local time).
  VirtualLocalTimeElapsedAfterAdaptionInterval    TV elapsed after adaption interval (virtual local time elapsed after offset correction adaption interval).
*/ 
#define STBM_START_SEC_CommonSharedMemory_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "StbM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(StbM_VirtualLocalTimeStateUType, STBM_VAR_NO_INIT) StbM_VirtualLocalTimeState;  /* PRQA S 0759 */  /* MD_CSL_Union */
#define STBM_STOP_SEC_CommonSharedMemory_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "StbM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */


/**********************************************************************************************************************
  CONFIGURATION CLASS: LINK
  SECTION: GLOBAL DATA PROTOTYPES
**********************************************************************************************************************/

/**********************************************************************************************************************
  CONFIGURATION CLASS: POST_BUILD
  SECTION: GLOBAL DATA PROTOTYPES
**********************************************************************************************************************/

/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL DATA PROTOTYPES
**********************************************************************************************************************/
/**********************************************************************************************************************
  StbM_GptClockConfig
**********************************************************************************************************************/
/** 
  \var    StbM_GptClockConfig
  \details
  Element                   Description
  MaxTickValue              Maximum value in ticks, the timer channel is able to count.
  GptChannelSymbolicName    Symbolic name of used Gpt channel as local reference clock.
*/ 
#define STBM_START_SEC_OsApplication_Trusted_Core0_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "StbM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(StbM_GptClockConfigType, STBM_CONST) StbM_GptClockConfig[1];
#define STBM_STOP_SEC_OsApplication_Trusted_Core0_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "StbM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  StbM_LocalClockConfig
**********************************************************************************************************************/
/** 
  \var    StbM_LocalClockConfig
  \details
  Element                                     Description
  HwFrequency                                 Frequency of the hardware reference clock in Hz.
  ClockType                                   The type of local clock, which is used as hardware clock
  DenominatorOfFactorClockTicksToLocalTime    Pre calculated denominator of the rational number of the calculation: (StbMClockPrescaler * 10^9) / StbMClockFrequency.
  GptClockConfigIdx                           the index of the 0:1 relation pointing to StbM_GptClockConfig
  HwPrescaler                                 Prescaler of hardware reference clock.
  NumeratorOfFactorClockTicksToLocalTime      Pre calculated numerator of the rational number of the calculation: (StbMClockPrescaler * 10^9) / StbMClockFrequency.
  TimeBasePartitionMappingIdx                 the index of the 1:1 relation pointing to StbM_TimeBasePartitionMapping
*/ 
#define STBM_START_SEC_OsApplication_Trusted_Core0_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "StbM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(StbM_LocalClockConfigType, STBM_CONST) StbM_LocalClockConfig[1];
#define STBM_STOP_SEC_OsApplication_Trusted_Core0_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "StbM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  StbM_LocalTimeConfig
**********************************************************************************************************************/
/** 
  \var    StbM_LocalTimeConfig
  \brief  This table contains the local time information of all timebases.
  \details
  Element                        Description
  LocalClockConfigIdx            the index of the 0:1 relation pointing to StbM_LocalClockConfig
  TimeBaseConfigIdx              the index of the 1:1 relation pointing to StbM_TimeBaseConfig
  TimeBasePartitionMappingIdx    the index of the 1:1 relation pointing to StbM_TimeBasePartitionMapping
*/ 
#define STBM_START_SEC_OsApplication_Trusted_Core0_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "StbM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(StbM_LocalTimeConfigType, STBM_CONST) StbM_LocalTimeConfig[1];
#define STBM_STOP_SEC_OsApplication_Trusted_Core0_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "StbM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  StbM_SyncTimeRecordingHeader
**********************************************************************************************************************/
/** 
  \var    StbM_SyncTimeRecordingHeader
  \brief  Time recording header of synchronized timebase.
  \details
  Element        Description
  HwFrequency    Frequency of the hardware reference clock in Hz.
  HwPrescaler    Prescaler of hardware reference clock.
  TimeDomain     Frequency of the hardware reference clock in Hz.
*/ 
#define STBM_START_SEC_OsApplication_Trusted_Core0_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "StbM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(StbM_SyncTimeRecordingHeaderType, STBM_CONST) StbM_SyncTimeRecordingHeader[1];
#define STBM_STOP_SEC_OsApplication_Trusted_Core0_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "StbM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  StbM_TimeBaseConfig
**********************************************************************************************************************/
/** 
  \var    StbM_TimeBaseConfig
  \brief  Configuration data from timebase. Contains all indirections to other tables.
  \details
  Element                   Description
  SynchronizedTimeBase      Indicates if the time base is a synchronized time base.
  TimeSlave                 true if timebase has the role of a time slave
  LocalTimeConfigIdx        the index of the 1:1 relation pointing to StbM_LocalTimeConfig
  PartitionConfigIdx        the index of the 1:1 relation pointing to StbM_PCPartitionConfig
  StatusIdx                 the index of the 1:1 relation pointing to StbM_Status
  TimeBaseId                Id of the timebase.
  TimeLeapConfigIdx         the index of the 0:1 relation pointing to StbM_TimeLeapConfig
  TimeRecordingConfigIdx    the index of the 0:1 relation pointing to StbM_TimeRecordingConfig
  TimeoutConfigIdx          the index of the 0:1 relation pointing to StbM_TimeoutConfig
  UserDataStateIdx          the index of the 1:1 relation pointing to StbM_UserDataState
*/ 
#define STBM_START_SEC_OsApplication_Trusted_Core0_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "StbM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(StbM_TimeBaseConfigType, STBM_CONST) StbM_TimeBaseConfig[1];
#define STBM_STOP_SEC_OsApplication_Trusted_Core0_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "StbM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  StbM_TimeLeapConfig
**********************************************************************************************************************/
/** 
  \var    StbM_TimeLeapConfig
  \details
  Element            Description
  FutureThreshold    Time leap threshold after which a future time leap is detected.
  PastThreshold      Time leap threshold after which a past time leap is detected.
  ClearCount         Counter after which the a time leap is deleted.
*/ 
#define STBM_START_SEC_OsApplication_Trusted_Core0_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "StbM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(StbM_TimeLeapConfigType, STBM_CONST) StbM_TimeLeapConfig[1];
#define STBM_STOP_SEC_OsApplication_Trusted_Core0_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "StbM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  StbM_TimeRecordingConfig
**********************************************************************************************************************/
/** 
  \var    StbM_TimeRecordingConfig
  \brief  Configuration data for time recording unit.
  \details
  Element                           Description
  BlockCount                        Number of configured recording blocks
  SyncTimeRecordingBlockEndIdx      the end index of the 0:n relation pointing to StbM_SyncTimeRecordingBlock
  SyncTimeRecordingBlockStartIdx    the start index of the 0:n relation pointing to StbM_SyncTimeRecordingBlock
  SyncTimeRecordingHeaderIdx        the index of the 0:1 relation pointing to StbM_SyncTimeRecordingHeader
  TimeBaseConfigIdx                 the index of the 0:1 relation pointing to StbM_TimeBaseConfig
  TimeRecordingSyncCallbackIdx      the index of the 0:1 relation pointing to StbM_TimeRecordingSyncCallback
*/ 
#define STBM_START_SEC_OsApplication_Trusted_Core0_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "StbM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(StbM_TimeRecordingConfigType, STBM_CONST) StbM_TimeRecordingConfig[1];
#define STBM_STOP_SEC_OsApplication_Trusted_Core0_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "StbM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  StbM_TimeRecordingSyncCallback
**********************************************************************************************************************/
/** 
  \var    StbM_TimeRecordingSyncCallback
  \brief  Time recording callback for synchronized timebase.
  \details
  Element     Description
  Callback    This function is called, once all recording blocks are updated.
*/ 
#define STBM_START_SEC_OsApplication_Trusted_Core0_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "StbM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(StbM_TimeRecordingSyncCallbackType, STBM_CONST) StbM_TimeRecordingSyncCallback[1];
#define STBM_STOP_SEC_OsApplication_Trusted_Core0_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "StbM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  StbM_TimeoutConfig
**********************************************************************************************************************/
/** 
  \var    StbM_TimeoutConfig
  \details
  Element                   Description
  SyncLossTimeoutCounter    Represents the amount of main functions until the timeout is expired. Calculated by Timeout(ns)/MainFunction(ns).
  TimeBaseConfigIdx         the index of the 1:1 relation pointing to StbM_TimeBaseConfig
*/ 
#define STBM_START_SEC_OsApplication_Trusted_Core0_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "StbM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(StbM_TimeoutConfigType, STBM_CONST) StbM_TimeoutConfig[1];
#define STBM_STOP_SEC_OsApplication_Trusted_Core0_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "StbM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  StbM_InitializedOsApplication_Trusted_Core0
**********************************************************************************************************************/
/** 
  \var    StbM_InitializedOsApplication_Trusted_Core0
  \brief  Initialization state of the StbM. TRUE, if StbM_Init() has been called, else FALSE.
*/ 
#define STBM_START_SEC_OsApplication_Trusted_Core0_VAR_CLEARED_8
/*lint -save -esym(961, 19.1) */
#include "StbM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(StbM_InitializedType, STBM_VAR_CLEARED) StbM_InitializedOsApplication_Trusted_Core0;  /* PRQA S 0777 */  /* MD_MSR_Rule5.1 */
#define STBM_STOP_SEC_OsApplication_Trusted_Core0_VAR_CLEARED_8
/*lint -save -esym(961, 19.1) */
#include "StbM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  StbM_ReceivedTimeState
**********************************************************************************************************************/
/** 
  \var    StbM_ReceivedTimeState
  \brief  Received time state table.
  \details
  Element               Description
  GlobalTimeRx          TGrx (received global time).
  LocalTimeSync         TLsync (local time before update).
  VirtualLocalTimeRx    TVrx (received virtual local time).
*/ 
#define STBM_START_SEC_OsApplication_Trusted_Core0_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "StbM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(StbM_ReceivedTimeStateUType, STBM_VAR_NO_INIT) StbM_ReceivedTimeState;  /* PRQA S 0759 */  /* MD_CSL_Union */
#define STBM_STOP_SEC_OsApplication_Trusted_Core0_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "StbM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  StbM_Status
**********************************************************************************************************************/
/** 
  \var    StbM_Status
  \brief  Table with timebase status
  \details
  Element             Description
  GlobalTimeStatus    Status of received global time.
  LocalTimeStatus     Status of local time.
*/ 
#define STBM_START_SEC_OsApplication_Trusted_Core0_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "StbM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(StbM_StatusUType, STBM_VAR_NO_INIT) StbM_Status;  /* PRQA S 0759 */  /* MD_CSL_Union */
#define STBM_STOP_SEC_OsApplication_Trusted_Core0_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "StbM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  StbM_SyncTimeRecordingBlock
**********************************************************************************************************************/
/** 
  \var    StbM_SyncTimeRecordingBlock
  \brief  Time recording blocks of synchronized timebase.
  \details
  Element                Description
  GlbNanoSeconds         Nanoseconds of global time after update.
  GlbSeconds             Seconds of global time after update.
  LocNanoSeconds         Nanoseconds of local time before update.
  LocSeconds             Seconds of local time before update.
  PathDelay              Received path delay.
  VirtualLocalTimeLow    Least significant 32 bit of the Virtual Local Time.
  TimeBaseStatus         TimeBaseStatus.
  RateDeviation          Rate deviation.
*/ 
#define STBM_START_SEC_OsApplication_Trusted_Core0_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "StbM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(StbM_SyncTimeRecordingBlockUType, STBM_VAR_NO_INIT) StbM_SyncTimeRecordingBlock;  /* PRQA S 0759 */  /* MD_CSL_Union */
#define STBM_STOP_SEC_OsApplication_Trusted_Core0_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "StbM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  StbM_TimeBaseState
**********************************************************************************************************************/
/** 
  \var    StbM_TimeBaseState
  \brief  Internal state of the Time Bases.
  \details
  Element          Description
  UpdateCounter    Actual counter value for immediate time synchronisation.
*/ 
#define STBM_START_SEC_OsApplication_Trusted_Core0_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "StbM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(StbM_TimeBaseStateUType, STBM_VAR_NO_INIT) StbM_TimeBaseState;  /* PRQA S 0759 */  /* MD_CSL_Union */
#define STBM_STOP_SEC_OsApplication_Trusted_Core0_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "StbM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  StbM_TimeLeapClearState
**********************************************************************************************************************/
/** 
  \var    StbM_TimeLeapClearState
  \details
  Element             Description
  ClearCountFuture    Clear counter to count until a detected timeleap to the future is reset.
  ClearCountPast      Clear counter to count until a detected timeleap to the past is reset.
*/ 
#define STBM_START_SEC_OsApplication_Trusted_Core0_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "StbM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(StbM_TimeLeapClearStateUType, STBM_VAR_NO_INIT) StbM_TimeLeapClearState;  /* PRQA S 0759 */  /* MD_CSL_Union */
#define STBM_STOP_SEC_OsApplication_Trusted_Core0_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "StbM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  StbM_TimeLeapState
**********************************************************************************************************************/
/** 
  \var    StbM_TimeLeapState
  \brief  Time leap state table.
  \details
  Element          Description
  TimeLeap         The last calculated time leap TGrx - TL.
  TimeLeapValid    Flag which indicates if the calculated time leap is valid.
*/ 
#define STBM_START_SEC_OsApplication_Trusted_Core0_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "StbM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(StbM_TimeLeapStateUType, STBM_VAR_NO_INIT) StbM_TimeLeapState;  /* PRQA S 0759 */  /* MD_CSL_Union */
#define STBM_STOP_SEC_OsApplication_Trusted_Core0_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "StbM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  StbM_TimeRecordingState
**********************************************************************************************************************/
/** 
  \var    StbM_TimeRecordingState
  \brief  State table for time recording unit.
  \details
  Element                Description
  CurrentBlockIdx        Current index of the next free block in timebase time recording blocks.
  PathDelay              Received path delay on last synchronization event.
  RecordedBlocksCount    Number of recorded blocks.
*/ 
#define STBM_START_SEC_OsApplication_Trusted_Core0_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "StbM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(StbM_TimeRecordingStateUType, STBM_VAR_NO_INIT) StbM_TimeRecordingState;  /* PRQA S 0759 */  /* MD_CSL_Union */
#define STBM_STOP_SEC_OsApplication_Trusted_Core0_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "StbM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  StbM_TimeoutState
**********************************************************************************************************************/
/** 
  \var    StbM_TimeoutState
  \details
  Element                   Description
  SyncLossTimeoutCounter    Timeout for the synchronisation of the Time Base.
*/ 
#define STBM_START_SEC_OsApplication_Trusted_Core0_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "StbM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(StbM_TimeoutStateUType, STBM_VAR_NO_INIT) StbM_TimeoutState;  /* PRQA S 0759 */  /* MD_CSL_Union */
#define STBM_STOP_SEC_OsApplication_Trusted_Core0_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "StbM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  StbM_UserDataState
**********************************************************************************************************************/
/** 
  \var    StbM_UserDataState
  \brief  State table for user data.
  \details
  Element     Description
  UserData    User data.
*/ 
#define STBM_START_SEC_OsApplication_Trusted_Core0_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "StbM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(StbM_UserDataStateUType, STBM_VAR_NO_INIT) StbM_UserDataState;  /* PRQA S 0759 */  /* MD_CSL_Union */
#define STBM_STOP_SEC_OsApplication_Trusted_Core0_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "StbM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */


/**********************************************************************************************************************
  CONFIGURATION CLASS: LINK
  SECTION: GLOBAL DATA PROTOTYPES
**********************************************************************************************************************/

/**********************************************************************************************************************
  CONFIGURATION CLASS: POST_BUILD
  SECTION: GLOBAL DATA PROTOTYPES
**********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
extern FUNC(void, STBM_CODE) StbM_MainFunction(StbM_PartitionIdentifiersIterType partitionIndex);

/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL FUNCTION PROTOTYPES
**********************************************************************************************************************/

/**********************************************************************************************************************
  CONFIGURATION CLASS: LINK
  SECTION: GLOBAL FUNCTION PROTOTYPES
**********************************************************************************************************************/

/**********************************************************************************************************************
  CONFIGURATION CLASS: POST_BUILD
  SECTION: GLOBAL FUNCTION PROTOTYPES
**********************************************************************************************************************/



#endif  /* STBM_CFG_H */
/**********************************************************************************************************************
 *  END OF FILE: StbM_Cfg.h
 *********************************************************************************************************************/
