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
 *              File: StbM_Cfg_OsApplication_Trusted_Core0.c
 *   Generation Time: 2023-07-10 14:36:14
 *           Project: StartApplication - Version 1.0
 *          Delivery: CBD2200333_D05
 *      Tool Version: DaVinci Configurator Classic 5.25.50 SP5
 *
 *
 *********************************************************************************************************************/


#define STBM_CFG_OSAPPLICATION_TRUSTED_CORE0_SOURCE

/**********************************************************************************************************************
 *  LOCAL MISRA / PCLINT JUSTIFICATION
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

#include "StbM.h"
#include "Rte_StbM_OsApplication_Trusted_Core0.h"

/**********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTION MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
 
 /**********************************************************************************************************************
 *  LOCAL DATA PROTOTYPES
 **********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: LOCAL DATA PROTOTYPES
**********************************************************************************************************************/

/**********************************************************************************************************************
  CONFIGURATION CLASS: LINK
  SECTION: LOCAL DATA PROTOTYPES
**********************************************************************************************************************/

/**********************************************************************************************************************
  CONFIGURATION CLASS: POST_BUILD
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
  CONFIGURATION CLASS: LINK
  SECTION: LOCAL DATA
**********************************************************************************************************************/

/**********************************************************************************************************************
  CONFIGURATION CLASS: POST_BUILD
  SECTION: LOCAL DATA
**********************************************************************************************************************/


/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/
 
 /**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL DATA
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
CONST(StbM_GptClockConfigType, STBM_CONST) StbM_GptClockConfig[1] = {  /* PRQA S 1514, 1533, 1504 */  /* MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ExternalMcData */
    /* Index    MaxTickValue  GptChannelSymbolicName                                                        Referable Keys */
  { /*     0 */    16777215u, GptConf_GptChannelConfiguration_GptChannelConfiguration_StbM_LocalTime }   /* [/ActiveEcuC/Gpt/GptChannelConfigSet/GptChannelConfiguration_StbM_LocalTime] */
};
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
CONST(StbM_LocalClockConfigType, STBM_CONST) StbM_LocalClockConfig[1] = {  /* PRQA S 1514, 1533, 1504 */  /* MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ExternalMcData */
    /* Index    HwFrequency  ClockType                                        DenominatorOfFactorClockTicksToLocalTime  GptClockConfigIdx                                                                                    HwPrescaler  NumeratorOfFactorClockTicksToLocalTime  TimeBasePartitionMappingIdx                                                     Referable Keys */
  { /*     0 */   40000000u, STBM_GPT_LOCALCLOCK_CLOCKTYPEOFLOCALCLOCKCONFIG,                                       1u,                0u  /* /ActiveEcuC/Gpt/GptChannelConfigSet/GptChannelConfiguration_StbM_LocalTime */,          1u,                                    25u,                          0u  /* /ActiveEcuC/StbM/GTD_BODY3_0_14e64f11 */ }   /* [/ActiveEcuC/StbM/GTD_BODY3_0_14e64f11] */
};
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
CONST(StbM_LocalTimeConfigType, STBM_CONST) StbM_LocalTimeConfig[1] = {  /* PRQA S 1514, 1533, 1504 */  /* MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ExternalMcData */
    /* Index    LocalClockConfigIdx                                               TimeBaseConfigIdx                                               TimeBasePartitionMappingIdx                                                     Referable Keys */
  { /*     0 */                  0u  /* /ActiveEcuC/StbM/GTD_BODY3_0_14e64f11 */,                0u  /* /ActiveEcuC/StbM/GTD_BODY3_0_14e64f11 */,                          0u  /* /ActiveEcuC/StbM/GTD_BODY3_0_14e64f11 */ }   /* [/ActiveEcuC/StbM/GTD_BODY3_0_14e64f11] */
};
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
CONST(StbM_SyncTimeRecordingHeaderType, STBM_CONST) StbM_SyncTimeRecordingHeader[1] = {  /* PRQA S 1514, 1533, 1504 */  /* MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ExternalMcData */
    /* Index    HwFrequency  HwPrescaler  TimeDomain        Referable Keys */
  { /*     0 */   40000000u,          1u,         0u }   /* [/ActiveEcuC/StbM/GTD_BODY3_0_14e64f11] */
};
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
CONST(StbM_TimeBaseConfigType, STBM_CONST) StbM_TimeBaseConfig[1] = {  /* PRQA S 1514, 1533, 1504 */  /* MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ExternalMcData */
    /* Index    SynchronizedTimeBase  TimeSlave  LocalTimeConfigIdx                                               PartitionConfigIdx                                     StatusIdx                                               TimeBaseId  TimeLeapConfigIdx                                               TimeRecordingConfigIdx                                               TimeoutConfigIdx                                               UserDataStateIdx                                                     Referable Keys */
  { /*     0 */                 TRUE,      TRUE,                 0u  /* /ActiveEcuC/StbM/GTD_BODY3_0_14e64f11 */,                 1u  /* OsApplication_Trusted_Core0 */,        0u  /* /ActiveEcuC/StbM/GTD_BODY3_0_14e64f11 */,         0u,                0u  /* /ActiveEcuC/StbM/GTD_BODY3_0_14e64f11 */,                     0u  /* /ActiveEcuC/StbM/GTD_BODY3_0_14e64f11 */,               0u  /* /ActiveEcuC/StbM/GTD_BODY3_0_14e64f11 */,               0u  /* /ActiveEcuC/StbM/GTD_BODY3_0_14e64f11 */ }   /* [/ActiveEcuC/StbM/GTD_BODY3_0_14e64f11] */
};
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
CONST(StbM_TimeLeapConfigType, STBM_CONST) StbM_TimeLeapConfig[1] = {  /* PRQA S 1514, 1533, 1504 */  /* MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ExternalMcData */
    /* Index    FutureThreshold  PastThreshold  ClearCount        Referable Keys */
  { /*     0 */        1700000u,      1700000u,         3u }   /* [/ActiveEcuC/StbM/GTD_BODY3_0_14e64f11] */
};
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
CONST(StbM_TimeRecordingConfigType, STBM_CONST) StbM_TimeRecordingConfig[1] = {  /* PRQA S 1514, 1533, 1504 */  /* MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ExternalMcData */
    /* Index    BlockCount  SyncTimeRecordingBlockEndIdx                                               SyncTimeRecordingBlockStartIdx                                               SyncTimeRecordingHeaderIdx                                               TimeBaseConfigIdx                                               TimeRecordingSyncCallbackIdx                                                     Referable Keys */
  { /*     0 */         1u,                           1u  /* /ActiveEcuC/StbM/GTD_BODY3_0_14e64f11 */,                             0u  /* /ActiveEcuC/StbM/GTD_BODY3_0_14e64f11 */,                         0u  /* /ActiveEcuC/StbM/GTD_BODY3_0_14e64f11 */,                0u  /* /ActiveEcuC/StbM/GTD_BODY3_0_14e64f11 */,                           0u  /* /ActiveEcuC/StbM/GTD_BODY3_0_14e64f11 */ }   /* [/ActiveEcuC/StbM/GTD_BODY3_0_14e64f11] */
};
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
CONST(StbM_TimeRecordingSyncCallbackType, STBM_CONST) StbM_TimeRecordingSyncCallback[1] = {  /* PRQA S 1514, 1533, 1504 */  /* MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ExternalMcData */
    /* Index    Callback                                                                              Referable Keys */
  { /*     0 */ Rte_Call_StbM_MeasurementNotification_GTD_BODY3_0_14e64f11_SyncTimeRecordBlock }   /* [/ActiveEcuC/StbM/GTD_BODY3_0_14e64f11] */
};
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
CONST(StbM_TimeoutConfigType, STBM_CONST) StbM_TimeoutConfig[1] = {  /* PRQA S 1514, 1533, 1504 */  /* MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ExternalMcData */
    /* Index    SyncLossTimeoutCounter  TimeBaseConfigIdx                                                     Referable Keys */
  { /*     0 */                   350u,                0u  /* /ActiveEcuC/StbM/GTD_BODY3_0_14e64f11 */ }   /* [/ActiveEcuC/StbM/GTD_BODY3_0_14e64f11] */
};
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
VAR(StbM_InitializedType, STBM_VAR_CLEARED) StbM_InitializedOsApplication_Trusted_Core0 = FALSE;  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
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
VAR(StbM_ReceivedTimeStateUType, STBM_VAR_NO_INIT) StbM_ReceivedTimeState;  /* PRQA S 0759, 1514, 1533 */  /* MD_CSL_Union, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/StbM/GTD_BODY3_0_14e64f11] */

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
VAR(StbM_StatusUType, STBM_VAR_NO_INIT) StbM_Status;  /* PRQA S 0759, 1514, 1533 */  /* MD_CSL_Union, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/StbM/GTD_BODY3_0_14e64f11] */

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
VAR(StbM_SyncTimeRecordingBlockUType, STBM_VAR_NO_INIT) StbM_SyncTimeRecordingBlock;  /* PRQA S 0759, 1514, 1533 */  /* MD_CSL_Union, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/StbM/GTD_BODY3_0_14e64f11] */

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
VAR(StbM_TimeBaseStateUType, STBM_VAR_NO_INIT) StbM_TimeBaseState;  /* PRQA S 0759, 1514, 1533 */  /* MD_CSL_Union, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/StbM/GTD_BODY3_0_14e64f11] */

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
VAR(StbM_TimeLeapClearStateUType, STBM_VAR_NO_INIT) StbM_TimeLeapClearState;  /* PRQA S 0759, 1514, 1533 */  /* MD_CSL_Union, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/StbM/GTD_BODY3_0_14e64f11] */

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
VAR(StbM_TimeLeapStateUType, STBM_VAR_NO_INIT) StbM_TimeLeapState;  /* PRQA S 0759, 1514, 1533 */  /* MD_CSL_Union, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/StbM/GTD_BODY3_0_14e64f11] */

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
VAR(StbM_TimeRecordingStateUType, STBM_VAR_NO_INIT) StbM_TimeRecordingState;  /* PRQA S 0759, 1514, 1533 */  /* MD_CSL_Union, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/StbM/GTD_BODY3_0_14e64f11] */

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
VAR(StbM_TimeoutStateUType, STBM_VAR_NO_INIT) StbM_TimeoutState;  /* PRQA S 0759, 1514, 1533 */  /* MD_CSL_Union, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/StbM/GTD_BODY3_0_14e64f11] */

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
VAR(StbM_UserDataStateUType, STBM_VAR_NO_INIT) StbM_UserDataState;  /* PRQA S 0759, 1514, 1533 */  /* MD_CSL_Union, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/StbM/GTD_BODY3_0_14e64f11] */

#define STBM_STOP_SEC_OsApplication_Trusted_Core0_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "StbM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */


/**********************************************************************************************************************
  CONFIGURATION CLASS: LINK
  SECTION: GLOBAL DATA
**********************************************************************************************************************/

/**********************************************************************************************************************
  CONFIGURATION CLASS: POST_BUILD
  SECTION: GLOBAL DATA
**********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * StbM_MainFunction_OsApplication_Trusted_Core0
 *********************************************************************************************************************/
/*!
 * \internal
 * - #10 Call StbM_MainFunction(partitionIndex) with the current partition index.
 * \endinternal
 *********************************************************************************************************************/
#define STBM_START_SEC_CODE
#include "StbM_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
FUNC(void, STBM_CODE) StbM_MainFunction_OsApplication_Trusted_Core0(void)
{
	/* #10 Call StbM_MainFunction(partitionIndex) with the current partition index. */
	StbM_MainFunction(StbM_PartitionIndexOfCSLForOsApplication_Trusted_Core0);
}
#define STBM_STOP_SEC_CODE
#include "StbM_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  END OF FILE: StbM_Cfg_OsApplication_Trusted_Core0.c
 *********************************************************************************************************************/
